

#include "EClass.hpp"
#include "EAnnotation.hpp"
#include "EcoreFactory.hpp"
#include "EcorePackage.hpp"
#include "EClassifier.hpp"
#include "impl/EcorePackageImpl.hpp"
#include "EStructuralFeature.hpp"
#include "EReference.hpp"
#include "EStringToStringMapEntry.hpp"
#include "impl/EcoreFactoryImpl.hpp"

#include <string>
#include <iostream>
#include <chrono>



using namespace ecore;

int main()
{
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

    start = std::chrono::high_resolution_clock::now();
    EcorePackage* package=EcorePackage::eInstance();
    EcoreFactory* factory=EcoreFactory::eInstance();
    end = std::chrono::high_resolution_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << std::endl;


    EClass * c = factory->createEClass();

    c->setName("Test");


    //invoke anony getter
    start = std::chrono::high_resolution_clock::now();
    for (int var = 0; var < 10000; ++var)
    {
        ecore::EClass* c = factory->createEClass();
        std::string b = boost::any_cast<std::string>(c->eGet(package->getENamedElement_Name()));
        c->setName(b);
        delete(c);
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << std::endl;
    //qDebug()<<b;




}
