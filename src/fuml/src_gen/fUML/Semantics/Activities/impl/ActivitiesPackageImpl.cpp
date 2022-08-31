#include "fUML/Semantics/Activities/impl/ActivitiesPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EDataType.hpp"

//metamodel factory
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::Activities;

bool ActivitiesPackageImpl::isInited = false;

ActivitiesPackageImpl::ActivitiesPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( ActivitiesFactory::eInstance()));
}

ActivitiesPackageImpl::~ActivitiesPackageImpl()
{
}

ActivitiesPackage* ActivitiesPackageImpl::create()
{
	if (isInited)
	{
		return ActivitiesPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    ActivitiesPackageImpl * metaModelPackage = new ActivitiesPackageImpl();
    return metaModelPackage;
}

void ActivitiesPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}



// Begin Class ActivityEdgeInstance
std::shared_ptr<ecore::EClass> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityEdgeInstance_Class() const
{
	return m_activityEdgeInstance_Class;
}


std::shared_ptr<ecore::EReference> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityEdgeInstance_Attribute_edge() const
{
	return m_activityEdgeInstance_Attribute_edge;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityEdgeInstance_Attribute_group() const
{
	return m_activityEdgeInstance_Attribute_group;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityEdgeInstance_Attribute_offers() const
{
	return m_activityEdgeInstance_Attribute_offers;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityEdgeInstance_Attribute_source() const
{
	return m_activityEdgeInstance_Attribute_source;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityEdgeInstance_Attribute_target() const
{
	return m_activityEdgeInstance_Attribute_target;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityEdgeInstance_Operation_countOfferedValue() const
{
	return m_activityEdgeInstance_Operation_countOfferedValue;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityEdgeInstance_Operation_getOfferedTokens() const
{
	return m_activityEdgeInstance_Operation_getOfferedTokens;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityEdgeInstance_Operation_hasOffer() const
{
	return m_activityEdgeInstance_Operation_hasOffer;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityEdgeInstance_Operation_sendOffer_Token() const
{
	return m_activityEdgeInstance_Operation_sendOffer_Token;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityEdgeInstance_Operation_takeOfferedTokens() const
{
	return m_activityEdgeInstance_Operation_takeOfferedTokens;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityEdgeInstance_Operation_takeOfferedTokens_EInt() const
{
	return m_activityEdgeInstance_Operation_takeOfferedTokens_EInt;
}

// End Class ActivityEdgeInstance

// Begin Class ActivityExecution
std::shared_ptr<ecore::EClass> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityExecution_Class() const
{
	return m_activityExecution_Class;
}


std::shared_ptr<ecore::EReference> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityExecution_Attribute_activationGroup() const
{
	return m_activityExecution_Attribute_activationGroup;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityExecution_Attribute_activity() const
{
	return m_activityExecution_Attribute_activity;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityExecution_Operation__copy() const
{
	return m_activityExecution_Operation__copy;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityExecution_Operation_execute() const
{
	return m_activityExecution_Operation_execute;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityExecution_Operation_new_() const
{
	return m_activityExecution_Operation_new_;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityExecution_Operation_terminate() const
{
	return m_activityExecution_Operation_terminate;
}

// End Class ActivityExecution

// Begin Class ActivityFinalNodeActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityFinalNodeActivation_Class() const
{
	return m_activityFinalNodeActivation_Class;
}



std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityFinalNodeActivation_Operation_fire_Token() const
{
	return m_activityFinalNodeActivation_Operation_fire_Token;
}

// End Class ActivityFinalNodeActivation

// Begin Class ActivityNodeActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Class() const
{
	return m_activityNodeActivation_Class;
}

std::shared_ptr<ecore::EAttribute> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Attribute_running() const
{
	return m_activityNodeActivation_Attribute_running;
}

std::shared_ptr<ecore::EReference> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Attribute_group() const
{
	return m_activityNodeActivation_Attribute_group;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Attribute_heldTokens() const
{
	return m_activityNodeActivation_Attribute_heldTokens;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Attribute_incomingEdges() const
{
	return m_activityNodeActivation_Attribute_incomingEdges;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Attribute_node() const
{
	return m_activityNodeActivation_Attribute_node;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Attribute_outgoingEdges() const
{
	return m_activityNodeActivation_Attribute_outgoingEdges;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_addIncomingEdge_ActivityEdgeInstance() const
{
	return m_activityNodeActivation_Operation_addIncomingEdge_ActivityEdgeInstance;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_addOutgoingEdge_ActivityEdgeInstance() const
{
	return m_activityNodeActivation_Operation_addOutgoingEdge_ActivityEdgeInstance;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_addToken_Token() const
{
	return m_activityNodeActivation_Operation_addToken_Token;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_addTokens_Token() const
{
	return m_activityNodeActivation_Operation_addTokens_Token;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_clearTokens() const
{
	return m_activityNodeActivation_Operation_clearTokens;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_createEdgeInstances() const
{
	return m_activityNodeActivation_Operation_createEdgeInstances;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_createNodeActivations() const
{
	return m_activityNodeActivation_Operation_createNodeActivations;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_fire_Token() const
{
	return m_activityNodeActivation_Operation_fire_Token;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_getActivityExecution() const
{
	return m_activityNodeActivation_Operation_getActivityExecution;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_getExecutionContext() const
{
	return m_activityNodeActivation_Operation_getExecutionContext;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_getExecutionLocus() const
{
	return m_activityNodeActivation_Operation_getExecutionLocus;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_getNodeActivation_ActivityNode() const
{
	return m_activityNodeActivation_Operation_getNodeActivation_ActivityNode;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_getRunning() const
{
	return m_activityNodeActivation_Operation_getRunning;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_getTokens() const
{
	return m_activityNodeActivation_Operation_getTokens;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_isReady() const
{
	return m_activityNodeActivation_Operation_isReady;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance() const
{
	return m_activityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_receiveOffer() const
{
	return m_activityNodeActivation_Operation_receiveOffer;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_removeToken_Token() const
{
	return m_activityNodeActivation_Operation_removeToken_Token;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_resume() const
{
	return m_activityNodeActivation_Operation_resume;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_run() const
{
	return m_activityNodeActivation_Operation_run;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_sendOffers_Token() const
{
	return m_activityNodeActivation_Operation_sendOffers_Token;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_suspend() const
{
	return m_activityNodeActivation_Operation_suspend;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_takeOfferedTokens() const
{
	return m_activityNodeActivation_Operation_takeOfferedTokens;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_takeTokens() const
{
	return m_activityNodeActivation_Operation_takeTokens;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_terminate() const
{
	return m_activityNodeActivation_Operation_terminate;
}

// End Class ActivityNodeActivation

// Begin Class ActivityNodeActivationGroup
std::shared_ptr<ecore::EClass> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Class() const
{
	return m_activityNodeActivationGroup_Class;
}


std::shared_ptr<ecore::EReference> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Attribute_activityExecution() const
{
	return m_activityNodeActivationGroup_Attribute_activityExecution;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Attribute_containingNodeActivation() const
{
	return m_activityNodeActivationGroup_Attribute_containingNodeActivation;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Attribute_edgeInstances() const
{
	return m_activityNodeActivationGroup_Attribute_edgeInstances;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Attribute_nodeActivations() const
{
	return m_activityNodeActivationGroup_Attribute_nodeActivations;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Attribute_suspendedActivations() const
{
	return m_activityNodeActivationGroup_Attribute_suspendedActivations;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Operation_activate_ActivityNode_ActivityEdge() const
{
	return m_activityNodeActivationGroup_Operation_activate_ActivityNode_ActivityEdge;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Operation_addEdgeInstance_ActivityEdgeInstance() const
{
	return m_activityNodeActivationGroup_Operation_addEdgeInstance_ActivityEdgeInstance;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Operation_addNodeActivation_ActivityNodeActivation() const
{
	return m_activityNodeActivationGroup_Operation_addNodeActivation_ActivityNodeActivation;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Operation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation() const
{
	return m_activityNodeActivationGroup_Operation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Operation_createEdgeInstance_ActivityEdge() const
{
	return m_activityNodeActivationGroup_Operation_createEdgeInstance_ActivityEdge;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Operation_createNodeActivation_ActivityNode() const
{
	return m_activityNodeActivationGroup_Operation_createNodeActivation_ActivityNode;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Operation_createNodeActivations_ActivityNode() const
{
	return m_activityNodeActivationGroup_Operation_createNodeActivations_ActivityNode;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Operation_getNodeActivation_ActivityNode() const
{
	return m_activityNodeActivationGroup_Operation_getNodeActivation_ActivityNode;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Operation_getOutputParameterNodeActivations() const
{
	return m_activityNodeActivationGroup_Operation_getOutputParameterNodeActivations;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Operation_hasSourceFor_ActivityEdgeInstance() const
{
	return m_activityNodeActivationGroup_Operation_hasSourceFor_ActivityEdgeInstance;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Operation_isSuspended() const
{
	return m_activityNodeActivationGroup_Operation_isSuspended;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Operation_resume_ActivityNodeActivation() const
{
	return m_activityNodeActivationGroup_Operation_resume_ActivityNodeActivation;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Operation_retrieveActivityExecution() const
{
	return m_activityNodeActivationGroup_Operation_retrieveActivityExecution;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Operation_run_ActivityNodeActivation() const
{
	return m_activityNodeActivationGroup_Operation_run_ActivityNodeActivation;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Operation_runNodes_ActivityNode() const
{
	return m_activityNodeActivationGroup_Operation_runNodes_ActivityNode;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Operation_suspend_ActivityNodeActivation() const
{
	return m_activityNodeActivationGroup_Operation_suspend_ActivityNodeActivation;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Operation_terminateAll() const
{
	return m_activityNodeActivationGroup_Operation_terminateAll;
}

// End Class ActivityNodeActivationGroup

// Begin Class ActivityParameterNodeActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityParameterNodeActivation_Class() const
{
	return m_activityParameterNodeActivation_Class;
}



std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityParameterNodeActivation_Operation_clearTokens() const
{
	return m_activityParameterNodeActivation_Operation_clearTokens;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityParameterNodeActivation_Operation_fire_Token() const
{
	return m_activityParameterNodeActivation_Operation_fire_Token;
}

// End Class ActivityParameterNodeActivation

// Begin Class CentralBufferNodeActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Activities::ActivitiesPackageImpl::getCentralBufferNodeActivation_Class() const
{
	return m_centralBufferNodeActivation_Class;
}



std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getCentralBufferNodeActivation_Operation_fire_Token() const
{
	return m_centralBufferNodeActivation_Operation_fire_Token;
}

// End Class CentralBufferNodeActivation

// Begin Class ClassifierBehaviorExecutionActivity
std::shared_ptr<ecore::EClass> fUML::Semantics::Activities::ActivitiesPackageImpl::getClassifierBehaviorExecutionActivity_Class() const
{
	return m_classifierBehaviorExecutionActivity_Class;
}




// End Class ClassifierBehaviorExecutionActivity

// Begin Class ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1
std::shared_ptr<ecore::EClass> fUML::Semantics::Activities::ActivitiesPackageImpl::getClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1_Class() const
{
	return m_classifierBehaviorExecutionActivity_OwnedBehaviorActivity1_Class;
}




// End Class ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1

// Begin Class ControlNodeActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Activities::ActivitiesPackageImpl::getControlNodeActivation_Class() const
{
	return m_controlNodeActivation_Class;
}



std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getControlNodeActivation_Operation_fire_Token() const
{
	return m_controlNodeActivation_Operation_fire_Token;
}

// End Class ControlNodeActivation

// Begin Class ControlToken
std::shared_ptr<ecore::EClass> fUML::Semantics::Activities::ActivitiesPackageImpl::getControlToken_Class() const
{
	return m_controlToken_Class;
}



std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getControlToken_Operation__copy() const
{
	return m_controlToken_Operation__copy;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getControlToken_Operation_equals_Token() const
{
	return m_controlToken_Operation_equals_Token;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getControlToken_Operation_isControl() const
{
	return m_controlToken_Operation_isControl;
}

// End Class ControlToken

// Begin Class DataStoreNodeActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Activities::ActivitiesPackageImpl::getDataStoreNodeActivation_Class() const
{
	return m_dataStoreNodeActivation_Class;
}



std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getDataStoreNodeActivation_Operation_addToken_Token() const
{
	return m_dataStoreNodeActivation_Operation_addToken_Token;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getDataStoreNodeActivation_Operation_removeToken_Token() const
{
	return m_dataStoreNodeActivation_Operation_removeToken_Token;
}

// End Class DataStoreNodeActivation

// Begin Class DecisionNodeActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Activities::ActivitiesPackageImpl::getDecisionNodeActivation_Class() const
{
	return m_decisionNodeActivation_Class;
}


std::shared_ptr<ecore::EReference> fUML::Semantics::Activities::ActivitiesPackageImpl::getDecisionNodeActivation_Attribute_decisionInputExecution() const
{
	return m_decisionNodeActivation_Attribute_decisionInputExecution;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::Activities::ActivitiesPackageImpl::getDecisionNodeActivation_Attribute_decisionNode() const
{
	return m_decisionNodeActivation_Attribute_decisionNode;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getDecisionNodeActivation_Operation_executeDecisionInputBehavior_EJavaObject_EJavaObject() const
{
	return m_decisionNodeActivation_Operation_executeDecisionInputBehavior_EJavaObject_EJavaObject;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getDecisionNodeActivation_Operation_fire_Token() const
{
	return m_decisionNodeActivation_Operation_fire_Token;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getDecisionNodeActivation_Operation_getDecisionInputFlowInstance() const
{
	return m_decisionNodeActivation_Operation_getDecisionInputFlowInstance;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getDecisionNodeActivation_Operation_getDecisionInputFlowValue() const
{
	return m_decisionNodeActivation_Operation_getDecisionInputFlowValue;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getDecisionNodeActivation_Operation_getDecisionValues_Token() const
{
	return m_decisionNodeActivation_Operation_getDecisionValues_Token;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getDecisionNodeActivation_Operation_hasObjectFlowInput() const
{
	return m_decisionNodeActivation_Operation_hasObjectFlowInput;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getDecisionNodeActivation_Operation_isReady() const
{
	return m_decisionNodeActivation_Operation_isReady;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getDecisionNodeActivation_Operation_removeJoinedControlTokens_Token() const
{
	return m_decisionNodeActivation_Operation_removeJoinedControlTokens_Token;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getDecisionNodeActivation_Operation_takeOfferedTokens() const
{
	return m_decisionNodeActivation_Operation_takeOfferedTokens;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getDecisionNodeActivation_Operation_terminate() const
{
	return m_decisionNodeActivation_Operation_terminate;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getDecisionNodeActivation_Operation_test_ValueSpecification_EJavaObject() const
{
	return m_decisionNodeActivation_Operation_test_ValueSpecification_EJavaObject;
}

// End Class DecisionNodeActivation

// Begin Class ExpansionActivationGroup
std::shared_ptr<ecore::EClass> fUML::Semantics::Activities::ActivitiesPackageImpl::getExpansionActivationGroup_Class() const
{
	return m_expansionActivationGroup_Class;
}

std::shared_ptr<ecore::EAttribute> fUML::Semantics::Activities::ActivitiesPackageImpl::getExpansionActivationGroup_Attribute_index() const
{
	return m_expansionActivationGroup_Attribute_index;
}

std::shared_ptr<ecore::EReference> fUML::Semantics::Activities::ActivitiesPackageImpl::getExpansionActivationGroup_Attribute_groupInputs() const
{
	return m_expansionActivationGroup_Attribute_groupInputs;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::Activities::ActivitiesPackageImpl::getExpansionActivationGroup_Attribute_groupOutputs() const
{
	return m_expansionActivationGroup_Attribute_groupOutputs;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::Activities::ActivitiesPackageImpl::getExpansionActivationGroup_Attribute_regionActivation() const
{
	return m_expansionActivationGroup_Attribute_regionActivation;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::Activities::ActivitiesPackageImpl::getExpansionActivationGroup_Attribute_regionInputs() const
{
	return m_expansionActivationGroup_Attribute_regionInputs;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getExpansionActivationGroup_Operation_getActivityExecution() const
{
	return m_expansionActivationGroup_Operation_getActivityExecution;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getExpansionActivationGroup_Operation_getNodeActivation_ActivityNode() const
{
	return m_expansionActivationGroup_Operation_getNodeActivation_ActivityNode;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getExpansionActivationGroup_Operation_resume_ActivityNodeActivation() const
{
	return m_expansionActivationGroup_Operation_resume_ActivityNodeActivation;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getExpansionActivationGroup_Operation_suspend_ActivityNodeActivation() const
{
	return m_expansionActivationGroup_Operation_suspend_ActivityNodeActivation;
}

// End Class ExpansionActivationGroup

// Begin Class ExpansionNodeActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Activities::ActivitiesPackageImpl::getExpansionNodeActivation_Class() const
{
	return m_expansionNodeActivation_Class;
}



std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getExpansionNodeActivation_Operation_fire_Token() const
{
	return m_expansionNodeActivation_Operation_fire_Token;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getExpansionNodeActivation_Operation_getExpansionRegionActivation() const
{
	return m_expansionNodeActivation_Operation_getExpansionRegionActivation;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getExpansionNodeActivation_Operation_isReady() const
{
	return m_expansionNodeActivation_Operation_isReady;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getExpansionNodeActivation_Operation_receiveOffer() const
{
	return m_expansionNodeActivation_Operation_receiveOffer;
}

// End Class ExpansionNodeActivation

// Begin Class ExpansionRegionActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Activities::ActivitiesPackageImpl::getExpansionRegionActivation_Class() const
{
	return m_expansionRegionActivation_Class;
}

std::shared_ptr<ecore::EAttribute> fUML::Semantics::Activities::ActivitiesPackageImpl::getExpansionRegionActivation_Attribute_next() const
{
	return m_expansionRegionActivation_Attribute_next;
}

std::shared_ptr<ecore::EReference> fUML::Semantics::Activities::ActivitiesPackageImpl::getExpansionRegionActivation_Attribute_activationGroups() const
{
	return m_expansionRegionActivation_Attribute_activationGroups;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::Activities::ActivitiesPackageImpl::getExpansionRegionActivation_Attribute_inputExpansionTokens() const
{
	return m_expansionRegionActivation_Attribute_inputExpansionTokens;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::Activities::ActivitiesPackageImpl::getExpansionRegionActivation_Attribute_inputTokens() const
{
	return m_expansionRegionActivation_Attribute_inputTokens;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getExpansionRegionActivation_Operation_doAction() const
{
	return m_expansionRegionActivation_Operation_doAction;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getExpansionRegionActivation_Operation_doOutput() const
{
	return m_expansionRegionActivation_Operation_doOutput;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getExpansionRegionActivation_Operation_doStructuredActivity() const
{
	return m_expansionRegionActivation_Operation_doStructuredActivity;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getExpansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode() const
{
	return m_expansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getExpansionRegionActivation_Operation_isSuspended() const
{
	return m_expansionRegionActivation_Operation_isSuspended;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getExpansionRegionActivation_Operation_numberOfValues() const
{
	return m_expansionRegionActivation_Operation_numberOfValues;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getExpansionRegionActivation_Operation_resume_ExpansionActivationGroup() const
{
	return m_expansionRegionActivation_Operation_resume_ExpansionActivationGroup;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getExpansionRegionActivation_Operation_runGroup_ExpansionActivationGroup() const
{
	return m_expansionRegionActivation_Operation_runGroup_ExpansionActivationGroup;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getExpansionRegionActivation_Operation_runIterative() const
{
	return m_expansionRegionActivation_Operation_runIterative;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getExpansionRegionActivation_Operation_runParallel() const
{
	return m_expansionRegionActivation_Operation_runParallel;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getExpansionRegionActivation_Operation_sendOffers() const
{
	return m_expansionRegionActivation_Operation_sendOffers;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getExpansionRegionActivation_Operation_takeOfferedTokens() const
{
	return m_expansionRegionActivation_Operation_takeOfferedTokens;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getExpansionRegionActivation_Operation_terminate() const
{
	return m_expansionRegionActivation_Operation_terminate;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getExpansionRegionActivation_Operation_terminateGroup_ExpansionActivationGroup() const
{
	return m_expansionRegionActivation_Operation_terminateGroup_ExpansionActivationGroup;
}

// End Class ExpansionRegionActivation

// Begin Class FlowFinalNodeActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Activities::ActivitiesPackageImpl::getFlowFinalNodeActivation_Class() const
{
	return m_flowFinalNodeActivation_Class;
}




// End Class FlowFinalNodeActivation

// Begin Class ForkNodeActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Activities::ActivitiesPackageImpl::getForkNodeActivation_Class() const
{
	return m_forkNodeActivation_Class;
}



std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getForkNodeActivation_Operation_fire_Token() const
{
	return m_forkNodeActivation_Operation_fire_Token;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getForkNodeActivation_Operation_terminate() const
{
	return m_forkNodeActivation_Operation_terminate;
}

// End Class ForkNodeActivation

// Begin Class ForkedToken
std::shared_ptr<ecore::EClass> fUML::Semantics::Activities::ActivitiesPackageImpl::getForkedToken_Class() const
{
	return m_forkedToken_Class;
}

std::shared_ptr<ecore::EAttribute> fUML::Semantics::Activities::ActivitiesPackageImpl::getForkedToken_Attribute_baseTokenIsWithdrawn() const
{
	return m_forkedToken_Attribute_baseTokenIsWithdrawn;
}
std::shared_ptr<ecore::EAttribute> fUML::Semantics::Activities::ActivitiesPackageImpl::getForkedToken_Attribute_remainingOffersCount() const
{
	return m_forkedToken_Attribute_remainingOffersCount;
}

std::shared_ptr<ecore::EReference> fUML::Semantics::Activities::ActivitiesPackageImpl::getForkedToken_Attribute_baseToken() const
{
	return m_forkedToken_Attribute_baseToken;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getForkedToken_Operation__copy() const
{
	return m_forkedToken_Operation__copy;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getForkedToken_Operation_equals_Token() const
{
	return m_forkedToken_Operation_equals_Token;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getForkedToken_Operation_getValue() const
{
	return m_forkedToken_Operation_getValue;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getForkedToken_Operation_isControl() const
{
	return m_forkedToken_Operation_isControl;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getForkedToken_Operation_withdraw() const
{
	return m_forkedToken_Operation_withdraw;
}

// End Class ForkedToken

// Begin Class InitialNodeActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Activities::ActivitiesPackageImpl::getInitialNodeActivation_Class() const
{
	return m_initialNodeActivation_Class;
}



std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getInitialNodeActivation_Operation_fire_Token() const
{
	return m_initialNodeActivation_Operation_fire_Token;
}

// End Class InitialNodeActivation

// Begin Class JoinNodeActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Activities::ActivitiesPackageImpl::getJoinNodeActivation_Class() const
{
	return m_joinNodeActivation_Class;
}



std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getJoinNodeActivation_Operation_fire_Token() const
{
	return m_joinNodeActivation_Operation_fire_Token;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getJoinNodeActivation_Operation_isReady() const
{
	return m_joinNodeActivation_Operation_isReady;
}

// End Class JoinNodeActivation

// Begin Class MergeNodeActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Activities::ActivitiesPackageImpl::getMergeNodeActivation_Class() const
{
	return m_mergeNodeActivation_Class;
}




// End Class MergeNodeActivation

// Begin Class ObjectNodeActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectNodeActivation_Class() const
{
	return m_objectNodeActivation_Class;
}

std::shared_ptr<ecore::EAttribute> fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectNodeActivation_Attribute_offeredTokenCount() const
{
	return m_objectNodeActivation_Attribute_offeredTokenCount;
}


std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectNodeActivation_Operation_addToken_Token() const
{
	return m_objectNodeActivation_Operation_addToken_Token;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectNodeActivation_Operation_clearTokens() const
{
	return m_objectNodeActivation_Operation_clearTokens;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectNodeActivation_Operation_countOfferedValues() const
{
	return m_objectNodeActivation_Operation_countOfferedValues;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectNodeActivation_Operation_countUnofferedTokens() const
{
	return m_objectNodeActivation_Operation_countUnofferedTokens;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectNodeActivation_Operation_getUnofferedTokens() const
{
	return m_objectNodeActivation_Operation_getUnofferedTokens;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectNodeActivation_Operation_removeToken_Token() const
{
	return m_objectNodeActivation_Operation_removeToken_Token;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectNodeActivation_Operation_run() const
{
	return m_objectNodeActivation_Operation_run;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectNodeActivation_Operation_sendOffers_Token() const
{
	return m_objectNodeActivation_Operation_sendOffers_Token;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectNodeActivation_Operation_sendUnofferedTokens() const
{
	return m_objectNodeActivation_Operation_sendUnofferedTokens;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectNodeActivation_Operation_takeUnofferedTokens() const
{
	return m_objectNodeActivation_Operation_takeUnofferedTokens;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectNodeActivation_Operation_terminate() const
{
	return m_objectNodeActivation_Operation_terminate;
}

// End Class ObjectNodeActivation

// Begin Class ObjectToken
std::shared_ptr<ecore::EClass> fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectToken_Class() const
{
	return m_objectToken_Class;
}

std::shared_ptr<ecore::EAttribute> fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectToken_Attribute_value() const
{
	return m_objectToken_Attribute_value;
}


std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectToken_Operation__copy() const
{
	return m_objectToken_Operation__copy;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectToken_Operation_equals_Token() const
{
	return m_objectToken_Operation_equals_Token;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectToken_Operation_isControl() const
{
	return m_objectToken_Operation_isControl;
}

// End Class ObjectToken

// Begin Class Offer
std::shared_ptr<ecore::EClass> fUML::Semantics::Activities::ActivitiesPackageImpl::getOffer_Class() const
{
	return m_offer_Class;
}


std::shared_ptr<ecore::EReference> fUML::Semantics::Activities::ActivitiesPackageImpl::getOffer_Attribute_offeredTokens() const
{
	return m_offer_Attribute_offeredTokens;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getOffer_Operation_countOfferedVales() const
{
	return m_offer_Operation_countOfferedVales;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getOffer_Operation_hasTokens() const
{
	return m_offer_Operation_hasTokens;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getOffer_Operation_removeOfferedValues_EInt() const
{
	return m_offer_Operation_removeOfferedValues_EInt;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getOffer_Operation_removeWithdrawnTokens() const
{
	return m_offer_Operation_removeWithdrawnTokens;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getOffer_Operation_retrieveOfferedTokens() const
{
	return m_offer_Operation_retrieveOfferedTokens;
}

// End Class Offer

// Begin Class Token
std::shared_ptr<ecore::EClass> fUML::Semantics::Activities::ActivitiesPackageImpl::getToken_Class() const
{
	return m_token_Class;
}

std::shared_ptr<ecore::EAttribute> fUML::Semantics::Activities::ActivitiesPackageImpl::getToken_Attribute_withdrawn() const
{
	return m_token_Attribute_withdrawn;
}

std::shared_ptr<ecore::EReference> fUML::Semantics::Activities::ActivitiesPackageImpl::getToken_Attribute_holder() const
{
	return m_token_Attribute_holder;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getToken_Operation__copy() const
{
	return m_token_Operation__copy;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getToken_Operation_equals_Token() const
{
	return m_token_Operation_equals_Token;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getToken_Operation_getValue() const
{
	return m_token_Operation_getValue;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getToken_Operation_isControl() const
{
	return m_token_Operation_isControl;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getToken_Operation_transfer_ActivityNodeActivation() const
{
	return m_token_Operation_transfer_ActivityNodeActivation;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Activities::ActivitiesPackageImpl::getToken_Operation_withdraw() const
{
	return m_token_Operation_withdraw;
}

// End Class Token

// Begin Class TokenSet
std::shared_ptr<ecore::EClass> fUML::Semantics::Activities::ActivitiesPackageImpl::getTokenSet_Class() const
{
	return m_tokenSet_Class;
}


std::shared_ptr<ecore::EReference> fUML::Semantics::Activities::ActivitiesPackageImpl::getTokenSet_Attribute_tokens() const
{
	return m_tokenSet_Attribute_tokens;
}


// End Class TokenSet

