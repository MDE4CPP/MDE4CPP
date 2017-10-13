#include "EcoreSimpleExampleModelPackageImpl.hpp"

//metametamodel classes
#include "EAttribute.hpp"
#include "EClass.hpp"
#include "EDataType.hpp"
#include "EEnum.hpp"
#include "EOperation.hpp"
#include "EReference.hpp"

//metamodel factory
#include "EcoreSimpleExampleModelFactory.hpp"

//depending model packages
#include "TypePackage.hpp"

using namespace ecoreSimpleExampleModel;

bool EcoreSimpleExampleModelPackageImpl::isInited = false;

EcoreSimpleExampleModelPackageImpl::EcoreSimpleExampleModelPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( EcoreSimpleExampleModelFactory::eInstance()));
}

EcoreSimpleExampleModelPackageImpl::~EcoreSimpleExampleModelPackageImpl()
{
	bookEClass.reset();
	authorEClass.reset();
	libraryModelEClass.reset();
	namedElementEClass.reset();
	
	
}

EcoreSimpleExampleModelPackage* EcoreSimpleExampleModelPackageImpl::create()
{
	if (isInited)
	{
		return EcoreSimpleExampleModelPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    EcoreSimpleExampleModelPackageImpl * metaModelPackage = new EcoreSimpleExampleModelPackageImpl();
	metaModelPackage->createPackageContents();
    return metaModelPackage;
}

void EcoreSimpleExampleModelPackageImpl::init()
{
    // Initialize created meta-data
    initializePackageContents();   
}

void EcoreSimpleExampleModelPackageImpl::createPackageContents()
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	authorEClass = createEClass(AUTHOR);
	
	
	

	bookEClass = createEClass(BOOK);
	
	createEReference(, );
	createEReference(, );
	
	

	libraryModelEClass = createEClass(LIBRARYMODEL);
	
	createEReference(, );
	createEReference(, );
	
	

	namedElementEClass = createEClass(NAMEDELEMENT);
	createEAttribute(, );
	
	
	

	
}

void EcoreSimpleExampleModelPackageImpl::initializePackageContents()
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
	
	std::shared_ptr<ecore::EOperation> op;

 	// Initialize classes and features; add operations and parameters
	// Begin Class Author
	initEClass(authorEClass, nullptr, "Author", false, false, true);
	
	
	
	// End Class Author

	// Begin Class Book
	initEClass(bookEClass, nullptr, "Book", false, false, true);
	
	initEReference(,,,"author","",0,-1, false,false, true, false, true, false, true, false,true);
	initEReference(,,,"library","",0,1, false,false, true, false, true, false, true, false,true);
	
	
	// End Class Book

	// Begin Class LibraryModel
	initEClass(libraryModelEClass, nullptr, "LibraryModel", false, false, true);
	
	initEReference(,,,"author","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(,,,"book","",0,-1, false,false, true, true, true, false, true, false,true);
	
	
	// End Class LibraryModel

	// Begin Class NamedElement
	initEClass(namedElementEClass, nullptr, "NamedElement", false, false, true);
	initEAttribute(,,"Name","",0,1, false,false, true, false, false, true, false, true);
	
	
	
	// End Class NamedElement

	
}

// Begin Class Author
std::shared_ptr<ecore::EClass> EcoreSimpleExampleModelPackageImpl::getAuthor() const
{
	return authorEClass;
}



// End Class Author

// Begin Class Book
std::shared_ptr<ecore::EClass> EcoreSimpleExampleModelPackageImpl::getBook() const
{
	return bookEClass;
}

std::shared_ptr<> EcoreSimpleExampleModelPackageImpl::get() const
{
	return std::dynamic_pointer_cast<>(->getEStructuralFeatures()->at());
}
std::shared_ptr<> EcoreSimpleExampleModelPackageImpl::get() const
{
	return std::dynamic_pointer_cast<>(->getEStructuralFeatures()->at());
}


// End Class Book

// Begin Class LibraryModel
std::shared_ptr<ecore::EClass> EcoreSimpleExampleModelPackageImpl::getLibraryModel() const
{
	return libraryModelEClass;
}

std::shared_ptr<> EcoreSimpleExampleModelPackageImpl::get() const
{
	return std::dynamic_pointer_cast<>(->getEStructuralFeatures()->at());
}
std::shared_ptr<> EcoreSimpleExampleModelPackageImpl::get() const
{
	return std::dynamic_pointer_cast<>(->getEStructuralFeatures()->at());
}


// End Class LibraryModel

// Begin Class NamedElement
std::shared_ptr<ecore::EClass> EcoreSimpleExampleModelPackageImpl::getNamedElement() const
{
	return namedElementEClass;
}
std::shared_ptr<> EcoreSimpleExampleModelPackageImpl::get() const
{
	return std::dynamic_pointer_cast<>(->getEStructuralFeatures()->at());
}



// End Class NamedElement

