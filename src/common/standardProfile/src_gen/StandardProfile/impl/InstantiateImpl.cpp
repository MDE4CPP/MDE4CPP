#include "StandardProfile/impl/InstantiateImpl.hpp"

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
#include "uml/Usage.hpp"




//Included from Ports typed by interface

//Included from roles of ConnectorEnds

using namespace StandardProfile;

//*********************************
// Constructor / Destructor
//*********************************
InstantiateImpl::InstantiateImpl()
{
	#ifdef ADD_COUNT
		ADD_COUNT("InstantiateImpl()");
	#endif

	DEBUG_MESSAGE(std::cout<<"Instantiate is created..."<<std::endl;)

	//***********************************
	// init Get Set
	//getter init
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("StandardProfile::Instantiate::base_Usage",[this](){ return eAny(this->getBase_Usage());}));
	
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("StandardProfile::Instantiate::base_Usage",[this](Any object){this->setBase_Usage(object->get<std::shared_ptr<uml::Usage>>());}));
	
	m_unsetterMap.insert(std::pair<std::string,std::function<void()>>("StandardProfile::Instantiate::base_Usage",[this](){m_base_Usage = std::shared_ptr<uml::Usage>(nullptr);}));
	 
}


InstantiateImpl::~InstantiateImpl()
{
	#ifdef SUB_COUNT
		SUB_COUNT("InstantiateImpl()");
	#endif

	DEBUG_MESSAGE(std::cout<<"Instantiate is destroyed..."<<std::endl;)
}

InstantiateImpl::InstantiateImpl(const InstantiateImpl & obj):InstantiateImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Instantiate "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
}

std::shared_ptr<ecore::EObject>  InstantiateImpl::copy() const
{
	std::shared_ptr<InstantiateImpl> element(new InstantiateImpl(*this));
	element->setThisInstantiatePtr(element);
	return element;
}


std::shared_ptr<uml::Class> InstantiateImpl::getMetaClass()
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_Instantiate();
}

void InstantiateImpl::instantiate()
{	
	
}

void InstantiateImpl::destroy()
{	

	//Erase properties
	//deleting property base_Usage
	m_base_Usage.reset();
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void InstantiateImpl::setBase_Usage(std::weak_ptr<uml::Usage> _base_Usage)
{
	m_base_Usage = _base_Usage;
}
std::weak_ptr<uml::Usage> InstantiateImpl::getBase_Usage() const 
{
	return m_base_Usage;
}

//*********************************
// Operations
//*********************************

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any InstantiateImpl::get(std::shared_ptr<uml::Property> _property) const
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

void InstantiateImpl::set(std::shared_ptr<uml::Property> _property, Any value)
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

void InstantiateImpl::unset(std::shared_ptr<uml::Property> _property)
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


std::shared_ptr<Instantiate> InstantiateImpl::getThisInstantiatePtr()
{
	return m_thisInstantiatePtr.lock();
}
void InstantiateImpl::setThisInstantiatePtr(std::weak_ptr<Instantiate> thisInstantiatePtr)
{
	m_thisInstantiatePtr = thisInstantiatePtr;
	setThisStereotypePtr(thisInstantiatePtr);
}
