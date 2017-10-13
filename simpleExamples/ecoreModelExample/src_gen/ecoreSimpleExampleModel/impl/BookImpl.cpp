#include "BookImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "EcoreSimpleExampleModelPackageImpl.hpp"

//Forward declaration includes
#include "Author.hpp"

#include "LibraryModel.hpp"

#include "NamedElement.hpp"


using namespace ecoreSimpleExampleModel;

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
	
	

	

	//Init references
	
	

	
}

BookImpl::~BookImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Book "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			BookImpl::BookImpl(std::weak_ptr<ecoreSimpleExampleModel::LibraryModel > par_library)
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
	

	m_library  = obj.getLibrary();


    
	//Clone references with containment (deep copy)



}

ecore::EObject *  BookImpl::copy() const
{
	return new BookImpl(*this);
}

std::shared_ptr<ecore::EClass> BookImpl::eStaticClass() const
{
	return EcoreSimpleExampleModelPackageImpl::eInstance()->getBook();
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




void BookImpl::(std::shared_ptr<> _library)
{
    m_library = _library;
}

//*********************************
// Union Getter
//*********************************
invalid

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any BookImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcoreSimpleExampleModelPackage::NAMEDELEMENT_NAME:
			return getName(); //00
		case EcoreSimpleExampleModelPackage::BOOK_AUTHOR:
			return getAuthor(); //01
		case EcoreSimpleExampleModelPackage::BOOK_LIBRARY:
			return getLibrary(); //02
	}
	return boost::any();
}
