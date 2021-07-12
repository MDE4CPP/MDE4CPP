#include "UML4CPPProfile/impl/MainBehaviorImpl.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include <iostream>


#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "UML4CPPProfile/UML4CPPProfileFactory.hpp"
#include "UML4CPPProfile/impl/UML4CPPProfilePackageImpl.hpp"
#include "uml/Stereotype.hpp"

//Types included from attributes, operation parameters, imports and composite owner classes
#include "uml/Behavior.hpp"

//Packges and Factories included from types of attributes, operation parameters, imports and composite owner classes
#include "uml/umlFactory.hpp"
#include "uml/impl/umlPackageImpl.hpp"

//Packages of included Enumerations

//Includes of PluginFramework (if required)

//Includes of OpaqueBevaiors (if required)

//Includes from InstanceValues (if required)

//Includes from Ports typed by interfaces (if required)

//Includes from roles of ConnectorEnds (if required)

using namespace UML4CPPProfile;

//*********************************
// Constructor / Destructor
//*********************************
MainBehaviorImpl::MainBehaviorImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_MESSAGE(std::cout<<"MainBehavior is created..."<<std::endl;)
	//***********************************
	// init Get Set
	//getter init
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("UML4CPPProfile::MainBehavior::base_Behavior",[this](){ return eAny(this->getBase_Behavior());}));
	
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("UML4CPPProfile::MainBehavior::base_Behavior",[this](Any object){this->setBase_Behavior(object->get<std::shared_ptr<uml::Behavior>>());}));
	
	m_unsetterMap.insert(std::pair<std::string,std::function<void()>>("UML4CPPProfile::MainBehavior::base_Behavior",[this](){m_base_Behavior = std::shared_ptr<uml::Behavior>(nullptr);}));
	 
}


MainBehaviorImpl::~MainBehaviorImpl()
{
	DEBUG_MESSAGE(std::cout<<"MainBehavior is destroyed..."<<std::endl;)
}

MainBehaviorImpl::MainBehaviorImpl(const MainBehaviorImpl & obj):MainBehaviorImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  MainBehaviorImpl::copy() const
{
	std::shared_ptr<MainBehaviorImpl> element(new MainBehaviorImpl());
	*element=(*this);
	element->setThisMainBehaviorPtr(element);
	return element;
}

MainBehaviorImpl& MainBehaviorImpl::operator=(const MainBehaviorImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::StereotypeImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy MainBehavior "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();
	return *this;
}


std::shared_ptr<uml::Class> MainBehaviorImpl::getMetaClass()
{
	return UML4CPPProfilePackageImpl::eInstance()->get_UML4CPPProfile_MainBehavior();
}

void MainBehaviorImpl::instantiate()
{   
	
}

void MainBehaviorImpl::destroy()
{	

	//Erase properties
	//deleting property base_Behavior
	m_base_Behavior.reset();
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void MainBehaviorImpl::setBase_Behavior(std::weak_ptr<uml::Behavior> _base_Behavior)
{
	m_base_Behavior = _base_Behavior;
}
std::weak_ptr<uml::Behavior> MainBehaviorImpl::getBase_Behavior() const 
{
	return m_base_Behavior;
}

//*********************************
// Operations
//*********************************

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any MainBehaviorImpl::get(std::shared_ptr<uml::Property> _property) const
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

void MainBehaviorImpl::set(std::shared_ptr<uml::Property> _property, Any value)
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

void MainBehaviorImpl::unset(std::shared_ptr<uml::Property> _property)
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


std::shared_ptr<MainBehavior> MainBehaviorImpl::getThisMainBehaviorPtr()
{
	return m_thisMainBehaviorPtr.lock();
}
void MainBehaviorImpl::setThisMainBehaviorPtr(std::weak_ptr<MainBehavior> thisMainBehaviorPtr)
{
	m_thisMainBehaviorPtr = thisMainBehaviorPtr;
	setThisStereotypePtr(thisMainBehaviorPtr);
}
