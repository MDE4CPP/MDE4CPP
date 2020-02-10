#include "StandardProfile/impl/CreateImpl.hpp"

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
#include "uml/Usage.hpp"




using namespace StandardProfile;

//*********************************
// Constructor / Destructor
//*********************************
CreateImpl::CreateImpl()
{
	//***********************************
	// init Get Set
	//getter init
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("StandardProfile::Create::base_BehavioralFeature",[this](){ return eAny(this->getBase_BehavioralFeature());}));
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("StandardProfile::Create::base_Usage",[this](){ return eAny(this->getBase_Usage());}));
	
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("StandardProfile::Create::base_BehavioralFeature",[this](Any object){this->setBase_BehavioralFeature(object->get<std::shared_ptr<uml::BehavioralFeature>>());}));
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("StandardProfile::Create::base_Usage",[this](Any object){this->setBase_Usage(object->get<std::shared_ptr<uml::Usage>>());}));
	
	m_unsetterMap.insert(std::pair<std::string,std::function<void()>>("StandardProfile::Create::base_BehavioralFeature",[this](){m_base_BehavioralFeature = std::shared_ptr<uml::BehavioralFeature>(nullptr);}));
	m_unsetterMap.insert(std::pair<std::string,std::function<void()>>("StandardProfile::Create::base_Usage",[this](){m_base_Usage = std::shared_ptr<uml::Usage>(nullptr);}));
	 

	// init properties without default
	
	

	
}


CreateImpl::~CreateImpl()
{
}


std::shared_ptr<uml::Class> CreateImpl::getMetaClass()
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_Create();
}

//*********************************
// Attribute Setter Getter
//*********************************
void CreateImpl::setBase_BehavioralFeature(std::weak_ptr<uml::BehavioralFeature> _base_BehavioralFeature)
{
	m_base_BehavioralFeature = _base_BehavioralFeature;
}
std::weak_ptr<uml::BehavioralFeature> CreateImpl::getBase_BehavioralFeature() const 
{
	return m_base_BehavioralFeature;
}

void CreateImpl::setBase_Usage(std::weak_ptr<uml::Usage> _base_Usage)
{
	m_base_Usage = _base_Usage;
}
std::weak_ptr<uml::Usage> CreateImpl::getBase_Usage() const 
{
	return m_base_Usage;
}

//*********************************
// Operations
//*********************************

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any CreateImpl::get(std::shared_ptr<uml::Property> _property) const
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

void CreateImpl::set(std::shared_ptr<uml::Property> _property, Any value)
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

void CreateImpl::unset(std::shared_ptr<uml::Property> _property)
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


std::shared_ptr<Create> CreateImpl::getThisCreatePtr()
{
	return m_thisCreatePtr.lock();
}
void CreateImpl::setThisCreatePtr(std::weak_ptr<Create> thisCreatePtr)
{
	m_thisCreatePtr = thisCreatePtr;
	setThisStereotypePtr(thisCreatePtr);
}
