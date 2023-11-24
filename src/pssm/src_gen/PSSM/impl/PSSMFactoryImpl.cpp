#include "PSSM/impl/PSSMFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"



using namespace PSSM;

std::shared_ptr<PSSMFactory> PSSMFactory::eInstance()
{
	static std::shared_ptr<PSSMFactory> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(PSSMFactoryImpl::create());
	}	
	return instance;
}

//*********************************
// Constructor / Destructor
//*********************************

PSSMFactoryImpl::PSSMFactoryImpl()
{
}

PSSMFactoryImpl::~PSSMFactoryImpl()
{
}

PSSMFactory* PSSMFactoryImpl::create()
{
	return new PSSMFactoryImpl();
}

//*********************************
// creators
//*********************************

std::shared_ptr<ecore::EObject> PSSMFactoryImpl::create(const int metaElementID, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	switch(metaElementID)
	{
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << metaElementID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<ecore::EObject> PSSMFactoryImpl::create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}
	int _elementID = _class->getMetaElementID();
	return create(_elementID, container, referenceID);
}

std::shared_ptr<ecore::EObject> PSSMFactoryImpl::create(std::string _className, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
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


