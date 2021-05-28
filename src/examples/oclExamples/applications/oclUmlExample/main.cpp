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

#include <abstractDataTypes/Any.hpp>
#include <abstractDataTypes/Bag.hpp>
#include <abstractDataTypes/SubsetUnion.hpp>

#include <BookStore_uml/BookStore_umlFactory.hpp>
#include <BookStore_uml/BookStore_umlPackage.hpp>
#include <BookStore_uml/Library.hpp>

void query1();
void query2();
void query3();
void query4();
void query5();
void query6();

void uml_any_query1();
void uml_any_query2();
void uml_any_query3();
void uml_any_query4();
void uml_any_query5();
void uml_any_query6();
void uml_any_query7();
void uml_any_query8();

void validate1();
void validate2();
void validate3();
void validate4();
void validate5();
void validate6();

void validate( std::shared_ptr<ecore::EObject> context, const std::string& query);
void query(std::shared_ptr<ecore::EObject> context, const std::string& query);
Any queryValue(std::shared_ptr<ecore::EObject> context, const std::string& query);

void printProperty(std::shared_ptr<uml::Property> prop);
void printTypedElement(std::shared_ptr<uml::TypedElement> utyped);
void printNamedElement(std::shared_ptr<uml::NamedElement> uname);
void printOperation(std::shared_ptr<uml::Operation> uope);
void print(Any value);
void print(Any value, bool isMany);

void pause();

int main()
{
   query1();
   query2();
   query3();
   query4();
   query5();
   query6();

   uml_any_query1();
   uml_any_query2();
   uml_any_query3();
   uml_any_query4();
   uml_any_query5();
   uml_any_query6();
   uml_any_query7();
   uml_any_query8();

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

void uml_any_query1() {
    std::string qry = "self.member";
    std::shared_ptr<uml::Package> context = BookStore_uml::BookStore_umlPackage::eInstance();
    Any value = queryValue(context, qry);

    std::cout << "START Query_Any_1 (context[Package] = BookStore_umlPackage): " << qry << std::endl;
    print(value, true);
    std::cout << "END Query_Any_1 -------------------------------------------\n" << std::endl;
}
void uml_any_query2() {
    std::string qry = "self.feature";
    std::shared_ptr<uml::Class> context = BookStore_uml::BookStore_umlPackage::eInstance()->get_BookStore_uml_Library();
    Any value = queryValue(context, qry);

    std::cout << "START Query_Any_2 (context[Class] = Library): " << qry << std::endl;
    print(value, true);
    std::cout << "END Query_Any_2 -------------------------------------------\n" << std::endl;
}
void uml_any_query3() {
    std::string qry = "self.name";
    std::shared_ptr<uml::Property> context =  BookStore_uml::BookStore_umlPackage::eInstance()->get_BookStore_uml_Book_title();
    Any value = queryValue(context, qry);

    std::cout << "START Query_Any_3 (context[Property] = Book::title): " << qry << std::endl;
    if(value != nullptr) {
        std::cout << value->get<std::string>() << std::endl;
    }
    std::cout << "END Query_Any_3 -------------------------------------------\n" << std::endl;
}
void uml_any_query4() {
    std::string qry = "self";
    std::shared_ptr<uml::Property> context =  BookStore_uml::BookStore_umlPackage::eInstance()->get_BookStore_uml_Library_books();
    Any value = queryValue(context, qry);

    std::cout << "START Query_Any_4 (context[Property] = Book::books): " << qry << std::endl;
    print(value);
    std::cout << "END Query_Any_4 -------------------------------------------\n" << std::endl;
}
void uml_any_query5() {
    std::string qry = "self";
    std::shared_ptr<uml::Operation> context =  BookStore_uml::BookStore_umlPackage::eInstance()->get_BookStore_uml_Library_addBook_Book_Book();
    Any value = queryValue(context, qry);

    std::cout << "START Query_Any_5 (context[EOperation] = Book::addBook): " << qry << std::endl;
    print(value);
    std::cout << "END Query_Any_5 -------------------------------------------\n" << std::endl;
}
void uml_any_query6() {
    std::string qry = "self.ownedElement";
    std::shared_ptr<uml::Classifier> context = BookStore_uml::BookStore_umlPackage::eInstance()->get_BookStore_uml_BookCategory();
    Any value = queryValue(context, qry);

    std::cout << "START Query_Any_6 (context[Enumeration] = BookCategory): " << qry << std::endl;
     print(value, true);
    std::cout << "END Query_Any_6 -------------------------------------------\n" << std::endl;
}

void uml_any_query7() {
    std::string qry = "Set{20, 1 .. 10}";
    std::shared_ptr<uml::Classifier> context = BookStore_uml::BookStore_umlPackage::eInstance()->get_BookStore_uml_BookCategory();
    Any value = queryValue(context, qry);

    std::cout << "START Query_Any_7 : " << qry << std::endl;
     print(value, true);
    std::cout << "END Query_Any_7 -------------------------------------------\n" << std::endl;
}

void uml_any_query8() {
    std::string qry = "Set{1, 2 .. 10}->iterate(i:Integer;sum:Integer=0 | sum + i)";
    std::shared_ptr<uml::Classifier> context = BookStore_uml::BookStore_umlPackage::eInstance()->get_BookStore_uml_BookCategory();
    Any value = queryValue(context, qry);

    std::cout << "START Query_Any_8 : " << qry << std::endl;
    print(value);
    std::cout << "END Query_Any_8 -------------------------------------------\n" << std::endl;
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

void print(Any value) {
    try {
        std::shared_ptr<ecore::EObject> uobj = value->get<std::shared_ptr<ecore::EObject>>();
        std::shared_ptr<uml::Operation> uope = std::dynamic_pointer_cast<uml::Operation>(uobj);
        if(uope != nullptr) {
            return printOperation(uope);
        }
        std::shared_ptr<uml::Property> prop = std::dynamic_pointer_cast<uml::Property>(uobj);
        if(prop != nullptr) {
            return printProperty(prop);
        }
        std::shared_ptr<uml::TypedElement> utyped = std::dynamic_pointer_cast<uml::TypedElement>(uobj);
        if(utyped != nullptr) {
            return printTypedElement(utyped);
        }
        std::shared_ptr<uml::NamedElement> uname = std::dynamic_pointer_cast<uml::NamedElement>(uobj);
        if(uname != nullptr) {
            return printNamedElement(uname);
        }
    } catch (...) { }
    try {
        std::shared_ptr<uml::EnumerationLiteral> liter = value->get<std::shared_ptr<uml::EnumerationLiteral>>();
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

void printProperty(std::shared_ptr<uml::Property> uprop) {
    if(uprop != nullptr) {
        if(uprop->getUpper() > 1 || uprop->getUpper() < 0)
            std::cout << "<Property> " + uprop->getName() + " : " + uprop->getType()->getName() + " ["
                +  std::to_string(uprop->getLower()) + "..*]" << std::endl;
        else
            std::cout << "<Property> " + uprop->getName() + " : " + uprop->getType()->getName() + " ["
                +  std::to_string(uprop->getLower()) + ".." + std::to_string(uprop->getUpper()) + "]" << std::endl;
    }
}

void printTypedElement(std::shared_ptr<uml::TypedElement> utyped) {
    if(utyped != nullptr) {
        std::cout << utyped->getName() + " : " + utyped->getType()->getName() << std::endl;
    }
}

void printNamedElement(std::shared_ptr<uml::NamedElement> uname) {
    if(uname != nullptr) {
        std::cout << uname->getName() << std::endl;
    }
}

void printOperation(std::shared_ptr<uml::Operation> uope) {
    if(uope != nullptr) {
        std::string result = "<Operation> " + uope->getName() + "(";
        std::shared_ptr<Bag<uml::Parameter>> ebag = std::dynamic_pointer_cast<Bag<uml::Parameter>>(uope->getOwnedParameter());
        for(unsigned int i = 0; i < ebag->size(); i++) {
            if(i > 0) result += ", ";
            result += ebag->at(i)->getName() + " : ";
            if(ebag->at(i)->getType() != nullptr) {
                if(ebag->at(i)->getUpper() > 1 || ebag->at(i)->getUpper() < 0)
                    result += ebag->at(i)->getType()->getName()+ " ["
                        +  std::to_string(ebag->at(i)->getLower()) + "..*]";
                else
                    result += ebag->at(i)->getType()->getName()+ " ["
                        +  std::to_string(ebag->at(i)->getLower()) + ".." + std::to_string(ebag->at(i)->getUpper()) + "]";
            }
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
