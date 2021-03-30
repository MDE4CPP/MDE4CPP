#include "fUML/Semantics/StructuredClassifiers/impl/StructuredClassifiersFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/impl/DispatchStrategyImpl.hpp"
#include "fUML/Semantics/StructuredClassifiers/impl/ExtensionalValueImpl.hpp"
#include "fUML/Semantics/StructuredClassifiers/impl/ExtensionalValueListImpl.hpp"
#include "fUML/Semantics/StructuredClassifiers/impl/LinkImpl.hpp"
#include "fUML/Semantics/StructuredClassifiers/impl/ObjectImpl.hpp"
#include "fUML/Semantics/StructuredClassifiers/impl/RedefinitionBasedDispatchStrategyImpl.hpp"
#include "fUML/Semantics/StructuredClassifiers/impl/ReferenceImpl.hpp"



using namespace fUML::Semantics::StructuredClassifiers;

//*********************************
// Constructor / Destructor
//*********************************

StructuredClassifiersFactoryImpl::StructuredClassifiersFactoryImpl()
{
	m_idMap.insert(std::make_pair("fUML::Semantics::StructuredClassifiers::DispatchStrategy", StructuredClassifiersPackage::DISPATCHSTRATEGY_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::StructuredClassifiers::ExtensionalValueList", StructuredClassifiersPackage::EXTENSIONALVALUELIST_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::StructuredClassifiers::Link", StructuredClassifiersPackage::LINK_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::StructuredClassifiers::Object", StructuredClassifiersPackage::OBJECT_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::StructuredClassifiers::RedefinitionBasedDispatchStrategy", StructuredClassifiersPackage::REDEFINITIONBASEDDISPATCHSTRATEGY_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::StructuredClassifiers::Reference", StructuredClassifiersPackage::REFERENCE_CLASS));
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
		case StructuredClassifiersPackage::DISPATCHSTRATEGY_CLASS:
		{
				return this->createDispatchStrategy(metaElementID);
			
		}
		case StructuredClassifiersPackage::EXTENSIONALVALUELIST_CLASS:
		{
				return this->createExtensionalValueList(metaElementID);
			
		}
		case StructuredClassifiersPackage::LINK_CLASS:
		{
				return this->createLink(metaElementID);
			
		}
		case StructuredClassifiersPackage::OBJECT_CLASS:
		{
				return this->createObject(metaElementID);
			
		}
		case StructuredClassifiersPackage::REDEFINITIONBASEDDISPATCHSTRATEGY_CLASS:
		{
				return this->createRedefinitionBasedDispatchStrategy(metaElementID);
			
		}
		case StructuredClassifiersPackage::REFERENCE_CLASS:
		{
				return this->createReference(metaElementID);
			
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

std::shared_ptr<fUML::Semantics::StructuredClassifiers::DispatchStrategy> StructuredClassifiersFactoryImpl::createDispatchStrategy(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::DispatchStrategyImpl> element(new fUML::Semantics::StructuredClassifiers::DispatchStrategyImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDispatchStrategyPtr(element);
	return element;
}

std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValueList> StructuredClassifiersFactoryImpl::createExtensionalValueList(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValueListImpl> element(new fUML::Semantics::StructuredClassifiers::ExtensionalValueListImpl());
	element->setMetaElementID(metaElementID);
	element->setThisExtensionalValueListPtr(element);
	return element;
}

std::shared_ptr<fUML::Semantics::StructuredClassifiers::Link> StructuredClassifiersFactoryImpl::createLink(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::LinkImpl> element(new fUML::Semantics::StructuredClassifiers::LinkImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLinkPtr(element);
	return element;
}

std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> StructuredClassifiersFactoryImpl::createObject(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::ObjectImpl> element(new fUML::Semantics::StructuredClassifiers::ObjectImpl());
	element->setMetaElementID(metaElementID);
	element->setThisObjectPtr(element);
	return element;
}

std::shared_ptr<fUML::Semantics::StructuredClassifiers::RedefinitionBasedDispatchStrategy> StructuredClassifiersFactoryImpl::createRedefinitionBasedDispatchStrategy(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::RedefinitionBasedDispatchStrategyImpl> element(new fUML::Semantics::StructuredClassifiers::RedefinitionBasedDispatchStrategyImpl());
	element->setMetaElementID(metaElementID);
	element->setThisRedefinitionBasedDispatchStrategyPtr(element);
	return element;
}

std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> StructuredClassifiersFactoryImpl::createReference(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::ReferenceImpl> element(new fUML::Semantics::StructuredClassifiers::ReferenceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReferencePtr(element);
	return element;
}


