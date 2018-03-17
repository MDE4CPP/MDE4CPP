#include "libraryModel_ecore/impl/LibraryModelImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//#include "util/ProfileCallCount.hpp"

#include <cassert>
#include <iostream>

#include "abstractDataTypes/Bag.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "libraryModel_ecore/impl/LibraryModel_ecorePackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "libraryModel_ecore/LibraryModel_ecoreFactory.hpp"
#include "libraryModel_ecore/LibraryModel_ecorePackage.hpp"
#include <exception> // used in Persistence

#include "libraryModel_ecore/Author.hpp"

#include "libraryModel_ecore/Book.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "libraryModel_ecore/LibraryModel_ecorePackage.hpp"
#include "libraryModel_ecore/LibraryModel_ecoreFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace libraryModel_ecore;

//*********************************
// Constructor / Destructor
//*********************************
LibraryModelImpl::LibraryModelImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_authors.reset(new Bag<libraryModel_ecore::Author>());
	
	

		m_book.reset(new Bag<libraryModel_ecore::Book>());
	
	

	//Init references
	
	

	
	
}

LibraryModelImpl::~LibraryModelImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LibraryModel "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




LibraryModelImpl::LibraryModelImpl(const LibraryModelImpl & obj):LibraryModelImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LibraryModel "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<libraryModel_ecore::Author>> _authorsList = obj.getAuthors();
	for(std::shared_ptr<libraryModel_ecore::Author> _authors : *_authorsList)
	{
		this->getAuthors()->add(std::shared_ptr<libraryModel_ecore::Author>(std::dynamic_pointer_cast<libraryModel_ecore::Author>(_authors->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_authors" << std::endl;
	#endif
	std::shared_ptr<Bag<libraryModel_ecore::Book>> _bookList = obj.getBook();
	for(std::shared_ptr<libraryModel_ecore::Book> _book : *_bookList)
	{
		this->getBook()->add(std::shared_ptr<libraryModel_ecore::Book>(std::dynamic_pointer_cast<libraryModel_ecore::Book>(_book->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_book" << std::endl;
	#endif

	
	

	
	
}

std::shared_ptr<ecore::EObject>  LibraryModelImpl::copy() const
{
	std::shared_ptr<LibraryModelImpl> element(new LibraryModelImpl(*this));
	element->setThisLibraryModelPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> LibraryModelImpl::eStaticClass() const
{
	return LibraryModel_ecorePackageImpl::eInstance()->getLibraryModel_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr<Bag<libraryModel_ecore::Author>> LibraryModelImpl::getAuthors() const
{

    return m_authors;
}


std::shared_ptr<Bag<libraryModel_ecore::Book>> LibraryModelImpl::getBook() const
{

    return m_book;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<LibraryModel> LibraryModelImpl::getThisLibraryModelPtr()
{
	return m_thisLibraryModelPtr.lock();
}
void LibraryModelImpl::setThisLibraryModelPtr(std::weak_ptr<LibraryModel> thisLibraryModelPtr)
{
	m_thisLibraryModelPtr = thisLibraryModelPtr;
}
std::shared_ptr<ecore::EObject> LibraryModelImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any LibraryModelImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case LibraryModel_ecorePackage::LIBRARYMODEL_EREFERENCE_AUTHORS:
			return getAuthors(); //21
		case LibraryModel_ecorePackage::LIBRARYMODEL_EREFERENCE_BOOK:
			return getBook(); //20
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool LibraryModelImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case LibraryModel_ecorePackage::LIBRARYMODEL_EREFERENCE_AUTHORS:
			return getAuthors() != nullptr; //21
		case LibraryModel_ecorePackage::LIBRARYMODEL_EREFERENCE_BOOK:
			return getBook() != nullptr; //20
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool LibraryModelImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void LibraryModelImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get LibraryModel_ecoreFactory
	std::shared_ptr<libraryModel_ecore::LibraryModel_ecoreFactory> modelFactory = libraryModel_ecore::LibraryModel_ecoreFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void LibraryModelImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void LibraryModelImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<libraryModel_ecore::LibraryModel_ecoreFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("authors") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Author";
			}
			std::shared_ptr<libraryModel_ecore::Author> authors = std::dynamic_pointer_cast<libraryModel_ecore::Author>(modelFactory->create(typeName));
			if (authors != nullptr)
			{
				std::shared_ptr<Bag<libraryModel_ecore::Author>> list_authors = this->getAuthors();
				list_authors->push_back(authors);
				loadHandler->handleChild(authors);
			}
			return;
		}

		if ( nodeName.compare("book") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Book";
			}
			std::shared_ptr<ecore::EObject> book = modelFactory->create(typeName, loadHandler->getCurrentObject(), LibraryModel_ecorePackage::BOOK_EREFERENCE_LIBRARY);
			if (book != nullptr)
			{
				loadHandler->handleChild(book);
			}
			return;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}

	ecore::EObjectImpl::loadNode(nodeName, loadHandler, ecore::EcoreFactory::eInstance());
}

void LibraryModelImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void LibraryModelImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void LibraryModelImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<libraryModel_ecore::LibraryModel_ecorePackage> package = libraryModel_ecore::LibraryModel_ecorePackage::eInstance();

	


		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'authors'
		std::shared_ptr<Bag<libraryModel_ecore::Author>> list_authors = this->getAuthors();
		for (std::shared_ptr<libraryModel_ecore::Author> authors : *list_authors) 
		{
			saveHandler->addReference(authors, "authors", authors->eClass() != package->getAuthor_EClass());
		}

		// Save 'book'
		std::shared_ptr<Bag<libraryModel_ecore::Book>> list_book = this->getBook();
		for (std::shared_ptr<libraryModel_ecore::Book> book : *list_book) 
		{
			saveHandler->addReference(book, "book", book->eClass() != package->getBook_EClass());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

