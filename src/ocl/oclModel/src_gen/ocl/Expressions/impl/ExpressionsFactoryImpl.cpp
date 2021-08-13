#include "ocl/Expressions/impl/ExpressionsFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "ocl/Expressions/impl/AssociationClassCallExpImpl.hpp"
#include "ocl/Expressions/impl/BooleanLiteralExpImpl.hpp"
#include "ocl/Expressions/impl/CallExpImpl.hpp"
#include "ocl/Expressions/impl/CollectionItemImpl.hpp"
#include "ocl/Expressions/impl/CollectionLiteralExpImpl.hpp"
#include "ocl/Expressions/impl/CollectionLiteralPartImpl.hpp"
#include "ocl/Expressions/impl/CollectionRangeImpl.hpp"
#include "ocl/Expressions/impl/EnumLiteralExpImpl.hpp"
#include "ocl/Expressions/impl/ExpressionInOclImpl.hpp"
#include "ocl/Expressions/impl/FeatureCallExpImpl.hpp"
#include "ocl/Expressions/impl/IfExpImpl.hpp"
#include "ocl/Expressions/impl/InfixedExpImpl.hpp"
#include "ocl/Expressions/impl/IntegerLiteralExpImpl.hpp"
#include "ocl/Expressions/impl/InvalidLiteralExpImpl.hpp"
#include "ocl/Expressions/impl/IterateExpImpl.hpp"
#include "ocl/Expressions/impl/IteratorExpImpl.hpp"
#include "ocl/Expressions/impl/LetExpImpl.hpp"
#include "ocl/Expressions/impl/LiteralExpImpl.hpp"
#include "ocl/Expressions/impl/LoopExpImpl.hpp"
#include "ocl/Expressions/impl/MessageExpImpl.hpp"
#include "ocl/Expressions/impl/NavigationCallExpImpl.hpp"
#include "ocl/Expressions/impl/NullLiteralExpImpl.hpp"
#include "ocl/Expressions/impl/NumericLiteralExpImpl.hpp"
#include "ocl/Expressions/impl/OclExpressionImpl.hpp"
#include "ocl/Expressions/impl/OperationCallExpImpl.hpp"
#include "ocl/Expressions/impl/PrimitiveLiteralExpImpl.hpp"
#include "ocl/Expressions/impl/PropertyCallExpImpl.hpp"
#include "ocl/Expressions/impl/RealLiteralExpImpl.hpp"
#include "ocl/Expressions/impl/StateExpImpl.hpp"
#include "ocl/Expressions/impl/StringLiteralExpImpl.hpp"
#include "ocl/Expressions/impl/TupleLiteralExpImpl.hpp"
#include "ocl/Expressions/impl/TupleLiteralPartImpl.hpp"
#include "ocl/Expressions/impl/TypeExpImpl.hpp"
#include "ocl/Expressions/impl/UnlimitedNaturalExpImpl.hpp"
#include "ocl/Expressions/impl/UnspecifiedValueExpImpl.hpp"
#include "ocl/Expressions/impl/VariableImpl.hpp"
#include "ocl/Expressions/impl/VariableExpImpl.hpp"

#include "ocl/Expressions/OclExpression.hpp"
#include "ocl/Expressions/OclExpression.hpp"
#include "ocl/Expressions/OclExpression.hpp"
#include "ocl/Expressions/OclExpression.hpp"
#include "ocl/Expressions/Variable.hpp"
#include "ocl/Expressions/OclExpression.hpp"
#include "ocl/Expressions/OclExpression.hpp"
#include "ocl/Expressions/OclExpression.hpp"
#include "ocl/Expressions/OclExpression.hpp"
#include "ocl/Expressions/OclExpression.hpp"
#include "ocl/Expressions/Variable.hpp"
#include "ocl/Expressions/OclExpression.hpp"
#include "ocl/Expressions/Variable.hpp"
#include "ocl/Expressions/TupleLiteralPart.hpp"
#include "ocl/Expressions/CollectionLiteralPart.hpp"
#include "ocl/Expressions/OclExpression.hpp"
#include "ocl/Expressions/Variable.hpp"
#include "ocl/Expressions/Variable.hpp"
#include "ocl/Expressions/OclExpression.hpp"
#include "ocl/Expressions/OclExpression.hpp"
#include "ocl/Expressions/Variable.hpp"


using namespace ocl::Expressions;

//*********************************
// Constructor / Destructor
//*********************************

ExpressionsFactoryImpl::ExpressionsFactoryImpl()
{
	m_idMap.insert(std::make_pair("ocl::Expressions::AssociationClassCallExp", ExpressionsPackage::ASSOCIATIONCLASSCALLEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::BooleanLiteralExp", ExpressionsPackage::BOOLEANLITERALEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::CollectionItem", ExpressionsPackage::COLLECTIONITEM_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::CollectionLiteralExp", ExpressionsPackage::COLLECTIONLITERALEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::CollectionRange", ExpressionsPackage::COLLECTIONRANGE_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::EnumLiteralExp", ExpressionsPackage::ENUMLITERALEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::ExpressionInOcl", ExpressionsPackage::EXPRESSIONINOCL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::IfExp", ExpressionsPackage::IFEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::InfixedExp", ExpressionsPackage::INFIXEDEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::IntegerLiteralExp", ExpressionsPackage::INTEGERLITERALEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::InvalidLiteralExp", ExpressionsPackage::INVALIDLITERALEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::IterateExp", ExpressionsPackage::ITERATEEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::IteratorExp", ExpressionsPackage::ITERATOREXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::LetExp", ExpressionsPackage::LETEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::MessageExp", ExpressionsPackage::MESSAGEEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::NullLiteralExp", ExpressionsPackage::NULLLITERALEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::OperationCallExp", ExpressionsPackage::OPERATIONCALLEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::PropertyCallExp", ExpressionsPackage::PROPERTYCALLEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::RealLiteralExp", ExpressionsPackage::REALLITERALEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::StateExp", ExpressionsPackage::STATEEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::StringLiteralExp", ExpressionsPackage::STRINGLITERALEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::TupleLiteralExp", ExpressionsPackage::TUPLELITERALEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::TupleLiteralPart", ExpressionsPackage::TUPLELITERALPART_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::TypeExp", ExpressionsPackage::TYPEEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::UnlimitedNaturalExp", ExpressionsPackage::UNLIMITEDNATURALEXP_CLASS));
	m_idMap.insert(std::make_pair("ocl::Expressions::UnspecifiedValueExp", ExpressionsPackage::UNSPECIFIEDVALUEEXP_CLASS));
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
					case  ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createAssociationClassCallExp_as_argument_in_ocl::Expressions::OperationCallExp(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has body as a containment
					case  ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createAssociationClassCallExp_as_body_in_ocl::Expressions::LoopExp(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has bodyExpression as a containment
					case  ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createAssociationClassCallExp_as_bodyExpression_in_ocl::Expressions::ExpressionInOcl(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has condition as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createAssociationClassCallExp_as_condition_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has elseExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createAssociationClassCallExp_as_elseExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has first as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createAssociationClassCallExp_as_first_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has in as a containment
					case  ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp>(container);
						return this->createAssociationClassCallExp_as_in_in_ocl::Expressions::LetExp(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has initExpression as a containment
					case  ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createAssociationClassCallExp_as_initExpression_in_ocl::Expressions::Variable(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has item as a containment
					case  ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem>(container);
						return this->createAssociationClassCallExp_as_item_in_ocl::Expressions::CollectionItem(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has last as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createAssociationClassCallExp_as_last_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has qualifier as a containment
					case  ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createAssociationClassCallExp_as_qualifier_in_ocl::Expressions::NavigationCallExp(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has source as a containment
					case  ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createAssociationClassCallExp_as_source_in_ocl::Expressions::CallExp(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has thenExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createAssociationClassCallExp_as_thenExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
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
					case  ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createBooleanLiteralExp_as_argument_in_ocl::Expressions::OperationCallExp(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has body as a containment
					case  ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createBooleanLiteralExp_as_body_in_ocl::Expressions::LoopExp(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has bodyExpression as a containment
					case  ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createBooleanLiteralExp_as_bodyExpression_in_ocl::Expressions::ExpressionInOcl(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has condition as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createBooleanLiteralExp_as_condition_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has elseExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createBooleanLiteralExp_as_elseExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has first as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createBooleanLiteralExp_as_first_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has in as a containment
					case  ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp>(container);
						return this->createBooleanLiteralExp_as_in_in_ocl::Expressions::LetExp(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has initExpression as a containment
					case  ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createBooleanLiteralExp_as_initExpression_in_ocl::Expressions::Variable(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has item as a containment
					case  ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem>(container);
						return this->createBooleanLiteralExp_as_item_in_ocl::Expressions::CollectionItem(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has last as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createBooleanLiteralExp_as_last_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has qualifier as a containment
					case  ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createBooleanLiteralExp_as_qualifier_in_ocl::Expressions::NavigationCallExp(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has source as a containment
					case  ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createBooleanLiteralExp_as_source_in_ocl::Expressions::CallExp(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has thenExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createBooleanLiteralExp_as_thenExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
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
				std::shared_ptr<ocl::Expressions::CollectionLiteralExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionLiteralExp>(container);
				assert(castedContainer);
				return std::shared_ptr<ocl::Expressions::CollectionItem>(this->createCollectionItem_as_part_in_CollectionLiteralExp(castedContainer,metaElementID));
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
					case  ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createCollectionLiteralExp_as_argument_in_ocl::Expressions::OperationCallExp(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has body as a containment
					case  ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createCollectionLiteralExp_as_body_in_ocl::Expressions::LoopExp(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has bodyExpression as a containment
					case  ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createCollectionLiteralExp_as_bodyExpression_in_ocl::Expressions::ExpressionInOcl(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has condition as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createCollectionLiteralExp_as_condition_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has elseExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createCollectionLiteralExp_as_elseExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has first as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createCollectionLiteralExp_as_first_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has in as a containment
					case  ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp>(container);
						return this->createCollectionLiteralExp_as_in_in_ocl::Expressions::LetExp(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has initExpression as a containment
					case  ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createCollectionLiteralExp_as_initExpression_in_ocl::Expressions::Variable(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has item as a containment
					case  ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem>(container);
						return this->createCollectionLiteralExp_as_item_in_ocl::Expressions::CollectionItem(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has last as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createCollectionLiteralExp_as_last_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has qualifier as a containment
					case  ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createCollectionLiteralExp_as_qualifier_in_ocl::Expressions::NavigationCallExp(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has source as a containment
					case  ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createCollectionLiteralExp_as_source_in_ocl::Expressions::CallExp(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has thenExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createCollectionLiteralExp_as_thenExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
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
				std::shared_ptr<ocl::Expressions::CollectionLiteralExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionLiteralExp>(container);
				assert(castedContainer);
				return std::shared_ptr<ocl::Expressions::CollectionRange>(this->createCollectionRange_as_part_in_CollectionLiteralExp(castedContainer,metaElementID));
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
					case  ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createEnumLiteralExp_as_argument_in_ocl::Expressions::OperationCallExp(castedContainer,metaElementID);
					}
					//EnumLiteralExp has body as a containment
					case  ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createEnumLiteralExp_as_body_in_ocl::Expressions::LoopExp(castedContainer,metaElementID);
					}
					//EnumLiteralExp has bodyExpression as a containment
					case  ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createEnumLiteralExp_as_bodyExpression_in_ocl::Expressions::ExpressionInOcl(castedContainer,metaElementID);
					}
					//EnumLiteralExp has condition as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createEnumLiteralExp_as_condition_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//EnumLiteralExp has elseExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createEnumLiteralExp_as_elseExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//EnumLiteralExp has first as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createEnumLiteralExp_as_first_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//EnumLiteralExp has in as a containment
					case  ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp>(container);
						return this->createEnumLiteralExp_as_in_in_ocl::Expressions::LetExp(castedContainer,metaElementID);
					}
					//EnumLiteralExp has initExpression as a containment
					case  ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createEnumLiteralExp_as_initExpression_in_ocl::Expressions::Variable(castedContainer,metaElementID);
					}
					//EnumLiteralExp has item as a containment
					case  ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem>(container);
						return this->createEnumLiteralExp_as_item_in_ocl::Expressions::CollectionItem(castedContainer,metaElementID);
					}
					//EnumLiteralExp has last as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createEnumLiteralExp_as_last_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//EnumLiteralExp has qualifier as a containment
					case  ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createEnumLiteralExp_as_qualifier_in_ocl::Expressions::NavigationCallExp(castedContainer,metaElementID);
					}
					//EnumLiteralExp has source as a containment
					case  ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createEnumLiteralExp_as_source_in_ocl::Expressions::CallExp(castedContainer,metaElementID);
					}
					//EnumLiteralExp has thenExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createEnumLiteralExp_as_thenExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ExpressionsPackage::EXPRESSIONINOCL_CLASS:
		{
				return this->createExpressionInOcl(metaElementID);
			
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
					case  ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createIfExp_as_argument_in_ocl::Expressions::OperationCallExp(castedContainer,metaElementID);
					}
					//IfExp has body as a containment
					case  ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createIfExp_as_body_in_ocl::Expressions::LoopExp(castedContainer,metaElementID);
					}
					//IfExp has bodyExpression as a containment
					case  ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createIfExp_as_bodyExpression_in_ocl::Expressions::ExpressionInOcl(castedContainer,metaElementID);
					}
					//IfExp has condition as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createIfExp_as_condition_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//IfExp has elseExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createIfExp_as_elseExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//IfExp has first as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createIfExp_as_first_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//IfExp has in as a containment
					case  ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp>(container);
						return this->createIfExp_as_in_in_ocl::Expressions::LetExp(castedContainer,metaElementID);
					}
					//IfExp has initExpression as a containment
					case  ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createIfExp_as_initExpression_in_ocl::Expressions::Variable(castedContainer,metaElementID);
					}
					//IfExp has item as a containment
					case  ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem>(container);
						return this->createIfExp_as_item_in_ocl::Expressions::CollectionItem(castedContainer,metaElementID);
					}
					//IfExp has last as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createIfExp_as_last_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//IfExp has qualifier as a containment
					case  ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createIfExp_as_qualifier_in_ocl::Expressions::NavigationCallExp(castedContainer,metaElementID);
					}
					//IfExp has source as a containment
					case  ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createIfExp_as_source_in_ocl::Expressions::CallExp(castedContainer,metaElementID);
					}
					//IfExp has thenExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createIfExp_as_thenExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
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
					case  ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createInfixedExp_as_argument_in_ocl::Expressions::OperationCallExp(castedContainer,metaElementID);
					}
					//InfixedExp has body as a containment
					case  ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createInfixedExp_as_body_in_ocl::Expressions::LoopExp(castedContainer,metaElementID);
					}
					//InfixedExp has bodyExpression as a containment
					case  ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createInfixedExp_as_bodyExpression_in_ocl::Expressions::ExpressionInOcl(castedContainer,metaElementID);
					}
					//InfixedExp has condition as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createInfixedExp_as_condition_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//InfixedExp has elseExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createInfixedExp_as_elseExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//InfixedExp has first as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createInfixedExp_as_first_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//InfixedExp has in as a containment
					case  ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp>(container);
						return this->createInfixedExp_as_in_in_ocl::Expressions::LetExp(castedContainer,metaElementID);
					}
					//InfixedExp has initExpression as a containment
					case  ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createInfixedExp_as_initExpression_in_ocl::Expressions::Variable(castedContainer,metaElementID);
					}
					//InfixedExp has item as a containment
					case  ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem>(container);
						return this->createInfixedExp_as_item_in_ocl::Expressions::CollectionItem(castedContainer,metaElementID);
					}
					//InfixedExp has last as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createInfixedExp_as_last_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//InfixedExp has qualifier as a containment
					case  ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createInfixedExp_as_qualifier_in_ocl::Expressions::NavigationCallExp(castedContainer,metaElementID);
					}
					//InfixedExp has source as a containment
					case  ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createInfixedExp_as_source_in_ocl::Expressions::CallExp(castedContainer,metaElementID);
					}
					//InfixedExp has thenExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createInfixedExp_as_thenExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
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
					case  ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createIntegerLiteralExp_as_argument_in_ocl::Expressions::OperationCallExp(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has body as a containment
					case  ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createIntegerLiteralExp_as_body_in_ocl::Expressions::LoopExp(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has bodyExpression as a containment
					case  ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createIntegerLiteralExp_as_bodyExpression_in_ocl::Expressions::ExpressionInOcl(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has condition as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createIntegerLiteralExp_as_condition_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has elseExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createIntegerLiteralExp_as_elseExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has first as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createIntegerLiteralExp_as_first_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has in as a containment
					case  ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp>(container);
						return this->createIntegerLiteralExp_as_in_in_ocl::Expressions::LetExp(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has initExpression as a containment
					case  ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createIntegerLiteralExp_as_initExpression_in_ocl::Expressions::Variable(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has item as a containment
					case  ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem>(container);
						return this->createIntegerLiteralExp_as_item_in_ocl::Expressions::CollectionItem(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has last as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createIntegerLiteralExp_as_last_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has qualifier as a containment
					case  ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createIntegerLiteralExp_as_qualifier_in_ocl::Expressions::NavigationCallExp(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has source as a containment
					case  ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createIntegerLiteralExp_as_source_in_ocl::Expressions::CallExp(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has thenExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createIntegerLiteralExp_as_thenExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
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
					case  ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createInvalidLiteralExp_as_argument_in_ocl::Expressions::OperationCallExp(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has body as a containment
					case  ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createInvalidLiteralExp_as_body_in_ocl::Expressions::LoopExp(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has bodyExpression as a containment
					case  ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createInvalidLiteralExp_as_bodyExpression_in_ocl::Expressions::ExpressionInOcl(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has condition as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createInvalidLiteralExp_as_condition_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has elseExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createInvalidLiteralExp_as_elseExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has first as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createInvalidLiteralExp_as_first_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has in as a containment
					case  ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp>(container);
						return this->createInvalidLiteralExp_as_in_in_ocl::Expressions::LetExp(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has initExpression as a containment
					case  ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createInvalidLiteralExp_as_initExpression_in_ocl::Expressions::Variable(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has item as a containment
					case  ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem>(container);
						return this->createInvalidLiteralExp_as_item_in_ocl::Expressions::CollectionItem(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has last as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createInvalidLiteralExp_as_last_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has qualifier as a containment
					case  ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createInvalidLiteralExp_as_qualifier_in_ocl::Expressions::NavigationCallExp(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has source as a containment
					case  ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createInvalidLiteralExp_as_source_in_ocl::Expressions::CallExp(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has thenExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createInvalidLiteralExp_as_thenExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
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
					case  ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createIterateExp_as_argument_in_ocl::Expressions::OperationCallExp(castedContainer,metaElementID);
					}
					//IterateExp has body as a containment
					case  ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createIterateExp_as_body_in_ocl::Expressions::LoopExp(castedContainer,metaElementID);
					}
					//IterateExp has bodyExpression as a containment
					case  ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createIterateExp_as_bodyExpression_in_ocl::Expressions::ExpressionInOcl(castedContainer,metaElementID);
					}
					//IterateExp has condition as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createIterateExp_as_condition_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//IterateExp has elseExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createIterateExp_as_elseExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//IterateExp has first as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createIterateExp_as_first_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//IterateExp has in as a containment
					case  ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp>(container);
						return this->createIterateExp_as_in_in_ocl::Expressions::LetExp(castedContainer,metaElementID);
					}
					//IterateExp has initExpression as a containment
					case  ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createIterateExp_as_initExpression_in_ocl::Expressions::Variable(castedContainer,metaElementID);
					}
					//IterateExp has item as a containment
					case  ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem>(container);
						return this->createIterateExp_as_item_in_ocl::Expressions::CollectionItem(castedContainer,metaElementID);
					}
					//IterateExp has last as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createIterateExp_as_last_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//IterateExp has qualifier as a containment
					case  ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createIterateExp_as_qualifier_in_ocl::Expressions::NavigationCallExp(castedContainer,metaElementID);
					}
					//IterateExp has source as a containment
					case  ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createIterateExp_as_source_in_ocl::Expressions::CallExp(castedContainer,metaElementID);
					}
					//IterateExp has thenExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createIterateExp_as_thenExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
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
					case  ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createIteratorExp_as_argument_in_ocl::Expressions::OperationCallExp(castedContainer,metaElementID);
					}
					//IteratorExp has body as a containment
					case  ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createIteratorExp_as_body_in_ocl::Expressions::LoopExp(castedContainer,metaElementID);
					}
					//IteratorExp has bodyExpression as a containment
					case  ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createIteratorExp_as_bodyExpression_in_ocl::Expressions::ExpressionInOcl(castedContainer,metaElementID);
					}
					//IteratorExp has condition as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createIteratorExp_as_condition_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//IteratorExp has elseExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createIteratorExp_as_elseExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//IteratorExp has first as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createIteratorExp_as_first_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//IteratorExp has in as a containment
					case  ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp>(container);
						return this->createIteratorExp_as_in_in_ocl::Expressions::LetExp(castedContainer,metaElementID);
					}
					//IteratorExp has initExpression as a containment
					case  ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createIteratorExp_as_initExpression_in_ocl::Expressions::Variable(castedContainer,metaElementID);
					}
					//IteratorExp has item as a containment
					case  ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem>(container);
						return this->createIteratorExp_as_item_in_ocl::Expressions::CollectionItem(castedContainer,metaElementID);
					}
					//IteratorExp has last as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createIteratorExp_as_last_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//IteratorExp has qualifier as a containment
					case  ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createIteratorExp_as_qualifier_in_ocl::Expressions::NavigationCallExp(castedContainer,metaElementID);
					}
					//IteratorExp has source as a containment
					case  ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createIteratorExp_as_source_in_ocl::Expressions::CallExp(castedContainer,metaElementID);
					}
					//IteratorExp has thenExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createIteratorExp_as_thenExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
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
					case  ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createLetExp_as_argument_in_ocl::Expressions::OperationCallExp(castedContainer,metaElementID);
					}
					//LetExp has body as a containment
					case  ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createLetExp_as_body_in_ocl::Expressions::LoopExp(castedContainer,metaElementID);
					}
					//LetExp has bodyExpression as a containment
					case  ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createLetExp_as_bodyExpression_in_ocl::Expressions::ExpressionInOcl(castedContainer,metaElementID);
					}
					//LetExp has condition as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createLetExp_as_condition_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//LetExp has elseExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createLetExp_as_elseExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//LetExp has first as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createLetExp_as_first_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//LetExp has in as a containment
					case  ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp>(container);
						return this->createLetExp_as_in_in_ocl::Expressions::LetExp(castedContainer,metaElementID);
					}
					//LetExp has initExpression as a containment
					case  ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createLetExp_as_initExpression_in_ocl::Expressions::Variable(castedContainer,metaElementID);
					}
					//LetExp has item as a containment
					case  ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem>(container);
						return this->createLetExp_as_item_in_ocl::Expressions::CollectionItem(castedContainer,metaElementID);
					}
					//LetExp has last as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createLetExp_as_last_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//LetExp has qualifier as a containment
					case  ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createLetExp_as_qualifier_in_ocl::Expressions::NavigationCallExp(castedContainer,metaElementID);
					}
					//LetExp has source as a containment
					case  ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createLetExp_as_source_in_ocl::Expressions::CallExp(castedContainer,metaElementID);
					}
					//LetExp has thenExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createLetExp_as_thenExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
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
					case  ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createMessageExp_as_argument_in_ocl::Expressions::OperationCallExp(castedContainer,metaElementID);
					}
					//MessageExp has body as a containment
					case  ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createMessageExp_as_body_in_ocl::Expressions::LoopExp(castedContainer,metaElementID);
					}
					//MessageExp has bodyExpression as a containment
					case  ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createMessageExp_as_bodyExpression_in_ocl::Expressions::ExpressionInOcl(castedContainer,metaElementID);
					}
					//MessageExp has condition as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createMessageExp_as_condition_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//MessageExp has elseExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createMessageExp_as_elseExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//MessageExp has first as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createMessageExp_as_first_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//MessageExp has in as a containment
					case  ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp>(container);
						return this->createMessageExp_as_in_in_ocl::Expressions::LetExp(castedContainer,metaElementID);
					}
					//MessageExp has initExpression as a containment
					case  ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createMessageExp_as_initExpression_in_ocl::Expressions::Variable(castedContainer,metaElementID);
					}
					//MessageExp has item as a containment
					case  ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem>(container);
						return this->createMessageExp_as_item_in_ocl::Expressions::CollectionItem(castedContainer,metaElementID);
					}
					//MessageExp has last as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createMessageExp_as_last_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//MessageExp has qualifier as a containment
					case  ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createMessageExp_as_qualifier_in_ocl::Expressions::NavigationCallExp(castedContainer,metaElementID);
					}
					//MessageExp has source as a containment
					case  ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createMessageExp_as_source_in_ocl::Expressions::CallExp(castedContainer,metaElementID);
					}
					//MessageExp has thenExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createMessageExp_as_thenExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
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
					case  ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createNullLiteralExp_as_argument_in_ocl::Expressions::OperationCallExp(castedContainer,metaElementID);
					}
					//NullLiteralExp has body as a containment
					case  ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createNullLiteralExp_as_body_in_ocl::Expressions::LoopExp(castedContainer,metaElementID);
					}
					//NullLiteralExp has bodyExpression as a containment
					case  ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createNullLiteralExp_as_bodyExpression_in_ocl::Expressions::ExpressionInOcl(castedContainer,metaElementID);
					}
					//NullLiteralExp has condition as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createNullLiteralExp_as_condition_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//NullLiteralExp has elseExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createNullLiteralExp_as_elseExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//NullLiteralExp has first as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createNullLiteralExp_as_first_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//NullLiteralExp has in as a containment
					case  ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp>(container);
						return this->createNullLiteralExp_as_in_in_ocl::Expressions::LetExp(castedContainer,metaElementID);
					}
					//NullLiteralExp has initExpression as a containment
					case  ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createNullLiteralExp_as_initExpression_in_ocl::Expressions::Variable(castedContainer,metaElementID);
					}
					//NullLiteralExp has item as a containment
					case  ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem>(container);
						return this->createNullLiteralExp_as_item_in_ocl::Expressions::CollectionItem(castedContainer,metaElementID);
					}
					//NullLiteralExp has last as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createNullLiteralExp_as_last_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//NullLiteralExp has qualifier as a containment
					case  ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createNullLiteralExp_as_qualifier_in_ocl::Expressions::NavigationCallExp(castedContainer,metaElementID);
					}
					//NullLiteralExp has source as a containment
					case  ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createNullLiteralExp_as_source_in_ocl::Expressions::CallExp(castedContainer,metaElementID);
					}
					//NullLiteralExp has thenExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createNullLiteralExp_as_thenExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
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
					case  ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createOperationCallExp_as_argument_in_ocl::Expressions::OperationCallExp(castedContainer,metaElementID);
					}
					//OperationCallExp has body as a containment
					case  ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createOperationCallExp_as_body_in_ocl::Expressions::LoopExp(castedContainer,metaElementID);
					}
					//OperationCallExp has bodyExpression as a containment
					case  ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createOperationCallExp_as_bodyExpression_in_ocl::Expressions::ExpressionInOcl(castedContainer,metaElementID);
					}
					//OperationCallExp has condition as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createOperationCallExp_as_condition_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//OperationCallExp has elseExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createOperationCallExp_as_elseExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//OperationCallExp has first as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createOperationCallExp_as_first_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//OperationCallExp has in as a containment
					case  ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp>(container);
						return this->createOperationCallExp_as_in_in_ocl::Expressions::LetExp(castedContainer,metaElementID);
					}
					//OperationCallExp has initExpression as a containment
					case  ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createOperationCallExp_as_initExpression_in_ocl::Expressions::Variable(castedContainer,metaElementID);
					}
					//OperationCallExp has item as a containment
					case  ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem>(container);
						return this->createOperationCallExp_as_item_in_ocl::Expressions::CollectionItem(castedContainer,metaElementID);
					}
					//OperationCallExp has last as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createOperationCallExp_as_last_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//OperationCallExp has qualifier as a containment
					case  ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createOperationCallExp_as_qualifier_in_ocl::Expressions::NavigationCallExp(castedContainer,metaElementID);
					}
					//OperationCallExp has source as a containment
					case  ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createOperationCallExp_as_source_in_ocl::Expressions::CallExp(castedContainer,metaElementID);
					}
					//OperationCallExp has thenExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createOperationCallExp_as_thenExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
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
					case  ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createPropertyCallExp_as_argument_in_ocl::Expressions::OperationCallExp(castedContainer,metaElementID);
					}
					//PropertyCallExp has body as a containment
					case  ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createPropertyCallExp_as_body_in_ocl::Expressions::LoopExp(castedContainer,metaElementID);
					}
					//PropertyCallExp has bodyExpression as a containment
					case  ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createPropertyCallExp_as_bodyExpression_in_ocl::Expressions::ExpressionInOcl(castedContainer,metaElementID);
					}
					//PropertyCallExp has condition as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createPropertyCallExp_as_condition_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//PropertyCallExp has elseExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createPropertyCallExp_as_elseExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//PropertyCallExp has first as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createPropertyCallExp_as_first_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//PropertyCallExp has in as a containment
					case  ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp>(container);
						return this->createPropertyCallExp_as_in_in_ocl::Expressions::LetExp(castedContainer,metaElementID);
					}
					//PropertyCallExp has initExpression as a containment
					case  ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createPropertyCallExp_as_initExpression_in_ocl::Expressions::Variable(castedContainer,metaElementID);
					}
					//PropertyCallExp has item as a containment
					case  ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem>(container);
						return this->createPropertyCallExp_as_item_in_ocl::Expressions::CollectionItem(castedContainer,metaElementID);
					}
					//PropertyCallExp has last as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createPropertyCallExp_as_last_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//PropertyCallExp has qualifier as a containment
					case  ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createPropertyCallExp_as_qualifier_in_ocl::Expressions::NavigationCallExp(castedContainer,metaElementID);
					}
					//PropertyCallExp has source as a containment
					case  ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createPropertyCallExp_as_source_in_ocl::Expressions::CallExp(castedContainer,metaElementID);
					}
					//PropertyCallExp has thenExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createPropertyCallExp_as_thenExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
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
					case  ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createRealLiteralExp_as_argument_in_ocl::Expressions::OperationCallExp(castedContainer,metaElementID);
					}
					//RealLiteralExp has body as a containment
					case  ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createRealLiteralExp_as_body_in_ocl::Expressions::LoopExp(castedContainer,metaElementID);
					}
					//RealLiteralExp has bodyExpression as a containment
					case  ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createRealLiteralExp_as_bodyExpression_in_ocl::Expressions::ExpressionInOcl(castedContainer,metaElementID);
					}
					//RealLiteralExp has condition as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createRealLiteralExp_as_condition_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//RealLiteralExp has elseExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createRealLiteralExp_as_elseExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//RealLiteralExp has first as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createRealLiteralExp_as_first_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//RealLiteralExp has in as a containment
					case  ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp>(container);
						return this->createRealLiteralExp_as_in_in_ocl::Expressions::LetExp(castedContainer,metaElementID);
					}
					//RealLiteralExp has initExpression as a containment
					case  ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createRealLiteralExp_as_initExpression_in_ocl::Expressions::Variable(castedContainer,metaElementID);
					}
					//RealLiteralExp has item as a containment
					case  ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem>(container);
						return this->createRealLiteralExp_as_item_in_ocl::Expressions::CollectionItem(castedContainer,metaElementID);
					}
					//RealLiteralExp has last as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createRealLiteralExp_as_last_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//RealLiteralExp has qualifier as a containment
					case  ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createRealLiteralExp_as_qualifier_in_ocl::Expressions::NavigationCallExp(castedContainer,metaElementID);
					}
					//RealLiteralExp has source as a containment
					case  ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createRealLiteralExp_as_source_in_ocl::Expressions::CallExp(castedContainer,metaElementID);
					}
					//RealLiteralExp has thenExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createRealLiteralExp_as_thenExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
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
					case  ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createStateExp_as_argument_in_ocl::Expressions::OperationCallExp(castedContainer,metaElementID);
					}
					//StateExp has body as a containment
					case  ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createStateExp_as_body_in_ocl::Expressions::LoopExp(castedContainer,metaElementID);
					}
					//StateExp has bodyExpression as a containment
					case  ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createStateExp_as_bodyExpression_in_ocl::Expressions::ExpressionInOcl(castedContainer,metaElementID);
					}
					//StateExp has condition as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createStateExp_as_condition_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//StateExp has elseExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createStateExp_as_elseExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//StateExp has first as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createStateExp_as_first_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//StateExp has in as a containment
					case  ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp>(container);
						return this->createStateExp_as_in_in_ocl::Expressions::LetExp(castedContainer,metaElementID);
					}
					//StateExp has initExpression as a containment
					case  ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createStateExp_as_initExpression_in_ocl::Expressions::Variable(castedContainer,metaElementID);
					}
					//StateExp has item as a containment
					case  ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem>(container);
						return this->createStateExp_as_item_in_ocl::Expressions::CollectionItem(castedContainer,metaElementID);
					}
					//StateExp has last as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createStateExp_as_last_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//StateExp has qualifier as a containment
					case  ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createStateExp_as_qualifier_in_ocl::Expressions::NavigationCallExp(castedContainer,metaElementID);
					}
					//StateExp has source as a containment
					case  ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createStateExp_as_source_in_ocl::Expressions::CallExp(castedContainer,metaElementID);
					}
					//StateExp has thenExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createStateExp_as_thenExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
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
					case  ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createStringLiteralExp_as_argument_in_ocl::Expressions::OperationCallExp(castedContainer,metaElementID);
					}
					//StringLiteralExp has body as a containment
					case  ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createStringLiteralExp_as_body_in_ocl::Expressions::LoopExp(castedContainer,metaElementID);
					}
					//StringLiteralExp has bodyExpression as a containment
					case  ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createStringLiteralExp_as_bodyExpression_in_ocl::Expressions::ExpressionInOcl(castedContainer,metaElementID);
					}
					//StringLiteralExp has condition as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createStringLiteralExp_as_condition_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//StringLiteralExp has elseExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createStringLiteralExp_as_elseExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//StringLiteralExp has first as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createStringLiteralExp_as_first_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//StringLiteralExp has in as a containment
					case  ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp>(container);
						return this->createStringLiteralExp_as_in_in_ocl::Expressions::LetExp(castedContainer,metaElementID);
					}
					//StringLiteralExp has initExpression as a containment
					case  ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createStringLiteralExp_as_initExpression_in_ocl::Expressions::Variable(castedContainer,metaElementID);
					}
					//StringLiteralExp has item as a containment
					case  ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem>(container);
						return this->createStringLiteralExp_as_item_in_ocl::Expressions::CollectionItem(castedContainer,metaElementID);
					}
					//StringLiteralExp has last as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createStringLiteralExp_as_last_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//StringLiteralExp has qualifier as a containment
					case  ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createStringLiteralExp_as_qualifier_in_ocl::Expressions::NavigationCallExp(castedContainer,metaElementID);
					}
					//StringLiteralExp has source as a containment
					case  ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createStringLiteralExp_as_source_in_ocl::Expressions::CallExp(castedContainer,metaElementID);
					}
					//StringLiteralExp has thenExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createStringLiteralExp_as_thenExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
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
					case  ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createTupleLiteralExp_as_argument_in_ocl::Expressions::OperationCallExp(castedContainer,metaElementID);
					}
					//TupleLiteralExp has body as a containment
					case  ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createTupleLiteralExp_as_body_in_ocl::Expressions::LoopExp(castedContainer,metaElementID);
					}
					//TupleLiteralExp has bodyExpression as a containment
					case  ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createTupleLiteralExp_as_bodyExpression_in_ocl::Expressions::ExpressionInOcl(castedContainer,metaElementID);
					}
					//TupleLiteralExp has condition as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createTupleLiteralExp_as_condition_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//TupleLiteralExp has elseExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createTupleLiteralExp_as_elseExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//TupleLiteralExp has first as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createTupleLiteralExp_as_first_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//TupleLiteralExp has in as a containment
					case  ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp>(container);
						return this->createTupleLiteralExp_as_in_in_ocl::Expressions::LetExp(castedContainer,metaElementID);
					}
					//TupleLiteralExp has initExpression as a containment
					case  ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createTupleLiteralExp_as_initExpression_in_ocl::Expressions::Variable(castedContainer,metaElementID);
					}
					//TupleLiteralExp has item as a containment
					case  ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem>(container);
						return this->createTupleLiteralExp_as_item_in_ocl::Expressions::CollectionItem(castedContainer,metaElementID);
					}
					//TupleLiteralExp has last as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createTupleLiteralExp_as_last_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//TupleLiteralExp has qualifier as a containment
					case  ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createTupleLiteralExp_as_qualifier_in_ocl::Expressions::NavigationCallExp(castedContainer,metaElementID);
					}
					//TupleLiteralExp has source as a containment
					case  ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createTupleLiteralExp_as_source_in_ocl::Expressions::CallExp(castedContainer,metaElementID);
					}
					//TupleLiteralExp has thenExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createTupleLiteralExp_as_thenExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
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
				std::shared_ptr<ocl::Expressions::TupleLiteralExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::TupleLiteralExp>(container);
				assert(castedContainer);
				return std::shared_ptr<ocl::Expressions::TupleLiteralPart>(this->createTupleLiteralPart_as_part_in_TupleLiteralExp(castedContainer,metaElementID));
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
					case  ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createTypeExp_as_argument_in_ocl::Expressions::OperationCallExp(castedContainer,metaElementID);
					}
					//TypeExp has body as a containment
					case  ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createTypeExp_as_body_in_ocl::Expressions::LoopExp(castedContainer,metaElementID);
					}
					//TypeExp has bodyExpression as a containment
					case  ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createTypeExp_as_bodyExpression_in_ocl::Expressions::ExpressionInOcl(castedContainer,metaElementID);
					}
					//TypeExp has condition as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createTypeExp_as_condition_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//TypeExp has elseExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createTypeExp_as_elseExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//TypeExp has first as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createTypeExp_as_first_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//TypeExp has in as a containment
					case  ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp>(container);
						return this->createTypeExp_as_in_in_ocl::Expressions::LetExp(castedContainer,metaElementID);
					}
					//TypeExp has initExpression as a containment
					case  ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createTypeExp_as_initExpression_in_ocl::Expressions::Variable(castedContainer,metaElementID);
					}
					//TypeExp has item as a containment
					case  ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem>(container);
						return this->createTypeExp_as_item_in_ocl::Expressions::CollectionItem(castedContainer,metaElementID);
					}
					//TypeExp has last as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createTypeExp_as_last_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//TypeExp has qualifier as a containment
					case  ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createTypeExp_as_qualifier_in_ocl::Expressions::NavigationCallExp(castedContainer,metaElementID);
					}
					//TypeExp has source as a containment
					case  ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createTypeExp_as_source_in_ocl::Expressions::CallExp(castedContainer,metaElementID);
					}
					//TypeExp has thenExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createTypeExp_as_thenExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
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
					case  ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createUnlimitedNaturalExp_as_argument_in_ocl::Expressions::OperationCallExp(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has body as a containment
					case  ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createUnlimitedNaturalExp_as_body_in_ocl::Expressions::LoopExp(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has bodyExpression as a containment
					case  ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createUnlimitedNaturalExp_as_bodyExpression_in_ocl::Expressions::ExpressionInOcl(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has condition as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createUnlimitedNaturalExp_as_condition_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has elseExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createUnlimitedNaturalExp_as_elseExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has first as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createUnlimitedNaturalExp_as_first_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has in as a containment
					case  ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp>(container);
						return this->createUnlimitedNaturalExp_as_in_in_ocl::Expressions::LetExp(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has initExpression as a containment
					case  ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createUnlimitedNaturalExp_as_initExpression_in_ocl::Expressions::Variable(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has item as a containment
					case  ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem>(container);
						return this->createUnlimitedNaturalExp_as_item_in_ocl::Expressions::CollectionItem(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has last as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createUnlimitedNaturalExp_as_last_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has qualifier as a containment
					case  ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createUnlimitedNaturalExp_as_qualifier_in_ocl::Expressions::NavigationCallExp(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has source as a containment
					case  ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createUnlimitedNaturalExp_as_source_in_ocl::Expressions::CallExp(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has thenExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createUnlimitedNaturalExp_as_thenExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
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
					case  ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createUnspecifiedValueExp_as_argument_in_ocl::Expressions::OperationCallExp(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has body as a containment
					case  ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createUnspecifiedValueExp_as_body_in_ocl::Expressions::LoopExp(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has bodyExpression as a containment
					case  ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createUnspecifiedValueExp_as_bodyExpression_in_ocl::Expressions::ExpressionInOcl(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has condition as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createUnspecifiedValueExp_as_condition_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has elseExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createUnspecifiedValueExp_as_elseExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has first as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createUnspecifiedValueExp_as_first_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has in as a containment
					case  ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp>(container);
						return this->createUnspecifiedValueExp_as_in_in_ocl::Expressions::LetExp(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has initExpression as a containment
					case  ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createUnspecifiedValueExp_as_initExpression_in_ocl::Expressions::Variable(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has item as a containment
					case  ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem>(container);
						return this->createUnspecifiedValueExp_as_item_in_ocl::Expressions::CollectionItem(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has last as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createUnspecifiedValueExp_as_last_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has qualifier as a containment
					case  ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createUnspecifiedValueExp_as_qualifier_in_ocl::Expressions::NavigationCallExp(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has source as a containment
					case  ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createUnspecifiedValueExp_as_source_in_ocl::Expressions::CallExp(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has thenExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createUnspecifiedValueExp_as_thenExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
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
					case  ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createVariable_as_contextVariable_in_ocl::Expressions::ExpressionInOcl(castedContainer,metaElementID);
					}
					//Variable has iterator as a containment
					case  ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createVariable_as_iterator_in_ocl::Expressions::LoopExp(castedContainer,metaElementID);
					}
					//Variable has parameterVariable as a containment
					case  ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createVariable_as_parameterVariable_in_ocl::Expressions::ExpressionInOcl(castedContainer,metaElementID);
					}
					//Variable has result as a containment
					case  ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp>(container);
						return this->createVariable_as_result_in_ocl::Expressions::IterateExp(castedContainer,metaElementID);
					}
					//Variable has resultVariable as a containment
					case  ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createVariable_as_resultVariable_in_ocl::Expressions::ExpressionInOcl(castedContainer,metaElementID);
					}
					//Variable has variable as a containment
					case  ExpressionsPackage::LETEXP_ATTRIBUTE_VARIABLE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp>(container);
						return this->createVariable_as_variable_in_ocl::Expressions::LetExp(castedContainer,metaElementID);
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
					case  ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createVariableExp_as_argument_in_ocl::Expressions::OperationCallExp(castedContainer,metaElementID);
					}
					//VariableExp has body as a containment
					case  ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createVariableExp_as_body_in_ocl::Expressions::LoopExp(castedContainer,metaElementID);
					}
					//VariableExp has bodyExpression as a containment
					case  ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createVariableExp_as_bodyExpression_in_ocl::Expressions::ExpressionInOcl(castedContainer,metaElementID);
					}
					//VariableExp has condition as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createVariableExp_as_condition_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//VariableExp has elseExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createVariableExp_as_elseExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
					}
					//VariableExp has first as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createVariableExp_as_first_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//VariableExp has in as a containment
					case  ExpressionsPackage::LETEXP_ATTRIBUTE_IN:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LetExp>(container);
						return this->createVariableExp_as_in_in_ocl::Expressions::LetExp(castedContainer,metaElementID);
					}
					//VariableExp has initExpression as a containment
					case  ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createVariableExp_as_initExpression_in_ocl::Expressions::Variable(castedContainer,metaElementID);
					}
					//VariableExp has item as a containment
					case  ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem>(container);
						return this->createVariableExp_as_item_in_ocl::Expressions::CollectionItem(castedContainer,metaElementID);
					}
					//VariableExp has last as a containment
					case  ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createVariableExp_as_last_in_ocl::Expressions::CollectionRange(castedContainer,metaElementID);
					}
					//VariableExp has qualifier as a containment
					case  ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createVariableExp_as_qualifier_in_ocl::Expressions::NavigationCallExp(castedContainer,metaElementID);
					}
					//VariableExp has source as a containment
					case  ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createVariableExp_as_source_in_ocl::Expressions::CallExp(castedContainer,metaElementID);
					}
					//VariableExp has thenExpression as a containment
					case  ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createVariableExp_as_thenExpression_in_ocl::Expressions::IfExp(castedContainer,metaElementID);
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
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl(par_LoopExp));
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
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl(par_IfExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	
	}
	element->setThisAssociationClassCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl(par_IfExp));
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
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl(par_CollectionRange));
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
std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp_as_initExpression_in_Variable(std::weak_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl(par_Variable));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_Variable.lock())
	{
		wp->setInitExpression(element);
	
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
std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl(par_CollectionRange));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	
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
std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp_as_source_in_CallExp(std::weak_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl(par_CallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CallExp.lock())
	{
		wp->setSource(element);
	
	}
	element->setThisAssociationClassCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl(par_IfExp));
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
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl(par_LoopExp));
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
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl(par_IfExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	
	}
	element->setThisBooleanLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl(par_IfExp));
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
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl(par_CollectionRange));
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
std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp_as_initExpression_in_Variable(std::weak_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl(par_Variable));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_Variable.lock())
	{
		wp->setInitExpression(element);
	
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
std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl(par_CollectionRange));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	
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
std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp_as_source_in_CallExp(std::weak_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl(par_CallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CallExp.lock())
	{
		wp->setSource(element);
	
	}
	element->setThisBooleanLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl(par_IfExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	
	}
	element->setThisBooleanLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionItem> ExpressionsFactoryImpl::createCollectionItem(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::CollectionItemImpl> element(new ocl::Expressions::CollectionItemImpl());
	element->setMetaElementID(metaElementID);
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
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl(par_LoopExp));
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
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl(par_IfExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	
	}
	element->setThisCollectionLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl(par_IfExp));
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
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl(par_CollectionRange));
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
std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp_as_initExpression_in_Variable(std::weak_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl(par_Variable));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_Variable.lock())
	{
		wp->setInitExpression(element);
	
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
std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl(par_CollectionRange));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	
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
std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp_as_source_in_CallExp(std::weak_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl(par_CallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CallExp.lock())
	{
		wp->setSource(element);
	
	}
	element->setThisCollectionLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl(par_IfExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	
	}
	element->setThisCollectionLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionRange> ExpressionsFactoryImpl::createCollectionRange(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::CollectionRangeImpl> element(new ocl::Expressions::CollectionRangeImpl());
	element->setMetaElementID(metaElementID);
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
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl(par_LoopExp));
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
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl(par_IfExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	
	}
	element->setThisEnumLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl(par_IfExp));
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
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl(par_CollectionRange));
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
std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp_as_initExpression_in_Variable(std::weak_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl(par_Variable));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_Variable.lock())
	{
		wp->setInitExpression(element);
	
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
std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl(par_CollectionRange));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	
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
std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp_as_source_in_CallExp(std::weak_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl(par_CallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CallExp.lock())
	{
		wp->setSource(element);
	
	}
	element->setThisEnumLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl(par_IfExp));
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
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisIfExpPtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_as_argument_in_OperationCallExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_OperationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl(par_OperationCallExp, ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT));
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
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl(par_LoopExp, ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY));
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
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl(par_ExpressionInOcl, ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION));
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
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl(par_IfExp, ExpressionsPackage::IFEXP_ATTRIBUTE_CONDITION));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	
	}
	element->setThisIfExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl(par_IfExp, ExpressionsPackage::IFEXP_ATTRIBUTE_ELSEEXPRESSION));
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
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl(par_CollectionRange, ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST));
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
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_as_initExpression_in_Variable(std::weak_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl(par_Variable, ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_Variable.lock())
	{
		wp->setInitExpression(element);
	
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
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl(par_CollectionRange, ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	
	}
	element->setThisIfExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_as_qualifier_in_NavigationCallExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_NavigationCallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl(par_NavigationCallExp, ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_NavigationCallExp.lock())
	{
		wp->getQualifier()->push_back(element);
	
	}
	element->setThisIfExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_as_source_in_CallExp(std::weak_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl(par_CallExp, ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CallExp.lock())
	{
		wp->setSource(element);
	
	}
	element->setThisIfExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl(par_IfExp, ExpressionsPackage::IFEXP_ATTRIBUTE_THENEXPRESSION));
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
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl(par_LoopExp));
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
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl(par_IfExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	
	}
	element->setThisInfixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl(par_IfExp));
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
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl(par_CollectionRange));
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
std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp_as_initExpression_in_Variable(std::weak_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl(par_Variable));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_Variable.lock())
	{
		wp->setInitExpression(element);
	
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
std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl(par_CollectionRange));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	
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
std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp_as_source_in_CallExp(std::weak_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl(par_CallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CallExp.lock())
	{
		wp->setSource(element);
	
	}
	element->setThisInfixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl(par_IfExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	
	}
	element->setThisInfixedExpPtr(element);
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
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl(par_LoopExp));
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
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl(par_IfExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	
	}
	element->setThisIntegerLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl(par_IfExp));
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
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl(par_CollectionRange));
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
std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp_as_initExpression_in_Variable(std::weak_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl(par_Variable));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_Variable.lock())
	{
		wp->setInitExpression(element);
	
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
std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl(par_CollectionRange));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	
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
std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp_as_source_in_CallExp(std::weak_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl(par_CallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CallExp.lock())
	{
		wp->setSource(element);
	
	}
	element->setThisIntegerLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl(par_IfExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	
	}
	element->setThisIntegerLiteralExpPtr(element);
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
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl(par_LoopExp));
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
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl(par_IfExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	
	}
	element->setThisInvalidLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl(par_IfExp));
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
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl(par_CollectionRange));
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
std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp_as_initExpression_in_Variable(std::weak_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl(par_Variable));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_Variable.lock())
	{
		wp->setInitExpression(element);
	
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
std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl(par_CollectionRange));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	
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
std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp_as_source_in_CallExp(std::weak_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl(par_CallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CallExp.lock())
	{
		wp->setSource(element);
	
	}
	element->setThisInvalidLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl(par_IfExp));
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
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl(par_LoopExp));
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
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl(par_IfExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	
	}
	element->setThisIterateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl(par_IfExp));
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
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl(par_CollectionRange));
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
std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp_as_initExpression_in_Variable(std::weak_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl(par_Variable));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_Variable.lock())
	{
		wp->setInitExpression(element);
	
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
std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl(par_CollectionRange));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	
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
std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp_as_source_in_CallExp(std::weak_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl(par_CallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CallExp.lock())
	{
		wp->setSource(element);
	
	}
	element->setThisIterateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl(par_IfExp));
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
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl(par_LoopExp));
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
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl(par_IfExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	
	}
	element->setThisIteratorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl(par_IfExp));
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
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl(par_CollectionRange));
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
std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp_as_initExpression_in_Variable(std::weak_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl(par_Variable));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_Variable.lock())
	{
		wp->setInitExpression(element);
	
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
std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl(par_CollectionRange));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	
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
std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp_as_source_in_CallExp(std::weak_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl(par_CallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CallExp.lock())
	{
		wp->setSource(element);
	
	}
	element->setThisIteratorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl(par_IfExp));
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
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl(par_LoopExp));
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
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl(par_IfExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	
	}
	element->setThisLetExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl(par_IfExp));
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
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl(par_CollectionRange));
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
std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp_as_initExpression_in_Variable(std::weak_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl(par_Variable));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_Variable.lock())
	{
		wp->setInitExpression(element);
	
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
std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl(par_CollectionRange));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	
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
std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp_as_source_in_CallExp(std::weak_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl(par_CallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CallExp.lock())
	{
		wp->setSource(element);
	
	}
	element->setThisLetExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl(par_IfExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	
	}
	element->setThisLetExpPtr(element);
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
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl(par_LoopExp));
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
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl(par_IfExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	
	}
	element->setThisMessageExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl(par_IfExp));
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
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl(par_CollectionRange));
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
std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp_as_initExpression_in_Variable(std::weak_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl(par_Variable));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_Variable.lock())
	{
		wp->setInitExpression(element);
	
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
std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl(par_CollectionRange));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	
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
std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp_as_source_in_CallExp(std::weak_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl(par_CallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CallExp.lock())
	{
		wp->setSource(element);
	
	}
	element->setThisMessageExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl(par_IfExp));
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
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl(par_LoopExp));
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
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl(par_IfExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	
	}
	element->setThisNullLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl(par_IfExp));
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
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl(par_CollectionRange));
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
std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp_as_initExpression_in_Variable(std::weak_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl(par_Variable));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_Variable.lock())
	{
		wp->setInitExpression(element);
	
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
std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl(par_CollectionRange));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	
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
std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp_as_source_in_CallExp(std::weak_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl(par_CallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CallExp.lock())
	{
		wp->setSource(element);
	
	}
	element->setThisNullLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl(par_IfExp));
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
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl(par_LoopExp));
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
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl(par_IfExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	
	}
	element->setThisOperationCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl(par_IfExp));
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
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl(par_CollectionRange));
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
std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp_as_initExpression_in_Variable(std::weak_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl(par_Variable));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_Variable.lock())
	{
		wp->setInitExpression(element);
	
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
std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl(par_CollectionRange));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	
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
std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp_as_source_in_CallExp(std::weak_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl(par_CallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CallExp.lock())
	{
		wp->setSource(element);
	
	}
	element->setThisOperationCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl(par_IfExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	
	}
	element->setThisOperationCallExpPtr(element);
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
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl(par_LoopExp));
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
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl(par_IfExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	
	}
	element->setThisPropertyCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl(par_IfExp));
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
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl(par_CollectionRange));
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
std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp_as_initExpression_in_Variable(std::weak_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl(par_Variable));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_Variable.lock())
	{
		wp->setInitExpression(element);
	
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
std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl(par_CollectionRange));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	
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
std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp_as_source_in_CallExp(std::weak_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl(par_CallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CallExp.lock())
	{
		wp->setSource(element);
	
	}
	element->setThisPropertyCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl(par_IfExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	
	}
	element->setThisPropertyCallExpPtr(element);
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
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl(par_LoopExp));
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
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl(par_IfExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	
	}
	element->setThisRealLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl(par_IfExp));
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
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl(par_CollectionRange));
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
std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp_as_initExpression_in_Variable(std::weak_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl(par_Variable));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_Variable.lock())
	{
		wp->setInitExpression(element);
	
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
std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl(par_CollectionRange));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	
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
std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp_as_source_in_CallExp(std::weak_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl(par_CallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CallExp.lock())
	{
		wp->setSource(element);
	
	}
	element->setThisRealLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl(par_IfExp));
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
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl(par_LoopExp));
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
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl(par_IfExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	
	}
	element->setThisStateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl(par_IfExp));
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
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl(par_CollectionRange));
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
std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp_as_initExpression_in_Variable(std::weak_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl(par_Variable));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_Variable.lock())
	{
		wp->setInitExpression(element);
	
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
std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl(par_CollectionRange));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	
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
std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp_as_source_in_CallExp(std::weak_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl(par_CallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CallExp.lock())
	{
		wp->setSource(element);
	
	}
	element->setThisStateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl(par_IfExp));
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
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl(par_LoopExp));
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
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl(par_IfExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	
	}
	element->setThisStringLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl(par_IfExp));
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
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl(par_CollectionRange));
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
std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp_as_initExpression_in_Variable(std::weak_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl(par_Variable));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_Variable.lock())
	{
		wp->setInitExpression(element);
	
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
std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl(par_CollectionRange));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	
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
std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp_as_source_in_CallExp(std::weak_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl(par_CallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CallExp.lock())
	{
		wp->setSource(element);
	
	}
	element->setThisStringLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl(par_IfExp));
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
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl(par_LoopExp));
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
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl(par_IfExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	
	}
	element->setThisTupleLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl(par_IfExp));
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
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl(par_CollectionRange));
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
std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp_as_initExpression_in_Variable(std::weak_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl(par_Variable));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_Variable.lock())
	{
		wp->setInitExpression(element);
	
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
std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl(par_CollectionRange));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	
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
std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp_as_source_in_CallExp(std::weak_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl(par_CallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CallExp.lock())
	{
		wp->setSource(element);
	
	}
	element->setThisTupleLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl(par_IfExp));
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
std::shared_ptr<ocl::Expressions::TupleLiteralPart> ExpressionsFactoryImpl::createTupleLiteralPart_as_part_in_TupleLiteralExp(std::shared_ptr<ocl::Expressions::TupleLiteralExp> par_TupleLiteralExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralPartImpl> element(new ocl::Expressions::TupleLiteralPartImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_TupleLiteralExp)
	{
		par_TupleLiteralExp->getPart()->push_back(element);
	
	}
	element->setThisTupleLiteralPartPtr(element);
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
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl(par_LoopExp));
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
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl(par_IfExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	
	}
	element->setThisTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl(par_IfExp));
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
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl(par_CollectionRange));
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
std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp_as_initExpression_in_Variable(std::weak_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl(par_Variable));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_Variable.lock())
	{
		wp->setInitExpression(element);
	
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
std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl(par_CollectionRange));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	
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
std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp_as_source_in_CallExp(std::weak_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl(par_CallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CallExp.lock())
	{
		wp->setSource(element);
	
	}
	element->setThisTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl(par_IfExp));
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
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl(par_LoopExp));
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
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl(par_IfExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	
	}
	element->setThisUnlimitedNaturalExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl(par_IfExp));
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
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl(par_CollectionRange));
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
std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp_as_initExpression_in_Variable(std::weak_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl(par_Variable));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_Variable.lock())
	{
		wp->setInitExpression(element);
	
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
std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl(par_CollectionRange));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	
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
std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp_as_source_in_CallExp(std::weak_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl(par_CallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CallExp.lock())
	{
		wp->setSource(element);
	
	}
	element->setThisUnlimitedNaturalExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl(par_IfExp));
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
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl(par_LoopExp));
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
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl(par_IfExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	
	}
	element->setThisUnspecifiedValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl(par_IfExp));
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
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl(par_CollectionRange));
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
std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp_as_initExpression_in_Variable(std::weak_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl(par_Variable));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_Variable.lock())
	{
		wp->setInitExpression(element);
	
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
std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl(par_CollectionRange));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	
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
std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp_as_source_in_CallExp(std::weak_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl(par_CallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CallExp.lock())
	{
		wp->setSource(element);
	
	}
	element->setThisUnspecifiedValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl(par_IfExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	
	}
	element->setThisUnspecifiedValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::Variable> ExpressionsFactoryImpl::createVariable(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::VariableImpl> element(new ocl::Expressions::VariableImpl());
	element->setMetaElementID(metaElementID);
	element->setThisVariablePtr(element);
	return element;
}
std::shared_ptr<ocl::Expressions::Variable> ExpressionsFactoryImpl::createVariable_as_contextVariable_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableImpl> element(new ocl::Expressions::VariableImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setContextVariable(element);
	
	}
	element->setThisVariablePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::Variable> ExpressionsFactoryImpl::createVariable_as_iterator_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableImpl> element(new ocl::Expressions::VariableImpl(par_LoopExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_LoopExp.lock())
	{
		wp->getIterator()->push_back(element);
	
	}
	element->setThisVariablePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::Variable> ExpressionsFactoryImpl::createVariable_as_parameterVariable_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableImpl> element(new ocl::Expressions::VariableImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->getParameterVariable()->push_back(element);
	
	}
	element->setThisVariablePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::Variable> ExpressionsFactoryImpl::createVariable_as_result_in_IterateExp(std::weak_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableImpl> element(new ocl::Expressions::VariableImpl(par_IterateExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IterateExp.lock())
	{
		wp->setResult(element);
	
	}
	element->setThisVariablePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::Variable> ExpressionsFactoryImpl::createVariable_as_resultVariable_in_ExpressionInOcl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableImpl> element(new ocl::Expressions::VariableImpl(par_ExpressionInOcl));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ExpressionInOcl.lock())
	{
		wp->setResultVariable(element);
	
	}
	element->setThisVariablePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::Variable> ExpressionsFactoryImpl::createVariable_as_variable_in_LetExp(std::shared_ptr<ocl::Expressions::LetExp> par_LetExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableImpl> element(new ocl::Expressions::VariableImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_LetExp)
	{
		par_LetExp->setVariable(element);
	
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
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl(par_LoopExp));
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
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl(par_IfExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setCondition(element);
	
	}
	element->setThisVariableExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp_as_elseExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl(par_IfExp));
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
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl(par_CollectionRange));
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
std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp_as_initExpression_in_Variable(std::weak_ptr<ocl::Expressions::Variable> par_Variable, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl(par_Variable));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_Variable.lock())
	{
		wp->setInitExpression(element);
	
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
std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp_as_last_in_CollectionRange(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl(par_CollectionRange));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CollectionRange.lock())
	{
		wp->setLast(element);
	
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
std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp_as_source_in_CallExp(std::weak_ptr<ocl::Expressions::CallExp> par_CallExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl(par_CallExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_CallExp.lock())
	{
		wp->setSource(element);
	
	}
	element->setThisVariableExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp_as_thenExpression_in_IfExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl(par_IfExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_IfExp.lock())
	{
		wp->setThenExpression(element);
	
	}
	element->setThisVariableExpPtr(element);
	return element;
	
}

