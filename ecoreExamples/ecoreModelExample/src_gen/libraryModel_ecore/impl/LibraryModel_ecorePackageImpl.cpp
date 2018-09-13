#include "libraryModel_ecore/impl/LibraryModel_ecorePackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EReference.hpp"

//metamodel factory
#include "libraryModel_ecore/LibraryModel_ecoreFactory.hpp"

//depending model packages
#include "types/TypesPackage.hpp"

using namespace libraryModel_ecore;

bool LibraryModel_ecorePackageImpl::isInited = false;

LibraryModel_ecorePackageImpl::LibraryModel_ecorePackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( LibraryModel_ecoreFactory::eInstance()));
}

LibraryModel_ecorePackageImpl::~LibraryModel_ecorePackageImpl()
{
}

LibraryModel_ecorePackage* LibraryModel_ecorePackageImpl::create()
{
	if (isInited)
	{
		return LibraryModel_ecorePackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    LibraryModel_ecorePackageImpl * metaModelPackage = new LibraryModel_ecorePackageImpl();
    return metaModelPackage;
}

void LibraryModel_ecorePackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}

// Begin Class Author
std::shared_ptr<ecore::EClass> LibraryModel_ecorePackageImpl::getAuthor_EClass() const
{
	return m_author_EClass;
}




// End Class Author

// Begin Class Book
std::shared_ptr<ecore::EClass> LibraryModel_ecorePackageImpl::getBook_EClass() const
{
	return m_book_EClass;
}


std::shared_ptr<ecore::EReference> LibraryModel_ecorePackageImpl::getBook_EReference_authors() const
{
	return m_book_EReference_authors;
}
std::shared_ptr<ecore::EReference> LibraryModel_ecorePackageImpl::getBook_EReference_library() const
{
	return m_book_EReference_library;
}
std::shared_ptr<ecore::EReference> LibraryModel_ecorePackageImpl::getBook_EReference_pictures() const
{
	return m_book_EReference_pictures;
}


// End Class Book

// Begin Class LibraryModel
std::shared_ptr<ecore::EClass> LibraryModel_ecorePackageImpl::getLibraryModel_EClass() const
{
	return m_libraryModel_EClass;
}


std::shared_ptr<ecore::EReference> LibraryModel_ecorePackageImpl::getLibraryModel_EReference_authors() const
{
	return m_libraryModel_EReference_authors;
}
std::shared_ptr<ecore::EReference> LibraryModel_ecorePackageImpl::getLibraryModel_EReference_book() const
{
	return m_libraryModel_EReference_book;
}

std::shared_ptr<ecore::EOperation> LibraryModel_ecorePackageImpl::getLibraryModel_EOperation_printLibrary() const
{
	return m_libraryModel_EOperation_printLibrary;
}

// End Class LibraryModel

// Begin Class NamedElement
std::shared_ptr<ecore::EClass> LibraryModel_ecorePackageImpl::getNamedElement_EClass() const
{
	return m_namedElement_EClass;
}

std::shared_ptr<ecore::EAttribute> LibraryModel_ecorePackageImpl::getNamedElement_EAttribute_name() const
{
	return m_namedElement_EAttribute_name;
}



// End Class NamedElement

// Begin Class Picture
std::shared_ptr<ecore::EClass> LibraryModel_ecorePackageImpl::getPicture_EClass() const
{
	return m_picture_EClass;
}

std::shared_ptr<ecore::EAttribute> LibraryModel_ecorePackageImpl::getPicture_EAttribute_pageNumber() const
{
	return m_picture_EAttribute_pageNumber;
}

std::shared_ptr<ecore::EReference> LibraryModel_ecorePackageImpl::getPicture_EReference_book() const
{
	return m_picture_EReference_book;
}


// End Class Picture

