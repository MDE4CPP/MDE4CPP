#include "fUML/impl/FUMLFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"

#include "fUML/FUMLPackage.hpp"
#include "fUML/Semantics/Actions/impl/AcceptCallActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/AcceptCallActionActivationsImpl.hpp"
#include "fUML/Semantics/Actions/impl/AcceptEventActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/AcceptEventActionEventAccepterImpl.hpp"
#include "fUML/Semantics/Actions/impl/ActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/AddStructuralFeatureValueActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/CallActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/CallBehaviorActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/CallOperationActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ClauseActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ClearAssociationActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ClearStructuralFeatureActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ConditionalNodeActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/CreateLinkActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/CreateObjectActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/DestroyLinkActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/DestroyObjectActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/InputPinActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/InvocationActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/LinkActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/LoopNodeActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/OutputPinActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/PinActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ReadExtentActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ReadIsClassifiedObjectActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ReadLinkActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ReadSelfActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ReadStructuralFeatureActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ReclassifyObjectActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ReduceActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/RemoveStructuralFeatureValueActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ReplyActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ReturnInformationImpl.hpp"
#include "fUML/Semantics/Actions/impl/SendSignalActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/StartClassifierBehaviorActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/StartObjectBehaviorActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/StructuralFeatureActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/StructuredActivityNodeActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/TestIdentityActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ValueSpecificationActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ValuesImpl.hpp"
#include "fUML/Semantics/Actions/impl/WriteLinkActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/WriteStructuralFeatureActionActivationImpl.hpp"

#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"

#include "fUML/Semantics/Activities/impl/ActivityEdgeInstanceImpl.hpp"
#include "fUML/Semantics/Activities/impl/ActivityExecutionImpl.hpp"
#include "fUML/Semantics/Activities/impl/ActivityFinalNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/ActivityNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/ActivityNodeActivationGroupImpl.hpp"
#include "fUML/Semantics/Activities/impl/ActivityParameterNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/CentralBufferNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/ClassifierBehaviorExecutionActivityImpl.hpp"
#include "fUML/Semantics/Activities/impl/ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl.hpp"
#include "fUML/Semantics/Activities/impl/ControlNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/ControlTokenImpl.hpp"
#include "fUML/Semantics/Activities/impl/DataStoreNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/DecisionNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/ExpansionActivationGroupImpl.hpp"
#include "fUML/Semantics/Activities/impl/ExpansionNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/ExpansionRegionActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/FlowFinalNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/ForkNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/ForkedTokenImpl.hpp"
#include "fUML/Semantics/Activities/impl/InitialNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/JoinNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/MergeNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/ObjectNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/ObjectTokenImpl.hpp"
#include "fUML/Semantics/Activities/impl/OfferImpl.hpp"
#include "fUML/Semantics/Activities/impl/TokenImpl.hpp"
#include "fUML/Semantics/Activities/impl/TokenSetImpl.hpp"

#include "fUML/Semantics/Activities/ActivityExecution.hpp"
#include "fUML/Semantics/Actions/StructuredActivityNodeActivation.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"

#include "fUML/Semantics/Classification/impl/InstanceValueEvaluationImpl.hpp"


#include "fUML/Semantics/CommonBehavior/impl/CallEventBehaviorImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/CallEventExecutionImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/CallEventOccurrenceImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/ClassifierBehaviorExecutionImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/ClassifierBehaviorInvocationEventAccepterImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/EventAccepterImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/EventDispatchLoopImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/EventOccurrenceImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/ExecutionImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/FIFOGetNextEventStrategyImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/GetNextEventStrategyImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/InvocationEventOccurrenceImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/ObjectActivationImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/OpaqueBehaviorExecutionImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/ParameterValueImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/SignalEventOccurrenceImpl.hpp"


#include "fUML/Semantics/Loci/impl/ChoiceStrategyImpl.hpp"
#include "fUML/Semantics/Loci/impl/ExecutionFactoryImpl.hpp"
#include "fUML/Semantics/Loci/impl/ExecutionFactoryL1Impl.hpp"
#include "fUML/Semantics/Loci/impl/ExecutionFactoryL2Impl.hpp"
#include "fUML/Semantics/Loci/impl/ExecutionFactoryL3Impl.hpp"
#include "fUML/Semantics/Loci/impl/ExecutorImpl.hpp"
#include "fUML/Semantics/Loci/impl/FirstChoiceStrategyImpl.hpp"
#include "fUML/Semantics/Loci/impl/LocusImpl.hpp"
#include "fUML/Semantics/Loci/impl/SemanticStrategyImpl.hpp"
#include "fUML/Semantics/Loci/impl/SemanticVisitorImpl.hpp"

#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"

#include "fUML/Semantics/SimpleClassifiers/impl/BooleanValueImpl.hpp"
#include "fUML/Semantics/SimpleClassifiers/impl/CompoundValueImpl.hpp"
#include "fUML/Semantics/SimpleClassifiers/impl/DataValueImpl.hpp"
#include "fUML/Semantics/SimpleClassifiers/impl/EnumerationValueImpl.hpp"
#include "fUML/Semantics/SimpleClassifiers/impl/FeatureValueImpl.hpp"
#include "fUML/Semantics/SimpleClassifiers/impl/IntegerValueImpl.hpp"
#include "fUML/Semantics/SimpleClassifiers/impl/PrimitiveValueImpl.hpp"
#include "fUML/Semantics/SimpleClassifiers/impl/RealValueImpl.hpp"
#include "fUML/Semantics/SimpleClassifiers/impl/SignalInstanceImpl.hpp"
#include "fUML/Semantics/SimpleClassifiers/impl/StringValueImpl.hpp"
#include "fUML/Semantics/SimpleClassifiers/impl/StructuredValueImpl.hpp"
#include "fUML/Semantics/SimpleClassifiers/impl/UnlimitedNaturalValueImpl.hpp"


#include "fUML/Semantics/StructuredClassifiers/impl/DispatchStrategyImpl.hpp"
#include "fUML/Semantics/StructuredClassifiers/impl/ExtensionalValueImpl.hpp"
#include "fUML/Semantics/StructuredClassifiers/impl/ExtensionalValueListImpl.hpp"
#include "fUML/Semantics/StructuredClassifiers/impl/LinkImpl.hpp"
#include "fUML/Semantics/StructuredClassifiers/impl/ObjectImpl.hpp"
#include "fUML/Semantics/StructuredClassifiers/impl/RedefinitionBasedDispatchStrategyImpl.hpp"
#include "fUML/Semantics/StructuredClassifiers/impl/ReferenceImpl.hpp"


#include "fUML/Semantics/Values/impl/EvaluationImpl.hpp"
#include "fUML/Semantics/Values/impl/LiteralBooleanEvaluationImpl.hpp"
#include "fUML/Semantics/Values/impl/LiteralEvaluationImpl.hpp"
#include "fUML/Semantics/Values/impl/LiteralIntegerEvaluationImpl.hpp"
#include "fUML/Semantics/Values/impl/LiteralNullEvaluationImpl.hpp"
#include "fUML/Semantics/Values/impl/LiteralRealEvaluationImpl.hpp"
#include "fUML/Semantics/Values/impl/LiteralStringEvaluationImpl.hpp"
#include "fUML/Semantics/Values/impl/LiteralUnlimitedNaturalEvaluationImpl.hpp"
#include "fUML/Semantics/Values/impl/ValueImpl.hpp"







using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************

FUMLFactoryImpl::FUMLFactoryImpl()
{
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::AcceptCallActionActivation", FUMLPackage::ACCEPTCALLACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::AcceptCallActionActivations", FUMLPackage::ACCEPTCALLACTIONACTIVATIONS_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::AcceptEventActionActivation", FUMLPackage::ACCEPTEVENTACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::AcceptEventActionEventAccepter", FUMLPackage::ACCEPTEVENTACTIONEVENTACCEPTER_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::ActivityEdgeInstance", FUMLPackage::ACTIVITYEDGEINSTANCE_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::ActivityExecution", FUMLPackage::ACTIVITYEXECUTION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::ActivityFinalNodeActivation", FUMLPackage::ACTIVITYFINALNODEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::ActivityNodeActivationGroup", FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::ActivityParameterNodeActivation", FUMLPackage::ACTIVITYPARAMETERNODEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::AddStructuralFeatureValueActionActivation", FUMLPackage::ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::SimpleClassifiers::BooleanValue", FUMLPackage::BOOLEANVALUE_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::CallBehaviorActionActivation", FUMLPackage::CALLBEHAVIORACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::CommonBehavior::CallEventBehavior", FUMLPackage::CALLEVENTBEHAVIOR_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::CommonBehavior::CallEventExecution", FUMLPackage::CALLEVENTEXECUTION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::CommonBehavior::CallEventOccurrence", FUMLPackage::CALLEVENTOCCURRENCE_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::CallOperationActionActivation", FUMLPackage::CALLOPERATIONACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::CentralBufferNodeActivation", FUMLPackage::CENTRALBUFFERNODEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution", FUMLPackage::CLASSIFIERBEHAVIOREXECUTION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::ClassifierBehaviorExecutionActivity", FUMLPackage::CLASSIFIERBEHAVIOREXECUTIONACTIVITY_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1", FUMLPackage::CLASSIFIERBEHAVIOREXECUTIONACTIVITY_OWNEDBEHAVIORACTIVITY1_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::CommonBehavior::ClassifierBehaviorInvocationEventAccepter", FUMLPackage::CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ClauseActivation", FUMLPackage::CLAUSEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ClearAssociationActionActivation", FUMLPackage::CLEARASSOCIATIONACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ClearStructuralFeatureActionActivation", FUMLPackage::CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ConditionalNodeActivation", FUMLPackage::CONDITIONALNODEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::ControlToken", FUMLPackage::CONTROLTOKEN_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::CreateLinkActionActivation", FUMLPackage::CREATELINKACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::CreateObjectActionActivation", FUMLPackage::CREATEOBJECTACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::DataStoreNodeActivation", FUMLPackage::DATASTORENODEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::SimpleClassifiers::DataValue", FUMLPackage::DATAVALUE_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::DecisionNodeActivation", FUMLPackage::DECISIONNODEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::DestroyLinkActionActivation", FUMLPackage::DESTROYLINKACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::DestroyObjectActionActivation", FUMLPackage::DESTROYOBJECTACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::StructuredClassifiers::DispatchStrategy", FUMLPackage::DISPATCHSTRATEGY_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::SimpleClassifiers::EnumerationValue", FUMLPackage::ENUMERATIONVALUE_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::CommonBehavior::EventDispatchLoop", FUMLPackage::EVENTDISPATCHLOOP_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::CommonBehavior::EventOccurrence", FUMLPackage::EVENTOCCURRENCE_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Loci::ExecutionFactory", FUMLPackage::EXECUTIONFACTORY_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Loci::ExecutionFactoryL1", FUMLPackage::EXECUTIONFACTORYL1_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Loci::ExecutionFactoryL2", FUMLPackage::EXECUTIONFACTORYL2_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Loci::ExecutionFactoryL3", FUMLPackage::EXECUTIONFACTORYL3_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Loci::Executor", FUMLPackage::EXECUTOR_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::ExpansionActivationGroup", FUMLPackage::EXPANSIONACTIVATIONGROUP_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::ExpansionNodeActivation", FUMLPackage::EXPANSIONNODEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::ExpansionRegionActivation", FUMLPackage::EXPANSIONREGIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::StructuredClassifiers::ExtensionalValueList", FUMLPackage::EXTENSIONALVALUELIST_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::CommonBehavior::FIFOGetNextEventStrategy", FUMLPackage::FIFOGETNEXTEVENTSTRATEGY_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::SimpleClassifiers::FeatureValue", FUMLPackage::FEATUREVALUE_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Loci::FirstChoiceStrategy", FUMLPackage::FIRSTCHOICESTRATEGY_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::FlowFinalNodeActivation", FUMLPackage::FLOWFINALNODEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::ForkNodeActivation", FUMLPackage::FORKNODEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::ForkedToken", FUMLPackage::FORKEDTOKEN_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::InitialNodeActivation", FUMLPackage::INITIALNODEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::InputPinActivation", FUMLPackage::INPUTPINACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Classification::InstanceValueEvaluation", FUMLPackage::INSTANCEVALUEEVALUATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::SimpleClassifiers::IntegerValue", FUMLPackage::INTEGERVALUE_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::CommonBehavior::InvocationEventOccurrence", FUMLPackage::INVOCATIONEVENTOCCURRENCE_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::JoinNodeActivation", FUMLPackage::JOINNODEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::StructuredClassifiers::Link", FUMLPackage::LINK_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Values::LiteralBooleanEvaluation", FUMLPackage::LITERALBOOLEANEVALUATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Values::LiteralIntegerEvaluation", FUMLPackage::LITERALINTEGEREVALUATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Values::LiteralNullEvaluation", FUMLPackage::LITERALNULLEVALUATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Values::LiteralRealEvaluation", FUMLPackage::LITERALREALEVALUATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Values::LiteralStringEvaluation", FUMLPackage::LITERALSTRINGEVALUATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Values::LiteralUnlimitedNaturalEvaluation", FUMLPackage::LITERALUNLIMITEDNATURALEVALUATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Loci::Locus", FUMLPackage::LOCUS_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::LoopNodeActivation", FUMLPackage::LOOPNODEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::MergeNodeActivation", FUMLPackage::MERGENODEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::StructuredClassifiers::Object", FUMLPackage::OBJECT_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::CommonBehavior::ObjectActivation", FUMLPackage::OBJECTACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::ObjectToken", FUMLPackage::OBJECTTOKEN_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::Offer", FUMLPackage::OFFER_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::OutputPinActivation", FUMLPackage::OUTPUTPINACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::CommonBehavior::ParameterValue", FUMLPackage::PARAMETERVALUE_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ReadExtentActionActivation", FUMLPackage::READEXTENTACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivation", FUMLPackage::READISCLASSIFIEDOBJECTACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ReadLinkActionActivation", FUMLPackage::READLINKACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ReadSelfActionActivation", FUMLPackage::READSELFACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ReadStructuralFeatureActionActivation", FUMLPackage::READSTRUCTURALFEATUREACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::SimpleClassifiers::RealValue", FUMLPackage::REALVALUE_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ReclassifyObjectActionActivation", FUMLPackage::RECLASSIFYOBJECTACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::StructuredClassifiers::RedefinitionBasedDispatchStrategy", FUMLPackage::REDEFINITIONBASEDDISPATCHSTRATEGY_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ReduceActionActivation", FUMLPackage::REDUCEACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::StructuredClassifiers::Reference", FUMLPackage::REFERENCE_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::RemoveStructuralFeatureValueActivation", FUMLPackage::REMOVESTRUCTURALFEATUREVALUEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ReplyActionActivation", FUMLPackage::REPLYACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ReturnInformation", FUMLPackage::RETURNINFORMATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::SendSignalActionActivation", FUMLPackage::SENDSIGNALACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::CommonBehavior::SignalEventOccurrence", FUMLPackage::SIGNALEVENTOCCURRENCE_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::SimpleClassifiers::SignalInstance", FUMLPackage::SIGNALINSTANCE_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::StartClassifierBehaviorActionActivation", FUMLPackage::STARTCLASSIFIERBEHAVIORACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::StartObjectBehaviorActionActivation", FUMLPackage::STARTOBJECTBEHAVIORACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::SimpleClassifiers::StringValue", FUMLPackage::STRINGVALUE_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::StructuredActivityNodeActivation", FUMLPackage::STRUCTUREDACTIVITYNODEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::TestIdentityActionActivation", FUMLPackage::TESTIDENTITYACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::TokenSet", FUMLPackage::TOKENSET_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue", FUMLPackage::UNLIMITEDNATURALVALUE_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ValueSpecificationActionActivation", FUMLPackage::VALUESPECIFICATIONACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::Values", FUMLPackage::VALUES_CLASS));
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

std::shared_ptr<ecore::EObject> FUMLFactoryImpl::create(const int metaElementID, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	switch(metaElementID)
	{
		case FUMLPackage::ACCEPTCALLACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createAcceptCallActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::AcceptCallActionActivation>(this->createAcceptCallActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::ACCEPTCALLACTIONACTIVATIONS_CLASS:
		{
				return this->createAcceptCallActionActivations(metaElementID);
			
		}
		case FUMLPackage::ACCEPTEVENTACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createAcceptEventActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionActivation>(this->createAcceptEventActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::ACCEPTEVENTACTIONEVENTACCEPTER_CLASS:
		{
				return this->createAcceptEventActionEventAccepter(metaElementID);
			
		}
		case FUMLPackage::ACTIVITYEDGEINSTANCE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createActivityEdgeInstance(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance>(this->createActivityEdgeInstance_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::ACTIVITYEXECUTION_CLASS:
		{
				return this->createActivityExecution(metaElementID);
			
		}
		case FUMLPackage::ACTIVITYFINALNODEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createActivityFinalNodeActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Activities::ActivityFinalNodeActivation>(this->createActivityFinalNodeActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createActivityNodeActivationGroup(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ActivityNodeActivationGroup has activityExecution as a containment
					case  FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_ACTIVITYEXECUTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityExecution>(container);
						return this->createActivityNodeActivationGroup_in_ActivityExecution(castedContainer,metaElementID);
					}
					//ActivityNodeActivationGroup has containingNodeActivation as a containment
					case  FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_CONTAININGNODEACTIVATION:
					{
						auto castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Actions::StructuredActivityNodeActivation>(container);
						return this->createActivityNodeActivationGroup_in_ContainingNodeActivation(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case FUMLPackage::ACTIVITYPARAMETERNODEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createActivityParameterNodeActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Activities::ActivityParameterNodeActivation>(this->createActivityParameterNodeActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createAddStructuralFeatureValueActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::AddStructuralFeatureValueActionActivation>(this->createAddStructuralFeatureValueActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::BOOLEANVALUE_CLASS:
		{
				return this->createBooleanValue(metaElementID);
			
		}
		case FUMLPackage::CALLBEHAVIORACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCallBehaviorActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::CallBehaviorActionActivation>(this->createCallBehaviorActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::CALLEVENTBEHAVIOR_CLASS:
		{
				return this->createCallEventBehavior(metaElementID);
			
		}
		case FUMLPackage::CALLEVENTEXECUTION_CLASS:
		{
				return this->createCallEventExecution(metaElementID);
			
		}
		case FUMLPackage::CALLEVENTOCCURRENCE_CLASS:
		{
				return this->createCallEventOccurrence(metaElementID);
			
		}
		case FUMLPackage::CALLOPERATIONACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCallOperationActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::CallOperationActionActivation>(this->createCallOperationActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::CENTRALBUFFERNODEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCentralBufferNodeActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Activities::CentralBufferNodeActivation>(this->createCentralBufferNodeActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::CLASSIFIERBEHAVIOREXECUTION_CLASS:
		{
				return this->createClassifierBehaviorExecution(metaElementID);
			
		}
		case FUMLPackage::CLASSIFIERBEHAVIOREXECUTIONACTIVITY_CLASS:
		{
				return this->createClassifierBehaviorExecutionActivity(metaElementID);
			
		}
		case FUMLPackage::CLASSIFIERBEHAVIOREXECUTIONACTIVITY_OWNEDBEHAVIORACTIVITY1_CLASS:
		{
				return this->createClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1(metaElementID);
			
		}
		case FUMLPackage::CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_CLASS:
		{
				return this->createClassifierBehaviorInvocationEventAccepter(metaElementID);
			
		}
		case FUMLPackage::CLAUSEACTIVATION_CLASS:
		{
				return this->createClauseActivation(metaElementID);
			
		}
		case FUMLPackage::CLEARASSOCIATIONACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createClearAssociationActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::ClearAssociationActionActivation>(this->createClearAssociationActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createClearStructuralFeatureActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::ClearStructuralFeatureActionActivation>(this->createClearStructuralFeatureActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::CONDITIONALNODEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createConditionalNodeActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::ConditionalNodeActivation>(this->createConditionalNodeActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::CONTROLTOKEN_CLASS:
		{
				return this->createControlToken(metaElementID);
			
		}
		case FUMLPackage::CREATELINKACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCreateLinkActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::CreateLinkActionActivation>(this->createCreateLinkActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::CREATEOBJECTACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCreateObjectActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::CreateObjectActionActivation>(this->createCreateObjectActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::DATASTORENODEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createDataStoreNodeActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Activities::DataStoreNodeActivation>(this->createDataStoreNodeActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::DATAVALUE_CLASS:
		{
				return this->createDataValue(metaElementID);
			
		}
		case FUMLPackage::DECISIONNODEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createDecisionNodeActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Activities::DecisionNodeActivation>(this->createDecisionNodeActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::DESTROYLINKACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createDestroyLinkActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::DestroyLinkActionActivation>(this->createDestroyLinkActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::DESTROYOBJECTACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createDestroyObjectActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::DestroyObjectActionActivation>(this->createDestroyObjectActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::DISPATCHSTRATEGY_CLASS:
		{
				return this->createDispatchStrategy(metaElementID);
			
		}
		case FUMLPackage::ENUMERATIONVALUE_CLASS:
		{
				return this->createEnumerationValue(metaElementID);
			
		}
		case FUMLPackage::EVENTDISPATCHLOOP_CLASS:
		{
				return this->createEventDispatchLoop(metaElementID);
			
		}
		case FUMLPackage::EVENTOCCURRENCE_CLASS:
		{
				return this->createEventOccurrence(metaElementID);
			
		}
		case FUMLPackage::EXECUTIONFACTORY_CLASS:
		{
			if (nullptr == container)
			{
				return this->createExecutionFactory(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Loci::Locus> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Loci::Locus>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Loci::ExecutionFactory>(this->createExecutionFactory_in_Locus(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::EXECUTIONFACTORYL1_CLASS:
		{
			if (nullptr == container)
			{
				return this->createExecutionFactoryL1(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Loci::Locus> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Loci::Locus>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Loci::ExecutionFactoryL1>(this->createExecutionFactoryL1_in_Locus(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::EXECUTIONFACTORYL2_CLASS:
		{
			if (nullptr == container)
			{
				return this->createExecutionFactoryL2(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Loci::Locus> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Loci::Locus>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Loci::ExecutionFactoryL2>(this->createExecutionFactoryL2_in_Locus(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::EXECUTIONFACTORYL3_CLASS:
		{
			if (nullptr == container)
			{
				return this->createExecutionFactoryL3(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Loci::Locus> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Loci::Locus>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Loci::ExecutionFactoryL3>(this->createExecutionFactoryL3_in_Locus(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::EXECUTOR_CLASS:
		{
			if (nullptr == container)
			{
				return this->createExecutor(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Loci::Locus> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Loci::Locus>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Loci::Executor>(this->createExecutor_in_Locus(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::EXPANSIONACTIVATIONGROUP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createExpansionActivationGroup(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ExpansionActivationGroup has activityExecution as a containment
					case  FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_ACTIVITYEXECUTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityExecution>(container);
						return this->createExpansionActivationGroup_in_ActivityExecution(castedContainer,metaElementID);
					}
					//ExpansionActivationGroup has containingNodeActivation as a containment
					case  FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_CONTAININGNODEACTIVATION:
					{
						auto castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Actions::StructuredActivityNodeActivation>(container);
						return this->createExpansionActivationGroup_in_ContainingNodeActivation(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case FUMLPackage::EXPANSIONNODEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createExpansionNodeActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivation>(this->createExpansionNodeActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::EXPANSIONREGIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createExpansionRegionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Activities::ExpansionRegionActivation>(this->createExpansionRegionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::EXTENSIONALVALUELIST_CLASS:
		{
				return this->createExtensionalValueList(metaElementID);
			
		}
		case FUMLPackage::FIFOGETNEXTEVENTSTRATEGY_CLASS:
		{
				return this->createFIFOGetNextEventStrategy(metaElementID);
			
		}
		case FUMLPackage::FEATUREVALUE_CLASS:
		{
				return this->createFeatureValue(metaElementID);
			
		}
		case FUMLPackage::FIRSTCHOICESTRATEGY_CLASS:
		{
				return this->createFirstChoiceStrategy(metaElementID);
			
		}
		case FUMLPackage::FLOWFINALNODEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createFlowFinalNodeActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Activities::FlowFinalNodeActivation>(this->createFlowFinalNodeActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::FORKNODEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createForkNodeActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Activities::ForkNodeActivation>(this->createForkNodeActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::FORKEDTOKEN_CLASS:
		{
				return this->createForkedToken(metaElementID);
			
		}
		case FUMLPackage::INITIALNODEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createInitialNodeActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Activities::InitialNodeActivation>(this->createInitialNodeActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::INPUTPINACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createInputPinActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::InputPinActivation>(this->createInputPinActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::INSTANCEVALUEEVALUATION_CLASS:
		{
				return this->createInstanceValueEvaluation(metaElementID);
			
		}
		case FUMLPackage::INTEGERVALUE_CLASS:
		{
				return this->createIntegerValue(metaElementID);
			
		}
		case FUMLPackage::INVOCATIONEVENTOCCURRENCE_CLASS:
		{
				return this->createInvocationEventOccurrence(metaElementID);
			
		}
		case FUMLPackage::JOINNODEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createJoinNodeActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Activities::JoinNodeActivation>(this->createJoinNodeActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::LINK_CLASS:
		{
				return this->createLink(metaElementID);
			
		}
		case FUMLPackage::LITERALBOOLEANEVALUATION_CLASS:
		{
				return this->createLiteralBooleanEvaluation(metaElementID);
			
		}
		case FUMLPackage::LITERALINTEGEREVALUATION_CLASS:
		{
				return this->createLiteralIntegerEvaluation(metaElementID);
			
		}
		case FUMLPackage::LITERALNULLEVALUATION_CLASS:
		{
				return this->createLiteralNullEvaluation(metaElementID);
			
		}
		case FUMLPackage::LITERALREALEVALUATION_CLASS:
		{
				return this->createLiteralRealEvaluation(metaElementID);
			
		}
		case FUMLPackage::LITERALSTRINGEVALUATION_CLASS:
		{
				return this->createLiteralStringEvaluation(metaElementID);
			
		}
		case FUMLPackage::LITERALUNLIMITEDNATURALEVALUATION_CLASS:
		{
				return this->createLiteralUnlimitedNaturalEvaluation(metaElementID);
			
		}
		case FUMLPackage::LOCUS_CLASS:
		{
				return this->createLocus(metaElementID);
			
		}
		case FUMLPackage::LOOPNODEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createLoopNodeActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::LoopNodeActivation>(this->createLoopNodeActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::MERGENODEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createMergeNodeActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Activities::MergeNodeActivation>(this->createMergeNodeActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::OBJECT_CLASS:
		{
				return this->createObject(metaElementID);
			
		}
		case FUMLPackage::OBJECTACTIVATION_CLASS:
		{
				return this->createObjectActivation(metaElementID);
			
		}
		case FUMLPackage::OBJECTTOKEN_CLASS:
		{
				return this->createObjectToken(metaElementID);
			
		}
		case FUMLPackage::OFFER_CLASS:
		{
				return this->createOffer(metaElementID);
			
		}
		case FUMLPackage::OUTPUTPINACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createOutputPinActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation>(this->createOutputPinActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::PARAMETERVALUE_CLASS:
		{
				return this->createParameterValue(metaElementID);
			
		}
		case FUMLPackage::READEXTENTACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createReadExtentActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::ReadExtentActionActivation>(this->createReadExtentActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::READISCLASSIFIEDOBJECTACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createReadIsClassifiedObjectActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivation>(this->createReadIsClassifiedObjectActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::READLINKACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createReadLinkActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::ReadLinkActionActivation>(this->createReadLinkActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::READSELFACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createReadSelfActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::ReadSelfActionActivation>(this->createReadSelfActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::READSTRUCTURALFEATUREACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createReadStructuralFeatureActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::ReadStructuralFeatureActionActivation>(this->createReadStructuralFeatureActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::REALVALUE_CLASS:
		{
				return this->createRealValue(metaElementID);
			
		}
		case FUMLPackage::RECLASSIFYOBJECTACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createReclassifyObjectActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::ReclassifyObjectActionActivation>(this->createReclassifyObjectActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::REDEFINITIONBASEDDISPATCHSTRATEGY_CLASS:
		{
				return this->createRedefinitionBasedDispatchStrategy(metaElementID);
			
		}
		case FUMLPackage::REDUCEACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createReduceActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::ReduceActionActivation>(this->createReduceActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::REFERENCE_CLASS:
		{
				return this->createReference(metaElementID);
			
		}
		case FUMLPackage::REMOVESTRUCTURALFEATUREVALUEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createRemoveStructuralFeatureValueActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActivation>(this->createRemoveStructuralFeatureValueActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::REPLYACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createReplyActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::ReplyActionActivation>(this->createReplyActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::RETURNINFORMATION_CLASS:
		{
				return this->createReturnInformation(metaElementID);
			
		}
		case FUMLPackage::SENDSIGNALACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createSendSignalActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::SendSignalActionActivation>(this->createSendSignalActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::SIGNALEVENTOCCURRENCE_CLASS:
		{
				return this->createSignalEventOccurrence(metaElementID);
			
		}
		case FUMLPackage::SIGNALINSTANCE_CLASS:
		{
				return this->createSignalInstance(metaElementID);
			
		}
		case FUMLPackage::STARTCLASSIFIERBEHAVIORACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createStartClassifierBehaviorActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::StartClassifierBehaviorActionActivation>(this->createStartClassifierBehaviorActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::STARTOBJECTBEHAVIORACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createStartObjectBehaviorActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::StartObjectBehaviorActionActivation>(this->createStartObjectBehaviorActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::STRINGVALUE_CLASS:
		{
				return this->createStringValue(metaElementID);
			
		}
		case FUMLPackage::STRUCTUREDACTIVITYNODEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createStructuredActivityNodeActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation>(this->createStructuredActivityNodeActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::TESTIDENTITYACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createTestIdentityActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::TestIdentityActionActivation>(this->createTestIdentityActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::TOKENSET_CLASS:
		{
				return this->createTokenSet(metaElementID);
			
		}
		case FUMLPackage::UNLIMITEDNATURALVALUE_CLASS:
		{
				return this->createUnlimitedNaturalValue(metaElementID);
			
		}
		case FUMLPackage::VALUESPECIFICATIONACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createValueSpecificationActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::ValueSpecificationActionActivation>(this->createValueSpecificationActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case FUMLPackage::VALUES_CLASS:
		{
				return this->createValues(metaElementID);
			
		}
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << metaElementID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<ecore::EObject> FUMLFactoryImpl::create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}
	int _elementID = _class->getMetaElementID();
	return create(_elementID, container, referenceID);
}

std::shared_ptr<ecore::EObject> FUMLFactoryImpl::create(std::string _className, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
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

std::shared_ptr<fUML::Semantics::Actions::AcceptCallActionActivation> FUMLFactoryImpl::createAcceptCallActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::AcceptCallActionActivationImpl> element(new fUML::Semantics::Actions::AcceptCallActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisAcceptCallActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::AcceptCallActionActivation> FUMLFactoryImpl::createAcceptCallActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::AcceptCallActionActivationImpl> element(new fUML::Semantics::Actions::AcceptCallActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisAcceptCallActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::AcceptCallActionActivations> FUMLFactoryImpl::createAcceptCallActionActivations(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::AcceptCallActionActivationsImpl> element(new fUML::Semantics::Actions::AcceptCallActionActivationsImpl());
	element->setMetaElementID(metaElementID);
	element->setThisAcceptCallActionActivationsPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionActivation> FUMLFactoryImpl::createAcceptEventActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionActivationImpl> element(new fUML::Semantics::Actions::AcceptEventActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisAcceptEventActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionActivation> FUMLFactoryImpl::createAcceptEventActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionActivationImpl> element(new fUML::Semantics::Actions::AcceptEventActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisAcceptEventActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionEventAccepter> FUMLFactoryImpl::createAcceptEventActionEventAccepter(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionEventAccepterImpl> element(new fUML::Semantics::Actions::AcceptEventActionEventAccepterImpl());
	element->setMetaElementID(metaElementID);
	element->setThisAcceptEventActionEventAccepterPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> FUMLFactoryImpl::createActivityEdgeInstance(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstanceImpl> element(new fUML::Semantics::Activities::ActivityEdgeInstanceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisActivityEdgeInstancePtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> FUMLFactoryImpl::createActivityEdgeInstance_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstanceImpl> element(new fUML::Semantics::Activities::ActivityEdgeInstanceImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getEdgeInstances()->push_back(element);
	}
	element->setThisActivityEdgeInstancePtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::ActivityExecution> FUMLFactoryImpl::createActivityExecution(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::ActivityExecutionImpl> element(new fUML::Semantics::Activities::ActivityExecutionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisActivityExecutionPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::ActivityFinalNodeActivation> FUMLFactoryImpl::createActivityFinalNodeActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::ActivityFinalNodeActivationImpl> element(new fUML::Semantics::Activities::ActivityFinalNodeActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisActivityFinalNodeActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::ActivityFinalNodeActivation> FUMLFactoryImpl::createActivityFinalNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::ActivityFinalNodeActivationImpl> element(new fUML::Semantics::Activities::ActivityFinalNodeActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisActivityFinalNodeActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> FUMLFactoryImpl::createActivityNodeActivationGroup(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroupImpl> element(new fUML::Semantics::Activities::ActivityNodeActivationGroupImpl());
	element->setMetaElementID(metaElementID);
	element->setThisActivityNodeActivationGroupPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> FUMLFactoryImpl::createActivityNodeActivationGroup_in_ActivityExecution(std::weak_ptr<fUML::Semantics::Activities::ActivityExecution > par_activityExecution, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroupImpl> element(new fUML::Semantics::Activities::ActivityNodeActivationGroupImpl(par_activityExecution));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activityExecution.lock())
	{
			wp->setActivationGroup(element);
	}
	element->setThisActivityNodeActivationGroupPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> FUMLFactoryImpl::createActivityNodeActivationGroup_in_ContainingNodeActivation(std::weak_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation > par_containingNodeActivation, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroupImpl> element(new fUML::Semantics::Activities::ActivityNodeActivationGroupImpl(par_containingNodeActivation));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_containingNodeActivation.lock())
	{
			wp->setActivationGroup(element);
	}
	element->setThisActivityNodeActivationGroupPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::ActivityParameterNodeActivation> FUMLFactoryImpl::createActivityParameterNodeActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::ActivityParameterNodeActivationImpl> element(new fUML::Semantics::Activities::ActivityParameterNodeActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisActivityParameterNodeActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::ActivityParameterNodeActivation> FUMLFactoryImpl::createActivityParameterNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::ActivityParameterNodeActivationImpl> element(new fUML::Semantics::Activities::ActivityParameterNodeActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisActivityParameterNodeActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::AddStructuralFeatureValueActionActivation> FUMLFactoryImpl::createAddStructuralFeatureValueActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl> element(new fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisAddStructuralFeatureValueActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::AddStructuralFeatureValueActionActivation> FUMLFactoryImpl::createAddStructuralFeatureValueActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl> element(new fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisAddStructuralFeatureValueActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> FUMLFactoryImpl::createBooleanValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValueImpl> element(new fUML::Semantics::SimpleClassifiers::BooleanValueImpl());
	element->setMetaElementID(metaElementID);
	element->setThisBooleanValuePtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::CallBehaviorActionActivation> FUMLFactoryImpl::createCallBehaviorActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::CallBehaviorActionActivationImpl> element(new fUML::Semantics::Actions::CallBehaviorActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCallBehaviorActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::CallBehaviorActionActivation> FUMLFactoryImpl::createCallBehaviorActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::CallBehaviorActionActivationImpl> element(new fUML::Semantics::Actions::CallBehaviorActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisCallBehaviorActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventBehavior> FUMLFactoryImpl::createCallEventBehavior(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventBehaviorImpl> element(new fUML::Semantics::CommonBehavior::CallEventBehaviorImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCallEventBehaviorPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventExecution> FUMLFactoryImpl::createCallEventExecution(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventExecutionImpl> element(new fUML::Semantics::CommonBehavior::CallEventExecutionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCallEventExecutionPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventOccurrence> FUMLFactoryImpl::createCallEventOccurrence(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventOccurrenceImpl> element(new fUML::Semantics::CommonBehavior::CallEventOccurrenceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCallEventOccurrencePtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::CallOperationActionActivation> FUMLFactoryImpl::createCallOperationActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::CallOperationActionActivationImpl> element(new fUML::Semantics::Actions::CallOperationActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCallOperationActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::CallOperationActionActivation> FUMLFactoryImpl::createCallOperationActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::CallOperationActionActivationImpl> element(new fUML::Semantics::Actions::CallOperationActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisCallOperationActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::CentralBufferNodeActivation> FUMLFactoryImpl::createCentralBufferNodeActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::CentralBufferNodeActivationImpl> element(new fUML::Semantics::Activities::CentralBufferNodeActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCentralBufferNodeActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::CentralBufferNodeActivation> FUMLFactoryImpl::createCentralBufferNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::CentralBufferNodeActivationImpl> element(new fUML::Semantics::Activities::CentralBufferNodeActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisCentralBufferNodeActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution> FUMLFactoryImpl::createClassifierBehaviorExecution(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecutionImpl> element(new fUML::Semantics::CommonBehavior::ClassifierBehaviorExecutionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisClassifierBehaviorExecutionPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::ClassifierBehaviorExecutionActivity> FUMLFactoryImpl::createClassifierBehaviorExecutionActivity(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::ClassifierBehaviorExecutionActivityImpl> element(new fUML::Semantics::Activities::ClassifierBehaviorExecutionActivityImpl());
	element->setMetaElementID(metaElementID);
	element->setThisClassifierBehaviorExecutionActivityPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1> FUMLFactoryImpl::createClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl> element(new fUML::Semantics::Activities::ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl());
	element->setMetaElementID(metaElementID);
	element->setThisClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Ptr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorInvocationEventAccepter> FUMLFactoryImpl::createClassifierBehaviorInvocationEventAccepter(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorInvocationEventAccepterImpl> element(new fUML::Semantics::CommonBehavior::ClassifierBehaviorInvocationEventAccepterImpl());
	element->setMetaElementID(metaElementID);
	element->setThisClassifierBehaviorInvocationEventAccepterPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ClauseActivation> FUMLFactoryImpl::createClauseActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ClauseActivationImpl> element(new fUML::Semantics::Actions::ClauseActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisClauseActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ClearAssociationActionActivation> FUMLFactoryImpl::createClearAssociationActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ClearAssociationActionActivationImpl> element(new fUML::Semantics::Actions::ClearAssociationActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisClearAssociationActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ClearAssociationActionActivation> FUMLFactoryImpl::createClearAssociationActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ClearAssociationActionActivationImpl> element(new fUML::Semantics::Actions::ClearAssociationActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisClearAssociationActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::ClearStructuralFeatureActionActivation> FUMLFactoryImpl::createClearStructuralFeatureActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ClearStructuralFeatureActionActivationImpl> element(new fUML::Semantics::Actions::ClearStructuralFeatureActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisClearStructuralFeatureActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ClearStructuralFeatureActionActivation> FUMLFactoryImpl::createClearStructuralFeatureActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ClearStructuralFeatureActionActivationImpl> element(new fUML::Semantics::Actions::ClearStructuralFeatureActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisClearStructuralFeatureActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::ConditionalNodeActivation> FUMLFactoryImpl::createConditionalNodeActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ConditionalNodeActivationImpl> element(new fUML::Semantics::Actions::ConditionalNodeActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisConditionalNodeActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ConditionalNodeActivation> FUMLFactoryImpl::createConditionalNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ConditionalNodeActivationImpl> element(new fUML::Semantics::Actions::ConditionalNodeActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisConditionalNodeActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::ControlToken> FUMLFactoryImpl::createControlToken(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::ControlTokenImpl> element(new fUML::Semantics::Activities::ControlTokenImpl());
	element->setMetaElementID(metaElementID);
	element->setThisControlTokenPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::CreateLinkActionActivation> FUMLFactoryImpl::createCreateLinkActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::CreateLinkActionActivationImpl> element(new fUML::Semantics::Actions::CreateLinkActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCreateLinkActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::CreateLinkActionActivation> FUMLFactoryImpl::createCreateLinkActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::CreateLinkActionActivationImpl> element(new fUML::Semantics::Actions::CreateLinkActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisCreateLinkActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::CreateObjectActionActivation> FUMLFactoryImpl::createCreateObjectActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::CreateObjectActionActivationImpl> element(new fUML::Semantics::Actions::CreateObjectActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCreateObjectActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::CreateObjectActionActivation> FUMLFactoryImpl::createCreateObjectActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::CreateObjectActionActivationImpl> element(new fUML::Semantics::Actions::CreateObjectActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisCreateObjectActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::DataStoreNodeActivation> FUMLFactoryImpl::createDataStoreNodeActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::DataStoreNodeActivationImpl> element(new fUML::Semantics::Activities::DataStoreNodeActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDataStoreNodeActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::DataStoreNodeActivation> FUMLFactoryImpl::createDataStoreNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::DataStoreNodeActivationImpl> element(new fUML::Semantics::Activities::DataStoreNodeActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisDataStoreNodeActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::DataValue> FUMLFactoryImpl::createDataValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::DataValueImpl> element(new fUML::Semantics::SimpleClassifiers::DataValueImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDataValuePtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::DecisionNodeActivation> FUMLFactoryImpl::createDecisionNodeActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::DecisionNodeActivationImpl> element(new fUML::Semantics::Activities::DecisionNodeActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDecisionNodeActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::DecisionNodeActivation> FUMLFactoryImpl::createDecisionNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::DecisionNodeActivationImpl> element(new fUML::Semantics::Activities::DecisionNodeActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisDecisionNodeActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::DestroyLinkActionActivation> FUMLFactoryImpl::createDestroyLinkActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::DestroyLinkActionActivationImpl> element(new fUML::Semantics::Actions::DestroyLinkActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDestroyLinkActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::DestroyLinkActionActivation> FUMLFactoryImpl::createDestroyLinkActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::DestroyLinkActionActivationImpl> element(new fUML::Semantics::Actions::DestroyLinkActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisDestroyLinkActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::DestroyObjectActionActivation> FUMLFactoryImpl::createDestroyObjectActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::DestroyObjectActionActivationImpl> element(new fUML::Semantics::Actions::DestroyObjectActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDestroyObjectActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::DestroyObjectActionActivation> FUMLFactoryImpl::createDestroyObjectActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::DestroyObjectActionActivationImpl> element(new fUML::Semantics::Actions::DestroyObjectActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisDestroyObjectActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::StructuredClassifiers::DispatchStrategy> FUMLFactoryImpl::createDispatchStrategy(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::DispatchStrategyImpl> element(new fUML::Semantics::StructuredClassifiers::DispatchStrategyImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDispatchStrategyPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> FUMLFactoryImpl::createEnumerationValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValueImpl> element(new fUML::Semantics::SimpleClassifiers::EnumerationValueImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEnumerationValuePtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::CommonBehavior::EventDispatchLoop> FUMLFactoryImpl::createEventDispatchLoop(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::EventDispatchLoopImpl> element(new fUML::Semantics::CommonBehavior::EventDispatchLoopImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEventDispatchLoopPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> FUMLFactoryImpl::createEventOccurrence(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrenceImpl> element(new fUML::Semantics::CommonBehavior::EventOccurrenceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEventOccurrencePtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Loci::ExecutionFactory> FUMLFactoryImpl::createExecutionFactory(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Loci::ExecutionFactoryImpl> element(new fUML::Semantics::Loci::ExecutionFactoryImpl());
	element->setMetaElementID(metaElementID);
	element->setThisExecutionFactoryPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Loci::ExecutionFactory> FUMLFactoryImpl::createExecutionFactory_in_Locus(std::weak_ptr<fUML::Semantics::Loci::Locus > par_locus, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Loci::ExecutionFactoryImpl> element(new fUML::Semantics::Loci::ExecutionFactoryImpl(par_locus));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_locus.lock())
	{
			wp->setFactory(element);
	}
	element->setThisExecutionFactoryPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Loci::ExecutionFactoryL1> FUMLFactoryImpl::createExecutionFactoryL1(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Loci::ExecutionFactoryL1Impl> element(new fUML::Semantics::Loci::ExecutionFactoryL1Impl());
	element->setMetaElementID(metaElementID);
	element->setThisExecutionFactoryL1Ptr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Loci::ExecutionFactoryL1> FUMLFactoryImpl::createExecutionFactoryL1_in_Locus(std::weak_ptr<fUML::Semantics::Loci::Locus > par_locus, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Loci::ExecutionFactoryL1Impl> element(new fUML::Semantics::Loci::ExecutionFactoryL1Impl(par_locus));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_locus.lock())
	{
			wp->setFactory(element);
	}
	element->setThisExecutionFactoryL1Ptr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Loci::ExecutionFactoryL2> FUMLFactoryImpl::createExecutionFactoryL2(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Loci::ExecutionFactoryL2Impl> element(new fUML::Semantics::Loci::ExecutionFactoryL2Impl());
	element->setMetaElementID(metaElementID);
	element->setThisExecutionFactoryL2Ptr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Loci::ExecutionFactoryL2> FUMLFactoryImpl::createExecutionFactoryL2_in_Locus(std::weak_ptr<fUML::Semantics::Loci::Locus > par_locus, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Loci::ExecutionFactoryL2Impl> element(new fUML::Semantics::Loci::ExecutionFactoryL2Impl(par_locus));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_locus.lock())
	{
			wp->setFactory(element);
	}
	element->setThisExecutionFactoryL2Ptr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Loci::ExecutionFactoryL3> FUMLFactoryImpl::createExecutionFactoryL3(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Loci::ExecutionFactoryL3Impl> element(new fUML::Semantics::Loci::ExecutionFactoryL3Impl());
	element->setMetaElementID(metaElementID);
	element->setThisExecutionFactoryL3Ptr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Loci::ExecutionFactoryL3> FUMLFactoryImpl::createExecutionFactoryL3_in_Locus(std::weak_ptr<fUML::Semantics::Loci::Locus > par_locus, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Loci::ExecutionFactoryL3Impl> element(new fUML::Semantics::Loci::ExecutionFactoryL3Impl(par_locus));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_locus.lock())
	{
			wp->setFactory(element);
	}
	element->setThisExecutionFactoryL3Ptr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Loci::Executor> FUMLFactoryImpl::createExecutor(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Loci::ExecutorImpl> element(new fUML::Semantics::Loci::ExecutorImpl());
	element->setMetaElementID(metaElementID);
	element->setThisExecutorPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Loci::Executor> FUMLFactoryImpl::createExecutor_in_Locus(std::weak_ptr<fUML::Semantics::Loci::Locus > par_locus, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Loci::ExecutorImpl> element(new fUML::Semantics::Loci::ExecutorImpl(par_locus));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_locus.lock())
	{
			wp->setExecutor(element);
	}
	element->setThisExecutorPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::ExpansionActivationGroup> FUMLFactoryImpl::createExpansionActivationGroup(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::ExpansionActivationGroupImpl> element(new fUML::Semantics::Activities::ExpansionActivationGroupImpl());
	element->setMetaElementID(metaElementID);
	element->setThisExpansionActivationGroupPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::ExpansionActivationGroup> FUMLFactoryImpl::createExpansionActivationGroup_in_ActivityExecution(std::weak_ptr<fUML::Semantics::Activities::ActivityExecution > par_activityExecution, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::ExpansionActivationGroupImpl> element(new fUML::Semantics::Activities::ExpansionActivationGroupImpl(par_activityExecution));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activityExecution.lock())
	{
			wp->setActivationGroup(element);
	}
	element->setThisExpansionActivationGroupPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::ExpansionActivationGroup> FUMLFactoryImpl::createExpansionActivationGroup_in_ContainingNodeActivation(std::weak_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation > par_containingNodeActivation, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::ExpansionActivationGroupImpl> element(new fUML::Semantics::Activities::ExpansionActivationGroupImpl(par_containingNodeActivation));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_containingNodeActivation.lock())
	{
			wp->setActivationGroup(element);
	}
	element->setThisExpansionActivationGroupPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivation> FUMLFactoryImpl::createExpansionNodeActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivationImpl> element(new fUML::Semantics::Activities::ExpansionNodeActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisExpansionNodeActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivation> FUMLFactoryImpl::createExpansionNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivationImpl> element(new fUML::Semantics::Activities::ExpansionNodeActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisExpansionNodeActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::ExpansionRegionActivation> FUMLFactoryImpl::createExpansionRegionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::ExpansionRegionActivationImpl> element(new fUML::Semantics::Activities::ExpansionRegionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisExpansionRegionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::ExpansionRegionActivation> FUMLFactoryImpl::createExpansionRegionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::ExpansionRegionActivationImpl> element(new fUML::Semantics::Activities::ExpansionRegionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisExpansionRegionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValueList> FUMLFactoryImpl::createExtensionalValueList(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValueListImpl> element(new fUML::Semantics::StructuredClassifiers::ExtensionalValueListImpl());
	element->setMetaElementID(metaElementID);
	element->setThisExtensionalValueListPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::CommonBehavior::FIFOGetNextEventStrategy> FUMLFactoryImpl::createFIFOGetNextEventStrategy(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::FIFOGetNextEventStrategyImpl> element(new fUML::Semantics::CommonBehavior::FIFOGetNextEventStrategyImpl());
	element->setMetaElementID(metaElementID);
	element->setThisFIFOGetNextEventStrategyPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> FUMLFactoryImpl::createFeatureValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValueImpl> element(new fUML::Semantics::SimpleClassifiers::FeatureValueImpl());
	element->setMetaElementID(metaElementID);
	element->setThisFeatureValuePtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Loci::FirstChoiceStrategy> FUMLFactoryImpl::createFirstChoiceStrategy(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Loci::FirstChoiceStrategyImpl> element(new fUML::Semantics::Loci::FirstChoiceStrategyImpl());
	element->setMetaElementID(metaElementID);
	element->setThisFirstChoiceStrategyPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::FlowFinalNodeActivation> FUMLFactoryImpl::createFlowFinalNodeActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::FlowFinalNodeActivationImpl> element(new fUML::Semantics::Activities::FlowFinalNodeActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisFlowFinalNodeActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::FlowFinalNodeActivation> FUMLFactoryImpl::createFlowFinalNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::FlowFinalNodeActivationImpl> element(new fUML::Semantics::Activities::FlowFinalNodeActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisFlowFinalNodeActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::ForkNodeActivation> FUMLFactoryImpl::createForkNodeActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::ForkNodeActivationImpl> element(new fUML::Semantics::Activities::ForkNodeActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisForkNodeActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::ForkNodeActivation> FUMLFactoryImpl::createForkNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::ForkNodeActivationImpl> element(new fUML::Semantics::Activities::ForkNodeActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisForkNodeActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::ForkedToken> FUMLFactoryImpl::createForkedToken(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::ForkedTokenImpl> element(new fUML::Semantics::Activities::ForkedTokenImpl());
	element->setMetaElementID(metaElementID);
	element->setThisForkedTokenPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::InitialNodeActivation> FUMLFactoryImpl::createInitialNodeActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::InitialNodeActivationImpl> element(new fUML::Semantics::Activities::InitialNodeActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisInitialNodeActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::InitialNodeActivation> FUMLFactoryImpl::createInitialNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::InitialNodeActivationImpl> element(new fUML::Semantics::Activities::InitialNodeActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisInitialNodeActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> FUMLFactoryImpl::createInputPinActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::InputPinActivationImpl> element(new fUML::Semantics::Actions::InputPinActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisInputPinActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> FUMLFactoryImpl::createInputPinActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::InputPinActivationImpl> element(new fUML::Semantics::Actions::InputPinActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisInputPinActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Classification::InstanceValueEvaluation> FUMLFactoryImpl::createInstanceValueEvaluation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Classification::InstanceValueEvaluationImpl> element(new fUML::Semantics::Classification::InstanceValueEvaluationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisInstanceValueEvaluationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> FUMLFactoryImpl::createIntegerValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValueImpl> element(new fUML::Semantics::SimpleClassifiers::IntegerValueImpl());
	element->setMetaElementID(metaElementID);
	element->setThisIntegerValuePtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::CommonBehavior::InvocationEventOccurrence> FUMLFactoryImpl::createInvocationEventOccurrence(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::InvocationEventOccurrenceImpl> element(new fUML::Semantics::CommonBehavior::InvocationEventOccurrenceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisInvocationEventOccurrencePtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::JoinNodeActivation> FUMLFactoryImpl::createJoinNodeActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::JoinNodeActivationImpl> element(new fUML::Semantics::Activities::JoinNodeActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisJoinNodeActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::JoinNodeActivation> FUMLFactoryImpl::createJoinNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::JoinNodeActivationImpl> element(new fUML::Semantics::Activities::JoinNodeActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisJoinNodeActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::StructuredClassifiers::Link> FUMLFactoryImpl::createLink(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::LinkImpl> element(new fUML::Semantics::StructuredClassifiers::LinkImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLinkPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Values::LiteralBooleanEvaluation> FUMLFactoryImpl::createLiteralBooleanEvaluation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Values::LiteralBooleanEvaluationImpl> element(new fUML::Semantics::Values::LiteralBooleanEvaluationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLiteralBooleanEvaluationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Values::LiteralIntegerEvaluation> FUMLFactoryImpl::createLiteralIntegerEvaluation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Values::LiteralIntegerEvaluationImpl> element(new fUML::Semantics::Values::LiteralIntegerEvaluationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLiteralIntegerEvaluationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Values::LiteralNullEvaluation> FUMLFactoryImpl::createLiteralNullEvaluation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Values::LiteralNullEvaluationImpl> element(new fUML::Semantics::Values::LiteralNullEvaluationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLiteralNullEvaluationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Values::LiteralRealEvaluation> FUMLFactoryImpl::createLiteralRealEvaluation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Values::LiteralRealEvaluationImpl> element(new fUML::Semantics::Values::LiteralRealEvaluationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLiteralRealEvaluationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Values::LiteralStringEvaluation> FUMLFactoryImpl::createLiteralStringEvaluation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Values::LiteralStringEvaluationImpl> element(new fUML::Semantics::Values::LiteralStringEvaluationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLiteralStringEvaluationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Values::LiteralUnlimitedNaturalEvaluation> FUMLFactoryImpl::createLiteralUnlimitedNaturalEvaluation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Values::LiteralUnlimitedNaturalEvaluationImpl> element(new fUML::Semantics::Values::LiteralUnlimitedNaturalEvaluationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLiteralUnlimitedNaturalEvaluationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Loci::Locus> FUMLFactoryImpl::createLocus(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Loci::LocusImpl> element(new fUML::Semantics::Loci::LocusImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLocusPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::LoopNodeActivation> FUMLFactoryImpl::createLoopNodeActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::LoopNodeActivationImpl> element(new fUML::Semantics::Actions::LoopNodeActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLoopNodeActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::LoopNodeActivation> FUMLFactoryImpl::createLoopNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::LoopNodeActivationImpl> element(new fUML::Semantics::Actions::LoopNodeActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisLoopNodeActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::MergeNodeActivation> FUMLFactoryImpl::createMergeNodeActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::MergeNodeActivationImpl> element(new fUML::Semantics::Activities::MergeNodeActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisMergeNodeActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::MergeNodeActivation> FUMLFactoryImpl::createMergeNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::MergeNodeActivationImpl> element(new fUML::Semantics::Activities::MergeNodeActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisMergeNodeActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> FUMLFactoryImpl::createObject(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::ObjectImpl> element(new fUML::Semantics::StructuredClassifiers::ObjectImpl());
	element->setMetaElementID(metaElementID);
	element->setThisObjectPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> FUMLFactoryImpl::createObjectActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivationImpl> element(new fUML::Semantics::CommonBehavior::ObjectActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisObjectActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::ObjectToken> FUMLFactoryImpl::createObjectToken(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::ObjectTokenImpl> element(new fUML::Semantics::Activities::ObjectTokenImpl());
	element->setMetaElementID(metaElementID);
	element->setThisObjectTokenPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::Offer> FUMLFactoryImpl::createOffer(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::OfferImpl> element(new fUML::Semantics::Activities::OfferImpl());
	element->setMetaElementID(metaElementID);
	element->setThisOfferPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> FUMLFactoryImpl::createOutputPinActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::OutputPinActivationImpl> element(new fUML::Semantics::Actions::OutputPinActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisOutputPinActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> FUMLFactoryImpl::createOutputPinActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::OutputPinActivationImpl> element(new fUML::Semantics::Actions::OutputPinActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisOutputPinActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> FUMLFactoryImpl::createParameterValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValueImpl> element(new fUML::Semantics::CommonBehavior::ParameterValueImpl());
	element->setMetaElementID(metaElementID);
	element->setThisParameterValuePtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ReadExtentActionActivation> FUMLFactoryImpl::createReadExtentActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReadExtentActionActivationImpl> element(new fUML::Semantics::Actions::ReadExtentActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReadExtentActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ReadExtentActionActivation> FUMLFactoryImpl::createReadExtentActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReadExtentActionActivationImpl> element(new fUML::Semantics::Actions::ReadExtentActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisReadExtentActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivation> FUMLFactoryImpl::createReadIsClassifiedObjectActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivationImpl> element(new fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReadIsClassifiedObjectActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivation> FUMLFactoryImpl::createReadIsClassifiedObjectActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivationImpl> element(new fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisReadIsClassifiedObjectActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::ReadLinkActionActivation> FUMLFactoryImpl::createReadLinkActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReadLinkActionActivationImpl> element(new fUML::Semantics::Actions::ReadLinkActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReadLinkActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ReadLinkActionActivation> FUMLFactoryImpl::createReadLinkActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReadLinkActionActivationImpl> element(new fUML::Semantics::Actions::ReadLinkActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisReadLinkActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::ReadSelfActionActivation> FUMLFactoryImpl::createReadSelfActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReadSelfActionActivationImpl> element(new fUML::Semantics::Actions::ReadSelfActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReadSelfActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ReadSelfActionActivation> FUMLFactoryImpl::createReadSelfActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReadSelfActionActivationImpl> element(new fUML::Semantics::Actions::ReadSelfActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisReadSelfActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::ReadStructuralFeatureActionActivation> FUMLFactoryImpl::createReadStructuralFeatureActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReadStructuralFeatureActionActivationImpl> element(new fUML::Semantics::Actions::ReadStructuralFeatureActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReadStructuralFeatureActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ReadStructuralFeatureActionActivation> FUMLFactoryImpl::createReadStructuralFeatureActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReadStructuralFeatureActionActivationImpl> element(new fUML::Semantics::Actions::ReadStructuralFeatureActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisReadStructuralFeatureActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::RealValue> FUMLFactoryImpl::createRealValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::RealValueImpl> element(new fUML::Semantics::SimpleClassifiers::RealValueImpl());
	element->setMetaElementID(metaElementID);
	element->setThisRealValuePtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ReclassifyObjectActionActivation> FUMLFactoryImpl::createReclassifyObjectActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReclassifyObjectActionActivationImpl> element(new fUML::Semantics::Actions::ReclassifyObjectActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReclassifyObjectActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ReclassifyObjectActionActivation> FUMLFactoryImpl::createReclassifyObjectActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReclassifyObjectActionActivationImpl> element(new fUML::Semantics::Actions::ReclassifyObjectActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisReclassifyObjectActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::StructuredClassifiers::RedefinitionBasedDispatchStrategy> FUMLFactoryImpl::createRedefinitionBasedDispatchStrategy(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::RedefinitionBasedDispatchStrategyImpl> element(new fUML::Semantics::StructuredClassifiers::RedefinitionBasedDispatchStrategyImpl());
	element->setMetaElementID(metaElementID);
	element->setThisRedefinitionBasedDispatchStrategyPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ReduceActionActivation> FUMLFactoryImpl::createReduceActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReduceActionActivationImpl> element(new fUML::Semantics::Actions::ReduceActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReduceActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ReduceActionActivation> FUMLFactoryImpl::createReduceActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReduceActionActivationImpl> element(new fUML::Semantics::Actions::ReduceActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisReduceActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> FUMLFactoryImpl::createReference(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::ReferenceImpl> element(new fUML::Semantics::StructuredClassifiers::ReferenceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReferencePtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActivation> FUMLFactoryImpl::createRemoveStructuralFeatureValueActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActivationImpl> element(new fUML::Semantics::Actions::RemoveStructuralFeatureValueActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisRemoveStructuralFeatureValueActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActivation> FUMLFactoryImpl::createRemoveStructuralFeatureValueActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActivationImpl> element(new fUML::Semantics::Actions::RemoveStructuralFeatureValueActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisRemoveStructuralFeatureValueActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::ReplyActionActivation> FUMLFactoryImpl::createReplyActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReplyActionActivationImpl> element(new fUML::Semantics::Actions::ReplyActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReplyActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ReplyActionActivation> FUMLFactoryImpl::createReplyActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReplyActionActivationImpl> element(new fUML::Semantics::Actions::ReplyActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisReplyActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::ReturnInformation> FUMLFactoryImpl::createReturnInformation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReturnInformationImpl> element(new fUML::Semantics::Actions::ReturnInformationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReturnInformationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::SendSignalActionActivation> FUMLFactoryImpl::createSendSignalActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::SendSignalActionActivationImpl> element(new fUML::Semantics::Actions::SendSignalActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisSendSignalActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::SendSignalActionActivation> FUMLFactoryImpl::createSendSignalActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::SendSignalActionActivationImpl> element(new fUML::Semantics::Actions::SendSignalActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisSendSignalActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::CommonBehavior::SignalEventOccurrence> FUMLFactoryImpl::createSignalEventOccurrence(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::SignalEventOccurrenceImpl> element(new fUML::Semantics::CommonBehavior::SignalEventOccurrenceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisSignalEventOccurrencePtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> FUMLFactoryImpl::createSignalInstance(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstanceImpl> element(new fUML::Semantics::SimpleClassifiers::SignalInstanceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisSignalInstancePtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::StartClassifierBehaviorActionActivation> FUMLFactoryImpl::createStartClassifierBehaviorActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::StartClassifierBehaviorActionActivationImpl> element(new fUML::Semantics::Actions::StartClassifierBehaviorActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisStartClassifierBehaviorActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::StartClassifierBehaviorActionActivation> FUMLFactoryImpl::createStartClassifierBehaviorActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::StartClassifierBehaviorActionActivationImpl> element(new fUML::Semantics::Actions::StartClassifierBehaviorActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisStartClassifierBehaviorActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::StartObjectBehaviorActionActivation> FUMLFactoryImpl::createStartObjectBehaviorActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::StartObjectBehaviorActionActivationImpl> element(new fUML::Semantics::Actions::StartObjectBehaviorActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisStartObjectBehaviorActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::StartObjectBehaviorActionActivation> FUMLFactoryImpl::createStartObjectBehaviorActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::StartObjectBehaviorActionActivationImpl> element(new fUML::Semantics::Actions::StartObjectBehaviorActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisStartObjectBehaviorActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> FUMLFactoryImpl::createStringValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValueImpl> element(new fUML::Semantics::SimpleClassifiers::StringValueImpl());
	element->setMetaElementID(metaElementID);
	element->setThisStringValuePtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> FUMLFactoryImpl::createStructuredActivityNodeActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivationImpl> element(new fUML::Semantics::Actions::StructuredActivityNodeActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisStructuredActivityNodeActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> FUMLFactoryImpl::createStructuredActivityNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivationImpl> element(new fUML::Semantics::Actions::StructuredActivityNodeActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisStructuredActivityNodeActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::TestIdentityActionActivation> FUMLFactoryImpl::createTestIdentityActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::TestIdentityActionActivationImpl> element(new fUML::Semantics::Actions::TestIdentityActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisTestIdentityActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::TestIdentityActionActivation> FUMLFactoryImpl::createTestIdentityActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::TestIdentityActionActivationImpl> element(new fUML::Semantics::Actions::TestIdentityActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisTestIdentityActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::TokenSet> FUMLFactoryImpl::createTokenSet(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::TokenSetImpl> element(new fUML::Semantics::Activities::TokenSetImpl());
	element->setMetaElementID(metaElementID);
	element->setThisTokenSetPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue> FUMLFactoryImpl::createUnlimitedNaturalValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValueImpl> element(new fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValueImpl());
	element->setMetaElementID(metaElementID);
	element->setThisUnlimitedNaturalValuePtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ValueSpecificationActionActivation> FUMLFactoryImpl::createValueSpecificationActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ValueSpecificationActionActivationImpl> element(new fUML::Semantics::Actions::ValueSpecificationActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisValueSpecificationActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ValueSpecificationActionActivation> FUMLFactoryImpl::createValueSpecificationActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ValueSpecificationActionActivationImpl> element(new fUML::Semantics::Actions::ValueSpecificationActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisValueSpecificationActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::Values> FUMLFactoryImpl::createValues(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ValuesImpl> element(new fUML::Semantics::Actions::ValuesImpl());
	element->setMetaElementID(metaElementID);
	element->setThisValuesPtr(element);
	return element;
}

std::shared_ptr<FUMLPackage> FUMLFactoryImpl::getFUMLPackage() const
{
	return FUMLPackage::eInstance();
}
