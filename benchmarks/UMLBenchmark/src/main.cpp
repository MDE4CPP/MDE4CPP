#include <chrono>
#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/Package.hpp"
#include "uml/Class.hpp"
#include "uml/Property.hpp"
#include "umlReflection/UMLPackage.hpp"

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;

	for (int i=0; i<1; i++){
	
    shared_ptr<uml::UmlFactory> umlFactory = uml::UmlFactory::eInstance();
    cout << "factory created " << umlFactory << endl;
    shared_ptr<UML::UMLPackage> umlPackage = UML::UMLPackage::eInstance();
    cout << "package created " << umlPackage << endl;
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
	{
		shared_ptr<uml::Package> package = umlFactory->createPackage_in_OwningPackage(umlPackage);
		cout << "package created" << endl;
		package->setName(std::string("Benchmark UML"));
		cout << package->getName() << endl;

		char buffer [33];

		start = std::chrono::high_resolution_clock::now();
		for (int i=0; i<10; i++)
		{
			shared_ptr<uml::Class> classObject = umlFactory->createClass_in_Package(package);
			classObject->setName("Class " + sprintf (buffer, "%i", i));
			shared_ptr<uml::Property> property = umlFactory->createProperty_in_Class(classObject);
			property->setName("A" + sprintf (buffer, "%i", i));
			classObject->getOwnedAttribute()->push_back(property);
		}
		end = std::chrono::high_resolution_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << std::endl;
		std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << std::endl;
		std::cout << std::chrono::duration_cast<std::chrono::seconds>(end-start).count() << std::endl;
		
		std::cout << "count: " << package->getPackagedElement()->size() << std::endl;;
		
		std::cout << "time for delete" << std::endl;
		start = std::chrono::high_resolution_clock::now();
	}
    
	end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << std::endl;
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << std::endl;
    std::cout << std::chrono::duration_cast<std::chrono::seconds>(end-start).count() << std::endl;

	}
//	Sleep( 10000000 );
    return 0;
}
