#include "SubsetUnionBenchmarkDepthPackageImpl.hpp"

//metametamodel classes
#include "EAttribute.hpp"
#include "EClass.hpp"
#include "EDataType.hpp"
#include "EEnum.hpp"
#include "EOperation.hpp"
#include "EReference.hpp"

//metamodel factory
#include "SubsetUnionBenchmarkDepthFactory.hpp"

//depending model packages
#include "EcorePackage.hpp"

using namespace subsetUnionBenchmarkDepth;

bool SubsetUnionBenchmarkDepthPackageImpl::isInited = false;

SubsetUnionBenchmarkDepthPackageImpl::SubsetUnionBenchmarkDepthPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( SubsetUnionBenchmarkDepthFactory::eInstance()));
}

SubsetUnionBenchmarkDepthPackageImpl::~SubsetUnionBenchmarkDepthPackageImpl()
{
	exampleModelEClass.reset();
	containerEClass.reset();
	elementEClass.reset();
	element_Level1EClass.reset();
	container_Level1EClass.reset();
	element_Level2EClass.reset();
	container_Level2EClass.reset();
	element_Level3EClass.reset();
	container_Level3EClass.reset();
	element_Level4EClass.reset();
	container_Level4EClass.reset();
	container_Level5EClass.reset();
	element_Level5EClass.reset();
	element_Level6EClass.reset();
	container_Level6EClass.reset();
	element_Level7EClass.reset();
	container_Level7EClass.reset();
	container_Level8EClass.reset();
	element_Level8EClass.reset();
	element_Level9EClass.reset();
	container_Level9EClass.reset();
	element_Level10EClass.reset();
	container_Level10EClass.reset();
	
	
}

SubsetUnionBenchmarkDepthPackage* SubsetUnionBenchmarkDepthPackageImpl::create()
{
	if (isInited)
	{
		return SubsetUnionBenchmarkDepthPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    SubsetUnionBenchmarkDepthPackageImpl * metaModelPackage = new SubsetUnionBenchmarkDepthPackageImpl();
	metaModelPackage->createPackageContents();
    return metaModelPackage;
}

void SubsetUnionBenchmarkDepthPackageImpl::init()
{
    // Initialize created meta-data
    initializePackageContents();   
}

void SubsetUnionBenchmarkDepthPackageImpl::createPackageContents()
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	containerEClass = createEClass(CONTAINER);
	createEAttribute(containerEClass, CONTAINER_NAME);
	
	createEReference(containerEClass, CONTAINER_UNION);
	
	

	container_Level1EClass = createEClass(CONTAINER_LEVEL1);
	
	createEReference(container_Level1EClass, CONTAINER_LEVEL1_SUBSET1);
	
	

	container_Level10EClass = createEClass(CONTAINER_LEVEL10);
	
	createEReference(container_Level10EClass, CONTAINER_LEVEL10_SUBSET10);
	
	

	container_Level2EClass = createEClass(CONTAINER_LEVEL2);
	
	createEReference(container_Level2EClass, CONTAINER_LEVEL2_SUBSET2);
	
	

	container_Level3EClass = createEClass(CONTAINER_LEVEL3);
	
	createEReference(container_Level3EClass, CONTAINER_LEVEL3_SUBSET3);
	
	

	container_Level4EClass = createEClass(CONTAINER_LEVEL4);
	
	createEReference(container_Level4EClass, CONTAINER_LEVEL4_SUBSET4);
	
	

	container_Level5EClass = createEClass(CONTAINER_LEVEL5);
	
	createEReference(container_Level5EClass, CONTAINER_LEVEL5_SUBSET5);
	
	

	container_Level6EClass = createEClass(CONTAINER_LEVEL6);
	
	createEReference(container_Level6EClass, CONTAINER_LEVEL6_SUBSET6);
	
	

	container_Level7EClass = createEClass(CONTAINER_LEVEL7);
	
	createEReference(container_Level7EClass, CONTAINER_LEVEL7_SUBSET7);
	
	

	container_Level8EClass = createEClass(CONTAINER_LEVEL8);
	
	createEReference(container_Level8EClass, CONTAINER_LEVEL8_SUBSET8);
	
	

	container_Level9EClass = createEClass(CONTAINER_LEVEL9);
	
	createEReference(container_Level9EClass, CONTAINER_LEVEL9_SUBSET9);
	
	

	elementEClass = createEClass(ELEMENT);
	createEAttribute(elementEClass, ELEMENT_NAME);
	
	
	

	element_Level1EClass = createEClass(ELEMENT_LEVEL1);
	
	
	

	element_Level10EClass = createEClass(ELEMENT_LEVEL10);
	
	
	

	element_Level2EClass = createEClass(ELEMENT_LEVEL2);
	
	
	

	element_Level3EClass = createEClass(ELEMENT_LEVEL3);
	
	
	

	element_Level4EClass = createEClass(ELEMENT_LEVEL4);
	
	
	

	element_Level5EClass = createEClass(ELEMENT_LEVEL5);
	
	
	

	element_Level6EClass = createEClass(ELEMENT_LEVEL6);
	
	
	

	element_Level7EClass = createEClass(ELEMENT_LEVEL7);
	
	
	

	element_Level8EClass = createEClass(ELEMENT_LEVEL8);
	
	
	

	element_Level9EClass = createEClass(ELEMENT_LEVEL9);
	
	
	

	exampleModelEClass = createEClass(EXAMPLEMODEL);
	
	createEReference(exampleModelEClass, EXAMPLEMODEL_CONTAINER);
	
	

	
}

void SubsetUnionBenchmarkDepthPackageImpl::initializePackageContents()
{
	if (isInitialized)
	{
		return;
	}
	isInitialized = true;

	// Initialize package
	setName(eNAME);
	setNsPrefix(eNS_PREFIX);
	setNsURI(eNS_URI);
	
	// Add supertypes to classes
	container_Level1EClass->getESuperTypes()->push_back(getContainer());
	container_Level10EClass->getESuperTypes()->push_back(getContainer_Level9());
	container_Level2EClass->getESuperTypes()->push_back(getContainer_Level1());
	container_Level3EClass->getESuperTypes()->push_back(getContainer_Level2());
	container_Level4EClass->getESuperTypes()->push_back(getContainer_Level3());
	container_Level5EClass->getESuperTypes()->push_back(getContainer_Level4());
	container_Level6EClass->getESuperTypes()->push_back(getContainer_Level5());
	container_Level7EClass->getESuperTypes()->push_back(getContainer_Level6());
	container_Level8EClass->getESuperTypes()->push_back(getContainer_Level7());
	container_Level9EClass->getESuperTypes()->push_back(getContainer_Level8());
	element_Level1EClass->getESuperTypes()->push_back(getElement());
	element_Level10EClass->getESuperTypes()->push_back(getElement_Level9());
	element_Level2EClass->getESuperTypes()->push_back(getElement_Level1());
	element_Level3EClass->getESuperTypes()->push_back(getElement_Level2());
	element_Level4EClass->getESuperTypes()->push_back(getElement_Level3());
	element_Level5EClass->getESuperTypes()->push_back(getElement_Level4());
	element_Level6EClass->getESuperTypes()->push_back(getElement_Level5());
	element_Level7EClass->getESuperTypes()->push_back(getElement_Level6());
	element_Level8EClass->getESuperTypes()->push_back(getElement_Level7());
	element_Level9EClass->getESuperTypes()->push_back(getElement_Level8());
	
	std::shared_ptr<ecore::EOperation> op;

 	// Initialize classes and features; add operations and parameters
	// Begin Class Container
	initEClass(containerEClass, nullptr, "Container", false, false, true);
	initEAttribute(getContainer_Name(),ecore::EcorePackage::eInstance()->getEString(),"name","",0,1, false,false, true, false, false, true, false, true);
	
	initEReference(getContainer_Union(),getElement(),nullptr,"union","",0,-1, false,false, true, true, true, false, true, true,true);
	
	
	// End Class Container

	// Begin Class Container_Level1
	initEClass(container_Level1EClass, nullptr, "Container_Level1", false, false, true);
	
	initEReference(getContainer_Level1_Subset1(),getElement_Level1(),nullptr,"subset1","",0,-1, false,false, true, true, true, false, true, false,true);
	
	
	// End Class Container_Level1

	// Begin Class Container_Level10
	initEClass(container_Level10EClass, nullptr, "Container_Level10", false, false, true);
	
	initEReference(getContainer_Level10_Subset10(),getElement_Level10(),nullptr,"subset10","",0,-1, false,false, true, true, true, false, true, false,true);
	
	
	// End Class Container_Level10

	// Begin Class Container_Level2
	initEClass(container_Level2EClass, nullptr, "Container_Level2", false, false, true);
	
	initEReference(getContainer_Level2_Subset2(),getElement_Level2(),nullptr,"subset2","",0,-1, false,false, true, true, true, false, true, false,true);
	
	
	// End Class Container_Level2

	// Begin Class Container_Level3
	initEClass(container_Level3EClass, nullptr, "Container_Level3", false, false, true);
	
	initEReference(getContainer_Level3_Subset3(),getElement_Level3(),nullptr,"subset3","",0,-1, false,false, true, true, true, false, true, false,true);
	
	
	// End Class Container_Level3

	// Begin Class Container_Level4
	initEClass(container_Level4EClass, nullptr, "Container_Level4", false, false, true);
	
	initEReference(getContainer_Level4_Subset4(),getElement_Level4(),nullptr,"subset4","",0,-1, false,false, true, true, true, false, true, false,true);
	
	
	// End Class Container_Level4

	// Begin Class Container_Level5
	initEClass(container_Level5EClass, nullptr, "Container_Level5", false, false, true);
	
	initEReference(getContainer_Level5_Subset5(),getElement_Level5(),nullptr,"subset5","",0,-1, false,false, true, true, true, false, true, false,true);
	
	
	// End Class Container_Level5

	// Begin Class Container_Level6
	initEClass(container_Level6EClass, nullptr, "Container_Level6", false, false, true);
	
	initEReference(getContainer_Level6_Subset6(),getElement_Level6(),nullptr,"subset6","",0,-1, false,false, true, true, true, false, true, false,true);
	
	
	// End Class Container_Level6

	// Begin Class Container_Level7
	initEClass(container_Level7EClass, nullptr, "Container_Level7", false, false, true);
	
	initEReference(getContainer_Level7_Subset7(),getElement_Level7(),nullptr,"subset7","",0,-1, false,false, true, true, true, false, true, false,true);
	
	
	// End Class Container_Level7

	// Begin Class Container_Level8
	initEClass(container_Level8EClass, nullptr, "Container_Level8", false, false, true);
	
	initEReference(getContainer_Level8_Subset8(),getElement_Level8(),nullptr,"subset8","",0,-1, false,false, true, true, true, false, true, false,true);
	
	
	// End Class Container_Level8

	// Begin Class Container_Level9
	initEClass(container_Level9EClass, nullptr, "Container_Level9", false, false, true);
	
	initEReference(getContainer_Level9_Subset9(),getElement_Level9(),nullptr,"subset9","",0,-1, false,false, true, true, true, false, true, false,true);
	
	
	// End Class Container_Level9

	// Begin Class Element
	initEClass(elementEClass, nullptr, "Element", false, false, true);
	initEAttribute(getElement_Name(),ecore::EcorePackage::eInstance()->getEString(),"name","",0,1, false,false, true, false, false, true, false, true);
	
	
	
	// End Class Element

	// Begin Class Element_Level1
	initEClass(element_Level1EClass, nullptr, "Element_Level1", false, false, true);
	
	
	
	// End Class Element_Level1

	// Begin Class Element_Level10
	initEClass(element_Level10EClass, nullptr, "Element_Level10", false, false, true);
	
	
	
	// End Class Element_Level10

	// Begin Class Element_Level2
	initEClass(element_Level2EClass, nullptr, "Element_Level2", false, false, true);
	
	
	
	// End Class Element_Level2

	// Begin Class Element_Level3
	initEClass(element_Level3EClass, nullptr, "Element_Level3", false, false, true);
	
	
	
	// End Class Element_Level3

	// Begin Class Element_Level4
	initEClass(element_Level4EClass, nullptr, "Element_Level4", false, false, true);
	
	
	
	// End Class Element_Level4

	// Begin Class Element_Level5
	initEClass(element_Level5EClass, nullptr, "Element_Level5", false, false, true);
	
	
	
	// End Class Element_Level5

	// Begin Class Element_Level6
	initEClass(element_Level6EClass, nullptr, "Element_Level6", false, false, true);
	
	
	
	// End Class Element_Level6

	// Begin Class Element_Level7
	initEClass(element_Level7EClass, nullptr, "Element_Level7", false, false, true);
	
	
	
	// End Class Element_Level7

	// Begin Class Element_Level8
	initEClass(element_Level8EClass, nullptr, "Element_Level8", false, false, true);
	
	
	
	// End Class Element_Level8

	// Begin Class Element_Level9
	initEClass(element_Level9EClass, nullptr, "Element_Level9", false, false, true);
	
	
	
	// End Class Element_Level9

	// Begin Class ExampleModel
	initEClass(exampleModelEClass, nullptr, "ExampleModel", false, false, true);
	
	initEReference(getExampleModel_Container(),getContainer(),nullptr,"container","",0,-1, false,false, true, true, true, false, true, false,true);
	
	
	// End Class ExampleModel

	
}

// Begin Class Container
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkDepthPackageImpl::getContainer() const
{
	return containerEClass;
}
std::shared_ptr<ecore::EAttribute> SubsetUnionBenchmarkDepthPackageImpl::getContainer_Name() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(containerEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> SubsetUnionBenchmarkDepthPackageImpl::getContainer_Union() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(containerEClass->getEStructuralFeatures()->at(1));
}


// End Class Container

// Begin Class Container_Level1
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkDepthPackageImpl::getContainer_Level1() const
{
	return container_Level1EClass;
}

std::shared_ptr<ecore::EReference> SubsetUnionBenchmarkDepthPackageImpl::getContainer_Level1_Subset1() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(container_Level1EClass->getEStructuralFeatures()->at(0));
}


// End Class Container_Level1

// Begin Class Container_Level10
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkDepthPackageImpl::getContainer_Level10() const
{
	return container_Level10EClass;
}

std::shared_ptr<ecore::EReference> SubsetUnionBenchmarkDepthPackageImpl::getContainer_Level10_Subset10() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(container_Level10EClass->getEStructuralFeatures()->at(0));
}


// End Class Container_Level10

// Begin Class Container_Level2
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkDepthPackageImpl::getContainer_Level2() const
{
	return container_Level2EClass;
}

std::shared_ptr<ecore::EReference> SubsetUnionBenchmarkDepthPackageImpl::getContainer_Level2_Subset2() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(container_Level2EClass->getEStructuralFeatures()->at(0));
}


// End Class Container_Level2

// Begin Class Container_Level3
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkDepthPackageImpl::getContainer_Level3() const
{
	return container_Level3EClass;
}

std::shared_ptr<ecore::EReference> SubsetUnionBenchmarkDepthPackageImpl::getContainer_Level3_Subset3() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(container_Level3EClass->getEStructuralFeatures()->at(0));
}


// End Class Container_Level3

// Begin Class Container_Level4
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkDepthPackageImpl::getContainer_Level4() const
{
	return container_Level4EClass;
}

std::shared_ptr<ecore::EReference> SubsetUnionBenchmarkDepthPackageImpl::getContainer_Level4_Subset4() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(container_Level4EClass->getEStructuralFeatures()->at(0));
}


// End Class Container_Level4

// Begin Class Container_Level5
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkDepthPackageImpl::getContainer_Level5() const
{
	return container_Level5EClass;
}

std::shared_ptr<ecore::EReference> SubsetUnionBenchmarkDepthPackageImpl::getContainer_Level5_Subset5() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(container_Level5EClass->getEStructuralFeatures()->at(0));
}


// End Class Container_Level5

// Begin Class Container_Level6
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkDepthPackageImpl::getContainer_Level6() const
{
	return container_Level6EClass;
}

std::shared_ptr<ecore::EReference> SubsetUnionBenchmarkDepthPackageImpl::getContainer_Level6_Subset6() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(container_Level6EClass->getEStructuralFeatures()->at(0));
}


// End Class Container_Level6

// Begin Class Container_Level7
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkDepthPackageImpl::getContainer_Level7() const
{
	return container_Level7EClass;
}

std::shared_ptr<ecore::EReference> SubsetUnionBenchmarkDepthPackageImpl::getContainer_Level7_Subset7() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(container_Level7EClass->getEStructuralFeatures()->at(0));
}


// End Class Container_Level7

// Begin Class Container_Level8
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkDepthPackageImpl::getContainer_Level8() const
{
	return container_Level8EClass;
}

std::shared_ptr<ecore::EReference> SubsetUnionBenchmarkDepthPackageImpl::getContainer_Level8_Subset8() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(container_Level8EClass->getEStructuralFeatures()->at(0));
}


// End Class Container_Level8

// Begin Class Container_Level9
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkDepthPackageImpl::getContainer_Level9() const
{
	return container_Level9EClass;
}

std::shared_ptr<ecore::EReference> SubsetUnionBenchmarkDepthPackageImpl::getContainer_Level9_Subset9() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(container_Level9EClass->getEStructuralFeatures()->at(0));
}


// End Class Container_Level9

// Begin Class Element
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkDepthPackageImpl::getElement() const
{
	return elementEClass;
}
std::shared_ptr<ecore::EAttribute> SubsetUnionBenchmarkDepthPackageImpl::getElement_Name() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(elementEClass->getEStructuralFeatures()->at(0));
}



// End Class Element

// Begin Class Element_Level1
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkDepthPackageImpl::getElement_Level1() const
{
	return element_Level1EClass;
}



// End Class Element_Level1

// Begin Class Element_Level10
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkDepthPackageImpl::getElement_Level10() const
{
	return element_Level10EClass;
}



// End Class Element_Level10

// Begin Class Element_Level2
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkDepthPackageImpl::getElement_Level2() const
{
	return element_Level2EClass;
}



// End Class Element_Level2

// Begin Class Element_Level3
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkDepthPackageImpl::getElement_Level3() const
{
	return element_Level3EClass;
}



// End Class Element_Level3

// Begin Class Element_Level4
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkDepthPackageImpl::getElement_Level4() const
{
	return element_Level4EClass;
}



// End Class Element_Level4

// Begin Class Element_Level5
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkDepthPackageImpl::getElement_Level5() const
{
	return element_Level5EClass;
}



// End Class Element_Level5

// Begin Class Element_Level6
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkDepthPackageImpl::getElement_Level6() const
{
	return element_Level6EClass;
}



// End Class Element_Level6

// Begin Class Element_Level7
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkDepthPackageImpl::getElement_Level7() const
{
	return element_Level7EClass;
}



// End Class Element_Level7

// Begin Class Element_Level8
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkDepthPackageImpl::getElement_Level8() const
{
	return element_Level8EClass;
}



// End Class Element_Level8

// Begin Class Element_Level9
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkDepthPackageImpl::getElement_Level9() const
{
	return element_Level9EClass;
}



// End Class Element_Level9

// Begin Class ExampleModel
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkDepthPackageImpl::getExampleModel() const
{
	return exampleModelEClass;
}

std::shared_ptr<ecore::EReference> SubsetUnionBenchmarkDepthPackageImpl::getExampleModel_Container() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(exampleModelEClass->getEStructuralFeatures()->at(0));
}


// End Class ExampleModel

