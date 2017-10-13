
#include <iostream>
using namespace std;

#include "LibraryModel.hpp"
#include "EcoreSimpleExampleModelFactory.hpp"


int main (){
    shared_ptr<EcoreSimpleExampleModelFactory> factory = ecoreSimpleExampleModel::EcoreSimpleExampleModelFactory::eInstance();
    std::shared_ptr<LibraryModel> lm = factory->createLibraryModel();

    auto book = factory->createBook_in_Library(lm);
    book->setName("Magritte");

    auto author = factory->createAuthor();
    author->setName("David Sylvester");

    book->setAuthor(author);

    std::cout << "The book " << book->getName()<< " was written by " book->getAuthor()->getName() << std::endl;

    return 0;

}