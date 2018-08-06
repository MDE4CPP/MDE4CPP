#include "libraryModel_ecore/impl/BookImpl.hpp"

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
#include <sstream>

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

#include "libraryModel_ecore/LibraryModel.hpp"

#include "libraryModel_ecore/NamedElement.hpp"

#include "libraryModel_ecore/Picture.hpp"

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
BookImpl::BookImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_authors.reset(new Bag<libraryModel_ecore::Author>());
	
	

	

		m_pictures.reset(new Bag<libraryModel_ecore::Picture>());
	
	

	//Init references
	
	

	

	
	
}

BookImpl::~BookImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Book "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			BookImpl::BookImpl(std::weak_ptr<libraryModel_ecore::LibraryModel > par_library)
			:BookImpl()
			{
			    m_library = par_library;
			}






BookImpl::BookImpl(const BookImpl & obj):BookImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Book "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_Name = obj.getName();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<libraryModel_ecore::Author>> _authors = obj.getAuthors();
	m_authors.reset(new Bag<libraryModel_ecore::Author>(*(obj.getAuthors().get())));

	m_library  = obj.getLibrary();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<libraryModel_ecore::Picture>> _picturesList = obj.getPictures();
	for(std::shared_ptr<libraryModel_ecore::Picture> _pictures : *_picturesList)
	{
		this->getPictures()->add(std::shared_ptr<libraryModel_ecore::Picture>(std::dynamic_pointer_cast<libraryModel_ecore::Picture>(_pictures->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_pictures" << std::endl;
	#endif

	
	
}

std::shared_ptr<ecore::EObject>  BookImpl::copy() const
{
	std::shared_ptr<BookImpl> element(new BookImpl(*this));
	element->setThisBookPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> BookImpl::eStaticClass() const
{
	return LibraryModel_ecorePackageImpl::eInstance()->getBook_EClass();
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
std::shared_ptr<Bag<libraryModel_ecore::Author>> BookImpl::getAuthors() const
{

    return m_authors;
}


std::weak_ptr<libraryModel_ecore::LibraryModel > BookImpl::getLibrary() const
{

    return m_library;
}
void BookImpl::setLibrary(std::shared_ptr<libraryModel_ecore::LibraryModel> _library)
{
    m_library = _library;
}

std::shared_ptr<Bag<libraryModel_ecore::Picture>> BookImpl::getPictures() const
{

    return m_pictures;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<Book> BookImpl::getThisBookPtr() const
{
	return m_thisBookPtr.lock();
}
void BookImpl::setThisBookPtr(std::weak_ptr<Book> thisBookPtr)
{
	m_thisBookPtr = thisBookPtr;
	setThisNamedElementPtr(thisBookPtr);
}
std::shared_ptr<ecore::EObject> BookImpl::eContainer() const
{
	if(auto wp = m_library.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any BookImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case LibraryModel_ecorePackage::BOOK_EREFERENCE_AUTHORS:
			return eAny(getAuthors()); //51
		case LibraryModel_ecorePackage::BOOK_EREFERENCE_LIBRARY:
			return eAny(getLibrary()); //52
		case LibraryModel_ecorePackage::BOOK_EREFERENCE_PICTURES:
			return eAny(getPictures()); //53
	}
	return NamedElementImpl::eGet(featureID, resolve, coreType);
}
bool BookImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case LibraryModel_ecorePackage::BOOK_EREFERENCE_AUTHORS:
			return getAuthors() != nullptr; //51
		case LibraryModel_ecorePackage::BOOK_EREFERENCE_LIBRARY:
			return getLibrary().lock() != nullptr; //52
		case LibraryModel_ecorePackage::BOOK_EREFERENCE_PICTURES:
			return getPictures() != nullptr; //53
	}
	return NamedElementImpl::internalEIsSet(featureID);
}
bool BookImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case LibraryModel_ecorePackage::BOOK_EREFERENCE_LIBRARY:
		{
			// BOOST CAST
			std::shared_ptr<libraryModel_ecore::LibraryModel> _library = newValue->get<std::shared_ptr<libraryModel_ecore::LibraryModel>>();
			setLibrary(_library); //52
			return true;
		}
	}

	return NamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void BookImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void BookImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("authors");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("authors")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	NamedElementImpl::loadAttributes(loadHandler, attr_list);
}

void BookImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<libraryModel_ecore::LibraryModel_ecoreFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("pictures") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Picture";
			}
			std::shared_ptr<ecore::EObject> pictures = modelFactory->create(typeName, loadHandler->getCurrentObject(), LibraryModel_ecorePackage::PICTURE_EREFERENCE_BOOK);
			if (pictures != nullptr)
			{
				loadHandler->handleChild(pictures);
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

	NamedElementImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void BookImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case LibraryModel_ecorePackage::BOOK_EREFERENCE_AUTHORS:
		{
			std::shared_ptr<Bag<libraryModel_ecore::Author>> _authors = getAuthors();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<libraryModel_ecore::Author> _r = std::dynamic_pointer_cast<libraryModel_ecore::Author>(ref);
				if (_r != nullptr)
				{
					_authors->push_back(_r);
				}				
			}
			return;
		}

		case LibraryModel_ecorePackage::BOOK_EREFERENCE_LIBRARY:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<libraryModel_ecore::LibraryModel> _library = std::dynamic_pointer_cast<libraryModel_ecore::LibraryModel>( references.front() );
				setLibrary(_library);
			}
			
			return;
		}
	}
	NamedElementImpl::resolveReferences(featureID, references);
}

void BookImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamedElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void BookImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<libraryModel_ecore::LibraryModel_ecorePackage> package = libraryModel_ecore::LibraryModel_ecorePackage::eInstance();

	

		// Add references
		std::shared_ptr<Bag<libraryModel_ecore::Author>> authors_list = this->getAuthors();
		for (std::shared_ptr<libraryModel_ecore::Author > object : *authors_list)
		{ 
			saveHandler->addReferences("authors", object);
		}


		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'pictures'
		std::shared_ptr<Bag<libraryModel_ecore::Picture>> list_pictures = this->getPictures();
		for (std::shared_ptr<libraryModel_ecore::Picture> pictures : *list_pictures) 
		{
			saveHandler->addReference(pictures, "pictures", pictures->eClass() != package->getPicture_EClass());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

