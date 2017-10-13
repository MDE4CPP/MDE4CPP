

#include "EClass.hpp"
#include "EAnnotation.hpp"
#include "EcoreFactory.hpp"
#include "EcorePackage.hpp"
#include "EClassifier.hpp"
#include "EStructuralFeature.hpp"
#include "EAttribute.hpp"
#include "EReference.hpp"
#include "EStringToStringMapEntry.hpp"

#include <string>
#include <iostream>
#include <chrono>



using namespace ecore;

int main()
{
	omp_set_num_threads(1);
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

    start = std::chrono::high_resolution_clock::now();
    std::shared_ptr<EcorePackage> package=EcorePackage::eInstance();
    std::shared_ptr<EcoreFactory> factory = EcoreFactory::eInstance();
    end = std::chrono::high_resolution_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << std::endl;

    //Create Instances of Ecore-Elemets

    //Create EPackage instance using Factory-Operation
	std::shared_ptr<EPackage> rootPackage = factory->createEPackage_in_ESuperPackage(std::shared_ptr<ecore::EPackage>()); // root-Package has no SuperPackage
	//Create EClass instance in root Package using Factory-Operation
    std::shared_ptr<EClass> c1 = factory->createEClass_in_EPackage(rootPackage);
	//Create EAttribute in class using Factory-Operation
    std::shared_ptr<EAttribute> a1 = factory->createEAttribute_in_EContainingClass(c1);

    //Set Properties of Ecore-Model Elements

    c1->setName("c1");
    a1->setName("a1");
    a1->setLowerBound(0);
    a1->setUpperBound(10);

    //Create Class instance using Name of Metaclass

    std::shared_ptr<EObject> o1 = factory->create("EClass");

    if (o1 != nullptr)
    {
    	std::shared_ptr< Bag<ecore::EClassifier> > classifiers = rootPackage->getEClassifiers();
    	std::shared_ptr<EClass> c2 = std::dynamic_pointer_cast<EClass>(o1);
    	if (c2 != nullptr)
    	{
    		std::cout << c2->eClass()->getName() << " for c3 created by typed class name" << std::endl;
    		classifiers->add(c2);
    	}
    }


    // creation class instances using class name (manual given (usable for serialization or by using meta class)
    std::shared_ptr<EClass> c_metaclass = o1->eClass();
    std::cout << "class name " << c_metaclass->getName() << std::endl;
    std::shared_ptr<EObject> c4 = factory->create(c_metaclass->getName());
	if (c4 != nullptr)
	{
		std::shared_ptr<EClass> c5 = std::dynamic_pointer_cast<EClass>(c4);
		if (c5 != nullptr)
		{
			std::cout << c5->eClass()->getName() << " for c5 created by name given by meta class of EClass" << std::endl;
		}
	}



	// Benchmark section
	std::shared_ptr<EClass> c = factory->createEClass_in_EPackage(rootPackage);

    c->setName("Test");


    //invoke anony getter
    start = std::chrono::high_resolution_clock::now();
    for (int var = 0; var < 10000; ++var)
    {
    	std::shared_ptr<EClass> c = factory->createEClass_in_EPackage(rootPackage);
        std::string b = boost::any_cast<std::string>(c->eGet(package->getENamedElement_Name()));
        c->setName(b);
        c.reset();
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << std::endl;
    //qDebug()<<b;



	return 0;
}
