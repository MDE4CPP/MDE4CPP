#include "StandardProfile/impl/DestroyImpl.hpp"

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
#include "uml/BehavioralFeature.hpp"




using namespace StandardProfile;

//*********************************
// Constructor / Destructor
//*********************************
DestroyImpl::DestroyImpl()
{
	//***********************************
	// init Get Set
	//getter init
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("StandardProfile::Destroy::base_BehavioralFeature",[this](){ return eAny(this->getBase_BehavioralFeature());}));
	
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("StandardProfile::Destroy::base_BehavioralFeature",[this](Any object){this->setBase_BehavioralFeature(object->get<std::shared_ptr<uml::BehavioralFeature>>());}));
	
	m_unsetterMap.insert(std::pair<std::string,std::function<void()>>("StandardProfile::Destroy::base_BehavioralFeature",[this](){m_base_BehavioralFeature = std::shared_ptr<uml::BehavioralFeature>(nullptr);}));
	 

	// init properties without default
	

	
}


DestroyImpl::~DestroyImpl()
{
}


std::shared_ptr<uml::Class> DestroyImpl::getMetaClass()
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_Destroy();
}

//*********************************
// Attribute Setter Getter
//*********************************
void DestroyImpl::setBase_BehavioralFeature(std::weak_ptr<uml::BehavioralFeature> _base_BehavioralFeature)
{
	m_base_BehavioralFeature = _base_BehavioralFeature;
}
std::weak_ptr<uml::BehavioralFeature> DestroyImpl::getBase_BehavioralFeature() const 
{
	return m_base_BehavioralFeature;
}

//*********************************
// Operations
//*********************************

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any DestroyImpl::get(std::shared_ptr<uml::Property> _property) const
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

void DestroyImpl::set(std::shared_ptr<uml::Property> _property, Any value)
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

void DestroyImpl::unset(std::shared_ptr<uml::Property> _property)
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


std::shared_ptr<Destroy> DestroyImpl::getThisDestroyPtr()
{
	return m_thisDestroyPtr.lock();
}
void DestroyImpl::setThisDestroyPtr(std::weak_ptr<Destroy> thisDestroyPtr)
{
	m_thisDestroyPtr = thisDestroyPtr;
	setThisStereotypePtr(thisDestroyPtr);
}
