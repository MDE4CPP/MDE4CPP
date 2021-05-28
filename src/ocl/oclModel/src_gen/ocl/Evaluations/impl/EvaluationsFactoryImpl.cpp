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



using namespace ocl::Evaluations;

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
				return this->createAssociationClassCallExpEval(metaElementID);
			
		}
		case EvaluationsPackage::ASSOCIATIONENDCALLEXPEVAL_CLASS:
		{
				return this->createAssociationEndCallExpEval(metaElementID);
			
		}
		case EvaluationsPackage::ATTRIBUTECALLEXPEVAL_CLASS:
		{
				return this->createAttributeCallExpEval(metaElementID);
			
		}
		case EvaluationsPackage::BOOLEANLITERALEXPEVAL_CLASS:
		{
				return this->createBooleanLiteralExpEval(metaElementID);
			
		}
		case EvaluationsPackage::COLLECTIONITEMEVAL_CLASS:
		{
				return this->createCollectionItemEval(metaElementID);
			
		}
		case EvaluationsPackage::COLLECTIONLITERALEXPEVAL_CLASS:
		{
				return this->createCollectionLiteralExpEval(metaElementID);
			
		}
		case EvaluationsPackage::COLLECTIONLITERALPARTEVAL_CLASS:
		{
				return this->createCollectionLiteralPartEval(metaElementID);
			
		}
		case EvaluationsPackage::COLLECTIONRANGEEVAL_CLASS:
		{
				return this->createCollectionRangeEval(metaElementID);
			
		}
		case EvaluationsPackage::ENUMLITERALEXPEVAL_CLASS:
		{
				return this->createEnumLiteralExpEval(metaElementID);
			
		}
		case EvaluationsPackage::EVALENVIRONMENT_CLASS:
		{
				return this->createEvalEnvironment(metaElementID);
			
		}
		case EvaluationsPackage::EVALNAMESPACE_CLASS:
		{
				return this->createEvalNameSpace(metaElementID);
			
		}
		case EvaluationsPackage::EXPRESSIONINOCLEVAL_CLASS:
		{
				return this->createExpressionInOclEval(metaElementID);
			
		}
		case EvaluationsPackage::IFEXPEVAL_CLASS:
		{
				return this->createIfExpEval(metaElementID);
			
		}
		case EvaluationsPackage::INTEGERLITERALEXPEVAL_CLASS:
		{
				return this->createIntegerLiteralExpEval(metaElementID);
			
		}
		case EvaluationsPackage::ITERATEEXPEVAL_CLASS:
		{
				return this->createIterateExpEval(metaElementID);
			
		}
		case EvaluationsPackage::ITERATOREXPEVAL_CLASS:
		{
				return this->createIteratorExpEval(metaElementID);
			
		}
		case EvaluationsPackage::LETEXPEVAL_CLASS:
		{
				return this->createLetExpEval(metaElementID);
			
		}
		case EvaluationsPackage::LITERALEXPEVAL_CLASS:
		{
				return this->createLiteralExpEval(metaElementID);
			
		}
		case EvaluationsPackage::LOOPEXPEVAL_CLASS:
		{
				return this->createLoopExpEval(metaElementID);
			
		}
		case EvaluationsPackage::MODELPROPERTYCALLEXPEVAL_CLASS:
		{
				return this->createModelPropertyCallExpEval(metaElementID);
			
		}
		case EvaluationsPackage::NAVIGATIONCALLEXPEVAL_CLASS:
		{
				return this->createNavigationCallExpEval(metaElementID);
			
		}
		case EvaluationsPackage::NUMERICLITERALEXPEVAL_CLASS:
		{
				return this->createNumericLiteralExpEval(metaElementID);
			
		}
		case EvaluationsPackage::OCLEXPEVAL_CLASS:
		{
				return this->createOclExpEval(metaElementID);
			
		}
		case EvaluationsPackage::OCLMESSAGEARGEVAL_CLASS:
		{
				return this->createOclMessageArgEval(metaElementID);
			
		}
		case EvaluationsPackage::OCLMESSAGEEXPEVAL_CLASS:
		{
				return this->createOclMessageExpEval(metaElementID);
			
		}
		case EvaluationsPackage::OPERATIONCALLEXPEVAL_CLASS:
		{
				return this->createOperationCallExpEval(metaElementID);
			
		}
		case EvaluationsPackage::PRIMITIVELITERALEXPEVAL_CLASS:
		{
				return this->createPrimitiveLiteralExpEval(metaElementID);
			
		}
		case EvaluationsPackage::PROPERTYCALLEXPEVAL_CLASS:
		{
				return this->createPropertyCallExpEval(metaElementID);
			
		}
		case EvaluationsPackage::REALLITERALEXPEVAL_CLASS:
		{
				return this->createRealLiteralExpEval(metaElementID);
			
		}
		case EvaluationsPackage::STRINGLITERALEXPEVAL_CLASS:
		{
				return this->createStringLiteralExpEval(metaElementID);
			
		}
		case EvaluationsPackage::TUPLELITERALEXPEVAL_CLASS:
		{
				return this->createTupleLiteralExpEval(metaElementID);
			
		}
		case EvaluationsPackage::TUPLELITERALEXPPARTEVAL_CLASS:
		{
				return this->createTupleLiteralExpPartEval(metaElementID);
			
		}
		case EvaluationsPackage::UNLIMITEDNATURALLITERALEXPEVAL_CLASS:
		{
				return this->createUnlimitedNaturalLiteralExpEval(metaElementID);
			
		}
		case EvaluationsPackage::UNSPECIFIEDVALUEEXPEVAL_CLASS:
		{
				return this->createUnspecifiedValueExpEval(metaElementID);
			
		}
		case EvaluationsPackage::VARIABLEDECLEVAL_CLASS:
		{
				return this->createVariableDeclEval(metaElementID);
			
		}
		case EvaluationsPackage::VARIABLEEXPEVAL_CLASS:
		{
				return this->createVariableExpEval(metaElementID);
			
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

std::shared_ptr<ocl::Evaluations::AssociationEndCallExpEval> EvaluationsFactoryImpl::createAssociationEndCallExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::AssociationEndCallExpEvalImpl> element(new ocl::Evaluations::AssociationEndCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
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

std::shared_ptr<ocl::Evaluations::BooleanLiteralExpEval> EvaluationsFactoryImpl::createBooleanLiteralExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::BooleanLiteralExpEvalImpl> element(new ocl::Evaluations::BooleanLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
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

std::shared_ptr<ocl::Evaluations::CollectionLiteralExpEval> EvaluationsFactoryImpl::createCollectionLiteralExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::CollectionLiteralExpEvalImpl> element(new ocl::Evaluations::CollectionLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
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

std::shared_ptr<ocl::Evaluations::CollectionRangeEval> EvaluationsFactoryImpl::createCollectionRangeEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::CollectionRangeEvalImpl> element(new ocl::Evaluations::CollectionRangeEvalImpl());
	element->setMetaElementID(metaElementID);
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

std::shared_ptr<ocl::Evaluations::EvalEnvironment> EvaluationsFactoryImpl::createEvalEnvironment(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::EvalEnvironmentImpl> element(new ocl::Evaluations::EvalEnvironmentImpl());
	element->setMetaElementID(metaElementID);
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

std::shared_ptr<ocl::Evaluations::ExpressionInOclEval> EvaluationsFactoryImpl::createExpressionInOclEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::ExpressionInOclEvalImpl> element(new ocl::Evaluations::ExpressionInOclEvalImpl());
	element->setMetaElementID(metaElementID);
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

std::shared_ptr<ocl::Evaluations::IntegerLiteralExpEval> EvaluationsFactoryImpl::createIntegerLiteralExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::IntegerLiteralExpEvalImpl> element(new ocl::Evaluations::IntegerLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
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

std::shared_ptr<ocl::Evaluations::IteratorExpEval> EvaluationsFactoryImpl::createIteratorExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::IteratorExpEvalImpl> element(new ocl::Evaluations::IteratorExpEvalImpl());
	element->setMetaElementID(metaElementID);
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

std::shared_ptr<ocl::Evaluations::LiteralExpEval> EvaluationsFactoryImpl::createLiteralExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::LiteralExpEvalImpl> element(new ocl::Evaluations::LiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
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

std::shared_ptr<ocl::Evaluations::ModelPropertyCallExpEval> EvaluationsFactoryImpl::createModelPropertyCallExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::ModelPropertyCallExpEvalImpl> element(new ocl::Evaluations::ModelPropertyCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisModelPropertyCallExpEvalPtr(element);
	return element;
}

std::shared_ptr<ocl::Evaluations::NavigationCallExpEval> EvaluationsFactoryImpl::createNavigationCallExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::NavigationCallExpEvalImpl> element(new ocl::Evaluations::NavigationCallExpEvalImpl());
	element->setMetaElementID(metaElementID);
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

std::shared_ptr<ocl::Evaluations::OclExpEval> EvaluationsFactoryImpl::createOclExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::OclExpEvalImpl> element(new ocl::Evaluations::OclExpEvalImpl());
	element->setMetaElementID(metaElementID);
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

std::shared_ptr<ocl::Evaluations::OclMessageExpEval> EvaluationsFactoryImpl::createOclMessageExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::OclMessageExpEvalImpl> element(new ocl::Evaluations::OclMessageExpEvalImpl());
	element->setMetaElementID(metaElementID);
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

std::shared_ptr<ocl::Evaluations::PrimitiveLiteralExpEval> EvaluationsFactoryImpl::createPrimitiveLiteralExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::PrimitiveLiteralExpEvalImpl> element(new ocl::Evaluations::PrimitiveLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
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

std::shared_ptr<ocl::Evaluations::RealLiteralExpEval> EvaluationsFactoryImpl::createRealLiteralExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::RealLiteralExpEvalImpl> element(new ocl::Evaluations::RealLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
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

std::shared_ptr<ocl::Evaluations::TupleLiteralExpEval> EvaluationsFactoryImpl::createTupleLiteralExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::TupleLiteralExpEvalImpl> element(new ocl::Evaluations::TupleLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
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

std::shared_ptr<ocl::Evaluations::UnlimitedNaturalLiteralExpEval> EvaluationsFactoryImpl::createUnlimitedNaturalLiteralExpEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::UnlimitedNaturalLiteralExpEvalImpl> element(new ocl::Evaluations::UnlimitedNaturalLiteralExpEvalImpl());
	element->setMetaElementID(metaElementID);
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

std::shared_ptr<ocl::Evaluations::VariableDeclEval> EvaluationsFactoryImpl::createVariableDeclEval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Evaluations::VariableDeclEvalImpl> element(new ocl::Evaluations::VariableDeclEvalImpl());
	element->setMetaElementID(metaElementID);
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


