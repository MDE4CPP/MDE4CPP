#include "StandardProfile/impl/DeriveImpl.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include <iostream>


#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "StandardProfile/impl/StandardProfilePackageImpl.hpp"
#include "uml/Stereotype.hpp"
#include "uml/Abstraction.hpp"




using namespace StandardProfile;

//*********************************
// Constructor / Destructor
//*********************************
DeriveImpl::DeriveImpl()
{
	//***********************************
	// init Get Set
	//getter init
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("StandardProfile::Derive::base_Abstraction",[this](){ return eAny(this->getBase_Abstraction());}));
	
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("StandardProfile::Derive::base_Abstraction",[this](Any object){this->setBase_Abstraction(object->get<std::shared_ptr<uml::Abstraction>>());}));
	
	m_unsetterMap.insert(std::pair<std::string,std::function<void()>>("StandardProfile::Derive::base_Abstraction",[this](){m_base_Abstraction = std::shared_ptr<uml::Abstraction>(nullptr);}));
	 

	// init properties without default
	

	
}


DeriveImpl::~DeriveImpl()
{
}


std::shared_ptr<uml::Class> DeriveImpl::getMetaClass()
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_Derive();
}

//*********************************
// Attribute Setter Getter
//*********************************
void DeriveImpl::setBase_Abstraction(std::weak_ptr<uml::Abstraction> _base_Abstraction)
{
	m_base_Abstraction = _base_Abstraction;
}
std::weak_ptr<uml::Abstraction> DeriveImpl::getBase_Abstraction() const 
{
	return m_base_Abstraction;
}

//*********************************
// Operations
//*********************************

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any DeriveImpl::get(std::shared_ptr<uml::Property> _property) const
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

void DeriveImpl::set(std::shared_ptr<uml::Property> _property, Any value)
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

void DeriveImpl::unset(std::shared_ptr<uml::Property> _property)
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


std::shared_ptr<Derive> DeriveImpl::getThisDerivePtr()
{
	return m_thisDerivePtr.lock();
}
void DeriveImpl::setThisDerivePtr(std::weak_ptr<Derive> thisDerivePtr)
{
	m_thisDerivePtr = thisDerivePtr;
	setThisStereotypePtr(thisDerivePtr);
}
