#include "PSSM/Semantics/StructuredClassifiers/impl/StructuredClassifiersFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "PSSM/Semantics/StructuredClassifiers/impl/SM_RedefinitionBasedDispatchStrategyImpl.hpp"



using namespace PSSM::Semantics::StructuredClassifiers;

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
	m_idMap.insert(std::make_pair("PSSM::Semantics::StructuredClassifiers::SM_RedefinitionBasedDispatchStrategy", StructuredClassifiersPackage::SM_REDEFINITIONBASEDDISPATCHSTRATEGY_CLASS));
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
		case StructuredClassifiersPackage::SM_REDEFINITIONBASEDDISPATCHSTRATEGY_CLASS:
		{
				return this->createSM_RedefinitionBasedDispatchStrategy(metaElementID);
			
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

std::shared_ptr<PSSM::Semantics::StructuredClassifiers::SM_RedefinitionBasedDispatchStrategy> StructuredClassifiersFactoryImpl::createSM_RedefinitionBasedDispatchStrategy(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSSM::Semantics::StructuredClassifiers::SM_RedefinitionBasedDispatchStrategyImpl> element(new PSSM::Semantics::StructuredClassifiers::SM_RedefinitionBasedDispatchStrategyImpl());
	element->setMetaElementID(metaElementID);
	element->setThisSM_RedefinitionBasedDispatchStrategyPtr(element);
	return element;
}

