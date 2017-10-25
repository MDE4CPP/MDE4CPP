
#include <iostream>
#include "SubsetUnionBenchmarkDepthFactory.hpp"
#include "SubsetUnionBenchmarkDepthPackage.hpp"

#include "ExampleModel.hpp"
#include "Container.hpp"
#include "Element.hpp"
#include "Element_Level1.hpp"
#include "Container_Level1.hpp"
#include "Element_Level2.hpp"
#include "Container_Level2.hpp"
#include "Element_Level3.hpp"
#include "Container_Level3.hpp"
#include "Element_Level4.hpp"
#include "Container_Level4.hpp"
#include "Container_Level5.hpp"
#include "Element_Level5.hpp"
#include "Element_Level6.hpp"
#include "Container_Level6.hpp"
#include "Element_Level7.hpp"
#include "Container_Level7.hpp"
#include "Container_Level8.hpp"
#include "Element_Level8.hpp"
#include "Element_Level9.hpp"
#include "Container_Level9.hpp"
#include "Element_Level10.hpp"
#include "Container_Level10.hpp"

// Start of user code includes
// You may manually edit additional includes, won't be overwritten upon generation.
#include <chrono>

#define TO_STR2(x) #x
#define TO_STR(x) TO_STR2(x)
#define createEl(X) std::shared_ptr< Element_Level##X > e##X = factory->createElement_Level##X(); e##X->setName("Element" TO_STR(X));        \
                    std::shared_ptr< Container_Level##X > c##X = factory->createContainer_Level##X(); c##X->setName("Container" TO_STR(X)); \
                    c##X->getSubset##X()->add(e##X);

#define printSubset(X)      {std::cout << "Printing out subset of level " TO_STR(X) << std::endl; \
                            std::shared_ptr< Bag<subsetUnionBenchmarkDepth::Element_Level##X> > s##X = c##X->getSubset##X(); \
                            std::cout << "Container name: " << c##X->getName() << std::endl;\
                            for(auto it= s##X->begin(); it != s##X->end(); ++it){ \
                                std::cout << "Name: " << (*it)->getName() << std::endl; \
                            }\
                            std::cout << "-------------------" << std::endl;}

#define printS(X,Y) { std::cout << "C" TO_STR(Y) << " - Subset Level: " TO_STR(X) <<  std::endl; \
                            std::shared_ptr< Bag<subsetUnionBenchmarkDepth::Element_Level##X> > ss##X = c##Y->getSubset##X(); \
                            for(auto it= ss##X->begin(); it != ss##X->end(); ++it){\
                                std::cout << "Name: " << (*it)->getName() << std::endl;\
                            }\
                            std::cout << "-------------------" << std::endl;}

#define createElAtLevel(X) start = std::chrono::high_resolution_clock::now();\
                            for(unsigned i =0; i<elCount; i++)\
                            {\
                                auto el = factory->createElement_Level##X();\
                                el->setName("C10_Subset" TO_STR(X));\
                                c10->getSubset##X()->add(el);\
                            }\
                            end = std::chrono::high_resolution_clock::now();\
                            std::cout << elCount <<" elements in C10, in subset at level " TO_STR(X) ": " << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << " microseconds" << std::endl;
// End of user code

using namespace subsetUnionBenchmarkDepth;

// Start of user code functions
// You may manually edit additional functions, won't be overwritten upon generation.
void getElements(){

}

void merge(std::shared_ptr<Container> c1, std::shared_ptr<Container> c2){
    auto u = c1->getUnion();
    for (auto it = u->begin(); it != u->end(); ++it) {
        if(c2->getUnion()->find(*it) < 0){
            c2->getUnion()->push_back(*it);
        }
    }
}
// End of user code

int main ()
{
	//Create Model Factory and Package
	std::shared_ptr<SubsetUnionBenchmarkDepthFactory> factory = SubsetUnionBenchmarkDepthFactory::eInstance();
	std::shared_ptr<SubsetUnionBenchmarkDepthPackage> package = SubsetUnionBenchmarkDepthPackage::eInstance();

// Start of user code main
// You may manually edit the following lines, won't be overwritten upon generation.
    omp_set_num_threads(11);
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

        start = std::chrono::high_resolution_clock::now();
        auto m = factory->createExampleModel();
        auto c = factory->createContainer();
        m->getContainer()->push_back(c);

        auto e = factory->createElement();
        e->setName("Element0");
        c->getUnion()->push_back(e);

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

        end = std::chrono::high_resolution_clock::now();
        std::cout << "Creation time: " << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << " microseconds"  << std::endl;
/*
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
        */

     /*   printS(9,10);
        printS(8,10);
        printS(7,10);
        printS(6,10);
        printS(5,10);
        printS(4,10);
        printS(3,10);
        printS(2,10);
        printS(1,10);


    printS(4,5);
    printS(3,5);
    printS(2,5);
    printS(1,5);*/



       /* start = std::chrono::high_resolution_clock::now();
        auto u = c->getUnion();
        end = std::chrono::high_resolution_clock::now();
        std::cout << "Get Union: " << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << "ms" << std::endl;
*/

        /*std::cout << "Printing out the Union. Size: " << u->size() << std::endl;

        for (auto it = u->begin(); it != u->end(); ++it) {
            std::cout << "Name: " << (*it)->getName() << std::endl;
        }
        std::cout << "-------------------" << std::endl;
        */

        /*auto ss9 = c10->getSubset9();

        std::cout << "Container name: " << c10->getName() << " - SIZE: "<< ss9->size() <<  std::endl;


        for(auto it= ss9->begin(); it != ss9->end(); ++it){
            std::cout << "Name: " << (*it)->getName() << std::endl;
        }
        std::cout << "-------------------" << std::endl;*/

        /*auto c2 = factory->createContainer();
        c2->getUnion()->push_back(e3);

        std::cout << "Merge C2 und C" << std::endl;
        merge(c,c2);

        auto u2 = c2->getUnion();
        for (auto it = u2->begin(); it != u2->end(); ++it) {
            std::cout << "Name: " << (*it)->getName() << std::endl;
        }
        std::cout << "-------------------" << std::endl;*/

    const unsigned int elCount = 1000000;
   // std::vector<std::shared_ptr<subsetUnionBenchmarkDepth::Element_Level10 > > v = new std::vector<subsetUnionBenchmarkDepth::Element_Level10>();

/*
    createElAtLevel(1);
    createElAtLevel(2);
    createElAtLevel(3);
    createElAtLevel(4);
    createElAtLevel(5);
    createElAtLevel(6);
    createElAtLevel(7);
    createElAtLevel(8);
    createElAtLevel(9);
    createElAtLevel(10);
    */

    createElAtLevel(10);
    createElAtLevel(9);
    createElAtLevel(8);
    createElAtLevel(7);
    createElAtLevel(6);
    createElAtLevel(5);
    createElAtLevel(4);
    createElAtLevel(3);
    createElAtLevel(2);
    createElAtLevel(1);



    start = std::chrono::high_resolution_clock::now();
    auto u = c10->getUnion();
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Get Union: " << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << " microseconds"  << std::endl;
    std::cout << "C10 Union contains "<<u->size() << " elements";


    std::cout << "-Finished";
    exit(0);
/*
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
*/
    //printS(9,10);
    //printS(8,10);
    //printS(7,10);
    //printS(6,10);
    //printS(5,10);
    //printS(4,10);
    //printS(3,10);
    //printS(2,10);
    //printS(1,10);

    /*start = std::chrono::high_resolution_clock::now();
    for(unsigned int i=0; i< 100; i++){
        auto newContainer = factory->createContainer();
        m->getContainer()->push_back(newContainer);
        merge(c, newContainer);
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Merge: " << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << "ms" << std::endl;

    std::cout << "Result of the Merge" << std::endl;
              auto containers = m->getContainer();
    for (auto it2 = containers->begin(); it2 != containers->end(); ++it2) {
        auto u = (*it2)->getUnion();
        for (auto it = u->begin(); it != u->end(); ++it) {
            std::cout << "Name: " << (*it)->getName() << std::endl;
        }
    }
*/
    //std::cout << "-------------------" << std::endl;



// End of user code

    return 0;

}
