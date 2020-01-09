#include "StandardProfile/impl/ModelLibraryImpl.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include <iostream>


#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "StandardProfile/impl/StandardProfilePackageImpl.hpp"
#include "uml/Stereotype.hpp"
#include "uml/Package.hpp"




using namespace StandardProfile;

//*********************************
// Constructor / Destructor
//*********************************
ModelLibraryImpl::ModelLibraryImpl()
{
	//***********************************
	// init Get Set
	//getter init
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("StandardProfile::ModelLibrary::base_Package",[this](){ return eAny(this->getBase_Package());}));
	
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("StandardProfile::ModelLibrary::base_Package",[this](Any object){this->setBase_Package(object->get<std::shared_ptr<uml::Package>>());}));
	
	m_unsetterMap.insert(std::pair<std::string,std::function<void()>>("StandardProfile::ModelLibrary::base_Package",[this](){m_base_Package = std::shared_ptr<uml::Package>(nullptr);}));
	 

	// init properties without default
	

	
}


ModelLibraryImpl::~ModelLibraryImpl()
{
}


std::shared_ptr<uml::Class> ModelLibraryImpl::getMetaClass()
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_ModelLibrary();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ModelLibraryImpl::setBase_Package(std::weak_ptr<uml::Package> _base_Package)
{
	m_base_Package = _base_Package;
}
std::weak_ptr<uml::Package> ModelLibraryImpl::getBase_Package() const 
{
	return m_base_Package;
}

//*********************************
// Operations
//*********************************

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ModelLibraryImpl::get(std::shared_ptr<uml::Property> _property) const
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

void ModelLibraryImpl::set(std::shared_ptr<uml::Property> _property, Any value)
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

void ModelLibraryImpl::unset(std::shared_ptr<uml::Property> _property)
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


std::shared_ptr<ModelLibrary> ModelLibraryImpl::getThisModelLibraryPtr()
{
	return m_thisModelLibraryPtr.lock();
}
void ModelLibraryImpl::setThisModelLibraryPtr(std::weak_ptr<ModelLibrary> thisModelLibraryPtr)
{
	m_thisModelLibraryPtr = thisModelLibraryPtr;
	setThisStereotypePtr(thisModelLibraryPtr);
}
