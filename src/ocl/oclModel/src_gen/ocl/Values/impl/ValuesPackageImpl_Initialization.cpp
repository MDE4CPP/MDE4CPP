#include "ocl/Values/impl/ValuesPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAnnotation.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "ocl/Types/TypesPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "ocl/oclPackage.hpp"
#include "types/typesPackage.hpp"


using namespace ocl::Values;

void ValuesPackageImpl::initializePackageContents()
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
	m_anyValue_Class->getESuperTypes()->push_back(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_bagTypeValue_Class->getESuperTypes()->push_back(getCollectionValue_Class());
	m_collectionValue_Class->getESuperTypes()->push_back(getStaticValue_Class());
	m_objectValue_Class->getESuperTypes()->push_back(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_oclMessageValue_Class->getESuperTypes()->push_back(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_oclVoidValue_Class->getESuperTypes()->push_back(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_orderedSetTypeValue_Class->getESuperTypes()->push_back(getCollectionValue_Class());
	m_sequenceTypeValue_Class->getESuperTypes()->push_back(getCollectionValue_Class());
	m_setTypeValue_Class->getESuperTypes()->push_back(getCollectionValue_Class());
	m_staticValue_Class->getESuperTypes()->push_back(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_tupleValue_Class->getESuperTypes()->push_back(getStaticValue_Class());
	m_undefinedValue_Class->getESuperTypes()->push_back(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeAnyValueContent();
	initializeBagTypeValueContent();
	initializeCollectionValueContent();
	initializeElementContent();
	initializeLocalSnapshotContent();
	initializeNameValueBindingContent();
	initializeObjectValueContent();
	initializeOclMessageValueContent();
	initializeOclVoidValueContent();
	initializeOrderedSetTypeValueContent();
	initializeSequenceTypeValueContent();
	initializeSetTypeValueContent();
	initializeStaticValueContent();
	initializeTupleValueContent();
	initializeUndefinedValueContent();

	initializePackageEDataTypes();

}

void ValuesPackageImpl::initializeAnyValueContent()
{
	m_anyValue_Class->setName("AnyValue");
	m_anyValue_Class->setAbstract(false);
	m_anyValue_Class->setInterface(false);
	
	m_anyValue_Attribute_value = getAnyValue_Attribute_value();
	m_anyValue_Attribute_value->setName("value");
		m_anyValue_Attribute_value->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_anyValue_Attribute_value->setLowerBound(0);
	m_anyValue_Attribute_value->setUpperBound(1);
	m_anyValue_Attribute_value->setTransient(false);
	m_anyValue_Attribute_value->setVolatile(false);
	m_anyValue_Attribute_value->setChangeable(true);
	m_anyValue_Attribute_value->setUnsettable(false);
	m_anyValue_Attribute_value->setUnique(true);
	m_anyValue_Attribute_value->setDerived(false);
	m_anyValue_Attribute_value->setOrdered(true);
	m_anyValue_Attribute_value->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_anyValue_Attribute_value->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	m_anyValue_Operation_toString->setName("toString");
	m_anyValue_Operation_toString->setEType(types::typesPackage::eInstance()->getString_Class());
	m_anyValue_Operation_toString->setLowerBound(1);
	m_anyValue_Operation_toString->setUpperBound(1);
	m_anyValue_Operation_toString->setUnique(true);
	m_anyValue_Operation_toString->setOrdered(false);
	
	
}

void ValuesPackageImpl::initializeBagTypeValueContent()
{
	m_bagTypeValue_Class->setName("BagTypeValue");
	m_bagTypeValue_Class->setAbstract(false);
	m_bagTypeValue_Class->setInterface(false);
	
	
	
	m_bagTypeValue_Operation_addValue_Value->setName("addValue");
	m_bagTypeValue_Operation_addValue_Value->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_bagTypeValue_Operation_addValue_Value->setLowerBound(0);
	m_bagTypeValue_Operation_addValue_Value->setUpperBound(1);
	m_bagTypeValue_Operation_addValue_Value->setUnique(true);
	m_bagTypeValue_Operation_addValue_Value->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_bagTypeValue_Operation_addValue_Value);
		parameter->setName("value");
		parameter->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ValuesPackageImpl::initializeCollectionValueContent()
{
	m_collectionValue_Class->setName("CollectionValue");
	m_collectionValue_Class->setAbstract(false);
	m_collectionValue_Class->setInterface(false);
	
	
	m_collectionValue_Attribute_elements->setName("elements");
	m_collectionValue_Attribute_elements->setEType(getElement_Class());
	m_collectionValue_Attribute_elements->setLowerBound(0);
	m_collectionValue_Attribute_elements->setUpperBound(-1);
	m_collectionValue_Attribute_elements->setTransient(false);
	m_collectionValue_Attribute_elements->setVolatile(false);
	m_collectionValue_Attribute_elements->setChangeable(true);
	m_collectionValue_Attribute_elements->setUnsettable(false);
	m_collectionValue_Attribute_elements->setUnique(true);
	m_collectionValue_Attribute_elements->setDerived(false);
	m_collectionValue_Attribute_elements->setOrdered(false);
	m_collectionValue_Attribute_elements->setContainment(false);
	m_collectionValue_Attribute_elements->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_collectionValue_Attribute_elements->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_collectionValue_Operation_addValue_Value->setName("addValue");
	m_collectionValue_Operation_addValue_Value->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_collectionValue_Operation_addValue_Value->setLowerBound(0);
	m_collectionValue_Operation_addValue_Value->setUpperBound(1);
	m_collectionValue_Operation_addValue_Value->setUnique(true);
	m_collectionValue_Operation_addValue_Value->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_collectionValue_Operation_addValue_Value);
		parameter->setName("value");
		parameter->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_collectionValue_Operation_equals_Value->setName("equals");
	m_collectionValue_Operation_equals_Value->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_collectionValue_Operation_equals_Value->setLowerBound(1);
	m_collectionValue_Operation_equals_Value->setUpperBound(1);
	m_collectionValue_Operation_equals_Value->setUnique(true);
	m_collectionValue_Operation_equals_Value->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_collectionValue_Operation_equals_Value);
		parameter->setName("otherValue");
		parameter->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_collectionValue_Operation_find_Value->setName("find");
	m_collectionValue_Operation_find_Value->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_collectionValue_Operation_find_Value->setLowerBound(1);
	m_collectionValue_Operation_find_Value->setUpperBound(1);
	m_collectionValue_Operation_find_Value->setUnique(true);
	m_collectionValue_Operation_find_Value->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_collectionValue_Operation_find_Value);
		parameter->setName("value");
		parameter->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_collectionValue_Operation_toString->setName("toString");
	m_collectionValue_Operation_toString->setEType(types::typesPackage::eInstance()->getString_Class());
	m_collectionValue_Operation_toString->setLowerBound(1);
	m_collectionValue_Operation_toString->setUpperBound(1);
	m_collectionValue_Operation_toString->setUnique(true);
	m_collectionValue_Operation_toString->setOrdered(false);
	
	
}

void ValuesPackageImpl::initializeElementContent()
{
	m_element_Class->setName("Element");
	m_element_Class->setAbstract(false);
	m_element_Class->setInterface(false);
	
	m_element_Attribute_indexNr = getElement_Attribute_indexNr();
	m_element_Attribute_indexNr->setName("indexNr");
		m_element_Attribute_indexNr->setEType(types::typesPackage::eInstance()->getInteger_Class());
	m_element_Attribute_indexNr->setLowerBound(0);
	m_element_Attribute_indexNr->setUpperBound(1);
	m_element_Attribute_indexNr->setTransient(false);
	m_element_Attribute_indexNr->setVolatile(false);
	m_element_Attribute_indexNr->setChangeable(true);
	m_element_Attribute_indexNr->setUnsettable(false);
	m_element_Attribute_indexNr->setUnique(true);
	m_element_Attribute_indexNr->setDerived(false);
	m_element_Attribute_indexNr->setOrdered(true);
	m_element_Attribute_indexNr->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_element_Attribute_indexNr->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_element_Attribute_value->setName("value");
	m_element_Attribute_value->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_element_Attribute_value->setLowerBound(0);
	m_element_Attribute_value->setUpperBound(1);
	m_element_Attribute_value->setTransient(false);
	m_element_Attribute_value->setVolatile(false);
	m_element_Attribute_value->setChangeable(true);
	m_element_Attribute_value->setUnsettable(false);
	m_element_Attribute_value->setUnique(true);
	m_element_Attribute_value->setDerived(false);
	m_element_Attribute_value->setOrdered(true);
	m_element_Attribute_value->setContainment(false);
	m_element_Attribute_value->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_element_Attribute_value->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	
}

void ValuesPackageImpl::initializeLocalSnapshotContent()
{
	m_localSnapshot_Class->setName("LocalSnapshot");
	m_localSnapshot_Class->setAbstract(false);
	m_localSnapshot_Class->setInterface(false);
	
	m_localSnapshot_Attribute_isPost = getLocalSnapshot_Attribute_isPost();
	m_localSnapshot_Attribute_isPost->setName("isPost");
		m_localSnapshot_Attribute_isPost->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_localSnapshot_Attribute_isPost->setLowerBound(0);
	m_localSnapshot_Attribute_isPost->setUpperBound(1);
	m_localSnapshot_Attribute_isPost->setTransient(false);
	m_localSnapshot_Attribute_isPost->setVolatile(false);
	m_localSnapshot_Attribute_isPost->setChangeable(true);
	m_localSnapshot_Attribute_isPost->setUnsettable(false);
	m_localSnapshot_Attribute_isPost->setUnique(true);
	m_localSnapshot_Attribute_isPost->setDerived(false);
	m_localSnapshot_Attribute_isPost->setOrdered(true);
	m_localSnapshot_Attribute_isPost->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_localSnapshot_Attribute_isPost->setDefaultValueLiteral(defaultValue);
		}
	}
	m_localSnapshot_Attribute_isPre = getLocalSnapshot_Attribute_isPre();
	m_localSnapshot_Attribute_isPre->setName("isPre");
		m_localSnapshot_Attribute_isPre->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_localSnapshot_Attribute_isPre->setLowerBound(0);
	m_localSnapshot_Attribute_isPre->setUpperBound(1);
	m_localSnapshot_Attribute_isPre->setTransient(false);
	m_localSnapshot_Attribute_isPre->setVolatile(false);
	m_localSnapshot_Attribute_isPre->setChangeable(true);
	m_localSnapshot_Attribute_isPre->setUnsettable(false);
	m_localSnapshot_Attribute_isPre->setUnique(true);
	m_localSnapshot_Attribute_isPre->setDerived(false);
	m_localSnapshot_Attribute_isPre->setOrdered(true);
	m_localSnapshot_Attribute_isPre->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_localSnapshot_Attribute_isPre->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_localSnapshot_Attribute_bindings->setName("bindings");
	m_localSnapshot_Attribute_bindings->setEType(getNameValueBinding_Class());
	m_localSnapshot_Attribute_bindings->setLowerBound(0);
	m_localSnapshot_Attribute_bindings->setUpperBound(-1);
	m_localSnapshot_Attribute_bindings->setTransient(false);
	m_localSnapshot_Attribute_bindings->setVolatile(false);
	m_localSnapshot_Attribute_bindings->setChangeable(true);
	m_localSnapshot_Attribute_bindings->setUnsettable(false);
	m_localSnapshot_Attribute_bindings->setUnique(true);
	m_localSnapshot_Attribute_bindings->setDerived(false);
	m_localSnapshot_Attribute_bindings->setOrdered(true);
	m_localSnapshot_Attribute_bindings->setContainment(false);
	m_localSnapshot_Attribute_bindings->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_localSnapshot_Attribute_bindings->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_localSnapshot_Attribute_inputQ->setName("inputQ");
	m_localSnapshot_Attribute_inputQ->setEType(getOclMessageValue_Class());
	m_localSnapshot_Attribute_inputQ->setLowerBound(0);
	m_localSnapshot_Attribute_inputQ->setUpperBound(-1);
	m_localSnapshot_Attribute_inputQ->setTransient(false);
	m_localSnapshot_Attribute_inputQ->setVolatile(false);
	m_localSnapshot_Attribute_inputQ->setChangeable(true);
	m_localSnapshot_Attribute_inputQ->setUnsettable(false);
	m_localSnapshot_Attribute_inputQ->setUnique(true);
	m_localSnapshot_Attribute_inputQ->setDerived(false);
	m_localSnapshot_Attribute_inputQ->setOrdered(false);
	m_localSnapshot_Attribute_inputQ->setContainment(false);
	m_localSnapshot_Attribute_inputQ->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_localSnapshot_Attribute_inputQ->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_localSnapshot_Attribute_outputQ->setName("outputQ");
	m_localSnapshot_Attribute_outputQ->setEType(getOclMessageValue_Class());
	m_localSnapshot_Attribute_outputQ->setLowerBound(0);
	m_localSnapshot_Attribute_outputQ->setUpperBound(-1);
	m_localSnapshot_Attribute_outputQ->setTransient(false);
	m_localSnapshot_Attribute_outputQ->setVolatile(false);
	m_localSnapshot_Attribute_outputQ->setChangeable(true);
	m_localSnapshot_Attribute_outputQ->setUnsettable(false);
	m_localSnapshot_Attribute_outputQ->setUnique(true);
	m_localSnapshot_Attribute_outputQ->setDerived(false);
	m_localSnapshot_Attribute_outputQ->setOrdered(true);
	m_localSnapshot_Attribute_outputQ->setContainment(false);
	m_localSnapshot_Attribute_outputQ->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_localSnapshot_Attribute_outputQ->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_localSnapshot_Attribute_pred->setName("pred");
	m_localSnapshot_Attribute_pred->setEType(getLocalSnapshot_Class());
	m_localSnapshot_Attribute_pred->setLowerBound(0);
	m_localSnapshot_Attribute_pred->setUpperBound(1);
	m_localSnapshot_Attribute_pred->setTransient(false);
	m_localSnapshot_Attribute_pred->setVolatile(false);
	m_localSnapshot_Attribute_pred->setChangeable(true);
	m_localSnapshot_Attribute_pred->setUnsettable(false);
	m_localSnapshot_Attribute_pred->setUnique(true);
	m_localSnapshot_Attribute_pred->setDerived(false);
	m_localSnapshot_Attribute_pred->setOrdered(true);
	m_localSnapshot_Attribute_pred->setContainment(false);
	m_localSnapshot_Attribute_pred->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_localSnapshot_Attribute_pred->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Values::ValuesPackage::eInstance()->getLocalSnapshot_Attribute_succ();
		if (otherEnd != nullptr)
	    {
	   		m_localSnapshot_Attribute_pred->setEOpposite(otherEnd);
	    }
	}
	m_localSnapshot_Attribute_succ->setName("succ");
	m_localSnapshot_Attribute_succ->setEType(getLocalSnapshot_Class());
	m_localSnapshot_Attribute_succ->setLowerBound(0);
	m_localSnapshot_Attribute_succ->setUpperBound(1);
	m_localSnapshot_Attribute_succ->setTransient(false);
	m_localSnapshot_Attribute_succ->setVolatile(false);
	m_localSnapshot_Attribute_succ->setChangeable(true);
	m_localSnapshot_Attribute_succ->setUnsettable(false);
	m_localSnapshot_Attribute_succ->setUnique(true);
	m_localSnapshot_Attribute_succ->setDerived(false);
	m_localSnapshot_Attribute_succ->setOrdered(true);
	m_localSnapshot_Attribute_succ->setContainment(false);
	m_localSnapshot_Attribute_succ->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_localSnapshot_Attribute_succ->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Values::ValuesPackage::eInstance()->getLocalSnapshot_Attribute_pred();
		if (otherEnd != nullptr)
	    {
	   		m_localSnapshot_Attribute_succ->setEOpposite(otherEnd);
	    }
	}
	
	
}

void ValuesPackageImpl::initializeNameValueBindingContent()
{
	m_nameValueBinding_Class->setName("NameValueBinding");
	m_nameValueBinding_Class->setAbstract(false);
	m_nameValueBinding_Class->setInterface(false);
	
	m_nameValueBinding_Attribute_name = getNameValueBinding_Attribute_name();
	m_nameValueBinding_Attribute_name->setName("name");
		m_nameValueBinding_Attribute_name->setEType(types::typesPackage::eInstance()->getString_Class());
	m_nameValueBinding_Attribute_name->setLowerBound(0);
	m_nameValueBinding_Attribute_name->setUpperBound(1);
	m_nameValueBinding_Attribute_name->setTransient(false);
	m_nameValueBinding_Attribute_name->setVolatile(false);
	m_nameValueBinding_Attribute_name->setChangeable(true);
	m_nameValueBinding_Attribute_name->setUnsettable(false);
	m_nameValueBinding_Attribute_name->setUnique(true);
	m_nameValueBinding_Attribute_name->setDerived(false);
	m_nameValueBinding_Attribute_name->setOrdered(true);
	m_nameValueBinding_Attribute_name->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_nameValueBinding_Attribute_name->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_nameValueBinding_Attribute_value->setName("value");
	m_nameValueBinding_Attribute_value->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_nameValueBinding_Attribute_value->setLowerBound(1);
	m_nameValueBinding_Attribute_value->setUpperBound(1);
	m_nameValueBinding_Attribute_value->setTransient(false);
	m_nameValueBinding_Attribute_value->setVolatile(false);
	m_nameValueBinding_Attribute_value->setChangeable(true);
	m_nameValueBinding_Attribute_value->setUnsettable(false);
	m_nameValueBinding_Attribute_value->setUnique(true);
	m_nameValueBinding_Attribute_value->setDerived(false);
	m_nameValueBinding_Attribute_value->setOrdered(true);
	m_nameValueBinding_Attribute_value->setContainment(false);
	m_nameValueBinding_Attribute_value->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_nameValueBinding_Attribute_value->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	
}

void ValuesPackageImpl::initializeObjectValueContent()
{
	m_objectValue_Class->setName("ObjectValue");
	m_objectValue_Class->setAbstract(false);
	m_objectValue_Class->setInterface(false);
	
	
	m_objectValue_Attribute_history->setName("history");
	m_objectValue_Attribute_history->setEType(getLocalSnapshot_Class());
	m_objectValue_Attribute_history->setLowerBound(0);
	m_objectValue_Attribute_history->setUpperBound(-1);
	m_objectValue_Attribute_history->setTransient(false);
	m_objectValue_Attribute_history->setVolatile(false);
	m_objectValue_Attribute_history->setChangeable(true);
	m_objectValue_Attribute_history->setUnsettable(false);
	m_objectValue_Attribute_history->setUnique(true);
	m_objectValue_Attribute_history->setDerived(false);
	m_objectValue_Attribute_history->setOrdered(true);
	m_objectValue_Attribute_history->setContainment(false);
	m_objectValue_Attribute_history->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_objectValue_Attribute_history->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_objectValue_Attribute_value->setName("value");
	m_objectValue_Attribute_value->setEType(ecore::ecorePackage::eInstance()->getEObject_Class());
	m_objectValue_Attribute_value->setLowerBound(1);
	m_objectValue_Attribute_value->setUpperBound(1);
	m_objectValue_Attribute_value->setTransient(false);
	m_objectValue_Attribute_value->setVolatile(false);
	m_objectValue_Attribute_value->setChangeable(true);
	m_objectValue_Attribute_value->setUnsettable(false);
	m_objectValue_Attribute_value->setUnique(true);
	m_objectValue_Attribute_value->setDerived(false);
	m_objectValue_Attribute_value->setOrdered(true);
	m_objectValue_Attribute_value->setContainment(false);
	m_objectValue_Attribute_value->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_objectValue_Attribute_value->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_objectValue_Operation_equals_Value->setName("equals");
	m_objectValue_Operation_equals_Value->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_objectValue_Operation_equals_Value->setLowerBound(1);
	m_objectValue_Operation_equals_Value->setUpperBound(1);
	m_objectValue_Operation_equals_Value->setUnique(true);
	m_objectValue_Operation_equals_Value->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_objectValue_Operation_equals_Value);
		parameter->setName("otherValue");
		parameter->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_objectValue_Operation_toString->setName("toString");
	m_objectValue_Operation_toString->setEType(types::typesPackage::eInstance()->getString_Class());
	m_objectValue_Operation_toString->setLowerBound(1);
	m_objectValue_Operation_toString->setUpperBound(1);
	m_objectValue_Operation_toString->setUnique(true);
	m_objectValue_Operation_toString->setOrdered(false);
	
	
}

void ValuesPackageImpl::initializeOclMessageValueContent()
{
	m_oclMessageValue_Class->setName("OclMessageValue");
	m_oclMessageValue_Class->setAbstract(false);
	m_oclMessageValue_Class->setInterface(false);
	
	m_oclMessageValue_Attribute_isAsyncOperation = getOclMessageValue_Attribute_isAsyncOperation();
	m_oclMessageValue_Attribute_isAsyncOperation->setName("isAsyncOperation");
		m_oclMessageValue_Attribute_isAsyncOperation->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_oclMessageValue_Attribute_isAsyncOperation->setLowerBound(0);
	m_oclMessageValue_Attribute_isAsyncOperation->setUpperBound(1);
	m_oclMessageValue_Attribute_isAsyncOperation->setTransient(false);
	m_oclMessageValue_Attribute_isAsyncOperation->setVolatile(false);
	m_oclMessageValue_Attribute_isAsyncOperation->setChangeable(true);
	m_oclMessageValue_Attribute_isAsyncOperation->setUnsettable(false);
	m_oclMessageValue_Attribute_isAsyncOperation->setUnique(true);
	m_oclMessageValue_Attribute_isAsyncOperation->setDerived(false);
	m_oclMessageValue_Attribute_isAsyncOperation->setOrdered(true);
	m_oclMessageValue_Attribute_isAsyncOperation->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_oclMessageValue_Attribute_isAsyncOperation->setDefaultValueLiteral(defaultValue);
		}
	}
	m_oclMessageValue_Attribute_isSignal = getOclMessageValue_Attribute_isSignal();
	m_oclMessageValue_Attribute_isSignal->setName("isSignal");
		m_oclMessageValue_Attribute_isSignal->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_oclMessageValue_Attribute_isSignal->setLowerBound(0);
	m_oclMessageValue_Attribute_isSignal->setUpperBound(1);
	m_oclMessageValue_Attribute_isSignal->setTransient(false);
	m_oclMessageValue_Attribute_isSignal->setVolatile(false);
	m_oclMessageValue_Attribute_isSignal->setChangeable(true);
	m_oclMessageValue_Attribute_isSignal->setUnsettable(false);
	m_oclMessageValue_Attribute_isSignal->setUnique(true);
	m_oclMessageValue_Attribute_isSignal->setDerived(false);
	m_oclMessageValue_Attribute_isSignal->setOrdered(true);
	m_oclMessageValue_Attribute_isSignal->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_oclMessageValue_Attribute_isSignal->setDefaultValueLiteral(defaultValue);
		}
	}
	m_oclMessageValue_Attribute_isSyncOperation = getOclMessageValue_Attribute_isSyncOperation();
	m_oclMessageValue_Attribute_isSyncOperation->setName("isSyncOperation");
		m_oclMessageValue_Attribute_isSyncOperation->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_oclMessageValue_Attribute_isSyncOperation->setLowerBound(0);
	m_oclMessageValue_Attribute_isSyncOperation->setUpperBound(1);
	m_oclMessageValue_Attribute_isSyncOperation->setTransient(false);
	m_oclMessageValue_Attribute_isSyncOperation->setVolatile(false);
	m_oclMessageValue_Attribute_isSyncOperation->setChangeable(true);
	m_oclMessageValue_Attribute_isSyncOperation->setUnsettable(false);
	m_oclMessageValue_Attribute_isSyncOperation->setUnique(true);
	m_oclMessageValue_Attribute_isSyncOperation->setDerived(false);
	m_oclMessageValue_Attribute_isSyncOperation->setOrdered(true);
	m_oclMessageValue_Attribute_isSyncOperation->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_oclMessageValue_Attribute_isSyncOperation->setDefaultValueLiteral(defaultValue);
		}
	}
	m_oclMessageValue_Attribute_name = getOclMessageValue_Attribute_name();
	m_oclMessageValue_Attribute_name->setName("name");
		m_oclMessageValue_Attribute_name->setEType(types::typesPackage::eInstance()->getString_Class());
	m_oclMessageValue_Attribute_name->setLowerBound(0);
	m_oclMessageValue_Attribute_name->setUpperBound(1);
	m_oclMessageValue_Attribute_name->setTransient(false);
	m_oclMessageValue_Attribute_name->setVolatile(false);
	m_oclMessageValue_Attribute_name->setChangeable(true);
	m_oclMessageValue_Attribute_name->setUnsettable(false);
	m_oclMessageValue_Attribute_name->setUnique(true);
	m_oclMessageValue_Attribute_name->setDerived(false);
	m_oclMessageValue_Attribute_name->setOrdered(true);
	m_oclMessageValue_Attribute_name->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_oclMessageValue_Attribute_name->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_oclMessageValue_Attribute_arguments->setName("arguments");
	m_oclMessageValue_Attribute_arguments->setEType(getNameValueBinding_Class());
	m_oclMessageValue_Attribute_arguments->setLowerBound(0);
	m_oclMessageValue_Attribute_arguments->setUpperBound(-1);
	m_oclMessageValue_Attribute_arguments->setTransient(false);
	m_oclMessageValue_Attribute_arguments->setVolatile(false);
	m_oclMessageValue_Attribute_arguments->setChangeable(true);
	m_oclMessageValue_Attribute_arguments->setUnsettable(false);
	m_oclMessageValue_Attribute_arguments->setUnique(true);
	m_oclMessageValue_Attribute_arguments->setDerived(false);
	m_oclMessageValue_Attribute_arguments->setOrdered(true);
	m_oclMessageValue_Attribute_arguments->setContainment(false);
	m_oclMessageValue_Attribute_arguments->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_oclMessageValue_Attribute_arguments->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_oclMessageValue_Attribute_returnMessage->setName("returnMessage");
	m_oclMessageValue_Attribute_returnMessage->setEType(getOclMessageValue_Class());
	m_oclMessageValue_Attribute_returnMessage->setLowerBound(0);
	m_oclMessageValue_Attribute_returnMessage->setUpperBound(1);
	m_oclMessageValue_Attribute_returnMessage->setTransient(false);
	m_oclMessageValue_Attribute_returnMessage->setVolatile(false);
	m_oclMessageValue_Attribute_returnMessage->setChangeable(true);
	m_oclMessageValue_Attribute_returnMessage->setUnsettable(false);
	m_oclMessageValue_Attribute_returnMessage->setUnique(true);
	m_oclMessageValue_Attribute_returnMessage->setDerived(false);
	m_oclMessageValue_Attribute_returnMessage->setOrdered(true);
	m_oclMessageValue_Attribute_returnMessage->setContainment(false);
	m_oclMessageValue_Attribute_returnMessage->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_oclMessageValue_Attribute_returnMessage->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_oclMessageValue_Attribute_source->setName("source");
	m_oclMessageValue_Attribute_source->setEType(getObjectValue_Class());
	m_oclMessageValue_Attribute_source->setLowerBound(0);
	m_oclMessageValue_Attribute_source->setUpperBound(1);
	m_oclMessageValue_Attribute_source->setTransient(false);
	m_oclMessageValue_Attribute_source->setVolatile(false);
	m_oclMessageValue_Attribute_source->setChangeable(true);
	m_oclMessageValue_Attribute_source->setUnsettable(false);
	m_oclMessageValue_Attribute_source->setUnique(true);
	m_oclMessageValue_Attribute_source->setDerived(false);
	m_oclMessageValue_Attribute_source->setOrdered(true);
	m_oclMessageValue_Attribute_source->setContainment(false);
	m_oclMessageValue_Attribute_source->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_oclMessageValue_Attribute_source->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_oclMessageValue_Attribute_target->setName("target");
	m_oclMessageValue_Attribute_target->setEType(getObjectValue_Class());
	m_oclMessageValue_Attribute_target->setLowerBound(0);
	m_oclMessageValue_Attribute_target->setUpperBound(1);
	m_oclMessageValue_Attribute_target->setTransient(false);
	m_oclMessageValue_Attribute_target->setVolatile(false);
	m_oclMessageValue_Attribute_target->setChangeable(true);
	m_oclMessageValue_Attribute_target->setUnsettable(false);
	m_oclMessageValue_Attribute_target->setUnique(true);
	m_oclMessageValue_Attribute_target->setDerived(false);
	m_oclMessageValue_Attribute_target->setOrdered(true);
	m_oclMessageValue_Attribute_target->setContainment(false);
	m_oclMessageValue_Attribute_target->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_oclMessageValue_Attribute_target->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_oclMessageValue_Operation_toString->setName("toString");
	m_oclMessageValue_Operation_toString->setEType(types::typesPackage::eInstance()->getString_Class());
	m_oclMessageValue_Operation_toString->setLowerBound(1);
	m_oclMessageValue_Operation_toString->setUpperBound(1);
	m_oclMessageValue_Operation_toString->setUnique(true);
	m_oclMessageValue_Operation_toString->setOrdered(false);
	
	
}

void ValuesPackageImpl::initializeOclVoidValueContent()
{
	m_oclVoidValue_Class->setName("OclVoidValue");
	m_oclVoidValue_Class->setAbstract(false);
	m_oclVoidValue_Class->setInterface(false);
	
	
	
	m_oclVoidValue_Operation_equals_Value->setName("equals");
	m_oclVoidValue_Operation_equals_Value->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_oclVoidValue_Operation_equals_Value->setLowerBound(1);
	m_oclVoidValue_Operation_equals_Value->setUpperBound(1);
	m_oclVoidValue_Operation_equals_Value->setUnique(true);
	m_oclVoidValue_Operation_equals_Value->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_oclVoidValue_Operation_equals_Value);
		parameter->setName("otherValue");
		parameter->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_oclVoidValue_Operation_toString->setName("toString");
	m_oclVoidValue_Operation_toString->setEType(types::typesPackage::eInstance()->getString_Class());
	m_oclVoidValue_Operation_toString->setLowerBound(1);
	m_oclVoidValue_Operation_toString->setUpperBound(1);
	m_oclVoidValue_Operation_toString->setUnique(true);
	m_oclVoidValue_Operation_toString->setOrdered(false);
	
	
}

void ValuesPackageImpl::initializeOrderedSetTypeValueContent()
{
	m_orderedSetTypeValue_Class->setName("OrderedSetTypeValue");
	m_orderedSetTypeValue_Class->setAbstract(false);
	m_orderedSetTypeValue_Class->setInterface(false);
	
	
	
	m_orderedSetTypeValue_Operation_addValue_Value->setName("addValue");
	m_orderedSetTypeValue_Operation_addValue_Value->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_orderedSetTypeValue_Operation_addValue_Value->setLowerBound(0);
	m_orderedSetTypeValue_Operation_addValue_Value->setUpperBound(1);
	m_orderedSetTypeValue_Operation_addValue_Value->setUnique(true);
	m_orderedSetTypeValue_Operation_addValue_Value->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_orderedSetTypeValue_Operation_addValue_Value);
		parameter->setName("value");
		parameter->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ValuesPackageImpl::initializeSequenceTypeValueContent()
{
	m_sequenceTypeValue_Class->setName("SequenceTypeValue");
	m_sequenceTypeValue_Class->setAbstract(false);
	m_sequenceTypeValue_Class->setInterface(false);
	
	
	
	m_sequenceTypeValue_Operation_addValue_Value->setName("addValue");
	m_sequenceTypeValue_Operation_addValue_Value->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_sequenceTypeValue_Operation_addValue_Value->setLowerBound(0);
	m_sequenceTypeValue_Operation_addValue_Value->setUpperBound(1);
	m_sequenceTypeValue_Operation_addValue_Value->setUnique(true);
	m_sequenceTypeValue_Operation_addValue_Value->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_sequenceTypeValue_Operation_addValue_Value);
		parameter->setName("value");
		parameter->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ValuesPackageImpl::initializeSetTypeValueContent()
{
	m_setTypeValue_Class->setName("SetTypeValue");
	m_setTypeValue_Class->setAbstract(false);
	m_setTypeValue_Class->setInterface(false);
	
	
	
	m_setTypeValue_Operation_addValue_Value->setName("addValue");
	m_setTypeValue_Operation_addValue_Value->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_setTypeValue_Operation_addValue_Value->setLowerBound(0);
	m_setTypeValue_Operation_addValue_Value->setUpperBound(1);
	m_setTypeValue_Operation_addValue_Value->setUnique(true);
	m_setTypeValue_Operation_addValue_Value->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_setTypeValue_Operation_addValue_Value);
		parameter->setName("value");
		parameter->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ValuesPackageImpl::initializeStaticValueContent()
{
	m_staticValue_Class->setName("StaticValue");
	m_staticValue_Class->setAbstract(false);
	m_staticValue_Class->setInterface(false);
	
	
	
	
}

void ValuesPackageImpl::initializeTupleValueContent()
{
	m_tupleValue_Class->setName("TupleValue");
	m_tupleValue_Class->setAbstract(false);
	m_tupleValue_Class->setInterface(false);
	
	
	m_tupleValue_Attribute_elements->setName("elements");
	m_tupleValue_Attribute_elements->setEType(getNameValueBinding_Class());
	m_tupleValue_Attribute_elements->setLowerBound(0);
	m_tupleValue_Attribute_elements->setUpperBound(-1);
	m_tupleValue_Attribute_elements->setTransient(false);
	m_tupleValue_Attribute_elements->setVolatile(false);
	m_tupleValue_Attribute_elements->setChangeable(true);
	m_tupleValue_Attribute_elements->setUnsettable(false);
	m_tupleValue_Attribute_elements->setUnique(true);
	m_tupleValue_Attribute_elements->setDerived(false);
	m_tupleValue_Attribute_elements->setOrdered(false);
	m_tupleValue_Attribute_elements->setContainment(false);
	m_tupleValue_Attribute_elements->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_tupleValue_Attribute_elements->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_tupleValue_Attribute_model->setName("model");
	m_tupleValue_Attribute_model->setEType(ocl::Types::TypesPackage::eInstance()->getTupleType_Class());
	m_tupleValue_Attribute_model->setLowerBound(0);
	m_tupleValue_Attribute_model->setUpperBound(1);
	m_tupleValue_Attribute_model->setTransient(false);
	m_tupleValue_Attribute_model->setVolatile(false);
	m_tupleValue_Attribute_model->setChangeable(true);
	m_tupleValue_Attribute_model->setUnsettable(false);
	m_tupleValue_Attribute_model->setUnique(true);
	m_tupleValue_Attribute_model->setDerived(false);
	m_tupleValue_Attribute_model->setOrdered(true);
	m_tupleValue_Attribute_model->setContainment(false);
	m_tupleValue_Attribute_model->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_tupleValue_Attribute_model->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Types::TypesPackage::eInstance()->getTupleType_Attribute_instance();
		if (otherEnd != nullptr)
	    {
	   		m_tupleValue_Attribute_model->setEOpposite(otherEnd);
	    }
	}
	
	m_tupleValue_Operation_equals_Value->setName("equals");
	m_tupleValue_Operation_equals_Value->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_tupleValue_Operation_equals_Value->setLowerBound(1);
	m_tupleValue_Operation_equals_Value->setUpperBound(1);
	m_tupleValue_Operation_equals_Value->setUnique(true);
	m_tupleValue_Operation_equals_Value->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_tupleValue_Operation_equals_Value);
		parameter->setName("otherValue");
		parameter->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_tupleValue_Operation_toString->setName("toString");
	m_tupleValue_Operation_toString->setEType(types::typesPackage::eInstance()->getString_Class());
	m_tupleValue_Operation_toString->setLowerBound(1);
	m_tupleValue_Operation_toString->setUpperBound(1);
	m_tupleValue_Operation_toString->setUnique(true);
	m_tupleValue_Operation_toString->setOrdered(false);
	
	
}

void ValuesPackageImpl::initializeUndefinedValueContent()
{
	m_undefinedValue_Class->setName("UndefinedValue");
	m_undefinedValue_Class->setAbstract(false);
	m_undefinedValue_Class->setInterface(false);
	
	
	
	m_undefinedValue_Operation_equals_Value->setName("equals");
	m_undefinedValue_Operation_equals_Value->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_undefinedValue_Operation_equals_Value->setLowerBound(1);
	m_undefinedValue_Operation_equals_Value->setUpperBound(1);
	m_undefinedValue_Operation_equals_Value->setUnique(true);
	m_undefinedValue_Operation_equals_Value->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_undefinedValue_Operation_equals_Value);
		parameter->setName("otherValue");
		parameter->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_undefinedValue_Operation_toString->setName("toString");
	m_undefinedValue_Operation_toString->setEType(types::typesPackage::eInstance()->getString_Class());
	m_undefinedValue_Operation_toString->setLowerBound(1);
	m_undefinedValue_Operation_toString->setUpperBound(1);
	m_undefinedValue_Operation_toString->setUnique(true);
	m_undefinedValue_Operation_toString->setOrdered(false);
	
	
}

void ValuesPackageImpl::initializePackageEDataTypes()
{
	
}

