//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONSFACTORYIMPL_HPP
#define FUML_SEMANTICS_ACTIONSFACTORYIMPL_HPP

// namespace macro header include
#include "fUML/fUML.hpp"

#include "ecore/impl/EFactoryImpl.hpp"

#include "fUML/Semantics/Actions/ActionsFactory.hpp"

namespace Actions 
{	class AcceptCallActionActivation;
	class AcceptCallActionActivations;
	class AcceptEventActionActivation;
	class AcceptEventActionEventAccepter;
	class ActionActivation;
	class AddStructuralFeatureValueActionActivation;
	class CallActionActivation;
	class CallBehaviorActionActivation;
	class CallOperationActionActivation;
	class ClauseActivation;
	class ClearAssociationActionActivation;
	class ClearStructuralFeatureActionActivation;
	class ConditionalNodeActivation;
	class CreateLinkActionActivation;
	class CreateObjectActionActivation;
	class DestroyLinkActionActivation;
	class DestroyObjectActionActivation;
	class InputPinActivation;
	class InvocationActionActivation;
	class LinkActionActivation;
	class LoopNodeActivation;
	class OutputPinActivation;
	class PinActivation;
	class ReadExtentActionActivation;
	class ReadIsClassifiedObjectActionActivation;
	class ReadLinkActionActivation;
	class ReadSelfActionActivation;
	class ReadStructuralFeatureActionActivation;
	class ReclassifyObjectActionActivation;
	class ReduceActionActivation;
	class RemoveStructuralFeatureValueActivation;
	class ReplyActionActivation;
	class ReturnInformation;
	class SendSignalActionActivation;
	class StartClassifierBehaviorActionActivation;
	class StartObjectBehaviorActionActivation;
	class StructuralFeatureActionActivation;
	class StructuredActivityNodeActivation;
	class TestIdentityActionActivation;
	class ValueSpecificationActionActivation;
	class Values;
	class WriteLinkActionActivation;
	class WriteStructuralFeatureActionActivation;
}

namespace fUML::Semantics::Actions 
{
	class FUML_API ActionsFactoryImpl : virtual public ecore::EFactoryImpl , virtual public ActionsFactory 
	{
		private:    
			ActionsFactoryImpl(ActionsFactoryImpl const&) = delete;
			ActionsFactoryImpl& operator=(ActionsFactoryImpl const&) = delete;

		protected:
			friend class ActionsFactory;
			// Constructor
			ActionsFactoryImpl();

		public:
			virtual ~ActionsFactoryImpl();
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const;

			//Creator functions
			 virtual std::shared_ptr<fUML::Semantics::Actions::AcceptCallActionActivation> createAcceptCallActionActivation(const int metaElementID = ActionsPackage::ACCEPTCALLACTIONACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::AcceptCallActionActivation> createAcceptCallActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::ACCEPTCALLACTIONACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::AcceptCallActionActivations> createAcceptCallActionActivations(const int metaElementID = ActionsPackage::ACCEPTCALLACTIONACTIVATIONS_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionActivation> createAcceptEventActionActivation(const int metaElementID = ActionsPackage::ACCEPTEVENTACTIONACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionActivation> createAcceptEventActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::ACCEPTEVENTACTIONACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionEventAccepter> createAcceptEventActionEventAccepter(const int metaElementID = ActionsPackage::ACCEPTEVENTACTIONEVENTACCEPTER_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::AddStructuralFeatureValueActionActivation> createAddStructuralFeatureValueActionActivation(const int metaElementID = ActionsPackage::ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::AddStructuralFeatureValueActionActivation> createAddStructuralFeatureValueActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::CallBehaviorActionActivation> createCallBehaviorActionActivation(const int metaElementID = ActionsPackage::CALLBEHAVIORACTIONACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::CallBehaviorActionActivation> createCallBehaviorActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::CALLBEHAVIORACTIONACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::CallOperationActionActivation> createCallOperationActionActivation(const int metaElementID = ActionsPackage::CALLOPERATIONACTIONACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::CallOperationActionActivation> createCallOperationActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::CALLOPERATIONACTIONACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::ClauseActivation> createClauseActivation(const int metaElementID = ActionsPackage::CLAUSEACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::ClauseActivation> createClauseActivation_as_clauseActivations_in_ConditionalNodeActivation(std::shared_ptr<fUML::Semantics::Actions::ConditionalNodeActivation> par_ConditionalNodeActivation, const int metaElementID = ActionsPackage::CLAUSEACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::ClearAssociationActionActivation> createClearAssociationActionActivation(const int metaElementID = ActionsPackage::CLEARASSOCIATIONACTIONACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::ClearAssociationActionActivation> createClearAssociationActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::CLEARASSOCIATIONACTIONACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::ClearStructuralFeatureActionActivation> createClearStructuralFeatureActionActivation(const int metaElementID = ActionsPackage::CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::ClearStructuralFeatureActionActivation> createClearStructuralFeatureActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::ConditionalNodeActivation> createConditionalNodeActivation(const int metaElementID = ActionsPackage::CONDITIONALNODEACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::ConditionalNodeActivation> createConditionalNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::CONDITIONALNODEACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::CreateLinkActionActivation> createCreateLinkActionActivation(const int metaElementID = ActionsPackage::CREATELINKACTIONACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::CreateLinkActionActivation> createCreateLinkActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::CREATELINKACTIONACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::CreateObjectActionActivation> createCreateObjectActionActivation(const int metaElementID = ActionsPackage::CREATEOBJECTACTIONACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::CreateObjectActionActivation> createCreateObjectActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::CREATEOBJECTACTIONACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::DestroyLinkActionActivation> createDestroyLinkActionActivation(const int metaElementID = ActionsPackage::DESTROYLINKACTIONACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::DestroyLinkActionActivation> createDestroyLinkActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::DESTROYLINKACTIONACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::DestroyObjectActionActivation> createDestroyObjectActionActivation(const int metaElementID = ActionsPackage::DESTROYOBJECTACTIONACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::DestroyObjectActionActivation> createDestroyObjectActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::DESTROYOBJECTACTIONACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> createInputPinActivation(const int metaElementID = ActionsPackage::INPUTPINACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> createInputPinActivation_as_inputPinActivation_in_ActionActivation(std::shared_ptr<fUML::Semantics::Actions::ActionActivation> par_ActionActivation, const int metaElementID = ActionsPackage::INPUTPINACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> createInputPinActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::INPUTPINACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::LoopNodeActivation> createLoopNodeActivation(const int metaElementID = ActionsPackage::LOOPNODEACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::LoopNodeActivation> createLoopNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::LOOPNODEACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> createOutputPinActivation(const int metaElementID = ActionsPackage::OUTPUTPINACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> createOutputPinActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::OUTPUTPINACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> createOutputPinActivation_as_outputPinActivation_in_ActionActivation(std::shared_ptr<fUML::Semantics::Actions::ActionActivation> par_ActionActivation, const int metaElementID = ActionsPackage::OUTPUTPINACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::ReadExtentActionActivation> createReadExtentActionActivation(const int metaElementID = ActionsPackage::READEXTENTACTIONACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::ReadExtentActionActivation> createReadExtentActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::READEXTENTACTIONACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivation> createReadIsClassifiedObjectActionActivation(const int metaElementID = ActionsPackage::READISCLASSIFIEDOBJECTACTIONACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivation> createReadIsClassifiedObjectActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::READISCLASSIFIEDOBJECTACTIONACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::ReadLinkActionActivation> createReadLinkActionActivation(const int metaElementID = ActionsPackage::READLINKACTIONACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::ReadLinkActionActivation> createReadLinkActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::READLINKACTIONACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::ReadSelfActionActivation> createReadSelfActionActivation(const int metaElementID = ActionsPackage::READSELFACTIONACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::ReadSelfActionActivation> createReadSelfActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::READSELFACTIONACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::ReadStructuralFeatureActionActivation> createReadStructuralFeatureActionActivation(const int metaElementID = ActionsPackage::READSTRUCTURALFEATUREACTIONACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::ReadStructuralFeatureActionActivation> createReadStructuralFeatureActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::READSTRUCTURALFEATUREACTIONACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::ReclassifyObjectActionActivation> createReclassifyObjectActionActivation(const int metaElementID = ActionsPackage::RECLASSIFYOBJECTACTIONACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::ReclassifyObjectActionActivation> createReclassifyObjectActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::RECLASSIFYOBJECTACTIONACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::ReduceActionActivation> createReduceActionActivation(const int metaElementID = ActionsPackage::REDUCEACTIONACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::ReduceActionActivation> createReduceActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::REDUCEACTIONACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActivation> createRemoveStructuralFeatureValueActivation(const int metaElementID = ActionsPackage::REMOVESTRUCTURALFEATUREVALUEACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActivation> createRemoveStructuralFeatureValueActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::REMOVESTRUCTURALFEATUREVALUEACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::ReplyActionActivation> createReplyActionActivation(const int metaElementID = ActionsPackage::REPLYACTIONACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::ReplyActionActivation> createReplyActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::REPLYACTIONACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::ReturnInformation> createReturnInformation(const int metaElementID = ActionsPackage::RETURNINFORMATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::SendSignalActionActivation> createSendSignalActionActivation(const int metaElementID = ActionsPackage::SENDSIGNALACTIONACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::SendSignalActionActivation> createSendSignalActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::SENDSIGNALACTIONACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::StartClassifierBehaviorActionActivation> createStartClassifierBehaviorActionActivation(const int metaElementID = ActionsPackage::STARTCLASSIFIERBEHAVIORACTIONACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::StartClassifierBehaviorActionActivation> createStartClassifierBehaviorActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::STARTCLASSIFIERBEHAVIORACTIONACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::StartObjectBehaviorActionActivation> createStartObjectBehaviorActionActivation(const int metaElementID = ActionsPackage::STARTOBJECTBEHAVIORACTIONACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::StartObjectBehaviorActionActivation> createStartObjectBehaviorActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::STARTOBJECTBEHAVIORACTIONACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> createStructuredActivityNodeActivation(const int metaElementID = ActionsPackage::STRUCTUREDACTIVITYNODEACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> createStructuredActivityNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::STRUCTUREDACTIVITYNODEACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::TestIdentityActionActivation> createTestIdentityActionActivation(const int metaElementID = ActionsPackage::TESTIDENTITYACTIONACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::TestIdentityActionActivation> createTestIdentityActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::TESTIDENTITYACTIONACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::ValueSpecificationActionActivation> createValueSpecificationActionActivation(const int metaElementID = ActionsPackage::VALUESPECIFICATIONACTIONACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::ValueSpecificationActionActivation> createValueSpecificationActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::VALUESPECIFICATIONACTIONACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::Values> createValues(const int metaElementID = ActionsPackage::VALUES_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::Values> createValues_as_bodyOutputLists_in_LoopNodeActivation(std::shared_ptr<fUML::Semantics::Actions::LoopNodeActivation> par_LoopNodeActivation, const int metaElementID = ActionsPackage::VALUES_CLASS) const ;
			 

		private:
			static ActionsFactory* create();
            std::map<std::string,int> m_idMap;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONSFACTORYIMPL_HPP */
