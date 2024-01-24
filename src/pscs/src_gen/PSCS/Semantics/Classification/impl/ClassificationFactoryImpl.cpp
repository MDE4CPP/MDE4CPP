#include "PSCS/Semantics/Classification/impl/ClassificationFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"



using namespace PSCS::Semantics::Classification;

std::shared_ptr<ClassificationFactory> ClassificationFactory::eInstance()
{
	static std::shared_ptr<ClassificationFactory> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(ClassificationFactoryImpl::create());
	}	
	return instance;
}

//*********************************
// Constructor / Destructor
//*********************************

ClassificationFactoryImpl::ClassificationFactoryImpl()
{
}

ClassificationFactoryImpl::~ClassificationFactoryImpl()
{
}

ClassificationFactory* ClassificationFactoryImpl::create()
{
	return new ClassificationFactoryImpl();
}

//*********************************
// creators
//*********************************

std::shared_ptr<ecore::EObject> ClassificationFactoryImpl::create(const int metaElementID, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	switch(metaElementID)
	{
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << metaElementID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<ecore::EObject> ClassificationFactoryImpl::create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}
	int _elementID = _class->getMetaElementID();
	return create(_elementID, container, referenceID);
}

std::shared_ptr<ecore::EObject> ClassificationFactoryImpl::create(std::string _className, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
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


