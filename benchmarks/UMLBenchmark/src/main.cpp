#include <iostream>
#include "UmlFactory.hpp"
#include "Package.hpp"
#include "Class.hpp"
#include "Property.hpp"
#include <string>
#include <chrono>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;

    uml::UmlFactory* umlFactory = uml::UmlFactory::eInstance();
    cout << "factory created " << umlFactory << endl;
    uml::Package* package = umlFactory->createPackage();
       cout << "package created" << endl;
    package->setName(std::string("Benchmark UML"));
    cout << package->getName() << endl;

    char buffer [33];

    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();
    for (int i=0; i<100000; i++)
    {
        uml::Class* classObject = umlFactory->createClass();
        classObject->setName("Class " + sprintf (buffer, "%i", i));
        uml::Property* property = umlFactory->createProperty();
        property->setName("A" + sprintf (buffer, "%i", i));
        classObject->getAttribute()->push_back(property);
        package->getOwnedMember()->push_back(classObject);
    }
    end = std::chrono::high_resolution_clock::now();
    delete (package);
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << std::endl;
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << std::endl;
    std::cout << std::chrono::duration_cast<std::chrono::seconds>(end-start).count() << std::endl;




    return 0;
}
