#include "fUML/impl/FUMLPackageImpl.hpp"

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
#include "fUML/FUMLFactory.hpp"

//depending model packages
#include "ecore/EcorePackage.hpp"
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
    return metaModelPackage;
}

void FUMLPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
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

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActionActivation_EReference_inputPinActivation() const
{
	return m_actionActivation_EReference_inputPinActivation;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActionActivation_EReference_outputPinActivation() const
{
	return m_actionActivation_EReference_outputPinActivation;
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

// Begin Class EventOccurrence
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getEventOccurrence_EClass() const
{
	return m_eventOccurrence_EClass;
}




// End Class EventOccurrence

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



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReadSelfActionActivation_EOperation_doAction() const
{
	return m_readSelfActionActivation_EOperation_doAction;
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

