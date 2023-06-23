#include "UML4CPPProfile/impl/GetterNameImpl.hpp"

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
#include "UML4CPPProfile/UML4CPPProfileFactory.hpp"
#include "UML4CPPProfile/impl/UML4CPPProfilePackageImpl.hpp"
#include "uml/Stereotype.hpp"

//Types included from attributes, operation parameters, imports and composite owner classes
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"
#include "uml/Property.hpp"

//Packges and Factories included from types of attributes, operation parameters, imports and composite owner classes
#include "uml/umlFactory.hpp"
#include "uml/impl/umlPackageImpl.hpp"

//Packages of included Enumerations


//Includes from InstanceValues (if required)

//Includes from Ports typed by interfaces (if required)

//Includes from roles of ConnectorEnds (if required)

using namespace UML4CPPProfile;

//*********************************
// Constructor / Destructor
//*********************************
GetterNameImpl::GetterNameImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_MESSAGE(std::cout<<"GetterName is created..."<<std::endl;)
	//***********************************
	// init Get Set
	//getter init
		//Property base_Property
		m_getterMap.insert(std::pair<unsigned long,std::function<Any()>>(14802423,[this](){ return eAny(this->getBase_Property(), uml::umlPackage::PROPERTY_CLASS, false);}));
		//Property getterName
		m_getterMap.insert(std::pair<unsigned long,std::function<Any()>>(1932053206,[this](){ return eAny(this->getGetterName(), types::typesPackage::STRING_CLASS, false);}));
	
	
	//setter init
	//Property base_Property
		m_setterMap.insert(std::pair<unsigned long,std::function<void(Any)>>(14802423,[this](Any object){this->setBase_Property(object->get<std::shared_ptr<uml::Property>>());}));
	//Property getterName
		m_setterMap.insert(std::pair<unsigned long,std::function<void(Any)>>(1932053206,[this](Any object){this->setGetterName(object->get<std::string>());}));
	
	
	//unsetter init
		//Property base_Property
		m_unsetterMap.insert(std::pair<unsigned long,std::function<void()>>(14802423,[this](){m_base_Property = std::shared_ptr<uml::Property>(nullptr);}));
	
	
	
}


GetterNameImpl::~GetterNameImpl()
{
	DEBUG_MESSAGE(std::cout<<"GetterName is destroyed..."<<std::endl;)
}

GetterNameImpl::GetterNameImpl(const GetterNameImpl & obj):GetterNameImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  GetterNameImpl::copy() const
{
	std::shared_ptr<GetterNameImpl> element(new GetterNameImpl());
	*element=(*this);
	element->setThisGetterNamePtr(element);
	return element;
}

GetterNameImpl& GetterNameImpl::operator=(const GetterNameImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::StereotypeImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy GetterName "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)
	m_base_Property = obj.getBase_Property();
	m_getterName = obj.getGetterName();

	//clone attributes with containment (deep copy)

	return *this;
}


std::shared_ptr<uml::Class> GetterNameImpl::getMetaClass() const
{
	return UML4CPPProfilePackageImpl::eInstance()->get_UML4CPPProfile_GetterName();
}

void GetterNameImpl::instantiate()
{   
	
	
}

void GetterNameImpl::destroy()
{	

	//Erase properties
	//deleting property base_Property
	m_base_Property.reset();
	
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void GetterNameImpl::setBase_Property(std::weak_ptr<uml::Property> _base_Property)
{
	m_base_Property = _base_Property;
	
}
std::weak_ptr<uml::Property> GetterNameImpl::getBase_Property() const 
{

	return m_base_Property;
}

void GetterNameImpl::setGetterName(std::string _getterName)
{
	m_getterName = _getterName;
	
}
std::string GetterNameImpl::getGetterName() const 
{

	return m_getterName;
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
Any GetterNameImpl::get(std::shared_ptr<uml::Property> _property) const
{
	std::string qualifiedName = _property->getQualifiedName();
    return this->get(qualifiedName);
}

Any GetterNameImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->get(uID);
}

Any GetterNameImpl::get(unsigned long _uID) const
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
void GetterNameImpl::set(std::shared_ptr<uml::Property> _property, Any value)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->set(qualifiedName, value);
}

void GetterNameImpl::set(std::string _qualifiedName, Any value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->set(uID, value);
}

void GetterNameImpl::set(unsigned long _uID, Any value)
{
	std::map<unsigned long, std::function<void(Any)>>::const_iterator iter = m_setterMap.find(_uID);
    if(iter != m_setterMap.cend())
    {
        //invoke the setter function
        iter->second(value);
    }
}

//Unset
void GetterNameImpl::unset(std::shared_ptr<uml::Property> _property)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->unset(qualifiedName);
}

void GetterNameImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->unset(uID);
}

void GetterNameImpl::unset(unsigned long _uID)
{
	std::map<unsigned long, std::function<void()>>::const_iterator iter = m_unsetterMap.find(_uID);
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
Any GetterNameImpl::invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> _arguments)
{
	std::string qualifiedName = _operation->getQualifiedName();

	for(unsigned int i = 0; i < _operation->getOwnedParameter()->size(); i++)
	{
		qualifiedName += "_" + _operation->getOwnedParameter()->at(i)->getType()->getName();
	}

    return this->invoke(qualifiedName, _arguments);
}

Any GetterNameImpl::invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> _arguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->invoke(uID, _arguments);
}

Any GetterNameImpl::invoke(unsigned long _uID, std::shared_ptr<Bag<Any>> _arguments)
{
	std::map<unsigned long, std::function<Any(std::shared_ptr<Bag<Any>>)>>::const_iterator iter = m_invocationMap.find(_uID);
    if(iter != m_invocationMap.cend())
    {
        //invoke the operation
        return iter->second(_arguments);
    }
	
	return eAny(nullptr, -1, false);
}

std::shared_ptr<GetterName> GetterNameImpl::getThisGetterNamePtr()
{
	return m_thisGetterNamePtr.lock();
}
void GetterNameImpl::setThisGetterNamePtr(std::weak_ptr<GetterName> thisGetterNamePtr)
{
	m_thisGetterNamePtr = thisGetterNamePtr;
	setThisStereotypePtr(thisGetterNamePtr);
}


//*********************************
// ObjectActivation Forwarder Impl
//*********************************
// Getter for Active Class
bool GetterNameImpl::GetIsActive() const
{
		return false;

}


