
#include <iostream>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "BookStore_ecore/BookStore_ecoreFactory.hpp"
#include "BookStore_ecore/BookStore_ecorePackage.hpp"

#include "BookStore_ecore/Library.hpp"
#include "BookStore_ecore/Member.hpp"
#include "BookStore_ecore/Book.hpp"
#include "BookStore_ecore/Loan.hpp"
#include "BookStore_ecore/Writer.hpp"
#include "BookStore_ecore/BookCategory.hpp"

#include <string>
#include <oclParser/Utilities/Ocl.h>

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

// Start of user code includes 
// You may manually edit additional includes, won't be overwritten upon generation.

// End of user code

using namespace BookStore_ecore;

// Start of user code functions 
// You may manually edit additional functions, won't be overwritten upon generation.
/*
These functions are currently stored in the "protected" section of the generated main. 
This is a backup in case the original main.cpp should be deleted.
*/

/*
Helper functions
*/
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

Any queryValue(std::shared_ptr<ecore::EObject> context, const std::string& query) {
    try {
        Utilities::Ocl ocl;
        if(ocl.query(query, context)) {
            return ocl.getResultValue();
        } else {
            std::cout << ocl.getError() << std::endl;
        }
    } catch (std::exception &e) {
        std::cout << "exception : " << e.what() << std::endl;
    }
    return nullptr;
}

void printEAttribute(std::shared_ptr<ecore::EAttribute> eattr) {
    if(eattr != nullptr) {
        if(eattr->getUpperBound() > 1 || eattr->getUpperBound() < 0)
            std::cout << "<EAttribute> " + eattr->getName() + " : " + eattr->getEType()->getName()+ " [" +  std::to_string(eattr->getLowerBound()) + "..*]" << std::endl;
        else
            std::cout << "<EAttribute> " + eattr->getName() + " : " + eattr->getEType()->getName()+ " [" +  std::to_string(eattr->getLowerBound()) + ".." + std::to_string(eattr->getUpperBound()) + "]" << std::endl;
    }
}

void printEReference(std::shared_ptr<ecore::EReference> eref) {
    if(eref != nullptr) {
        if(eref->getUpperBound() > 1 || eref->getUpperBound() < 0)
            std::cout << "<EReference> " + eref->getName() + " : " + eref->getEType()->getName()+ " [" +  std::to_string(eref->getLowerBound()) + "..*]" << std::endl;
        else
            std::cout << "<EReference> " + eref->getName() + " : " + eref->getEType()->getName()+ " [" +  std::to_string(eref->getLowerBound()) + ".." + std::to_string(eref->getUpperBound()) + "]" << std::endl;
    }
}

void printETypedElement(std::shared_ptr<ecore::ETypedElement> etyped) {
    if(etyped != nullptr) {
        if(etyped->isMany())
            std::cout << etyped->getName() + " : " + etyped->getEType()->getName()+ " [0..*]" << std::endl;
        else
            std::cout << etyped->getName() + " : " + etyped->getEType()->getName()+ " [0..1]" << std::endl;
    }
}

void printENamedElement(std::shared_ptr<ecore::ENamedElement> ename) {
    if(ename != nullptr) {
        std::cout << ename->getName() << std::endl;
    }
}

void printEOperation(std::shared_ptr<ecore::EOperation> eope) {
    if(eope != nullptr) {
        std::string result = "<Operation> " + eope->getName() + "(";
        std::shared_ptr<Bag<ecore::EParameter>> ebag = std::dynamic_pointer_cast<Bag<ecore::EParameter>>(eope->getEParameters());
        for(unsigned int i = 0; i < ebag->size(); i++) {
            if(i > 0) result += ", ";
            result += ebag->at(i)->getName() + " : ";
            if(ebag->at(i)->getEType() != nullptr)
                result += ebag->at(i)->getEType()->getName();
            else
                result += "[Not set in Model]";
        }
        result += ")";
        if(eope->getEType() != nullptr && eope->getEType()->getName() != "invalid")
            result += " : " + eope->getEType()->getName();
        std::cout << result << std::endl;
    }
}

void print(Any value) {
    try {
        std::shared_ptr<ecore::EObject> eobj = value->get<std::shared_ptr<ecore::EObject>>();
        std::shared_ptr<ecore::EOperation> eope = std::dynamic_pointer_cast<ecore::EOperation>(eobj);
        if(eope != nullptr) {
            return printEOperation(eope);
        }
        std::shared_ptr<ecore::EAttribute> eattr = std::dynamic_pointer_cast<ecore::EAttribute>(eobj);
        if(eattr != nullptr) {
            return printEAttribute(eattr);
        }
        std::shared_ptr<ecore::EReference> eref = std::dynamic_pointer_cast<ecore::EReference>(eobj);
        if(eref != nullptr) {
            return printEReference(eref);
        }
        std::shared_ptr<ecore::ETypedElement> etyped = std::dynamic_pointer_cast<ecore::ETypedElement>(eobj);
        if(etyped != nullptr) {
            return printETypedElement(etyped);
        }
        std::shared_ptr<ecore::ENamedElement> ename = std::dynamic_pointer_cast<ecore::ENamedElement>(eobj);
        if(ename != nullptr) {
            return printENamedElement(ename);
        }
    } catch (...) { }
    try {
        std::shared_ptr<ecore::EEnumLiteral> liter = value->get<std::shared_ptr<ecore::EEnumLiteral>>();
        std::cout << liter->getName() << std::endl;
        return;
    } catch (...) { }

    try {
        bool result = value->get<bool>();
        std::cout << result << std::endl;
        return;
    } catch (...) { }
    try {
        std::string result = value->get<std::string>();
        std::cout << result << std::endl;
        return;
    } catch (...) { }
    try {
        int result = value->get<int>();
        std::cout << result << std::endl;
        return;
    } catch (...) { }
    try {
        double result = value->get<double>();
        std::cout << result << std::endl;
        return;
    } catch (...) { }
}

void print(Any value, bool isMany) {
    if(value != nullptr && !value->isEmpty()) {
        if(isMany) {
            std::shared_ptr<Bag<AnyObject>> valueItems = value->get<std::shared_ptr<Bag<AnyObject>>>();
            for(size_t i = 0; i < valueItems->size(); i++) {
                print(valueItems->at(i));
            }
        }
        else {
            print(value);
        }
    }
}

void pause() {
	std::cout << "Enter to continue...";
	std::cin.get();
}

/*
Actual OCL functions
*/
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

void ecore_any_query1() {
    std::string qry = "self.name";
    std::shared_ptr<ecore::EPackage> context = BookStore_ecore::BookStore_ecorePackage::eInstance();
    Any value = queryValue(context, qry);

    std::cout << "START Query_Any_1 (context[EPackage] = LibraryPackage): " << qry << std::endl;
    if(value != nullptr) {
        std::cout << value->get<std::string>() << std::endl;
    }
    std::cout << "END Query_Any_1 -------------------------------------------\n" << std::endl;
}
void ecore_any_query2() {
    std::string qry = "self.eAttributes";
    std::shared_ptr<ecore::EClass> context = BookStore_ecore::BookStore_ecorePackage::eInstance()->getLibrary_Class();
    Any value = queryValue(context, qry);

    std::cout << "START Query_Any_2 (context[EClass] = Library): " << qry << std::endl;
    if(value != nullptr) {
        try {
            std::shared_ptr<Bag<AnyObject>> valueItems = value->get<std::shared_ptr<Bag<AnyObject>>>();
            for(size_t i = 0; i < valueItems->size(); i++) {
                std::shared_ptr<ecore::EObject> eobj = valueItems->at(i)->get<std::shared_ptr<ecore::EObject>>();
                std::shared_ptr<ecore::EAttribute> eattr = std::dynamic_pointer_cast<ecore::EAttribute>(eobj);
                printEAttribute(eattr);
            }
        } catch(...) {
            std::cout << "Error : get failed" << std::endl;
        }
    }
    std::cout << "END Query_Any_2 -------------------------------------------\n" << std::endl;
}
void ecore_any_query3() {
    std::string qry = "self.name";
    std::shared_ptr<ecore::EAttribute> context = BookStore_ecore::BookStore_ecorePackage::eInstance()->getBook_Attribute_category();
    Any value = queryValue(context, qry);

    std::cout << "START Query_Any_3 (context[EAttribute] = Book::category): " << qry << std::endl;
    if(value != nullptr) {
        std::cout << value->get<std::string>() << std::endl;
    }
    std::cout << "END Query_Any_3 -------------------------------------------\n" << std::endl;
}
void ecore_any_query4() {
    std::string qry = "self";
    std::shared_ptr<ecore::EReference> context = BookStore_ecore::BookStore_ecorePackage::eInstance()->getLibrary_Attribute_books();
    Any value = queryValue(context, qry);

    std::cout << "START Query_4 (context[EReference] = Book::books): " << qry << std::endl;
    if(value != nullptr) {
        std::shared_ptr<ecore::EReference> eref = std::dynamic_pointer_cast<ecore::EReference>
                (value->get<std::shared_ptr<ecore::EObject>>());
        printEReference(eref);
    }
    std::cout << "END Query_4 -------------------------------------------\n" << std::endl;
}
void ecore_any_query5() {
    std::string qry = "self";
    std::shared_ptr<ecore::EOperation> context = BookStore_ecore::BookStore_ecorePackage::eInstance()->getLibrary_Operation_addBook_Book();
    Any value = queryValue(context, qry);

    std::cout << "START Query_5 (context[EOperation] = Book::addBook): " << qry << std::endl;
    if(value != nullptr) {
        std::shared_ptr<ecore::EOperation> eope = std::dynamic_pointer_cast<ecore::EOperation>
                (value->get<std::shared_ptr<ecore::EObject>>());
        printEOperation(eope);
    }
    std::cout << "END Query_5 -------------------------------------------\n" << std::endl;
}

void ecore_any_query6() {
    std::string qry = "self.eStructuralFeatures";
    std::shared_ptr<ecore::EClass> context = BookStore_ecore::BookStore_ecorePackage::eInstance()->getLibrary_Class();
    Any value = queryValue(context, qry);

    std::cout << "START Query_Any_6 (context[EClass] = Library): " << qry << std::endl;
    print(value, true);
    std::cout << "END Query_Any_6 -------------------------------------------\n" << std::endl;
}

void ecore_any_query7() {
    std::string qry = "Set{20, 1 .. 10}";
    std::shared_ptr<ecore::EClass> context = BookStore_ecore::BookStore_ecorePackage::eInstance()->getLibrary_Class();
    Any value = queryValue(context, qry);

    std::cout << "START Query_Any_7 : " << qry << std::endl;
    print(value, true);
    std::cout << "END Query_Any_7 -------------------------------------------\n" << std::endl;
}

void ecore_any_query8() {
    std::string qry = "Set{1, 2 .. 10}->iterate(i:Integer;sum:Integer=0 | sum + i)";
    std::shared_ptr<ecore::EClass> context = BookStore_ecore::BookStore_ecorePackage::eInstance()->getLibrary_Class();
    Any value = queryValue(context, qry);

    std::cout << "START Query_Any_8 : " << qry << std::endl;
    print(value);
    std::cout << "END Query_Any_8 -------------------------------------------\n" << std::endl;
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
                      "context Book::countCopies() : Integer \n"
                      "body: self.copies \n"
                      "endpackage \n";
    std::shared_ptr<BookStore_ecore::Book> context = BookStore_ecore::BookStore_ecoreFactory::eInstance()->createBook();
    context->setCopies(5);
    std::cout << "START Validate_6(copies = 5) : " << qry << std::endl;
    validate(context, qry);
    std::cout << "END Validate_6 -------------------------------------------\n" << std::endl;
}

void validate7() {
    std::string qry = "\npackage BookStore_ecore \n"
                      "context Book::addCopies(nbCopies:Integer=2): \n"
                      "pre: nbCopies > 0 \n"
                      "endpackage \n";
    std::shared_ptr<BookStore_ecore::Book> context = BookStore_ecore::BookStore_ecoreFactory::eInstance()->createBook();
    std::cout << "START Validate_7(addCopy(2)) : " << qry << std::endl;
    validate(context, qry);
    std::cout << "END Validate_7 -------------------------------------------\n" << std::endl;
}

void validate8() {
    std::string qry = "\npackage BookStore_ecore \n"
                      "context Book::addCopies(nbCopies:Integer=2): \n"
                      "post: self.copies = 2 \n"
                      "endpackage \n";
    std::shared_ptr<BookStore_ecore::Book> context = BookStore_ecore::BookStore_ecoreFactory::eInstance()->createBook();
    std::cout << "START Validate_8(addCopy(2)) : " << qry << std::endl;
    validate(context, qry);
    std::cout << "END Validate_8 -------------------------------------------\n" << std::endl;
}

void validate9() {
    std::string qry = "\npackage BookStore_ecore \n"
                      "context Library::open(): \n"
                      "pre: self.opened = false \n"
                      "endpackage \n";
    std::shared_ptr<BookStore_ecore::Library> context = BookStore_ecore::BookStore_ecoreFactory::eInstance()->createLibrary();
    context->setOpened(false);
    std::cout << "START Validate_9(open()) : " << qry << std::endl;
    validate(context, qry);
    std::cout << "END Validate_9 -------------------------------------------\n" << std::endl;
}

void validate10() {
    std::string qry = "context Library::open(): \n"
                      "post: self.opened = true";
    std::shared_ptr<BookStore_ecore::Library> context = BookStore_ecore::BookStore_ecoreFactory::eInstance()->createLibrary();
    context->setOpened(false);
    std::cout << "START Validate_10(open()) : " << qry << std::endl;
    validate(context, qry);
    std::cout << "END Validate_10 -------------------------------------------\n" << std::endl;
}

void validate11() {
    std::string qry = "\npackage BookStore_ecore \n"
                      "context Book::addCopies(nbCopies:Integer=2): \n"
                      "post: copies = copies@pre + nbCopies \n"
                      "endpackage \n";
    std::shared_ptr<BookStore_ecore::Book> context = BookStore_ecore::BookStore_ecoreFactory::eInstance()->createBook();
    std::cout << "START Validate_11(addCopies(2)) : " << qry << std::endl;
    validate(context, qry);
    std::cout << "END Validate_11 -------------------------------------------\n" << std::endl;
}
// End of user code



int main ()
{
	//Create Model Factory
	std::shared_ptr<BookStore_ecoreFactory> factory = BookStore_ecoreFactory::eInstance();

query1();
query2();
query3();
query4();
query5();

ecore_any_query1();
ecore_any_query2();
ecore_any_query3();
ecore_any_query4();
ecore_any_query5();
ecore_any_query6();
ecore_any_query7();
ecore_any_query8();

validate1();
validate2();
validate3();
validate4();
validate5();
validate6();
validate7();
validate8();
validate9();
validate10();
validate11();

pause();

// Start of user code main
// You may manually edit the following lines, won't be overwritten upon generation.

// End of user code

    return 0;

}
