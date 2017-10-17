#include "LibraryModelImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "LibraryModel_ecorePackageImpl.hpp"

//Forward declaration includes
#include "Author.hpp"

#include "Book.hpp"


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
	std::shared_ptr<ecore::EObject> element(new LibraryModelImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> LibraryModelImpl::eStaticClass() const
{
	return LibraryModel_ecorePackageImpl::eInstance()->getLibraryModel();
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
std::shared_ptr< Bag<libraryModel_ecore::Author> > LibraryModelImpl::getAuthors() const
{

    return m_authors;
}


std::shared_ptr< Bag<libraryModel_ecore::Book> > LibraryModelImpl::getBook() const
{

    return m_book;
}


//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any LibraryModelImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case LibraryModel_ecorePackage::LIBRARYMODEL_AUTHORS:
			return getAuthors(); //21
		case LibraryModel_ecorePackage::LIBRARYMODEL_BOOK:
			return getBook(); //20
	}
	return boost::any();
}
