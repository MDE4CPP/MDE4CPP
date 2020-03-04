#include "StandardProfile/impl/ProcessImpl.hpp"

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
#include "uml/Component.hpp"




//Included from Ports typed by interface

//Included from roles of ConnectorEnds

using namespace StandardProfile;

//*********************************
// Constructor / Destructor
//*********************************
ProcessImpl::ProcessImpl()
{
	//***********************************
	// init Get Set
	//getter init
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("StandardProfile::Process::base_Component",[this](){ return eAny(this->getBase_Component());}));
	
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("StandardProfile::Process::base_Component",[this](Any object){this->setBase_Component(object->get<std::shared_ptr<uml::Component>>());}));
	
	m_unsetterMap.insert(std::pair<std::string,std::function<void()>>("StandardProfile::Process::base_Component",[this](){m_base_Component = std::shared_ptr<uml::Component>(nullptr);}));
	 

	// init properties without default
	
	
	// init properties with default

	// init connectors
}


ProcessImpl::~ProcessImpl()
{
}

ProcessImpl::ProcessImpl(const ProcessImpl & obj):ProcessImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Process "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
}

std::shared_ptr<ecore::EObject>  ProcessImpl::copy() const
{
	std::shared_ptr<ProcessImpl> element(new ProcessImpl(*this));
	element->setThisProcessPtr(element);
	return element;
}


std::shared_ptr<uml::Class> ProcessImpl::getMetaClass()
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_Process();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ProcessImpl::setBase_Component(std::weak_ptr<uml::Component> _base_Component)
{
	m_base_Component = _base_Component;
}
std::weak_ptr<uml::Component> ProcessImpl::getBase_Component() const 
{
	return m_base_Component;
}

//*********************************
// Operations
//*********************************

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ProcessImpl::get(std::shared_ptr<uml::Property> _property) const
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

void ProcessImpl::set(std::shared_ptr<uml::Property> _property, Any value)
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

void ProcessImpl::unset(std::shared_ptr<uml::Property> _property)
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


std::shared_ptr<Process> ProcessImpl::getThisProcessPtr()
{
	return m_thisProcessPtr.lock();
}
void ProcessImpl::setThisProcessPtr(std::weak_ptr<Process> thisProcessPtr)
{
	m_thisProcessPtr = thisProcessPtr;
	setThisStereotypePtr(thisProcessPtr);
}
