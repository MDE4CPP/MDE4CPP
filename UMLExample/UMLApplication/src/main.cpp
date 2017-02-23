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
using namespace std;

#include "uml/UmlFactory.hpp"
#include "uml/Class.hpp"
#include "uml/Model.hpp"
#include "uml/Operation.hpp"
#include "uml/InstanceSpecification.hpp"

#include "umlReflection/UMLPackage.hpp"

#include "ecore/EClass.hpp"
#include "ecore/EOperation.hpp"


int main()
{
    //#############  Create simple UML model  #############
    uml::UmlFactory *factory=uml::UmlFactory::eInstance();

    uml::Model* p=factory->createModel();
    p->setName("Modell");

    uml::Class* c=factory->createClass();
    c->setName("Class1");
    p->getPackagedElement()->push_back(c);

    //use Metamodel to create a Class
    ecore::EObject *a=factory->create(UML::UMLPackage::eInstance()->get_UML_Class()->eClass());

    c=dynamic_cast<uml::Class*>(a);
    c->setName("Class2");
    c->setPackage(p);
    p->getPackagedElement()->push_back(c);

    //create an operation
    uml::Operation* o=factory->createOperation();
    o->setName("do");
    c->getOwnedOperation()->push_back(o);

    //create an UML-Objekt (InstanceSpecification) of Class2
    uml::InstanceSpecification* i=factory->createInstanceSpecification();
    i->setName("o");
    std::vector<uml::Classifier * > *t=i->getClassifier();
    t->push_back(c); //set Type to Class2
    p->getPackagedElement()->push_back(i);

    //#############  Print model content  #############

    cout << "______________ Model ____________" << endl;

    for(uml::PackageableElement *it :*p->getPackagedElement())
    {
        // optional type check using UML Metamodel
        uml::Class* uc=UML::UMLPackage::eInstance()->get_UML_Class();
        if(it->eClass() == uc->eClass())
        {
            cout << it->getName() << " is a Class"<< endl;
            uml::Class* itC=dynamic_cast<uml::Class*> (it); // It is certainly an uml::Class
            for(uml::Operation *it :*itC->getOwnedOperation())
            {
                cout << it->getName() << endl;
            }
        }
        else
        {
            cout << it->getName() << " ia a " << it->eClass()->getName() << endl;
        }
    }

    cout << "______________ MetaModel ____________" << endl;

    ecore::EClass *mc = c->eClass(); // UML is defined with ecore
    cout << mc->getName() << " :" << endl;
    for(ecore::EOperation * it :*mc->getEAllOperations())
    {
        cout << it->getName() << endl;
    }

    cout << "___________ MetaMetaModel _______________" << endl;

    ecore::EClass *mmc = mc->eClass();
    cout << mmc->getName() << " :" << endl;

    for(ecore::EOperation * it :*mmc->getEAllOperations())
    {
        cout << it->getName() << endl;
    }

    return 0;
}
