
#include "LibraryModel_uml/impl/BookImpl.hpp"
#include "LibraryModel_uml/impl/LibraryModel_umlPackageImpl.hpp"
#include "uml/Class.hpp"
#include "LibraryModel_uml/Author.hpp"
#include "LibraryModel_uml/Picture.hpp"

using namespace LibraryModel_uml;
using boost::any_cast;

//*********************************
// Constructor / Destructor
//*********************************
BookImpl::BookImpl()
{
	//***********************************
	// init Get Set
	//getter init
	m_getterMap.insert(std::pair<std::string,std::function<boost::any()>>("LibraryModel_uml::Book::authors",[this](){ return this->getAuthors();}));
	m_getterMap.insert(std::pair<std::string,std::function<boost::any()>>("LibraryModel_uml::Book::pictures",[this](){ return this->getPictures();}));
	m_getterMap.insert(std::pair<std::string,std::function<boost::any()>>("LibraryModel_uml::NamedModelElement::name",[this](){ return this->getName();}));
	
	m_setterMap.insert(std::pair<std::string,std::function<void(boost::any)>>("LibraryModel_uml::NamedModelElement::name",[this](boost::any object){this->setName(any_cast<std::string>(object));}));
	
	m_unsetterMap.insert(std::pair<std::string,std::function<void()>>("LibraryModel_uml::Book::authors",[this](){m_authors->clear();}));
	m_unsetterMap.insert(std::pair<std::string,std::function<void()>>("LibraryModel_uml::Book::pictures",[this](){m_pictures->clear();}));
	 

	// init properties without default
	m_authors.reset(new Bag<LibraryModel_uml::Author>());
	
	m_pictures.reset(new Bag<LibraryModel_uml::Picture>());
	
}




BookImpl::~BookImpl()
{
}

std::shared_ptr<uml::Class> BookImpl::getMetaClass()
{
	return LibraryModel_umlPackageImpl::eInstance()->get_LibraryModel_uml_Book();
}

//*********************************
// Attribute Setter Getter
//*********************************

std::shared_ptr<Bag<LibraryModel_uml::Author>> BookImpl::getAuthors() const 
{
	return m_authors;
}


std::shared_ptr<Bag<LibraryModel_uml::Picture>> BookImpl::getPictures() const 
{
	return m_pictures;
}

//*********************************
// Operations
//*********************************

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any BookImpl::get(std::shared_ptr<uml::Property> _property) const
{
	//TODO: still two times run through map (contains and [])
	std::string qName = _property->getQualifiedName();
	std::map<std::string,std::function<boost::any()>>::const_iterator iter = m_getterMap.find(qName);
    if(iter != m_getterMap.cend())
    {
        //invoke the getter function
        return iter->second();
    }
	return boost::any();
}

void BookImpl::set(std::shared_ptr<uml::Property> _property,boost::any value)
{
	//TODO: still two times run through map (contains and [])
	std::string qName = _property->getQualifiedName();
	std::map<std::string,std::function<void(boost::any)>>::iterator iter = m_setterMap.find(qName);
    if(iter != m_setterMap.end())
    {
        //invoke the getter function
        iter->second(value);
    }
}

void BookImpl::unset(std::shared_ptr<uml::Property> _property)
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
