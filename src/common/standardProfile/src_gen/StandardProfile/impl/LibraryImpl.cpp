#include "StandardProfile/impl/LibraryImpl.hpp"

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
#include "uml/Artifact.hpp"




using namespace StandardProfile;

//*********************************
// Constructor / Destructor
//*********************************
LibraryImpl::LibraryImpl()
{
	//***********************************
	// init Get Set
	//getter init
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("StandardProfile::File::base_Artifact",[this](){ return eAny(this->getBase_Artifact());}));
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("StandardProfile::Library::base_Artifact",[this](){ return eAny(this->getBase_Artifact());}));
	
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("StandardProfile::File::base_Artifact",[this](Any object){this->setBase_Artifact(object->get<std::shared_ptr<uml::Artifact>>());}));
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("StandardProfile::Library::base_Artifact",[this](Any object){this->setBase_Artifact(object->get<std::shared_ptr<uml::Artifact>>());}));
	
	m_unsetterMap.insert(std::pair<std::string,std::function<void()>>("StandardProfile::File::base_Artifact",[this](){m_base_Artifact = std::shared_ptr<uml::Artifact>(nullptr);}));
	m_unsetterMap.insert(std::pair<std::string,std::function<void()>>("StandardProfile::Library::base_Artifact",[this](){m_base_Artifact = std::shared_ptr<uml::Artifact>(nullptr);}));
	 

	// init properties without default
	

	
}


LibraryImpl::~LibraryImpl()
{
}


std::shared_ptr<uml::Class> LibraryImpl::getMetaClass()
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_Library();
}

//*********************************
// Attribute Setter Getter
//*********************************
void LibraryImpl::setBase_Artifact(std::weak_ptr<uml::Artifact> _base_Artifact)
{
	m_base_Artifact = _base_Artifact;
}
std::weak_ptr<uml::Artifact> LibraryImpl::getBase_Artifact() const 
{
	return m_base_Artifact;
}

//*********************************
// Operations
//*********************************

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any LibraryImpl::get(std::shared_ptr<uml::Property> _property) const
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

void LibraryImpl::set(std::shared_ptr<uml::Property> _property, Any value)
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

void LibraryImpl::unset(std::shared_ptr<uml::Property> _property)
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


std::shared_ptr<Library> LibraryImpl::getThisLibraryPtr()
{
	return m_thisLibraryPtr.lock();
}
void LibraryImpl::setThisLibraryPtr(std::weak_ptr<Library> thisLibraryPtr)
{
	m_thisLibraryPtr = thisLibraryPtr;
	setThisFilePtr(thisLibraryPtr);
}
