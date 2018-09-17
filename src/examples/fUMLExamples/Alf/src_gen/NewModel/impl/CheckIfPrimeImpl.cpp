
#include "CheckIfPrimeImpl.hpp"
#include "NewModelPackageImpl.hpp"
#include "Activity.hpp"
#include "PrimeChecker.hpp"

using namespace NewModel;
using boost::any_cast;

//*********************************
// Constructor / Destructor
//*********************************
CheckIfPrimeImpl::CheckIfPrimeImpl()
{
	//***********************************
	// init Get Set
	//getter init
	
	
	 
}

CheckIfPrimeImpl::~CheckIfPrimeImpl()
{
	
}

uml::Class * CheckIfPrimeImpl::getMetaClass() const
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
boost::any CheckIfPrimeImpl::get(uml::Property * _property) const
{
	//TODO: still two times run through map (contains and [])
	std::string qName = _property->getQualifiedName();
	std::map<std::string,std::function<boost::any()>>::const_iterator iter = m_getterMap.find(qName);
    if(iter != m_getterMap.cend())
    {
        //invoke the getter function
        return iter->second();
    }
	return boost::any();
}

void CheckIfPrimeImpl::set(uml::Property *  _property,boost::any value)
{
	//TODO: still two times run through map (contains and [])
	std::string qName = _property->getQualifiedName();
	std::map<std::string,std::function<void(boost::any)>>::iterator iter = m_setterMap.find(qName);
    if(iter != m_setterMap.end())
    {
        //invoke the getter function
        iter->second(value);
    }
}

void CheckIfPrimeImpl::unset(uml::Property *  _property)
{
	//TODO: still two times run through map (contains and [])
	std::string qName = _property->getQualifiedName();
	std::map<std::string,std::function<void()>>::iterator iter = m_unsetterMap.find(qName);
    if(iter != m_unsetterMap.end())
    {
        //invoke the getter function
        iter->second();
    }
}
