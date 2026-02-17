
#include <iostream>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "subsetUnionDepth/subsetUnionDepthFactory.hpp"
#include "subsetUnionDepth/subsetUnionDepthPackage.hpp"

#include "subsetUnionDepth/Container.hpp"
#include "subsetUnionDepth/Element.hpp"
#include "subsetUnionDepth/Element_Level1.hpp"
#include "subsetUnionDepth/Container_Level1.hpp"
#include "subsetUnionDepth/Element_Level2.hpp"
#include "subsetUnionDepth/Container_Level2.hpp"
#include "subsetUnionDepth/Element_Level3.hpp"
#include "subsetUnionDepth/Container_Level3.hpp"
#include "subsetUnionDepth/Element_Level4.hpp"
#include "subsetUnionDepth/Container_Level4.hpp"
#include "subsetUnionDepth/Container_Level5.hpp"
#include "subsetUnionDepth/Element_Level5.hpp"
#include "subsetUnionDepth/Element_Level6.hpp"
#include "subsetUnionDepth/Container_Level6.hpp"
#include "subsetUnionDepth/Element_Level7.hpp"
#include "subsetUnionDepth/Container_Level7.hpp"
#include "subsetUnionDepth/Container_Level8.hpp"
#include "subsetUnionDepth/Element_Level8.hpp"
#include "subsetUnionDepth/Element_Level9.hpp"
#include "subsetUnionDepth/Container_Level9.hpp"
#include "subsetUnionDepth/Element_Level10.hpp"
#include "subsetUnionDepth/Container_Level10.hpp"

#include "ecore/EClass.hpp"

#define TO_STR2(x) #x
#define TO_STR(x) TO_STR2(x)
#define createEl(X) std::shared_ptr< Element_Level##X > e##X = factory->createElement_Level##X(); e##X->setName("Element" TO_STR(X));   \
                    c->getSubset##X()->add(e##X); \
					std::cout << "c->getSubset"<< TO_STR(X) <<"()->add(e" <<  TO_STR(X) <<"); size:" << c->getSubset##X()->size() <<std::endl; \
					std::cout << "Union size:" << c->getUnionBag()->size() <<std::endl;

#define printSubset(X)      std::cout << "Printing out subset of level " TO_STR(X) << std::endl;\
                            auto s##X = c->getSubset##X(); \
                            for(auto it= s##X->begin(); it != s##X->end(); ++it){ \
                                std::cout << "Name: " << (*it)->getName() << " Type of: " << (*it)->eClass()->getName() << std::endl; \
                            }\
                            std::cout << "-------------------" << std::endl;


// Start of user code includes 
// You may manually edit additional includes, won't be overwritten upon generation.

// End of user code

using namespace subsetUnionDepth;

// Start of user code functions 
// You may manually edit additional functions, won't be overwritten upon generation.

// End of user code

int main ()
{
	//Create Model Factory
	std::shared_ptr<subsetUnionDepthFactory> factory = subsetUnionDepthFactory::eInstance();

    std::shared_ptr< Container_Level10 > c = factory->createContainer_Level10();
    c->setName("Container10");

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
