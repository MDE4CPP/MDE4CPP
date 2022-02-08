#include "StandardProfile/impl/CreateImpl.hpp"

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
#include "uml/umlPackage.hpp"
#include "uml/BehavioralFeature.hpp"
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
CreateImpl::CreateImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_MESSAGE(std::cout<<"Create is created..."<<std::endl;)
	//***********************************
	// init Get Set
	//getter init
		//Property base_BehavioralFeature
		m_getterMap.insert(std::pair<unsigned long,std::function<Any()>>(2108279685,[this](){ return eAny(this->getBase_BehavioralFeature(), uml::umlPackage::BEHAVIORALFEATURE_CLASS, false);}));
		//Property base_Usage
		m_getterMap.insert(std::pair<unsigned long,std::function<Any()>>(2008362745,[this](){ return eAny(this->getBase_Usage(), uml::umlPackage::USAGE_CLASS, false);}));
	
	
	//setter init
	//Property base_BehavioralFeature
		m_setterMap.insert(std::pair<unsigned long,std::function<void(Any)>>(2108279685,[this](Any object){this->setBase_BehavioralFeature(object->get<std::shared_ptr<uml::BehavioralFeature>>());}));
	//Property base_Usage
		m_setterMap.insert(std::pair<unsigned long,std::function<void(Any)>>(2008362745,[this](Any object){this->setBase_Usage(object->get<std::shared_ptr<uml::Usage>>());}));
	
	
	//unsetter init
		//Property base_BehavioralFeature
		m_unsetterMap.insert(std::pair<unsigned long,std::function<void()>>(2108279685,[this](){m_base_BehavioralFeature = std::shared_ptr<uml::BehavioralFeature>(nullptr);}));
		//Property base_Usage
		m_unsetterMap.insert(std::pair<unsigned long,std::function<void()>>(2008362745,[this](){m_base_Usage = std::shared_ptr<uml::Usage>(nullptr);}));
	
	
	
}


CreateImpl::~CreateImpl()
{
	DEBUG_MESSAGE(std::cout<<"Create is destroyed..."<<std::endl;)
}

CreateImpl::CreateImpl(const CreateImpl & obj):CreateImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  CreateImpl::copy() const
{
	std::shared_ptr<CreateImpl> element(new CreateImpl());
	*element=(*this);
	element->setThisCreatePtr(element);
	return element;
}

CreateImpl& CreateImpl::operator=(const CreateImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::StereotypeImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Create "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)
	m_base_BehavioralFeature = obj.getBase_BehavioralFeature();
	m_base_Usage = obj.getBase_Usage();

	//clone attributes with containment (deep copy)

	return *this;
}


std::shared_ptr<uml::Class> CreateImpl::getMetaClass() const
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_Create();
}

void CreateImpl::instantiate()
{   
	
	
}

void CreateImpl::destroy()
{	

	//Erase properties
	//deleting property base_BehavioralFeature
	m_base_BehavioralFeature.reset();
	
	//deleting property base_Usage
	m_base_Usage.reset();
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void CreateImpl::setBase_BehavioralFeature(std::weak_ptr<uml::BehavioralFeature> _base_BehavioralFeature)
{
	m_base_BehavioralFeature = _base_BehavioralFeature;
	
}
std::weak_ptr<uml::BehavioralFeature> CreateImpl::getBase_BehavioralFeature() const 
{

	return m_base_BehavioralFeature;
}

void CreateImpl::setBase_Usage(std::weak_ptr<uml::Usage> _base_Usage)
{
	m_base_Usage = _base_Usage;
	
}
std::weak_ptr<uml::Usage> CreateImpl::getBase_Usage() const 
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
Any CreateImpl::get(std::shared_ptr<uml::Property> _property) const
{
	std::string qualifiedName = _property->getQualifiedName();
    return this->get(qualifiedName);
}

Any CreateImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->get(uID);
}

Any CreateImpl::get(unsigned long _uID) const
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
void CreateImpl::set(std::shared_ptr<uml::Property> _property, Any value)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->set(qualifiedName, value);
}

void CreateImpl::set(std::string _qualifiedName, Any value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->set(uID, value);
}

void CreateImpl::set(unsigned long _uID, Any value)
{
	std::map<unsigned long, std::function<void(Any)>>::const_iterator iter = m_setterMap.find(_uID);
    if(iter != m_setterMap.cend())
    {
        //invoke the setter function
        iter->second(value);
    }
}

//Unset
void CreateImpl::unset(std::shared_ptr<uml::Property> _property)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->unset(qualifiedName);
}

void CreateImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->unset(uID);
}

void CreateImpl::unset(unsigned long _uID)
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
Any CreateImpl::invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> _arguments)
{
	std::string qualifiedName = _operation->getQualifiedName();

	for(unsigned int i = 0; i < _operation->getOwnedParameter()->size(); i++)
	{
		qualifiedName += "_" + _operation->getOwnedParameter()->at(i)->getType()->getName();
	}

    return this->invoke(qualifiedName, _arguments);
}

Any CreateImpl::invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> _arguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->invoke(uID, _arguments);
}

Any CreateImpl::invoke(unsigned long _uID, std::shared_ptr<Bag<Any>> _arguments)
{
	std::map<unsigned long, std::function<Any(std::shared_ptr<Bag<Any>>)>>::const_iterator iter = m_invocationMap.find(_uID);
    if(iter != m_invocationMap.cend())
    {
        //invoke the operation
        return iter->second(_arguments);
    }
	
	return eAny(nullptr, -1, false);
}

std::shared_ptr<Create> CreateImpl::getThisCreatePtr()
{
	return m_thisCreatePtr.lock();
}
void CreateImpl::setThisCreatePtr(std::weak_ptr<Create> thisCreatePtr)
{
	m_thisCreatePtr = thisCreatePtr;
	setThisStereotypePtr(thisCreatePtr);
}
