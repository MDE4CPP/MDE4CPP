#include "ocl/Types/impl/TypesPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "ocl/Values/ValuesPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "ocl/oclPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"


using namespace ocl::Types;

void TypesPackageImpl::initializePackageContents()
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
	m_anyType_Class->getESuperTypes()->push_back(ecore::ecorePackage::eInstance()->getEClassifier_Class());
	m_bagType_Class->getESuperTypes()->push_back(getCollectionType_Class());
	m_collectionType_Class->getESuperTypes()->push_back(ecore::ecorePackage::eInstance()->getEDataType_Class());
	m_invalidType_Class->getESuperTypes()->push_back(ecore::ecorePackage::eInstance()->getEClassifier_Class());
	m_messageType_Class->getESuperTypes()->push_back(ecore::ecorePackage::eInstance()->getEClassifier_Class());
	m_orderedSetType_Class->getESuperTypes()->push_back(getCollectionType_Class());
	m_sequenceType_Class->getESuperTypes()->push_back(getCollectionType_Class());
	m_setType_Class->getESuperTypes()->push_back(getCollectionType_Class());
	m_templateParameterType_Class->getESuperTypes()->push_back(ecore::ecorePackage::eInstance()->getEClassifier_Class());
	m_tupleType_Class->getESuperTypes()->push_back(ecore::ecorePackage::eInstance()->getEDataType_Class());
	m_voidType_Class->getESuperTypes()->push_back(ecore::ecorePackage::eInstance()->getEClassifier_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeAnyTypeContent();
	initializeBagTypeContent();
	initializeCollectionTypeContent();
	initializeInvalidTypeContent();
	initializeMessageTypeContent();
	initializeNameTypeBindingContent();
	initializeOrderedSetTypeContent();
	initializeSequenceTypeContent();
	initializeSetTypeContent();
	initializeTemplateParameterTypeContent();
	initializeTupleTypeContent();
	initializeVoidTypeContent();

	initializePackageEDataTypes();

}

void TypesPackageImpl::initializeAnyTypeContent()
{
	m_anyType_Class->setName("AnyType");
	m_anyType_Class->setAbstract(false);
	m_anyType_Class->setInterface(false);
	
	
	m_anyType_Attribute_object->setName("object");
	m_anyType_Attribute_object->setEType(ecore::ecorePackage::eInstance()->getEClassifier_Class());
	m_anyType_Attribute_object->setLowerBound(0);
	m_anyType_Attribute_object->setUpperBound(1);
	m_anyType_Attribute_object->setTransient(false);
	m_anyType_Attribute_object->setVolatile(false);
	m_anyType_Attribute_object->setChangeable(true);
	m_anyType_Attribute_object->setUnsettable(false);
	m_anyType_Attribute_object->setUnique(true);
	m_anyType_Attribute_object->setDerived(false);
	m_anyType_Attribute_object->setOrdered(true);
	m_anyType_Attribute_object->setContainment(true);
	m_anyType_Attribute_object->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_anyType_Attribute_object->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	
}

void TypesPackageImpl::initializeBagTypeContent()
{
	m_bagType_Class->setName("BagType");
	m_bagType_Class->setAbstract(false);
	m_bagType_Class->setInterface(false);
	
	
	
	
}

void TypesPackageImpl::initializeCollectionTypeContent()
{
	m_collectionType_Class->setName("CollectionType");
	m_collectionType_Class->setAbstract(false);
	m_collectionType_Class->setInterface(false);
	
	
	m_collectionType_Attribute_elementType->setName("elementType");
	m_collectionType_Attribute_elementType->setEType(ecore::ecorePackage::eInstance()->getEClassifier_Class());
	m_collectionType_Attribute_elementType->setLowerBound(1);
	m_collectionType_Attribute_elementType->setUpperBound(1);
	m_collectionType_Attribute_elementType->setTransient(false);
	m_collectionType_Attribute_elementType->setVolatile(false);
	m_collectionType_Attribute_elementType->setChangeable(true);
	m_collectionType_Attribute_elementType->setUnsettable(false);
	m_collectionType_Attribute_elementType->setUnique(true);
	m_collectionType_Attribute_elementType->setDerived(false);
	m_collectionType_Attribute_elementType->setOrdered(false);
	m_collectionType_Attribute_elementType->setContainment(true);
	m_collectionType_Attribute_elementType->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_collectionType_Attribute_elementType->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_collectionType_Attribute_instance->setName("instance");
	m_collectionType_Attribute_instance->setEType(ocl::Values::ValuesPackage::eInstance()->getCollectionValue_Class());
	m_collectionType_Attribute_instance->setLowerBound(0);
	m_collectionType_Attribute_instance->setUpperBound(1);
	m_collectionType_Attribute_instance->setTransient(false);
	m_collectionType_Attribute_instance->setVolatile(false);
	m_collectionType_Attribute_instance->setChangeable(true);
	m_collectionType_Attribute_instance->setUnsettable(false);
	m_collectionType_Attribute_instance->setUnique(true);
	m_collectionType_Attribute_instance->setDerived(false);
	m_collectionType_Attribute_instance->setOrdered(true);
	m_collectionType_Attribute_instance->setContainment(false);
	m_collectionType_Attribute_instance->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_collectionType_Attribute_instance->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Values::ValuesPackage::eInstance()->getCollectionValue_Attribute_model();
		if (otherEnd != nullptr)
	    {
	   		m_collectionType_Attribute_instance->setEOpposite(otherEnd);
	    }
	}
	
	m_collectionType_Operation_kindOf_CollectionType->setName("kindOf");
	m_collectionType_Operation_kindOf_CollectionType->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_collectionType_Operation_kindOf_CollectionType->setLowerBound(1);
	m_collectionType_Operation_kindOf_CollectionType->setUpperBound(1);
	m_collectionType_Operation_kindOf_CollectionType->setUnique(true);
	m_collectionType_Operation_kindOf_CollectionType->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_collectionType_Operation_kindOf_CollectionType);
		parameter->setName("coll");
		parameter->setEType(getCollectionType_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void TypesPackageImpl::initializeInvalidTypeContent()
{
	m_invalidType_Class->setName("InvalidType");
	m_invalidType_Class->setAbstract(false);
	m_invalidType_Class->setInterface(false);
	
	
	
	
}

void TypesPackageImpl::initializeMessageTypeContent()
{
	m_messageType_Class->setName("MessageType");
	m_messageType_Class->setAbstract(false);
	m_messageType_Class->setInterface(false);
	
	
	m_messageType_Attribute_referredOperation->setName("referredOperation");
	m_messageType_Attribute_referredOperation->setEType(ecore::ecorePackage::eInstance()->getEOperation_Class());
	m_messageType_Attribute_referredOperation->setLowerBound(0);
	m_messageType_Attribute_referredOperation->setUpperBound(1);
	m_messageType_Attribute_referredOperation->setTransient(false);
	m_messageType_Attribute_referredOperation->setVolatile(false);
	m_messageType_Attribute_referredOperation->setChangeable(true);
	m_messageType_Attribute_referredOperation->setUnsettable(false);
	m_messageType_Attribute_referredOperation->setUnique(true);
	m_messageType_Attribute_referredOperation->setDerived(false);
	m_messageType_Attribute_referredOperation->setOrdered(true);
	m_messageType_Attribute_referredOperation->setContainment(false);
	m_messageType_Attribute_referredOperation->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_messageType_Attribute_referredOperation->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_messageType_Attribute_referredSignal->setName("referredSignal");
	m_messageType_Attribute_referredSignal->setEType(uml::umlPackage::eInstance()->getSignal_Class());
	m_messageType_Attribute_referredSignal->setLowerBound(0);
	m_messageType_Attribute_referredSignal->setUpperBound(1);
	m_messageType_Attribute_referredSignal->setTransient(false);
	m_messageType_Attribute_referredSignal->setVolatile(false);
	m_messageType_Attribute_referredSignal->setChangeable(true);
	m_messageType_Attribute_referredSignal->setUnsettable(false);
	m_messageType_Attribute_referredSignal->setUnique(true);
	m_messageType_Attribute_referredSignal->setDerived(false);
	m_messageType_Attribute_referredSignal->setOrdered(true);
	m_messageType_Attribute_referredSignal->setContainment(false);
	m_messageType_Attribute_referredSignal->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_messageType_Attribute_referredSignal->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	
}

void TypesPackageImpl::initializeNameTypeBindingContent()
{
	m_nameTypeBinding_Class->setName("NameTypeBinding");
	m_nameTypeBinding_Class->setAbstract(false);
	m_nameTypeBinding_Class->setInterface(false);
	
	m_nameTypeBinding_Attribute_name = getNameTypeBinding_Attribute_name();
	m_nameTypeBinding_Attribute_name->setName("name");
		m_nameTypeBinding_Attribute_name->setEType(types::typesPackage::eInstance()->getString_Class());
	m_nameTypeBinding_Attribute_name->setLowerBound(0);
	m_nameTypeBinding_Attribute_name->setUpperBound(1);
	m_nameTypeBinding_Attribute_name->setTransient(false);
	m_nameTypeBinding_Attribute_name->setVolatile(false);
	m_nameTypeBinding_Attribute_name->setChangeable(true);
	m_nameTypeBinding_Attribute_name->setUnsettable(false);
	m_nameTypeBinding_Attribute_name->setUnique(true);
	m_nameTypeBinding_Attribute_name->setDerived(false);
	m_nameTypeBinding_Attribute_name->setOrdered(true);
	m_nameTypeBinding_Attribute_name->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_nameTypeBinding_Attribute_name->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_nameTypeBinding_Attribute_type->setName("type");
	m_nameTypeBinding_Attribute_type->setEType(ecore::ecorePackage::eInstance()->getEClassifier_Class());
	m_nameTypeBinding_Attribute_type->setLowerBound(0);
	m_nameTypeBinding_Attribute_type->setUpperBound(1);
	m_nameTypeBinding_Attribute_type->setTransient(false);
	m_nameTypeBinding_Attribute_type->setVolatile(false);
	m_nameTypeBinding_Attribute_type->setChangeable(true);
	m_nameTypeBinding_Attribute_type->setUnsettable(false);
	m_nameTypeBinding_Attribute_type->setUnique(true);
	m_nameTypeBinding_Attribute_type->setDerived(false);
	m_nameTypeBinding_Attribute_type->setOrdered(true);
	m_nameTypeBinding_Attribute_type->setContainment(false);
	m_nameTypeBinding_Attribute_type->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_nameTypeBinding_Attribute_type->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	
}

void TypesPackageImpl::initializeOrderedSetTypeContent()
{
	m_orderedSetType_Class->setName("OrderedSetType");
	m_orderedSetType_Class->setAbstract(false);
	m_orderedSetType_Class->setInterface(false);
	
	
	
	
}

void TypesPackageImpl::initializeSequenceTypeContent()
{
	m_sequenceType_Class->setName("SequenceType");
	m_sequenceType_Class->setAbstract(false);
	m_sequenceType_Class->setInterface(false);
	
	
	
	
}

void TypesPackageImpl::initializeSetTypeContent()
{
	m_setType_Class->setName("SetType");
	m_setType_Class->setAbstract(false);
	m_setType_Class->setInterface(false);
	
	
	
	
}

void TypesPackageImpl::initializeTemplateParameterTypeContent()
{
	m_templateParameterType_Class->setName("TemplateParameterType");
	m_templateParameterType_Class->setAbstract(false);
	m_templateParameterType_Class->setInterface(false);
	
	m_templateParameterType_Attribute_specification = getTemplateParameterType_Attribute_specification();
	m_templateParameterType_Attribute_specification->setName("specification");
		m_templateParameterType_Attribute_specification->setEType(types::typesPackage::eInstance()->getString_Class());
	m_templateParameterType_Attribute_specification->setLowerBound(0);
	m_templateParameterType_Attribute_specification->setUpperBound(1);
	m_templateParameterType_Attribute_specification->setTransient(false);
	m_templateParameterType_Attribute_specification->setVolatile(false);
	m_templateParameterType_Attribute_specification->setChangeable(true);
	m_templateParameterType_Attribute_specification->setUnsettable(false);
	m_templateParameterType_Attribute_specification->setUnique(true);
	m_templateParameterType_Attribute_specification->setDerived(false);
	m_templateParameterType_Attribute_specification->setOrdered(false);
	m_templateParameterType_Attribute_specification->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_templateParameterType_Attribute_specification->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	
}

void TypesPackageImpl::initializeTupleTypeContent()
{
	m_tupleType_Class->setName("TupleType");
	m_tupleType_Class->setAbstract(false);
	m_tupleType_Class->setInterface(false);
	
	
	m_tupleType_Attribute_instance->setName("instance");
	m_tupleType_Attribute_instance->setEType(ocl::Values::ValuesPackage::eInstance()->getTupleValue_Class());
	m_tupleType_Attribute_instance->setLowerBound(0);
	m_tupleType_Attribute_instance->setUpperBound(1);
	m_tupleType_Attribute_instance->setTransient(false);
	m_tupleType_Attribute_instance->setVolatile(false);
	m_tupleType_Attribute_instance->setChangeable(true);
	m_tupleType_Attribute_instance->setUnsettable(false);
	m_tupleType_Attribute_instance->setUnique(true);
	m_tupleType_Attribute_instance->setDerived(false);
	m_tupleType_Attribute_instance->setOrdered(true);
	m_tupleType_Attribute_instance->setContainment(false);
	m_tupleType_Attribute_instance->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_tupleType_Attribute_instance->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Values::ValuesPackage::eInstance()->getTupleValue_Attribute_model();
		if (otherEnd != nullptr)
	    {
	   		m_tupleType_Attribute_instance->setEOpposite(otherEnd);
	    }
	}
	m_tupleType_Attribute_parts->setName("parts");
	m_tupleType_Attribute_parts->setEType(getNameTypeBinding_Class());
	m_tupleType_Attribute_parts->setLowerBound(0);
	m_tupleType_Attribute_parts->setUpperBound(-1);
	m_tupleType_Attribute_parts->setTransient(false);
	m_tupleType_Attribute_parts->setVolatile(false);
	m_tupleType_Attribute_parts->setChangeable(true);
	m_tupleType_Attribute_parts->setUnsettable(false);
	m_tupleType_Attribute_parts->setUnique(true);
	m_tupleType_Attribute_parts->setDerived(false);
	m_tupleType_Attribute_parts->setOrdered(true);
	m_tupleType_Attribute_parts->setContainment(false);
	m_tupleType_Attribute_parts->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_tupleType_Attribute_parts->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	
}

void TypesPackageImpl::initializeVoidTypeContent()
{
	m_voidType_Class->setName("VoidType");
	m_voidType_Class->setAbstract(false);
	m_voidType_Class->setInterface(false);
	
	
	
	
}

void TypesPackageImpl::initializePackageEDataTypes()
{
	
}

