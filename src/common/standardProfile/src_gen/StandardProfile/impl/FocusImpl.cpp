#include "StandardProfile/impl/FocusImpl.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include <iostream>


#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "util/util.hpp"
#include "uml/Property.hpp"
#include "uml/Operation.hpp"
#include "uml/Parameter.hpp"
#include "StandardProfile/StandardProfileFactory.hpp"
#include "StandardProfile/impl/StandardProfilePackageImpl.hpp"
#include "uml/Stereotype.hpp"

//Types included from attributes, operation parameters, imports and composite owner classes
#include "uml/umlPackage.hpp"
#include "uml/Class.hpp"

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
FocusImpl::FocusImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_MESSAGE(std::cout<<"Focus is created..."<<std::endl;)
	//***********************************
	// init Get Set
	//getter init
		//Property base_Class
		m_getterMap.insert(std::pair<unsigned long,std::function<Any()>>(1705935987,[this](){ return eAny(this->getBase_Class(), uml::umlPackage::CLASS_CLASS, false);}));
	
	
	//setter init
	//Property base_Class
		m_setterMap.insert(std::pair<unsigned long,std::function<void(Any)>>(1705935987,[this](Any object){this->setBase_Class(object->get<std::shared_ptr<uml::Class>>());}));
	
	
	//unsetter init
		//Property base_Class
		m_unsetterMap.insert(std::pair<unsigned long,std::function<void()>>(1705935987,[this](){m_base_Class = std::shared_ptr<uml::Class>(nullptr);}));
	
	
	
}


FocusImpl::~FocusImpl()
{
	DEBUG_MESSAGE(std::cout<<"Focus is destroyed..."<<std::endl;)
}

FocusImpl::FocusImpl(const FocusImpl & obj):FocusImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  FocusImpl::copy() const
{
	std::shared_ptr<FocusImpl> element(new FocusImpl());
	*element=(*this);
	element->setThisFocusPtr(element);
	return element;
}

FocusImpl& FocusImpl::operator=(const FocusImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::StereotypeImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Focus "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)
	m_base_Class = obj.getBase_Class();

	//clone attributes with containment (deep copy)

	return *this;
}


const std::shared_ptr<uml::Class>& FocusImpl::getMetaClass() const
{
	static const std::shared_ptr<uml::Class> metaClass = StandardProfilePackageImpl::eInstance()->get_StandardProfile_Focus();
	return metaClass;
}

void FocusImpl::instantiate()
{   
	
}

void FocusImpl::destroy()
{	

	//Erase properties
	//deleting property base_Class
	m_base_Class.reset();
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void FocusImpl::setBase_Class(std::weak_ptr<uml::Class> _base_Class)
{
	m_base_Class = _base_Class;
	
}
std::weak_ptr<uml::Class> FocusImpl::getBase_Class() const 
{

	return m_base_Class;
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
Any FocusImpl::get(const std::shared_ptr<uml::Property>& _property) const
{
	std::string qualifiedName = _property->getQualifiedName();
    return this->get(qualifiedName);
}

Any FocusImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->get(uID);
}

Any FocusImpl::get(unsigned long _uID) const
{
	std::map<unsigned long, std::function<Any()>>::const_iterator iter = m_getterMap.find(_uID);
    if(iter != m_getterMap.cend())
    {
        //invoke the getter function
        return iter->second();
    }

	return eAny(nullptr, -1, false);
}

//Set
void FocusImpl::set(const std::shared_ptr<uml::Property>& _property, const Any& value)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->set(qualifiedName, value);
}

void FocusImpl::set(std::string _qualifiedName, const Any& value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->set(uID, value);
}

void FocusImpl::set(unsigned long _uID, const Any& value)
{
	std::map<unsigned long, std::function<void(Any)>>::const_iterator iter = m_setterMap.find(_uID);
    if(iter != m_setterMap.cend())
    {
        //invoke the setter function
        iter->second(value);
    }
}

//Unset
void FocusImpl::unset(const std::shared_ptr<uml::Property>& _property)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->unset(qualifiedName);
}

void FocusImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->unset(uID);
}

void FocusImpl::unset(unsigned long _uID)
{
	std::map<unsigned long, std::function<void()>>::const_iterator iter = m_unsetterMap.find(_uID);
    if(iter != m_unsetterMap.cend()) //TODO optimize loop
    {
        //invoke the unsetter function
        iter->second();
    }
}


//*********************************
// Operation Invoction
//*********************************
//Invoke
Any FocusImpl::invoke(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<Bag<Any>>& _arguments)
{
	std::string qualifiedName = _operation->getQualifiedName();

	int ownedParameterSize = _operation->getOwnedParameter()->size();
	for(int i = 0; i < ownedParameterSize; i++)
	{
		qualifiedName += "_" + _operation->getOwnedParameter()->at(i)->getType()->getName();
	}

    return this->invoke(qualifiedName, _arguments);
}

Any FocusImpl::invoke(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& _arguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->invoke(uID, _arguments);
}

Any FocusImpl::invoke(unsigned long _uID, const std::shared_ptr<Bag<Any>>& _arguments)
{
	std::map<unsigned long, std::function<Any(std::shared_ptr<Bag<Any>>)>>::const_iterator iter = m_invocationMap.find(_uID);
    if(iter != m_invocationMap.cend()) //TODO optimize loop
    {
        //invoke the operation
        return iter->second(_arguments);
    }
	
	return eAny(nullptr, -1, false);
}

std::shared_ptr<Focus> FocusImpl::getThisFocusPtr()
{
	return m_thisFocusPtr.lock();
}
void FocusImpl::setThisFocusPtr(std::weak_ptr<Focus> thisFocusPtr)
{
	m_thisFocusPtr = thisFocusPtr;
	setThisStereotypePtr(thisFocusPtr);
}

