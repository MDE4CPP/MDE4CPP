#include "libraryModel_ecore/impl/PictureImpl.hpp"

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

#include "libraryModel_ecore/Book.hpp"

#include "libraryModel_ecore/NamedElement.hpp"

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
PictureImpl::PictureImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References
	

	//Init references
	
}

PictureImpl::~PictureImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Picture "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			PictureImpl::PictureImpl(std::weak_ptr<libraryModel_ecore::Book > par_book)
			:PictureImpl()
			{
			    m_book = par_book;
			}






PictureImpl::PictureImpl(const PictureImpl & obj):PictureImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Picture "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_Name = obj.getName();
	m_pageNumber = obj.getPageNumber();

	//copy references with no containment (soft copy)
	
	m_book  = obj.getBook();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  PictureImpl::copy() const
{
	std::shared_ptr<PictureImpl> element(new PictureImpl(*this));
	element->setThisPicturePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> PictureImpl::eStaticClass() const
{
	return LibraryModel_ecorePackageImpl::eInstance()->getPicture_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void PictureImpl::setPageNumber(int _pageNumber)
{
	m_pageNumber = _pageNumber;
} 

int PictureImpl::getPageNumber() const 
{
	return m_pageNumber;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::weak_ptr<libraryModel_ecore::Book > PictureImpl::getBook() const
{

    return m_book;
}
void PictureImpl::setBook(std::shared_ptr<libraryModel_ecore::Book> _book)
{
    m_book = _book;
}

//*********************************
// Union Getter
//*********************************


std::shared_ptr<Picture> PictureImpl::getThisPicturePtr()
{
	return m_thisPicturePtr.lock();
}
void PictureImpl::setThisPicturePtr(std::weak_ptr<Picture> thisPicturePtr)
{
	m_thisPicturePtr = thisPicturePtr;
	setThisNamedElementPtr(thisPicturePtr);
}
std::shared_ptr<ecore::EObject> PictureImpl::eContainer() const
{
	if(auto wp = m_book.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any PictureImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case LibraryModel_ecorePackage::PICTURE_EREFERENCE_BOOK:
			return getBook(); //41
		case LibraryModel_ecorePackage::PICTURE_EATTRIBUTE_PAGENUMBER:
			return getPageNumber(); //42
	}
	return NamedElementImpl::internalEIsSet(featureID);
}
bool PictureImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case LibraryModel_ecorePackage::PICTURE_EREFERENCE_BOOK:
			return getBook().lock() != nullptr; //41
		case LibraryModel_ecorePackage::PICTURE_EATTRIBUTE_PAGENUMBER:
			return getPageNumber() != 0; //42
	}
	return NamedElementImpl::internalEIsSet(featureID);
}
bool PictureImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case LibraryModel_ecorePackage::PICTURE_EREFERENCE_BOOK:
		{
			// BOOST CAST
			std::shared_ptr<libraryModel_ecore::Book> _book = boost::any_cast<std::shared_ptr<libraryModel_ecore::Book>>(newValue);
			setBook(_book); //41
			return true;
		}
		case LibraryModel_ecorePackage::PICTURE_EATTRIBUTE_PAGENUMBER:
		{
			// BOOST CAST
			int _pageNumber = boost::any_cast<int>(newValue);
			setPageNumber(_pageNumber); //42
			return true;
		}
	}

	return NamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void PictureImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void PictureImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("pageNumber");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'int'
			int value;
			std::istringstream ( iter->second ) >> value;
			this->setPageNumber(value);
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

void PictureImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<libraryModel_ecore::LibraryModel_ecoreFactory> modelFactory)
{


	NamedElementImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void PictureImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case LibraryModel_ecorePackage::PICTURE_EREFERENCE_BOOK:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<libraryModel_ecore::Book> _book = std::dynamic_pointer_cast<libraryModel_ecore::Book>( references.front() );
				setBook(_book);
			}
			
			return;
		}
	}
	NamedElementImpl::resolveReferences(featureID, references);
}

void PictureImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamedElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void PictureImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<libraryModel_ecore::LibraryModel_ecorePackage> package = libraryModel_ecore::LibraryModel_ecorePackage::eInstance();

	
 
		// Add attributes
		if ( this->eIsSet(package->getPicture_EAttribute_pageNumber()) )
		{
			saveHandler->addAttribute("pageNumber", this->getPageNumber());
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

