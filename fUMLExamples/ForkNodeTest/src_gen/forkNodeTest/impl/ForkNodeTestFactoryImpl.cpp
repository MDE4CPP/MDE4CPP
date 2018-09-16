#include "forkNodeTest/impl/ForkNodeTestFactoryImpl.hpp"
#include "forkNodeTest/ForkNodeTestPackage.hpp"

#include "abstractDataTypes/Bag.hpp"
#include "uml/Class.hpp"

#include "forkNodeTest/impl/ForkClassImpl.hpp"

using namespace forkNodeTest;

//*********************************
// Constructor / Destructor
//*********************************
ForkNodeTestFactoryImpl::ForkNodeTestFactoryImpl()
{
	m_creatorMap.insert(std::pair<std::string,std::function<std::shared_ptr<uml::Element>()>>("ForkClass",[this](){return this->createForkClass();}));
}

ForkNodeTestFactoryImpl::~ForkNodeTestFactoryImpl()
{
}

ForkNodeTestFactory* ForkNodeTestFactoryImpl::create()
{
	return new ForkNodeTestFactoryImpl();
}

//*********************************
// creators
//*********************************
std::shared_ptr<uml::Element> ForkNodeTestFactoryImpl::create(std::shared_ptr<uml::Class> _class)
{
	if(_class->getIsAbstract())
    {
    	return nullptr;
    }

	//TODO: still two times run through map
	std::string _className = _class->getName();
	return create(_className);
}

std::shared_ptr<uml::Element> ForkNodeTestFactoryImpl::create(std::string _className)
{
	std::map<std::string,std::function<std::shared_ptr<uml::Element>()>>::iterator iter = m_creatorMap.find(_className);
    if(iter != m_creatorMap.end())
    {
		//invoke the creator function
        return iter->second();
    }
    return nullptr;
}

std::shared_ptr<forkNodeTest::ForkClass> ForkNodeTestFactoryImpl::createForkClass ()
{
	std::shared_ptr<forkNodeTest::ForkClassImpl> element(new ForkClassImpl());
	element->setThisForkClassPtr(element);
	return element;
}

std::shared_ptr<ForkNodeTestPackage> ForkNodeTestFactoryImpl::getForkNodeTestPackage()
{
	return ForkNodeTestPackage::eInstance();
}
