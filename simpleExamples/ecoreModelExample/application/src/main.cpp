
#include <iostream>
using namespace std;

#include "LibraryModel.hpp"
#include "LibraryModel_ecoreFactory.hpp"

#include "Book.hpp"
#include "Author.hpp"
#include "Picture.hpp"


using namespace libraryModel_ecore;

void printLibrary(std::shared_ptr<LibraryModel> model)
{
	std::shared_ptr< Bag<libraryModel_ecore::Book> > books=model->getBook();

	for(Bag<libraryModel_ecore::Book>::const_iterator it=books->begin();it!=books->end();it++)
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
	std::shared_ptr<LibraryModel_ecoreFactory> factory = LibraryModel_ecoreFactory::eInstance();
	// Create new Library Model instance
    std::shared_ptr<LibraryModel> lm = factory->createLibraryModel();

    std::shared_ptr<Book> book = factory->createBook_in_Library(lm);
    book->setName("Magritte");

    std::shared_ptr<Author> author = factory->createAuthor();
    author->setName("David Sylvester");
    book->getAuthors()->add(author);

    std::shared_ptr<Picture> picture = factory->createPicture_in_Book(book);
    picture->setName("Der Verrat der Binder (La trahison des images), 1929: Öl, 60x82 cm");
    picture->setPageNumber(212);

    printLibrary(lm);

    return 0;

}
