#include "fUML/Semantics/Actions/impl/ActionsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EReference.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"

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
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getAcceptCallActionActivation_Class() const
{
	return m_acceptCallActionActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getAcceptCallActionActivation_Operation_accept_EventOccurrence() const
{
	return m_acceptCallActionActivation_Operation_accept_EventOccurrence;
}

// End Class AcceptCallActionActivation

// Begin Class AcceptCallActionActivations
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getAcceptCallActionActivations_Class() const
{
	return m_acceptCallActionActivations_Class;
}




// End Class AcceptCallActionActivations

// Begin Class AcceptEventActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getAcceptEventActionActivation_Class() const
{
	return m_acceptEventActionActivation_Class;
}

const std::shared_ptr<ecore::EAttribute>& fUML::Semantics::Actions::ActionsPackageImpl::getAcceptEventActionActivation_Attribute_waiting() const
{
	return m_acceptEventActionActivation_Attribute_waiting;
}

const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getAcceptEventActionActivation_Attribute_eventAccepter() const
{
	return m_acceptEventActionActivation_Attribute_eventAccepter;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getAcceptEventActionActivation_Operation_accept_EventOccurrence() const
{
	return m_acceptEventActionActivation_Operation_accept_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getAcceptEventActionActivation_Operation_doAction() const
{
	return m_acceptEventActionActivation_Operation_doAction;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getAcceptEventActionActivation_Operation_fire_Token() const
{
	return m_acceptEventActionActivation_Operation_fire_Token;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getAcceptEventActionActivation_Operation_initialize_ActivityNode_ActivityNodeActivationGroup() const
{
	return m_acceptEventActionActivation_Operation_initialize_ActivityNode_ActivityNodeActivationGroup;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getAcceptEventActionActivation_Operation_isReady() const
{
	return m_acceptEventActionActivation_Operation_isReady;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getAcceptEventActionActivation_Operation_match_EventOccurrence() const
{
	return m_acceptEventActionActivation_Operation_match_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getAcceptEventActionActivation_Operation_run() const
{
	return m_acceptEventActionActivation_Operation_run;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getAcceptEventActionActivation_Operation_terminate() const
{
	return m_acceptEventActionActivation_Operation_terminate;
}

// End Class AcceptEventActionActivation

// Begin Class AcceptEventActionEventAccepter
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getAcceptEventActionEventAccepter_Class() const
{
	return m_acceptEventActionEventAccepter_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getAcceptEventActionEventAccepter_Attribute_actionActivation() const
{
	return m_acceptEventActionEventAccepter_Attribute_actionActivation;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getAcceptEventActionEventAccepter_Operation_accept_EventOccurrence() const
{
	return m_acceptEventActionEventAccepter_Operation_accept_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getAcceptEventActionEventAccepter_Operation_match_EventOccurrence() const
{
	return m_acceptEventActionEventAccepter_Operation_match_EventOccurrence;
}

// End Class AcceptEventActionEventAccepter

// Begin Class ActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Class() const
{
	return m_actionActivation_Class;
}

const std::shared_ptr<ecore::EAttribute>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Attribute_firing() const
{
	return m_actionActivation_Attribute_firing;
}

const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Attribute_action() const
{
	return m_actionActivation_Attribute_action;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Attribute_inputPinActivation() const
{
	return m_actionActivation_Attribute_inputPinActivation;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Attribute_outputPinActivation() const
{
	return m_actionActivation_Attribute_outputPinActivation;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Attribute_pinActivation() const
{
	return m_actionActivation_Attribute_pinActivation;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance() const
{
	return m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_addPinActivation_PinActivation() const
{
	return m_actionActivation_Operation_addPinActivation_PinActivation;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_completeAction() const
{
	return m_actionActivation_Operation_completeAction;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_createNodeActivations() const
{
	return m_actionActivation_Operation_createNodeActivations;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_doAction() const
{
	return m_actionActivation_Operation_doAction;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_fire_Token() const
{
	return m_actionActivation_Operation_fire_Token;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_getTokens_InputPin() const
{
	return m_actionActivation_Operation_getTokens_InputPin;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_initialize_ActivityNode_ActivityNodeActivationGroup() const
{
	return m_actionActivation_Operation_initialize_ActivityNode_ActivityNodeActivationGroup;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_isFirng() const
{
	return m_actionActivation_Operation_isFirng;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_isReady() const
{
	return m_actionActivation_Operation_isReady;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_isSourceFor_ActivityEdgeInstance() const
{
	return m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_makeBooleanValue_EBoolean() const
{
	return m_actionActivation_Operation_makeBooleanValue_EBoolean;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_putToken_OutputPin_Value() const
{
	return m_actionActivation_Operation_putToken_OutputPin_Value;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_putTokens_OutputPin_Value() const
{
	return m_actionActivation_Operation_putTokens_OutputPin_Value;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_retrievePinActivation_Pin() const
{
	return m_actionActivation_Operation_retrievePinActivation_Pin;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_run() const
{
	return m_actionActivation_Operation_run;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_sendOffers() const
{
	return m_actionActivation_Operation_sendOffers;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_takeOfferedTokens() const
{
	return m_actionActivation_Operation_takeOfferedTokens;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_takeTokens_InputPin() const
{
	return m_actionActivation_Operation_takeTokens_InputPin;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_terminate() const
{
	return m_actionActivation_Operation_terminate;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getActionActivation_Operation_valueParticipatesInLink_Value_Link() const
{
	return m_actionActivation_Operation_valueParticipatesInLink_Value_Link;
}

// End Class ActionActivation

// Begin Class AddStructuralFeatureValueActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getAddStructuralFeatureValueActionActivation_Class() const
{
	return m_addStructuralFeatureValueActionActivation_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getAddStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction() const
{
	return m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getAddStructuralFeatureValueActionActivation_Operation_doAction() const
{
	return m_addStructuralFeatureValueActionActivation_Operation_doAction;
}

// End Class AddStructuralFeatureValueActionActivation

// Begin Class CallActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getCallActionActivation_Class() const
{
	return m_callActionActivation_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getCallActionActivation_Attribute_callAction() const
{
	return m_callActionActivation_Attribute_callAction;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getCallActionActivation_Attribute_callExecutions() const
{
	return m_callActionActivation_Attribute_callExecutions;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getCallActionActivation_Operation_doAction() const
{
	return m_callActionActivation_Operation_doAction;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getCallActionActivation_Operation_getCallExecution() const
{
	return m_callActionActivation_Operation_getCallExecution;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getCallActionActivation_Operation_removeCallExecution_Execution() const
{
	return m_callActionActivation_Operation_removeCallExecution_Execution;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getCallActionActivation_Operation_terminate() const
{
	return m_callActionActivation_Operation_terminate;
}

// End Class CallActionActivation

// Begin Class CallBehaviorActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getCallBehaviorActionActivation_Class() const
{
	return m_callBehaviorActionActivation_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getCallBehaviorActionActivation_Attribute_callBehaviorAction() const
{
	return m_callBehaviorActionActivation_Attribute_callBehaviorAction;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getCallBehaviorActionActivation_Operation_getCallExecution() const
{
	return m_callBehaviorActionActivation_Operation_getCallExecution;
}

// End Class CallBehaviorActionActivation

// Begin Class CallOperationActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getCallOperationActionActivation_Class() const
{
	return m_callOperationActionActivation_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getCallOperationActionActivation_Attribute_callOperationAction() const
{
	return m_callOperationActionActivation_Attribute_callOperationAction;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getCallOperationActionActivation_Operation_getCallExecution() const
{
	return m_callOperationActionActivation_Operation_getCallExecution;
}

// End Class CallOperationActionActivation

// Begin Class ClauseActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getClauseActivation_Class() const
{
	return m_clauseActivation_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getClauseActivation_Attribute_clause() const
{
	return m_clauseActivation_Attribute_clause;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getClauseActivation_Attribute_conditionalNodeActivation() const
{
	return m_clauseActivation_Attribute_conditionalNodeActivation;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getClauseActivation_Operation_getDecision() const
{
	return m_clauseActivation_Operation_getDecision;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getClauseActivation_Operation_getPredecessors() const
{
	return m_clauseActivation_Operation_getPredecessors;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getClauseActivation_Operation_getSuccessors() const
{
	return m_clauseActivation_Operation_getSuccessors;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getClauseActivation_Operation_isReady() const
{
	return m_clauseActivation_Operation_isReady;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getClauseActivation_Operation_recieveControl() const
{
	return m_clauseActivation_Operation_recieveControl;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getClauseActivation_Operation_runTest() const
{
	return m_clauseActivation_Operation_runTest;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getClauseActivation_Operation_selectBody() const
{
	return m_clauseActivation_Operation_selectBody;
}

// End Class ClauseActivation

// Begin Class ClearAssociationActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getClearAssociationActionActivation_Class() const
{
	return m_clearAssociationActionActivation_Class;
}




// End Class ClearAssociationActionActivation

// Begin Class ClearStructuralFeatureActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getClearStructuralFeatureActionActivation_Class() const
{
	return m_clearStructuralFeatureActionActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getClearStructuralFeatureActionActivation_Operation_doAction() const
{
	return m_clearStructuralFeatureActionActivation_Operation_doAction;
}

// End Class ClearStructuralFeatureActionActivation

// Begin Class ConditionalNodeActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getConditionalNodeActivation_Class() const
{
	return m_conditionalNodeActivation_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getConditionalNodeActivation_Attribute_clauseActivations() const
{
	return m_conditionalNodeActivation_Attribute_clauseActivations;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getConditionalNodeActivation_Attribute_selectedClauses() const
{
	return m_conditionalNodeActivation_Attribute_selectedClauses;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getConditionalNodeActivation_Operation_getClauseActivation_Clause() const
{
	return m_conditionalNodeActivation_Operation_getClauseActivation_Clause;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getConditionalNodeActivation_Operation_runTest_Clause() const
{
	return m_conditionalNodeActivation_Operation_runTest_Clause;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getConditionalNodeActivation_Operation_selectBody_Clause() const
{
	return m_conditionalNodeActivation_Operation_selectBody_Clause;
}

// End Class ConditionalNodeActivation

// Begin Class CreateLinkActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getCreateLinkActionActivation_Class() const
{
	return m_createLinkActionActivation_Class;
}




// End Class CreateLinkActionActivation

// Begin Class CreateObjectActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getCreateObjectActionActivation_Class() const
{
	return m_createObjectActionActivation_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getCreateObjectActionActivation_Attribute_createObjectAction() const
{
	return m_createObjectActionActivation_Attribute_createObjectAction;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getCreateObjectActionActivation_Operation_doAction() const
{
	return m_createObjectActionActivation_Operation_doAction;
}

// End Class CreateObjectActionActivation

// Begin Class DestroyLinkActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getDestroyLinkActionActivation_Class() const
{
	return m_destroyLinkActionActivation_Class;
}




// End Class DestroyLinkActionActivation

// Begin Class DestroyObjectActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getDestroyObjectActionActivation_Class() const
{
	return m_destroyObjectActionActivation_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getDestroyObjectActionActivation_Attribute_destroyObjectAction() const
{
	return m_destroyObjectActionActivation_Attribute_destroyObjectAction;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getDestroyObjectActionActivation_Operation_destroyObject_Value_EBoolean() const
{
	return m_destroyObjectActionActivation_Operation_destroyObject_Value_EBoolean;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getDestroyObjectActionActivation_Operation_doAction() const
{
	return m_destroyObjectActionActivation_Operation_doAction;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getDestroyObjectActionActivation_Operation_objectIsComposite_Reference_Link() const
{
	return m_destroyObjectActionActivation_Operation_objectIsComposite_Reference_Link;
}

// End Class DestroyObjectActionActivation

// Begin Class InputPinActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getInputPinActivation_Class() const
{
	return m_inputPinActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getInputPinActivation_Operation_isReady() const
{
	return m_inputPinActivation_Operation_isReady;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getInputPinActivation_Operation_receiveOffer() const
{
	return m_inputPinActivation_Operation_receiveOffer;
}

// End Class InputPinActivation

// Begin Class InvocationActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getInvocationActionActivation_Class() const
{
	return m_invocationActionActivation_Class;
}




// End Class InvocationActionActivation

// Begin Class LinkActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getLinkActionActivation_Class() const
{
	return m_linkActionActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getLinkActionActivation_Operation_endMatchesEndData_Link_LinkEndData() const
{
	return m_linkActionActivation_Operation_endMatchesEndData_Link_LinkEndData;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getLinkActionActivation_Operation_getAssociation() const
{
	return m_linkActionActivation_Operation_getAssociation;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getLinkActionActivation_Operation_linkMatchesEndData_Link_LinkEndData() const
{
	return m_linkActionActivation_Operation_linkMatchesEndData_Link_LinkEndData;
}

// End Class LinkActionActivation

// Begin Class LoopNodeActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getLoopNodeActivation_Class() const
{
	return m_loopNodeActivation_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getLoopNodeActivation_Attribute_bodyOutputLists() const
{
	return m_loopNodeActivation_Attribute_bodyOutputLists;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getLoopNodeActivation_Operation_makeLoopVariableList() const
{
	return m_loopNodeActivation_Operation_makeLoopVariableList;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getLoopNodeActivation_Operation_runBody() const
{
	return m_loopNodeActivation_Operation_runBody;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getLoopNodeActivation_Operation_runLoopVariables() const
{
	return m_loopNodeActivation_Operation_runLoopVariables;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getLoopNodeActivation_Operation_runTest() const
{
	return m_loopNodeActivation_Operation_runTest;
}

// End Class LoopNodeActivation

// Begin Class OutputPinActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getOutputPinActivation_Class() const
{
	return m_outputPinActivation_Class;
}




// End Class OutputPinActivation

// Begin Class PinActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getPinActivation_Class() const
{
	return m_pinActivation_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getPinActivation_Attribute_actionActivation() const
{
	return m_pinActivation_Attribute_actionActivation;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getPinActivation_Attribute_pin() const
{
	return m_pinActivation_Attribute_pin;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getPinActivation_Operation_fire_Token() const
{
	return m_pinActivation_Operation_fire_Token;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getPinActivation_Operation_takeOfferedTokens() const
{
	return m_pinActivation_Operation_takeOfferedTokens;
}

// End Class PinActivation

// Begin Class ReadExtentActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getReadExtentActionActivation_Class() const
{
	return m_readExtentActionActivation_Class;
}




// End Class ReadExtentActionActivation

// Begin Class ReadIsClassifiedObjectActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getReadIsClassifiedObjectActionActivation_Class() const
{
	return m_readIsClassifiedObjectActionActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getReadIsClassifiedObjectActionActivation_Operation_checkAllParents_Classifier_Classifier() const
{
	return m_readIsClassifiedObjectActionActivation_Operation_checkAllParents_Classifier_Classifier;
}

// End Class ReadIsClassifiedObjectActionActivation

// Begin Class ReadLinkActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getReadLinkActionActivation_Class() const
{
	return m_readLinkActionActivation_Class;
}




// End Class ReadLinkActionActivation

// Begin Class ReadSelfActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getReadSelfActionActivation_Class() const
{
	return m_readSelfActionActivation_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getReadSelfActionActivation_Attribute_readSelfAction() const
{
	return m_readSelfActionActivation_Attribute_readSelfAction;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getReadSelfActionActivation_Operation_doAction() const
{
	return m_readSelfActionActivation_Operation_doAction;
}

// End Class ReadSelfActionActivation

// Begin Class ReadStructuralFeatureActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getReadStructuralFeatureActionActivation_Class() const
{
	return m_readStructuralFeatureActionActivation_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getReadStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction() const
{
	return m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getReadStructuralFeatureActionActivation_Operation_doAction() const
{
	return m_readStructuralFeatureActionActivation_Operation_doAction;
}

// End Class ReadStructuralFeatureActionActivation

// Begin Class ReclassifyObjectActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getReclassifyObjectActionActivation_Class() const
{
	return m_reclassifyObjectActionActivation_Class;
}




// End Class ReclassifyObjectActionActivation

// Begin Class ReduceActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getReduceActionActivation_Class() const
{
	return m_reduceActionActivation_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getReduceActionActivation_Attribute_currentExecution() const
{
	return m_reduceActionActivation_Attribute_currentExecution;
}


// End Class ReduceActionActivation

// Begin Class RemoveStructuralFeatureValueActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getRemoveStructuralFeatureValueActivation_Class() const
{
	return m_removeStructuralFeatureValueActivation_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getRemoveStructuralFeatureValueActivation_Attribute_removeStructuralFeatureValueAction() const
{
	return m_removeStructuralFeatureValueActivation_Attribute_removeStructuralFeatureValueAction;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getRemoveStructuralFeatureValueActivation_Operation_doAction() const
{
	return m_removeStructuralFeatureValueActivation_Operation_doAction;
}

// End Class RemoveStructuralFeatureValueActivation

// Begin Class ReplyActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getReplyActionActivation_Class() const
{
	return m_replyActionActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getReplyActionActivation_Operation_doAction() const
{
	return m_replyActionActivation_Operation_doAction;
}

// End Class ReplyActionActivation

// Begin Class ReturnInformation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getReturnInformation_Class() const
{
	return m_returnInformation_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getReturnInformation_Attribute_callEventOccurrence() const
{
	return m_returnInformation_Attribute_callEventOccurrence;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getReturnInformation_Operation__copy() const
{
	return m_returnInformation_Operation__copy;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getReturnInformation_Operation_equals_Value() const
{
	return m_returnInformation_Operation_equals_Value;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getReturnInformation_Operation_getOperation() const
{
	return m_returnInformation_Operation_getOperation;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getReturnInformation_Operation_getTypes() const
{
	return m_returnInformation_Operation_getTypes;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getReturnInformation_Operation_new_() const
{
	return m_returnInformation_Operation_new_;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getReturnInformation_Operation_reply_ParameterValue() const
{
	return m_returnInformation_Operation_reply_ParameterValue;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getReturnInformation_Operation_specify() const
{
	return m_returnInformation_Operation_specify;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getReturnInformation_Operation_toString() const
{
	return m_returnInformation_Operation_toString;
}

// End Class ReturnInformation

// Begin Class SendSignalActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getSendSignalActionActivation_Class() const
{
	return m_sendSignalActionActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getSendSignalActionActivation_Operation_doAction() const
{
	return m_sendSignalActionActivation_Operation_doAction;
}

// End Class SendSignalActionActivation

// Begin Class StartClassifierBehaviorActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getStartClassifierBehaviorActionActivation_Class() const
{
	return m_startClassifierBehaviorActionActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStartClassifierBehaviorActionActivation_Operation_doAction() const
{
	return m_startClassifierBehaviorActionActivation_Operation_doAction;
}

// End Class StartClassifierBehaviorActionActivation

// Begin Class StartObjectBehaviorActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getStartObjectBehaviorActionActivation_Class() const
{
	return m_startObjectBehaviorActionActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStartObjectBehaviorActionActivation_Operation_doAction() const
{
	return m_startObjectBehaviorActionActivation_Operation_doAction;
}

// End Class StartObjectBehaviorActionActivation

// Begin Class StructuralFeatureActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuralFeatureActionActivation_Class() const
{
	return m_structuralFeatureActionActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuralFeatureActionActivation_Operation_getAssociation_StructuralFeature() const
{
	return m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuralFeatureActionActivation_Operation_getMatchingLinks_Association_Value() const
{
	return m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_Value;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_Value() const
{
	return m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_Value;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature() const
{
	return m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature;
}

// End Class StructuralFeatureActionActivation

// Begin Class StructuredActivityNodeActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Class() const
{
	return m_structuredActivityNodeActivation_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Attribute_activationGroup() const
{
	return m_structuredActivityNodeActivation_Attribute_activationGroup;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_completeAction() const
{
	return m_structuredActivityNodeActivation_Operation_completeAction;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_createEdgeInstances() const
{
	return m_structuredActivityNodeActivation_Operation_createEdgeInstances;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_createNodeActivations() const
{
	return m_structuredActivityNodeActivation_Operation_createNodeActivations;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_doAction() const
{
	return m_structuredActivityNodeActivation_Operation_doAction;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_doStructuredActivity() const
{
	return m_structuredActivityNodeActivation_Operation_doStructuredActivity;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode() const
{
	return m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_getPinValues_OutputPin() const
{
	return m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance() const
{
	return m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_isSuspended() const
{
	return m_structuredActivityNodeActivation_Operation_isSuspended;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode() const
{
	return m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_putPinValues_OutputPin_Value() const
{
	return m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_Value;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_resume() const
{
	return m_structuredActivityNodeActivation_Operation_resume;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_terminate() const
{
	return m_structuredActivityNodeActivation_Operation_terminate;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getStructuredActivityNodeActivation_Operation_terminateAll() const
{
	return m_structuredActivityNodeActivation_Operation_terminateAll;
}

// End Class StructuredActivityNodeActivation

// Begin Class TestIdentityActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getTestIdentityActionActivation_Class() const
{
	return m_testIdentityActionActivation_Class;
}




// End Class TestIdentityActionActivation

// Begin Class ValueSpecificationActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getValueSpecificationActionActivation_Class() const
{
	return m_valueSpecificationActionActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getValueSpecificationActionActivation_Operation_doAction() const
{
	return m_valueSpecificationActionActivation_Operation_doAction;
}

// End Class ValueSpecificationActionActivation

// Begin Class Values
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getValues_Class() const
{
	return m_values_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Actions::ActionsPackageImpl::getValues_Attribute_values() const
{
	return m_values_Attribute_values;
}


// End Class Values

// Begin Class WriteLinkActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getWriteLinkActionActivation_Class() const
{
	return m_writeLinkActionActivation_Class;
}




// End Class WriteLinkActionActivation

// Begin Class WriteStructuralFeatureActionActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Actions::ActionsPackageImpl::getWriteStructuralFeatureActionActivation_Class() const
{
	return m_writeStructuralFeatureActionActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Actions::ActionsPackageImpl::getWriteStructuralFeatureActionActivation_Operation_position_Value_EInt() const
{
	return m_writeStructuralFeatureActionActivation_Operation_position_Value_EInt;
}

// End Class WriteStructuralFeatureActionActivation

