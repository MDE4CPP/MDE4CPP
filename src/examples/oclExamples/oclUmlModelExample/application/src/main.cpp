
#include <iostream>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "BookStore_uml/BookStore_umlFactory.hpp"
#include "BookStore_uml/BookStore_umlPackage.hpp"

#include "BookStore_uml/Book.hpp"
#include "BookStore_uml/Library.hpp"
#include "BookStore_uml/Loan.hpp"
#include "BookStore_uml/Member.hpp"
#include "BookStore_uml/Writer.hpp"
#include "BookStore_uml/BookCategory.hpp"

//Includes from main behavior main
#include <string>
#include <sstream>
#include <oclParser/Utilities/Ocl.h>

#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"

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
#include <ecore/ecorePackage.hpp>
#include <ecore/ecoreFactory.hpp>
#include <ecore/EClassifier.hpp>
#include <ecore/EObjectContainer.hpp>
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

using namespace BookStore_uml;

// Start of user code functions 
// You may manually edit additional functions, won't be overwritten upon generation.
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

std::string printProperty(std::shared_ptr<uml::Property> uprop) {
	std::ostringstream returnStringStream;
    if(uprop != nullptr) {
        if(uprop->getUpper() > 1 || uprop->getUpper() < 0)
        	returnStringStream  << "<Property> " + uprop->getName() + " : " + uprop->getType()->getName() + " ["
                +  std::to_string(uprop->getLower()) + "..*]" << std::endl;
        else
        	returnStringStream  << "<Property> " + uprop->getName() + " : " + uprop->getType()->getName() + " ["
                +  std::to_string(uprop->getLower()) + ".." + std::to_string(uprop->getUpper()) + "]" << std::endl;
    }
	return returnStringStream.str();
}

std::string printTypedElement(std::shared_ptr<uml::TypedElement> utyped) {
	std::ostringstream returnStringStream;
    if(utyped != nullptr) {
    	returnStringStream << utyped->getName() + " : " + utyped->getType()->getName() << std::endl;
    }
	return returnStringStream.str();
}

std::string printNamedElement(std::shared_ptr<uml::NamedElement> uname) {
	std::ostringstream returnStringStream;
    if(uname != nullptr) {
    	returnStringStream << uname->getName() << std::endl;
    }
	return returnStringStream.str();
}

std::string printOperation(std::shared_ptr<uml::Operation> uope) {
	std::string result = "<Operation> ";
    if(uope != nullptr) {
        result += uope->getName() + "(";
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
     }
	return result;
}

std::string printEAttribute(std::shared_ptr<ecore::EAttribute> eattr) {
	std::ostringstream returnStringStream;
    if(eattr != nullptr) {
        if(eattr->getUpperBound() > 1 || eattr->getUpperBound() < 0)
        	returnStringStream << "<EAttribute>:" + eattr->getName() + ":" + eattr->getEType()->getName()+ "[" +  std::to_string(eattr->getLowerBound()) + "..*]" << std::endl;
        else
        	returnStringStream << "<EAttribute>:" + eattr->getName() + ":" + eattr->getEType()->getName()+ "[" +  std::to_string(eattr->getLowerBound()) + ".." + std::to_string(eattr->getUpperBound()) + "]" << std::endl;
    }
	return returnStringStream.str();
}

std::string printEReference(std::shared_ptr<ecore::EReference> eref) {
	std::ostringstream returnStringStream;
    if(eref != nullptr) {
        if(eref->getUpperBound() > 1 || eref->getUpperBound() < 0)
        	returnStringStream << "<EReference>:" + eref->getName() + ":" + eref->getEType()->getName()+ "[" +  std::to_string(eref->getLowerBound()) + "..*]" << std::endl;
        else
        	returnStringStream << "<EReference>:" + eref->getName() + ":" + eref->getEType()->getName()+ "[" +  std::to_string(eref->getLowerBound()) + ".." + std::to_string(eref->getUpperBound()) + "]" << std::endl;
    }
	return returnStringStream.str();
}

std::string  printETypedElement(std::shared_ptr<ecore::ETypedElement> etyped) {
	std::ostringstream returnStringStream;
    if(etyped != nullptr) {
        if(etyped->isMany())
        	returnStringStream << etyped->getName() + ":" + etyped->getEType()->getName()+ "[0..*]" << std::endl;
        else
        	returnStringStream << etyped->getName() + ":" + etyped->getEType()->getName()+ "[0..1]" << std::endl;
    }
	return returnStringStream.str();
}

std::string printENamedElement(std::shared_ptr<ecore::ENamedElement> ename) {
	std::ostringstream returnStringStream;
    if(ename != nullptr) {
    	returnStringStream << ename->getName() << std::endl;
    }
	return returnStringStream.str();
}

std::string printEOperation(std::shared_ptr<ecore::EOperation> eope) {
	std::string result="";
    if(eope != nullptr) {
        result = "<Operation>:" + eope->getName() + "(";
        std::shared_ptr<Bag<ecore::EParameter>> ebag = std::dynamic_pointer_cast<Bag<ecore::EParameter>>(eope->getEParameters());
        for(unsigned int i = 0; i < ebag->size(); i++) {
            if(i > 0) result += ", ";
            result += ebag->at(i)->getName() + ":";
            if(ebag->at(i)->getEType() != nullptr)
                result += ebag->at(i)->getEType()->getName();
            else
                result += "[Not set in Model]";
        }
        result += ")";
        if(eope->getEType() != nullptr && eope->getEType()->getName() != "invalid")
            result += ":" + eope->getEType()->getName();
    }
	return result;
}

std::string print(Any value) {
	std::ostringstream returnStringStream;

	bool handled=false;
    try{
    	switch(value->getTypeId())
    	{
			case ecore::ecorePackage::EOBJECT_CLASS: // unknown or primitive type
			{
				std::shared_ptr<ecore::EObject> eobj = value->get<std::shared_ptr<ecore::EObject>>();
			    std::shared_ptr<uml::Operation> uope = std::dynamic_pointer_cast<uml::Operation>(eobj);
				if(uope != nullptr) {
					return printOperation(uope);
				}
				std::shared_ptr<uml::Property> prop = std::dynamic_pointer_cast<uml::Property>(eobj);
				if(prop != nullptr) {
					return printProperty(prop);
				}
				std::shared_ptr<uml::TypedElement> utyped = std::dynamic_pointer_cast<uml::TypedElement>(eobj);
				if(utyped != nullptr) {
					return printTypedElement(utyped);
				}
				std::shared_ptr<uml::NamedElement> uname = std::dynamic_pointer_cast<uml::NamedElement>(eobj);
				if(uname != nullptr) {
					return printNamedElement(uname);
				}
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
				handled=true;
				break;
			}
			case ecore::ecorePackage::EOBJECTCONTAINER_CLASS:
			{
				std::shared_ptr<ecore::EObjectContainer> eObjectContainer = value->get<std::shared_ptr<ecore::EObjectContainer>>();
				std::shared_ptr<Bag<ecore::EObject>> eObjectBag =  eObjectContainer->getContainer();
				returnStringStream << "<EObjectContainer> size: " << eObjectBag->size() <<std::endl;
				for(const std::shared_ptr<ecore::EObject> object: *eObjectBag)
				{	// recursive Call of convertToString via new Any EObject Value
					returnStringStream << "\t"<<print(eAny(object,ecore::ecorePackage::EOBJECT_CLASS,false))<<std::endl;
				}
				handled=true;
				break;
			}
			case ecore::ecorePackage::ECLASS_CLASS:
			case ecore::ecorePackage::EOBJECTANY_CLASS:
			case ecore::ecorePackage::EATTRIBUTE_CLASS:
			case ecore::ecorePackage::EREFERENCE_CLASS:
			case ecore::ecorePackage::ESTRUCTURALFEATURE_CLASS:
			case ecore::ecorePackage::EOPERATION_CLASS:
			case ecore::ecorePackage::EBOOLEANOBJECT_CLASS:
			case ecore::ecorePackage::EBOOLEAN_CLASS:
			case ecore::ecorePackage::EBYTE_CLASS:
			case ecore::ecorePackage::EBYTEARRAY_CLASS:
			case ecore::ecorePackage::EBYTEOBJECT_CLASS:
			case ecore::ecorePackage::ECHARACTEROBJECT_CLASS:
			case ecore::ecorePackage::ECHAR_CLASS:
			case ecore::ecorePackage::EDATE_CLASS:
			case ecore::ecorePackage::ERESOURCE_CLASS:
			case ecore::ecorePackage::EINTEGEROBJECT_CLASS:
			case ecore::ecorePackage::EBIGINTEGER_CLASS:
			case ecore::ecorePackage::ESHORT_CLASS:
			case ecore::ecorePackage::ESHORTOBJECT_CLASS:
			case ecore::ecorePackage::EINT_CLASS:
			case ecore::ecorePackage::ELONGOBJECT_CLASS:
			case ecore::ecorePackage::ELONG_CLASS:
			case ecore::ecorePackage::EFLOATOBJECT_CLASS:
			case ecore::ecorePackage::EFLOAT_CLASS:
			case ecore::ecorePackage::EBIGDECIMAL_CLASS:
			case ecore::ecorePackage::EDOUBLE_CLASS:
			case ecore::ecorePackage::ESTRING_CLASS:
			case ecore::ecorePackage::EJAVAOBJECT_CLASS:
			case ecore::ecorePackage::EENUMERATOR_CLASS:
			case ecore::ecorePackage::EDIAGNOSTICCHAIN_CLASS:
			case ecore::ecorePackage::ANY_CLASS:
			{
				returnStringStream << ecore::ecoreFactory::eInstance()->convertToString(nullptr, value);
				handled=true;
				break;
			}
			// Model types are not supported right now --> manual handling
			case BookStore_uml::BookStore_umlPackage::BOOK_CLASS:
			{
				std::shared_ptr<BookStore_uml::Book> book= nullptr;
				try
				{
					book= value->get<std::shared_ptr<BookStore_uml::Book>>();
				}
				catch(...)
				{
					std::shared_ptr<ecore::EObject> object= value->get<std::shared_ptr<ecore::EObject>>();
					book= std::dynamic_pointer_cast<BookStore_uml::Book>(object);
				}
				if(nullptr !=book)
				{
					returnStringStream << book->getTitle() << ": "  << (book->isAvailable() ? "available" : "not available" ) << ": Num copies: " << book->getCopies() << ": category: " << (int)(book->getCategory()) << std::endl;
					handled=true;
				}
		        break;
			}
			case BookStore_uml::BookStore_umlPackage::MEMBER_CLASS:
			{
		        std::shared_ptr<BookStore_uml::Member> member=nullptr;
		        try
		        {
		        	member = value->get<std::shared_ptr<BookStore_uml::Member>>();
		        }
				catch(...)
				{
					std::shared_ptr<ecore::EObject> object= value->get<std::shared_ptr<ecore::EObject>>();
					member= std::dynamic_pointer_cast<BookStore_uml::Member>(object);
				}
				if(nullptr !=member)
				{
					returnStringStream <<"Member: "<< member->getName() << std::endl;
					handled=true;
				}
		        break;
			}
			case BookStore_uml::BookStore_umlPackage::LOAN_CLASS:
			{
		        std::shared_ptr<BookStore_uml::Loan> loan = nullptr;
		        try
		        {
		        	loan = value->get<std::shared_ptr<BookStore_uml::Loan>>();
		        }
				catch(...)
				{
					std::shared_ptr<ecore::EObject> object= value->get<std::shared_ptr<ecore::EObject>>();
					loan= std::dynamic_pointer_cast<BookStore_uml::Loan>(object);
				}
				if(nullptr !=loan)
				{
					returnStringStream <<"a Loan"<< std::endl;
					handled=true;
				}
		        break;
			}
		}

    } catch (...) { }
    if(!handled)
    {
		try {
		    std::shared_ptr<ecore::EObject> eobj = value->get<std::shared_ptr<ecore::EObject>>();

			std::shared_ptr<uml::Operation> uope = std::dynamic_pointer_cast<uml::Operation>(eobj);
			if(uope != nullptr) {
				return printOperation(uope);
			}
			std::shared_ptr<uml::Property> prop = std::dynamic_pointer_cast<uml::Property>(eobj);
			if(prop != nullptr) {
				return printProperty(prop);
			}
			std::shared_ptr<uml::TypedElement> utyped = std::dynamic_pointer_cast<uml::TypedElement>(eobj);
			if(utyped != nullptr) {
				return printTypedElement(utyped);
			}
			std::shared_ptr<uml::NamedElement> uname = std::dynamic_pointer_cast<uml::NamedElement>(eobj);
			if(uname != nullptr) {
				return printNamedElement(uname);
			}
		} catch (...) { }
		try {
			std::shared_ptr<uml::EnumerationLiteral> liter = value->get<std::shared_ptr<uml::EnumerationLiteral>>();
			std::cout << liter->getName() << std::endl;
			return returnStringStream.str();
		} catch (...) { }
		try {
			std::shared_ptr<ecore::EEnumLiteral> liter = value->get<std::shared_ptr<ecore::EEnumLiteral>>();
			returnStringStream << liter->getName() << std::endl;
			return returnStringStream.str();
		} catch (...) { }

		try {
			bool result = value->get<bool>();
			returnStringStream << result << std::endl;
			return returnStringStream.str();
		} catch (...) { }
		try {
			std::string result = value->get<std::string>();
			returnStringStream << result << std::endl;
			return returnStringStream.str();
		} catch (...) { }
		try {
			int result = value->get<int>();
			returnStringStream << result << std::endl;
			return returnStringStream.str();
		} catch (...) { }
		try {
			double result = value->get<double>();
			returnStringStream << result << std::endl;
			return returnStringStream.str();
		} catch (...) { }
		returnStringStream << "Any (typeId: " << value->getTypeId() <<")";
    }
	return returnStringStream.str();
}

std::string print(Any value, bool isMany) {
	std::ostringstream returnStringStream;
    if(value != nullptr && !value->isEmpty()) {
        if(isMany) {
            std::shared_ptr<Bag<AnyObject>> valueItems = value->get<std::shared_ptr<Bag<AnyObject>>>();
            for(size_t i = 0; i < valueItems->size(); i++) {
            	returnStringStream << print(valueItems->at(i));
            }
        }
        else {
        	returnStringStream << print(value);
        }
    }
	return returnStringStream.str();
}

void pause() {
	std::cout << "Enter to continue...";
	std::cin.get();
}

/*
Actual OCL functions
*/
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
    std::cout << print(value, true) << std::endl;
    std::cout << "END Query_Any_1 -------------------------------------------\n" << std::endl;
}
void uml_any_query2() {
    std::string qry = "self.feature";
    std::shared_ptr<uml::Class> context = BookStore_uml::BookStore_umlPackage::eInstance()->get_BookStore_uml_Library();
    Any value = queryValue(context, qry);

    std::cout << "START Query_Any_2 (context[Class] = Library): " << qry << std::endl;
    std::cout << print(value, true) << std::endl;
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
    std::cout<< print(value) << std::endl;
    std::cout << "END Query_Any_4 -------------------------------------------\n" << std::endl;
}
void uml_any_query5() {
    std::string qry = "self";
    std::shared_ptr<uml::Operation> context =  BookStore_uml::BookStore_umlPackage::eInstance()->get_BookStore_uml_Library_addBook_Book_Book();
    Any value = queryValue(context, qry);

    std::cout << "START Query_Any_5 (context[EOperation] = Book::addBook): " << qry << std::endl;
    std::cout<< print(value) << std::endl;
    std::cout << "END Query_Any_5 -------------------------------------------\n" << std::endl;
}
void uml_any_query6() {
    std::string qry = "self.ownedElement";
    std::shared_ptr<uml::Classifier> context = BookStore_uml::BookStore_umlPackage::eInstance()->get_BookStore_uml_BookCategory();
    Any value = queryValue(context, qry);

    std::cout << "START Query_Any_6 (context[Enumeration] = BookCategory): " << qry << std::endl;
    std::cout<< print(value, true) << std::endl;
    std::cout << "END Query_Any_6 -------------------------------------------\n" << std::endl;
}

void uml_any_query7() {
    std::string qry = "Set{20, 1 .. 10}";
    std::shared_ptr<uml::Classifier> context = BookStore_uml::BookStore_umlPackage::eInstance()->get_BookStore_uml_BookCategory();
    Any value = queryValue(context, qry);

    std::cout << "START Query_Any_7 : " << qry << std::endl;
    std::cout<< print(value, true) << std::endl;
    std::cout << "END Query_Any_7 -------------------------------------------\n" << std::endl;
}

void uml_any_query8() {
    std::string qry = "Set{1, 2 .. 10}->iterate(i:Integer;sum:Integer=0 | sum + i)";
    std::shared_ptr<uml::Classifier> context = BookStore_uml::BookStore_umlPackage::eInstance()->get_BookStore_uml_BookCategory();
    Any value = queryValue(context, qry);

    std::cout << "START Query_Any_8 : " << qry << std::endl;
    std::cout<< print(value) << std::endl;
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
    std::string qry = "context Book::countCopies() : Integer \n"
                      "body: self.copies \n";
    std::shared_ptr<BookStore_uml::Book> context = BookStore_uml::BookStore_umlFactory::eInstance()->createBook();
    context->setCopies(5);
    std::cout << "START Validate_6(copies = 5) : " << qry << std::endl;
    validate(context, qry);
    std::cout << "END Validate_6 -------------------------------------------\n" << std::endl;
}

void validate7() {
    std::string qry = "\npackage BookStore_uml \n"
                      "context Book::addCopies(nbCopies:Integer=2): \n"
                      "pre: nbCopies > 0 \n"
                      "endpackage \n";
    std::shared_ptr<BookStore_uml::Book> context = BookStore_uml::BookStore_umlFactory::eInstance()->createBook();
    std::cout << "START Validate_7(addCopies(2)) : " << qry << std::endl;
    validate(context, qry);
    std::cout << "END Validate_7 -------------------------------------------\n" << std::endl;
}

void validate8() {
    std::string qry = "\npackage BookStore_uml \n"
                      "context Book::addCopies(nbCopies:Integer=2): \n"
                      "post: self.copies = 2 \n"
                      "endpackage \n";
    std::shared_ptr<BookStore_uml::Book> context = BookStore_uml::BookStore_umlFactory::eInstance()->createBook();
    std::cout << "START Validate_8(addCopies(2)) : " << qry << std::endl;
    validate(context, qry);
    std::cout << "END Validate_8 -------------------------------------------\n" << std::endl;
}

void validate9() {
    std::string qry = "\npackage BookStore_uml \n"
                      "context Library::open(): \n"
                      "pre: self.opened = false \n"
                      "endpackage \n";
    std::shared_ptr<BookStore_uml::Library> context = BookStore_uml::BookStore_umlFactory::eInstance()->createLibrary();
    context->setOpened(false);
    std::cout << "START Validate_9(open()) : " << qry << std::endl;
    validate(context, qry);
    std::cout << "END Validate_9 -------------------------------------------\n" << std::endl;
}

void validate10() {
    std::string qry = "context Library::open(): \n"
                      "post: self.opened = true";
    std::shared_ptr<BookStore_uml::Library> context = BookStore_uml::BookStore_umlFactory::eInstance()->createLibrary();
    context->setOpened(false);
    std::cout << "START Validate_10(open()) : " << qry << std::endl;
    validate(context, qry);
    std::cout << "END Validate_10 -------------------------------------------\n" << std::endl;
}

void validate11() {
    std::string qry = "\npackage BookStore_uml \n"
                      "context Book::addCopies(nbCopies:Integer=2): \n"
                      "post: copies = copies@pre + nbCopies \n"
                      "endpackage \n";
    std::shared_ptr<BookStore_uml::Book> context = BookStore_uml::BookStore_umlFactory::eInstance()->createBook();
    std::cout << "START Validate_11(addCopies(2)) : " << qry << std::endl;
    validate(context, qry);
    std::cout << "END Validate_11 -------------------------------------------\n" << std::endl;
}
// End of user code

int main ()
{
	//Create Model Factory and Package
	std::shared_ptr<BookStore_umlFactory> factory = BookStore_umlFactory::eInstance();
	std::shared_ptr<BookStore_umlPackage> package = BookStore_umlPackage::eInstance();

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
