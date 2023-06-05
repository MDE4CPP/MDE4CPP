
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

#include <oclParser/Utilities/OclEcore.h>

// Start of user code includes 
// // You may manually edit additional includes, won't be overwritten upon generation.

// // End of user code

using namespace Library_ecore;

// Start of user code functions 
// You may manually edit additional functions, won't be overwritten upon generation.

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
        //const std::shared_ptr<ecore::EStructuralFeature>& elem = eClass->getEAllStructuralFeatures()->at(i); -> causes with debugger an error
        std::shared_ptr<ecore::EStructuralFeature> elem = eClass->getEAllStructuralFeatures()->at(i);
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

bool testCases() {

	std::shared_ptr<Library_ecore::Library> store = createBookStore();

	// preparation
	std::shared_ptr<Bag<Library_ecore::Book>> bookList = store->getBooks();
	std::vector<std::string> bookTitles;
	size_t bookBagSize = bookList->size();

	for (size_t i = 0; i < bookBagSize; i++)
	{
		bookTitles.push_back(bookList->at(i)->getTitle());
	}
	
	bool allPassed = true;
    bool thisPassed = true;
	int failCounter = 0;
	int counter = 1;

	std::shared_ptr<Any> anyLib = eEcoreAny(store, store->getMetaElementID());
    
	{ // Test Case 1
		std::cout << "-------------------------------------Test Case: " << counter << "---------------------------------" << std::endl;
		
		Utilities::OclEcore ocl;
		std::string query = "self.books->iterate(elem; acc: Bag(Book) = Bag{} | acc->including(elem))";
		std::shared_ptr<Any> result = ocl.debugQuery(query, anyLib);
		std::cout << "\nQuery: " << query << std::endl;
		// get result as Bag
		std::shared_ptr<Bag<Any>> resultBag = nullptr;
		std::vector<std::string> relevantBookTitles = bookTitles;
        thisPassed = true;
		
		try 
		{
			if (result != nullptr) {
                resultBag = result->get<std::shared_ptr<Bag<Any>>>();
            } else {
                throw("Result is no Bag<Any>!");
            }
		}
		catch(...)
		{
			std::cout << "Query result is no Bag<Any>" << std::endl;
			thisPassed = false;
		}

		if (resultBag != nullptr) {

			//read out result bag
			std::shared_ptr<Any> bagElement;
			std::shared_ptr<Any> foundFeat;
			std::string featStr = "";

			size_t bagSize = resultBag->size();

			//check each element
			for (size_t i = 0; i < bagSize; i++) {
				
				bagElement = resultBag->at(i);
				foundFeat = lookupPropertyName("title", bagElement);

				if (foundFeat != nullptr) {

					try
					{
						featStr = foundFeat->get<std::string>();
					}
					catch(...)
					{
						std::cout << "Bag Element at " << i << " is no Book!" << std::endl;
						thisPassed = false;
					}

					if (!(featStr == relevantBookTitles.at(i))){
						std::cout << "Book Title at " << i << " is not equal!" << std::endl;
						std::cout << "Have to be: " << relevantBookTitles.at(i) << std::endl;
						std::cout << "Got: " << featStr << std::endl;
						thisPassed = false;
					}

				} // end of foundFeat != nullptr
				else {
					std::cout << "Bag Element at " << i << " is no Book!" << std::endl;
					thisPassed = false;
				}

				if (!thisPassed) {
					break;
				}

			}// end of check each element
		}// end of resultBag != nullptr

		allPassed = (allPassed) ? thisPassed : allPassed;
        failCounter += (!thisPassed) ? 1 : 0;
        std::string res = thisPassed ? "PASSED!" : "FAILED!";
        std::cout << res << std::endl;
		std::cout << "-------------------------------------End of Test Case: " << counter << "--------------------------" << std::endl;
		counter++;

	}// end of Test Case 1

    { // Test Case 2
		std::cout << "\n-------------------------------------Test Case: " << counter << "---------------------------------" << std::endl;
		
		Utilities::OclEcore ocl;
		std::string query = "self.books->iterate(elem : Book; acc: Bag(Book) = Bag{} | acc->including(elem))";
		std::shared_ptr<Any> result = ocl.debugQuery(query, anyLib);
		std::cout << "\nQuery: " << query << std::endl;
		// get result as Bag
		std::shared_ptr<Bag<Any>> resultBag = nullptr;
		std::vector<std::string> relevantBookTitles = bookTitles;
        thisPassed = true;
		
		try 
		{
            if (result != nullptr) {
                resultBag = result->get<std::shared_ptr<Bag<Any>>>();
            } else {
                throw("Result is no Bag<Any>!");
            }
		}
		catch(...)
		{
			std::cout << "Query result is no Bag<Any>" << std::endl;
			thisPassed = false;
		}

		if (resultBag != nullptr) {

			//read out result bag
			std::shared_ptr<Any> bagElement;
			std::shared_ptr<Any> foundFeat;
			std::string featStr = "";

			size_t bagSize = resultBag->size();

			//check each element
			for (size_t i = 0; i < bagSize; i++) {
				
				bagElement = resultBag->at(i);
				foundFeat = lookupPropertyName("title", bagElement);

				if (foundFeat != nullptr) {

					try
					{
                        featStr = foundFeat->get<std::string>();
					}
					catch(...)
					{
						std::cout << "Bag Element at " << i << " is no Book!" << std::endl;
						thisPassed = false;
					}

					if (!(featStr == relevantBookTitles.at(i))){
						std::cout << "Book Title at " << i << " is not equal!" << std::endl;
						std::cout << "Have to be: " << relevantBookTitles.at(i) << std::endl;
						std::cout << "Got: " << featStr << std::endl;
						thisPassed = false;
					}

				} // end of foundFeat != nullptr
				else {
					std::cout << "Bag Element at " << i << " is no Book!" << std::endl;
					thisPassed = false;
				}

				if (!thisPassed) {
					break;
				}

			}// end of check each element
		}// end of resultBag != nullptr

		allPassed = (allPassed) ? thisPassed : allPassed;
        failCounter += (!thisPassed) ? 1 : 0;
        std::string res = thisPassed ? "PASSED!" : "FAILED!";
        std::cout << res << std::endl;
		std::cout << "-------------------------------------End of Test Case: " << counter << "--------------------------" << std::endl;
		counter++;

	}// end of Test Case 2

	{// Test Case 3
		std::cout << "\n-------------------------------------Test Case: " << counter << "---------------------------------" << std::endl;

		Utilities::OclEcore ocl;
		std::string query = "self.books->select(elem: Book | elem.title='Perry')";
		std::shared_ptr<Any> result = ocl.debugQuery(query, anyLib);
		std::cout << "\nQuery: " << query << std::endl;
		std::string relevantBookTitle = bookTitles.at(1);
		std::string title = "";
        std::shared_ptr<Any> anyBook = nullptr;
        std::shared_ptr<Bag<Any>> resultBag = nullptr;
        thisPassed = true;

		try 
		{
			if (result != nullptr) {
                resultBag = result->get<std::shared_ptr<Bag<Any>>>();
            } else {
                throw("Result is no Bag<Any>!");
            }
		}
		catch(...)
		{
			std::cout << "Query result is no Bag<Any>" << std::endl;
			thisPassed = false;
		}

        if (resultBag->size() != 1) {
            std::cout << "Result Bag of Query have not length of 1!" << std::endl;
            std::cout << "Bag length: " << resultBag->size() << std::endl;
            thisPassed = false;

        } else {

            anyBook = resultBag->at(0);
        
            try
            {
                std::shared_ptr<Any> lookupReturn = lookupPropertyName("title", anyBook);
                if (lookupReturn != nullptr) {
                    title = lookupReturn->get<std::string>();
                } else {
                    throw("Wrong type of bag element!");
                }
            }
            catch(...)
            {
                std::cout << "Result is no Book!" << std::endl;
                thisPassed = false;
            }

            if (!(title == relevantBookTitle)){
                std::cout << "Book Title is not equal!" << std::endl;
                std::cout << "Have to be: " << relevantBookTitle << std::endl;
                std::cout << "Got: " << title << std::endl;
                thisPassed = false;
            }

        }


		allPassed = (allPassed) ? thisPassed : allPassed;
        failCounter += (!thisPassed) ? 1 : 0;
        std::string res = thisPassed ? "PASSED!" : "FAILED!";
        std::cout << res << std::endl;
		std::cout << "-------------------------------------End of Test Case: " << counter << "---------------------------------" << std::endl;
		counter++;
	}// end of Test Case 3

    {// Test Case 4

        std::cout << "\n-------------------------------------Test Case: " << counter << "---------------------------------" << std::endl;

		Utilities::OclEcore ocl;
		std::string query = "self.books->select(title<>'Magritte')";
		std::shared_ptr<Any> result = ocl.debugQuery(query, anyLib);
		std::cout << "\nQuery: " << query << std::endl;
		std::vector<std::string> relevantBookTitles = bookTitles;
        relevantBookTitles.erase(relevantBookTitles.begin());
		std::string title = "";
        std::shared_ptr<Any> anyBook = nullptr;
        std::shared_ptr<Bag<Any>> resultBag = nullptr;
        thisPassed = true;

        try 
		{
			if (result != nullptr) {
                resultBag = result->get<std::shared_ptr<Bag<Any>>>();
            } else {
                throw("Result is no Bag<Any>!");
            }
		}
		catch(...)
		{
			std::cout << "Query result is no Bag<Any>" << std::endl;
			thisPassed = false;
		}

		if (resultBag != nullptr) {

			//read out result bag
			std::shared_ptr<Any> bagElement;
			std::shared_ptr<Any> foundFeat;
			std::string featStr = "";

			size_t bagSize = resultBag->size();

			//check each element
			for (size_t i = 0; i < bagSize; i++) {
				
				bagElement = resultBag->at(i);
				foundFeat = lookupPropertyName("title", bagElement);

				if (foundFeat != nullptr) {

					try
					{
						featStr = foundFeat->get<std::string>();
					}
					catch(...)
					{
						std::cout << "Bag Element at " << i << " is no Book!" << std::endl;
						thisPassed = false;
					}

					if (!(featStr == relevantBookTitles.at(i))){
						std::cout << "Book Title at " << i << " is not equal!" << std::endl;
						std::cout << "Have to be: " << relevantBookTitles.at(i) << std::endl;
						std::cout << "Got: " << featStr << std::endl;
						thisPassed = false;
					}

				} // end of foundFeat != nullptr
				else {
					std::cout << "Bag Element at " << i << " is no Book!" << std::endl;
					thisPassed = false;
				}

				if (!thisPassed) {
					break;
				}

			}// end of check each element
		}// end of resultBag != nullptr


        allPassed = (allPassed) ? thisPassed : allPassed;
        failCounter += (!thisPassed) ? 1 : 0;
        std::string res = thisPassed ? "PASSED!" : "FAILED!";
        std::cout << res << std::endl;
		std::cout << "-------------------------------------End of Test Case: " << counter << "---------------------------------" << std::endl;
		counter++;

    }// end of Test Case 4

    {// Test Case 5

        std::cout << "\n-------------------------------------Test Case: " << counter << "---------------------------------" << std::endl;

		Utilities::OclEcore ocl;
		std::string query = "self.books->reject(title<>'Magritte')";
		std::shared_ptr<Any> result = ocl.debugQuery(query, anyLib);
		std::cout << "\nQuery: " << query << std::endl;
		std::string relevantBookTitle = bookTitles.at(0);
		std::string title = "";
        std::shared_ptr<Any> anyBook = nullptr;
        std::shared_ptr<Bag<Any>> resultBag = nullptr;
        thisPassed = true;

		try 
		{
			if (result != nullptr) {
                resultBag = result->get<std::shared_ptr<Bag<Any>>>();
            } else {
                throw("Result is no Bag<Any>!");
            }
		}
		catch(...)
		{
			std::cout << "Query result is no Bag<Any>" << std::endl;
			thisPassed = false;
		}

        if (resultBag->size() != 1) {
            std::cout << "Result Bag of Query have not length of 1!" << std::endl;
            std::cout << "Bag length: " << resultBag->size() << std::endl;
            thisPassed = false;

        } else {

            anyBook = resultBag->at(0);
        
            try
            {
                std::shared_ptr<Any> lookupReturn = lookupPropertyName("title", anyBook);
                if (lookupReturn != nullptr) {
                    title = lookupReturn->get<std::string>();
                } else {
                    throw("Wrong type of bag element!");
                }
            }
            catch(...)
            {
                std::cout << "Result is no Book!" << std::endl;
                thisPassed = false;
            }

            if (!(title == relevantBookTitle)){
                std::cout << "Book Title is not equal!" << std::endl;
                std::cout << "Have to be: " << relevantBookTitle << std::endl;
                std::cout << "Got: " << title << std::endl;
                thisPassed = false;
            }

        }


        allPassed = (allPassed) ? thisPassed : allPassed;
        failCounter += (!thisPassed) ? 1 : 0;
        std::string res = thisPassed ? "PASSED!" : "FAILED!";
        std::cout << res << std::endl;
		std::cout << "-------------------------------------End of Test Case: " << counter << "---------------------------------" << std::endl;
		counter++;

    }// end of Test Case 5

    {// Test Case 6

        std::cout << "\n-------------------------------------Test Case: " << counter << "---------------------------------" << std::endl;

		Utilities::OclEcore ocl;
		std::string query = "self.books->reject(elem: Book | elem.title='Perry')";
		std::shared_ptr<Any> result = ocl.debugQuery(query, anyLib);
		std::cout << "\nQuery: " << query << std::endl;
		std::vector<std::string> relevantBookTitles = bookTitles;
        relevantBookTitles.erase(relevantBookTitles.begin()+1);
		std::string title = "";
        std::shared_ptr<Any> anyBook = nullptr;
        std::shared_ptr<Bag<Any>> resultBag = nullptr;
        thisPassed = true;

        try 
		{
			if (result != nullptr) {
                resultBag = result->get<std::shared_ptr<Bag<Any>>>();
            } else {
                throw("Result is no Bag<Any>!");
            }
		}
		catch(...)
		{
			std::cout << "Query result is no Bag<Any>" << std::endl;
			thisPassed = false;
		}

		if (resultBag != nullptr) {

			//read out result bag
			std::shared_ptr<Any> bagElement;
			std::shared_ptr<Any> foundFeat;
			std::string featStr = "";

			size_t bagSize = resultBag->size();

			//check each element
			for (size_t i = 0; i < bagSize; i++) {
				
				bagElement = resultBag->at(i);
				foundFeat = lookupPropertyName("title", bagElement);

				if (foundFeat != nullptr) {

					try
					{
						featStr = foundFeat->get<std::string>();
					}
					catch(...)
					{
						std::cout << "Bag Element at " << i << " is no Book!" << std::endl;
						thisPassed = false;
					}

					if (!(featStr == relevantBookTitles.at(i))){
						std::cout << "Book Title at " << i << " is not equal!" << std::endl;
						std::cout << "Have to be: " << relevantBookTitles.at(i) << std::endl;
						std::cout << "Got: " << featStr << std::endl;
						thisPassed = false;
					}

				} // end of foundFeat != nullptr
				else {
					std::cout << "Bag Element at " << i << " is no Book!" << std::endl;
					thisPassed = false;
				}

				if (!thisPassed) {
					break;
				}

			}// end of check each element
		}// end of resultBag != nullptr


        allPassed = (allPassed) ? thisPassed : allPassed;
        failCounter += (!thisPassed) ? 1 : 0;
        std::string res = thisPassed ? "PASSED!" : "FAILED!";
        std::cout << res << std::endl;
		std::cout << "-------------------------------------End of Test Case: " << counter << "---------------------------------" << std::endl;
		counter++;

    }// end of Test Case 6

    {// Test Case 7

        std::cout << "\n-------------------------------------Test Case: " << counter << "---------------------------------" << std::endl;

		bool oldOpenedValue = store->isOpened();
        if (store->isOpened()) {
            store->setOpened(true);
        }
        
        Utilities::OclEcore ocl;
		std::string query = "self.close()";
		std::shared_ptr<Any> result = ocl.debugQuery(query, anyLib);
		std::cout << "\nQuery: " << query << std::endl;
        thisPassed = true;

        if (store->isOpened()) {
            std::cout << "Function call does not work!" << std::endl;
            thisPassed = false;
        }

        store->setOpened(oldOpenedValue);

        allPassed = (allPassed) ? thisPassed : allPassed;
        failCounter += (!thisPassed) ? 1 : 0;
        std::string res = thisPassed ? "PASSED!" : "FAILED!";
        std::cout << res << std::endl;
		std::cout << "-------------------------------------End of Test Case: " << counter << "---------------------------------" << std::endl;
		counter++;

    }// end of Test Case 7

    {// Test Case 8

        std::cout << "\n-------------------------------------Test Case: " << counter << "---------------------------------" << std::endl;
        
        Utilities::OclEcore ocl;
		std::string query = "if self.opened then 'open' else 'closed' endif";
		std::shared_ptr<Any> result = ocl.debugQuery(query, anyLib);
		std::cout << "\nQuery: " << query << std::endl;
        thisPassed = true;
        std::string resultString = "";

        try
        {
            if (result != nullptr) {
                resultString = result->get<std::string>();
            } else {
                throw("Result is nullptr!");
            }
        }
        catch(...)
        {
            std::cout << "Result value is no String!" << std::endl;
            thisPassed = false;
        }

        if (resultString != "open") {
            std::cout << "Result string is not correct!" << std::endl;
            std::cout << "Result is: " << resultString <<  std::endl;
            std::cout << "Should be: open" <<  std::endl;
            thisPassed = false;
        }

        allPassed = (allPassed) ? thisPassed : allPassed;
        failCounter += (!thisPassed) ? 1 : 0;
        std::string res = thisPassed ? "PASSED!" : "FAILED!";
        std::cout << res << std::endl;
		std::cout << "-------------------------------------End of Test Case: " << counter << "---------------------------------" << std::endl;
		counter++;

    }// end of Test Case 8

    {// Test Case 9

        std::cout << "\n-------------------------------------Test Case: " << counter << "---------------------------------" << std::endl;
        
        bool oldOpenedValue = store->isOpened();
        if (store->isOpened()) {
            store->setOpened(false);
        }
        
        Utilities::OclEcore ocl;
		std::string query = "if self.opened then 'open' else 'closed' endif";
		std::shared_ptr<Any> result = ocl.debugQuery(query, anyLib);
		std::cout << "\nQuery: " << query << std::endl;
        thisPassed = true;
        std::string resultString = "";

        try
        {
            if (result != nullptr) {
                resultString = result->get<std::string>();
            } else {
                throw("Result is nullptr!");
            }
        }
        catch(...)
        {
            std::cout << "Result value is no String!" << std::endl;
            thisPassed = false;
        }

        if (resultString != "closed") {
            std::cout << "Result string is not correct!" << std::endl;
            std::cout << "Result is: " << resultString <<  std::endl;
            std::cout << "Should be: open" <<  std::endl;
            thisPassed = false;
        }

        store->setOpened(oldOpenedValue);

        allPassed = (allPassed) ? thisPassed : allPassed;
        failCounter += (!thisPassed) ? 1 : 0;
        std::string res = thisPassed ? "PASSED!" : "FAILED!";
        std::cout << res << std::endl;
		std::cout << "-------------------------------------End of Test Case: " << counter << "---------------------------------" << std::endl;
		counter++;

    }// end of Test Case 9

    {// Test Case 10

        std::cout << "\n-------------------------------------Test Case: " << counter << "---------------------------------" << std::endl;

		Utilities::OclEcore ocl;
		std::string query = "self.writers[0].name";
		std::shared_ptr<Any> result = ocl.debugQuery(query, anyLib);
		std::cout << "\nQuery: " << query << std::endl;
        std::string writerName = store->getWriters()->at(0)->getName();
        std::string resultString = "";
        thisPassed = true;

        try
        {
            if (result != nullptr) {
                resultString = result->get<std::string>();

            } else {
                throw("Result is nullptr!");
            }
            
        }
        catch(const std::exception& e)
        {
            std::cout << "Result value is no String!" << std::endl;
            thisPassed = false;
        }

        if (resultString != writerName) {
            std::cout << "Result string is not correct!" << std::endl;
            std::cout << "Result is: " << resultString <<  std::endl;
            std::cout << "Should be: " << writerName <<  std::endl;
            thisPassed = false;
        }
        

        allPassed = (allPassed) ? thisPassed : allPassed;
        failCounter += (!thisPassed) ? 1 : 0;
        std::string res = thisPassed ? "PASSED!" : "FAILED!";
        std::cout << res << std::endl;
		std::cout << "-------------------------------------End of Test Case: " << counter << "---------------------------------" << std::endl;
		counter++;

    }// end of Test Case 10

    {// Test Case 11

        std::cout << "\n-------------------------------------Test Case: " << counter << "---------------------------------" << std::endl;

		Utilities::OclEcore ocl;
		std::string query = "self.writers[].name";
		std::shared_ptr<Any> result = ocl.debugQuery(query, anyLib);
		std::cout << "\nQuery: " << query << std::endl;
        thisPassed = true;

        // correctly nullptr '[]' on an collection without index always returns the Collection
        if (result != nullptr) {
            std::cout << "Result have to be nullptr! An collection call without index specification returns always the complete collection." << std::endl;
            thisPassed = false;
        }

        allPassed = (allPassed) ? thisPassed : allPassed;
        failCounter += (!thisPassed) ? 1 : 0;
        std::string res = thisPassed ? "PASSED!" : "FAILED!";
        std::cout << res << std::endl;
		std::cout << "-------------------------------------End of Test Case: " << counter << "---------------------------------" << std::endl;
		counter++;

    }// end of Test Case 11

    {// Test Case 12

        std::cout << "\n-------------------------------------Test Case: " << counter << "---------------------------------" << std::endl;

		Utilities::OclEcore ocl;
		std::string query = "self.books[0, 3, 1, 5, 2, 5]";
		std::shared_ptr<Any> result = ocl.debugQuery(query, anyLib);
		std::cout << "\nQuery: " << query << std::endl;
		std::vector<std::string> relevantBookTitles = std::vector<std::string>();
        relevantBookTitles.push_back(bookTitles.at(0));
        relevantBookTitles.push_back(bookTitles.at(3));
        relevantBookTitles.push_back(bookTitles.at(1));
        relevantBookTitles.push_back(bookTitles.at(5));
        relevantBookTitles.push_back(bookTitles.at(2));
        relevantBookTitles.push_back(bookTitles.at(5));
		std::string title = "";
        std::shared_ptr<Any> anyBook = nullptr;
        std::shared_ptr<Bag<Any>> resultBag = nullptr;
        thisPassed = true;

        try 
		{
			if (result != nullptr) {
                resultBag = result->get<std::shared_ptr<Bag<Any>>>();
            } else {
                throw("Result is no Bag<Any>!");
            }
		}
		catch(...)
		{
			std::cout << "Query result is no Bag<Any>" << std::endl;
			thisPassed = false;
		}

		if (resultBag != nullptr) {

			//read out result bag
			std::shared_ptr<Any> bagElement;
			std::shared_ptr<Any> foundFeat;
			std::string featStr = "";

			size_t bagSize = resultBag->size();

			//check each element
			for (size_t i = 0; i < bagSize; i++) {
				
				bagElement = resultBag->at(i);
				foundFeat = lookupPropertyName("title", bagElement);

				if (foundFeat != nullptr) {

					try
					{
						featStr = foundFeat->get<std::string>();
					}
					catch(...)
					{
						std::cout << "Bag Element at " << i << " is no Book!" << std::endl;
						thisPassed = false;
					}

					if (!(featStr == relevantBookTitles.at(i))){
						std::cout << "Book Title at " << i << " is not equal!" << std::endl;
						std::cout << "Have to be: " << relevantBookTitles.at(i) << std::endl;
						std::cout << "Got: " << featStr << std::endl;
						thisPassed = false;
					}

				} // end of foundFeat != nullptr
				else {
					std::cout << "Bag Element at " << i << " is no Book!" << std::endl;
					thisPassed = false;
				}

				if (!thisPassed) {
					break;
				}

			}// end of check each element
		}// end of resultBag != nullptr


        allPassed = (allPassed) ? thisPassed : allPassed;
        failCounter += (!thisPassed) ? 1 : 0;
        std::string res = thisPassed ? "PASSED!" : "FAILED!";
        std::cout << res << std::endl;
		std::cout << "-------------------------------------End of Test Case: " << counter << "---------------------------------" << std::endl;
		counter++;

    }// end of Test Case 12

    {// Test Case 13

        std::cout << "\n-------------------------------------Test Case: " << counter << "---------------------------------" << std::endl;

		Utilities::OclEcore ocl;
		std::string query = "self.books[2]";
		std::shared_ptr<Any> result = ocl.debugQuery(query, anyLib);
		std::cout << "\nQuery: " << query << std::endl;
        std::shared_ptr<ecore::EObject> book = bookList->at(2);
        std::shared_ptr<ecore::EObject> resultBook = nullptr;
        thisPassed = true;

        try
        {
            if (result != nullptr) {
                std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(result);
                resultBook = ecoreAny->getAsEObject();

            } else {
                throw("Result is nullptr!");
            }
            
        }
        catch(...)
        {
            std::cout << "Result value is no Book!" << std::endl;
            thisPassed = false;
        }

        if (resultBook != book) {
            std::cout << "Result is not correct!" << std::endl;
            thisPassed = false;
        }
        

        allPassed = (allPassed) ? thisPassed : allPassed;
        failCounter += (!thisPassed) ? 1 : 0;
        std::string res = thisPassed ? "PASSED!" : "FAILED!";
        std::cout << res << std::endl;
		std::cout << "-------------------------------------End of Test Case: " << counter << "---------------------------------" << std::endl;
		counter++;

    }// end of Test Case 13

    {// Test Case 14

        std::cout << "\n-------------------------------------Test Case: " << counter << "---------------------------------" << std::endl;

		int oldCopiesValue = bookList->at(2)->getCopies();
        bookList->at(2)->setCopies(50);
        
        Utilities::OclEcore ocl;
		std::string query = "self.books[2].countCopies()";
		std::shared_ptr<Any> result = ocl.debugQuery(query, anyLib);
		std::cout << "\nQuery: " << query << std::endl;
        int bookCopies = bookList->at(2)->getCopies();
        int resultInt = -1;
        thisPassed = true;

        try
        {
            if (result != nullptr) {
                resultInt = result->get<int>();
            } else {
                throw("Result is nullptr!");
            }
            
        }
        catch(...)
        {
            std::cout << "Result value is no Integer!" << std::endl;
            thisPassed = false;
        }

        if (resultInt != bookCopies) {
            std::cout << "Number of copies is not correct!" << std::endl;
            std::cout << "Have to be: " << bookCopies << std::endl;
			std::cout << "Got: " << resultInt << std::endl;
            thisPassed = false;
        }


        bookList->at(2)->setCopies(oldCopiesValue);

        allPassed = (allPassed) ? thisPassed : allPassed;
        failCounter += (!thisPassed) ? 1 : 0;
        std::string res = thisPassed ? "PASSED!" : "FAILED!";
        std::cout << res << std::endl;
		std::cout << "-------------------------------------End of Test Case: " << counter << "---------------------------------" << std::endl;
		counter++;

    }// end of Test Case 14

    {// Test Case 15

        std::cout << "\n-------------------------------------Test Case: " << counter << "---------------------------------" << std::endl;

		int oldCopiesValue = bookList->at(2)->getCopies();
        bookList->at(2)->setCopies(50);
        
        Utilities::OclEcore ocl;
		std::string query1 = "let z = self.books[2].countCopies() in self.books[2].addCopies(z)";
		std::shared_ptr<Any> result = ocl.debugQuery(query1, anyLib);
        std::string query2 = "self.books[2].countCopies()";
        result = ocl.debugQuery(query2, anyLib);
		std::cout << "\nQuery 1/2: " << query1 << std::endl;
        std::cout << "\nQuery 2/2: " << query2 << std::endl;
        int bookCopies = 100;
        int resultInt = -1;
        thisPassed = true;

        try
        {
            if (result != nullptr) {
                resultInt = result->get<int>();
            } else {
                throw("Result is nullptr!");
            }
            
        }
        catch(...)
        {
            std::cout << "Result value is no Integer!" << std::endl;
            thisPassed = false;
        }

        if (resultInt != bookCopies) {
            std::cout << "Number of copies is not correct!" << std::endl;
            std::cout << "Have to be: " << bookCopies << std::endl;
			std::cout << "Got: " << resultInt << std::endl;
            thisPassed = false;
        }


        bookList->at(2)->setCopies(oldCopiesValue);

        allPassed = (allPassed) ? thisPassed : allPassed;
        failCounter += (!thisPassed) ? 1 : 0;
        std::string res = thisPassed ? "PASSED!" : "FAILED!";
        std::cout << res << std::endl;
		std::cout << "-------------------------------------End of Test Case: " << counter << "---------------------------------" << std::endl;
		counter++;

    }// end of Test Case 15

	if (!allPassed) {
		std::cout << "##################################" << std::endl;
		std::cout << "Not all Test cases were successful!" << std::endl;
		std::cout << "Fail Count: " << failCounter << std::endl;
		std::cout << "##################################" << std::endl;
	} else {
		std::cout << "###############################" << std::endl;
		std::cout << "All Test cases were successful!" << std::endl;
		std::cout << "###############################" << std::endl;
	}
	
	return allPassed;

}

// End of user code

int main ()
{
	//Create Model Factory
	std::shared_ptr<Library_ecoreFactory> factory = Library_ecoreFactory::eInstance();

	// Test
	testCases();

// Start of user code main
// You may manually edit the following lines, won't be overwritten upon generation.

// End of user code

    return 0;

}
