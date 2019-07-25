#include "PSCS/impl/PSCSFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"

#include "PSCS/PSCSPackage.hpp"
#include "PSCS/Semantics/Actions/impl/CS_AcceptCallActionActivationImpl.hpp"
#include "PSCS/Semantics/Actions/impl/CS_AcceptEventActionActivationImpl.hpp"
#include "PSCS/Semantics/Actions/impl/CS_AddStructuralFeatureValueActionActivationImpl.hpp"
#include "PSCS/Semantics/Actions/impl/CS_CallOperationActionActivationImpl.hpp"
#include "PSCS/Semantics/Actions/impl/CS_ClearStructuralFeatureActionActivationImpl.hpp"
#include "PSCS/Semantics/Actions/impl/CS_ConstructStrategyImpl.hpp"
#include "PSCS/Semantics/Actions/impl/CS_CreateLinkActionActivationImpl.hpp"
#include "PSCS/Semantics/Actions/impl/CS_CreateObjectActionActivationImpl.hpp"
#include "PSCS/Semantics/Actions/impl/CS_DefaultConstructStrategyImpl.hpp"
#include "PSCS/Semantics/Actions/impl/CS_ReadExtentActionActivationImpl.hpp"
#include "PSCS/Semantics/Actions/impl/CS_ReadSelfActionActivationImpl.hpp"
#include "PSCS/Semantics/Actions/impl/CS_RemoveStructuralFeatureValueActionActivationImpl.hpp"
#include "PSCS/Semantics/Actions/impl/CS_SendSignalActionActivationImpl.hpp"

#include "PSCS/Semantics/Classification/impl/CS_InstanceValueEvaluationImpl.hpp"

#include "PSCS/Semantics/CommonBehavior/impl/CS_CallEventExecutionImpl.hpp"
#include "PSCS/Semantics/CommonBehavior/impl/CS_EventOccurrenceImpl.hpp"

#include "PSCS/Semantics/Loci/impl/CS_ExecutionFactoryImpl.hpp"
#include "PSCS/Semantics/Loci/impl/CS_ExecutorImpl.hpp"
#include "PSCS/Semantics/Loci/impl/CS_LocusImpl.hpp"

#include "PSCS/Semantics/StructuredClassifiers/impl/CS_DefaultRequestPropagationStrategyImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_DispatchOperationOfInterfaceStrategyImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_InteractionPointImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_LinkImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_ObjectImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_ReferenceImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_RequestPropagationStrategyImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_StructuralFeatureOfInterfaceAccessStrategyImpl.hpp"

#include "PSCS/Semantics/Values/impl/CS_OpaqueExpressionEvaluationImpl.hpp"




using namespace PSCS;

//*********************************
// Constructor / Destructor
//*********************************

PSCSFactoryImpl::PSCSFactoryImpl()
{
	m_idMap.insert(std::make_pair("PSCS::Semantics::Actions::CS_AcceptCallActionActivation", PSCSPackage::CS_ACCEPTCALLACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::Actions::CS_AcceptEventActionActivation", PSCSPackage::CS_ACCEPTEVENTACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::Actions::CS_AddStructuralFeatureValueActionActivation", PSCSPackage::CS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::CommonBehavior::CS_CallEventExecution", PSCSPackage::CS_CALLEVENTEXECUTION_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::Actions::CS_CallOperationActionActivation", PSCSPackage::CS_CALLOPERATIONACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::Actions::CS_ClearStructuralFeatureActionActivation", PSCSPackage::CS_CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::Actions::CS_CreateLinkActionActivation", PSCSPackage::CS_CREATELINKACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::Actions::CS_CreateObjectActionActivation", PSCSPackage::CS_CREATEOBJECTACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::Actions::CS_DefaultConstructStrategy", PSCSPackage::CS_DEFAULTCONSTRUCTSTRATEGY_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::StructuredClassifiers::CS_DefaultRequestPropagationStrategy", PSCSPackage::CS_DEFAULTREQUESTPROPAGATIONSTRATEGY_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::StructuredClassifiers::CS_DispatchOperationOfInterfaceStrategy", PSCSPackage::CS_DISPATCHOPERATIONOFINTERFACESTRATEGY_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::CommonBehavior::CS_EventOccurrence", PSCSPackage::CS_EVENTOCCURRENCE_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::Loci::CS_ExecutionFactory", PSCSPackage::CS_EXECUTIONFACTORY_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::Loci::CS_Executor", PSCSPackage::CS_EXECUTOR_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::Classification::CS_InstanceValueEvaluation", PSCSPackage::CS_INSTANCEVALUEEVALUATION_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint", PSCSPackage::CS_INTERACTIONPOINT_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::StructuredClassifiers::CS_Link", PSCSPackage::CS_LINK_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::Loci::CS_Locus", PSCSPackage::CS_LOCUS_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::StructuredClassifiers::CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy", PSCSPackage::CS_NAMEBASED_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::StructuredClassifiers::CS_Object", PSCSPackage::CS_OBJECT_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::Values::CS_OpaqueExpressionEvaluation", PSCSPackage::CS_OPAQUEEXPRESSIONEVALUATION_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::Actions::CS_ReadExtentActionActivation", PSCSPackage::CS_READEXTENTACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::Actions::CS_ReadSelfActionActivation", PSCSPackage::CS_READSELFACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::StructuredClassifiers::CS_Reference", PSCSPackage::CS_REFERENCE_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::Actions::CS_RemoveStructuralFeatureValueActionActivation", PSCSPackage::CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::Actions::CS_SendSignalActionActivation", PSCSPackage::CS_SENDSIGNALACTIONACTIVATION_CLASS));
}

PSCSFactoryImpl::~PSCSFactoryImpl()
{
}

PSCSFactory* PSCSFactoryImpl::create()
{
	return new PSCSFactoryImpl();
}

//*********************************
// creators
//*********************************

std::shared_ptr<ecore::EObject> PSCSFactoryImpl::create(const int metaElementID, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	switch(metaElementID)
	{
		case PSCSPackage::CS_ACCEPTCALLACTIONACTIVATION_CLASS:
		{
				return this->createCS_AcceptCallActionActivation(metaElementID);
			
		}
		case PSCSPackage::CS_ACCEPTEVENTACTIONACTIVATION_CLASS:
		{
				return this->createCS_AcceptEventActionActivation(metaElementID);
			
		}
		case PSCSPackage::CS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS:
		{
				return this->createCS_AddStructuralFeatureValueActionActivation(metaElementID);
			
		}
		case PSCSPackage::CS_CALLEVENTEXECUTION_CLASS:
		{
				return this->createCS_CallEventExecution(metaElementID);
			
		}
		case PSCSPackage::CS_CALLOPERATIONACTIONACTIVATION_CLASS:
		{
				return this->createCS_CallOperationActionActivation(metaElementID);
			
		}
		case PSCSPackage::CS_CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS:
		{
				return this->createCS_ClearStructuralFeatureActionActivation(metaElementID);
			
		}
		case PSCSPackage::CS_CREATELINKACTIONACTIVATION_CLASS:
		{
				return this->createCS_CreateLinkActionActivation(metaElementID);
			
		}
		case PSCSPackage::CS_CREATEOBJECTACTIONACTIVATION_CLASS:
		{
				return this->createCS_CreateObjectActionActivation(metaElementID);
			
		}
		case PSCSPackage::CS_DEFAULTCONSTRUCTSTRATEGY_CLASS:
		{
				return this->createCS_DefaultConstructStrategy(metaElementID);
			
		}
		case PSCSPackage::CS_DEFAULTREQUESTPROPAGATIONSTRATEGY_CLASS:
		{
				return this->createCS_DefaultRequestPropagationStrategy(metaElementID);
			
		}
		case PSCSPackage::CS_DISPATCHOPERATIONOFINTERFACESTRATEGY_CLASS:
		{
				return this->createCS_DispatchOperationOfInterfaceStrategy(metaElementID);
			
		}
		case PSCSPackage::CS_EVENTOCCURRENCE_CLASS:
		{
				return this->createCS_EventOccurrence(metaElementID);
			
		}
		case PSCSPackage::CS_EXECUTIONFACTORY_CLASS:
		{
				return this->createCS_ExecutionFactory(metaElementID);
			
		}
		case PSCSPackage::CS_EXECUTOR_CLASS:
		{
				return this->createCS_Executor(metaElementID);
			
		}
		case PSCSPackage::CS_INSTANCEVALUEEVALUATION_CLASS:
		{
				return this->createCS_InstanceValueEvaluation(metaElementID);
			
		}
		case PSCSPackage::CS_INTERACTIONPOINT_CLASS:
		{
				return this->createCS_InteractionPoint(metaElementID);
			
		}
		case PSCSPackage::CS_LINK_CLASS:
		{
				return this->createCS_Link(metaElementID);
			
		}
		case PSCSPackage::CS_LOCUS_CLASS:
		{
				return this->createCS_Locus(metaElementID);
			
		}
		case PSCSPackage::CS_NAMEBASED_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_CLASS:
		{
				return this->createCS_NameBased_StructuralFeatureOfInterfaceAccessStrategy(metaElementID);
			
		}
		case PSCSPackage::CS_OBJECT_CLASS:
		{
				return this->createCS_Object(metaElementID);
			
		}
		case PSCSPackage::CS_OPAQUEEXPRESSIONEVALUATION_CLASS:
		{
				return this->createCS_OpaqueExpressionEvaluation(metaElementID);
			
		}
		case PSCSPackage::CS_READEXTENTACTIONACTIVATION_CLASS:
		{
				return this->createCS_ReadExtentActionActivation(metaElementID);
			
		}
		case PSCSPackage::CS_READSELFACTIONACTIVATION_CLASS:
		{
				return this->createCS_ReadSelfActionActivation(metaElementID);
			
		}
		case PSCSPackage::CS_REFERENCE_CLASS:
		{
				return this->createCS_Reference(metaElementID);
			
		}
		case PSCSPackage::CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS:
		{
				return this->createCS_RemoveStructuralFeatureValueActionActivation(metaElementID);
			
		}
		case PSCSPackage::CS_SENDSIGNALACTIONACTIVATION_CLASS:
		{
				return this->createCS_SendSignalActionActivation(metaElementID);
			
		}
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << metaElementID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<ecore::EObject> PSCSFactoryImpl::create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}
	int _elementID = _class->getMetaElementID();
	return create(_elementID, container, referenceID);
}

std::shared_ptr<ecore::EObject> PSCSFactoryImpl::create(std::string _className, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
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

std::shared_ptr<PSCS::Semantics::Actions::CS_AcceptCallActionActivation> PSCSFactoryImpl::createCS_AcceptCallActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_AcceptCallActionActivationImpl> element(new PSCS::Semantics::Actions::CS_AcceptCallActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_AcceptCallActionActivationPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::Actions::CS_AcceptEventActionActivation> PSCSFactoryImpl::createCS_AcceptEventActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_AcceptEventActionActivationImpl> element(new PSCS::Semantics::Actions::CS_AcceptEventActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_AcceptEventActionActivationPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::Actions::CS_AddStructuralFeatureValueActionActivation> PSCSFactoryImpl::createCS_AddStructuralFeatureValueActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_AddStructuralFeatureValueActionActivationImpl> element(new PSCS::Semantics::Actions::CS_AddStructuralFeatureValueActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_AddStructuralFeatureValueActionActivationPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_CallEventExecution> PSCSFactoryImpl::createCS_CallEventExecution(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_CallEventExecutionImpl> element(new PSCS::Semantics::CommonBehavior::CS_CallEventExecutionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_CallEventExecutionPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::Actions::CS_CallOperationActionActivation> PSCSFactoryImpl::createCS_CallOperationActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_CallOperationActionActivationImpl> element(new PSCS::Semantics::Actions::CS_CallOperationActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_CallOperationActionActivationPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::Actions::CS_ClearStructuralFeatureActionActivation> PSCSFactoryImpl::createCS_ClearStructuralFeatureActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_ClearStructuralFeatureActionActivationImpl> element(new PSCS::Semantics::Actions::CS_ClearStructuralFeatureActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_ClearStructuralFeatureActionActivationPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::Actions::CS_CreateLinkActionActivation> PSCSFactoryImpl::createCS_CreateLinkActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_CreateLinkActionActivationImpl> element(new PSCS::Semantics::Actions::CS_CreateLinkActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_CreateLinkActionActivationPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::Actions::CS_CreateObjectActionActivation> PSCSFactoryImpl::createCS_CreateObjectActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_CreateObjectActionActivationImpl> element(new PSCS::Semantics::Actions::CS_CreateObjectActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_CreateObjectActionActivationPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::Actions::CS_DefaultConstructStrategy> PSCSFactoryImpl::createCS_DefaultConstructStrategy(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_DefaultConstructStrategyImpl> element(new PSCS::Semantics::Actions::CS_DefaultConstructStrategyImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_DefaultConstructStrategyPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_DefaultRequestPropagationStrategy> PSCSFactoryImpl::createCS_DefaultRequestPropagationStrategy(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_DefaultRequestPropagationStrategyImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_DefaultRequestPropagationStrategyImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_DefaultRequestPropagationStrategyPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_DispatchOperationOfInterfaceStrategy> PSCSFactoryImpl::createCS_DispatchOperationOfInterfaceStrategy(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_DispatchOperationOfInterfaceStrategyImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_DispatchOperationOfInterfaceStrategyImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_DispatchOperationOfInterfaceStrategyPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_EventOccurrence> PSCSFactoryImpl::createCS_EventOccurrence(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_EventOccurrenceImpl> element(new PSCS::Semantics::CommonBehavior::CS_EventOccurrenceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_EventOccurrencePtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::Loci::CS_ExecutionFactory> PSCSFactoryImpl::createCS_ExecutionFactory(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Loci::CS_ExecutionFactoryImpl> element(new PSCS::Semantics::Loci::CS_ExecutionFactoryImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_ExecutionFactoryPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::Loci::CS_Executor> PSCSFactoryImpl::createCS_Executor(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Loci::CS_ExecutorImpl> element(new PSCS::Semantics::Loci::CS_ExecutorImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_ExecutorPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::Classification::CS_InstanceValueEvaluation> PSCSFactoryImpl::createCS_InstanceValueEvaluation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Classification::CS_InstanceValueEvaluationImpl> element(new PSCS::Semantics::Classification::CS_InstanceValueEvaluationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_InstanceValueEvaluationPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> PSCSFactoryImpl::createCS_InteractionPoint(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPointImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_InteractionPointImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_InteractionPointPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> PSCSFactoryImpl::createCS_Link(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_LinkImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_LinkImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_LinkPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::Loci::CS_Locus> PSCSFactoryImpl::createCS_Locus(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Loci::CS_LocusImpl> element(new PSCS::Semantics::Loci::CS_LocusImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_LocusPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy> PSCSFactoryImpl::createCS_NameBased_StructuralFeatureOfInterfaceAccessStrategy(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_NameBased_StructuralFeatureOfInterfaceAccessStrategyPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> PSCSFactoryImpl::createCS_Object(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_ObjectImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_ObjectImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_ObjectPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::Values::CS_OpaqueExpressionEvaluation> PSCSFactoryImpl::createCS_OpaqueExpressionEvaluation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Values::CS_OpaqueExpressionEvaluationImpl> element(new PSCS::Semantics::Values::CS_OpaqueExpressionEvaluationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_OpaqueExpressionEvaluationPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::Actions::CS_ReadExtentActionActivation> PSCSFactoryImpl::createCS_ReadExtentActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_ReadExtentActionActivationImpl> element(new PSCS::Semantics::Actions::CS_ReadExtentActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_ReadExtentActionActivationPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::Actions::CS_ReadSelfActionActivation> PSCSFactoryImpl::createCS_ReadSelfActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_ReadSelfActionActivationImpl> element(new PSCS::Semantics::Actions::CS_ReadSelfActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_ReadSelfActionActivationPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> PSCSFactoryImpl::createCS_Reference(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_ReferenceImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_ReferenceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_ReferencePtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::Actions::CS_RemoveStructuralFeatureValueActionActivation> PSCSFactoryImpl::createCS_RemoveStructuralFeatureValueActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_RemoveStructuralFeatureValueActionActivationImpl> element(new PSCS::Semantics::Actions::CS_RemoveStructuralFeatureValueActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_RemoveStructuralFeatureValueActionActivationPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::Actions::CS_SendSignalActionActivation> PSCSFactoryImpl::createCS_SendSignalActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_SendSignalActionActivationImpl> element(new PSCS::Semantics::Actions::CS_SendSignalActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_SendSignalActionActivationPtr(element);
	return element;
}

std::shared_ptr<PSCSPackage> PSCSFactoryImpl::getPSCSPackage() const
{
	return PSCSPackage::eInstance();
}
