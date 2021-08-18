#include "PSCS/Semantics/Actions/impl/ActionsFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
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

#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"


using namespace PSCS::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************

ActionsFactoryImpl::ActionsFactoryImpl()
{
	m_idMap.insert(std::make_pair("PSCS::Semantics::Actions::CS_AcceptCallActionActivation", ActionsPackage::CS_ACCEPTCALLACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::Actions::CS_AcceptEventActionActivation", ActionsPackage::CS_ACCEPTEVENTACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::Actions::CS_AddStructuralFeatureValueActionActivation", ActionsPackage::CS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::Actions::CS_CallOperationActionActivation", ActionsPackage::CS_CALLOPERATIONACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::Actions::CS_ClearStructuralFeatureActionActivation", ActionsPackage::CS_CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::Actions::CS_CreateLinkActionActivation", ActionsPackage::CS_CREATELINKACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::Actions::CS_CreateObjectActionActivation", ActionsPackage::CS_CREATEOBJECTACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::Actions::CS_DefaultConstructStrategy", ActionsPackage::CS_DEFAULTCONSTRUCTSTRATEGY_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::Actions::CS_ReadExtentActionActivation", ActionsPackage::CS_READEXTENTACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::Actions::CS_ReadSelfActionActivation", ActionsPackage::CS_READSELFACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::Actions::CS_RemoveStructuralFeatureValueActionActivation", ActionsPackage::CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::Actions::CS_SendSignalActionActivation", ActionsPackage::CS_SENDSIGNALACTIONACTIVATION_CLASS));
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
		case ActionsPackage::CS_ACCEPTCALLACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCS_AcceptCallActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<PSCS::Semantics::Actions::CS_AcceptCallActionActivation>(this->createCS_AcceptCallActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActionsPackage::CS_ACCEPTEVENTACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCS_AcceptEventActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<PSCS::Semantics::Actions::CS_AcceptEventActionActivation>(this->createCS_AcceptEventActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActionsPackage::CS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCS_AddStructuralFeatureValueActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<PSCS::Semantics::Actions::CS_AddStructuralFeatureValueActionActivation>(this->createCS_AddStructuralFeatureValueActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActionsPackage::CS_CALLOPERATIONACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCS_CallOperationActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<PSCS::Semantics::Actions::CS_CallOperationActionActivation>(this->createCS_CallOperationActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActionsPackage::CS_CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCS_ClearStructuralFeatureActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<PSCS::Semantics::Actions::CS_ClearStructuralFeatureActionActivation>(this->createCS_ClearStructuralFeatureActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActionsPackage::CS_CREATELINKACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCS_CreateLinkActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<PSCS::Semantics::Actions::CS_CreateLinkActionActivation>(this->createCS_CreateLinkActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActionsPackage::CS_CREATEOBJECTACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCS_CreateObjectActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<PSCS::Semantics::Actions::CS_CreateObjectActionActivation>(this->createCS_CreateObjectActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActionsPackage::CS_DEFAULTCONSTRUCTSTRATEGY_CLASS:
		{
				return this->createCS_DefaultConstructStrategy(metaElementID);
			
			break;
		}
		case ActionsPackage::CS_READEXTENTACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCS_ReadExtentActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<PSCS::Semantics::Actions::CS_ReadExtentActionActivation>(this->createCS_ReadExtentActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActionsPackage::CS_READSELFACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCS_ReadSelfActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<PSCS::Semantics::Actions::CS_ReadSelfActionActivation>(this->createCS_ReadSelfActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActionsPackage::CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCS_RemoveStructuralFeatureValueActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<PSCS::Semantics::Actions::CS_RemoveStructuralFeatureValueActionActivation>(this->createCS_RemoveStructuralFeatureValueActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActionsPackage::CS_SENDSIGNALACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCS_SendSignalActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<PSCS::Semantics::Actions::CS_SendSignalActionActivation>(this->createCS_SendSignalActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
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

std::shared_ptr<PSCS::Semantics::Actions::CS_AcceptCallActionActivation> ActionsFactoryImpl::createCS_AcceptCallActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_AcceptCallActionActivationImpl> element(new PSCS::Semantics::Actions::CS_AcceptCallActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_AcceptCallActionActivationPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::Actions::CS_AcceptCallActionActivation> ActionsFactoryImpl::createCS_AcceptCallActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_AcceptCallActionActivationImpl> element(new PSCS::Semantics::Actions::CS_AcceptCallActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	
	}
	element->setThisCS_AcceptCallActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<PSCS::Semantics::Actions::CS_AcceptEventActionActivation> ActionsFactoryImpl::createCS_AcceptEventActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_AcceptEventActionActivationImpl> element(new PSCS::Semantics::Actions::CS_AcceptEventActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_AcceptEventActionActivationPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::Actions::CS_AcceptEventActionActivation> ActionsFactoryImpl::createCS_AcceptEventActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_AcceptEventActionActivationImpl> element(new PSCS::Semantics::Actions::CS_AcceptEventActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	
	}
	element->setThisCS_AcceptEventActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<PSCS::Semantics::Actions::CS_AddStructuralFeatureValueActionActivation> ActionsFactoryImpl::createCS_AddStructuralFeatureValueActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_AddStructuralFeatureValueActionActivationImpl> element(new PSCS::Semantics::Actions::CS_AddStructuralFeatureValueActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_AddStructuralFeatureValueActionActivationPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::Actions::CS_AddStructuralFeatureValueActionActivation> ActionsFactoryImpl::createCS_AddStructuralFeatureValueActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_AddStructuralFeatureValueActionActivationImpl> element(new PSCS::Semantics::Actions::CS_AddStructuralFeatureValueActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	
	}
	element->setThisCS_AddStructuralFeatureValueActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<PSCS::Semantics::Actions::CS_CallOperationActionActivation> ActionsFactoryImpl::createCS_CallOperationActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_CallOperationActionActivationImpl> element(new PSCS::Semantics::Actions::CS_CallOperationActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_CallOperationActionActivationPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::Actions::CS_CallOperationActionActivation> ActionsFactoryImpl::createCS_CallOperationActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_CallOperationActionActivationImpl> element(new PSCS::Semantics::Actions::CS_CallOperationActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	
	}
	element->setThisCS_CallOperationActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<PSCS::Semantics::Actions::CS_ClearStructuralFeatureActionActivation> ActionsFactoryImpl::createCS_ClearStructuralFeatureActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_ClearStructuralFeatureActionActivationImpl> element(new PSCS::Semantics::Actions::CS_ClearStructuralFeatureActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_ClearStructuralFeatureActionActivationPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::Actions::CS_ClearStructuralFeatureActionActivation> ActionsFactoryImpl::createCS_ClearStructuralFeatureActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_ClearStructuralFeatureActionActivationImpl> element(new PSCS::Semantics::Actions::CS_ClearStructuralFeatureActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	
	}
	element->setThisCS_ClearStructuralFeatureActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<PSCS::Semantics::Actions::CS_CreateLinkActionActivation> ActionsFactoryImpl::createCS_CreateLinkActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_CreateLinkActionActivationImpl> element(new PSCS::Semantics::Actions::CS_CreateLinkActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_CreateLinkActionActivationPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::Actions::CS_CreateLinkActionActivation> ActionsFactoryImpl::createCS_CreateLinkActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_CreateLinkActionActivationImpl> element(new PSCS::Semantics::Actions::CS_CreateLinkActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	
	}
	element->setThisCS_CreateLinkActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<PSCS::Semantics::Actions::CS_CreateObjectActionActivation> ActionsFactoryImpl::createCS_CreateObjectActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_CreateObjectActionActivationImpl> element(new PSCS::Semantics::Actions::CS_CreateObjectActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_CreateObjectActionActivationPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::Actions::CS_CreateObjectActionActivation> ActionsFactoryImpl::createCS_CreateObjectActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_CreateObjectActionActivationImpl> element(new PSCS::Semantics::Actions::CS_CreateObjectActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	
	}
	element->setThisCS_CreateObjectActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<PSCS::Semantics::Actions::CS_DefaultConstructStrategy> ActionsFactoryImpl::createCS_DefaultConstructStrategy(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_DefaultConstructStrategyImpl> element(new PSCS::Semantics::Actions::CS_DefaultConstructStrategyImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_DefaultConstructStrategyPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::Actions::CS_ReadExtentActionActivation> ActionsFactoryImpl::createCS_ReadExtentActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_ReadExtentActionActivationImpl> element(new PSCS::Semantics::Actions::CS_ReadExtentActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_ReadExtentActionActivationPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::Actions::CS_ReadExtentActionActivation> ActionsFactoryImpl::createCS_ReadExtentActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_ReadExtentActionActivationImpl> element(new PSCS::Semantics::Actions::CS_ReadExtentActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	
	}
	element->setThisCS_ReadExtentActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<PSCS::Semantics::Actions::CS_ReadSelfActionActivation> ActionsFactoryImpl::createCS_ReadSelfActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_ReadSelfActionActivationImpl> element(new PSCS::Semantics::Actions::CS_ReadSelfActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_ReadSelfActionActivationPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::Actions::CS_ReadSelfActionActivation> ActionsFactoryImpl::createCS_ReadSelfActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_ReadSelfActionActivationImpl> element(new PSCS::Semantics::Actions::CS_ReadSelfActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	
	}
	element->setThisCS_ReadSelfActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<PSCS::Semantics::Actions::CS_RemoveStructuralFeatureValueActionActivation> ActionsFactoryImpl::createCS_RemoveStructuralFeatureValueActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_RemoveStructuralFeatureValueActionActivationImpl> element(new PSCS::Semantics::Actions::CS_RemoveStructuralFeatureValueActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_RemoveStructuralFeatureValueActionActivationPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::Actions::CS_RemoveStructuralFeatureValueActionActivation> ActionsFactoryImpl::createCS_RemoveStructuralFeatureValueActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_RemoveStructuralFeatureValueActionActivationImpl> element(new PSCS::Semantics::Actions::CS_RemoveStructuralFeatureValueActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	
	}
	element->setThisCS_RemoveStructuralFeatureValueActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<PSCS::Semantics::Actions::CS_SendSignalActionActivation> ActionsFactoryImpl::createCS_SendSignalActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_SendSignalActionActivationImpl> element(new PSCS::Semantics::Actions::CS_SendSignalActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_SendSignalActionActivationPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::Actions::CS_SendSignalActionActivation> ActionsFactoryImpl::createCS_SendSignalActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_SendSignalActionActivationImpl> element(new PSCS::Semantics::Actions::CS_SendSignalActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	
	}
	element->setThisCS_SendSignalActionActivationPtr(element);
	return element;
	
}

