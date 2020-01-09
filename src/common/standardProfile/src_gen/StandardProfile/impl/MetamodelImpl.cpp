#include "StandardProfile/impl/MetamodelImpl.hpp"

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
#include "uml/Model.hpp"




using namespace StandardProfile;

//*********************************
// Constructor / Destructor
//*********************************
MetamodelImpl::MetamodelImpl()
{
	//***********************************
	// init Get Set
	//getter init
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("StandardProfile::Metamodel::base_Model",[this](){ return eAny(this->getBase_Model());}));
	
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("StandardProfile::Metamodel::base_Model",[this](Any object){this->setBase_Model(object->get<std::shared_ptr<uml::Model>>());}));
	
	m_unsetterMap.insert(std::pair<std::string,std::function<void()>>("StandardProfile::Metamodel::base_Model",[this](){m_base_Model = std::shared_ptr<uml::Model>(nullptr);}));
	 

	// init properties without default
	

	
}


MetamodelImpl::~MetamodelImpl()
{
}


std::shared_ptr<uml::Class> MetamodelImpl::getMetaClass()
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_Metamodel();
}

//*********************************
// Attribute Setter Getter
//*********************************
void MetamodelImpl::setBase_Model(std::weak_ptr<uml::Model> _base_Model)
{
	m_base_Model = _base_Model;
}
std::weak_ptr<uml::Model> MetamodelImpl::getBase_Model() const 
{
	return m_base_Model;
}

//*********************************
// Operations
//*********************************

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any MetamodelImpl::get(std::shared_ptr<uml::Property> _property) const
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

void MetamodelImpl::set(std::shared_ptr<uml::Property> _property, Any value)
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

void MetamodelImpl::unset(std::shared_ptr<uml::Property> _property)
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


std::shared_ptr<Metamodel> MetamodelImpl::getThisMetamodelPtr()
{
	return m_thisMetamodelPtr.lock();
}
void MetamodelImpl::setThisMetamodelPtr(std::weak_ptr<Metamodel> thisMetamodelPtr)
{
	m_thisMetamodelPtr = thisMetamodelPtr;
	setThisStereotypePtr(thisMetamodelPtr);
}
