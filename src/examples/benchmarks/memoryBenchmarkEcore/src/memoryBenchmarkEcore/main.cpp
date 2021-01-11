#include <string>
#include <iostream>
#include <chrono>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/ecoreFactory.hpp"
#include "ecore/impl/ecoreFactoryImpl.hpp"
#include "ecore/ecorePackage.hpp"
#include "ecore/impl/ecorePackageImpl.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EStructuralFeature.hpp"


#define NUMBER_OF_OBJECTS 50000

using namespace ecore;

int main()
{
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

    std::shared_ptr<ecoreFactory> factory = ecoreFactory::eInstance();

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
