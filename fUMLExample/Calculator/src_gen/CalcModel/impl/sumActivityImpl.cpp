
#include "sumActivityImpl.hpp"
#include "CalcModelPackageImpl.hpp"
#include "Activity.hpp"

using namespace CalcModel;
using boost::any_cast;

//*********************************
// Constructor / Destructor
//*********************************
sumActivityImpl::sumActivityImpl()
{
	//***********************************
	// init Get Set
	//getter init
	
	
	 

	// init properties without default
}

sumActivityImpl::~sumActivityImpl()
{
}

std::shared_ptr<uml::Class> sumActivityImpl::getMetaClass() const
{
	return CalcModelPackageImpl::eInstance()->get_CalcModel_Calculator_sumActivity();
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
boost::any sumActivityImpl::get(std::shared_ptr<uml::Property> _property) const
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

void sumActivityImpl::set(std::shared_ptr<uml::Property> _property,boost::any value)
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

void sumActivityImpl::unset(std::shared_ptr<uml::Property> _property)
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
