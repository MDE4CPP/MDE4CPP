#include "libraryModel_ecore/impl/BookImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "libraryModel_ecore/impl/LibraryModel_ecorePackageImpl.hpp"

//Forward declaration includes
#include "libraryModel_ecore/Author.hpp"

#include "libraryModel_ecore/LibraryModel.hpp"

#include "libraryModel_ecore/NamedElement.hpp"

#include "libraryModel_ecore/Picture.hpp"


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
	
	std::shared_ptr< Bag<libraryModel_ecore::Author> > _authors = obj.getAuthors();
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
	std::shared_ptr<ecore::EObject> element(new BookImpl(*this));
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
std::shared_ptr< Bag<libraryModel_ecore::Author> > BookImpl::getAuthors() const
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

std::shared_ptr< Bag<libraryModel_ecore::Picture> > BookImpl::getPictures() const
{

    return m_pictures;
}


//*********************************
// Union Getter
//*********************************


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
boost::any BookImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case LibraryModel_ecorePackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //00
		case LibraryModel_ecorePackage::BOOK_EREFERENCE_AUTHORS:
			return getAuthors(); //01
		case LibraryModel_ecorePackage::BOOK_EREFERENCE_LIBRARY:
			return getLibrary(); //02
		case LibraryModel_ecorePackage::BOOK_EREFERENCE_PICTURES:
			return getPictures(); //03
	}
	return boost::any();
}

void BookImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case LibraryModel_ecorePackage::NAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _Name = boost::any_cast<std::string>(newValue);
			setName(_Name); //00
			break;
		}
		case LibraryModel_ecorePackage::BOOK_EREFERENCE_LIBRARY:
		{
			// BOOST CAST
			std::shared_ptr<libraryModel_ecore::LibraryModel> _library = boost::any_cast<std::shared_ptr<libraryModel_ecore::LibraryModel>>(newValue);
			setLibrary(_library); //02
			break;
		}
	}
}
