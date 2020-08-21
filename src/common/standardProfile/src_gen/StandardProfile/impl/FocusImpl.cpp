#include "StandardProfile/impl/FocusImpl.hpp"

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




//Included from Ports typed by interface

//Included from roles of ConnectorEnds

using namespace StandardProfile;

//*********************************
// Constructor / Destructor
//*********************************
FocusImpl::FocusImpl()
{
	#ifdef ADD_COUNT
		ADD_COUNT("FocusImpl()");
	#endif

	DEBUG_MESSAGE(std::cout<<"Focus is created..."<<std::endl;)

	//***********************************
	// init Get Set
	//getter init
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("StandardProfile::Focus::base_Class",[this](){ return eAny(this->getBase_Class());}));
	
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("StandardProfile::Focus::base_Class",[this](Any object){this->setBase_Class(object->get<std::shared_ptr<uml::Class>>());}));
	
	m_unsetterMap.insert(std::pair<std::string,std::function<void()>>("StandardProfile::Focus::base_Class",[this](){m_base_Class = std::shared_ptr<uml::Class>(nullptr);}));
	 
}


FocusImpl::~FocusImpl()
{
	#ifdef SUB_COUNT
		SUB_COUNT("FocusImpl()");
	#endif

	DEBUG_MESSAGE(std::cout<<"Focus is destroyed..."<<std::endl;)
}

FocusImpl::FocusImpl(const FocusImpl & obj):FocusImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Focus "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
}

std::shared_ptr<ecore::EObject>  FocusImpl::copy() const
{
	std::shared_ptr<FocusImpl> element(new FocusImpl(*this));
	element->setThisFocusPtr(element);
	return element;
}


std::shared_ptr<uml::Class> FocusImpl::getMetaClass()
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_Focus();
}

void FocusImpl::instantiate()
{	
	
}

void FocusImpl::destroy()
{	

	//Erase properties
	//deleting property base_Class
	m_base_Class.reset();
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void FocusImpl::setBase_Class(std::weak_ptr<uml::Class> _base_Class)
{
	m_base_Class = _base_Class;
}
std::weak_ptr<uml::Class> FocusImpl::getBase_Class() const 
{
	return m_base_Class;
}

//*********************************
// Operations
//*********************************

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any FocusImpl::get(std::shared_ptr<uml::Property> _property) const
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

void FocusImpl::set(std::shared_ptr<uml::Property> _property, Any value)
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

void FocusImpl::unset(std::shared_ptr<uml::Property> _property)
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


std::shared_ptr<Focus> FocusImpl::getThisFocusPtr()
{
	return m_thisFocusPtr.lock();
}
void FocusImpl::setThisFocusPtr(std::weak_ptr<Focus> thisFocusPtr)
{
	m_thisFocusPtr = thisFocusPtr;
	setThisStereotypePtr(thisFocusPtr);
}
