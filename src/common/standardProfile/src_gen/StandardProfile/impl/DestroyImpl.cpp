#include "StandardProfile/impl/DestroyImpl.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include <iostream>


#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "util/util.hpp"
#include "uml/Property.hpp"
#include "uml/Operation.hpp"
#include "uml/Parameter.hpp"
#include "StandardProfile/StandardProfileFactory.hpp"
#include "StandardProfile/impl/StandardProfilePackageImpl.hpp"
#include "uml/Stereotype.hpp"

//Types included from attributes, operation parameters, imports and composite owner classes
#include "uml/BehavioralFeature.hpp"

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
DestroyImpl::DestroyImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_MESSAGE(std::cout<<"Destroy is created..."<<std::endl;)
	//***********************************
	// init Get Set
	//getter init
		//Property base_BehavioralFeature
		m_getterMap.insert(std::pair<long long,std::function<Any()>>(891766883,[this](){ return eAny(this->getBase_BehavioralFeature());}));
	
	
	//setter init
	//Property base_BehavioralFeature
		m_setterMap.insert(std::pair<long long,std::function<void(Any)>>(891766883,[this](Any object){this->setBase_BehavioralFeature(object->get<std::shared_ptr<uml::BehavioralFeature>>());}));
	
	
	//unsetter init
		//Property base_BehavioralFeature
		m_unsetterMap.insert(std::pair<long long,std::function<void()>>(891766883,[this](){m_base_BehavioralFeature = std::shared_ptr<uml::BehavioralFeature>(nullptr);}));
	
	
	
}


DestroyImpl::~DestroyImpl()
{
	DEBUG_MESSAGE(std::cout<<"Destroy is destroyed..."<<std::endl;)
}

DestroyImpl::DestroyImpl(const DestroyImpl & obj):DestroyImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  DestroyImpl::copy() const
{
	std::shared_ptr<DestroyImpl> element(new DestroyImpl());
	*element=(*this);
	element->setThisDestroyPtr(element);
	return element;
}

DestroyImpl& DestroyImpl::operator=(const DestroyImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::StereotypeImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Destroy "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)
	m_base_BehavioralFeature = obj.getBase_BehavioralFeature();

	//clone attributes with containment (deep copy)

	return *this;
}


std::shared_ptr<uml::Class> DestroyImpl::getMetaClass()
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_Destroy();
}

void DestroyImpl::instantiate()
{   
	
}

void DestroyImpl::destroy()
{	

	//Erase properties
	//deleting property base_BehavioralFeature
	m_base_BehavioralFeature.reset();
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void DestroyImpl::setBase_BehavioralFeature(std::weak_ptr<uml::BehavioralFeature> _base_BehavioralFeature)
{
	m_base_BehavioralFeature = _base_BehavioralFeature;
	
}
std::weak_ptr<uml::BehavioralFeature> DestroyImpl::getBase_BehavioralFeature() const 
{

	return m_base_BehavioralFeature;
}

//*********************************
// Union Getter
//*********************************



//*********************************
// Operations
//*********************************

//*********************************
// Structural Feature Getter/Setter
//*********************************
//Get
Any DestroyImpl::get(std::shared_ptr<uml::Property> _property) const
{
	std::string qualifiedName = _property->getQualifiedName();
    return this->get(qualifiedName);
}

Any DestroyImpl::get(std::string _qualifiedName) const
{
	long long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->get(uID);
}

Any DestroyImpl::get(long long _uID) const
{
	std::map<long long, std::function<Any()>>::const_iterator iter = m_getterMap.find(_uID);
    if(iter != m_getterMap.cend())
    {
        //invoke the getter function
        return iter->second();
    }

	return eAny(nullptr);
}

//Set
void DestroyImpl::set(std::shared_ptr<uml::Property> _property, Any value)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->set(qualifiedName, value);
}

void DestroyImpl::set(std::string _qualifiedName, Any value)
{
	long long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->set(uID, value);
}

void DestroyImpl::set(long long _uID, Any value)
{
	std::map<long long, std::function<void(Any)>>::const_iterator iter = m_setterMap.find(_uID);
    if(iter != m_setterMap.cend())
    {
        //invoke the setter function
        iter->second(value);
    }
}

//Unset
void DestroyImpl::unset(std::shared_ptr<uml::Property> _property)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->unset(qualifiedName);
}

void DestroyImpl::unset(std::string _qualifiedName)
{
	long long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->unset(uID);
}

void DestroyImpl::unset(long long _uID)
{
	std::map<long long, std::function<void()>>::const_iterator iter = m_unsetterMap.find(_uID);
    if(iter != m_unsetterMap.cend())
    {
        //invoke the unsetter function
        iter->second();
    }
}


//*********************************
// Operation Invoction
//*********************************
//Invoke
Any DestroyImpl::invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> _arguments)
{
	std::string qualifiedName = _operation->getQualifiedName();

	for(unsigned int i = 0; i < _operation->getOwnedParameter()->size(); i++)
	{
		qualifiedName += "_" + _operation->getOwnedParameter()->at(i)->getType()->getName();
	}

    return this->invoke(qualifiedName, _arguments);
}

Any DestroyImpl::invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> _arguments)
{
	long long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->invoke(uID, _arguments);
}

Any DestroyImpl::invoke(long long _uID, std::shared_ptr<Bag<Any>> _arguments)
{
	std::map<long long, std::function<Any(std::shared_ptr<Bag<Any>>)>>::const_iterator iter = m_invocationMap.find(_uID);
    if(iter != m_invocationMap.cend())
    {
        //invoke the operation
        return iter->second(_arguments);
    }
	
	return eAny(nullptr);
}

std::shared_ptr<Destroy> DestroyImpl::getThisDestroyPtr()
{
	return m_thisDestroyPtr.lock();
}
void DestroyImpl::setThisDestroyPtr(std::weak_ptr<Destroy> thisDestroyPtr)
{
	m_thisDestroyPtr = thisDestroyPtr;
	setThisStereotypePtr(thisDestroyPtr);
}
