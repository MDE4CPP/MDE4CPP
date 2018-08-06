#include "libraryModel_ecore/impl/LibraryModel_ecoreFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "libraryModel_ecore/LibraryModel_ecorePackage.hpp"

#include "ecore/EClass.hpp"


#include "libraryModel_ecore/impl/AuthorImpl.hpp"
#include "libraryModel_ecore/impl/BookImpl.hpp"
#include "libraryModel_ecore/impl/LibraryModelImpl.hpp"
#include "libraryModel_ecore/impl/NamedElementImpl.hpp"
#include "libraryModel_ecore/impl/PictureImpl.hpp"

using namespace libraryModel_ecore;

//*********************************
// Constructor / Destructor
//*********************************

LibraryModel_ecoreFactoryImpl::LibraryModel_ecoreFactoryImpl()
{
	m_idMap.insert(std::make_pair("Author", LibraryModel_ecorePackage::AUTHOR_ECLASS));
	m_idMap.insert(std::make_pair("Book", LibraryModel_ecorePackage::BOOK_ECLASS));
	m_idMap.insert(std::make_pair("LibraryModel", LibraryModel_ecorePackage::LIBRARYMODEL_ECLASS));
	m_idMap.insert(std::make_pair("NamedElement", LibraryModel_ecorePackage::NAMEDELEMENT_ECLASS));
	m_idMap.insert(std::make_pair("Picture", LibraryModel_ecorePackage::PICTURE_ECLASS));
}

LibraryModel_ecoreFactoryImpl::~LibraryModel_ecoreFactoryImpl()
{
}

LibraryModel_ecoreFactory* LibraryModel_ecoreFactoryImpl::create()
{
	return new LibraryModel_ecoreFactoryImpl();
}

//*********************************
// creators
//*********************************

std::shared_ptr<ecore::EObject> LibraryModel_ecoreFactoryImpl::create(const unsigned int classID,  std::shared_ptr<ecore::EObject> container /*= nullptr*/, const unsigned int referenceID/* = -1*/) const
{
	switch(classID)
	{
		case LibraryModel_ecorePackage::AUTHOR_ECLASS:
		{
				return this->createAuthor();
			
		}
		case LibraryModel_ecorePackage::BOOK_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createBook();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<libraryModel_ecore::LibraryModel>(container);
				assert(castedContainer);
				return std::shared_ptr<Book>(this->createBook_in_Library(castedContainer));
			}
		}
		case LibraryModel_ecorePackage::LIBRARYMODEL_ECLASS:
		{
				return this->createLibraryModel();
			
		}
		case LibraryModel_ecorePackage::NAMEDELEMENT_ECLASS:
		{
				return this->createNamedElement();
			
		}
		case LibraryModel_ecorePackage::PICTURE_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createPicture();
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<libraryModel_ecore::Book>(container);
				assert(castedContainer);
				return std::shared_ptr<Picture>(this->createPicture_in_Book(castedContainer));
			}
		}
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << classID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<ecore::EObject> LibraryModel_ecoreFactoryImpl::create(std::shared_ptr<ecore::EClass> _class) const
{
	return create(_class, nullptr);
}

std::shared_ptr<ecore::EObject> LibraryModel_ecoreFactoryImpl::create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}

	int _classID = _class->eClass()->getClassifierID();
	return create(_classID, _container);
}

std::shared_ptr<ecore::EObject> LibraryModel_ecoreFactoryImpl::create(std::string _className) const
{
	auto iter = m_idMap.find(_className);
	if(iter != m_idMap.end())
    {
		//get the ID
        unsigned int id = iter->second;
		return create(id);
    }

    return nullptr;
}

std::shared_ptr<ecore::EObject> LibraryModel_ecoreFactoryImpl::create(std::string _className, std::shared_ptr<EObject> _container, const unsigned int referenceID) const
{
	auto iter = m_idMap.find(_className);
	if(iter != m_idMap.end())
    {
		//get the ID
        unsigned int id = iter->second;
		return create(id, _container, referenceID);
    }

    return nullptr;
}


std::shared_ptr<Author> LibraryModel_ecoreFactoryImpl::createAuthor() const
{
	std::shared_ptr<AuthorImpl> element(new AuthorImpl());
	element->setThisAuthorPtr(element);
	return element;
}
std::shared_ptr<Book> LibraryModel_ecoreFactoryImpl::createBook() const
{
	std::shared_ptr<BookImpl> element(new BookImpl());
	element->setThisBookPtr(element);
	return element;
}
std::shared_ptr<Book> LibraryModel_ecoreFactoryImpl::createBook_in_Library(std::weak_ptr<libraryModel_ecore::LibraryModel > par_library) const
{
	std::shared_ptr<BookImpl> element(new BookImpl(par_library));
	if(auto wp = par_library.lock())
	{
			wp->getBook()->push_back(element);
	}
	element->setThisBookPtr(element);
	return element;
	
}

std::shared_ptr<LibraryModel> LibraryModel_ecoreFactoryImpl::createLibraryModel() const
{
	std::shared_ptr<LibraryModelImpl> element(new LibraryModelImpl());
	element->setThisLibraryModelPtr(element);
	return element;
}
std::shared_ptr<NamedElement> LibraryModel_ecoreFactoryImpl::createNamedElement() const
{
	std::shared_ptr<NamedElementImpl> element(new NamedElementImpl());
	element->setThisNamedElementPtr(element);
	return element;
}
std::shared_ptr<Picture> LibraryModel_ecoreFactoryImpl::createPicture() const
{
	std::shared_ptr<PictureImpl> element(new PictureImpl());
	element->setThisPicturePtr(element);
	return element;
}
std::shared_ptr<Picture> LibraryModel_ecoreFactoryImpl::createPicture_in_Book(std::weak_ptr<libraryModel_ecore::Book > par_book) const
{
	std::shared_ptr<PictureImpl> element(new PictureImpl(par_book));
	if(auto wp = par_book.lock())
	{
			wp->getPictures()->push_back(element);
	}
	element->setThisPicturePtr(element);
	return element;
	
}


std::shared_ptr<LibraryModel_ecorePackage> LibraryModel_ecoreFactoryImpl::getLibraryModel_ecorePackage() const
{
	return LibraryModel_ecorePackage::eInstance();
}
