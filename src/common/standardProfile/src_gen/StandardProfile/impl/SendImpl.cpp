#include "StandardProfile/impl/SendImpl.hpp"

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
#include "uml/Usage.hpp"

//Packges and Factories included from types of attributes, operation parameters, imports and composite owner classes
#include "uml/umlFactory.hpp"
#include "uml/impl/umlPackageImpl.hpp"

//Packages of included Enumerations


//Includes from InstanceValues (if required)

//Includes from Ports typed by interfaces (if required)

//Includes from roles of ConnectorEnds (if required)

using namespace StandardProfile;

//*********************************
// Constructor / Destructor
//*********************************
SendImpl::SendImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_MESSAGE(std::cout<<"Send is created..."<<std::endl;)
	//***********************************
	// init Get Set
	//getter init
		//Property base_Usage
		m_getterMap.insert(std::pair<long long,std::function<Any()>>(2030524368,[this](){ return eAny(this->getBase_Usage());}));
	
	
	//setter init
	//Property base_Usage
		m_setterMap.insert(std::pair<long long,std::function<void(Any)>>(2030524368,[this](Any object){this->setBase_Usage(object->get<std::shared_ptr<uml::Usage>>());}));
	
	
	//unsetter init
		//Property base_Usage
		m_unsetterMap.insert(std::pair<long long,std::function<void()>>(2030524368,[this](){m_base_Usage = std::shared_ptr<uml::Usage>(nullptr);}));
	
	
	
}


SendImpl::~SendImpl()
{
	DEBUG_MESSAGE(std::cout<<"Send is destroyed..."<<std::endl;)
}

SendImpl::SendImpl(const SendImpl & obj):SendImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  SendImpl::copy() const
{
	std::shared_ptr<SendImpl> element(new SendImpl());
	*element=(*this);
	element->setThisSendPtr(element);
	return element;
}

SendImpl& SendImpl::operator=(const SendImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::StereotypeImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Send "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)
	m_base_Usage = obj.getBase_Usage();

	//clone attributes with containment (deep copy)

	return *this;
}


std::shared_ptr<uml::Class> SendImpl::getMetaClass()
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_Send();
}

void SendImpl::instantiate()
{   
	
}

void SendImpl::destroy()
{	

	//Erase properties
	//deleting property base_Usage
	m_base_Usage.reset();
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void SendImpl::setBase_Usage(std::weak_ptr<uml::Usage> _base_Usage)
{
	m_base_Usage = _base_Usage;
	
}
std::weak_ptr<uml::Usage> SendImpl::getBase_Usage() const 
{

	return m_base_Usage;
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
Any SendImpl::get(std::shared_ptr<uml::Property> _property) const
{
	std::string qualifiedName = _property->getQualifiedName();
    return this->get(qualifiedName);
}

Any SendImpl::get(std::string _qualifiedName) const
{
	long long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->get(uID);
}

Any SendImpl::get(long long _uID) const
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
void SendImpl::set(std::shared_ptr<uml::Property> _property, Any value)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->set(qualifiedName, value);
}

void SendImpl::set(std::string _qualifiedName, Any value)
{
	long long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->set(uID, value);
}

void SendImpl::set(long long _uID, Any value)
{
	std::map<long long, std::function<void(Any)>>::const_iterator iter = m_setterMap.find(_uID);
    if(iter != m_setterMap.cend())
    {
        //invoke the setter function
        iter->second(value);
    }
}

//Unset
void SendImpl::unset(std::shared_ptr<uml::Property> _property)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->unset(qualifiedName);
}

void SendImpl::unset(std::string _qualifiedName)
{
	long long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->unset(uID);
}

void SendImpl::unset(long long _uID)
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
Any SendImpl::invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> _arguments)
{
	std::string qualifiedName = _operation->getQualifiedName();

	for(unsigned int i = 0; i < _operation->getOwnedParameter()->size(); i++)
	{
		qualifiedName += "_" + _operation->getOwnedParameter()->at(i)->getType()->getName();
	}

    return this->invoke(qualifiedName, _arguments);
}

Any SendImpl::invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> _arguments)
{
	long long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->invoke(uID, _arguments);
}

Any SendImpl::invoke(long long _uID, std::shared_ptr<Bag<Any>> _arguments)
{
	std::map<long long, std::function<Any(std::shared_ptr<Bag<Any>>)>>::const_iterator iter = m_invocationMap.find(_uID);
    if(iter != m_invocationMap.cend())
    {
        //invoke the operation
        return iter->second(_arguments);
    }
	
	return eAny(nullptr);
}

std::shared_ptr<Send> SendImpl::getThisSendPtr()
{
	return m_thisSendPtr.lock();
}
void SendImpl::setThisSendPtr(std::weak_ptr<Send> thisSendPtr)
{
	m_thisSendPtr = thisSendPtr;
	setThisStereotypePtr(thisSendPtr);
}
