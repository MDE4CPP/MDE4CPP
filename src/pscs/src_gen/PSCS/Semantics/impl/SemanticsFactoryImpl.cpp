#include "PSCS/Semantics/impl/SemanticsFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"



using namespace PSCS::Semantics;

std::shared_ptr<SemanticsFactory> SemanticsFactory::eInstance()
{
	static std::shared_ptr<SemanticsFactory> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(SemanticsFactoryImpl::create());
	}	
	return instance;
}

//*********************************
// Constructor / Destructor
//*********************************

SemanticsFactoryImpl::SemanticsFactoryImpl()
{
}

SemanticsFactoryImpl::~SemanticsFactoryImpl()
{
}

SemanticsFactory* SemanticsFactoryImpl::create()
{
	return new SemanticsFactoryImpl();
}

//*********************************
// creators
//*********************************

std::shared_ptr<ecore::EObject> SemanticsFactoryImpl::create(const int metaElementID, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	switch(metaElementID)
	{
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << metaElementID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<ecore::EObject> SemanticsFactoryImpl::create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}
	int _elementID = _class->getMetaElementID();
	return create(_elementID, container, referenceID);
}

std::shared_ptr<ecore::EObject> SemanticsFactoryImpl::create(std::string _className, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
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


