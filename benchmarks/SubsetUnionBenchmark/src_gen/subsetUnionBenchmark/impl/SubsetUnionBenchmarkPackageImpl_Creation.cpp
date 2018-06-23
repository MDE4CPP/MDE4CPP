#include "subsetUnionBenchmark/impl/SubsetUnionBenchmarkPackageImpl.hpp"

// metametamodel factory
#include "ecore/EcoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EReference.hpp"

//depending model packages
#include "ecore/EcorePackage.hpp"

using namespace subsetUnionBenchmark;

void SubsetUnionBenchmarkPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::EcoreFactory> factory = ecore::EcoreFactory::eInstance();

	createContainerContent(package, factory);
	createElementContent(package, factory);
	createElement_Level1Content(package, factory);
	createElement_Level10Content(package, factory);
	createElement_Level2Content(package, factory);
	createElement_Level3Content(package, factory);
	createElement_Level4Content(package, factory);
	createElement_Level5Content(package, factory);
	createElement_Level6Content(package, factory);
	createElement_Level7Content(package, factory);
	createElement_Level8Content(package, factory);
	createElement_Level9Content(package, factory);

	createPackageEDataTypes(package, factory);
}

void SubsetUnionBenchmarkPackageImpl::createContainerContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_container_EClass = factory->createEClass_in_EPackage(package, CONTAINER_ECLASS);
	m_container_EAttribute_name = factory->createEAttribute_in_EContainingClass(m_container_EClass, CONTAINER_EATTRIBUTE_NAME);
	
	m_container_EReference_subset1 = factory->createEReference_in_EContainingClass(m_container_EClass, CONTAINER_EREFERENCE_SUBSET1);
	m_container_EReference_subset10 = factory->createEReference_in_EContainingClass(m_container_EClass, CONTAINER_EREFERENCE_SUBSET10);
	m_container_EReference_subset2 = factory->createEReference_in_EContainingClass(m_container_EClass, CONTAINER_EREFERENCE_SUBSET2);
	m_container_EReference_subset3 = factory->createEReference_in_EContainingClass(m_container_EClass, CONTAINER_EREFERENCE_SUBSET3);
	m_container_EReference_subset4 = factory->createEReference_in_EContainingClass(m_container_EClass, CONTAINER_EREFERENCE_SUBSET4);
	m_container_EReference_subset5 = factory->createEReference_in_EContainingClass(m_container_EClass, CONTAINER_EREFERENCE_SUBSET5);
	m_container_EReference_subset6 = factory->createEReference_in_EContainingClass(m_container_EClass, CONTAINER_EREFERENCE_SUBSET6);
	m_container_EReference_subset7 = factory->createEReference_in_EContainingClass(m_container_EClass, CONTAINER_EREFERENCE_SUBSET7);
	m_container_EReference_subset8 = factory->createEReference_in_EContainingClass(m_container_EClass, CONTAINER_EREFERENCE_SUBSET8);
	m_container_EReference_subset9 = factory->createEReference_in_EContainingClass(m_container_EClass, CONTAINER_EREFERENCE_SUBSET9);
	m_container_EReference_union = factory->createEReference_in_EContainingClass(m_container_EClass, CONTAINER_EREFERENCE_UNION);
	
	
}

void SubsetUnionBenchmarkPackageImpl::createElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_element_EClass = factory->createEClass_in_EPackage(package, ELEMENT_ECLASS);
	m_element_EAttribute_name = factory->createEAttribute_in_EContainingClass(m_element_EClass, ELEMENT_EATTRIBUTE_NAME);
	
	
	
}

void SubsetUnionBenchmarkPackageImpl::createElement_Level1Content(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_element_Level1_EClass = factory->createEClass_in_EPackage(package, ELEMENT_LEVEL1_ECLASS);
	
	
	
}

void SubsetUnionBenchmarkPackageImpl::createElement_Level10Content(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_element_Level10_EClass = factory->createEClass_in_EPackage(package, ELEMENT_LEVEL10_ECLASS);
	
	
	
}

void SubsetUnionBenchmarkPackageImpl::createElement_Level2Content(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_element_Level2_EClass = factory->createEClass_in_EPackage(package, ELEMENT_LEVEL2_ECLASS);
	
	
	
}

void SubsetUnionBenchmarkPackageImpl::createElement_Level3Content(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_element_Level3_EClass = factory->createEClass_in_EPackage(package, ELEMENT_LEVEL3_ECLASS);
	
	
	
}

void SubsetUnionBenchmarkPackageImpl::createElement_Level4Content(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_element_Level4_EClass = factory->createEClass_in_EPackage(package, ELEMENT_LEVEL4_ECLASS);
	
	
	
}

void SubsetUnionBenchmarkPackageImpl::createElement_Level5Content(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_element_Level5_EClass = factory->createEClass_in_EPackage(package, ELEMENT_LEVEL5_ECLASS);
	
	
	
}

void SubsetUnionBenchmarkPackageImpl::createElement_Level6Content(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_element_Level6_EClass = factory->createEClass_in_EPackage(package, ELEMENT_LEVEL6_ECLASS);
	
	
	
}

void SubsetUnionBenchmarkPackageImpl::createElement_Level7Content(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_element_Level7_EClass = factory->createEClass_in_EPackage(package, ELEMENT_LEVEL7_ECLASS);
	
	
	
}

void SubsetUnionBenchmarkPackageImpl::createElement_Level8Content(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_element_Level8_EClass = factory->createEClass_in_EPackage(package, ELEMENT_LEVEL8_ECLASS);
	
	
	
}

void SubsetUnionBenchmarkPackageImpl::createElement_Level9Content(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_element_Level9_EClass = factory->createEClass_in_EPackage(package, ELEMENT_LEVEL9_ECLASS);
	
	
	
}

void SubsetUnionBenchmarkPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	
}
