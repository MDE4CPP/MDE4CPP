
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
#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
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
