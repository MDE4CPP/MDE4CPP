//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONSPACKAGEIMPL_HPP
#define FUML_SEMANTICS_ACTIONSPACKAGEIMPL_HPP

// namespace macro header include
#include "fUML/fUML.hpp"

#include "ecore/ecorePackage.hpp"
#include "ecore/impl/EPackageImpl.hpp"

#include "fUML/Semantics/Actions/ActionsPackage.hpp" 


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
	class WriteStructuralFeatureActionActivation;}

namespace ecore
{
	class ecoreFactory;
}

namespace fUML::Semantics::Actions
{
	class FUML_API ActionsPackageImpl : public ecore::EPackageImpl ,virtual public ActionsPackage
	{
		private:    
			ActionsPackageImpl(ActionsPackageImpl const&) = delete;
			ActionsPackageImpl& operator=(ActionsPackageImpl const&) = delete;

		protected:
			ActionsPackageImpl();

		public:
			virtual ~ActionsPackageImpl();

			// Begin Class ActionActivation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getActionActivation_Class() const ;
			
			virtual std::shared_ptr<ecore::EAttribute> getActionActivation_Attribute_firing() const ;
			
			virtual std::shared_ptr<ecore::EReference> getActionActivation_Attribute_action() const ;
			virtual std::shared_ptr<ecore::EReference> getActionActivation_Attribute_inputPinActivation() const ;
			virtual std::shared_ptr<ecore::EReference> getActionActivation_Attribute_outputPinActivation() const ;
			virtual std::shared_ptr<ecore::EReference> getActionActivation_Attribute_pinActivation() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance() const ;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_addPinActivation_PinActivation() const ;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_completeAction() const ;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_createNodeActivations() const ;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_doAction() const ;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_fire_Token() const ;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_getTokens_InputPin() const ;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_isFirng() const ;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_isReady() const ;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_isSourceFor_ActivityEdgeInstance() const ;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_putToken_OutputPin_EJavaObject() const ;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_putTokens_OutputPin_EJavaObject() const ;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_retrievePinActivation_Pin() const ;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_run() const ;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_sendOffers() const ;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_takeOfferedTokens() const ;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_takeTokens_InputPin() const ;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_terminate() const ;
			virtual std::shared_ptr<ecore::EOperation> getActionActivation_Operation_valueParticipatesInLink_EJavaObject_Element() const ;
			
			// End Class ActionActivation

			// Begin Class AddStructuralFeatureValueActionActivation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getAddStructuralFeatureValueActionActivation_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getAddStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getAddStructuralFeatureValueActionActivation_Operation_doAction() const ;
			
			// End Class AddStructuralFeatureValueActionActivation

			// Begin Class CallActionActivation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCallActionActivation_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getCallActionActivation_Attribute_callAction() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getCallActionActivation_Operation_doAction() const ;
			virtual std::shared_ptr<ecore::EOperation> getCallActionActivation_Operation_doCall_ParameterValue() const ;
			virtual std::shared_ptr<ecore::EOperation> getCallActionActivation_Operation_retrieveCallParameters() const ;
			virtual std::shared_ptr<ecore::EOperation> getCallActionActivation_Operation_terminate() const ;
			
			// End Class CallActionActivation

			// Begin Class CallBehaviorActionActivation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCallBehaviorActionActivation_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getCallBehaviorActionActivation_Attribute_callBehaviorAction() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getCallBehaviorActionActivation_Operation_doCall_ParameterValue() const ;
			virtual std::shared_ptr<ecore::EOperation> getCallBehaviorActionActivation_Operation_retrieveBehavior() const ;
			virtual std::shared_ptr<ecore::EOperation> getCallBehaviorActionActivation_Operation_retrieveCallParameters() const ;
			
			// End Class CallBehaviorActionActivation

			// Begin Class CallOperationActionActivation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCallOperationActionActivation_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getCallOperationActionActivation_Attribute_callOperationAction() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getCallOperationActionActivation_Operation_doCall_ParameterValue() const ;
			virtual std::shared_ptr<ecore::EOperation> getCallOperationActionActivation_Operation_retrieveBehavior() const ;
			virtual std::shared_ptr<ecore::EOperation> getCallOperationActionActivation_Operation_retrieveCallParameters() const ;
			
			// End Class CallOperationActionActivation

			// Begin Class ClearStructuralFeatureActionActivation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getClearStructuralFeatureActionActivation_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getClearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getClearStructuralFeatureActionActivation_Operation_doAction() const ;
			
			// End Class ClearStructuralFeatureActionActivation

			// Begin Class CreateObjectActionActivation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCreateObjectActionActivation_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getCreateObjectActionActivation_Attribute_createObjectAction() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getCreateObjectActionActivation_Operation_doAction() const ;
			
			// End Class CreateObjectActionActivation

			// Begin Class DestroyObjectActionActivation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getDestroyObjectActionActivation_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getDestroyObjectActionActivation_Attribute_destroyObjectAction() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getDestroyObjectActionActivation_Operation_destroyObject_EJavaObject_EBoolean() const ;
			virtual std::shared_ptr<ecore::EOperation> getDestroyObjectActionActivation_Operation_doAction() const ;
			virtual std::shared_ptr<ecore::EOperation> getDestroyObjectActionActivation_Operation_objectIsComposite_Element_Element() const ;
			
			// End Class DestroyObjectActionActivation

			// Begin Class ExpansionActivationGroup
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getExpansionActivationGroup_Class() const ;
			
			virtual std::shared_ptr<ecore::EAttribute> getExpansionActivationGroup_Attribute_index() const ;
			
			virtual std::shared_ptr<ecore::EReference> getExpansionActivationGroup_Attribute_groupInputs() const ;
			virtual std::shared_ptr<ecore::EReference> getExpansionActivationGroup_Attribute_groupOutputs() const ;
			virtual std::shared_ptr<ecore::EReference> getExpansionActivationGroup_Attribute_regionActivation() const ;
			virtual std::shared_ptr<ecore::EReference> getExpansionActivationGroup_Attribute_regionInputs() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getExpansionActivationGroup_Operation_getActivityExecution() const ;
			virtual std::shared_ptr<ecore::EOperation> getExpansionActivationGroup_Operation_getNodeActivation_ActivityNode() const ;
			virtual std::shared_ptr<ecore::EOperation> getExpansionActivationGroup_Operation_resume_ActivityNodeActivation() const ;
			virtual std::shared_ptr<ecore::EOperation> getExpansionActivationGroup_Operation_suspend_ActivityNodeActivation() const ;
			
			// End Class ExpansionActivationGroup

			// Begin Class ExpansionNodeActivation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getExpansionNodeActivation_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getExpansionNodeActivation_Operation_fire_Token() const ;
			virtual std::shared_ptr<ecore::EOperation> getExpansionNodeActivation_Operation_getExpansionRegionActivation() const ;
			virtual std::shared_ptr<ecore::EOperation> getExpansionNodeActivation_Operation_isReady() const ;
			virtual std::shared_ptr<ecore::EOperation> getExpansionNodeActivation_Operation_receiveOffer() const ;
			
			// End Class ExpansionNodeActivation

			// Begin Class ExpansionRegionActivation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getExpansionRegionActivation_Class() const ;
			
			virtual std::shared_ptr<ecore::EAttribute> getExpansionRegionActivation_Attribute_next() const ;
			
			virtual std::shared_ptr<ecore::EReference> getExpansionRegionActivation_Attribute_activationGroups() const ;
			virtual std::shared_ptr<ecore::EReference> getExpansionRegionActivation_Attribute_inputExpansionTokens() const ;
			virtual std::shared_ptr<ecore::EReference> getExpansionRegionActivation_Attribute_inputTokens() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getExpansionRegionActivation_Operation_doAction() const ;
			virtual std::shared_ptr<ecore::EOperation> getExpansionRegionActivation_Operation_doOutput() const ;
			virtual std::shared_ptr<ecore::EOperation> getExpansionRegionActivation_Operation_doStructuredActivity() const ;
			virtual std::shared_ptr<ecore::EOperation> getExpansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode() const ;
			virtual std::shared_ptr<ecore::EOperation> getExpansionRegionActivation_Operation_isSuspended() const ;
			virtual std::shared_ptr<ecore::EOperation> getExpansionRegionActivation_Operation_numberOfValues() const ;
			virtual std::shared_ptr<ecore::EOperation> getExpansionRegionActivation_Operation_resume_ExpansionActivationGroup() const ;
			virtual std::shared_ptr<ecore::EOperation> getExpansionRegionActivation_Operation_runGroup_ExpansionActivationGroup() const ;
			virtual std::shared_ptr<ecore::EOperation> getExpansionRegionActivation_Operation_runIterative() const ;
			virtual std::shared_ptr<ecore::EOperation> getExpansionRegionActivation_Operation_runParallel() const ;
			virtual std::shared_ptr<ecore::EOperation> getExpansionRegionActivation_Operation_sendOffers() const ;
			virtual std::shared_ptr<ecore::EOperation> getExpansionRegionActivation_Operation_takeOfferedTokens() const ;
			virtual std::shared_ptr<ecore::EOperation> getExpansionRegionActivation_Operation_terminate() const ;
			virtual std::shared_ptr<ecore::EOperation> getExpansionRegionActivation_Operation_terminateGroup_ExpansionActivationGroup() const ;
			
			// End Class ExpansionRegionActivation

			// Begin Class InputPinActivation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getInputPinActivation_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getInputPinActivation_Operation_isReady() const ;
			virtual std::shared_ptr<ecore::EOperation> getInputPinActivation_Operation_receiveOffer() const ;
			
			// End Class InputPinActivation

			// Begin Class InvocationActionActivation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getInvocationActionActivation_Class() const ;
			
			
			
			
			// End Class InvocationActionActivation

			// Begin Class OutputPinActivation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getOutputPinActivation_Class() const ;
			
			
			
			
			// End Class OutputPinActivation

			// Begin Class PinActivation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getPinActivation_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getPinActivation_Attribute_actionActivation() const ;
			virtual std::shared_ptr<ecore::EReference> getPinActivation_Attribute_pin() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getPinActivation_Operation_fire_Token() const ;
			virtual std::shared_ptr<ecore::EOperation> getPinActivation_Operation_takeOfferedTokens() const ;
			
			// End Class PinActivation

			// Begin Class ReadIsClassifiedObjectActionActivation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getReadIsClassifiedObjectActionActivation_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getReadIsClassifiedObjectActionActivation_Attribute_readIsClassifiedObjectAction() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getReadIsClassifiedObjectActionActivation_Operation_doAction() const ;
			
			// End Class ReadIsClassifiedObjectActionActivation

			// Begin Class ReadSelfActionActivation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getReadSelfActionActivation_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getReadSelfActionActivation_Attribute_readSelfAction() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getReadSelfActionActivation_Operation_doAction() const ;
			
			// End Class ReadSelfActionActivation

			// Begin Class ReadStructuralFeatureActionActivation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getReadStructuralFeatureActionActivation_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getReadStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getReadStructuralFeatureActionActivation_Operation_doAction() const ;
			
			// End Class ReadStructuralFeatureActionActivation

			// Begin Class RemoveStructuralFeatureValueActionActivation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getRemoveStructuralFeatureValueActionActivation_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getRemoveStructuralFeatureValueActionActivation_Attribute_removeStructuralFeatureValueAction() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getRemoveStructuralFeatureValueActionActivation_Operation_doAction() const ;
			
			// End Class RemoveStructuralFeatureValueActionActivation

			// Begin Class StructuralFeatureActionActivation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getStructuralFeatureActionActivation_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getStructuralFeatureActionActivation_Operation_getAssociation_StructuralFeature() const ;
			virtual std::shared_ptr<ecore::EOperation> getStructuralFeatureActionActivation_Operation_getMatchingLinks_Association_EJavaObject() const ;
			virtual std::shared_ptr<ecore::EOperation> getStructuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_EJavaObject() const ;
			virtual std::shared_ptr<ecore::EOperation> getStructuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature() const ;
			
			// End Class StructuralFeatureActionActivation

			// Begin Class StructuredActivityNodeActivation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getStructuredActivityNodeActivation_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getStructuredActivityNodeActivation_Attribute_activationGroup() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getStructuredActivityNodeActivation_Operation_completeAction() const ;
			virtual std::shared_ptr<ecore::EOperation> getStructuredActivityNodeActivation_Operation_createEdgeInstances() const ;
			virtual std::shared_ptr<ecore::EOperation> getStructuredActivityNodeActivation_Operation_createNodeActivations() const ;
			virtual std::shared_ptr<ecore::EOperation> getStructuredActivityNodeActivation_Operation_doAction() const ;
			virtual std::shared_ptr<ecore::EOperation> getStructuredActivityNodeActivation_Operation_doStructuredActivity() const ;
			virtual std::shared_ptr<ecore::EOperation> getStructuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode() const ;
			virtual std::shared_ptr<ecore::EOperation> getStructuredActivityNodeActivation_Operation_getPinValues_OutputPin() const ;
			virtual std::shared_ptr<ecore::EOperation> getStructuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance() const ;
			virtual std::shared_ptr<ecore::EOperation> getStructuredActivityNodeActivation_Operation_isSuspended() const ;
			virtual std::shared_ptr<ecore::EOperation> getStructuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode() const ;
			virtual std::shared_ptr<ecore::EOperation> getStructuredActivityNodeActivation_Operation_putPinValues_OutputPin_EJavaObject() const ;
			virtual std::shared_ptr<ecore::EOperation> getStructuredActivityNodeActivation_Operation_resume() const ;
			virtual std::shared_ptr<ecore::EOperation> getStructuredActivityNodeActivation_Operation_terminate() const ;
			virtual std::shared_ptr<ecore::EOperation> getStructuredActivityNodeActivation_Operation_terminateAll() const ;
			
			// End Class StructuredActivityNodeActivation

			// Begin Class ValueSpecificationActionActivation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getValueSpecificationActionActivation_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getValueSpecificationActionActivation_Operation_doAction() const ;
			
			// End Class ValueSpecificationActionActivation

			// Begin Class Values
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getValues_Class() const ;
			
			virtual std::shared_ptr<ecore::EAttribute> getValues_Attribute_values() const ;
			
			
			
			// End Class Values

			// Begin Class WriteStructuralFeatureActionActivation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getWriteStructuralFeatureActionActivation_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getWriteStructuralFeatureActionActivation_Operation_position_EJavaObject_EInt() const ;
			
			// End Class WriteStructuralFeatureActionActivation

			
			// SubPackages Getters
			

		private:
			std::shared_ptr<ecore::EClass> m_actionActivation_Class = nullptr;std::shared_ptr<ecore::EClass> m_addStructuralFeatureValueActionActivation_Class = nullptr;std::shared_ptr<ecore::EClass> m_callActionActivation_Class = nullptr;std::shared_ptr<ecore::EClass> m_callBehaviorActionActivation_Class = nullptr;std::shared_ptr<ecore::EClass> m_callOperationActionActivation_Class = nullptr;std::shared_ptr<ecore::EClass> m_clearStructuralFeatureActionActivation_Class = nullptr;std::shared_ptr<ecore::EClass> m_createObjectActionActivation_Class = nullptr;std::shared_ptr<ecore::EClass> m_destroyObjectActionActivation_Class = nullptr;std::shared_ptr<ecore::EClass> m_expansionActivationGroup_Class = nullptr;std::shared_ptr<ecore::EClass> m_expansionNodeActivation_Class = nullptr;std::shared_ptr<ecore::EClass> m_expansionRegionActivation_Class = nullptr;std::shared_ptr<ecore::EClass> m_inputPinActivation_Class = nullptr;std::shared_ptr<ecore::EClass> m_invocationActionActivation_Class = nullptr;std::shared_ptr<ecore::EClass> m_outputPinActivation_Class = nullptr;std::shared_ptr<ecore::EClass> m_pinActivation_Class = nullptr;std::shared_ptr<ecore::EClass> m_readIsClassifiedObjectActionActivation_Class = nullptr;std::shared_ptr<ecore::EClass> m_readSelfActionActivation_Class = nullptr;std::shared_ptr<ecore::EClass> m_readStructuralFeatureActionActivation_Class = nullptr;std::shared_ptr<ecore::EClass> m_removeStructuralFeatureValueActionActivation_Class = nullptr;std::shared_ptr<ecore::EClass> m_structuralFeatureActionActivation_Class = nullptr;std::shared_ptr<ecore::EClass> m_structuredActivityNodeActivation_Class = nullptr;std::shared_ptr<ecore::EClass> m_valueSpecificationActionActivation_Class = nullptr;std::shared_ptr<ecore::EClass> m_values_Class = nullptr;std::shared_ptr<ecore::EClass> m_writeStructuralFeatureActionActivation_Class = nullptr;
			
			std::shared_ptr<ecore::EAttribute> m_actionActivation_Attribute_firing = nullptr;std::shared_ptr<ecore::EAttribute> m_expansionActivationGroup_Attribute_index = nullptr;std::shared_ptr<ecore::EAttribute> m_expansionRegionActivation_Attribute_next = nullptr;std::shared_ptr<ecore::EAttribute> m_values_Attribute_values = nullptr;
			std::shared_ptr<ecore::EReference> m_actionActivation_Attribute_action = nullptr;std::shared_ptr<ecore::EReference> m_pinActivation_Attribute_actionActivation = nullptr;std::shared_ptr<ecore::EReference> m_structuredActivityNodeActivation_Attribute_activationGroup = nullptr;std::shared_ptr<ecore::EReference> m_expansionRegionActivation_Attribute_activationGroups = nullptr;std::shared_ptr<ecore::EReference> m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction = nullptr;std::shared_ptr<ecore::EReference> m_callActionActivation_Attribute_callAction = nullptr;std::shared_ptr<ecore::EReference> m_callBehaviorActionActivation_Attribute_callBehaviorAction = nullptr;std::shared_ptr<ecore::EReference> m_callOperationActionActivation_Attribute_callOperationAction = nullptr;std::shared_ptr<ecore::EReference> m_clearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction = nullptr;std::shared_ptr<ecore::EReference> m_createObjectActionActivation_Attribute_createObjectAction = nullptr;std::shared_ptr<ecore::EReference> m_destroyObjectActionActivation_Attribute_destroyObjectAction = nullptr;std::shared_ptr<ecore::EReference> m_expansionActivationGroup_Attribute_groupInputs = nullptr;std::shared_ptr<ecore::EReference> m_expansionActivationGroup_Attribute_groupOutputs = nullptr;std::shared_ptr<ecore::EReference> m_expansionRegionActivation_Attribute_inputExpansionTokens = nullptr;std::shared_ptr<ecore::EReference> m_actionActivation_Attribute_inputPinActivation = nullptr;std::shared_ptr<ecore::EReference> m_expansionRegionActivation_Attribute_inputTokens = nullptr;std::shared_ptr<ecore::EReference> m_actionActivation_Attribute_outputPinActivation = nullptr;std::shared_ptr<ecore::EReference> m_pinActivation_Attribute_pin = nullptr;std::shared_ptr<ecore::EReference> m_actionActivation_Attribute_pinActivation = nullptr;std::shared_ptr<ecore::EReference> m_readIsClassifiedObjectActionActivation_Attribute_readIsClassifiedObjectAction = nullptr;std::shared_ptr<ecore::EReference> m_readSelfActionActivation_Attribute_readSelfAction = nullptr;std::shared_ptr<ecore::EReference> m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction = nullptr;std::shared_ptr<ecore::EReference> m_expansionActivationGroup_Attribute_regionActivation = nullptr;std::shared_ptr<ecore::EReference> m_expansionActivationGroup_Attribute_regionInputs = nullptr;std::shared_ptr<ecore::EReference> m_removeStructuralFeatureValueActionActivation_Attribute_removeStructuralFeatureValueAction = nullptr;
			std::shared_ptr<ecore::EOperation> m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance = nullptr;std::shared_ptr<ecore::EOperation> m_actionActivation_Operation_addPinActivation_PinActivation = nullptr;std::shared_ptr<ecore::EOperation> m_actionActivation_Operation_completeAction = nullptr;std::shared_ptr<ecore::EOperation> m_structuredActivityNodeActivation_Operation_completeAction = nullptr;std::shared_ptr<ecore::EOperation> m_structuredActivityNodeActivation_Operation_createEdgeInstances = nullptr;std::shared_ptr<ecore::EOperation> m_actionActivation_Operation_createNodeActivations = nullptr;std::shared_ptr<ecore::EOperation> m_structuredActivityNodeActivation_Operation_createNodeActivations = nullptr;std::shared_ptr<ecore::EOperation> m_destroyObjectActionActivation_Operation_destroyObject_EJavaObject_EBoolean = nullptr;std::shared_ptr<ecore::EOperation> m_actionActivation_Operation_doAction = nullptr;std::shared_ptr<ecore::EOperation> m_addStructuralFeatureValueActionActivation_Operation_doAction = nullptr;std::shared_ptr<ecore::EOperation> m_callActionActivation_Operation_doAction = nullptr;std::shared_ptr<ecore::EOperation> m_clearStructuralFeatureActionActivation_Operation_doAction = nullptr;std::shared_ptr<ecore::EOperation> m_createObjectActionActivation_Operation_doAction = nullptr;std::shared_ptr<ecore::EOperation> m_destroyObjectActionActivation_Operation_doAction = nullptr;std::shared_ptr<ecore::EOperation> m_expansionRegionActivation_Operation_doAction = nullptr;std::shared_ptr<ecore::EOperation> m_readIsClassifiedObjectActionActivation_Operation_doAction = nullptr;std::shared_ptr<ecore::EOperation> m_readSelfActionActivation_Operation_doAction = nullptr;std::shared_ptr<ecore::EOperation> m_readStructuralFeatureActionActivation_Operation_doAction = nullptr;std::shared_ptr<ecore::EOperation> m_removeStructuralFeatureValueActionActivation_Operation_doAction = nullptr;std::shared_ptr<ecore::EOperation> m_structuredActivityNodeActivation_Operation_doAction = nullptr;std::shared_ptr<ecore::EOperation> m_valueSpecificationActionActivation_Operation_doAction = nullptr;std::shared_ptr<ecore::EOperation> m_callActionActivation_Operation_doCall_ParameterValue = nullptr;std::shared_ptr<ecore::EOperation> m_callBehaviorActionActivation_Operation_doCall_ParameterValue = nullptr;std::shared_ptr<ecore::EOperation> m_callOperationActionActivation_Operation_doCall_ParameterValue = nullptr;std::shared_ptr<ecore::EOperation> m_expansionRegionActivation_Operation_doOutput = nullptr;std::shared_ptr<ecore::EOperation> m_expansionRegionActivation_Operation_doStructuredActivity = nullptr;std::shared_ptr<ecore::EOperation> m_structuredActivityNodeActivation_Operation_doStructuredActivity = nullptr;std::shared_ptr<ecore::EOperation> m_actionActivation_Operation_fire_Token = nullptr;std::shared_ptr<ecore::EOperation> m_expansionNodeActivation_Operation_fire_Token = nullptr;std::shared_ptr<ecore::EOperation> m_pinActivation_Operation_fire_Token = nullptr;std::shared_ptr<ecore::EOperation> m_expansionActivationGroup_Operation_getActivityExecution = nullptr;std::shared_ptr<ecore::EOperation> m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature = nullptr;std::shared_ptr<ecore::EOperation> m_expansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode = nullptr;std::shared_ptr<ecore::EOperation> m_expansionNodeActivation_Operation_getExpansionRegionActivation = nullptr;std::shared_ptr<ecore::EOperation> m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_EJavaObject = nullptr;std::shared_ptr<ecore::EOperation> m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_EJavaObject = nullptr;std::shared_ptr<ecore::EOperation> m_expansionActivationGroup_Operation_getNodeActivation_ActivityNode = nullptr;std::shared_ptr<ecore::EOperation> m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode = nullptr;std::shared_ptr<ecore::EOperation> m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature = nullptr;std::shared_ptr<ecore::EOperation> m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin = nullptr;std::shared_ptr<ecore::EOperation> m_actionActivation_Operation_getTokens_InputPin = nullptr;std::shared_ptr<ecore::EOperation> m_actionActivation_Operation_isFirng = nullptr;std::shared_ptr<ecore::EOperation> m_actionActivation_Operation_isReady = nullptr;std::shared_ptr<ecore::EOperation> m_expansionNodeActivation_Operation_isReady = nullptr;std::shared_ptr<ecore::EOperation> m_inputPinActivation_Operation_isReady = nullptr;std::shared_ptr<ecore::EOperation> m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance = nullptr;std::shared_ptr<ecore::EOperation> m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance = nullptr;std::shared_ptr<ecore::EOperation> m_expansionRegionActivation_Operation_isSuspended = nullptr;std::shared_ptr<ecore::EOperation> m_structuredActivityNodeActivation_Operation_isSuspended = nullptr;std::shared_ptr<ecore::EOperation> m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode = nullptr;std::shared_ptr<ecore::EOperation> m_expansionRegionActivation_Operation_numberOfValues = nullptr;std::shared_ptr<ecore::EOperation> m_destroyObjectActionActivation_Operation_objectIsComposite_Element_Element = nullptr;std::shared_ptr<ecore::EOperation> m_writeStructuralFeatureActionActivation_Operation_position_EJavaObject_EInt = nullptr;std::shared_ptr<ecore::EOperation> m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_EJavaObject = nullptr;std::shared_ptr<ecore::EOperation> m_actionActivation_Operation_putToken_OutputPin_EJavaObject = nullptr;std::shared_ptr<ecore::EOperation> m_actionActivation_Operation_putTokens_OutputPin_EJavaObject = nullptr;std::shared_ptr<ecore::EOperation> m_expansionNodeActivation_Operation_receiveOffer = nullptr;std::shared_ptr<ecore::EOperation> m_inputPinActivation_Operation_receiveOffer = nullptr;std::shared_ptr<ecore::EOperation> m_expansionActivationGroup_Operation_resume_ActivityNodeActivation = nullptr;std::shared_ptr<ecore::EOperation> m_expansionRegionActivation_Operation_resume_ExpansionActivationGroup = nullptr;std::shared_ptr<ecore::EOperation> m_structuredActivityNodeActivation_Operation_resume = nullptr;std::shared_ptr<ecore::EOperation> m_callBehaviorActionActivation_Operation_retrieveBehavior = nullptr;std::shared_ptr<ecore::EOperation> m_callOperationActionActivation_Operation_retrieveBehavior = nullptr;std::shared_ptr<ecore::EOperation> m_callActionActivation_Operation_retrieveCallParameters = nullptr;std::shared_ptr<ecore::EOperation> m_callBehaviorActionActivation_Operation_retrieveCallParameters = nullptr;std::shared_ptr<ecore::EOperation> m_callOperationActionActivation_Operation_retrieveCallParameters = nullptr;std::shared_ptr<ecore::EOperation> m_actionActivation_Operation_retrievePinActivation_Pin = nullptr;std::shared_ptr<ecore::EOperation> m_actionActivation_Operation_run = nullptr;std::shared_ptr<ecore::EOperation> m_expansionRegionActivation_Operation_runGroup_ExpansionActivationGroup = nullptr;std::shared_ptr<ecore::EOperation> m_expansionRegionActivation_Operation_runIterative = nullptr;std::shared_ptr<ecore::EOperation> m_expansionRegionActivation_Operation_runParallel = nullptr;std::shared_ptr<ecore::EOperation> m_actionActivation_Operation_sendOffers = nullptr;std::shared_ptr<ecore::EOperation> m_expansionRegionActivation_Operation_sendOffers = nullptr;std::shared_ptr<ecore::EOperation> m_expansionActivationGroup_Operation_suspend_ActivityNodeActivation = nullptr;std::shared_ptr<ecore::EOperation> m_actionActivation_Operation_takeOfferedTokens = nullptr;std::shared_ptr<ecore::EOperation> m_expansionRegionActivation_Operation_takeOfferedTokens = nullptr;std::shared_ptr<ecore::EOperation> m_pinActivation_Operation_takeOfferedTokens = nullptr;std::shared_ptr<ecore::EOperation> m_actionActivation_Operation_takeTokens_InputPin = nullptr;std::shared_ptr<ecore::EOperation> m_actionActivation_Operation_terminate = nullptr;std::shared_ptr<ecore::EOperation> m_callActionActivation_Operation_terminate = nullptr;std::shared_ptr<ecore::EOperation> m_expansionRegionActivation_Operation_terminate = nullptr;std::shared_ptr<ecore::EOperation> m_structuredActivityNodeActivation_Operation_terminate = nullptr;std::shared_ptr<ecore::EOperation> m_structuredActivityNodeActivation_Operation_terminateAll = nullptr;std::shared_ptr<ecore::EOperation> m_expansionRegionActivation_Operation_terminateGroup_ExpansionActivationGroup = nullptr;std::shared_ptr<ecore::EOperation> m_actionActivation_Operation_valueParticipatesInLink_EJavaObject_Element = nullptr;

			friend class ActionsPackage;

			static bool isInited;
			static ActionsPackage* create();
			bool isInitialized = false;
 			bool isCreated = false;

			virtual void init(std::shared_ptr<ecore::EPackage> package);

		public:
			void createPackageContents(std::shared_ptr<ecore::EPackage> package);
			void initializePackageContents();

		private:
			void createActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createAddStructuralFeatureValueActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createCallActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createCallBehaviorActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createCallOperationActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createClearStructuralFeatureActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createCreateObjectActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createDestroyObjectActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createExpansionActivationGroupContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createExpansionNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createExpansionRegionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createInputPinActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createInvocationActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createOutputPinActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createPinActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createReadIsClassifiedObjectActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createReadSelfActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createReadStructuralFeatureActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createRemoveStructuralFeatureValueActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createStructuralFeatureActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createStructuredActivityNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createValueSpecificationActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createValuesContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createWriteStructuralFeatureActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);

			void initializeActionActivationContent();
			void initializeAddStructuralFeatureValueActionActivationContent();
			void initializeCallActionActivationContent();
			void initializeCallBehaviorActionActivationContent();
			void initializeCallOperationActionActivationContent();
			void initializeClearStructuralFeatureActionActivationContent();
			void initializeCreateObjectActionActivationContent();
			void initializeDestroyObjectActionActivationContent();
			void initializeExpansionActivationGroupContent();
			void initializeExpansionNodeActivationContent();
			void initializeExpansionRegionActivationContent();
			void initializeInputPinActivationContent();
			void initializeInvocationActionActivationContent();
			void initializeOutputPinActivationContent();
			void initializePinActivationContent();
			void initializeReadIsClassifiedObjectActionActivationContent();
			void initializeReadSelfActionActivationContent();
			void initializeReadStructuralFeatureActionActivationContent();
			void initializeRemoveStructuralFeatureValueActionActivationContent();
			void initializeStructuralFeatureActionActivationContent();
			void initializeStructuredActivityNodeActivationContent();
			void initializeValueSpecificationActionActivationContent();
			void initializeValuesContent();
			void initializeWriteStructuralFeatureActionActivationContent();
			void initializePackageEDataTypes();



	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONSPACKAGEIMPL_HPP */
