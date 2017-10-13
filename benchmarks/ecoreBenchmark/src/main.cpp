

#include "EClass.hpp"
#include "EAnnotation.hpp"
#include "EcoreFactory.hpp"
#include "EcorePackage.hpp"
#include "EClassifier.hpp"
#include "EStructuralFeature.hpp"
#include "EReference.hpp"
#include "EAttribute.hpp"
#include "EClassifier.hpp"
#include "EStringToStringMapEntry.hpp"
#include "SubsetUnion.hpp"

#include <string>
#include <iostream>
#include <chrono>

#define NUM_ELEMENT 100000

using namespace ecore;

int main()
{
	omp_set_num_threads(1);
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

    {
		start = std::chrono::high_resolution_clock::now();
		std::shared_ptr<EcorePackage> package=EcorePackage::eInstance();
		std::shared_ptr<EcoreFactory> factory = EcoreFactory::eInstance();
		end = std::chrono::high_resolution_clock::now();

		std::cout << "setup time: " << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << std::endl;

		// Benchmark section

		// Create Elements
		{
			start = std::chrono::high_resolution_clock::now();
			for (int var = 0; var < NUM_ELEMENT; ++var)
			{
				std::shared_ptr<EClass> c = factory->createEClass_in_EPackage(package);
				c->setName(std::string("Class")+std::to_string(var));
				std::shared_ptr<EAttribute> a = factory->createEAttribute_in_EContainingClass(c);
				a->setName(std::string("a")+std::to_string(var));
            }

			end = std::chrono::high_resolution_clock::now();
			std::cout << "time to create " << NUM_ELEMENT << " classes: " <<  std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << std::endl;
		}

		// Delete Elements
		start = std::chrono::high_resolution_clock::now();
		std::shared_ptr< Bag<ecore::EClassifier> > classifiers = package->getEClassifiers();
		classifiers->clear();
		end = std::chrono::high_resolution_clock::now();
		std::cout << "time to delete " << NUM_ELEMENT << " classes: " <<  std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << std::endl;

		// Delete All
		start = std::chrono::high_resolution_clock::now();
    }
	end = std::chrono::high_resolution_clock::now();

	std::cout << "time to delete package: " <<  std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << std::endl;
    return 0;
}
