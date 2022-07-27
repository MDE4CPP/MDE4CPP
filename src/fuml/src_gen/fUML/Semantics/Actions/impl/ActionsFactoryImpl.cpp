#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
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

#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Activities/ObjectToken.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"


using namespace fUML::Semantics::Actions;

std::shared_ptr<ActionsFactory> ActionsFactory::eInstance()
{
	static std::shared_ptr<ActionsFactory> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(ActionsFactoryImpl::create());
	}	
	return instance;
}

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
				return std::shared_ptr<fUML::Semantics::Actions::AcceptCallActionActivation>(this->createAcceptCallActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActionsPackage::ACCEPTCALLACTIONACTIVATIONS_CLASS:
		{
				return this->createAcceptCallActionActivations(metaElementID);
			
			break;
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
				return std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionActivation>(this->createAcceptEventActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActionsPackage::ACCEPTEVENTACTIONEVENTACCEPTER_CLASS:
		{
				return this->createAcceptEventActionEventAccepter(metaElementID);
			
			break;
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
				return std::shared_ptr<fUML::Semantics::Actions::AddStructuralFeatureValueActionActivation>(this->createAddStructuralFeatureValueActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
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
				return std::shared_ptr<fUML::Semantics::Actions::CallBehaviorActionActivation>(this->createCallBehaviorActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
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
				return std::shared_ptr<fUML::Semantics::Actions::CallOperationActionActivation>(this->createCallOperationActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActionsPackage::CLAUSEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createClauseActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Actions::ConditionalNodeActivation> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Actions::ConditionalNodeActivation>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::ClauseActivation>(this->createClauseActivation_as_clauseActivations_in_ConditionalNodeActivation(castedContainer,metaElementID));
			}
			break;
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
				return std::shared_ptr<fUML::Semantics::Actions::ClearAssociationActionActivation>(this->createClearAssociationActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
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
				return std::shared_ptr<fUML::Semantics::Actions::ClearStructuralFeatureActionActivation>(this->createClearStructuralFeatureActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
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
				return std::shared_ptr<fUML::Semantics::Actions::ConditionalNodeActivation>(this->createConditionalNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
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
				return std::shared_ptr<fUML::Semantics::Actions::CreateLinkActionActivation>(this->createCreateLinkActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
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
				return std::shared_ptr<fUML::Semantics::Actions::CreateObjectActionActivation>(this->createCreateObjectActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
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
				return std::shared_ptr<fUML::Semantics::Actions::DestroyLinkActionActivation>(this->createDestroyLinkActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
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
				return std::shared_ptr<fUML::Semantics::Actions::DestroyObjectActionActivation>(this->createDestroyObjectActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActionsPackage::INPUTPINACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createInputPinActivation(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//InputPinActivation has inputPinActivation as a containment
					case  fUML::Semantics::Actions::ActionsPackage::ACTIONACTIVATION_ATTRIBUTE_INPUTPINACTIVATION:	
					{
						std::shared_ptr<fUML::Semantics::Actions::ActionActivation> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Actions::ActionActivation> (container);;
						return this->createInputPinActivation_as_inputPinActivation_in_ActionActivation(castedContainer,metaElementID);
					}
					//InputPinActivation has nodeActivations as a containment
					case  fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_NODEACTIVATIONS:	
					{
						std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup> (container);
						return this->createInputPinActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
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
				return std::shared_ptr<fUML::Semantics::Actions::LoopNodeActivation>(this->createLoopNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActionsPackage::OUTPUTPINACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createOutputPinActivation(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//OutputPinActivation has nodeActivations as a containment
					case  fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_NODEACTIVATIONS:	
					{
						std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup> (container);
						return this->createOutputPinActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID);
					}
					//OutputPinActivation has outputPinActivation as a containment
					case  fUML::Semantics::Actions::ActionsPackage::ACTIONACTIVATION_ATTRIBUTE_OUTPUTPINACTIVATION:	
					{
						std::shared_ptr<fUML::Semantics::Actions::ActionActivation> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Actions::ActionActivation> (container);;
						return this->createOutputPinActivation_as_outputPinActivation_in_ActionActivation(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
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
				return std::shared_ptr<fUML::Semantics::Actions::ReadExtentActionActivation>(this->createReadExtentActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
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
				return std::shared_ptr<fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivation>(this->createReadIsClassifiedObjectActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
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
				return std::shared_ptr<fUML::Semantics::Actions::ReadLinkActionActivation>(this->createReadLinkActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
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
				return std::shared_ptr<fUML::Semantics::Actions::ReadSelfActionActivation>(this->createReadSelfActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
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
				return std::shared_ptr<fUML::Semantics::Actions::ReadStructuralFeatureActionActivation>(this->createReadStructuralFeatureActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
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
				return std::shared_ptr<fUML::Semantics::Actions::ReclassifyObjectActionActivation>(this->createReclassifyObjectActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
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
				return std::shared_ptr<fUML::Semantics::Actions::ReduceActionActivation>(this->createReduceActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
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
				return std::shared_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActivation>(this->createRemoveStructuralFeatureValueActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
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
				return std::shared_ptr<fUML::Semantics::Actions::ReplyActionActivation>(this->createReplyActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActionsPackage::RETURNINFORMATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createReturnInformation(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ReturnInformation has value as a containment
					case  fUML::Semantics::Activities::ActivitiesPackage::OBJECTTOKEN_ATTRIBUTE_VALUE:	
					{
						std::shared_ptr<fUML::Semantics::Activities::ObjectToken> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ObjectToken> (container);;
						return this->createReturnInformation_as_value_in_ObjectToken(castedContainer,metaElementID);
					}
					//ReturnInformation has values as a containment
					case  fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::FeatureValue> (container);;
						return this->createReturnInformation_as_values_in_FeatureValue(castedContainer,metaElementID);
					}
					//ReturnInformation has values as a containment
					case  fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue> (container);;
						return this->createReturnInformation_as_values_in_ParameterValue(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
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
				return std::shared_ptr<fUML::Semantics::Actions::SendSignalActionActivation>(this->createSendSignalActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
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
				return std::shared_ptr<fUML::Semantics::Actions::StartClassifierBehaviorActionActivation>(this->createStartClassifierBehaviorActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
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
				return std::shared_ptr<fUML::Semantics::Actions::StartObjectBehaviorActionActivation>(this->createStartObjectBehaviorActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
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
				return std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation>(this->createStructuredActivityNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
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
				return std::shared_ptr<fUML::Semantics::Actions::TestIdentityActionActivation>(this->createTestIdentityActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
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
				return std::shared_ptr<fUML::Semantics::Actions::ValueSpecificationActionActivation>(this->createValueSpecificationActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActionsPackage::VALUES_CLASS:
		{
			if (nullptr == container)
			{
				return this->createValues(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Actions::LoopNodeActivation> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Actions::LoopNodeActivation>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::Values>(this->createValues_as_bodyOutputLists_in_LoopNodeActivation(castedContainer,metaElementID));
			}
			break;
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
std::shared_ptr<fUML::Semantics::Actions::AcceptCallActionActivation> ActionsFactoryImpl::createAcceptCallActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::AcceptCallActionActivationImpl> element(new fUML::Semantics::Actions::AcceptCallActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
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
std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionActivation> ActionsFactoryImpl::createAcceptEventActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionActivationImpl> element(new fUML::Semantics::Actions::AcceptEventActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
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
std::shared_ptr<fUML::Semantics::Actions::AddStructuralFeatureValueActionActivation> ActionsFactoryImpl::createAddStructuralFeatureValueActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl> element(new fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
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
std::shared_ptr<fUML::Semantics::Actions::CallBehaviorActionActivation> ActionsFactoryImpl::createCallBehaviorActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::CallBehaviorActionActivationImpl> element(new fUML::Semantics::Actions::CallBehaviorActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
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
std::shared_ptr<fUML::Semantics::Actions::CallOperationActionActivation> ActionsFactoryImpl::createCallOperationActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::CallOperationActionActivationImpl> element(new fUML::Semantics::Actions::CallOperationActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
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
std::shared_ptr<fUML::Semantics::Actions::ClauseActivation> ActionsFactoryImpl::createClauseActivation_as_clauseActivations_in_ConditionalNodeActivation(std::shared_ptr<fUML::Semantics::Actions::ConditionalNodeActivation> par_ConditionalNodeActivation, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ClauseActivationImpl> element(new fUML::Semantics::Actions::ClauseActivationImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ConditionalNodeActivation)
	{
		par_ConditionalNodeActivation->getClauseActivations()->push_back(element);
	}
	
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
std::shared_ptr<fUML::Semantics::Actions::ClearAssociationActionActivation> ActionsFactoryImpl::createClearAssociationActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ClearAssociationActionActivationImpl> element(new fUML::Semantics::Actions::ClearAssociationActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
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
std::shared_ptr<fUML::Semantics::Actions::ClearStructuralFeatureActionActivation> ActionsFactoryImpl::createClearStructuralFeatureActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ClearStructuralFeatureActionActivationImpl> element(new fUML::Semantics::Actions::ClearStructuralFeatureActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
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
std::shared_ptr<fUML::Semantics::Actions::ConditionalNodeActivation> ActionsFactoryImpl::createConditionalNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ConditionalNodeActivationImpl> element(new fUML::Semantics::Actions::ConditionalNodeActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
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
std::shared_ptr<fUML::Semantics::Actions::CreateLinkActionActivation> ActionsFactoryImpl::createCreateLinkActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::CreateLinkActionActivationImpl> element(new fUML::Semantics::Actions::CreateLinkActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
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
std::shared_ptr<fUML::Semantics::Actions::CreateObjectActionActivation> ActionsFactoryImpl::createCreateObjectActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::CreateObjectActionActivationImpl> element(new fUML::Semantics::Actions::CreateObjectActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
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
std::shared_ptr<fUML::Semantics::Actions::DestroyLinkActionActivation> ActionsFactoryImpl::createDestroyLinkActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::DestroyLinkActionActivationImpl> element(new fUML::Semantics::Actions::DestroyLinkActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
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
std::shared_ptr<fUML::Semantics::Actions::DestroyObjectActionActivation> ActionsFactoryImpl::createDestroyObjectActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::DestroyObjectActionActivationImpl> element(new fUML::Semantics::Actions::DestroyObjectActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
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
std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> ActionsFactoryImpl::createInputPinActivation_as_inputPinActivation_in_ActionActivation(std::shared_ptr<fUML::Semantics::Actions::ActionActivation> par_ActionActivation, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::InputPinActivationImpl> element(new fUML::Semantics::Actions::InputPinActivationImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ActionActivation)
	{
		par_ActionActivation->getInputPinActivation()->push_back(element);
	}
	
	element->setThisInputPinActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> ActionsFactoryImpl::createInputPinActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::InputPinActivationImpl> element(new fUML::Semantics::Actions::InputPinActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
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
std::shared_ptr<fUML::Semantics::Actions::LoopNodeActivation> ActionsFactoryImpl::createLoopNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::LoopNodeActivationImpl> element(new fUML::Semantics::Actions::LoopNodeActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
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
std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> ActionsFactoryImpl::createOutputPinActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::OutputPinActivationImpl> element(new fUML::Semantics::Actions::OutputPinActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	}
	
	element->setThisOutputPinActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> ActionsFactoryImpl::createOutputPinActivation_as_outputPinActivation_in_ActionActivation(std::shared_ptr<fUML::Semantics::Actions::ActionActivation> par_ActionActivation, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::OutputPinActivationImpl> element(new fUML::Semantics::Actions::OutputPinActivationImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ActionActivation)
	{
		par_ActionActivation->getOutputPinActivation()->push_back(element);
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
std::shared_ptr<fUML::Semantics::Actions::ReadExtentActionActivation> ActionsFactoryImpl::createReadExtentActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReadExtentActionActivationImpl> element(new fUML::Semantics::Actions::ReadExtentActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
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
std::shared_ptr<fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivation> ActionsFactoryImpl::createReadIsClassifiedObjectActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivationImpl> element(new fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
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
std::shared_ptr<fUML::Semantics::Actions::ReadLinkActionActivation> ActionsFactoryImpl::createReadLinkActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReadLinkActionActivationImpl> element(new fUML::Semantics::Actions::ReadLinkActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
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
std::shared_ptr<fUML::Semantics::Actions::ReadSelfActionActivation> ActionsFactoryImpl::createReadSelfActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReadSelfActionActivationImpl> element(new fUML::Semantics::Actions::ReadSelfActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
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
std::shared_ptr<fUML::Semantics::Actions::ReadStructuralFeatureActionActivation> ActionsFactoryImpl::createReadStructuralFeatureActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReadStructuralFeatureActionActivationImpl> element(new fUML::Semantics::Actions::ReadStructuralFeatureActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
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
std::shared_ptr<fUML::Semantics::Actions::ReclassifyObjectActionActivation> ActionsFactoryImpl::createReclassifyObjectActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReclassifyObjectActionActivationImpl> element(new fUML::Semantics::Actions::ReclassifyObjectActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
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
std::shared_ptr<fUML::Semantics::Actions::ReduceActionActivation> ActionsFactoryImpl::createReduceActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReduceActionActivationImpl> element(new fUML::Semantics::Actions::ReduceActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
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
std::shared_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActivation> ActionsFactoryImpl::createRemoveStructuralFeatureValueActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActivationImpl> element(new fUML::Semantics::Actions::RemoveStructuralFeatureValueActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
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
std::shared_ptr<fUML::Semantics::Actions::ReplyActionActivation> ActionsFactoryImpl::createReplyActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReplyActionActivationImpl> element(new fUML::Semantics::Actions::ReplyActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
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
std::shared_ptr<fUML::Semantics::Actions::ReturnInformation> ActionsFactoryImpl::createReturnInformation_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReturnInformationImpl> element(new fUML::Semantics::Actions::ReturnInformationImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ObjectToken)
	{
		par_ObjectToken->setValue(element);
	}
	
	element->setThisReturnInformationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::ReturnInformation> ActionsFactoryImpl::createReturnInformation_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReturnInformationImpl> element(new fUML::Semantics::Actions::ReturnInformationImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_FeatureValue)
	{
		par_FeatureValue->getValues()->push_back(element);
	}
	
	element->setThisReturnInformationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::ReturnInformation> ActionsFactoryImpl::createReturnInformation_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReturnInformationImpl> element(new fUML::Semantics::Actions::ReturnInformationImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ParameterValue)
	{
		par_ParameterValue->getValues()->push_back(element);
	}
	
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
std::shared_ptr<fUML::Semantics::Actions::SendSignalActionActivation> ActionsFactoryImpl::createSendSignalActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::SendSignalActionActivationImpl> element(new fUML::Semantics::Actions::SendSignalActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
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
std::shared_ptr<fUML::Semantics::Actions::StartClassifierBehaviorActionActivation> ActionsFactoryImpl::createStartClassifierBehaviorActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::StartClassifierBehaviorActionActivationImpl> element(new fUML::Semantics::Actions::StartClassifierBehaviorActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
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
std::shared_ptr<fUML::Semantics::Actions::StartObjectBehaviorActionActivation> ActionsFactoryImpl::createStartObjectBehaviorActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::StartObjectBehaviorActionActivationImpl> element(new fUML::Semantics::Actions::StartObjectBehaviorActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
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
std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> ActionsFactoryImpl::createStructuredActivityNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivationImpl> element(new fUML::Semantics::Actions::StructuredActivityNodeActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
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
std::shared_ptr<fUML::Semantics::Actions::TestIdentityActionActivation> ActionsFactoryImpl::createTestIdentityActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::TestIdentityActionActivationImpl> element(new fUML::Semantics::Actions::TestIdentityActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
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
std::shared_ptr<fUML::Semantics::Actions::ValueSpecificationActionActivation> ActionsFactoryImpl::createValueSpecificationActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ValueSpecificationActionActivationImpl> element(new fUML::Semantics::Actions::ValueSpecificationActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
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
std::shared_ptr<fUML::Semantics::Actions::Values> ActionsFactoryImpl::createValues_as_bodyOutputLists_in_LoopNodeActivation(std::shared_ptr<fUML::Semantics::Actions::LoopNodeActivation> par_LoopNodeActivation, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ValuesImpl> element(new fUML::Semantics::Actions::ValuesImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LoopNodeActivation)
	{
		par_LoopNodeActivation->getBodyOutputLists()->push_back(element);
	}
	
	element->setThisValuesPtr(element);
	return element;
	
}

