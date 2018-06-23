#include "LibraryModel_uml/impl/NamedModelElementImpl.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include <iostream>


#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "LibraryModel_uml/impl/LibraryModel_umlPackageImpl.hpp"
#include "uml/Class.hpp"




using namespace LibraryModel_uml;

//*********************************
// Constructor / Destructor
//*********************************
NamedModelElementImpl::NamedModelElementImpl()
{
	//***********************************
	// init Get Set
	//getter init
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("LibraryModel_uml::NamedModelElement::name",[this](){ return eAny(this->getName());}));
	
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("LibraryModel_uml::NamedModelElement::name",[this](Any object){this->setName(object->get<std::string>());}));
	
	 

	// init properties without default
	
}




NamedModelElementImpl::~NamedModelElementImpl()
{
}

std::shared_ptr<uml::Class> NamedModelElementImpl::getMetaClass()
{
	return LibraryModel_umlPackageImpl::eInstance()->get_LibraryModel_uml_NamedModelElement();
}

//*********************************
// Attribute Setter Getter
//*********************************
void NamedModelElementImpl::setName(std::string _name)
{
	m_name = _name;
}
std::string NamedModelElementImpl::getName() const 
{
	return m_name;
}

//*********************************
// Operations
//*********************************

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any NamedModelElementImpl::get(std::shared_ptr<uml::Property> _property) const
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

void NamedModelElementImpl::set(std::shared_ptr<uml::Property> _property, Any value)
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

void NamedModelElementImpl::unset(std::shared_ptr<uml::Property> _property)
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


std::shared_ptr<NamedModelElement> NamedModelElementImpl::getThisNamedModelElementPtr()
{
	return m_thisNamedModelElementPtr.lock();
}
void NamedModelElementImpl::setThisNamedModelElementPtr(std::weak_ptr<NamedModelElement> thisNamedModelElementPtr)
{
	m_thisNamedModelElementPtr = thisNamedModelElementPtr;
	setThisClassPtr(thisNamedModelElementPtr);
}
