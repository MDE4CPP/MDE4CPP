
#include "CalculatorImpl.hpp"
#include "CalcModelPackageImpl.hpp"
#include "Class.hpp"

using namespace CalcModel;
using boost::any_cast;

//*********************************
// Constructor / Destructor
//*********************************
CalculatorImpl::CalculatorImpl()
{
	//***********************************
	// init Get Set
	//getter init
	
	
	 

	// init properties without default
}

CalculatorImpl::~CalculatorImpl()
{
}

std::shared_ptr<uml::Class> CalculatorImpl::getMetaClass() const
{
	return CalcModelPackageImpl::eInstance()->get_CalcModel_Calculator();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
int CalculatorImpl::sum(int op1,int op2)
{
	int res;

#if defined SUMACTIVITY
	// Implemented as an Activity sumActivity
	sumActivityExecution* execution = new sumActivityExecution();
	res = 	execution->execute( op1, op2);
#endif

	return res;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any CalculatorImpl::get(std::shared_ptr<uml::Property> _property) const
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

void CalculatorImpl::set(std::shared_ptr<uml::Property> _property,boost::any value)
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

void CalculatorImpl::unset(std::shared_ptr<uml::Property> _property)
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
