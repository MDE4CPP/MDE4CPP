#include "fUML/Semantics/Actions/impl/ActionsPackageImpl.hpp"

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
#include "ecore/EParameter.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

//depending model packages
#include "ecore/EcorePackage.hpp"
#include "fUML/FUMLPackage.hpp"
#include "uml/UmlPackage.hpp"
//include subpackages 
 
using namespace fUML::Semantics::Actions;

void ActionsPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::EcoreFactory> factory = ecore::EcoreFactory::eInstance();

	createAcceptCallActionActivationContent(package, factory);
	createAcceptCallActionActivationsContent(package, factory);
	createAcceptEventActionActivationContent(package, factory);
	createAcceptEventActionEventAccepterContent(package, factory);
	createActionActivationContent(package, factory);
	createAddStructuralFeatureValueActionActivationContent(package, factory);
	createCallActionActivationContent(package, factory);
	createCallBehaviorActionActivationContent(package, factory);
	createCallOperationActionActivationContent(package, factory);
	createClauseActivationContent(package, factory);
	createClearAssociationActionActivationContent(package, factory);
	createClearStructuralFeatureActionActivationContent(package, factory);
	createConditionalNodeActivationContent(package, factory);
	createCreateLinkActionActivationContent(package, factory);
	createCreateObjectActionActivationContent(package, factory);
	createDestroyLinkActionActivationContent(package, factory);
	createDestroyObjectActionActivationContent(package, factory);
	createInputPinActivationContent(package, factory);
	createInvocationActionActivationContent(package, factory);
	createLinkActionActivationContent(package, factory);
	createLoopNodeActivationContent(package, factory);
	createOutputPinActivationContent(package, factory);
	createPinActivationContent(package, factory);
	createReadExtentActionActivationContent(package, factory);
	createReadIsClassifiedObjectActionActivationContent(package, factory);
	createReadLinkActionActivationContent(package, factory);
	createReadSelfActionActivationContent(package, factory);
	createReadStructuralFeatureActionActivationContent(package, factory);
	createReclassifyObjectActionActivationContent(package, factory);
	createReduceActionActivationContent(package, factory);
	createRemoveStructuralFeatureValueActivationContent(package, factory);
	createReplyActionActivationContent(package, factory);
	createReturnInformationContent(package, factory);
	createSendSignalActionActivationContent(package, factory);
	createStartClassifierBehaviorActionActivationContent(package, factory);
	createStartObjectBehaviorActionActivationContent(package, factory);
	createStructuralFeatureActionActivationContent(package, factory);
	createStructuredActivityNodeActivationContent(package, factory);
	createTestIdentityActionActivationContent(package, factory);
	createValueSpecificationActionActivationContent(package, factory);
	createValuesContent(package, factory);
	createWriteLinkActionActivationContent(package, factory);
	createWriteStructuralFeatureActionActivationContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void ActionsPackageImpl::createAcceptCallActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_acceptCallActionActivation_Class = factory->createEClass_in_EPackage(package, ACCEPTCALLACTIONACTIVATION_CLASS);
	
	
	m_acceptCallActionActivation_Operation_accept_EventOccurrence = factory->createEOperation_in_EContainingClass(m_acceptCallActionActivation_Class, ACCEPTCALLACTIONACTIVATION_OPERATION_ACCEPT_EVENTOCCURRENCE);
	
}

void ActionsPackageImpl::createAcceptCallActionActivationsContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_acceptCallActionActivations_Class = factory->createEClass_in_EPackage(package, ACCEPTCALLACTIONACTIVATIONS_CLASS);
	
	
	
}

void ActionsPackageImpl::createAcceptEventActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_acceptEventActionActivation_Class = factory->createEClass_in_EPackage(package, ACCEPTEVENTACTIONACTIVATION_CLASS);
	m_acceptEventActionActivation_Attribute_waiting = factory->createEAttribute_in_EContainingClass(m_acceptEventActionActivation_Class, ACCEPTEVENTACTIONACTIVATION_ATTRIBUTE_WAITING);
	
	m_acceptEventActionActivation_Attribute_eventAccepter = factory->createEReference_in_EContainingClass(m_acceptEventActionActivation_Class, ACCEPTEVENTACTIONACTIVATION_ATTRIBUTE_EVENTACCEPTER);
	
	m_acceptEventActionActivation_Operation_accept_EventOccurrence = factory->createEOperation_in_EContainingClass(m_acceptEventActionActivation_Class, ACCEPTEVENTACTIONACTIVATION_OPERATION_ACCEPT_EVENTOCCURRENCE);
	m_acceptEventActionActivation_Operation_doAction = factory->createEOperation_in_EContainingClass(m_acceptEventActionActivation_Class, ACCEPTEVENTACTIONACTIVATION_OPERATION_DOACTION);
	m_acceptEventActionActivation_Operation_fire_Token = factory->createEOperation_in_EContainingClass(m_acceptEventActionActivation_Class, ACCEPTEVENTACTIONACTIVATION_OPERATION_FIRE_TOKEN);
	m_acceptEventActionActivation_Operation_initialize_ActivityNode_ActivityNodeActivationGroup = factory->createEOperation_in_EContainingClass(m_acceptEventActionActivation_Class, ACCEPTEVENTACTIONACTIVATION_OPERATION_INITIALIZE_ACTIVITYNODE_ACTIVITYNODEACTIVATIONGROUP);
	m_acceptEventActionActivation_Operation_isReady = factory->createEOperation_in_EContainingClass(m_acceptEventActionActivation_Class, ACCEPTEVENTACTIONACTIVATION_OPERATION_ISREADY);
	m_acceptEventActionActivation_Operation_match_EventOccurrence = factory->createEOperation_in_EContainingClass(m_acceptEventActionActivation_Class, ACCEPTEVENTACTIONACTIVATION_OPERATION_MATCH_EVENTOCCURRENCE);
	m_acceptEventActionActivation_Operation_run = factory->createEOperation_in_EContainingClass(m_acceptEventActionActivation_Class, ACCEPTEVENTACTIONACTIVATION_OPERATION_RUN);
	m_acceptEventActionActivation_Operation_terminate = factory->createEOperation_in_EContainingClass(m_acceptEventActionActivation_Class, ACCEPTEVENTACTIONACTIVATION_OPERATION_TERMINATE);
	
}

void ActionsPackageImpl::createAcceptEventActionEventAccepterContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_acceptEventActionEventAccepter_Class = factory->createEClass_in_EPackage(package, ACCEPTEVENTACTIONEVENTACCEPTER_CLASS);
	
	m_acceptEventActionEventAccepter_Attribute_actionActivation = factory->createEReference_in_EContainingClass(m_acceptEventActionEventAccepter_Class, ACCEPTEVENTACTIONEVENTACCEPTER_ATTRIBUTE_ACTIONACTIVATION);
	
	
}

void ActionsPackageImpl::createActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_actionActivation_Class = factory->createEClass_in_EPackage(package, ACTIONACTIVATION_CLASS);
	m_actionActivation_Attribute_firing = factory->createEAttribute_in_EContainingClass(m_actionActivation_Class, ACTIONACTIVATION_ATTRIBUTE_FIRING);
	
	m_actionActivation_Attribute_inputPinActivation = factory->createEReference_in_EContainingClass(m_actionActivation_Class, ACTIONACTIVATION_ATTRIBUTE_INPUTPINACTIVATION);
	m_actionActivation_Attribute_outputPinActivation = factory->createEReference_in_EContainingClass(m_actionActivation_Class, ACTIONACTIVATION_ATTRIBUTE_OUTPUTPINACTIVATION);
	m_actionActivation_Attribute_pinActivation = factory->createEReference_in_EContainingClass(m_actionActivation_Class, ACTIONACTIVATION_ATTRIBUTE_PINACTIVATION);
	
	m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance = factory->createEOperation_in_EContainingClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_ADDOUTGOINGEDGE_ACTIVITYEDGEINSTANCE);
	m_actionActivation_Operation_addPinActivation_PinActivation = factory->createEOperation_in_EContainingClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_ADDPINACTIVATION_PINACTIVATION);
	m_actionActivation_Operation_completeAction = factory->createEOperation_in_EContainingClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_COMPLETEACTION);
	m_actionActivation_Operation_createNodeActivations = factory->createEOperation_in_EContainingClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_CREATENODEACTIVATIONS);
	m_actionActivation_Operation_doAction = factory->createEOperation_in_EContainingClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_DOACTION);
	m_actionActivation_Operation_fire_Token = factory->createEOperation_in_EContainingClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_FIRE_TOKEN);
	m_actionActivation_Operation_getTokens_InputPin = factory->createEOperation_in_EContainingClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_GETTOKENS_INPUTPIN);
	m_actionActivation_Operation_isFirng = factory->createEOperation_in_EContainingClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_ISFIRNG);
	m_actionActivation_Operation_isReady = factory->createEOperation_in_EContainingClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_ISREADY);
	m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance = factory->createEOperation_in_EContainingClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_ISSOURCEFOR_ACTIVITYEDGEINSTANCE);
	m_actionActivation_Operation_makeBooleanValue_EBoolean = factory->createEOperation_in_EContainingClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_MAKEBOOLEANVALUE_EBOOLEAN);
	m_actionActivation_Operation_putToken_OutputPin_Value = factory->createEOperation_in_EContainingClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_PUTTOKEN_OUTPUTPIN_VALUE);
	m_actionActivation_Operation_putTokens_OutputPin_Value = factory->createEOperation_in_EContainingClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_PUTTOKENS_OUTPUTPIN_VALUE);
	m_actionActivation_Operation_retrievePinActivation_Pin = factory->createEOperation_in_EContainingClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_RETRIEVEPINACTIVATION_PIN);
	m_actionActivation_Operation_run = factory->createEOperation_in_EContainingClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_RUN);
	m_actionActivation_Operation_sendOffers = factory->createEOperation_in_EContainingClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_SENDOFFERS);
	m_actionActivation_Operation_takeOfferedTokens = factory->createEOperation_in_EContainingClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_TAKEOFFEREDTOKENS);
	m_actionActivation_Operation_takeTokens_InputPin = factory->createEOperation_in_EContainingClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_TAKETOKENS_INPUTPIN);
	m_actionActivation_Operation_terminate = factory->createEOperation_in_EContainingClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_TERMINATE);
	m_actionActivation_Operation_valueParticipatesInLink_Value_Link = factory->createEOperation_in_EContainingClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_VALUEPARTICIPATESINLINK_VALUE_LINK);
	
}

void ActionsPackageImpl::createAddStructuralFeatureValueActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_addStructuralFeatureValueActionActivation_Class = factory->createEClass_in_EPackage(package, ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS);
	
	
	m_addStructuralFeatureValueActionActivation_Operation_doAction = factory->createEOperation_in_EContainingClass(m_addStructuralFeatureValueActionActivation_Class, ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_OPERATION_DOACTION);
	
}

void ActionsPackageImpl::createCallActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_callActionActivation_Class = factory->createEClass_in_EPackage(package, CALLACTIONACTIVATION_CLASS);
	
	m_callActionActivation_Attribute_callExecutions = factory->createEReference_in_EContainingClass(m_callActionActivation_Class, CALLACTIONACTIVATION_ATTRIBUTE_CALLEXECUTIONS);
	
	m_callActionActivation_Operation_doAction = factory->createEOperation_in_EContainingClass(m_callActionActivation_Class, CALLACTIONACTIVATION_OPERATION_DOACTION);
	m_callActionActivation_Operation_getCallExecution = factory->createEOperation_in_EContainingClass(m_callActionActivation_Class, CALLACTIONACTIVATION_OPERATION_GETCALLEXECUTION);
	m_callActionActivation_Operation_removeCallExecution_Execution = factory->createEOperation_in_EContainingClass(m_callActionActivation_Class, CALLACTIONACTIVATION_OPERATION_REMOVECALLEXECUTION_EXECUTION);
	m_callActionActivation_Operation_terminate = factory->createEOperation_in_EContainingClass(m_callActionActivation_Class, CALLACTIONACTIVATION_OPERATION_TERMINATE);
	
}

void ActionsPackageImpl::createCallBehaviorActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_callBehaviorActionActivation_Class = factory->createEClass_in_EPackage(package, CALLBEHAVIORACTIONACTIVATION_CLASS);
	
	
	m_callBehaviorActionActivation_Operation_getCallExecution = factory->createEOperation_in_EContainingClass(m_callBehaviorActionActivation_Class, CALLBEHAVIORACTIONACTIVATION_OPERATION_GETCALLEXECUTION);
	
}

void ActionsPackageImpl::createCallOperationActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_callOperationActionActivation_Class = factory->createEClass_in_EPackage(package, CALLOPERATIONACTIONACTIVATION_CLASS);
	
	
	m_callOperationActionActivation_Operation_getCallExecution = factory->createEOperation_in_EContainingClass(m_callOperationActionActivation_Class, CALLOPERATIONACTIONACTIVATION_OPERATION_GETCALLEXECUTION);
	
}

void ActionsPackageImpl::createClauseActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_clauseActivation_Class = factory->createEClass_in_EPackage(package, CLAUSEACTIVATION_CLASS);
	
	m_clauseActivation_Attribute_clause = factory->createEReference_in_EContainingClass(m_clauseActivation_Class, CLAUSEACTIVATION_ATTRIBUTE_CLAUSE);
	m_clauseActivation_Attribute_conditionalNodeActivation = factory->createEReference_in_EContainingClass(m_clauseActivation_Class, CLAUSEACTIVATION_ATTRIBUTE_CONDITIONALNODEACTIVATION);
	
	m_clauseActivation_Operation_getDecision = factory->createEOperation_in_EContainingClass(m_clauseActivation_Class, CLAUSEACTIVATION_OPERATION_GETDECISION);
	m_clauseActivation_Operation_getPredecessors = factory->createEOperation_in_EContainingClass(m_clauseActivation_Class, CLAUSEACTIVATION_OPERATION_GETPREDECESSORS);
	m_clauseActivation_Operation_getSuccessors = factory->createEOperation_in_EContainingClass(m_clauseActivation_Class, CLAUSEACTIVATION_OPERATION_GETSUCCESSORS);
	m_clauseActivation_Operation_isReady = factory->createEOperation_in_EContainingClass(m_clauseActivation_Class, CLAUSEACTIVATION_OPERATION_ISREADY);
	m_clauseActivation_Operation_recieveControl = factory->createEOperation_in_EContainingClass(m_clauseActivation_Class, CLAUSEACTIVATION_OPERATION_RECIEVECONTROL);
	m_clauseActivation_Operation_runTest = factory->createEOperation_in_EContainingClass(m_clauseActivation_Class, CLAUSEACTIVATION_OPERATION_RUNTEST);
	m_clauseActivation_Operation_selectBody = factory->createEOperation_in_EContainingClass(m_clauseActivation_Class, CLAUSEACTIVATION_OPERATION_SELECTBODY);
	
}

void ActionsPackageImpl::createClearAssociationActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_clearAssociationActionActivation_Class = factory->createEClass_in_EPackage(package, CLEARASSOCIATIONACTIONACTIVATION_CLASS);
	
	
	
}

void ActionsPackageImpl::createClearStructuralFeatureActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_clearStructuralFeatureActionActivation_Class = factory->createEClass_in_EPackage(package, CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS);
	
	
	m_clearStructuralFeatureActionActivation_Operation_doAction = factory->createEOperation_in_EContainingClass(m_clearStructuralFeatureActionActivation_Class, CLEARSTRUCTURALFEATUREACTIONACTIVATION_OPERATION_DOACTION);
	
}

void ActionsPackageImpl::createConditionalNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_conditionalNodeActivation_Class = factory->createEClass_in_EPackage(package, CONDITIONALNODEACTIVATION_CLASS);
	
	m_conditionalNodeActivation_Attribute_clauseActivations = factory->createEReference_in_EContainingClass(m_conditionalNodeActivation_Class, CONDITIONALNODEACTIVATION_ATTRIBUTE_CLAUSEACTIVATIONS);
	m_conditionalNodeActivation_Attribute_selectedClauses = factory->createEReference_in_EContainingClass(m_conditionalNodeActivation_Class, CONDITIONALNODEACTIVATION_ATTRIBUTE_SELECTEDCLAUSES);
	
	m_conditionalNodeActivation_Operation_getClauseActivation_Clause = factory->createEOperation_in_EContainingClass(m_conditionalNodeActivation_Class, CONDITIONALNODEACTIVATION_OPERATION_GETCLAUSEACTIVATION_CLAUSE);
	m_conditionalNodeActivation_Operation_runTest_Clause = factory->createEOperation_in_EContainingClass(m_conditionalNodeActivation_Class, CONDITIONALNODEACTIVATION_OPERATION_RUNTEST_CLAUSE);
	m_conditionalNodeActivation_Operation_selectBody_Clause = factory->createEOperation_in_EContainingClass(m_conditionalNodeActivation_Class, CONDITIONALNODEACTIVATION_OPERATION_SELECTBODY_CLAUSE);
	
}

void ActionsPackageImpl::createCreateLinkActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_createLinkActionActivation_Class = factory->createEClass_in_EPackage(package, CREATELINKACTIONACTIVATION_CLASS);
	
	
	
}

void ActionsPackageImpl::createCreateObjectActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_createObjectActionActivation_Class = factory->createEClass_in_EPackage(package, CREATEOBJECTACTIONACTIVATION_CLASS);
	
	
	m_createObjectActionActivation_Operation_doAction = factory->createEOperation_in_EContainingClass(m_createObjectActionActivation_Class, CREATEOBJECTACTIONACTIVATION_OPERATION_DOACTION);
	
}

void ActionsPackageImpl::createDestroyLinkActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_destroyLinkActionActivation_Class = factory->createEClass_in_EPackage(package, DESTROYLINKACTIONACTIVATION_CLASS);
	
	
	
}

void ActionsPackageImpl::createDestroyObjectActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_destroyObjectActionActivation_Class = factory->createEClass_in_EPackage(package, DESTROYOBJECTACTIONACTIVATION_CLASS);
	
	
	m_destroyObjectActionActivation_Operation_destroyObject_Value_EBoolean = factory->createEOperation_in_EContainingClass(m_destroyObjectActionActivation_Class, DESTROYOBJECTACTIONACTIVATION_OPERATION_DESTROYOBJECT_VALUE_EBOOLEAN);
	m_destroyObjectActionActivation_Operation_doAction = factory->createEOperation_in_EContainingClass(m_destroyObjectActionActivation_Class, DESTROYOBJECTACTIONACTIVATION_OPERATION_DOACTION);
	m_destroyObjectActionActivation_Operation_objectIsComposite_Reference_Link = factory->createEOperation_in_EContainingClass(m_destroyObjectActionActivation_Class, DESTROYOBJECTACTIONACTIVATION_OPERATION_OBJECTISCOMPOSITE_REFERENCE_LINK);
	
}

void ActionsPackageImpl::createInputPinActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_inputPinActivation_Class = factory->createEClass_in_EPackage(package, INPUTPINACTIVATION_CLASS);
	
	
	m_inputPinActivation_Operation_isReady = factory->createEOperation_in_EContainingClass(m_inputPinActivation_Class, INPUTPINACTIVATION_OPERATION_ISREADY);
	m_inputPinActivation_Operation_receiveOffer = factory->createEOperation_in_EContainingClass(m_inputPinActivation_Class, INPUTPINACTIVATION_OPERATION_RECEIVEOFFER);
	
}

void ActionsPackageImpl::createInvocationActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_invocationActionActivation_Class = factory->createEClass_in_EPackage(package, INVOCATIONACTIONACTIVATION_CLASS);
	
	
	
}

void ActionsPackageImpl::createLinkActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_linkActionActivation_Class = factory->createEClass_in_EPackage(package, LINKACTIONACTIVATION_CLASS);
	
	
	m_linkActionActivation_Operation_endMatchesEndData_Link_LinkEndData = factory->createEOperation_in_EContainingClass(m_linkActionActivation_Class, LINKACTIONACTIVATION_OPERATION_ENDMATCHESENDDATA_LINK_LINKENDDATA);
	m_linkActionActivation_Operation_getAssociation = factory->createEOperation_in_EContainingClass(m_linkActionActivation_Class, LINKACTIONACTIVATION_OPERATION_GETASSOCIATION);
	m_linkActionActivation_Operation_linkMatchesEndData_Link_LinkEndData = factory->createEOperation_in_EContainingClass(m_linkActionActivation_Class, LINKACTIONACTIVATION_OPERATION_LINKMATCHESENDDATA_LINK_LINKENDDATA);
	
}

void ActionsPackageImpl::createLoopNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_loopNodeActivation_Class = factory->createEClass_in_EPackage(package, LOOPNODEACTIVATION_CLASS);
	
	m_loopNodeActivation_Attribute_bodyOutputLists = factory->createEReference_in_EContainingClass(m_loopNodeActivation_Class, LOOPNODEACTIVATION_ATTRIBUTE_BODYOUTPUTLISTS);
	
	m_loopNodeActivation_Operation_makeLoopVariableList = factory->createEOperation_in_EContainingClass(m_loopNodeActivation_Class, LOOPNODEACTIVATION_OPERATION_MAKELOOPVARIABLELIST);
	m_loopNodeActivation_Operation_runBody = factory->createEOperation_in_EContainingClass(m_loopNodeActivation_Class, LOOPNODEACTIVATION_OPERATION_RUNBODY);
	m_loopNodeActivation_Operation_runLoopVariables = factory->createEOperation_in_EContainingClass(m_loopNodeActivation_Class, LOOPNODEACTIVATION_OPERATION_RUNLOOPVARIABLES);
	m_loopNodeActivation_Operation_runTest = factory->createEOperation_in_EContainingClass(m_loopNodeActivation_Class, LOOPNODEACTIVATION_OPERATION_RUNTEST);
	
}

void ActionsPackageImpl::createOutputPinActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_outputPinActivation_Class = factory->createEClass_in_EPackage(package, OUTPUTPINACTIVATION_CLASS);
	
	
	
}

void ActionsPackageImpl::createPinActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_pinActivation_Class = factory->createEClass_in_EPackage(package, PINACTIVATION_CLASS);
	
	m_pinActivation_Attribute_actionActivation = factory->createEReference_in_EContainingClass(m_pinActivation_Class, PINACTIVATION_ATTRIBUTE_ACTIONACTIVATION);
	
	m_pinActivation_Operation_fire_Token = factory->createEOperation_in_EContainingClass(m_pinActivation_Class, PINACTIVATION_OPERATION_FIRE_TOKEN);
	m_pinActivation_Operation_takeOfferedTokens = factory->createEOperation_in_EContainingClass(m_pinActivation_Class, PINACTIVATION_OPERATION_TAKEOFFEREDTOKENS);
	
}

void ActionsPackageImpl::createReadExtentActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_readExtentActionActivation_Class = factory->createEClass_in_EPackage(package, READEXTENTACTIONACTIVATION_CLASS);
	
	
	
}

void ActionsPackageImpl::createReadIsClassifiedObjectActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_readIsClassifiedObjectActionActivation_Class = factory->createEClass_in_EPackage(package, READISCLASSIFIEDOBJECTACTIONACTIVATION_CLASS);
	
	
	m_readIsClassifiedObjectActionActivation_Operation_checkAllParents_Classifier_Classifier = factory->createEOperation_in_EContainingClass(m_readIsClassifiedObjectActionActivation_Class, READISCLASSIFIEDOBJECTACTIONACTIVATION_OPERATION_CHECKALLPARENTS_CLASSIFIER_CLASSIFIER);
	
}

void ActionsPackageImpl::createReadLinkActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_readLinkActionActivation_Class = factory->createEClass_in_EPackage(package, READLINKACTIONACTIVATION_CLASS);
	
	
	
}

void ActionsPackageImpl::createReadSelfActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_readSelfActionActivation_Class = factory->createEClass_in_EPackage(package, READSELFACTIONACTIVATION_CLASS);
	
	
	m_readSelfActionActivation_Operation_doAction = factory->createEOperation_in_EContainingClass(m_readSelfActionActivation_Class, READSELFACTIONACTIVATION_OPERATION_DOACTION);
	
}

void ActionsPackageImpl::createReadStructuralFeatureActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_readStructuralFeatureActionActivation_Class = factory->createEClass_in_EPackage(package, READSTRUCTURALFEATUREACTIONACTIVATION_CLASS);
	
	
	m_readStructuralFeatureActionActivation_Operation_doAction = factory->createEOperation_in_EContainingClass(m_readStructuralFeatureActionActivation_Class, READSTRUCTURALFEATUREACTIONACTIVATION_OPERATION_DOACTION);
	
}

void ActionsPackageImpl::createReclassifyObjectActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_reclassifyObjectActionActivation_Class = factory->createEClass_in_EPackage(package, RECLASSIFYOBJECTACTIONACTIVATION_CLASS);
	
	
	
}

void ActionsPackageImpl::createReduceActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_reduceActionActivation_Class = factory->createEClass_in_EPackage(package, REDUCEACTIONACTIVATION_CLASS);
	
	m_reduceActionActivation_Attribute_currentExecution = factory->createEReference_in_EContainingClass(m_reduceActionActivation_Class, REDUCEACTIONACTIVATION_ATTRIBUTE_CURRENTEXECUTION);
	
	
}

void ActionsPackageImpl::createRemoveStructuralFeatureValueActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_removeStructuralFeatureValueActivation_Class = factory->createEClass_in_EPackage(package, REMOVESTRUCTURALFEATUREVALUEACTIVATION_CLASS);
	
	
	m_removeStructuralFeatureValueActivation_Operation_doAction = factory->createEOperation_in_EContainingClass(m_removeStructuralFeatureValueActivation_Class, REMOVESTRUCTURALFEATUREVALUEACTIVATION_OPERATION_DOACTION);
	
}

void ActionsPackageImpl::createReplyActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_replyActionActivation_Class = factory->createEClass_in_EPackage(package, REPLYACTIONACTIVATION_CLASS);
	
	
	m_replyActionActivation_Operation_doAction = factory->createEOperation_in_EContainingClass(m_replyActionActivation_Class, REPLYACTIONACTIVATION_OPERATION_DOACTION);
	
}

void ActionsPackageImpl::createReturnInformationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
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

void ActionsPackageImpl::createSendSignalActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_sendSignalActionActivation_Class = factory->createEClass_in_EPackage(package, SENDSIGNALACTIONACTIVATION_CLASS);
	
	
	m_sendSignalActionActivation_Operation_doAction = factory->createEOperation_in_EContainingClass(m_sendSignalActionActivation_Class, SENDSIGNALACTIONACTIVATION_OPERATION_DOACTION);
	
}

void ActionsPackageImpl::createStartClassifierBehaviorActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_startClassifierBehaviorActionActivation_Class = factory->createEClass_in_EPackage(package, STARTCLASSIFIERBEHAVIORACTIONACTIVATION_CLASS);
	
	
	m_startClassifierBehaviorActionActivation_Operation_doAction = factory->createEOperation_in_EContainingClass(m_startClassifierBehaviorActionActivation_Class, STARTCLASSIFIERBEHAVIORACTIONACTIVATION_OPERATION_DOACTION);
	
}

void ActionsPackageImpl::createStartObjectBehaviorActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_startObjectBehaviorActionActivation_Class = factory->createEClass_in_EPackage(package, STARTOBJECTBEHAVIORACTIONACTIVATION_CLASS);
	
	
	m_startObjectBehaviorActionActivation_Operation_doAction = factory->createEOperation_in_EContainingClass(m_startObjectBehaviorActionActivation_Class, STARTOBJECTBEHAVIORACTIONACTIVATION_OPERATION_DOACTION);
	
}

void ActionsPackageImpl::createStructuralFeatureActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_structuralFeatureActionActivation_Class = factory->createEClass_in_EPackage(package, STRUCTURALFEATUREACTIONACTIVATION_CLASS);
	
	
	m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature = factory->createEOperation_in_EContainingClass(m_structuralFeatureActionActivation_Class, STRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETASSOCIATION_STRUCTURALFEATURE);
	m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_Value = factory->createEOperation_in_EContainingClass(m_structuralFeatureActionActivation_Class, STRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETMATCHINGLINKS_ASSOCIATION_VALUE);
	m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_Value = factory->createEOperation_in_EContainingClass(m_structuralFeatureActionActivation_Class, STRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETMATCHINGLINKSFORENDVALUE_ASSOCIATION_VALUE);
	m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature = factory->createEOperation_in_EContainingClass(m_structuralFeatureActionActivation_Class, STRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETOPPOSITEEND_ASSOCIATION_STRUCTURALFEATURE);
	
}

void ActionsPackageImpl::createStructuredActivityNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
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

void ActionsPackageImpl::createTestIdentityActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_testIdentityActionActivation_Class = factory->createEClass_in_EPackage(package, TESTIDENTITYACTIONACTIVATION_CLASS);
	
	
	
}

void ActionsPackageImpl::createValueSpecificationActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_valueSpecificationActionActivation_Class = factory->createEClass_in_EPackage(package, VALUESPECIFICATIONACTIONACTIVATION_CLASS);
	
	
	m_valueSpecificationActionActivation_Operation_doAction = factory->createEOperation_in_EContainingClass(m_valueSpecificationActionActivation_Class, VALUESPECIFICATIONACTIONACTIVATION_OPERATION_DOACTION);
	
}

void ActionsPackageImpl::createValuesContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_values_Class = factory->createEClass_in_EPackage(package, VALUES_CLASS);
	
	m_values_Attribute_values = factory->createEReference_in_EContainingClass(m_values_Class, VALUES_ATTRIBUTE_VALUES);
	
	
}

void ActionsPackageImpl::createWriteLinkActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_writeLinkActionActivation_Class = factory->createEClass_in_EPackage(package, WRITELINKACTIONACTIVATION_CLASS);
	
	
	
}

void ActionsPackageImpl::createWriteStructuralFeatureActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_writeStructuralFeatureActionActivation_Class = factory->createEClass_in_EPackage(package, WRITESTRUCTURALFEATUREACTIONACTIVATION_CLASS);
	
	
	m_writeStructuralFeatureActionActivation_Operation_position_Value_EInt = factory->createEOperation_in_EContainingClass(m_writeStructuralFeatureActionActivation_Class, WRITESTRUCTURALFEATUREACTIONACTIVATION_OPERATION_POSITION_VALUE_EINT);
	
}

void ActionsPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	
}
