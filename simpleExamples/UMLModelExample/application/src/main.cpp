
#include <iostream>
using namespace std;

#include "LibraryModel_umlFactory.hpp"

#include "Book.hpp"
#include "Author.hpp"
#include "Picture.hpp"
#include "Library.hpp"

using namespace LibraryModel_uml;

void printLibrary(std::shared_ptr<Library> model)
{
	std::shared_ptr< Bag<Book> > books=model->getBooks();

	for(Bag<Book>::const_iterator it=books->begin();it!=books->end();it++)
	{
		std::cout << "The book " << (*it)->getName() << std::endl;
		{
			std::cout << "\twas written by:" << std::endl;

			std::shared_ptr< Bag<Author> > authors= (*it)->getAuthors();
			for(Bag<Author>::const_iterator itA=authors->begin();itA!=authors->end();itA++)
			{
				std::cout << "\t\t- " << (*itA)->getName() << std::endl;
			}
		}
		{
			std::cout << "\tIndex of Figures:" << std::endl;

			std::shared_ptr< Bag<Picture> > pictures= (*it)->getPictures();
			for(Bag<Picture>::const_iterator itP=pictures->begin();itP!=pictures->end();itP++)
			{
				std::cout << "\t\t- " << (*itP)->getName() << " - Page number: "<< (*itP)->getPageNumber() << std::endl;
			}
		}

	}
}

int main ()
{
	//Create Model Factory
	 std::shared_ptr<LibraryModel_umlFactory> factory = LibraryModel_umlFactory::eInstance();
	// Create new Library Model instance

	std::shared_ptr<Library> lib=factory->createLibrary();

    std::shared_ptr<Book> book = factory->createBook_in_Library(lib);
    book->setName("Magritte");

    std::shared_ptr<Author> author = factory->createAuthor_in_Library(lib);
    author->setName("David Sylvester");
    book->getAuthors()->add(author);

    std::shared_ptr<Picture> picture = factory->createPicture_in_Book(book);
    picture->setName("Der Verrat der Binder (La trahison des images), 1929: Öl, 60x82 cm");
    picture->setPageNumber(212);

    printLibrary(lib);

    return 0;

}
