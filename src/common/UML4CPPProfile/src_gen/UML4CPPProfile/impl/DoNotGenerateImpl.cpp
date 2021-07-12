#include "UML4CPPProfile/impl/DoNotGenerateImpl.hpp"

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
#include "uml/Element.hpp"

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
DoNotGenerateImpl::DoNotGenerateImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_MESSAGE(std::cout<<"DoNotGenerate is created..."<<std::endl;)
	//***********************************
	// init Get Set
	//getter init
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("UML4CPPProfile::DoNotGenerate::base_Element",[this](){ return eAny(this->getBase_Element());}));
	
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("UML4CPPProfile::DoNotGenerate::base_Element",[this](Any object){this->setBase_Element(object->get<std::shared_ptr<uml::Element>>());}));
	
	m_unsetterMap.insert(std::pair<std::string,std::function<void()>>("UML4CPPProfile::DoNotGenerate::base_Element",[this](){m_base_Element = std::shared_ptr<uml::Element>(nullptr);}));
	 
}


DoNotGenerateImpl::~DoNotGenerateImpl()
{
	DEBUG_MESSAGE(std::cout<<"DoNotGenerate is destroyed..."<<std::endl;)
}

DoNotGenerateImpl::DoNotGenerateImpl(const DoNotGenerateImpl & obj):DoNotGenerateImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  DoNotGenerateImpl::copy() const
{
	std::shared_ptr<DoNotGenerateImpl> element(new DoNotGenerateImpl());
	*element=(*this);
	element->setThisDoNotGeneratePtr(element);
	return element;
}

DoNotGenerateImpl& DoNotGenerateImpl::operator=(const DoNotGenerateImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::StereotypeImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DoNotGenerate "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();
	if (obj.getBase_Element() != nullptr)
	{
	m_base_Element = std::dynamic_pointer_cast<uml::Element>(obj.getBase_Element()->copy());
	}
	return *this;
}


std::shared_ptr<uml::Class> DoNotGenerateImpl::getMetaClass()
{
	return UML4CPPProfilePackageImpl::eInstance()->get_UML4CPPProfile_DoNotGenerate();
}

void DoNotGenerateImpl::instantiate()
{   
	
}

void DoNotGenerateImpl::destroy()
{	

	//Erase properties
	//deleting property base_Element
	m_base_Element.reset();
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void DoNotGenerateImpl::setBase_Element(std::shared_ptr<uml::Element> _base_Element)
{
	m_base_Element = _base_Element;
}
std::shared_ptr<uml::Element> DoNotGenerateImpl::getBase_Element() const 
{
	return m_base_Element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any DoNotGenerateImpl::get(std::shared_ptr<uml::Property> _property) const
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

void DoNotGenerateImpl::set(std::shared_ptr<uml::Property> _property, Any value)
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

void DoNotGenerateImpl::unset(std::shared_ptr<uml::Property> _property)
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


std::shared_ptr<DoNotGenerate> DoNotGenerateImpl::getThisDoNotGeneratePtr()
{
	return m_thisDoNotGeneratePtr.lock();
}
void DoNotGenerateImpl::setThisDoNotGeneratePtr(std::weak_ptr<DoNotGenerate> thisDoNotGeneratePtr)
{
	m_thisDoNotGeneratePtr = thisDoNotGeneratePtr;
	setThisStereotypePtr(thisDoNotGeneratePtr);
}
