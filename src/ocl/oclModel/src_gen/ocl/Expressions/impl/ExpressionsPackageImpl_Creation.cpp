#include "ocl/Expressions/impl/ExpressionsPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EReference.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EEnumLiteral.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "ocl/oclPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"
//include subpackages 
 
using namespace ocl::Expressions;

void ExpressionsPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();

	createAssociationClassCallExpContent(package, factory);
	createBooleanLiteralExpContent(package, factory);
	createCallExpContent(package, factory);
	createCollectionItemContent(package, factory);
	createCollectionLiteralExpContent(package, factory);
	createCollectionLiteralPartContent(package, factory);
	createCollectionRangeContent(package, factory);
	createEnumLiteralExpContent(package, factory);
	createExpressionInOclContent(package, factory);
	createFeatureCallExpContent(package, factory);
	createIfExpContent(package, factory);
	createInfixedExpContent(package, factory);
	createIntegerLiteralExpContent(package, factory);
	createInvalidLiteralExpContent(package, factory);
	createIterateExpContent(package, factory);
	createIteratorExpContent(package, factory);
	createLetExpContent(package, factory);
	createLiteralExpContent(package, factory);
	createLoopExpContent(package, factory);
	createMessageExpContent(package, factory);
	createNavigationCallExpContent(package, factory);
	createNullLiteralExpContent(package, factory);
	createNumericLiteralExpContent(package, factory);
	createOclExpressionContent(package, factory);
	createOperationCallExpContent(package, factory);
	createPrimitiveLiteralExpContent(package, factory);
	createPropertyCallExpContent(package, factory);
	createRealLiteralExpContent(package, factory);
	createStateExpContent(package, factory);
	createStringLiteralExpContent(package, factory);
	createTupleLiteralExpContent(package, factory);
	createTupleLiteralPartContent(package, factory);
	createTypeExpContent(package, factory);
	createUnlimitedNaturalExpContent(package, factory);
	createUnspecifiedValueExpContent(package, factory);
	createVariableContent(package, factory);
	createVariableExpContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void ExpressionsPackageImpl::createAssociationClassCallExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_associationClassCallExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ASSOCIATIONCLASSCALLEXP_CLASS);
	
	m_associationClassCallExp_Attribute_referredAssociationClass = factory->createEReference_as_eStructuralFeatures_in_EClass(m_associationClassCallExp_Class, ASSOCIATIONCLASSCALLEXP_ATTRIBUTE_REFERREDASSOCIATIONCLASS);
	
}

void ExpressionsPackageImpl::createBooleanLiteralExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_booleanLiteralExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, BOOLEANLITERALEXP_CLASS);
	m_booleanLiteralExp_Attribute_booleanSymbol = factory->createEAttribute_as_eStructuralFeatures_in_EClass(m_booleanLiteralExp_Class, BOOLEANLITERALEXP_ATTRIBUTE_BOOLEANSYMBOL);
	
	
}

void ExpressionsPackageImpl::createCallExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_callExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CALLEXP_CLASS);
	
	m_callExp_Attribute_source = factory->createEReference_as_eStructuralFeatures_in_EClass(m_callExp_Class, CALLEXP_ATTRIBUTE_SOURCE);
	
}

void ExpressionsPackageImpl::createCollectionItemContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_collectionItem_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, COLLECTIONITEM_CLASS);
	
	m_collectionItem_Attribute_item = factory->createEReference_as_eStructuralFeatures_in_EClass(m_collectionItem_Class, COLLECTIONITEM_ATTRIBUTE_ITEM);
	
}

void ExpressionsPackageImpl::createCollectionLiteralExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_collectionLiteralExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, COLLECTIONLITERALEXP_CLASS);
	m_collectionLiteralExp_Attribute_kind = factory->createEAttribute_as_eStructuralFeatures_in_EClass(m_collectionLiteralExp_Class, COLLECTIONLITERALEXP_ATTRIBUTE_KIND);
	m_collectionLiteralExp_Attribute_part = factory->createEReference_as_eStructuralFeatures_in_EClass(m_collectionLiteralExp_Class, COLLECTIONLITERALEXP_ATTRIBUTE_PART);
	
}

void ExpressionsPackageImpl::createCollectionLiteralPartContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_collectionLiteralPart_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, COLLECTIONLITERALPART_CLASS);
	
	
	
}

void ExpressionsPackageImpl::createCollectionRangeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_collectionRange_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, COLLECTIONRANGE_CLASS);
	
	m_collectionRange_Attribute_first = factory->createEReference_as_eStructuralFeatures_in_EClass(m_collectionRange_Class, COLLECTIONRANGE_ATTRIBUTE_FIRST);m_collectionRange_Attribute_last = factory->createEReference_as_eStructuralFeatures_in_EClass(m_collectionRange_Class, COLLECTIONRANGE_ATTRIBUTE_LAST);
	
}

void ExpressionsPackageImpl::createEnumLiteralExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_enumLiteralExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ENUMLITERALEXP_CLASS);
	
	m_enumLiteralExp_Attribute_referredEnumLiteral = factory->createEReference_as_eStructuralFeatures_in_EClass(m_enumLiteralExp_Class, ENUMLITERALEXP_ATTRIBUTE_REFERREDENUMLITERAL);
	
}

void ExpressionsPackageImpl::createExpressionInOclContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_expressionInOcl_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EXPRESSIONINOCL_CLASS);
	
	m_expressionInOcl_Attribute_bodyExpression = factory->createEReference_as_eStructuralFeatures_in_EClass(m_expressionInOcl_Class, EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION);m_expressionInOcl_Attribute_contextVariable = factory->createEReference_as_eStructuralFeatures_in_EClass(m_expressionInOcl_Class, EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE);m_expressionInOcl_Attribute_parameterVariable = factory->createEReference_as_eStructuralFeatures_in_EClass(m_expressionInOcl_Class, EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE);m_expressionInOcl_Attribute_resultVariable = factory->createEReference_as_eStructuralFeatures_in_EClass(m_expressionInOcl_Class, EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE);
	
}

void ExpressionsPackageImpl::createFeatureCallExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_featureCallExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, FEATURECALLEXP_CLASS);
	m_featureCallExp_Attribute_isPre = factory->createEAttribute_as_eStructuralFeatures_in_EClass(m_featureCallExp_Class, FEATURECALLEXP_ATTRIBUTE_ISPRE);
	
	
}

void ExpressionsPackageImpl::createIfExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_ifExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, IFEXP_CLASS);
	
	m_ifExp_Attribute_condition = factory->createEReference_as_eStructuralFeatures_in_EClass(m_ifExp_Class, IFEXP_ATTRIBUTE_CONDITION);m_ifExp_Attribute_elseExpression = factory->createEReference_as_eStructuralFeatures_in_EClass(m_ifExp_Class, IFEXP_ATTRIBUTE_ELSEEXPRESSION);m_ifExp_Attribute_thenExpression = factory->createEReference_as_eStructuralFeatures_in_EClass(m_ifExp_Class, IFEXP_ATTRIBUTE_THENEXPRESSION);
	
}

void ExpressionsPackageImpl::createInfixedExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_infixedExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INFIXEDEXP_CLASS);
	
	m_infixedExp_Attribute_source = factory->createEReference_as_eStructuralFeatures_in_EClass(m_infixedExp_Class, INFIXEDEXP_ATTRIBUTE_SOURCE);
	
}

void ExpressionsPackageImpl::createIntegerLiteralExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_integerLiteralExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INTEGERLITERALEXP_CLASS);
	m_integerLiteralExp_Attribute_integerSymbol = factory->createEAttribute_as_eStructuralFeatures_in_EClass(m_integerLiteralExp_Class, INTEGERLITERALEXP_ATTRIBUTE_INTEGERSYMBOL);
	
	
}

void ExpressionsPackageImpl::createInvalidLiteralExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_invalidLiteralExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INVALIDLITERALEXP_CLASS);
	
	
	
}

void ExpressionsPackageImpl::createIterateExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_iterateExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ITERATEEXP_CLASS);
	
	m_iterateExp_Attribute_result = factory->createEReference_as_eStructuralFeatures_in_EClass(m_iterateExp_Class, ITERATEEXP_ATTRIBUTE_RESULT);
	
}

void ExpressionsPackageImpl::createIteratorExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_iteratorExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ITERATOREXP_CLASS);
	
	
	
}

void ExpressionsPackageImpl::createLetExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_letExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, LETEXP_CLASS);
	
	m_letExp_Attribute_in = factory->createEReference_as_eStructuralFeatures_in_EClass(m_letExp_Class, LETEXP_ATTRIBUTE_IN);m_letExp_Attribute_variable = factory->createEReference_as_eStructuralFeatures_in_EClass(m_letExp_Class, LETEXP_ATTRIBUTE_VARIABLE);
	
}

void ExpressionsPackageImpl::createLiteralExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_literalExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, LITERALEXP_CLASS);
	
	
	
}

void ExpressionsPackageImpl::createLoopExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_loopExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, LOOPEXP_CLASS);
	
	m_loopExp_Attribute_body = factory->createEReference_as_eStructuralFeatures_in_EClass(m_loopExp_Class, LOOPEXP_ATTRIBUTE_BODY);m_loopExp_Attribute_iterator = factory->createEReference_as_eStructuralFeatures_in_EClass(m_loopExp_Class, LOOPEXP_ATTRIBUTE_ITERATOR);
	
}

void ExpressionsPackageImpl::createMessageExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_messageExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, MESSAGEEXP_CLASS);
	
	m_messageExp_Attribute_argument = factory->createEReference_as_eStructuralFeatures_in_EClass(m_messageExp_Class, MESSAGEEXP_ATTRIBUTE_ARGUMENT);m_messageExp_Attribute_calledOperation = factory->createEReference_as_eStructuralFeatures_in_EClass(m_messageExp_Class, MESSAGEEXP_ATTRIBUTE_CALLEDOPERATION);m_messageExp_Attribute_sentSignal = factory->createEReference_as_eStructuralFeatures_in_EClass(m_messageExp_Class, MESSAGEEXP_ATTRIBUTE_SENTSIGNAL);m_messageExp_Attribute_target = factory->createEReference_as_eStructuralFeatures_in_EClass(m_messageExp_Class, MESSAGEEXP_ATTRIBUTE_TARGET);
	
}

void ExpressionsPackageImpl::createNavigationCallExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_navigationCallExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, NAVIGATIONCALLEXP_CLASS);
	
	m_navigationCallExp_Attribute_navigationSource = factory->createEReference_as_eStructuralFeatures_in_EClass(m_navigationCallExp_Class, NAVIGATIONCALLEXP_ATTRIBUTE_NAVIGATIONSOURCE);m_navigationCallExp_Attribute_qualifier = factory->createEReference_as_eStructuralFeatures_in_EClass(m_navigationCallExp_Class, NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER);
	
}

void ExpressionsPackageImpl::createNullLiteralExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_nullLiteralExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, NULLLITERALEXP_CLASS);
	
	
	
}

void ExpressionsPackageImpl::createNumericLiteralExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_numericLiteralExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, NUMERICLITERALEXP_CLASS);
	
	
	
}

void ExpressionsPackageImpl::createOclExpressionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_oclExpression_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, OCLEXPRESSION_CLASS);
	
	m_oclExpression_Attribute_appliedElement = factory->createEReference_as_eStructuralFeatures_in_EClass(m_oclExpression_Class, OCLEXPRESSION_ATTRIBUTE_APPLIEDELEMENT);m_oclExpression_Attribute_elseOwner = factory->createEReference_as_eStructuralFeatures_in_EClass(m_oclExpression_Class, OCLEXPRESSION_ATTRIBUTE_ELSEOWNER);m_oclExpression_Attribute_firstOwner = factory->createEReference_as_eStructuralFeatures_in_EClass(m_oclExpression_Class, OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER);m_oclExpression_Attribute_ifOwner = factory->createEReference_as_eStructuralFeatures_in_EClass(m_oclExpression_Class, OCLEXPRESSION_ATTRIBUTE_IFOWNER);m_oclExpression_Attribute_initializedElement = factory->createEReference_as_eStructuralFeatures_in_EClass(m_oclExpression_Class, OCLEXPRESSION_ATTRIBUTE_INITIALIZEDELEMENT);m_oclExpression_Attribute_instance = factory->createEReference_as_eStructuralFeatures_in_EClass(m_oclExpression_Class, OCLEXPRESSION_ATTRIBUTE_INSTANCE);m_oclExpression_Attribute_lastOwner = factory->createEReference_as_eStructuralFeatures_in_EClass(m_oclExpression_Class, OCLEXPRESSION_ATTRIBUTE_LASTOWNER);m_oclExpression_Attribute_loopBodyOwner = factory->createEReference_as_eStructuralFeatures_in_EClass(m_oclExpression_Class, OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER);m_oclExpression_Attribute_parentCall = factory->createEReference_as_eStructuralFeatures_in_EClass(m_oclExpression_Class, OCLEXPRESSION_ATTRIBUTE_PARENTCALL);m_oclExpression_Attribute_parentNav = factory->createEReference_as_eStructuralFeatures_in_EClass(m_oclExpression_Class, OCLEXPRESSION_ATTRIBUTE_PARENTNAV);m_oclExpression_Attribute_thenOwner = factory->createEReference_as_eStructuralFeatures_in_EClass(m_oclExpression_Class, OCLEXPRESSION_ATTRIBUTE_THENOWNER);m_oclExpression_Attribute_topExpression = factory->createEReference_as_eStructuralFeatures_in_EClass(m_oclExpression_Class, OCLEXPRESSION_ATTRIBUTE_TOPEXPRESSION);
	
}

void ExpressionsPackageImpl::createOperationCallExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_operationCallExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, OPERATIONCALLEXP_CLASS);
	
	m_operationCallExp_Attribute_argument = factory->createEReference_as_eStructuralFeatures_in_EClass(m_operationCallExp_Class, OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT);m_operationCallExp_Attribute_referredOperation = factory->createEReference_as_eStructuralFeatures_in_EClass(m_operationCallExp_Class, OPERATIONCALLEXP_ATTRIBUTE_REFERREDOPERATION);
	
}

void ExpressionsPackageImpl::createPrimitiveLiteralExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_primitiveLiteralExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PRIMITIVELITERALEXP_CLASS);
	m_primitiveLiteralExp_Attribute_symbol = factory->createEAttribute_as_eStructuralFeatures_in_EClass(m_primitiveLiteralExp_Class, PRIMITIVELITERALEXP_ATTRIBUTE_SYMBOL);
	
	
}

void ExpressionsPackageImpl::createPropertyCallExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_propertyCallExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PROPERTYCALLEXP_CLASS);
	
	m_propertyCallExp_Attribute_referredProperty = factory->createEReference_as_eStructuralFeatures_in_EClass(m_propertyCallExp_Class, PROPERTYCALLEXP_ATTRIBUTE_REFERREDPROPERTY);
	
}

void ExpressionsPackageImpl::createRealLiteralExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_realLiteralExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, REALLITERALEXP_CLASS);
	m_realLiteralExp_Attribute_realSymbol = factory->createEAttribute_as_eStructuralFeatures_in_EClass(m_realLiteralExp_Class, REALLITERALEXP_ATTRIBUTE_REALSYMBOL);
	
	
}

void ExpressionsPackageImpl::createStateExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_stateExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, STATEEXP_CLASS);
	
	m_stateExp_Attribute_referredState = factory->createEReference_as_eStructuralFeatures_in_EClass(m_stateExp_Class, STATEEXP_ATTRIBUTE_REFERREDSTATE);
	
}

void ExpressionsPackageImpl::createStringLiteralExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_stringLiteralExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, STRINGLITERALEXP_CLASS);
	m_stringLiteralExp_Attribute_stringSymbol = factory->createEAttribute_as_eStructuralFeatures_in_EClass(m_stringLiteralExp_Class, STRINGLITERALEXP_ATTRIBUTE_STRINGSYMBOL);
	
	
}

void ExpressionsPackageImpl::createTupleLiteralExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_tupleLiteralExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, TUPLELITERALEXP_CLASS);
	
	m_tupleLiteralExp_Attribute_part = factory->createEReference_as_eStructuralFeatures_in_EClass(m_tupleLiteralExp_Class, TUPLELITERALEXP_ATTRIBUTE_PART);
	
}

void ExpressionsPackageImpl::createTupleLiteralPartContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_tupleLiteralPart_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, TUPLELITERALPART_CLASS);
	
	m_tupleLiteralPart_Attribute_attribute = factory->createEReference_as_eStructuralFeatures_in_EClass(m_tupleLiteralPart_Class, TUPLELITERALPART_ATTRIBUTE_ATTRIBUTE);
	
}

void ExpressionsPackageImpl::createTypeExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_typeExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, TYPEEXP_CLASS);
	
	m_typeExp_Attribute_referredType = factory->createEReference_as_eStructuralFeatures_in_EClass(m_typeExp_Class, TYPEEXP_ATTRIBUTE_REFERREDTYPE);
	
}

void ExpressionsPackageImpl::createUnlimitedNaturalExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_unlimitedNaturalExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, UNLIMITEDNATURALEXP_CLASS);
	m_unlimitedNaturalExp_Attribute_unlimitedNaturalSymbol = factory->createEAttribute_as_eStructuralFeatures_in_EClass(m_unlimitedNaturalExp_Class, UNLIMITEDNATURALEXP_ATTRIBUTE_UNLIMITEDNATURALSYMBOL);
	
	
}

void ExpressionsPackageImpl::createUnspecifiedValueExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_unspecifiedValueExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, UNSPECIFIEDVALUEEXP_CLASS);
	
	
	
}

void ExpressionsPackageImpl::createVariableContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_variable_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, VARIABLE_CLASS);
	
	m_variable_Attribute_baseExp = factory->createEReference_as_eStructuralFeatures_in_EClass(m_variable_Class, VARIABLE_ATTRIBUTE_BASEEXP);m_variable_Attribute_initExpression = factory->createEReference_as_eStructuralFeatures_in_EClass(m_variable_Class, VARIABLE_ATTRIBUTE_INITEXPRESSION);m_variable_Attribute_loopExp = factory->createEReference_as_eStructuralFeatures_in_EClass(m_variable_Class, VARIABLE_ATTRIBUTE_LOOPEXP);m_variable_Attribute_referringExp = factory->createEReference_as_eStructuralFeatures_in_EClass(m_variable_Class, VARIABLE_ATTRIBUTE_REFERRINGEXP);m_variable_Attribute_representedParameter = factory->createEReference_as_eStructuralFeatures_in_EClass(m_variable_Class, VARIABLE_ATTRIBUTE_REPRESENTEDPARAMETER);m_variable_Attribute_resultOwner = factory->createEReference_as_eStructuralFeatures_in_EClass(m_variable_Class, VARIABLE_ATTRIBUTE_RESULTOWNER);m_variable_Attribute_selfOwner = factory->createEReference_as_eStructuralFeatures_in_EClass(m_variable_Class, VARIABLE_ATTRIBUTE_SELFOWNER);m_variable_Attribute_value = factory->createEReference_as_eStructuralFeatures_in_EClass(m_variable_Class, VARIABLE_ATTRIBUTE_VALUE);m_variable_Attribute_varOwner = factory->createEReference_as_eStructuralFeatures_in_EClass(m_variable_Class, VARIABLE_ATTRIBUTE_VAROWNER);
	
}

void ExpressionsPackageImpl::createVariableExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_variableExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, VARIABLEEXP_CLASS);
	
	m_variableExp_Attribute_referredVariable = factory->createEReference_as_eStructuralFeatures_in_EClass(m_variableExp_Class, VARIABLEEXP_ATTRIBUTE_REFERREDVARIABLE);
	
}

void ExpressionsPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_collectionKind_Class = factory->createEEnum_as_eClassifiers_in_EPackage(package, COLLECTIONKIND_CLASS);
	
}
