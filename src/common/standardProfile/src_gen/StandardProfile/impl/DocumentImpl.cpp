#include "StandardProfile/impl/DocumentImpl.hpp"

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
DocumentImpl::DocumentImpl()
{
	//***********************************
	// init Get Set
	//getter init
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("StandardProfile::Document::base_Artifact",[this](){ return eAny(this->getBase_Artifact());}));
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("StandardProfile::File::base_Artifact",[this](){ return eAny(this->getBase_Artifact());}));
	
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("StandardProfile::Document::base_Artifact",[this](Any object){this->setBase_Artifact(object->get<std::shared_ptr<uml::Artifact>>());}));
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("StandardProfile::File::base_Artifact",[this](Any object){this->setBase_Artifact(object->get<std::shared_ptr<uml::Artifact>>());}));
	
	m_unsetterMap.insert(std::pair<std::string,std::function<void()>>("StandardProfile::Document::base_Artifact",[this](){m_base_Artifact = std::shared_ptr<uml::Artifact>(nullptr);}));
	m_unsetterMap.insert(std::pair<std::string,std::function<void()>>("StandardProfile::File::base_Artifact",[this](){m_base_Artifact = std::shared_ptr<uml::Artifact>(nullptr);}));
	 

	// init properties without default
	

	
}


DocumentImpl::~DocumentImpl()
{
}


std::shared_ptr<uml::Class> DocumentImpl::getMetaClass()
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_Document();
}

//*********************************
// Attribute Setter Getter
//*********************************
void DocumentImpl::setBase_Artifact(std::weak_ptr<uml::Artifact> _base_Artifact)
{
	m_base_Artifact = _base_Artifact;
}
std::weak_ptr<uml::Artifact> DocumentImpl::getBase_Artifact() const 
{
	return m_base_Artifact;
}

//*********************************
// Operations
//*********************************

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any DocumentImpl::get(std::shared_ptr<uml::Property> _property) const
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

void DocumentImpl::set(std::shared_ptr<uml::Property> _property, Any value)
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

void DocumentImpl::unset(std::shared_ptr<uml::Property> _property)
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


std::shared_ptr<Document> DocumentImpl::getThisDocumentPtr()
{
	return m_thisDocumentPtr.lock();
}
void DocumentImpl::setThisDocumentPtr(std::weak_ptr<Document> thisDocumentPtr)
{
	m_thisDocumentPtr = thisDocumentPtr;
	setThisFilePtr(thisDocumentPtr);
}
