#include "UML4CPPProfile/impl/DoNotGenerateImpl.hpp"

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
#include "UML4CPPProfile/UML4CPPProfileFactory.hpp"
#include "UML4CPPProfile/impl/UML4CPPProfilePackageImpl.hpp"
#include "uml/Stereotype.hpp"

//Types included from attributes, operation parameters, imports and composite owner classes
#include "uml/umlPackage.hpp"
#include "uml/Element.hpp"

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
DoNotGenerateImpl::DoNotGenerateImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_MESSAGE(std::cout<<"DoNotGenerate is created..."<<std::endl;)
	//***********************************
	// init Get Set
	//getter init
		//Property base_Element
		m_getterMap.insert(std::pair<long long,std::function<Any()>>(1158171776,[this](){ return eAny(this->getBase_Element(), uml::umlPackage::ELEMENT_CLASS, false);}));
	
	
	//setter init
	//Property base_Element
		m_setterMap.insert(std::pair<long long,std::function<void(Any)>>(1158171776,[this](Any object){this->setBase_Element(object->get<std::shared_ptr<uml::Element>>());}));
	
	
	//unsetter init
		//Property base_Element
		m_unsetterMap.insert(std::pair<long long,std::function<void()>>(1158171776,[this](){m_base_Element = std::shared_ptr<uml::Element>(nullptr);}));
	
	
	
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

	//copy attributes with no containment (soft copy)
	m_base_Element = obj.getBase_Element();

	//clone attributes with containment (deep copy)

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
// Union Getter
//*********************************



//*********************************
// Operations
//*********************************

//*********************************
// Structural Feature Getter/Setter
//*********************************
//Get
Any DoNotGenerateImpl::get(std::shared_ptr<uml::Property> _property) const
{
	std::string qualifiedName = _property->getQualifiedName();
    return this->get(qualifiedName);
}

Any DoNotGenerateImpl::get(std::string _qualifiedName) const
{
	long long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->get(uID);
}

Any DoNotGenerateImpl::get(long long _uID) const
{
	std::map<long long, std::function<Any()>>::const_iterator iter = m_getterMap.find(_uID);
    if(iter != m_getterMap.cend())
    {
        //invoke the getter function
        return iter->second();
    }

	return eAny(nullptr, -1, false);
}

//Set
void DoNotGenerateImpl::set(std::shared_ptr<uml::Property> _property, Any value)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->set(qualifiedName, value);
}

void DoNotGenerateImpl::set(std::string _qualifiedName, Any value)
{
	long long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->set(uID, value);
}

void DoNotGenerateImpl::set(long long _uID, Any value)
{
	std::map<long long, std::function<void(Any)>>::const_iterator iter = m_setterMap.find(_uID);
    if(iter != m_setterMap.cend())
    {
        //invoke the setter function
        iter->second(value);
    }
}

//Unset
void DoNotGenerateImpl::unset(std::shared_ptr<uml::Property> _property)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->unset(qualifiedName);
}

void DoNotGenerateImpl::unset(std::string _qualifiedName)
{
	long long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->unset(uID);
}

void DoNotGenerateImpl::unset(long long _uID)
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
Any DoNotGenerateImpl::invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> _arguments)
{
	std::string qualifiedName = _operation->getQualifiedName();

	for(unsigned int i = 0; i < _operation->getOwnedParameter()->size(); i++)
	{
		qualifiedName += "_" + _operation->getOwnedParameter()->at(i)->getType()->getName();
	}

    return this->invoke(qualifiedName, _arguments);
}

Any DoNotGenerateImpl::invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> _arguments)
{
	long long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->invoke(uID, _arguments);
}

Any DoNotGenerateImpl::invoke(long long _uID, std::shared_ptr<Bag<Any>> _arguments)
{
	std::map<long long, std::function<Any(std::shared_ptr<Bag<Any>>)>>::const_iterator iter = m_invocationMap.find(_uID);
    if(iter != m_invocationMap.cend())
    {
        //invoke the operation
        return iter->second(_arguments);
    }
	
	return eAny(nullptr, -1, false);
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
