#include "fUMLMultiplePins/impl/TestClassImpl.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include <iostream>


#include "abstractDataTypes/SubsetUnion.hpp"
#include "boost/any.hpp"
#include "fUMLMultiplePins/impl/FUMLMultiplePinsPackageImpl.hpp"
#include "uml/Class.hpp"
#include "fUMLMultiplePins/TestClass.hpp"





using namespace fUMLMultiplePins;
using boost::any_cast;

//*********************************
// Constructor / Destructor
//*********************************
TestClassImpl::TestClassImpl()
{
	//***********************************
	// init Get Set
	//getter init
	
	
	 

	// init properties without default
}




TestClassImpl::~TestClassImpl()
{
}

std::shared_ptr<uml::Class> TestClassImpl::getMetaClass()
{
	return FUMLMultiplePinsPackageImpl::eInstance()->get_fUMLMultiplePins_TestClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void TestClassImpl::do1(std::shared_ptr<fUMLMultiplePins::TestClass> input_1,int& param_0,int& param_1,int& param_2,int& param_3,int& param_4,int& param_5,int& param_6,int& param_7,int& param_8,int& param_9)
{

	// Implemented as Function behaviour fbDo1

std::cout << "init" << std::endl;
input_1=0;


}

void TestClassImpl::doAll(int& param_0,int& param_1,int& param_2,int& param_3,int& param_4,int& param_5,int& param_6,int& param_7,int& param_8,int& param_9)
{

	// Implemented as Function behaviour fbDoAll

param_0++;
//std::cout << "doAll:" << param_0 << std::endl;

}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any TestClassImpl::get(std::shared_ptr<uml::Property> _property) const
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

void TestClassImpl::set(std::shared_ptr<uml::Property> _property,boost::any value)
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

void TestClassImpl::unset(std::shared_ptr<uml::Property> _property)
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

std::shared_ptr<TestClass> TestClassImpl::getThisTestClassPtr()
{
	return m_thisTestClassPtr.lock();
}
void TestClassImpl::setThisTestClassPtr(std::weak_ptr<TestClass> thisTestClassPtr)
{
	m_thisTestClassPtr = thisTestClassPtr;
	setThisClassPtr(thisTestClassPtr);
}
