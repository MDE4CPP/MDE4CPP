
#include "NewModelFactoryImpl.hpp"
#include "NewModelPackage.hpp"



#include "Class.hpp"

namespace NewModel {

//*********************************
// Constructor / Destructor
//*********************************

NewModelFactoryImpl::NewModelFactoryImpl()
{
	m_creatorMap.insert("NewModel::PrimeChecker",[this](){return this->createPrimeChecker();});
	m_creatorMap.insert("NewModel::CheckIfPrime",[this](){return this->createCheckIfPrime();});
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
	QString qName = _class->getQualifiedName();
    if(m_creatorMap.contains(qName))
    {
		//invoke the creator function
    	return m_creatorMap[qName]();
    }

    return nullptr;
}

NewModel::PrimeChecker * NewModelFactoryImpl::createPrimeChecker ()
{
	//qDebug() << __PRETTY_FUNCTION__ ;
	return new PrimeCheckerImpl();
}
NewModel::CheckIfPrime * NewModelFactoryImpl::createCheckIfPrime ()
{
	//qDebug() << __PRETTY_FUNCTION__ ;
	return new CheckIfPrimeImpl();
}

NewModelPackage * NewModelFactoryImpl::getNewModelPackage()
{
	return NewModelPackage::eInstance();
}

}

