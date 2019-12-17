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
#include "ecore/EPackage.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

//metamodel factory
#include "fUML/FUMLFactory.hpp"

//depending model packages
#include "ecore/EcorePackage.hpp"
#include "types/TypesPackage.hpp"
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

// Begin Class AcceptCallActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getAcceptCallActionActivation_Class() const
{
	return m_acceptCallActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getAcceptCallActionActivation_Operation_accept_EventOccurrence() const
{
	return m_acceptCallActionActivation_Operation_accept_EventOccurrence;
}

// End Class AcceptCallActionActivation

// Begin Class AcceptCallActionActivations
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getAcceptCallActionActivations_Class() const
{
	return m_acceptCallActionActivations_Class;
}




// End Class AcceptCallActionActivations

// Begin Class AcceptEventActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getAcceptEventActionActivation_Class() const
{
	return m_acceptEventActionActivation_Class;
}

std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getAcceptEventActionActivation_Attribute_waiting() const
{
	return m_acceptEventActionActivation_Attribute_waiting;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getAcceptEventActionActivation_Attribute_eventAccepter() const
{
	return m_acceptEventActionActivation_Attribute_eventAccepter;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getAcceptEventActionActivation_Operation_accept_EventOccurrence() const
{
	return m_acceptEventActionActivation_Operation_accept_EventOccurrence;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getAcceptEventActionActivation_Operation_doAction() const
{
	return m_acceptEventActionActivation_Operation_doAction;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getAcceptEventActionActivation_Operation_fire_Token() const
{
	return m_acceptEventActionActivation_Operation_fire_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getAcceptEventActionActivation_Operation_initialize_ActivityNode_ActivityNodeActivationGroup() const
{
	return m_acceptEventActionActivation_Operation_initialize_ActivityNode_ActivityNodeActivationGroup;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getAcceptEventActionActivation_Operation_isReady() const
{
	return m_acceptEventActionActivation_Operation_isReady;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getAcceptEventActionActivation_Operation_match_EventOccurrence() const
{
	return m_acceptEventActionActivation_Operation_match_EventOccurrence;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getAcceptEventActionActivation_Operation_run() const
{
	return m_acceptEventActionActivation_Operation_run;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getAcceptEventActionActivation_Operation_terminate() const
{
	return m_acceptEventActionActivation_Operation_terminate;
}

// End Class AcceptEventActionActivation

// Begin Class AcceptEventActionEventAccepter
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getAcceptEventActionEventAccepter_Class() const
{
	return m_acceptEventActionEventAccepter_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getAcceptEventActionEventAccepter_Attribute_actionActivation() const
{
	return m_acceptEventActionEventAccepter_Attribute_actionActivation;
}


// End Class AcceptEventActionEventAccepter

// Begin Class ActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getActionActivation_Class() const
{
	return m_actionActivation_Class;
}

std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getActionActivation_Attribute_firing() const
{
	return m_actionActivation_Attribute_firing;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActionActivation_Attribute_inputPinActivation() const
{
	return m_actionActivation_Attribute_inputPinActivation;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActionActivation_Attribute_outputPinActivation() const
{
	return m_actionActivation_Attribute_outputPinActivation;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActionActivation_Attribute_pinActivation() const
{
	return m_actionActivation_Attribute_pinActivation;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance() const
{
	return m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_Operation_addPinActivation_PinActivation() const
{
	return m_actionActivation_Operation_addPinActivation_PinActivation;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_Operation_completeAction() const
{
	return m_actionActivation_Operation_completeAction;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_Operation_createNodeActivations() const
{
	return m_actionActivation_Operation_createNodeActivations;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_Operation_doAction() const
{
	return m_actionActivation_Operation_doAction;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_Operation_fire_Token() const
{
	return m_actionActivation_Operation_fire_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_Operation_getTokens_InputPin() const
{
	return m_actionActivation_Operation_getTokens_InputPin;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_Operation_isFirng() const
{
	return m_actionActivation_Operation_isFirng;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_Operation_isReady() const
{
	return m_actionActivation_Operation_isReady;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_Operation_isSourceFor_ActivityEdgeInstance() const
{
	return m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_Operation_makeBooleanValue_EBoolean() const
{
	return m_actionActivation_Operation_makeBooleanValue_EBoolean;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_Operation_putToken_OutputPin_Value() const
{
	return m_actionActivation_Operation_putToken_OutputPin_Value;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_Operation_putTokens_OutputPin_Value() const
{
	return m_actionActivation_Operation_putTokens_OutputPin_Value;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_Operation_retrievePinActivation_Pin() const
{
	return m_actionActivation_Operation_retrievePinActivation_Pin;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_Operation_run() const
{
	return m_actionActivation_Operation_run;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_Operation_sendOffers() const
{
	return m_actionActivation_Operation_sendOffers;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_Operation_takeOfferedTokens() const
{
	return m_actionActivation_Operation_takeOfferedTokens;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_Operation_takeTokens_InputPin() const
{
	return m_actionActivation_Operation_takeTokens_InputPin;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_Operation_terminate() const
{
	return m_actionActivation_Operation_terminate;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation_Operation_valueParticipatesInLink_Value_Link() const
{
	return m_actionActivation_Operation_valueParticipatesInLink_Value_Link;
}

// End Class ActionActivation

// Begin Class ActivityEdgeInstance
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getActivityEdgeInstance_Class() const
{
	return m_activityEdgeInstance_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityEdgeInstance_Attribute_edge() const
{
	return m_activityEdgeInstance_Attribute_edge;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityEdgeInstance_Attribute_group() const
{
	return m_activityEdgeInstance_Attribute_group;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityEdgeInstance_Attribute_offers() const
{
	return m_activityEdgeInstance_Attribute_offers;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityEdgeInstance_Attribute_source() const
{
	return m_activityEdgeInstance_Attribute_source;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityEdgeInstance_Attribute_target() const
{
	return m_activityEdgeInstance_Attribute_target;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityEdgeInstance_Operation_countOfferedValue() const
{
	return m_activityEdgeInstance_Operation_countOfferedValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityEdgeInstance_Operation_getOfferedTokens() const
{
	return m_activityEdgeInstance_Operation_getOfferedTokens;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityEdgeInstance_Operation_hasOffer() const
{
	return m_activityEdgeInstance_Operation_hasOffer;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityEdgeInstance_Operation_sendOffer_Token() const
{
	return m_activityEdgeInstance_Operation_sendOffer_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityEdgeInstance_Operation_takeOfferedTokens() const
{
	return m_activityEdgeInstance_Operation_takeOfferedTokens;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityEdgeInstance_Operation_takeOfferedTokens_EInt() const
{
	return m_activityEdgeInstance_Operation_takeOfferedTokens_EInt;
}

// End Class ActivityEdgeInstance

// Begin Class ActivityExecution
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getActivityExecution_Class() const
{
	return m_activityExecution_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityExecution_Attribute_activationGroup() const
{
	return m_activityExecution_Attribute_activationGroup;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityExecution_Operation_execute() const
{
	return m_activityExecution_Operation_execute;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityExecution_Operation_new_() const
{
	return m_activityExecution_Operation_new_;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityExecution_Operation_terminate() const
{
	return m_activityExecution_Operation_terminate;
}

// End Class ActivityExecution

// Begin Class ActivityFinalNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getActivityFinalNodeActivation_Class() const
{
	return m_activityFinalNodeActivation_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityFinalNodeActivation_Operation_fire_Token() const
{
	return m_activityFinalNodeActivation_Operation_fire_Token;
}

// End Class ActivityFinalNodeActivation

// Begin Class ActivityNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getActivityNodeActivation_Class() const
{
	return m_activityNodeActivation_Class;
}

std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getActivityNodeActivation_Attribute_running() const
{
	return m_activityNodeActivation_Attribute_running;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityNodeActivation_Attribute_group() const
{
	return m_activityNodeActivation_Attribute_group;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityNodeActivation_Attribute_heldTokens() const
{
	return m_activityNodeActivation_Attribute_heldTokens;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityNodeActivation_Attribute_incomingEdges() const
{
	return m_activityNodeActivation_Attribute_incomingEdges;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityNodeActivation_Attribute_node() const
{
	return m_activityNodeActivation_Attribute_node;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityNodeActivation_Attribute_outgoingEdges() const
{
	return m_activityNodeActivation_Attribute_outgoingEdges;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_Operation_addIncomingEdge_ActivityEdgeInstance() const
{
	return m_activityNodeActivation_Operation_addIncomingEdge_ActivityEdgeInstance;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_Operation_addOutgoingEdge_ActivityEdgeInstance() const
{
	return m_activityNodeActivation_Operation_addOutgoingEdge_ActivityEdgeInstance;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_Operation_addToken_Token() const
{
	return m_activityNodeActivation_Operation_addToken_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_Operation_addTokens_Token() const
{
	return m_activityNodeActivation_Operation_addTokens_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_Operation_clearTokens() const
{
	return m_activityNodeActivation_Operation_clearTokens;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_Operation_createEdgeInstances() const
{
	return m_activityNodeActivation_Operation_createEdgeInstances;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_Operation_createNodeActivations() const
{
	return m_activityNodeActivation_Operation_createNodeActivations;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_Operation_fire_Token() const
{
	return m_activityNodeActivation_Operation_fire_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_Operation_getActivityExecution() const
{
	return m_activityNodeActivation_Operation_getActivityExecution;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_Operation_getExecutionContext() const
{
	return m_activityNodeActivation_Operation_getExecutionContext;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_Operation_getExecutionLocus() const
{
	return m_activityNodeActivation_Operation_getExecutionLocus;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_Operation_getNodeActivation_ActivityNode() const
{
	return m_activityNodeActivation_Operation_getNodeActivation_ActivityNode;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_Operation_getRunning() const
{
	return m_activityNodeActivation_Operation_getRunning;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_Operation_getTokens() const
{
	return m_activityNodeActivation_Operation_getTokens;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_Operation_isReady() const
{
	return m_activityNodeActivation_Operation_isReady;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance() const
{
	return m_activityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_Operation_recieveOffer() const
{
	return m_activityNodeActivation_Operation_recieveOffer;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_Operation_removeToken_Token() const
{
	return m_activityNodeActivation_Operation_removeToken_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_Operation_resume() const
{
	return m_activityNodeActivation_Operation_resume;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_Operation_run() const
{
	return m_activityNodeActivation_Operation_run;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_Operation_sendOffers_Token() const
{
	return m_activityNodeActivation_Operation_sendOffers_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_Operation_suspend() const
{
	return m_activityNodeActivation_Operation_suspend;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_Operation_takeOfferedTokens() const
{
	return m_activityNodeActivation_Operation_takeOfferedTokens;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_Operation_takeTokens() const
{
	return m_activityNodeActivation_Operation_takeTokens;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation_Operation_terminate() const
{
	return m_activityNodeActivation_Operation_terminate;
}

// End Class ActivityNodeActivation

// Begin Class ActivityNodeActivationGroup
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getActivityNodeActivationGroup_Class() const
{
	return m_activityNodeActivationGroup_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityNodeActivationGroup_Attribute_activityExecution() const
{
	return m_activityNodeActivationGroup_Attribute_activityExecution;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityNodeActivationGroup_Attribute_containingNodeActivation() const
{
	return m_activityNodeActivationGroup_Attribute_containingNodeActivation;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityNodeActivationGroup_Attribute_edgeInstances() const
{
	return m_activityNodeActivationGroup_Attribute_edgeInstances;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityNodeActivationGroup_Attribute_nodeActivations() const
{
	return m_activityNodeActivationGroup_Attribute_nodeActivations;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityNodeActivationGroup_Attribute_suspendedActivations() const
{
	return m_activityNodeActivationGroup_Attribute_suspendedActivations;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup_Operation_activate_ActivityNode_ActivityEdge() const
{
	return m_activityNodeActivationGroup_Operation_activate_ActivityNode_ActivityEdge;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup_Operation_addEdgeInstance_ActivityEdgeInstance() const
{
	return m_activityNodeActivationGroup_Operation_addEdgeInstance_ActivityEdgeInstance;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup_Operation_addNodeActivation_ActivityNodeActivation() const
{
	return m_activityNodeActivationGroup_Operation_addNodeActivation_ActivityNodeActivation;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup_Operation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation() const
{
	return m_activityNodeActivationGroup_Operation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup_Operation_createEdgeInstance_ActivityEdge() const
{
	return m_activityNodeActivationGroup_Operation_createEdgeInstance_ActivityEdge;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup_Operation_createNodeActivation_ActivityNode() const
{
	return m_activityNodeActivationGroup_Operation_createNodeActivation_ActivityNode;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup_Operation_createNodeActivations_ActivityNode() const
{
	return m_activityNodeActivationGroup_Operation_createNodeActivations_ActivityNode;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup_Operation_getNodeActivation_ActivityNode() const
{
	return m_activityNodeActivationGroup_Operation_getNodeActivation_ActivityNode;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup_Operation_getOutputParameterNodeActivations() const
{
	return m_activityNodeActivationGroup_Operation_getOutputParameterNodeActivations;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup_Operation_hasSourceFor_ActivityEdgeInstance() const
{
	return m_activityNodeActivationGroup_Operation_hasSourceFor_ActivityEdgeInstance;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup_Operation_isSuspended() const
{
	return m_activityNodeActivationGroup_Operation_isSuspended;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup_Operation_resume_ActivityNodeActivation() const
{
	return m_activityNodeActivationGroup_Operation_resume_ActivityNodeActivation;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup_Operation_retrieveActivityExecution() const
{
	return m_activityNodeActivationGroup_Operation_retrieveActivityExecution;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup_Operation_run_ActivityNodeActivation() const
{
	return m_activityNodeActivationGroup_Operation_run_ActivityNodeActivation;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup_Operation_runNodes_ActivityNode() const
{
	return m_activityNodeActivationGroup_Operation_runNodes_ActivityNode;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup_Operation_suspend_ActivityNodeActivation() const
{
	return m_activityNodeActivationGroup_Operation_suspend_ActivityNodeActivation;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup_Operation_terminateAll() const
{
	return m_activityNodeActivationGroup_Operation_terminateAll;
}

// End Class ActivityNodeActivationGroup

// Begin Class ActivityParameterNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getActivityParameterNodeActivation_Class() const
{
	return m_activityParameterNodeActivation_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityParameterNodeActivation_Operation_clearTokens() const
{
	return m_activityParameterNodeActivation_Operation_clearTokens;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityParameterNodeActivation_Operation_fire_Token() const
{
	return m_activityParameterNodeActivation_Operation_fire_Token;
}

// End Class ActivityParameterNodeActivation

// Begin Class AddStructuralFeatureValueActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getAddStructuralFeatureValueActionActivation_Class() const
{
	return m_addStructuralFeatureValueActionActivation_Class;
}




// End Class AddStructuralFeatureValueActionActivation

// Begin Class BooleanValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getBooleanValue_Class() const
{
	return m_booleanValue_Class;
}

std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getBooleanValue_Attribute_value() const
{
	return m_booleanValue_Attribute_value;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getBooleanValue_Operation_equals_Value() const
{
	return m_booleanValue_Operation_equals_Value;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getBooleanValue_Operation_specify() const
{
	return m_booleanValue_Operation_specify;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getBooleanValue_Operation_toString() const
{
	return m_booleanValue_Operation_toString;
}

// End Class BooleanValue

// Begin Class CallActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getCallActionActivation_Class() const
{
	return m_callActionActivation_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getCallActionActivation_Attribute_callExecutions() const
{
	return m_callActionActivation_Attribute_callExecutions;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallActionActivation_Operation_doAction() const
{
	return m_callActionActivation_Operation_doAction;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallActionActivation_Operation_getCallExecution() const
{
	return m_callActionActivation_Operation_getCallExecution;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallActionActivation_Operation_removeCallExecution_Execution() const
{
	return m_callActionActivation_Operation_removeCallExecution_Execution;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallActionActivation_Operation_terminate() const
{
	return m_callActionActivation_Operation_terminate;
}

// End Class CallActionActivation

// Begin Class CallBehaviorActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getCallBehaviorActionActivation_Class() const
{
	return m_callBehaviorActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallBehaviorActionActivation_Operation_getCallExecution() const
{
	return m_callBehaviorActionActivation_Operation_getCallExecution;
}

// End Class CallBehaviorActionActivation

// Begin Class CallEventBehavior
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getCallEventBehavior_Class() const
{
	return m_callEventBehavior_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getCallEventBehavior_Attribute_operation() const
{
	return m_callEventBehavior_Attribute_operation;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallEventBehavior_Operation_assignOperation_Operation() const
{
	return m_callEventBehavior_Operation_assignOperation_Operation;
}

// End Class CallEventBehavior

// Begin Class CallEventExecution
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getCallEventExecution_Class() const
{
	return m_callEventExecution_Class;
}

std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getCallEventExecution_Attribute_callerSuspended() const
{
	return m_callEventExecution_Attribute_callerSuspended;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallEventExecution_Operation_copy() const
{
	return m_callEventExecution_Operation_copy;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallEventExecution_Operation_createEventOccurrence() const
{
	return m_callEventExecution_Operation_createEventOccurrence;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallEventExecution_Operation_execute() const
{
	return m_callEventExecution_Operation_execute;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallEventExecution_Operation_getInputParameterValues() const
{
	return m_callEventExecution_Operation_getInputParameterValues;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallEventExecution_Operation_getOperation() const
{
	return m_callEventExecution_Operation_getOperation;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallEventExecution_Operation_isCallerSuspended() const
{
	return m_callEventExecution_Operation_isCallerSuspended;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallEventExecution_Operation_makeCall() const
{
	return m_callEventExecution_Operation_makeCall;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallEventExecution_Operation_new_() const
{
	return m_callEventExecution_Operation_new_;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallEventExecution_Operation_releaseCaller() const
{
	return m_callEventExecution_Operation_releaseCaller;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallEventExecution_Operation_setOutputParameterValues_ParameterValue() const
{
	return m_callEventExecution_Operation_setOutputParameterValues_ParameterValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallEventExecution_Operation_suspendCaller() const
{
	return m_callEventExecution_Operation_suspendCaller;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallEventExecution_Operation_wait_() const
{
	return m_callEventExecution_Operation_wait_;
}

// End Class CallEventExecution

// Begin Class CallEventOccurrence
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getCallEventOccurrence_Class() const
{
	return m_callEventOccurrence_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getCallEventOccurrence_Attribute_execution() const
{
	return m_callEventOccurrence_Attribute_execution;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallEventOccurrence_Operation_getOperation() const
{
	return m_callEventOccurrence_Operation_getOperation;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallEventOccurrence_Operation_getParameterValues() const
{
	return m_callEventOccurrence_Operation_getParameterValues;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallEventOccurrence_Operation_match_Trigger() const
{
	return m_callEventOccurrence_Operation_match_Trigger;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallEventOccurrence_Operation_releaseCaller() const
{
	return m_callEventOccurrence_Operation_releaseCaller;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallEventOccurrence_Operation_setOutputParameterValues_ParameterValue() const
{
	return m_callEventOccurrence_Operation_setOutputParameterValues_ParameterValue;
}

// End Class CallEventOccurrence

// Begin Class CallOperationActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getCallOperationActionActivation_Class() const
{
	return m_callOperationActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallOperationActionActivation_Operation_getCallExecution() const
{
	return m_callOperationActionActivation_Operation_getCallExecution;
}

// End Class CallOperationActionActivation

// Begin Class CentralBufferNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getCentralBufferNodeActivation_Class() const
{
	return m_centralBufferNodeActivation_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCentralBufferNodeActivation_Operation_fire_Token() const
{
	return m_centralBufferNodeActivation_Operation_fire_Token;
}

// End Class CentralBufferNodeActivation

// Begin Class ChoiceStrategy
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getChoiceStrategy_Class() const
{
	return m_choiceStrategy_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getChoiceStrategy_Operation_choose_EInt() const
{
	return m_choiceStrategy_Operation_choose_EInt;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getChoiceStrategy_Operation_getName() const
{
	return m_choiceStrategy_Operation_getName;
}

// End Class ChoiceStrategy

// Begin Class ClassifierBehaviorExecution
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getClassifierBehaviorExecution_Class() const
{
	return m_classifierBehaviorExecution_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getClassifierBehaviorExecution_Attribute_classifier() const
{
	return m_classifierBehaviorExecution_Attribute_classifier;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getClassifierBehaviorExecution_Attribute_execution() const
{
	return m_classifierBehaviorExecution_Attribute_execution;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getClassifierBehaviorExecution_Attribute_objectActivation() const
{
	return m_classifierBehaviorExecution_Attribute_objectActivation;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getClassifierBehaviorExecution_Operation__startObjectBehavior() const
{
	return m_classifierBehaviorExecution_Operation__startObjectBehavior;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getClassifierBehaviorExecution_Operation_execute_Class_ParameterValue() const
{
	return m_classifierBehaviorExecution_Operation_execute_Class_ParameterValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getClassifierBehaviorExecution_Operation_terminate() const
{
	return m_classifierBehaviorExecution_Operation_terminate;
}

// End Class ClassifierBehaviorExecution

// Begin Class ClassifierBehaviorExecutionActivity
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getClassifierBehaviorExecutionActivity_Class() const
{
	return m_classifierBehaviorExecutionActivity_Class;
}




// End Class ClassifierBehaviorExecutionActivity

// Begin Class ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1_Class() const
{
	return m_classifierBehaviorExecutionActivity_OwnedBehaviorActivity1_Class;
}




// End Class ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1

// Begin Class ClassifierBehaviorInvocationEventAccepter
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getClassifierBehaviorInvocationEventAccepter_Class() const
{
	return m_classifierBehaviorInvocationEventAccepter_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getClassifierBehaviorInvocationEventAccepter_Attribute_classifier() const
{
	return m_classifierBehaviorInvocationEventAccepter_Attribute_classifier;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getClassifierBehaviorInvocationEventAccepter_Attribute_execution() const
{
	return m_classifierBehaviorInvocationEventAccepter_Attribute_execution;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getClassifierBehaviorInvocationEventAccepter_Attribute_objectActivation() const
{
	return m_classifierBehaviorInvocationEventAccepter_Attribute_objectActivation;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getClassifierBehaviorInvocationEventAccepter_Operation_accept_EventOccurrence() const
{
	return m_classifierBehaviorInvocationEventAccepter_Operation_accept_EventOccurrence;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getClassifierBehaviorInvocationEventAccepter_Operation_invokeBehavior_Class_ParameterValue() const
{
	return m_classifierBehaviorInvocationEventAccepter_Operation_invokeBehavior_Class_ParameterValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getClassifierBehaviorInvocationEventAccepter_Operation_match_EventOccurrence() const
{
	return m_classifierBehaviorInvocationEventAccepter_Operation_match_EventOccurrence;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getClassifierBehaviorInvocationEventAccepter_Operation_terminate() const
{
	return m_classifierBehaviorInvocationEventAccepter_Operation_terminate;
}

// End Class ClassifierBehaviorInvocationEventAccepter

// Begin Class ClauseActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getClauseActivation_Class() const
{
	return m_clauseActivation_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getClauseActivation_Attribute_clause() const
{
	return m_clauseActivation_Attribute_clause;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getClauseActivation_Attribute_conditionalNodeActivation() const
{
	return m_clauseActivation_Attribute_conditionalNodeActivation;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getClauseActivation_Operation_getDecision() const
{
	return m_clauseActivation_Operation_getDecision;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getClauseActivation_Operation_getPredecessors() const
{
	return m_clauseActivation_Operation_getPredecessors;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getClauseActivation_Operation_getSuccessors() const
{
	return m_clauseActivation_Operation_getSuccessors;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getClauseActivation_Operation_isReady() const
{
	return m_clauseActivation_Operation_isReady;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getClauseActivation_Operation_recieveControl() const
{
	return m_clauseActivation_Operation_recieveControl;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getClauseActivation_Operation_runTest() const
{
	return m_clauseActivation_Operation_runTest;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getClauseActivation_Operation_selectBody() const
{
	return m_clauseActivation_Operation_selectBody;
}

// End Class ClauseActivation

// Begin Class ClearAssociationActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getClearAssociationActionActivation_Class() const
{
	return m_clearAssociationActionActivation_Class;
}




// End Class ClearAssociationActionActivation

// Begin Class ClearStructuralFeatureActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getClearStructuralFeatureActionActivation_Class() const
{
	return m_clearStructuralFeatureActionActivation_Class;
}




// End Class ClearStructuralFeatureActionActivation

// Begin Class CompoundValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getCompoundValue_Class() const
{
	return m_compoundValue_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getCompoundValue_Attribute_featureValues() const
{
	return m_compoundValue_Attribute_featureValues;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCompoundValue_Operation_assignFeatureValue_StructuralFeature_EInt() const
{
	return m_compoundValue_Operation_assignFeatureValue_StructuralFeature_EInt;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCompoundValue_Operation_equals_Value() const
{
	return m_compoundValue_Operation_equals_Value;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCompoundValue_Operation_removeFeatureValues_Classifier() const
{
	return m_compoundValue_Operation_removeFeatureValues_Classifier;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCompoundValue_Operation_retrieveFeatureValue_StructuralFeature() const
{
	return m_compoundValue_Operation_retrieveFeatureValue_StructuralFeature;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCompoundValue_Operation_retrieveFeatureValues() const
{
	return m_compoundValue_Operation_retrieveFeatureValues;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCompoundValue_Operation_toString() const
{
	return m_compoundValue_Operation_toString;
}

// End Class CompoundValue

// Begin Class ConditionalNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getConditionalNodeActivation_Class() const
{
	return m_conditionalNodeActivation_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getConditionalNodeActivation_Attribute_clauseActivations() const
{
	return m_conditionalNodeActivation_Attribute_clauseActivations;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getConditionalNodeActivation_Attribute_selectedClauses() const
{
	return m_conditionalNodeActivation_Attribute_selectedClauses;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getConditionalNodeActivation_Operation_getClauseActivation_Clause() const
{
	return m_conditionalNodeActivation_Operation_getClauseActivation_Clause;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getConditionalNodeActivation_Operation_runTest_Clause() const
{
	return m_conditionalNodeActivation_Operation_runTest_Clause;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getConditionalNodeActivation_Operation_selectBody_Clause() const
{
	return m_conditionalNodeActivation_Operation_selectBody_Clause;
}

// End Class ConditionalNodeActivation

// Begin Class ControlNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getControlNodeActivation_Class() const
{
	return m_controlNodeActivation_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getControlNodeActivation_Operation_fire_Token() const
{
	return m_controlNodeActivation_Operation_fire_Token;
}

// End Class ControlNodeActivation

// Begin Class ControlToken
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getControlToken_Class() const
{
	return m_controlToken_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getControlToken_Operation_equals_Token() const
{
	return m_controlToken_Operation_equals_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getControlToken_Operation_getValue() const
{
	return m_controlToken_Operation_getValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getControlToken_Operation_isControl() const
{
	return m_controlToken_Operation_isControl;
}

// End Class ControlToken

// Begin Class CreateLinkActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getCreateLinkActionActivation_Class() const
{
	return m_createLinkActionActivation_Class;
}




// End Class CreateLinkActionActivation

// Begin Class CreateObjectActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getCreateObjectActionActivation_Class() const
{
	return m_createObjectActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCreateObjectActionActivation_Operation_doAction() const
{
	return m_createObjectActionActivation_Operation_doAction;
}

// End Class CreateObjectActionActivation

// Begin Class DataStoreNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getDataStoreNodeActivation_Class() const
{
	return m_dataStoreNodeActivation_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDataStoreNodeActivation_Operation_addToken_Token() const
{
	return m_dataStoreNodeActivation_Operation_addToken_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDataStoreNodeActivation_Operation_removeToken_Token() const
{
	return m_dataStoreNodeActivation_Operation_removeToken_Token;
}

// End Class DataStoreNodeActivation

// Begin Class DataValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getDataValue_Class() const
{
	return m_dataValue_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getDataValue_Attribute_type() const
{
	return m_dataValue_Attribute_type;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDataValue_Operation_getTypes() const
{
	return m_dataValue_Operation_getTypes;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDataValue_Operation_new_() const
{
	return m_dataValue_Operation_new_;
}

// End Class DataValue

// Begin Class DecisionNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getDecisionNodeActivation_Class() const
{
	return m_decisionNodeActivation_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getDecisionNodeActivation_Attribute_decisionInputExecution() const
{
	return m_decisionNodeActivation_Attribute_decisionInputExecution;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDecisionNodeActivation_Operation_executeDecisionInputBehavior_Value_Value() const
{
	return m_decisionNodeActivation_Operation_executeDecisionInputBehavior_Value_Value;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDecisionNodeActivation_Operation_fire_Token() const
{
	return m_decisionNodeActivation_Operation_fire_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDecisionNodeActivation_Operation_getDecisionInputFlowInstance() const
{
	return m_decisionNodeActivation_Operation_getDecisionInputFlowInstance;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDecisionNodeActivation_Operation_getDecisionInputFlowValue() const
{
	return m_decisionNodeActivation_Operation_getDecisionInputFlowValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDecisionNodeActivation_Operation_getDecisionValues_Token() const
{
	return m_decisionNodeActivation_Operation_getDecisionValues_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDecisionNodeActivation_Operation_hasObjectFlowInput() const
{
	return m_decisionNodeActivation_Operation_hasObjectFlowInput;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDecisionNodeActivation_Operation_isReady() const
{
	return m_decisionNodeActivation_Operation_isReady;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDecisionNodeActivation_Operation_removeJoinedControlTokens_Token() const
{
	return m_decisionNodeActivation_Operation_removeJoinedControlTokens_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDecisionNodeActivation_Operation_takeOfferedTokens() const
{
	return m_decisionNodeActivation_Operation_takeOfferedTokens;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDecisionNodeActivation_Operation_terminate() const
{
	return m_decisionNodeActivation_Operation_terminate;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDecisionNodeActivation_Operation_test_ValueSpecification_Value() const
{
	return m_decisionNodeActivation_Operation_test_ValueSpecification_Value;
}

// End Class DecisionNodeActivation

// Begin Class DestroyLinkActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getDestroyLinkActionActivation_Class() const
{
	return m_destroyLinkActionActivation_Class;
}




// End Class DestroyLinkActionActivation

// Begin Class DestroyObjectActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getDestroyObjectActionActivation_Class() const
{
	return m_destroyObjectActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDestroyObjectActionActivation_Operation_destroyObject_Value_EBoolean() const
{
	return m_destroyObjectActionActivation_Operation_destroyObject_Value_EBoolean;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDestroyObjectActionActivation_Operation_doAction() const
{
	return m_destroyObjectActionActivation_Operation_doAction;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDestroyObjectActionActivation_Operation_objectIsComposite_Reference_Link() const
{
	return m_destroyObjectActionActivation_Operation_objectIsComposite_Reference_Link;
}

// End Class DestroyObjectActionActivation

// Begin Class DispatchStrategy
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getDispatchStrategy_Class() const
{
	return m_dispatchStrategy_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDispatchStrategy_Operation_dispatch_Object_Operation() const
{
	return m_dispatchStrategy_Operation_dispatch_Object_Operation;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDispatchStrategy_Operation_getName() const
{
	return m_dispatchStrategy_Operation_getName;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDispatchStrategy_Operation_retrieveMethod_Object_Operation() const
{
	return m_dispatchStrategy_Operation_retrieveMethod_Object_Operation;
}

// End Class DispatchStrategy

// Begin Class EnumerationValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getEnumerationValue_Class() const
{
	return m_enumerationValue_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getEnumerationValue_Attribute_literal() const
{
	return m_enumerationValue_Attribute_literal;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getEnumerationValue_Attribute_type() const
{
	return m_enumerationValue_Attribute_type;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getEnumerationValue_Operation_equals_Value() const
{
	return m_enumerationValue_Operation_equals_Value;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getEnumerationValue_Operation_getTypes() const
{
	return m_enumerationValue_Operation_getTypes;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getEnumerationValue_Operation_new_() const
{
	return m_enumerationValue_Operation_new_;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getEnumerationValue_Operation_specify() const
{
	return m_enumerationValue_Operation_specify;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getEnumerationValue_Operation_toString() const
{
	return m_enumerationValue_Operation_toString;
}

// End Class EnumerationValue

// Begin Class Evaluation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getEvaluation_Class() const
{
	return m_evaluation_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getEvaluation_Attribute_locus() const
{
	return m_evaluation_Attribute_locus;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getEvaluation_Attribute_specification() const
{
	return m_evaluation_Attribute_specification;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getEvaluation_Operation_evaluate() const
{
	return m_evaluation_Operation_evaluate;
}

// End Class Evaluation

// Begin Class EventAccepter
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getEventAccepter_Class() const
{
	return m_eventAccepter_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getEventAccepter_Operation_accept_SignalInstance() const
{
	return m_eventAccepter_Operation_accept_SignalInstance;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getEventAccepter_Operation_match_SignalInstance() const
{
	return m_eventAccepter_Operation_match_SignalInstance;
}

// End Class EventAccepter

// Begin Class EventDispatchLoop
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getEventDispatchLoop_Class() const
{
	return m_eventDispatchLoop_Class;
}




// End Class EventDispatchLoop

// Begin Class EventOccurrence
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getEventOccurrence_Class() const
{
	return m_eventOccurrence_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getEventOccurrence_Attribute_target() const
{
	return m_eventOccurrence_Attribute_target;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getEventOccurrence_Operation_doSend() const
{
	return m_eventOccurrence_Operation_doSend;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getEventOccurrence_Operation_getParameterValues() const
{
	return m_eventOccurrence_Operation_getParameterValues;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getEventOccurrence_Operation_match_Trigger() const
{
	return m_eventOccurrence_Operation_match_Trigger;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getEventOccurrence_Operation_matchAny_Trigger() const
{
	return m_eventOccurrence_Operation_matchAny_Trigger;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getEventOccurrence_Operation_sendTo_Reference() const
{
	return m_eventOccurrence_Operation_sendTo_Reference;
}

// End Class EventOccurrence

// Begin Class Execution
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getExecution_Class() const
{
	return m_execution_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExecution_Attribute_context() const
{
	return m_execution_Attribute_context;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExecution_Attribute_parameterValues() const
{
	return m_execution_Attribute_parameterValues;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecution_Operation_execute() const
{
	return m_execution_Operation_execute;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecution_Operation_getBehavior() const
{
	return m_execution_Operation_getBehavior;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecution_Operation_getOutputParameterValues() const
{
	return m_execution_Operation_getOutputParameterValues;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecution_Operation_getParameterValue_Parameter() const
{
	return m_execution_Operation_getParameterValue_Parameter;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecution_Operation_new_() const
{
	return m_execution_Operation_new_;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecution_Operation_setParameterValue_ParameterValue() const
{
	return m_execution_Operation_setParameterValue_ParameterValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecution_Operation_terminate() const
{
	return m_execution_Operation_terminate;
}

// End Class Execution

// Begin Class ExecutionFactory
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getExecutionFactory_Class() const
{
	return m_executionFactory_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExecutionFactory_Attribute_builtInTypes() const
{
	return m_executionFactory_Attribute_builtInTypes;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExecutionFactory_Attribute_locus() const
{
	return m_executionFactory_Attribute_locus;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExecutionFactory_Attribute_primitiveBehaviorPrototypes() const
{
	return m_executionFactory_Attribute_primitiveBehaviorPrototypes;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExecutionFactory_Attribute_strategies() const
{
	return m_executionFactory_Attribute_strategies;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactory_Operation_addBuiltInType_PrimitiveType() const
{
	return m_executionFactory_Operation_addBuiltInType_PrimitiveType;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactory_Operation_addPrimitiveBehaviorPrototype_OpaqueBehaviorExecution() const
{
	return m_executionFactory_Operation_addPrimitiveBehaviorPrototype_OpaqueBehaviorExecution;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactory_Operation_assignStrategy_SemanticStrategy() const
{
	return m_executionFactory_Operation_assignStrategy_SemanticStrategy;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactory_Operation_createEvaluation_ValueSpecification() const
{
	return m_executionFactory_Operation_createEvaluation_ValueSpecification;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactory_Operation_createExecution_Behavior_Object() const
{
	return m_executionFactory_Operation_createExecution_Behavior_Object;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactory_Operation_getBuiltInType_EString() const
{
	return m_executionFactory_Operation_getBuiltInType_EString;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactory_Operation_getStrategy_EString() const
{
	return m_executionFactory_Operation_getStrategy_EString;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactory_Operation_getStrategyIndex_EString() const
{
	return m_executionFactory_Operation_getStrategyIndex_EString;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactory_Operation_instantiateOpaqueBehaviorExecution_OpaqueBehavior() const
{
	return m_executionFactory_Operation_instantiateOpaqueBehaviorExecution_OpaqueBehavior;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactory_Operation_instantiateVisitor_Element() const
{
	return m_executionFactory_Operation_instantiateVisitor_Element;
}

// End Class ExecutionFactory

// Begin Class ExecutionFactoryL1
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getExecutionFactoryL1_Class() const
{
	return m_executionFactoryL1_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactoryL1_Operation_instantiateVisitor_Element() const
{
	return m_executionFactoryL1_Operation_instantiateVisitor_Element;
}

// End Class ExecutionFactoryL1

// Begin Class ExecutionFactoryL2
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getExecutionFactoryL2_Class() const
{
	return m_executionFactoryL2_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactoryL2_Operation_instantiateVisitor_Element() const
{
	return m_executionFactoryL2_Operation_instantiateVisitor_Element;
}

// End Class ExecutionFactoryL2

// Begin Class ExecutionFactoryL3
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getExecutionFactoryL3_Class() const
{
	return m_executionFactoryL3_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactoryL3_Operation_instantiateVisitor_Element() const
{
	return m_executionFactoryL3_Operation_instantiateVisitor_Element;
}

// End Class ExecutionFactoryL3

// Begin Class Executor
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getExecutor_Class() const
{
	return m_executor_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExecutor_Attribute_locus() const
{
	return m_executor_Attribute_locus;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutor_Operation_evaluate_ValueSpecification() const
{
	return m_executor_Operation_evaluate_ValueSpecification;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutor_Operation_execute_Behavior_ParameterValue() const
{
	return m_executor_Operation_execute_Behavior_ParameterValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutor_Operation_start_Class_ParameterValue() const
{
	return m_executor_Operation_start_Class_ParameterValue;
}

// End Class Executor

// Begin Class ExpansionActivationGroup
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getExpansionActivationGroup_Class() const
{
	return m_expansionActivationGroup_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExpansionActivationGroup_Attribute_regionActivation() const
{
	return m_expansionActivationGroup_Attribute_regionActivation;
}


// End Class ExpansionActivationGroup

// Begin Class ExpansionNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getExpansionNodeActivation_Class() const
{
	return m_expansionNodeActivation_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExpansionNodeActivation_Operation_getExpansionRegionActivation() const
{
	return m_expansionNodeActivation_Operation_getExpansionRegionActivation;
}

// End Class ExpansionNodeActivation

// Begin Class ExpansionRegionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getExpansionRegionActivation_Class() const
{
	return m_expansionRegionActivation_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExpansionRegionActivation_Attribute_activationGroups() const
{
	return m_expansionRegionActivation_Attribute_activationGroups;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExpansionRegionActivation_Attribute_inputExpansionTokens() const
{
	return m_expansionRegionActivation_Attribute_inputExpansionTokens;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExpansionRegionActivation_Attribute_inputTokens() const
{
	return m_expansionRegionActivation_Attribute_inputTokens;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExpansionRegionActivation_Operation_doStructuredActivity() const
{
	return m_expansionRegionActivation_Operation_doStructuredActivity;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExpansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode() const
{
	return m_expansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExpansionRegionActivation_Operation_numberOfValues() const
{
	return m_expansionRegionActivation_Operation_numberOfValues;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExpansionRegionActivation_Operation_runGroup_ExpansionActivationGroup() const
{
	return m_expansionRegionActivation_Operation_runGroup_ExpansionActivationGroup;
}

// End Class ExpansionRegionActivation

// Begin Class ExtensionalValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getExtensionalValue_Class() const
{
	return m_extensionalValue_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExtensionalValue_Attribute_locus() const
{
	return m_extensionalValue_Attribute_locus;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExtensionalValue_Operation_destroy() const
{
	return m_extensionalValue_Operation_destroy;
}

// End Class ExtensionalValue

// Begin Class ExtensionalValueList
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getExtensionalValueList_Class() const
{
	return m_extensionalValueList_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExtensionalValueList_Operation_addValue_ExtensionalValue() const
{
	return m_extensionalValueList_Operation_addValue_ExtensionalValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExtensionalValueList_Operation_addValue_ExtensionalValue_EInt() const
{
	return m_extensionalValueList_Operation_addValue_ExtensionalValue_EInt;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExtensionalValueList_Operation_getValue() const
{
	return m_extensionalValueList_Operation_getValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExtensionalValueList_Operation_removeValue_EInt() const
{
	return m_extensionalValueList_Operation_removeValue_EInt;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExtensionalValueList_Operation_setValue_ExtensionalValue_EInt() const
{
	return m_extensionalValueList_Operation_setValue_ExtensionalValue_EInt;
}

// End Class ExtensionalValueList

// Begin Class FIFOGetNextEventStrategy
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getFIFOGetNextEventStrategy_Class() const
{
	return m_fIFOGetNextEventStrategy_Class;
}




// End Class FIFOGetNextEventStrategy

// Begin Class FeatureValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getFeatureValue_Class() const
{
	return m_featureValue_Class;
}

std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getFeatureValue_Attribute_position() const
{
	return m_featureValue_Attribute_position;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getFeatureValue_Attribute_feature() const
{
	return m_featureValue_Attribute_feature;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getFeatureValue_Attribute_values() const
{
	return m_featureValue_Attribute_values;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getFeatureValue_Operation_hasEqualValues_FeatureValue() const
{
	return m_featureValue_Operation_hasEqualValues_FeatureValue;
}

// End Class FeatureValue

// Begin Class FirstChoiceStrategy
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getFirstChoiceStrategy_Class() const
{
	return m_firstChoiceStrategy_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getFirstChoiceStrategy_Operation_choose_EInt() const
{
	return m_firstChoiceStrategy_Operation_choose_EInt;
}

// End Class FirstChoiceStrategy

// Begin Class FlowFinalNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getFlowFinalNodeActivation_Class() const
{
	return m_flowFinalNodeActivation_Class;
}




// End Class FlowFinalNodeActivation

// Begin Class ForkNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getForkNodeActivation_Class() const
{
	return m_forkNodeActivation_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getForkNodeActivation_Operation_fire_Token() const
{
	return m_forkNodeActivation_Operation_fire_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getForkNodeActivation_Operation_terminate() const
{
	return m_forkNodeActivation_Operation_terminate;
}

// End Class ForkNodeActivation

// Begin Class ForkedToken
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getForkedToken_Class() const
{
	return m_forkedToken_Class;
}

std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getForkedToken_Attribute_baseTokenIsWithdrawn() const
{
	return m_forkedToken_Attribute_baseTokenIsWithdrawn;
}
std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getForkedToken_Attribute_remainingOffersCount() const
{
	return m_forkedToken_Attribute_remainingOffersCount;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getForkedToken_Attribute_baseToken() const
{
	return m_forkedToken_Attribute_baseToken;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getForkedToken_Operation_equals_Token() const
{
	return m_forkedToken_Operation_equals_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getForkedToken_Operation_getValue() const
{
	return m_forkedToken_Operation_getValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getForkedToken_Operation_isControl() const
{
	return m_forkedToken_Operation_isControl;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getForkedToken_Operation_withdraw() const
{
	return m_forkedToken_Operation_withdraw;
}

// End Class ForkedToken

// Begin Class GetNextEventStrategy
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getGetNextEventStrategy_Class() const
{
	return m_getNextEventStrategy_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getGetNextEventStrategy_Operation_getName() const
{
	return m_getNextEventStrategy_Operation_getName;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getGetNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation() const
{
	return m_getNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation;
}

// End Class GetNextEventStrategy

// Begin Class InitialNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getInitialNodeActivation_Class() const
{
	return m_initialNodeActivation_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getInitialNodeActivation_Operation_fire_Token() const
{
	return m_initialNodeActivation_Operation_fire_Token;
}

// End Class InitialNodeActivation

// Begin Class InputPinActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getInputPinActivation_Class() const
{
	return m_inputPinActivation_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getInputPinActivation_Operation_isReady() const
{
	return m_inputPinActivation_Operation_isReady;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getInputPinActivation_Operation_recieveOffer() const
{
	return m_inputPinActivation_Operation_recieveOffer;
}

// End Class InputPinActivation

// Begin Class InstanceValueEvaluation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getInstanceValueEvaluation_Class() const
{
	return m_instanceValueEvaluation_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getInstanceValueEvaluation_Operation_evaluate() const
{
	return m_instanceValueEvaluation_Operation_evaluate;
}

// End Class InstanceValueEvaluation

// Begin Class IntegerValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getIntegerValue_Class() const
{
	return m_integerValue_Class;
}

std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getIntegerValue_Attribute_value() const
{
	return m_integerValue_Attribute_value;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getIntegerValue_Operation_equals_Value() const
{
	return m_integerValue_Operation_equals_Value;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getIntegerValue_Operation_specify() const
{
	return m_integerValue_Operation_specify;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getIntegerValue_Operation_toString() const
{
	return m_integerValue_Operation_toString;
}

// End Class IntegerValue

// Begin Class InvocationActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getInvocationActionActivation_Class() const
{
	return m_invocationActionActivation_Class;
}




// End Class InvocationActionActivation

// Begin Class InvocationEventOccurrence
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getInvocationEventOccurrence_Class() const
{
	return m_invocationEventOccurrence_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getInvocationEventOccurrence_Attribute_execution() const
{
	return m_invocationEventOccurrence_Attribute_execution;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getInvocationEventOccurrence_Operation_getParameterValues() const
{
	return m_invocationEventOccurrence_Operation_getParameterValues;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getInvocationEventOccurrence_Operation_match_Trigger() const
{
	return m_invocationEventOccurrence_Operation_match_Trigger;
}

// End Class InvocationEventOccurrence

// Begin Class JoinNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getJoinNodeActivation_Class() const
{
	return m_joinNodeActivation_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getJoinNodeActivation_Operation_isReady() const
{
	return m_joinNodeActivation_Operation_isReady;
}

// End Class JoinNodeActivation

// Begin Class Link
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getLink_Class() const
{
	return m_link_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getLink_Attribute_type() const
{
	return m_link_Attribute_type;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLink_Operation_addTo_Locus() const
{
	return m_link_Operation_addTo_Locus;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLink_Operation_getOtherFeatureValues_ExtensionalValue_Property() const
{
	return m_link_Operation_getOtherFeatureValues_ExtensionalValue_Property;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLink_Operation_getTypes() const
{
	return m_link_Operation_getTypes;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLink_Operation_isMatchingLink_ExtensionalValue_Property() const
{
	return m_link_Operation_isMatchingLink_ExtensionalValue_Property;
}

// End Class Link

// Begin Class LinkActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getLinkActionActivation_Class() const
{
	return m_linkActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLinkActionActivation_Operation_endMatchesEndData_Link_LinkEndData() const
{
	return m_linkActionActivation_Operation_endMatchesEndData_Link_LinkEndData;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLinkActionActivation_Operation_getAssociation() const
{
	return m_linkActionActivation_Operation_getAssociation;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLinkActionActivation_Operation_linkMatchesEndData_Link_LinkEndData() const
{
	return m_linkActionActivation_Operation_linkMatchesEndData_Link_LinkEndData;
}

// End Class LinkActionActivation

// Begin Class LiteralBooleanEvaluation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getLiteralBooleanEvaluation_Class() const
{
	return m_literalBooleanEvaluation_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLiteralBooleanEvaluation_Operation_evaluate() const
{
	return m_literalBooleanEvaluation_Operation_evaluate;
}

// End Class LiteralBooleanEvaluation

// Begin Class LiteralEvaluation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getLiteralEvaluation_Class() const
{
	return m_literalEvaluation_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLiteralEvaluation_Operation_getType_EString() const
{
	return m_literalEvaluation_Operation_getType_EString;
}

// End Class LiteralEvaluation

// Begin Class LiteralIntegerEvaluation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getLiteralIntegerEvaluation_Class() const
{
	return m_literalIntegerEvaluation_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLiteralIntegerEvaluation_Operation_evaluate() const
{
	return m_literalIntegerEvaluation_Operation_evaluate;
}

// End Class LiteralIntegerEvaluation

// Begin Class LiteralNullEvaluation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getLiteralNullEvaluation_Class() const
{
	return m_literalNullEvaluation_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLiteralNullEvaluation_Operation_evaluate() const
{
	return m_literalNullEvaluation_Operation_evaluate;
}

// End Class LiteralNullEvaluation

// Begin Class LiteralRealEvaluation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getLiteralRealEvaluation_Class() const
{
	return m_literalRealEvaluation_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLiteralRealEvaluation_Operation_evaluate() const
{
	return m_literalRealEvaluation_Operation_evaluate;
}

// End Class LiteralRealEvaluation

// Begin Class LiteralStringEvaluation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getLiteralStringEvaluation_Class() const
{
	return m_literalStringEvaluation_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLiteralStringEvaluation_Operation_evaluate() const
{
	return m_literalStringEvaluation_Operation_evaluate;
}

// End Class LiteralStringEvaluation

// Begin Class LiteralUnlimitedNaturalEvaluation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getLiteralUnlimitedNaturalEvaluation_Class() const
{
	return m_literalUnlimitedNaturalEvaluation_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLiteralUnlimitedNaturalEvaluation_Operation_evaluate() const
{
	return m_literalUnlimitedNaturalEvaluation_Operation_evaluate;
}

// End Class LiteralUnlimitedNaturalEvaluation

// Begin Class Locus
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getLocus_Class() const
{
	return m_locus_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getLocus_Attribute_executor() const
{
	return m_locus_Attribute_executor;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getLocus_Attribute_extensionalValues() const
{
	return m_locus_Attribute_extensionalValues;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getLocus_Attribute_factory() const
{
	return m_locus_Attribute_factory;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLocus_Operation_add_ExtensionalValue() const
{
	return m_locus_Operation_add_ExtensionalValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLocus_Operation_assignExecutor_Executor() const
{
	return m_locus_Operation_assignExecutor_Executor;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLocus_Operation_assignFactory_ExecutionFactory() const
{
	return m_locus_Operation_assignFactory_ExecutionFactory;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLocus_Operation_conforms_Classifier_Classifier() const
{
	return m_locus_Operation_conforms_Classifier_Classifier;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLocus_Operation_instantiate_Class() const
{
	return m_locus_Operation_instantiate_Class;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLocus_Operation_remove_ExtensionalValue() const
{
	return m_locus_Operation_remove_ExtensionalValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLocus_Operation_retrieveExtent_Classifier() const
{
	return m_locus_Operation_retrieveExtent_Classifier;
}

// End Class Locus

// Begin Class LoopNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getLoopNodeActivation_Class() const
{
	return m_loopNodeActivation_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getLoopNodeActivation_Attribute_bodyOutputLists() const
{
	return m_loopNodeActivation_Attribute_bodyOutputLists;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLoopNodeActivation_Operation_makeLoopVariableList() const
{
	return m_loopNodeActivation_Operation_makeLoopVariableList;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLoopNodeActivation_Operation_runBody() const
{
	return m_loopNodeActivation_Operation_runBody;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLoopNodeActivation_Operation_runLoopVariables() const
{
	return m_loopNodeActivation_Operation_runLoopVariables;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLoopNodeActivation_Operation_runTest() const
{
	return m_loopNodeActivation_Operation_runTest;
}

// End Class LoopNodeActivation

// Begin Class MergeNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getMergeNodeActivation_Class() const
{
	return m_mergeNodeActivation_Class;
}




// End Class MergeNodeActivation

// Begin Class Object
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getObject_Class() const
{
	return m_object_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getObject_Attribute_objectActivation() const
{
	return m_object_Attribute_objectActivation;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getObject_Attribute_types() const
{
	return m_object_Attribute_types;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObject_Operation__register_EventAccepter() const
{
	return m_object_Operation__register_EventAccepter;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObject_Operation_destroy() const
{
	return m_object_Operation_destroy;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObject_Operation_dispatch_Operation() const
{
	return m_object_Operation_dispatch_Operation;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObject_Operation_new_() const
{
	return m_object_Operation_new_;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObject_Operation_send_SignalInstance() const
{
	return m_object_Operation_send_SignalInstance;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObject_Operation_send_EventOccurrence() const
{
	return m_object_Operation_send_EventOccurrence;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObject_Operation_startBehavior_Class_ParameterValue() const
{
	return m_object_Operation_startBehavior_Class_ParameterValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObject_Operation_unregister_EventAccepter() const
{
	return m_object_Operation_unregister_EventAccepter;
}

// End Class Object

// Begin Class ObjectActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getObjectActivation_Class() const
{
	return m_objectActivation_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getObjectActivation_Attribute_classifierBehaviorExecutions() const
{
	return m_objectActivation_Attribute_classifierBehaviorExecutions;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getObjectActivation_Attribute_eventPool() const
{
	return m_objectActivation_Attribute_eventPool;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getObjectActivation_Attribute_object() const
{
	return m_objectActivation_Attribute_object;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getObjectActivation_Attribute_waitingEventAccepters() const
{
	return m_objectActivation_Attribute_waitingEventAccepters;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectActivation_Operation__register_EventAccepter() const
{
	return m_objectActivation_Operation__register_EventAccepter;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectActivation_Operation__send_EJavaObject() const
{
	return m_objectActivation_Operation__send_EJavaObject;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectActivation_Operation__startObjectBehavior() const
{
	return m_objectActivation_Operation__startObjectBehavior;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectActivation_Operation_dispatchNextEvent() const
{
	return m_objectActivation_Operation_dispatchNextEvent;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectActivation_Operation_retrieveNextEvent() const
{
	return m_objectActivation_Operation_retrieveNextEvent;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectActivation_Operation_send_SignalInstance() const
{
	return m_objectActivation_Operation_send_SignalInstance;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectActivation_Operation_startBehavior_Class_ParameterValue() const
{
	return m_objectActivation_Operation_startBehavior_Class_ParameterValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectActivation_Operation_stop() const
{
	return m_objectActivation_Operation_stop;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectActivation_Operation_unregister_EventAccepter() const
{
	return m_objectActivation_Operation_unregister_EventAccepter;
}

// End Class ObjectActivation

// Begin Class ObjectNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getObjectNodeActivation_Class() const
{
	return m_objectNodeActivation_Class;
}

std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getObjectNodeActivation_Attribute_offeredTokenCount() const
{
	return m_objectNodeActivation_Attribute_offeredTokenCount;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectNodeActivation_Operation_addToken_Token() const
{
	return m_objectNodeActivation_Operation_addToken_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectNodeActivation_Operation_clearTokens() const
{
	return m_objectNodeActivation_Operation_clearTokens;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectNodeActivation_Operation_countOfferedValues() const
{
	return m_objectNodeActivation_Operation_countOfferedValues;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectNodeActivation_Operation_countUnofferedTokens() const
{
	return m_objectNodeActivation_Operation_countUnofferedTokens;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectNodeActivation_Operation_getUnofferedTokens() const
{
	return m_objectNodeActivation_Operation_getUnofferedTokens;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectNodeActivation_Operation_removeToken_Token() const
{
	return m_objectNodeActivation_Operation_removeToken_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectNodeActivation_Operation_run() const
{
	return m_objectNodeActivation_Operation_run;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectNodeActivation_Operation_sendOffers_Token() const
{
	return m_objectNodeActivation_Operation_sendOffers_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectNodeActivation_Operation_sendUnofferedTokens() const
{
	return m_objectNodeActivation_Operation_sendUnofferedTokens;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectNodeActivation_Operation_takeUnofferedTokens() const
{
	return m_objectNodeActivation_Operation_takeUnofferedTokens;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectNodeActivation_Operation_terminate() const
{
	return m_objectNodeActivation_Operation_terminate;
}

// End Class ObjectNodeActivation

// Begin Class ObjectToken
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getObjectToken_Class() const
{
	return m_objectToken_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getObjectToken_Attribute_value() const
{
	return m_objectToken_Attribute_value;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectToken_Operation_equals_Token() const
{
	return m_objectToken_Operation_equals_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectToken_Operation_isControl() const
{
	return m_objectToken_Operation_isControl;
}

// End Class ObjectToken

// Begin Class Offer
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getOffer_Class() const
{
	return m_offer_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getOffer_Attribute_offeredTokens() const
{
	return m_offer_Attribute_offeredTokens;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getOffer_Operation_countOfferedVales() const
{
	return m_offer_Operation_countOfferedVales;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getOffer_Operation_hasTokens() const
{
	return m_offer_Operation_hasTokens;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getOffer_Operation_removeOfferedValues_EInt() const
{
	return m_offer_Operation_removeOfferedValues_EInt;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getOffer_Operation_removeWithdrawnTokens() const
{
	return m_offer_Operation_removeWithdrawnTokens;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getOffer_Operation_retrieveOfferedTokens() const
{
	return m_offer_Operation_retrieveOfferedTokens;
}

// End Class Offer

// Begin Class OpaqueBehaviorExecution
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getOpaqueBehaviorExecution_Class() const
{
	return m_opaqueBehaviorExecution_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getOpaqueBehaviorExecution_Operation_doBody_ParameterValue_ParameterValue() const
{
	return m_opaqueBehaviorExecution_Operation_doBody_ParameterValue_ParameterValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getOpaqueBehaviorExecution_Operation_execute() const
{
	return m_opaqueBehaviorExecution_Operation_execute;
}

// End Class OpaqueBehaviorExecution

// Begin Class OutputPinActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getOutputPinActivation_Class() const
{
	return m_outputPinActivation_Class;
}




// End Class OutputPinActivation

// Begin Class ParameterValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getParameterValue_Class() const
{
	return m_parameterValue_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getParameterValue_Attribute_parameter() const
{
	return m_parameterValue_Attribute_parameter;
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getParameterValue_Attribute_values() const
{
	return m_parameterValue_Attribute_values;
}


// End Class ParameterValue

// Begin Class PinActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getPinActivation_Class() const
{
	return m_pinActivation_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getPinActivation_Attribute_actionActivation() const
{
	return m_pinActivation_Attribute_actionActivation;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getPinActivation_Operation_fire_Token() const
{
	return m_pinActivation_Operation_fire_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getPinActivation_Operation_takeOfferedTokens() const
{
	return m_pinActivation_Operation_takeOfferedTokens;
}

// End Class PinActivation

// Begin Class PrimitiveValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getPrimitiveValue_Class() const
{
	return m_primitiveValue_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getPrimitiveValue_Attribute_type() const
{
	return m_primitiveValue_Attribute_type;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getPrimitiveValue_Operation_getTypes() const
{
	return m_primitiveValue_Operation_getTypes;
}

// End Class PrimitiveValue

// Begin Class ReadExtentActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getReadExtentActionActivation_Class() const
{
	return m_readExtentActionActivation_Class;
}




// End Class ReadExtentActionActivation

// Begin Class ReadIsClassifiedObjectActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getReadIsClassifiedObjectActionActivation_Class() const
{
	return m_readIsClassifiedObjectActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReadIsClassifiedObjectActionActivation_Operation_checkAllParents_Classifier_Classifier() const
{
	return m_readIsClassifiedObjectActionActivation_Operation_checkAllParents_Classifier_Classifier;
}

// End Class ReadIsClassifiedObjectActionActivation

// Begin Class ReadLinkActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getReadLinkActionActivation_Class() const
{
	return m_readLinkActionActivation_Class;
}




// End Class ReadLinkActionActivation

// Begin Class ReadSelfActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getReadSelfActionActivation_Class() const
{
	return m_readSelfActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReadSelfActionActivation_Operation_doAction() const
{
	return m_readSelfActionActivation_Operation_doAction;
}

// End Class ReadSelfActionActivation

// Begin Class ReadStructuralFeatureActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getReadStructuralFeatureActionActivation_Class() const
{
	return m_readStructuralFeatureActionActivation_Class;
}




// End Class ReadStructuralFeatureActionActivation

// Begin Class RealValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getRealValue_Class() const
{
	return m_realValue_Class;
}

std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getRealValue_Attribute_value() const
{
	return m_realValue_Attribute_value;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getRealValue_Operation_equals_Value() const
{
	return m_realValue_Operation_equals_Value;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getRealValue_Operation_specify() const
{
	return m_realValue_Operation_specify;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getRealValue_Operation_toString() const
{
	return m_realValue_Operation_toString;
}

// End Class RealValue

// Begin Class ReclassifyObjectActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getReclassifyObjectActionActivation_Class() const
{
	return m_reclassifyObjectActionActivation_Class;
}




// End Class ReclassifyObjectActionActivation

// Begin Class RedefinitionBasedDispatchStrategy
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getRedefinitionBasedDispatchStrategy_Class() const
{
	return m_redefinitionBasedDispatchStrategy_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getRedefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation() const
{
	return m_redefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getRedefinitionBasedDispatchStrategy_Operation_retrieveMethod_Object_Operation() const
{
	return m_redefinitionBasedDispatchStrategy_Operation_retrieveMethod_Object_Operation;
}

// End Class RedefinitionBasedDispatchStrategy

// Begin Class ReduceActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getReduceActionActivation_Class() const
{
	return m_reduceActionActivation_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getReduceActionActivation_Attribute_currentExecution() const
{
	return m_reduceActionActivation_Attribute_currentExecution;
}


// End Class ReduceActionActivation

// Begin Class Reference
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getReference_Class() const
{
	return m_reference_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getReference_Attribute_referent() const
{
	return m_reference_Attribute_referent;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReference_Operation_assignFeatureValue_StructuralFeature_EInt() const
{
	return m_reference_Operation_assignFeatureValue_StructuralFeature_EInt;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReference_Operation_destroy() const
{
	return m_reference_Operation_destroy;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReference_Operation_dispatch_Operation() const
{
	return m_reference_Operation_dispatch_Operation;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReference_Operation_equals_Value() const
{
	return m_reference_Operation_equals_Value;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReference_Operation_getTypes() const
{
	return m_reference_Operation_getTypes;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReference_Operation_new_() const
{
	return m_reference_Operation_new_;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReference_Operation_retrieveFeatureValue_StructuralFeature() const
{
	return m_reference_Operation_retrieveFeatureValue_StructuralFeature;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReference_Operation_retrieveFeatureValues() const
{
	return m_reference_Operation_retrieveFeatureValues;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReference_Operation_send_SignalInstance() const
{
	return m_reference_Operation_send_SignalInstance;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReference_Operation_send_EventOccurrence() const
{
	return m_reference_Operation_send_EventOccurrence;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReference_Operation_startBehavior_Class_ParameterValue() const
{
	return m_reference_Operation_startBehavior_Class_ParameterValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReference_Operation_toString() const
{
	return m_reference_Operation_toString;
}

// End Class Reference

// Begin Class RemoveStructuralFeatureValueActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getRemoveStructuralFeatureValueActivation_Class() const
{
	return m_removeStructuralFeatureValueActivation_Class;
}




// End Class RemoveStructuralFeatureValueActivation

// Begin Class ReplyActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getReplyActionActivation_Class() const
{
	return m_replyActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReplyActionActivation_Operation_doAction() const
{
	return m_replyActionActivation_Operation_doAction;
}

// End Class ReplyActionActivation

// Begin Class ReturnInformation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getReturnInformation_Class() const
{
	return m_returnInformation_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getReturnInformation_Attribute_callEventOccurrence() const
{
	return m_returnInformation_Attribute_callEventOccurrence;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReturnInformation_Operation_copy() const
{
	return m_returnInformation_Operation_copy;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReturnInformation_Operation_equals_Value() const
{
	return m_returnInformation_Operation_equals_Value;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReturnInformation_Operation_getOperation() const
{
	return m_returnInformation_Operation_getOperation;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReturnInformation_Operation_getTypes() const
{
	return m_returnInformation_Operation_getTypes;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReturnInformation_Operation_new_() const
{
	return m_returnInformation_Operation_new_;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReturnInformation_Operation_reply_ParameterValue() const
{
	return m_returnInformation_Operation_reply_ParameterValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReturnInformation_Operation_specify() const
{
	return m_returnInformation_Operation_specify;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReturnInformation_Operation_toString() const
{
	return m_returnInformation_Operation_toString;
}

// End Class ReturnInformation

// Begin Class SemanticStrategy
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getSemanticStrategy_Class() const
{
	return m_semanticStrategy_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getSemanticStrategy_Operation_getName() const
{
	return m_semanticStrategy_Operation_getName;
}

// End Class SemanticStrategy

// Begin Class SemanticVisitor
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getSemanticVisitor_Class() const
{
	return m_semanticVisitor_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getSemanticVisitor_Operation__beginIsolation() const
{
	return m_semanticVisitor_Operation__beginIsolation;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getSemanticVisitor_Operation__endIsolation() const
{
	return m_semanticVisitor_Operation__endIsolation;
}

// End Class SemanticVisitor

// Begin Class SendSignalActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getSendSignalActionActivation_Class() const
{
	return m_sendSignalActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getSendSignalActionActivation_Operation_doAction() const
{
	return m_sendSignalActionActivation_Operation_doAction;
}

// End Class SendSignalActionActivation

// Begin Class SignalEventOccurrence
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getSignalEventOccurrence_Class() const
{
	return m_signalEventOccurrence_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getSignalEventOccurrence_Attribute_signalInstance() const
{
	return m_signalEventOccurrence_Attribute_signalInstance;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getSignalEventOccurrence_Operation_getParameterValues() const
{
	return m_signalEventOccurrence_Operation_getParameterValues;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getSignalEventOccurrence_Operation_match_Trigger() const
{
	return m_signalEventOccurrence_Operation_match_Trigger;
}

// End Class SignalEventOccurrence

// Begin Class SignalInstance
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getSignalInstance_Class() const
{
	return m_signalInstance_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getSignalInstance_Attribute_type() const
{
	return m_signalInstance_Attribute_type;
}


// End Class SignalInstance

// Begin Class StartClassifierBehaviorActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getStartClassifierBehaviorActionActivation_Class() const
{
	return m_startClassifierBehaviorActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStartClassifierBehaviorActionActivation_Operation_doAction() const
{
	return m_startClassifierBehaviorActionActivation_Operation_doAction;
}

// End Class StartClassifierBehaviorActionActivation

// Begin Class StartObjectBehaviorActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getStartObjectBehaviorActionActivation_Class() const
{
	return m_startObjectBehaviorActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStartObjectBehaviorActionActivation_Operation_doAction() const
{
	return m_startObjectBehaviorActionActivation_Operation_doAction;
}

// End Class StartObjectBehaviorActionActivation

// Begin Class StringValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getStringValue_Class() const
{
	return m_stringValue_Class;
}

std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getStringValue_Attribute_value() const
{
	return m_stringValue_Attribute_value;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStringValue_Operation_equals_Value() const
{
	return m_stringValue_Operation_equals_Value;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStringValue_Operation_specify() const
{
	return m_stringValue_Operation_specify;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStringValue_Operation_toString() const
{
	return m_stringValue_Operation_toString;
}

// End Class StringValue

// Begin Class StructuralFeatureActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getStructuralFeatureActionActivation_Class() const
{
	return m_structuralFeatureActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuralFeatureActionActivation_Operation_getAssociation_StructuralFeature() const
{
	return m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuralFeatureActionActivation_Operation_getMatchingLinks_Association_Value() const
{
	return m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_Value;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_Value() const
{
	return m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_Value;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature() const
{
	return m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature;
}

// End Class StructuralFeatureActionActivation

// Begin Class StructuredActivityNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getStructuredActivityNodeActivation_Class() const
{
	return m_structuredActivityNodeActivation_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getStructuredActivityNodeActivation_Attribute_activationGroup() const
{
	return m_structuredActivityNodeActivation_Attribute_activationGroup;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation_Operation_completeAction() const
{
	return m_structuredActivityNodeActivation_Operation_completeAction;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation_Operation_createEdgeInstances() const
{
	return m_structuredActivityNodeActivation_Operation_createEdgeInstances;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation_Operation_createNodeActivations() const
{
	return m_structuredActivityNodeActivation_Operation_createNodeActivations;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation_Operation_doAction() const
{
	return m_structuredActivityNodeActivation_Operation_doAction;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation_Operation_doStructuredActivity() const
{
	return m_structuredActivityNodeActivation_Operation_doStructuredActivity;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode() const
{
	return m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation_Operation_getPinValues_OutputPin() const
{
	return m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance() const
{
	return m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation_Operation_isSuspended() const
{
	return m_structuredActivityNodeActivation_Operation_isSuspended;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode() const
{
	return m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation_Operation_putPinValues_OutputPin_Value() const
{
	return m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_Value;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation_Operation_resume() const
{
	return m_structuredActivityNodeActivation_Operation_resume;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation_Operation_terminate() const
{
	return m_structuredActivityNodeActivation_Operation_terminate;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation_Operation_terminateAll() const
{
	return m_structuredActivityNodeActivation_Operation_terminateAll;
}

// End Class StructuredActivityNodeActivation

// Begin Class StructuredValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getStructuredValue_Class() const
{
	return m_structuredValue_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredValue_Operation_assignFeatureValue_StructuralFeature_EInt() const
{
	return m_structuredValue_Operation_assignFeatureValue_StructuralFeature_EInt;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredValue_Operation_createFeatureValues() const
{
	return m_structuredValue_Operation_createFeatureValues;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredValue_Operation_retrieveFeatureValue_StructuralFeature() const
{
	return m_structuredValue_Operation_retrieveFeatureValue_StructuralFeature;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredValue_Operation_retrieveFeatureValues() const
{
	return m_structuredValue_Operation_retrieveFeatureValues;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredValue_Operation_specify() const
{
	return m_structuredValue_Operation_specify;
}

// End Class StructuredValue

// Begin Class TestIdentityActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getTestIdentityActionActivation_Class() const
{
	return m_testIdentityActionActivation_Class;
}




// End Class TestIdentityActionActivation

// Begin Class Token
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getToken_Class() const
{
	return m_token_Class;
}

std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getToken_Attribute_withdrawn() const
{
	return m_token_Attribute_withdrawn;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getToken_Attribute_holder() const
{
	return m_token_Attribute_holder;
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getToken_Operation_equals_Token() const
{
	return m_token_Operation_equals_Token;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getToken_Operation_getValue() const
{
	return m_token_Operation_getValue;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getToken_Operation_isControl() const
{
	return m_token_Operation_isControl;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getToken_Operation_transfer_ActivityNodeActivation() const
{
	return m_token_Operation_transfer_ActivityNodeActivation;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getToken_Operation_withdraw() const
{
	return m_token_Operation_withdraw;
}

// End Class Token

// Begin Class TokenSet
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getTokenSet_Class() const
{
	return m_tokenSet_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getTokenSet_Attribute_tokens() const
{
	return m_tokenSet_Attribute_tokens;
}


// End Class TokenSet

// Begin Class UnlimitedNaturalValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getUnlimitedNaturalValue_Class() const
{
	return m_unlimitedNaturalValue_Class;
}

std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getUnlimitedNaturalValue_Attribute_value() const
{
	return m_unlimitedNaturalValue_Attribute_value;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getUnlimitedNaturalValue_Operation_equals_Value() const
{
	return m_unlimitedNaturalValue_Operation_equals_Value;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getUnlimitedNaturalValue_Operation_specify() const
{
	return m_unlimitedNaturalValue_Operation_specify;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getUnlimitedNaturalValue_Operation_toString() const
{
	return m_unlimitedNaturalValue_Operation_toString;
}

// End Class UnlimitedNaturalValue

// Begin Class Value
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getValue_Class() const
{
	return m_value_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getValue_Operation_checkAllParents_Classifier_Classifier() const
{
	return m_value_Operation_checkAllParents_Classifier_Classifier;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getValue_Operation_equals_Value() const
{
	return m_value_Operation_equals_Value;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getValue_Operation_getTypes() const
{
	return m_value_Operation_getTypes;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getValue_Operation_hasTypes_Classifier() const
{
	return m_value_Operation_hasTypes_Classifier;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getValue_Operation_objectId() const
{
	return m_value_Operation_objectId;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getValue_Operation_specify() const
{
	return m_value_Operation_specify;
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getValue_Operation_toString() const
{
	return m_value_Operation_toString;
}

// End Class Value

// Begin Class ValueSpecificationActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getValueSpecificationActionActivation_Class() const
{
	return m_valueSpecificationActionActivation_Class;
}




// End Class ValueSpecificationActionActivation

// Begin Class Values
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getValues_Class() const
{
	return m_values_Class;
}


std::shared_ptr<ecore::EReference> FUMLPackageImpl::getValues_Attribute_values() const
{
	return m_values_Attribute_values;
}


// End Class Values

// Begin Class WriteLinkActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getWriteLinkActionActivation_Class() const
{
	return m_writeLinkActionActivation_Class;
}




// End Class WriteLinkActionActivation

// Begin Class WriteStructuralFeatureActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getWriteStructuralFeatureActionActivation_Class() const
{
	return m_writeStructuralFeatureActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getWriteStructuralFeatureActionActivation_Operation_position_Value_EInt() const
{
	return m_writeStructuralFeatureActionActivation_Operation_position_Value_EInt;
}

// End Class WriteStructuralFeatureActionActivation

