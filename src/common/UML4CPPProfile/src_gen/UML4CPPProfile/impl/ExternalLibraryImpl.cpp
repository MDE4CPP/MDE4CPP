#include "UML4CPPProfile/impl/ExternalLibraryImpl.hpp"

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
ExternalLibraryImpl::ExternalLibraryImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_MESSAGE(std::cout<<"ExternalLibrary is created..."<<std::endl;)
	//***********************************
	// init Get Set
	//getter init
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("UML4CPPProfile::ExternalLibrary::base_Package",[this](){ return eAny(this->getBase_Package());}));
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("UML4CPPProfile::ExternalLibrary::includePath",[this](){ return eAny(this->getIncludePath());}));
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("UML4CPPProfile::ExternalLibrary::libraryName",[this](){ return eAny(this->getLibraryName());}));
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("UML4CPPProfile::ExternalLibrary::libraryPath",[this](){ return eAny(this->getLibraryPath());}));
	
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("UML4CPPProfile::ExternalLibrary::base_Package",[this](Any object){this->setBase_Package(object->get<std::shared_ptr<uml::Package>>());}));
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("UML4CPPProfile::ExternalLibrary::includePath",[this](Any object){this->setIncludePath(object->get<std::string>());}));
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("UML4CPPProfile::ExternalLibrary::libraryName",[this](Any object){this->setLibraryName(object->get<std::string>());}));
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("UML4CPPProfile::ExternalLibrary::libraryPath",[this](Any object){this->setLibraryPath(object->get<std::string>());}));
	
	m_unsetterMap.insert(std::pair<std::string,std::function<void()>>("UML4CPPProfile::ExternalLibrary::base_Package",[this](){m_base_Package = std::shared_ptr<uml::Package>(nullptr);}));
	 
}


ExternalLibraryImpl::~ExternalLibraryImpl()
{
	DEBUG_MESSAGE(std::cout<<"ExternalLibrary is destroyed..."<<std::endl;)
}

ExternalLibraryImpl::ExternalLibraryImpl(const ExternalLibraryImpl & obj):ExternalLibraryImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  ExternalLibraryImpl::copy() const
{
	std::shared_ptr<ExternalLibraryImpl> element(new ExternalLibraryImpl());
	*element=(*this);
	element->setThisExternalLibraryPtr(element);
	return element;
}

ExternalLibraryImpl& ExternalLibraryImpl::operator=(const ExternalLibraryImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::StereotypeImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExternalLibrary "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();
	m_includePath = obj.getIncludePath();
	m_libraryName = obj.getLibraryName();
	m_libraryPath = obj.getLibraryPath();
	return *this;
}


std::shared_ptr<uml::Class> ExternalLibraryImpl::getMetaClass()
{
	return UML4CPPProfilePackageImpl::eInstance()->get_UML4CPPProfile_ExternalLibrary();
}

void ExternalLibraryImpl::instantiate()
{   
	
	
	
	
}

void ExternalLibraryImpl::destroy()
{	

	//Erase properties
	//deleting property base_Package
	m_base_Package.reset();
	
	
	
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void ExternalLibraryImpl::setBase_Package(std::weak_ptr<uml::Package> _base_Package)
{
	m_base_Package = _base_Package;
}
std::weak_ptr<uml::Package> ExternalLibraryImpl::getBase_Package() const 
{
	return m_base_Package;
}

void ExternalLibraryImpl::setIncludePath(std::string _includePath)
{
	m_includePath = _includePath;
}
std::string ExternalLibraryImpl::getIncludePath() const 
{
	return m_includePath;
}

void ExternalLibraryImpl::setLibraryName(std::string _libraryName)
{
	m_libraryName = _libraryName;
}
std::string ExternalLibraryImpl::getLibraryName() const 
{
	return m_libraryName;
}

void ExternalLibraryImpl::setLibraryPath(std::string _libraryPath)
{
	m_libraryPath = _libraryPath;
}
std::string ExternalLibraryImpl::getLibraryPath() const 
{
	return m_libraryPath;
}

//*********************************
// Operations
//*********************************

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ExternalLibraryImpl::get(std::shared_ptr<uml::Property> _property) const
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

void ExternalLibraryImpl::set(std::shared_ptr<uml::Property> _property, Any value)
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

void ExternalLibraryImpl::unset(std::shared_ptr<uml::Property> _property)
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


std::shared_ptr<ExternalLibrary> ExternalLibraryImpl::getThisExternalLibraryPtr()
{
	return m_thisExternalLibraryPtr.lock();
}
void ExternalLibraryImpl::setThisExternalLibraryPtr(std::weak_ptr<ExternalLibrary> thisExternalLibraryPtr)
{
	m_thisExternalLibraryPtr = thisExternalLibraryPtr;
	setThisStereotypePtr(thisExternalLibraryPtr);
}
