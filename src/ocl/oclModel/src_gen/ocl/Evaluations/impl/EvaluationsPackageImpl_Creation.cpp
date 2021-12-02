#include "ocl/Evaluations/impl/EvaluationsPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

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

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "ocl/oclPackage.hpp"
#include "types/typesPackage.hpp"
//include subpackages 
 
using namespace ocl::Evaluations;

void EvaluationsPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();

	createAssociationClassCallExpEvalContent(package, factory);
	createAssociationEndCallExpEvalContent(package, factory);
	createAttributeCallExpEvalContent(package, factory);
	createBooleanLiteralExpEvalContent(package, factory);
	createCollectionItemEvalContent(package, factory);
	createCollectionLiteralExpEvalContent(package, factory);
	createCollectionLiteralPartEvalContent(package, factory);
	createCollectionRangeEvalContent(package, factory);
	createEnumLiteralExpEvalContent(package, factory);
	createEvalEnvironmentContent(package, factory);
	createEvalNameSpaceContent(package, factory);
	createExpressionInOclEvalContent(package, factory);
	createIfExpEvalContent(package, factory);
	createIntegerLiteralExpEvalContent(package, factory);
	createIterateExpEvalContent(package, factory);
	createIteratorExpEvalContent(package, factory);
	createLetExpEvalContent(package, factory);
	createLiteralExpEvalContent(package, factory);
	createLoopExpEvalContent(package, factory);
	createModelPropertyCallExpEvalContent(package, factory);
	createNavigationCallExpEvalContent(package, factory);
	createNumericLiteralExpEvalContent(package, factory);
	createOclExpEvalContent(package, factory);
	createOclMessageArgEvalContent(package, factory);
	createOclMessageExpEvalContent(package, factory);
	createOperationCallExpEvalContent(package, factory);
	createPrimitiveLiteralExpEvalContent(package, factory);
	createPropertyCallExpEvalContent(package, factory);
	createRealLiteralExpEvalContent(package, factory);
	createStringLiteralExpEvalContent(package, factory);
	createTupleLiteralExpEvalContent(package, factory);
	createTupleLiteralExpPartEvalContent(package, factory);
	createUnlimitedNaturalLiteralExpEvalContent(package, factory);
	createUnspecifiedValueExpEvalContent(package, factory);
	createVariableDeclEvalContent(package, factory);
	createVariableExpEvalContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void EvaluationsPackageImpl::createAssociationClassCallExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_associationClassCallExpEval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ASSOCIATIONCLASSCALLEXPEVAL_CLASS);
	
	m_associationClassCallExpEval_Attribute_referredAssociationClass = factory->createEReference_as_eReferences_in_EClass(m_associationClassCallExpEval_Class, ASSOCIATIONCLASSCALLEXPEVAL_ATTRIBUTE_REFERREDASSOCIATIONCLASS);
	
	
}

void EvaluationsPackageImpl::createAssociationEndCallExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_associationEndCallExpEval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ASSOCIATIONENDCALLEXPEVAL_CLASS);
	
	m_associationEndCallExpEval_Attribute_referredAssociationEnd = factory->createEReference_as_eReferences_in_EClass(m_associationEndCallExpEval_Class, ASSOCIATIONENDCALLEXPEVAL_ATTRIBUTE_REFERREDASSOCIATIONEND);
	
	
}

void EvaluationsPackageImpl::createAttributeCallExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_attributeCallExpEval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ATTRIBUTECALLEXPEVAL_CLASS);
	
	m_attributeCallExpEval_Attribute_referredAttribute = factory->createEReference_as_eReferences_in_EClass(m_attributeCallExpEval_Class, ATTRIBUTECALLEXPEVAL_ATTRIBUTE_REFERREDATTRIBUTE);
	
	
}

void EvaluationsPackageImpl::createBooleanLiteralExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_booleanLiteralExpEval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, BOOLEANLITERALEXPEVAL_CLASS);
	
	
	
}

void EvaluationsPackageImpl::createCollectionItemEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_collectionItemEval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, COLLECTIONITEMEVAL_CLASS);
	
	m_collectionItemEval_Attribute_item = factory->createEReference_as_eReferences_in_EClass(m_collectionItemEval_Class, COLLECTIONITEMEVAL_ATTRIBUTE_ITEM);
	
	
}

void EvaluationsPackageImpl::createCollectionLiteralExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_collectionLiteralExpEval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, COLLECTIONLITERALEXPEVAL_CLASS);
	
	m_collectionLiteralExpEval_Attribute_parts = factory->createEReference_as_eReferences_in_EClass(m_collectionLiteralExpEval_Class, COLLECTIONLITERALEXPEVAL_ATTRIBUTE_PARTS);
	
	
}

void EvaluationsPackageImpl::createCollectionLiteralPartEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_collectionLiteralPartEval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, COLLECTIONLITERALPARTEVAL_CLASS);
	
	m_collectionLiteralPartEval_Attribute_element = factory->createEReference_as_eReferences_in_EClass(m_collectionLiteralPartEval_Class, COLLECTIONLITERALPARTEVAL_ATTRIBUTE_ELEMENT);
	
	
}

void EvaluationsPackageImpl::createCollectionRangeEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_collectionRangeEval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, COLLECTIONRANGEEVAL_CLASS);
	
	m_collectionRangeEval_Attribute_first = factory->createEReference_as_eReferences_in_EClass(m_collectionRangeEval_Class, COLLECTIONRANGEEVAL_ATTRIBUTE_FIRST);
	m_collectionRangeEval_Attribute_last = factory->createEReference_as_eReferences_in_EClass(m_collectionRangeEval_Class, COLLECTIONRANGEEVAL_ATTRIBUTE_LAST);
	
	
}

void EvaluationsPackageImpl::createEnumLiteralExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_enumLiteralExpEval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ENUMLITERALEXPEVAL_CLASS);
	
	
	
}

void EvaluationsPackageImpl::createEvalEnvironmentContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_evalEnvironment_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EVALENVIRONMENT_CLASS);
	
	m_evalEnvironment_Attribute_bindings = factory->createEReference_as_eReferences_in_EClass(m_evalEnvironment_Class, EVALENVIRONMENT_ATTRIBUTE_BINDINGS);
	
	m_evalEnvironment_Operation_add_NameValueBinding = factory->createEOperation_as_eOperations_in_EClass(m_evalEnvironment_Class, EVALENVIRONMENT_OPERATION_ADD_NAMEVALUEBINDING);
	m_evalEnvironment_Operation_addAll_NameValueBinding = factory->createEOperation_as_eOperations_in_EClass(m_evalEnvironment_Class, EVALENVIRONMENT_OPERATION_ADDALL_NAMEVALUEBINDING);
	m_evalEnvironment_Operation_find_String = factory->createEOperation_as_eOperations_in_EClass(m_evalEnvironment_Class, EVALENVIRONMENT_OPERATION_FIND_STRING);
	m_evalEnvironment_Operation_getValueOf_EString = factory->createEOperation_as_eOperations_in_EClass(m_evalEnvironment_Class, EVALENVIRONMENT_OPERATION_GETVALUEOF_ESTRING);
	m_evalEnvironment_Operation_replace_NameValueBinding = factory->createEOperation_as_eOperations_in_EClass(m_evalEnvironment_Class, EVALENVIRONMENT_OPERATION_REPLACE_NAMEVALUEBINDING);
	
}

void EvaluationsPackageImpl::createEvalNameSpaceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_evalNameSpace_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EVALNAMESPACE_CLASS);
	
	
	
}

void EvaluationsPackageImpl::createExpressionInOclEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_expressionInOclEval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EXPRESSIONINOCLEVAL_CLASS);
	
	m_expressionInOclEval_Attribute_context = factory->createEReference_as_eReferences_in_EClass(m_expressionInOclEval_Class, EXPRESSIONINOCLEVAL_ATTRIBUTE_CONTEXT);
	m_expressionInOclEval_Attribute_environment = factory->createEReference_as_eReferences_in_EClass(m_expressionInOclEval_Class, EXPRESSIONINOCLEVAL_ATTRIBUTE_ENVIRONMENT);
	
	
}

void EvaluationsPackageImpl::createIfExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_ifExpEval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, IFEXPEVAL_CLASS);
	
	m_ifExpEval_Attribute_condition = factory->createEReference_as_eReferences_in_EClass(m_ifExpEval_Class, IFEXPEVAL_ATTRIBUTE_CONDITION);
	m_ifExpEval_Attribute_elseExpression = factory->createEReference_as_eReferences_in_EClass(m_ifExpEval_Class, IFEXPEVAL_ATTRIBUTE_ELSEEXPRESSION);
	m_ifExpEval_Attribute_thenExpression = factory->createEReference_as_eReferences_in_EClass(m_ifExpEval_Class, IFEXPEVAL_ATTRIBUTE_THENEXPRESSION);
	
	
}

void EvaluationsPackageImpl::createIntegerLiteralExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_integerLiteralExpEval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INTEGERLITERALEXPEVAL_CLASS);
	
	
	
}

void EvaluationsPackageImpl::createIterateExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_iterateExpEval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ITERATEEXPEVAL_CLASS);
	
	m_iterateExpEval_Attribute_result = factory->createEReference_as_eReferences_in_EClass(m_iterateExpEval_Class, ITERATEEXPEVAL_ATTRIBUTE_RESULT);
	
	
}

void EvaluationsPackageImpl::createIteratorExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_iteratorExpEval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ITERATOREXPEVAL_CLASS);
	
	
	
}

void EvaluationsPackageImpl::createLetExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_letExpEval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, LETEXPEVAL_CLASS);
	
	m_letExpEval_Attribute_in = factory->createEReference_as_eReferences_in_EClass(m_letExpEval_Class, LETEXPEVAL_ATTRIBUTE_IN);
	m_letExpEval_Attribute_initExpression = factory->createEReference_as_eReferences_in_EClass(m_letExpEval_Class, LETEXPEVAL_ATTRIBUTE_INITEXPRESSION);
	m_letExpEval_Attribute_variable = factory->createEReference_as_eReferences_in_EClass(m_letExpEval_Class, LETEXPEVAL_ATTRIBUTE_VARIABLE);
	
	
}

void EvaluationsPackageImpl::createLiteralExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_literalExpEval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, LITERALEXPEVAL_CLASS);
	
	
	
}

void EvaluationsPackageImpl::createLoopExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_loopExpEval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, LOOPEXPEVAL_CLASS);
	
	m_loopExpEval_Attribute_bodyEvals = factory->createEReference_as_eReferences_in_EClass(m_loopExpEval_Class, LOOPEXPEVAL_ATTRIBUTE_BODYEVALS);
	m_loopExpEval_Attribute_iterators = factory->createEReference_as_eReferences_in_EClass(m_loopExpEval_Class, LOOPEXPEVAL_ATTRIBUTE_ITERATORS);
	
	
}

void EvaluationsPackageImpl::createModelPropertyCallExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_modelPropertyCallExpEval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, MODELPROPERTYCALLEXPEVAL_CLASS);
	
	
	m_modelPropertyCallExpEval_Operation_atPre = factory->createEOperation_as_eOperations_in_EClass(m_modelPropertyCallExpEval_Class, MODELPROPERTYCALLEXPEVAL_OPERATION_ATPRE);
	
}

void EvaluationsPackageImpl::createNavigationCallExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_navigationCallExpEval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, NAVIGATIONCALLEXPEVAL_CLASS);
	
	m_navigationCallExpEval_Attribute_navigationSource = factory->createEReference_as_eReferences_in_EClass(m_navigationCallExpEval_Class, NAVIGATIONCALLEXPEVAL_ATTRIBUTE_NAVIGATIONSOURCE);
	m_navigationCallExpEval_Attribute_qualifiers = factory->createEReference_as_eReferences_in_EClass(m_navigationCallExpEval_Class, NAVIGATIONCALLEXPEVAL_ATTRIBUTE_QUALIFIERS);
	
	
}

void EvaluationsPackageImpl::createNumericLiteralExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_numericLiteralExpEval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, NUMERICLITERALEXPEVAL_CLASS);
	
	
	
}

void EvaluationsPackageImpl::createOclExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_oclExpEval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, OCLEXPEVAL_CLASS);
	
	m_oclExpEval_Attribute_beforeEnvironment = factory->createEReference_as_eReferences_in_EClass(m_oclExpEval_Class, OCLEXPEVAL_ATTRIBUTE_BEFOREENVIRONMENT);
	m_oclExpEval_Attribute_environment = factory->createEReference_as_eReferences_in_EClass(m_oclExpEval_Class, OCLEXPEVAL_ATTRIBUTE_ENVIRONMENT);
	m_oclExpEval_Attribute_model = factory->createEReference_as_eReferences_in_EClass(m_oclExpEval_Class, OCLEXPEVAL_ATTRIBUTE_MODEL);
	m_oclExpEval_Attribute_resultValue = factory->createEReference_as_eReferences_in_EClass(m_oclExpEval_Class, OCLEXPEVAL_ATTRIBUTE_RESULTVALUE);
	
	
}

void EvaluationsPackageImpl::createOclMessageArgEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_oclMessageArgEval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, OCLMESSAGEARGEVAL_CLASS);
	
	m_oclMessageArgEval_Attribute_expression = factory->createEReference_as_eReferences_in_EClass(m_oclMessageArgEval_Class, OCLMESSAGEARGEVAL_ATTRIBUTE_EXPRESSION);
	m_oclMessageArgEval_Attribute_unspecified = factory->createEReference_as_eReferences_in_EClass(m_oclMessageArgEval_Class, OCLMESSAGEARGEVAL_ATTRIBUTE_UNSPECIFIED);
	m_oclMessageArgEval_Attribute_variable = factory->createEReference_as_eReferences_in_EClass(m_oclMessageArgEval_Class, OCLMESSAGEARGEVAL_ATTRIBUTE_VARIABLE);
	
	
}

void EvaluationsPackageImpl::createOclMessageExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_oclMessageExpEval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, OCLMESSAGEEXPEVAL_CLASS);
	m_oclMessageExpEval_Attribute_name = factory->createEAttribute_as_eAttributes_in_EClass(m_oclMessageExpEval_Class, OCLMESSAGEEXPEVAL_ATTRIBUTE_NAME);
	
	m_oclMessageExpEval_Attribute_arguments = factory->createEReference_as_eReferences_in_EClass(m_oclMessageExpEval_Class, OCLMESSAGEEXPEVAL_ATTRIBUTE_ARGUMENTS);
	m_oclMessageExpEval_Attribute_target = factory->createEReference_as_eReferences_in_EClass(m_oclMessageExpEval_Class, OCLMESSAGEEXPEVAL_ATTRIBUTE_TARGET);
	
	
}

void EvaluationsPackageImpl::createOperationCallExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_operationCallExpEval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, OPERATIONCALLEXPEVAL_CLASS);
	
	m_operationCallExpEval_Attribute_arguments = factory->createEReference_as_eReferences_in_EClass(m_operationCallExpEval_Class, OPERATIONCALLEXPEVAL_ATTRIBUTE_ARGUMENTS);
	m_operationCallExpEval_Attribute_referredOperation = factory->createEReference_as_eReferences_in_EClass(m_operationCallExpEval_Class, OPERATIONCALLEXPEVAL_ATTRIBUTE_REFERREDOPERATION);
	
	
}

void EvaluationsPackageImpl::createPrimitiveLiteralExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_primitiveLiteralExpEval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PRIMITIVELITERALEXPEVAL_CLASS);
	
	
	
}

void EvaluationsPackageImpl::createPropertyCallExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_propertyCallExpEval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PROPERTYCALLEXPEVAL_CLASS);
	
	m_propertyCallExpEval_Attribute_source = factory->createEReference_as_eReferences_in_EClass(m_propertyCallExpEval_Class, PROPERTYCALLEXPEVAL_ATTRIBUTE_SOURCE);
	
	
}

void EvaluationsPackageImpl::createRealLiteralExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_realLiteralExpEval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, REALLITERALEXPEVAL_CLASS);
	
	
	
}

void EvaluationsPackageImpl::createStringLiteralExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_stringLiteralExpEval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, STRINGLITERALEXPEVAL_CLASS);
	
	
	
}

void EvaluationsPackageImpl::createTupleLiteralExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_tupleLiteralExpEval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, TUPLELITERALEXPEVAL_CLASS);
	
	m_tupleLiteralExpEval_Attribute_tuplePart = factory->createEReference_as_eReferences_in_EClass(m_tupleLiteralExpEval_Class, TUPLELITERALEXPEVAL_ATTRIBUTE_TUPLEPART);
	
	
}

void EvaluationsPackageImpl::createTupleLiteralExpPartEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_tupleLiteralExpPartEval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, TUPLELITERALEXPPARTEVAL_CLASS);
	
	
	
}

void EvaluationsPackageImpl::createUnlimitedNaturalLiteralExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_unlimitedNaturalLiteralExpEval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, UNLIMITEDNATURALLITERALEXPEVAL_CLASS);
	
	
	
}

void EvaluationsPackageImpl::createUnspecifiedValueExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_unspecifiedValueExpEval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, UNSPECIFIEDVALUEEXPEVAL_CLASS);
	
	
	
}

void EvaluationsPackageImpl::createVariableDeclEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_variableDeclEval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, VARIABLEDECLEVAL_CLASS);
	
	m_variableDeclEval_Attribute_initExp = factory->createEReference_as_eReferences_in_EClass(m_variableDeclEval_Class, VARIABLEDECLEVAL_ATTRIBUTE_INITEXP);
	m_variableDeclEval_Attribute_name = factory->createEReference_as_eReferences_in_EClass(m_variableDeclEval_Class, VARIABLEDECLEVAL_ATTRIBUTE_NAME);
	
	
}

void EvaluationsPackageImpl::createVariableExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_variableExpEval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, VARIABLEEXPEVAL_CLASS);
	
	m_variableExpEval_Attribute_referredVariable = factory->createEReference_as_eReferences_in_EClass(m_variableExpEval_Class, VARIABLEEXPEVAL_ATTRIBUTE_REFERREDVARIABLE);
	
	
}

void EvaluationsPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}
