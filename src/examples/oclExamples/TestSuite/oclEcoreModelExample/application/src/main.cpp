
#include <iostream>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "Library_ecore/Library_ecoreFactory.hpp"
#include "Library_ecore/Library_ecorePackage.hpp"

#include "Library_ecore/Library.hpp"
#include "Library_ecore/Member.hpp"
#include "Library_ecore/Book.hpp"
#include "Library_ecore/Loan.hpp"
#include "Library_ecore/Writer.hpp"
#include "Library_ecore/BookCategory.hpp"

#include <string>
#include <sstream>
// //#include <oclParser/Utilities/Ocl.h>

#include <ecore/EFactory.hpp>
#include <ecore/EPackage.hpp>
#include <ecore/ecorePackage.hpp>
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
#include <ecore/EcoreAny.hpp>
#include <ecore/EcoreContainerAny.hpp>

#include <oclParser/Utilities/test_query.h>

using namespace Library_ecore;

std::shared_ptr<Library_ecore::Library> createBookStore()
{
	std::shared_ptr<Library_ecore::Library_ecoreFactory> factory = Library_ecore::Library_ecoreFactory::eInstance();
    std::shared_ptr<Library_ecore::Library> lib = factory ->createLibrary();
    lib->setName("TU Ilmenau - University Library");
    std::shared_ptr<Library_ecore::Book> bookMag = factory->createBook_as_books_in_Library(lib);

    bookMag->setTitle("Magritte");

    std::shared_ptr<Library_ecore::Book> bookPe = factory->createBook_as_books_in_Library(lib);
    bookPe->setTitle("Perry");

    std::shared_ptr<Library_ecore::Book> bookRo = factory->createBook_as_books_in_Library(lib);
    bookRo->setTitle("Robin");

    std::shared_ptr<Library_ecore::Book> bookAl = factory->createBook_as_books_in_Library(lib);
    bookAl->setTitle("Alena");

    std::shared_ptr<Library_ecore::Book> bookLe = factory->createBook_as_books_in_Library(lib);
    bookLe->setTitle("Leonie");

    std::shared_ptr<Library_ecore::Book> bookUd = factory->createBook_as_books_in_Library(lib);
    bookUd->setTitle("Udo");

    std::shared_ptr<Writer> author = factory->createWriter_as_writers_in_Library(lib);
    author->setName("David Sylvester");
    bookMag->getWriters()->add(author);

    std::shared_ptr<Member> paul=factory->createMember_as_members_in_Library(lib);
	paul->setName("Paul");

    std::shared_ptr<Loan> loan=factory->createLoan_as_loans_in_Library(lib);
    loan->setMember(paul);
    loan->setBook(bookMag);
    bookMag->setAvailable(false);
	return lib;
}

//looks for the given (property) name in the given (EClass) context
//returns nullptr if property with name is not found
std::shared_ptr<Any> lookupPropertyName(const std::string& name, std::shared_ptr<Any> context) {

    //try as ecoreAny
    std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(context);

    if (ecoreAny == nullptr) {
        //TODO add error
        //context have to be an ecoreAny
        return nullptr;
    }

    //get eObject to get eClass
    std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();

    if (eObject == nullptr) {
        //TODO add error can't get eObject out of ecoreAny
        return nullptr;
    }
    
    //try to get eClass
    std::shared_ptr<ecore::EClass> eClass = eObject->eClass();

    if (eClass == nullptr) {
        //TODO add error
        //eObject have no class
        return nullptr;
    }

    //find property with given name
    size_t size = eClass->getEAllStructuralFeatures()->size();

    std::shared_ptr<ecore::EStructuralFeature> foundFeat;

    for (size_t i = 0; i < size; i++) {
        const std::shared_ptr<ecore::EStructuralFeature>& elem = eClass->getEAllStructuralFeatures()->at(i);
        if (name == elem->getName()) {
            foundFeat = elem;
            break;
        }
    }

    //check if found
    if (foundFeat == nullptr) {
        //TODO property name 'name' in eClass.getName() not found
        return nullptr;
    }

    //get actual object
    const std::shared_ptr<Any>& returnObject = eObject->eGet(foundFeat);

    return returnObject;
}

int main() {

    std::shared_ptr<Library_ecore::Library> store = createBookStore();

    std::shared_ptr<ecore::EObject> objLib = store;

    //std::shared_ptr<ecore::EPackage> contextAsPackage = std::dynamic_pointer_cast<ecore::EPackage>(objLib);
    std::shared_ptr<ecore::EClass> eClass = objLib->eClass();
    std::shared_ptr<ecore::EClassifier> contextAsClass = std::dynamic_pointer_cast<ecore::EClassifier>(eClass);
    std::shared_ptr<Bag<ecore::EStructuralFeature>> structTest = eClass->getEAllStructuralFeatures();
    //std::shared_ptr<Any> returnTest = objLib->eGet();
    // std::cout << "EClassifier: " << contextAsClass->getName() << std::endl;
    // std::cout << "EStructuralFeatures: " << structTest->size() << std::endl;

    std::shared_ptr<ecore::EStructuralFeature> bookFeature;

    std::string name = "books";

    for(size_t i = 0; i < structTest->size(); i++) {

        std::shared_ptr<ecore::EStructuralFeature> elem = structTest->at(i);
        if (elem->getName() == name) {

            bookFeature = elem;
        }
    }

    // std::shared_ptr<Any> returnTest = objLib->eGet(bookFeature);
    // std::cout << "returnTest ID: " << (returnTest->getTypeId()) << std::endl;
    // std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(returnTest);
    // std::cout << "ecoreAny: " << (ecoreAny!=nullptr) << std::endl; // is null
    // // ist ein EContainerAny()
    // std::shared_ptr<ecore::EcoreContainerAny> ecoreConAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(returnTest);
    // std::cout << "ecoreContainerAny: " << (ecoreConAny!=nullptr) << std::endl; // is null
    // //std::shared_ptr<ecore::EStructuralFeature> returnFeature = returnTest->get<std::shared_ptr<>();
    // //std::shared_ptr<Any> test = eEcoreAny<>("test",ecore::ecorePackage::ESTRING_CLASS);

    // std::cout << "----------------------------------------------------------------------" << std::endl;
    
    // Utilities::ts ts;

    std::shared_ptr<Any> anyLib = eEcoreAny<std::shared_ptr<ecore::EObject>>(objLib, objLib->getMetaElementID());
    // std::shared_ptr<Any> result = ts.contextTest("not self.opened", anyLib);
    // std::cout << "Query result is present: " << (result!=nullptr) << std::endl;
    // bool boolTest = result->get<bool>();
    // std::cout << "Query result as bool: " << boolTest << std::endl;
    
    std::cout << "----------------------------------------------------------------------" << std::endl;
    
    Utilities::ts ts2;
    std::shared_ptr<Any> result2 = ts2.contextTest("self.books->iterate(elem; acc: Bag(Book) = Bag{} | acc->including(elem))", anyLib);
    // also support type check of elem
    //std::shared_ptr<Any> result2 = ts2.contextTest("self.books->iterate(elem : Book; acc: Bag(Book) = Bag{} | acc->including(elem))", anyLib);

    std::shared_ptr<Bag<Any>> resultBag = result2->get<std::shared_ptr<Bag<Any>>>();

    std::cout << "resultBag len: " << resultBag->size() << std::endl;
    std::cout << "Done" << std::endl; 

    //read out result bag
    
    std::shared_ptr<Any> bagElement;
    std::shared_ptr<ecore::EcoreAny> resultEcoreAny;
    std::shared_ptr<ecore::EObject> eObject;

    for (size_t i = 0; i < resultBag->size(); i++) {
        
        bagElement = resultBag->at(i);
        resultEcoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(bagElement);
        eObject = resultEcoreAny->getAsEObject();

        if (eObject!=nullptr){

            std::shared_ptr<ecore::EClass> eResultClass = eObject->eClass();
            std::shared_ptr<Bag<ecore::EStructuralFeature>> resultTest = eResultClass->getEAllStructuralFeatures();
            std::string resultName = "title";
            std::shared_ptr<ecore::EStructuralFeature> resultFeature;

            for(size_t i = 0; i < resultTest->size(); i++) {

                std::shared_ptr<ecore::EStructuralFeature> elem = resultTest->at(i);
                if (elem->getName() == resultName) {

                    resultFeature = elem;
                }
            }

            if (resultFeature != nullptr) {

                std::shared_ptr<Any> resultAny = eObject->eGet(resultFeature);
                std::string resultStr = resultAny->get<std::string>();
                std::cout << resultStr << std::endl;
            }
        }   
    }

    std::cout << "----------------------------------------------------------------------" << std::endl;

    Utilities::ts ts3;
    //std::shared_ptr<Any> result3 = ts3.contextTest("self.books->select(elem: Book | elem.title='Perry')", anyLib);
    std::shared_ptr<Any> result3 = ts3.contextTest("self.books->select(title<>'Magritte')", anyLib);
    //std::shared_ptr<Any> result3 = ts3.contextTest("self.books->reject(title<>'Magritte')", anyLib);
    //std::shared_ptr<Any> result3 = ts3.contextTest("self.books->reject(elem: Book | elem.title='Perry')", anyLib);

    //read out result bag
    
    resultBag = result3->get<std::shared_ptr<Bag<Any>>>();

    std::cout << "resultBag len: " << resultBag->size() << std::endl;
    std::cout << "Done" << std::endl; 

    for (size_t i = 0; i < resultBag->size(); i++) {

        bagElement = resultBag->at(i);
        resultEcoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(bagElement);
        eObject = resultEcoreAny->getAsEObject();

        if (eObject!=nullptr){

            std::shared_ptr<ecore::EClass> eResultClass = eObject->eClass();
            std::shared_ptr<Bag<ecore::EStructuralFeature>> resultTest = eResultClass->getEAllStructuralFeatures();
            std::string resultName = "title";
            std::shared_ptr<ecore::EStructuralFeature> resultFeature;

            for(size_t i = 0; i < resultTest->size(); i++) {

                std::shared_ptr<ecore::EStructuralFeature> elem = resultTest->at(i);
                if (elem->getName() == resultName) {

                    resultFeature = elem;
                }
            }

            if (resultFeature != nullptr) {

                std::shared_ptr<Any> resultAny = eObject->eGet(resultFeature);
                std::string resultStr = resultAny->get<std::string>();
                std::cout << resultStr << std::endl;
            }
        }   
    }

    std::cout << "----------------------------------------------------------------------" << std::endl;

    Utilities::ts ts4;
    std::shared_ptr<Any> result4 = ts4.contextTest("self.close()", anyLib);


    //read out result bag
    
    std::string openendName = "opened";
    std::shared_ptr<ecore::EStructuralFeature> openedFeature = nullptr;

    for(size_t i = 0; i < structTest->size(); i++) {

        std::shared_ptr<ecore::EStructuralFeature> elem = structTest->at(i);
        if (elem->getName() == openendName) {

            openedFeature = elem;
        }
    }

    std::shared_ptr<Any> openendTest = objLib->eGet(openedFeature);

    if (openendTest->getTypeId() == ecore::ecorePackage::EBOOLEAN_CLASS) {

        bool openStatus = openendTest->get<bool>();

        std::cout << "Library is: " << openStatus << std::endl;

    }

    std::cout << "----------------------------------------------------------------------" << std::endl;

    Utilities::ts ts5;
    std::shared_ptr<Any> result5 = ts5.contextTest("if self.opened then 'offen' else 'geschlossen' endif", anyLib);

    std::string answer = result5->get<std::string>();

    std::cout << "Library is per OCL: " << answer << std::endl;

    result4 = ts4.contextTest("self.open()", anyLib);

    result5 = ts5.contextTest("if self.opened then 'offen' else 'geschlossen' endif", anyLib);

    answer = result5->get<std::string>();

    std::cout << "Library is per OCL: " << answer << std::endl;

    std::shared_ptr<Library_ecore::Library_ecoreFactory> factory = Library_ecore::Library_ecoreFactory::eInstance();

    std::cout << "----------------------------------------------------------------------" << std::endl;

    Utilities::ts ts6;
    //std::shared_ptr<Any> result6 = ts6.contextTest("self.writers[0].name", anyLib);
    //std::shared_ptr<Any> result6 = ts6.contextTest("self.writers[].name", anyLib); // correctly nullptr '[]' on an collection without index always returns the Collection
    std::shared_ptr<Any> result6 = ts6.contextTest("self.books[0, 3, 1, 5, 2, 5]", anyLib);
    //std::shared_ptr<Any> result6 = ts6.contextTest("self.books[2]", anyLib);

    if (result6 != nullptr) {

        if (result6->getTypeId() == Library_ecore::Library_ecorePackage::BOOK_CLASS) {

            std::shared_ptr<Any> titleAny = lookupPropertyName("title", result6);
            std::string title = titleAny->get<std::string>();

            std::cout << title << std::endl;
        } else if (result6->isContainer()){

            std::shared_ptr<Bag<Any>> resultBag = result6->get<std::shared_ptr<Bag<Any>>>();

            for (size_t i = 0; i < resultBag->size(); i++)
            {
                std::shared_ptr<Any> titleAny = lookupPropertyName("title", resultBag->at(i));
                std::string title = titleAny->get<std::string>();
                std::cout << title << std::endl;
            }
        } else if (result6->getTypeId() == ecore::ecorePackage::ESTRING_CLASS) {

            std::string strResult = result6->get<std::string>();
            std::cout << "Str Result name: " << strResult << std::endl;
        }

    }

    
    return 0;

}

// // Start of user code includes 
// // You may manually edit additional includes, won't be overwritten upon generation.

// // End of user code

// // Start of user code functions 
// // You may manually edit additional functions, won't be overwritten upon generation.
// /*
// Helper functions
// */
// bool validate(const std::string& query, std::shared_ptr<ecore::EObject> context, const std::string& testStr) {
// 	bool returnValue = false;
//     try {
//         Utilities::Ocl ocl;
//         ocl.validate(query, context);
//         if(ocl.getErrors().size() > 0) {
//             std::cout << ocl.getError() << std::endl;
//         } else {
//         	std::string resultStr=ocl.getResult();
//             std::cout << resultStr << std::endl;
//             (resultStr.compare(testStr) == 0) ? returnValue =  true : returnValue =  false;
//         }
//     } catch (std::exception &e) {
//         std::cout << "exception : " << e.what() << std::endl;
//     }
//     returnValue ? std::cout << "success" << std::endl : std::cout << "fail" << std::endl;
//     return returnValue;
// }

// bool query(const std::string& query,  std::shared_ptr<ecore::EObject> context, const std::string& testStr) {
// 	bool returnValue = false;
// 	try {
//         Utilities::Ocl ocl;
//         if(ocl.query(query, context)) {
//         	std::string resultStr=ocl.getResult();
//             std::cout << resultStr << std::endl;
//             (resultStr.compare(testStr) == 0) ? returnValue =  true : returnValue =  false;
//         } else {
//             std::cout << ocl.getError() << std::endl;
//         }
//     } catch (std::exception &e) {
//         std::cout << "exception : " << e.what() << std::endl;
//     }
//     returnValue ? std::cout << "success" << std::endl : std::cout << "fail" << std::endl;
//     return returnValue;
// }

// Any queryValue(const std::string& query, std::shared_ptr<ecore::EObject> context) {
//     try {
//         Utilities::Ocl ocl;
//         if(ocl.query(query, context)) {
//             return ocl.getResultValue();
//         } else {
//             std::cout << ocl.getError() << std::endl;
//         }
//     } catch (std::exception &e) {
//         std::cout << "exception : " << e.what() << std::endl;
//     }
//     return nullptr;
// }

// std::string printEAttribute(std::shared_ptr<ecore::EAttribute> eattr) {
// 	std::ostringstream returnStringStream;
//     if(eattr != nullptr) {
//         if(eattr->getUpperBound() > 1 || eattr->getUpperBound() < 0)
//         	returnStringStream << "<EAttribute>:" + eattr->getName() + ":" + eattr->getEType()->getName()+ "[" +  std::to_string(eattr->getLowerBound()) + "..*]" << std::endl;
//         else
//         	returnStringStream << "<EAttribute>:" + eattr->getName() + ":" + eattr->getEType()->getName()+ "[" +  std::to_string(eattr->getLowerBound()) + ".." + std::to_string(eattr->getUpperBound()) + "]" << std::endl;
//     }
// 	return returnStringStream.str();
// }

// std::string printEReference(std::shared_ptr<ecore::EReference> eref) {
// 	std::ostringstream returnStringStream;
//     if(eref != nullptr) {
//         if(eref->getUpperBound() > 1 || eref->getUpperBound() < 0)
//         	returnStringStream << "<EReference>:" + eref->getName() + ":" + eref->getEType()->getName()+ "[" +  std::to_string(eref->getLowerBound()) + "..*]" << std::endl;
//         else
//         	returnStringStream << "<EReference>:" + eref->getName() + ":" + eref->getEType()->getName()+ "[" +  std::to_string(eref->getLowerBound()) + ".." + std::to_string(eref->getUpperBound()) + "]" << std::endl;
//     }
// 	return returnStringStream.str();
// }

// std::string  printETypedElement(std::shared_ptr<ecore::ETypedElement> etyped) {
// 	std::ostringstream returnStringStream;
//     if(etyped != nullptr) {
//         if(etyped->isMany())
//         	returnStringStream << etyped->getName() + ":" + etyped->getEType()->getName()+ "[0..*]" << std::endl;
//         else
//         	returnStringStream << etyped->getName() + ":" + etyped->getEType()->getName()+ "[0..1]" << std::endl;
//     }
// 	return returnStringStream.str();
// }

// std::string printENamedElement(std::shared_ptr<ecore::ENamedElement> ename) {
// 	std::ostringstream returnStringStream;
//     if(ename != nullptr) {
//     	returnStringStream << ename->getName() << std::endl;
//     }
// 	return returnStringStream.str();
// }

// std::string printEOperation(std::shared_ptr<ecore::EOperation> eope) {
// 	std::string result="";
//     if(eope != nullptr) {
//         result = "<Operation>:" + eope->getName() + "(";
//         std::shared_ptr<Bag<ecore::EParameter>> ebag = std::dynamic_pointer_cast<Bag<ecore::EParameter>>(eope->getEParameters());
//         for(unsigned int i = 0; i < ebag->size(); i++) {
//             if(i > 0) result += ", ";
//             result += ebag->at(i)->getName() + ":";
//             if(ebag->at(i)->getEType() != nullptr)
//                 result += ebag->at(i)->getEType()->getName();
//             else
//                 result += "[Not set in Model]";
//         }
//         result += ")";
//         if(eope->getEType() != nullptr && eope->getEType()->getName() != "invalid")
//             result += ":" + eope->getEType()->getName();
//     }
// 	return result;
// }

// std::string print(Any value) {
// 	std::ostringstream returnStringStream;
// 	bool handled=false;
//     try{
//     	switch(value->getTypeId())
//     	{
// 			case ecore::ecorePackage::EOBJECT_CLASS: // unknown or primitive type
// 			{
// 				std::shared_ptr<ecore::EObject> eobj = value->get<std::shared_ptr<ecore::EObject>>();
// 				std::shared_ptr<ecore::EOperation> eope = std::dynamic_pointer_cast<ecore::EOperation>(eobj);
// 				if(eope != nullptr) {
// 					return printEOperation(eope);
// 				}
// 				std::shared_ptr<ecore::EAttribute> eattr = std::dynamic_pointer_cast<ecore::EAttribute>(eobj);
// 				if(eattr != nullptr) {
// 					return printEAttribute(eattr);
// 				}
// 				std::shared_ptr<ecore::EReference> eref = std::dynamic_pointer_cast<ecore::EReference>(eobj);
// 				if(eref != nullptr) {
// 					return printEReference(eref);
// 				}
// 				std::shared_ptr<ecore::ETypedElement> etyped = std::dynamic_pointer_cast<ecore::ETypedElement>(eobj);
// 				if(etyped != nullptr) {
// 					return printETypedElement(etyped);
// 				}
// 				std::shared_ptr<ecore::ENamedElement> ename = std::dynamic_pointer_cast<ecore::ENamedElement>(eobj);
// 				if(ename != nullptr) {
// 					return printENamedElement(ename);
// 				}
// 				handled=true;
// 				break;
// 			}
// 			case ecore::ecorePackage::EOBJECTCONTAINER_CLASS:
// 			{
// 				std::shared_ptr<ecore::EObjectContainer> eObjectContainer = value->get<std::shared_ptr<ecore::EObjectContainer>>();
// 				std::shared_ptr<Bag<ecore::EObject>> eObjectBag =  eObjectContainer->getContainer();
// 				returnStringStream << "<EObjectContainer> size: " << eObjectBag->size() <<std::endl;
// 				for(const std::shared_ptr<ecore::EObject> object: *eObjectBag)
// 				{	// recursive Call of convertToString via new Any EObject Value
// 					returnStringStream << "\t"<<print(eAny(object,ecore::ecorePackage::EOBJECT_CLASS,false))<<std::endl;
// 				}
// 				handled=true;
// 				break;
// 			}
// 			case ecore::ecorePackage::ECLASS_CLASS:
// 			case ecore::ecorePackage::EOBJECTANY_CLASS:
// 			case ecore::ecorePackage::EATTRIBUTE_CLASS:
// 			case ecore::ecorePackage::EREFERENCE_CLASS:
// 			case ecore::ecorePackage::ESTRUCTURALFEATURE_CLASS:
// 			case ecore::ecorePackage::EOPERATION_CLASS:
// 			case ecore::ecorePackage::EBOOLEANOBJECT_CLASS:
// 			case ecore::ecorePackage::EBOOLEAN_CLASS:
// 			case ecore::ecorePackage::EBYTE_CLASS:
// 			case ecore::ecorePackage::EBYTEARRAY_CLASS:
// 			case ecore::ecorePackage::EBYTEOBJECT_CLASS:
// 			case ecore::ecorePackage::ECHARACTEROBJECT_CLASS:
// 			case ecore::ecorePackage::ECHAR_CLASS:
// 			case ecore::ecorePackage::EDATE_CLASS:
// 			case ecore::ecorePackage::ERESOURCE_CLASS:
// 			case ecore::ecorePackage::EINTEGEROBJECT_CLASS:
// 			case ecore::ecorePackage::EBIGINTEGER_CLASS:
// 			case ecore::ecorePackage::ESHORT_CLASS:
// 			case ecore::ecorePackage::ESHORTOBJECT_CLASS:
// 			case ecore::ecorePackage::EINT_CLASS:
// 			case ecore::ecorePackage::ELONGOBJECT_CLASS:
// 			case ecore::ecorePackage::ELONG_CLASS:
// 			case ecore::ecorePackage::EFLOATOBJECT_CLASS:
// 			case ecore::ecorePackage::EFLOAT_CLASS:
// 			case ecore::ecorePackage::EBIGDECIMAL_CLASS:
// 			case ecore::ecorePackage::EDOUBLE_CLASS:
// 			case ecore::ecorePackage::ESTRING_CLASS:
// 			case ecore::ecorePackage::EJAVAOBJECT_CLASS:
// 			case ecore::ecorePackage::EENUMERATOR_CLASS:
// 			case ecore::ecorePackage::EDIAGNOSTICCHAIN_CLASS:
// 			case ecore::ecorePackage::ANY_CLASS:
// 			{
// 				returnStringStream << Library_ecore::Library_ecoreFactory::eInstance()->convertToString(nullptr, value);
// 				handled=true;
// 				break;
// 			}
// 			// Model types are not supported right now --> manual handling
// 			case Library_ecore::Library_ecorePackage::BOOK_CLASS:
// 			{
// 				std::shared_ptr<Library_ecore::Book> book= nullptr;
// 				try
// 				{
// 					book= value->get<std::shared_ptr<Library_ecore::Book>>();
// 				}
// 				catch(...)
// 				{
// 					std::shared_ptr<ecore::EObject> object= value->get<std::shared_ptr<ecore::EObject>>();
// 					book= std::dynamic_pointer_cast<Library_ecore::Book>(object);
// 				}
// 				if(nullptr !=book)
// 				{
// 					returnStringStream << book->getTitle() << ": "  << (book->getAvailable() ? "available" : "not available" ) << ": Num copies: " << book->getCopies() << ": category: " << (int)(book->getCategory()) << std::endl;
// 					handled=true;
// 				}
// 		        break;
// 			}
// 			case Library_ecore::Library_ecorePackage::MEMBER_CLASS:
// 			{
// 		        std::shared_ptr<Library_ecore::Member> member=nullptr;
// 		        try
// 		        {
// 		        	member = value->get<std::shared_ptr<Library_ecore::Member>>();
// 		        }
// 				catch(...)
// 				{
// 					std::shared_ptr<ecore::EObject> object= value->get<std::shared_ptr<ecore::EObject>>();
// 					member= std::dynamic_pointer_cast<Library_ecore::Member>(object);
// 				}
// 				if(nullptr !=member)
// 				{
// 					returnStringStream <<"Member: "<< member->getName() << std::endl;
// 					handled=true;
// 				}
// 		        break;
// 			}
// 			case Library_ecore::Library_ecorePackage::LOAN_CLASS:
// 			{
// 		        std::shared_ptr<Library_ecore::Loan> loan = nullptr;
// 		        try
// 		        {
// 		        	loan = value->get<std::shared_ptr<Library_ecore::Loan>>();
// 		        }
// 				catch(...)
// 				{
// 					std::shared_ptr<ecore::EObject> object= value->get<std::shared_ptr<ecore::EObject>>();
// 					loan= std::dynamic_pointer_cast<Library_ecore::Loan>(object);
// 				}
// 				if(nullptr !=loan)
// 				{
// 					returnStringStream <<"Loan: "<< loan->getDate()<< std::endl;
// 					handled=true;
// 				}
// 		        break;
// 			}
// 		}

//     } catch (...) { }
//     if(!handled)
//     {
// 		try {
// 			std::shared_ptr<ecore::EEnumLiteral> liter = value->get<std::shared_ptr<ecore::EEnumLiteral>>();
// 			returnStringStream << liter->getName() << std::endl;
// 			return returnStringStream.str();
// 		} catch (...) { }

// 		try {
// 			bool result = value->get<bool>();
// 			returnStringStream << result << std::endl;
// 			return returnStringStream.str();
// 		} catch (...) { }
// 		try {
// 			std::string result = value->get<std::string>();
// 			returnStringStream << result << std::endl;
// 			return returnStringStream.str();
// 		} catch (...) { }
// 		try {
// 			int result = value->get<int>();
// 			returnStringStream << result << std::endl;
// 			return returnStringStream.str();
// 		} catch (...) { }
// 		try {
// 			double result = value->get<double>();
// 			returnStringStream << result << std::endl;
// 			return returnStringStream.str();
// 		} catch (...) { }
// 		returnStringStream << "Any (typeId: " << value->getTypeId() <<")";
//     }
// 	return returnStringStream.str();
// }

// std::string  print(Any value, bool isMany) {
// 	std::ostringstream returnStringStream;
//     if(value != nullptr && !value->isEmpty()) {
//         if(isMany) {
//             std::shared_ptr<Bag<AnyObject>> valueItems = value->get<std::shared_ptr<Bag<AnyObject>>>();
//             for(size_t i = 0; i < valueItems->size(); i++) {
//             	returnStringStream << print(valueItems->at(i));
//             }
//         }
//         else {
//         	returnStringStream << print(value);
//         }
//     }
// 	return returnStringStream.str();
// }

// void pause() {
// 	std::cout << "Enter to continue...";
// 	std::cin.get();
// }

// /*
// Actual OCL functions
// */
// bool query1() {
//     std::string qry = "self.name";
//     std::shared_ptr<ecore::EPackage> context = Library_ecore::Library_ecorePackage::eInstance();

//     std::cout << "START Query_1 (context[EPackage] = LibraryPackage): " << qry << std::endl;
//     bool returnValue=query(qry, context, "Library_ecore");
//     std::cout << "END Query_1 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }
// bool query2() {
//     std::string qry = "self.eAttributes";
//     std::shared_ptr<ecore::EClass> context = Library_ecore::Library_ecorePackage::eInstance()->getLibrary_Class();
//     std::cout << "START Query_2 (context[EClass] = Library): " << qry << std::endl;
//     bool returnValue=query(qry, context, "<EAttribute>:name:String[0..1]\n<EAttribute>:nbBooks:Integer[0..1]\n<EAttribute>:opened:EBoolean[0..1]");
//     std::cout << "END Query_2 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }
// bool query3() {
//     std::string qry = "self.name";
//     std::shared_ptr<ecore::EAttribute> context = Library_ecore::Library_ecorePackage::eInstance()->getBook_Attribute_category();
//     std::cout << "START Query_3 (context[EAttribute] = Book::category): " << qry << std::endl;
//     bool returnValue=query(qry,context, "category");
//     std::cout << "END Query_3 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }
// bool query4() {
//     std::string qry = "self";
//     std::shared_ptr<ecore::EReference> context = Library_ecore::Library_ecorePackage::eInstance()->getLibrary_Attribute_books();
//     std::cout << "START Query_4 (context[EReference] = Book::books): " << qry << std::endl;
//     bool returnValue=query(qry,context, "<EReference>:books:Book[0..*]");
//     std::cout << "END Query_4 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }
// bool query5() {
//     std::string qry = "self";
//     std::shared_ptr<ecore::EOperation> context = Library_ecore::Library_ecorePackage::eInstance()->getLibrary_Operation_addBook_Book();
//     std::cout << "START Query_5 (context[EOperation] = Book::addBook): " << qry << std::endl;
//     bool returnValue=query(qry,context, "addBook(b:Book)");
//     std::cout << "END Query_5 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }
// bool ecore_any_query1() {
// 	bool returnValue=false;
//     std::string qry = "self.name";
//     std::shared_ptr<ecore::EPackage> context = Library_ecore::Library_ecorePackage::eInstance();
//     Any value = queryValue(qry,context);

//     std::cout << "START Query_Any_1 (context[EPackage] = LibraryPackage): " << qry << std::endl;
//     if(value != nullptr) {
//     	std::string resultStr=value->get<std::string>() ;
//         std::cout << resultStr << std::endl;
//         (resultStr.compare("Library_ecore") == 0) ? returnValue =  true : returnValue =  false;
//     }
//     returnValue ? std::cout << "success" << std::endl : std::cout << "fail" << std::endl;
//     std::cout << "END Query_Any_1 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }
// bool ecore_any_query2() {
// 	bool returnValue=false;
// 	std::string qry = "self.eAttributes";
//     std::shared_ptr<ecore::EClass> context = Library_ecore::Library_ecorePackage::eInstance()->getLibrary_Class();
//     Any value = queryValue(qry, context);

//     std::cout << "START Query_Any_2 (context[EClass] = Library): " << qry << std::endl;
//     std::string resultStr="";
//     if(value != nullptr) {
//         try {
//             std::shared_ptr<Bag<AnyObject>> valueItems = value->get<std::shared_ptr<Bag<AnyObject>>>();
//             for(size_t i = 0; i < valueItems->size(); i++) {
//                 std::shared_ptr<ecore::EObject> eobj = valueItems->at(i)->get<std::shared_ptr<ecore::EObject>>();
//                 std::shared_ptr<ecore::EAttribute> eattr = std::dynamic_pointer_cast<ecore::EAttribute>(eobj);
//                 std::string attrStr = printEAttribute(eattr);
//                 std::cout << attrStr;
//                 resultStr +=attrStr;
//             }
//         } catch(...) {
//             std::cout << "Error : get failed" << std::endl;
//         }
//     }
//     (resultStr.compare("<EAttribute>:name:String[0..1]\n<EAttribute>:nbBooks:Integer[0..1]\n<EAttribute>:opened:EBoolean[0..1]\n") == 0) ? returnValue =  true : returnValue =  false;
//     returnValue ? std::cout << "success" << std::endl : std::cout << "fail" << std::endl;

//     std::cout << "END Query_Any_2 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }
// bool ecore_any_query3() {
// 	bool returnValue=false;
// 	std::string qry = "self.name";
//     std::shared_ptr<ecore::EAttribute> context = Library_ecore::Library_ecorePackage::eInstance()->getBook_Attribute_category();
//     Any value = queryValue(qry,context);

//     std::cout << "START Query_Any_3 (context[EAttribute] = Book::category): " << qry << std::endl;
//     if(value != nullptr) {
//     	std::string resultStr=value->get<std::string>() ;
//         std::cout << resultStr << std::endl;
//         (resultStr.compare("category") == 0) ? returnValue =  true : returnValue =  false;
//     }
//     returnValue ? std::cout << "success" << std::endl : std::cout << "fail" << std::endl;
//     std::cout << "END Query_Any_3 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }
// bool ecore_any_query4() {
// 	bool returnValue=false;
// 	std::string qry = "self";
//     std::shared_ptr<ecore::EReference> context = Library_ecore::Library_ecorePackage::eInstance()->getLibrary_Attribute_books();
//     Any value = queryValue(qry,context);

//     std::cout << "START Query_4 (context[EReference] = Book::books): " << qry << std::endl;
//     std::string resultStr="";
//     if(value != nullptr) {
//         std::shared_ptr<ecore::EReference> eref = std::dynamic_pointer_cast<ecore::EReference>
//                 (value->get<std::shared_ptr<ecore::EObject>>());
//         std::string attrStr = printEReference(eref);
//         std::cout << attrStr;
//         resultStr +=attrStr;
//     }
// 	(resultStr.compare("<EReference>:books:Book[0..*]\n") == 0) ? returnValue =  true : returnValue =  false;
// 	returnValue ? std::cout << "success" << std::endl : std::cout << "fail" << std::endl;
// 	std::cout << "END Query_Any__4 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }
// bool ecore_any_query5() {
// 	bool returnValue=false;
// 	std::string qry = "self";
//     std::shared_ptr<ecore::EOperation> context = Library_ecore::Library_ecorePackage::eInstance()->getLibrary_Operation_addBook_Book();
//     Any value = queryValue(qry,context);

//     std::cout << "START Query_5 (context[EOperation] = Book::addBook): " << qry << std::endl;
//     std::string resultStr="";

//     if(value != nullptr) {
//         std::shared_ptr<ecore::EOperation> eope = std::dynamic_pointer_cast<ecore::EOperation>
//                 (value->get<std::shared_ptr<ecore::EObject>>());
//         std::string attrStr = printEOperation(eope);
//         std::cout << attrStr;
//         resultStr +=attrStr;

//     }
// 	(resultStr.compare("<Operation>:addBook(b:Book):Boolean") == 0) ? returnValue =  true : returnValue =  false;
// 	returnValue ? std::cout << std::endl<<"success" << std::endl : std::cout << std::endl << "fail" << std::endl;
//     std::cout << "END Query_Any_5 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }
// bool ecore_any_query6() {
// 	bool returnValue=false;

// 	std::string qry = "self.eStructuralFeatures";
//     std::shared_ptr<ecore::EClass> context = Library_ecore::Library_ecorePackage::eInstance()->getLibrary_Class();
//     Any value = queryValue(qry,context);

//     std::cout << "START Query_Any_6 (context[EClass] = Library): " << qry << std::endl;
//     std::string resultStr=print(value, true);
//     std::cout << resultStr;
// 	(resultStr.compare("<EAttribute>:name:String[0..1]\n<EAttribute>:nbBooks:Integer[0..1]\n<EAttribute>:opened:EBoolean[0..1]\n<EReference>:books:Book[0..*]\n<EReference>:loans:Loan[0..*]\n<EReference>:members:Member[0..*]\n<EReference>:writers:Writer[0..*]\n") == 0) ? returnValue =  true : returnValue =  false;
// 	returnValue ? std::cout << "success" << std::endl : std::cout << "fail" << std::endl;
//     std::cout << "END Query_Any_6 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }
// bool ecore_any_query7() {
// 	bool returnValue=false;

// 	std::string qry = "Set{20, 1 .. 10}";
//     std::shared_ptr<ecore::EClass> context = Library_ecore::Library_ecorePackage::eInstance()->getLibrary_Class();
//     Any value = queryValue(qry,context);

//     std::cout << "START Query_Any_7 : " << qry << std::endl;
//     std::string resultStr=print(value, true);
//     std::cout << resultStr;
//     (resultStr.compare("20\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n") == 0) ? returnValue =  true : returnValue =  false;
// 	returnValue ? std::cout << "success" << std::endl : std::cout << "fail" << std::endl;
//     std::cout << "END Query_Any_7 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }
// bool ecore_any_query8() {
// 	bool returnValue=false;

// 	std::string qry = "Set{1, 2 .. 10}->iterate(i:Integer;sum:Integer=0 | sum + i)";
//     std::shared_ptr<ecore::EClass> context = Library_ecore::Library_ecorePackage::eInstance()->getLibrary_Class();
//     Any value = queryValue(qry,context);

//     std::cout << "START Query_Any_8 : " << qry << std::endl;
//     std::string resultStr=print(value);
//     std::cout << resultStr;
//     (resultStr.compare("55\n") == 0) ? returnValue =  true : returnValue =  false;
// 	returnValue ? std::cout << "success" << std::endl : std::cout << "fail" << std::endl;
//     std::cout << "END Query_Any_8 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }
// bool validate1() {
// 	std::string qry = "\npackage Library_ecore \n"
//                       "context Library::nbBooks : Integer \n"
//                       "init: nbBooks = 3 \n"
//                       "endpackage \n";
//     std::shared_ptr<ecore::EObject> context = Library_ecore::Library_ecoreFactory::eInstance()->createLibrary();
//     std::cout << "START Validate_1 : " << qry << std::endl;
//     bool returnValue=validate(qry,context,"false"); // ToDo OCL Intit validation is buggy right now
//     std::cout << "END Validate_1 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }
// bool validate2() {
//     std::string qry = "\ncontext Library::opened : Boolean derive: true \n";
//     std::shared_ptr<Library_ecore::Library> context = Library_ecore::Library_ecoreFactory::eInstance()->createLibrary();
//     context->setOpened(true);
//     std::cout << "START Validate_2 : " << qry << std::endl;
//     bool returnValue=validate(qry,context, "true");
//     context->setOpened(false);
//     returnValue=returnValue && validate(qry,context, "false");

//     std::cout << "END Validate_2 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }
// bool validate3() {
//     std::string qry = "\ncontext Library inv: self.nbBooks > 0 \n";
//     std::shared_ptr<Library_ecore::Library> context = Library_ecore::Library_ecoreFactory::eInstance()->createLibrary();
//     context->setNbBooks(5);
//     std::cout << "START Validate_3(nbBooks = 5) : " << qry << std::endl;
//     bool returnValue=validate(qry,context, "true");
//     std::cout << "END Validate_3 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }
// bool validate4() {
//     std::string qry = "\ncontext Library \n"
//                       "def: value: Real = self.nbBooks / self.nbBooks * self.nbBooks \n"
//                       "context Library \n"
//                       "inv: 25 = 5 * value \n";
//     std::shared_ptr<Library_ecore::Library> context = Library_ecore::Library_ecoreFactory::eInstance()->createLibrary();
//     context->setNbBooks(5);
//     std::cout << "START Validate_4(nbBooks = 5) : " << qry << std::endl;
//     bool returnValue=validate(qry,context, "true");
//     std::cout << "END Validate_4 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }
// bool  validate5() {
//     std::string qry = "\npackage Library_ecore \n"
//                       "context Library \n"
//                       "def: rest1: Real = nbBooks - 2 * nbBooks \n"
//                       "context Library \n"
//                       "def: rest2: Real = rest1 * 2 \n"
//                       "context Library \n"
//                       "inv: 15 = let result : Integer = 0 in nbBooks - rest2 \n"
//                       "endpackage \n";
//     std::shared_ptr<Library_ecore::Library> context = Library_ecore::Library_ecoreFactory::eInstance()->createLibrary();
//     context->setNbBooks(5);
//     std::cout << "START Validate_5(nbBooks = 5) : " << qry << std::endl;
//     bool returnValue=validate(qry,context, "true");
//     std::cout << "START Validate_5(nbBooks = 1) : " << std::endl;
//     context->setNbBooks(1);
//     returnValue=returnValue&&validate(qry,context, "false");
//     std::cout << "END Validate_5 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }
// bool  validate6() {
//     std::string qry = "\npackage Library_ecore \n"
//                       "context Book::countCopies() : Integer \n"
//                       "body: self.copies \n"
//                       "endpackage \n";
//     std::shared_ptr<Library_ecore::Book> context = Library_ecore::Library_ecoreFactory::eInstance()->createBook();
//     context->setCopies(5);
//     std::cout << "START Validate_6(copies = 5) : " << qry << std::endl;
//     bool returnValue=validate(qry,context, "5");
//     std::cout << "END Validate_6 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }

// bool validate7() {
//     std::string qry = "\npackage Library_ecore \n"
//                       "context Book::addCopies(nbCopies:Integer=2): \n"
//                       "pre: nbCopies > 2 \n"
//                       "endpackage \n";
//     std::shared_ptr<Library_ecore::Book> context = Library_ecore::Library_ecoreFactory::eInstance()->createBook();
//     std::cout << "START Validate_7(addCopy(2)>2) : " << qry << std::endl;
//     bool returnValue=validate(qry,context, "false");
// 	qry = "\npackage Library_ecore \n"
//                       "context Book::addCopies(nbCopies:Integer=2): \n"
//                       "pre: nbCopies >= 2 \n"
//                       "endpackage \n";
//     std::cout << "START Validate_7(addCopy(2)>=2) : " << std::endl;
//     returnValue=returnValue && validate(qry,context, "true");

//     std::cout << "END Validate_7 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }

// bool validate8() {
//     std::string qry = "\npackage Library_ecore \n"
//                       "context Book::addCopies(nbCopies:Integer=2): \n"
//                       "post: self.copies = 2 \n"
//                       "endpackage \n";
//     std::shared_ptr<Library_ecore::Book> context = Library_ecore::Library_ecoreFactory::eInstance()->createBook();
//     std::cout << "START Validate_8(addCopy(2)) : " << qry << std::endl;
//     bool returnValue=validate(qry,context, "true");
//     std::cout << "END Validate_8 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }

// bool validate9() {
//     std::string qry = "\npackage Library_ecore \n"
//                       "context Library::open(): \n"
//                       "pre: self.opened = false \n"
//                       "endpackage \n";
//     std::shared_ptr<Library_ecore::Library> context = Library_ecore::Library_ecoreFactory::eInstance()->createLibrary();
//     context->setOpened(false);
//     std::cout << "START Validate_9(open()) : " << qry << std::endl;
//     bool returnValue=validate(qry,context, "true");
//     std::cout << "Validate_9(open()) : " << std::endl;
//     context->setOpened(true);
//     returnValue=returnValue && validate(qry,context, "false");
//     std::cout << "END Validate_9 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }

// bool validate10() {
//     std::string qry = "context Library::open(): \n"
//                       "post: self.opened = true";
//     std::shared_ptr<Library_ecore::Library> context = Library_ecore::Library_ecoreFactory::eInstance()->createLibrary();
//     context->setOpened(false);
//     std::cout << "START Validate_10(open()) : " << qry << std::endl;
//     bool returnValue=validate(qry,context, "true");
//     std::cout << "END Validate_10 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }

// bool validate11() {
//     std::string qry = "\npackage Library_ecore \n"
//                       "context Book::addCopies(nbCopies:Integer=2): \n"
//                       "post: copies = copies@pre + nbCopies \n"
//                       "endpackage\n";
//     std::shared_ptr<Library_ecore::Book> context = Library_ecore::Library_ecoreFactory::eInstance()->createBook();
//     std::cout << "START Validate_11(addCopies(2)) : " << qry << std::endl;
//     bool returnValue=validate(qry,context, "true");
//     std::cout << "END Validate_11 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }


// bool model_any_query1() {
// 	bool returnValue = false;
//     std::string qry = "self.name";
//     std::shared_ptr<Library_ecore::Library> store= createBookStore();
//     std::cout << "START query: " << qry << std::endl;
//     Any value = queryValue(qry,store);
//     if(value != nullptr) {
//     	std::string resultStr=value->get<std::string>() ;
//         std::cout << resultStr << std::endl;
//         (resultStr.compare("TU Ilmenau - University Library") == 0) ? returnValue =  true : returnValue =  false;
//     }
//     qry = "self.loans";
//     std::cout << "START query: " << qry << std::endl;
//     value = queryValue(qry,store);
//     if(value != nullptr) {
//     	try
//     	{
// 			std::shared_ptr<Bag<AnyObject>> anyBag = value->get<std::shared_ptr<Bag<AnyObject>>>();
// 			Any loanAny = anyBag->at(0);
// 			std::shared_ptr<ecore::EObject> obj= loanAny->get<std::shared_ptr<ecore::EObject>>(); //throws exception
// 	        std::shared_ptr<Loan> loan = std::dynamic_pointer_cast<Loan>(obj);
// 	    	std::ostringstream outStringStream;
// 	    	outStringStream<< "Loan: " << loan->getMember()->getName() << " -> " << loan->getBook()->getTitle();
// 	    	std::cout << outStringStream.str()<< std::endl;
// 	    	bool testVal;
// 	    	(outStringStream.str().compare("Loan: Paul -> Magritte") == 0) ? testVal =  true : testVal =  false;
// 	    	returnValue = returnValue && testVal;
//     	}
//     	catch(...)
//     	{
//             std::cout << "Fail: Type error" << std::endl;
//             returnValue = false;
//     	}
//     }
//     returnValue ? std::cout << "success" << std::endl : std::cout << "fail" << std::endl;
// 	std::cout << "END Model Query_1 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }

// bool model_any_query2() {
// 	bool returnValue = false;
// 	try
// 	{
// 		std::string qry ="self->eContents()";
// 		std::shared_ptr<Library_ecore::Library> store= createBookStore();
// 		std::cout << "START query: " << qry << std::endl;
// 		Any value = queryValue(qry,store);
// 		std::string resultStr=Library_ecore::Library_ecoreFactory::eInstance()->convertToString(nullptr, value);
// 		std::cout << resultStr << std::endl;
// 		qry ="self->eAllContents()";
// 		std::cout << "START query: " << qry << std::endl;

// 		(resultStr.compare("<Bag<Any>> size: 7\n\tAny: TU Ilmenau - University Library\n\tAny: 3\n\tAny: 1\n\t<EObjectContainer> size: 1\n\tType:Book\n\t<EObjectContainer> size: 1\n\tType:Loan\n\t<EObjectContainer> size: 1\n\tType:Member\n\t<EObjectContainer> size: 1\n\tType:Writer\n\n") == 0) ? returnValue =  true : returnValue =  false;
// 		value = queryValue(qry,store);
// 		resultStr=Library_ecore::Library_ecoreFactory::eInstance()->convertToString(nullptr, value);
// 		std::cout << resultStr << std::endl;
// 		(resultStr.compare("<Bag<Any>> size: 7\n\tTU Ilmenau - University Library\n\t3\n\t1\n\t<Bag<Any>> size: 1\n\tAny (typeId: 373399861)\n\t<Bag<Any>> size: 1\n\tAny (typeId: 1722537035)\n\t<Bag<Any>> size: 1\n\tAny (typeId: 1119152035)\n\t<Bag<Any>> size: 1\n\tAny (typeId: 100089347)\n\n") == 0) ? returnValue =  returnValue && true : returnValue =  false;
// 	}
// 	catch(...)
// 	{
// 	}
// 	returnValue ? std::cout << "success" << std::endl : std::cout << "fail" << std::endl;
// 	std::cout << "END Model Query_2 -------------------------------------------\n" << std::endl;
// 	return returnValue;
// }

// /*
// bool model_any_query4()
// {
// 	bool returnValue = false;
//     std::string qry = "self.eContentUnion";
//     std::shared_ptr<Library_ecore::Library> store= createBookStore();
//     std::cout << "START query : " << qry << std::endl;
//     Any value = queryValue(qry,store);
//     std::string resultStr=print(value, true);
//     std::cout << resultStr;
// 	(resultStr.compare("Magritte: not available: Num copies: 0: category: 0\nMember: Paul\nLoan: 0\n") == 0) ? returnValue =  true : returnValue =  false;
// 	returnValue ? std::cout << "success" << std::endl : std::cout << "fail" << std::endl;
// 	std::cout << "END Model Query_4 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }
// */

// bool model_any_query3()
// {
// 	bool returnValue = false;
//     std::string qry = "self->eClass()";
//     std::shared_ptr<Library_ecore::Library> store= createBookStore();
//     std::cout << "START query : " << qry << std::endl;
//     Any value = queryValue(qry,store);
//     std::string resultStr="";
//     try{
//     	std::shared_ptr<ecore::EObject> libObj = value->get<std::shared_ptr<ecore::EObject>>();
//     	std::shared_ptr<ecore::EClass> libClass = std::dynamic_pointer_cast<ecore::EClass>(libObj);
//     	if(libClass)   resultStr= libClass ->getName();
//     }catch(...){}

// 	std::cout << resultStr << std::endl;

//     (resultStr.compare("Library") == 0) ? returnValue =  true : returnValue =  false;

//     returnValue ? std::cout << "success" << std::endl : std::cout << "fail" << std::endl;
// 	std::cout << "END Model Query_3 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }

// // End of user code

// int main ()
// {
// 	//Create Model Factory
// 	std::shared_ptr<Library_ecoreFactory> factory = Library_ecoreFactory::eInstance();

// 	int sucCount=0;
// 	int failCount=0;
// 	try{
// 	// ecore Metamodel test
// 	query1()== true ? sucCount++:failCount++;
// 	query2()== true ? sucCount++:failCount++;
// 	query3()== true ? sucCount++:failCount++;
// 	query4()== true ? sucCount++:failCount++;
// 	query5()== true ? sucCount++:failCount++;

// 	ecore_any_query1()== true ? sucCount++:failCount++;
// 	ecore_any_query2()== true ? sucCount++:failCount++;
// 	ecore_any_query3()== true ? sucCount++:failCount++;
// 	ecore_any_query4()== true ? sucCount++:failCount++;
// 	ecore_any_query5()== true ? sucCount++:failCount++;
// 	ecore_any_query6()== true ? sucCount++:failCount++;
// 	ecore_any_query7()== true ? sucCount++:failCount++;
// 	ecore_any_query8()== true ? sucCount++:failCount++;
// 	//Model based Tests
// 	validate1()== true ? sucCount++:failCount++;
// 	validate2()== true ? sucCount++:failCount++;
// 	validate3()== true ? sucCount++:failCount++;
// 	validate4()== true ? sucCount++:failCount++;
// 	validate5()== true ? sucCount++:failCount++;
// 	validate6()== true ? sucCount++:failCount++;
// 	validate7()== true ? sucCount++:failCount++;
// 	validate8()== true ? sucCount++:failCount++;
// 	validate9()== true ? sucCount++:failCount++;
// 	validate10()== true ? sucCount++:failCount++;
// 	validate11()== true ? sucCount++:failCount++;

// 	//Model quwey

// 	model_any_query1()== true ? sucCount++:failCount++;
// 	model_any_query2()== true ? sucCount++:failCount++;
// 	model_any_query3()== true ? sucCount++:failCount++;

// 	}
// 	catch(...){}
// 	std::cout << sucCount << "/"<< sucCount+failCount << " correct: ";
// 	(failCount==0) ? std::cout << "success" << std::endl: std::cout << "fail" << std::endl;

// 	pause();

// // Start of user code main
// // You may manually edit the following lines, won't be overwritten upon generation.

// // End of user code

//     return 0;

// }
