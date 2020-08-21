#include "StandardProfile/impl/BuildComponentImpl.hpp"

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
BuildComponentImpl::BuildComponentImpl()
{
	#ifdef ADD_COUNT
		ADD_COUNT("BuildComponentImpl()");
	#endif

	DEBUG_MESSAGE(std::cout<<"BuildComponent is created..."<<std::endl;)

	//***********************************
	// init Get Set
	//getter init
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("StandardProfile::BuildComponent::base_Component",[this](){ return eAny(this->getBase_Component());}));
	
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("StandardProfile::BuildComponent::base_Component",[this](Any object){this->setBase_Component(object->get<std::shared_ptr<uml::Component>>());}));
	
	m_unsetterMap.insert(std::pair<std::string,std::function<void()>>("StandardProfile::BuildComponent::base_Component",[this](){m_base_Component = std::shared_ptr<uml::Component>(nullptr);}));
	 
}


BuildComponentImpl::~BuildComponentImpl()
{
	#ifdef SUB_COUNT
		SUB_COUNT("BuildComponentImpl()");
	#endif

	DEBUG_MESSAGE(std::cout<<"BuildComponent is destroyed..."<<std::endl;)
}

BuildComponentImpl::BuildComponentImpl(const BuildComponentImpl & obj):BuildComponentImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy BuildComponent "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
}

std::shared_ptr<ecore::EObject>  BuildComponentImpl::copy() const
{
	std::shared_ptr<BuildComponentImpl> element(new BuildComponentImpl(*this));
	element->setThisBuildComponentPtr(element);
	return element;
}


std::shared_ptr<uml::Class> BuildComponentImpl::getMetaClass()
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_BuildComponent();
}

void BuildComponentImpl::instantiate()
{	
	
}

void BuildComponentImpl::destroy()
{	

	//Erase properties
	//deleting property base_Component
	m_base_Component.reset();
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void BuildComponentImpl::setBase_Component(std::weak_ptr<uml::Component> _base_Component)
{
	m_base_Component = _base_Component;
}
std::weak_ptr<uml::Component> BuildComponentImpl::getBase_Component() const 
{
	return m_base_Component;
}

//*********************************
// Operations
//*********************************

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any BuildComponentImpl::get(std::shared_ptr<uml::Property> _property) const
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

void BuildComponentImpl::set(std::shared_ptr<uml::Property> _property, Any value)
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

void BuildComponentImpl::unset(std::shared_ptr<uml::Property> _property)
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


std::shared_ptr<BuildComponent> BuildComponentImpl::getThisBuildComponentPtr()
{
	return m_thisBuildComponentPtr.lock();
}
void BuildComponentImpl::setThisBuildComponentPtr(std::weak_ptr<BuildComponent> thisBuildComponentPtr)
{
	m_thisBuildComponentPtr = thisBuildComponentPtr;
	setThisStereotypePtr(thisBuildComponentPtr);
}
