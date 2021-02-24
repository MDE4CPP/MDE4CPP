#include "StandardProfile/impl/RefineImpl.hpp"

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

//Types included from attributes, operation parameters, imports and composite owner classes
#include "uml/Abstraction.hpp"

//Packges and Factories included from types of attributes, operation parameters, imports and composite owner classes
#include "uml/umlFactory.hpp"
#include "uml/impl/umlPackageImpl.hpp"

//Packages of included Enumerations

//Includes of PluginFramework (if required)

//Includes of OpaqueBevaiors (if required)

//Includes from InstanceValues (if required)

//Includes from Ports typed by interfaces (if required)

//Includes from roles of ConnectorEnds (if required)

using namespace StandardProfile;

//*********************************
// Constructor / Destructor
//*********************************
RefineImpl::RefineImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/

	DEBUG_MESSAGE(std::cout<<"Refine is created..."<<std::endl;)

	//***********************************
	// init Get Set
	//getter init
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("StandardProfile::Refine::base_Abstraction",[this](){ return eAny(this->getBase_Abstraction());}));
	
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("StandardProfile::Refine::base_Abstraction",[this](Any object){this->setBase_Abstraction(object->get<std::shared_ptr<uml::Abstraction>>());}));
	
	m_unsetterMap.insert(std::pair<std::string,std::function<void()>>("StandardProfile::Refine::base_Abstraction",[this](){m_base_Abstraction = std::shared_ptr<uml::Abstraction>(nullptr);}));
	 
}


RefineImpl::~RefineImpl()
{
	DEBUG_MESSAGE(std::cout<<"Refine is destroyed..."<<std::endl;)
}

RefineImpl::RefineImpl(const RefineImpl & obj):RefineImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  RefineImpl::copy() const
{
	std::shared_ptr<RefineImpl> element(new RefineImpl(*this));
	element->setThisRefinePtr(element);
	return element;
}

RefineImpl& RefineImpl::operator=(const RefineImpl & obj)
{
		//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Refine "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();
	return *this;
}


std::shared_ptr<uml::Class> RefineImpl::getMetaClass()
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_Refine();
}

void RefineImpl::instantiate()
{   
	
}

void RefineImpl::destroy()
{	

	//Erase properties
	//deleting property base_Abstraction
	m_base_Abstraction.reset();
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void RefineImpl::setBase_Abstraction(std::weak_ptr<uml::Abstraction> _base_Abstraction)
{
	m_base_Abstraction = _base_Abstraction;
}
std::weak_ptr<uml::Abstraction> RefineImpl::getBase_Abstraction() const 
{
	return m_base_Abstraction;
}

//*********************************
// Operations
//*********************************

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any RefineImpl::get(std::shared_ptr<uml::Property> _property) const
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

void RefineImpl::set(std::shared_ptr<uml::Property> _property, Any value)
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

void RefineImpl::unset(std::shared_ptr<uml::Property> _property)
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


std::shared_ptr<Refine> RefineImpl::getThisRefinePtr()
{
	return m_thisRefinePtr.lock();
}
void RefineImpl::setThisRefinePtr(std::weak_ptr<Refine> thisRefinePtr)
{
	m_thisRefinePtr = thisRefinePtr;
	setThisStereotypePtr(thisRefinePtr);
}
