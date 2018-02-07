#include "libraryModel_ecore/impl/PictureImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "libraryModel_ecore/impl/LibraryModel_ecorePackageImpl.hpp"

//Forward declaration includes
#include "libraryModel_ecore/Book.hpp"

#include "libraryModel_ecore/NamedElement.hpp"


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
	std::shared_ptr<ecore::EObject> element(new PictureImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> PictureImpl::eStaticClass() const
{
	return LibraryModel_ecorePackageImpl::eInstance()->getPicture();
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
		case LibraryModel_ecorePackage::NAMEDELEMENT_NAME:
			return getName(); //40
		case LibraryModel_ecorePackage::PICTURE_BOOK:
			return getBook(); //41
		case LibraryModel_ecorePackage::PICTURE_PAGENUMBER:
			return getPageNumber(); //42
	}
	return boost::any();
}

void PictureImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case LibraryModel_ecorePackage::NAMEDELEMENT_NAME:
		{
			// BOOST CAST
			std::string _Name = boost::any_cast<std::string>(newValue);
			setName(_Name); //40
			break;
		}
		case LibraryModel_ecorePackage::PICTURE_BOOK:
		{
			// BOOST CAST
			std::shared_ptr<libraryModel_ecore::Book> _book = boost::any_cast<std::shared_ptr<libraryModel_ecore::Book>>(newValue);
			setBook(_book); //41
			break;
		}
		case LibraryModel_ecorePackage::PICTURE_PAGENUMBER:
		{
			// BOOST CAST
			int _pageNumber = boost::any_cast<int>(newValue);
			setPageNumber(_pageNumber); //42
			break;
		}
	}
}
