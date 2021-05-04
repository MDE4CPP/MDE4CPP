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

#include <abstractDataTypes/Bag.hpp>
#include <abstractDataTypes/SubsetUnion.hpp>

#include <BookStore_ecore/BookStore_ecoreFactory.hpp>
#include <BookStore_ecore/BookStore_ecorePackage.hpp>
#include <BookStore_ecore/Library.hpp>

void query1();
void query2();
void query3();
void query4();
void query5();

void ecore_any_query1();
void ecore_any_query2();
void ecore_any_query3();
void ecore_any_query4();
void ecore_any_query5();
void ecore_any_query6();

void validate1();
void validate2();
void validate3();
void validate4();
void validate5();
void validate6();

void validate( std::shared_ptr<ecore::EObject> context, const std::string& query);
void query(std::shared_ptr<ecore::EObject> context, const std::string& query);
Any queryValue(std::shared_ptr<ecore::EObject> context, const std::string& query);

void printEAttribute(std::shared_ptr<ecore::EAttribute> eattr);
void printEReference(std::shared_ptr<ecore::EReference> eref);
void printETypedElement(std::shared_ptr<ecore::ETypedElement> etyped);
void printENamedElement(std::shared_ptr<ecore::ENamedElement> ename);
void printEOperation(std::shared_ptr<ecore::EOperation> eope);
void printEObject(std::shared_ptr<ecore::EObject> eobj);
void printEcoreAny(Any value, bool isMany);

void pause();

int main()
{
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
        std::shared_ptr<Bag<ecore::EObject>> valueItems = value->get<std::shared_ptr<Bag<ecore::EObject>>>();
        for(size_t i = 0; i < valueItems->size(); i++) {
            std::shared_ptr<ecore::EAttribute> eattr = std::dynamic_pointer_cast<ecore::EAttribute>(valueItems->at(i));
            printEAttribute(eattr);
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
        std::shared_ptr<ecore::EReference> eref = std::dynamic_pointer_cast<ecore::EReference>(value);
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
        std::shared_ptr<ecore::EOperation> eope = std::dynamic_pointer_cast<ecore::EOperation>(value);
        printEOperation(eope);
    }
    std::cout << "END Query_5 -------------------------------------------\n" << std::endl;
}

void ecore_any_query6() {
    std::string qry = "self.eStructuralFeatures";
    std::shared_ptr<ecore::EClass> context = BookStore_ecore::BookStore_ecorePackage::eInstance()->getLibrary_Class();
    Any value = queryValue(context, qry);

    std::cout << "START Query_Any_2 (context[EClass] = Library): " << qry << std::endl;
    printEcoreAny(value, true);
    std::cout << "END Query_Any_2 -------------------------------------------\n" << std::endl;
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

void printEcoreAny(Any value, bool isMany) {
    if(value != nullptr && !value->isEmpty()) {
        if(isMany) {
            std::shared_ptr<Bag<ecore::EObject>> valueItems = value->get<std::shared_ptr<Bag<ecore::EObject>>>();
            for(size_t i = 0; i < valueItems->size(); i++) {
                printEObject(valueItems->at(i));
            }
        }
        else {
            try {
                std::shared_ptr<ecore::EObject> obj = value->get<std::shared_ptr<ecore::EObject>>();
                return printEObject(obj);
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
    }
}

void printEObject(std::shared_ptr<ecore::EObject> eobj) {
    if(eobj != nullptr) {
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
    }
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
        std::cout << result << std::endl;
    }
}

void pause() {
	std::cout << "Enter to continue...";
	std::cin.get();
}
