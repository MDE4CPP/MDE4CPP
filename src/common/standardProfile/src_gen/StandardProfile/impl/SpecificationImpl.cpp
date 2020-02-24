#include "StandardProfile/impl/SpecificationImpl.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include <iostream>


#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "StandardProfile/StandardProfileFactory.hpp"
#include "StandardProfile/impl/StandardProfilePackageImpl.hpp"
#include "uml/Stereotype.hpp"
#include "uml/Classifier.hpp"




//Included from from Ports typed by interface

using namespace StandardProfile;

//*********************************
// Constructor / Destructor
//*********************************
SpecificationImpl::SpecificationImpl()
{
	//***********************************
	// init Get Set
	//getter init
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("StandardProfile::Specification::base_Classifier",[this](){ return eAny(this->getBase_Classifier());}));
	
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("StandardProfile::Specification::base_Classifier",[this](Any object){this->setBase_Classifier(object->get<std::shared_ptr<uml::Classifier>>());}));
	
	m_unsetterMap.insert(std::pair<std::string,std::function<void()>>("StandardProfile::Specification::base_Classifier",[this](){m_base_Classifier = std::shared_ptr<uml::Classifier>(nullptr);}));
	 

	// init properties without default
	
	
	// init properties with default

	// init connectors
}


SpecificationImpl::~SpecificationImpl()
{
}

SpecificationImpl::SpecificationImpl(const SpecificationImpl & obj):SpecificationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Specification "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
}

std::shared_ptr<ecore::EObject>  SpecificationImpl::copy() const
{
	std::shared_ptr<SpecificationImpl> element(new SpecificationImpl(*this));
	element->setThisSpecificationPtr(element);
	return element;
}


std::shared_ptr<uml::Class> SpecificationImpl::getMetaClass()
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_Specification();
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
// Operations
//*********************************

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any SpecificationImpl::get(std::shared_ptr<uml::Property> _property) const
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

void SpecificationImpl::set(std::shared_ptr<uml::Property> _property, Any value)
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

void SpecificationImpl::unset(std::shared_ptr<uml::Property> _property)
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


std::shared_ptr<Specification> SpecificationImpl::getThisSpecificationPtr()
{
	return m_thisSpecificationPtr.lock();
}
void SpecificationImpl::setThisSpecificationPtr(std::weak_ptr<Specification> thisSpecificationPtr)
{
	m_thisSpecificationPtr = thisSpecificationPtr;
	setThisStereotypePtr(thisSpecificationPtr);
}
