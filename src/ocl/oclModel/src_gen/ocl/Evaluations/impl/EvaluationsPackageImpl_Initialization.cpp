#include "ocl/Evaluations/impl/EvaluationsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EParameter.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "ocl/Expressions/ExpressionsPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "ocl/oclPackage.hpp"


using namespace ocl::Evaluations;

void EvaluationsPackageImpl::initializePackageContents()
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
	m_associationClassCallExpEval_Class->getESuperTypes()->push_back(getNavigationCallExpEval_Class());
	m_associationEndCallExpEval_Class->getESuperTypes()->push_back(getNavigationCallExpEval_Class());
	m_attributeCallExpEval_Class->getESuperTypes()->push_back(getModelPropertyCallExpEval_Class());
	m_booleanLiteralExpEval_Class->getESuperTypes()->push_back(getPrimitiveLiteralExpEval_Class());
	m_collectionItemEval_Class->getESuperTypes()->push_back(getCollectionLiteralPartEval_Class());
	m_collectionLiteralExpEval_Class->getESuperTypes()->push_back(getLiteralExpEval_Class());
	m_collectionLiteralPartEval_Class->getESuperTypes()->push_back(getOclExpEval_Class());
	m_collectionRangeEval_Class->getESuperTypes()->push_back(getCollectionLiteralPartEval_Class());
	m_enumLiteralExpEval_Class->getESuperTypes()->push_back(getLiteralExpEval_Class());
	m_evalEnvironment_Class->getESuperTypes()->push_back(ecore::ecorePackage::eInstance()->getETypedElement_Class());
	m_evalNameSpace_Class->getESuperTypes()->push_back(getOclExpEval_Class());
	m_expressionInOclEval_Class->getESuperTypes()->push_back(ecore::ecorePackage::eInstance()->getETypedElement_Class());
	m_ifExpEval_Class->getESuperTypes()->push_back(getOclExpEval_Class());
	m_integerLiteralExpEval_Class->getESuperTypes()->push_back(getNumericLiteralExpEval_Class());
	m_iterateExpEval_Class->getESuperTypes()->push_back(getLoopExpEval_Class());
	m_iteratorExpEval_Class->getESuperTypes()->push_back(getLoopExpEval_Class());
	m_letExpEval_Class->getESuperTypes()->push_back(getOclExpEval_Class());
	m_literalExpEval_Class->getESuperTypes()->push_back(getOclExpEval_Class());
	m_loopExpEval_Class->getESuperTypes()->push_back(getPropertyCallExpEval_Class());
	m_modelPropertyCallExpEval_Class->getESuperTypes()->push_back(getPropertyCallExpEval_Class());
	m_nameValueBinding_Class->getESuperTypes()->push_back(ecore::ecorePackage::eInstance()->getETypedElement_Class());
	m_navigationCallExpEval_Class->getESuperTypes()->push_back(getModelPropertyCallExpEval_Class());
	m_numericLiteralExpEval_Class->getESuperTypes()->push_back(getPrimitiveLiteralExpEval_Class());
	m_oclExpEval_Class->getESuperTypes()->push_back(ecore::ecorePackage::eInstance()->getETypedElement_Class());
	m_oclMessageArgEval_Class->getESuperTypes()->push_back(getOclExpEval_Class());
	m_oclMessageExpEval_Class->getESuperTypes()->push_back(getOclExpEval_Class());
	m_operationCallExpEval_Class->getESuperTypes()->push_back(getModelPropertyCallExpEval_Class());
	m_primitiveLiteralExpEval_Class->getESuperTypes()->push_back(getLiteralExpEval_Class());
	m_propertyCallExpEval_Class->getESuperTypes()->push_back(getOclExpEval_Class());
	m_realLiteralExpEval_Class->getESuperTypes()->push_back(getNumericLiteralExpEval_Class());
	m_stringLiteralExpEval_Class->getESuperTypes()->push_back(getPrimitiveLiteralExpEval_Class());
	m_tupleLiteralExpEval_Class->getESuperTypes()->push_back(getLiteralExpEval_Class());
	m_tupleLiteralExpPartEval_Class->getESuperTypes()->push_back(getOclExpEval_Class());
	m_unlimitedNaturalLiteralExpEval_Class->getESuperTypes()->push_back(getNumericLiteralExpEval_Class());
	m_unspecifiedValueExpEval_Class->getESuperTypes()->push_back(getOclExpEval_Class());
	m_variableDeclEval_Class->getESuperTypes()->push_back(getOclExpEval_Class());
	m_variableExpEval_Class->getESuperTypes()->push_back(getOclExpEval_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeAssociationClassCallExpEvalContent();
	initializeAssociationEndCallExpEvalContent();
	initializeAttributeCallExpEvalContent();
	initializeBooleanLiteralExpEvalContent();
	initializeCollectionItemEvalContent();
	initializeCollectionLiteralExpEvalContent();
	initializeCollectionLiteralPartEvalContent();
	initializeCollectionRangeEvalContent();
	initializeEnumLiteralExpEvalContent();
	initializeEvalEnvironmentContent();
	initializeEvalNameSpaceContent();
	initializeExpressionInOclEvalContent();
	initializeIfExpEvalContent();
	initializeIntegerLiteralExpEvalContent();
	initializeIterateExpEvalContent();
	initializeIteratorExpEvalContent();
	initializeLetExpEvalContent();
	initializeLiteralExpEvalContent();
	initializeLoopExpEvalContent();
	initializeModelPropertyCallExpEvalContent();
	initializeNameValueBindingContent();
	initializeNavigationCallExpEvalContent();
	initializeNumericLiteralExpEvalContent();
	initializeOclExpEvalContent();
	initializeOclMessageArgEvalContent();
	initializeOclMessageExpEvalContent();
	initializeOperationCallExpEvalContent();
	initializePrimitiveLiteralExpEvalContent();
	initializePropertyCallExpEvalContent();
	initializeRealLiteralExpEvalContent();
	initializeStringLiteralExpEvalContent();
	initializeTupleLiteralExpEvalContent();
	initializeTupleLiteralExpPartEvalContent();
	initializeUnlimitedNaturalLiteralExpEvalContent();
	initializeUnspecifiedValueExpEvalContent();
	initializeVariableDeclEvalContent();
	initializeVariableExpEvalContent();

	initializePackageEDataTypes();

}

void EvaluationsPackageImpl::initializeAssociationClassCallExpEvalContent()
{
	m_associationClassCallExpEval_Class->setName("AssociationClassCallExpEval");
	m_associationClassCallExpEval_Class->setAbstract(false);
	m_associationClassCallExpEval_Class->setInterface(false);
	
	m_associationClassCallExpEval_Class->_setID(ASSOCIATIONCLASSCALLEXPEVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	m_associationClassCallExpEval_Attribute_referredAssociationClass = getAssociationClassCallExpEval_Attribute_referredAssociationClass();
	m_associationClassCallExpEval_Attribute_referredAssociationClass->setName("referredAssociationClass");
	m_associationClassCallExpEval_Attribute_referredAssociationClass->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_associationClassCallExpEval_Attribute_referredAssociationClass->setLowerBound(1);
	m_associationClassCallExpEval_Attribute_referredAssociationClass->setUpperBound(1);
	m_associationClassCallExpEval_Attribute_referredAssociationClass->setTransient(false);
	m_associationClassCallExpEval_Attribute_referredAssociationClass->setVolatile(false);
	m_associationClassCallExpEval_Attribute_referredAssociationClass->setChangeable(true);
	m_associationClassCallExpEval_Attribute_referredAssociationClass->setUnsettable(false);
	m_associationClassCallExpEval_Attribute_referredAssociationClass->setUnique(true);
	m_associationClassCallExpEval_Attribute_referredAssociationClass->setDerived(false);
	m_associationClassCallExpEval_Attribute_referredAssociationClass->setOrdered(true);
	m_associationClassCallExpEval_Attribute_referredAssociationClass->setID(false);
	m_associationClassCallExpEval_Attribute_referredAssociationClass->setDefaultValueLiteral("");
	
	m_associationClassCallExpEval_Attribute_referredAssociationClass->_setID(ASSOCIATIONCLASSCALLEXPEVAL_ATTRIBUTE_REFERREDASSOCIATIONCLASS);
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializeAssociationEndCallExpEvalContent()
{
	m_associationEndCallExpEval_Class->setName("AssociationEndCallExpEval");
	m_associationEndCallExpEval_Class->setAbstract(false);
	m_associationEndCallExpEval_Class->setInterface(false);
	
	m_associationEndCallExpEval_Class->_setID(ASSOCIATIONENDCALLEXPEVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	m_associationEndCallExpEval_Attribute_referredAssociationEnd = getAssociationEndCallExpEval_Attribute_referredAssociationEnd();
	m_associationEndCallExpEval_Attribute_referredAssociationEnd->setName("referredAssociationEnd");
	m_associationEndCallExpEval_Attribute_referredAssociationEnd->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_associationEndCallExpEval_Attribute_referredAssociationEnd->setLowerBound(1);
	m_associationEndCallExpEval_Attribute_referredAssociationEnd->setUpperBound(1);
	m_associationEndCallExpEval_Attribute_referredAssociationEnd->setTransient(false);
	m_associationEndCallExpEval_Attribute_referredAssociationEnd->setVolatile(false);
	m_associationEndCallExpEval_Attribute_referredAssociationEnd->setChangeable(true);
	m_associationEndCallExpEval_Attribute_referredAssociationEnd->setUnsettable(false);
	m_associationEndCallExpEval_Attribute_referredAssociationEnd->setUnique(true);
	m_associationEndCallExpEval_Attribute_referredAssociationEnd->setDerived(false);
	m_associationEndCallExpEval_Attribute_referredAssociationEnd->setOrdered(true);
	m_associationEndCallExpEval_Attribute_referredAssociationEnd->setID(false);
	m_associationEndCallExpEval_Attribute_referredAssociationEnd->setDefaultValueLiteral("");
	
	m_associationEndCallExpEval_Attribute_referredAssociationEnd->_setID(ASSOCIATIONENDCALLEXPEVAL_ATTRIBUTE_REFERREDASSOCIATIONEND);
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializeAttributeCallExpEvalContent()
{
	m_attributeCallExpEval_Class->setName("AttributeCallExpEval");
	m_attributeCallExpEval_Class->setAbstract(false);
	m_attributeCallExpEval_Class->setInterface(false);
	
	m_attributeCallExpEval_Class->_setID(ATTRIBUTECALLEXPEVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	m_attributeCallExpEval_Attribute_referredAttribute = getAttributeCallExpEval_Attribute_referredAttribute();
	m_attributeCallExpEval_Attribute_referredAttribute->setName("referredAttribute");
	m_attributeCallExpEval_Attribute_referredAttribute->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_attributeCallExpEval_Attribute_referredAttribute->setLowerBound(1);
	m_attributeCallExpEval_Attribute_referredAttribute->setUpperBound(1);
	m_attributeCallExpEval_Attribute_referredAttribute->setTransient(false);
	m_attributeCallExpEval_Attribute_referredAttribute->setVolatile(false);
	m_attributeCallExpEval_Attribute_referredAttribute->setChangeable(true);
	m_attributeCallExpEval_Attribute_referredAttribute->setUnsettable(false);
	m_attributeCallExpEval_Attribute_referredAttribute->setUnique(true);
	m_attributeCallExpEval_Attribute_referredAttribute->setDerived(false);
	m_attributeCallExpEval_Attribute_referredAttribute->setOrdered(true);
	m_attributeCallExpEval_Attribute_referredAttribute->setID(false);
	m_attributeCallExpEval_Attribute_referredAttribute->setDefaultValueLiteral("");
	
	m_attributeCallExpEval_Attribute_referredAttribute->_setID(ATTRIBUTECALLEXPEVAL_ATTRIBUTE_REFERREDATTRIBUTE);
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializeBooleanLiteralExpEvalContent()
{
	m_booleanLiteralExpEval_Class->setName("BooleanLiteralExpEval");
	m_booleanLiteralExpEval_Class->setAbstract(false);
	m_booleanLiteralExpEval_Class->setInterface(false);
	
	m_booleanLiteralExpEval_Class->_setID(BOOLEANLITERALEXPEVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializeCollectionItemEvalContent()
{
	m_collectionItemEval_Class->setName("CollectionItemEval");
	m_collectionItemEval_Class->setAbstract(false);
	m_collectionItemEval_Class->setInterface(false);
	
	m_collectionItemEval_Class->_setID(COLLECTIONITEMEVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_collectionItemEval_Attribute_item->setName("item");
	m_collectionItemEval_Attribute_item->setEType(getOclExpEval_Class());
	m_collectionItemEval_Attribute_item->setLowerBound(1);
	m_collectionItemEval_Attribute_item->setUpperBound(1);
	m_collectionItemEval_Attribute_item->setTransient(false);
	m_collectionItemEval_Attribute_item->setVolatile(false);
	m_collectionItemEval_Attribute_item->setChangeable(true);
	m_collectionItemEval_Attribute_item->setUnsettable(false);
	m_collectionItemEval_Attribute_item->setUnique(true);
	m_collectionItemEval_Attribute_item->setDerived(false);
	m_collectionItemEval_Attribute_item->setOrdered(true);
	m_collectionItemEval_Attribute_item->setContainment(false);
	m_collectionItemEval_Attribute_item->setResolveProxies(true);
	m_collectionItemEval_Attribute_item->setDefaultValueLiteral("");	
	
	m_collectionItemEval_Attribute_item->_setID(COLLECTIONITEMEVAL_ATTRIBUTE_ITEM);
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializeCollectionLiteralExpEvalContent()
{
	m_collectionLiteralExpEval_Class->setName("CollectionLiteralExpEval");
	m_collectionLiteralExpEval_Class->setAbstract(false);
	m_collectionLiteralExpEval_Class->setInterface(false);
	
	m_collectionLiteralExpEval_Class->_setID(COLLECTIONLITERALEXPEVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_collectionLiteralExpEval_Attribute_parts->setName("parts");
	m_collectionLiteralExpEval_Attribute_parts->setEType(getCollectionLiteralPartEval_Class());
	m_collectionLiteralExpEval_Attribute_parts->setLowerBound(0);
	m_collectionLiteralExpEval_Attribute_parts->setUpperBound(-1);
	m_collectionLiteralExpEval_Attribute_parts->setTransient(false);
	m_collectionLiteralExpEval_Attribute_parts->setVolatile(false);
	m_collectionLiteralExpEval_Attribute_parts->setChangeable(true);
	m_collectionLiteralExpEval_Attribute_parts->setUnsettable(false);
	m_collectionLiteralExpEval_Attribute_parts->setUnique(false);
	m_collectionLiteralExpEval_Attribute_parts->setDerived(false);
	m_collectionLiteralExpEval_Attribute_parts->setOrdered(true);
	m_collectionLiteralExpEval_Attribute_parts->setContainment(false);
	m_collectionLiteralExpEval_Attribute_parts->setResolveProxies(true);
	m_collectionLiteralExpEval_Attribute_parts->setDefaultValueLiteral("");	
	
	m_collectionLiteralExpEval_Attribute_parts->_setID(COLLECTIONLITERALEXPEVAL_ATTRIBUTE_PARTS);
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializeCollectionLiteralPartEvalContent()
{
	m_collectionLiteralPartEval_Class->setName("CollectionLiteralPartEval");
	m_collectionLiteralPartEval_Class->setAbstract(false);
	m_collectionLiteralPartEval_Class->setInterface(false);
	
	m_collectionLiteralPartEval_Class->_setID(COLLECTIONLITERALPARTEVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_collectionLiteralPartEval_Attribute_element->setName("element");
	m_collectionLiteralPartEval_Attribute_element->setEType(ecore::ecorePackage::eInstance()->getEObject_Class());
	m_collectionLiteralPartEval_Attribute_element->setLowerBound(1);
	m_collectionLiteralPartEval_Attribute_element->setUpperBound(1);
	m_collectionLiteralPartEval_Attribute_element->setTransient(false);
	m_collectionLiteralPartEval_Attribute_element->setVolatile(false);
	m_collectionLiteralPartEval_Attribute_element->setChangeable(true);
	m_collectionLiteralPartEval_Attribute_element->setUnsettable(false);
	m_collectionLiteralPartEval_Attribute_element->setUnique(true);
	m_collectionLiteralPartEval_Attribute_element->setDerived(false);
	m_collectionLiteralPartEval_Attribute_element->setOrdered(true);
	m_collectionLiteralPartEval_Attribute_element->setContainment(false);
	m_collectionLiteralPartEval_Attribute_element->setResolveProxies(true);
	m_collectionLiteralPartEval_Attribute_element->setDefaultValueLiteral("");	
	
	m_collectionLiteralPartEval_Attribute_element->_setID(COLLECTIONLITERALPARTEVAL_ATTRIBUTE_ELEMENT);
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializeCollectionRangeEvalContent()
{
	m_collectionRangeEval_Class->setName("CollectionRangeEval");
	m_collectionRangeEval_Class->setAbstract(false);
	m_collectionRangeEval_Class->setInterface(false);
	
	m_collectionRangeEval_Class->_setID(COLLECTIONRANGEEVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_collectionRangeEval_Attribute_first->setName("first");
	m_collectionRangeEval_Attribute_first->setEType(getOclExpEval_Class());
	m_collectionRangeEval_Attribute_first->setLowerBound(1);
	m_collectionRangeEval_Attribute_first->setUpperBound(1);
	m_collectionRangeEval_Attribute_first->setTransient(false);
	m_collectionRangeEval_Attribute_first->setVolatile(false);
	m_collectionRangeEval_Attribute_first->setChangeable(true);
	m_collectionRangeEval_Attribute_first->setUnsettable(false);
	m_collectionRangeEval_Attribute_first->setUnique(true);
	m_collectionRangeEval_Attribute_first->setDerived(false);
	m_collectionRangeEval_Attribute_first->setOrdered(true);
	m_collectionRangeEval_Attribute_first->setContainment(false);
	m_collectionRangeEval_Attribute_first->setResolveProxies(true);
	m_collectionRangeEval_Attribute_first->setDefaultValueLiteral("");	
	
	m_collectionRangeEval_Attribute_first->_setID(COLLECTIONRANGEEVAL_ATTRIBUTE_FIRST);
	m_collectionRangeEval_Attribute_last->setName("last");
	m_collectionRangeEval_Attribute_last->setEType(getOclExpEval_Class());
	m_collectionRangeEval_Attribute_last->setLowerBound(1);
	m_collectionRangeEval_Attribute_last->setUpperBound(1);
	m_collectionRangeEval_Attribute_last->setTransient(false);
	m_collectionRangeEval_Attribute_last->setVolatile(false);
	m_collectionRangeEval_Attribute_last->setChangeable(true);
	m_collectionRangeEval_Attribute_last->setUnsettable(false);
	m_collectionRangeEval_Attribute_last->setUnique(true);
	m_collectionRangeEval_Attribute_last->setDerived(false);
	m_collectionRangeEval_Attribute_last->setOrdered(true);
	m_collectionRangeEval_Attribute_last->setContainment(false);
	m_collectionRangeEval_Attribute_last->setResolveProxies(true);
	m_collectionRangeEval_Attribute_last->setDefaultValueLiteral("");	
	
	m_collectionRangeEval_Attribute_last->_setID(COLLECTIONRANGEEVAL_ATTRIBUTE_LAST);
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializeEnumLiteralExpEvalContent()
{
	m_enumLiteralExpEval_Class->setName("EnumLiteralExpEval");
	m_enumLiteralExpEval_Class->setAbstract(false);
	m_enumLiteralExpEval_Class->setInterface(false);
	
	m_enumLiteralExpEval_Class->_setID(ENUMLITERALEXPEVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializeEvalEnvironmentContent()
{
	m_evalEnvironment_Class->setName("EvalEnvironment");
	m_evalEnvironment_Class->setAbstract(false);
	m_evalEnvironment_Class->setInterface(false);
	
	m_evalEnvironment_Class->_setID(EVALENVIRONMENT_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_evalEnvironment_Attribute_bindings->setName("bindings");
	m_evalEnvironment_Attribute_bindings->setEType(getNameValueBinding_Class());
	m_evalEnvironment_Attribute_bindings->setLowerBound(0);
	m_evalEnvironment_Attribute_bindings->setUpperBound(-1);
	m_evalEnvironment_Attribute_bindings->setTransient(false);
	m_evalEnvironment_Attribute_bindings->setVolatile(false);
	m_evalEnvironment_Attribute_bindings->setChangeable(true);
	m_evalEnvironment_Attribute_bindings->setUnsettable(false);
	m_evalEnvironment_Attribute_bindings->setUnique(true);
	m_evalEnvironment_Attribute_bindings->setDerived(false);
	m_evalEnvironment_Attribute_bindings->setOrdered(true);
	m_evalEnvironment_Attribute_bindings->setContainment(false);
	m_evalEnvironment_Attribute_bindings->setResolveProxies(true);
	m_evalEnvironment_Attribute_bindings->setDefaultValueLiteral("");	
	
	m_evalEnvironment_Attribute_bindings->_setID(EVALENVIRONMENT_ATTRIBUTE_BINDINGS);
	
	/*
	 * EOperations
	 */
	m_evalEnvironment_Operation_add_NameValueBinding->setName("add");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_evalEnvironment_Operation_add_NameValueBinding->setEType(unknownClass);
	}
	m_evalEnvironment_Operation_add_NameValueBinding->setLowerBound(1);
	m_evalEnvironment_Operation_add_NameValueBinding->setUpperBound(1);
	m_evalEnvironment_Operation_add_NameValueBinding->setUnique(true);
	m_evalEnvironment_Operation_add_NameValueBinding->setOrdered(false);
	
	m_evalEnvironment_Operation_add_NameValueBinding->_setID(EVALENVIRONMENT_OPERATION_ADD_NAMEVALUEBINDING);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_evalEnvironment_Operation_add_NameValueBinding);
		parameter->setName("n");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_evalEnvironment_Operation_addAll_NameValueBinding->setName("addAll");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_evalEnvironment_Operation_addAll_NameValueBinding->setEType(unknownClass);
	}
	m_evalEnvironment_Operation_addAll_NameValueBinding->setLowerBound(1);
	m_evalEnvironment_Operation_addAll_NameValueBinding->setUpperBound(1);
	m_evalEnvironment_Operation_addAll_NameValueBinding->setUnique(true);
	m_evalEnvironment_Operation_addAll_NameValueBinding->setOrdered(false);
	
	m_evalEnvironment_Operation_addAll_NameValueBinding->_setID(EVALENVIRONMENT_OPERATION_ADDALL_NAMEVALUEBINDING);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_evalEnvironment_Operation_addAll_NameValueBinding);
		parameter->setName("nvbs");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_evalEnvironment_Operation_find_EString->setName("find");
	m_evalEnvironment_Operation_find_EString->setEType(getNameValueBinding_Class());
	m_evalEnvironment_Operation_find_EString->setLowerBound(1);
	m_evalEnvironment_Operation_find_EString->setUpperBound(1);
	m_evalEnvironment_Operation_find_EString->setUnique(true);
	m_evalEnvironment_Operation_find_EString->setOrdered(false);
	
	m_evalEnvironment_Operation_find_EString->_setID(EVALENVIRONMENT_OPERATION_FIND_ESTRING);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_evalEnvironment_Operation_find_EString);
		parameter->setName("name");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_evalEnvironment_Operation_getValueOf_EString->setName("getValueOf");
	m_evalEnvironment_Operation_getValueOf_EString->setEType(ecore::ecorePackage::eInstance()->getEObject_Class());
	m_evalEnvironment_Operation_getValueOf_EString->setLowerBound(1);
	m_evalEnvironment_Operation_getValueOf_EString->setUpperBound(1);
	m_evalEnvironment_Operation_getValueOf_EString->setUnique(true);
	m_evalEnvironment_Operation_getValueOf_EString->setOrdered(false);
	
	m_evalEnvironment_Operation_getValueOf_EString->_setID(EVALENVIRONMENT_OPERATION_GETVALUEOF_ESTRING);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_evalEnvironment_Operation_getValueOf_EString);
		parameter->setName("n");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_evalEnvironment_Operation_replace_NameValueBinding->setName("replace");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_evalEnvironment_Operation_replace_NameValueBinding->setEType(unknownClass);
	}
	m_evalEnvironment_Operation_replace_NameValueBinding->setLowerBound(1);
	m_evalEnvironment_Operation_replace_NameValueBinding->setUpperBound(1);
	m_evalEnvironment_Operation_replace_NameValueBinding->setUnique(true);
	m_evalEnvironment_Operation_replace_NameValueBinding->setOrdered(false);
	
	m_evalEnvironment_Operation_replace_NameValueBinding->_setID(EVALENVIRONMENT_OPERATION_REPLACE_NAMEVALUEBINDING);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_evalEnvironment_Operation_replace_NameValueBinding);
		parameter->setName("n");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void EvaluationsPackageImpl::initializeEvalNameSpaceContent()
{
	m_evalNameSpace_Class->setName("EvalNameSpace");
	m_evalNameSpace_Class->setAbstract(false);
	m_evalNameSpace_Class->setInterface(false);
	
	m_evalNameSpace_Class->_setID(EVALNAMESPACE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializeExpressionInOclEvalContent()
{
	m_expressionInOclEval_Class->setName("ExpressionInOclEval");
	m_expressionInOclEval_Class->setAbstract(false);
	m_expressionInOclEval_Class->setInterface(false);
	
	m_expressionInOclEval_Class->_setID(EXPRESSIONINOCLEVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_expressionInOclEval_Attribute_context->setName("context");
	m_expressionInOclEval_Attribute_context->setEType(getOclExpEval_Class());
	m_expressionInOclEval_Attribute_context->setLowerBound(1);
	m_expressionInOclEval_Attribute_context->setUpperBound(1);
	m_expressionInOclEval_Attribute_context->setTransient(false);
	m_expressionInOclEval_Attribute_context->setVolatile(false);
	m_expressionInOclEval_Attribute_context->setChangeable(true);
	m_expressionInOclEval_Attribute_context->setUnsettable(false);
	m_expressionInOclEval_Attribute_context->setUnique(true);
	m_expressionInOclEval_Attribute_context->setDerived(false);
	m_expressionInOclEval_Attribute_context->setOrdered(true);
	m_expressionInOclEval_Attribute_context->setContainment(false);
	m_expressionInOclEval_Attribute_context->setResolveProxies(true);
	m_expressionInOclEval_Attribute_context->setDefaultValueLiteral("");	
	
	m_expressionInOclEval_Attribute_context->_setID(EXPRESSIONINOCLEVAL_ATTRIBUTE_CONTEXT);
	m_expressionInOclEval_Attribute_environment->setName("environment");
	m_expressionInOclEval_Attribute_environment->setEType(getEvalEnvironment_Class());
	m_expressionInOclEval_Attribute_environment->setLowerBound(0);
	m_expressionInOclEval_Attribute_environment->setUpperBound(1);
	m_expressionInOclEval_Attribute_environment->setTransient(false);
	m_expressionInOclEval_Attribute_environment->setVolatile(false);
	m_expressionInOclEval_Attribute_environment->setChangeable(true);
	m_expressionInOclEval_Attribute_environment->setUnsettable(false);
	m_expressionInOclEval_Attribute_environment->setUnique(true);
	m_expressionInOclEval_Attribute_environment->setDerived(false);
	m_expressionInOclEval_Attribute_environment->setOrdered(true);
	m_expressionInOclEval_Attribute_environment->setContainment(false);
	m_expressionInOclEval_Attribute_environment->setResolveProxies(true);
	m_expressionInOclEval_Attribute_environment->setDefaultValueLiteral("");	
	
	m_expressionInOclEval_Attribute_environment->_setID(EXPRESSIONINOCLEVAL_ATTRIBUTE_ENVIRONMENT);
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializeIfExpEvalContent()
{
	m_ifExpEval_Class->setName("IfExpEval");
	m_ifExpEval_Class->setAbstract(false);
	m_ifExpEval_Class->setInterface(false);
	
	m_ifExpEval_Class->_setID(IFEXPEVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_ifExpEval_Attribute_condition->setName("condition");
	m_ifExpEval_Attribute_condition->setEType(getOclExpEval_Class());
	m_ifExpEval_Attribute_condition->setLowerBound(1);
	m_ifExpEval_Attribute_condition->setUpperBound(1);
	m_ifExpEval_Attribute_condition->setTransient(false);
	m_ifExpEval_Attribute_condition->setVolatile(false);
	m_ifExpEval_Attribute_condition->setChangeable(true);
	m_ifExpEval_Attribute_condition->setUnsettable(false);
	m_ifExpEval_Attribute_condition->setUnique(true);
	m_ifExpEval_Attribute_condition->setDerived(false);
	m_ifExpEval_Attribute_condition->setOrdered(true);
	m_ifExpEval_Attribute_condition->setContainment(false);
	m_ifExpEval_Attribute_condition->setResolveProxies(true);
	m_ifExpEval_Attribute_condition->setDefaultValueLiteral("");	
	
	m_ifExpEval_Attribute_condition->_setID(IFEXPEVAL_ATTRIBUTE_CONDITION);
	m_ifExpEval_Attribute_elseExpression->setName("elseExpression");
	m_ifExpEval_Attribute_elseExpression->setEType(getOclExpEval_Class());
	m_ifExpEval_Attribute_elseExpression->setLowerBound(1);
	m_ifExpEval_Attribute_elseExpression->setUpperBound(1);
	m_ifExpEval_Attribute_elseExpression->setTransient(false);
	m_ifExpEval_Attribute_elseExpression->setVolatile(false);
	m_ifExpEval_Attribute_elseExpression->setChangeable(true);
	m_ifExpEval_Attribute_elseExpression->setUnsettable(false);
	m_ifExpEval_Attribute_elseExpression->setUnique(true);
	m_ifExpEval_Attribute_elseExpression->setDerived(false);
	m_ifExpEval_Attribute_elseExpression->setOrdered(true);
	m_ifExpEval_Attribute_elseExpression->setContainment(false);
	m_ifExpEval_Attribute_elseExpression->setResolveProxies(true);
	m_ifExpEval_Attribute_elseExpression->setDefaultValueLiteral("");	
	
	m_ifExpEval_Attribute_elseExpression->_setID(IFEXPEVAL_ATTRIBUTE_ELSEEXPRESSION);
	m_ifExpEval_Attribute_thenExpression->setName("thenExpression");
	m_ifExpEval_Attribute_thenExpression->setEType(getOclExpEval_Class());
	m_ifExpEval_Attribute_thenExpression->setLowerBound(1);
	m_ifExpEval_Attribute_thenExpression->setUpperBound(1);
	m_ifExpEval_Attribute_thenExpression->setTransient(false);
	m_ifExpEval_Attribute_thenExpression->setVolatile(false);
	m_ifExpEval_Attribute_thenExpression->setChangeable(true);
	m_ifExpEval_Attribute_thenExpression->setUnsettable(false);
	m_ifExpEval_Attribute_thenExpression->setUnique(true);
	m_ifExpEval_Attribute_thenExpression->setDerived(false);
	m_ifExpEval_Attribute_thenExpression->setOrdered(true);
	m_ifExpEval_Attribute_thenExpression->setContainment(false);
	m_ifExpEval_Attribute_thenExpression->setResolveProxies(true);
	m_ifExpEval_Attribute_thenExpression->setDefaultValueLiteral("");	
	
	m_ifExpEval_Attribute_thenExpression->_setID(IFEXPEVAL_ATTRIBUTE_THENEXPRESSION);
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializeIntegerLiteralExpEvalContent()
{
	m_integerLiteralExpEval_Class->setName("IntegerLiteralExpEval");
	m_integerLiteralExpEval_Class->setAbstract(false);
	m_integerLiteralExpEval_Class->setInterface(false);
	
	m_integerLiteralExpEval_Class->_setID(INTEGERLITERALEXPEVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializeIterateExpEvalContent()
{
	m_iterateExpEval_Class->setName("IterateExpEval");
	m_iterateExpEval_Class->setAbstract(false);
	m_iterateExpEval_Class->setInterface(false);
	
	m_iterateExpEval_Class->_setID(ITERATEEXPEVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_iterateExpEval_Attribute_result->setName("result");
	m_iterateExpEval_Attribute_result->setEType(getVariableDeclEval_Class());
	m_iterateExpEval_Attribute_result->setLowerBound(1);
	m_iterateExpEval_Attribute_result->setUpperBound(1);
	m_iterateExpEval_Attribute_result->setTransient(false);
	m_iterateExpEval_Attribute_result->setVolatile(false);
	m_iterateExpEval_Attribute_result->setChangeable(true);
	m_iterateExpEval_Attribute_result->setUnsettable(false);
	m_iterateExpEval_Attribute_result->setUnique(true);
	m_iterateExpEval_Attribute_result->setDerived(false);
	m_iterateExpEval_Attribute_result->setOrdered(true);
	m_iterateExpEval_Attribute_result->setContainment(false);
	m_iterateExpEval_Attribute_result->setResolveProxies(true);
	m_iterateExpEval_Attribute_result->setDefaultValueLiteral("");	
	
	m_iterateExpEval_Attribute_result->_setID(ITERATEEXPEVAL_ATTRIBUTE_RESULT);
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializeIteratorExpEvalContent()
{
	m_iteratorExpEval_Class->setName("IteratorExpEval");
	m_iteratorExpEval_Class->setAbstract(false);
	m_iteratorExpEval_Class->setInterface(false);
	
	m_iteratorExpEval_Class->_setID(ITERATOREXPEVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializeLetExpEvalContent()
{
	m_letExpEval_Class->setName("LetExpEval");
	m_letExpEval_Class->setAbstract(false);
	m_letExpEval_Class->setInterface(false);
	
	m_letExpEval_Class->_setID(LETEXPEVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	m_letExpEval_Attribute_variable = getLetExpEval_Attribute_variable();
	m_letExpEval_Attribute_variable->setName("variable");
	m_letExpEval_Attribute_variable->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_letExpEval_Attribute_variable->setLowerBound(1);
	m_letExpEval_Attribute_variable->setUpperBound(1);
	m_letExpEval_Attribute_variable->setTransient(false);
	m_letExpEval_Attribute_variable->setVolatile(false);
	m_letExpEval_Attribute_variable->setChangeable(true);
	m_letExpEval_Attribute_variable->setUnsettable(false);
	m_letExpEval_Attribute_variable->setUnique(true);
	m_letExpEval_Attribute_variable->setDerived(false);
	m_letExpEval_Attribute_variable->setOrdered(true);
	m_letExpEval_Attribute_variable->setID(false);
	m_letExpEval_Attribute_variable->setDefaultValueLiteral("");
	
	m_letExpEval_Attribute_variable->_setID(LETEXPEVAL_ATTRIBUTE_VARIABLE);
	
	/*
	 * EReferences
	 */
	m_letExpEval_Attribute_in->setName("in");
	m_letExpEval_Attribute_in->setEType(getOclExpEval_Class());
	m_letExpEval_Attribute_in->setLowerBound(1);
	m_letExpEval_Attribute_in->setUpperBound(1);
	m_letExpEval_Attribute_in->setTransient(false);
	m_letExpEval_Attribute_in->setVolatile(false);
	m_letExpEval_Attribute_in->setChangeable(true);
	m_letExpEval_Attribute_in->setUnsettable(false);
	m_letExpEval_Attribute_in->setUnique(true);
	m_letExpEval_Attribute_in->setDerived(false);
	m_letExpEval_Attribute_in->setOrdered(true);
	m_letExpEval_Attribute_in->setContainment(false);
	m_letExpEval_Attribute_in->setResolveProxies(true);
	m_letExpEval_Attribute_in->setDefaultValueLiteral("");	
	
	m_letExpEval_Attribute_in->_setID(LETEXPEVAL_ATTRIBUTE_IN);
	m_letExpEval_Attribute_initExpression->setName("initExpression");
	m_letExpEval_Attribute_initExpression->setEType(getOclExpEval_Class());
	m_letExpEval_Attribute_initExpression->setLowerBound(0);
	m_letExpEval_Attribute_initExpression->setUpperBound(1);
	m_letExpEval_Attribute_initExpression->setTransient(false);
	m_letExpEval_Attribute_initExpression->setVolatile(false);
	m_letExpEval_Attribute_initExpression->setChangeable(true);
	m_letExpEval_Attribute_initExpression->setUnsettable(false);
	m_letExpEval_Attribute_initExpression->setUnique(true);
	m_letExpEval_Attribute_initExpression->setDerived(false);
	m_letExpEval_Attribute_initExpression->setOrdered(true);
	m_letExpEval_Attribute_initExpression->setContainment(false);
	m_letExpEval_Attribute_initExpression->setResolveProxies(true);
	m_letExpEval_Attribute_initExpression->setDefaultValueLiteral("");	
	
	m_letExpEval_Attribute_initExpression->_setID(LETEXPEVAL_ATTRIBUTE_INITEXPRESSION);
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializeLiteralExpEvalContent()
{
	m_literalExpEval_Class->setName("LiteralExpEval");
	m_literalExpEval_Class->setAbstract(false);
	m_literalExpEval_Class->setInterface(false);
	
	m_literalExpEval_Class->_setID(LITERALEXPEVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializeLoopExpEvalContent()
{
	m_loopExpEval_Class->setName("LoopExpEval");
	m_loopExpEval_Class->setAbstract(false);
	m_loopExpEval_Class->setInterface(false);
	
	m_loopExpEval_Class->_setID(LOOPEXPEVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	m_loopExpEval_Attribute_iterators = getLoopExpEval_Attribute_iterators();
	m_loopExpEval_Attribute_iterators->setName("iterators");
	m_loopExpEval_Attribute_iterators->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_loopExpEval_Attribute_iterators->setLowerBound(1);
	m_loopExpEval_Attribute_iterators->setUpperBound(-1);
	m_loopExpEval_Attribute_iterators->setTransient(false);
	m_loopExpEval_Attribute_iterators->setVolatile(false);
	m_loopExpEval_Attribute_iterators->setChangeable(true);
	m_loopExpEval_Attribute_iterators->setUnsettable(false);
	m_loopExpEval_Attribute_iterators->setUnique(true);
	m_loopExpEval_Attribute_iterators->setDerived(false);
	m_loopExpEval_Attribute_iterators->setOrdered(true);
	m_loopExpEval_Attribute_iterators->setID(false);
	m_loopExpEval_Attribute_iterators->setDefaultValueLiteral("");
	
	m_loopExpEval_Attribute_iterators->_setID(LOOPEXPEVAL_ATTRIBUTE_ITERATORS);
	
	/*
	 * EReferences
	 */
	m_loopExpEval_Attribute_bodyEvals->setName("bodyEvals");
	m_loopExpEval_Attribute_bodyEvals->setEType(getOclExpEval_Class());
	m_loopExpEval_Attribute_bodyEvals->setLowerBound(1);
	m_loopExpEval_Attribute_bodyEvals->setUpperBound(-1);
	m_loopExpEval_Attribute_bodyEvals->setTransient(false);
	m_loopExpEval_Attribute_bodyEvals->setVolatile(false);
	m_loopExpEval_Attribute_bodyEvals->setChangeable(true);
	m_loopExpEval_Attribute_bodyEvals->setUnsettable(false);
	m_loopExpEval_Attribute_bodyEvals->setUnique(true);
	m_loopExpEval_Attribute_bodyEvals->setDerived(false);
	m_loopExpEval_Attribute_bodyEvals->setOrdered(true);
	m_loopExpEval_Attribute_bodyEvals->setContainment(false);
	m_loopExpEval_Attribute_bodyEvals->setResolveProxies(true);
	m_loopExpEval_Attribute_bodyEvals->setDefaultValueLiteral("");	
	
	m_loopExpEval_Attribute_bodyEvals->_setID(LOOPEXPEVAL_ATTRIBUTE_BODYEVALS);
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializeModelPropertyCallExpEvalContent()
{
	m_modelPropertyCallExpEval_Class->setName("ModelPropertyCallExpEval");
	m_modelPropertyCallExpEval_Class->setAbstract(false);
	m_modelPropertyCallExpEval_Class->setInterface(false);
	
	m_modelPropertyCallExpEval_Class->_setID(MODELPROPERTYCALLEXPEVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_modelPropertyCallExpEval_Operation_atPre->setName("atPre");
	m_modelPropertyCallExpEval_Operation_atPre->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_modelPropertyCallExpEval_Operation_atPre->setLowerBound(0);
	m_modelPropertyCallExpEval_Operation_atPre->setUpperBound(1);
	m_modelPropertyCallExpEval_Operation_atPre->setUnique(true);
	m_modelPropertyCallExpEval_Operation_atPre->setOrdered(true);
	
	m_modelPropertyCallExpEval_Operation_atPre->_setID(MODELPROPERTYCALLEXPEVAL_OPERATION_ATPRE);
	
	
	
}

void EvaluationsPackageImpl::initializeNameValueBindingContent()
{
	m_nameValueBinding_Class->setName("NameValueBinding");
	m_nameValueBinding_Class->setAbstract(false);
	m_nameValueBinding_Class->setInterface(false);
	
	m_nameValueBinding_Class->_setID(NAMEVALUEBINDING_CLASS);
	
	/*
	 * EAttributes
	 */
	m_nameValueBinding_Attribute_name = getNameValueBinding_Attribute_name();
	m_nameValueBinding_Attribute_name->setName("name");
	m_nameValueBinding_Attribute_name->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
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
	m_nameValueBinding_Attribute_name->setDefaultValueLiteral("");
	
	m_nameValueBinding_Attribute_name->_setID(NAMEVALUEBINDING_ATTRIBUTE_NAME);
	
	/*
	 * EReferences
	 */
	m_nameValueBinding_Attribute_value->setName("value");
	m_nameValueBinding_Attribute_value->setEType(ecore::ecorePackage::eInstance()->getEObject_Class());
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
	m_nameValueBinding_Attribute_value->setDefaultValueLiteral("");	
	
	m_nameValueBinding_Attribute_value->_setID(NAMEVALUEBINDING_ATTRIBUTE_VALUE);
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializeNavigationCallExpEvalContent()
{
	m_navigationCallExpEval_Class->setName("NavigationCallExpEval");
	m_navigationCallExpEval_Class->setAbstract(false);
	m_navigationCallExpEval_Class->setInterface(false);
	
	m_navigationCallExpEval_Class->_setID(NAVIGATIONCALLEXPEVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	m_navigationCallExpEval_Attribute_navigationSource = getNavigationCallExpEval_Attribute_navigationSource();
	m_navigationCallExpEval_Attribute_navigationSource->setName("navigationSource");
	m_navigationCallExpEval_Attribute_navigationSource->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_navigationCallExpEval_Attribute_navigationSource->setLowerBound(1);
	m_navigationCallExpEval_Attribute_navigationSource->setUpperBound(1);
	m_navigationCallExpEval_Attribute_navigationSource->setTransient(false);
	m_navigationCallExpEval_Attribute_navigationSource->setVolatile(false);
	m_navigationCallExpEval_Attribute_navigationSource->setChangeable(true);
	m_navigationCallExpEval_Attribute_navigationSource->setUnsettable(false);
	m_navigationCallExpEval_Attribute_navigationSource->setUnique(true);
	m_navigationCallExpEval_Attribute_navigationSource->setDerived(false);
	m_navigationCallExpEval_Attribute_navigationSource->setOrdered(true);
	m_navigationCallExpEval_Attribute_navigationSource->setID(false);
	m_navigationCallExpEval_Attribute_navigationSource->setDefaultValueLiteral("");
	
	m_navigationCallExpEval_Attribute_navigationSource->_setID(NAVIGATIONCALLEXPEVAL_ATTRIBUTE_NAVIGATIONSOURCE);
	
	/*
	 * EReferences
	 */
	m_navigationCallExpEval_Attribute_qualifiers->setName("qualifiers");
	m_navigationCallExpEval_Attribute_qualifiers->setEType(getOclExpEval_Class());
	m_navigationCallExpEval_Attribute_qualifiers->setLowerBound(0);
	m_navigationCallExpEval_Attribute_qualifiers->setUpperBound(-1);
	m_navigationCallExpEval_Attribute_qualifiers->setTransient(false);
	m_navigationCallExpEval_Attribute_qualifiers->setVolatile(false);
	m_navigationCallExpEval_Attribute_qualifiers->setChangeable(true);
	m_navigationCallExpEval_Attribute_qualifiers->setUnsettable(false);
	m_navigationCallExpEval_Attribute_qualifiers->setUnique(false);
	m_navigationCallExpEval_Attribute_qualifiers->setDerived(false);
	m_navigationCallExpEval_Attribute_qualifiers->setOrdered(true);
	m_navigationCallExpEval_Attribute_qualifiers->setContainment(false);
	m_navigationCallExpEval_Attribute_qualifiers->setResolveProxies(true);
	m_navigationCallExpEval_Attribute_qualifiers->setDefaultValueLiteral("");	
	
	m_navigationCallExpEval_Attribute_qualifiers->_setID(NAVIGATIONCALLEXPEVAL_ATTRIBUTE_QUALIFIERS);
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializeNumericLiteralExpEvalContent()
{
	m_numericLiteralExpEval_Class->setName("NumericLiteralExpEval");
	m_numericLiteralExpEval_Class->setAbstract(false);
	m_numericLiteralExpEval_Class->setInterface(false);
	
	m_numericLiteralExpEval_Class->_setID(NUMERICLITERALEXPEVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializeOclExpEvalContent()
{
	m_oclExpEval_Class->setName("OclExpEval");
	m_oclExpEval_Class->setAbstract(false);
	m_oclExpEval_Class->setInterface(false);
	
	m_oclExpEval_Class->_setID(OCLEXPEVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_oclExpEval_Attribute_beforeEnvironment->setName("beforeEnvironment");
	m_oclExpEval_Attribute_beforeEnvironment->setEType(getEvalEnvironment_Class());
	m_oclExpEval_Attribute_beforeEnvironment->setLowerBound(0);
	m_oclExpEval_Attribute_beforeEnvironment->setUpperBound(1);
	m_oclExpEval_Attribute_beforeEnvironment->setTransient(false);
	m_oclExpEval_Attribute_beforeEnvironment->setVolatile(false);
	m_oclExpEval_Attribute_beforeEnvironment->setChangeable(true);
	m_oclExpEval_Attribute_beforeEnvironment->setUnsettable(false);
	m_oclExpEval_Attribute_beforeEnvironment->setUnique(true);
	m_oclExpEval_Attribute_beforeEnvironment->setDerived(false);
	m_oclExpEval_Attribute_beforeEnvironment->setOrdered(true);
	m_oclExpEval_Attribute_beforeEnvironment->setContainment(false);
	m_oclExpEval_Attribute_beforeEnvironment->setResolveProxies(true);
	m_oclExpEval_Attribute_beforeEnvironment->setDefaultValueLiteral("");	
	
	m_oclExpEval_Attribute_beforeEnvironment->_setID(OCLEXPEVAL_ATTRIBUTE_BEFOREENVIRONMENT);
	m_oclExpEval_Attribute_environment->setName("environment");
	m_oclExpEval_Attribute_environment->setEType(getEvalEnvironment_Class());
	m_oclExpEval_Attribute_environment->setLowerBound(1);
	m_oclExpEval_Attribute_environment->setUpperBound(1);
	m_oclExpEval_Attribute_environment->setTransient(false);
	m_oclExpEval_Attribute_environment->setVolatile(false);
	m_oclExpEval_Attribute_environment->setChangeable(true);
	m_oclExpEval_Attribute_environment->setUnsettable(false);
	m_oclExpEval_Attribute_environment->setUnique(true);
	m_oclExpEval_Attribute_environment->setDerived(false);
	m_oclExpEval_Attribute_environment->setOrdered(true);
	m_oclExpEval_Attribute_environment->setContainment(false);
	m_oclExpEval_Attribute_environment->setResolveProxies(true);
	m_oclExpEval_Attribute_environment->setDefaultValueLiteral("");	
	
	m_oclExpEval_Attribute_environment->_setID(OCLEXPEVAL_ATTRIBUTE_ENVIRONMENT);
	m_oclExpEval_Attribute_model->setName("model");
	m_oclExpEval_Attribute_model->setEType(ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Class());
	m_oclExpEval_Attribute_model->setLowerBound(1);
	m_oclExpEval_Attribute_model->setUpperBound(1);
	m_oclExpEval_Attribute_model->setTransient(false);
	m_oclExpEval_Attribute_model->setVolatile(false);
	m_oclExpEval_Attribute_model->setChangeable(true);
	m_oclExpEval_Attribute_model->setUnsettable(false);
	m_oclExpEval_Attribute_model->setUnique(true);
	m_oclExpEval_Attribute_model->setDerived(false);
	m_oclExpEval_Attribute_model->setOrdered(true);
	m_oclExpEval_Attribute_model->setContainment(false);
	m_oclExpEval_Attribute_model->setResolveProxies(true);
	m_oclExpEval_Attribute_model->setDefaultValueLiteral("");	
	m_oclExpEval_Attribute_model->setEOpposite(ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Attribute_instance());
	
	m_oclExpEval_Attribute_model->_setID(OCLEXPEVAL_ATTRIBUTE_MODEL);
	m_oclExpEval_Attribute_resultValue->setName("resultValue");
	m_oclExpEval_Attribute_resultValue->setEType(ecore::ecorePackage::eInstance()->getEObject_Class());
	m_oclExpEval_Attribute_resultValue->setLowerBound(1);
	m_oclExpEval_Attribute_resultValue->setUpperBound(1);
	m_oclExpEval_Attribute_resultValue->setTransient(false);
	m_oclExpEval_Attribute_resultValue->setVolatile(false);
	m_oclExpEval_Attribute_resultValue->setChangeable(true);
	m_oclExpEval_Attribute_resultValue->setUnsettable(false);
	m_oclExpEval_Attribute_resultValue->setUnique(true);
	m_oclExpEval_Attribute_resultValue->setDerived(false);
	m_oclExpEval_Attribute_resultValue->setOrdered(true);
	m_oclExpEval_Attribute_resultValue->setContainment(false);
	m_oclExpEval_Attribute_resultValue->setResolveProxies(true);
	m_oclExpEval_Attribute_resultValue->setDefaultValueLiteral("");	
	
	m_oclExpEval_Attribute_resultValue->_setID(OCLEXPEVAL_ATTRIBUTE_RESULTVALUE);
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializeOclMessageArgEvalContent()
{
	m_oclMessageArgEval_Class->setName("OclMessageArgEval");
	m_oclMessageArgEval_Class->setAbstract(false);
	m_oclMessageArgEval_Class->setInterface(false);
	
	m_oclMessageArgEval_Class->_setID(OCLMESSAGEARGEVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_oclMessageArgEval_Attribute_expression->setName("expression");
	m_oclMessageArgEval_Attribute_expression->setEType(getOclExpEval_Class());
	m_oclMessageArgEval_Attribute_expression->setLowerBound(0);
	m_oclMessageArgEval_Attribute_expression->setUpperBound(1);
	m_oclMessageArgEval_Attribute_expression->setTransient(false);
	m_oclMessageArgEval_Attribute_expression->setVolatile(false);
	m_oclMessageArgEval_Attribute_expression->setChangeable(true);
	m_oclMessageArgEval_Attribute_expression->setUnsettable(false);
	m_oclMessageArgEval_Attribute_expression->setUnique(true);
	m_oclMessageArgEval_Attribute_expression->setDerived(false);
	m_oclMessageArgEval_Attribute_expression->setOrdered(true);
	m_oclMessageArgEval_Attribute_expression->setContainment(false);
	m_oclMessageArgEval_Attribute_expression->setResolveProxies(true);
	m_oclMessageArgEval_Attribute_expression->setDefaultValueLiteral("");	
	
	m_oclMessageArgEval_Attribute_expression->_setID(OCLMESSAGEARGEVAL_ATTRIBUTE_EXPRESSION);
	m_oclMessageArgEval_Attribute_unspecified->setName("unspecified");
	m_oclMessageArgEval_Attribute_unspecified->setEType(getUnspecifiedValueExpEval_Class());
	m_oclMessageArgEval_Attribute_unspecified->setLowerBound(0);
	m_oclMessageArgEval_Attribute_unspecified->setUpperBound(1);
	m_oclMessageArgEval_Attribute_unspecified->setTransient(false);
	m_oclMessageArgEval_Attribute_unspecified->setVolatile(false);
	m_oclMessageArgEval_Attribute_unspecified->setChangeable(true);
	m_oclMessageArgEval_Attribute_unspecified->setUnsettable(false);
	m_oclMessageArgEval_Attribute_unspecified->setUnique(true);
	m_oclMessageArgEval_Attribute_unspecified->setDerived(false);
	m_oclMessageArgEval_Attribute_unspecified->setOrdered(true);
	m_oclMessageArgEval_Attribute_unspecified->setContainment(false);
	m_oclMessageArgEval_Attribute_unspecified->setResolveProxies(true);
	m_oclMessageArgEval_Attribute_unspecified->setDefaultValueLiteral("");	
	
	m_oclMessageArgEval_Attribute_unspecified->_setID(OCLMESSAGEARGEVAL_ATTRIBUTE_UNSPECIFIED);
	m_oclMessageArgEval_Attribute_variable->setName("variable");
	m_oclMessageArgEval_Attribute_variable->setEType(getOclExpEval_Class());
	m_oclMessageArgEval_Attribute_variable->setLowerBound(0);
	m_oclMessageArgEval_Attribute_variable->setUpperBound(1);
	m_oclMessageArgEval_Attribute_variable->setTransient(false);
	m_oclMessageArgEval_Attribute_variable->setVolatile(false);
	m_oclMessageArgEval_Attribute_variable->setChangeable(true);
	m_oclMessageArgEval_Attribute_variable->setUnsettable(false);
	m_oclMessageArgEval_Attribute_variable->setUnique(true);
	m_oclMessageArgEval_Attribute_variable->setDerived(false);
	m_oclMessageArgEval_Attribute_variable->setOrdered(true);
	m_oclMessageArgEval_Attribute_variable->setContainment(false);
	m_oclMessageArgEval_Attribute_variable->setResolveProxies(true);
	m_oclMessageArgEval_Attribute_variable->setDefaultValueLiteral("");	
	
	m_oclMessageArgEval_Attribute_variable->_setID(OCLMESSAGEARGEVAL_ATTRIBUTE_VARIABLE);
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializeOclMessageExpEvalContent()
{
	m_oclMessageExpEval_Class->setName("OclMessageExpEval");
	m_oclMessageExpEval_Class->setAbstract(false);
	m_oclMessageExpEval_Class->setInterface(false);
	
	m_oclMessageExpEval_Class->_setID(OCLMESSAGEEXPEVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	m_oclMessageExpEval_Attribute_name = getOclMessageExpEval_Attribute_name();
	m_oclMessageExpEval_Attribute_name->setName("name");
	m_oclMessageExpEval_Attribute_name->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_oclMessageExpEval_Attribute_name->setLowerBound(0);
	m_oclMessageExpEval_Attribute_name->setUpperBound(1);
	m_oclMessageExpEval_Attribute_name->setTransient(false);
	m_oclMessageExpEval_Attribute_name->setVolatile(false);
	m_oclMessageExpEval_Attribute_name->setChangeable(true);
	m_oclMessageExpEval_Attribute_name->setUnsettable(false);
	m_oclMessageExpEval_Attribute_name->setUnique(true);
	m_oclMessageExpEval_Attribute_name->setDerived(false);
	m_oclMessageExpEval_Attribute_name->setOrdered(true);
	m_oclMessageExpEval_Attribute_name->setID(false);
	m_oclMessageExpEval_Attribute_name->setDefaultValueLiteral("");
	
	m_oclMessageExpEval_Attribute_name->_setID(OCLMESSAGEEXPEVAL_ATTRIBUTE_NAME);
	
	/*
	 * EReferences
	 */
	m_oclMessageExpEval_Attribute_arguments->setName("arguments");
	m_oclMessageExpEval_Attribute_arguments->setEType(getOclMessageArgEval_Class());
	m_oclMessageExpEval_Attribute_arguments->setLowerBound(0);
	m_oclMessageExpEval_Attribute_arguments->setUpperBound(-1);
	m_oclMessageExpEval_Attribute_arguments->setTransient(false);
	m_oclMessageExpEval_Attribute_arguments->setVolatile(false);
	m_oclMessageExpEval_Attribute_arguments->setChangeable(true);
	m_oclMessageExpEval_Attribute_arguments->setUnsettable(false);
	m_oclMessageExpEval_Attribute_arguments->setUnique(false);
	m_oclMessageExpEval_Attribute_arguments->setDerived(false);
	m_oclMessageExpEval_Attribute_arguments->setOrdered(true);
	m_oclMessageExpEval_Attribute_arguments->setContainment(false);
	m_oclMessageExpEval_Attribute_arguments->setResolveProxies(true);
	m_oclMessageExpEval_Attribute_arguments->setDefaultValueLiteral("");	
	
	m_oclMessageExpEval_Attribute_arguments->_setID(OCLMESSAGEEXPEVAL_ATTRIBUTE_ARGUMENTS);
	m_oclMessageExpEval_Attribute_target->setName("target");
	m_oclMessageExpEval_Attribute_target->setEType(getOclExpEval_Class());
	m_oclMessageExpEval_Attribute_target->setLowerBound(1);
	m_oclMessageExpEval_Attribute_target->setUpperBound(1);
	m_oclMessageExpEval_Attribute_target->setTransient(false);
	m_oclMessageExpEval_Attribute_target->setVolatile(false);
	m_oclMessageExpEval_Attribute_target->setChangeable(true);
	m_oclMessageExpEval_Attribute_target->setUnsettable(false);
	m_oclMessageExpEval_Attribute_target->setUnique(true);
	m_oclMessageExpEval_Attribute_target->setDerived(false);
	m_oclMessageExpEval_Attribute_target->setOrdered(true);
	m_oclMessageExpEval_Attribute_target->setContainment(false);
	m_oclMessageExpEval_Attribute_target->setResolveProxies(true);
	m_oclMessageExpEval_Attribute_target->setDefaultValueLiteral("");	
	
	m_oclMessageExpEval_Attribute_target->_setID(OCLMESSAGEEXPEVAL_ATTRIBUTE_TARGET);
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializeOperationCallExpEvalContent()
{
	m_operationCallExpEval_Class->setName("OperationCallExpEval");
	m_operationCallExpEval_Class->setAbstract(false);
	m_operationCallExpEval_Class->setInterface(false);
	
	m_operationCallExpEval_Class->_setID(OPERATIONCALLEXPEVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	m_operationCallExpEval_Attribute_referredOperation = getOperationCallExpEval_Attribute_referredOperation();
	m_operationCallExpEval_Attribute_referredOperation->setName("referredOperation");
	m_operationCallExpEval_Attribute_referredOperation->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_operationCallExpEval_Attribute_referredOperation->setLowerBound(1);
	m_operationCallExpEval_Attribute_referredOperation->setUpperBound(1);
	m_operationCallExpEval_Attribute_referredOperation->setTransient(false);
	m_operationCallExpEval_Attribute_referredOperation->setVolatile(false);
	m_operationCallExpEval_Attribute_referredOperation->setChangeable(true);
	m_operationCallExpEval_Attribute_referredOperation->setUnsettable(false);
	m_operationCallExpEval_Attribute_referredOperation->setUnique(true);
	m_operationCallExpEval_Attribute_referredOperation->setDerived(false);
	m_operationCallExpEval_Attribute_referredOperation->setOrdered(true);
	m_operationCallExpEval_Attribute_referredOperation->setID(false);
	m_operationCallExpEval_Attribute_referredOperation->setDefaultValueLiteral("");
	
	m_operationCallExpEval_Attribute_referredOperation->_setID(OPERATIONCALLEXPEVAL_ATTRIBUTE_REFERREDOPERATION);
	
	/*
	 * EReferences
	 */
	m_operationCallExpEval_Attribute_arguments->setName("arguments");
	m_operationCallExpEval_Attribute_arguments->setEType(getOclExpEval_Class());
	m_operationCallExpEval_Attribute_arguments->setLowerBound(0);
	m_operationCallExpEval_Attribute_arguments->setUpperBound(-1);
	m_operationCallExpEval_Attribute_arguments->setTransient(false);
	m_operationCallExpEval_Attribute_arguments->setVolatile(false);
	m_operationCallExpEval_Attribute_arguments->setChangeable(true);
	m_operationCallExpEval_Attribute_arguments->setUnsettable(false);
	m_operationCallExpEval_Attribute_arguments->setUnique(false);
	m_operationCallExpEval_Attribute_arguments->setDerived(false);
	m_operationCallExpEval_Attribute_arguments->setOrdered(false);
	m_operationCallExpEval_Attribute_arguments->setContainment(false);
	m_operationCallExpEval_Attribute_arguments->setResolveProxies(true);
	m_operationCallExpEval_Attribute_arguments->setDefaultValueLiteral("");	
	
	m_operationCallExpEval_Attribute_arguments->_setID(OPERATIONCALLEXPEVAL_ATTRIBUTE_ARGUMENTS);
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializePrimitiveLiteralExpEvalContent()
{
	m_primitiveLiteralExpEval_Class->setName("PrimitiveLiteralExpEval");
	m_primitiveLiteralExpEval_Class->setAbstract(false);
	m_primitiveLiteralExpEval_Class->setInterface(false);
	
	m_primitiveLiteralExpEval_Class->_setID(PRIMITIVELITERALEXPEVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializePropertyCallExpEvalContent()
{
	m_propertyCallExpEval_Class->setName("PropertyCallExpEval");
	m_propertyCallExpEval_Class->setAbstract(false);
	m_propertyCallExpEval_Class->setInterface(false);
	
	m_propertyCallExpEval_Class->_setID(PROPERTYCALLEXPEVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_propertyCallExpEval_Attribute_source->setName("source");
	m_propertyCallExpEval_Attribute_source->setEType(getOclExpEval_Class());
	m_propertyCallExpEval_Attribute_source->setLowerBound(0);
	m_propertyCallExpEval_Attribute_source->setUpperBound(1);
	m_propertyCallExpEval_Attribute_source->setTransient(false);
	m_propertyCallExpEval_Attribute_source->setVolatile(false);
	m_propertyCallExpEval_Attribute_source->setChangeable(true);
	m_propertyCallExpEval_Attribute_source->setUnsettable(false);
	m_propertyCallExpEval_Attribute_source->setUnique(true);
	m_propertyCallExpEval_Attribute_source->setDerived(false);
	m_propertyCallExpEval_Attribute_source->setOrdered(true);
	m_propertyCallExpEval_Attribute_source->setContainment(false);
	m_propertyCallExpEval_Attribute_source->setResolveProxies(true);
	m_propertyCallExpEval_Attribute_source->setDefaultValueLiteral("");	
	
	m_propertyCallExpEval_Attribute_source->_setID(PROPERTYCALLEXPEVAL_ATTRIBUTE_SOURCE);
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializeRealLiteralExpEvalContent()
{
	m_realLiteralExpEval_Class->setName("RealLiteralExpEval");
	m_realLiteralExpEval_Class->setAbstract(false);
	m_realLiteralExpEval_Class->setInterface(false);
	
	m_realLiteralExpEval_Class->_setID(REALLITERALEXPEVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializeStringLiteralExpEvalContent()
{
	m_stringLiteralExpEval_Class->setName("StringLiteralExpEval");
	m_stringLiteralExpEval_Class->setAbstract(false);
	m_stringLiteralExpEval_Class->setInterface(false);
	
	m_stringLiteralExpEval_Class->_setID(STRINGLITERALEXPEVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializeTupleLiteralExpEvalContent()
{
	m_tupleLiteralExpEval_Class->setName("TupleLiteralExpEval");
	m_tupleLiteralExpEval_Class->setAbstract(false);
	m_tupleLiteralExpEval_Class->setInterface(false);
	
	m_tupleLiteralExpEval_Class->_setID(TUPLELITERALEXPEVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_tupleLiteralExpEval_Attribute_tuplePart->setName("tuplePart");
	m_tupleLiteralExpEval_Attribute_tuplePart->setEType(getVariableDeclEval_Class());
	m_tupleLiteralExpEval_Attribute_tuplePart->setLowerBound(0);
	m_tupleLiteralExpEval_Attribute_tuplePart->setUpperBound(-1);
	m_tupleLiteralExpEval_Attribute_tuplePart->setTransient(false);
	m_tupleLiteralExpEval_Attribute_tuplePart->setVolatile(false);
	m_tupleLiteralExpEval_Attribute_tuplePart->setChangeable(true);
	m_tupleLiteralExpEval_Attribute_tuplePart->setUnsettable(false);
	m_tupleLiteralExpEval_Attribute_tuplePart->setUnique(false);
	m_tupleLiteralExpEval_Attribute_tuplePart->setDerived(false);
	m_tupleLiteralExpEval_Attribute_tuplePart->setOrdered(false);
	m_tupleLiteralExpEval_Attribute_tuplePart->setContainment(false);
	m_tupleLiteralExpEval_Attribute_tuplePart->setResolveProxies(true);
	m_tupleLiteralExpEval_Attribute_tuplePart->setDefaultValueLiteral("");	
	
	m_tupleLiteralExpEval_Attribute_tuplePart->_setID(TUPLELITERALEXPEVAL_ATTRIBUTE_TUPLEPART);
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializeTupleLiteralExpPartEvalContent()
{
	m_tupleLiteralExpPartEval_Class->setName("TupleLiteralExpPartEval");
	m_tupleLiteralExpPartEval_Class->setAbstract(false);
	m_tupleLiteralExpPartEval_Class->setInterface(false);
	
	m_tupleLiteralExpPartEval_Class->_setID(TUPLELITERALEXPPARTEVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializeUnlimitedNaturalLiteralExpEvalContent()
{
	m_unlimitedNaturalLiteralExpEval_Class->setName("UnlimitedNaturalLiteralExpEval");
	m_unlimitedNaturalLiteralExpEval_Class->setAbstract(false);
	m_unlimitedNaturalLiteralExpEval_Class->setInterface(false);
	
	m_unlimitedNaturalLiteralExpEval_Class->_setID(UNLIMITEDNATURALLITERALEXPEVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializeUnspecifiedValueExpEvalContent()
{
	m_unspecifiedValueExpEval_Class->setName("UnspecifiedValueExpEval");
	m_unspecifiedValueExpEval_Class->setAbstract(false);
	m_unspecifiedValueExpEval_Class->setInterface(false);
	
	m_unspecifiedValueExpEval_Class->_setID(UNSPECIFIEDVALUEEXPEVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializeVariableDeclEvalContent()
{
	m_variableDeclEval_Class->setName("VariableDeclEval");
	m_variableDeclEval_Class->setAbstract(false);
	m_variableDeclEval_Class->setInterface(false);
	
	m_variableDeclEval_Class->_setID(VARIABLEDECLEVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	m_variableDeclEval_Attribute_name = getVariableDeclEval_Attribute_name();
	m_variableDeclEval_Attribute_name->setName("name");
	m_variableDeclEval_Attribute_name->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_variableDeclEval_Attribute_name->setLowerBound(1);
	m_variableDeclEval_Attribute_name->setUpperBound(1);
	m_variableDeclEval_Attribute_name->setTransient(false);
	m_variableDeclEval_Attribute_name->setVolatile(false);
	m_variableDeclEval_Attribute_name->setChangeable(true);
	m_variableDeclEval_Attribute_name->setUnsettable(false);
	m_variableDeclEval_Attribute_name->setUnique(true);
	m_variableDeclEval_Attribute_name->setDerived(false);
	m_variableDeclEval_Attribute_name->setOrdered(true);
	m_variableDeclEval_Attribute_name->setID(false);
	m_variableDeclEval_Attribute_name->setDefaultValueLiteral("");
	
	m_variableDeclEval_Attribute_name->_setID(VARIABLEDECLEVAL_ATTRIBUTE_NAME);
	
	/*
	 * EReferences
	 */
	m_variableDeclEval_Attribute_initExp->setName("initExp");
	m_variableDeclEval_Attribute_initExp->setEType(getOclExpEval_Class());
	m_variableDeclEval_Attribute_initExp->setLowerBound(1);
	m_variableDeclEval_Attribute_initExp->setUpperBound(1);
	m_variableDeclEval_Attribute_initExp->setTransient(false);
	m_variableDeclEval_Attribute_initExp->setVolatile(false);
	m_variableDeclEval_Attribute_initExp->setChangeable(true);
	m_variableDeclEval_Attribute_initExp->setUnsettable(false);
	m_variableDeclEval_Attribute_initExp->setUnique(true);
	m_variableDeclEval_Attribute_initExp->setDerived(false);
	m_variableDeclEval_Attribute_initExp->setOrdered(true);
	m_variableDeclEval_Attribute_initExp->setContainment(false);
	m_variableDeclEval_Attribute_initExp->setResolveProxies(true);
	m_variableDeclEval_Attribute_initExp->setDefaultValueLiteral("");	
	
	m_variableDeclEval_Attribute_initExp->_setID(VARIABLEDECLEVAL_ATTRIBUTE_INITEXP);
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializeVariableExpEvalContent()
{
	m_variableExpEval_Class->setName("VariableExpEval");
	m_variableExpEval_Class->setAbstract(false);
	m_variableExpEval_Class->setInterface(false);
	
	m_variableExpEval_Class->_setID(VARIABLEEXPEVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	m_variableExpEval_Attribute_referredVariable = getVariableExpEval_Attribute_referredVariable();
	m_variableExpEval_Attribute_referredVariable->setName("referredVariable");
	m_variableExpEval_Attribute_referredVariable->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_variableExpEval_Attribute_referredVariable->setLowerBound(1);
	m_variableExpEval_Attribute_referredVariable->setUpperBound(1);
	m_variableExpEval_Attribute_referredVariable->setTransient(false);
	m_variableExpEval_Attribute_referredVariable->setVolatile(false);
	m_variableExpEval_Attribute_referredVariable->setChangeable(true);
	m_variableExpEval_Attribute_referredVariable->setUnsettable(false);
	m_variableExpEval_Attribute_referredVariable->setUnique(true);
	m_variableExpEval_Attribute_referredVariable->setDerived(false);
	m_variableExpEval_Attribute_referredVariable->setOrdered(true);
	m_variableExpEval_Attribute_referredVariable->setID(false);
	m_variableExpEval_Attribute_referredVariable->setDefaultValueLiteral("");
	
	m_variableExpEval_Attribute_referredVariable->_setID(VARIABLEEXPEVAL_ATTRIBUTE_REFERREDVARIABLE);
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void EvaluationsPackageImpl::initializePackageEDataTypes()
{
	
}

