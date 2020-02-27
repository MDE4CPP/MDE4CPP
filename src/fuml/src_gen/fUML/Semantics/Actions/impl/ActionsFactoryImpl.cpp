#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Actions/impl/AcceptCallActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/AcceptCallActionActivationsImpl.hpp"
#include "fUML/Semantics/Actions/impl/AcceptEventActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/AcceptEventActionEventAccepterImpl.hpp"
#include "fUML/Semantics/Actions/impl/ActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/AddStructuralFeatureValueActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/CallActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/CallBehaviorActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/CallOperationActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ClauseActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ClearAssociationActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ClearStructuralFeatureActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ConditionalNodeActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/CreateLinkActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/CreateObjectActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/DestroyLinkActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/DestroyObjectActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/InputPinActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/InvocationActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/LinkActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/LoopNodeActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/OutputPinActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/PinActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ReadExtentActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ReadIsClassifiedObjectActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ReadLinkActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ReadSelfActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ReadStructuralFeatureActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ReclassifyObjectActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ReduceActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/RemoveStructuralFeatureValueActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ReplyActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ReturnInformationImpl.hpp"
#include "fUML/Semantics/Actions/impl/SendSignalActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/StartClassifierBehaviorActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/StartObjectBehaviorActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/StructuralFeatureActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/StructuredActivityNodeActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/TestIdentityActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ValueSpecificationActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ValuesImpl.hpp"
#include "fUML/Semantics/Actions/impl/WriteLinkActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/WriteStructuralFeatureActionActivationImpl.hpp"

#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"


using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************

ActionsFactoryImpl::ActionsFactoryImpl()
{
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::AcceptCallActionActivation", ActionsPackage::ACCEPTCALLACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::AcceptCallActionActivations", ActionsPackage::ACCEPTCALLACTIONACTIVATIONS_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::AcceptEventActionActivation", ActionsPackage::ACCEPTEVENTACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::AcceptEventActionEventAccepter", ActionsPackage::ACCEPTEVENTACTIONEVENTACCEPTER_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::AddStructuralFeatureValueActionActivation", ActionsPackage::ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::CallBehaviorActionActivation", ActionsPackage::CALLBEHAVIORACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::CallOperationActionActivation", ActionsPackage::CALLOPERATIONACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ClauseActivation", ActionsPackage::CLAUSEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ClearAssociationActionActivation", ActionsPackage::CLEARASSOCIATIONACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ClearStructuralFeatureActionActivation", ActionsPackage::CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ConditionalNodeActivation", ActionsPackage::CONDITIONALNODEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::CreateLinkActionActivation", ActionsPackage::CREATELINKACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::CreateObjectActionActivation", ActionsPackage::CREATEOBJECTACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::DestroyLinkActionActivation", ActionsPackage::DESTROYLINKACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::DestroyObjectActionActivation", ActionsPackage::DESTROYOBJECTACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::InputPinActivation", ActionsPackage::INPUTPINACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::LoopNodeActivation", ActionsPackage::LOOPNODEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::OutputPinActivation", ActionsPackage::OUTPUTPINACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ReadExtentActionActivation", ActionsPackage::READEXTENTACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivation", ActionsPackage::READISCLASSIFIEDOBJECTACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ReadLinkActionActivation", ActionsPackage::READLINKACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ReadSelfActionActivation", ActionsPackage::READSELFACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ReadStructuralFeatureActionActivation", ActionsPackage::READSTRUCTURALFEATUREACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ReclassifyObjectActionActivation", ActionsPackage::RECLASSIFYOBJECTACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ReduceActionActivation", ActionsPackage::REDUCEACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::RemoveStructuralFeatureValueActivation", ActionsPackage::REMOVESTRUCTURALFEATUREVALUEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ReplyActionActivation", ActionsPackage::REPLYACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ReturnInformation", ActionsPackage::RETURNINFORMATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::SendSignalActionActivation", ActionsPackage::SENDSIGNALACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::StartClassifierBehaviorActionActivation", ActionsPackage::STARTCLASSIFIERBEHAVIORACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::StartObjectBehaviorActionActivation", ActionsPackage::STARTOBJECTBEHAVIORACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::StructuredActivityNodeActivation", ActionsPackage::STRUCTUREDACTIVITYNODEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::TestIdentityActionActivation", ActionsPackage::TESTIDENTITYACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ValueSpecificationActionActivation", ActionsPackage::VALUESPECIFICATIONACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::Values", ActionsPackage::VALUES_CLASS));
}

ActionsFactoryImpl::~ActionsFactoryImpl()
{
}

ActionsFactory* ActionsFactoryImpl::create()
{
	return new ActionsFactoryImpl();
}

//*********************************
// creators
//*********************************

std::shared_ptr<ecore::EObject> ActionsFactoryImpl::create(const int metaElementID, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	switch(metaElementID)
	{
		case ActionsPackage::ACCEPTCALLACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createAcceptCallActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::AcceptCallActionActivation>(this->createAcceptCallActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActionsPackage::ACCEPTCALLACTIONACTIVATIONS_CLASS:
		{
				return this->createAcceptCallActionActivations(metaElementID);
			
		}
		case ActionsPackage::ACCEPTEVENTACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createAcceptEventActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionActivation>(this->createAcceptEventActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActionsPackage::ACCEPTEVENTACTIONEVENTACCEPTER_CLASS:
		{
				return this->createAcceptEventActionEventAccepter(metaElementID);
			
		}
		case ActionsPackage::ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createAddStructuralFeatureValueActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::AddStructuralFeatureValueActionActivation>(this->createAddStructuralFeatureValueActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActionsPackage::CALLBEHAVIORACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCallBehaviorActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::CallBehaviorActionActivation>(this->createCallBehaviorActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActionsPackage::CALLOPERATIONACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCallOperationActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::CallOperationActionActivation>(this->createCallOperationActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActionsPackage::CLAUSEACTIVATION_CLASS:
		{
				return this->createClauseActivation(metaElementID);
			
		}
		case ActionsPackage::CLEARASSOCIATIONACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createClearAssociationActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::ClearAssociationActionActivation>(this->createClearAssociationActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActionsPackage::CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createClearStructuralFeatureActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::ClearStructuralFeatureActionActivation>(this->createClearStructuralFeatureActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActionsPackage::CONDITIONALNODEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createConditionalNodeActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::ConditionalNodeActivation>(this->createConditionalNodeActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActionsPackage::CREATELINKACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCreateLinkActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::CreateLinkActionActivation>(this->createCreateLinkActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActionsPackage::CREATEOBJECTACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCreateObjectActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::CreateObjectActionActivation>(this->createCreateObjectActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActionsPackage::DESTROYLINKACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createDestroyLinkActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::DestroyLinkActionActivation>(this->createDestroyLinkActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActionsPackage::DESTROYOBJECTACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createDestroyObjectActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::DestroyObjectActionActivation>(this->createDestroyObjectActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActionsPackage::INPUTPINACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createInputPinActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::InputPinActivation>(this->createInputPinActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActionsPackage::LOOPNODEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createLoopNodeActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::LoopNodeActivation>(this->createLoopNodeActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActionsPackage::OUTPUTPINACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createOutputPinActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation>(this->createOutputPinActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActionsPackage::READEXTENTACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createReadExtentActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::ReadExtentActionActivation>(this->createReadExtentActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActionsPackage::READISCLASSIFIEDOBJECTACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createReadIsClassifiedObjectActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivation>(this->createReadIsClassifiedObjectActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActionsPackage::READLINKACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createReadLinkActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::ReadLinkActionActivation>(this->createReadLinkActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActionsPackage::READSELFACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createReadSelfActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::ReadSelfActionActivation>(this->createReadSelfActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActionsPackage::READSTRUCTURALFEATUREACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createReadStructuralFeatureActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::ReadStructuralFeatureActionActivation>(this->createReadStructuralFeatureActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActionsPackage::RECLASSIFYOBJECTACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createReclassifyObjectActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::ReclassifyObjectActionActivation>(this->createReclassifyObjectActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActionsPackage::REDUCEACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createReduceActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::ReduceActionActivation>(this->createReduceActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActionsPackage::REMOVESTRUCTURALFEATUREVALUEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createRemoveStructuralFeatureValueActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActivation>(this->createRemoveStructuralFeatureValueActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActionsPackage::REPLYACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createReplyActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::ReplyActionActivation>(this->createReplyActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActionsPackage::RETURNINFORMATION_CLASS:
		{
				return this->createReturnInformation(metaElementID);
			
		}
		case ActionsPackage::SENDSIGNALACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createSendSignalActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::SendSignalActionActivation>(this->createSendSignalActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActionsPackage::STARTCLASSIFIERBEHAVIORACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createStartClassifierBehaviorActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::StartClassifierBehaviorActionActivation>(this->createStartClassifierBehaviorActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActionsPackage::STARTOBJECTBEHAVIORACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createStartObjectBehaviorActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::StartObjectBehaviorActionActivation>(this->createStartObjectBehaviorActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActionsPackage::STRUCTUREDACTIVITYNODEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createStructuredActivityNodeActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation>(this->createStructuredActivityNodeActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActionsPackage::TESTIDENTITYACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createTestIdentityActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::TestIdentityActionActivation>(this->createTestIdentityActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActionsPackage::VALUESPECIFICATIONACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createValueSpecificationActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::ValueSpecificationActionActivation>(this->createValueSpecificationActionActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActionsPackage::VALUES_CLASS:
		{
				return this->createValues(metaElementID);
			
		}
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << metaElementID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<ecore::EObject> ActionsFactoryImpl::create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}
	int _elementID = _class->getMetaElementID();
	return create(_elementID, container, referenceID);
}

std::shared_ptr<ecore::EObject> ActionsFactoryImpl::create(std::string _className, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	auto iter = m_idMap.find(_className);
	if(iter != m_idMap.end())
    {
		//get the ID
        int id = iter->second;
		return create(id,container,referenceID);
    }
    return nullptr;
}

std::shared_ptr<fUML::Semantics::Actions::AcceptCallActionActivation> ActionsFactoryImpl::createAcceptCallActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::AcceptCallActionActivationImpl> element(new fUML::Semantics::Actions::AcceptCallActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisAcceptCallActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::AcceptCallActionActivation> ActionsFactoryImpl::createAcceptCallActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::AcceptCallActionActivationImpl> element(new fUML::Semantics::Actions::AcceptCallActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisAcceptCallActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::AcceptCallActionActivations> ActionsFactoryImpl::createAcceptCallActionActivations(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::AcceptCallActionActivationsImpl> element(new fUML::Semantics::Actions::AcceptCallActionActivationsImpl());
	element->setMetaElementID(metaElementID);
	element->setThisAcceptCallActionActivationsPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionActivation> ActionsFactoryImpl::createAcceptEventActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionActivationImpl> element(new fUML::Semantics::Actions::AcceptEventActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisAcceptEventActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionActivation> ActionsFactoryImpl::createAcceptEventActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionActivationImpl> element(new fUML::Semantics::Actions::AcceptEventActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisAcceptEventActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionEventAccepter> ActionsFactoryImpl::createAcceptEventActionEventAccepter(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionEventAccepterImpl> element(new fUML::Semantics::Actions::AcceptEventActionEventAccepterImpl());
	element->setMetaElementID(metaElementID);
	element->setThisAcceptEventActionEventAccepterPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::AddStructuralFeatureValueActionActivation> ActionsFactoryImpl::createAddStructuralFeatureValueActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl> element(new fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisAddStructuralFeatureValueActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::AddStructuralFeatureValueActionActivation> ActionsFactoryImpl::createAddStructuralFeatureValueActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl> element(new fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisAddStructuralFeatureValueActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::CallBehaviorActionActivation> ActionsFactoryImpl::createCallBehaviorActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::CallBehaviorActionActivationImpl> element(new fUML::Semantics::Actions::CallBehaviorActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCallBehaviorActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::CallBehaviorActionActivation> ActionsFactoryImpl::createCallBehaviorActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::CallBehaviorActionActivationImpl> element(new fUML::Semantics::Actions::CallBehaviorActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisCallBehaviorActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::CallOperationActionActivation> ActionsFactoryImpl::createCallOperationActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::CallOperationActionActivationImpl> element(new fUML::Semantics::Actions::CallOperationActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCallOperationActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::CallOperationActionActivation> ActionsFactoryImpl::createCallOperationActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::CallOperationActionActivationImpl> element(new fUML::Semantics::Actions::CallOperationActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisCallOperationActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::ClauseActivation> ActionsFactoryImpl::createClauseActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ClauseActivationImpl> element(new fUML::Semantics::Actions::ClauseActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisClauseActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ClearAssociationActionActivation> ActionsFactoryImpl::createClearAssociationActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ClearAssociationActionActivationImpl> element(new fUML::Semantics::Actions::ClearAssociationActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisClearAssociationActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ClearAssociationActionActivation> ActionsFactoryImpl::createClearAssociationActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ClearAssociationActionActivationImpl> element(new fUML::Semantics::Actions::ClearAssociationActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisClearAssociationActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::ClearStructuralFeatureActionActivation> ActionsFactoryImpl::createClearStructuralFeatureActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ClearStructuralFeatureActionActivationImpl> element(new fUML::Semantics::Actions::ClearStructuralFeatureActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisClearStructuralFeatureActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ClearStructuralFeatureActionActivation> ActionsFactoryImpl::createClearStructuralFeatureActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ClearStructuralFeatureActionActivationImpl> element(new fUML::Semantics::Actions::ClearStructuralFeatureActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisClearStructuralFeatureActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::ConditionalNodeActivation> ActionsFactoryImpl::createConditionalNodeActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ConditionalNodeActivationImpl> element(new fUML::Semantics::Actions::ConditionalNodeActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisConditionalNodeActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ConditionalNodeActivation> ActionsFactoryImpl::createConditionalNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ConditionalNodeActivationImpl> element(new fUML::Semantics::Actions::ConditionalNodeActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisConditionalNodeActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::CreateLinkActionActivation> ActionsFactoryImpl::createCreateLinkActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::CreateLinkActionActivationImpl> element(new fUML::Semantics::Actions::CreateLinkActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCreateLinkActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::CreateLinkActionActivation> ActionsFactoryImpl::createCreateLinkActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::CreateLinkActionActivationImpl> element(new fUML::Semantics::Actions::CreateLinkActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisCreateLinkActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::CreateObjectActionActivation> ActionsFactoryImpl::createCreateObjectActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::CreateObjectActionActivationImpl> element(new fUML::Semantics::Actions::CreateObjectActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCreateObjectActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::CreateObjectActionActivation> ActionsFactoryImpl::createCreateObjectActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::CreateObjectActionActivationImpl> element(new fUML::Semantics::Actions::CreateObjectActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisCreateObjectActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::DestroyLinkActionActivation> ActionsFactoryImpl::createDestroyLinkActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::DestroyLinkActionActivationImpl> element(new fUML::Semantics::Actions::DestroyLinkActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDestroyLinkActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::DestroyLinkActionActivation> ActionsFactoryImpl::createDestroyLinkActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::DestroyLinkActionActivationImpl> element(new fUML::Semantics::Actions::DestroyLinkActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisDestroyLinkActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::DestroyObjectActionActivation> ActionsFactoryImpl::createDestroyObjectActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::DestroyObjectActionActivationImpl> element(new fUML::Semantics::Actions::DestroyObjectActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDestroyObjectActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::DestroyObjectActionActivation> ActionsFactoryImpl::createDestroyObjectActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::DestroyObjectActionActivationImpl> element(new fUML::Semantics::Actions::DestroyObjectActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisDestroyObjectActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> ActionsFactoryImpl::createInputPinActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::InputPinActivationImpl> element(new fUML::Semantics::Actions::InputPinActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisInputPinActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> ActionsFactoryImpl::createInputPinActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::InputPinActivationImpl> element(new fUML::Semantics::Actions::InputPinActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisInputPinActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::LoopNodeActivation> ActionsFactoryImpl::createLoopNodeActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::LoopNodeActivationImpl> element(new fUML::Semantics::Actions::LoopNodeActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLoopNodeActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::LoopNodeActivation> ActionsFactoryImpl::createLoopNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::LoopNodeActivationImpl> element(new fUML::Semantics::Actions::LoopNodeActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisLoopNodeActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> ActionsFactoryImpl::createOutputPinActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::OutputPinActivationImpl> element(new fUML::Semantics::Actions::OutputPinActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisOutputPinActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> ActionsFactoryImpl::createOutputPinActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::OutputPinActivationImpl> element(new fUML::Semantics::Actions::OutputPinActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisOutputPinActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::ReadExtentActionActivation> ActionsFactoryImpl::createReadExtentActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReadExtentActionActivationImpl> element(new fUML::Semantics::Actions::ReadExtentActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReadExtentActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ReadExtentActionActivation> ActionsFactoryImpl::createReadExtentActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReadExtentActionActivationImpl> element(new fUML::Semantics::Actions::ReadExtentActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisReadExtentActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivation> ActionsFactoryImpl::createReadIsClassifiedObjectActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivationImpl> element(new fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReadIsClassifiedObjectActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivation> ActionsFactoryImpl::createReadIsClassifiedObjectActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivationImpl> element(new fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisReadIsClassifiedObjectActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::ReadLinkActionActivation> ActionsFactoryImpl::createReadLinkActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReadLinkActionActivationImpl> element(new fUML::Semantics::Actions::ReadLinkActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReadLinkActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ReadLinkActionActivation> ActionsFactoryImpl::createReadLinkActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReadLinkActionActivationImpl> element(new fUML::Semantics::Actions::ReadLinkActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisReadLinkActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::ReadSelfActionActivation> ActionsFactoryImpl::createReadSelfActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReadSelfActionActivationImpl> element(new fUML::Semantics::Actions::ReadSelfActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReadSelfActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ReadSelfActionActivation> ActionsFactoryImpl::createReadSelfActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReadSelfActionActivationImpl> element(new fUML::Semantics::Actions::ReadSelfActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisReadSelfActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::ReadStructuralFeatureActionActivation> ActionsFactoryImpl::createReadStructuralFeatureActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReadStructuralFeatureActionActivationImpl> element(new fUML::Semantics::Actions::ReadStructuralFeatureActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReadStructuralFeatureActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ReadStructuralFeatureActionActivation> ActionsFactoryImpl::createReadStructuralFeatureActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReadStructuralFeatureActionActivationImpl> element(new fUML::Semantics::Actions::ReadStructuralFeatureActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisReadStructuralFeatureActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::ReclassifyObjectActionActivation> ActionsFactoryImpl::createReclassifyObjectActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReclassifyObjectActionActivationImpl> element(new fUML::Semantics::Actions::ReclassifyObjectActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReclassifyObjectActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ReclassifyObjectActionActivation> ActionsFactoryImpl::createReclassifyObjectActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReclassifyObjectActionActivationImpl> element(new fUML::Semantics::Actions::ReclassifyObjectActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisReclassifyObjectActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::ReduceActionActivation> ActionsFactoryImpl::createReduceActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReduceActionActivationImpl> element(new fUML::Semantics::Actions::ReduceActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReduceActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ReduceActionActivation> ActionsFactoryImpl::createReduceActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReduceActionActivationImpl> element(new fUML::Semantics::Actions::ReduceActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisReduceActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActivation> ActionsFactoryImpl::createRemoveStructuralFeatureValueActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActivationImpl> element(new fUML::Semantics::Actions::RemoveStructuralFeatureValueActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisRemoveStructuralFeatureValueActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActivation> ActionsFactoryImpl::createRemoveStructuralFeatureValueActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActivationImpl> element(new fUML::Semantics::Actions::RemoveStructuralFeatureValueActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisRemoveStructuralFeatureValueActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::ReplyActionActivation> ActionsFactoryImpl::createReplyActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReplyActionActivationImpl> element(new fUML::Semantics::Actions::ReplyActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReplyActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ReplyActionActivation> ActionsFactoryImpl::createReplyActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReplyActionActivationImpl> element(new fUML::Semantics::Actions::ReplyActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisReplyActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::ReturnInformation> ActionsFactoryImpl::createReturnInformation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReturnInformationImpl> element(new fUML::Semantics::Actions::ReturnInformationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReturnInformationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::SendSignalActionActivation> ActionsFactoryImpl::createSendSignalActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::SendSignalActionActivationImpl> element(new fUML::Semantics::Actions::SendSignalActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisSendSignalActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::SendSignalActionActivation> ActionsFactoryImpl::createSendSignalActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::SendSignalActionActivationImpl> element(new fUML::Semantics::Actions::SendSignalActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisSendSignalActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::StartClassifierBehaviorActionActivation> ActionsFactoryImpl::createStartClassifierBehaviorActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::StartClassifierBehaviorActionActivationImpl> element(new fUML::Semantics::Actions::StartClassifierBehaviorActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisStartClassifierBehaviorActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::StartClassifierBehaviorActionActivation> ActionsFactoryImpl::createStartClassifierBehaviorActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::StartClassifierBehaviorActionActivationImpl> element(new fUML::Semantics::Actions::StartClassifierBehaviorActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisStartClassifierBehaviorActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::StartObjectBehaviorActionActivation> ActionsFactoryImpl::createStartObjectBehaviorActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::StartObjectBehaviorActionActivationImpl> element(new fUML::Semantics::Actions::StartObjectBehaviorActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisStartObjectBehaviorActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::StartObjectBehaviorActionActivation> ActionsFactoryImpl::createStartObjectBehaviorActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::StartObjectBehaviorActionActivationImpl> element(new fUML::Semantics::Actions::StartObjectBehaviorActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisStartObjectBehaviorActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> ActionsFactoryImpl::createStructuredActivityNodeActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivationImpl> element(new fUML::Semantics::Actions::StructuredActivityNodeActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisStructuredActivityNodeActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> ActionsFactoryImpl::createStructuredActivityNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivationImpl> element(new fUML::Semantics::Actions::StructuredActivityNodeActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisStructuredActivityNodeActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::TestIdentityActionActivation> ActionsFactoryImpl::createTestIdentityActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::TestIdentityActionActivationImpl> element(new fUML::Semantics::Actions::TestIdentityActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisTestIdentityActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::TestIdentityActionActivation> ActionsFactoryImpl::createTestIdentityActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::TestIdentityActionActivationImpl> element(new fUML::Semantics::Actions::TestIdentityActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisTestIdentityActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::ValueSpecificationActionActivation> ActionsFactoryImpl::createValueSpecificationActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ValueSpecificationActionActivationImpl> element(new fUML::Semantics::Actions::ValueSpecificationActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisValueSpecificationActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ValueSpecificationActionActivation> ActionsFactoryImpl::createValueSpecificationActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ValueSpecificationActionActivationImpl> element(new fUML::Semantics::Actions::ValueSpecificationActionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisValueSpecificationActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::Values> ActionsFactoryImpl::createValues(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ValuesImpl> element(new fUML::Semantics::Actions::ValuesImpl());
	element->setMetaElementID(metaElementID);
	element->setThisValuesPtr(element);
	return element;
}

