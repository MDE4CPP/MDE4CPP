#include "UML4CPPProfile/impl/NonExecutableImpl.hpp"

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
#include "uml/NamedElement.hpp"

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
NonExecutableImpl::NonExecutableImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_MESSAGE(std::cout<<"NonExecutable is created..."<<std::endl;)
	//***********************************
	// init Get Set
	//getter init
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("UML4CPPProfile::NonExecutable::base_NamedElement",[this](){ return eAny(this->getBase_NamedElement());}));
	
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("UML4CPPProfile::NonExecutable::base_NamedElement",[this](Any object){this->setBase_NamedElement(object->get<std::shared_ptr<uml::NamedElement>>());}));
	
	m_unsetterMap.insert(std::pair<std::string,std::function<void()>>("UML4CPPProfile::NonExecutable::base_NamedElement",[this](){m_base_NamedElement = std::shared_ptr<uml::NamedElement>(nullptr);}));
	 
}


NonExecutableImpl::~NonExecutableImpl()
{
	DEBUG_MESSAGE(std::cout<<"NonExecutable is destroyed..."<<std::endl;)
}

NonExecutableImpl::NonExecutableImpl(const NonExecutableImpl & obj):NonExecutableImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  NonExecutableImpl::copy() const
{
	std::shared_ptr<NonExecutableImpl> element(new NonExecutableImpl());
	*element=(*this);
	element->setThisNonExecutablePtr(element);
	return element;
}

NonExecutableImpl& NonExecutableImpl::operator=(const NonExecutableImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::StereotypeImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy NonExecutable "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();
	return *this;
}


std::shared_ptr<uml::Class> NonExecutableImpl::getMetaClass()
{
	return UML4CPPProfilePackageImpl::eInstance()->get_UML4CPPProfile_NonExecutable();
}

void NonExecutableImpl::instantiate()
{   
	
}

void NonExecutableImpl::destroy()
{	

	//Erase properties
	//deleting property base_NamedElement
	m_base_NamedElement.reset();
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void NonExecutableImpl::setBase_NamedElement(std::weak_ptr<uml::NamedElement> _base_NamedElement)
{
	m_base_NamedElement = _base_NamedElement;
}
std::weak_ptr<uml::NamedElement> NonExecutableImpl::getBase_NamedElement() const 
{
	return m_base_NamedElement;
}

//*********************************
// Operations
//*********************************

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any NonExecutableImpl::get(std::shared_ptr<uml::Property> _property) const
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

void NonExecutableImpl::set(std::shared_ptr<uml::Property> _property, Any value)
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

void NonExecutableImpl::unset(std::shared_ptr<uml::Property> _property)
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


std::shared_ptr<NonExecutable> NonExecutableImpl::getThisNonExecutablePtr()
{
	return m_thisNonExecutablePtr.lock();
}
void NonExecutableImpl::setThisNonExecutablePtr(std::weak_ptr<NonExecutable> thisNonExecutablePtr)
{
	m_thisNonExecutablePtr = thisNonExecutablePtr;
	setThisStereotypePtr(thisNonExecutablePtr);
}
