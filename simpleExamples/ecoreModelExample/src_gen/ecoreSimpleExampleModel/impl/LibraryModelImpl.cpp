#include "LibraryModelImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "EcoreSimpleExampleModelPackageImpl.hpp"

//Forward declaration includes
#include "Author.hpp"

#include "Book.hpp"


using namespace ecoreSimpleExampleModel;

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

	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_author" << std::endl;
	#endif
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_book" << std::endl;
	#endif

	
	

	
	

}

ecore::EObject *  LibraryModelImpl::copy() const
{
	return new LibraryModelImpl(*this);
}

std::shared_ptr<ecore::EClass> LibraryModelImpl::eStaticClass() const
{
	return EcoreSimpleExampleModelPackageImpl::eInstance()->getLibraryModel();
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






//*********************************
// Union Getter
//*********************************
invalid

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any LibraryModelImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcoreSimpleExampleModelPackage::LIBRARYMODEL_AUTHOR:
			return getAuthor(); //21
		case EcoreSimpleExampleModelPackage::LIBRARYMODEL_BOOK:
			return getBook(); //20
	}
	return boost::any();
}
