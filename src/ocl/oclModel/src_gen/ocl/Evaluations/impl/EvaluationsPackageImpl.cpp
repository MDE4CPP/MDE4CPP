#include "ocl/Evaluations/impl/EvaluationsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAnnotation.hpp"

//metamodel factory
#include "ocl/Evaluations/EvaluationsFactory.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "ocl/oclPackage.hpp"
#include "types/typesPackage.hpp"

using namespace ocl::Evaluations;

bool EvaluationsPackageImpl::isInited = false;

EvaluationsPackageImpl::EvaluationsPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( EvaluationsFactory::eInstance()));
}

EvaluationsPackageImpl::~EvaluationsPackageImpl()
{
}

EvaluationsPackage* EvaluationsPackageImpl::create()
{
	if (isInited)
	{
		return EvaluationsPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    EvaluationsPackageImpl * metaModelPackage = new EvaluationsPackageImpl();
    return metaModelPackage;
}

void EvaluationsPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}



// Begin Class AssociationClassCallExpEval
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getAssociationClassCallExpEval_Class() const
{
	return m_associationClassCallExpEval_Class;
}


std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getAssociationClassCallExpEval_Attribute_referredAssociationClass() const
{
	return m_associationClassCallExpEval_Attribute_referredAssociationClass;
}


// End Class AssociationClassCallExpEval

// Begin Class AssociationEndCallExpEval
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getAssociationEndCallExpEval_Class() const
{
	return m_associationEndCallExpEval_Class;
}


std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getAssociationEndCallExpEval_Attribute_referredAssociationEnd() const
{
	return m_associationEndCallExpEval_Attribute_referredAssociationEnd;
}


// End Class AssociationEndCallExpEval

// Begin Class AttributeCallExpEval
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getAttributeCallExpEval_Class() const
{
	return m_attributeCallExpEval_Class;
}


std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getAttributeCallExpEval_Attribute_referredAttribute() const
{
	return m_attributeCallExpEval_Attribute_referredAttribute;
}


// End Class AttributeCallExpEval

// Begin Class BooleanLiteralExpEval
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getBooleanLiteralExpEval_Class() const
{
	return m_booleanLiteralExpEval_Class;
}




// End Class BooleanLiteralExpEval

// Begin Class CollectionItemEval
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getCollectionItemEval_Class() const
{
	return m_collectionItemEval_Class;
}


std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getCollectionItemEval_Attribute_item() const
{
	return m_collectionItemEval_Attribute_item;
}


// End Class CollectionItemEval

// Begin Class CollectionLiteralExpEval
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getCollectionLiteralExpEval_Class() const
{
	return m_collectionLiteralExpEval_Class;
}


std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getCollectionLiteralExpEval_Attribute_parts() const
{
	return m_collectionLiteralExpEval_Attribute_parts;
}


// End Class CollectionLiteralExpEval

// Begin Class CollectionLiteralPartEval
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getCollectionLiteralPartEval_Class() const
{
	return m_collectionLiteralPartEval_Class;
}


std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getCollectionLiteralPartEval_Attribute_element() const
{
	return m_collectionLiteralPartEval_Attribute_element;
}


// End Class CollectionLiteralPartEval

// Begin Class CollectionRangeEval
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getCollectionRangeEval_Class() const
{
	return m_collectionRangeEval_Class;
}


std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getCollectionRangeEval_Attribute_first() const
{
	return m_collectionRangeEval_Attribute_first;
}
std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getCollectionRangeEval_Attribute_last() const
{
	return m_collectionRangeEval_Attribute_last;
}


// End Class CollectionRangeEval

// Begin Class EnumLiteralExpEval
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getEnumLiteralExpEval_Class() const
{
	return m_enumLiteralExpEval_Class;
}




// End Class EnumLiteralExpEval

// Begin Class EvalEnvironment
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getEvalEnvironment_Class() const
{
	return m_evalEnvironment_Class;
}


std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getEvalEnvironment_Attribute_bindings() const
{
	return m_evalEnvironment_Attribute_bindings;
}

std::shared_ptr<ecore::EOperation> ocl::Evaluations::EvaluationsPackageImpl::getEvalEnvironment_Operation_add_NameValueBinding() const
{
	return m_evalEnvironment_Operation_add_NameValueBinding;
}
std::shared_ptr<ecore::EOperation> ocl::Evaluations::EvaluationsPackageImpl::getEvalEnvironment_Operation_addAll_NameValueBinding() const
{
	return m_evalEnvironment_Operation_addAll_NameValueBinding;
}
std::shared_ptr<ecore::EOperation> ocl::Evaluations::EvaluationsPackageImpl::getEvalEnvironment_Operation_find_String() const
{
	return m_evalEnvironment_Operation_find_String;
}
std::shared_ptr<ecore::EOperation> ocl::Evaluations::EvaluationsPackageImpl::getEvalEnvironment_Operation_getValueOf_EString() const
{
	return m_evalEnvironment_Operation_getValueOf_EString;
}
std::shared_ptr<ecore::EOperation> ocl::Evaluations::EvaluationsPackageImpl::getEvalEnvironment_Operation_replace_NameValueBinding() const
{
	return m_evalEnvironment_Operation_replace_NameValueBinding;
}

// End Class EvalEnvironment

// Begin Class EvalNameSpace
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getEvalNameSpace_Class() const
{
	return m_evalNameSpace_Class;
}




// End Class EvalNameSpace

// Begin Class ExpressionInOclEval
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getExpressionInOclEval_Class() const
{
	return m_expressionInOclEval_Class;
}


std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getExpressionInOclEval_Attribute_context() const
{
	return m_expressionInOclEval_Attribute_context;
}
std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getExpressionInOclEval_Attribute_environment() const
{
	return m_expressionInOclEval_Attribute_environment;
}


// End Class ExpressionInOclEval

// Begin Class IfExpEval
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getIfExpEval_Class() const
{
	return m_ifExpEval_Class;
}


std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getIfExpEval_Attribute_condition() const
{
	return m_ifExpEval_Attribute_condition;
}
std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getIfExpEval_Attribute_elseExpression() const
{
	return m_ifExpEval_Attribute_elseExpression;
}
std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getIfExpEval_Attribute_thenExpression() const
{
	return m_ifExpEval_Attribute_thenExpression;
}


// End Class IfExpEval

// Begin Class IntegerLiteralExpEval
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getIntegerLiteralExpEval_Class() const
{
	return m_integerLiteralExpEval_Class;
}




// End Class IntegerLiteralExpEval

// Begin Class IterateExpEval
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getIterateExpEval_Class() const
{
	return m_iterateExpEval_Class;
}


std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getIterateExpEval_Attribute_result() const
{
	return m_iterateExpEval_Attribute_result;
}


// End Class IterateExpEval

// Begin Class IteratorExpEval
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getIteratorExpEval_Class() const
{
	return m_iteratorExpEval_Class;
}




// End Class IteratorExpEval

// Begin Class LetExpEval
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getLetExpEval_Class() const
{
	return m_letExpEval_Class;
}


std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getLetExpEval_Attribute_in() const
{
	return m_letExpEval_Attribute_in;
}
std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getLetExpEval_Attribute_initExpression() const
{
	return m_letExpEval_Attribute_initExpression;
}
std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getLetExpEval_Attribute_variable() const
{
	return m_letExpEval_Attribute_variable;
}


// End Class LetExpEval

// Begin Class LiteralExpEval
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getLiteralExpEval_Class() const
{
	return m_literalExpEval_Class;
}




// End Class LiteralExpEval

// Begin Class LoopExpEval
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getLoopExpEval_Class() const
{
	return m_loopExpEval_Class;
}


std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getLoopExpEval_Attribute_bodyEvals() const
{
	return m_loopExpEval_Attribute_bodyEvals;
}
std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getLoopExpEval_Attribute_iterators() const
{
	return m_loopExpEval_Attribute_iterators;
}


// End Class LoopExpEval

// Begin Class ModelPropertyCallExpEval
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getModelPropertyCallExpEval_Class() const
{
	return m_modelPropertyCallExpEval_Class;
}



std::shared_ptr<ecore::EOperation> ocl::Evaluations::EvaluationsPackageImpl::getModelPropertyCallExpEval_Operation_atPre() const
{
	return m_modelPropertyCallExpEval_Operation_atPre;
}

// End Class ModelPropertyCallExpEval

// Begin Class NavigationCallExpEval
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getNavigationCallExpEval_Class() const
{
	return m_navigationCallExpEval_Class;
}


std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getNavigationCallExpEval_Attribute_navigationSource() const
{
	return m_navigationCallExpEval_Attribute_navigationSource;
}
std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getNavigationCallExpEval_Attribute_qualifiers() const
{
	return m_navigationCallExpEval_Attribute_qualifiers;
}


// End Class NavigationCallExpEval

// Begin Class NumericLiteralExpEval
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getNumericLiteralExpEval_Class() const
{
	return m_numericLiteralExpEval_Class;
}




// End Class NumericLiteralExpEval

// Begin Class OclExpEval
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getOclExpEval_Class() const
{
	return m_oclExpEval_Class;
}


std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getOclExpEval_Attribute_beforeEnvironment() const
{
	return m_oclExpEval_Attribute_beforeEnvironment;
}
std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getOclExpEval_Attribute_environment() const
{
	return m_oclExpEval_Attribute_environment;
}
std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getOclExpEval_Attribute_model() const
{
	return m_oclExpEval_Attribute_model;
}
std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getOclExpEval_Attribute_resultValue() const
{
	return m_oclExpEval_Attribute_resultValue;
}


// End Class OclExpEval

// Begin Class OclMessageArgEval
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getOclMessageArgEval_Class() const
{
	return m_oclMessageArgEval_Class;
}


std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getOclMessageArgEval_Attribute_expression() const
{
	return m_oclMessageArgEval_Attribute_expression;
}
std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getOclMessageArgEval_Attribute_unspecified() const
{
	return m_oclMessageArgEval_Attribute_unspecified;
}
std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getOclMessageArgEval_Attribute_variable() const
{
	return m_oclMessageArgEval_Attribute_variable;
}


// End Class OclMessageArgEval

// Begin Class OclMessageExpEval
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getOclMessageExpEval_Class() const
{
	return m_oclMessageExpEval_Class;
}

std::shared_ptr<ecore::EAttribute> ocl::Evaluations::EvaluationsPackageImpl::getOclMessageExpEval_Attribute_name() const
{
	return m_oclMessageExpEval_Attribute_name;
}

std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getOclMessageExpEval_Attribute_arguments() const
{
	return m_oclMessageExpEval_Attribute_arguments;
}
std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getOclMessageExpEval_Attribute_target() const
{
	return m_oclMessageExpEval_Attribute_target;
}


// End Class OclMessageExpEval

// Begin Class OperationCallExpEval
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getOperationCallExpEval_Class() const
{
	return m_operationCallExpEval_Class;
}


std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getOperationCallExpEval_Attribute_arguments() const
{
	return m_operationCallExpEval_Attribute_arguments;
}
std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getOperationCallExpEval_Attribute_referredOperation() const
{
	return m_operationCallExpEval_Attribute_referredOperation;
}


// End Class OperationCallExpEval

// Begin Class PrimitiveLiteralExpEval
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getPrimitiveLiteralExpEval_Class() const
{
	return m_primitiveLiteralExpEval_Class;
}




// End Class PrimitiveLiteralExpEval

// Begin Class PropertyCallExpEval
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getPropertyCallExpEval_Class() const
{
	return m_propertyCallExpEval_Class;
}


std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getPropertyCallExpEval_Attribute_source() const
{
	return m_propertyCallExpEval_Attribute_source;
}


// End Class PropertyCallExpEval

// Begin Class RealLiteralExpEval
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getRealLiteralExpEval_Class() const
{
	return m_realLiteralExpEval_Class;
}




// End Class RealLiteralExpEval

// Begin Class StringLiteralExpEval
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getStringLiteralExpEval_Class() const
{
	return m_stringLiteralExpEval_Class;
}




// End Class StringLiteralExpEval

// Begin Class TupleLiteralExpEval
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getTupleLiteralExpEval_Class() const
{
	return m_tupleLiteralExpEval_Class;
}


std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getTupleLiteralExpEval_Attribute_tuplePart() const
{
	return m_tupleLiteralExpEval_Attribute_tuplePart;
}


// End Class TupleLiteralExpEval

// Begin Class TupleLiteralExpPartEval
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getTupleLiteralExpPartEval_Class() const
{
	return m_tupleLiteralExpPartEval_Class;
}




// End Class TupleLiteralExpPartEval

// Begin Class UnlimitedNaturalLiteralExpEval
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getUnlimitedNaturalLiteralExpEval_Class() const
{
	return m_unlimitedNaturalLiteralExpEval_Class;
}




// End Class UnlimitedNaturalLiteralExpEval

// Begin Class UnspecifiedValueExpEval
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getUnspecifiedValueExpEval_Class() const
{
	return m_unspecifiedValueExpEval_Class;
}




// End Class UnspecifiedValueExpEval

// Begin Class VariableDeclEval
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getVariableDeclEval_Class() const
{
	return m_variableDeclEval_Class;
}


std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getVariableDeclEval_Attribute_initExp() const
{
	return m_variableDeclEval_Attribute_initExp;
}
std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getVariableDeclEval_Attribute_name() const
{
	return m_variableDeclEval_Attribute_name;
}


// End Class VariableDeclEval

// Begin Class VariableExpEval
std::shared_ptr<ecore::EClass> ocl::Evaluations::EvaluationsPackageImpl::getVariableExpEval_Class() const
{
	return m_variableExpEval_Class;
}


std::shared_ptr<ecore::EReference> ocl::Evaluations::EvaluationsPackageImpl::getVariableExpEval_Attribute_referredVariable() const
{
	return m_variableExpEval_Attribute_referredVariable;
}


// End Class VariableExpEval

