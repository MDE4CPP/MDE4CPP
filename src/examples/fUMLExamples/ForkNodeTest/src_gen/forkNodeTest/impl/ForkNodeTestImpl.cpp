#include "forkNodeTest/impl/ForkNodeTestImpl.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include <iostream>


#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "forkNodeTest/impl/ForkNodeTestPackageImpl.hpp"
#include "uml/Activity.hpp"




using namespace forkNodeTest;

//*********************************
// Constructor / Destructor
//*********************************
ForkNodeTestImpl::ForkNodeTestImpl()
{
	//***********************************
	// init Get Set
	//getter init
	
	
	 

	// init properties without default

	
}




ForkNodeTestImpl::~ForkNodeTestImpl()
{
}

std::shared_ptr<uml::Class> ForkNodeTestImpl::getMetaClass()
{
	return ForkNodeTestPackageImpl::eInstance()->get_forkNodeTest_forkClass_forkNodeTest();
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
Any ForkNodeTestImpl::get(std::shared_ptr<uml::Property> _property) const
{
	//TODO: still two times run through map (contains and [])
	std::string qName = _property->getQualifiedName();
	std::map<std::string, std::function<Any()>>::const_iterator iter = m_getterMap.find(qName);
    if(iter != m_getterMap.cend())
    {
        //invoke the getter function
        return iter->second();
    }
	return eAny(nullptr);
}

void ForkNodeTestImpl::set(std::shared_ptr<uml::Property> _property, Any value)
{
	//TODO: still two times run through map (contains and [])
	std::string qName = _property->getQualifiedName();
	std::map<std::string, std::function<void(Any)>>::iterator iter = m_setterMap.find(qName);
    if(iter != m_setterMap.end())
    {
        //invoke the getter function
        iter->second(value);
    }
}

void ForkNodeTestImpl::unset(std::shared_ptr<uml::Property> _property)
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


std::shared_ptr<ForkNodeTest> ForkNodeTestImpl::getThisForkNodeTestPtr()
{
	return m_thisForkNodeTestPtr.lock();
}
void ForkNodeTestImpl::setThisForkNodeTestPtr(std::weak_ptr<ForkNodeTest> thisForkNodeTestPtr)
{
	m_thisForkNodeTestPtr = thisForkNodeTestPtr;
	setThisClassPtr(thisForkNodeTestPtr);
}
