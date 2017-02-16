#include "UmlPackage.hpp"
#include "UmlFactory.hpp"
#include "EcorePackage.hpp"
#include "Model.hpp"

#include "Constraint.hpp"

#include "Class.hpp"
#include "Property.hpp"
#include "Stereotype.hpp"
#include "Extension.hpp"
#include <iostream>


int main(int argc, char *argv[])
{

    //ecore::EcorePackage * pac2 = ecore::EcorePackage::eInstance();
    //uml::UmlPackage * pac = uml::UmlPackage::eInstance();
    uml::UmlFactory * fac = uml::UmlFactory::eInstance();
    uml::Model * model = fac->createModel();
    model->setName("MyModel");

    uml::Class * metaClass = fac->createClass();
    metaClass->setName("Class");

    uml::Class * c = fac->createClass();
    c->setName("Test");

    uml::Constraint * con = fac->createConstraint();
    con->setContext(c->getNamespace());

    c->setPackage(model);
    model->getPackagedElement()->push_back(c);

    uml::Stereotype * s = fac->createStereotype();
    uml::Property * bp = fac->createProperty();
    uml::Extension * ex = fac->createExtension();
    bp->setAssociation(ex);
    bp->setName("base_Class");
    bp->setType(metaClass);

    s->getOwnedAttribute()->push_back(bp);
    c->applyStereotype(s);

    std::cout << bp->getQualifiedName() << std::endl;



    std::cout << "End" << std::endl;
    return 0;
}
