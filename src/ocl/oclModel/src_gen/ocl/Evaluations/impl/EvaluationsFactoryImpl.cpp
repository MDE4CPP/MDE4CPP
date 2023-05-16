#include "ocl/Evaluations/impl/EvaluationsFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "ocl/Evaluations/impl/AssociationClassCallExpEvalImpl.hpp"
#include "ocl/Evaluations/impl/AssociationEndCallExpEvalImpl.hpp"
#include "ocl/Evaluations/impl/AttributeCallExpEvalImpl.hpp"
#include "ocl/Evaluations/impl/BooleanLiteralExpEvalImpl.hpp"
#include "ocl/Evaluations/impl/CollectionItemEvalImpl.hpp"
#include "ocl/Evaluations/impl/CollectionLiteralExpEvalImpl.hpp"
#include "ocl/Evaluations/impl/CollectionLiteralPartEvalImpl.hpp"
#include "ocl/Evaluations/impl/CollectionRangeEvalImpl.hpp"
#include "ocl/Evaluations/impl/EnumLiteralExpEvalImpl.hpp"
#include "ocl/Evaluations/impl/EvalEnvironmentImpl.hpp"
#include "ocl/Evaluations/impl/EvalNameSpaceImpl.hpp"
#include "ocl/Evaluations/impl/ExpressionInOclEvalImpl.hpp"
#include "ocl/Evaluations/impl/IfExpEvalImpl.hpp"
#include "ocl/Evaluations/impl/IntegerLiteralExpEvalImpl.hpp"
#include "ocl/Evaluations/impl/IterateExpEvalImpl.hpp"
#include "ocl/Evaluations/impl/IteratorExpEvalImpl.hpp"
#include "ocl/Evaluations/impl/LetExpEvalImpl.hpp"
#include "ocl/Evaluations/impl/LiteralExpEvalImpl.hpp"
#include "ocl/Evaluations/impl/LoopExpEvalImpl.hpp"
#include "ocl/Evaluations/impl/ModelPropertyCallExpEvalImpl.hpp"
#include "ocl/Evaluations/impl/NameValueBindingImpl.hpp"
#include "ocl/Evaluations/impl/NavigationCallExpEvalImpl.hpp"
#include "ocl/Evaluations/impl/NumericLiteralExpEvalImpl.hpp"
#include "ocl/Evaluations/impl/OclExpEvalImpl.hpp"
#include "ocl/Evaluations/impl/OclMessageArgEvalImpl.hpp"
#include "ocl/Evaluations/impl/OclMessageExpEvalImpl.hpp"
#include "ocl/Evaluations/impl/OperationCallExpEvalImpl.hpp"
#include "ocl/Evaluations/impl/PrimitiveLiteralExpEvalImpl.hpp"
#include "ocl/Evaluations/impl/PropertyCallExpEvalImpl.hpp"
#include "ocl/Evaluations/impl/RealLiteralExpEvalImpl.hpp"
#include "ocl/Evaluations/impl/StringLiteralExpEvalImpl.hpp"
#include "ocl/Evaluations/impl/TupleLiteralExpEvalImpl.hpp"
#include "ocl/Evaluations/impl/TupleLiteralExpPartEvalImpl.hpp"
#include "ocl/Evaluations/impl/UnlimitedNaturalLiteralExpEvalImpl.hpp"
#include "ocl/Evaluations/impl/UnspecifiedValueExpEvalImpl.hpp"
#include "ocl/Evaluations/impl/VariableDeclEvalImpl.hpp"
#include "ocl/Evaluations/impl/VariableExpEvalImpl.hpp"

#include "ocl/Expressions/ExpressionsPackage.hpp"
#include "ocl/Expressions/ExpressionInOcl.hpp"
#include "ocl/Expressions/IterateExp.hpp"


using namespace ocl::Evaluations;

std::shared_ptr<EvaluationsFactory> EvaluationsFactory::eInstance()
{
	static std::shared_ptr<EvaluationsFactory> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(EvaluationsFactoryImpl::create());
	}	
	return instance;
}

//*********************************
// Constructor / Destructor
//*********************************

EvaluationsFactoryImpl::EvaluationsFactoryImpl()
{
	m_idMap.insert(std::make_pair("ocl::Evaluations::AssociationClassCallExpEval", EvaluationsPackage::ASSOCIATIONCLASSCALLEXPEVAL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::AssociationEndCallExpEval", EvaluationsPackage::ASSOCIATIONENDCALLEXPEVAL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::AttributeCallExpEval", EvaluationsPackage::ATTRIBUTECALLEXPEVAL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::BooleanLiteralExpEval", EvaluationsPackage::BOOLEANLITERALEXPEVAL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::CollectionItemEval", EvaluationsPackage::COLLECTIONITEMEVAL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::CollectionLiteralExpEval", EvaluationsPackage::COLLECTIONLITERALEXPEVAL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::CollectionLiteralPartEval", EvaluationsPackage::COLLECTIONLITERALPARTEVAL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::CollectionRangeEval", EvaluationsPackage::COLLECTIONRANGEEVAL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::EnumLiteralExpEval", EvaluationsPackage::ENUMLITERALEXPEVAL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::EvalEnvironment", EvaluationsPackage::EVALENVIRONMENT_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::EvalNameSpace", EvaluationsPackage::EVALNAMESPACE_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::ExpressionInOclEval", EvaluationsPackage::EXPRESSIONINOCLEVAL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::IfExpEval", EvaluationsPackage::IFEXPEVAL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::IntegerLiteralExpEval", EvaluationsPackage::INTEGERLITERALEXPEVAL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::IterateExpEval", EvaluationsPackage::ITERATEEXPEVAL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::IteratorExpEval", EvaluationsPackage::ITERATOREXPEVAL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::LetExpEval", EvaluationsPackage::LETEXPEVAL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::LiteralExpEval", EvaluationsPackage::LITERALEXPEVAL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::LoopExpEval", EvaluationsPackage::LOOPEXPEVAL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::ModelPropertyCallExpEval", EvaluationsPackage::MODELPROPERTYCALLEXPEVAL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::NameValueBinding", EvaluationsPackage::NAMEVALUEBINDING_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::NavigationCallExpEval", EvaluationsPackage::NAVIGATIONCALLEXPEVAL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::NumericLiteralExpEval", EvaluationsPackage::NUMERICLITERALEXPEVAL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::OclExpEval", EvaluationsPackage::OCLEXPEVAL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::OclMessageArgEval", EvaluationsPackage::OCLMESSAGEARGEVAL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::OclMessageExpEval", EvaluationsPackage::OCLMESSAGEEXPEVAL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::OperationCallExpEval", EvaluationsPackage::OPERATIONCALLEXPEVAL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::PrimitiveLiteralExpEval", EvaluationsPackage::PRIMITIVELITERALEXPEVAL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::PropertyCallExpEval", EvaluationsPackage::PROPERTYCALLEXPEVAL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::RealLiteralExpEval", EvaluationsPackage::REALLITERALEXPEVAL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::StringLiteralExpEval", EvaluationsPackage::STRINGLITERALEXPEVAL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::TupleLiteralExpEval", EvaluationsPackage::TUPLELITERALEXPEVAL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::TupleLiteralExpPartEval", EvaluationsPackage::TUPLELITERALEXPPARTEVAL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::UnlimitedNaturalLiteralExpEval", EvaluationsPackage::UNLIMITEDNATURALLITERALEXPEVAL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::UnspecifiedValueExpEval", EvaluationsPackage::UNSPECIFIEDVALUEEXPEVAL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::VariableDeclEval", EvaluationsPackage::VARIABLEDECLEVAL_CLASS));
	m_idMap.insert(std::make_pair("ocl::Evaluations::VariableExpEval", EvaluationsPackage::VARIABLEEXPEVAL_CLASS));
}

EvaluationsFactoryImpl::~EvaluationsFactoryImpl()
{
}

EvaluationsFactory* EvaluationsFactoryImpl::create()
{
	return new EvaluationsFactoryImpl();
}

//*********************************
// creators
//*********************************

std::shared_ptr<ecore::EObject> EvaluationsFactoryImpl::create(const int metaElementID, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	switch(metaElementID)
	{
		case EvaluationsPackage::ASSOCIATIONCLASSCALLEXPEVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createAssociationClassCallExpEval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//AssociationClassCallExpEval has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createAssociationClassCallExpEval_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//AssociationClassCallExpEval has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createAssociationClassCallExpEval_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//AssociationClassCallExpEval has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createAssociationClassCallExpEval_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//AssociationClassCallExpEval has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createAssociationClassCallExpEval_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::ASSOCIATIONENDCALLEXPEVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createAssociationEndCallExpEval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//AssociationEndCallExpEval has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createAssociationEndCallExpEval_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//AssociationEndCallExpEval has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createAssociationEndCallExpEval_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//AssociationEndCallExpEval has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createAssociationEndCallExpEval_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//AssociationEndCallExpEval has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createAssociationEndCallExpEval_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::ATTRIBUTECALLEXPEVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createAttributeCallExpEval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//AttributeCallExpEval has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createAttributeCallExpEval_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//AttributeCallExpEval has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createAttributeCallExpEval_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//AttributeCallExpEval has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createAttributeCallExpEval_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//AttributeCallExpEval has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createAttributeCallExpEval_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::BOOLEANLITERALEXPEVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createBooleanLiteralExpEval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//BooleanLiteralExpEval has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createBooleanLiteralExpEval_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//BooleanLiteralExpEval has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createBooleanLiteralExpEval_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//BooleanLiteralExpEval has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createBooleanLiteralExpEval_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//BooleanLiteralExpEval has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createBooleanLiteralExpEval_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::COLLECTIONITEMEVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCollectionItemEval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//CollectionItemEval has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createCollectionItemEval_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//CollectionItemEval has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createCollectionItemEval_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//CollectionItemEval has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createCollectionItemEval_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//CollectionItemEval has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createCollectionItemEval_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::COLLECTIONLITERALEXPEVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCollectionLiteralExpEval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//CollectionLiteralExpEval has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createCollectionLiteralExpEval_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//CollectionLiteralExpEval has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createCollectionLiteralExpEval_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//CollectionLiteralExpEval has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createCollectionLiteralExpEval_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//CollectionLiteralExpEval has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createCollectionLiteralExpEval_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::COLLECTIONLITERALPARTEVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCollectionLiteralPartEval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//CollectionLiteralPartEval has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createCollectionLiteralPartEval_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//CollectionLiteralPartEval has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createCollectionLiteralPartEval_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//CollectionLiteralPartEval has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createCollectionLiteralPartEval_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//CollectionLiteralPartEval has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createCollectionLiteralPartEval_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::COLLECTIONRANGEEVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCollectionRangeEval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//CollectionRangeEval has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createCollectionRangeEval_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//CollectionRangeEval has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createCollectionRangeEval_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//CollectionRangeEval has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createCollectionRangeEval_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//CollectionRangeEval has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createCollectionRangeEval_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::ENUMLITERALEXPEVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createEnumLiteralExpEval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//EnumLiteralExpEval has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createEnumLiteralExpEval_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//EnumLiteralExpEval has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createEnumLiteralExpEval_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//EnumLiteralExpEval has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createEnumLiteralExpEval_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//EnumLiteralExpEval has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createEnumLiteralExpEval_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::EVALENVIRONMENT_CLASS:
		{
			if (nullptr == container)
			{
				return this->createEvalEnvironment(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//EvalEnvironment has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createEvalEnvironment_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//EvalEnvironment has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createEvalEnvironment_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//EvalEnvironment has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createEvalEnvironment_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//EvalEnvironment has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createEvalEnvironment_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::EVALNAMESPACE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createEvalNameSpace(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//EvalNameSpace has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createEvalNameSpace_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//EvalNameSpace has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createEvalNameSpace_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//EvalNameSpace has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createEvalNameSpace_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//EvalNameSpace has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createEvalNameSpace_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::EXPRESSIONINOCLEVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createExpressionInOclEval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ExpressionInOclEval has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createExpressionInOclEval_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//ExpressionInOclEval has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createExpressionInOclEval_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//ExpressionInOclEval has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createExpressionInOclEval_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//ExpressionInOclEval has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createExpressionInOclEval_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::IFEXPEVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createIfExpEval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//IfExpEval has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createIfExpEval_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//IfExpEval has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createIfExpEval_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//IfExpEval has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createIfExpEval_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//IfExpEval has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createIfExpEval_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::INTEGERLITERALEXPEVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createIntegerLiteralExpEval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//IntegerLiteralExpEval has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createIntegerLiteralExpEval_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//IntegerLiteralExpEval has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createIntegerLiteralExpEval_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//IntegerLiteralExpEval has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createIntegerLiteralExpEval_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//IntegerLiteralExpEval has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createIntegerLiteralExpEval_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::ITERATEEXPEVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createIterateExpEval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//IterateExpEval has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createIterateExpEval_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//IterateExpEval has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createIterateExpEval_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//IterateExpEval has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createIterateExpEval_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//IterateExpEval has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createIterateExpEval_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::ITERATOREXPEVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createIteratorExpEval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//IteratorExpEval has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createIteratorExpEval_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//IteratorExpEval has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createIteratorExpEval_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//IteratorExpEval has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createIteratorExpEval_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//IteratorExpEval has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createIteratorExpEval_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::LETEXPEVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createLetExpEval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//LetExpEval has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createLetExpEval_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//LetExpEval has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createLetExpEval_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//LetExpEval has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createLetExpEval_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//LetExpEval has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createLetExpEval_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::LITERALEXPEVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createLiteralExpEval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//LiteralExpEval has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createLiteralExpEval_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//LiteralExpEval has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createLiteralExpEval_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//LiteralExpEval has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createLiteralExpEval_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//LiteralExpEval has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createLiteralExpEval_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::LOOPEXPEVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createLoopExpEval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//LoopExpEval has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createLoopExpEval_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//LoopExpEval has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createLoopExpEval_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//LoopExpEval has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createLoopExpEval_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//LoopExpEval has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createLoopExpEval_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::MODELPROPERTYCALLEXPEVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createModelPropertyCallExpEval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ModelPropertyCallExpEval has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createModelPropertyCallExpEval_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//ModelPropertyCallExpEval has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createModelPropertyCallExpEval_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//ModelPropertyCallExpEval has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createModelPropertyCallExpEval_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//ModelPropertyCallExpEval has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createModelPropertyCallExpEval_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::NAMEVALUEBINDING_CLASS:
		{
			if (nullptr == container)
			{
				return this->createNameValueBinding(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//NameValueBinding has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createNameValueBinding_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//NameValueBinding has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createNameValueBinding_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//NameValueBinding has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createNameValueBinding_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//NameValueBinding has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createNameValueBinding_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::NAVIGATIONCALLEXPEVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createNavigationCallExpEval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//NavigationCallExpEval has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createNavigationCallExpEval_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//NavigationCallExpEval has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createNavigationCallExpEval_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//NavigationCallExpEval has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createNavigationCallExpEval_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//NavigationCallExpEval has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createNavigationCallExpEval_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::NUMERICLITERALEXPEVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createNumericLiteralExpEval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//NumericLiteralExpEval has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createNumericLiteralExpEval_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//NumericLiteralExpEval has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createNumericLiteralExpEval_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//NumericLiteralExpEval has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createNumericLiteralExpEval_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//NumericLiteralExpEval has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createNumericLiteralExpEval_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::OCLEXPEVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createOclExpEval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//OclExpEval has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createOclExpEval_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//OclExpEval has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createOclExpEval_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//OclExpEval has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createOclExpEval_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//OclExpEval has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createOclExpEval_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::OCLMESSAGEARGEVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createOclMessageArgEval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//OclMessageArgEval has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createOclMessageArgEval_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//OclMessageArgEval has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createOclMessageArgEval_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//OclMessageArgEval has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createOclMessageArgEval_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//OclMessageArgEval has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createOclMessageArgEval_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::OCLMESSAGEEXPEVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createOclMessageExpEval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//OclMessageExpEval has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createOclMessageExpEval_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//OclMessageExpEval has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createOclMessageExpEval_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//OclMessageExpEval has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createOclMessageExpEval_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//OclMessageExpEval has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createOclMessageExpEval_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::OPERATIONCALLEXPEVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createOperationCallExpEval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//OperationCallExpEval has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createOperationCallExpEval_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//OperationCallExpEval has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createOperationCallExpEval_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//OperationCallExpEval has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createOperationCallExpEval_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//OperationCallExpEval has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createOperationCallExpEval_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::PRIMITIVELITERALEXPEVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createPrimitiveLiteralExpEval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//PrimitiveLiteralExpEval has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createPrimitiveLiteralExpEval_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//PrimitiveLiteralExpEval has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createPrimitiveLiteralExpEval_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//PrimitiveLiteralExpEval has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createPrimitiveLiteralExpEval_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//PrimitiveLiteralExpEval has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createPrimitiveLiteralExpEval_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::PROPERTYCALLEXPEVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createPropertyCallExpEval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//PropertyCallExpEval has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createPropertyCallExpEval_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//PropertyCallExpEval has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createPropertyCallExpEval_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//PropertyCallExpEval has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createPropertyCallExpEval_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//PropertyCallExpEval has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createPropertyCallExpEval_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::REALLITERALEXPEVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createRealLiteralExpEval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//RealLiteralExpEval has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createRealLiteralExpEval_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//RealLiteralExpEval has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createRealLiteralExpEval_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//RealLiteralExpEval has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createRealLiteralExpEval_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//RealLiteralExpEval has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createRealLiteralExpEval_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::STRINGLITERALEXPEVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createStringLiteralExpEval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//StringLiteralExpEval has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createStringLiteralExpEval_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//StringLiteralExpEval has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createStringLiteralExpEval_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//StringLiteralExpEval has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createStringLiteralExpEval_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//StringLiteralExpEval has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createStringLiteralExpEval_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::TUPLELITERALEXPEVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createTupleLiteralExpEval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//TupleLiteralExpEval has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createTupleLiteralExpEval_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//TupleLiteralExpEval has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createTupleLiteralExpEval_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//TupleLiteralExpEval has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createTupleLiteralExpEval_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//TupleLiteralExpEval has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createTupleLiteralExpEval_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::TUPLELITERALEXPPARTEVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createTupleLiteralExpPartEval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//TupleLiteralExpPartEval has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createTupleLiteralExpPartEval_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//TupleLiteralExpPartEval has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createTupleLiteralExpPartEval_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//TupleLiteralExpPartEval has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createTupleLiteralExpPartEval_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//TupleLiteralExpPartEval has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createTupleLiteralExpPartEval_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::UNLIMITEDNATURALLITERALEXPEVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createUnlimitedNaturalLiteralExpEval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//UnlimitedNaturalLiteralExpEval has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createUnlimitedNaturalLiteralExpEval_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//UnlimitedNaturalLiteralExpEval has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createUnlimitedNaturalLiteralExpEval_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//UnlimitedNaturalLiteralExpEval has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createUnlimitedNaturalLiteralExpEval_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//UnlimitedNaturalLiteralExpEval has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createUnlimitedNaturalLiteralExpEval_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::UNSPECIFIEDVALUEEXPEVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createUnspecifiedValueExpEval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//UnspecifiedValueExpEval has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createUnspecifiedValueExpEval_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//UnspecifiedValueExpEval has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createUnspecifiedValueExpEval_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//UnspecifiedValueExpEval has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createUnspecifiedValueExpEval_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//UnspecifiedValueExpEval has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createUnspecifiedValueExpEval_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::VARIABLEDECLEVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createVariableDeclEval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//VariableDeclEval has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createVariableDeclEval_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//VariableDeclEval has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createVariableDeclEval_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//VariableDeclEval has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createVariableDeclEval_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//VariableDeclEval has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createVariableDeclEval_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case EvaluationsPackage::VARIABLEEXPEVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createVariableExpEval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//VariableExpEval has contextVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createVariableExpEval_as_contextVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//VariableExpEval has parameterVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createVariableExpEval_as_parameterVariable_in_ExpressionInOcl(castedContainer,metaElementID);
					}
					//VariableExpEval has result as a containment
					case  ocl::Expressions::ExpressionsPackage::ITERATEEXP_ATTRIBUTE_RESULT:	
					{
						std::shared_ptr<ocl::Expressions::IterateExp> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::IterateExp> (container);;
						return this->createVariableExpEval_as_result_in_IterateExp(castedContainer,metaElementID);
					}
					//VariableExpEval has resultVariable as a containment
					case  ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:	
					{
						std::shared_ptr<ocl::Expressions::ExpressionInOcl> castedContainer = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl> (container);;
						return this->createVariableExpEval_as_resultVariable_in_ExpressionInOcl(castedContainer,metaElementID);
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

std::shared_ptr<ecore::EObject> EvaluationsFactoryImpl::create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}
	int _elementID = _class->getMetaElementID();
	return create(_elementID, container, referenceID);
}

std::shared_ptr<ecore::EObject> EvaluationsFactoryImpl::create(std::string _className, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
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

std::shared_ptr<ocl::Evaluations::AssociationClassCallExpEval> EvaluationsFactoryImpl::createAssociationClassCallExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::AssociationClassCallExpEvalImpl> element(new ocl::Evaluations::AssociationClassCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisAssociationClassCallExpEvalPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::AssociationClassCallExpEval> EvaluationsFactoryImpl::createAssociationClassCallExpEval_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::AssociationClassCallExpEvalImpl> element(new ocl::Evaluations::AssociationClassCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisAssociationClassCallExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::AssociationClassCallExpEval> EvaluationsFactoryImpl::createAssociationClassCallExpEval_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::AssociationClassCallExpEvalImpl> element(new ocl::Evaluations::AssociationClassCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisAssociationClassCallExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::AssociationClassCallExpEval> EvaluationsFactoryImpl::createAssociationClassCallExpEval_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::AssociationClassCallExpEvalImpl> element(new ocl::Evaluations::AssociationClassCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisAssociationClassCallExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::AssociationClassCallExpEval> EvaluationsFactoryImpl::createAssociationClassCallExpEval_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::AssociationClassCallExpEvalImpl> element(new ocl::Evaluations::AssociationClassCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisAssociationClassCallExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::AssociationEndCallExpEval> EvaluationsFactoryImpl::createAssociationEndCallExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::AssociationEndCallExpEvalImpl> element(new ocl::Evaluations::AssociationEndCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisAssociationEndCallExpEvalPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::AssociationEndCallExpEval> EvaluationsFactoryImpl::createAssociationEndCallExpEval_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::AssociationEndCallExpEvalImpl> element(new ocl::Evaluations::AssociationEndCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisAssociationEndCallExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::AssociationEndCallExpEval> EvaluationsFactoryImpl::createAssociationEndCallExpEval_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::AssociationEndCallExpEvalImpl> element(new ocl::Evaluations::AssociationEndCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisAssociationEndCallExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::AssociationEndCallExpEval> EvaluationsFactoryImpl::createAssociationEndCallExpEval_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::AssociationEndCallExpEvalImpl> element(new ocl::Evaluations::AssociationEndCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisAssociationEndCallExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::AssociationEndCallExpEval> EvaluationsFactoryImpl::createAssociationEndCallExpEval_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::AssociationEndCallExpEvalImpl> element(new ocl::Evaluations::AssociationEndCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisAssociationEndCallExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::AttributeCallExpEval> EvaluationsFactoryImpl::createAttributeCallExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::AttributeCallExpEvalImpl> element(new ocl::Evaluations::AttributeCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisAttributeCallExpEvalPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::AttributeCallExpEval> EvaluationsFactoryImpl::createAttributeCallExpEval_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::AttributeCallExpEvalImpl> element(new ocl::Evaluations::AttributeCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisAttributeCallExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::AttributeCallExpEval> EvaluationsFactoryImpl::createAttributeCallExpEval_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::AttributeCallExpEvalImpl> element(new ocl::Evaluations::AttributeCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisAttributeCallExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::AttributeCallExpEval> EvaluationsFactoryImpl::createAttributeCallExpEval_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::AttributeCallExpEvalImpl> element(new ocl::Evaluations::AttributeCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisAttributeCallExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::AttributeCallExpEval> EvaluationsFactoryImpl::createAttributeCallExpEval_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::AttributeCallExpEvalImpl> element(new ocl::Evaluations::AttributeCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisAttributeCallExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::BooleanLiteralExpEval> EvaluationsFactoryImpl::createBooleanLiteralExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::BooleanLiteralExpEvalImpl> element(new ocl::Evaluations::BooleanLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisBooleanLiteralExpEvalPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::BooleanLiteralExpEval> EvaluationsFactoryImpl::createBooleanLiteralExpEval_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::BooleanLiteralExpEvalImpl> element(new ocl::Evaluations::BooleanLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisBooleanLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::BooleanLiteralExpEval> EvaluationsFactoryImpl::createBooleanLiteralExpEval_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::BooleanLiteralExpEvalImpl> element(new ocl::Evaluations::BooleanLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisBooleanLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::BooleanLiteralExpEval> EvaluationsFactoryImpl::createBooleanLiteralExpEval_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::BooleanLiteralExpEvalImpl> element(new ocl::Evaluations::BooleanLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisBooleanLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::BooleanLiteralExpEval> EvaluationsFactoryImpl::createBooleanLiteralExpEval_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::BooleanLiteralExpEvalImpl> element(new ocl::Evaluations::BooleanLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisBooleanLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::CollectionItemEval> EvaluationsFactoryImpl::createCollectionItemEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::CollectionItemEvalImpl> element(new ocl::Evaluations::CollectionItemEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCollectionItemEvalPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::CollectionItemEval> EvaluationsFactoryImpl::createCollectionItemEval_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::CollectionItemEvalImpl> element(new ocl::Evaluations::CollectionItemEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisCollectionItemEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::CollectionItemEval> EvaluationsFactoryImpl::createCollectionItemEval_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::CollectionItemEvalImpl> element(new ocl::Evaluations::CollectionItemEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisCollectionItemEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::CollectionItemEval> EvaluationsFactoryImpl::createCollectionItemEval_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::CollectionItemEvalImpl> element(new ocl::Evaluations::CollectionItemEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisCollectionItemEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::CollectionItemEval> EvaluationsFactoryImpl::createCollectionItemEval_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::CollectionItemEvalImpl> element(new ocl::Evaluations::CollectionItemEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisCollectionItemEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::CollectionLiteralExpEval> EvaluationsFactoryImpl::createCollectionLiteralExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::CollectionLiteralExpEvalImpl> element(new ocl::Evaluations::CollectionLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCollectionLiteralExpEvalPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::CollectionLiteralExpEval> EvaluationsFactoryImpl::createCollectionLiteralExpEval_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::CollectionLiteralExpEvalImpl> element(new ocl::Evaluations::CollectionLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisCollectionLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::CollectionLiteralExpEval> EvaluationsFactoryImpl::createCollectionLiteralExpEval_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::CollectionLiteralExpEvalImpl> element(new ocl::Evaluations::CollectionLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisCollectionLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::CollectionLiteralExpEval> EvaluationsFactoryImpl::createCollectionLiteralExpEval_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::CollectionLiteralExpEvalImpl> element(new ocl::Evaluations::CollectionLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisCollectionLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::CollectionLiteralExpEval> EvaluationsFactoryImpl::createCollectionLiteralExpEval_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::CollectionLiteralExpEvalImpl> element(new ocl::Evaluations::CollectionLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisCollectionLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::CollectionLiteralPartEval> EvaluationsFactoryImpl::createCollectionLiteralPartEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::CollectionLiteralPartEvalImpl> element(new ocl::Evaluations::CollectionLiteralPartEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCollectionLiteralPartEvalPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::CollectionLiteralPartEval> EvaluationsFactoryImpl::createCollectionLiteralPartEval_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::CollectionLiteralPartEvalImpl> element(new ocl::Evaluations::CollectionLiteralPartEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisCollectionLiteralPartEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::CollectionLiteralPartEval> EvaluationsFactoryImpl::createCollectionLiteralPartEval_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::CollectionLiteralPartEvalImpl> element(new ocl::Evaluations::CollectionLiteralPartEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisCollectionLiteralPartEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::CollectionLiteralPartEval> EvaluationsFactoryImpl::createCollectionLiteralPartEval_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::CollectionLiteralPartEvalImpl> element(new ocl::Evaluations::CollectionLiteralPartEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisCollectionLiteralPartEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::CollectionLiteralPartEval> EvaluationsFactoryImpl::createCollectionLiteralPartEval_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::CollectionLiteralPartEvalImpl> element(new ocl::Evaluations::CollectionLiteralPartEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisCollectionLiteralPartEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::CollectionRangeEval> EvaluationsFactoryImpl::createCollectionRangeEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::CollectionRangeEvalImpl> element(new ocl::Evaluations::CollectionRangeEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCollectionRangeEvalPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::CollectionRangeEval> EvaluationsFactoryImpl::createCollectionRangeEval_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::CollectionRangeEvalImpl> element(new ocl::Evaluations::CollectionRangeEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisCollectionRangeEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::CollectionRangeEval> EvaluationsFactoryImpl::createCollectionRangeEval_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::CollectionRangeEvalImpl> element(new ocl::Evaluations::CollectionRangeEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisCollectionRangeEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::CollectionRangeEval> EvaluationsFactoryImpl::createCollectionRangeEval_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::CollectionRangeEvalImpl> element(new ocl::Evaluations::CollectionRangeEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisCollectionRangeEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::CollectionRangeEval> EvaluationsFactoryImpl::createCollectionRangeEval_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::CollectionRangeEvalImpl> element(new ocl::Evaluations::CollectionRangeEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisCollectionRangeEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::EnumLiteralExpEval> EvaluationsFactoryImpl::createEnumLiteralExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::EnumLiteralExpEvalImpl> element(new ocl::Evaluations::EnumLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEnumLiteralExpEvalPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::EnumLiteralExpEval> EvaluationsFactoryImpl::createEnumLiteralExpEval_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::EnumLiteralExpEvalImpl> element(new ocl::Evaluations::EnumLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisEnumLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::EnumLiteralExpEval> EvaluationsFactoryImpl::createEnumLiteralExpEval_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::EnumLiteralExpEvalImpl> element(new ocl::Evaluations::EnumLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisEnumLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::EnumLiteralExpEval> EvaluationsFactoryImpl::createEnumLiteralExpEval_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::EnumLiteralExpEvalImpl> element(new ocl::Evaluations::EnumLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisEnumLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::EnumLiteralExpEval> EvaluationsFactoryImpl::createEnumLiteralExpEval_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::EnumLiteralExpEvalImpl> element(new ocl::Evaluations::EnumLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisEnumLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::EvalEnvironment> EvaluationsFactoryImpl::createEvalEnvironment(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::EvalEnvironmentImpl> element(new ocl::Evaluations::EvalEnvironmentImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEvalEnvironmentPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::EvalEnvironment> EvaluationsFactoryImpl::createEvalEnvironment_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::EvalEnvironmentImpl> element(new ocl::Evaluations::EvalEnvironmentImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisEvalEnvironmentPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::EvalEnvironment> EvaluationsFactoryImpl::createEvalEnvironment_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::EvalEnvironmentImpl> element(new ocl::Evaluations::EvalEnvironmentImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisEvalEnvironmentPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::EvalEnvironment> EvaluationsFactoryImpl::createEvalEnvironment_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::EvalEnvironmentImpl> element(new ocl::Evaluations::EvalEnvironmentImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisEvalEnvironmentPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::EvalEnvironment> EvaluationsFactoryImpl::createEvalEnvironment_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::EvalEnvironmentImpl> element(new ocl::Evaluations::EvalEnvironmentImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisEvalEnvironmentPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::EvalNameSpace> EvaluationsFactoryImpl::createEvalNameSpace(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::EvalNameSpaceImpl> element(new ocl::Evaluations::EvalNameSpaceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEvalNameSpacePtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::EvalNameSpace> EvaluationsFactoryImpl::createEvalNameSpace_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::EvalNameSpaceImpl> element(new ocl::Evaluations::EvalNameSpaceImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisEvalNameSpacePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::EvalNameSpace> EvaluationsFactoryImpl::createEvalNameSpace_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::EvalNameSpaceImpl> element(new ocl::Evaluations::EvalNameSpaceImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisEvalNameSpacePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::EvalNameSpace> EvaluationsFactoryImpl::createEvalNameSpace_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::EvalNameSpaceImpl> element(new ocl::Evaluations::EvalNameSpaceImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisEvalNameSpacePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::EvalNameSpace> EvaluationsFactoryImpl::createEvalNameSpace_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::EvalNameSpaceImpl> element(new ocl::Evaluations::EvalNameSpaceImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisEvalNameSpacePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::ExpressionInOclEval> EvaluationsFactoryImpl::createExpressionInOclEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::ExpressionInOclEvalImpl> element(new ocl::Evaluations::ExpressionInOclEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisExpressionInOclEvalPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::ExpressionInOclEval> EvaluationsFactoryImpl::createExpressionInOclEval_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::ExpressionInOclEvalImpl> element(new ocl::Evaluations::ExpressionInOclEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisExpressionInOclEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::ExpressionInOclEval> EvaluationsFactoryImpl::createExpressionInOclEval_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::ExpressionInOclEvalImpl> element(new ocl::Evaluations::ExpressionInOclEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisExpressionInOclEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::ExpressionInOclEval> EvaluationsFactoryImpl::createExpressionInOclEval_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::ExpressionInOclEvalImpl> element(new ocl::Evaluations::ExpressionInOclEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisExpressionInOclEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::ExpressionInOclEval> EvaluationsFactoryImpl::createExpressionInOclEval_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::ExpressionInOclEvalImpl> element(new ocl::Evaluations::ExpressionInOclEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisExpressionInOclEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::IfExpEval> EvaluationsFactoryImpl::createIfExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::IfExpEvalImpl> element(new ocl::Evaluations::IfExpEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisIfExpEvalPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::IfExpEval> EvaluationsFactoryImpl::createIfExpEval_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::IfExpEvalImpl> element(new ocl::Evaluations::IfExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisIfExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::IfExpEval> EvaluationsFactoryImpl::createIfExpEval_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::IfExpEvalImpl> element(new ocl::Evaluations::IfExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisIfExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::IfExpEval> EvaluationsFactoryImpl::createIfExpEval_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::IfExpEvalImpl> element(new ocl::Evaluations::IfExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisIfExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::IfExpEval> EvaluationsFactoryImpl::createIfExpEval_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::IfExpEvalImpl> element(new ocl::Evaluations::IfExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisIfExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::IntegerLiteralExpEval> EvaluationsFactoryImpl::createIntegerLiteralExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::IntegerLiteralExpEvalImpl> element(new ocl::Evaluations::IntegerLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisIntegerLiteralExpEvalPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::IntegerLiteralExpEval> EvaluationsFactoryImpl::createIntegerLiteralExpEval_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::IntegerLiteralExpEvalImpl> element(new ocl::Evaluations::IntegerLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisIntegerLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::IntegerLiteralExpEval> EvaluationsFactoryImpl::createIntegerLiteralExpEval_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::IntegerLiteralExpEvalImpl> element(new ocl::Evaluations::IntegerLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisIntegerLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::IntegerLiteralExpEval> EvaluationsFactoryImpl::createIntegerLiteralExpEval_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::IntegerLiteralExpEvalImpl> element(new ocl::Evaluations::IntegerLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisIntegerLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::IntegerLiteralExpEval> EvaluationsFactoryImpl::createIntegerLiteralExpEval_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::IntegerLiteralExpEvalImpl> element(new ocl::Evaluations::IntegerLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisIntegerLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::IterateExpEval> EvaluationsFactoryImpl::createIterateExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::IterateExpEvalImpl> element(new ocl::Evaluations::IterateExpEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisIterateExpEvalPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::IterateExpEval> EvaluationsFactoryImpl::createIterateExpEval_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::IterateExpEvalImpl> element(new ocl::Evaluations::IterateExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisIterateExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::IterateExpEval> EvaluationsFactoryImpl::createIterateExpEval_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::IterateExpEvalImpl> element(new ocl::Evaluations::IterateExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisIterateExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::IterateExpEval> EvaluationsFactoryImpl::createIterateExpEval_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::IterateExpEvalImpl> element(new ocl::Evaluations::IterateExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisIterateExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::IterateExpEval> EvaluationsFactoryImpl::createIterateExpEval_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::IterateExpEvalImpl> element(new ocl::Evaluations::IterateExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisIterateExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::IteratorExpEval> EvaluationsFactoryImpl::createIteratorExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::IteratorExpEvalImpl> element(new ocl::Evaluations::IteratorExpEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisIteratorExpEvalPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::IteratorExpEval> EvaluationsFactoryImpl::createIteratorExpEval_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::IteratorExpEvalImpl> element(new ocl::Evaluations::IteratorExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisIteratorExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::IteratorExpEval> EvaluationsFactoryImpl::createIteratorExpEval_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::IteratorExpEvalImpl> element(new ocl::Evaluations::IteratorExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisIteratorExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::IteratorExpEval> EvaluationsFactoryImpl::createIteratorExpEval_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::IteratorExpEvalImpl> element(new ocl::Evaluations::IteratorExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisIteratorExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::IteratorExpEval> EvaluationsFactoryImpl::createIteratorExpEval_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::IteratorExpEvalImpl> element(new ocl::Evaluations::IteratorExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisIteratorExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::LetExpEval> EvaluationsFactoryImpl::createLetExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::LetExpEvalImpl> element(new ocl::Evaluations::LetExpEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLetExpEvalPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::LetExpEval> EvaluationsFactoryImpl::createLetExpEval_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::LetExpEvalImpl> element(new ocl::Evaluations::LetExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisLetExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::LetExpEval> EvaluationsFactoryImpl::createLetExpEval_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::LetExpEvalImpl> element(new ocl::Evaluations::LetExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisLetExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::LetExpEval> EvaluationsFactoryImpl::createLetExpEval_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::LetExpEvalImpl> element(new ocl::Evaluations::LetExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisLetExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::LetExpEval> EvaluationsFactoryImpl::createLetExpEval_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::LetExpEvalImpl> element(new ocl::Evaluations::LetExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisLetExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::LiteralExpEval> EvaluationsFactoryImpl::createLiteralExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::LiteralExpEvalImpl> element(new ocl::Evaluations::LiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLiteralExpEvalPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::LiteralExpEval> EvaluationsFactoryImpl::createLiteralExpEval_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::LiteralExpEvalImpl> element(new ocl::Evaluations::LiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::LiteralExpEval> EvaluationsFactoryImpl::createLiteralExpEval_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::LiteralExpEvalImpl> element(new ocl::Evaluations::LiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::LiteralExpEval> EvaluationsFactoryImpl::createLiteralExpEval_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::LiteralExpEvalImpl> element(new ocl::Evaluations::LiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::LiteralExpEval> EvaluationsFactoryImpl::createLiteralExpEval_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::LiteralExpEvalImpl> element(new ocl::Evaluations::LiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::LoopExpEval> EvaluationsFactoryImpl::createLoopExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::LoopExpEvalImpl> element(new ocl::Evaluations::LoopExpEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLoopExpEvalPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::LoopExpEval> EvaluationsFactoryImpl::createLoopExpEval_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::LoopExpEvalImpl> element(new ocl::Evaluations::LoopExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisLoopExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::LoopExpEval> EvaluationsFactoryImpl::createLoopExpEval_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::LoopExpEvalImpl> element(new ocl::Evaluations::LoopExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisLoopExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::LoopExpEval> EvaluationsFactoryImpl::createLoopExpEval_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::LoopExpEvalImpl> element(new ocl::Evaluations::LoopExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisLoopExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::LoopExpEval> EvaluationsFactoryImpl::createLoopExpEval_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::LoopExpEvalImpl> element(new ocl::Evaluations::LoopExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisLoopExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::ModelPropertyCallExpEval> EvaluationsFactoryImpl::createModelPropertyCallExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::ModelPropertyCallExpEvalImpl> element(new ocl::Evaluations::ModelPropertyCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisModelPropertyCallExpEvalPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::ModelPropertyCallExpEval> EvaluationsFactoryImpl::createModelPropertyCallExpEval_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::ModelPropertyCallExpEvalImpl> element(new ocl::Evaluations::ModelPropertyCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisModelPropertyCallExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::ModelPropertyCallExpEval> EvaluationsFactoryImpl::createModelPropertyCallExpEval_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::ModelPropertyCallExpEvalImpl> element(new ocl::Evaluations::ModelPropertyCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisModelPropertyCallExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::ModelPropertyCallExpEval> EvaluationsFactoryImpl::createModelPropertyCallExpEval_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::ModelPropertyCallExpEvalImpl> element(new ocl::Evaluations::ModelPropertyCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisModelPropertyCallExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::ModelPropertyCallExpEval> EvaluationsFactoryImpl::createModelPropertyCallExpEval_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::ModelPropertyCallExpEvalImpl> element(new ocl::Evaluations::ModelPropertyCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisModelPropertyCallExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::NameValueBinding> EvaluationsFactoryImpl::createNameValueBinding(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::NameValueBindingImpl> element(new ocl::Evaluations::NameValueBindingImpl());
	element->setMetaElementID(metaElementID);
	element->setThisNameValueBindingPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::NameValueBinding> EvaluationsFactoryImpl::createNameValueBinding_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::NameValueBindingImpl> element(new ocl::Evaluations::NameValueBindingImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisNameValueBindingPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::NameValueBinding> EvaluationsFactoryImpl::createNameValueBinding_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::NameValueBindingImpl> element(new ocl::Evaluations::NameValueBindingImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisNameValueBindingPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::NameValueBinding> EvaluationsFactoryImpl::createNameValueBinding_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::NameValueBindingImpl> element(new ocl::Evaluations::NameValueBindingImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisNameValueBindingPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::NameValueBinding> EvaluationsFactoryImpl::createNameValueBinding_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::NameValueBindingImpl> element(new ocl::Evaluations::NameValueBindingImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisNameValueBindingPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::NavigationCallExpEval> EvaluationsFactoryImpl::createNavigationCallExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::NavigationCallExpEvalImpl> element(new ocl::Evaluations::NavigationCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisNavigationCallExpEvalPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::NavigationCallExpEval> EvaluationsFactoryImpl::createNavigationCallExpEval_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::NavigationCallExpEvalImpl> element(new ocl::Evaluations::NavigationCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisNavigationCallExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::NavigationCallExpEval> EvaluationsFactoryImpl::createNavigationCallExpEval_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::NavigationCallExpEvalImpl> element(new ocl::Evaluations::NavigationCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisNavigationCallExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::NavigationCallExpEval> EvaluationsFactoryImpl::createNavigationCallExpEval_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::NavigationCallExpEvalImpl> element(new ocl::Evaluations::NavigationCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisNavigationCallExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::NavigationCallExpEval> EvaluationsFactoryImpl::createNavigationCallExpEval_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::NavigationCallExpEvalImpl> element(new ocl::Evaluations::NavigationCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisNavigationCallExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::NumericLiteralExpEval> EvaluationsFactoryImpl::createNumericLiteralExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::NumericLiteralExpEvalImpl> element(new ocl::Evaluations::NumericLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisNumericLiteralExpEvalPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::NumericLiteralExpEval> EvaluationsFactoryImpl::createNumericLiteralExpEval_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::NumericLiteralExpEvalImpl> element(new ocl::Evaluations::NumericLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisNumericLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::NumericLiteralExpEval> EvaluationsFactoryImpl::createNumericLiteralExpEval_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::NumericLiteralExpEvalImpl> element(new ocl::Evaluations::NumericLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisNumericLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::NumericLiteralExpEval> EvaluationsFactoryImpl::createNumericLiteralExpEval_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::NumericLiteralExpEvalImpl> element(new ocl::Evaluations::NumericLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisNumericLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::NumericLiteralExpEval> EvaluationsFactoryImpl::createNumericLiteralExpEval_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::NumericLiteralExpEvalImpl> element(new ocl::Evaluations::NumericLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisNumericLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::OclExpEval> EvaluationsFactoryImpl::createOclExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::OclExpEvalImpl> element(new ocl::Evaluations::OclExpEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisOclExpEvalPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::OclExpEval> EvaluationsFactoryImpl::createOclExpEval_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::OclExpEvalImpl> element(new ocl::Evaluations::OclExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisOclExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::OclExpEval> EvaluationsFactoryImpl::createOclExpEval_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::OclExpEvalImpl> element(new ocl::Evaluations::OclExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisOclExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::OclExpEval> EvaluationsFactoryImpl::createOclExpEval_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::OclExpEvalImpl> element(new ocl::Evaluations::OclExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisOclExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::OclExpEval> EvaluationsFactoryImpl::createOclExpEval_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::OclExpEvalImpl> element(new ocl::Evaluations::OclExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisOclExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::OclMessageArgEval> EvaluationsFactoryImpl::createOclMessageArgEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::OclMessageArgEvalImpl> element(new ocl::Evaluations::OclMessageArgEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisOclMessageArgEvalPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::OclMessageArgEval> EvaluationsFactoryImpl::createOclMessageArgEval_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::OclMessageArgEvalImpl> element(new ocl::Evaluations::OclMessageArgEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisOclMessageArgEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::OclMessageArgEval> EvaluationsFactoryImpl::createOclMessageArgEval_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::OclMessageArgEvalImpl> element(new ocl::Evaluations::OclMessageArgEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisOclMessageArgEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::OclMessageArgEval> EvaluationsFactoryImpl::createOclMessageArgEval_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::OclMessageArgEvalImpl> element(new ocl::Evaluations::OclMessageArgEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisOclMessageArgEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::OclMessageArgEval> EvaluationsFactoryImpl::createOclMessageArgEval_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::OclMessageArgEvalImpl> element(new ocl::Evaluations::OclMessageArgEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisOclMessageArgEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::OclMessageExpEval> EvaluationsFactoryImpl::createOclMessageExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::OclMessageExpEvalImpl> element(new ocl::Evaluations::OclMessageExpEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisOclMessageExpEvalPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::OclMessageExpEval> EvaluationsFactoryImpl::createOclMessageExpEval_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::OclMessageExpEvalImpl> element(new ocl::Evaluations::OclMessageExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisOclMessageExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::OclMessageExpEval> EvaluationsFactoryImpl::createOclMessageExpEval_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::OclMessageExpEvalImpl> element(new ocl::Evaluations::OclMessageExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisOclMessageExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::OclMessageExpEval> EvaluationsFactoryImpl::createOclMessageExpEval_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::OclMessageExpEvalImpl> element(new ocl::Evaluations::OclMessageExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisOclMessageExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::OclMessageExpEval> EvaluationsFactoryImpl::createOclMessageExpEval_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::OclMessageExpEvalImpl> element(new ocl::Evaluations::OclMessageExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisOclMessageExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::OperationCallExpEval> EvaluationsFactoryImpl::createOperationCallExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::OperationCallExpEvalImpl> element(new ocl::Evaluations::OperationCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisOperationCallExpEvalPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::OperationCallExpEval> EvaluationsFactoryImpl::createOperationCallExpEval_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::OperationCallExpEvalImpl> element(new ocl::Evaluations::OperationCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisOperationCallExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::OperationCallExpEval> EvaluationsFactoryImpl::createOperationCallExpEval_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::OperationCallExpEvalImpl> element(new ocl::Evaluations::OperationCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisOperationCallExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::OperationCallExpEval> EvaluationsFactoryImpl::createOperationCallExpEval_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::OperationCallExpEvalImpl> element(new ocl::Evaluations::OperationCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisOperationCallExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::OperationCallExpEval> EvaluationsFactoryImpl::createOperationCallExpEval_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::OperationCallExpEvalImpl> element(new ocl::Evaluations::OperationCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisOperationCallExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::PrimitiveLiteralExpEval> EvaluationsFactoryImpl::createPrimitiveLiteralExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::PrimitiveLiteralExpEvalImpl> element(new ocl::Evaluations::PrimitiveLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisPrimitiveLiteralExpEvalPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::PrimitiveLiteralExpEval> EvaluationsFactoryImpl::createPrimitiveLiteralExpEval_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::PrimitiveLiteralExpEvalImpl> element(new ocl::Evaluations::PrimitiveLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisPrimitiveLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::PrimitiveLiteralExpEval> EvaluationsFactoryImpl::createPrimitiveLiteralExpEval_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::PrimitiveLiteralExpEvalImpl> element(new ocl::Evaluations::PrimitiveLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisPrimitiveLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::PrimitiveLiteralExpEval> EvaluationsFactoryImpl::createPrimitiveLiteralExpEval_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::PrimitiveLiteralExpEvalImpl> element(new ocl::Evaluations::PrimitiveLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisPrimitiveLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::PrimitiveLiteralExpEval> EvaluationsFactoryImpl::createPrimitiveLiteralExpEval_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::PrimitiveLiteralExpEvalImpl> element(new ocl::Evaluations::PrimitiveLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisPrimitiveLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::PropertyCallExpEval> EvaluationsFactoryImpl::createPropertyCallExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::PropertyCallExpEvalImpl> element(new ocl::Evaluations::PropertyCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisPropertyCallExpEvalPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::PropertyCallExpEval> EvaluationsFactoryImpl::createPropertyCallExpEval_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::PropertyCallExpEvalImpl> element(new ocl::Evaluations::PropertyCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisPropertyCallExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::PropertyCallExpEval> EvaluationsFactoryImpl::createPropertyCallExpEval_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::PropertyCallExpEvalImpl> element(new ocl::Evaluations::PropertyCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisPropertyCallExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::PropertyCallExpEval> EvaluationsFactoryImpl::createPropertyCallExpEval_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::PropertyCallExpEvalImpl> element(new ocl::Evaluations::PropertyCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisPropertyCallExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::PropertyCallExpEval> EvaluationsFactoryImpl::createPropertyCallExpEval_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::PropertyCallExpEvalImpl> element(new ocl::Evaluations::PropertyCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisPropertyCallExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::RealLiteralExpEval> EvaluationsFactoryImpl::createRealLiteralExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::RealLiteralExpEvalImpl> element(new ocl::Evaluations::RealLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisRealLiteralExpEvalPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::RealLiteralExpEval> EvaluationsFactoryImpl::createRealLiteralExpEval_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::RealLiteralExpEvalImpl> element(new ocl::Evaluations::RealLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisRealLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::RealLiteralExpEval> EvaluationsFactoryImpl::createRealLiteralExpEval_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::RealLiteralExpEvalImpl> element(new ocl::Evaluations::RealLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisRealLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::RealLiteralExpEval> EvaluationsFactoryImpl::createRealLiteralExpEval_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::RealLiteralExpEvalImpl> element(new ocl::Evaluations::RealLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisRealLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::RealLiteralExpEval> EvaluationsFactoryImpl::createRealLiteralExpEval_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::RealLiteralExpEvalImpl> element(new ocl::Evaluations::RealLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisRealLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::StringLiteralExpEval> EvaluationsFactoryImpl::createStringLiteralExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::StringLiteralExpEvalImpl> element(new ocl::Evaluations::StringLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisStringLiteralExpEvalPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::StringLiteralExpEval> EvaluationsFactoryImpl::createStringLiteralExpEval_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::StringLiteralExpEvalImpl> element(new ocl::Evaluations::StringLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisStringLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::StringLiteralExpEval> EvaluationsFactoryImpl::createStringLiteralExpEval_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::StringLiteralExpEvalImpl> element(new ocl::Evaluations::StringLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisStringLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::StringLiteralExpEval> EvaluationsFactoryImpl::createStringLiteralExpEval_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::StringLiteralExpEvalImpl> element(new ocl::Evaluations::StringLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisStringLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::StringLiteralExpEval> EvaluationsFactoryImpl::createStringLiteralExpEval_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::StringLiteralExpEvalImpl> element(new ocl::Evaluations::StringLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisStringLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::TupleLiteralExpEval> EvaluationsFactoryImpl::createTupleLiteralExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::TupleLiteralExpEvalImpl> element(new ocl::Evaluations::TupleLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisTupleLiteralExpEvalPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::TupleLiteralExpEval> EvaluationsFactoryImpl::createTupleLiteralExpEval_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::TupleLiteralExpEvalImpl> element(new ocl::Evaluations::TupleLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisTupleLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::TupleLiteralExpEval> EvaluationsFactoryImpl::createTupleLiteralExpEval_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::TupleLiteralExpEvalImpl> element(new ocl::Evaluations::TupleLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisTupleLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::TupleLiteralExpEval> EvaluationsFactoryImpl::createTupleLiteralExpEval_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::TupleLiteralExpEvalImpl> element(new ocl::Evaluations::TupleLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisTupleLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::TupleLiteralExpEval> EvaluationsFactoryImpl::createTupleLiteralExpEval_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::TupleLiteralExpEvalImpl> element(new ocl::Evaluations::TupleLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisTupleLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::TupleLiteralExpPartEval> EvaluationsFactoryImpl::createTupleLiteralExpPartEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::TupleLiteralExpPartEvalImpl> element(new ocl::Evaluations::TupleLiteralExpPartEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisTupleLiteralExpPartEvalPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::TupleLiteralExpPartEval> EvaluationsFactoryImpl::createTupleLiteralExpPartEval_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::TupleLiteralExpPartEvalImpl> element(new ocl::Evaluations::TupleLiteralExpPartEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisTupleLiteralExpPartEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::TupleLiteralExpPartEval> EvaluationsFactoryImpl::createTupleLiteralExpPartEval_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::TupleLiteralExpPartEvalImpl> element(new ocl::Evaluations::TupleLiteralExpPartEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisTupleLiteralExpPartEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::TupleLiteralExpPartEval> EvaluationsFactoryImpl::createTupleLiteralExpPartEval_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::TupleLiteralExpPartEvalImpl> element(new ocl::Evaluations::TupleLiteralExpPartEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisTupleLiteralExpPartEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::TupleLiteralExpPartEval> EvaluationsFactoryImpl::createTupleLiteralExpPartEval_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::TupleLiteralExpPartEvalImpl> element(new ocl::Evaluations::TupleLiteralExpPartEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisTupleLiteralExpPartEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::UnlimitedNaturalLiteralExpEval> EvaluationsFactoryImpl::createUnlimitedNaturalLiteralExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::UnlimitedNaturalLiteralExpEvalImpl> element(new ocl::Evaluations::UnlimitedNaturalLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisUnlimitedNaturalLiteralExpEvalPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::UnlimitedNaturalLiteralExpEval> EvaluationsFactoryImpl::createUnlimitedNaturalLiteralExpEval_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::UnlimitedNaturalLiteralExpEvalImpl> element(new ocl::Evaluations::UnlimitedNaturalLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisUnlimitedNaturalLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::UnlimitedNaturalLiteralExpEval> EvaluationsFactoryImpl::createUnlimitedNaturalLiteralExpEval_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::UnlimitedNaturalLiteralExpEvalImpl> element(new ocl::Evaluations::UnlimitedNaturalLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisUnlimitedNaturalLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::UnlimitedNaturalLiteralExpEval> EvaluationsFactoryImpl::createUnlimitedNaturalLiteralExpEval_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::UnlimitedNaturalLiteralExpEvalImpl> element(new ocl::Evaluations::UnlimitedNaturalLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisUnlimitedNaturalLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::UnlimitedNaturalLiteralExpEval> EvaluationsFactoryImpl::createUnlimitedNaturalLiteralExpEval_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::UnlimitedNaturalLiteralExpEvalImpl> element(new ocl::Evaluations::UnlimitedNaturalLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisUnlimitedNaturalLiteralExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::UnspecifiedValueExpEval> EvaluationsFactoryImpl::createUnspecifiedValueExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::UnspecifiedValueExpEvalImpl> element(new ocl::Evaluations::UnspecifiedValueExpEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisUnspecifiedValueExpEvalPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::UnspecifiedValueExpEval> EvaluationsFactoryImpl::createUnspecifiedValueExpEval_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::UnspecifiedValueExpEvalImpl> element(new ocl::Evaluations::UnspecifiedValueExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisUnspecifiedValueExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::UnspecifiedValueExpEval> EvaluationsFactoryImpl::createUnspecifiedValueExpEval_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::UnspecifiedValueExpEvalImpl> element(new ocl::Evaluations::UnspecifiedValueExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisUnspecifiedValueExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::UnspecifiedValueExpEval> EvaluationsFactoryImpl::createUnspecifiedValueExpEval_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::UnspecifiedValueExpEvalImpl> element(new ocl::Evaluations::UnspecifiedValueExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisUnspecifiedValueExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::UnspecifiedValueExpEval> EvaluationsFactoryImpl::createUnspecifiedValueExpEval_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::UnspecifiedValueExpEvalImpl> element(new ocl::Evaluations::UnspecifiedValueExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisUnspecifiedValueExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::VariableDeclEval> EvaluationsFactoryImpl::createVariableDeclEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::VariableDeclEvalImpl> element(new ocl::Evaluations::VariableDeclEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisVariableDeclEvalPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::VariableDeclEval> EvaluationsFactoryImpl::createVariableDeclEval_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::VariableDeclEvalImpl> element(new ocl::Evaluations::VariableDeclEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisVariableDeclEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::VariableDeclEval> EvaluationsFactoryImpl::createVariableDeclEval_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::VariableDeclEvalImpl> element(new ocl::Evaluations::VariableDeclEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisVariableDeclEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::VariableDeclEval> EvaluationsFactoryImpl::createVariableDeclEval_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::VariableDeclEvalImpl> element(new ocl::Evaluations::VariableDeclEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisVariableDeclEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::VariableDeclEval> EvaluationsFactoryImpl::createVariableDeclEval_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::VariableDeclEvalImpl> element(new ocl::Evaluations::VariableDeclEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisVariableDeclEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::VariableExpEval> EvaluationsFactoryImpl::createVariableExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::VariableExpEvalImpl> element(new ocl::Evaluations::VariableExpEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisVariableExpEvalPtr(element);
	return element;
}
std::shared_ptr<ocl::Evaluations::VariableExpEval> EvaluationsFactoryImpl::createVariableExpEval_as_contextVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::VariableExpEvalImpl> element(new ocl::Evaluations::VariableExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setContextVariable(element);
	}
	
	element->setThisVariableExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::VariableExpEval> EvaluationsFactoryImpl::createVariableExpEval_as_parameterVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::VariableExpEvalImpl> element(new ocl::Evaluations::VariableExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->getParameterVariable()->push_back(element);
	}
	
	element->setThisVariableExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::VariableExpEval> EvaluationsFactoryImpl::createVariableExpEval_as_result_in_IterateExp(std::shared_ptr<ocl::Expressions::IterateExp> par_IterateExp, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::VariableExpEvalImpl> element(new ocl::Evaluations::VariableExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_IterateExp)
	{
		par_IterateExp->setResult(element);
	}
	
	element->setThisVariableExpEvalPtr(element);
	return element;
	
}
std::shared_ptr<ocl::Evaluations::VariableExpEval> EvaluationsFactoryImpl::createVariableExpEval_as_resultVariable_in_ExpressionInOcl(std::shared_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int metaElementID) const
{
	std::shared_ptr<ocl::Evaluations::VariableExpEvalImpl> element(new ocl::Evaluations::VariableExpEvalImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ExpressionInOcl)
	{
		par_ExpressionInOcl->setResultVariable(element);
	}
	
	element->setThisVariableExpEvalPtr(element);
	return element;
	
}

