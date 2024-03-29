//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EVALUATIONSFACTORYIMPL_HPP
#define OCL_EVALUATIONSFACTORYIMPL_HPP

// namespace macro header include
#include "ocl/ocl.hpp"

#include "ecore/impl/EFactoryImpl.hpp"

#include "ocl/Evaluations/EvaluationsFactory.hpp"

namespace Evaluations 
{	class AssociationClassCallExpEval;
	class AssociationEndCallExpEval;
	class AttributeCallExpEval;
	class BooleanLiteralExpEval;
	class CollectionItemEval;
	class CollectionLiteralExpEval;
	class CollectionLiteralPartEval;
	class CollectionRangeEval;
	class EnumLiteralExpEval;
	class EvalEnvironment;
	class EvalNameSpace;
	class ExpressionInOclEval;
	class IfExpEval;
	class IntegerLiteralExpEval;
	class IterateExpEval;
	class IteratorExpEval;
	class LetExpEval;
	class LiteralExpEval;
	class LoopExpEval;
	class ModelPropertyCallExpEval;
	class NavigationCallExpEval;
	class NumericLiteralExpEval;
	class OclExpEval;
	class OclMessageArgEval;
	class OclMessageExpEval;
	class OperationCallExpEval;
	class PrimitiveLiteralExpEval;
	class PropertyCallExpEval;
	class RealLiteralExpEval;
	class StringLiteralExpEval;
	class TupleLiteralExpEval;
	class TupleLiteralExpPartEval;
	class UnlimitedNaturalLiteralExpEval;
	class UnspecifiedValueExpEval;
	class VariableDeclEval;
	class VariableExpEval;
}

namespace ocl::Evaluations 
{
	class OCL_API EvaluationsFactoryImpl : virtual public ecore::EFactoryImpl , virtual public EvaluationsFactory 
	{
		private:    
			EvaluationsFactoryImpl(EvaluationsFactoryImpl const&) = delete;
			EvaluationsFactoryImpl& operator=(EvaluationsFactoryImpl const&) = delete;

		protected:
			friend class EvaluationsFactory;
			// Constructor
			EvaluationsFactoryImpl();

		public:
			virtual ~EvaluationsFactoryImpl();
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const;

			//Creator functions
			 virtual std::shared_ptr<ocl::Evaluations::AssociationClassCallExpEval> createAssociationClassCallExpEval(const int metaElementID = EvaluationsPackage::ASSOCIATIONCLASSCALLEXPEVAL_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::AssociationEndCallExpEval> createAssociationEndCallExpEval(const int metaElementID = EvaluationsPackage::ASSOCIATIONENDCALLEXPEVAL_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::AttributeCallExpEval> createAttributeCallExpEval(const int metaElementID = EvaluationsPackage::ATTRIBUTECALLEXPEVAL_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::BooleanLiteralExpEval> createBooleanLiteralExpEval(const int metaElementID = EvaluationsPackage::BOOLEANLITERALEXPEVAL_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::CollectionItemEval> createCollectionItemEval(const int metaElementID = EvaluationsPackage::COLLECTIONITEMEVAL_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::CollectionLiteralExpEval> createCollectionLiteralExpEval(const int metaElementID = EvaluationsPackage::COLLECTIONLITERALEXPEVAL_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::CollectionLiteralPartEval> createCollectionLiteralPartEval(const int metaElementID = EvaluationsPackage::COLLECTIONLITERALPARTEVAL_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::CollectionRangeEval> createCollectionRangeEval(const int metaElementID = EvaluationsPackage::COLLECTIONRANGEEVAL_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::EnumLiteralExpEval> createEnumLiteralExpEval(const int metaElementID = EvaluationsPackage::ENUMLITERALEXPEVAL_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::EvalEnvironment> createEvalEnvironment(const int metaElementID = EvaluationsPackage::EVALENVIRONMENT_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::EvalNameSpace> createEvalNameSpace(const int metaElementID = EvaluationsPackage::EVALNAMESPACE_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::ExpressionInOclEval> createExpressionInOclEval(const int metaElementID = EvaluationsPackage::EXPRESSIONINOCLEVAL_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::IfExpEval> createIfExpEval(const int metaElementID = EvaluationsPackage::IFEXPEVAL_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::IntegerLiteralExpEval> createIntegerLiteralExpEval(const int metaElementID = EvaluationsPackage::INTEGERLITERALEXPEVAL_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::IterateExpEval> createIterateExpEval(const int metaElementID = EvaluationsPackage::ITERATEEXPEVAL_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::IteratorExpEval> createIteratorExpEval(const int metaElementID = EvaluationsPackage::ITERATOREXPEVAL_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::LetExpEval> createLetExpEval(const int metaElementID = EvaluationsPackage::LETEXPEVAL_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::LiteralExpEval> createLiteralExpEval(const int metaElementID = EvaluationsPackage::LITERALEXPEVAL_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::LoopExpEval> createLoopExpEval(const int metaElementID = EvaluationsPackage::LOOPEXPEVAL_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::ModelPropertyCallExpEval> createModelPropertyCallExpEval(const int metaElementID = EvaluationsPackage::MODELPROPERTYCALLEXPEVAL_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::NavigationCallExpEval> createNavigationCallExpEval(const int metaElementID = EvaluationsPackage::NAVIGATIONCALLEXPEVAL_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::NumericLiteralExpEval> createNumericLiteralExpEval(const int metaElementID = EvaluationsPackage::NUMERICLITERALEXPEVAL_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::OclExpEval> createOclExpEval(const int metaElementID = EvaluationsPackage::OCLEXPEVAL_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::OclMessageArgEval> createOclMessageArgEval(const int metaElementID = EvaluationsPackage::OCLMESSAGEARGEVAL_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::OclMessageExpEval> createOclMessageExpEval(const int metaElementID = EvaluationsPackage::OCLMESSAGEEXPEVAL_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::OperationCallExpEval> createOperationCallExpEval(const int metaElementID = EvaluationsPackage::OPERATIONCALLEXPEVAL_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::PrimitiveLiteralExpEval> createPrimitiveLiteralExpEval(const int metaElementID = EvaluationsPackage::PRIMITIVELITERALEXPEVAL_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::PropertyCallExpEval> createPropertyCallExpEval(const int metaElementID = EvaluationsPackage::PROPERTYCALLEXPEVAL_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::RealLiteralExpEval> createRealLiteralExpEval(const int metaElementID = EvaluationsPackage::REALLITERALEXPEVAL_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::StringLiteralExpEval> createStringLiteralExpEval(const int metaElementID = EvaluationsPackage::STRINGLITERALEXPEVAL_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::TupleLiteralExpEval> createTupleLiteralExpEval(const int metaElementID = EvaluationsPackage::TUPLELITERALEXPEVAL_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::TupleLiteralExpPartEval> createTupleLiteralExpPartEval(const int metaElementID = EvaluationsPackage::TUPLELITERALEXPPARTEVAL_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::UnlimitedNaturalLiteralExpEval> createUnlimitedNaturalLiteralExpEval(const int metaElementID = EvaluationsPackage::UNLIMITEDNATURALLITERALEXPEVAL_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::UnspecifiedValueExpEval> createUnspecifiedValueExpEval(const int metaElementID = EvaluationsPackage::UNSPECIFIEDVALUEEXPEVAL_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::VariableDeclEval> createVariableDeclEval(const int metaElementID = EvaluationsPackage::VARIABLEDECLEVAL_CLASS) const ;
			 virtual std::shared_ptr<ocl::Evaluations::VariableExpEval> createVariableExpEval(const int metaElementID = EvaluationsPackage::VARIABLEEXPEVAL_CLASS) const ;
			 

		private:
			static EvaluationsFactory* create();
            std::map<std::string,int> m_idMap;
	};
}
#endif /* end of include guard: OCL_EVALUATIONSFACTORYIMPL_HPP */
