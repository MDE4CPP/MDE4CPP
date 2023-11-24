#include "PSSM/Semantics/Loci/impl/LociFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "PSSM/Semantics/Loci/impl/SM_ExecutionFactoryImpl.hpp"
#include "PSSM/Semantics/Loci/impl/SM_LocusImpl.hpp"

#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"


using namespace PSSM::Semantics::Loci;

std::shared_ptr<LociFactory> LociFactory::eInstance()
{
	static std::shared_ptr<LociFactory> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(LociFactoryImpl::create());
	}	
	return instance;
}

//*********************************
// Constructor / Destructor
//*********************************

LociFactoryImpl::LociFactoryImpl()
{
	m_idMap.insert(std::make_pair("PSSM::Semantics::Loci::SM_ExecutionFactory", LociPackage::SM_EXECUTIONFACTORY_CLASS));
	m_idMap.insert(std::make_pair("PSSM::Semantics::Loci::SM_Locus", LociPackage::SM_LOCUS_CLASS));
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
		case LociPackage::SM_EXECUTIONFACTORY_CLASS:
		{
			if (nullptr == container)
			{
				return this->createSM_ExecutionFactory(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Loci::Locus> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Loci::Locus>(container);
				assert(castedContainer);
				return std::shared_ptr<PSSM::Semantics::Loci::SM_ExecutionFactory>(this->createSM_ExecutionFactory_as_factory_in_Locus(castedContainer,metaElementID));
			}
			break;
		}
		case LociPackage::SM_LOCUS_CLASS:
		{
				return this->createSM_Locus(metaElementID);
			
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

std::shared_ptr<PSSM::Semantics::Loci::SM_ExecutionFactory> LociFactoryImpl::createSM_ExecutionFactory(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSSM::Semantics::Loci::SM_ExecutionFactoryImpl> element(new PSSM::Semantics::Loci::SM_ExecutionFactoryImpl());
	element->setMetaElementID(metaElementID);
	element->setThisSM_ExecutionFactoryPtr(element);
	return element;
}
std::shared_ptr<PSSM::Semantics::Loci::SM_ExecutionFactory> LociFactoryImpl::createSM_ExecutionFactory_as_factory_in_Locus(std::weak_ptr<fUML::Semantics::Loci::Locus> par_Locus, const int metaElementID) const
{
	std::shared_ptr<PSSM::Semantics::Loci::SM_ExecutionFactoryImpl> element(new PSSM::Semantics::Loci::SM_ExecutionFactoryImpl(par_Locus));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_Locus.lock())
	{
		wp->setFactory(element);
	}
	
	element->setThisSM_ExecutionFactoryPtr(element);
	return element;
	
}
std::shared_ptr<PSSM::Semantics::Loci::SM_Locus> LociFactoryImpl::createSM_Locus(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSSM::Semantics::Loci::SM_LocusImpl> element(new PSSM::Semantics::Loci::SM_LocusImpl());
	element->setMetaElementID(metaElementID);
	element->setThisSM_LocusPtr(element);
	return element;
}

