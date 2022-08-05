#include "ocl/Expressions/impl/ExpressionsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EEnumLiteral.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EClass.hpp"

//metamodel factory
#include "ocl/Expressions/ExpressionsFactory.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "ocl/oclPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace ocl::Expressions;


//static initialisation
const std::string ExpressionsPackage::eNAME ="Expressions";
const std::string ExpressionsPackage::eNS_URI ="http://ocl4cpp/ocl/expressions.ecore";
const std::string ExpressionsPackage::eNS_PREFIX ="ocl.expressions";

bool ExpressionsPackageImpl::isInited = false;

ExpressionsPackageImpl::ExpressionsPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( ExpressionsFactory::eInstance()));
}

ExpressionsPackageImpl::~ExpressionsPackageImpl()
{
}

ExpressionsPackage* ExpressionsPackageImpl::create()
{
	if (isInited)
	{
		return ExpressionsPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    ExpressionsPackageImpl * metaModelPackage = new ExpressionsPackageImpl();
    return metaModelPackage;
}

void ExpressionsPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}



// Begin Class AssociationClassCallExp
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getAssociationClassCallExp_Class() const
{
	return m_associationClassCallExp_Class;
}


std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getAssociationClassCallExp_Attribute_referredAssociationClass() const
{
	return m_associationClassCallExp_Attribute_referredAssociationClass;
}


// End Class AssociationClassCallExp

// Begin Class BooleanLiteralExp
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getBooleanLiteralExp_Class() const
{
	return m_booleanLiteralExp_Class;
}

std::shared_ptr<ecore::EAttribute> ocl::Expressions::ExpressionsPackageImpl::getBooleanLiteralExp_Attribute_booleanSymbol() const
{
	return m_booleanLiteralExp_Attribute_booleanSymbol;
}



// End Class BooleanLiteralExp

// Begin Class CallExp
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getCallExp_Class() const
{
	return m_callExp_Class;
}


std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getCallExp_Attribute_source() const
{
	return m_callExp_Attribute_source;
}


// End Class CallExp

// Begin Class CollectionItem
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getCollectionItem_Class() const
{
	return m_collectionItem_Class;
}


std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getCollectionItem_Attribute_item() const
{
	return m_collectionItem_Attribute_item;
}


// End Class CollectionItem

// Begin Class CollectionLiteralExp
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getCollectionLiteralExp_Class() const
{
	return m_collectionLiteralExp_Class;
}

std::shared_ptr<ecore::EAttribute> ocl::Expressions::ExpressionsPackageImpl::getCollectionLiteralExp_Attribute_kind() const
{
	return m_collectionLiteralExp_Attribute_kind;
}

std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getCollectionLiteralExp_Attribute_part() const
{
	return m_collectionLiteralExp_Attribute_part;
}


// End Class CollectionLiteralExp

// Begin Class CollectionLiteralPart
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getCollectionLiteralPart_Class() const
{
	return m_collectionLiteralPart_Class;
}




// End Class CollectionLiteralPart

// Begin Class CollectionRange
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getCollectionRange_Class() const
{
	return m_collectionRange_Class;
}


std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getCollectionRange_Attribute_first() const
{
	return m_collectionRange_Attribute_first;
}
std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getCollectionRange_Attribute_last() const
{
	return m_collectionRange_Attribute_last;
}


// End Class CollectionRange

// Begin Class EnumLiteralExp
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getEnumLiteralExp_Class() const
{
	return m_enumLiteralExp_Class;
}


std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getEnumLiteralExp_Attribute_referredEnumLiteral() const
{
	return m_enumLiteralExp_Attribute_referredEnumLiteral;
}


// End Class EnumLiteralExp

// Begin Class ExpressionInOcl
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getExpressionInOcl_Class() const
{
	return m_expressionInOcl_Class;
}


std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getExpressionInOcl_Attribute_bodyExpression() const
{
	return m_expressionInOcl_Attribute_bodyExpression;
}
std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getExpressionInOcl_Attribute_contextVariable() const
{
	return m_expressionInOcl_Attribute_contextVariable;
}
std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getExpressionInOcl_Attribute_parameterVariable() const
{
	return m_expressionInOcl_Attribute_parameterVariable;
}
std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getExpressionInOcl_Attribute_resultVariable() const
{
	return m_expressionInOcl_Attribute_resultVariable;
}


// End Class ExpressionInOcl

// Begin Class FeatureCallExp
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getFeatureCallExp_Class() const
{
	return m_featureCallExp_Class;
}

std::shared_ptr<ecore::EAttribute> ocl::Expressions::ExpressionsPackageImpl::getFeatureCallExp_Attribute_isPre() const
{
	return m_featureCallExp_Attribute_isPre;
}



// End Class FeatureCallExp

// Begin Class IfExp
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getIfExp_Class() const
{
	return m_ifExp_Class;
}


std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getIfExp_Attribute_condition() const
{
	return m_ifExp_Attribute_condition;
}
std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getIfExp_Attribute_elseExpression() const
{
	return m_ifExp_Attribute_elseExpression;
}
std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getIfExp_Attribute_thenExpression() const
{
	return m_ifExp_Attribute_thenExpression;
}


// End Class IfExp

// Begin Class InfixedExp
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getInfixedExp_Class() const
{
	return m_infixedExp_Class;
}


std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getInfixedExp_Attribute_source() const
{
	return m_infixedExp_Attribute_source;
}


// End Class InfixedExp

// Begin Class IntegerLiteralExp
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getIntegerLiteralExp_Class() const
{
	return m_integerLiteralExp_Class;
}

std::shared_ptr<ecore::EAttribute> ocl::Expressions::ExpressionsPackageImpl::getIntegerLiteralExp_Attribute_integerSymbol() const
{
	return m_integerLiteralExp_Attribute_integerSymbol;
}



// End Class IntegerLiteralExp

// Begin Class InvalidLiteralExp
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getInvalidLiteralExp_Class() const
{
	return m_invalidLiteralExp_Class;
}




// End Class InvalidLiteralExp

// Begin Class IterateExp
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getIterateExp_Class() const
{
	return m_iterateExp_Class;
}


std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getIterateExp_Attribute_result() const
{
	return m_iterateExp_Attribute_result;
}


// End Class IterateExp

// Begin Class IteratorExp
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getIteratorExp_Class() const
{
	return m_iteratorExp_Class;
}




// End Class IteratorExp

// Begin Class LetExp
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getLetExp_Class() const
{
	return m_letExp_Class;
}


std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getLetExp_Attribute_in() const
{
	return m_letExp_Attribute_in;
}
std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getLetExp_Attribute_variable() const
{
	return m_letExp_Attribute_variable;
}


// End Class LetExp

// Begin Class LiteralExp
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getLiteralExp_Class() const
{
	return m_literalExp_Class;
}




// End Class LiteralExp

// Begin Class LoopExp
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getLoopExp_Class() const
{
	return m_loopExp_Class;
}


std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getLoopExp_Attribute_body() const
{
	return m_loopExp_Attribute_body;
}
std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getLoopExp_Attribute_iterator() const
{
	return m_loopExp_Attribute_iterator;
}


// End Class LoopExp

// Begin Class MessageExp
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getMessageExp_Class() const
{
	return m_messageExp_Class;
}


std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getMessageExp_Attribute_argument() const
{
	return m_messageExp_Attribute_argument;
}
std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getMessageExp_Attribute_calledOperation() const
{
	return m_messageExp_Attribute_calledOperation;
}
std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getMessageExp_Attribute_sentSignal() const
{
	return m_messageExp_Attribute_sentSignal;
}
std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getMessageExp_Attribute_target() const
{
	return m_messageExp_Attribute_target;
}


// End Class MessageExp

// Begin Class NavigationCallExp
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getNavigationCallExp_Class() const
{
	return m_navigationCallExp_Class;
}


std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getNavigationCallExp_Attribute_navigationSource() const
{
	return m_navigationCallExp_Attribute_navigationSource;
}
std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getNavigationCallExp_Attribute_qualifier() const
{
	return m_navigationCallExp_Attribute_qualifier;
}


// End Class NavigationCallExp

// Begin Class NullLiteralExp
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getNullLiteralExp_Class() const
{
	return m_nullLiteralExp_Class;
}




// End Class NullLiteralExp

// Begin Class NumericLiteralExp
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getNumericLiteralExp_Class() const
{
	return m_numericLiteralExp_Class;
}




// End Class NumericLiteralExp

// Begin Class OclExpression
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getOclExpression_Class() const
{
	return m_oclExpression_Class;
}


std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getOclExpression_Attribute_appliedElement() const
{
	return m_oclExpression_Attribute_appliedElement;
}
std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getOclExpression_Attribute_elseOwner() const
{
	return m_oclExpression_Attribute_elseOwner;
}
std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getOclExpression_Attribute_firstOwner() const
{
	return m_oclExpression_Attribute_firstOwner;
}
std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getOclExpression_Attribute_ifOwner() const
{
	return m_oclExpression_Attribute_ifOwner;
}
std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getOclExpression_Attribute_initializedElement() const
{
	return m_oclExpression_Attribute_initializedElement;
}
std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getOclExpression_Attribute_instance() const
{
	return m_oclExpression_Attribute_instance;
}
std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getOclExpression_Attribute_lastOwner() const
{
	return m_oclExpression_Attribute_lastOwner;
}
std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getOclExpression_Attribute_loopBodyOwner() const
{
	return m_oclExpression_Attribute_loopBodyOwner;
}
std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getOclExpression_Attribute_parentCall() const
{
	return m_oclExpression_Attribute_parentCall;
}
std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getOclExpression_Attribute_parentNav() const
{
	return m_oclExpression_Attribute_parentNav;
}
std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getOclExpression_Attribute_thenOwner() const
{
	return m_oclExpression_Attribute_thenOwner;
}
std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getOclExpression_Attribute_topExpression() const
{
	return m_oclExpression_Attribute_topExpression;
}


// End Class OclExpression

// Begin Class OperationCallExp
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getOperationCallExp_Class() const
{
	return m_operationCallExp_Class;
}


std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getOperationCallExp_Attribute_argument() const
{
	return m_operationCallExp_Attribute_argument;
}
std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getOperationCallExp_Attribute_referredOperation() const
{
	return m_operationCallExp_Attribute_referredOperation;
}


// End Class OperationCallExp

// Begin Class PrimitiveLiteralExp
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getPrimitiveLiteralExp_Class() const
{
	return m_primitiveLiteralExp_Class;
}

std::shared_ptr<ecore::EAttribute> ocl::Expressions::ExpressionsPackageImpl::getPrimitiveLiteralExp_Attribute_symbol() const
{
	return m_primitiveLiteralExp_Attribute_symbol;
}



// End Class PrimitiveLiteralExp

// Begin Class PropertyCallExp
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getPropertyCallExp_Class() const
{
	return m_propertyCallExp_Class;
}


std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getPropertyCallExp_Attribute_referredProperty() const
{
	return m_propertyCallExp_Attribute_referredProperty;
}


// End Class PropertyCallExp

// Begin Class RealLiteralExp
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getRealLiteralExp_Class() const
{
	return m_realLiteralExp_Class;
}

std::shared_ptr<ecore::EAttribute> ocl::Expressions::ExpressionsPackageImpl::getRealLiteralExp_Attribute_realSymbol() const
{
	return m_realLiteralExp_Attribute_realSymbol;
}



// End Class RealLiteralExp

// Begin Class StateExp
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getStateExp_Class() const
{
	return m_stateExp_Class;
}


std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getStateExp_Attribute_referredState() const
{
	return m_stateExp_Attribute_referredState;
}


// End Class StateExp

// Begin Class StringLiteralExp
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getStringLiteralExp_Class() const
{
	return m_stringLiteralExp_Class;
}

std::shared_ptr<ecore::EAttribute> ocl::Expressions::ExpressionsPackageImpl::getStringLiteralExp_Attribute_stringSymbol() const
{
	return m_stringLiteralExp_Attribute_stringSymbol;
}



// End Class StringLiteralExp

// Begin Class TupleLiteralExp
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getTupleLiteralExp_Class() const
{
	return m_tupleLiteralExp_Class;
}


std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getTupleLiteralExp_Attribute_part() const
{
	return m_tupleLiteralExp_Attribute_part;
}


// End Class TupleLiteralExp

// Begin Class TupleLiteralPart
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getTupleLiteralPart_Class() const
{
	return m_tupleLiteralPart_Class;
}


std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getTupleLiteralPart_Attribute_attribute() const
{
	return m_tupleLiteralPart_Attribute_attribute;
}


// End Class TupleLiteralPart

// Begin Class TypeExp
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getTypeExp_Class() const
{
	return m_typeExp_Class;
}


std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getTypeExp_Attribute_referredType() const
{
	return m_typeExp_Attribute_referredType;
}


// End Class TypeExp

// Begin Class UnlimitedNaturalExp
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getUnlimitedNaturalExp_Class() const
{
	return m_unlimitedNaturalExp_Class;
}

std::shared_ptr<ecore::EAttribute> ocl::Expressions::ExpressionsPackageImpl::getUnlimitedNaturalExp_Attribute_unlimitedNaturalSymbol() const
{
	return m_unlimitedNaturalExp_Attribute_unlimitedNaturalSymbol;
}



// End Class UnlimitedNaturalExp

// Begin Class UnspecifiedValueExp
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getUnspecifiedValueExp_Class() const
{
	return m_unspecifiedValueExp_Class;
}




// End Class UnspecifiedValueExp

// Begin Class Variable
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getVariable_Class() const
{
	return m_variable_Class;
}


std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getVariable_Attribute_baseExp() const
{
	return m_variable_Attribute_baseExp;
}
std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getVariable_Attribute_initExpression() const
{
	return m_variable_Attribute_initExpression;
}
std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getVariable_Attribute_loopExp() const
{
	return m_variable_Attribute_loopExp;
}
std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getVariable_Attribute_referringExp() const
{
	return m_variable_Attribute_referringExp;
}
std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getVariable_Attribute_representedParameter() const
{
	return m_variable_Attribute_representedParameter;
}
std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getVariable_Attribute_resultOwner() const
{
	return m_variable_Attribute_resultOwner;
}
std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getVariable_Attribute_selfOwner() const
{
	return m_variable_Attribute_selfOwner;
}
std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getVariable_Attribute_value() const
{
	return m_variable_Attribute_value;
}
std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getVariable_Attribute_varOwner() const
{
	return m_variable_Attribute_varOwner;
}


// End Class Variable

// Begin Class VariableExp
std::shared_ptr<ecore::EClass> ocl::Expressions::ExpressionsPackageImpl::getVariableExp_Class() const
{
	return m_variableExp_Class;
}


std::shared_ptr<ecore::EReference> ocl::Expressions::ExpressionsPackageImpl::getVariableExp_Attribute_referredVariable() const
{
	return m_variableExp_Attribute_referredVariable;
}


// End Class VariableExp
std::shared_ptr<ecore::EEnum> ocl::Expressions::ExpressionsPackageImpl::getCollectionKind_Class() const
{
	return m_collectionKind_Class;
}

