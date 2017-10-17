

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

#define NUMBER_OF_OBJECTS 50000

using namespace ecore;

int main()
{
	omp_set_num_threads(omp_get_num_procs());
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

    std::shared_ptr<EcoreFactory> factory = EcoreFactory::eInstance();

    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << std::endl;

    for (int var2 = 0; var2 < 5; ++var2)
    {
        std::cout<< "----------------------------   start next iteration  ---------------------------------------\n";
    	system("PAUSE");
        start = std::chrono::high_resolution_clock::now();
        {
        	std::shared_ptr<EPackage> p = factory->createEPackage();
			std::shared_ptr<EEnum> e = factory->createEEnum_in_EPackage(p);
			std::shared_ptr<EClass> t = factory->createEClass_in_EPackage(p);
			t->setName("AClass");

			for (int var = 0; var<=NUMBER_OF_OBJECTS; ++var)
			{
				std::shared_ptr<EClass> c = factory->createEClass_in_EPackage(p);
				std::shared_ptr<EAttribute> a = factory->createEAttribute_in_EContainingClass(c);
				std::shared_ptr<EReference> r = factory->createEReference_in_EContainingClass(c);
				std::shared_ptr<EOperation> o = factory->createEOperation_in_EContainingClass(c);
				std::shared_ptr<EParameter> p = factory->createEParameter_in_EOperation(o);

				c->setName("Class");
				e->setName("Enumeration");
				a->setName("Attribute");
				a->setEType(e);
				r->setName("Reference");
				r->setEType(t); // Use class c creates a ring dependency!
				o->setName("Operation");
				p->setName("Parameter");
				p->setEType(t);
			}

			end = std::chrono::high_resolution_clock::now();
			std::cout << "Time to create objects:" << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << std::endl;
	    	system("PAUSE");
			std::cout<< "----------- delete objects\n" << std::endl;
	        start = std::chrono::high_resolution_clock::now();
        }
    	end = std::chrono::high_resolution_clock::now();
        std::cout << "Time to delete objects: " << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << std::endl;
    }
    std::cout<< "------------------------------- Finished  ------------------------------------\n";


	return 0;
}
