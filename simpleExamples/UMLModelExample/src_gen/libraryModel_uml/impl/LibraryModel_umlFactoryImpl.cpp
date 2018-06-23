#include "LibraryModel_uml/impl/LibraryModel_umlFactoryImpl.hpp"
#include "LibraryModel_uml/LibraryModel_umlPackage.hpp"

#include "abstractDataTypes/Bag.hpp"
#include "uml/Class.hpp"

#include "LibraryModel_uml/impl/AuthorImpl.hpp"
#include "LibraryModel_uml/impl/BookImpl.hpp"
#include "LibraryModel_uml/impl/LibraryImpl.hpp"
#include "LibraryModel_uml/impl/NamedModelElementImpl.hpp"
#include "LibraryModel_uml/impl/PictureImpl.hpp"

using namespace LibraryModel_uml;

//*********************************
// Constructor / Destructor
//*********************************
LibraryModel_umlFactoryImpl::LibraryModel_umlFactoryImpl()
{
	m_creatorMap.insert(std::pair<std::string,std::function<std::shared_ptr<uml::Element>()>>("Author",[this](){return this->createAuthor();}));
	m_creatorMap.insert(std::pair<std::string,std::function<std::shared_ptr<uml::Element>()>>("Book",[this](){return this->createBook();}));
	m_creatorMap.insert(std::pair<std::string,std::function<std::shared_ptr<uml::Element>()>>("Library",[this](){return this->createLibrary();}));
	m_creatorMap.insert(std::pair<std::string,std::function<std::shared_ptr<uml::Element>()>>("NamedModelElement",[this](){return this->createNamedModelElement();}));
	m_creatorMap.insert(std::pair<std::string,std::function<std::shared_ptr<uml::Element>()>>("Picture",[this](){return this->createPicture();}));
}

LibraryModel_umlFactoryImpl::~LibraryModel_umlFactoryImpl()
{
}

LibraryModel_umlFactory* LibraryModel_umlFactoryImpl::create()
{
	return new LibraryModel_umlFactoryImpl();
}

//*********************************
// creators
//*********************************
std::shared_ptr<uml::Element> LibraryModel_umlFactoryImpl::create(std::shared_ptr<uml::Class> _class)
{
	if(_class->getIsAbstract())
    {
    	return nullptr;
    }

	//TODO: still two times run through map
	std::string _className = _class->getName();
	return create(_className);
}

std::shared_ptr<uml::Element> LibraryModel_umlFactoryImpl::create(std::string _className)
{
	std::map<std::string,std::function<std::shared_ptr<uml::Element>()>>::iterator iter = m_creatorMap.find(_className);
    if(iter != m_creatorMap.end())
    {
		//invoke the creator function
        return iter->second();
    }
    return nullptr;
}

std::shared_ptr<LibraryModel_uml::Author> LibraryModel_umlFactoryImpl::createAuthor ()
{
	std::shared_ptr<LibraryModel_uml::AuthorImpl> element(new AuthorImpl());
	element->setThisAuthorPtr(element);
	return element;
}
std::shared_ptr<LibraryModel_uml::Author> LibraryModel_umlFactoryImpl::createAuthor_in_Library(std::shared_ptr<LibraryModel_uml::Library> library)
{
	std::shared_ptr<LibraryModel_uml::AuthorImpl> element(new AuthorImpl());
	if (nullptr != library)
	{
		library->getAuthors()->push_back(element);
	}
	element->setThisAuthorPtr(element);
	return element;
}
std::shared_ptr<LibraryModel_uml::Book> LibraryModel_umlFactoryImpl::createBook ()
{
	std::shared_ptr<LibraryModel_uml::BookImpl> element(new BookImpl());
	element->setThisBookPtr(element);
	return element;
}
std::shared_ptr<LibraryModel_uml::Book> LibraryModel_umlFactoryImpl::createBook_in_Library(std::shared_ptr<LibraryModel_uml::Library> library)
{
	std::shared_ptr<LibraryModel_uml::BookImpl> element(new BookImpl());
	if (nullptr != library)
	{
		library->getBooks()->push_back(element);
	}
	element->setThisBookPtr(element);
	return element;
}
std::shared_ptr<LibraryModel_uml::Library> LibraryModel_umlFactoryImpl::createLibrary ()
{
	std::shared_ptr<LibraryModel_uml::LibraryImpl> element(new LibraryImpl());
	element->setThisLibraryPtr(element);
	return element;
}
std::shared_ptr<LibraryModel_uml::NamedModelElement> LibraryModel_umlFactoryImpl::createNamedModelElement ()
{
	std::shared_ptr<LibraryModel_uml::NamedModelElementImpl> element(new NamedModelElementImpl());
	element->setThisNamedModelElementPtr(element);
	return element;
}
std::shared_ptr<LibraryModel_uml::Picture> LibraryModel_umlFactoryImpl::createPicture ()
{
	std::shared_ptr<LibraryModel_uml::PictureImpl> element(new PictureImpl());
	element->setThisPicturePtr(element);
	return element;
}
std::shared_ptr<LibraryModel_uml::Picture> LibraryModel_umlFactoryImpl::createPicture_in_Book(std::shared_ptr<LibraryModel_uml::Book> book)
{
	std::shared_ptr<LibraryModel_uml::PictureImpl> element(new PictureImpl());
	if (nullptr != book)
	{
		book->getPictures()->push_back(element);
	}
	element->setThisPicturePtr(element);
	return element;
}

std::shared_ptr<LibraryModel_umlPackage> LibraryModel_umlFactoryImpl::getLibraryModel_umlPackage()
{
	return LibraryModel_umlPackage::eInstance();
}
