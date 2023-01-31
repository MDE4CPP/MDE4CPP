#include "FoundationalModelLibrary/PrimitiveBehaviors/RealFunctions/impl/RealFunctionsFactoryImpl.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "uml/Class.hpp"
#include <cassert>


using namespace FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions;
std::shared_ptr<RealFunctionsFactory> RealFunctionsFactory::eInstance()
{
	static std::shared_ptr<RealFunctionsFactory> instance;
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(RealFunctionsFactoryImpl::create());
	}	
	return instance;
}

//*********************************
// Constructor / Destructor
//*********************************
RealFunctionsFactoryImpl::RealFunctionsFactoryImpl()
{
}

RealFunctionsFactoryImpl::~RealFunctionsFactoryImpl()
{
}

RealFunctionsFactory* RealFunctionsFactoryImpl::create()
{
	return new RealFunctionsFactoryImpl();
}

//*********************************
// creators
//*********************************
std::shared_ptr<uml::Element> RealFunctionsFactoryImpl::create(const unsigned int _metaClassId,  std::shared_ptr<uml::Element> container /*= nullptr*/, const unsigned int referenceID/* = -1*/) const
{
	switch(_metaClassId)
	{
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << _metaClassId <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<uml::Element> RealFunctionsFactoryImpl::create(std::shared_ptr<uml::Class> _class, std::shared_ptr<uml::Element> container /*= nullptr*/, const unsigned int referenceID/* = -1*/) const
{
	if(_class->getIsAbstract())
    {
    	return nullptr;
    }
	std::string typeName = _class->getQualifiedName();
	return create(typeName,container,referenceID);
}

std::shared_ptr<uml::Element> RealFunctionsFactoryImpl::create(std::string _className, std::shared_ptr<uml::Element> container /*= nullptr*/, const unsigned int referenceID/* = -1*/) const
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


std::shared_ptr<RealFunctionsPackage> RealFunctionsFactoryImpl::getRealFunctionsPackage()
{
	return RealFunctionsPackage::eInstance();
}
