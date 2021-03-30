#include "ocl/Expressions/impl/ExpressionsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EEnumLiteral.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EReference.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "ocl/Evaluations/EvaluationsPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "ocl/oclPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"


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
	m_collectionItem_Class->getESuperTypes()->push_back(getCollectionLiteralPart_Class());
	m_collectionLiteralExp_Class->getESuperTypes()->push_back(getLiteralExp_Class());
	m_collectionLiteralPart_Class->getESuperTypes()->push_back(ecore::ecorePackage::eInstance()->getETypedElement_Class());
	m_collectionRange_Class->getESuperTypes()->push_back(getCollectionLiteralPart_Class());
	m_enumLiteralExp_Class->getESuperTypes()->push_back(getLiteralExp_Class());
	m_expressionInOcl_Class->getESuperTypes()->push_back(ecore::ecorePackage::eInstance()->getETypedElement_Class());
	m_featureCallExp_Class->getESuperTypes()->push_back(getCallExp_Class());
	m_ifExp_Class->getESuperTypes()->push_back(getOclExpression_Class());
	m_infixedExp_Class->getESuperTypes()->push_back(getOclExpression_Class());
	m_integerLiteralExp_Class->getESuperTypes()->push_back(getNumericLiteralExp_Class());
	m_invalidLiteralExp_Class->getESuperTypes()->push_back(getLiteralExp_Class());
	m_iterateExp_Class->getESuperTypes()->push_back(getLoopExp_Class());
	m_iteratorExp_Class->getESuperTypes()->push_back(getLoopExp_Class());
	m_letExp_Class->getESuperTypes()->push_back(getOclExpression_Class());
	m_literalExp_Class->getESuperTypes()->push_back(getOclExpression_Class());
	m_loopExp_Class->getESuperTypes()->push_back(getCallExp_Class());
	m_messageExp_Class->getESuperTypes()->push_back(getOclExpression_Class());
	m_navigationCallExp_Class->getESuperTypes()->push_back(getFeatureCallExp_Class());
	m_nullLiteralExp_Class->getESuperTypes()->push_back(getPrimitiveLiteralExp_Class());
	m_numericLiteralExp_Class->getESuperTypes()->push_back(getPrimitiveLiteralExp_Class());
	m_oclExpression_Class->getESuperTypes()->push_back(ecore::ecorePackage::eInstance()->getETypedElement_Class());
	m_operationCallExp_Class->getESuperTypes()->push_back(getFeatureCallExp_Class());
	m_primitiveLiteralExp_Class->getESuperTypes()->push_back(getLiteralExp_Class());
	m_propertyCallExp_Class->getESuperTypes()->push_back(getNavigationCallExp_Class());
	m_realLiteralExp_Class->getESuperTypes()->push_back(getNumericLiteralExp_Class());
	m_stateExp_Class->getESuperTypes()->push_back(getOclExpression_Class());
	m_stringLiteralExp_Class->getESuperTypes()->push_back(getPrimitiveLiteralExp_Class());
	m_tupleLiteralExp_Class->getESuperTypes()->push_back(getLiteralExp_Class());
	m_tupleLiteralPart_Class->getESuperTypes()->push_back(ecore::ecorePackage::eInstance()->getETypedElement_Class());
	m_typeExp_Class->getESuperTypes()->push_back(getOclExpression_Class());
	m_unlimitedNaturalExp_Class->getESuperTypes()->push_back(getNumericLiteralExp_Class());
	m_unspecifiedValueExp_Class->getESuperTypes()->push_back(getOclExpression_Class());
	m_variable_Class->getESuperTypes()->push_back(ecore::ecorePackage::eInstance()->getETypedElement_Class());
	m_variableExp_Class->getESuperTypes()->push_back(getOclExpression_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeAssociationClassCallExpContent();
	initializeBooleanLiteralExpContent();
	initializeCallExpContent();
	initializeCollectionItemContent();
	initializeCollectionLiteralExpContent();
	initializeCollectionLiteralPartContent();
	initializeCollectionRangeContent();
	initializeEnumLiteralExpContent();
	initializeExpressionInOclContent();
	initializeFeatureCallExpContent();
	initializeIfExpContent();
	initializeInfixedExpContent();
	initializeIntegerLiteralExpContent();
	initializeInvalidLiteralExpContent();
	initializeIterateExpContent();
	initializeIteratorExpContent();
	initializeLetExpContent();
	initializeLiteralExpContent();
	initializeLoopExpContent();
	initializeMessageExpContent();
	initializeNavigationCallExpContent();
	initializeNullLiteralExpContent();
	initializeNumericLiteralExpContent();
	initializeOclExpressionContent();
	initializeOperationCallExpContent();
	initializePrimitiveLiteralExpContent();
	initializePropertyCallExpContent();
	initializeRealLiteralExpContent();
	initializeStateExpContent();
	initializeStringLiteralExpContent();
	initializeTupleLiteralExpContent();
	initializeTupleLiteralPartContent();
	initializeTypeExpContent();
	initializeUnlimitedNaturalExpContent();
	initializeUnspecifiedValueExpContent();
	initializeVariableContent();
	initializeVariableExpContent();

	initializePackageEDataTypes();

}

void ExpressionsPackageImpl::initializeAssociationClassCallExpContent()
{
	m_associationClassCallExp_Class->setName("AssociationClassCallExp");
	m_associationClassCallExp_Class->setAbstract(false);
	m_associationClassCallExp_Class->setInterface(false);
	
	
	m_associationClassCallExp_Attribute_referredAssociationClass->setName("referredAssociationClass");
	m_associationClassCallExp_Attribute_referredAssociationClass->setEType(ecore::ecorePackage::eInstance()->getEReference_Class());
	m_associationClassCallExp_Attribute_referredAssociationClass->setLowerBound(0);
	m_associationClassCallExp_Attribute_referredAssociationClass->setUpperBound(1);
	m_associationClassCallExp_Attribute_referredAssociationClass->setTransient(false);
	m_associationClassCallExp_Attribute_referredAssociationClass->setVolatile(false);
	m_associationClassCallExp_Attribute_referredAssociationClass->setChangeable(true);
	m_associationClassCallExp_Attribute_referredAssociationClass->setUnsettable(false);
	m_associationClassCallExp_Attribute_referredAssociationClass->setUnique(true);
	m_associationClassCallExp_Attribute_referredAssociationClass->setDerived(false);
	m_associationClassCallExp_Attribute_referredAssociationClass->setOrdered(true);
	m_associationClassCallExp_Attribute_referredAssociationClass->setContainment(false);
	m_associationClassCallExp_Attribute_referredAssociationClass->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_associationClassCallExp_Attribute_referredAssociationClass->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	
}

void ExpressionsPackageImpl::initializeBooleanLiteralExpContent()
{
	m_booleanLiteralExp_Class->setName("BooleanLiteralExp");
	m_booleanLiteralExp_Class->setAbstract(false);
	m_booleanLiteralExp_Class->setInterface(false);
	
	m_booleanLiteralExp_Attribute_booleanSymbol = getBooleanLiteralExp_Attribute_booleanSymbol();
	m_booleanLiteralExp_Attribute_booleanSymbol->setName("booleanSymbol");
		m_booleanLiteralExp_Attribute_booleanSymbol->setEType(types::typesPackage::eInstance()->getBoolean_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_booleanLiteralExp_Attribute_booleanSymbol->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	
}

void ExpressionsPackageImpl::initializeCallExpContent()
{
	m_callExp_Class->setName("CallExp");
	m_callExp_Class->setAbstract(true);
	m_callExp_Class->setInterface(false);
	
	
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_callExp_Attribute_source->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Attribute_appliedElement();
		if (otherEnd != nullptr)
	    {
	   		m_callExp_Attribute_source->setEOpposite(otherEnd);
	    }
	}
	
	
}

void ExpressionsPackageImpl::initializeCollectionItemContent()
{
	m_collectionItem_Class->setName("CollectionItem");
	m_collectionItem_Class->setAbstract(false);
	m_collectionItem_Class->setInterface(false);
	
	
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_collectionItem_Attribute_item->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	
}

void ExpressionsPackageImpl::initializeCollectionLiteralExpContent()
{
	m_collectionLiteralExp_Class->setName("CollectionLiteralExp");
	m_collectionLiteralExp_Class->setAbstract(false);
	m_collectionLiteralExp_Class->setInterface(false);
	
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_collectionLiteralExp_Attribute_kind->setDefaultValueLiteral(defaultValue);
		}
	}
	
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_collectionLiteralExp_Attribute_part->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	
}

void ExpressionsPackageImpl::initializeCollectionLiteralPartContent()
{
	m_collectionLiteralPart_Class->setName("CollectionLiteralPart");
	m_collectionLiteralPart_Class->setAbstract(true);
	m_collectionLiteralPart_Class->setInterface(false);
	
	
	
	
}

void ExpressionsPackageImpl::initializeCollectionRangeContent()
{
	m_collectionRange_Class->setName("CollectionRange");
	m_collectionRange_Class->setAbstract(false);
	m_collectionRange_Class->setInterface(false);
	
	
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_collectionRange_Attribute_first->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Attribute_firstOwner();
		if (otherEnd != nullptr)
	    {
	   		m_collectionRange_Attribute_first->setEOpposite(otherEnd);
	    }
	}
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_collectionRange_Attribute_last->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Attribute_lastOwner();
		if (otherEnd != nullptr)
	    {
	   		m_collectionRange_Attribute_last->setEOpposite(otherEnd);
	    }
	}
	
	
}

void ExpressionsPackageImpl::initializeEnumLiteralExpContent()
{
	m_enumLiteralExp_Class->setName("EnumLiteralExp");
	m_enumLiteralExp_Class->setAbstract(false);
	m_enumLiteralExp_Class->setInterface(false);
	
	
	m_enumLiteralExp_Attribute_referredEnumLiteral->setName("referredEnumLiteral");
	m_enumLiteralExp_Attribute_referredEnumLiteral->setEType(uml::umlPackage::eInstance()->getEnumerationLiteral_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_enumLiteralExp_Attribute_referredEnumLiteral->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	
}

void ExpressionsPackageImpl::initializeExpressionInOclContent()
{
	m_expressionInOcl_Class->setName("ExpressionInOcl");
	m_expressionInOcl_Class->setAbstract(false);
	m_expressionInOcl_Class->setInterface(false);
	
	
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_expressionInOcl_Attribute_bodyExpression->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Attribute_topExpression();
		if (otherEnd != nullptr)
	    {
	   		m_expressionInOcl_Attribute_bodyExpression->setEOpposite(otherEnd);
	    }
	}
	m_expressionInOcl_Attribute_contextVariable->setName("contextVariable");
	m_expressionInOcl_Attribute_contextVariable->setEType(getVariable_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_expressionInOcl_Attribute_contextVariable->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Expressions::ExpressionsPackage::eInstance()->getVariable_Attribute_selfOwner();
		if (otherEnd != nullptr)
	    {
	   		m_expressionInOcl_Attribute_contextVariable->setEOpposite(otherEnd);
	    }
	}
	m_expressionInOcl_Attribute_parameterVariable->setName("parameterVariable");
	m_expressionInOcl_Attribute_parameterVariable->setEType(getVariable_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_expressionInOcl_Attribute_parameterVariable->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Expressions::ExpressionsPackage::eInstance()->getVariable_Attribute_varOwner();
		if (otherEnd != nullptr)
	    {
	   		m_expressionInOcl_Attribute_parameterVariable->setEOpposite(otherEnd);
	    }
	}
	m_expressionInOcl_Attribute_resultVariable->setName("resultVariable");
	m_expressionInOcl_Attribute_resultVariable->setEType(getVariable_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_expressionInOcl_Attribute_resultVariable->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Expressions::ExpressionsPackage::eInstance()->getVariable_Attribute_resultOwner();
		if (otherEnd != nullptr)
	    {
	   		m_expressionInOcl_Attribute_resultVariable->setEOpposite(otherEnd);
	    }
	}
	
	
}

void ExpressionsPackageImpl::initializeFeatureCallExpContent()
{
	m_featureCallExp_Class->setName("FeatureCallExp");
	m_featureCallExp_Class->setAbstract(true);
	m_featureCallExp_Class->setInterface(false);
	
	m_featureCallExp_Attribute_isPre = getFeatureCallExp_Attribute_isPre();
	m_featureCallExp_Attribute_isPre->setName("isPre");
		m_featureCallExp_Attribute_isPre->setEType(types::typesPackage::eInstance()->getBoolean_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_featureCallExp_Attribute_isPre->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	
}

void ExpressionsPackageImpl::initializeIfExpContent()
{
	m_ifExp_Class->setName("IfExp");
	m_ifExp_Class->setAbstract(false);
	m_ifExp_Class->setInterface(false);
	
	
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_ifExp_Attribute_condition->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Attribute_ifOwner();
		if (otherEnd != nullptr)
	    {
	   		m_ifExp_Attribute_condition->setEOpposite(otherEnd);
	    }
	}
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_ifExp_Attribute_elseExpression->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Attribute_elseOwner();
		if (otherEnd != nullptr)
	    {
	   		m_ifExp_Attribute_elseExpression->setEOpposite(otherEnd);
	    }
	}
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_ifExp_Attribute_thenExpression->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Attribute_thenOwner();
		if (otherEnd != nullptr)
	    {
	   		m_ifExp_Attribute_thenExpression->setEOpposite(otherEnd);
	    }
	}
	
	
}

void ExpressionsPackageImpl::initializeInfixedExpContent()
{
	m_infixedExp_Class->setName("InfixedExp");
	m_infixedExp_Class->setAbstract(false);
	m_infixedExp_Class->setInterface(false);
	
	
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_infixedExp_Attribute_source->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	
}

void ExpressionsPackageImpl::initializeIntegerLiteralExpContent()
{
	m_integerLiteralExp_Class->setName("IntegerLiteralExp");
	m_integerLiteralExp_Class->setAbstract(false);
	m_integerLiteralExp_Class->setInterface(false);
	
	m_integerLiteralExp_Attribute_integerSymbol = getIntegerLiteralExp_Attribute_integerSymbol();
	m_integerLiteralExp_Attribute_integerSymbol->setName("integerSymbol");
		m_integerLiteralExp_Attribute_integerSymbol->setEType(types::typesPackage::eInstance()->getInteger_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_integerLiteralExp_Attribute_integerSymbol->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	
}

void ExpressionsPackageImpl::initializeInvalidLiteralExpContent()
{
	m_invalidLiteralExp_Class->setName("InvalidLiteralExp");
	m_invalidLiteralExp_Class->setAbstract(false);
	m_invalidLiteralExp_Class->setInterface(false);
	
	
	
	
}

void ExpressionsPackageImpl::initializeIterateExpContent()
{
	m_iterateExp_Class->setName("IterateExp");
	m_iterateExp_Class->setAbstract(false);
	m_iterateExp_Class->setInterface(false);
	
	
	m_iterateExp_Attribute_result->setName("result");
	m_iterateExp_Attribute_result->setEType(getVariable_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_iterateExp_Attribute_result->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Expressions::ExpressionsPackage::eInstance()->getVariable_Attribute_baseExp();
		if (otherEnd != nullptr)
	    {
	   		m_iterateExp_Attribute_result->setEOpposite(otherEnd);
	    }
	}
	
	
}

void ExpressionsPackageImpl::initializeIteratorExpContent()
{
	m_iteratorExp_Class->setName("IteratorExp");
	m_iteratorExp_Class->setAbstract(false);
	m_iteratorExp_Class->setInterface(false);
	
	
	
	
}

void ExpressionsPackageImpl::initializeLetExpContent()
{
	m_letExp_Class->setName("LetExp");
	m_letExp_Class->setAbstract(false);
	m_letExp_Class->setInterface(false);
	
	
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_letExp_Attribute_in->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_letExp_Attribute_variable->setName("variable");
	m_letExp_Attribute_variable->setEType(getVariable_Class());
	m_letExp_Attribute_variable->setLowerBound(1);
	m_letExp_Attribute_variable->setUpperBound(1);
	m_letExp_Attribute_variable->setTransient(false);
	m_letExp_Attribute_variable->setVolatile(false);
	m_letExp_Attribute_variable->setChangeable(true);
	m_letExp_Attribute_variable->setUnsettable(false);
	m_letExp_Attribute_variable->setUnique(true);
	m_letExp_Attribute_variable->setDerived(false);
	m_letExp_Attribute_variable->setOrdered(false);
	m_letExp_Attribute_variable->setContainment(true);
	m_letExp_Attribute_variable->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_letExp_Attribute_variable->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	
}

void ExpressionsPackageImpl::initializeLiteralExpContent()
{
	m_literalExp_Class->setName("LiteralExp");
	m_literalExp_Class->setAbstract(true);
	m_literalExp_Class->setInterface(false);
	
	
	
	
}

void ExpressionsPackageImpl::initializeLoopExpContent()
{
	m_loopExp_Class->setName("LoopExp");
	m_loopExp_Class->setAbstract(true);
	m_loopExp_Class->setInterface(false);
	
	
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_loopExp_Attribute_body->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Attribute_loopBodyOwner();
		if (otherEnd != nullptr)
	    {
	   		m_loopExp_Attribute_body->setEOpposite(otherEnd);
	    }
	}
	m_loopExp_Attribute_iterator->setName("iterator");
	m_loopExp_Attribute_iterator->setEType(getVariable_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_loopExp_Attribute_iterator->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Expressions::ExpressionsPackage::eInstance()->getVariable_Attribute_loopExp();
		if (otherEnd != nullptr)
	    {
	   		m_loopExp_Attribute_iterator->setEOpposite(otherEnd);
	    }
	}
	
	
}

void ExpressionsPackageImpl::initializeMessageExpContent()
{
	m_messageExp_Class->setName("MessageExp");
	m_messageExp_Class->setAbstract(false);
	m_messageExp_Class->setInterface(false);
	
	
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_messageExp_Attribute_argument->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_messageExp_Attribute_calledOperation->setName("calledOperation");
	m_messageExp_Attribute_calledOperation->setEType(uml::umlPackage::eInstance()->getCallOperationAction_Class());
	m_messageExp_Attribute_calledOperation->setLowerBound(0);
	m_messageExp_Attribute_calledOperation->setUpperBound(1);
	m_messageExp_Attribute_calledOperation->setTransient(false);
	m_messageExp_Attribute_calledOperation->setVolatile(false);
	m_messageExp_Attribute_calledOperation->setChangeable(true);
	m_messageExp_Attribute_calledOperation->setUnsettable(false);
	m_messageExp_Attribute_calledOperation->setUnique(true);
	m_messageExp_Attribute_calledOperation->setDerived(false);
	m_messageExp_Attribute_calledOperation->setOrdered(true);
	m_messageExp_Attribute_calledOperation->setContainment(false);
	m_messageExp_Attribute_calledOperation->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_messageExp_Attribute_calledOperation->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_messageExp_Attribute_sentSignal->setName("sentSignal");
	m_messageExp_Attribute_sentSignal->setEType(uml::umlPackage::eInstance()->getSendSignalAction_Class());
	m_messageExp_Attribute_sentSignal->setLowerBound(0);
	m_messageExp_Attribute_sentSignal->setUpperBound(1);
	m_messageExp_Attribute_sentSignal->setTransient(false);
	m_messageExp_Attribute_sentSignal->setVolatile(false);
	m_messageExp_Attribute_sentSignal->setChangeable(true);
	m_messageExp_Attribute_sentSignal->setUnsettable(false);
	m_messageExp_Attribute_sentSignal->setUnique(true);
	m_messageExp_Attribute_sentSignal->setDerived(false);
	m_messageExp_Attribute_sentSignal->setOrdered(true);
	m_messageExp_Attribute_sentSignal->setContainment(false);
	m_messageExp_Attribute_sentSignal->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_messageExp_Attribute_sentSignal->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_messageExp_Attribute_target->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	
}

void ExpressionsPackageImpl::initializeNavigationCallExpContent()
{
	m_navigationCallExp_Class->setName("NavigationCallExp");
	m_navigationCallExp_Class->setAbstract(true);
	m_navigationCallExp_Class->setInterface(false);
	
	
	m_navigationCallExp_Attribute_navigationSource->setName("navigationSource");
	m_navigationCallExp_Attribute_navigationSource->setEType(ecore::ecorePackage::eInstance()->getEAttribute_Class());
	m_navigationCallExp_Attribute_navigationSource->setLowerBound(0);
	m_navigationCallExp_Attribute_navigationSource->setUpperBound(1);
	m_navigationCallExp_Attribute_navigationSource->setTransient(false);
	m_navigationCallExp_Attribute_navigationSource->setVolatile(false);
	m_navigationCallExp_Attribute_navigationSource->setChangeable(true);
	m_navigationCallExp_Attribute_navigationSource->setUnsettable(false);
	m_navigationCallExp_Attribute_navigationSource->setUnique(true);
	m_navigationCallExp_Attribute_navigationSource->setDerived(false);
	m_navigationCallExp_Attribute_navigationSource->setOrdered(true);
	m_navigationCallExp_Attribute_navigationSource->setContainment(false);
	m_navigationCallExp_Attribute_navigationSource->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_navigationCallExp_Attribute_navigationSource->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_navigationCallExp_Attribute_qualifier->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Attribute_parentNav();
		if (otherEnd != nullptr)
	    {
	   		m_navigationCallExp_Attribute_qualifier->setEOpposite(otherEnd);
	    }
	}
	
	
}

void ExpressionsPackageImpl::initializeNullLiteralExpContent()
{
	m_nullLiteralExp_Class->setName("NullLiteralExp");
	m_nullLiteralExp_Class->setAbstract(false);
	m_nullLiteralExp_Class->setInterface(false);
	
	
	
	
}

void ExpressionsPackageImpl::initializeNumericLiteralExpContent()
{
	m_numericLiteralExp_Class->setName("NumericLiteralExp");
	m_numericLiteralExp_Class->setAbstract(true);
	m_numericLiteralExp_Class->setInterface(false);
	
	
	
	
}

void ExpressionsPackageImpl::initializeOclExpressionContent()
{
	m_oclExpression_Class->setName("OclExpression");
	m_oclExpression_Class->setAbstract(true);
	m_oclExpression_Class->setInterface(false);
	
	
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_oclExpression_Attribute_appliedElement->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Expressions::ExpressionsPackage::eInstance()->getCallExp_Attribute_source();
		if (otherEnd != nullptr)
	    {
	   		m_oclExpression_Attribute_appliedElement->setEOpposite(otherEnd);
	    }
	}
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_oclExpression_Attribute_elseOwner->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Expressions::ExpressionsPackage::eInstance()->getIfExp_Attribute_elseExpression();
		if (otherEnd != nullptr)
	    {
	   		m_oclExpression_Attribute_elseOwner->setEOpposite(otherEnd);
	    }
	}
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_oclExpression_Attribute_firstOwner->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Expressions::ExpressionsPackage::eInstance()->getCollectionRange_Attribute_first();
		if (otherEnd != nullptr)
	    {
	   		m_oclExpression_Attribute_firstOwner->setEOpposite(otherEnd);
	    }
	}
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_oclExpression_Attribute_ifOwner->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Expressions::ExpressionsPackage::eInstance()->getIfExp_Attribute_condition();
		if (otherEnd != nullptr)
	    {
	   		m_oclExpression_Attribute_ifOwner->setEOpposite(otherEnd);
	    }
	}
	m_oclExpression_Attribute_initializedElement->setName("initializedElement");
	m_oclExpression_Attribute_initializedElement->setEType(getVariable_Class());
	m_oclExpression_Attribute_initializedElement->setLowerBound(0);
	m_oclExpression_Attribute_initializedElement->setUpperBound(1);
	m_oclExpression_Attribute_initializedElement->setTransient(false);
	m_oclExpression_Attribute_initializedElement->setVolatile(false);
	m_oclExpression_Attribute_initializedElement->setChangeable(true);
	m_oclExpression_Attribute_initializedElement->setUnsettable(false);
	m_oclExpression_Attribute_initializedElement->setUnique(true);
	m_oclExpression_Attribute_initializedElement->setDerived(false);
	m_oclExpression_Attribute_initializedElement->setOrdered(true);
	m_oclExpression_Attribute_initializedElement->setContainment(false);
	m_oclExpression_Attribute_initializedElement->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_oclExpression_Attribute_initializedElement->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Expressions::ExpressionsPackage::eInstance()->getVariable_Attribute_initExpression();
		if (otherEnd != nullptr)
	    {
	   		m_oclExpression_Attribute_initializedElement->setEOpposite(otherEnd);
	    }
	}
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_oclExpression_Attribute_instance->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Evaluations::EvaluationsPackage::eInstance()->getOclExpEval_Attribute_model();
		if (otherEnd != nullptr)
	    {
	   		m_oclExpression_Attribute_instance->setEOpposite(otherEnd);
	    }
	}
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_oclExpression_Attribute_lastOwner->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Expressions::ExpressionsPackage::eInstance()->getCollectionRange_Attribute_last();
		if (otherEnd != nullptr)
	    {
	   		m_oclExpression_Attribute_lastOwner->setEOpposite(otherEnd);
	    }
	}
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_oclExpression_Attribute_loopBodyOwner->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Expressions::ExpressionsPackage::eInstance()->getLoopExp_Attribute_body();
		if (otherEnd != nullptr)
	    {
	   		m_oclExpression_Attribute_loopBodyOwner->setEOpposite(otherEnd);
	    }
	}
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_oclExpression_Attribute_parentCall->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Expressions::ExpressionsPackage::eInstance()->getOperationCallExp_Attribute_argument();
		if (otherEnd != nullptr)
	    {
	   		m_oclExpression_Attribute_parentCall->setEOpposite(otherEnd);
	    }
	}
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_oclExpression_Attribute_parentNav->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Expressions::ExpressionsPackage::eInstance()->getNavigationCallExp_Attribute_qualifier();
		if (otherEnd != nullptr)
	    {
	   		m_oclExpression_Attribute_parentNav->setEOpposite(otherEnd);
	    }
	}
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_oclExpression_Attribute_thenOwner->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Expressions::ExpressionsPackage::eInstance()->getIfExp_Attribute_thenExpression();
		if (otherEnd != nullptr)
	    {
	   		m_oclExpression_Attribute_thenOwner->setEOpposite(otherEnd);
	    }
	}
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_oclExpression_Attribute_topExpression->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Expressions::ExpressionsPackage::eInstance()->getExpressionInOcl_Attribute_bodyExpression();
		if (otherEnd != nullptr)
	    {
	   		m_oclExpression_Attribute_topExpression->setEOpposite(otherEnd);
	    }
	}
	
	
}

void ExpressionsPackageImpl::initializeOperationCallExpContent()
{
	m_operationCallExp_Class->setName("OperationCallExp");
	m_operationCallExp_Class->setAbstract(false);
	m_operationCallExp_Class->setInterface(false);
	
	
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_operationCallExp_Attribute_argument->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Attribute_parentCall();
		if (otherEnd != nullptr)
	    {
	   		m_operationCallExp_Attribute_argument->setEOpposite(otherEnd);
	    }
	}
	m_operationCallExp_Attribute_referredOperation->setName("referredOperation");
	m_operationCallExp_Attribute_referredOperation->setEType(ecore::ecorePackage::eInstance()->getEOperation_Class());
	m_operationCallExp_Attribute_referredOperation->setLowerBound(0);
	m_operationCallExp_Attribute_referredOperation->setUpperBound(1);
	m_operationCallExp_Attribute_referredOperation->setTransient(false);
	m_operationCallExp_Attribute_referredOperation->setVolatile(false);
	m_operationCallExp_Attribute_referredOperation->setChangeable(true);
	m_operationCallExp_Attribute_referredOperation->setUnsettable(false);
	m_operationCallExp_Attribute_referredOperation->setUnique(true);
	m_operationCallExp_Attribute_referredOperation->setDerived(false);
	m_operationCallExp_Attribute_referredOperation->setOrdered(false);
	m_operationCallExp_Attribute_referredOperation->setContainment(false);
	m_operationCallExp_Attribute_referredOperation->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_operationCallExp_Attribute_referredOperation->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	
}

void ExpressionsPackageImpl::initializePrimitiveLiteralExpContent()
{
	m_primitiveLiteralExp_Class->setName("PrimitiveLiteralExp");
	m_primitiveLiteralExp_Class->setAbstract(true);
	m_primitiveLiteralExp_Class->setInterface(false);
	
	m_primitiveLiteralExp_Attribute_symbol = getPrimitiveLiteralExp_Attribute_symbol();
	m_primitiveLiteralExp_Attribute_symbol->setName("symbol");
		m_primitiveLiteralExp_Attribute_symbol->setEType(types::typesPackage::eInstance()->getString_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_primitiveLiteralExp_Attribute_symbol->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	
}

void ExpressionsPackageImpl::initializePropertyCallExpContent()
{
	m_propertyCallExp_Class->setName("PropertyCallExp");
	m_propertyCallExp_Class->setAbstract(false);
	m_propertyCallExp_Class->setInterface(false);
	
	
	m_propertyCallExp_Attribute_referredProperty->setName("referredProperty");
	m_propertyCallExp_Attribute_referredProperty->setEType(ecore::ecorePackage::eInstance()->getEAttribute_Class());
	m_propertyCallExp_Attribute_referredProperty->setLowerBound(0);
	m_propertyCallExp_Attribute_referredProperty->setUpperBound(1);
	m_propertyCallExp_Attribute_referredProperty->setTransient(false);
	m_propertyCallExp_Attribute_referredProperty->setVolatile(false);
	m_propertyCallExp_Attribute_referredProperty->setChangeable(true);
	m_propertyCallExp_Attribute_referredProperty->setUnsettable(false);
	m_propertyCallExp_Attribute_referredProperty->setUnique(true);
	m_propertyCallExp_Attribute_referredProperty->setDerived(false);
	m_propertyCallExp_Attribute_referredProperty->setOrdered(false);
	m_propertyCallExp_Attribute_referredProperty->setContainment(false);
	m_propertyCallExp_Attribute_referredProperty->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_propertyCallExp_Attribute_referredProperty->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	
}

void ExpressionsPackageImpl::initializeRealLiteralExpContent()
{
	m_realLiteralExp_Class->setName("RealLiteralExp");
	m_realLiteralExp_Class->setAbstract(false);
	m_realLiteralExp_Class->setInterface(false);
	
	m_realLiteralExp_Attribute_realSymbol = getRealLiteralExp_Attribute_realSymbol();
	m_realLiteralExp_Attribute_realSymbol->setName("realSymbol");
		m_realLiteralExp_Attribute_realSymbol->setEType(types::typesPackage::eInstance()->getInteger_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_realLiteralExp_Attribute_realSymbol->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	
}

void ExpressionsPackageImpl::initializeStateExpContent()
{
	m_stateExp_Class->setName("StateExp");
	m_stateExp_Class->setAbstract(false);
	m_stateExp_Class->setInterface(false);
	
	
	m_stateExp_Attribute_referredState->setName("referredState");
	m_stateExp_Attribute_referredState->setEType(uml::umlPackage::eInstance()->getState_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_stateExp_Attribute_referredState->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	
}

void ExpressionsPackageImpl::initializeStringLiteralExpContent()
{
	m_stringLiteralExp_Class->setName("StringLiteralExp");
	m_stringLiteralExp_Class->setAbstract(false);
	m_stringLiteralExp_Class->setInterface(false);
	
	m_stringLiteralExp_Attribute_stringSymbol = getStringLiteralExp_Attribute_stringSymbol();
	m_stringLiteralExp_Attribute_stringSymbol->setName("stringSymbol");
		m_stringLiteralExp_Attribute_stringSymbol->setEType(types::typesPackage::eInstance()->getString_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_stringLiteralExp_Attribute_stringSymbol->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	
}

void ExpressionsPackageImpl::initializeTupleLiteralExpContent()
{
	m_tupleLiteralExp_Class->setName("TupleLiteralExp");
	m_tupleLiteralExp_Class->setAbstract(false);
	m_tupleLiteralExp_Class->setInterface(false);
	
	
	m_tupleLiteralExp_Attribute_part->setName("part");
	m_tupleLiteralExp_Attribute_part->setEType(getTupleLiteralPart_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_tupleLiteralExp_Attribute_part->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	
}

void ExpressionsPackageImpl::initializeTupleLiteralPartContent()
{
	m_tupleLiteralPart_Class->setName("TupleLiteralPart");
	m_tupleLiteralPart_Class->setAbstract(false);
	m_tupleLiteralPart_Class->setInterface(false);
	
	
	m_tupleLiteralPart_Attribute_attribute->setName("attribute");
	m_tupleLiteralPart_Attribute_attribute->setEType(ecore::ecorePackage::eInstance()->getEAttribute_Class());
	m_tupleLiteralPart_Attribute_attribute->setLowerBound(0);
	m_tupleLiteralPart_Attribute_attribute->setUpperBound(1);
	m_tupleLiteralPart_Attribute_attribute->setTransient(false);
	m_tupleLiteralPart_Attribute_attribute->setVolatile(false);
	m_tupleLiteralPart_Attribute_attribute->setChangeable(true);
	m_tupleLiteralPart_Attribute_attribute->setUnsettable(false);
	m_tupleLiteralPart_Attribute_attribute->setUnique(true);
	m_tupleLiteralPart_Attribute_attribute->setDerived(false);
	m_tupleLiteralPart_Attribute_attribute->setOrdered(false);
	m_tupleLiteralPart_Attribute_attribute->setContainment(true);
	m_tupleLiteralPart_Attribute_attribute->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_tupleLiteralPart_Attribute_attribute->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	
}

void ExpressionsPackageImpl::initializeTypeExpContent()
{
	m_typeExp_Class->setName("TypeExp");
	m_typeExp_Class->setAbstract(false);
	m_typeExp_Class->setInterface(false);
	
	
	m_typeExp_Attribute_referredType->setName("referredType");
	m_typeExp_Attribute_referredType->setEType(ecore::ecorePackage::eInstance()->getEClassifier_Class());
	m_typeExp_Attribute_referredType->setLowerBound(0);
	m_typeExp_Attribute_referredType->setUpperBound(1);
	m_typeExp_Attribute_referredType->setTransient(false);
	m_typeExp_Attribute_referredType->setVolatile(false);
	m_typeExp_Attribute_referredType->setChangeable(true);
	m_typeExp_Attribute_referredType->setUnsettable(false);
	m_typeExp_Attribute_referredType->setUnique(true);
	m_typeExp_Attribute_referredType->setDerived(false);
	m_typeExp_Attribute_referredType->setOrdered(false);
	m_typeExp_Attribute_referredType->setContainment(false);
	m_typeExp_Attribute_referredType->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_typeExp_Attribute_referredType->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	
}

void ExpressionsPackageImpl::initializeUnlimitedNaturalExpContent()
{
	m_unlimitedNaturalExp_Class->setName("UnlimitedNaturalExp");
	m_unlimitedNaturalExp_Class->setAbstract(false);
	m_unlimitedNaturalExp_Class->setInterface(false);
	
	m_unlimitedNaturalExp_Attribute_unlimitedNaturalSymbol = getUnlimitedNaturalExp_Attribute_unlimitedNaturalSymbol();
	m_unlimitedNaturalExp_Attribute_unlimitedNaturalSymbol->setName("unlimitedNaturalSymbol");
		m_unlimitedNaturalExp_Attribute_unlimitedNaturalSymbol->setEType(types::typesPackage::eInstance()->getUnlimitedNatural_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_unlimitedNaturalExp_Attribute_unlimitedNaturalSymbol->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	
}

void ExpressionsPackageImpl::initializeUnspecifiedValueExpContent()
{
	m_unspecifiedValueExp_Class->setName("UnspecifiedValueExp");
	m_unspecifiedValueExp_Class->setAbstract(false);
	m_unspecifiedValueExp_Class->setInterface(false);
	
	
	
	
}

void ExpressionsPackageImpl::initializeVariableContent()
{
	m_variable_Class->setName("Variable");
	m_variable_Class->setAbstract(false);
	m_variable_Class->setInterface(false);
	
	
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_variable_Attribute_baseExp->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Expressions::ExpressionsPackage::eInstance()->getIterateExp_Attribute_result();
		if (otherEnd != nullptr)
	    {
	   		m_variable_Attribute_baseExp->setEOpposite(otherEnd);
	    }
	}
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_variable_Attribute_initExpression->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Attribute_initializedElement();
		if (otherEnd != nullptr)
	    {
	   		m_variable_Attribute_initExpression->setEOpposite(otherEnd);
	    }
	}
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_variable_Attribute_loopExp->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Expressions::ExpressionsPackage::eInstance()->getLoopExp_Attribute_iterator();
		if (otherEnd != nullptr)
	    {
	   		m_variable_Attribute_loopExp->setEOpposite(otherEnd);
	    }
	}
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_variable_Attribute_referringExp->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Expressions::ExpressionsPackage::eInstance()->getVariableExp_Attribute_referredVariable();
		if (otherEnd != nullptr)
	    {
	   		m_variable_Attribute_referringExp->setEOpposite(otherEnd);
	    }
	}
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_variable_Attribute_representedParameter->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_variable_Attribute_resultOwner->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Expressions::ExpressionsPackage::eInstance()->getExpressionInOcl_Attribute_resultVariable();
		if (otherEnd != nullptr)
	    {
	   		m_variable_Attribute_resultOwner->setEOpposite(otherEnd);
	    }
	}
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_variable_Attribute_selfOwner->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Expressions::ExpressionsPackage::eInstance()->getExpressionInOcl_Attribute_contextVariable();
		if (otherEnd != nullptr)
	    {
	   		m_variable_Attribute_selfOwner->setEOpposite(otherEnd);
	    }
	}
	m_variable_Attribute_value->setName("value");
	m_variable_Attribute_value->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_variable_Attribute_value->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_variable_Attribute_varOwner->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Expressions::ExpressionsPackage::eInstance()->getExpressionInOcl_Attribute_parameterVariable();
		if (otherEnd != nullptr)
	    {
	   		m_variable_Attribute_varOwner->setEOpposite(otherEnd);
	    }
	}
	
	
}

void ExpressionsPackageImpl::initializeVariableExpContent()
{
	m_variableExp_Class->setName("VariableExp");
	m_variableExp_Class->setAbstract(false);
	m_variableExp_Class->setInterface(false);
	
	
	m_variableExp_Attribute_referredVariable->setName("referredVariable");
	m_variableExp_Attribute_referredVariable->setEType(getVariable_Class());
	m_variableExp_Attribute_referredVariable->setLowerBound(0);
	m_variableExp_Attribute_referredVariable->setUpperBound(1);
	m_variableExp_Attribute_referredVariable->setTransient(false);
	m_variableExp_Attribute_referredVariable->setVolatile(false);
	m_variableExp_Attribute_referredVariable->setChangeable(true);
	m_variableExp_Attribute_referredVariable->setUnsettable(false);
	m_variableExp_Attribute_referredVariable->setUnique(true);
	m_variableExp_Attribute_referredVariable->setDerived(false);
	m_variableExp_Attribute_referredVariable->setOrdered(false);
	m_variableExp_Attribute_referredVariable->setContainment(false);
	m_variableExp_Attribute_referredVariable->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_variableExp_Attribute_referredVariable->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = ocl::Expressions::ExpressionsPackage::eInstance()->getVariable_Attribute_referringExp();
		if (otherEnd != nullptr)
	    {
	   		m_variableExp_Attribute_referredVariable->setEOpposite(otherEnd);
	    }
	}
	
	
}

void ExpressionsPackageImpl::initializePackageEDataTypes()
{
	m_collectionKind_Class->setName("CollectionKind");
	
}

