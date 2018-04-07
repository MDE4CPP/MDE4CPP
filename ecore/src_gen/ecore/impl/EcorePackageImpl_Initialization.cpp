#include "ecore/impl/EcorePackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EReference.hpp"

// metametamodel factory
#include "ecore/EcoreFactory.hpp"

//depending model packages

using namespace ecore;

void EcorePackageImpl::initializePackageContents()
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
	m_eAnnotation_EClass->getESuperTypes()->push_back(getEModelElement_EClass());
	m_eAttribute_EClass->getESuperTypes()->push_back(getEStructuralFeature_EClass());
	m_eClass_EClass->getESuperTypes()->push_back(getEClassifier_EClass());
	m_eClassifier_EClass->getESuperTypes()->push_back(getENamedElement_EClass());
	m_eDataType_EClass->getESuperTypes()->push_back(getEClassifier_EClass());
	m_eEnum_EClass->getESuperTypes()->push_back(getEDataType_EClass());
	m_eEnumLiteral_EClass->getESuperTypes()->push_back(getENamedElement_EClass());
	m_eFactory_EClass->getESuperTypes()->push_back(getEModelElement_EClass());
	m_eGenericType_EClass->getESuperTypes()->push_back(getEObject_EClass());
	m_eNamedElement_EClass->getESuperTypes()->push_back(getEModelElement_EClass());
	m_eOperation_EClass->getESuperTypes()->push_back(getETypedElement_EClass());
	m_ePackage_EClass->getESuperTypes()->push_back(getENamedElement_EClass());
	m_eParameter_EClass->getESuperTypes()->push_back(getETypedElement_EClass());
	m_eReference_EClass->getESuperTypes()->push_back(getEStructuralFeature_EClass());
	m_eStringToStringMapEntry_EClass->getESuperTypes()->push_back(getEObject_EClass());
	m_eStructuralFeature_EClass->getESuperTypes()->push_back(getETypedElement_EClass());
	m_eTypeParameter_EClass->getESuperTypes()->push_back(getENamedElement_EClass());
	m_eTypedElement_EClass->getESuperTypes()->push_back(getENamedElement_EClass());
	

 	// Initialize classes and features; add operations and parameters
	initializeEAnnotationContent();
	initializeEAttributeContent();
	initializeEClassContent();
	initializeEClassifierContent();
	initializeEDataTypeContent();
	initializeEEnumContent();
	initializeEEnumLiteralContent();
	initializeEFactoryContent();
	initializeEGenericTypeContent();
	initializeEModelElementContent();
	initializeENamedElementContent();
	initializeEObjectContent();
	initializeEOperationContent();
	initializeEPackageContent();
	initializeEParameterContent();
	initializeEReferenceContent();
	initializeEStringToStringMapEntryContent();
	initializeEStructuralFeatureContent();
	initializeETypeParameterContent();
	initializeETypedElementContent();

	initializePackageEDataTypes();
}

void EcorePackageImpl::initializeEAnnotationContent()
{
	m_eAnnotation_EClass->setInstanceClass(nullptr);
	m_eAnnotation_EClass->setName("EAnnotation");
	m_eAnnotation_EClass->setAbstract(false);
	m_eAnnotation_EClass->setInterface(false);
	
	m_eAnnotation_EAttribute_source = getEAnnotation_EAttribute_source();
	m_eAnnotation_EAttribute_source->setName("source");
	m_eAnnotation_EAttribute_source->setEType(getEString_EDataType());
	m_eAnnotation_EAttribute_source->setLowerBound(0);
	m_eAnnotation_EAttribute_source->setUpperBound(1);
	m_eAnnotation_EAttribute_source->setTransient(false);
	m_eAnnotation_EAttribute_source->setVolatile(false);
	m_eAnnotation_EAttribute_source->setChangeable(true);
	m_eAnnotation_EAttribute_source->setUnsettable(false);
	m_eAnnotation_EAttribute_source->setUnique(true);
	m_eAnnotation_EAttribute_source->setDerived(false);
	m_eAnnotation_EAttribute_source->setOrdered(true);
	m_eAnnotation_EAttribute_source->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eAnnotation_EAttribute_source->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_eAnnotation_EReference_contents->setName("contents");
	m_eAnnotation_EReference_contents->setEType(getEObject_EClass());
	m_eAnnotation_EReference_contents->setLowerBound(0);
	m_eAnnotation_EReference_contents->setUpperBound(-1);
	m_eAnnotation_EReference_contents->setTransient(false);
	m_eAnnotation_EReference_contents->setVolatile(false);
	m_eAnnotation_EReference_contents->setChangeable(true);
	m_eAnnotation_EReference_contents->setUnsettable(false);
	m_eAnnotation_EReference_contents->setUnique(true);
	m_eAnnotation_EReference_contents->setDerived(false);
	m_eAnnotation_EReference_contents->setOrdered(true);
	m_eAnnotation_EReference_contents->setContainment(true);
	m_eAnnotation_EReference_contents->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eAnnotation_EReference_contents->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eAnnotation_EReference_contents->setEOpposite(otherEnd);
	    }
	}
	m_eAnnotation_EReference_details->setName("details");
	m_eAnnotation_EReference_details->setEType(getEStringToStringMapEntry_EClass());
	m_eAnnotation_EReference_details->setLowerBound(0);
	m_eAnnotation_EReference_details->setUpperBound(-1);
	m_eAnnotation_EReference_details->setTransient(false);
	m_eAnnotation_EReference_details->setVolatile(false);
	m_eAnnotation_EReference_details->setChangeable(true);
	m_eAnnotation_EReference_details->setUnsettable(false);
	m_eAnnotation_EReference_details->setUnique(true);
	m_eAnnotation_EReference_details->setDerived(false);
	m_eAnnotation_EReference_details->setOrdered(true);
	m_eAnnotation_EReference_details->setContainment(true);
	m_eAnnotation_EReference_details->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eAnnotation_EReference_details->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eAnnotation_EReference_details->setEOpposite(otherEnd);
	    }
	}
	m_eAnnotation_EReference_eModelElement->setName("eModelElement");
	m_eAnnotation_EReference_eModelElement->setEType(getEModelElement_EClass());
	m_eAnnotation_EReference_eModelElement->setLowerBound(0);
	m_eAnnotation_EReference_eModelElement->setUpperBound(1);
	m_eAnnotation_EReference_eModelElement->setTransient(true);
	m_eAnnotation_EReference_eModelElement->setVolatile(false);
	m_eAnnotation_EReference_eModelElement->setChangeable(true);
	m_eAnnotation_EReference_eModelElement->setUnsettable(false);
	m_eAnnotation_EReference_eModelElement->setUnique(true);
	m_eAnnotation_EReference_eModelElement->setDerived(false);
	m_eAnnotation_EReference_eModelElement->setOrdered(true);
	m_eAnnotation_EReference_eModelElement->setContainment(false);
	m_eAnnotation_EReference_eModelElement->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eAnnotation_EReference_eModelElement->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEModelElement_EReference_eAnnotations();
		if (otherEnd != nullptr)
	    {
	   		m_eAnnotation_EReference_eModelElement->setEOpposite(otherEnd);
	    }
	}
	m_eAnnotation_EReference_references->setName("references");
	m_eAnnotation_EReference_references->setEType(getEObject_EClass());
	m_eAnnotation_EReference_references->setLowerBound(0);
	m_eAnnotation_EReference_references->setUpperBound(-1);
	m_eAnnotation_EReference_references->setTransient(false);
	m_eAnnotation_EReference_references->setVolatile(false);
	m_eAnnotation_EReference_references->setChangeable(true);
	m_eAnnotation_EReference_references->setUnsettable(false);
	m_eAnnotation_EReference_references->setUnique(true);
	m_eAnnotation_EReference_references->setDerived(false);
	m_eAnnotation_EReference_references->setOrdered(true);
	m_eAnnotation_EReference_references->setContainment(false);
	m_eAnnotation_EReference_references->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eAnnotation_EReference_references->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eAnnotation_EReference_references->setEOpposite(otherEnd);
	    }
	}
	
	
}

void EcorePackageImpl::initializeEAttributeContent()
{
	m_eAttribute_EClass->setInstanceClass(nullptr);
	m_eAttribute_EClass->setName("EAttribute");
	m_eAttribute_EClass->setAbstract(false);
	m_eAttribute_EClass->setInterface(false);
	
	m_eAttribute_EAttribute_iD = getEAttribute_EAttribute_iD();
	m_eAttribute_EAttribute_iD->setName("iD");
	m_eAttribute_EAttribute_iD->setEType(getEBoolean_EDataType());
	m_eAttribute_EAttribute_iD->setLowerBound(0);
	m_eAttribute_EAttribute_iD->setUpperBound(1);
	m_eAttribute_EAttribute_iD->setTransient(false);
	m_eAttribute_EAttribute_iD->setVolatile(false);
	m_eAttribute_EAttribute_iD->setChangeable(true);
	m_eAttribute_EAttribute_iD->setUnsettable(false);
	m_eAttribute_EAttribute_iD->setUnique(true);
	m_eAttribute_EAttribute_iD->setDerived(false);
	m_eAttribute_EAttribute_iD->setOrdered(true);
	m_eAttribute_EAttribute_iD->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eAttribute_EAttribute_iD->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_eAttribute_EReference_eAttributeType->setName("eAttributeType");
	m_eAttribute_EReference_eAttributeType->setEType(getEDataType_EClass());
	m_eAttribute_EReference_eAttributeType->setLowerBound(1);
	m_eAttribute_EReference_eAttributeType->setUpperBound(1);
	m_eAttribute_EReference_eAttributeType->setTransient(true);
	m_eAttribute_EReference_eAttributeType->setVolatile(true);
	m_eAttribute_EReference_eAttributeType->setChangeable(false);
	m_eAttribute_EReference_eAttributeType->setUnsettable(false);
	m_eAttribute_EReference_eAttributeType->setUnique(true);
	m_eAttribute_EReference_eAttributeType->setDerived(true);
	m_eAttribute_EReference_eAttributeType->setOrdered(true);
	m_eAttribute_EReference_eAttributeType->setContainment(false);
	m_eAttribute_EReference_eAttributeType->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eAttribute_EReference_eAttributeType->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eAttribute_EReference_eAttributeType->setEOpposite(otherEnd);
	    }
	}
	
	
}

void EcorePackageImpl::initializeEClassContent()
{
	m_eClass_EClass->setInstanceClass(nullptr);
	m_eClass_EClass->setName("EClass");
	m_eClass_EClass->setAbstract(false);
	m_eClass_EClass->setInterface(false);
	
	m_eClass_EAttribute_abstract = getEClass_EAttribute_abstract();
	m_eClass_EAttribute_abstract->setName("abstract");
	m_eClass_EAttribute_abstract->setEType(getEBoolean_EDataType());
	m_eClass_EAttribute_abstract->setLowerBound(0);
	m_eClass_EAttribute_abstract->setUpperBound(1);
	m_eClass_EAttribute_abstract->setTransient(false);
	m_eClass_EAttribute_abstract->setVolatile(false);
	m_eClass_EAttribute_abstract->setChangeable(true);
	m_eClass_EAttribute_abstract->setUnsettable(false);
	m_eClass_EAttribute_abstract->setUnique(true);
	m_eClass_EAttribute_abstract->setDerived(false);
	m_eClass_EAttribute_abstract->setOrdered(true);
	m_eClass_EAttribute_abstract->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eClass_EAttribute_abstract->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eClass_EAttribute_interface = getEClass_EAttribute_interface();
	m_eClass_EAttribute_interface->setName("interface");
	m_eClass_EAttribute_interface->setEType(getEBoolean_EDataType());
	m_eClass_EAttribute_interface->setLowerBound(0);
	m_eClass_EAttribute_interface->setUpperBound(1);
	m_eClass_EAttribute_interface->setTransient(false);
	m_eClass_EAttribute_interface->setVolatile(false);
	m_eClass_EAttribute_interface->setChangeable(true);
	m_eClass_EAttribute_interface->setUnsettable(false);
	m_eClass_EAttribute_interface->setUnique(true);
	m_eClass_EAttribute_interface->setDerived(false);
	m_eClass_EAttribute_interface->setOrdered(true);
	m_eClass_EAttribute_interface->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eClass_EAttribute_interface->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_eClass_EReference_eAllAttributes->setName("eAllAttributes");
	m_eClass_EReference_eAllAttributes->setEType(getEAttribute_EClass());
	m_eClass_EReference_eAllAttributes->setLowerBound(0);
	m_eClass_EReference_eAllAttributes->setUpperBound(-1);
	m_eClass_EReference_eAllAttributes->setTransient(true);
	m_eClass_EReference_eAllAttributes->setVolatile(true);
	m_eClass_EReference_eAllAttributes->setChangeable(false);
	m_eClass_EReference_eAllAttributes->setUnsettable(false);
	m_eClass_EReference_eAllAttributes->setUnique(true);
	m_eClass_EReference_eAllAttributes->setDerived(true);
	m_eClass_EReference_eAllAttributes->setOrdered(true);
	m_eClass_EReference_eAllAttributes->setContainment(false);
	m_eClass_EReference_eAllAttributes->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_EReference_eAllAttributes->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eClass_EReference_eAllAttributes->setEOpposite(otherEnd);
	    }
	}
	m_eClass_EReference_eAllContainments->setName("eAllContainments");
	m_eClass_EReference_eAllContainments->setEType(getEReference_EClass());
	m_eClass_EReference_eAllContainments->setLowerBound(0);
	m_eClass_EReference_eAllContainments->setUpperBound(-1);
	m_eClass_EReference_eAllContainments->setTransient(true);
	m_eClass_EReference_eAllContainments->setVolatile(true);
	m_eClass_EReference_eAllContainments->setChangeable(false);
	m_eClass_EReference_eAllContainments->setUnsettable(false);
	m_eClass_EReference_eAllContainments->setUnique(true);
	m_eClass_EReference_eAllContainments->setDerived(true);
	m_eClass_EReference_eAllContainments->setOrdered(true);
	m_eClass_EReference_eAllContainments->setContainment(false);
	m_eClass_EReference_eAllContainments->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_EReference_eAllContainments->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eClass_EReference_eAllContainments->setEOpposite(otherEnd);
	    }
	}
	m_eClass_EReference_eAllGenericSuperTypes->setName("eAllGenericSuperTypes");
	m_eClass_EReference_eAllGenericSuperTypes->setEType(getEGenericType_EClass());
	m_eClass_EReference_eAllGenericSuperTypes->setLowerBound(0);
	m_eClass_EReference_eAllGenericSuperTypes->setUpperBound(-1);
	m_eClass_EReference_eAllGenericSuperTypes->setTransient(true);
	m_eClass_EReference_eAllGenericSuperTypes->setVolatile(true);
	m_eClass_EReference_eAllGenericSuperTypes->setChangeable(false);
	m_eClass_EReference_eAllGenericSuperTypes->setUnsettable(false);
	m_eClass_EReference_eAllGenericSuperTypes->setUnique(true);
	m_eClass_EReference_eAllGenericSuperTypes->setDerived(true);
	m_eClass_EReference_eAllGenericSuperTypes->setOrdered(true);
	m_eClass_EReference_eAllGenericSuperTypes->setContainment(false);
	m_eClass_EReference_eAllGenericSuperTypes->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_EReference_eAllGenericSuperTypes->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eClass_EReference_eAllGenericSuperTypes->setEOpposite(otherEnd);
	    }
	}
	m_eClass_EReference_eAllOperations->setName("eAllOperations");
	m_eClass_EReference_eAllOperations->setEType(getEOperation_EClass());
	m_eClass_EReference_eAllOperations->setLowerBound(0);
	m_eClass_EReference_eAllOperations->setUpperBound(-1);
	m_eClass_EReference_eAllOperations->setTransient(true);
	m_eClass_EReference_eAllOperations->setVolatile(true);
	m_eClass_EReference_eAllOperations->setChangeable(false);
	m_eClass_EReference_eAllOperations->setUnsettable(false);
	m_eClass_EReference_eAllOperations->setUnique(true);
	m_eClass_EReference_eAllOperations->setDerived(true);
	m_eClass_EReference_eAllOperations->setOrdered(true);
	m_eClass_EReference_eAllOperations->setContainment(false);
	m_eClass_EReference_eAllOperations->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_EReference_eAllOperations->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eClass_EReference_eAllOperations->setEOpposite(otherEnd);
	    }
	}
	m_eClass_EReference_eAllReferences->setName("eAllReferences");
	m_eClass_EReference_eAllReferences->setEType(getEReference_EClass());
	m_eClass_EReference_eAllReferences->setLowerBound(0);
	m_eClass_EReference_eAllReferences->setUpperBound(-1);
	m_eClass_EReference_eAllReferences->setTransient(true);
	m_eClass_EReference_eAllReferences->setVolatile(true);
	m_eClass_EReference_eAllReferences->setChangeable(false);
	m_eClass_EReference_eAllReferences->setUnsettable(false);
	m_eClass_EReference_eAllReferences->setUnique(true);
	m_eClass_EReference_eAllReferences->setDerived(true);
	m_eClass_EReference_eAllReferences->setOrdered(true);
	m_eClass_EReference_eAllReferences->setContainment(false);
	m_eClass_EReference_eAllReferences->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_EReference_eAllReferences->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eClass_EReference_eAllReferences->setEOpposite(otherEnd);
	    }
	}
	m_eClass_EReference_eAllStructuralFeatures->setName("eAllStructuralFeatures");
	m_eClass_EReference_eAllStructuralFeatures->setEType(getEStructuralFeature_EClass());
	m_eClass_EReference_eAllStructuralFeatures->setLowerBound(0);
	m_eClass_EReference_eAllStructuralFeatures->setUpperBound(-1);
	m_eClass_EReference_eAllStructuralFeatures->setTransient(true);
	m_eClass_EReference_eAllStructuralFeatures->setVolatile(true);
	m_eClass_EReference_eAllStructuralFeatures->setChangeable(false);
	m_eClass_EReference_eAllStructuralFeatures->setUnsettable(false);
	m_eClass_EReference_eAllStructuralFeatures->setUnique(true);
	m_eClass_EReference_eAllStructuralFeatures->setDerived(true);
	m_eClass_EReference_eAllStructuralFeatures->setOrdered(true);
	m_eClass_EReference_eAllStructuralFeatures->setContainment(false);
	m_eClass_EReference_eAllStructuralFeatures->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_EReference_eAllStructuralFeatures->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eClass_EReference_eAllStructuralFeatures->setEOpposite(otherEnd);
	    }
	}
	m_eClass_EReference_eAllSuperTypes->setName("eAllSuperTypes");
	m_eClass_EReference_eAllSuperTypes->setEType(getEClass_EClass());
	m_eClass_EReference_eAllSuperTypes->setLowerBound(0);
	m_eClass_EReference_eAllSuperTypes->setUpperBound(-1);
	m_eClass_EReference_eAllSuperTypes->setTransient(true);
	m_eClass_EReference_eAllSuperTypes->setVolatile(true);
	m_eClass_EReference_eAllSuperTypes->setChangeable(false);
	m_eClass_EReference_eAllSuperTypes->setUnsettable(false);
	m_eClass_EReference_eAllSuperTypes->setUnique(true);
	m_eClass_EReference_eAllSuperTypes->setDerived(true);
	m_eClass_EReference_eAllSuperTypes->setOrdered(true);
	m_eClass_EReference_eAllSuperTypes->setContainment(false);
	m_eClass_EReference_eAllSuperTypes->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_EReference_eAllSuperTypes->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eClass_EReference_eAllSuperTypes->setEOpposite(otherEnd);
	    }
	}
	m_eClass_EReference_eAttributes->setName("eAttributes");
	m_eClass_EReference_eAttributes->setEType(getEAttribute_EClass());
	m_eClass_EReference_eAttributes->setLowerBound(0);
	m_eClass_EReference_eAttributes->setUpperBound(-1);
	m_eClass_EReference_eAttributes->setTransient(true);
	m_eClass_EReference_eAttributes->setVolatile(true);
	m_eClass_EReference_eAttributes->setChangeable(false);
	m_eClass_EReference_eAttributes->setUnsettable(false);
	m_eClass_EReference_eAttributes->setUnique(true);
	m_eClass_EReference_eAttributes->setDerived(true);
	m_eClass_EReference_eAttributes->setOrdered(true);
	m_eClass_EReference_eAttributes->setContainment(false);
	m_eClass_EReference_eAttributes->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_EReference_eAttributes->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eClass_EReference_eAttributes->setEOpposite(otherEnd);
	    }
	}
	m_eClass_EReference_eGenericSuperTypes->setName("eGenericSuperTypes");
	m_eClass_EReference_eGenericSuperTypes->setEType(getEGenericType_EClass());
	m_eClass_EReference_eGenericSuperTypes->setLowerBound(0);
	m_eClass_EReference_eGenericSuperTypes->setUpperBound(-1);
	m_eClass_EReference_eGenericSuperTypes->setTransient(false);
	m_eClass_EReference_eGenericSuperTypes->setVolatile(false);
	m_eClass_EReference_eGenericSuperTypes->setChangeable(true);
	m_eClass_EReference_eGenericSuperTypes->setUnsettable(true);
	m_eClass_EReference_eGenericSuperTypes->setUnique(true);
	m_eClass_EReference_eGenericSuperTypes->setDerived(false);
	m_eClass_EReference_eGenericSuperTypes->setOrdered(true);
	m_eClass_EReference_eGenericSuperTypes->setContainment(true);
	m_eClass_EReference_eGenericSuperTypes->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_EReference_eGenericSuperTypes->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eClass_EReference_eGenericSuperTypes->setEOpposite(otherEnd);
	    }
	}
	m_eClass_EReference_eIDAttribute->setName("eIDAttribute");
	m_eClass_EReference_eIDAttribute->setEType(getEAttribute_EClass());
	m_eClass_EReference_eIDAttribute->setLowerBound(0);
	m_eClass_EReference_eIDAttribute->setUpperBound(1);
	m_eClass_EReference_eIDAttribute->setTransient(true);
	m_eClass_EReference_eIDAttribute->setVolatile(true);
	m_eClass_EReference_eIDAttribute->setChangeable(false);
	m_eClass_EReference_eIDAttribute->setUnsettable(false);
	m_eClass_EReference_eIDAttribute->setUnique(true);
	m_eClass_EReference_eIDAttribute->setDerived(true);
	m_eClass_EReference_eIDAttribute->setOrdered(true);
	m_eClass_EReference_eIDAttribute->setContainment(false);
	m_eClass_EReference_eIDAttribute->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_EReference_eIDAttribute->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eClass_EReference_eIDAttribute->setEOpposite(otherEnd);
	    }
	}
	m_eClass_EReference_eOperations->setName("eOperations");
	m_eClass_EReference_eOperations->setEType(getEOperation_EClass());
	m_eClass_EReference_eOperations->setLowerBound(0);
	m_eClass_EReference_eOperations->setUpperBound(-1);
	m_eClass_EReference_eOperations->setTransient(false);
	m_eClass_EReference_eOperations->setVolatile(false);
	m_eClass_EReference_eOperations->setChangeable(true);
	m_eClass_EReference_eOperations->setUnsettable(false);
	m_eClass_EReference_eOperations->setUnique(true);
	m_eClass_EReference_eOperations->setDerived(false);
	m_eClass_EReference_eOperations->setOrdered(true);
	m_eClass_EReference_eOperations->setContainment(true);
	m_eClass_EReference_eOperations->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_EReference_eOperations->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEOperation_EReference_eContainingClass();
		if (otherEnd != nullptr)
	    {
	   		m_eClass_EReference_eOperations->setEOpposite(otherEnd);
	    }
	}
	m_eClass_EReference_eReferences->setName("eReferences");
	m_eClass_EReference_eReferences->setEType(getEReference_EClass());
	m_eClass_EReference_eReferences->setLowerBound(0);
	m_eClass_EReference_eReferences->setUpperBound(-1);
	m_eClass_EReference_eReferences->setTransient(true);
	m_eClass_EReference_eReferences->setVolatile(true);
	m_eClass_EReference_eReferences->setChangeable(false);
	m_eClass_EReference_eReferences->setUnsettable(false);
	m_eClass_EReference_eReferences->setUnique(true);
	m_eClass_EReference_eReferences->setDerived(true);
	m_eClass_EReference_eReferences->setOrdered(true);
	m_eClass_EReference_eReferences->setContainment(false);
	m_eClass_EReference_eReferences->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_EReference_eReferences->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eClass_EReference_eReferences->setEOpposite(otherEnd);
	    }
	}
	m_eClass_EReference_eStructuralFeatures->setName("eStructuralFeatures");
	m_eClass_EReference_eStructuralFeatures->setEType(getEStructuralFeature_EClass());
	m_eClass_EReference_eStructuralFeatures->setLowerBound(0);
	m_eClass_EReference_eStructuralFeatures->setUpperBound(-1);
	m_eClass_EReference_eStructuralFeatures->setTransient(false);
	m_eClass_EReference_eStructuralFeatures->setVolatile(false);
	m_eClass_EReference_eStructuralFeatures->setChangeable(true);
	m_eClass_EReference_eStructuralFeatures->setUnsettable(false);
	m_eClass_EReference_eStructuralFeatures->setUnique(true);
	m_eClass_EReference_eStructuralFeatures->setDerived(false);
	m_eClass_EReference_eStructuralFeatures->setOrdered(true);
	m_eClass_EReference_eStructuralFeatures->setContainment(true);
	m_eClass_EReference_eStructuralFeatures->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_EReference_eStructuralFeatures->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEStructuralFeature_EReference_eContainingClass();
		if (otherEnd != nullptr)
	    {
	   		m_eClass_EReference_eStructuralFeatures->setEOpposite(otherEnd);
	    }
	}
	m_eClass_EReference_eSuperTypes->setName("eSuperTypes");
	m_eClass_EReference_eSuperTypes->setEType(getEClass_EClass());
	m_eClass_EReference_eSuperTypes->setLowerBound(0);
	m_eClass_EReference_eSuperTypes->setUpperBound(-1);
	m_eClass_EReference_eSuperTypes->setTransient(false);
	m_eClass_EReference_eSuperTypes->setVolatile(false);
	m_eClass_EReference_eSuperTypes->setChangeable(true);
	m_eClass_EReference_eSuperTypes->setUnsettable(true);
	m_eClass_EReference_eSuperTypes->setUnique(true);
	m_eClass_EReference_eSuperTypes->setDerived(false);
	m_eClass_EReference_eSuperTypes->setOrdered(true);
	m_eClass_EReference_eSuperTypes->setContainment(false);
	m_eClass_EReference_eSuperTypes->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_EReference_eSuperTypes->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eClass_EReference_eSuperTypes->setEOpposite(otherEnd);
	    }
	}
	
	m_eClass_EOperation_getEOperation_EInt->setEType(getEOperation_EClass());
	m_eClass_EOperation_getEOperation_EInt->setName("getEOperation");
	m_eClass_EOperation_getEOperation_EInt->setLowerBound(0);
	m_eClass_EOperation_getEOperation_EInt->setUpperBound(1);
	m_eClass_EOperation_getEOperation_EInt->setUnique(true);
	m_eClass_EOperation_getEOperation_EInt->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eClass_EOperation_getEOperation_EInt);
		parameter->setName("operationID");
		parameter->setEType(getEInt_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eClass_EOperation_getEStructuralFeature_EInt->setEType(getEStructuralFeature_EClass());
	m_eClass_EOperation_getEStructuralFeature_EInt->setName("getEStructuralFeature");
	m_eClass_EOperation_getEStructuralFeature_EInt->setLowerBound(0);
	m_eClass_EOperation_getEStructuralFeature_EInt->setUpperBound(1);
	m_eClass_EOperation_getEStructuralFeature_EInt->setUnique(true);
	m_eClass_EOperation_getEStructuralFeature_EInt->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eClass_EOperation_getEStructuralFeature_EInt);
		parameter->setName("featureID");
		parameter->setEType(getEInt_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eClass_EOperation_getEStructuralFeature_EString->setEType(getEStructuralFeature_EClass());
	m_eClass_EOperation_getEStructuralFeature_EString->setName("getEStructuralFeature");
	m_eClass_EOperation_getEStructuralFeature_EString->setLowerBound(0);
	m_eClass_EOperation_getEStructuralFeature_EString->setUpperBound(1);
	m_eClass_EOperation_getEStructuralFeature_EString->setUnique(true);
	m_eClass_EOperation_getEStructuralFeature_EString->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eClass_EOperation_getEStructuralFeature_EString);
		parameter->setName("featureName");
		parameter->setEType(getEString_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eClass_EOperation_getFeatureCount->setEType(getEInt_EDataType());
	m_eClass_EOperation_getFeatureCount->setName("getFeatureCount");
	m_eClass_EOperation_getFeatureCount->setLowerBound(0);
	m_eClass_EOperation_getFeatureCount->setUpperBound(1);
	m_eClass_EOperation_getFeatureCount->setUnique(true);
	m_eClass_EOperation_getFeatureCount->setOrdered(true);
	
	
	m_eClass_EOperation_getFeatureID_EStructuralFeature->setEType(getEInt_EDataType());
	m_eClass_EOperation_getFeatureID_EStructuralFeature->setName("getFeatureID");
	m_eClass_EOperation_getFeatureID_EStructuralFeature->setLowerBound(0);
	m_eClass_EOperation_getFeatureID_EStructuralFeature->setUpperBound(1);
	m_eClass_EOperation_getFeatureID_EStructuralFeature->setUnique(true);
	m_eClass_EOperation_getFeatureID_EStructuralFeature->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eClass_EOperation_getFeatureID_EStructuralFeature);
		parameter->setName("feature");
		parameter->setEType(getEStructuralFeature_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eClass_EOperation_getFeatureType_EStructuralFeature->setEType(getEGenericType_EClass());
	m_eClass_EOperation_getFeatureType_EStructuralFeature->setName("getFeatureType");
	m_eClass_EOperation_getFeatureType_EStructuralFeature->setLowerBound(0);
	m_eClass_EOperation_getFeatureType_EStructuralFeature->setUpperBound(1);
	m_eClass_EOperation_getFeatureType_EStructuralFeature->setUnique(true);
	m_eClass_EOperation_getFeatureType_EStructuralFeature->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eClass_EOperation_getFeatureType_EStructuralFeature);
		parameter->setName("feature");
		parameter->setEType(getEStructuralFeature_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eClass_EOperation_getOperationCount->setEType(getEInt_EDataType());
	m_eClass_EOperation_getOperationCount->setName("getOperationCount");
	m_eClass_EOperation_getOperationCount->setLowerBound(0);
	m_eClass_EOperation_getOperationCount->setUpperBound(1);
	m_eClass_EOperation_getOperationCount->setUnique(true);
	m_eClass_EOperation_getOperationCount->setOrdered(true);
	
	
	m_eClass_EOperation_getOperationID_EOperation->setEType(getEInt_EDataType());
	m_eClass_EOperation_getOperationID_EOperation->setName("getOperationID");
	m_eClass_EOperation_getOperationID_EOperation->setLowerBound(0);
	m_eClass_EOperation_getOperationID_EOperation->setUpperBound(1);
	m_eClass_EOperation_getOperationID_EOperation->setUnique(true);
	m_eClass_EOperation_getOperationID_EOperation->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eClass_EOperation_getOperationID_EOperation);
		parameter->setName("operation");
		parameter->setEType(getEOperation_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eClass_EOperation_getOverride_EOperation->setEType(getEOperation_EClass());
	m_eClass_EOperation_getOverride_EOperation->setName("getOverride");
	m_eClass_EOperation_getOverride_EOperation->setLowerBound(0);
	m_eClass_EOperation_getOverride_EOperation->setUpperBound(1);
	m_eClass_EOperation_getOverride_EOperation->setUnique(true);
	m_eClass_EOperation_getOverride_EOperation->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eClass_EOperation_getOverride_EOperation);
		parameter->setName("operation");
		parameter->setEType(getEOperation_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eClass_EOperation_isSuperTypeOf_EClass->setEType(getEBoolean_EDataType());
	m_eClass_EOperation_isSuperTypeOf_EClass->setName("isSuperTypeOf");
	m_eClass_EOperation_isSuperTypeOf_EClass->setLowerBound(0);
	m_eClass_EOperation_isSuperTypeOf_EClass->setUpperBound(1);
	m_eClass_EOperation_isSuperTypeOf_EClass->setUnique(true);
	m_eClass_EOperation_isSuperTypeOf_EClass->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eClass_EOperation_isSuperTypeOf_EClass);
		parameter->setName("someClass");
		parameter->setEType(getEClass_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void EcorePackageImpl::initializeEClassifierContent()
{
	m_eClassifier_EClass->setInstanceClass(nullptr);
	m_eClassifier_EClass->setName("EClassifier");
	m_eClassifier_EClass->setAbstract(true);
	m_eClassifier_EClass->setInterface(false);
	
	m_eClassifier_EAttribute_classifierID = getEClassifier_EAttribute_classifierID();
	m_eClassifier_EAttribute_classifierID->setName("classifierID");
	m_eClassifier_EAttribute_classifierID->setEType(getEInt_EDataType());
	m_eClassifier_EAttribute_classifierID->setLowerBound(0);
	m_eClassifier_EAttribute_classifierID->setUpperBound(1);
	m_eClassifier_EAttribute_classifierID->setTransient(false);
	m_eClassifier_EAttribute_classifierID->setVolatile(false);
	m_eClassifier_EAttribute_classifierID->setChangeable(false);
	m_eClassifier_EAttribute_classifierID->setUnsettable(false);
	m_eClassifier_EAttribute_classifierID->setUnique(true);
	m_eClassifier_EAttribute_classifierID->setDerived(false);
	m_eClassifier_EAttribute_classifierID->setOrdered(true);
	m_eClassifier_EAttribute_classifierID->setID(false);
	{
		std::string defaultValue = "-1";
		if (!defaultValue.empty())
		{
		   m_eClassifier_EAttribute_classifierID->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eClassifier_EAttribute_defaultValue = getEClassifier_EAttribute_defaultValue();
	m_eClassifier_EAttribute_defaultValue->setName("defaultValue");
	m_eClassifier_EAttribute_defaultValue->setEType(getEJavaObject_EDataType());
	m_eClassifier_EAttribute_defaultValue->setLowerBound(0);
	m_eClassifier_EAttribute_defaultValue->setUpperBound(1);
	m_eClassifier_EAttribute_defaultValue->setTransient(true);
	m_eClassifier_EAttribute_defaultValue->setVolatile(true);
	m_eClassifier_EAttribute_defaultValue->setChangeable(false);
	m_eClassifier_EAttribute_defaultValue->setUnsettable(false);
	m_eClassifier_EAttribute_defaultValue->setUnique(true);
	m_eClassifier_EAttribute_defaultValue->setDerived(true);
	m_eClassifier_EAttribute_defaultValue->setOrdered(true);
	m_eClassifier_EAttribute_defaultValue->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eClassifier_EAttribute_defaultValue->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eClassifier_EAttribute_instanceClass = getEClassifier_EAttribute_instanceClass();
	m_eClassifier_EAttribute_instanceClass->setName("instanceClass");
	m_eClassifier_EAttribute_instanceClass->setEType(getEJavaClass_EDataType());
	m_eClassifier_EAttribute_instanceClass->setLowerBound(0);
	m_eClassifier_EAttribute_instanceClass->setUpperBound(1);
	m_eClassifier_EAttribute_instanceClass->setTransient(true);
	m_eClassifier_EAttribute_instanceClass->setVolatile(true);
	m_eClassifier_EAttribute_instanceClass->setChangeable(true);
	m_eClassifier_EAttribute_instanceClass->setUnsettable(false);
	m_eClassifier_EAttribute_instanceClass->setUnique(true);
	m_eClassifier_EAttribute_instanceClass->setDerived(false);
	m_eClassifier_EAttribute_instanceClass->setOrdered(true);
	m_eClassifier_EAttribute_instanceClass->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eClassifier_EAttribute_instanceClass->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eClassifier_EAttribute_instanceClassName = getEClassifier_EAttribute_instanceClassName();
	m_eClassifier_EAttribute_instanceClassName->setName("instanceClassName");
	m_eClassifier_EAttribute_instanceClassName->setEType(getEString_EDataType());
	m_eClassifier_EAttribute_instanceClassName->setLowerBound(0);
	m_eClassifier_EAttribute_instanceClassName->setUpperBound(1);
	m_eClassifier_EAttribute_instanceClassName->setTransient(false);
	m_eClassifier_EAttribute_instanceClassName->setVolatile(true);
	m_eClassifier_EAttribute_instanceClassName->setChangeable(true);
	m_eClassifier_EAttribute_instanceClassName->setUnsettable(true);
	m_eClassifier_EAttribute_instanceClassName->setUnique(true);
	m_eClassifier_EAttribute_instanceClassName->setDerived(false);
	m_eClassifier_EAttribute_instanceClassName->setOrdered(true);
	m_eClassifier_EAttribute_instanceClassName->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eClassifier_EAttribute_instanceClassName->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eClassifier_EAttribute_instanceTypeName = getEClassifier_EAttribute_instanceTypeName();
	m_eClassifier_EAttribute_instanceTypeName->setName("instanceTypeName");
	m_eClassifier_EAttribute_instanceTypeName->setEType(getEString_EDataType());
	m_eClassifier_EAttribute_instanceTypeName->setLowerBound(0);
	m_eClassifier_EAttribute_instanceTypeName->setUpperBound(1);
	m_eClassifier_EAttribute_instanceTypeName->setTransient(false);
	m_eClassifier_EAttribute_instanceTypeName->setVolatile(true);
	m_eClassifier_EAttribute_instanceTypeName->setChangeable(true);
	m_eClassifier_EAttribute_instanceTypeName->setUnsettable(true);
	m_eClassifier_EAttribute_instanceTypeName->setUnique(true);
	m_eClassifier_EAttribute_instanceTypeName->setDerived(false);
	m_eClassifier_EAttribute_instanceTypeName->setOrdered(true);
	m_eClassifier_EAttribute_instanceTypeName->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eClassifier_EAttribute_instanceTypeName->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_eClassifier_EReference_ePackage->setName("ePackage");
	m_eClassifier_EReference_ePackage->setEType(getEPackage_EClass());
	m_eClassifier_EReference_ePackage->setLowerBound(0);
	m_eClassifier_EReference_ePackage->setUpperBound(1);
	m_eClassifier_EReference_ePackage->setTransient(true);
	m_eClassifier_EReference_ePackage->setVolatile(false);
	m_eClassifier_EReference_ePackage->setChangeable(true);
	m_eClassifier_EReference_ePackage->setUnsettable(false);
	m_eClassifier_EReference_ePackage->setUnique(true);
	m_eClassifier_EReference_ePackage->setDerived(false);
	m_eClassifier_EReference_ePackage->setOrdered(true);
	m_eClassifier_EReference_ePackage->setContainment(false);
	m_eClassifier_EReference_ePackage->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClassifier_EReference_ePackage->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEPackage_EReference_eClassifiers();
		if (otherEnd != nullptr)
	    {
	   		m_eClassifier_EReference_ePackage->setEOpposite(otherEnd);
	    }
	}
	m_eClassifier_EReference_eTypeParameters->setName("eTypeParameters");
	m_eClassifier_EReference_eTypeParameters->setEType(getETypeParameter_EClass());
	m_eClassifier_EReference_eTypeParameters->setLowerBound(0);
	m_eClassifier_EReference_eTypeParameters->setUpperBound(-1);
	m_eClassifier_EReference_eTypeParameters->setTransient(false);
	m_eClassifier_EReference_eTypeParameters->setVolatile(false);
	m_eClassifier_EReference_eTypeParameters->setChangeable(true);
	m_eClassifier_EReference_eTypeParameters->setUnsettable(false);
	m_eClassifier_EReference_eTypeParameters->setUnique(true);
	m_eClassifier_EReference_eTypeParameters->setDerived(false);
	m_eClassifier_EReference_eTypeParameters->setOrdered(true);
	m_eClassifier_EReference_eTypeParameters->setContainment(true);
	m_eClassifier_EReference_eTypeParameters->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClassifier_EReference_eTypeParameters->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eClassifier_EReference_eTypeParameters->setEOpposite(otherEnd);
	    }
	}
	
	m_eClassifier_EOperation_isInstance_EJavaObject->setEType(getEBoolean_EDataType());
	m_eClassifier_EOperation_isInstance_EJavaObject->setName("isInstance");
	m_eClassifier_EOperation_isInstance_EJavaObject->setLowerBound(0);
	m_eClassifier_EOperation_isInstance_EJavaObject->setUpperBound(1);
	m_eClassifier_EOperation_isInstance_EJavaObject->setUnique(true);
	m_eClassifier_EOperation_isInstance_EJavaObject->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eClassifier_EOperation_isInstance_EJavaObject);
		parameter->setName("object");
		parameter->setEType(getEJavaObject_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void EcorePackageImpl::initializeEDataTypeContent()
{
	m_eDataType_EClass->setInstanceClass(nullptr);
	m_eDataType_EClass->setName("EDataType");
	m_eDataType_EClass->setAbstract(false);
	m_eDataType_EClass->setInterface(false);
	
	m_eDataType_EAttribute_serializable = getEDataType_EAttribute_serializable();
	m_eDataType_EAttribute_serializable->setName("serializable");
	m_eDataType_EAttribute_serializable->setEType(getEBoolean_EDataType());
	m_eDataType_EAttribute_serializable->setLowerBound(0);
	m_eDataType_EAttribute_serializable->setUpperBound(1);
	m_eDataType_EAttribute_serializable->setTransient(false);
	m_eDataType_EAttribute_serializable->setVolatile(false);
	m_eDataType_EAttribute_serializable->setChangeable(true);
	m_eDataType_EAttribute_serializable->setUnsettable(false);
	m_eDataType_EAttribute_serializable->setUnique(true);
	m_eDataType_EAttribute_serializable->setDerived(false);
	m_eDataType_EAttribute_serializable->setOrdered(true);
	m_eDataType_EAttribute_serializable->setID(false);
	{
		std::string defaultValue = "true";
		if (!defaultValue.empty())
		{
		   m_eDataType_EAttribute_serializable->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	
}

void EcorePackageImpl::initializeEEnumContent()
{
	m_eEnum_EClass->setInstanceClass(nullptr);
	m_eEnum_EClass->setName("EEnum");
	m_eEnum_EClass->setAbstract(false);
	m_eEnum_EClass->setInterface(false);
	
	
	m_eEnum_EReference_eLiterals->setName("eLiterals");
	m_eEnum_EReference_eLiterals->setEType(getEEnumLiteral_EClass());
	m_eEnum_EReference_eLiterals->setLowerBound(0);
	m_eEnum_EReference_eLiterals->setUpperBound(-1);
	m_eEnum_EReference_eLiterals->setTransient(false);
	m_eEnum_EReference_eLiterals->setVolatile(false);
	m_eEnum_EReference_eLiterals->setChangeable(true);
	m_eEnum_EReference_eLiterals->setUnsettable(false);
	m_eEnum_EReference_eLiterals->setUnique(true);
	m_eEnum_EReference_eLiterals->setDerived(false);
	m_eEnum_EReference_eLiterals->setOrdered(true);
	m_eEnum_EReference_eLiterals->setContainment(true);
	m_eEnum_EReference_eLiterals->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eEnum_EReference_eLiterals->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEEnumLiteral_EReference_eEnum();
		if (otherEnd != nullptr)
	    {
	   		m_eEnum_EReference_eLiterals->setEOpposite(otherEnd);
	    }
	}
	
	m_eEnum_EOperation_getEEnumLiteral_EString->setEType(getEEnumLiteral_EClass());
	m_eEnum_EOperation_getEEnumLiteral_EString->setName("getEEnumLiteral");
	m_eEnum_EOperation_getEEnumLiteral_EString->setLowerBound(0);
	m_eEnum_EOperation_getEEnumLiteral_EString->setUpperBound(1);
	m_eEnum_EOperation_getEEnumLiteral_EString->setUnique(true);
	m_eEnum_EOperation_getEEnumLiteral_EString->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eEnum_EOperation_getEEnumLiteral_EString);
		parameter->setName("name");
		parameter->setEType(getEString_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eEnum_EOperation_getEEnumLiteral_EInt->setEType(getEEnumLiteral_EClass());
	m_eEnum_EOperation_getEEnumLiteral_EInt->setName("getEEnumLiteral");
	m_eEnum_EOperation_getEEnumLiteral_EInt->setLowerBound(0);
	m_eEnum_EOperation_getEEnumLiteral_EInt->setUpperBound(1);
	m_eEnum_EOperation_getEEnumLiteral_EInt->setUnique(true);
	m_eEnum_EOperation_getEEnumLiteral_EInt->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eEnum_EOperation_getEEnumLiteral_EInt);
		parameter->setName("value");
		parameter->setEType(getEInt_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eEnum_EOperation_getEEnumLiteralByLiteral_EString->setEType(getEEnumLiteral_EClass());
	m_eEnum_EOperation_getEEnumLiteralByLiteral_EString->setName("getEEnumLiteralByLiteral");
	m_eEnum_EOperation_getEEnumLiteralByLiteral_EString->setLowerBound(0);
	m_eEnum_EOperation_getEEnumLiteralByLiteral_EString->setUpperBound(1);
	m_eEnum_EOperation_getEEnumLiteralByLiteral_EString->setUnique(true);
	m_eEnum_EOperation_getEEnumLiteralByLiteral_EString->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eEnum_EOperation_getEEnumLiteralByLiteral_EString);
		parameter->setName("literal");
		parameter->setEType(getEString_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void EcorePackageImpl::initializeEEnumLiteralContent()
{
	m_eEnumLiteral_EClass->setInstanceClass(nullptr);
	m_eEnumLiteral_EClass->setName("EEnumLiteral");
	m_eEnumLiteral_EClass->setAbstract(false);
	m_eEnumLiteral_EClass->setInterface(false);
	
	m_eEnumLiteral_EAttribute_instance = getEEnumLiteral_EAttribute_instance();
	m_eEnumLiteral_EAttribute_instance->setName("instance");
	m_eEnumLiteral_EAttribute_instance->setEType(getEEnumerator_EDataType());
	m_eEnumLiteral_EAttribute_instance->setLowerBound(0);
	m_eEnumLiteral_EAttribute_instance->setUpperBound(1);
	m_eEnumLiteral_EAttribute_instance->setTransient(true);
	m_eEnumLiteral_EAttribute_instance->setVolatile(false);
	m_eEnumLiteral_EAttribute_instance->setChangeable(true);
	m_eEnumLiteral_EAttribute_instance->setUnsettable(false);
	m_eEnumLiteral_EAttribute_instance->setUnique(true);
	m_eEnumLiteral_EAttribute_instance->setDerived(false);
	m_eEnumLiteral_EAttribute_instance->setOrdered(true);
	m_eEnumLiteral_EAttribute_instance->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eEnumLiteral_EAttribute_instance->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eEnumLiteral_EAttribute_literal = getEEnumLiteral_EAttribute_literal();
	m_eEnumLiteral_EAttribute_literal->setName("literal");
	m_eEnumLiteral_EAttribute_literal->setEType(getEString_EDataType());
	m_eEnumLiteral_EAttribute_literal->setLowerBound(0);
	m_eEnumLiteral_EAttribute_literal->setUpperBound(1);
	m_eEnumLiteral_EAttribute_literal->setTransient(false);
	m_eEnumLiteral_EAttribute_literal->setVolatile(false);
	m_eEnumLiteral_EAttribute_literal->setChangeable(true);
	m_eEnumLiteral_EAttribute_literal->setUnsettable(false);
	m_eEnumLiteral_EAttribute_literal->setUnique(true);
	m_eEnumLiteral_EAttribute_literal->setDerived(false);
	m_eEnumLiteral_EAttribute_literal->setOrdered(true);
	m_eEnumLiteral_EAttribute_literal->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eEnumLiteral_EAttribute_literal->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eEnumLiteral_EAttribute_value = getEEnumLiteral_EAttribute_value();
	m_eEnumLiteral_EAttribute_value->setName("value");
	m_eEnumLiteral_EAttribute_value->setEType(getEInt_EDataType());
	m_eEnumLiteral_EAttribute_value->setLowerBound(0);
	m_eEnumLiteral_EAttribute_value->setUpperBound(1);
	m_eEnumLiteral_EAttribute_value->setTransient(false);
	m_eEnumLiteral_EAttribute_value->setVolatile(false);
	m_eEnumLiteral_EAttribute_value->setChangeable(true);
	m_eEnumLiteral_EAttribute_value->setUnsettable(false);
	m_eEnumLiteral_EAttribute_value->setUnique(true);
	m_eEnumLiteral_EAttribute_value->setDerived(false);
	m_eEnumLiteral_EAttribute_value->setOrdered(true);
	m_eEnumLiteral_EAttribute_value->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eEnumLiteral_EAttribute_value->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_eEnumLiteral_EReference_eEnum->setName("eEnum");
	m_eEnumLiteral_EReference_eEnum->setEType(getEEnum_EClass());
	m_eEnumLiteral_EReference_eEnum->setLowerBound(0);
	m_eEnumLiteral_EReference_eEnum->setUpperBound(1);
	m_eEnumLiteral_EReference_eEnum->setTransient(true);
	m_eEnumLiteral_EReference_eEnum->setVolatile(false);
	m_eEnumLiteral_EReference_eEnum->setChangeable(false);
	m_eEnumLiteral_EReference_eEnum->setUnsettable(false);
	m_eEnumLiteral_EReference_eEnum->setUnique(true);
	m_eEnumLiteral_EReference_eEnum->setDerived(false);
	m_eEnumLiteral_EReference_eEnum->setOrdered(true);
	m_eEnumLiteral_EReference_eEnum->setContainment(false);
	m_eEnumLiteral_EReference_eEnum->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eEnumLiteral_EReference_eEnum->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEEnum_EReference_eLiterals();
		if (otherEnd != nullptr)
	    {
	   		m_eEnumLiteral_EReference_eEnum->setEOpposite(otherEnd);
	    }
	}
	
	
}

void EcorePackageImpl::initializeEFactoryContent()
{
	m_eFactory_EClass->setInstanceClass(nullptr);
	m_eFactory_EClass->setName("EFactory");
	m_eFactory_EClass->setAbstract(false);
	m_eFactory_EClass->setInterface(false);
	
	
	m_eFactory_EReference_ePackage->setName("ePackage");
	m_eFactory_EReference_ePackage->setEType(getEPackage_EClass());
	m_eFactory_EReference_ePackage->setLowerBound(1);
	m_eFactory_EReference_ePackage->setUpperBound(1);
	m_eFactory_EReference_ePackage->setTransient(true);
	m_eFactory_EReference_ePackage->setVolatile(false);
	m_eFactory_EReference_ePackage->setChangeable(true);
	m_eFactory_EReference_ePackage->setUnsettable(false);
	m_eFactory_EReference_ePackage->setUnique(true);
	m_eFactory_EReference_ePackage->setDerived(false);
	m_eFactory_EReference_ePackage->setOrdered(true);
	m_eFactory_EReference_ePackage->setContainment(false);
	m_eFactory_EReference_ePackage->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eFactory_EReference_ePackage->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEPackage_EReference_eFactoryInstance();
		if (otherEnd != nullptr)
	    {
	   		m_eFactory_EReference_ePackage->setEOpposite(otherEnd);
	    }
	}
	
	m_eFactory_EOperation_convertToString_EDataType_EJavaObject->setEType(getEString_EDataType());
	m_eFactory_EOperation_convertToString_EDataType_EJavaObject->setName("convertToString");
	m_eFactory_EOperation_convertToString_EDataType_EJavaObject->setLowerBound(0);
	m_eFactory_EOperation_convertToString_EDataType_EJavaObject->setUpperBound(1);
	m_eFactory_EOperation_convertToString_EDataType_EJavaObject->setUnique(true);
	m_eFactory_EOperation_convertToString_EDataType_EJavaObject->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eFactory_EOperation_convertToString_EDataType_EJavaObject);
		parameter->setName("eDataType");
		parameter->setEType(getEDataType_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eFactory_EOperation_convertToString_EDataType_EJavaObject);
		parameter->setName("instanceValue");
		parameter->setEType(getEJavaObject_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eFactory_EOperation_create_EClass_EObject->setEType(getEObject_EClass());
	m_eFactory_EOperation_create_EClass_EObject->setName("create");
	m_eFactory_EOperation_create_EClass_EObject->setLowerBound(0);
	m_eFactory_EOperation_create_EClass_EObject->setUpperBound(1);
	m_eFactory_EOperation_create_EClass_EObject->setUnique(true);
	m_eFactory_EOperation_create_EClass_EObject->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eFactory_EOperation_create_EClass_EObject);
		parameter->setName("eClass");
		parameter->setEType(getEClass_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eFactory_EOperation_create_EClass_EObject);
		parameter->setName("container");
		parameter->setEType(getEObject_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eFactory_EOperation_createFromString_EDataType_EString->setEType(getEJavaObject_EDataType());
	m_eFactory_EOperation_createFromString_EDataType_EString->setName("createFromString");
	m_eFactory_EOperation_createFromString_EDataType_EString->setLowerBound(0);
	m_eFactory_EOperation_createFromString_EDataType_EString->setUpperBound(1);
	m_eFactory_EOperation_createFromString_EDataType_EString->setUnique(true);
	m_eFactory_EOperation_createFromString_EDataType_EString->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eFactory_EOperation_createFromString_EDataType_EString);
		parameter->setName("eDataType");
		parameter->setEType(getEDataType_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eFactory_EOperation_createFromString_EDataType_EString);
		parameter->setName("literalValue");
		parameter->setEType(getEString_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void EcorePackageImpl::initializeEGenericTypeContent()
{
	m_eGenericType_EClass->setInstanceClass(nullptr);
	m_eGenericType_EClass->setName("EGenericType");
	m_eGenericType_EClass->setAbstract(false);
	m_eGenericType_EClass->setInterface(false);
	
	
	m_eGenericType_EReference_eClassifier->setName("eClassifier");
	m_eGenericType_EReference_eClassifier->setEType(getEClassifier_EClass());
	m_eGenericType_EReference_eClassifier->setLowerBound(0);
	m_eGenericType_EReference_eClassifier->setUpperBound(1);
	m_eGenericType_EReference_eClassifier->setTransient(false);
	m_eGenericType_EReference_eClassifier->setVolatile(false);
	m_eGenericType_EReference_eClassifier->setChangeable(true);
	m_eGenericType_EReference_eClassifier->setUnsettable(false);
	m_eGenericType_EReference_eClassifier->setUnique(true);
	m_eGenericType_EReference_eClassifier->setDerived(false);
	m_eGenericType_EReference_eClassifier->setOrdered(true);
	m_eGenericType_EReference_eClassifier->setContainment(false);
	m_eGenericType_EReference_eClassifier->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eGenericType_EReference_eClassifier->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eGenericType_EReference_eClassifier->setEOpposite(otherEnd);
	    }
	}
	m_eGenericType_EReference_eLowerBound->setName("eLowerBound");
	m_eGenericType_EReference_eLowerBound->setEType(getEGenericType_EClass());
	m_eGenericType_EReference_eLowerBound->setLowerBound(0);
	m_eGenericType_EReference_eLowerBound->setUpperBound(1);
	m_eGenericType_EReference_eLowerBound->setTransient(false);
	m_eGenericType_EReference_eLowerBound->setVolatile(false);
	m_eGenericType_EReference_eLowerBound->setChangeable(true);
	m_eGenericType_EReference_eLowerBound->setUnsettable(false);
	m_eGenericType_EReference_eLowerBound->setUnique(true);
	m_eGenericType_EReference_eLowerBound->setDerived(false);
	m_eGenericType_EReference_eLowerBound->setOrdered(true);
	m_eGenericType_EReference_eLowerBound->setContainment(true);
	m_eGenericType_EReference_eLowerBound->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eGenericType_EReference_eLowerBound->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eGenericType_EReference_eLowerBound->setEOpposite(otherEnd);
	    }
	}
	m_eGenericType_EReference_eRawType->setName("eRawType");
	m_eGenericType_EReference_eRawType->setEType(getEClassifier_EClass());
	m_eGenericType_EReference_eRawType->setLowerBound(1);
	m_eGenericType_EReference_eRawType->setUpperBound(1);
	m_eGenericType_EReference_eRawType->setTransient(true);
	m_eGenericType_EReference_eRawType->setVolatile(false);
	m_eGenericType_EReference_eRawType->setChangeable(false);
	m_eGenericType_EReference_eRawType->setUnsettable(false);
	m_eGenericType_EReference_eRawType->setUnique(true);
	m_eGenericType_EReference_eRawType->setDerived(true);
	m_eGenericType_EReference_eRawType->setOrdered(true);
	m_eGenericType_EReference_eRawType->setContainment(false);
	m_eGenericType_EReference_eRawType->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eGenericType_EReference_eRawType->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eGenericType_EReference_eRawType->setEOpposite(otherEnd);
	    }
	}
	m_eGenericType_EReference_eTypeArguments->setName("eTypeArguments");
	m_eGenericType_EReference_eTypeArguments->setEType(getEGenericType_EClass());
	m_eGenericType_EReference_eTypeArguments->setLowerBound(0);
	m_eGenericType_EReference_eTypeArguments->setUpperBound(-1);
	m_eGenericType_EReference_eTypeArguments->setTransient(false);
	m_eGenericType_EReference_eTypeArguments->setVolatile(false);
	m_eGenericType_EReference_eTypeArguments->setChangeable(true);
	m_eGenericType_EReference_eTypeArguments->setUnsettable(false);
	m_eGenericType_EReference_eTypeArguments->setUnique(true);
	m_eGenericType_EReference_eTypeArguments->setDerived(false);
	m_eGenericType_EReference_eTypeArguments->setOrdered(true);
	m_eGenericType_EReference_eTypeArguments->setContainment(true);
	m_eGenericType_EReference_eTypeArguments->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eGenericType_EReference_eTypeArguments->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eGenericType_EReference_eTypeArguments->setEOpposite(otherEnd);
	    }
	}
	m_eGenericType_EReference_eTypeParameter->setName("eTypeParameter");
	m_eGenericType_EReference_eTypeParameter->setEType(getETypeParameter_EClass());
	m_eGenericType_EReference_eTypeParameter->setLowerBound(0);
	m_eGenericType_EReference_eTypeParameter->setUpperBound(1);
	m_eGenericType_EReference_eTypeParameter->setTransient(false);
	m_eGenericType_EReference_eTypeParameter->setVolatile(false);
	m_eGenericType_EReference_eTypeParameter->setChangeable(true);
	m_eGenericType_EReference_eTypeParameter->setUnsettable(false);
	m_eGenericType_EReference_eTypeParameter->setUnique(true);
	m_eGenericType_EReference_eTypeParameter->setDerived(false);
	m_eGenericType_EReference_eTypeParameter->setOrdered(true);
	m_eGenericType_EReference_eTypeParameter->setContainment(false);
	m_eGenericType_EReference_eTypeParameter->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eGenericType_EReference_eTypeParameter->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eGenericType_EReference_eTypeParameter->setEOpposite(otherEnd);
	    }
	}
	m_eGenericType_EReference_eUpperBound->setName("eUpperBound");
	m_eGenericType_EReference_eUpperBound->setEType(getEGenericType_EClass());
	m_eGenericType_EReference_eUpperBound->setLowerBound(0);
	m_eGenericType_EReference_eUpperBound->setUpperBound(1);
	m_eGenericType_EReference_eUpperBound->setTransient(false);
	m_eGenericType_EReference_eUpperBound->setVolatile(false);
	m_eGenericType_EReference_eUpperBound->setChangeable(true);
	m_eGenericType_EReference_eUpperBound->setUnsettable(false);
	m_eGenericType_EReference_eUpperBound->setUnique(true);
	m_eGenericType_EReference_eUpperBound->setDerived(false);
	m_eGenericType_EReference_eUpperBound->setOrdered(true);
	m_eGenericType_EReference_eUpperBound->setContainment(true);
	m_eGenericType_EReference_eUpperBound->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eGenericType_EReference_eUpperBound->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eGenericType_EReference_eUpperBound->setEOpposite(otherEnd);
	    }
	}
	
	m_eGenericType_EOperation_isInstance_EJavaObject->setEType(getEBoolean_EDataType());
	m_eGenericType_EOperation_isInstance_EJavaObject->setName("isInstance");
	m_eGenericType_EOperation_isInstance_EJavaObject->setLowerBound(0);
	m_eGenericType_EOperation_isInstance_EJavaObject->setUpperBound(1);
	m_eGenericType_EOperation_isInstance_EJavaObject->setUnique(true);
	m_eGenericType_EOperation_isInstance_EJavaObject->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eGenericType_EOperation_isInstance_EJavaObject);
		parameter->setName("object");
		parameter->setEType(getEJavaObject_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void EcorePackageImpl::initializeEModelElementContent()
{
	m_eModelElement_EClass->setInstanceClass(nullptr);
	m_eModelElement_EClass->setName("EModelElement");
	m_eModelElement_EClass->setAbstract(true);
	m_eModelElement_EClass->setInterface(false);
	
	
	m_eModelElement_EReference_eAnnotations->setName("eAnnotations");
	m_eModelElement_EReference_eAnnotations->setEType(getEAnnotation_EClass());
	m_eModelElement_EReference_eAnnotations->setLowerBound(0);
	m_eModelElement_EReference_eAnnotations->setUpperBound(-1);
	m_eModelElement_EReference_eAnnotations->setTransient(false);
	m_eModelElement_EReference_eAnnotations->setVolatile(false);
	m_eModelElement_EReference_eAnnotations->setChangeable(true);
	m_eModelElement_EReference_eAnnotations->setUnsettable(false);
	m_eModelElement_EReference_eAnnotations->setUnique(true);
	m_eModelElement_EReference_eAnnotations->setDerived(false);
	m_eModelElement_EReference_eAnnotations->setOrdered(true);
	m_eModelElement_EReference_eAnnotations->setContainment(true);
	m_eModelElement_EReference_eAnnotations->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eModelElement_EReference_eAnnotations->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEAnnotation_EReference_eModelElement();
		if (otherEnd != nullptr)
	    {
	   		m_eModelElement_EReference_eAnnotations->setEOpposite(otherEnd);
	    }
	}
	
	m_eModelElement_EOperation_getEAnnotation_EString->setEType(getEAnnotation_EClass());
	m_eModelElement_EOperation_getEAnnotation_EString->setName("getEAnnotation");
	m_eModelElement_EOperation_getEAnnotation_EString->setLowerBound(0);
	m_eModelElement_EOperation_getEAnnotation_EString->setUpperBound(1);
	m_eModelElement_EOperation_getEAnnotation_EString->setUnique(true);
	m_eModelElement_EOperation_getEAnnotation_EString->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eModelElement_EOperation_getEAnnotation_EString);
		parameter->setName("source");
		parameter->setEType(getEString_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void EcorePackageImpl::initializeENamedElementContent()
{
	m_eNamedElement_EClass->setInstanceClass(nullptr);
	m_eNamedElement_EClass->setName("ENamedElement");
	m_eNamedElement_EClass->setAbstract(true);
	m_eNamedElement_EClass->setInterface(false);
	
	m_eNamedElement_EAttribute_name = getENamedElement_EAttribute_name();
	m_eNamedElement_EAttribute_name->setName("name");
	m_eNamedElement_EAttribute_name->setEType(getEString_EDataType());
	m_eNamedElement_EAttribute_name->setLowerBound(0);
	m_eNamedElement_EAttribute_name->setUpperBound(1);
	m_eNamedElement_EAttribute_name->setTransient(false);
	m_eNamedElement_EAttribute_name->setVolatile(false);
	m_eNamedElement_EAttribute_name->setChangeable(true);
	m_eNamedElement_EAttribute_name->setUnsettable(false);
	m_eNamedElement_EAttribute_name->setUnique(true);
	m_eNamedElement_EAttribute_name->setDerived(false);
	m_eNamedElement_EAttribute_name->setOrdered(true);
	m_eNamedElement_EAttribute_name->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eNamedElement_EAttribute_name->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	
}

void EcorePackageImpl::initializeEObjectContent()
{
	m_eObject_EClass->setInstanceClass(nullptr);
	m_eObject_EClass->setName("EObject");
	m_eObject_EClass->setAbstract(false);
	m_eObject_EClass->setInterface(false);
	
	
	m_eObject_EReference_eContainer->setName("eContainer");
	m_eObject_EReference_eContainer->setEType(getEObject_EClass());
	m_eObject_EReference_eContainer->setLowerBound(0);
	m_eObject_EReference_eContainer->setUpperBound(1);
	m_eObject_EReference_eContainer->setTransient(false);
	m_eObject_EReference_eContainer->setVolatile(false);
	m_eObject_EReference_eContainer->setChangeable(false);
	m_eObject_EReference_eContainer->setUnsettable(false);
	m_eObject_EReference_eContainer->setUnique(true);
	m_eObject_EReference_eContainer->setDerived(false);
	m_eObject_EReference_eContainer->setOrdered(true);
	m_eObject_EReference_eContainer->setContainment(false);
	m_eObject_EReference_eContainer->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eObject_EReference_eContainer->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eObject_EReference_eContainer->setEOpposite(otherEnd);
	    }
	}
	
	m_eObject_EOperation_eAllContents->setEType(getETreeIterator_EDataType());
	m_eObject_EOperation_eAllContents->setName("eAllContents");
	m_eObject_EOperation_eAllContents->setLowerBound(0);
	m_eObject_EOperation_eAllContents->setUpperBound(1);
	m_eObject_EOperation_eAllContents->setUnique(true);
	m_eObject_EOperation_eAllContents->setOrdered(true);
	
	
	m_eObject_EOperation_eClass->setEType(getEClass_EClass());
	m_eObject_EOperation_eClass->setName("eClass");
	m_eObject_EOperation_eClass->setLowerBound(0);
	m_eObject_EOperation_eClass->setUpperBound(1);
	m_eObject_EOperation_eClass->setUnique(true);
	m_eObject_EOperation_eClass->setOrdered(true);
	
	
	m_eObject_EOperation_eContainingFeature->setEType(getEStructuralFeature_EClass());
	m_eObject_EOperation_eContainingFeature->setName("eContainingFeature");
	m_eObject_EOperation_eContainingFeature->setLowerBound(0);
	m_eObject_EOperation_eContainingFeature->setUpperBound(1);
	m_eObject_EOperation_eContainingFeature->setUnique(true);
	m_eObject_EOperation_eContainingFeature->setOrdered(true);
	
	
	m_eObject_EOperation_eContainmentFeature->setEType(getEReference_EClass());
	m_eObject_EOperation_eContainmentFeature->setName("eContainmentFeature");
	m_eObject_EOperation_eContainmentFeature->setLowerBound(0);
	m_eObject_EOperation_eContainmentFeature->setUpperBound(1);
	m_eObject_EOperation_eContainmentFeature->setUnique(true);
	m_eObject_EOperation_eContainmentFeature->setOrdered(true);
	
	
	m_eObject_EOperation_eContents->setEType(getEEList_EDataType());
	m_eObject_EOperation_eContents->setName("eContents");
	m_eObject_EOperation_eContents->setLowerBound(0);
	m_eObject_EOperation_eContents->setUpperBound(1);
	m_eObject_EOperation_eContents->setUnique(true);
	m_eObject_EOperation_eContents->setOrdered(true);
	
	
	m_eObject_EOperation_eCrossReferences->setEType(getEEList_EDataType());
	m_eObject_EOperation_eCrossReferences->setName("eCrossReferences");
	m_eObject_EOperation_eCrossReferences->setLowerBound(0);
	m_eObject_EOperation_eCrossReferences->setUpperBound(1);
	m_eObject_EOperation_eCrossReferences->setUnique(true);
	m_eObject_EOperation_eCrossReferences->setOrdered(true);
	
	
	m_eObject_EOperation_eGet_EStructuralFeature->setEType(getEJavaObject_EDataType());
	m_eObject_EOperation_eGet_EStructuralFeature->setName("eGet");
	m_eObject_EOperation_eGet_EStructuralFeature->setLowerBound(0);
	m_eObject_EOperation_eGet_EStructuralFeature->setUpperBound(1);
	m_eObject_EOperation_eGet_EStructuralFeature->setUnique(true);
	m_eObject_EOperation_eGet_EStructuralFeature->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eObject_EOperation_eGet_EStructuralFeature);
		parameter->setName("feature");
		parameter->setEType(getEStructuralFeature_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eObject_EOperation_eGet_EStructuralFeature_EBoolean->setEType(getEJavaObject_EDataType());
	m_eObject_EOperation_eGet_EStructuralFeature_EBoolean->setName("eGet");
	m_eObject_EOperation_eGet_EStructuralFeature_EBoolean->setLowerBound(0);
	m_eObject_EOperation_eGet_EStructuralFeature_EBoolean->setUpperBound(1);
	m_eObject_EOperation_eGet_EStructuralFeature_EBoolean->setUnique(true);
	m_eObject_EOperation_eGet_EStructuralFeature_EBoolean->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eObject_EOperation_eGet_EStructuralFeature_EBoolean);
		parameter->setName("feature");
		parameter->setEType(getEStructuralFeature_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eObject_EOperation_eGet_EStructuralFeature_EBoolean);
		parameter->setName("resolve");
		parameter->setEType(getEBoolean_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eObject_EOperation_eInvoke_EOperation_EEList->setEType(getEJavaObject_EDataType());
	m_eObject_EOperation_eInvoke_EOperation_EEList->setName("eInvoke");
	m_eObject_EOperation_eInvoke_EOperation_EEList->setLowerBound(0);
	m_eObject_EOperation_eInvoke_EOperation_EEList->setUpperBound(1);
	m_eObject_EOperation_eInvoke_EOperation_EEList->setUnique(true);
	m_eObject_EOperation_eInvoke_EOperation_EEList->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eObject_EOperation_eInvoke_EOperation_EEList);
		parameter->setName("operation");
		parameter->setEType(getEOperation_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eObject_EOperation_eInvoke_EOperation_EEList);
		parameter->setName("arguments");
		parameter->setEType(getEEList_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eObject_EOperation_eIsProxy->setEType(getEBoolean_EDataType());
	m_eObject_EOperation_eIsProxy->setName("eIsProxy");
	m_eObject_EOperation_eIsProxy->setLowerBound(0);
	m_eObject_EOperation_eIsProxy->setUpperBound(1);
	m_eObject_EOperation_eIsProxy->setUnique(true);
	m_eObject_EOperation_eIsProxy->setOrdered(true);
	
	
	m_eObject_EOperation_eIsSet_EStructuralFeature->setEType(getEBoolean_EDataType());
	m_eObject_EOperation_eIsSet_EStructuralFeature->setName("eIsSet");
	m_eObject_EOperation_eIsSet_EStructuralFeature->setLowerBound(0);
	m_eObject_EOperation_eIsSet_EStructuralFeature->setUpperBound(1);
	m_eObject_EOperation_eIsSet_EStructuralFeature->setUnique(true);
	m_eObject_EOperation_eIsSet_EStructuralFeature->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eObject_EOperation_eIsSet_EStructuralFeature);
		parameter->setName("feature");
		parameter->setEType(getEStructuralFeature_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eObject_EOperation_eResource->setEType(getEResource_EDataType());
	m_eObject_EOperation_eResource->setName("eResource");
	m_eObject_EOperation_eResource->setLowerBound(0);
	m_eObject_EOperation_eResource->setUpperBound(1);
	m_eObject_EOperation_eResource->setUnique(true);
	m_eObject_EOperation_eResource->setOrdered(true);
	
	
	m_eObject_EOperation_eSet_EStructuralFeature_EJavaObject->setEType(nullptr);
	m_eObject_EOperation_eSet_EStructuralFeature_EJavaObject->setName("eSet");
	m_eObject_EOperation_eSet_EStructuralFeature_EJavaObject->setLowerBound(0);
	m_eObject_EOperation_eSet_EStructuralFeature_EJavaObject->setUpperBound(1);
	m_eObject_EOperation_eSet_EStructuralFeature_EJavaObject->setUnique(true);
	m_eObject_EOperation_eSet_EStructuralFeature_EJavaObject->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eObject_EOperation_eSet_EStructuralFeature_EJavaObject);
		parameter->setName("feature");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eObject_EOperation_eSet_EStructuralFeature_EJavaObject);
		parameter->setName("newValue");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eObject_EOperation_eUnset_EStructuralFeature->setEType(nullptr);
	m_eObject_EOperation_eUnset_EStructuralFeature->setName("eUnset");
	m_eObject_EOperation_eUnset_EStructuralFeature->setLowerBound(0);
	m_eObject_EOperation_eUnset_EStructuralFeature->setUpperBound(1);
	m_eObject_EOperation_eUnset_EStructuralFeature->setUnique(true);
	m_eObject_EOperation_eUnset_EStructuralFeature->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eObject_EOperation_eUnset_EStructuralFeature);
		parameter->setName("feature");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void EcorePackageImpl::initializeEOperationContent()
{
	m_eOperation_EClass->setInstanceClass(nullptr);
	m_eOperation_EClass->setName("EOperation");
	m_eOperation_EClass->setAbstract(false);
	m_eOperation_EClass->setInterface(false);
	
	m_eOperation_EAttribute_operationID = getEOperation_EAttribute_operationID();
	m_eOperation_EAttribute_operationID->setName("operationID");
	m_eOperation_EAttribute_operationID->setEType(getEInt_EDataType());
	m_eOperation_EAttribute_operationID->setLowerBound(0);
	m_eOperation_EAttribute_operationID->setUpperBound(1);
	m_eOperation_EAttribute_operationID->setTransient(false);
	m_eOperation_EAttribute_operationID->setVolatile(false);
	m_eOperation_EAttribute_operationID->setChangeable(false);
	m_eOperation_EAttribute_operationID->setUnsettable(false);
	m_eOperation_EAttribute_operationID->setUnique(true);
	m_eOperation_EAttribute_operationID->setDerived(false);
	m_eOperation_EAttribute_operationID->setOrdered(true);
	m_eOperation_EAttribute_operationID->setID(false);
	{
		std::string defaultValue = "-1";
		if (!defaultValue.empty())
		{
		   m_eOperation_EAttribute_operationID->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_eOperation_EReference_eContainingClass->setName("eContainingClass");
	m_eOperation_EReference_eContainingClass->setEType(getEClass_EClass());
	m_eOperation_EReference_eContainingClass->setLowerBound(0);
	m_eOperation_EReference_eContainingClass->setUpperBound(1);
	m_eOperation_EReference_eContainingClass->setTransient(true);
	m_eOperation_EReference_eContainingClass->setVolatile(false);
	m_eOperation_EReference_eContainingClass->setChangeable(false);
	m_eOperation_EReference_eContainingClass->setUnsettable(false);
	m_eOperation_EReference_eContainingClass->setUnique(true);
	m_eOperation_EReference_eContainingClass->setDerived(false);
	m_eOperation_EReference_eContainingClass->setOrdered(true);
	m_eOperation_EReference_eContainingClass->setContainment(false);
	m_eOperation_EReference_eContainingClass->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eOperation_EReference_eContainingClass->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEClass_EReference_eOperations();
		if (otherEnd != nullptr)
	    {
	   		m_eOperation_EReference_eContainingClass->setEOpposite(otherEnd);
	    }
	}
	m_eOperation_EReference_eExceptions->setName("eExceptions");
	m_eOperation_EReference_eExceptions->setEType(getEClassifier_EClass());
	m_eOperation_EReference_eExceptions->setLowerBound(0);
	m_eOperation_EReference_eExceptions->setUpperBound(-1);
	m_eOperation_EReference_eExceptions->setTransient(false);
	m_eOperation_EReference_eExceptions->setVolatile(false);
	m_eOperation_EReference_eExceptions->setChangeable(true);
	m_eOperation_EReference_eExceptions->setUnsettable(true);
	m_eOperation_EReference_eExceptions->setUnique(true);
	m_eOperation_EReference_eExceptions->setDerived(false);
	m_eOperation_EReference_eExceptions->setOrdered(true);
	m_eOperation_EReference_eExceptions->setContainment(false);
	m_eOperation_EReference_eExceptions->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eOperation_EReference_eExceptions->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eOperation_EReference_eExceptions->setEOpposite(otherEnd);
	    }
	}
	m_eOperation_EReference_eGenericExceptions->setName("eGenericExceptions");
	m_eOperation_EReference_eGenericExceptions->setEType(getEGenericType_EClass());
	m_eOperation_EReference_eGenericExceptions->setLowerBound(0);
	m_eOperation_EReference_eGenericExceptions->setUpperBound(-1);
	m_eOperation_EReference_eGenericExceptions->setTransient(false);
	m_eOperation_EReference_eGenericExceptions->setVolatile(false);
	m_eOperation_EReference_eGenericExceptions->setChangeable(true);
	m_eOperation_EReference_eGenericExceptions->setUnsettable(true);
	m_eOperation_EReference_eGenericExceptions->setUnique(true);
	m_eOperation_EReference_eGenericExceptions->setDerived(false);
	m_eOperation_EReference_eGenericExceptions->setOrdered(true);
	m_eOperation_EReference_eGenericExceptions->setContainment(true);
	m_eOperation_EReference_eGenericExceptions->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eOperation_EReference_eGenericExceptions->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eOperation_EReference_eGenericExceptions->setEOpposite(otherEnd);
	    }
	}
	m_eOperation_EReference_eParameters->setName("eParameters");
	m_eOperation_EReference_eParameters->setEType(getEParameter_EClass());
	m_eOperation_EReference_eParameters->setLowerBound(0);
	m_eOperation_EReference_eParameters->setUpperBound(-1);
	m_eOperation_EReference_eParameters->setTransient(false);
	m_eOperation_EReference_eParameters->setVolatile(false);
	m_eOperation_EReference_eParameters->setChangeable(true);
	m_eOperation_EReference_eParameters->setUnsettable(false);
	m_eOperation_EReference_eParameters->setUnique(true);
	m_eOperation_EReference_eParameters->setDerived(false);
	m_eOperation_EReference_eParameters->setOrdered(true);
	m_eOperation_EReference_eParameters->setContainment(true);
	m_eOperation_EReference_eParameters->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eOperation_EReference_eParameters->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEParameter_EReference_eOperation();
		if (otherEnd != nullptr)
	    {
	   		m_eOperation_EReference_eParameters->setEOpposite(otherEnd);
	    }
	}
	m_eOperation_EReference_eTypeParameters->setName("eTypeParameters");
	m_eOperation_EReference_eTypeParameters->setEType(getETypeParameter_EClass());
	m_eOperation_EReference_eTypeParameters->setLowerBound(0);
	m_eOperation_EReference_eTypeParameters->setUpperBound(-1);
	m_eOperation_EReference_eTypeParameters->setTransient(false);
	m_eOperation_EReference_eTypeParameters->setVolatile(false);
	m_eOperation_EReference_eTypeParameters->setChangeable(true);
	m_eOperation_EReference_eTypeParameters->setUnsettable(false);
	m_eOperation_EReference_eTypeParameters->setUnique(true);
	m_eOperation_EReference_eTypeParameters->setDerived(false);
	m_eOperation_EReference_eTypeParameters->setOrdered(true);
	m_eOperation_EReference_eTypeParameters->setContainment(true);
	m_eOperation_EReference_eTypeParameters->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eOperation_EReference_eTypeParameters->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eOperation_EReference_eTypeParameters->setEOpposite(otherEnd);
	    }
	}
	
	m_eOperation_EOperation_isOverrideOf_EOperation->setEType(getEBoolean_EDataType());
	m_eOperation_EOperation_isOverrideOf_EOperation->setName("isOverrideOf");
	m_eOperation_EOperation_isOverrideOf_EOperation->setLowerBound(0);
	m_eOperation_EOperation_isOverrideOf_EOperation->setUpperBound(1);
	m_eOperation_EOperation_isOverrideOf_EOperation->setUnique(true);
	m_eOperation_EOperation_isOverrideOf_EOperation->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eOperation_EOperation_isOverrideOf_EOperation);
		parameter->setName("someOperation");
		parameter->setEType(getEOperation_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void EcorePackageImpl::initializeEPackageContent()
{
	m_ePackage_EClass->setInstanceClass(nullptr);
	m_ePackage_EClass->setName("EPackage");
	m_ePackage_EClass->setAbstract(false);
	m_ePackage_EClass->setInterface(false);
	
	m_ePackage_EAttribute_nsPrefix = getEPackage_EAttribute_nsPrefix();
	m_ePackage_EAttribute_nsPrefix->setName("nsPrefix");
	m_ePackage_EAttribute_nsPrefix->setEType(getEString_EDataType());
	m_ePackage_EAttribute_nsPrefix->setLowerBound(0);
	m_ePackage_EAttribute_nsPrefix->setUpperBound(1);
	m_ePackage_EAttribute_nsPrefix->setTransient(false);
	m_ePackage_EAttribute_nsPrefix->setVolatile(false);
	m_ePackage_EAttribute_nsPrefix->setChangeable(true);
	m_ePackage_EAttribute_nsPrefix->setUnsettable(false);
	m_ePackage_EAttribute_nsPrefix->setUnique(true);
	m_ePackage_EAttribute_nsPrefix->setDerived(false);
	m_ePackage_EAttribute_nsPrefix->setOrdered(true);
	m_ePackage_EAttribute_nsPrefix->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_ePackage_EAttribute_nsPrefix->setDefaultValueLiteral(defaultValue);
		}
	}
	m_ePackage_EAttribute_nsURI = getEPackage_EAttribute_nsURI();
	m_ePackage_EAttribute_nsURI->setName("nsURI");
	m_ePackage_EAttribute_nsURI->setEType(getEString_EDataType());
	m_ePackage_EAttribute_nsURI->setLowerBound(0);
	m_ePackage_EAttribute_nsURI->setUpperBound(1);
	m_ePackage_EAttribute_nsURI->setTransient(false);
	m_ePackage_EAttribute_nsURI->setVolatile(false);
	m_ePackage_EAttribute_nsURI->setChangeable(true);
	m_ePackage_EAttribute_nsURI->setUnsettable(false);
	m_ePackage_EAttribute_nsURI->setUnique(true);
	m_ePackage_EAttribute_nsURI->setDerived(false);
	m_ePackage_EAttribute_nsURI->setOrdered(true);
	m_ePackage_EAttribute_nsURI->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_ePackage_EAttribute_nsURI->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_ePackage_EReference_eClassifiers->setName("eClassifiers");
	m_ePackage_EReference_eClassifiers->setEType(getEClassifier_EClass());
	m_ePackage_EReference_eClassifiers->setLowerBound(0);
	m_ePackage_EReference_eClassifiers->setUpperBound(-1);
	m_ePackage_EReference_eClassifiers->setTransient(false);
	m_ePackage_EReference_eClassifiers->setVolatile(false);
	m_ePackage_EReference_eClassifiers->setChangeable(true);
	m_ePackage_EReference_eClassifiers->setUnsettable(false);
	m_ePackage_EReference_eClassifiers->setUnique(true);
	m_ePackage_EReference_eClassifiers->setDerived(false);
	m_ePackage_EReference_eClassifiers->setOrdered(true);
	m_ePackage_EReference_eClassifiers->setContainment(true);
	m_ePackage_EReference_eClassifiers->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_ePackage_EReference_eClassifiers->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEClassifier_EReference_ePackage();
		if (otherEnd != nullptr)
	    {
	   		m_ePackage_EReference_eClassifiers->setEOpposite(otherEnd);
	    }
	}
	m_ePackage_EReference_eFactoryInstance->setName("eFactoryInstance");
	m_ePackage_EReference_eFactoryInstance->setEType(getEFactory_EClass());
	m_ePackage_EReference_eFactoryInstance->setLowerBound(1);
	m_ePackage_EReference_eFactoryInstance->setUpperBound(1);
	m_ePackage_EReference_eFactoryInstance->setTransient(true);
	m_ePackage_EReference_eFactoryInstance->setVolatile(false);
	m_ePackage_EReference_eFactoryInstance->setChangeable(true);
	m_ePackage_EReference_eFactoryInstance->setUnsettable(false);
	m_ePackage_EReference_eFactoryInstance->setUnique(true);
	m_ePackage_EReference_eFactoryInstance->setDerived(false);
	m_ePackage_EReference_eFactoryInstance->setOrdered(true);
	m_ePackage_EReference_eFactoryInstance->setContainment(false);
	m_ePackage_EReference_eFactoryInstance->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_ePackage_EReference_eFactoryInstance->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEFactory_EReference_ePackage();
		if (otherEnd != nullptr)
	    {
	   		m_ePackage_EReference_eFactoryInstance->setEOpposite(otherEnd);
	    }
	}
	m_ePackage_EReference_eSubpackages->setName("eSubpackages");
	m_ePackage_EReference_eSubpackages->setEType(getEPackage_EClass());
	m_ePackage_EReference_eSubpackages->setLowerBound(0);
	m_ePackage_EReference_eSubpackages->setUpperBound(-1);
	m_ePackage_EReference_eSubpackages->setTransient(false);
	m_ePackage_EReference_eSubpackages->setVolatile(false);
	m_ePackage_EReference_eSubpackages->setChangeable(true);
	m_ePackage_EReference_eSubpackages->setUnsettable(false);
	m_ePackage_EReference_eSubpackages->setUnique(true);
	m_ePackage_EReference_eSubpackages->setDerived(false);
	m_ePackage_EReference_eSubpackages->setOrdered(true);
	m_ePackage_EReference_eSubpackages->setContainment(true);
	m_ePackage_EReference_eSubpackages->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_ePackage_EReference_eSubpackages->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEPackage_EReference_eSuperPackage();
		if (otherEnd != nullptr)
	    {
	   		m_ePackage_EReference_eSubpackages->setEOpposite(otherEnd);
	    }
	}
	m_ePackage_EReference_eSuperPackage->setName("eSuperPackage");
	m_ePackage_EReference_eSuperPackage->setEType(getEPackage_EClass());
	m_ePackage_EReference_eSuperPackage->setLowerBound(0);
	m_ePackage_EReference_eSuperPackage->setUpperBound(1);
	m_ePackage_EReference_eSuperPackage->setTransient(true);
	m_ePackage_EReference_eSuperPackage->setVolatile(false);
	m_ePackage_EReference_eSuperPackage->setChangeable(false);
	m_ePackage_EReference_eSuperPackage->setUnsettable(false);
	m_ePackage_EReference_eSuperPackage->setUnique(true);
	m_ePackage_EReference_eSuperPackage->setDerived(false);
	m_ePackage_EReference_eSuperPackage->setOrdered(true);
	m_ePackage_EReference_eSuperPackage->setContainment(false);
	m_ePackage_EReference_eSuperPackage->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_ePackage_EReference_eSuperPackage->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEPackage_EReference_eSubpackages();
		if (otherEnd != nullptr)
	    {
	   		m_ePackage_EReference_eSuperPackage->setEOpposite(otherEnd);
	    }
	}
	
	m_ePackage_EOperation_getEClassifier_EString->setEType(getEClassifier_EClass());
	m_ePackage_EOperation_getEClassifier_EString->setName("getEClassifier");
	m_ePackage_EOperation_getEClassifier_EString->setLowerBound(0);
	m_ePackage_EOperation_getEClassifier_EString->setUpperBound(1);
	m_ePackage_EOperation_getEClassifier_EString->setUnique(true);
	m_ePackage_EOperation_getEClassifier_EString->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_ePackage_EOperation_getEClassifier_EString);
		parameter->setName("name");
		parameter->setEType(getEString_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void EcorePackageImpl::initializeEParameterContent()
{
	m_eParameter_EClass->setInstanceClass(nullptr);
	m_eParameter_EClass->setName("EParameter");
	m_eParameter_EClass->setAbstract(false);
	m_eParameter_EClass->setInterface(false);
	
	
	m_eParameter_EReference_eOperation->setName("eOperation");
	m_eParameter_EReference_eOperation->setEType(getEOperation_EClass());
	m_eParameter_EReference_eOperation->setLowerBound(0);
	m_eParameter_EReference_eOperation->setUpperBound(1);
	m_eParameter_EReference_eOperation->setTransient(true);
	m_eParameter_EReference_eOperation->setVolatile(false);
	m_eParameter_EReference_eOperation->setChangeable(false);
	m_eParameter_EReference_eOperation->setUnsettable(false);
	m_eParameter_EReference_eOperation->setUnique(true);
	m_eParameter_EReference_eOperation->setDerived(false);
	m_eParameter_EReference_eOperation->setOrdered(true);
	m_eParameter_EReference_eOperation->setContainment(false);
	m_eParameter_EReference_eOperation->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eParameter_EReference_eOperation->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEOperation_EReference_eParameters();
		if (otherEnd != nullptr)
	    {
	   		m_eParameter_EReference_eOperation->setEOpposite(otherEnd);
	    }
	}
	
	
}

void EcorePackageImpl::initializeEReferenceContent()
{
	m_eReference_EClass->setInstanceClass(nullptr);
	m_eReference_EClass->setName("EReference");
	m_eReference_EClass->setAbstract(false);
	m_eReference_EClass->setInterface(false);
	
	m_eReference_EAttribute_container = getEReference_EAttribute_container();
	m_eReference_EAttribute_container->setName("container");
	m_eReference_EAttribute_container->setEType(getEBoolean_EDataType());
	m_eReference_EAttribute_container->setLowerBound(0);
	m_eReference_EAttribute_container->setUpperBound(1);
	m_eReference_EAttribute_container->setTransient(true);
	m_eReference_EAttribute_container->setVolatile(true);
	m_eReference_EAttribute_container->setChangeable(false);
	m_eReference_EAttribute_container->setUnsettable(false);
	m_eReference_EAttribute_container->setUnique(true);
	m_eReference_EAttribute_container->setDerived(true);
	m_eReference_EAttribute_container->setOrdered(true);
	m_eReference_EAttribute_container->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eReference_EAttribute_container->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eReference_EAttribute_containment = getEReference_EAttribute_containment();
	m_eReference_EAttribute_containment->setName("containment");
	m_eReference_EAttribute_containment->setEType(getEBoolean_EDataType());
	m_eReference_EAttribute_containment->setLowerBound(0);
	m_eReference_EAttribute_containment->setUpperBound(1);
	m_eReference_EAttribute_containment->setTransient(false);
	m_eReference_EAttribute_containment->setVolatile(false);
	m_eReference_EAttribute_containment->setChangeable(true);
	m_eReference_EAttribute_containment->setUnsettable(false);
	m_eReference_EAttribute_containment->setUnique(true);
	m_eReference_EAttribute_containment->setDerived(false);
	m_eReference_EAttribute_containment->setOrdered(true);
	m_eReference_EAttribute_containment->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eReference_EAttribute_containment->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eReference_EAttribute_resolveProxies = getEReference_EAttribute_resolveProxies();
	m_eReference_EAttribute_resolveProxies->setName("resolveProxies");
	m_eReference_EAttribute_resolveProxies->setEType(getEBoolean_EDataType());
	m_eReference_EAttribute_resolveProxies->setLowerBound(0);
	m_eReference_EAttribute_resolveProxies->setUpperBound(1);
	m_eReference_EAttribute_resolveProxies->setTransient(false);
	m_eReference_EAttribute_resolveProxies->setVolatile(false);
	m_eReference_EAttribute_resolveProxies->setChangeable(true);
	m_eReference_EAttribute_resolveProxies->setUnsettable(false);
	m_eReference_EAttribute_resolveProxies->setUnique(true);
	m_eReference_EAttribute_resolveProxies->setDerived(false);
	m_eReference_EAttribute_resolveProxies->setOrdered(true);
	m_eReference_EAttribute_resolveProxies->setID(false);
	{
		std::string defaultValue = "true";
		if (!defaultValue.empty())
		{
		   m_eReference_EAttribute_resolveProxies->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_eReference_EReference_eKeys->setName("eKeys");
	m_eReference_EReference_eKeys->setEType(getEAttribute_EClass());
	m_eReference_EReference_eKeys->setLowerBound(0);
	m_eReference_EReference_eKeys->setUpperBound(-1);
	m_eReference_EReference_eKeys->setTransient(false);
	m_eReference_EReference_eKeys->setVolatile(false);
	m_eReference_EReference_eKeys->setChangeable(true);
	m_eReference_EReference_eKeys->setUnsettable(false);
	m_eReference_EReference_eKeys->setUnique(true);
	m_eReference_EReference_eKeys->setDerived(false);
	m_eReference_EReference_eKeys->setOrdered(true);
	m_eReference_EReference_eKeys->setContainment(false);
	m_eReference_EReference_eKeys->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eReference_EReference_eKeys->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eReference_EReference_eKeys->setEOpposite(otherEnd);
	    }
	}
	m_eReference_EReference_eOpposite->setName("eOpposite");
	m_eReference_EReference_eOpposite->setEType(getEReference_EClass());
	m_eReference_EReference_eOpposite->setLowerBound(0);
	m_eReference_EReference_eOpposite->setUpperBound(1);
	m_eReference_EReference_eOpposite->setTransient(false);
	m_eReference_EReference_eOpposite->setVolatile(false);
	m_eReference_EReference_eOpposite->setChangeable(true);
	m_eReference_EReference_eOpposite->setUnsettable(false);
	m_eReference_EReference_eOpposite->setUnique(true);
	m_eReference_EReference_eOpposite->setDerived(false);
	m_eReference_EReference_eOpposite->setOrdered(true);
	m_eReference_EReference_eOpposite->setContainment(false);
	m_eReference_EReference_eOpposite->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eReference_EReference_eOpposite->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eReference_EReference_eOpposite->setEOpposite(otherEnd);
	    }
	}
	m_eReference_EReference_eReferenceType->setName("eReferenceType");
	m_eReference_EReference_eReferenceType->setEType(getEClass_EClass());
	m_eReference_EReference_eReferenceType->setLowerBound(1);
	m_eReference_EReference_eReferenceType->setUpperBound(1);
	m_eReference_EReference_eReferenceType->setTransient(true);
	m_eReference_EReference_eReferenceType->setVolatile(true);
	m_eReference_EReference_eReferenceType->setChangeable(false);
	m_eReference_EReference_eReferenceType->setUnsettable(false);
	m_eReference_EReference_eReferenceType->setUnique(true);
	m_eReference_EReference_eReferenceType->setDerived(true);
	m_eReference_EReference_eReferenceType->setOrdered(true);
	m_eReference_EReference_eReferenceType->setContainment(false);
	m_eReference_EReference_eReferenceType->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eReference_EReference_eReferenceType->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eReference_EReference_eReferenceType->setEOpposite(otherEnd);
	    }
	}
	
	
}

void EcorePackageImpl::initializeEStringToStringMapEntryContent()
{
	m_eStringToStringMapEntry_EClass->setInstanceClass(nullptr);
	m_eStringToStringMapEntry_EClass->setName("EStringToStringMapEntry");
	m_eStringToStringMapEntry_EClass->setAbstract(false);
	m_eStringToStringMapEntry_EClass->setInterface(false);
	
	m_eStringToStringMapEntry_EAttribute_key = getEStringToStringMapEntry_EAttribute_key();
	m_eStringToStringMapEntry_EAttribute_key->setName("key");
	m_eStringToStringMapEntry_EAttribute_key->setEType(getEString_EDataType());
	m_eStringToStringMapEntry_EAttribute_key->setLowerBound(0);
	m_eStringToStringMapEntry_EAttribute_key->setUpperBound(1);
	m_eStringToStringMapEntry_EAttribute_key->setTransient(false);
	m_eStringToStringMapEntry_EAttribute_key->setVolatile(false);
	m_eStringToStringMapEntry_EAttribute_key->setChangeable(true);
	m_eStringToStringMapEntry_EAttribute_key->setUnsettable(false);
	m_eStringToStringMapEntry_EAttribute_key->setUnique(true);
	m_eStringToStringMapEntry_EAttribute_key->setDerived(false);
	m_eStringToStringMapEntry_EAttribute_key->setOrdered(true);
	m_eStringToStringMapEntry_EAttribute_key->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eStringToStringMapEntry_EAttribute_key->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eStringToStringMapEntry_EAttribute_value = getEStringToStringMapEntry_EAttribute_value();
	m_eStringToStringMapEntry_EAttribute_value->setName("value");
	m_eStringToStringMapEntry_EAttribute_value->setEType(getEString_EDataType());
	m_eStringToStringMapEntry_EAttribute_value->setLowerBound(0);
	m_eStringToStringMapEntry_EAttribute_value->setUpperBound(1);
	m_eStringToStringMapEntry_EAttribute_value->setTransient(false);
	m_eStringToStringMapEntry_EAttribute_value->setVolatile(false);
	m_eStringToStringMapEntry_EAttribute_value->setChangeable(true);
	m_eStringToStringMapEntry_EAttribute_value->setUnsettable(false);
	m_eStringToStringMapEntry_EAttribute_value->setUnique(true);
	m_eStringToStringMapEntry_EAttribute_value->setDerived(false);
	m_eStringToStringMapEntry_EAttribute_value->setOrdered(true);
	m_eStringToStringMapEntry_EAttribute_value->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eStringToStringMapEntry_EAttribute_value->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	
}

void EcorePackageImpl::initializeEStructuralFeatureContent()
{
	m_eStructuralFeature_EClass->setInstanceClass(nullptr);
	m_eStructuralFeature_EClass->setName("EStructuralFeature");
	m_eStructuralFeature_EClass->setAbstract(true);
	m_eStructuralFeature_EClass->setInterface(false);
	
	m_eStructuralFeature_EAttribute_changeable = getEStructuralFeature_EAttribute_changeable();
	m_eStructuralFeature_EAttribute_changeable->setName("changeable");
	m_eStructuralFeature_EAttribute_changeable->setEType(getEBoolean_EDataType());
	m_eStructuralFeature_EAttribute_changeable->setLowerBound(0);
	m_eStructuralFeature_EAttribute_changeable->setUpperBound(1);
	m_eStructuralFeature_EAttribute_changeable->setTransient(false);
	m_eStructuralFeature_EAttribute_changeable->setVolatile(false);
	m_eStructuralFeature_EAttribute_changeable->setChangeable(true);
	m_eStructuralFeature_EAttribute_changeable->setUnsettable(false);
	m_eStructuralFeature_EAttribute_changeable->setUnique(true);
	m_eStructuralFeature_EAttribute_changeable->setDerived(false);
	m_eStructuralFeature_EAttribute_changeable->setOrdered(true);
	m_eStructuralFeature_EAttribute_changeable->setID(false);
	{
		std::string defaultValue = "true";
		if (!defaultValue.empty())
		{
		   m_eStructuralFeature_EAttribute_changeable->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eStructuralFeature_EAttribute_containerClass = getEStructuralFeature_EAttribute_containerClass();
	m_eStructuralFeature_EAttribute_containerClass->setName("containerClass");
	m_eStructuralFeature_EAttribute_containerClass->setEType(getEJavaClass_EDataType());
	m_eStructuralFeature_EAttribute_containerClass->setLowerBound(0);
	m_eStructuralFeature_EAttribute_containerClass->setUpperBound(1);
	m_eStructuralFeature_EAttribute_containerClass->setTransient(false);
	m_eStructuralFeature_EAttribute_containerClass->setVolatile(false);
	m_eStructuralFeature_EAttribute_containerClass->setChangeable(false);
	m_eStructuralFeature_EAttribute_containerClass->setUnsettable(false);
	m_eStructuralFeature_EAttribute_containerClass->setUnique(true);
	m_eStructuralFeature_EAttribute_containerClass->setDerived(false);
	m_eStructuralFeature_EAttribute_containerClass->setOrdered(true);
	m_eStructuralFeature_EAttribute_containerClass->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eStructuralFeature_EAttribute_containerClass->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eStructuralFeature_EAttribute_defaultValue = getEStructuralFeature_EAttribute_defaultValue();
	m_eStructuralFeature_EAttribute_defaultValue->setName("defaultValue");
	m_eStructuralFeature_EAttribute_defaultValue->setEType(getEJavaObject_EDataType());
	m_eStructuralFeature_EAttribute_defaultValue->setLowerBound(0);
	m_eStructuralFeature_EAttribute_defaultValue->setUpperBound(1);
	m_eStructuralFeature_EAttribute_defaultValue->setTransient(true);
	m_eStructuralFeature_EAttribute_defaultValue->setVolatile(true);
	m_eStructuralFeature_EAttribute_defaultValue->setChangeable(false);
	m_eStructuralFeature_EAttribute_defaultValue->setUnsettable(false);
	m_eStructuralFeature_EAttribute_defaultValue->setUnique(true);
	m_eStructuralFeature_EAttribute_defaultValue->setDerived(true);
	m_eStructuralFeature_EAttribute_defaultValue->setOrdered(true);
	m_eStructuralFeature_EAttribute_defaultValue->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eStructuralFeature_EAttribute_defaultValue->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eStructuralFeature_EAttribute_defaultValueLiteral = getEStructuralFeature_EAttribute_defaultValueLiteral();
	m_eStructuralFeature_EAttribute_defaultValueLiteral->setName("defaultValueLiteral");
	m_eStructuralFeature_EAttribute_defaultValueLiteral->setEType(getEString_EDataType());
	m_eStructuralFeature_EAttribute_defaultValueLiteral->setLowerBound(0);
	m_eStructuralFeature_EAttribute_defaultValueLiteral->setUpperBound(1);
	m_eStructuralFeature_EAttribute_defaultValueLiteral->setTransient(false);
	m_eStructuralFeature_EAttribute_defaultValueLiteral->setVolatile(false);
	m_eStructuralFeature_EAttribute_defaultValueLiteral->setChangeable(true);
	m_eStructuralFeature_EAttribute_defaultValueLiteral->setUnsettable(false);
	m_eStructuralFeature_EAttribute_defaultValueLiteral->setUnique(true);
	m_eStructuralFeature_EAttribute_defaultValueLiteral->setDerived(false);
	m_eStructuralFeature_EAttribute_defaultValueLiteral->setOrdered(true);
	m_eStructuralFeature_EAttribute_defaultValueLiteral->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eStructuralFeature_EAttribute_defaultValueLiteral->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eStructuralFeature_EAttribute_derived = getEStructuralFeature_EAttribute_derived();
	m_eStructuralFeature_EAttribute_derived->setName("derived");
	m_eStructuralFeature_EAttribute_derived->setEType(getEBoolean_EDataType());
	m_eStructuralFeature_EAttribute_derived->setLowerBound(0);
	m_eStructuralFeature_EAttribute_derived->setUpperBound(1);
	m_eStructuralFeature_EAttribute_derived->setTransient(false);
	m_eStructuralFeature_EAttribute_derived->setVolatile(false);
	m_eStructuralFeature_EAttribute_derived->setChangeable(true);
	m_eStructuralFeature_EAttribute_derived->setUnsettable(false);
	m_eStructuralFeature_EAttribute_derived->setUnique(true);
	m_eStructuralFeature_EAttribute_derived->setDerived(false);
	m_eStructuralFeature_EAttribute_derived->setOrdered(true);
	m_eStructuralFeature_EAttribute_derived->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eStructuralFeature_EAttribute_derived->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eStructuralFeature_EAttribute_featureID = getEStructuralFeature_EAttribute_featureID();
	m_eStructuralFeature_EAttribute_featureID->setName("featureID");
	m_eStructuralFeature_EAttribute_featureID->setEType(getEInt_EDataType());
	m_eStructuralFeature_EAttribute_featureID->setLowerBound(0);
	m_eStructuralFeature_EAttribute_featureID->setUpperBound(1);
	m_eStructuralFeature_EAttribute_featureID->setTransient(false);
	m_eStructuralFeature_EAttribute_featureID->setVolatile(false);
	m_eStructuralFeature_EAttribute_featureID->setChangeable(false);
	m_eStructuralFeature_EAttribute_featureID->setUnsettable(false);
	m_eStructuralFeature_EAttribute_featureID->setUnique(true);
	m_eStructuralFeature_EAttribute_featureID->setDerived(false);
	m_eStructuralFeature_EAttribute_featureID->setOrdered(true);
	m_eStructuralFeature_EAttribute_featureID->setID(false);
	{
		std::string defaultValue = "-1";
		if (!defaultValue.empty())
		{
		   m_eStructuralFeature_EAttribute_featureID->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eStructuralFeature_EAttribute_transient = getEStructuralFeature_EAttribute_transient();
	m_eStructuralFeature_EAttribute_transient->setName("transient");
	m_eStructuralFeature_EAttribute_transient->setEType(getEBoolean_EDataType());
	m_eStructuralFeature_EAttribute_transient->setLowerBound(0);
	m_eStructuralFeature_EAttribute_transient->setUpperBound(1);
	m_eStructuralFeature_EAttribute_transient->setTransient(false);
	m_eStructuralFeature_EAttribute_transient->setVolatile(false);
	m_eStructuralFeature_EAttribute_transient->setChangeable(true);
	m_eStructuralFeature_EAttribute_transient->setUnsettable(false);
	m_eStructuralFeature_EAttribute_transient->setUnique(true);
	m_eStructuralFeature_EAttribute_transient->setDerived(false);
	m_eStructuralFeature_EAttribute_transient->setOrdered(true);
	m_eStructuralFeature_EAttribute_transient->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eStructuralFeature_EAttribute_transient->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eStructuralFeature_EAttribute_unsettable = getEStructuralFeature_EAttribute_unsettable();
	m_eStructuralFeature_EAttribute_unsettable->setName("unsettable");
	m_eStructuralFeature_EAttribute_unsettable->setEType(getEBoolean_EDataType());
	m_eStructuralFeature_EAttribute_unsettable->setLowerBound(0);
	m_eStructuralFeature_EAttribute_unsettable->setUpperBound(1);
	m_eStructuralFeature_EAttribute_unsettable->setTransient(false);
	m_eStructuralFeature_EAttribute_unsettable->setVolatile(false);
	m_eStructuralFeature_EAttribute_unsettable->setChangeable(true);
	m_eStructuralFeature_EAttribute_unsettable->setUnsettable(false);
	m_eStructuralFeature_EAttribute_unsettable->setUnique(true);
	m_eStructuralFeature_EAttribute_unsettable->setDerived(false);
	m_eStructuralFeature_EAttribute_unsettable->setOrdered(true);
	m_eStructuralFeature_EAttribute_unsettable->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eStructuralFeature_EAttribute_unsettable->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eStructuralFeature_EAttribute_volatile = getEStructuralFeature_EAttribute_volatile();
	m_eStructuralFeature_EAttribute_volatile->setName("volatile");
	m_eStructuralFeature_EAttribute_volatile->setEType(getEBoolean_EDataType());
	m_eStructuralFeature_EAttribute_volatile->setLowerBound(0);
	m_eStructuralFeature_EAttribute_volatile->setUpperBound(1);
	m_eStructuralFeature_EAttribute_volatile->setTransient(false);
	m_eStructuralFeature_EAttribute_volatile->setVolatile(false);
	m_eStructuralFeature_EAttribute_volatile->setChangeable(true);
	m_eStructuralFeature_EAttribute_volatile->setUnsettable(false);
	m_eStructuralFeature_EAttribute_volatile->setUnique(true);
	m_eStructuralFeature_EAttribute_volatile->setDerived(false);
	m_eStructuralFeature_EAttribute_volatile->setOrdered(true);
	m_eStructuralFeature_EAttribute_volatile->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eStructuralFeature_EAttribute_volatile->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_eStructuralFeature_EReference_eContainingClass->setName("eContainingClass");
	m_eStructuralFeature_EReference_eContainingClass->setEType(getEClass_EClass());
	m_eStructuralFeature_EReference_eContainingClass->setLowerBound(0);
	m_eStructuralFeature_EReference_eContainingClass->setUpperBound(1);
	m_eStructuralFeature_EReference_eContainingClass->setTransient(true);
	m_eStructuralFeature_EReference_eContainingClass->setVolatile(false);
	m_eStructuralFeature_EReference_eContainingClass->setChangeable(false);
	m_eStructuralFeature_EReference_eContainingClass->setUnsettable(false);
	m_eStructuralFeature_EReference_eContainingClass->setUnique(true);
	m_eStructuralFeature_EReference_eContainingClass->setDerived(false);
	m_eStructuralFeature_EReference_eContainingClass->setOrdered(true);
	m_eStructuralFeature_EReference_eContainingClass->setContainment(false);
	m_eStructuralFeature_EReference_eContainingClass->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eStructuralFeature_EReference_eContainingClass->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEClass_EReference_eStructuralFeatures();
		if (otherEnd != nullptr)
	    {
	   		m_eStructuralFeature_EReference_eContainingClass->setEOpposite(otherEnd);
	    }
	}
	
	
}

void EcorePackageImpl::initializeETypeParameterContent()
{
	m_eTypeParameter_EClass->setInstanceClass(nullptr);
	m_eTypeParameter_EClass->setName("ETypeParameter");
	m_eTypeParameter_EClass->setAbstract(false);
	m_eTypeParameter_EClass->setInterface(false);
	
	
	m_eTypeParameter_EReference_eBounds->setName("eBounds");
	m_eTypeParameter_EReference_eBounds->setEType(getEGenericType_EClass());
	m_eTypeParameter_EReference_eBounds->setLowerBound(0);
	m_eTypeParameter_EReference_eBounds->setUpperBound(-1);
	m_eTypeParameter_EReference_eBounds->setTransient(false);
	m_eTypeParameter_EReference_eBounds->setVolatile(false);
	m_eTypeParameter_EReference_eBounds->setChangeable(true);
	m_eTypeParameter_EReference_eBounds->setUnsettable(false);
	m_eTypeParameter_EReference_eBounds->setUnique(true);
	m_eTypeParameter_EReference_eBounds->setDerived(false);
	m_eTypeParameter_EReference_eBounds->setOrdered(true);
	m_eTypeParameter_EReference_eBounds->setContainment(true);
	m_eTypeParameter_EReference_eBounds->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eTypeParameter_EReference_eBounds->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eTypeParameter_EReference_eBounds->setEOpposite(otherEnd);
	    }
	}
	
	
}

void EcorePackageImpl::initializeETypedElementContent()
{
	m_eTypedElement_EClass->setInstanceClass(nullptr);
	m_eTypedElement_EClass->setName("ETypedElement");
	m_eTypedElement_EClass->setAbstract(true);
	m_eTypedElement_EClass->setInterface(false);
	
	m_eTypedElement_EAttribute_lowerBound = getETypedElement_EAttribute_lowerBound();
	m_eTypedElement_EAttribute_lowerBound->setName("lowerBound");
	m_eTypedElement_EAttribute_lowerBound->setEType(getEInt_EDataType());
	m_eTypedElement_EAttribute_lowerBound->setLowerBound(0);
	m_eTypedElement_EAttribute_lowerBound->setUpperBound(1);
	m_eTypedElement_EAttribute_lowerBound->setTransient(false);
	m_eTypedElement_EAttribute_lowerBound->setVolatile(false);
	m_eTypedElement_EAttribute_lowerBound->setChangeable(true);
	m_eTypedElement_EAttribute_lowerBound->setUnsettable(false);
	m_eTypedElement_EAttribute_lowerBound->setUnique(true);
	m_eTypedElement_EAttribute_lowerBound->setDerived(false);
	m_eTypedElement_EAttribute_lowerBound->setOrdered(true);
	m_eTypedElement_EAttribute_lowerBound->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eTypedElement_EAttribute_lowerBound->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eTypedElement_EAttribute_many = getETypedElement_EAttribute_many();
	m_eTypedElement_EAttribute_many->setName("many");
	m_eTypedElement_EAttribute_many->setEType(getEBoolean_EDataType());
	m_eTypedElement_EAttribute_many->setLowerBound(0);
	m_eTypedElement_EAttribute_many->setUpperBound(1);
	m_eTypedElement_EAttribute_many->setTransient(true);
	m_eTypedElement_EAttribute_many->setVolatile(true);
	m_eTypedElement_EAttribute_many->setChangeable(false);
	m_eTypedElement_EAttribute_many->setUnsettable(false);
	m_eTypedElement_EAttribute_many->setUnique(true);
	m_eTypedElement_EAttribute_many->setDerived(true);
	m_eTypedElement_EAttribute_many->setOrdered(true);
	m_eTypedElement_EAttribute_many->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eTypedElement_EAttribute_many->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eTypedElement_EAttribute_ordered = getETypedElement_EAttribute_ordered();
	m_eTypedElement_EAttribute_ordered->setName("ordered");
	m_eTypedElement_EAttribute_ordered->setEType(getEBoolean_EDataType());
	m_eTypedElement_EAttribute_ordered->setLowerBound(0);
	m_eTypedElement_EAttribute_ordered->setUpperBound(1);
	m_eTypedElement_EAttribute_ordered->setTransient(false);
	m_eTypedElement_EAttribute_ordered->setVolatile(false);
	m_eTypedElement_EAttribute_ordered->setChangeable(true);
	m_eTypedElement_EAttribute_ordered->setUnsettable(false);
	m_eTypedElement_EAttribute_ordered->setUnique(true);
	m_eTypedElement_EAttribute_ordered->setDerived(false);
	m_eTypedElement_EAttribute_ordered->setOrdered(true);
	m_eTypedElement_EAttribute_ordered->setID(false);
	{
		std::string defaultValue = "true";
		if (!defaultValue.empty())
		{
		   m_eTypedElement_EAttribute_ordered->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eTypedElement_EAttribute_required = getETypedElement_EAttribute_required();
	m_eTypedElement_EAttribute_required->setName("required");
	m_eTypedElement_EAttribute_required->setEType(getEBoolean_EDataType());
	m_eTypedElement_EAttribute_required->setLowerBound(0);
	m_eTypedElement_EAttribute_required->setUpperBound(1);
	m_eTypedElement_EAttribute_required->setTransient(true);
	m_eTypedElement_EAttribute_required->setVolatile(true);
	m_eTypedElement_EAttribute_required->setChangeable(false);
	m_eTypedElement_EAttribute_required->setUnsettable(false);
	m_eTypedElement_EAttribute_required->setUnique(true);
	m_eTypedElement_EAttribute_required->setDerived(true);
	m_eTypedElement_EAttribute_required->setOrdered(true);
	m_eTypedElement_EAttribute_required->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eTypedElement_EAttribute_required->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eTypedElement_EAttribute_unique = getETypedElement_EAttribute_unique();
	m_eTypedElement_EAttribute_unique->setName("unique");
	m_eTypedElement_EAttribute_unique->setEType(getEBoolean_EDataType());
	m_eTypedElement_EAttribute_unique->setLowerBound(0);
	m_eTypedElement_EAttribute_unique->setUpperBound(1);
	m_eTypedElement_EAttribute_unique->setTransient(false);
	m_eTypedElement_EAttribute_unique->setVolatile(false);
	m_eTypedElement_EAttribute_unique->setChangeable(true);
	m_eTypedElement_EAttribute_unique->setUnsettable(false);
	m_eTypedElement_EAttribute_unique->setUnique(true);
	m_eTypedElement_EAttribute_unique->setDerived(false);
	m_eTypedElement_EAttribute_unique->setOrdered(true);
	m_eTypedElement_EAttribute_unique->setID(false);
	{
		std::string defaultValue = "true";
		if (!defaultValue.empty())
		{
		   m_eTypedElement_EAttribute_unique->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eTypedElement_EAttribute_upperBound = getETypedElement_EAttribute_upperBound();
	m_eTypedElement_EAttribute_upperBound->setName("upperBound");
	m_eTypedElement_EAttribute_upperBound->setEType(getEInt_EDataType());
	m_eTypedElement_EAttribute_upperBound->setLowerBound(0);
	m_eTypedElement_EAttribute_upperBound->setUpperBound(1);
	m_eTypedElement_EAttribute_upperBound->setTransient(false);
	m_eTypedElement_EAttribute_upperBound->setVolatile(false);
	m_eTypedElement_EAttribute_upperBound->setChangeable(true);
	m_eTypedElement_EAttribute_upperBound->setUnsettable(false);
	m_eTypedElement_EAttribute_upperBound->setUnique(true);
	m_eTypedElement_EAttribute_upperBound->setDerived(false);
	m_eTypedElement_EAttribute_upperBound->setOrdered(true);
	m_eTypedElement_EAttribute_upperBound->setID(false);
	{
		std::string defaultValue = "1";
		if (!defaultValue.empty())
		{
		   m_eTypedElement_EAttribute_upperBound->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_eTypedElement_EReference_eGenericType->setName("eGenericType");
	m_eTypedElement_EReference_eGenericType->setEType(getEGenericType_EClass());
	m_eTypedElement_EReference_eGenericType->setLowerBound(0);
	m_eTypedElement_EReference_eGenericType->setUpperBound(1);
	m_eTypedElement_EReference_eGenericType->setTransient(false);
	m_eTypedElement_EReference_eGenericType->setVolatile(true);
	m_eTypedElement_EReference_eGenericType->setChangeable(true);
	m_eTypedElement_EReference_eGenericType->setUnsettable(true);
	m_eTypedElement_EReference_eGenericType->setUnique(true);
	m_eTypedElement_EReference_eGenericType->setDerived(false);
	m_eTypedElement_EReference_eGenericType->setOrdered(true);
	m_eTypedElement_EReference_eGenericType->setContainment(true);
	m_eTypedElement_EReference_eGenericType->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eTypedElement_EReference_eGenericType->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eTypedElement_EReference_eGenericType->setEOpposite(otherEnd);
	    }
	}
	m_eTypedElement_EReference_eType->setName("eType");
	m_eTypedElement_EReference_eType->setEType(getEClassifier_EClass());
	m_eTypedElement_EReference_eType->setLowerBound(0);
	m_eTypedElement_EReference_eType->setUpperBound(1);
	m_eTypedElement_EReference_eType->setTransient(false);
	m_eTypedElement_EReference_eType->setVolatile(true);
	m_eTypedElement_EReference_eType->setChangeable(true);
	m_eTypedElement_EReference_eType->setUnsettable(true);
	m_eTypedElement_EReference_eType->setUnique(true);
	m_eTypedElement_EReference_eType->setDerived(false);
	m_eTypedElement_EReference_eType->setOrdered(true);
	m_eTypedElement_EReference_eType->setContainment(false);
	m_eTypedElement_EReference_eType->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eTypedElement_EReference_eType->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eTypedElement_EReference_eType->setEOpposite(otherEnd);
	    }
	}
	
	
}

void EcorePackageImpl::initializePackageEDataTypes()
{
	m_eBigDecimal_EDataType->setInstanceClass(nullptr);
	m_eBigDecimal_EDataType->setName("EBigDecimal");
	m_eBigDecimal_EDataType->setSerializable(true);
	m_eBigInteger_EDataType->setInstanceClass(nullptr);
	m_eBigInteger_EDataType->setName("EBigInteger");
	m_eBigInteger_EDataType->setSerializable(true);
	m_eBoolean_EDataType->setInstanceClass(nullptr);
	m_eBoolean_EDataType->setName("EBoolean");
	m_eBoolean_EDataType->setSerializable(true);
	m_eBooleanObject_EDataType->setInstanceClass(nullptr);
	m_eBooleanObject_EDataType->setName("EBooleanObject");
	m_eBooleanObject_EDataType->setSerializable(true);
	m_eByte_EDataType->setInstanceClass(nullptr);
	m_eByte_EDataType->setName("EByte");
	m_eByte_EDataType->setSerializable(true);
	m_eByteArray_EDataType->setInstanceClass(nullptr);
	m_eByteArray_EDataType->setName("EByteArray");
	m_eByteArray_EDataType->setSerializable(true);
	m_eByteObject_EDataType->setInstanceClass(nullptr);
	m_eByteObject_EDataType->setName("EByteObject");
	m_eByteObject_EDataType->setSerializable(true);
	m_eChar_EDataType->setInstanceClass(nullptr);
	m_eChar_EDataType->setName("EChar");
	m_eChar_EDataType->setSerializable(true);
	m_eCharacterObject_EDataType->setInstanceClass(nullptr);
	m_eCharacterObject_EDataType->setName("ECharacterObject");
	m_eCharacterObject_EDataType->setSerializable(true);
	m_eDate_EDataType->setInstanceClass(nullptr);
	m_eDate_EDataType->setName("EDate");
	m_eDate_EDataType->setSerializable(true);
	m_eDiagnosticChain_EDataType->setInstanceClass(nullptr);
	m_eDiagnosticChain_EDataType->setName("EDiagnosticChain");
	m_eDiagnosticChain_EDataType->setSerializable(false);
	m_eDouble_EDataType->setInstanceClass(nullptr);
	m_eDouble_EDataType->setName("EDouble");
	m_eDouble_EDataType->setSerializable(true);
	m_eDoubleObject_EDataType->setInstanceClass(nullptr);
	m_eDoubleObject_EDataType->setName("EDoubleObject");
	m_eDoubleObject_EDataType->setSerializable(true);
	m_eEList_EDataType->setInstanceClass(nullptr);
	m_eEList_EDataType->setName("EEList");
	m_eEList_EDataType->setSerializable(false);
	m_eEnumerator_EDataType->setInstanceClass(nullptr);
	m_eEnumerator_EDataType->setName("EEnumerator");
	m_eEnumerator_EDataType->setSerializable(false);
	m_eFeatureMap_EDataType->setInstanceClass(nullptr);
	m_eFeatureMap_EDataType->setName("EFeatureMap");
	m_eFeatureMap_EDataType->setSerializable(false);
	m_eFeatureMapEntry_EDataType->setInstanceClass(nullptr);
	m_eFeatureMapEntry_EDataType->setName("EFeatureMapEntry");
	m_eFeatureMapEntry_EDataType->setSerializable(false);
	m_eFloat_EDataType->setInstanceClass(nullptr);
	m_eFloat_EDataType->setName("EFloat");
	m_eFloat_EDataType->setSerializable(true);
	m_eFloatObject_EDataType->setInstanceClass(nullptr);
	m_eFloatObject_EDataType->setName("EFloatObject");
	m_eFloatObject_EDataType->setSerializable(true);
	m_eInt_EDataType->setInstanceClass(nullptr);
	m_eInt_EDataType->setName("EInt");
	m_eInt_EDataType->setSerializable(true);
	m_eIntegerObject_EDataType->setInstanceClass(nullptr);
	m_eIntegerObject_EDataType->setName("EIntegerObject");
	m_eIntegerObject_EDataType->setSerializable(true);
	m_eInvocationTargetException_EDataType->setInstanceClass(nullptr);
	m_eInvocationTargetException_EDataType->setName("EInvocationTargetException");
	m_eInvocationTargetException_EDataType->setSerializable(false);
	m_eJavaClass_EDataType->setInstanceClass(nullptr);
	m_eJavaClass_EDataType->setName("EJavaClass");
	m_eJavaClass_EDataType->setSerializable(true);
	m_eJavaObject_EDataType->setInstanceClass(nullptr);
	m_eJavaObject_EDataType->setName("EJavaObject");
	m_eJavaObject_EDataType->setSerializable(true);
	m_eLong_EDataType->setInstanceClass(nullptr);
	m_eLong_EDataType->setName("ELong");
	m_eLong_EDataType->setSerializable(true);
	m_eLongObject_EDataType->setInstanceClass(nullptr);
	m_eLongObject_EDataType->setName("ELongObject");
	m_eLongObject_EDataType->setSerializable(true);
	m_eMap_EDataType->setInstanceClass(nullptr);
	m_eMap_EDataType->setName("EMap");
	m_eMap_EDataType->setSerializable(false);
	m_eResource_EDataType->setInstanceClass(nullptr);
	m_eResource_EDataType->setName("EResource");
	m_eResource_EDataType->setSerializable(false);
	m_eResourceSet_EDataType->setInstanceClass(nullptr);
	m_eResourceSet_EDataType->setName("EResourceSet");
	m_eResourceSet_EDataType->setSerializable(false);
	m_eShort_EDataType->setInstanceClass(nullptr);
	m_eShort_EDataType->setName("EShort");
	m_eShort_EDataType->setSerializable(true);
	m_eShortObject_EDataType->setInstanceClass(nullptr);
	m_eShortObject_EDataType->setName("EShortObject");
	m_eShortObject_EDataType->setSerializable(true);
	m_eString_EDataType->setInstanceClass(nullptr);
	m_eString_EDataType->setName("EString");
	m_eString_EDataType->setSerializable(true);
	m_eTreeIterator_EDataType->setInstanceClass(nullptr);
	m_eTreeIterator_EDataType->setName("ETreeIterator");
	m_eTreeIterator_EDataType->setSerializable(false);
	
}
