
#include <iostream>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "libraryModel_ecore/LibraryModel_ecoreFactory.hpp"
#include "libraryModel_ecore/LibraryModel_ecorePackage.hpp"

#include "libraryModel_ecore/Book.hpp"
#include "libraryModel_ecore/Author.hpp"
#include "libraryModel_ecore/LibraryModel.hpp"
#include "libraryModel_ecore/NamedElement.hpp"
#include "libraryModel_ecore/Picture.hpp"

// Start of user code includes 
// You may manually edit additional includes, won't be overwritten upon generation.

// End of user code

using namespace libraryModel_ecore;

// Start of user code functions 
// You may manually edit additional functions, won't be overwritten upon generation.

// End of user code

int main ()
{
	//Create Model Factory and Package
	std::shared_ptr<LibraryModel_ecoreFactory> factory = LibraryModel_ecoreFactory::eInstance();
	std::shared_ptr<LibraryModel_ecorePackage> package = LibraryModel_ecorePackage::eInstance();

	// Create new Library Model instance
    std::shared_ptr<LibraryModel> lm = factory->createLibraryModel();

    std::shared_ptr<Book> book = factory->createBook_in_Library(lm);
    book->setName("Magritte");

    std::shared_ptr<Author> author = factory->createAuthor();
    author->setName("David Sylvester");
    book->getAuthors()->add(author);

    std::shared_ptr<Picture> picture = factory->createPicture_in_Book(book);
    picture->setName("Der Verrat der Binder (La trahison des images), 1929: l, 60x82 cm");
    picture->setPageNumber(212);

    lm->printLibrary();

// Start of user code main
// You may manually edit the following lines, won't be overwritten upon generation.

// End of user code

    return 0;

}
