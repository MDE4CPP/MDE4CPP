//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIESPACKAGE_HPP
#define FUML_SEMANTICS_ACTIVITIESPACKAGE_HPP

// namespace macro header include
#include "fUML/fUML.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EParameter;
	class EDataType;
	class EStringToStringMapEntry;
	class EGenericType;
	class EReference;
	class EOperation;
	class EAttribute;
	class EAnnotation;
	class EClass;
}

namespace fUML::Semantics::Activities 
{
	class ActivityEdgeInstance;
	class ActivityExecution;
	class ActivityFinalNodeActivation;
	class ActivityNodeActivation;
	class ActivityNodeActivationGroup;
	class ActivityParameterNodeActivation;
	class CentralBufferNodeActivation;
	class ControlNodeActivation;
	class ControlToken;
	class DataStoreNodeActivation;
	class DecisionNodeActivation;
	class FlowFinalNodeActivation;
	class ForkNodeActivation;
	class ForkedToken;
	class InitialNodeActivation;
	class JoinNodeActivation;
	class MergeNodeActivation;
	class ObjectNodeActivation;
	class ObjectToken;
	class Offer;
	class Token;
	class TokenSet;
}
 
namespace fUML::Semantics::Activities 
{
	/*!
	The Metamodel Package for the Activities metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class FUML_API ActivitiesPackage : virtual public ecore::EPackage 
	{
		private:    
			ActivitiesPackage(ActivitiesPackage const&) = delete;
			ActivitiesPackage& operator=(ActivitiesPackage const&) = delete;

		protected:
			ActivitiesPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			// Begin Class ActivityEdgeInstance
			//Class and Feature IDs 
			static const unsigned long ACTIVITYEDGEINSTANCE_CLASS = 203010502;
			static const unsigned int ACTIVITYEDGEINSTANCE_CLASS_FEATURE_COUNT = 5;
			static const unsigned int ACTIVITYEDGEINSTANCE_CLASS_OPERATION_COUNT = 6;
			
			static const unsigned long ACTIVITYEDGEINSTANCE_ATTRIBUTE_EDGE = 637048440;
			static const unsigned long ACTIVITYEDGEINSTANCE_ATTRIBUTE_GROUP = 436524052;
			static const unsigned long ACTIVITYEDGEINSTANCE_ATTRIBUTE_OFFERS = 472653455;
			static const unsigned long ACTIVITYEDGEINSTANCE_ATTRIBUTE_SOURCE = 1109285379;
			static const unsigned long ACTIVITYEDGEINSTANCE_ATTRIBUTE_TARGET = 1425032255;
			
			static const unsigned long ACTIVITYEDGEINSTANCE_OPERATION_COUNTOFFEREDVALUE = 3512353870;
			static const unsigned long ACTIVITYEDGEINSTANCE_OPERATION_GETOFFEREDTOKENS = 247253392;
			static const unsigned long ACTIVITYEDGEINSTANCE_OPERATION_HASOFFER = 2669398996;
			static const unsigned long ACTIVITYEDGEINSTANCE_OPERATION_SENDOFFER_TOKEN = 2265631071;
			static const unsigned long ACTIVITYEDGEINSTANCE_OPERATION_TAKEOFFEREDTOKENS = 3785400521;
			static const unsigned long ACTIVITYEDGEINSTANCE_OPERATION_TAKEOFFEREDTOKENS_EINT = 1787668928;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getActivityEdgeInstance_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getActivityEdgeInstance_Attribute_edge() const = 0;
			virtual std::shared_ptr<ecore::EReference> getActivityEdgeInstance_Attribute_group() const = 0;
			virtual std::shared_ptr<ecore::EReference> getActivityEdgeInstance_Attribute_offers() const = 0;
			virtual std::shared_ptr<ecore::EReference> getActivityEdgeInstance_Attribute_source() const = 0;
			virtual std::shared_ptr<ecore::EReference> getActivityEdgeInstance_Attribute_target() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getActivityEdgeInstance_Operation_countOfferedValue() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityEdgeInstance_Operation_getOfferedTokens() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityEdgeInstance_Operation_hasOffer() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityEdgeInstance_Operation_sendOffer_Token() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityEdgeInstance_Operation_takeOfferedTokens() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityEdgeInstance_Operation_takeOfferedTokens_EInt() const = 0;
			
			// End Class ActivityEdgeInstance


			// Begin Class ActivityExecution
			//Class and Feature IDs 
			static const unsigned long ACTIVITYEXECUTION_CLASS = 750496334;
			static const unsigned int ACTIVITYEXECUTION_CLASS_FEATURE_COUNT = 11;
			static const unsigned int ACTIVITYEXECUTION_CLASS_OPERATION_COUNT = 51;
			
			static const unsigned long ACTIVITYEXECUTION_ATTRIBUTE_ACTIVATIONGROUP = 11280750;
			static const unsigned long ACTIVITYEXECUTION_ATTRIBUTE_ACTIVITY = 1195953016;
			
			static const unsigned long ACTIVITYEXECUTION_OPERATION__COPY = 2018352062;
			static const unsigned long ACTIVITYEXECUTION_OPERATION_EXECUTE = 2440252333;
			static const unsigned long ACTIVITYEXECUTION_OPERATION_NEW_ = 357511021;
			static const unsigned long ACTIVITYEXECUTION_OPERATION_TERMINATE = 1105822471;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getActivityExecution_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getActivityExecution_Attribute_activationGroup() const = 0;
			virtual std::shared_ptr<ecore::EReference> getActivityExecution_Attribute_activity() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getActivityExecution_Operation__copy() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityExecution_Operation_execute() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityExecution_Operation_new_() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityExecution_Operation_terminate() const = 0;
			
			// End Class ActivityExecution


			// Begin Class ActivityFinalNodeActivation
			//Class and Feature IDs 
			static const unsigned long ACTIVITYFINALNODEACTIVATION_CLASS = 1133474033;
			static const unsigned int ACTIVITYFINALNODEACTIVATION_CLASS_FEATURE_COUNT = 6;
			static const unsigned int ACTIVITYFINALNODEACTIVATION_CLASS_OPERATION_COUNT = 29;
			
			
			static const unsigned long ACTIVITYFINALNODEACTIVATION_OPERATION_FIRE_TOKEN = 3991177345;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getActivityFinalNodeActivation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getActivityFinalNodeActivation_Operation_fire_Token() const = 0;
			
			// End Class ActivityFinalNodeActivation


			// Begin Class ActivityNodeActivation
			//Class and Feature IDs 
			static const unsigned long ACTIVITYNODEACTIVATION_CLASS = 646106009;
			static const unsigned int ACTIVITYNODEACTIVATION_CLASS_FEATURE_COUNT = 6;
			static const unsigned int ACTIVITYNODEACTIVATION_CLASS_OPERATION_COUNT = 27;
			static const unsigned long ACTIVITYNODEACTIVATION_ATTRIBUTE_RUNNING = 1304818101;
			
			static const unsigned long ACTIVITYNODEACTIVATION_ATTRIBUTE_GROUP = 1603155624;
			static const unsigned long ACTIVITYNODEACTIVATION_ATTRIBUTE_HELDTOKENS = 151258436;
			static const unsigned long ACTIVITYNODEACTIVATION_ATTRIBUTE_INCOMINGEDGES = 739450042;
			static const unsigned long ACTIVITYNODEACTIVATION_ATTRIBUTE_NODE = 1710961840;
			static const unsigned long ACTIVITYNODEACTIVATION_ATTRIBUTE_OUTGOINGEDGES = 1556272480;
			
			static const unsigned long ACTIVITYNODEACTIVATION_OPERATION_ADDINCOMINGEDGE_ACTIVITYEDGEINSTANCE = 2329513027;
			static const unsigned long ACTIVITYNODEACTIVATION_OPERATION_ADDOUTGOINGEDGE_ACTIVITYEDGEINSTANCE = 3040559551;
			static const unsigned long ACTIVITYNODEACTIVATION_OPERATION_ADDTOKEN_TOKEN = 1438112633;
			static const unsigned long ACTIVITYNODEACTIVATION_OPERATION_ADDTOKENS_TOKEN = 1994943910;
			static const unsigned long ACTIVITYNODEACTIVATION_OPERATION_CLEARTOKENS = 305402021;
			static const unsigned long ACTIVITYNODEACTIVATION_OPERATION_CREATEEDGEINSTANCES = 2189392667;
			static const unsigned long ACTIVITYNODEACTIVATION_OPERATION_CREATENODEACTIVATIONS = 1346898969;
			static const unsigned long ACTIVITYNODEACTIVATION_OPERATION_FIRE_TOKEN = 3892530199;
			static const unsigned long ACTIVITYNODEACTIVATION_OPERATION_GETACTIVITYEXECUTION = 415943298;
			static const unsigned long ACTIVITYNODEACTIVATION_OPERATION_GETEXECUTIONCONTEXT = 3574975649;
			static const unsigned long ACTIVITYNODEACTIVATION_OPERATION_GETEXECUTIONLOCUS = 4097970094;
			static const unsigned long ACTIVITYNODEACTIVATION_OPERATION_GETNODEACTIVATION_ACTIVITYNODE = 4201354494;
			static const unsigned long ACTIVITYNODEACTIVATION_OPERATION_GETRUNNING = 254630437;
			static const unsigned long ACTIVITYNODEACTIVATION_OPERATION_GETTOKENS = 3137100059;
			static const unsigned long ACTIVITYNODEACTIVATION_OPERATION_ISREADY = 2594491909;
			static const unsigned long ACTIVITYNODEACTIVATION_OPERATION_ISSOURCEFOR_ACTIVITYEDGEINSTANCE = 2410514251;
			static const unsigned long ACTIVITYNODEACTIVATION_OPERATION_RECEIVEOFFER = 4022154831;
			static const unsigned long ACTIVITYNODEACTIVATION_OPERATION_REMOVETOKEN_TOKEN = 2530926611;
			static const unsigned long ACTIVITYNODEACTIVATION_OPERATION_RESUME = 1522436987;
			static const unsigned long ACTIVITYNODEACTIVATION_OPERATION_RUN = 3682367227;
			static const unsigned long ACTIVITYNODEACTIVATION_OPERATION_SENDOFFERS_TOKEN = 3528690584;
			static const unsigned long ACTIVITYNODEACTIVATION_OPERATION_SUSPEND = 1833763532;
			static const unsigned long ACTIVITYNODEACTIVATION_OPERATION_TAKEOFFEREDTOKENS = 4181507751;
			static const unsigned long ACTIVITYNODEACTIVATION_OPERATION_TAKETOKENS = 1423548432;
			static const unsigned long ACTIVITYNODEACTIVATION_OPERATION_TERMINATE = 1536647187;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getActivityNodeActivation_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getActivityNodeActivation_Attribute_running() const = 0;
			
			virtual std::shared_ptr<ecore::EReference> getActivityNodeActivation_Attribute_group() const = 0;
			virtual std::shared_ptr<ecore::EReference> getActivityNodeActivation_Attribute_heldTokens() const = 0;
			virtual std::shared_ptr<ecore::EReference> getActivityNodeActivation_Attribute_incomingEdges() const = 0;
			virtual std::shared_ptr<ecore::EReference> getActivityNodeActivation_Attribute_node() const = 0;
			virtual std::shared_ptr<ecore::EReference> getActivityNodeActivation_Attribute_outgoingEdges() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivation_Operation_addIncomingEdge_ActivityEdgeInstance() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivation_Operation_addOutgoingEdge_ActivityEdgeInstance() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivation_Operation_addToken_Token() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivation_Operation_addTokens_Token() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivation_Operation_clearTokens() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivation_Operation_createEdgeInstances() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivation_Operation_createNodeActivations() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivation_Operation_fire_Token() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivation_Operation_getActivityExecution() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivation_Operation_getExecutionContext() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivation_Operation_getExecutionLocus() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivation_Operation_getNodeActivation_ActivityNode() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivation_Operation_getRunning() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivation_Operation_getTokens() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivation_Operation_isReady() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivation_Operation_receiveOffer() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivation_Operation_removeToken_Token() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivation_Operation_resume() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivation_Operation_run() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivation_Operation_sendOffers_Token() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivation_Operation_suspend() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivation_Operation_takeOfferedTokens() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivation_Operation_takeTokens() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivation_Operation_terminate() const = 0;
			
			// End Class ActivityNodeActivation


			// Begin Class ActivityNodeActivationGroup
			//Class and Feature IDs 
			static const unsigned long ACTIVITYNODEACTIVATIONGROUP_CLASS = 447489606;
			static const unsigned int ACTIVITYNODEACTIVATIONGROUP_CLASS_FEATURE_COUNT = 5;
			static const unsigned int ACTIVITYNODEACTIVATIONGROUP_CLASS_OPERATION_COUNT = 17;
			
			static const unsigned long ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_ACTIVITYEXECUTION = 643167494;
			static const unsigned long ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_CONTAININGNODEACTIVATION = 441933508;
			static const unsigned long ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_EDGEINSTANCES = 1462566797;
			static const unsigned long ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_NODEACTIVATIONS = 312223170;
			static const unsigned long ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_SUSPENDEDACTIVATIONS = 652260595;
			
			static const unsigned long ACTIVITYNODEACTIVATIONGROUP_OPERATION_ACTIVATE_ACTIVITYNODE_ACTIVITYEDGE = 1424879345;
			static const unsigned long ACTIVITYNODEACTIVATIONGROUP_OPERATION_ADDEDGEINSTANCE_ACTIVITYEDGEINSTANCE = 3481165333;
			static const unsigned long ACTIVITYNODEACTIVATIONGROUP_OPERATION_ADDNODEACTIVATION_ACTIVITYNODEACTIVATION = 1678168073;
			static const unsigned long ACTIVITYNODEACTIVATIONGROUP_OPERATION_CHECKINCOMINGEDGES_ACTIVITYEDGEINSTANCE_ACTIVITYNODEACTIVATION = 2941723279;
			static const unsigned long ACTIVITYNODEACTIVATIONGROUP_OPERATION_CREATEEDGEINSTANCE_ACTIVITYEDGE = 553340279;
			static const unsigned long ACTIVITYNODEACTIVATIONGROUP_OPERATION_CREATENODEACTIVATION_ACTIVITYNODE = 221360211;
			static const unsigned long ACTIVITYNODEACTIVATIONGROUP_OPERATION_CREATENODEACTIVATIONS_ACTIVITYNODE = 3543208085;
			static const unsigned long ACTIVITYNODEACTIVATIONGROUP_OPERATION_GETNODEACTIVATION_ACTIVITYNODE = 4739911;
			static const unsigned long ACTIVITYNODEACTIVATIONGROUP_OPERATION_GETOUTPUTPARAMETERNODEACTIVATIONS = 2536177538;
			static const unsigned long ACTIVITYNODEACTIVATIONGROUP_OPERATION_HASSOURCEFOR_ACTIVITYEDGEINSTANCE = 2460897072;
			static const unsigned long ACTIVITYNODEACTIVATIONGROUP_OPERATION_ISSUSPENDED = 1715228724;
			static const unsigned long ACTIVITYNODEACTIVATIONGROUP_OPERATION_RESUME_ACTIVITYNODEACTIVATION = 3637760725;
			static const unsigned long ACTIVITYNODEACTIVATIONGROUP_OPERATION_RETRIEVEACTIVITYEXECUTION = 1009503597;
			static const unsigned long ACTIVITYNODEACTIVATIONGROUP_OPERATION_RUN_ACTIVITYNODEACTIVATION = 3898662735;
			static const unsigned long ACTIVITYNODEACTIVATIONGROUP_OPERATION_RUNNODES_ACTIVITYNODE = 485740428;
			static const unsigned long ACTIVITYNODEACTIVATIONGROUP_OPERATION_SUSPEND_ACTIVITYNODEACTIVATION = 1485995758;
			static const unsigned long ACTIVITYNODEACTIVATIONGROUP_OPERATION_TERMINATEALL = 2675640689;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getActivityNodeActivationGroup_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getActivityNodeActivationGroup_Attribute_activityExecution() const = 0;
			virtual std::shared_ptr<ecore::EReference> getActivityNodeActivationGroup_Attribute_containingNodeActivation() const = 0;
			virtual std::shared_ptr<ecore::EReference> getActivityNodeActivationGroup_Attribute_edgeInstances() const = 0;
			virtual std::shared_ptr<ecore::EReference> getActivityNodeActivationGroup_Attribute_nodeActivations() const = 0;
			virtual std::shared_ptr<ecore::EReference> getActivityNodeActivationGroup_Attribute_suspendedActivations() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivationGroup_Operation_activate_ActivityNode_ActivityEdge() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivationGroup_Operation_addEdgeInstance_ActivityEdgeInstance() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivationGroup_Operation_addNodeActivation_ActivityNodeActivation() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivationGroup_Operation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivationGroup_Operation_createEdgeInstance_ActivityEdge() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivationGroup_Operation_createNodeActivation_ActivityNode() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivationGroup_Operation_createNodeActivations_ActivityNode() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivationGroup_Operation_getNodeActivation_ActivityNode() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivationGroup_Operation_getOutputParameterNodeActivations() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivationGroup_Operation_hasSourceFor_ActivityEdgeInstance() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivationGroup_Operation_isSuspended() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivationGroup_Operation_resume_ActivityNodeActivation() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivationGroup_Operation_retrieveActivityExecution() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivationGroup_Operation_run_ActivityNodeActivation() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivationGroup_Operation_runNodes_ActivityNode() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivationGroup_Operation_suspend_ActivityNodeActivation() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityNodeActivationGroup_Operation_terminateAll() const = 0;
			
			// End Class ActivityNodeActivationGroup


			// Begin Class ActivityParameterNodeActivation
			//Class and Feature IDs 
			static const unsigned long ACTIVITYPARAMETERNODEACTIVATION_CLASS = 1310518118;
			static const unsigned int ACTIVITYPARAMETERNODEACTIVATION_CLASS_FEATURE_COUNT = 7;
			static const unsigned int ACTIVITYPARAMETERNODEACTIVATION_CLASS_OPERATION_COUNT = 40;
			
			
			static const unsigned long ACTIVITYPARAMETERNODEACTIVATION_OPERATION_CLEARTOKENS = 779512874;
			static const unsigned long ACTIVITYPARAMETERNODEACTIVATION_OPERATION_FIRE_TOKEN = 1225512580;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getActivityParameterNodeActivation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getActivityParameterNodeActivation_Operation_clearTokens() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActivityParameterNodeActivation_Operation_fire_Token() const = 0;
			
			// End Class ActivityParameterNodeActivation


			// Begin Class CentralBufferNodeActivation
			//Class and Feature IDs 
			static const unsigned long CENTRALBUFFERNODEACTIVATION_CLASS = 2083734229;
			static const unsigned int CENTRALBUFFERNODEACTIVATION_CLASS_FEATURE_COUNT = 7;
			static const unsigned int CENTRALBUFFERNODEACTIVATION_CLASS_OPERATION_COUNT = 39;
			
			
			static const unsigned long CENTRALBUFFERNODEACTIVATION_OPERATION_FIRE_TOKEN = 3196789593;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCentralBufferNodeActivation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCentralBufferNodeActivation_Operation_fire_Token() const = 0;
			
			// End Class CentralBufferNodeActivation


			// Begin Class ControlNodeActivation
			//Class and Feature IDs 
			static const unsigned long CONTROLNODEACTIVATION_CLASS = 1062574970;
			static const unsigned int CONTROLNODEACTIVATION_CLASS_FEATURE_COUNT = 6;
			static const unsigned int CONTROLNODEACTIVATION_CLASS_OPERATION_COUNT = 28;
			
			
			static const unsigned long CONTROLNODEACTIVATION_OPERATION_FIRE_TOKEN = 1708232627;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getControlNodeActivation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getControlNodeActivation_Operation_fire_Token() const = 0;
			
			// End Class ControlNodeActivation


			// Begin Class ControlToken
			//Class and Feature IDs 
			static const unsigned long CONTROLTOKEN_CLASS = 897770333;
			static const unsigned int CONTROLTOKEN_CLASS_FEATURE_COUNT = 2;
			static const unsigned int CONTROLTOKEN_CLASS_OPERATION_COUNT = 9;
			
			
			static const unsigned long CONTROLTOKEN_OPERATION__COPY = 4065084616;
			static const unsigned long CONTROLTOKEN_OPERATION_EQUALS_TOKEN = 338981101;
			static const unsigned long CONTROLTOKEN_OPERATION_ISCONTROL = 972980650;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getControlToken_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getControlToken_Operation__copy() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getControlToken_Operation_equals_Token() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getControlToken_Operation_isControl() const = 0;
			
			// End Class ControlToken


			// Begin Class DataStoreNodeActivation
			//Class and Feature IDs 
			static const unsigned long DATASTORENODEACTIVATION_CLASS = 602540034;
			static const unsigned int DATASTORENODEACTIVATION_CLASS_FEATURE_COUNT = 7;
			static const unsigned int DATASTORENODEACTIVATION_CLASS_OPERATION_COUNT = 41;
			
			
			static const unsigned long DATASTORENODEACTIVATION_OPERATION_ADDTOKEN_TOKEN = 2150799315;
			static const unsigned long DATASTORENODEACTIVATION_OPERATION_REMOVETOKEN_TOKEN = 4235365301;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getDataStoreNodeActivation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getDataStoreNodeActivation_Operation_addToken_Token() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getDataStoreNodeActivation_Operation_removeToken_Token() const = 0;
			
			// End Class DataStoreNodeActivation


			// Begin Class DecisionNodeActivation
			//Class and Feature IDs 
			static const unsigned long DECISIONNODEACTIVATION_CLASS = 52454155;
			static const unsigned int DECISIONNODEACTIVATION_CLASS_FEATURE_COUNT = 7;
			static const unsigned int DECISIONNODEACTIVATION_CLASS_OPERATION_COUNT = 38;
			
			static const unsigned long DECISIONNODEACTIVATION_ATTRIBUTE_DECISIONNODE = 1894640136;
			
			static const unsigned long DECISIONNODEACTIVATION_OPERATION_EXECUTEDECISIONINPUTBEHAVIOR_EJAVAOBJECT_EJAVAOBJECT = 3052258302;
			static const unsigned long DECISIONNODEACTIVATION_OPERATION_FIRE_TOKEN = 4127070096;
			static const unsigned long DECISIONNODEACTIVATION_OPERATION_GETDECISIONINPUTFLOWINSTANCE = 589400247;
			static const unsigned long DECISIONNODEACTIVATION_OPERATION_GETDECISIONINPUTFLOWVALUE = 1399588784;
			static const unsigned long DECISIONNODEACTIVATION_OPERATION_GETDECISIONVALUES_TOKEN = 2333144120;
			static const unsigned long DECISIONNODEACTIVATION_OPERATION_HASOBJECTFLOWINPUT = 336094904;
			static const unsigned long DECISIONNODEACTIVATION_OPERATION_ISREADY = 2829031806;
			static const unsigned long DECISIONNODEACTIVATION_OPERATION_REMOVEJOINEDCONTROLTOKENS_TOKEN = 1559509247;
			static const unsigned long DECISIONNODEACTIVATION_OPERATION_TAKEOFFEREDTOKENS = 121080352;
			static const unsigned long DECISIONNODEACTIVATION_OPERATION_TEST_VALUESPECIFICATION_EJAVAOBJECT = 2379610281;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getDecisionNodeActivation_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getDecisionNodeActivation_Attribute_decisionNode() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getDecisionNodeActivation_Operation_executeDecisionInputBehavior_EJavaObject_EJavaObject() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getDecisionNodeActivation_Operation_fire_Token() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getDecisionNodeActivation_Operation_getDecisionInputFlowInstance() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getDecisionNodeActivation_Operation_getDecisionInputFlowValue() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getDecisionNodeActivation_Operation_getDecisionValues_Token() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getDecisionNodeActivation_Operation_hasObjectFlowInput() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getDecisionNodeActivation_Operation_isReady() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getDecisionNodeActivation_Operation_removeJoinedControlTokens_Token() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getDecisionNodeActivation_Operation_takeOfferedTokens() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getDecisionNodeActivation_Operation_test_ValueSpecification_EJavaObject() const = 0;
			
			// End Class DecisionNodeActivation


			// Begin Class FlowFinalNodeActivation
			//Class and Feature IDs 
			static const unsigned long FLOWFINALNODEACTIVATION_CLASS = 1816371590;
			static const unsigned int FLOWFINALNODEACTIVATION_CLASS_FEATURE_COUNT = 6;
			static const unsigned int FLOWFINALNODEACTIVATION_CLASS_OPERATION_COUNT = 28;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getFlowFinalNodeActivation_Class() const = 0;
			
			
			
			
			// End Class FlowFinalNodeActivation


			// Begin Class ForkNodeActivation
			//Class and Feature IDs 
			static const unsigned long FORKNODEACTIVATION_CLASS = 1142288693;
			static const unsigned int FORKNODEACTIVATION_CLASS_FEATURE_COUNT = 6;
			static const unsigned int FORKNODEACTIVATION_CLASS_OPERATION_COUNT = 30;
			
			
			static const unsigned long FORKNODEACTIVATION_OPERATION_FIRE_TOKEN = 974284456;
			static const unsigned long FORKNODEACTIVATION_OPERATION_TERMINATE = 3793874788;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getForkNodeActivation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getForkNodeActivation_Operation_fire_Token() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getForkNodeActivation_Operation_terminate() const = 0;
			
			// End Class ForkNodeActivation


			// Begin Class ForkedToken
			//Class and Feature IDs 
			static const unsigned long FORKEDTOKEN_CLASS = 387026340;
			static const unsigned int FORKEDTOKEN_CLASS_FEATURE_COUNT = 5;
			static const unsigned int FORKEDTOKEN_CLASS_OPERATION_COUNT = 11;
			static const unsigned long FORKEDTOKEN_ATTRIBUTE_BASETOKENISWITHDRAWN = 980310284;
			static const unsigned long FORKEDTOKEN_ATTRIBUTE_REMAININGOFFERSCOUNT = 1967729962;
			
			static const unsigned long FORKEDTOKEN_ATTRIBUTE_BASETOKEN = 1285402041;
			
			static const unsigned long FORKEDTOKEN_OPERATION__COPY = 3813886438;
			static const unsigned long FORKEDTOKEN_OPERATION_EQUALS_TOKEN = 2609062935;
			static const unsigned long FORKEDTOKEN_OPERATION_GETVALUE = 776594391;
			static const unsigned long FORKEDTOKEN_OPERATION_ISCONTROL = 919245696;
			static const unsigned long FORKEDTOKEN_OPERATION_WITHDRAW = 3679135667;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getForkedToken_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getForkedToken_Attribute_baseTokenIsWithdrawn() const = 0;
			virtual std::shared_ptr<ecore::EAttribute> getForkedToken_Attribute_remainingOffersCount() const = 0;
			
			virtual std::shared_ptr<ecore::EReference> getForkedToken_Attribute_baseToken() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getForkedToken_Operation__copy() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getForkedToken_Operation_equals_Token() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getForkedToken_Operation_getValue() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getForkedToken_Operation_isControl() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getForkedToken_Operation_withdraw() const = 0;
			
			// End Class ForkedToken


			// Begin Class InitialNodeActivation
			//Class and Feature IDs 
			static const unsigned long INITIALNODEACTIVATION_CLASS = 176514932;
			static const unsigned int INITIALNODEACTIVATION_CLASS_FEATURE_COUNT = 6;
			static const unsigned int INITIALNODEACTIVATION_CLASS_OPERATION_COUNT = 29;
			
			
			static const unsigned long INITIALNODEACTIVATION_OPERATION_FIRE_TOKEN = 3439352700;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getInitialNodeActivation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getInitialNodeActivation_Operation_fire_Token() const = 0;
			
			// End Class InitialNodeActivation


			// Begin Class JoinNodeActivation
			//Class and Feature IDs 
			static const unsigned long JOINNODEACTIVATION_CLASS = 982186466;
			static const unsigned int JOINNODEACTIVATION_CLASS_FEATURE_COUNT = 6;
			static const unsigned int JOINNODEACTIVATION_CLASS_OPERATION_COUNT = 30;
			
			
			static const unsigned long JOINNODEACTIVATION_OPERATION_FIRE_TOKEN = 1770507194;
			static const unsigned long JOINNODEACTIVATION_OPERATION_ISREADY = 1408588552;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getJoinNodeActivation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getJoinNodeActivation_Operation_fire_Token() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getJoinNodeActivation_Operation_isReady() const = 0;
			
			// End Class JoinNodeActivation


			// Begin Class MergeNodeActivation
			//Class and Feature IDs 
			static const unsigned long MERGENODEACTIVATION_CLASS = 1031931828;
			static const unsigned int MERGENODEACTIVATION_CLASS_FEATURE_COUNT = 6;
			static const unsigned int MERGENODEACTIVATION_CLASS_OPERATION_COUNT = 28;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getMergeNodeActivation_Class() const = 0;
			
			
			
			
			// End Class MergeNodeActivation


			// Begin Class ObjectNodeActivation
			//Class and Feature IDs 
			static const unsigned long OBJECTNODEACTIVATION_CLASS = 898578487;
			static const unsigned int OBJECTNODEACTIVATION_CLASS_FEATURE_COUNT = 7;
			static const unsigned int OBJECTNODEACTIVATION_CLASS_OPERATION_COUNT = 38;
			static const unsigned long OBJECTNODEACTIVATION_ATTRIBUTE_OFFEREDTOKENCOUNT = 1384449261;
			
			
			static const unsigned long OBJECTNODEACTIVATION_OPERATION_ADDTOKEN_TOKEN = 3455616103;
			static const unsigned long OBJECTNODEACTIVATION_OPERATION_CLEARTOKENS = 955294195;
			static const unsigned long OBJECTNODEACTIVATION_OPERATION_COUNTOFFEREDVALUES = 2731645893;
			static const unsigned long OBJECTNODEACTIVATION_OPERATION_COUNTUNOFFEREDTOKENS = 209809884;
			static const unsigned long OBJECTNODEACTIVATION_OPERATION_GETUNOFFEREDTOKENS = 2051750135;
			static const unsigned long OBJECTNODEACTIVATION_OPERATION_REMOVETOKEN_TOKEN = 794012241;
			static const unsigned long OBJECTNODEACTIVATION_OPERATION_RUN = 2383055481;
			static const unsigned long OBJECTNODEACTIVATION_OPERATION_SENDOFFERS_TOKEN = 1025246782;
			static const unsigned long OBJECTNODEACTIVATION_OPERATION_SENDUNOFFEREDTOKENS = 230468136;
			static const unsigned long OBJECTNODEACTIVATION_OPERATION_TAKEUNOFFEREDTOKENS = 4049856236;
			static const unsigned long OBJECTNODEACTIVATION_OPERATION_TERMINATE = 2022976081;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getObjectNodeActivation_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getObjectNodeActivation_Attribute_offeredTokenCount() const = 0;
			
			
			virtual std::shared_ptr<ecore::EOperation> getObjectNodeActivation_Operation_addToken_Token() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getObjectNodeActivation_Operation_clearTokens() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getObjectNodeActivation_Operation_countOfferedValues() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getObjectNodeActivation_Operation_countUnofferedTokens() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getObjectNodeActivation_Operation_getUnofferedTokens() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getObjectNodeActivation_Operation_removeToken_Token() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getObjectNodeActivation_Operation_run() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getObjectNodeActivation_Operation_sendOffers_Token() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getObjectNodeActivation_Operation_sendUnofferedTokens() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getObjectNodeActivation_Operation_takeUnofferedTokens() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getObjectNodeActivation_Operation_terminate() const = 0;
			
			// End Class ObjectNodeActivation


			// Begin Class ObjectToken
			//Class and Feature IDs 
			static const unsigned long OBJECTTOKEN_CLASS = 85097778;
			static const unsigned int OBJECTTOKEN_CLASS_FEATURE_COUNT = 3;
			static const unsigned int OBJECTTOKEN_CLASS_OPERATION_COUNT = 9;
			static const unsigned long OBJECTTOKEN_ATTRIBUTE_VALUE = 2030770298;
			
			
			static const unsigned long OBJECTTOKEN_OPERATION__COPY = 2325156054;
			static const unsigned long OBJECTTOKEN_OPERATION_EQUALS_TOKEN = 1120332551;
			static const unsigned long OBJECTTOKEN_OPERATION_ISCONTROL = 3725482608;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getObjectToken_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getObjectToken_Attribute_value() const = 0;
			
			
			virtual std::shared_ptr<ecore::EOperation> getObjectToken_Operation__copy() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getObjectToken_Operation_equals_Token() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getObjectToken_Operation_isControl() const = 0;
			
			// End Class ObjectToken


			// Begin Class Offer
			//Class and Feature IDs 
			static const unsigned long OFFER_CLASS = 1035192448;
			static const unsigned int OFFER_CLASS_FEATURE_COUNT = 1;
			static const unsigned int OFFER_CLASS_OPERATION_COUNT = 5;
			
			static const unsigned long OFFER_ATTRIBUTE_OFFEREDTOKENS = 295657861;
			
			static const unsigned long OFFER_OPERATION_COUNTOFFEREDVALES = 904773483;
			static const unsigned long OFFER_OPERATION_HASTOKENS = 3339319593;
			static const unsigned long OFFER_OPERATION_REMOVEOFFEREDVALUES_EINT = 1313324759;
			static const unsigned long OFFER_OPERATION_REMOVEWITHDRAWNTOKENS = 3955994697;
			static const unsigned long OFFER_OPERATION_RETRIEVEOFFEREDTOKENS = 1383812745;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getOffer_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getOffer_Attribute_offeredTokens() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getOffer_Operation_countOfferedVales() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getOffer_Operation_hasTokens() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getOffer_Operation_removeOfferedValues_EInt() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getOffer_Operation_removeWithdrawnTokens() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getOffer_Operation_retrieveOfferedTokens() const = 0;
			
			// End Class Offer


			// Begin Class Token
			//Class and Feature IDs 
			static const unsigned long TOKEN_CLASS = 476107875;
			static const unsigned int TOKEN_CLASS_FEATURE_COUNT = 2;
			static const unsigned int TOKEN_CLASS_OPERATION_COUNT = 6;
			static const unsigned long TOKEN_ATTRIBUTE_WITHDRAWN = 849638730;
			
			static const unsigned long TOKEN_ATTRIBUTE_HOLDER = 1704390519;
			
			static const unsigned long TOKEN_OPERATION__COPY = 2860108519;
			static const unsigned long TOKEN_OPERATION_EQUALS_TOKEN = 378713648;
			static const unsigned long TOKEN_OPERATION_GETVALUE = 900354032;
			static const unsigned long TOKEN_OPERATION_ISCONTROL = 2683482097;
			static const unsigned long TOKEN_OPERATION_TRANSFER_ACTIVITYNODEACTIVATION = 2200060239;
			static const unsigned long TOKEN_OPERATION_WITHDRAW = 81284716;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getToken_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getToken_Attribute_withdrawn() const = 0;
			
			virtual std::shared_ptr<ecore::EReference> getToken_Attribute_holder() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getToken_Operation__copy() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getToken_Operation_equals_Token() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getToken_Operation_getValue() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getToken_Operation_isControl() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getToken_Operation_transfer_ActivityNodeActivation() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getToken_Operation_withdraw() const = 0;
			
			// End Class Token


			// Begin Class TokenSet
			//Class and Feature IDs 
			static const unsigned long TOKENSET_CLASS = 1781345229;
			static const unsigned int TOKENSET_CLASS_FEATURE_COUNT = 1;
			static const unsigned int TOKENSET_CLASS_OPERATION_COUNT = 0;
			
			static const unsigned long TOKENSET_ATTRIBUTE_TOKENS = 1809780411;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getTokenSet_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getTokenSet_Attribute_tokens() const = 0;
			
			
			// End Class TokenSet

			
			

			

			//Singleton Getter
			public:
				static std::shared_ptr<ActivitiesPackage> eInstance();
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIESPACKAGE_HPP */
