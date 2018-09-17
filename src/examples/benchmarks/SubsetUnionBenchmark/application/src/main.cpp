
#include <iostream>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "subsetUnionBenchmark/SubsetUnionBenchmarkFactory.hpp"
#include "subsetUnionBenchmark/SubsetUnionBenchmarkPackage.hpp"

#include "subsetUnionBenchmark/Container.hpp"
#include "subsetUnionBenchmark/Element.hpp"
#include "subsetUnionBenchmark/Element_Level1.hpp"
#include "subsetUnionBenchmark/Element_Level2.hpp"
#include "subsetUnionBenchmark/Element_Level3.hpp"
#include "subsetUnionBenchmark/Element_Level4.hpp"
#include "subsetUnionBenchmark/Element_Level5.hpp"
#include "subsetUnionBenchmark/Element_Level6.hpp"
#include "subsetUnionBenchmark/Element_Level7.hpp"
#include "subsetUnionBenchmark/Element_Level8.hpp"
#include "subsetUnionBenchmark/Element_Level9.hpp"
#include "subsetUnionBenchmark/Element_Level10.hpp"

#define TO_STR2(x) #x
#define TO_STR(x) TO_STR2(x)
#define createEl(X) std::shared_ptr< Element_Level##X > e##X = factory->createElement_Level##X(); e##X->setName("Element" TO_STR(X));        \
                    /*std::shared_ptr< Container_Level##X > c##X = factory->createContainer_Level##X(); c##X->setName("Container" TO_STR(X));*/ \
                    c->getSubset##X()->add(e##X);

#define printSubset(X)      std::cout << "Printing out subset of level " TO_STR(X) << std::endl;\
                            std::shared_ptr< Bag<subsetUnionBenchmark::Element_Level##X> > s##X = c->getSubset##X(); \
                            std::cout << "Container name: " << c->getName() << std::endl;\
                            for(auto it= s##X->begin(); it != s##X->end(); ++it){ \
                                std::cout << "Name: " << (*it)->getName() << std::endl; \
                            }\
                            std::cout << "-------------------" << std::endl;

// Start of user code includes 
// You may manually edit additional includes, won't be overwritten upon generation.

// End of user code

using namespace subsetUnionBenchmark;

// Start of user code functions 
// You may manually edit additional functions, won't be overwritten upon generation.

// End of user code

int main ()
{
	//Create Model Factory and Package
	std::shared_ptr<SubsetUnionBenchmarkFactory> factory = SubsetUnionBenchmarkFactory::eInstance();
	std::shared_ptr<SubsetUnionBenchmarkPackage> package = SubsetUnionBenchmarkPackage::eInstance();

    auto c = factory->createContainer();

    auto e = factory->createElement();
    e->setName("Element0");
    c->getUnionBag()->push_back(e);

    createEl(1)
    createEl(2)
    createEl(3)
    createEl(4)
    createEl(5)
    createEl(6)
    createEl(7)
    createEl(8)
    createEl(9)
    createEl(10)


    printSubset(1)
    printSubset(2)
    printSubset(3)
    printSubset(4)
    printSubset(5)
    printSubset(6)
    printSubset(7)
    printSubset(8)
    printSubset(9)
    printSubset(10)

    auto u = c->getUnionBag();
    std::cout << "Printing out the Union. Size: " << u->size() << std::endl;

    for(auto it= u->begin(); it != u->end(); ++it){
        std::cout << "Name: " << (*it)->getName() << std::endl;
    }
    std::cout << "-------------------" << std::endl;


// Start of user code main
// You may manually edit the following lines, won't be overwritten upon generation.

// End of user code

    return 0;

}
