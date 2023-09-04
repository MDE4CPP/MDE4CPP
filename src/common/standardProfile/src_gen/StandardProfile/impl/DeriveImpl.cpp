#include "StandardProfile/impl/DeriveImpl.hpp"

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
#include "uml/Abstraction.hpp"

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
DeriveImpl::DeriveImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_MESSAGE(std::cout<<"Derive is created..."<<std::endl;)
	//***********************************
	// init Get Set
	//getter init
		//Property base_Abstraction
		m_getterMap.insert(std::pair<unsigned long,std::function<Any()>>(893379002,[this](){ return eAny(this->getBase_Abstraction(), uml::umlPackage::ABSTRACTION_CLASS, false);}));
	
	
	//setter init
	//Property base_Abstraction
		m_setterMap.insert(std::pair<unsigned long,std::function<void(Any)>>(893379002,[this](Any object){this->setBase_Abstraction(object->get<std::shared_ptr<uml::Abstraction>>());}));
	
	
	//unsetter init
		//Property base_Abstraction
		m_unsetterMap.insert(std::pair<unsigned long,std::function<void()>>(893379002,[this](){m_base_Abstraction = std::shared_ptr<uml::Abstraction>(nullptr);}));
	
	
	
}


DeriveImpl::~DeriveImpl()
{
	DEBUG_MESSAGE(std::cout<<"Derive is destroyed..."<<std::endl;)
}

DeriveImpl::DeriveImpl(const DeriveImpl & obj):DeriveImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  DeriveImpl::copy() const
{
	std::shared_ptr<DeriveImpl> element(new DeriveImpl());
	*element=(*this);
	element->setThisDerivePtr(element);
	return element;
}

DeriveImpl& DeriveImpl::operator=(const DeriveImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::StereotypeImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Derive "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)
	m_base_Abstraction = obj.getBase_Abstraction();

	//clone attributes with containment (deep copy)

	return *this;
}


const std::shared_ptr<uml::Class>& DeriveImpl::getMetaClass() const
{
	static const std::shared_ptr<uml::Class> metaClass = StandardProfilePackageImpl::eInstance()->get_StandardProfile_Derive();
	return metaClass;
}

void DeriveImpl::instantiate()
{   
	
}

void DeriveImpl::destroy()
{	

	//Erase properties
	//deleting property base_Abstraction
	m_base_Abstraction.reset();
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void DeriveImpl::setBase_Abstraction(std::weak_ptr<uml::Abstraction> _base_Abstraction)
{
	m_base_Abstraction = _base_Abstraction;
	
}
std::weak_ptr<uml::Abstraction> DeriveImpl::getBase_Abstraction() const 
{

	return m_base_Abstraction;
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
Any DeriveImpl::get(const std::shared_ptr<uml::Property>& _property) const
{
	std::string qualifiedName = _property->getQualifiedName();
    return this->get(qualifiedName);
}

Any DeriveImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->get(uID);
}

Any DeriveImpl::get(unsigned long _uID) const
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
void DeriveImpl::set(const std::shared_ptr<uml::Property>& _property, const Any& value)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->set(qualifiedName, value);
}

void DeriveImpl::set(std::string _qualifiedName, const Any& value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->set(uID, value);
}

void DeriveImpl::set(unsigned long _uID, const Any& value)
{
	std::map<unsigned long, std::function<void(Any)>>::const_iterator iter = m_setterMap.find(_uID);
    if(iter != m_setterMap.cend())
    {
        //invoke the setter function
        iter->second(value);
    }
}

//Unset
void DeriveImpl::unset(const std::shared_ptr<uml::Property>& _property)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->unset(qualifiedName);
}

void DeriveImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->unset(uID);
}

void DeriveImpl::unset(unsigned long _uID)
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
Any DeriveImpl::invoke(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<Bag<Any>>& _arguments)
{
	std::string qualifiedName = _operation->getQualifiedName();

	int ownedParameterSize = _operation->getOwnedParameter()->size();
	for(int i = 0; i < ownedParameterSize; i++)
	{
		qualifiedName += "_" + _operation->getOwnedParameter()->at(i)->getType()->getName();
	}

    return this->invoke(qualifiedName, _arguments);
}

Any DeriveImpl::invoke(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& _arguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->invoke(uID, _arguments);
}

Any DeriveImpl::invoke(unsigned long _uID, const std::shared_ptr<Bag<Any>>& _arguments)
{
	std::map<unsigned long, std::function<Any(std::shared_ptr<Bag<Any>>)>>::const_iterator iter = m_invocationMap.find(_uID);
    if(iter != m_invocationMap.cend()) //TODO optimize loop
    {
        //invoke the operation
        return iter->second(_arguments);
    }
	
	return eAny(nullptr, -1, false);
}

std::shared_ptr<Derive> DeriveImpl::getThisDerivePtr()
{
	return m_thisDerivePtr.lock();
}
void DeriveImpl::setThisDerivePtr(std::weak_ptr<Derive> thisDerivePtr)
{
	m_thisDerivePtr = thisDerivePtr;
	setThisStereotypePtr(thisDerivePtr);
}

