
#include <iostream>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "libraryModel_ecore/libraryModel_ecoreFactory.hpp"
#include "libraryModel_ecore/libraryModel_ecorePackage.hpp"

#include "libraryModel_ecore/Book.hpp"
#include "libraryModel_ecore/Author.hpp"
#include "libraryModel_ecore/LibraryModel.hpp"
#include "libraryModel_ecore/NamedElement.hpp"
#include "libraryModel_ecore/Picture.hpp"
#include "libraryModel_ecore/Publisher.hpp"
#include "libraryModel_ecore/Adress.hpp"

#include <iostream>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "libraryModel_ecore/libraryModel_ecoreFactory.hpp"
#include "libraryModel_ecore/libraryModel_ecorePackage.hpp"

#include "libraryModel_ecore/Book.hpp"
#include "libraryModel_ecore/Author.hpp"
#include "libraryModel_ecore/LibraryModel.hpp"
#include "libraryModel_ecore/NamedElement.hpp"
#include "libraryModel_ecore/Picture.hpp"

#include "abstractDataTypes/Any.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
//#include "pluginFramework/PluginFramework.hpp" // can be used, if external (model independent) library can be specified inside the ecore model
#include "pluginFramework/MDE4CPPPlugin.hpp"
#include "libraryModel_ecore/LibraryModel_ecorePlugin.hpp"

// Start of user code includes 
// You may manually edit additional includes, won't be overwritten upon generation.

// End of user code

using namespace libraryModel_ecore;

// Start of user code functions 
// You may manually edit additional functions, won't be overwritten upon generation.

// End of user code

int main ()
{
	//Create Model Factory
	std::shared_ptr<libraryModel_ecoreFactory> factory = libraryModel_ecoreFactory::eInstance();

    // Create new Library Model instance
    std::shared_ptr<LibraryModel> lm = factory->createLibraryModel();

    std::shared_ptr<Book> bookMag = factory->createBook_as_books_in_LibraryModel(lm);
    bookMag->setName("Magritte");
    bookMag->setPages(448);
    //bookMag->setGenres("");

    std::shared_ptr<Author> author = factory->createAuthor_as_authors_in_LibraryModel(lm);
    author->setName("David Sylvester");
    bookMag->getAuthors()->add(author);

    std::shared_ptr<Picture> picture = factory->createPicture_as_pictures_in_Book(bookMag);
    picture->setName("Der Verrat der Binder (La trahison des images), 1929: l, 60x82 cm");
    picture->setPageNumber(212);

    lm->printLibrary();

    std::cout << "--------------------------" << std::endl;
	std::cout << "build model in generic way" << std::endl;


	// can be used, if external (model independent) library can be specified inside the ecore model
	//	std::shared_ptr<PluginFramework> pfw = PluginFramework::eInstance();
	//	std::shared_ptr<MDE4CPPPlugin> plugin = pfw->findPluginByName("libraryModel_ecore");

	std::shared_ptr<MDE4CPPPlugin> plugin = libraryModel_ecorePlugin::eInstance();


	if (!plugin)
	{
		std::cout << "plugin not found" << std::endl;
	}
	else
	{
		std::cout << "generic model ..." << std::endl;

		std::shared_ptr<libraryModel_ecorePackage> package = libraryModel_ecorePackage::eInstance();

		std::shared_ptr<ecore::EObject> xlm = plugin->create("libraryModel_ecore::LibraryModel");
		std::shared_ptr<ecore::EObject> xbook = plugin->create("libraryModel_ecore::Book", xlm, package->LIBRARYMODEL_ATTRIBUTE_BOOKS);

		std::string bookname = "Magritte";
		xbook->eSet(package->getNamedElement_Attribute_name(), eAny(bookname, package->NAMEDELEMENT_ATTRIBUTE_NAME, false));

		std::shared_ptr<ecore::EObject> xauthor = plugin->create("libraryModel_ecore::Author", xlm, package->LIBRARYMODEL_ATTRIBUTE_AUTHORS);
		std::string authorname = "David Sylvester";
		xauthor->eSet(package->getNamedElement_Attribute_name(), eAny(authorname, package->NAMEDELEMENT_ATTRIBUTE_NAME, false));

		std::shared_ptr<Any> anyxbookauthors = xbook->eGet(package->getBook_Attribute_authors());
		std::shared_ptr<Bag<libraryModel_ecore::Author>> bookauthors = anyxbookauthors->get<std::shared_ptr<Bag<libraryModel_ecore::Author>>>();
		bookauthors->add(author);
		xbook->eSet(package->getBook_Attribute_authors(), eEcoreContainerAny(bookauthors, package->BOOK_ATTRIBUTE_AUTHORS));

		std::shared_ptr<ecore::EObject> xpicture = plugin->create("libraryModel_ecore::Picture", xbook, package->BOOK_ATTRIBUTE_PICTURES);
		int xint = 212;
		xpicture->eSet(package->getPicture_Attribute_pageNumber(), eAny(xint, package->PICTURE_ATTRIBUTE_PAGENUMBER, false));
		std::string picname = "Der Verrat der Binder (La trahison des images), 1929: l, 60x82 cm";
		xpicture->eSet(package->getNamedElement_Attribute_name(), eAny(picname, package->NAMEDELEMENT_ATTRIBUTE_NAME, false));

		// TODO call printLibrary by using invoce
		auto x = std::dynamic_pointer_cast<LibraryModel>(xlm);
		x->printLibrary();
	}

// Start of user code main
// You may manually edit the following lines, won't be overwritten upon generation.

// End of user code

    return 0;

}
