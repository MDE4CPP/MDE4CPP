#include "LibraryModel_uml/impl/AuthorImpl.hpp"

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
AuthorImpl::AuthorImpl()
{
	//***********************************
	// init Get Set
	//getter init
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("LibraryModel_uml::NamedModelElement::name",[this](){ return eAny(this->getName());}));
	
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("LibraryModel_uml::NamedModelElement::name",[this](Any object){this->setName(object->get<std::string>());}));
	
	 

	// init properties without default
}




AuthorImpl::~AuthorImpl()
{
}

std::shared_ptr<uml::Class> AuthorImpl::getMetaClass()
{
	return LibraryModel_umlPackageImpl::eInstance()->get_LibraryModel_uml_Author();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any AuthorImpl::get(std::shared_ptr<uml::Property> _property) const
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

void AuthorImpl::set(std::shared_ptr<uml::Property> _property, Any value)
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

void AuthorImpl::unset(std::shared_ptr<uml::Property> _property)
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


std::shared_ptr<Author> AuthorImpl::getThisAuthorPtr()
{
	return m_thisAuthorPtr.lock();
}
void AuthorImpl::setThisAuthorPtr(std::weak_ptr<Author> thisAuthorPtr)
{
	m_thisAuthorPtr = thisAuthorPtr;
	setThisNamedModelElementPtr(thisAuthorPtr);
}
