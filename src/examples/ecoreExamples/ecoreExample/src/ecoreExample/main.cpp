#include <string>
#include <iostream>
#include <chrono>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/ecoreFactory.hpp"
#include "ecore/ecorePackage.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EStructuralFeature.hpp"


using namespace ecore;

int main()
{
  std::shared_ptr<ecorePackage> package = ecorePackage::eInstance();
  std::shared_ptr<ecoreFactory> factory = ecoreFactory::eInstance();

  // Create Instances of Ecore-Elemets

  // Create EPackage instance using Factory-Operation
  std::shared_ptr<EPackage> rootPackage = factory->createEPackage(); // root-Package has no SuperPackage
  // Create EClass instance in root Package using Factory-Operation
  std::shared_ptr<EClass> c1 = factory->createEClass_in_EPackage(rootPackage);
  // Create EAttribute in class using Factory-Operation
  std::shared_ptr<EAttribute> a1 = factory->createEAttribute_in_EContainingClass(c1);

  // Set Properties of Ecore-Model Elements

  c1->setName("c1");
  a1->setName("a1");
  a1->setLowerBound(0);
  a1->setUpperBound(10);

  // Create Class instance using Name of Metaclass (usable for serialization)

  std::shared_ptr<EObject> o1 = factory->create("EClass");

  if (o1 != nullptr) {
    std::shared_ptr<EClass> c2 = std::dynamic_pointer_cast<EClass>(o1);
    if (c2 != nullptr) {
      std::cout << c2->eClass()->getName() << " for c2 created by typed class name" << std::endl;
      c2->setName("c2");
      std::shared_ptr<EAttribute> a2 = factory->createEAttribute_in_EContainingClass(c2);
      a2->setName("a2");
      // Add Class to package
      std::shared_ptr<Bag<ecore::EClassifier> > classifiers = rootPackage->getEClassifiers();
      classifiers->add(c2);
    }
  }

  // creation class instances using class ID (manual given (usable by using meta class))
  std::shared_ptr<EClass> c_metaclass = o1->eClass();
  std::cout << "class name " << c_metaclass->getName() << std::endl;
  std::shared_ptr<EObject> o2 = factory->create(c_metaclass->getClassifierID());
  if (o2 != nullptr) {
    std::shared_ptr<EClass> c3 = std::dynamic_pointer_cast<EClass>(o2);
    if (c3 != nullptr) {
      std::cout << c3->eClass()->getName() << " for c3 created by name given by meta class of EClass" << std::endl;
      c3->setName("c3");
      // Add a new Reference
      std::shared_ptr<EReference> r1 = factory->createEReference_in_EContainingClass(c3);
      r1->setName("r1");
      r1->setEType(c1);
      // Add Class to package
      std::shared_ptr<Bag<ecore::EClassifier> > classifiers = rootPackage->getEClassifiers();
      classifiers->add(c3);
    }
  }

  // Output Package content

  std::shared_ptr<Bag<ecore::EClassifier> > classifiers = rootPackage->getEClassifiers();
  Bag<ecore::EClassifier>::const_iterator endIt         = classifiers->end();
  for (Bag<ecore::EClassifier>::const_iterator it = classifiers->begin(); it != endIt; ++it) {
    std::cout << "class: " << (*it)->getName() << std::endl;
    std::shared_ptr<EClass> c = std::dynamic_pointer_cast<EClass>(*it);

    std::cout << "	Features:"<< std::endl;

    std::shared_ptr<Bag<ecore::EStructuralFeature> > structuralFeatures = c->getEAllStructuralFeatures();
    Bag<ecore::EStructuralFeature>::const_iterator endItFeature         = structuralFeatures->end();
    for (Bag<ecore::EStructuralFeature>::const_iterator itFeature = structuralFeatures->begin();
      itFeature != endItFeature;
      ++itFeature)
    {
      std::cout << "		- "<< (*itFeature)->getName() << std::endl;
    }
    std::cout << "____________" << std::endl;
  }

  std::cout << "Finished..." << std::endl;

  return 0;
} // main
