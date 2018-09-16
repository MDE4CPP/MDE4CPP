#include "subsetUnionBenchmark/impl/SubsetUnionBenchmarkPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EReference.hpp"

//metamodel factory
#include "subsetUnionBenchmark/SubsetUnionBenchmarkFactory.hpp"

//depending model packages
#include "ecore/EcorePackage.hpp"

using namespace subsetUnionBenchmark;

bool SubsetUnionBenchmarkPackageImpl::isInited = false;

SubsetUnionBenchmarkPackageImpl::SubsetUnionBenchmarkPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( SubsetUnionBenchmarkFactory::eInstance()));
}

SubsetUnionBenchmarkPackageImpl::~SubsetUnionBenchmarkPackageImpl()
{
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
    return metaModelPackage;
}

void SubsetUnionBenchmarkPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}

// Begin Class Container
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkPackageImpl::getContainer_EClass() const
{
	return m_container_EClass;
}

std::shared_ptr<ecore::EAttribute> SubsetUnionBenchmarkPackageImpl::getContainer_EAttribute_name() const
{
	return m_container_EAttribute_name;
}

std::shared_ptr<ecore::EReference> SubsetUnionBenchmarkPackageImpl::getContainer_EReference_subset1() const
{
	return m_container_EReference_subset1;
}
std::shared_ptr<ecore::EReference> SubsetUnionBenchmarkPackageImpl::getContainer_EReference_subset10() const
{
	return m_container_EReference_subset10;
}
std::shared_ptr<ecore::EReference> SubsetUnionBenchmarkPackageImpl::getContainer_EReference_subset2() const
{
	return m_container_EReference_subset2;
}
std::shared_ptr<ecore::EReference> SubsetUnionBenchmarkPackageImpl::getContainer_EReference_subset3() const
{
	return m_container_EReference_subset3;
}
std::shared_ptr<ecore::EReference> SubsetUnionBenchmarkPackageImpl::getContainer_EReference_subset4() const
{
	return m_container_EReference_subset4;
}
std::shared_ptr<ecore::EReference> SubsetUnionBenchmarkPackageImpl::getContainer_EReference_subset5() const
{
	return m_container_EReference_subset5;
}
std::shared_ptr<ecore::EReference> SubsetUnionBenchmarkPackageImpl::getContainer_EReference_subset6() const
{
	return m_container_EReference_subset6;
}
std::shared_ptr<ecore::EReference> SubsetUnionBenchmarkPackageImpl::getContainer_EReference_subset7() const
{
	return m_container_EReference_subset7;
}
std::shared_ptr<ecore::EReference> SubsetUnionBenchmarkPackageImpl::getContainer_EReference_subset8() const
{
	return m_container_EReference_subset8;
}
std::shared_ptr<ecore::EReference> SubsetUnionBenchmarkPackageImpl::getContainer_EReference_subset9() const
{
	return m_container_EReference_subset9;
}
std::shared_ptr<ecore::EReference> SubsetUnionBenchmarkPackageImpl::getContainer_EReference_unionBag() const
{
	return m_container_EReference_unionBag;
}


// End Class Container

// Begin Class Element
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkPackageImpl::getElement_EClass() const
{
	return m_element_EClass;
}

std::shared_ptr<ecore::EAttribute> SubsetUnionBenchmarkPackageImpl::getElement_EAttribute_name() const
{
	return m_element_EAttribute_name;
}



// End Class Element

// Begin Class Element_Level1
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkPackageImpl::getElement_Level1_EClass() const
{
	return m_element_Level1_EClass;
}




// End Class Element_Level1

// Begin Class Element_Level10
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkPackageImpl::getElement_Level10_EClass() const
{
	return m_element_Level10_EClass;
}




// End Class Element_Level10

// Begin Class Element_Level2
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkPackageImpl::getElement_Level2_EClass() const
{
	return m_element_Level2_EClass;
}




// End Class Element_Level2

// Begin Class Element_Level3
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkPackageImpl::getElement_Level3_EClass() const
{
	return m_element_Level3_EClass;
}




// End Class Element_Level3

// Begin Class Element_Level4
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkPackageImpl::getElement_Level4_EClass() const
{
	return m_element_Level4_EClass;
}




// End Class Element_Level4

// Begin Class Element_Level5
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkPackageImpl::getElement_Level5_EClass() const
{
	return m_element_Level5_EClass;
}




// End Class Element_Level5

// Begin Class Element_Level6
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkPackageImpl::getElement_Level6_EClass() const
{
	return m_element_Level6_EClass;
}




// End Class Element_Level6

// Begin Class Element_Level7
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkPackageImpl::getElement_Level7_EClass() const
{
	return m_element_Level7_EClass;
}




// End Class Element_Level7

// Begin Class Element_Level8
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkPackageImpl::getElement_Level8_EClass() const
{
	return m_element_Level8_EClass;
}




// End Class Element_Level8

// Begin Class Element_Level9
std::shared_ptr<ecore::EClass> SubsetUnionBenchmarkPackageImpl::getElement_Level9_EClass() const
{
	return m_element_Level9_EClass;
}




// End Class Element_Level9

