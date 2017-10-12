

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
	omp_set_num_threads(1);
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

    start = std::chrono::high_resolution_clock::now();
    std::shared_ptr<EcorePackage> package=EcorePackage::eInstance();
    std::shared_ptr<EcoreFactory> factory = EcoreFactory::eInstance();
    end = std::chrono::high_resolution_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << std::endl;

    std::shared_ptr<EObject> c2 = factory->create("EClass", package);
    if (c2 != nullptr)
    {
    	std::shared_ptr<EClass> c3 = std::dynamic_pointer_cast<EClass>(c2);
    	if (c3 != nullptr)
    	{
    		std::cout << c3->eClass()->getName() << " for c3 created by typed class name" << std::endl;
    	}
    }
    // creation class instances using class name (manual given (usable for serialization or by using meta class)
    std::shared_ptr<EClass> c_metaclass = c2->eClass();
    std::cout << "class name " << c_metaclass->getName() << std::endl;
    std::shared_ptr<EObject> c4 = factory->create(c_metaclass->getName(), package);
	if (c4 != nullptr)
	{
		std::shared_ptr<EClass> c5 = std::dynamic_pointer_cast<EClass>(c4);
		if (c5 != nullptr)
		{
			std::cout << c5->eClass()->getName() << " for c5 created by name given by meta class of EClass" << std::endl;
		}
	}



	// Benchmark section
	std::shared_ptr<EClass> c = factory->createEClass_in_EPackage(package);

    c->setName("Test");


    //invoke anony getter
    start = std::chrono::high_resolution_clock::now();
    for (int var = 0; var < 10000; ++var)
    {
    	std::shared_ptr<EClass> c = factory->createEClass_in_EPackage(package);
        std::string b = boost::any_cast<std::string>(c->eGet(package->getENamedElement_Name()));
        c->setName(b);
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << std::endl;



	return 0;
}
