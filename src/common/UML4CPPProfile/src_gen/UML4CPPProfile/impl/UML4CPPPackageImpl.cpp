#include "UML4CPPProfile/impl/UML4CPPPackageImpl.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include <iostream>


#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "UML4CPPProfile/UML4CPPProfileFactory.hpp"
#include "UML4CPPProfile/impl/UML4CPPProfilePackageImpl.hpp"
#include "uml/Stereotype.hpp"

//Types included from attributes, operation parameters, imports and composite owner classes
#include "uml/Package.hpp"

//Packges and Factories included from types of attributes, operation parameters, imports and composite owner classes
#include "uml/umlFactory.hpp"
#include "uml/impl/umlPackageImpl.hpp"

//Packages of included Enumerations

//Includes of PluginFramework (if required)

//Includes of OpaqueBevaiors (if required)

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
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("UML4CPPProfile::UML4CPPPackage::base_Package",[this](){ return eAny(this->getBase_Package());}));
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("UML4CPPProfile::UML4CPPPackage::eclipseURI",[this](){ return eAny(this->getEclipseURI());}));
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("UML4CPPProfile::UML4CPPPackage::ignoreNamespace",[this](){ return eAny(this->isIgnoreNamespace());}));
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("UML4CPPProfile::UML4CPPPackage::packageOnly",[this](){ return eAny(this->isPackageOnly());}));
	
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("UML4CPPProfile::UML4CPPPackage::base_Package",[this](Any object){this->setBase_Package(object->get<std::shared_ptr<uml::Package>>());}));
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("UML4CPPProfile::UML4CPPPackage::eclipseURI",[this](Any object){this->setEclipseURI(object->get<std::string>());}));
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("UML4CPPProfile::UML4CPPPackage::ignoreNamespace",[this](Any object){this->setIgnoreNamespace(object->get<bool>());}));
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("UML4CPPProfile::UML4CPPPackage::packageOnly",[this](Any object){this->setPackageOnly(object->get<bool>());}));
	
	m_unsetterMap.insert(std::pair<std::string,std::function<void()>>("UML4CPPProfile::UML4CPPPackage::base_Package",[this](){m_base_Package = std::shared_ptr<uml::Package>(nullptr);}));
	 
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
	m_eclipseURI = obj.getEclipseURI();
	m_ignoreNamespace = obj.isIgnoreNamespace();
	m_packageOnly = obj.isPackageOnly();
	return *this;
}


std::shared_ptr<uml::Class> UML4CPPPackageImpl::getMetaClass()
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
// Operations
//*********************************

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any UML4CPPPackageImpl::get(std::shared_ptr<uml::Property> _property) const
{
	//TODO: still two times run through map (contains and [])
	std::string qName = _property->getQualifiedName();
	std::map<std::string, std::function<Any()>>::const_iterator iter = m_getterMap.find(qName);
    if(iter != m_getterMap.cend())
    {
        //invoke the getter function
        return iter->second();
    }
	return eAny(nullptr);
}

void UML4CPPPackageImpl::set(std::shared_ptr<uml::Property> _property, Any value)
{
	//TODO: still two times run through map (contains and [])
	std::string qName = _property->getQualifiedName();
	std::map<std::string, std::function<void(Any)>>::iterator iter = m_setterMap.find(qName);
    if(iter != m_setterMap.end())
    {
        //invoke the getter function
        iter->second(value);
    }
}

void UML4CPPPackageImpl::unset(std::shared_ptr<uml::Property> _property)
{
	//TODO: still two times run through map (contains and [])
	std::string qName = _property->getQualifiedName();
	std::map<std::string,std::function<void()>>::iterator iter = m_unsetterMap.find(qName);
    if(iter != m_unsetterMap.end())
    {
        //invoke the getter function
        iter->second();
    }
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
