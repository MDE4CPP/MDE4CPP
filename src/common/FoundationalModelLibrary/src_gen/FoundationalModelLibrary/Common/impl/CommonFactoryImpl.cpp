#include "FoundationalModelLibrary/Common/impl/CommonFactoryImpl.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "uml/Class.hpp"
#include <cassert>

#include "FoundationalModelLibrary/Common/impl/ListenerImpl.hpp"
#include "FoundationalModelLibrary/Common/impl/StatusImpl.hpp"

using namespace FoundationalModelLibrary::Common;
//*********************************
// Constructor / Destructor
//*********************************
CommonFactoryImpl::CommonFactoryImpl()
{
	m_idMap.insert(std::make_pair("FoundationalModelLibrary::Common::Status", CommonPackage::STATUS_DATATYPE));
}

CommonFactoryImpl::~CommonFactoryImpl()
{
}

CommonFactory* CommonFactoryImpl::create()
{
	return new CommonFactoryImpl();
}

//*********************************
// creators
//*********************************
std::shared_ptr<uml::Element> CommonFactoryImpl::create(const unsigned int _metaClassId,  std::shared_ptr<uml::Element> container /*= nullptr*/, const unsigned int referenceID/* = -1*/) const
{
	switch(_metaClassId)
	{
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << _metaClassId <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<uml::Element> CommonFactoryImpl::create(std::shared_ptr<uml::Class> _class, std::shared_ptr<uml::Element> container /*= nullptr*/, const unsigned int referenceID/* = -1*/) const
{
	if(_class->getIsAbstract())
    {
    	return nullptr;
    }
	std::string typeName = _class->getQualifiedName();
	return create(typeName,container,referenceID);
}

std::shared_ptr<uml::Element> CommonFactoryImpl::create(std::string _className, std::shared_ptr<uml::Element> container /*= nullptr*/, const unsigned int referenceID/* = -1*/) const
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

//--------------------------
//create-Functions for data type 'Status'
//--------------------------
std::shared_ptr<FoundationalModelLibrary::Common::Status> CommonFactoryImpl::createStatus(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<FoundationalModelLibrary::Common::StatusImpl> element(new FoundationalModelLibrary::Common::StatusImpl());
	element->setMetaElementID(metaElementID);
	return element;
}


std::shared_ptr<CommonPackage> CommonFactoryImpl::getCommonPackage()
{
	return CommonPackage::eInstance();
}
