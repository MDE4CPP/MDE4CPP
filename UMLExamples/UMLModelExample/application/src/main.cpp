
#include <iostream>
#include "LibraryModel_uml/LibraryModel_umlFactory.hpp"
#include "LibraryModel_uml/LibraryModel_umlPackage.hpp"

#include "LibraryModel_uml/Author.hpp"
#include "LibraryModel_uml/Book.hpp"
#include "LibraryModel_uml/Library.hpp"
#include "LibraryModel_uml/NamedModelElement.hpp"
#include "LibraryModel_uml/Picture.hpp"

// Start of user code includes 
// You may manually edit additional includes, won't be overwritten upon generation.
#include "abstractDataTypes/SubsetUnion.hpp"
// End of user code

using namespace LibraryModel_uml;

// Start of user code functions 
// You may manually edit additional functions, won't be overwritten upon generation.

// End of user code

int main ()
{
	//Create Model Factory and Package
	std::shared_ptr<LibraryModel_umlFactory> factory = LibraryModel_umlFactory::eInstance();
	std::shared_ptr<LibraryModel_umlPackage> package = LibraryModel_umlPackage::eInstance();

// Start of user code main
// You may manually edit the following lines, won't be overwritten upon generation.

// End of user code

    return 0;

}