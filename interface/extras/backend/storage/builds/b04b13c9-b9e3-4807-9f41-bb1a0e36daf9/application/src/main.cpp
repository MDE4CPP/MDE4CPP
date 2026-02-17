
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
// You may manually edit additional includes, won't be overwritten upon generation.

// End of user code

using namespace Library_ecore;

// Start of user code functions 
// You may manually edit additional functions, won't be overwritten upon generation.

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
