#include "LibraryModel_uml/impl/LibraryImpl.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include <iostream>

#include "abstractDataTypes/Bag.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "boost/any.hpp"
#include "LibraryModel_uml/impl/LibraryModel_umlPackageImpl.hpp"
#include "uml/Class.hpp"
#include "LibraryModel_uml/Author.hpp"
#include "LibraryModel_uml/Book.hpp"



using namespace LibraryModel_uml;
using boost::any_cast;

//*********************************
// Constructor / Destructor
//*********************************
LibraryImpl::LibraryImpl()
{
	//***********************************
	// init Get Set
	//getter init
	m_getterMap.insert(std::pair<std::string,std::function<boost::any()>>("LibraryModel_uml::Library::authors",[this](){ return this->getAuthors();}));
	m_getterMap.insert(std::pair<std::string,std::function<boost::any()>>("LibraryModel_uml::Library::books",[this](){ return this->getBooks();}));
	
	
	m_unsetterMap.insert(std::pair<std::string,std::function<void()>>("LibraryModel_uml::Library::authors",[this](){m_authors->clear();}));
	m_unsetterMap.insert(std::pair<std::string,std::function<void()>>("LibraryModel_uml::Library::books",[this](){m_books->clear();}));
	 

	// init properties without default
	m_authors.reset(new Bag<LibraryModel_uml::Author>());
	
	m_books.reset(new Bag<LibraryModel_uml::Book>());
	
}




LibraryImpl::~LibraryImpl()
{
}

std::shared_ptr<uml::Class> LibraryImpl::getMetaClass()
{
	return LibraryModel_umlPackageImpl::eInstance()->get_LibraryModel_uml_Library();
}

//*********************************
// Attribute Setter Getter
//*********************************

std::shared_ptr<Bag<LibraryModel_uml::Author>> LibraryImpl::getAuthors() const 
{
	return m_authors;
}


std::shared_ptr<Bag<LibraryModel_uml::Book>> LibraryImpl::getBooks() const 
{
	return m_books;
}

//*********************************
// Operations
//*********************************

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any LibraryImpl::get(std::shared_ptr<uml::Property> _property) const
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

void LibraryImpl::set(std::shared_ptr<uml::Property> _property,boost::any value)
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
	setThisClassPtr(thisLibraryPtr);
}
