#include "StandardProfile/impl/MetaclassImpl.hpp"

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
MetaclassImpl::MetaclassImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_MESSAGE(std::cout<<"Metaclass is created..."<<std::endl;)
	//***********************************
	// init Get Set
	//getter init
		//Property base_Class
		m_getterMap.insert(std::pair<unsigned long,std::function<Any()>>(1215377267,[this](){ return eAny(this->getBase_Class(), uml::umlPackage::CLASS_CLASS, false);}));
	
	
	//setter init
	//Property base_Class
		m_setterMap.insert(std::pair<unsigned long,std::function<void(Any)>>(1215377267,[this](Any object){this->setBase_Class(object->get<std::shared_ptr<uml::Class>>());}));
	
	
	//unsetter init
		//Property base_Class
		m_unsetterMap.insert(std::pair<unsigned long,std::function<void()>>(1215377267,[this](){m_base_Class = std::shared_ptr<uml::Class>(nullptr);}));
	
	
	
}


MetaclassImpl::~MetaclassImpl()
{
	DEBUG_MESSAGE(std::cout<<"Metaclass is destroyed..."<<std::endl;)
}

MetaclassImpl::MetaclassImpl(const MetaclassImpl & obj):MetaclassImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  MetaclassImpl::copy() const
{
	std::shared_ptr<MetaclassImpl> element(new MetaclassImpl());
	*element=(*this);
	element->setThisMetaclassPtr(element);
	return element;
}

MetaclassImpl& MetaclassImpl::operator=(const MetaclassImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::StereotypeImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Metaclass "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)
	m_base_Class = obj.getBase_Class();

	//clone attributes with containment (deep copy)

	return *this;
}


std::shared_ptr<uml::Class> MetaclassImpl::getMetaClass() const
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_Metaclass();
}

void MetaclassImpl::instantiate()
{   
	
}

void MetaclassImpl::destroy()
{	

	//Erase properties
	//deleting property base_Class
	m_base_Class.reset();
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void MetaclassImpl::setBase_Class(std::weak_ptr<uml::Class> _base_Class)
{
	m_base_Class = _base_Class;
	
}
std::weak_ptr<uml::Class> MetaclassImpl::getBase_Class() const 
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
Any MetaclassImpl::get(const std::shared_ptr<uml::Property>& _property) const
{
	std::string qualifiedName = _property->getQualifiedName();
    return this->get(qualifiedName);
}

Any MetaclassImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->get(uID);
}

Any MetaclassImpl::get(unsigned long _uID) const
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
void MetaclassImpl::set(const std::shared_ptr<uml::Property>& _property, const Any& value)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->set(qualifiedName, value);
}

void MetaclassImpl::set(std::string _qualifiedName, const Any& value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->set(uID, value);
}

void MetaclassImpl::set(unsigned long _uID, const Any& value)
{
	std::map<unsigned long, std::function<void(Any)>>::const_iterator iter = m_setterMap.find(_uID);
    if(iter != m_setterMap.cend())
    {
        //invoke the setter function
        iter->second(value);
    }
}

//Unset
void MetaclassImpl::unset(const std::shared_ptr<uml::Property>& _property)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->unset(qualifiedName);
}

void MetaclassImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->unset(uID);
}

void MetaclassImpl::unset(unsigned long _uID)
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
Any MetaclassImpl::invoke(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<Bag<Any>>& _arguments)
{
	std::string qualifiedName = _operation->getQualifiedName();

	int ownedParameterSize = _operation->getOwnedParameter()->size();
	for(int i = 0; i < ownedParameterSize; i++)
	{
		qualifiedName += "_" + _operation->getOwnedParameter()->at(i)->getType()->getName();
	}

    return this->invoke(qualifiedName, _arguments);
}

Any MetaclassImpl::invoke(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& _arguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->invoke(uID, _arguments);
}

Any MetaclassImpl::invoke(unsigned long _uID, const std::shared_ptr<Bag<Any>>& _arguments)
{
	std::map<unsigned long, std::function<Any(std::shared_ptr<Bag<Any>>)>>::const_iterator iter = m_invocationMap.find(_uID);
    if(iter != m_invocationMap.cend()) //TODO optimize loop
    {
        //invoke the operation
        return iter->second(_arguments);
    }
	
	return eAny(nullptr, -1, false);
}

std::shared_ptr<Metaclass> MetaclassImpl::getThisMetaclassPtr()
{
	return m_thisMetaclassPtr.lock();
}
void MetaclassImpl::setThisMetaclassPtr(std::weak_ptr<Metaclass> thisMetaclassPtr)
{
	m_thisMetaclassPtr = thisMetaclassPtr;
	setThisStereotypePtr(thisMetaclassPtr);
}


//*********************************
// ObjectActivation Forwarder Impl
//*********************************
// Getter for Active Class
bool MetaclassImpl::GetIsActive() const
{
		return false;

}


