
#include "CheckIfPrimeImpl.hpp"
#include <QDebug>

#include "NewModelPackageImpl.hpp"

#include "Activity.hpp"

#include "PrimeChecker.hpp"



namespace NewModel {

//*********************************
// Constructor / Destructor
//*********************************

using boost::any_cast;



CheckIfPrimeImpl::CheckIfPrimeImpl()
{
	//qDebug() << __PRETTY_FUNCTION__ ;
	
	//***********************************
	// init Get Set
	//getter init
	
	
	
	
	 

}

CheckIfPrimeImpl::~CheckIfPrimeImpl()
{
}


uml::Class * CheckIfPrimeImpl::getMetaClass()
{

	return NewModelPackageImpl::eInstance()->get_NewModel_CheckIfPrime();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************




//*********************************
// Structural Feature Getter/Setter
//*********************************

boost::any CheckIfPrimeImpl::get(uml::Property * _property)
{
	//TODO: still two times run through map (contains and [])
	QString qName = _property->getQualifiedName();
    if(m_getterMap.contains(qName))
    {
        //invoke the getter function
        return m_getterMap[qName]();
    }

	return boost::any();
}

void CheckIfPrimeImpl::set(uml::Property *  _property,boost::any value)
{
	//TODO: still two times run through map (contains and [])
	QString qName = _property->getQualifiedName();
    if(m_setterMap.contains(qName))
    {
        //invoke the getter function
        return m_setterMap[qName](value);
    }

}

void CheckIfPrimeImpl::unset(uml::Property *  _property)
{
	//TODO: still two times run through map (contains and [])
	QString qName = _property->getQualifiedName();
    if(m_unsetterMap.contains(qName))
    {
        //invoke the getter function
        return m_unsetterMap[qName]();
    }

}


}

