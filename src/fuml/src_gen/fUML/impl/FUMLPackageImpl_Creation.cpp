#include "fUML/impl/FUMLPackageImpl.hpp"

// metametamodel factory
#include "ecore/EcoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

//depending model packages
#include "ecore/EcorePackage.hpp"
#include "types/TypesPackage.hpp"
#include "uml/UmlPackage.hpp"
//include subpackages 
#include "fUML/Semantics/impl/SemanticsPackageImpl.hpp"
 
using namespace fUML;

void FUMLPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::EcoreFactory> factory = ecore::EcoreFactory::eInstance();


	createPackageEDataTypes(package, factory);

	std::dynamic_pointer_cast<fUML::Semantics::SemanticsPackageImpl>(getSemantics_Package())->createPackageContents(getSemantics_Package());

}

<<<<<<< HEAD
void FUMLPackageImpl::createEventAccepterContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_eventAccepter_Class = factory->createEClass_in_EPackage(package, EVENTACCEPTER_CLASS);
	
	
	m_eventAccepter_Operation_accept_SignalInstance = factory->createEOperation_in_EContainingClass(m_eventAccepter_Class, EVENTACCEPTER_OPERATION_ACCEPT_SIGNALINSTANCE);
	m_eventAccepter_Operation_match_SignalInstance = factory->createEOperation_in_EContainingClass(m_eventAccepter_Class, EVENTACCEPTER_OPERATION_MATCH_SIGNALINSTANCE);
	
}

void FUMLPackageImpl::createEventDispatchLoopContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_eventDispatchLoop_Class = factory->createEClass_in_EPackage(package, EVENTDISPATCHLOOP_CLASS);
	
	
	
}

void FUMLPackageImpl::createEventOccurrenceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_eventOccurrence_Class = factory->createEClass_in_EPackage(package, EVENTOCCURRENCE_CLASS);
	
	m_eventOccurrence_Attribute_target = factory->createEReference_in_EContainingClass(m_eventOccurrence_Class, EVENTOCCURRENCE_ATTRIBUTE_TARGET);
	
	m_eventOccurrence_Operation_doSend = factory->createEOperation_in_EContainingClass(m_eventOccurrence_Class, EVENTOCCURRENCE_OPERATION_DOSEND);
	m_eventOccurrence_Operation_getParameterValues = factory->createEOperation_in_EContainingClass(m_eventOccurrence_Class, EVENTOCCURRENCE_OPERATION_GETPARAMETERVALUES);
	m_eventOccurrence_Operation_match_Trigger = factory->createEOperation_in_EContainingClass(m_eventOccurrence_Class, EVENTOCCURRENCE_OPERATION_MATCH_TRIGGER);
	m_eventOccurrence_Operation_matchAny_Trigger = factory->createEOperation_in_EContainingClass(m_eventOccurrence_Class, EVENTOCCURRENCE_OPERATION_MATCHANY_TRIGGER);
	m_eventOccurrence_Operation_sendTo_Reference = factory->createEOperation_in_EContainingClass(m_eventOccurrence_Class, EVENTOCCURRENCE_OPERATION_SENDTO_REFERENCE);
	
}

void FUMLPackageImpl::createExecutionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_execution_Class = factory->createEClass_in_EPackage(package, EXECUTION_CLASS);
	
	m_execution_Attribute_context = factory->createEReference_in_EContainingClass(m_execution_Class, EXECUTION_ATTRIBUTE_CONTEXT);
	m_execution_Attribute_parameterValues = factory->createEReference_in_EContainingClass(m_execution_Class, EXECUTION_ATTRIBUTE_PARAMETERVALUES);
	
	m_execution_Operation_execute = factory->createEOperation_in_EContainingClass(m_execution_Class, EXECUTION_OPERATION_EXECUTE);
	m_execution_Operation_getBehavior = factory->createEOperation_in_EContainingClass(m_execution_Class, EXECUTION_OPERATION_GETBEHAVIOR);
	m_execution_Operation_getOutputParameterValues = factory->createEOperation_in_EContainingClass(m_execution_Class, EXECUTION_OPERATION_GETOUTPUTPARAMETERVALUES);
	m_execution_Operation_getParameterValue_Parameter = factory->createEOperation_in_EContainingClass(m_execution_Class, EXECUTION_OPERATION_GETPARAMETERVALUE_PARAMETER);
	m_execution_Operation_new_ = factory->createEOperation_in_EContainingClass(m_execution_Class, EXECUTION_OPERATION_NEW_);
	m_execution_Operation_setParameterValue_ParameterValue = factory->createEOperation_in_EContainingClass(m_execution_Class, EXECUTION_OPERATION_SETPARAMETERVALUE_PARAMETERVALUE);
	m_execution_Operation_terminate = factory->createEOperation_in_EContainingClass(m_execution_Class, EXECUTION_OPERATION_TERMINATE);
	
}

void FUMLPackageImpl::createExecutionFactoryContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_executionFactory_Class = factory->createEClass_in_EPackage(package, EXECUTIONFACTORY_CLASS);
	
	m_executionFactory_Attribute_builtInTypes = factory->createEReference_in_EContainingClass(m_executionFactory_Class, EXECUTIONFACTORY_ATTRIBUTE_BUILTINTYPES);
	m_executionFactory_Attribute_locus = factory->createEReference_in_EContainingClass(m_executionFactory_Class, EXECUTIONFACTORY_ATTRIBUTE_LOCUS);
	m_executionFactory_Attribute_primitiveBehaviorPrototypes = factory->createEReference_in_EContainingClass(m_executionFactory_Class, EXECUTIONFACTORY_ATTRIBUTE_PRIMITIVEBEHAVIORPROTOTYPES);
	m_executionFactory_Attribute_strategies = factory->createEReference_in_EContainingClass(m_executionFactory_Class, EXECUTIONFACTORY_ATTRIBUTE_STRATEGIES);
	
	m_executionFactory_Operation_addBuiltInType_PrimitiveType = factory->createEOperation_in_EContainingClass(m_executionFactory_Class, EXECUTIONFACTORY_OPERATION_ADDBUILTINTYPE_PRIMITIVETYPE);
	m_executionFactory_Operation_addPrimitiveBehaviorPrototype_OpaqueBehaviorExecution = factory->createEOperation_in_EContainingClass(m_executionFactory_Class, EXECUTIONFACTORY_OPERATION_ADDPRIMITIVEBEHAVIORPROTOTYPE_OPAQUEBEHAVIOREXECUTION);
	m_executionFactory_Operation_assignStrategy_SemanticStrategy = factory->createEOperation_in_EContainingClass(m_executionFactory_Class, EXECUTIONFACTORY_OPERATION_ASSIGNSTRATEGY_SEMANTICSTRATEGY);
	m_executionFactory_Operation_createEvaluation_ValueSpecification = factory->createEOperation_in_EContainingClass(m_executionFactory_Class, EXECUTIONFACTORY_OPERATION_CREATEEVALUATION_VALUESPECIFICATION);
	m_executionFactory_Operation_createExecution_Behavior_Object = factory->createEOperation_in_EContainingClass(m_executionFactory_Class, EXECUTIONFACTORY_OPERATION_CREATEEXECUTION_BEHAVIOR_OBJECT);
	m_executionFactory_Operation_getBuiltInType_EString = factory->createEOperation_in_EContainingClass(m_executionFactory_Class, EXECUTIONFACTORY_OPERATION_GETBUILTINTYPE_ESTRING);
	m_executionFactory_Operation_getStrategy_EString = factory->createEOperation_in_EContainingClass(m_executionFactory_Class, EXECUTIONFACTORY_OPERATION_GETSTRATEGY_ESTRING);
	m_executionFactory_Operation_getStrategyIndex_EString = factory->createEOperation_in_EContainingClass(m_executionFactory_Class, EXECUTIONFACTORY_OPERATION_GETSTRATEGYINDEX_ESTRING);
	m_executionFactory_Operation_instantiateOpaqueBehaviorExecution_OpaqueBehavior = factory->createEOperation_in_EContainingClass(m_executionFactory_Class, EXECUTIONFACTORY_OPERATION_INSTANTIATEOPAQUEBEHAVIOREXECUTION_OPAQUEBEHAVIOR);
	m_executionFactory_Operation_instantiateVisitor_Element = factory->createEOperation_in_EContainingClass(m_executionFactory_Class, EXECUTIONFACTORY_OPERATION_INSTANTIATEVISITOR_ELEMENT);
	
}

void FUMLPackageImpl::createExecutorContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_executor_Class = factory->createEClass_in_EPackage(package, EXECUTOR_CLASS);
	
	m_executor_Attribute_locus = factory->createEReference_in_EContainingClass(m_executor_Class, EXECUTOR_ATTRIBUTE_LOCUS);
	
	m_executor_Operation_evaluate_ValueSpecification = factory->createEOperation_in_EContainingClass(m_executor_Class, EXECUTOR_OPERATION_EVALUATE_VALUESPECIFICATION);
	m_executor_Operation_execute_Behavior_ParameterValue = factory->createEOperation_in_EContainingClass(m_executor_Class, EXECUTOR_OPERATION_EXECUTE_BEHAVIOR_PARAMETERVALUE);
	m_executor_Operation_start_Class_ParameterValue = factory->createEOperation_in_EContainingClass(m_executor_Class, EXECUTOR_OPERATION_START_CLASS_PARAMETERVALUE);
	
}

void FUMLPackageImpl::createExpansionActivationGroupContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_expansionActivationGroup_Class = factory->createEClass_in_EPackage(package, EXPANSIONACTIVATIONGROUP_CLASS);
	m_expansionActivationGroup_Attribute_index = factory->createEAttribute_in_EContainingClass(m_expansionActivationGroup_Class, EXPANSIONACTIVATIONGROUP_ATTRIBUTE_INDEX);
	
	m_expansionActivationGroup_Attribute_groupInputs = factory->createEReference_in_EContainingClass(m_expansionActivationGroup_Class, EXPANSIONACTIVATIONGROUP_ATTRIBUTE_GROUPINPUTS);
	m_expansionActivationGroup_Attribute_groupOutputs = factory->createEReference_in_EContainingClass(m_expansionActivationGroup_Class, EXPANSIONACTIVATIONGROUP_ATTRIBUTE_GROUPOUTPUTS);
	m_expansionActivationGroup_Attribute_regionActivation = factory->createEReference_in_EContainingClass(m_expansionActivationGroup_Class, EXPANSIONACTIVATIONGROUP_ATTRIBUTE_REGIONACTIVATION);
	m_expansionActivationGroup_Attribute_regionInputs = factory->createEReference_in_EContainingClass(m_expansionActivationGroup_Class, EXPANSIONACTIVATIONGROUP_ATTRIBUTE_REGIONINPUTS);
	
	m_expansionActivationGroup_Operation_getActivityExecution = factory->createEOperation_in_EContainingClass(m_expansionActivationGroup_Class, EXPANSIONACTIVATIONGROUP_OPERATION_GETACTIVITYEXECUTION);
	m_expansionActivationGroup_Operation_getNodeActivation_ActivityNode = factory->createEOperation_in_EContainingClass(m_expansionActivationGroup_Class, EXPANSIONACTIVATIONGROUP_OPERATION_GETNODEACTIVATION_ACTIVITYNODE);
	m_expansionActivationGroup_Operation_resume_ActivityNodeActivation = factory->createEOperation_in_EContainingClass(m_expansionActivationGroup_Class, EXPANSIONACTIVATIONGROUP_OPERATION_RESUME_ACTIVITYNODEACTIVATION);
	m_expansionActivationGroup_Operation_suspend_ActivityNodeActivation = factory->createEOperation_in_EContainingClass(m_expansionActivationGroup_Class, EXPANSIONACTIVATIONGROUP_OPERATION_SUSPEND_ACTIVITYNODEACTIVATION);
	
}

void FUMLPackageImpl::createExpansionNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_expansionNodeActivation_Class = factory->createEClass_in_EPackage(package, EXPANSIONNODEACTIVATION_CLASS);
	
	
	m_expansionNodeActivation_Operation_fire_Token = factory->createEOperation_in_EContainingClass(m_expansionNodeActivation_Class, EXPANSIONNODEACTIVATION_OPERATION_FIRE_TOKEN);
	m_expansionNodeActivation_Operation_getExpansionRegionActivation = factory->createEOperation_in_EContainingClass(m_expansionNodeActivation_Class, EXPANSIONNODEACTIVATION_OPERATION_GETEXPANSIONREGIONACTIVATION);
	m_expansionNodeActivation_Operation_isReady = factory->createEOperation_in_EContainingClass(m_expansionNodeActivation_Class, EXPANSIONNODEACTIVATION_OPERATION_ISREADY);
	m_expansionNodeActivation_Operation_receiveOffer = factory->createEOperation_in_EContainingClass(m_expansionNodeActivation_Class, EXPANSIONNODEACTIVATION_OPERATION_RECEIVEOFFER);
	
}

void FUMLPackageImpl::createExpansionRegionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_expansionRegionActivation_Class = factory->createEClass_in_EPackage(package, EXPANSIONREGIONACTIVATION_CLASS);
	m_expansionRegionActivation_Attribute_next = factory->createEAttribute_in_EContainingClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_ATTRIBUTE_NEXT);
	
	m_expansionRegionActivation_Attribute_activationGroups = factory->createEReference_in_EContainingClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_ATTRIBUTE_ACTIVATIONGROUPS);
	m_expansionRegionActivation_Attribute_inputExpansionTokens = factory->createEReference_in_EContainingClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_ATTRIBUTE_INPUTEXPANSIONTOKENS);
	m_expansionRegionActivation_Attribute_inputTokens = factory->createEReference_in_EContainingClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_ATTRIBUTE_INPUTTOKENS);
	
	m_expansionRegionActivation_Operation_doAction = factory->createEOperation_in_EContainingClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_OPERATION_DOACTION);
	m_expansionRegionActivation_Operation_doOutput = factory->createEOperation_in_EContainingClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_OPERATION_DOOUTPUT);
	m_expansionRegionActivation_Operation_doStructuredActivity = factory->createEOperation_in_EContainingClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_OPERATION_DOSTRUCTUREDACTIVITY);
	m_expansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode = factory->createEOperation_in_EContainingClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_OPERATION_GETEXPANSIONNODEACTIVATION_EXPANSIONNODE);
	m_expansionRegionActivation_Operation_isSuspended = factory->createEOperation_in_EContainingClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_OPERATION_ISSUSPENDED);
	m_expansionRegionActivation_Operation_numberOfValues = factory->createEOperation_in_EContainingClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_OPERATION_NUMBEROFVALUES);
	m_expansionRegionActivation_Operation_resume_ExpansionActivationGroup = factory->createEOperation_in_EContainingClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_OPERATION_RESUME_EXPANSIONACTIVATIONGROUP);
	m_expansionRegionActivation_Operation_runGroup_ExpansionActivationGroup = factory->createEOperation_in_EContainingClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_OPERATION_RUNGROUP_EXPANSIONACTIVATIONGROUP);
	m_expansionRegionActivation_Operation_runIterative = factory->createEOperation_in_EContainingClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_OPERATION_RUNITERATIVE);
	m_expansionRegionActivation_Operation_runParallel = factory->createEOperation_in_EContainingClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_OPERATION_RUNPARALLEL);
	m_expansionRegionActivation_Operation_sendOffers = factory->createEOperation_in_EContainingClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_OPERATION_SENDOFFERS);
	m_expansionRegionActivation_Operation_takeOfferedTokens = factory->createEOperation_in_EContainingClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_OPERATION_TAKEOFFEREDTOKENS);
	m_expansionRegionActivation_Operation_terminate = factory->createEOperation_in_EContainingClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_OPERATION_TERMINATE);
	m_expansionRegionActivation_Operation_terminateGroup_ExpansionActivationGroup = factory->createEOperation_in_EContainingClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_OPERATION_TERMINATEGROUP_EXPANSIONACTIVATIONGROUP);
	
}

void FUMLPackageImpl::createExtensionalValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_extensionalValue_Class = factory->createEClass_in_EPackage(package, EXTENSIONALVALUE_CLASS);
	
	m_extensionalValue_Attribute_locus = factory->createEReference_in_EContainingClass(m_extensionalValue_Class, EXTENSIONALVALUE_ATTRIBUTE_LOCUS);
	
	m_extensionalValue_Operation_destroy = factory->createEOperation_in_EContainingClass(m_extensionalValue_Class, EXTENSIONALVALUE_OPERATION_DESTROY);
	
}

void FUMLPackageImpl::createExtensionalValueListContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_extensionalValueList_Class = factory->createEClass_in_EPackage(package, EXTENSIONALVALUELIST_CLASS);
	
	
	m_extensionalValueList_Operation_addValue_ExtensionalValue = factory->createEOperation_in_EContainingClass(m_extensionalValueList_Class, EXTENSIONALVALUELIST_OPERATION_ADDVALUE_EXTENSIONALVALUE);
	m_extensionalValueList_Operation_addValue_ExtensionalValue_EInt = factory->createEOperation_in_EContainingClass(m_extensionalValueList_Class, EXTENSIONALVALUELIST_OPERATION_ADDVALUE_EXTENSIONALVALUE_EINT);
	m_extensionalValueList_Operation_getValue = factory->createEOperation_in_EContainingClass(m_extensionalValueList_Class, EXTENSIONALVALUELIST_OPERATION_GETVALUE);
	m_extensionalValueList_Operation_removeValue_EInt = factory->createEOperation_in_EContainingClass(m_extensionalValueList_Class, EXTENSIONALVALUELIST_OPERATION_REMOVEVALUE_EINT);
	m_extensionalValueList_Operation_setValue_ExtensionalValue_EInt = factory->createEOperation_in_EContainingClass(m_extensionalValueList_Class, EXTENSIONALVALUELIST_OPERATION_SETVALUE_EXTENSIONALVALUE_EINT);
	
}

void FUMLPackageImpl::createFIFOGetNextEventStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_fIFOGetNextEventStrategy_Class = factory->createEClass_in_EPackage(package, FIFOGETNEXTEVENTSTRATEGY_CLASS);
	
	
	
}

void FUMLPackageImpl::createFeatureValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_featureValue_Class = factory->createEClass_in_EPackage(package, FEATUREVALUE_CLASS);
	m_featureValue_Attribute_position = factory->createEAttribute_in_EContainingClass(m_featureValue_Class, FEATUREVALUE_ATTRIBUTE_POSITION);
	
	m_featureValue_Attribute_feature = factory->createEReference_in_EContainingClass(m_featureValue_Class, FEATUREVALUE_ATTRIBUTE_FEATURE);
	m_featureValue_Attribute_values = factory->createEReference_in_EContainingClass(m_featureValue_Class, FEATUREVALUE_ATTRIBUTE_VALUES);
	
	m_featureValue_Operation_hasEqualValues_FeatureValue = factory->createEOperation_in_EContainingClass(m_featureValue_Class, FEATUREVALUE_OPERATION_HASEQUALVALUES_FEATUREVALUE);
	
}

void FUMLPackageImpl::createFirstChoiceStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_firstChoiceStrategy_Class = factory->createEClass_in_EPackage(package, FIRSTCHOICESTRATEGY_CLASS);
	
	
	m_firstChoiceStrategy_Operation_choose_EInt = factory->createEOperation_in_EContainingClass(m_firstChoiceStrategy_Class, FIRSTCHOICESTRATEGY_OPERATION_CHOOSE_EINT);
	
}

void FUMLPackageImpl::createFlowFinalNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_flowFinalNodeActivation_Class = factory->createEClass_in_EPackage(package, FLOWFINALNODEACTIVATION_CLASS);
	
	
	
}

void FUMLPackageImpl::createForkNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_forkNodeActivation_Class = factory->createEClass_in_EPackage(package, FORKNODEACTIVATION_CLASS);
	
	
	m_forkNodeActivation_Operation_fire_Token = factory->createEOperation_in_EContainingClass(m_forkNodeActivation_Class, FORKNODEACTIVATION_OPERATION_FIRE_TOKEN);
	m_forkNodeActivation_Operation_terminate = factory->createEOperation_in_EContainingClass(m_forkNodeActivation_Class, FORKNODEACTIVATION_OPERATION_TERMINATE);
	
}

void FUMLPackageImpl::createForkedTokenContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_forkedToken_Class = factory->createEClass_in_EPackage(package, FORKEDTOKEN_CLASS);
	m_forkedToken_Attribute_baseTokenIsWithdrawn = factory->createEAttribute_in_EContainingClass(m_forkedToken_Class, FORKEDTOKEN_ATTRIBUTE_BASETOKENISWITHDRAWN);
	m_forkedToken_Attribute_remainingOffersCount = factory->createEAttribute_in_EContainingClass(m_forkedToken_Class, FORKEDTOKEN_ATTRIBUTE_REMAININGOFFERSCOUNT);
	
	m_forkedToken_Attribute_baseToken = factory->createEReference_in_EContainingClass(m_forkedToken_Class, FORKEDTOKEN_ATTRIBUTE_BASETOKEN);
	
	m_forkedToken_Operation_equals_Token = factory->createEOperation_in_EContainingClass(m_forkedToken_Class, FORKEDTOKEN_OPERATION_EQUALS_TOKEN);
	m_forkedToken_Operation_getValue = factory->createEOperation_in_EContainingClass(m_forkedToken_Class, FORKEDTOKEN_OPERATION_GETVALUE);
	m_forkedToken_Operation_isControl = factory->createEOperation_in_EContainingClass(m_forkedToken_Class, FORKEDTOKEN_OPERATION_ISCONTROL);
	m_forkedToken_Operation_withdraw = factory->createEOperation_in_EContainingClass(m_forkedToken_Class, FORKEDTOKEN_OPERATION_WITHDRAW);
	
}

void FUMLPackageImpl::createGetNextEventStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_getNextEventStrategy_Class = factory->createEClass_in_EPackage(package, GETNEXTEVENTSTRATEGY_CLASS);
	
	
	m_getNextEventStrategy_Operation_getName = factory->createEOperation_in_EContainingClass(m_getNextEventStrategy_Class, GETNEXTEVENTSTRATEGY_OPERATION_GETNAME);
	m_getNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation = factory->createEOperation_in_EContainingClass(m_getNextEventStrategy_Class, GETNEXTEVENTSTRATEGY_OPERATION_RETRIEVENEXTEVENT_OBJECTACTIVATION);
	
}

void FUMLPackageImpl::createInitialNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_initialNodeActivation_Class = factory->createEClass_in_EPackage(package, INITIALNODEACTIVATION_CLASS);
	
	
	m_initialNodeActivation_Operation_fire_Token = factory->createEOperation_in_EContainingClass(m_initialNodeActivation_Class, INITIALNODEACTIVATION_OPERATION_FIRE_TOKEN);
	
}

void FUMLPackageImpl::createInputPinActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_inputPinActivation_Class = factory->createEClass_in_EPackage(package, INPUTPINACTIVATION_CLASS);
	
	
	m_inputPinActivation_Operation_isReady = factory->createEOperation_in_EContainingClass(m_inputPinActivation_Class, INPUTPINACTIVATION_OPERATION_ISREADY);
	m_inputPinActivation_Operation_receiveOffer = factory->createEOperation_in_EContainingClass(m_inputPinActivation_Class, INPUTPINACTIVATION_OPERATION_RECEIVEOFFER);
	
}

void FUMLPackageImpl::createInstanceValueEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_instanceValueEvaluation_Class = factory->createEClass_in_EPackage(package, INSTANCEVALUEEVALUATION_CLASS);
	
	
	m_instanceValueEvaluation_Operation_evaluate = factory->createEOperation_in_EContainingClass(m_instanceValueEvaluation_Class, INSTANCEVALUEEVALUATION_OPERATION_EVALUATE);
	
}

void FUMLPackageImpl::createIntegerValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_integerValue_Class = factory->createEClass_in_EPackage(package, INTEGERVALUE_CLASS);
	m_integerValue_Attribute_value = factory->createEAttribute_in_EContainingClass(m_integerValue_Class, INTEGERVALUE_ATTRIBUTE_VALUE);
	
	
	m_integerValue_Operation_equals_Value = factory->createEOperation_in_EContainingClass(m_integerValue_Class, INTEGERVALUE_OPERATION_EQUALS_VALUE);
	m_integerValue_Operation_specify = factory->createEOperation_in_EContainingClass(m_integerValue_Class, INTEGERVALUE_OPERATION_SPECIFY);
	m_integerValue_Operation_toString = factory->createEOperation_in_EContainingClass(m_integerValue_Class, INTEGERVALUE_OPERATION_TOSTRING);
	
}

void FUMLPackageImpl::createInvocationActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_invocationActionActivation_Class = factory->createEClass_in_EPackage(package, INVOCATIONACTIONACTIVATION_CLASS);
	
	
	
}

void FUMLPackageImpl::createInvocationEventOccurrenceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_invocationEventOccurrence_Class = factory->createEClass_in_EPackage(package, INVOCATIONEVENTOCCURRENCE_CLASS);
	
	m_invocationEventOccurrence_Attribute_execution = factory->createEReference_in_EContainingClass(m_invocationEventOccurrence_Class, INVOCATIONEVENTOCCURRENCE_ATTRIBUTE_EXECUTION);
	
	m_invocationEventOccurrence_Operation_getParameterValues = factory->createEOperation_in_EContainingClass(m_invocationEventOccurrence_Class, INVOCATIONEVENTOCCURRENCE_OPERATION_GETPARAMETERVALUES);
	m_invocationEventOccurrence_Operation_match_Trigger = factory->createEOperation_in_EContainingClass(m_invocationEventOccurrence_Class, INVOCATIONEVENTOCCURRENCE_OPERATION_MATCH_TRIGGER);
	
}

void FUMLPackageImpl::createJoinNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_joinNodeActivation_Class = factory->createEClass_in_EPackage(package, JOINNODEACTIVATION_CLASS);
	
	
	m_joinNodeActivation_Operation_fire_Token = factory->createEOperation_in_EContainingClass(m_joinNodeActivation_Class, JOINNODEACTIVATION_OPERATION_FIRE_TOKEN);
	m_joinNodeActivation_Operation_isReady = factory->createEOperation_in_EContainingClass(m_joinNodeActivation_Class, JOINNODEACTIVATION_OPERATION_ISREADY);
	
}

void FUMLPackageImpl::createLinkContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_link_Class = factory->createEClass_in_EPackage(package, LINK_CLASS);
	
	m_link_Attribute_type = factory->createEReference_in_EContainingClass(m_link_Class, LINK_ATTRIBUTE_TYPE);
	
	m_link_Operation_addTo_Locus = factory->createEOperation_in_EContainingClass(m_link_Class, LINK_OPERATION_ADDTO_LOCUS);
	m_link_Operation_getOtherFeatureValues_ExtensionalValue_Property = factory->createEOperation_in_EContainingClass(m_link_Class, LINK_OPERATION_GETOTHERFEATUREVALUES_EXTENSIONALVALUE_PROPERTY);
	m_link_Operation_getTypes = factory->createEOperation_in_EContainingClass(m_link_Class, LINK_OPERATION_GETTYPES);
	m_link_Operation_isMatchingLink_ExtensionalValue_Property = factory->createEOperation_in_EContainingClass(m_link_Class, LINK_OPERATION_ISMATCHINGLINK_EXTENSIONALVALUE_PROPERTY);
	
}

void FUMLPackageImpl::createLinkActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_linkActionActivation_Class = factory->createEClass_in_EPackage(package, LINKACTIONACTIVATION_CLASS);
	
	
	m_linkActionActivation_Operation_endMatchesEndData_Link_LinkEndData = factory->createEOperation_in_EContainingClass(m_linkActionActivation_Class, LINKACTIONACTIVATION_OPERATION_ENDMATCHESENDDATA_LINK_LINKENDDATA);
	m_linkActionActivation_Operation_getAssociation = factory->createEOperation_in_EContainingClass(m_linkActionActivation_Class, LINKACTIONACTIVATION_OPERATION_GETASSOCIATION);
	m_linkActionActivation_Operation_linkMatchesEndData_Link_LinkEndData = factory->createEOperation_in_EContainingClass(m_linkActionActivation_Class, LINKACTIONACTIVATION_OPERATION_LINKMATCHESENDDATA_LINK_LINKENDDATA);
	
}

void FUMLPackageImpl::createLiteralBooleanEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalBooleanEvaluation_Class = factory->createEClass_in_EPackage(package, LITERALBOOLEANEVALUATION_CLASS);
	
	
	m_literalBooleanEvaluation_Operation_evaluate = factory->createEOperation_in_EContainingClass(m_literalBooleanEvaluation_Class, LITERALBOOLEANEVALUATION_OPERATION_EVALUATE);
	
}

void FUMLPackageImpl::createLiteralEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalEvaluation_Class = factory->createEClass_in_EPackage(package, LITERALEVALUATION_CLASS);
	
	
	m_literalEvaluation_Operation_getType_EString = factory->createEOperation_in_EContainingClass(m_literalEvaluation_Class, LITERALEVALUATION_OPERATION_GETTYPE_ESTRING);
	
}

void FUMLPackageImpl::createLiteralIntegerEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalIntegerEvaluation_Class = factory->createEClass_in_EPackage(package, LITERALINTEGEREVALUATION_CLASS);
	
	
	m_literalIntegerEvaluation_Operation_evaluate = factory->createEOperation_in_EContainingClass(m_literalIntegerEvaluation_Class, LITERALINTEGEREVALUATION_OPERATION_EVALUATE);
	
}

void FUMLPackageImpl::createLiteralNullEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalNullEvaluation_Class = factory->createEClass_in_EPackage(package, LITERALNULLEVALUATION_CLASS);
	
	
	m_literalNullEvaluation_Operation_evaluate = factory->createEOperation_in_EContainingClass(m_literalNullEvaluation_Class, LITERALNULLEVALUATION_OPERATION_EVALUATE);
	
}

void FUMLPackageImpl::createLiteralRealEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalRealEvaluation_Class = factory->createEClass_in_EPackage(package, LITERALREALEVALUATION_CLASS);
	
	
	m_literalRealEvaluation_Operation_evaluate = factory->createEOperation_in_EContainingClass(m_literalRealEvaluation_Class, LITERALREALEVALUATION_OPERATION_EVALUATE);
	
}

void FUMLPackageImpl::createLiteralStringEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalStringEvaluation_Class = factory->createEClass_in_EPackage(package, LITERALSTRINGEVALUATION_CLASS);
	
	
	m_literalStringEvaluation_Operation_evaluate = factory->createEOperation_in_EContainingClass(m_literalStringEvaluation_Class, LITERALSTRINGEVALUATION_OPERATION_EVALUATE);
	
}

void FUMLPackageImpl::createLiteralUnlimitedNaturalEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalUnlimitedNaturalEvaluation_Class = factory->createEClass_in_EPackage(package, LITERALUNLIMITEDNATURALEVALUATION_CLASS);
	
	
	m_literalUnlimitedNaturalEvaluation_Operation_evaluate = factory->createEOperation_in_EContainingClass(m_literalUnlimitedNaturalEvaluation_Class, LITERALUNLIMITEDNATURALEVALUATION_OPERATION_EVALUATE);
	
}

void FUMLPackageImpl::createLocusContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_locus_Class = factory->createEClass_in_EPackage(package, LOCUS_CLASS);
	
	m_locus_Attribute_executor = factory->createEReference_in_EContainingClass(m_locus_Class, LOCUS_ATTRIBUTE_EXECUTOR);
	m_locus_Attribute_extensionalValues = factory->createEReference_in_EContainingClass(m_locus_Class, LOCUS_ATTRIBUTE_EXTENSIONALVALUES);
	m_locus_Attribute_factory = factory->createEReference_in_EContainingClass(m_locus_Class, LOCUS_ATTRIBUTE_FACTORY);
	
	m_locus_Operation_add_ExtensionalValue = factory->createEOperation_in_EContainingClass(m_locus_Class, LOCUS_OPERATION_ADD_EXTENSIONALVALUE);
	m_locus_Operation_assignExecutor_Executor = factory->createEOperation_in_EContainingClass(m_locus_Class, LOCUS_OPERATION_ASSIGNEXECUTOR_EXECUTOR);
	m_locus_Operation_assignFactory_ExecutionFactory = factory->createEOperation_in_EContainingClass(m_locus_Class, LOCUS_OPERATION_ASSIGNFACTORY_EXECUTIONFACTORY);
	m_locus_Operation_conforms_Classifier_Classifier = factory->createEOperation_in_EContainingClass(m_locus_Class, LOCUS_OPERATION_CONFORMS_CLASSIFIER_CLASSIFIER);
	m_locus_Operation_instantiate_Class = factory->createEOperation_in_EContainingClass(m_locus_Class, LOCUS_OPERATION_INSTANTIATE_CLASS);
	m_locus_Operation_remove_ExtensionalValue = factory->createEOperation_in_EContainingClass(m_locus_Class, LOCUS_OPERATION_REMOVE_EXTENSIONALVALUE);
	m_locus_Operation_retrieveExtent_Classifier = factory->createEOperation_in_EContainingClass(m_locus_Class, LOCUS_OPERATION_RETRIEVEEXTENT_CLASSIFIER);
	
}

void FUMLPackageImpl::createLoopNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_loopNodeActivation_Class = factory->createEClass_in_EPackage(package, LOOPNODEACTIVATION_CLASS);
	
	m_loopNodeActivation_Attribute_bodyOutputLists = factory->createEReference_in_EContainingClass(m_loopNodeActivation_Class, LOOPNODEACTIVATION_ATTRIBUTE_BODYOUTPUTLISTS);
	
	m_loopNodeActivation_Operation_makeLoopVariableList = factory->createEOperation_in_EContainingClass(m_loopNodeActivation_Class, LOOPNODEACTIVATION_OPERATION_MAKELOOPVARIABLELIST);
	m_loopNodeActivation_Operation_runBody = factory->createEOperation_in_EContainingClass(m_loopNodeActivation_Class, LOOPNODEACTIVATION_OPERATION_RUNBODY);
	m_loopNodeActivation_Operation_runLoopVariables = factory->createEOperation_in_EContainingClass(m_loopNodeActivation_Class, LOOPNODEACTIVATION_OPERATION_RUNLOOPVARIABLES);
	m_loopNodeActivation_Operation_runTest = factory->createEOperation_in_EContainingClass(m_loopNodeActivation_Class, LOOPNODEACTIVATION_OPERATION_RUNTEST);
	
}

void FUMLPackageImpl::createMergeNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_mergeNodeActivation_Class = factory->createEClass_in_EPackage(package, MERGENODEACTIVATION_CLASS);
	
	
	
}

void FUMLPackageImpl::createObjectContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_object_Class = factory->createEClass_in_EPackage(package, OBJECT_CLASS);
	
	m_object_Attribute_objectActivation = factory->createEReference_in_EContainingClass(m_object_Class, OBJECT_ATTRIBUTE_OBJECTACTIVATION);
	m_object_Attribute_types = factory->createEReference_in_EContainingClass(m_object_Class, OBJECT_ATTRIBUTE_TYPES);
	
	m_object_Operation__register_EventAccepter = factory->createEOperation_in_EContainingClass(m_object_Class, OBJECT_OPERATION__REGISTER_EVENTACCEPTER);
	m_object_Operation_destroy = factory->createEOperation_in_EContainingClass(m_object_Class, OBJECT_OPERATION_DESTROY);
	m_object_Operation_dispatch_Operation = factory->createEOperation_in_EContainingClass(m_object_Class, OBJECT_OPERATION_DISPATCH_OPERATION);
	m_object_Operation_new_ = factory->createEOperation_in_EContainingClass(m_object_Class, OBJECT_OPERATION_NEW_);
	m_object_Operation_send_SignalInstance = factory->createEOperation_in_EContainingClass(m_object_Class, OBJECT_OPERATION_SEND_SIGNALINSTANCE);
	m_object_Operation_send_EventOccurrence = factory->createEOperation_in_EContainingClass(m_object_Class, OBJECT_OPERATION_SEND_EVENTOCCURRENCE);
	m_object_Operation_startBehavior_Class_ParameterValue = factory->createEOperation_in_EContainingClass(m_object_Class, OBJECT_OPERATION_STARTBEHAVIOR_CLASS_PARAMETERVALUE);
	m_object_Operation_unregister_EventAccepter = factory->createEOperation_in_EContainingClass(m_object_Class, OBJECT_OPERATION_UNREGISTER_EVENTACCEPTER);
	
}

void FUMLPackageImpl::createObjectActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_objectActivation_Class = factory->createEClass_in_EPackage(package, OBJECTACTIVATION_CLASS);
	
	m_objectActivation_Attribute_classifierBehaviorExecutions = factory->createEReference_in_EContainingClass(m_objectActivation_Class, OBJECTACTIVATION_ATTRIBUTE_CLASSIFIERBEHAVIOREXECUTIONS);
	m_objectActivation_Attribute_eventPool = factory->createEReference_in_EContainingClass(m_objectActivation_Class, OBJECTACTIVATION_ATTRIBUTE_EVENTPOOL);
	m_objectActivation_Attribute_object = factory->createEReference_in_EContainingClass(m_objectActivation_Class, OBJECTACTIVATION_ATTRIBUTE_OBJECT);
	m_objectActivation_Attribute_waitingEventAccepters = factory->createEReference_in_EContainingClass(m_objectActivation_Class, OBJECTACTIVATION_ATTRIBUTE_WAITINGEVENTACCEPTERS);
	
	m_objectActivation_Operation__register_EventAccepter = factory->createEOperation_in_EContainingClass(m_objectActivation_Class, OBJECTACTIVATION_OPERATION__REGISTER_EVENTACCEPTER);
	m_objectActivation_Operation__send_EJavaObject = factory->createEOperation_in_EContainingClass(m_objectActivation_Class, OBJECTACTIVATION_OPERATION__SEND_EJAVAOBJECT);
	m_objectActivation_Operation__startObjectBehavior = factory->createEOperation_in_EContainingClass(m_objectActivation_Class, OBJECTACTIVATION_OPERATION__STARTOBJECTBEHAVIOR);
	m_objectActivation_Operation_dispatchNextEvent = factory->createEOperation_in_EContainingClass(m_objectActivation_Class, OBJECTACTIVATION_OPERATION_DISPATCHNEXTEVENT);
	m_objectActivation_Operation_retrieveNextEvent = factory->createEOperation_in_EContainingClass(m_objectActivation_Class, OBJECTACTIVATION_OPERATION_RETRIEVENEXTEVENT);
	m_objectActivation_Operation_send_SignalInstance = factory->createEOperation_in_EContainingClass(m_objectActivation_Class, OBJECTACTIVATION_OPERATION_SEND_SIGNALINSTANCE);
	m_objectActivation_Operation_startBehavior_Class_ParameterValue = factory->createEOperation_in_EContainingClass(m_objectActivation_Class, OBJECTACTIVATION_OPERATION_STARTBEHAVIOR_CLASS_PARAMETERVALUE);
	m_objectActivation_Operation_stop = factory->createEOperation_in_EContainingClass(m_objectActivation_Class, OBJECTACTIVATION_OPERATION_STOP);
	m_objectActivation_Operation_unregister_EventAccepter = factory->createEOperation_in_EContainingClass(m_objectActivation_Class, OBJECTACTIVATION_OPERATION_UNREGISTER_EVENTACCEPTER);
	
}

void FUMLPackageImpl::createObjectNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_objectNodeActivation_Class = factory->createEClass_in_EPackage(package, OBJECTNODEACTIVATION_CLASS);
	m_objectNodeActivation_Attribute_offeredTokenCount = factory->createEAttribute_in_EContainingClass(m_objectNodeActivation_Class, OBJECTNODEACTIVATION_ATTRIBUTE_OFFEREDTOKENCOUNT);
	
	
	m_objectNodeActivation_Operation_addToken_Token = factory->createEOperation_in_EContainingClass(m_objectNodeActivation_Class, OBJECTNODEACTIVATION_OPERATION_ADDTOKEN_TOKEN);
	m_objectNodeActivation_Operation_clearTokens = factory->createEOperation_in_EContainingClass(m_objectNodeActivation_Class, OBJECTNODEACTIVATION_OPERATION_CLEARTOKENS);
	m_objectNodeActivation_Operation_countOfferedValues = factory->createEOperation_in_EContainingClass(m_objectNodeActivation_Class, OBJECTNODEACTIVATION_OPERATION_COUNTOFFEREDVALUES);
	m_objectNodeActivation_Operation_countUnofferedTokens = factory->createEOperation_in_EContainingClass(m_objectNodeActivation_Class, OBJECTNODEACTIVATION_OPERATION_COUNTUNOFFEREDTOKENS);
	m_objectNodeActivation_Operation_getUnofferedTokens = factory->createEOperation_in_EContainingClass(m_objectNodeActivation_Class, OBJECTNODEACTIVATION_OPERATION_GETUNOFFEREDTOKENS);
	m_objectNodeActivation_Operation_removeToken_Token = factory->createEOperation_in_EContainingClass(m_objectNodeActivation_Class, OBJECTNODEACTIVATION_OPERATION_REMOVETOKEN_TOKEN);
	m_objectNodeActivation_Operation_run = factory->createEOperation_in_EContainingClass(m_objectNodeActivation_Class, OBJECTNODEACTIVATION_OPERATION_RUN);
	m_objectNodeActivation_Operation_sendOffers_Token = factory->createEOperation_in_EContainingClass(m_objectNodeActivation_Class, OBJECTNODEACTIVATION_OPERATION_SENDOFFERS_TOKEN);
	m_objectNodeActivation_Operation_sendUnofferedTokens = factory->createEOperation_in_EContainingClass(m_objectNodeActivation_Class, OBJECTNODEACTIVATION_OPERATION_SENDUNOFFEREDTOKENS);
	m_objectNodeActivation_Operation_takeUnofferedTokens = factory->createEOperation_in_EContainingClass(m_objectNodeActivation_Class, OBJECTNODEACTIVATION_OPERATION_TAKEUNOFFEREDTOKENS);
	m_objectNodeActivation_Operation_terminate = factory->createEOperation_in_EContainingClass(m_objectNodeActivation_Class, OBJECTNODEACTIVATION_OPERATION_TERMINATE);
	
}

void FUMLPackageImpl::createObjectTokenContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_objectToken_Class = factory->createEClass_in_EPackage(package, OBJECTTOKEN_CLASS);
	
	m_objectToken_Attribute_value = factory->createEReference_in_EContainingClass(m_objectToken_Class, OBJECTTOKEN_ATTRIBUTE_VALUE);
	
	m_objectToken_Operation_equals_Token = factory->createEOperation_in_EContainingClass(m_objectToken_Class, OBJECTTOKEN_OPERATION_EQUALS_TOKEN);
	m_objectToken_Operation_isControl = factory->createEOperation_in_EContainingClass(m_objectToken_Class, OBJECTTOKEN_OPERATION_ISCONTROL);
	
}

void FUMLPackageImpl::createOfferContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_offer_Class = factory->createEClass_in_EPackage(package, OFFER_CLASS);
	
	m_offer_Attribute_offeredTokens = factory->createEReference_in_EContainingClass(m_offer_Class, OFFER_ATTRIBUTE_OFFEREDTOKENS);
	
	m_offer_Operation_countOfferedVales = factory->createEOperation_in_EContainingClass(m_offer_Class, OFFER_OPERATION_COUNTOFFEREDVALES);
	m_offer_Operation_hasTokens = factory->createEOperation_in_EContainingClass(m_offer_Class, OFFER_OPERATION_HASTOKENS);
	m_offer_Operation_removeOfferedValues_EInt = factory->createEOperation_in_EContainingClass(m_offer_Class, OFFER_OPERATION_REMOVEOFFEREDVALUES_EINT);
	m_offer_Operation_removeWithdrawnTokens = factory->createEOperation_in_EContainingClass(m_offer_Class, OFFER_OPERATION_REMOVEWITHDRAWNTOKENS);
	m_offer_Operation_retrieveOfferedTokens = factory->createEOperation_in_EContainingClass(m_offer_Class, OFFER_OPERATION_RETRIEVEOFFEREDTOKENS);
	
}

void FUMLPackageImpl::createOpaqueBehaviorExecutionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_opaqueBehaviorExecution_Class = factory->createEClass_in_EPackage(package, OPAQUEBEHAVIOREXECUTION_CLASS);
	
	
	m_opaqueBehaviorExecution_Operation_doBody_ParameterValue_ParameterValue = factory->createEOperation_in_EContainingClass(m_opaqueBehaviorExecution_Class, OPAQUEBEHAVIOREXECUTION_OPERATION_DOBODY_PARAMETERVALUE_PARAMETERVALUE);
	m_opaqueBehaviorExecution_Operation_execute = factory->createEOperation_in_EContainingClass(m_opaqueBehaviorExecution_Class, OPAQUEBEHAVIOREXECUTION_OPERATION_EXECUTE);
	
}

void FUMLPackageImpl::createOutputPinActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_outputPinActivation_Class = factory->createEClass_in_EPackage(package, OUTPUTPINACTIVATION_CLASS);
	
	
	
}

void FUMLPackageImpl::createParameterValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_parameterValue_Class = factory->createEClass_in_EPackage(package, PARAMETERVALUE_CLASS);
	
	m_parameterValue_Attribute_parameter = factory->createEReference_in_EContainingClass(m_parameterValue_Class, PARAMETERVALUE_ATTRIBUTE_PARAMETER);
	m_parameterValue_Attribute_values = factory->createEReference_in_EContainingClass(m_parameterValue_Class, PARAMETERVALUE_ATTRIBUTE_VALUES);
	
	
}

void FUMLPackageImpl::createPinActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_pinActivation_Class = factory->createEClass_in_EPackage(package, PINACTIVATION_CLASS);
	
	m_pinActivation_Attribute_actionActivation = factory->createEReference_in_EContainingClass(m_pinActivation_Class, PINACTIVATION_ATTRIBUTE_ACTIONACTIVATION);
	
	m_pinActivation_Operation_fire_Token = factory->createEOperation_in_EContainingClass(m_pinActivation_Class, PINACTIVATION_OPERATION_FIRE_TOKEN);
	m_pinActivation_Operation_takeOfferedTokens = factory->createEOperation_in_EContainingClass(m_pinActivation_Class, PINACTIVATION_OPERATION_TAKEOFFEREDTOKENS);
	
}

void FUMLPackageImpl::createPrimitiveValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_primitiveValue_Class = factory->createEClass_in_EPackage(package, PRIMITIVEVALUE_CLASS);
	
	m_primitiveValue_Attribute_type = factory->createEReference_in_EContainingClass(m_primitiveValue_Class, PRIMITIVEVALUE_ATTRIBUTE_TYPE);
	
	m_primitiveValue_Operation_getTypes = factory->createEOperation_in_EContainingClass(m_primitiveValue_Class, PRIMITIVEVALUE_OPERATION_GETTYPES);
	
}

void FUMLPackageImpl::createReadExtentActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_readExtentActionActivation_Class = factory->createEClass_in_EPackage(package, READEXTENTACTIONACTIVATION_CLASS);
	
	
	
}

void FUMLPackageImpl::createReadIsClassifiedObjectActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_readIsClassifiedObjectActionActivation_Class = factory->createEClass_in_EPackage(package, READISCLASSIFIEDOBJECTACTIONACTIVATION_CLASS);
	
	
	m_readIsClassifiedObjectActionActivation_Operation_checkAllParents_Classifier_Classifier = factory->createEOperation_in_EContainingClass(m_readIsClassifiedObjectActionActivation_Class, READISCLASSIFIEDOBJECTACTIONACTIVATION_OPERATION_CHECKALLPARENTS_CLASSIFIER_CLASSIFIER);
	
}

void FUMLPackageImpl::createReadLinkActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_readLinkActionActivation_Class = factory->createEClass_in_EPackage(package, READLINKACTIONACTIVATION_CLASS);
	
	
	
}

void FUMLPackageImpl::createReadSelfActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_readSelfActionActivation_Class = factory->createEClass_in_EPackage(package, READSELFACTIONACTIVATION_CLASS);
	
	
	m_readSelfActionActivation_Operation_doAction = factory->createEOperation_in_EContainingClass(m_readSelfActionActivation_Class, READSELFACTIONACTIVATION_OPERATION_DOACTION);
	
}

void FUMLPackageImpl::createReadStructuralFeatureActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_readStructuralFeatureActionActivation_Class = factory->createEClass_in_EPackage(package, READSTRUCTURALFEATUREACTIONACTIVATION_CLASS);
	
	
	m_readStructuralFeatureActionActivation_Operation_doAction = factory->createEOperation_in_EContainingClass(m_readStructuralFeatureActionActivation_Class, READSTRUCTURALFEATUREACTIONACTIVATION_OPERATION_DOACTION);
	
}

void FUMLPackageImpl::createRealValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_realValue_Class = factory->createEClass_in_EPackage(package, REALVALUE_CLASS);
	m_realValue_Attribute_value = factory->createEAttribute_in_EContainingClass(m_realValue_Class, REALVALUE_ATTRIBUTE_VALUE);
	
	
	m_realValue_Operation_equals_Value = factory->createEOperation_in_EContainingClass(m_realValue_Class, REALVALUE_OPERATION_EQUALS_VALUE);
	m_realValue_Operation_specify = factory->createEOperation_in_EContainingClass(m_realValue_Class, REALVALUE_OPERATION_SPECIFY);
	m_realValue_Operation_toString = factory->createEOperation_in_EContainingClass(m_realValue_Class, REALVALUE_OPERATION_TOSTRING);
	
}

void FUMLPackageImpl::createReclassifyObjectActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_reclassifyObjectActionActivation_Class = factory->createEClass_in_EPackage(package, RECLASSIFYOBJECTACTIONACTIVATION_CLASS);
	
	
	
}

void FUMLPackageImpl::createRedefinitionBasedDispatchStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_redefinitionBasedDispatchStrategy_Class = factory->createEClass_in_EPackage(package, REDEFINITIONBASEDDISPATCHSTRATEGY_CLASS);
	
	
	m_redefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation = factory->createEOperation_in_EContainingClass(m_redefinitionBasedDispatchStrategy_Class, REDEFINITIONBASEDDISPATCHSTRATEGY_OPERATION_OPERATIONSMATCH_OPERATION_OPERATION);
	m_redefinitionBasedDispatchStrategy_Operation_retrieveMethod_Object_Operation = factory->createEOperation_in_EContainingClass(m_redefinitionBasedDispatchStrategy_Class, REDEFINITIONBASEDDISPATCHSTRATEGY_OPERATION_RETRIEVEMETHOD_OBJECT_OPERATION);
	
}

void FUMLPackageImpl::createReduceActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_reduceActionActivation_Class = factory->createEClass_in_EPackage(package, REDUCEACTIONACTIVATION_CLASS);
	
	m_reduceActionActivation_Attribute_currentExecution = factory->createEReference_in_EContainingClass(m_reduceActionActivation_Class, REDUCEACTIONACTIVATION_ATTRIBUTE_CURRENTEXECUTION);
	
	
}

void FUMLPackageImpl::createReferenceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_reference_Class = factory->createEClass_in_EPackage(package, REFERENCE_CLASS);
	
	m_reference_Attribute_referent = factory->createEReference_in_EContainingClass(m_reference_Class, REFERENCE_ATTRIBUTE_REFERENT);
	
	m_reference_Operation_assignFeatureValue_StructuralFeature_EInt = factory->createEOperation_in_EContainingClass(m_reference_Class, REFERENCE_OPERATION_ASSIGNFEATUREVALUE_STRUCTURALFEATURE_EINT);
	m_reference_Operation_destroy = factory->createEOperation_in_EContainingClass(m_reference_Class, REFERENCE_OPERATION_DESTROY);
	m_reference_Operation_dispatch_Operation = factory->createEOperation_in_EContainingClass(m_reference_Class, REFERENCE_OPERATION_DISPATCH_OPERATION);
	m_reference_Operation_equals_Value = factory->createEOperation_in_EContainingClass(m_reference_Class, REFERENCE_OPERATION_EQUALS_VALUE);
	m_reference_Operation_getTypes = factory->createEOperation_in_EContainingClass(m_reference_Class, REFERENCE_OPERATION_GETTYPES);
	m_reference_Operation_getValues_StructuralFeature_FeatureValue = factory->createEOperation_in_EContainingClass(m_reference_Class, REFERENCE_OPERATION_GETVALUES_STRUCTURALFEATURE_FEATUREVALUE);
	m_reference_Operation_new_ = factory->createEOperation_in_EContainingClass(m_reference_Class, REFERENCE_OPERATION_NEW_);
	m_reference_Operation_removeValue_StructuralFeature_Value = factory->createEOperation_in_EContainingClass(m_reference_Class, REFERENCE_OPERATION_REMOVEVALUE_STRUCTURALFEATURE_VALUE);
	m_reference_Operation_retrieveFeatureValue_StructuralFeature = factory->createEOperation_in_EContainingClass(m_reference_Class, REFERENCE_OPERATION_RETRIEVEFEATUREVALUE_STRUCTURALFEATURE);
	m_reference_Operation_retrieveFeatureValues = factory->createEOperation_in_EContainingClass(m_reference_Class, REFERENCE_OPERATION_RETRIEVEFEATUREVALUES);
	m_reference_Operation_send_SignalInstance = factory->createEOperation_in_EContainingClass(m_reference_Class, REFERENCE_OPERATION_SEND_SIGNALINSTANCE);
	m_reference_Operation_send_EventOccurrence = factory->createEOperation_in_EContainingClass(m_reference_Class, REFERENCE_OPERATION_SEND_EVENTOCCURRENCE);
	m_reference_Operation_setFeatureValue_StructuralFeature_EInt = factory->createEOperation_in_EContainingClass(m_reference_Class, REFERENCE_OPERATION_SETFEATUREVALUE_STRUCTURALFEATURE_EINT);
	m_reference_Operation_startBehavior_Class_ParameterValue = factory->createEOperation_in_EContainingClass(m_reference_Class, REFERENCE_OPERATION_STARTBEHAVIOR_CLASS_PARAMETERVALUE);
	m_reference_Operation_toString = factory->createEOperation_in_EContainingClass(m_reference_Class, REFERENCE_OPERATION_TOSTRING);
	
}

void FUMLPackageImpl::createRemoveStructuralFeatureValueActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_removeStructuralFeatureValueActivation_Class = factory->createEClass_in_EPackage(package, REMOVESTRUCTURALFEATUREVALUEACTIVATION_CLASS);
	
	
	m_removeStructuralFeatureValueActivation_Operation_doAction = factory->createEOperation_in_EContainingClass(m_removeStructuralFeatureValueActivation_Class, REMOVESTRUCTURALFEATUREVALUEACTIVATION_OPERATION_DOACTION);
	
}

void FUMLPackageImpl::createReplyActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_replyActionActivation_Class = factory->createEClass_in_EPackage(package, REPLYACTIONACTIVATION_CLASS);
	
	
	m_replyActionActivation_Operation_doAction = factory->createEOperation_in_EContainingClass(m_replyActionActivation_Class, REPLYACTIONACTIVATION_OPERATION_DOACTION);
	
}

void FUMLPackageImpl::createReturnInformationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_returnInformation_Class = factory->createEClass_in_EPackage(package, RETURNINFORMATION_CLASS);
	
	m_returnInformation_Attribute_callEventOccurrence = factory->createEReference_in_EContainingClass(m_returnInformation_Class, RETURNINFORMATION_ATTRIBUTE_CALLEVENTOCCURRENCE);
	
	m_returnInformation_Operation_copy = factory->createEOperation_in_EContainingClass(m_returnInformation_Class, RETURNINFORMATION_OPERATION_COPY);
	m_returnInformation_Operation_equals_Value = factory->createEOperation_in_EContainingClass(m_returnInformation_Class, RETURNINFORMATION_OPERATION_EQUALS_VALUE);
	m_returnInformation_Operation_getOperation = factory->createEOperation_in_EContainingClass(m_returnInformation_Class, RETURNINFORMATION_OPERATION_GETOPERATION);
	m_returnInformation_Operation_getTypes = factory->createEOperation_in_EContainingClass(m_returnInformation_Class, RETURNINFORMATION_OPERATION_GETTYPES);
	m_returnInformation_Operation_new_ = factory->createEOperation_in_EContainingClass(m_returnInformation_Class, RETURNINFORMATION_OPERATION_NEW_);
	m_returnInformation_Operation_reply_ParameterValue = factory->createEOperation_in_EContainingClass(m_returnInformation_Class, RETURNINFORMATION_OPERATION_REPLY_PARAMETERVALUE);
	m_returnInformation_Operation_specify = factory->createEOperation_in_EContainingClass(m_returnInformation_Class, RETURNINFORMATION_OPERATION_SPECIFY);
	m_returnInformation_Operation_toString = factory->createEOperation_in_EContainingClass(m_returnInformation_Class, RETURNINFORMATION_OPERATION_TOSTRING);
	
}

void FUMLPackageImpl::createSemanticStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_semanticStrategy_Class = factory->createEClass_in_EPackage(package, SEMANTICSTRATEGY_CLASS);
	
	
	m_semanticStrategy_Operation_getName = factory->createEOperation_in_EContainingClass(m_semanticStrategy_Class, SEMANTICSTRATEGY_OPERATION_GETNAME);
	
}

void FUMLPackageImpl::createSemanticVisitorContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_semanticVisitor_Class = factory->createEClass_in_EPackage(package, SEMANTICVISITOR_CLASS);
	
	
	m_semanticVisitor_Operation__beginIsolation = factory->createEOperation_in_EContainingClass(m_semanticVisitor_Class, SEMANTICVISITOR_OPERATION__BEGINISOLATION);
	m_semanticVisitor_Operation__endIsolation = factory->createEOperation_in_EContainingClass(m_semanticVisitor_Class, SEMANTICVISITOR_OPERATION__ENDISOLATION);
	
}

void FUMLPackageImpl::createSendSignalActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_sendSignalActionActivation_Class = factory->createEClass_in_EPackage(package, SENDSIGNALACTIONACTIVATION_CLASS);
	
	
	m_sendSignalActionActivation_Operation_doAction = factory->createEOperation_in_EContainingClass(m_sendSignalActionActivation_Class, SENDSIGNALACTIONACTIVATION_OPERATION_DOACTION);
	
}

void FUMLPackageImpl::createSignalEventOccurrenceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_signalEventOccurrence_Class = factory->createEClass_in_EPackage(package, SIGNALEVENTOCCURRENCE_CLASS);
	
	m_signalEventOccurrence_Attribute_signalInstance = factory->createEReference_in_EContainingClass(m_signalEventOccurrence_Class, SIGNALEVENTOCCURRENCE_ATTRIBUTE_SIGNALINSTANCE);
	
	m_signalEventOccurrence_Operation_getParameterValues = factory->createEOperation_in_EContainingClass(m_signalEventOccurrence_Class, SIGNALEVENTOCCURRENCE_OPERATION_GETPARAMETERVALUES);
	m_signalEventOccurrence_Operation_match_Trigger = factory->createEOperation_in_EContainingClass(m_signalEventOccurrence_Class, SIGNALEVENTOCCURRENCE_OPERATION_MATCH_TRIGGER);
	
}

void FUMLPackageImpl::createSignalInstanceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_signalInstance_Class = factory->createEClass_in_EPackage(package, SIGNALINSTANCE_CLASS);
	
	m_signalInstance_Attribute_type = factory->createEReference_in_EContainingClass(m_signalInstance_Class, SIGNALINSTANCE_ATTRIBUTE_TYPE);
	
	
}

void FUMLPackageImpl::createStartClassifierBehaviorActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_startClassifierBehaviorActionActivation_Class = factory->createEClass_in_EPackage(package, STARTCLASSIFIERBEHAVIORACTIONACTIVATION_CLASS);
	
	
	m_startClassifierBehaviorActionActivation_Operation_doAction = factory->createEOperation_in_EContainingClass(m_startClassifierBehaviorActionActivation_Class, STARTCLASSIFIERBEHAVIORACTIONACTIVATION_OPERATION_DOACTION);
	
}

void FUMLPackageImpl::createStartObjectBehaviorActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_startObjectBehaviorActionActivation_Class = factory->createEClass_in_EPackage(package, STARTOBJECTBEHAVIORACTIONACTIVATION_CLASS);
	
	
	m_startObjectBehaviorActionActivation_Operation_doAction = factory->createEOperation_in_EContainingClass(m_startObjectBehaviorActionActivation_Class, STARTOBJECTBEHAVIORACTIONACTIVATION_OPERATION_DOACTION);
	
}

void FUMLPackageImpl::createStringValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_stringValue_Class = factory->createEClass_in_EPackage(package, STRINGVALUE_CLASS);
	m_stringValue_Attribute_value = factory->createEAttribute_in_EContainingClass(m_stringValue_Class, STRINGVALUE_ATTRIBUTE_VALUE);
	
	
	m_stringValue_Operation_equals_Value = factory->createEOperation_in_EContainingClass(m_stringValue_Class, STRINGVALUE_OPERATION_EQUALS_VALUE);
	m_stringValue_Operation_specify = factory->createEOperation_in_EContainingClass(m_stringValue_Class, STRINGVALUE_OPERATION_SPECIFY);
	m_stringValue_Operation_toString = factory->createEOperation_in_EContainingClass(m_stringValue_Class, STRINGVALUE_OPERATION_TOSTRING);
	
}

void FUMLPackageImpl::createStructuralFeatureActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_structuralFeatureActionActivation_Class = factory->createEClass_in_EPackage(package, STRUCTURALFEATUREACTIONACTIVATION_CLASS);
	
	
	m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature = factory->createEOperation_in_EContainingClass(m_structuralFeatureActionActivation_Class, STRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETASSOCIATION_STRUCTURALFEATURE);
	m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_Value = factory->createEOperation_in_EContainingClass(m_structuralFeatureActionActivation_Class, STRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETMATCHINGLINKS_ASSOCIATION_VALUE);
	m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_Value = factory->createEOperation_in_EContainingClass(m_structuralFeatureActionActivation_Class, STRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETMATCHINGLINKSFORENDVALUE_ASSOCIATION_VALUE);
	m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature = factory->createEOperation_in_EContainingClass(m_structuralFeatureActionActivation_Class, STRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETOPPOSITEEND_ASSOCIATION_STRUCTURALFEATURE);
	
}

void FUMLPackageImpl::createStructuredActivityNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_structuredActivityNodeActivation_Class = factory->createEClass_in_EPackage(package, STRUCTUREDACTIVITYNODEACTIVATION_CLASS);
	
	m_structuredActivityNodeActivation_Attribute_activationGroup = factory->createEReference_in_EContainingClass(m_structuredActivityNodeActivation_Class, STRUCTUREDACTIVITYNODEACTIVATION_ATTRIBUTE_ACTIVATIONGROUP);
	
	m_structuredActivityNodeActivation_Operation_completeAction = factory->createEOperation_in_EContainingClass(m_structuredActivityNodeActivation_Class, STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_COMPLETEACTION);
	m_structuredActivityNodeActivation_Operation_createEdgeInstances = factory->createEOperation_in_EContainingClass(m_structuredActivityNodeActivation_Class, STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_CREATEEDGEINSTANCES);
	m_structuredActivityNodeActivation_Operation_createNodeActivations = factory->createEOperation_in_EContainingClass(m_structuredActivityNodeActivation_Class, STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_CREATENODEACTIVATIONS);
	m_structuredActivityNodeActivation_Operation_doAction = factory->createEOperation_in_EContainingClass(m_structuredActivityNodeActivation_Class, STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_DOACTION);
	m_structuredActivityNodeActivation_Operation_doStructuredActivity = factory->createEOperation_in_EContainingClass(m_structuredActivityNodeActivation_Class, STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_DOSTRUCTUREDACTIVITY);
	m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode = factory->createEOperation_in_EContainingClass(m_structuredActivityNodeActivation_Class, STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_GETNODEACTIVATION_ACTIVITYNODE);
	m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin = factory->createEOperation_in_EContainingClass(m_structuredActivityNodeActivation_Class, STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_GETPINVALUES_OUTPUTPIN);
	m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance = factory->createEOperation_in_EContainingClass(m_structuredActivityNodeActivation_Class, STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_ISSOURCEFOR_ACTIVITYEDGEINSTANCE);
	m_structuredActivityNodeActivation_Operation_isSuspended = factory->createEOperation_in_EContainingClass(m_structuredActivityNodeActivation_Class, STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_ISSUSPENDED);
	m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode = factory->createEOperation_in_EContainingClass(m_structuredActivityNodeActivation_Class, STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_MAKEACTIVITYNODELIST_EXECUTABLENODE);
	m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_Value = factory->createEOperation_in_EContainingClass(m_structuredActivityNodeActivation_Class, STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_PUTPINVALUES_OUTPUTPIN_VALUE);
	m_structuredActivityNodeActivation_Operation_resume = factory->createEOperation_in_EContainingClass(m_structuredActivityNodeActivation_Class, STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_RESUME);
	m_structuredActivityNodeActivation_Operation_terminate = factory->createEOperation_in_EContainingClass(m_structuredActivityNodeActivation_Class, STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_TERMINATE);
	m_structuredActivityNodeActivation_Operation_terminateAll = factory->createEOperation_in_EContainingClass(m_structuredActivityNodeActivation_Class, STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_TERMINATEALL);
	
}

void FUMLPackageImpl::createStructuredValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_structuredValue_Class = factory->createEClass_in_EPackage(package, STRUCTUREDVALUE_CLASS);
	
	
	m_structuredValue_Operation_assignFeatureValue_StructuralFeature_EInt = factory->createEOperation_in_EContainingClass(m_structuredValue_Class, STRUCTUREDVALUE_OPERATION_ASSIGNFEATUREVALUE_STRUCTURALFEATURE_EINT);
	m_structuredValue_Operation_createFeatureValues = factory->createEOperation_in_EContainingClass(m_structuredValue_Class, STRUCTUREDVALUE_OPERATION_CREATEFEATUREVALUES);
	m_structuredValue_Operation_getValues_StructuralFeature_FeatureValue = factory->createEOperation_in_EContainingClass(m_structuredValue_Class, STRUCTUREDVALUE_OPERATION_GETVALUES_STRUCTURALFEATURE_FEATUREVALUE);
	m_structuredValue_Operation_removeValue_StructuralFeature_Value = factory->createEOperation_in_EContainingClass(m_structuredValue_Class, STRUCTUREDVALUE_OPERATION_REMOVEVALUE_STRUCTURALFEATURE_VALUE);
	m_structuredValue_Operation_retrieveFeatureValue_StructuralFeature = factory->createEOperation_in_EContainingClass(m_structuredValue_Class, STRUCTUREDVALUE_OPERATION_RETRIEVEFEATUREVALUE_STRUCTURALFEATURE);
	m_structuredValue_Operation_retrieveFeatureValues = factory->createEOperation_in_EContainingClass(m_structuredValue_Class, STRUCTUREDVALUE_OPERATION_RETRIEVEFEATUREVALUES);
	m_structuredValue_Operation_setFeatureValue_StructuralFeature_EInt = factory->createEOperation_in_EContainingClass(m_structuredValue_Class, STRUCTUREDVALUE_OPERATION_SETFEATUREVALUE_STRUCTURALFEATURE_EINT);
	m_structuredValue_Operation_specify = factory->createEOperation_in_EContainingClass(m_structuredValue_Class, STRUCTUREDVALUE_OPERATION_SPECIFY);
	
}

void FUMLPackageImpl::createTestIdentityActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_testIdentityActionActivation_Class = factory->createEClass_in_EPackage(package, TESTIDENTITYACTIONACTIVATION_CLASS);
	
	
	
}

void FUMLPackageImpl::createTokenContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_token_Class = factory->createEClass_in_EPackage(package, TOKEN_CLASS);
	m_token_Attribute_withdrawn = factory->createEAttribute_in_EContainingClass(m_token_Class, TOKEN_ATTRIBUTE_WITHDRAWN);
	
	m_token_Attribute_holder = factory->createEReference_in_EContainingClass(m_token_Class, TOKEN_ATTRIBUTE_HOLDER);
	
	m_token_Operation_equals_Token = factory->createEOperation_in_EContainingClass(m_token_Class, TOKEN_OPERATION_EQUALS_TOKEN);
	m_token_Operation_getValue = factory->createEOperation_in_EContainingClass(m_token_Class, TOKEN_OPERATION_GETVALUE);
	m_token_Operation_isControl = factory->createEOperation_in_EContainingClass(m_token_Class, TOKEN_OPERATION_ISCONTROL);
	m_token_Operation_transfer_ActivityNodeActivation = factory->createEOperation_in_EContainingClass(m_token_Class, TOKEN_OPERATION_TRANSFER_ACTIVITYNODEACTIVATION);
	m_token_Operation_withdraw = factory->createEOperation_in_EContainingClass(m_token_Class, TOKEN_OPERATION_WITHDRAW);
	
}

void FUMLPackageImpl::createTokenSetContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_tokenSet_Class = factory->createEClass_in_EPackage(package, TOKENSET_CLASS);
	
	m_tokenSet_Attribute_tokens = factory->createEReference_in_EContainingClass(m_tokenSet_Class, TOKENSET_ATTRIBUTE_TOKENS);
	
	
}

void FUMLPackageImpl::createUnlimitedNaturalValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_unlimitedNaturalValue_Class = factory->createEClass_in_EPackage(package, UNLIMITEDNATURALVALUE_CLASS);
	m_unlimitedNaturalValue_Attribute_value = factory->createEAttribute_in_EContainingClass(m_unlimitedNaturalValue_Class, UNLIMITEDNATURALVALUE_ATTRIBUTE_VALUE);
	
	
	m_unlimitedNaturalValue_Operation_equals_Value = factory->createEOperation_in_EContainingClass(m_unlimitedNaturalValue_Class, UNLIMITEDNATURALVALUE_OPERATION_EQUALS_VALUE);
	m_unlimitedNaturalValue_Operation_specify = factory->createEOperation_in_EContainingClass(m_unlimitedNaturalValue_Class, UNLIMITEDNATURALVALUE_OPERATION_SPECIFY);
	m_unlimitedNaturalValue_Operation_toString = factory->createEOperation_in_EContainingClass(m_unlimitedNaturalValue_Class, UNLIMITEDNATURALVALUE_OPERATION_TOSTRING);
	
}

void FUMLPackageImpl::createValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_value_Class = factory->createEClass_in_EPackage(package, VALUE_CLASS);
	
	
	m_value_Operation_checkAllParents_Classifier_Classifier = factory->createEOperation_in_EContainingClass(m_value_Class, VALUE_OPERATION_CHECKALLPARENTS_CLASSIFIER_CLASSIFIER);
	m_value_Operation_equals_Value = factory->createEOperation_in_EContainingClass(m_value_Class, VALUE_OPERATION_EQUALS_VALUE);
	m_value_Operation_getTypes = factory->createEOperation_in_EContainingClass(m_value_Class, VALUE_OPERATION_GETTYPES);
	m_value_Operation_hasTypes_Classifier = factory->createEOperation_in_EContainingClass(m_value_Class, VALUE_OPERATION_HASTYPES_CLASSIFIER);
	m_value_Operation_objectId = factory->createEOperation_in_EContainingClass(m_value_Class, VALUE_OPERATION_OBJECTID);
	m_value_Operation_specify = factory->createEOperation_in_EContainingClass(m_value_Class, VALUE_OPERATION_SPECIFY);
	m_value_Operation_toString = factory->createEOperation_in_EContainingClass(m_value_Class, VALUE_OPERATION_TOSTRING);
	
}

void FUMLPackageImpl::createValueSpecificationActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_valueSpecificationActionActivation_Class = factory->createEClass_in_EPackage(package, VALUESPECIFICATIONACTIONACTIVATION_CLASS);
	
	
	m_valueSpecificationActionActivation_Operation_doAction = factory->createEOperation_in_EContainingClass(m_valueSpecificationActionActivation_Class, VALUESPECIFICATIONACTIONACTIVATION_OPERATION_DOACTION);
	
}

void FUMLPackageImpl::createValuesContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_values_Class = factory->createEClass_in_EPackage(package, VALUES_CLASS);
	
	m_values_Attribute_values = factory->createEReference_in_EContainingClass(m_values_Class, VALUES_ATTRIBUTE_VALUES);
	
	
}

void FUMLPackageImpl::createWriteLinkActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_writeLinkActionActivation_Class = factory->createEClass_in_EPackage(package, WRITELINKACTIONACTIVATION_CLASS);
	
	
	
}

void FUMLPackageImpl::createWriteStructuralFeatureActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_writeStructuralFeatureActionActivation_Class = factory->createEClass_in_EPackage(package, WRITESTRUCTURALFEATUREACTIONACTIVATION_CLASS);
	
	
	m_writeStructuralFeatureActionActivation_Operation_position_Value_EInt = factory->createEOperation_in_EContainingClass(m_writeStructuralFeatureActionActivation_Class, WRITESTRUCTURALFEATUREACTIONACTIVATION_OPERATION_POSITION_VALUE_EINT);
	
}
=======
>>>>>>> 6da89415d34eadfee120c931945e66653629f773

void FUMLPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	
}
