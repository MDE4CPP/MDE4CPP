#include "ocl/Expressions/impl/ExpressionsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EClass.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EEnumLiteral.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EDataType.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "ocl/Evaluations/EvaluationsPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "ocl/oclPackage.hpp"


using namespace ocl::Expressions;

void ExpressionsPackageImpl::initializePackageContents()
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
	m_associationClassCallExp_Class->getESuperTypes()->push_back(getNavigationCallExp_Class());
	m_booleanLiteralExp_Class->getESuperTypes()->push_back(getPrimitiveLiteralExp_Class());
	m_callExp_Class->getESuperTypes()->push_back(getOclExpression_Class());
	m_classifierContextDeclExp_Class->getESuperTypes()->push_back(getContextDeclarationExp_Class());
	m_collectionItem_Class->getESuperTypes()->push_back(getCollectionLiteralPart_Class());
	m_collectionLiteralExp_Class->getESuperTypes()->push_back(getLiteralExp_Class());
	m_collectionLiteralPart_Class->getESuperTypes()->push_back(ecore::ecorePackage::eInstance()->getETypedElement_Class());
	m_collectionLiteralParts_Class->getESuperTypes()->push_back(ecore::ecorePackage::eInstance()->getETypedElement_Class());
	m_collectionRange_Class->getESuperTypes()->push_back(getCollectionLiteralPart_Class());
	m_collectionTypeExp_Class->getESuperTypes()->push_back(getTypeExp_Class());
	m_contextDeclarationExp_Class->getESuperTypes()->push_back(getOclExpression_Class());
	m_defExp_Class->getESuperTypes()->push_back(getOclExpression_Class());
	m_enumLiteralExp_Class->getESuperTypes()->push_back(getLiteralExp_Class());
	m_expressionInOcl_Class->getESuperTypes()->push_back(ecore::ecorePackage::eInstance()->getETypedElement_Class());
	m_featureCallExp_Class->getESuperTypes()->push_back(getCallExp_Class());
	m_ifExp_Class->getESuperTypes()->push_back(getOclExpression_Class());
	m_infixedExp_Class->getESuperTypes()->push_back(getOclExpression_Class());
	m_initOrDerValueExp_Class->getESuperTypes()->push_back(ecore::ecorePackage::eInstance()->getETypedElement_Class());
	m_initOrDerValueListExp_Class->getESuperTypes()->push_back(getOclExpression_Class());
	m_integerLiteralExp_Class->getESuperTypes()->push_back(getNumericLiteralExp_Class());
	m_invOrDefExp_Class->getESuperTypes()->push_back(ecore::ecorePackage::eInstance()->getETypedElement_Class());
	m_invalidLiteralExp_Class->getESuperTypes()->push_back(getLiteralExp_Class());
	m_iterateExp_Class->getESuperTypes()->push_back(getLoopExp_Class());
	m_iteratorExp_Class->getESuperTypes()->push_back(getLoopExp_Class());
	m_letExp_Class->getESuperTypes()->push_back(getOclExpression_Class());
	m_literalExp_Class->getESuperTypes()->push_back(getOclExpression_Class());
	m_loopExp_Class->getESuperTypes()->push_back(getCallExp_Class());
	m_messageArguments_Class->getESuperTypes()->push_back(ecore::ecorePackage::eInstance()->getETypedElement_Class());
	m_messageExp_Class->getESuperTypes()->push_back(getOclExpression_Class());
	m_navigationCallExp_Class->getESuperTypes()->push_back(getFeatureCallExp_Class());
	m_nullLiteralExp_Class->getESuperTypes()->push_back(getLiteralExp_Class());
	m_numericLiteralExp_Class->getESuperTypes()->push_back(getPrimitiveLiteralExp_Class());
	m_oclExpression_Class->getESuperTypes()->push_back(ecore::ecorePackage::eInstance()->getETypedElement_Class());
	m_operationCallExp_Class->getESuperTypes()->push_back(getFeatureCallExp_Class());
	m_operationContextDeclExp_Class->getESuperTypes()->push_back(getContextDeclarationExp_Class());
	m_operationContextExp_Class->getESuperTypes()->push_back(getOclExpression_Class());
	m_operatorExp_Class->getESuperTypes()->push_back(getOclExpression_Class());
	m_packageDeclarationExp_Class->getESuperTypes()->push_back(getOclExpression_Class());
	m_parentedExp_Class->getESuperTypes()->push_back(getOclExpression_Class());
	m_prePostBodyExp_Class->getESuperTypes()->push_back(ecore::ecorePackage::eInstance()->getETypedElement_Class());
	m_prePostBodyListExp_Class->getESuperTypes()->push_back(getOclExpression_Class());
	m_prefixedExp_Class->getESuperTypes()->push_back(getOclExpression_Class());
	m_primitiveLiteralExp_Class->getESuperTypes()->push_back(getLiteralExp_Class());
	m_propertyCallExp_Class->getESuperTypes()->push_back(getNavigationCallExp_Class());
	m_propertyContextDeclExp_Class->getESuperTypes()->push_back(getContextDeclarationExp_Class());
	m_realLiteralExp_Class->getESuperTypes()->push_back(getNumericLiteralExp_Class());
	m_stateExp_Class->getESuperTypes()->push_back(getOclExpression_Class());
	m_stringLiteralExp_Class->getESuperTypes()->push_back(getPrimitiveLiteralExp_Class());
	m_tupleLiteralExp_Class->getESuperTypes()->push_back(getLiteralExp_Class());
	m_tupleLiteralPart_Class->getESuperTypes()->push_back(ecore::ecorePackage::eInstance()->getETypedElement_Class());
	m_tupleTypeExp_Class->getESuperTypes()->push_back(getTypeExp_Class());
	m_typeExp_Class->getESuperTypes()->push_back(getOclExpression_Class());
	m_unlimitedNaturalExp_Class->getESuperTypes()->push_back(getNumericLiteralExp_Class());
	m_unspecifiedValueExp_Class->getESuperTypes()->push_back(getOclExpression_Class());
	m_varDeclarationExp_Class->getESuperTypes()->push_back(getOclExpression_Class());
	m_variable_Class->getESuperTypes()->push_back(ecore::ecorePackage::eInstance()->getETypedElement_Class());
	m_variableExp_Class->getESuperTypes()->push_back(getOclExpression_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeAssociationClassCallExpContent();
	initializeBooleanLiteralExpContent();
	initializeCallExpContent();
	initializeClassifierContextDeclExpContent();
	initializeCollectionItemContent();
	initializeCollectionLiteralExpContent();
	initializeCollectionLiteralPartContent();
	initializeCollectionLiteralPartsContent();
	initializeCollectionRangeContent();
	initializeCollectionTypeExpContent();
	initializeContextDeclarationExpContent();
	initializeDefExpContent();
	initializeEnumLiteralExpContent();
	initializeExpressionInOclContent();
	initializeFeatureCallExpContent();
	initializeIfExpContent();
	initializeInfixedExpContent();
	initializeInitOrDerValueExpContent();
	initializeInitOrDerValueListExpContent();
	initializeIntegerLiteralExpContent();
	initializeInvOrDefExpContent();
	initializeInvalidLiteralExpContent();
	initializeIterateExpContent();
	initializeIteratorExpContent();
	initializeLetExpContent();
	initializeLiteralExpContent();
	initializeLoopExpContent();
	initializeMessageArgumentsContent();
	initializeMessageExpContent();
	initializeNavigationCallExpContent();
	initializeNullLiteralExpContent();
	initializeNumericLiteralExpContent();
	initializeOclExpressionContent();
	initializeOperationCallExpContent();
	initializeOperationContextDeclExpContent();
	initializeOperationContextExpContent();
	initializeOperatorExpContent();
	initializePackageDeclarationExpContent();
	initializeParentedExpContent();
	initializePrePostBodyExpContent();
	initializePrePostBodyListExpContent();
	initializePrefixedExpContent();
	initializePrimitiveLiteralExpContent();
	initializePropertyCallExpContent();
	initializePropertyContextDeclExpContent();
	initializeRealLiteralExpContent();
	initializeStateExpContent();
	initializeStringLiteralExpContent();
	initializeTupleLiteralExpContent();
	initializeTupleLiteralPartContent();
	initializeTupleTypeExpContent();
	initializeTypeExpContent();
	initializeUnlimitedNaturalExpContent();
	initializeUnspecifiedValueExpContent();
	initializeVarDeclarationExpContent();
	initializeVariableContent();
	initializeVariableExpContent();

	initializePackageEDataTypes();

}

void ExpressionsPackageImpl::initializeAssociationClassCallExpContent()
{
	m_associationClassCallExp_Class->setName("AssociationClassCallExp");
	m_associationClassCallExp_Class->setAbstract(false);
	m_associationClassCallExp_Class->setInterface(false);
	
	m_associationClassCallExp_Class->_setID(ASSOCIATIONCLASSCALLEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	m_associationClassCallExp_Attribute_referredAssociationClass = getAssociationClassCallExp_Attribute_referredAssociationClass();
	m_associationClassCallExp_Attribute_referredAssociationClass->setName("referredAssociationClass");
	m_associationClassCallExp_Attribute_referredAssociationClass->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_associationClassCallExp_Attribute_referredAssociationClass->setLowerBound(0);
	m_associationClassCallExp_Attribute_referredAssociationClass->setUpperBound(1);
	m_associationClassCallExp_Attribute_referredAssociationClass->setTransient(false);
	m_associationClassCallExp_Attribute_referredAssociationClass->setVolatile(false);
	m_associationClassCallExp_Attribute_referredAssociationClass->setChangeable(true);
	m_associationClassCallExp_Attribute_referredAssociationClass->setUnsettable(false);
	m_associationClassCallExp_Attribute_referredAssociationClass->setUnique(true);
	m_associationClassCallExp_Attribute_referredAssociationClass->setDerived(false);
	m_associationClassCallExp_Attribute_referredAssociationClass->setOrdered(true);
	m_associationClassCallExp_Attribute_referredAssociationClass->setID(false);
	m_associationClassCallExp_Attribute_referredAssociationClass->setDefaultValueLiteral("");
	
	m_associationClassCallExp_Attribute_referredAssociationClass->_setID(ASSOCIATIONCLASSCALLEXP_ATTRIBUTE_REFERREDASSOCIATIONCLASS);
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeBooleanLiteralExpContent()
{
	m_booleanLiteralExp_Class->setName("BooleanLiteralExp");
	m_booleanLiteralExp_Class->setAbstract(false);
	m_booleanLiteralExp_Class->setInterface(false);
	
	m_booleanLiteralExp_Class->_setID(BOOLEANLITERALEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	m_booleanLiteralExp_Attribute_booleanSymbol = getBooleanLiteralExp_Attribute_booleanSymbol();
	m_booleanLiteralExp_Attribute_booleanSymbol->setName("booleanSymbol");
	m_booleanLiteralExp_Attribute_booleanSymbol->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_booleanLiteralExp_Attribute_booleanSymbol->setLowerBound(0);
	m_booleanLiteralExp_Attribute_booleanSymbol->setUpperBound(1);
	m_booleanLiteralExp_Attribute_booleanSymbol->setTransient(false);
	m_booleanLiteralExp_Attribute_booleanSymbol->setVolatile(false);
	m_booleanLiteralExp_Attribute_booleanSymbol->setChangeable(true);
	m_booleanLiteralExp_Attribute_booleanSymbol->setUnsettable(false);
	m_booleanLiteralExp_Attribute_booleanSymbol->setUnique(true);
	m_booleanLiteralExp_Attribute_booleanSymbol->setDerived(false);
	m_booleanLiteralExp_Attribute_booleanSymbol->setOrdered(true);
	m_booleanLiteralExp_Attribute_booleanSymbol->setID(false);
	m_booleanLiteralExp_Attribute_booleanSymbol->setDefaultValueLiteral("");
	
	m_booleanLiteralExp_Attribute_booleanSymbol->_setID(BOOLEANLITERALEXP_ATTRIBUTE_BOOLEANSYMBOL);
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeCallExpContent()
{
	m_callExp_Class->setName("CallExp");
	m_callExp_Class->setAbstract(true);
	m_callExp_Class->setInterface(false);
	
	m_callExp_Class->_setID(CALLEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_callExp_Attribute_source->setName("source");
	m_callExp_Attribute_source->setEType(getOclExpression_Class());
	m_callExp_Attribute_source->setLowerBound(0);
	m_callExp_Attribute_source->setUpperBound(1);
	m_callExp_Attribute_source->setTransient(false);
	m_callExp_Attribute_source->setVolatile(false);
	m_callExp_Attribute_source->setChangeable(true);
	m_callExp_Attribute_source->setUnsettable(false);
	m_callExp_Attribute_source->setUnique(true);
	m_callExp_Attribute_source->setDerived(false);
	m_callExp_Attribute_source->setOrdered(false);
	m_callExp_Attribute_source->setContainment(true);
	m_callExp_Attribute_source->setResolveProxies(true);
	m_callExp_Attribute_source->setDefaultValueLiteral("");	
	
	m_callExp_Attribute_source->_setID(CALLEXP_ATTRIBUTE_SOURCE);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeClassifierContextDeclExpContent()
{
	m_classifierContextDeclExp_Class->setName("ClassifierContextDeclExp");
	m_classifierContextDeclExp_Class->setAbstract(false);
	m_classifierContextDeclExp_Class->setInterface(false);
	
	m_classifierContextDeclExp_Class->_setID(CLASSIFIERCONTEXTDECLEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	m_classifierContextDeclExp_Attribute_classifierName = getClassifierContextDeclExp_Attribute_classifierName();
	m_classifierContextDeclExp_Attribute_classifierName->setName("classifierName");
	m_classifierContextDeclExp_Attribute_classifierName->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_classifierContextDeclExp_Attribute_classifierName->setLowerBound(0);
	m_classifierContextDeclExp_Attribute_classifierName->setUpperBound(1);
	m_classifierContextDeclExp_Attribute_classifierName->setTransient(false);
	m_classifierContextDeclExp_Attribute_classifierName->setVolatile(false);
	m_classifierContextDeclExp_Attribute_classifierName->setChangeable(true);
	m_classifierContextDeclExp_Attribute_classifierName->setUnsettable(false);
	m_classifierContextDeclExp_Attribute_classifierName->setUnique(true);
	m_classifierContextDeclExp_Attribute_classifierName->setDerived(false);
	m_classifierContextDeclExp_Attribute_classifierName->setOrdered(true);
	m_classifierContextDeclExp_Attribute_classifierName->setID(false);
	m_classifierContextDeclExp_Attribute_classifierName->setDefaultValueLiteral("");
	
	m_classifierContextDeclExp_Attribute_classifierName->_setID(CLASSIFIERCONTEXTDECLEXP_ATTRIBUTE_CLASSIFIERNAME);
	
	/*
	 * EReferences
	 */
	m_classifierContextDeclExp_Attribute_invOrDevExp->setName("invOrDevExp");
	m_classifierContextDeclExp_Attribute_invOrDevExp->setEType(getInvOrDefExp_Class());
	m_classifierContextDeclExp_Attribute_invOrDevExp->setLowerBound(0);
	m_classifierContextDeclExp_Attribute_invOrDevExp->setUpperBound(1);
	m_classifierContextDeclExp_Attribute_invOrDevExp->setTransient(false);
	m_classifierContextDeclExp_Attribute_invOrDevExp->setVolatile(false);
	m_classifierContextDeclExp_Attribute_invOrDevExp->setChangeable(true);
	m_classifierContextDeclExp_Attribute_invOrDevExp->setUnsettable(false);
	m_classifierContextDeclExp_Attribute_invOrDevExp->setUnique(true);
	m_classifierContextDeclExp_Attribute_invOrDevExp->setDerived(false);
	m_classifierContextDeclExp_Attribute_invOrDevExp->setOrdered(true);
	m_classifierContextDeclExp_Attribute_invOrDevExp->setContainment(false);
	m_classifierContextDeclExp_Attribute_invOrDevExp->setResolveProxies(true);
	m_classifierContextDeclExp_Attribute_invOrDevExp->setDefaultValueLiteral("");	
	
	m_classifierContextDeclExp_Attribute_invOrDevExp->_setID(CLASSIFIERCONTEXTDECLEXP_ATTRIBUTE_INVORDEVEXP);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeCollectionItemContent()
{
	m_collectionItem_Class->setName("CollectionItem");
	m_collectionItem_Class->setAbstract(false);
	m_collectionItem_Class->setInterface(false);
	
	m_collectionItem_Class->_setID(COLLECTIONITEM_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_collectionItem_Attribute_item->setName("item");
	m_collectionItem_Attribute_item->setEType(getOclExpression_Class());
	m_collectionItem_Attribute_item->setLowerBound(1);
	m_collectionItem_Attribute_item->setUpperBound(1);
	m_collectionItem_Attribute_item->setTransient(false);
	m_collectionItem_Attribute_item->setVolatile(false);
	m_collectionItem_Attribute_item->setChangeable(true);
	m_collectionItem_Attribute_item->setUnsettable(false);
	m_collectionItem_Attribute_item->setUnique(true);
	m_collectionItem_Attribute_item->setDerived(false);
	m_collectionItem_Attribute_item->setOrdered(false);
	m_collectionItem_Attribute_item->setContainment(true);
	m_collectionItem_Attribute_item->setResolveProxies(true);
	m_collectionItem_Attribute_item->setDefaultValueLiteral("");	
	
	m_collectionItem_Attribute_item->_setID(COLLECTIONITEM_ATTRIBUTE_ITEM);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeCollectionLiteralExpContent()
{
	m_collectionLiteralExp_Class->setName("CollectionLiteralExp");
	m_collectionLiteralExp_Class->setAbstract(false);
	m_collectionLiteralExp_Class->setInterface(false);
	
	m_collectionLiteralExp_Class->_setID(COLLECTIONLITERALEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	m_collectionLiteralExp_Attribute_kind = getCollectionLiteralExp_Attribute_kind();
	m_collectionLiteralExp_Attribute_kind->setName("kind");
	m_collectionLiteralExp_Attribute_kind->setEType(getCollectionKind_Class());
	m_collectionLiteralExp_Attribute_kind->setLowerBound(1);
	m_collectionLiteralExp_Attribute_kind->setUpperBound(1);
	m_collectionLiteralExp_Attribute_kind->setTransient(false);
	m_collectionLiteralExp_Attribute_kind->setVolatile(false);
	m_collectionLiteralExp_Attribute_kind->setChangeable(true);
	m_collectionLiteralExp_Attribute_kind->setUnsettable(false);
	m_collectionLiteralExp_Attribute_kind->setUnique(true);
	m_collectionLiteralExp_Attribute_kind->setDerived(false);
	m_collectionLiteralExp_Attribute_kind->setOrdered(false);
	m_collectionLiteralExp_Attribute_kind->setID(false);
	m_collectionLiteralExp_Attribute_kind->setDefaultValueLiteral("");
	
	m_collectionLiteralExp_Attribute_kind->_setID(COLLECTIONLITERALEXP_ATTRIBUTE_KIND);
	
	/*
	 * EReferences
	 */
	m_collectionLiteralExp_Attribute_part->setName("part");
	m_collectionLiteralExp_Attribute_part->setEType(getCollectionLiteralPart_Class());
	m_collectionLiteralExp_Attribute_part->setLowerBound(0);
	m_collectionLiteralExp_Attribute_part->setUpperBound(-1);
	m_collectionLiteralExp_Attribute_part->setTransient(false);
	m_collectionLiteralExp_Attribute_part->setVolatile(false);
	m_collectionLiteralExp_Attribute_part->setChangeable(true);
	m_collectionLiteralExp_Attribute_part->setUnsettable(false);
	m_collectionLiteralExp_Attribute_part->setUnique(true);
	m_collectionLiteralExp_Attribute_part->setDerived(false);
	m_collectionLiteralExp_Attribute_part->setOrdered(true);
	m_collectionLiteralExp_Attribute_part->setContainment(true);
	m_collectionLiteralExp_Attribute_part->setResolveProxies(true);
	m_collectionLiteralExp_Attribute_part->setDefaultValueLiteral("");	
	
	m_collectionLiteralExp_Attribute_part->_setID(COLLECTIONLITERALEXP_ATTRIBUTE_PART);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeCollectionLiteralPartContent()
{
	m_collectionLiteralPart_Class->setName("CollectionLiteralPart");
	m_collectionLiteralPart_Class->setAbstract(true);
	m_collectionLiteralPart_Class->setInterface(false);
	
	m_collectionLiteralPart_Class->_setID(COLLECTIONLITERALPART_CLASS);
	
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

void ExpressionsPackageImpl::initializeCollectionLiteralPartsContent()
{
	m_collectionLiteralParts_Class->setName("CollectionLiteralParts");
	m_collectionLiteralParts_Class->setAbstract(false);
	m_collectionLiteralParts_Class->setInterface(false);
	
	m_collectionLiteralParts_Class->_setID(COLLECTIONLITERALPARTS_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_collectionLiteralParts_Attribute_literalParts->setName("literalParts");
	m_collectionLiteralParts_Attribute_literalParts->setEType(getCollectionLiteralPart_Class());
	m_collectionLiteralParts_Attribute_literalParts->setLowerBound(0);
	m_collectionLiteralParts_Attribute_literalParts->setUpperBound(-1);
	m_collectionLiteralParts_Attribute_literalParts->setTransient(false);
	m_collectionLiteralParts_Attribute_literalParts->setVolatile(false);
	m_collectionLiteralParts_Attribute_literalParts->setChangeable(true);
	m_collectionLiteralParts_Attribute_literalParts->setUnsettable(false);
	m_collectionLiteralParts_Attribute_literalParts->setUnique(true);
	m_collectionLiteralParts_Attribute_literalParts->setDerived(false);
	m_collectionLiteralParts_Attribute_literalParts->setOrdered(true);
	m_collectionLiteralParts_Attribute_literalParts->setContainment(false);
	m_collectionLiteralParts_Attribute_literalParts->setResolveProxies(true);
	m_collectionLiteralParts_Attribute_literalParts->setDefaultValueLiteral("");	
	
	m_collectionLiteralParts_Attribute_literalParts->_setID(COLLECTIONLITERALPARTS_ATTRIBUTE_LITERALPARTS);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeCollectionRangeContent()
{
	m_collectionRange_Class->setName("CollectionRange");
	m_collectionRange_Class->setAbstract(false);
	m_collectionRange_Class->setInterface(false);
	
	m_collectionRange_Class->_setID(COLLECTIONRANGE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_collectionRange_Attribute_first->setName("first");
	m_collectionRange_Attribute_first->setEType(getOclExpression_Class());
	m_collectionRange_Attribute_first->setLowerBound(1);
	m_collectionRange_Attribute_first->setUpperBound(1);
	m_collectionRange_Attribute_first->setTransient(false);
	m_collectionRange_Attribute_first->setVolatile(false);
	m_collectionRange_Attribute_first->setChangeable(true);
	m_collectionRange_Attribute_first->setUnsettable(false);
	m_collectionRange_Attribute_first->setUnique(true);
	m_collectionRange_Attribute_first->setDerived(false);
	m_collectionRange_Attribute_first->setOrdered(false);
	m_collectionRange_Attribute_first->setContainment(true);
	m_collectionRange_Attribute_first->setResolveProxies(true);
	m_collectionRange_Attribute_first->setDefaultValueLiteral("");	
	m_collectionRange_Attribute_first->setEOpposite(ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Attribute_firstOwner());
	
	m_collectionRange_Attribute_first->_setID(COLLECTIONRANGE_ATTRIBUTE_FIRST);
	m_collectionRange_Attribute_last->setName("last");
	m_collectionRange_Attribute_last->setEType(getOclExpression_Class());
	m_collectionRange_Attribute_last->setLowerBound(1);
	m_collectionRange_Attribute_last->setUpperBound(1);
	m_collectionRange_Attribute_last->setTransient(false);
	m_collectionRange_Attribute_last->setVolatile(false);
	m_collectionRange_Attribute_last->setChangeable(true);
	m_collectionRange_Attribute_last->setUnsettable(false);
	m_collectionRange_Attribute_last->setUnique(true);
	m_collectionRange_Attribute_last->setDerived(false);
	m_collectionRange_Attribute_last->setOrdered(false);
	m_collectionRange_Attribute_last->setContainment(true);
	m_collectionRange_Attribute_last->setResolveProxies(true);
	m_collectionRange_Attribute_last->setDefaultValueLiteral("");	
	m_collectionRange_Attribute_last->setEOpposite(ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Attribute_lastOwner());
	
	m_collectionRange_Attribute_last->_setID(COLLECTIONRANGE_ATTRIBUTE_LAST);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeCollectionTypeExpContent()
{
	m_collectionTypeExp_Class->setName("CollectionTypeExp");
	m_collectionTypeExp_Class->setAbstract(false);
	m_collectionTypeExp_Class->setInterface(false);
	
	m_collectionTypeExp_Class->_setID(COLLECTIONTYPEEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_collectionTypeExp_Attribute_innerType->setName("innerType");
	m_collectionTypeExp_Attribute_innerType->setEType(getTypeExp_Class());
	m_collectionTypeExp_Attribute_innerType->setLowerBound(0);
	m_collectionTypeExp_Attribute_innerType->setUpperBound(1);
	m_collectionTypeExp_Attribute_innerType->setTransient(false);
	m_collectionTypeExp_Attribute_innerType->setVolatile(false);
	m_collectionTypeExp_Attribute_innerType->setChangeable(true);
	m_collectionTypeExp_Attribute_innerType->setUnsettable(false);
	m_collectionTypeExp_Attribute_innerType->setUnique(true);
	m_collectionTypeExp_Attribute_innerType->setDerived(false);
	m_collectionTypeExp_Attribute_innerType->setOrdered(true);
	m_collectionTypeExp_Attribute_innerType->setContainment(false);
	m_collectionTypeExp_Attribute_innerType->setResolveProxies(true);
	m_collectionTypeExp_Attribute_innerType->setDefaultValueLiteral("");	
	
	m_collectionTypeExp_Attribute_innerType->_setID(COLLECTIONTYPEEXP_ATTRIBUTE_INNERTYPE);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeContextDeclarationExpContent()
{
	m_contextDeclarationExp_Class->setName("ContextDeclarationExp");
	m_contextDeclarationExp_Class->setAbstract(true);
	m_contextDeclarationExp_Class->setInterface(false);
	
	m_contextDeclarationExp_Class->_setID(CONTEXTDECLARATIONEXP_CLASS);
	
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

void ExpressionsPackageImpl::initializeDefExpContent()
{
	m_defExp_Class->setName("DefExp");
	m_defExp_Class->setAbstract(false);
	m_defExp_Class->setInterface(false);
	
	m_defExp_Class->_setID(DEFEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_defExp_Attribute_bodyExp->setName("bodyExp");
	m_defExp_Attribute_bodyExp->setEType(getOclExpression_Class());
	m_defExp_Attribute_bodyExp->setLowerBound(0);
	m_defExp_Attribute_bodyExp->setUpperBound(1);
	m_defExp_Attribute_bodyExp->setTransient(false);
	m_defExp_Attribute_bodyExp->setVolatile(false);
	m_defExp_Attribute_bodyExp->setChangeable(true);
	m_defExp_Attribute_bodyExp->setUnsettable(false);
	m_defExp_Attribute_bodyExp->setUnique(true);
	m_defExp_Attribute_bodyExp->setDerived(false);
	m_defExp_Attribute_bodyExp->setOrdered(true);
	m_defExp_Attribute_bodyExp->setContainment(false);
	m_defExp_Attribute_bodyExp->setResolveProxies(true);
	m_defExp_Attribute_bodyExp->setDefaultValueLiteral("");	
	
	m_defExp_Attribute_bodyExp->_setID(DEFEXP_ATTRIBUTE_BODYEXP);
	m_defExp_Attribute_frontExp->setName("frontExp");
	m_defExp_Attribute_frontExp->setEType(getOclExpression_Class());
	m_defExp_Attribute_frontExp->setLowerBound(0);
	m_defExp_Attribute_frontExp->setUpperBound(1);
	m_defExp_Attribute_frontExp->setTransient(false);
	m_defExp_Attribute_frontExp->setVolatile(false);
	m_defExp_Attribute_frontExp->setChangeable(true);
	m_defExp_Attribute_frontExp->setUnsettable(false);
	m_defExp_Attribute_frontExp->setUnique(true);
	m_defExp_Attribute_frontExp->setDerived(false);
	m_defExp_Attribute_frontExp->setOrdered(true);
	m_defExp_Attribute_frontExp->setContainment(false);
	m_defExp_Attribute_frontExp->setResolveProxies(true);
	m_defExp_Attribute_frontExp->setDefaultValueLiteral("");	
	
	m_defExp_Attribute_frontExp->_setID(DEFEXP_ATTRIBUTE_FRONTEXP);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeEnumLiteralExpContent()
{
	m_enumLiteralExp_Class->setName("EnumLiteralExp");
	m_enumLiteralExp_Class->setAbstract(false);
	m_enumLiteralExp_Class->setInterface(false);
	
	m_enumLiteralExp_Class->_setID(ENUMLITERALEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	m_enumLiteralExp_Attribute_referredEnumLiteralStr = getEnumLiteralExp_Attribute_referredEnumLiteralStr();
	m_enumLiteralExp_Attribute_referredEnumLiteralStr->setName("referredEnumLiteralStr");
	m_enumLiteralExp_Attribute_referredEnumLiteralStr->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_enumLiteralExp_Attribute_referredEnumLiteralStr->setLowerBound(0);
	m_enumLiteralExp_Attribute_referredEnumLiteralStr->setUpperBound(1);
	m_enumLiteralExp_Attribute_referredEnumLiteralStr->setTransient(false);
	m_enumLiteralExp_Attribute_referredEnumLiteralStr->setVolatile(false);
	m_enumLiteralExp_Attribute_referredEnumLiteralStr->setChangeable(true);
	m_enumLiteralExp_Attribute_referredEnumLiteralStr->setUnsettable(false);
	m_enumLiteralExp_Attribute_referredEnumLiteralStr->setUnique(true);
	m_enumLiteralExp_Attribute_referredEnumLiteralStr->setDerived(false);
	m_enumLiteralExp_Attribute_referredEnumLiteralStr->setOrdered(true);
	m_enumLiteralExp_Attribute_referredEnumLiteralStr->setID(false);
	m_enumLiteralExp_Attribute_referredEnumLiteralStr->setDefaultValueLiteral("");
	
	m_enumLiteralExp_Attribute_referredEnumLiteralStr->_setID(ENUMLITERALEXP_ATTRIBUTE_REFERREDENUMLITERALSTR);
	
	/*
	 * EReferences
	 */
	m_enumLiteralExp_Attribute_referredEnumLiteral->setName("referredEnumLiteral");
	m_enumLiteralExp_Attribute_referredEnumLiteral->setEType(ecore::ecorePackage::eInstance()->getEEnumLiteral_Class());
	m_enumLiteralExp_Attribute_referredEnumLiteral->setLowerBound(0);
	m_enumLiteralExp_Attribute_referredEnumLiteral->setUpperBound(1);
	m_enumLiteralExp_Attribute_referredEnumLiteral->setTransient(false);
	m_enumLiteralExp_Attribute_referredEnumLiteral->setVolatile(false);
	m_enumLiteralExp_Attribute_referredEnumLiteral->setChangeable(true);
	m_enumLiteralExp_Attribute_referredEnumLiteral->setUnsettable(false);
	m_enumLiteralExp_Attribute_referredEnumLiteral->setUnique(true);
	m_enumLiteralExp_Attribute_referredEnumLiteral->setDerived(false);
	m_enumLiteralExp_Attribute_referredEnumLiteral->setOrdered(false);
	m_enumLiteralExp_Attribute_referredEnumLiteral->setContainment(false);
	m_enumLiteralExp_Attribute_referredEnumLiteral->setResolveProxies(true);
	m_enumLiteralExp_Attribute_referredEnumLiteral->setDefaultValueLiteral("");	
	
	m_enumLiteralExp_Attribute_referredEnumLiteral->_setID(ENUMLITERALEXP_ATTRIBUTE_REFERREDENUMLITERAL);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeExpressionInOclContent()
{
	m_expressionInOcl_Class->setName("ExpressionInOcl");
	m_expressionInOcl_Class->setAbstract(false);
	m_expressionInOcl_Class->setInterface(false);
	
	m_expressionInOcl_Class->_setID(EXPRESSIONINOCL_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_expressionInOcl_Attribute_bodyExpression->setName("bodyExpression");
	m_expressionInOcl_Attribute_bodyExpression->setEType(getOclExpression_Class());
	m_expressionInOcl_Attribute_bodyExpression->setLowerBound(1);
	m_expressionInOcl_Attribute_bodyExpression->setUpperBound(1);
	m_expressionInOcl_Attribute_bodyExpression->setTransient(false);
	m_expressionInOcl_Attribute_bodyExpression->setVolatile(false);
	m_expressionInOcl_Attribute_bodyExpression->setChangeable(true);
	m_expressionInOcl_Attribute_bodyExpression->setUnsettable(false);
	m_expressionInOcl_Attribute_bodyExpression->setUnique(true);
	m_expressionInOcl_Attribute_bodyExpression->setDerived(false);
	m_expressionInOcl_Attribute_bodyExpression->setOrdered(false);
	m_expressionInOcl_Attribute_bodyExpression->setContainment(true);
	m_expressionInOcl_Attribute_bodyExpression->setResolveProxies(true);
	m_expressionInOcl_Attribute_bodyExpression->setDefaultValueLiteral("");	
	m_expressionInOcl_Attribute_bodyExpression->setEOpposite(ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Attribute_topExpression());
	
	m_expressionInOcl_Attribute_bodyExpression->_setID(EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION);
	m_expressionInOcl_Attribute_contextVariable->setName("contextVariable");
	m_expressionInOcl_Attribute_contextVariable->setEType(ecore::ecorePackage::eInstance()->getETypedElement_Class());
	m_expressionInOcl_Attribute_contextVariable->setLowerBound(0);
	m_expressionInOcl_Attribute_contextVariable->setUpperBound(1);
	m_expressionInOcl_Attribute_contextVariable->setTransient(false);
	m_expressionInOcl_Attribute_contextVariable->setVolatile(false);
	m_expressionInOcl_Attribute_contextVariable->setChangeable(true);
	m_expressionInOcl_Attribute_contextVariable->setUnsettable(false);
	m_expressionInOcl_Attribute_contextVariable->setUnique(true);
	m_expressionInOcl_Attribute_contextVariable->setDerived(false);
	m_expressionInOcl_Attribute_contextVariable->setOrdered(false);
	m_expressionInOcl_Attribute_contextVariable->setContainment(true);
	m_expressionInOcl_Attribute_contextVariable->setResolveProxies(true);
	m_expressionInOcl_Attribute_contextVariable->setDefaultValueLiteral("");	
	
	m_expressionInOcl_Attribute_contextVariable->_setID(EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE);
	m_expressionInOcl_Attribute_parameterVariable->setName("parameterVariable");
	m_expressionInOcl_Attribute_parameterVariable->setEType(ecore::ecorePackage::eInstance()->getETypedElement_Class());
	m_expressionInOcl_Attribute_parameterVariable->setLowerBound(0);
	m_expressionInOcl_Attribute_parameterVariable->setUpperBound(-1);
	m_expressionInOcl_Attribute_parameterVariable->setTransient(false);
	m_expressionInOcl_Attribute_parameterVariable->setVolatile(false);
	m_expressionInOcl_Attribute_parameterVariable->setChangeable(true);
	m_expressionInOcl_Attribute_parameterVariable->setUnsettable(false);
	m_expressionInOcl_Attribute_parameterVariable->setUnique(true);
	m_expressionInOcl_Attribute_parameterVariable->setDerived(false);
	m_expressionInOcl_Attribute_parameterVariable->setOrdered(true);
	m_expressionInOcl_Attribute_parameterVariable->setContainment(true);
	m_expressionInOcl_Attribute_parameterVariable->setResolveProxies(true);
	m_expressionInOcl_Attribute_parameterVariable->setDefaultValueLiteral("");	
	
	m_expressionInOcl_Attribute_parameterVariable->_setID(EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE);
	m_expressionInOcl_Attribute_resultVariable->setName("resultVariable");
	m_expressionInOcl_Attribute_resultVariable->setEType(ecore::ecorePackage::eInstance()->getETypedElement_Class());
	m_expressionInOcl_Attribute_resultVariable->setLowerBound(0);
	m_expressionInOcl_Attribute_resultVariable->setUpperBound(1);
	m_expressionInOcl_Attribute_resultVariable->setTransient(false);
	m_expressionInOcl_Attribute_resultVariable->setVolatile(false);
	m_expressionInOcl_Attribute_resultVariable->setChangeable(true);
	m_expressionInOcl_Attribute_resultVariable->setUnsettable(false);
	m_expressionInOcl_Attribute_resultVariable->setUnique(true);
	m_expressionInOcl_Attribute_resultVariable->setDerived(false);
	m_expressionInOcl_Attribute_resultVariable->setOrdered(false);
	m_expressionInOcl_Attribute_resultVariable->setContainment(true);
	m_expressionInOcl_Attribute_resultVariable->setResolveProxies(true);
	m_expressionInOcl_Attribute_resultVariable->setDefaultValueLiteral("");	
	
	m_expressionInOcl_Attribute_resultVariable->_setID(EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeFeatureCallExpContent()
{
	m_featureCallExp_Class->setName("FeatureCallExp");
	m_featureCallExp_Class->setAbstract(true);
	m_featureCallExp_Class->setInterface(false);
	
	m_featureCallExp_Class->_setID(FEATURECALLEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	m_featureCallExp_Attribute_isPre = getFeatureCallExp_Attribute_isPre();
	m_featureCallExp_Attribute_isPre->setName("isPre");
	m_featureCallExp_Attribute_isPre->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_featureCallExp_Attribute_isPre->setLowerBound(0);
	m_featureCallExp_Attribute_isPre->setUpperBound(1);
	m_featureCallExp_Attribute_isPre->setTransient(false);
	m_featureCallExp_Attribute_isPre->setVolatile(false);
	m_featureCallExp_Attribute_isPre->setChangeable(true);
	m_featureCallExp_Attribute_isPre->setUnsettable(false);
	m_featureCallExp_Attribute_isPre->setUnique(true);
	m_featureCallExp_Attribute_isPre->setDerived(false);
	m_featureCallExp_Attribute_isPre->setOrdered(true);
	m_featureCallExp_Attribute_isPre->setID(false);
	m_featureCallExp_Attribute_isPre->setDefaultValueLiteral("");
	
	m_featureCallExp_Attribute_isPre->_setID(FEATURECALLEXP_ATTRIBUTE_ISPRE);
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeIfExpContent()
{
	m_ifExp_Class->setName("IfExp");
	m_ifExp_Class->setAbstract(false);
	m_ifExp_Class->setInterface(false);
	
	m_ifExp_Class->_setID(IFEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_ifExp_Attribute_condition->setName("condition");
	m_ifExp_Attribute_condition->setEType(getOclExpression_Class());
	m_ifExp_Attribute_condition->setLowerBound(1);
	m_ifExp_Attribute_condition->setUpperBound(1);
	m_ifExp_Attribute_condition->setTransient(false);
	m_ifExp_Attribute_condition->setVolatile(false);
	m_ifExp_Attribute_condition->setChangeable(true);
	m_ifExp_Attribute_condition->setUnsettable(false);
	m_ifExp_Attribute_condition->setUnique(true);
	m_ifExp_Attribute_condition->setDerived(false);
	m_ifExp_Attribute_condition->setOrdered(false);
	m_ifExp_Attribute_condition->setContainment(true);
	m_ifExp_Attribute_condition->setResolveProxies(true);
	m_ifExp_Attribute_condition->setDefaultValueLiteral("");	
	m_ifExp_Attribute_condition->setEOpposite(ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Attribute_ifOwner());
	
	m_ifExp_Attribute_condition->_setID(IFEXP_ATTRIBUTE_CONDITION);
	m_ifExp_Attribute_elseExpression->setName("elseExpression");
	m_ifExp_Attribute_elseExpression->setEType(getOclExpression_Class());
	m_ifExp_Attribute_elseExpression->setLowerBound(1);
	m_ifExp_Attribute_elseExpression->setUpperBound(1);
	m_ifExp_Attribute_elseExpression->setTransient(false);
	m_ifExp_Attribute_elseExpression->setVolatile(false);
	m_ifExp_Attribute_elseExpression->setChangeable(true);
	m_ifExp_Attribute_elseExpression->setUnsettable(false);
	m_ifExp_Attribute_elseExpression->setUnique(true);
	m_ifExp_Attribute_elseExpression->setDerived(false);
	m_ifExp_Attribute_elseExpression->setOrdered(false);
	m_ifExp_Attribute_elseExpression->setContainment(true);
	m_ifExp_Attribute_elseExpression->setResolveProxies(true);
	m_ifExp_Attribute_elseExpression->setDefaultValueLiteral("");	
	m_ifExp_Attribute_elseExpression->setEOpposite(ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Attribute_elseOwner());
	
	m_ifExp_Attribute_elseExpression->_setID(IFEXP_ATTRIBUTE_ELSEEXPRESSION);
	m_ifExp_Attribute_thenExpression->setName("thenExpression");
	m_ifExp_Attribute_thenExpression->setEType(getOclExpression_Class());
	m_ifExp_Attribute_thenExpression->setLowerBound(1);
	m_ifExp_Attribute_thenExpression->setUpperBound(1);
	m_ifExp_Attribute_thenExpression->setTransient(false);
	m_ifExp_Attribute_thenExpression->setVolatile(false);
	m_ifExp_Attribute_thenExpression->setChangeable(true);
	m_ifExp_Attribute_thenExpression->setUnsettable(false);
	m_ifExp_Attribute_thenExpression->setUnique(true);
	m_ifExp_Attribute_thenExpression->setDerived(false);
	m_ifExp_Attribute_thenExpression->setOrdered(false);
	m_ifExp_Attribute_thenExpression->setContainment(true);
	m_ifExp_Attribute_thenExpression->setResolveProxies(true);
	m_ifExp_Attribute_thenExpression->setDefaultValueLiteral("");	
	m_ifExp_Attribute_thenExpression->setEOpposite(ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Attribute_thenOwner());
	
	m_ifExp_Attribute_thenExpression->_setID(IFEXP_ATTRIBUTE_THENEXPRESSION);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeInfixedExpContent()
{
	m_infixedExp_Class->setName("InfixedExp");
	m_infixedExp_Class->setAbstract(false);
	m_infixedExp_Class->setInterface(false);
	
	m_infixedExp_Class->_setID(INFIXEDEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_infixedExp_Attribute_source->setName("source");
	m_infixedExp_Attribute_source->setEType(getOclExpression_Class());
	m_infixedExp_Attribute_source->setLowerBound(0);
	m_infixedExp_Attribute_source->setUpperBound(1);
	m_infixedExp_Attribute_source->setTransient(false);
	m_infixedExp_Attribute_source->setVolatile(false);
	m_infixedExp_Attribute_source->setChangeable(true);
	m_infixedExp_Attribute_source->setUnsettable(false);
	m_infixedExp_Attribute_source->setUnique(true);
	m_infixedExp_Attribute_source->setDerived(false);
	m_infixedExp_Attribute_source->setOrdered(true);
	m_infixedExp_Attribute_source->setContainment(false);
	m_infixedExp_Attribute_source->setResolveProxies(true);
	m_infixedExp_Attribute_source->setDefaultValueLiteral("");	
	
	m_infixedExp_Attribute_source->_setID(INFIXEDEXP_ATTRIBUTE_SOURCE);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeInitOrDerValueExpContent()
{
	m_initOrDerValueExp_Class->setName("InitOrDerValueExp");
	m_initOrDerValueExp_Class->setAbstract(false);
	m_initOrDerValueExp_Class->setInterface(false);
	
	m_initOrDerValueExp_Class->_setID(INITORDERVALUEEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	m_initOrDerValueExp_Attribute_kind = getInitOrDerValueExp_Attribute_kind();
	m_initOrDerValueExp_Attribute_kind->setName("kind");
	m_initOrDerValueExp_Attribute_kind->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_initOrDerValueExp_Attribute_kind->setLowerBound(0);
	m_initOrDerValueExp_Attribute_kind->setUpperBound(1);
	m_initOrDerValueExp_Attribute_kind->setTransient(false);
	m_initOrDerValueExp_Attribute_kind->setVolatile(false);
	m_initOrDerValueExp_Attribute_kind->setChangeable(true);
	m_initOrDerValueExp_Attribute_kind->setUnsettable(false);
	m_initOrDerValueExp_Attribute_kind->setUnique(true);
	m_initOrDerValueExp_Attribute_kind->setDerived(false);
	m_initOrDerValueExp_Attribute_kind->setOrdered(true);
	m_initOrDerValueExp_Attribute_kind->setID(false);
	m_initOrDerValueExp_Attribute_kind->setDefaultValueLiteral("");
	
	m_initOrDerValueExp_Attribute_kind->_setID(INITORDERVALUEEXP_ATTRIBUTE_KIND);
	
	/*
	 * EReferences
	 */
	m_initOrDerValueExp_Attribute_bodyExpression->setName("bodyExpression");
	m_initOrDerValueExp_Attribute_bodyExpression->setEType(getOclExpression_Class());
	m_initOrDerValueExp_Attribute_bodyExpression->setLowerBound(0);
	m_initOrDerValueExp_Attribute_bodyExpression->setUpperBound(1);
	m_initOrDerValueExp_Attribute_bodyExpression->setTransient(false);
	m_initOrDerValueExp_Attribute_bodyExpression->setVolatile(false);
	m_initOrDerValueExp_Attribute_bodyExpression->setChangeable(true);
	m_initOrDerValueExp_Attribute_bodyExpression->setUnsettable(false);
	m_initOrDerValueExp_Attribute_bodyExpression->setUnique(true);
	m_initOrDerValueExp_Attribute_bodyExpression->setDerived(false);
	m_initOrDerValueExp_Attribute_bodyExpression->setOrdered(true);
	m_initOrDerValueExp_Attribute_bodyExpression->setContainment(false);
	m_initOrDerValueExp_Attribute_bodyExpression->setResolveProxies(true);
	m_initOrDerValueExp_Attribute_bodyExpression->setDefaultValueLiteral("");	
	
	m_initOrDerValueExp_Attribute_bodyExpression->_setID(INITORDERVALUEEXP_ATTRIBUTE_BODYEXPRESSION);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeInitOrDerValueListExpContent()
{
	m_initOrDerValueListExp_Class->setName("InitOrDerValueListExp");
	m_initOrDerValueListExp_Class->setAbstract(false);
	m_initOrDerValueListExp_Class->setInterface(false);
	
	m_initOrDerValueListExp_Class->_setID(INITORDERVALUELISTEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_initOrDerValueListExp_Attribute_derExpressionList->setName("derExpressionList");
	m_initOrDerValueListExp_Attribute_derExpressionList->setEType(getInitOrDerValueExp_Class());
	m_initOrDerValueListExp_Attribute_derExpressionList->setLowerBound(0);
	m_initOrDerValueListExp_Attribute_derExpressionList->setUpperBound(-1);
	m_initOrDerValueListExp_Attribute_derExpressionList->setTransient(false);
	m_initOrDerValueListExp_Attribute_derExpressionList->setVolatile(false);
	m_initOrDerValueListExp_Attribute_derExpressionList->setChangeable(true);
	m_initOrDerValueListExp_Attribute_derExpressionList->setUnsettable(false);
	m_initOrDerValueListExp_Attribute_derExpressionList->setUnique(true);
	m_initOrDerValueListExp_Attribute_derExpressionList->setDerived(false);
	m_initOrDerValueListExp_Attribute_derExpressionList->setOrdered(true);
	m_initOrDerValueListExp_Attribute_derExpressionList->setContainment(false);
	m_initOrDerValueListExp_Attribute_derExpressionList->setResolveProxies(true);
	m_initOrDerValueListExp_Attribute_derExpressionList->setDefaultValueLiteral("");	
	
	m_initOrDerValueListExp_Attribute_derExpressionList->_setID(INITORDERVALUELISTEXP_ATTRIBUTE_DEREXPRESSIONLIST);
	m_initOrDerValueListExp_Attribute_initExpressionList->setName("initExpressionList");
	m_initOrDerValueListExp_Attribute_initExpressionList->setEType(getInitOrDerValueExp_Class());
	m_initOrDerValueListExp_Attribute_initExpressionList->setLowerBound(0);
	m_initOrDerValueListExp_Attribute_initExpressionList->setUpperBound(-1);
	m_initOrDerValueListExp_Attribute_initExpressionList->setTransient(false);
	m_initOrDerValueListExp_Attribute_initExpressionList->setVolatile(false);
	m_initOrDerValueListExp_Attribute_initExpressionList->setChangeable(true);
	m_initOrDerValueListExp_Attribute_initExpressionList->setUnsettable(false);
	m_initOrDerValueListExp_Attribute_initExpressionList->setUnique(true);
	m_initOrDerValueListExp_Attribute_initExpressionList->setDerived(false);
	m_initOrDerValueListExp_Attribute_initExpressionList->setOrdered(true);
	m_initOrDerValueListExp_Attribute_initExpressionList->setContainment(false);
	m_initOrDerValueListExp_Attribute_initExpressionList->setResolveProxies(true);
	m_initOrDerValueListExp_Attribute_initExpressionList->setDefaultValueLiteral("");	
	
	m_initOrDerValueListExp_Attribute_initExpressionList->_setID(INITORDERVALUELISTEXP_ATTRIBUTE_INITEXPRESSIONLIST);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeIntegerLiteralExpContent()
{
	m_integerLiteralExp_Class->setName("IntegerLiteralExp");
	m_integerLiteralExp_Class->setAbstract(false);
	m_integerLiteralExp_Class->setInterface(false);
	
	m_integerLiteralExp_Class->_setID(INTEGERLITERALEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	m_integerLiteralExp_Attribute_integerSymbol = getIntegerLiteralExp_Attribute_integerSymbol();
	m_integerLiteralExp_Attribute_integerSymbol->setName("integerSymbol");
	m_integerLiteralExp_Attribute_integerSymbol->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
	m_integerLiteralExp_Attribute_integerSymbol->setLowerBound(0);
	m_integerLiteralExp_Attribute_integerSymbol->setUpperBound(1);
	m_integerLiteralExp_Attribute_integerSymbol->setTransient(false);
	m_integerLiteralExp_Attribute_integerSymbol->setVolatile(false);
	m_integerLiteralExp_Attribute_integerSymbol->setChangeable(true);
	m_integerLiteralExp_Attribute_integerSymbol->setUnsettable(false);
	m_integerLiteralExp_Attribute_integerSymbol->setUnique(true);
	m_integerLiteralExp_Attribute_integerSymbol->setDerived(false);
	m_integerLiteralExp_Attribute_integerSymbol->setOrdered(true);
	m_integerLiteralExp_Attribute_integerSymbol->setID(false);
	m_integerLiteralExp_Attribute_integerSymbol->setDefaultValueLiteral("");
	
	m_integerLiteralExp_Attribute_integerSymbol->_setID(INTEGERLITERALEXP_ATTRIBUTE_INTEGERSYMBOL);
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeInvOrDefExpContent()
{
	m_invOrDefExp_Class->setName("InvOrDefExp");
	m_invOrDefExp_Class->setAbstract(false);
	m_invOrDefExp_Class->setInterface(false);
	
	m_invOrDefExp_Class->_setID(INVORDEFEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	m_invOrDefExp_Attribute_kind = getInvOrDefExp_Attribute_kind();
	m_invOrDefExp_Attribute_kind->setName("kind");
	m_invOrDefExp_Attribute_kind->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_invOrDefExp_Attribute_kind->setLowerBound(0);
	m_invOrDefExp_Attribute_kind->setUpperBound(1);
	m_invOrDefExp_Attribute_kind->setTransient(false);
	m_invOrDefExp_Attribute_kind->setVolatile(false);
	m_invOrDefExp_Attribute_kind->setChangeable(true);
	m_invOrDefExp_Attribute_kind->setUnsettable(false);
	m_invOrDefExp_Attribute_kind->setUnique(true);
	m_invOrDefExp_Attribute_kind->setDerived(false);
	m_invOrDefExp_Attribute_kind->setOrdered(true);
	m_invOrDefExp_Attribute_kind->setID(false);
	m_invOrDefExp_Attribute_kind->setDefaultValueLiteral("");
	
	m_invOrDefExp_Attribute_kind->_setID(INVORDEFEXP_ATTRIBUTE_KIND);
	m_invOrDefExp_Attribute_name = getInvOrDefExp_Attribute_name();
	m_invOrDefExp_Attribute_name->setName("name");
	m_invOrDefExp_Attribute_name->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_invOrDefExp_Attribute_name->setLowerBound(0);
	m_invOrDefExp_Attribute_name->setUpperBound(1);
	m_invOrDefExp_Attribute_name->setTransient(false);
	m_invOrDefExp_Attribute_name->setVolatile(false);
	m_invOrDefExp_Attribute_name->setChangeable(true);
	m_invOrDefExp_Attribute_name->setUnsettable(false);
	m_invOrDefExp_Attribute_name->setUnique(true);
	m_invOrDefExp_Attribute_name->setDerived(false);
	m_invOrDefExp_Attribute_name->setOrdered(true);
	m_invOrDefExp_Attribute_name->setID(false);
	m_invOrDefExp_Attribute_name->setDefaultValueLiteral("");
	
	m_invOrDefExp_Attribute_name->_setID(INVORDEFEXP_ATTRIBUTE_NAME);
	
	/*
	 * EReferences
	 */
	m_invOrDefExp_Attribute_referredExpression->setName("referredExpression");
	m_invOrDefExp_Attribute_referredExpression->setEType(getOclExpression_Class());
	m_invOrDefExp_Attribute_referredExpression->setLowerBound(0);
	m_invOrDefExp_Attribute_referredExpression->setUpperBound(1);
	m_invOrDefExp_Attribute_referredExpression->setTransient(false);
	m_invOrDefExp_Attribute_referredExpression->setVolatile(false);
	m_invOrDefExp_Attribute_referredExpression->setChangeable(true);
	m_invOrDefExp_Attribute_referredExpression->setUnsettable(false);
	m_invOrDefExp_Attribute_referredExpression->setUnique(true);
	m_invOrDefExp_Attribute_referredExpression->setDerived(false);
	m_invOrDefExp_Attribute_referredExpression->setOrdered(true);
	m_invOrDefExp_Attribute_referredExpression->setContainment(false);
	m_invOrDefExp_Attribute_referredExpression->setResolveProxies(true);
	m_invOrDefExp_Attribute_referredExpression->setDefaultValueLiteral("");	
	
	m_invOrDefExp_Attribute_referredExpression->_setID(INVORDEFEXP_ATTRIBUTE_REFERREDEXPRESSION);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeInvalidLiteralExpContent()
{
	m_invalidLiteralExp_Class->setName("InvalidLiteralExp");
	m_invalidLiteralExp_Class->setAbstract(false);
	m_invalidLiteralExp_Class->setInterface(false);
	
	m_invalidLiteralExp_Class->_setID(INVALIDLITERALEXP_CLASS);
	
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

void ExpressionsPackageImpl::initializeIterateExpContent()
{
	m_iterateExp_Class->setName("IterateExp");
	m_iterateExp_Class->setAbstract(false);
	m_iterateExp_Class->setInterface(false);
	
	m_iterateExp_Class->_setID(ITERATEEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_iterateExp_Attribute_result->setName("result");
	m_iterateExp_Attribute_result->setEType(ecore::ecorePackage::eInstance()->getETypedElement_Class());
	m_iterateExp_Attribute_result->setLowerBound(0);
	m_iterateExp_Attribute_result->setUpperBound(1);
	m_iterateExp_Attribute_result->setTransient(false);
	m_iterateExp_Attribute_result->setVolatile(false);
	m_iterateExp_Attribute_result->setChangeable(true);
	m_iterateExp_Attribute_result->setUnsettable(false);
	m_iterateExp_Attribute_result->setUnique(true);
	m_iterateExp_Attribute_result->setDerived(false);
	m_iterateExp_Attribute_result->setOrdered(false);
	m_iterateExp_Attribute_result->setContainment(true);
	m_iterateExp_Attribute_result->setResolveProxies(true);
	m_iterateExp_Attribute_result->setDefaultValueLiteral("");	
	
	m_iterateExp_Attribute_result->_setID(ITERATEEXP_ATTRIBUTE_RESULT);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeIteratorExpContent()
{
	m_iteratorExp_Class->setName("IteratorExp");
	m_iteratorExp_Class->setAbstract(false);
	m_iteratorExp_Class->setInterface(false);
	
	m_iteratorExp_Class->_setID(ITERATOREXP_CLASS);
	
	/*
	 * EAttributes
	 */
	m_iteratorExp_Attribute_sourrundedBy = getIteratorExp_Attribute_sourrundedBy();
	m_iteratorExp_Attribute_sourrundedBy->setName("sourrundedBy");
	m_iteratorExp_Attribute_sourrundedBy->setEType(getSurroundingType_Class());
	m_iteratorExp_Attribute_sourrundedBy->setLowerBound(0);
	m_iteratorExp_Attribute_sourrundedBy->setUpperBound(1);
	m_iteratorExp_Attribute_sourrundedBy->setTransient(false);
	m_iteratorExp_Attribute_sourrundedBy->setVolatile(false);
	m_iteratorExp_Attribute_sourrundedBy->setChangeable(true);
	m_iteratorExp_Attribute_sourrundedBy->setUnsettable(false);
	m_iteratorExp_Attribute_sourrundedBy->setUnique(true);
	m_iteratorExp_Attribute_sourrundedBy->setDerived(false);
	m_iteratorExp_Attribute_sourrundedBy->setOrdered(true);
	m_iteratorExp_Attribute_sourrundedBy->setID(false);
	m_iteratorExp_Attribute_sourrundedBy->setDefaultValueLiteral("");
	
	m_iteratorExp_Attribute_sourrundedBy->_setID(ITERATOREXP_ATTRIBUTE_SOURRUNDEDBY);
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeLetExpContent()
{
	m_letExp_Class->setName("LetExp");
	m_letExp_Class->setAbstract(false);
	m_letExp_Class->setInterface(false);
	
	m_letExp_Class->_setID(LETEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_letExp_Attribute_in->setName("in");
	m_letExp_Attribute_in->setEType(getOclExpression_Class());
	m_letExp_Attribute_in->setLowerBound(1);
	m_letExp_Attribute_in->setUpperBound(1);
	m_letExp_Attribute_in->setTransient(false);
	m_letExp_Attribute_in->setVolatile(false);
	m_letExp_Attribute_in->setChangeable(true);
	m_letExp_Attribute_in->setUnsettable(false);
	m_letExp_Attribute_in->setUnique(true);
	m_letExp_Attribute_in->setDerived(false);
	m_letExp_Attribute_in->setOrdered(false);
	m_letExp_Attribute_in->setContainment(true);
	m_letExp_Attribute_in->setResolveProxies(true);
	m_letExp_Attribute_in->setDefaultValueLiteral("");	
	
	m_letExp_Attribute_in->_setID(LETEXP_ATTRIBUTE_IN);
	m_letExp_Attribute_variables->setName("variables");
	m_letExp_Attribute_variables->setEType(getVarDeclarationExp_Class());
	m_letExp_Attribute_variables->setLowerBound(1);
	m_letExp_Attribute_variables->setUpperBound(-1);
	m_letExp_Attribute_variables->setTransient(false);
	m_letExp_Attribute_variables->setVolatile(false);
	m_letExp_Attribute_variables->setChangeable(true);
	m_letExp_Attribute_variables->setUnsettable(false);
	m_letExp_Attribute_variables->setUnique(true);
	m_letExp_Attribute_variables->setDerived(false);
	m_letExp_Attribute_variables->setOrdered(true);
	m_letExp_Attribute_variables->setContainment(true);
	m_letExp_Attribute_variables->setResolveProxies(true);
	m_letExp_Attribute_variables->setDefaultValueLiteral("");	
	
	m_letExp_Attribute_variables->_setID(LETEXP_ATTRIBUTE_VARIABLES);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeLiteralExpContent()
{
	m_literalExp_Class->setName("LiteralExp");
	m_literalExp_Class->setAbstract(true);
	m_literalExp_Class->setInterface(false);
	
	m_literalExp_Class->_setID(LITERALEXP_CLASS);
	
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

void ExpressionsPackageImpl::initializeLoopExpContent()
{
	m_loopExp_Class->setName("LoopExp");
	m_loopExp_Class->setAbstract(true);
	m_loopExp_Class->setInterface(false);
	
	m_loopExp_Class->_setID(LOOPEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	m_loopExp_Attribute_isCollectionOperation = getLoopExp_Attribute_isCollectionOperation();
	m_loopExp_Attribute_isCollectionOperation->setName("isCollectionOperation");
	m_loopExp_Attribute_isCollectionOperation->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_loopExp_Attribute_isCollectionOperation->setLowerBound(0);
	m_loopExp_Attribute_isCollectionOperation->setUpperBound(1);
	m_loopExp_Attribute_isCollectionOperation->setTransient(false);
	m_loopExp_Attribute_isCollectionOperation->setVolatile(false);
	m_loopExp_Attribute_isCollectionOperation->setChangeable(true);
	m_loopExp_Attribute_isCollectionOperation->setUnsettable(false);
	m_loopExp_Attribute_isCollectionOperation->setUnique(true);
	m_loopExp_Attribute_isCollectionOperation->setDerived(false);
	m_loopExp_Attribute_isCollectionOperation->setOrdered(true);
	m_loopExp_Attribute_isCollectionOperation->setID(false);
	m_loopExp_Attribute_isCollectionOperation->setDefaultValueLiteral("");
	
	m_loopExp_Attribute_isCollectionOperation->_setID(LOOPEXP_ATTRIBUTE_ISCOLLECTIONOPERATION);
	m_loopExp_Attribute_isImplCollectIterator = getLoopExp_Attribute_isImplCollectIterator();
	m_loopExp_Attribute_isImplCollectIterator->setName("isImplCollectIterator");
	m_loopExp_Attribute_isImplCollectIterator->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_loopExp_Attribute_isImplCollectIterator->setLowerBound(0);
	m_loopExp_Attribute_isImplCollectIterator->setUpperBound(1);
	m_loopExp_Attribute_isImplCollectIterator->setTransient(false);
	m_loopExp_Attribute_isImplCollectIterator->setVolatile(false);
	m_loopExp_Attribute_isImplCollectIterator->setChangeable(true);
	m_loopExp_Attribute_isImplCollectIterator->setUnsettable(false);
	m_loopExp_Attribute_isImplCollectIterator->setUnique(true);
	m_loopExp_Attribute_isImplCollectIterator->setDerived(false);
	m_loopExp_Attribute_isImplCollectIterator->setOrdered(true);
	m_loopExp_Attribute_isImplCollectIterator->setID(false);
	m_loopExp_Attribute_isImplCollectIterator->setDefaultValueLiteral("");
	
	m_loopExp_Attribute_isImplCollectIterator->_setID(LOOPEXP_ATTRIBUTE_ISIMPLCOLLECTITERATOR);
	m_loopExp_Attribute_iterName = getLoopExp_Attribute_iterName();
	m_loopExp_Attribute_iterName->setName("iterName");
	m_loopExp_Attribute_iterName->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_loopExp_Attribute_iterName->setLowerBound(0);
	m_loopExp_Attribute_iterName->setUpperBound(1);
	m_loopExp_Attribute_iterName->setTransient(false);
	m_loopExp_Attribute_iterName->setVolatile(false);
	m_loopExp_Attribute_iterName->setChangeable(true);
	m_loopExp_Attribute_iterName->setUnsettable(false);
	m_loopExp_Attribute_iterName->setUnique(true);
	m_loopExp_Attribute_iterName->setDerived(false);
	m_loopExp_Attribute_iterName->setOrdered(true);
	m_loopExp_Attribute_iterName->setID(false);
	m_loopExp_Attribute_iterName->setDefaultValueLiteral("");
	
	m_loopExp_Attribute_iterName->_setID(LOOPEXP_ATTRIBUTE_ITERNAME);
	
	/*
	 * EReferences
	 */
	m_loopExp_Attribute_body->setName("body");
	m_loopExp_Attribute_body->setEType(getOclExpression_Class());
	m_loopExp_Attribute_body->setLowerBound(1);
	m_loopExp_Attribute_body->setUpperBound(1);
	m_loopExp_Attribute_body->setTransient(false);
	m_loopExp_Attribute_body->setVolatile(false);
	m_loopExp_Attribute_body->setChangeable(true);
	m_loopExp_Attribute_body->setUnsettable(false);
	m_loopExp_Attribute_body->setUnique(true);
	m_loopExp_Attribute_body->setDerived(false);
	m_loopExp_Attribute_body->setOrdered(false);
	m_loopExp_Attribute_body->setContainment(true);
	m_loopExp_Attribute_body->setResolveProxies(true);
	m_loopExp_Attribute_body->setDefaultValueLiteral("");	
	m_loopExp_Attribute_body->setEOpposite(ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Attribute_loopBodyOwner());
	
	m_loopExp_Attribute_body->_setID(LOOPEXP_ATTRIBUTE_BODY);
	m_loopExp_Attribute_iterator->setName("iterator");
	m_loopExp_Attribute_iterator->setEType(getOclExpression_Class());
	m_loopExp_Attribute_iterator->setLowerBound(0);
	m_loopExp_Attribute_iterator->setUpperBound(-1);
	m_loopExp_Attribute_iterator->setTransient(false);
	m_loopExp_Attribute_iterator->setVolatile(false);
	m_loopExp_Attribute_iterator->setChangeable(true);
	m_loopExp_Attribute_iterator->setUnsettable(false);
	m_loopExp_Attribute_iterator->setUnique(true);
	m_loopExp_Attribute_iterator->setDerived(false);
	m_loopExp_Attribute_iterator->setOrdered(true);
	m_loopExp_Attribute_iterator->setContainment(true);
	m_loopExp_Attribute_iterator->setResolveProxies(true);
	m_loopExp_Attribute_iterator->setDefaultValueLiteral("");	
	m_loopExp_Attribute_iterator->setEOpposite(ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Attribute_loopExp());
	
	m_loopExp_Attribute_iterator->_setID(LOOPEXP_ATTRIBUTE_ITERATOR);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeMessageArgumentsContent()
{
	m_messageArguments_Class->setName("MessageArguments");
	m_messageArguments_Class->setAbstract(false);
	m_messageArguments_Class->setInterface(false);
	
	m_messageArguments_Class->_setID(MESSAGEARGUMENTS_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_messageArguments_Attribute_referredOclExpressions->setName("referredOclExpressions");
	m_messageArguments_Attribute_referredOclExpressions->setEType(getOclExpression_Class());
	m_messageArguments_Attribute_referredOclExpressions->setLowerBound(0);
	m_messageArguments_Attribute_referredOclExpressions->setUpperBound(-1);
	m_messageArguments_Attribute_referredOclExpressions->setTransient(false);
	m_messageArguments_Attribute_referredOclExpressions->setVolatile(false);
	m_messageArguments_Attribute_referredOclExpressions->setChangeable(true);
	m_messageArguments_Attribute_referredOclExpressions->setUnsettable(false);
	m_messageArguments_Attribute_referredOclExpressions->setUnique(true);
	m_messageArguments_Attribute_referredOclExpressions->setDerived(false);
	m_messageArguments_Attribute_referredOclExpressions->setOrdered(true);
	m_messageArguments_Attribute_referredOclExpressions->setContainment(false);
	m_messageArguments_Attribute_referredOclExpressions->setResolveProxies(true);
	m_messageArguments_Attribute_referredOclExpressions->setDefaultValueLiteral("");	
	
	m_messageArguments_Attribute_referredOclExpressions->_setID(MESSAGEARGUMENTS_ATTRIBUTE_REFERREDOCLEXPRESSIONS);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeMessageExpContent()
{
	m_messageExp_Class->setName("MessageExp");
	m_messageExp_Class->setAbstract(false);
	m_messageExp_Class->setInterface(false);
	
	m_messageExp_Class->_setID(MESSAGEEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	m_messageExp_Attribute_calledOperation = getMessageExp_Attribute_calledOperation();
	m_messageExp_Attribute_calledOperation->setName("calledOperation");
	m_messageExp_Attribute_calledOperation->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_messageExp_Attribute_calledOperation->setLowerBound(0);
	m_messageExp_Attribute_calledOperation->setUpperBound(1);
	m_messageExp_Attribute_calledOperation->setTransient(false);
	m_messageExp_Attribute_calledOperation->setVolatile(false);
	m_messageExp_Attribute_calledOperation->setChangeable(true);
	m_messageExp_Attribute_calledOperation->setUnsettable(false);
	m_messageExp_Attribute_calledOperation->setUnique(true);
	m_messageExp_Attribute_calledOperation->setDerived(false);
	m_messageExp_Attribute_calledOperation->setOrdered(true);
	m_messageExp_Attribute_calledOperation->setID(false);
	m_messageExp_Attribute_calledOperation->setDefaultValueLiteral("");
	
	m_messageExp_Attribute_calledOperation->_setID(MESSAGEEXP_ATTRIBUTE_CALLEDOPERATION);
	m_messageExp_Attribute_sentSignal = getMessageExp_Attribute_sentSignal();
	m_messageExp_Attribute_sentSignal->setName("sentSignal");
	m_messageExp_Attribute_sentSignal->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_messageExp_Attribute_sentSignal->setLowerBound(0);
	m_messageExp_Attribute_sentSignal->setUpperBound(1);
	m_messageExp_Attribute_sentSignal->setTransient(false);
	m_messageExp_Attribute_sentSignal->setVolatile(false);
	m_messageExp_Attribute_sentSignal->setChangeable(true);
	m_messageExp_Attribute_sentSignal->setUnsettable(false);
	m_messageExp_Attribute_sentSignal->setUnique(true);
	m_messageExp_Attribute_sentSignal->setDerived(false);
	m_messageExp_Attribute_sentSignal->setOrdered(true);
	m_messageExp_Attribute_sentSignal->setID(false);
	m_messageExp_Attribute_sentSignal->setDefaultValueLiteral("");
	
	m_messageExp_Attribute_sentSignal->_setID(MESSAGEEXP_ATTRIBUTE_SENTSIGNAL);
	
	/*
	 * EReferences
	 */
	m_messageExp_Attribute_argument->setName("argument");
	m_messageExp_Attribute_argument->setEType(getOclExpression_Class());
	m_messageExp_Attribute_argument->setLowerBound(0);
	m_messageExp_Attribute_argument->setUpperBound(-1);
	m_messageExp_Attribute_argument->setTransient(false);
	m_messageExp_Attribute_argument->setVolatile(false);
	m_messageExp_Attribute_argument->setChangeable(true);
	m_messageExp_Attribute_argument->setUnsettable(false);
	m_messageExp_Attribute_argument->setUnique(true);
	m_messageExp_Attribute_argument->setDerived(false);
	m_messageExp_Attribute_argument->setOrdered(true);
	m_messageExp_Attribute_argument->setContainment(false);
	m_messageExp_Attribute_argument->setResolveProxies(true);
	m_messageExp_Attribute_argument->setDefaultValueLiteral("");	
	
	m_messageExp_Attribute_argument->_setID(MESSAGEEXP_ATTRIBUTE_ARGUMENT);
	m_messageExp_Attribute_target->setName("target");
	m_messageExp_Attribute_target->setEType(getOclExpression_Class());
	m_messageExp_Attribute_target->setLowerBound(0);
	m_messageExp_Attribute_target->setUpperBound(1);
	m_messageExp_Attribute_target->setTransient(false);
	m_messageExp_Attribute_target->setVolatile(false);
	m_messageExp_Attribute_target->setChangeable(true);
	m_messageExp_Attribute_target->setUnsettable(false);
	m_messageExp_Attribute_target->setUnique(true);
	m_messageExp_Attribute_target->setDerived(false);
	m_messageExp_Attribute_target->setOrdered(true);
	m_messageExp_Attribute_target->setContainment(false);
	m_messageExp_Attribute_target->setResolveProxies(true);
	m_messageExp_Attribute_target->setDefaultValueLiteral("");	
	
	m_messageExp_Attribute_target->_setID(MESSAGEEXP_ATTRIBUTE_TARGET);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeNavigationCallExpContent()
{
	m_navigationCallExp_Class->setName("NavigationCallExp");
	m_navigationCallExp_Class->setAbstract(true);
	m_navigationCallExp_Class->setInterface(false);
	
	m_navigationCallExp_Class->_setID(NAVIGATIONCALLEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	m_navigationCallExp_Attribute_navigationSource = getNavigationCallExp_Attribute_navigationSource();
	m_navigationCallExp_Attribute_navigationSource->setName("navigationSource");
	m_navigationCallExp_Attribute_navigationSource->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_navigationCallExp_Attribute_navigationSource->setLowerBound(0);
	m_navigationCallExp_Attribute_navigationSource->setUpperBound(1);
	m_navigationCallExp_Attribute_navigationSource->setTransient(false);
	m_navigationCallExp_Attribute_navigationSource->setVolatile(false);
	m_navigationCallExp_Attribute_navigationSource->setChangeable(true);
	m_navigationCallExp_Attribute_navigationSource->setUnsettable(false);
	m_navigationCallExp_Attribute_navigationSource->setUnique(true);
	m_navigationCallExp_Attribute_navigationSource->setDerived(false);
	m_navigationCallExp_Attribute_navigationSource->setOrdered(true);
	m_navigationCallExp_Attribute_navigationSource->setID(false);
	m_navigationCallExp_Attribute_navigationSource->setDefaultValueLiteral("");
	
	m_navigationCallExp_Attribute_navigationSource->_setID(NAVIGATIONCALLEXP_ATTRIBUTE_NAVIGATIONSOURCE);
	
	/*
	 * EReferences
	 */
	m_navigationCallExp_Attribute_qualifier->setName("qualifier");
	m_navigationCallExp_Attribute_qualifier->setEType(getOclExpression_Class());
	m_navigationCallExp_Attribute_qualifier->setLowerBound(0);
	m_navigationCallExp_Attribute_qualifier->setUpperBound(-1);
	m_navigationCallExp_Attribute_qualifier->setTransient(false);
	m_navigationCallExp_Attribute_qualifier->setVolatile(false);
	m_navigationCallExp_Attribute_qualifier->setChangeable(true);
	m_navigationCallExp_Attribute_qualifier->setUnsettable(false);
	m_navigationCallExp_Attribute_qualifier->setUnique(true);
	m_navigationCallExp_Attribute_qualifier->setDerived(false);
	m_navigationCallExp_Attribute_qualifier->setOrdered(true);
	m_navigationCallExp_Attribute_qualifier->setContainment(true);
	m_navigationCallExp_Attribute_qualifier->setResolveProxies(true);
	m_navigationCallExp_Attribute_qualifier->setDefaultValueLiteral("");	
	m_navigationCallExp_Attribute_qualifier->setEOpposite(ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Attribute_parentNav());
	
	m_navigationCallExp_Attribute_qualifier->_setID(NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeNullLiteralExpContent()
{
	m_nullLiteralExp_Class->setName("NullLiteralExp");
	m_nullLiteralExp_Class->setAbstract(false);
	m_nullLiteralExp_Class->setInterface(false);
	
	m_nullLiteralExp_Class->_setID(NULLLITERALEXP_CLASS);
	
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

void ExpressionsPackageImpl::initializeNumericLiteralExpContent()
{
	m_numericLiteralExp_Class->setName("NumericLiteralExp");
	m_numericLiteralExp_Class->setAbstract(true);
	m_numericLiteralExp_Class->setInterface(false);
	
	m_numericLiteralExp_Class->_setID(NUMERICLITERALEXP_CLASS);
	
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

void ExpressionsPackageImpl::initializeOclExpressionContent()
{
	m_oclExpression_Class->setName("OclExpression");
	m_oclExpression_Class->setAbstract(true);
	m_oclExpression_Class->setInterface(false);
	
	m_oclExpression_Class->_setID(OCLEXPRESSION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_oclExpression_Attribute_appliedElement->setName("appliedElement");
	m_oclExpression_Attribute_appliedElement->setEType(getCallExp_Class());
	m_oclExpression_Attribute_appliedElement->setLowerBound(0);
	m_oclExpression_Attribute_appliedElement->setUpperBound(1);
	m_oclExpression_Attribute_appliedElement->setTransient(false);
	m_oclExpression_Attribute_appliedElement->setVolatile(false);
	m_oclExpression_Attribute_appliedElement->setChangeable(true);
	m_oclExpression_Attribute_appliedElement->setUnsettable(false);
	m_oclExpression_Attribute_appliedElement->setUnique(true);
	m_oclExpression_Attribute_appliedElement->setDerived(false);
	m_oclExpression_Attribute_appliedElement->setOrdered(true);
	m_oclExpression_Attribute_appliedElement->setContainment(false);
	m_oclExpression_Attribute_appliedElement->setResolveProxies(true);
	m_oclExpression_Attribute_appliedElement->setDefaultValueLiteral("");	
	
	m_oclExpression_Attribute_appliedElement->_setID(OCLEXPRESSION_ATTRIBUTE_APPLIEDELEMENT);
	m_oclExpression_Attribute_elseOwner->setName("elseOwner");
	m_oclExpression_Attribute_elseOwner->setEType(getIfExp_Class());
	m_oclExpression_Attribute_elseOwner->setLowerBound(0);
	m_oclExpression_Attribute_elseOwner->setUpperBound(1);
	m_oclExpression_Attribute_elseOwner->setTransient(false);
	m_oclExpression_Attribute_elseOwner->setVolatile(false);
	m_oclExpression_Attribute_elseOwner->setChangeable(true);
	m_oclExpression_Attribute_elseOwner->setUnsettable(false);
	m_oclExpression_Attribute_elseOwner->setUnique(true);
	m_oclExpression_Attribute_elseOwner->setDerived(false);
	m_oclExpression_Attribute_elseOwner->setOrdered(true);
	m_oclExpression_Attribute_elseOwner->setContainment(false);
	m_oclExpression_Attribute_elseOwner->setResolveProxies(true);
	m_oclExpression_Attribute_elseOwner->setDefaultValueLiteral("");	
	m_oclExpression_Attribute_elseOwner->setEOpposite(ocl::Expressions::ExpressionsPackage::eInstance()->getIfExp_Attribute_elseExpression());
	
	m_oclExpression_Attribute_elseOwner->_setID(OCLEXPRESSION_ATTRIBUTE_ELSEOWNER);
	m_oclExpression_Attribute_firstOwner->setName("firstOwner");
	m_oclExpression_Attribute_firstOwner->setEType(getCollectionRange_Class());
	m_oclExpression_Attribute_firstOwner->setLowerBound(0);
	m_oclExpression_Attribute_firstOwner->setUpperBound(1);
	m_oclExpression_Attribute_firstOwner->setTransient(false);
	m_oclExpression_Attribute_firstOwner->setVolatile(false);
	m_oclExpression_Attribute_firstOwner->setChangeable(true);
	m_oclExpression_Attribute_firstOwner->setUnsettable(false);
	m_oclExpression_Attribute_firstOwner->setUnique(true);
	m_oclExpression_Attribute_firstOwner->setDerived(false);
	m_oclExpression_Attribute_firstOwner->setOrdered(true);
	m_oclExpression_Attribute_firstOwner->setContainment(false);
	m_oclExpression_Attribute_firstOwner->setResolveProxies(true);
	m_oclExpression_Attribute_firstOwner->setDefaultValueLiteral("");	
	m_oclExpression_Attribute_firstOwner->setEOpposite(ocl::Expressions::ExpressionsPackage::eInstance()->getCollectionRange_Attribute_first());
	
	m_oclExpression_Attribute_firstOwner->_setID(OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER);
	m_oclExpression_Attribute_ifOwner->setName("ifOwner");
	m_oclExpression_Attribute_ifOwner->setEType(getIfExp_Class());
	m_oclExpression_Attribute_ifOwner->setLowerBound(0);
	m_oclExpression_Attribute_ifOwner->setUpperBound(1);
	m_oclExpression_Attribute_ifOwner->setTransient(false);
	m_oclExpression_Attribute_ifOwner->setVolatile(false);
	m_oclExpression_Attribute_ifOwner->setChangeable(true);
	m_oclExpression_Attribute_ifOwner->setUnsettable(false);
	m_oclExpression_Attribute_ifOwner->setUnique(true);
	m_oclExpression_Attribute_ifOwner->setDerived(false);
	m_oclExpression_Attribute_ifOwner->setOrdered(true);
	m_oclExpression_Attribute_ifOwner->setContainment(false);
	m_oclExpression_Attribute_ifOwner->setResolveProxies(true);
	m_oclExpression_Attribute_ifOwner->setDefaultValueLiteral("");	
	m_oclExpression_Attribute_ifOwner->setEOpposite(ocl::Expressions::ExpressionsPackage::eInstance()->getIfExp_Attribute_condition());
	
	m_oclExpression_Attribute_ifOwner->_setID(OCLEXPRESSION_ATTRIBUTE_IFOWNER);
	m_oclExpression_Attribute_initializedElement->setName("initializedElement");
	m_oclExpression_Attribute_initializedElement->setEType(getVarDeclarationExp_Class());
	m_oclExpression_Attribute_initializedElement->setLowerBound(0);
	m_oclExpression_Attribute_initializedElement->setUpperBound(-1);
	m_oclExpression_Attribute_initializedElement->setTransient(false);
	m_oclExpression_Attribute_initializedElement->setVolatile(false);
	m_oclExpression_Attribute_initializedElement->setChangeable(true);
	m_oclExpression_Attribute_initializedElement->setUnsettable(false);
	m_oclExpression_Attribute_initializedElement->setUnique(true);
	m_oclExpression_Attribute_initializedElement->setDerived(false);
	m_oclExpression_Attribute_initializedElement->setOrdered(true);
	m_oclExpression_Attribute_initializedElement->setContainment(true);
	m_oclExpression_Attribute_initializedElement->setResolveProxies(true);
	m_oclExpression_Attribute_initializedElement->setDefaultValueLiteral("");	
	m_oclExpression_Attribute_initializedElement->setEOpposite(ocl::Expressions::ExpressionsPackage::eInstance()->getVarDeclarationExp_Attribute_initExpression());
	
	m_oclExpression_Attribute_initializedElement->_setID(OCLEXPRESSION_ATTRIBUTE_INITIALIZEDELEMENT);
	m_oclExpression_Attribute_instance->setName("instance");
	m_oclExpression_Attribute_instance->setEType(ocl::Evaluations::EvaluationsPackage::eInstance()->getOclExpEval_Class());
	m_oclExpression_Attribute_instance->setLowerBound(0);
	m_oclExpression_Attribute_instance->setUpperBound(1);
	m_oclExpression_Attribute_instance->setTransient(false);
	m_oclExpression_Attribute_instance->setVolatile(false);
	m_oclExpression_Attribute_instance->setChangeable(true);
	m_oclExpression_Attribute_instance->setUnsettable(false);
	m_oclExpression_Attribute_instance->setUnique(true);
	m_oclExpression_Attribute_instance->setDerived(false);
	m_oclExpression_Attribute_instance->setOrdered(true);
	m_oclExpression_Attribute_instance->setContainment(false);
	m_oclExpression_Attribute_instance->setResolveProxies(true);
	m_oclExpression_Attribute_instance->setDefaultValueLiteral("");	
	m_oclExpression_Attribute_instance->setEOpposite(ocl::Evaluations::EvaluationsPackage::eInstance()->getOclExpEval_Attribute_model());
	
	m_oclExpression_Attribute_instance->_setID(OCLEXPRESSION_ATTRIBUTE_INSTANCE);
	m_oclExpression_Attribute_lastOwner->setName("lastOwner");
	m_oclExpression_Attribute_lastOwner->setEType(getCollectionRange_Class());
	m_oclExpression_Attribute_lastOwner->setLowerBound(0);
	m_oclExpression_Attribute_lastOwner->setUpperBound(1);
	m_oclExpression_Attribute_lastOwner->setTransient(false);
	m_oclExpression_Attribute_lastOwner->setVolatile(false);
	m_oclExpression_Attribute_lastOwner->setChangeable(true);
	m_oclExpression_Attribute_lastOwner->setUnsettable(false);
	m_oclExpression_Attribute_lastOwner->setUnique(true);
	m_oclExpression_Attribute_lastOwner->setDerived(false);
	m_oclExpression_Attribute_lastOwner->setOrdered(true);
	m_oclExpression_Attribute_lastOwner->setContainment(false);
	m_oclExpression_Attribute_lastOwner->setResolveProxies(true);
	m_oclExpression_Attribute_lastOwner->setDefaultValueLiteral("");	
	m_oclExpression_Attribute_lastOwner->setEOpposite(ocl::Expressions::ExpressionsPackage::eInstance()->getCollectionRange_Attribute_last());
	
	m_oclExpression_Attribute_lastOwner->_setID(OCLEXPRESSION_ATTRIBUTE_LASTOWNER);
	m_oclExpression_Attribute_loopBodyOwner->setName("loopBodyOwner");
	m_oclExpression_Attribute_loopBodyOwner->setEType(getLoopExp_Class());
	m_oclExpression_Attribute_loopBodyOwner->setLowerBound(0);
	m_oclExpression_Attribute_loopBodyOwner->setUpperBound(1);
	m_oclExpression_Attribute_loopBodyOwner->setTransient(false);
	m_oclExpression_Attribute_loopBodyOwner->setVolatile(false);
	m_oclExpression_Attribute_loopBodyOwner->setChangeable(true);
	m_oclExpression_Attribute_loopBodyOwner->setUnsettable(false);
	m_oclExpression_Attribute_loopBodyOwner->setUnique(true);
	m_oclExpression_Attribute_loopBodyOwner->setDerived(false);
	m_oclExpression_Attribute_loopBodyOwner->setOrdered(true);
	m_oclExpression_Attribute_loopBodyOwner->setContainment(false);
	m_oclExpression_Attribute_loopBodyOwner->setResolveProxies(true);
	m_oclExpression_Attribute_loopBodyOwner->setDefaultValueLiteral("");	
	m_oclExpression_Attribute_loopBodyOwner->setEOpposite(ocl::Expressions::ExpressionsPackage::eInstance()->getLoopExp_Attribute_body());
	
	m_oclExpression_Attribute_loopBodyOwner->_setID(OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER);
	m_oclExpression_Attribute_loopExp->setName("loopExp");
	m_oclExpression_Attribute_loopExp->setEType(getLoopExp_Class());
	m_oclExpression_Attribute_loopExp->setLowerBound(0);
	m_oclExpression_Attribute_loopExp->setUpperBound(1);
	m_oclExpression_Attribute_loopExp->setTransient(false);
	m_oclExpression_Attribute_loopExp->setVolatile(false);
	m_oclExpression_Attribute_loopExp->setChangeable(true);
	m_oclExpression_Attribute_loopExp->setUnsettable(false);
	m_oclExpression_Attribute_loopExp->setUnique(true);
	m_oclExpression_Attribute_loopExp->setDerived(false);
	m_oclExpression_Attribute_loopExp->setOrdered(true);
	m_oclExpression_Attribute_loopExp->setContainment(false);
	m_oclExpression_Attribute_loopExp->setResolveProxies(true);
	m_oclExpression_Attribute_loopExp->setDefaultValueLiteral("");	
	m_oclExpression_Attribute_loopExp->setEOpposite(ocl::Expressions::ExpressionsPackage::eInstance()->getLoopExp_Attribute_iterator());
	
	m_oclExpression_Attribute_loopExp->_setID(OCLEXPRESSION_ATTRIBUTE_LOOPEXP);
	m_oclExpression_Attribute_parentCall->setName("parentCall");
	m_oclExpression_Attribute_parentCall->setEType(getOperationCallExp_Class());
	m_oclExpression_Attribute_parentCall->setLowerBound(0);
	m_oclExpression_Attribute_parentCall->setUpperBound(1);
	m_oclExpression_Attribute_parentCall->setTransient(false);
	m_oclExpression_Attribute_parentCall->setVolatile(false);
	m_oclExpression_Attribute_parentCall->setChangeable(true);
	m_oclExpression_Attribute_parentCall->setUnsettable(false);
	m_oclExpression_Attribute_parentCall->setUnique(true);
	m_oclExpression_Attribute_parentCall->setDerived(false);
	m_oclExpression_Attribute_parentCall->setOrdered(true);
	m_oclExpression_Attribute_parentCall->setContainment(false);
	m_oclExpression_Attribute_parentCall->setResolveProxies(true);
	m_oclExpression_Attribute_parentCall->setDefaultValueLiteral("");	
	m_oclExpression_Attribute_parentCall->setEOpposite(ocl::Expressions::ExpressionsPackage::eInstance()->getOperationCallExp_Attribute_argument());
	
	m_oclExpression_Attribute_parentCall->_setID(OCLEXPRESSION_ATTRIBUTE_PARENTCALL);
	m_oclExpression_Attribute_parentNav->setName("parentNav");
	m_oclExpression_Attribute_parentNav->setEType(getNavigationCallExp_Class());
	m_oclExpression_Attribute_parentNav->setLowerBound(0);
	m_oclExpression_Attribute_parentNav->setUpperBound(1);
	m_oclExpression_Attribute_parentNav->setTransient(false);
	m_oclExpression_Attribute_parentNav->setVolatile(false);
	m_oclExpression_Attribute_parentNav->setChangeable(true);
	m_oclExpression_Attribute_parentNav->setUnsettable(false);
	m_oclExpression_Attribute_parentNav->setUnique(true);
	m_oclExpression_Attribute_parentNav->setDerived(false);
	m_oclExpression_Attribute_parentNav->setOrdered(true);
	m_oclExpression_Attribute_parentNav->setContainment(false);
	m_oclExpression_Attribute_parentNav->setResolveProxies(true);
	m_oclExpression_Attribute_parentNav->setDefaultValueLiteral("");	
	m_oclExpression_Attribute_parentNav->setEOpposite(ocl::Expressions::ExpressionsPackage::eInstance()->getNavigationCallExp_Attribute_qualifier());
	
	m_oclExpression_Attribute_parentNav->_setID(OCLEXPRESSION_ATTRIBUTE_PARENTNAV);
	m_oclExpression_Attribute_thenOwner->setName("thenOwner");
	m_oclExpression_Attribute_thenOwner->setEType(getIfExp_Class());
	m_oclExpression_Attribute_thenOwner->setLowerBound(0);
	m_oclExpression_Attribute_thenOwner->setUpperBound(1);
	m_oclExpression_Attribute_thenOwner->setTransient(false);
	m_oclExpression_Attribute_thenOwner->setVolatile(false);
	m_oclExpression_Attribute_thenOwner->setChangeable(true);
	m_oclExpression_Attribute_thenOwner->setUnsettable(false);
	m_oclExpression_Attribute_thenOwner->setUnique(true);
	m_oclExpression_Attribute_thenOwner->setDerived(false);
	m_oclExpression_Attribute_thenOwner->setOrdered(true);
	m_oclExpression_Attribute_thenOwner->setContainment(false);
	m_oclExpression_Attribute_thenOwner->setResolveProxies(true);
	m_oclExpression_Attribute_thenOwner->setDefaultValueLiteral("");	
	m_oclExpression_Attribute_thenOwner->setEOpposite(ocl::Expressions::ExpressionsPackage::eInstance()->getIfExp_Attribute_thenExpression());
	
	m_oclExpression_Attribute_thenOwner->_setID(OCLEXPRESSION_ATTRIBUTE_THENOWNER);
	m_oclExpression_Attribute_topExpression->setName("topExpression");
	m_oclExpression_Attribute_topExpression->setEType(getExpressionInOcl_Class());
	m_oclExpression_Attribute_topExpression->setLowerBound(0);
	m_oclExpression_Attribute_topExpression->setUpperBound(1);
	m_oclExpression_Attribute_topExpression->setTransient(false);
	m_oclExpression_Attribute_topExpression->setVolatile(false);
	m_oclExpression_Attribute_topExpression->setChangeable(true);
	m_oclExpression_Attribute_topExpression->setUnsettable(false);
	m_oclExpression_Attribute_topExpression->setUnique(true);
	m_oclExpression_Attribute_topExpression->setDerived(false);
	m_oclExpression_Attribute_topExpression->setOrdered(true);
	m_oclExpression_Attribute_topExpression->setContainment(false);
	m_oclExpression_Attribute_topExpression->setResolveProxies(true);
	m_oclExpression_Attribute_topExpression->setDefaultValueLiteral("");	
	m_oclExpression_Attribute_topExpression->setEOpposite(ocl::Expressions::ExpressionsPackage::eInstance()->getExpressionInOcl_Attribute_bodyExpression());
	
	m_oclExpression_Attribute_topExpression->_setID(OCLEXPRESSION_ATTRIBUTE_TOPEXPRESSION);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeOperationCallExpContent()
{
	m_operationCallExp_Class->setName("OperationCallExp");
	m_operationCallExp_Class->setAbstract(false);
	m_operationCallExp_Class->setInterface(false);
	
	m_operationCallExp_Class->_setID(OPERATIONCALLEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	m_operationCallExp_Attribute_isRArrow = getOperationCallExp_Attribute_isRArrow();
	m_operationCallExp_Attribute_isRArrow->setName("isRArrow");
	m_operationCallExp_Attribute_isRArrow->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_operationCallExp_Attribute_isRArrow->setLowerBound(0);
	m_operationCallExp_Attribute_isRArrow->setUpperBound(1);
	m_operationCallExp_Attribute_isRArrow->setTransient(false);
	m_operationCallExp_Attribute_isRArrow->setVolatile(false);
	m_operationCallExp_Attribute_isRArrow->setChangeable(true);
	m_operationCallExp_Attribute_isRArrow->setUnsettable(false);
	m_operationCallExp_Attribute_isRArrow->setUnique(true);
	m_operationCallExp_Attribute_isRArrow->setDerived(false);
	m_operationCallExp_Attribute_isRArrow->setOrdered(true);
	m_operationCallExp_Attribute_isRArrow->setID(false);
	m_operationCallExp_Attribute_isRArrow->setDefaultValueLiteral("false");
	
	m_operationCallExp_Attribute_isRArrow->_setID(OPERATIONCALLEXP_ATTRIBUTE_ISRARROW);
	m_operationCallExp_Attribute_referredOperation = getOperationCallExp_Attribute_referredOperation();
	m_operationCallExp_Attribute_referredOperation->setName("referredOperation");
	m_operationCallExp_Attribute_referredOperation->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_operationCallExp_Attribute_referredOperation->setLowerBound(0);
	m_operationCallExp_Attribute_referredOperation->setUpperBound(1);
	m_operationCallExp_Attribute_referredOperation->setTransient(false);
	m_operationCallExp_Attribute_referredOperation->setVolatile(false);
	m_operationCallExp_Attribute_referredOperation->setChangeable(true);
	m_operationCallExp_Attribute_referredOperation->setUnsettable(false);
	m_operationCallExp_Attribute_referredOperation->setUnique(true);
	m_operationCallExp_Attribute_referredOperation->setDerived(false);
	m_operationCallExp_Attribute_referredOperation->setOrdered(true);
	m_operationCallExp_Attribute_referredOperation->setID(false);
	m_operationCallExp_Attribute_referredOperation->setDefaultValueLiteral("");
	
	m_operationCallExp_Attribute_referredOperation->_setID(OPERATIONCALLEXP_ATTRIBUTE_REFERREDOPERATION);
	
	/*
	 * EReferences
	 */
	m_operationCallExp_Attribute_argument->setName("argument");
	m_operationCallExp_Attribute_argument->setEType(getOclExpression_Class());
	m_operationCallExp_Attribute_argument->setLowerBound(0);
	m_operationCallExp_Attribute_argument->setUpperBound(-1);
	m_operationCallExp_Attribute_argument->setTransient(false);
	m_operationCallExp_Attribute_argument->setVolatile(false);
	m_operationCallExp_Attribute_argument->setChangeable(true);
	m_operationCallExp_Attribute_argument->setUnsettable(false);
	m_operationCallExp_Attribute_argument->setUnique(true);
	m_operationCallExp_Attribute_argument->setDerived(false);
	m_operationCallExp_Attribute_argument->setOrdered(true);
	m_operationCallExp_Attribute_argument->setContainment(true);
	m_operationCallExp_Attribute_argument->setResolveProxies(true);
	m_operationCallExp_Attribute_argument->setDefaultValueLiteral("");	
	m_operationCallExp_Attribute_argument->setEOpposite(ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Attribute_parentCall());
	
	m_operationCallExp_Attribute_argument->_setID(OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeOperationContextDeclExpContent()
{
	m_operationContextDeclExp_Class->setName("OperationContextDeclExp");
	m_operationContextDeclExp_Class->setAbstract(false);
	m_operationContextDeclExp_Class->setInterface(false);
	
	m_operationContextDeclExp_Class->_setID(OPERATIONCONTEXTDECLEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_operationContextDeclExp_Attribute_operationContext->setName("operationContext");
	m_operationContextDeclExp_Attribute_operationContext->setEType(getOperationContextExp_Class());
	m_operationContextDeclExp_Attribute_operationContext->setLowerBound(0);
	m_operationContextDeclExp_Attribute_operationContext->setUpperBound(1);
	m_operationContextDeclExp_Attribute_operationContext->setTransient(false);
	m_operationContextDeclExp_Attribute_operationContext->setVolatile(false);
	m_operationContextDeclExp_Attribute_operationContext->setChangeable(true);
	m_operationContextDeclExp_Attribute_operationContext->setUnsettable(false);
	m_operationContextDeclExp_Attribute_operationContext->setUnique(true);
	m_operationContextDeclExp_Attribute_operationContext->setDerived(false);
	m_operationContextDeclExp_Attribute_operationContext->setOrdered(true);
	m_operationContextDeclExp_Attribute_operationContext->setContainment(false);
	m_operationContextDeclExp_Attribute_operationContext->setResolveProxies(true);
	m_operationContextDeclExp_Attribute_operationContext->setDefaultValueLiteral("");	
	
	m_operationContextDeclExp_Attribute_operationContext->_setID(OPERATIONCONTEXTDECLEXP_ATTRIBUTE_OPERATIONCONTEXT);
	m_operationContextDeclExp_Attribute_prePostBodyExpressions->setName("prePostBodyExpressions");
	m_operationContextDeclExp_Attribute_prePostBodyExpressions->setEType(getPrePostBodyListExp_Class());
	m_operationContextDeclExp_Attribute_prePostBodyExpressions->setLowerBound(0);
	m_operationContextDeclExp_Attribute_prePostBodyExpressions->setUpperBound(1);
	m_operationContextDeclExp_Attribute_prePostBodyExpressions->setTransient(false);
	m_operationContextDeclExp_Attribute_prePostBodyExpressions->setVolatile(false);
	m_operationContextDeclExp_Attribute_prePostBodyExpressions->setChangeable(true);
	m_operationContextDeclExp_Attribute_prePostBodyExpressions->setUnsettable(false);
	m_operationContextDeclExp_Attribute_prePostBodyExpressions->setUnique(true);
	m_operationContextDeclExp_Attribute_prePostBodyExpressions->setDerived(false);
	m_operationContextDeclExp_Attribute_prePostBodyExpressions->setOrdered(true);
	m_operationContextDeclExp_Attribute_prePostBodyExpressions->setContainment(false);
	m_operationContextDeclExp_Attribute_prePostBodyExpressions->setResolveProxies(true);
	m_operationContextDeclExp_Attribute_prePostBodyExpressions->setDefaultValueLiteral("");	
	
	m_operationContextDeclExp_Attribute_prePostBodyExpressions->_setID(OPERATIONCONTEXTDECLEXP_ATTRIBUTE_PREPOSTBODYEXPRESSIONS);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeOperationContextExpContent()
{
	m_operationContextExp_Class->setName("OperationContextExp");
	m_operationContextExp_Class->setAbstract(false);
	m_operationContextExp_Class->setInterface(false);
	
	m_operationContextExp_Class->_setID(OPERATIONCONTEXTEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	m_operationContextExp_Attribute_operationName = getOperationContextExp_Attribute_operationName();
	m_operationContextExp_Attribute_operationName->setName("operationName");
	m_operationContextExp_Attribute_operationName->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_operationContextExp_Attribute_operationName->setLowerBound(0);
	m_operationContextExp_Attribute_operationName->setUpperBound(1);
	m_operationContextExp_Attribute_operationName->setTransient(false);
	m_operationContextExp_Attribute_operationName->setVolatile(false);
	m_operationContextExp_Attribute_operationName->setChangeable(true);
	m_operationContextExp_Attribute_operationName->setUnsettable(false);
	m_operationContextExp_Attribute_operationName->setUnique(true);
	m_operationContextExp_Attribute_operationName->setDerived(false);
	m_operationContextExp_Attribute_operationName->setOrdered(true);
	m_operationContextExp_Attribute_operationName->setID(false);
	m_operationContextExp_Attribute_operationName->setDefaultValueLiteral("");
	
	m_operationContextExp_Attribute_operationName->_setID(OPERATIONCONTEXTEXP_ATTRIBUTE_OPERATIONNAME);
	
	/*
	 * EReferences
	 */
	m_operationContextExp_Attribute_inputParameters->setName("inputParameters");
	m_operationContextExp_Attribute_inputParameters->setEType(getVarDeclarationExp_Class());
	m_operationContextExp_Attribute_inputParameters->setLowerBound(0);
	m_operationContextExp_Attribute_inputParameters->setUpperBound(-1);
	m_operationContextExp_Attribute_inputParameters->setTransient(false);
	m_operationContextExp_Attribute_inputParameters->setVolatile(false);
	m_operationContextExp_Attribute_inputParameters->setChangeable(true);
	m_operationContextExp_Attribute_inputParameters->setUnsettable(false);
	m_operationContextExp_Attribute_inputParameters->setUnique(true);
	m_operationContextExp_Attribute_inputParameters->setDerived(false);
	m_operationContextExp_Attribute_inputParameters->setOrdered(true);
	m_operationContextExp_Attribute_inputParameters->setContainment(false);
	m_operationContextExp_Attribute_inputParameters->setResolveProxies(true);
	m_operationContextExp_Attribute_inputParameters->setDefaultValueLiteral("");	
	
	m_operationContextExp_Attribute_inputParameters->_setID(OPERATIONCONTEXTEXP_ATTRIBUTE_INPUTPARAMETERS);
	m_operationContextExp_Attribute_returnType->setName("returnType");
	m_operationContextExp_Attribute_returnType->setEType(getTypeExp_Class());
	m_operationContextExp_Attribute_returnType->setLowerBound(0);
	m_operationContextExp_Attribute_returnType->setUpperBound(1);
	m_operationContextExp_Attribute_returnType->setTransient(false);
	m_operationContextExp_Attribute_returnType->setVolatile(false);
	m_operationContextExp_Attribute_returnType->setChangeable(true);
	m_operationContextExp_Attribute_returnType->setUnsettable(false);
	m_operationContextExp_Attribute_returnType->setUnique(true);
	m_operationContextExp_Attribute_returnType->setDerived(false);
	m_operationContextExp_Attribute_returnType->setOrdered(true);
	m_operationContextExp_Attribute_returnType->setContainment(false);
	m_operationContextExp_Attribute_returnType->setResolveProxies(true);
	m_operationContextExp_Attribute_returnType->setDefaultValueLiteral("");	
	
	m_operationContextExp_Attribute_returnType->_setID(OPERATIONCONTEXTEXP_ATTRIBUTE_RETURNTYPE);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeOperatorExpContent()
{
	m_operatorExp_Class->setName("OperatorExp");
	m_operatorExp_Class->setAbstract(false);
	m_operatorExp_Class->setInterface(false);
	
	m_operatorExp_Class->_setID(OPERATOREXP_CLASS);
	
	/*
	 * EAttributes
	 */
	m_operatorExp_Attribute_operator = getOperatorExp_Attribute_operator();
	m_operatorExp_Attribute_operator->setName("operator");
	m_operatorExp_Attribute_operator->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_operatorExp_Attribute_operator->setLowerBound(0);
	m_operatorExp_Attribute_operator->setUpperBound(1);
	m_operatorExp_Attribute_operator->setTransient(false);
	m_operatorExp_Attribute_operator->setVolatile(false);
	m_operatorExp_Attribute_operator->setChangeable(true);
	m_operatorExp_Attribute_operator->setUnsettable(false);
	m_operatorExp_Attribute_operator->setUnique(true);
	m_operatorExp_Attribute_operator->setDerived(false);
	m_operatorExp_Attribute_operator->setOrdered(true);
	m_operatorExp_Attribute_operator->setID(false);
	m_operatorExp_Attribute_operator->setDefaultValueLiteral("");
	
	m_operatorExp_Attribute_operator->_setID(OPERATOREXP_ATTRIBUTE_OPERATOR);
	
	/*
	 * EReferences
	 */
	m_operatorExp_Attribute_leftHandOperand->setName("leftHandOperand");
	m_operatorExp_Attribute_leftHandOperand->setEType(getOclExpression_Class());
	m_operatorExp_Attribute_leftHandOperand->setLowerBound(0);
	m_operatorExp_Attribute_leftHandOperand->setUpperBound(1);
	m_operatorExp_Attribute_leftHandOperand->setTransient(false);
	m_operatorExp_Attribute_leftHandOperand->setVolatile(false);
	m_operatorExp_Attribute_leftHandOperand->setChangeable(true);
	m_operatorExp_Attribute_leftHandOperand->setUnsettable(false);
	m_operatorExp_Attribute_leftHandOperand->setUnique(true);
	m_operatorExp_Attribute_leftHandOperand->setDerived(false);
	m_operatorExp_Attribute_leftHandOperand->setOrdered(true);
	m_operatorExp_Attribute_leftHandOperand->setContainment(false);
	m_operatorExp_Attribute_leftHandOperand->setResolveProxies(true);
	m_operatorExp_Attribute_leftHandOperand->setDefaultValueLiteral("");	
	
	m_operatorExp_Attribute_leftHandOperand->_setID(OPERATOREXP_ATTRIBUTE_LEFTHANDOPERAND);
	m_operatorExp_Attribute_rightHandOperand->setName("rightHandOperand");
	m_operatorExp_Attribute_rightHandOperand->setEType(getOclExpression_Class());
	m_operatorExp_Attribute_rightHandOperand->setLowerBound(0);
	m_operatorExp_Attribute_rightHandOperand->setUpperBound(1);
	m_operatorExp_Attribute_rightHandOperand->setTransient(false);
	m_operatorExp_Attribute_rightHandOperand->setVolatile(false);
	m_operatorExp_Attribute_rightHandOperand->setChangeable(true);
	m_operatorExp_Attribute_rightHandOperand->setUnsettable(false);
	m_operatorExp_Attribute_rightHandOperand->setUnique(true);
	m_operatorExp_Attribute_rightHandOperand->setDerived(false);
	m_operatorExp_Attribute_rightHandOperand->setOrdered(true);
	m_operatorExp_Attribute_rightHandOperand->setContainment(false);
	m_operatorExp_Attribute_rightHandOperand->setResolveProxies(true);
	m_operatorExp_Attribute_rightHandOperand->setDefaultValueLiteral("");	
	
	m_operatorExp_Attribute_rightHandOperand->_setID(OPERATOREXP_ATTRIBUTE_RIGHTHANDOPERAND);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializePackageDeclarationExpContent()
{
	m_packageDeclarationExp_Class->setName("PackageDeclarationExp");
	m_packageDeclarationExp_Class->setAbstract(false);
	m_packageDeclarationExp_Class->setInterface(false);
	
	m_packageDeclarationExp_Class->_setID(PACKAGEDECLARATIONEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	m_packageDeclarationExp_Attribute_path = getPackageDeclarationExp_Attribute_path();
	m_packageDeclarationExp_Attribute_path->setName("path");
	m_packageDeclarationExp_Attribute_path->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_packageDeclarationExp_Attribute_path->setLowerBound(0);
	m_packageDeclarationExp_Attribute_path->setUpperBound(1);
	m_packageDeclarationExp_Attribute_path->setTransient(false);
	m_packageDeclarationExp_Attribute_path->setVolatile(false);
	m_packageDeclarationExp_Attribute_path->setChangeable(true);
	m_packageDeclarationExp_Attribute_path->setUnsettable(false);
	m_packageDeclarationExp_Attribute_path->setUnique(true);
	m_packageDeclarationExp_Attribute_path->setDerived(false);
	m_packageDeclarationExp_Attribute_path->setOrdered(true);
	m_packageDeclarationExp_Attribute_path->setID(false);
	m_packageDeclarationExp_Attribute_path->setDefaultValueLiteral("");
	
	m_packageDeclarationExp_Attribute_path->_setID(PACKAGEDECLARATIONEXP_ATTRIBUTE_PATH);
	
	/*
	 * EReferences
	 */
	m_packageDeclarationExp_Attribute_contextDeclarations->setName("contextDeclarations");
	m_packageDeclarationExp_Attribute_contextDeclarations->setEType(getContextDeclarationExp_Class());
	m_packageDeclarationExp_Attribute_contextDeclarations->setLowerBound(0);
	m_packageDeclarationExp_Attribute_contextDeclarations->setUpperBound(-1);
	m_packageDeclarationExp_Attribute_contextDeclarations->setTransient(false);
	m_packageDeclarationExp_Attribute_contextDeclarations->setVolatile(false);
	m_packageDeclarationExp_Attribute_contextDeclarations->setChangeable(true);
	m_packageDeclarationExp_Attribute_contextDeclarations->setUnsettable(false);
	m_packageDeclarationExp_Attribute_contextDeclarations->setUnique(true);
	m_packageDeclarationExp_Attribute_contextDeclarations->setDerived(false);
	m_packageDeclarationExp_Attribute_contextDeclarations->setOrdered(true);
	m_packageDeclarationExp_Attribute_contextDeclarations->setContainment(false);
	m_packageDeclarationExp_Attribute_contextDeclarations->setResolveProxies(true);
	m_packageDeclarationExp_Attribute_contextDeclarations->setDefaultValueLiteral("");	
	
	m_packageDeclarationExp_Attribute_contextDeclarations->_setID(PACKAGEDECLARATIONEXP_ATTRIBUTE_CONTEXTDECLARATIONS);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeParentedExpContent()
{
	m_parentedExp_Class->setName("ParentedExp");
	m_parentedExp_Class->setAbstract(false);
	m_parentedExp_Class->setInterface(false);
	
	m_parentedExp_Class->_setID(PARENTEDEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_parentedExp_Attribute_innerExp->setName("innerExp");
	m_parentedExp_Attribute_innerExp->setEType(getOclExpression_Class());
	m_parentedExp_Attribute_innerExp->setLowerBound(0);
	m_parentedExp_Attribute_innerExp->setUpperBound(1);
	m_parentedExp_Attribute_innerExp->setTransient(false);
	m_parentedExp_Attribute_innerExp->setVolatile(false);
	m_parentedExp_Attribute_innerExp->setChangeable(true);
	m_parentedExp_Attribute_innerExp->setUnsettable(false);
	m_parentedExp_Attribute_innerExp->setUnique(true);
	m_parentedExp_Attribute_innerExp->setDerived(false);
	m_parentedExp_Attribute_innerExp->setOrdered(true);
	m_parentedExp_Attribute_innerExp->setContainment(false);
	m_parentedExp_Attribute_innerExp->setResolveProxies(true);
	m_parentedExp_Attribute_innerExp->setDefaultValueLiteral("");	
	
	m_parentedExp_Attribute_innerExp->_setID(PARENTEDEXP_ATTRIBUTE_INNEREXP);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializePrePostBodyExpContent()
{
	m_prePostBodyExp_Class->setName("PrePostBodyExp");
	m_prePostBodyExp_Class->setAbstract(false);
	m_prePostBodyExp_Class->setInterface(false);
	
	m_prePostBodyExp_Class->_setID(PREPOSTBODYEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	m_prePostBodyExp_Attribute_kind = getPrePostBodyExp_Attribute_kind();
	m_prePostBodyExp_Attribute_kind->setName("kind");
	m_prePostBodyExp_Attribute_kind->setEType(getPrePostBody_Class());
	m_prePostBodyExp_Attribute_kind->setLowerBound(0);
	m_prePostBodyExp_Attribute_kind->setUpperBound(1);
	m_prePostBodyExp_Attribute_kind->setTransient(false);
	m_prePostBodyExp_Attribute_kind->setVolatile(false);
	m_prePostBodyExp_Attribute_kind->setChangeable(true);
	m_prePostBodyExp_Attribute_kind->setUnsettable(false);
	m_prePostBodyExp_Attribute_kind->setUnique(true);
	m_prePostBodyExp_Attribute_kind->setDerived(false);
	m_prePostBodyExp_Attribute_kind->setOrdered(true);
	m_prePostBodyExp_Attribute_kind->setID(false);
	m_prePostBodyExp_Attribute_kind->setDefaultValueLiteral("");
	
	m_prePostBodyExp_Attribute_kind->_setID(PREPOSTBODYEXP_ATTRIBUTE_KIND);
	m_prePostBodyExp_Attribute_name = getPrePostBodyExp_Attribute_name();
	m_prePostBodyExp_Attribute_name->setName("name");
	m_prePostBodyExp_Attribute_name->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_prePostBodyExp_Attribute_name->setLowerBound(0);
	m_prePostBodyExp_Attribute_name->setUpperBound(1);
	m_prePostBodyExp_Attribute_name->setTransient(false);
	m_prePostBodyExp_Attribute_name->setVolatile(false);
	m_prePostBodyExp_Attribute_name->setChangeable(true);
	m_prePostBodyExp_Attribute_name->setUnsettable(false);
	m_prePostBodyExp_Attribute_name->setUnique(true);
	m_prePostBodyExp_Attribute_name->setDerived(false);
	m_prePostBodyExp_Attribute_name->setOrdered(true);
	m_prePostBodyExp_Attribute_name->setID(false);
	m_prePostBodyExp_Attribute_name->setDefaultValueLiteral("");
	
	m_prePostBodyExp_Attribute_name->_setID(PREPOSTBODYEXP_ATTRIBUTE_NAME);
	
	/*
	 * EReferences
	 */
	m_prePostBodyExp_Attribute_bodyExpression->setName("bodyExpression");
	m_prePostBodyExp_Attribute_bodyExpression->setEType(getOclExpression_Class());
	m_prePostBodyExp_Attribute_bodyExpression->setLowerBound(0);
	m_prePostBodyExp_Attribute_bodyExpression->setUpperBound(1);
	m_prePostBodyExp_Attribute_bodyExpression->setTransient(false);
	m_prePostBodyExp_Attribute_bodyExpression->setVolatile(false);
	m_prePostBodyExp_Attribute_bodyExpression->setChangeable(true);
	m_prePostBodyExp_Attribute_bodyExpression->setUnsettable(false);
	m_prePostBodyExp_Attribute_bodyExpression->setUnique(true);
	m_prePostBodyExp_Attribute_bodyExpression->setDerived(false);
	m_prePostBodyExp_Attribute_bodyExpression->setOrdered(true);
	m_prePostBodyExp_Attribute_bodyExpression->setContainment(false);
	m_prePostBodyExp_Attribute_bodyExpression->setResolveProxies(true);
	m_prePostBodyExp_Attribute_bodyExpression->setDefaultValueLiteral("");	
	
	m_prePostBodyExp_Attribute_bodyExpression->_setID(PREPOSTBODYEXP_ATTRIBUTE_BODYEXPRESSION);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializePrePostBodyListExpContent()
{
	m_prePostBodyListExp_Class->setName("PrePostBodyListExp");
	m_prePostBodyListExp_Class->setAbstract(false);
	m_prePostBodyListExp_Class->setInterface(false);
	
	m_prePostBodyListExp_Class->_setID(PREPOSTBODYLISTEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_prePostBodyListExp_Attribute_bodyExpressionList->setName("bodyExpressionList");
	m_prePostBodyListExp_Attribute_bodyExpressionList->setEType(getPrePostBodyExp_Class());
	m_prePostBodyListExp_Attribute_bodyExpressionList->setLowerBound(0);
	m_prePostBodyListExp_Attribute_bodyExpressionList->setUpperBound(-1);
	m_prePostBodyListExp_Attribute_bodyExpressionList->setTransient(false);
	m_prePostBodyListExp_Attribute_bodyExpressionList->setVolatile(false);
	m_prePostBodyListExp_Attribute_bodyExpressionList->setChangeable(true);
	m_prePostBodyListExp_Attribute_bodyExpressionList->setUnsettable(false);
	m_prePostBodyListExp_Attribute_bodyExpressionList->setUnique(true);
	m_prePostBodyListExp_Attribute_bodyExpressionList->setDerived(false);
	m_prePostBodyListExp_Attribute_bodyExpressionList->setOrdered(true);
	m_prePostBodyListExp_Attribute_bodyExpressionList->setContainment(false);
	m_prePostBodyListExp_Attribute_bodyExpressionList->setResolveProxies(true);
	m_prePostBodyListExp_Attribute_bodyExpressionList->setDefaultValueLiteral("");	
	
	m_prePostBodyListExp_Attribute_bodyExpressionList->_setID(PREPOSTBODYLISTEXP_ATTRIBUTE_BODYEXPRESSIONLIST);
	m_prePostBodyListExp_Attribute_postExpressionList->setName("postExpressionList");
	m_prePostBodyListExp_Attribute_postExpressionList->setEType(getPrePostBodyExp_Class());
	m_prePostBodyListExp_Attribute_postExpressionList->setLowerBound(0);
	m_prePostBodyListExp_Attribute_postExpressionList->setUpperBound(-1);
	m_prePostBodyListExp_Attribute_postExpressionList->setTransient(false);
	m_prePostBodyListExp_Attribute_postExpressionList->setVolatile(false);
	m_prePostBodyListExp_Attribute_postExpressionList->setChangeable(true);
	m_prePostBodyListExp_Attribute_postExpressionList->setUnsettable(false);
	m_prePostBodyListExp_Attribute_postExpressionList->setUnique(true);
	m_prePostBodyListExp_Attribute_postExpressionList->setDerived(false);
	m_prePostBodyListExp_Attribute_postExpressionList->setOrdered(true);
	m_prePostBodyListExp_Attribute_postExpressionList->setContainment(false);
	m_prePostBodyListExp_Attribute_postExpressionList->setResolveProxies(true);
	m_prePostBodyListExp_Attribute_postExpressionList->setDefaultValueLiteral("");	
	
	m_prePostBodyListExp_Attribute_postExpressionList->_setID(PREPOSTBODYLISTEXP_ATTRIBUTE_POSTEXPRESSIONLIST);
	m_prePostBodyListExp_Attribute_preExpressionList->setName("preExpressionList");
	m_prePostBodyListExp_Attribute_preExpressionList->setEType(getPrePostBodyExp_Class());
	m_prePostBodyListExp_Attribute_preExpressionList->setLowerBound(0);
	m_prePostBodyListExp_Attribute_preExpressionList->setUpperBound(-1);
	m_prePostBodyListExp_Attribute_preExpressionList->setTransient(false);
	m_prePostBodyListExp_Attribute_preExpressionList->setVolatile(false);
	m_prePostBodyListExp_Attribute_preExpressionList->setChangeable(true);
	m_prePostBodyListExp_Attribute_preExpressionList->setUnsettable(false);
	m_prePostBodyListExp_Attribute_preExpressionList->setUnique(true);
	m_prePostBodyListExp_Attribute_preExpressionList->setDerived(false);
	m_prePostBodyListExp_Attribute_preExpressionList->setOrdered(true);
	m_prePostBodyListExp_Attribute_preExpressionList->setContainment(false);
	m_prePostBodyListExp_Attribute_preExpressionList->setResolveProxies(true);
	m_prePostBodyListExp_Attribute_preExpressionList->setDefaultValueLiteral("");	
	
	m_prePostBodyListExp_Attribute_preExpressionList->_setID(PREPOSTBODYLISTEXP_ATTRIBUTE_PREEXPRESSIONLIST);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializePrefixedExpContent()
{
	m_prefixedExp_Class->setName("PrefixedExp");
	m_prefixedExp_Class->setAbstract(false);
	m_prefixedExp_Class->setInterface(false);
	
	m_prefixedExp_Class->_setID(PREFIXEDEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	m_prefixedExp_Attribute_unarySymbol = getPrefixedExp_Attribute_unarySymbol();
	m_prefixedExp_Attribute_unarySymbol->setName("unarySymbol");
	m_prefixedExp_Attribute_unarySymbol->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_prefixedExp_Attribute_unarySymbol->setLowerBound(0);
	m_prefixedExp_Attribute_unarySymbol->setUpperBound(1);
	m_prefixedExp_Attribute_unarySymbol->setTransient(false);
	m_prefixedExp_Attribute_unarySymbol->setVolatile(false);
	m_prefixedExp_Attribute_unarySymbol->setChangeable(true);
	m_prefixedExp_Attribute_unarySymbol->setUnsettable(false);
	m_prefixedExp_Attribute_unarySymbol->setUnique(true);
	m_prefixedExp_Attribute_unarySymbol->setDerived(false);
	m_prefixedExp_Attribute_unarySymbol->setOrdered(true);
	m_prefixedExp_Attribute_unarySymbol->setID(false);
	m_prefixedExp_Attribute_unarySymbol->setDefaultValueLiteral("");
	
	m_prefixedExp_Attribute_unarySymbol->_setID(PREFIXEDEXP_ATTRIBUTE_UNARYSYMBOL);
	
	/*
	 * EReferences
	 */
	m_prefixedExp_Attribute_referredExpression->setName("referredExpression");
	m_prefixedExp_Attribute_referredExpression->setEType(getOclExpression_Class());
	m_prefixedExp_Attribute_referredExpression->setLowerBound(0);
	m_prefixedExp_Attribute_referredExpression->setUpperBound(1);
	m_prefixedExp_Attribute_referredExpression->setTransient(false);
	m_prefixedExp_Attribute_referredExpression->setVolatile(false);
	m_prefixedExp_Attribute_referredExpression->setChangeable(true);
	m_prefixedExp_Attribute_referredExpression->setUnsettable(false);
	m_prefixedExp_Attribute_referredExpression->setUnique(true);
	m_prefixedExp_Attribute_referredExpression->setDerived(false);
	m_prefixedExp_Attribute_referredExpression->setOrdered(true);
	m_prefixedExp_Attribute_referredExpression->setContainment(false);
	m_prefixedExp_Attribute_referredExpression->setResolveProxies(true);
	m_prefixedExp_Attribute_referredExpression->setDefaultValueLiteral("");	
	
	m_prefixedExp_Attribute_referredExpression->_setID(PREFIXEDEXP_ATTRIBUTE_REFERREDEXPRESSION);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializePrimitiveLiteralExpContent()
{
	m_primitiveLiteralExp_Class->setName("PrimitiveLiteralExp");
	m_primitiveLiteralExp_Class->setAbstract(true);
	m_primitiveLiteralExp_Class->setInterface(false);
	
	m_primitiveLiteralExp_Class->_setID(PRIMITIVELITERALEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	m_primitiveLiteralExp_Attribute_symbol = getPrimitiveLiteralExp_Attribute_symbol();
	m_primitiveLiteralExp_Attribute_symbol->setName("symbol");
	m_primitiveLiteralExp_Attribute_symbol->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_primitiveLiteralExp_Attribute_symbol->setLowerBound(0);
	m_primitiveLiteralExp_Attribute_symbol->setUpperBound(1);
	m_primitiveLiteralExp_Attribute_symbol->setTransient(false);
	m_primitiveLiteralExp_Attribute_symbol->setVolatile(false);
	m_primitiveLiteralExp_Attribute_symbol->setChangeable(true);
	m_primitiveLiteralExp_Attribute_symbol->setUnsettable(false);
	m_primitiveLiteralExp_Attribute_symbol->setUnique(true);
	m_primitiveLiteralExp_Attribute_symbol->setDerived(false);
	m_primitiveLiteralExp_Attribute_symbol->setOrdered(true);
	m_primitiveLiteralExp_Attribute_symbol->setID(false);
	m_primitiveLiteralExp_Attribute_symbol->setDefaultValueLiteral("");
	
	m_primitiveLiteralExp_Attribute_symbol->_setID(PRIMITIVELITERALEXP_ATTRIBUTE_SYMBOL);
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializePropertyCallExpContent()
{
	m_propertyCallExp_Class->setName("PropertyCallExp");
	m_propertyCallExp_Class->setAbstract(false);
	m_propertyCallExp_Class->setInterface(false);
	
	m_propertyCallExp_Class->_setID(PROPERTYCALLEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	m_propertyCallExp_Attribute_referredProperty = getPropertyCallExp_Attribute_referredProperty();
	m_propertyCallExp_Attribute_referredProperty->setName("referredProperty");
	m_propertyCallExp_Attribute_referredProperty->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_propertyCallExp_Attribute_referredProperty->setLowerBound(0);
	m_propertyCallExp_Attribute_referredProperty->setUpperBound(1);
	m_propertyCallExp_Attribute_referredProperty->setTransient(false);
	m_propertyCallExp_Attribute_referredProperty->setVolatile(false);
	m_propertyCallExp_Attribute_referredProperty->setChangeable(true);
	m_propertyCallExp_Attribute_referredProperty->setUnsettable(false);
	m_propertyCallExp_Attribute_referredProperty->setUnique(true);
	m_propertyCallExp_Attribute_referredProperty->setDerived(false);
	m_propertyCallExp_Attribute_referredProperty->setOrdered(true);
	m_propertyCallExp_Attribute_referredProperty->setID(false);
	m_propertyCallExp_Attribute_referredProperty->setDefaultValueLiteral("");
	
	m_propertyCallExp_Attribute_referredProperty->_setID(PROPERTYCALLEXP_ATTRIBUTE_REFERREDPROPERTY);
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializePropertyContextDeclExpContent()
{
	m_propertyContextDeclExp_Class->setName("PropertyContextDeclExp");
	m_propertyContextDeclExp_Class->setAbstract(false);
	m_propertyContextDeclExp_Class->setInterface(false);
	
	m_propertyContextDeclExp_Class->_setID(PROPERTYCONTEXTDECLEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	m_propertyContextDeclExp_Attribute_propName = getPropertyContextDeclExp_Attribute_propName();
	m_propertyContextDeclExp_Attribute_propName->setName("propName");
	m_propertyContextDeclExp_Attribute_propName->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_propertyContextDeclExp_Attribute_propName->setLowerBound(0);
	m_propertyContextDeclExp_Attribute_propName->setUpperBound(1);
	m_propertyContextDeclExp_Attribute_propName->setTransient(false);
	m_propertyContextDeclExp_Attribute_propName->setVolatile(false);
	m_propertyContextDeclExp_Attribute_propName->setChangeable(true);
	m_propertyContextDeclExp_Attribute_propName->setUnsettable(false);
	m_propertyContextDeclExp_Attribute_propName->setUnique(true);
	m_propertyContextDeclExp_Attribute_propName->setDerived(false);
	m_propertyContextDeclExp_Attribute_propName->setOrdered(true);
	m_propertyContextDeclExp_Attribute_propName->setID(false);
	m_propertyContextDeclExp_Attribute_propName->setDefaultValueLiteral("");
	
	m_propertyContextDeclExp_Attribute_propName->_setID(PROPERTYCONTEXTDECLEXP_ATTRIBUTE_PROPNAME);
	
	/*
	 * EReferences
	 */
	m_propertyContextDeclExp_Attribute_initOrDerValues->setName("initOrDerValues");
	m_propertyContextDeclExp_Attribute_initOrDerValues->setEType(getInitOrDerValueListExp_Class());
	m_propertyContextDeclExp_Attribute_initOrDerValues->setLowerBound(0);
	m_propertyContextDeclExp_Attribute_initOrDerValues->setUpperBound(1);
	m_propertyContextDeclExp_Attribute_initOrDerValues->setTransient(false);
	m_propertyContextDeclExp_Attribute_initOrDerValues->setVolatile(false);
	m_propertyContextDeclExp_Attribute_initOrDerValues->setChangeable(true);
	m_propertyContextDeclExp_Attribute_initOrDerValues->setUnsettable(false);
	m_propertyContextDeclExp_Attribute_initOrDerValues->setUnique(true);
	m_propertyContextDeclExp_Attribute_initOrDerValues->setDerived(false);
	m_propertyContextDeclExp_Attribute_initOrDerValues->setOrdered(true);
	m_propertyContextDeclExp_Attribute_initOrDerValues->setContainment(false);
	m_propertyContextDeclExp_Attribute_initOrDerValues->setResolveProxies(true);
	m_propertyContextDeclExp_Attribute_initOrDerValues->setDefaultValueLiteral("");	
	
	m_propertyContextDeclExp_Attribute_initOrDerValues->_setID(PROPERTYCONTEXTDECLEXP_ATTRIBUTE_INITORDERVALUES);
	m_propertyContextDeclExp_Attribute_propType->setName("propType");
	m_propertyContextDeclExp_Attribute_propType->setEType(getTypeExp_Class());
	m_propertyContextDeclExp_Attribute_propType->setLowerBound(0);
	m_propertyContextDeclExp_Attribute_propType->setUpperBound(1);
	m_propertyContextDeclExp_Attribute_propType->setTransient(false);
	m_propertyContextDeclExp_Attribute_propType->setVolatile(false);
	m_propertyContextDeclExp_Attribute_propType->setChangeable(true);
	m_propertyContextDeclExp_Attribute_propType->setUnsettable(false);
	m_propertyContextDeclExp_Attribute_propType->setUnique(true);
	m_propertyContextDeclExp_Attribute_propType->setDerived(false);
	m_propertyContextDeclExp_Attribute_propType->setOrdered(true);
	m_propertyContextDeclExp_Attribute_propType->setContainment(false);
	m_propertyContextDeclExp_Attribute_propType->setResolveProxies(true);
	m_propertyContextDeclExp_Attribute_propType->setDefaultValueLiteral("");	
	
	m_propertyContextDeclExp_Attribute_propType->_setID(PROPERTYCONTEXTDECLEXP_ATTRIBUTE_PROPTYPE);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeRealLiteralExpContent()
{
	m_realLiteralExp_Class->setName("RealLiteralExp");
	m_realLiteralExp_Class->setAbstract(false);
	m_realLiteralExp_Class->setInterface(false);
	
	m_realLiteralExp_Class->_setID(REALLITERALEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	m_realLiteralExp_Attribute_realSymbol = getRealLiteralExp_Attribute_realSymbol();
	m_realLiteralExp_Attribute_realSymbol->setName("realSymbol");
	m_realLiteralExp_Attribute_realSymbol->setEType(ecore::ecorePackage::eInstance()->getEDouble_Class());
	m_realLiteralExp_Attribute_realSymbol->setLowerBound(0);
	m_realLiteralExp_Attribute_realSymbol->setUpperBound(1);
	m_realLiteralExp_Attribute_realSymbol->setTransient(false);
	m_realLiteralExp_Attribute_realSymbol->setVolatile(false);
	m_realLiteralExp_Attribute_realSymbol->setChangeable(true);
	m_realLiteralExp_Attribute_realSymbol->setUnsettable(false);
	m_realLiteralExp_Attribute_realSymbol->setUnique(true);
	m_realLiteralExp_Attribute_realSymbol->setDerived(false);
	m_realLiteralExp_Attribute_realSymbol->setOrdered(true);
	m_realLiteralExp_Attribute_realSymbol->setID(false);
	m_realLiteralExp_Attribute_realSymbol->setDefaultValueLiteral("");
	
	m_realLiteralExp_Attribute_realSymbol->_setID(REALLITERALEXP_ATTRIBUTE_REALSYMBOL);
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeStateExpContent()
{
	m_stateExp_Class->setName("StateExp");
	m_stateExp_Class->setAbstract(false);
	m_stateExp_Class->setInterface(false);
	
	m_stateExp_Class->_setID(STATEEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_stateExp_Attribute_referredState->setName("referredState");
	m_stateExp_Attribute_referredState->setEType(ecore::ecorePackage::eInstance()->getEObject_Class());
	m_stateExp_Attribute_referredState->setLowerBound(0);
	m_stateExp_Attribute_referredState->setUpperBound(1);
	m_stateExp_Attribute_referredState->setTransient(false);
	m_stateExp_Attribute_referredState->setVolatile(false);
	m_stateExp_Attribute_referredState->setChangeable(true);
	m_stateExp_Attribute_referredState->setUnsettable(false);
	m_stateExp_Attribute_referredState->setUnique(true);
	m_stateExp_Attribute_referredState->setDerived(false);
	m_stateExp_Attribute_referredState->setOrdered(true);
	m_stateExp_Attribute_referredState->setContainment(false);
	m_stateExp_Attribute_referredState->setResolveProxies(true);
	m_stateExp_Attribute_referredState->setDefaultValueLiteral("");	
	
	m_stateExp_Attribute_referredState->_setID(STATEEXP_ATTRIBUTE_REFERREDSTATE);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeStringLiteralExpContent()
{
	m_stringLiteralExp_Class->setName("StringLiteralExp");
	m_stringLiteralExp_Class->setAbstract(false);
	m_stringLiteralExp_Class->setInterface(false);
	
	m_stringLiteralExp_Class->_setID(STRINGLITERALEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	m_stringLiteralExp_Attribute_stringSymbol = getStringLiteralExp_Attribute_stringSymbol();
	m_stringLiteralExp_Attribute_stringSymbol->setName("stringSymbol");
	m_stringLiteralExp_Attribute_stringSymbol->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_stringLiteralExp_Attribute_stringSymbol->setLowerBound(0);
	m_stringLiteralExp_Attribute_stringSymbol->setUpperBound(1);
	m_stringLiteralExp_Attribute_stringSymbol->setTransient(false);
	m_stringLiteralExp_Attribute_stringSymbol->setVolatile(false);
	m_stringLiteralExp_Attribute_stringSymbol->setChangeable(true);
	m_stringLiteralExp_Attribute_stringSymbol->setUnsettable(false);
	m_stringLiteralExp_Attribute_stringSymbol->setUnique(true);
	m_stringLiteralExp_Attribute_stringSymbol->setDerived(false);
	m_stringLiteralExp_Attribute_stringSymbol->setOrdered(true);
	m_stringLiteralExp_Attribute_stringSymbol->setID(false);
	m_stringLiteralExp_Attribute_stringSymbol->setDefaultValueLiteral("");
	
	m_stringLiteralExp_Attribute_stringSymbol->_setID(STRINGLITERALEXP_ATTRIBUTE_STRINGSYMBOL);
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeTupleLiteralExpContent()
{
	m_tupleLiteralExp_Class->setName("TupleLiteralExp");
	m_tupleLiteralExp_Class->setAbstract(false);
	m_tupleLiteralExp_Class->setInterface(false);
	
	m_tupleLiteralExp_Class->_setID(TUPLELITERALEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_tupleLiteralExp_Attribute_part->setName("part");
	m_tupleLiteralExp_Attribute_part->setEType(getVarDeclarationExp_Class());
	m_tupleLiteralExp_Attribute_part->setLowerBound(0);
	m_tupleLiteralExp_Attribute_part->setUpperBound(-1);
	m_tupleLiteralExp_Attribute_part->setTransient(false);
	m_tupleLiteralExp_Attribute_part->setVolatile(false);
	m_tupleLiteralExp_Attribute_part->setChangeable(true);
	m_tupleLiteralExp_Attribute_part->setUnsettable(false);
	m_tupleLiteralExp_Attribute_part->setUnique(true);
	m_tupleLiteralExp_Attribute_part->setDerived(false);
	m_tupleLiteralExp_Attribute_part->setOrdered(true);
	m_tupleLiteralExp_Attribute_part->setContainment(true);
	m_tupleLiteralExp_Attribute_part->setResolveProxies(true);
	m_tupleLiteralExp_Attribute_part->setDefaultValueLiteral("");	
	
	m_tupleLiteralExp_Attribute_part->_setID(TUPLELITERALEXP_ATTRIBUTE_PART);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeTupleLiteralPartContent()
{
	m_tupleLiteralPart_Class->setName("TupleLiteralPart");
	m_tupleLiteralPart_Class->setAbstract(false);
	m_tupleLiteralPart_Class->setInterface(false);
	
	m_tupleLiteralPart_Class->_setID(TUPLELITERALPART_CLASS);
	
	/*
	 * EAttributes
	 */
	m_tupleLiteralPart_Attribute_tuplePartName = getTupleLiteralPart_Attribute_tuplePartName();
	m_tupleLiteralPart_Attribute_tuplePartName->setName("tuplePartName");
	m_tupleLiteralPart_Attribute_tuplePartName->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_tupleLiteralPart_Attribute_tuplePartName->setLowerBound(0);
	m_tupleLiteralPart_Attribute_tuplePartName->setUpperBound(1);
	m_tupleLiteralPart_Attribute_tuplePartName->setTransient(false);
	m_tupleLiteralPart_Attribute_tuplePartName->setVolatile(false);
	m_tupleLiteralPart_Attribute_tuplePartName->setChangeable(true);
	m_tupleLiteralPart_Attribute_tuplePartName->setUnsettable(false);
	m_tupleLiteralPart_Attribute_tuplePartName->setUnique(true);
	m_tupleLiteralPart_Attribute_tuplePartName->setDerived(false);
	m_tupleLiteralPart_Attribute_tuplePartName->setOrdered(true);
	m_tupleLiteralPart_Attribute_tuplePartName->setID(false);
	m_tupleLiteralPart_Attribute_tuplePartName->setDefaultValueLiteral("");
	
	m_tupleLiteralPart_Attribute_tuplePartName->_setID(TUPLELITERALPART_ATTRIBUTE_TUPLEPARTNAME);
	m_tupleLiteralPart_Attribute_tuplePartType = getTupleLiteralPart_Attribute_tuplePartType();
	m_tupleLiteralPart_Attribute_tuplePartType->setName("tuplePartType");
	m_tupleLiteralPart_Attribute_tuplePartType->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_tupleLiteralPart_Attribute_tuplePartType->setLowerBound(0);
	m_tupleLiteralPart_Attribute_tuplePartType->setUpperBound(1);
	m_tupleLiteralPart_Attribute_tuplePartType->setTransient(false);
	m_tupleLiteralPart_Attribute_tuplePartType->setVolatile(false);
	m_tupleLiteralPart_Attribute_tuplePartType->setChangeable(true);
	m_tupleLiteralPart_Attribute_tuplePartType->setUnsettable(false);
	m_tupleLiteralPart_Attribute_tuplePartType->setUnique(true);
	m_tupleLiteralPart_Attribute_tuplePartType->setDerived(false);
	m_tupleLiteralPart_Attribute_tuplePartType->setOrdered(true);
	m_tupleLiteralPart_Attribute_tuplePartType->setID(false);
	m_tupleLiteralPart_Attribute_tuplePartType->setDefaultValueLiteral("");
	
	m_tupleLiteralPart_Attribute_tuplePartType->_setID(TUPLELITERALPART_ATTRIBUTE_TUPLEPARTTYPE);
	
	/*
	 * EReferences
	 */
	m_tupleLiteralPart_Attribute_assignedOclExpression->setName("assignedOclExpression");
	m_tupleLiteralPart_Attribute_assignedOclExpression->setEType(getOclExpression_Class());
	m_tupleLiteralPart_Attribute_assignedOclExpression->setLowerBound(0);
	m_tupleLiteralPart_Attribute_assignedOclExpression->setUpperBound(1);
	m_tupleLiteralPart_Attribute_assignedOclExpression->setTransient(false);
	m_tupleLiteralPart_Attribute_assignedOclExpression->setVolatile(false);
	m_tupleLiteralPart_Attribute_assignedOclExpression->setChangeable(true);
	m_tupleLiteralPart_Attribute_assignedOclExpression->setUnsettable(false);
	m_tupleLiteralPart_Attribute_assignedOclExpression->setUnique(true);
	m_tupleLiteralPart_Attribute_assignedOclExpression->setDerived(false);
	m_tupleLiteralPart_Attribute_assignedOclExpression->setOrdered(true);
	m_tupleLiteralPart_Attribute_assignedOclExpression->setContainment(false);
	m_tupleLiteralPart_Attribute_assignedOclExpression->setResolveProxies(true);
	m_tupleLiteralPart_Attribute_assignedOclExpression->setDefaultValueLiteral("");	
	
	m_tupleLiteralPart_Attribute_assignedOclExpression->_setID(TUPLELITERALPART_ATTRIBUTE_ASSIGNEDOCLEXPRESSION);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeTupleTypeExpContent()
{
	m_tupleTypeExp_Class->setName("TupleTypeExp");
	m_tupleTypeExp_Class->setAbstract(false);
	m_tupleTypeExp_Class->setInterface(false);
	
	m_tupleTypeExp_Class->_setID(TUPLETYPEEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_tupleTypeExp_Attribute_part->setName("part");
	m_tupleTypeExp_Attribute_part->setEType(getVarDeclarationExp_Class());
	m_tupleTypeExp_Attribute_part->setLowerBound(0);
	m_tupleTypeExp_Attribute_part->setUpperBound(-1);
	m_tupleTypeExp_Attribute_part->setTransient(false);
	m_tupleTypeExp_Attribute_part->setVolatile(false);
	m_tupleTypeExp_Attribute_part->setChangeable(true);
	m_tupleTypeExp_Attribute_part->setUnsettable(false);
	m_tupleTypeExp_Attribute_part->setUnique(true);
	m_tupleTypeExp_Attribute_part->setDerived(false);
	m_tupleTypeExp_Attribute_part->setOrdered(true);
	m_tupleTypeExp_Attribute_part->setContainment(false);
	m_tupleTypeExp_Attribute_part->setResolveProxies(true);
	m_tupleTypeExp_Attribute_part->setDefaultValueLiteral("");	
	
	m_tupleTypeExp_Attribute_part->_setID(TUPLETYPEEXP_ATTRIBUTE_PART);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeTypeExpContent()
{
	m_typeExp_Class->setName("TypeExp");
	m_typeExp_Class->setAbstract(false);
	m_typeExp_Class->setInterface(false);
	
	m_typeExp_Class->_setID(TYPEEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	m_typeExp_Attribute_referredType = getTypeExp_Attribute_referredType();
	m_typeExp_Attribute_referredType->setName("referredType");
	m_typeExp_Attribute_referredType->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_typeExp_Attribute_referredType->setLowerBound(0);
	m_typeExp_Attribute_referredType->setUpperBound(1);
	m_typeExp_Attribute_referredType->setTransient(false);
	m_typeExp_Attribute_referredType->setVolatile(false);
	m_typeExp_Attribute_referredType->setChangeable(true);
	m_typeExp_Attribute_referredType->setUnsettable(false);
	m_typeExp_Attribute_referredType->setUnique(true);
	m_typeExp_Attribute_referredType->setDerived(false);
	m_typeExp_Attribute_referredType->setOrdered(true);
	m_typeExp_Attribute_referredType->setID(false);
	m_typeExp_Attribute_referredType->setDefaultValueLiteral("");
	
	m_typeExp_Attribute_referredType->_setID(TYPEEXP_ATTRIBUTE_REFERREDTYPE);
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeUnlimitedNaturalExpContent()
{
	m_unlimitedNaturalExp_Class->setName("UnlimitedNaturalExp");
	m_unlimitedNaturalExp_Class->setAbstract(false);
	m_unlimitedNaturalExp_Class->setInterface(false);
	
	m_unlimitedNaturalExp_Class->_setID(UNLIMITEDNATURALEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	m_unlimitedNaturalExp_Attribute_unlimitedNaturalSymbol = getUnlimitedNaturalExp_Attribute_unlimitedNaturalSymbol();
	m_unlimitedNaturalExp_Attribute_unlimitedNaturalSymbol->setName("unlimitedNaturalSymbol");
	m_unlimitedNaturalExp_Attribute_unlimitedNaturalSymbol->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
	m_unlimitedNaturalExp_Attribute_unlimitedNaturalSymbol->setLowerBound(0);
	m_unlimitedNaturalExp_Attribute_unlimitedNaturalSymbol->setUpperBound(1);
	m_unlimitedNaturalExp_Attribute_unlimitedNaturalSymbol->setTransient(false);
	m_unlimitedNaturalExp_Attribute_unlimitedNaturalSymbol->setVolatile(false);
	m_unlimitedNaturalExp_Attribute_unlimitedNaturalSymbol->setChangeable(true);
	m_unlimitedNaturalExp_Attribute_unlimitedNaturalSymbol->setUnsettable(false);
	m_unlimitedNaturalExp_Attribute_unlimitedNaturalSymbol->setUnique(true);
	m_unlimitedNaturalExp_Attribute_unlimitedNaturalSymbol->setDerived(false);
	m_unlimitedNaturalExp_Attribute_unlimitedNaturalSymbol->setOrdered(true);
	m_unlimitedNaturalExp_Attribute_unlimitedNaturalSymbol->setID(false);
	m_unlimitedNaturalExp_Attribute_unlimitedNaturalSymbol->setDefaultValueLiteral("");
	
	m_unlimitedNaturalExp_Attribute_unlimitedNaturalSymbol->_setID(UNLIMITEDNATURALEXP_ATTRIBUTE_UNLIMITEDNATURALSYMBOL);
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeUnspecifiedValueExpContent()
{
	m_unspecifiedValueExp_Class->setName("UnspecifiedValueExp");
	m_unspecifiedValueExp_Class->setAbstract(false);
	m_unspecifiedValueExp_Class->setInterface(false);
	
	m_unspecifiedValueExp_Class->_setID(UNSPECIFIEDVALUEEXP_CLASS);
	
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

void ExpressionsPackageImpl::initializeVarDeclarationExpContent()
{
	m_varDeclarationExp_Class->setName("VarDeclarationExp");
	m_varDeclarationExp_Class->setAbstract(false);
	m_varDeclarationExp_Class->setInterface(false);
	
	m_varDeclarationExp_Class->_setID(VARDECLARATIONEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	m_varDeclarationExp_Attribute_varName = getVarDeclarationExp_Attribute_varName();
	m_varDeclarationExp_Attribute_varName->setName("varName");
	m_varDeclarationExp_Attribute_varName->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_varDeclarationExp_Attribute_varName->setLowerBound(0);
	m_varDeclarationExp_Attribute_varName->setUpperBound(1);
	m_varDeclarationExp_Attribute_varName->setTransient(false);
	m_varDeclarationExp_Attribute_varName->setVolatile(false);
	m_varDeclarationExp_Attribute_varName->setChangeable(true);
	m_varDeclarationExp_Attribute_varName->setUnsettable(false);
	m_varDeclarationExp_Attribute_varName->setUnique(true);
	m_varDeclarationExp_Attribute_varName->setDerived(false);
	m_varDeclarationExp_Attribute_varName->setOrdered(true);
	m_varDeclarationExp_Attribute_varName->setID(false);
	m_varDeclarationExp_Attribute_varName->setDefaultValueLiteral("");
	
	m_varDeclarationExp_Attribute_varName->_setID(VARDECLARATIONEXP_ATTRIBUTE_VARNAME);
	
	/*
	 * EReferences
	 */
	m_varDeclarationExp_Attribute_assignedOclExp->setName("assignedOclExp");
	m_varDeclarationExp_Attribute_assignedOclExp->setEType(getOclExpression_Class());
	m_varDeclarationExp_Attribute_assignedOclExp->setLowerBound(0);
	m_varDeclarationExp_Attribute_assignedOclExp->setUpperBound(1);
	m_varDeclarationExp_Attribute_assignedOclExp->setTransient(false);
	m_varDeclarationExp_Attribute_assignedOclExp->setVolatile(false);
	m_varDeclarationExp_Attribute_assignedOclExp->setChangeable(true);
	m_varDeclarationExp_Attribute_assignedOclExp->setUnsettable(false);
	m_varDeclarationExp_Attribute_assignedOclExp->setUnique(true);
	m_varDeclarationExp_Attribute_assignedOclExp->setDerived(false);
	m_varDeclarationExp_Attribute_assignedOclExp->setOrdered(true);
	m_varDeclarationExp_Attribute_assignedOclExp->setContainment(false);
	m_varDeclarationExp_Attribute_assignedOclExp->setResolveProxies(true);
	m_varDeclarationExp_Attribute_assignedOclExp->setDefaultValueLiteral("");	
	
	m_varDeclarationExp_Attribute_assignedOclExp->_setID(VARDECLARATIONEXP_ATTRIBUTE_ASSIGNEDOCLEXP);
	m_varDeclarationExp_Attribute_initExpression->setName("initExpression");
	m_varDeclarationExp_Attribute_initExpression->setEType(getOclExpression_Class());
	m_varDeclarationExp_Attribute_initExpression->setLowerBound(0);
	m_varDeclarationExp_Attribute_initExpression->setUpperBound(1);
	m_varDeclarationExp_Attribute_initExpression->setTransient(false);
	m_varDeclarationExp_Attribute_initExpression->setVolatile(false);
	m_varDeclarationExp_Attribute_initExpression->setChangeable(true);
	m_varDeclarationExp_Attribute_initExpression->setUnsettable(false);
	m_varDeclarationExp_Attribute_initExpression->setUnique(true);
	m_varDeclarationExp_Attribute_initExpression->setDerived(false);
	m_varDeclarationExp_Attribute_initExpression->setOrdered(true);
	m_varDeclarationExp_Attribute_initExpression->setContainment(false);
	m_varDeclarationExp_Attribute_initExpression->setResolveProxies(true);
	m_varDeclarationExp_Attribute_initExpression->setDefaultValueLiteral("");	
	m_varDeclarationExp_Attribute_initExpression->setEOpposite(ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Attribute_initializedElement());
	
	m_varDeclarationExp_Attribute_initExpression->_setID(VARDECLARATIONEXP_ATTRIBUTE_INITEXPRESSION);
	m_varDeclarationExp_Attribute_varType->setName("varType");
	m_varDeclarationExp_Attribute_varType->setEType(getTypeExp_Class());
	m_varDeclarationExp_Attribute_varType->setLowerBound(0);
	m_varDeclarationExp_Attribute_varType->setUpperBound(1);
	m_varDeclarationExp_Attribute_varType->setTransient(false);
	m_varDeclarationExp_Attribute_varType->setVolatile(false);
	m_varDeclarationExp_Attribute_varType->setChangeable(true);
	m_varDeclarationExp_Attribute_varType->setUnsettable(false);
	m_varDeclarationExp_Attribute_varType->setUnique(true);
	m_varDeclarationExp_Attribute_varType->setDerived(false);
	m_varDeclarationExp_Attribute_varType->setOrdered(true);
	m_varDeclarationExp_Attribute_varType->setContainment(false);
	m_varDeclarationExp_Attribute_varType->setResolveProxies(true);
	m_varDeclarationExp_Attribute_varType->setDefaultValueLiteral("");	
	
	m_varDeclarationExp_Attribute_varType->_setID(VARDECLARATIONEXP_ATTRIBUTE_VARTYPE);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeVariableContent()
{
	m_variable_Class->setName("Variable");
	m_variable_Class->setAbstract(false);
	m_variable_Class->setInterface(false);
	
	m_variable_Class->_setID(VARIABLE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_variable_Attribute_baseExp->setName("baseExp");
	m_variable_Attribute_baseExp->setEType(getIterateExp_Class());
	m_variable_Attribute_baseExp->setLowerBound(0);
	m_variable_Attribute_baseExp->setUpperBound(1);
	m_variable_Attribute_baseExp->setTransient(false);
	m_variable_Attribute_baseExp->setVolatile(false);
	m_variable_Attribute_baseExp->setChangeable(true);
	m_variable_Attribute_baseExp->setUnsettable(false);
	m_variable_Attribute_baseExp->setUnique(true);
	m_variable_Attribute_baseExp->setDerived(false);
	m_variable_Attribute_baseExp->setOrdered(true);
	m_variable_Attribute_baseExp->setContainment(false);
	m_variable_Attribute_baseExp->setResolveProxies(true);
	m_variable_Attribute_baseExp->setDefaultValueLiteral("");	
	
	m_variable_Attribute_baseExp->_setID(VARIABLE_ATTRIBUTE_BASEEXP);
	m_variable_Attribute_initExpression->setName("initExpression");
	m_variable_Attribute_initExpression->setEType(getOclExpression_Class());
	m_variable_Attribute_initExpression->setLowerBound(0);
	m_variable_Attribute_initExpression->setUpperBound(1);
	m_variable_Attribute_initExpression->setTransient(false);
	m_variable_Attribute_initExpression->setVolatile(false);
	m_variable_Attribute_initExpression->setChangeable(true);
	m_variable_Attribute_initExpression->setUnsettable(false);
	m_variable_Attribute_initExpression->setUnique(true);
	m_variable_Attribute_initExpression->setDerived(false);
	m_variable_Attribute_initExpression->setOrdered(false);
	m_variable_Attribute_initExpression->setContainment(true);
	m_variable_Attribute_initExpression->setResolveProxies(true);
	m_variable_Attribute_initExpression->setDefaultValueLiteral("");	
	
	m_variable_Attribute_initExpression->_setID(VARIABLE_ATTRIBUTE_INITEXPRESSION);
	m_variable_Attribute_loopExp->setName("loopExp");
	m_variable_Attribute_loopExp->setEType(getLoopExp_Class());
	m_variable_Attribute_loopExp->setLowerBound(0);
	m_variable_Attribute_loopExp->setUpperBound(1);
	m_variable_Attribute_loopExp->setTransient(false);
	m_variable_Attribute_loopExp->setVolatile(false);
	m_variable_Attribute_loopExp->setChangeable(true);
	m_variable_Attribute_loopExp->setUnsettable(false);
	m_variable_Attribute_loopExp->setUnique(true);
	m_variable_Attribute_loopExp->setDerived(false);
	m_variable_Attribute_loopExp->setOrdered(true);
	m_variable_Attribute_loopExp->setContainment(false);
	m_variable_Attribute_loopExp->setResolveProxies(true);
	m_variable_Attribute_loopExp->setDefaultValueLiteral("");	
	
	m_variable_Attribute_loopExp->_setID(VARIABLE_ATTRIBUTE_LOOPEXP);
	m_variable_Attribute_referringExp->setName("referringExp");
	m_variable_Attribute_referringExp->setEType(getVariableExp_Class());
	m_variable_Attribute_referringExp->setLowerBound(0);
	m_variable_Attribute_referringExp->setUpperBound(1);
	m_variable_Attribute_referringExp->setTransient(false);
	m_variable_Attribute_referringExp->setVolatile(false);
	m_variable_Attribute_referringExp->setChangeable(true);
	m_variable_Attribute_referringExp->setUnsettable(false);
	m_variable_Attribute_referringExp->setUnique(true);
	m_variable_Attribute_referringExp->setDerived(false);
	m_variable_Attribute_referringExp->setOrdered(true);
	m_variable_Attribute_referringExp->setContainment(false);
	m_variable_Attribute_referringExp->setResolveProxies(true);
	m_variable_Attribute_referringExp->setDefaultValueLiteral("");	
	
	m_variable_Attribute_referringExp->_setID(VARIABLE_ATTRIBUTE_REFERRINGEXP);
	m_variable_Attribute_representedParameter->setName("representedParameter");
	m_variable_Attribute_representedParameter->setEType(ecore::ecorePackage::eInstance()->getEParameter_Class());
	m_variable_Attribute_representedParameter->setLowerBound(0);
	m_variable_Attribute_representedParameter->setUpperBound(1);
	m_variable_Attribute_representedParameter->setTransient(false);
	m_variable_Attribute_representedParameter->setVolatile(false);
	m_variable_Attribute_representedParameter->setChangeable(true);
	m_variable_Attribute_representedParameter->setUnsettable(false);
	m_variable_Attribute_representedParameter->setUnique(true);
	m_variable_Attribute_representedParameter->setDerived(false);
	m_variable_Attribute_representedParameter->setOrdered(false);
	m_variable_Attribute_representedParameter->setContainment(false);
	m_variable_Attribute_representedParameter->setResolveProxies(true);
	m_variable_Attribute_representedParameter->setDefaultValueLiteral("");	
	
	m_variable_Attribute_representedParameter->_setID(VARIABLE_ATTRIBUTE_REPRESENTEDPARAMETER);
	m_variable_Attribute_resultOwner->setName("resultOwner");
	m_variable_Attribute_resultOwner->setEType(getExpressionInOcl_Class());
	m_variable_Attribute_resultOwner->setLowerBound(0);
	m_variable_Attribute_resultOwner->setUpperBound(1);
	m_variable_Attribute_resultOwner->setTransient(false);
	m_variable_Attribute_resultOwner->setVolatile(false);
	m_variable_Attribute_resultOwner->setChangeable(true);
	m_variable_Attribute_resultOwner->setUnsettable(false);
	m_variable_Attribute_resultOwner->setUnique(true);
	m_variable_Attribute_resultOwner->setDerived(false);
	m_variable_Attribute_resultOwner->setOrdered(true);
	m_variable_Attribute_resultOwner->setContainment(false);
	m_variable_Attribute_resultOwner->setResolveProxies(true);
	m_variable_Attribute_resultOwner->setDefaultValueLiteral("");	
	
	m_variable_Attribute_resultOwner->_setID(VARIABLE_ATTRIBUTE_RESULTOWNER);
	m_variable_Attribute_selfOwner->setName("selfOwner");
	m_variable_Attribute_selfOwner->setEType(getExpressionInOcl_Class());
	m_variable_Attribute_selfOwner->setLowerBound(0);
	m_variable_Attribute_selfOwner->setUpperBound(1);
	m_variable_Attribute_selfOwner->setTransient(false);
	m_variable_Attribute_selfOwner->setVolatile(false);
	m_variable_Attribute_selfOwner->setChangeable(true);
	m_variable_Attribute_selfOwner->setUnsettable(false);
	m_variable_Attribute_selfOwner->setUnique(true);
	m_variable_Attribute_selfOwner->setDerived(false);
	m_variable_Attribute_selfOwner->setOrdered(true);
	m_variable_Attribute_selfOwner->setContainment(false);
	m_variable_Attribute_selfOwner->setResolveProxies(true);
	m_variable_Attribute_selfOwner->setDefaultValueLiteral("");	
	
	m_variable_Attribute_selfOwner->_setID(VARIABLE_ATTRIBUTE_SELFOWNER);
	m_variable_Attribute_value->setName("value");
	m_variable_Attribute_value->setEType(ecore::ecorePackage::eInstance()->getETypedElement_Class());
	m_variable_Attribute_value->setLowerBound(0);
	m_variable_Attribute_value->setUpperBound(1);
	m_variable_Attribute_value->setTransient(false);
	m_variable_Attribute_value->setVolatile(false);
	m_variable_Attribute_value->setChangeable(true);
	m_variable_Attribute_value->setUnsettable(false);
	m_variable_Attribute_value->setUnique(true);
	m_variable_Attribute_value->setDerived(false);
	m_variable_Attribute_value->setOrdered(true);
	m_variable_Attribute_value->setContainment(false);
	m_variable_Attribute_value->setResolveProxies(true);
	m_variable_Attribute_value->setDefaultValueLiteral("");	
	
	m_variable_Attribute_value->_setID(VARIABLE_ATTRIBUTE_VALUE);
	m_variable_Attribute_varOwner->setName("varOwner");
	m_variable_Attribute_varOwner->setEType(getExpressionInOcl_Class());
	m_variable_Attribute_varOwner->setLowerBound(0);
	m_variable_Attribute_varOwner->setUpperBound(1);
	m_variable_Attribute_varOwner->setTransient(false);
	m_variable_Attribute_varOwner->setVolatile(false);
	m_variable_Attribute_varOwner->setChangeable(true);
	m_variable_Attribute_varOwner->setUnsettable(false);
	m_variable_Attribute_varOwner->setUnique(true);
	m_variable_Attribute_varOwner->setDerived(false);
	m_variable_Attribute_varOwner->setOrdered(true);
	m_variable_Attribute_varOwner->setContainment(false);
	m_variable_Attribute_varOwner->setResolveProxies(true);
	m_variable_Attribute_varOwner->setDefaultValueLiteral("");	
	
	m_variable_Attribute_varOwner->_setID(VARIABLE_ATTRIBUTE_VAROWNER);
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializeVariableExpContent()
{
	m_variableExp_Class->setName("VariableExp");
	m_variableExp_Class->setAbstract(false);
	m_variableExp_Class->setInterface(false);
	
	m_variableExp_Class->_setID(VARIABLEEXP_CLASS);
	
	/*
	 * EAttributes
	 */
	m_variableExp_Attribute_referredVariable = getVariableExp_Attribute_referredVariable();
	m_variableExp_Attribute_referredVariable->setName("referredVariable");
	m_variableExp_Attribute_referredVariable->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_variableExp_Attribute_referredVariable->setLowerBound(0);
	m_variableExp_Attribute_referredVariable->setUpperBound(1);
	m_variableExp_Attribute_referredVariable->setTransient(false);
	m_variableExp_Attribute_referredVariable->setVolatile(false);
	m_variableExp_Attribute_referredVariable->setChangeable(true);
	m_variableExp_Attribute_referredVariable->setUnsettable(false);
	m_variableExp_Attribute_referredVariable->setUnique(true);
	m_variableExp_Attribute_referredVariable->setDerived(false);
	m_variableExp_Attribute_referredVariable->setOrdered(true);
	m_variableExp_Attribute_referredVariable->setID(false);
	m_variableExp_Attribute_referredVariable->setDefaultValueLiteral("");
	
	m_variableExp_Attribute_referredVariable->_setID(VARIABLEEXP_ATTRIBUTE_REFERREDVARIABLE);
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void ExpressionsPackageImpl::initializePackageEDataTypes()
{
	m_collectionKind_Class->setName("CollectionKind");
	m_prePostBody_Class->setName("PrePostBody");
	m_surroundingType_Class->setName("SurroundingType");
	
}

