#include "testHelpers.hpp"

#include "pluginFramework/MDE4CPPPlugin.hpp"
#include "libraryModel_ecore/LibraryModel_ecorePlugin.hpp"

#include "libraryModel_ecore/libraryModel_ecoreFactory.hpp"
#include "libraryModel_ecore/libraryModel_ecorePackage.hpp"
#include "libraryModel_ecore/libraryModel_ecoreApi.hpp"

#include "libraryModel_ecore/Book.hpp"
#include "libraryModel_ecore/Author.hpp"
#include "libraryModel_ecore/LibraryModel.hpp"
#include "libraryModel_ecore/NamedElement.hpp"
#include "libraryModel_ecore/Picture.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/Bag.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"

std::shared_ptr<ecore::EObject> testHelpers::getExampleModelInstance_1(){
    using namespace libraryModel_ecore;
    std::shared_ptr<libraryModel_ecorePackage> package = libraryModel_ecorePackage::eInstance();
    
    std::shared_ptr<MDE4CPPPlugin> plugin = libraryModel_ecorePlugin::eInstance();
    
    //creates an instance of a LibraryModel lm
    std::shared_ptr<ecore::EObject> lm = plugin->create("libraryModel_ecore::LibraryModel");

    //creates an instance of a Book with name "Magritte" in lm
	std::shared_ptr<ecore::EObject> book = plugin->create("libraryModel_ecore::Book", lm, package->LIBRARYMODEL_ATTRIBUTE_BOOK);
    std::string bookname = "Magritte";
    book->eSet(package->getNamedElement_Attribute_name(), eAny(bookname, package->NAMEDELEMENT_ATTRIBUTE_NAME, false)); //set attribute name to "Magritte"
    Bag<std::string> b = Bag<std::string>();
    std::shared_ptr<Bag<std::string>> b_ptr = std::make_shared<Bag<std::string>>(b);
    b_ptr->push_back(std::make_shared<std::string>("Art"));
    b_ptr->push_back(std::make_shared<std::string>("Architecture"));
    book->eSet(package->getBook_Attribute_genres(), eAny(b_ptr, package->BOOK_ATTRIBUTE_GENRES, true)); //set attribute genres to "Architecture" and "Art"
    int pages = 448;
    book->eSet(package->getBook_Attribute_pages(), eAny(pages, package->BOOK_ATTRIBUTE_PAGES, false)); //set attribute pages to 448

    //creates an instance of an Author with name "David Sylvester" in lm
    std::shared_ptr<ecore::EObject> author = plugin->create("libraryModel_ecore::Author", lm, package->LIBRARYMODEL_ATTRIBUTE_AUTHORS);
    std::string authorname = "David Sylvester";
    author->eSet(package->getNamedElement_Attribute_name(), eAny(authorname, package->NAMEDELEMENT_ATTRIBUTE_NAME, false)); //set attribute name to "David Sylvester"

    //set author of the book
    std::shared_ptr<Any> anybookauthors = book->eGet(package->getBook_Attribute_authors());
    std::shared_ptr<Bag<libraryModel_ecore::Author>> bookauthors = anybookauthors->get<std::shared_ptr<Bag<libraryModel_ecore::Author>>>();
    bookauthors->add(std::dynamic_pointer_cast<Author>(author));
    book->eSet(package->getBook_Attribute_authors(), eEcoreContainerAny(bookauthors, package->BOOK_ATTRIBUTE_AUTHORS));

    //creates an instance of a Picture with name "Der Verrat der Binder (La trahison des images), 1929: l, 60x82 cm" in book
    std::shared_ptr<ecore::EObject> picture = plugin->create("libraryModel_ecore::Picture", book, package->BOOK_ATTRIBUTE_PICTURES);
    int i = 212;
    picture->eSet(package->getPicture_Attribute_pageNumber(), eAny(i, package->PICTURE_ATTRIBUTE_PAGENUMBER, false)); 
    std::string picname = "Der Verrat der Binder (La trahison des images), 1929: l, 60x82 cm";
    picture->eSet(package->getNamedElement_Attribute_name(), eAny(picname, package->NAMEDELEMENT_ATTRIBUTE_NAME, false));

    return lm;
}


