#include "fUML/Semantics/Actions/impl/ActionsPackageImpl.hpp"

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

//metamodel factory
#include "fUML/Semantics/Actions/ActionsFactory.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::Actions;

bool ActionsPackageImpl::isInited = false;

ActionsPackageImpl::ActionsPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( ActionsFactory::eInstance()));
}

ActionsPackageImpl::~ActionsPackageImpl()
{
}

ActionsPackage* ActionsPackageImpl::create()
{
	if (isInited)
	{
		return ActionsPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    ActionsPackageImpl * metaModelPackage = new ActionsPackageImpl();
    return metaModelPackage;
}

void ActionsPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}



// Begin Class AcceptCallActionActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getAcceptCallActionActivation_Class() const
{
	return m_acceptCallActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getAcceptCallActionActivation_Operation_accept_EventOccurrence() const
{
	return m_acceptCallActionActivation_Operation_accept_EventOccurrence;
}

// End Class AcceptCallActionActivation

// Begin Class AcceptCallActionActivations
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getAcceptCallActionActivations_Class() const
{
	return m_acceptCallActionActivations_Class;
}




// End Class AcceptCallActionActivations

// Begin Class AcceptEventActionActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getAcceptEventActionActivation_Class() const
{
	return m_acceptEventActionActivation_Class;
}

std::shared_ptr<ecore::EAttribute> ActionsPackageImpl::getAcceptEventActionActivation_Attribute_waiting() const
{
	return m_acceptEventActionActivation_Attribute_waiting;
}

std::shared_ptr<ecore::EReference> ActionsPackageImpl::getAcceptEventActionActivation_Attribute_eventAccepter() const
{
	return m_acceptEventActionActivation_Attribute_eventAccepter;
}

std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getAcceptEventActionActivation_Operation_accept_EventOccurrence() const
{
	return m_acceptEventActionActivation_Operation_accept_EventOccurrence;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getAcceptEventActionActivation_Operation_doAction() const
{
	return m_acceptEventActionActivation_Operation_doAction;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getAcceptEventActionActivation_Operation_fire_Token() const
{
	return m_acceptEventActionActivation_Operation_fire_Token;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getAcceptEventActionActivation_Operation_initialize_ActivityNode_ActivityNodeActivationGroup() const
{
	return m_acceptEventActionActivation_Operation_initialize_ActivityNode_ActivityNodeActivationGroup;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getAcceptEventActionActivation_Operation_isReady() const
{
	return m_acceptEventActionActivation_Operation_isReady;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getAcceptEventActionActivation_Operation_match_EventOccurrence() const
{
	return m_acceptEventActionActivation_Operation_match_EventOccurrence;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getAcceptEventActionActivation_Operation_run() const
{
	return m_acceptEventActionActivation_Operation_run;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getAcceptEventActionActivation_Operation_terminate() const
{
	return m_acceptEventActionActivation_Operation_terminate;
}

// End Class AcceptEventActionActivation

// Begin Class AcceptEventActionEventAccepter
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getAcceptEventActionEventAccepter_Class() const
{
	return m_acceptEventActionEventAccepter_Class;
}


std::shared_ptr<ecore::EReference> ActionsPackageImpl::getAcceptEventActionEventAccepter_Attribute_actionActivation() const
{
	return m_acceptEventActionEventAccepter_Attribute_actionActivation;
}


// End Class AcceptEventActionEventAccepter

// Begin Class ActionActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getActionActivation_Class() const
{
	return m_actionActivation_Class;
}

std::shared_ptr<ecore::EAttribute> ActionsPackageImpl::getActionActivation_Attribute_firing() const
{
	return m_actionActivation_Attribute_firing;
}

std::shared_ptr<ecore::EReference> ActionsPackageImpl::getActionActivation_Attribute_action() const
{
	return m_actionActivation_Attribute_action;
}
std::shared_ptr<ecore::EReference> ActionsPackageImpl::getActionActivation_Attribute_inputPinActivation() const
{
	return m_actionActivation_Attribute_inputPinActivation;
}
std::shared_ptr<ecore::EReference> ActionsPackageImpl::getActionActivation_Attribute_outputPinActivation() const
{
	return m_actionActivation_Attribute_outputPinActivation;
}
std::shared_ptr<ecore::EReference> ActionsPackageImpl::getActionActivation_Attribute_pinActivation() const
{
	return m_actionActivation_Attribute_pinActivation;
}

std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getActionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance() const
{
	return m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getActionActivation_Operation_addPinActivation_PinActivation() const
{
	return m_actionActivation_Operation_addPinActivation_PinActivation;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getActionActivation_Operation_completeAction() const
{
	return m_actionActivation_Operation_completeAction;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getActionActivation_Operation_createNodeActivations() const
{
	return m_actionActivation_Operation_createNodeActivations;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getActionActivation_Operation_doAction() const
{
	return m_actionActivation_Operation_doAction;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getActionActivation_Operation_fire_Token() const
{
	return m_actionActivation_Operation_fire_Token;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getActionActivation_Operation_getTokens_InputPin() const
{
	return m_actionActivation_Operation_getTokens_InputPin;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getActionActivation_Operation_isFirng() const
{
	return m_actionActivation_Operation_isFirng;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getActionActivation_Operation_isReady() const
{
	return m_actionActivation_Operation_isReady;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getActionActivation_Operation_isSourceFor_ActivityEdgeInstance() const
{
	return m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getActionActivation_Operation_makeBooleanValue_EBoolean() const
{
	return m_actionActivation_Operation_makeBooleanValue_EBoolean;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getActionActivation_Operation_putToken_OutputPin_Value() const
{
	return m_actionActivation_Operation_putToken_OutputPin_Value;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getActionActivation_Operation_putTokens_OutputPin_Value() const
{
	return m_actionActivation_Operation_putTokens_OutputPin_Value;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getActionActivation_Operation_retrievePinActivation_Pin() const
{
	return m_actionActivation_Operation_retrievePinActivation_Pin;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getActionActivation_Operation_run() const
{
	return m_actionActivation_Operation_run;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getActionActivation_Operation_sendOffers() const
{
	return m_actionActivation_Operation_sendOffers;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getActionActivation_Operation_takeOfferedTokens() const
{
	return m_actionActivation_Operation_takeOfferedTokens;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getActionActivation_Operation_takeTokens_InputPin() const
{
	return m_actionActivation_Operation_takeTokens_InputPin;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getActionActivation_Operation_terminate() const
{
	return m_actionActivation_Operation_terminate;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getActionActivation_Operation_valueParticipatesInLink_Value_Link() const
{
	return m_actionActivation_Operation_valueParticipatesInLink_Value_Link;
}

// End Class ActionActivation

// Begin Class AddStructuralFeatureValueActionActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getAddStructuralFeatureValueActionActivation_Class() const
{
	return m_addStructuralFeatureValueActionActivation_Class;
}


std::shared_ptr<ecore::EReference> ActionsPackageImpl::getAddStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction() const
{
	return m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction;
}

std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getAddStructuralFeatureValueActionActivation_Operation_doAction() const
{
	return m_addStructuralFeatureValueActionActivation_Operation_doAction;
}

// End Class AddStructuralFeatureValueActionActivation

// Begin Class CallActionActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getCallActionActivation_Class() const
{
	return m_callActionActivation_Class;
}


std::shared_ptr<ecore::EReference> ActionsPackageImpl::getCallActionActivation_Attribute_callAction() const
{
	return m_callActionActivation_Attribute_callAction;
}
std::shared_ptr<ecore::EReference> ActionsPackageImpl::getCallActionActivation_Attribute_callExecutions() const
{
	return m_callActionActivation_Attribute_callExecutions;
}

std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getCallActionActivation_Operation_doAction() const
{
	return m_callActionActivation_Operation_doAction;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getCallActionActivation_Operation_getCallExecution() const
{
	return m_callActionActivation_Operation_getCallExecution;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getCallActionActivation_Operation_removeCallExecution_Execution() const
{
	return m_callActionActivation_Operation_removeCallExecution_Execution;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getCallActionActivation_Operation_terminate() const
{
	return m_callActionActivation_Operation_terminate;
}

// End Class CallActionActivation

// Begin Class CallBehaviorActionActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getCallBehaviorActionActivation_Class() const
{
	return m_callBehaviorActionActivation_Class;
}


std::shared_ptr<ecore::EReference> ActionsPackageImpl::getCallBehaviorActionActivation_Attribute_callBehaviorAction() const
{
	return m_callBehaviorActionActivation_Attribute_callBehaviorAction;
}

std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getCallBehaviorActionActivation_Operation_getCallExecution() const
{
	return m_callBehaviorActionActivation_Operation_getCallExecution;
}

// End Class CallBehaviorActionActivation

// Begin Class CallOperationActionActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getCallOperationActionActivation_Class() const
{
	return m_callOperationActionActivation_Class;
}


std::shared_ptr<ecore::EReference> ActionsPackageImpl::getCallOperationActionActivation_Attribute_callOperationAction() const
{
	return m_callOperationActionActivation_Attribute_callOperationAction;
}

std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getCallOperationActionActivation_Operation_getCallExecution() const
{
	return m_callOperationActionActivation_Operation_getCallExecution;
}

// End Class CallOperationActionActivation

// Begin Class ClauseActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getClauseActivation_Class() const
{
	return m_clauseActivation_Class;
}


std::shared_ptr<ecore::EReference> ActionsPackageImpl::getClauseActivation_Attribute_clause() const
{
	return m_clauseActivation_Attribute_clause;
}
std::shared_ptr<ecore::EReference> ActionsPackageImpl::getClauseActivation_Attribute_conditionalNodeActivation() const
{
	return m_clauseActivation_Attribute_conditionalNodeActivation;
}

std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getClauseActivation_Operation_getDecision() const
{
	return m_clauseActivation_Operation_getDecision;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getClauseActivation_Operation_getPredecessors() const
{
	return m_clauseActivation_Operation_getPredecessors;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getClauseActivation_Operation_getSuccessors() const
{
	return m_clauseActivation_Operation_getSuccessors;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getClauseActivation_Operation_isReady() const
{
	return m_clauseActivation_Operation_isReady;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getClauseActivation_Operation_recieveControl() const
{
	return m_clauseActivation_Operation_recieveControl;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getClauseActivation_Operation_runTest() const
{
	return m_clauseActivation_Operation_runTest;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getClauseActivation_Operation_selectBody() const
{
	return m_clauseActivation_Operation_selectBody;
}

// End Class ClauseActivation

// Begin Class ClearAssociationActionActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getClearAssociationActionActivation_Class() const
{
	return m_clearAssociationActionActivation_Class;
}




// End Class ClearAssociationActionActivation

// Begin Class ClearStructuralFeatureActionActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getClearStructuralFeatureActionActivation_Class() const
{
	return m_clearStructuralFeatureActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getClearStructuralFeatureActionActivation_Operation_doAction() const
{
	return m_clearStructuralFeatureActionActivation_Operation_doAction;
}

// End Class ClearStructuralFeatureActionActivation

// Begin Class ConditionalNodeActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getConditionalNodeActivation_Class() const
{
	return m_conditionalNodeActivation_Class;
}


std::shared_ptr<ecore::EReference> ActionsPackageImpl::getConditionalNodeActivation_Attribute_clauseActivations() const
{
	return m_conditionalNodeActivation_Attribute_clauseActivations;
}
std::shared_ptr<ecore::EReference> ActionsPackageImpl::getConditionalNodeActivation_Attribute_selectedClauses() const
{
	return m_conditionalNodeActivation_Attribute_selectedClauses;
}

std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getConditionalNodeActivation_Operation_getClauseActivation_Clause() const
{
	return m_conditionalNodeActivation_Operation_getClauseActivation_Clause;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getConditionalNodeActivation_Operation_runTest_Clause() const
{
	return m_conditionalNodeActivation_Operation_runTest_Clause;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getConditionalNodeActivation_Operation_selectBody_Clause() const
{
	return m_conditionalNodeActivation_Operation_selectBody_Clause;
}

// End Class ConditionalNodeActivation

// Begin Class CreateLinkActionActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getCreateLinkActionActivation_Class() const
{
	return m_createLinkActionActivation_Class;
}




// End Class CreateLinkActionActivation

// Begin Class CreateObjectActionActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getCreateObjectActionActivation_Class() const
{
	return m_createObjectActionActivation_Class;
}


std::shared_ptr<ecore::EReference> ActionsPackageImpl::getCreateObjectActionActivation_Attribute_createObjectAction() const
{
	return m_createObjectActionActivation_Attribute_createObjectAction;
}

std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getCreateObjectActionActivation_Operation_doAction() const
{
	return m_createObjectActionActivation_Operation_doAction;
}

// End Class CreateObjectActionActivation

// Begin Class DestroyLinkActionActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getDestroyLinkActionActivation_Class() const
{
	return m_destroyLinkActionActivation_Class;
}




// End Class DestroyLinkActionActivation

// Begin Class DestroyObjectActionActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getDestroyObjectActionActivation_Class() const
{
	return m_destroyObjectActionActivation_Class;
}


std::shared_ptr<ecore::EReference> ActionsPackageImpl::getDestroyObjectActionActivation_Attribute_destroyObjectAction() const
{
	return m_destroyObjectActionActivation_Attribute_destroyObjectAction;
}

std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getDestroyObjectActionActivation_Operation_destroyObject_Value_EBoolean() const
{
	return m_destroyObjectActionActivation_Operation_destroyObject_Value_EBoolean;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getDestroyObjectActionActivation_Operation_doAction() const
{
	return m_destroyObjectActionActivation_Operation_doAction;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getDestroyObjectActionActivation_Operation_objectIsComposite_Reference_Link() const
{
	return m_destroyObjectActionActivation_Operation_objectIsComposite_Reference_Link;
}

// End Class DestroyObjectActionActivation

// Begin Class InputPinActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getInputPinActivation_Class() const
{
	return m_inputPinActivation_Class;
}



std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getInputPinActivation_Operation_isReady() const
{
	return m_inputPinActivation_Operation_isReady;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getInputPinActivation_Operation_receiveOffer() const
{
	return m_inputPinActivation_Operation_receiveOffer;
}

// End Class InputPinActivation

// Begin Class InvocationActionActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getInvocationActionActivation_Class() const
{
	return m_invocationActionActivation_Class;
}




// End Class InvocationActionActivation

// Begin Class LinkActionActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getLinkActionActivation_Class() const
{
	return m_linkActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getLinkActionActivation_Operation_endMatchesEndData_Link_LinkEndData() const
{
	return m_linkActionActivation_Operation_endMatchesEndData_Link_LinkEndData;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getLinkActionActivation_Operation_getAssociation() const
{
	return m_linkActionActivation_Operation_getAssociation;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getLinkActionActivation_Operation_linkMatchesEndData_Link_LinkEndData() const
{
	return m_linkActionActivation_Operation_linkMatchesEndData_Link_LinkEndData;
}

// End Class LinkActionActivation

// Begin Class LoopNodeActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getLoopNodeActivation_Class() const
{
	return m_loopNodeActivation_Class;
}


std::shared_ptr<ecore::EReference> ActionsPackageImpl::getLoopNodeActivation_Attribute_bodyOutputLists() const
{
	return m_loopNodeActivation_Attribute_bodyOutputLists;
}

std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getLoopNodeActivation_Operation_makeLoopVariableList() const
{
	return m_loopNodeActivation_Operation_makeLoopVariableList;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getLoopNodeActivation_Operation_runBody() const
{
	return m_loopNodeActivation_Operation_runBody;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getLoopNodeActivation_Operation_runLoopVariables() const
{
	return m_loopNodeActivation_Operation_runLoopVariables;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getLoopNodeActivation_Operation_runTest() const
{
	return m_loopNodeActivation_Operation_runTest;
}

// End Class LoopNodeActivation

// Begin Class OutputPinActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getOutputPinActivation_Class() const
{
	return m_outputPinActivation_Class;
}




// End Class OutputPinActivation

// Begin Class PinActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getPinActivation_Class() const
{
	return m_pinActivation_Class;
}


std::shared_ptr<ecore::EReference> ActionsPackageImpl::getPinActivation_Attribute_actionActivation() const
{
	return m_pinActivation_Attribute_actionActivation;
}
std::shared_ptr<ecore::EReference> ActionsPackageImpl::getPinActivation_Attribute_pin() const
{
	return m_pinActivation_Attribute_pin;
}

std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getPinActivation_Operation_fire_Token() const
{
	return m_pinActivation_Operation_fire_Token;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getPinActivation_Operation_takeOfferedTokens() const
{
	return m_pinActivation_Operation_takeOfferedTokens;
}

// End Class PinActivation

// Begin Class ReadExtentActionActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getReadExtentActionActivation_Class() const
{
	return m_readExtentActionActivation_Class;
}




// End Class ReadExtentActionActivation

// Begin Class ReadIsClassifiedObjectActionActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getReadIsClassifiedObjectActionActivation_Class() const
{
	return m_readIsClassifiedObjectActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getReadIsClassifiedObjectActionActivation_Operation_checkAllParents_Classifier_Classifier() const
{
	return m_readIsClassifiedObjectActionActivation_Operation_checkAllParents_Classifier_Classifier;
}

// End Class ReadIsClassifiedObjectActionActivation

// Begin Class ReadLinkActionActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getReadLinkActionActivation_Class() const
{
	return m_readLinkActionActivation_Class;
}




// End Class ReadLinkActionActivation

// Begin Class ReadSelfActionActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getReadSelfActionActivation_Class() const
{
	return m_readSelfActionActivation_Class;
}


std::shared_ptr<ecore::EReference> ActionsPackageImpl::getReadSelfActionActivation_Attribute_readSelfAction() const
{
	return m_readSelfActionActivation_Attribute_readSelfAction;
}

std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getReadSelfActionActivation_Operation_doAction() const
{
	return m_readSelfActionActivation_Operation_doAction;
}

// End Class ReadSelfActionActivation

// Begin Class ReadStructuralFeatureActionActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getReadStructuralFeatureActionActivation_Class() const
{
	return m_readStructuralFeatureActionActivation_Class;
}


std::shared_ptr<ecore::EReference> ActionsPackageImpl::getReadStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction() const
{
	return m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction;
}

std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getReadStructuralFeatureActionActivation_Operation_doAction() const
{
	return m_readStructuralFeatureActionActivation_Operation_doAction;
}

// End Class ReadStructuralFeatureActionActivation

// Begin Class ReclassifyObjectActionActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getReclassifyObjectActionActivation_Class() const
{
	return m_reclassifyObjectActionActivation_Class;
}




// End Class ReclassifyObjectActionActivation

// Begin Class ReduceActionActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getReduceActionActivation_Class() const
{
	return m_reduceActionActivation_Class;
}


std::shared_ptr<ecore::EReference> ActionsPackageImpl::getReduceActionActivation_Attribute_currentExecution() const
{
	return m_reduceActionActivation_Attribute_currentExecution;
}


// End Class ReduceActionActivation

// Begin Class RemoveStructuralFeatureValueActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getRemoveStructuralFeatureValueActivation_Class() const
{
	return m_removeStructuralFeatureValueActivation_Class;
}


std::shared_ptr<ecore::EReference> ActionsPackageImpl::getRemoveStructuralFeatureValueActivation_Attribute_removeStructuralFeatureValueAction() const
{
	return m_removeStructuralFeatureValueActivation_Attribute_removeStructuralFeatureValueAction;
}

std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getRemoveStructuralFeatureValueActivation_Operation_doAction() const
{
	return m_removeStructuralFeatureValueActivation_Operation_doAction;
}

// End Class RemoveStructuralFeatureValueActivation

// Begin Class ReplyActionActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getReplyActionActivation_Class() const
{
	return m_replyActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getReplyActionActivation_Operation_doAction() const
{
	return m_replyActionActivation_Operation_doAction;
}

// End Class ReplyActionActivation

// Begin Class ReturnInformation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getReturnInformation_Class() const
{
	return m_returnInformation_Class;
}


std::shared_ptr<ecore::EReference> ActionsPackageImpl::getReturnInformation_Attribute_callEventOccurrence() const
{
	return m_returnInformation_Attribute_callEventOccurrence;
}

std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getReturnInformation_Operation__copy() const
{
	return m_returnInformation_Operation__copy;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getReturnInformation_Operation_equals_Value() const
{
	return m_returnInformation_Operation_equals_Value;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getReturnInformation_Operation_getOperation() const
{
	return m_returnInformation_Operation_getOperation;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getReturnInformation_Operation_getTypes() const
{
	return m_returnInformation_Operation_getTypes;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getReturnInformation_Operation_new_() const
{
	return m_returnInformation_Operation_new_;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getReturnInformation_Operation_reply_ParameterValue() const
{
	return m_returnInformation_Operation_reply_ParameterValue;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getReturnInformation_Operation_specify() const
{
	return m_returnInformation_Operation_specify;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getReturnInformation_Operation_toString() const
{
	return m_returnInformation_Operation_toString;
}

// End Class ReturnInformation

// Begin Class SendSignalActionActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getSendSignalActionActivation_Class() const
{
	return m_sendSignalActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getSendSignalActionActivation_Operation_doAction() const
{
	return m_sendSignalActionActivation_Operation_doAction;
}

// End Class SendSignalActionActivation

// Begin Class StartClassifierBehaviorActionActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getStartClassifierBehaviorActionActivation_Class() const
{
	return m_startClassifierBehaviorActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getStartClassifierBehaviorActionActivation_Operation_doAction() const
{
	return m_startClassifierBehaviorActionActivation_Operation_doAction;
}

// End Class StartClassifierBehaviorActionActivation

// Begin Class StartObjectBehaviorActionActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getStartObjectBehaviorActionActivation_Class() const
{
	return m_startObjectBehaviorActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getStartObjectBehaviorActionActivation_Operation_doAction() const
{
	return m_startObjectBehaviorActionActivation_Operation_doAction;
}

// End Class StartObjectBehaviorActionActivation

// Begin Class StructuralFeatureActionActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getStructuralFeatureActionActivation_Class() const
{
	return m_structuralFeatureActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getStructuralFeatureActionActivation_Operation_getAssociation_StructuralFeature() const
{
	return m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getStructuralFeatureActionActivation_Operation_getMatchingLinks_Association_Value() const
{
	return m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_Value;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getStructuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_Value() const
{
	return m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_Value;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getStructuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature() const
{
	return m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature;
}

// End Class StructuralFeatureActionActivation

// Begin Class StructuredActivityNodeActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getStructuredActivityNodeActivation_Class() const
{
	return m_structuredActivityNodeActivation_Class;
}


std::shared_ptr<ecore::EReference> ActionsPackageImpl::getStructuredActivityNodeActivation_Attribute_activationGroup() const
{
	return m_structuredActivityNodeActivation_Attribute_activationGroup;
}

std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_completeAction() const
{
	return m_structuredActivityNodeActivation_Operation_completeAction;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_createEdgeInstances() const
{
	return m_structuredActivityNodeActivation_Operation_createEdgeInstances;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_createNodeActivations() const
{
	return m_structuredActivityNodeActivation_Operation_createNodeActivations;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_doAction() const
{
	return m_structuredActivityNodeActivation_Operation_doAction;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_doStructuredActivity() const
{
	return m_structuredActivityNodeActivation_Operation_doStructuredActivity;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode() const
{
	return m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_getPinValues_OutputPin() const
{
	return m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance() const
{
	return m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_isSuspended() const
{
	return m_structuredActivityNodeActivation_Operation_isSuspended;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode() const
{
	return m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_putPinValues_OutputPin_Value() const
{
	return m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_Value;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_resume() const
{
	return m_structuredActivityNodeActivation_Operation_resume;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_terminate() const
{
	return m_structuredActivityNodeActivation_Operation_terminate;
}
std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_terminateAll() const
{
	return m_structuredActivityNodeActivation_Operation_terminateAll;
}

// End Class StructuredActivityNodeActivation

// Begin Class TestIdentityActionActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getTestIdentityActionActivation_Class() const
{
	return m_testIdentityActionActivation_Class;
}




// End Class TestIdentityActionActivation

// Begin Class ValueSpecificationActionActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getValueSpecificationActionActivation_Class() const
{
	return m_valueSpecificationActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getValueSpecificationActionActivation_Operation_doAction() const
{
	return m_valueSpecificationActionActivation_Operation_doAction;
}

// End Class ValueSpecificationActionActivation

// Begin Class Values
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getValues_Class() const
{
	return m_values_Class;
}


std::shared_ptr<ecore::EReference> ActionsPackageImpl::getValues_Attribute_values() const
{
	return m_values_Attribute_values;
}


// End Class Values

// Begin Class WriteLinkActionActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getWriteLinkActionActivation_Class() const
{
	return m_writeLinkActionActivation_Class;
}




// End Class WriteLinkActionActivation

// Begin Class WriteStructuralFeatureActionActivation
std::shared_ptr<ecore::EClass> ActionsPackageImpl::getWriteStructuralFeatureActionActivation_Class() const
{
	return m_writeStructuralFeatureActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> ActionsPackageImpl::getWriteStructuralFeatureActionActivation_Operation_position_Value_EInt() const
{
	return m_writeStructuralFeatureActionActivation_Operation_position_Value_EInt;
}

// End Class WriteStructuralFeatureActionActivation

