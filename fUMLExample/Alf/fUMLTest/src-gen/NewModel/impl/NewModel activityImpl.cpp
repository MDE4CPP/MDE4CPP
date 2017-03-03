
#include "NewModel activityImpl.hpp"
#include <QDebug>

#include "NewModelPackageImpl.hpp"

#include "Activity.hpp"




namespace NewModel {

//*********************************
// Constructor / Destructor
//*********************************

using boost::any_cast;



NewModel activityImpl::NewModel activityImpl()
{
	//qDebug() << __PRETTY_FUNCTION__ ;
	
	//***********************************
	// init Get Set
	//getter init
	
	
	
	
	 

}

NewModel activityImpl::~NewModel activityImpl()
{
}


uml::Class * NewModel activityImpl::getMetaClass()
{

	return NewModelPackageImpl::eInstance()->get_NewModel_NewModel activity();
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

boost::any NewModel activityImpl::get(uml::Property * _property)
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

void NewModel activityImpl::set(uml::Property *  _property,boost::any value)
{
	//TODO: still two times run through map (contains and [])
	QString qName = _property->getQualifiedName();
    if(m_setterMap.contains(qName))
    {
        //invoke the getter function
        return m_setterMap[qName](value);
    }

}

void NewModel activityImpl::unset(uml::Property *  _property)
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

