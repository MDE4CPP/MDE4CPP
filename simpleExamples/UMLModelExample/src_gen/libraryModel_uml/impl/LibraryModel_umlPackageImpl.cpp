#include "LibraryModel_uml/impl/LibraryModel_umlPackageImpl.hpp"

//meta meta model classes
#include "uml/Association.hpp"
#include "uml/Class.hpp"
#include "uml/Generalization.hpp"
#include "uml/LiteralInteger.hpp"
#include "uml/LiteralUnlimitedNatural.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PrimitiveType.hpp"
#include "uml/Property.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "uml/VisibilityKind.hpp"
//meta meta model factory
#include "uml/UmlFactory.hpp"

//metamodel factory
#include "LibraryModel_uml/LibraryModel_umlFactory.hpp"

//depending model packages
#include "ecoreReflection/EcorePackage.hpp"
#include "primitivetypesReflection/PrimitiveTypesPackage.hpp"



using namespace LibraryModel_uml;

LibraryModel_umlPackageImpl::LibraryModel_umlPackageImpl()
{
}

LibraryModel_umlPackageImpl::~LibraryModel_umlPackageImpl()
{
}

bool LibraryModel_umlPackageImpl::isInited = false;

LibraryModel_umlPackage* LibraryModel_umlPackageImpl::create()
{
	if (isInited)
	{
		return LibraryModel_umlPackage::eInstance().get();
	}
	isInited = true;
	
    // Obtain or create and register package, create package meta-data objects
    LibraryModel_umlPackageImpl * metaModelPackage = new LibraryModel_umlPackageImpl();
    return metaModelPackage;
}

void LibraryModel_umlPackageImpl::init(std::shared_ptr<uml::Package> libraryModel_uml)
{
    // Initialize created meta-data
	setThisPackagePtr(libraryModel_uml);
	initMetaModel();
    createPackageContents(libraryModel_uml);
    initializePackageContents(libraryModel_uml);   
}

void LibraryModel_umlPackageImpl::initMetaModel()
{
}

void LibraryModel_umlPackageImpl::createPackageContents(std::shared_ptr<uml::Package> libraryModel_uml)
{
	if (isCreated)
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<uml::UmlFactory> factory = uml::UmlFactory::eInstance();

	createPackageValueSpecifications(libraryModel_uml, factory);
	createPackageInterfaces(libraryModel_uml, factory);
	createPackageClasses(libraryModel_uml, factory);
	createPackageInstanceSpecifications(libraryModel_uml, factory);
	createPackageStereotypes(libraryModel_uml, factory);
	createPackageActivities(libraryModel_uml, factory);
	createPackageDependencies(libraryModel_uml, factory);
	createPackagePrimitiveTypes(libraryModel_uml, factory);
	createPackageEnumerationLiterals(libraryModel_uml, factory);
	createPackageInterfaceRealizations(libraryModel_uml, factory);
}

void LibraryModel_umlPackageImpl::createPackageActivities(std::shared_ptr<uml::Package> libraryModel_uml, std::shared_ptr<uml::UmlFactory> factory)
{
}

void LibraryModel_umlPackageImpl::createPackageClasses(std::shared_ptr<uml::Package> libraryModel_uml, std::shared_ptr<uml::UmlFactory> factory)
{
	std::shared_ptr<uml::Constraint> con = nullptr;
	std::shared_ptr<uml::OpaqueExpression> oe = nullptr;

	// Author
	libraryModel_uml_Author = factory->createClass_in_Package(libraryModel_uml);
	

    //-------------------------------------------
	// Book
	libraryModel_uml_Book = factory->createClass_in_Package(libraryModel_uml);
	
    // Book attributes
	libraryModel_uml_Book_authors = factory->createProperty_in_Class(libraryModel_uml_Book);
	libraryModel_uml_Book_pictures = factory->createProperty_in_Class(libraryModel_uml_Book);


    //-------------------------------------------
	// Library
	libraryModel_uml_Library = factory->createClass_in_Package(libraryModel_uml);
	
    // Library attributes
	libraryModel_uml_Library_authors = factory->createProperty_in_Class(libraryModel_uml_Library);
	libraryModel_uml_Library_books = factory->createProperty_in_Class(libraryModel_uml_Library);


    //-------------------------------------------
	// NamedModelElement
	libraryModel_uml_NamedModelElement = factory->createClass_in_Package(libraryModel_uml);
	
    // NamedModelElement attributes
	libraryModel_uml_NamedModelElement_name = factory->createProperty_in_Class(libraryModel_uml_NamedModelElement);


    //-------------------------------------------
	// Picture
	libraryModel_uml_Picture = factory->createClass_in_Package(libraryModel_uml);
	
    // Picture attributes
	libraryModel_uml_Picture_pageNumber = factory->createProperty_in_Class(libraryModel_uml_Picture);

}

void LibraryModel_umlPackageImpl::createPackageDependencies(std::shared_ptr<uml::Package> libraryModel_uml, std::shared_ptr<uml::UmlFactory> factory)
{
}

void LibraryModel_umlPackageImpl::createPackageEnumerationLiterals(std::shared_ptr<uml::Package> libraryModel_uml, std::shared_ptr<uml::UmlFactory> factory)
{
}

void LibraryModel_umlPackageImpl::createPackageInstanceSpecifications(std::shared_ptr<uml::Package> libraryModel_uml, std::shared_ptr<uml::UmlFactory> factory)
{
}

void LibraryModel_umlPackageImpl::createPackageInterfaceRealizations(std::shared_ptr<uml::Package> libraryModel_uml, std::shared_ptr<uml::UmlFactory> factory)
{
}

void LibraryModel_umlPackageImpl::createPackageInterfaces(std::shared_ptr<uml::Package> libraryModel_uml, std::shared_ptr<uml::UmlFactory> factory)
{
}

void LibraryModel_umlPackageImpl::createPackagePrimitiveTypes(std::shared_ptr<uml::Package> libraryModel_uml, std::shared_ptr<uml::UmlFactory> factory)
{
}

void LibraryModel_umlPackageImpl::createPackageStereotypes(std::shared_ptr<uml::Package> libraryModel_uml, std::shared_ptr<uml::UmlFactory> factory)
{
}

void LibraryModel_umlPackageImpl::createPackageValueSpecifications(std::shared_ptr<uml::Package> libraryModel_uml, std::shared_ptr<uml::UmlFactory> factory)
{
	libraryModel_uml_A_Lib_Author_library_lowerValue_LiteralInteger_LibraryModel_uml_A_Lib_Author_library = factory->createLiteralInteger_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_A_Lib_Author_library));
	libraryModel_uml_A_Lib_Author_library_lowerValue_LiteralInteger_LibraryModel_uml_A_Lib_Author_library->setValue(0);

	libraryModel_uml_A_Lib_Author_library_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_A_Lib_Author_library = factory->createLiteralUnlimitedNatural_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_A_Lib_Author_library));
	libraryModel_uml_A_Lib_Author_library_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_A_Lib_Author_library->setValue(1);

	libraryModel_uml_A_Lib_Boock_library_lowerValue_LiteralInteger_LibraryModel_uml_A_Lib_Boock_library = factory->createLiteralInteger_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_A_Lib_Boock_library));
	libraryModel_uml_A_Lib_Boock_library_lowerValue_LiteralInteger_LibraryModel_uml_A_Lib_Boock_library->setValue(0);

	libraryModel_uml_A_Lib_Boock_library_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_A_Lib_Boock_library = factory->createLiteralUnlimitedNatural_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_A_Lib_Boock_library));
	libraryModel_uml_A_Lib_Boock_library_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_A_Lib_Boock_library->setValue(1);

	libraryModel_uml_Book_authors_lowerValue_LiteralInteger_LibraryModel_uml_Book_authors = factory->createLiteralInteger_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_Book_authors));
	libraryModel_uml_Book_authors_lowerValue_LiteralInteger_LibraryModel_uml_Book_authors->setValue(0);

	libraryModel_uml_Book_authors_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_Book_authors = factory->createLiteralUnlimitedNatural_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_Book_authors));
	libraryModel_uml_Book_authors_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_Book_authors->setValue(-1);

	libraryModel_uml_Book_book_lowerValue_LiteralInteger_LibraryModel_uml_Book_book = factory->createLiteralInteger_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_Book_book));
	libraryModel_uml_Book_book_lowerValue_LiteralInteger_LibraryModel_uml_Book_book->setValue(0);

	libraryModel_uml_Book_book_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_Book_book = factory->createLiteralUnlimitedNatural_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_Book_book));
	libraryModel_uml_Book_book_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_Book_book->setValue(1);

	libraryModel_uml_Book_books_lowerValue_LiteralInteger_LibraryModel_uml_Book_books = factory->createLiteralInteger_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_Book_books));
	libraryModel_uml_Book_books_lowerValue_LiteralInteger_LibraryModel_uml_Book_books->setValue(0);

	libraryModel_uml_Book_books_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_Book_books = factory->createLiteralUnlimitedNatural_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_Book_books));
	libraryModel_uml_Book_books_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_Book_books->setValue(-1);

	libraryModel_uml_Book_pictures_lowerValue_LiteralInteger_LibraryModel_uml_Book_pictures = factory->createLiteralInteger_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_Book_pictures));
	libraryModel_uml_Book_pictures_lowerValue_LiteralInteger_LibraryModel_uml_Book_pictures->setValue(0);

	libraryModel_uml_Book_pictures_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_Book_pictures = factory->createLiteralUnlimitedNatural_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_Book_pictures));
	libraryModel_uml_Book_pictures_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_Book_pictures->setValue(-1);

	libraryModel_uml_Library_authors_lowerValue_LiteralInteger_LibraryModel_uml_Library_authors = factory->createLiteralInteger_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_Library_authors));
	libraryModel_uml_Library_authors_lowerValue_LiteralInteger_LibraryModel_uml_Library_authors->setValue(0);

	libraryModel_uml_Library_authors_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_Library_authors = factory->createLiteralUnlimitedNatural_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_Library_authors));
	libraryModel_uml_Library_authors_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_Library_authors->setValue(-1);

	libraryModel_uml_Library_books_lowerValue_LiteralInteger_LibraryModel_uml_Library_books = factory->createLiteralInteger_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_Library_books));
	libraryModel_uml_Library_books_lowerValue_LiteralInteger_LibraryModel_uml_Library_books->setValue(0);

	libraryModel_uml_Library_books_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_Library_books = factory->createLiteralUnlimitedNatural_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_Library_books));
	libraryModel_uml_Library_books_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_Library_books->setValue(-1);

	libraryModel_uml_NamedModelElement_name_lowerValue_LiteralInteger_LibraryModel_uml_NamedModelElement_name = factory->createLiteralInteger_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_NamedModelElement_name));
	libraryModel_uml_NamedModelElement_name_lowerValue_LiteralInteger_LibraryModel_uml_NamedModelElement_name->setValue(0);

	libraryModel_uml_NamedModelElement_name_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_NamedModelElement_name = factory->createLiteralUnlimitedNatural_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_NamedModelElement_name));
	libraryModel_uml_NamedModelElement_name_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_NamedModelElement_name->setValue(1);

	libraryModel_uml_Picture_pageNumber_lowerValue_LiteralInteger_LibraryModel_uml_Picture_pageNumber = factory->createLiteralInteger_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_Picture_pageNumber));
	libraryModel_uml_Picture_pageNumber_lowerValue_LiteralInteger_LibraryModel_uml_Picture_pageNumber->setValue(0);

	libraryModel_uml_Picture_pageNumber_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_Picture_pageNumber = factory->createLiteralUnlimitedNatural_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_Picture_pageNumber));
	libraryModel_uml_Picture_pageNumber_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_Picture_pageNumber->setValue(1);
}

void LibraryModel_umlPackageImpl::initializePackageContents(std::shared_ptr<uml::Package> libraryModel_uml)
{
	if (isInitialized)
	{
		return;
	}
	isInitialized = true;

	// Initialize package
	setName(eNAME);
	setURI(eNS_URI);

	initializePackageActivities();
	initializePackageClasses();
	initializePackageDependencies();
	initializePackageInstanceSpecifications();
	initializePackageInterfaceRealizations();
	initializePackageInterfaces();
	initializePackageStereotypes();

	
}

//ActivityNodes and Edges
void LibraryModel_umlPackageImpl::initializePackageActivities()
{
}

void LibraryModel_umlPackageImpl::initializePackageClasses()
{
	std::shared_ptr<uml::Generalization> gen = nullptr;

	//	class Author
	libraryModel_uml_Author->setName("Author");
	libraryModel_uml_Author->setIsAbstract(false);
	
	gen = uml::UmlFactory::eInstance()->createGeneralization_in_Specific(get_LibraryModel_uml_Author());
	gen->setGeneral(get_LibraryModel_uml_NamedModelElement());
	

    //-------------------------------------------
	//	class Book
	libraryModel_uml_Book->setName("Book");
	libraryModel_uml_Book->setIsAbstract(false);
	
	gen = uml::UmlFactory::eInstance()->createGeneralization_in_Specific(get_LibraryModel_uml_Book());
	gen->setGeneral(get_LibraryModel_uml_NamedModelElement());
	
    // Book attributes
	libraryModel_uml_Book_authors->setName("authors");
	libraryModel_uml_Book_authors->setType(get_LibraryModel_uml_Author());
	libraryModel_uml_Book_authors->setLower(0);
	libraryModel_uml_Book_authors->setUpper(-1);
	libraryModel_uml_Book_authors->setVisibility(uml::VisibilityKind::PRIVATE);
	
	
	
	libraryModel_uml_Book_pictures->setName("pictures");
	libraryModel_uml_Book_pictures->setType(get_LibraryModel_uml_Picture());
	libraryModel_uml_Book_pictures->setLower(0);
	libraryModel_uml_Book_pictures->setUpper(-1);
	libraryModel_uml_Book_pictures->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	


    //-------------------------------------------
	//	class Library
	libraryModel_uml_Library->setName("Library");
	libraryModel_uml_Library->setIsAbstract(false);
	
    // Library attributes
	libraryModel_uml_Library_authors->setName("authors");
	libraryModel_uml_Library_authors->setType(get_LibraryModel_uml_Author());
	libraryModel_uml_Library_authors->setLower(0);
	libraryModel_uml_Library_authors->setUpper(-1);
	libraryModel_uml_Library_authors->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	
	libraryModel_uml_Library_books->setName("books");
	libraryModel_uml_Library_books->setType(get_LibraryModel_uml_Book());
	libraryModel_uml_Library_books->setLower(0);
	libraryModel_uml_Library_books->setUpper(-1);
	libraryModel_uml_Library_books->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	


    //-------------------------------------------
	//	class NamedModelElement
	libraryModel_uml_NamedModelElement->setName("NamedModelElement");
	libraryModel_uml_NamedModelElement->setIsAbstract(false);
	
    // NamedModelElement attributes
	libraryModel_uml_NamedModelElement_name->setName("name");
	libraryModel_uml_NamedModelElement_name->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String());
	libraryModel_uml_NamedModelElement_name->setLower(0);
	libraryModel_uml_NamedModelElement_name->setUpper(1);
	libraryModel_uml_NamedModelElement_name->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	


    //-------------------------------------------
	//	class Picture
	libraryModel_uml_Picture->setName("Picture");
	libraryModel_uml_Picture->setIsAbstract(false);
	
	gen = uml::UmlFactory::eInstance()->createGeneralization_in_Specific(get_LibraryModel_uml_Picture());
	gen->setGeneral(get_LibraryModel_uml_NamedModelElement());
	
    // Picture attributes
	libraryModel_uml_Picture_pageNumber->setName("pageNumber");
	libraryModel_uml_Picture_pageNumber->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Integer());
	libraryModel_uml_Picture_pageNumber->setLower(0);
	libraryModel_uml_Picture_pageNumber->setUpper(1);
	libraryModel_uml_Picture_pageNumber->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	

}

void LibraryModel_umlPackageImpl::initializePackageDependencies()
{
}

void LibraryModel_umlPackageImpl::initializePackageInstanceSpecifications()
{
}


void LibraryModel_umlPackageImpl::initializePackageInterfaceRealizations()
{
}

void LibraryModel_umlPackageImpl::initializePackageInterfaces()
{
}

void LibraryModel_umlPackageImpl::initializePackageStereotypes()
{
}

std::shared_ptr<uml::Association> LibraryModel_umlPackageImpl::get_A_libraryModel_uml_Book_LibraryModel_uml_Book_authors()
{
	return a_libraryModel_uml_Book_LibraryModel_uml_Book_authors;
}
std::shared_ptr<uml::Association> LibraryModel_umlPackageImpl::get_A_libraryModel_uml_Book_LibraryModel_uml_Book_pictures()
{
	return a_libraryModel_uml_Book_LibraryModel_uml_Book_pictures;
}
std::shared_ptr<uml::Association> LibraryModel_umlPackageImpl::get_LibraryModel_uml_A_Lib_Author()
{
	return libraryModel_uml_A_Lib_Author;
}
std::shared_ptr<uml::Property> LibraryModel_umlPackageImpl::get_LibraryModel_uml_A_Lib_Author_library()
{
	return libraryModel_uml_A_Lib_Author_library;
}
std::shared_ptr<uml::Association> LibraryModel_umlPackageImpl::get_LibraryModel_uml_A_Lib_Boock()
{
	return libraryModel_uml_A_Lib_Boock;
}
std::shared_ptr<uml::Property> LibraryModel_umlPackageImpl::get_LibraryModel_uml_A_Lib_Boock_library()
{
	return libraryModel_uml_A_Lib_Boock_library;
}
std::shared_ptr<uml::Class> LibraryModel_umlPackageImpl::get_LibraryModel_uml_Author()
{
	return libraryModel_uml_Author;
}
std::shared_ptr<uml::Class> LibraryModel_umlPackageImpl::get_LibraryModel_uml_Book()
{
	return libraryModel_uml_Book;
}
std::shared_ptr<uml::Property> LibraryModel_umlPackageImpl::get_LibraryModel_uml_Book_authors()
{
	return libraryModel_uml_Book_authors;
}
std::shared_ptr<uml::Property> LibraryModel_umlPackageImpl::get_LibraryModel_uml_Book_book()
{
	return libraryModel_uml_Book_book;
}
std::shared_ptr<uml::Property> LibraryModel_umlPackageImpl::get_LibraryModel_uml_Book_books()
{
	return libraryModel_uml_Book_books;
}
std::shared_ptr<uml::Property> LibraryModel_umlPackageImpl::get_LibraryModel_uml_Book_pictures()
{
	return libraryModel_uml_Book_pictures;
}
std::shared_ptr<uml::Class> LibraryModel_umlPackageImpl::get_LibraryModel_uml_Library()
{
	return libraryModel_uml_Library;
}
std::shared_ptr<uml::Property> LibraryModel_umlPackageImpl::get_LibraryModel_uml_Library_authors()
{
	return libraryModel_uml_Library_authors;
}
std::shared_ptr<uml::Property> LibraryModel_umlPackageImpl::get_LibraryModel_uml_Library_books()
{
	return libraryModel_uml_Library_books;
}
std::shared_ptr<uml::Class> LibraryModel_umlPackageImpl::get_LibraryModel_uml_NamedModelElement()
{
	return libraryModel_uml_NamedModelElement;
}
std::shared_ptr<uml::Property> LibraryModel_umlPackageImpl::get_LibraryModel_uml_NamedModelElement_name()
{
	return libraryModel_uml_NamedModelElement_name;
}
std::shared_ptr<uml::Class> LibraryModel_umlPackageImpl::get_LibraryModel_uml_Picture()
{
	return libraryModel_uml_Picture;
}
std::shared_ptr<uml::Property> LibraryModel_umlPackageImpl::get_LibraryModel_uml_Picture_pageNumber()
{
	return libraryModel_uml_Picture_pageNumber;
}


