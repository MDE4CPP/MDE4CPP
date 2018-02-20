/*MIT License

Copyright (c) 2017 TU Ilmenau, Systems and Software Engineering Group

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/*
 * Simple C++UML Example. In this example simple UML-Elements (Class, Model, Operation,...) will be created. Some model contet will be printed out followed by the informations of metamodel and meta-metamodel.
 */

#include <iostream>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/Class.hpp"
#include "uml/Model.hpp"
#include "uml/Operation.hpp"
#include "uml/InstanceSpecification.hpp"

#include "ecore/EClass.hpp"
#include "ecore/EOperation.hpp"

#include "UmlReflection/UMLPackage.hpp"

using namespace std;

int main()
{
	omp_set_num_threads(1);

    //#############  Create simple UML model  #############
    std::shared_ptr<uml::UmlFactory> factory = uml::UmlFactory::eInstance();
    std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

    std::shared_ptr<uml::Model> p = factory->createModel();
    p->setName("Model");
//
    std::shared_ptr<uml::Class> c = factory->createClass_in_Package(p);
    c->setName("Class1");
//
    //use Metamodel to create a Class
    std::shared_ptr<ecore::EObject> a = factory->create(package->getClass_EClass()->getName(), p, package->TYPE_EREFERENCE_PACKAGE);
//
    c = std::dynamic_pointer_cast<uml::Class>(a);
    c->setName("Class2");
    c->setPackage(p);

    //create an operation
    std::shared_ptr<uml::Operation> o = factory->createOperation_in_Class(c);
    o->setName("do");

    //create an UML-Objekt (InstanceSpecification) of Class2
    std::shared_ptr<uml::InstanceSpecification> i = factory->createInstanceSpecification_in_Owner(p);
    i->setName("o");
    std::shared_ptr<Bag<uml::Classifier>> t = i->getClassifier();
    t->push_back(c); //set Type to Class2

    //#############  Print model content  #############

    cout << "______________ Model ____________" << endl;
	std::shared_ptr<Bag<uml::PackageableElement>> elements = p->getPackagedElement();
    for(std::shared_ptr<uml::PackageableElement>it : *elements)
    {
        // optional type check using UML Metamodel
        std::shared_ptr<ecore::EClass> uc = uml::UmlPackage::eInstance()->getClass_EClass();
        if(it->eClass() == uc->eClass())
        {
            cout << it->getName() << " is a Class"<< endl;
            std::shared_ptr<uml::Class> itC = std::dynamic_pointer_cast<uml::Class>(it); // It is certainly an uml::Class
			std::shared_ptr<Bag<uml::Operation>> opList = itC->getOwnedOperation();
            for(std::shared_ptr<uml::Operation>it : *opList)
            {
                cout << it->getName() << endl;
            }
        }
        else
        {
            cout << it->getName() << " is a " << it->eClass()->getName() << endl;
        }
    }

    cout << "______________ Ecore MetaModel ____________" << endl;

    std::shared_ptr<ecore::EClass> mc = c->eClass(); // UML is defined with ecore
    cout << mc->getName() << " :" << endl;
	std::shared_ptr<Bag<ecore::EOperation>> opList = mc->getEAllOperations();
    for(std::shared_ptr<ecore::EOperation> it : *opList)
    {
        cout << it->getName() << endl;
    }

    cout << "___________ Ecore MetaMetaModel _______________" << endl;

    std::shared_ptr<ecore::EClass> mmc = mc->eClass();
    cout << mmc->getName() << " :" << endl;

	std::shared_ptr<Bag<ecore::EOperation>> opList2 = mmc->getEAllOperations();
    for(std::shared_ptr<ecore::EOperation> it : *opList2)
    {
        cout << it->getName() << endl;
    }

    return 0;
}
