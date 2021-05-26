#include "ocl/Expressions/impl/ExpressionsFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "ocl/Expressions/ExpressionsPackage.hpp"
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

#include "ocl/Expressions/CallExp.hpp"
#include "ocl/Expressions/IterateExp.hpp"
#include "ocl/Expressions/IfExp.hpp"
#include "ocl/Expressions/CollectionRange.hpp"
#include "ocl/Expressions/IfExp.hpp"
#include "ocl/Expressions/Variable.hpp"
#include "ocl/Expressions/CollectionRange.hpp"
#include "ocl/Expressions/LoopExp.hpp"
#include "ocl/Expressions/LoopExp.hpp"
#include "ocl/Expressions/OperationCallExp.hpp"
#include "ocl/Expressions/NavigationCallExp.hpp"
#include "ocl/Expressions/ExpressionInOcl.hpp"
#include "ocl/Expressions/ExpressionInOcl.hpp"
#include "ocl/Expressions/IfExp.hpp"
#include "ocl/Expressions/ExpressionInOcl.hpp"
#include "ocl/Expressions/ExpressionInOcl.hpp"


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
					//AssociationClassCallExp has appliedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_APPLIEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createAssociationClassCallExp_in_AppliedElement(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has elseOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createAssociationClassCallExp_in_ElseOwner(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has firstOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createAssociationClassCallExp_in_FirstOwner(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has ifOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createAssociationClassCallExp_in_IfOwner(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has initializedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_INITIALIZEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createAssociationClassCallExp_in_InitializedElement(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has lastOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createAssociationClassCallExp_in_LastOwner(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has loopBodyOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createAssociationClassCallExp_in_LoopBodyOwner(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has parentCall as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTCALL:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createAssociationClassCallExp_in_ParentCall(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has parentNav as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTNAV:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createAssociationClassCallExp_in_ParentNav(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has thenOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createAssociationClassCallExp_in_ThenOwner(castedContainer,metaElementID);
					}
					//AssociationClassCallExp has topExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_TOPEXPRESSION:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createAssociationClassCallExp_in_TopExpression(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
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
					//BooleanLiteralExp has appliedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_APPLIEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createBooleanLiteralExp_in_AppliedElement(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has elseOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createBooleanLiteralExp_in_ElseOwner(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has firstOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createBooleanLiteralExp_in_FirstOwner(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has ifOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createBooleanLiteralExp_in_IfOwner(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has initializedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_INITIALIZEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createBooleanLiteralExp_in_InitializedElement(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has lastOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createBooleanLiteralExp_in_LastOwner(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has loopBodyOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createBooleanLiteralExp_in_LoopBodyOwner(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has parentCall as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTCALL:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createBooleanLiteralExp_in_ParentCall(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has parentNav as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTNAV:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createBooleanLiteralExp_in_ParentNav(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has thenOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createBooleanLiteralExp_in_ThenOwner(castedContainer,metaElementID);
					}
					//BooleanLiteralExp has topExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_TOPEXPRESSION:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createBooleanLiteralExp_in_TopExpression(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case ExpressionsPackage::COLLECTIONITEM_CLASS:
		{
				return this->createCollectionItem(metaElementID);
			
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
					//CollectionLiteralExp has appliedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_APPLIEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createCollectionLiteralExp_in_AppliedElement(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has elseOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createCollectionLiteralExp_in_ElseOwner(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has firstOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createCollectionLiteralExp_in_FirstOwner(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has ifOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createCollectionLiteralExp_in_IfOwner(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has initializedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_INITIALIZEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createCollectionLiteralExp_in_InitializedElement(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has lastOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createCollectionLiteralExp_in_LastOwner(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has loopBodyOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createCollectionLiteralExp_in_LoopBodyOwner(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has parentCall as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTCALL:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createCollectionLiteralExp_in_ParentCall(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has parentNav as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTNAV:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createCollectionLiteralExp_in_ParentNav(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has thenOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createCollectionLiteralExp_in_ThenOwner(castedContainer,metaElementID);
					}
					//CollectionLiteralExp has topExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_TOPEXPRESSION:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createCollectionLiteralExp_in_TopExpression(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case ExpressionsPackage::COLLECTIONRANGE_CLASS:
		{
				return this->createCollectionRange(metaElementID);
			
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
					//EnumLiteralExp has appliedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_APPLIEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createEnumLiteralExp_in_AppliedElement(castedContainer,metaElementID);
					}
					//EnumLiteralExp has elseOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createEnumLiteralExp_in_ElseOwner(castedContainer,metaElementID);
					}
					//EnumLiteralExp has firstOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createEnumLiteralExp_in_FirstOwner(castedContainer,metaElementID);
					}
					//EnumLiteralExp has ifOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createEnumLiteralExp_in_IfOwner(castedContainer,metaElementID);
					}
					//EnumLiteralExp has initializedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_INITIALIZEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createEnumLiteralExp_in_InitializedElement(castedContainer,metaElementID);
					}
					//EnumLiteralExp has lastOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createEnumLiteralExp_in_LastOwner(castedContainer,metaElementID);
					}
					//EnumLiteralExp has loopBodyOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createEnumLiteralExp_in_LoopBodyOwner(castedContainer,metaElementID);
					}
					//EnumLiteralExp has parentCall as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTCALL:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createEnumLiteralExp_in_ParentCall(castedContainer,metaElementID);
					}
					//EnumLiteralExp has parentNav as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTNAV:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createEnumLiteralExp_in_ParentNav(castedContainer,metaElementID);
					}
					//EnumLiteralExp has thenOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createEnumLiteralExp_in_ThenOwner(castedContainer,metaElementID);
					}
					//EnumLiteralExp has topExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_TOPEXPRESSION:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createEnumLiteralExp_in_TopExpression(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case ExpressionsPackage::EXPRESSIONINOCL_CLASS:
		{
				return this->createExpressionInOcl(metaElementID);
			
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
					//IfExp has appliedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_APPLIEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createIfExp_in_AppliedElement(castedContainer,metaElementID);
					}
					//IfExp has elseOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createIfExp_in_ElseOwner(castedContainer,metaElementID);
					}
					//IfExp has firstOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createIfExp_in_FirstOwner(castedContainer,metaElementID);
					}
					//IfExp has ifOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createIfExp_in_IfOwner(castedContainer,metaElementID);
					}
					//IfExp has initializedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_INITIALIZEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createIfExp_in_InitializedElement(castedContainer,metaElementID);
					}
					//IfExp has lastOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createIfExp_in_LastOwner(castedContainer,metaElementID);
					}
					//IfExp has loopBodyOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createIfExp_in_LoopBodyOwner(castedContainer,metaElementID);
					}
					//IfExp has parentCall as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTCALL:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createIfExp_in_ParentCall(castedContainer,metaElementID);
					}
					//IfExp has parentNav as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTNAV:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createIfExp_in_ParentNav(castedContainer,metaElementID);
					}
					//IfExp has thenOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createIfExp_in_ThenOwner(castedContainer,metaElementID);
					}
					//IfExp has topExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_TOPEXPRESSION:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createIfExp_in_TopExpression(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
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
					//InfixedExp has appliedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_APPLIEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createInfixedExp_in_AppliedElement(castedContainer,metaElementID);
					}
					//InfixedExp has elseOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createInfixedExp_in_ElseOwner(castedContainer,metaElementID);
					}
					//InfixedExp has firstOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createInfixedExp_in_FirstOwner(castedContainer,metaElementID);
					}
					//InfixedExp has ifOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createInfixedExp_in_IfOwner(castedContainer,metaElementID);
					}
					//InfixedExp has initializedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_INITIALIZEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createInfixedExp_in_InitializedElement(castedContainer,metaElementID);
					}
					//InfixedExp has lastOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createInfixedExp_in_LastOwner(castedContainer,metaElementID);
					}
					//InfixedExp has loopBodyOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createInfixedExp_in_LoopBodyOwner(castedContainer,metaElementID);
					}
					//InfixedExp has parentCall as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTCALL:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createInfixedExp_in_ParentCall(castedContainer,metaElementID);
					}
					//InfixedExp has parentNav as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTNAV:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createInfixedExp_in_ParentNav(castedContainer,metaElementID);
					}
					//InfixedExp has thenOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createInfixedExp_in_ThenOwner(castedContainer,metaElementID);
					}
					//InfixedExp has topExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_TOPEXPRESSION:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createInfixedExp_in_TopExpression(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
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
					//IntegerLiteralExp has appliedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_APPLIEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createIntegerLiteralExp_in_AppliedElement(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has elseOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createIntegerLiteralExp_in_ElseOwner(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has firstOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createIntegerLiteralExp_in_FirstOwner(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has ifOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createIntegerLiteralExp_in_IfOwner(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has initializedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_INITIALIZEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createIntegerLiteralExp_in_InitializedElement(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has lastOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createIntegerLiteralExp_in_LastOwner(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has loopBodyOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createIntegerLiteralExp_in_LoopBodyOwner(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has parentCall as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTCALL:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createIntegerLiteralExp_in_ParentCall(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has parentNav as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTNAV:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createIntegerLiteralExp_in_ParentNav(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has thenOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createIntegerLiteralExp_in_ThenOwner(castedContainer,metaElementID);
					}
					//IntegerLiteralExp has topExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_TOPEXPRESSION:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createIntegerLiteralExp_in_TopExpression(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
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
					//InvalidLiteralExp has appliedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_APPLIEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createInvalidLiteralExp_in_AppliedElement(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has elseOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createInvalidLiteralExp_in_ElseOwner(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has firstOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createInvalidLiteralExp_in_FirstOwner(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has ifOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createInvalidLiteralExp_in_IfOwner(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has initializedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_INITIALIZEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createInvalidLiteralExp_in_InitializedElement(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has lastOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createInvalidLiteralExp_in_LastOwner(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has loopBodyOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createInvalidLiteralExp_in_LoopBodyOwner(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has parentCall as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTCALL:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createInvalidLiteralExp_in_ParentCall(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has parentNav as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTNAV:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createInvalidLiteralExp_in_ParentNav(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has thenOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createInvalidLiteralExp_in_ThenOwner(castedContainer,metaElementID);
					}
					//InvalidLiteralExp has topExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_TOPEXPRESSION:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createInvalidLiteralExp_in_TopExpression(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
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
					//IterateExp has appliedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_APPLIEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createIterateExp_in_AppliedElement(castedContainer,metaElementID);
					}
					//IterateExp has elseOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createIterateExp_in_ElseOwner(castedContainer,metaElementID);
					}
					//IterateExp has firstOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createIterateExp_in_FirstOwner(castedContainer,metaElementID);
					}
					//IterateExp has ifOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createIterateExp_in_IfOwner(castedContainer,metaElementID);
					}
					//IterateExp has initializedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_INITIALIZEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createIterateExp_in_InitializedElement(castedContainer,metaElementID);
					}
					//IterateExp has lastOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createIterateExp_in_LastOwner(castedContainer,metaElementID);
					}
					//IterateExp has loopBodyOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createIterateExp_in_LoopBodyOwner(castedContainer,metaElementID);
					}
					//IterateExp has parentCall as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTCALL:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createIterateExp_in_ParentCall(castedContainer,metaElementID);
					}
					//IterateExp has parentNav as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTNAV:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createIterateExp_in_ParentNav(castedContainer,metaElementID);
					}
					//IterateExp has thenOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createIterateExp_in_ThenOwner(castedContainer,metaElementID);
					}
					//IterateExp has topExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_TOPEXPRESSION:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createIterateExp_in_TopExpression(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
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
					//IteratorExp has appliedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_APPLIEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createIteratorExp_in_AppliedElement(castedContainer,metaElementID);
					}
					//IteratorExp has elseOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createIteratorExp_in_ElseOwner(castedContainer,metaElementID);
					}
					//IteratorExp has firstOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createIteratorExp_in_FirstOwner(castedContainer,metaElementID);
					}
					//IteratorExp has ifOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createIteratorExp_in_IfOwner(castedContainer,metaElementID);
					}
					//IteratorExp has initializedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_INITIALIZEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createIteratorExp_in_InitializedElement(castedContainer,metaElementID);
					}
					//IteratorExp has lastOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createIteratorExp_in_LastOwner(castedContainer,metaElementID);
					}
					//IteratorExp has loopBodyOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createIteratorExp_in_LoopBodyOwner(castedContainer,metaElementID);
					}
					//IteratorExp has parentCall as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTCALL:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createIteratorExp_in_ParentCall(castedContainer,metaElementID);
					}
					//IteratorExp has parentNav as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTNAV:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createIteratorExp_in_ParentNav(castedContainer,metaElementID);
					}
					//IteratorExp has thenOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createIteratorExp_in_ThenOwner(castedContainer,metaElementID);
					}
					//IteratorExp has topExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_TOPEXPRESSION:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createIteratorExp_in_TopExpression(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
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
					//LetExp has appliedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_APPLIEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createLetExp_in_AppliedElement(castedContainer,metaElementID);
					}
					//LetExp has elseOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createLetExp_in_ElseOwner(castedContainer,metaElementID);
					}
					//LetExp has firstOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createLetExp_in_FirstOwner(castedContainer,metaElementID);
					}
					//LetExp has ifOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createLetExp_in_IfOwner(castedContainer,metaElementID);
					}
					//LetExp has initializedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_INITIALIZEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createLetExp_in_InitializedElement(castedContainer,metaElementID);
					}
					//LetExp has lastOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createLetExp_in_LastOwner(castedContainer,metaElementID);
					}
					//LetExp has loopBodyOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createLetExp_in_LoopBodyOwner(castedContainer,metaElementID);
					}
					//LetExp has parentCall as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTCALL:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createLetExp_in_ParentCall(castedContainer,metaElementID);
					}
					//LetExp has parentNav as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTNAV:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createLetExp_in_ParentNav(castedContainer,metaElementID);
					}
					//LetExp has thenOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createLetExp_in_ThenOwner(castedContainer,metaElementID);
					}
					//LetExp has topExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_TOPEXPRESSION:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createLetExp_in_TopExpression(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
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
					//MessageExp has appliedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_APPLIEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createMessageExp_in_AppliedElement(castedContainer,metaElementID);
					}
					//MessageExp has elseOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createMessageExp_in_ElseOwner(castedContainer,metaElementID);
					}
					//MessageExp has firstOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createMessageExp_in_FirstOwner(castedContainer,metaElementID);
					}
					//MessageExp has ifOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createMessageExp_in_IfOwner(castedContainer,metaElementID);
					}
					//MessageExp has initializedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_INITIALIZEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createMessageExp_in_InitializedElement(castedContainer,metaElementID);
					}
					//MessageExp has lastOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createMessageExp_in_LastOwner(castedContainer,metaElementID);
					}
					//MessageExp has loopBodyOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createMessageExp_in_LoopBodyOwner(castedContainer,metaElementID);
					}
					//MessageExp has parentCall as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTCALL:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createMessageExp_in_ParentCall(castedContainer,metaElementID);
					}
					//MessageExp has parentNav as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTNAV:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createMessageExp_in_ParentNav(castedContainer,metaElementID);
					}
					//MessageExp has thenOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createMessageExp_in_ThenOwner(castedContainer,metaElementID);
					}
					//MessageExp has topExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_TOPEXPRESSION:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createMessageExp_in_TopExpression(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
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
					//NullLiteralExp has appliedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_APPLIEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createNullLiteralExp_in_AppliedElement(castedContainer,metaElementID);
					}
					//NullLiteralExp has elseOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createNullLiteralExp_in_ElseOwner(castedContainer,metaElementID);
					}
					//NullLiteralExp has firstOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createNullLiteralExp_in_FirstOwner(castedContainer,metaElementID);
					}
					//NullLiteralExp has ifOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createNullLiteralExp_in_IfOwner(castedContainer,metaElementID);
					}
					//NullLiteralExp has initializedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_INITIALIZEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createNullLiteralExp_in_InitializedElement(castedContainer,metaElementID);
					}
					//NullLiteralExp has lastOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createNullLiteralExp_in_LastOwner(castedContainer,metaElementID);
					}
					//NullLiteralExp has loopBodyOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createNullLiteralExp_in_LoopBodyOwner(castedContainer,metaElementID);
					}
					//NullLiteralExp has parentCall as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTCALL:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createNullLiteralExp_in_ParentCall(castedContainer,metaElementID);
					}
					//NullLiteralExp has parentNav as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTNAV:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createNullLiteralExp_in_ParentNav(castedContainer,metaElementID);
					}
					//NullLiteralExp has thenOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createNullLiteralExp_in_ThenOwner(castedContainer,metaElementID);
					}
					//NullLiteralExp has topExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_TOPEXPRESSION:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createNullLiteralExp_in_TopExpression(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
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
					//OperationCallExp has appliedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_APPLIEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createOperationCallExp_in_AppliedElement(castedContainer,metaElementID);
					}
					//OperationCallExp has elseOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createOperationCallExp_in_ElseOwner(castedContainer,metaElementID);
					}
					//OperationCallExp has firstOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createOperationCallExp_in_FirstOwner(castedContainer,metaElementID);
					}
					//OperationCallExp has ifOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createOperationCallExp_in_IfOwner(castedContainer,metaElementID);
					}
					//OperationCallExp has initializedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_INITIALIZEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createOperationCallExp_in_InitializedElement(castedContainer,metaElementID);
					}
					//OperationCallExp has lastOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createOperationCallExp_in_LastOwner(castedContainer,metaElementID);
					}
					//OperationCallExp has loopBodyOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createOperationCallExp_in_LoopBodyOwner(castedContainer,metaElementID);
					}
					//OperationCallExp has parentCall as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTCALL:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createOperationCallExp_in_ParentCall(castedContainer,metaElementID);
					}
					//OperationCallExp has parentNav as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTNAV:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createOperationCallExp_in_ParentNav(castedContainer,metaElementID);
					}
					//OperationCallExp has thenOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createOperationCallExp_in_ThenOwner(castedContainer,metaElementID);
					}
					//OperationCallExp has topExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_TOPEXPRESSION:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createOperationCallExp_in_TopExpression(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
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
					//PropertyCallExp has appliedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_APPLIEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createPropertyCallExp_in_AppliedElement(castedContainer,metaElementID);
					}
					//PropertyCallExp has elseOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createPropertyCallExp_in_ElseOwner(castedContainer,metaElementID);
					}
					//PropertyCallExp has firstOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createPropertyCallExp_in_FirstOwner(castedContainer,metaElementID);
					}
					//PropertyCallExp has ifOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createPropertyCallExp_in_IfOwner(castedContainer,metaElementID);
					}
					//PropertyCallExp has initializedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_INITIALIZEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createPropertyCallExp_in_InitializedElement(castedContainer,metaElementID);
					}
					//PropertyCallExp has lastOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createPropertyCallExp_in_LastOwner(castedContainer,metaElementID);
					}
					//PropertyCallExp has loopBodyOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createPropertyCallExp_in_LoopBodyOwner(castedContainer,metaElementID);
					}
					//PropertyCallExp has parentCall as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTCALL:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createPropertyCallExp_in_ParentCall(castedContainer,metaElementID);
					}
					//PropertyCallExp has parentNav as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTNAV:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createPropertyCallExp_in_ParentNav(castedContainer,metaElementID);
					}
					//PropertyCallExp has thenOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createPropertyCallExp_in_ThenOwner(castedContainer,metaElementID);
					}
					//PropertyCallExp has topExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_TOPEXPRESSION:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createPropertyCallExp_in_TopExpression(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
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
					//RealLiteralExp has appliedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_APPLIEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createRealLiteralExp_in_AppliedElement(castedContainer,metaElementID);
					}
					//RealLiteralExp has elseOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createRealLiteralExp_in_ElseOwner(castedContainer,metaElementID);
					}
					//RealLiteralExp has firstOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createRealLiteralExp_in_FirstOwner(castedContainer,metaElementID);
					}
					//RealLiteralExp has ifOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createRealLiteralExp_in_IfOwner(castedContainer,metaElementID);
					}
					//RealLiteralExp has initializedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_INITIALIZEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createRealLiteralExp_in_InitializedElement(castedContainer,metaElementID);
					}
					//RealLiteralExp has lastOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createRealLiteralExp_in_LastOwner(castedContainer,metaElementID);
					}
					//RealLiteralExp has loopBodyOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createRealLiteralExp_in_LoopBodyOwner(castedContainer,metaElementID);
					}
					//RealLiteralExp has parentCall as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTCALL:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createRealLiteralExp_in_ParentCall(castedContainer,metaElementID);
					}
					//RealLiteralExp has parentNav as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTNAV:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createRealLiteralExp_in_ParentNav(castedContainer,metaElementID);
					}
					//RealLiteralExp has thenOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createRealLiteralExp_in_ThenOwner(castedContainer,metaElementID);
					}
					//RealLiteralExp has topExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_TOPEXPRESSION:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createRealLiteralExp_in_TopExpression(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
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
					//StateExp has appliedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_APPLIEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createStateExp_in_AppliedElement(castedContainer,metaElementID);
					}
					//StateExp has elseOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createStateExp_in_ElseOwner(castedContainer,metaElementID);
					}
					//StateExp has firstOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createStateExp_in_FirstOwner(castedContainer,metaElementID);
					}
					//StateExp has ifOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createStateExp_in_IfOwner(castedContainer,metaElementID);
					}
					//StateExp has initializedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_INITIALIZEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createStateExp_in_InitializedElement(castedContainer,metaElementID);
					}
					//StateExp has lastOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createStateExp_in_LastOwner(castedContainer,metaElementID);
					}
					//StateExp has loopBodyOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createStateExp_in_LoopBodyOwner(castedContainer,metaElementID);
					}
					//StateExp has parentCall as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTCALL:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createStateExp_in_ParentCall(castedContainer,metaElementID);
					}
					//StateExp has parentNav as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTNAV:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createStateExp_in_ParentNav(castedContainer,metaElementID);
					}
					//StateExp has thenOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createStateExp_in_ThenOwner(castedContainer,metaElementID);
					}
					//StateExp has topExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_TOPEXPRESSION:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createStateExp_in_TopExpression(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
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
					//StringLiteralExp has appliedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_APPLIEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createStringLiteralExp_in_AppliedElement(castedContainer,metaElementID);
					}
					//StringLiteralExp has elseOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createStringLiteralExp_in_ElseOwner(castedContainer,metaElementID);
					}
					//StringLiteralExp has firstOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createStringLiteralExp_in_FirstOwner(castedContainer,metaElementID);
					}
					//StringLiteralExp has ifOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createStringLiteralExp_in_IfOwner(castedContainer,metaElementID);
					}
					//StringLiteralExp has initializedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_INITIALIZEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createStringLiteralExp_in_InitializedElement(castedContainer,metaElementID);
					}
					//StringLiteralExp has lastOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createStringLiteralExp_in_LastOwner(castedContainer,metaElementID);
					}
					//StringLiteralExp has loopBodyOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createStringLiteralExp_in_LoopBodyOwner(castedContainer,metaElementID);
					}
					//StringLiteralExp has parentCall as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTCALL:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createStringLiteralExp_in_ParentCall(castedContainer,metaElementID);
					}
					//StringLiteralExp has parentNav as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTNAV:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createStringLiteralExp_in_ParentNav(castedContainer,metaElementID);
					}
					//StringLiteralExp has thenOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createStringLiteralExp_in_ThenOwner(castedContainer,metaElementID);
					}
					//StringLiteralExp has topExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_TOPEXPRESSION:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createStringLiteralExp_in_TopExpression(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
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
					//TupleLiteralExp has appliedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_APPLIEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createTupleLiteralExp_in_AppliedElement(castedContainer,metaElementID);
					}
					//TupleLiteralExp has elseOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createTupleLiteralExp_in_ElseOwner(castedContainer,metaElementID);
					}
					//TupleLiteralExp has firstOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createTupleLiteralExp_in_FirstOwner(castedContainer,metaElementID);
					}
					//TupleLiteralExp has ifOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createTupleLiteralExp_in_IfOwner(castedContainer,metaElementID);
					}
					//TupleLiteralExp has initializedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_INITIALIZEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createTupleLiteralExp_in_InitializedElement(castedContainer,metaElementID);
					}
					//TupleLiteralExp has lastOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createTupleLiteralExp_in_LastOwner(castedContainer,metaElementID);
					}
					//TupleLiteralExp has loopBodyOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createTupleLiteralExp_in_LoopBodyOwner(castedContainer,metaElementID);
					}
					//TupleLiteralExp has parentCall as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTCALL:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createTupleLiteralExp_in_ParentCall(castedContainer,metaElementID);
					}
					//TupleLiteralExp has parentNav as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTNAV:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createTupleLiteralExp_in_ParentNav(castedContainer,metaElementID);
					}
					//TupleLiteralExp has thenOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createTupleLiteralExp_in_ThenOwner(castedContainer,metaElementID);
					}
					//TupleLiteralExp has topExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_TOPEXPRESSION:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createTupleLiteralExp_in_TopExpression(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case ExpressionsPackage::TUPLELITERALPART_CLASS:
		{
				return this->createTupleLiteralPart(metaElementID);
			
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
					//TypeExp has appliedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_APPLIEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createTypeExp_in_AppliedElement(castedContainer,metaElementID);
					}
					//TypeExp has elseOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createTypeExp_in_ElseOwner(castedContainer,metaElementID);
					}
					//TypeExp has firstOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createTypeExp_in_FirstOwner(castedContainer,metaElementID);
					}
					//TypeExp has ifOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createTypeExp_in_IfOwner(castedContainer,metaElementID);
					}
					//TypeExp has initializedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_INITIALIZEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createTypeExp_in_InitializedElement(castedContainer,metaElementID);
					}
					//TypeExp has lastOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createTypeExp_in_LastOwner(castedContainer,metaElementID);
					}
					//TypeExp has loopBodyOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createTypeExp_in_LoopBodyOwner(castedContainer,metaElementID);
					}
					//TypeExp has parentCall as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTCALL:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createTypeExp_in_ParentCall(castedContainer,metaElementID);
					}
					//TypeExp has parentNav as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTNAV:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createTypeExp_in_ParentNav(castedContainer,metaElementID);
					}
					//TypeExp has thenOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createTypeExp_in_ThenOwner(castedContainer,metaElementID);
					}
					//TypeExp has topExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_TOPEXPRESSION:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createTypeExp_in_TopExpression(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
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
					//UnlimitedNaturalExp has appliedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_APPLIEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createUnlimitedNaturalExp_in_AppliedElement(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has elseOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createUnlimitedNaturalExp_in_ElseOwner(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has firstOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createUnlimitedNaturalExp_in_FirstOwner(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has ifOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createUnlimitedNaturalExp_in_IfOwner(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has initializedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_INITIALIZEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createUnlimitedNaturalExp_in_InitializedElement(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has lastOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createUnlimitedNaturalExp_in_LastOwner(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has loopBodyOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createUnlimitedNaturalExp_in_LoopBodyOwner(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has parentCall as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTCALL:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createUnlimitedNaturalExp_in_ParentCall(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has parentNav as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTNAV:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createUnlimitedNaturalExp_in_ParentNav(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has thenOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createUnlimitedNaturalExp_in_ThenOwner(castedContainer,metaElementID);
					}
					//UnlimitedNaturalExp has topExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_TOPEXPRESSION:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createUnlimitedNaturalExp_in_TopExpression(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
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
					//UnspecifiedValueExp has appliedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_APPLIEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createUnspecifiedValueExp_in_AppliedElement(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has elseOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createUnspecifiedValueExp_in_ElseOwner(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has firstOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createUnspecifiedValueExp_in_FirstOwner(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has ifOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createUnspecifiedValueExp_in_IfOwner(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has initializedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_INITIALIZEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createUnspecifiedValueExp_in_InitializedElement(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has lastOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createUnspecifiedValueExp_in_LastOwner(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has loopBodyOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createUnspecifiedValueExp_in_LoopBodyOwner(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has parentCall as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTCALL:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createUnspecifiedValueExp_in_ParentCall(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has parentNav as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTNAV:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createUnspecifiedValueExp_in_ParentNav(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has thenOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createUnspecifiedValueExp_in_ThenOwner(castedContainer,metaElementID);
					}
					//UnspecifiedValueExp has topExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_TOPEXPRESSION:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createUnspecifiedValueExp_in_TopExpression(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
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
					//Variable has baseExp as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_BASEEXP:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp>(container);
						return this->createVariable_in_BaseExp(castedContainer,metaElementID);
					}
					//Variable has loopExp as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_LOOPEXP:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createVariable_in_LoopExp(castedContainer,metaElementID);
					}
					//Variable has resultOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_RESULTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createVariable_in_ResultOwner(castedContainer,metaElementID);
					}
					//Variable has selfOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_SELFOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createVariable_in_SelfOwner(castedContainer,metaElementID);
					}
					//Variable has varOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_VAROWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createVariable_in_VarOwner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
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
					//VariableExp has appliedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_APPLIEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(container);
						return this->createVariableExp_in_AppliedElement(castedContainer,metaElementID);
					}
					//VariableExp has elseOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createVariableExp_in_ElseOwner(castedContainer,metaElementID);
					}
					//VariableExp has firstOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createVariableExp_in_FirstOwner(castedContainer,metaElementID);
					}
					//VariableExp has ifOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createVariableExp_in_IfOwner(castedContainer,metaElementID);
					}
					//VariableExp has initializedElement as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_INITIALIZEDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::Variable>(container);
						return this->createVariableExp_in_InitializedElement(castedContainer,metaElementID);
					}
					//VariableExp has lastOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(container);
						return this->createVariableExp_in_LastOwner(castedContainer,metaElementID);
					}
					//VariableExp has loopBodyOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(container);
						return this->createVariableExp_in_LoopBodyOwner(castedContainer,metaElementID);
					}
					//VariableExp has parentCall as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTCALL:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(container);
						return this->createVariableExp_in_ParentCall(castedContainer,metaElementID);
					}
					//VariableExp has parentNav as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTNAV:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(container);
						return this->createVariableExp_in_ParentNav(castedContainer,metaElementID);
					}
					//VariableExp has thenOwner as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(container);
						return this->createVariableExp_in_ThenOwner(castedContainer,metaElementID);
					}
					//VariableExp has topExpression as a containment
					case  ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_TOPEXPRESSION:
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(container);
						return this->createVariableExp_in_TopExpression(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
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

std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp_in_AppliedElement(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl(par_appliedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_appliedElement.lock())
	{
			wp->setSource(element);
	}
	element->setThisAssociationClassCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp_in_ElseOwner(std::weak_ptr<ocl::Expressions::IfExp> par_elseOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl(par_elseOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_elseOwner.lock())
	{
			wp->setElseExpression(element);
	}
	element->setThisAssociationClassCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp_in_FirstOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_firstOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl(par_firstOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_firstOwner.lock())
	{
			wp->setFirst(element);
	}
	element->setThisAssociationClassCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp_in_IfOwner(std::weak_ptr<ocl::Expressions::IfExp> par_ifOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl(par_ifOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ifOwner.lock())
	{
			wp->setCondition(element);
	}
	element->setThisAssociationClassCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp_in_InitializedElement(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl(par_initializedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_initializedElement.lock())
	{
			wp->setInitExpression(element);
	}
	element->setThisAssociationClassCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp_in_LastOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_lastOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl(par_lastOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_lastOwner.lock())
	{
			wp->setLast(element);
	}
	element->setThisAssociationClassCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp_in_LoopBodyOwner(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl(par_loopBodyOwner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_loopBodyOwner.lock())
	{
			wp->setBody(element);
	}
	element->setThisAssociationClassCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp_in_ParentCall(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl(par_parentCall));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentCall.lock())
	{
			wp->getArgument()->push_back(element);
	}
	element->setThisAssociationClassCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp_in_ParentNav(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl(par_parentNav));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentNav.lock())
	{
			wp->getQualifier()->push_back(element);
	}
	element->setThisAssociationClassCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp_in_ThenOwner(std::weak_ptr<ocl::Expressions::IfExp> par_thenOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl(par_thenOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_thenOwner.lock())
	{
			wp->setThenExpression(element);
	}
	element->setThisAssociationClassCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::AssociationClassCallExp> ExpressionsFactoryImpl::createAssociationClassCallExp_in_TopExpression(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::AssociationClassCallExpImpl> element(new ocl::Expressions::AssociationClassCallExpImpl(par_topExpression));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_topExpression.lock())
	{
			wp->setBodyExpression(element);
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

std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp_in_AppliedElement(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl(par_appliedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_appliedElement.lock())
	{
			wp->setSource(element);
	}
	element->setThisBooleanLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp_in_ElseOwner(std::weak_ptr<ocl::Expressions::IfExp> par_elseOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl(par_elseOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_elseOwner.lock())
	{
			wp->setElseExpression(element);
	}
	element->setThisBooleanLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp_in_FirstOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_firstOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl(par_firstOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_firstOwner.lock())
	{
			wp->setFirst(element);
	}
	element->setThisBooleanLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp_in_IfOwner(std::weak_ptr<ocl::Expressions::IfExp> par_ifOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl(par_ifOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ifOwner.lock())
	{
			wp->setCondition(element);
	}
	element->setThisBooleanLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp_in_InitializedElement(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl(par_initializedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_initializedElement.lock())
	{
			wp->setInitExpression(element);
	}
	element->setThisBooleanLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp_in_LastOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_lastOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl(par_lastOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_lastOwner.lock())
	{
			wp->setLast(element);
	}
	element->setThisBooleanLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp_in_LoopBodyOwner(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl(par_loopBodyOwner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_loopBodyOwner.lock())
	{
			wp->setBody(element);
	}
	element->setThisBooleanLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp_in_ParentCall(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl(par_parentCall));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentCall.lock())
	{
			wp->getArgument()->push_back(element);
	}
	element->setThisBooleanLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp_in_ParentNav(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl(par_parentNav));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentNav.lock())
	{
			wp->getQualifier()->push_back(element);
	}
	element->setThisBooleanLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp_in_ThenOwner(std::weak_ptr<ocl::Expressions::IfExp> par_thenOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl(par_thenOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_thenOwner.lock())
	{
			wp->setThenExpression(element);
	}
	element->setThisBooleanLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::BooleanLiteralExp> ExpressionsFactoryImpl::createBooleanLiteralExp_in_TopExpression(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::BooleanLiteralExpImpl> element(new ocl::Expressions::BooleanLiteralExpImpl(par_topExpression));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_topExpression.lock())
	{
			wp->setBodyExpression(element);
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

std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCollectionLiteralExpPtr(element);
	return element;
}

std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp_in_AppliedElement(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl(par_appliedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_appliedElement.lock())
	{
			wp->setSource(element);
	}
	element->setThisCollectionLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp_in_ElseOwner(std::weak_ptr<ocl::Expressions::IfExp> par_elseOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl(par_elseOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_elseOwner.lock())
	{
			wp->setElseExpression(element);
	}
	element->setThisCollectionLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp_in_FirstOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_firstOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl(par_firstOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_firstOwner.lock())
	{
			wp->setFirst(element);
	}
	element->setThisCollectionLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp_in_IfOwner(std::weak_ptr<ocl::Expressions::IfExp> par_ifOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl(par_ifOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ifOwner.lock())
	{
			wp->setCondition(element);
	}
	element->setThisCollectionLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp_in_InitializedElement(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl(par_initializedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_initializedElement.lock())
	{
			wp->setInitExpression(element);
	}
	element->setThisCollectionLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp_in_LastOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_lastOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl(par_lastOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_lastOwner.lock())
	{
			wp->setLast(element);
	}
	element->setThisCollectionLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp_in_LoopBodyOwner(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl(par_loopBodyOwner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_loopBodyOwner.lock())
	{
			wp->setBody(element);
	}
	element->setThisCollectionLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp_in_ParentCall(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl(par_parentCall));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentCall.lock())
	{
			wp->getArgument()->push_back(element);
	}
	element->setThisCollectionLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp_in_ParentNav(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl(par_parentNav));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentNav.lock())
	{
			wp->getQualifier()->push_back(element);
	}
	element->setThisCollectionLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp_in_ThenOwner(std::weak_ptr<ocl::Expressions::IfExp> par_thenOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl(par_thenOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_thenOwner.lock())
	{
			wp->setThenExpression(element);
	}
	element->setThisCollectionLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::CollectionLiteralExp> ExpressionsFactoryImpl::createCollectionLiteralExp_in_TopExpression(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::CollectionLiteralExpImpl> element(new ocl::Expressions::CollectionLiteralExpImpl(par_topExpression));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_topExpression.lock())
	{
			wp->setBodyExpression(element);
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

std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEnumLiteralExpPtr(element);
	return element;
}

std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp_in_AppliedElement(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl(par_appliedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_appliedElement.lock())
	{
			wp->setSource(element);
	}
	element->setThisEnumLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp_in_ElseOwner(std::weak_ptr<ocl::Expressions::IfExp> par_elseOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl(par_elseOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_elseOwner.lock())
	{
			wp->setElseExpression(element);
	}
	element->setThisEnumLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp_in_FirstOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_firstOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl(par_firstOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_firstOwner.lock())
	{
			wp->setFirst(element);
	}
	element->setThisEnumLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp_in_IfOwner(std::weak_ptr<ocl::Expressions::IfExp> par_ifOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl(par_ifOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ifOwner.lock())
	{
			wp->setCondition(element);
	}
	element->setThisEnumLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp_in_InitializedElement(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl(par_initializedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_initializedElement.lock())
	{
			wp->setInitExpression(element);
	}
	element->setThisEnumLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp_in_LastOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_lastOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl(par_lastOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_lastOwner.lock())
	{
			wp->setLast(element);
	}
	element->setThisEnumLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp_in_LoopBodyOwner(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl(par_loopBodyOwner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_loopBodyOwner.lock())
	{
			wp->setBody(element);
	}
	element->setThisEnumLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp_in_ParentCall(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl(par_parentCall));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentCall.lock())
	{
			wp->getArgument()->push_back(element);
	}
	element->setThisEnumLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp_in_ParentNav(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl(par_parentNav));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentNav.lock())
	{
			wp->getQualifier()->push_back(element);
	}
	element->setThisEnumLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp_in_ThenOwner(std::weak_ptr<ocl::Expressions::IfExp> par_thenOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl(par_thenOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_thenOwner.lock())
	{
			wp->setThenExpression(element);
	}
	element->setThisEnumLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::EnumLiteralExp> ExpressionsFactoryImpl::createEnumLiteralExp_in_TopExpression(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::EnumLiteralExpImpl> element(new ocl::Expressions::EnumLiteralExpImpl(par_topExpression));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_topExpression.lock())
	{
			wp->setBodyExpression(element);
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

std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_in_AppliedElement(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl(par_appliedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_appliedElement.lock())
	{
			wp->setSource(element);
	}
	element->setThisIfExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_in_ElseOwner(std::weak_ptr<ocl::Expressions::IfExp> par_elseOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl(par_elseOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_elseOwner.lock())
	{
			wp->setElseExpression(element);
	}
	element->setThisIfExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_in_FirstOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_firstOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl(par_firstOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_firstOwner.lock())
	{
			wp->setFirst(element);
	}
	element->setThisIfExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_in_IfOwner(std::weak_ptr<ocl::Expressions::IfExp> par_ifOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl(par_ifOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ifOwner.lock())
	{
			wp->setCondition(element);
	}
	element->setThisIfExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_in_InitializedElement(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl(par_initializedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_initializedElement.lock())
	{
			wp->setInitExpression(element);
	}
	element->setThisIfExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_in_LastOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_lastOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl(par_lastOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_lastOwner.lock())
	{
			wp->setLast(element);
	}
	element->setThisIfExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_in_LoopBodyOwner(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl(par_loopBodyOwner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_loopBodyOwner.lock())
	{
			wp->setBody(element);
	}
	element->setThisIfExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_in_ParentCall(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl(par_parentCall));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentCall.lock())
	{
			wp->getArgument()->push_back(element);
	}
	element->setThisIfExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_in_ParentNav(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl(par_parentNav));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentNav.lock())
	{
			wp->getQualifier()->push_back(element);
	}
	element->setThisIfExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_in_ThenOwner(std::weak_ptr<ocl::Expressions::IfExp> par_thenOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl(par_thenOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_thenOwner.lock())
	{
			wp->setThenExpression(element);
	}
	element->setThisIfExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IfExp> ExpressionsFactoryImpl::createIfExp_in_TopExpression(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IfExpImpl> element(new ocl::Expressions::IfExpImpl(par_topExpression));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_topExpression.lock())
	{
			wp->setBodyExpression(element);
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

std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp_in_AppliedElement(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl(par_appliedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_appliedElement.lock())
	{
			wp->setSource(element);
	}
	element->setThisInfixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp_in_ElseOwner(std::weak_ptr<ocl::Expressions::IfExp> par_elseOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl(par_elseOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_elseOwner.lock())
	{
			wp->setElseExpression(element);
	}
	element->setThisInfixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp_in_FirstOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_firstOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl(par_firstOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_firstOwner.lock())
	{
			wp->setFirst(element);
	}
	element->setThisInfixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp_in_IfOwner(std::weak_ptr<ocl::Expressions::IfExp> par_ifOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl(par_ifOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ifOwner.lock())
	{
			wp->setCondition(element);
	}
	element->setThisInfixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp_in_InitializedElement(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl(par_initializedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_initializedElement.lock())
	{
			wp->setInitExpression(element);
	}
	element->setThisInfixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp_in_LastOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_lastOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl(par_lastOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_lastOwner.lock())
	{
			wp->setLast(element);
	}
	element->setThisInfixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp_in_LoopBodyOwner(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl(par_loopBodyOwner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_loopBodyOwner.lock())
	{
			wp->setBody(element);
	}
	element->setThisInfixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp_in_ParentCall(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl(par_parentCall));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentCall.lock())
	{
			wp->getArgument()->push_back(element);
	}
	element->setThisInfixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp_in_ParentNav(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl(par_parentNav));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentNav.lock())
	{
			wp->getQualifier()->push_back(element);
	}
	element->setThisInfixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp_in_ThenOwner(std::weak_ptr<ocl::Expressions::IfExp> par_thenOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl(par_thenOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_thenOwner.lock())
	{
			wp->setThenExpression(element);
	}
	element->setThisInfixedExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InfixedExp> ExpressionsFactoryImpl::createInfixedExp_in_TopExpression(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InfixedExpImpl> element(new ocl::Expressions::InfixedExpImpl(par_topExpression));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_topExpression.lock())
	{
			wp->setBodyExpression(element);
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

std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp_in_AppliedElement(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl(par_appliedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_appliedElement.lock())
	{
			wp->setSource(element);
	}
	element->setThisIntegerLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp_in_ElseOwner(std::weak_ptr<ocl::Expressions::IfExp> par_elseOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl(par_elseOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_elseOwner.lock())
	{
			wp->setElseExpression(element);
	}
	element->setThisIntegerLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp_in_FirstOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_firstOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl(par_firstOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_firstOwner.lock())
	{
			wp->setFirst(element);
	}
	element->setThisIntegerLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp_in_IfOwner(std::weak_ptr<ocl::Expressions::IfExp> par_ifOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl(par_ifOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ifOwner.lock())
	{
			wp->setCondition(element);
	}
	element->setThisIntegerLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp_in_InitializedElement(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl(par_initializedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_initializedElement.lock())
	{
			wp->setInitExpression(element);
	}
	element->setThisIntegerLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp_in_LastOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_lastOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl(par_lastOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_lastOwner.lock())
	{
			wp->setLast(element);
	}
	element->setThisIntegerLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp_in_LoopBodyOwner(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl(par_loopBodyOwner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_loopBodyOwner.lock())
	{
			wp->setBody(element);
	}
	element->setThisIntegerLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp_in_ParentCall(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl(par_parentCall));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentCall.lock())
	{
			wp->getArgument()->push_back(element);
	}
	element->setThisIntegerLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp_in_ParentNav(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl(par_parentNav));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentNav.lock())
	{
			wp->getQualifier()->push_back(element);
	}
	element->setThisIntegerLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp_in_ThenOwner(std::weak_ptr<ocl::Expressions::IfExp> par_thenOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl(par_thenOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_thenOwner.lock())
	{
			wp->setThenExpression(element);
	}
	element->setThisIntegerLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IntegerLiteralExp> ExpressionsFactoryImpl::createIntegerLiteralExp_in_TopExpression(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IntegerLiteralExpImpl> element(new ocl::Expressions::IntegerLiteralExpImpl(par_topExpression));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_topExpression.lock())
	{
			wp->setBodyExpression(element);
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

std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp_in_AppliedElement(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl(par_appliedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_appliedElement.lock())
	{
			wp->setSource(element);
	}
	element->setThisInvalidLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp_in_ElseOwner(std::weak_ptr<ocl::Expressions::IfExp> par_elseOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl(par_elseOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_elseOwner.lock())
	{
			wp->setElseExpression(element);
	}
	element->setThisInvalidLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp_in_FirstOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_firstOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl(par_firstOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_firstOwner.lock())
	{
			wp->setFirst(element);
	}
	element->setThisInvalidLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp_in_IfOwner(std::weak_ptr<ocl::Expressions::IfExp> par_ifOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl(par_ifOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ifOwner.lock())
	{
			wp->setCondition(element);
	}
	element->setThisInvalidLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp_in_InitializedElement(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl(par_initializedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_initializedElement.lock())
	{
			wp->setInitExpression(element);
	}
	element->setThisInvalidLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp_in_LastOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_lastOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl(par_lastOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_lastOwner.lock())
	{
			wp->setLast(element);
	}
	element->setThisInvalidLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp_in_LoopBodyOwner(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl(par_loopBodyOwner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_loopBodyOwner.lock())
	{
			wp->setBody(element);
	}
	element->setThisInvalidLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp_in_ParentCall(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl(par_parentCall));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentCall.lock())
	{
			wp->getArgument()->push_back(element);
	}
	element->setThisInvalidLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp_in_ParentNav(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl(par_parentNav));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentNav.lock())
	{
			wp->getQualifier()->push_back(element);
	}
	element->setThisInvalidLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp_in_ThenOwner(std::weak_ptr<ocl::Expressions::IfExp> par_thenOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl(par_thenOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_thenOwner.lock())
	{
			wp->setThenExpression(element);
	}
	element->setThisInvalidLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::InvalidLiteralExp> ExpressionsFactoryImpl::createInvalidLiteralExp_in_TopExpression(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::InvalidLiteralExpImpl> element(new ocl::Expressions::InvalidLiteralExpImpl(par_topExpression));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_topExpression.lock())
	{
			wp->setBodyExpression(element);
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

std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp_in_AppliedElement(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl(par_appliedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_appliedElement.lock())
	{
			wp->setSource(element);
	}
	element->setThisIterateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp_in_ElseOwner(std::weak_ptr<ocl::Expressions::IfExp> par_elseOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl(par_elseOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_elseOwner.lock())
	{
			wp->setElseExpression(element);
	}
	element->setThisIterateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp_in_FirstOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_firstOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl(par_firstOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_firstOwner.lock())
	{
			wp->setFirst(element);
	}
	element->setThisIterateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp_in_IfOwner(std::weak_ptr<ocl::Expressions::IfExp> par_ifOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl(par_ifOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ifOwner.lock())
	{
			wp->setCondition(element);
	}
	element->setThisIterateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp_in_InitializedElement(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl(par_initializedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_initializedElement.lock())
	{
			wp->setInitExpression(element);
	}
	element->setThisIterateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp_in_LastOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_lastOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl(par_lastOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_lastOwner.lock())
	{
			wp->setLast(element);
	}
	element->setThisIterateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp_in_LoopBodyOwner(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl(par_loopBodyOwner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_loopBodyOwner.lock())
	{
			wp->setBody(element);
	}
	element->setThisIterateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp_in_ParentCall(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl(par_parentCall));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentCall.lock())
	{
			wp->getArgument()->push_back(element);
	}
	element->setThisIterateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp_in_ParentNav(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl(par_parentNav));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentNav.lock())
	{
			wp->getQualifier()->push_back(element);
	}
	element->setThisIterateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp_in_ThenOwner(std::weak_ptr<ocl::Expressions::IfExp> par_thenOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl(par_thenOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_thenOwner.lock())
	{
			wp->setThenExpression(element);
	}
	element->setThisIterateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IterateExp> ExpressionsFactoryImpl::createIterateExp_in_TopExpression(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IterateExpImpl> element(new ocl::Expressions::IterateExpImpl(par_topExpression));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_topExpression.lock())
	{
			wp->setBodyExpression(element);
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

std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp_in_AppliedElement(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl(par_appliedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_appliedElement.lock())
	{
			wp->setSource(element);
	}
	element->setThisIteratorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp_in_ElseOwner(std::weak_ptr<ocl::Expressions::IfExp> par_elseOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl(par_elseOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_elseOwner.lock())
	{
			wp->setElseExpression(element);
	}
	element->setThisIteratorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp_in_FirstOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_firstOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl(par_firstOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_firstOwner.lock())
	{
			wp->setFirst(element);
	}
	element->setThisIteratorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp_in_IfOwner(std::weak_ptr<ocl::Expressions::IfExp> par_ifOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl(par_ifOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ifOwner.lock())
	{
			wp->setCondition(element);
	}
	element->setThisIteratorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp_in_InitializedElement(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl(par_initializedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_initializedElement.lock())
	{
			wp->setInitExpression(element);
	}
	element->setThisIteratorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp_in_LastOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_lastOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl(par_lastOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_lastOwner.lock())
	{
			wp->setLast(element);
	}
	element->setThisIteratorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp_in_LoopBodyOwner(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl(par_loopBodyOwner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_loopBodyOwner.lock())
	{
			wp->setBody(element);
	}
	element->setThisIteratorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp_in_ParentCall(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl(par_parentCall));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentCall.lock())
	{
			wp->getArgument()->push_back(element);
	}
	element->setThisIteratorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp_in_ParentNav(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl(par_parentNav));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentNav.lock())
	{
			wp->getQualifier()->push_back(element);
	}
	element->setThisIteratorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp_in_ThenOwner(std::weak_ptr<ocl::Expressions::IfExp> par_thenOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl(par_thenOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_thenOwner.lock())
	{
			wp->setThenExpression(element);
	}
	element->setThisIteratorExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::IteratorExp> ExpressionsFactoryImpl::createIteratorExp_in_TopExpression(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::IteratorExpImpl> element(new ocl::Expressions::IteratorExpImpl(par_topExpression));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_topExpression.lock())
	{
			wp->setBodyExpression(element);
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

std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp_in_AppliedElement(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl(par_appliedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_appliedElement.lock())
	{
			wp->setSource(element);
	}
	element->setThisLetExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp_in_ElseOwner(std::weak_ptr<ocl::Expressions::IfExp> par_elseOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl(par_elseOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_elseOwner.lock())
	{
			wp->setElseExpression(element);
	}
	element->setThisLetExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp_in_FirstOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_firstOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl(par_firstOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_firstOwner.lock())
	{
			wp->setFirst(element);
	}
	element->setThisLetExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp_in_IfOwner(std::weak_ptr<ocl::Expressions::IfExp> par_ifOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl(par_ifOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ifOwner.lock())
	{
			wp->setCondition(element);
	}
	element->setThisLetExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp_in_InitializedElement(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl(par_initializedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_initializedElement.lock())
	{
			wp->setInitExpression(element);
	}
	element->setThisLetExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp_in_LastOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_lastOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl(par_lastOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_lastOwner.lock())
	{
			wp->setLast(element);
	}
	element->setThisLetExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp_in_LoopBodyOwner(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl(par_loopBodyOwner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_loopBodyOwner.lock())
	{
			wp->setBody(element);
	}
	element->setThisLetExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp_in_ParentCall(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl(par_parentCall));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentCall.lock())
	{
			wp->getArgument()->push_back(element);
	}
	element->setThisLetExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp_in_ParentNav(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl(par_parentNav));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentNav.lock())
	{
			wp->getQualifier()->push_back(element);
	}
	element->setThisLetExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp_in_ThenOwner(std::weak_ptr<ocl::Expressions::IfExp> par_thenOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl(par_thenOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_thenOwner.lock())
	{
			wp->setThenExpression(element);
	}
	element->setThisLetExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::LetExp> ExpressionsFactoryImpl::createLetExp_in_TopExpression(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::LetExpImpl> element(new ocl::Expressions::LetExpImpl(par_topExpression));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_topExpression.lock())
	{
			wp->setBodyExpression(element);
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

std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp_in_AppliedElement(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl(par_appliedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_appliedElement.lock())
	{
			wp->setSource(element);
	}
	element->setThisMessageExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp_in_ElseOwner(std::weak_ptr<ocl::Expressions::IfExp> par_elseOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl(par_elseOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_elseOwner.lock())
	{
			wp->setElseExpression(element);
	}
	element->setThisMessageExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp_in_FirstOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_firstOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl(par_firstOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_firstOwner.lock())
	{
			wp->setFirst(element);
	}
	element->setThisMessageExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp_in_IfOwner(std::weak_ptr<ocl::Expressions::IfExp> par_ifOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl(par_ifOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ifOwner.lock())
	{
			wp->setCondition(element);
	}
	element->setThisMessageExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp_in_InitializedElement(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl(par_initializedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_initializedElement.lock())
	{
			wp->setInitExpression(element);
	}
	element->setThisMessageExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp_in_LastOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_lastOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl(par_lastOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_lastOwner.lock())
	{
			wp->setLast(element);
	}
	element->setThisMessageExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp_in_LoopBodyOwner(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl(par_loopBodyOwner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_loopBodyOwner.lock())
	{
			wp->setBody(element);
	}
	element->setThisMessageExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp_in_ParentCall(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl(par_parentCall));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentCall.lock())
	{
			wp->getArgument()->push_back(element);
	}
	element->setThisMessageExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp_in_ParentNav(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl(par_parentNav));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentNav.lock())
	{
			wp->getQualifier()->push_back(element);
	}
	element->setThisMessageExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp_in_ThenOwner(std::weak_ptr<ocl::Expressions::IfExp> par_thenOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl(par_thenOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_thenOwner.lock())
	{
			wp->setThenExpression(element);
	}
	element->setThisMessageExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::MessageExp> ExpressionsFactoryImpl::createMessageExp_in_TopExpression(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::MessageExpImpl> element(new ocl::Expressions::MessageExpImpl(par_topExpression));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_topExpression.lock())
	{
			wp->setBodyExpression(element);
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

std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp_in_AppliedElement(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl(par_appliedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_appliedElement.lock())
	{
			wp->setSource(element);
	}
	element->setThisNullLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp_in_ElseOwner(std::weak_ptr<ocl::Expressions::IfExp> par_elseOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl(par_elseOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_elseOwner.lock())
	{
			wp->setElseExpression(element);
	}
	element->setThisNullLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp_in_FirstOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_firstOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl(par_firstOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_firstOwner.lock())
	{
			wp->setFirst(element);
	}
	element->setThisNullLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp_in_IfOwner(std::weak_ptr<ocl::Expressions::IfExp> par_ifOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl(par_ifOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ifOwner.lock())
	{
			wp->setCondition(element);
	}
	element->setThisNullLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp_in_InitializedElement(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl(par_initializedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_initializedElement.lock())
	{
			wp->setInitExpression(element);
	}
	element->setThisNullLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp_in_LastOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_lastOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl(par_lastOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_lastOwner.lock())
	{
			wp->setLast(element);
	}
	element->setThisNullLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp_in_LoopBodyOwner(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl(par_loopBodyOwner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_loopBodyOwner.lock())
	{
			wp->setBody(element);
	}
	element->setThisNullLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp_in_ParentCall(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl(par_parentCall));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentCall.lock())
	{
			wp->getArgument()->push_back(element);
	}
	element->setThisNullLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp_in_ParentNav(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl(par_parentNav));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentNav.lock())
	{
			wp->getQualifier()->push_back(element);
	}
	element->setThisNullLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp_in_ThenOwner(std::weak_ptr<ocl::Expressions::IfExp> par_thenOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl(par_thenOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_thenOwner.lock())
	{
			wp->setThenExpression(element);
	}
	element->setThisNullLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::NullLiteralExp> ExpressionsFactoryImpl::createNullLiteralExp_in_TopExpression(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::NullLiteralExpImpl> element(new ocl::Expressions::NullLiteralExpImpl(par_topExpression));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_topExpression.lock())
	{
			wp->setBodyExpression(element);
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

std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp_in_AppliedElement(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl(par_appliedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_appliedElement.lock())
	{
			wp->setSource(element);
	}
	element->setThisOperationCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp_in_ElseOwner(std::weak_ptr<ocl::Expressions::IfExp> par_elseOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl(par_elseOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_elseOwner.lock())
	{
			wp->setElseExpression(element);
	}
	element->setThisOperationCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp_in_FirstOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_firstOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl(par_firstOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_firstOwner.lock())
	{
			wp->setFirst(element);
	}
	element->setThisOperationCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp_in_IfOwner(std::weak_ptr<ocl::Expressions::IfExp> par_ifOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl(par_ifOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ifOwner.lock())
	{
			wp->setCondition(element);
	}
	element->setThisOperationCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp_in_InitializedElement(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl(par_initializedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_initializedElement.lock())
	{
			wp->setInitExpression(element);
	}
	element->setThisOperationCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp_in_LastOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_lastOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl(par_lastOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_lastOwner.lock())
	{
			wp->setLast(element);
	}
	element->setThisOperationCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp_in_LoopBodyOwner(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl(par_loopBodyOwner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_loopBodyOwner.lock())
	{
			wp->setBody(element);
	}
	element->setThisOperationCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp_in_ParentCall(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl(par_parentCall));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentCall.lock())
	{
			wp->getArgument()->push_back(element);
	}
	element->setThisOperationCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp_in_ParentNav(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl(par_parentNav));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentNav.lock())
	{
			wp->getQualifier()->push_back(element);
	}
	element->setThisOperationCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp_in_ThenOwner(std::weak_ptr<ocl::Expressions::IfExp> par_thenOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl(par_thenOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_thenOwner.lock())
	{
			wp->setThenExpression(element);
	}
	element->setThisOperationCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::OperationCallExp> ExpressionsFactoryImpl::createOperationCallExp_in_TopExpression(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::OperationCallExpImpl> element(new ocl::Expressions::OperationCallExpImpl(par_topExpression));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_topExpression.lock())
	{
			wp->setBodyExpression(element);
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

std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp_in_AppliedElement(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl(par_appliedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_appliedElement.lock())
	{
			wp->setSource(element);
	}
	element->setThisPropertyCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp_in_ElseOwner(std::weak_ptr<ocl::Expressions::IfExp> par_elseOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl(par_elseOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_elseOwner.lock())
	{
			wp->setElseExpression(element);
	}
	element->setThisPropertyCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp_in_FirstOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_firstOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl(par_firstOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_firstOwner.lock())
	{
			wp->setFirst(element);
	}
	element->setThisPropertyCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp_in_IfOwner(std::weak_ptr<ocl::Expressions::IfExp> par_ifOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl(par_ifOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ifOwner.lock())
	{
			wp->setCondition(element);
	}
	element->setThisPropertyCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp_in_InitializedElement(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl(par_initializedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_initializedElement.lock())
	{
			wp->setInitExpression(element);
	}
	element->setThisPropertyCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp_in_LastOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_lastOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl(par_lastOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_lastOwner.lock())
	{
			wp->setLast(element);
	}
	element->setThisPropertyCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp_in_LoopBodyOwner(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl(par_loopBodyOwner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_loopBodyOwner.lock())
	{
			wp->setBody(element);
	}
	element->setThisPropertyCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp_in_ParentCall(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl(par_parentCall));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentCall.lock())
	{
			wp->getArgument()->push_back(element);
	}
	element->setThisPropertyCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp_in_ParentNav(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl(par_parentNav));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentNav.lock())
	{
			wp->getQualifier()->push_back(element);
	}
	element->setThisPropertyCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp_in_ThenOwner(std::weak_ptr<ocl::Expressions::IfExp> par_thenOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl(par_thenOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_thenOwner.lock())
	{
			wp->setThenExpression(element);
	}
	element->setThisPropertyCallExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::PropertyCallExp> ExpressionsFactoryImpl::createPropertyCallExp_in_TopExpression(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::PropertyCallExpImpl> element(new ocl::Expressions::PropertyCallExpImpl(par_topExpression));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_topExpression.lock())
	{
			wp->setBodyExpression(element);
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

std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp_in_AppliedElement(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl(par_appliedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_appliedElement.lock())
	{
			wp->setSource(element);
	}
	element->setThisRealLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp_in_ElseOwner(std::weak_ptr<ocl::Expressions::IfExp> par_elseOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl(par_elseOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_elseOwner.lock())
	{
			wp->setElseExpression(element);
	}
	element->setThisRealLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp_in_FirstOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_firstOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl(par_firstOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_firstOwner.lock())
	{
			wp->setFirst(element);
	}
	element->setThisRealLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp_in_IfOwner(std::weak_ptr<ocl::Expressions::IfExp> par_ifOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl(par_ifOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ifOwner.lock())
	{
			wp->setCondition(element);
	}
	element->setThisRealLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp_in_InitializedElement(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl(par_initializedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_initializedElement.lock())
	{
			wp->setInitExpression(element);
	}
	element->setThisRealLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp_in_LastOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_lastOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl(par_lastOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_lastOwner.lock())
	{
			wp->setLast(element);
	}
	element->setThisRealLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp_in_LoopBodyOwner(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl(par_loopBodyOwner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_loopBodyOwner.lock())
	{
			wp->setBody(element);
	}
	element->setThisRealLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp_in_ParentCall(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl(par_parentCall));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentCall.lock())
	{
			wp->getArgument()->push_back(element);
	}
	element->setThisRealLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp_in_ParentNav(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl(par_parentNav));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentNav.lock())
	{
			wp->getQualifier()->push_back(element);
	}
	element->setThisRealLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp_in_ThenOwner(std::weak_ptr<ocl::Expressions::IfExp> par_thenOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl(par_thenOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_thenOwner.lock())
	{
			wp->setThenExpression(element);
	}
	element->setThisRealLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::RealLiteralExp> ExpressionsFactoryImpl::createRealLiteralExp_in_TopExpression(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::RealLiteralExpImpl> element(new ocl::Expressions::RealLiteralExpImpl(par_topExpression));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_topExpression.lock())
	{
			wp->setBodyExpression(element);
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

std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp_in_AppliedElement(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl(par_appliedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_appliedElement.lock())
	{
			wp->setSource(element);
	}
	element->setThisStateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp_in_ElseOwner(std::weak_ptr<ocl::Expressions::IfExp> par_elseOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl(par_elseOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_elseOwner.lock())
	{
			wp->setElseExpression(element);
	}
	element->setThisStateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp_in_FirstOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_firstOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl(par_firstOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_firstOwner.lock())
	{
			wp->setFirst(element);
	}
	element->setThisStateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp_in_IfOwner(std::weak_ptr<ocl::Expressions::IfExp> par_ifOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl(par_ifOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ifOwner.lock())
	{
			wp->setCondition(element);
	}
	element->setThisStateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp_in_InitializedElement(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl(par_initializedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_initializedElement.lock())
	{
			wp->setInitExpression(element);
	}
	element->setThisStateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp_in_LastOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_lastOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl(par_lastOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_lastOwner.lock())
	{
			wp->setLast(element);
	}
	element->setThisStateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp_in_LoopBodyOwner(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl(par_loopBodyOwner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_loopBodyOwner.lock())
	{
			wp->setBody(element);
	}
	element->setThisStateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp_in_ParentCall(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl(par_parentCall));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentCall.lock())
	{
			wp->getArgument()->push_back(element);
	}
	element->setThisStateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp_in_ParentNav(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl(par_parentNav));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentNav.lock())
	{
			wp->getQualifier()->push_back(element);
	}
	element->setThisStateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp_in_ThenOwner(std::weak_ptr<ocl::Expressions::IfExp> par_thenOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl(par_thenOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_thenOwner.lock())
	{
			wp->setThenExpression(element);
	}
	element->setThisStateExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StateExp> ExpressionsFactoryImpl::createStateExp_in_TopExpression(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StateExpImpl> element(new ocl::Expressions::StateExpImpl(par_topExpression));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_topExpression.lock())
	{
			wp->setBodyExpression(element);
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

std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp_in_AppliedElement(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl(par_appliedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_appliedElement.lock())
	{
			wp->setSource(element);
	}
	element->setThisStringLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp_in_ElseOwner(std::weak_ptr<ocl::Expressions::IfExp> par_elseOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl(par_elseOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_elseOwner.lock())
	{
			wp->setElseExpression(element);
	}
	element->setThisStringLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp_in_FirstOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_firstOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl(par_firstOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_firstOwner.lock())
	{
			wp->setFirst(element);
	}
	element->setThisStringLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp_in_IfOwner(std::weak_ptr<ocl::Expressions::IfExp> par_ifOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl(par_ifOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ifOwner.lock())
	{
			wp->setCondition(element);
	}
	element->setThisStringLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp_in_InitializedElement(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl(par_initializedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_initializedElement.lock())
	{
			wp->setInitExpression(element);
	}
	element->setThisStringLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp_in_LastOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_lastOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl(par_lastOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_lastOwner.lock())
	{
			wp->setLast(element);
	}
	element->setThisStringLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp_in_LoopBodyOwner(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl(par_loopBodyOwner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_loopBodyOwner.lock())
	{
			wp->setBody(element);
	}
	element->setThisStringLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp_in_ParentCall(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl(par_parentCall));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentCall.lock())
	{
			wp->getArgument()->push_back(element);
	}
	element->setThisStringLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp_in_ParentNav(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl(par_parentNav));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentNav.lock())
	{
			wp->getQualifier()->push_back(element);
	}
	element->setThisStringLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp_in_ThenOwner(std::weak_ptr<ocl::Expressions::IfExp> par_thenOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl(par_thenOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_thenOwner.lock())
	{
			wp->setThenExpression(element);
	}
	element->setThisStringLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::StringLiteralExp> ExpressionsFactoryImpl::createStringLiteralExp_in_TopExpression(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::StringLiteralExpImpl> element(new ocl::Expressions::StringLiteralExpImpl(par_topExpression));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_topExpression.lock())
	{
			wp->setBodyExpression(element);
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

std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp_in_AppliedElement(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl(par_appliedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_appliedElement.lock())
	{
			wp->setSource(element);
	}
	element->setThisTupleLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp_in_ElseOwner(std::weak_ptr<ocl::Expressions::IfExp> par_elseOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl(par_elseOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_elseOwner.lock())
	{
			wp->setElseExpression(element);
	}
	element->setThisTupleLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp_in_FirstOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_firstOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl(par_firstOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_firstOwner.lock())
	{
			wp->setFirst(element);
	}
	element->setThisTupleLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp_in_IfOwner(std::weak_ptr<ocl::Expressions::IfExp> par_ifOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl(par_ifOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ifOwner.lock())
	{
			wp->setCondition(element);
	}
	element->setThisTupleLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp_in_InitializedElement(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl(par_initializedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_initializedElement.lock())
	{
			wp->setInitExpression(element);
	}
	element->setThisTupleLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp_in_LastOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_lastOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl(par_lastOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_lastOwner.lock())
	{
			wp->setLast(element);
	}
	element->setThisTupleLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp_in_LoopBodyOwner(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl(par_loopBodyOwner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_loopBodyOwner.lock())
	{
			wp->setBody(element);
	}
	element->setThisTupleLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp_in_ParentCall(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl(par_parentCall));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentCall.lock())
	{
			wp->getArgument()->push_back(element);
	}
	element->setThisTupleLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp_in_ParentNav(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl(par_parentNav));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentNav.lock())
	{
			wp->getQualifier()->push_back(element);
	}
	element->setThisTupleLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp_in_ThenOwner(std::weak_ptr<ocl::Expressions::IfExp> par_thenOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl(par_thenOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_thenOwner.lock())
	{
			wp->setThenExpression(element);
	}
	element->setThisTupleLiteralExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TupleLiteralExp> ExpressionsFactoryImpl::createTupleLiteralExp_in_TopExpression(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TupleLiteralExpImpl> element(new ocl::Expressions::TupleLiteralExpImpl(par_topExpression));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_topExpression.lock())
	{
			wp->setBodyExpression(element);
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

std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl());
	element->setMetaElementID(metaElementID);
	element->setThisTypeExpPtr(element);
	return element;
}

std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp_in_AppliedElement(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl(par_appliedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_appliedElement.lock())
	{
			wp->setSource(element);
	}
	element->setThisTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp_in_ElseOwner(std::weak_ptr<ocl::Expressions::IfExp> par_elseOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl(par_elseOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_elseOwner.lock())
	{
			wp->setElseExpression(element);
	}
	element->setThisTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp_in_FirstOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_firstOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl(par_firstOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_firstOwner.lock())
	{
			wp->setFirst(element);
	}
	element->setThisTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp_in_IfOwner(std::weak_ptr<ocl::Expressions::IfExp> par_ifOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl(par_ifOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ifOwner.lock())
	{
			wp->setCondition(element);
	}
	element->setThisTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp_in_InitializedElement(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl(par_initializedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_initializedElement.lock())
	{
			wp->setInitExpression(element);
	}
	element->setThisTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp_in_LastOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_lastOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl(par_lastOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_lastOwner.lock())
	{
			wp->setLast(element);
	}
	element->setThisTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp_in_LoopBodyOwner(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl(par_loopBodyOwner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_loopBodyOwner.lock())
	{
			wp->setBody(element);
	}
	element->setThisTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp_in_ParentCall(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl(par_parentCall));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentCall.lock())
	{
			wp->getArgument()->push_back(element);
	}
	element->setThisTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp_in_ParentNav(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl(par_parentNav));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentNav.lock())
	{
			wp->getQualifier()->push_back(element);
	}
	element->setThisTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp_in_ThenOwner(std::weak_ptr<ocl::Expressions::IfExp> par_thenOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl(par_thenOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_thenOwner.lock())
	{
			wp->setThenExpression(element);
	}
	element->setThisTypeExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::TypeExp> ExpressionsFactoryImpl::createTypeExp_in_TopExpression(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::TypeExpImpl> element(new ocl::Expressions::TypeExpImpl(par_topExpression));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_topExpression.lock())
	{
			wp->setBodyExpression(element);
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

std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp_in_AppliedElement(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl(par_appliedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_appliedElement.lock())
	{
			wp->setSource(element);
	}
	element->setThisUnlimitedNaturalExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp_in_ElseOwner(std::weak_ptr<ocl::Expressions::IfExp> par_elseOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl(par_elseOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_elseOwner.lock())
	{
			wp->setElseExpression(element);
	}
	element->setThisUnlimitedNaturalExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp_in_FirstOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_firstOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl(par_firstOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_firstOwner.lock())
	{
			wp->setFirst(element);
	}
	element->setThisUnlimitedNaturalExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp_in_IfOwner(std::weak_ptr<ocl::Expressions::IfExp> par_ifOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl(par_ifOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ifOwner.lock())
	{
			wp->setCondition(element);
	}
	element->setThisUnlimitedNaturalExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp_in_InitializedElement(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl(par_initializedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_initializedElement.lock())
	{
			wp->setInitExpression(element);
	}
	element->setThisUnlimitedNaturalExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp_in_LastOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_lastOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl(par_lastOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_lastOwner.lock())
	{
			wp->setLast(element);
	}
	element->setThisUnlimitedNaturalExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp_in_LoopBodyOwner(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl(par_loopBodyOwner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_loopBodyOwner.lock())
	{
			wp->setBody(element);
	}
	element->setThisUnlimitedNaturalExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp_in_ParentCall(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl(par_parentCall));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentCall.lock())
	{
			wp->getArgument()->push_back(element);
	}
	element->setThisUnlimitedNaturalExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp_in_ParentNav(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl(par_parentNav));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentNav.lock())
	{
			wp->getQualifier()->push_back(element);
	}
	element->setThisUnlimitedNaturalExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp_in_ThenOwner(std::weak_ptr<ocl::Expressions::IfExp> par_thenOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl(par_thenOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_thenOwner.lock())
	{
			wp->setThenExpression(element);
	}
	element->setThisUnlimitedNaturalExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> ExpressionsFactoryImpl::createUnlimitedNaturalExp_in_TopExpression(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnlimitedNaturalExpImpl> element(new ocl::Expressions::UnlimitedNaturalExpImpl(par_topExpression));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_topExpression.lock())
	{
			wp->setBodyExpression(element);
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

std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp_in_AppliedElement(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl(par_appliedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_appliedElement.lock())
	{
			wp->setSource(element);
	}
	element->setThisUnspecifiedValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp_in_ElseOwner(std::weak_ptr<ocl::Expressions::IfExp> par_elseOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl(par_elseOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_elseOwner.lock())
	{
			wp->setElseExpression(element);
	}
	element->setThisUnspecifiedValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp_in_FirstOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_firstOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl(par_firstOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_firstOwner.lock())
	{
			wp->setFirst(element);
	}
	element->setThisUnspecifiedValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp_in_IfOwner(std::weak_ptr<ocl::Expressions::IfExp> par_ifOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl(par_ifOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ifOwner.lock())
	{
			wp->setCondition(element);
	}
	element->setThisUnspecifiedValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp_in_InitializedElement(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl(par_initializedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_initializedElement.lock())
	{
			wp->setInitExpression(element);
	}
	element->setThisUnspecifiedValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp_in_LastOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_lastOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl(par_lastOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_lastOwner.lock())
	{
			wp->setLast(element);
	}
	element->setThisUnspecifiedValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp_in_LoopBodyOwner(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl(par_loopBodyOwner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_loopBodyOwner.lock())
	{
			wp->setBody(element);
	}
	element->setThisUnspecifiedValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp_in_ParentCall(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl(par_parentCall));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentCall.lock())
	{
			wp->getArgument()->push_back(element);
	}
	element->setThisUnspecifiedValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp_in_ParentNav(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl(par_parentNav));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentNav.lock())
	{
			wp->getQualifier()->push_back(element);
	}
	element->setThisUnspecifiedValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp_in_ThenOwner(std::weak_ptr<ocl::Expressions::IfExp> par_thenOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl(par_thenOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_thenOwner.lock())
	{
			wp->setThenExpression(element);
	}
	element->setThisUnspecifiedValueExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> ExpressionsFactoryImpl::createUnspecifiedValueExp_in_TopExpression(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::UnspecifiedValueExpImpl> element(new ocl::Expressions::UnspecifiedValueExpImpl(par_topExpression));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_topExpression.lock())
	{
			wp->setBodyExpression(element);
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

std::shared_ptr<ocl::Expressions::Variable> ExpressionsFactoryImpl::createVariable_in_BaseExp(std::weak_ptr<ocl::Expressions::IterateExp> par_baseExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableImpl> element(new ocl::Expressions::VariableImpl(par_baseExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_baseExp.lock())
	{
			wp->setResult(element);
	}
	element->setThisVariablePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::Variable> ExpressionsFactoryImpl::createVariable_in_LoopExp(std::weak_ptr<ocl::Expressions::LoopExp> par_loopExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableImpl> element(new ocl::Expressions::VariableImpl(par_loopExp));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_loopExp.lock())
	{
			wp->getIterator()->push_back(element);
	}
	element->setThisVariablePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::Variable> ExpressionsFactoryImpl::createVariable_in_ResultOwner(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_resultOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableImpl> element(new ocl::Expressions::VariableImpl(par_resultOwner, ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_RESULTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_resultOwner.lock())
	{
			wp->setResultVariable(element);
	}
	element->setThisVariablePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::Variable> ExpressionsFactoryImpl::createVariable_in_SelfOwner(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_selfOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableImpl> element(new ocl::Expressions::VariableImpl(par_selfOwner, ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_SELFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_selfOwner.lock())
	{
			wp->setContextVariable(element);
	}
	element->setThisVariablePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::Variable> ExpressionsFactoryImpl::createVariable_in_VarOwner(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_varOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableImpl> element(new ocl::Expressions::VariableImpl(par_varOwner, ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_VAROWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_varOwner.lock())
	{
			wp->getParameterVariable()->push_back(element);
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

std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp_in_AppliedElement(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl(par_appliedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_appliedElement.lock())
	{
			wp->setSource(element);
	}
	element->setThisVariableExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp_in_ElseOwner(std::weak_ptr<ocl::Expressions::IfExp> par_elseOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl(par_elseOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_elseOwner.lock())
	{
			wp->setElseExpression(element);
	}
	element->setThisVariableExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp_in_FirstOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_firstOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl(par_firstOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_firstOwner.lock())
	{
			wp->setFirst(element);
	}
	element->setThisVariableExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp_in_IfOwner(std::weak_ptr<ocl::Expressions::IfExp> par_ifOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl(par_ifOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ifOwner.lock())
	{
			wp->setCondition(element);
	}
	element->setThisVariableExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp_in_InitializedElement(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl(par_initializedElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_initializedElement.lock())
	{
			wp->setInitExpression(element);
	}
	element->setThisVariableExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp_in_LastOwner(std::weak_ptr<ocl::Expressions::CollectionRange> par_lastOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl(par_lastOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_lastOwner.lock())
	{
			wp->setLast(element);
	}
	element->setThisVariableExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp_in_LoopBodyOwner(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl(par_loopBodyOwner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_loopBodyOwner.lock())
	{
			wp->setBody(element);
	}
	element->setThisVariableExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp_in_ParentCall(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl(par_parentCall));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentCall.lock())
	{
			wp->getArgument()->push_back(element);
	}
	element->setThisVariableExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp_in_ParentNav(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl(par_parentNav));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_parentNav.lock())
	{
			wp->getQualifier()->push_back(element);
	}
	element->setThisVariableExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp_in_ThenOwner(std::weak_ptr<ocl::Expressions::IfExp> par_thenOwner, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl(par_thenOwner, ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_thenOwner.lock())
	{
			wp->setThenExpression(element);
	}
	element->setThisVariableExpPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Expressions::VariableExp> ExpressionsFactoryImpl::createVariableExp_in_TopExpression(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression, const int metaElementID) const
{
	std::shared_ptr<ocl::Expressions::VariableExpImpl> element(new ocl::Expressions::VariableExpImpl(par_topExpression));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_topExpression.lock())
	{
			wp->setBodyExpression(element);
	}
	element->setThisVariableExpPtr(element);
	return element;
	
}

