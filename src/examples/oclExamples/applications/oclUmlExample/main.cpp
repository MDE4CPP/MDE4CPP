#include <string>
#include <oclParser/Utilities/Ocl.h>
#include <iostream>

#include <uml/Model.hpp>
#include <uml/Package.hpp>
#include <uml/Classifier.hpp>
#include <uml/Enumeration.hpp>
#include <uml/Class.hpp>
#include <uml/Association.hpp>
#include <uml/Property.hpp>
#include <uml/Operation.hpp>
#include <uml/Parameter.hpp>
#include <uml/EnumerationLiteral.hpp>
#include <uml/PrimitiveType.hpp>

#include <BookStore_uml/BookStore_umlFactory.hpp>
#include <BookStore_uml/BookStore_umlPackage.hpp>
#include <BookStore_uml/Library.hpp>

void query1();
void query2();
void query3();
void query4();
void query5();
void query6();

void validate1();
void validate2();
void validate3();
void validate4();
void validate5();
void validate6();

void validate( std::shared_ptr<ecore::EObject> context, const std::string& query);
void query(std::shared_ptr<ecore::EObject> context, const std::string& query);
void pause();

int main()
{
   query1();
   query2();
   query3();
   query4();
   query5();
   query6();

   validate1();
   validate2();
   validate3();
   validate4();
   validate5();
   validate6();

	pause();
	
    return 1;
}

void query1() {
    std::string qry = "self.member";
    std::shared_ptr<uml::Package> context = BookStore_uml::BookStore_umlPackage::eInstance();

    std::cout << "START Query_1 (context[Package] = BookStore_umlPackage): " << qry << std::endl;
    query(context, qry);
    std::cout << "END Query_1 -------------------------------------------\n" << std::endl;
}
void query2() {
    std::string qry = "self.feature";
    std::shared_ptr<uml::Class> context = BookStore_uml::BookStore_umlPackage::eInstance()->get_BookStore_uml_Library();
    std::cout << "START Query_2 (context[Class] = Library): " << qry << std::endl;
    query(context, qry);
    std::cout << "END Query_2 -------------------------------------------\n" << std::endl;
}
void query3() {
    std::string qry = "self.name";
    std::shared_ptr<uml::Property> context =  BookStore_uml::BookStore_umlPackage::eInstance()->get_BookStore_uml_Book_title();
    std::cout << "START Query_3 (context[Property] = Book::title): " << qry << std::endl;
    query(context, qry);
    std::cout << "END Query_3 -------------------------------------------\n" << std::endl;
}
void query4() {
    std::string qry = "self";
    std::shared_ptr<uml::Property> context =  BookStore_uml::BookStore_umlPackage::eInstance()->get_BookStore_uml_Library_books();
    std::cout << "START Query_4 (context[Property] = Book::books): " << qry << std::endl;
    query(context, qry);
    std::cout << "END Query_4 -------------------------------------------\n" << std::endl;
}
void query5() {
    std::string qry = "self";
    std::shared_ptr<uml::Operation> context =  BookStore_uml::BookStore_umlPackage::eInstance()->get_BookStore_uml_Library_addBook_Book_Book();
    std::cout << "START Query_5 (context[EOperation] = Book::addBook): " << qry << std::endl;
    query(context, qry);
    std::cout << "END Query_5 -------------------------------------------\n" << std::endl;
}
void query6() {
    std::string qry = "self.ownedElement";
    std::shared_ptr<uml::Classifier> context = BookStore_uml::BookStore_umlPackage::eInstance()->get_BookStore_uml_BookCategory();
    std::cout << "START Query_5 (context[Enumeration] = BookCategory): " << qry << std::endl;
    query(context, qry);
    std::cout << "END Query_5 -------------------------------------------\n" << std::endl;
}

void validate1() {
    std::string qry = "\ncontext Library::nbBooks : Integer init: 5  \n";
    std::shared_ptr<uml::Object> context = BookStore_uml::BookStore_umlFactory::eInstance()->createLibrary();
    std::cout << "START Validate_1 : " << qry << std::endl;
    validate(context, qry);
    std::cout << "END Validate_1 -------------------------------------------\n" << std::endl;
}
void validate2() {
    std::string qry = "\ncontext Library::opened : Boolean derive: true \n";
    std::shared_ptr<BookStore_uml::Library> context = BookStore_uml::BookStore_umlFactory::eInstance()->createLibrary();
    context->setOpened(true);
    std::cout << "START Validate_2 : " << qry << std::endl;
    validate(context, qry);
    std::cout << "END Validate_2 -------------------------------------------\n" << std::endl;
}
void validate3() {
    std::string qry = "\ncontext Library inv: self.nbBooks > 0 \n";
    std::shared_ptr<BookStore_uml::Library> context = BookStore_uml::BookStore_umlFactory::eInstance()->createLibrary();
    context->setNbBooks(5);
    std::cout << "START Validate_3(nbBooks = 5) : " << qry << std::endl;
    validate(context, qry);
    std::cout << "END Validate_3 -------------------------------------------\n" << std::endl;
}
void validate4() {
    std::string qry = "\ncontext Library \n"
                      "def: value: Real = self.nbBooks / self.nbBooks * self.nbBooks \n"
                      "context Library \n"
                      "inv: 25 = 5 * value \n";
    std::shared_ptr<BookStore_uml::Library> context = BookStore_uml::BookStore_umlFactory::eInstance()->createLibrary();
    context->setNbBooks(5);
    std::cout << "START Validate_4(nbBooks = 5) : " << qry << std::endl;
    validate(context, qry);
    std::cout << "END Validate_4 -------------------------------------------\n" << std::endl;
}
void validate5() {
    std::string qry = "context Library \n"
                      "def: rest1: Real = nbBooks - 2 * nbBooks \n"
                      "context Library \n"
                      "def: rest2: Real = rest1 * 2 \n"
                      "context Library \n"
                      "inv: 15 <> let result : Integer = 0 in nbBooks - rest2 \n";
    std::shared_ptr<BookStore_uml::Library> context = BookStore_uml::BookStore_umlFactory::eInstance()->createLibrary();
    context->setNbBooks(5);
    std::cout << "START Validate_5(nbBooks = 5) : " << qry << std::endl;
    validate(context, qry);
    std::cout << "END Validate_5 -------------------------------------------\n" << std::endl;
}
void validate6() {
    std::string qry = "context Library::getBooks() : Integer \n"
                      "body: self.nbBooks \n";
    std::shared_ptr<BookStore_uml::Library> context = BookStore_uml::BookStore_umlFactory::eInstance()->createLibrary();
    context->setNbBooks(5);
    std::cout << "START Validate_6(nbBooks = 5) : " << qry << std::endl;
    validate(context, qry);
    std::cout << "END Validate_6 -------------------------------------------\n" << std::endl;
}

void validate(std::shared_ptr<ecore::EObject> context,const std::string& query) {
    try {
        Utilities::Ocl ocl;
        ocl.validate(query, context);
        if(ocl.getErrors().size() > 0) {
            std::cout << ocl.getError() << std::endl;
        } else {
            std::cout << ocl.getResult() << std::endl;
        }
    } catch (std::exception &e) {
        std::cout << "exception : " << e.what() << std::endl;
    }
}

void query( std::shared_ptr<ecore::EObject> context, const std::string& query) {
    try {
        Utilities::Ocl ocl;
        if(ocl.query(query, context)) {
            std::cout << ocl.getResult() << std::endl;
        } else {
            std::cout << ocl.getError() << std::endl;
        }
    } catch (std::exception &e) {
        std::cout << "exception : " << e.what() << std::endl;
    }
}

void pause() {
	std::cout << "Enter to continue...";
	std::cin.get();
}