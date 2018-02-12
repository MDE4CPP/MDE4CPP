#include "libraryModel_ecore/impl/LibraryModel_ecorePackageImpl.hpp"

//metametamodel classes
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
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

	createAuthorContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createBookContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createLibraryModelContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createNamedElementContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createPictureContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);

	createPackageEDataTypes(std::shared_ptr<EPackage>(this, null_deleter()), factory);
}

void LibraryModel_ecorePackageImpl::createAuthorContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_author_EClass = factory->createEClass_in_EPackage(package, AUTHOR_ECLASS);
	
	
	
}

void LibraryModel_ecorePackageImpl::createBookContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_book_EClass = factory->createEClass_in_EPackage(package, BOOK_ECLASS);
	
	m_book_EReference_authors = factory->createEReference_in_EContainingClass(m_book_EClass, BOOK_EREFERENCE_AUTHORS);
	m_book_EReference_library = factory->createEReference_in_EContainingClass(m_book_EClass, BOOK_EREFERENCE_LIBRARY);
	m_book_EReference_pictures = factory->createEReference_in_EContainingClass(m_book_EClass, BOOK_EREFERENCE_PICTURES);
	
	
}

void LibraryModel_ecorePackageImpl::createLibraryModelContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_libraryModel_EClass = factory->createEClass_in_EPackage(package, LIBRARYMODEL_ECLASS);
	
	m_libraryModel_EReference_authors = factory->createEReference_in_EContainingClass(m_libraryModel_EClass, LIBRARYMODEL_EREFERENCE_AUTHORS);
	m_libraryModel_EReference_book = factory->createEReference_in_EContainingClass(m_libraryModel_EClass, LIBRARYMODEL_EREFERENCE_BOOK);
	
	
}

void LibraryModel_ecorePackageImpl::createNamedElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_namedElement_EClass = factory->createEClass_in_EPackage(package, NAMEDELEMENT_ECLASS);
	m_namedElement_EAttribute_name = factory->createEAttribute_in_EContainingClass(m_namedElement_EClass, NAMEDELEMENT_EATTRIBUTE_NAME);
	
	
	
}

void LibraryModel_ecorePackageImpl::createPictureContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_picture_EClass = factory->createEClass_in_EPackage(package, PICTURE_ECLASS);
	m_picture_EAttribute_pageNumber = factory->createEAttribute_in_EContainingClass(m_picture_EClass, PICTURE_EATTRIBUTE_PAGENUMBER);
	
	m_picture_EReference_book = factory->createEReference_in_EContainingClass(m_picture_EClass, PICTURE_EREFERENCE_BOOK);
	
	
}

void LibraryModel_ecorePackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	
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
	m_author_EClass->getESuperTypes()->push_back(getNamedElement_EClass());
	m_book_EClass->getESuperTypes()->push_back(getNamedElement_EClass());
	m_picture_EClass->getESuperTypes()->push_back(getNamedElement_EClass());
	

 	// Initialize classes and features; add operations and parameters
	initializeAuthorContent();
	initializeBookContent();
	initializeLibraryModelContent();
	initializeNamedElementContent();
	initializePictureContent();

	initializePackageEDataTypes();
}

void LibraryModel_ecorePackageImpl::initializeAuthorContent()
{
	m_author_EClass->setInstanceClass(nullptr);
	m_author_EClass->setName("Author");
	m_author_EClass->setAbstract(false);
	m_author_EClass->setInterface(false);
	
	
	
	
}

void LibraryModel_ecorePackageImpl::initializeBookContent()
{
	m_book_EClass->setInstanceClass(nullptr);
	m_book_EClass->setName("Book");
	m_book_EClass->setAbstract(false);
	m_book_EClass->setInterface(false);
	
	
	m_book_EReference_authors->setName("authors");
	m_book_EReference_authors->setEType(getAuthor_EClass());
	m_book_EReference_authors->setLowerBound(0);
	m_book_EReference_authors->setUpperBound(-1);
	m_book_EReference_authors->setTransient(false);
	m_book_EReference_authors->setVolatile(false);
	m_book_EReference_authors->setChangeable(true);
	m_book_EReference_authors->setUnsettable(false);
	m_book_EReference_authors->setUnique(true);
	m_book_EReference_authors->setDerived(false);
	m_book_EReference_authors->setOrdered(true);
	m_book_EReference_authors->setContainment(false);
	m_book_EReference_authors->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_book_EReference_authors->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_book_EReference_authors->setEOpposite(otherEnd);
	    }
	}
	m_book_EReference_library->setName("library");
	m_book_EReference_library->setEType(getLibraryModel_EClass());
	m_book_EReference_library->setLowerBound(0);
	m_book_EReference_library->setUpperBound(1);
	m_book_EReference_library->setTransient(false);
	m_book_EReference_library->setVolatile(false);
	m_book_EReference_library->setChangeable(true);
	m_book_EReference_library->setUnsettable(false);
	m_book_EReference_library->setUnique(true);
	m_book_EReference_library->setDerived(false);
	m_book_EReference_library->setOrdered(true);
	m_book_EReference_library->setContainment(false);
	m_book_EReference_library->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_book_EReference_library->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getLibraryModel_EReference_book();
		if (otherEnd != nullptr)
	    {
	   		m_book_EReference_library->setEOpposite(otherEnd);
	    }
	}
	m_book_EReference_pictures->setName("pictures");
	m_book_EReference_pictures->setEType(getPicture_EClass());
	m_book_EReference_pictures->setLowerBound(0);
	m_book_EReference_pictures->setUpperBound(-1);
	m_book_EReference_pictures->setTransient(false);
	m_book_EReference_pictures->setVolatile(false);
	m_book_EReference_pictures->setChangeable(true);
	m_book_EReference_pictures->setUnsettable(false);
	m_book_EReference_pictures->setUnique(true);
	m_book_EReference_pictures->setDerived(false);
	m_book_EReference_pictures->setOrdered(true);
	m_book_EReference_pictures->setContainment(true);
	m_book_EReference_pictures->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_book_EReference_pictures->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getPicture_EReference_book();
		if (otherEnd != nullptr)
	    {
	   		m_book_EReference_pictures->setEOpposite(otherEnd);
	    }
	}
	
	
}

void LibraryModel_ecorePackageImpl::initializeLibraryModelContent()
{
	m_libraryModel_EClass->setInstanceClass(nullptr);
	m_libraryModel_EClass->setName("LibraryModel");
	m_libraryModel_EClass->setAbstract(false);
	m_libraryModel_EClass->setInterface(false);
	
	
	m_libraryModel_EReference_authors->setName("authors");
	m_libraryModel_EReference_authors->setEType(getAuthor_EClass());
	m_libraryModel_EReference_authors->setLowerBound(0);
	m_libraryModel_EReference_authors->setUpperBound(-1);
	m_libraryModel_EReference_authors->setTransient(false);
	m_libraryModel_EReference_authors->setVolatile(false);
	m_libraryModel_EReference_authors->setChangeable(true);
	m_libraryModel_EReference_authors->setUnsettable(false);
	m_libraryModel_EReference_authors->setUnique(true);
	m_libraryModel_EReference_authors->setDerived(false);
	m_libraryModel_EReference_authors->setOrdered(true);
	m_libraryModel_EReference_authors->setContainment(true);
	m_libraryModel_EReference_authors->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_libraryModel_EReference_authors->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_libraryModel_EReference_authors->setEOpposite(otherEnd);
	    }
	}
	m_libraryModel_EReference_book->setName("book");
	m_libraryModel_EReference_book->setEType(getBook_EClass());
	m_libraryModel_EReference_book->setLowerBound(0);
	m_libraryModel_EReference_book->setUpperBound(-1);
	m_libraryModel_EReference_book->setTransient(false);
	m_libraryModel_EReference_book->setVolatile(false);
	m_libraryModel_EReference_book->setChangeable(true);
	m_libraryModel_EReference_book->setUnsettable(false);
	m_libraryModel_EReference_book->setUnique(true);
	m_libraryModel_EReference_book->setDerived(false);
	m_libraryModel_EReference_book->setOrdered(true);
	m_libraryModel_EReference_book->setContainment(true);
	m_libraryModel_EReference_book->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_libraryModel_EReference_book->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getBook_EReference_library();
		if (otherEnd != nullptr)
	    {
	   		m_libraryModel_EReference_book->setEOpposite(otherEnd);
	    }
	}
	
	
}

void LibraryModel_ecorePackageImpl::initializeNamedElementContent()
{
	m_namedElement_EClass->setInstanceClass(nullptr);
	m_namedElement_EClass->setName("NamedElement");
	m_namedElement_EClass->setAbstract(false);
	m_namedElement_EClass->setInterface(false);
	
	m_namedElement_EAttribute_name = getNamedElement_EAttribute_name();
	m_namedElement_EAttribute_name->setName("Name");
	m_namedElement_EAttribute_name->setEType(types::TypesPackage::eInstance()->getString_EDataType());
	m_namedElement_EAttribute_name->setLowerBound(0);
	m_namedElement_EAttribute_name->setUpperBound(1);
	m_namedElement_EAttribute_name->setTransient(false);
	m_namedElement_EAttribute_name->setVolatile(false);
	m_namedElement_EAttribute_name->setChangeable(true);
	m_namedElement_EAttribute_name->setUnsettable(false);
	m_namedElement_EAttribute_name->setUnique(true);
	m_namedElement_EAttribute_name->setDerived(false);
	m_namedElement_EAttribute_name->setOrdered(true);
	m_namedElement_EAttribute_name->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_namedElement_EAttribute_name->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	
}

void LibraryModel_ecorePackageImpl::initializePictureContent()
{
	m_picture_EClass->setInstanceClass(nullptr);
	m_picture_EClass->setName("Picture");
	m_picture_EClass->setAbstract(false);
	m_picture_EClass->setInterface(false);
	
	m_picture_EAttribute_pageNumber = getPicture_EAttribute_pageNumber();
	m_picture_EAttribute_pageNumber->setName("pageNumber");
	m_picture_EAttribute_pageNumber->setEType(types::TypesPackage::eInstance()->getInteger_EDataType());
	m_picture_EAttribute_pageNumber->setLowerBound(0);
	m_picture_EAttribute_pageNumber->setUpperBound(1);
	m_picture_EAttribute_pageNumber->setTransient(false);
	m_picture_EAttribute_pageNumber->setVolatile(false);
	m_picture_EAttribute_pageNumber->setChangeable(true);
	m_picture_EAttribute_pageNumber->setUnsettable(false);
	m_picture_EAttribute_pageNumber->setUnique(true);
	m_picture_EAttribute_pageNumber->setDerived(false);
	m_picture_EAttribute_pageNumber->setOrdered(true);
	m_picture_EAttribute_pageNumber->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_picture_EAttribute_pageNumber->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_picture_EReference_book->setName("book");
	m_picture_EReference_book->setEType(getBook_EClass());
	m_picture_EReference_book->setLowerBound(0);
	m_picture_EReference_book->setUpperBound(1);
	m_picture_EReference_book->setTransient(false);
	m_picture_EReference_book->setVolatile(false);
	m_picture_EReference_book->setChangeable(true);
	m_picture_EReference_book->setUnsettable(false);
	m_picture_EReference_book->setUnique(true);
	m_picture_EReference_book->setDerived(false);
	m_picture_EReference_book->setOrdered(true);
	m_picture_EReference_book->setContainment(false);
	m_picture_EReference_book->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_picture_EReference_book->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getBook_EReference_pictures();
		if (otherEnd != nullptr)
	    {
	   		m_picture_EReference_book->setEOpposite(otherEnd);
	    }
	}
	
	
}

void LibraryModel_ecorePackageImpl::initializePackageEDataTypes()
{
	
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

