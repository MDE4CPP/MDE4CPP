#include "FoundationalModelLibrary/PrimitiveBehaviors/impl/PrimitiveBehaviorsFactoryImpl.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "uml/Class.hpp"
#include <cassert>


using namespace FoundationalModelLibrary::PrimitiveBehaviors;
//*********************************
// Constructor / Destructor
//*********************************
PrimitiveBehaviorsFactoryImpl::PrimitiveBehaviorsFactoryImpl()
{
}

PrimitiveBehaviorsFactoryImpl::~PrimitiveBehaviorsFactoryImpl()
{
}

PrimitiveBehaviorsFactory* PrimitiveBehaviorsFactoryImpl::create()
{
	return new PrimitiveBehaviorsFactoryImpl();
}

//*********************************
// creators
//*********************************
std::shared_ptr<uml::Element> PrimitiveBehaviorsFactoryImpl::create(const unsigned int _metaClassId,  std::shared_ptr<uml::Element> container /*= nullptr*/, const unsigned int referenceID/* = -1*/) const
{
	switch(_metaClassId)
	{
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << _metaClassId <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<uml::Element> PrimitiveBehaviorsFactoryImpl::create(std::shared_ptr<uml::Class> _class, std::shared_ptr<uml::Element> container /*= nullptr*/, const unsigned int referenceID/* = -1*/) const
{
	if(_class->getIsAbstract())
    {
    	return nullptr;
    }
	std::string typeName = _class->getQualifiedName();
	return create(typeName,container,referenceID);
}

std::shared_ptr<uml::Element> PrimitiveBehaviorsFactoryImpl::create(std::string _className, std::shared_ptr<uml::Element> container /*= nullptr*/, const unsigned int referenceID/* = -1*/) const
{
	auto iter = m_idMap.find(_className);
	if(iter != m_idMap.end())
    {
		//get the getMetaElementId()
        unsigned int id = iter->second;
		return create(id,container,referenceID);
    }
    return nullptr;
}


std::shared_ptr<PrimitiveBehaviorsPackage> PrimitiveBehaviorsFactoryImpl::getPrimitiveBehaviorsPackage()
{
	return PrimitiveBehaviorsPackage::eInstance();
}
