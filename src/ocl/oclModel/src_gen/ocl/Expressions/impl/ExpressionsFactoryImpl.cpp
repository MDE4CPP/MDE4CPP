#include "ocl/Expressions/impl/ExpressionsFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "ocl/Expressions/impl/AssociationClassCallExpImpl.hpp"
#include "ocl/Expressions/impl/BooleanLiteralExpImpl.hpp"
#include "ocl/Expressions/impl/CallExpImpl.hpp"
#include "ocl/Expressions/impl/ClassifierContextDeclExpImpl.hpp"
#include "ocl/Expressions/impl/CollectionItemImpl.hpp"
#include "ocl/Expressions/impl/CollectionLiteralExpImpl.hpp"
#include "ocl/Expressions/impl/CollectionLiteralPartImpl.hpp"
#include "ocl/Expressions/impl/CollectionLiteralPartsImpl.hpp"
#include "ocl/Expressions/impl/CollectionRangeImpl.hpp"
#include "ocl/Expressions/impl/CollectionTypeExpImpl.hpp"
#include "ocl/Expressions/impl/ContextDeclarationExpImpl.hpp"
#include "ocl/Expressions/impl/DefExpImpl.hpp"
#include "ocl/Expressions/impl/EnumLiteralExpImpl.hpp"
#include "ocl/Expressions/impl/ExpressionInOclImpl.hpp"
#include "ocl/Expressions/impl/FeatureCallExpImpl.hpp"
#include "ocl/Expressions/impl/IfExpImpl.hpp"
#include "ocl/Expressions/impl/InfixedExpImpl.hpp"
#include "ocl/Expressions/impl/InitOrDerValueExpImpl.hpp"
#include "ocl/Expressions/impl/InitOrDerValueListExpImpl.hpp"
#include "ocl/Expressions/impl/IntegerLiteralExpImpl.hpp"
#include "ocl/Expressions/impl/InvOrDefExpImpl.hpp"
#include "ocl/Expressions/impl/InvalidLiteralExpImpl.hpp"
#include "ocl/Expressions/impl/IterateExpImpl.hpp"
#include "ocl/Expressions/impl/IteratorExpImpl.hpp"
#include "ocl/Expressions/impl/LetExpImpl.hpp"
#include "ocl/Expressions/impl/LiteralExpImpl.hpp"
#include "ocl/Expressions/impl/LoopExpImpl.hpp"
#include "ocl/Expressions/impl/MessageArgumentsImpl.hpp"
#include "ocl/Expressions/impl/MessageExpImpl.hpp"
#include "ocl/Expressions/impl/NavigationCallExpImpl.hpp"
#include "ocl/Expressions/impl/NullLiteralExpImpl.hpp"
#include "ocl/Expressions/impl/NumericLiteralExpImpl.hpp"
#include "ocl/Expressions/impl/OclExpressionImpl.hpp"
#include "ocl/Expressions/impl/OperationCallExpImpl.hpp"
#include "ocl/Expressions/impl/OperationContextDeclExpImpl.hpp"
#include "ocl/Expressions/impl/OperationContextExpImpl.hpp"
#include "ocl/Expressions/impl/OperatorExpImpl.hpp"
#include "ocl/Expressions/impl/PackageDeclarationExpImpl.hpp"
#include "ocl/Expressions/impl/ParentedExpImpl.hpp"
#include "ocl/Expressions/impl/PrePostBodyExpImpl.hpp"
#include "ocl/Expressions/impl/PrePostBodyListExpImpl.hpp"
#include "ocl/Expressions/impl/PrefixedExpImpl.hpp"
#include "ocl/Expressions/impl/PrimitiveLiteralExpImpl.hpp"
#include "ocl/Expressions/impl/PropertyCallExpImpl.hpp"
#include "ocl/Expressions/impl/PropertyContextDeclExpImpl.hpp"
#include "ocl/Expressions/impl/RealLiteralExpImpl.hpp"
#include "ocl/Expressions/impl/StateExpImpl.hpp"
#include "ocl/Expressions/impl/StringLiteralExpImpl.hpp"
#include "ocl/Expressions/impl/TupleLiteralExpImpl.hpp"
#include "ocl/Expressions/impl/TupleLiteralPartImpl.hpp"
#include "ocl/Expressions/impl/TupleTypeExpImpl.hpp"
#include "ocl/Expressions/impl/TypeExpImpl.hpp"
#include "ocl/Expressions/impl/UnlimitedNaturalExpImpl.hpp"
#include "ocl/Expressions/impl/UnspecifiedValueExpImpl.hpp"
#include "ocl/Expressions/impl/VarDeclarationExpImpl.hpp"
#include "ocl/Expressions/impl/VariableImpl.hpp"
#include "ocl/Expressions/impl/VariableExpImpl.hpp"



using namespace ocl::Expressions;

std::shared_ptr<ExpressionsFactory> ExpressionsFactory::eInstance()
{
	static std::shared_ptr<ExpressionsFactory> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(ExpressionsFactoryImpl::create());
	}	
	return instance;
}

//*********************************
// Constructor / Destructor
//*********************************

ExpressionsFactoryImpl::ExpressionsFactoryImpl()
{
	m_idMap.insert(std::make_pair("ocl::Expressions::AssociationClassCallExp", ExpressionsPackage::ASSOCIATIONCLASSCALLEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::BooleanLiteralExp", ExpressionsPackage::BOOLEANLITERALEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::ClassifierContextDeclExp", ExpressionsPackage::CLASSIFIERCONTEXTDECLEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::CollectionItem", ExpressionsPackage::COLLECTIONITEM_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::CollectionLiteralExp", ExpressionsPackage::COLLECTIONLITERALEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::CollectionLiteralParts", ExpressionsPackage::COLLECTIONLITERALPARTS_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::CollectionRange", ExpressionsPackage::COLLECTIONRANGE_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::CollectionTypeExp", ExpressionsPackage::COLLECTIONTYPEEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::DefExp", ExpressionsPackage::DEFEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::EnumLiteralExp", ExpressionsPackage::ENUMLITERALEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::ExpressionInOcl", ExpressionsPackage::EXPRESSIONINOCL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::IfExp", ExpressionsPackage::IFEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::InfixedExp", ExpressionsPackage::INFIXEDEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::InitOrDerValueExp", ExpressionsPackage::INITORDERVALUEEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::InitOrDerValueListExp", ExpressionsPackage::INITORDERVALUELISTEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::IntegerLiteralExp", ExpressionsPackage::INTEGERLITERALEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::InvOrDefExp", ExpressionsPackage::INVORDEFEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::InvalidLiteralExp", ExpressionsPackage::INVALIDLITERALEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::IterateExp", ExpressionsPackage::ITERATEEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::IteratorExp", ExpressionsPackage::ITERATOREXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::LetExp", ExpressionsPackage::LETEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::MessageArguments", ExpressionsPackage::MESSAGEARGUMENTS_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::MessageExp", ExpressionsPackage::MESSAGEEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::NullLiteralExp", ExpressionsPackage::NULLLITERALEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::OperationCallExp", ExpressionsPackage::OPERATIONCALLEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::OperationContextDeclExp", ExpressionsPackage::OPERATIONCONTEXTDECLEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::OperationContextExp", ExpressionsPackage::OPERATIONCONTEXTEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::OperatorExp", ExpressionsPackage::OPERATOREXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::PackageDeclarationExp", ExpressionsPackage::PACKAGEDECLARATIONEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::ParentedExp", ExpressionsPackage::PARENTEDEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::PrePostBodyExp", ExpressionsPackage::PREPOSTBODYEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::PrePostBodyListExp", ExpressionsPackage::PREPOSTBODYLISTEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::PrefixedExp", ExpressionsPackage::PREFIXEDEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::PropertyCallExp", ExpressionsPackage::PROPERTYCALLEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::PropertyContextDeclExp", ExpressionsPackage::PROPERTYCONTEXTDECLEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::RealLiteralExp", ExpressionsPackage::REALLITERALEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::StateExp", ExpressionsPackage::STATEEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::StringLiteralExp", ExpressionsPackage::STRINGLITERALEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::TupleLiteralExp", ExpressionsPackage::TUPLELITERALEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::TupleLiteralPart", ExpressionsPackage::TUPLELITERALPART_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::TupleTypeExp", ExpressionsPackage::TUPLETYPEEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::TypeExp", ExpressionsPackage::TYPEEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::UnlimitedNaturalExp", ExpressionsPackage::UNLIMITEDNATURALEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::UnspecifiedValueExp", ExpressionsPackage::UNSPECIFIEDVALUEEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::VarDeclarationExp", ExpressionsPackage::VARDECLARATIONEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::Variable", ExpressionsPackage::VARIABLE_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::VariableExp", ExpressionsPackage::VARIABLEEXP_CLASS));
}

ExpressionsFactoryImpl::~ExpressionsFactoryImpl()
{
}

ExpressionsFactory* ExpressionsFactoryImpl::create()
{
	return new ExpressionsFactoryImpl();
}

//*********************************
// creators
//*********************************

std::shared_ptr<ecore::EObject> ExpressionsFactoryImpl::create(const int metaElementID, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	switch(metaElementID)
	{
		case ExpressionsPackage::ASSOCIATIONCLASSCALLEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createAssociationClassCallExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//AssociationClassCallExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createAssociationClassCallExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createAssociationClassCallExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createAssociationClassCallExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createAssociationClassCallExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createAssociationClassCallExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createAssociationClassCallExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createAssociationClassCallExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createAssociationClassCallExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createAssociationClassCallExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createAssociationClassCallExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createAssociationClassCallExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createAssociationClassCallExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createAssociationClassCallExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createAssociationClassCallExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createAssociationClassCallExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createAssociationClassCallExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createAssociationClassCallExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createAssociationClassCallExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::BOOLEANLITERALEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createBooleanLiteralExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//BooleanLiteralExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createBooleanLiteralExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createBooleanLiteralExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createBooleanLiteralExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createBooleanLiteralExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createBooleanLiteralExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createBooleanLiteralExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createBooleanLiteralExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createBooleanLiteralExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createBooleanLiteralExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createBooleanLiteralExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createBooleanLiteralExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createBooleanLiteralExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createBooleanLiteralExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createBooleanLiteralExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createBooleanLiteralExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createBooleanLiteralExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createBooleanLiteralExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createBooleanLiteralExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::CLASSIFIERCONTEXTDECLEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createClassifierContextDeclExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ClassifierContextDeclExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createClassifierContextDeclExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//ClassifierContextDeclExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createClassifierContextDeclExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//ClassifierContextDeclExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createClassifierContextDeclExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//ClassifierContextDeclExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createClassifierContextDeclExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//ClassifierContextDeclExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createClassifierContextDeclExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//ClassifierContextDeclExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createClassifierContextDeclExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//ClassifierContextDeclExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createClassifierContextDeclExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//ClassifierContextDeclExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createClassifierContextDeclExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//ClassifierContextDeclExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createClassifierContextDeclExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//ClassifierContextDeclExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createClassifierContextDeclExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//ClassifierContextDeclExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createClassifierContextDeclExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//ClassifierContextDeclExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createClassifierContextDeclExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//ClassifierContextDeclExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createClassifierContextDeclExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//ClassifierContextDeclExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createClassifierContextDeclExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//ClassifierContextDeclExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createClassifierContextDeclExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//ClassifierContextDeclExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createClassifierContextDeclExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//ClassifierContextDeclExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createClassifierContextDeclExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//ClassifierContextDeclExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createClassifierContextDeclExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::COLLECTIONITEM_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCollectionItem(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//CollectionItem has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createCollectionItem_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//CollectionItem has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createCollectionItem_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//CollectionItem has part as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONLITERALEXP_ATTRIBUTE_PART:	
					{
						std::shared_ptr<ocl::Expressions::CollectionLiteralExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionLiteralExp> (container);
						return this->createCollectionItem_as_part_in_CollectionLiteralExp(castedContainer,metaElementID);
					}
					//CollectionItem has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createCollectionItem_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//CollectionItem has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createCollectionItem_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::COLLECTIONLITERALEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCollectionLiteralExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//CollectionLiteralExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createCollectionLiteralExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createCollectionLiteralExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createCollectionLiteralExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createCollectionLiteralExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createCollectionLiteralExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createCollectionLiteralExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createCollectionLiteralExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createCollectionLiteralExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createCollectionLiteralExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createCollectionLiteralExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createCollectionLiteralExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createCollectionLiteralExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createCollectionLiteralExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createCollectionLiteralExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createCollectionLiteralExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createCollectionLiteralExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createCollectionLiteralExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createCollectionLiteralExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::COLLECTIONLITERALPARTS_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCollectionLiteralParts(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//CollectionLiteralParts has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createCollectionLiteralParts_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//CollectionLiteralParts has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createCollectionLiteralParts_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//CollectionLiteralParts has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createCollectionLiteralParts_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//CollectionLiteralParts has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createCollectionLiteralParts_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::COLLECTIONRANGE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCollectionRange(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//CollectionRange has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createCollectionRange_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//CollectionRange has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createCollectionRange_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//CollectionRange has part as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONLITERALEXP_ATTRIBUTE_PART:	
					{
						std::shared_ptr<ocl::Expressions::CollectionLiteralExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionLiteralExp> (container);
						return this->createCollectionRange_as_part_in_CollectionLiteralExp(castedContainer,metaElementID);
					}
					//CollectionRange has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createCollectionRange_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//CollectionRange has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createCollectionRange_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::COLLECTIONTYPEEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCollectionTypeExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//CollectionTypeExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createCollectionTypeExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//CollectionTypeExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createCollectionTypeExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//CollectionTypeExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createCollectionTypeExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//CollectionTypeExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createCollectionTypeExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//CollectionTypeExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createCollectionTypeExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//CollectionTypeExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createCollectionTypeExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//CollectionTypeExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createCollectionTypeExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//CollectionTypeExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createCollectionTypeExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//CollectionTypeExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createCollectionTypeExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//CollectionTypeExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createCollectionTypeExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//CollectionTypeExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createCollectionTypeExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//CollectionTypeExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createCollectionTypeExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//CollectionTypeExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createCollectionTypeExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//CollectionTypeExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createCollectionTypeExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//CollectionTypeExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createCollectionTypeExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//CollectionTypeExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createCollectionTypeExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//CollectionTypeExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createCollectionTypeExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//CollectionTypeExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createCollectionTypeExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::DEFEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createDefExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//DefExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createDefExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//DefExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createDefExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//DefExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createDefExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//DefExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createDefExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//DefExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createDefExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//DefExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createDefExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//DefExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createDefExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//DefExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createDefExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//DefExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createDefExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//DefExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createDefExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//DefExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createDefExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//DefExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createDefExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//DefExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createDefExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//DefExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createDefExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//DefExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createDefExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//DefExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createDefExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//DefExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createDefExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//DefExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createDefExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::ENUMLITERALEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createEnumLiteralExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//EnumLiteralExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createEnumLiteralExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//EnumLiteralExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createEnumLiteralExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//EnumLiteralExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createEnumLiteralExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//EnumLiteralExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createEnumLiteralExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//EnumLiteralExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createEnumLiteralExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//EnumLiteralExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createEnumLiteralExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//EnumLiteralExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createEnumLiteralExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//EnumLiteralExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createEnumLiteralExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//EnumLiteralExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createEnumLiteralExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//EnumLiteralExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createEnumLiteralExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//EnumLiteralExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createEnumLiteralExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//EnumLiteralExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createEnumLiteralExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//EnumLiteralExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createEnumLiteralExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//EnumLiteralExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createEnumLiteralExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//EnumLiteralExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createEnumLiteralExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//EnumLiteralExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createEnumLiteralExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//EnumLiteralExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createEnumLiteralExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//EnumLiteralExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createEnumLiteralExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::EXPRESSIONINOCL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createExpressionInOcl(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ExpressionInOcl has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createExpressionInOcl_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//ExpressionInOcl has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createExpressionInOcl_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//ExpressionInOcl has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createExpressionInOcl_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//ExpressionInOcl has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createExpressionInOcl_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::IFEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createIfExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//IfExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createIfExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//IfExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createIfExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//IfExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createIfExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//IfExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createIfExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//IfExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createIfExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//IfExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createIfExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//IfExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createIfExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//IfExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createIfExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//IfExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createIfExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//IfExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createIfExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//IfExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createIfExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//IfExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createIfExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//IfExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createIfExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//IfExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createIfExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//IfExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createIfExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//IfExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createIfExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//IfExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createIfExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//IfExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createIfExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::INFIXEDEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createInfixedExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//InfixedExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createInfixedExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//InfixedExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createInfixedExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//InfixedExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createInfixedExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//InfixedExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createInfixedExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//InfixedExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createInfixedExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//InfixedExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createInfixedExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//InfixedExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createInfixedExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//InfixedExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createInfixedExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//InfixedExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createInfixedExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//InfixedExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createInfixedExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//InfixedExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createInfixedExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//InfixedExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createInfixedExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//InfixedExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createInfixedExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//InfixedExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createInfixedExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//InfixedExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createInfixedExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//InfixedExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createInfixedExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//InfixedExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createInfixedExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//InfixedExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createInfixedExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::INITORDERVALUEEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createInitOrDerValueExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//InitOrDerValueExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createInitOrDerValueExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//InitOrDerValueExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createInitOrDerValueExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//InitOrDerValueExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createInitOrDerValueExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//InitOrDerValueExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createInitOrDerValueExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::INITORDERVALUELISTEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createInitOrDerValueListExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//InitOrDerValueListExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createInitOrDerValueListExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//InitOrDerValueListExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createInitOrDerValueListExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//InitOrDerValueListExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createInitOrDerValueListExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//InitOrDerValueListExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createInitOrDerValueListExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//InitOrDerValueListExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createInitOrDerValueListExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//InitOrDerValueListExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createInitOrDerValueListExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//InitOrDerValueListExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createInitOrDerValueListExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//InitOrDerValueListExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createInitOrDerValueListExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//InitOrDerValueListExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createInitOrDerValueListExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//InitOrDerValueListExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createInitOrDerValueListExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//InitOrDerValueListExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createInitOrDerValueListExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//InitOrDerValueListExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createInitOrDerValueListExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//InitOrDerValueListExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createInitOrDerValueListExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//InitOrDerValueListExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createInitOrDerValueListExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//InitOrDerValueListExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createInitOrDerValueListExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//InitOrDerValueListExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createInitOrDerValueListExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//InitOrDerValueListExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createInitOrDerValueListExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//InitOrDerValueListExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createInitOrDerValueListExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::INTEGERLITERALEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createIntegerLiteralExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//IntegerLiteralExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createIntegerLiteralExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createIntegerLiteralExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createIntegerLiteralExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createIntegerLiteralExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createIntegerLiteralExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createIntegerLiteralExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createIntegerLiteralExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createIntegerLiteralExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createIntegerLiteralExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createIntegerLiteralExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createIntegerLiteralExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createIntegerLiteralExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createIntegerLiteralExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createIntegerLiteralExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createIntegerLiteralExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createIntegerLiteralExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createIntegerLiteralExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createIntegerLiteralExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::INVORDEFEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createInvOrDefExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//InvOrDefExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createInvOrDefExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//InvOrDefExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createInvOrDefExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//InvOrDefExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createInvOrDefExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//InvOrDefExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createInvOrDefExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::INVALIDLITERALEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createInvalidLiteralExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//InvalidLiteralExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createInvalidLiteralExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createInvalidLiteralExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createInvalidLiteralExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createInvalidLiteralExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createInvalidLiteralExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createInvalidLiteralExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createInvalidLiteralExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createInvalidLiteralExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createInvalidLiteralExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createInvalidLiteralExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createInvalidLiteralExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createInvalidLiteralExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createInvalidLiteralExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createInvalidLiteralExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createInvalidLiteralExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createInvalidLiteralExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createInvalidLiteralExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createInvalidLiteralExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::ITERATEEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createIterateExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//IterateExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createIterateExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//IterateExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createIterateExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//IterateExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createIterateExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//IterateExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createIterateExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//IterateExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createIterateExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//IterateExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createIterateExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//IterateExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createIterateExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//IterateExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createIterateExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//IterateExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createIterateExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//IterateExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createIterateExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//IterateExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createIterateExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//IterateExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createIterateExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//IterateExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createIterateExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//IterateExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createIterateExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//IterateExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createIterateExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//IterateExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createIterateExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//IterateExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createIterateExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//IterateExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createIterateExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::ITERATOREXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createIteratorExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//IteratorExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createIteratorExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//IteratorExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createIteratorExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//IteratorExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createIteratorExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//IteratorExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createIteratorExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//IteratorExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createIteratorExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//IteratorExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createIteratorExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//IteratorExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createIteratorExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//IteratorExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createIteratorExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//IteratorExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createIteratorExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//IteratorExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createIteratorExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//IteratorExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createIteratorExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//IteratorExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createIteratorExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//IteratorExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createIteratorExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//IteratorExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createIteratorExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//IteratorExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createIteratorExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//IteratorExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createIteratorExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//IteratorExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createIteratorExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//IteratorExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createIteratorExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::LETEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createLetExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//LetExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createLetExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//LetExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createLetExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//LetExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createLetExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//LetExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createLetExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//LetExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createLetExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//LetExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createLetExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//LetExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createLetExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//LetExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createLetExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//LetExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createLetExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//LetExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createLetExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//LetExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createLetExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//LetExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createLetExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//LetExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createLetExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//LetExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createLetExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//LetExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createLetExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//LetExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createLetExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//LetExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createLetExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//LetExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createLetExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::MESSAGEARGUMENTS_CLASS:
		{
			if (nullptr == container)
			{
				return this->createMessageArguments(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//MessageArguments has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createMessageArguments_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//MessageArguments has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createMessageArguments_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//MessageArguments has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createMessageArguments_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//MessageArguments has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createMessageArguments_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::MESSAGEEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createMessageExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//MessageExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createMessageExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//MessageExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createMessageExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//MessageExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createMessageExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//MessageExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createMessageExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//MessageExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createMessageExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//MessageExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createMessageExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//MessageExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createMessageExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//MessageExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createMessageExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//MessageExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createMessageExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//MessageExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createMessageExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//MessageExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createMessageExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//MessageExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createMessageExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//MessageExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createMessageExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//MessageExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createMessageExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//MessageExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createMessageExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//MessageExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createMessageExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//MessageExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createMessageExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//MessageExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createMessageExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::NULLLITERALEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createNullLiteralExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//NullLiteralExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createNullLiteralExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//NullLiteralExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createNullLiteralExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//NullLiteralExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createNullLiteralExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//NullLiteralExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createNullLiteralExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//NullLiteralExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createNullLiteralExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//NullLiteralExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createNullLiteralExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//NullLiteralExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createNullLiteralExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//NullLiteralExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createNullLiteralExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//NullLiteralExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createNullLiteralExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//NullLiteralExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createNullLiteralExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//NullLiteralExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createNullLiteralExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//NullLiteralExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createNullLiteralExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//NullLiteralExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createNullLiteralExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//NullLiteralExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createNullLiteralExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//NullLiteralExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createNullLiteralExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//NullLiteralExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createNullLiteralExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//NullLiteralExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createNullLiteralExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//NullLiteralExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createNullLiteralExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::OPERATIONCALLEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createOperationCallExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//OperationCallExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createOperationCallExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//OperationCallExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createOperationCallExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//OperationCallExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createOperationCallExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//OperationCallExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createOperationCallExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//OperationCallExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createOperationCallExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//OperationCallExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createOperationCallExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//OperationCallExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createOperationCallExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//OperationCallExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createOperationCallExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//OperationCallExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createOperationCallExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//OperationCallExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createOperationCallExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//OperationCallExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createOperationCallExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//OperationCallExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createOperationCallExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//OperationCallExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createOperationCallExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//OperationCallExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createOperationCallExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//OperationCallExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createOperationCallExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//OperationCallExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createOperationCallExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//OperationCallExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createOperationCallExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//OperationCallExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createOperationCallExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::OPERATIONCONTEXTDECLEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createOperationContextDeclExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//OperationContextDeclExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createOperationContextDeclExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//OperationContextDeclExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createOperationContextDeclExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//OperationContextDeclExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createOperationContextDeclExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//OperationContextDeclExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createOperationContextDeclExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//OperationContextDeclExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createOperationContextDeclExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//OperationContextDeclExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createOperationContextDeclExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//OperationContextDeclExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createOperationContextDeclExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//OperationContextDeclExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createOperationContextDeclExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//OperationContextDeclExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createOperationContextDeclExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//OperationContextDeclExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createOperationContextDeclExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//OperationContextDeclExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createOperationContextDeclExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//OperationContextDeclExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createOperationContextDeclExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//OperationContextDeclExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createOperationContextDeclExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//OperationContextDeclExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createOperationContextDeclExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//OperationContextDeclExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createOperationContextDeclExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//OperationContextDeclExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createOperationContextDeclExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//OperationContextDeclExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createOperationContextDeclExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//OperationContextDeclExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createOperationContextDeclExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::OPERATIONCONTEXTEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createOperationContextExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//OperationContextExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createOperationContextExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//OperationContextExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createOperationContextExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//OperationContextExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createOperationContextExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//OperationContextExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createOperationContextExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//OperationContextExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createOperationContextExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//OperationContextExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createOperationContextExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//OperationContextExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createOperationContextExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//OperationContextExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createOperationContextExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//OperationContextExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createOperationContextExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//OperationContextExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createOperationContextExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//OperationContextExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createOperationContextExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//OperationContextExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createOperationContextExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//OperationContextExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createOperationContextExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//OperationContextExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createOperationContextExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//OperationContextExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createOperationContextExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//OperationContextExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createOperationContextExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//OperationContextExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createOperationContextExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//OperationContextExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createOperationContextExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::OPERATOREXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createOperatorExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//OperatorExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createOperatorExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//OperatorExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createOperatorExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//OperatorExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createOperatorExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//OperatorExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createOperatorExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//OperatorExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createOperatorExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//OperatorExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createOperatorExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//OperatorExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createOperatorExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//OperatorExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createOperatorExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//OperatorExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createOperatorExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//OperatorExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createOperatorExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//OperatorExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createOperatorExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//OperatorExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createOperatorExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//OperatorExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createOperatorExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//OperatorExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createOperatorExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//OperatorExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createOperatorExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//OperatorExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createOperatorExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//OperatorExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createOperatorExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//OperatorExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createOperatorExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::PACKAGEDECLARATIONEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createPackageDeclarationExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//PackageDeclarationExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createPackageDeclarationExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//PackageDeclarationExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createPackageDeclarationExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//PackageDeclarationExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createPackageDeclarationExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//PackageDeclarationExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createPackageDeclarationExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//PackageDeclarationExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createPackageDeclarationExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//PackageDeclarationExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createPackageDeclarationExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//PackageDeclarationExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createPackageDeclarationExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//PackageDeclarationExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createPackageDeclarationExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//PackageDeclarationExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createPackageDeclarationExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//PackageDeclarationExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createPackageDeclarationExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//PackageDeclarationExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createPackageDeclarationExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//PackageDeclarationExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createPackageDeclarationExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//PackageDeclarationExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createPackageDeclarationExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//PackageDeclarationExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createPackageDeclarationExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//PackageDeclarationExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createPackageDeclarationExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//PackageDeclarationExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createPackageDeclarationExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//PackageDeclarationExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createPackageDeclarationExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//PackageDeclarationExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createPackageDeclarationExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::PARENTEDEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createParentedExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ParentedExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createParentedExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//ParentedExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createParentedExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//ParentedExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createParentedExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//ParentedExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createParentedExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//ParentedExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createParentedExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//ParentedExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createParentedExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//ParentedExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createParentedExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//ParentedExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createParentedExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//ParentedExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createParentedExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//ParentedExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createParentedExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//ParentedExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createParentedExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//ParentedExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createParentedExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//ParentedExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createParentedExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//ParentedExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createParentedExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//ParentedExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createParentedExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//ParentedExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createParentedExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//ParentedExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createParentedExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//ParentedExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createParentedExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::PREPOSTBODYEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createPrePostBodyExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//PrePostBodyExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createPrePostBodyExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//PrePostBodyExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createPrePostBodyExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//PrePostBodyExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createPrePostBodyExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//PrePostBodyExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createPrePostBodyExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::PREPOSTBODYLISTEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createPrePostBodyListExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//PrePostBodyListExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createPrePostBodyListExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//PrePostBodyListExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createPrePostBodyListExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//PrePostBodyListExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createPrePostBodyListExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//PrePostBodyListExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createPrePostBodyListExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//PrePostBodyListExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createPrePostBodyListExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//PrePostBodyListExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createPrePostBodyListExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//PrePostBodyListExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createPrePostBodyListExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//PrePostBodyListExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createPrePostBodyListExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//PrePostBodyListExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createPrePostBodyListExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//PrePostBodyListExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createPrePostBodyListExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//PrePostBodyListExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createPrePostBodyListExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//PrePostBodyListExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createPrePostBodyListExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//PrePostBodyListExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createPrePostBodyListExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//PrePostBodyListExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createPrePostBodyListExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//PrePostBodyListExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createPrePostBodyListExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//PrePostBodyListExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createPrePostBodyListExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//PrePostBodyListExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createPrePostBodyListExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//PrePostBodyListExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createPrePostBodyListExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::PREFIXEDEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createPrefixedExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//PrefixedExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createPrefixedExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//PrefixedExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createPrefixedExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//PrefixedExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createPrefixedExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//PrefixedExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createPrefixedExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//PrefixedExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createPrefixedExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//PrefixedExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createPrefixedExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//PrefixedExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createPrefixedExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//PrefixedExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createPrefixedExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//PrefixedExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createPrefixedExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//PrefixedExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createPrefixedExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//PrefixedExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createPrefixedExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//PrefixedExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createPrefixedExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//PrefixedExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createPrefixedExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//PrefixedExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createPrefixedExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//PrefixedExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createPrefixedExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//PrefixedExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createPrefixedExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//PrefixedExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createPrefixedExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//PrefixedExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createPrefixedExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::PROPERTYCALLEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createPropertyCallExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//PropertyCallExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createPropertyCallExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//PropertyCallExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createPropertyCallExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//PropertyCallExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createPropertyCallExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//PropertyCallExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createPropertyCallExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//PropertyCallExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createPropertyCallExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//PropertyCallExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createPropertyCallExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//PropertyCallExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createPropertyCallExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//PropertyCallExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createPropertyCallExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//PropertyCallExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createPropertyCallExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//PropertyCallExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createPropertyCallExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//PropertyCallExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createPropertyCallExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//PropertyCallExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createPropertyCallExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//PropertyCallExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createPropertyCallExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//PropertyCallExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createPropertyCallExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//PropertyCallExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createPropertyCallExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//PropertyCallExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createPropertyCallExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//PropertyCallExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createPropertyCallExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//PropertyCallExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createPropertyCallExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::PROPERTYCONTEXTDECLEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createPropertyContextDeclExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//PropertyContextDeclExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createPropertyContextDeclExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//PropertyContextDeclExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createPropertyContextDeclExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//PropertyContextDeclExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createPropertyContextDeclExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//PropertyContextDeclExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createPropertyContextDeclExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//PropertyContextDeclExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createPropertyContextDeclExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//PropertyContextDeclExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createPropertyContextDeclExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//PropertyContextDeclExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createPropertyContextDeclExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//PropertyContextDeclExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createPropertyContextDeclExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//PropertyContextDeclExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createPropertyContextDeclExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//PropertyContextDeclExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createPropertyContextDeclExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//PropertyContextDeclExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createPropertyContextDeclExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//PropertyContextDeclExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createPropertyContextDeclExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//PropertyContextDeclExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createPropertyContextDeclExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//PropertyContextDeclExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createPropertyContextDeclExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//PropertyContextDeclExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createPropertyContextDeclExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//PropertyContextDeclExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createPropertyContextDeclExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//PropertyContextDeclExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createPropertyContextDeclExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//PropertyContextDeclExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createPropertyContextDeclExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::REALLITERALEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createRealLiteralExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//RealLiteralExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createRealLiteralExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//RealLiteralExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createRealLiteralExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//RealLiteralExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createRealLiteralExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//RealLiteralExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createRealLiteralExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//RealLiteralExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createRealLiteralExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//RealLiteralExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createRealLiteralExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//RealLiteralExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createRealLiteralExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//RealLiteralExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createRealLiteralExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//RealLiteralExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createRealLiteralExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//RealLiteralExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createRealLiteralExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//RealLiteralExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createRealLiteralExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//RealLiteralExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createRealLiteralExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//RealLiteralExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createRealLiteralExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//RealLiteralExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createRealLiteralExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//RealLiteralExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createRealLiteralExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//RealLiteralExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createRealLiteralExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//RealLiteralExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createRealLiteralExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//RealLiteralExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createRealLiteralExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::STATEEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createStateExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//StateExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createStateExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//StateExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createStateExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//StateExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createStateExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//StateExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createStateExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//StateExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createStateExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//StateExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createStateExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//StateExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createStateExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//StateExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createStateExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//StateExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createStateExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//StateExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createStateExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//StateExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createStateExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//StateExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createStateExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//StateExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createStateExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//StateExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createStateExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//StateExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createStateExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//StateExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createStateExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//StateExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createStateExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//StateExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createStateExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::STRINGLITERALEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createStringLiteralExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//StringLiteralExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createStringLiteralExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//StringLiteralExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createStringLiteralExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//StringLiteralExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createStringLiteralExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//StringLiteralExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createStringLiteralExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//StringLiteralExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createStringLiteralExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//StringLiteralExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createStringLiteralExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//StringLiteralExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createStringLiteralExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//StringLiteralExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createStringLiteralExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//StringLiteralExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createStringLiteralExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//StringLiteralExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createStringLiteralExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//StringLiteralExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createStringLiteralExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//StringLiteralExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createStringLiteralExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//StringLiteralExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createStringLiteralExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//StringLiteralExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createStringLiteralExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//StringLiteralExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createStringLiteralExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//StringLiteralExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createStringLiteralExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//StringLiteralExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createStringLiteralExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//StringLiteralExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createStringLiteralExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::TUPLELITERALEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createTupleLiteralExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//TupleLiteralExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createTupleLiteralExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//TupleLiteralExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createTupleLiteralExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//TupleLiteralExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createTupleLiteralExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//TupleLiteralExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createTupleLiteralExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//TupleLiteralExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createTupleLiteralExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//TupleLiteralExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createTupleLiteralExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//TupleLiteralExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createTupleLiteralExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//TupleLiteralExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createTupleLiteralExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//TupleLiteralExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createTupleLiteralExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//TupleLiteralExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createTupleLiteralExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//TupleLiteralExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createTupleLiteralExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//TupleLiteralExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createTupleLiteralExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//TupleLiteralExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createTupleLiteralExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//TupleLiteralExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createTupleLiteralExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//TupleLiteralExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createTupleLiteralExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//TupleLiteralExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createTupleLiteralExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//TupleLiteralExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createTupleLiteralExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//TupleLiteralExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createTupleLiteralExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::TUPLELITERALPART_CLASS:
		{
			if (nullptr == container)
			{
				return this->createTupleLiteralPart(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//TupleLiteralPart has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createTupleLiteralPart_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//TupleLiteralPart has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createTupleLiteralPart_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//TupleLiteralPart has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createTupleLiteralPart_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//TupleLiteralPart has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createTupleLiteralPart_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::TUPLETYPEEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createTupleTypeExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//TupleTypeExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createTupleTypeExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//TupleTypeExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createTupleTypeExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//TupleTypeExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createTupleTypeExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//TupleTypeExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createTupleTypeExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//TupleTypeExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createTupleTypeExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//TupleTypeExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createTupleTypeExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//TupleTypeExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createTupleTypeExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//TupleTypeExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createTupleTypeExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//TupleTypeExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createTupleTypeExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//TupleTypeExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createTupleTypeExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//TupleTypeExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createTupleTypeExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//TupleTypeExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createTupleTypeExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//TupleTypeExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createTupleTypeExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//TupleTypeExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createTupleTypeExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//TupleTypeExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createTupleTypeExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//TupleTypeExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createTupleTypeExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//TupleTypeExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createTupleTypeExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//TupleTypeExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createTupleTypeExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::TYPEEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createTypeExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//TypeExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createTypeExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//TypeExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createTypeExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//TypeExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createTypeExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//TypeExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createTypeExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//TypeExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createTypeExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//TypeExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createTypeExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//TypeExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createTypeExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//TypeExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createTypeExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//TypeExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createTypeExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//TypeExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createTypeExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//TypeExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createTypeExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//TypeExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createTypeExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//TypeExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createTypeExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//TypeExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createTypeExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//TypeExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createTypeExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//TypeExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createTypeExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//TypeExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createTypeExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//TypeExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createTypeExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::UNLIMITEDNATURALEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createUnlimitedNaturalExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//UnlimitedNaturalExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createUnlimitedNaturalExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createUnlimitedNaturalExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createUnlimitedNaturalExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createUnlimitedNaturalExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createUnlimitedNaturalExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createUnlimitedNaturalExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createUnlimitedNaturalExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createUnlimitedNaturalExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createUnlimitedNaturalExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createUnlimitedNaturalExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createUnlimitedNaturalExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createUnlimitedNaturalExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createUnlimitedNaturalExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createUnlimitedNaturalExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createUnlimitedNaturalExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createUnlimitedNaturalExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createUnlimitedNaturalExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createUnlimitedNaturalExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::UNSPECIFIEDVALUEEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createUnspecifiedValueExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//UnspecifiedValueExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createUnspecifiedValueExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createUnspecifiedValueExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createUnspecifiedValueExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createUnspecifiedValueExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createUnspecifiedValueExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createUnspecifiedValueExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createUnspecifiedValueExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createUnspecifiedValueExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createUnspecifiedValueExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createUnspecifiedValueExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createUnspecifiedValueExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createUnspecifiedValueExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createUnspecifiedValueExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createUnspecifiedValueExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createUnspecifiedValueExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createUnspecifiedValueExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createUnspecifiedValueExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createUnspecifiedValueExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::VARDECLARATIONEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createVarDeclarationExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//VarDeclarationExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createVarDeclarationExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//VarDeclarationExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createVarDeclarationExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//VarDeclarationExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createVarDeclarationExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//VarDeclarationExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createVarDeclarationExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//VarDeclarationExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createVarDeclarationExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//VarDeclarationExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createVarDeclarationExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//VarDeclarationExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createVarDeclarationExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//VarDeclarationExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createVarDeclarationExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//VarDeclarationExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createVarDeclarationExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//VarDeclarationExp has initializedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_INITIALIZEDELEMENT:	
					{
						std::weak_ptr<ocl::Expressions::OclExpression> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OclExpression> (container);
						return this->createVarDeclarationExp_as_initializedElement_in_OclExpression(castedContainer,metaElementID);
					}
					//VarDeclarationExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createVarDeclarationExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//VarDeclarationExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createVarDeclarationExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//VarDeclarationExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createVarDeclarationExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//VarDeclarationExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createVarDeclarationExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//VarDeclarationExp has part as a containment
					case  ocl::Expressions::ExpressionsPackage::TUPLELITERALEXP_ATTRIBUTE_PART:	
					{
						std::shared_ptr<ocl::Expressions::TupleLiteralExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::TupleLiteralExp> (container);
						return this->createVarDeclarationExp_as_part_in_TupleLiteralExp(castedContainer,metaElementID);
					}
					//VarDeclarationExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createVarDeclarationExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//VarDeclarationExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createVarDeclarationExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//VarDeclarationExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createVarDeclarationExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//VarDeclarationExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createVarDeclarationExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//VarDeclarationExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createVarDeclarationExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					//VarDeclarationExp has variables as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_VARIABLES:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createVarDeclarationExp_as_variables_in_LetExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::VARIABLE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createVariable(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Variable has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createVariable_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//Variable has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createVariable_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//Variable has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createVariable_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//Variable has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createVariable_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::VARIABLEEXP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createVariableExp(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//VariableExp has argument as a containment
					case  ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						std::weak_ptr<ocl::Expressions::OperationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp> (container);
						return this->createVariableExp_as_argument_in_OperationCallExp(castedContainer,metaElementID);
					}
					//VariableExp has body as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createVariableExp_as_body_in_LoopExp(castedContainer,metaElementID);
					}
					//VariableExp has bodyExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createVariableExp_as_bodyExpression_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//VariableExp has condition as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createVariableExp_as_condition_in_IfExp(castedContainer,metaElementID);
					}
					//VariableExp has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createVariableExp_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//VariableExp has elseExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createVariableExp_as_elseExpression_in_IfExp(castedContainer,metaElementID);
					}
					//VariableExp has first as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createVariableExp_as_first_in_CollectionRange(castedContainer,metaElementID);
					}
					//VariableExp has in as a containment
					case  ocl::Expressions::ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						std::shared_ptr<ocl::Expressions::LetExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp> (container);
						return this->createVariableExp_as_in_in_LetExp(castedContainer,metaElementID);
					}
					//VariableExp has initExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						std::shared_ptr<ocl::Expressions::Variable> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable> (container);
						return this->createVariableExp_as_initExpression_in_Variable(castedContainer,metaElementID);
					}
					//VariableExp has item as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						std::shared_ptr<ocl::Expressions::CollectionItem> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem> (container);
						return this->createVariableExp_as_item_in_CollectionItem(castedContainer,metaElementID);
					}
					//VariableExp has iterator as a containment
					case  ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						std::weak_ptr<ocl::Expressions::LoopExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp> (container);
						return this->createVariableExp_as_iterator_in_LoopExp(castedContainer,metaElementID);
					}
					//VariableExp has last as a containment
					case  ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						std::weak_ptr<ocl::Expressions::CollectionRange> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange> (container);
						return this->createVariableExp_as_last_in_CollectionRange(castedContainer,metaElementID);
					}
					//VariableExp has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createVariableExp_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//VariableExp has qualifier as a containment
					case  ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						std::weak_ptr<ocl::Expressions::NavigationCallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp> (container);
						return this->createVariableExp_as_qualifier_in_NavigationCallExp(castedContainer,metaElementID);
					}
					//VariableExp has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);
						return this->createVariableExp_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//VariableExp has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);
						return this->createVariableExp_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//VariableExp has source as a containment
					case  ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<ocl::Expressions::CallExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp> (container);
						return this->createVariableExp_as_source_in_CallExp(castedContainer,metaElementID);
					}
					//VariableExp has thenExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						std::weak_ptr<ocl::Expressions::IfExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp> (container);
						return this->createVariableExp_as_thenExpression_in_IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << metaElementID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<ecore::EObject> ExpressionsFactoryImpl::create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}
	int _elementID = _class->getMetaElementID();
	return create(_elementID, container, referenceID);
}

std::shared_ptr<ecore::EObject> ExpressionsFactoryImpl::create(std::string _className, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	auto iter = m_idMap.find(_className);
	if(iter != m_idMap.end())
    {
		//get the ID
        int id = iter->second;
		return create(id,container,referenceID);
    }
    return nullptr;
}

std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisAssociationClassCallExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisAssociationClassCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisAssociationClassCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisAssociationClassCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisAssociationClassCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisAssociationClassCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisAssociationClassCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisAssociationClassCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisAssociationClassCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisAssociationClassCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisAssociationClassCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisAssociationClassCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisAssociationClassCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisAssociationClassCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisAssociationClassCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisAssociationClassCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisAssociationClassCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisAssociationClassCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisAssociationClassCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisBooleanLiteralExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisBooleanLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisBooleanLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisBooleanLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisBooleanLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisBooleanLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisBooleanLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisBooleanLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisBooleanLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisBooleanLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisBooleanLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisBooleanLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisBooleanLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisBooleanLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisBooleanLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisBooleanLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisBooleanLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisBooleanLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisBooleanLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ClassifierContextDeclExp> ExpressionsFactoryImpl::createClassifierContextDeclExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::ClassifierContextDeclExpImpl> element(new ocl::Expressions::ClassifierContextDeclExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisClassifierContextDeclExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::ClassifierContextDeclExp> ExpressionsFactoryImpl::createClassifierContextDeclExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ClassifierContextDeclExpImpl> element(new ocl::Expressions::ClassifierContextDeclExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisClassifierContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ClassifierContextDeclExp> ExpressionsFactoryImpl::createClassifierContextDeclExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ClassifierContextDeclExpImpl> element(new ocl::Expressions::ClassifierContextDeclExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisClassifierContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ClassifierContextDeclExp> ExpressionsFactoryImpl::createClassifierContextDeclExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ClassifierContextDeclExpImpl> element(new ocl::Expressions::ClassifierContextDeclExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisClassifierContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ClassifierContextDeclExp> ExpressionsFactoryImpl::createClassifierContextDeclExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ClassifierContextDeclExpImpl> element(new ocl::Expressions::ClassifierContextDeclExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisClassifierContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ClassifierContextDeclExp> ExpressionsFactoryImpl::createClassifierContextDeclExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ClassifierContextDeclExpImpl> element(new ocl::Expressions::ClassifierContextDeclExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisClassifierContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ClassifierContextDeclExp> ExpressionsFactoryImpl::createClassifierContextDeclExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ClassifierContextDeclExpImpl> element(new ocl::Expressions::ClassifierContextDeclExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisClassifierContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ClassifierContextDeclExp> ExpressionsFactoryImpl::createClassifierContextDeclExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ClassifierContextDeclExpImpl> element(new ocl::Expressions::ClassifierContextDeclExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisClassifierContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ClassifierContextDeclExp> ExpressionsFactoryImpl::createClassifierContextDeclExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ClassifierContextDeclExpImpl> element(new ocl::Expressions::ClassifierContextDeclExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisClassifierContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ClassifierContextDeclExp> ExpressionsFactoryImpl::createClassifierContextDeclExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ClassifierContextDeclExpImpl> element(new ocl::Expressions::ClassifierContextDeclExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisClassifierContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ClassifierContextDeclExp> ExpressionsFactoryImpl::createClassifierContextDeclExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ClassifierContextDeclExpImpl> element(new ocl::Expressions::ClassifierContextDeclExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisClassifierContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ClassifierContextDeclExp> ExpressionsFactoryImpl::createClassifierContextDeclExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ClassifierContextDeclExpImpl> element(new ocl::Expressions::ClassifierContextDeclExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisClassifierContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ClassifierContextDeclExp> ExpressionsFactoryImpl::createClassifierContextDeclExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ClassifierContextDeclExpImpl> element(new ocl::Expressions::ClassifierContextDeclExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisClassifierContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ClassifierContextDeclExp> ExpressionsFactoryImpl::createClassifierContextDeclExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ClassifierContextDeclExpImpl> element(new ocl::Expressions::ClassifierContextDeclExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisClassifierContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ClassifierContextDeclExp> ExpressionsFactoryImpl::createClassifierContextDeclExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ClassifierContextDeclExpImpl> element(new ocl::Expressions::ClassifierContextDeclExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisClassifierContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ClassifierContextDeclExp> ExpressionsFactoryImpl::createClassifierContextDeclExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ClassifierContextDeclExpImpl> element(new ocl::Expressions::ClassifierContextDeclExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisClassifierContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ClassifierContextDeclExp> ExpressionsFactoryImpl::createClassifierContextDeclExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ClassifierContextDeclExpImpl> element(new ocl::Expressions::ClassifierContextDeclExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisClassifierContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ClassifierContextDeclExp> ExpressionsFactoryImpl::createClassifierContextDeclExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ClassifierContextDeclExpImpl> element(new ocl::Expressions::ClassifierContextDeclExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisClassifierContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ClassifierContextDeclExp> ExpressionsFactoryImpl::createClassifierContextDeclExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ClassifierContextDeclExpImpl> element(new ocl::Expressions::ClassifierContextDeclExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisClassifierContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionItem> ExpressionsFactoryImpl::createCollectionItem(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::CollectionItemImpl> element(new ocl::Expressions::CollectionItemImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCollectionItemPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::CollectionItem> ExpressionsFactoryImpl::createCollectionItem_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionItemImpl> element(new ocl::Expressions::CollectionItemImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisCollectionItemPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionItem> ExpressionsFactoryImpl::createCollectionItem_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionItemImpl> element(new ocl::Expressions::CollectionItemImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisCollectionItemPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionItem> ExpressionsFactoryImpl::createCollectionItem_as_part_in_CollectionLiteralExp(std::shared_ptr<ocl::Expressions::CollectionLiteralExp> par_CollectionLiteralExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionItemImpl> element(new ocl::Expressions::CollectionItemImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionLiteralExp)
	{
		par_CollectionLiteralExp->getPart()->push_back(element);
	}
	
	element->setThisCollectionItemPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionItem> ExpressionsFactoryImpl::createCollectionItem_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionItemImpl> element(new ocl::Expressions::CollectionItemImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisCollectionItemPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionItem> ExpressionsFactoryImpl::createCollectionItem_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionItemImpl> element(new ocl::Expressions::CollectionItemImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisCollectionItemPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCollectionLiteralExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisCollectionLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisCollectionLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisCollectionLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisCollectionLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisCollectionLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisCollectionLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisCollectionLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisCollectionLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisCollectionLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisCollectionLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisCollectionLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisCollectionLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisCollectionLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisCollectionLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisCollectionLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisCollectionLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisCollectionLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisCollectionLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionLiteralParts> ExpressionsFactoryImpl::createCollectionLiteralParts(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralPartsImpl> element(new ocl::Expressions::CollectionLiteralPartsImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCollectionLiteralPartsPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::CollectionLiteralParts> ExpressionsFactoryImpl::createCollectionLiteralParts_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralPartsImpl> element(new ocl::Expressions::CollectionLiteralPartsImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisCollectionLiteralPartsPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionLiteralParts> ExpressionsFactoryImpl::createCollectionLiteralParts_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralPartsImpl> element(new ocl::Expressions::CollectionLiteralPartsImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisCollectionLiteralPartsPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionLiteralParts> ExpressionsFactoryImpl::createCollectionLiteralParts_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralPartsImpl> element(new ocl::Expressions::CollectionLiteralPartsImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisCollectionLiteralPartsPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionLiteralParts> ExpressionsFactoryImpl::createCollectionLiteralParts_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralPartsImpl> element(new ocl::Expressions::CollectionLiteralPartsImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisCollectionLiteralPartsPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionRange> ExpressionsFactoryImpl::createCollectionRange(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::CollectionRangeImpl> element(new ocl::Expressions::CollectionRangeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCollectionRangePtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::CollectionRange> ExpressionsFactoryImpl::createCollectionRange_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionRangeImpl> element(new ocl::Expressions::CollectionRangeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisCollectionRangePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionRange> ExpressionsFactoryImpl::createCollectionRange_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionRangeImpl> element(new ocl::Expressions::CollectionRangeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisCollectionRangePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionRange> ExpressionsFactoryImpl::createCollectionRange_as_part_in_CollectionLiteralExp(std::shared_ptr<ocl::Expressions::CollectionLiteralExp> par_CollectionLiteralExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionRangeImpl> element(new ocl::Expressions::CollectionRangeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionLiteralExp)
	{
		par_CollectionLiteralExp->getPart()->push_back(element);
	}
	
	element->setThisCollectionRangePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionRange> ExpressionsFactoryImpl::createCollectionRange_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionRangeImpl> element(new ocl::Expressions::CollectionRangeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisCollectionRangePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionRange> ExpressionsFactoryImpl::createCollectionRange_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionRangeImpl> element(new ocl::Expressions::CollectionRangeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisCollectionRangePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionTypeExp> ExpressionsFactoryImpl::createCollectionTypeExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::CollectionTypeExpImpl> element(new ocl::Expressions::CollectionTypeExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCollectionTypeExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::CollectionTypeExp> ExpressionsFactoryImpl::createCollectionTypeExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionTypeExpImpl> element(new ocl::Expressions::CollectionTypeExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisCollectionTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionTypeExp> ExpressionsFactoryImpl::createCollectionTypeExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionTypeExpImpl> element(new ocl::Expressions::CollectionTypeExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisCollectionTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionTypeExp> ExpressionsFactoryImpl::createCollectionTypeExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionTypeExpImpl> element(new ocl::Expressions::CollectionTypeExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisCollectionTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionTypeExp> ExpressionsFactoryImpl::createCollectionTypeExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionTypeExpImpl> element(new ocl::Expressions::CollectionTypeExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisCollectionTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionTypeExp> ExpressionsFactoryImpl::createCollectionTypeExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionTypeExpImpl> element(new ocl::Expressions::CollectionTypeExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisCollectionTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionTypeExp> ExpressionsFactoryImpl::createCollectionTypeExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionTypeExpImpl> element(new ocl::Expressions::CollectionTypeExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisCollectionTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionTypeExp> ExpressionsFactoryImpl::createCollectionTypeExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionTypeExpImpl> element(new ocl::Expressions::CollectionTypeExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisCollectionTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionTypeExp> ExpressionsFactoryImpl::createCollectionTypeExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionTypeExpImpl> element(new ocl::Expressions::CollectionTypeExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisCollectionTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionTypeExp> ExpressionsFactoryImpl::createCollectionTypeExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionTypeExpImpl> element(new ocl::Expressions::CollectionTypeExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisCollectionTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionTypeExp> ExpressionsFactoryImpl::createCollectionTypeExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionTypeExpImpl> element(new ocl::Expressions::CollectionTypeExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisCollectionTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionTypeExp> ExpressionsFactoryImpl::createCollectionTypeExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionTypeExpImpl> element(new ocl::Expressions::CollectionTypeExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisCollectionTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionTypeExp> ExpressionsFactoryImpl::createCollectionTypeExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionTypeExpImpl> element(new ocl::Expressions::CollectionTypeExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisCollectionTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionTypeExp> ExpressionsFactoryImpl::createCollectionTypeExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionTypeExpImpl> element(new ocl::Expressions::CollectionTypeExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisCollectionTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionTypeExp> ExpressionsFactoryImpl::createCollectionTypeExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionTypeExpImpl> element(new ocl::Expressions::CollectionTypeExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisCollectionTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionTypeExp> ExpressionsFactoryImpl::createCollectionTypeExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionTypeExpImpl> element(new ocl::Expressions::CollectionTypeExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisCollectionTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionTypeExp> ExpressionsFactoryImpl::createCollectionTypeExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionTypeExpImpl> element(new ocl::Expressions::CollectionTypeExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisCollectionTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionTypeExp> ExpressionsFactoryImpl::createCollectionTypeExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionTypeExpImpl> element(new ocl::Expressions::CollectionTypeExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisCollectionTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionTypeExp> ExpressionsFactoryImpl::createCollectionTypeExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionTypeExpImpl> element(new ocl::Expressions::CollectionTypeExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisCollectionTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::DefExp> ExpressionsFactoryImpl::createDefExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::DefExpImpl> element(new ocl::Expressions::DefExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDefExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::DefExp> ExpressionsFactoryImpl::createDefExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::DefExpImpl> element(new ocl::Expressions::DefExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisDefExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::DefExp> ExpressionsFactoryImpl::createDefExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::DefExpImpl> element(new ocl::Expressions::DefExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisDefExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::DefExp> ExpressionsFactoryImpl::createDefExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::DefExpImpl> element(new ocl::Expressions::DefExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisDefExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::DefExp> ExpressionsFactoryImpl::createDefExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::DefExpImpl> element(new ocl::Expressions::DefExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisDefExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::DefExp> ExpressionsFactoryImpl::createDefExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::DefExpImpl> element(new ocl::Expressions::DefExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisDefExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::DefExp> ExpressionsFactoryImpl::createDefExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::DefExpImpl> element(new ocl::Expressions::DefExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisDefExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::DefExp> ExpressionsFactoryImpl::createDefExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::DefExpImpl> element(new ocl::Expressions::DefExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisDefExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::DefExp> ExpressionsFactoryImpl::createDefExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::DefExpImpl> element(new ocl::Expressions::DefExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisDefExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::DefExp> ExpressionsFactoryImpl::createDefExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::DefExpImpl> element(new ocl::Expressions::DefExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisDefExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::DefExp> ExpressionsFactoryImpl::createDefExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::DefExpImpl> element(new ocl::Expressions::DefExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisDefExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::DefExp> ExpressionsFactoryImpl::createDefExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::DefExpImpl> element(new ocl::Expressions::DefExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisDefExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::DefExp> ExpressionsFactoryImpl::createDefExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::DefExpImpl> element(new ocl::Expressions::DefExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisDefExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::DefExp> ExpressionsFactoryImpl::createDefExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::DefExpImpl> element(new ocl::Expressions::DefExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisDefExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::DefExp> ExpressionsFactoryImpl::createDefExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::DefExpImpl> element(new ocl::Expressions::DefExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisDefExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::DefExp> ExpressionsFactoryImpl::createDefExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::DefExpImpl> element(new ocl::Expressions::DefExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisDefExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::DefExp> ExpressionsFactoryImpl::createDefExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::DefExpImpl> element(new ocl::Expressions::DefExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisDefExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::DefExp> ExpressionsFactoryImpl::createDefExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::DefExpImpl> element(new ocl::Expressions::DefExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisDefExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::DefExp> ExpressionsFactoryImpl::createDefExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::DefExpImpl> element(new ocl::Expressions::DefExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisDefExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEnumLiteralExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisEnumLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisEnumLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisEnumLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisEnumLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisEnumLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisEnumLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisEnumLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisEnumLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisEnumLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisEnumLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisEnumLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisEnumLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisEnumLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisEnumLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisEnumLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisEnumLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisEnumLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisEnumLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ExpressionInOcl> ExpressionsFactoryImpl::createExpressionInOcl(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::ExpressionInOclImpl> element(new ocl::Expressions::ExpressionInOclImpl());
	element->setMetaElementID(metaElementID);
	element->setThisExpressionInOclPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::ExpressionInOcl> ExpressionsFactoryImpl::createExpressionInOcl_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ExpressionInOclImpl> element(new ocl::Expressions::ExpressionInOclImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisExpressionInOclPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ExpressionInOcl> ExpressionsFactoryImpl::createExpressionInOcl_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ExpressionInOclImpl> element(new ocl::Expressions::ExpressionInOclImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisExpressionInOclPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ExpressionInOcl> ExpressionsFactoryImpl::createExpressionInOcl_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ExpressionInOclImpl> element(new ocl::Expressions::ExpressionInOclImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisExpressionInOclPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ExpressionInOcl> ExpressionsFactoryImpl::createExpressionInOcl_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ExpressionInOclImpl> element(new ocl::Expressions::ExpressionInOclImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisExpressionInOclPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisIfExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisIfExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisIfExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisIfExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisIfExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisIfExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisIfExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisIfExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisIfExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisIfExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisIfExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisIfExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisIfExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisIfExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisIfExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisIfExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisIfExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisIfExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisIfExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisInfixedExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisInfixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisInfixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisInfixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisInfixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisInfixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisInfixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisInfixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisInfixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisInfixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisInfixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisInfixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisInfixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisInfixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisInfixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisInfixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisInfixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisInfixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisInfixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InitOrDerValueExp> ExpressionsFactoryImpl::createInitOrDerValueExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::InitOrDerValueExpImpl> element(new ocl::Expressions::InitOrDerValueExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisInitOrDerValueExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::InitOrDerValueExp> ExpressionsFactoryImpl::createInitOrDerValueExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InitOrDerValueExpImpl> element(new ocl::Expressions::InitOrDerValueExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisInitOrDerValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InitOrDerValueExp> ExpressionsFactoryImpl::createInitOrDerValueExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InitOrDerValueExpImpl> element(new ocl::Expressions::InitOrDerValueExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisInitOrDerValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InitOrDerValueExp> ExpressionsFactoryImpl::createInitOrDerValueExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InitOrDerValueExpImpl> element(new ocl::Expressions::InitOrDerValueExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisInitOrDerValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InitOrDerValueExp> ExpressionsFactoryImpl::createInitOrDerValueExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InitOrDerValueExpImpl> element(new ocl::Expressions::InitOrDerValueExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisInitOrDerValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InitOrDerValueListExp> ExpressionsFactoryImpl::createInitOrDerValueListExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::InitOrDerValueListExpImpl> element(new ocl::Expressions::InitOrDerValueListExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisInitOrDerValueListExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::InitOrDerValueListExp> ExpressionsFactoryImpl::createInitOrDerValueListExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InitOrDerValueListExpImpl> element(new ocl::Expressions::InitOrDerValueListExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisInitOrDerValueListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InitOrDerValueListExp> ExpressionsFactoryImpl::createInitOrDerValueListExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InitOrDerValueListExpImpl> element(new ocl::Expressions::InitOrDerValueListExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisInitOrDerValueListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InitOrDerValueListExp> ExpressionsFactoryImpl::createInitOrDerValueListExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InitOrDerValueListExpImpl> element(new ocl::Expressions::InitOrDerValueListExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisInitOrDerValueListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InitOrDerValueListExp> ExpressionsFactoryImpl::createInitOrDerValueListExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InitOrDerValueListExpImpl> element(new ocl::Expressions::InitOrDerValueListExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisInitOrDerValueListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InitOrDerValueListExp> ExpressionsFactoryImpl::createInitOrDerValueListExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InitOrDerValueListExpImpl> element(new ocl::Expressions::InitOrDerValueListExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisInitOrDerValueListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InitOrDerValueListExp> ExpressionsFactoryImpl::createInitOrDerValueListExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InitOrDerValueListExpImpl> element(new ocl::Expressions::InitOrDerValueListExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisInitOrDerValueListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InitOrDerValueListExp> ExpressionsFactoryImpl::createInitOrDerValueListExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InitOrDerValueListExpImpl> element(new ocl::Expressions::InitOrDerValueListExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisInitOrDerValueListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InitOrDerValueListExp> ExpressionsFactoryImpl::createInitOrDerValueListExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InitOrDerValueListExpImpl> element(new ocl::Expressions::InitOrDerValueListExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisInitOrDerValueListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InitOrDerValueListExp> ExpressionsFactoryImpl::createInitOrDerValueListExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InitOrDerValueListExpImpl> element(new ocl::Expressions::InitOrDerValueListExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisInitOrDerValueListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InitOrDerValueListExp> ExpressionsFactoryImpl::createInitOrDerValueListExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InitOrDerValueListExpImpl> element(new ocl::Expressions::InitOrDerValueListExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisInitOrDerValueListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InitOrDerValueListExp> ExpressionsFactoryImpl::createInitOrDerValueListExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InitOrDerValueListExpImpl> element(new ocl::Expressions::InitOrDerValueListExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisInitOrDerValueListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InitOrDerValueListExp> ExpressionsFactoryImpl::createInitOrDerValueListExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InitOrDerValueListExpImpl> element(new ocl::Expressions::InitOrDerValueListExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisInitOrDerValueListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InitOrDerValueListExp> ExpressionsFactoryImpl::createInitOrDerValueListExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InitOrDerValueListExpImpl> element(new ocl::Expressions::InitOrDerValueListExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisInitOrDerValueListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InitOrDerValueListExp> ExpressionsFactoryImpl::createInitOrDerValueListExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InitOrDerValueListExpImpl> element(new ocl::Expressions::InitOrDerValueListExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisInitOrDerValueListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InitOrDerValueListExp> ExpressionsFactoryImpl::createInitOrDerValueListExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InitOrDerValueListExpImpl> element(new ocl::Expressions::InitOrDerValueListExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisInitOrDerValueListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InitOrDerValueListExp> ExpressionsFactoryImpl::createInitOrDerValueListExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InitOrDerValueListExpImpl> element(new ocl::Expressions::InitOrDerValueListExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisInitOrDerValueListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InitOrDerValueListExp> ExpressionsFactoryImpl::createInitOrDerValueListExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InitOrDerValueListExpImpl> element(new ocl::Expressions::InitOrDerValueListExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisInitOrDerValueListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InitOrDerValueListExp> ExpressionsFactoryImpl::createInitOrDerValueListExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InitOrDerValueListExpImpl> element(new ocl::Expressions::InitOrDerValueListExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisInitOrDerValueListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisIntegerLiteralExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisIntegerLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisIntegerLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisIntegerLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisIntegerLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisIntegerLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisIntegerLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisIntegerLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisIntegerLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisIntegerLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisIntegerLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisIntegerLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisIntegerLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisIntegerLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisIntegerLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisIntegerLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisIntegerLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisIntegerLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisIntegerLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InvOrDefExp> ExpressionsFactoryImpl::createInvOrDefExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::InvOrDefExpImpl> element(new ocl::Expressions::InvOrDefExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisInvOrDefExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::InvOrDefExp> ExpressionsFactoryImpl::createInvOrDefExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvOrDefExpImpl> element(new ocl::Expressions::InvOrDefExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisInvOrDefExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InvOrDefExp> ExpressionsFactoryImpl::createInvOrDefExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvOrDefExpImpl> element(new ocl::Expressions::InvOrDefExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisInvOrDefExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InvOrDefExp> ExpressionsFactoryImpl::createInvOrDefExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvOrDefExpImpl> element(new ocl::Expressions::InvOrDefExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisInvOrDefExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InvOrDefExp> ExpressionsFactoryImpl::createInvOrDefExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvOrDefExpImpl> element(new ocl::Expressions::InvOrDefExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisInvOrDefExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisInvalidLiteralExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisInvalidLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisInvalidLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisInvalidLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisInvalidLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisInvalidLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisInvalidLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisInvalidLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisInvalidLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisInvalidLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisInvalidLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisInvalidLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisInvalidLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisInvalidLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisInvalidLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisInvalidLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisInvalidLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisInvalidLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisInvalidLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisIterateExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisIterateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisIterateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisIterateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisIterateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisIterateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisIterateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisIterateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisIterateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisIterateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisIterateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisIterateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisIterateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisIterateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisIterateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisIterateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisIterateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisIterateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisIterateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisIteratorExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisIteratorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisIteratorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisIteratorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisIteratorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisIteratorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisIteratorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisIteratorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisIteratorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisIteratorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisIteratorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisIteratorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisIteratorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisIteratorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisIteratorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisIteratorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisIteratorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisIteratorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisIteratorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLetExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisLetExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisLetExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisLetExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisLetExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisLetExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisLetExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisLetExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisLetExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisLetExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisLetExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisLetExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisLetExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisLetExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisLetExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisLetExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisLetExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisLetExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisLetExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::MessageArguments> ExpressionsFactoryImpl::createMessageArguments(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::MessageArgumentsImpl> element(new ocl::Expressions::MessageArgumentsImpl());
	element->setMetaElementID(metaElementID);
	element->setThisMessageArgumentsPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::MessageArguments> ExpressionsFactoryImpl::createMessageArguments_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageArgumentsImpl> element(new ocl::Expressions::MessageArgumentsImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisMessageArgumentsPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::MessageArguments> ExpressionsFactoryImpl::createMessageArguments_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageArgumentsImpl> element(new ocl::Expressions::MessageArgumentsImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisMessageArgumentsPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::MessageArguments> ExpressionsFactoryImpl::createMessageArguments_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageArgumentsImpl> element(new ocl::Expressions::MessageArgumentsImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisMessageArgumentsPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::MessageArguments> ExpressionsFactoryImpl::createMessageArguments_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageArgumentsImpl> element(new ocl::Expressions::MessageArgumentsImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisMessageArgumentsPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisMessageExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisMessageExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisMessageExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisMessageExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisMessageExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisMessageExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisMessageExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisMessageExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisMessageExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisMessageExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisMessageExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisMessageExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisMessageExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisMessageExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisMessageExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisMessageExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisMessageExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisMessageExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisMessageExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisNullLiteralExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisNullLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisNullLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisNullLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisNullLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisNullLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisNullLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisNullLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisNullLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisNullLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisNullLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisNullLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisNullLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisNullLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisNullLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisNullLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisNullLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisNullLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisNullLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisOperationCallExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisOperationCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisOperationCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisOperationCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisOperationCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisOperationCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisOperationCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisOperationCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisOperationCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisOperationCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisOperationCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisOperationCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisOperationCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisOperationCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisOperationCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisOperationCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisOperationCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisOperationCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisOperationCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextDeclExp> ExpressionsFactoryImpl::createOperationContextDeclExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::OperationContextDeclExpImpl> element(new ocl::Expressions::OperationContextDeclExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisOperationContextDeclExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::OperationContextDeclExp> ExpressionsFactoryImpl::createOperationContextDeclExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextDeclExpImpl> element(new ocl::Expressions::OperationContextDeclExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisOperationContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextDeclExp> ExpressionsFactoryImpl::createOperationContextDeclExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextDeclExpImpl> element(new ocl::Expressions::OperationContextDeclExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisOperationContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextDeclExp> ExpressionsFactoryImpl::createOperationContextDeclExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextDeclExpImpl> element(new ocl::Expressions::OperationContextDeclExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisOperationContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextDeclExp> ExpressionsFactoryImpl::createOperationContextDeclExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextDeclExpImpl> element(new ocl::Expressions::OperationContextDeclExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisOperationContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextDeclExp> ExpressionsFactoryImpl::createOperationContextDeclExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextDeclExpImpl> element(new ocl::Expressions::OperationContextDeclExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisOperationContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextDeclExp> ExpressionsFactoryImpl::createOperationContextDeclExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextDeclExpImpl> element(new ocl::Expressions::OperationContextDeclExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisOperationContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextDeclExp> ExpressionsFactoryImpl::createOperationContextDeclExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextDeclExpImpl> element(new ocl::Expressions::OperationContextDeclExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisOperationContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextDeclExp> ExpressionsFactoryImpl::createOperationContextDeclExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextDeclExpImpl> element(new ocl::Expressions::OperationContextDeclExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisOperationContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextDeclExp> ExpressionsFactoryImpl::createOperationContextDeclExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextDeclExpImpl> element(new ocl::Expressions::OperationContextDeclExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisOperationContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextDeclExp> ExpressionsFactoryImpl::createOperationContextDeclExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextDeclExpImpl> element(new ocl::Expressions::OperationContextDeclExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisOperationContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextDeclExp> ExpressionsFactoryImpl::createOperationContextDeclExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextDeclExpImpl> element(new ocl::Expressions::OperationContextDeclExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisOperationContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextDeclExp> ExpressionsFactoryImpl::createOperationContextDeclExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextDeclExpImpl> element(new ocl::Expressions::OperationContextDeclExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisOperationContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextDeclExp> ExpressionsFactoryImpl::createOperationContextDeclExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextDeclExpImpl> element(new ocl::Expressions::OperationContextDeclExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisOperationContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextDeclExp> ExpressionsFactoryImpl::createOperationContextDeclExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextDeclExpImpl> element(new ocl::Expressions::OperationContextDeclExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisOperationContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextDeclExp> ExpressionsFactoryImpl::createOperationContextDeclExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextDeclExpImpl> element(new ocl::Expressions::OperationContextDeclExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisOperationContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextDeclExp> ExpressionsFactoryImpl::createOperationContextDeclExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextDeclExpImpl> element(new ocl::Expressions::OperationContextDeclExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisOperationContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextDeclExp> ExpressionsFactoryImpl::createOperationContextDeclExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextDeclExpImpl> element(new ocl::Expressions::OperationContextDeclExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisOperationContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextDeclExp> ExpressionsFactoryImpl::createOperationContextDeclExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextDeclExpImpl> element(new ocl::Expressions::OperationContextDeclExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisOperationContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextExp> ExpressionsFactoryImpl::createOperationContextExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::OperationContextExpImpl> element(new ocl::Expressions::OperationContextExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisOperationContextExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::OperationContextExp> ExpressionsFactoryImpl::createOperationContextExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextExpImpl> element(new ocl::Expressions::OperationContextExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisOperationContextExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextExp> ExpressionsFactoryImpl::createOperationContextExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextExpImpl> element(new ocl::Expressions::OperationContextExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisOperationContextExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextExp> ExpressionsFactoryImpl::createOperationContextExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextExpImpl> element(new ocl::Expressions::OperationContextExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisOperationContextExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextExp> ExpressionsFactoryImpl::createOperationContextExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextExpImpl> element(new ocl::Expressions::OperationContextExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisOperationContextExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextExp> ExpressionsFactoryImpl::createOperationContextExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextExpImpl> element(new ocl::Expressions::OperationContextExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisOperationContextExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextExp> ExpressionsFactoryImpl::createOperationContextExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextExpImpl> element(new ocl::Expressions::OperationContextExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisOperationContextExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextExp> ExpressionsFactoryImpl::createOperationContextExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextExpImpl> element(new ocl::Expressions::OperationContextExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisOperationContextExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextExp> ExpressionsFactoryImpl::createOperationContextExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextExpImpl> element(new ocl::Expressions::OperationContextExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisOperationContextExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextExp> ExpressionsFactoryImpl::createOperationContextExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextExpImpl> element(new ocl::Expressions::OperationContextExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisOperationContextExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextExp> ExpressionsFactoryImpl::createOperationContextExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextExpImpl> element(new ocl::Expressions::OperationContextExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisOperationContextExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextExp> ExpressionsFactoryImpl::createOperationContextExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextExpImpl> element(new ocl::Expressions::OperationContextExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisOperationContextExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextExp> ExpressionsFactoryImpl::createOperationContextExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextExpImpl> element(new ocl::Expressions::OperationContextExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisOperationContextExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextExp> ExpressionsFactoryImpl::createOperationContextExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextExpImpl> element(new ocl::Expressions::OperationContextExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisOperationContextExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextExp> ExpressionsFactoryImpl::createOperationContextExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextExpImpl> element(new ocl::Expressions::OperationContextExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisOperationContextExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextExp> ExpressionsFactoryImpl::createOperationContextExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextExpImpl> element(new ocl::Expressions::OperationContextExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisOperationContextExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextExp> ExpressionsFactoryImpl::createOperationContextExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextExpImpl> element(new ocl::Expressions::OperationContextExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisOperationContextExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextExp> ExpressionsFactoryImpl::createOperationContextExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextExpImpl> element(new ocl::Expressions::OperationContextExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisOperationContextExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationContextExp> ExpressionsFactoryImpl::createOperationContextExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationContextExpImpl> element(new ocl::Expressions::OperationContextExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisOperationContextExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperatorExp> ExpressionsFactoryImpl::createOperatorExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::OperatorExpImpl> element(new ocl::Expressions::OperatorExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisOperatorExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::OperatorExp> ExpressionsFactoryImpl::createOperatorExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperatorExpImpl> element(new ocl::Expressions::OperatorExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisOperatorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperatorExp> ExpressionsFactoryImpl::createOperatorExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperatorExpImpl> element(new ocl::Expressions::OperatorExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisOperatorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperatorExp> ExpressionsFactoryImpl::createOperatorExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperatorExpImpl> element(new ocl::Expressions::OperatorExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisOperatorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperatorExp> ExpressionsFactoryImpl::createOperatorExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperatorExpImpl> element(new ocl::Expressions::OperatorExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisOperatorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperatorExp> ExpressionsFactoryImpl::createOperatorExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperatorExpImpl> element(new ocl::Expressions::OperatorExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisOperatorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperatorExp> ExpressionsFactoryImpl::createOperatorExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperatorExpImpl> element(new ocl::Expressions::OperatorExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisOperatorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperatorExp> ExpressionsFactoryImpl::createOperatorExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperatorExpImpl> element(new ocl::Expressions::OperatorExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisOperatorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperatorExp> ExpressionsFactoryImpl::createOperatorExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperatorExpImpl> element(new ocl::Expressions::OperatorExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisOperatorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperatorExp> ExpressionsFactoryImpl::createOperatorExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperatorExpImpl> element(new ocl::Expressions::OperatorExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisOperatorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperatorExp> ExpressionsFactoryImpl::createOperatorExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperatorExpImpl> element(new ocl::Expressions::OperatorExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisOperatorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperatorExp> ExpressionsFactoryImpl::createOperatorExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperatorExpImpl> element(new ocl::Expressions::OperatorExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisOperatorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperatorExp> ExpressionsFactoryImpl::createOperatorExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperatorExpImpl> element(new ocl::Expressions::OperatorExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisOperatorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperatorExp> ExpressionsFactoryImpl::createOperatorExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperatorExpImpl> element(new ocl::Expressions::OperatorExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisOperatorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperatorExp> ExpressionsFactoryImpl::createOperatorExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperatorExpImpl> element(new ocl::Expressions::OperatorExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisOperatorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperatorExp> ExpressionsFactoryImpl::createOperatorExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperatorExpImpl> element(new ocl::Expressions::OperatorExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisOperatorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperatorExp> ExpressionsFactoryImpl::createOperatorExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperatorExpImpl> element(new ocl::Expressions::OperatorExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisOperatorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperatorExp> ExpressionsFactoryImpl::createOperatorExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperatorExpImpl> element(new ocl::Expressions::OperatorExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisOperatorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperatorExp> ExpressionsFactoryImpl::createOperatorExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperatorExpImpl> element(new ocl::Expressions::OperatorExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisOperatorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PackageDeclarationExp> ExpressionsFactoryImpl::createPackageDeclarationExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::PackageDeclarationExpImpl> element(new ocl::Expressions::PackageDeclarationExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisPackageDeclarationExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::PackageDeclarationExp> ExpressionsFactoryImpl::createPackageDeclarationExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PackageDeclarationExpImpl> element(new ocl::Expressions::PackageDeclarationExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisPackageDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PackageDeclarationExp> ExpressionsFactoryImpl::createPackageDeclarationExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PackageDeclarationExpImpl> element(new ocl::Expressions::PackageDeclarationExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisPackageDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PackageDeclarationExp> ExpressionsFactoryImpl::createPackageDeclarationExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PackageDeclarationExpImpl> element(new ocl::Expressions::PackageDeclarationExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisPackageDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PackageDeclarationExp> ExpressionsFactoryImpl::createPackageDeclarationExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PackageDeclarationExpImpl> element(new ocl::Expressions::PackageDeclarationExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisPackageDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PackageDeclarationExp> ExpressionsFactoryImpl::createPackageDeclarationExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PackageDeclarationExpImpl> element(new ocl::Expressions::PackageDeclarationExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisPackageDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PackageDeclarationExp> ExpressionsFactoryImpl::createPackageDeclarationExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PackageDeclarationExpImpl> element(new ocl::Expressions::PackageDeclarationExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisPackageDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PackageDeclarationExp> ExpressionsFactoryImpl::createPackageDeclarationExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PackageDeclarationExpImpl> element(new ocl::Expressions::PackageDeclarationExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisPackageDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PackageDeclarationExp> ExpressionsFactoryImpl::createPackageDeclarationExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PackageDeclarationExpImpl> element(new ocl::Expressions::PackageDeclarationExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisPackageDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PackageDeclarationExp> ExpressionsFactoryImpl::createPackageDeclarationExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PackageDeclarationExpImpl> element(new ocl::Expressions::PackageDeclarationExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisPackageDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PackageDeclarationExp> ExpressionsFactoryImpl::createPackageDeclarationExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PackageDeclarationExpImpl> element(new ocl::Expressions::PackageDeclarationExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisPackageDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PackageDeclarationExp> ExpressionsFactoryImpl::createPackageDeclarationExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PackageDeclarationExpImpl> element(new ocl::Expressions::PackageDeclarationExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisPackageDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PackageDeclarationExp> ExpressionsFactoryImpl::createPackageDeclarationExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PackageDeclarationExpImpl> element(new ocl::Expressions::PackageDeclarationExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisPackageDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PackageDeclarationExp> ExpressionsFactoryImpl::createPackageDeclarationExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PackageDeclarationExpImpl> element(new ocl::Expressions::PackageDeclarationExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisPackageDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PackageDeclarationExp> ExpressionsFactoryImpl::createPackageDeclarationExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PackageDeclarationExpImpl> element(new ocl::Expressions::PackageDeclarationExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisPackageDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PackageDeclarationExp> ExpressionsFactoryImpl::createPackageDeclarationExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PackageDeclarationExpImpl> element(new ocl::Expressions::PackageDeclarationExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisPackageDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PackageDeclarationExp> ExpressionsFactoryImpl::createPackageDeclarationExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PackageDeclarationExpImpl> element(new ocl::Expressions::PackageDeclarationExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisPackageDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PackageDeclarationExp> ExpressionsFactoryImpl::createPackageDeclarationExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PackageDeclarationExpImpl> element(new ocl::Expressions::PackageDeclarationExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisPackageDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PackageDeclarationExp> ExpressionsFactoryImpl::createPackageDeclarationExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PackageDeclarationExpImpl> element(new ocl::Expressions::PackageDeclarationExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisPackageDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ParentedExp> ExpressionsFactoryImpl::createParentedExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::ParentedExpImpl> element(new ocl::Expressions::ParentedExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisParentedExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::ParentedExp> ExpressionsFactoryImpl::createParentedExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ParentedExpImpl> element(new ocl::Expressions::ParentedExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisParentedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ParentedExp> ExpressionsFactoryImpl::createParentedExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ParentedExpImpl> element(new ocl::Expressions::ParentedExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisParentedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ParentedExp> ExpressionsFactoryImpl::createParentedExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ParentedExpImpl> element(new ocl::Expressions::ParentedExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisParentedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ParentedExp> ExpressionsFactoryImpl::createParentedExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ParentedExpImpl> element(new ocl::Expressions::ParentedExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisParentedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ParentedExp> ExpressionsFactoryImpl::createParentedExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ParentedExpImpl> element(new ocl::Expressions::ParentedExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisParentedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ParentedExp> ExpressionsFactoryImpl::createParentedExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ParentedExpImpl> element(new ocl::Expressions::ParentedExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisParentedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ParentedExp> ExpressionsFactoryImpl::createParentedExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ParentedExpImpl> element(new ocl::Expressions::ParentedExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisParentedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ParentedExp> ExpressionsFactoryImpl::createParentedExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ParentedExpImpl> element(new ocl::Expressions::ParentedExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisParentedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ParentedExp> ExpressionsFactoryImpl::createParentedExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ParentedExpImpl> element(new ocl::Expressions::ParentedExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisParentedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ParentedExp> ExpressionsFactoryImpl::createParentedExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ParentedExpImpl> element(new ocl::Expressions::ParentedExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisParentedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ParentedExp> ExpressionsFactoryImpl::createParentedExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ParentedExpImpl> element(new ocl::Expressions::ParentedExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisParentedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ParentedExp> ExpressionsFactoryImpl::createParentedExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ParentedExpImpl> element(new ocl::Expressions::ParentedExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisParentedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ParentedExp> ExpressionsFactoryImpl::createParentedExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ParentedExpImpl> element(new ocl::Expressions::ParentedExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisParentedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ParentedExp> ExpressionsFactoryImpl::createParentedExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ParentedExpImpl> element(new ocl::Expressions::ParentedExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisParentedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ParentedExp> ExpressionsFactoryImpl::createParentedExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ParentedExpImpl> element(new ocl::Expressions::ParentedExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisParentedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ParentedExp> ExpressionsFactoryImpl::createParentedExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ParentedExpImpl> element(new ocl::Expressions::ParentedExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisParentedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ParentedExp> ExpressionsFactoryImpl::createParentedExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ParentedExpImpl> element(new ocl::Expressions::ParentedExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisParentedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::ParentedExp> ExpressionsFactoryImpl::createParentedExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::ParentedExpImpl> element(new ocl::Expressions::ParentedExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisParentedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrePostBodyExp> ExpressionsFactoryImpl::createPrePostBodyExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::PrePostBodyExpImpl> element(new ocl::Expressions::PrePostBodyExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisPrePostBodyExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::PrePostBodyExp> ExpressionsFactoryImpl::createPrePostBodyExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrePostBodyExpImpl> element(new ocl::Expressions::PrePostBodyExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisPrePostBodyExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrePostBodyExp> ExpressionsFactoryImpl::createPrePostBodyExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrePostBodyExpImpl> element(new ocl::Expressions::PrePostBodyExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisPrePostBodyExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrePostBodyExp> ExpressionsFactoryImpl::createPrePostBodyExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrePostBodyExpImpl> element(new ocl::Expressions::PrePostBodyExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisPrePostBodyExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrePostBodyExp> ExpressionsFactoryImpl::createPrePostBodyExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrePostBodyExpImpl> element(new ocl::Expressions::PrePostBodyExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisPrePostBodyExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrePostBodyListExp> ExpressionsFactoryImpl::createPrePostBodyListExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::PrePostBodyListExpImpl> element(new ocl::Expressions::PrePostBodyListExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisPrePostBodyListExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::PrePostBodyListExp> ExpressionsFactoryImpl::createPrePostBodyListExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrePostBodyListExpImpl> element(new ocl::Expressions::PrePostBodyListExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisPrePostBodyListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrePostBodyListExp> ExpressionsFactoryImpl::createPrePostBodyListExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrePostBodyListExpImpl> element(new ocl::Expressions::PrePostBodyListExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisPrePostBodyListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrePostBodyListExp> ExpressionsFactoryImpl::createPrePostBodyListExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrePostBodyListExpImpl> element(new ocl::Expressions::PrePostBodyListExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisPrePostBodyListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrePostBodyListExp> ExpressionsFactoryImpl::createPrePostBodyListExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrePostBodyListExpImpl> element(new ocl::Expressions::PrePostBodyListExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisPrePostBodyListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrePostBodyListExp> ExpressionsFactoryImpl::createPrePostBodyListExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrePostBodyListExpImpl> element(new ocl::Expressions::PrePostBodyListExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisPrePostBodyListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrePostBodyListExp> ExpressionsFactoryImpl::createPrePostBodyListExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrePostBodyListExpImpl> element(new ocl::Expressions::PrePostBodyListExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisPrePostBodyListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrePostBodyListExp> ExpressionsFactoryImpl::createPrePostBodyListExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrePostBodyListExpImpl> element(new ocl::Expressions::PrePostBodyListExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisPrePostBodyListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrePostBodyListExp> ExpressionsFactoryImpl::createPrePostBodyListExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrePostBodyListExpImpl> element(new ocl::Expressions::PrePostBodyListExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisPrePostBodyListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrePostBodyListExp> ExpressionsFactoryImpl::createPrePostBodyListExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrePostBodyListExpImpl> element(new ocl::Expressions::PrePostBodyListExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisPrePostBodyListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrePostBodyListExp> ExpressionsFactoryImpl::createPrePostBodyListExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrePostBodyListExpImpl> element(new ocl::Expressions::PrePostBodyListExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisPrePostBodyListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrePostBodyListExp> ExpressionsFactoryImpl::createPrePostBodyListExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrePostBodyListExpImpl> element(new ocl::Expressions::PrePostBodyListExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisPrePostBodyListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrePostBodyListExp> ExpressionsFactoryImpl::createPrePostBodyListExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrePostBodyListExpImpl> element(new ocl::Expressions::PrePostBodyListExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisPrePostBodyListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrePostBodyListExp> ExpressionsFactoryImpl::createPrePostBodyListExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrePostBodyListExpImpl> element(new ocl::Expressions::PrePostBodyListExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisPrePostBodyListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrePostBodyListExp> ExpressionsFactoryImpl::createPrePostBodyListExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrePostBodyListExpImpl> element(new ocl::Expressions::PrePostBodyListExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisPrePostBodyListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrePostBodyListExp> ExpressionsFactoryImpl::createPrePostBodyListExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrePostBodyListExpImpl> element(new ocl::Expressions::PrePostBodyListExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisPrePostBodyListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrePostBodyListExp> ExpressionsFactoryImpl::createPrePostBodyListExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrePostBodyListExpImpl> element(new ocl::Expressions::PrePostBodyListExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisPrePostBodyListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrePostBodyListExp> ExpressionsFactoryImpl::createPrePostBodyListExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrePostBodyListExpImpl> element(new ocl::Expressions::PrePostBodyListExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisPrePostBodyListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrePostBodyListExp> ExpressionsFactoryImpl::createPrePostBodyListExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrePostBodyListExpImpl> element(new ocl::Expressions::PrePostBodyListExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisPrePostBodyListExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrefixedExp> ExpressionsFactoryImpl::createPrefixedExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::PrefixedExpImpl> element(new ocl::Expressions::PrefixedExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisPrefixedExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::PrefixedExp> ExpressionsFactoryImpl::createPrefixedExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrefixedExpImpl> element(new ocl::Expressions::PrefixedExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisPrefixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrefixedExp> ExpressionsFactoryImpl::createPrefixedExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrefixedExpImpl> element(new ocl::Expressions::PrefixedExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisPrefixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrefixedExp> ExpressionsFactoryImpl::createPrefixedExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrefixedExpImpl> element(new ocl::Expressions::PrefixedExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisPrefixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrefixedExp> ExpressionsFactoryImpl::createPrefixedExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrefixedExpImpl> element(new ocl::Expressions::PrefixedExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisPrefixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrefixedExp> ExpressionsFactoryImpl::createPrefixedExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrefixedExpImpl> element(new ocl::Expressions::PrefixedExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisPrefixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrefixedExp> ExpressionsFactoryImpl::createPrefixedExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrefixedExpImpl> element(new ocl::Expressions::PrefixedExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisPrefixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrefixedExp> ExpressionsFactoryImpl::createPrefixedExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrefixedExpImpl> element(new ocl::Expressions::PrefixedExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisPrefixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrefixedExp> ExpressionsFactoryImpl::createPrefixedExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrefixedExpImpl> element(new ocl::Expressions::PrefixedExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisPrefixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrefixedExp> ExpressionsFactoryImpl::createPrefixedExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrefixedExpImpl> element(new ocl::Expressions::PrefixedExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisPrefixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrefixedExp> ExpressionsFactoryImpl::createPrefixedExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrefixedExpImpl> element(new ocl::Expressions::PrefixedExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisPrefixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrefixedExp> ExpressionsFactoryImpl::createPrefixedExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrefixedExpImpl> element(new ocl::Expressions::PrefixedExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisPrefixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrefixedExp> ExpressionsFactoryImpl::createPrefixedExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrefixedExpImpl> element(new ocl::Expressions::PrefixedExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisPrefixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrefixedExp> ExpressionsFactoryImpl::createPrefixedExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrefixedExpImpl> element(new ocl::Expressions::PrefixedExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisPrefixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrefixedExp> ExpressionsFactoryImpl::createPrefixedExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrefixedExpImpl> element(new ocl::Expressions::PrefixedExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisPrefixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrefixedExp> ExpressionsFactoryImpl::createPrefixedExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrefixedExpImpl> element(new ocl::Expressions::PrefixedExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisPrefixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrefixedExp> ExpressionsFactoryImpl::createPrefixedExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrefixedExpImpl> element(new ocl::Expressions::PrefixedExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisPrefixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrefixedExp> ExpressionsFactoryImpl::createPrefixedExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrefixedExpImpl> element(new ocl::Expressions::PrefixedExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisPrefixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PrefixedExp> ExpressionsFactoryImpl::createPrefixedExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PrefixedExpImpl> element(new ocl::Expressions::PrefixedExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisPrefixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisPropertyCallExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisPropertyCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisPropertyCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisPropertyCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisPropertyCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisPropertyCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisPropertyCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisPropertyCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisPropertyCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisPropertyCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisPropertyCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisPropertyCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisPropertyCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisPropertyCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisPropertyCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisPropertyCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisPropertyCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisPropertyCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisPropertyCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyContextDeclExp> ExpressionsFactoryImpl::createPropertyContextDeclExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::PropertyContextDeclExpImpl> element(new ocl::Expressions::PropertyContextDeclExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisPropertyContextDeclExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::PropertyContextDeclExp> ExpressionsFactoryImpl::createPropertyContextDeclExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyContextDeclExpImpl> element(new ocl::Expressions::PropertyContextDeclExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisPropertyContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyContextDeclExp> ExpressionsFactoryImpl::createPropertyContextDeclExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyContextDeclExpImpl> element(new ocl::Expressions::PropertyContextDeclExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisPropertyContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyContextDeclExp> ExpressionsFactoryImpl::createPropertyContextDeclExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyContextDeclExpImpl> element(new ocl::Expressions::PropertyContextDeclExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisPropertyContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyContextDeclExp> ExpressionsFactoryImpl::createPropertyContextDeclExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyContextDeclExpImpl> element(new ocl::Expressions::PropertyContextDeclExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisPropertyContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyContextDeclExp> ExpressionsFactoryImpl::createPropertyContextDeclExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyContextDeclExpImpl> element(new ocl::Expressions::PropertyContextDeclExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisPropertyContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyContextDeclExp> ExpressionsFactoryImpl::createPropertyContextDeclExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyContextDeclExpImpl> element(new ocl::Expressions::PropertyContextDeclExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisPropertyContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyContextDeclExp> ExpressionsFactoryImpl::createPropertyContextDeclExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyContextDeclExpImpl> element(new ocl::Expressions::PropertyContextDeclExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisPropertyContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyContextDeclExp> ExpressionsFactoryImpl::createPropertyContextDeclExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyContextDeclExpImpl> element(new ocl::Expressions::PropertyContextDeclExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisPropertyContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyContextDeclExp> ExpressionsFactoryImpl::createPropertyContextDeclExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyContextDeclExpImpl> element(new ocl::Expressions::PropertyContextDeclExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisPropertyContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyContextDeclExp> ExpressionsFactoryImpl::createPropertyContextDeclExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyContextDeclExpImpl> element(new ocl::Expressions::PropertyContextDeclExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisPropertyContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyContextDeclExp> ExpressionsFactoryImpl::createPropertyContextDeclExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyContextDeclExpImpl> element(new ocl::Expressions::PropertyContextDeclExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisPropertyContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyContextDeclExp> ExpressionsFactoryImpl::createPropertyContextDeclExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyContextDeclExpImpl> element(new ocl::Expressions::PropertyContextDeclExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisPropertyContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyContextDeclExp> ExpressionsFactoryImpl::createPropertyContextDeclExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyContextDeclExpImpl> element(new ocl::Expressions::PropertyContextDeclExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisPropertyContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyContextDeclExp> ExpressionsFactoryImpl::createPropertyContextDeclExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyContextDeclExpImpl> element(new ocl::Expressions::PropertyContextDeclExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisPropertyContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyContextDeclExp> ExpressionsFactoryImpl::createPropertyContextDeclExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyContextDeclExpImpl> element(new ocl::Expressions::PropertyContextDeclExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisPropertyContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyContextDeclExp> ExpressionsFactoryImpl::createPropertyContextDeclExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyContextDeclExpImpl> element(new ocl::Expressions::PropertyContextDeclExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisPropertyContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyContextDeclExp> ExpressionsFactoryImpl::createPropertyContextDeclExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyContextDeclExpImpl> element(new ocl::Expressions::PropertyContextDeclExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisPropertyContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyContextDeclExp> ExpressionsFactoryImpl::createPropertyContextDeclExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyContextDeclExpImpl> element(new ocl::Expressions::PropertyContextDeclExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisPropertyContextDeclExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisRealLiteralExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisRealLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisRealLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisRealLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisRealLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisRealLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisRealLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisRealLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisRealLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisRealLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisRealLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisRealLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisRealLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisRealLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisRealLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisRealLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisRealLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisRealLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisRealLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisStateExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisStateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisStateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisStateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisStateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisStateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisStateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisStateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisStateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisStateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisStateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisStateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisStateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisStateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisStateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisStateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisStateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisStateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisStateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisStringLiteralExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisStringLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisStringLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisStringLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisStringLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisStringLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisStringLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisStringLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisStringLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisStringLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisStringLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisStringLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisStringLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisStringLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisStringLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisStringLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisStringLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisStringLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisStringLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisTupleLiteralExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisTupleLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisTupleLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisTupleLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisTupleLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisTupleLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisTupleLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisTupleLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisTupleLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisTupleLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisTupleLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisTupleLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisTupleLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisTupleLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisTupleLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisTupleLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisTupleLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisTupleLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisTupleLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleLiteralPart> ExpressionsFactoryImpl::createTupleLiteralPart(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralPartImpl> element(new ocl::Expressions::TupleLiteralPartImpl());
	element->setMetaElementID(metaElementID);
	element->setThisTupleLiteralPartPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::TupleLiteralPart> ExpressionsFactoryImpl::createTupleLiteralPart_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralPartImpl> element(new ocl::Expressions::TupleLiteralPartImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisTupleLiteralPartPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleLiteralPart> ExpressionsFactoryImpl::createTupleLiteralPart_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralPartImpl> element(new ocl::Expressions::TupleLiteralPartImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisTupleLiteralPartPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleLiteralPart> ExpressionsFactoryImpl::createTupleLiteralPart_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralPartImpl> element(new ocl::Expressions::TupleLiteralPartImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisTupleLiteralPartPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleLiteralPart> ExpressionsFactoryImpl::createTupleLiteralPart_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralPartImpl> element(new ocl::Expressions::TupleLiteralPartImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisTupleLiteralPartPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleTypeExp> ExpressionsFactoryImpl::createTupleTypeExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::TupleTypeExpImpl> element(new ocl::Expressions::TupleTypeExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisTupleTypeExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::TupleTypeExp> ExpressionsFactoryImpl::createTupleTypeExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleTypeExpImpl> element(new ocl::Expressions::TupleTypeExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisTupleTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleTypeExp> ExpressionsFactoryImpl::createTupleTypeExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleTypeExpImpl> element(new ocl::Expressions::TupleTypeExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisTupleTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleTypeExp> ExpressionsFactoryImpl::createTupleTypeExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleTypeExpImpl> element(new ocl::Expressions::TupleTypeExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisTupleTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleTypeExp> ExpressionsFactoryImpl::createTupleTypeExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleTypeExpImpl> element(new ocl::Expressions::TupleTypeExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisTupleTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleTypeExp> ExpressionsFactoryImpl::createTupleTypeExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleTypeExpImpl> element(new ocl::Expressions::TupleTypeExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisTupleTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleTypeExp> ExpressionsFactoryImpl::createTupleTypeExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleTypeExpImpl> element(new ocl::Expressions::TupleTypeExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisTupleTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleTypeExp> ExpressionsFactoryImpl::createTupleTypeExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleTypeExpImpl> element(new ocl::Expressions::TupleTypeExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisTupleTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleTypeExp> ExpressionsFactoryImpl::createTupleTypeExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleTypeExpImpl> element(new ocl::Expressions::TupleTypeExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisTupleTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleTypeExp> ExpressionsFactoryImpl::createTupleTypeExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleTypeExpImpl> element(new ocl::Expressions::TupleTypeExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisTupleTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleTypeExp> ExpressionsFactoryImpl::createTupleTypeExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleTypeExpImpl> element(new ocl::Expressions::TupleTypeExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisTupleTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleTypeExp> ExpressionsFactoryImpl::createTupleTypeExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleTypeExpImpl> element(new ocl::Expressions::TupleTypeExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisTupleTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleTypeExp> ExpressionsFactoryImpl::createTupleTypeExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleTypeExpImpl> element(new ocl::Expressions::TupleTypeExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisTupleTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleTypeExp> ExpressionsFactoryImpl::createTupleTypeExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleTypeExpImpl> element(new ocl::Expressions::TupleTypeExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisTupleTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleTypeExp> ExpressionsFactoryImpl::createTupleTypeExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleTypeExpImpl> element(new ocl::Expressions::TupleTypeExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisTupleTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleTypeExp> ExpressionsFactoryImpl::createTupleTypeExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleTypeExpImpl> element(new ocl::Expressions::TupleTypeExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisTupleTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleTypeExp> ExpressionsFactoryImpl::createTupleTypeExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleTypeExpImpl> element(new ocl::Expressions::TupleTypeExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisTupleTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleTypeExp> ExpressionsFactoryImpl::createTupleTypeExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleTypeExpImpl> element(new ocl::Expressions::TupleTypeExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisTupleTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleTypeExp> ExpressionsFactoryImpl::createTupleTypeExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleTypeExpImpl> element(new ocl::Expressions::TupleTypeExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisTupleTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisTypeExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisUnlimitedNaturalExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisUnlimitedNaturalExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisUnlimitedNaturalExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisUnlimitedNaturalExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisUnlimitedNaturalExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisUnlimitedNaturalExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisUnlimitedNaturalExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisUnlimitedNaturalExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisUnlimitedNaturalExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisUnlimitedNaturalExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisUnlimitedNaturalExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisUnlimitedNaturalExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisUnlimitedNaturalExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisUnlimitedNaturalExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisUnlimitedNaturalExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisUnlimitedNaturalExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisUnlimitedNaturalExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisUnlimitedNaturalExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisUnlimitedNaturalExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisUnspecifiedValueExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisUnspecifiedValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisUnspecifiedValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisUnspecifiedValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisUnspecifiedValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisUnspecifiedValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisUnspecifiedValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisUnspecifiedValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisUnspecifiedValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisUnspecifiedValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisUnspecifiedValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisUnspecifiedValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisUnspecifiedValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisUnspecifiedValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisUnspecifiedValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisUnspecifiedValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisUnspecifiedValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisUnspecifiedValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisUnspecifiedValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VarDeclarationExp> ExpressionsFactoryImpl::createVarDeclarationExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::VarDeclarationExpImpl> element(new ocl::Expressions::VarDeclarationExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisVarDeclarationExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::VarDeclarationExp> ExpressionsFactoryImpl::createVarDeclarationExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VarDeclarationExpImpl> element(new ocl::Expressions::VarDeclarationExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisVarDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VarDeclarationExp> ExpressionsFactoryImpl::createVarDeclarationExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VarDeclarationExpImpl> element(new ocl::Expressions::VarDeclarationExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisVarDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VarDeclarationExp> ExpressionsFactoryImpl::createVarDeclarationExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VarDeclarationExpImpl> element(new ocl::Expressions::VarDeclarationExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisVarDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VarDeclarationExp> ExpressionsFactoryImpl::createVarDeclarationExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VarDeclarationExpImpl> element(new ocl::Expressions::VarDeclarationExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisVarDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VarDeclarationExp> ExpressionsFactoryImpl::createVarDeclarationExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VarDeclarationExpImpl> element(new ocl::Expressions::VarDeclarationExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisVarDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VarDeclarationExp> ExpressionsFactoryImpl::createVarDeclarationExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VarDeclarationExpImpl> element(new ocl::Expressions::VarDeclarationExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisVarDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VarDeclarationExp> ExpressionsFactoryImpl::createVarDeclarationExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VarDeclarationExpImpl> element(new ocl::Expressions::VarDeclarationExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisVarDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VarDeclarationExp> ExpressionsFactoryImpl::createVarDeclarationExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VarDeclarationExpImpl> element(new ocl::Expressions::VarDeclarationExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisVarDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VarDeclarationExp> ExpressionsFactoryImpl::createVarDeclarationExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VarDeclarationExpImpl> element(new ocl::Expressions::VarDeclarationExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisVarDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VarDeclarationExp> ExpressionsFactoryImpl::createVarDeclarationExp_as_initializedElement_in_OclExpression(std::weak_ptr<ocl::Expressions::OclExpression> par_OclExpression, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VarDeclarationExpImpl> element(new ocl::Expressions::VarDeclarationExpImpl(par_OclExpression));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OclExpression.lock())
	{
		wp->getInitializedElement()->push_back(element);
	}
	
	element->setThisVarDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VarDeclarationExp> ExpressionsFactoryImpl::createVarDeclarationExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VarDeclarationExpImpl> element(new ocl::Expressions::VarDeclarationExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisVarDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VarDeclarationExp> ExpressionsFactoryImpl::createVarDeclarationExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VarDeclarationExpImpl> element(new ocl::Expressions::VarDeclarationExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisVarDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VarDeclarationExp> ExpressionsFactoryImpl::createVarDeclarationExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VarDeclarationExpImpl> element(new ocl::Expressions::VarDeclarationExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisVarDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VarDeclarationExp> ExpressionsFactoryImpl::createVarDeclarationExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VarDeclarationExpImpl> element(new ocl::Expressions::VarDeclarationExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisVarDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VarDeclarationExp> ExpressionsFactoryImpl::createVarDeclarationExp_as_part_in_TupleLiteralExp(std::shared_ptr<ocl::Expressions::TupleLiteralExp> par_TupleLiteralExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VarDeclarationExpImpl> element(new ocl::Expressions::VarDeclarationExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_TupleLiteralExp)
	{
		par_TupleLiteralExp->getPart()->push_back(element);
	}
	
	element->setThisVarDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VarDeclarationExp> ExpressionsFactoryImpl::createVarDeclarationExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VarDeclarationExpImpl> element(new ocl::Expressions::VarDeclarationExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisVarDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VarDeclarationExp> ExpressionsFactoryImpl::createVarDeclarationExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VarDeclarationExpImpl> element(new ocl::Expressions::VarDeclarationExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisVarDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VarDeclarationExp> ExpressionsFactoryImpl::createVarDeclarationExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VarDeclarationExpImpl> element(new ocl::Expressions::VarDeclarationExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisVarDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VarDeclarationExp> ExpressionsFactoryImpl::createVarDeclarationExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VarDeclarationExpImpl> element(new ocl::Expressions::VarDeclarationExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisVarDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VarDeclarationExp> ExpressionsFactoryImpl::createVarDeclarationExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VarDeclarationExpImpl> element(new ocl::Expressions::VarDeclarationExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisVarDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VarDeclarationExp> ExpressionsFactoryImpl::createVarDeclarationExp_as_variables_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VarDeclarationExpImpl> element(new ocl::Expressions::VarDeclarationExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->getVariables()->push_back(element);
	}
	
	element->setThisVarDeclarationExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::Variable> ExpressionsFactoryImpl::createVariable(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::VariableImpl> element(new ocl::Expressions::VariableImpl());
	element->setMetaElementID(metaElementID);
	element->setThisVariablePtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::Variable> ExpressionsFactoryImpl::createVariable_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableImpl> element(new ocl::Expressions::VariableImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisVariablePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::Variable> ExpressionsFactoryImpl::createVariable_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableImpl> element(new ocl::Expressions::VariableImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisVariablePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::Variable> ExpressionsFactoryImpl::createVariable_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableImpl> element(new ocl::Expressions::VariableImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisVariablePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::Variable> ExpressionsFactoryImpl::createVariable_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableImpl> element(new ocl::Expressions::VariableImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisVariablePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisVariableExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl(par_OperationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_OperationCallExp.lock())
	{
		wp->getArgument()->push_back(element);
	}
	
	element->setThisVariableExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp_as_body_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->setBody(element);
	}
	
	element->setThisVariableExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp_as_bodyExpression_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setBodyExpression(element);
	}
	
	element->setThisVariableExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp_as_condition_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	}
	
	element->setThisVariableExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisVariableExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setElseExpression(element);
	}
	
	element->setThisVariableExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp_as_first_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setFirst(element);
	}
	
	element->setThisVariableExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp_as_in_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setIn(element);
	}
	
	element->setThisVariableExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp_as_initExpression_in_Variable(std::shared_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Variable)
	{
		par_Variable->setInitExpression(element);
	}
	
	element->setThisVariableExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp_as_item_in_CollectionItem(std::shared_ptr<ocl::Expressions::CollectionItem> par_CollectionItem, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionItem)
	{
		par_CollectionItem->setItem(element);
	}
	
	element->setThisVariableExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl(par_LoopExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	}
	
	element->setThisVariableExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl(par_CollectionRange, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	}
	
	element->setThisVariableExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisVariableExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl(par_NavigationCallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	}
	
	element->setThisVariableExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisVariableExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisVariableExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp_as_source_in_CallExp(std::shared_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallExp)
	{
		par_CallExp->setSource(element);
	}
	
	element->setThisVariableExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl(par_IfExp, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	}
	
	element->setThisVariableExpPtr(element);
	return element;
	
}

