#include "FoundationalModelLibrary/BasicInputOutput/impl/BasicInputOutputFactoryImpl.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "uml/Class.hpp"
#include <cassert>

#include "FoundationalModelLibrary/BasicInputOutput/impl/ActiveChannelImpl.hpp"
#include "FoundationalModelLibrary/BasicInputOutput/impl/ChannelImpl.hpp"
#include "FoundationalModelLibrary/BasicInputOutput/impl/InputChannelImpl.hpp"
#include "FoundationalModelLibrary/BasicInputOutput/impl/OutputChannelImpl.hpp"
#include "FoundationalModelLibrary/BasicInputOutput/impl/StandardInputChannelImpl.hpp"
#include "FoundationalModelLibrary/BasicInputOutput/impl/StandardOutputChannelImpl.hpp"
#include "FoundationalModelLibrary/BasicInputOutput/impl/TextInputChannelImpl.hpp"
#include "FoundationalModelLibrary/BasicInputOutput/impl/TextOutputChannelImpl.hpp"

using namespace FoundationalModelLibrary::BasicInputOutput;
//*********************************
// Constructor / Destructor
//*********************************
BasicInputOutputFactoryImpl::BasicInputOutputFactoryImpl()
{
	m_idMap.insert(std::make_pair("FoundationalModelLibrary::BasicInputOutput::StandardInputChannel", BasicInputOutputPackage::STANDARDINPUTCHANNEL_CLASS));
	m_idMap.insert(std::make_pair("FoundationalModelLibrary::BasicInputOutput::StandardOutputChannel", BasicInputOutputPackage::STANDARDOUTPUTCHANNEL_CLASS));
}

BasicInputOutputFactoryImpl::~BasicInputOutputFactoryImpl()
{
}

BasicInputOutputFactory* BasicInputOutputFactoryImpl::create()
{
	return new BasicInputOutputFactoryImpl();
}

//*********************************
// creators
//*********************************
std::shared_ptr<uml::Element> BasicInputOutputFactoryImpl::create(const unsigned int _metaClassId,  std::shared_ptr<uml::Element> container /*= nullptr*/, const unsigned int referenceID/* = -1*/) const
{
	switch(_metaClassId)
	{
		case BasicInputOutputPackage::STANDARDINPUTCHANNEL_CLASS:
		{
				return this->createStandardInputChannel(_metaClassId);
			
		}
		case BasicInputOutputPackage::STANDARDOUTPUTCHANNEL_CLASS:
		{
				return this->createStandardOutputChannel(_metaClassId);
			
		}
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << _metaClassId <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<uml::Element> BasicInputOutputFactoryImpl::create(std::shared_ptr<uml::Class> _class, std::shared_ptr<uml::Element> container /*= nullptr*/, const unsigned int referenceID/* = -1*/) const
{
	if(_class->getIsAbstract())
    {
    	return nullptr;
    }
	std::string typeName = _class->getQualifiedName();
	return create(typeName,container,referenceID);
}

std::shared_ptr<uml::Element> BasicInputOutputFactoryImpl::create(std::string _className, std::shared_ptr<uml::Element> container /*= nullptr*/, const unsigned int referenceID/* = -1*/) const
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
//create-Functions for class 'StandardInputChannel'
//--------------------------
std::shared_ptr<FoundationalModelLibrary::BasicInputOutput::StandardInputChannel> BasicInputOutputFactoryImpl::createStandardInputChannel(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<FoundationalModelLibrary::BasicInputOutput::StandardInputChannelImpl> element(new FoundationalModelLibrary::BasicInputOutput::StandardInputChannelImpl());
	element->setMetaElementID(metaElementID);
	element->setThisStandardInputChannelPtr(element);
	element->instantiate();
	return element;
}


//--------------------------
//create-Functions for class 'StandardOutputChannel'
//--------------------------
std::shared_ptr<FoundationalModelLibrary::BasicInputOutput::StandardOutputChannel> BasicInputOutputFactoryImpl::createStandardOutputChannel(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<FoundationalModelLibrary::BasicInputOutput::StandardOutputChannelImpl> element(new FoundationalModelLibrary::BasicInputOutput::StandardOutputChannelImpl());
	element->setMetaElementID(metaElementID);
	element->setThisStandardOutputChannelPtr(element);
	element->instantiate();
	return element;
}



std::shared_ptr<BasicInputOutputPackage> BasicInputOutputFactoryImpl::getBasicInputOutputPackage()
{
	return BasicInputOutputPackage::eInstance();
}
