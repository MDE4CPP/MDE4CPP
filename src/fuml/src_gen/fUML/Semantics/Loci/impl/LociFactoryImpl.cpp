#include "fUML/Semantics/Loci/impl/LociFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "fUML/Semantics/Loci/impl/ChoiceStrategyImpl.hpp"
#include "fUML/Semantics/Loci/impl/ExecutionFactoryImpl.hpp"
#include "fUML/Semantics/Loci/impl/ExecutorImpl.hpp"
#include "fUML/Semantics/Loci/impl/FirstChoiceStrategyImpl.hpp"
#include "fUML/Semantics/Loci/impl/LocusImpl.hpp"
#include "fUML/Semantics/Loci/impl/SemanticStrategyImpl.hpp"
#include "fUML/Semantics/Loci/impl/SemanticVisitorImpl.hpp"



using namespace fUML::Semantics::Loci;

//*********************************
// Constructor / Destructor
//*********************************

LociFactoryImpl::LociFactoryImpl()
{
	m_idMap.insert(std::make_pair("fUML::Semantics::Loci::ExecutionFactory", LociPackage::EXECUTIONFACTORY_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Loci::Executor", LociPackage::EXECUTOR_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Loci::FirstChoiceStrategy", LociPackage::FIRSTCHOICESTRATEGY_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Loci::Locus", LociPackage::LOCUS_CLASS));
}

LociFactoryImpl::~LociFactoryImpl()
{
}

LociFactory* LociFactoryImpl::create()
{
	return new LociFactoryImpl();
}

//*********************************
// creators
//*********************************

std::shared_ptr<ecore::EObject> LociFactoryImpl::create(const int metaElementID, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	switch(metaElementID)
	{
		case LociPackage::EXECUTIONFACTORY_CLASS:
		{
			if (nullptr == container)
			{
				return this->createExecutionFactory(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Loci::Locus> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Loci::Locus>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Loci::ExecutionFactory>(this->createExecutionFactory_as_factory_in_Locus(castedContainer,metaElementID));
			}
			break;
		}
		case LociPackage::EXECUTOR_CLASS:
		{
			if (nullptr == container)
			{
				return this->createExecutor(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Loci::Locus> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Loci::Locus>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Loci::Executor>(this->createExecutor_as_executor_in_Locus(castedContainer,metaElementID));
			}
			break;
		}
		case LociPackage::FIRSTCHOICESTRATEGY_CLASS:
		{
				return this->createFirstChoiceStrategy(metaElementID);
			
			break;
		}
		case LociPackage::LOCUS_CLASS:
		{
				return this->createLocus(metaElementID);
			
			break;
		}
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << metaElementID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<ecore::EObject> LociFactoryImpl::create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}
	int _elementID = _class->getMetaElementID();
	return create(_elementID, container, referenceID);
}

std::shared_ptr<ecore::EObject> LociFactoryImpl::create(std::string _className, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
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

std::shared_ptr<fUML::Semantics::Loci::ExecutionFactory> LociFactoryImpl::createExecutionFactory(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Loci::ExecutionFactoryImpl> element(new fUML::Semantics::Loci::ExecutionFactoryImpl());
	element->setMetaElementID(metaElementID);
	element->setThisExecutionFactoryPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Loci::ExecutionFactory> LociFactoryImpl::createExecutionFactory_as_factory_in_Locus(std::weak_ptr<fUML::Semantics::Loci::Locus> par_Locus, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Loci::ExecutionFactoryImpl> element(new fUML::Semantics::Loci::ExecutionFactoryImpl(par_Locus));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_Locus.lock())
	{
		wp->setFactory(element);
	
	}
	element->setThisExecutionFactoryPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Loci::Executor> LociFactoryImpl::createExecutor(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Loci::ExecutorImpl> element(new fUML::Semantics::Loci::ExecutorImpl());
	element->setMetaElementID(metaElementID);
	element->setThisExecutorPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Loci::Executor> LociFactoryImpl::createExecutor_as_executor_in_Locus(std::weak_ptr<fUML::Semantics::Loci::Locus> par_Locus, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Loci::ExecutorImpl> element(new fUML::Semantics::Loci::ExecutorImpl(par_Locus));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_Locus.lock())
	{
		wp->setExecutor(element);
	
	}
	element->setThisExecutorPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Loci::FirstChoiceStrategy> LociFactoryImpl::createFirstChoiceStrategy(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Loci::FirstChoiceStrategyImpl> element(new fUML::Semantics::Loci::FirstChoiceStrategyImpl());
	element->setMetaElementID(metaElementID);
	element->setThisFirstChoiceStrategyPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Loci::Locus> LociFactoryImpl::createLocus(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Loci::LocusImpl> element(new fUML::Semantics::Loci::LocusImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLocusPtr(element);
	return element;
}

