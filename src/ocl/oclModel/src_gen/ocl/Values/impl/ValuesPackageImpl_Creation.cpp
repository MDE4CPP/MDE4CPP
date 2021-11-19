#include "ocl/Values/impl/ValuesPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EParameter.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "ocl/oclPackage.hpp"
#include "types/typesPackage.hpp"
//include subpackages 
 
using namespace ocl::Values;

void ValuesPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();

	createBagTypeValueContent(package, factory);
	createCollectionValueContent(package, factory);
	createElementContent(package, factory);
	createLocalSnapshotContent(package, factory);
	createNameValueBindingContent(package, factory);
	createObjectValueContent(package, factory);
	createOclMessageValueContent(package, factory);
	createOclVoidValueContent(package, factory);
	createOrderedSetTypeValueContent(package, factory);
	createSequenceTypeValueContent(package, factory);
	createSetTypeValueContent(package, factory);
	createStaticValueContent(package, factory);
	createTupleValueContent(package, factory);
	createUndefinedValueContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void ValuesPackageImpl::createBagTypeValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_bagTypeValue_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, BAGTYPEVALUE_CLASS);
	
	
	m_bagTypeValue_Operation_addValue_Value = factory->createEOperation_as_eOperations_in_EClass(m_bagTypeValue_Class, BAGTYPEVALUE_OPERATION_ADDVALUE_VALUE);
	
}

void ValuesPackageImpl::createCollectionValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_collectionValue_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, COLLECTIONVALUE_CLASS);
	
	m_collectionValue_Attribute_elements = factory->createEReference_as_eReferences_in_EClass(m_collectionValue_Class, COLLECTIONVALUE_ATTRIBUTE_ELEMENTS);
	m_collectionValue_Attribute_model = factory->createEReference_as_eReferences_in_EClass(m_collectionValue_Class, COLLECTIONVALUE_ATTRIBUTE_MODEL);
	
	m_collectionValue_Operation_addValue_Value = factory->createEOperation_as_eOperations_in_EClass(m_collectionValue_Class, COLLECTIONVALUE_OPERATION_ADDVALUE_VALUE);
	m_collectionValue_Operation_equals_Value = factory->createEOperation_as_eOperations_in_EClass(m_collectionValue_Class, COLLECTIONVALUE_OPERATION_EQUALS_VALUE);
	m_collectionValue_Operation_find_Value = factory->createEOperation_as_eOperations_in_EClass(m_collectionValue_Class, COLLECTIONVALUE_OPERATION_FIND_VALUE);
	m_collectionValue_Operation_toString = factory->createEOperation_as_eOperations_in_EClass(m_collectionValue_Class, COLLECTIONVALUE_OPERATION_TOSTRING);
	
}

void ValuesPackageImpl::createElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_element_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ELEMENT_CLASS);
	m_element_Attribute_indexNr = factory->createEAttribute_as_eAttributes_in_EClas(m_element_Class, ELEMENT_ATTRIBUTE_INDEXNR);
	
	m_element_Attribute_value = factory->createEReference_as_eReferences_in_EClass(m_element_Class, ELEMENT_ATTRIBUTE_VALUE);
	
	
}

void ValuesPackageImpl::createLocalSnapshotContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_localSnapshot_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, LOCALSNAPSHOT_CLASS);
	m_localSnapshot_Attribute_isPost = factory->createEAttribute_as_eAttributes_in_EClas(m_localSnapshot_Class, LOCALSNAPSHOT_ATTRIBUTE_ISPOST);
	m_localSnapshot_Attribute_isPre = factory->createEAttribute_as_eAttributes_in_EClas(m_localSnapshot_Class, LOCALSNAPSHOT_ATTRIBUTE_ISPRE);
	
	m_localSnapshot_Attribute_bindings = factory->createEReference_as_eReferences_in_EClass(m_localSnapshot_Class, LOCALSNAPSHOT_ATTRIBUTE_BINDINGS);
	m_localSnapshot_Attribute_inputQ = factory->createEReference_as_eReferences_in_EClass(m_localSnapshot_Class, LOCALSNAPSHOT_ATTRIBUTE_INPUTQ);
	m_localSnapshot_Attribute_outputQ = factory->createEReference_as_eReferences_in_EClass(m_localSnapshot_Class, LOCALSNAPSHOT_ATTRIBUTE_OUTPUTQ);
	m_localSnapshot_Attribute_pred = factory->createEReference_as_eReferences_in_EClass(m_localSnapshot_Class, LOCALSNAPSHOT_ATTRIBUTE_PRED);
	m_localSnapshot_Attribute_succ = factory->createEReference_as_eReferences_in_EClass(m_localSnapshot_Class, LOCALSNAPSHOT_ATTRIBUTE_SUCC);
	
	
}

void ValuesPackageImpl::createNameValueBindingContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_nameValueBinding_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, NAMEVALUEBINDING_CLASS);
	m_nameValueBinding_Attribute_name = factory->createEAttribute_as_eAttributes_in_EClas(m_nameValueBinding_Class, NAMEVALUEBINDING_ATTRIBUTE_NAME);
	
	m_nameValueBinding_Attribute_value = factory->createEReference_as_eReferences_in_EClass(m_nameValueBinding_Class, NAMEVALUEBINDING_ATTRIBUTE_VALUE);
	
	
}

void ValuesPackageImpl::createObjectValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_objectValue_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, OBJECTVALUE_CLASS);
	
	m_objectValue_Attribute_history = factory->createEReference_as_eReferences_in_EClass(m_objectValue_Class, OBJECTVALUE_ATTRIBUTE_HISTORY);
	m_objectValue_Attribute_value = factory->createEReference_as_eReferences_in_EClass(m_objectValue_Class, OBJECTVALUE_ATTRIBUTE_VALUE);
	
	m_objectValue_Operation_equals_Value = factory->createEOperation_as_eOperations_in_EClass(m_objectValue_Class, OBJECTVALUE_OPERATION_EQUALS_VALUE);
	m_objectValue_Operation_toString = factory->createEOperation_as_eOperations_in_EClass(m_objectValue_Class, OBJECTVALUE_OPERATION_TOSTRING);
	
}

void ValuesPackageImpl::createOclMessageValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_oclMessageValue_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, OCLMESSAGEVALUE_CLASS);
	m_oclMessageValue_Attribute_isAsyncOperation = factory->createEAttribute_as_eAttributes_in_EClas(m_oclMessageValue_Class, OCLMESSAGEVALUE_ATTRIBUTE_ISASYNCOPERATION);
	m_oclMessageValue_Attribute_isSignal = factory->createEAttribute_as_eAttributes_in_EClas(m_oclMessageValue_Class, OCLMESSAGEVALUE_ATTRIBUTE_ISSIGNAL);
	m_oclMessageValue_Attribute_isSyncOperation = factory->createEAttribute_as_eAttributes_in_EClas(m_oclMessageValue_Class, OCLMESSAGEVALUE_ATTRIBUTE_ISSYNCOPERATION);
	m_oclMessageValue_Attribute_name = factory->createEAttribute_as_eAttributes_in_EClas(m_oclMessageValue_Class, OCLMESSAGEVALUE_ATTRIBUTE_NAME);
	
	m_oclMessageValue_Attribute_arguments = factory->createEReference_as_eReferences_in_EClass(m_oclMessageValue_Class, OCLMESSAGEVALUE_ATTRIBUTE_ARGUMENTS);
	m_oclMessageValue_Attribute_returnMessage = factory->createEReference_as_eReferences_in_EClass(m_oclMessageValue_Class, OCLMESSAGEVALUE_ATTRIBUTE_RETURNMESSAGE);
	m_oclMessageValue_Attribute_source = factory->createEReference_as_eReferences_in_EClass(m_oclMessageValue_Class, OCLMESSAGEVALUE_ATTRIBUTE_SOURCE);
	m_oclMessageValue_Attribute_target = factory->createEReference_as_eReferences_in_EClass(m_oclMessageValue_Class, OCLMESSAGEVALUE_ATTRIBUTE_TARGET);
	
	m_oclMessageValue_Operation_toString = factory->createEOperation_as_eOperations_in_EClass(m_oclMessageValue_Class, OCLMESSAGEVALUE_OPERATION_TOSTRING);
	
}

void ValuesPackageImpl::createOclVoidValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_oclVoidValue_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, OCLVOIDVALUE_CLASS);
	
	
	m_oclVoidValue_Operation_equals_Value = factory->createEOperation_as_eOperations_in_EClass(m_oclVoidValue_Class, OCLVOIDVALUE_OPERATION_EQUALS_VALUE);
	m_oclVoidValue_Operation_toString = factory->createEOperation_as_eOperations_in_EClass(m_oclVoidValue_Class, OCLVOIDVALUE_OPERATION_TOSTRING);
	
}

void ValuesPackageImpl::createOrderedSetTypeValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_orderedSetTypeValue_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ORDEREDSETTYPEVALUE_CLASS);
	
	
	m_orderedSetTypeValue_Operation_addValue_Value = factory->createEOperation_as_eOperations_in_EClass(m_orderedSetTypeValue_Class, ORDEREDSETTYPEVALUE_OPERATION_ADDVALUE_VALUE);
	
}

void ValuesPackageImpl::createSequenceTypeValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_sequenceTypeValue_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, SEQUENCETYPEVALUE_CLASS);
	
	
	m_sequenceTypeValue_Operation_addValue_Value = factory->createEOperation_as_eOperations_in_EClass(m_sequenceTypeValue_Class, SEQUENCETYPEVALUE_OPERATION_ADDVALUE_VALUE);
	
}

void ValuesPackageImpl::createSetTypeValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_setTypeValue_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, SETTYPEVALUE_CLASS);
	
	
	m_setTypeValue_Operation_addValue_Value = factory->createEOperation_as_eOperations_in_EClass(m_setTypeValue_Class, SETTYPEVALUE_OPERATION_ADDVALUE_VALUE);
	
}

void ValuesPackageImpl::createStaticValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_staticValue_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, STATICVALUE_CLASS);
	
	
	
}

void ValuesPackageImpl::createTupleValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_tupleValue_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, TUPLEVALUE_CLASS);
	
	m_tupleValue_Attribute_elements = factory->createEReference_as_eReferences_in_EClass(m_tupleValue_Class, TUPLEVALUE_ATTRIBUTE_ELEMENTS);
	m_tupleValue_Attribute_model = factory->createEReference_as_eReferences_in_EClass(m_tupleValue_Class, TUPLEVALUE_ATTRIBUTE_MODEL);
	
	m_tupleValue_Operation_equals_Value = factory->createEOperation_as_eOperations_in_EClass(m_tupleValue_Class, TUPLEVALUE_OPERATION_EQUALS_VALUE);
	m_tupleValue_Operation_toString = factory->createEOperation_as_eOperations_in_EClass(m_tupleValue_Class, TUPLEVALUE_OPERATION_TOSTRING);
	
}

void ValuesPackageImpl::createUndefinedValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_undefinedValue_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, UNDEFINEDVALUE_CLASS);
	
	
	m_undefinedValue_Operation_equals_Value = factory->createEOperation_as_eOperations_in_EClass(m_undefinedValue_Class, UNDEFINEDVALUE_OPERATION_EQUALS_VALUE);
	m_undefinedValue_Operation_toString = factory->createEOperation_as_eOperations_in_EClass(m_undefinedValue_Class, UNDEFINEDVALUE_OPERATION_TOSTRING);
	
}

void ValuesPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}
