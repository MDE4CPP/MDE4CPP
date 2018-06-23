#include "fUMLMultiplePins/impl/FUMLMultiplePinsFactoryImpl.hpp"
#include "fUMLMultiplePins/FUMLMultiplePinsPackage.hpp"

#include "abstractDataTypes/Bag.hpp"
#include "uml/Class.hpp"

#include "fUMLMultiplePins/impl/TestClassImpl.hpp"

using namespace fUMLMultiplePins;

//*********************************
// Constructor / Destructor
//*********************************
FUMLMultiplePinsFactoryImpl::FUMLMultiplePinsFactoryImpl()
{
	m_creatorMap.insert(std::pair<std::string,std::function<std::shared_ptr<uml::Element>()>>("TestClass",[this](){return this->createTestClass();}));
}

FUMLMultiplePinsFactoryImpl::~FUMLMultiplePinsFactoryImpl()
{
}

FUMLMultiplePinsFactory* FUMLMultiplePinsFactoryImpl::create()
{
	return new FUMLMultiplePinsFactoryImpl();
}

//*********************************
// creators
//*********************************
std::shared_ptr<uml::Element> FUMLMultiplePinsFactoryImpl::create(std::shared_ptr<uml::Class> _class)
{
	if(_class->getIsAbstract())
    {
    	return nullptr;
    }

	//TODO: still two times run through map
	std::string _className = _class->getName();
	return create(_className);
}

std::shared_ptr<uml::Element> FUMLMultiplePinsFactoryImpl::create(std::string _className)
{
	std::map<std::string,std::function<std::shared_ptr<uml::Element>()>>::iterator iter = m_creatorMap.find(_className);
    if(iter != m_creatorMap.end())
    {
		//invoke the creator function
        return iter->second();
    }
    return nullptr;
}

std::shared_ptr<fUMLMultiplePins::TestClass> FUMLMultiplePinsFactoryImpl::createTestClass ()
{
	std::shared_ptr<fUMLMultiplePins::TestClassImpl> element(new TestClassImpl());
	element->setThisTestClassPtr(element);
	return element;
}

std::shared_ptr<FUMLMultiplePinsPackage> FUMLMultiplePinsFactoryImpl::getFUMLMultiplePinsPackage()
{
	return FUMLMultiplePinsPackage::eInstance();
}
