#include "PSCS/impl/PSCSFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"



using namespace PSCS;

std::shared_ptr<PSCSFactory> PSCSFactory::eInstance()
{
	static std::shared_ptr<PSCSFactory> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(PSCSFactoryImpl::create());
	}	
	return instance;
}

//*********************************
// Constructor / Destructor
//*********************************

PSCSFactoryImpl::PSCSFactoryImpl()
{
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


