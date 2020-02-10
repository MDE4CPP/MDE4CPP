#include "StandardProfile/impl/ResponsibilityImpl.hpp"

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
#include "uml/Usage.hpp"




using namespace StandardProfile;

//*********************************
// Constructor / Destructor
//*********************************
ResponsibilityImpl::ResponsibilityImpl()
{
	//***********************************
	// init Get Set
	//getter init
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("StandardProfile::Responsibility::base_Usage",[this](){ return eAny(this->getBase_Usage());}));
	
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("StandardProfile::Responsibility::base_Usage",[this](Any object){this->setBase_Usage(object->get<std::shared_ptr<uml::Usage>>());}));
	
	m_unsetterMap.insert(std::pair<std::string,std::function<void()>>("StandardProfile::Responsibility::base_Usage",[this](){m_base_Usage = std::shared_ptr<uml::Usage>(nullptr);}));
	 

	// init properties without default
	

	
}


ResponsibilityImpl::~ResponsibilityImpl()
{
}


std::shared_ptr<uml::Class> ResponsibilityImpl::getMetaClass()
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_Responsibility();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ResponsibilityImpl::setBase_Usage(std::weak_ptr<uml::Usage> _base_Usage)
{
	m_base_Usage = _base_Usage;
}
std::weak_ptr<uml::Usage> ResponsibilityImpl::getBase_Usage() const 
{
	return m_base_Usage;
}

//*********************************
// Operations
//*********************************

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ResponsibilityImpl::get(std::shared_ptr<uml::Property> _property) const
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

void ResponsibilityImpl::set(std::shared_ptr<uml::Property> _property, Any value)
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

void ResponsibilityImpl::unset(std::shared_ptr<uml::Property> _property)
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


std::shared_ptr<Responsibility> ResponsibilityImpl::getThisResponsibilityPtr()
{
	return m_thisResponsibilityPtr.lock();
}
void ResponsibilityImpl::setThisResponsibilityPtr(std::weak_ptr<Responsibility> thisResponsibilityPtr)
{
	m_thisResponsibilityPtr = thisResponsibilityPtr;
	setThisStereotypePtr(thisResponsibilityPtr);
}
