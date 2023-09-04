#include "ocl/Expressions/impl/ExpressionsPackageImpl.hpp"

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

//metamodel factory
#include "ocl/Expressions/ExpressionsFactory.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "ocl/oclPackage.hpp"

using namespace ocl::Expressions;

//Singleton implementation 
std::shared_ptr<ExpressionsPackage> ExpressionsPackage::eInstance()
{
	static std::shared_ptr<ExpressionsPackage> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(ExpressionsPackageImpl::create());
		std::dynamic_pointer_cast<ExpressionsPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
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
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getAssociationClassCallExp_Class() const
{
	return m_associationClassCallExp_Class;
}

const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getAssociationClassCallExp_Attribute_referredAssociationClass() const
{
	return m_associationClassCallExp_Attribute_referredAssociationClass;
}



// End Class AssociationClassCallExp

// Begin Class BooleanLiteralExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getBooleanLiteralExp_Class() const
{
	return m_booleanLiteralExp_Class;
}

const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getBooleanLiteralExp_Attribute_booleanSymbol() const
{
	return m_booleanLiteralExp_Attribute_booleanSymbol;
}



// End Class BooleanLiteralExp

// Begin Class CallExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getCallExp_Class() const
{
	return m_callExp_Class;
}


const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getCallExp_Attribute_source() const
{
	return m_callExp_Attribute_source;
}


// End Class CallExp

// Begin Class ClassifierContextDeclExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getClassifierContextDeclExp_Class() const
{
	return m_classifierContextDeclExp_Class;
}

const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getClassifierContextDeclExp_Attribute_classifierName() const
{
	return m_classifierContextDeclExp_Attribute_classifierName;
}

const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getClassifierContextDeclExp_Attribute_invOrDevExp() const
{
	return m_classifierContextDeclExp_Attribute_invOrDevExp;
}


// End Class ClassifierContextDeclExp

// Begin Class CollectionItem
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getCollectionItem_Class() const
{
	return m_collectionItem_Class;
}


const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getCollectionItem_Attribute_item() const
{
	return m_collectionItem_Attribute_item;
}


// End Class CollectionItem

// Begin Class CollectionLiteralExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getCollectionLiteralExp_Class() const
{
	return m_collectionLiteralExp_Class;
}

const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getCollectionLiteralExp_Attribute_kind() const
{
	return m_collectionLiteralExp_Attribute_kind;
}

const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getCollectionLiteralExp_Attribute_part() const
{
	return m_collectionLiteralExp_Attribute_part;
}


// End Class CollectionLiteralExp

// Begin Class CollectionLiteralPart
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getCollectionLiteralPart_Class() const
{
	return m_collectionLiteralPart_Class;
}




// End Class CollectionLiteralPart

// Begin Class CollectionLiteralParts
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getCollectionLiteralParts_Class() const
{
	return m_collectionLiteralParts_Class;
}


const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getCollectionLiteralParts_Attribute_literalParts() const
{
	return m_collectionLiteralParts_Attribute_literalParts;
}


// End Class CollectionLiteralParts

// Begin Class CollectionRange
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getCollectionRange_Class() const
{
	return m_collectionRange_Class;
}


const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getCollectionRange_Attribute_first() const
{
	return m_collectionRange_Attribute_first;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getCollectionRange_Attribute_last() const
{
	return m_collectionRange_Attribute_last;
}


// End Class CollectionRange

// Begin Class CollectionTypeExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getCollectionTypeExp_Class() const
{
	return m_collectionTypeExp_Class;
}


const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getCollectionTypeExp_Attribute_innerType() const
{
	return m_collectionTypeExp_Attribute_innerType;
}


// End Class CollectionTypeExp

// Begin Class ContextDeclarationExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getContextDeclarationExp_Class() const
{
	return m_contextDeclarationExp_Class;
}




// End Class ContextDeclarationExp

// Begin Class DefExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getDefExp_Class() const
{
	return m_defExp_Class;
}


const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getDefExp_Attribute_bodyExp() const
{
	return m_defExp_Attribute_bodyExp;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getDefExp_Attribute_frontExp() const
{
	return m_defExp_Attribute_frontExp;
}


// End Class DefExp

// Begin Class EnumLiteralExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getEnumLiteralExp_Class() const
{
	return m_enumLiteralExp_Class;
}

const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getEnumLiteralExp_Attribute_referredEnumLiteralStr() const
{
	return m_enumLiteralExp_Attribute_referredEnumLiteralStr;
}

const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getEnumLiteralExp_Attribute_referredEnumLiteral() const
{
	return m_enumLiteralExp_Attribute_referredEnumLiteral;
}


// End Class EnumLiteralExp

// Begin Class ExpressionInOcl
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getExpressionInOcl_Class() const
{
	return m_expressionInOcl_Class;
}


const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getExpressionInOcl_Attribute_bodyExpression() const
{
	return m_expressionInOcl_Attribute_bodyExpression;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getExpressionInOcl_Attribute_contextVariable() const
{
	return m_expressionInOcl_Attribute_contextVariable;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getExpressionInOcl_Attribute_parameterVariable() const
{
	return m_expressionInOcl_Attribute_parameterVariable;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getExpressionInOcl_Attribute_resultVariable() const
{
	return m_expressionInOcl_Attribute_resultVariable;
}


// End Class ExpressionInOcl

// Begin Class FeatureCallExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getFeatureCallExp_Class() const
{
	return m_featureCallExp_Class;
}

const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getFeatureCallExp_Attribute_isPre() const
{
	return m_featureCallExp_Attribute_isPre;
}



// End Class FeatureCallExp

// Begin Class IfExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getIfExp_Class() const
{
	return m_ifExp_Class;
}


const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getIfExp_Attribute_condition() const
{
	return m_ifExp_Attribute_condition;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getIfExp_Attribute_elseExpression() const
{
	return m_ifExp_Attribute_elseExpression;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getIfExp_Attribute_thenExpression() const
{
	return m_ifExp_Attribute_thenExpression;
}


// End Class IfExp

// Begin Class InfixedExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getInfixedExp_Class() const
{
	return m_infixedExp_Class;
}


const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getInfixedExp_Attribute_source() const
{
	return m_infixedExp_Attribute_source;
}


// End Class InfixedExp

// Begin Class InitOrDerValueExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getInitOrDerValueExp_Class() const
{
	return m_initOrDerValueExp_Class;
}

const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getInitOrDerValueExp_Attribute_kind() const
{
	return m_initOrDerValueExp_Attribute_kind;
}

const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getInitOrDerValueExp_Attribute_bodyExpression() const
{
	return m_initOrDerValueExp_Attribute_bodyExpression;
}


// End Class InitOrDerValueExp

// Begin Class InitOrDerValueListExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getInitOrDerValueListExp_Class() const
{
	return m_initOrDerValueListExp_Class;
}


const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getInitOrDerValueListExp_Attribute_derExpressionList() const
{
	return m_initOrDerValueListExp_Attribute_derExpressionList;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getInitOrDerValueListExp_Attribute_initExpressionList() const
{
	return m_initOrDerValueListExp_Attribute_initExpressionList;
}


// End Class InitOrDerValueListExp

// Begin Class IntegerLiteralExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getIntegerLiteralExp_Class() const
{
	return m_integerLiteralExp_Class;
}

const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getIntegerLiteralExp_Attribute_integerSymbol() const
{
	return m_integerLiteralExp_Attribute_integerSymbol;
}



// End Class IntegerLiteralExp

// Begin Class InvOrDefExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getInvOrDefExp_Class() const
{
	return m_invOrDefExp_Class;
}

const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getInvOrDefExp_Attribute_kind() const
{
	return m_invOrDefExp_Attribute_kind;
}
const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getInvOrDefExp_Attribute_name() const
{
	return m_invOrDefExp_Attribute_name;
}

const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getInvOrDefExp_Attribute_referredExpression() const
{
	return m_invOrDefExp_Attribute_referredExpression;
}


// End Class InvOrDefExp

// Begin Class InvalidLiteralExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getInvalidLiteralExp_Class() const
{
	return m_invalidLiteralExp_Class;
}




// End Class InvalidLiteralExp

// Begin Class IterateExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getIterateExp_Class() const
{
	return m_iterateExp_Class;
}


const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getIterateExp_Attribute_result() const
{
	return m_iterateExp_Attribute_result;
}


// End Class IterateExp

// Begin Class IteratorExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getIteratorExp_Class() const
{
	return m_iteratorExp_Class;
}

const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getIteratorExp_Attribute_sourrundedBy() const
{
	return m_iteratorExp_Attribute_sourrundedBy;
}



// End Class IteratorExp

// Begin Class LetExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getLetExp_Class() const
{
	return m_letExp_Class;
}


const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getLetExp_Attribute_in() const
{
	return m_letExp_Attribute_in;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getLetExp_Attribute_variables() const
{
	return m_letExp_Attribute_variables;
}


// End Class LetExp

// Begin Class LiteralExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getLiteralExp_Class() const
{
	return m_literalExp_Class;
}




// End Class LiteralExp

// Begin Class LoopExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getLoopExp_Class() const
{
	return m_loopExp_Class;
}

const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getLoopExp_Attribute_isCollectionOperation() const
{
	return m_loopExp_Attribute_isCollectionOperation;
}
const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getLoopExp_Attribute_isImplCollectIterator() const
{
	return m_loopExp_Attribute_isImplCollectIterator;
}
const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getLoopExp_Attribute_iterName() const
{
	return m_loopExp_Attribute_iterName;
}

const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getLoopExp_Attribute_body() const
{
	return m_loopExp_Attribute_body;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getLoopExp_Attribute_iterator() const
{
	return m_loopExp_Attribute_iterator;
}


// End Class LoopExp

// Begin Class MessageArguments
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getMessageArguments_Class() const
{
	return m_messageArguments_Class;
}


const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getMessageArguments_Attribute_referredOclExpressions() const
{
	return m_messageArguments_Attribute_referredOclExpressions;
}


// End Class MessageArguments

// Begin Class MessageExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getMessageExp_Class() const
{
	return m_messageExp_Class;
}

const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getMessageExp_Attribute_calledOperation() const
{
	return m_messageExp_Attribute_calledOperation;
}
const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getMessageExp_Attribute_sentSignal() const
{
	return m_messageExp_Attribute_sentSignal;
}

const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getMessageExp_Attribute_argument() const
{
	return m_messageExp_Attribute_argument;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getMessageExp_Attribute_target() const
{
	return m_messageExp_Attribute_target;
}


// End Class MessageExp

// Begin Class NavigationCallExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getNavigationCallExp_Class() const
{
	return m_navigationCallExp_Class;
}

const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getNavigationCallExp_Attribute_navigationSource() const
{
	return m_navigationCallExp_Attribute_navigationSource;
}

const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getNavigationCallExp_Attribute_qualifier() const
{
	return m_navigationCallExp_Attribute_qualifier;
}


// End Class NavigationCallExp

// Begin Class NullLiteralExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getNullLiteralExp_Class() const
{
	return m_nullLiteralExp_Class;
}




// End Class NullLiteralExp

// Begin Class NumericLiteralExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getNumericLiteralExp_Class() const
{
	return m_numericLiteralExp_Class;
}




// End Class NumericLiteralExp

// Begin Class OclExpression
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getOclExpression_Class() const
{
	return m_oclExpression_Class;
}


const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getOclExpression_Attribute_appliedElement() const
{
	return m_oclExpression_Attribute_appliedElement;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getOclExpression_Attribute_elseOwner() const
{
	return m_oclExpression_Attribute_elseOwner;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getOclExpression_Attribute_firstOwner() const
{
	return m_oclExpression_Attribute_firstOwner;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getOclExpression_Attribute_ifOwner() const
{
	return m_oclExpression_Attribute_ifOwner;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getOclExpression_Attribute_initializedElement() const
{
	return m_oclExpression_Attribute_initializedElement;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getOclExpression_Attribute_instance() const
{
	return m_oclExpression_Attribute_instance;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getOclExpression_Attribute_lastOwner() const
{
	return m_oclExpression_Attribute_lastOwner;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getOclExpression_Attribute_loopBodyOwner() const
{
	return m_oclExpression_Attribute_loopBodyOwner;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getOclExpression_Attribute_loopExp() const
{
	return m_oclExpression_Attribute_loopExp;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getOclExpression_Attribute_parentCall() const
{
	return m_oclExpression_Attribute_parentCall;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getOclExpression_Attribute_parentNav() const
{
	return m_oclExpression_Attribute_parentNav;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getOclExpression_Attribute_thenOwner() const
{
	return m_oclExpression_Attribute_thenOwner;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getOclExpression_Attribute_topExpression() const
{
	return m_oclExpression_Attribute_topExpression;
}


// End Class OclExpression

// Begin Class OperationCallExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getOperationCallExp_Class() const
{
	return m_operationCallExp_Class;
}

const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getOperationCallExp_Attribute_isRArrow() const
{
	return m_operationCallExp_Attribute_isRArrow;
}
const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getOperationCallExp_Attribute_referredOperation() const
{
	return m_operationCallExp_Attribute_referredOperation;
}

const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getOperationCallExp_Attribute_argument() const
{
	return m_operationCallExp_Attribute_argument;
}


// End Class OperationCallExp

// Begin Class OperationContextDeclExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getOperationContextDeclExp_Class() const
{
	return m_operationContextDeclExp_Class;
}


const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getOperationContextDeclExp_Attribute_operationContext() const
{
	return m_operationContextDeclExp_Attribute_operationContext;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getOperationContextDeclExp_Attribute_prePostBodyExpressions() const
{
	return m_operationContextDeclExp_Attribute_prePostBodyExpressions;
}


// End Class OperationContextDeclExp

// Begin Class OperationContextExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getOperationContextExp_Class() const
{
	return m_operationContextExp_Class;
}

const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getOperationContextExp_Attribute_operationName() const
{
	return m_operationContextExp_Attribute_operationName;
}

const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getOperationContextExp_Attribute_inputParameters() const
{
	return m_operationContextExp_Attribute_inputParameters;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getOperationContextExp_Attribute_returnType() const
{
	return m_operationContextExp_Attribute_returnType;
}


// End Class OperationContextExp

// Begin Class OperatorExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getOperatorExp_Class() const
{
	return m_operatorExp_Class;
}

const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getOperatorExp_Attribute_operator() const
{
	return m_operatorExp_Attribute_operator;
}

const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getOperatorExp_Attribute_leftHandOperand() const
{
	return m_operatorExp_Attribute_leftHandOperand;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getOperatorExp_Attribute_rightHandOperand() const
{
	return m_operatorExp_Attribute_rightHandOperand;
}


// End Class OperatorExp

// Begin Class PackageDeclarationExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getPackageDeclarationExp_Class() const
{
	return m_packageDeclarationExp_Class;
}

const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getPackageDeclarationExp_Attribute_path() const
{
	return m_packageDeclarationExp_Attribute_path;
}

const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getPackageDeclarationExp_Attribute_contextDeclarations() const
{
	return m_packageDeclarationExp_Attribute_contextDeclarations;
}


// End Class PackageDeclarationExp

// Begin Class ParentedExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getParentedExp_Class() const
{
	return m_parentedExp_Class;
}


const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getParentedExp_Attribute_innerExp() const
{
	return m_parentedExp_Attribute_innerExp;
}


// End Class ParentedExp

// Begin Class PrePostBodyExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getPrePostBodyExp_Class() const
{
	return m_prePostBodyExp_Class;
}

const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getPrePostBodyExp_Attribute_kind() const
{
	return m_prePostBodyExp_Attribute_kind;
}
const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getPrePostBodyExp_Attribute_name() const
{
	return m_prePostBodyExp_Attribute_name;
}

const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getPrePostBodyExp_Attribute_bodyExpression() const
{
	return m_prePostBodyExp_Attribute_bodyExpression;
}


// End Class PrePostBodyExp

// Begin Class PrePostBodyListExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getPrePostBodyListExp_Class() const
{
	return m_prePostBodyListExp_Class;
}


const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getPrePostBodyListExp_Attribute_bodyExpressionList() const
{
	return m_prePostBodyListExp_Attribute_bodyExpressionList;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getPrePostBodyListExp_Attribute_postExpressionList() const
{
	return m_prePostBodyListExp_Attribute_postExpressionList;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getPrePostBodyListExp_Attribute_preExpressionList() const
{
	return m_prePostBodyListExp_Attribute_preExpressionList;
}


// End Class PrePostBodyListExp

// Begin Class PrefixedExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getPrefixedExp_Class() const
{
	return m_prefixedExp_Class;
}

const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getPrefixedExp_Attribute_unarySymbol() const
{
	return m_prefixedExp_Attribute_unarySymbol;
}

const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getPrefixedExp_Attribute_referredExpression() const
{
	return m_prefixedExp_Attribute_referredExpression;
}


// End Class PrefixedExp

// Begin Class PrimitiveLiteralExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getPrimitiveLiteralExp_Class() const
{
	return m_primitiveLiteralExp_Class;
}

const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getPrimitiveLiteralExp_Attribute_symbol() const
{
	return m_primitiveLiteralExp_Attribute_symbol;
}



// End Class PrimitiveLiteralExp

// Begin Class PropertyCallExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getPropertyCallExp_Class() const
{
	return m_propertyCallExp_Class;
}

const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getPropertyCallExp_Attribute_referredProperty() const
{
	return m_propertyCallExp_Attribute_referredProperty;
}



// End Class PropertyCallExp

// Begin Class PropertyContextDeclExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getPropertyContextDeclExp_Class() const
{
	return m_propertyContextDeclExp_Class;
}

const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getPropertyContextDeclExp_Attribute_propName() const
{
	return m_propertyContextDeclExp_Attribute_propName;
}

const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getPropertyContextDeclExp_Attribute_initOrDerValues() const
{
	return m_propertyContextDeclExp_Attribute_initOrDerValues;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getPropertyContextDeclExp_Attribute_propType() const
{
	return m_propertyContextDeclExp_Attribute_propType;
}


// End Class PropertyContextDeclExp

// Begin Class RealLiteralExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getRealLiteralExp_Class() const
{
	return m_realLiteralExp_Class;
}

const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getRealLiteralExp_Attribute_realSymbol() const
{
	return m_realLiteralExp_Attribute_realSymbol;
}



// End Class RealLiteralExp

// Begin Class StateExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getStateExp_Class() const
{
	return m_stateExp_Class;
}


const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getStateExp_Attribute_referredState() const
{
	return m_stateExp_Attribute_referredState;
}


// End Class StateExp

// Begin Class StringLiteralExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getStringLiteralExp_Class() const
{
	return m_stringLiteralExp_Class;
}

const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getStringLiteralExp_Attribute_stringSymbol() const
{
	return m_stringLiteralExp_Attribute_stringSymbol;
}



// End Class StringLiteralExp

// Begin Class TupleLiteralExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getTupleLiteralExp_Class() const
{
	return m_tupleLiteralExp_Class;
}


const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getTupleLiteralExp_Attribute_part() const
{
	return m_tupleLiteralExp_Attribute_part;
}


// End Class TupleLiteralExp

// Begin Class TupleLiteralPart
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getTupleLiteralPart_Class() const
{
	return m_tupleLiteralPart_Class;
}

const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getTupleLiteralPart_Attribute_tuplePartName() const
{
	return m_tupleLiteralPart_Attribute_tuplePartName;
}
const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getTupleLiteralPart_Attribute_tuplePartType() const
{
	return m_tupleLiteralPart_Attribute_tuplePartType;
}

const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getTupleLiteralPart_Attribute_assignedOclExpression() const
{
	return m_tupleLiteralPart_Attribute_assignedOclExpression;
}


// End Class TupleLiteralPart

// Begin Class TupleTypeExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getTupleTypeExp_Class() const
{
	return m_tupleTypeExp_Class;
}


const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getTupleTypeExp_Attribute_part() const
{
	return m_tupleTypeExp_Attribute_part;
}


// End Class TupleTypeExp

// Begin Class TypeExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getTypeExp_Class() const
{
	return m_typeExp_Class;
}

const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getTypeExp_Attribute_referredType() const
{
	return m_typeExp_Attribute_referredType;
}



// End Class TypeExp

// Begin Class UnlimitedNaturalExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getUnlimitedNaturalExp_Class() const
{
	return m_unlimitedNaturalExp_Class;
}

const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getUnlimitedNaturalExp_Attribute_unlimitedNaturalSymbol() const
{
	return m_unlimitedNaturalExp_Attribute_unlimitedNaturalSymbol;
}



// End Class UnlimitedNaturalExp

// Begin Class UnspecifiedValueExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getUnspecifiedValueExp_Class() const
{
	return m_unspecifiedValueExp_Class;
}




// End Class UnspecifiedValueExp

// Begin Class VarDeclarationExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getVarDeclarationExp_Class() const
{
	return m_varDeclarationExp_Class;
}

const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getVarDeclarationExp_Attribute_varName() const
{
	return m_varDeclarationExp_Attribute_varName;
}

const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getVarDeclarationExp_Attribute_assignedOclExp() const
{
	return m_varDeclarationExp_Attribute_assignedOclExp;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getVarDeclarationExp_Attribute_initExpression() const
{
	return m_varDeclarationExp_Attribute_initExpression;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getVarDeclarationExp_Attribute_varType() const
{
	return m_varDeclarationExp_Attribute_varType;
}


// End Class VarDeclarationExp

// Begin Class Variable
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getVariable_Class() const
{
	return m_variable_Class;
}


const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getVariable_Attribute_baseExp() const
{
	return m_variable_Attribute_baseExp;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getVariable_Attribute_initExpression() const
{
	return m_variable_Attribute_initExpression;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getVariable_Attribute_loopExp() const
{
	return m_variable_Attribute_loopExp;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getVariable_Attribute_referringExp() const
{
	return m_variable_Attribute_referringExp;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getVariable_Attribute_representedParameter() const
{
	return m_variable_Attribute_representedParameter;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getVariable_Attribute_resultOwner() const
{
	return m_variable_Attribute_resultOwner;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getVariable_Attribute_selfOwner() const
{
	return m_variable_Attribute_selfOwner;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getVariable_Attribute_value() const
{
	return m_variable_Attribute_value;
}
const std::shared_ptr<ecore::EReference>& ocl::Expressions::ExpressionsPackageImpl::getVariable_Attribute_varOwner() const
{
	return m_variable_Attribute_varOwner;
}


// End Class Variable

// Begin Class VariableExp
const std::shared_ptr<ecore::EClass>& ocl::Expressions::ExpressionsPackageImpl::getVariableExp_Class() const
{
	return m_variableExp_Class;
}

const std::shared_ptr<ecore::EAttribute>& ocl::Expressions::ExpressionsPackageImpl::getVariableExp_Attribute_referredVariable() const
{
	return m_variableExp_Attribute_referredVariable;
}



// End Class VariableExp
const std::shared_ptr<ecore::EEnum>& ocl::Expressions::ExpressionsPackageImpl::getCollectionKind_Class() const
{
	return m_collectionKind_Class;
}
const std::shared_ptr<ecore::EEnum>& ocl::Expressions::ExpressionsPackageImpl::getPrePostBody_Class() const
{
	return m_prePostBody_Class;
}
const std::shared_ptr<ecore::EEnum>& ocl::Expressions::ExpressionsPackageImpl::getSurroundingType_Class() const
{
	return m_surroundingType_Class;
}

