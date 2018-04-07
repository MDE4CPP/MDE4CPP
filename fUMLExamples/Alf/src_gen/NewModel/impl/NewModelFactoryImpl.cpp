#include "NewModelFactoryImpl.hpp"
#include "NewModelPackage.hpp"
#include "Class.hpp"

using namespace NewModel;

//*********************************
// Constructor / Destructor
//*********************************
NewModelFactoryImpl::NewModelFactoryImpl()
{
	m_creatorMap.insert(std::pair<std::string,std::function<uml::Element *()>>("NewModel::CheckIfPrime",[this](){return this->createCheckIfPrime();}));
	m_creatorMap.insert(std::pair<std::string,std::function<uml::Element *()>>("NewModel::PrimeChecker",[this](){return this->createPrimeChecker();}));
}

NewModelFactoryImpl::~NewModelFactoryImpl()
{
}

NewModelFactory* NewModelFactoryImpl::create()
{
	return new NewModelFactoryImpl();
}

//*********************************
// creators
//*********************************
uml::Element * NewModelFactoryImpl::create(uml::Class * _class)
{
	if(_class->getIsAbstract())
    {
    	return nullptr;
    }

	//TODO: still two times run through map
	std::string qName = _class->getQualifiedName();
	std::map<std::string,std::function<uml::Element *()>>::iterator iter = m_creatorMap.find(qName);
    if(iter != m_creatorMap.end())
    {
		//invoke the creator function
        return iter->second();
    }

    return nullptr;
}

NewModel::CheckIfPrime * NewModelFactoryImpl::createCheckIfPrime ()
{
	return new CheckIfPrimeImpl();
}
NewModel::PrimeChecker * NewModelFactoryImpl::createPrimeChecker ()
{
	return new PrimeCheckerImpl();
}

NewModelPackage * NewModelFactoryImpl::getNewModelPackage()
{
	return NewModelPackage::eInstance();
}
