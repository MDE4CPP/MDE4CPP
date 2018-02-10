#include "libraryModel_ecore/impl/LibraryModel_ecorePackageImpl.hpp"

//metametamodel classes
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EEnum.hpp"
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
	bookEClass.reset();
	authorEClass.reset();
	libraryModelEClass.reset();
	namedElementEClass.reset();
	pictureEClass.reset();
	
	
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
	metaModelPackage->createPackageContents();
    return metaModelPackage;
}

void LibraryModel_ecorePackageImpl::init()
{
    // Initialize created meta-data
    initializePackageContents();   
}

void LibraryModel_ecorePackageImpl::createPackageContents()
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;
	struct null_deleter{void operator()(void const *) const { } };

	std::shared_ptr<ecore::EcoreFactory> factory = ecore::EcoreFactory::eInstance();

	authorEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), AUTHOR);
	
	
	
	

	bookEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), BOOK);
	
	
	factory->createEReference_in_EContainingClass(bookEClass, BOOK_AUTHORS);
	factory->createEReference_in_EContainingClass(bookEClass, BOOK_LIBRARY);
	factory->createEReference_in_EContainingClass(bookEClass, BOOK_PICTURES);
	
	

	libraryModelEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), LIBRARYMODEL);
	
	
	factory->createEReference_in_EContainingClass(libraryModelEClass, LIBRARYMODEL_AUTHORS);
	factory->createEReference_in_EContainingClass(libraryModelEClass, LIBRARYMODEL_BOOK);
	
	

	namedElementEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), NAMEDELEMENT);
	
	factory->createEAttribute_in_EContainingClass(namedElementEClass, NAMEDELEMENT_NAME);
	
	
	

	pictureEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), PICTURE);
	
	factory->createEAttribute_in_EContainingClass(pictureEClass, PICTURE_PAGENUMBER);
	
	factory->createEReference_in_EContainingClass(pictureEClass, PICTURE_BOOK);
	
	

	
}

void LibraryModel_ecorePackageImpl::initializePackageContents()
{
	if (isInitialized)
	{
		return;
	}
	isInitialized = true;

	// Initialize package
	setName(eNAME);
	setNsPrefix(eNS_PREFIX);
	setNsURI(eNS_URI);
	
	// Add supertypes to classes
	authorEClass->getESuperTypes()->push_back(getNamedElement());
	bookEClass->getESuperTypes()->push_back(getNamedElement());
	pictureEClass->getESuperTypes()->push_back(getNamedElement());
	
	std::shared_ptr<ecore::EOperation> op;

 	// Initialize classes and features; add operations and parameters
	// Begin Class Author
	initEClass(authorEClass, nullptr, "Author", false, false, true);
	
	
	
	// End Class Author

	// Begin Class Book
	initEClass(bookEClass, nullptr, "Book", false, false, true);
	
	initEReference(getBook_Authors(),getAuthor(),nullptr,"authors","",0,-1, false,false, true, false, true, false, true, false,true);
	initEReference(getBook_Library(),getLibraryModel(),getLibraryModel_Book(),"library","",0,1, false,false, true, false, true, false, true, false,true);
	initEReference(getBook_Pictures(),getPicture(),getPicture_Book(),"pictures","",0,-1, false,false, true, true, true, false, true, false,true);
	
	
	// End Class Book

	// Begin Class LibraryModel
	initEClass(libraryModelEClass, nullptr, "LibraryModel", false, false, true);
	
	initEReference(getLibraryModel_Authors(),getAuthor(),nullptr,"authors","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getLibraryModel_Book(),getBook(),getBook_Library(),"book","",0,-1, false,false, true, true, true, false, true, false,true);
	
	
	// End Class LibraryModel

	// Begin Class NamedElement
	initEClass(namedElementEClass, nullptr, "NamedElement", false, false, true);
	initEAttribute(getNamedElement_Name(),types::TypesPackage::eInstance()->getString(),"Name","",0,1, false,false, true, false, false, true, false, true);
	
	
	
	// End Class NamedElement

	// Begin Class Picture
	initEClass(pictureEClass, nullptr, "Picture", false, false, true);
	initEAttribute(getPicture_PageNumber(),types::TypesPackage::eInstance()->getInteger(),"pageNumber","",0,1, false,false, true, false, false, true, false, true);
	
	initEReference(getPicture_Book(),getBook(),getBook_Pictures(),"book","",0,1, false,false, true, false, true, false, true, false,true);
	
	
	// End Class Picture

	
}

// Begin Class Author
std::shared_ptr<ecore::EClass> LibraryModel_ecorePackageImpl::getAuthor() const
{
	return authorEClass;
}



// End Class Author

// Begin Class Book
std::shared_ptr<ecore::EClass> LibraryModel_ecorePackageImpl::getBook() const
{
	return bookEClass;
}

std::shared_ptr<ecore::EReference> LibraryModel_ecorePackageImpl::getBook_Authors() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(bookEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> LibraryModel_ecorePackageImpl::getBook_Library() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(bookEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> LibraryModel_ecorePackageImpl::getBook_Pictures() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(bookEClass->getEStructuralFeatures()->at(2));
}


// End Class Book

// Begin Class LibraryModel
std::shared_ptr<ecore::EClass> LibraryModel_ecorePackageImpl::getLibraryModel() const
{
	return libraryModelEClass;
}

std::shared_ptr<ecore::EReference> LibraryModel_ecorePackageImpl::getLibraryModel_Authors() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(libraryModelEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> LibraryModel_ecorePackageImpl::getLibraryModel_Book() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(libraryModelEClass->getEStructuralFeatures()->at(1));
}


// End Class LibraryModel

// Begin Class NamedElement
std::shared_ptr<ecore::EClass> LibraryModel_ecorePackageImpl::getNamedElement() const
{
	return namedElementEClass;
}
std::shared_ptr<ecore::EAttribute> LibraryModel_ecorePackageImpl::getNamedElement_Name() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(namedElementEClass->getEStructuralFeatures()->at(0));
}



// End Class NamedElement

// Begin Class Picture
std::shared_ptr<ecore::EClass> LibraryModel_ecorePackageImpl::getPicture() const
{
	return pictureEClass;
}
std::shared_ptr<ecore::EAttribute> LibraryModel_ecorePackageImpl::getPicture_PageNumber() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(pictureEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> LibraryModel_ecorePackageImpl::getPicture_Book() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(pictureEClass->getEStructuralFeatures()->at(1));
}


// End Class Picture

