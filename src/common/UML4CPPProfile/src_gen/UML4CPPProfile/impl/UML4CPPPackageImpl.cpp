#include "UML4CPPProfile/impl/UML4CPPPackageImpl.hpp"

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
#include "uml/Package.hpp"

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
UML4CPPPackageImpl::UML4CPPPackageImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_MESSAGE(std::cout<<"UML4CPPPackage is created..."<<std::endl;)
	//***********************************
	// init Get Set
	//getter init
		//Property base_Package
		m_getterMap.insert(std::pair<unsigned long,std::function<Any()>>(364749133,[this](){ return eAny(this->getBase_Package(), uml::umlPackage::PACKAGE_CLASS, false);}));
		//Property eclipseURI
		m_getterMap.insert(std::pair<unsigned long,std::function<Any()>>(1162675821,[this](){ return eAny(this->getEclipseURI(), types::typesPackage::STRING_CLASS, false);}));
		//Property ignoreNamespace
		m_getterMap.insert(std::pair<unsigned long,std::function<Any()>>(1716152545,[this](){ return eAny(this->isIgnoreNamespace(), types::typesPackage::BOOLEAN_CLASS, false);}));
		//Property packageOnly
		m_getterMap.insert(std::pair<unsigned long,std::function<Any()>>(262131715,[this](){ return eAny(this->isPackageOnly(), types::typesPackage::BOOLEAN_CLASS, false);}));
	
	
	//setter init
	//Property base_Package
		m_setterMap.insert(std::pair<unsigned long,std::function<void(Any)>>(364749133,[this](Any object){this->setBase_Package(object->get<std::shared_ptr<uml::Package>>());}));
	//Property eclipseURI
		m_setterMap.insert(std::pair<unsigned long,std::function<void(Any)>>(1162675821,[this](Any object){this->setEclipseURI(object->get<std::string>());}));
	//Property ignoreNamespace
		m_setterMap.insert(std::pair<unsigned long,std::function<void(Any)>>(1716152545,[this](Any object){this->setIgnoreNamespace(object->get<bool>());}));
	//Property packageOnly
		m_setterMap.insert(std::pair<unsigned long,std::function<void(Any)>>(262131715,[this](Any object){this->setPackageOnly(object->get<bool>());}));
	
	
	//unsetter init
		//Property base_Package
		m_unsetterMap.insert(std::pair<unsigned long,std::function<void()>>(364749133,[this](){m_base_Package = std::shared_ptr<uml::Package>(nullptr);}));
	
	
	
}


UML4CPPPackageImpl::~UML4CPPPackageImpl()
{
	DEBUG_MESSAGE(std::cout<<"UML4CPPPackage is destroyed..."<<std::endl;)
}

UML4CPPPackageImpl::UML4CPPPackageImpl(const UML4CPPPackageImpl & obj):UML4CPPPackageImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  UML4CPPPackageImpl::copy() const
{
	std::shared_ptr<UML4CPPPackageImpl> element(new UML4CPPPackageImpl());
	*element=(*this);
	element->setThisUML4CPPPackagePtr(element);
	return element;
}

UML4CPPPackageImpl& UML4CPPPackageImpl::operator=(const UML4CPPPackageImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::StereotypeImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy UML4CPPPackage "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)
	m_base_Package = obj.getBase_Package();
	m_eclipseURI = obj.getEclipseURI();
	m_ignoreNamespace = obj.isIgnoreNamespace();
	m_packageOnly = obj.isPackageOnly();

	//clone attributes with containment (deep copy)

	return *this;
}


std::shared_ptr<uml::Class> UML4CPPPackageImpl::getMetaClass() const
{
	return UML4CPPProfilePackageImpl::eInstance()->get_UML4CPPProfile_UML4CPPPackage();
}

void UML4CPPPackageImpl::instantiate()
{   
	
	
}

void UML4CPPPackageImpl::destroy()
{	

	//Erase properties
	//deleting property base_Package
	m_base_Package.reset();
	
	
	
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void UML4CPPPackageImpl::setBase_Package(std::weak_ptr<uml::Package> _base_Package)
{
	m_base_Package = _base_Package;
	
}
std::weak_ptr<uml::Package> UML4CPPPackageImpl::getBase_Package() const 
{

	return m_base_Package;
}

void UML4CPPPackageImpl::setEclipseURI(std::string _eclipseURI)
{
	m_eclipseURI = _eclipseURI;
	
}
std::string UML4CPPPackageImpl::getEclipseURI() const 
{

	return m_eclipseURI;
}

void UML4CPPPackageImpl::setIgnoreNamespace(bool _ignoreNamespace)
{
	m_ignoreNamespace = _ignoreNamespace;
	
}
bool UML4CPPPackageImpl::isIgnoreNamespace() const 
{

	return m_ignoreNamespace;
}

void UML4CPPPackageImpl::setPackageOnly(bool _packageOnly)
{
	m_packageOnly = _packageOnly;
	
}
bool UML4CPPPackageImpl::isPackageOnly() const 
{

	return m_packageOnly;
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
Any UML4CPPPackageImpl::get(std::shared_ptr<uml::Property> _property) const
{
	std::string qualifiedName = _property->getQualifiedName();
    return this->get(qualifiedName);
}

Any UML4CPPPackageImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->get(uID);
}

Any UML4CPPPackageImpl::get(unsigned long _uID) const
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
void UML4CPPPackageImpl::set(std::shared_ptr<uml::Property> _property, Any value)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->set(qualifiedName, value);
}

void UML4CPPPackageImpl::set(std::string _qualifiedName, Any value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->set(uID, value);
}

void UML4CPPPackageImpl::set(unsigned long _uID, Any value)
{
	std::map<unsigned long, std::function<void(Any)>>::const_iterator iter = m_setterMap.find(_uID);
    if(iter != m_setterMap.cend())
    {
        //invoke the setter function
        iter->second(value);
    }
}

//Unset
void UML4CPPPackageImpl::unset(std::shared_ptr<uml::Property> _property)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->unset(qualifiedName);
}

void UML4CPPPackageImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->unset(uID);
}

void UML4CPPPackageImpl::unset(unsigned long _uID)
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
Any UML4CPPPackageImpl::invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> _arguments)
{
	std::string qualifiedName = _operation->getQualifiedName();

	for(unsigned int i = 0; i < _operation->getOwnedParameter()->size(); i++)
	{
		qualifiedName += "_" + _operation->getOwnedParameter()->at(i)->getType()->getName();
	}

    return this->invoke(qualifiedName, _arguments);
}

Any UML4CPPPackageImpl::invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> _arguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->invoke(uID, _arguments);
}

Any UML4CPPPackageImpl::invoke(unsigned long _uID, std::shared_ptr<Bag<Any>> _arguments)
{
	std::map<unsigned long, std::function<Any(std::shared_ptr<Bag<Any>>)>>::const_iterator iter = m_invocationMap.find(_uID);
    if(iter != m_invocationMap.cend())
    {
        //invoke the operation
        return iter->second(_arguments);
    }
	
	return eAny(nullptr, -1, false);
}

std::shared_ptr<UML4CPPPackage> UML4CPPPackageImpl::getThisUML4CPPPackagePtr()
{
	return m_thisUML4CPPPackagePtr.lock();
}
void UML4CPPPackageImpl::setThisUML4CPPPackagePtr(std::weak_ptr<UML4CPPPackage> thisUML4CPPPackagePtr)
{
	m_thisUML4CPPPackagePtr = thisUML4CPPPackagePtr;
	setThisStereotypePtr(thisUML4CPPPackagePtr);
}
