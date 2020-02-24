#include "StandardProfile/impl/ImplementationClassImpl.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include <iostream>


#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "StandardProfile/StandardProfileFactory.hpp"
#include "StandardProfile/impl/StandardProfilePackageImpl.hpp"
#include "uml/Stereotype.hpp"
#include "uml/Class.hpp"




//Included from from Ports typed by interface

using namespace StandardProfile;

//*********************************
// Constructor / Destructor
//*********************************
ImplementationClassImpl::ImplementationClassImpl()
{
	//***********************************
	// init Get Set
	//getter init
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("StandardProfile::ImplementationClass::base_Class",[this](){ return eAny(this->getBase_Class());}));
	
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("StandardProfile::ImplementationClass::base_Class",[this](Any object){this->setBase_Class(object->get<std::shared_ptr<uml::Class>>());}));
	
	m_unsetterMap.insert(std::pair<std::string,std::function<void()>>("StandardProfile::ImplementationClass::base_Class",[this](){m_base_Class = std::shared_ptr<uml::Class>(nullptr);}));
	 

	// init properties without default
	
	
	// init properties with default

	// init connectors
}


ImplementationClassImpl::~ImplementationClassImpl()
{
}

ImplementationClassImpl::ImplementationClassImpl(const ImplementationClassImpl & obj):ImplementationClassImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ImplementationClass "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
}

std::shared_ptr<ecore::EObject>  ImplementationClassImpl::copy() const
{
	std::shared_ptr<ImplementationClassImpl> element(new ImplementationClassImpl(*this));
	element->setThisImplementationClassPtr(element);
	return element;
}


std::shared_ptr<uml::Class> ImplementationClassImpl::getMetaClass()
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_ImplementationClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ImplementationClassImpl::setBase_Class(std::weak_ptr<uml::Class> _base_Class)
{
	m_base_Class = _base_Class;
}
std::weak_ptr<uml::Class> ImplementationClassImpl::getBase_Class() const 
{
	return m_base_Class;
}

//*********************************
// Operations
//*********************************

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ImplementationClassImpl::get(std::shared_ptr<uml::Property> _property) const
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

void ImplementationClassImpl::set(std::shared_ptr<uml::Property> _property, Any value)
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

void ImplementationClassImpl::unset(std::shared_ptr<uml::Property> _property)
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


std::shared_ptr<ImplementationClass> ImplementationClassImpl::getThisImplementationClassPtr()
{
	return m_thisImplementationClassPtr.lock();
}
void ImplementationClassImpl::setThisImplementationClassPtr(std::weak_ptr<ImplementationClass> thisImplementationClassPtr)
{
	m_thisImplementationClassPtr = thisImplementationClassPtr;
	setThisStereotypePtr(thisImplementationClassPtr);
}
