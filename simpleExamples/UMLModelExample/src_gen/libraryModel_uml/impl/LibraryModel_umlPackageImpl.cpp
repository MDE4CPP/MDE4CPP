#include "LibraryModel_umlPackageImpl.hpp"

//metamodel classes
#include "Stereotype.hpp"
#include "Generalization.hpp"
#include "Constraint.hpp"
#include "OpaqueExpression.hpp"
#include "EnumerationLiteral.hpp"
#include "PrimitiveType.hpp"
#include "FunctionBehavior.hpp"
#include "Interface.hpp"
#include "Operation.hpp"
#include "Property.hpp"

#include "Generalization.hpp"
#include "Property.hpp"
#include "PackageImport.hpp"
#include "Class.hpp"
#include "LiteralUnlimitedNatural.hpp"
#include "LiteralInteger.hpp"
#include "Association.hpp"
//metamodel factory
#include "LibraryModel_umlFactory.hpp"
#include "UmlFactory.hpp"

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
	metaModelPackage->initMetaModel();
    metaModelPackage->createPackageContents();
    return metaModelPackage;
}

void LibraryModel_umlPackageImpl::init()
{
    // Initialize created meta-data
    initializePackageContents();   
}

void LibraryModel_umlPackageImpl::initMetaModel()
{
}

void LibraryModel_umlPackageImpl::createPackageContents()
{
	if (isCreated)
	{
		return;
	}
	isCreated = true;

	struct null_deleter{void operator()(void const *) const {} };
	std::shared_ptr<LibraryModel_umlPackageImpl> libraryModel_uml = std::shared_ptr<LibraryModel_umlPackageImpl>(this, null_deleter());
	std::shared_ptr<uml::Constraint> con = nullptr;
	std::shared_ptr<uml::OpaqueExpression> oe = nullptr;
	
	libraryModel_uml_A_Lib_Author_library_lowerValue_LiteralInteger_LibraryModel_uml_A_Lib_Author_library = uml::UmlFactory::eInstance()->createLiteralInteger_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_A_Lib_Author_library));
	libraryModel_uml_A_Lib_Author_library_lowerValue_LiteralInteger_LibraryModel_uml_A_Lib_Author_library->setValue(0);
	
	libraryModel_uml_A_Lib_Author_library_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_A_Lib_Author_library = uml::UmlFactory::eInstance()->createLiteralUnlimitedNatural_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_A_Lib_Author_library));
	libraryModel_uml_A_Lib_Author_library_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_A_Lib_Author_library->setValue(1);
	
	libraryModel_uml_A_Lib_Boock_library_lowerValue_LiteralInteger_LibraryModel_uml_A_Lib_Boock_library = uml::UmlFactory::eInstance()->createLiteralInteger_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_A_Lib_Boock_library));
	libraryModel_uml_A_Lib_Boock_library_lowerValue_LiteralInteger_LibraryModel_uml_A_Lib_Boock_library->setValue(0);
	
	libraryModel_uml_A_Lib_Boock_library_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_A_Lib_Boock_library = uml::UmlFactory::eInstance()->createLiteralUnlimitedNatural_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_A_Lib_Boock_library));
	libraryModel_uml_A_Lib_Boock_library_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_A_Lib_Boock_library->setValue(1);
	
	libraryModel_uml_Book_authors_lowerValue_LiteralInteger_LibraryModel_uml_Book_authors = uml::UmlFactory::eInstance()->createLiteralInteger_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_Book_authors));
	libraryModel_uml_Book_authors_lowerValue_LiteralInteger_LibraryModel_uml_Book_authors->setValue(0);
	
	libraryModel_uml_Book_authors_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_Book_authors = uml::UmlFactory::eInstance()->createLiteralUnlimitedNatural_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_Book_authors));
	libraryModel_uml_Book_authors_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_Book_authors->setValue(-1);
	
	libraryModel_uml_Book_pictures_lowerValue_LiteralInteger_LibraryModel_uml_Book_pictures = uml::UmlFactory::eInstance()->createLiteralInteger_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_Book_pictures));
	libraryModel_uml_Book_pictures_lowerValue_LiteralInteger_LibraryModel_uml_Book_pictures->setValue(0);
	
	libraryModel_uml_Book_pictures_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_Book_pictures = uml::UmlFactory::eInstance()->createLiteralUnlimitedNatural_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_Book_pictures));
	libraryModel_uml_Book_pictures_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_Book_pictures->setValue(-1);
	
	libraryModel_uml_Book_book_lowerValue_LiteralInteger_LibraryModel_uml_Book_book = uml::UmlFactory::eInstance()->createLiteralInteger_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_Book_book));
	libraryModel_uml_Book_book_lowerValue_LiteralInteger_LibraryModel_uml_Book_book->setValue(0);
	
	libraryModel_uml_Book_book_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_Book_book = uml::UmlFactory::eInstance()->createLiteralUnlimitedNatural_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_Book_book));
	libraryModel_uml_Book_book_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_Book_book->setValue(1);
	
	libraryModel_uml_Book_books_lowerValue_LiteralInteger_LibraryModel_uml_Book_books = uml::UmlFactory::eInstance()->createLiteralInteger_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_Book_books));
	libraryModel_uml_Book_books_lowerValue_LiteralInteger_LibraryModel_uml_Book_books->setValue(0);
	
	libraryModel_uml_Book_books_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_Book_books = uml::UmlFactory::eInstance()->createLiteralUnlimitedNatural_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_Book_books));
	libraryModel_uml_Book_books_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_Book_books->setValue(-1);
	
	libraryModel_uml_Library_authors_lowerValue_LiteralInteger_LibraryModel_uml_Library_authors = uml::UmlFactory::eInstance()->createLiteralInteger_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_Library_authors));
	libraryModel_uml_Library_authors_lowerValue_LiteralInteger_LibraryModel_uml_Library_authors->setValue(0);
	
	libraryModel_uml_Library_authors_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_Library_authors = uml::UmlFactory::eInstance()->createLiteralUnlimitedNatural_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_Library_authors));
	libraryModel_uml_Library_authors_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_Library_authors->setValue(-1);
	
	libraryModel_uml_Library_books_lowerValue_LiteralInteger_LibraryModel_uml_Library_books = uml::UmlFactory::eInstance()->createLiteralInteger_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_Library_books));
	libraryModel_uml_Library_books_lowerValue_LiteralInteger_LibraryModel_uml_Library_books->setValue(0);
	
	libraryModel_uml_Library_books_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_Library_books = uml::UmlFactory::eInstance()->createLiteralUnlimitedNatural_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_Library_books));
	libraryModel_uml_Library_books_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_Library_books->setValue(-1);
	
	libraryModel_uml_NamedModelElement_name_lowerValue_LiteralInteger_LibraryModel_uml_NamedModelElement_name = uml::UmlFactory::eInstance()->createLiteralInteger_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_NamedModelElement_name));
	libraryModel_uml_NamedModelElement_name_lowerValue_LiteralInteger_LibraryModel_uml_NamedModelElement_name->setValue(0);
	
	libraryModel_uml_NamedModelElement_name_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_NamedModelElement_name = uml::UmlFactory::eInstance()->createLiteralUnlimitedNatural_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_NamedModelElement_name));
	libraryModel_uml_NamedModelElement_name_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_NamedModelElement_name->setValue(1);
	
	libraryModel_uml_Picture_pageNumber_lowerValue_LiteralInteger_LibraryModel_uml_Picture_pageNumber = uml::UmlFactory::eInstance()->createLiteralInteger_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_Picture_pageNumber));
	libraryModel_uml_Picture_pageNumber_lowerValue_LiteralInteger_LibraryModel_uml_Picture_pageNumber->setValue(0);
	
	libraryModel_uml_Picture_pageNumber_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_Picture_pageNumber = uml::UmlFactory::eInstance()->createLiteralUnlimitedNatural_in_Namespace(std::dynamic_pointer_cast<uml::Namespace>(libraryModel_uml_Picture_pageNumber));
	libraryModel_uml_Picture_pageNumber_upperValue_LiteralUnlimitedNatural_LibraryModel_uml_Picture_pageNumber->setValue(1);
	
	


	libraryModel_uml_Author = uml::UmlFactory::eInstance()->createClass_in_Package(libraryModel_uml);
	libraryModel_uml_Author->setName("Author");
	libraryModel_uml_Author->setIsAbstract(false);
	
	//constraints
	
	
	
	
	


	libraryModel_uml_Book = uml::UmlFactory::eInstance()->createClass_in_Package(libraryModel_uml);
	libraryModel_uml_Book->setName("Book");
	libraryModel_uml_Book->setIsAbstract(false);
	
	//constraints
	
	
	libraryModel_uml_Book_authors = uml::UmlFactory::eInstance()->createProperty_in_Class(libraryModel_uml_Book);
	
	libraryModel_uml_Book_authors->setName("authors");
	libraryModel_uml_Book_authors->setType(get_LibraryModel_uml_Author());
	libraryModel_uml_Book_authors->setLower(0);
	libraryModel_uml_Book_authors->setUpper(-1);
	
	
	
	libraryModel_uml_Book_pictures = uml::UmlFactory::eInstance()->createProperty_in_Class(libraryModel_uml_Book);
	
	libraryModel_uml_Book_pictures->setName("pictures");
	libraryModel_uml_Book_pictures->setType(get_LibraryModel_uml_Picture());
	libraryModel_uml_Book_pictures->setLower(0);
	libraryModel_uml_Book_pictures->setUpper(-1);
	
	
	
	
	
	


	libraryModel_uml_Library = uml::UmlFactory::eInstance()->createClass_in_Package(libraryModel_uml);
	libraryModel_uml_Library->setName("Library");
	libraryModel_uml_Library->setIsAbstract(false);
	
	//constraints
	
	
	libraryModel_uml_Library_authors = uml::UmlFactory::eInstance()->createProperty_in_Class(libraryModel_uml_Library);
	
	libraryModel_uml_Library_authors->setName("authors");
	libraryModel_uml_Library_authors->setType(get_LibraryModel_uml_Author());
	libraryModel_uml_Library_authors->setLower(0);
	libraryModel_uml_Library_authors->setUpper(-1);
	
	
	
	libraryModel_uml_Library_books = uml::UmlFactory::eInstance()->createProperty_in_Class(libraryModel_uml_Library);
	
	libraryModel_uml_Library_books->setName("books");
	libraryModel_uml_Library_books->setType(get_LibraryModel_uml_Book());
	libraryModel_uml_Library_books->setLower(0);
	libraryModel_uml_Library_books->setUpper(-1);
	
	
	
	
	
	


	libraryModel_uml_NamedModelElement = uml::UmlFactory::eInstance()->createClass_in_Package(libraryModel_uml);
	libraryModel_uml_NamedModelElement->setName("NamedModelElement");
	libraryModel_uml_NamedModelElement->setIsAbstract(false);
	
	//constraints
	
	
	libraryModel_uml_NamedModelElement_name = uml::UmlFactory::eInstance()->createProperty_in_Class(libraryModel_uml_NamedModelElement);
	
	libraryModel_uml_NamedModelElement_name->setName("name");
	libraryModel_uml_NamedModelElement_name->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String());
	libraryModel_uml_NamedModelElement_name->setLower(0);
	libraryModel_uml_NamedModelElement_name->setUpper(1);
	
	
	
	
	
	


	libraryModel_uml_Picture = uml::UmlFactory::eInstance()->createClass_in_Package(libraryModel_uml);
	libraryModel_uml_Picture->setName("Picture");
	libraryModel_uml_Picture->setIsAbstract(false);
	
	//constraints
	
	
	libraryModel_uml_Picture_pageNumber = uml::UmlFactory::eInstance()->createProperty_in_Class(libraryModel_uml_Picture);
	
	libraryModel_uml_Picture_pageNumber->setName("pageNumber");
	libraryModel_uml_Picture_pageNumber->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Integer());
	libraryModel_uml_Picture_pageNumber->setLower(0);
	libraryModel_uml_Picture_pageNumber->setUpper(1);
	
	
	
	
	
	





//Dependency 

	

}

void LibraryModel_umlPackageImpl::initializePackageContents()
{
	if (isInitialized)
	{
		return;
	}
	isInitialized = true;

	// Initialize package
	setName(eNAME);
	setURI(eNS_URI);

	// Add supertypes to classes
	struct null_deleter{void operator()(void const *) const {} };
	std::shared_ptr<LibraryModel_umlPackageImpl> libraryModel_uml = std::shared_ptr<LibraryModel_umlPackageImpl>(this, null_deleter());
	std::shared_ptr<uml::Generalization> gen = nullptr;
	gen = uml::UmlFactory::eInstance()->createGeneralization_in_Specific(get_LibraryModel_uml_Author());
	gen->setGeneral(get_LibraryModel_uml_NamedModelElement());
	
	gen = uml::UmlFactory::eInstance()->createGeneralization_in_Specific(get_LibraryModel_uml_Book());
	gen->setGeneral(get_LibraryModel_uml_NamedModelElement());
	
	gen = uml::UmlFactory::eInstance()->createGeneralization_in_Specific(get_LibraryModel_uml_Picture());
	gen->setGeneral(get_LibraryModel_uml_NamedModelElement());
	
	
	
	

	
	
	//initalize ActivityNodes and Edges
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
std::shared_ptr<uml::Property> LibraryModel_umlPackageImpl::get_LibraryModel_uml_Book_pictures()
{
	return libraryModel_uml_Book_pictures;
}
std::shared_ptr<uml::Property> LibraryModel_umlPackageImpl::get_LibraryModel_uml_Book_book()
{
	return libraryModel_uml_Book_book;
}
std::shared_ptr<uml::Property> LibraryModel_umlPackageImpl::get_LibraryModel_uml_Book_books()
{
	return libraryModel_uml_Book_books;
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


