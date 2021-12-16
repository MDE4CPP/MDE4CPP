#include "StandardProfile/impl/SpecificationImpl.hpp"

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
#include "uml/umlPackage.hpp"
#include "uml/Classifier.hpp"

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
SpecificationImpl::SpecificationImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_MESSAGE(std::cout<<"Specification is created..."<<std::endl;)
	//***********************************
	// init Get Set
	//getter init
		//Property base_Classifier
		m_getterMap.insert(std::pair<long long,std::function<Any()>>(59271704,[this](){ return eAny(this->getBase_Classifier(), uml::umlPackage::CLASSIFIER_CLASS, false);}));
	
	
	//setter init
	//Property base_Classifier
		m_setterMap.insert(std::pair<long long,std::function<void(Any)>>(59271704,[this](Any object){this->setBase_Classifier(object->get<std::shared_ptr<uml::Classifier>>());}));
	
	
	//unsetter init
		//Property base_Classifier
		m_unsetterMap.insert(std::pair<long long,std::function<void()>>(59271704,[this](){m_base_Classifier = std::shared_ptr<uml::Classifier>(nullptr);}));
	
	
	
}


SpecificationImpl::~SpecificationImpl()
{
	DEBUG_MESSAGE(std::cout<<"Specification is destroyed..."<<std::endl;)
}

SpecificationImpl::SpecificationImpl(const SpecificationImpl & obj):SpecificationImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  SpecificationImpl::copy() const
{
	std::shared_ptr<SpecificationImpl> element(new SpecificationImpl());
	*element=(*this);
	element->setThisSpecificationPtr(element);
	return element;
}

SpecificationImpl& SpecificationImpl::operator=(const SpecificationImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::StereotypeImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Specification "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)
	m_base_Classifier = obj.getBase_Classifier();

	//clone attributes with containment (deep copy)

	return *this;
}


std::shared_ptr<uml::Class> SpecificationImpl::getMetaClass()
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_Specification();
}

void SpecificationImpl::instantiate()
{   
	
}

void SpecificationImpl::destroy()
{	

	//Erase properties
	//deleting property base_Classifier
	m_base_Classifier.reset();
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void SpecificationImpl::setBase_Classifier(std::weak_ptr<uml::Classifier> _base_Classifier)
{
	m_base_Classifier = _base_Classifier;
	
}
std::weak_ptr<uml::Classifier> SpecificationImpl::getBase_Classifier() const 
{

	return m_base_Classifier;
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
Any SpecificationImpl::get(std::shared_ptr<uml::Property> _property) const
{
	std::string qualifiedName = _property->getQualifiedName();
    return this->get(qualifiedName);
}

Any SpecificationImpl::get(std::string _qualifiedName) const
{
	long long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->get(uID);
}

Any SpecificationImpl::get(long long _uID) const
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
void SpecificationImpl::set(std::shared_ptr<uml::Property> _property, Any value)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->set(qualifiedName, value);
}

void SpecificationImpl::set(std::string _qualifiedName, Any value)
{
	long long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->set(uID, value);
}

void SpecificationImpl::set(long long _uID, Any value)
{
	std::map<long long, std::function<void(Any)>>::const_iterator iter = m_setterMap.find(_uID);
    if(iter != m_setterMap.cend())
    {
        //invoke the setter function
        iter->second(value);
    }
}

//Unset
void SpecificationImpl::unset(std::shared_ptr<uml::Property> _property)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->unset(qualifiedName);
}

void SpecificationImpl::unset(std::string _qualifiedName)
{
	long long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->unset(uID);
}

void SpecificationImpl::unset(long long _uID)
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
Any SpecificationImpl::invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> _arguments)
{
	std::string qualifiedName = _operation->getQualifiedName();

	for(unsigned int i = 0; i < _operation->getOwnedParameter()->size(); i++)
	{
		qualifiedName += "_" + _operation->getOwnedParameter()->at(i)->getType()->getName();
	}

    return this->invoke(qualifiedName, _arguments);
}

Any SpecificationImpl::invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> _arguments)
{
	long long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->invoke(uID, _arguments);
}

Any SpecificationImpl::invoke(long long _uID, std::shared_ptr<Bag<Any>> _arguments)
{
	std::map<long long, std::function<Any(std::shared_ptr<Bag<Any>>)>>::const_iterator iter = m_invocationMap.find(_uID);
    if(iter != m_invocationMap.cend())
    {
        //invoke the operation
        return iter->second(_arguments);
    }
	
	return eAny(nullptr, -1, false);
}

std::shared_ptr<Specification> SpecificationImpl::getThisSpecificationPtr()
{
	return m_thisSpecificationPtr.lock();
}
void SpecificationImpl::setThisSpecificationPtr(std::weak_ptr<Specification> thisSpecificationPtr)
{
	m_thisSpecificationPtr = thisSpecificationPtr;
	setThisStereotypePtr(thisSpecificationPtr);
}
