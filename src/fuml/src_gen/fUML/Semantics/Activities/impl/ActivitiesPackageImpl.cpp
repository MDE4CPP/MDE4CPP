#include "fUML/Semantics/Activities/impl/ActivitiesPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EReference.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EGenericType.hpp"

//metamodel factory
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::Activities;

//Singleton implementation 
std::shared_ptr<ActivitiesPackage> ActivitiesPackage::eInstance()
{
	static std::shared_ptr<ActivitiesPackage> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(ActivitiesPackageImpl::create());
		std::dynamic_pointer_cast<ActivitiesPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
//static initialisation
const std::string ActivitiesPackage::eNAME ="Activities";
const std::string ActivitiesPackage::eNS_URI ="http:///fUML_Semantics/Semantics/Activities.ecore";
const std::string ActivitiesPackage::eNS_PREFIX ="fUML_Semantics.Semantics.Activities";

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
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityEdgeInstance_Class() const
{
	return m_activityEdgeInstance_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityEdgeInstance_Attribute_edge() const
{
	return m_activityEdgeInstance_Attribute_edge;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityEdgeInstance_Attribute_group() const
{
	return m_activityEdgeInstance_Attribute_group;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityEdgeInstance_Attribute_offers() const
{
	return m_activityEdgeInstance_Attribute_offers;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityEdgeInstance_Attribute_source() const
{
	return m_activityEdgeInstance_Attribute_source;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityEdgeInstance_Attribute_target() const
{
	return m_activityEdgeInstance_Attribute_target;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityEdgeInstance_Operation_countOfferedValue() const
{
	return m_activityEdgeInstance_Operation_countOfferedValue;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityEdgeInstance_Operation_getOfferedTokens() const
{
	return m_activityEdgeInstance_Operation_getOfferedTokens;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityEdgeInstance_Operation_hasOffer() const
{
	return m_activityEdgeInstance_Operation_hasOffer;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityEdgeInstance_Operation_sendOffer_Token() const
{
	return m_activityEdgeInstance_Operation_sendOffer_Token;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityEdgeInstance_Operation_takeOfferedTokens() const
{
	return m_activityEdgeInstance_Operation_takeOfferedTokens;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityEdgeInstance_Operation_takeOfferedTokens_EInt() const
{
	return m_activityEdgeInstance_Operation_takeOfferedTokens_EInt;
}

// End Class ActivityEdgeInstance

// Begin Class ActivityExecution
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityExecution_Class() const
{
	return m_activityExecution_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityExecution_Attribute_activationGroup() const
{
	return m_activityExecution_Attribute_activationGroup;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityExecution_Attribute_activity() const
{
	return m_activityExecution_Attribute_activity;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityExecution_Operation__copy() const
{
	return m_activityExecution_Operation__copy;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityExecution_Operation_execute() const
{
	return m_activityExecution_Operation_execute;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityExecution_Operation_new_() const
{
	return m_activityExecution_Operation_new_;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityExecution_Operation_terminate() const
{
	return m_activityExecution_Operation_terminate;
}

// End Class ActivityExecution

// Begin Class ActivityFinalNodeActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityFinalNodeActivation_Class() const
{
	return m_activityFinalNodeActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityFinalNodeActivation_Operation_fire_Token() const
{
	return m_activityFinalNodeActivation_Operation_fire_Token;
}

// End Class ActivityFinalNodeActivation

// Begin Class ActivityNodeActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Class() const
{
	return m_activityNodeActivation_Class;
}

const std::shared_ptr<ecore::EAttribute>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Attribute_running() const
{
	return m_activityNodeActivation_Attribute_running;
}

const std::shared_ptr<ecore::EReference>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Attribute_group() const
{
	return m_activityNodeActivation_Attribute_group;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Attribute_heldTokens() const
{
	return m_activityNodeActivation_Attribute_heldTokens;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Attribute_incomingEdges() const
{
	return m_activityNodeActivation_Attribute_incomingEdges;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Attribute_node() const
{
	return m_activityNodeActivation_Attribute_node;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Attribute_outgoingEdges() const
{
	return m_activityNodeActivation_Attribute_outgoingEdges;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_addIncomingEdge_ActivityEdgeInstance() const
{
	return m_activityNodeActivation_Operation_addIncomingEdge_ActivityEdgeInstance;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_addOutgoingEdge_ActivityEdgeInstance() const
{
	return m_activityNodeActivation_Operation_addOutgoingEdge_ActivityEdgeInstance;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_addToken_Token() const
{
	return m_activityNodeActivation_Operation_addToken_Token;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_addTokens_Token() const
{
	return m_activityNodeActivation_Operation_addTokens_Token;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_clearTokens() const
{
	return m_activityNodeActivation_Operation_clearTokens;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_createEdgeInstances() const
{
	return m_activityNodeActivation_Operation_createEdgeInstances;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_createNodeActivations() const
{
	return m_activityNodeActivation_Operation_createNodeActivations;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_fire_Token() const
{
	return m_activityNodeActivation_Operation_fire_Token;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_getActivityExecution() const
{
	return m_activityNodeActivation_Operation_getActivityExecution;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_getExecutionContext() const
{
	return m_activityNodeActivation_Operation_getExecutionContext;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_getExecutionLocus() const
{
	return m_activityNodeActivation_Operation_getExecutionLocus;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_getNodeActivation_ActivityNode() const
{
	return m_activityNodeActivation_Operation_getNodeActivation_ActivityNode;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_getRunning() const
{
	return m_activityNodeActivation_Operation_getRunning;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_getTokens() const
{
	return m_activityNodeActivation_Operation_getTokens;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_isReady() const
{
	return m_activityNodeActivation_Operation_isReady;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance() const
{
	return m_activityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_receiveOffer() const
{
	return m_activityNodeActivation_Operation_receiveOffer;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_removeToken_Token() const
{
	return m_activityNodeActivation_Operation_removeToken_Token;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_resume() const
{
	return m_activityNodeActivation_Operation_resume;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_run() const
{
	return m_activityNodeActivation_Operation_run;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_sendOffers_Token() const
{
	return m_activityNodeActivation_Operation_sendOffers_Token;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_suspend() const
{
	return m_activityNodeActivation_Operation_suspend;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_takeOfferedTokens() const
{
	return m_activityNodeActivation_Operation_takeOfferedTokens;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_takeTokens() const
{
	return m_activityNodeActivation_Operation_takeTokens;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivation_Operation_terminate() const
{
	return m_activityNodeActivation_Operation_terminate;
}

// End Class ActivityNodeActivation

// Begin Class ActivityNodeActivationGroup
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Class() const
{
	return m_activityNodeActivationGroup_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Attribute_activityExecution() const
{
	return m_activityNodeActivationGroup_Attribute_activityExecution;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Attribute_containingNodeActivation() const
{
	return m_activityNodeActivationGroup_Attribute_containingNodeActivation;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Attribute_edgeInstances() const
{
	return m_activityNodeActivationGroup_Attribute_edgeInstances;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Attribute_nodeActivations() const
{
	return m_activityNodeActivationGroup_Attribute_nodeActivations;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Attribute_suspendedActivations() const
{
	return m_activityNodeActivationGroup_Attribute_suspendedActivations;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Operation_activate_ActivityNode_ActivityEdge() const
{
	return m_activityNodeActivationGroup_Operation_activate_ActivityNode_ActivityEdge;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Operation_addEdgeInstance_ActivityEdgeInstance() const
{
	return m_activityNodeActivationGroup_Operation_addEdgeInstance_ActivityEdgeInstance;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Operation_addNodeActivation_ActivityNodeActivation() const
{
	return m_activityNodeActivationGroup_Operation_addNodeActivation_ActivityNodeActivation;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Operation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation() const
{
	return m_activityNodeActivationGroup_Operation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Operation_createEdgeInstance_ActivityEdge() const
{
	return m_activityNodeActivationGroup_Operation_createEdgeInstance_ActivityEdge;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Operation_createNodeActivation_ActivityNode() const
{
	return m_activityNodeActivationGroup_Operation_createNodeActivation_ActivityNode;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Operation_createNodeActivations_ActivityNode() const
{
	return m_activityNodeActivationGroup_Operation_createNodeActivations_ActivityNode;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Operation_getNodeActivation_ActivityNode() const
{
	return m_activityNodeActivationGroup_Operation_getNodeActivation_ActivityNode;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Operation_getOutputParameterNodeActivations() const
{
	return m_activityNodeActivationGroup_Operation_getOutputParameterNodeActivations;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Operation_hasSourceFor_ActivityEdgeInstance() const
{
	return m_activityNodeActivationGroup_Operation_hasSourceFor_ActivityEdgeInstance;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Operation_isSuspended() const
{
	return m_activityNodeActivationGroup_Operation_isSuspended;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Operation_resume_ActivityNodeActivation() const
{
	return m_activityNodeActivationGroup_Operation_resume_ActivityNodeActivation;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Operation_retrieveActivityExecution() const
{
	return m_activityNodeActivationGroup_Operation_retrieveActivityExecution;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Operation_run_ActivityNodeActivation() const
{
	return m_activityNodeActivationGroup_Operation_run_ActivityNodeActivation;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Operation_runNodes_ActivityNode() const
{
	return m_activityNodeActivationGroup_Operation_runNodes_ActivityNode;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Operation_suspend_ActivityNodeActivation() const
{
	return m_activityNodeActivationGroup_Operation_suspend_ActivityNodeActivation;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityNodeActivationGroup_Operation_terminateAll() const
{
	return m_activityNodeActivationGroup_Operation_terminateAll;
}

// End Class ActivityNodeActivationGroup

// Begin Class ActivityParameterNodeActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityParameterNodeActivation_Class() const
{
	return m_activityParameterNodeActivation_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityParameterNodeActivation_Attribute_activityParameterNode() const
{
	return m_activityParameterNodeActivation_Attribute_activityParameterNode;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityParameterNodeActivation_Operation_clearTokens() const
{
	return m_activityParameterNodeActivation_Operation_clearTokens;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getActivityParameterNodeActivation_Operation_fire_Token() const
{
	return m_activityParameterNodeActivation_Operation_fire_Token;
}

// End Class ActivityParameterNodeActivation

// Begin Class CentralBufferNodeActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Activities::ActivitiesPackageImpl::getCentralBufferNodeActivation_Class() const
{
	return m_centralBufferNodeActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getCentralBufferNodeActivation_Operation_fire_Token() const
{
	return m_centralBufferNodeActivation_Operation_fire_Token;
}

// End Class CentralBufferNodeActivation

// Begin Class ControlNodeActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Activities::ActivitiesPackageImpl::getControlNodeActivation_Class() const
{
	return m_controlNodeActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getControlNodeActivation_Operation_fire_Token() const
{
	return m_controlNodeActivation_Operation_fire_Token;
}

// End Class ControlNodeActivation

// Begin Class ControlToken
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Activities::ActivitiesPackageImpl::getControlToken_Class() const
{
	return m_controlToken_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getControlToken_Operation__copy() const
{
	return m_controlToken_Operation__copy;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getControlToken_Operation_equals_Token() const
{
	return m_controlToken_Operation_equals_Token;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getControlToken_Operation_isControl() const
{
	return m_controlToken_Operation_isControl;
}

// End Class ControlToken

// Begin Class DataStoreNodeActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Activities::ActivitiesPackageImpl::getDataStoreNodeActivation_Class() const
{
	return m_dataStoreNodeActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getDataStoreNodeActivation_Operation_addToken_Token() const
{
	return m_dataStoreNodeActivation_Operation_addToken_Token;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getDataStoreNodeActivation_Operation_removeToken_Token() const
{
	return m_dataStoreNodeActivation_Operation_removeToken_Token;
}

// End Class DataStoreNodeActivation

// Begin Class DecisionNodeActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Activities::ActivitiesPackageImpl::getDecisionNodeActivation_Class() const
{
	return m_decisionNodeActivation_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Activities::ActivitiesPackageImpl::getDecisionNodeActivation_Attribute_decisionNode() const
{
	return m_decisionNodeActivation_Attribute_decisionNode;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getDecisionNodeActivation_Operation_executeDecisionInputBehavior_EJavaObject_EJavaObject() const
{
	return m_decisionNodeActivation_Operation_executeDecisionInputBehavior_EJavaObject_EJavaObject;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getDecisionNodeActivation_Operation_fire_Token() const
{
	return m_decisionNodeActivation_Operation_fire_Token;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getDecisionNodeActivation_Operation_getDecisionInputFlowInstance() const
{
	return m_decisionNodeActivation_Operation_getDecisionInputFlowInstance;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getDecisionNodeActivation_Operation_getDecisionInputFlowValue() const
{
	return m_decisionNodeActivation_Operation_getDecisionInputFlowValue;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getDecisionNodeActivation_Operation_getDecisionValues_Token() const
{
	return m_decisionNodeActivation_Operation_getDecisionValues_Token;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getDecisionNodeActivation_Operation_hasObjectFlowInput() const
{
	return m_decisionNodeActivation_Operation_hasObjectFlowInput;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getDecisionNodeActivation_Operation_isReady() const
{
	return m_decisionNodeActivation_Operation_isReady;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getDecisionNodeActivation_Operation_removeJoinedControlTokens_Token() const
{
	return m_decisionNodeActivation_Operation_removeJoinedControlTokens_Token;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getDecisionNodeActivation_Operation_takeOfferedTokens() const
{
	return m_decisionNodeActivation_Operation_takeOfferedTokens;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getDecisionNodeActivation_Operation_test_ValueSpecification_EJavaObject() const
{
	return m_decisionNodeActivation_Operation_test_ValueSpecification_EJavaObject;
}

// End Class DecisionNodeActivation

// Begin Class FlowFinalNodeActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Activities::ActivitiesPackageImpl::getFlowFinalNodeActivation_Class() const
{
	return m_flowFinalNodeActivation_Class;
}




// End Class FlowFinalNodeActivation

// Begin Class ForkNodeActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Activities::ActivitiesPackageImpl::getForkNodeActivation_Class() const
{
	return m_forkNodeActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getForkNodeActivation_Operation_fire_Token() const
{
	return m_forkNodeActivation_Operation_fire_Token;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getForkNodeActivation_Operation_terminate() const
{
	return m_forkNodeActivation_Operation_terminate;
}

// End Class ForkNodeActivation

// Begin Class ForkedToken
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Activities::ActivitiesPackageImpl::getForkedToken_Class() const
{
	return m_forkedToken_Class;
}

const std::shared_ptr<ecore::EAttribute>& fUML::Semantics::Activities::ActivitiesPackageImpl::getForkedToken_Attribute_baseTokenIsWithdrawn() const
{
	return m_forkedToken_Attribute_baseTokenIsWithdrawn;
}
const std::shared_ptr<ecore::EAttribute>& fUML::Semantics::Activities::ActivitiesPackageImpl::getForkedToken_Attribute_remainingOffersCount() const
{
	return m_forkedToken_Attribute_remainingOffersCount;
}

const std::shared_ptr<ecore::EReference>& fUML::Semantics::Activities::ActivitiesPackageImpl::getForkedToken_Attribute_baseToken() const
{
	return m_forkedToken_Attribute_baseToken;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getForkedToken_Operation__copy() const
{
	return m_forkedToken_Operation__copy;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getForkedToken_Operation_equals_Token() const
{
	return m_forkedToken_Operation_equals_Token;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getForkedToken_Operation_getValue() const
{
	return m_forkedToken_Operation_getValue;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getForkedToken_Operation_isControl() const
{
	return m_forkedToken_Operation_isControl;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getForkedToken_Operation_withdraw() const
{
	return m_forkedToken_Operation_withdraw;
}

// End Class ForkedToken

// Begin Class InitialNodeActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Activities::ActivitiesPackageImpl::getInitialNodeActivation_Class() const
{
	return m_initialNodeActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getInitialNodeActivation_Operation_fire_Token() const
{
	return m_initialNodeActivation_Operation_fire_Token;
}

// End Class InitialNodeActivation

// Begin Class JoinNodeActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Activities::ActivitiesPackageImpl::getJoinNodeActivation_Class() const
{
	return m_joinNodeActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getJoinNodeActivation_Operation_fire_Token() const
{
	return m_joinNodeActivation_Operation_fire_Token;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getJoinNodeActivation_Operation_isReady() const
{
	return m_joinNodeActivation_Operation_isReady;
}

// End Class JoinNodeActivation

// Begin Class MergeNodeActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Activities::ActivitiesPackageImpl::getMergeNodeActivation_Class() const
{
	return m_mergeNodeActivation_Class;
}




// End Class MergeNodeActivation

// Begin Class ObjectNodeActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectNodeActivation_Class() const
{
	return m_objectNodeActivation_Class;
}

const std::shared_ptr<ecore::EAttribute>& fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectNodeActivation_Attribute_offeredTokenCount() const
{
	return m_objectNodeActivation_Attribute_offeredTokenCount;
}


const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectNodeActivation_Operation_addToken_Token() const
{
	return m_objectNodeActivation_Operation_addToken_Token;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectNodeActivation_Operation_clearTokens() const
{
	return m_objectNodeActivation_Operation_clearTokens;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectNodeActivation_Operation_countOfferedValues() const
{
	return m_objectNodeActivation_Operation_countOfferedValues;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectNodeActivation_Operation_countUnofferedTokens() const
{
	return m_objectNodeActivation_Operation_countUnofferedTokens;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectNodeActivation_Operation_getUnofferedTokens() const
{
	return m_objectNodeActivation_Operation_getUnofferedTokens;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectNodeActivation_Operation_removeToken_Token() const
{
	return m_objectNodeActivation_Operation_removeToken_Token;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectNodeActivation_Operation_run() const
{
	return m_objectNodeActivation_Operation_run;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectNodeActivation_Operation_sendOffers_Token() const
{
	return m_objectNodeActivation_Operation_sendOffers_Token;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectNodeActivation_Operation_sendUnofferedTokens() const
{
	return m_objectNodeActivation_Operation_sendUnofferedTokens;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectNodeActivation_Operation_takeUnofferedTokens() const
{
	return m_objectNodeActivation_Operation_takeUnofferedTokens;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectNodeActivation_Operation_terminate() const
{
	return m_objectNodeActivation_Operation_terminate;
}

// End Class ObjectNodeActivation

// Begin Class ObjectToken
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectToken_Class() const
{
	return m_objectToken_Class;
}

const std::shared_ptr<ecore::EAttribute>& fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectToken_Attribute_value() const
{
	return m_objectToken_Attribute_value;
}


const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectToken_Operation__copy() const
{
	return m_objectToken_Operation__copy;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectToken_Operation_equals_Token() const
{
	return m_objectToken_Operation_equals_Token;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getObjectToken_Operation_isControl() const
{
	return m_objectToken_Operation_isControl;
}

// End Class ObjectToken

// Begin Class Offer
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Activities::ActivitiesPackageImpl::getOffer_Class() const
{
	return m_offer_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Activities::ActivitiesPackageImpl::getOffer_Attribute_offeredTokens() const
{
	return m_offer_Attribute_offeredTokens;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getOffer_Operation_countOfferedValues() const
{
	return m_offer_Operation_countOfferedValues;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getOffer_Operation_hasTokens() const
{
	return m_offer_Operation_hasTokens;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getOffer_Operation_removeOfferedValues_EInt() const
{
	return m_offer_Operation_removeOfferedValues_EInt;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getOffer_Operation_removeWithdrawnTokens() const
{
	return m_offer_Operation_removeWithdrawnTokens;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getOffer_Operation_retrieveOfferedTokens() const
{
	return m_offer_Operation_retrieveOfferedTokens;
}

// End Class Offer

// Begin Class Token
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Activities::ActivitiesPackageImpl::getToken_Class() const
{
	return m_token_Class;
}

const std::shared_ptr<ecore::EAttribute>& fUML::Semantics::Activities::ActivitiesPackageImpl::getToken_Attribute_withdrawn() const
{
	return m_token_Attribute_withdrawn;
}

const std::shared_ptr<ecore::EReference>& fUML::Semantics::Activities::ActivitiesPackageImpl::getToken_Attribute_holder() const
{
	return m_token_Attribute_holder;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getToken_Operation__copy() const
{
	return m_token_Operation__copy;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getToken_Operation_equals_Token() const
{
	return m_token_Operation_equals_Token;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getToken_Operation_getValue() const
{
	return m_token_Operation_getValue;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getToken_Operation_isControl() const
{
	return m_token_Operation_isControl;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getToken_Operation_transfer_ActivityNodeActivation() const
{
	return m_token_Operation_transfer_ActivityNodeActivation;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Activities::ActivitiesPackageImpl::getToken_Operation_withdraw() const
{
	return m_token_Operation_withdraw;
}

// End Class Token

// Begin Class TokenSet
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Activities::ActivitiesPackageImpl::getTokenSet_Class() const
{
	return m_tokenSet_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Activities::ActivitiesPackageImpl::getTokenSet_Attribute_tokens() const
{
	return m_tokenSet_Attribute_tokens;
}


// End Class TokenSet

