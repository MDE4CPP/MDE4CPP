//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONSPACKAGE_HPP
#define FUML_SEMANTICS_ACTIONSPACKAGE_HPP

// namespace macro header include
#include "fUML/fUML.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EStringToStringMapEntry;
	class EAnnotation;
	class EAttribute;
	class EReference;
	class EGenericType;
	class EOperation;
	class EClass;
	class EParameter;
	class EDataType;
}

namespace fUML::Semantics::Actions 
{
	class ActionActivation;
	class AddStructuralFeatureValueActionActivation;
	class CallActionActivation;
	class CallBehaviorActionActivation;
	class CallOperationActionActivation;
	class ClearStructuralFeatureActionActivation;
	class CreateObjectActionActivation;
	class DestroyObjectActionActivation;
	class ExpansionActivationGroup;
	class ExpansionNodeActivation;
	class ExpansionRegionActivation;
	class InputPinActivation;
	class InvocationActionActivation;
	class OutputPinActivation;
	class PinActivation;
	class ReadIsClassifiedObjectActionActivation;
	class ReadSelfActionActivation;
	class ReadStructuralFeatureActionActivation;
	class RemoveStructuralFeatureValueActionActivation;
	class StructuralFeatureActionActivation;
	class StructuredActivityNodeActivation;
	class ValueSpecificationActionActivation;
	class Values;
	class WriteStructuralFeatureActionActivation;
}
 
namespace fUML::Semantics::Actions 
{
	/*!
	The Metamodel Package for the Actions metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class FUML_API ActionsPackage : virtual public ecore::EPackage 
	{
		private:    
			ActionsPackage(ActionsPackage const&) = delete;
			ActionsPackage& operator=(ActionsPackage const&) = delete;

		protected:
			ActionsPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			// Begin Class ActionActivation
			//Class and Feature IDs 
			static const unsigned long ACTIONACTIVATION_CLASS = 1460715511;
			static const unsigned int ACTIONACTIVATION_CLASS_FEATURE_COUNT = 11;
			static const unsigned int ACTIONACTIVATION_CLASS_OPERATION_COUNT = 46;
			static const unsigned long ACTIONACTIVATION_ATTRIBUTE_FIRING = 1491419949;
			
			static const unsigned long ACTIONACTIVATION_ATTRIBUTE_ACTION = 2026266654;
			static const unsigned long ACTIONACTIVATION_ATTRIBUTE_INPUTPINACTIVATION = 1578596931;
			static const unsigned long ACTIONACTIVATION_ATTRIBUTE_OUTPUTPINACTIVATION = 785116916;
			static const unsigned long ACTIONACTIVATION_ATTRIBUTE_PINACTIVATION = 527832669;
			
			static const unsigned int ACTIONACTIVATION_OPERATION_ADDOUTGOINGEDGE_ACTIVITYEDGEINSTANCE = 1241788814;
			static const unsigned int ACTIONACTIVATION_OPERATION_ADDPINACTIVATION_PINACTIVATION = 3005291216;
			static const unsigned int ACTIONACTIVATION_OPERATION_COMPLETEACTION = 3464717817;
			static const unsigned int ACTIONACTIVATION_OPERATION_CREATENODEACTIVATIONS = 1074089216;
			static const unsigned int ACTIONACTIVATION_OPERATION_DOACTION = 700884178;
			static const unsigned int ACTIONACTIVATION_OPERATION_FIRE_TOKEN = 1791268998;
			static const unsigned int ACTIONACTIVATION_OPERATION_GETTOKENS_INPUTPIN = 4209096250;
			static const unsigned int ACTIONACTIVATION_OPERATION_ISFIRNG = 392760869;
			static const unsigned int ACTIONACTIVATION_OPERATION_ISREADY = 215874108;
			static const unsigned int ACTIONACTIVATION_OPERATION_ISSOURCEFOR_ACTIVITYEDGEINSTANCE = 655850474;
			static const unsigned int ACTIONACTIVATION_OPERATION_PUTTOKEN_OUTPUTPIN_EJAVAOBJECT = 2145374429;
			static const unsigned int ACTIONACTIVATION_OPERATION_PUTTOKENS_OUTPUTPIN_EJAVAOBJECT = 3216810370;
			static const unsigned int ACTIONACTIVATION_OPERATION_RETRIEVEPINACTIVATION_PIN = 1625370816;
			static const unsigned int ACTIONACTIVATION_OPERATION_RUN = 4008736986;
			static const unsigned int ACTIONACTIVATION_OPERATION_SENDOFFERS = 2377121568;
			static const unsigned int ACTIONACTIVATION_OPERATION_TAKEOFFEREDTOKENS = 4135421142;
			static const unsigned int ACTIONACTIVATION_OPERATION_TAKETOKENS_INPUTPIN = 1093731227;
			static const unsigned int ACTIONACTIVATION_OPERATION_TERMINATE = 1071084434;
			static const unsigned int ACTIONACTIVATION_OPERATION_VALUEPARTICIPATESINLINK_EJAVAOBJECT_ELEMENT = 3874903198;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getActionActivation_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getActionActivation_Attribute_firing() const = 0;
			
			virtual std::shared_ptr<ecore::EReference> getActionActivation_Attribute_action() const = 0;
			virtual std::shared_ptr<ecore::EReference> getActionActivation_Attribute_inputPinActivation() const = 0;
			virtual std::shared_ptr<ecore::EReference> getActionActivation_Attribute_outputPinActivation() const = 0;
			virtual std::shared_ptr<ecore::EReference> getActionActivation_Attribute_pinActivation() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_addPinActivation_PinActivation() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_completeAction() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_createNodeActivations() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_doAction() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_fire_Token() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_getTokens_InputPin() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_isFirng() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_isReady() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_isSourceFor_ActivityEdgeInstance() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_putToken_OutputPin_EJavaObject() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_putTokens_OutputPin_EJavaObject() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_retrievePinActivation_Pin() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_run() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_sendOffers() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_takeOfferedTokens() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_takeTokens_InputPin() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_terminate() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_valueParticipatesInLink_EJavaObject_Element() const = 0;
			
			// End Class ActionActivation


			// Begin Class AddStructuralFeatureValueActionActivation
			//Class and Feature IDs 
			static const unsigned long ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS = 1064766578;
			static const unsigned int ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS_FEATURE_COUNT = 12;
			static const unsigned int ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS_OPERATION_COUNT = 52;
			
			static const unsigned long ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_ATTRIBUTE_ADDSTRUCTURALFEATUREVALUEACTION = 901896398;
			
			static const unsigned int ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_OPERATION_DOACTION = 2452594673;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getAddStructuralFeatureValueActionActivation_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getAddStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getAddStructuralFeatureValueActionActivation_Operation_doAction() const = 0;
			
			// End Class AddStructuralFeatureValueActionActivation


			// Begin Class CallActionActivation
			//Class and Feature IDs 
			static const unsigned long CALLACTIONACTIVATION_CLASS = 129532533;
			static const unsigned int CALLACTIONACTIVATION_CLASS_FEATURE_COUNT = 12;
			static const unsigned int CALLACTIONACTIVATION_CLASS_OPERATION_COUNT = 50;
			
			static const unsigned long CALLACTIONACTIVATION_ATTRIBUTE_CALLACTION = 661588975;
			
			static const unsigned int CALLACTIONACTIVATION_OPERATION_DOACTION = 3531200850;
			static const unsigned int CALLACTIONACTIVATION_OPERATION_DOCALL_PARAMETERVALUE = 27461358;
			static const unsigned int CALLACTIONACTIVATION_OPERATION_RETRIEVECALLPARAMETERS = 3734106017;
			static const unsigned int CALLACTIONACTIVATION_OPERATION_TERMINATE = 2819746834;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCallActionActivation_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getCallActionActivation_Attribute_callAction() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getCallActionActivation_Operation_doAction() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallActionActivation_Operation_doCall_ParameterValue() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallActionActivation_Operation_retrieveCallParameters() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallActionActivation_Operation_terminate() const = 0;
			
			// End Class CallActionActivation


			// Begin Class CallBehaviorActionActivation
			//Class and Feature IDs 
			static const unsigned long CALLBEHAVIORACTIONACTIVATION_CLASS = 1169624682;
			static const unsigned int CALLBEHAVIORACTIONACTIVATION_CLASS_FEATURE_COUNT = 13;
			static const unsigned int CALLBEHAVIORACTIONACTIVATION_CLASS_OPERATION_COUNT = 53;
			
			static const unsigned long CALLBEHAVIORACTIONACTIVATION_ATTRIBUTE_CALLBEHAVIORACTION = 1409658851;
			
			static const unsigned int CALLBEHAVIORACTIONACTIVATION_OPERATION_DOCALL_PARAMETERVALUE = 2530900674;
			static const unsigned int CALLBEHAVIORACTIONACTIVATION_OPERATION_RETRIEVEBEHAVIOR = 2035427474;
			static const unsigned int CALLBEHAVIORACTIONACTIVATION_OPERATION_RETRIEVECALLPARAMETERS = 3812119957;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCallBehaviorActionActivation_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getCallBehaviorActionActivation_Attribute_callBehaviorAction() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getCallBehaviorActionActivation_Operation_doCall_ParameterValue() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallBehaviorActionActivation_Operation_retrieveBehavior() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallBehaviorActionActivation_Operation_retrieveCallParameters() const = 0;
			
			// End Class CallBehaviorActionActivation


			// Begin Class CallOperationActionActivation
			//Class and Feature IDs 
			static const unsigned long CALLOPERATIONACTIONACTIVATION_CLASS = 1019024267;
			static const unsigned int CALLOPERATIONACTIONACTIVATION_CLASS_FEATURE_COUNT = 13;
			static const unsigned int CALLOPERATIONACTIONACTIVATION_CLASS_OPERATION_COUNT = 53;
			
			static const unsigned long CALLOPERATIONACTIONACTIVATION_ATTRIBUTE_CALLOPERATIONACTION = 1907981028;
			
			static const unsigned int CALLOPERATIONACTIONACTIVATION_OPERATION_DOCALL_PARAMETERVALUE = 3826002027;
			static const unsigned int CALLOPERATIONACTIONACTIVATION_OPERATION_RETRIEVEBEHAVIOR = 3335726203;
			static const unsigned int CALLOPERATIONACTIONACTIVATION_OPERATION_RETRIEVECALLPARAMETERS = 3011147290;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCallOperationActionActivation_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getCallOperationActionActivation_Attribute_callOperationAction() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getCallOperationActionActivation_Operation_doCall_ParameterValue() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallOperationActionActivation_Operation_retrieveBehavior() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallOperationActionActivation_Operation_retrieveCallParameters() const = 0;
			
			// End Class CallOperationActionActivation


			// Begin Class ClearStructuralFeatureActionActivation
			//Class and Feature IDs 
			static const unsigned long CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS = 2133607571;
			static const unsigned int CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS_FEATURE_COUNT = 12;
			static const unsigned int CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS_OPERATION_COUNT = 51;
			
			static const unsigned long CLEARSTRUCTURALFEATUREACTIONACTIVATION_ATTRIBUTE_CLEARSTRUCTURALFEATUREACTION = 1879561411;
			
			static const unsigned int CLEARSTRUCTURALFEATUREACTIONACTIVATION_OPERATION_DOACTION = 673492974;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getClearStructuralFeatureActionActivation_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getClearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getClearStructuralFeatureActionActivation_Operation_doAction() const = 0;
			
			// End Class ClearStructuralFeatureActionActivation


			// Begin Class CreateObjectActionActivation
			//Class and Feature IDs 
			static const unsigned long CREATEOBJECTACTIONACTIVATION_CLASS = 1800625725;
			static const unsigned int CREATEOBJECTACTIONACTIVATION_CLASS_FEATURE_COUNT = 12;
			static const unsigned int CREATEOBJECTACTIONACTIVATION_CLASS_OPERATION_COUNT = 47;
			
			static const unsigned long CREATEOBJECTACTIONACTIVATION_ATTRIBUTE_CREATEOBJECTACTION = 502545191;
			
			static const unsigned int CREATEOBJECTACTIONACTIVATION_OPERATION_DOACTION = 4275045489;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCreateObjectActionActivation_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getCreateObjectActionActivation_Attribute_createObjectAction() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getCreateObjectActionActivation_Operation_doAction() const = 0;
			
			// End Class CreateObjectActionActivation


			// Begin Class DestroyObjectActionActivation
			//Class and Feature IDs 
			static const unsigned long DESTROYOBJECTACTIONACTIVATION_CLASS = 624995293;
			static const unsigned int DESTROYOBJECTACTIONACTIVATION_CLASS_FEATURE_COUNT = 12;
			static const unsigned int DESTROYOBJECTACTIONACTIVATION_CLASS_OPERATION_COUNT = 49;
			
			static const unsigned long DESTROYOBJECTACTIONACTIVATION_ATTRIBUTE_DESTROYOBJECTACTION = 445795804;
			
			static const unsigned int DESTROYOBJECTACTIONACTIVATION_OPERATION_DESTROYOBJECT_EJAVAOBJECT_EBOOLEAN = 3697661383;
			static const unsigned int DESTROYOBJECTACTIONACTIVATION_OPERATION_DOACTION = 393014891;
			static const unsigned int DESTROYOBJECTACTIONACTIVATION_OPERATION_OBJECTISCOMPOSITE_ELEMENT_ELEMENT = 4059157106;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getDestroyObjectActionActivation_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getDestroyObjectActionActivation_Attribute_destroyObjectAction() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getDestroyObjectActionActivation_Operation_destroyObject_EJavaObject_EBoolean() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getDestroyObjectActionActivation_Operation_doAction() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getDestroyObjectActionActivation_Operation_objectIsComposite_Element_Element() const = 0;
			
			// End Class DestroyObjectActionActivation


			// Begin Class ExpansionActivationGroup
			//Class and Feature IDs 
			static const unsigned long EXPANSIONACTIVATIONGROUP_CLASS = 1593704580;
			static const unsigned int EXPANSIONACTIVATIONGROUP_CLASS_FEATURE_COUNT = 10;
			static const unsigned int EXPANSIONACTIVATIONGROUP_CLASS_OPERATION_COUNT = 21;
			static const unsigned long EXPANSIONACTIVATIONGROUP_ATTRIBUTE_INDEX = 1361222347;
			
			static const unsigned long EXPANSIONACTIVATIONGROUP_ATTRIBUTE_GROUPINPUTS = 1154311782;
			static const unsigned long EXPANSIONACTIVATIONGROUP_ATTRIBUTE_GROUPOUTPUTS = 219625111;
			static const unsigned long EXPANSIONACTIVATIONGROUP_ATTRIBUTE_REGIONACTIVATION = 1024001702;
			static const unsigned long EXPANSIONACTIVATIONGROUP_ATTRIBUTE_REGIONINPUTS = 681462531;
			
			static const unsigned int EXPANSIONACTIVATIONGROUP_OPERATION_GETACTIVITYEXECUTION = 466733328;
			static const unsigned int EXPANSIONACTIVATIONGROUP_OPERATION_GETNODEACTIVATION_ACTIVITYNODE = 2828128313;
			static const unsigned int EXPANSIONACTIVATIONGROUP_OPERATION_RESUME_ACTIVITYNODEACTIVATION = 1335215127;
			static const unsigned int EXPANSIONACTIVATIONGROUP_OPERATION_SUSPEND_ACTIVITYNODEACTIVATION = 3809461000;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getExpansionActivationGroup_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getExpansionActivationGroup_Attribute_index() const = 0;
			
			virtual std::shared_ptr<ecore::EReference> getExpansionActivationGroup_Attribute_groupInputs() const = 0;
			virtual std::shared_ptr<ecore::EReference> getExpansionActivationGroup_Attribute_groupOutputs() const = 0;
			virtual std::shared_ptr<ecore::EReference> getExpansionActivationGroup_Attribute_regionActivation() const = 0;
			virtual std::shared_ptr<ecore::EReference> getExpansionActivationGroup_Attribute_regionInputs() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getExpansionActivationGroup_Operation_getActivityExecution() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExpansionActivationGroup_Operation_getNodeActivation_ActivityNode() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExpansionActivationGroup_Operation_resume_ActivityNodeActivation() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExpansionActivationGroup_Operation_suspend_ActivityNodeActivation() const = 0;
			
			// End Class ExpansionActivationGroup


			// Begin Class ExpansionNodeActivation
			//Class and Feature IDs 
			static const unsigned long EXPANSIONNODEACTIVATION_CLASS = 950888510;
			static const unsigned int EXPANSIONNODEACTIVATION_CLASS_FEATURE_COUNT = 7;
			static const unsigned int EXPANSIONNODEACTIVATION_CLASS_OPERATION_COUNT = 42;
			
			
			static const unsigned int EXPANSIONNODEACTIVATION_OPERATION_FIRE_TOKEN = 1479997855;
			static const unsigned int EXPANSIONNODEACTIVATION_OPERATION_GETEXPANSIONREGIONACTIVATION = 932977362;
			static const unsigned int EXPANSIONNODEACTIVATION_OPERATION_ISREADY = 2757781629;
			static const unsigned int EXPANSIONNODEACTIVATION_OPERATION_RECEIVEOFFER = 2973879191;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getExpansionNodeActivation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getExpansionNodeActivation_Operation_fire_Token() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExpansionNodeActivation_Operation_getExpansionRegionActivation() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExpansionNodeActivation_Operation_isReady() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExpansionNodeActivation_Operation_receiveOffer() const = 0;
			
			// End Class ExpansionNodeActivation


			// Begin Class ExpansionRegionActivation
			//Class and Feature IDs 
			static const unsigned long EXPANSIONREGIONACTIVATION_CLASS = 468567239;
			static const unsigned int EXPANSIONREGIONACTIVATION_CLASS_FEATURE_COUNT = 15;
			static const unsigned int EXPANSIONREGIONACTIVATION_CLASS_OPERATION_COUNT = 60;
			static const unsigned long EXPANSIONREGIONACTIVATION_ATTRIBUTE_NEXT = 1185153702;
			
			static const unsigned long EXPANSIONREGIONACTIVATION_ATTRIBUTE_ACTIVATIONGROUPS = 1045207305;
			static const unsigned long EXPANSIONREGIONACTIVATION_ATTRIBUTE_INPUTEXPANSIONTOKENS = 1671556985;
			static const unsigned long EXPANSIONREGIONACTIVATION_ATTRIBUTE_INPUTTOKENS = 438709559;
			
			static const unsigned int EXPANSIONREGIONACTIVATION_OPERATION_DOACTION = 1666075641;
			static const unsigned int EXPANSIONREGIONACTIVATION_OPERATION_DOOUTPUT = 665072324;
			static const unsigned int EXPANSIONREGIONACTIVATION_OPERATION_DOSTRUCTUREDACTIVITY = 16459977;
			static const unsigned int EXPANSIONREGIONACTIVATION_OPERATION_GETEXPANSIONNODEACTIVATION_EXPANSIONNODE = 2910413301;
			static const unsigned int EXPANSIONREGIONACTIVATION_OPERATION_ISSUSPENDED = 1287707085;
			static const unsigned int EXPANSIONREGIONACTIVATION_OPERATION_NUMBEROFVALUES = 386548955;
			static const unsigned int EXPANSIONREGIONACTIVATION_OPERATION_RESUME_EXPANSIONACTIVATIONGROUP = 4204554741;
			static const unsigned int EXPANSIONREGIONACTIVATION_OPERATION_RUNGROUP_EXPANSIONACTIVATIONGROUP = 2755718114;
			static const unsigned int EXPANSIONREGIONACTIVATION_OPERATION_RUNITERATIVE = 2181022978;
			static const unsigned int EXPANSIONREGIONACTIVATION_OPERATION_RUNPARALLEL = 789694982;
			static const unsigned int EXPANSIONREGIONACTIVATION_OPERATION_SENDOFFERS = 4292864607;
			static const unsigned int EXPANSIONREGIONACTIVATION_OPERATION_TAKEOFFEREDTOKENS = 4271661133;
			static const unsigned int EXPANSIONREGIONACTIVATION_OPERATION_TERMINATE = 1626800569;
			static const unsigned int EXPANSIONREGIONACTIVATION_OPERATION_TERMINATEGROUP_EXPANSIONACTIVATIONGROUP = 2249229986;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getExpansionRegionActivation_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getExpansionRegionActivation_Attribute_next() const = 0;
			
			virtual std::shared_ptr<ecore::EReference> getExpansionRegionActivation_Attribute_activationGroups() const = 0;
			virtual std::shared_ptr<ecore::EReference> getExpansionRegionActivation_Attribute_inputExpansionTokens() const = 0;
			virtual std::shared_ptr<ecore::EReference> getExpansionRegionActivation_Attribute_inputTokens() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getExpansionRegionActivation_Operation_doAction() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExpansionRegionActivation_Operation_doOutput() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExpansionRegionActivation_Operation_doStructuredActivity() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExpansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExpansionRegionActivation_Operation_isSuspended() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExpansionRegionActivation_Operation_numberOfValues() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExpansionRegionActivation_Operation_resume_ExpansionActivationGroup() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExpansionRegionActivation_Operation_runGroup_ExpansionActivationGroup() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExpansionRegionActivation_Operation_runIterative() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExpansionRegionActivation_Operation_runParallel() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExpansionRegionActivation_Operation_sendOffers() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExpansionRegionActivation_Operation_takeOfferedTokens() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExpansionRegionActivation_Operation_terminate() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExpansionRegionActivation_Operation_terminateGroup_ExpansionActivationGroup() const = 0;
			
			// End Class ExpansionRegionActivation


			// Begin Class InputPinActivation
			//Class and Feature IDs 
			static const unsigned long INPUTPINACTIVATION_CLASS = 241768265;
			static const unsigned int INPUTPINACTIVATION_CLASS_FEATURE_COUNT = 9;
			static const unsigned int INPUTPINACTIVATION_CLASS_OPERATION_COUNT = 42;
			
			
			static const unsigned int INPUTPINACTIVATION_OPERATION_ISREADY = 2767333969;
			static const unsigned int INPUTPINACTIVATION_OPERATION_RECEIVEOFFER = 1988186339;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getInputPinActivation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getInputPinActivation_Operation_isReady() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getInputPinActivation_Operation_receiveOffer() const = 0;
			
			// End Class InputPinActivation


			// Begin Class InvocationActionActivation
			//Class and Feature IDs 
			static const unsigned long INVOCATIONACTIONACTIVATION_CLASS = 520674205;
			static const unsigned int INVOCATIONACTIONACTIVATION_CLASS_FEATURE_COUNT = 11;
			static const unsigned int INVOCATIONACTIONACTIVATION_CLASS_OPERATION_COUNT = 46;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getInvocationActionActivation_Class() const = 0;
			
			
			
			
			// End Class InvocationActionActivation


			// Begin Class OutputPinActivation
			//Class and Feature IDs 
			static const unsigned long OUTPUTPINACTIVATION_CLASS = 1393072800;
			static const unsigned int OUTPUTPINACTIVATION_CLASS_FEATURE_COUNT = 9;
			static const unsigned int OUTPUTPINACTIVATION_CLASS_OPERATION_COUNT = 40;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getOutputPinActivation_Class() const = 0;
			
			
			
			
			// End Class OutputPinActivation


			// Begin Class PinActivation
			//Class and Feature IDs 
			static const unsigned long PINACTIVATION_CLASS = 1234693025;
			static const unsigned int PINACTIVATION_CLASS_FEATURE_COUNT = 9;
			static const unsigned int PINACTIVATION_CLASS_OPERATION_COUNT = 40;
			
			static const unsigned long PINACTIVATION_ATTRIBUTE_ACTIONACTIVATION = 933287949;
			static const unsigned long PINACTIVATION_ATTRIBUTE_PIN = 1051508779;
			
			static const unsigned int PINACTIVATION_OPERATION_FIRE_TOKEN = 1644915019;
			static const unsigned int PINACTIVATION_OPERATION_TAKEOFFEREDTOKENS = 1396222683;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getPinActivation_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getPinActivation_Attribute_actionActivation() const = 0;
			virtual std::shared_ptr<ecore::EReference> getPinActivation_Attribute_pin() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getPinActivation_Operation_fire_Token() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getPinActivation_Operation_takeOfferedTokens() const = 0;
			
			// End Class PinActivation


			// Begin Class ReadIsClassifiedObjectActionActivation
			//Class and Feature IDs 
			static const unsigned long READISCLASSIFIEDOBJECTACTIONACTIVATION_CLASS = 882448659;
			static const unsigned int READISCLASSIFIEDOBJECTACTIONACTIVATION_CLASS_FEATURE_COUNT = 12;
			static const unsigned int READISCLASSIFIEDOBJECTACTIONACTIVATION_CLASS_OPERATION_COUNT = 47;
			
			static const unsigned long READISCLASSIFIEDOBJECTACTIONACTIVATION_ATTRIBUTE_READISCLASSIFIEDOBJECTACTION = 691102859;
			
			static const unsigned int READISCLASSIFIEDOBJECTACTIONACTIVATION_OPERATION_DOACTION = 2223647656;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getReadIsClassifiedObjectActionActivation_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getReadIsClassifiedObjectActionActivation_Attribute_readIsClassifiedObjectAction() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getReadIsClassifiedObjectActionActivation_Operation_doAction() const = 0;
			
			// End Class ReadIsClassifiedObjectActionActivation


			// Begin Class ReadSelfActionActivation
			//Class and Feature IDs 
			static const unsigned long READSELFACTIONACTIVATION_CLASS = 1073972718;
			static const unsigned int READSELFACTIONACTIVATION_CLASS_FEATURE_COUNT = 12;
			static const unsigned int READSELFACTIONACTIVATION_CLASS_OPERATION_COUNT = 47;
			
			static const unsigned long READSELFACTIONACTIVATION_ATTRIBUTE_READSELFACTION = 681779623;
			
			static const unsigned int READSELFACTIONACTIVATION_OPERATION_DOACTION = 2282322208;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getReadSelfActionActivation_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getReadSelfActionActivation_Attribute_readSelfAction() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getReadSelfActionActivation_Operation_doAction() const = 0;
			
			// End Class ReadSelfActionActivation


			// Begin Class ReadStructuralFeatureActionActivation
			//Class and Feature IDs 
			static const unsigned long READSTRUCTURALFEATUREACTIONACTIVATION_CLASS = 990872664;
			static const unsigned int READSTRUCTURALFEATUREACTIONACTIVATION_CLASS_FEATURE_COUNT = 12;
			static const unsigned int READSTRUCTURALFEATUREACTIONACTIVATION_CLASS_OPERATION_COUNT = 51;
			
			static const unsigned long READSTRUCTURALFEATUREACTIONACTIVATION_ATTRIBUTE_READSTRUCTURALFEATUREACTION = 2088398247;
			
			static const unsigned int READSTRUCTURALFEATUREACTIONACTIVATION_OPERATION_DOACTION = 2509578359;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getReadStructuralFeatureActionActivation_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getReadStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getReadStructuralFeatureActionActivation_Operation_doAction() const = 0;
			
			// End Class ReadStructuralFeatureActionActivation


			// Begin Class RemoveStructuralFeatureValueActionActivation
			//Class and Feature IDs 
			static const unsigned long REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS = 730007269;
			static const unsigned int REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS_FEATURE_COUNT = 12;
			static const unsigned int REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS_OPERATION_COUNT = 52;
			
			static const unsigned long REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_ATTRIBUTE_REMOVESTRUCTURALFEATUREVALUEACTION = 204338767;
			
			static const unsigned int REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_OPERATION_DOACTION = 3575480050;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getRemoveStructuralFeatureValueActionActivation_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getRemoveStructuralFeatureValueActionActivation_Attribute_removeStructuralFeatureValueAction() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getRemoveStructuralFeatureValueActionActivation_Operation_doAction() const = 0;
			
			// End Class RemoveStructuralFeatureValueActionActivation


			// Begin Class StructuralFeatureActionActivation
			//Class and Feature IDs 
			static const unsigned long STRUCTURALFEATUREACTIONACTIVATION_CLASS = 303469345;
			static const unsigned int STRUCTURALFEATUREACTIONACTIVATION_CLASS_FEATURE_COUNT = 11;
			static const unsigned int STRUCTURALFEATUREACTIONACTIVATION_CLASS_OPERATION_COUNT = 50;
			
			
			static const unsigned int STRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETASSOCIATION_STRUCTURALFEATURE = 4112546735;
			static const unsigned int STRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETMATCHINGLINKS_ASSOCIATION_EJAVAOBJECT = 2765304632;
			static const unsigned int STRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETMATCHINGLINKSFORENDVALUE_ASSOCIATION_EJAVAOBJECT = 2298435547;
			static const unsigned int STRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETOPPOSITEEND_ASSOCIATION_STRUCTURALFEATURE = 1289289959;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getStructuralFeatureActionActivation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getStructuralFeatureActionActivation_Operation_getAssociation_StructuralFeature() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getStructuralFeatureActionActivation_Operation_getMatchingLinks_Association_EJavaObject() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getStructuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_EJavaObject() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getStructuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature() const = 0;
			
			// End Class StructuralFeatureActionActivation


			// Begin Class StructuredActivityNodeActivation
			//Class and Feature IDs 
			static const unsigned long STRUCTUREDACTIVITYNODEACTIVATION_CLASS = 1589145908;
			static const unsigned int STRUCTUREDACTIVITYNODEACTIVATION_CLASS_FEATURE_COUNT = 12;
			static const unsigned int STRUCTUREDACTIVITYNODEACTIVATION_CLASS_OPERATION_COUNT = 60;
			
			static const unsigned long STRUCTUREDACTIVITYNODEACTIVATION_ATTRIBUTE_ACTIVATIONGROUP = 1502048964;
			
			static const unsigned int STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_COMPLETEACTION = 3878860807;
			static const unsigned int STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_CREATEEDGEINSTANCES = 4189320520;
			static const unsigned int STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_CREATENODEACTIVATIONS = 3493676622;
			static const unsigned int STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_DOACTION = 3506173856;
			static const unsigned int STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_DOSTRUCTUREDACTIVITY = 1244905776;
			static const unsigned int STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_GETNODEACTIVATION_ACTIVITYNODE = 935616927;
			static const unsigned int STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_GETPINVALUES_OUTPUTPIN = 418079140;
			static const unsigned int STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_ISSOURCEFOR_ACTIVITYEDGEINSTANCE = 3281612984;
			static const unsigned int STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_ISSUSPENDED = 3925255716;
			static const unsigned int STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_MAKEACTIVITYNODELIST_EXECUTABLENODE = 854326129;
			static const unsigned int STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_PUTPINVALUES_OUTPUTPIN_EJAVAOBJECT = 362386455;
			static const unsigned int STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_RESUME = 568722472;
			static const unsigned int STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_TERMINATE = 2956351072;
			static const unsigned int STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_TERMINATEALL = 188036217;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getStructuredActivityNodeActivation_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getStructuredActivityNodeActivation_Attribute_activationGroup() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getStructuredActivityNodeActivation_Operation_completeAction() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getStructuredActivityNodeActivation_Operation_createEdgeInstances() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getStructuredActivityNodeActivation_Operation_createNodeActivations() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getStructuredActivityNodeActivation_Operation_doAction() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getStructuredActivityNodeActivation_Operation_doStructuredActivity() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getStructuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getStructuredActivityNodeActivation_Operation_getPinValues_OutputPin() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getStructuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getStructuredActivityNodeActivation_Operation_isSuspended() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getStructuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getStructuredActivityNodeActivation_Operation_putPinValues_OutputPin_EJavaObject() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getStructuredActivityNodeActivation_Operation_resume() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getStructuredActivityNodeActivation_Operation_terminate() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getStructuredActivityNodeActivation_Operation_terminateAll() const = 0;
			
			// End Class StructuredActivityNodeActivation


			// Begin Class ValueSpecificationActionActivation
			//Class and Feature IDs 
			static const unsigned long VALUESPECIFICATIONACTIONACTIVATION_CLASS = 1084170516;
			static const unsigned int VALUESPECIFICATIONACTIONACTIVATION_CLASS_FEATURE_COUNT = 11;
			static const unsigned int VALUESPECIFICATIONACTIONACTIVATION_CLASS_OPERATION_COUNT = 47;
			
			
			static const unsigned int VALUESPECIFICATIONACTIONACTIVATION_OPERATION_DOACTION = 871196704;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getValueSpecificationActionActivation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getValueSpecificationActionActivation_Operation_doAction() const = 0;
			
			// End Class ValueSpecificationActionActivation


			// Begin Class Values
			//Class and Feature IDs 
			static const unsigned long VALUES_CLASS = 1160776639;
			static const unsigned int VALUES_CLASS_FEATURE_COUNT = 1;
			static const unsigned int VALUES_CLASS_OPERATION_COUNT = 0;
			static const unsigned long VALUES_ATTRIBUTE_VALUES = 1875116502;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getValues_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getValues_Attribute_values() const = 0;
			
			
			
			// End Class Values


			// Begin Class WriteStructuralFeatureActionActivation
			//Class and Feature IDs 
			static const unsigned long WRITESTRUCTURALFEATUREACTIONACTIVATION_CLASS = 2019683585;
			static const unsigned int WRITESTRUCTURALFEATUREACTIONACTIVATION_CLASS_FEATURE_COUNT = 11;
			static const unsigned int WRITESTRUCTURALFEATUREACTIONACTIVATION_CLASS_OPERATION_COUNT = 51;
			
			
			static const unsigned int WRITESTRUCTURALFEATUREACTIONACTIVATION_OPERATION_POSITION_EJAVAOBJECT_EINT = 455262104;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getWriteStructuralFeatureActionActivation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getWriteStructuralFeatureActionActivation_Operation_position_EJavaObject_EInt() const = 0;
			
			// End Class WriteStructuralFeatureActionActivation

			
			

			

			//Singleton Instance and Getter
			private:
				static std::shared_ptr<ActionsPackage> instance;
			public:
				static std::shared_ptr<ActionsPackage> eInstance();
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONSPACKAGE_HPP */
