#include "fUML/impl/FUMLFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "fUML/FUMLPackage.hpp"

#include "ecore/EClass.hpp"


#include "fUML/impl/AcceptEventActionActivationImpl.hpp"
#include "fUML/impl/AcceptEventActionEventAccepterImpl.hpp"
#include "fUML/impl/ActionActivationImpl.hpp"
#include "fUML/impl/ActivityEdgeInstanceImpl.hpp"
#include "fUML/impl/ActivityExecutionImpl.hpp"
#include "fUML/impl/ActivityFinalNodeActivationImpl.hpp"
#include "fUML/impl/ActivityNodeActivationImpl.hpp"
#include "fUML/impl/ActivityNodeActivationGroupImpl.hpp"
#include "fUML/impl/ActivityParameterNodeActivationImpl.hpp"
#include "fUML/impl/AddStructuralFeatureValueActionActivationImpl.hpp"
#include "fUML/impl/BooleanValueImpl.hpp"
#include "fUML/impl/CallActionActivationImpl.hpp"
#include "fUML/impl/CallBehaviorActionActivationImpl.hpp"
#include "fUML/impl/CallOperationActionActivationImpl.hpp"
#include "fUML/impl/CentralBufferNodeActivationImpl.hpp"
#include "fUML/impl/ChoiceStrategyImpl.hpp"
#include "fUML/impl/ClassifierBehaviorExecutionImpl.hpp"
#include "fUML/impl/ClassifierBehaviorExecutionActivityImpl.hpp"
#include "fUML/impl/ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl.hpp"
#include "fUML/impl/ClauseActivationImpl.hpp"
#include "fUML/impl/ClearAssociationActionActivationImpl.hpp"
#include "fUML/impl/ClearStructuralFeatureActionActivationImpl.hpp"
#include "fUML/impl/CompoundValueImpl.hpp"
#include "fUML/impl/ConditionalNodeActivationImpl.hpp"
#include "fUML/impl/ControlNodeActivationImpl.hpp"
#include "fUML/impl/ControlTokenImpl.hpp"
#include "fUML/impl/CreateLinkActionActivationImpl.hpp"
#include "fUML/impl/CreateObjectActionActivationImpl.hpp"
#include "fUML/impl/DataStoreNodeActivationImpl.hpp"
#include "fUML/impl/DataValueImpl.hpp"
#include "fUML/impl/DecisionNodeActivationImpl.hpp"
#include "fUML/impl/DestroyLinkActionActivationImpl.hpp"
#include "fUML/impl/DestroyObjectActionActivationImpl.hpp"
#include "fUML/impl/DispatchStrategyImpl.hpp"
#include "fUML/impl/EnumerationValueImpl.hpp"
#include "fUML/impl/EvaluationImpl.hpp"
#include "fUML/impl/EventAccepterImpl.hpp"
#include "fUML/impl/EventDispatchLoopImpl.hpp"
#include "fUML/impl/ExecutionImpl.hpp"
#include "fUML/impl/ExecutionFactoryImpl.hpp"
#include "fUML/impl/ExecutionFactoryL1Impl.hpp"
#include "fUML/impl/ExecutionFactoryL2Impl.hpp"
#include "fUML/impl/ExecutionFactoryL3Impl.hpp"
#include "fUML/impl/ExecutorImpl.hpp"
#include "fUML/impl/ExpansionActivationGroupImpl.hpp"
#include "fUML/impl/ExpansionNodeActivationImpl.hpp"
#include "fUML/impl/ExpansionRegionActivationImpl.hpp"
#include "fUML/impl/ExtensionalValueImpl.hpp"
#include "fUML/impl/ExtensionalValueListImpl.hpp"
#include "fUML/impl/FIFOGetNextEventStrategyImpl.hpp"
#include "fUML/impl/FeatureValueImpl.hpp"
#include "fUML/impl/FirstChoiceStrategyImpl.hpp"
#include "fUML/impl/FlowFinalNodeActivationImpl.hpp"
#include "fUML/impl/ForkNodeActivationImpl.hpp"
#include "fUML/impl/ForkedTokenImpl.hpp"
#include "fUML/impl/GetNextEventStrategyImpl.hpp"
#include "fUML/impl/InitialNodeActivationImpl.hpp"
#include "fUML/impl/InputPinActivationImpl.hpp"
#include "fUML/impl/InstanceValueEvaluationImpl.hpp"
#include "fUML/impl/IntegerValueImpl.hpp"
#include "fUML/impl/InvocationActionActivationImpl.hpp"
#include "fUML/impl/JoinNodeActivationImpl.hpp"
#include "fUML/impl/LinkImpl.hpp"
#include "fUML/impl/LinkActionActivationImpl.hpp"
#include "fUML/impl/LiteralBooleanEvaluationImpl.hpp"
#include "fUML/impl/LiteralEvaluationImpl.hpp"
#include "fUML/impl/LiteralIntegerEvaluationImpl.hpp"
#include "fUML/impl/LiteralNullEvaluationImpl.hpp"
#include "fUML/impl/LiteralRealEvaluationImpl.hpp"
#include "fUML/impl/LiteralStringEvaluationImpl.hpp"
#include "fUML/impl/LiteralUnlimitedNaturalEvaluationImpl.hpp"
#include "fUML/impl/LocusImpl.hpp"
#include "fUML/impl/LoopNodeActivationImpl.hpp"
#include "fUML/impl/MergeNodeActivationImpl.hpp"
#include "fUML/impl/ObjectImpl.hpp"
#include "fUML/impl/ObjectActivationImpl.hpp"
#include "fUML/impl/ObjectNodeActivationImpl.hpp"
#include "fUML/impl/ObjectTokenImpl.hpp"
#include "fUML/impl/OfferImpl.hpp"
#include "fUML/impl/OpaqueBehaviorExecutionImpl.hpp"
#include "fUML/impl/OutputPinActivationImpl.hpp"
#include "fUML/impl/ParameterValueImpl.hpp"
#include "fUML/impl/PinActivationImpl.hpp"
#include "fUML/impl/PrimitiveValueImpl.hpp"
#include "fUML/impl/ReadExtentActionActivationImpl.hpp"
#include "fUML/impl/ReadIsClassifiedObjectActionActivationImpl.hpp"
#include "fUML/impl/ReadLinkActionActivationImpl.hpp"
#include "fUML/impl/ReadSelfActionActivationImpl.hpp"
#include "fUML/impl/ReadStructuralFeatureActionActivationImpl.hpp"
#include "fUML/impl/RealValueImpl.hpp"
#include "fUML/impl/ReclassifyObjectActionActivationImpl.hpp"
#include "fUML/impl/RedefinitionBasedDispatchStrategyImpl.hpp"
#include "fUML/impl/ReduceActionActivationImpl.hpp"
#include "fUML/impl/ReferenceImpl.hpp"
#include "fUML/impl/RemoveStructuralFeatureValueActivationImpl.hpp"
#include "fUML/impl/SemanticStrategyImpl.hpp"
#include "fUML/impl/SemanticVisitorImpl.hpp"
#include "fUML/impl/SendSignalActionActivationImpl.hpp"
#include "fUML/impl/SignalInstanceImpl.hpp"
#include "fUML/impl/StartClassifierBehaviorActionActivationImpl.hpp"
#include "fUML/impl/StartObjectBehaviorActionActivationImpl.hpp"
#include "fUML/impl/StringValueImpl.hpp"
#include "fUML/impl/StructuralFeatureActionActivationImpl.hpp"
#include "fUML/impl/StructuredActivityNodeActivationImpl.hpp"
#include "fUML/impl/StructuredValueImpl.hpp"
#include "fUML/impl/TestIdentityActionActivationImpl.hpp"
#include "fUML/impl/TokenImpl.hpp"
#include "fUML/impl/TokenSetImpl.hpp"
#include "fUML/impl/UnlimitedNaturalValueImpl.hpp"
#include "fUML/impl/ValueImpl.hpp"
#include "fUML/impl/ValueSpecificActionActivationImpl.hpp"
#include "fUML/impl/ValuesImpl.hpp"
#include "fUML/impl/WriteLinkActionActivationImpl.hpp"
#include "fUML/impl/WriteStructuralFeatureActionActivationImpl.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************

FUMLFactoryImpl::FUMLFactoryImpl()
{
	m_idMap.insert(std::make_pair("AcceptEventActionActivation", FUMLPackage::ACCEPTEVENTACTIONACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("AcceptEventActionEventAccepter", FUMLPackage::ACCEPTEVENTACTIONEVENTACCEPTER_ECLASS));
	m_idMap.insert(std::make_pair("ActivityEdgeInstance", FUMLPackage::ACTIVITYEDGEINSTANCE_ECLASS));
	m_idMap.insert(std::make_pair("ActivityExecution", FUMLPackage::ACTIVITYEXECUTION_ECLASS));
	m_idMap.insert(std::make_pair("ActivityFinalNodeActivation", FUMLPackage::ACTIVITYFINALNODEACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("ActivityNodeActivationGroup", FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_ECLASS));
	m_idMap.insert(std::make_pair("ActivityParameterNodeActivation", FUMLPackage::ACTIVITYPARAMETERNODEACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("AddStructuralFeatureValueActionActivation", FUMLPackage::ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("BooleanValue", FUMLPackage::BOOLEANVALUE_ECLASS));
	m_idMap.insert(std::make_pair("CallBehaviorActionActivation", FUMLPackage::CALLBEHAVIORACTIONACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("CallOperationActionActivation", FUMLPackage::CALLOPERATIONACTIONACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("CentralBufferNodeActivation", FUMLPackage::CENTRALBUFFERNODEACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("ClassifierBehaviorExecution", FUMLPackage::CLASSIFIERBEHAVIOREXECUTION_ECLASS));
	m_idMap.insert(std::make_pair("ClassifierBehaviorExecutionActivity", FUMLPackage::CLASSIFIERBEHAVIOREXECUTIONACTIVITY_ECLASS));
	m_idMap.insert(std::make_pair("ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1", FUMLPackage::CLASSIFIERBEHAVIOREXECUTIONACTIVITY_OWNEDBEHAVIORACTIVITY1_ECLASS));
	m_idMap.insert(std::make_pair("ClauseActivation", FUMLPackage::CLAUSEACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("ClearAssociationActionActivation", FUMLPackage::CLEARASSOCIATIONACTIONACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("ClearStructuralFeatureActionActivation", FUMLPackage::CLEARSTRUCTURALFEATUREACTIONACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("ConditionalNodeActivation", FUMLPackage::CONDITIONALNODEACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("ControlToken", FUMLPackage::CONTROLTOKEN_ECLASS));
	m_idMap.insert(std::make_pair("CreateLinkActionActivation", FUMLPackage::CREATELINKACTIONACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("CreateObjectActionActivation", FUMLPackage::CREATEOBJECTACTIONACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("DataStoreNodeActivation", FUMLPackage::DATASTORENODEACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("DataValue", FUMLPackage::DATAVALUE_ECLASS));
	m_idMap.insert(std::make_pair("DecisionNodeActivation", FUMLPackage::DECISIONNODEACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("DestroyLinkActionActivation", FUMLPackage::DESTROYLINKACTIONACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("DestroyObjectActionActivation", FUMLPackage::DESTROYOBJECTACTIONACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("DispatchStrategy", FUMLPackage::DISPATCHSTRATEGY_ECLASS));
	m_idMap.insert(std::make_pair("EnumerationValue", FUMLPackage::ENUMERATIONVALUE_ECLASS));
	m_idMap.insert(std::make_pair("EventDispatchLoop", FUMLPackage::EVENTDISPATCHLOOP_ECLASS));
	m_idMap.insert(std::make_pair("ExecutionFactoryL1", FUMLPackage::EXECUTIONFACTORYL1_ECLASS));
	m_idMap.insert(std::make_pair("ExecutionFactoryL2", FUMLPackage::EXECUTIONFACTORYL2_ECLASS));
	m_idMap.insert(std::make_pair("ExecutionFactoryL3", FUMLPackage::EXECUTIONFACTORYL3_ECLASS));
	m_idMap.insert(std::make_pair("Executor", FUMLPackage::EXECUTOR_ECLASS));
	m_idMap.insert(std::make_pair("ExpansionActivationGroup", FUMLPackage::EXPANSIONACTIVATIONGROUP_ECLASS));
	m_idMap.insert(std::make_pair("ExpansionNodeActivation", FUMLPackage::EXPANSIONNODEACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("ExpansionRegionActivation", FUMLPackage::EXPANSIONREGIONACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("ExtensionalValueList", FUMLPackage::EXTENSIONALVALUELIST_ECLASS));
	m_idMap.insert(std::make_pair("FIFOGetNextEventStrategy", FUMLPackage::FIFOGETNEXTEVENTSTRATEGY_ECLASS));
	m_idMap.insert(std::make_pair("FeatureValue", FUMLPackage::FEATUREVALUE_ECLASS));
	m_idMap.insert(std::make_pair("FirstChoiceStrategy", FUMLPackage::FIRSTCHOICESTRATEGY_ECLASS));
	m_idMap.insert(std::make_pair("FlowFinalNodeActivation", FUMLPackage::FLOWFINALNODEACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("ForkNodeActivation", FUMLPackage::FORKNODEACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("ForkedToken", FUMLPackage::FORKEDTOKEN_ECLASS));
	m_idMap.insert(std::make_pair("InitialNodeActivation", FUMLPackage::INITIALNODEACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("InputPinActivation", FUMLPackage::INPUTPINACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("InstanceValueEvaluation", FUMLPackage::INSTANCEVALUEEVALUATION_ECLASS));
	m_idMap.insert(std::make_pair("IntegerValue", FUMLPackage::INTEGERVALUE_ECLASS));
	m_idMap.insert(std::make_pair("JoinNodeActivation", FUMLPackage::JOINNODEACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("Link", FUMLPackage::LINK_ECLASS));
	m_idMap.insert(std::make_pair("LiteralBooleanEvaluation", FUMLPackage::LITERALBOOLEANEVALUATION_ECLASS));
	m_idMap.insert(std::make_pair("LiteralIntegerEvaluation", FUMLPackage::LITERALINTEGEREVALUATION_ECLASS));
	m_idMap.insert(std::make_pair("LiteralNullEvaluation", FUMLPackage::LITERALNULLEVALUATION_ECLASS));
	m_idMap.insert(std::make_pair("LiteralRealEvaluation", FUMLPackage::LITERALREALEVALUATION_ECLASS));
	m_idMap.insert(std::make_pair("LiteralStringEvaluation", FUMLPackage::LITERALSTRINGEVALUATION_ECLASS));
	m_idMap.insert(std::make_pair("LiteralUnlimitedNaturalEvaluation", FUMLPackage::LITERALUNLIMITEDNATURALEVALUATION_ECLASS));
	m_idMap.insert(std::make_pair("Locus", FUMLPackage::LOCUS_ECLASS));
	m_idMap.insert(std::make_pair("LoopNodeActivation", FUMLPackage::LOOPNODEACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("MergeNodeActivation", FUMLPackage::MERGENODEACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("Object", FUMLPackage::OBJECT_ECLASS));
	m_idMap.insert(std::make_pair("ObjectActivation", FUMLPackage::OBJECTACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("ObjectToken", FUMLPackage::OBJECTTOKEN_ECLASS));
	m_idMap.insert(std::make_pair("Offer", FUMLPackage::OFFER_ECLASS));
	m_idMap.insert(std::make_pair("OutputPinActivation", FUMLPackage::OUTPUTPINACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("ParameterValue", FUMLPackage::PARAMETERVALUE_ECLASS));
	m_idMap.insert(std::make_pair("ReadExtentActionActivation", FUMLPackage::READEXTENTACTIONACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("ReadIsClassifiedObjectActionActivation", FUMLPackage::READISCLASSIFIEDOBJECTACTIONACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("ReadLinkActionActivation", FUMLPackage::READLINKACTIONACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("ReadSelfActionActivation", FUMLPackage::READSELFACTIONACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("ReadStructuralFeatureActionActivation", FUMLPackage::READSTRUCTURALFEATUREACTIONACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("RealValue", FUMLPackage::REALVALUE_ECLASS));
	m_idMap.insert(std::make_pair("ReclassifyObjectActionActivation", FUMLPackage::RECLASSIFYOBJECTACTIONACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("RedefinitionBasedDispatchStrategy", FUMLPackage::REDEFINITIONBASEDDISPATCHSTRATEGY_ECLASS));
	m_idMap.insert(std::make_pair("ReduceActionActivation", FUMLPackage::REDUCEACTIONACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("Reference", FUMLPackage::REFERENCE_ECLASS));
	m_idMap.insert(std::make_pair("RemoveStructuralFeatureValueActivation", FUMLPackage::REMOVESTRUCTURALFEATUREVALUEACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("SendSignalActionActivation", FUMLPackage::SENDSIGNALACTIONACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("SignalInstance", FUMLPackage::SIGNALINSTANCE_ECLASS));
	m_idMap.insert(std::make_pair("StartClassifierBehaviorActionActivation", FUMLPackage::STARTCLASSIFIERBEHAVIORACTIONACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("StartObjectBehaviorActionActivation", FUMLPackage::STARTOBJECTBEHAVIORACTIONACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("StringValue", FUMLPackage::STRINGVALUE_ECLASS));
	m_idMap.insert(std::make_pair("StructuredActivityNodeActivation", FUMLPackage::STRUCTUREDACTIVITYNODEACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("TestIdentityActionActivation", FUMLPackage::TESTIDENTITYACTIONACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("TokenSet", FUMLPackage::TOKENSET_ECLASS));
	m_idMap.insert(std::make_pair("UnlimitedNaturalValue", FUMLPackage::UNLIMITEDNATURALVALUE_ECLASS));
	m_idMap.insert(std::make_pair("ValueSpecificActionActivation", FUMLPackage::VALUESPECIFICACTIONACTIVATION_ECLASS));
	m_idMap.insert(std::make_pair("Values", FUMLPackage::VALUES_ECLASS));
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
		case FUMLPackage::ACCEPTEVENTACTIONACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createAcceptEventActionActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<AcceptEventActionActivation>(this->createAcceptEventActionActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::ACCEPTEVENTACTIONEVENTACCEPTER_ECLASS:
		{
				return this->createAcceptEventActionEventAccepter();
			
		}
		case FUMLPackage::ACTIVITYEDGEINSTANCE_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createActivityEdgeInstance();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<ActivityEdgeInstance>(this->createActivityEdgeInstance_in_Group(castedContainer));
			}
		}
		case FUMLPackage::ACTIVITYEXECUTION_ECLASS:
		{
				return this->createActivityExecution();
			
		}
		case FUMLPackage::ACTIVITYFINALNODEACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createActivityFinalNodeActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<ActivityFinalNodeActivation>(this->createActivityFinalNodeActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createActivityNodeActivationGroup();
			}
			else
			{
				switch(referenceID)
				{
					//ActivityNodeActivationGroup has activityExecution as a containment
					case  FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_EREFERENCE_ACTIVITYEXECUTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityExecution>(container);
						return this->createActivityNodeActivationGroup_in_ActivityExecution(castedContainer);
					}
					//ActivityNodeActivationGroup has containingNodeActivation as a containment
					case  FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_EREFERENCE_CONTAININGNODEACTIVATION:
					{
						auto castedContainer = std::dynamic_pointer_cast<fUML::StructuredActivityNodeActivation>(container);
						return this->createActivityNodeActivationGroup_in_ContainingNodeActivation(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case FUMLPackage::ACTIVITYPARAMETERNODEACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createActivityParameterNodeActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<ActivityParameterNodeActivation>(this->createActivityParameterNodeActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createAddStructuralFeatureValueActionActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<AddStructuralFeatureValueActionActivation>(this->createAddStructuralFeatureValueActionActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::BOOLEANVALUE_ECLASS:
		{
				return this->createBooleanValue();
			
		}
		case FUMLPackage::CALLBEHAVIORACTIONACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createCallBehaviorActionActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<CallBehaviorActionActivation>(this->createCallBehaviorActionActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::CALLOPERATIONACTIONACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createCallOperationActionActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<CallOperationActionActivation>(this->createCallOperationActionActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::CENTRALBUFFERNODEACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createCentralBufferNodeActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<CentralBufferNodeActivation>(this->createCentralBufferNodeActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::CLASSIFIERBEHAVIOREXECUTION_ECLASS:
		{
				return this->createClassifierBehaviorExecution();
			
		}
		case FUMLPackage::CLASSIFIERBEHAVIOREXECUTIONACTIVITY_ECLASS:
		{
				return this->createClassifierBehaviorExecutionActivity();
			
		}
		case FUMLPackage::CLASSIFIERBEHAVIOREXECUTIONACTIVITY_OWNEDBEHAVIORACTIVITY1_ECLASS:
		{
				return this->createClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1();
			
		}
		case FUMLPackage::CLAUSEACTIVATION_ECLASS:
		{
				return this->createClauseActivation();
			
		}
		case FUMLPackage::CLEARASSOCIATIONACTIONACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createClearAssociationActionActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<ClearAssociationActionActivation>(this->createClearAssociationActionActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::CLEARSTRUCTURALFEATUREACTIONACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createClearStructuralFeatureActionActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<ClearStructuralFeatureActionActivation>(this->createClearStructuralFeatureActionActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::CONDITIONALNODEACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createConditionalNodeActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<ConditionalNodeActivation>(this->createConditionalNodeActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::CONTROLTOKEN_ECLASS:
		{
				return this->createControlToken();
			
		}
		case FUMLPackage::CREATELINKACTIONACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createCreateLinkActionActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<CreateLinkActionActivation>(this->createCreateLinkActionActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::CREATEOBJECTACTIONACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createCreateObjectActionActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<CreateObjectActionActivation>(this->createCreateObjectActionActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::DATASTORENODEACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createDataStoreNodeActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<DataStoreNodeActivation>(this->createDataStoreNodeActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::DATAVALUE_ECLASS:
		{
				return this->createDataValue();
			
		}
		case FUMLPackage::DECISIONNODEACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createDecisionNodeActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<DecisionNodeActivation>(this->createDecisionNodeActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::DESTROYLINKACTIONACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createDestroyLinkActionActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<DestroyLinkActionActivation>(this->createDestroyLinkActionActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::DESTROYOBJECTACTIONACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createDestroyObjectActionActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<DestroyObjectActionActivation>(this->createDestroyObjectActionActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::DISPATCHSTRATEGY_ECLASS:
		{
				return this->createDispatchStrategy();
			
		}
		case FUMLPackage::ENUMERATIONVALUE_ECLASS:
		{
				return this->createEnumerationValue();
			
		}
		case FUMLPackage::EVENTDISPATCHLOOP_ECLASS:
		{
				return this->createEventDispatchLoop();
			
		}
		case FUMLPackage::EXECUTIONFACTORYL1_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createExecutionFactoryL1();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::Locus>(container);
				assert(castedContainer);
				return std::shared_ptr<ExecutionFactoryL1>(this->createExecutionFactoryL1_in_Locus(castedContainer));
			}
		}
		case FUMLPackage::EXECUTIONFACTORYL2_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createExecutionFactoryL2();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::Locus>(container);
				assert(castedContainer);
				return std::shared_ptr<ExecutionFactoryL2>(this->createExecutionFactoryL2_in_Locus(castedContainer));
			}
		}
		case FUMLPackage::EXECUTIONFACTORYL3_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createExecutionFactoryL3();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::Locus>(container);
				assert(castedContainer);
				return std::shared_ptr<ExecutionFactoryL3>(this->createExecutionFactoryL3_in_Locus(castedContainer));
			}
		}
		case FUMLPackage::EXECUTOR_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createExecutor();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::Locus>(container);
				assert(castedContainer);
				return std::shared_ptr<Executor>(this->createExecutor_in_Locus(castedContainer));
			}
		}
		case FUMLPackage::EXPANSIONACTIVATIONGROUP_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createExpansionActivationGroup();
			}
			else
			{
				switch(referenceID)
				{
					//ExpansionActivationGroup has activityExecution as a containment
					case  FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_EREFERENCE_ACTIVITYEXECUTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityExecution>(container);
						return this->createExpansionActivationGroup_in_ActivityExecution(castedContainer);
					}
					//ExpansionActivationGroup has containingNodeActivation as a containment
					case  FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_EREFERENCE_CONTAININGNODEACTIVATION:
					{
						auto castedContainer = std::dynamic_pointer_cast<fUML::StructuredActivityNodeActivation>(container);
						return this->createExpansionActivationGroup_in_ContainingNodeActivation(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case FUMLPackage::EXPANSIONNODEACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createExpansionNodeActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<ExpansionNodeActivation>(this->createExpansionNodeActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::EXPANSIONREGIONACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createExpansionRegionActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<ExpansionRegionActivation>(this->createExpansionRegionActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::EXTENSIONALVALUELIST_ECLASS:
		{
				return this->createExtensionalValueList();
			
		}
		case FUMLPackage::FIFOGETNEXTEVENTSTRATEGY_ECLASS:
		{
				return this->createFIFOGetNextEventStrategy();
			
		}
		case FUMLPackage::FEATUREVALUE_ECLASS:
		{
				return this->createFeatureValue();
			
		}
		case FUMLPackage::FIRSTCHOICESTRATEGY_ECLASS:
		{
				return this->createFirstChoiceStrategy();
			
		}
		case FUMLPackage::FLOWFINALNODEACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createFlowFinalNodeActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<FlowFinalNodeActivation>(this->createFlowFinalNodeActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::FORKNODEACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createForkNodeActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<ForkNodeActivation>(this->createForkNodeActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::FORKEDTOKEN_ECLASS:
		{
				return this->createForkedToken();
			
		}
		case FUMLPackage::INITIALNODEACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createInitialNodeActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<InitialNodeActivation>(this->createInitialNodeActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::INPUTPINACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createInputPinActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<InputPinActivation>(this->createInputPinActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::INSTANCEVALUEEVALUATION_ECLASS:
		{
				return this->createInstanceValueEvaluation();
			
		}
		case FUMLPackage::INTEGERVALUE_ECLASS:
		{
				return this->createIntegerValue();
			
		}
		case FUMLPackage::JOINNODEACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createJoinNodeActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<JoinNodeActivation>(this->createJoinNodeActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::LINK_ECLASS:
		{
				return this->createLink();
			
		}
		case FUMLPackage::LITERALBOOLEANEVALUATION_ECLASS:
		{
				return this->createLiteralBooleanEvaluation();
			
		}
		case FUMLPackage::LITERALINTEGEREVALUATION_ECLASS:
		{
				return this->createLiteralIntegerEvaluation();
			
		}
		case FUMLPackage::LITERALNULLEVALUATION_ECLASS:
		{
				return this->createLiteralNullEvaluation();
			
		}
		case FUMLPackage::LITERALREALEVALUATION_ECLASS:
		{
				return this->createLiteralRealEvaluation();
			
		}
		case FUMLPackage::LITERALSTRINGEVALUATION_ECLASS:
		{
				return this->createLiteralStringEvaluation();
			
		}
		case FUMLPackage::LITERALUNLIMITEDNATURALEVALUATION_ECLASS:
		{
				return this->createLiteralUnlimitedNaturalEvaluation();
			
		}
		case FUMLPackage::LOCUS_ECLASS:
		{
				return this->createLocus();
			
		}
		case FUMLPackage::LOOPNODEACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createLoopNodeActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<LoopNodeActivation>(this->createLoopNodeActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::MERGENODEACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createMergeNodeActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<MergeNodeActivation>(this->createMergeNodeActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::OBJECT_ECLASS:
		{
				return this->createObject();
			
		}
		case FUMLPackage::OBJECTACTIVATION_ECLASS:
		{
				return this->createObjectActivation();
			
		}
		case FUMLPackage::OBJECTTOKEN_ECLASS:
		{
				return this->createObjectToken();
			
		}
		case FUMLPackage::OFFER_ECLASS:
		{
				return this->createOffer();
			
		}
		case FUMLPackage::OUTPUTPINACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createOutputPinActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<OutputPinActivation>(this->createOutputPinActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::PARAMETERVALUE_ECLASS:
		{
				return this->createParameterValue();
			
		}
		case FUMLPackage::READEXTENTACTIONACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createReadExtentActionActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<ReadExtentActionActivation>(this->createReadExtentActionActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::READISCLASSIFIEDOBJECTACTIONACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createReadIsClassifiedObjectActionActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<ReadIsClassifiedObjectActionActivation>(this->createReadIsClassifiedObjectActionActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::READLINKACTIONACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createReadLinkActionActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<ReadLinkActionActivation>(this->createReadLinkActionActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::READSELFACTIONACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createReadSelfActionActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<ReadSelfActionActivation>(this->createReadSelfActionActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::READSTRUCTURALFEATUREACTIONACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createReadStructuralFeatureActionActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<ReadStructuralFeatureActionActivation>(this->createReadStructuralFeatureActionActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::REALVALUE_ECLASS:
		{
				return this->createRealValue();
			
		}
		case FUMLPackage::RECLASSIFYOBJECTACTIONACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createReclassifyObjectActionActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<ReclassifyObjectActionActivation>(this->createReclassifyObjectActionActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::REDEFINITIONBASEDDISPATCHSTRATEGY_ECLASS:
		{
				return this->createRedefinitionBasedDispatchStrategy();
			
		}
		case FUMLPackage::REDUCEACTIONACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createReduceActionActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<ReduceActionActivation>(this->createReduceActionActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::REFERENCE_ECLASS:
		{
				return this->createReference();
			
		}
		case FUMLPackage::REMOVESTRUCTURALFEATUREVALUEACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createRemoveStructuralFeatureValueActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<RemoveStructuralFeatureValueActivation>(this->createRemoveStructuralFeatureValueActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::SENDSIGNALACTIONACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createSendSignalActionActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<SendSignalActionActivation>(this->createSendSignalActionActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::SIGNALINSTANCE_ECLASS:
		{
				return this->createSignalInstance();
			
		}
		case FUMLPackage::STARTCLASSIFIERBEHAVIORACTIONACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createStartClassifierBehaviorActionActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<StartClassifierBehaviorActionActivation>(this->createStartClassifierBehaviorActionActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::STARTOBJECTBEHAVIORACTIONACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createStartObjectBehaviorActionActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<StartObjectBehaviorActionActivation>(this->createStartObjectBehaviorActionActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::STRINGVALUE_ECLASS:
		{
				return this->createStringValue();
			
		}
		case FUMLPackage::STRUCTUREDACTIVITYNODEACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createStructuredActivityNodeActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<StructuredActivityNodeActivation>(this->createStructuredActivityNodeActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::TESTIDENTITYACTIONACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createTestIdentityActionActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<TestIdentityActionActivation>(this->createTestIdentityActionActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::TOKENSET_ECLASS:
		{
				return this->createTokenSet();
			
		}
		case FUMLPackage::UNLIMITEDNATURALVALUE_ECLASS:
		{
				return this->createUnlimitedNaturalValue();
			
		}
		case FUMLPackage::VALUESPECIFICACTIONACTIVATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createValueSpecificActionActivation();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<ValueSpecificActionActivation>(this->createValueSpecificActionActivation_in_Group(castedContainer));
			}
		}
		case FUMLPackage::VALUES_ECLASS:
		{
				return this->createValues();
			
		}
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << classID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<ecore::EObject> FUMLFactoryImpl::create(std::shared_ptr<ecore::EClass> _class) const
{
	return create(_class, nullptr);
}

std::shared_ptr<ecore::EObject> FUMLFactoryImpl::create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}

	int _classID = _class->eClass()->getClassifierID();
	return create(_classID, _container);
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
	std::shared_ptr<AcceptEventActionActivationImpl> element(new AcceptEventActionActivationImpl());
	element->setThisAcceptEventActionActivationPtr(element);
	return element;
}
std::shared_ptr<AcceptEventActionActivation> FUMLFactoryImpl::createAcceptEventActionActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<AcceptEventActionActivationImpl> element(new AcceptEventActionActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisAcceptEventActionActivationPtr(element);
	return element;
	
}

std::shared_ptr<AcceptEventActionEventAccepter> FUMLFactoryImpl::createAcceptEventActionEventAccepter() const
{
	std::shared_ptr<AcceptEventActionEventAccepterImpl> element(new AcceptEventActionEventAccepterImpl());
	element->setThisAcceptEventActionEventAccepterPtr(element);
	return element;
}
std::shared_ptr<ActivityEdgeInstance> FUMLFactoryImpl::createActivityEdgeInstance() const
{
	std::shared_ptr<ActivityEdgeInstanceImpl> element(new ActivityEdgeInstanceImpl());
	element->setThisActivityEdgeInstancePtr(element);
	return element;
}
std::shared_ptr<ActivityEdgeInstance> FUMLFactoryImpl::createActivityEdgeInstance_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<ActivityEdgeInstanceImpl> element(new ActivityEdgeInstanceImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getEdgeInstances()->push_back(element);
	}
	element->setThisActivityEdgeInstancePtr(element);
	return element;
	
}

std::shared_ptr<ActivityExecution> FUMLFactoryImpl::createActivityExecution() const
{
	std::shared_ptr<ActivityExecutionImpl> element(new ActivityExecutionImpl());
	element->setThisActivityExecutionPtr(element);
	return element;
}
std::shared_ptr<ActivityFinalNodeActivation> FUMLFactoryImpl::createActivityFinalNodeActivation() const
{
	std::shared_ptr<ActivityFinalNodeActivationImpl> element(new ActivityFinalNodeActivationImpl());
	element->setThisActivityFinalNodeActivationPtr(element);
	return element;
}
std::shared_ptr<ActivityFinalNodeActivation> FUMLFactoryImpl::createActivityFinalNodeActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<ActivityFinalNodeActivationImpl> element(new ActivityFinalNodeActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisActivityFinalNodeActivationPtr(element);
	return element;
	
}

std::shared_ptr<ActivityNodeActivationGroup> FUMLFactoryImpl::createActivityNodeActivationGroup() const
{
	std::shared_ptr<ActivityNodeActivationGroupImpl> element(new ActivityNodeActivationGroupImpl());
	element->setThisActivityNodeActivationGroupPtr(element);
	return element;
}
std::shared_ptr<ActivityNodeActivationGroup> FUMLFactoryImpl::createActivityNodeActivationGroup_in_ActivityExecution(std::weak_ptr<fUML::ActivityExecution > par_activityExecution) const
{
	std::shared_ptr<ActivityNodeActivationGroupImpl> element(new ActivityNodeActivationGroupImpl(par_activityExecution));
	if(auto wp = par_activityExecution.lock())
	{
			wp->setActivationGroup(element);
	}
	element->setThisActivityNodeActivationGroupPtr(element);
	return element;
	
}

std::shared_ptr<ActivityNodeActivationGroup> FUMLFactoryImpl::createActivityNodeActivationGroup_in_ContainingNodeActivation(std::weak_ptr<fUML::StructuredActivityNodeActivation > par_containingNodeActivation) const
{
	std::shared_ptr<ActivityNodeActivationGroupImpl> element(new ActivityNodeActivationGroupImpl(par_containingNodeActivation));
	if(auto wp = par_containingNodeActivation.lock())
	{
			wp->setActivationGroup(element);
	}
	element->setThisActivityNodeActivationGroupPtr(element);
	return element;
	
}

std::shared_ptr<ActivityParameterNodeActivation> FUMLFactoryImpl::createActivityParameterNodeActivation() const
{
	std::shared_ptr<ActivityParameterNodeActivationImpl> element(new ActivityParameterNodeActivationImpl());
	element->setThisActivityParameterNodeActivationPtr(element);
	return element;
}
std::shared_ptr<ActivityParameterNodeActivation> FUMLFactoryImpl::createActivityParameterNodeActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<ActivityParameterNodeActivationImpl> element(new ActivityParameterNodeActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisActivityParameterNodeActivationPtr(element);
	return element;
	
}

std::shared_ptr<AddStructuralFeatureValueActionActivation> FUMLFactoryImpl::createAddStructuralFeatureValueActionActivation() const
{
	std::shared_ptr<AddStructuralFeatureValueActionActivationImpl> element(new AddStructuralFeatureValueActionActivationImpl());
	element->setThisAddStructuralFeatureValueActionActivationPtr(element);
	return element;
}
std::shared_ptr<AddStructuralFeatureValueActionActivation> FUMLFactoryImpl::createAddStructuralFeatureValueActionActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<AddStructuralFeatureValueActionActivationImpl> element(new AddStructuralFeatureValueActionActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisAddStructuralFeatureValueActionActivationPtr(element);
	return element;
	
}

std::shared_ptr<BooleanValue> FUMLFactoryImpl::createBooleanValue() const
{
	std::shared_ptr<BooleanValueImpl> element(new BooleanValueImpl());
	element->setThisBooleanValuePtr(element);
	return element;
}
std::shared_ptr<CallBehaviorActionActivation> FUMLFactoryImpl::createCallBehaviorActionActivation() const
{
	std::shared_ptr<CallBehaviorActionActivationImpl> element(new CallBehaviorActionActivationImpl());
	element->setThisCallBehaviorActionActivationPtr(element);
	return element;
}
std::shared_ptr<CallBehaviorActionActivation> FUMLFactoryImpl::createCallBehaviorActionActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<CallBehaviorActionActivationImpl> element(new CallBehaviorActionActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisCallBehaviorActionActivationPtr(element);
	return element;
	
}

std::shared_ptr<CallOperationActionActivation> FUMLFactoryImpl::createCallOperationActionActivation() const
{
	std::shared_ptr<CallOperationActionActivationImpl> element(new CallOperationActionActivationImpl());
	element->setThisCallOperationActionActivationPtr(element);
	return element;
}
std::shared_ptr<CallOperationActionActivation> FUMLFactoryImpl::createCallOperationActionActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<CallOperationActionActivationImpl> element(new CallOperationActionActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisCallOperationActionActivationPtr(element);
	return element;
	
}

std::shared_ptr<CentralBufferNodeActivation> FUMLFactoryImpl::createCentralBufferNodeActivation() const
{
	std::shared_ptr<CentralBufferNodeActivationImpl> element(new CentralBufferNodeActivationImpl());
	element->setThisCentralBufferNodeActivationPtr(element);
	return element;
}
std::shared_ptr<CentralBufferNodeActivation> FUMLFactoryImpl::createCentralBufferNodeActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<CentralBufferNodeActivationImpl> element(new CentralBufferNodeActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisCentralBufferNodeActivationPtr(element);
	return element;
	
}

std::shared_ptr<ClassifierBehaviorExecution> FUMLFactoryImpl::createClassifierBehaviorExecution() const
{
	std::shared_ptr<ClassifierBehaviorExecutionImpl> element(new ClassifierBehaviorExecutionImpl());
	element->setThisClassifierBehaviorExecutionPtr(element);
	return element;
}
std::shared_ptr<ClassifierBehaviorExecutionActivity> FUMLFactoryImpl::createClassifierBehaviorExecutionActivity() const
{
	std::shared_ptr<ClassifierBehaviorExecutionActivityImpl> element(new ClassifierBehaviorExecutionActivityImpl());
	element->setThisClassifierBehaviorExecutionActivityPtr(element);
	return element;
}
std::shared_ptr<ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1> FUMLFactoryImpl::createClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1() const
{
	std::shared_ptr<ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl> element(new ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl());
	element->setThisClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Ptr(element);
	return element;
}
std::shared_ptr<ClauseActivation> FUMLFactoryImpl::createClauseActivation() const
{
	std::shared_ptr<ClauseActivationImpl> element(new ClauseActivationImpl());
	element->setThisClauseActivationPtr(element);
	return element;
}
std::shared_ptr<ClearAssociationActionActivation> FUMLFactoryImpl::createClearAssociationActionActivation() const
{
	std::shared_ptr<ClearAssociationActionActivationImpl> element(new ClearAssociationActionActivationImpl());
	element->setThisClearAssociationActionActivationPtr(element);
	return element;
}
std::shared_ptr<ClearAssociationActionActivation> FUMLFactoryImpl::createClearAssociationActionActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<ClearAssociationActionActivationImpl> element(new ClearAssociationActionActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisClearAssociationActionActivationPtr(element);
	return element;
	
}

std::shared_ptr<ClearStructuralFeatureActionActivation> FUMLFactoryImpl::createClearStructuralFeatureActionActivation() const
{
	std::shared_ptr<ClearStructuralFeatureActionActivationImpl> element(new ClearStructuralFeatureActionActivationImpl());
	element->setThisClearStructuralFeatureActionActivationPtr(element);
	return element;
}
std::shared_ptr<ClearStructuralFeatureActionActivation> FUMLFactoryImpl::createClearStructuralFeatureActionActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<ClearStructuralFeatureActionActivationImpl> element(new ClearStructuralFeatureActionActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisClearStructuralFeatureActionActivationPtr(element);
	return element;
	
}

std::shared_ptr<ConditionalNodeActivation> FUMLFactoryImpl::createConditionalNodeActivation() const
{
	std::shared_ptr<ConditionalNodeActivationImpl> element(new ConditionalNodeActivationImpl());
	element->setThisConditionalNodeActivationPtr(element);
	return element;
}
std::shared_ptr<ConditionalNodeActivation> FUMLFactoryImpl::createConditionalNodeActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<ConditionalNodeActivationImpl> element(new ConditionalNodeActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisConditionalNodeActivationPtr(element);
	return element;
	
}

std::shared_ptr<ControlToken> FUMLFactoryImpl::createControlToken() const
{
	std::shared_ptr<ControlTokenImpl> element(new ControlTokenImpl());
	element->setThisControlTokenPtr(element);
	return element;
}
std::shared_ptr<CreateLinkActionActivation> FUMLFactoryImpl::createCreateLinkActionActivation() const
{
	std::shared_ptr<CreateLinkActionActivationImpl> element(new CreateLinkActionActivationImpl());
	element->setThisCreateLinkActionActivationPtr(element);
	return element;
}
std::shared_ptr<CreateLinkActionActivation> FUMLFactoryImpl::createCreateLinkActionActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<CreateLinkActionActivationImpl> element(new CreateLinkActionActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisCreateLinkActionActivationPtr(element);
	return element;
	
}

std::shared_ptr<CreateObjectActionActivation> FUMLFactoryImpl::createCreateObjectActionActivation() const
{
	std::shared_ptr<CreateObjectActionActivationImpl> element(new CreateObjectActionActivationImpl());
	element->setThisCreateObjectActionActivationPtr(element);
	return element;
}
std::shared_ptr<CreateObjectActionActivation> FUMLFactoryImpl::createCreateObjectActionActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<CreateObjectActionActivationImpl> element(new CreateObjectActionActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisCreateObjectActionActivationPtr(element);
	return element;
	
}

std::shared_ptr<DataStoreNodeActivation> FUMLFactoryImpl::createDataStoreNodeActivation() const
{
	std::shared_ptr<DataStoreNodeActivationImpl> element(new DataStoreNodeActivationImpl());
	element->setThisDataStoreNodeActivationPtr(element);
	return element;
}
std::shared_ptr<DataStoreNodeActivation> FUMLFactoryImpl::createDataStoreNodeActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<DataStoreNodeActivationImpl> element(new DataStoreNodeActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisDataStoreNodeActivationPtr(element);
	return element;
	
}

std::shared_ptr<DataValue> FUMLFactoryImpl::createDataValue() const
{
	std::shared_ptr<DataValueImpl> element(new DataValueImpl());
	element->setThisDataValuePtr(element);
	return element;
}
std::shared_ptr<DecisionNodeActivation> FUMLFactoryImpl::createDecisionNodeActivation() const
{
	std::shared_ptr<DecisionNodeActivationImpl> element(new DecisionNodeActivationImpl());
	element->setThisDecisionNodeActivationPtr(element);
	return element;
}
std::shared_ptr<DecisionNodeActivation> FUMLFactoryImpl::createDecisionNodeActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<DecisionNodeActivationImpl> element(new DecisionNodeActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisDecisionNodeActivationPtr(element);
	return element;
	
}

std::shared_ptr<DestroyLinkActionActivation> FUMLFactoryImpl::createDestroyLinkActionActivation() const
{
	std::shared_ptr<DestroyLinkActionActivationImpl> element(new DestroyLinkActionActivationImpl());
	element->setThisDestroyLinkActionActivationPtr(element);
	return element;
}
std::shared_ptr<DestroyLinkActionActivation> FUMLFactoryImpl::createDestroyLinkActionActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<DestroyLinkActionActivationImpl> element(new DestroyLinkActionActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisDestroyLinkActionActivationPtr(element);
	return element;
	
}

std::shared_ptr<DestroyObjectActionActivation> FUMLFactoryImpl::createDestroyObjectActionActivation() const
{
	std::shared_ptr<DestroyObjectActionActivationImpl> element(new DestroyObjectActionActivationImpl());
	element->setThisDestroyObjectActionActivationPtr(element);
	return element;
}
std::shared_ptr<DestroyObjectActionActivation> FUMLFactoryImpl::createDestroyObjectActionActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<DestroyObjectActionActivationImpl> element(new DestroyObjectActionActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisDestroyObjectActionActivationPtr(element);
	return element;
	
}

std::shared_ptr<DispatchStrategy> FUMLFactoryImpl::createDispatchStrategy() const
{
	std::shared_ptr<DispatchStrategyImpl> element(new DispatchStrategyImpl());
	element->setThisDispatchStrategyPtr(element);
	return element;
}
std::shared_ptr<EnumerationValue> FUMLFactoryImpl::createEnumerationValue() const
{
	std::shared_ptr<EnumerationValueImpl> element(new EnumerationValueImpl());
	element->setThisEnumerationValuePtr(element);
	return element;
}
std::shared_ptr<EventDispatchLoop> FUMLFactoryImpl::createEventDispatchLoop() const
{
	std::shared_ptr<EventDispatchLoopImpl> element(new EventDispatchLoopImpl());
	element->setThisEventDispatchLoopPtr(element);
	return element;
}
std::shared_ptr<ExecutionFactoryL1> FUMLFactoryImpl::createExecutionFactoryL1() const
{
	std::shared_ptr<ExecutionFactoryL1Impl> element(new ExecutionFactoryL1Impl());
	element->setThisExecutionFactoryL1Ptr(element);
	return element;
}
std::shared_ptr<ExecutionFactoryL1> FUMLFactoryImpl::createExecutionFactoryL1_in_Locus(std::weak_ptr<fUML::Locus > par_locus) const
{
	std::shared_ptr<ExecutionFactoryL1Impl> element(new ExecutionFactoryL1Impl(par_locus));
	if(auto wp = par_locus.lock())
	{
			wp->setFactory(element);
	}
	element->setThisExecutionFactoryL1Ptr(element);
	return element;
	
}

std::shared_ptr<ExecutionFactoryL2> FUMLFactoryImpl::createExecutionFactoryL2() const
{
	std::shared_ptr<ExecutionFactoryL2Impl> element(new ExecutionFactoryL2Impl());
	element->setThisExecutionFactoryL2Ptr(element);
	return element;
}
std::shared_ptr<ExecutionFactoryL2> FUMLFactoryImpl::createExecutionFactoryL2_in_Locus(std::weak_ptr<fUML::Locus > par_locus) const
{
	std::shared_ptr<ExecutionFactoryL2Impl> element(new ExecutionFactoryL2Impl(par_locus));
	if(auto wp = par_locus.lock())
	{
			wp->setFactory(element);
	}
	element->setThisExecutionFactoryL2Ptr(element);
	return element;
	
}

std::shared_ptr<ExecutionFactoryL3> FUMLFactoryImpl::createExecutionFactoryL3() const
{
	std::shared_ptr<ExecutionFactoryL3Impl> element(new ExecutionFactoryL3Impl());
	element->setThisExecutionFactoryL3Ptr(element);
	return element;
}
std::shared_ptr<ExecutionFactoryL3> FUMLFactoryImpl::createExecutionFactoryL3_in_Locus(std::weak_ptr<fUML::Locus > par_locus) const
{
	std::shared_ptr<ExecutionFactoryL3Impl> element(new ExecutionFactoryL3Impl(par_locus));
	if(auto wp = par_locus.lock())
	{
			wp->setFactory(element);
	}
	element->setThisExecutionFactoryL3Ptr(element);
	return element;
	
}

std::shared_ptr<Executor> FUMLFactoryImpl::createExecutor() const
{
	std::shared_ptr<ExecutorImpl> element(new ExecutorImpl());
	element->setThisExecutorPtr(element);
	return element;
}
std::shared_ptr<Executor> FUMLFactoryImpl::createExecutor_in_Locus(std::weak_ptr<fUML::Locus > par_locus) const
{
	std::shared_ptr<ExecutorImpl> element(new ExecutorImpl(par_locus));
	if(auto wp = par_locus.lock())
	{
			wp->setExecutor(element);
	}
	element->setThisExecutorPtr(element);
	return element;
	
}

std::shared_ptr<ExpansionActivationGroup> FUMLFactoryImpl::createExpansionActivationGroup() const
{
	std::shared_ptr<ExpansionActivationGroupImpl> element(new ExpansionActivationGroupImpl());
	element->setThisExpansionActivationGroupPtr(element);
	return element;
}
std::shared_ptr<ExpansionActivationGroup> FUMLFactoryImpl::createExpansionActivationGroup_in_ActivityExecution(std::weak_ptr<fUML::ActivityExecution > par_activityExecution) const
{
	std::shared_ptr<ExpansionActivationGroupImpl> element(new ExpansionActivationGroupImpl(par_activityExecution));
	if(auto wp = par_activityExecution.lock())
	{
			wp->setActivationGroup(element);
	}
	element->setThisExpansionActivationGroupPtr(element);
	return element;
	
}

std::shared_ptr<ExpansionActivationGroup> FUMLFactoryImpl::createExpansionActivationGroup_in_ContainingNodeActivation(std::weak_ptr<fUML::StructuredActivityNodeActivation > par_containingNodeActivation) const
{
	std::shared_ptr<ExpansionActivationGroupImpl> element(new ExpansionActivationGroupImpl(par_containingNodeActivation));
	if(auto wp = par_containingNodeActivation.lock())
	{
			wp->setActivationGroup(element);
	}
	element->setThisExpansionActivationGroupPtr(element);
	return element;
	
}

std::shared_ptr<ExpansionNodeActivation> FUMLFactoryImpl::createExpansionNodeActivation() const
{
	std::shared_ptr<ExpansionNodeActivationImpl> element(new ExpansionNodeActivationImpl());
	element->setThisExpansionNodeActivationPtr(element);
	return element;
}
std::shared_ptr<ExpansionNodeActivation> FUMLFactoryImpl::createExpansionNodeActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<ExpansionNodeActivationImpl> element(new ExpansionNodeActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisExpansionNodeActivationPtr(element);
	return element;
	
}

std::shared_ptr<ExpansionRegionActivation> FUMLFactoryImpl::createExpansionRegionActivation() const
{
	std::shared_ptr<ExpansionRegionActivationImpl> element(new ExpansionRegionActivationImpl());
	element->setThisExpansionRegionActivationPtr(element);
	return element;
}
std::shared_ptr<ExpansionRegionActivation> FUMLFactoryImpl::createExpansionRegionActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<ExpansionRegionActivationImpl> element(new ExpansionRegionActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisExpansionRegionActivationPtr(element);
	return element;
	
}

std::shared_ptr<ExtensionalValueList> FUMLFactoryImpl::createExtensionalValueList() const
{
	std::shared_ptr<ExtensionalValueListImpl> element(new ExtensionalValueListImpl());
	element->setThisExtensionalValueListPtr(element);
	return element;
}
std::shared_ptr<FIFOGetNextEventStrategy> FUMLFactoryImpl::createFIFOGetNextEventStrategy() const
{
	std::shared_ptr<FIFOGetNextEventStrategyImpl> element(new FIFOGetNextEventStrategyImpl());
	element->setThisFIFOGetNextEventStrategyPtr(element);
	return element;
}
std::shared_ptr<FeatureValue> FUMLFactoryImpl::createFeatureValue() const
{
	std::shared_ptr<FeatureValueImpl> element(new FeatureValueImpl());
	element->setThisFeatureValuePtr(element);
	return element;
}
std::shared_ptr<FirstChoiceStrategy> FUMLFactoryImpl::createFirstChoiceStrategy() const
{
	std::shared_ptr<FirstChoiceStrategyImpl> element(new FirstChoiceStrategyImpl());
	element->setThisFirstChoiceStrategyPtr(element);
	return element;
}
std::shared_ptr<FlowFinalNodeActivation> FUMLFactoryImpl::createFlowFinalNodeActivation() const
{
	std::shared_ptr<FlowFinalNodeActivationImpl> element(new FlowFinalNodeActivationImpl());
	element->setThisFlowFinalNodeActivationPtr(element);
	return element;
}
std::shared_ptr<FlowFinalNodeActivation> FUMLFactoryImpl::createFlowFinalNodeActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<FlowFinalNodeActivationImpl> element(new FlowFinalNodeActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisFlowFinalNodeActivationPtr(element);
	return element;
	
}

std::shared_ptr<ForkNodeActivation> FUMLFactoryImpl::createForkNodeActivation() const
{
	std::shared_ptr<ForkNodeActivationImpl> element(new ForkNodeActivationImpl());
	element->setThisForkNodeActivationPtr(element);
	return element;
}
std::shared_ptr<ForkNodeActivation> FUMLFactoryImpl::createForkNodeActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<ForkNodeActivationImpl> element(new ForkNodeActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisForkNodeActivationPtr(element);
	return element;
	
}

std::shared_ptr<ForkedToken> FUMLFactoryImpl::createForkedToken() const
{
	std::shared_ptr<ForkedTokenImpl> element(new ForkedTokenImpl());
	element->setThisForkedTokenPtr(element);
	return element;
}
std::shared_ptr<InitialNodeActivation> FUMLFactoryImpl::createInitialNodeActivation() const
{
	std::shared_ptr<InitialNodeActivationImpl> element(new InitialNodeActivationImpl());
	element->setThisInitialNodeActivationPtr(element);
	return element;
}
std::shared_ptr<InitialNodeActivation> FUMLFactoryImpl::createInitialNodeActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<InitialNodeActivationImpl> element(new InitialNodeActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisInitialNodeActivationPtr(element);
	return element;
	
}

std::shared_ptr<InputPinActivation> FUMLFactoryImpl::createInputPinActivation() const
{
	std::shared_ptr<InputPinActivationImpl> element(new InputPinActivationImpl());
	element->setThisInputPinActivationPtr(element);
	return element;
}
std::shared_ptr<InputPinActivation> FUMLFactoryImpl::createInputPinActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<InputPinActivationImpl> element(new InputPinActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisInputPinActivationPtr(element);
	return element;
	
}

std::shared_ptr<InstanceValueEvaluation> FUMLFactoryImpl::createInstanceValueEvaluation() const
{
	std::shared_ptr<InstanceValueEvaluationImpl> element(new InstanceValueEvaluationImpl());
	element->setThisInstanceValueEvaluationPtr(element);
	return element;
}
std::shared_ptr<IntegerValue> FUMLFactoryImpl::createIntegerValue() const
{
	std::shared_ptr<IntegerValueImpl> element(new IntegerValueImpl());
	element->setThisIntegerValuePtr(element);
	return element;
}
std::shared_ptr<JoinNodeActivation> FUMLFactoryImpl::createJoinNodeActivation() const
{
	std::shared_ptr<JoinNodeActivationImpl> element(new JoinNodeActivationImpl());
	element->setThisJoinNodeActivationPtr(element);
	return element;
}
std::shared_ptr<JoinNodeActivation> FUMLFactoryImpl::createJoinNodeActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<JoinNodeActivationImpl> element(new JoinNodeActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisJoinNodeActivationPtr(element);
	return element;
	
}

std::shared_ptr<Link> FUMLFactoryImpl::createLink() const
{
	std::shared_ptr<LinkImpl> element(new LinkImpl());
	element->setThisLinkPtr(element);
	return element;
}
std::shared_ptr<LiteralBooleanEvaluation> FUMLFactoryImpl::createLiteralBooleanEvaluation() const
{
	std::shared_ptr<LiteralBooleanEvaluationImpl> element(new LiteralBooleanEvaluationImpl());
	element->setThisLiteralBooleanEvaluationPtr(element);
	return element;
}
std::shared_ptr<LiteralIntegerEvaluation> FUMLFactoryImpl::createLiteralIntegerEvaluation() const
{
	std::shared_ptr<LiteralIntegerEvaluationImpl> element(new LiteralIntegerEvaluationImpl());
	element->setThisLiteralIntegerEvaluationPtr(element);
	return element;
}
std::shared_ptr<LiteralNullEvaluation> FUMLFactoryImpl::createLiteralNullEvaluation() const
{
	std::shared_ptr<LiteralNullEvaluationImpl> element(new LiteralNullEvaluationImpl());
	element->setThisLiteralNullEvaluationPtr(element);
	return element;
}
std::shared_ptr<LiteralRealEvaluation> FUMLFactoryImpl::createLiteralRealEvaluation() const
{
	std::shared_ptr<LiteralRealEvaluationImpl> element(new LiteralRealEvaluationImpl());
	element->setThisLiteralRealEvaluationPtr(element);
	return element;
}
std::shared_ptr<LiteralStringEvaluation> FUMLFactoryImpl::createLiteralStringEvaluation() const
{
	std::shared_ptr<LiteralStringEvaluationImpl> element(new LiteralStringEvaluationImpl());
	element->setThisLiteralStringEvaluationPtr(element);
	return element;
}
std::shared_ptr<LiteralUnlimitedNaturalEvaluation> FUMLFactoryImpl::createLiteralUnlimitedNaturalEvaluation() const
{
	std::shared_ptr<LiteralUnlimitedNaturalEvaluationImpl> element(new LiteralUnlimitedNaturalEvaluationImpl());
	element->setThisLiteralUnlimitedNaturalEvaluationPtr(element);
	return element;
}
std::shared_ptr<Locus> FUMLFactoryImpl::createLocus() const
{
	std::shared_ptr<LocusImpl> element(new LocusImpl());
	element->setThisLocusPtr(element);
	return element;
}
std::shared_ptr<LoopNodeActivation> FUMLFactoryImpl::createLoopNodeActivation() const
{
	std::shared_ptr<LoopNodeActivationImpl> element(new LoopNodeActivationImpl());
	element->setThisLoopNodeActivationPtr(element);
	return element;
}
std::shared_ptr<LoopNodeActivation> FUMLFactoryImpl::createLoopNodeActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<LoopNodeActivationImpl> element(new LoopNodeActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisLoopNodeActivationPtr(element);
	return element;
	
}

std::shared_ptr<MergeNodeActivation> FUMLFactoryImpl::createMergeNodeActivation() const
{
	std::shared_ptr<MergeNodeActivationImpl> element(new MergeNodeActivationImpl());
	element->setThisMergeNodeActivationPtr(element);
	return element;
}
std::shared_ptr<MergeNodeActivation> FUMLFactoryImpl::createMergeNodeActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<MergeNodeActivationImpl> element(new MergeNodeActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisMergeNodeActivationPtr(element);
	return element;
	
}

std::shared_ptr<Object> FUMLFactoryImpl::createObject() const
{
	std::shared_ptr<ObjectImpl> element(new ObjectImpl());
	element->setThisObjectPtr(element);
	return element;
}
std::shared_ptr<ObjectActivation> FUMLFactoryImpl::createObjectActivation() const
{
	std::shared_ptr<ObjectActivationImpl> element(new ObjectActivationImpl());
	element->setThisObjectActivationPtr(element);
	return element;
}
std::shared_ptr<ObjectToken> FUMLFactoryImpl::createObjectToken() const
{
	std::shared_ptr<ObjectTokenImpl> element(new ObjectTokenImpl());
	element->setThisObjectTokenPtr(element);
	return element;
}
std::shared_ptr<Offer> FUMLFactoryImpl::createOffer() const
{
	std::shared_ptr<OfferImpl> element(new OfferImpl());
	element->setThisOfferPtr(element);
	return element;
}
std::shared_ptr<OutputPinActivation> FUMLFactoryImpl::createOutputPinActivation() const
{
	std::shared_ptr<OutputPinActivationImpl> element(new OutputPinActivationImpl());
	element->setThisOutputPinActivationPtr(element);
	return element;
}
std::shared_ptr<OutputPinActivation> FUMLFactoryImpl::createOutputPinActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<OutputPinActivationImpl> element(new OutputPinActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisOutputPinActivationPtr(element);
	return element;
	
}

std::shared_ptr<ParameterValue> FUMLFactoryImpl::createParameterValue() const
{
	std::shared_ptr<ParameterValueImpl> element(new ParameterValueImpl());
	element->setThisParameterValuePtr(element);
	return element;
}
std::shared_ptr<ReadExtentActionActivation> FUMLFactoryImpl::createReadExtentActionActivation() const
{
	std::shared_ptr<ReadExtentActionActivationImpl> element(new ReadExtentActionActivationImpl());
	element->setThisReadExtentActionActivationPtr(element);
	return element;
}
std::shared_ptr<ReadExtentActionActivation> FUMLFactoryImpl::createReadExtentActionActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<ReadExtentActionActivationImpl> element(new ReadExtentActionActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisReadExtentActionActivationPtr(element);
	return element;
	
}

std::shared_ptr<ReadIsClassifiedObjectActionActivation> FUMLFactoryImpl::createReadIsClassifiedObjectActionActivation() const
{
	std::shared_ptr<ReadIsClassifiedObjectActionActivationImpl> element(new ReadIsClassifiedObjectActionActivationImpl());
	element->setThisReadIsClassifiedObjectActionActivationPtr(element);
	return element;
}
std::shared_ptr<ReadIsClassifiedObjectActionActivation> FUMLFactoryImpl::createReadIsClassifiedObjectActionActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<ReadIsClassifiedObjectActionActivationImpl> element(new ReadIsClassifiedObjectActionActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisReadIsClassifiedObjectActionActivationPtr(element);
	return element;
	
}

std::shared_ptr<ReadLinkActionActivation> FUMLFactoryImpl::createReadLinkActionActivation() const
{
	std::shared_ptr<ReadLinkActionActivationImpl> element(new ReadLinkActionActivationImpl());
	element->setThisReadLinkActionActivationPtr(element);
	return element;
}
std::shared_ptr<ReadLinkActionActivation> FUMLFactoryImpl::createReadLinkActionActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<ReadLinkActionActivationImpl> element(new ReadLinkActionActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisReadLinkActionActivationPtr(element);
	return element;
	
}

std::shared_ptr<ReadSelfActionActivation> FUMLFactoryImpl::createReadSelfActionActivation() const
{
	std::shared_ptr<ReadSelfActionActivationImpl> element(new ReadSelfActionActivationImpl());
	element->setThisReadSelfActionActivationPtr(element);
	return element;
}
std::shared_ptr<ReadSelfActionActivation> FUMLFactoryImpl::createReadSelfActionActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<ReadSelfActionActivationImpl> element(new ReadSelfActionActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisReadSelfActionActivationPtr(element);
	return element;
	
}

std::shared_ptr<ReadStructuralFeatureActionActivation> FUMLFactoryImpl::createReadStructuralFeatureActionActivation() const
{
	std::shared_ptr<ReadStructuralFeatureActionActivationImpl> element(new ReadStructuralFeatureActionActivationImpl());
	element->setThisReadStructuralFeatureActionActivationPtr(element);
	return element;
}
std::shared_ptr<ReadStructuralFeatureActionActivation> FUMLFactoryImpl::createReadStructuralFeatureActionActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<ReadStructuralFeatureActionActivationImpl> element(new ReadStructuralFeatureActionActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisReadStructuralFeatureActionActivationPtr(element);
	return element;
	
}

std::shared_ptr<RealValue> FUMLFactoryImpl::createRealValue() const
{
	std::shared_ptr<RealValueImpl> element(new RealValueImpl());
	element->setThisRealValuePtr(element);
	return element;
}
std::shared_ptr<ReclassifyObjectActionActivation> FUMLFactoryImpl::createReclassifyObjectActionActivation() const
{
	std::shared_ptr<ReclassifyObjectActionActivationImpl> element(new ReclassifyObjectActionActivationImpl());
	element->setThisReclassifyObjectActionActivationPtr(element);
	return element;
}
std::shared_ptr<ReclassifyObjectActionActivation> FUMLFactoryImpl::createReclassifyObjectActionActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<ReclassifyObjectActionActivationImpl> element(new ReclassifyObjectActionActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisReclassifyObjectActionActivationPtr(element);
	return element;
	
}

std::shared_ptr<RedefinitionBasedDispatchStrategy> FUMLFactoryImpl::createRedefinitionBasedDispatchStrategy() const
{
	std::shared_ptr<RedefinitionBasedDispatchStrategyImpl> element(new RedefinitionBasedDispatchStrategyImpl());
	element->setThisRedefinitionBasedDispatchStrategyPtr(element);
	return element;
}
std::shared_ptr<ReduceActionActivation> FUMLFactoryImpl::createReduceActionActivation() const
{
	std::shared_ptr<ReduceActionActivationImpl> element(new ReduceActionActivationImpl());
	element->setThisReduceActionActivationPtr(element);
	return element;
}
std::shared_ptr<ReduceActionActivation> FUMLFactoryImpl::createReduceActionActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<ReduceActionActivationImpl> element(new ReduceActionActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisReduceActionActivationPtr(element);
	return element;
	
}

std::shared_ptr<Reference> FUMLFactoryImpl::createReference() const
{
	std::shared_ptr<ReferenceImpl> element(new ReferenceImpl());
	element->setThisReferencePtr(element);
	return element;
}
std::shared_ptr<RemoveStructuralFeatureValueActivation> FUMLFactoryImpl::createRemoveStructuralFeatureValueActivation() const
{
	std::shared_ptr<RemoveStructuralFeatureValueActivationImpl> element(new RemoveStructuralFeatureValueActivationImpl());
	element->setThisRemoveStructuralFeatureValueActivationPtr(element);
	return element;
}
std::shared_ptr<RemoveStructuralFeatureValueActivation> FUMLFactoryImpl::createRemoveStructuralFeatureValueActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<RemoveStructuralFeatureValueActivationImpl> element(new RemoveStructuralFeatureValueActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisRemoveStructuralFeatureValueActivationPtr(element);
	return element;
	
}

std::shared_ptr<SendSignalActionActivation> FUMLFactoryImpl::createSendSignalActionActivation() const
{
	std::shared_ptr<SendSignalActionActivationImpl> element(new SendSignalActionActivationImpl());
	element->setThisSendSignalActionActivationPtr(element);
	return element;
}
std::shared_ptr<SendSignalActionActivation> FUMLFactoryImpl::createSendSignalActionActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<SendSignalActionActivationImpl> element(new SendSignalActionActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisSendSignalActionActivationPtr(element);
	return element;
	
}

std::shared_ptr<SignalInstance> FUMLFactoryImpl::createSignalInstance() const
{
	std::shared_ptr<SignalInstanceImpl> element(new SignalInstanceImpl());
	element->setThisSignalInstancePtr(element);
	return element;
}
std::shared_ptr<StartClassifierBehaviorActionActivation> FUMLFactoryImpl::createStartClassifierBehaviorActionActivation() const
{
	std::shared_ptr<StartClassifierBehaviorActionActivationImpl> element(new StartClassifierBehaviorActionActivationImpl());
	element->setThisStartClassifierBehaviorActionActivationPtr(element);
	return element;
}
std::shared_ptr<StartClassifierBehaviorActionActivation> FUMLFactoryImpl::createStartClassifierBehaviorActionActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<StartClassifierBehaviorActionActivationImpl> element(new StartClassifierBehaviorActionActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisStartClassifierBehaviorActionActivationPtr(element);
	return element;
	
}

std::shared_ptr<StartObjectBehaviorActionActivation> FUMLFactoryImpl::createStartObjectBehaviorActionActivation() const
{
	std::shared_ptr<StartObjectBehaviorActionActivationImpl> element(new StartObjectBehaviorActionActivationImpl());
	element->setThisStartObjectBehaviorActionActivationPtr(element);
	return element;
}
std::shared_ptr<StartObjectBehaviorActionActivation> FUMLFactoryImpl::createStartObjectBehaviorActionActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<StartObjectBehaviorActionActivationImpl> element(new StartObjectBehaviorActionActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisStartObjectBehaviorActionActivationPtr(element);
	return element;
	
}

std::shared_ptr<StringValue> FUMLFactoryImpl::createStringValue() const
{
	std::shared_ptr<StringValueImpl> element(new StringValueImpl());
	element->setThisStringValuePtr(element);
	return element;
}
std::shared_ptr<StructuredActivityNodeActivation> FUMLFactoryImpl::createStructuredActivityNodeActivation() const
{
	std::shared_ptr<StructuredActivityNodeActivationImpl> element(new StructuredActivityNodeActivationImpl());
	element->setThisStructuredActivityNodeActivationPtr(element);
	return element;
}
std::shared_ptr<StructuredActivityNodeActivation> FUMLFactoryImpl::createStructuredActivityNodeActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<StructuredActivityNodeActivationImpl> element(new StructuredActivityNodeActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisStructuredActivityNodeActivationPtr(element);
	return element;
	
}

std::shared_ptr<TestIdentityActionActivation> FUMLFactoryImpl::createTestIdentityActionActivation() const
{
	std::shared_ptr<TestIdentityActionActivationImpl> element(new TestIdentityActionActivationImpl());
	element->setThisTestIdentityActionActivationPtr(element);
	return element;
}
std::shared_ptr<TestIdentityActionActivation> FUMLFactoryImpl::createTestIdentityActionActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<TestIdentityActionActivationImpl> element(new TestIdentityActionActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisTestIdentityActionActivationPtr(element);
	return element;
	
}

std::shared_ptr<TokenSet> FUMLFactoryImpl::createTokenSet() const
{
	std::shared_ptr<TokenSetImpl> element(new TokenSetImpl());
	element->setThisTokenSetPtr(element);
	return element;
}
std::shared_ptr<UnlimitedNaturalValue> FUMLFactoryImpl::createUnlimitedNaturalValue() const
{
	std::shared_ptr<UnlimitedNaturalValueImpl> element(new UnlimitedNaturalValueImpl());
	element->setThisUnlimitedNaturalValuePtr(element);
	return element;
}
std::shared_ptr<ValueSpecificActionActivation> FUMLFactoryImpl::createValueSpecificActionActivation() const
{
	std::shared_ptr<ValueSpecificActionActivationImpl> element(new ValueSpecificActionActivationImpl());
	element->setThisValueSpecificActionActivationPtr(element);
	return element;
}
std::shared_ptr<ValueSpecificActionActivation> FUMLFactoryImpl::createValueSpecificActionActivation_in_Group(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group) const
{
	std::shared_ptr<ValueSpecificActionActivationImpl> element(new ValueSpecificActionActivationImpl(par_group));
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisValueSpecificActionActivationPtr(element);
	return element;
	
}

std::shared_ptr<Values> FUMLFactoryImpl::createValues() const
{
	std::shared_ptr<ValuesImpl> element(new ValuesImpl());
	element->setThisValuesPtr(element);
	return element;
}

std::shared_ptr<FUMLPackage> FUMLFactoryImpl::getFUMLPackage() const
{
	return FUMLPackage::eInstance();
}
