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
				return this->createCS_AcceptCallActionActivation(metaElementID);
			
			break;
		}
		case ActionsPackage::CS_ACCEPTEVENTACTIONACTIVATION_CLASS:
		{
				return this->createCS_AcceptEventActionActivation(metaElementID);
			
			break;
		}
		case ActionsPackage::CS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS:
		{
				return this->createCS_AddStructuralFeatureValueActionActivation(metaElementID);
			
			break;
		}
		case ActionsPackage::CS_CALLOPERATIONACTIONACTIVATION_CLASS:
		{
				return this->createCS_CallOperationActionActivation(metaElementID);
			
			break;
		}
		case ActionsPackage::CS_CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS:
		{
				return this->createCS_ClearStructuralFeatureActionActivation(metaElementID);
			
			break;
		}
		case ActionsPackage::CS_CREATELINKACTIONACTIVATION_CLASS:
		{
				return this->createCS_CreateLinkActionActivation(metaElementID);
			
			break;
		}
		case ActionsPackage::CS_CREATEOBJECTACTIONACTIVATION_CLASS:
		{
				return this->createCS_CreateObjectActionActivation(metaElementID);
			
			break;
		}
		case ActionsPackage::CS_DEFAULTCONSTRUCTSTRATEGY_CLASS:
		{
				return this->createCS_DefaultConstructStrategy(metaElementID);
			
			break;
		}
		case ActionsPackage::CS_READEXTENTACTIONACTIVATION_CLASS:
		{
				return this->createCS_ReadExtentActionActivation(metaElementID);
			
			break;
		}
		case ActionsPackage::CS_READSELFACTIONACTIVATION_CLASS:
		{
				return this->createCS_ReadSelfActionActivation(metaElementID);
			
			break;
		}
		case ActionsPackage::CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS:
		{
				return this->createCS_RemoveStructuralFeatureValueActionActivation(metaElementID);
			
			break;
		}
		case ActionsPackage::CS_SENDSIGNALACTIONACTIVATION_CLASS:
		{
				return this->createCS_SendSignalActionActivation(metaElementID);
			
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
std::shared_ptr<PSCS::Semantics::Actions::CS_AcceptEventActionActivation> ActionsFactoryImpl::createCS_AcceptEventActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_AcceptEventActionActivationImpl> element(new PSCS::Semantics::Actions::CS_AcceptEventActionActivationImpl());
	element->setMetaElementID(metaElementID);
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
std::shared_ptr<PSCS::Semantics::Actions::CS_CallOperationActionActivation> ActionsFactoryImpl::createCS_CallOperationActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_CallOperationActionActivationImpl> element(new PSCS::Semantics::Actions::CS_CallOperationActionActivationImpl());
	element->setMetaElementID(metaElementID);
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
std::shared_ptr<PSCS::Semantics::Actions::CS_CreateLinkActionActivation> ActionsFactoryImpl::createCS_CreateLinkActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_CreateLinkActionActivationImpl> element(new PSCS::Semantics::Actions::CS_CreateLinkActionActivationImpl());
	element->setMetaElementID(metaElementID);
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
std::shared_ptr<PSCS::Semantics::Actions::CS_ReadSelfActionActivation> ActionsFactoryImpl::createCS_ReadSelfActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_ReadSelfActionActivationImpl> element(new PSCS::Semantics::Actions::CS_ReadSelfActionActivationImpl());
	element->setMetaElementID(metaElementID);
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
std::shared_ptr<PSCS::Semantics::Actions::CS_SendSignalActionActivation> ActionsFactoryImpl::createCS_SendSignalActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Actions::CS_SendSignalActionActivationImpl> element(new PSCS::Semantics::Actions::CS_SendSignalActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_SendSignalActionActivationPtr(element);
	return element;
}

