#include "UML4CPPProfile/impl/SingletonImpl.hpp"

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
#include "uml/Class.hpp"

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
SingletonImpl::SingletonImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_MESSAGE(std::cout<<"Singleton is created..."<<std::endl;)
	//***********************************
	// init Get Set
	//getter init
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("UML4CPPProfile::Singleton::base_Class",[this](){ return eAny(this->getBase_Class());}));
	
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("UML4CPPProfile::Singleton::base_Class",[this](Any object){this->setBase_Class(object->get<std::shared_ptr<uml::Class>>());}));
	
	m_unsetterMap.insert(std::pair<std::string,std::function<void()>>("UML4CPPProfile::Singleton::base_Class",[this](){m_base_Class = std::shared_ptr<uml::Class>(nullptr);}));
	 
}


SingletonImpl::~SingletonImpl()
{
	DEBUG_MESSAGE(std::cout<<"Singleton is destroyed..."<<std::endl;)
}

SingletonImpl::SingletonImpl(const SingletonImpl & obj):SingletonImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  SingletonImpl::copy() const
{
	std::shared_ptr<SingletonImpl> element(new SingletonImpl());
	*element=(*this);
	element->setThisSingletonPtr(element);
	return element;
}

SingletonImpl& SingletonImpl::operator=(const SingletonImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::StereotypeImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Singleton "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();
	return *this;
}


std::shared_ptr<uml::Class> SingletonImpl::getMetaClass()
{
	return UML4CPPProfilePackageImpl::eInstance()->get_UML4CPPProfile_Singleton();
}

void SingletonImpl::instantiate()
{   
	
}

void SingletonImpl::destroy()
{	

	//Erase properties
	//deleting property base_Class
	m_base_Class.reset();
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void SingletonImpl::setBase_Class(std::weak_ptr<uml::Class> _base_Class)
{
	m_base_Class = _base_Class;
}
std::weak_ptr<uml::Class> SingletonImpl::getBase_Class() const 
{
	return m_base_Class;
}

//*********************************
// Operations
//*********************************

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any SingletonImpl::get(std::shared_ptr<uml::Property> _property) const
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

void SingletonImpl::set(std::shared_ptr<uml::Property> _property, Any value)
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

void SingletonImpl::unset(std::shared_ptr<uml::Property> _property)
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


std::shared_ptr<Singleton> SingletonImpl::getThisSingletonPtr()
{
	return m_thisSingletonPtr.lock();
}
void SingletonImpl::setThisSingletonPtr(std::weak_ptr<Singleton> thisSingletonPtr)
{
	m_thisSingletonPtr = thisSingletonPtr;
	setThisStereotypePtr(thisSingletonPtr);
}
