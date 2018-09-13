
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

	std::shared_ptr<Library> lib=factory->createLibrary();

    std::shared_ptr<Book> book = factory->createBook_in_Library(lib);
    book->setName("Magritte");

    std::shared_ptr<Author> author = factory->createAuthor_in_Library(lib);
    author->setName("David Sylvester");
    book->getAuthors()->add(author);

    std::shared_ptr<Picture> picture = factory->createPicture_in_Book(book);
    picture->setName("Der Verrat der Binder (La trahison des images), 1929: Öl, 60x82 cm");
    picture->setPageNumber(212);

    lib->printLibrary();

// Start of user code main
// You may manually edit the following lines, won't be overwritten upon generation.

// End of user code

    return 0;

}
