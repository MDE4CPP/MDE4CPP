#include "UML4CPPProfile/impl/ExternalLibraryImpl.hpp"

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
ExternalLibraryImpl::ExternalLibraryImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_MESSAGE(std::cout<<"ExternalLibrary is created..."<<std::endl;)
	//***********************************
	// init Get Set
	//getter init
		//Property base_Package
		m_getterMap.insert(std::pair<unsigned long,std::function<Any()>>(441090789,[this](){ return eAny(this->getBase_Package(), uml::umlPackage::PACKAGE_CLASS, false);}));
		//Property includePath
		m_getterMap.insert(std::pair<unsigned long,std::function<Any()>>(83544771,[this](){ return eAny(this->getIncludePath(), types::typesPackage::STRING_CLASS, false);}));
		//Property libraryName
		m_getterMap.insert(std::pair<unsigned long,std::function<Any()>>(596096889,[this](){ return eAny(this->getLibraryName(), types::typesPackage::STRING_CLASS, false);}));
		//Property libraryPath
		m_getterMap.insert(std::pair<unsigned long,std::function<Any()>>(1321918160,[this](){ return eAny(this->getLibraryPath(), types::typesPackage::STRING_CLASS, false);}));
	
	
	//setter init
	//Property base_Package
		m_setterMap.insert(std::pair<unsigned long,std::function<void(Any)>>(441090789,[this](Any object){this->setBase_Package(object->get<std::shared_ptr<uml::Package>>());}));
	//Property includePath
		m_setterMap.insert(std::pair<unsigned long,std::function<void(Any)>>(83544771,[this](Any object){this->setIncludePath(object->get<std::string>());}));
	//Property libraryName
		m_setterMap.insert(std::pair<unsigned long,std::function<void(Any)>>(596096889,[this](Any object){this->setLibraryName(object->get<std::string>());}));
	//Property libraryPath
		m_setterMap.insert(std::pair<unsigned long,std::function<void(Any)>>(1321918160,[this](Any object){this->setLibraryPath(object->get<std::string>());}));
	
	
	//unsetter init
		//Property base_Package
		m_unsetterMap.insert(std::pair<unsigned long,std::function<void()>>(441090789,[this](){m_base_Package = std::shared_ptr<uml::Package>(nullptr);}));
	
	
	
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

	//copy attributes with no containment (soft copy)
	m_base_Package = obj.getBase_Package();
	m_includePath = obj.getIncludePath();
	m_libraryName = obj.getLibraryName();
	m_libraryPath = obj.getLibraryPath();

	//clone attributes with containment (deep copy)

	return *this;
}


std::shared_ptr<uml::Class> ExternalLibraryImpl::getMetaClass() const
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
// Union Getter
//*********************************



//*********************************
// Operations
//*********************************

//*********************************
// Structural Feature Getter/Setter
//*********************************
//Get
Any ExternalLibraryImpl::get(const std::shared_ptr<uml::Property>& _property) const
{
	std::string qualifiedName = _property->getQualifiedName();
    return this->get(qualifiedName);
}

Any ExternalLibraryImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->get(uID);
}

Any ExternalLibraryImpl::get(unsigned long _uID) const
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
void ExternalLibraryImpl::set(const std::shared_ptr<uml::Property>& _property, const Any& value)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->set(qualifiedName, value);
}

void ExternalLibraryImpl::set(std::string _qualifiedName, const Any& value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->set(uID, value);
}

void ExternalLibraryImpl::set(unsigned long _uID, const Any& value)
{
	std::map<unsigned long, std::function<void(Any)>>::const_iterator iter = m_setterMap.find(_uID);
    if(iter != m_setterMap.cend())
    {
        //invoke the setter function
        iter->second(value);
    }
}

//Unset
void ExternalLibraryImpl::unset(const std::shared_ptr<uml::Property>& _property)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->unset(qualifiedName);
}

void ExternalLibraryImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->unset(uID);
}

void ExternalLibraryImpl::unset(unsigned long _uID)
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
Any ExternalLibraryImpl::invoke(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<Bag<Any>>& _arguments)
{
	std::string qualifiedName = _operation->getQualifiedName();

	int ownedParameterSize = _operation->getOwnedParameter()->size();
	for(int i = 0; i < ownedParameterSize; i++)
	{
		qualifiedName += "_" + _operation->getOwnedParameter()->at(i)->getType()->getName();
	}

    return this->invoke(qualifiedName, _arguments);
}

Any ExternalLibraryImpl::invoke(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& _arguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->invoke(uID, _arguments);
}

Any ExternalLibraryImpl::invoke(unsigned long _uID, const std::shared_ptr<Bag<Any>>& _arguments)
{
	std::map<unsigned long, std::function<Any(std::shared_ptr<Bag<Any>>)>>::const_iterator iter = m_invocationMap.find(_uID);
    if(iter != m_invocationMap.cend()) //TODO optimize loop
    {
        //invoke the operation
        return iter->second(_arguments);
    }
	
	return eAny(nullptr, -1, false);
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


//*********************************
// ObjectActivation Forwarder Impl
//*********************************
// Getter for Active Class
bool ExternalLibraryImpl::GetIsActive() const
{
		return false;

}


