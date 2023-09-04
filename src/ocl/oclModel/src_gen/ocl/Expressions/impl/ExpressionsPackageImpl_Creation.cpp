#include "ocl/Expressions/impl/ExpressionsPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EEnum.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EEnumLiteral.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EDataType.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "ocl/oclPackage.hpp"
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
	createClassifierContextDeclExpContent(package, factory);
	createCollectionItemContent(package, factory);
	createCollectionLiteralExpContent(package, factory);
	createCollectionLiteralPartContent(package, factory);
	createCollectionLiteralPartsContent(package, factory);
	createCollectionRangeContent(package, factory);
	createCollectionTypeExpContent(package, factory);
	createContextDeclarationExpContent(package, factory);
	createDefExpContent(package, factory);
	createEnumLiteralExpContent(package, factory);
	createExpressionInOclContent(package, factory);
	createFeatureCallExpContent(package, factory);
	createIfExpContent(package, factory);
	createInfixedExpContent(package, factory);
	createInitOrDerValueExpContent(package, factory);
	createInitOrDerValueListExpContent(package, factory);
	createIntegerLiteralExpContent(package, factory);
	createInvOrDefExpContent(package, factory);
	createInvalidLiteralExpContent(package, factory);
	createIterateExpContent(package, factory);
	createIteratorExpContent(package, factory);
	createLetExpContent(package, factory);
	createLiteralExpContent(package, factory);
	createLoopExpContent(package, factory);
	createMessageArgumentsContent(package, factory);
	createMessageExpContent(package, factory);
	createNavigationCallExpContent(package, factory);
	createNullLiteralExpContent(package, factory);
	createNumericLiteralExpContent(package, factory);
	createOclExpressionContent(package, factory);
	createOperationCallExpContent(package, factory);
	createOperationContextDeclExpContent(package, factory);
	createOperationContextExpContent(package, factory);
	createOperatorExpContent(package, factory);
	createPackageDeclarationExpContent(package, factory);
	createParentedExpContent(package, factory);
	createPrePostBodyExpContent(package, factory);
	createPrePostBodyListExpContent(package, factory);
	createPrefixedExpContent(package, factory);
	createPrimitiveLiteralExpContent(package, factory);
	createPropertyCallExpContent(package, factory);
	createPropertyContextDeclExpContent(package, factory);
	createRealLiteralExpContent(package, factory);
	createStateExpContent(package, factory);
	createStringLiteralExpContent(package, factory);
	createTupleLiteralExpContent(package, factory);
	createTupleLiteralPartContent(package, factory);
	createTupleTypeExpContent(package, factory);
	createTypeExpContent(package, factory);
	createUnlimitedNaturalExpContent(package, factory);
	createUnspecifiedValueExpContent(package, factory);
	createVarDeclarationExpContent(package, factory);
	createVariableContent(package, factory);
	createVariableExpContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void ExpressionsPackageImpl::createAssociationClassCallExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_associationClassCallExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ASSOCIATIONCLASSCALLEXP_CLASS);
	m_associationClassCallExp_Attribute_referredAssociationClass = factory->createEAttribute_as_eAttributes_in_EClass(m_associationClassCallExp_Class, ASSOCIATIONCLASSCALLEXP_ATTRIBUTE_REFERREDASSOCIATIONCLASS);
	
	
	
}

void ExpressionsPackageImpl::createBooleanLiteralExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_booleanLiteralExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, BOOLEANLITERALEXP_CLASS);
	m_booleanLiteralExp_Attribute_booleanSymbol = factory->createEAttribute_as_eAttributes_in_EClass(m_booleanLiteralExp_Class, BOOLEANLITERALEXP_ATTRIBUTE_BOOLEANSYMBOL);
	
	
	
}

void ExpressionsPackageImpl::createCallExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_callExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CALLEXP_CLASS);
	
	m_callExp_Attribute_source = factory->createEReference_as_eReferences_in_EClass(m_callExp_Class, CALLEXP_ATTRIBUTE_SOURCE);
	
	
}

void ExpressionsPackageImpl::createClassifierContextDeclExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_classifierContextDeclExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CLASSIFIERCONTEXTDECLEXP_CLASS);
	m_classifierContextDeclExp_Attribute_classifierName = factory->createEAttribute_as_eAttributes_in_EClass(m_classifierContextDeclExp_Class, CLASSIFIERCONTEXTDECLEXP_ATTRIBUTE_CLASSIFIERNAME);
	
	m_classifierContextDeclExp_Attribute_invOrDevExp = factory->createEReference_as_eReferences_in_EClass(m_classifierContextDeclExp_Class, CLASSIFIERCONTEXTDECLEXP_ATTRIBUTE_INVORDEVEXP);
	
	
}

void ExpressionsPackageImpl::createCollectionItemContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_collectionItem_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, COLLECTIONITEM_CLASS);
	
	m_collectionItem_Attribute_item = factory->createEReference_as_eReferences_in_EClass(m_collectionItem_Class, COLLECTIONITEM_ATTRIBUTE_ITEM);
	
	
}

void ExpressionsPackageImpl::createCollectionLiteralExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_collectionLiteralExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, COLLECTIONLITERALEXP_CLASS);
	m_collectionLiteralExp_Attribute_kind = factory->createEAttribute_as_eAttributes_in_EClass(m_collectionLiteralExp_Class, COLLECTIONLITERALEXP_ATTRIBUTE_KIND);
	
	m_collectionLiteralExp_Attribute_part = factory->createEReference_as_eReferences_in_EClass(m_collectionLiteralExp_Class, COLLECTIONLITERALEXP_ATTRIBUTE_PART);
	
	
}

void ExpressionsPackageImpl::createCollectionLiteralPartContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_collectionLiteralPart_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, COLLECTIONLITERALPART_CLASS);
	
	
	
}

void ExpressionsPackageImpl::createCollectionLiteralPartsContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_collectionLiteralParts_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, COLLECTIONLITERALPARTS_CLASS);
	
	m_collectionLiteralParts_Attribute_literalParts = factory->createEReference_as_eReferences_in_EClass(m_collectionLiteralParts_Class, COLLECTIONLITERALPARTS_ATTRIBUTE_LITERALPARTS);
	
	
}

void ExpressionsPackageImpl::createCollectionRangeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_collectionRange_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, COLLECTIONRANGE_CLASS);
	
	m_collectionRange_Attribute_first = factory->createEReference_as_eReferences_in_EClass(m_collectionRange_Class, COLLECTIONRANGE_ATTRIBUTE_FIRST);
	m_collectionRange_Attribute_last = factory->createEReference_as_eReferences_in_EClass(m_collectionRange_Class, COLLECTIONRANGE_ATTRIBUTE_LAST);
	
	
}

void ExpressionsPackageImpl::createCollectionTypeExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_collectionTypeExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, COLLECTIONTYPEEXP_CLASS);
	
	m_collectionTypeExp_Attribute_innerType = factory->createEReference_as_eReferences_in_EClass(m_collectionTypeExp_Class, COLLECTIONTYPEEXP_ATTRIBUTE_INNERTYPE);
	
	
}

void ExpressionsPackageImpl::createContextDeclarationExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_contextDeclarationExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CONTEXTDECLARATIONEXP_CLASS);
	
	
	
}

void ExpressionsPackageImpl::createDefExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_defExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, DEFEXP_CLASS);
	
	m_defExp_Attribute_bodyExp = factory->createEReference_as_eReferences_in_EClass(m_defExp_Class, DEFEXP_ATTRIBUTE_BODYEXP);
	m_defExp_Attribute_frontExp = factory->createEReference_as_eReferences_in_EClass(m_defExp_Class, DEFEXP_ATTRIBUTE_FRONTEXP);
	
	
}

void ExpressionsPackageImpl::createEnumLiteralExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_enumLiteralExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ENUMLITERALEXP_CLASS);
	m_enumLiteralExp_Attribute_referredEnumLiteralStr = factory->createEAttribute_as_eAttributes_in_EClass(m_enumLiteralExp_Class, ENUMLITERALEXP_ATTRIBUTE_REFERREDENUMLITERALSTR);
	
	m_enumLiteralExp_Attribute_referredEnumLiteral = factory->createEReference_as_eReferences_in_EClass(m_enumLiteralExp_Class, ENUMLITERALEXP_ATTRIBUTE_REFERREDENUMLITERAL);
	
	
}

void ExpressionsPackageImpl::createExpressionInOclContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_expressionInOcl_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EXPRESSIONINOCL_CLASS);
	
	m_expressionInOcl_Attribute_bodyExpression = factory->createEReference_as_eReferences_in_EClass(m_expressionInOcl_Class, EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION);
	m_expressionInOcl_Attribute_contextVariable = factory->createEReference_as_eReferences_in_EClass(m_expressionInOcl_Class, EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE);
	m_expressionInOcl_Attribute_parameterVariable = factory->createEReference_as_eReferences_in_EClass(m_expressionInOcl_Class, EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE);
	m_expressionInOcl_Attribute_resultVariable = factory->createEReference_as_eReferences_in_EClass(m_expressionInOcl_Class, EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE);
	
	
}

void ExpressionsPackageImpl::createFeatureCallExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_featureCallExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, FEATURECALLEXP_CLASS);
	m_featureCallExp_Attribute_isPre = factory->createEAttribute_as_eAttributes_in_EClass(m_featureCallExp_Class, FEATURECALLEXP_ATTRIBUTE_ISPRE);
	
	
	
}

void ExpressionsPackageImpl::createIfExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_ifExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, IFEXP_CLASS);
	
	m_ifExp_Attribute_condition = factory->createEReference_as_eReferences_in_EClass(m_ifExp_Class, IFEXP_ATTRIBUTE_CONDITION);
	m_ifExp_Attribute_elseExpression = factory->createEReference_as_eReferences_in_EClass(m_ifExp_Class, IFEXP_ATTRIBUTE_ELSEEXPRESSION);
	m_ifExp_Attribute_thenExpression = factory->createEReference_as_eReferences_in_EClass(m_ifExp_Class, IFEXP_ATTRIBUTE_THENEXPRESSION);
	
	
}

void ExpressionsPackageImpl::createInfixedExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_infixedExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INFIXEDEXP_CLASS);
	
	m_infixedExp_Attribute_source = factory->createEReference_as_eReferences_in_EClass(m_infixedExp_Class, INFIXEDEXP_ATTRIBUTE_SOURCE);
	
	
}

void ExpressionsPackageImpl::createInitOrDerValueExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_initOrDerValueExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INITORDERVALUEEXP_CLASS);
	m_initOrDerValueExp_Attribute_kind = factory->createEAttribute_as_eAttributes_in_EClass(m_initOrDerValueExp_Class, INITORDERVALUEEXP_ATTRIBUTE_KIND);
	
	m_initOrDerValueExp_Attribute_bodyExpression = factory->createEReference_as_eReferences_in_EClass(m_initOrDerValueExp_Class, INITORDERVALUEEXP_ATTRIBUTE_BODYEXPRESSION);
	
	
}

void ExpressionsPackageImpl::createInitOrDerValueListExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_initOrDerValueListExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INITORDERVALUELISTEXP_CLASS);
	
	m_initOrDerValueListExp_Attribute_derExpressionList = factory->createEReference_as_eReferences_in_EClass(m_initOrDerValueListExp_Class, INITORDERVALUELISTEXP_ATTRIBUTE_DEREXPRESSIONLIST);
	m_initOrDerValueListExp_Attribute_initExpressionList = factory->createEReference_as_eReferences_in_EClass(m_initOrDerValueListExp_Class, INITORDERVALUELISTEXP_ATTRIBUTE_INITEXPRESSIONLIST);
	
	
}

void ExpressionsPackageImpl::createIntegerLiteralExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_integerLiteralExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INTEGERLITERALEXP_CLASS);
	m_integerLiteralExp_Attribute_integerSymbol = factory->createEAttribute_as_eAttributes_in_EClass(m_integerLiteralExp_Class, INTEGERLITERALEXP_ATTRIBUTE_INTEGERSYMBOL);
	
	
	
}

void ExpressionsPackageImpl::createInvOrDefExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_invOrDefExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INVORDEFEXP_CLASS);
	m_invOrDefExp_Attribute_kind = factory->createEAttribute_as_eAttributes_in_EClass(m_invOrDefExp_Class, INVORDEFEXP_ATTRIBUTE_KIND);
	m_invOrDefExp_Attribute_name = factory->createEAttribute_as_eAttributes_in_EClass(m_invOrDefExp_Class, INVORDEFEXP_ATTRIBUTE_NAME);
	
	m_invOrDefExp_Attribute_referredExpression = factory->createEReference_as_eReferences_in_EClass(m_invOrDefExp_Class, INVORDEFEXP_ATTRIBUTE_REFERREDEXPRESSION);
	
	
}

void ExpressionsPackageImpl::createInvalidLiteralExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_invalidLiteralExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INVALIDLITERALEXP_CLASS);
	
	
	
}

void ExpressionsPackageImpl::createIterateExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_iterateExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ITERATEEXP_CLASS);
	
	m_iterateExp_Attribute_result = factory->createEReference_as_eReferences_in_EClass(m_iterateExp_Class, ITERATEEXP_ATTRIBUTE_RESULT);
	
	
}

void ExpressionsPackageImpl::createIteratorExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_iteratorExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ITERATOREXP_CLASS);
	m_iteratorExp_Attribute_sourrundedBy = factory->createEAttribute_as_eAttributes_in_EClass(m_iteratorExp_Class, ITERATOREXP_ATTRIBUTE_SOURRUNDEDBY);
	
	
	
}

void ExpressionsPackageImpl::createLetExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_letExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, LETEXP_CLASS);
	
	m_letExp_Attribute_in = factory->createEReference_as_eReferences_in_EClass(m_letExp_Class, LETEXP_ATTRIBUTE_IN);
	m_letExp_Attribute_variables = factory->createEReference_as_eReferences_in_EClass(m_letExp_Class, LETEXP_ATTRIBUTE_VARIABLES);
	
	
}

void ExpressionsPackageImpl::createLiteralExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_literalExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, LITERALEXP_CLASS);
	
	
	
}

void ExpressionsPackageImpl::createLoopExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_loopExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, LOOPEXP_CLASS);
	m_loopExp_Attribute_isCollectionOperation = factory->createEAttribute_as_eAttributes_in_EClass(m_loopExp_Class, LOOPEXP_ATTRIBUTE_ISCOLLECTIONOPERATION);
	m_loopExp_Attribute_isImplCollectIterator = factory->createEAttribute_as_eAttributes_in_EClass(m_loopExp_Class, LOOPEXP_ATTRIBUTE_ISIMPLCOLLECTITERATOR);
	m_loopExp_Attribute_iterName = factory->createEAttribute_as_eAttributes_in_EClass(m_loopExp_Class, LOOPEXP_ATTRIBUTE_ITERNAME);
	
	m_loopExp_Attribute_body = factory->createEReference_as_eReferences_in_EClass(m_loopExp_Class, LOOPEXP_ATTRIBUTE_BODY);
	m_loopExp_Attribute_iterator = factory->createEReference_as_eReferences_in_EClass(m_loopExp_Class, LOOPEXP_ATTRIBUTE_ITERATOR);
	
	
}

void ExpressionsPackageImpl::createMessageArgumentsContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_messageArguments_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, MESSAGEARGUMENTS_CLASS);
	
	m_messageArguments_Attribute_referredOclExpressions = factory->createEReference_as_eReferences_in_EClass(m_messageArguments_Class, MESSAGEARGUMENTS_ATTRIBUTE_REFERREDOCLEXPRESSIONS);
	
	
}

void ExpressionsPackageImpl::createMessageExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_messageExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, MESSAGEEXP_CLASS);
	m_messageExp_Attribute_calledOperation = factory->createEAttribute_as_eAttributes_in_EClass(m_messageExp_Class, MESSAGEEXP_ATTRIBUTE_CALLEDOPERATION);
	m_messageExp_Attribute_sentSignal = factory->createEAttribute_as_eAttributes_in_EClass(m_messageExp_Class, MESSAGEEXP_ATTRIBUTE_SENTSIGNAL);
	
	m_messageExp_Attribute_argument = factory->createEReference_as_eReferences_in_EClass(m_messageExp_Class, MESSAGEEXP_ATTRIBUTE_ARGUMENT);
	m_messageExp_Attribute_target = factory->createEReference_as_eReferences_in_EClass(m_messageExp_Class, MESSAGEEXP_ATTRIBUTE_TARGET);
	
	
}

void ExpressionsPackageImpl::createNavigationCallExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_navigationCallExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, NAVIGATIONCALLEXP_CLASS);
	m_navigationCallExp_Attribute_navigationSource = factory->createEAttribute_as_eAttributes_in_EClass(m_navigationCallExp_Class, NAVIGATIONCALLEXP_ATTRIBUTE_NAVIGATIONSOURCE);
	
	m_navigationCallExp_Attribute_qualifier = factory->createEReference_as_eReferences_in_EClass(m_navigationCallExp_Class, NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER);
	
	
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
	
	m_oclExpression_Attribute_appliedElement = factory->createEReference_as_eReferences_in_EClass(m_oclExpression_Class, OCLEXPRESSION_ATTRIBUTE_APPLIEDELEMENT);
	m_oclExpression_Attribute_elseOwner = factory->createEReference_as_eReferences_in_EClass(m_oclExpression_Class, OCLEXPRESSION_ATTRIBUTE_ELSEOWNER);
	m_oclExpression_Attribute_firstOwner = factory->createEReference_as_eReferences_in_EClass(m_oclExpression_Class, OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER);
	m_oclExpression_Attribute_ifOwner = factory->createEReference_as_eReferences_in_EClass(m_oclExpression_Class, OCLEXPRESSION_ATTRIBUTE_IFOWNER);
	m_oclExpression_Attribute_initializedElement = factory->createEReference_as_eReferences_in_EClass(m_oclExpression_Class, OCLEXPRESSION_ATTRIBUTE_INITIALIZEDELEMENT);
	m_oclExpression_Attribute_instance = factory->createEReference_as_eReferences_in_EClass(m_oclExpression_Class, OCLEXPRESSION_ATTRIBUTE_INSTANCE);
	m_oclExpression_Attribute_lastOwner = factory->createEReference_as_eReferences_in_EClass(m_oclExpression_Class, OCLEXPRESSION_ATTRIBUTE_LASTOWNER);
	m_oclExpression_Attribute_loopBodyOwner = factory->createEReference_as_eReferences_in_EClass(m_oclExpression_Class, OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER);
	m_oclExpression_Attribute_loopExp = factory->createEReference_as_eReferences_in_EClass(m_oclExpression_Class, OCLEXPRESSION_ATTRIBUTE_LOOPEXP);
	m_oclExpression_Attribute_parentCall = factory->createEReference_as_eReferences_in_EClass(m_oclExpression_Class, OCLEXPRESSION_ATTRIBUTE_PARENTCALL);
	m_oclExpression_Attribute_parentNav = factory->createEReference_as_eReferences_in_EClass(m_oclExpression_Class, OCLEXPRESSION_ATTRIBUTE_PARENTNAV);
	m_oclExpression_Attribute_thenOwner = factory->createEReference_as_eReferences_in_EClass(m_oclExpression_Class, OCLEXPRESSION_ATTRIBUTE_THENOWNER);
	m_oclExpression_Attribute_topExpression = factory->createEReference_as_eReferences_in_EClass(m_oclExpression_Class, OCLEXPRESSION_ATTRIBUTE_TOPEXPRESSION);
	
	
}

void ExpressionsPackageImpl::createOperationCallExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_operationCallExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, OPERATIONCALLEXP_CLASS);
	m_operationCallExp_Attribute_isRArrow = factory->createEAttribute_as_eAttributes_in_EClass(m_operationCallExp_Class, OPERATIONCALLEXP_ATTRIBUTE_ISRARROW);
	m_operationCallExp_Attribute_referredOperation = factory->createEAttribute_as_eAttributes_in_EClass(m_operationCallExp_Class, OPERATIONCALLEXP_ATTRIBUTE_REFERREDOPERATION);
	
	m_operationCallExp_Attribute_argument = factory->createEReference_as_eReferences_in_EClass(m_operationCallExp_Class, OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT);
	
	
}

void ExpressionsPackageImpl::createOperationContextDeclExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_operationContextDeclExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, OPERATIONCONTEXTDECLEXP_CLASS);
	
	m_operationContextDeclExp_Attribute_operationContext = factory->createEReference_as_eReferences_in_EClass(m_operationContextDeclExp_Class, OPERATIONCONTEXTDECLEXP_ATTRIBUTE_OPERATIONCONTEXT);
	m_operationContextDeclExp_Attribute_prePostBodyExpressions = factory->createEReference_as_eReferences_in_EClass(m_operationContextDeclExp_Class, OPERATIONCONTEXTDECLEXP_ATTRIBUTE_PREPOSTBODYEXPRESSIONS);
	
	
}

void ExpressionsPackageImpl::createOperationContextExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_operationContextExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, OPERATIONCONTEXTEXP_CLASS);
	m_operationContextExp_Attribute_operationName = factory->createEAttribute_as_eAttributes_in_EClass(m_operationContextExp_Class, OPERATIONCONTEXTEXP_ATTRIBUTE_OPERATIONNAME);
	
	m_operationContextExp_Attribute_inputParameters = factory->createEReference_as_eReferences_in_EClass(m_operationContextExp_Class, OPERATIONCONTEXTEXP_ATTRIBUTE_INPUTPARAMETERS);
	m_operationContextExp_Attribute_returnType = factory->createEReference_as_eReferences_in_EClass(m_operationContextExp_Class, OPERATIONCONTEXTEXP_ATTRIBUTE_RETURNTYPE);
	
	
}

void ExpressionsPackageImpl::createOperatorExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_operatorExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, OPERATOREXP_CLASS);
	m_operatorExp_Attribute_operator = factory->createEAttribute_as_eAttributes_in_EClass(m_operatorExp_Class, OPERATOREXP_ATTRIBUTE_OPERATOR);
	
	m_operatorExp_Attribute_leftHandOperand = factory->createEReference_as_eReferences_in_EClass(m_operatorExp_Class, OPERATOREXP_ATTRIBUTE_LEFTHANDOPERAND);
	m_operatorExp_Attribute_rightHandOperand = factory->createEReference_as_eReferences_in_EClass(m_operatorExp_Class, OPERATOREXP_ATTRIBUTE_RIGHTHANDOPERAND);
	
	
}

void ExpressionsPackageImpl::createPackageDeclarationExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_packageDeclarationExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PACKAGEDECLARATIONEXP_CLASS);
	m_packageDeclarationExp_Attribute_path = factory->createEAttribute_as_eAttributes_in_EClass(m_packageDeclarationExp_Class, PACKAGEDECLARATIONEXP_ATTRIBUTE_PATH);
	
	m_packageDeclarationExp_Attribute_contextDeclarations = factory->createEReference_as_eReferences_in_EClass(m_packageDeclarationExp_Class, PACKAGEDECLARATIONEXP_ATTRIBUTE_CONTEXTDECLARATIONS);
	
	
}

void ExpressionsPackageImpl::createParentedExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_parentedExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PARENTEDEXP_CLASS);
	
	m_parentedExp_Attribute_innerExp = factory->createEReference_as_eReferences_in_EClass(m_parentedExp_Class, PARENTEDEXP_ATTRIBUTE_INNEREXP);
	
	
}

void ExpressionsPackageImpl::createPrePostBodyExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_prePostBodyExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PREPOSTBODYEXP_CLASS);
	m_prePostBodyExp_Attribute_kind = factory->createEAttribute_as_eAttributes_in_EClass(m_prePostBodyExp_Class, PREPOSTBODYEXP_ATTRIBUTE_KIND);
	m_prePostBodyExp_Attribute_name = factory->createEAttribute_as_eAttributes_in_EClass(m_prePostBodyExp_Class, PREPOSTBODYEXP_ATTRIBUTE_NAME);
	
	m_prePostBodyExp_Attribute_bodyExpression = factory->createEReference_as_eReferences_in_EClass(m_prePostBodyExp_Class, PREPOSTBODYEXP_ATTRIBUTE_BODYEXPRESSION);
	
	
}

void ExpressionsPackageImpl::createPrePostBodyListExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_prePostBodyListExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PREPOSTBODYLISTEXP_CLASS);
	
	m_prePostBodyListExp_Attribute_bodyExpressionList = factory->createEReference_as_eReferences_in_EClass(m_prePostBodyListExp_Class, PREPOSTBODYLISTEXP_ATTRIBUTE_BODYEXPRESSIONLIST);
	m_prePostBodyListExp_Attribute_postExpressionList = factory->createEReference_as_eReferences_in_EClass(m_prePostBodyListExp_Class, PREPOSTBODYLISTEXP_ATTRIBUTE_POSTEXPRESSIONLIST);
	m_prePostBodyListExp_Attribute_preExpressionList = factory->createEReference_as_eReferences_in_EClass(m_prePostBodyListExp_Class, PREPOSTBODYLISTEXP_ATTRIBUTE_PREEXPRESSIONLIST);
	
	
}

void ExpressionsPackageImpl::createPrefixedExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_prefixedExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PREFIXEDEXP_CLASS);
	m_prefixedExp_Attribute_unarySymbol = factory->createEAttribute_as_eAttributes_in_EClass(m_prefixedExp_Class, PREFIXEDEXP_ATTRIBUTE_UNARYSYMBOL);
	
	m_prefixedExp_Attribute_referredExpression = factory->createEReference_as_eReferences_in_EClass(m_prefixedExp_Class, PREFIXEDEXP_ATTRIBUTE_REFERREDEXPRESSION);
	
	
}

void ExpressionsPackageImpl::createPrimitiveLiteralExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_primitiveLiteralExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PRIMITIVELITERALEXP_CLASS);
	m_primitiveLiteralExp_Attribute_symbol = factory->createEAttribute_as_eAttributes_in_EClass(m_primitiveLiteralExp_Class, PRIMITIVELITERALEXP_ATTRIBUTE_SYMBOL);
	
	
	
}

void ExpressionsPackageImpl::createPropertyCallExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_propertyCallExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PROPERTYCALLEXP_CLASS);
	m_propertyCallExp_Attribute_referredProperty = factory->createEAttribute_as_eAttributes_in_EClass(m_propertyCallExp_Class, PROPERTYCALLEXP_ATTRIBUTE_REFERREDPROPERTY);
	
	
	
}

void ExpressionsPackageImpl::createPropertyContextDeclExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_propertyContextDeclExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PROPERTYCONTEXTDECLEXP_CLASS);
	m_propertyContextDeclExp_Attribute_propName = factory->createEAttribute_as_eAttributes_in_EClass(m_propertyContextDeclExp_Class, PROPERTYCONTEXTDECLEXP_ATTRIBUTE_PROPNAME);
	
	m_propertyContextDeclExp_Attribute_initOrDerValues = factory->createEReference_as_eReferences_in_EClass(m_propertyContextDeclExp_Class, PROPERTYCONTEXTDECLEXP_ATTRIBUTE_INITORDERVALUES);
	m_propertyContextDeclExp_Attribute_propType = factory->createEReference_as_eReferences_in_EClass(m_propertyContextDeclExp_Class, PROPERTYCONTEXTDECLEXP_ATTRIBUTE_PROPTYPE);
	
	
}

void ExpressionsPackageImpl::createRealLiteralExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_realLiteralExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, REALLITERALEXP_CLASS);
	m_realLiteralExp_Attribute_realSymbol = factory->createEAttribute_as_eAttributes_in_EClass(m_realLiteralExp_Class, REALLITERALEXP_ATTRIBUTE_REALSYMBOL);
	
	
	
}

void ExpressionsPackageImpl::createStateExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_stateExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, STATEEXP_CLASS);
	
	m_stateExp_Attribute_referredState = factory->createEReference_as_eReferences_in_EClass(m_stateExp_Class, STATEEXP_ATTRIBUTE_REFERREDSTATE);
	
	
}

void ExpressionsPackageImpl::createStringLiteralExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_stringLiteralExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, STRINGLITERALEXP_CLASS);
	m_stringLiteralExp_Attribute_stringSymbol = factory->createEAttribute_as_eAttributes_in_EClass(m_stringLiteralExp_Class, STRINGLITERALEXP_ATTRIBUTE_STRINGSYMBOL);
	
	
	
}

void ExpressionsPackageImpl::createTupleLiteralExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_tupleLiteralExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, TUPLELITERALEXP_CLASS);
	
	m_tupleLiteralExp_Attribute_part = factory->createEReference_as_eReferences_in_EClass(m_tupleLiteralExp_Class, TUPLELITERALEXP_ATTRIBUTE_PART);
	
	
}

void ExpressionsPackageImpl::createTupleLiteralPartContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_tupleLiteralPart_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, TUPLELITERALPART_CLASS);
	m_tupleLiteralPart_Attribute_tuplePartName = factory->createEAttribute_as_eAttributes_in_EClass(m_tupleLiteralPart_Class, TUPLELITERALPART_ATTRIBUTE_TUPLEPARTNAME);
	m_tupleLiteralPart_Attribute_tuplePartType = factory->createEAttribute_as_eAttributes_in_EClass(m_tupleLiteralPart_Class, TUPLELITERALPART_ATTRIBUTE_TUPLEPARTTYPE);
	
	m_tupleLiteralPart_Attribute_assignedOclExpression = factory->createEReference_as_eReferences_in_EClass(m_tupleLiteralPart_Class, TUPLELITERALPART_ATTRIBUTE_ASSIGNEDOCLEXPRESSION);
	
	
}

void ExpressionsPackageImpl::createTupleTypeExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_tupleTypeExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, TUPLETYPEEXP_CLASS);
	
	m_tupleTypeExp_Attribute_part = factory->createEReference_as_eReferences_in_EClass(m_tupleTypeExp_Class, TUPLETYPEEXP_ATTRIBUTE_PART);
	
	
}

void ExpressionsPackageImpl::createTypeExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_typeExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, TYPEEXP_CLASS);
	m_typeExp_Attribute_referredType = factory->createEAttribute_as_eAttributes_in_EClass(m_typeExp_Class, TYPEEXP_ATTRIBUTE_REFERREDTYPE);
	
	
	
}

void ExpressionsPackageImpl::createUnlimitedNaturalExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_unlimitedNaturalExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, UNLIMITEDNATURALEXP_CLASS);
	m_unlimitedNaturalExp_Attribute_unlimitedNaturalSymbol = factory->createEAttribute_as_eAttributes_in_EClass(m_unlimitedNaturalExp_Class, UNLIMITEDNATURALEXP_ATTRIBUTE_UNLIMITEDNATURALSYMBOL);
	
	
	
}

void ExpressionsPackageImpl::createUnspecifiedValueExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_unspecifiedValueExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, UNSPECIFIEDVALUEEXP_CLASS);
	
	
	
}

void ExpressionsPackageImpl::createVarDeclarationExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_varDeclarationExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, VARDECLARATIONEXP_CLASS);
	m_varDeclarationExp_Attribute_varName = factory->createEAttribute_as_eAttributes_in_EClass(m_varDeclarationExp_Class, VARDECLARATIONEXP_ATTRIBUTE_VARNAME);
	
	m_varDeclarationExp_Attribute_assignedOclExp = factory->createEReference_as_eReferences_in_EClass(m_varDeclarationExp_Class, VARDECLARATIONEXP_ATTRIBUTE_ASSIGNEDOCLEXP);
	m_varDeclarationExp_Attribute_initExpression = factory->createEReference_as_eReferences_in_EClass(m_varDeclarationExp_Class, VARDECLARATIONEXP_ATTRIBUTE_INITEXPRESSION);
	m_varDeclarationExp_Attribute_varType = factory->createEReference_as_eReferences_in_EClass(m_varDeclarationExp_Class, VARDECLARATIONEXP_ATTRIBUTE_VARTYPE);
	
	
}

void ExpressionsPackageImpl::createVariableContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_variable_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, VARIABLE_CLASS);
	
	m_variable_Attribute_baseExp = factory->createEReference_as_eReferences_in_EClass(m_variable_Class, VARIABLE_ATTRIBUTE_BASEEXP);
	m_variable_Attribute_initExpression = factory->createEReference_as_eReferences_in_EClass(m_variable_Class, VARIABLE_ATTRIBUTE_INITEXPRESSION);
	m_variable_Attribute_loopExp = factory->createEReference_as_eReferences_in_EClass(m_variable_Class, VARIABLE_ATTRIBUTE_LOOPEXP);
	m_variable_Attribute_referringExp = factory->createEReference_as_eReferences_in_EClass(m_variable_Class, VARIABLE_ATTRIBUTE_REFERRINGEXP);
	m_variable_Attribute_representedParameter = factory->createEReference_as_eReferences_in_EClass(m_variable_Class, VARIABLE_ATTRIBUTE_REPRESENTEDPARAMETER);
	m_variable_Attribute_resultOwner = factory->createEReference_as_eReferences_in_EClass(m_variable_Class, VARIABLE_ATTRIBUTE_RESULTOWNER);
	m_variable_Attribute_selfOwner = factory->createEReference_as_eReferences_in_EClass(m_variable_Class, VARIABLE_ATTRIBUTE_SELFOWNER);
	m_variable_Attribute_value = factory->createEReference_as_eReferences_in_EClass(m_variable_Class, VARIABLE_ATTRIBUTE_VALUE);
	m_variable_Attribute_varOwner = factory->createEReference_as_eReferences_in_EClass(m_variable_Class, VARIABLE_ATTRIBUTE_VAROWNER);
	
	
}

void ExpressionsPackageImpl::createVariableExpContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_variableExp_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, VARIABLEEXP_CLASS);
	m_variableExp_Attribute_referredVariable = factory->createEAttribute_as_eAttributes_in_EClass(m_variableExp_Class, VARIABLEEXP_ATTRIBUTE_REFERREDVARIABLE);
	
	
	
}

void ExpressionsPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_collectionKind_Class = factory->createEEnum_as_eClassifiers_in_EPackage(package, COLLECTIONKIND_CLASS);
	m_prePostBody_Class = factory->createEEnum_as_eClassifiers_in_EPackage(package, PREPOSTBODY_CLASS);
	m_surroundingType_Class = factory->createEEnum_as_eClassifiers_in_EPackage(package, SURROUNDINGTYPE_CLASS);
	
}
