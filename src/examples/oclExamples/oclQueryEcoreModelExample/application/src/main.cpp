
#include <iostream>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "Library_QueryEcore/Library_QueryEcoreFactory.hpp"
#include "Library_QueryEcore/Library_QueryEcorePackage.hpp"

#include "Library_QueryEcore/Library.hpp"
#include "Library_QueryEcore/Member.hpp"
#include "Library_QueryEcore/Book.hpp"
#include "Library_QueryEcore/Loan.hpp"
#include "Library_QueryEcore/Writer.hpp"
#include "Library_QueryEcore/LibraryModel.hpp"
#include "Library_QueryEcore/BookCategory.hpp"

#include <string>
#include <sstream>
#include <oclParser/Utilities/OclEcore.h>
#include <ecore/EObject.hpp>
#include <ecore/EObjectAny.hpp>
#include "abstractDataTypes/EcoreAny.hpp"
#include "abstractDataTypes/EcoreContainerAny.hpp"
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
#include <ecore/EObjectContainer.hpp>

// Start of user code includes 
// You may manually edit additional includes, won't be overwritten upon generation.

// End of user code

using namespace Library_QueryEcore;

// Start of user code functions 
// You may manually edit additional functions, won't be overwritten upon generation.
/*
Helper functions
*/

Any queryValue(const std::string& query, std::shared_ptr<ecore::EObject> context)
{
	Utilities::Ocl ocl;
    try {
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

std::string printLibrary(const std::shared_ptr<Library_QueryEcore::Library> library)
{
	std::ostringstream returnStringStream;
	if(nullptr!=library)
	{
		returnStringStream << library->getName() << ": "  << (library->isOpened() ? "open" : "closed") << ": Num books: " << library->getNbBooks() << std::endl;
	}
	return returnStringStream.str();
}

std::string printLibraryModel(const std::shared_ptr<Library_QueryEcore::LibraryModel> model)
{
	std::ostringstream returnStringStream;
	if(nullptr !=model)
	{
		std::shared_ptr<Bag<Library_QueryEcore::Library> > libraries = model->getLibraries();
		returnStringStream << "LibraryModel. Number of libraries: " << libraries->size() << std::endl;
		for (std::shared_ptr<Library_QueryEcore::Library> lib : *(libraries))
		{
			returnStringStream << printLibrary(lib);
		}
	}
	return returnStringStream.str();
}

std::string printBook(const std::shared_ptr<Library_QueryEcore::Book> book)
{
	std::ostringstream returnStringStream;
	if(nullptr!=book)
	{
		returnStringStream << book->getTitle() << ": "	<< (book->isAvailable() ? "available" : "not available") << ": Num copies: " << book->getCopies() << ": category: "	<< (int) ((book->getCategory())) << std::endl;
	}
	return returnStringStream.str();
}


std::string printEClassifier(std::shared_ptr<ecore::EClass> anEClass)
{
	std::ostringstream returnStringStream;
	if(nullptr!= anEClass)
	{
		returnStringStream << "<EClass>:" << anEClass->getName() << ":"<< anEClass->getName()<<std::endl;

		std::shared_ptr<Subset<ecore::EAttribute, ecore::EStructuralFeature>> attributes = anEClass->getEAttributes();
		Any eAnyValue= eAnyBag(attributes,ecore::ecorePackage::EATTRIBUTE_CLASS);
		returnStringStream << Library_QueryEcore::Library_QueryEcoreFactory::eInstance()->convertToString(nullptr,  eAnyValue);
		std::shared_ptr<Subset<ecore::EReference, ecore::EStructuralFeature>> references = anEClass->getEReferences();
		eAnyValue =eAnyBag(references,ecore::ecorePackage::EREFERENCE_CLASS);
		returnStringStream << Library_QueryEcore::Library_QueryEcoreFactory::eInstance()->convertToString(nullptr, eAnyValue);
	}
	return returnStringStream.str();
}


std::string print(Any value);

std::string printEObject(std::shared_ptr<ecore::EObject> eobj) 
{
	std::ostringstream returnStringStream;
    if(eobj!= nullptr) 
    {
		std::shared_ptr<ecore::EClass> anEClass= std::dynamic_pointer_cast<ecore::EClass>(eobj);
		if(nullptr !=anEClass) // It's an meta-clas description! print MetaClass
		{
			returnStringStream << printEClassifier(anEClass);
		}
		else
		{
			switch (eobj->getMetaElementID())
			{
				case ecore::ecorePackage::EOBJECT_CLASS: // unknown or primitive type
				case ecore::ecorePackage::ECLASS_CLASS:
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
				{
					returnStringStream << Library_QueryEcore::Library_QueryEcoreFactory::eInstance()->convertToString(nullptr, eAnyObject(eobj,eobj->getMetaElementID()));
					break;
				}
				case ecore::ecorePackage::ANY_CLASS:
				case ecore::ecorePackage::EOBJECTANY_CLASS:
				{
					std::shared_ptr<ecore::EObjectAny> eObjectAny=std::dynamic_pointer_cast<ecore::EObjectAny>(eobj);
					if(nullptr!=eObjectAny)
					{
						returnStringStream << "Any: " << print(eObjectAny->getAny()) << std::endl;
					}
					break;
				}
				case ecore::ecorePackage::EOBJECTCONTAINER_CLASS:
				{
					std::shared_ptr<ecore::EObjectContainer> eObjectContainer= std::dynamic_pointer_cast<ecore::EObjectContainer>(eobj);
					if(nullptr!=eObjectContainer)
					{
						std::shared_ptr<Bag<ecore::EObject>> eObjectBag =  eObjectContainer->getContainer();
						returnStringStream << "<EObjectContainer> size: " << eObjectBag->size();
						for(const std::shared_ptr<ecore::EObject> object: *eObjectBag)
						{	// recursive Call of printEObject Value
							returnStringStream <<  "\t" << printEObject(object);
						}
					}
					break;
				}
				case Library_QueryEcore::Library_QueryEcorePackage::LIBRARYMODEL_CLASS:
				{
					std::shared_ptr<Library_QueryEcore::LibraryModel> model= std::dynamic_pointer_cast<Library_QueryEcore::LibraryModel>(eobj);
					if(nullptr !=model)
					{
						returnStringStream << printLibraryModel(model);
					}
					break;
				}
				case Library_QueryEcore::Library_QueryEcorePackage::LIBRARY_CLASS:
				{
					std::shared_ptr<Library_QueryEcore::Library> library= std::dynamic_pointer_cast<Library_QueryEcore::Library>(eobj);
					if(nullptr !=library)
					{
						returnStringStream << printLibrary(library);
					}
					break;
				}
				case Library_QueryEcore::Library_QueryEcorePackage::BOOK_CLASS:
				{
					std::shared_ptr<Library_QueryEcore::Book> book=  std::dynamic_pointer_cast<Library_QueryEcore::Book>(eobj);
					if(nullptr !=book)
					{
						returnStringStream <<  printBook(book);
					}
					break;
				}
				case Library_QueryEcore::Library_QueryEcorePackage::MEMBER_CLASS:
				{
					std::shared_ptr<Library_QueryEcore::Member> member= std::dynamic_pointer_cast<Library_QueryEcore::Member>(eobj);
					if(nullptr !=member)
					{
						returnStringStream << "Member: " << member->getName()<< std::endl;
					}
					break;
				}
				case Library_QueryEcore::Library_QueryEcorePackage::LOAN_CLASS:
				{
					std::shared_ptr<Library_QueryEcore::Loan> loan = std::dynamic_pointer_cast<Library_QueryEcore::Loan>(eobj);
					if(nullptr !=loan)
					{
						returnStringStream << "Loan: " << loan->getDate() << std::endl;
					}
					break;
				}
				default:
				{
					returnStringStream << "EObject (typeId: " << eobj->getMetaElementID()  <<  ")" << std::endl;
				}
			}
		}
    }
	return returnStringStream.str();
}

std::string print(Any value)
{
	std::ostringstream returnStringStream;
	bool handled=false;
	if(nullptr==value )
	{
		return "";
	}
	if(value->isContainer())
	{
		try
		{
			switch (value->getTypeId())
			{
				case ecore::ecorePackage::EOBJECT_CLASS:
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectBag;
					try
					{
						eObjectBag= value->get<std::shared_ptr<Bag<ecore::EObject>>>(); //throws exception
						returnStringStream << "<Bag<EObject>> size: " << eObjectBag->size() <<std::endl;
					}
					catch(...)
					{
						std::shared_ptr<AnyEObjectBag> anyObjectBag = std::dynamic_pointer_cast<AnyEObjectBag>(value);
						if(nullptr!=anyObjectBag)// AnyEobjectBag?
						{
							eObjectBag=anyObjectBag->getBag();
							returnStringStream << "<AnyEObjectBag<EObject>> size: " << eObjectBag->size() <<std::endl;
						}
						else
						{
							returnStringStream << "An EObject Container";
						}
					}
					if(nullptr!=eObjectBag)
					{
						for(const std::shared_ptr<ecore::EObject> object: *eObjectBag)
						{	// recursive Call of convertToString via new Any EObject Value
							returnStringStream << "\t"<< printEObject(object);
						}
					}
					handled = true; break;
				}
				case ecore::ecorePackage::EOBJECTCONTAINER_CLASS:
				{
					std::shared_ptr<ecore::EObjectContainer> eObjectContainer = value->get<std::shared_ptr<ecore::EObjectContainer>>();
					std::shared_ptr<Bag<ecore::EObject>> eObjectBag =  eObjectContainer->getContainer();
					returnStringStream << "<EObjectContainer> size: " << eObjectBag->size() <<std::endl;
					for(const std::shared_ptr<ecore::EObject> object: *eObjectBag)
					{	// recursive Call of convertToString via new Any EObject Value
						returnStringStream << "\t"<<printEObject(object);
					}
					handled = true; break;
				}
				default:
				{
					std::shared_ptr<AnyEObjectBag> anyObjectBag = std::dynamic_pointer_cast<AnyEObjectBag>(value);
					if(nullptr!=anyObjectBag)// AnyEObjectBag?
					{
						std::shared_ptr<Bag<ecore::EObject>> eObjectBag=anyObjectBag->getBag();
						returnStringStream << "<AnyEObjectBag> size: " << eObjectBag->size() <<std::endl;
						for(const std::shared_ptr<ecore::EObject> object: *eObjectBag)
						{	// recursive Call of convertToString via new Any EObject Value
							returnStringStream << "\t"<<printEObject(object);
						}
						handled = true; break;
					}
					else // last supported type bag<Any>
					{
						std::shared_ptr<Bag<AnyObject>> anyBag = value->get<std::shared_ptr<Bag<AnyObject>>>();
						unsigned int size=anyBag->size();
						returnStringStream << "<Bag<Any>> size: " << size<<std::endl;
						for(unsigned int i = 0; i < size; i++)
						{
							returnStringStream << "\t"<< print(anyBag->at(i));
						}
						returnStringStream << std::endl;
						handled = true; break;
					}
				}
			}
		}
		catch(...)
		{
			returnStringStream <<""<<std::endl;
		}
	}
	else
	{
		try{
			switch(value->getTypeId())
			{
				case ecore::ecorePackage::EOBJECT_CLASS: // unknown or primitive type
				{
					std::shared_ptr<ecore::EObject> eobj = value->get<std::shared_ptr<ecore::EObject>>();
					return printEObject(eobj );
					handled=true;
					break;
				}
				case ecore::ecorePackage::EOBJECTCONTAINER_CLASS:
				{
					std::shared_ptr<ecore::EObjectContainer> eObjectContainer= nullptr;
					try
					{
						eObjectContainer= value->get<std::shared_ptr<ecore::EObjectContainer>>();
					}
					catch(...)
					{
						std::shared_ptr<ecore::EObject> object= value->get<std::shared_ptr<ecore::EObject>>();
						eObjectContainer= std::dynamic_pointer_cast<ecore::EObjectContainer>(object);
					}
					std::shared_ptr<Bag<ecore::EObject>> eObjectBag =  eObjectContainer->getContainer();
					returnStringStream << "<EObjectContainer> size: " << eObjectBag->size() <<std::endl;
					for(const std::shared_ptr<ecore::EObject> object: *eObjectBag)
					{	// recursive Call of convertToString via new Any EObject Value
						returnStringStream << "\t"<<printEObject(object)<<std::endl;
					}
					handled=true;
					break;
				}
				case ecore::ecorePackage::ECLASS_CLASS:
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
				{
					returnStringStream << Library_QueryEcore::Library_QueryEcoreFactory::eInstance()->convertToString(nullptr, value);
					handled=true;
					break;
				}
				case ecore::ecorePackage::EOBJECTANY_CLASS:
				{
					std::shared_ptr<ecore::EObjectAny> eObjectAny=nullptr;
					try
					{
						std::shared_ptr<ecore::EObject> aObject = value->get<std::shared_ptr<ecore::EObject>>();
						eObjectAny = std::dynamic_pointer_cast<ecore::EObjectAny>(aObject);
					}
					catch(...) // 2. try
					{
						eObjectAny= value->get<std::shared_ptr<ecore::EObjectAny>>();
					}
					// recursive Call of convertToString via new Any EObject Value
					if(nullptr!=eObjectAny)
					{
						returnStringStream << "Any: " << print(eObjectAny->getAny());
						handled = true;
					}
					break;
				}
				case ecore::ecorePackage::ANY_CLASS:
				{
					std::shared_ptr<ecore::EObjectAny> eObjectAny=nullptr;
					try
					{
						std::shared_ptr<ecore::EObject> aObject = value->get<std::shared_ptr<ecore::EObject>>();
						eObjectAny = std::dynamic_pointer_cast<ecore::EObjectAny>(aObject);
					}
					catch(...) // 2. try
					{
						try
						{
							eObjectAny= value->get<std::shared_ptr<ecore::EObjectAny>>();
						}
						catch(...) // 2. last try
						{
							Any anAny= value->get<Any>();
							returnStringStream << "Any: " << print(anAny);
							handled = true;
						}
					}
					// recursive Call of convertToString via new Any EObject Value
					if(nullptr!=eObjectAny)
					{
						returnStringStream << "Any: " << print(eObjectAny->getAny());
						handled = true;
					}
					break;
				}
				// Model types are not supported right now --> manual handling
				case Library_QueryEcore::Library_QueryEcorePackage::LIBRARYMODEL_CLASS:
				{
					std::shared_ptr<Library_QueryEcore::LibraryModel> model= nullptr;
					try
					{
						model= value->get<std::shared_ptr<Library_QueryEcore::LibraryModel>>();
						if(nullptr !=model)
						{
							returnStringStream<<printLibraryModel(model);
						}
					}
					catch(...)
					{
						std::shared_ptr<ecore::EObject> object= value->get<std::shared_ptr<ecore::EObject>>();
						returnStringStream<<printEObject(object);
						handled=true;
					}
					break;
				}
				case Library_QueryEcore::Library_QueryEcorePackage::BOOK_CLASS:
				{
					std::shared_ptr<Library_QueryEcore::Book> book= nullptr;
					try
					{
						book= value->get<std::shared_ptr<Library_QueryEcore::Book>>();
						if(nullptr !=book)
						{
							returnStringStream << printBook(book);
							handled=true;
						}
					}
					catch(...)
					{
						std::shared_ptr<ecore::EObject> object= value->get<std::shared_ptr<ecore::EObject>>();
						returnStringStream<<printEObject(object);
						handled=true;
					}
					break;
				}
				case Library_QueryEcore::Library_QueryEcorePackage::LIBRARY_CLASS:
				{
					std::shared_ptr<Library_QueryEcore::Library> library= nullptr;
					try
					{
						library= value->get<std::shared_ptr<Library_QueryEcore::Library>>();
						if(nullptr !=library)
						{
							returnStringStream << printLibrary(library);
							handled=true;
						}
					}
					catch(...)
					{
						std::shared_ptr<ecore::EObject> object= value->get<std::shared_ptr<ecore::EObject>>();
						returnStringStream<<printEObject(object);
						handled=true;
					}
					break;
				}
				case Library_QueryEcore::Library_QueryEcorePackage::MEMBER_CLASS:
				{
					std::shared_ptr<Library_QueryEcore::Member> member=nullptr;
					try
					{
						member = value->get<std::shared_ptr<Library_QueryEcore::Member>>();
						if(nullptr !=member)
						{
							returnStringStream <<"Member: "<< member->getName() << std::endl;
							handled=true;
						}
					}
					catch(...)
					{
						std::shared_ptr<ecore::EObject> object= value->get<std::shared_ptr<ecore::EObject>>();
						returnStringStream<<printEObject(object);
					}
					break;
				}
				case Library_QueryEcore::Library_QueryEcorePackage::LOAN_CLASS:
				{
					std::shared_ptr<Library_QueryEcore::Loan> loan = nullptr;
					try
					{
						loan = value->get<std::shared_ptr<Library_QueryEcore::Loan>>();
						if(nullptr !=loan)
						{
							returnStringStream <<"Loan: "<< loan->getDate()<< std::endl;
							handled=true;
						}
					}
					catch(...)
					{
						std::shared_ptr<ecore::EObject> object= value->get<std::shared_ptr<ecore::EObject>>();
						returnStringStream<<printEObject(object);
					}
					break;
				}
			}

		} catch (...) { }
		if(!handled)
		{
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
	}
	return returnStringStream.str();

}

std::shared_ptr<Library_QueryEcore::Library> createTestLibrary(std::shared_ptr<Library_QueryEcore::LibraryModel> libModel, std::string name)
{
	std::shared_ptr<Library_QueryEcore::Library_QueryEcoreFactory> factory = Library_QueryEcore::Library_QueryEcoreFactory::eInstance();
    std::shared_ptr<Library_QueryEcore::Library> lib = factory ->createLibrary_as_libraries_in_LibraryModel(libModel);

    lib->setName(name);
    std::shared_ptr<Library_QueryEcore::Book> bookMag = factory->createBook_as_books_in_Library(lib);

    bookMag->setTitle("Magritte");

    std::shared_ptr<Writer> writer=factory->createWriter_as_writers_in_Library(lib);
    bookMag->setCategory(BookCategory::ART);
    writer->setName("David Sylvester");
    bookMag->getWriters()->add(writer);
    bookMag->setAvailable(true);
    bookMag->setCopies(2);

    std::shared_ptr<Member> paul=factory->createMember_as_members_in_Library(lib);
	paul->setName("Paul");

    std::shared_ptr<Loan> loan=factory->createLoan_as_loans_in_Library(lib);
    loan->setMember(paul);
    loan->setBook(bookMag);
    std::shared_ptr<Library_QueryEcore::Book> book=nullptr;
	for(int i=0; i<5;i++)
	{
		book = factory->createBook_as_books_in_Library(lib);
		std::string title=std::to_string(i);
		book->setTitle("book # "+title);
	}

	return lib;
}

int currentContextNumber=0;
const int numberOfQueries=9;
std::string queryList[numberOfQueries]={"self","self.name", "self->eContents()", "self->eAllContents()", "self->getLib(0)", "self->calcBookNum()", "self.books", "self.members", "self->eClass()"};

void Clear()
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
#elif defined (__APPLE__)
    system("clear");
#endif
}

void printMainMenu(int contextNumber)
{
	std::cout << "OCL Query Ecore Main Menu" << std::endl;
	std::cout << "_________________________" << std::endl;
	std::cout << "Current context: ";
	switch(contextNumber)
	{
		case 0:
		{
			std::cout << "Library Model" << std::endl;
			break;
		}
		case 1:
		{
			std::cout << "TU Ilmenau - University Library" << std::endl;
			break;
		}
		case 2:
		{
			std::cout << "FH Schmalkalden - Cellarius University Library Schmalkalden" << std::endl;
			break;
		}
		case 3:
		{
			std::cout << "Metamodel of Library Model (ecore)" << std::endl;
			break;
		}
		default:
		{
			std::cout << "Library Model" << std::endl;
			break;
		}
	}
	std::cout << "Commands: " << std::endl;
	std::cout << "\tset context:" << std::endl;
	std::cout << "\t\t- m: select Library Model" << std::endl;
	std::cout << "\t\t- i: select TU Ilmenau - University Library" << std::endl;
	std::cout << "\t\t- s: select FH Schmalkalden - Cellarius University Library Schmalkalden" << std::endl;
	std::cout << "\t\t- e: select Metamodel of Library Model" << std::endl;
	std::cout << "\tpredefined Queries:" << std::endl;
	for(int i=0; i<numberOfQueries;i++)
	{
		std::cout << "\t\t- " << i << ": " << queryList[i] << std::endl;
	}
	std::cout << "\tExit: x" << std::endl;
}
// End of user code

int main ()
{
	//Create Model Factory
	std::shared_ptr<Library_QueryEcoreFactory> factory = Library_QueryEcoreFactory::eInstance();

	std::shared_ptr<Library_QueryEcore::LibraryModel> libModel=factory->createLibraryModel();

	std::shared_ptr<Library_QueryEcore::Library> lib1= createTestLibrary(libModel,"TU Ilmenau - University Library");
	std::shared_ptr<Library_QueryEcore::Library> lib2= createTestLibrary(libModel,"FH Schmalkalden - Cellarius University Library Schmalkalden");

	std::string enterValue;

	std::shared_ptr<ecore::EObject> context=libModel;
	Clear();
	printMainMenu(currentContextNumber);
	std::cout << "Enter an OCL expression or a command:";
	std::string resultString="";
	std::getline(std::cin, enterValue);
	while(enterValue.compare("x"))
	{
		Clear();

		if(enterValue.size()==1)
		{
			if(0==enterValue.compare("m"))
			{
				currentContextNumber=0;
				context=libModel;
				resultString ="Context set to Library Model";
				printMainMenu(currentContextNumber);
			}
			else
			{
				if(0==enterValue.compare("i"))
				{
					currentContextNumber=1;
					context=lib1;
					resultString = "Context set to " + lib1->getName();
					printMainMenu(currentContextNumber);
				}
				else
				{
					if(0==enterValue.compare("s"))
					{
						currentContextNumber=2;
						context=lib2;
						resultString = "Context set to " + lib2->getName();
						printMainMenu(currentContextNumber);
					}
					else
					{
						if(0==enterValue.compare("e"))
						{
							currentContextNumber=3;
							context=libModel->eClass();
							resultString = "Context set to Metamodel: " + libModel->eClass()->getName();
							printMainMenu(currentContextNumber);
						}
						else
						{
							printMainMenu(currentContextNumber);
							std::cout<< "___________ Result: ___________" << std::endl;

							try
							{
								int commandNumber=std::stoi(enterValue);
								if( (commandNumber>=0) && (commandNumber<=numberOfQueries))
								{
									try
									{
										std::string command=std::string(queryList[commandNumber])+"\n";
										resultString =  std::string("Query: ") + command ;
										Any anyValue=queryValue(command, context);
										resultString = resultString  + print(anyValue);
									}
									catch (std::exception &e) {
										resultString =  std::string("exception : ") + e.what();
									}
									catch (...) {
										resultString = "unknown Error\n";
									}
								}
								else
								{
									resultString = "unknown Command\n";
								}
							}
							catch(...)
							{
								resultString = "unknown Command\n";
							}
						}
					}
				}
			}
		}
		else
		{
			try
			{
				printMainMenu(currentContextNumber);
				std::cout<< "___________ Result: ___________" << std::endl;
				Any anyValue=queryValue(enterValue, context);
				resultString =  std::string("Query: ") + enterValue + "\n";
				resultString = print(anyValue);
			}
			catch (std::exception &e) {
				resultString =  std::string("exception : ") + e.what();
			}
			catch (...) {
				resultString = "unknown Error\n";
			}
		}
		std::cout<< resultString << std::endl<< std::endl;
		std::cout << "Enter an OCL expression or a command:";
		std::getline(std::cin, enterValue);
	}

// Start of user code main
// You may manually edit the following lines, won't be overwritten upon generation.

// End of user code

    return 0;

}
