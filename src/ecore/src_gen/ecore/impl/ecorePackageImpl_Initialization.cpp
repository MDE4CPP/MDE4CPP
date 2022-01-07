#include "ecore/impl/ecorePackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EParameter.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EReference.hpp"
#include "ecore/ETypeParameter.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "ecore/ecorePackage.hpp"


using namespace ecore;

void ecorePackageImpl::initializePackageContents()
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
	m_eAnnotation_Class->getESuperTypes()->push_back(getEModelElement_Class());
	m_eAttribute_Class->getESuperTypes()->push_back(getEStructuralFeature_Class());
	m_eClass_Class->getESuperTypes()->push_back(getEClassifier_Class());
	m_eClassifier_Class->getESuperTypes()->push_back(getENamedElement_Class());
	m_eDataType_Class->getESuperTypes()->push_back(getEClassifier_Class());
	m_eEnum_Class->getESuperTypes()->push_back(getEDataType_Class());
	m_eEnumLiteral_Class->getESuperTypes()->push_back(getENamedElement_Class());
	m_eFactory_Class->getESuperTypes()->push_back(getEModelElement_Class());
	m_eModelElement_Class->getESuperTypes()->push_back(getEObject_Class());
	m_eNamedElement_Class->getESuperTypes()->push_back(getEModelElement_Class());
	m_eObjectContainer_Class->getESuperTypes()->push_back(getEObject_Class());
	m_eOperation_Class->getESuperTypes()->push_back(getETypedElement_Class());
	m_ePackage_Class->getESuperTypes()->push_back(getENamedElement_Class());
	m_eParameter_Class->getESuperTypes()->push_back(getETypedElement_Class());
	m_eReference_Class->getESuperTypes()->push_back(getEStructuralFeature_Class());
	m_eStructuralFeature_Class->getESuperTypes()->push_back(getETypedElement_Class());
	m_eTypeParameter_Class->getESuperTypes()->push_back(getENamedElement_Class());
	m_eTypedElement_Class->getESuperTypes()->push_back(getENamedElement_Class());
	

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
	initializeEObjectContainerContent();
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

void ecorePackageImpl::initializeEAnnotationContent()
{
	m_eAnnotation_Class->setName("EAnnotation");
	m_eAnnotation_Class->setAbstract(false);
	m_eAnnotation_Class->setInterface(false);
	
	m_eAnnotation_Attribute_details = getEAnnotation_Attribute_details();
	m_eAnnotation_Attribute_details->setName("details");
		m_eAnnotation_Attribute_details->setEType(getEMap_Class());
	m_eAnnotation_Attribute_details->setLowerBound(0);
	m_eAnnotation_Attribute_details->setUpperBound(1);
	m_eAnnotation_Attribute_details->setTransient(true);
	m_eAnnotation_Attribute_details->setVolatile(false);
	m_eAnnotation_Attribute_details->setChangeable(true);
	m_eAnnotation_Attribute_details->setUnsettable(false);
	m_eAnnotation_Attribute_details->setUnique(true);
	m_eAnnotation_Attribute_details->setDerived(false);
	m_eAnnotation_Attribute_details->setOrdered(true);
	m_eAnnotation_Attribute_details->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eAnnotation_Attribute_details->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eAnnotation_Attribute_source = getEAnnotation_Attribute_source();
	m_eAnnotation_Attribute_source->setName("source");
		m_eAnnotation_Attribute_source->setEType(getEString_Class());
	m_eAnnotation_Attribute_source->setLowerBound(0);
	m_eAnnotation_Attribute_source->setUpperBound(1);
	m_eAnnotation_Attribute_source->setTransient(false);
	m_eAnnotation_Attribute_source->setVolatile(false);
	m_eAnnotation_Attribute_source->setChangeable(true);
	m_eAnnotation_Attribute_source->setUnsettable(false);
	m_eAnnotation_Attribute_source->setUnique(true);
	m_eAnnotation_Attribute_source->setDerived(false);
	m_eAnnotation_Attribute_source->setOrdered(true);
	m_eAnnotation_Attribute_source->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eAnnotation_Attribute_source->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_eAnnotation_Attribute_contents->setName("contents");
	m_eAnnotation_Attribute_contents->setEType(getEObject_Class());
	m_eAnnotation_Attribute_contents->setLowerBound(0);
	m_eAnnotation_Attribute_contents->setUpperBound(-1);
	m_eAnnotation_Attribute_contents->setTransient(false);
	m_eAnnotation_Attribute_contents->setVolatile(false);
	m_eAnnotation_Attribute_contents->setChangeable(true);
	m_eAnnotation_Attribute_contents->setUnsettable(false);
	m_eAnnotation_Attribute_contents->setUnique(true);
	m_eAnnotation_Attribute_contents->setDerived(false);
	m_eAnnotation_Attribute_contents->setOrdered(true);
	m_eAnnotation_Attribute_contents->setContainment(true);
	m_eAnnotation_Attribute_contents->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eAnnotation_Attribute_contents->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_eAnnotation_Attribute_eModelElement->setName("eModelElement");
	m_eAnnotation_Attribute_eModelElement->setEType(getEModelElement_Class());
	m_eAnnotation_Attribute_eModelElement->setLowerBound(0);
	m_eAnnotation_Attribute_eModelElement->setUpperBound(1);
	m_eAnnotation_Attribute_eModelElement->setTransient(true);
	m_eAnnotation_Attribute_eModelElement->setVolatile(false);
	m_eAnnotation_Attribute_eModelElement->setChangeable(true);
	m_eAnnotation_Attribute_eModelElement->setUnsettable(false);
	m_eAnnotation_Attribute_eModelElement->setUnique(true);
	m_eAnnotation_Attribute_eModelElement->setDerived(false);
	m_eAnnotation_Attribute_eModelElement->setOrdered(true);
	m_eAnnotation_Attribute_eModelElement->setContainment(false);
	m_eAnnotation_Attribute_eModelElement->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eAnnotation_Attribute_eModelElement->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ecore::ecorePackage::eInstance()->getEModelElement_Attribute_eAnnotations();
		if (otherEnd != nullptr)
	    {
	   		m_eAnnotation_Attribute_eModelElement->setEOpposite(otherEnd);
	    }
	}
	m_eAnnotation_Attribute_references->setName("references");
	m_eAnnotation_Attribute_references->setEType(getEObject_Class());
	m_eAnnotation_Attribute_references->setLowerBound(0);
	m_eAnnotation_Attribute_references->setUpperBound(-1);
	m_eAnnotation_Attribute_references->setTransient(false);
	m_eAnnotation_Attribute_references->setVolatile(false);
	m_eAnnotation_Attribute_references->setChangeable(true);
	m_eAnnotation_Attribute_references->setUnsettable(false);
	m_eAnnotation_Attribute_references->setUnique(true);
	m_eAnnotation_Attribute_references->setDerived(false);
	m_eAnnotation_Attribute_references->setOrdered(true);
	m_eAnnotation_Attribute_references->setContainment(false);
	m_eAnnotation_Attribute_references->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eAnnotation_Attribute_references->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	
}

void ecorePackageImpl::initializeEAttributeContent()
{
	m_eAttribute_Class->setName("EAttribute");
	m_eAttribute_Class->setAbstract(false);
	m_eAttribute_Class->setInterface(false);
	
	m_eAttribute_Attribute_iD = getEAttribute_Attribute_iD();
	m_eAttribute_Attribute_iD->setName("iD");
		m_eAttribute_Attribute_iD->setEType(getEBoolean_Class());
	m_eAttribute_Attribute_iD->setLowerBound(0);
	m_eAttribute_Attribute_iD->setUpperBound(1);
	m_eAttribute_Attribute_iD->setTransient(false);
	m_eAttribute_Attribute_iD->setVolatile(false);
	m_eAttribute_Attribute_iD->setChangeable(true);
	m_eAttribute_Attribute_iD->setUnsettable(false);
	m_eAttribute_Attribute_iD->setUnique(true);
	m_eAttribute_Attribute_iD->setDerived(false);
	m_eAttribute_Attribute_iD->setOrdered(true);
	m_eAttribute_Attribute_iD->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eAttribute_Attribute_iD->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_eAttribute_Attribute_eAttributeType->setName("eAttributeType");
	m_eAttribute_Attribute_eAttributeType->setEType(getEDataType_Class());
	m_eAttribute_Attribute_eAttributeType->setLowerBound(1);
	m_eAttribute_Attribute_eAttributeType->setUpperBound(1);
	m_eAttribute_Attribute_eAttributeType->setTransient(true);
	m_eAttribute_Attribute_eAttributeType->setVolatile(true);
	m_eAttribute_Attribute_eAttributeType->setChangeable(false);
	m_eAttribute_Attribute_eAttributeType->setUnsettable(false);
	m_eAttribute_Attribute_eAttributeType->setUnique(true);
	m_eAttribute_Attribute_eAttributeType->setDerived(true);
	m_eAttribute_Attribute_eAttributeType->setOrdered(true);
	m_eAttribute_Attribute_eAttributeType->setContainment(false);
	m_eAttribute_Attribute_eAttributeType->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eAttribute_Attribute_eAttributeType->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	
}

void ecorePackageImpl::initializeEClassContent()
{
	m_eClass_Class->setName("EClass");
	m_eClass_Class->setAbstract(false);
	m_eClass_Class->setInterface(false);
	
	m_eClass_Attribute_abstract = getEClass_Attribute_abstract();
	m_eClass_Attribute_abstract->setName("abstract");
		m_eClass_Attribute_abstract->setEType(getEBoolean_Class());
	m_eClass_Attribute_abstract->setLowerBound(0);
	m_eClass_Attribute_abstract->setUpperBound(1);
	m_eClass_Attribute_abstract->setTransient(false);
	m_eClass_Attribute_abstract->setVolatile(false);
	m_eClass_Attribute_abstract->setChangeable(true);
	m_eClass_Attribute_abstract->setUnsettable(false);
	m_eClass_Attribute_abstract->setUnique(true);
	m_eClass_Attribute_abstract->setDerived(false);
	m_eClass_Attribute_abstract->setOrdered(true);
	m_eClass_Attribute_abstract->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eClass_Attribute_abstract->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eClass_Attribute_interface = getEClass_Attribute_interface();
	m_eClass_Attribute_interface->setName("interface");
		m_eClass_Attribute_interface->setEType(getEBoolean_Class());
	m_eClass_Attribute_interface->setLowerBound(0);
	m_eClass_Attribute_interface->setUpperBound(1);
	m_eClass_Attribute_interface->setTransient(false);
	m_eClass_Attribute_interface->setVolatile(false);
	m_eClass_Attribute_interface->setChangeable(true);
	m_eClass_Attribute_interface->setUnsettable(false);
	m_eClass_Attribute_interface->setUnique(true);
	m_eClass_Attribute_interface->setDerived(false);
	m_eClass_Attribute_interface->setOrdered(true);
	m_eClass_Attribute_interface->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eClass_Attribute_interface->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_eClass_Attribute_eAllAttributes->setName("eAllAttributes");
	m_eClass_Attribute_eAllAttributes->setEType(getEAttribute_Class());
	m_eClass_Attribute_eAllAttributes->setLowerBound(0);
	m_eClass_Attribute_eAllAttributes->setUpperBound(-1);
	m_eClass_Attribute_eAllAttributes->setTransient(true);
	m_eClass_Attribute_eAllAttributes->setVolatile(true);
	m_eClass_Attribute_eAllAttributes->setChangeable(false);
	m_eClass_Attribute_eAllAttributes->setUnsettable(false);
	m_eClass_Attribute_eAllAttributes->setUnique(true);
	m_eClass_Attribute_eAllAttributes->setDerived(true);
	m_eClass_Attribute_eAllAttributes->setOrdered(true);
	m_eClass_Attribute_eAllAttributes->setContainment(false);
	m_eClass_Attribute_eAllAttributes->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_Attribute_eAllAttributes->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_eClass_Attribute_eAllContainments->setName("eAllContainments");
	m_eClass_Attribute_eAllContainments->setEType(getEReference_Class());
	m_eClass_Attribute_eAllContainments->setLowerBound(0);
	m_eClass_Attribute_eAllContainments->setUpperBound(-1);
	m_eClass_Attribute_eAllContainments->setTransient(true);
	m_eClass_Attribute_eAllContainments->setVolatile(true);
	m_eClass_Attribute_eAllContainments->setChangeable(false);
	m_eClass_Attribute_eAllContainments->setUnsettable(false);
	m_eClass_Attribute_eAllContainments->setUnique(true);
	m_eClass_Attribute_eAllContainments->setDerived(true);
	m_eClass_Attribute_eAllContainments->setOrdered(true);
	m_eClass_Attribute_eAllContainments->setContainment(false);
	m_eClass_Attribute_eAllContainments->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_Attribute_eAllContainments->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_eClass_Attribute_eAllGenericSuperTypes->setName("eAllGenericSuperTypes");
	m_eClass_Attribute_eAllGenericSuperTypes->setEType(getEGenericType_Class());
	m_eClass_Attribute_eAllGenericSuperTypes->setLowerBound(0);
	m_eClass_Attribute_eAllGenericSuperTypes->setUpperBound(-1);
	m_eClass_Attribute_eAllGenericSuperTypes->setTransient(true);
	m_eClass_Attribute_eAllGenericSuperTypes->setVolatile(true);
	m_eClass_Attribute_eAllGenericSuperTypes->setChangeable(false);
	m_eClass_Attribute_eAllGenericSuperTypes->setUnsettable(false);
	m_eClass_Attribute_eAllGenericSuperTypes->setUnique(true);
	m_eClass_Attribute_eAllGenericSuperTypes->setDerived(true);
	m_eClass_Attribute_eAllGenericSuperTypes->setOrdered(true);
	m_eClass_Attribute_eAllGenericSuperTypes->setContainment(false);
	m_eClass_Attribute_eAllGenericSuperTypes->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_Attribute_eAllGenericSuperTypes->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_eClass_Attribute_eAllOperations->setName("eAllOperations");
	m_eClass_Attribute_eAllOperations->setEType(getEOperation_Class());
	m_eClass_Attribute_eAllOperations->setLowerBound(0);
	m_eClass_Attribute_eAllOperations->setUpperBound(-1);
	m_eClass_Attribute_eAllOperations->setTransient(true);
	m_eClass_Attribute_eAllOperations->setVolatile(true);
	m_eClass_Attribute_eAllOperations->setChangeable(false);
	m_eClass_Attribute_eAllOperations->setUnsettable(false);
	m_eClass_Attribute_eAllOperations->setUnique(true);
	m_eClass_Attribute_eAllOperations->setDerived(true);
	m_eClass_Attribute_eAllOperations->setOrdered(true);
	m_eClass_Attribute_eAllOperations->setContainment(false);
	m_eClass_Attribute_eAllOperations->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_Attribute_eAllOperations->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_eClass_Attribute_eAllReferences->setName("eAllReferences");
	m_eClass_Attribute_eAllReferences->setEType(getEReference_Class());
	m_eClass_Attribute_eAllReferences->setLowerBound(0);
	m_eClass_Attribute_eAllReferences->setUpperBound(-1);
	m_eClass_Attribute_eAllReferences->setTransient(true);
	m_eClass_Attribute_eAllReferences->setVolatile(true);
	m_eClass_Attribute_eAllReferences->setChangeable(false);
	m_eClass_Attribute_eAllReferences->setUnsettable(false);
	m_eClass_Attribute_eAllReferences->setUnique(true);
	m_eClass_Attribute_eAllReferences->setDerived(true);
	m_eClass_Attribute_eAllReferences->setOrdered(true);
	m_eClass_Attribute_eAllReferences->setContainment(false);
	m_eClass_Attribute_eAllReferences->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_Attribute_eAllReferences->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_eClass_Attribute_eAllStructuralFeatures->setName("eAllStructuralFeatures");
	m_eClass_Attribute_eAllStructuralFeatures->setEType(getEStructuralFeature_Class());
	m_eClass_Attribute_eAllStructuralFeatures->setLowerBound(0);
	m_eClass_Attribute_eAllStructuralFeatures->setUpperBound(-1);
	m_eClass_Attribute_eAllStructuralFeatures->setTransient(true);
	m_eClass_Attribute_eAllStructuralFeatures->setVolatile(true);
	m_eClass_Attribute_eAllStructuralFeatures->setChangeable(false);
	m_eClass_Attribute_eAllStructuralFeatures->setUnsettable(false);
	m_eClass_Attribute_eAllStructuralFeatures->setUnique(true);
	m_eClass_Attribute_eAllStructuralFeatures->setDerived(true);
	m_eClass_Attribute_eAllStructuralFeatures->setOrdered(true);
	m_eClass_Attribute_eAllStructuralFeatures->setContainment(false);
	m_eClass_Attribute_eAllStructuralFeatures->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_Attribute_eAllStructuralFeatures->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_eClass_Attribute_eAllSuperTypes->setName("eAllSuperTypes");
	m_eClass_Attribute_eAllSuperTypes->setEType(getEClass_Class());
	m_eClass_Attribute_eAllSuperTypes->setLowerBound(0);
	m_eClass_Attribute_eAllSuperTypes->setUpperBound(-1);
	m_eClass_Attribute_eAllSuperTypes->setTransient(true);
	m_eClass_Attribute_eAllSuperTypes->setVolatile(true);
	m_eClass_Attribute_eAllSuperTypes->setChangeable(false);
	m_eClass_Attribute_eAllSuperTypes->setUnsettable(false);
	m_eClass_Attribute_eAllSuperTypes->setUnique(true);
	m_eClass_Attribute_eAllSuperTypes->setDerived(true);
	m_eClass_Attribute_eAllSuperTypes->setOrdered(true);
	m_eClass_Attribute_eAllSuperTypes->setContainment(false);
	m_eClass_Attribute_eAllSuperTypes->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_Attribute_eAllSuperTypes->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_eClass_Attribute_eAttributes->setName("eAttributes");
	m_eClass_Attribute_eAttributes->setEType(getEAttribute_Class());
	m_eClass_Attribute_eAttributes->setLowerBound(0);
	m_eClass_Attribute_eAttributes->setUpperBound(-1);
	m_eClass_Attribute_eAttributes->setTransient(true);
	m_eClass_Attribute_eAttributes->setVolatile(true);
	m_eClass_Attribute_eAttributes->setChangeable(true);
	m_eClass_Attribute_eAttributes->setUnsettable(false);
	m_eClass_Attribute_eAttributes->setUnique(true);
	m_eClass_Attribute_eAttributes->setDerived(true);
	m_eClass_Attribute_eAttributes->setOrdered(true);
	m_eClass_Attribute_eAttributes->setContainment(false);
	m_eClass_Attribute_eAttributes->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_Attribute_eAttributes->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_eClass_Attribute_eGenericSuperTypes->setName("eGenericSuperTypes");
	m_eClass_Attribute_eGenericSuperTypes->setEType(getEGenericType_Class());
	m_eClass_Attribute_eGenericSuperTypes->setLowerBound(0);
	m_eClass_Attribute_eGenericSuperTypes->setUpperBound(-1);
	m_eClass_Attribute_eGenericSuperTypes->setTransient(false);
	m_eClass_Attribute_eGenericSuperTypes->setVolatile(false);
	m_eClass_Attribute_eGenericSuperTypes->setChangeable(true);
	m_eClass_Attribute_eGenericSuperTypes->setUnsettable(true);
	m_eClass_Attribute_eGenericSuperTypes->setUnique(true);
	m_eClass_Attribute_eGenericSuperTypes->setDerived(false);
	m_eClass_Attribute_eGenericSuperTypes->setOrdered(true);
	m_eClass_Attribute_eGenericSuperTypes->setContainment(true);
	m_eClass_Attribute_eGenericSuperTypes->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_Attribute_eGenericSuperTypes->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_eClass_Attribute_eIDAttribute->setName("eIDAttribute");
	m_eClass_Attribute_eIDAttribute->setEType(getEAttribute_Class());
	m_eClass_Attribute_eIDAttribute->setLowerBound(0);
	m_eClass_Attribute_eIDAttribute->setUpperBound(1);
	m_eClass_Attribute_eIDAttribute->setTransient(true);
	m_eClass_Attribute_eIDAttribute->setVolatile(true);
	m_eClass_Attribute_eIDAttribute->setChangeable(true);
	m_eClass_Attribute_eIDAttribute->setUnsettable(false);
	m_eClass_Attribute_eIDAttribute->setUnique(true);
	m_eClass_Attribute_eIDAttribute->setDerived(true);
	m_eClass_Attribute_eIDAttribute->setOrdered(true);
	m_eClass_Attribute_eIDAttribute->setContainment(false);
	m_eClass_Attribute_eIDAttribute->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_Attribute_eIDAttribute->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_eClass_Attribute_eOperations->setName("eOperations");
	m_eClass_Attribute_eOperations->setEType(getEOperation_Class());
	m_eClass_Attribute_eOperations->setLowerBound(0);
	m_eClass_Attribute_eOperations->setUpperBound(-1);
	m_eClass_Attribute_eOperations->setTransient(false);
	m_eClass_Attribute_eOperations->setVolatile(false);
	m_eClass_Attribute_eOperations->setChangeable(true);
	m_eClass_Attribute_eOperations->setUnsettable(false);
	m_eClass_Attribute_eOperations->setUnique(true);
	m_eClass_Attribute_eOperations->setDerived(false);
	m_eClass_Attribute_eOperations->setOrdered(true);
	m_eClass_Attribute_eOperations->setContainment(true);
	m_eClass_Attribute_eOperations->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_Attribute_eOperations->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ecore::ecorePackage::eInstance()->getEOperation_Attribute_eContainingClass();
		if (otherEnd != nullptr)
	    {
	   		m_eClass_Attribute_eOperations->setEOpposite(otherEnd);
	    }
	}
	m_eClass_Attribute_eReferences->setName("eReferences");
	m_eClass_Attribute_eReferences->setEType(getEReference_Class());
	m_eClass_Attribute_eReferences->setLowerBound(0);
	m_eClass_Attribute_eReferences->setUpperBound(-1);
	m_eClass_Attribute_eReferences->setTransient(true);
	m_eClass_Attribute_eReferences->setVolatile(true);
	m_eClass_Attribute_eReferences->setChangeable(true);
	m_eClass_Attribute_eReferences->setUnsettable(false);
	m_eClass_Attribute_eReferences->setUnique(true);
	m_eClass_Attribute_eReferences->setDerived(true);
	m_eClass_Attribute_eReferences->setOrdered(true);
	m_eClass_Attribute_eReferences->setContainment(false);
	m_eClass_Attribute_eReferences->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_Attribute_eReferences->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_eClass_Attribute_eStructuralFeatures->setName("eStructuralFeatures");
	m_eClass_Attribute_eStructuralFeatures->setEType(getEStructuralFeature_Class());
	m_eClass_Attribute_eStructuralFeatures->setLowerBound(0);
	m_eClass_Attribute_eStructuralFeatures->setUpperBound(-1);
	m_eClass_Attribute_eStructuralFeatures->setTransient(false);
	m_eClass_Attribute_eStructuralFeatures->setVolatile(false);
	m_eClass_Attribute_eStructuralFeatures->setChangeable(true);
	m_eClass_Attribute_eStructuralFeatures->setUnsettable(false);
	m_eClass_Attribute_eStructuralFeatures->setUnique(true);
	m_eClass_Attribute_eStructuralFeatures->setDerived(false);
	m_eClass_Attribute_eStructuralFeatures->setOrdered(true);
	m_eClass_Attribute_eStructuralFeatures->setContainment(true);
	m_eClass_Attribute_eStructuralFeatures->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_Attribute_eStructuralFeatures->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ecore::ecorePackage::eInstance()->getEStructuralFeature_Attribute_eContainingClass();
		if (otherEnd != nullptr)
	    {
	   		m_eClass_Attribute_eStructuralFeatures->setEOpposite(otherEnd);
	    }
	}
	m_eClass_Attribute_eSuperTypes->setName("eSuperTypes");
	m_eClass_Attribute_eSuperTypes->setEType(getEClass_Class());
	m_eClass_Attribute_eSuperTypes->setLowerBound(0);
	m_eClass_Attribute_eSuperTypes->setUpperBound(-1);
	m_eClass_Attribute_eSuperTypes->setTransient(false);
	m_eClass_Attribute_eSuperTypes->setVolatile(false);
	m_eClass_Attribute_eSuperTypes->setChangeable(true);
	m_eClass_Attribute_eSuperTypes->setUnsettable(true);
	m_eClass_Attribute_eSuperTypes->setUnique(true);
	m_eClass_Attribute_eSuperTypes->setDerived(false);
	m_eClass_Attribute_eSuperTypes->setOrdered(true);
	m_eClass_Attribute_eSuperTypes->setContainment(false);
	m_eClass_Attribute_eSuperTypes->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_Attribute_eSuperTypes->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_eClass_Operation_getEOperation_EInt->setName("getEOperation");
	m_eClass_Operation_getEOperation_EInt->setEType(getEOperation_Class());
	m_eClass_Operation_getEOperation_EInt->setLowerBound(0);
	m_eClass_Operation_getEOperation_EInt->setUpperBound(1);
	m_eClass_Operation_getEOperation_EInt->setUnique(true);
	m_eClass_Operation_getEOperation_EInt->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eClass_Operation_getEOperation_EInt);
		parameter->setName("operationID");
		parameter->setEType(getEInt_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eClass_Operation_getEStructuralFeature_EInt->setName("getEStructuralFeature");
	m_eClass_Operation_getEStructuralFeature_EInt->setEType(getEStructuralFeature_Class());
	m_eClass_Operation_getEStructuralFeature_EInt->setLowerBound(0);
	m_eClass_Operation_getEStructuralFeature_EInt->setUpperBound(1);
	m_eClass_Operation_getEStructuralFeature_EInt->setUnique(true);
	m_eClass_Operation_getEStructuralFeature_EInt->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eClass_Operation_getEStructuralFeature_EInt);
		parameter->setName("featureID");
		parameter->setEType(getEInt_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eClass_Operation_getEStructuralFeature_EString->setName("getEStructuralFeature");
	m_eClass_Operation_getEStructuralFeature_EString->setEType(getEStructuralFeature_Class());
	m_eClass_Operation_getEStructuralFeature_EString->setLowerBound(0);
	m_eClass_Operation_getEStructuralFeature_EString->setUpperBound(1);
	m_eClass_Operation_getEStructuralFeature_EString->setUnique(true);
	m_eClass_Operation_getEStructuralFeature_EString->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eClass_Operation_getEStructuralFeature_EString);
		parameter->setName("featureName");
		parameter->setEType(getEString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eClass_Operation_getFeatureCount->setName("getFeatureCount");
	m_eClass_Operation_getFeatureCount->setEType(getEInt_Class());
	m_eClass_Operation_getFeatureCount->setLowerBound(0);
	m_eClass_Operation_getFeatureCount->setUpperBound(1);
	m_eClass_Operation_getFeatureCount->setUnique(true);
	m_eClass_Operation_getFeatureCount->setOrdered(true);
	
	m_eClass_Operation_getFeatureID_EStructuralFeature->setName("getFeatureID");
	m_eClass_Operation_getFeatureID_EStructuralFeature->setEType(getEInt_Class());
	m_eClass_Operation_getFeatureID_EStructuralFeature->setLowerBound(0);
	m_eClass_Operation_getFeatureID_EStructuralFeature->setUpperBound(1);
	m_eClass_Operation_getFeatureID_EStructuralFeature->setUnique(true);
	m_eClass_Operation_getFeatureID_EStructuralFeature->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eClass_Operation_getFeatureID_EStructuralFeature);
		parameter->setName("feature");
		parameter->setEType(getEStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eClass_Operation_getFeatureType_EStructuralFeature->setName("getFeatureType");
	m_eClass_Operation_getFeatureType_EStructuralFeature->setEType(getEGenericType_Class());
	m_eClass_Operation_getFeatureType_EStructuralFeature->setLowerBound(0);
	m_eClass_Operation_getFeatureType_EStructuralFeature->setUpperBound(1);
	m_eClass_Operation_getFeatureType_EStructuralFeature->setUnique(true);
	m_eClass_Operation_getFeatureType_EStructuralFeature->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eClass_Operation_getFeatureType_EStructuralFeature);
		parameter->setName("feature");
		parameter->setEType(getEStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eClass_Operation_getOperationCount->setName("getOperationCount");
	m_eClass_Operation_getOperationCount->setEType(getEInt_Class());
	m_eClass_Operation_getOperationCount->setLowerBound(0);
	m_eClass_Operation_getOperationCount->setUpperBound(1);
	m_eClass_Operation_getOperationCount->setUnique(true);
	m_eClass_Operation_getOperationCount->setOrdered(true);
	
	m_eClass_Operation_getOperationID_EOperation->setName("getOperationID");
	m_eClass_Operation_getOperationID_EOperation->setEType(getEInt_Class());
	m_eClass_Operation_getOperationID_EOperation->setLowerBound(0);
	m_eClass_Operation_getOperationID_EOperation->setUpperBound(1);
	m_eClass_Operation_getOperationID_EOperation->setUnique(true);
	m_eClass_Operation_getOperationID_EOperation->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eClass_Operation_getOperationID_EOperation);
		parameter->setName("operation");
		parameter->setEType(getEOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eClass_Operation_getOverride_EOperation->setName("getOverride");
	m_eClass_Operation_getOverride_EOperation->setEType(getEOperation_Class());
	m_eClass_Operation_getOverride_EOperation->setLowerBound(0);
	m_eClass_Operation_getOverride_EOperation->setUpperBound(1);
	m_eClass_Operation_getOverride_EOperation->setUnique(true);
	m_eClass_Operation_getOverride_EOperation->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eClass_Operation_getOverride_EOperation);
		parameter->setName("operation");
		parameter->setEType(getEOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eClass_Operation_isSuperTypeOf_EClass->setName("isSuperTypeOf");
	m_eClass_Operation_isSuperTypeOf_EClass->setEType(getEBoolean_Class());
	m_eClass_Operation_isSuperTypeOf_EClass->setLowerBound(0);
	m_eClass_Operation_isSuperTypeOf_EClass->setUpperBound(1);
	m_eClass_Operation_isSuperTypeOf_EClass->setUnique(true);
	m_eClass_Operation_isSuperTypeOf_EClass->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eClass_Operation_isSuperTypeOf_EClass);
		parameter->setName("someClass");
		parameter->setEType(getEClass_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ecorePackageImpl::initializeEClassifierContent()
{
	m_eClassifier_Class->setName("EClassifier");
	m_eClassifier_Class->setAbstract(true);
	m_eClassifier_Class->setInterface(false);
	
	m_eClassifier_Attribute_defaultValue = getEClassifier_Attribute_defaultValue();
	m_eClassifier_Attribute_defaultValue->setName("defaultValue");
		m_eClassifier_Attribute_defaultValue->setEType(getEJavaObject_Class());
	m_eClassifier_Attribute_defaultValue->setLowerBound(0);
	m_eClassifier_Attribute_defaultValue->setUpperBound(1);
	m_eClassifier_Attribute_defaultValue->setTransient(true);
	m_eClassifier_Attribute_defaultValue->setVolatile(true);
	m_eClassifier_Attribute_defaultValue->setChangeable(true);
	m_eClassifier_Attribute_defaultValue->setUnsettable(false);
	m_eClassifier_Attribute_defaultValue->setUnique(true);
	m_eClassifier_Attribute_defaultValue->setDerived(true);
	m_eClassifier_Attribute_defaultValue->setOrdered(true);
	m_eClassifier_Attribute_defaultValue->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eClassifier_Attribute_defaultValue->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eClassifier_Attribute_instanceClass = getEClassifier_Attribute_instanceClass();
	m_eClassifier_Attribute_instanceClass->setName("instanceClass");
		m_eClassifier_Attribute_instanceClass->setEType(getEJavaClass_Class());
	m_eClassifier_Attribute_instanceClass->setLowerBound(0);
	m_eClassifier_Attribute_instanceClass->setUpperBound(1);
	m_eClassifier_Attribute_instanceClass->setTransient(true);
	m_eClassifier_Attribute_instanceClass->setVolatile(true);
	m_eClassifier_Attribute_instanceClass->setChangeable(false);
	m_eClassifier_Attribute_instanceClass->setUnsettable(false);
	m_eClassifier_Attribute_instanceClass->setUnique(true);
	m_eClassifier_Attribute_instanceClass->setDerived(true);
	m_eClassifier_Attribute_instanceClass->setOrdered(true);
	m_eClassifier_Attribute_instanceClass->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eClassifier_Attribute_instanceClass->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eClassifier_Attribute_instanceClassName = getEClassifier_Attribute_instanceClassName();
	m_eClassifier_Attribute_instanceClassName->setName("instanceClassName");
		m_eClassifier_Attribute_instanceClassName->setEType(getEString_Class());
	m_eClassifier_Attribute_instanceClassName->setLowerBound(0);
	m_eClassifier_Attribute_instanceClassName->setUpperBound(1);
	m_eClassifier_Attribute_instanceClassName->setTransient(false);
	m_eClassifier_Attribute_instanceClassName->setVolatile(true);
	m_eClassifier_Attribute_instanceClassName->setChangeable(true);
	m_eClassifier_Attribute_instanceClassName->setUnsettable(true);
	m_eClassifier_Attribute_instanceClassName->setUnique(true);
	m_eClassifier_Attribute_instanceClassName->setDerived(false);
	m_eClassifier_Attribute_instanceClassName->setOrdered(true);
	m_eClassifier_Attribute_instanceClassName->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eClassifier_Attribute_instanceClassName->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eClassifier_Attribute_instanceTypeName = getEClassifier_Attribute_instanceTypeName();
	m_eClassifier_Attribute_instanceTypeName->setName("instanceTypeName");
		m_eClassifier_Attribute_instanceTypeName->setEType(getEString_Class());
	m_eClassifier_Attribute_instanceTypeName->setLowerBound(0);
	m_eClassifier_Attribute_instanceTypeName->setUpperBound(1);
	m_eClassifier_Attribute_instanceTypeName->setTransient(false);
	m_eClassifier_Attribute_instanceTypeName->setVolatile(true);
	m_eClassifier_Attribute_instanceTypeName->setChangeable(true);
	m_eClassifier_Attribute_instanceTypeName->setUnsettable(true);
	m_eClassifier_Attribute_instanceTypeName->setUnique(true);
	m_eClassifier_Attribute_instanceTypeName->setDerived(false);
	m_eClassifier_Attribute_instanceTypeName->setOrdered(true);
	m_eClassifier_Attribute_instanceTypeName->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eClassifier_Attribute_instanceTypeName->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_eClassifier_Attribute_ePackage->setName("ePackage");
	m_eClassifier_Attribute_ePackage->setEType(getEPackage_Class());
	m_eClassifier_Attribute_ePackage->setLowerBound(0);
	m_eClassifier_Attribute_ePackage->setUpperBound(1);
	m_eClassifier_Attribute_ePackage->setTransient(true);
	m_eClassifier_Attribute_ePackage->setVolatile(false);
	m_eClassifier_Attribute_ePackage->setChangeable(false);
	m_eClassifier_Attribute_ePackage->setUnsettable(false);
	m_eClassifier_Attribute_ePackage->setUnique(true);
	m_eClassifier_Attribute_ePackage->setDerived(false);
	m_eClassifier_Attribute_ePackage->setOrdered(true);
	m_eClassifier_Attribute_ePackage->setContainment(false);
	m_eClassifier_Attribute_ePackage->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClassifier_Attribute_ePackage->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ecore::ecorePackage::eInstance()->getEPackage_Attribute_eClassifiers();
		if (otherEnd != nullptr)
	    {
	   		m_eClassifier_Attribute_ePackage->setEOpposite(otherEnd);
	    }
	}
	m_eClassifier_Attribute_eTypeParameters->setName("eTypeParameters");
	m_eClassifier_Attribute_eTypeParameters->setEType(getETypeParameter_Class());
	m_eClassifier_Attribute_eTypeParameters->setLowerBound(0);
	m_eClassifier_Attribute_eTypeParameters->setUpperBound(-1);
	m_eClassifier_Attribute_eTypeParameters->setTransient(false);
	m_eClassifier_Attribute_eTypeParameters->setVolatile(false);
	m_eClassifier_Attribute_eTypeParameters->setChangeable(true);
	m_eClassifier_Attribute_eTypeParameters->setUnsettable(false);
	m_eClassifier_Attribute_eTypeParameters->setUnique(true);
	m_eClassifier_Attribute_eTypeParameters->setDerived(false);
	m_eClassifier_Attribute_eTypeParameters->setOrdered(true);
	m_eClassifier_Attribute_eTypeParameters->setContainment(true);
	m_eClassifier_Attribute_eTypeParameters->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClassifier_Attribute_eTypeParameters->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_eClassifier_Operation_getClassifierID->setName("getClassifierID");
	m_eClassifier_Operation_getClassifierID->setEType(getEInt_Class());
	m_eClassifier_Operation_getClassifierID->setLowerBound(0);
	m_eClassifier_Operation_getClassifierID->setUpperBound(1);
	m_eClassifier_Operation_getClassifierID->setUnique(true);
	m_eClassifier_Operation_getClassifierID->setOrdered(true);
	
	m_eClassifier_Operation_isInstance_EJavaObject->setName("isInstance");
	m_eClassifier_Operation_isInstance_EJavaObject->setEType(getEBoolean_Class());
	m_eClassifier_Operation_isInstance_EJavaObject->setLowerBound(0);
	m_eClassifier_Operation_isInstance_EJavaObject->setUpperBound(1);
	m_eClassifier_Operation_isInstance_EJavaObject->setUnique(true);
	m_eClassifier_Operation_isInstance_EJavaObject->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eClassifier_Operation_isInstance_EJavaObject);
		parameter->setName("object");
		parameter->setEType(getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ecorePackageImpl::initializeEDataTypeContent()
{
	m_eDataType_Class->setName("EDataType");
	m_eDataType_Class->setAbstract(false);
	m_eDataType_Class->setInterface(false);
	
	m_eDataType_Attribute_serializable = getEDataType_Attribute_serializable();
	m_eDataType_Attribute_serializable->setName("serializable");
		m_eDataType_Attribute_serializable->setEType(getEBoolean_Class());
	m_eDataType_Attribute_serializable->setLowerBound(0);
	m_eDataType_Attribute_serializable->setUpperBound(1);
	m_eDataType_Attribute_serializable->setTransient(false);
	m_eDataType_Attribute_serializable->setVolatile(false);
	m_eDataType_Attribute_serializable->setChangeable(true);
	m_eDataType_Attribute_serializable->setUnsettable(false);
	m_eDataType_Attribute_serializable->setUnique(true);
	m_eDataType_Attribute_serializable->setDerived(false);
	m_eDataType_Attribute_serializable->setOrdered(true);
	m_eDataType_Attribute_serializable->setID(false);
	{
		std::string defaultValue = "true";
		if (!defaultValue.empty())
		{
		   m_eDataType_Attribute_serializable->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	
}

void ecorePackageImpl::initializeEEnumContent()
{
	m_eEnum_Class->setName("EEnum");
	m_eEnum_Class->setAbstract(false);
	m_eEnum_Class->setInterface(false);
	
	
	m_eEnum_Attribute_eLiterals->setName("eLiterals");
	m_eEnum_Attribute_eLiterals->setEType(getEEnumLiteral_Class());
	m_eEnum_Attribute_eLiterals->setLowerBound(0);
	m_eEnum_Attribute_eLiterals->setUpperBound(-1);
	m_eEnum_Attribute_eLiterals->setTransient(false);
	m_eEnum_Attribute_eLiterals->setVolatile(false);
	m_eEnum_Attribute_eLiterals->setChangeable(true);
	m_eEnum_Attribute_eLiterals->setUnsettable(false);
	m_eEnum_Attribute_eLiterals->setUnique(true);
	m_eEnum_Attribute_eLiterals->setDerived(false);
	m_eEnum_Attribute_eLiterals->setOrdered(true);
	m_eEnum_Attribute_eLiterals->setContainment(true);
	m_eEnum_Attribute_eLiterals->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eEnum_Attribute_eLiterals->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ecore::ecorePackage::eInstance()->getEEnumLiteral_Attribute_eEnum();
		if (otherEnd != nullptr)
	    {
	   		m_eEnum_Attribute_eLiterals->setEOpposite(otherEnd);
	    }
	}
	
	m_eEnum_Operation_getEEnumLiteral_EString->setName("getEEnumLiteral");
	m_eEnum_Operation_getEEnumLiteral_EString->setEType(getEEnumLiteral_Class());
	m_eEnum_Operation_getEEnumLiteral_EString->setLowerBound(0);
	m_eEnum_Operation_getEEnumLiteral_EString->setUpperBound(1);
	m_eEnum_Operation_getEEnumLiteral_EString->setUnique(true);
	m_eEnum_Operation_getEEnumLiteral_EString->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eEnum_Operation_getEEnumLiteral_EString);
		parameter->setName("name");
		parameter->setEType(getEString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eEnum_Operation_getEEnumLiteral_EInt->setName("getEEnumLiteral");
	m_eEnum_Operation_getEEnumLiteral_EInt->setEType(getEEnumLiteral_Class());
	m_eEnum_Operation_getEEnumLiteral_EInt->setLowerBound(0);
	m_eEnum_Operation_getEEnumLiteral_EInt->setUpperBound(1);
	m_eEnum_Operation_getEEnumLiteral_EInt->setUnique(true);
	m_eEnum_Operation_getEEnumLiteral_EInt->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eEnum_Operation_getEEnumLiteral_EInt);
		parameter->setName("value");
		parameter->setEType(getEInt_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eEnum_Operation_getEEnumLiteralByLiteral_EString->setName("getEEnumLiteralByLiteral");
	m_eEnum_Operation_getEEnumLiteralByLiteral_EString->setEType(getEEnumLiteral_Class());
	m_eEnum_Operation_getEEnumLiteralByLiteral_EString->setLowerBound(0);
	m_eEnum_Operation_getEEnumLiteralByLiteral_EString->setUpperBound(1);
	m_eEnum_Operation_getEEnumLiteralByLiteral_EString->setUnique(true);
	m_eEnum_Operation_getEEnumLiteralByLiteral_EString->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eEnum_Operation_getEEnumLiteralByLiteral_EString);
		parameter->setName("literal");
		parameter->setEType(getEString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ecorePackageImpl::initializeEEnumLiteralContent()
{
	m_eEnumLiteral_Class->setName("EEnumLiteral");
	m_eEnumLiteral_Class->setAbstract(false);
	m_eEnumLiteral_Class->setInterface(false);
	
	m_eEnumLiteral_Attribute_instance = getEEnumLiteral_Attribute_instance();
	m_eEnumLiteral_Attribute_instance->setName("instance");
		m_eEnumLiteral_Attribute_instance->setEType(getEEnumerator_Class());
	m_eEnumLiteral_Attribute_instance->setLowerBound(0);
	m_eEnumLiteral_Attribute_instance->setUpperBound(1);
	m_eEnumLiteral_Attribute_instance->setTransient(true);
	m_eEnumLiteral_Attribute_instance->setVolatile(false);
	m_eEnumLiteral_Attribute_instance->setChangeable(true);
	m_eEnumLiteral_Attribute_instance->setUnsettable(false);
	m_eEnumLiteral_Attribute_instance->setUnique(true);
	m_eEnumLiteral_Attribute_instance->setDerived(false);
	m_eEnumLiteral_Attribute_instance->setOrdered(true);
	m_eEnumLiteral_Attribute_instance->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eEnumLiteral_Attribute_instance->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eEnumLiteral_Attribute_literal = getEEnumLiteral_Attribute_literal();
	m_eEnumLiteral_Attribute_literal->setName("literal");
		m_eEnumLiteral_Attribute_literal->setEType(getEString_Class());
	m_eEnumLiteral_Attribute_literal->setLowerBound(0);
	m_eEnumLiteral_Attribute_literal->setUpperBound(1);
	m_eEnumLiteral_Attribute_literal->setTransient(false);
	m_eEnumLiteral_Attribute_literal->setVolatile(false);
	m_eEnumLiteral_Attribute_literal->setChangeable(true);
	m_eEnumLiteral_Attribute_literal->setUnsettable(false);
	m_eEnumLiteral_Attribute_literal->setUnique(true);
	m_eEnumLiteral_Attribute_literal->setDerived(false);
	m_eEnumLiteral_Attribute_literal->setOrdered(true);
	m_eEnumLiteral_Attribute_literal->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eEnumLiteral_Attribute_literal->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eEnumLiteral_Attribute_value = getEEnumLiteral_Attribute_value();
	m_eEnumLiteral_Attribute_value->setName("value");
		m_eEnumLiteral_Attribute_value->setEType(getEInt_Class());
	m_eEnumLiteral_Attribute_value->setLowerBound(0);
	m_eEnumLiteral_Attribute_value->setUpperBound(1);
	m_eEnumLiteral_Attribute_value->setTransient(false);
	m_eEnumLiteral_Attribute_value->setVolatile(false);
	m_eEnumLiteral_Attribute_value->setChangeable(true);
	m_eEnumLiteral_Attribute_value->setUnsettable(false);
	m_eEnumLiteral_Attribute_value->setUnique(true);
	m_eEnumLiteral_Attribute_value->setDerived(false);
	m_eEnumLiteral_Attribute_value->setOrdered(true);
	m_eEnumLiteral_Attribute_value->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eEnumLiteral_Attribute_value->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_eEnumLiteral_Attribute_eEnum->setName("eEnum");
	m_eEnumLiteral_Attribute_eEnum->setEType(getEEnum_Class());
	m_eEnumLiteral_Attribute_eEnum->setLowerBound(0);
	m_eEnumLiteral_Attribute_eEnum->setUpperBound(1);
	m_eEnumLiteral_Attribute_eEnum->setTransient(true);
	m_eEnumLiteral_Attribute_eEnum->setVolatile(false);
	m_eEnumLiteral_Attribute_eEnum->setChangeable(false);
	m_eEnumLiteral_Attribute_eEnum->setUnsettable(false);
	m_eEnumLiteral_Attribute_eEnum->setUnique(true);
	m_eEnumLiteral_Attribute_eEnum->setDerived(false);
	m_eEnumLiteral_Attribute_eEnum->setOrdered(true);
	m_eEnumLiteral_Attribute_eEnum->setContainment(false);
	m_eEnumLiteral_Attribute_eEnum->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eEnumLiteral_Attribute_eEnum->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ecore::ecorePackage::eInstance()->getEEnum_Attribute_eLiterals();
		if (otherEnd != nullptr)
	    {
	   		m_eEnumLiteral_Attribute_eEnum->setEOpposite(otherEnd);
	    }
	}
	
	
}

void ecorePackageImpl::initializeEFactoryContent()
{
	m_eFactory_Class->setName("EFactory");
	m_eFactory_Class->setAbstract(false);
	m_eFactory_Class->setInterface(false);
	
	
	m_eFactory_Attribute_ePackage->setName("ePackage");
	m_eFactory_Attribute_ePackage->setEType(getEPackage_Class());
	m_eFactory_Attribute_ePackage->setLowerBound(1);
	m_eFactory_Attribute_ePackage->setUpperBound(1);
	m_eFactory_Attribute_ePackage->setTransient(true);
	m_eFactory_Attribute_ePackage->setVolatile(false);
	m_eFactory_Attribute_ePackage->setChangeable(true);
	m_eFactory_Attribute_ePackage->setUnsettable(false);
	m_eFactory_Attribute_ePackage->setUnique(true);
	m_eFactory_Attribute_ePackage->setDerived(false);
	m_eFactory_Attribute_ePackage->setOrdered(true);
	m_eFactory_Attribute_ePackage->setContainment(false);
	m_eFactory_Attribute_ePackage->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eFactory_Attribute_ePackage->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ecore::ecorePackage::eInstance()->getEPackage_Attribute_eFactoryInstance();
		if (otherEnd != nullptr)
	    {
	   		m_eFactory_Attribute_ePackage->setEOpposite(otherEnd);
	    }
	}
	
	m_eFactory_Operation_convertToString_EDataType_EJavaObject->setName("convertToString");
	m_eFactory_Operation_convertToString_EDataType_EJavaObject->setEType(getEString_Class());
	m_eFactory_Operation_convertToString_EDataType_EJavaObject->setLowerBound(0);
	m_eFactory_Operation_convertToString_EDataType_EJavaObject->setUpperBound(1);
	m_eFactory_Operation_convertToString_EDataType_EJavaObject->setUnique(true);
	m_eFactory_Operation_convertToString_EDataType_EJavaObject->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eFactory_Operation_convertToString_EDataType_EJavaObject);
		parameter->setName("eDataType");
		parameter->setEType(getEDataType_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eFactory_Operation_convertToString_EDataType_EJavaObject);
		parameter->setName("instanceValue");
		parameter->setEType(getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eFactory_Operation_create_EClass->setName("create");
	m_eFactory_Operation_create_EClass->setEType(getEObject_Class());
	m_eFactory_Operation_create_EClass->setLowerBound(0);
	m_eFactory_Operation_create_EClass->setUpperBound(1);
	m_eFactory_Operation_create_EClass->setUnique(true);
	m_eFactory_Operation_create_EClass->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eFactory_Operation_create_EClass);
		parameter->setName("eClass");
		parameter->setEType(getEClass_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eFactory_Operation_createFromString_EDataType_EString->setName("createFromString");
	m_eFactory_Operation_createFromString_EDataType_EString->setEType(getEJavaObject_Class());
	m_eFactory_Operation_createFromString_EDataType_EString->setLowerBound(0);
	m_eFactory_Operation_createFromString_EDataType_EString->setUpperBound(1);
	m_eFactory_Operation_createFromString_EDataType_EString->setUnique(true);
	m_eFactory_Operation_createFromString_EDataType_EString->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eFactory_Operation_createFromString_EDataType_EString);
		parameter->setName("eDataType");
		parameter->setEType(getEDataType_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eFactory_Operation_createFromString_EDataType_EString);
		parameter->setName("literalValue");
		parameter->setEType(getEString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ecorePackageImpl::initializeEGenericTypeContent()
{
	m_eGenericType_Class->setName("EGenericType");
	m_eGenericType_Class->setAbstract(false);
	m_eGenericType_Class->setInterface(false);
	
	
	m_eGenericType_Attribute_eClassifier->setName("eClassifier");
	m_eGenericType_Attribute_eClassifier->setEType(getEClassifier_Class());
	m_eGenericType_Attribute_eClassifier->setLowerBound(0);
	m_eGenericType_Attribute_eClassifier->setUpperBound(1);
	m_eGenericType_Attribute_eClassifier->setTransient(false);
	m_eGenericType_Attribute_eClassifier->setVolatile(false);
	m_eGenericType_Attribute_eClassifier->setChangeable(true);
	m_eGenericType_Attribute_eClassifier->setUnsettable(false);
	m_eGenericType_Attribute_eClassifier->setUnique(true);
	m_eGenericType_Attribute_eClassifier->setDerived(false);
	m_eGenericType_Attribute_eClassifier->setOrdered(true);
	m_eGenericType_Attribute_eClassifier->setContainment(false);
	m_eGenericType_Attribute_eClassifier->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eGenericType_Attribute_eClassifier->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_eGenericType_Attribute_eLowerBound->setName("eLowerBound");
	m_eGenericType_Attribute_eLowerBound->setEType(getEGenericType_Class());
	m_eGenericType_Attribute_eLowerBound->setLowerBound(0);
	m_eGenericType_Attribute_eLowerBound->setUpperBound(1);
	m_eGenericType_Attribute_eLowerBound->setTransient(false);
	m_eGenericType_Attribute_eLowerBound->setVolatile(false);
	m_eGenericType_Attribute_eLowerBound->setChangeable(true);
	m_eGenericType_Attribute_eLowerBound->setUnsettable(false);
	m_eGenericType_Attribute_eLowerBound->setUnique(true);
	m_eGenericType_Attribute_eLowerBound->setDerived(false);
	m_eGenericType_Attribute_eLowerBound->setOrdered(true);
	m_eGenericType_Attribute_eLowerBound->setContainment(true);
	m_eGenericType_Attribute_eLowerBound->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eGenericType_Attribute_eLowerBound->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_eGenericType_Attribute_eRawType->setName("eRawType");
	m_eGenericType_Attribute_eRawType->setEType(getEClassifier_Class());
	m_eGenericType_Attribute_eRawType->setLowerBound(1);
	m_eGenericType_Attribute_eRawType->setUpperBound(1);
	m_eGenericType_Attribute_eRawType->setTransient(true);
	m_eGenericType_Attribute_eRawType->setVolatile(false);
	m_eGenericType_Attribute_eRawType->setChangeable(true);
	m_eGenericType_Attribute_eRawType->setUnsettable(false);
	m_eGenericType_Attribute_eRawType->setUnique(true);
	m_eGenericType_Attribute_eRawType->setDerived(true);
	m_eGenericType_Attribute_eRawType->setOrdered(true);
	m_eGenericType_Attribute_eRawType->setContainment(false);
	m_eGenericType_Attribute_eRawType->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eGenericType_Attribute_eRawType->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_eGenericType_Attribute_eTypeArguments->setName("eTypeArguments");
	m_eGenericType_Attribute_eTypeArguments->setEType(getEGenericType_Class());
	m_eGenericType_Attribute_eTypeArguments->setLowerBound(0);
	m_eGenericType_Attribute_eTypeArguments->setUpperBound(-1);
	m_eGenericType_Attribute_eTypeArguments->setTransient(false);
	m_eGenericType_Attribute_eTypeArguments->setVolatile(false);
	m_eGenericType_Attribute_eTypeArguments->setChangeable(true);
	m_eGenericType_Attribute_eTypeArguments->setUnsettable(false);
	m_eGenericType_Attribute_eTypeArguments->setUnique(true);
	m_eGenericType_Attribute_eTypeArguments->setDerived(false);
	m_eGenericType_Attribute_eTypeArguments->setOrdered(true);
	m_eGenericType_Attribute_eTypeArguments->setContainment(true);
	m_eGenericType_Attribute_eTypeArguments->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eGenericType_Attribute_eTypeArguments->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_eGenericType_Attribute_eTypeParameter->setName("eTypeParameter");
	m_eGenericType_Attribute_eTypeParameter->setEType(getETypeParameter_Class());
	m_eGenericType_Attribute_eTypeParameter->setLowerBound(0);
	m_eGenericType_Attribute_eTypeParameter->setUpperBound(1);
	m_eGenericType_Attribute_eTypeParameter->setTransient(false);
	m_eGenericType_Attribute_eTypeParameter->setVolatile(false);
	m_eGenericType_Attribute_eTypeParameter->setChangeable(true);
	m_eGenericType_Attribute_eTypeParameter->setUnsettable(false);
	m_eGenericType_Attribute_eTypeParameter->setUnique(true);
	m_eGenericType_Attribute_eTypeParameter->setDerived(false);
	m_eGenericType_Attribute_eTypeParameter->setOrdered(true);
	m_eGenericType_Attribute_eTypeParameter->setContainment(false);
	m_eGenericType_Attribute_eTypeParameter->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eGenericType_Attribute_eTypeParameter->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_eGenericType_Attribute_eUpperBound->setName("eUpperBound");
	m_eGenericType_Attribute_eUpperBound->setEType(getEGenericType_Class());
	m_eGenericType_Attribute_eUpperBound->setLowerBound(0);
	m_eGenericType_Attribute_eUpperBound->setUpperBound(1);
	m_eGenericType_Attribute_eUpperBound->setTransient(false);
	m_eGenericType_Attribute_eUpperBound->setVolatile(false);
	m_eGenericType_Attribute_eUpperBound->setChangeable(true);
	m_eGenericType_Attribute_eUpperBound->setUnsettable(false);
	m_eGenericType_Attribute_eUpperBound->setUnique(true);
	m_eGenericType_Attribute_eUpperBound->setDerived(false);
	m_eGenericType_Attribute_eUpperBound->setOrdered(true);
	m_eGenericType_Attribute_eUpperBound->setContainment(true);
	m_eGenericType_Attribute_eUpperBound->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eGenericType_Attribute_eUpperBound->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_eGenericType_Operation_isInstance_EJavaObject->setName("isInstance");
	m_eGenericType_Operation_isInstance_EJavaObject->setEType(getEBoolean_Class());
	m_eGenericType_Operation_isInstance_EJavaObject->setLowerBound(0);
	m_eGenericType_Operation_isInstance_EJavaObject->setUpperBound(1);
	m_eGenericType_Operation_isInstance_EJavaObject->setUnique(true);
	m_eGenericType_Operation_isInstance_EJavaObject->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eGenericType_Operation_isInstance_EJavaObject);
		parameter->setName("object");
		parameter->setEType(getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ecorePackageImpl::initializeEModelElementContent()
{
	m_eModelElement_Class->setName("EModelElement");
	m_eModelElement_Class->setAbstract(true);
	m_eModelElement_Class->setInterface(false);
	
	
	m_eModelElement_Attribute_eAnnotations->setName("eAnnotations");
	m_eModelElement_Attribute_eAnnotations->setEType(getEAnnotation_Class());
	m_eModelElement_Attribute_eAnnotations->setLowerBound(0);
	m_eModelElement_Attribute_eAnnotations->setUpperBound(-1);
	m_eModelElement_Attribute_eAnnotations->setTransient(false);
	m_eModelElement_Attribute_eAnnotations->setVolatile(false);
	m_eModelElement_Attribute_eAnnotations->setChangeable(true);
	m_eModelElement_Attribute_eAnnotations->setUnsettable(false);
	m_eModelElement_Attribute_eAnnotations->setUnique(true);
	m_eModelElement_Attribute_eAnnotations->setDerived(false);
	m_eModelElement_Attribute_eAnnotations->setOrdered(true);
	m_eModelElement_Attribute_eAnnotations->setContainment(true);
	m_eModelElement_Attribute_eAnnotations->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eModelElement_Attribute_eAnnotations->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ecore::ecorePackage::eInstance()->getEAnnotation_Attribute_eModelElement();
		if (otherEnd != nullptr)
	    {
	   		m_eModelElement_Attribute_eAnnotations->setEOpposite(otherEnd);
	    }
	}
	
	m_eModelElement_Operation_getEAnnotation_EString->setName("getEAnnotation");
	m_eModelElement_Operation_getEAnnotation_EString->setEType(getEAnnotation_Class());
	m_eModelElement_Operation_getEAnnotation_EString->setLowerBound(0);
	m_eModelElement_Operation_getEAnnotation_EString->setUpperBound(1);
	m_eModelElement_Operation_getEAnnotation_EString->setUnique(true);
	m_eModelElement_Operation_getEAnnotation_EString->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eModelElement_Operation_getEAnnotation_EString);
		parameter->setName("source");
		parameter->setEType(getEString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ecorePackageImpl::initializeENamedElementContent()
{
	m_eNamedElement_Class->setName("ENamedElement");
	m_eNamedElement_Class->setAbstract(true);
	m_eNamedElement_Class->setInterface(false);
	
	m_eNamedElement_Attribute_name = getENamedElement_Attribute_name();
	m_eNamedElement_Attribute_name->setName("name");
		m_eNamedElement_Attribute_name->setEType(getEString_Class());
	m_eNamedElement_Attribute_name->setLowerBound(0);
	m_eNamedElement_Attribute_name->setUpperBound(1);
	m_eNamedElement_Attribute_name->setTransient(false);
	m_eNamedElement_Attribute_name->setVolatile(false);
	m_eNamedElement_Attribute_name->setChangeable(true);
	m_eNamedElement_Attribute_name->setUnsettable(false);
	m_eNamedElement_Attribute_name->setUnique(true);
	m_eNamedElement_Attribute_name->setDerived(false);
	m_eNamedElement_Attribute_name->setOrdered(true);
	m_eNamedElement_Attribute_name->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eNamedElement_Attribute_name->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	
}

void ecorePackageImpl::initializeEObjectContent()
{
	m_eObject_Class->setName("EObject");
	m_eObject_Class->setAbstract(false);
	m_eObject_Class->setInterface(false);
	
	m_eObject_Attribute_metaElementID = getEObject_Attribute_metaElementID();
	m_eObject_Attribute_metaElementID->setName("metaElementID");
		m_eObject_Attribute_metaElementID->setEType(getEInt_Class());
	m_eObject_Attribute_metaElementID->setLowerBound(0);
	m_eObject_Attribute_metaElementID->setUpperBound(1);
	m_eObject_Attribute_metaElementID->setTransient(false);
	m_eObject_Attribute_metaElementID->setVolatile(false);
	m_eObject_Attribute_metaElementID->setChangeable(true);
	m_eObject_Attribute_metaElementID->setUnsettable(true);
	m_eObject_Attribute_metaElementID->setUnique(true);
	m_eObject_Attribute_metaElementID->setDerived(false);
	m_eObject_Attribute_metaElementID->setOrdered(true);
	m_eObject_Attribute_metaElementID->setID(false);
	{
		std::string defaultValue = "0";
		if (!defaultValue.empty())
		{
		   m_eObject_Attribute_metaElementID->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_eObject_Attribute_eContainer->setName("eContainer");
	m_eObject_Attribute_eContainer->setEType(getEObject_Class());
	m_eObject_Attribute_eContainer->setLowerBound(0);
	m_eObject_Attribute_eContainer->setUpperBound(1);
	m_eObject_Attribute_eContainer->setTransient(false);
	m_eObject_Attribute_eContainer->setVolatile(false);
	m_eObject_Attribute_eContainer->setChangeable(true);
	m_eObject_Attribute_eContainer->setUnsettable(false);
	m_eObject_Attribute_eContainer->setUnique(true);
	m_eObject_Attribute_eContainer->setDerived(false);
	m_eObject_Attribute_eContainer->setOrdered(true);
	m_eObject_Attribute_eContainer->setContainment(false);
	m_eObject_Attribute_eContainer->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eObject_Attribute_eContainer->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ecore::ecorePackage::eInstance()->getEObject_Attribute_eContentUnion();
		if (otherEnd != nullptr)
	    {
	   		m_eObject_Attribute_eContainer->setEOpposite(otherEnd);
	    }
	}
	m_eObject_Attribute_eContentUnion->setName("eContentUnion");
	m_eObject_Attribute_eContentUnion->setEType(getEObject_Class());
	m_eObject_Attribute_eContentUnion->setLowerBound(0);
	m_eObject_Attribute_eContentUnion->setUpperBound(-1);
	m_eObject_Attribute_eContentUnion->setTransient(false);
	m_eObject_Attribute_eContentUnion->setVolatile(false);
	m_eObject_Attribute_eContentUnion->setChangeable(true);
	m_eObject_Attribute_eContentUnion->setUnsettable(false);
	m_eObject_Attribute_eContentUnion->setUnique(true);
	m_eObject_Attribute_eContentUnion->setDerived(false);
	m_eObject_Attribute_eContentUnion->setOrdered(true);
	m_eObject_Attribute_eContentUnion->setContainment(true);
	m_eObject_Attribute_eContentUnion->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eObject_Attribute_eContentUnion->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ecore::ecorePackage::eInstance()->getEObject_Attribute_eContainer();
		if (otherEnd != nullptr)
	    {
	   		m_eObject_Attribute_eContentUnion->setEOpposite(otherEnd);
	    }
	}
	
	m_eObject_Operation_eAllContents->setName("eAllContents");
	m_eObject_Operation_eAllContents->setEType(getEJavaObject_Class());
	m_eObject_Operation_eAllContents->setLowerBound(0);
	m_eObject_Operation_eAllContents->setUpperBound(1);
	m_eObject_Operation_eAllContents->setUnique(true);
	m_eObject_Operation_eAllContents->setOrdered(true);
	
	m_eObject_Operation_eClass->setName("eClass");
	m_eObject_Operation_eClass->setEType(getEClass_Class());
	m_eObject_Operation_eClass->setLowerBound(0);
	m_eObject_Operation_eClass->setUpperBound(1);
	m_eObject_Operation_eClass->setUnique(true);
	m_eObject_Operation_eClass->setOrdered(true);
	
	m_eObject_Operation_eContainer->setName("eContainer");
	m_eObject_Operation_eContainer->setEType(getEObject_Class());
	m_eObject_Operation_eContainer->setLowerBound(0);
	m_eObject_Operation_eContainer->setUpperBound(1);
	m_eObject_Operation_eContainer->setUnique(true);
	m_eObject_Operation_eContainer->setOrdered(true);
	
	m_eObject_Operation_eContainingFeature->setName("eContainingFeature");
	m_eObject_Operation_eContainingFeature->setEType(getEStructuralFeature_Class());
	m_eObject_Operation_eContainingFeature->setLowerBound(0);
	m_eObject_Operation_eContainingFeature->setUpperBound(1);
	m_eObject_Operation_eContainingFeature->setUnique(true);
	m_eObject_Operation_eContainingFeature->setOrdered(true);
	
	m_eObject_Operation_eContainmentFeature->setName("eContainmentFeature");
	m_eObject_Operation_eContainmentFeature->setEType(getEReference_Class());
	m_eObject_Operation_eContainmentFeature->setLowerBound(0);
	m_eObject_Operation_eContainmentFeature->setUpperBound(1);
	m_eObject_Operation_eContainmentFeature->setUnique(true);
	m_eObject_Operation_eContainmentFeature->setOrdered(true);
	
	m_eObject_Operation_eContents->setName("eContents");
	m_eObject_Operation_eContents->setEType(getEObject_Class());
	m_eObject_Operation_eContents->setLowerBound(0);
	m_eObject_Operation_eContents->setUpperBound(-1);
	m_eObject_Operation_eContents->setUnique(true);
	m_eObject_Operation_eContents->setOrdered(true);
	
	m_eObject_Operation_eCrossReferences->setName("eCrossReferences");
	m_eObject_Operation_eCrossReferences->setEType(getEEList_Class());
	m_eObject_Operation_eCrossReferences->setLowerBound(0);
	m_eObject_Operation_eCrossReferences->setUpperBound(1);
	m_eObject_Operation_eCrossReferences->setUnique(true);
	m_eObject_Operation_eCrossReferences->setOrdered(true);
	
	m_eObject_Operation_eGet_EStructuralFeature->setName("eGet");
	m_eObject_Operation_eGet_EStructuralFeature->setEType(getEJavaObject_Class());
	m_eObject_Operation_eGet_EStructuralFeature->setLowerBound(0);
	m_eObject_Operation_eGet_EStructuralFeature->setUpperBound(1);
	m_eObject_Operation_eGet_EStructuralFeature->setUnique(true);
	m_eObject_Operation_eGet_EStructuralFeature->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eObject_Operation_eGet_EStructuralFeature);
		parameter->setName("feature");
		parameter->setEType(getEStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eObject_Operation_eGet_EStructuralFeature_EBoolean->setName("eGet");
	m_eObject_Operation_eGet_EStructuralFeature_EBoolean->setEType(getEJavaObject_Class());
	m_eObject_Operation_eGet_EStructuralFeature_EBoolean->setLowerBound(0);
	m_eObject_Operation_eGet_EStructuralFeature_EBoolean->setUpperBound(1);
	m_eObject_Operation_eGet_EStructuralFeature_EBoolean->setUnique(true);
	m_eObject_Operation_eGet_EStructuralFeature_EBoolean->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eObject_Operation_eGet_EStructuralFeature_EBoolean);
		parameter->setName("feature");
		parameter->setEType(getEStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eObject_Operation_eGet_EStructuralFeature_EBoolean);
		parameter->setName("resolve");
		parameter->setEType(getEBoolean_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eObject_Operation_eInvoke_EOperation_EEList->setName("eInvoke");
	m_eObject_Operation_eInvoke_EOperation_EEList->setEType(getEJavaObject_Class());
	m_eObject_Operation_eInvoke_EOperation_EEList->setLowerBound(0);
	m_eObject_Operation_eInvoke_EOperation_EEList->setUpperBound(1);
	m_eObject_Operation_eInvoke_EOperation_EEList->setUnique(true);
	m_eObject_Operation_eInvoke_EOperation_EEList->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eObject_Operation_eInvoke_EOperation_EEList);
		parameter->setName("operation");
		parameter->setEType(getEOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eObject_Operation_eInvoke_EOperation_EEList);
		parameter->setName("arguments");
		parameter->setEType(getEEList_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eObject_Operation_eIsProxy->setName("eIsProxy");
	m_eObject_Operation_eIsProxy->setEType(getEBoolean_Class());
	m_eObject_Operation_eIsProxy->setLowerBound(0);
	m_eObject_Operation_eIsProxy->setUpperBound(1);
	m_eObject_Operation_eIsProxy->setUnique(true);
	m_eObject_Operation_eIsProxy->setOrdered(true);
	
	m_eObject_Operation_eIsSet_EStructuralFeature->setName("eIsSet");
	m_eObject_Operation_eIsSet_EStructuralFeature->setEType(getEBoolean_Class());
	m_eObject_Operation_eIsSet_EStructuralFeature->setLowerBound(0);
	m_eObject_Operation_eIsSet_EStructuralFeature->setUpperBound(1);
	m_eObject_Operation_eIsSet_EStructuralFeature->setUnique(true);
	m_eObject_Operation_eIsSet_EStructuralFeature->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eObject_Operation_eIsSet_EStructuralFeature);
		parameter->setName("feature");
		parameter->setEType(getEStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eObject_Operation_eResource->setName("eResource");
	m_eObject_Operation_eResource->setEType(getEResource_Class());
	m_eObject_Operation_eResource->setLowerBound(0);
	m_eObject_Operation_eResource->setUpperBound(1);
	m_eObject_Operation_eResource->setUnique(true);
	m_eObject_Operation_eResource->setOrdered(true);
	
	m_eObject_Operation_eSet_EStructuralFeature_EJavaObject->setName("eSet");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_eObject_Operation_eSet_EStructuralFeature_EJavaObject->setEType(unknownClass);
	}
	m_eObject_Operation_eSet_EStructuralFeature_EJavaObject->setLowerBound(0);
	m_eObject_Operation_eSet_EStructuralFeature_EJavaObject->setUpperBound(1);
	m_eObject_Operation_eSet_EStructuralFeature_EJavaObject->setUnique(true);
	m_eObject_Operation_eSet_EStructuralFeature_EJavaObject->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eObject_Operation_eSet_EStructuralFeature_EJavaObject);
		parameter->setName("feature");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eObject_Operation_eSet_EStructuralFeature_EJavaObject);
		parameter->setName("newValue");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eObject_Operation_eUnset_EStructuralFeature->setName("eUnset");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_eObject_Operation_eUnset_EStructuralFeature->setEType(unknownClass);
	}
	m_eObject_Operation_eUnset_EStructuralFeature->setLowerBound(0);
	m_eObject_Operation_eUnset_EStructuralFeature->setUpperBound(1);
	m_eObject_Operation_eUnset_EStructuralFeature->setUnique(true);
	m_eObject_Operation_eUnset_EStructuralFeature->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eObject_Operation_eUnset_EStructuralFeature);
		parameter->setName("feature");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ecorePackageImpl::initializeEObjectContainerContent()
{
	m_eObjectContainer_Class->setName("EObjectContainer");
	m_eObjectContainer_Class->setAbstract(false);
	m_eObjectContainer_Class->setInterface(false);
	
	
	m_eObjectContainer_Attribute_container->setName("container");
	m_eObjectContainer_Attribute_container->setEType(getEObject_Class());
	m_eObjectContainer_Attribute_container->setLowerBound(0);
	m_eObjectContainer_Attribute_container->setUpperBound(-1);
	m_eObjectContainer_Attribute_container->setTransient(false);
	m_eObjectContainer_Attribute_container->setVolatile(false);
	m_eObjectContainer_Attribute_container->setChangeable(true);
	m_eObjectContainer_Attribute_container->setUnsettable(false);
	m_eObjectContainer_Attribute_container->setUnique(true);
	m_eObjectContainer_Attribute_container->setDerived(false);
	m_eObjectContainer_Attribute_container->setOrdered(true);
	m_eObjectContainer_Attribute_container->setContainment(false);
	m_eObjectContainer_Attribute_container->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eObjectContainer_Attribute_container->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_eObjectContainer_Operation_setContainer_EObject->setName("setContainer");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_eObjectContainer_Operation_setContainer_EObject->setEType(unknownClass);
	}
	m_eObjectContainer_Operation_setContainer_EObject->setLowerBound(0);
	m_eObjectContainer_Operation_setContainer_EObject->setUpperBound(1);
	m_eObjectContainer_Operation_setContainer_EObject->setUnique(true);
	m_eObjectContainer_Operation_setContainer_EObject->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eObjectContainer_Operation_setContainer_EObject);
		parameter->setName("container");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ecorePackageImpl::initializeEOperationContent()
{
	m_eOperation_Class->setName("EOperation");
	m_eOperation_Class->setAbstract(false);
	m_eOperation_Class->setInterface(false);
	
	m_eOperation_Attribute_operationID = getEOperation_Attribute_operationID();
	m_eOperation_Attribute_operationID->setName("operationID");
		m_eOperation_Attribute_operationID->setEType(getEInt_Class());
	m_eOperation_Attribute_operationID->setLowerBound(0);
	m_eOperation_Attribute_operationID->setUpperBound(1);
	m_eOperation_Attribute_operationID->setTransient(false);
	m_eOperation_Attribute_operationID->setVolatile(false);
	m_eOperation_Attribute_operationID->setChangeable(false);
	m_eOperation_Attribute_operationID->setUnsettable(false);
	m_eOperation_Attribute_operationID->setUnique(true);
	m_eOperation_Attribute_operationID->setDerived(false);
	m_eOperation_Attribute_operationID->setOrdered(true);
	m_eOperation_Attribute_operationID->setID(false);
	{
		std::string defaultValue = "-1";
		if (!defaultValue.empty())
		{
		   m_eOperation_Attribute_operationID->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_eOperation_Attribute_eContainingClass->setName("eContainingClass");
	m_eOperation_Attribute_eContainingClass->setEType(getEClass_Class());
	m_eOperation_Attribute_eContainingClass->setLowerBound(0);
	m_eOperation_Attribute_eContainingClass->setUpperBound(1);
	m_eOperation_Attribute_eContainingClass->setTransient(true);
	m_eOperation_Attribute_eContainingClass->setVolatile(false);
	m_eOperation_Attribute_eContainingClass->setChangeable(false);
	m_eOperation_Attribute_eContainingClass->setUnsettable(false);
	m_eOperation_Attribute_eContainingClass->setUnique(true);
	m_eOperation_Attribute_eContainingClass->setDerived(false);
	m_eOperation_Attribute_eContainingClass->setOrdered(true);
	m_eOperation_Attribute_eContainingClass->setContainment(false);
	m_eOperation_Attribute_eContainingClass->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eOperation_Attribute_eContainingClass->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ecore::ecorePackage::eInstance()->getEClass_Attribute_eOperations();
		if (otherEnd != nullptr)
	    {
	   		m_eOperation_Attribute_eContainingClass->setEOpposite(otherEnd);
	    }
	}
	m_eOperation_Attribute_eExceptions->setName("eExceptions");
	m_eOperation_Attribute_eExceptions->setEType(getEClassifier_Class());
	m_eOperation_Attribute_eExceptions->setLowerBound(0);
	m_eOperation_Attribute_eExceptions->setUpperBound(-1);
	m_eOperation_Attribute_eExceptions->setTransient(false);
	m_eOperation_Attribute_eExceptions->setVolatile(false);
	m_eOperation_Attribute_eExceptions->setChangeable(true);
	m_eOperation_Attribute_eExceptions->setUnsettable(true);
	m_eOperation_Attribute_eExceptions->setUnique(true);
	m_eOperation_Attribute_eExceptions->setDerived(false);
	m_eOperation_Attribute_eExceptions->setOrdered(true);
	m_eOperation_Attribute_eExceptions->setContainment(false);
	m_eOperation_Attribute_eExceptions->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eOperation_Attribute_eExceptions->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_eOperation_Attribute_eGenericExceptions->setName("eGenericExceptions");
	m_eOperation_Attribute_eGenericExceptions->setEType(getEGenericType_Class());
	m_eOperation_Attribute_eGenericExceptions->setLowerBound(0);
	m_eOperation_Attribute_eGenericExceptions->setUpperBound(-1);
	m_eOperation_Attribute_eGenericExceptions->setTransient(false);
	m_eOperation_Attribute_eGenericExceptions->setVolatile(false);
	m_eOperation_Attribute_eGenericExceptions->setChangeable(true);
	m_eOperation_Attribute_eGenericExceptions->setUnsettable(true);
	m_eOperation_Attribute_eGenericExceptions->setUnique(true);
	m_eOperation_Attribute_eGenericExceptions->setDerived(false);
	m_eOperation_Attribute_eGenericExceptions->setOrdered(true);
	m_eOperation_Attribute_eGenericExceptions->setContainment(true);
	m_eOperation_Attribute_eGenericExceptions->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eOperation_Attribute_eGenericExceptions->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_eOperation_Attribute_eParameters->setName("eParameters");
	m_eOperation_Attribute_eParameters->setEType(getEParameter_Class());
	m_eOperation_Attribute_eParameters->setLowerBound(0);
	m_eOperation_Attribute_eParameters->setUpperBound(-1);
	m_eOperation_Attribute_eParameters->setTransient(false);
	m_eOperation_Attribute_eParameters->setVolatile(false);
	m_eOperation_Attribute_eParameters->setChangeable(true);
	m_eOperation_Attribute_eParameters->setUnsettable(false);
	m_eOperation_Attribute_eParameters->setUnique(true);
	m_eOperation_Attribute_eParameters->setDerived(false);
	m_eOperation_Attribute_eParameters->setOrdered(true);
	m_eOperation_Attribute_eParameters->setContainment(true);
	m_eOperation_Attribute_eParameters->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eOperation_Attribute_eParameters->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ecore::ecorePackage::eInstance()->getEParameter_Attribute_eOperation();
		if (otherEnd != nullptr)
	    {
	   		m_eOperation_Attribute_eParameters->setEOpposite(otherEnd);
	    }
	}
	m_eOperation_Attribute_eTypeParameters->setName("eTypeParameters");
	m_eOperation_Attribute_eTypeParameters->setEType(getETypeParameter_Class());
	m_eOperation_Attribute_eTypeParameters->setLowerBound(0);
	m_eOperation_Attribute_eTypeParameters->setUpperBound(-1);
	m_eOperation_Attribute_eTypeParameters->setTransient(false);
	m_eOperation_Attribute_eTypeParameters->setVolatile(false);
	m_eOperation_Attribute_eTypeParameters->setChangeable(true);
	m_eOperation_Attribute_eTypeParameters->setUnsettable(false);
	m_eOperation_Attribute_eTypeParameters->setUnique(true);
	m_eOperation_Attribute_eTypeParameters->setDerived(false);
	m_eOperation_Attribute_eTypeParameters->setOrdered(true);
	m_eOperation_Attribute_eTypeParameters->setContainment(true);
	m_eOperation_Attribute_eTypeParameters->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eOperation_Attribute_eTypeParameters->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_eOperation_Operation_isOverrideOf_EOperation->setName("isOverrideOf");
	m_eOperation_Operation_isOverrideOf_EOperation->setEType(getEBoolean_Class());
	m_eOperation_Operation_isOverrideOf_EOperation->setLowerBound(0);
	m_eOperation_Operation_isOverrideOf_EOperation->setUpperBound(1);
	m_eOperation_Operation_isOverrideOf_EOperation->setUnique(true);
	m_eOperation_Operation_isOverrideOf_EOperation->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eOperation_Operation_isOverrideOf_EOperation);
		parameter->setName("someOperation");
		parameter->setEType(getEOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ecorePackageImpl::initializeEPackageContent()
{
	m_ePackage_Class->setName("EPackage");
	m_ePackage_Class->setAbstract(false);
	m_ePackage_Class->setInterface(false);
	
	m_ePackage_Attribute_nsPrefix = getEPackage_Attribute_nsPrefix();
	m_ePackage_Attribute_nsPrefix->setName("nsPrefix");
		m_ePackage_Attribute_nsPrefix->setEType(getEString_Class());
	m_ePackage_Attribute_nsPrefix->setLowerBound(0);
	m_ePackage_Attribute_nsPrefix->setUpperBound(1);
	m_ePackage_Attribute_nsPrefix->setTransient(false);
	m_ePackage_Attribute_nsPrefix->setVolatile(false);
	m_ePackage_Attribute_nsPrefix->setChangeable(true);
	m_ePackage_Attribute_nsPrefix->setUnsettable(false);
	m_ePackage_Attribute_nsPrefix->setUnique(true);
	m_ePackage_Attribute_nsPrefix->setDerived(false);
	m_ePackage_Attribute_nsPrefix->setOrdered(true);
	m_ePackage_Attribute_nsPrefix->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_ePackage_Attribute_nsPrefix->setDefaultValueLiteral(defaultValue);
		}
	}
	m_ePackage_Attribute_nsURI = getEPackage_Attribute_nsURI();
	m_ePackage_Attribute_nsURI->setName("nsURI");
		m_ePackage_Attribute_nsURI->setEType(getEString_Class());
	m_ePackage_Attribute_nsURI->setLowerBound(0);
	m_ePackage_Attribute_nsURI->setUpperBound(1);
	m_ePackage_Attribute_nsURI->setTransient(false);
	m_ePackage_Attribute_nsURI->setVolatile(false);
	m_ePackage_Attribute_nsURI->setChangeable(true);
	m_ePackage_Attribute_nsURI->setUnsettable(false);
	m_ePackage_Attribute_nsURI->setUnique(true);
	m_ePackage_Attribute_nsURI->setDerived(false);
	m_ePackage_Attribute_nsURI->setOrdered(true);
	m_ePackage_Attribute_nsURI->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_ePackage_Attribute_nsURI->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_ePackage_Attribute_eClassifiers->setName("eClassifiers");
	m_ePackage_Attribute_eClassifiers->setEType(getEClassifier_Class());
	m_ePackage_Attribute_eClassifiers->setLowerBound(0);
	m_ePackage_Attribute_eClassifiers->setUpperBound(-1);
	m_ePackage_Attribute_eClassifiers->setTransient(false);
	m_ePackage_Attribute_eClassifiers->setVolatile(false);
	m_ePackage_Attribute_eClassifiers->setChangeable(true);
	m_ePackage_Attribute_eClassifiers->setUnsettable(false);
	m_ePackage_Attribute_eClassifiers->setUnique(true);
	m_ePackage_Attribute_eClassifiers->setDerived(false);
	m_ePackage_Attribute_eClassifiers->setOrdered(true);
	m_ePackage_Attribute_eClassifiers->setContainment(true);
	m_ePackage_Attribute_eClassifiers->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_ePackage_Attribute_eClassifiers->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ecore::ecorePackage::eInstance()->getEClassifier_Attribute_ePackage();
		if (otherEnd != nullptr)
	    {
	   		m_ePackage_Attribute_eClassifiers->setEOpposite(otherEnd);
	    }
	}
	m_ePackage_Attribute_eFactoryInstance->setName("eFactoryInstance");
	m_ePackage_Attribute_eFactoryInstance->setEType(getEFactory_Class());
	m_ePackage_Attribute_eFactoryInstance->setLowerBound(1);
	m_ePackage_Attribute_eFactoryInstance->setUpperBound(1);
	m_ePackage_Attribute_eFactoryInstance->setTransient(true);
	m_ePackage_Attribute_eFactoryInstance->setVolatile(false);
	m_ePackage_Attribute_eFactoryInstance->setChangeable(true);
	m_ePackage_Attribute_eFactoryInstance->setUnsettable(false);
	m_ePackage_Attribute_eFactoryInstance->setUnique(true);
	m_ePackage_Attribute_eFactoryInstance->setDerived(false);
	m_ePackage_Attribute_eFactoryInstance->setOrdered(true);
	m_ePackage_Attribute_eFactoryInstance->setContainment(false);
	m_ePackage_Attribute_eFactoryInstance->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_ePackage_Attribute_eFactoryInstance->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ecore::ecorePackage::eInstance()->getEFactory_Attribute_ePackage();
		if (otherEnd != nullptr)
	    {
	   		m_ePackage_Attribute_eFactoryInstance->setEOpposite(otherEnd);
	    }
	}
	m_ePackage_Attribute_eSubpackages->setName("eSubpackages");
	m_ePackage_Attribute_eSubpackages->setEType(getEPackage_Class());
	m_ePackage_Attribute_eSubpackages->setLowerBound(0);
	m_ePackage_Attribute_eSubpackages->setUpperBound(-1);
	m_ePackage_Attribute_eSubpackages->setTransient(false);
	m_ePackage_Attribute_eSubpackages->setVolatile(false);
	m_ePackage_Attribute_eSubpackages->setChangeable(true);
	m_ePackage_Attribute_eSubpackages->setUnsettable(false);
	m_ePackage_Attribute_eSubpackages->setUnique(true);
	m_ePackage_Attribute_eSubpackages->setDerived(false);
	m_ePackage_Attribute_eSubpackages->setOrdered(true);
	m_ePackage_Attribute_eSubpackages->setContainment(true);
	m_ePackage_Attribute_eSubpackages->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_ePackage_Attribute_eSubpackages->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ecore::ecorePackage::eInstance()->getEPackage_Attribute_eSuperPackage();
		if (otherEnd != nullptr)
	    {
	   		m_ePackage_Attribute_eSubpackages->setEOpposite(otherEnd);
	    }
	}
	m_ePackage_Attribute_eSuperPackage->setName("eSuperPackage");
	m_ePackage_Attribute_eSuperPackage->setEType(getEPackage_Class());
	m_ePackage_Attribute_eSuperPackage->setLowerBound(0);
	m_ePackage_Attribute_eSuperPackage->setUpperBound(1);
	m_ePackage_Attribute_eSuperPackage->setTransient(true);
	m_ePackage_Attribute_eSuperPackage->setVolatile(false);
	m_ePackage_Attribute_eSuperPackage->setChangeable(false);
	m_ePackage_Attribute_eSuperPackage->setUnsettable(false);
	m_ePackage_Attribute_eSuperPackage->setUnique(true);
	m_ePackage_Attribute_eSuperPackage->setDerived(false);
	m_ePackage_Attribute_eSuperPackage->setOrdered(true);
	m_ePackage_Attribute_eSuperPackage->setContainment(false);
	m_ePackage_Attribute_eSuperPackage->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_ePackage_Attribute_eSuperPackage->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ecore::ecorePackage::eInstance()->getEPackage_Attribute_eSubpackages();
		if (otherEnd != nullptr)
	    {
	   		m_ePackage_Attribute_eSuperPackage->setEOpposite(otherEnd);
	    }
	}
	
	m_ePackage_Operation_getEClassifier_EString->setName("getEClassifier");
	m_ePackage_Operation_getEClassifier_EString->setEType(getEClassifier_Class());
	m_ePackage_Operation_getEClassifier_EString->setLowerBound(0);
	m_ePackage_Operation_getEClassifier_EString->setUpperBound(1);
	m_ePackage_Operation_getEClassifier_EString->setUnique(true);
	m_ePackage_Operation_getEClassifier_EString->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_ePackage_Operation_getEClassifier_EString);
		parameter->setName("name");
		parameter->setEType(getEString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ecorePackageImpl::initializeEParameterContent()
{
	m_eParameter_Class->setName("EParameter");
	m_eParameter_Class->setAbstract(false);
	m_eParameter_Class->setInterface(false);
	
	
	m_eParameter_Attribute_eOperation->setName("eOperation");
	m_eParameter_Attribute_eOperation->setEType(getEOperation_Class());
	m_eParameter_Attribute_eOperation->setLowerBound(0);
	m_eParameter_Attribute_eOperation->setUpperBound(1);
	m_eParameter_Attribute_eOperation->setTransient(true);
	m_eParameter_Attribute_eOperation->setVolatile(false);
	m_eParameter_Attribute_eOperation->setChangeable(false);
	m_eParameter_Attribute_eOperation->setUnsettable(false);
	m_eParameter_Attribute_eOperation->setUnique(true);
	m_eParameter_Attribute_eOperation->setDerived(false);
	m_eParameter_Attribute_eOperation->setOrdered(true);
	m_eParameter_Attribute_eOperation->setContainment(false);
	m_eParameter_Attribute_eOperation->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eParameter_Attribute_eOperation->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ecore::ecorePackage::eInstance()->getEOperation_Attribute_eParameters();
		if (otherEnd != nullptr)
	    {
	   		m_eParameter_Attribute_eOperation->setEOpposite(otherEnd);
	    }
	}
	
	
}

void ecorePackageImpl::initializeEReferenceContent()
{
	m_eReference_Class->setName("EReference");
	m_eReference_Class->setAbstract(false);
	m_eReference_Class->setInterface(false);
	
	m_eReference_Attribute_container = getEReference_Attribute_container();
	m_eReference_Attribute_container->setName("container");
		m_eReference_Attribute_container->setEType(getEBoolean_Class());
	m_eReference_Attribute_container->setLowerBound(0);
	m_eReference_Attribute_container->setUpperBound(1);
	m_eReference_Attribute_container->setTransient(true);
	m_eReference_Attribute_container->setVolatile(true);
	m_eReference_Attribute_container->setChangeable(false);
	m_eReference_Attribute_container->setUnsettable(false);
	m_eReference_Attribute_container->setUnique(true);
	m_eReference_Attribute_container->setDerived(true);
	m_eReference_Attribute_container->setOrdered(true);
	m_eReference_Attribute_container->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eReference_Attribute_container->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eReference_Attribute_containment = getEReference_Attribute_containment();
	m_eReference_Attribute_containment->setName("containment");
		m_eReference_Attribute_containment->setEType(getEBoolean_Class());
	m_eReference_Attribute_containment->setLowerBound(0);
	m_eReference_Attribute_containment->setUpperBound(1);
	m_eReference_Attribute_containment->setTransient(false);
	m_eReference_Attribute_containment->setVolatile(false);
	m_eReference_Attribute_containment->setChangeable(true);
	m_eReference_Attribute_containment->setUnsettable(false);
	m_eReference_Attribute_containment->setUnique(true);
	m_eReference_Attribute_containment->setDerived(false);
	m_eReference_Attribute_containment->setOrdered(true);
	m_eReference_Attribute_containment->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eReference_Attribute_containment->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eReference_Attribute_resolveProxies = getEReference_Attribute_resolveProxies();
	m_eReference_Attribute_resolveProxies->setName("resolveProxies");
		m_eReference_Attribute_resolveProxies->setEType(getEBoolean_Class());
	m_eReference_Attribute_resolveProxies->setLowerBound(0);
	m_eReference_Attribute_resolveProxies->setUpperBound(1);
	m_eReference_Attribute_resolveProxies->setTransient(false);
	m_eReference_Attribute_resolveProxies->setVolatile(false);
	m_eReference_Attribute_resolveProxies->setChangeable(true);
	m_eReference_Attribute_resolveProxies->setUnsettable(false);
	m_eReference_Attribute_resolveProxies->setUnique(true);
	m_eReference_Attribute_resolveProxies->setDerived(false);
	m_eReference_Attribute_resolveProxies->setOrdered(true);
	m_eReference_Attribute_resolveProxies->setID(false);
	{
		std::string defaultValue = "true";
		if (!defaultValue.empty())
		{
		   m_eReference_Attribute_resolveProxies->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_eReference_Attribute_eKeys->setName("eKeys");
	m_eReference_Attribute_eKeys->setEType(getEAttribute_Class());
	m_eReference_Attribute_eKeys->setLowerBound(0);
	m_eReference_Attribute_eKeys->setUpperBound(-1);
	m_eReference_Attribute_eKeys->setTransient(false);
	m_eReference_Attribute_eKeys->setVolatile(false);
	m_eReference_Attribute_eKeys->setChangeable(true);
	m_eReference_Attribute_eKeys->setUnsettable(false);
	m_eReference_Attribute_eKeys->setUnique(true);
	m_eReference_Attribute_eKeys->setDerived(false);
	m_eReference_Attribute_eKeys->setOrdered(true);
	m_eReference_Attribute_eKeys->setContainment(false);
	m_eReference_Attribute_eKeys->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eReference_Attribute_eKeys->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_eReference_Attribute_eOpposite->setName("eOpposite");
	m_eReference_Attribute_eOpposite->setEType(getEReference_Class());
	m_eReference_Attribute_eOpposite->setLowerBound(0);
	m_eReference_Attribute_eOpposite->setUpperBound(1);
	m_eReference_Attribute_eOpposite->setTransient(false);
	m_eReference_Attribute_eOpposite->setVolatile(false);
	m_eReference_Attribute_eOpposite->setChangeable(true);
	m_eReference_Attribute_eOpposite->setUnsettable(false);
	m_eReference_Attribute_eOpposite->setUnique(true);
	m_eReference_Attribute_eOpposite->setDerived(false);
	m_eReference_Attribute_eOpposite->setOrdered(true);
	m_eReference_Attribute_eOpposite->setContainment(false);
	m_eReference_Attribute_eOpposite->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eReference_Attribute_eOpposite->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_eReference_Attribute_eReferenceType->setName("eReferenceType");
	m_eReference_Attribute_eReferenceType->setEType(getEClass_Class());
	m_eReference_Attribute_eReferenceType->setLowerBound(1);
	m_eReference_Attribute_eReferenceType->setUpperBound(1);
	m_eReference_Attribute_eReferenceType->setTransient(true);
	m_eReference_Attribute_eReferenceType->setVolatile(true);
	m_eReference_Attribute_eReferenceType->setChangeable(true);
	m_eReference_Attribute_eReferenceType->setUnsettable(false);
	m_eReference_Attribute_eReferenceType->setUnique(true);
	m_eReference_Attribute_eReferenceType->setDerived(true);
	m_eReference_Attribute_eReferenceType->setOrdered(true);
	m_eReference_Attribute_eReferenceType->setContainment(false);
	m_eReference_Attribute_eReferenceType->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eReference_Attribute_eReferenceType->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	
}

void ecorePackageImpl::initializeEStringToStringMapEntryContent()
{
	m_eStringToStringMapEntry_Class->setName("EStringToStringMapEntry");
	m_eStringToStringMapEntry_Class->setAbstract(false);
	m_eStringToStringMapEntry_Class->setInterface(false);
	
	m_eStringToStringMapEntry_Attribute_key = getEStringToStringMapEntry_Attribute_key();
	m_eStringToStringMapEntry_Attribute_key->setName("key");
		m_eStringToStringMapEntry_Attribute_key->setEType(getEString_Class());
	m_eStringToStringMapEntry_Attribute_key->setLowerBound(0);
	m_eStringToStringMapEntry_Attribute_key->setUpperBound(1);
	m_eStringToStringMapEntry_Attribute_key->setTransient(false);
	m_eStringToStringMapEntry_Attribute_key->setVolatile(false);
	m_eStringToStringMapEntry_Attribute_key->setChangeable(true);
	m_eStringToStringMapEntry_Attribute_key->setUnsettable(false);
	m_eStringToStringMapEntry_Attribute_key->setUnique(true);
	m_eStringToStringMapEntry_Attribute_key->setDerived(false);
	m_eStringToStringMapEntry_Attribute_key->setOrdered(true);
	m_eStringToStringMapEntry_Attribute_key->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eStringToStringMapEntry_Attribute_key->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eStringToStringMapEntry_Attribute_value = getEStringToStringMapEntry_Attribute_value();
	m_eStringToStringMapEntry_Attribute_value->setName("value");
		m_eStringToStringMapEntry_Attribute_value->setEType(getEString_Class());
	m_eStringToStringMapEntry_Attribute_value->setLowerBound(0);
	m_eStringToStringMapEntry_Attribute_value->setUpperBound(1);
	m_eStringToStringMapEntry_Attribute_value->setTransient(false);
	m_eStringToStringMapEntry_Attribute_value->setVolatile(false);
	m_eStringToStringMapEntry_Attribute_value->setChangeable(true);
	m_eStringToStringMapEntry_Attribute_value->setUnsettable(false);
	m_eStringToStringMapEntry_Attribute_value->setUnique(true);
	m_eStringToStringMapEntry_Attribute_value->setDerived(false);
	m_eStringToStringMapEntry_Attribute_value->setOrdered(true);
	m_eStringToStringMapEntry_Attribute_value->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eStringToStringMapEntry_Attribute_value->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	
}

void ecorePackageImpl::initializeEStructuralFeatureContent()
{
	m_eStructuralFeature_Class->setName("EStructuralFeature");
	m_eStructuralFeature_Class->setAbstract(true);
	m_eStructuralFeature_Class->setInterface(false);
	
	m_eStructuralFeature_Attribute_changeable = getEStructuralFeature_Attribute_changeable();
	m_eStructuralFeature_Attribute_changeable->setName("changeable");
		m_eStructuralFeature_Attribute_changeable->setEType(getEBoolean_Class());
	m_eStructuralFeature_Attribute_changeable->setLowerBound(0);
	m_eStructuralFeature_Attribute_changeable->setUpperBound(1);
	m_eStructuralFeature_Attribute_changeable->setTransient(false);
	m_eStructuralFeature_Attribute_changeable->setVolatile(false);
	m_eStructuralFeature_Attribute_changeable->setChangeable(true);
	m_eStructuralFeature_Attribute_changeable->setUnsettable(false);
	m_eStructuralFeature_Attribute_changeable->setUnique(true);
	m_eStructuralFeature_Attribute_changeable->setDerived(false);
	m_eStructuralFeature_Attribute_changeable->setOrdered(true);
	m_eStructuralFeature_Attribute_changeable->setID(false);
	{
		std::string defaultValue = "true";
		if (!defaultValue.empty())
		{
		   m_eStructuralFeature_Attribute_changeable->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eStructuralFeature_Attribute_defaultValue = getEStructuralFeature_Attribute_defaultValue();
	m_eStructuralFeature_Attribute_defaultValue->setName("defaultValue");
		m_eStructuralFeature_Attribute_defaultValue->setEType(getEJavaObject_Class());
	m_eStructuralFeature_Attribute_defaultValue->setLowerBound(0);
	m_eStructuralFeature_Attribute_defaultValue->setUpperBound(1);
	m_eStructuralFeature_Attribute_defaultValue->setTransient(true);
	m_eStructuralFeature_Attribute_defaultValue->setVolatile(true);
	m_eStructuralFeature_Attribute_defaultValue->setChangeable(true);
	m_eStructuralFeature_Attribute_defaultValue->setUnsettable(false);
	m_eStructuralFeature_Attribute_defaultValue->setUnique(true);
	m_eStructuralFeature_Attribute_defaultValue->setDerived(true);
	m_eStructuralFeature_Attribute_defaultValue->setOrdered(true);
	m_eStructuralFeature_Attribute_defaultValue->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eStructuralFeature_Attribute_defaultValue->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eStructuralFeature_Attribute_defaultValueLiteral = getEStructuralFeature_Attribute_defaultValueLiteral();
	m_eStructuralFeature_Attribute_defaultValueLiteral->setName("defaultValueLiteral");
		m_eStructuralFeature_Attribute_defaultValueLiteral->setEType(getEString_Class());
	m_eStructuralFeature_Attribute_defaultValueLiteral->setLowerBound(0);
	m_eStructuralFeature_Attribute_defaultValueLiteral->setUpperBound(1);
	m_eStructuralFeature_Attribute_defaultValueLiteral->setTransient(false);
	m_eStructuralFeature_Attribute_defaultValueLiteral->setVolatile(false);
	m_eStructuralFeature_Attribute_defaultValueLiteral->setChangeable(true);
	m_eStructuralFeature_Attribute_defaultValueLiteral->setUnsettable(false);
	m_eStructuralFeature_Attribute_defaultValueLiteral->setUnique(true);
	m_eStructuralFeature_Attribute_defaultValueLiteral->setDerived(false);
	m_eStructuralFeature_Attribute_defaultValueLiteral->setOrdered(true);
	m_eStructuralFeature_Attribute_defaultValueLiteral->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eStructuralFeature_Attribute_defaultValueLiteral->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eStructuralFeature_Attribute_derived = getEStructuralFeature_Attribute_derived();
	m_eStructuralFeature_Attribute_derived->setName("derived");
		m_eStructuralFeature_Attribute_derived->setEType(getEBoolean_Class());
	m_eStructuralFeature_Attribute_derived->setLowerBound(0);
	m_eStructuralFeature_Attribute_derived->setUpperBound(1);
	m_eStructuralFeature_Attribute_derived->setTransient(false);
	m_eStructuralFeature_Attribute_derived->setVolatile(false);
	m_eStructuralFeature_Attribute_derived->setChangeable(true);
	m_eStructuralFeature_Attribute_derived->setUnsettable(false);
	m_eStructuralFeature_Attribute_derived->setUnique(true);
	m_eStructuralFeature_Attribute_derived->setDerived(false);
	m_eStructuralFeature_Attribute_derived->setOrdered(true);
	m_eStructuralFeature_Attribute_derived->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eStructuralFeature_Attribute_derived->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eStructuralFeature_Attribute_featureID = getEStructuralFeature_Attribute_featureID();
	m_eStructuralFeature_Attribute_featureID->setName("featureID");
		m_eStructuralFeature_Attribute_featureID->setEType(getEInt_Class());
	m_eStructuralFeature_Attribute_featureID->setLowerBound(0);
	m_eStructuralFeature_Attribute_featureID->setUpperBound(1);
	m_eStructuralFeature_Attribute_featureID->setTransient(false);
	m_eStructuralFeature_Attribute_featureID->setVolatile(false);
	m_eStructuralFeature_Attribute_featureID->setChangeable(false);
	m_eStructuralFeature_Attribute_featureID->setUnsettable(false);
	m_eStructuralFeature_Attribute_featureID->setUnique(true);
	m_eStructuralFeature_Attribute_featureID->setDerived(false);
	m_eStructuralFeature_Attribute_featureID->setOrdered(true);
	m_eStructuralFeature_Attribute_featureID->setID(false);
	{
		std::string defaultValue = "-1";
		if (!defaultValue.empty())
		{
		   m_eStructuralFeature_Attribute_featureID->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eStructuralFeature_Attribute_transient = getEStructuralFeature_Attribute_transient();
	m_eStructuralFeature_Attribute_transient->setName("transient");
		m_eStructuralFeature_Attribute_transient->setEType(getEBoolean_Class());
	m_eStructuralFeature_Attribute_transient->setLowerBound(0);
	m_eStructuralFeature_Attribute_transient->setUpperBound(1);
	m_eStructuralFeature_Attribute_transient->setTransient(false);
	m_eStructuralFeature_Attribute_transient->setVolatile(false);
	m_eStructuralFeature_Attribute_transient->setChangeable(true);
	m_eStructuralFeature_Attribute_transient->setUnsettable(false);
	m_eStructuralFeature_Attribute_transient->setUnique(true);
	m_eStructuralFeature_Attribute_transient->setDerived(false);
	m_eStructuralFeature_Attribute_transient->setOrdered(true);
	m_eStructuralFeature_Attribute_transient->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eStructuralFeature_Attribute_transient->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eStructuralFeature_Attribute_unsettable = getEStructuralFeature_Attribute_unsettable();
	m_eStructuralFeature_Attribute_unsettable->setName("unsettable");
		m_eStructuralFeature_Attribute_unsettable->setEType(getEBoolean_Class());
	m_eStructuralFeature_Attribute_unsettable->setLowerBound(0);
	m_eStructuralFeature_Attribute_unsettable->setUpperBound(1);
	m_eStructuralFeature_Attribute_unsettable->setTransient(false);
	m_eStructuralFeature_Attribute_unsettable->setVolatile(false);
	m_eStructuralFeature_Attribute_unsettable->setChangeable(true);
	m_eStructuralFeature_Attribute_unsettable->setUnsettable(false);
	m_eStructuralFeature_Attribute_unsettable->setUnique(true);
	m_eStructuralFeature_Attribute_unsettable->setDerived(false);
	m_eStructuralFeature_Attribute_unsettable->setOrdered(true);
	m_eStructuralFeature_Attribute_unsettable->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eStructuralFeature_Attribute_unsettable->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eStructuralFeature_Attribute_volatile = getEStructuralFeature_Attribute_volatile();
	m_eStructuralFeature_Attribute_volatile->setName("volatile");
		m_eStructuralFeature_Attribute_volatile->setEType(getEBoolean_Class());
	m_eStructuralFeature_Attribute_volatile->setLowerBound(0);
	m_eStructuralFeature_Attribute_volatile->setUpperBound(1);
	m_eStructuralFeature_Attribute_volatile->setTransient(false);
	m_eStructuralFeature_Attribute_volatile->setVolatile(false);
	m_eStructuralFeature_Attribute_volatile->setChangeable(true);
	m_eStructuralFeature_Attribute_volatile->setUnsettable(false);
	m_eStructuralFeature_Attribute_volatile->setUnique(true);
	m_eStructuralFeature_Attribute_volatile->setDerived(false);
	m_eStructuralFeature_Attribute_volatile->setOrdered(true);
	m_eStructuralFeature_Attribute_volatile->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eStructuralFeature_Attribute_volatile->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_eStructuralFeature_Attribute_eContainingClass->setName("eContainingClass");
	m_eStructuralFeature_Attribute_eContainingClass->setEType(getEClass_Class());
	m_eStructuralFeature_Attribute_eContainingClass->setLowerBound(0);
	m_eStructuralFeature_Attribute_eContainingClass->setUpperBound(1);
	m_eStructuralFeature_Attribute_eContainingClass->setTransient(true);
	m_eStructuralFeature_Attribute_eContainingClass->setVolatile(false);
	m_eStructuralFeature_Attribute_eContainingClass->setChangeable(false);
	m_eStructuralFeature_Attribute_eContainingClass->setUnsettable(false);
	m_eStructuralFeature_Attribute_eContainingClass->setUnique(true);
	m_eStructuralFeature_Attribute_eContainingClass->setDerived(false);
	m_eStructuralFeature_Attribute_eContainingClass->setOrdered(true);
	m_eStructuralFeature_Attribute_eContainingClass->setContainment(false);
	m_eStructuralFeature_Attribute_eContainingClass->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eStructuralFeature_Attribute_eContainingClass->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ecore::ecorePackage::eInstance()->getEClass_Attribute_eStructuralFeatures();
		if (otherEnd != nullptr)
	    {
	   		m_eStructuralFeature_Attribute_eContainingClass->setEOpposite(otherEnd);
	    }
	}
	
	m_eStructuralFeature_Operation_getContainerClass->setName("getContainerClass");
	m_eStructuralFeature_Operation_getContainerClass->setEType(getEJavaClass_Class());
	m_eStructuralFeature_Operation_getContainerClass->setLowerBound(0);
	m_eStructuralFeature_Operation_getContainerClass->setUpperBound(1);
	m_eStructuralFeature_Operation_getContainerClass->setUnique(true);
	m_eStructuralFeature_Operation_getContainerClass->setOrdered(true);
	
	
}

void ecorePackageImpl::initializeETypeParameterContent()
{
	m_eTypeParameter_Class->setName("ETypeParameter");
	m_eTypeParameter_Class->setAbstract(false);
	m_eTypeParameter_Class->setInterface(false);
	
	
	m_eTypeParameter_Attribute_eBounds->setName("eBounds");
	m_eTypeParameter_Attribute_eBounds->setEType(getEGenericType_Class());
	m_eTypeParameter_Attribute_eBounds->setLowerBound(0);
	m_eTypeParameter_Attribute_eBounds->setUpperBound(-1);
	m_eTypeParameter_Attribute_eBounds->setTransient(false);
	m_eTypeParameter_Attribute_eBounds->setVolatile(false);
	m_eTypeParameter_Attribute_eBounds->setChangeable(true);
	m_eTypeParameter_Attribute_eBounds->setUnsettable(false);
	m_eTypeParameter_Attribute_eBounds->setUnique(true);
	m_eTypeParameter_Attribute_eBounds->setDerived(false);
	m_eTypeParameter_Attribute_eBounds->setOrdered(true);
	m_eTypeParameter_Attribute_eBounds->setContainment(true);
	m_eTypeParameter_Attribute_eBounds->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eTypeParameter_Attribute_eBounds->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	
}

void ecorePackageImpl::initializeETypedElementContent()
{
	m_eTypedElement_Class->setName("ETypedElement");
	m_eTypedElement_Class->setAbstract(true);
	m_eTypedElement_Class->setInterface(false);
	
	m_eTypedElement_Attribute_lowerBound = getETypedElement_Attribute_lowerBound();
	m_eTypedElement_Attribute_lowerBound->setName("lowerBound");
		m_eTypedElement_Attribute_lowerBound->setEType(getEInt_Class());
	m_eTypedElement_Attribute_lowerBound->setLowerBound(0);
	m_eTypedElement_Attribute_lowerBound->setUpperBound(1);
	m_eTypedElement_Attribute_lowerBound->setTransient(false);
	m_eTypedElement_Attribute_lowerBound->setVolatile(false);
	m_eTypedElement_Attribute_lowerBound->setChangeable(true);
	m_eTypedElement_Attribute_lowerBound->setUnsettable(false);
	m_eTypedElement_Attribute_lowerBound->setUnique(true);
	m_eTypedElement_Attribute_lowerBound->setDerived(false);
	m_eTypedElement_Attribute_lowerBound->setOrdered(true);
	m_eTypedElement_Attribute_lowerBound->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eTypedElement_Attribute_lowerBound->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eTypedElement_Attribute_many = getETypedElement_Attribute_many();
	m_eTypedElement_Attribute_many->setName("many");
		m_eTypedElement_Attribute_many->setEType(getEBoolean_Class());
	m_eTypedElement_Attribute_many->setLowerBound(0);
	m_eTypedElement_Attribute_many->setUpperBound(1);
	m_eTypedElement_Attribute_many->setTransient(true);
	m_eTypedElement_Attribute_many->setVolatile(true);
	m_eTypedElement_Attribute_many->setChangeable(false);
	m_eTypedElement_Attribute_many->setUnsettable(false);
	m_eTypedElement_Attribute_many->setUnique(true);
	m_eTypedElement_Attribute_many->setDerived(true);
	m_eTypedElement_Attribute_many->setOrdered(true);
	m_eTypedElement_Attribute_many->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eTypedElement_Attribute_many->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eTypedElement_Attribute_ordered = getETypedElement_Attribute_ordered();
	m_eTypedElement_Attribute_ordered->setName("ordered");
		m_eTypedElement_Attribute_ordered->setEType(getEBoolean_Class());
	m_eTypedElement_Attribute_ordered->setLowerBound(0);
	m_eTypedElement_Attribute_ordered->setUpperBound(1);
	m_eTypedElement_Attribute_ordered->setTransient(false);
	m_eTypedElement_Attribute_ordered->setVolatile(false);
	m_eTypedElement_Attribute_ordered->setChangeable(true);
	m_eTypedElement_Attribute_ordered->setUnsettable(false);
	m_eTypedElement_Attribute_ordered->setUnique(true);
	m_eTypedElement_Attribute_ordered->setDerived(false);
	m_eTypedElement_Attribute_ordered->setOrdered(true);
	m_eTypedElement_Attribute_ordered->setID(false);
	{
		std::string defaultValue = "true";
		if (!defaultValue.empty())
		{
		   m_eTypedElement_Attribute_ordered->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eTypedElement_Attribute_required = getETypedElement_Attribute_required();
	m_eTypedElement_Attribute_required->setName("required");
		m_eTypedElement_Attribute_required->setEType(getEBoolean_Class());
	m_eTypedElement_Attribute_required->setLowerBound(0);
	m_eTypedElement_Attribute_required->setUpperBound(1);
	m_eTypedElement_Attribute_required->setTransient(true);
	m_eTypedElement_Attribute_required->setVolatile(true);
	m_eTypedElement_Attribute_required->setChangeable(true);
	m_eTypedElement_Attribute_required->setUnsettable(false);
	m_eTypedElement_Attribute_required->setUnique(true);
	m_eTypedElement_Attribute_required->setDerived(true);
	m_eTypedElement_Attribute_required->setOrdered(true);
	m_eTypedElement_Attribute_required->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eTypedElement_Attribute_required->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eTypedElement_Attribute_unique = getETypedElement_Attribute_unique();
	m_eTypedElement_Attribute_unique->setName("unique");
		m_eTypedElement_Attribute_unique->setEType(getEBoolean_Class());
	m_eTypedElement_Attribute_unique->setLowerBound(0);
	m_eTypedElement_Attribute_unique->setUpperBound(1);
	m_eTypedElement_Attribute_unique->setTransient(false);
	m_eTypedElement_Attribute_unique->setVolatile(false);
	m_eTypedElement_Attribute_unique->setChangeable(true);
	m_eTypedElement_Attribute_unique->setUnsettable(false);
	m_eTypedElement_Attribute_unique->setUnique(true);
	m_eTypedElement_Attribute_unique->setDerived(false);
	m_eTypedElement_Attribute_unique->setOrdered(true);
	m_eTypedElement_Attribute_unique->setID(false);
	{
		std::string defaultValue = "true";
		if (!defaultValue.empty())
		{
		   m_eTypedElement_Attribute_unique->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eTypedElement_Attribute_upperBound = getETypedElement_Attribute_upperBound();
	m_eTypedElement_Attribute_upperBound->setName("upperBound");
		m_eTypedElement_Attribute_upperBound->setEType(getEInt_Class());
	m_eTypedElement_Attribute_upperBound->setLowerBound(0);
	m_eTypedElement_Attribute_upperBound->setUpperBound(1);
	m_eTypedElement_Attribute_upperBound->setTransient(false);
	m_eTypedElement_Attribute_upperBound->setVolatile(false);
	m_eTypedElement_Attribute_upperBound->setChangeable(true);
	m_eTypedElement_Attribute_upperBound->setUnsettable(false);
	m_eTypedElement_Attribute_upperBound->setUnique(true);
	m_eTypedElement_Attribute_upperBound->setDerived(false);
	m_eTypedElement_Attribute_upperBound->setOrdered(true);
	m_eTypedElement_Attribute_upperBound->setID(false);
	{
		std::string defaultValue = "1";
		if (!defaultValue.empty())
		{
		   m_eTypedElement_Attribute_upperBound->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_eTypedElement_Attribute_eGenericType->setName("eGenericType");
	m_eTypedElement_Attribute_eGenericType->setEType(getEGenericType_Class());
	m_eTypedElement_Attribute_eGenericType->setLowerBound(0);
	m_eTypedElement_Attribute_eGenericType->setUpperBound(1);
	m_eTypedElement_Attribute_eGenericType->setTransient(false);
	m_eTypedElement_Attribute_eGenericType->setVolatile(true);
	m_eTypedElement_Attribute_eGenericType->setChangeable(true);
	m_eTypedElement_Attribute_eGenericType->setUnsettable(true);
	m_eTypedElement_Attribute_eGenericType->setUnique(true);
	m_eTypedElement_Attribute_eGenericType->setDerived(false);
	m_eTypedElement_Attribute_eGenericType->setOrdered(true);
	m_eTypedElement_Attribute_eGenericType->setContainment(true);
	m_eTypedElement_Attribute_eGenericType->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eTypedElement_Attribute_eGenericType->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_eTypedElement_Attribute_eType->setName("eType");
	m_eTypedElement_Attribute_eType->setEType(getEClassifier_Class());
	m_eTypedElement_Attribute_eType->setLowerBound(0);
	m_eTypedElement_Attribute_eType->setUpperBound(1);
	m_eTypedElement_Attribute_eType->setTransient(false);
	m_eTypedElement_Attribute_eType->setVolatile(true);
	m_eTypedElement_Attribute_eType->setChangeable(true);
	m_eTypedElement_Attribute_eType->setUnsettable(true);
	m_eTypedElement_Attribute_eType->setUnique(true);
	m_eTypedElement_Attribute_eType->setDerived(false);
	m_eTypedElement_Attribute_eType->setOrdered(true);
	m_eTypedElement_Attribute_eType->setContainment(false);
	m_eTypedElement_Attribute_eType->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eTypedElement_Attribute_eType->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	
}

void ecorePackageImpl::initializePackageEDataTypes()
{
	m_any_Class->setName("Any");
	m_any_Class->setSerializable(true);
	m_eBigDecimal_Class->setName("EBigDecimal");
	m_eBigDecimal_Class->setSerializable(true);
	m_eBigInteger_Class->setName("EBigInteger");
	m_eBigInteger_Class->setSerializable(true);
	m_eBoolean_Class->setName("EBoolean");
	m_eBoolean_Class->setSerializable(true);
	m_eBooleanObject_Class->setName("EBooleanObject");
	m_eBooleanObject_Class->setSerializable(true);
	m_eByte_Class->setName("EByte");
	m_eByte_Class->setSerializable(true);
	m_eByteArray_Class->setName("EByteArray");
	m_eByteArray_Class->setSerializable(true);
	m_eByteObject_Class->setName("EByteObject");
	m_eByteObject_Class->setSerializable(true);
	m_eChar_Class->setName("EChar");
	m_eChar_Class->setSerializable(true);
	m_eCharacterObject_Class->setName("ECharacterObject");
	m_eCharacterObject_Class->setSerializable(true);
	m_eDate_Class->setName("EDate");
	m_eDate_Class->setSerializable(true);
	m_eDiagnosticChain_Class->setName("EDiagnosticChain");
	m_eDiagnosticChain_Class->setSerializable(false);
	m_eDouble_Class->setName("EDouble");
	m_eDouble_Class->setSerializable(true);
	m_eDoubleObject_Class->setName("EDoubleObject");
	m_eDoubleObject_Class->setSerializable(true);
	m_eEList_Class->setName("EEList");
	m_eEList_Class->setSerializable(false);
	m_eEnumerator_Class->setName("EEnumerator");
	m_eEnumerator_Class->setSerializable(false);
	m_eFeatureMap_Class->setName("EFeatureMap");
	m_eFeatureMap_Class->setSerializable(false);
	m_eFeatureMapEntry_Class->setName("EFeatureMapEntry");
	m_eFeatureMapEntry_Class->setSerializable(false);
	m_eFloat_Class->setName("EFloat");
	m_eFloat_Class->setSerializable(true);
	m_eFloatObject_Class->setName("EFloatObject");
	m_eFloatObject_Class->setSerializable(true);
	m_eInt_Class->setName("EInt");
	m_eInt_Class->setSerializable(true);
	m_eIntegerObject_Class->setName("EIntegerObject");
	m_eIntegerObject_Class->setSerializable(true);
	m_eInvocationTargetException_Class->setName("EInvocationTargetException");
	m_eInvocationTargetException_Class->setSerializable(false);
	m_eJavaClass_Class->setName("EJavaClass");
	m_eJavaClass_Class->setSerializable(true);
	m_eJavaObject_Class->setName("EJavaObject");
	m_eJavaObject_Class->setSerializable(true);
	m_eLong_Class->setName("ELong");
	m_eLong_Class->setSerializable(true);
	m_eLongObject_Class->setName("ELongObject");
	m_eLongObject_Class->setSerializable(true);
	m_eMap_Class->setName("EMap");
	m_eMap_Class->setSerializable(false);
	m_eResource_Class->setName("EResource");
	m_eResource_Class->setSerializable(false);
	m_eResourceSet_Class->setName("EResourceSet");
	m_eResourceSet_Class->setSerializable(false);
	m_eShort_Class->setName("EShort");
	m_eShort_Class->setSerializable(true);
	m_eShortObject_Class->setName("EShortObject");
	m_eShortObject_Class->setSerializable(true);
	m_eString_Class->setName("EString");
	m_eString_Class->setSerializable(true);
	m_eTreeIterator_Class->setName("ETreeIterator");
	m_eTreeIterator_Class->setSerializable(false);
	
}

