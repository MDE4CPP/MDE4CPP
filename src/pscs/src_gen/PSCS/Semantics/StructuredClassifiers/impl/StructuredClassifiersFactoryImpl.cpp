#include "PSCS/Semantics/StructuredClassifiers/impl/StructuredClassifiersFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_DefaultRequestPropagationStrategyImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_DispatchOperationOfInterfaceStrategyImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_InteractionPointImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_LinkImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_ObjectImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_ReferenceImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_RequestPropagationStrategyImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_StructuralFeatureOfInterfaceAccessStrategyImpl.hpp"



using namespace PSCS::Semantics::StructuredClassifiers;

//*********************************
// Constructor / Destructor
//*********************************

StructuredClassifiersFactoryImpl::StructuredClassifiersFactoryImpl()
{
	m_idMap.insert(std::make_pair("PSCS::Semantics::StructuredClassifiers::CS_DefaultRequestPropagationStrategy", StructuredClassifiersPackage::CS_DEFAULTREQUESTPROPAGATIONSTRATEGY_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::StructuredClassifiers::CS_DispatchOperationOfInterfaceStrategy", StructuredClassifiersPackage::CS_DISPATCHOPERATIONOFINTERFACESTRATEGY_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint", StructuredClassifiersPackage::CS_INTERACTIONPOINT_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::StructuredClassifiers::CS_Link", StructuredClassifiersPackage::CS_LINK_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::StructuredClassifiers::CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy", StructuredClassifiersPackage::CS_NAMEBASED_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::StructuredClassifiers::CS_Object", StructuredClassifiersPackage::CS_OBJECT_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::StructuredClassifiers::CS_Reference", StructuredClassifiersPackage::CS_REFERENCE_CLASS));
}

StructuredClassifiersFactoryImpl::~StructuredClassifiersFactoryImpl()
{
}

StructuredClassifiersFactory* StructuredClassifiersFactoryImpl::create()
{
	return new StructuredClassifiersFactoryImpl();
}

//*********************************
// creators
//*********************************

std::shared_ptr<ecore::EObject> StructuredClassifiersFactoryImpl::create(const int metaElementID, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	switch(metaElementID)
	{
		case StructuredClassifiersPackage::CS_DEFAULTREQUESTPROPAGATIONSTRATEGY_CLASS:
		{
				return this->createCS_DefaultRequestPropagationStrategy(metaElementID);
			
		}
		case StructuredClassifiersPackage::CS_DISPATCHOPERATIONOFINTERFACESTRATEGY_CLASS:
		{
				return this->createCS_DispatchOperationOfInterfaceStrategy(metaElementID);
			
		}
		case StructuredClassifiersPackage::CS_INTERACTIONPOINT_CLASS:
		{
				return this->createCS_InteractionPoint(metaElementID);
			
		}
		case StructuredClassifiersPackage::CS_LINK_CLASS:
		{
				return this->createCS_Link(metaElementID);
			
		}
		case StructuredClassifiersPackage::CS_NAMEBASED_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_CLASS:
		{
				return this->createCS_NameBased_StructuralFeatureOfInterfaceAccessStrategy(metaElementID);
			
		}
		case StructuredClassifiersPackage::CS_OBJECT_CLASS:
		{
				return this->createCS_Object(metaElementID);
			
		}
		case StructuredClassifiersPackage::CS_REFERENCE_CLASS:
		{
				return this->createCS_Reference(metaElementID);
			
		}
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << metaElementID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<ecore::EObject> StructuredClassifiersFactoryImpl::create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}
	int _elementID = _class->getMetaElementID();
	return create(_elementID, container, referenceID);
}

std::shared_ptr<ecore::EObject> StructuredClassifiersFactoryImpl::create(std::string _className, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
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

std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_DefaultRequestPropagationStrategy> StructuredClassifiersFactoryImpl::createCS_DefaultRequestPropagationStrategy(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_DefaultRequestPropagationStrategyImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_DefaultRequestPropagationStrategyImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_DefaultRequestPropagationStrategyPtr(element);
	return element;
}

std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_DispatchOperationOfInterfaceStrategy> StructuredClassifiersFactoryImpl::createCS_DispatchOperationOfInterfaceStrategy(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_DispatchOperationOfInterfaceStrategyImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_DispatchOperationOfInterfaceStrategyImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_DispatchOperationOfInterfaceStrategyPtr(element);
	return element;
}

std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> StructuredClassifiersFactoryImpl::createCS_InteractionPoint(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPointImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_InteractionPointImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_InteractionPointPtr(element);
	return element;
}

std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> StructuredClassifiersFactoryImpl::createCS_Link(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_LinkImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_LinkImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_LinkPtr(element);
	return element;
}

std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy> StructuredClassifiersFactoryImpl::createCS_NameBased_StructuralFeatureOfInterfaceAccessStrategy(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_NameBased_StructuralFeatureOfInterfaceAccessStrategyPtr(element);
	return element;
}

std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> StructuredClassifiersFactoryImpl::createCS_Object(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_ObjectImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_ObjectImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_ObjectPtr(element);
	return element;
}

std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> StructuredClassifiersFactoryImpl::createCS_Reference(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_ReferenceImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_ReferenceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_ReferencePtr(element);
	return element;
}


