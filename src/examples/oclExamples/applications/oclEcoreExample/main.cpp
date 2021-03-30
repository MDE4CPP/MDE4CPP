#include <string>
#include <oclParser/Utilities/Ocl.h>
#include <iostream>

#include <ecore/EFactory.hpp>
#include <ecore/EPackage.hpp>
#include <ecore/EClassifier.hpp>
#include <ecore/EEnum.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EOperation.hpp>
#include <ecore/EAttribute.hpp>
#include <ecore/EParameter.hpp>
#include <ecore/EEnumLiteral.hpp>
#include <ecore/ETypeParameter.hpp>

#include <BookStore_ecore/BookStore_ecoreFactory.hpp>
#include <BookStore_ecore/BookStore_ecorePackage.hpp>
#include <BookStore_ecore/Library.hpp>

void query1();
void query2();
void query3();
void query4();
void query5();

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
    std::string qry = "self.name";
    std::shared_ptr<ecore::EPackage> context = BookStore_ecore::BookStore_ecorePackage::eInstance();

    std::cout << "START Query_1 (context[EPackage] = LibraryPackage): " << qry << std::endl;
    query(context, qry);
    std::cout << "END Query_1 -------------------------------------------\n" << std::endl;
}
void query2() {
    std::string qry = "self.eAttributes";
    std::shared_ptr<ecore::EClass> context = BookStore_ecore::BookStore_ecorePackage::eInstance()->getLibrary_Class();
    std::cout << "START Query_2 (context[EClass] = Library): " << qry << std::endl;
    query(context, qry);
    std::cout << "END Query_2 -------------------------------------------\n" << std::endl;
}
void query3() {
    std::string qry = "self.name";
    std::shared_ptr<ecore::EAttribute> context = BookStore_ecore::BookStore_ecorePackage::eInstance()->getBook_Attribute_category();
    std::cout << "START Query_3 (context[EAttribute] = Book::category): " << qry << std::endl;
    query(context, qry);
    std::cout << "END Query_3 -------------------------------------------\n" << std::endl;
}
void query4() {
    std::string qry = "self";
    std::shared_ptr<ecore::EReference> context = BookStore_ecore::BookStore_ecorePackage::eInstance()->getLibrary_Attribute_books();
    std::cout << "START Query_4 (context[EReference] = Book::books): " << qry << std::endl;
    query(context, qry);
    std::cout << "END Query_4 -------------------------------------------\n" << std::endl;
}
void query5() {
    std::string qry = "self";
    std::shared_ptr<ecore::EOperation> context = BookStore_ecore::BookStore_ecorePackage::eInstance()->getLibrary_Operation_addBook_Book();
    std::cout << "START Query_5 (context[EOperation] = Book::addBook): " << qry << std::endl;
    query(context, qry);
    std::cout << "END Query_5 -------------------------------------------\n" << std::endl;
}

void validate1() {
    std::string qry = "\npackage BookStore_ecore \n"
                      "context Library::books : Integer \n"
                      "init: nbBooks = 0 \n"
                      "endpackage \n";
    std::shared_ptr<ecore::EObject> context = BookStore_ecore::BookStore_ecoreFactory::eInstance()->createLibrary();
    std::cout << "START Validate_1 : " << qry << std::endl;
    validate(context, qry);
    std::cout << "END Validate_1 -------------------------------------------\n" << std::endl;
}
void validate2() {
    std::string qry = "\ncontext Library::opened : Boolean derive: true \n";
    std::shared_ptr<BookStore_ecore::Library> context = BookStore_ecore::BookStore_ecoreFactory::eInstance()->createLibrary();
    context->setOpened(true);
    std::cout << "START Validate_2 : " << qry << std::endl;
    validate(context, qry);
    std::cout << "END Validate_2 -------------------------------------------\n" << std::endl;
}
void validate3() {
    std::string qry = "\ncontext Library inv: self.nbBooks > 0 \n";
    std::shared_ptr<BookStore_ecore::Library> context = BookStore_ecore::BookStore_ecoreFactory::eInstance()->createLibrary();
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
    std::shared_ptr<BookStore_ecore::Library> context = BookStore_ecore::BookStore_ecoreFactory::eInstance()->createLibrary();
    context->setNbBooks(5);
    std::cout << "START Validate_4(nbBooks = 5) : " << qry << std::endl;
    validate(context, qry);
    std::cout << "END Validate_4 -------------------------------------------\n" << std::endl;
}
void validate5() {
    std::string qry = "\npackage BookStore_ecore \n"
                      "context Library \n"
                      "def: rest1: Real = nbBooks - 2 * nbBooks \n"
                      "context Library \n"
                      "def: rest2: Real = rest1 * 2 \n"
                      "context Library \n"
                      "inv: 15 <> let result : Integer = 0 in nbBooks - rest2 \n"
                      "endpackage \n";
    std::shared_ptr<BookStore_ecore::Library> context = BookStore_ecore::BookStore_ecoreFactory::eInstance()->createLibrary();
    context->setNbBooks(5);
    std::cout << "START Validate_5(nbBooks = 5) : " << qry << std::endl;
    validate(context, qry);
    std::cout << "END Validate_5 -------------------------------------------\n" << std::endl;
}
void validate6() {
    std::string qry = "\npackage BookStore_ecore \n"
                      "context Library::getBooks() : Integer \n"
                      "body: self.nbBooks \n"
                      "endpackage \n";
    std::shared_ptr<BookStore_ecore::Library> context = BookStore_ecore::BookStore_ecoreFactory::eInstance()->createLibrary();
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
