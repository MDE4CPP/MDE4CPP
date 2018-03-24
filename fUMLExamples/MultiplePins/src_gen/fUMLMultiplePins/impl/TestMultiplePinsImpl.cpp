#include "fUMLMultiplePins/impl/TestMultiplePinsImpl.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include <iostream>


#include "abstractDataTypes/SubsetUnion.hpp"
#include "boost/any.hpp"
#include "fUMLMultiplePins/impl/FUMLMultiplePinsPackageImpl.hpp"
#include "uml/Activity.hpp"
#include "fUMLMultiplePins/TestClass.hpp"



using namespace fUMLMultiplePins;
using boost::any_cast;

//*********************************
// Constructor / Destructor
//*********************************
TestMultiplePinsImpl::TestMultiplePinsImpl()
{
	//***********************************
	// init Get Set
	//getter init
	
	
	 

	// init properties without default
}




TestMultiplePinsImpl::~TestMultiplePinsImpl()
{
}

std::shared_ptr<uml::Class> TestMultiplePinsImpl::getMetaClass()
{
	return FUMLMultiplePinsPackageImpl::eInstance()->get_fUMLMultiplePins_TestClass_TestMultiplePins();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any TestMultiplePinsImpl::get(std::shared_ptr<uml::Property> _property) const
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

void TestMultiplePinsImpl::set(std::shared_ptr<uml::Property> _property,boost::any value)
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

void TestMultiplePinsImpl::unset(std::shared_ptr<uml::Property> _property)
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

std::shared_ptr<TestMultiplePins> TestMultiplePinsImpl::getThisTestMultiplePinsPtr()
{
	return m_thisTestMultiplePinsPtr.lock();
}
void TestMultiplePinsImpl::setThisTestMultiplePinsPtr(std::weak_ptr<TestMultiplePins> thisTestMultiplePinsPtr)
{
	m_thisTestMultiplePinsPtr = thisTestMultiplePinsPtr;
	setThisClassPtr(thisTestMultiplePinsPtr);
}
