#include "SubsetUnionBenchmarkPackageImpl.hpp"

//metametamodel classes
#include "EAttribute.hpp"
#include "EClass.hpp"
#include "EDataType.hpp"
#include "EEnum.hpp"
#include "EOperation.hpp"
#include "EReference.hpp"

//metamodel factory
#include "SubsetUnionBenchmarkFactory.hpp"

//depending model packages
#include "EcorePackage.hpp"

using namespace subsetUnionBenchmark;

bool SubsetUnionBenchmarkPackageImpl::isInited = false;

SubsetUnionBenchmarkPackageImpl::SubsetUnionBenchmarkPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( SubsetUnionBenchmarkFactory::eInstance()));
}

SubsetUnionBenchmarkPackageImpl::~SubsetUnionBenchmarkPackageImpl()
{
	containerEClass.reset();
	elementEClass.reset();
	element_Level1EClass.reset();
	element_Level2EClass.reset();
	element_Level3EClass.reset();
	element_Level4EClass.reset();
	element_Level5EClass.reset();
	element_Level6EClass.reset();
	element_Level7EClass.reset();
	element_Level8EClass.reset();
	element_Level9EClass.reset();
	element_Level10EClass.reset();
	
	
}

SubsetUnionBenchmarkPackage* SubsetUnionBenchmarkPackageImpl::create()
{
	if (isInited)
	{
		return SubsetUnionBenchmarkPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    SubsetUnionBenchmarkPackageImpl * metaModelPackage = new SubsetUnionBenchmarkPackageImpl();
	metaModelPackage->createPackageContents();
    return metaModelPackage;
}

void SubsetUnionBenchmarkPackageImpl::init()
{
    // Initialize created meta-data
    initializePackageContents();   
}

void SubsetUnionBenchmarkPackageImpl::createPackageContents()
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	containerEClass = createEClass(CONTAINER);
	createEAttribute(containerEClass, CONTAINER_NAME);
	
	createEReference(containerEClass, CONTAINER_SUBSET1);
	createEReference(containerEClass, CONTAINER_SUBSET10);
	createEReference(containerEClass, CONTAINER_SUBSET2);
	createEReference(containerEClass, CONTAINER_SUBSET3);
	createEReference(containerEClass, CONTAINER_SUBSET4);
	createEReference(containerEClass, CONTAINER_SUBSET5);
	createEReference(containerEClass, CONTAINER_SUBSET6);
	createEReference(containerEClass, CONTAINER_SUBSET7);
	createEReference(containerEClass, CONTAINER_SUBSET8);
	createEReference(containerEClass, CONTAINER_SUBSET9);
	createEReference(containerEClass, CONTAINER_UNION);
	
	

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
	
	
	

	
}

void SubsetUnionBenchmarkPackageImpl::initializePackageContents()
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
	element_Level1EClass->getESuperTypes()->push_back(getElement());
	element_Level10EClass->getESuperTypes()->push_back(getElement());
	element_Level2EClass->getESuperTypes()->push_back(getElement());
	element_Level3EClass->getESuperTypes()->push_back(getElement());
	element_Level4EClass->getESuperTypes()->push_back(getElement());
	element_Level5EClass->getESuperTypes()->push_back(getElement());
	element_Level6EClass->getESuperTypes()->push_back(getElement());
	element_Level7EClass->getESuperTypes()->push_back(getElement());
	element_Level8EClass->getESuperTypes()->push_back(getElement());
	element_Level9EClass->getESuperTypes()->push_back(getElement());
	
	std::shared_ptr<ecore::EOperation> op;

 	// Initialize classes and features; add operations and parameters
	// Begin Class Container
	initEClass(containerEClass, nullptr, "Container", false, false, true);
	initEAttribute(getContainer_Name(),ecore::EcorePackage::eInstance()->getEString(),"name","",0,1, false,false, true, false, false, true, false, true);
	
	initEReference(getContainer_Subset1(),getElement_Level1(),nullptr,"subset1","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getContainer_Subset10(),getElement_Level10(),nullptr,"subset10","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getContainer_Subset2(),getElement_Level2(),nullptr,"subset2","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getContainer_Subset3(),getElement_Level3(),nullptr,"subset3","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getContainer_Subset4(),getElement_Level4(),nullptr,"subset4","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getContainer_Subset5(),getElement_Level5(),nullptr,"subset5","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getContainer_Subset6(),getElement_Level6(),nullptr,"subset6","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getContainer_Subset7(),getElement_Level7(),nullptr,"subset7","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getContainer_Subset8(),getElement_Level8(),nullptr,"subset8","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getContainer_Subset9(),getElement_Level9(),nullptr,"subset9","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getContainer_Union(),getElement(),nullptr,"union","",0,-1, false,false, true, true, true, false, true, true,true);
	
	
	// End Class Container

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

	
}

// Begin Class Container
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkPackageImpl::getContainer() const
{
	return containerEClass;
}
std::shared_ptr<ecore::EAttribute> SubsetUnionBenchmarkPackageImpl::getContainer_Name() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(containerEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> SubsetUnionBenchmarkPackageImpl::getContainer_Subset1() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(containerEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> SubsetUnionBenchmarkPackageImpl::getContainer_Subset10() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(containerEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> SubsetUnionBenchmarkPackageImpl::getContainer_Subset2() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(containerEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> SubsetUnionBenchmarkPackageImpl::getContainer_Subset3() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(containerEClass->getEStructuralFeatures()->at(4));
}
std::shared_ptr<ecore::EReference> SubsetUnionBenchmarkPackageImpl::getContainer_Subset4() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(containerEClass->getEStructuralFeatures()->at(5));
}
std::shared_ptr<ecore::EReference> SubsetUnionBenchmarkPackageImpl::getContainer_Subset5() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(containerEClass->getEStructuralFeatures()->at(6));
}
std::shared_ptr<ecore::EReference> SubsetUnionBenchmarkPackageImpl::getContainer_Subset6() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(containerEClass->getEStructuralFeatures()->at(7));
}
std::shared_ptr<ecore::EReference> SubsetUnionBenchmarkPackageImpl::getContainer_Subset7() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(containerEClass->getEStructuralFeatures()->at(8));
}
std::shared_ptr<ecore::EReference> SubsetUnionBenchmarkPackageImpl::getContainer_Subset8() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(containerEClass->getEStructuralFeatures()->at(9));
}
std::shared_ptr<ecore::EReference> SubsetUnionBenchmarkPackageImpl::getContainer_Subset9() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(containerEClass->getEStructuralFeatures()->at(10));
}
std::shared_ptr<ecore::EReference> SubsetUnionBenchmarkPackageImpl::getContainer_Union() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(containerEClass->getEStructuralFeatures()->at(11));
}


// End Class Container

// Begin Class Element
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkPackageImpl::getElement() const
{
	return elementEClass;
}
std::shared_ptr<ecore::EAttribute> SubsetUnionBenchmarkPackageImpl::getElement_Name() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(elementEClass->getEStructuralFeatures()->at(0));
}



// End Class Element

// Begin Class Element_Level1
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkPackageImpl::getElement_Level1() const
{
	return element_Level1EClass;
}



// End Class Element_Level1

// Begin Class Element_Level10
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkPackageImpl::getElement_Level10() const
{
	return element_Level10EClass;
}



// End Class Element_Level10

// Begin Class Element_Level2
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkPackageImpl::getElement_Level2() const
{
	return element_Level2EClass;
}



// End Class Element_Level2

// Begin Class Element_Level3
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkPackageImpl::getElement_Level3() const
{
	return element_Level3EClass;
}



// End Class Element_Level3

// Begin Class Element_Level4
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkPackageImpl::getElement_Level4() const
{
	return element_Level4EClass;
}



// End Class Element_Level4

// Begin Class Element_Level5
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkPackageImpl::getElement_Level5() const
{
	return element_Level5EClass;
}



// End Class Element_Level5

// Begin Class Element_Level6
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkPackageImpl::getElement_Level6() const
{
	return element_Level6EClass;
}



// End Class Element_Level6

// Begin Class Element_Level7
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkPackageImpl::getElement_Level7() const
{
	return element_Level7EClass;
}



// End Class Element_Level7

// Begin Class Element_Level8
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkPackageImpl::getElement_Level8() const
{
	return element_Level8EClass;
}



// End Class Element_Level8

// Begin Class Element_Level9
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkPackageImpl::getElement_Level9() const
{
	return element_Level9EClass;
}



// End Class Element_Level9

