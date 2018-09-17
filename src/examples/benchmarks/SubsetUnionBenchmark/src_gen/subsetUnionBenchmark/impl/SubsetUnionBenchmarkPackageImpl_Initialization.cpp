#include "subsetUnionBenchmark/impl/SubsetUnionBenchmarkPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EReference.hpp"

// metametamodel factory
#include "ecore/EcoreFactory.hpp"

//depending model packages
#include "ecore/EcorePackage.hpp"

using namespace subsetUnionBenchmark;

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
	m_element_Level1_EClass->getESuperTypes()->push_back(getElement_EClass());
	m_element_Level10_EClass->getESuperTypes()->push_back(getElement_EClass());
	m_element_Level2_EClass->getESuperTypes()->push_back(getElement_EClass());
	m_element_Level3_EClass->getESuperTypes()->push_back(getElement_EClass());
	m_element_Level4_EClass->getESuperTypes()->push_back(getElement_EClass());
	m_element_Level5_EClass->getESuperTypes()->push_back(getElement_EClass());
	m_element_Level6_EClass->getESuperTypes()->push_back(getElement_EClass());
	m_element_Level7_EClass->getESuperTypes()->push_back(getElement_EClass());
	m_element_Level8_EClass->getESuperTypes()->push_back(getElement_EClass());
	m_element_Level9_EClass->getESuperTypes()->push_back(getElement_EClass());
	

 	// Initialize classes and features; add operations and parameters
	initializeContainerContent();
	initializeElementContent();
	initializeElement_Level1Content();
	initializeElement_Level10Content();
	initializeElement_Level2Content();
	initializeElement_Level3Content();
	initializeElement_Level4Content();
	initializeElement_Level5Content();
	initializeElement_Level6Content();
	initializeElement_Level7Content();
	initializeElement_Level8Content();
	initializeElement_Level9Content();

	initializePackageEDataTypes();
}

void SubsetUnionBenchmarkPackageImpl::initializeContainerContent()
{
	m_container_EClass->setName("Container");
	m_container_EClass->setAbstract(false);
	m_container_EClass->setInterface(false);
	
	m_container_EAttribute_name = getContainer_EAttribute_name();
	m_container_EAttribute_name->setName("name");
	m_container_EAttribute_name->setEType(ecore::EcorePackage::eInstance()->getEString_EDataType());
	m_container_EAttribute_name->setLowerBound(0);
	m_container_EAttribute_name->setUpperBound(1);
	m_container_EAttribute_name->setTransient(false);
	m_container_EAttribute_name->setVolatile(false);
	m_container_EAttribute_name->setChangeable(true);
	m_container_EAttribute_name->setUnsettable(false);
	m_container_EAttribute_name->setUnique(true);
	m_container_EAttribute_name->setDerived(false);
	m_container_EAttribute_name->setOrdered(true);
	m_container_EAttribute_name->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_container_EAttribute_name->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_container_EReference_subset1->setName("subset1");
	m_container_EReference_subset1->setEType(getElement_Level1_EClass());
	m_container_EReference_subset1->setLowerBound(0);
	m_container_EReference_subset1->setUpperBound(-1);
	m_container_EReference_subset1->setTransient(false);
	m_container_EReference_subset1->setVolatile(false);
	m_container_EReference_subset1->setChangeable(true);
	m_container_EReference_subset1->setUnsettable(false);
	m_container_EReference_subset1->setUnique(true);
	m_container_EReference_subset1->setDerived(false);
	m_container_EReference_subset1->setOrdered(true);
	m_container_EReference_subset1->setContainment(true);
	m_container_EReference_subset1->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_container_EReference_subset1->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_container_EReference_subset1->setEOpposite(otherEnd);
	    }
	}
	m_container_EReference_subset10->setName("subset10");
	m_container_EReference_subset10->setEType(getElement_Level10_EClass());
	m_container_EReference_subset10->setLowerBound(0);
	m_container_EReference_subset10->setUpperBound(-1);
	m_container_EReference_subset10->setTransient(false);
	m_container_EReference_subset10->setVolatile(false);
	m_container_EReference_subset10->setChangeable(true);
	m_container_EReference_subset10->setUnsettable(false);
	m_container_EReference_subset10->setUnique(true);
	m_container_EReference_subset10->setDerived(false);
	m_container_EReference_subset10->setOrdered(true);
	m_container_EReference_subset10->setContainment(true);
	m_container_EReference_subset10->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_container_EReference_subset10->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_container_EReference_subset10->setEOpposite(otherEnd);
	    }
	}
	m_container_EReference_subset2->setName("subset2");
	m_container_EReference_subset2->setEType(getElement_Level2_EClass());
	m_container_EReference_subset2->setLowerBound(0);
	m_container_EReference_subset2->setUpperBound(-1);
	m_container_EReference_subset2->setTransient(false);
	m_container_EReference_subset2->setVolatile(false);
	m_container_EReference_subset2->setChangeable(true);
	m_container_EReference_subset2->setUnsettable(false);
	m_container_EReference_subset2->setUnique(true);
	m_container_EReference_subset2->setDerived(false);
	m_container_EReference_subset2->setOrdered(true);
	m_container_EReference_subset2->setContainment(true);
	m_container_EReference_subset2->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_container_EReference_subset2->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_container_EReference_subset2->setEOpposite(otherEnd);
	    }
	}
	m_container_EReference_subset3->setName("subset3");
	m_container_EReference_subset3->setEType(getElement_Level3_EClass());
	m_container_EReference_subset3->setLowerBound(0);
	m_container_EReference_subset3->setUpperBound(-1);
	m_container_EReference_subset3->setTransient(false);
	m_container_EReference_subset3->setVolatile(false);
	m_container_EReference_subset3->setChangeable(true);
	m_container_EReference_subset3->setUnsettable(false);
	m_container_EReference_subset3->setUnique(true);
	m_container_EReference_subset3->setDerived(false);
	m_container_EReference_subset3->setOrdered(true);
	m_container_EReference_subset3->setContainment(true);
	m_container_EReference_subset3->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_container_EReference_subset3->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_container_EReference_subset3->setEOpposite(otherEnd);
	    }
	}
	m_container_EReference_subset4->setName("subset4");
	m_container_EReference_subset4->setEType(getElement_Level4_EClass());
	m_container_EReference_subset4->setLowerBound(0);
	m_container_EReference_subset4->setUpperBound(-1);
	m_container_EReference_subset4->setTransient(false);
	m_container_EReference_subset4->setVolatile(false);
	m_container_EReference_subset4->setChangeable(true);
	m_container_EReference_subset4->setUnsettable(false);
	m_container_EReference_subset4->setUnique(true);
	m_container_EReference_subset4->setDerived(false);
	m_container_EReference_subset4->setOrdered(true);
	m_container_EReference_subset4->setContainment(true);
	m_container_EReference_subset4->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_container_EReference_subset4->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_container_EReference_subset4->setEOpposite(otherEnd);
	    }
	}
	m_container_EReference_subset5->setName("subset5");
	m_container_EReference_subset5->setEType(getElement_Level5_EClass());
	m_container_EReference_subset5->setLowerBound(0);
	m_container_EReference_subset5->setUpperBound(-1);
	m_container_EReference_subset5->setTransient(false);
	m_container_EReference_subset5->setVolatile(false);
	m_container_EReference_subset5->setChangeable(true);
	m_container_EReference_subset5->setUnsettable(false);
	m_container_EReference_subset5->setUnique(true);
	m_container_EReference_subset5->setDerived(false);
	m_container_EReference_subset5->setOrdered(true);
	m_container_EReference_subset5->setContainment(true);
	m_container_EReference_subset5->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_container_EReference_subset5->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_container_EReference_subset5->setEOpposite(otherEnd);
	    }
	}
	m_container_EReference_subset6->setName("subset6");
	m_container_EReference_subset6->setEType(getElement_Level6_EClass());
	m_container_EReference_subset6->setLowerBound(0);
	m_container_EReference_subset6->setUpperBound(-1);
	m_container_EReference_subset6->setTransient(false);
	m_container_EReference_subset6->setVolatile(false);
	m_container_EReference_subset6->setChangeable(true);
	m_container_EReference_subset6->setUnsettable(false);
	m_container_EReference_subset6->setUnique(true);
	m_container_EReference_subset6->setDerived(false);
	m_container_EReference_subset6->setOrdered(true);
	m_container_EReference_subset6->setContainment(true);
	m_container_EReference_subset6->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_container_EReference_subset6->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_container_EReference_subset6->setEOpposite(otherEnd);
	    }
	}
	m_container_EReference_subset7->setName("subset7");
	m_container_EReference_subset7->setEType(getElement_Level7_EClass());
	m_container_EReference_subset7->setLowerBound(0);
	m_container_EReference_subset7->setUpperBound(-1);
	m_container_EReference_subset7->setTransient(false);
	m_container_EReference_subset7->setVolatile(false);
	m_container_EReference_subset7->setChangeable(true);
	m_container_EReference_subset7->setUnsettable(false);
	m_container_EReference_subset7->setUnique(true);
	m_container_EReference_subset7->setDerived(false);
	m_container_EReference_subset7->setOrdered(true);
	m_container_EReference_subset7->setContainment(true);
	m_container_EReference_subset7->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_container_EReference_subset7->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_container_EReference_subset7->setEOpposite(otherEnd);
	    }
	}
	m_container_EReference_subset8->setName("subset8");
	m_container_EReference_subset8->setEType(getElement_Level8_EClass());
	m_container_EReference_subset8->setLowerBound(0);
	m_container_EReference_subset8->setUpperBound(-1);
	m_container_EReference_subset8->setTransient(false);
	m_container_EReference_subset8->setVolatile(false);
	m_container_EReference_subset8->setChangeable(true);
	m_container_EReference_subset8->setUnsettable(false);
	m_container_EReference_subset8->setUnique(true);
	m_container_EReference_subset8->setDerived(false);
	m_container_EReference_subset8->setOrdered(true);
	m_container_EReference_subset8->setContainment(true);
	m_container_EReference_subset8->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_container_EReference_subset8->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_container_EReference_subset8->setEOpposite(otherEnd);
	    }
	}
	m_container_EReference_subset9->setName("subset9");
	m_container_EReference_subset9->setEType(getElement_Level9_EClass());
	m_container_EReference_subset9->setLowerBound(0);
	m_container_EReference_subset9->setUpperBound(-1);
	m_container_EReference_subset9->setTransient(false);
	m_container_EReference_subset9->setVolatile(false);
	m_container_EReference_subset9->setChangeable(true);
	m_container_EReference_subset9->setUnsettable(false);
	m_container_EReference_subset9->setUnique(true);
	m_container_EReference_subset9->setDerived(false);
	m_container_EReference_subset9->setOrdered(true);
	m_container_EReference_subset9->setContainment(true);
	m_container_EReference_subset9->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_container_EReference_subset9->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_container_EReference_subset9->setEOpposite(otherEnd);
	    }
	}
	m_container_EReference_unionBag->setName("unionBag");
	m_container_EReference_unionBag->setEType(getElement_EClass());
	m_container_EReference_unionBag->setLowerBound(0);
	m_container_EReference_unionBag->setUpperBound(-1);
	m_container_EReference_unionBag->setTransient(false);
	m_container_EReference_unionBag->setVolatile(false);
	m_container_EReference_unionBag->setChangeable(true);
	m_container_EReference_unionBag->setUnsettable(false);
	m_container_EReference_unionBag->setUnique(true);
	m_container_EReference_unionBag->setDerived(true);
	m_container_EReference_unionBag->setOrdered(true);
	m_container_EReference_unionBag->setContainment(true);
	m_container_EReference_unionBag->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_container_EReference_unionBag->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_container_EReference_unionBag->setEOpposite(otherEnd);
	    }
	}
	
	
}

void SubsetUnionBenchmarkPackageImpl::initializeElementContent()
{
	m_element_EClass->setName("Element");
	m_element_EClass->setAbstract(false);
	m_element_EClass->setInterface(false);
	
	m_element_EAttribute_name = getElement_EAttribute_name();
	m_element_EAttribute_name->setName("name");
	m_element_EAttribute_name->setEType(ecore::EcorePackage::eInstance()->getEString_EDataType());
	m_element_EAttribute_name->setLowerBound(0);
	m_element_EAttribute_name->setUpperBound(1);
	m_element_EAttribute_name->setTransient(false);
	m_element_EAttribute_name->setVolatile(false);
	m_element_EAttribute_name->setChangeable(true);
	m_element_EAttribute_name->setUnsettable(false);
	m_element_EAttribute_name->setUnique(true);
	m_element_EAttribute_name->setDerived(false);
	m_element_EAttribute_name->setOrdered(true);
	m_element_EAttribute_name->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_element_EAttribute_name->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	
}

void SubsetUnionBenchmarkPackageImpl::initializeElement_Level1Content()
{
	m_element_Level1_EClass->setName("Element_Level1");
	m_element_Level1_EClass->setAbstract(false);
	m_element_Level1_EClass->setInterface(false);
	
	
	
	
}

void SubsetUnionBenchmarkPackageImpl::initializeElement_Level10Content()
{
	m_element_Level10_EClass->setName("Element_Level10");
	m_element_Level10_EClass->setAbstract(false);
	m_element_Level10_EClass->setInterface(false);
	
	
	
	
}

void SubsetUnionBenchmarkPackageImpl::initializeElement_Level2Content()
{
	m_element_Level2_EClass->setName("Element_Level2");
	m_element_Level2_EClass->setAbstract(false);
	m_element_Level2_EClass->setInterface(false);
	
	
	
	
}

void SubsetUnionBenchmarkPackageImpl::initializeElement_Level3Content()
{
	m_element_Level3_EClass->setName("Element_Level3");
	m_element_Level3_EClass->setAbstract(false);
	m_element_Level3_EClass->setInterface(false);
	
	
	
	
}

void SubsetUnionBenchmarkPackageImpl::initializeElement_Level4Content()
{
	m_element_Level4_EClass->setName("Element_Level4");
	m_element_Level4_EClass->setAbstract(false);
	m_element_Level4_EClass->setInterface(false);
	
	
	
	
}

void SubsetUnionBenchmarkPackageImpl::initializeElement_Level5Content()
{
	m_element_Level5_EClass->setName("Element_Level5");
	m_element_Level5_EClass->setAbstract(false);
	m_element_Level5_EClass->setInterface(false);
	
	
	
	
}

void SubsetUnionBenchmarkPackageImpl::initializeElement_Level6Content()
{
	m_element_Level6_EClass->setName("Element_Level6");
	m_element_Level6_EClass->setAbstract(false);
	m_element_Level6_EClass->setInterface(false);
	
	
	
	
}

void SubsetUnionBenchmarkPackageImpl::initializeElement_Level7Content()
{
	m_element_Level7_EClass->setName("Element_Level7");
	m_element_Level7_EClass->setAbstract(false);
	m_element_Level7_EClass->setInterface(false);
	
	
	
	
}

void SubsetUnionBenchmarkPackageImpl::initializeElement_Level8Content()
{
	m_element_Level8_EClass->setName("Element_Level8");
	m_element_Level8_EClass->setAbstract(false);
	m_element_Level8_EClass->setInterface(false);
	
	
	
	
}

void SubsetUnionBenchmarkPackageImpl::initializeElement_Level9Content()
{
	m_element_Level9_EClass->setName("Element_Level9");
	m_element_Level9_EClass->setAbstract(false);
	m_element_Level9_EClass->setInterface(false);
	
	
	
	
}

void SubsetUnionBenchmarkPackageImpl::initializePackageEDataTypes()
{
	
}
