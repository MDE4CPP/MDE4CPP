#include "fUML/impl/FUMLPackageImpl.hpp"

//metametamodel classes
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EReference.hpp"

// metametamodel factory
#include "ecore/EcoreFactory.hpp"
//metamodel factory
#include "fUML/FUMLFactory.hpp"

//depending model packages
#include "ecore/EcorePackage.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlPackage.hpp"

using namespace fUML;

bool FUMLPackageImpl::isInited = false;

FUMLPackageImpl::FUMLPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( FUMLFactory::eInstance()));
}

FUMLPackageImpl::~FUMLPackageImpl()
{
}

FUMLPackage* FUMLPackageImpl::create()
{
	if (isInited)
	{
		return FUMLPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    FUMLPackageImpl * metaModelPackage = new FUMLPackageImpl();
	metaModelPackage->createPackageContents();
    return metaModelPackage;
}

void FUMLPackageImpl::init()
{
    // Initialize created meta-data
    initializePackageContents();   
}

void FUMLPackageImpl::createPackageContents()
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;
	struct null_deleter{void operator()(void const *) const { } };

	std::shared_ptr<ecore::EcoreFactory> factory = ecore::EcoreFactory::eInstance();

	createAcceptEventActionActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createAcceptEventActionEventAccepterContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createActionActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createActivityEdgeInstanceContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createActivityExecutionContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createActivityFinalNodeActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createActivityNodeActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createActivityNodeActivationGroupContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createActivityParameterNodeActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createAddStructuralFeatureValueActionActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createBooleanValueContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createCallActionActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createCallBehaviorActionActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createCallOperationActionActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createCentralBufferNodeActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createChoiceStrategyContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createClassifierBehaviorExecutionContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createClassifierBehaviorExecutionActivityContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Content(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createClauseActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createClearAssociationActionActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createClearStructuralFeatureActionActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createCompoundValueContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createConditionalNodeActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createControlNodeActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createControlTokenContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createCreateLinkActionActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createCreateObjectActionActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createDataStoreNodeActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createDataValueContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createDecisionNodeActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createDestroyLinkActionActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createDestroyObjectActionActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createDispatchStrategyContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createEnumerationValueContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createEvaluationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createEventAccepterContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createEventDispatchLoopContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createExecutionContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createExecutionFactoryContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createExecutionFactoryL1Content(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createExecutionFactoryL2Content(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createExecutionFactoryL3Content(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createExecutorContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createExpansionActivationGroupContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createExpansionNodeActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createExpansionRegionActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createExtensionalValueContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createExtensionalValueListContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createFIFOGetNextEventStrategyContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createFeatureValueContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createFirstChoiceStrategyContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createFlowFinalNodeActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createForkNodeActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createForkedTokenContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createGetNextEventStrategyContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createInitialNodeActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createInputPinActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createInstanceValueEvaluationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createIntegerValueContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createInvocationActionActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createJoinNodeActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createLinkContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createLinkActionActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createLiteralBooleanEvaluationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createLiteralEvaluationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createLiteralIntegerEvaluationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createLiteralNullEvaluationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createLiteralRealEvaluationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createLiteralStringEvaluationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createLiteralUnlimitedNaturalEvaluationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createLocusContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createLoopNodeActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createMergeNodeActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createObjectContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createObjectActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createObjectNodeActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createObjectTokenContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createOfferContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createOpaqueBehaviorExecutionContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createOutputPinActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createParameterValueContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createPinActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createPrimitiveValueContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createReadExtentActionActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createReadIsClassifiedObjectActionActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createReadLinkActionActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createReadSelfActionActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createReadStructuralFeatureActionActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createRealValueContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createReclassifyObjectActionActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createRedefinitionBasedDispatchStrategyContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createReduceActionActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createReferenceContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createRemoveStructuralFeatureValueActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createSemanticStrategyContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createSemanticVisitorContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createSendSignalActionActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createSignalInstanceContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createStartClassifierBehaviorActionActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createStartObjectBehaviorActionActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createStringValueContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createStructuralFeatureActionActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createStructuredActivityNodeActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createStructuredValueContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createTestIdentityActionActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createTokenContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createTokenSetContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createUnlimitedNaturalValueContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createValueContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createValueSpecificActionActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createValuesContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createWriteLinkActionActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createWriteStructuralFeatureActionActivationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);

	createPackageEDataTypes(std::shared_ptr<EPackage>(this, null_deleter()), factory);
}

void FUMLPackageImpl::createAcceptEventActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_acceptEventActionActivation_EClass = factory->createEClass_in_EPackage(package, ACCEPTEVENTACTIONACTIVATION_ECLASS);
	m_acceptEventActionActivation_EAttribute_waiting = factory->createEAttribute_in_EContainingClass(m_acceptEventActionActivation_EClass, ACCEPTEVENTACTIONACTIVATION_EATTRIBUTE_WAITING);
	
	m_acceptEventActionActivation_EReference_eventAccepter = factory->createEReference_in_EContainingClass(m_acceptEventActionActivation_EClass, ACCEPTEVENTACTIONACTIVATION_EREFERENCE_EVENTACCEPTER);
	
	m_acceptEventActionActivation_EOperation_accept_SignalInstance = factory->createEOperation_in_EContainingClass(m_acceptEventActionActivation_EClass, ACCEPTEVENTACTIONACTIVATION_EOPERATION_ACCEPT_SIGNALINSTANCE);
	m_acceptEventActionActivation_EOperation_match_SignalInstance = factory->createEOperation_in_EContainingClass(m_acceptEventActionActivation_EClass, ACCEPTEVENTACTIONACTIVATION_EOPERATION_MATCH_SIGNALINSTANCE);
	
}

void FUMLPackageImpl::createAcceptEventActionEventAccepterContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_acceptEventActionEventAccepter_EClass = factory->createEClass_in_EPackage(package, ACCEPTEVENTACTIONEVENTACCEPTER_ECLASS);
	
	m_acceptEventActionEventAccepter_EReference_actionActivation = factory->createEReference_in_EContainingClass(m_acceptEventActionEventAccepter_EClass, ACCEPTEVENTACTIONEVENTACCEPTER_EREFERENCE_ACTIONACTIVATION);
	
	
}

void FUMLPackageImpl::createActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_actionActivation_EClass = factory->createEClass_in_EPackage(package, ACTIONACTIVATION_ECLASS);
	m_actionActivation_EAttribute_firing = factory->createEAttribute_in_EContainingClass(m_actionActivation_EClass, ACTIONACTIVATION_EATTRIBUTE_FIRING);
	
	m_actionActivation_EReference_pinActivation = factory->createEReference_in_EContainingClass(m_actionActivation_EClass, ACTIONACTIVATION_EREFERENCE_PINACTIVATION);
	
	m_actionActivation_EOperation_addOutgoingEdge_ActivityEdgeInstance = factory->createEOperation_in_EContainingClass(m_actionActivation_EClass, ACTIONACTIVATION_EOPERATION_ADDOUTGOINGEDGE_ACTIVITYEDGEINSTANCE);
	m_actionActivation_EOperation_addPinActivation_PinActivation = factory->createEOperation_in_EContainingClass(m_actionActivation_EClass, ACTIONACTIVATION_EOPERATION_ADDPINACTIVATION_PINACTIVATION);
	m_actionActivation_EOperation_completeAction = factory->createEOperation_in_EContainingClass(m_actionActivation_EClass, ACTIONACTIVATION_EOPERATION_COMPLETEACTION);
	m_actionActivation_EOperation_createNodeActivations = factory->createEOperation_in_EContainingClass(m_actionActivation_EClass, ACTIONACTIVATION_EOPERATION_CREATENODEACTIVATIONS);
	m_actionActivation_EOperation_doAction = factory->createEOperation_in_EContainingClass(m_actionActivation_EClass, ACTIONACTIVATION_EOPERATION_DOACTION);
	m_actionActivation_EOperation_fire_Token = factory->createEOperation_in_EContainingClass(m_actionActivation_EClass, ACTIONACTIVATION_EOPERATION_FIRE_TOKEN);
	m_actionActivation_EOperation_getTokens_InputPin = factory->createEOperation_in_EContainingClass(m_actionActivation_EClass, ACTIONACTIVATION_EOPERATION_GETTOKENS_INPUTPIN);
	m_actionActivation_EOperation_isFirng = factory->createEOperation_in_EContainingClass(m_actionActivation_EClass, ACTIONACTIVATION_EOPERATION_ISFIRNG);
	m_actionActivation_EOperation_isReady = factory->createEOperation_in_EContainingClass(m_actionActivation_EClass, ACTIONACTIVATION_EOPERATION_ISREADY);
	m_actionActivation_EOperation_isSourceFor_ActivityEdgeInstance = factory->createEOperation_in_EContainingClass(m_actionActivation_EClass, ACTIONACTIVATION_EOPERATION_ISSOURCEFOR_ACTIVITYEDGEINSTANCE);
	m_actionActivation_EOperation_makeBooleanValue_EBoolean = factory->createEOperation_in_EContainingClass(m_actionActivation_EClass, ACTIONACTIVATION_EOPERATION_MAKEBOOLEANVALUE_EBOOLEAN);
	m_actionActivation_EOperation_putToken_OutputPin_Value = factory->createEOperation_in_EContainingClass(m_actionActivation_EClass, ACTIONACTIVATION_EOPERATION_PUTTOKEN_OUTPUTPIN_VALUE);
	m_actionActivation_EOperation_putTokens_OutputPin_Value = factory->createEOperation_in_EContainingClass(m_actionActivation_EClass, ACTIONACTIVATION_EOPERATION_PUTTOKENS_OUTPUTPIN_VALUE);
	m_actionActivation_EOperation_retrievePinActivation_Pin = factory->createEOperation_in_EContainingClass(m_actionActivation_EClass, ACTIONACTIVATION_EOPERATION_RETRIEVEPINACTIVATION_PIN);
	m_actionActivation_EOperation_run = factory->createEOperation_in_EContainingClass(m_actionActivation_EClass, ACTIONACTIVATION_EOPERATION_RUN);
	m_actionActivation_EOperation_sendOffers = factory->createEOperation_in_EContainingClass(m_actionActivation_EClass, ACTIONACTIVATION_EOPERATION_SENDOFFERS);
	m_actionActivation_EOperation_takeOfferedTokens = factory->createEOperation_in_EContainingClass(m_actionActivation_EClass, ACTIONACTIVATION_EOPERATION_TAKEOFFEREDTOKENS);
	m_actionActivation_EOperation_takeTokens_InputPin = factory->createEOperation_in_EContainingClass(m_actionActivation_EClass, ACTIONACTIVATION_EOPERATION_TAKETOKENS_INPUTPIN);
	m_actionActivation_EOperation_terminate = factory->createEOperation_in_EContainingClass(m_actionActivation_EClass, ACTIONACTIVATION_EOPERATION_TERMINATE);
	m_actionActivation_EOperation_valueParticipatesInLink_Value_Link = factory->createEOperation_in_EContainingClass(m_actionActivation_EClass, ACTIONACTIVATION_EOPERATION_VALUEPARTICIPATESINLINK_VALUE_LINK);
	
}

void FUMLPackageImpl::createActivityEdgeInstanceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_activityEdgeInstance_EClass = factory->createEClass_in_EPackage(package, ACTIVITYEDGEINSTANCE_ECLASS);
	
	m_activityEdgeInstance_EReference_edge = factory->createEReference_in_EContainingClass(m_activityEdgeInstance_EClass, ACTIVITYEDGEINSTANCE_EREFERENCE_EDGE);
	m_activityEdgeInstance_EReference_group = factory->createEReference_in_EContainingClass(m_activityEdgeInstance_EClass, ACTIVITYEDGEINSTANCE_EREFERENCE_GROUP);
	m_activityEdgeInstance_EReference_offers = factory->createEReference_in_EContainingClass(m_activityEdgeInstance_EClass, ACTIVITYEDGEINSTANCE_EREFERENCE_OFFERS);
	m_activityEdgeInstance_EReference_source = factory->createEReference_in_EContainingClass(m_activityEdgeInstance_EClass, ACTIVITYEDGEINSTANCE_EREFERENCE_SOURCE);
	m_activityEdgeInstance_EReference_target = factory->createEReference_in_EContainingClass(m_activityEdgeInstance_EClass, ACTIVITYEDGEINSTANCE_EREFERENCE_TARGET);
	
	m_activityEdgeInstance_EOperation_countOfferedValue = factory->createEOperation_in_EContainingClass(m_activityEdgeInstance_EClass, ACTIVITYEDGEINSTANCE_EOPERATION_COUNTOFFEREDVALUE);
	m_activityEdgeInstance_EOperation_getOfferedTokens = factory->createEOperation_in_EContainingClass(m_activityEdgeInstance_EClass, ACTIVITYEDGEINSTANCE_EOPERATION_GETOFFEREDTOKENS);
	m_activityEdgeInstance_EOperation_hasOffer = factory->createEOperation_in_EContainingClass(m_activityEdgeInstance_EClass, ACTIVITYEDGEINSTANCE_EOPERATION_HASOFFER);
	m_activityEdgeInstance_EOperation_sendOffer_Token = factory->createEOperation_in_EContainingClass(m_activityEdgeInstance_EClass, ACTIVITYEDGEINSTANCE_EOPERATION_SENDOFFER_TOKEN);
	m_activityEdgeInstance_EOperation_takeOfferedTokens = factory->createEOperation_in_EContainingClass(m_activityEdgeInstance_EClass, ACTIVITYEDGEINSTANCE_EOPERATION_TAKEOFFEREDTOKENS);
	m_activityEdgeInstance_EOperation_takeOfferedTokens_EInt = factory->createEOperation_in_EContainingClass(m_activityEdgeInstance_EClass, ACTIVITYEDGEINSTANCE_EOPERATION_TAKEOFFEREDTOKENS_EINT);
	
}

void FUMLPackageImpl::createActivityExecutionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_activityExecution_EClass = factory->createEClass_in_EPackage(package, ACTIVITYEXECUTION_ECLASS);
	
	m_activityExecution_EReference_activationGroup = factory->createEReference_in_EContainingClass(m_activityExecution_EClass, ACTIVITYEXECUTION_EREFERENCE_ACTIVATIONGROUP);
	
	m_activityExecution_EOperation_execute = factory->createEOperation_in_EContainingClass(m_activityExecution_EClass, ACTIVITYEXECUTION_EOPERATION_EXECUTE);
	m_activityExecution_EOperation_new_ = factory->createEOperation_in_EContainingClass(m_activityExecution_EClass, ACTIVITYEXECUTION_EOPERATION_NEW_);
	m_activityExecution_EOperation_terminate = factory->createEOperation_in_EContainingClass(m_activityExecution_EClass, ACTIVITYEXECUTION_EOPERATION_TERMINATE);
	
}

void FUMLPackageImpl::createActivityFinalNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_activityFinalNodeActivation_EClass = factory->createEClass_in_EPackage(package, ACTIVITYFINALNODEACTIVATION_ECLASS);
	
	
	m_activityFinalNodeActivation_EOperation_fire_Token = factory->createEOperation_in_EContainingClass(m_activityFinalNodeActivation_EClass, ACTIVITYFINALNODEACTIVATION_EOPERATION_FIRE_TOKEN);
	
}

void FUMLPackageImpl::createActivityNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_activityNodeActivation_EClass = factory->createEClass_in_EPackage(package, ACTIVITYNODEACTIVATION_ECLASS);
	m_activityNodeActivation_EAttribute_running = factory->createEAttribute_in_EContainingClass(m_activityNodeActivation_EClass, ACTIVITYNODEACTIVATION_EATTRIBUTE_RUNNING);
	
	m_activityNodeActivation_EReference_group = factory->createEReference_in_EContainingClass(m_activityNodeActivation_EClass, ACTIVITYNODEACTIVATION_EREFERENCE_GROUP);
	m_activityNodeActivation_EReference_heldTokens = factory->createEReference_in_EContainingClass(m_activityNodeActivation_EClass, ACTIVITYNODEACTIVATION_EREFERENCE_HELDTOKENS);
	m_activityNodeActivation_EReference_incomingEdges = factory->createEReference_in_EContainingClass(m_activityNodeActivation_EClass, ACTIVITYNODEACTIVATION_EREFERENCE_INCOMINGEDGES);
	m_activityNodeActivation_EReference_node = factory->createEReference_in_EContainingClass(m_activityNodeActivation_EClass, ACTIVITYNODEACTIVATION_EREFERENCE_NODE);
	m_activityNodeActivation_EReference_outgoingEdges = factory->createEReference_in_EContainingClass(m_activityNodeActivation_EClass, ACTIVITYNODEACTIVATION_EREFERENCE_OUTGOINGEDGES);
	
	m_activityNodeActivation_EOperation_addIncomingEdge_ActivityEdgeInstance = factory->createEOperation_in_EContainingClass(m_activityNodeActivation_EClass, ACTIVITYNODEACTIVATION_EOPERATION_ADDINCOMINGEDGE_ACTIVITYEDGEINSTANCE);
	m_activityNodeActivation_EOperation_addOutgoingEdge_ActivityEdgeInstance = factory->createEOperation_in_EContainingClass(m_activityNodeActivation_EClass, ACTIVITYNODEACTIVATION_EOPERATION_ADDOUTGOINGEDGE_ACTIVITYEDGEINSTANCE);
	m_activityNodeActivation_EOperation_addToken_Token = factory->createEOperation_in_EContainingClass(m_activityNodeActivation_EClass, ACTIVITYNODEACTIVATION_EOPERATION_ADDTOKEN_TOKEN);
	m_activityNodeActivation_EOperation_addTokens_Token = factory->createEOperation_in_EContainingClass(m_activityNodeActivation_EClass, ACTIVITYNODEACTIVATION_EOPERATION_ADDTOKENS_TOKEN);
	m_activityNodeActivation_EOperation_clearTokens = factory->createEOperation_in_EContainingClass(m_activityNodeActivation_EClass, ACTIVITYNODEACTIVATION_EOPERATION_CLEARTOKENS);
	m_activityNodeActivation_EOperation_createEdgeInstances = factory->createEOperation_in_EContainingClass(m_activityNodeActivation_EClass, ACTIVITYNODEACTIVATION_EOPERATION_CREATEEDGEINSTANCES);
	m_activityNodeActivation_EOperation_createNodeActivations = factory->createEOperation_in_EContainingClass(m_activityNodeActivation_EClass, ACTIVITYNODEACTIVATION_EOPERATION_CREATENODEACTIVATIONS);
	m_activityNodeActivation_EOperation_fire_Token = factory->createEOperation_in_EContainingClass(m_activityNodeActivation_EClass, ACTIVITYNODEACTIVATION_EOPERATION_FIRE_TOKEN);
	m_activityNodeActivation_EOperation_getActivityExecution = factory->createEOperation_in_EContainingClass(m_activityNodeActivation_EClass, ACTIVITYNODEACTIVATION_EOPERATION_GETACTIVITYEXECUTION);
	m_activityNodeActivation_EOperation_getExecutionContext = factory->createEOperation_in_EContainingClass(m_activityNodeActivation_EClass, ACTIVITYNODEACTIVATION_EOPERATION_GETEXECUTIONCONTEXT);
	m_activityNodeActivation_EOperation_getExecutionLocus = factory->createEOperation_in_EContainingClass(m_activityNodeActivation_EClass, ACTIVITYNODEACTIVATION_EOPERATION_GETEXECUTIONLOCUS);
	m_activityNodeActivation_EOperation_getNodeActivation_ActivityNode = factory->createEOperation_in_EContainingClass(m_activityNodeActivation_EClass, ACTIVITYNODEACTIVATION_EOPERATION_GETNODEACTIVATION_ACTIVITYNODE);
	m_activityNodeActivation_EOperation_getRunning = factory->createEOperation_in_EContainingClass(m_activityNodeActivation_EClass, ACTIVITYNODEACTIVATION_EOPERATION_GETRUNNING);
	m_activityNodeActivation_EOperation_getTokens = factory->createEOperation_in_EContainingClass(m_activityNodeActivation_EClass, ACTIVITYNODEACTIVATION_EOPERATION_GETTOKENS);
	m_activityNodeActivation_EOperation_isReady = factory->createEOperation_in_EContainingClass(m_activityNodeActivation_EClass, ACTIVITYNODEACTIVATION_EOPERATION_ISREADY);
	m_activityNodeActivation_EOperation_isSourceFor_ActivityEdgeInstance = factory->createEOperation_in_EContainingClass(m_activityNodeActivation_EClass, ACTIVITYNODEACTIVATION_EOPERATION_ISSOURCEFOR_ACTIVITYEDGEINSTANCE);
	m_activityNodeActivation_EOperation_recieveOffer = factory->createEOperation_in_EContainingClass(m_activityNodeActivation_EClass, ACTIVITYNODEACTIVATION_EOPERATION_RECIEVEOFFER);
	m_activityNodeActivation_EOperation_removeToken_Token = factory->createEOperation_in_EContainingClass(m_activityNodeActivation_EClass, ACTIVITYNODEACTIVATION_EOPERATION_REMOVETOKEN_TOKEN);
	m_activityNodeActivation_EOperation_resume = factory->createEOperation_in_EContainingClass(m_activityNodeActivation_EClass, ACTIVITYNODEACTIVATION_EOPERATION_RESUME);
	m_activityNodeActivation_EOperation_run = factory->createEOperation_in_EContainingClass(m_activityNodeActivation_EClass, ACTIVITYNODEACTIVATION_EOPERATION_RUN);
	m_activityNodeActivation_EOperation_sendOffers_Token = factory->createEOperation_in_EContainingClass(m_activityNodeActivation_EClass, ACTIVITYNODEACTIVATION_EOPERATION_SENDOFFERS_TOKEN);
	m_activityNodeActivation_EOperation_suspend = factory->createEOperation_in_EContainingClass(m_activityNodeActivation_EClass, ACTIVITYNODEACTIVATION_EOPERATION_SUSPEND);
	m_activityNodeActivation_EOperation_takeOfferedTokens = factory->createEOperation_in_EContainingClass(m_activityNodeActivation_EClass, ACTIVITYNODEACTIVATION_EOPERATION_TAKEOFFEREDTOKENS);
	m_activityNodeActivation_EOperation_takeTokens = factory->createEOperation_in_EContainingClass(m_activityNodeActivation_EClass, ACTIVITYNODEACTIVATION_EOPERATION_TAKETOKENS);
	m_activityNodeActivation_EOperation_terminate = factory->createEOperation_in_EContainingClass(m_activityNodeActivation_EClass, ACTIVITYNODEACTIVATION_EOPERATION_TERMINATE);
	
}

void FUMLPackageImpl::createActivityNodeActivationGroupContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_activityNodeActivationGroup_EClass = factory->createEClass_in_EPackage(package, ACTIVITYNODEACTIVATIONGROUP_ECLASS);
	
	m_activityNodeActivationGroup_EReference_activityExecution = factory->createEReference_in_EContainingClass(m_activityNodeActivationGroup_EClass, ACTIVITYNODEACTIVATIONGROUP_EREFERENCE_ACTIVITYEXECUTION);
	m_activityNodeActivationGroup_EReference_containingNodeActivation = factory->createEReference_in_EContainingClass(m_activityNodeActivationGroup_EClass, ACTIVITYNODEACTIVATIONGROUP_EREFERENCE_CONTAININGNODEACTIVATION);
	m_activityNodeActivationGroup_EReference_edgeInstances = factory->createEReference_in_EContainingClass(m_activityNodeActivationGroup_EClass, ACTIVITYNODEACTIVATIONGROUP_EREFERENCE_EDGEINSTANCES);
	m_activityNodeActivationGroup_EReference_nodeActivations = factory->createEReference_in_EContainingClass(m_activityNodeActivationGroup_EClass, ACTIVITYNODEACTIVATIONGROUP_EREFERENCE_NODEACTIVATIONS);
	m_activityNodeActivationGroup_EReference_suspendedActivations = factory->createEReference_in_EContainingClass(m_activityNodeActivationGroup_EClass, ACTIVITYNODEACTIVATIONGROUP_EREFERENCE_SUSPENDEDACTIVATIONS);
	
	m_activityNodeActivationGroup_EOperation_activate_ActivityNode_ActivityEdge = factory->createEOperation_in_EContainingClass(m_activityNodeActivationGroup_EClass, ACTIVITYNODEACTIVATIONGROUP_EOPERATION_ACTIVATE_ACTIVITYNODE_ACTIVITYEDGE);
	m_activityNodeActivationGroup_EOperation_addEdgeInstance_ActivityEdgeInstance = factory->createEOperation_in_EContainingClass(m_activityNodeActivationGroup_EClass, ACTIVITYNODEACTIVATIONGROUP_EOPERATION_ADDEDGEINSTANCE_ACTIVITYEDGEINSTANCE);
	m_activityNodeActivationGroup_EOperation_addNodeActivation_ActivityNodeActivation = factory->createEOperation_in_EContainingClass(m_activityNodeActivationGroup_EClass, ACTIVITYNODEACTIVATIONGROUP_EOPERATION_ADDNODEACTIVATION_ACTIVITYNODEACTIVATION);
	m_activityNodeActivationGroup_EOperation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation = factory->createEOperation_in_EContainingClass(m_activityNodeActivationGroup_EClass, ACTIVITYNODEACTIVATIONGROUP_EOPERATION_CHECKINCOMINGEDGES_ACTIVITYEDGEINSTANCE_ACTIVITYNODEACTIVATION);
	m_activityNodeActivationGroup_EOperation_createEdgeInstance_ActivityEdge = factory->createEOperation_in_EContainingClass(m_activityNodeActivationGroup_EClass, ACTIVITYNODEACTIVATIONGROUP_EOPERATION_CREATEEDGEINSTANCE_ACTIVITYEDGE);
	m_activityNodeActivationGroup_EOperation_createNodeActivation_ActivityNode = factory->createEOperation_in_EContainingClass(m_activityNodeActivationGroup_EClass, ACTIVITYNODEACTIVATIONGROUP_EOPERATION_CREATENODEACTIVATION_ACTIVITYNODE);
	m_activityNodeActivationGroup_EOperation_createNodeActivations_ActivityNode = factory->createEOperation_in_EContainingClass(m_activityNodeActivationGroup_EClass, ACTIVITYNODEACTIVATIONGROUP_EOPERATION_CREATENODEACTIVATIONS_ACTIVITYNODE);
	m_activityNodeActivationGroup_EOperation_getNodeActivation_ActivityNode = factory->createEOperation_in_EContainingClass(m_activityNodeActivationGroup_EClass, ACTIVITYNODEACTIVATIONGROUP_EOPERATION_GETNODEACTIVATION_ACTIVITYNODE);
	m_activityNodeActivationGroup_EOperation_getOutputParameterNodeActivations = factory->createEOperation_in_EContainingClass(m_activityNodeActivationGroup_EClass, ACTIVITYNODEACTIVATIONGROUP_EOPERATION_GETOUTPUTPARAMETERNODEACTIVATIONS);
	m_activityNodeActivationGroup_EOperation_hasSourceFor_ActivityEdgeInstance = factory->createEOperation_in_EContainingClass(m_activityNodeActivationGroup_EClass, ACTIVITYNODEACTIVATIONGROUP_EOPERATION_HASSOURCEFOR_ACTIVITYEDGEINSTANCE);
	m_activityNodeActivationGroup_EOperation_isSuspended = factory->createEOperation_in_EContainingClass(m_activityNodeActivationGroup_EClass, ACTIVITYNODEACTIVATIONGROUP_EOPERATION_ISSUSPENDED);
	m_activityNodeActivationGroup_EOperation_resume_ActivityNodeActivation = factory->createEOperation_in_EContainingClass(m_activityNodeActivationGroup_EClass, ACTIVITYNODEACTIVATIONGROUP_EOPERATION_RESUME_ACTIVITYNODEACTIVATION);
	m_activityNodeActivationGroup_EOperation_retrieveActivityExecution = factory->createEOperation_in_EContainingClass(m_activityNodeActivationGroup_EClass, ACTIVITYNODEACTIVATIONGROUP_EOPERATION_RETRIEVEACTIVITYEXECUTION);
	m_activityNodeActivationGroup_EOperation_run_ActivityNodeActivation = factory->createEOperation_in_EContainingClass(m_activityNodeActivationGroup_EClass, ACTIVITYNODEACTIVATIONGROUP_EOPERATION_RUN_ACTIVITYNODEACTIVATION);
	m_activityNodeActivationGroup_EOperation_runNodes_ActivityNode = factory->createEOperation_in_EContainingClass(m_activityNodeActivationGroup_EClass, ACTIVITYNODEACTIVATIONGROUP_EOPERATION_RUNNODES_ACTIVITYNODE);
	m_activityNodeActivationGroup_EOperation_suspend_ActivityNodeActivation = factory->createEOperation_in_EContainingClass(m_activityNodeActivationGroup_EClass, ACTIVITYNODEACTIVATIONGROUP_EOPERATION_SUSPEND_ACTIVITYNODEACTIVATION);
	m_activityNodeActivationGroup_EOperation_terminateAll = factory->createEOperation_in_EContainingClass(m_activityNodeActivationGroup_EClass, ACTIVITYNODEACTIVATIONGROUP_EOPERATION_TERMINATEALL);
	
}

void FUMLPackageImpl::createActivityParameterNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_activityParameterNodeActivation_EClass = factory->createEClass_in_EPackage(package, ACTIVITYPARAMETERNODEACTIVATION_ECLASS);
	
	
	m_activityParameterNodeActivation_EOperation_clearTokens = factory->createEOperation_in_EContainingClass(m_activityParameterNodeActivation_EClass, ACTIVITYPARAMETERNODEACTIVATION_EOPERATION_CLEARTOKENS);
	m_activityParameterNodeActivation_EOperation_fire_Token = factory->createEOperation_in_EContainingClass(m_activityParameterNodeActivation_EClass, ACTIVITYPARAMETERNODEACTIVATION_EOPERATION_FIRE_TOKEN);
	
}

void FUMLPackageImpl::createAddStructuralFeatureValueActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_addStructuralFeatureValueActionActivation_EClass = factory->createEClass_in_EPackage(package, ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_ECLASS);
	
	
	
}

void FUMLPackageImpl::createBooleanValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_booleanValue_EClass = factory->createEClass_in_EPackage(package, BOOLEANVALUE_ECLASS);
	m_booleanValue_EAttribute_value = factory->createEAttribute_in_EContainingClass(m_booleanValue_EClass, BOOLEANVALUE_EATTRIBUTE_VALUE);
	
	
	m_booleanValue_EOperation_equals_Value = factory->createEOperation_in_EContainingClass(m_booleanValue_EClass, BOOLEANVALUE_EOPERATION_EQUALS_VALUE);
	m_booleanValue_EOperation_specify = factory->createEOperation_in_EContainingClass(m_booleanValue_EClass, BOOLEANVALUE_EOPERATION_SPECIFY);
	m_booleanValue_EOperation_toString = factory->createEOperation_in_EContainingClass(m_booleanValue_EClass, BOOLEANVALUE_EOPERATION_TOSTRING);
	
}

void FUMLPackageImpl::createCallActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_callActionActivation_EClass = factory->createEClass_in_EPackage(package, CALLACTIONACTIVATION_ECLASS);
	
	m_callActionActivation_EReference_callExecutions = factory->createEReference_in_EContainingClass(m_callActionActivation_EClass, CALLACTIONACTIVATION_EREFERENCE_CALLEXECUTIONS);
	
	m_callActionActivation_EOperation_doAction = factory->createEOperation_in_EContainingClass(m_callActionActivation_EClass, CALLACTIONACTIVATION_EOPERATION_DOACTION);
	m_callActionActivation_EOperation_getCallExecution = factory->createEOperation_in_EContainingClass(m_callActionActivation_EClass, CALLACTIONACTIVATION_EOPERATION_GETCALLEXECUTION);
	m_callActionActivation_EOperation_removeCallExecution_Execution = factory->createEOperation_in_EContainingClass(m_callActionActivation_EClass, CALLACTIONACTIVATION_EOPERATION_REMOVECALLEXECUTION_EXECUTION);
	m_callActionActivation_EOperation_terminate = factory->createEOperation_in_EContainingClass(m_callActionActivation_EClass, CALLACTIONACTIVATION_EOPERATION_TERMINATE);
	
}

void FUMLPackageImpl::createCallBehaviorActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_callBehaviorActionActivation_EClass = factory->createEClass_in_EPackage(package, CALLBEHAVIORACTIONACTIVATION_ECLASS);
	
	
	m_callBehaviorActionActivation_EOperation_getCallExecution = factory->createEOperation_in_EContainingClass(m_callBehaviorActionActivation_EClass, CALLBEHAVIORACTIONACTIVATION_EOPERATION_GETCALLEXECUTION);
	
}

void FUMLPackageImpl::createCallOperationActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_callOperationActionActivation_EClass = factory->createEClass_in_EPackage(package, CALLOPERATIONACTIONACTIVATION_ECLASS);
	
	
	m_callOperationActionActivation_EOperation_getCallExecution = factory->createEOperation_in_EContainingClass(m_callOperationActionActivation_EClass, CALLOPERATIONACTIONACTIVATION_EOPERATION_GETCALLEXECUTION);
	
}

void FUMLPackageImpl::createCentralBufferNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_centralBufferNodeActivation_EClass = factory->createEClass_in_EPackage(package, CENTRALBUFFERNODEACTIVATION_ECLASS);
	
	
	m_centralBufferNodeActivation_EOperation_fire_Token = factory->createEOperation_in_EContainingClass(m_centralBufferNodeActivation_EClass, CENTRALBUFFERNODEACTIVATION_EOPERATION_FIRE_TOKEN);
	
}

void FUMLPackageImpl::createChoiceStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_choiceStrategy_EClass = factory->createEClass_in_EPackage(package, CHOICESTRATEGY_ECLASS);
	
	
	m_choiceStrategy_EOperation_choose_EInt = factory->createEOperation_in_EContainingClass(m_choiceStrategy_EClass, CHOICESTRATEGY_EOPERATION_CHOOSE_EINT);
	m_choiceStrategy_EOperation_retrieveName = factory->createEOperation_in_EContainingClass(m_choiceStrategy_EClass, CHOICESTRATEGY_EOPERATION_RETRIEVENAME);
	
}

void FUMLPackageImpl::createClassifierBehaviorExecutionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_classifierBehaviorExecution_EClass = factory->createEClass_in_EPackage(package, CLASSIFIERBEHAVIOREXECUTION_ECLASS);
	
	m_classifierBehaviorExecution_EReference_classifier = factory->createEReference_in_EContainingClass(m_classifierBehaviorExecution_EClass, CLASSIFIERBEHAVIOREXECUTION_EREFERENCE_CLASSIFIER);
	m_classifierBehaviorExecution_EReference_execution = factory->createEReference_in_EContainingClass(m_classifierBehaviorExecution_EClass, CLASSIFIERBEHAVIOREXECUTION_EREFERENCE_EXECUTION);
	m_classifierBehaviorExecution_EReference_objectActivation = factory->createEReference_in_EContainingClass(m_classifierBehaviorExecution_EClass, CLASSIFIERBEHAVIOREXECUTION_EREFERENCE_OBJECTACTIVATION);
	
	m_classifierBehaviorExecution_EOperation__startObjectBehavior = factory->createEOperation_in_EContainingClass(m_classifierBehaviorExecution_EClass, CLASSIFIERBEHAVIOREXECUTION_EOPERATION__STARTOBJECTBEHAVIOR);
	m_classifierBehaviorExecution_EOperation_execute_Class_ParameterValue = factory->createEOperation_in_EContainingClass(m_classifierBehaviorExecution_EClass, CLASSIFIERBEHAVIOREXECUTION_EOPERATION_EXECUTE_CLASS_PARAMETERVALUE);
	m_classifierBehaviorExecution_EOperation_terminate = factory->createEOperation_in_EContainingClass(m_classifierBehaviorExecution_EClass, CLASSIFIERBEHAVIOREXECUTION_EOPERATION_TERMINATE);
	
}

void FUMLPackageImpl::createClassifierBehaviorExecutionActivityContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_classifierBehaviorExecutionActivity_EClass = factory->createEClass_in_EPackage(package, CLASSIFIERBEHAVIOREXECUTIONACTIVITY_ECLASS);
	
	
	
}

void FUMLPackageImpl::createClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Content(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_classifierBehaviorExecutionActivity_OwnedBehaviorActivity1_EClass = factory->createEClass_in_EPackage(package, CLASSIFIERBEHAVIOREXECUTIONACTIVITY_OWNEDBEHAVIORACTIVITY1_ECLASS);
	
	
	
}

void FUMLPackageImpl::createClauseActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_clauseActivation_EClass = factory->createEClass_in_EPackage(package, CLAUSEACTIVATION_ECLASS);
	
	m_clauseActivation_EReference_clause = factory->createEReference_in_EContainingClass(m_clauseActivation_EClass, CLAUSEACTIVATION_EREFERENCE_CLAUSE);
	m_clauseActivation_EReference_conditionalNodeActivation = factory->createEReference_in_EContainingClass(m_clauseActivation_EClass, CLAUSEACTIVATION_EREFERENCE_CONDITIONALNODEACTIVATION);
	
	m_clauseActivation_EOperation_getDecision = factory->createEOperation_in_EContainingClass(m_clauseActivation_EClass, CLAUSEACTIVATION_EOPERATION_GETDECISION);
	m_clauseActivation_EOperation_getPredecessors = factory->createEOperation_in_EContainingClass(m_clauseActivation_EClass, CLAUSEACTIVATION_EOPERATION_GETPREDECESSORS);
	m_clauseActivation_EOperation_getSuccessors = factory->createEOperation_in_EContainingClass(m_clauseActivation_EClass, CLAUSEACTIVATION_EOPERATION_GETSUCCESSORS);
	m_clauseActivation_EOperation_isReady = factory->createEOperation_in_EContainingClass(m_clauseActivation_EClass, CLAUSEACTIVATION_EOPERATION_ISREADY);
	m_clauseActivation_EOperation_recieveControl = factory->createEOperation_in_EContainingClass(m_clauseActivation_EClass, CLAUSEACTIVATION_EOPERATION_RECIEVECONTROL);
	m_clauseActivation_EOperation_runTest = factory->createEOperation_in_EContainingClass(m_clauseActivation_EClass, CLAUSEACTIVATION_EOPERATION_RUNTEST);
	m_clauseActivation_EOperation_selectBody = factory->createEOperation_in_EContainingClass(m_clauseActivation_EClass, CLAUSEACTIVATION_EOPERATION_SELECTBODY);
	
}

void FUMLPackageImpl::createClearAssociationActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_clearAssociationActionActivation_EClass = factory->createEClass_in_EPackage(package, CLEARASSOCIATIONACTIONACTIVATION_ECLASS);
	
	
	
}

void FUMLPackageImpl::createClearStructuralFeatureActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_clearStructuralFeatureActionActivation_EClass = factory->createEClass_in_EPackage(package, CLEARSTRUCTURALFEATUREACTIONACTIVATION_ECLASS);
	
	
	
}

void FUMLPackageImpl::createCompoundValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_compoundValue_EClass = factory->createEClass_in_EPackage(package, COMPOUNDVALUE_ECLASS);
	
	m_compoundValue_EReference_featureValues = factory->createEReference_in_EContainingClass(m_compoundValue_EClass, COMPOUNDVALUE_EREFERENCE_FEATUREVALUES);
	
	m_compoundValue_EOperation_assignFeatureValue_StructuralFeature_EInt = factory->createEOperation_in_EContainingClass(m_compoundValue_EClass, COMPOUNDVALUE_EOPERATION_ASSIGNFEATUREVALUE_STRUCTURALFEATURE_EINT);
	m_compoundValue_EOperation_equals_Value = factory->createEOperation_in_EContainingClass(m_compoundValue_EClass, COMPOUNDVALUE_EOPERATION_EQUALS_VALUE);
	m_compoundValue_EOperation_removeFeatureValues_Classifier = factory->createEOperation_in_EContainingClass(m_compoundValue_EClass, COMPOUNDVALUE_EOPERATION_REMOVEFEATUREVALUES_CLASSIFIER);
	m_compoundValue_EOperation_retrieveFeatureValue_StructuralFeature = factory->createEOperation_in_EContainingClass(m_compoundValue_EClass, COMPOUNDVALUE_EOPERATION_RETRIEVEFEATUREVALUE_STRUCTURALFEATURE);
	m_compoundValue_EOperation_retrieveFeatureValues = factory->createEOperation_in_EContainingClass(m_compoundValue_EClass, COMPOUNDVALUE_EOPERATION_RETRIEVEFEATUREVALUES);
	m_compoundValue_EOperation_toString = factory->createEOperation_in_EContainingClass(m_compoundValue_EClass, COMPOUNDVALUE_EOPERATION_TOSTRING);
	
}

void FUMLPackageImpl::createConditionalNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_conditionalNodeActivation_EClass = factory->createEClass_in_EPackage(package, CONDITIONALNODEACTIVATION_ECLASS);
	
	m_conditionalNodeActivation_EReference_clauseActivations = factory->createEReference_in_EContainingClass(m_conditionalNodeActivation_EClass, CONDITIONALNODEACTIVATION_EREFERENCE_CLAUSEACTIVATIONS);
	m_conditionalNodeActivation_EReference_selectedClauses = factory->createEReference_in_EContainingClass(m_conditionalNodeActivation_EClass, CONDITIONALNODEACTIVATION_EREFERENCE_SELECTEDCLAUSES);
	
	m_conditionalNodeActivation_EOperation_getClauseActivation_Clause = factory->createEOperation_in_EContainingClass(m_conditionalNodeActivation_EClass, CONDITIONALNODEACTIVATION_EOPERATION_GETCLAUSEACTIVATION_CLAUSE);
	m_conditionalNodeActivation_EOperation_runTest_Clause = factory->createEOperation_in_EContainingClass(m_conditionalNodeActivation_EClass, CONDITIONALNODEACTIVATION_EOPERATION_RUNTEST_CLAUSE);
	m_conditionalNodeActivation_EOperation_selectBody_Clause = factory->createEOperation_in_EContainingClass(m_conditionalNodeActivation_EClass, CONDITIONALNODEACTIVATION_EOPERATION_SELECTBODY_CLAUSE);
	
}

void FUMLPackageImpl::createControlNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_controlNodeActivation_EClass = factory->createEClass_in_EPackage(package, CONTROLNODEACTIVATION_ECLASS);
	
	
	m_controlNodeActivation_EOperation_fire_Token = factory->createEOperation_in_EContainingClass(m_controlNodeActivation_EClass, CONTROLNODEACTIVATION_EOPERATION_FIRE_TOKEN);
	
}

void FUMLPackageImpl::createControlTokenContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_controlToken_EClass = factory->createEClass_in_EPackage(package, CONTROLTOKEN_ECLASS);
	
	
	m_controlToken_EOperation_equals_Token = factory->createEOperation_in_EContainingClass(m_controlToken_EClass, CONTROLTOKEN_EOPERATION_EQUALS_TOKEN);
	m_controlToken_EOperation_getValue = factory->createEOperation_in_EContainingClass(m_controlToken_EClass, CONTROLTOKEN_EOPERATION_GETVALUE);
	m_controlToken_EOperation_isControl = factory->createEOperation_in_EContainingClass(m_controlToken_EClass, CONTROLTOKEN_EOPERATION_ISCONTROL);
	
}

void FUMLPackageImpl::createCreateLinkActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_createLinkActionActivation_EClass = factory->createEClass_in_EPackage(package, CREATELINKACTIONACTIVATION_ECLASS);
	
	
	
}

void FUMLPackageImpl::createCreateObjectActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_createObjectActionActivation_EClass = factory->createEClass_in_EPackage(package, CREATEOBJECTACTIONACTIVATION_ECLASS);
	
	
	
}

void FUMLPackageImpl::createDataStoreNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_dataStoreNodeActivation_EClass = factory->createEClass_in_EPackage(package, DATASTORENODEACTIVATION_ECLASS);
	
	
	m_dataStoreNodeActivation_EOperation_addToken_Token = factory->createEOperation_in_EContainingClass(m_dataStoreNodeActivation_EClass, DATASTORENODEACTIVATION_EOPERATION_ADDTOKEN_TOKEN);
	m_dataStoreNodeActivation_EOperation_removeToken_Token = factory->createEOperation_in_EContainingClass(m_dataStoreNodeActivation_EClass, DATASTORENODEACTIVATION_EOPERATION_REMOVETOKEN_TOKEN);
	
}

void FUMLPackageImpl::createDataValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_dataValue_EClass = factory->createEClass_in_EPackage(package, DATAVALUE_ECLASS);
	
	m_dataValue_EReference_type = factory->createEReference_in_EContainingClass(m_dataValue_EClass, DATAVALUE_EREFERENCE_TYPE);
	
	m_dataValue_EOperation_getTypes = factory->createEOperation_in_EContainingClass(m_dataValue_EClass, DATAVALUE_EOPERATION_GETTYPES);
	m_dataValue_EOperation_new_ = factory->createEOperation_in_EContainingClass(m_dataValue_EClass, DATAVALUE_EOPERATION_NEW_);
	
}

void FUMLPackageImpl::createDecisionNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_decisionNodeActivation_EClass = factory->createEClass_in_EPackage(package, DECISIONNODEACTIVATION_ECLASS);
	
	m_decisionNodeActivation_EReference_decisionInputExecution = factory->createEReference_in_EContainingClass(m_decisionNodeActivation_EClass, DECISIONNODEACTIVATION_EREFERENCE_DECISIONINPUTEXECUTION);
	
	m_decisionNodeActivation_EOperation_executeDecisionInputBehavior_Value_Value = factory->createEOperation_in_EContainingClass(m_decisionNodeActivation_EClass, DECISIONNODEACTIVATION_EOPERATION_EXECUTEDECISIONINPUTBEHAVIOR_VALUE_VALUE);
	m_decisionNodeActivation_EOperation_fire_Token = factory->createEOperation_in_EContainingClass(m_decisionNodeActivation_EClass, DECISIONNODEACTIVATION_EOPERATION_FIRE_TOKEN);
	m_decisionNodeActivation_EOperation_getDecisionInputFlowInstance = factory->createEOperation_in_EContainingClass(m_decisionNodeActivation_EClass, DECISIONNODEACTIVATION_EOPERATION_GETDECISIONINPUTFLOWINSTANCE);
	m_decisionNodeActivation_EOperation_getDecisionInputFlowValue = factory->createEOperation_in_EContainingClass(m_decisionNodeActivation_EClass, DECISIONNODEACTIVATION_EOPERATION_GETDECISIONINPUTFLOWVALUE);
	m_decisionNodeActivation_EOperation_getDecisionValues_Token = factory->createEOperation_in_EContainingClass(m_decisionNodeActivation_EClass, DECISIONNODEACTIVATION_EOPERATION_GETDECISIONVALUES_TOKEN);
	m_decisionNodeActivation_EOperation_hasObjectFlowInput = factory->createEOperation_in_EContainingClass(m_decisionNodeActivation_EClass, DECISIONNODEACTIVATION_EOPERATION_HASOBJECTFLOWINPUT);
	m_decisionNodeActivation_EOperation_isReady = factory->createEOperation_in_EContainingClass(m_decisionNodeActivation_EClass, DECISIONNODEACTIVATION_EOPERATION_ISREADY);
	m_decisionNodeActivation_EOperation_removeJoinedControlTokens_Token = factory->createEOperation_in_EContainingClass(m_decisionNodeActivation_EClass, DECISIONNODEACTIVATION_EOPERATION_REMOVEJOINEDCONTROLTOKENS_TOKEN);
	m_decisionNodeActivation_EOperation_takeOfferedTokens = factory->createEOperation_in_EContainingClass(m_decisionNodeActivation_EClass, DECISIONNODEACTIVATION_EOPERATION_TAKEOFFEREDTOKENS);
	m_decisionNodeActivation_EOperation_terminate = factory->createEOperation_in_EContainingClass(m_decisionNodeActivation_EClass, DECISIONNODEACTIVATION_EOPERATION_TERMINATE);
	m_decisionNodeActivation_EOperation_test_ValueSpecification_Value = factory->createEOperation_in_EContainingClass(m_decisionNodeActivation_EClass, DECISIONNODEACTIVATION_EOPERATION_TEST_VALUESPECIFICATION_VALUE);
	
}

void FUMLPackageImpl::createDestroyLinkActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_destroyLinkActionActivation_EClass = factory->createEClass_in_EPackage(package, DESTROYLINKACTIONACTIVATION_ECLASS);
	
	
	
}

void FUMLPackageImpl::createDestroyObjectActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_destroyObjectActionActivation_EClass = factory->createEClass_in_EPackage(package, DESTROYOBJECTACTIONACTIVATION_ECLASS);
	
	
	m_destroyObjectActionActivation_EOperation_destroyObject_Value_EBoolean = factory->createEOperation_in_EContainingClass(m_destroyObjectActionActivation_EClass, DESTROYOBJECTACTIONACTIVATION_EOPERATION_DESTROYOBJECT_VALUE_EBOOLEAN);
	m_destroyObjectActionActivation_EOperation_objectIsComposite_Reference_Link = factory->createEOperation_in_EContainingClass(m_destroyObjectActionActivation_EClass, DESTROYOBJECTACTIONACTIVATION_EOPERATION_OBJECTISCOMPOSITE_REFERENCE_LINK);
	
}

void FUMLPackageImpl::createDispatchStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_dispatchStrategy_EClass = factory->createEClass_in_EPackage(package, DISPATCHSTRATEGY_ECLASS);
	
	
	m_dispatchStrategy_EOperation_dispatch_Object_Operation = factory->createEOperation_in_EContainingClass(m_dispatchStrategy_EClass, DISPATCHSTRATEGY_EOPERATION_DISPATCH_OBJECT_OPERATION);
	m_dispatchStrategy_EOperation_retrieveMethod_Object_Operation = factory->createEOperation_in_EContainingClass(m_dispatchStrategy_EClass, DISPATCHSTRATEGY_EOPERATION_RETRIEVEMETHOD_OBJECT_OPERATION);
	m_dispatchStrategy_EOperation_retrieveName = factory->createEOperation_in_EContainingClass(m_dispatchStrategy_EClass, DISPATCHSTRATEGY_EOPERATION_RETRIEVENAME);
	
}

void FUMLPackageImpl::createEnumerationValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_enumerationValue_EClass = factory->createEClass_in_EPackage(package, ENUMERATIONVALUE_ECLASS);
	
	m_enumerationValue_EReference_literal = factory->createEReference_in_EContainingClass(m_enumerationValue_EClass, ENUMERATIONVALUE_EREFERENCE_LITERAL);
	m_enumerationValue_EReference_type = factory->createEReference_in_EContainingClass(m_enumerationValue_EClass, ENUMERATIONVALUE_EREFERENCE_TYPE);
	
	m_enumerationValue_EOperation_equals_Value = factory->createEOperation_in_EContainingClass(m_enumerationValue_EClass, ENUMERATIONVALUE_EOPERATION_EQUALS_VALUE);
	m_enumerationValue_EOperation_getTypes = factory->createEOperation_in_EContainingClass(m_enumerationValue_EClass, ENUMERATIONVALUE_EOPERATION_GETTYPES);
	m_enumerationValue_EOperation_new_ = factory->createEOperation_in_EContainingClass(m_enumerationValue_EClass, ENUMERATIONVALUE_EOPERATION_NEW_);
	m_enumerationValue_EOperation_specify = factory->createEOperation_in_EContainingClass(m_enumerationValue_EClass, ENUMERATIONVALUE_EOPERATION_SPECIFY);
	m_enumerationValue_EOperation_toString = factory->createEOperation_in_EContainingClass(m_enumerationValue_EClass, ENUMERATIONVALUE_EOPERATION_TOSTRING);
	
}

void FUMLPackageImpl::createEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_evaluation_EClass = factory->createEClass_in_EPackage(package, EVALUATION_ECLASS);
	
	m_evaluation_EReference_locus = factory->createEReference_in_EContainingClass(m_evaluation_EClass, EVALUATION_EREFERENCE_LOCUS);
	m_evaluation_EReference_specification = factory->createEReference_in_EContainingClass(m_evaluation_EClass, EVALUATION_EREFERENCE_SPECIFICATION);
	
	m_evaluation_EOperation_evaluate = factory->createEOperation_in_EContainingClass(m_evaluation_EClass, EVALUATION_EOPERATION_EVALUATE);
	
}

void FUMLPackageImpl::createEventAccepterContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_eventAccepter_EClass = factory->createEClass_in_EPackage(package, EVENTACCEPTER_ECLASS);
	
	
	m_eventAccepter_EOperation_accept_SignalInstance = factory->createEOperation_in_EContainingClass(m_eventAccepter_EClass, EVENTACCEPTER_EOPERATION_ACCEPT_SIGNALINSTANCE);
	m_eventAccepter_EOperation_match_SignalInstance = factory->createEOperation_in_EContainingClass(m_eventAccepter_EClass, EVENTACCEPTER_EOPERATION_MATCH_SIGNALINSTANCE);
	
}

void FUMLPackageImpl::createEventDispatchLoopContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_eventDispatchLoop_EClass = factory->createEClass_in_EPackage(package, EVENTDISPATCHLOOP_ECLASS);
	
	
	
}

void FUMLPackageImpl::createExecutionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_execution_EClass = factory->createEClass_in_EPackage(package, EXECUTION_ECLASS);
	
	m_execution_EReference_context = factory->createEReference_in_EContainingClass(m_execution_EClass, EXECUTION_EREFERENCE_CONTEXT);
	m_execution_EReference_parameterValues = factory->createEReference_in_EContainingClass(m_execution_EClass, EXECUTION_EREFERENCE_PARAMETERVALUES);
	
	m_execution_EOperation_execute = factory->createEOperation_in_EContainingClass(m_execution_EClass, EXECUTION_EOPERATION_EXECUTE);
	m_execution_EOperation_getBehavior = factory->createEOperation_in_EContainingClass(m_execution_EClass, EXECUTION_EOPERATION_GETBEHAVIOR);
	m_execution_EOperation_getOutputParameterValues = factory->createEOperation_in_EContainingClass(m_execution_EClass, EXECUTION_EOPERATION_GETOUTPUTPARAMETERVALUES);
	m_execution_EOperation_getParameterValue_Parameter = factory->createEOperation_in_EContainingClass(m_execution_EClass, EXECUTION_EOPERATION_GETPARAMETERVALUE_PARAMETER);
	m_execution_EOperation_new_ = factory->createEOperation_in_EContainingClass(m_execution_EClass, EXECUTION_EOPERATION_NEW_);
	m_execution_EOperation_setParameterValue_ParameterValue = factory->createEOperation_in_EContainingClass(m_execution_EClass, EXECUTION_EOPERATION_SETPARAMETERVALUE_PARAMETERVALUE);
	m_execution_EOperation_terminate = factory->createEOperation_in_EContainingClass(m_execution_EClass, EXECUTION_EOPERATION_TERMINATE);
	
}

void FUMLPackageImpl::createExecutionFactoryContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_executionFactory_EClass = factory->createEClass_in_EPackage(package, EXECUTIONFACTORY_ECLASS);
	
	m_executionFactory_EReference_builtInTypes = factory->createEReference_in_EContainingClass(m_executionFactory_EClass, EXECUTIONFACTORY_EREFERENCE_BUILTINTYPES);
	m_executionFactory_EReference_locus = factory->createEReference_in_EContainingClass(m_executionFactory_EClass, EXECUTIONFACTORY_EREFERENCE_LOCUS);
	m_executionFactory_EReference_primitiveBehaviorPrototypes = factory->createEReference_in_EContainingClass(m_executionFactory_EClass, EXECUTIONFACTORY_EREFERENCE_PRIMITIVEBEHAVIORPROTOTYPES);
	m_executionFactory_EReference_strategies = factory->createEReference_in_EContainingClass(m_executionFactory_EClass, EXECUTIONFACTORY_EREFERENCE_STRATEGIES);
	
	m_executionFactory_EOperation_addBuiltInType_PrimitiveType = factory->createEOperation_in_EContainingClass(m_executionFactory_EClass, EXECUTIONFACTORY_EOPERATION_ADDBUILTINTYPE_PRIMITIVETYPE);
	m_executionFactory_EOperation_addPrimitiveBehaviorPrototype_OpaqueBehaviorExecution = factory->createEOperation_in_EContainingClass(m_executionFactory_EClass, EXECUTIONFACTORY_EOPERATION_ADDPRIMITIVEBEHAVIORPROTOTYPE_OPAQUEBEHAVIOREXECUTION);
	m_executionFactory_EOperation_assignStrategy_SemanticStrategy = factory->createEOperation_in_EContainingClass(m_executionFactory_EClass, EXECUTIONFACTORY_EOPERATION_ASSIGNSTRATEGY_SEMANTICSTRATEGY);
	m_executionFactory_EOperation_createEvaluation_ValueSpecification = factory->createEOperation_in_EContainingClass(m_executionFactory_EClass, EXECUTIONFACTORY_EOPERATION_CREATEEVALUATION_VALUESPECIFICATION);
	m_executionFactory_EOperation_createExecution_Behavior_Object = factory->createEOperation_in_EContainingClass(m_executionFactory_EClass, EXECUTIONFACTORY_EOPERATION_CREATEEXECUTION_BEHAVIOR_OBJECT);
	m_executionFactory_EOperation_getBuiltInType_EString = factory->createEOperation_in_EContainingClass(m_executionFactory_EClass, EXECUTIONFACTORY_EOPERATION_GETBUILTINTYPE_ESTRING);
	m_executionFactory_EOperation_getStrategy_EString = factory->createEOperation_in_EContainingClass(m_executionFactory_EClass, EXECUTIONFACTORY_EOPERATION_GETSTRATEGY_ESTRING);
	m_executionFactory_EOperation_getStrategyIndex_EString = factory->createEOperation_in_EContainingClass(m_executionFactory_EClass, EXECUTIONFACTORY_EOPERATION_GETSTRATEGYINDEX_ESTRING);
	m_executionFactory_EOperation_instantiateOpaqueBehaviorExecution_OpaqueBehavior = factory->createEOperation_in_EContainingClass(m_executionFactory_EClass, EXECUTIONFACTORY_EOPERATION_INSTANTIATEOPAQUEBEHAVIOREXECUTION_OPAQUEBEHAVIOR);
	m_executionFactory_EOperation_instantiateVisitor_Element = factory->createEOperation_in_EContainingClass(m_executionFactory_EClass, EXECUTIONFACTORY_EOPERATION_INSTANTIATEVISITOR_ELEMENT);
	
}

void FUMLPackageImpl::createExecutionFactoryL1Content(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_executionFactoryL1_EClass = factory->createEClass_in_EPackage(package, EXECUTIONFACTORYL1_ECLASS);
	
	
	m_executionFactoryL1_EOperation_instantiateVisitor_Element = factory->createEOperation_in_EContainingClass(m_executionFactoryL1_EClass, EXECUTIONFACTORYL1_EOPERATION_INSTANTIATEVISITOR_ELEMENT);
	
}

void FUMLPackageImpl::createExecutionFactoryL2Content(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_executionFactoryL2_EClass = factory->createEClass_in_EPackage(package, EXECUTIONFACTORYL2_ECLASS);
	
	
	m_executionFactoryL2_EOperation_instantiateVisitor_Element = factory->createEOperation_in_EContainingClass(m_executionFactoryL2_EClass, EXECUTIONFACTORYL2_EOPERATION_INSTANTIATEVISITOR_ELEMENT);
	
}

void FUMLPackageImpl::createExecutionFactoryL3Content(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_executionFactoryL3_EClass = factory->createEClass_in_EPackage(package, EXECUTIONFACTORYL3_ECLASS);
	
	
	m_executionFactoryL3_EOperation_instantiateVisitor_Element = factory->createEOperation_in_EContainingClass(m_executionFactoryL3_EClass, EXECUTIONFACTORYL3_EOPERATION_INSTANTIATEVISITOR_ELEMENT);
	
}

void FUMLPackageImpl::createExecutorContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_executor_EClass = factory->createEClass_in_EPackage(package, EXECUTOR_ECLASS);
	
	m_executor_EReference_locus = factory->createEReference_in_EContainingClass(m_executor_EClass, EXECUTOR_EREFERENCE_LOCUS);
	
	m_executor_EOperation_evaluate_ValueSpecification = factory->createEOperation_in_EContainingClass(m_executor_EClass, EXECUTOR_EOPERATION_EVALUATE_VALUESPECIFICATION);
	m_executor_EOperation_execute_Behavior_ParameterValue = factory->createEOperation_in_EContainingClass(m_executor_EClass, EXECUTOR_EOPERATION_EXECUTE_BEHAVIOR_PARAMETERVALUE);
	m_executor_EOperation_start_Class_ParameterValue = factory->createEOperation_in_EContainingClass(m_executor_EClass, EXECUTOR_EOPERATION_START_CLASS_PARAMETERVALUE);
	
}

void FUMLPackageImpl::createExpansionActivationGroupContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_expansionActivationGroup_EClass = factory->createEClass_in_EPackage(package, EXPANSIONACTIVATIONGROUP_ECLASS);
	
	m_expansionActivationGroup_EReference_regionActivation = factory->createEReference_in_EContainingClass(m_expansionActivationGroup_EClass, EXPANSIONACTIVATIONGROUP_EREFERENCE_REGIONACTIVATION);
	
	
}

void FUMLPackageImpl::createExpansionNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_expansionNodeActivation_EClass = factory->createEClass_in_EPackage(package, EXPANSIONNODEACTIVATION_ECLASS);
	
	
	m_expansionNodeActivation_EOperation_getExpansionRegionActivation = factory->createEOperation_in_EContainingClass(m_expansionNodeActivation_EClass, EXPANSIONNODEACTIVATION_EOPERATION_GETEXPANSIONREGIONACTIVATION);
	
}

void FUMLPackageImpl::createExpansionRegionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_expansionRegionActivation_EClass = factory->createEClass_in_EPackage(package, EXPANSIONREGIONACTIVATION_ECLASS);
	
	m_expansionRegionActivation_EReference_activationGroups = factory->createEReference_in_EContainingClass(m_expansionRegionActivation_EClass, EXPANSIONREGIONACTIVATION_EREFERENCE_ACTIVATIONGROUPS);
	m_expansionRegionActivation_EReference_inputExpansionTokens = factory->createEReference_in_EContainingClass(m_expansionRegionActivation_EClass, EXPANSIONREGIONACTIVATION_EREFERENCE_INPUTEXPANSIONTOKENS);
	m_expansionRegionActivation_EReference_inputTokens = factory->createEReference_in_EContainingClass(m_expansionRegionActivation_EClass, EXPANSIONREGIONACTIVATION_EREFERENCE_INPUTTOKENS);
	
	m_expansionRegionActivation_EOperation_doStructuredActivity = factory->createEOperation_in_EContainingClass(m_expansionRegionActivation_EClass, EXPANSIONREGIONACTIVATION_EOPERATION_DOSTRUCTUREDACTIVITY);
	m_expansionRegionActivation_EOperation_getExpansionNodeActivation_ExpansionNode = factory->createEOperation_in_EContainingClass(m_expansionRegionActivation_EClass, EXPANSIONREGIONACTIVATION_EOPERATION_GETEXPANSIONNODEACTIVATION_EXPANSIONNODE);
	m_expansionRegionActivation_EOperation_numberOfValues = factory->createEOperation_in_EContainingClass(m_expansionRegionActivation_EClass, EXPANSIONREGIONACTIVATION_EOPERATION_NUMBEROFVALUES);
	m_expansionRegionActivation_EOperation_runGroup_ExpansionActivationGroup = factory->createEOperation_in_EContainingClass(m_expansionRegionActivation_EClass, EXPANSIONREGIONACTIVATION_EOPERATION_RUNGROUP_EXPANSIONACTIVATIONGROUP);
	
}

void FUMLPackageImpl::createExtensionalValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_extensionalValue_EClass = factory->createEClass_in_EPackage(package, EXTENSIONALVALUE_ECLASS);
	
	m_extensionalValue_EReference_locus = factory->createEReference_in_EContainingClass(m_extensionalValue_EClass, EXTENSIONALVALUE_EREFERENCE_LOCUS);
	
	m_extensionalValue_EOperation_destroy = factory->createEOperation_in_EContainingClass(m_extensionalValue_EClass, EXTENSIONALVALUE_EOPERATION_DESTROY);
	
}

void FUMLPackageImpl::createExtensionalValueListContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_extensionalValueList_EClass = factory->createEClass_in_EPackage(package, EXTENSIONALVALUELIST_ECLASS);
	
	
	m_extensionalValueList_EOperation_addValue_ExtensionalValue = factory->createEOperation_in_EContainingClass(m_extensionalValueList_EClass, EXTENSIONALVALUELIST_EOPERATION_ADDVALUE_EXTENSIONALVALUE);
	m_extensionalValueList_EOperation_addValue_ExtensionalValue_EInt = factory->createEOperation_in_EContainingClass(m_extensionalValueList_EClass, EXTENSIONALVALUELIST_EOPERATION_ADDVALUE_EXTENSIONALVALUE_EINT);
	m_extensionalValueList_EOperation_getValue = factory->createEOperation_in_EContainingClass(m_extensionalValueList_EClass, EXTENSIONALVALUELIST_EOPERATION_GETVALUE);
	m_extensionalValueList_EOperation_removeValue_EInt = factory->createEOperation_in_EContainingClass(m_extensionalValueList_EClass, EXTENSIONALVALUELIST_EOPERATION_REMOVEVALUE_EINT);
	m_extensionalValueList_EOperation_setValue_ExtensionalValue_EInt = factory->createEOperation_in_EContainingClass(m_extensionalValueList_EClass, EXTENSIONALVALUELIST_EOPERATION_SETVALUE_EXTENSIONALVALUE_EINT);
	
}

void FUMLPackageImpl::createFIFOGetNextEventStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_fIFOGetNextEventStrategy_EClass = factory->createEClass_in_EPackage(package, FIFOGETNEXTEVENTSTRATEGY_ECLASS);
	
	
	
}

void FUMLPackageImpl::createFeatureValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_featureValue_EClass = factory->createEClass_in_EPackage(package, FEATUREVALUE_ECLASS);
	m_featureValue_EAttribute_position = factory->createEAttribute_in_EContainingClass(m_featureValue_EClass, FEATUREVALUE_EATTRIBUTE_POSITION);
	
	m_featureValue_EReference_feature = factory->createEReference_in_EContainingClass(m_featureValue_EClass, FEATUREVALUE_EREFERENCE_FEATURE);
	m_featureValue_EReference_values = factory->createEReference_in_EContainingClass(m_featureValue_EClass, FEATUREVALUE_EREFERENCE_VALUES);
	
	m_featureValue_EOperation_hasEqualValues_FeatureValue = factory->createEOperation_in_EContainingClass(m_featureValue_EClass, FEATUREVALUE_EOPERATION_HASEQUALVALUES_FEATUREVALUE);
	
}

void FUMLPackageImpl::createFirstChoiceStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_firstChoiceStrategy_EClass = factory->createEClass_in_EPackage(package, FIRSTCHOICESTRATEGY_ECLASS);
	
	
	m_firstChoiceStrategy_EOperation_choose_EInt = factory->createEOperation_in_EContainingClass(m_firstChoiceStrategy_EClass, FIRSTCHOICESTRATEGY_EOPERATION_CHOOSE_EINT);
	
}

void FUMLPackageImpl::createFlowFinalNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_flowFinalNodeActivation_EClass = factory->createEClass_in_EPackage(package, FLOWFINALNODEACTIVATION_ECLASS);
	
	
	
}

void FUMLPackageImpl::createForkNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_forkNodeActivation_EClass = factory->createEClass_in_EPackage(package, FORKNODEACTIVATION_ECLASS);
	
	
	m_forkNodeActivation_EOperation_fire_Token = factory->createEOperation_in_EContainingClass(m_forkNodeActivation_EClass, FORKNODEACTIVATION_EOPERATION_FIRE_TOKEN);
	m_forkNodeActivation_EOperation_terminate = factory->createEOperation_in_EContainingClass(m_forkNodeActivation_EClass, FORKNODEACTIVATION_EOPERATION_TERMINATE);
	
}

void FUMLPackageImpl::createForkedTokenContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_forkedToken_EClass = factory->createEClass_in_EPackage(package, FORKEDTOKEN_ECLASS);
	m_forkedToken_EAttribute_baseTokenIsWithdrawn = factory->createEAttribute_in_EContainingClass(m_forkedToken_EClass, FORKEDTOKEN_EATTRIBUTE_BASETOKENISWITHDRAWN);
	m_forkedToken_EAttribute_remainingOffersCount = factory->createEAttribute_in_EContainingClass(m_forkedToken_EClass, FORKEDTOKEN_EATTRIBUTE_REMAININGOFFERSCOUNT);
	
	m_forkedToken_EReference_baseToken = factory->createEReference_in_EContainingClass(m_forkedToken_EClass, FORKEDTOKEN_EREFERENCE_BASETOKEN);
	
	m_forkedToken_EOperation_equals_Token = factory->createEOperation_in_EContainingClass(m_forkedToken_EClass, FORKEDTOKEN_EOPERATION_EQUALS_TOKEN);
	m_forkedToken_EOperation_getValue = factory->createEOperation_in_EContainingClass(m_forkedToken_EClass, FORKEDTOKEN_EOPERATION_GETVALUE);
	m_forkedToken_EOperation_isControl = factory->createEOperation_in_EContainingClass(m_forkedToken_EClass, FORKEDTOKEN_EOPERATION_ISCONTROL);
	m_forkedToken_EOperation_withdraw = factory->createEOperation_in_EContainingClass(m_forkedToken_EClass, FORKEDTOKEN_EOPERATION_WITHDRAW);
	
}

void FUMLPackageImpl::createGetNextEventStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_getNextEventStrategy_EClass = factory->createEClass_in_EPackage(package, GETNEXTEVENTSTRATEGY_ECLASS);
	
	
	m_getNextEventStrategy_EOperation_retrieveNextEvent_ObjectActivation = factory->createEOperation_in_EContainingClass(m_getNextEventStrategy_EClass, GETNEXTEVENTSTRATEGY_EOPERATION_RETRIEVENEXTEVENT_OBJECTACTIVATION);
	
}

void FUMLPackageImpl::createInitialNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_initialNodeActivation_EClass = factory->createEClass_in_EPackage(package, INITIALNODEACTIVATION_ECLASS);
	
	
	m_initialNodeActivation_EOperation_fire_Token = factory->createEOperation_in_EContainingClass(m_initialNodeActivation_EClass, INITIALNODEACTIVATION_EOPERATION_FIRE_TOKEN);
	
}

void FUMLPackageImpl::createInputPinActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_inputPinActivation_EClass = factory->createEClass_in_EPackage(package, INPUTPINACTIVATION_ECLASS);
	
	
	m_inputPinActivation_EOperation_isReady = factory->createEOperation_in_EContainingClass(m_inputPinActivation_EClass, INPUTPINACTIVATION_EOPERATION_ISREADY);
	m_inputPinActivation_EOperation_recieveOffer = factory->createEOperation_in_EContainingClass(m_inputPinActivation_EClass, INPUTPINACTIVATION_EOPERATION_RECIEVEOFFER);
	
}

void FUMLPackageImpl::createInstanceValueEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_instanceValueEvaluation_EClass = factory->createEClass_in_EPackage(package, INSTANCEVALUEEVALUATION_ECLASS);
	
	
	m_instanceValueEvaluation_EOperation_evaluate = factory->createEOperation_in_EContainingClass(m_instanceValueEvaluation_EClass, INSTANCEVALUEEVALUATION_EOPERATION_EVALUATE);
	
}

void FUMLPackageImpl::createIntegerValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_integerValue_EClass = factory->createEClass_in_EPackage(package, INTEGERVALUE_ECLASS);
	m_integerValue_EAttribute_value = factory->createEAttribute_in_EContainingClass(m_integerValue_EClass, INTEGERVALUE_EATTRIBUTE_VALUE);
	
	
	m_integerValue_EOperation_equals_Value = factory->createEOperation_in_EContainingClass(m_integerValue_EClass, INTEGERVALUE_EOPERATION_EQUALS_VALUE);
	m_integerValue_EOperation_specify = factory->createEOperation_in_EContainingClass(m_integerValue_EClass, INTEGERVALUE_EOPERATION_SPECIFY);
	m_integerValue_EOperation_toString = factory->createEOperation_in_EContainingClass(m_integerValue_EClass, INTEGERVALUE_EOPERATION_TOSTRING);
	
}

void FUMLPackageImpl::createInvocationActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_invocationActionActivation_EClass = factory->createEClass_in_EPackage(package, INVOCATIONACTIONACTIVATION_ECLASS);
	
	
	
}

void FUMLPackageImpl::createJoinNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_joinNodeActivation_EClass = factory->createEClass_in_EPackage(package, JOINNODEACTIVATION_ECLASS);
	
	
	m_joinNodeActivation_EOperation_isReady = factory->createEOperation_in_EContainingClass(m_joinNodeActivation_EClass, JOINNODEACTIVATION_EOPERATION_ISREADY);
	
}

void FUMLPackageImpl::createLinkContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_link_EClass = factory->createEClass_in_EPackage(package, LINK_ECLASS);
	
	m_link_EReference_type = factory->createEReference_in_EContainingClass(m_link_EClass, LINK_EREFERENCE_TYPE);
	
	m_link_EOperation_addTo_Locus = factory->createEOperation_in_EContainingClass(m_link_EClass, LINK_EOPERATION_ADDTO_LOCUS);
	m_link_EOperation_getOtherFeatureValues_ExtensionalValue_Property = factory->createEOperation_in_EContainingClass(m_link_EClass, LINK_EOPERATION_GETOTHERFEATUREVALUES_EXTENSIONALVALUE_PROPERTY);
	m_link_EOperation_getTypes = factory->createEOperation_in_EContainingClass(m_link_EClass, LINK_EOPERATION_GETTYPES);
	m_link_EOperation_isMatchingLink_ExtensionalValue_Property = factory->createEOperation_in_EContainingClass(m_link_EClass, LINK_EOPERATION_ISMATCHINGLINK_EXTENSIONALVALUE_PROPERTY);
	
}

void FUMLPackageImpl::createLinkActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_linkActionActivation_EClass = factory->createEClass_in_EPackage(package, LINKACTIONACTIVATION_ECLASS);
	
	
	m_linkActionActivation_EOperation_endMatchesEndData_Link_LinkEndData = factory->createEOperation_in_EContainingClass(m_linkActionActivation_EClass, LINKACTIONACTIVATION_EOPERATION_ENDMATCHESENDDATA_LINK_LINKENDDATA);
	m_linkActionActivation_EOperation_getAssociation = factory->createEOperation_in_EContainingClass(m_linkActionActivation_EClass, LINKACTIONACTIVATION_EOPERATION_GETASSOCIATION);
	m_linkActionActivation_EOperation_linkMatchesEndData_Link_LinkEndData = factory->createEOperation_in_EContainingClass(m_linkActionActivation_EClass, LINKACTIONACTIVATION_EOPERATION_LINKMATCHESENDDATA_LINK_LINKENDDATA);
	
}

void FUMLPackageImpl::createLiteralBooleanEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalBooleanEvaluation_EClass = factory->createEClass_in_EPackage(package, LITERALBOOLEANEVALUATION_ECLASS);
	
	
	m_literalBooleanEvaluation_EOperation_evaluate = factory->createEOperation_in_EContainingClass(m_literalBooleanEvaluation_EClass, LITERALBOOLEANEVALUATION_EOPERATION_EVALUATE);
	
}

void FUMLPackageImpl::createLiteralEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalEvaluation_EClass = factory->createEClass_in_EPackage(package, LITERALEVALUATION_ECLASS);
	
	
	m_literalEvaluation_EOperation_getType_EString = factory->createEOperation_in_EContainingClass(m_literalEvaluation_EClass, LITERALEVALUATION_EOPERATION_GETTYPE_ESTRING);
	
}

void FUMLPackageImpl::createLiteralIntegerEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalIntegerEvaluation_EClass = factory->createEClass_in_EPackage(package, LITERALINTEGEREVALUATION_ECLASS);
	
	
	m_literalIntegerEvaluation_EOperation_evaluate = factory->createEOperation_in_EContainingClass(m_literalIntegerEvaluation_EClass, LITERALINTEGEREVALUATION_EOPERATION_EVALUATE);
	
}

void FUMLPackageImpl::createLiteralNullEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalNullEvaluation_EClass = factory->createEClass_in_EPackage(package, LITERALNULLEVALUATION_ECLASS);
	
	
	m_literalNullEvaluation_EOperation_evaluate = factory->createEOperation_in_EContainingClass(m_literalNullEvaluation_EClass, LITERALNULLEVALUATION_EOPERATION_EVALUATE);
	
}

void FUMLPackageImpl::createLiteralRealEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalRealEvaluation_EClass = factory->createEClass_in_EPackage(package, LITERALREALEVALUATION_ECLASS);
	
	
	m_literalRealEvaluation_EOperation_evaluate = factory->createEOperation_in_EContainingClass(m_literalRealEvaluation_EClass, LITERALREALEVALUATION_EOPERATION_EVALUATE);
	
}

void FUMLPackageImpl::createLiteralStringEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalStringEvaluation_EClass = factory->createEClass_in_EPackage(package, LITERALSTRINGEVALUATION_ECLASS);
	
	
	m_literalStringEvaluation_EOperation_evaluate = factory->createEOperation_in_EContainingClass(m_literalStringEvaluation_EClass, LITERALSTRINGEVALUATION_EOPERATION_EVALUATE);
	
}

void FUMLPackageImpl::createLiteralUnlimitedNaturalEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalUnlimitedNaturalEvaluation_EClass = factory->createEClass_in_EPackage(package, LITERALUNLIMITEDNATURALEVALUATION_ECLASS);
	
	
	m_literalUnlimitedNaturalEvaluation_EOperation_evaluate = factory->createEOperation_in_EContainingClass(m_literalUnlimitedNaturalEvaluation_EClass, LITERALUNLIMITEDNATURALEVALUATION_EOPERATION_EVALUATE);
	
}

void FUMLPackageImpl::createLocusContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_locus_EClass = factory->createEClass_in_EPackage(package, LOCUS_ECLASS);
	
	m_locus_EReference_executor = factory->createEReference_in_EContainingClass(m_locus_EClass, LOCUS_EREFERENCE_EXECUTOR);
	m_locus_EReference_extensionalValues = factory->createEReference_in_EContainingClass(m_locus_EClass, LOCUS_EREFERENCE_EXTENSIONALVALUES);
	m_locus_EReference_factory = factory->createEReference_in_EContainingClass(m_locus_EClass, LOCUS_EREFERENCE_FACTORY);
	
	m_locus_EOperation_add_ExtensionalValue = factory->createEOperation_in_EContainingClass(m_locus_EClass, LOCUS_EOPERATION_ADD_EXTENSIONALVALUE);
	m_locus_EOperation_assignExecutor_Executor = factory->createEOperation_in_EContainingClass(m_locus_EClass, LOCUS_EOPERATION_ASSIGNEXECUTOR_EXECUTOR);
	m_locus_EOperation_assignFactory_ExecutionFactory = factory->createEOperation_in_EContainingClass(m_locus_EClass, LOCUS_EOPERATION_ASSIGNFACTORY_EXECUTIONFACTORY);
	m_locus_EOperation_conforms_Classifier_Classifier = factory->createEOperation_in_EContainingClass(m_locus_EClass, LOCUS_EOPERATION_CONFORMS_CLASSIFIER_CLASSIFIER);
	m_locus_EOperation_instantiate_Class = factory->createEOperation_in_EContainingClass(m_locus_EClass, LOCUS_EOPERATION_INSTANTIATE_CLASS);
	m_locus_EOperation_remove_ExtensionalValue = factory->createEOperation_in_EContainingClass(m_locus_EClass, LOCUS_EOPERATION_REMOVE_EXTENSIONALVALUE);
	m_locus_EOperation_retrieveExtent_Classifier = factory->createEOperation_in_EContainingClass(m_locus_EClass, LOCUS_EOPERATION_RETRIEVEEXTENT_CLASSIFIER);
	
}

void FUMLPackageImpl::createLoopNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_loopNodeActivation_EClass = factory->createEClass_in_EPackage(package, LOOPNODEACTIVATION_ECLASS);
	
	m_loopNodeActivation_EReference_bodyOutputLists = factory->createEReference_in_EContainingClass(m_loopNodeActivation_EClass, LOOPNODEACTIVATION_EREFERENCE_BODYOUTPUTLISTS);
	
	m_loopNodeActivation_EOperation_makeLoopVariableList = factory->createEOperation_in_EContainingClass(m_loopNodeActivation_EClass, LOOPNODEACTIVATION_EOPERATION_MAKELOOPVARIABLELIST);
	m_loopNodeActivation_EOperation_runBody = factory->createEOperation_in_EContainingClass(m_loopNodeActivation_EClass, LOOPNODEACTIVATION_EOPERATION_RUNBODY);
	m_loopNodeActivation_EOperation_runLoopVariables = factory->createEOperation_in_EContainingClass(m_loopNodeActivation_EClass, LOOPNODEACTIVATION_EOPERATION_RUNLOOPVARIABLES);
	m_loopNodeActivation_EOperation_runTest = factory->createEOperation_in_EContainingClass(m_loopNodeActivation_EClass, LOOPNODEACTIVATION_EOPERATION_RUNTEST);
	
}

void FUMLPackageImpl::createMergeNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_mergeNodeActivation_EClass = factory->createEClass_in_EPackage(package, MERGENODEACTIVATION_ECLASS);
	
	
	
}

void FUMLPackageImpl::createObjectContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_object_EClass = factory->createEClass_in_EPackage(package, OBJECT_ECLASS);
	
	m_object_EReference_objectActivation = factory->createEReference_in_EContainingClass(m_object_EClass, OBJECT_EREFERENCE_OBJECTACTIVATION);
	m_object_EReference_types = factory->createEReference_in_EContainingClass(m_object_EClass, OBJECT_EREFERENCE_TYPES);
	
	m_object_EOperation__register_EventAccepter = factory->createEOperation_in_EContainingClass(m_object_EClass, OBJECT_EOPERATION__REGISTER_EVENTACCEPTER);
	m_object_EOperation_destroy = factory->createEOperation_in_EContainingClass(m_object_EClass, OBJECT_EOPERATION_DESTROY);
	m_object_EOperation_dispatch_Operation = factory->createEOperation_in_EContainingClass(m_object_EClass, OBJECT_EOPERATION_DISPATCH_OPERATION);
	m_object_EOperation_new_ = factory->createEOperation_in_EContainingClass(m_object_EClass, OBJECT_EOPERATION_NEW_);
	m_object_EOperation_send_SignalInstance = factory->createEOperation_in_EContainingClass(m_object_EClass, OBJECT_EOPERATION_SEND_SIGNALINSTANCE);
	m_object_EOperation_startBehavior_Class_ParameterValue = factory->createEOperation_in_EContainingClass(m_object_EClass, OBJECT_EOPERATION_STARTBEHAVIOR_CLASS_PARAMETERVALUE);
	m_object_EOperation_unregister_EventAccepter = factory->createEOperation_in_EContainingClass(m_object_EClass, OBJECT_EOPERATION_UNREGISTER_EVENTACCEPTER);
	
}

void FUMLPackageImpl::createObjectActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_objectActivation_EClass = factory->createEClass_in_EPackage(package, OBJECTACTIVATION_ECLASS);
	
	m_objectActivation_EReference_classifierBehaviorExecutions = factory->createEReference_in_EContainingClass(m_objectActivation_EClass, OBJECTACTIVATION_EREFERENCE_CLASSIFIERBEHAVIOREXECUTIONS);
	m_objectActivation_EReference_eventPool = factory->createEReference_in_EContainingClass(m_objectActivation_EClass, OBJECTACTIVATION_EREFERENCE_EVENTPOOL);
	m_objectActivation_EReference_object = factory->createEReference_in_EContainingClass(m_objectActivation_EClass, OBJECTACTIVATION_EREFERENCE_OBJECT);
	m_objectActivation_EReference_waitingEventAccepters = factory->createEReference_in_EContainingClass(m_objectActivation_EClass, OBJECTACTIVATION_EREFERENCE_WAITINGEVENTACCEPTERS);
	
	m_objectActivation_EOperation__register_EventAccepter = factory->createEOperation_in_EContainingClass(m_objectActivation_EClass, OBJECTACTIVATION_EOPERATION__REGISTER_EVENTACCEPTER);
	m_objectActivation_EOperation__send_EJavaObject = factory->createEOperation_in_EContainingClass(m_objectActivation_EClass, OBJECTACTIVATION_EOPERATION__SEND_EJAVAOBJECT);
	m_objectActivation_EOperation__startObjectBehavior = factory->createEOperation_in_EContainingClass(m_objectActivation_EClass, OBJECTACTIVATION_EOPERATION__STARTOBJECTBEHAVIOR);
	m_objectActivation_EOperation_dispatchNextEvent = factory->createEOperation_in_EContainingClass(m_objectActivation_EClass, OBJECTACTIVATION_EOPERATION_DISPATCHNEXTEVENT);
	m_objectActivation_EOperation_retrieveNextEvent = factory->createEOperation_in_EContainingClass(m_objectActivation_EClass, OBJECTACTIVATION_EOPERATION_RETRIEVENEXTEVENT);
	m_objectActivation_EOperation_send_SignalInstance = factory->createEOperation_in_EContainingClass(m_objectActivation_EClass, OBJECTACTIVATION_EOPERATION_SEND_SIGNALINSTANCE);
	m_objectActivation_EOperation_startBehavior_Class_ParameterValue = factory->createEOperation_in_EContainingClass(m_objectActivation_EClass, OBJECTACTIVATION_EOPERATION_STARTBEHAVIOR_CLASS_PARAMETERVALUE);
	m_objectActivation_EOperation_stop = factory->createEOperation_in_EContainingClass(m_objectActivation_EClass, OBJECTACTIVATION_EOPERATION_STOP);
	m_objectActivation_EOperation_unregister_EventAccepter = factory->createEOperation_in_EContainingClass(m_objectActivation_EClass, OBJECTACTIVATION_EOPERATION_UNREGISTER_EVENTACCEPTER);
	
}

void FUMLPackageImpl::createObjectNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_objectNodeActivation_EClass = factory->createEClass_in_EPackage(package, OBJECTNODEACTIVATION_ECLASS);
	m_objectNodeActivation_EAttribute_offeredTokenCount = factory->createEAttribute_in_EContainingClass(m_objectNodeActivation_EClass, OBJECTNODEACTIVATION_EATTRIBUTE_OFFEREDTOKENCOUNT);
	
	
	m_objectNodeActivation_EOperation_addToken_Token = factory->createEOperation_in_EContainingClass(m_objectNodeActivation_EClass, OBJECTNODEACTIVATION_EOPERATION_ADDTOKEN_TOKEN);
	m_objectNodeActivation_EOperation_clearTokens = factory->createEOperation_in_EContainingClass(m_objectNodeActivation_EClass, OBJECTNODEACTIVATION_EOPERATION_CLEARTOKENS);
	m_objectNodeActivation_EOperation_countOfferedValues = factory->createEOperation_in_EContainingClass(m_objectNodeActivation_EClass, OBJECTNODEACTIVATION_EOPERATION_COUNTOFFEREDVALUES);
	m_objectNodeActivation_EOperation_countUnofferedTokens = factory->createEOperation_in_EContainingClass(m_objectNodeActivation_EClass, OBJECTNODEACTIVATION_EOPERATION_COUNTUNOFFEREDTOKENS);
	m_objectNodeActivation_EOperation_getUnofferedTokens = factory->createEOperation_in_EContainingClass(m_objectNodeActivation_EClass, OBJECTNODEACTIVATION_EOPERATION_GETUNOFFEREDTOKENS);
	m_objectNodeActivation_EOperation_removeToken_Token = factory->createEOperation_in_EContainingClass(m_objectNodeActivation_EClass, OBJECTNODEACTIVATION_EOPERATION_REMOVETOKEN_TOKEN);
	m_objectNodeActivation_EOperation_run = factory->createEOperation_in_EContainingClass(m_objectNodeActivation_EClass, OBJECTNODEACTIVATION_EOPERATION_RUN);
	m_objectNodeActivation_EOperation_sendOffers_Token = factory->createEOperation_in_EContainingClass(m_objectNodeActivation_EClass, OBJECTNODEACTIVATION_EOPERATION_SENDOFFERS_TOKEN);
	m_objectNodeActivation_EOperation_sendUnofferedTokens = factory->createEOperation_in_EContainingClass(m_objectNodeActivation_EClass, OBJECTNODEACTIVATION_EOPERATION_SENDUNOFFEREDTOKENS);
	m_objectNodeActivation_EOperation_takeUnofferedTokens = factory->createEOperation_in_EContainingClass(m_objectNodeActivation_EClass, OBJECTNODEACTIVATION_EOPERATION_TAKEUNOFFEREDTOKENS);
	m_objectNodeActivation_EOperation_terminate = factory->createEOperation_in_EContainingClass(m_objectNodeActivation_EClass, OBJECTNODEACTIVATION_EOPERATION_TERMINATE);
	
}

void FUMLPackageImpl::createObjectTokenContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_objectToken_EClass = factory->createEClass_in_EPackage(package, OBJECTTOKEN_ECLASS);
	
	m_objectToken_EReference_value = factory->createEReference_in_EContainingClass(m_objectToken_EClass, OBJECTTOKEN_EREFERENCE_VALUE);
	
	m_objectToken_EOperation_equals_Token = factory->createEOperation_in_EContainingClass(m_objectToken_EClass, OBJECTTOKEN_EOPERATION_EQUALS_TOKEN);
	m_objectToken_EOperation_isControl = factory->createEOperation_in_EContainingClass(m_objectToken_EClass, OBJECTTOKEN_EOPERATION_ISCONTROL);
	
}

void FUMLPackageImpl::createOfferContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_offer_EClass = factory->createEClass_in_EPackage(package, OFFER_ECLASS);
	
	m_offer_EReference_offeredTokens = factory->createEReference_in_EContainingClass(m_offer_EClass, OFFER_EREFERENCE_OFFEREDTOKENS);
	
	m_offer_EOperation_countOfferedVales = factory->createEOperation_in_EContainingClass(m_offer_EClass, OFFER_EOPERATION_COUNTOFFEREDVALES);
	m_offer_EOperation_hasTokens = factory->createEOperation_in_EContainingClass(m_offer_EClass, OFFER_EOPERATION_HASTOKENS);
	m_offer_EOperation_removeOfferedValues_EInt = factory->createEOperation_in_EContainingClass(m_offer_EClass, OFFER_EOPERATION_REMOVEOFFEREDVALUES_EINT);
	m_offer_EOperation_removeWithdrawnTokens = factory->createEOperation_in_EContainingClass(m_offer_EClass, OFFER_EOPERATION_REMOVEWITHDRAWNTOKENS);
	m_offer_EOperation_retrieveOfferedTokens = factory->createEOperation_in_EContainingClass(m_offer_EClass, OFFER_EOPERATION_RETRIEVEOFFEREDTOKENS);
	
}

void FUMLPackageImpl::createOpaqueBehaviorExecutionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_opaqueBehaviorExecution_EClass = factory->createEClass_in_EPackage(package, OPAQUEBEHAVIOREXECUTION_ECLASS);
	
	
	m_opaqueBehaviorExecution_EOperation_doBody_ParameterValue_ParameterValue = factory->createEOperation_in_EContainingClass(m_opaqueBehaviorExecution_EClass, OPAQUEBEHAVIOREXECUTION_EOPERATION_DOBODY_PARAMETERVALUE_PARAMETERVALUE);
	m_opaqueBehaviorExecution_EOperation_execute = factory->createEOperation_in_EContainingClass(m_opaqueBehaviorExecution_EClass, OPAQUEBEHAVIOREXECUTION_EOPERATION_EXECUTE);
	
}

void FUMLPackageImpl::createOutputPinActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_outputPinActivation_EClass = factory->createEClass_in_EPackage(package, OUTPUTPINACTIVATION_ECLASS);
	
	
	
}

void FUMLPackageImpl::createParameterValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_parameterValue_EClass = factory->createEClass_in_EPackage(package, PARAMETERVALUE_ECLASS);
	
	m_parameterValue_EReference_parameter = factory->createEReference_in_EContainingClass(m_parameterValue_EClass, PARAMETERVALUE_EREFERENCE_PARAMETER);
	m_parameterValue_EReference_values = factory->createEReference_in_EContainingClass(m_parameterValue_EClass, PARAMETERVALUE_EREFERENCE_VALUES);
	
	
}

void FUMLPackageImpl::createPinActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_pinActivation_EClass = factory->createEClass_in_EPackage(package, PINACTIVATION_ECLASS);
	
	m_pinActivation_EReference_actionActivation = factory->createEReference_in_EContainingClass(m_pinActivation_EClass, PINACTIVATION_EREFERENCE_ACTIONACTIVATION);
	
	m_pinActivation_EOperation_fire_Token = factory->createEOperation_in_EContainingClass(m_pinActivation_EClass, PINACTIVATION_EOPERATION_FIRE_TOKEN);
	m_pinActivation_EOperation_takeOfferedTokens = factory->createEOperation_in_EContainingClass(m_pinActivation_EClass, PINACTIVATION_EOPERATION_TAKEOFFEREDTOKENS);
	
}

void FUMLPackageImpl::createPrimitiveValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_primitiveValue_EClass = factory->createEClass_in_EPackage(package, PRIMITIVEVALUE_ECLASS);
	
	m_primitiveValue_EReference_type = factory->createEReference_in_EContainingClass(m_primitiveValue_EClass, PRIMITIVEVALUE_EREFERENCE_TYPE);
	
	m_primitiveValue_EOperation_getTypes = factory->createEOperation_in_EContainingClass(m_primitiveValue_EClass, PRIMITIVEVALUE_EOPERATION_GETTYPES);
	
}

void FUMLPackageImpl::createReadExtentActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_readExtentActionActivation_EClass = factory->createEClass_in_EPackage(package, READEXTENTACTIONACTIVATION_ECLASS);
	
	
	
}

void FUMLPackageImpl::createReadIsClassifiedObjectActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_readIsClassifiedObjectActionActivation_EClass = factory->createEClass_in_EPackage(package, READISCLASSIFIEDOBJECTACTIONACTIVATION_ECLASS);
	
	
	m_readIsClassifiedObjectActionActivation_EOperation_checkAllParents_Classifier_Classifier = factory->createEOperation_in_EContainingClass(m_readIsClassifiedObjectActionActivation_EClass, READISCLASSIFIEDOBJECTACTIONACTIVATION_EOPERATION_CHECKALLPARENTS_CLASSIFIER_CLASSIFIER);
	
}

void FUMLPackageImpl::createReadLinkActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_readLinkActionActivation_EClass = factory->createEClass_in_EPackage(package, READLINKACTIONACTIVATION_ECLASS);
	
	
	
}

void FUMLPackageImpl::createReadSelfActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_readSelfActionActivation_EClass = factory->createEClass_in_EPackage(package, READSELFACTIONACTIVATION_ECLASS);
	
	
	
}

void FUMLPackageImpl::createReadStructuralFeatureActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_readStructuralFeatureActionActivation_EClass = factory->createEClass_in_EPackage(package, READSTRUCTURALFEATUREACTIONACTIVATION_ECLASS);
	
	
	
}

void FUMLPackageImpl::createRealValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_realValue_EClass = factory->createEClass_in_EPackage(package, REALVALUE_ECLASS);
	m_realValue_EAttribute_value = factory->createEAttribute_in_EContainingClass(m_realValue_EClass, REALVALUE_EATTRIBUTE_VALUE);
	
	
	m_realValue_EOperation_equals_Value = factory->createEOperation_in_EContainingClass(m_realValue_EClass, REALVALUE_EOPERATION_EQUALS_VALUE);
	m_realValue_EOperation_specify = factory->createEOperation_in_EContainingClass(m_realValue_EClass, REALVALUE_EOPERATION_SPECIFY);
	m_realValue_EOperation_toString = factory->createEOperation_in_EContainingClass(m_realValue_EClass, REALVALUE_EOPERATION_TOSTRING);
	
}

void FUMLPackageImpl::createReclassifyObjectActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_reclassifyObjectActionActivation_EClass = factory->createEClass_in_EPackage(package, RECLASSIFYOBJECTACTIONACTIVATION_ECLASS);
	
	
	
}

void FUMLPackageImpl::createRedefinitionBasedDispatchStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_redefinitionBasedDispatchStrategy_EClass = factory->createEClass_in_EPackage(package, REDEFINITIONBASEDDISPATCHSTRATEGY_ECLASS);
	
	
	m_redefinitionBasedDispatchStrategy_EOperation_operationsMatch_Operation_Operation = factory->createEOperation_in_EContainingClass(m_redefinitionBasedDispatchStrategy_EClass, REDEFINITIONBASEDDISPATCHSTRATEGY_EOPERATION_OPERATIONSMATCH_OPERATION_OPERATION);
	m_redefinitionBasedDispatchStrategy_EOperation_retrieveMethod_Object_Operation = factory->createEOperation_in_EContainingClass(m_redefinitionBasedDispatchStrategy_EClass, REDEFINITIONBASEDDISPATCHSTRATEGY_EOPERATION_RETRIEVEMETHOD_OBJECT_OPERATION);
	
}

void FUMLPackageImpl::createReduceActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_reduceActionActivation_EClass = factory->createEClass_in_EPackage(package, REDUCEACTIONACTIVATION_ECLASS);
	
	m_reduceActionActivation_EReference_currentExecution = factory->createEReference_in_EContainingClass(m_reduceActionActivation_EClass, REDUCEACTIONACTIVATION_EREFERENCE_CURRENTEXECUTION);
	
	
}

void FUMLPackageImpl::createReferenceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_reference_EClass = factory->createEClass_in_EPackage(package, REFERENCE_ECLASS);
	
	m_reference_EReference_referent = factory->createEReference_in_EContainingClass(m_reference_EClass, REFERENCE_EREFERENCE_REFERENT);
	
	m_reference_EOperation_assignFeatureValue_StructuralFeature_EInt = factory->createEOperation_in_EContainingClass(m_reference_EClass, REFERENCE_EOPERATION_ASSIGNFEATUREVALUE_STRUCTURALFEATURE_EINT);
	m_reference_EOperation_destroy = factory->createEOperation_in_EContainingClass(m_reference_EClass, REFERENCE_EOPERATION_DESTROY);
	m_reference_EOperation_dispatch_Operation = factory->createEOperation_in_EContainingClass(m_reference_EClass, REFERENCE_EOPERATION_DISPATCH_OPERATION);
	m_reference_EOperation_equals_Value = factory->createEOperation_in_EContainingClass(m_reference_EClass, REFERENCE_EOPERATION_EQUALS_VALUE);
	m_reference_EOperation_getTypes = factory->createEOperation_in_EContainingClass(m_reference_EClass, REFERENCE_EOPERATION_GETTYPES);
	m_reference_EOperation_new_ = factory->createEOperation_in_EContainingClass(m_reference_EClass, REFERENCE_EOPERATION_NEW_);
	m_reference_EOperation_retrieveFeatureValue_StructuralFeature = factory->createEOperation_in_EContainingClass(m_reference_EClass, REFERENCE_EOPERATION_RETRIEVEFEATUREVALUE_STRUCTURALFEATURE);
	m_reference_EOperation_retrieveFeatureValues = factory->createEOperation_in_EContainingClass(m_reference_EClass, REFERENCE_EOPERATION_RETRIEVEFEATUREVALUES);
	m_reference_EOperation_send_SignalInstance = factory->createEOperation_in_EContainingClass(m_reference_EClass, REFERENCE_EOPERATION_SEND_SIGNALINSTANCE);
	m_reference_EOperation_startBehavior_Class_ParameterValue = factory->createEOperation_in_EContainingClass(m_reference_EClass, REFERENCE_EOPERATION_STARTBEHAVIOR_CLASS_PARAMETERVALUE);
	m_reference_EOperation_toString = factory->createEOperation_in_EContainingClass(m_reference_EClass, REFERENCE_EOPERATION_TOSTRING);
	
}

void FUMLPackageImpl::createRemoveStructuralFeatureValueActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_removeStructuralFeatureValueActivation_EClass = factory->createEClass_in_EPackage(package, REMOVESTRUCTURALFEATUREVALUEACTIVATION_ECLASS);
	
	
	
}

void FUMLPackageImpl::createSemanticStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_semanticStrategy_EClass = factory->createEClass_in_EPackage(package, SEMANTICSTRATEGY_ECLASS);
	
	
	m_semanticStrategy_EOperation_retrieveName = factory->createEOperation_in_EContainingClass(m_semanticStrategy_EClass, SEMANTICSTRATEGY_EOPERATION_RETRIEVENAME);
	
}

void FUMLPackageImpl::createSemanticVisitorContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_semanticVisitor_EClass = factory->createEClass_in_EPackage(package, SEMANTICVISITOR_ECLASS);
	
	
	m_semanticVisitor_EOperation__beginIsolation = factory->createEOperation_in_EContainingClass(m_semanticVisitor_EClass, SEMANTICVISITOR_EOPERATION__BEGINISOLATION);
	m_semanticVisitor_EOperation__endIsolation = factory->createEOperation_in_EContainingClass(m_semanticVisitor_EClass, SEMANTICVISITOR_EOPERATION__ENDISOLATION);
	
}

void FUMLPackageImpl::createSendSignalActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_sendSignalActionActivation_EClass = factory->createEClass_in_EPackage(package, SENDSIGNALACTIONACTIVATION_ECLASS);
	
	
	m_sendSignalActionActivation_EOperation_doAction = factory->createEOperation_in_EContainingClass(m_sendSignalActionActivation_EClass, SENDSIGNALACTIONACTIVATION_EOPERATION_DOACTION);
	
}

void FUMLPackageImpl::createSignalInstanceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_signalInstance_EClass = factory->createEClass_in_EPackage(package, SIGNALINSTANCE_ECLASS);
	
	m_signalInstance_EReference_type = factory->createEReference_in_EContainingClass(m_signalInstance_EClass, SIGNALINSTANCE_EREFERENCE_TYPE);
	
	
}

void FUMLPackageImpl::createStartClassifierBehaviorActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_startClassifierBehaviorActionActivation_EClass = factory->createEClass_in_EPackage(package, STARTCLASSIFIERBEHAVIORACTIONACTIVATION_ECLASS);
	
	
	
}

void FUMLPackageImpl::createStartObjectBehaviorActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_startObjectBehaviorActionActivation_EClass = factory->createEClass_in_EPackage(package, STARTOBJECTBEHAVIORACTIONACTIVATION_ECLASS);
	
	
	
}

void FUMLPackageImpl::createStringValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_stringValue_EClass = factory->createEClass_in_EPackage(package, STRINGVALUE_ECLASS);
	m_stringValue_EAttribute_value = factory->createEAttribute_in_EContainingClass(m_stringValue_EClass, STRINGVALUE_EATTRIBUTE_VALUE);
	
	
	m_stringValue_EOperation_equals_Value = factory->createEOperation_in_EContainingClass(m_stringValue_EClass, STRINGVALUE_EOPERATION_EQUALS_VALUE);
	m_stringValue_EOperation_specify = factory->createEOperation_in_EContainingClass(m_stringValue_EClass, STRINGVALUE_EOPERATION_SPECIFY);
	m_stringValue_EOperation_toString = factory->createEOperation_in_EContainingClass(m_stringValue_EClass, STRINGVALUE_EOPERATION_TOSTRING);
	
}

void FUMLPackageImpl::createStructuralFeatureActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_structuralFeatureActionActivation_EClass = factory->createEClass_in_EPackage(package, STRUCTURALFEATUREACTIONACTIVATION_ECLASS);
	
	
	m_structuralFeatureActionActivation_EOperation_getAssociation_StructuralFeature = factory->createEOperation_in_EContainingClass(m_structuralFeatureActionActivation_EClass, STRUCTURALFEATUREACTIONACTIVATION_EOPERATION_GETASSOCIATION_STRUCTURALFEATURE);
	m_structuralFeatureActionActivation_EOperation_getMatchingLinks_Association_Value = factory->createEOperation_in_EContainingClass(m_structuralFeatureActionActivation_EClass, STRUCTURALFEATUREACTIONACTIVATION_EOPERATION_GETMATCHINGLINKS_ASSOCIATION_VALUE);
	m_structuralFeatureActionActivation_EOperation_getOppositeEnd_Association_StructuralFeature = factory->createEOperation_in_EContainingClass(m_structuralFeatureActionActivation_EClass, STRUCTURALFEATUREACTIONACTIVATION_EOPERATION_GETOPPOSITEEND_ASSOCIATION_STRUCTURALFEATURE);
	
}

void FUMLPackageImpl::createStructuredActivityNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_structuredActivityNodeActivation_EClass = factory->createEClass_in_EPackage(package, STRUCTUREDACTIVITYNODEACTIVATION_ECLASS);
	
	m_structuredActivityNodeActivation_EReference_activationGroup = factory->createEReference_in_EContainingClass(m_structuredActivityNodeActivation_EClass, STRUCTUREDACTIVITYNODEACTIVATION_EREFERENCE_ACTIVATIONGROUP);
	
	m_structuredActivityNodeActivation_EOperation_completeAction = factory->createEOperation_in_EContainingClass(m_structuredActivityNodeActivation_EClass, STRUCTUREDACTIVITYNODEACTIVATION_EOPERATION_COMPLETEACTION);
	m_structuredActivityNodeActivation_EOperation_createEdgeInstances = factory->createEOperation_in_EContainingClass(m_structuredActivityNodeActivation_EClass, STRUCTUREDACTIVITYNODEACTIVATION_EOPERATION_CREATEEDGEINSTANCES);
	m_structuredActivityNodeActivation_EOperation_createNodeActivations = factory->createEOperation_in_EContainingClass(m_structuredActivityNodeActivation_EClass, STRUCTUREDACTIVITYNODEACTIVATION_EOPERATION_CREATENODEACTIVATIONS);
	m_structuredActivityNodeActivation_EOperation_doAction = factory->createEOperation_in_EContainingClass(m_structuredActivityNodeActivation_EClass, STRUCTUREDACTIVITYNODEACTIVATION_EOPERATION_DOACTION);
	m_structuredActivityNodeActivation_EOperation_doStructuredActivity = factory->createEOperation_in_EContainingClass(m_structuredActivityNodeActivation_EClass, STRUCTUREDACTIVITYNODEACTIVATION_EOPERATION_DOSTRUCTUREDACTIVITY);
	m_structuredActivityNodeActivation_EOperation_getNodeActivation_ActivityNode = factory->createEOperation_in_EContainingClass(m_structuredActivityNodeActivation_EClass, STRUCTUREDACTIVITYNODEACTIVATION_EOPERATION_GETNODEACTIVATION_ACTIVITYNODE);
	m_structuredActivityNodeActivation_EOperation_getPinValues_OutputPin = factory->createEOperation_in_EContainingClass(m_structuredActivityNodeActivation_EClass, STRUCTUREDACTIVITYNODEACTIVATION_EOPERATION_GETPINVALUES_OUTPUTPIN);
	m_structuredActivityNodeActivation_EOperation_isSourceFor_ActivityEdgeInstance = factory->createEOperation_in_EContainingClass(m_structuredActivityNodeActivation_EClass, STRUCTUREDACTIVITYNODEACTIVATION_EOPERATION_ISSOURCEFOR_ACTIVITYEDGEINSTANCE);
	m_structuredActivityNodeActivation_EOperation_isSuspended = factory->createEOperation_in_EContainingClass(m_structuredActivityNodeActivation_EClass, STRUCTUREDACTIVITYNODEACTIVATION_EOPERATION_ISSUSPENDED);
	m_structuredActivityNodeActivation_EOperation_makeActivityNodeList_ExecutableNode = factory->createEOperation_in_EContainingClass(m_structuredActivityNodeActivation_EClass, STRUCTUREDACTIVITYNODEACTIVATION_EOPERATION_MAKEACTIVITYNODELIST_EXECUTABLENODE);
	m_structuredActivityNodeActivation_EOperation_putPinValues_OutputPin_Value = factory->createEOperation_in_EContainingClass(m_structuredActivityNodeActivation_EClass, STRUCTUREDACTIVITYNODEACTIVATION_EOPERATION_PUTPINVALUES_OUTPUTPIN_VALUE);
	m_structuredActivityNodeActivation_EOperation_resume = factory->createEOperation_in_EContainingClass(m_structuredActivityNodeActivation_EClass, STRUCTUREDACTIVITYNODEACTIVATION_EOPERATION_RESUME);
	m_structuredActivityNodeActivation_EOperation_terminate = factory->createEOperation_in_EContainingClass(m_structuredActivityNodeActivation_EClass, STRUCTUREDACTIVITYNODEACTIVATION_EOPERATION_TERMINATE);
	m_structuredActivityNodeActivation_EOperation_terminateAll = factory->createEOperation_in_EContainingClass(m_structuredActivityNodeActivation_EClass, STRUCTUREDACTIVITYNODEACTIVATION_EOPERATION_TERMINATEALL);
	
}

void FUMLPackageImpl::createStructuredValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_structuredValue_EClass = factory->createEClass_in_EPackage(package, STRUCTUREDVALUE_ECLASS);
	
	
	m_structuredValue_EOperation_assignFeatureValue_StructuralFeature_EInt = factory->createEOperation_in_EContainingClass(m_structuredValue_EClass, STRUCTUREDVALUE_EOPERATION_ASSIGNFEATUREVALUE_STRUCTURALFEATURE_EINT);
	m_structuredValue_EOperation_createFeatureValues = factory->createEOperation_in_EContainingClass(m_structuredValue_EClass, STRUCTUREDVALUE_EOPERATION_CREATEFEATUREVALUES);
	m_structuredValue_EOperation_retrieveFeatureValue_StructuralFeature = factory->createEOperation_in_EContainingClass(m_structuredValue_EClass, STRUCTUREDVALUE_EOPERATION_RETRIEVEFEATUREVALUE_STRUCTURALFEATURE);
	m_structuredValue_EOperation_retrieveFeatureValues = factory->createEOperation_in_EContainingClass(m_structuredValue_EClass, STRUCTUREDVALUE_EOPERATION_RETRIEVEFEATUREVALUES);
	m_structuredValue_EOperation_specify = factory->createEOperation_in_EContainingClass(m_structuredValue_EClass, STRUCTUREDVALUE_EOPERATION_SPECIFY);
	
}

void FUMLPackageImpl::createTestIdentityActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_testIdentityActionActivation_EClass = factory->createEClass_in_EPackage(package, TESTIDENTITYACTIONACTIVATION_ECLASS);
	
	
	
}

void FUMLPackageImpl::createTokenContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_token_EClass = factory->createEClass_in_EPackage(package, TOKEN_ECLASS);
	m_token_EAttribute_withdrawn = factory->createEAttribute_in_EContainingClass(m_token_EClass, TOKEN_EATTRIBUTE_WITHDRAWN);
	
	m_token_EReference_holder = factory->createEReference_in_EContainingClass(m_token_EClass, TOKEN_EREFERENCE_HOLDER);
	
	m_token_EOperation_equals_Token = factory->createEOperation_in_EContainingClass(m_token_EClass, TOKEN_EOPERATION_EQUALS_TOKEN);
	m_token_EOperation_getValue = factory->createEOperation_in_EContainingClass(m_token_EClass, TOKEN_EOPERATION_GETVALUE);
	m_token_EOperation_isControl = factory->createEOperation_in_EContainingClass(m_token_EClass, TOKEN_EOPERATION_ISCONTROL);
	m_token_EOperation_transfer_ActivityNodeActivation = factory->createEOperation_in_EContainingClass(m_token_EClass, TOKEN_EOPERATION_TRANSFER_ACTIVITYNODEACTIVATION);
	m_token_EOperation_withdraw = factory->createEOperation_in_EContainingClass(m_token_EClass, TOKEN_EOPERATION_WITHDRAW);
	
}

void FUMLPackageImpl::createTokenSetContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_tokenSet_EClass = factory->createEClass_in_EPackage(package, TOKENSET_ECLASS);
	
	m_tokenSet_EReference_tokens = factory->createEReference_in_EContainingClass(m_tokenSet_EClass, TOKENSET_EREFERENCE_TOKENS);
	
	
}

void FUMLPackageImpl::createUnlimitedNaturalValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_unlimitedNaturalValue_EClass = factory->createEClass_in_EPackage(package, UNLIMITEDNATURALVALUE_ECLASS);
	m_unlimitedNaturalValue_EAttribute_value = factory->createEAttribute_in_EContainingClass(m_unlimitedNaturalValue_EClass, UNLIMITEDNATURALVALUE_EATTRIBUTE_VALUE);
	
	
	m_unlimitedNaturalValue_EOperation_equals_Value = factory->createEOperation_in_EContainingClass(m_unlimitedNaturalValue_EClass, UNLIMITEDNATURALVALUE_EOPERATION_EQUALS_VALUE);
	m_unlimitedNaturalValue_EOperation_specify = factory->createEOperation_in_EContainingClass(m_unlimitedNaturalValue_EClass, UNLIMITEDNATURALVALUE_EOPERATION_SPECIFY);
	m_unlimitedNaturalValue_EOperation_toString = factory->createEOperation_in_EContainingClass(m_unlimitedNaturalValue_EClass, UNLIMITEDNATURALVALUE_EOPERATION_TOSTRING);
	
}

void FUMLPackageImpl::createValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_value_EClass = factory->createEClass_in_EPackage(package, VALUE_ECLASS);
	
	
	m_value_EOperation_equals_Value = factory->createEOperation_in_EContainingClass(m_value_EClass, VALUE_EOPERATION_EQUALS_VALUE);
	m_value_EOperation_getTypes = factory->createEOperation_in_EContainingClass(m_value_EClass, VALUE_EOPERATION_GETTYPES);
	m_value_EOperation_hasTypes_Classifier = factory->createEOperation_in_EContainingClass(m_value_EClass, VALUE_EOPERATION_HASTYPES_CLASSIFIER);
	m_value_EOperation_objectId = factory->createEOperation_in_EContainingClass(m_value_EClass, VALUE_EOPERATION_OBJECTID);
	m_value_EOperation_specify = factory->createEOperation_in_EContainingClass(m_value_EClass, VALUE_EOPERATION_SPECIFY);
	m_value_EOperation_toString = factory->createEOperation_in_EContainingClass(m_value_EClass, VALUE_EOPERATION_TOSTRING);
	
}

void FUMLPackageImpl::createValueSpecificActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_valueSpecificActionActivation_EClass = factory->createEClass_in_EPackage(package, VALUESPECIFICACTIONACTIVATION_ECLASS);
	
	
	
}

void FUMLPackageImpl::createValuesContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_values_EClass = factory->createEClass_in_EPackage(package, VALUES_ECLASS);
	
	m_values_EReference_values = factory->createEReference_in_EContainingClass(m_values_EClass, VALUES_EREFERENCE_VALUES);
	
	
}

void FUMLPackageImpl::createWriteLinkActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_writeLinkActionActivation_EClass = factory->createEClass_in_EPackage(package, WRITELINKACTIONACTIVATION_ECLASS);
	
	
	
}

void FUMLPackageImpl::createWriteStructuralFeatureActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_writeStructuralFeatureActionActivation_EClass = factory->createEClass_in_EPackage(package, WRITESTRUCTURALFEATUREACTIONACTIVATION_ECLASS);
	
	
	m_writeStructuralFeatureActionActivation_EOperation_position_Value_EInt = factory->createEOperation_in_EContainingClass(m_writeStructuralFeatureActionActivation_EClass, WRITESTRUCTURALFEATUREACTIONACTIVATION_EOPERATION_POSITION_VALUE_EINT);
	
}

void FUMLPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	
}

void FUMLPackageImpl::initializePackageContents()
{
	if (isInitialized)
	{
		return;
	}
	isInitialized = true;

	// Initialize package
	setName(eNAME);
	setNsPrefix(eNS_PREFIX);
	setNsURI(eNS_URI);
	
	// Add supertypes to classes
	m_acceptEventActionActivation_EClass->getESuperTypes()->push_back(getActionActivation_EClass());
	m_acceptEventActionEventAccepter_EClass->getESuperTypes()->push_back(getEventAccepter_EClass());
	m_actionActivation_EClass->getESuperTypes()->push_back(getActivityNodeActivation_EClass());
	m_activityExecution_EClass->getESuperTypes()->push_back(getExecution_EClass());
	m_activityFinalNodeActivation_EClass->getESuperTypes()->push_back(getControlNodeActivation_EClass());
	m_activityNodeActivation_EClass->getESuperTypes()->push_back(getSemanticVisitor_EClass());
	m_activityParameterNodeActivation_EClass->getESuperTypes()->push_back(getObjectNodeActivation_EClass());
	m_addStructuralFeatureValueActionActivation_EClass->getESuperTypes()->push_back(getWriteStructuralFeatureActionActivation_EClass());
	m_booleanValue_EClass->getESuperTypes()->push_back(getPrimitiveValue_EClass());
	m_callActionActivation_EClass->getESuperTypes()->push_back(getInvocationActionActivation_EClass());
	m_callBehaviorActionActivation_EClass->getESuperTypes()->push_back(getCallActionActivation_EClass());
	m_callOperationActionActivation_EClass->getESuperTypes()->push_back(getCallActionActivation_EClass());
	m_centralBufferNodeActivation_EClass->getESuperTypes()->push_back(getObjectNodeActivation_EClass());
	m_choiceStrategy_EClass->getESuperTypes()->push_back(getSemanticStrategy_EClass());
	m_clearAssociationActionActivation_EClass->getESuperTypes()->push_back(getActionActivation_EClass());
	m_clearStructuralFeatureActionActivation_EClass->getESuperTypes()->push_back(getStructuralFeatureActionActivation_EClass());
	m_compoundValue_EClass->getESuperTypes()->push_back(getStructuredValue_EClass());
	m_conditionalNodeActivation_EClass->getESuperTypes()->push_back(getStructuredActivityNodeActivation_EClass());
	m_controlNodeActivation_EClass->getESuperTypes()->push_back(getActivityNodeActivation_EClass());
	m_controlToken_EClass->getESuperTypes()->push_back(getToken_EClass());
	m_createLinkActionActivation_EClass->getESuperTypes()->push_back(getWriteLinkActionActivation_EClass());
	m_createObjectActionActivation_EClass->getESuperTypes()->push_back(getActionActivation_EClass());
	m_dataStoreNodeActivation_EClass->getESuperTypes()->push_back(getCentralBufferNodeActivation_EClass());
	m_dataValue_EClass->getESuperTypes()->push_back(getCompoundValue_EClass());
	m_decisionNodeActivation_EClass->getESuperTypes()->push_back(getControlNodeActivation_EClass());
	m_destroyLinkActionActivation_EClass->getESuperTypes()->push_back(getWriteLinkActionActivation_EClass());
	m_destroyObjectActionActivation_EClass->getESuperTypes()->push_back(getActionActivation_EClass());
	m_dispatchStrategy_EClass->getESuperTypes()->push_back(getSemanticStrategy_EClass());
	m_enumerationValue_EClass->getESuperTypes()->push_back(getValue_EClass());
	m_evaluation_EClass->getESuperTypes()->push_back(getSemanticVisitor_EClass());
	m_execution_EClass->getESuperTypes()->push_back(getObject_EClass());
	m_executionFactoryL1_EClass->getESuperTypes()->push_back(getExecutionFactory_EClass());
	m_executionFactoryL2_EClass->getESuperTypes()->push_back(getExecutionFactoryL1_EClass());
	m_executionFactoryL3_EClass->getESuperTypes()->push_back(getExecutionFactoryL2_EClass());
	m_expansionActivationGroup_EClass->getESuperTypes()->push_back(getActivityNodeActivationGroup_EClass());
	m_expansionNodeActivation_EClass->getESuperTypes()->push_back(getObjectNodeActivation_EClass());
	m_expansionRegionActivation_EClass->getESuperTypes()->push_back(getActionActivation_EClass());
	m_extensionalValue_EClass->getESuperTypes()->push_back(getCompoundValue_EClass());
	m_extensionalValueList_EClass->getESuperTypes()->push_back(getExtensionalValue_EClass());
	m_fIFOGetNextEventStrategy_EClass->getESuperTypes()->push_back(getGetNextEventStrategy_EClass());
	m_firstChoiceStrategy_EClass->getESuperTypes()->push_back(getChoiceStrategy_EClass());
	m_flowFinalNodeActivation_EClass->getESuperTypes()->push_back(getControlNodeActivation_EClass());
	m_forkNodeActivation_EClass->getESuperTypes()->push_back(getControlNodeActivation_EClass());
	m_forkedToken_EClass->getESuperTypes()->push_back(getToken_EClass());
	m_getNextEventStrategy_EClass->getESuperTypes()->push_back(getSemanticStrategy_EClass());
	m_initialNodeActivation_EClass->getESuperTypes()->push_back(getControlNodeActivation_EClass());
	m_inputPinActivation_EClass->getESuperTypes()->push_back(getPinActivation_EClass());
	m_instanceValueEvaluation_EClass->getESuperTypes()->push_back(getEvaluation_EClass());
	m_integerValue_EClass->getESuperTypes()->push_back(getPrimitiveValue_EClass());
	m_invocationActionActivation_EClass->getESuperTypes()->push_back(getActionActivation_EClass());
	m_joinNodeActivation_EClass->getESuperTypes()->push_back(getControlNodeActivation_EClass());
	m_link_EClass->getESuperTypes()->push_back(getExtensionalValue_EClass());
	m_linkActionActivation_EClass->getESuperTypes()->push_back(getActionActivation_EClass());
	m_literalBooleanEvaluation_EClass->getESuperTypes()->push_back(getLiteralEvaluation_EClass());
	m_literalEvaluation_EClass->getESuperTypes()->push_back(getEvaluation_EClass());
	m_literalIntegerEvaluation_EClass->getESuperTypes()->push_back(getLiteralEvaluation_EClass());
	m_literalNullEvaluation_EClass->getESuperTypes()->push_back(getLiteralEvaluation_EClass());
	m_literalRealEvaluation_EClass->getESuperTypes()->push_back(getLiteralEvaluation_EClass());
	m_literalStringEvaluation_EClass->getESuperTypes()->push_back(getLiteralEvaluation_EClass());
	m_literalUnlimitedNaturalEvaluation_EClass->getESuperTypes()->push_back(getLiteralEvaluation_EClass());
	m_loopNodeActivation_EClass->getESuperTypes()->push_back(getStructuredActivityNodeActivation_EClass());
	m_mergeNodeActivation_EClass->getESuperTypes()->push_back(getControlNodeActivation_EClass());
	m_object_EClass->getESuperTypes()->push_back(getExtensionalValue_EClass());
	m_objectNodeActivation_EClass->getESuperTypes()->push_back(getActivityNodeActivation_EClass());
	m_objectToken_EClass->getESuperTypes()->push_back(getToken_EClass());
	m_opaqueBehaviorExecution_EClass->getESuperTypes()->push_back(getExecution_EClass());
	m_outputPinActivation_EClass->getESuperTypes()->push_back(getPinActivation_EClass());
	m_pinActivation_EClass->getESuperTypes()->push_back(getObjectNodeActivation_EClass());
	m_primitiveValue_EClass->getESuperTypes()->push_back(getValue_EClass());
	m_readExtentActionActivation_EClass->getESuperTypes()->push_back(getActionActivation_EClass());
	m_readIsClassifiedObjectActionActivation_EClass->getESuperTypes()->push_back(getActionActivation_EClass());
	m_readLinkActionActivation_EClass->getESuperTypes()->push_back(getLinkActionActivation_EClass());
	m_readSelfActionActivation_EClass->getESuperTypes()->push_back(getActionActivation_EClass());
	m_readStructuralFeatureActionActivation_EClass->getESuperTypes()->push_back(getStructuralFeatureActionActivation_EClass());
	m_realValue_EClass->getESuperTypes()->push_back(getPrimitiveValue_EClass());
	m_reclassifyObjectActionActivation_EClass->getESuperTypes()->push_back(getActionActivation_EClass());
	m_redefinitionBasedDispatchStrategy_EClass->getESuperTypes()->push_back(getDispatchStrategy_EClass());
	m_reduceActionActivation_EClass->getESuperTypes()->push_back(getActionActivation_EClass());
	m_reference_EClass->getESuperTypes()->push_back(getStructuredValue_EClass());
	m_removeStructuralFeatureValueActivation_EClass->getESuperTypes()->push_back(getWriteStructuralFeatureActionActivation_EClass());
	m_sendSignalActionActivation_EClass->getESuperTypes()->push_back(getInvocationActionActivation_EClass());
	m_signalInstance_EClass->getESuperTypes()->push_back(getCompoundValue_EClass());
	m_startClassifierBehaviorActionActivation_EClass->getESuperTypes()->push_back(getActionActivation_EClass());
	m_startObjectBehaviorActionActivation_EClass->getESuperTypes()->push_back(getInvocationActionActivation_EClass());
	m_stringValue_EClass->getESuperTypes()->push_back(getPrimitiveValue_EClass());
	m_structuralFeatureActionActivation_EClass->getESuperTypes()->push_back(getActionActivation_EClass());
	m_structuredActivityNodeActivation_EClass->getESuperTypes()->push_back(getActionActivation_EClass());
	m_structuredValue_EClass->getESuperTypes()->push_back(getValue_EClass());
	m_testIdentityActionActivation_EClass->getESuperTypes()->push_back(getActionActivation_EClass());
	m_unlimitedNaturalValue_EClass->getESuperTypes()->push_back(getPrimitiveValue_EClass());
	m_value_EClass->getESuperTypes()->push_back(getSemanticVisitor_EClass());
	m_valueSpecificActionActivation_EClass->getESuperTypes()->push_back(getActionActivation_EClass());
	m_writeLinkActionActivation_EClass->getESuperTypes()->push_back(getLinkActionActivation_EClass());
	m_writeStructuralFeatureActionActivation_EClass->getESuperTypes()->push_back(getStructuralFeatureActionActivation_EClass());
	

 	// Initialize classes and features; add operations and parameters
	initializeAcceptEventActionActivationContent();
	initializeAcceptEventActionEventAccepterContent();
	initializeActionActivationContent();
	initializeActivityEdgeInstanceContent();
	initializeActivityExecutionContent();
	initializeActivityFinalNodeActivationContent();
	initializeActivityNodeActivationContent();
	initializeActivityNodeActivationGroupContent();
	initializeActivityParameterNodeActivationContent();
	initializeAddStructuralFeatureValueActionActivationContent();
	initializeBooleanValueContent();
	initializeCallActionActivationContent();
	initializeCallBehaviorActionActivationContent();
	initializeCallOperationActionActivationContent();
	initializeCentralBufferNodeActivationContent();
	initializeChoiceStrategyContent();
	initializeClassifierBehaviorExecutionContent();
	initializeClassifierBehaviorExecutionActivityContent();
	initializeClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Content();
	initializeClauseActivationContent();
	initializeClearAssociationActionActivationContent();
	initializeClearStructuralFeatureActionActivationContent();
	initializeCompoundValueContent();
	initializeConditionalNodeActivationContent();
	initializeControlNodeActivationContent();
	initializeControlTokenContent();
	initializeCreateLinkActionActivationContent();
	initializeCreateObjectActionActivationContent();
	initializeDataStoreNodeActivationContent();
	initializeDataValueContent();
	initializeDecisionNodeActivationContent();
	initializeDestroyLinkActionActivationContent();
	initializeDestroyObjectActionActivationContent();
	initializeDispatchStrategyContent();
	initializeEnumerationValueContent();
	initializeEvaluationContent();
	initializeEventAccepterContent();
	initializeEventDispatchLoopContent();
	initializeExecutionContent();
	initializeExecutionFactoryContent();
	initializeExecutionFactoryL1Content();
	initializeExecutionFactoryL2Content();
	initializeExecutionFactoryL3Content();
	initializeExecutorContent();
	initializeExpansionActivationGroupContent();
	initializeExpansionNodeActivationContent();
	initializeExpansionRegionActivationContent();
	initializeExtensionalValueContent();
	initializeExtensionalValueListContent();
	initializeFIFOGetNextEventStrategyContent();
	initializeFeatureValueContent();
	initializeFirstChoiceStrategyContent();
	initializeFlowFinalNodeActivationContent();
	initializeForkNodeActivationContent();
	initializeForkedTokenContent();
	initializeGetNextEventStrategyContent();
	initializeInitialNodeActivationContent();
	initializeInputPinActivationContent();
	initializeInstanceValueEvaluationContent();
	initializeIntegerValueContent();
	initializeInvocationActionActivationContent();
	initializeJoinNodeActivationContent();
	initializeLinkContent();
	initializeLinkActionActivationContent();
	initializeLiteralBooleanEvaluationContent();
	initializeLiteralEvaluationContent();
	initializeLiteralIntegerEvaluationContent();
	initializeLiteralNullEvaluationContent();
	initializeLiteralRealEvaluationContent();
	initializeLiteralStringEvaluationContent();
	initializeLiteralUnlimitedNaturalEvaluationContent();
	initializeLocusContent();
	initializeLoopNodeActivationContent();
	initializeMergeNodeActivationContent();
	initializeObjectContent();
	initializeObjectActivationContent();
	initializeObjectNodeActivationContent();
	initializeObjectTokenContent();
	initializeOfferContent();
	initializeOpaqueBehaviorExecutionContent();
	initializeOutputPinActivationContent();
	initializeParameterValueContent();
	initializePinActivationContent();
	initializePrimitiveValueContent();
	initializeReadExtentActionActivationContent();
	initializeReadIsClassifiedObjectActionActivationContent();
	initializeReadLinkActionActivationContent();
	initializeReadSelfActionActivationContent();
	initializeReadStructuralFeatureActionActivationContent();
	initializeRealValueContent();
	initializeReclassifyObjectActionActivationContent();
	initializeRedefinitionBasedDispatchStrategyContent();
	initializeReduceActionActivationContent();
	initializeReferenceContent();
	initializeRemoveStructuralFeatureValueActivationContent();
	initializeSemanticStrategyContent();
	initializeSemanticVisitorContent();
	initializeSendSignalActionActivationContent();
	initializeSignalInstanceContent();
	initializeStartClassifierBehaviorActionActivationContent();
	initializeStartObjectBehaviorActionActivationContent();
	initializeStringValueContent();
	initializeStructuralFeatureActionActivationContent();
	initializeStructuredActivityNodeActivationContent();
	initializeStructuredValueContent();
	initializeTestIdentityActionActivationContent();
	initializeTokenContent();
	initializeTokenSetContent();
	initializeUnlimitedNaturalValueContent();
	initializeValueContent();
	initializeValueSpecificActionActivationContent();
	initializeValuesContent();
	initializeWriteLinkActionActivationContent();
	initializeWriteStructuralFeatureActionActivationContent();

	initializePackageEDataTypes();
}

void FUMLPackageImpl::initializeAcceptEventActionActivationContent()
{
	m_acceptEventActionActivation_EClass->setInstanceClass(nullptr);
	m_acceptEventActionActivation_EClass->setName("AcceptEventActionActivation");
	m_acceptEventActionActivation_EClass->setAbstract(false);
	m_acceptEventActionActivation_EClass->setInterface(false);
	
	m_acceptEventActionActivation_EAttribute_waiting = getAcceptEventActionActivation_EAttribute_waiting();
	m_acceptEventActionActivation_EAttribute_waiting->setName("waiting");
	m_acceptEventActionActivation_EAttribute_waiting->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_acceptEventActionActivation_EAttribute_waiting->setLowerBound(1);
	m_acceptEventActionActivation_EAttribute_waiting->setUpperBound(1);
	m_acceptEventActionActivation_EAttribute_waiting->setTransient(false);
	m_acceptEventActionActivation_EAttribute_waiting->setVolatile(false);
	m_acceptEventActionActivation_EAttribute_waiting->setChangeable(true);
	m_acceptEventActionActivation_EAttribute_waiting->setUnsettable(false);
	m_acceptEventActionActivation_EAttribute_waiting->setUnique(true);
	m_acceptEventActionActivation_EAttribute_waiting->setDerived(false);
	m_acceptEventActionActivation_EAttribute_waiting->setOrdered(false);
	m_acceptEventActionActivation_EAttribute_waiting->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_acceptEventActionActivation_EAttribute_waiting->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_acceptEventActionActivation_EReference_eventAccepter->setName("eventAccepter");
	m_acceptEventActionActivation_EReference_eventAccepter->setEType(getAcceptEventActionEventAccepter_EClass());
	m_acceptEventActionActivation_EReference_eventAccepter->setLowerBound(0);
	m_acceptEventActionActivation_EReference_eventAccepter->setUpperBound(1);
	m_acceptEventActionActivation_EReference_eventAccepter->setTransient(false);
	m_acceptEventActionActivation_EReference_eventAccepter->setVolatile(false);
	m_acceptEventActionActivation_EReference_eventAccepter->setChangeable(true);
	m_acceptEventActionActivation_EReference_eventAccepter->setUnsettable(false);
	m_acceptEventActionActivation_EReference_eventAccepter->setUnique(true);
	m_acceptEventActionActivation_EReference_eventAccepter->setDerived(false);
	m_acceptEventActionActivation_EReference_eventAccepter->setOrdered(false);
	m_acceptEventActionActivation_EReference_eventAccepter->setContainment(false);
	m_acceptEventActionActivation_EReference_eventAccepter->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_acceptEventActionActivation_EReference_eventAccepter->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_acceptEventActionActivation_EReference_eventAccepter->setEOpposite(otherEnd);
	    }
	}
	
	m_acceptEventActionActivation_EOperation_accept_SignalInstance->setEType(nullptr);
	m_acceptEventActionActivation_EOperation_accept_SignalInstance->setName("accept");
	m_acceptEventActionActivation_EOperation_accept_SignalInstance->setLowerBound(1);
	m_acceptEventActionActivation_EOperation_accept_SignalInstance->setUpperBound(1);
	m_acceptEventActionActivation_EOperation_accept_SignalInstance->setUnique(true);
	m_acceptEventActionActivation_EOperation_accept_SignalInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_acceptEventActionActivation_EOperation_accept_SignalInstance);
		parameter->setName("signalInstance");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_acceptEventActionActivation_EOperation_match_SignalInstance->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_acceptEventActionActivation_EOperation_match_SignalInstance->setName("match");
	m_acceptEventActionActivation_EOperation_match_SignalInstance->setLowerBound(1);
	m_acceptEventActionActivation_EOperation_match_SignalInstance->setUpperBound(1);
	m_acceptEventActionActivation_EOperation_match_SignalInstance->setUnique(true);
	m_acceptEventActionActivation_EOperation_match_SignalInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_acceptEventActionActivation_EOperation_match_SignalInstance);
		parameter->setName("signalInstance");
		parameter->setEType(getSignalInstance_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeAcceptEventActionEventAccepterContent()
{
	m_acceptEventActionEventAccepter_EClass->setInstanceClass(nullptr);
	m_acceptEventActionEventAccepter_EClass->setName("AcceptEventActionEventAccepter");
	m_acceptEventActionEventAccepter_EClass->setAbstract(false);
	m_acceptEventActionEventAccepter_EClass->setInterface(false);
	
	
	m_acceptEventActionEventAccepter_EReference_actionActivation->setName("actionActivation");
	m_acceptEventActionEventAccepter_EReference_actionActivation->setEType(getAcceptEventActionActivation_EClass());
	m_acceptEventActionEventAccepter_EReference_actionActivation->setLowerBound(1);
	m_acceptEventActionEventAccepter_EReference_actionActivation->setUpperBound(1);
	m_acceptEventActionEventAccepter_EReference_actionActivation->setTransient(false);
	m_acceptEventActionEventAccepter_EReference_actionActivation->setVolatile(false);
	m_acceptEventActionEventAccepter_EReference_actionActivation->setChangeable(true);
	m_acceptEventActionEventAccepter_EReference_actionActivation->setUnsettable(false);
	m_acceptEventActionEventAccepter_EReference_actionActivation->setUnique(true);
	m_acceptEventActionEventAccepter_EReference_actionActivation->setDerived(false);
	m_acceptEventActionEventAccepter_EReference_actionActivation->setOrdered(false);
	m_acceptEventActionEventAccepter_EReference_actionActivation->setContainment(false);
	m_acceptEventActionEventAccepter_EReference_actionActivation->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_acceptEventActionEventAccepter_EReference_actionActivation->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_acceptEventActionEventAccepter_EReference_actionActivation->setEOpposite(otherEnd);
	    }
	}
	
	
}

void FUMLPackageImpl::initializeActionActivationContent()
{
	m_actionActivation_EClass->setInstanceClass(nullptr);
	m_actionActivation_EClass->setName("ActionActivation");
	m_actionActivation_EClass->setAbstract(true);
	m_actionActivation_EClass->setInterface(false);
	
	m_actionActivation_EAttribute_firing = getActionActivation_EAttribute_firing();
	m_actionActivation_EAttribute_firing->setName("firing");
	m_actionActivation_EAttribute_firing->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_actionActivation_EAttribute_firing->setLowerBound(1);
	m_actionActivation_EAttribute_firing->setUpperBound(1);
	m_actionActivation_EAttribute_firing->setTransient(false);
	m_actionActivation_EAttribute_firing->setVolatile(false);
	m_actionActivation_EAttribute_firing->setChangeable(true);
	m_actionActivation_EAttribute_firing->setUnsettable(false);
	m_actionActivation_EAttribute_firing->setUnique(true);
	m_actionActivation_EAttribute_firing->setDerived(false);
	m_actionActivation_EAttribute_firing->setOrdered(false);
	m_actionActivation_EAttribute_firing->setID(false);
	{
		std::string defaultValue = "false";
		if (!defaultValue.empty())
		{
		   m_actionActivation_EAttribute_firing->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_actionActivation_EReference_pinActivation->setName("pinActivation");
	m_actionActivation_EReference_pinActivation->setEType(getPinActivation_EClass());
	m_actionActivation_EReference_pinActivation->setLowerBound(0);
	m_actionActivation_EReference_pinActivation->setUpperBound(-1);
	m_actionActivation_EReference_pinActivation->setTransient(false);
	m_actionActivation_EReference_pinActivation->setVolatile(false);
	m_actionActivation_EReference_pinActivation->setChangeable(true);
	m_actionActivation_EReference_pinActivation->setUnsettable(false);
	m_actionActivation_EReference_pinActivation->setUnique(true);
	m_actionActivation_EReference_pinActivation->setDerived(false);
	m_actionActivation_EReference_pinActivation->setOrdered(false);
	m_actionActivation_EReference_pinActivation->setContainment(false);
	m_actionActivation_EReference_pinActivation->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_actionActivation_EReference_pinActivation->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_actionActivation_EReference_pinActivation->setEOpposite(otherEnd);
	    }
	}
	
	m_actionActivation_EOperation_addOutgoingEdge_ActivityEdgeInstance->setEType(nullptr);
	m_actionActivation_EOperation_addOutgoingEdge_ActivityEdgeInstance->setName("addOutgoingEdge");
	m_actionActivation_EOperation_addOutgoingEdge_ActivityEdgeInstance->setLowerBound(1);
	m_actionActivation_EOperation_addOutgoingEdge_ActivityEdgeInstance->setUpperBound(1);
	m_actionActivation_EOperation_addOutgoingEdge_ActivityEdgeInstance->setUnique(true);
	m_actionActivation_EOperation_addOutgoingEdge_ActivityEdgeInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_EOperation_addOutgoingEdge_ActivityEdgeInstance);
		parameter->setName("edge");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_EOperation_addPinActivation_PinActivation->setEType(nullptr);
	m_actionActivation_EOperation_addPinActivation_PinActivation->setName("addPinActivation");
	m_actionActivation_EOperation_addPinActivation_PinActivation->setLowerBound(1);
	m_actionActivation_EOperation_addPinActivation_PinActivation->setUpperBound(1);
	m_actionActivation_EOperation_addPinActivation_PinActivation->setUnique(true);
	m_actionActivation_EOperation_addPinActivation_PinActivation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_EOperation_addPinActivation_PinActivation);
		parameter->setName("pinActivation");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_EOperation_completeAction->setEType(getToken_EClass());
	m_actionActivation_EOperation_completeAction->setName("completeAction");
	m_actionActivation_EOperation_completeAction->setLowerBound(0);
	m_actionActivation_EOperation_completeAction->setUpperBound(-1);
	m_actionActivation_EOperation_completeAction->setUnique(true);
	m_actionActivation_EOperation_completeAction->setOrdered(false);
	
	
	m_actionActivation_EOperation_createNodeActivations->setEType(nullptr);
	m_actionActivation_EOperation_createNodeActivations->setName("createNodeActivations");
	m_actionActivation_EOperation_createNodeActivations->setLowerBound(1);
	m_actionActivation_EOperation_createNodeActivations->setUpperBound(1);
	m_actionActivation_EOperation_createNodeActivations->setUnique(true);
	m_actionActivation_EOperation_createNodeActivations->setOrdered(false);
	
	
	m_actionActivation_EOperation_doAction->setEType(nullptr);
	m_actionActivation_EOperation_doAction->setName("doAction");
	m_actionActivation_EOperation_doAction->setLowerBound(1);
	m_actionActivation_EOperation_doAction->setUpperBound(1);
	m_actionActivation_EOperation_doAction->setUnique(true);
	m_actionActivation_EOperation_doAction->setOrdered(false);
	
	
	m_actionActivation_EOperation_fire_Token->setEType(nullptr);
	m_actionActivation_EOperation_fire_Token->setName("fire");
	m_actionActivation_EOperation_fire_Token->setLowerBound(1);
	m_actionActivation_EOperation_fire_Token->setUpperBound(1);
	m_actionActivation_EOperation_fire_Token->setUnique(true);
	m_actionActivation_EOperation_fire_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_EOperation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_EOperation_getTokens_InputPin->setEType(getValue_EClass());
	m_actionActivation_EOperation_getTokens_InputPin->setName("getTokens");
	m_actionActivation_EOperation_getTokens_InputPin->setLowerBound(0);
	m_actionActivation_EOperation_getTokens_InputPin->setUpperBound(-1);
	m_actionActivation_EOperation_getTokens_InputPin->setUnique(true);
	m_actionActivation_EOperation_getTokens_InputPin->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_EOperation_getTokens_InputPin);
		parameter->setName("pin");
		parameter->setEType(uml::UmlPackage::eInstance()->getInputPin_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_EOperation_isFirng->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_actionActivation_EOperation_isFirng->setName("isFirng");
	m_actionActivation_EOperation_isFirng->setLowerBound(1);
	m_actionActivation_EOperation_isFirng->setUpperBound(1);
	m_actionActivation_EOperation_isFirng->setUnique(true);
	m_actionActivation_EOperation_isFirng->setOrdered(false);
	
	
	m_actionActivation_EOperation_isReady->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_actionActivation_EOperation_isReady->setName("isReady");
	m_actionActivation_EOperation_isReady->setLowerBound(1);
	m_actionActivation_EOperation_isReady->setUpperBound(1);
	m_actionActivation_EOperation_isReady->setUnique(true);
	m_actionActivation_EOperation_isReady->setOrdered(false);
	
	
	m_actionActivation_EOperation_isSourceFor_ActivityEdgeInstance->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_actionActivation_EOperation_isSourceFor_ActivityEdgeInstance->setName("isSourceFor");
	m_actionActivation_EOperation_isSourceFor_ActivityEdgeInstance->setLowerBound(1);
	m_actionActivation_EOperation_isSourceFor_ActivityEdgeInstance->setUpperBound(1);
	m_actionActivation_EOperation_isSourceFor_ActivityEdgeInstance->setUnique(true);
	m_actionActivation_EOperation_isSourceFor_ActivityEdgeInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_EOperation_isSourceFor_ActivityEdgeInstance);
		parameter->setName("edgeInstance");
		parameter->setEType(getActivityEdgeInstance_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_EOperation_makeBooleanValue_EBoolean->setEType(getBooleanValue_EClass());
	m_actionActivation_EOperation_makeBooleanValue_EBoolean->setName("makeBooleanValue");
	m_actionActivation_EOperation_makeBooleanValue_EBoolean->setLowerBound(1);
	m_actionActivation_EOperation_makeBooleanValue_EBoolean->setUpperBound(1);
	m_actionActivation_EOperation_makeBooleanValue_EBoolean->setUnique(true);
	m_actionActivation_EOperation_makeBooleanValue_EBoolean->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_EOperation_makeBooleanValue_EBoolean);
		parameter->setName("value");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_EOperation_putToken_OutputPin_Value->setEType(nullptr);
	m_actionActivation_EOperation_putToken_OutputPin_Value->setName("putToken");
	m_actionActivation_EOperation_putToken_OutputPin_Value->setLowerBound(1);
	m_actionActivation_EOperation_putToken_OutputPin_Value->setUpperBound(1);
	m_actionActivation_EOperation_putToken_OutputPin_Value->setUnique(true);
	m_actionActivation_EOperation_putToken_OutputPin_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_EOperation_putToken_OutputPin_Value);
		parameter->setName("pin");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_EOperation_putToken_OutputPin_Value);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_EOperation_putTokens_OutputPin_Value->setEType(nullptr);
	m_actionActivation_EOperation_putTokens_OutputPin_Value->setName("putTokens");
	m_actionActivation_EOperation_putTokens_OutputPin_Value->setLowerBound(1);
	m_actionActivation_EOperation_putTokens_OutputPin_Value->setUpperBound(1);
	m_actionActivation_EOperation_putTokens_OutputPin_Value->setUnique(true);
	m_actionActivation_EOperation_putTokens_OutputPin_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_EOperation_putTokens_OutputPin_Value);
		parameter->setName("pin");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_EOperation_putTokens_OutputPin_Value);
		parameter->setName("values");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_EOperation_retrievePinActivation_Pin->setEType(getPinActivation_EClass());
	m_actionActivation_EOperation_retrievePinActivation_Pin->setName("retrievePinActivation");
	m_actionActivation_EOperation_retrievePinActivation_Pin->setLowerBound(1);
	m_actionActivation_EOperation_retrievePinActivation_Pin->setUpperBound(1);
	m_actionActivation_EOperation_retrievePinActivation_Pin->setUnique(true);
	m_actionActivation_EOperation_retrievePinActivation_Pin->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_EOperation_retrievePinActivation_Pin);
		parameter->setName("pin");
		parameter->setEType(uml::UmlPackage::eInstance()->getPin_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_EOperation_run->setEType(nullptr);
	m_actionActivation_EOperation_run->setName("run");
	m_actionActivation_EOperation_run->setLowerBound(1);
	m_actionActivation_EOperation_run->setUpperBound(1);
	m_actionActivation_EOperation_run->setUnique(true);
	m_actionActivation_EOperation_run->setOrdered(false);
	
	
	m_actionActivation_EOperation_sendOffers->setEType(nullptr);
	m_actionActivation_EOperation_sendOffers->setName("sendOffers");
	m_actionActivation_EOperation_sendOffers->setLowerBound(1);
	m_actionActivation_EOperation_sendOffers->setUpperBound(1);
	m_actionActivation_EOperation_sendOffers->setUnique(true);
	m_actionActivation_EOperation_sendOffers->setOrdered(false);
	
	
	m_actionActivation_EOperation_takeOfferedTokens->setEType(getToken_EClass());
	m_actionActivation_EOperation_takeOfferedTokens->setName("takeOfferedTokens");
	m_actionActivation_EOperation_takeOfferedTokens->setLowerBound(0);
	m_actionActivation_EOperation_takeOfferedTokens->setUpperBound(-1);
	m_actionActivation_EOperation_takeOfferedTokens->setUnique(true);
	m_actionActivation_EOperation_takeOfferedTokens->setOrdered(false);
	
	
	m_actionActivation_EOperation_takeTokens_InputPin->setEType(getValue_EClass());
	m_actionActivation_EOperation_takeTokens_InputPin->setName("takeTokens");
	m_actionActivation_EOperation_takeTokens_InputPin->setLowerBound(0);
	m_actionActivation_EOperation_takeTokens_InputPin->setUpperBound(-1);
	m_actionActivation_EOperation_takeTokens_InputPin->setUnique(true);
	m_actionActivation_EOperation_takeTokens_InputPin->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_EOperation_takeTokens_InputPin);
		parameter->setName("pin");
		parameter->setEType(uml::UmlPackage::eInstance()->getInputPin_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_EOperation_terminate->setEType(nullptr);
	m_actionActivation_EOperation_terminate->setName("terminate");
	m_actionActivation_EOperation_terminate->setLowerBound(1);
	m_actionActivation_EOperation_terminate->setUpperBound(1);
	m_actionActivation_EOperation_terminate->setUnique(true);
	m_actionActivation_EOperation_terminate->setOrdered(false);
	
	
	m_actionActivation_EOperation_valueParticipatesInLink_Value_Link->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_actionActivation_EOperation_valueParticipatesInLink_Value_Link->setName("valueParticipatesInLink");
	m_actionActivation_EOperation_valueParticipatesInLink_Value_Link->setLowerBound(1);
	m_actionActivation_EOperation_valueParticipatesInLink_Value_Link->setUpperBound(1);
	m_actionActivation_EOperation_valueParticipatesInLink_Value_Link->setUnique(true);
	m_actionActivation_EOperation_valueParticipatesInLink_Value_Link->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_EOperation_valueParticipatesInLink_Value_Link);
		parameter->setName("value");
		parameter->setEType(getValue_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_EOperation_valueParticipatesInLink_Value_Link);
		parameter->setName("link");
		parameter->setEType(getLink_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeActivityEdgeInstanceContent()
{
	m_activityEdgeInstance_EClass->setInstanceClass(nullptr);
	m_activityEdgeInstance_EClass->setName("ActivityEdgeInstance");
	m_activityEdgeInstance_EClass->setAbstract(false);
	m_activityEdgeInstance_EClass->setInterface(false);
	
	
	m_activityEdgeInstance_EReference_edge->setName("edge");
	m_activityEdgeInstance_EReference_edge->setEType(uml::UmlPackage::eInstance()->getActivityEdge_EClass());
	m_activityEdgeInstance_EReference_edge->setLowerBound(0);
	m_activityEdgeInstance_EReference_edge->setUpperBound(1);
	m_activityEdgeInstance_EReference_edge->setTransient(false);
	m_activityEdgeInstance_EReference_edge->setVolatile(false);
	m_activityEdgeInstance_EReference_edge->setChangeable(true);
	m_activityEdgeInstance_EReference_edge->setUnsettable(false);
	m_activityEdgeInstance_EReference_edge->setUnique(true);
	m_activityEdgeInstance_EReference_edge->setDerived(false);
	m_activityEdgeInstance_EReference_edge->setOrdered(false);
	m_activityEdgeInstance_EReference_edge->setContainment(false);
	m_activityEdgeInstance_EReference_edge->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityEdgeInstance_EReference_edge->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_activityEdgeInstance_EReference_edge->setEOpposite(otherEnd);
	    }
	}
	m_activityEdgeInstance_EReference_group->setName("group");
	m_activityEdgeInstance_EReference_group->setEType(getActivityNodeActivationGroup_EClass());
	m_activityEdgeInstance_EReference_group->setLowerBound(1);
	m_activityEdgeInstance_EReference_group->setUpperBound(1);
	m_activityEdgeInstance_EReference_group->setTransient(false);
	m_activityEdgeInstance_EReference_group->setVolatile(false);
	m_activityEdgeInstance_EReference_group->setChangeable(true);
	m_activityEdgeInstance_EReference_group->setUnsettable(false);
	m_activityEdgeInstance_EReference_group->setUnique(true);
	m_activityEdgeInstance_EReference_group->setDerived(false);
	m_activityEdgeInstance_EReference_group->setOrdered(false);
	m_activityEdgeInstance_EReference_group->setContainment(false);
	m_activityEdgeInstance_EReference_group->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityEdgeInstance_EReference_group->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_activityEdgeInstance_EReference_group->setEOpposite(otherEnd);
	    }
	}
	m_activityEdgeInstance_EReference_offers->setName("offers");
	m_activityEdgeInstance_EReference_offers->setEType(getOffer_EClass());
	m_activityEdgeInstance_EReference_offers->setLowerBound(0);
	m_activityEdgeInstance_EReference_offers->setUpperBound(-1);
	m_activityEdgeInstance_EReference_offers->setTransient(false);
	m_activityEdgeInstance_EReference_offers->setVolatile(false);
	m_activityEdgeInstance_EReference_offers->setChangeable(true);
	m_activityEdgeInstance_EReference_offers->setUnsettable(false);
	m_activityEdgeInstance_EReference_offers->setUnique(true);
	m_activityEdgeInstance_EReference_offers->setDerived(false);
	m_activityEdgeInstance_EReference_offers->setOrdered(false);
	m_activityEdgeInstance_EReference_offers->setContainment(false);
	m_activityEdgeInstance_EReference_offers->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityEdgeInstance_EReference_offers->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_activityEdgeInstance_EReference_offers->setEOpposite(otherEnd);
	    }
	}
	m_activityEdgeInstance_EReference_source->setName("source");
	m_activityEdgeInstance_EReference_source->setEType(getActivityNodeActivation_EClass());
	m_activityEdgeInstance_EReference_source->setLowerBound(1);
	m_activityEdgeInstance_EReference_source->setUpperBound(1);
	m_activityEdgeInstance_EReference_source->setTransient(false);
	m_activityEdgeInstance_EReference_source->setVolatile(false);
	m_activityEdgeInstance_EReference_source->setChangeable(true);
	m_activityEdgeInstance_EReference_source->setUnsettable(false);
	m_activityEdgeInstance_EReference_source->setUnique(true);
	m_activityEdgeInstance_EReference_source->setDerived(false);
	m_activityEdgeInstance_EReference_source->setOrdered(false);
	m_activityEdgeInstance_EReference_source->setContainment(false);
	m_activityEdgeInstance_EReference_source->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityEdgeInstance_EReference_source->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_activityEdgeInstance_EReference_source->setEOpposite(otherEnd);
	    }
	}
	m_activityEdgeInstance_EReference_target->setName("target");
	m_activityEdgeInstance_EReference_target->setEType(getActivityNodeActivation_EClass());
	m_activityEdgeInstance_EReference_target->setLowerBound(1);
	m_activityEdgeInstance_EReference_target->setUpperBound(1);
	m_activityEdgeInstance_EReference_target->setTransient(false);
	m_activityEdgeInstance_EReference_target->setVolatile(false);
	m_activityEdgeInstance_EReference_target->setChangeable(true);
	m_activityEdgeInstance_EReference_target->setUnsettable(false);
	m_activityEdgeInstance_EReference_target->setUnique(true);
	m_activityEdgeInstance_EReference_target->setDerived(false);
	m_activityEdgeInstance_EReference_target->setOrdered(false);
	m_activityEdgeInstance_EReference_target->setContainment(false);
	m_activityEdgeInstance_EReference_target->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityEdgeInstance_EReference_target->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_activityEdgeInstance_EReference_target->setEOpposite(otherEnd);
	    }
	}
	
	m_activityEdgeInstance_EOperation_countOfferedValue->setEType(ecore::EcorePackage::eInstance()->getEInt_EDataType());
	m_activityEdgeInstance_EOperation_countOfferedValue->setName("countOfferedValue");
	m_activityEdgeInstance_EOperation_countOfferedValue->setLowerBound(1);
	m_activityEdgeInstance_EOperation_countOfferedValue->setUpperBound(1);
	m_activityEdgeInstance_EOperation_countOfferedValue->setUnique(true);
	m_activityEdgeInstance_EOperation_countOfferedValue->setOrdered(false);
	
	
	m_activityEdgeInstance_EOperation_getOfferedTokens->setEType(getToken_EClass());
	m_activityEdgeInstance_EOperation_getOfferedTokens->setName("getOfferedTokens");
	m_activityEdgeInstance_EOperation_getOfferedTokens->setLowerBound(0);
	m_activityEdgeInstance_EOperation_getOfferedTokens->setUpperBound(-1);
	m_activityEdgeInstance_EOperation_getOfferedTokens->setUnique(true);
	m_activityEdgeInstance_EOperation_getOfferedTokens->setOrdered(false);
	
	
	m_activityEdgeInstance_EOperation_hasOffer->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_activityEdgeInstance_EOperation_hasOffer->setName("hasOffer");
	m_activityEdgeInstance_EOperation_hasOffer->setLowerBound(1);
	m_activityEdgeInstance_EOperation_hasOffer->setUpperBound(1);
	m_activityEdgeInstance_EOperation_hasOffer->setUnique(true);
	m_activityEdgeInstance_EOperation_hasOffer->setOrdered(false);
	
	
	m_activityEdgeInstance_EOperation_sendOffer_Token->setEType(nullptr);
	m_activityEdgeInstance_EOperation_sendOffer_Token->setName("sendOffer");
	m_activityEdgeInstance_EOperation_sendOffer_Token->setLowerBound(1);
	m_activityEdgeInstance_EOperation_sendOffer_Token->setUpperBound(1);
	m_activityEdgeInstance_EOperation_sendOffer_Token->setUnique(true);
	m_activityEdgeInstance_EOperation_sendOffer_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityEdgeInstance_EOperation_sendOffer_Token);
		parameter->setName("tokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityEdgeInstance_EOperation_takeOfferedTokens->setEType(getToken_EClass());
	m_activityEdgeInstance_EOperation_takeOfferedTokens->setName("takeOfferedTokens");
	m_activityEdgeInstance_EOperation_takeOfferedTokens->setLowerBound(0);
	m_activityEdgeInstance_EOperation_takeOfferedTokens->setUpperBound(-1);
	m_activityEdgeInstance_EOperation_takeOfferedTokens->setUnique(true);
	m_activityEdgeInstance_EOperation_takeOfferedTokens->setOrdered(false);
	
	
	m_activityEdgeInstance_EOperation_takeOfferedTokens_EInt->setEType(getToken_EClass());
	m_activityEdgeInstance_EOperation_takeOfferedTokens_EInt->setName("takeOfferedTokens");
	m_activityEdgeInstance_EOperation_takeOfferedTokens_EInt->setLowerBound(0);
	m_activityEdgeInstance_EOperation_takeOfferedTokens_EInt->setUpperBound(-1);
	m_activityEdgeInstance_EOperation_takeOfferedTokens_EInt->setUnique(true);
	m_activityEdgeInstance_EOperation_takeOfferedTokens_EInt->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityEdgeInstance_EOperation_takeOfferedTokens_EInt);
		parameter->setName("maxCount");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEInt_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeActivityExecutionContent()
{
	m_activityExecution_EClass->setInstanceClass(nullptr);
	m_activityExecution_EClass->setName("ActivityExecution");
	m_activityExecution_EClass->setAbstract(false);
	m_activityExecution_EClass->setInterface(false);
	
	
	m_activityExecution_EReference_activationGroup->setName("activationGroup");
	m_activityExecution_EReference_activationGroup->setEType(getActivityNodeActivationGroup_EClass());
	m_activityExecution_EReference_activationGroup->setLowerBound(1);
	m_activityExecution_EReference_activationGroup->setUpperBound(1);
	m_activityExecution_EReference_activationGroup->setTransient(false);
	m_activityExecution_EReference_activationGroup->setVolatile(false);
	m_activityExecution_EReference_activationGroup->setChangeable(true);
	m_activityExecution_EReference_activationGroup->setUnsettable(false);
	m_activityExecution_EReference_activationGroup->setUnique(true);
	m_activityExecution_EReference_activationGroup->setDerived(false);
	m_activityExecution_EReference_activationGroup->setOrdered(false);
	m_activityExecution_EReference_activationGroup->setContainment(true);
	m_activityExecution_EReference_activationGroup->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityExecution_EReference_activationGroup->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_activityExecution_EReference_activationGroup->setEOpposite(otherEnd);
	    }
	}
	
	m_activityExecution_EOperation_execute->setEType(nullptr);
	m_activityExecution_EOperation_execute->setName("execute");
	m_activityExecution_EOperation_execute->setLowerBound(1);
	m_activityExecution_EOperation_execute->setUpperBound(1);
	m_activityExecution_EOperation_execute->setUnique(true);
	m_activityExecution_EOperation_execute->setOrdered(false);
	
	
	m_activityExecution_EOperation_new_->setEType(getValue_EClass());
	m_activityExecution_EOperation_new_->setName("new_");
	m_activityExecution_EOperation_new_->setLowerBound(1);
	m_activityExecution_EOperation_new_->setUpperBound(1);
	m_activityExecution_EOperation_new_->setUnique(true);
	m_activityExecution_EOperation_new_->setOrdered(false);
	
	
	m_activityExecution_EOperation_terminate->setEType(nullptr);
	m_activityExecution_EOperation_terminate->setName("terminate");
	m_activityExecution_EOperation_terminate->setLowerBound(1);
	m_activityExecution_EOperation_terminate->setUpperBound(1);
	m_activityExecution_EOperation_terminate->setUnique(true);
	m_activityExecution_EOperation_terminate->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeActivityFinalNodeActivationContent()
{
	m_activityFinalNodeActivation_EClass->setInstanceClass(nullptr);
	m_activityFinalNodeActivation_EClass->setName("ActivityFinalNodeActivation");
	m_activityFinalNodeActivation_EClass->setAbstract(false);
	m_activityFinalNodeActivation_EClass->setInterface(false);
	
	
	
	m_activityFinalNodeActivation_EOperation_fire_Token->setEType(nullptr);
	m_activityFinalNodeActivation_EOperation_fire_Token->setName("fire");
	m_activityFinalNodeActivation_EOperation_fire_Token->setLowerBound(1);
	m_activityFinalNodeActivation_EOperation_fire_Token->setUpperBound(1);
	m_activityFinalNodeActivation_EOperation_fire_Token->setUnique(true);
	m_activityFinalNodeActivation_EOperation_fire_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityFinalNodeActivation_EOperation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeActivityNodeActivationContent()
{
	m_activityNodeActivation_EClass->setInstanceClass(nullptr);
	m_activityNodeActivation_EClass->setName("ActivityNodeActivation");
	m_activityNodeActivation_EClass->setAbstract(true);
	m_activityNodeActivation_EClass->setInterface(false);
	
	m_activityNodeActivation_EAttribute_running = getActivityNodeActivation_EAttribute_running();
	m_activityNodeActivation_EAttribute_running->setName("running");
	m_activityNodeActivation_EAttribute_running->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_activityNodeActivation_EAttribute_running->setLowerBound(1);
	m_activityNodeActivation_EAttribute_running->setUpperBound(1);
	m_activityNodeActivation_EAttribute_running->setTransient(false);
	m_activityNodeActivation_EAttribute_running->setVolatile(false);
	m_activityNodeActivation_EAttribute_running->setChangeable(true);
	m_activityNodeActivation_EAttribute_running->setUnsettable(false);
	m_activityNodeActivation_EAttribute_running->setUnique(true);
	m_activityNodeActivation_EAttribute_running->setDerived(false);
	m_activityNodeActivation_EAttribute_running->setOrdered(false);
	m_activityNodeActivation_EAttribute_running->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_activityNodeActivation_EAttribute_running->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_activityNodeActivation_EReference_group->setName("group");
	m_activityNodeActivation_EReference_group->setEType(getActivityNodeActivationGroup_EClass());
	m_activityNodeActivation_EReference_group->setLowerBound(1);
	m_activityNodeActivation_EReference_group->setUpperBound(1);
	m_activityNodeActivation_EReference_group->setTransient(false);
	m_activityNodeActivation_EReference_group->setVolatile(false);
	m_activityNodeActivation_EReference_group->setChangeable(true);
	m_activityNodeActivation_EReference_group->setUnsettable(false);
	m_activityNodeActivation_EReference_group->setUnique(true);
	m_activityNodeActivation_EReference_group->setDerived(false);
	m_activityNodeActivation_EReference_group->setOrdered(false);
	m_activityNodeActivation_EReference_group->setContainment(false);
	m_activityNodeActivation_EReference_group->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityNodeActivation_EReference_group->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_activityNodeActivation_EReference_group->setEOpposite(otherEnd);
	    }
	}
	m_activityNodeActivation_EReference_heldTokens->setName("heldTokens");
	m_activityNodeActivation_EReference_heldTokens->setEType(getToken_EClass());
	m_activityNodeActivation_EReference_heldTokens->setLowerBound(0);
	m_activityNodeActivation_EReference_heldTokens->setUpperBound(-1);
	m_activityNodeActivation_EReference_heldTokens->setTransient(false);
	m_activityNodeActivation_EReference_heldTokens->setVolatile(false);
	m_activityNodeActivation_EReference_heldTokens->setChangeable(true);
	m_activityNodeActivation_EReference_heldTokens->setUnsettable(false);
	m_activityNodeActivation_EReference_heldTokens->setUnique(true);
	m_activityNodeActivation_EReference_heldTokens->setDerived(false);
	m_activityNodeActivation_EReference_heldTokens->setOrdered(false);
	m_activityNodeActivation_EReference_heldTokens->setContainment(true);
	m_activityNodeActivation_EReference_heldTokens->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityNodeActivation_EReference_heldTokens->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getToken_EReference_holder();
		if (otherEnd != nullptr)
	    {
	   		m_activityNodeActivation_EReference_heldTokens->setEOpposite(otherEnd);
	    }
	}
	m_activityNodeActivation_EReference_incomingEdges->setName("incomingEdges");
	m_activityNodeActivation_EReference_incomingEdges->setEType(getActivityEdgeInstance_EClass());
	m_activityNodeActivation_EReference_incomingEdges->setLowerBound(0);
	m_activityNodeActivation_EReference_incomingEdges->setUpperBound(-1);
	m_activityNodeActivation_EReference_incomingEdges->setTransient(false);
	m_activityNodeActivation_EReference_incomingEdges->setVolatile(false);
	m_activityNodeActivation_EReference_incomingEdges->setChangeable(true);
	m_activityNodeActivation_EReference_incomingEdges->setUnsettable(false);
	m_activityNodeActivation_EReference_incomingEdges->setUnique(true);
	m_activityNodeActivation_EReference_incomingEdges->setDerived(false);
	m_activityNodeActivation_EReference_incomingEdges->setOrdered(false);
	m_activityNodeActivation_EReference_incomingEdges->setContainment(false);
	m_activityNodeActivation_EReference_incomingEdges->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityNodeActivation_EReference_incomingEdges->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_activityNodeActivation_EReference_incomingEdges->setEOpposite(otherEnd);
	    }
	}
	m_activityNodeActivation_EReference_node->setName("node");
	m_activityNodeActivation_EReference_node->setEType(uml::UmlPackage::eInstance()->getActivityNode_EClass());
	m_activityNodeActivation_EReference_node->setLowerBound(0);
	m_activityNodeActivation_EReference_node->setUpperBound(1);
	m_activityNodeActivation_EReference_node->setTransient(false);
	m_activityNodeActivation_EReference_node->setVolatile(false);
	m_activityNodeActivation_EReference_node->setChangeable(true);
	m_activityNodeActivation_EReference_node->setUnsettable(false);
	m_activityNodeActivation_EReference_node->setUnique(true);
	m_activityNodeActivation_EReference_node->setDerived(false);
	m_activityNodeActivation_EReference_node->setOrdered(false);
	m_activityNodeActivation_EReference_node->setContainment(false);
	m_activityNodeActivation_EReference_node->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityNodeActivation_EReference_node->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_activityNodeActivation_EReference_node->setEOpposite(otherEnd);
	    }
	}
	m_activityNodeActivation_EReference_outgoingEdges->setName("outgoingEdges");
	m_activityNodeActivation_EReference_outgoingEdges->setEType(getActivityEdgeInstance_EClass());
	m_activityNodeActivation_EReference_outgoingEdges->setLowerBound(0);
	m_activityNodeActivation_EReference_outgoingEdges->setUpperBound(-1);
	m_activityNodeActivation_EReference_outgoingEdges->setTransient(false);
	m_activityNodeActivation_EReference_outgoingEdges->setVolatile(false);
	m_activityNodeActivation_EReference_outgoingEdges->setChangeable(true);
	m_activityNodeActivation_EReference_outgoingEdges->setUnsettable(false);
	m_activityNodeActivation_EReference_outgoingEdges->setUnique(true);
	m_activityNodeActivation_EReference_outgoingEdges->setDerived(false);
	m_activityNodeActivation_EReference_outgoingEdges->setOrdered(false);
	m_activityNodeActivation_EReference_outgoingEdges->setContainment(false);
	m_activityNodeActivation_EReference_outgoingEdges->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityNodeActivation_EReference_outgoingEdges->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_activityNodeActivation_EReference_outgoingEdges->setEOpposite(otherEnd);
	    }
	}
	
	m_activityNodeActivation_EOperation_addIncomingEdge_ActivityEdgeInstance->setEType(nullptr);
	m_activityNodeActivation_EOperation_addIncomingEdge_ActivityEdgeInstance->setName("addIncomingEdge");
	m_activityNodeActivation_EOperation_addIncomingEdge_ActivityEdgeInstance->setLowerBound(1);
	m_activityNodeActivation_EOperation_addIncomingEdge_ActivityEdgeInstance->setUpperBound(1);
	m_activityNodeActivation_EOperation_addIncomingEdge_ActivityEdgeInstance->setUnique(true);
	m_activityNodeActivation_EOperation_addIncomingEdge_ActivityEdgeInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivation_EOperation_addIncomingEdge_ActivityEdgeInstance);
		parameter->setName("edge");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_EOperation_addOutgoingEdge_ActivityEdgeInstance->setEType(nullptr);
	m_activityNodeActivation_EOperation_addOutgoingEdge_ActivityEdgeInstance->setName("addOutgoingEdge");
	m_activityNodeActivation_EOperation_addOutgoingEdge_ActivityEdgeInstance->setLowerBound(1);
	m_activityNodeActivation_EOperation_addOutgoingEdge_ActivityEdgeInstance->setUpperBound(1);
	m_activityNodeActivation_EOperation_addOutgoingEdge_ActivityEdgeInstance->setUnique(true);
	m_activityNodeActivation_EOperation_addOutgoingEdge_ActivityEdgeInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivation_EOperation_addOutgoingEdge_ActivityEdgeInstance);
		parameter->setName("edge");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_EOperation_addToken_Token->setEType(nullptr);
	m_activityNodeActivation_EOperation_addToken_Token->setName("addToken");
	m_activityNodeActivation_EOperation_addToken_Token->setLowerBound(1);
	m_activityNodeActivation_EOperation_addToken_Token->setUpperBound(1);
	m_activityNodeActivation_EOperation_addToken_Token->setUnique(true);
	m_activityNodeActivation_EOperation_addToken_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivation_EOperation_addToken_Token);
		parameter->setName("token");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_EOperation_addTokens_Token->setEType(nullptr);
	m_activityNodeActivation_EOperation_addTokens_Token->setName("addTokens");
	m_activityNodeActivation_EOperation_addTokens_Token->setLowerBound(1);
	m_activityNodeActivation_EOperation_addTokens_Token->setUpperBound(1);
	m_activityNodeActivation_EOperation_addTokens_Token->setUnique(true);
	m_activityNodeActivation_EOperation_addTokens_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivation_EOperation_addTokens_Token);
		parameter->setName("tokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_EOperation_clearTokens->setEType(nullptr);
	m_activityNodeActivation_EOperation_clearTokens->setName("clearTokens");
	m_activityNodeActivation_EOperation_clearTokens->setLowerBound(1);
	m_activityNodeActivation_EOperation_clearTokens->setUpperBound(1);
	m_activityNodeActivation_EOperation_clearTokens->setUnique(true);
	m_activityNodeActivation_EOperation_clearTokens->setOrdered(false);
	
	
	m_activityNodeActivation_EOperation_createEdgeInstances->setEType(nullptr);
	m_activityNodeActivation_EOperation_createEdgeInstances->setName("createEdgeInstances");
	m_activityNodeActivation_EOperation_createEdgeInstances->setLowerBound(1);
	m_activityNodeActivation_EOperation_createEdgeInstances->setUpperBound(1);
	m_activityNodeActivation_EOperation_createEdgeInstances->setUnique(true);
	m_activityNodeActivation_EOperation_createEdgeInstances->setOrdered(false);
	
	
	m_activityNodeActivation_EOperation_createNodeActivations->setEType(nullptr);
	m_activityNodeActivation_EOperation_createNodeActivations->setName("createNodeActivations");
	m_activityNodeActivation_EOperation_createNodeActivations->setLowerBound(1);
	m_activityNodeActivation_EOperation_createNodeActivations->setUpperBound(1);
	m_activityNodeActivation_EOperation_createNodeActivations->setUnique(true);
	m_activityNodeActivation_EOperation_createNodeActivations->setOrdered(false);
	
	
	m_activityNodeActivation_EOperation_fire_Token->setEType(nullptr);
	m_activityNodeActivation_EOperation_fire_Token->setName("fire");
	m_activityNodeActivation_EOperation_fire_Token->setLowerBound(1);
	m_activityNodeActivation_EOperation_fire_Token->setUpperBound(1);
	m_activityNodeActivation_EOperation_fire_Token->setUnique(true);
	m_activityNodeActivation_EOperation_fire_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivation_EOperation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_EOperation_getActivityExecution->setEType(getActivityExecution_EClass());
	m_activityNodeActivation_EOperation_getActivityExecution->setName("getActivityExecution");
	m_activityNodeActivation_EOperation_getActivityExecution->setLowerBound(1);
	m_activityNodeActivation_EOperation_getActivityExecution->setUpperBound(1);
	m_activityNodeActivation_EOperation_getActivityExecution->setUnique(true);
	m_activityNodeActivation_EOperation_getActivityExecution->setOrdered(false);
	
	
	m_activityNodeActivation_EOperation_getExecutionContext->setEType(getObject_EClass());
	m_activityNodeActivation_EOperation_getExecutionContext->setName("getExecutionContext");
	m_activityNodeActivation_EOperation_getExecutionContext->setLowerBound(1);
	m_activityNodeActivation_EOperation_getExecutionContext->setUpperBound(1);
	m_activityNodeActivation_EOperation_getExecutionContext->setUnique(true);
	m_activityNodeActivation_EOperation_getExecutionContext->setOrdered(false);
	
	
	m_activityNodeActivation_EOperation_getExecutionLocus->setEType(getLocus_EClass());
	m_activityNodeActivation_EOperation_getExecutionLocus->setName("getExecutionLocus");
	m_activityNodeActivation_EOperation_getExecutionLocus->setLowerBound(1);
	m_activityNodeActivation_EOperation_getExecutionLocus->setUpperBound(1);
	m_activityNodeActivation_EOperation_getExecutionLocus->setUnique(true);
	m_activityNodeActivation_EOperation_getExecutionLocus->setOrdered(false);
	
	
	m_activityNodeActivation_EOperation_getNodeActivation_ActivityNode->setEType(getActivityNodeActivation_EClass());
	m_activityNodeActivation_EOperation_getNodeActivation_ActivityNode->setName("getNodeActivation");
	m_activityNodeActivation_EOperation_getNodeActivation_ActivityNode->setLowerBound(1);
	m_activityNodeActivation_EOperation_getNodeActivation_ActivityNode->setUpperBound(1);
	m_activityNodeActivation_EOperation_getNodeActivation_ActivityNode->setUnique(true);
	m_activityNodeActivation_EOperation_getNodeActivation_ActivityNode->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivation_EOperation_getNodeActivation_ActivityNode);
		parameter->setName("node");
		parameter->setEType(uml::UmlPackage::eInstance()->getActivityNode_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_EOperation_getRunning->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_activityNodeActivation_EOperation_getRunning->setName("getRunning");
	m_activityNodeActivation_EOperation_getRunning->setLowerBound(1);
	m_activityNodeActivation_EOperation_getRunning->setUpperBound(1);
	m_activityNodeActivation_EOperation_getRunning->setUnique(true);
	m_activityNodeActivation_EOperation_getRunning->setOrdered(false);
	
	
	m_activityNodeActivation_EOperation_getTokens->setEType(getToken_EClass());
	m_activityNodeActivation_EOperation_getTokens->setName("getTokens");
	m_activityNodeActivation_EOperation_getTokens->setLowerBound(0);
	m_activityNodeActivation_EOperation_getTokens->setUpperBound(-1);
	m_activityNodeActivation_EOperation_getTokens->setUnique(true);
	m_activityNodeActivation_EOperation_getTokens->setOrdered(false);
	
	
	m_activityNodeActivation_EOperation_isReady->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_activityNodeActivation_EOperation_isReady->setName("isReady");
	m_activityNodeActivation_EOperation_isReady->setLowerBound(1);
	m_activityNodeActivation_EOperation_isReady->setUpperBound(1);
	m_activityNodeActivation_EOperation_isReady->setUnique(true);
	m_activityNodeActivation_EOperation_isReady->setOrdered(false);
	
	
	m_activityNodeActivation_EOperation_isSourceFor_ActivityEdgeInstance->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_activityNodeActivation_EOperation_isSourceFor_ActivityEdgeInstance->setName("isSourceFor");
	m_activityNodeActivation_EOperation_isSourceFor_ActivityEdgeInstance->setLowerBound(1);
	m_activityNodeActivation_EOperation_isSourceFor_ActivityEdgeInstance->setUpperBound(1);
	m_activityNodeActivation_EOperation_isSourceFor_ActivityEdgeInstance->setUnique(true);
	m_activityNodeActivation_EOperation_isSourceFor_ActivityEdgeInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivation_EOperation_isSourceFor_ActivityEdgeInstance);
		parameter->setName("edgeInstances");
		parameter->setEType(getActivityEdgeInstance_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_EOperation_recieveOffer->setEType(nullptr);
	m_activityNodeActivation_EOperation_recieveOffer->setName("recieveOffer");
	m_activityNodeActivation_EOperation_recieveOffer->setLowerBound(1);
	m_activityNodeActivation_EOperation_recieveOffer->setUpperBound(1);
	m_activityNodeActivation_EOperation_recieveOffer->setUnique(true);
	m_activityNodeActivation_EOperation_recieveOffer->setOrdered(false);
	
	
	m_activityNodeActivation_EOperation_removeToken_Token->setEType(ecore::EcorePackage::eInstance()->getEInt_EDataType());
	m_activityNodeActivation_EOperation_removeToken_Token->setName("removeToken");
	m_activityNodeActivation_EOperation_removeToken_Token->setLowerBound(1);
	m_activityNodeActivation_EOperation_removeToken_Token->setUpperBound(1);
	m_activityNodeActivation_EOperation_removeToken_Token->setUnique(true);
	m_activityNodeActivation_EOperation_removeToken_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivation_EOperation_removeToken_Token);
		parameter->setName("token");
		parameter->setEType(getToken_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_EOperation_resume->setEType(nullptr);
	m_activityNodeActivation_EOperation_resume->setName("resume");
	m_activityNodeActivation_EOperation_resume->setLowerBound(1);
	m_activityNodeActivation_EOperation_resume->setUpperBound(1);
	m_activityNodeActivation_EOperation_resume->setUnique(true);
	m_activityNodeActivation_EOperation_resume->setOrdered(false);
	
	
	m_activityNodeActivation_EOperation_run->setEType(nullptr);
	m_activityNodeActivation_EOperation_run->setName("run");
	m_activityNodeActivation_EOperation_run->setLowerBound(1);
	m_activityNodeActivation_EOperation_run->setUpperBound(1);
	m_activityNodeActivation_EOperation_run->setUnique(true);
	m_activityNodeActivation_EOperation_run->setOrdered(false);
	
	
	m_activityNodeActivation_EOperation_sendOffers_Token->setEType(nullptr);
	m_activityNodeActivation_EOperation_sendOffers_Token->setName("sendOffers");
	m_activityNodeActivation_EOperation_sendOffers_Token->setLowerBound(0);
	m_activityNodeActivation_EOperation_sendOffers_Token->setUpperBound(1);
	m_activityNodeActivation_EOperation_sendOffers_Token->setUnique(true);
	m_activityNodeActivation_EOperation_sendOffers_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivation_EOperation_sendOffers_Token);
		parameter->setName("tokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_EOperation_suspend->setEType(nullptr);
	m_activityNodeActivation_EOperation_suspend->setName("suspend");
	m_activityNodeActivation_EOperation_suspend->setLowerBound(1);
	m_activityNodeActivation_EOperation_suspend->setUpperBound(1);
	m_activityNodeActivation_EOperation_suspend->setUnique(true);
	m_activityNodeActivation_EOperation_suspend->setOrdered(false);
	
	
	m_activityNodeActivation_EOperation_takeOfferedTokens->setEType(getToken_EClass());
	m_activityNodeActivation_EOperation_takeOfferedTokens->setName("takeOfferedTokens");
	m_activityNodeActivation_EOperation_takeOfferedTokens->setLowerBound(0);
	m_activityNodeActivation_EOperation_takeOfferedTokens->setUpperBound(-1);
	m_activityNodeActivation_EOperation_takeOfferedTokens->setUnique(true);
	m_activityNodeActivation_EOperation_takeOfferedTokens->setOrdered(false);
	
	
	m_activityNodeActivation_EOperation_takeTokens->setEType(getToken_EClass());
	m_activityNodeActivation_EOperation_takeTokens->setName("takeTokens");
	m_activityNodeActivation_EOperation_takeTokens->setLowerBound(1);
	m_activityNodeActivation_EOperation_takeTokens->setUpperBound(-1);
	m_activityNodeActivation_EOperation_takeTokens->setUnique(true);
	m_activityNodeActivation_EOperation_takeTokens->setOrdered(false);
	
	
	m_activityNodeActivation_EOperation_terminate->setEType(nullptr);
	m_activityNodeActivation_EOperation_terminate->setName("terminate");
	m_activityNodeActivation_EOperation_terminate->setLowerBound(1);
	m_activityNodeActivation_EOperation_terminate->setUpperBound(1);
	m_activityNodeActivation_EOperation_terminate->setUnique(true);
	m_activityNodeActivation_EOperation_terminate->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeActivityNodeActivationGroupContent()
{
	m_activityNodeActivationGroup_EClass->setInstanceClass(nullptr);
	m_activityNodeActivationGroup_EClass->setName("ActivityNodeActivationGroup");
	m_activityNodeActivationGroup_EClass->setAbstract(false);
	m_activityNodeActivationGroup_EClass->setInterface(false);
	
	
	m_activityNodeActivationGroup_EReference_activityExecution->setName("activityExecution");
	m_activityNodeActivationGroup_EReference_activityExecution->setEType(getActivityExecution_EClass());
	m_activityNodeActivationGroup_EReference_activityExecution->setLowerBound(0);
	m_activityNodeActivationGroup_EReference_activityExecution->setUpperBound(1);
	m_activityNodeActivationGroup_EReference_activityExecution->setTransient(false);
	m_activityNodeActivationGroup_EReference_activityExecution->setVolatile(false);
	m_activityNodeActivationGroup_EReference_activityExecution->setChangeable(true);
	m_activityNodeActivationGroup_EReference_activityExecution->setUnsettable(false);
	m_activityNodeActivationGroup_EReference_activityExecution->setUnique(true);
	m_activityNodeActivationGroup_EReference_activityExecution->setDerived(false);
	m_activityNodeActivationGroup_EReference_activityExecution->setOrdered(true);
	m_activityNodeActivationGroup_EReference_activityExecution->setContainment(false);
	m_activityNodeActivationGroup_EReference_activityExecution->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityNodeActivationGroup_EReference_activityExecution->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_activityNodeActivationGroup_EReference_activityExecution->setEOpposite(otherEnd);
	    }
	}
	m_activityNodeActivationGroup_EReference_containingNodeActivation->setName("containingNodeActivation");
	m_activityNodeActivationGroup_EReference_containingNodeActivation->setEType(getStructuredActivityNodeActivation_EClass());
	m_activityNodeActivationGroup_EReference_containingNodeActivation->setLowerBound(0);
	m_activityNodeActivationGroup_EReference_containingNodeActivation->setUpperBound(1);
	m_activityNodeActivationGroup_EReference_containingNodeActivation->setTransient(false);
	m_activityNodeActivationGroup_EReference_containingNodeActivation->setVolatile(false);
	m_activityNodeActivationGroup_EReference_containingNodeActivation->setChangeable(true);
	m_activityNodeActivationGroup_EReference_containingNodeActivation->setUnsettable(false);
	m_activityNodeActivationGroup_EReference_containingNodeActivation->setUnique(true);
	m_activityNodeActivationGroup_EReference_containingNodeActivation->setDerived(false);
	m_activityNodeActivationGroup_EReference_containingNodeActivation->setOrdered(false);
	m_activityNodeActivationGroup_EReference_containingNodeActivation->setContainment(false);
	m_activityNodeActivationGroup_EReference_containingNodeActivation->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityNodeActivationGroup_EReference_containingNodeActivation->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_activityNodeActivationGroup_EReference_containingNodeActivation->setEOpposite(otherEnd);
	    }
	}
	m_activityNodeActivationGroup_EReference_edgeInstances->setName("edgeInstances");
	m_activityNodeActivationGroup_EReference_edgeInstances->setEType(getActivityEdgeInstance_EClass());
	m_activityNodeActivationGroup_EReference_edgeInstances->setLowerBound(0);
	m_activityNodeActivationGroup_EReference_edgeInstances->setUpperBound(-1);
	m_activityNodeActivationGroup_EReference_edgeInstances->setTransient(false);
	m_activityNodeActivationGroup_EReference_edgeInstances->setVolatile(false);
	m_activityNodeActivationGroup_EReference_edgeInstances->setChangeable(true);
	m_activityNodeActivationGroup_EReference_edgeInstances->setUnsettable(false);
	m_activityNodeActivationGroup_EReference_edgeInstances->setUnique(true);
	m_activityNodeActivationGroup_EReference_edgeInstances->setDerived(false);
	m_activityNodeActivationGroup_EReference_edgeInstances->setOrdered(false);
	m_activityNodeActivationGroup_EReference_edgeInstances->setContainment(true);
	m_activityNodeActivationGroup_EReference_edgeInstances->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityNodeActivationGroup_EReference_edgeInstances->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_activityNodeActivationGroup_EReference_edgeInstances->setEOpposite(otherEnd);
	    }
	}
	m_activityNodeActivationGroup_EReference_nodeActivations->setName("nodeActivations");
	m_activityNodeActivationGroup_EReference_nodeActivations->setEType(getActivityNodeActivation_EClass());
	m_activityNodeActivationGroup_EReference_nodeActivations->setLowerBound(0);
	m_activityNodeActivationGroup_EReference_nodeActivations->setUpperBound(-1);
	m_activityNodeActivationGroup_EReference_nodeActivations->setTransient(false);
	m_activityNodeActivationGroup_EReference_nodeActivations->setVolatile(false);
	m_activityNodeActivationGroup_EReference_nodeActivations->setChangeable(true);
	m_activityNodeActivationGroup_EReference_nodeActivations->setUnsettable(false);
	m_activityNodeActivationGroup_EReference_nodeActivations->setUnique(true);
	m_activityNodeActivationGroup_EReference_nodeActivations->setDerived(false);
	m_activityNodeActivationGroup_EReference_nodeActivations->setOrdered(false);
	m_activityNodeActivationGroup_EReference_nodeActivations->setContainment(true);
	m_activityNodeActivationGroup_EReference_nodeActivations->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityNodeActivationGroup_EReference_nodeActivations->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_activityNodeActivationGroup_EReference_nodeActivations->setEOpposite(otherEnd);
	    }
	}
	m_activityNodeActivationGroup_EReference_suspendedActivations->setName("suspendedActivations");
	m_activityNodeActivationGroup_EReference_suspendedActivations->setEType(getActivityNodeActivation_EClass());
	m_activityNodeActivationGroup_EReference_suspendedActivations->setLowerBound(0);
	m_activityNodeActivationGroup_EReference_suspendedActivations->setUpperBound(-1);
	m_activityNodeActivationGroup_EReference_suspendedActivations->setTransient(false);
	m_activityNodeActivationGroup_EReference_suspendedActivations->setVolatile(false);
	m_activityNodeActivationGroup_EReference_suspendedActivations->setChangeable(true);
	m_activityNodeActivationGroup_EReference_suspendedActivations->setUnsettable(false);
	m_activityNodeActivationGroup_EReference_suspendedActivations->setUnique(true);
	m_activityNodeActivationGroup_EReference_suspendedActivations->setDerived(false);
	m_activityNodeActivationGroup_EReference_suspendedActivations->setOrdered(false);
	m_activityNodeActivationGroup_EReference_suspendedActivations->setContainment(false);
	m_activityNodeActivationGroup_EReference_suspendedActivations->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityNodeActivationGroup_EReference_suspendedActivations->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_activityNodeActivationGroup_EReference_suspendedActivations->setEOpposite(otherEnd);
	    }
	}
	
	m_activityNodeActivationGroup_EOperation_activate_ActivityNode_ActivityEdge->setEType(nullptr);
	m_activityNodeActivationGroup_EOperation_activate_ActivityNode_ActivityEdge->setName("activate");
	m_activityNodeActivationGroup_EOperation_activate_ActivityNode_ActivityEdge->setLowerBound(1);
	m_activityNodeActivationGroup_EOperation_activate_ActivityNode_ActivityEdge->setUpperBound(1);
	m_activityNodeActivationGroup_EOperation_activate_ActivityNode_ActivityEdge->setUnique(true);
	m_activityNodeActivationGroup_EOperation_activate_ActivityNode_ActivityEdge->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_EOperation_activate_ActivityNode_ActivityEdge);
		parameter->setName("nodes");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_EOperation_activate_ActivityNode_ActivityEdge);
		parameter->setName("edges");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_EOperation_addEdgeInstance_ActivityEdgeInstance->setEType(nullptr);
	m_activityNodeActivationGroup_EOperation_addEdgeInstance_ActivityEdgeInstance->setName("addEdgeInstance");
	m_activityNodeActivationGroup_EOperation_addEdgeInstance_ActivityEdgeInstance->setLowerBound(1);
	m_activityNodeActivationGroup_EOperation_addEdgeInstance_ActivityEdgeInstance->setUpperBound(1);
	m_activityNodeActivationGroup_EOperation_addEdgeInstance_ActivityEdgeInstance->setUnique(true);
	m_activityNodeActivationGroup_EOperation_addEdgeInstance_ActivityEdgeInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_EOperation_addEdgeInstance_ActivityEdgeInstance);
		parameter->setName("instance");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_EOperation_addNodeActivation_ActivityNodeActivation->setEType(nullptr);
	m_activityNodeActivationGroup_EOperation_addNodeActivation_ActivityNodeActivation->setName("addNodeActivation");
	m_activityNodeActivationGroup_EOperation_addNodeActivation_ActivityNodeActivation->setLowerBound(1);
	m_activityNodeActivationGroup_EOperation_addNodeActivation_ActivityNodeActivation->setUpperBound(1);
	m_activityNodeActivationGroup_EOperation_addNodeActivation_ActivityNodeActivation->setUnique(true);
	m_activityNodeActivationGroup_EOperation_addNodeActivation_ActivityNodeActivation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_EOperation_addNodeActivation_ActivityNodeActivation);
		parameter->setName("activation");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_EOperation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_activityNodeActivationGroup_EOperation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation->setName("checkIncomingEdges");
	m_activityNodeActivationGroup_EOperation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation->setLowerBound(1);
	m_activityNodeActivationGroup_EOperation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation->setUpperBound(1);
	m_activityNodeActivationGroup_EOperation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation->setUnique(true);
	m_activityNodeActivationGroup_EOperation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_EOperation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation);
		parameter->setName("incomingEdges");
		parameter->setEType(getActivityEdgeInstance_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_EOperation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation);
		parameter->setName("activations");
		parameter->setEType(getActivityNodeActivation_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_EOperation_createEdgeInstance_ActivityEdge->setEType(nullptr);
	m_activityNodeActivationGroup_EOperation_createEdgeInstance_ActivityEdge->setName("createEdgeInstance");
	m_activityNodeActivationGroup_EOperation_createEdgeInstance_ActivityEdge->setLowerBound(1);
	m_activityNodeActivationGroup_EOperation_createEdgeInstance_ActivityEdge->setUpperBound(1);
	m_activityNodeActivationGroup_EOperation_createEdgeInstance_ActivityEdge->setUnique(true);
	m_activityNodeActivationGroup_EOperation_createEdgeInstance_ActivityEdge->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_EOperation_createEdgeInstance_ActivityEdge);
		parameter->setName("edges");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_EOperation_createNodeActivation_ActivityNode->setEType(getActivityNodeActivation_EClass());
	m_activityNodeActivationGroup_EOperation_createNodeActivation_ActivityNode->setName("createNodeActivation");
	m_activityNodeActivationGroup_EOperation_createNodeActivation_ActivityNode->setLowerBound(1);
	m_activityNodeActivationGroup_EOperation_createNodeActivation_ActivityNode->setUpperBound(1);
	m_activityNodeActivationGroup_EOperation_createNodeActivation_ActivityNode->setUnique(true);
	m_activityNodeActivationGroup_EOperation_createNodeActivation_ActivityNode->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_EOperation_createNodeActivation_ActivityNode);
		parameter->setName("node");
		parameter->setEType(uml::UmlPackage::eInstance()->getActivityNode_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_EOperation_createNodeActivations_ActivityNode->setEType(nullptr);
	m_activityNodeActivationGroup_EOperation_createNodeActivations_ActivityNode->setName("createNodeActivations");
	m_activityNodeActivationGroup_EOperation_createNodeActivations_ActivityNode->setLowerBound(1);
	m_activityNodeActivationGroup_EOperation_createNodeActivations_ActivityNode->setUpperBound(1);
	m_activityNodeActivationGroup_EOperation_createNodeActivations_ActivityNode->setUnique(true);
	m_activityNodeActivationGroup_EOperation_createNodeActivations_ActivityNode->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_EOperation_createNodeActivations_ActivityNode);
		parameter->setName("nodes");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_EOperation_getNodeActivation_ActivityNode->setEType(getActivityNodeActivation_EClass());
	m_activityNodeActivationGroup_EOperation_getNodeActivation_ActivityNode->setName("getNodeActivation");
	m_activityNodeActivationGroup_EOperation_getNodeActivation_ActivityNode->setLowerBound(1);
	m_activityNodeActivationGroup_EOperation_getNodeActivation_ActivityNode->setUpperBound(1);
	m_activityNodeActivationGroup_EOperation_getNodeActivation_ActivityNode->setUnique(true);
	m_activityNodeActivationGroup_EOperation_getNodeActivation_ActivityNode->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_EOperation_getNodeActivation_ActivityNode);
		parameter->setName("node");
		parameter->setEType(uml::UmlPackage::eInstance()->getActivityNode_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_EOperation_getOutputParameterNodeActivations->setEType(getActivityParameterNodeActivation_EClass());
	m_activityNodeActivationGroup_EOperation_getOutputParameterNodeActivations->setName("getOutputParameterNodeActivations");
	m_activityNodeActivationGroup_EOperation_getOutputParameterNodeActivations->setLowerBound(1);
	m_activityNodeActivationGroup_EOperation_getOutputParameterNodeActivations->setUpperBound(-1);
	m_activityNodeActivationGroup_EOperation_getOutputParameterNodeActivations->setUnique(true);
	m_activityNodeActivationGroup_EOperation_getOutputParameterNodeActivations->setOrdered(false);
	
	
	m_activityNodeActivationGroup_EOperation_hasSourceFor_ActivityEdgeInstance->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_activityNodeActivationGroup_EOperation_hasSourceFor_ActivityEdgeInstance->setName("hasSourceFor");
	m_activityNodeActivationGroup_EOperation_hasSourceFor_ActivityEdgeInstance->setLowerBound(1);
	m_activityNodeActivationGroup_EOperation_hasSourceFor_ActivityEdgeInstance->setUpperBound(1);
	m_activityNodeActivationGroup_EOperation_hasSourceFor_ActivityEdgeInstance->setUnique(true);
	m_activityNodeActivationGroup_EOperation_hasSourceFor_ActivityEdgeInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_EOperation_hasSourceFor_ActivityEdgeInstance);
		parameter->setName("edgeInstance");
		parameter->setEType(getActivityEdgeInstance_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_EOperation_isSuspended->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_activityNodeActivationGroup_EOperation_isSuspended->setName("isSuspended");
	m_activityNodeActivationGroup_EOperation_isSuspended->setLowerBound(1);
	m_activityNodeActivationGroup_EOperation_isSuspended->setUpperBound(1);
	m_activityNodeActivationGroup_EOperation_isSuspended->setUnique(true);
	m_activityNodeActivationGroup_EOperation_isSuspended->setOrdered(false);
	
	
	m_activityNodeActivationGroup_EOperation_resume_ActivityNodeActivation->setEType(nullptr);
	m_activityNodeActivationGroup_EOperation_resume_ActivityNodeActivation->setName("resume");
	m_activityNodeActivationGroup_EOperation_resume_ActivityNodeActivation->setLowerBound(1);
	m_activityNodeActivationGroup_EOperation_resume_ActivityNodeActivation->setUpperBound(1);
	m_activityNodeActivationGroup_EOperation_resume_ActivityNodeActivation->setUnique(true);
	m_activityNodeActivationGroup_EOperation_resume_ActivityNodeActivation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_EOperation_resume_ActivityNodeActivation);
		parameter->setName("activation");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_EOperation_retrieveActivityExecution->setEType(getActivityExecution_EClass());
	m_activityNodeActivationGroup_EOperation_retrieveActivityExecution->setName("retrieveActivityExecution");
	m_activityNodeActivationGroup_EOperation_retrieveActivityExecution->setLowerBound(1);
	m_activityNodeActivationGroup_EOperation_retrieveActivityExecution->setUpperBound(1);
	m_activityNodeActivationGroup_EOperation_retrieveActivityExecution->setUnique(true);
	m_activityNodeActivationGroup_EOperation_retrieveActivityExecution->setOrdered(false);
	
	
	m_activityNodeActivationGroup_EOperation_run_ActivityNodeActivation->setEType(nullptr);
	m_activityNodeActivationGroup_EOperation_run_ActivityNodeActivation->setName("run");
	m_activityNodeActivationGroup_EOperation_run_ActivityNodeActivation->setLowerBound(1);
	m_activityNodeActivationGroup_EOperation_run_ActivityNodeActivation->setUpperBound(1);
	m_activityNodeActivationGroup_EOperation_run_ActivityNodeActivation->setUnique(true);
	m_activityNodeActivationGroup_EOperation_run_ActivityNodeActivation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_EOperation_run_ActivityNodeActivation);
		parameter->setName("activations");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_EOperation_runNodes_ActivityNode->setEType(nullptr);
	m_activityNodeActivationGroup_EOperation_runNodes_ActivityNode->setName("runNodes");
	m_activityNodeActivationGroup_EOperation_runNodes_ActivityNode->setLowerBound(1);
	m_activityNodeActivationGroup_EOperation_runNodes_ActivityNode->setUpperBound(1);
	m_activityNodeActivationGroup_EOperation_runNodes_ActivityNode->setUnique(true);
	m_activityNodeActivationGroup_EOperation_runNodes_ActivityNode->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_EOperation_runNodes_ActivityNode);
		parameter->setName("nodes");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_EOperation_suspend_ActivityNodeActivation->setEType(nullptr);
	m_activityNodeActivationGroup_EOperation_suspend_ActivityNodeActivation->setName("suspend");
	m_activityNodeActivationGroup_EOperation_suspend_ActivityNodeActivation->setLowerBound(1);
	m_activityNodeActivationGroup_EOperation_suspend_ActivityNodeActivation->setUpperBound(1);
	m_activityNodeActivationGroup_EOperation_suspend_ActivityNodeActivation->setUnique(true);
	m_activityNodeActivationGroup_EOperation_suspend_ActivityNodeActivation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_EOperation_suspend_ActivityNodeActivation);
		parameter->setName("activation");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_EOperation_terminateAll->setEType(nullptr);
	m_activityNodeActivationGroup_EOperation_terminateAll->setName("terminateAll");
	m_activityNodeActivationGroup_EOperation_terminateAll->setLowerBound(1);
	m_activityNodeActivationGroup_EOperation_terminateAll->setUpperBound(1);
	m_activityNodeActivationGroup_EOperation_terminateAll->setUnique(true);
	m_activityNodeActivationGroup_EOperation_terminateAll->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeActivityParameterNodeActivationContent()
{
	m_activityParameterNodeActivation_EClass->setInstanceClass(nullptr);
	m_activityParameterNodeActivation_EClass->setName("ActivityParameterNodeActivation");
	m_activityParameterNodeActivation_EClass->setAbstract(false);
	m_activityParameterNodeActivation_EClass->setInterface(false);
	
	
	
	m_activityParameterNodeActivation_EOperation_clearTokens->setEType(nullptr);
	m_activityParameterNodeActivation_EOperation_clearTokens->setName("clearTokens");
	m_activityParameterNodeActivation_EOperation_clearTokens->setLowerBound(1);
	m_activityParameterNodeActivation_EOperation_clearTokens->setUpperBound(1);
	m_activityParameterNodeActivation_EOperation_clearTokens->setUnique(true);
	m_activityParameterNodeActivation_EOperation_clearTokens->setOrdered(false);
	
	
	m_activityParameterNodeActivation_EOperation_fire_Token->setEType(nullptr);
	m_activityParameterNodeActivation_EOperation_fire_Token->setName("fire");
	m_activityParameterNodeActivation_EOperation_fire_Token->setLowerBound(1);
	m_activityParameterNodeActivation_EOperation_fire_Token->setUpperBound(1);
	m_activityParameterNodeActivation_EOperation_fire_Token->setUnique(true);
	m_activityParameterNodeActivation_EOperation_fire_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityParameterNodeActivation_EOperation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeAddStructuralFeatureValueActionActivationContent()
{
	m_addStructuralFeatureValueActionActivation_EClass->setInstanceClass(nullptr);
	m_addStructuralFeatureValueActionActivation_EClass->setName("AddStructuralFeatureValueActionActivation");
	m_addStructuralFeatureValueActionActivation_EClass->setAbstract(false);
	m_addStructuralFeatureValueActionActivation_EClass->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeBooleanValueContent()
{
	m_booleanValue_EClass->setInstanceClass(nullptr);
	m_booleanValue_EClass->setName("BooleanValue");
	m_booleanValue_EClass->setAbstract(false);
	m_booleanValue_EClass->setInterface(false);
	
	m_booleanValue_EAttribute_value = getBooleanValue_EAttribute_value();
	m_booleanValue_EAttribute_value->setName("value");
	m_booleanValue_EAttribute_value->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_booleanValue_EAttribute_value->setLowerBound(1);
	m_booleanValue_EAttribute_value->setUpperBound(1);
	m_booleanValue_EAttribute_value->setTransient(false);
	m_booleanValue_EAttribute_value->setVolatile(false);
	m_booleanValue_EAttribute_value->setChangeable(true);
	m_booleanValue_EAttribute_value->setUnsettable(false);
	m_booleanValue_EAttribute_value->setUnique(true);
	m_booleanValue_EAttribute_value->setDerived(false);
	m_booleanValue_EAttribute_value->setOrdered(false);
	m_booleanValue_EAttribute_value->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_booleanValue_EAttribute_value->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	m_booleanValue_EOperation_equals_Value->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_booleanValue_EOperation_equals_Value->setName("equals");
	m_booleanValue_EOperation_equals_Value->setLowerBound(1);
	m_booleanValue_EOperation_equals_Value->setUpperBound(1);
	m_booleanValue_EOperation_equals_Value->setUnique(true);
	m_booleanValue_EOperation_equals_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_booleanValue_EOperation_equals_Value);
		parameter->setName("otherValue");
		parameter->setEType(getValue_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_booleanValue_EOperation_specify->setEType(uml::UmlPackage::eInstance()->getValueSpecification_EClass());
	m_booleanValue_EOperation_specify->setName("specify");
	m_booleanValue_EOperation_specify->setLowerBound(1);
	m_booleanValue_EOperation_specify->setUpperBound(1);
	m_booleanValue_EOperation_specify->setUnique(true);
	m_booleanValue_EOperation_specify->setOrdered(false);
	
	
	m_booleanValue_EOperation_toString->setEType(ecore::EcorePackage::eInstance()->getEString_EDataType());
	m_booleanValue_EOperation_toString->setName("toString");
	m_booleanValue_EOperation_toString->setLowerBound(1);
	m_booleanValue_EOperation_toString->setUpperBound(1);
	m_booleanValue_EOperation_toString->setUnique(true);
	m_booleanValue_EOperation_toString->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeCallActionActivationContent()
{
	m_callActionActivation_EClass->setInstanceClass(nullptr);
	m_callActionActivation_EClass->setName("CallActionActivation");
	m_callActionActivation_EClass->setAbstract(true);
	m_callActionActivation_EClass->setInterface(false);
	
	
	m_callActionActivation_EReference_callExecutions->setName("callExecutions");
	m_callActionActivation_EReference_callExecutions->setEType(getExecution_EClass());
	m_callActionActivation_EReference_callExecutions->setLowerBound(0);
	m_callActionActivation_EReference_callExecutions->setUpperBound(-1);
	m_callActionActivation_EReference_callExecutions->setTransient(false);
	m_callActionActivation_EReference_callExecutions->setVolatile(false);
	m_callActionActivation_EReference_callExecutions->setChangeable(true);
	m_callActionActivation_EReference_callExecutions->setUnsettable(false);
	m_callActionActivation_EReference_callExecutions->setUnique(true);
	m_callActionActivation_EReference_callExecutions->setDerived(false);
	m_callActionActivation_EReference_callExecutions->setOrdered(false);
	m_callActionActivation_EReference_callExecutions->setContainment(true);
	m_callActionActivation_EReference_callExecutions->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_callActionActivation_EReference_callExecutions->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_callActionActivation_EReference_callExecutions->setEOpposite(otherEnd);
	    }
	}
	
	m_callActionActivation_EOperation_doAction->setEType(nullptr);
	m_callActionActivation_EOperation_doAction->setName("doAction");
	m_callActionActivation_EOperation_doAction->setLowerBound(1);
	m_callActionActivation_EOperation_doAction->setUpperBound(1);
	m_callActionActivation_EOperation_doAction->setUnique(true);
	m_callActionActivation_EOperation_doAction->setOrdered(false);
	
	
	m_callActionActivation_EOperation_getCallExecution->setEType(getExecution_EClass());
	m_callActionActivation_EOperation_getCallExecution->setName("getCallExecution");
	m_callActionActivation_EOperation_getCallExecution->setLowerBound(1);
	m_callActionActivation_EOperation_getCallExecution->setUpperBound(1);
	m_callActionActivation_EOperation_getCallExecution->setUnique(true);
	m_callActionActivation_EOperation_getCallExecution->setOrdered(false);
	
	
	m_callActionActivation_EOperation_removeCallExecution_Execution->setEType(nullptr);
	m_callActionActivation_EOperation_removeCallExecution_Execution->setName("removeCallExecution");
	m_callActionActivation_EOperation_removeCallExecution_Execution->setLowerBound(1);
	m_callActionActivation_EOperation_removeCallExecution_Execution->setUpperBound(1);
	m_callActionActivation_EOperation_removeCallExecution_Execution->setUnique(true);
	m_callActionActivation_EOperation_removeCallExecution_Execution->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_callActionActivation_EOperation_removeCallExecution_Execution);
		parameter->setName("execution");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_callActionActivation_EOperation_terminate->setEType(nullptr);
	m_callActionActivation_EOperation_terminate->setName("terminate");
	m_callActionActivation_EOperation_terminate->setLowerBound(1);
	m_callActionActivation_EOperation_terminate->setUpperBound(1);
	m_callActionActivation_EOperation_terminate->setUnique(true);
	m_callActionActivation_EOperation_terminate->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeCallBehaviorActionActivationContent()
{
	m_callBehaviorActionActivation_EClass->setInstanceClass(nullptr);
	m_callBehaviorActionActivation_EClass->setName("CallBehaviorActionActivation");
	m_callBehaviorActionActivation_EClass->setAbstract(false);
	m_callBehaviorActionActivation_EClass->setInterface(false);
	
	
	
	m_callBehaviorActionActivation_EOperation_getCallExecution->setEType(getExecution_EClass());
	m_callBehaviorActionActivation_EOperation_getCallExecution->setName("getCallExecution");
	m_callBehaviorActionActivation_EOperation_getCallExecution->setLowerBound(1);
	m_callBehaviorActionActivation_EOperation_getCallExecution->setUpperBound(1);
	m_callBehaviorActionActivation_EOperation_getCallExecution->setUnique(true);
	m_callBehaviorActionActivation_EOperation_getCallExecution->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeCallOperationActionActivationContent()
{
	m_callOperationActionActivation_EClass->setInstanceClass(nullptr);
	m_callOperationActionActivation_EClass->setName("CallOperationActionActivation");
	m_callOperationActionActivation_EClass->setAbstract(false);
	m_callOperationActionActivation_EClass->setInterface(false);
	
	
	
	m_callOperationActionActivation_EOperation_getCallExecution->setEType(getExecution_EClass());
	m_callOperationActionActivation_EOperation_getCallExecution->setName("getCallExecution");
	m_callOperationActionActivation_EOperation_getCallExecution->setLowerBound(1);
	m_callOperationActionActivation_EOperation_getCallExecution->setUpperBound(1);
	m_callOperationActionActivation_EOperation_getCallExecution->setUnique(true);
	m_callOperationActionActivation_EOperation_getCallExecution->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeCentralBufferNodeActivationContent()
{
	m_centralBufferNodeActivation_EClass->setInstanceClass(nullptr);
	m_centralBufferNodeActivation_EClass->setName("CentralBufferNodeActivation");
	m_centralBufferNodeActivation_EClass->setAbstract(false);
	m_centralBufferNodeActivation_EClass->setInterface(false);
	
	
	
	m_centralBufferNodeActivation_EOperation_fire_Token->setEType(nullptr);
	m_centralBufferNodeActivation_EOperation_fire_Token->setName("fire");
	m_centralBufferNodeActivation_EOperation_fire_Token->setLowerBound(1);
	m_centralBufferNodeActivation_EOperation_fire_Token->setUpperBound(1);
	m_centralBufferNodeActivation_EOperation_fire_Token->setUnique(true);
	m_centralBufferNodeActivation_EOperation_fire_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_centralBufferNodeActivation_EOperation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeChoiceStrategyContent()
{
	m_choiceStrategy_EClass->setInstanceClass(nullptr);
	m_choiceStrategy_EClass->setName("ChoiceStrategy");
	m_choiceStrategy_EClass->setAbstract(true);
	m_choiceStrategy_EClass->setInterface(false);
	
	
	
	m_choiceStrategy_EOperation_choose_EInt->setEType(ecore::EcorePackage::eInstance()->getEInt_EDataType());
	m_choiceStrategy_EOperation_choose_EInt->setName("choose");
	m_choiceStrategy_EOperation_choose_EInt->setLowerBound(1);
	m_choiceStrategy_EOperation_choose_EInt->setUpperBound(1);
	m_choiceStrategy_EOperation_choose_EInt->setUnique(true);
	m_choiceStrategy_EOperation_choose_EInt->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_choiceStrategy_EOperation_choose_EInt);
		parameter->setName("size");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEInt_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_choiceStrategy_EOperation_retrieveName->setEType(ecore::EcorePackage::eInstance()->getEString_EDataType());
	m_choiceStrategy_EOperation_retrieveName->setName("retrieveName");
	m_choiceStrategy_EOperation_retrieveName->setLowerBound(1);
	m_choiceStrategy_EOperation_retrieveName->setUpperBound(1);
	m_choiceStrategy_EOperation_retrieveName->setUnique(true);
	m_choiceStrategy_EOperation_retrieveName->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeClassifierBehaviorExecutionContent()
{
	m_classifierBehaviorExecution_EClass->setInstanceClass(nullptr);
	m_classifierBehaviorExecution_EClass->setName("ClassifierBehaviorExecution");
	m_classifierBehaviorExecution_EClass->setAbstract(false);
	m_classifierBehaviorExecution_EClass->setInterface(false);
	
	
	m_classifierBehaviorExecution_EReference_classifier->setName("classifier");
	m_classifierBehaviorExecution_EReference_classifier->setEType(uml::UmlPackage::eInstance()->getClass_EClass());
	m_classifierBehaviorExecution_EReference_classifier->setLowerBound(1);
	m_classifierBehaviorExecution_EReference_classifier->setUpperBound(1);
	m_classifierBehaviorExecution_EReference_classifier->setTransient(false);
	m_classifierBehaviorExecution_EReference_classifier->setVolatile(false);
	m_classifierBehaviorExecution_EReference_classifier->setChangeable(true);
	m_classifierBehaviorExecution_EReference_classifier->setUnsettable(false);
	m_classifierBehaviorExecution_EReference_classifier->setUnique(true);
	m_classifierBehaviorExecution_EReference_classifier->setDerived(false);
	m_classifierBehaviorExecution_EReference_classifier->setOrdered(false);
	m_classifierBehaviorExecution_EReference_classifier->setContainment(false);
	m_classifierBehaviorExecution_EReference_classifier->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_classifierBehaviorExecution_EReference_classifier->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_classifierBehaviorExecution_EReference_classifier->setEOpposite(otherEnd);
	    }
	}
	m_classifierBehaviorExecution_EReference_execution->setName("execution");
	m_classifierBehaviorExecution_EReference_execution->setEType(getExecution_EClass());
	m_classifierBehaviorExecution_EReference_execution->setLowerBound(1);
	m_classifierBehaviorExecution_EReference_execution->setUpperBound(1);
	m_classifierBehaviorExecution_EReference_execution->setTransient(false);
	m_classifierBehaviorExecution_EReference_execution->setVolatile(false);
	m_classifierBehaviorExecution_EReference_execution->setChangeable(true);
	m_classifierBehaviorExecution_EReference_execution->setUnsettable(false);
	m_classifierBehaviorExecution_EReference_execution->setUnique(true);
	m_classifierBehaviorExecution_EReference_execution->setDerived(false);
	m_classifierBehaviorExecution_EReference_execution->setOrdered(false);
	m_classifierBehaviorExecution_EReference_execution->setContainment(false);
	m_classifierBehaviorExecution_EReference_execution->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_classifierBehaviorExecution_EReference_execution->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_classifierBehaviorExecution_EReference_execution->setEOpposite(otherEnd);
	    }
	}
	m_classifierBehaviorExecution_EReference_objectActivation->setName("objectActivation");
	m_classifierBehaviorExecution_EReference_objectActivation->setEType(getObjectActivation_EClass());
	m_classifierBehaviorExecution_EReference_objectActivation->setLowerBound(0);
	m_classifierBehaviorExecution_EReference_objectActivation->setUpperBound(1);
	m_classifierBehaviorExecution_EReference_objectActivation->setTransient(false);
	m_classifierBehaviorExecution_EReference_objectActivation->setVolatile(false);
	m_classifierBehaviorExecution_EReference_objectActivation->setChangeable(true);
	m_classifierBehaviorExecution_EReference_objectActivation->setUnsettable(false);
	m_classifierBehaviorExecution_EReference_objectActivation->setUnique(true);
	m_classifierBehaviorExecution_EReference_objectActivation->setDerived(false);
	m_classifierBehaviorExecution_EReference_objectActivation->setOrdered(false);
	m_classifierBehaviorExecution_EReference_objectActivation->setContainment(false);
	m_classifierBehaviorExecution_EReference_objectActivation->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_classifierBehaviorExecution_EReference_objectActivation->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_classifierBehaviorExecution_EReference_objectActivation->setEOpposite(otherEnd);
	    }
	}
	
	m_classifierBehaviorExecution_EOperation__startObjectBehavior->setEType(nullptr);
	m_classifierBehaviorExecution_EOperation__startObjectBehavior->setName("_startObjectBehavior");
	m_classifierBehaviorExecution_EOperation__startObjectBehavior->setLowerBound(1);
	m_classifierBehaviorExecution_EOperation__startObjectBehavior->setUpperBound(1);
	m_classifierBehaviorExecution_EOperation__startObjectBehavior->setUnique(true);
	m_classifierBehaviorExecution_EOperation__startObjectBehavior->setOrdered(false);
	
	
	m_classifierBehaviorExecution_EOperation_execute_Class_ParameterValue->setEType(nullptr);
	m_classifierBehaviorExecution_EOperation_execute_Class_ParameterValue->setName("execute");
	m_classifierBehaviorExecution_EOperation_execute_Class_ParameterValue->setLowerBound(1);
	m_classifierBehaviorExecution_EOperation_execute_Class_ParameterValue->setUpperBound(1);
	m_classifierBehaviorExecution_EOperation_execute_Class_ParameterValue->setUnique(true);
	m_classifierBehaviorExecution_EOperation_execute_Class_ParameterValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_classifierBehaviorExecution_EOperation_execute_Class_ParameterValue);
		parameter->setName("classifier");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_classifierBehaviorExecution_EOperation_execute_Class_ParameterValue);
		parameter->setName("inputs");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_classifierBehaviorExecution_EOperation_terminate->setEType(nullptr);
	m_classifierBehaviorExecution_EOperation_terminate->setName("terminate");
	m_classifierBehaviorExecution_EOperation_terminate->setLowerBound(1);
	m_classifierBehaviorExecution_EOperation_terminate->setUpperBound(1);
	m_classifierBehaviorExecution_EOperation_terminate->setUnique(true);
	m_classifierBehaviorExecution_EOperation_terminate->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeClassifierBehaviorExecutionActivityContent()
{
	m_classifierBehaviorExecutionActivity_EClass->setInstanceClass(nullptr);
	m_classifierBehaviorExecutionActivity_EClass->setName("ClassifierBehaviorExecutionActivity");
	m_classifierBehaviorExecutionActivity_EClass->setAbstract(false);
	m_classifierBehaviorExecutionActivity_EClass->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Content()
{
	m_classifierBehaviorExecutionActivity_OwnedBehaviorActivity1_EClass->setInstanceClass(nullptr);
	m_classifierBehaviorExecutionActivity_OwnedBehaviorActivity1_EClass->setName("ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1");
	m_classifierBehaviorExecutionActivity_OwnedBehaviorActivity1_EClass->setAbstract(false);
	m_classifierBehaviorExecutionActivity_OwnedBehaviorActivity1_EClass->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeClauseActivationContent()
{
	m_clauseActivation_EClass->setInstanceClass(nullptr);
	m_clauseActivation_EClass->setName("ClauseActivation");
	m_clauseActivation_EClass->setAbstract(false);
	m_clauseActivation_EClass->setInterface(false);
	
	
	m_clauseActivation_EReference_clause->setName("clause");
	m_clauseActivation_EReference_clause->setEType(uml::UmlPackage::eInstance()->getClause_EClass());
	m_clauseActivation_EReference_clause->setLowerBound(1);
	m_clauseActivation_EReference_clause->setUpperBound(1);
	m_clauseActivation_EReference_clause->setTransient(false);
	m_clauseActivation_EReference_clause->setVolatile(false);
	m_clauseActivation_EReference_clause->setChangeable(true);
	m_clauseActivation_EReference_clause->setUnsettable(false);
	m_clauseActivation_EReference_clause->setUnique(true);
	m_clauseActivation_EReference_clause->setDerived(false);
	m_clauseActivation_EReference_clause->setOrdered(false);
	m_clauseActivation_EReference_clause->setContainment(false);
	m_clauseActivation_EReference_clause->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_clauseActivation_EReference_clause->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_clauseActivation_EReference_clause->setEOpposite(otherEnd);
	    }
	}
	m_clauseActivation_EReference_conditionalNodeActivation->setName("conditionalNodeActivation");
	m_clauseActivation_EReference_conditionalNodeActivation->setEType(getConditionalNodeActivation_EClass());
	m_clauseActivation_EReference_conditionalNodeActivation->setLowerBound(1);
	m_clauseActivation_EReference_conditionalNodeActivation->setUpperBound(1);
	m_clauseActivation_EReference_conditionalNodeActivation->setTransient(false);
	m_clauseActivation_EReference_conditionalNodeActivation->setVolatile(false);
	m_clauseActivation_EReference_conditionalNodeActivation->setChangeable(true);
	m_clauseActivation_EReference_conditionalNodeActivation->setUnsettable(false);
	m_clauseActivation_EReference_conditionalNodeActivation->setUnique(true);
	m_clauseActivation_EReference_conditionalNodeActivation->setDerived(false);
	m_clauseActivation_EReference_conditionalNodeActivation->setOrdered(false);
	m_clauseActivation_EReference_conditionalNodeActivation->setContainment(false);
	m_clauseActivation_EReference_conditionalNodeActivation->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_clauseActivation_EReference_conditionalNodeActivation->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_clauseActivation_EReference_conditionalNodeActivation->setEOpposite(otherEnd);
	    }
	}
	
	m_clauseActivation_EOperation_getDecision->setEType(getBooleanValue_EClass());
	m_clauseActivation_EOperation_getDecision->setName("getDecision");
	m_clauseActivation_EOperation_getDecision->setLowerBound(0);
	m_clauseActivation_EOperation_getDecision->setUpperBound(1);
	m_clauseActivation_EOperation_getDecision->setUnique(true);
	m_clauseActivation_EOperation_getDecision->setOrdered(false);
	
	
	m_clauseActivation_EOperation_getPredecessors->setEType(getClauseActivation_EClass());
	m_clauseActivation_EOperation_getPredecessors->setName("getPredecessors");
	m_clauseActivation_EOperation_getPredecessors->setLowerBound(0);
	m_clauseActivation_EOperation_getPredecessors->setUpperBound(-1);
	m_clauseActivation_EOperation_getPredecessors->setUnique(true);
	m_clauseActivation_EOperation_getPredecessors->setOrdered(false);
	
	
	m_clauseActivation_EOperation_getSuccessors->setEType(getClauseActivation_EClass());
	m_clauseActivation_EOperation_getSuccessors->setName("getSuccessors");
	m_clauseActivation_EOperation_getSuccessors->setLowerBound(0);
	m_clauseActivation_EOperation_getSuccessors->setUpperBound(-1);
	m_clauseActivation_EOperation_getSuccessors->setUnique(true);
	m_clauseActivation_EOperation_getSuccessors->setOrdered(false);
	
	
	m_clauseActivation_EOperation_isReady->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_clauseActivation_EOperation_isReady->setName("isReady");
	m_clauseActivation_EOperation_isReady->setLowerBound(1);
	m_clauseActivation_EOperation_isReady->setUpperBound(1);
	m_clauseActivation_EOperation_isReady->setUnique(true);
	m_clauseActivation_EOperation_isReady->setOrdered(false);
	
	
	m_clauseActivation_EOperation_recieveControl->setEType(nullptr);
	m_clauseActivation_EOperation_recieveControl->setName("recieveControl");
	m_clauseActivation_EOperation_recieveControl->setLowerBound(1);
	m_clauseActivation_EOperation_recieveControl->setUpperBound(1);
	m_clauseActivation_EOperation_recieveControl->setUnique(true);
	m_clauseActivation_EOperation_recieveControl->setOrdered(false);
	
	
	m_clauseActivation_EOperation_runTest->setEType(nullptr);
	m_clauseActivation_EOperation_runTest->setName("runTest");
	m_clauseActivation_EOperation_runTest->setLowerBound(1);
	m_clauseActivation_EOperation_runTest->setUpperBound(1);
	m_clauseActivation_EOperation_runTest->setUnique(true);
	m_clauseActivation_EOperation_runTest->setOrdered(false);
	
	
	m_clauseActivation_EOperation_selectBody->setEType(nullptr);
	m_clauseActivation_EOperation_selectBody->setName("selectBody");
	m_clauseActivation_EOperation_selectBody->setLowerBound(1);
	m_clauseActivation_EOperation_selectBody->setUpperBound(1);
	m_clauseActivation_EOperation_selectBody->setUnique(true);
	m_clauseActivation_EOperation_selectBody->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeClearAssociationActionActivationContent()
{
	m_clearAssociationActionActivation_EClass->setInstanceClass(nullptr);
	m_clearAssociationActionActivation_EClass->setName("ClearAssociationActionActivation");
	m_clearAssociationActionActivation_EClass->setAbstract(false);
	m_clearAssociationActionActivation_EClass->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeClearStructuralFeatureActionActivationContent()
{
	m_clearStructuralFeatureActionActivation_EClass->setInstanceClass(nullptr);
	m_clearStructuralFeatureActionActivation_EClass->setName("ClearStructuralFeatureActionActivation");
	m_clearStructuralFeatureActionActivation_EClass->setAbstract(false);
	m_clearStructuralFeatureActionActivation_EClass->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeCompoundValueContent()
{
	m_compoundValue_EClass->setInstanceClass(nullptr);
	m_compoundValue_EClass->setName("CompoundValue");
	m_compoundValue_EClass->setAbstract(true);
	m_compoundValue_EClass->setInterface(false);
	
	
	m_compoundValue_EReference_featureValues->setName("featureValues");
	m_compoundValue_EReference_featureValues->setEType(getFeatureValue_EClass());
	m_compoundValue_EReference_featureValues->setLowerBound(0);
	m_compoundValue_EReference_featureValues->setUpperBound(-1);
	m_compoundValue_EReference_featureValues->setTransient(false);
	m_compoundValue_EReference_featureValues->setVolatile(false);
	m_compoundValue_EReference_featureValues->setChangeable(true);
	m_compoundValue_EReference_featureValues->setUnsettable(false);
	m_compoundValue_EReference_featureValues->setUnique(true);
	m_compoundValue_EReference_featureValues->setDerived(false);
	m_compoundValue_EReference_featureValues->setOrdered(false);
	m_compoundValue_EReference_featureValues->setContainment(true);
	m_compoundValue_EReference_featureValues->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_compoundValue_EReference_featureValues->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_compoundValue_EReference_featureValues->setEOpposite(otherEnd);
	    }
	}
	
	m_compoundValue_EOperation_assignFeatureValue_StructuralFeature_EInt->setEType(nullptr);
	m_compoundValue_EOperation_assignFeatureValue_StructuralFeature_EInt->setName("assignFeatureValue");
	m_compoundValue_EOperation_assignFeatureValue_StructuralFeature_EInt->setLowerBound(1);
	m_compoundValue_EOperation_assignFeatureValue_StructuralFeature_EInt->setUpperBound(1);
	m_compoundValue_EOperation_assignFeatureValue_StructuralFeature_EInt->setUnique(true);
	m_compoundValue_EOperation_assignFeatureValue_StructuralFeature_EInt->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_compoundValue_EOperation_assignFeatureValue_StructuralFeature_EInt);
		parameter->setName("feature");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_compoundValue_EOperation_assignFeatureValue_StructuralFeature_EInt);
		parameter->setName("values");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_compoundValue_EOperation_assignFeatureValue_StructuralFeature_EInt);
		parameter->setName("position");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_compoundValue_EOperation_equals_Value->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_compoundValue_EOperation_equals_Value->setName("equals");
	m_compoundValue_EOperation_equals_Value->setLowerBound(1);
	m_compoundValue_EOperation_equals_Value->setUpperBound(1);
	m_compoundValue_EOperation_equals_Value->setUnique(true);
	m_compoundValue_EOperation_equals_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_compoundValue_EOperation_equals_Value);
		parameter->setName("otherValue");
		parameter->setEType(getValue_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_compoundValue_EOperation_removeFeatureValues_Classifier->setEType(nullptr);
	m_compoundValue_EOperation_removeFeatureValues_Classifier->setName("removeFeatureValues");
	m_compoundValue_EOperation_removeFeatureValues_Classifier->setLowerBound(1);
	m_compoundValue_EOperation_removeFeatureValues_Classifier->setUpperBound(1);
	m_compoundValue_EOperation_removeFeatureValues_Classifier->setUnique(true);
	m_compoundValue_EOperation_removeFeatureValues_Classifier->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_compoundValue_EOperation_removeFeatureValues_Classifier);
		parameter->setName("classifier");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_compoundValue_EOperation_retrieveFeatureValue_StructuralFeature->setEType(getFeatureValue_EClass());
	m_compoundValue_EOperation_retrieveFeatureValue_StructuralFeature->setName("retrieveFeatureValue");
	m_compoundValue_EOperation_retrieveFeatureValue_StructuralFeature->setLowerBound(1);
	m_compoundValue_EOperation_retrieveFeatureValue_StructuralFeature->setUpperBound(1);
	m_compoundValue_EOperation_retrieveFeatureValue_StructuralFeature->setUnique(true);
	m_compoundValue_EOperation_retrieveFeatureValue_StructuralFeature->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_compoundValue_EOperation_retrieveFeatureValue_StructuralFeature);
		parameter->setName("feature");
		parameter->setEType(uml::UmlPackage::eInstance()->getStructuralFeature_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_compoundValue_EOperation_retrieveFeatureValues->setEType(getFeatureValue_EClass());
	m_compoundValue_EOperation_retrieveFeatureValues->setName("retrieveFeatureValues");
	m_compoundValue_EOperation_retrieveFeatureValues->setLowerBound(0);
	m_compoundValue_EOperation_retrieveFeatureValues->setUpperBound(-1);
	m_compoundValue_EOperation_retrieveFeatureValues->setUnique(true);
	m_compoundValue_EOperation_retrieveFeatureValues->setOrdered(false);
	
	
	m_compoundValue_EOperation_toString->setEType(ecore::EcorePackage::eInstance()->getEString_EDataType());
	m_compoundValue_EOperation_toString->setName("toString");
	m_compoundValue_EOperation_toString->setLowerBound(1);
	m_compoundValue_EOperation_toString->setUpperBound(1);
	m_compoundValue_EOperation_toString->setUnique(true);
	m_compoundValue_EOperation_toString->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeConditionalNodeActivationContent()
{
	m_conditionalNodeActivation_EClass->setInstanceClass(nullptr);
	m_conditionalNodeActivation_EClass->setName("ConditionalNodeActivation");
	m_conditionalNodeActivation_EClass->setAbstract(false);
	m_conditionalNodeActivation_EClass->setInterface(false);
	
	
	m_conditionalNodeActivation_EReference_clauseActivations->setName("clauseActivations");
	m_conditionalNodeActivation_EReference_clauseActivations->setEType(getClauseActivation_EClass());
	m_conditionalNodeActivation_EReference_clauseActivations->setLowerBound(0);
	m_conditionalNodeActivation_EReference_clauseActivations->setUpperBound(-1);
	m_conditionalNodeActivation_EReference_clauseActivations->setTransient(false);
	m_conditionalNodeActivation_EReference_clauseActivations->setVolatile(false);
	m_conditionalNodeActivation_EReference_clauseActivations->setChangeable(true);
	m_conditionalNodeActivation_EReference_clauseActivations->setUnsettable(false);
	m_conditionalNodeActivation_EReference_clauseActivations->setUnique(true);
	m_conditionalNodeActivation_EReference_clauseActivations->setDerived(false);
	m_conditionalNodeActivation_EReference_clauseActivations->setOrdered(false);
	m_conditionalNodeActivation_EReference_clauseActivations->setContainment(true);
	m_conditionalNodeActivation_EReference_clauseActivations->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_conditionalNodeActivation_EReference_clauseActivations->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_conditionalNodeActivation_EReference_clauseActivations->setEOpposite(otherEnd);
	    }
	}
	m_conditionalNodeActivation_EReference_selectedClauses->setName("selectedClauses");
	m_conditionalNodeActivation_EReference_selectedClauses->setEType(uml::UmlPackage::eInstance()->getClause_EClass());
	m_conditionalNodeActivation_EReference_selectedClauses->setLowerBound(0);
	m_conditionalNodeActivation_EReference_selectedClauses->setUpperBound(-1);
	m_conditionalNodeActivation_EReference_selectedClauses->setTransient(false);
	m_conditionalNodeActivation_EReference_selectedClauses->setVolatile(false);
	m_conditionalNodeActivation_EReference_selectedClauses->setChangeable(true);
	m_conditionalNodeActivation_EReference_selectedClauses->setUnsettable(false);
	m_conditionalNodeActivation_EReference_selectedClauses->setUnique(true);
	m_conditionalNodeActivation_EReference_selectedClauses->setDerived(false);
	m_conditionalNodeActivation_EReference_selectedClauses->setOrdered(false);
	m_conditionalNodeActivation_EReference_selectedClauses->setContainment(false);
	m_conditionalNodeActivation_EReference_selectedClauses->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_conditionalNodeActivation_EReference_selectedClauses->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_conditionalNodeActivation_EReference_selectedClauses->setEOpposite(otherEnd);
	    }
	}
	
	m_conditionalNodeActivation_EOperation_getClauseActivation_Clause->setEType(getClauseActivation_EClass());
	m_conditionalNodeActivation_EOperation_getClauseActivation_Clause->setName("getClauseActivation");
	m_conditionalNodeActivation_EOperation_getClauseActivation_Clause->setLowerBound(1);
	m_conditionalNodeActivation_EOperation_getClauseActivation_Clause->setUpperBound(1);
	m_conditionalNodeActivation_EOperation_getClauseActivation_Clause->setUnique(true);
	m_conditionalNodeActivation_EOperation_getClauseActivation_Clause->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_conditionalNodeActivation_EOperation_getClauseActivation_Clause);
		parameter->setName("clause");
		parameter->setEType(uml::UmlPackage::eInstance()->getClause_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_conditionalNodeActivation_EOperation_runTest_Clause->setEType(nullptr);
	m_conditionalNodeActivation_EOperation_runTest_Clause->setName("runTest");
	m_conditionalNodeActivation_EOperation_runTest_Clause->setLowerBound(1);
	m_conditionalNodeActivation_EOperation_runTest_Clause->setUpperBound(1);
	m_conditionalNodeActivation_EOperation_runTest_Clause->setUnique(true);
	m_conditionalNodeActivation_EOperation_runTest_Clause->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_conditionalNodeActivation_EOperation_runTest_Clause);
		parameter->setName("clause");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_conditionalNodeActivation_EOperation_selectBody_Clause->setEType(nullptr);
	m_conditionalNodeActivation_EOperation_selectBody_Clause->setName("selectBody");
	m_conditionalNodeActivation_EOperation_selectBody_Clause->setLowerBound(1);
	m_conditionalNodeActivation_EOperation_selectBody_Clause->setUpperBound(1);
	m_conditionalNodeActivation_EOperation_selectBody_Clause->setUnique(true);
	m_conditionalNodeActivation_EOperation_selectBody_Clause->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_conditionalNodeActivation_EOperation_selectBody_Clause);
		parameter->setName("clause");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeControlNodeActivationContent()
{
	m_controlNodeActivation_EClass->setInstanceClass(nullptr);
	m_controlNodeActivation_EClass->setName("ControlNodeActivation");
	m_controlNodeActivation_EClass->setAbstract(true);
	m_controlNodeActivation_EClass->setInterface(false);
	
	
	
	m_controlNodeActivation_EOperation_fire_Token->setEType(nullptr);
	m_controlNodeActivation_EOperation_fire_Token->setName("fire");
	m_controlNodeActivation_EOperation_fire_Token->setLowerBound(1);
	m_controlNodeActivation_EOperation_fire_Token->setUpperBound(1);
	m_controlNodeActivation_EOperation_fire_Token->setUnique(true);
	m_controlNodeActivation_EOperation_fire_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_controlNodeActivation_EOperation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeControlTokenContent()
{
	m_controlToken_EClass->setInstanceClass(nullptr);
	m_controlToken_EClass->setName("ControlToken");
	m_controlToken_EClass->setAbstract(false);
	m_controlToken_EClass->setInterface(false);
	
	
	
	m_controlToken_EOperation_equals_Token->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_controlToken_EOperation_equals_Token->setName("equals");
	m_controlToken_EOperation_equals_Token->setLowerBound(1);
	m_controlToken_EOperation_equals_Token->setUpperBound(1);
	m_controlToken_EOperation_equals_Token->setUnique(true);
	m_controlToken_EOperation_equals_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_controlToken_EOperation_equals_Token);
		parameter->setName("other");
		parameter->setEType(getToken_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_controlToken_EOperation_getValue->setEType(getValue_EClass());
	m_controlToken_EOperation_getValue->setName("getValue");
	m_controlToken_EOperation_getValue->setLowerBound(0);
	m_controlToken_EOperation_getValue->setUpperBound(1);
	m_controlToken_EOperation_getValue->setUnique(true);
	m_controlToken_EOperation_getValue->setOrdered(false);
	
	
	m_controlToken_EOperation_isControl->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_controlToken_EOperation_isControl->setName("isControl");
	m_controlToken_EOperation_isControl->setLowerBound(1);
	m_controlToken_EOperation_isControl->setUpperBound(1);
	m_controlToken_EOperation_isControl->setUnique(true);
	m_controlToken_EOperation_isControl->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeCreateLinkActionActivationContent()
{
	m_createLinkActionActivation_EClass->setInstanceClass(nullptr);
	m_createLinkActionActivation_EClass->setName("CreateLinkActionActivation");
	m_createLinkActionActivation_EClass->setAbstract(false);
	m_createLinkActionActivation_EClass->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeCreateObjectActionActivationContent()
{
	m_createObjectActionActivation_EClass->setInstanceClass(nullptr);
	m_createObjectActionActivation_EClass->setName("CreateObjectActionActivation");
	m_createObjectActionActivation_EClass->setAbstract(false);
	m_createObjectActionActivation_EClass->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeDataStoreNodeActivationContent()
{
	m_dataStoreNodeActivation_EClass->setInstanceClass(nullptr);
	m_dataStoreNodeActivation_EClass->setName("DataStoreNodeActivation");
	m_dataStoreNodeActivation_EClass->setAbstract(false);
	m_dataStoreNodeActivation_EClass->setInterface(false);
	
	
	
	m_dataStoreNodeActivation_EOperation_addToken_Token->setEType(nullptr);
	m_dataStoreNodeActivation_EOperation_addToken_Token->setName("addToken");
	m_dataStoreNodeActivation_EOperation_addToken_Token->setLowerBound(1);
	m_dataStoreNodeActivation_EOperation_addToken_Token->setUpperBound(1);
	m_dataStoreNodeActivation_EOperation_addToken_Token->setUnique(true);
	m_dataStoreNodeActivation_EOperation_addToken_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_dataStoreNodeActivation_EOperation_addToken_Token);
		parameter->setName("token");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_dataStoreNodeActivation_EOperation_removeToken_Token->setEType(ecore::EcorePackage::eInstance()->getEInt_EDataType());
	m_dataStoreNodeActivation_EOperation_removeToken_Token->setName("removeToken");
	m_dataStoreNodeActivation_EOperation_removeToken_Token->setLowerBound(1);
	m_dataStoreNodeActivation_EOperation_removeToken_Token->setUpperBound(1);
	m_dataStoreNodeActivation_EOperation_removeToken_Token->setUnique(true);
	m_dataStoreNodeActivation_EOperation_removeToken_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_dataStoreNodeActivation_EOperation_removeToken_Token);
		parameter->setName("token");
		parameter->setEType(getToken_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeDataValueContent()
{
	m_dataValue_EClass->setInstanceClass(nullptr);
	m_dataValue_EClass->setName("DataValue");
	m_dataValue_EClass->setAbstract(false);
	m_dataValue_EClass->setInterface(false);
	
	
	m_dataValue_EReference_type->setName("type");
	m_dataValue_EReference_type->setEType(uml::UmlPackage::eInstance()->getDataType_EClass());
	m_dataValue_EReference_type->setLowerBound(1);
	m_dataValue_EReference_type->setUpperBound(1);
	m_dataValue_EReference_type->setTransient(false);
	m_dataValue_EReference_type->setVolatile(false);
	m_dataValue_EReference_type->setChangeable(true);
	m_dataValue_EReference_type->setUnsettable(false);
	m_dataValue_EReference_type->setUnique(true);
	m_dataValue_EReference_type->setDerived(false);
	m_dataValue_EReference_type->setOrdered(false);
	m_dataValue_EReference_type->setContainment(false);
	m_dataValue_EReference_type->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_dataValue_EReference_type->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_dataValue_EReference_type->setEOpposite(otherEnd);
	    }
	}
	
	m_dataValue_EOperation_getTypes->setEType(uml::UmlPackage::eInstance()->getClassifier_EClass());
	m_dataValue_EOperation_getTypes->setName("getTypes");
	m_dataValue_EOperation_getTypes->setLowerBound(0);
	m_dataValue_EOperation_getTypes->setUpperBound(-1);
	m_dataValue_EOperation_getTypes->setUnique(true);
	m_dataValue_EOperation_getTypes->setOrdered(false);
	
	
	m_dataValue_EOperation_new_->setEType(getValue_EClass());
	m_dataValue_EOperation_new_->setName("new_");
	m_dataValue_EOperation_new_->setLowerBound(1);
	m_dataValue_EOperation_new_->setUpperBound(1);
	m_dataValue_EOperation_new_->setUnique(true);
	m_dataValue_EOperation_new_->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeDecisionNodeActivationContent()
{
	m_decisionNodeActivation_EClass->setInstanceClass(nullptr);
	m_decisionNodeActivation_EClass->setName("DecisionNodeActivation");
	m_decisionNodeActivation_EClass->setAbstract(false);
	m_decisionNodeActivation_EClass->setInterface(false);
	
	
	m_decisionNodeActivation_EReference_decisionInputExecution->setName("decisionInputExecution");
	m_decisionNodeActivation_EReference_decisionInputExecution->setEType(getExecution_EClass());
	m_decisionNodeActivation_EReference_decisionInputExecution->setLowerBound(1);
	m_decisionNodeActivation_EReference_decisionInputExecution->setUpperBound(1);
	m_decisionNodeActivation_EReference_decisionInputExecution->setTransient(false);
	m_decisionNodeActivation_EReference_decisionInputExecution->setVolatile(false);
	m_decisionNodeActivation_EReference_decisionInputExecution->setChangeable(true);
	m_decisionNodeActivation_EReference_decisionInputExecution->setUnsettable(false);
	m_decisionNodeActivation_EReference_decisionInputExecution->setUnique(true);
	m_decisionNodeActivation_EReference_decisionInputExecution->setDerived(false);
	m_decisionNodeActivation_EReference_decisionInputExecution->setOrdered(false);
	m_decisionNodeActivation_EReference_decisionInputExecution->setContainment(true);
	m_decisionNodeActivation_EReference_decisionInputExecution->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_decisionNodeActivation_EReference_decisionInputExecution->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_decisionNodeActivation_EReference_decisionInputExecution->setEOpposite(otherEnd);
	    }
	}
	
	m_decisionNodeActivation_EOperation_executeDecisionInputBehavior_Value_Value->setEType(getValue_EClass());
	m_decisionNodeActivation_EOperation_executeDecisionInputBehavior_Value_Value->setName("executeDecisionInputBehavior");
	m_decisionNodeActivation_EOperation_executeDecisionInputBehavior_Value_Value->setLowerBound(1);
	m_decisionNodeActivation_EOperation_executeDecisionInputBehavior_Value_Value->setUpperBound(1);
	m_decisionNodeActivation_EOperation_executeDecisionInputBehavior_Value_Value->setUnique(true);
	m_decisionNodeActivation_EOperation_executeDecisionInputBehavior_Value_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_decisionNodeActivation_EOperation_executeDecisionInputBehavior_Value_Value);
		parameter->setName("inputValue");
		parameter->setEType(getValue_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_decisionNodeActivation_EOperation_executeDecisionInputBehavior_Value_Value);
		parameter->setName("decisionInputValue");
		parameter->setEType(getValue_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_decisionNodeActivation_EOperation_fire_Token->setEType(nullptr);
	m_decisionNodeActivation_EOperation_fire_Token->setName("fire");
	m_decisionNodeActivation_EOperation_fire_Token->setLowerBound(1);
	m_decisionNodeActivation_EOperation_fire_Token->setUpperBound(1);
	m_decisionNodeActivation_EOperation_fire_Token->setUnique(true);
	m_decisionNodeActivation_EOperation_fire_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_decisionNodeActivation_EOperation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_decisionNodeActivation_EOperation_getDecisionInputFlowInstance->setEType(getActivityEdgeInstance_EClass());
	m_decisionNodeActivation_EOperation_getDecisionInputFlowInstance->setName("getDecisionInputFlowInstance");
	m_decisionNodeActivation_EOperation_getDecisionInputFlowInstance->setLowerBound(0);
	m_decisionNodeActivation_EOperation_getDecisionInputFlowInstance->setUpperBound(1);
	m_decisionNodeActivation_EOperation_getDecisionInputFlowInstance->setUnique(true);
	m_decisionNodeActivation_EOperation_getDecisionInputFlowInstance->setOrdered(false);
	
	
	m_decisionNodeActivation_EOperation_getDecisionInputFlowValue->setEType(getValue_EClass());
	m_decisionNodeActivation_EOperation_getDecisionInputFlowValue->setName("getDecisionInputFlowValue");
	m_decisionNodeActivation_EOperation_getDecisionInputFlowValue->setLowerBound(0);
	m_decisionNodeActivation_EOperation_getDecisionInputFlowValue->setUpperBound(1);
	m_decisionNodeActivation_EOperation_getDecisionInputFlowValue->setUnique(true);
	m_decisionNodeActivation_EOperation_getDecisionInputFlowValue->setOrdered(false);
	
	
	m_decisionNodeActivation_EOperation_getDecisionValues_Token->setEType(getValue_EClass());
	m_decisionNodeActivation_EOperation_getDecisionValues_Token->setName("getDecisionValues");
	m_decisionNodeActivation_EOperation_getDecisionValues_Token->setLowerBound(0);
	m_decisionNodeActivation_EOperation_getDecisionValues_Token->setUpperBound(-1);
	m_decisionNodeActivation_EOperation_getDecisionValues_Token->setUnique(true);
	m_decisionNodeActivation_EOperation_getDecisionValues_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_decisionNodeActivation_EOperation_getDecisionValues_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(getToken_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_decisionNodeActivation_EOperation_hasObjectFlowInput->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_decisionNodeActivation_EOperation_hasObjectFlowInput->setName("hasObjectFlowInput");
	m_decisionNodeActivation_EOperation_hasObjectFlowInput->setLowerBound(1);
	m_decisionNodeActivation_EOperation_hasObjectFlowInput->setUpperBound(1);
	m_decisionNodeActivation_EOperation_hasObjectFlowInput->setUnique(true);
	m_decisionNodeActivation_EOperation_hasObjectFlowInput->setOrdered(false);
	
	
	m_decisionNodeActivation_EOperation_isReady->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_decisionNodeActivation_EOperation_isReady->setName("isReady");
	m_decisionNodeActivation_EOperation_isReady->setLowerBound(1);
	m_decisionNodeActivation_EOperation_isReady->setUpperBound(1);
	m_decisionNodeActivation_EOperation_isReady->setUnique(true);
	m_decisionNodeActivation_EOperation_isReady->setOrdered(false);
	
	
	m_decisionNodeActivation_EOperation_removeJoinedControlTokens_Token->setEType(getToken_EClass());
	m_decisionNodeActivation_EOperation_removeJoinedControlTokens_Token->setName("removeJoinedControlTokens");
	m_decisionNodeActivation_EOperation_removeJoinedControlTokens_Token->setLowerBound(0);
	m_decisionNodeActivation_EOperation_removeJoinedControlTokens_Token->setUpperBound(-1);
	m_decisionNodeActivation_EOperation_removeJoinedControlTokens_Token->setUnique(true);
	m_decisionNodeActivation_EOperation_removeJoinedControlTokens_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_decisionNodeActivation_EOperation_removeJoinedControlTokens_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(getToken_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_decisionNodeActivation_EOperation_takeOfferedTokens->setEType(getToken_EClass());
	m_decisionNodeActivation_EOperation_takeOfferedTokens->setName("takeOfferedTokens");
	m_decisionNodeActivation_EOperation_takeOfferedTokens->setLowerBound(0);
	m_decisionNodeActivation_EOperation_takeOfferedTokens->setUpperBound(-1);
	m_decisionNodeActivation_EOperation_takeOfferedTokens->setUnique(true);
	m_decisionNodeActivation_EOperation_takeOfferedTokens->setOrdered(false);
	
	
	m_decisionNodeActivation_EOperation_terminate->setEType(nullptr);
	m_decisionNodeActivation_EOperation_terminate->setName("terminate");
	m_decisionNodeActivation_EOperation_terminate->setLowerBound(1);
	m_decisionNodeActivation_EOperation_terminate->setUpperBound(1);
	m_decisionNodeActivation_EOperation_terminate->setUnique(true);
	m_decisionNodeActivation_EOperation_terminate->setOrdered(false);
	
	
	m_decisionNodeActivation_EOperation_test_ValueSpecification_Value->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_decisionNodeActivation_EOperation_test_ValueSpecification_Value->setName("test");
	m_decisionNodeActivation_EOperation_test_ValueSpecification_Value->setLowerBound(1);
	m_decisionNodeActivation_EOperation_test_ValueSpecification_Value->setUpperBound(1);
	m_decisionNodeActivation_EOperation_test_ValueSpecification_Value->setUnique(true);
	m_decisionNodeActivation_EOperation_test_ValueSpecification_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_decisionNodeActivation_EOperation_test_ValueSpecification_Value);
		parameter->setName("gaurd");
		parameter->setEType(uml::UmlPackage::eInstance()->getValueSpecification_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_decisionNodeActivation_EOperation_test_ValueSpecification_Value);
		parameter->setName("value");
		parameter->setEType(getValue_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeDestroyLinkActionActivationContent()
{
	m_destroyLinkActionActivation_EClass->setInstanceClass(nullptr);
	m_destroyLinkActionActivation_EClass->setName("DestroyLinkActionActivation");
	m_destroyLinkActionActivation_EClass->setAbstract(false);
	m_destroyLinkActionActivation_EClass->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeDestroyObjectActionActivationContent()
{
	m_destroyObjectActionActivation_EClass->setInstanceClass(nullptr);
	m_destroyObjectActionActivation_EClass->setName("DestroyObjectActionActivation");
	m_destroyObjectActionActivation_EClass->setAbstract(false);
	m_destroyObjectActionActivation_EClass->setInterface(false);
	
	
	
	m_destroyObjectActionActivation_EOperation_destroyObject_Value_EBoolean->setEType(nullptr);
	m_destroyObjectActionActivation_EOperation_destroyObject_Value_EBoolean->setName("destroyObject");
	m_destroyObjectActionActivation_EOperation_destroyObject_Value_EBoolean->setLowerBound(1);
	m_destroyObjectActionActivation_EOperation_destroyObject_Value_EBoolean->setUpperBound(1);
	m_destroyObjectActionActivation_EOperation_destroyObject_Value_EBoolean->setUnique(true);
	m_destroyObjectActionActivation_EOperation_destroyObject_Value_EBoolean->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_destroyObjectActionActivation_EOperation_destroyObject_Value_EBoolean);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_destroyObjectActionActivation_EOperation_destroyObject_Value_EBoolean);
		parameter->setName("isDestroyLinks");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_destroyObjectActionActivation_EOperation_destroyObject_Value_EBoolean);
		parameter->setName("isDestroyOwnedObjects");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_destroyObjectActionActivation_EOperation_objectIsComposite_Reference_Link->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_destroyObjectActionActivation_EOperation_objectIsComposite_Reference_Link->setName("objectIsComposite");
	m_destroyObjectActionActivation_EOperation_objectIsComposite_Reference_Link->setLowerBound(1);
	m_destroyObjectActionActivation_EOperation_objectIsComposite_Reference_Link->setUpperBound(1);
	m_destroyObjectActionActivation_EOperation_objectIsComposite_Reference_Link->setUnique(true);
	m_destroyObjectActionActivation_EOperation_objectIsComposite_Reference_Link->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_destroyObjectActionActivation_EOperation_objectIsComposite_Reference_Link);
		parameter->setName("reference");
		parameter->setEType(getReference_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_destroyObjectActionActivation_EOperation_objectIsComposite_Reference_Link);
		parameter->setName("link");
		parameter->setEType(getLink_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeDispatchStrategyContent()
{
	m_dispatchStrategy_EClass->setInstanceClass(nullptr);
	m_dispatchStrategy_EClass->setName("DispatchStrategy");
	m_dispatchStrategy_EClass->setAbstract(false);
	m_dispatchStrategy_EClass->setInterface(false);
	
	
	
	m_dispatchStrategy_EOperation_dispatch_Object_Operation->setEType(getExecution_EClass());
	m_dispatchStrategy_EOperation_dispatch_Object_Operation->setName("dispatch");
	m_dispatchStrategy_EOperation_dispatch_Object_Operation->setLowerBound(1);
	m_dispatchStrategy_EOperation_dispatch_Object_Operation->setUpperBound(1);
	m_dispatchStrategy_EOperation_dispatch_Object_Operation->setUnique(true);
	m_dispatchStrategy_EOperation_dispatch_Object_Operation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_dispatchStrategy_EOperation_dispatch_Object_Operation);
		parameter->setName("object");
		parameter->setEType(getObject_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_dispatchStrategy_EOperation_dispatch_Object_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::UmlPackage::eInstance()->getOperation_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_dispatchStrategy_EOperation_retrieveMethod_Object_Operation->setEType(uml::UmlPackage::eInstance()->getBehavior_EClass());
	m_dispatchStrategy_EOperation_retrieveMethod_Object_Operation->setName("retrieveMethod");
	m_dispatchStrategy_EOperation_retrieveMethod_Object_Operation->setLowerBound(1);
	m_dispatchStrategy_EOperation_retrieveMethod_Object_Operation->setUpperBound(1);
	m_dispatchStrategy_EOperation_retrieveMethod_Object_Operation->setUnique(true);
	m_dispatchStrategy_EOperation_retrieveMethod_Object_Operation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_dispatchStrategy_EOperation_retrieveMethod_Object_Operation);
		parameter->setName("object");
		parameter->setEType(getObject_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_dispatchStrategy_EOperation_retrieveMethod_Object_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::UmlPackage::eInstance()->getOperation_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_dispatchStrategy_EOperation_retrieveName->setEType(ecore::EcorePackage::eInstance()->getEString_EDataType());
	m_dispatchStrategy_EOperation_retrieveName->setName("retrieveName");
	m_dispatchStrategy_EOperation_retrieveName->setLowerBound(1);
	m_dispatchStrategy_EOperation_retrieveName->setUpperBound(1);
	m_dispatchStrategy_EOperation_retrieveName->setUnique(true);
	m_dispatchStrategy_EOperation_retrieveName->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeEnumerationValueContent()
{
	m_enumerationValue_EClass->setInstanceClass(nullptr);
	m_enumerationValue_EClass->setName("EnumerationValue");
	m_enumerationValue_EClass->setAbstract(false);
	m_enumerationValue_EClass->setInterface(false);
	
	
	m_enumerationValue_EReference_literal->setName("literal");
	m_enumerationValue_EReference_literal->setEType(uml::UmlPackage::eInstance()->getEnumerationLiteral_EClass());
	m_enumerationValue_EReference_literal->setLowerBound(1);
	m_enumerationValue_EReference_literal->setUpperBound(1);
	m_enumerationValue_EReference_literal->setTransient(false);
	m_enumerationValue_EReference_literal->setVolatile(false);
	m_enumerationValue_EReference_literal->setChangeable(true);
	m_enumerationValue_EReference_literal->setUnsettable(false);
	m_enumerationValue_EReference_literal->setUnique(true);
	m_enumerationValue_EReference_literal->setDerived(false);
	m_enumerationValue_EReference_literal->setOrdered(false);
	m_enumerationValue_EReference_literal->setContainment(false);
	m_enumerationValue_EReference_literal->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_enumerationValue_EReference_literal->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_enumerationValue_EReference_literal->setEOpposite(otherEnd);
	    }
	}
	m_enumerationValue_EReference_type->setName("type");
	m_enumerationValue_EReference_type->setEType(uml::UmlPackage::eInstance()->getEnumeration_EClass());
	m_enumerationValue_EReference_type->setLowerBound(1);
	m_enumerationValue_EReference_type->setUpperBound(1);
	m_enumerationValue_EReference_type->setTransient(false);
	m_enumerationValue_EReference_type->setVolatile(false);
	m_enumerationValue_EReference_type->setChangeable(true);
	m_enumerationValue_EReference_type->setUnsettable(false);
	m_enumerationValue_EReference_type->setUnique(true);
	m_enumerationValue_EReference_type->setDerived(false);
	m_enumerationValue_EReference_type->setOrdered(false);
	m_enumerationValue_EReference_type->setContainment(false);
	m_enumerationValue_EReference_type->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_enumerationValue_EReference_type->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_enumerationValue_EReference_type->setEOpposite(otherEnd);
	    }
	}
	
	m_enumerationValue_EOperation_equals_Value->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_enumerationValue_EOperation_equals_Value->setName("equals");
	m_enumerationValue_EOperation_equals_Value->setLowerBound(1);
	m_enumerationValue_EOperation_equals_Value->setUpperBound(1);
	m_enumerationValue_EOperation_equals_Value->setUnique(true);
	m_enumerationValue_EOperation_equals_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_enumerationValue_EOperation_equals_Value);
		parameter->setName("otherValue");
		parameter->setEType(getValue_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_enumerationValue_EOperation_getTypes->setEType(uml::UmlPackage::eInstance()->getClassifier_EClass());
	m_enumerationValue_EOperation_getTypes->setName("getTypes");
	m_enumerationValue_EOperation_getTypes->setLowerBound(0);
	m_enumerationValue_EOperation_getTypes->setUpperBound(-1);
	m_enumerationValue_EOperation_getTypes->setUnique(true);
	m_enumerationValue_EOperation_getTypes->setOrdered(false);
	
	
	m_enumerationValue_EOperation_new_->setEType(getValue_EClass());
	m_enumerationValue_EOperation_new_->setName("new_");
	m_enumerationValue_EOperation_new_->setLowerBound(1);
	m_enumerationValue_EOperation_new_->setUpperBound(1);
	m_enumerationValue_EOperation_new_->setUnique(true);
	m_enumerationValue_EOperation_new_->setOrdered(false);
	
	
	m_enumerationValue_EOperation_specify->setEType(uml::UmlPackage::eInstance()->getValueSpecification_EClass());
	m_enumerationValue_EOperation_specify->setName("specify");
	m_enumerationValue_EOperation_specify->setLowerBound(1);
	m_enumerationValue_EOperation_specify->setUpperBound(1);
	m_enumerationValue_EOperation_specify->setUnique(true);
	m_enumerationValue_EOperation_specify->setOrdered(false);
	
	
	m_enumerationValue_EOperation_toString->setEType(ecore::EcorePackage::eInstance()->getEString_EDataType());
	m_enumerationValue_EOperation_toString->setName("toString");
	m_enumerationValue_EOperation_toString->setLowerBound(1);
	m_enumerationValue_EOperation_toString->setUpperBound(1);
	m_enumerationValue_EOperation_toString->setUnique(true);
	m_enumerationValue_EOperation_toString->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeEvaluationContent()
{
	m_evaluation_EClass->setInstanceClass(nullptr);
	m_evaluation_EClass->setName("Evaluation");
	m_evaluation_EClass->setAbstract(true);
	m_evaluation_EClass->setInterface(false);
	
	
	m_evaluation_EReference_locus->setName("locus");
	m_evaluation_EReference_locus->setEType(getLocus_EClass());
	m_evaluation_EReference_locus->setLowerBound(1);
	m_evaluation_EReference_locus->setUpperBound(1);
	m_evaluation_EReference_locus->setTransient(false);
	m_evaluation_EReference_locus->setVolatile(false);
	m_evaluation_EReference_locus->setChangeable(true);
	m_evaluation_EReference_locus->setUnsettable(false);
	m_evaluation_EReference_locus->setUnique(true);
	m_evaluation_EReference_locus->setDerived(false);
	m_evaluation_EReference_locus->setOrdered(false);
	m_evaluation_EReference_locus->setContainment(false);
	m_evaluation_EReference_locus->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_evaluation_EReference_locus->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_evaluation_EReference_locus->setEOpposite(otherEnd);
	    }
	}
	m_evaluation_EReference_specification->setName("specification");
	m_evaluation_EReference_specification->setEType(uml::UmlPackage::eInstance()->getValueSpecification_EClass());
	m_evaluation_EReference_specification->setLowerBound(1);
	m_evaluation_EReference_specification->setUpperBound(1);
	m_evaluation_EReference_specification->setTransient(false);
	m_evaluation_EReference_specification->setVolatile(false);
	m_evaluation_EReference_specification->setChangeable(true);
	m_evaluation_EReference_specification->setUnsettable(false);
	m_evaluation_EReference_specification->setUnique(true);
	m_evaluation_EReference_specification->setDerived(false);
	m_evaluation_EReference_specification->setOrdered(false);
	m_evaluation_EReference_specification->setContainment(false);
	m_evaluation_EReference_specification->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_evaluation_EReference_specification->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_evaluation_EReference_specification->setEOpposite(otherEnd);
	    }
	}
	
	m_evaluation_EOperation_evaluate->setEType(getValue_EClass());
	m_evaluation_EOperation_evaluate->setName("evaluate");
	m_evaluation_EOperation_evaluate->setLowerBound(0);
	m_evaluation_EOperation_evaluate->setUpperBound(1);
	m_evaluation_EOperation_evaluate->setUnique(true);
	m_evaluation_EOperation_evaluate->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeEventAccepterContent()
{
	m_eventAccepter_EClass->setInstanceClass(nullptr);
	m_eventAccepter_EClass->setName("EventAccepter");
	m_eventAccepter_EClass->setAbstract(true);
	m_eventAccepter_EClass->setInterface(false);
	
	
	
	m_eventAccepter_EOperation_accept_SignalInstance->setEType(nullptr);
	m_eventAccepter_EOperation_accept_SignalInstance->setName("accept");
	m_eventAccepter_EOperation_accept_SignalInstance->setLowerBound(1);
	m_eventAccepter_EOperation_accept_SignalInstance->setUpperBound(1);
	m_eventAccepter_EOperation_accept_SignalInstance->setUnique(true);
	m_eventAccepter_EOperation_accept_SignalInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eventAccepter_EOperation_accept_SignalInstance);
		parameter->setName("signalInstance");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eventAccepter_EOperation_match_SignalInstance->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_eventAccepter_EOperation_match_SignalInstance->setName("match");
	m_eventAccepter_EOperation_match_SignalInstance->setLowerBound(1);
	m_eventAccepter_EOperation_match_SignalInstance->setUpperBound(1);
	m_eventAccepter_EOperation_match_SignalInstance->setUnique(true);
	m_eventAccepter_EOperation_match_SignalInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eventAccepter_EOperation_match_SignalInstance);
		parameter->setName("signalInstance");
		parameter->setEType(getSignalInstance_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeEventDispatchLoopContent()
{
	m_eventDispatchLoop_EClass->setInstanceClass(nullptr);
	m_eventDispatchLoop_EClass->setName("EventDispatchLoop");
	m_eventDispatchLoop_EClass->setAbstract(false);
	m_eventDispatchLoop_EClass->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeExecutionContent()
{
	m_execution_EClass->setInstanceClass(nullptr);
	m_execution_EClass->setName("Execution");
	m_execution_EClass->setAbstract(true);
	m_execution_EClass->setInterface(false);
	
	
	m_execution_EReference_context->setName("context");
	m_execution_EReference_context->setEType(getObject_EClass());
	m_execution_EReference_context->setLowerBound(1);
	m_execution_EReference_context->setUpperBound(1);
	m_execution_EReference_context->setTransient(false);
	m_execution_EReference_context->setVolatile(false);
	m_execution_EReference_context->setChangeable(true);
	m_execution_EReference_context->setUnsettable(false);
	m_execution_EReference_context->setUnique(true);
	m_execution_EReference_context->setDerived(false);
	m_execution_EReference_context->setOrdered(false);
	m_execution_EReference_context->setContainment(false);
	m_execution_EReference_context->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_execution_EReference_context->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_execution_EReference_context->setEOpposite(otherEnd);
	    }
	}
	m_execution_EReference_parameterValues->setName("parameterValues");
	m_execution_EReference_parameterValues->setEType(getParameterValue_EClass());
	m_execution_EReference_parameterValues->setLowerBound(0);
	m_execution_EReference_parameterValues->setUpperBound(-1);
	m_execution_EReference_parameterValues->setTransient(false);
	m_execution_EReference_parameterValues->setVolatile(false);
	m_execution_EReference_parameterValues->setChangeable(true);
	m_execution_EReference_parameterValues->setUnsettable(false);
	m_execution_EReference_parameterValues->setUnique(true);
	m_execution_EReference_parameterValues->setDerived(false);
	m_execution_EReference_parameterValues->setOrdered(false);
	m_execution_EReference_parameterValues->setContainment(true);
	m_execution_EReference_parameterValues->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_execution_EReference_parameterValues->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_execution_EReference_parameterValues->setEOpposite(otherEnd);
	    }
	}
	
	m_execution_EOperation_execute->setEType(nullptr);
	m_execution_EOperation_execute->setName("execute");
	m_execution_EOperation_execute->setLowerBound(1);
	m_execution_EOperation_execute->setUpperBound(1);
	m_execution_EOperation_execute->setUnique(true);
	m_execution_EOperation_execute->setOrdered(false);
	
	
	m_execution_EOperation_getBehavior->setEType(uml::UmlPackage::eInstance()->getBehavior_EClass());
	m_execution_EOperation_getBehavior->setName("getBehavior");
	m_execution_EOperation_getBehavior->setLowerBound(1);
	m_execution_EOperation_getBehavior->setUpperBound(1);
	m_execution_EOperation_getBehavior->setUnique(true);
	m_execution_EOperation_getBehavior->setOrdered(false);
	
	
	m_execution_EOperation_getOutputParameterValues->setEType(getParameterValue_EClass());
	m_execution_EOperation_getOutputParameterValues->setName("getOutputParameterValues");
	m_execution_EOperation_getOutputParameterValues->setLowerBound(0);
	m_execution_EOperation_getOutputParameterValues->setUpperBound(-1);
	m_execution_EOperation_getOutputParameterValues->setUnique(true);
	m_execution_EOperation_getOutputParameterValues->setOrdered(false);
	
	
	m_execution_EOperation_getParameterValue_Parameter->setEType(getParameterValue_EClass());
	m_execution_EOperation_getParameterValue_Parameter->setName("getParameterValue");
	m_execution_EOperation_getParameterValue_Parameter->setLowerBound(1);
	m_execution_EOperation_getParameterValue_Parameter->setUpperBound(1);
	m_execution_EOperation_getParameterValue_Parameter->setUnique(true);
	m_execution_EOperation_getParameterValue_Parameter->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_execution_EOperation_getParameterValue_Parameter);
		parameter->setName("parameter");
		parameter->setEType(uml::UmlPackage::eInstance()->getParameter_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_execution_EOperation_new_->setEType(getValue_EClass());
	m_execution_EOperation_new_->setName("new_");
	m_execution_EOperation_new_->setLowerBound(1);
	m_execution_EOperation_new_->setUpperBound(1);
	m_execution_EOperation_new_->setUnique(true);
	m_execution_EOperation_new_->setOrdered(false);
	
	
	m_execution_EOperation_setParameterValue_ParameterValue->setEType(nullptr);
	m_execution_EOperation_setParameterValue_ParameterValue->setName("setParameterValue");
	m_execution_EOperation_setParameterValue_ParameterValue->setLowerBound(1);
	m_execution_EOperation_setParameterValue_ParameterValue->setUpperBound(1);
	m_execution_EOperation_setParameterValue_ParameterValue->setUnique(true);
	m_execution_EOperation_setParameterValue_ParameterValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_execution_EOperation_setParameterValue_ParameterValue);
		parameter->setName("parameterValue");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_execution_EOperation_terminate->setEType(nullptr);
	m_execution_EOperation_terminate->setName("terminate");
	m_execution_EOperation_terminate->setLowerBound(1);
	m_execution_EOperation_terminate->setUpperBound(1);
	m_execution_EOperation_terminate->setUnique(true);
	m_execution_EOperation_terminate->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeExecutionFactoryContent()
{
	m_executionFactory_EClass->setInstanceClass(nullptr);
	m_executionFactory_EClass->setName("ExecutionFactory");
	m_executionFactory_EClass->setAbstract(true);
	m_executionFactory_EClass->setInterface(false);
	
	
	m_executionFactory_EReference_builtInTypes->setName("builtInTypes");
	m_executionFactory_EReference_builtInTypes->setEType(uml::UmlPackage::eInstance()->getPrimitiveType_EClass());
	m_executionFactory_EReference_builtInTypes->setLowerBound(0);
	m_executionFactory_EReference_builtInTypes->setUpperBound(-1);
	m_executionFactory_EReference_builtInTypes->setTransient(false);
	m_executionFactory_EReference_builtInTypes->setVolatile(false);
	m_executionFactory_EReference_builtInTypes->setChangeable(true);
	m_executionFactory_EReference_builtInTypes->setUnsettable(false);
	m_executionFactory_EReference_builtInTypes->setUnique(true);
	m_executionFactory_EReference_builtInTypes->setDerived(false);
	m_executionFactory_EReference_builtInTypes->setOrdered(false);
	m_executionFactory_EReference_builtInTypes->setContainment(false);
	m_executionFactory_EReference_builtInTypes->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_executionFactory_EReference_builtInTypes->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_executionFactory_EReference_builtInTypes->setEOpposite(otherEnd);
	    }
	}
	m_executionFactory_EReference_locus->setName("locus");
	m_executionFactory_EReference_locus->setEType(getLocus_EClass());
	m_executionFactory_EReference_locus->setLowerBound(0);
	m_executionFactory_EReference_locus->setUpperBound(1);
	m_executionFactory_EReference_locus->setTransient(false);
	m_executionFactory_EReference_locus->setVolatile(false);
	m_executionFactory_EReference_locus->setChangeable(true);
	m_executionFactory_EReference_locus->setUnsettable(false);
	m_executionFactory_EReference_locus->setUnique(true);
	m_executionFactory_EReference_locus->setDerived(false);
	m_executionFactory_EReference_locus->setOrdered(false);
	m_executionFactory_EReference_locus->setContainment(false);
	m_executionFactory_EReference_locus->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_executionFactory_EReference_locus->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getLocus_EReference_factory();
		if (otherEnd != nullptr)
	    {
	   		m_executionFactory_EReference_locus->setEOpposite(otherEnd);
	    }
	}
	m_executionFactory_EReference_primitiveBehaviorPrototypes->setName("primitiveBehaviorPrototypes");
	m_executionFactory_EReference_primitiveBehaviorPrototypes->setEType(getOpaqueBehaviorExecution_EClass());
	m_executionFactory_EReference_primitiveBehaviorPrototypes->setLowerBound(0);
	m_executionFactory_EReference_primitiveBehaviorPrototypes->setUpperBound(-1);
	m_executionFactory_EReference_primitiveBehaviorPrototypes->setTransient(false);
	m_executionFactory_EReference_primitiveBehaviorPrototypes->setVolatile(false);
	m_executionFactory_EReference_primitiveBehaviorPrototypes->setChangeable(true);
	m_executionFactory_EReference_primitiveBehaviorPrototypes->setUnsettable(false);
	m_executionFactory_EReference_primitiveBehaviorPrototypes->setUnique(true);
	m_executionFactory_EReference_primitiveBehaviorPrototypes->setDerived(false);
	m_executionFactory_EReference_primitiveBehaviorPrototypes->setOrdered(true);
	m_executionFactory_EReference_primitiveBehaviorPrototypes->setContainment(false);
	m_executionFactory_EReference_primitiveBehaviorPrototypes->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_executionFactory_EReference_primitiveBehaviorPrototypes->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_executionFactory_EReference_primitiveBehaviorPrototypes->setEOpposite(otherEnd);
	    }
	}
	m_executionFactory_EReference_strategies->setName("strategies");
	m_executionFactory_EReference_strategies->setEType(getSemanticStrategy_EClass());
	m_executionFactory_EReference_strategies->setLowerBound(0);
	m_executionFactory_EReference_strategies->setUpperBound(-1);
	m_executionFactory_EReference_strategies->setTransient(false);
	m_executionFactory_EReference_strategies->setVolatile(false);
	m_executionFactory_EReference_strategies->setChangeable(true);
	m_executionFactory_EReference_strategies->setUnsettable(false);
	m_executionFactory_EReference_strategies->setUnique(true);
	m_executionFactory_EReference_strategies->setDerived(false);
	m_executionFactory_EReference_strategies->setOrdered(false);
	m_executionFactory_EReference_strategies->setContainment(false);
	m_executionFactory_EReference_strategies->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_executionFactory_EReference_strategies->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_executionFactory_EReference_strategies->setEOpposite(otherEnd);
	    }
	}
	
	m_executionFactory_EOperation_addBuiltInType_PrimitiveType->setEType(nullptr);
	m_executionFactory_EOperation_addBuiltInType_PrimitiveType->setName("addBuiltInType");
	m_executionFactory_EOperation_addBuiltInType_PrimitiveType->setLowerBound(1);
	m_executionFactory_EOperation_addBuiltInType_PrimitiveType->setUpperBound(1);
	m_executionFactory_EOperation_addBuiltInType_PrimitiveType->setUnique(true);
	m_executionFactory_EOperation_addBuiltInType_PrimitiveType->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactory_EOperation_addBuiltInType_PrimitiveType);
		parameter->setName("type");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executionFactory_EOperation_addPrimitiveBehaviorPrototype_OpaqueBehaviorExecution->setEType(nullptr);
	m_executionFactory_EOperation_addPrimitiveBehaviorPrototype_OpaqueBehaviorExecution->setName("addPrimitiveBehaviorPrototype");
	m_executionFactory_EOperation_addPrimitiveBehaviorPrototype_OpaqueBehaviorExecution->setLowerBound(1);
	m_executionFactory_EOperation_addPrimitiveBehaviorPrototype_OpaqueBehaviorExecution->setUpperBound(1);
	m_executionFactory_EOperation_addPrimitiveBehaviorPrototype_OpaqueBehaviorExecution->setUnique(true);
	m_executionFactory_EOperation_addPrimitiveBehaviorPrototype_OpaqueBehaviorExecution->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactory_EOperation_addPrimitiveBehaviorPrototype_OpaqueBehaviorExecution);
		parameter->setName("execution");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executionFactory_EOperation_assignStrategy_SemanticStrategy->setEType(nullptr);
	m_executionFactory_EOperation_assignStrategy_SemanticStrategy->setName("assignStrategy");
	m_executionFactory_EOperation_assignStrategy_SemanticStrategy->setLowerBound(1);
	m_executionFactory_EOperation_assignStrategy_SemanticStrategy->setUpperBound(1);
	m_executionFactory_EOperation_assignStrategy_SemanticStrategy->setUnique(true);
	m_executionFactory_EOperation_assignStrategy_SemanticStrategy->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactory_EOperation_assignStrategy_SemanticStrategy);
		parameter->setName("strategy");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executionFactory_EOperation_createEvaluation_ValueSpecification->setEType(getEvaluation_EClass());
	m_executionFactory_EOperation_createEvaluation_ValueSpecification->setName("createEvaluation");
	m_executionFactory_EOperation_createEvaluation_ValueSpecification->setLowerBound(1);
	m_executionFactory_EOperation_createEvaluation_ValueSpecification->setUpperBound(1);
	m_executionFactory_EOperation_createEvaluation_ValueSpecification->setUnique(true);
	m_executionFactory_EOperation_createEvaluation_ValueSpecification->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactory_EOperation_createEvaluation_ValueSpecification);
		parameter->setName("specification");
		parameter->setEType(uml::UmlPackage::eInstance()->getValueSpecification_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executionFactory_EOperation_createExecution_Behavior_Object->setEType(getExecution_EClass());
	m_executionFactory_EOperation_createExecution_Behavior_Object->setName("createExecution");
	m_executionFactory_EOperation_createExecution_Behavior_Object->setLowerBound(1);
	m_executionFactory_EOperation_createExecution_Behavior_Object->setUpperBound(1);
	m_executionFactory_EOperation_createExecution_Behavior_Object->setUnique(true);
	m_executionFactory_EOperation_createExecution_Behavior_Object->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactory_EOperation_createExecution_Behavior_Object);
		parameter->setName("behavior");
		parameter->setEType(uml::UmlPackage::eInstance()->getBehavior_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactory_EOperation_createExecution_Behavior_Object);
		parameter->setName("context");
		parameter->setEType(getObject_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executionFactory_EOperation_getBuiltInType_EString->setEType(uml::UmlPackage::eInstance()->getPrimitiveType_EClass());
	m_executionFactory_EOperation_getBuiltInType_EString->setName("getBuiltInType");
	m_executionFactory_EOperation_getBuiltInType_EString->setLowerBound(0);
	m_executionFactory_EOperation_getBuiltInType_EString->setUpperBound(1);
	m_executionFactory_EOperation_getBuiltInType_EString->setUnique(true);
	m_executionFactory_EOperation_getBuiltInType_EString->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactory_EOperation_getBuiltInType_EString);
		parameter->setName("name");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEString_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executionFactory_EOperation_getStrategy_EString->setEType(getSemanticStrategy_EClass());
	m_executionFactory_EOperation_getStrategy_EString->setName("getStrategy");
	m_executionFactory_EOperation_getStrategy_EString->setLowerBound(0);
	m_executionFactory_EOperation_getStrategy_EString->setUpperBound(1);
	m_executionFactory_EOperation_getStrategy_EString->setUnique(true);
	m_executionFactory_EOperation_getStrategy_EString->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactory_EOperation_getStrategy_EString);
		parameter->setName("name");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEString_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executionFactory_EOperation_getStrategyIndex_EString->setEType(ecore::EcorePackage::eInstance()->getEInt_EDataType());
	m_executionFactory_EOperation_getStrategyIndex_EString->setName("getStrategyIndex");
	m_executionFactory_EOperation_getStrategyIndex_EString->setLowerBound(1);
	m_executionFactory_EOperation_getStrategyIndex_EString->setUpperBound(1);
	m_executionFactory_EOperation_getStrategyIndex_EString->setUnique(true);
	m_executionFactory_EOperation_getStrategyIndex_EString->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactory_EOperation_getStrategyIndex_EString);
		parameter->setName("name");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEString_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executionFactory_EOperation_instantiateOpaqueBehaviorExecution_OpaqueBehavior->setEType(getOpaqueBehaviorExecution_EClass());
	m_executionFactory_EOperation_instantiateOpaqueBehaviorExecution_OpaqueBehavior->setName("instantiateOpaqueBehaviorExecution");
	m_executionFactory_EOperation_instantiateOpaqueBehaviorExecution_OpaqueBehavior->setLowerBound(1);
	m_executionFactory_EOperation_instantiateOpaqueBehaviorExecution_OpaqueBehavior->setUpperBound(1);
	m_executionFactory_EOperation_instantiateOpaqueBehaviorExecution_OpaqueBehavior->setUnique(true);
	m_executionFactory_EOperation_instantiateOpaqueBehaviorExecution_OpaqueBehavior->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactory_EOperation_instantiateOpaqueBehaviorExecution_OpaqueBehavior);
		parameter->setName("behavior");
		parameter->setEType(uml::UmlPackage::eInstance()->getOpaqueBehavior_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executionFactory_EOperation_instantiateVisitor_Element->setEType(getSemanticVisitor_EClass());
	m_executionFactory_EOperation_instantiateVisitor_Element->setName("instantiateVisitor");
	m_executionFactory_EOperation_instantiateVisitor_Element->setLowerBound(1);
	m_executionFactory_EOperation_instantiateVisitor_Element->setUpperBound(1);
	m_executionFactory_EOperation_instantiateVisitor_Element->setUnique(true);
	m_executionFactory_EOperation_instantiateVisitor_Element->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactory_EOperation_instantiateVisitor_Element);
		parameter->setName("element");
		parameter->setEType(uml::UmlPackage::eInstance()->getElement_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeExecutionFactoryL1Content()
{
	m_executionFactoryL1_EClass->setInstanceClass(nullptr);
	m_executionFactoryL1_EClass->setName("ExecutionFactoryL1");
	m_executionFactoryL1_EClass->setAbstract(false);
	m_executionFactoryL1_EClass->setInterface(false);
	
	
	
	m_executionFactoryL1_EOperation_instantiateVisitor_Element->setEType(getSemanticVisitor_EClass());
	m_executionFactoryL1_EOperation_instantiateVisitor_Element->setName("instantiateVisitor");
	m_executionFactoryL1_EOperation_instantiateVisitor_Element->setLowerBound(1);
	m_executionFactoryL1_EOperation_instantiateVisitor_Element->setUpperBound(1);
	m_executionFactoryL1_EOperation_instantiateVisitor_Element->setUnique(true);
	m_executionFactoryL1_EOperation_instantiateVisitor_Element->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactoryL1_EOperation_instantiateVisitor_Element);
		parameter->setName("element");
		parameter->setEType(uml::UmlPackage::eInstance()->getElement_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeExecutionFactoryL2Content()
{
	m_executionFactoryL2_EClass->setInstanceClass(nullptr);
	m_executionFactoryL2_EClass->setName("ExecutionFactoryL2");
	m_executionFactoryL2_EClass->setAbstract(false);
	m_executionFactoryL2_EClass->setInterface(false);
	
	
	
	m_executionFactoryL2_EOperation_instantiateVisitor_Element->setEType(getSemanticVisitor_EClass());
	m_executionFactoryL2_EOperation_instantiateVisitor_Element->setName("instantiateVisitor");
	m_executionFactoryL2_EOperation_instantiateVisitor_Element->setLowerBound(1);
	m_executionFactoryL2_EOperation_instantiateVisitor_Element->setUpperBound(1);
	m_executionFactoryL2_EOperation_instantiateVisitor_Element->setUnique(true);
	m_executionFactoryL2_EOperation_instantiateVisitor_Element->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactoryL2_EOperation_instantiateVisitor_Element);
		parameter->setName("element");
		parameter->setEType(uml::UmlPackage::eInstance()->getElement_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeExecutionFactoryL3Content()
{
	m_executionFactoryL3_EClass->setInstanceClass(nullptr);
	m_executionFactoryL3_EClass->setName("ExecutionFactoryL3");
	m_executionFactoryL3_EClass->setAbstract(false);
	m_executionFactoryL3_EClass->setInterface(false);
	
	
	
	m_executionFactoryL3_EOperation_instantiateVisitor_Element->setEType(getSemanticVisitor_EClass());
	m_executionFactoryL3_EOperation_instantiateVisitor_Element->setName("instantiateVisitor");
	m_executionFactoryL3_EOperation_instantiateVisitor_Element->setLowerBound(1);
	m_executionFactoryL3_EOperation_instantiateVisitor_Element->setUpperBound(1);
	m_executionFactoryL3_EOperation_instantiateVisitor_Element->setUnique(true);
	m_executionFactoryL3_EOperation_instantiateVisitor_Element->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactoryL3_EOperation_instantiateVisitor_Element);
		parameter->setName("element");
		parameter->setEType(uml::UmlPackage::eInstance()->getElement_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeExecutorContent()
{
	m_executor_EClass->setInstanceClass(nullptr);
	m_executor_EClass->setName("Executor");
	m_executor_EClass->setAbstract(false);
	m_executor_EClass->setInterface(false);
	
	
	m_executor_EReference_locus->setName("locus");
	m_executor_EReference_locus->setEType(getLocus_EClass());
	m_executor_EReference_locus->setLowerBound(0);
	m_executor_EReference_locus->setUpperBound(1);
	m_executor_EReference_locus->setTransient(false);
	m_executor_EReference_locus->setVolatile(false);
	m_executor_EReference_locus->setChangeable(true);
	m_executor_EReference_locus->setUnsettable(false);
	m_executor_EReference_locus->setUnique(true);
	m_executor_EReference_locus->setDerived(false);
	m_executor_EReference_locus->setOrdered(false);
	m_executor_EReference_locus->setContainment(false);
	m_executor_EReference_locus->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_executor_EReference_locus->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_executor_EReference_locus->setEOpposite(otherEnd);
	    }
	}
	
	m_executor_EOperation_evaluate_ValueSpecification->setEType(getValue_EClass());
	m_executor_EOperation_evaluate_ValueSpecification->setName("evaluate");
	m_executor_EOperation_evaluate_ValueSpecification->setLowerBound(1);
	m_executor_EOperation_evaluate_ValueSpecification->setUpperBound(1);
	m_executor_EOperation_evaluate_ValueSpecification->setUnique(true);
	m_executor_EOperation_evaluate_ValueSpecification->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executor_EOperation_evaluate_ValueSpecification);
		parameter->setName("specification");
		parameter->setEType(uml::UmlPackage::eInstance()->getValueSpecification_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executor_EOperation_execute_Behavior_ParameterValue->setEType(getParameterValue_EClass());
	m_executor_EOperation_execute_Behavior_ParameterValue->setName("execute");
	m_executor_EOperation_execute_Behavior_ParameterValue->setLowerBound(0);
	m_executor_EOperation_execute_Behavior_ParameterValue->setUpperBound(-1);
	m_executor_EOperation_execute_Behavior_ParameterValue->setUnique(true);
	m_executor_EOperation_execute_Behavior_ParameterValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executor_EOperation_execute_Behavior_ParameterValue);
		parameter->setName("behavior");
		parameter->setEType(uml::UmlPackage::eInstance()->getBehavior_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executor_EOperation_execute_Behavior_ParameterValue);
		parameter->setName("context");
		parameter->setEType(getObject_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executor_EOperation_execute_Behavior_ParameterValue);
		parameter->setName("inputs");
		parameter->setEType(getParameterValue_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executor_EOperation_start_Class_ParameterValue->setEType(getReference_EClass());
	m_executor_EOperation_start_Class_ParameterValue->setName("start");
	m_executor_EOperation_start_Class_ParameterValue->setLowerBound(1);
	m_executor_EOperation_start_Class_ParameterValue->setUpperBound(1);
	m_executor_EOperation_start_Class_ParameterValue->setUnique(true);
	m_executor_EOperation_start_Class_ParameterValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executor_EOperation_start_Class_ParameterValue);
		parameter->setName("type");
		parameter->setEType(uml::UmlPackage::eInstance()->getClass_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executor_EOperation_start_Class_ParameterValue);
		parameter->setName("inputs");
		parameter->setEType(getParameterValue_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeExpansionActivationGroupContent()
{
	m_expansionActivationGroup_EClass->setInstanceClass(nullptr);
	m_expansionActivationGroup_EClass->setName("ExpansionActivationGroup");
	m_expansionActivationGroup_EClass->setAbstract(false);
	m_expansionActivationGroup_EClass->setInterface(false);
	
	
	m_expansionActivationGroup_EReference_regionActivation->setName("regionActivation");
	m_expansionActivationGroup_EReference_regionActivation->setEType(getExpansionRegionActivation_EClass());
	m_expansionActivationGroup_EReference_regionActivation->setLowerBound(1);
	m_expansionActivationGroup_EReference_regionActivation->setUpperBound(1);
	m_expansionActivationGroup_EReference_regionActivation->setTransient(false);
	m_expansionActivationGroup_EReference_regionActivation->setVolatile(false);
	m_expansionActivationGroup_EReference_regionActivation->setChangeable(true);
	m_expansionActivationGroup_EReference_regionActivation->setUnsettable(false);
	m_expansionActivationGroup_EReference_regionActivation->setUnique(true);
	m_expansionActivationGroup_EReference_regionActivation->setDerived(false);
	m_expansionActivationGroup_EReference_regionActivation->setOrdered(false);
	m_expansionActivationGroup_EReference_regionActivation->setContainment(false);
	m_expansionActivationGroup_EReference_regionActivation->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_expansionActivationGroup_EReference_regionActivation->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_expansionActivationGroup_EReference_regionActivation->setEOpposite(otherEnd);
	    }
	}
	
	
}

void FUMLPackageImpl::initializeExpansionNodeActivationContent()
{
	m_expansionNodeActivation_EClass->setInstanceClass(nullptr);
	m_expansionNodeActivation_EClass->setName("ExpansionNodeActivation");
	m_expansionNodeActivation_EClass->setAbstract(false);
	m_expansionNodeActivation_EClass->setInterface(false);
	
	
	
	m_expansionNodeActivation_EOperation_getExpansionRegionActivation->setEType(getExpansionRegionActivation_EClass());
	m_expansionNodeActivation_EOperation_getExpansionRegionActivation->setName("getExpansionRegionActivation");
	m_expansionNodeActivation_EOperation_getExpansionRegionActivation->setLowerBound(1);
	m_expansionNodeActivation_EOperation_getExpansionRegionActivation->setUpperBound(1);
	m_expansionNodeActivation_EOperation_getExpansionRegionActivation->setUnique(true);
	m_expansionNodeActivation_EOperation_getExpansionRegionActivation->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeExpansionRegionActivationContent()
{
	m_expansionRegionActivation_EClass->setInstanceClass(nullptr);
	m_expansionRegionActivation_EClass->setName("ExpansionRegionActivation");
	m_expansionRegionActivation_EClass->setAbstract(false);
	m_expansionRegionActivation_EClass->setInterface(false);
	
	
	m_expansionRegionActivation_EReference_activationGroups->setName("activationGroups");
	m_expansionRegionActivation_EReference_activationGroups->setEType(getExpansionActivationGroup_EClass());
	m_expansionRegionActivation_EReference_activationGroups->setLowerBound(0);
	m_expansionRegionActivation_EReference_activationGroups->setUpperBound(-1);
	m_expansionRegionActivation_EReference_activationGroups->setTransient(false);
	m_expansionRegionActivation_EReference_activationGroups->setVolatile(false);
	m_expansionRegionActivation_EReference_activationGroups->setChangeable(true);
	m_expansionRegionActivation_EReference_activationGroups->setUnsettable(false);
	m_expansionRegionActivation_EReference_activationGroups->setUnique(true);
	m_expansionRegionActivation_EReference_activationGroups->setDerived(false);
	m_expansionRegionActivation_EReference_activationGroups->setOrdered(false);
	m_expansionRegionActivation_EReference_activationGroups->setContainment(false);
	m_expansionRegionActivation_EReference_activationGroups->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_expansionRegionActivation_EReference_activationGroups->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_expansionRegionActivation_EReference_activationGroups->setEOpposite(otherEnd);
	    }
	}
	m_expansionRegionActivation_EReference_inputExpansionTokens->setName("inputExpansionTokens");
	m_expansionRegionActivation_EReference_inputExpansionTokens->setEType(getTokenSet_EClass());
	m_expansionRegionActivation_EReference_inputExpansionTokens->setLowerBound(1);
	m_expansionRegionActivation_EReference_inputExpansionTokens->setUpperBound(-1);
	m_expansionRegionActivation_EReference_inputExpansionTokens->setTransient(false);
	m_expansionRegionActivation_EReference_inputExpansionTokens->setVolatile(false);
	m_expansionRegionActivation_EReference_inputExpansionTokens->setChangeable(true);
	m_expansionRegionActivation_EReference_inputExpansionTokens->setUnsettable(false);
	m_expansionRegionActivation_EReference_inputExpansionTokens->setUnique(true);
	m_expansionRegionActivation_EReference_inputExpansionTokens->setDerived(false);
	m_expansionRegionActivation_EReference_inputExpansionTokens->setOrdered(false);
	m_expansionRegionActivation_EReference_inputExpansionTokens->setContainment(false);
	m_expansionRegionActivation_EReference_inputExpansionTokens->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_expansionRegionActivation_EReference_inputExpansionTokens->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_expansionRegionActivation_EReference_inputExpansionTokens->setEOpposite(otherEnd);
	    }
	}
	m_expansionRegionActivation_EReference_inputTokens->setName("inputTokens");
	m_expansionRegionActivation_EReference_inputTokens->setEType(getTokenSet_EClass());
	m_expansionRegionActivation_EReference_inputTokens->setLowerBound(0);
	m_expansionRegionActivation_EReference_inputTokens->setUpperBound(-1);
	m_expansionRegionActivation_EReference_inputTokens->setTransient(false);
	m_expansionRegionActivation_EReference_inputTokens->setVolatile(false);
	m_expansionRegionActivation_EReference_inputTokens->setChangeable(true);
	m_expansionRegionActivation_EReference_inputTokens->setUnsettable(false);
	m_expansionRegionActivation_EReference_inputTokens->setUnique(true);
	m_expansionRegionActivation_EReference_inputTokens->setDerived(false);
	m_expansionRegionActivation_EReference_inputTokens->setOrdered(false);
	m_expansionRegionActivation_EReference_inputTokens->setContainment(false);
	m_expansionRegionActivation_EReference_inputTokens->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_expansionRegionActivation_EReference_inputTokens->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_expansionRegionActivation_EReference_inputTokens->setEOpposite(otherEnd);
	    }
	}
	
	m_expansionRegionActivation_EOperation_doStructuredActivity->setEType(nullptr);
	m_expansionRegionActivation_EOperation_doStructuredActivity->setName("doStructuredActivity");
	m_expansionRegionActivation_EOperation_doStructuredActivity->setLowerBound(1);
	m_expansionRegionActivation_EOperation_doStructuredActivity->setUpperBound(1);
	m_expansionRegionActivation_EOperation_doStructuredActivity->setUnique(true);
	m_expansionRegionActivation_EOperation_doStructuredActivity->setOrdered(false);
	
	
	m_expansionRegionActivation_EOperation_getExpansionNodeActivation_ExpansionNode->setEType(getExpansionNodeActivation_EClass());
	m_expansionRegionActivation_EOperation_getExpansionNodeActivation_ExpansionNode->setName("getExpansionNodeActivation");
	m_expansionRegionActivation_EOperation_getExpansionNodeActivation_ExpansionNode->setLowerBound(1);
	m_expansionRegionActivation_EOperation_getExpansionNodeActivation_ExpansionNode->setUpperBound(1);
	m_expansionRegionActivation_EOperation_getExpansionNodeActivation_ExpansionNode->setUnique(true);
	m_expansionRegionActivation_EOperation_getExpansionNodeActivation_ExpansionNode->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_expansionRegionActivation_EOperation_getExpansionNodeActivation_ExpansionNode);
		parameter->setName("node");
		parameter->setEType(uml::UmlPackage::eInstance()->getExpansionNode_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_expansionRegionActivation_EOperation_numberOfValues->setEType(ecore::EcorePackage::eInstance()->getEInt_EDataType());
	m_expansionRegionActivation_EOperation_numberOfValues->setName("numberOfValues");
	m_expansionRegionActivation_EOperation_numberOfValues->setLowerBound(1);
	m_expansionRegionActivation_EOperation_numberOfValues->setUpperBound(1);
	m_expansionRegionActivation_EOperation_numberOfValues->setUnique(true);
	m_expansionRegionActivation_EOperation_numberOfValues->setOrdered(false);
	
	
	m_expansionRegionActivation_EOperation_runGroup_ExpansionActivationGroup->setEType(nullptr);
	m_expansionRegionActivation_EOperation_runGroup_ExpansionActivationGroup->setName("runGroup");
	m_expansionRegionActivation_EOperation_runGroup_ExpansionActivationGroup->setLowerBound(1);
	m_expansionRegionActivation_EOperation_runGroup_ExpansionActivationGroup->setUpperBound(1);
	m_expansionRegionActivation_EOperation_runGroup_ExpansionActivationGroup->setUnique(true);
	m_expansionRegionActivation_EOperation_runGroup_ExpansionActivationGroup->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_expansionRegionActivation_EOperation_runGroup_ExpansionActivationGroup);
		parameter->setName("activationGroup");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeExtensionalValueContent()
{
	m_extensionalValue_EClass->setInstanceClass(nullptr);
	m_extensionalValue_EClass->setName("ExtensionalValue");
	m_extensionalValue_EClass->setAbstract(true);
	m_extensionalValue_EClass->setInterface(false);
	
	
	m_extensionalValue_EReference_locus->setName("locus");
	m_extensionalValue_EReference_locus->setEType(getLocus_EClass());
	m_extensionalValue_EReference_locus->setLowerBound(0);
	m_extensionalValue_EReference_locus->setUpperBound(1);
	m_extensionalValue_EReference_locus->setTransient(false);
	m_extensionalValue_EReference_locus->setVolatile(false);
	m_extensionalValue_EReference_locus->setChangeable(true);
	m_extensionalValue_EReference_locus->setUnsettable(false);
	m_extensionalValue_EReference_locus->setUnique(true);
	m_extensionalValue_EReference_locus->setDerived(false);
	m_extensionalValue_EReference_locus->setOrdered(false);
	m_extensionalValue_EReference_locus->setContainment(false);
	m_extensionalValue_EReference_locus->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_extensionalValue_EReference_locus->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_extensionalValue_EReference_locus->setEOpposite(otherEnd);
	    }
	}
	
	m_extensionalValue_EOperation_destroy->setEType(nullptr);
	m_extensionalValue_EOperation_destroy->setName("destroy");
	m_extensionalValue_EOperation_destroy->setLowerBound(1);
	m_extensionalValue_EOperation_destroy->setUpperBound(1);
	m_extensionalValue_EOperation_destroy->setUnique(true);
	m_extensionalValue_EOperation_destroy->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeExtensionalValueListContent()
{
	m_extensionalValueList_EClass->setInstanceClass(nullptr);
	m_extensionalValueList_EClass->setName("ExtensionalValueList");
	m_extensionalValueList_EClass->setAbstract(false);
	m_extensionalValueList_EClass->setInterface(false);
	
	
	
	m_extensionalValueList_EOperation_addValue_ExtensionalValue->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_extensionalValueList_EOperation_addValue_ExtensionalValue->setName("addValue");
	m_extensionalValueList_EOperation_addValue_ExtensionalValue->setLowerBound(1);
	m_extensionalValueList_EOperation_addValue_ExtensionalValue->setUpperBound(1);
	m_extensionalValueList_EOperation_addValue_ExtensionalValue->setUnique(true);
	m_extensionalValueList_EOperation_addValue_ExtensionalValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_extensionalValueList_EOperation_addValue_ExtensionalValue);
		parameter->setName("value");
		parameter->setEType(getExtensionalValue_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_extensionalValueList_EOperation_addValue_ExtensionalValue_EInt->setEType(nullptr);
	m_extensionalValueList_EOperation_addValue_ExtensionalValue_EInt->setName("addValue");
	m_extensionalValueList_EOperation_addValue_ExtensionalValue_EInt->setLowerBound(1);
	m_extensionalValueList_EOperation_addValue_ExtensionalValue_EInt->setUpperBound(1);
	m_extensionalValueList_EOperation_addValue_ExtensionalValue_EInt->setUnique(true);
	m_extensionalValueList_EOperation_addValue_ExtensionalValue_EInt->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_extensionalValueList_EOperation_addValue_ExtensionalValue_EInt);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_extensionalValueList_EOperation_addValue_ExtensionalValue_EInt);
		parameter->setName("i");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_extensionalValueList_EOperation_getValue->setEType(getExtensionalValue_EClass());
	m_extensionalValueList_EOperation_getValue->setName("getValue");
	m_extensionalValueList_EOperation_getValue->setLowerBound(1);
	m_extensionalValueList_EOperation_getValue->setUpperBound(1);
	m_extensionalValueList_EOperation_getValue->setUnique(true);
	m_extensionalValueList_EOperation_getValue->setOrdered(false);
	
	
	m_extensionalValueList_EOperation_removeValue_EInt->setEType(ecore::EcorePackage::eInstance()->getEString_EDataType());
	m_extensionalValueList_EOperation_removeValue_EInt->setName("removeValue");
	m_extensionalValueList_EOperation_removeValue_EInt->setLowerBound(1);
	m_extensionalValueList_EOperation_removeValue_EInt->setUpperBound(1);
	m_extensionalValueList_EOperation_removeValue_EInt->setUnique(true);
	m_extensionalValueList_EOperation_removeValue_EInt->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_extensionalValueList_EOperation_removeValue_EInt);
		parameter->setName("i");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEInt_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_extensionalValueList_EOperation_setValue_ExtensionalValue_EInt->setEType(getValue_EClass());
	m_extensionalValueList_EOperation_setValue_ExtensionalValue_EInt->setName("setValue");
	m_extensionalValueList_EOperation_setValue_ExtensionalValue_EInt->setLowerBound(1);
	m_extensionalValueList_EOperation_setValue_ExtensionalValue_EInt->setUpperBound(1);
	m_extensionalValueList_EOperation_setValue_ExtensionalValue_EInt->setUnique(true);
	m_extensionalValueList_EOperation_setValue_ExtensionalValue_EInt->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_extensionalValueList_EOperation_setValue_ExtensionalValue_EInt);
		parameter->setName("value");
		parameter->setEType(getExtensionalValue_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_extensionalValueList_EOperation_setValue_ExtensionalValue_EInt);
		parameter->setName("i");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEInt_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeFIFOGetNextEventStrategyContent()
{
	m_fIFOGetNextEventStrategy_EClass->setInstanceClass(nullptr);
	m_fIFOGetNextEventStrategy_EClass->setName("FIFOGetNextEventStrategy");
	m_fIFOGetNextEventStrategy_EClass->setAbstract(false);
	m_fIFOGetNextEventStrategy_EClass->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeFeatureValueContent()
{
	m_featureValue_EClass->setInstanceClass(nullptr);
	m_featureValue_EClass->setName("FeatureValue");
	m_featureValue_EClass->setAbstract(false);
	m_featureValue_EClass->setInterface(false);
	
	m_featureValue_EAttribute_position = getFeatureValue_EAttribute_position();
	m_featureValue_EAttribute_position->setName("position");
	m_featureValue_EAttribute_position->setEType(ecore::EcorePackage::eInstance()->getEInt_EDataType());
	m_featureValue_EAttribute_position->setLowerBound(0);
	m_featureValue_EAttribute_position->setUpperBound(1);
	m_featureValue_EAttribute_position->setTransient(false);
	m_featureValue_EAttribute_position->setVolatile(false);
	m_featureValue_EAttribute_position->setChangeable(true);
	m_featureValue_EAttribute_position->setUnsettable(false);
	m_featureValue_EAttribute_position->setUnique(true);
	m_featureValue_EAttribute_position->setDerived(false);
	m_featureValue_EAttribute_position->setOrdered(false);
	m_featureValue_EAttribute_position->setID(false);
	{
		std::string defaultValue = "0";
		if (!defaultValue.empty())
		{
		   m_featureValue_EAttribute_position->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_featureValue_EReference_feature->setName("feature");
	m_featureValue_EReference_feature->setEType(uml::UmlPackage::eInstance()->getStructuralFeature_EClass());
	m_featureValue_EReference_feature->setLowerBound(1);
	m_featureValue_EReference_feature->setUpperBound(1);
	m_featureValue_EReference_feature->setTransient(false);
	m_featureValue_EReference_feature->setVolatile(false);
	m_featureValue_EReference_feature->setChangeable(true);
	m_featureValue_EReference_feature->setUnsettable(false);
	m_featureValue_EReference_feature->setUnique(true);
	m_featureValue_EReference_feature->setDerived(false);
	m_featureValue_EReference_feature->setOrdered(false);
	m_featureValue_EReference_feature->setContainment(false);
	m_featureValue_EReference_feature->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_featureValue_EReference_feature->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_featureValue_EReference_feature->setEOpposite(otherEnd);
	    }
	}
	m_featureValue_EReference_values->setName("values");
	m_featureValue_EReference_values->setEType(getValue_EClass());
	m_featureValue_EReference_values->setLowerBound(0);
	m_featureValue_EReference_values->setUpperBound(-1);
	m_featureValue_EReference_values->setTransient(false);
	m_featureValue_EReference_values->setVolatile(false);
	m_featureValue_EReference_values->setChangeable(true);
	m_featureValue_EReference_values->setUnsettable(false);
	m_featureValue_EReference_values->setUnique(true);
	m_featureValue_EReference_values->setDerived(false);
	m_featureValue_EReference_values->setOrdered(false);
	m_featureValue_EReference_values->setContainment(true);
	m_featureValue_EReference_values->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_featureValue_EReference_values->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_featureValue_EReference_values->setEOpposite(otherEnd);
	    }
	}
	
	m_featureValue_EOperation_hasEqualValues_FeatureValue->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_featureValue_EOperation_hasEqualValues_FeatureValue->setName("hasEqualValues");
	m_featureValue_EOperation_hasEqualValues_FeatureValue->setLowerBound(1);
	m_featureValue_EOperation_hasEqualValues_FeatureValue->setUpperBound(1);
	m_featureValue_EOperation_hasEqualValues_FeatureValue->setUnique(true);
	m_featureValue_EOperation_hasEqualValues_FeatureValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_featureValue_EOperation_hasEqualValues_FeatureValue);
		parameter->setName("other");
		parameter->setEType(getFeatureValue_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeFirstChoiceStrategyContent()
{
	m_firstChoiceStrategy_EClass->setInstanceClass(nullptr);
	m_firstChoiceStrategy_EClass->setName("FirstChoiceStrategy");
	m_firstChoiceStrategy_EClass->setAbstract(false);
	m_firstChoiceStrategy_EClass->setInterface(false);
	
	
	
	m_firstChoiceStrategy_EOperation_choose_EInt->setEType(ecore::EcorePackage::eInstance()->getEInt_EDataType());
	m_firstChoiceStrategy_EOperation_choose_EInt->setName("choose");
	m_firstChoiceStrategy_EOperation_choose_EInt->setLowerBound(1);
	m_firstChoiceStrategy_EOperation_choose_EInt->setUpperBound(1);
	m_firstChoiceStrategy_EOperation_choose_EInt->setUnique(true);
	m_firstChoiceStrategy_EOperation_choose_EInt->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_firstChoiceStrategy_EOperation_choose_EInt);
		parameter->setName("size");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEInt_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeFlowFinalNodeActivationContent()
{
	m_flowFinalNodeActivation_EClass->setInstanceClass(nullptr);
	m_flowFinalNodeActivation_EClass->setName("FlowFinalNodeActivation");
	m_flowFinalNodeActivation_EClass->setAbstract(false);
	m_flowFinalNodeActivation_EClass->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeForkNodeActivationContent()
{
	m_forkNodeActivation_EClass->setInstanceClass(nullptr);
	m_forkNodeActivation_EClass->setName("ForkNodeActivation");
	m_forkNodeActivation_EClass->setAbstract(false);
	m_forkNodeActivation_EClass->setInterface(false);
	
	
	
	m_forkNodeActivation_EOperation_fire_Token->setEType(nullptr);
	m_forkNodeActivation_EOperation_fire_Token->setName("fire");
	m_forkNodeActivation_EOperation_fire_Token->setLowerBound(1);
	m_forkNodeActivation_EOperation_fire_Token->setUpperBound(1);
	m_forkNodeActivation_EOperation_fire_Token->setUnique(true);
	m_forkNodeActivation_EOperation_fire_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_forkNodeActivation_EOperation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_forkNodeActivation_EOperation_terminate->setEType(nullptr);
	m_forkNodeActivation_EOperation_terminate->setName("terminate");
	m_forkNodeActivation_EOperation_terminate->setLowerBound(1);
	m_forkNodeActivation_EOperation_terminate->setUpperBound(1);
	m_forkNodeActivation_EOperation_terminate->setUnique(true);
	m_forkNodeActivation_EOperation_terminate->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeForkedTokenContent()
{
	m_forkedToken_EClass->setInstanceClass(nullptr);
	m_forkedToken_EClass->setName("ForkedToken");
	m_forkedToken_EClass->setAbstract(false);
	m_forkedToken_EClass->setInterface(false);
	
	m_forkedToken_EAttribute_baseTokenIsWithdrawn = getForkedToken_EAttribute_baseTokenIsWithdrawn();
	m_forkedToken_EAttribute_baseTokenIsWithdrawn->setName("baseTokenIsWithdrawn");
	m_forkedToken_EAttribute_baseTokenIsWithdrawn->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_forkedToken_EAttribute_baseTokenIsWithdrawn->setLowerBound(1);
	m_forkedToken_EAttribute_baseTokenIsWithdrawn->setUpperBound(1);
	m_forkedToken_EAttribute_baseTokenIsWithdrawn->setTransient(false);
	m_forkedToken_EAttribute_baseTokenIsWithdrawn->setVolatile(false);
	m_forkedToken_EAttribute_baseTokenIsWithdrawn->setChangeable(true);
	m_forkedToken_EAttribute_baseTokenIsWithdrawn->setUnsettable(false);
	m_forkedToken_EAttribute_baseTokenIsWithdrawn->setUnique(true);
	m_forkedToken_EAttribute_baseTokenIsWithdrawn->setDerived(false);
	m_forkedToken_EAttribute_baseTokenIsWithdrawn->setOrdered(false);
	m_forkedToken_EAttribute_baseTokenIsWithdrawn->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_forkedToken_EAttribute_baseTokenIsWithdrawn->setDefaultValueLiteral(defaultValue);
		}
	}
	m_forkedToken_EAttribute_remainingOffersCount = getForkedToken_EAttribute_remainingOffersCount();
	m_forkedToken_EAttribute_remainingOffersCount->setName("remainingOffersCount");
	m_forkedToken_EAttribute_remainingOffersCount->setEType(ecore::EcorePackage::eInstance()->getEInt_EDataType());
	m_forkedToken_EAttribute_remainingOffersCount->setLowerBound(1);
	m_forkedToken_EAttribute_remainingOffersCount->setUpperBound(1);
	m_forkedToken_EAttribute_remainingOffersCount->setTransient(false);
	m_forkedToken_EAttribute_remainingOffersCount->setVolatile(false);
	m_forkedToken_EAttribute_remainingOffersCount->setChangeable(true);
	m_forkedToken_EAttribute_remainingOffersCount->setUnsettable(false);
	m_forkedToken_EAttribute_remainingOffersCount->setUnique(true);
	m_forkedToken_EAttribute_remainingOffersCount->setDerived(false);
	m_forkedToken_EAttribute_remainingOffersCount->setOrdered(false);
	m_forkedToken_EAttribute_remainingOffersCount->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_forkedToken_EAttribute_remainingOffersCount->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_forkedToken_EReference_baseToken->setName("baseToken");
	m_forkedToken_EReference_baseToken->setEType(getToken_EClass());
	m_forkedToken_EReference_baseToken->setLowerBound(0);
	m_forkedToken_EReference_baseToken->setUpperBound(1);
	m_forkedToken_EReference_baseToken->setTransient(false);
	m_forkedToken_EReference_baseToken->setVolatile(false);
	m_forkedToken_EReference_baseToken->setChangeable(true);
	m_forkedToken_EReference_baseToken->setUnsettable(false);
	m_forkedToken_EReference_baseToken->setUnique(true);
	m_forkedToken_EReference_baseToken->setDerived(false);
	m_forkedToken_EReference_baseToken->setOrdered(false);
	m_forkedToken_EReference_baseToken->setContainment(false);
	m_forkedToken_EReference_baseToken->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_forkedToken_EReference_baseToken->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_forkedToken_EReference_baseToken->setEOpposite(otherEnd);
	    }
	}
	
	m_forkedToken_EOperation_equals_Token->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_forkedToken_EOperation_equals_Token->setName("equals");
	m_forkedToken_EOperation_equals_Token->setLowerBound(1);
	m_forkedToken_EOperation_equals_Token->setUpperBound(1);
	m_forkedToken_EOperation_equals_Token->setUnique(true);
	m_forkedToken_EOperation_equals_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_forkedToken_EOperation_equals_Token);
		parameter->setName("otherToken");
		parameter->setEType(getToken_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_forkedToken_EOperation_getValue->setEType(getValue_EClass());
	m_forkedToken_EOperation_getValue->setName("getValue");
	m_forkedToken_EOperation_getValue->setLowerBound(0);
	m_forkedToken_EOperation_getValue->setUpperBound(1);
	m_forkedToken_EOperation_getValue->setUnique(true);
	m_forkedToken_EOperation_getValue->setOrdered(false);
	
	
	m_forkedToken_EOperation_isControl->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_forkedToken_EOperation_isControl->setName("isControl");
	m_forkedToken_EOperation_isControl->setLowerBound(1);
	m_forkedToken_EOperation_isControl->setUpperBound(1);
	m_forkedToken_EOperation_isControl->setUnique(true);
	m_forkedToken_EOperation_isControl->setOrdered(false);
	
	
	m_forkedToken_EOperation_withdraw->setEType(nullptr);
	m_forkedToken_EOperation_withdraw->setName("withdraw");
	m_forkedToken_EOperation_withdraw->setLowerBound(1);
	m_forkedToken_EOperation_withdraw->setUpperBound(1);
	m_forkedToken_EOperation_withdraw->setUnique(true);
	m_forkedToken_EOperation_withdraw->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeGetNextEventStrategyContent()
{
	m_getNextEventStrategy_EClass->setInstanceClass(nullptr);
	m_getNextEventStrategy_EClass->setName("GetNextEventStrategy");
	m_getNextEventStrategy_EClass->setAbstract(true);
	m_getNextEventStrategy_EClass->setInterface(false);
	
	
	
	m_getNextEventStrategy_EOperation_retrieveNextEvent_ObjectActivation->setEType(getSignalInstance_EClass());
	m_getNextEventStrategy_EOperation_retrieveNextEvent_ObjectActivation->setName("retrieveNextEvent");
	m_getNextEventStrategy_EOperation_retrieveNextEvent_ObjectActivation->setLowerBound(1);
	m_getNextEventStrategy_EOperation_retrieveNextEvent_ObjectActivation->setUpperBound(1);
	m_getNextEventStrategy_EOperation_retrieveNextEvent_ObjectActivation->setUnique(true);
	m_getNextEventStrategy_EOperation_retrieveNextEvent_ObjectActivation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_getNextEventStrategy_EOperation_retrieveNextEvent_ObjectActivation);
		parameter->setName("objectActivation");
		parameter->setEType(getObjectActivation_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeInitialNodeActivationContent()
{
	m_initialNodeActivation_EClass->setInstanceClass(nullptr);
	m_initialNodeActivation_EClass->setName("InitialNodeActivation");
	m_initialNodeActivation_EClass->setAbstract(false);
	m_initialNodeActivation_EClass->setInterface(false);
	
	
	
	m_initialNodeActivation_EOperation_fire_Token->setEType(nullptr);
	m_initialNodeActivation_EOperation_fire_Token->setName("fire");
	m_initialNodeActivation_EOperation_fire_Token->setLowerBound(1);
	m_initialNodeActivation_EOperation_fire_Token->setUpperBound(1);
	m_initialNodeActivation_EOperation_fire_Token->setUnique(true);
	m_initialNodeActivation_EOperation_fire_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_initialNodeActivation_EOperation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeInputPinActivationContent()
{
	m_inputPinActivation_EClass->setInstanceClass(nullptr);
	m_inputPinActivation_EClass->setName("InputPinActivation");
	m_inputPinActivation_EClass->setAbstract(false);
	m_inputPinActivation_EClass->setInterface(false);
	
	
	
	m_inputPinActivation_EOperation_isReady->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_inputPinActivation_EOperation_isReady->setName("isReady");
	m_inputPinActivation_EOperation_isReady->setLowerBound(1);
	m_inputPinActivation_EOperation_isReady->setUpperBound(1);
	m_inputPinActivation_EOperation_isReady->setUnique(true);
	m_inputPinActivation_EOperation_isReady->setOrdered(false);
	
	
	m_inputPinActivation_EOperation_recieveOffer->setEType(nullptr);
	m_inputPinActivation_EOperation_recieveOffer->setName("recieveOffer");
	m_inputPinActivation_EOperation_recieveOffer->setLowerBound(1);
	m_inputPinActivation_EOperation_recieveOffer->setUpperBound(1);
	m_inputPinActivation_EOperation_recieveOffer->setUnique(true);
	m_inputPinActivation_EOperation_recieveOffer->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeInstanceValueEvaluationContent()
{
	m_instanceValueEvaluation_EClass->setInstanceClass(nullptr);
	m_instanceValueEvaluation_EClass->setName("InstanceValueEvaluation");
	m_instanceValueEvaluation_EClass->setAbstract(false);
	m_instanceValueEvaluation_EClass->setInterface(false);
	
	
	
	m_instanceValueEvaluation_EOperation_evaluate->setEType(getValue_EClass());
	m_instanceValueEvaluation_EOperation_evaluate->setName("evaluate");
	m_instanceValueEvaluation_EOperation_evaluate->setLowerBound(0);
	m_instanceValueEvaluation_EOperation_evaluate->setUpperBound(1);
	m_instanceValueEvaluation_EOperation_evaluate->setUnique(true);
	m_instanceValueEvaluation_EOperation_evaluate->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeIntegerValueContent()
{
	m_integerValue_EClass->setInstanceClass(nullptr);
	m_integerValue_EClass->setName("IntegerValue");
	m_integerValue_EClass->setAbstract(false);
	m_integerValue_EClass->setInterface(false);
	
	m_integerValue_EAttribute_value = getIntegerValue_EAttribute_value();
	m_integerValue_EAttribute_value->setName("value");
	m_integerValue_EAttribute_value->setEType(ecore::EcorePackage::eInstance()->getEInt_EDataType());
	m_integerValue_EAttribute_value->setLowerBound(1);
	m_integerValue_EAttribute_value->setUpperBound(1);
	m_integerValue_EAttribute_value->setTransient(false);
	m_integerValue_EAttribute_value->setVolatile(false);
	m_integerValue_EAttribute_value->setChangeable(true);
	m_integerValue_EAttribute_value->setUnsettable(false);
	m_integerValue_EAttribute_value->setUnique(true);
	m_integerValue_EAttribute_value->setDerived(false);
	m_integerValue_EAttribute_value->setOrdered(false);
	m_integerValue_EAttribute_value->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_integerValue_EAttribute_value->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	m_integerValue_EOperation_equals_Value->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_integerValue_EOperation_equals_Value->setName("equals");
	m_integerValue_EOperation_equals_Value->setLowerBound(1);
	m_integerValue_EOperation_equals_Value->setUpperBound(1);
	m_integerValue_EOperation_equals_Value->setUnique(true);
	m_integerValue_EOperation_equals_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_integerValue_EOperation_equals_Value);
		parameter->setName("otherValue");
		parameter->setEType(getValue_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_integerValue_EOperation_specify->setEType(uml::UmlPackage::eInstance()->getValueSpecification_EClass());
	m_integerValue_EOperation_specify->setName("specify");
	m_integerValue_EOperation_specify->setLowerBound(1);
	m_integerValue_EOperation_specify->setUpperBound(1);
	m_integerValue_EOperation_specify->setUnique(true);
	m_integerValue_EOperation_specify->setOrdered(false);
	
	
	m_integerValue_EOperation_toString->setEType(ecore::EcorePackage::eInstance()->getEString_EDataType());
	m_integerValue_EOperation_toString->setName("toString");
	m_integerValue_EOperation_toString->setLowerBound(1);
	m_integerValue_EOperation_toString->setUpperBound(1);
	m_integerValue_EOperation_toString->setUnique(true);
	m_integerValue_EOperation_toString->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeInvocationActionActivationContent()
{
	m_invocationActionActivation_EClass->setInstanceClass(nullptr);
	m_invocationActionActivation_EClass->setName("InvocationActionActivation");
	m_invocationActionActivation_EClass->setAbstract(true);
	m_invocationActionActivation_EClass->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeJoinNodeActivationContent()
{
	m_joinNodeActivation_EClass->setInstanceClass(nullptr);
	m_joinNodeActivation_EClass->setName("JoinNodeActivation");
	m_joinNodeActivation_EClass->setAbstract(false);
	m_joinNodeActivation_EClass->setInterface(false);
	
	
	
	m_joinNodeActivation_EOperation_isReady->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_joinNodeActivation_EOperation_isReady->setName("isReady");
	m_joinNodeActivation_EOperation_isReady->setLowerBound(1);
	m_joinNodeActivation_EOperation_isReady->setUpperBound(1);
	m_joinNodeActivation_EOperation_isReady->setUnique(true);
	m_joinNodeActivation_EOperation_isReady->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeLinkContent()
{
	m_link_EClass->setInstanceClass(nullptr);
	m_link_EClass->setName("Link");
	m_link_EClass->setAbstract(false);
	m_link_EClass->setInterface(false);
	
	
	m_link_EReference_type->setName("type");
	m_link_EReference_type->setEType(uml::UmlPackage::eInstance()->getAssociation_EClass());
	m_link_EReference_type->setLowerBound(0);
	m_link_EReference_type->setUpperBound(1);
	m_link_EReference_type->setTransient(false);
	m_link_EReference_type->setVolatile(false);
	m_link_EReference_type->setChangeable(true);
	m_link_EReference_type->setUnsettable(false);
	m_link_EReference_type->setUnique(true);
	m_link_EReference_type->setDerived(false);
	m_link_EReference_type->setOrdered(false);
	m_link_EReference_type->setContainment(false);
	m_link_EReference_type->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_link_EReference_type->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_link_EReference_type->setEOpposite(otherEnd);
	    }
	}
	
	m_link_EOperation_addTo_Locus->setEType(nullptr);
	m_link_EOperation_addTo_Locus->setName("addTo");
	m_link_EOperation_addTo_Locus->setLowerBound(0);
	m_link_EOperation_addTo_Locus->setUpperBound(1);
	m_link_EOperation_addTo_Locus->setUnique(true);
	m_link_EOperation_addTo_Locus->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_link_EOperation_addTo_Locus);
		parameter->setName("locus");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_link_EOperation_getOtherFeatureValues_ExtensionalValue_Property->setEType(getFeatureValue_EClass());
	m_link_EOperation_getOtherFeatureValues_ExtensionalValue_Property->setName("getOtherFeatureValues");
	m_link_EOperation_getOtherFeatureValues_ExtensionalValue_Property->setLowerBound(0);
	m_link_EOperation_getOtherFeatureValues_ExtensionalValue_Property->setUpperBound(-1);
	m_link_EOperation_getOtherFeatureValues_ExtensionalValue_Property->setUnique(true);
	m_link_EOperation_getOtherFeatureValues_ExtensionalValue_Property->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_link_EOperation_getOtherFeatureValues_ExtensionalValue_Property);
		parameter->setName("extent");
		parameter->setEType(getExtensionalValue_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_link_EOperation_getOtherFeatureValues_ExtensionalValue_Property);
		parameter->setName("end");
		parameter->setEType(uml::UmlPackage::eInstance()->getProperty_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_link_EOperation_getTypes->setEType(uml::UmlPackage::eInstance()->getClassifier_EClass());
	m_link_EOperation_getTypes->setName("getTypes");
	m_link_EOperation_getTypes->setLowerBound(0);
	m_link_EOperation_getTypes->setUpperBound(-1);
	m_link_EOperation_getTypes->setUnique(true);
	m_link_EOperation_getTypes->setOrdered(false);
	
	
	m_link_EOperation_isMatchingLink_ExtensionalValue_Property->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_link_EOperation_isMatchingLink_ExtensionalValue_Property->setName("isMatchingLink");
	m_link_EOperation_isMatchingLink_ExtensionalValue_Property->setLowerBound(0);
	m_link_EOperation_isMatchingLink_ExtensionalValue_Property->setUpperBound(1);
	m_link_EOperation_isMatchingLink_ExtensionalValue_Property->setUnique(true);
	m_link_EOperation_isMatchingLink_ExtensionalValue_Property->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_link_EOperation_isMatchingLink_ExtensionalValue_Property);
		parameter->setName("link");
		parameter->setEType(getExtensionalValue_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_link_EOperation_isMatchingLink_ExtensionalValue_Property);
		parameter->setName("end");
		parameter->setEType(uml::UmlPackage::eInstance()->getProperty_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeLinkActionActivationContent()
{
	m_linkActionActivation_EClass->setInstanceClass(nullptr);
	m_linkActionActivation_EClass->setName("LinkActionActivation");
	m_linkActionActivation_EClass->setAbstract(true);
	m_linkActionActivation_EClass->setInterface(false);
	
	
	
	m_linkActionActivation_EOperation_endMatchesEndData_Link_LinkEndData->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_linkActionActivation_EOperation_endMatchesEndData_Link_LinkEndData->setName("endMatchesEndData");
	m_linkActionActivation_EOperation_endMatchesEndData_Link_LinkEndData->setLowerBound(1);
	m_linkActionActivation_EOperation_endMatchesEndData_Link_LinkEndData->setUpperBound(1);
	m_linkActionActivation_EOperation_endMatchesEndData_Link_LinkEndData->setUnique(true);
	m_linkActionActivation_EOperation_endMatchesEndData_Link_LinkEndData->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_linkActionActivation_EOperation_endMatchesEndData_Link_LinkEndData);
		parameter->setName("link");
		parameter->setEType(getLink_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_linkActionActivation_EOperation_endMatchesEndData_Link_LinkEndData);
		parameter->setName("endData");
		parameter->setEType(uml::UmlPackage::eInstance()->getLinkEndData_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_linkActionActivation_EOperation_getAssociation->setEType(uml::UmlPackage::eInstance()->getAssociation_EClass());
	m_linkActionActivation_EOperation_getAssociation->setName("getAssociation");
	m_linkActionActivation_EOperation_getAssociation->setLowerBound(1);
	m_linkActionActivation_EOperation_getAssociation->setUpperBound(1);
	m_linkActionActivation_EOperation_getAssociation->setUnique(true);
	m_linkActionActivation_EOperation_getAssociation->setOrdered(false);
	
	
	m_linkActionActivation_EOperation_linkMatchesEndData_Link_LinkEndData->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_linkActionActivation_EOperation_linkMatchesEndData_Link_LinkEndData->setName("linkMatchesEndData");
	m_linkActionActivation_EOperation_linkMatchesEndData_Link_LinkEndData->setLowerBound(1);
	m_linkActionActivation_EOperation_linkMatchesEndData_Link_LinkEndData->setUpperBound(1);
	m_linkActionActivation_EOperation_linkMatchesEndData_Link_LinkEndData->setUnique(true);
	m_linkActionActivation_EOperation_linkMatchesEndData_Link_LinkEndData->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_linkActionActivation_EOperation_linkMatchesEndData_Link_LinkEndData);
		parameter->setName("link");
		parameter->setEType(getLink_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_linkActionActivation_EOperation_linkMatchesEndData_Link_LinkEndData);
		parameter->setName("endDataList");
		parameter->setEType(uml::UmlPackage::eInstance()->getLinkEndData_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeLiteralBooleanEvaluationContent()
{
	m_literalBooleanEvaluation_EClass->setInstanceClass(nullptr);
	m_literalBooleanEvaluation_EClass->setName("LiteralBooleanEvaluation");
	m_literalBooleanEvaluation_EClass->setAbstract(false);
	m_literalBooleanEvaluation_EClass->setInterface(false);
	
	
	
	m_literalBooleanEvaluation_EOperation_evaluate->setEType(getValue_EClass());
	m_literalBooleanEvaluation_EOperation_evaluate->setName("evaluate");
	m_literalBooleanEvaluation_EOperation_evaluate->setLowerBound(0);
	m_literalBooleanEvaluation_EOperation_evaluate->setUpperBound(1);
	m_literalBooleanEvaluation_EOperation_evaluate->setUnique(true);
	m_literalBooleanEvaluation_EOperation_evaluate->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeLiteralEvaluationContent()
{
	m_literalEvaluation_EClass->setInstanceClass(nullptr);
	m_literalEvaluation_EClass->setName("LiteralEvaluation");
	m_literalEvaluation_EClass->setAbstract(true);
	m_literalEvaluation_EClass->setInterface(false);
	
	
	
	m_literalEvaluation_EOperation_getType_EString->setEType(uml::UmlPackage::eInstance()->getPrimitiveType_EClass());
	m_literalEvaluation_EOperation_getType_EString->setName("getType");
	m_literalEvaluation_EOperation_getType_EString->setLowerBound(1);
	m_literalEvaluation_EOperation_getType_EString->setUpperBound(1);
	m_literalEvaluation_EOperation_getType_EString->setUnique(true);
	m_literalEvaluation_EOperation_getType_EString->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_literalEvaluation_EOperation_getType_EString);
		parameter->setName("builtInTypeName");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEString_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeLiteralIntegerEvaluationContent()
{
	m_literalIntegerEvaluation_EClass->setInstanceClass(nullptr);
	m_literalIntegerEvaluation_EClass->setName("LiteralIntegerEvaluation");
	m_literalIntegerEvaluation_EClass->setAbstract(false);
	m_literalIntegerEvaluation_EClass->setInterface(false);
	
	
	
	m_literalIntegerEvaluation_EOperation_evaluate->setEType(getValue_EClass());
	m_literalIntegerEvaluation_EOperation_evaluate->setName("evaluate");
	m_literalIntegerEvaluation_EOperation_evaluate->setLowerBound(0);
	m_literalIntegerEvaluation_EOperation_evaluate->setUpperBound(1);
	m_literalIntegerEvaluation_EOperation_evaluate->setUnique(true);
	m_literalIntegerEvaluation_EOperation_evaluate->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeLiteralNullEvaluationContent()
{
	m_literalNullEvaluation_EClass->setInstanceClass(nullptr);
	m_literalNullEvaluation_EClass->setName("LiteralNullEvaluation");
	m_literalNullEvaluation_EClass->setAbstract(false);
	m_literalNullEvaluation_EClass->setInterface(false);
	
	
	
	m_literalNullEvaluation_EOperation_evaluate->setEType(getValue_EClass());
	m_literalNullEvaluation_EOperation_evaluate->setName("evaluate");
	m_literalNullEvaluation_EOperation_evaluate->setLowerBound(0);
	m_literalNullEvaluation_EOperation_evaluate->setUpperBound(1);
	m_literalNullEvaluation_EOperation_evaluate->setUnique(true);
	m_literalNullEvaluation_EOperation_evaluate->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeLiteralRealEvaluationContent()
{
	m_literalRealEvaluation_EClass->setInstanceClass(nullptr);
	m_literalRealEvaluation_EClass->setName("LiteralRealEvaluation");
	m_literalRealEvaluation_EClass->setAbstract(false);
	m_literalRealEvaluation_EClass->setInterface(false);
	
	
	
	m_literalRealEvaluation_EOperation_evaluate->setEType(getValue_EClass());
	m_literalRealEvaluation_EOperation_evaluate->setName("evaluate");
	m_literalRealEvaluation_EOperation_evaluate->setLowerBound(0);
	m_literalRealEvaluation_EOperation_evaluate->setUpperBound(1);
	m_literalRealEvaluation_EOperation_evaluate->setUnique(true);
	m_literalRealEvaluation_EOperation_evaluate->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeLiteralStringEvaluationContent()
{
	m_literalStringEvaluation_EClass->setInstanceClass(nullptr);
	m_literalStringEvaluation_EClass->setName("LiteralStringEvaluation");
	m_literalStringEvaluation_EClass->setAbstract(false);
	m_literalStringEvaluation_EClass->setInterface(false);
	
	
	
	m_literalStringEvaluation_EOperation_evaluate->setEType(getValue_EClass());
	m_literalStringEvaluation_EOperation_evaluate->setName("evaluate");
	m_literalStringEvaluation_EOperation_evaluate->setLowerBound(0);
	m_literalStringEvaluation_EOperation_evaluate->setUpperBound(1);
	m_literalStringEvaluation_EOperation_evaluate->setUnique(true);
	m_literalStringEvaluation_EOperation_evaluate->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeLiteralUnlimitedNaturalEvaluationContent()
{
	m_literalUnlimitedNaturalEvaluation_EClass->setInstanceClass(nullptr);
	m_literalUnlimitedNaturalEvaluation_EClass->setName("LiteralUnlimitedNaturalEvaluation");
	m_literalUnlimitedNaturalEvaluation_EClass->setAbstract(false);
	m_literalUnlimitedNaturalEvaluation_EClass->setInterface(false);
	
	
	
	m_literalUnlimitedNaturalEvaluation_EOperation_evaluate->setEType(getValue_EClass());
	m_literalUnlimitedNaturalEvaluation_EOperation_evaluate->setName("evaluate");
	m_literalUnlimitedNaturalEvaluation_EOperation_evaluate->setLowerBound(0);
	m_literalUnlimitedNaturalEvaluation_EOperation_evaluate->setUpperBound(1);
	m_literalUnlimitedNaturalEvaluation_EOperation_evaluate->setUnique(true);
	m_literalUnlimitedNaturalEvaluation_EOperation_evaluate->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeLocusContent()
{
	m_locus_EClass->setInstanceClass(nullptr);
	m_locus_EClass->setName("Locus");
	m_locus_EClass->setAbstract(false);
	m_locus_EClass->setInterface(false);
	
	
	m_locus_EReference_executor->setName("executor");
	m_locus_EReference_executor->setEType(getExecutor_EClass());
	m_locus_EReference_executor->setLowerBound(0);
	m_locus_EReference_executor->setUpperBound(1);
	m_locus_EReference_executor->setTransient(false);
	m_locus_EReference_executor->setVolatile(false);
	m_locus_EReference_executor->setChangeable(true);
	m_locus_EReference_executor->setUnsettable(false);
	m_locus_EReference_executor->setUnique(true);
	m_locus_EReference_executor->setDerived(false);
	m_locus_EReference_executor->setOrdered(false);
	m_locus_EReference_executor->setContainment(true);
	m_locus_EReference_executor->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_locus_EReference_executor->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_locus_EReference_executor->setEOpposite(otherEnd);
	    }
	}
	m_locus_EReference_extensionalValues->setName("extensionalValues");
	m_locus_EReference_extensionalValues->setEType(getExtensionalValue_EClass());
	m_locus_EReference_extensionalValues->setLowerBound(0);
	m_locus_EReference_extensionalValues->setUpperBound(-1);
	m_locus_EReference_extensionalValues->setTransient(false);
	m_locus_EReference_extensionalValues->setVolatile(false);
	m_locus_EReference_extensionalValues->setChangeable(true);
	m_locus_EReference_extensionalValues->setUnsettable(false);
	m_locus_EReference_extensionalValues->setUnique(true);
	m_locus_EReference_extensionalValues->setDerived(false);
	m_locus_EReference_extensionalValues->setOrdered(false);
	m_locus_EReference_extensionalValues->setContainment(true);
	m_locus_EReference_extensionalValues->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_locus_EReference_extensionalValues->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_locus_EReference_extensionalValues->setEOpposite(otherEnd);
	    }
	}
	m_locus_EReference_factory->setName("factory");
	m_locus_EReference_factory->setEType(getExecutionFactory_EClass());
	m_locus_EReference_factory->setLowerBound(1);
	m_locus_EReference_factory->setUpperBound(1);
	m_locus_EReference_factory->setTransient(false);
	m_locus_EReference_factory->setVolatile(false);
	m_locus_EReference_factory->setChangeable(true);
	m_locus_EReference_factory->setUnsettable(false);
	m_locus_EReference_factory->setUnique(true);
	m_locus_EReference_factory->setDerived(false);
	m_locus_EReference_factory->setOrdered(true);
	m_locus_EReference_factory->setContainment(true);
	m_locus_EReference_factory->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_locus_EReference_factory->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getExecutionFactory_EReference_locus();
		if (otherEnd != nullptr)
	    {
	   		m_locus_EReference_factory->setEOpposite(otherEnd);
	    }
	}
	
	m_locus_EOperation_add_ExtensionalValue->setEType(nullptr);
	m_locus_EOperation_add_ExtensionalValue->setName("add");
	m_locus_EOperation_add_ExtensionalValue->setLowerBound(1);
	m_locus_EOperation_add_ExtensionalValue->setUpperBound(1);
	m_locus_EOperation_add_ExtensionalValue->setUnique(true);
	m_locus_EOperation_add_ExtensionalValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_locus_EOperation_add_ExtensionalValue);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_locus_EOperation_assignExecutor_Executor->setEType(nullptr);
	m_locus_EOperation_assignExecutor_Executor->setName("assignExecutor");
	m_locus_EOperation_assignExecutor_Executor->setLowerBound(1);
	m_locus_EOperation_assignExecutor_Executor->setUpperBound(1);
	m_locus_EOperation_assignExecutor_Executor->setUnique(true);
	m_locus_EOperation_assignExecutor_Executor->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_locus_EOperation_assignExecutor_Executor);
		parameter->setName("executor");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_locus_EOperation_assignFactory_ExecutionFactory->setEType(nullptr);
	m_locus_EOperation_assignFactory_ExecutionFactory->setName("assignFactory");
	m_locus_EOperation_assignFactory_ExecutionFactory->setLowerBound(1);
	m_locus_EOperation_assignFactory_ExecutionFactory->setUpperBound(1);
	m_locus_EOperation_assignFactory_ExecutionFactory->setUnique(true);
	m_locus_EOperation_assignFactory_ExecutionFactory->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_locus_EOperation_assignFactory_ExecutionFactory);
		parameter->setName("factory");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_locus_EOperation_conforms_Classifier_Classifier->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_locus_EOperation_conforms_Classifier_Classifier->setName("conforms");
	m_locus_EOperation_conforms_Classifier_Classifier->setLowerBound(1);
	m_locus_EOperation_conforms_Classifier_Classifier->setUpperBound(1);
	m_locus_EOperation_conforms_Classifier_Classifier->setUnique(true);
	m_locus_EOperation_conforms_Classifier_Classifier->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_locus_EOperation_conforms_Classifier_Classifier);
		parameter->setName("type");
		parameter->setEType(uml::UmlPackage::eInstance()->getClassifier_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_locus_EOperation_conforms_Classifier_Classifier);
		parameter->setName("classifier");
		parameter->setEType(uml::UmlPackage::eInstance()->getClassifier_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_locus_EOperation_instantiate_Class->setEType(getObject_EClass());
	m_locus_EOperation_instantiate_Class->setName("instantiate");
	m_locus_EOperation_instantiate_Class->setLowerBound(1);
	m_locus_EOperation_instantiate_Class->setUpperBound(1);
	m_locus_EOperation_instantiate_Class->setUnique(true);
	m_locus_EOperation_instantiate_Class->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_locus_EOperation_instantiate_Class);
		parameter->setName("type");
		parameter->setEType(uml::UmlPackage::eInstance()->getClass_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_locus_EOperation_remove_ExtensionalValue->setEType(nullptr);
	m_locus_EOperation_remove_ExtensionalValue->setName("remove");
	m_locus_EOperation_remove_ExtensionalValue->setLowerBound(1);
	m_locus_EOperation_remove_ExtensionalValue->setUpperBound(1);
	m_locus_EOperation_remove_ExtensionalValue->setUnique(true);
	m_locus_EOperation_remove_ExtensionalValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_locus_EOperation_remove_ExtensionalValue);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_locus_EOperation_retrieveExtent_Classifier->setEType(getExtensionalValue_EClass());
	m_locus_EOperation_retrieveExtent_Classifier->setName("retrieveExtent");
	m_locus_EOperation_retrieveExtent_Classifier->setLowerBound(0);
	m_locus_EOperation_retrieveExtent_Classifier->setUpperBound(-1);
	m_locus_EOperation_retrieveExtent_Classifier->setUnique(true);
	m_locus_EOperation_retrieveExtent_Classifier->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_locus_EOperation_retrieveExtent_Classifier);
		parameter->setName("classifier");
		parameter->setEType(uml::UmlPackage::eInstance()->getClassifier_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeLoopNodeActivationContent()
{
	m_loopNodeActivation_EClass->setInstanceClass(nullptr);
	m_loopNodeActivation_EClass->setName("LoopNodeActivation");
	m_loopNodeActivation_EClass->setAbstract(false);
	m_loopNodeActivation_EClass->setInterface(false);
	
	
	m_loopNodeActivation_EReference_bodyOutputLists->setName("bodyOutputLists");
	m_loopNodeActivation_EReference_bodyOutputLists->setEType(getValues_EClass());
	m_loopNodeActivation_EReference_bodyOutputLists->setLowerBound(0);
	m_loopNodeActivation_EReference_bodyOutputLists->setUpperBound(-1);
	m_loopNodeActivation_EReference_bodyOutputLists->setTransient(false);
	m_loopNodeActivation_EReference_bodyOutputLists->setVolatile(false);
	m_loopNodeActivation_EReference_bodyOutputLists->setChangeable(true);
	m_loopNodeActivation_EReference_bodyOutputLists->setUnsettable(false);
	m_loopNodeActivation_EReference_bodyOutputLists->setUnique(true);
	m_loopNodeActivation_EReference_bodyOutputLists->setDerived(false);
	m_loopNodeActivation_EReference_bodyOutputLists->setOrdered(false);
	m_loopNodeActivation_EReference_bodyOutputLists->setContainment(true);
	m_loopNodeActivation_EReference_bodyOutputLists->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_loopNodeActivation_EReference_bodyOutputLists->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_loopNodeActivation_EReference_bodyOutputLists->setEOpposite(otherEnd);
	    }
	}
	
	m_loopNodeActivation_EOperation_makeLoopVariableList->setEType(uml::UmlPackage::eInstance()->getActivityNode_EClass());
	m_loopNodeActivation_EOperation_makeLoopVariableList->setName("makeLoopVariableList");
	m_loopNodeActivation_EOperation_makeLoopVariableList->setLowerBound(1);
	m_loopNodeActivation_EOperation_makeLoopVariableList->setUpperBound(1);
	m_loopNodeActivation_EOperation_makeLoopVariableList->setUnique(true);
	m_loopNodeActivation_EOperation_makeLoopVariableList->setOrdered(false);
	
	
	m_loopNodeActivation_EOperation_runBody->setEType(nullptr);
	m_loopNodeActivation_EOperation_runBody->setName("runBody");
	m_loopNodeActivation_EOperation_runBody->setLowerBound(1);
	m_loopNodeActivation_EOperation_runBody->setUpperBound(1);
	m_loopNodeActivation_EOperation_runBody->setUnique(true);
	m_loopNodeActivation_EOperation_runBody->setOrdered(false);
	
	
	m_loopNodeActivation_EOperation_runLoopVariables->setEType(nullptr);
	m_loopNodeActivation_EOperation_runLoopVariables->setName("runLoopVariables");
	m_loopNodeActivation_EOperation_runLoopVariables->setLowerBound(1);
	m_loopNodeActivation_EOperation_runLoopVariables->setUpperBound(1);
	m_loopNodeActivation_EOperation_runLoopVariables->setUnique(true);
	m_loopNodeActivation_EOperation_runLoopVariables->setOrdered(false);
	
	
	m_loopNodeActivation_EOperation_runTest->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_loopNodeActivation_EOperation_runTest->setName("runTest");
	m_loopNodeActivation_EOperation_runTest->setLowerBound(1);
	m_loopNodeActivation_EOperation_runTest->setUpperBound(1);
	m_loopNodeActivation_EOperation_runTest->setUnique(true);
	m_loopNodeActivation_EOperation_runTest->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeMergeNodeActivationContent()
{
	m_mergeNodeActivation_EClass->setInstanceClass(nullptr);
	m_mergeNodeActivation_EClass->setName("MergeNodeActivation");
	m_mergeNodeActivation_EClass->setAbstract(false);
	m_mergeNodeActivation_EClass->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeObjectContent()
{
	m_object_EClass->setInstanceClass(nullptr);
	m_object_EClass->setName("Object");
	m_object_EClass->setAbstract(false);
	m_object_EClass->setInterface(false);
	
	
	m_object_EReference_objectActivation->setName("objectActivation");
	m_object_EReference_objectActivation->setEType(getObjectActivation_EClass());
	m_object_EReference_objectActivation->setLowerBound(0);
	m_object_EReference_objectActivation->setUpperBound(1);
	m_object_EReference_objectActivation->setTransient(false);
	m_object_EReference_objectActivation->setVolatile(false);
	m_object_EReference_objectActivation->setChangeable(true);
	m_object_EReference_objectActivation->setUnsettable(false);
	m_object_EReference_objectActivation->setUnique(true);
	m_object_EReference_objectActivation->setDerived(false);
	m_object_EReference_objectActivation->setOrdered(false);
	m_object_EReference_objectActivation->setContainment(true);
	m_object_EReference_objectActivation->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_object_EReference_objectActivation->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_object_EReference_objectActivation->setEOpposite(otherEnd);
	    }
	}
	m_object_EReference_types->setName("types");
	m_object_EReference_types->setEType(uml::UmlPackage::eInstance()->getClassifier_EClass());
	m_object_EReference_types->setLowerBound(0);
	m_object_EReference_types->setUpperBound(-1);
	m_object_EReference_types->setTransient(false);
	m_object_EReference_types->setVolatile(false);
	m_object_EReference_types->setChangeable(true);
	m_object_EReference_types->setUnsettable(false);
	m_object_EReference_types->setUnique(true);
	m_object_EReference_types->setDerived(false);
	m_object_EReference_types->setOrdered(false);
	m_object_EReference_types->setContainment(false);
	m_object_EReference_types->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_object_EReference_types->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_object_EReference_types->setEOpposite(otherEnd);
	    }
	}
	
	m_object_EOperation__register_EventAccepter->setEType(nullptr);
	m_object_EOperation__register_EventAccepter->setName("_register");
	m_object_EOperation__register_EventAccepter->setLowerBound(1);
	m_object_EOperation__register_EventAccepter->setUpperBound(1);
	m_object_EOperation__register_EventAccepter->setUnique(true);
	m_object_EOperation__register_EventAccepter->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_object_EOperation__register_EventAccepter);
		parameter->setName("accepter");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_object_EOperation_destroy->setEType(nullptr);
	m_object_EOperation_destroy->setName("destroy");
	m_object_EOperation_destroy->setLowerBound(1);
	m_object_EOperation_destroy->setUpperBound(1);
	m_object_EOperation_destroy->setUnique(true);
	m_object_EOperation_destroy->setOrdered(false);
	
	
	m_object_EOperation_dispatch_Operation->setEType(getExecution_EClass());
	m_object_EOperation_dispatch_Operation->setName("dispatch");
	m_object_EOperation_dispatch_Operation->setLowerBound(1);
	m_object_EOperation_dispatch_Operation->setUpperBound(1);
	m_object_EOperation_dispatch_Operation->setUnique(true);
	m_object_EOperation_dispatch_Operation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_object_EOperation_dispatch_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::UmlPackage::eInstance()->getOperation_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_object_EOperation_new_->setEType(getValue_EClass());
	m_object_EOperation_new_->setName("new_");
	m_object_EOperation_new_->setLowerBound(1);
	m_object_EOperation_new_->setUpperBound(1);
	m_object_EOperation_new_->setUnique(true);
	m_object_EOperation_new_->setOrdered(false);
	
	
	m_object_EOperation_send_SignalInstance->setEType(nullptr);
	m_object_EOperation_send_SignalInstance->setName("send");
	m_object_EOperation_send_SignalInstance->setLowerBound(1);
	m_object_EOperation_send_SignalInstance->setUpperBound(1);
	m_object_EOperation_send_SignalInstance->setUnique(true);
	m_object_EOperation_send_SignalInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_object_EOperation_send_SignalInstance);
		parameter->setName("signalInstance");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_object_EOperation_startBehavior_Class_ParameterValue->setEType(nullptr);
	m_object_EOperation_startBehavior_Class_ParameterValue->setName("startBehavior");
	m_object_EOperation_startBehavior_Class_ParameterValue->setLowerBound(1);
	m_object_EOperation_startBehavior_Class_ParameterValue->setUpperBound(1);
	m_object_EOperation_startBehavior_Class_ParameterValue->setUnique(true);
	m_object_EOperation_startBehavior_Class_ParameterValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_object_EOperation_startBehavior_Class_ParameterValue);
		parameter->setName("classifier");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_object_EOperation_startBehavior_Class_ParameterValue);
		parameter->setName("inputs");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_object_EOperation_unregister_EventAccepter->setEType(nullptr);
	m_object_EOperation_unregister_EventAccepter->setName("unregister");
	m_object_EOperation_unregister_EventAccepter->setLowerBound(1);
	m_object_EOperation_unregister_EventAccepter->setUpperBound(1);
	m_object_EOperation_unregister_EventAccepter->setUnique(true);
	m_object_EOperation_unregister_EventAccepter->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_object_EOperation_unregister_EventAccepter);
		parameter->setName("accepter");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeObjectActivationContent()
{
	m_objectActivation_EClass->setInstanceClass(nullptr);
	m_objectActivation_EClass->setName("ObjectActivation");
	m_objectActivation_EClass->setAbstract(false);
	m_objectActivation_EClass->setInterface(false);
	
	
	m_objectActivation_EReference_classifierBehaviorExecutions->setName("classifierBehaviorExecutions");
	m_objectActivation_EReference_classifierBehaviorExecutions->setEType(getClassifierBehaviorExecution_EClass());
	m_objectActivation_EReference_classifierBehaviorExecutions->setLowerBound(0);
	m_objectActivation_EReference_classifierBehaviorExecutions->setUpperBound(-1);
	m_objectActivation_EReference_classifierBehaviorExecutions->setTransient(false);
	m_objectActivation_EReference_classifierBehaviorExecutions->setVolatile(false);
	m_objectActivation_EReference_classifierBehaviorExecutions->setChangeable(true);
	m_objectActivation_EReference_classifierBehaviorExecutions->setUnsettable(false);
	m_objectActivation_EReference_classifierBehaviorExecutions->setUnique(true);
	m_objectActivation_EReference_classifierBehaviorExecutions->setDerived(false);
	m_objectActivation_EReference_classifierBehaviorExecutions->setOrdered(false);
	m_objectActivation_EReference_classifierBehaviorExecutions->setContainment(true);
	m_objectActivation_EReference_classifierBehaviorExecutions->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_objectActivation_EReference_classifierBehaviorExecutions->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_objectActivation_EReference_classifierBehaviorExecutions->setEOpposite(otherEnd);
	    }
	}
	m_objectActivation_EReference_eventPool->setName("eventPool");
	m_objectActivation_EReference_eventPool->setEType(getSignalInstance_EClass());
	m_objectActivation_EReference_eventPool->setLowerBound(0);
	m_objectActivation_EReference_eventPool->setUpperBound(-1);
	m_objectActivation_EReference_eventPool->setTransient(false);
	m_objectActivation_EReference_eventPool->setVolatile(false);
	m_objectActivation_EReference_eventPool->setChangeable(true);
	m_objectActivation_EReference_eventPool->setUnsettable(false);
	m_objectActivation_EReference_eventPool->setUnique(true);
	m_objectActivation_EReference_eventPool->setDerived(false);
	m_objectActivation_EReference_eventPool->setOrdered(false);
	m_objectActivation_EReference_eventPool->setContainment(true);
	m_objectActivation_EReference_eventPool->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_objectActivation_EReference_eventPool->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_objectActivation_EReference_eventPool->setEOpposite(otherEnd);
	    }
	}
	m_objectActivation_EReference_object->setName("object");
	m_objectActivation_EReference_object->setEType(getObject_EClass());
	m_objectActivation_EReference_object->setLowerBound(1);
	m_objectActivation_EReference_object->setUpperBound(1);
	m_objectActivation_EReference_object->setTransient(false);
	m_objectActivation_EReference_object->setVolatile(false);
	m_objectActivation_EReference_object->setChangeable(true);
	m_objectActivation_EReference_object->setUnsettable(false);
	m_objectActivation_EReference_object->setUnique(true);
	m_objectActivation_EReference_object->setDerived(false);
	m_objectActivation_EReference_object->setOrdered(false);
	m_objectActivation_EReference_object->setContainment(false);
	m_objectActivation_EReference_object->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_objectActivation_EReference_object->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_objectActivation_EReference_object->setEOpposite(otherEnd);
	    }
	}
	m_objectActivation_EReference_waitingEventAccepters->setName("waitingEventAccepters");
	m_objectActivation_EReference_waitingEventAccepters->setEType(getEventAccepter_EClass());
	m_objectActivation_EReference_waitingEventAccepters->setLowerBound(0);
	m_objectActivation_EReference_waitingEventAccepters->setUpperBound(-1);
	m_objectActivation_EReference_waitingEventAccepters->setTransient(false);
	m_objectActivation_EReference_waitingEventAccepters->setVolatile(false);
	m_objectActivation_EReference_waitingEventAccepters->setChangeable(true);
	m_objectActivation_EReference_waitingEventAccepters->setUnsettable(false);
	m_objectActivation_EReference_waitingEventAccepters->setUnique(true);
	m_objectActivation_EReference_waitingEventAccepters->setDerived(false);
	m_objectActivation_EReference_waitingEventAccepters->setOrdered(false);
	m_objectActivation_EReference_waitingEventAccepters->setContainment(false);
	m_objectActivation_EReference_waitingEventAccepters->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_objectActivation_EReference_waitingEventAccepters->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_objectActivation_EReference_waitingEventAccepters->setEOpposite(otherEnd);
	    }
	}
	
	m_objectActivation_EOperation__register_EventAccepter->setEType(nullptr);
	m_objectActivation_EOperation__register_EventAccepter->setName("_register");
	m_objectActivation_EOperation__register_EventAccepter->setLowerBound(1);
	m_objectActivation_EOperation__register_EventAccepter->setUpperBound(1);
	m_objectActivation_EOperation__register_EventAccepter->setUnique(true);
	m_objectActivation_EOperation__register_EventAccepter->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_objectActivation_EOperation__register_EventAccepter);
		parameter->setName("accepter");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_objectActivation_EOperation__send_EJavaObject->setEType(nullptr);
	m_objectActivation_EOperation__send_EJavaObject->setName("_send");
	m_objectActivation_EOperation__send_EJavaObject->setLowerBound(1);
	m_objectActivation_EOperation__send_EJavaObject->setUpperBound(1);
	m_objectActivation_EOperation__send_EJavaObject->setUnique(true);
	m_objectActivation_EOperation__send_EJavaObject->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_objectActivation_EOperation__send_EJavaObject);
		parameter->setName("signal");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_objectActivation_EOperation__startObjectBehavior->setEType(nullptr);
	m_objectActivation_EOperation__startObjectBehavior->setName("_startObjectBehavior");
	m_objectActivation_EOperation__startObjectBehavior->setLowerBound(1);
	m_objectActivation_EOperation__startObjectBehavior->setUpperBound(1);
	m_objectActivation_EOperation__startObjectBehavior->setUnique(true);
	m_objectActivation_EOperation__startObjectBehavior->setOrdered(false);
	
	
	m_objectActivation_EOperation_dispatchNextEvent->setEType(nullptr);
	m_objectActivation_EOperation_dispatchNextEvent->setName("dispatchNextEvent");
	m_objectActivation_EOperation_dispatchNextEvent->setLowerBound(1);
	m_objectActivation_EOperation_dispatchNextEvent->setUpperBound(1);
	m_objectActivation_EOperation_dispatchNextEvent->setUnique(true);
	m_objectActivation_EOperation_dispatchNextEvent->setOrdered(false);
	
	
	m_objectActivation_EOperation_retrieveNextEvent->setEType(getSignalInstance_EClass());
	m_objectActivation_EOperation_retrieveNextEvent->setName("retrieveNextEvent");
	m_objectActivation_EOperation_retrieveNextEvent->setLowerBound(1);
	m_objectActivation_EOperation_retrieveNextEvent->setUpperBound(1);
	m_objectActivation_EOperation_retrieveNextEvent->setUnique(true);
	m_objectActivation_EOperation_retrieveNextEvent->setOrdered(false);
	
	
	m_objectActivation_EOperation_send_SignalInstance->setEType(nullptr);
	m_objectActivation_EOperation_send_SignalInstance->setName("send");
	m_objectActivation_EOperation_send_SignalInstance->setLowerBound(1);
	m_objectActivation_EOperation_send_SignalInstance->setUpperBound(1);
	m_objectActivation_EOperation_send_SignalInstance->setUnique(true);
	m_objectActivation_EOperation_send_SignalInstance->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_objectActivation_EOperation_send_SignalInstance);
		parameter->setName("signalInstance");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_objectActivation_EOperation_startBehavior_Class_ParameterValue->setEType(nullptr);
	m_objectActivation_EOperation_startBehavior_Class_ParameterValue->setName("startBehavior");
	m_objectActivation_EOperation_startBehavior_Class_ParameterValue->setLowerBound(1);
	m_objectActivation_EOperation_startBehavior_Class_ParameterValue->setUpperBound(1);
	m_objectActivation_EOperation_startBehavior_Class_ParameterValue->setUnique(true);
	m_objectActivation_EOperation_startBehavior_Class_ParameterValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_objectActivation_EOperation_startBehavior_Class_ParameterValue);
		parameter->setName("classifier");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_objectActivation_EOperation_startBehavior_Class_ParameterValue);
		parameter->setName("inputs");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_objectActivation_EOperation_stop->setEType(nullptr);
	m_objectActivation_EOperation_stop->setName("stop");
	m_objectActivation_EOperation_stop->setLowerBound(1);
	m_objectActivation_EOperation_stop->setUpperBound(1);
	m_objectActivation_EOperation_stop->setUnique(true);
	m_objectActivation_EOperation_stop->setOrdered(false);
	
	
	m_objectActivation_EOperation_unregister_EventAccepter->setEType(nullptr);
	m_objectActivation_EOperation_unregister_EventAccepter->setName("unregister");
	m_objectActivation_EOperation_unregister_EventAccepter->setLowerBound(1);
	m_objectActivation_EOperation_unregister_EventAccepter->setUpperBound(1);
	m_objectActivation_EOperation_unregister_EventAccepter->setUnique(true);
	m_objectActivation_EOperation_unregister_EventAccepter->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_objectActivation_EOperation_unregister_EventAccepter);
		parameter->setName("accepter");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeObjectNodeActivationContent()
{
	m_objectNodeActivation_EClass->setInstanceClass(nullptr);
	m_objectNodeActivation_EClass->setName("ObjectNodeActivation");
	m_objectNodeActivation_EClass->setAbstract(true);
	m_objectNodeActivation_EClass->setInterface(false);
	
	m_objectNodeActivation_EAttribute_offeredTokenCount = getObjectNodeActivation_EAttribute_offeredTokenCount();
	m_objectNodeActivation_EAttribute_offeredTokenCount->setName("offeredTokenCount");
	m_objectNodeActivation_EAttribute_offeredTokenCount->setEType(ecore::EcorePackage::eInstance()->getEInt_EDataType());
	m_objectNodeActivation_EAttribute_offeredTokenCount->setLowerBound(1);
	m_objectNodeActivation_EAttribute_offeredTokenCount->setUpperBound(1);
	m_objectNodeActivation_EAttribute_offeredTokenCount->setTransient(false);
	m_objectNodeActivation_EAttribute_offeredTokenCount->setVolatile(false);
	m_objectNodeActivation_EAttribute_offeredTokenCount->setChangeable(true);
	m_objectNodeActivation_EAttribute_offeredTokenCount->setUnsettable(false);
	m_objectNodeActivation_EAttribute_offeredTokenCount->setUnique(true);
	m_objectNodeActivation_EAttribute_offeredTokenCount->setDerived(false);
	m_objectNodeActivation_EAttribute_offeredTokenCount->setOrdered(false);
	m_objectNodeActivation_EAttribute_offeredTokenCount->setID(false);
	{
		std::string defaultValue = "0";
		if (!defaultValue.empty())
		{
		   m_objectNodeActivation_EAttribute_offeredTokenCount->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	m_objectNodeActivation_EOperation_addToken_Token->setEType(nullptr);
	m_objectNodeActivation_EOperation_addToken_Token->setName("addToken");
	m_objectNodeActivation_EOperation_addToken_Token->setLowerBound(1);
	m_objectNodeActivation_EOperation_addToken_Token->setUpperBound(1);
	m_objectNodeActivation_EOperation_addToken_Token->setUnique(true);
	m_objectNodeActivation_EOperation_addToken_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_objectNodeActivation_EOperation_addToken_Token);
		parameter->setName("token");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_objectNodeActivation_EOperation_clearTokens->setEType(nullptr);
	m_objectNodeActivation_EOperation_clearTokens->setName("clearTokens");
	m_objectNodeActivation_EOperation_clearTokens->setLowerBound(1);
	m_objectNodeActivation_EOperation_clearTokens->setUpperBound(1);
	m_objectNodeActivation_EOperation_clearTokens->setUnique(true);
	m_objectNodeActivation_EOperation_clearTokens->setOrdered(false);
	
	
	m_objectNodeActivation_EOperation_countOfferedValues->setEType(ecore::EcorePackage::eInstance()->getEInt_EDataType());
	m_objectNodeActivation_EOperation_countOfferedValues->setName("countOfferedValues");
	m_objectNodeActivation_EOperation_countOfferedValues->setLowerBound(1);
	m_objectNodeActivation_EOperation_countOfferedValues->setUpperBound(1);
	m_objectNodeActivation_EOperation_countOfferedValues->setUnique(true);
	m_objectNodeActivation_EOperation_countOfferedValues->setOrdered(false);
	
	
	m_objectNodeActivation_EOperation_countUnofferedTokens->setEType(ecore::EcorePackage::eInstance()->getEInt_EDataType());
	m_objectNodeActivation_EOperation_countUnofferedTokens->setName("countUnofferedTokens");
	m_objectNodeActivation_EOperation_countUnofferedTokens->setLowerBound(1);
	m_objectNodeActivation_EOperation_countUnofferedTokens->setUpperBound(1);
	m_objectNodeActivation_EOperation_countUnofferedTokens->setUnique(true);
	m_objectNodeActivation_EOperation_countUnofferedTokens->setOrdered(false);
	
	
	m_objectNodeActivation_EOperation_getUnofferedTokens->setEType(getToken_EClass());
	m_objectNodeActivation_EOperation_getUnofferedTokens->setName("getUnofferedTokens");
	m_objectNodeActivation_EOperation_getUnofferedTokens->setLowerBound(0);
	m_objectNodeActivation_EOperation_getUnofferedTokens->setUpperBound(-1);
	m_objectNodeActivation_EOperation_getUnofferedTokens->setUnique(true);
	m_objectNodeActivation_EOperation_getUnofferedTokens->setOrdered(false);
	
	
	m_objectNodeActivation_EOperation_removeToken_Token->setEType(ecore::EcorePackage::eInstance()->getEInt_EDataType());
	m_objectNodeActivation_EOperation_removeToken_Token->setName("removeToken");
	m_objectNodeActivation_EOperation_removeToken_Token->setLowerBound(1);
	m_objectNodeActivation_EOperation_removeToken_Token->setUpperBound(1);
	m_objectNodeActivation_EOperation_removeToken_Token->setUnique(true);
	m_objectNodeActivation_EOperation_removeToken_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_objectNodeActivation_EOperation_removeToken_Token);
		parameter->setName("token");
		parameter->setEType(getToken_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_objectNodeActivation_EOperation_run->setEType(nullptr);
	m_objectNodeActivation_EOperation_run->setName("run");
	m_objectNodeActivation_EOperation_run->setLowerBound(1);
	m_objectNodeActivation_EOperation_run->setUpperBound(1);
	m_objectNodeActivation_EOperation_run->setUnique(true);
	m_objectNodeActivation_EOperation_run->setOrdered(false);
	
	
	m_objectNodeActivation_EOperation_sendOffers_Token->setEType(nullptr);
	m_objectNodeActivation_EOperation_sendOffers_Token->setName("sendOffers");
	m_objectNodeActivation_EOperation_sendOffers_Token->setLowerBound(0);
	m_objectNodeActivation_EOperation_sendOffers_Token->setUpperBound(1);
	m_objectNodeActivation_EOperation_sendOffers_Token->setUnique(true);
	m_objectNodeActivation_EOperation_sendOffers_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_objectNodeActivation_EOperation_sendOffers_Token);
		parameter->setName("tokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_objectNodeActivation_EOperation_sendUnofferedTokens->setEType(nullptr);
	m_objectNodeActivation_EOperation_sendUnofferedTokens->setName("sendUnofferedTokens");
	m_objectNodeActivation_EOperation_sendUnofferedTokens->setLowerBound(1);
	m_objectNodeActivation_EOperation_sendUnofferedTokens->setUpperBound(1);
	m_objectNodeActivation_EOperation_sendUnofferedTokens->setUnique(true);
	m_objectNodeActivation_EOperation_sendUnofferedTokens->setOrdered(false);
	
	
	m_objectNodeActivation_EOperation_takeUnofferedTokens->setEType(getToken_EClass());
	m_objectNodeActivation_EOperation_takeUnofferedTokens->setName("takeUnofferedTokens");
	m_objectNodeActivation_EOperation_takeUnofferedTokens->setLowerBound(0);
	m_objectNodeActivation_EOperation_takeUnofferedTokens->setUpperBound(-1);
	m_objectNodeActivation_EOperation_takeUnofferedTokens->setUnique(true);
	m_objectNodeActivation_EOperation_takeUnofferedTokens->setOrdered(false);
	
	
	m_objectNodeActivation_EOperation_terminate->setEType(nullptr);
	m_objectNodeActivation_EOperation_terminate->setName("terminate");
	m_objectNodeActivation_EOperation_terminate->setLowerBound(1);
	m_objectNodeActivation_EOperation_terminate->setUpperBound(1);
	m_objectNodeActivation_EOperation_terminate->setUnique(true);
	m_objectNodeActivation_EOperation_terminate->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeObjectTokenContent()
{
	m_objectToken_EClass->setInstanceClass(nullptr);
	m_objectToken_EClass->setName("ObjectToken");
	m_objectToken_EClass->setAbstract(false);
	m_objectToken_EClass->setInterface(false);
	
	
	m_objectToken_EReference_value->setName("value");
	m_objectToken_EReference_value->setEType(getValue_EClass());
	m_objectToken_EReference_value->setLowerBound(0);
	m_objectToken_EReference_value->setUpperBound(1);
	m_objectToken_EReference_value->setTransient(false);
	m_objectToken_EReference_value->setVolatile(false);
	m_objectToken_EReference_value->setChangeable(true);
	m_objectToken_EReference_value->setUnsettable(false);
	m_objectToken_EReference_value->setUnique(true);
	m_objectToken_EReference_value->setDerived(false);
	m_objectToken_EReference_value->setOrdered(false);
	m_objectToken_EReference_value->setContainment(true);
	m_objectToken_EReference_value->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_objectToken_EReference_value->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_objectToken_EReference_value->setEOpposite(otherEnd);
	    }
	}
	
	m_objectToken_EOperation_equals_Token->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_objectToken_EOperation_equals_Token->setName("equals");
	m_objectToken_EOperation_equals_Token->setLowerBound(1);
	m_objectToken_EOperation_equals_Token->setUpperBound(1);
	m_objectToken_EOperation_equals_Token->setUnique(true);
	m_objectToken_EOperation_equals_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_objectToken_EOperation_equals_Token);
		parameter->setName("other");
		parameter->setEType(getToken_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_objectToken_EOperation_isControl->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_objectToken_EOperation_isControl->setName("isControl");
	m_objectToken_EOperation_isControl->setLowerBound(1);
	m_objectToken_EOperation_isControl->setUpperBound(1);
	m_objectToken_EOperation_isControl->setUnique(true);
	m_objectToken_EOperation_isControl->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeOfferContent()
{
	m_offer_EClass->setInstanceClass(nullptr);
	m_offer_EClass->setName("Offer");
	m_offer_EClass->setAbstract(false);
	m_offer_EClass->setInterface(false);
	
	
	m_offer_EReference_offeredTokens->setName("offeredTokens");
	m_offer_EReference_offeredTokens->setEType(getToken_EClass());
	m_offer_EReference_offeredTokens->setLowerBound(0);
	m_offer_EReference_offeredTokens->setUpperBound(-1);
	m_offer_EReference_offeredTokens->setTransient(false);
	m_offer_EReference_offeredTokens->setVolatile(false);
	m_offer_EReference_offeredTokens->setChangeable(true);
	m_offer_EReference_offeredTokens->setUnsettable(false);
	m_offer_EReference_offeredTokens->setUnique(true);
	m_offer_EReference_offeredTokens->setDerived(false);
	m_offer_EReference_offeredTokens->setOrdered(false);
	m_offer_EReference_offeredTokens->setContainment(false);
	m_offer_EReference_offeredTokens->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_offer_EReference_offeredTokens->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_offer_EReference_offeredTokens->setEOpposite(otherEnd);
	    }
	}
	
	m_offer_EOperation_countOfferedVales->setEType(ecore::EcorePackage::eInstance()->getEInt_EDataType());
	m_offer_EOperation_countOfferedVales->setName("countOfferedVales");
	m_offer_EOperation_countOfferedVales->setLowerBound(1);
	m_offer_EOperation_countOfferedVales->setUpperBound(1);
	m_offer_EOperation_countOfferedVales->setUnique(true);
	m_offer_EOperation_countOfferedVales->setOrdered(false);
	
	
	m_offer_EOperation_hasTokens->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_offer_EOperation_hasTokens->setName("hasTokens");
	m_offer_EOperation_hasTokens->setLowerBound(1);
	m_offer_EOperation_hasTokens->setUpperBound(1);
	m_offer_EOperation_hasTokens->setUnique(true);
	m_offer_EOperation_hasTokens->setOrdered(false);
	
	
	m_offer_EOperation_removeOfferedValues_EInt->setEType(nullptr);
	m_offer_EOperation_removeOfferedValues_EInt->setName("removeOfferedValues");
	m_offer_EOperation_removeOfferedValues_EInt->setLowerBound(1);
	m_offer_EOperation_removeOfferedValues_EInt->setUpperBound(1);
	m_offer_EOperation_removeOfferedValues_EInt->setUnique(true);
	m_offer_EOperation_removeOfferedValues_EInt->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_offer_EOperation_removeOfferedValues_EInt);
		parameter->setName("count");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_offer_EOperation_removeWithdrawnTokens->setEType(nullptr);
	m_offer_EOperation_removeWithdrawnTokens->setName("removeWithdrawnTokens");
	m_offer_EOperation_removeWithdrawnTokens->setLowerBound(1);
	m_offer_EOperation_removeWithdrawnTokens->setUpperBound(1);
	m_offer_EOperation_removeWithdrawnTokens->setUnique(true);
	m_offer_EOperation_removeWithdrawnTokens->setOrdered(false);
	
	
	m_offer_EOperation_retrieveOfferedTokens->setEType(getToken_EClass());
	m_offer_EOperation_retrieveOfferedTokens->setName("retrieveOfferedTokens");
	m_offer_EOperation_retrieveOfferedTokens->setLowerBound(0);
	m_offer_EOperation_retrieveOfferedTokens->setUpperBound(-1);
	m_offer_EOperation_retrieveOfferedTokens->setUnique(true);
	m_offer_EOperation_retrieveOfferedTokens->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeOpaqueBehaviorExecutionContent()
{
	m_opaqueBehaviorExecution_EClass->setInstanceClass(nullptr);
	m_opaqueBehaviorExecution_EClass->setName("OpaqueBehaviorExecution");
	m_opaqueBehaviorExecution_EClass->setAbstract(true);
	m_opaqueBehaviorExecution_EClass->setInterface(false);
	
	
	
	m_opaqueBehaviorExecution_EOperation_doBody_ParameterValue_ParameterValue->setEType(nullptr);
	m_opaqueBehaviorExecution_EOperation_doBody_ParameterValue_ParameterValue->setName("doBody");
	m_opaqueBehaviorExecution_EOperation_doBody_ParameterValue_ParameterValue->setLowerBound(1);
	m_opaqueBehaviorExecution_EOperation_doBody_ParameterValue_ParameterValue->setUpperBound(1);
	m_opaqueBehaviorExecution_EOperation_doBody_ParameterValue_ParameterValue->setUnique(true);
	m_opaqueBehaviorExecution_EOperation_doBody_ParameterValue_ParameterValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_opaqueBehaviorExecution_EOperation_doBody_ParameterValue_ParameterValue);
		parameter->setName("inputParameters");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_opaqueBehaviorExecution_EOperation_doBody_ParameterValue_ParameterValue);
		parameter->setName("outputParameters");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_opaqueBehaviorExecution_EOperation_execute->setEType(nullptr);
	m_opaqueBehaviorExecution_EOperation_execute->setName("execute");
	m_opaqueBehaviorExecution_EOperation_execute->setLowerBound(1);
	m_opaqueBehaviorExecution_EOperation_execute->setUpperBound(1);
	m_opaqueBehaviorExecution_EOperation_execute->setUnique(true);
	m_opaqueBehaviorExecution_EOperation_execute->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeOutputPinActivationContent()
{
	m_outputPinActivation_EClass->setInstanceClass(nullptr);
	m_outputPinActivation_EClass->setName("OutputPinActivation");
	m_outputPinActivation_EClass->setAbstract(false);
	m_outputPinActivation_EClass->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeParameterValueContent()
{
	m_parameterValue_EClass->setInstanceClass(nullptr);
	m_parameterValue_EClass->setName("ParameterValue");
	m_parameterValue_EClass->setAbstract(false);
	m_parameterValue_EClass->setInterface(false);
	
	
	m_parameterValue_EReference_parameter->setName("parameter");
	m_parameterValue_EReference_parameter->setEType(uml::UmlPackage::eInstance()->getParameter_EClass());
	m_parameterValue_EReference_parameter->setLowerBound(1);
	m_parameterValue_EReference_parameter->setUpperBound(1);
	m_parameterValue_EReference_parameter->setTransient(false);
	m_parameterValue_EReference_parameter->setVolatile(false);
	m_parameterValue_EReference_parameter->setChangeable(true);
	m_parameterValue_EReference_parameter->setUnsettable(false);
	m_parameterValue_EReference_parameter->setUnique(true);
	m_parameterValue_EReference_parameter->setDerived(false);
	m_parameterValue_EReference_parameter->setOrdered(false);
	m_parameterValue_EReference_parameter->setContainment(false);
	m_parameterValue_EReference_parameter->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_parameterValue_EReference_parameter->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_parameterValue_EReference_parameter->setEOpposite(otherEnd);
	    }
	}
	m_parameterValue_EReference_values->setName("values");
	m_parameterValue_EReference_values->setEType(getValue_EClass());
	m_parameterValue_EReference_values->setLowerBound(0);
	m_parameterValue_EReference_values->setUpperBound(-1);
	m_parameterValue_EReference_values->setTransient(false);
	m_parameterValue_EReference_values->setVolatile(false);
	m_parameterValue_EReference_values->setChangeable(true);
	m_parameterValue_EReference_values->setUnsettable(false);
	m_parameterValue_EReference_values->setUnique(true);
	m_parameterValue_EReference_values->setDerived(false);
	m_parameterValue_EReference_values->setOrdered(false);
	m_parameterValue_EReference_values->setContainment(true);
	m_parameterValue_EReference_values->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_parameterValue_EReference_values->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_parameterValue_EReference_values->setEOpposite(otherEnd);
	    }
	}
	
	
}

void FUMLPackageImpl::initializePinActivationContent()
{
	m_pinActivation_EClass->setInstanceClass(nullptr);
	m_pinActivation_EClass->setName("PinActivation");
	m_pinActivation_EClass->setAbstract(true);
	m_pinActivation_EClass->setInterface(false);
	
	
	m_pinActivation_EReference_actionActivation->setName("actionActivation");
	m_pinActivation_EReference_actionActivation->setEType(getActionActivation_EClass());
	m_pinActivation_EReference_actionActivation->setLowerBound(1);
	m_pinActivation_EReference_actionActivation->setUpperBound(1);
	m_pinActivation_EReference_actionActivation->setTransient(false);
	m_pinActivation_EReference_actionActivation->setVolatile(false);
	m_pinActivation_EReference_actionActivation->setChangeable(true);
	m_pinActivation_EReference_actionActivation->setUnsettable(false);
	m_pinActivation_EReference_actionActivation->setUnique(true);
	m_pinActivation_EReference_actionActivation->setDerived(false);
	m_pinActivation_EReference_actionActivation->setOrdered(false);
	m_pinActivation_EReference_actionActivation->setContainment(false);
	m_pinActivation_EReference_actionActivation->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_pinActivation_EReference_actionActivation->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_pinActivation_EReference_actionActivation->setEOpposite(otherEnd);
	    }
	}
	
	m_pinActivation_EOperation_fire_Token->setEType(nullptr);
	m_pinActivation_EOperation_fire_Token->setName("fire");
	m_pinActivation_EOperation_fire_Token->setLowerBound(1);
	m_pinActivation_EOperation_fire_Token->setUpperBound(1);
	m_pinActivation_EOperation_fire_Token->setUnique(true);
	m_pinActivation_EOperation_fire_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_pinActivation_EOperation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_pinActivation_EOperation_takeOfferedTokens->setEType(getToken_EClass());
	m_pinActivation_EOperation_takeOfferedTokens->setName("takeOfferedTokens");
	m_pinActivation_EOperation_takeOfferedTokens->setLowerBound(0);
	m_pinActivation_EOperation_takeOfferedTokens->setUpperBound(-1);
	m_pinActivation_EOperation_takeOfferedTokens->setUnique(true);
	m_pinActivation_EOperation_takeOfferedTokens->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializePrimitiveValueContent()
{
	m_primitiveValue_EClass->setInstanceClass(nullptr);
	m_primitiveValue_EClass->setName("PrimitiveValue");
	m_primitiveValue_EClass->setAbstract(true);
	m_primitiveValue_EClass->setInterface(false);
	
	
	m_primitiveValue_EReference_type->setName("type");
	m_primitiveValue_EReference_type->setEType(uml::UmlPackage::eInstance()->getPrimitiveType_EClass());
	m_primitiveValue_EReference_type->setLowerBound(1);
	m_primitiveValue_EReference_type->setUpperBound(1);
	m_primitiveValue_EReference_type->setTransient(false);
	m_primitiveValue_EReference_type->setVolatile(false);
	m_primitiveValue_EReference_type->setChangeable(true);
	m_primitiveValue_EReference_type->setUnsettable(false);
	m_primitiveValue_EReference_type->setUnique(true);
	m_primitiveValue_EReference_type->setDerived(false);
	m_primitiveValue_EReference_type->setOrdered(false);
	m_primitiveValue_EReference_type->setContainment(false);
	m_primitiveValue_EReference_type->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_primitiveValue_EReference_type->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_primitiveValue_EReference_type->setEOpposite(otherEnd);
	    }
	}
	
	m_primitiveValue_EOperation_getTypes->setEType(uml::UmlPackage::eInstance()->getClassifier_EClass());
	m_primitiveValue_EOperation_getTypes->setName("getTypes");
	m_primitiveValue_EOperation_getTypes->setLowerBound(0);
	m_primitiveValue_EOperation_getTypes->setUpperBound(-1);
	m_primitiveValue_EOperation_getTypes->setUnique(true);
	m_primitiveValue_EOperation_getTypes->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeReadExtentActionActivationContent()
{
	m_readExtentActionActivation_EClass->setInstanceClass(nullptr);
	m_readExtentActionActivation_EClass->setName("ReadExtentActionActivation");
	m_readExtentActionActivation_EClass->setAbstract(false);
	m_readExtentActionActivation_EClass->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeReadIsClassifiedObjectActionActivationContent()
{
	m_readIsClassifiedObjectActionActivation_EClass->setInstanceClass(nullptr);
	m_readIsClassifiedObjectActionActivation_EClass->setName("ReadIsClassifiedObjectActionActivation");
	m_readIsClassifiedObjectActionActivation_EClass->setAbstract(false);
	m_readIsClassifiedObjectActionActivation_EClass->setInterface(false);
	
	
	
	m_readIsClassifiedObjectActionActivation_EOperation_checkAllParents_Classifier_Classifier->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_readIsClassifiedObjectActionActivation_EOperation_checkAllParents_Classifier_Classifier->setName("checkAllParents");
	m_readIsClassifiedObjectActionActivation_EOperation_checkAllParents_Classifier_Classifier->setLowerBound(0);
	m_readIsClassifiedObjectActionActivation_EOperation_checkAllParents_Classifier_Classifier->setUpperBound(1);
	m_readIsClassifiedObjectActionActivation_EOperation_checkAllParents_Classifier_Classifier->setUnique(true);
	m_readIsClassifiedObjectActionActivation_EOperation_checkAllParents_Classifier_Classifier->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_readIsClassifiedObjectActionActivation_EOperation_checkAllParents_Classifier_Classifier);
		parameter->setName("type");
		parameter->setEType(uml::UmlPackage::eInstance()->getClassifier_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_readIsClassifiedObjectActionActivation_EOperation_checkAllParents_Classifier_Classifier);
		parameter->setName("classifier");
		parameter->setEType(uml::UmlPackage::eInstance()->getClassifier_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeReadLinkActionActivationContent()
{
	m_readLinkActionActivation_EClass->setInstanceClass(nullptr);
	m_readLinkActionActivation_EClass->setName("ReadLinkActionActivation");
	m_readLinkActionActivation_EClass->setAbstract(false);
	m_readLinkActionActivation_EClass->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeReadSelfActionActivationContent()
{
	m_readSelfActionActivation_EClass->setInstanceClass(nullptr);
	m_readSelfActionActivation_EClass->setName("ReadSelfActionActivation");
	m_readSelfActionActivation_EClass->setAbstract(false);
	m_readSelfActionActivation_EClass->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeReadStructuralFeatureActionActivationContent()
{
	m_readStructuralFeatureActionActivation_EClass->setInstanceClass(nullptr);
	m_readStructuralFeatureActionActivation_EClass->setName("ReadStructuralFeatureActionActivation");
	m_readStructuralFeatureActionActivation_EClass->setAbstract(false);
	m_readStructuralFeatureActionActivation_EClass->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeRealValueContent()
{
	m_realValue_EClass->setInstanceClass(nullptr);
	m_realValue_EClass->setName("RealValue");
	m_realValue_EClass->setAbstract(false);
	m_realValue_EClass->setInterface(false);
	
	m_realValue_EAttribute_value = getRealValue_EAttribute_value();
	m_realValue_EAttribute_value->setName("value");
	m_realValue_EAttribute_value->setEType(ecore::EcorePackage::eInstance()->getEFloat_EDataType());
	m_realValue_EAttribute_value->setLowerBound(1);
	m_realValue_EAttribute_value->setUpperBound(1);
	m_realValue_EAttribute_value->setTransient(false);
	m_realValue_EAttribute_value->setVolatile(false);
	m_realValue_EAttribute_value->setChangeable(true);
	m_realValue_EAttribute_value->setUnsettable(false);
	m_realValue_EAttribute_value->setUnique(true);
	m_realValue_EAttribute_value->setDerived(false);
	m_realValue_EAttribute_value->setOrdered(false);
	m_realValue_EAttribute_value->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_realValue_EAttribute_value->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	m_realValue_EOperation_equals_Value->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_realValue_EOperation_equals_Value->setName("equals");
	m_realValue_EOperation_equals_Value->setLowerBound(1);
	m_realValue_EOperation_equals_Value->setUpperBound(1);
	m_realValue_EOperation_equals_Value->setUnique(true);
	m_realValue_EOperation_equals_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_realValue_EOperation_equals_Value);
		parameter->setName("otherValue");
		parameter->setEType(getValue_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_realValue_EOperation_specify->setEType(uml::UmlPackage::eInstance()->getValueSpecification_EClass());
	m_realValue_EOperation_specify->setName("specify");
	m_realValue_EOperation_specify->setLowerBound(1);
	m_realValue_EOperation_specify->setUpperBound(1);
	m_realValue_EOperation_specify->setUnique(true);
	m_realValue_EOperation_specify->setOrdered(false);
	
	
	m_realValue_EOperation_toString->setEType(ecore::EcorePackage::eInstance()->getEString_EDataType());
	m_realValue_EOperation_toString->setName("toString");
	m_realValue_EOperation_toString->setLowerBound(1);
	m_realValue_EOperation_toString->setUpperBound(1);
	m_realValue_EOperation_toString->setUnique(true);
	m_realValue_EOperation_toString->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeReclassifyObjectActionActivationContent()
{
	m_reclassifyObjectActionActivation_EClass->setInstanceClass(nullptr);
	m_reclassifyObjectActionActivation_EClass->setName("ReclassifyObjectActionActivation");
	m_reclassifyObjectActionActivation_EClass->setAbstract(false);
	m_reclassifyObjectActionActivation_EClass->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeRedefinitionBasedDispatchStrategyContent()
{
	m_redefinitionBasedDispatchStrategy_EClass->setInstanceClass(nullptr);
	m_redefinitionBasedDispatchStrategy_EClass->setName("RedefinitionBasedDispatchStrategy");
	m_redefinitionBasedDispatchStrategy_EClass->setAbstract(false);
	m_redefinitionBasedDispatchStrategy_EClass->setInterface(false);
	
	
	
	m_redefinitionBasedDispatchStrategy_EOperation_operationsMatch_Operation_Operation->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_redefinitionBasedDispatchStrategy_EOperation_operationsMatch_Operation_Operation->setName("operationsMatch");
	m_redefinitionBasedDispatchStrategy_EOperation_operationsMatch_Operation_Operation->setLowerBound(1);
	m_redefinitionBasedDispatchStrategy_EOperation_operationsMatch_Operation_Operation->setUpperBound(1);
	m_redefinitionBasedDispatchStrategy_EOperation_operationsMatch_Operation_Operation->setUnique(true);
	m_redefinitionBasedDispatchStrategy_EOperation_operationsMatch_Operation_Operation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_redefinitionBasedDispatchStrategy_EOperation_operationsMatch_Operation_Operation);
		parameter->setName("ownedOperation");
		parameter->setEType(uml::UmlPackage::eInstance()->getOperation_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_redefinitionBasedDispatchStrategy_EOperation_operationsMatch_Operation_Operation);
		parameter->setName("baseOperation");
		parameter->setEType(uml::UmlPackage::eInstance()->getOperation_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_redefinitionBasedDispatchStrategy_EOperation_retrieveMethod_Object_Operation->setEType(uml::UmlPackage::eInstance()->getBehavior_EClass());
	m_redefinitionBasedDispatchStrategy_EOperation_retrieveMethod_Object_Operation->setName("retrieveMethod");
	m_redefinitionBasedDispatchStrategy_EOperation_retrieveMethod_Object_Operation->setLowerBound(1);
	m_redefinitionBasedDispatchStrategy_EOperation_retrieveMethod_Object_Operation->setUpperBound(1);
	m_redefinitionBasedDispatchStrategy_EOperation_retrieveMethod_Object_Operation->setUnique(true);
	m_redefinitionBasedDispatchStrategy_EOperation_retrieveMethod_Object_Operation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_redefinitionBasedDispatchStrategy_EOperation_retrieveMethod_Object_Operation);
		parameter->setName("object");
		parameter->setEType(getObject_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_redefinitionBasedDispatchStrategy_EOperation_retrieveMethod_Object_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::UmlPackage::eInstance()->getOperation_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeReduceActionActivationContent()
{
	m_reduceActionActivation_EClass->setInstanceClass(nullptr);
	m_reduceActionActivation_EClass->setName("ReduceActionActivation");
	m_reduceActionActivation_EClass->setAbstract(false);
	m_reduceActionActivation_EClass->setInterface(false);
	
	
	m_reduceActionActivation_EReference_currentExecution->setName("currentExecution");
	m_reduceActionActivation_EReference_currentExecution->setEType(getExecution_EClass());
	m_reduceActionActivation_EReference_currentExecution->setLowerBound(0);
	m_reduceActionActivation_EReference_currentExecution->setUpperBound(1);
	m_reduceActionActivation_EReference_currentExecution->setTransient(false);
	m_reduceActionActivation_EReference_currentExecution->setVolatile(false);
	m_reduceActionActivation_EReference_currentExecution->setChangeable(true);
	m_reduceActionActivation_EReference_currentExecution->setUnsettable(false);
	m_reduceActionActivation_EReference_currentExecution->setUnique(true);
	m_reduceActionActivation_EReference_currentExecution->setDerived(false);
	m_reduceActionActivation_EReference_currentExecution->setOrdered(false);
	m_reduceActionActivation_EReference_currentExecution->setContainment(false);
	m_reduceActionActivation_EReference_currentExecution->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_reduceActionActivation_EReference_currentExecution->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_reduceActionActivation_EReference_currentExecution->setEOpposite(otherEnd);
	    }
	}
	
	
}

void FUMLPackageImpl::initializeReferenceContent()
{
	m_reference_EClass->setInstanceClass(nullptr);
	m_reference_EClass->setName("Reference");
	m_reference_EClass->setAbstract(false);
	m_reference_EClass->setInterface(false);
	
	
	m_reference_EReference_referent->setName("referent");
	m_reference_EReference_referent->setEType(getObject_EClass());
	m_reference_EReference_referent->setLowerBound(1);
	m_reference_EReference_referent->setUpperBound(1);
	m_reference_EReference_referent->setTransient(false);
	m_reference_EReference_referent->setVolatile(false);
	m_reference_EReference_referent->setChangeable(true);
	m_reference_EReference_referent->setUnsettable(false);
	m_reference_EReference_referent->setUnique(true);
	m_reference_EReference_referent->setDerived(false);
	m_reference_EReference_referent->setOrdered(false);
	m_reference_EReference_referent->setContainment(false);
	m_reference_EReference_referent->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_reference_EReference_referent->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_reference_EReference_referent->setEOpposite(otherEnd);
	    }
	}
	
	m_reference_EOperation_assignFeatureValue_StructuralFeature_EInt->setEType(nullptr);
	m_reference_EOperation_assignFeatureValue_StructuralFeature_EInt->setName("assignFeatureValue");
	m_reference_EOperation_assignFeatureValue_StructuralFeature_EInt->setLowerBound(1);
	m_reference_EOperation_assignFeatureValue_StructuralFeature_EInt->setUpperBound(1);
	m_reference_EOperation_assignFeatureValue_StructuralFeature_EInt->setUnique(true);
	m_reference_EOperation_assignFeatureValue_StructuralFeature_EInt->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_reference_EOperation_assignFeatureValue_StructuralFeature_EInt);
		parameter->setName("feature");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_reference_EOperation_assignFeatureValue_StructuralFeature_EInt);
		parameter->setName("values");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_reference_EOperation_assignFeatureValue_StructuralFeature_EInt);
		parameter->setName("position");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_reference_EOperation_destroy->setEType(nullptr);
	m_reference_EOperation_destroy->setName("destroy");
	m_reference_EOperation_destroy->setLowerBound(1);
	m_reference_EOperation_destroy->setUpperBound(1);
	m_reference_EOperation_destroy->setUnique(true);
	m_reference_EOperation_destroy->setOrdered(false);
	
	
	m_reference_EOperation_dispatch_Operation->setEType(getExecution_EClass());
	m_reference_EOperation_dispatch_Operation->setName("dispatch");
	m_reference_EOperation_dispatch_Operation->setLowerBound(1);
	m_reference_EOperation_dispatch_Operation->setUpperBound(1);
	m_reference_EOperation_dispatch_Operation->setUnique(true);
	m_reference_EOperation_dispatch_Operation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_reference_EOperation_dispatch_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::UmlPackage::eInstance()->getOperation_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_reference_EOperation_equals_Value->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_reference_EOperation_equals_Value->setName("equals");
	m_reference_EOperation_equals_Value->setLowerBound(1);
	m_reference_EOperation_equals_Value->setUpperBound(1);
	m_reference_EOperation_equals_Value->setUnique(true);
	m_reference_EOperation_equals_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_reference_EOperation_equals_Value);
		parameter->setName("otherValue");
		parameter->setEType(getValue_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_reference_EOperation_getTypes->setEType(uml::UmlPackage::eInstance()->getClassifier_EClass());
	m_reference_EOperation_getTypes->setName("getTypes");
	m_reference_EOperation_getTypes->setLowerBound(0);
	m_reference_EOperation_getTypes->setUpperBound(-1);
	m_reference_EOperation_getTypes->setUnique(true);
	m_reference_EOperation_getTypes->setOrdered(false);
	
	
	m_reference_EOperation_new_->setEType(getValue_EClass());
	m_reference_EOperation_new_->setName("new_");
	m_reference_EOperation_new_->setLowerBound(1);
	m_reference_EOperation_new_->setUpperBound(1);
	m_reference_EOperation_new_->setUnique(true);
	m_reference_EOperation_new_->setOrdered(false);
	
	
	m_reference_EOperation_retrieveFeatureValue_StructuralFeature->setEType(getFeatureValue_EClass());
	m_reference_EOperation_retrieveFeatureValue_StructuralFeature->setName("retrieveFeatureValue");
	m_reference_EOperation_retrieveFeatureValue_StructuralFeature->setLowerBound(1);
	m_reference_EOperation_retrieveFeatureValue_StructuralFeature->setUpperBound(1);
	m_reference_EOperation_retrieveFeatureValue_StructuralFeature->setUnique(true);
	m_reference_EOperation_retrieveFeatureValue_StructuralFeature->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_reference_EOperation_retrieveFeatureValue_StructuralFeature);
		parameter->setName("feature");
		parameter->setEType(uml::UmlPackage::eInstance()->getStructuralFeature_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_reference_EOperation_retrieveFeatureValues->setEType(getFeatureValue_EClass());
	m_reference_EOperation_retrieveFeatureValues->setName("retrieveFeatureValues");
	m_reference_EOperation_retrieveFeatureValues->setLowerBound(0);
	m_reference_EOperation_retrieveFeatureValues->setUpperBound(-1);
	m_reference_EOperation_retrieveFeatureValues->setUnique(true);
	m_reference_EOperation_retrieveFeatureValues->setOrdered(false);
	
	
	m_reference_EOperation_send_SignalInstance->setEType(nullptr);
	m_reference_EOperation_send_SignalInstance->setName("send");
	m_reference_EOperation_send_SignalInstance->setLowerBound(1);
	m_reference_EOperation_send_SignalInstance->setUpperBound(1);
	m_reference_EOperation_send_SignalInstance->setUnique(true);
	m_reference_EOperation_send_SignalInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_reference_EOperation_send_SignalInstance);
		parameter->setName("signalInstance");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_reference_EOperation_startBehavior_Class_ParameterValue->setEType(nullptr);
	m_reference_EOperation_startBehavior_Class_ParameterValue->setName("startBehavior");
	m_reference_EOperation_startBehavior_Class_ParameterValue->setLowerBound(1);
	m_reference_EOperation_startBehavior_Class_ParameterValue->setUpperBound(1);
	m_reference_EOperation_startBehavior_Class_ParameterValue->setUnique(true);
	m_reference_EOperation_startBehavior_Class_ParameterValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_reference_EOperation_startBehavior_Class_ParameterValue);
		parameter->setName("classifier");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_reference_EOperation_startBehavior_Class_ParameterValue);
		parameter->setName("inputs");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_reference_EOperation_toString->setEType(ecore::EcorePackage::eInstance()->getEString_EDataType());
	m_reference_EOperation_toString->setName("toString");
	m_reference_EOperation_toString->setLowerBound(1);
	m_reference_EOperation_toString->setUpperBound(1);
	m_reference_EOperation_toString->setUnique(true);
	m_reference_EOperation_toString->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeRemoveStructuralFeatureValueActivationContent()
{
	m_removeStructuralFeatureValueActivation_EClass->setInstanceClass(nullptr);
	m_removeStructuralFeatureValueActivation_EClass->setName("RemoveStructuralFeatureValueActivation");
	m_removeStructuralFeatureValueActivation_EClass->setAbstract(false);
	m_removeStructuralFeatureValueActivation_EClass->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeSemanticStrategyContent()
{
	m_semanticStrategy_EClass->setInstanceClass(nullptr);
	m_semanticStrategy_EClass->setName("SemanticStrategy");
	m_semanticStrategy_EClass->setAbstract(true);
	m_semanticStrategy_EClass->setInterface(false);
	
	
	
	m_semanticStrategy_EOperation_retrieveName->setEType(ecore::EcorePackage::eInstance()->getEString_EDataType());
	m_semanticStrategy_EOperation_retrieveName->setName("retrieveName");
	m_semanticStrategy_EOperation_retrieveName->setLowerBound(1);
	m_semanticStrategy_EOperation_retrieveName->setUpperBound(1);
	m_semanticStrategy_EOperation_retrieveName->setUnique(true);
	m_semanticStrategy_EOperation_retrieveName->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeSemanticVisitorContent()
{
	m_semanticVisitor_EClass->setInstanceClass(nullptr);
	m_semanticVisitor_EClass->setName("SemanticVisitor");
	m_semanticVisitor_EClass->setAbstract(true);
	m_semanticVisitor_EClass->setInterface(false);
	
	
	
	m_semanticVisitor_EOperation__beginIsolation->setEType(nullptr);
	m_semanticVisitor_EOperation__beginIsolation->setName("_beginIsolation");
	m_semanticVisitor_EOperation__beginIsolation->setLowerBound(1);
	m_semanticVisitor_EOperation__beginIsolation->setUpperBound(1);
	m_semanticVisitor_EOperation__beginIsolation->setUnique(true);
	m_semanticVisitor_EOperation__beginIsolation->setOrdered(false);
	
	
	m_semanticVisitor_EOperation__endIsolation->setEType(nullptr);
	m_semanticVisitor_EOperation__endIsolation->setName("_endIsolation");
	m_semanticVisitor_EOperation__endIsolation->setLowerBound(1);
	m_semanticVisitor_EOperation__endIsolation->setUpperBound(1);
	m_semanticVisitor_EOperation__endIsolation->setUnique(true);
	m_semanticVisitor_EOperation__endIsolation->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeSendSignalActionActivationContent()
{
	m_sendSignalActionActivation_EClass->setInstanceClass(nullptr);
	m_sendSignalActionActivation_EClass->setName("SendSignalActionActivation");
	m_sendSignalActionActivation_EClass->setAbstract(false);
	m_sendSignalActionActivation_EClass->setInterface(false);
	
	
	
	m_sendSignalActionActivation_EOperation_doAction->setEType(nullptr);
	m_sendSignalActionActivation_EOperation_doAction->setName("doAction");
	m_sendSignalActionActivation_EOperation_doAction->setLowerBound(1);
	m_sendSignalActionActivation_EOperation_doAction->setUpperBound(1);
	m_sendSignalActionActivation_EOperation_doAction->setUnique(true);
	m_sendSignalActionActivation_EOperation_doAction->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeSignalInstanceContent()
{
	m_signalInstance_EClass->setInstanceClass(nullptr);
	m_signalInstance_EClass->setName("SignalInstance");
	m_signalInstance_EClass->setAbstract(false);
	m_signalInstance_EClass->setInterface(false);
	
	
	m_signalInstance_EReference_type->setName("type");
	m_signalInstance_EReference_type->setEType(uml::UmlPackage::eInstance()->getSignal_EClass());
	m_signalInstance_EReference_type->setLowerBound(1);
	m_signalInstance_EReference_type->setUpperBound(1);
	m_signalInstance_EReference_type->setTransient(false);
	m_signalInstance_EReference_type->setVolatile(false);
	m_signalInstance_EReference_type->setChangeable(true);
	m_signalInstance_EReference_type->setUnsettable(false);
	m_signalInstance_EReference_type->setUnique(true);
	m_signalInstance_EReference_type->setDerived(false);
	m_signalInstance_EReference_type->setOrdered(false);
	m_signalInstance_EReference_type->setContainment(false);
	m_signalInstance_EReference_type->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_signalInstance_EReference_type->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_signalInstance_EReference_type->setEOpposite(otherEnd);
	    }
	}
	
	
}

void FUMLPackageImpl::initializeStartClassifierBehaviorActionActivationContent()
{
	m_startClassifierBehaviorActionActivation_EClass->setInstanceClass(nullptr);
	m_startClassifierBehaviorActionActivation_EClass->setName("StartClassifierBehaviorActionActivation");
	m_startClassifierBehaviorActionActivation_EClass->setAbstract(false);
	m_startClassifierBehaviorActionActivation_EClass->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeStartObjectBehaviorActionActivationContent()
{
	m_startObjectBehaviorActionActivation_EClass->setInstanceClass(nullptr);
	m_startObjectBehaviorActionActivation_EClass->setName("StartObjectBehaviorActionActivation");
	m_startObjectBehaviorActionActivation_EClass->setAbstract(false);
	m_startObjectBehaviorActionActivation_EClass->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeStringValueContent()
{
	m_stringValue_EClass->setInstanceClass(nullptr);
	m_stringValue_EClass->setName("StringValue");
	m_stringValue_EClass->setAbstract(false);
	m_stringValue_EClass->setInterface(false);
	
	m_stringValue_EAttribute_value = getStringValue_EAttribute_value();
	m_stringValue_EAttribute_value->setName("value");
	m_stringValue_EAttribute_value->setEType(ecore::EcorePackage::eInstance()->getEString_EDataType());
	m_stringValue_EAttribute_value->setLowerBound(1);
	m_stringValue_EAttribute_value->setUpperBound(1);
	m_stringValue_EAttribute_value->setTransient(false);
	m_stringValue_EAttribute_value->setVolatile(false);
	m_stringValue_EAttribute_value->setChangeable(true);
	m_stringValue_EAttribute_value->setUnsettable(false);
	m_stringValue_EAttribute_value->setUnique(true);
	m_stringValue_EAttribute_value->setDerived(false);
	m_stringValue_EAttribute_value->setOrdered(false);
	m_stringValue_EAttribute_value->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_stringValue_EAttribute_value->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	m_stringValue_EOperation_equals_Value->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_stringValue_EOperation_equals_Value->setName("equals");
	m_stringValue_EOperation_equals_Value->setLowerBound(1);
	m_stringValue_EOperation_equals_Value->setUpperBound(1);
	m_stringValue_EOperation_equals_Value->setUnique(true);
	m_stringValue_EOperation_equals_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_stringValue_EOperation_equals_Value);
		parameter->setName("otherValue");
		parameter->setEType(getValue_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stringValue_EOperation_specify->setEType(uml::UmlPackage::eInstance()->getValueSpecification_EClass());
	m_stringValue_EOperation_specify->setName("specify");
	m_stringValue_EOperation_specify->setLowerBound(1);
	m_stringValue_EOperation_specify->setUpperBound(1);
	m_stringValue_EOperation_specify->setUnique(true);
	m_stringValue_EOperation_specify->setOrdered(false);
	
	
	m_stringValue_EOperation_toString->setEType(ecore::EcorePackage::eInstance()->getEString_EDataType());
	m_stringValue_EOperation_toString->setName("toString");
	m_stringValue_EOperation_toString->setLowerBound(1);
	m_stringValue_EOperation_toString->setUpperBound(1);
	m_stringValue_EOperation_toString->setUnique(true);
	m_stringValue_EOperation_toString->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeStructuralFeatureActionActivationContent()
{
	m_structuralFeatureActionActivation_EClass->setInstanceClass(nullptr);
	m_structuralFeatureActionActivation_EClass->setName("StructuralFeatureActionActivation");
	m_structuralFeatureActionActivation_EClass->setAbstract(true);
	m_structuralFeatureActionActivation_EClass->setInterface(false);
	
	
	
	m_structuralFeatureActionActivation_EOperation_getAssociation_StructuralFeature->setEType(uml::UmlPackage::eInstance()->getAssociation_EClass());
	m_structuralFeatureActionActivation_EOperation_getAssociation_StructuralFeature->setName("getAssociation");
	m_structuralFeatureActionActivation_EOperation_getAssociation_StructuralFeature->setLowerBound(0);
	m_structuralFeatureActionActivation_EOperation_getAssociation_StructuralFeature->setUpperBound(1);
	m_structuralFeatureActionActivation_EOperation_getAssociation_StructuralFeature->setUnique(true);
	m_structuralFeatureActionActivation_EOperation_getAssociation_StructuralFeature->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuralFeatureActionActivation_EOperation_getAssociation_StructuralFeature);
		parameter->setName("feature");
		parameter->setEType(uml::UmlPackage::eInstance()->getStructuralFeature_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuralFeatureActionActivation_EOperation_getMatchingLinks_Association_Value->setEType(getLink_EClass());
	m_structuralFeatureActionActivation_EOperation_getMatchingLinks_Association_Value->setName("getMatchingLinks");
	m_structuralFeatureActionActivation_EOperation_getMatchingLinks_Association_Value->setLowerBound(0);
	m_structuralFeatureActionActivation_EOperation_getMatchingLinks_Association_Value->setUpperBound(-1);
	m_structuralFeatureActionActivation_EOperation_getMatchingLinks_Association_Value->setUnique(true);
	m_structuralFeatureActionActivation_EOperation_getMatchingLinks_Association_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuralFeatureActionActivation_EOperation_getMatchingLinks_Association_Value);
		parameter->setName("association");
		parameter->setEType(uml::UmlPackage::eInstance()->getAssociation_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuralFeatureActionActivation_EOperation_getMatchingLinks_Association_Value);
		parameter->setName("end");
		parameter->setEType(uml::UmlPackage::eInstance()->getStructuralFeature_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuralFeatureActionActivation_EOperation_getMatchingLinks_Association_Value);
		parameter->setName("oppositeValue");
		parameter->setEType(getValue_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuralFeatureActionActivation_EOperation_getOppositeEnd_Association_StructuralFeature->setEType(uml::UmlPackage::eInstance()->getProperty_EClass());
	m_structuralFeatureActionActivation_EOperation_getOppositeEnd_Association_StructuralFeature->setName("getOppositeEnd");
	m_structuralFeatureActionActivation_EOperation_getOppositeEnd_Association_StructuralFeature->setLowerBound(1);
	m_structuralFeatureActionActivation_EOperation_getOppositeEnd_Association_StructuralFeature->setUpperBound(1);
	m_structuralFeatureActionActivation_EOperation_getOppositeEnd_Association_StructuralFeature->setUnique(true);
	m_structuralFeatureActionActivation_EOperation_getOppositeEnd_Association_StructuralFeature->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuralFeatureActionActivation_EOperation_getOppositeEnd_Association_StructuralFeature);
		parameter->setName("association");
		parameter->setEType(uml::UmlPackage::eInstance()->getAssociation_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuralFeatureActionActivation_EOperation_getOppositeEnd_Association_StructuralFeature);
		parameter->setName("end");
		parameter->setEType(uml::UmlPackage::eInstance()->getStructuralFeature_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeStructuredActivityNodeActivationContent()
{
	m_structuredActivityNodeActivation_EClass->setInstanceClass(nullptr);
	m_structuredActivityNodeActivation_EClass->setName("StructuredActivityNodeActivation");
	m_structuredActivityNodeActivation_EClass->setAbstract(false);
	m_structuredActivityNodeActivation_EClass->setInterface(false);
	
	
	m_structuredActivityNodeActivation_EReference_activationGroup->setName("activationGroup");
	m_structuredActivityNodeActivation_EReference_activationGroup->setEType(getActivityNodeActivationGroup_EClass());
	m_structuredActivityNodeActivation_EReference_activationGroup->setLowerBound(1);
	m_structuredActivityNodeActivation_EReference_activationGroup->setUpperBound(1);
	m_structuredActivityNodeActivation_EReference_activationGroup->setTransient(false);
	m_structuredActivityNodeActivation_EReference_activationGroup->setVolatile(false);
	m_structuredActivityNodeActivation_EReference_activationGroup->setChangeable(true);
	m_structuredActivityNodeActivation_EReference_activationGroup->setUnsettable(false);
	m_structuredActivityNodeActivation_EReference_activationGroup->setUnique(true);
	m_structuredActivityNodeActivation_EReference_activationGroup->setDerived(false);
	m_structuredActivityNodeActivation_EReference_activationGroup->setOrdered(false);
	m_structuredActivityNodeActivation_EReference_activationGroup->setContainment(true);
	m_structuredActivityNodeActivation_EReference_activationGroup->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_structuredActivityNodeActivation_EReference_activationGroup->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_structuredActivityNodeActivation_EReference_activationGroup->setEOpposite(otherEnd);
	    }
	}
	
	m_structuredActivityNodeActivation_EOperation_completeAction->setEType(getToken_EClass());
	m_structuredActivityNodeActivation_EOperation_completeAction->setName("completeAction");
	m_structuredActivityNodeActivation_EOperation_completeAction->setLowerBound(0);
	m_structuredActivityNodeActivation_EOperation_completeAction->setUpperBound(-1);
	m_structuredActivityNodeActivation_EOperation_completeAction->setUnique(true);
	m_structuredActivityNodeActivation_EOperation_completeAction->setOrdered(false);
	
	
	m_structuredActivityNodeActivation_EOperation_createEdgeInstances->setEType(nullptr);
	m_structuredActivityNodeActivation_EOperation_createEdgeInstances->setName("createEdgeInstances");
	m_structuredActivityNodeActivation_EOperation_createEdgeInstances->setLowerBound(1);
	m_structuredActivityNodeActivation_EOperation_createEdgeInstances->setUpperBound(1);
	m_structuredActivityNodeActivation_EOperation_createEdgeInstances->setUnique(true);
	m_structuredActivityNodeActivation_EOperation_createEdgeInstances->setOrdered(false);
	
	
	m_structuredActivityNodeActivation_EOperation_createNodeActivations->setEType(nullptr);
	m_structuredActivityNodeActivation_EOperation_createNodeActivations->setName("createNodeActivations");
	m_structuredActivityNodeActivation_EOperation_createNodeActivations->setLowerBound(1);
	m_structuredActivityNodeActivation_EOperation_createNodeActivations->setUpperBound(1);
	m_structuredActivityNodeActivation_EOperation_createNodeActivations->setUnique(true);
	m_structuredActivityNodeActivation_EOperation_createNodeActivations->setOrdered(false);
	
	
	m_structuredActivityNodeActivation_EOperation_doAction->setEType(nullptr);
	m_structuredActivityNodeActivation_EOperation_doAction->setName("doAction");
	m_structuredActivityNodeActivation_EOperation_doAction->setLowerBound(1);
	m_structuredActivityNodeActivation_EOperation_doAction->setUpperBound(1);
	m_structuredActivityNodeActivation_EOperation_doAction->setUnique(true);
	m_structuredActivityNodeActivation_EOperation_doAction->setOrdered(false);
	
	
	m_structuredActivityNodeActivation_EOperation_doStructuredActivity->setEType(nullptr);
	m_structuredActivityNodeActivation_EOperation_doStructuredActivity->setName("doStructuredActivity");
	m_structuredActivityNodeActivation_EOperation_doStructuredActivity->setLowerBound(0);
	m_structuredActivityNodeActivation_EOperation_doStructuredActivity->setUpperBound(1);
	m_structuredActivityNodeActivation_EOperation_doStructuredActivity->setUnique(true);
	m_structuredActivityNodeActivation_EOperation_doStructuredActivity->setOrdered(false);
	
	
	m_structuredActivityNodeActivation_EOperation_getNodeActivation_ActivityNode->setEType(getActivityNodeActivation_EClass());
	m_structuredActivityNodeActivation_EOperation_getNodeActivation_ActivityNode->setName("getNodeActivation");
	m_structuredActivityNodeActivation_EOperation_getNodeActivation_ActivityNode->setLowerBound(1);
	m_structuredActivityNodeActivation_EOperation_getNodeActivation_ActivityNode->setUpperBound(1);
	m_structuredActivityNodeActivation_EOperation_getNodeActivation_ActivityNode->setUnique(true);
	m_structuredActivityNodeActivation_EOperation_getNodeActivation_ActivityNode->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuredActivityNodeActivation_EOperation_getNodeActivation_ActivityNode);
		parameter->setName("node");
		parameter->setEType(uml::UmlPackage::eInstance()->getActivityNode_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredActivityNodeActivation_EOperation_getPinValues_OutputPin->setEType(getValue_EClass());
	m_structuredActivityNodeActivation_EOperation_getPinValues_OutputPin->setName("getPinValues");
	m_structuredActivityNodeActivation_EOperation_getPinValues_OutputPin->setLowerBound(0);
	m_structuredActivityNodeActivation_EOperation_getPinValues_OutputPin->setUpperBound(-1);
	m_structuredActivityNodeActivation_EOperation_getPinValues_OutputPin->setUnique(true);
	m_structuredActivityNodeActivation_EOperation_getPinValues_OutputPin->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuredActivityNodeActivation_EOperation_getPinValues_OutputPin);
		parameter->setName("pin");
		parameter->setEType(uml::UmlPackage::eInstance()->getOutputPin_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredActivityNodeActivation_EOperation_isSourceFor_ActivityEdgeInstance->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_structuredActivityNodeActivation_EOperation_isSourceFor_ActivityEdgeInstance->setName("isSourceFor");
	m_structuredActivityNodeActivation_EOperation_isSourceFor_ActivityEdgeInstance->setLowerBound(1);
	m_structuredActivityNodeActivation_EOperation_isSourceFor_ActivityEdgeInstance->setUpperBound(1);
	m_structuredActivityNodeActivation_EOperation_isSourceFor_ActivityEdgeInstance->setUnique(true);
	m_structuredActivityNodeActivation_EOperation_isSourceFor_ActivityEdgeInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuredActivityNodeActivation_EOperation_isSourceFor_ActivityEdgeInstance);
		parameter->setName("edgeInstance");
		parameter->setEType(getActivityEdgeInstance_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredActivityNodeActivation_EOperation_isSuspended->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_structuredActivityNodeActivation_EOperation_isSuspended->setName("isSuspended");
	m_structuredActivityNodeActivation_EOperation_isSuspended->setLowerBound(1);
	m_structuredActivityNodeActivation_EOperation_isSuspended->setUpperBound(1);
	m_structuredActivityNodeActivation_EOperation_isSuspended->setUnique(true);
	m_structuredActivityNodeActivation_EOperation_isSuspended->setOrdered(false);
	
	
	m_structuredActivityNodeActivation_EOperation_makeActivityNodeList_ExecutableNode->setEType(uml::UmlPackage::eInstance()->getActivityNode_EClass());
	m_structuredActivityNodeActivation_EOperation_makeActivityNodeList_ExecutableNode->setName("makeActivityNodeList");
	m_structuredActivityNodeActivation_EOperation_makeActivityNodeList_ExecutableNode->setLowerBound(0);
	m_structuredActivityNodeActivation_EOperation_makeActivityNodeList_ExecutableNode->setUpperBound(-1);
	m_structuredActivityNodeActivation_EOperation_makeActivityNodeList_ExecutableNode->setUnique(true);
	m_structuredActivityNodeActivation_EOperation_makeActivityNodeList_ExecutableNode->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuredActivityNodeActivation_EOperation_makeActivityNodeList_ExecutableNode);
		parameter->setName("nodes");
		parameter->setEType(uml::UmlPackage::eInstance()->getExecutableNode_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredActivityNodeActivation_EOperation_putPinValues_OutputPin_Value->setEType(nullptr);
	m_structuredActivityNodeActivation_EOperation_putPinValues_OutputPin_Value->setName("putPinValues");
	m_structuredActivityNodeActivation_EOperation_putPinValues_OutputPin_Value->setLowerBound(1);
	m_structuredActivityNodeActivation_EOperation_putPinValues_OutputPin_Value->setUpperBound(1);
	m_structuredActivityNodeActivation_EOperation_putPinValues_OutputPin_Value->setUnique(true);
	m_structuredActivityNodeActivation_EOperation_putPinValues_OutputPin_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuredActivityNodeActivation_EOperation_putPinValues_OutputPin_Value);
		parameter->setName("pin");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuredActivityNodeActivation_EOperation_putPinValues_OutputPin_Value);
		parameter->setName("values");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredActivityNodeActivation_EOperation_resume->setEType(nullptr);
	m_structuredActivityNodeActivation_EOperation_resume->setName("resume");
	m_structuredActivityNodeActivation_EOperation_resume->setLowerBound(1);
	m_structuredActivityNodeActivation_EOperation_resume->setUpperBound(1);
	m_structuredActivityNodeActivation_EOperation_resume->setUnique(true);
	m_structuredActivityNodeActivation_EOperation_resume->setOrdered(false);
	
	
	m_structuredActivityNodeActivation_EOperation_terminate->setEType(nullptr);
	m_structuredActivityNodeActivation_EOperation_terminate->setName("terminate");
	m_structuredActivityNodeActivation_EOperation_terminate->setLowerBound(1);
	m_structuredActivityNodeActivation_EOperation_terminate->setUpperBound(1);
	m_structuredActivityNodeActivation_EOperation_terminate->setUnique(true);
	m_structuredActivityNodeActivation_EOperation_terminate->setOrdered(false);
	
	
	m_structuredActivityNodeActivation_EOperation_terminateAll->setEType(nullptr);
	m_structuredActivityNodeActivation_EOperation_terminateAll->setName("terminateAll");
	m_structuredActivityNodeActivation_EOperation_terminateAll->setLowerBound(1);
	m_structuredActivityNodeActivation_EOperation_terminateAll->setUpperBound(1);
	m_structuredActivityNodeActivation_EOperation_terminateAll->setUnique(true);
	m_structuredActivityNodeActivation_EOperation_terminateAll->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeStructuredValueContent()
{
	m_structuredValue_EClass->setInstanceClass(nullptr);
	m_structuredValue_EClass->setName("StructuredValue");
	m_structuredValue_EClass->setAbstract(true);
	m_structuredValue_EClass->setInterface(false);
	
	
	
	m_structuredValue_EOperation_assignFeatureValue_StructuralFeature_EInt->setEType(nullptr);
	m_structuredValue_EOperation_assignFeatureValue_StructuralFeature_EInt->setName("assignFeatureValue");
	m_structuredValue_EOperation_assignFeatureValue_StructuralFeature_EInt->setLowerBound(1);
	m_structuredValue_EOperation_assignFeatureValue_StructuralFeature_EInt->setUpperBound(1);
	m_structuredValue_EOperation_assignFeatureValue_StructuralFeature_EInt->setUnique(true);
	m_structuredValue_EOperation_assignFeatureValue_StructuralFeature_EInt->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuredValue_EOperation_assignFeatureValue_StructuralFeature_EInt);
		parameter->setName("feature");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuredValue_EOperation_assignFeatureValue_StructuralFeature_EInt);
		parameter->setName("values");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuredValue_EOperation_assignFeatureValue_StructuralFeature_EInt);
		parameter->setName("position");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredValue_EOperation_createFeatureValues->setEType(nullptr);
	m_structuredValue_EOperation_createFeatureValues->setName("createFeatureValues");
	m_structuredValue_EOperation_createFeatureValues->setLowerBound(0);
	m_structuredValue_EOperation_createFeatureValues->setUpperBound(1);
	m_structuredValue_EOperation_createFeatureValues->setUnique(true);
	m_structuredValue_EOperation_createFeatureValues->setOrdered(true);
	
	
	m_structuredValue_EOperation_retrieveFeatureValue_StructuralFeature->setEType(getFeatureValue_EClass());
	m_structuredValue_EOperation_retrieveFeatureValue_StructuralFeature->setName("retrieveFeatureValue");
	m_structuredValue_EOperation_retrieveFeatureValue_StructuralFeature->setLowerBound(1);
	m_structuredValue_EOperation_retrieveFeatureValue_StructuralFeature->setUpperBound(1);
	m_structuredValue_EOperation_retrieveFeatureValue_StructuralFeature->setUnique(true);
	m_structuredValue_EOperation_retrieveFeatureValue_StructuralFeature->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuredValue_EOperation_retrieveFeatureValue_StructuralFeature);
		parameter->setName("feature");
		parameter->setEType(uml::UmlPackage::eInstance()->getStructuralFeature_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredValue_EOperation_retrieveFeatureValues->setEType(getFeatureValue_EClass());
	m_structuredValue_EOperation_retrieveFeatureValues->setName("retrieveFeatureValues");
	m_structuredValue_EOperation_retrieveFeatureValues->setLowerBound(0);
	m_structuredValue_EOperation_retrieveFeatureValues->setUpperBound(-1);
	m_structuredValue_EOperation_retrieveFeatureValues->setUnique(true);
	m_structuredValue_EOperation_retrieveFeatureValues->setOrdered(false);
	
	
	m_structuredValue_EOperation_specify->setEType(uml::UmlPackage::eInstance()->getValueSpecification_EClass());
	m_structuredValue_EOperation_specify->setName("specify");
	m_structuredValue_EOperation_specify->setLowerBound(1);
	m_structuredValue_EOperation_specify->setUpperBound(1);
	m_structuredValue_EOperation_specify->setUnique(true);
	m_structuredValue_EOperation_specify->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeTestIdentityActionActivationContent()
{
	m_testIdentityActionActivation_EClass->setInstanceClass(nullptr);
	m_testIdentityActionActivation_EClass->setName("TestIdentityActionActivation");
	m_testIdentityActionActivation_EClass->setAbstract(false);
	m_testIdentityActionActivation_EClass->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeTokenContent()
{
	m_token_EClass->setInstanceClass(nullptr);
	m_token_EClass->setName("Token");
	m_token_EClass->setAbstract(true);
	m_token_EClass->setInterface(false);
	
	m_token_EAttribute_withdrawn = getToken_EAttribute_withdrawn();
	m_token_EAttribute_withdrawn->setName("withdrawn");
	m_token_EAttribute_withdrawn->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_token_EAttribute_withdrawn->setLowerBound(0);
	m_token_EAttribute_withdrawn->setUpperBound(1);
	m_token_EAttribute_withdrawn->setTransient(false);
	m_token_EAttribute_withdrawn->setVolatile(false);
	m_token_EAttribute_withdrawn->setChangeable(true);
	m_token_EAttribute_withdrawn->setUnsettable(false);
	m_token_EAttribute_withdrawn->setUnique(true);
	m_token_EAttribute_withdrawn->setDerived(false);
	m_token_EAttribute_withdrawn->setOrdered(true);
	m_token_EAttribute_withdrawn->setID(false);
	{
		std::string defaultValue = "true";
		if (!defaultValue.empty())
		{
		   m_token_EAttribute_withdrawn->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_token_EReference_holder->setName("holder");
	m_token_EReference_holder->setEType(getActivityNodeActivation_EClass());
	m_token_EReference_holder->setLowerBound(0);
	m_token_EReference_holder->setUpperBound(1);
	m_token_EReference_holder->setTransient(false);
	m_token_EReference_holder->setVolatile(false);
	m_token_EReference_holder->setChangeable(true);
	m_token_EReference_holder->setUnsettable(false);
	m_token_EReference_holder->setUnique(true);
	m_token_EReference_holder->setDerived(false);
	m_token_EReference_holder->setOrdered(false);
	m_token_EReference_holder->setContainment(false);
	m_token_EReference_holder->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_token_EReference_holder->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getActivityNodeActivation_EReference_heldTokens();
		if (otherEnd != nullptr)
	    {
	   		m_token_EReference_holder->setEOpposite(otherEnd);
	    }
	}
	
	m_token_EOperation_equals_Token->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_token_EOperation_equals_Token->setName("equals");
	m_token_EOperation_equals_Token->setLowerBound(1);
	m_token_EOperation_equals_Token->setUpperBound(1);
	m_token_EOperation_equals_Token->setUnique(true);
	m_token_EOperation_equals_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_token_EOperation_equals_Token);
		parameter->setName("other");
		parameter->setEType(getToken_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_token_EOperation_getValue->setEType(getValue_EClass());
	m_token_EOperation_getValue->setName("getValue");
	m_token_EOperation_getValue->setLowerBound(0);
	m_token_EOperation_getValue->setUpperBound(1);
	m_token_EOperation_getValue->setUnique(true);
	m_token_EOperation_getValue->setOrdered(false);
	
	
	m_token_EOperation_isControl->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_token_EOperation_isControl->setName("isControl");
	m_token_EOperation_isControl->setLowerBound(1);
	m_token_EOperation_isControl->setUpperBound(1);
	m_token_EOperation_isControl->setUnique(true);
	m_token_EOperation_isControl->setOrdered(false);
	
	
	m_token_EOperation_transfer_ActivityNodeActivation->setEType(getToken_EClass());
	m_token_EOperation_transfer_ActivityNodeActivation->setName("transfer");
	m_token_EOperation_transfer_ActivityNodeActivation->setLowerBound(1);
	m_token_EOperation_transfer_ActivityNodeActivation->setUpperBound(1);
	m_token_EOperation_transfer_ActivityNodeActivation->setUnique(true);
	m_token_EOperation_transfer_ActivityNodeActivation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_token_EOperation_transfer_ActivityNodeActivation);
		parameter->setName("holder");
		parameter->setEType(getActivityNodeActivation_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_token_EOperation_withdraw->setEType(nullptr);
	m_token_EOperation_withdraw->setName("withdraw");
	m_token_EOperation_withdraw->setLowerBound(1);
	m_token_EOperation_withdraw->setUpperBound(1);
	m_token_EOperation_withdraw->setUnique(true);
	m_token_EOperation_withdraw->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeTokenSetContent()
{
	m_tokenSet_EClass->setInstanceClass(nullptr);
	m_tokenSet_EClass->setName("TokenSet");
	m_tokenSet_EClass->setAbstract(false);
	m_tokenSet_EClass->setInterface(false);
	
	
	m_tokenSet_EReference_tokens->setName("tokens");
	m_tokenSet_EReference_tokens->setEType(getToken_EClass());
	m_tokenSet_EReference_tokens->setLowerBound(0);
	m_tokenSet_EReference_tokens->setUpperBound(-1);
	m_tokenSet_EReference_tokens->setTransient(false);
	m_tokenSet_EReference_tokens->setVolatile(false);
	m_tokenSet_EReference_tokens->setChangeable(true);
	m_tokenSet_EReference_tokens->setUnsettable(false);
	m_tokenSet_EReference_tokens->setUnique(true);
	m_tokenSet_EReference_tokens->setDerived(false);
	m_tokenSet_EReference_tokens->setOrdered(false);
	m_tokenSet_EReference_tokens->setContainment(false);
	m_tokenSet_EReference_tokens->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_tokenSet_EReference_tokens->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_tokenSet_EReference_tokens->setEOpposite(otherEnd);
	    }
	}
	
	
}

void FUMLPackageImpl::initializeUnlimitedNaturalValueContent()
{
	m_unlimitedNaturalValue_EClass->setInstanceClass(nullptr);
	m_unlimitedNaturalValue_EClass->setName("UnlimitedNaturalValue");
	m_unlimitedNaturalValue_EClass->setAbstract(false);
	m_unlimitedNaturalValue_EClass->setInterface(false);
	
	m_unlimitedNaturalValue_EAttribute_value = getUnlimitedNaturalValue_EAttribute_value();
	m_unlimitedNaturalValue_EAttribute_value->setName("value");
	m_unlimitedNaturalValue_EAttribute_value->setEType(ecore::EcorePackage::eInstance()->getEInt_EDataType());
	m_unlimitedNaturalValue_EAttribute_value->setLowerBound(1);
	m_unlimitedNaturalValue_EAttribute_value->setUpperBound(1);
	m_unlimitedNaturalValue_EAttribute_value->setTransient(false);
	m_unlimitedNaturalValue_EAttribute_value->setVolatile(false);
	m_unlimitedNaturalValue_EAttribute_value->setChangeable(true);
	m_unlimitedNaturalValue_EAttribute_value->setUnsettable(false);
	m_unlimitedNaturalValue_EAttribute_value->setUnique(true);
	m_unlimitedNaturalValue_EAttribute_value->setDerived(false);
	m_unlimitedNaturalValue_EAttribute_value->setOrdered(false);
	m_unlimitedNaturalValue_EAttribute_value->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_unlimitedNaturalValue_EAttribute_value->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	m_unlimitedNaturalValue_EOperation_equals_Value->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_unlimitedNaturalValue_EOperation_equals_Value->setName("equals");
	m_unlimitedNaturalValue_EOperation_equals_Value->setLowerBound(1);
	m_unlimitedNaturalValue_EOperation_equals_Value->setUpperBound(1);
	m_unlimitedNaturalValue_EOperation_equals_Value->setUnique(true);
	m_unlimitedNaturalValue_EOperation_equals_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_unlimitedNaturalValue_EOperation_equals_Value);
		parameter->setName("otherValue");
		parameter->setEType(getValue_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_unlimitedNaturalValue_EOperation_specify->setEType(uml::UmlPackage::eInstance()->getValueSpecification_EClass());
	m_unlimitedNaturalValue_EOperation_specify->setName("specify");
	m_unlimitedNaturalValue_EOperation_specify->setLowerBound(1);
	m_unlimitedNaturalValue_EOperation_specify->setUpperBound(1);
	m_unlimitedNaturalValue_EOperation_specify->setUnique(true);
	m_unlimitedNaturalValue_EOperation_specify->setOrdered(false);
	
	
	m_unlimitedNaturalValue_EOperation_toString->setEType(ecore::EcorePackage::eInstance()->getEString_EDataType());
	m_unlimitedNaturalValue_EOperation_toString->setName("toString");
	m_unlimitedNaturalValue_EOperation_toString->setLowerBound(1);
	m_unlimitedNaturalValue_EOperation_toString->setUpperBound(1);
	m_unlimitedNaturalValue_EOperation_toString->setUnique(true);
	m_unlimitedNaturalValue_EOperation_toString->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeValueContent()
{
	m_value_EClass->setInstanceClass(nullptr);
	m_value_EClass->setName("Value");
	m_value_EClass->setAbstract(true);
	m_value_EClass->setInterface(false);
	
	
	
	m_value_EOperation_equals_Value->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_value_EOperation_equals_Value->setName("equals");
	m_value_EOperation_equals_Value->setLowerBound(1);
	m_value_EOperation_equals_Value->setUpperBound(1);
	m_value_EOperation_equals_Value->setUnique(true);
	m_value_EOperation_equals_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_value_EOperation_equals_Value);
		parameter->setName("otherValue");
		parameter->setEType(getValue_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_value_EOperation_getTypes->setEType(uml::UmlPackage::eInstance()->getClassifier_EClass());
	m_value_EOperation_getTypes->setName("getTypes");
	m_value_EOperation_getTypes->setLowerBound(0);
	m_value_EOperation_getTypes->setUpperBound(-1);
	m_value_EOperation_getTypes->setUnique(true);
	m_value_EOperation_getTypes->setOrdered(false);
	
	
	m_value_EOperation_hasTypes_Classifier->setEType(ecore::EcorePackage::eInstance()->getEBoolean_EDataType());
	m_value_EOperation_hasTypes_Classifier->setName("hasTypes");
	m_value_EOperation_hasTypes_Classifier->setLowerBound(1);
	m_value_EOperation_hasTypes_Classifier->setUpperBound(1);
	m_value_EOperation_hasTypes_Classifier->setUnique(true);
	m_value_EOperation_hasTypes_Classifier->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_value_EOperation_hasTypes_Classifier);
		parameter->setName("type");
		parameter->setEType(uml::UmlPackage::eInstance()->getClassifier_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_value_EOperation_objectId->setEType(ecore::EcorePackage::eInstance()->getEString_EDataType());
	m_value_EOperation_objectId->setName("objectId");
	m_value_EOperation_objectId->setLowerBound(1);
	m_value_EOperation_objectId->setUpperBound(1);
	m_value_EOperation_objectId->setUnique(true);
	m_value_EOperation_objectId->setOrdered(false);
	
	
	m_value_EOperation_specify->setEType(uml::UmlPackage::eInstance()->getValueSpecification_EClass());
	m_value_EOperation_specify->setName("specify");
	m_value_EOperation_specify->setLowerBound(1);
	m_value_EOperation_specify->setUpperBound(1);
	m_value_EOperation_specify->setUnique(true);
	m_value_EOperation_specify->setOrdered(false);
	
	
	m_value_EOperation_toString->setEType(ecore::EcorePackage::eInstance()->getEString_EDataType());
	m_value_EOperation_toString->setName("toString");
	m_value_EOperation_toString->setLowerBound(1);
	m_value_EOperation_toString->setUpperBound(1);
	m_value_EOperation_toString->setUnique(true);
	m_value_EOperation_toString->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeValueSpecificActionActivationContent()
{
	m_valueSpecificActionActivation_EClass->setInstanceClass(nullptr);
	m_valueSpecificActionActivation_EClass->setName("ValueSpecificActionActivation");
	m_valueSpecificActionActivation_EClass->setAbstract(false);
	m_valueSpecificActionActivation_EClass->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeValuesContent()
{
	m_values_EClass->setInstanceClass(nullptr);
	m_values_EClass->setName("Values");
	m_values_EClass->setAbstract(false);
	m_values_EClass->setInterface(false);
	
	
	m_values_EReference_values->setName("values");
	m_values_EReference_values->setEType(getValue_EClass());
	m_values_EReference_values->setLowerBound(0);
	m_values_EReference_values->setUpperBound(-1);
	m_values_EReference_values->setTransient(false);
	m_values_EReference_values->setVolatile(false);
	m_values_EReference_values->setChangeable(true);
	m_values_EReference_values->setUnsettable(false);
	m_values_EReference_values->setUnique(true);
	m_values_EReference_values->setDerived(false);
	m_values_EReference_values->setOrdered(false);
	m_values_EReference_values->setContainment(false);
	m_values_EReference_values->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_values_EReference_values->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_values_EReference_values->setEOpposite(otherEnd);
	    }
	}
	
	
}

void FUMLPackageImpl::initializeWriteLinkActionActivationContent()
{
	m_writeLinkActionActivation_EClass->setInstanceClass(nullptr);
	m_writeLinkActionActivation_EClass->setName("WriteLinkActionActivation");
	m_writeLinkActionActivation_EClass->setAbstract(true);
	m_writeLinkActionActivation_EClass->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeWriteStructuralFeatureActionActivationContent()
{
	m_writeStructuralFeatureActionActivation_EClass->setInstanceClass(nullptr);
	m_writeStructuralFeatureActionActivation_EClass->setName("WriteStructuralFeatureActionActivation");
	m_writeStructuralFeatureActionActivation_EClass->setAbstract(true);
	m_writeStructuralFeatureActionActivation_EClass->setInterface(false);
	
	
	
	m_writeStructuralFeatureActionActivation_EOperation_position_Value_EInt->setEType(ecore::EcorePackage::eInstance()->getEInt_EDataType());
	m_writeStructuralFeatureActionActivation_EOperation_position_Value_EInt->setName("position");
	m_writeStructuralFeatureActionActivation_EOperation_position_Value_EInt->setLowerBound(1);
	m_writeStructuralFeatureActionActivation_EOperation_position_Value_EInt->setUpperBound(1);
	m_writeStructuralFeatureActionActivation_EOperation_position_Value_EInt->setUnique(true);
	m_writeStructuralFeatureActionActivation_EOperation_position_Value_EInt->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_writeStructuralFeatureActionActivation_EOperation_position_Value_EInt);
		parameter->setName("value");
		parameter->setEType(getValue_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_writeStructuralFeatureActionActivation_EOperation_position_Value_EInt);
		parameter->setName("list");
		parameter->setEType(getValue_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_writeStructuralFeatureActionActivation_EOperation_position_Value_EInt);
		parameter->setName("startAt");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEInt_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializePackageEDataTypes()
{
	
}

// Begin Class AcceptEventActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getAcceptEventActionActivation_EClass() const
{
	return m_acceptEventActionActivation_EClass;
}

std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getAcceptEventActionActivation_EAttribute_waiting() const
{
	return m_acceptEventActionActivation_EAttribute_waiting;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getAcceptEventActionActivation_EReference_eventAccepter() const
{
	return m_acceptEventActionActivation_EReference_eventAccepter;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getAcceptEventActionActivation_EOperation_accept_SignalInstance() const
{
	return m_acceptEventActionActivation_EOperation_accept_SignalInstance;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getAcceptEventActionActivation_EOperation_match_SignalInstance() const
{
	return m_acceptEventActionActivation_EOperation_match_SignalInstance;
}

// End Class AcceptEventActionActivation

// Begin Class AcceptEventActionEventAccepter
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getAcceptEventActionEventAccepter_EClass() const
{
	return m_acceptEventActionEventAccepter_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getAcceptEventActionEventAccepter_EReference_actionActivation() const
{
	return m_acceptEventActionEventAccepter_EReference_actionActivation;
}


// End Class AcceptEventActionEventAccepter

// Begin Class ActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getActionActivation_EClass() const
{
	return m_actionActivation_EClass;
}

std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getActionActivation_EAttribute_firing() const
{
	return m_actionActivation_EAttribute_firing;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActionActivation_EReference_pinActivation() const
{
	return m_actionActivation_EReference_pinActivation;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_EOperation_addOutgoingEdge_ActivityEdgeInstance() const
{
	return m_actionActivation_EOperation_addOutgoingEdge_ActivityEdgeInstance;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_EOperation_addPinActivation_PinActivation() const
{
	return m_actionActivation_EOperation_addPinActivation_PinActivation;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_EOperation_completeAction() const
{
	return m_actionActivation_EOperation_completeAction;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_EOperation_createNodeActivations() const
{
	return m_actionActivation_EOperation_createNodeActivations;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_EOperation_doAction() const
{
	return m_actionActivation_EOperation_doAction;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_EOperation_fire_Token() const
{
	return m_actionActivation_EOperation_fire_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_EOperation_getTokens_InputPin() const
{
	return m_actionActivation_EOperation_getTokens_InputPin;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_EOperation_isFirng() const
{
	return m_actionActivation_EOperation_isFirng;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_EOperation_isReady() const
{
	return m_actionActivation_EOperation_isReady;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_EOperation_isSourceFor_ActivityEdgeInstance() const
{
	return m_actionActivation_EOperation_isSourceFor_ActivityEdgeInstance;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_EOperation_makeBooleanValue_EBoolean() const
{
	return m_actionActivation_EOperation_makeBooleanValue_EBoolean;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_EOperation_putToken_OutputPin_Value() const
{
	return m_actionActivation_EOperation_putToken_OutputPin_Value;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_EOperation_putTokens_OutputPin_Value() const
{
	return m_actionActivation_EOperation_putTokens_OutputPin_Value;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_EOperation_retrievePinActivation_Pin() const
{
	return m_actionActivation_EOperation_retrievePinActivation_Pin;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_EOperation_run() const
{
	return m_actionActivation_EOperation_run;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_EOperation_sendOffers() const
{
	return m_actionActivation_EOperation_sendOffers;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_EOperation_takeOfferedTokens() const
{
	return m_actionActivation_EOperation_takeOfferedTokens;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_EOperation_takeTokens_InputPin() const
{
	return m_actionActivation_EOperation_takeTokens_InputPin;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_EOperation_terminate() const
{
	return m_actionActivation_EOperation_terminate;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_EOperation_valueParticipatesInLink_Value_Link() const
{
	return m_actionActivation_EOperation_valueParticipatesInLink_Value_Link;
}

// End Class ActionActivation

// Begin Class ActivityEdgeInstance
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getActivityEdgeInstance_EClass() const
{
	return m_activityEdgeInstance_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityEdgeInstance_EReference_edge() const
{
	return m_activityEdgeInstance_EReference_edge;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityEdgeInstance_EReference_group() const
{
	return m_activityEdgeInstance_EReference_group;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityEdgeInstance_EReference_offers() const
{
	return m_activityEdgeInstance_EReference_offers;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityEdgeInstance_EReference_source() const
{
	return m_activityEdgeInstance_EReference_source;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityEdgeInstance_EReference_target() const
{
	return m_activityEdgeInstance_EReference_target;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityEdgeInstance_EOperation_countOfferedValue() const
{
	return m_activityEdgeInstance_EOperation_countOfferedValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityEdgeInstance_EOperation_getOfferedTokens() const
{
	return m_activityEdgeInstance_EOperation_getOfferedTokens;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityEdgeInstance_EOperation_hasOffer() const
{
	return m_activityEdgeInstance_EOperation_hasOffer;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityEdgeInstance_EOperation_sendOffer_Token() const
{
	return m_activityEdgeInstance_EOperation_sendOffer_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityEdgeInstance_EOperation_takeOfferedTokens() const
{
	return m_activityEdgeInstance_EOperation_takeOfferedTokens;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityEdgeInstance_EOperation_takeOfferedTokens_EInt() const
{
	return m_activityEdgeInstance_EOperation_takeOfferedTokens_EInt;
}

// End Class ActivityEdgeInstance

// Begin Class ActivityExecution
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getActivityExecution_EClass() const
{
	return m_activityExecution_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityExecution_EReference_activationGroup() const
{
	return m_activityExecution_EReference_activationGroup;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityExecution_EOperation_execute() const
{
	return m_activityExecution_EOperation_execute;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityExecution_EOperation_new_() const
{
	return m_activityExecution_EOperation_new_;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityExecution_EOperation_terminate() const
{
	return m_activityExecution_EOperation_terminate;
}

// End Class ActivityExecution

// Begin Class ActivityFinalNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getActivityFinalNodeActivation_EClass() const
{
	return m_activityFinalNodeActivation_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityFinalNodeActivation_EOperation_fire_Token() const
{
	return m_activityFinalNodeActivation_EOperation_fire_Token;
}

// End Class ActivityFinalNodeActivation

// Begin Class ActivityNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getActivityNodeActivation_EClass() const
{
	return m_activityNodeActivation_EClass;
}

std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getActivityNodeActivation_EAttribute_running() const
{
	return m_activityNodeActivation_EAttribute_running;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityNodeActivation_EReference_group() const
{
	return m_activityNodeActivation_EReference_group;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityNodeActivation_EReference_heldTokens() const
{
	return m_activityNodeActivation_EReference_heldTokens;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityNodeActivation_EReference_incomingEdges() const
{
	return m_activityNodeActivation_EReference_incomingEdges;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityNodeActivation_EReference_node() const
{
	return m_activityNodeActivation_EReference_node;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityNodeActivation_EReference_outgoingEdges() const
{
	return m_activityNodeActivation_EReference_outgoingEdges;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_EOperation_addIncomingEdge_ActivityEdgeInstance() const
{
	return m_activityNodeActivation_EOperation_addIncomingEdge_ActivityEdgeInstance;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_EOperation_addOutgoingEdge_ActivityEdgeInstance() const
{
	return m_activityNodeActivation_EOperation_addOutgoingEdge_ActivityEdgeInstance;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_EOperation_addToken_Token() const
{
	return m_activityNodeActivation_EOperation_addToken_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_EOperation_addTokens_Token() const
{
	return m_activityNodeActivation_EOperation_addTokens_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_EOperation_clearTokens() const
{
	return m_activityNodeActivation_EOperation_clearTokens;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_EOperation_createEdgeInstances() const
{
	return m_activityNodeActivation_EOperation_createEdgeInstances;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_EOperation_createNodeActivations() const
{
	return m_activityNodeActivation_EOperation_createNodeActivations;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_EOperation_fire_Token() const
{
	return m_activityNodeActivation_EOperation_fire_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_EOperation_getActivityExecution() const
{
	return m_activityNodeActivation_EOperation_getActivityExecution;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_EOperation_getExecutionContext() const
{
	return m_activityNodeActivation_EOperation_getExecutionContext;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_EOperation_getExecutionLocus() const
{
	return m_activityNodeActivation_EOperation_getExecutionLocus;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_EOperation_getNodeActivation_ActivityNode() const
{
	return m_activityNodeActivation_EOperation_getNodeActivation_ActivityNode;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_EOperation_getRunning() const
{
	return m_activityNodeActivation_EOperation_getRunning;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_EOperation_getTokens() const
{
	return m_activityNodeActivation_EOperation_getTokens;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_EOperation_isReady() const
{
	return m_activityNodeActivation_EOperation_isReady;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_EOperation_isSourceFor_ActivityEdgeInstance() const
{
	return m_activityNodeActivation_EOperation_isSourceFor_ActivityEdgeInstance;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_EOperation_recieveOffer() const
{
	return m_activityNodeActivation_EOperation_recieveOffer;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_EOperation_removeToken_Token() const
{
	return m_activityNodeActivation_EOperation_removeToken_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_EOperation_resume() const
{
	return m_activityNodeActivation_EOperation_resume;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_EOperation_run() const
{
	return m_activityNodeActivation_EOperation_run;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_EOperation_sendOffers_Token() const
{
	return m_activityNodeActivation_EOperation_sendOffers_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_EOperation_suspend() const
{
	return m_activityNodeActivation_EOperation_suspend;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_EOperation_takeOfferedTokens() const
{
	return m_activityNodeActivation_EOperation_takeOfferedTokens;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_EOperation_takeTokens() const
{
	return m_activityNodeActivation_EOperation_takeTokens;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_EOperation_terminate() const
{
	return m_activityNodeActivation_EOperation_terminate;
}

// End Class ActivityNodeActivation

// Begin Class ActivityNodeActivationGroup
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getActivityNodeActivationGroup_EClass() const
{
	return m_activityNodeActivationGroup_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityNodeActivationGroup_EReference_activityExecution() const
{
	return m_activityNodeActivationGroup_EReference_activityExecution;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityNodeActivationGroup_EReference_containingNodeActivation() const
{
	return m_activityNodeActivationGroup_EReference_containingNodeActivation;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityNodeActivationGroup_EReference_edgeInstances() const
{
	return m_activityNodeActivationGroup_EReference_edgeInstances;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityNodeActivationGroup_EReference_nodeActivations() const
{
	return m_activityNodeActivationGroup_EReference_nodeActivations;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityNodeActivationGroup_EReference_suspendedActivations() const
{
	return m_activityNodeActivationGroup_EReference_suspendedActivations;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup_EOperation_activate_ActivityNode_ActivityEdge() const
{
	return m_activityNodeActivationGroup_EOperation_activate_ActivityNode_ActivityEdge;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup_EOperation_addEdgeInstance_ActivityEdgeInstance() const
{
	return m_activityNodeActivationGroup_EOperation_addEdgeInstance_ActivityEdgeInstance;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup_EOperation_addNodeActivation_ActivityNodeActivation() const
{
	return m_activityNodeActivationGroup_EOperation_addNodeActivation_ActivityNodeActivation;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup_EOperation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation() const
{
	return m_activityNodeActivationGroup_EOperation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup_EOperation_createEdgeInstance_ActivityEdge() const
{
	return m_activityNodeActivationGroup_EOperation_createEdgeInstance_ActivityEdge;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup_EOperation_createNodeActivation_ActivityNode() const
{
	return m_activityNodeActivationGroup_EOperation_createNodeActivation_ActivityNode;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup_EOperation_createNodeActivations_ActivityNode() const
{
	return m_activityNodeActivationGroup_EOperation_createNodeActivations_ActivityNode;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup_EOperation_getNodeActivation_ActivityNode() const
{
	return m_activityNodeActivationGroup_EOperation_getNodeActivation_ActivityNode;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup_EOperation_getOutputParameterNodeActivations() const
{
	return m_activityNodeActivationGroup_EOperation_getOutputParameterNodeActivations;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup_EOperation_hasSourceFor_ActivityEdgeInstance() const
{
	return m_activityNodeActivationGroup_EOperation_hasSourceFor_ActivityEdgeInstance;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup_EOperation_isSuspended() const
{
	return m_activityNodeActivationGroup_EOperation_isSuspended;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup_EOperation_resume_ActivityNodeActivation() const
{
	return m_activityNodeActivationGroup_EOperation_resume_ActivityNodeActivation;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup_EOperation_retrieveActivityExecution() const
{
	return m_activityNodeActivationGroup_EOperation_retrieveActivityExecution;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup_EOperation_run_ActivityNodeActivation() const
{
	return m_activityNodeActivationGroup_EOperation_run_ActivityNodeActivation;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup_EOperation_runNodes_ActivityNode() const
{
	return m_activityNodeActivationGroup_EOperation_runNodes_ActivityNode;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup_EOperation_suspend_ActivityNodeActivation() const
{
	return m_activityNodeActivationGroup_EOperation_suspend_ActivityNodeActivation;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup_EOperation_terminateAll() const
{
	return m_activityNodeActivationGroup_EOperation_terminateAll;
}

// End Class ActivityNodeActivationGroup

// Begin Class ActivityParameterNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getActivityParameterNodeActivation_EClass() const
{
	return m_activityParameterNodeActivation_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityParameterNodeActivation_EOperation_clearTokens() const
{
	return m_activityParameterNodeActivation_EOperation_clearTokens;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityParameterNodeActivation_EOperation_fire_Token() const
{
	return m_activityParameterNodeActivation_EOperation_fire_Token;
}

// End Class ActivityParameterNodeActivation

// Begin Class AddStructuralFeatureValueActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getAddStructuralFeatureValueActionActivation_EClass() const
{
	return m_addStructuralFeatureValueActionActivation_EClass;
}




// End Class AddStructuralFeatureValueActionActivation

// Begin Class BooleanValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getBooleanValue_EClass() const
{
	return m_booleanValue_EClass;
}

std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getBooleanValue_EAttribute_value() const
{
	return m_booleanValue_EAttribute_value;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getBooleanValue_EOperation_equals_Value() const
{
	return m_booleanValue_EOperation_equals_Value;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getBooleanValue_EOperation_specify() const
{
	return m_booleanValue_EOperation_specify;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getBooleanValue_EOperation_toString() const
{
	return m_booleanValue_EOperation_toString;
}

// End Class BooleanValue

// Begin Class CallActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getCallActionActivation_EClass() const
{
	return m_callActionActivation_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getCallActionActivation_EReference_callExecutions() const
{
	return m_callActionActivation_EReference_callExecutions;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallActionActivation_EOperation_doAction() const
{
	return m_callActionActivation_EOperation_doAction;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallActionActivation_EOperation_getCallExecution() const
{
	return m_callActionActivation_EOperation_getCallExecution;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallActionActivation_EOperation_removeCallExecution_Execution() const
{
	return m_callActionActivation_EOperation_removeCallExecution_Execution;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallActionActivation_EOperation_terminate() const
{
	return m_callActionActivation_EOperation_terminate;
}

// End Class CallActionActivation

// Begin Class CallBehaviorActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getCallBehaviorActionActivation_EClass() const
{
	return m_callBehaviorActionActivation_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallBehaviorActionActivation_EOperation_getCallExecution() const
{
	return m_callBehaviorActionActivation_EOperation_getCallExecution;
}

// End Class CallBehaviorActionActivation

// Begin Class CallOperationActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getCallOperationActionActivation_EClass() const
{
	return m_callOperationActionActivation_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallOperationActionActivation_EOperation_getCallExecution() const
{
	return m_callOperationActionActivation_EOperation_getCallExecution;
}

// End Class CallOperationActionActivation

// Begin Class CentralBufferNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getCentralBufferNodeActivation_EClass() const
{
	return m_centralBufferNodeActivation_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCentralBufferNodeActivation_EOperation_fire_Token() const
{
	return m_centralBufferNodeActivation_EOperation_fire_Token;
}

// End Class CentralBufferNodeActivation

// Begin Class ChoiceStrategy
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getChoiceStrategy_EClass() const
{
	return m_choiceStrategy_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getChoiceStrategy_EOperation_choose_EInt() const
{
	return m_choiceStrategy_EOperation_choose_EInt;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getChoiceStrategy_EOperation_retrieveName() const
{
	return m_choiceStrategy_EOperation_retrieveName;
}

// End Class ChoiceStrategy

// Begin Class ClassifierBehaviorExecution
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getClassifierBehaviorExecution_EClass() const
{
	return m_classifierBehaviorExecution_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getClassifierBehaviorExecution_EReference_classifier() const
{
	return m_classifierBehaviorExecution_EReference_classifier;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getClassifierBehaviorExecution_EReference_execution() const
{
	return m_classifierBehaviorExecution_EReference_execution;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getClassifierBehaviorExecution_EReference_objectActivation() const
{
	return m_classifierBehaviorExecution_EReference_objectActivation;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getClassifierBehaviorExecution_EOperation__startObjectBehavior() const
{
	return m_classifierBehaviorExecution_EOperation__startObjectBehavior;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getClassifierBehaviorExecution_EOperation_execute_Class_ParameterValue() const
{
	return m_classifierBehaviorExecution_EOperation_execute_Class_ParameterValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getClassifierBehaviorExecution_EOperation_terminate() const
{
	return m_classifierBehaviorExecution_EOperation_terminate;
}

// End Class ClassifierBehaviorExecution

// Begin Class ClassifierBehaviorExecutionActivity
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getClassifierBehaviorExecutionActivity_EClass() const
{
	return m_classifierBehaviorExecutionActivity_EClass;
}




// End Class ClassifierBehaviorExecutionActivity

// Begin Class ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1_EClass() const
{
	return m_classifierBehaviorExecutionActivity_OwnedBehaviorActivity1_EClass;
}




// End Class ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1

// Begin Class ClauseActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getClauseActivation_EClass() const
{
	return m_clauseActivation_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getClauseActivation_EReference_clause() const
{
	return m_clauseActivation_EReference_clause;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getClauseActivation_EReference_conditionalNodeActivation() const
{
	return m_clauseActivation_EReference_conditionalNodeActivation;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getClauseActivation_EOperation_getDecision() const
{
	return m_clauseActivation_EOperation_getDecision;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getClauseActivation_EOperation_getPredecessors() const
{
	return m_clauseActivation_EOperation_getPredecessors;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getClauseActivation_EOperation_getSuccessors() const
{
	return m_clauseActivation_EOperation_getSuccessors;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getClauseActivation_EOperation_isReady() const
{
	return m_clauseActivation_EOperation_isReady;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getClauseActivation_EOperation_recieveControl() const
{
	return m_clauseActivation_EOperation_recieveControl;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getClauseActivation_EOperation_runTest() const
{
	return m_clauseActivation_EOperation_runTest;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getClauseActivation_EOperation_selectBody() const
{
	return m_clauseActivation_EOperation_selectBody;
}

// End Class ClauseActivation

// Begin Class ClearAssociationActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getClearAssociationActionActivation_EClass() const
{
	return m_clearAssociationActionActivation_EClass;
}




// End Class ClearAssociationActionActivation

// Begin Class ClearStructuralFeatureActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getClearStructuralFeatureActionActivation_EClass() const
{
	return m_clearStructuralFeatureActionActivation_EClass;
}




// End Class ClearStructuralFeatureActionActivation

// Begin Class CompoundValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getCompoundValue_EClass() const
{
	return m_compoundValue_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getCompoundValue_EReference_featureValues() const
{
	return m_compoundValue_EReference_featureValues;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCompoundValue_EOperation_assignFeatureValue_StructuralFeature_EInt() const
{
	return m_compoundValue_EOperation_assignFeatureValue_StructuralFeature_EInt;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCompoundValue_EOperation_equals_Value() const
{
	return m_compoundValue_EOperation_equals_Value;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCompoundValue_EOperation_removeFeatureValues_Classifier() const
{
	return m_compoundValue_EOperation_removeFeatureValues_Classifier;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCompoundValue_EOperation_retrieveFeatureValue_StructuralFeature() const
{
	return m_compoundValue_EOperation_retrieveFeatureValue_StructuralFeature;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCompoundValue_EOperation_retrieveFeatureValues() const
{
	return m_compoundValue_EOperation_retrieveFeatureValues;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCompoundValue_EOperation_toString() const
{
	return m_compoundValue_EOperation_toString;
}

// End Class CompoundValue

// Begin Class ConditionalNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getConditionalNodeActivation_EClass() const
{
	return m_conditionalNodeActivation_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getConditionalNodeActivation_EReference_clauseActivations() const
{
	return m_conditionalNodeActivation_EReference_clauseActivations;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getConditionalNodeActivation_EReference_selectedClauses() const
{
	return m_conditionalNodeActivation_EReference_selectedClauses;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getConditionalNodeActivation_EOperation_getClauseActivation_Clause() const
{
	return m_conditionalNodeActivation_EOperation_getClauseActivation_Clause;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getConditionalNodeActivation_EOperation_runTest_Clause() const
{
	return m_conditionalNodeActivation_EOperation_runTest_Clause;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getConditionalNodeActivation_EOperation_selectBody_Clause() const
{
	return m_conditionalNodeActivation_EOperation_selectBody_Clause;
}

// End Class ConditionalNodeActivation

// Begin Class ControlNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getControlNodeActivation_EClass() const
{
	return m_controlNodeActivation_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getControlNodeActivation_EOperation_fire_Token() const
{
	return m_controlNodeActivation_EOperation_fire_Token;
}

// End Class ControlNodeActivation

// Begin Class ControlToken
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getControlToken_EClass() const
{
	return m_controlToken_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getControlToken_EOperation_equals_Token() const
{
	return m_controlToken_EOperation_equals_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getControlToken_EOperation_getValue() const
{
	return m_controlToken_EOperation_getValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getControlToken_EOperation_isControl() const
{
	return m_controlToken_EOperation_isControl;
}

// End Class ControlToken

// Begin Class CreateLinkActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getCreateLinkActionActivation_EClass() const
{
	return m_createLinkActionActivation_EClass;
}




// End Class CreateLinkActionActivation

// Begin Class CreateObjectActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getCreateObjectActionActivation_EClass() const
{
	return m_createObjectActionActivation_EClass;
}




// End Class CreateObjectActionActivation

// Begin Class DataStoreNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getDataStoreNodeActivation_EClass() const
{
	return m_dataStoreNodeActivation_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDataStoreNodeActivation_EOperation_addToken_Token() const
{
	return m_dataStoreNodeActivation_EOperation_addToken_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDataStoreNodeActivation_EOperation_removeToken_Token() const
{
	return m_dataStoreNodeActivation_EOperation_removeToken_Token;
}

// End Class DataStoreNodeActivation

// Begin Class DataValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getDataValue_EClass() const
{
	return m_dataValue_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getDataValue_EReference_type() const
{
	return m_dataValue_EReference_type;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDataValue_EOperation_getTypes() const
{
	return m_dataValue_EOperation_getTypes;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDataValue_EOperation_new_() const
{
	return m_dataValue_EOperation_new_;
}

// End Class DataValue

// Begin Class DecisionNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getDecisionNodeActivation_EClass() const
{
	return m_decisionNodeActivation_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getDecisionNodeActivation_EReference_decisionInputExecution() const
{
	return m_decisionNodeActivation_EReference_decisionInputExecution;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDecisionNodeActivation_EOperation_executeDecisionInputBehavior_Value_Value() const
{
	return m_decisionNodeActivation_EOperation_executeDecisionInputBehavior_Value_Value;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDecisionNodeActivation_EOperation_fire_Token() const
{
	return m_decisionNodeActivation_EOperation_fire_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDecisionNodeActivation_EOperation_getDecisionInputFlowInstance() const
{
	return m_decisionNodeActivation_EOperation_getDecisionInputFlowInstance;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDecisionNodeActivation_EOperation_getDecisionInputFlowValue() const
{
	return m_decisionNodeActivation_EOperation_getDecisionInputFlowValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDecisionNodeActivation_EOperation_getDecisionValues_Token() const
{
	return m_decisionNodeActivation_EOperation_getDecisionValues_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDecisionNodeActivation_EOperation_hasObjectFlowInput() const
{
	return m_decisionNodeActivation_EOperation_hasObjectFlowInput;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDecisionNodeActivation_EOperation_isReady() const
{
	return m_decisionNodeActivation_EOperation_isReady;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDecisionNodeActivation_EOperation_removeJoinedControlTokens_Token() const
{
	return m_decisionNodeActivation_EOperation_removeJoinedControlTokens_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDecisionNodeActivation_EOperation_takeOfferedTokens() const
{
	return m_decisionNodeActivation_EOperation_takeOfferedTokens;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDecisionNodeActivation_EOperation_terminate() const
{
	return m_decisionNodeActivation_EOperation_terminate;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDecisionNodeActivation_EOperation_test_ValueSpecification_Value() const
{
	return m_decisionNodeActivation_EOperation_test_ValueSpecification_Value;
}

// End Class DecisionNodeActivation

// Begin Class DestroyLinkActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getDestroyLinkActionActivation_EClass() const
{
	return m_destroyLinkActionActivation_EClass;
}




// End Class DestroyLinkActionActivation

// Begin Class DestroyObjectActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getDestroyObjectActionActivation_EClass() const
{
	return m_destroyObjectActionActivation_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDestroyObjectActionActivation_EOperation_destroyObject_Value_EBoolean() const
{
	return m_destroyObjectActionActivation_EOperation_destroyObject_Value_EBoolean;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDestroyObjectActionActivation_EOperation_objectIsComposite_Reference_Link() const
{
	return m_destroyObjectActionActivation_EOperation_objectIsComposite_Reference_Link;
}

// End Class DestroyObjectActionActivation

// Begin Class DispatchStrategy
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getDispatchStrategy_EClass() const
{
	return m_dispatchStrategy_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDispatchStrategy_EOperation_dispatch_Object_Operation() const
{
	return m_dispatchStrategy_EOperation_dispatch_Object_Operation;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDispatchStrategy_EOperation_retrieveMethod_Object_Operation() const
{
	return m_dispatchStrategy_EOperation_retrieveMethod_Object_Operation;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDispatchStrategy_EOperation_retrieveName() const
{
	return m_dispatchStrategy_EOperation_retrieveName;
}

// End Class DispatchStrategy

// Begin Class EnumerationValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getEnumerationValue_EClass() const
{
	return m_enumerationValue_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getEnumerationValue_EReference_literal() const
{
	return m_enumerationValue_EReference_literal;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getEnumerationValue_EReference_type() const
{
	return m_enumerationValue_EReference_type;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getEnumerationValue_EOperation_equals_Value() const
{
	return m_enumerationValue_EOperation_equals_Value;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getEnumerationValue_EOperation_getTypes() const
{
	return m_enumerationValue_EOperation_getTypes;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getEnumerationValue_EOperation_new_() const
{
	return m_enumerationValue_EOperation_new_;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getEnumerationValue_EOperation_specify() const
{
	return m_enumerationValue_EOperation_specify;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getEnumerationValue_EOperation_toString() const
{
	return m_enumerationValue_EOperation_toString;
}

// End Class EnumerationValue

// Begin Class Evaluation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getEvaluation_EClass() const
{
	return m_evaluation_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getEvaluation_EReference_locus() const
{
	return m_evaluation_EReference_locus;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getEvaluation_EReference_specification() const
{
	return m_evaluation_EReference_specification;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getEvaluation_EOperation_evaluate() const
{
	return m_evaluation_EOperation_evaluate;
}

// End Class Evaluation

// Begin Class EventAccepter
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getEventAccepter_EClass() const
{
	return m_eventAccepter_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getEventAccepter_EOperation_accept_SignalInstance() const
{
	return m_eventAccepter_EOperation_accept_SignalInstance;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getEventAccepter_EOperation_match_SignalInstance() const
{
	return m_eventAccepter_EOperation_match_SignalInstance;
}

// End Class EventAccepter

// Begin Class EventDispatchLoop
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getEventDispatchLoop_EClass() const
{
	return m_eventDispatchLoop_EClass;
}




// End Class EventDispatchLoop

// Begin Class Execution
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getExecution_EClass() const
{
	return m_execution_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExecution_EReference_context() const
{
	return m_execution_EReference_context;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExecution_EReference_parameterValues() const
{
	return m_execution_EReference_parameterValues;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecution_EOperation_execute() const
{
	return m_execution_EOperation_execute;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecution_EOperation_getBehavior() const
{
	return m_execution_EOperation_getBehavior;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecution_EOperation_getOutputParameterValues() const
{
	return m_execution_EOperation_getOutputParameterValues;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecution_EOperation_getParameterValue_Parameter() const
{
	return m_execution_EOperation_getParameterValue_Parameter;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecution_EOperation_new_() const
{
	return m_execution_EOperation_new_;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecution_EOperation_setParameterValue_ParameterValue() const
{
	return m_execution_EOperation_setParameterValue_ParameterValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecution_EOperation_terminate() const
{
	return m_execution_EOperation_terminate;
}

// End Class Execution

// Begin Class ExecutionFactory
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getExecutionFactory_EClass() const
{
	return m_executionFactory_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExecutionFactory_EReference_builtInTypes() const
{
	return m_executionFactory_EReference_builtInTypes;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExecutionFactory_EReference_locus() const
{
	return m_executionFactory_EReference_locus;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExecutionFactory_EReference_primitiveBehaviorPrototypes() const
{
	return m_executionFactory_EReference_primitiveBehaviorPrototypes;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExecutionFactory_EReference_strategies() const
{
	return m_executionFactory_EReference_strategies;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactory_EOperation_addBuiltInType_PrimitiveType() const
{
	return m_executionFactory_EOperation_addBuiltInType_PrimitiveType;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactory_EOperation_addPrimitiveBehaviorPrototype_OpaqueBehaviorExecution() const
{
	return m_executionFactory_EOperation_addPrimitiveBehaviorPrototype_OpaqueBehaviorExecution;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactory_EOperation_assignStrategy_SemanticStrategy() const
{
	return m_executionFactory_EOperation_assignStrategy_SemanticStrategy;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactory_EOperation_createEvaluation_ValueSpecification() const
{
	return m_executionFactory_EOperation_createEvaluation_ValueSpecification;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactory_EOperation_createExecution_Behavior_Object() const
{
	return m_executionFactory_EOperation_createExecution_Behavior_Object;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactory_EOperation_getBuiltInType_EString() const
{
	return m_executionFactory_EOperation_getBuiltInType_EString;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactory_EOperation_getStrategy_EString() const
{
	return m_executionFactory_EOperation_getStrategy_EString;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactory_EOperation_getStrategyIndex_EString() const
{
	return m_executionFactory_EOperation_getStrategyIndex_EString;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactory_EOperation_instantiateOpaqueBehaviorExecution_OpaqueBehavior() const
{
	return m_executionFactory_EOperation_instantiateOpaqueBehaviorExecution_OpaqueBehavior;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactory_EOperation_instantiateVisitor_Element() const
{
	return m_executionFactory_EOperation_instantiateVisitor_Element;
}

// End Class ExecutionFactory

// Begin Class ExecutionFactoryL1
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getExecutionFactoryL1_EClass() const
{
	return m_executionFactoryL1_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactoryL1_EOperation_instantiateVisitor_Element() const
{
	return m_executionFactoryL1_EOperation_instantiateVisitor_Element;
}

// End Class ExecutionFactoryL1

// Begin Class ExecutionFactoryL2
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getExecutionFactoryL2_EClass() const
{
	return m_executionFactoryL2_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactoryL2_EOperation_instantiateVisitor_Element() const
{
	return m_executionFactoryL2_EOperation_instantiateVisitor_Element;
}

// End Class ExecutionFactoryL2

// Begin Class ExecutionFactoryL3
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getExecutionFactoryL3_EClass() const
{
	return m_executionFactoryL3_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactoryL3_EOperation_instantiateVisitor_Element() const
{
	return m_executionFactoryL3_EOperation_instantiateVisitor_Element;
}

// End Class ExecutionFactoryL3

// Begin Class Executor
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getExecutor_EClass() const
{
	return m_executor_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExecutor_EReference_locus() const
{
	return m_executor_EReference_locus;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutor_EOperation_evaluate_ValueSpecification() const
{
	return m_executor_EOperation_evaluate_ValueSpecification;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutor_EOperation_execute_Behavior_ParameterValue() const
{
	return m_executor_EOperation_execute_Behavior_ParameterValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutor_EOperation_start_Class_ParameterValue() const
{
	return m_executor_EOperation_start_Class_ParameterValue;
}

// End Class Executor

// Begin Class ExpansionActivationGroup
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getExpansionActivationGroup_EClass() const
{
	return m_expansionActivationGroup_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExpansionActivationGroup_EReference_regionActivation() const
{
	return m_expansionActivationGroup_EReference_regionActivation;
}


// End Class ExpansionActivationGroup

// Begin Class ExpansionNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getExpansionNodeActivation_EClass() const
{
	return m_expansionNodeActivation_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExpansionNodeActivation_EOperation_getExpansionRegionActivation() const
{
	return m_expansionNodeActivation_EOperation_getExpansionRegionActivation;
}

// End Class ExpansionNodeActivation

// Begin Class ExpansionRegionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getExpansionRegionActivation_EClass() const
{
	return m_expansionRegionActivation_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExpansionRegionActivation_EReference_activationGroups() const
{
	return m_expansionRegionActivation_EReference_activationGroups;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExpansionRegionActivation_EReference_inputExpansionTokens() const
{
	return m_expansionRegionActivation_EReference_inputExpansionTokens;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExpansionRegionActivation_EReference_inputTokens() const
{
	return m_expansionRegionActivation_EReference_inputTokens;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExpansionRegionActivation_EOperation_doStructuredActivity() const
{
	return m_expansionRegionActivation_EOperation_doStructuredActivity;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExpansionRegionActivation_EOperation_getExpansionNodeActivation_ExpansionNode() const
{
	return m_expansionRegionActivation_EOperation_getExpansionNodeActivation_ExpansionNode;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExpansionRegionActivation_EOperation_numberOfValues() const
{
	return m_expansionRegionActivation_EOperation_numberOfValues;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExpansionRegionActivation_EOperation_runGroup_ExpansionActivationGroup() const
{
	return m_expansionRegionActivation_EOperation_runGroup_ExpansionActivationGroup;
}

// End Class ExpansionRegionActivation

// Begin Class ExtensionalValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getExtensionalValue_EClass() const
{
	return m_extensionalValue_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExtensionalValue_EReference_locus() const
{
	return m_extensionalValue_EReference_locus;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExtensionalValue_EOperation_destroy() const
{
	return m_extensionalValue_EOperation_destroy;
}

// End Class ExtensionalValue

// Begin Class ExtensionalValueList
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getExtensionalValueList_EClass() const
{
	return m_extensionalValueList_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExtensionalValueList_EOperation_addValue_ExtensionalValue() const
{
	return m_extensionalValueList_EOperation_addValue_ExtensionalValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExtensionalValueList_EOperation_addValue_ExtensionalValue_EInt() const
{
	return m_extensionalValueList_EOperation_addValue_ExtensionalValue_EInt;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExtensionalValueList_EOperation_getValue() const
{
	return m_extensionalValueList_EOperation_getValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExtensionalValueList_EOperation_removeValue_EInt() const
{
	return m_extensionalValueList_EOperation_removeValue_EInt;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExtensionalValueList_EOperation_setValue_ExtensionalValue_EInt() const
{
	return m_extensionalValueList_EOperation_setValue_ExtensionalValue_EInt;
}

// End Class ExtensionalValueList

// Begin Class FIFOGetNextEventStrategy
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getFIFOGetNextEventStrategy_EClass() const
{
	return m_fIFOGetNextEventStrategy_EClass;
}




// End Class FIFOGetNextEventStrategy

// Begin Class FeatureValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getFeatureValue_EClass() const
{
	return m_featureValue_EClass;
}

std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getFeatureValue_EAttribute_position() const
{
	return m_featureValue_EAttribute_position;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getFeatureValue_EReference_feature() const
{
	return m_featureValue_EReference_feature;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getFeatureValue_EReference_values() const
{
	return m_featureValue_EReference_values;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getFeatureValue_EOperation_hasEqualValues_FeatureValue() const
{
	return m_featureValue_EOperation_hasEqualValues_FeatureValue;
}

// End Class FeatureValue

// Begin Class FirstChoiceStrategy
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getFirstChoiceStrategy_EClass() const
{
	return m_firstChoiceStrategy_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getFirstChoiceStrategy_EOperation_choose_EInt() const
{
	return m_firstChoiceStrategy_EOperation_choose_EInt;
}

// End Class FirstChoiceStrategy

// Begin Class FlowFinalNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getFlowFinalNodeActivation_EClass() const
{
	return m_flowFinalNodeActivation_EClass;
}




// End Class FlowFinalNodeActivation

// Begin Class ForkNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getForkNodeActivation_EClass() const
{
	return m_forkNodeActivation_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getForkNodeActivation_EOperation_fire_Token() const
{
	return m_forkNodeActivation_EOperation_fire_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getForkNodeActivation_EOperation_terminate() const
{
	return m_forkNodeActivation_EOperation_terminate;
}

// End Class ForkNodeActivation

// Begin Class ForkedToken
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getForkedToken_EClass() const
{
	return m_forkedToken_EClass;
}

std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getForkedToken_EAttribute_baseTokenIsWithdrawn() const
{
	return m_forkedToken_EAttribute_baseTokenIsWithdrawn;
}
std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getForkedToken_EAttribute_remainingOffersCount() const
{
	return m_forkedToken_EAttribute_remainingOffersCount;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getForkedToken_EReference_baseToken() const
{
	return m_forkedToken_EReference_baseToken;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getForkedToken_EOperation_equals_Token() const
{
	return m_forkedToken_EOperation_equals_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getForkedToken_EOperation_getValue() const
{
	return m_forkedToken_EOperation_getValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getForkedToken_EOperation_isControl() const
{
	return m_forkedToken_EOperation_isControl;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getForkedToken_EOperation_withdraw() const
{
	return m_forkedToken_EOperation_withdraw;
}

// End Class ForkedToken

// Begin Class GetNextEventStrategy
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getGetNextEventStrategy_EClass() const
{
	return m_getNextEventStrategy_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getGetNextEventStrategy_EOperation_retrieveNextEvent_ObjectActivation() const
{
	return m_getNextEventStrategy_EOperation_retrieveNextEvent_ObjectActivation;
}

// End Class GetNextEventStrategy

// Begin Class InitialNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getInitialNodeActivation_EClass() const
{
	return m_initialNodeActivation_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getInitialNodeActivation_EOperation_fire_Token() const
{
	return m_initialNodeActivation_EOperation_fire_Token;
}

// End Class InitialNodeActivation

// Begin Class InputPinActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getInputPinActivation_EClass() const
{
	return m_inputPinActivation_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getInputPinActivation_EOperation_isReady() const
{
	return m_inputPinActivation_EOperation_isReady;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getInputPinActivation_EOperation_recieveOffer() const
{
	return m_inputPinActivation_EOperation_recieveOffer;
}

// End Class InputPinActivation

// Begin Class InstanceValueEvaluation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getInstanceValueEvaluation_EClass() const
{
	return m_instanceValueEvaluation_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getInstanceValueEvaluation_EOperation_evaluate() const
{
	return m_instanceValueEvaluation_EOperation_evaluate;
}

// End Class InstanceValueEvaluation

// Begin Class IntegerValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getIntegerValue_EClass() const
{
	return m_integerValue_EClass;
}

std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getIntegerValue_EAttribute_value() const
{
	return m_integerValue_EAttribute_value;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getIntegerValue_EOperation_equals_Value() const
{
	return m_integerValue_EOperation_equals_Value;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getIntegerValue_EOperation_specify() const
{
	return m_integerValue_EOperation_specify;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getIntegerValue_EOperation_toString() const
{
	return m_integerValue_EOperation_toString;
}

// End Class IntegerValue

// Begin Class InvocationActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getInvocationActionActivation_EClass() const
{
	return m_invocationActionActivation_EClass;
}




// End Class InvocationActionActivation

// Begin Class JoinNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getJoinNodeActivation_EClass() const
{
	return m_joinNodeActivation_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getJoinNodeActivation_EOperation_isReady() const
{
	return m_joinNodeActivation_EOperation_isReady;
}

// End Class JoinNodeActivation

// Begin Class Link
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getLink_EClass() const
{
	return m_link_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getLink_EReference_type() const
{
	return m_link_EReference_type;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLink_EOperation_addTo_Locus() const
{
	return m_link_EOperation_addTo_Locus;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLink_EOperation_getOtherFeatureValues_ExtensionalValue_Property() const
{
	return m_link_EOperation_getOtherFeatureValues_ExtensionalValue_Property;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLink_EOperation_getTypes() const
{
	return m_link_EOperation_getTypes;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLink_EOperation_isMatchingLink_ExtensionalValue_Property() const
{
	return m_link_EOperation_isMatchingLink_ExtensionalValue_Property;
}

// End Class Link

// Begin Class LinkActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getLinkActionActivation_EClass() const
{
	return m_linkActionActivation_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLinkActionActivation_EOperation_endMatchesEndData_Link_LinkEndData() const
{
	return m_linkActionActivation_EOperation_endMatchesEndData_Link_LinkEndData;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLinkActionActivation_EOperation_getAssociation() const
{
	return m_linkActionActivation_EOperation_getAssociation;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLinkActionActivation_EOperation_linkMatchesEndData_Link_LinkEndData() const
{
	return m_linkActionActivation_EOperation_linkMatchesEndData_Link_LinkEndData;
}

// End Class LinkActionActivation

// Begin Class LiteralBooleanEvaluation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getLiteralBooleanEvaluation_EClass() const
{
	return m_literalBooleanEvaluation_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLiteralBooleanEvaluation_EOperation_evaluate() const
{
	return m_literalBooleanEvaluation_EOperation_evaluate;
}

// End Class LiteralBooleanEvaluation

// Begin Class LiteralEvaluation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getLiteralEvaluation_EClass() const
{
	return m_literalEvaluation_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLiteralEvaluation_EOperation_getType_EString() const
{
	return m_literalEvaluation_EOperation_getType_EString;
}

// End Class LiteralEvaluation

// Begin Class LiteralIntegerEvaluation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getLiteralIntegerEvaluation_EClass() const
{
	return m_literalIntegerEvaluation_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLiteralIntegerEvaluation_EOperation_evaluate() const
{
	return m_literalIntegerEvaluation_EOperation_evaluate;
}

// End Class LiteralIntegerEvaluation

// Begin Class LiteralNullEvaluation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getLiteralNullEvaluation_EClass() const
{
	return m_literalNullEvaluation_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLiteralNullEvaluation_EOperation_evaluate() const
{
	return m_literalNullEvaluation_EOperation_evaluate;
}

// End Class LiteralNullEvaluation

// Begin Class LiteralRealEvaluation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getLiteralRealEvaluation_EClass() const
{
	return m_literalRealEvaluation_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLiteralRealEvaluation_EOperation_evaluate() const
{
	return m_literalRealEvaluation_EOperation_evaluate;
}

// End Class LiteralRealEvaluation

// Begin Class LiteralStringEvaluation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getLiteralStringEvaluation_EClass() const
{
	return m_literalStringEvaluation_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLiteralStringEvaluation_EOperation_evaluate() const
{
	return m_literalStringEvaluation_EOperation_evaluate;
}

// End Class LiteralStringEvaluation

// Begin Class LiteralUnlimitedNaturalEvaluation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getLiteralUnlimitedNaturalEvaluation_EClass() const
{
	return m_literalUnlimitedNaturalEvaluation_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLiteralUnlimitedNaturalEvaluation_EOperation_evaluate() const
{
	return m_literalUnlimitedNaturalEvaluation_EOperation_evaluate;
}

// End Class LiteralUnlimitedNaturalEvaluation

// Begin Class Locus
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getLocus_EClass() const
{
	return m_locus_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getLocus_EReference_executor() const
{
	return m_locus_EReference_executor;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getLocus_EReference_extensionalValues() const
{
	return m_locus_EReference_extensionalValues;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getLocus_EReference_factory() const
{
	return m_locus_EReference_factory;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLocus_EOperation_add_ExtensionalValue() const
{
	return m_locus_EOperation_add_ExtensionalValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLocus_EOperation_assignExecutor_Executor() const
{
	return m_locus_EOperation_assignExecutor_Executor;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLocus_EOperation_assignFactory_ExecutionFactory() const
{
	return m_locus_EOperation_assignFactory_ExecutionFactory;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLocus_EOperation_conforms_Classifier_Classifier() const
{
	return m_locus_EOperation_conforms_Classifier_Classifier;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLocus_EOperation_instantiate_Class() const
{
	return m_locus_EOperation_instantiate_Class;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLocus_EOperation_remove_ExtensionalValue() const
{
	return m_locus_EOperation_remove_ExtensionalValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLocus_EOperation_retrieveExtent_Classifier() const
{
	return m_locus_EOperation_retrieveExtent_Classifier;
}

// End Class Locus

// Begin Class LoopNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getLoopNodeActivation_EClass() const
{
	return m_loopNodeActivation_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getLoopNodeActivation_EReference_bodyOutputLists() const
{
	return m_loopNodeActivation_EReference_bodyOutputLists;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLoopNodeActivation_EOperation_makeLoopVariableList() const
{
	return m_loopNodeActivation_EOperation_makeLoopVariableList;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLoopNodeActivation_EOperation_runBody() const
{
	return m_loopNodeActivation_EOperation_runBody;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLoopNodeActivation_EOperation_runLoopVariables() const
{
	return m_loopNodeActivation_EOperation_runLoopVariables;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLoopNodeActivation_EOperation_runTest() const
{
	return m_loopNodeActivation_EOperation_runTest;
}

// End Class LoopNodeActivation

// Begin Class MergeNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getMergeNodeActivation_EClass() const
{
	return m_mergeNodeActivation_EClass;
}




// End Class MergeNodeActivation

// Begin Class Object
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getObject_EClass() const
{
	return m_object_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getObject_EReference_objectActivation() const
{
	return m_object_EReference_objectActivation;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getObject_EReference_types() const
{
	return m_object_EReference_types;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObject_EOperation__register_EventAccepter() const
{
	return m_object_EOperation__register_EventAccepter;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObject_EOperation_destroy() const
{
	return m_object_EOperation_destroy;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObject_EOperation_dispatch_Operation() const
{
	return m_object_EOperation_dispatch_Operation;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObject_EOperation_new_() const
{
	return m_object_EOperation_new_;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObject_EOperation_send_SignalInstance() const
{
	return m_object_EOperation_send_SignalInstance;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObject_EOperation_startBehavior_Class_ParameterValue() const
{
	return m_object_EOperation_startBehavior_Class_ParameterValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObject_EOperation_unregister_EventAccepter() const
{
	return m_object_EOperation_unregister_EventAccepter;
}

// End Class Object

// Begin Class ObjectActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getObjectActivation_EClass() const
{
	return m_objectActivation_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getObjectActivation_EReference_classifierBehaviorExecutions() const
{
	return m_objectActivation_EReference_classifierBehaviorExecutions;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getObjectActivation_EReference_eventPool() const
{
	return m_objectActivation_EReference_eventPool;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getObjectActivation_EReference_object() const
{
	return m_objectActivation_EReference_object;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getObjectActivation_EReference_waitingEventAccepters() const
{
	return m_objectActivation_EReference_waitingEventAccepters;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectActivation_EOperation__register_EventAccepter() const
{
	return m_objectActivation_EOperation__register_EventAccepter;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectActivation_EOperation__send_EJavaObject() const
{
	return m_objectActivation_EOperation__send_EJavaObject;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectActivation_EOperation__startObjectBehavior() const
{
	return m_objectActivation_EOperation__startObjectBehavior;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectActivation_EOperation_dispatchNextEvent() const
{
	return m_objectActivation_EOperation_dispatchNextEvent;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectActivation_EOperation_retrieveNextEvent() const
{
	return m_objectActivation_EOperation_retrieveNextEvent;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectActivation_EOperation_send_SignalInstance() const
{
	return m_objectActivation_EOperation_send_SignalInstance;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectActivation_EOperation_startBehavior_Class_ParameterValue() const
{
	return m_objectActivation_EOperation_startBehavior_Class_ParameterValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectActivation_EOperation_stop() const
{
	return m_objectActivation_EOperation_stop;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectActivation_EOperation_unregister_EventAccepter() const
{
	return m_objectActivation_EOperation_unregister_EventAccepter;
}

// End Class ObjectActivation

// Begin Class ObjectNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getObjectNodeActivation_EClass() const
{
	return m_objectNodeActivation_EClass;
}

std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getObjectNodeActivation_EAttribute_offeredTokenCount() const
{
	return m_objectNodeActivation_EAttribute_offeredTokenCount;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectNodeActivation_EOperation_addToken_Token() const
{
	return m_objectNodeActivation_EOperation_addToken_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectNodeActivation_EOperation_clearTokens() const
{
	return m_objectNodeActivation_EOperation_clearTokens;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectNodeActivation_EOperation_countOfferedValues() const
{
	return m_objectNodeActivation_EOperation_countOfferedValues;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectNodeActivation_EOperation_countUnofferedTokens() const
{
	return m_objectNodeActivation_EOperation_countUnofferedTokens;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectNodeActivation_EOperation_getUnofferedTokens() const
{
	return m_objectNodeActivation_EOperation_getUnofferedTokens;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectNodeActivation_EOperation_removeToken_Token() const
{
	return m_objectNodeActivation_EOperation_removeToken_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectNodeActivation_EOperation_run() const
{
	return m_objectNodeActivation_EOperation_run;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectNodeActivation_EOperation_sendOffers_Token() const
{
	return m_objectNodeActivation_EOperation_sendOffers_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectNodeActivation_EOperation_sendUnofferedTokens() const
{
	return m_objectNodeActivation_EOperation_sendUnofferedTokens;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectNodeActivation_EOperation_takeUnofferedTokens() const
{
	return m_objectNodeActivation_EOperation_takeUnofferedTokens;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectNodeActivation_EOperation_terminate() const
{
	return m_objectNodeActivation_EOperation_terminate;
}

// End Class ObjectNodeActivation

// Begin Class ObjectToken
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getObjectToken_EClass() const
{
	return m_objectToken_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getObjectToken_EReference_value() const
{
	return m_objectToken_EReference_value;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectToken_EOperation_equals_Token() const
{
	return m_objectToken_EOperation_equals_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectToken_EOperation_isControl() const
{
	return m_objectToken_EOperation_isControl;
}

// End Class ObjectToken

// Begin Class Offer
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getOffer_EClass() const
{
	return m_offer_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getOffer_EReference_offeredTokens() const
{
	return m_offer_EReference_offeredTokens;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getOffer_EOperation_countOfferedVales() const
{
	return m_offer_EOperation_countOfferedVales;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getOffer_EOperation_hasTokens() const
{
	return m_offer_EOperation_hasTokens;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getOffer_EOperation_removeOfferedValues_EInt() const
{
	return m_offer_EOperation_removeOfferedValues_EInt;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getOffer_EOperation_removeWithdrawnTokens() const
{
	return m_offer_EOperation_removeWithdrawnTokens;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getOffer_EOperation_retrieveOfferedTokens() const
{
	return m_offer_EOperation_retrieveOfferedTokens;
}

// End Class Offer

// Begin Class OpaqueBehaviorExecution
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getOpaqueBehaviorExecution_EClass() const
{
	return m_opaqueBehaviorExecution_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getOpaqueBehaviorExecution_EOperation_doBody_ParameterValue_ParameterValue() const
{
	return m_opaqueBehaviorExecution_EOperation_doBody_ParameterValue_ParameterValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getOpaqueBehaviorExecution_EOperation_execute() const
{
	return m_opaqueBehaviorExecution_EOperation_execute;
}

// End Class OpaqueBehaviorExecution

// Begin Class OutputPinActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getOutputPinActivation_EClass() const
{
	return m_outputPinActivation_EClass;
}




// End Class OutputPinActivation

// Begin Class ParameterValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getParameterValue_EClass() const
{
	return m_parameterValue_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getParameterValue_EReference_parameter() const
{
	return m_parameterValue_EReference_parameter;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getParameterValue_EReference_values() const
{
	return m_parameterValue_EReference_values;
}


// End Class ParameterValue

// Begin Class PinActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getPinActivation_EClass() const
{
	return m_pinActivation_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getPinActivation_EReference_actionActivation() const
{
	return m_pinActivation_EReference_actionActivation;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getPinActivation_EOperation_fire_Token() const
{
	return m_pinActivation_EOperation_fire_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getPinActivation_EOperation_takeOfferedTokens() const
{
	return m_pinActivation_EOperation_takeOfferedTokens;
}

// End Class PinActivation

// Begin Class PrimitiveValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getPrimitiveValue_EClass() const
{
	return m_primitiveValue_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getPrimitiveValue_EReference_type() const
{
	return m_primitiveValue_EReference_type;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getPrimitiveValue_EOperation_getTypes() const
{
	return m_primitiveValue_EOperation_getTypes;
}

// End Class PrimitiveValue

// Begin Class ReadExtentActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getReadExtentActionActivation_EClass() const
{
	return m_readExtentActionActivation_EClass;
}




// End Class ReadExtentActionActivation

// Begin Class ReadIsClassifiedObjectActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getReadIsClassifiedObjectActionActivation_EClass() const
{
	return m_readIsClassifiedObjectActionActivation_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReadIsClassifiedObjectActionActivation_EOperation_checkAllParents_Classifier_Classifier() const
{
	return m_readIsClassifiedObjectActionActivation_EOperation_checkAllParents_Classifier_Classifier;
}

// End Class ReadIsClassifiedObjectActionActivation

// Begin Class ReadLinkActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getReadLinkActionActivation_EClass() const
{
	return m_readLinkActionActivation_EClass;
}




// End Class ReadLinkActionActivation

// Begin Class ReadSelfActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getReadSelfActionActivation_EClass() const
{
	return m_readSelfActionActivation_EClass;
}




// End Class ReadSelfActionActivation

// Begin Class ReadStructuralFeatureActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getReadStructuralFeatureActionActivation_EClass() const
{
	return m_readStructuralFeatureActionActivation_EClass;
}




// End Class ReadStructuralFeatureActionActivation

// Begin Class RealValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getRealValue_EClass() const
{
	return m_realValue_EClass;
}

std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getRealValue_EAttribute_value() const
{
	return m_realValue_EAttribute_value;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getRealValue_EOperation_equals_Value() const
{
	return m_realValue_EOperation_equals_Value;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getRealValue_EOperation_specify() const
{
	return m_realValue_EOperation_specify;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getRealValue_EOperation_toString() const
{
	return m_realValue_EOperation_toString;
}

// End Class RealValue

// Begin Class ReclassifyObjectActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getReclassifyObjectActionActivation_EClass() const
{
	return m_reclassifyObjectActionActivation_EClass;
}




// End Class ReclassifyObjectActionActivation

// Begin Class RedefinitionBasedDispatchStrategy
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getRedefinitionBasedDispatchStrategy_EClass() const
{
	return m_redefinitionBasedDispatchStrategy_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getRedefinitionBasedDispatchStrategy_EOperation_operationsMatch_Operation_Operation() const
{
	return m_redefinitionBasedDispatchStrategy_EOperation_operationsMatch_Operation_Operation;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getRedefinitionBasedDispatchStrategy_EOperation_retrieveMethod_Object_Operation() const
{
	return m_redefinitionBasedDispatchStrategy_EOperation_retrieveMethod_Object_Operation;
}

// End Class RedefinitionBasedDispatchStrategy

// Begin Class ReduceActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getReduceActionActivation_EClass() const
{
	return m_reduceActionActivation_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getReduceActionActivation_EReference_currentExecution() const
{
	return m_reduceActionActivation_EReference_currentExecution;
}


// End Class ReduceActionActivation

// Begin Class Reference
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getReference_EClass() const
{
	return m_reference_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getReference_EReference_referent() const
{
	return m_reference_EReference_referent;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReference_EOperation_assignFeatureValue_StructuralFeature_EInt() const
{
	return m_reference_EOperation_assignFeatureValue_StructuralFeature_EInt;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReference_EOperation_destroy() const
{
	return m_reference_EOperation_destroy;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReference_EOperation_dispatch_Operation() const
{
	return m_reference_EOperation_dispatch_Operation;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReference_EOperation_equals_Value() const
{
	return m_reference_EOperation_equals_Value;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReference_EOperation_getTypes() const
{
	return m_reference_EOperation_getTypes;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReference_EOperation_new_() const
{
	return m_reference_EOperation_new_;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReference_EOperation_retrieveFeatureValue_StructuralFeature() const
{
	return m_reference_EOperation_retrieveFeatureValue_StructuralFeature;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReference_EOperation_retrieveFeatureValues() const
{
	return m_reference_EOperation_retrieveFeatureValues;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReference_EOperation_send_SignalInstance() const
{
	return m_reference_EOperation_send_SignalInstance;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReference_EOperation_startBehavior_Class_ParameterValue() const
{
	return m_reference_EOperation_startBehavior_Class_ParameterValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReference_EOperation_toString() const
{
	return m_reference_EOperation_toString;
}

// End Class Reference

// Begin Class RemoveStructuralFeatureValueActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getRemoveStructuralFeatureValueActivation_EClass() const
{
	return m_removeStructuralFeatureValueActivation_EClass;
}




// End Class RemoveStructuralFeatureValueActivation

// Begin Class SemanticStrategy
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getSemanticStrategy_EClass() const
{
	return m_semanticStrategy_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getSemanticStrategy_EOperation_retrieveName() const
{
	return m_semanticStrategy_EOperation_retrieveName;
}

// End Class SemanticStrategy

// Begin Class SemanticVisitor
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getSemanticVisitor_EClass() const
{
	return m_semanticVisitor_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getSemanticVisitor_EOperation__beginIsolation() const
{
	return m_semanticVisitor_EOperation__beginIsolation;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getSemanticVisitor_EOperation__endIsolation() const
{
	return m_semanticVisitor_EOperation__endIsolation;
}

// End Class SemanticVisitor

// Begin Class SendSignalActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getSendSignalActionActivation_EClass() const
{
	return m_sendSignalActionActivation_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getSendSignalActionActivation_EOperation_doAction() const
{
	return m_sendSignalActionActivation_EOperation_doAction;
}

// End Class SendSignalActionActivation

// Begin Class SignalInstance
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getSignalInstance_EClass() const
{
	return m_signalInstance_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getSignalInstance_EReference_type() const
{
	return m_signalInstance_EReference_type;
}


// End Class SignalInstance

// Begin Class StartClassifierBehaviorActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getStartClassifierBehaviorActionActivation_EClass() const
{
	return m_startClassifierBehaviorActionActivation_EClass;
}




// End Class StartClassifierBehaviorActionActivation

// Begin Class StartObjectBehaviorActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getStartObjectBehaviorActionActivation_EClass() const
{
	return m_startObjectBehaviorActionActivation_EClass;
}




// End Class StartObjectBehaviorActionActivation

// Begin Class StringValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getStringValue_EClass() const
{
	return m_stringValue_EClass;
}

std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getStringValue_EAttribute_value() const
{
	return m_stringValue_EAttribute_value;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStringValue_EOperation_equals_Value() const
{
	return m_stringValue_EOperation_equals_Value;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStringValue_EOperation_specify() const
{
	return m_stringValue_EOperation_specify;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStringValue_EOperation_toString() const
{
	return m_stringValue_EOperation_toString;
}

// End Class StringValue

// Begin Class StructuralFeatureActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getStructuralFeatureActionActivation_EClass() const
{
	return m_structuralFeatureActionActivation_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuralFeatureActionActivation_EOperation_getAssociation_StructuralFeature() const
{
	return m_structuralFeatureActionActivation_EOperation_getAssociation_StructuralFeature;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuralFeatureActionActivation_EOperation_getMatchingLinks_Association_Value() const
{
	return m_structuralFeatureActionActivation_EOperation_getMatchingLinks_Association_Value;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuralFeatureActionActivation_EOperation_getOppositeEnd_Association_StructuralFeature() const
{
	return m_structuralFeatureActionActivation_EOperation_getOppositeEnd_Association_StructuralFeature;
}

// End Class StructuralFeatureActionActivation

// Begin Class StructuredActivityNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getStructuredActivityNodeActivation_EClass() const
{
	return m_structuredActivityNodeActivation_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getStructuredActivityNodeActivation_EReference_activationGroup() const
{
	return m_structuredActivityNodeActivation_EReference_activationGroup;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation_EOperation_completeAction() const
{
	return m_structuredActivityNodeActivation_EOperation_completeAction;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation_EOperation_createEdgeInstances() const
{
	return m_structuredActivityNodeActivation_EOperation_createEdgeInstances;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation_EOperation_createNodeActivations() const
{
	return m_structuredActivityNodeActivation_EOperation_createNodeActivations;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation_EOperation_doAction() const
{
	return m_structuredActivityNodeActivation_EOperation_doAction;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation_EOperation_doStructuredActivity() const
{
	return m_structuredActivityNodeActivation_EOperation_doStructuredActivity;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation_EOperation_getNodeActivation_ActivityNode() const
{
	return m_structuredActivityNodeActivation_EOperation_getNodeActivation_ActivityNode;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation_EOperation_getPinValues_OutputPin() const
{
	return m_structuredActivityNodeActivation_EOperation_getPinValues_OutputPin;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation_EOperation_isSourceFor_ActivityEdgeInstance() const
{
	return m_structuredActivityNodeActivation_EOperation_isSourceFor_ActivityEdgeInstance;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation_EOperation_isSuspended() const
{
	return m_structuredActivityNodeActivation_EOperation_isSuspended;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation_EOperation_makeActivityNodeList_ExecutableNode() const
{
	return m_structuredActivityNodeActivation_EOperation_makeActivityNodeList_ExecutableNode;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation_EOperation_putPinValues_OutputPin_Value() const
{
	return m_structuredActivityNodeActivation_EOperation_putPinValues_OutputPin_Value;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation_EOperation_resume() const
{
	return m_structuredActivityNodeActivation_EOperation_resume;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation_EOperation_terminate() const
{
	return m_structuredActivityNodeActivation_EOperation_terminate;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation_EOperation_terminateAll() const
{
	return m_structuredActivityNodeActivation_EOperation_terminateAll;
}

// End Class StructuredActivityNodeActivation

// Begin Class StructuredValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getStructuredValue_EClass() const
{
	return m_structuredValue_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredValue_EOperation_assignFeatureValue_StructuralFeature_EInt() const
{
	return m_structuredValue_EOperation_assignFeatureValue_StructuralFeature_EInt;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredValue_EOperation_createFeatureValues() const
{
	return m_structuredValue_EOperation_createFeatureValues;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredValue_EOperation_retrieveFeatureValue_StructuralFeature() const
{
	return m_structuredValue_EOperation_retrieveFeatureValue_StructuralFeature;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredValue_EOperation_retrieveFeatureValues() const
{
	return m_structuredValue_EOperation_retrieveFeatureValues;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredValue_EOperation_specify() const
{
	return m_structuredValue_EOperation_specify;
}

// End Class StructuredValue

// Begin Class TestIdentityActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getTestIdentityActionActivation_EClass() const
{
	return m_testIdentityActionActivation_EClass;
}




// End Class TestIdentityActionActivation

// Begin Class Token
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getToken_EClass() const
{
	return m_token_EClass;
}

std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getToken_EAttribute_withdrawn() const
{
	return m_token_EAttribute_withdrawn;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getToken_EReference_holder() const
{
	return m_token_EReference_holder;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getToken_EOperation_equals_Token() const
{
	return m_token_EOperation_equals_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getToken_EOperation_getValue() const
{
	return m_token_EOperation_getValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getToken_EOperation_isControl() const
{
	return m_token_EOperation_isControl;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getToken_EOperation_transfer_ActivityNodeActivation() const
{
	return m_token_EOperation_transfer_ActivityNodeActivation;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getToken_EOperation_withdraw() const
{
	return m_token_EOperation_withdraw;
}

// End Class Token

// Begin Class TokenSet
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getTokenSet_EClass() const
{
	return m_tokenSet_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getTokenSet_EReference_tokens() const
{
	return m_tokenSet_EReference_tokens;
}


// End Class TokenSet

// Begin Class UnlimitedNaturalValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getUnlimitedNaturalValue_EClass() const
{
	return m_unlimitedNaturalValue_EClass;
}

std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getUnlimitedNaturalValue_EAttribute_value() const
{
	return m_unlimitedNaturalValue_EAttribute_value;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getUnlimitedNaturalValue_EOperation_equals_Value() const
{
	return m_unlimitedNaturalValue_EOperation_equals_Value;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getUnlimitedNaturalValue_EOperation_specify() const
{
	return m_unlimitedNaturalValue_EOperation_specify;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getUnlimitedNaturalValue_EOperation_toString() const
{
	return m_unlimitedNaturalValue_EOperation_toString;
}

// End Class UnlimitedNaturalValue

// Begin Class Value
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getValue_EClass() const
{
	return m_value_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getValue_EOperation_equals_Value() const
{
	return m_value_EOperation_equals_Value;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getValue_EOperation_getTypes() const
{
	return m_value_EOperation_getTypes;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getValue_EOperation_hasTypes_Classifier() const
{
	return m_value_EOperation_hasTypes_Classifier;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getValue_EOperation_objectId() const
{
	return m_value_EOperation_objectId;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getValue_EOperation_specify() const
{
	return m_value_EOperation_specify;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getValue_EOperation_toString() const
{
	return m_value_EOperation_toString;
}

// End Class Value

// Begin Class ValueSpecificActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getValueSpecificActionActivation_EClass() const
{
	return m_valueSpecificActionActivation_EClass;
}




// End Class ValueSpecificActionActivation

// Begin Class Values
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getValues_EClass() const
{
	return m_values_EClass;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getValues_EReference_values() const
{
	return m_values_EReference_values;
}


// End Class Values

// Begin Class WriteLinkActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getWriteLinkActionActivation_EClass() const
{
	return m_writeLinkActionActivation_EClass;
}




// End Class WriteLinkActionActivation

// Begin Class WriteStructuralFeatureActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getWriteStructuralFeatureActionActivation_EClass() const
{
	return m_writeStructuralFeatureActionActivation_EClass;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getWriteStructuralFeatureActionActivation_EOperation_position_Value_EInt() const
{
	return m_writeStructuralFeatureActionActivation_EOperation_position_Value_EInt;
}

// End Class WriteStructuralFeatureActionActivation

