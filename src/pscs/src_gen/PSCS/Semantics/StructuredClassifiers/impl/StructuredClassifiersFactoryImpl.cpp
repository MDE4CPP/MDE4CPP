#include "PSCS/Semantics/StructuredClassifiers/impl/StructuredClassifiersFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_DefaultRequestPropagationStrategyImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_DispatchOperationOfInterfaceStrategyImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_RequestPropagationStrategyImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_StructuralFeatureOfInterfaceAccessStrategyImpl.hpp"



using namespace PSCS::Semantics::StructuredClassifiers;

std::shared_ptr<StructuredClassifiersFactory> StructuredClassifiersFactory::eInstance()
{
	static std::shared_ptr<StructuredClassifiersFactory> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(StructuredClassifiersFactoryImpl::create());
	}	
	return instance;
}

//*********************************
// Constructor / Destructor
//*********************************

StructuredClassifiersFactoryImpl::StructuredClassifiersFactoryImpl()
{
	m_idMap.insert(std::make_pair("PSCS::Semantics::StructuredClassifiers::CS_DefaultRequestPropagationStrategy", StructuredClassifiersPackage::CS_DEFAULTREQUESTPROPAGATIONSTRATEGY_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::StructuredClassifiers::CS_DispatchOperationOfInterfaceStrategy", StructuredClassifiersPackage::CS_DISPATCHOPERATIONOFINTERFACESTRATEGY_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::StructuredClassifiers::CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy", StructuredClassifiersPackage::CS_NAMEBASED_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_CLASS));
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
			
			break;
		}
		case StructuredClassifiersPackage::CS_DISPATCHOPERATIONOFINTERFACESTRATEGY_CLASS:
		{
				return this->createCS_DispatchOperationOfInterfaceStrategy(metaElementID);
			
			break;
		}
		case StructuredClassifiersPackage::CS_NAMEBASED_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_CLASS:
		{
				return this->createCS_NameBased_StructuralFeatureOfInterfaceAccessStrategy(metaElementID);
			
			break;
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
std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy> StructuredClassifiersFactoryImpl::createCS_NameBased_StructuralFeatureOfInterfaceAccessStrategy(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_NameBased_StructuralFeatureOfInterfaceAccessStrategyPtr(element);
	return element;
}

