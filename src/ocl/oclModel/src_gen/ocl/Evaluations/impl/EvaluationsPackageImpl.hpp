//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EVALUATIONSPACKAGEIMPL_HPP
#define OCL_EVALUATIONSPACKAGEIMPL_HPP

// namespace macro header include
#include "ocl/ocl.hpp"

#include "ecore/ecorePackage.hpp"
#include "ecore/impl/EPackageImpl.hpp"

#include "ocl/Evaluations/EvaluationsPackage.hpp" 


namespace ocl::Evaluations 
{
	class AssociationClassCallExpEval;
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
	class VariableExpEval;}

namespace ecore
{
	class ecoreFactory;
}

namespace ocl::Evaluations
{
	class OCL_API EvaluationsPackageImpl : public ecore::EPackageImpl ,virtual public EvaluationsPackage
	{
		private:    
			EvaluationsPackageImpl(EvaluationsPackageImpl const&) = delete;
			EvaluationsPackageImpl& operator=(EvaluationsPackageImpl const&) = delete;

		protected:
			EvaluationsPackageImpl();

		public:
			virtual ~EvaluationsPackageImpl();

			// Begin Class AssociationClassCallExpEval
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getAssociationClassCallExpEval_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getAssociationClassCallExpEval_Attribute_referredAssociationClass() const ;
			
			
			// End Class AssociationClassCallExpEval

			// Begin Class AssociationEndCallExpEval
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getAssociationEndCallExpEval_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getAssociationEndCallExpEval_Attribute_referredAssociationEnd() const ;
			
			
			// End Class AssociationEndCallExpEval

			// Begin Class AttributeCallExpEval
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getAttributeCallExpEval_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getAttributeCallExpEval_Attribute_referredAttribute() const ;
			
			
			// End Class AttributeCallExpEval

			// Begin Class BooleanLiteralExpEval
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getBooleanLiteralExpEval_Class() const ;
			
			
			
			
			// End Class BooleanLiteralExpEval

			// Begin Class CollectionItemEval
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCollectionItemEval_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getCollectionItemEval_Attribute_item() const ;
			
			
			// End Class CollectionItemEval

			// Begin Class CollectionLiteralExpEval
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCollectionLiteralExpEval_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getCollectionLiteralExpEval_Attribute_parts() const ;
			
			
			// End Class CollectionLiteralExpEval

			// Begin Class CollectionLiteralPartEval
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCollectionLiteralPartEval_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getCollectionLiteralPartEval_Attribute_element() const ;
			
			
			// End Class CollectionLiteralPartEval

			// Begin Class CollectionRangeEval
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCollectionRangeEval_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getCollectionRangeEval_Attribute_first() const ;
			virtual std::shared_ptr<ecore::EReference> getCollectionRangeEval_Attribute_last() const ;
			
			
			// End Class CollectionRangeEval

			// Begin Class EnumLiteralExpEval
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEnumLiteralExpEval_Class() const ;
			
			
			
			
			// End Class EnumLiteralExpEval

			// Begin Class EvalEnvironment
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEvalEnvironment_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getEvalEnvironment_Attribute_bindings() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getEvalEnvironment_Operation_add_NameValueBinding() const ;
			virtual std::shared_ptr<ecore::EOperation> getEvalEnvironment_Operation_addAll_NameValueBinding() const ;
			virtual std::shared_ptr<ecore::EOperation> getEvalEnvironment_Operation_find_String() const ;
			virtual std::shared_ptr<ecore::EOperation> getEvalEnvironment_Operation_getValueOf_EString() const ;
			virtual std::shared_ptr<ecore::EOperation> getEvalEnvironment_Operation_replace_NameValueBinding() const ;
			
			// End Class EvalEnvironment

			// Begin Class EvalNameSpace
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEvalNameSpace_Class() const ;
			
			
			
			
			// End Class EvalNameSpace

			// Begin Class ExpressionInOclEval
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getExpressionInOclEval_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getExpressionInOclEval_Attribute_context() const ;
			virtual std::shared_ptr<ecore::EReference> getExpressionInOclEval_Attribute_environment() const ;
			
			
			// End Class ExpressionInOclEval

			// Begin Class IfExpEval
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getIfExpEval_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getIfExpEval_Attribute_condition() const ;
			virtual std::shared_ptr<ecore::EReference> getIfExpEval_Attribute_elseExpression() const ;
			virtual std::shared_ptr<ecore::EReference> getIfExpEval_Attribute_thenExpression() const ;
			
			
			// End Class IfExpEval

			// Begin Class IntegerLiteralExpEval
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getIntegerLiteralExpEval_Class() const ;
			
			
			
			
			// End Class IntegerLiteralExpEval

			// Begin Class IterateExpEval
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getIterateExpEval_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getIterateExpEval_Attribute_result() const ;
			
			
			// End Class IterateExpEval

			// Begin Class IteratorExpEval
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getIteratorExpEval_Class() const ;
			
			
			
			
			// End Class IteratorExpEval

			// Begin Class LetExpEval
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getLetExpEval_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getLetExpEval_Attribute_in() const ;
			virtual std::shared_ptr<ecore::EReference> getLetExpEval_Attribute_initExpression() const ;
			virtual std::shared_ptr<ecore::EReference> getLetExpEval_Attribute_variable() const ;
			
			
			// End Class LetExpEval

			// Begin Class LiteralExpEval
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getLiteralExpEval_Class() const ;
			
			
			
			
			// End Class LiteralExpEval

			// Begin Class LoopExpEval
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getLoopExpEval_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getLoopExpEval_Attribute_bodyEvals() const ;
			virtual std::shared_ptr<ecore::EReference> getLoopExpEval_Attribute_iterators() const ;
			
			
			// End Class LoopExpEval

			// Begin Class ModelPropertyCallExpEval
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getModelPropertyCallExpEval_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getModelPropertyCallExpEval_Operation_atPre() const ;
			
			// End Class ModelPropertyCallExpEval

			// Begin Class NavigationCallExpEval
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getNavigationCallExpEval_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getNavigationCallExpEval_Attribute_navigationSource() const ;
			virtual std::shared_ptr<ecore::EReference> getNavigationCallExpEval_Attribute_qualifiers() const ;
			
			
			// End Class NavigationCallExpEval

			// Begin Class NumericLiteralExpEval
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getNumericLiteralExpEval_Class() const ;
			
			
			
			
			// End Class NumericLiteralExpEval

			// Begin Class OclExpEval
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getOclExpEval_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getOclExpEval_Attribute_beforeEnvironment() const ;
			virtual std::shared_ptr<ecore::EReference> getOclExpEval_Attribute_environment() const ;
			virtual std::shared_ptr<ecore::EReference> getOclExpEval_Attribute_model() const ;
			virtual std::shared_ptr<ecore::EReference> getOclExpEval_Attribute_resultValue() const ;
			
			
			// End Class OclExpEval

			// Begin Class OclMessageArgEval
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getOclMessageArgEval_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getOclMessageArgEval_Attribute_expression() const ;
			virtual std::shared_ptr<ecore::EReference> getOclMessageArgEval_Attribute_unspecified() const ;
			virtual std::shared_ptr<ecore::EReference> getOclMessageArgEval_Attribute_variable() const ;
			
			
			// End Class OclMessageArgEval

			// Begin Class OclMessageExpEval
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getOclMessageExpEval_Class() const ;
			
			virtual std::shared_ptr<ecore::EAttribute> getOclMessageExpEval_Attribute_name() const ;
			
			virtual std::shared_ptr<ecore::EReference> getOclMessageExpEval_Attribute_arguments() const ;
			virtual std::shared_ptr<ecore::EReference> getOclMessageExpEval_Attribute_target() const ;
			
			
			// End Class OclMessageExpEval

			// Begin Class OperationCallExpEval
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getOperationCallExpEval_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getOperationCallExpEval_Attribute_arguments() const ;
			virtual std::shared_ptr<ecore::EReference> getOperationCallExpEval_Attribute_referredOperation() const ;
			
			
			// End Class OperationCallExpEval

			// Begin Class PrimitiveLiteralExpEval
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getPrimitiveLiteralExpEval_Class() const ;
			
			
			
			
			// End Class PrimitiveLiteralExpEval

			// Begin Class PropertyCallExpEval
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getPropertyCallExpEval_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getPropertyCallExpEval_Attribute_source() const ;
			
			
			// End Class PropertyCallExpEval

			// Begin Class RealLiteralExpEval
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getRealLiteralExpEval_Class() const ;
			
			
			
			
			// End Class RealLiteralExpEval

			// Begin Class StringLiteralExpEval
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getStringLiteralExpEval_Class() const ;
			
			
			
			
			// End Class StringLiteralExpEval

			// Begin Class TupleLiteralExpEval
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getTupleLiteralExpEval_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getTupleLiteralExpEval_Attribute_tuplePart() const ;
			
			
			// End Class TupleLiteralExpEval

			// Begin Class TupleLiteralExpPartEval
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getTupleLiteralExpPartEval_Class() const ;
			
			
			
			
			// End Class TupleLiteralExpPartEval

			// Begin Class UnlimitedNaturalLiteralExpEval
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getUnlimitedNaturalLiteralExpEval_Class() const ;
			
			
			
			
			// End Class UnlimitedNaturalLiteralExpEval

			// Begin Class UnspecifiedValueExpEval
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getUnspecifiedValueExpEval_Class() const ;
			
			
			
			
			// End Class UnspecifiedValueExpEval

			// Begin Class VariableDeclEval
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getVariableDeclEval_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getVariableDeclEval_Attribute_initExp() const ;
			virtual std::shared_ptr<ecore::EReference> getVariableDeclEval_Attribute_name() const ;
			
			
			// End Class VariableDeclEval

			// Begin Class VariableExpEval
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getVariableExpEval_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getVariableExpEval_Attribute_referredVariable() const ;
			
			
			// End Class VariableExpEval

			
			// SubPackages Getters
			

		private:
			std::shared_ptr<ecore::EClass> m_associationClassCallExpEval_Class = nullptr;std::shared_ptr<ecore::EClass> m_associationEndCallExpEval_Class = nullptr;std::shared_ptr<ecore::EClass> m_attributeCallExpEval_Class = nullptr;std::shared_ptr<ecore::EClass> m_booleanLiteralExpEval_Class = nullptr;std::shared_ptr<ecore::EClass> m_collectionItemEval_Class = nullptr;std::shared_ptr<ecore::EClass> m_collectionLiteralExpEval_Class = nullptr;std::shared_ptr<ecore::EClass> m_collectionLiteralPartEval_Class = nullptr;std::shared_ptr<ecore::EClass> m_collectionRangeEval_Class = nullptr;std::shared_ptr<ecore::EClass> m_enumLiteralExpEval_Class = nullptr;std::shared_ptr<ecore::EClass> m_evalEnvironment_Class = nullptr;std::shared_ptr<ecore::EClass> m_evalNameSpace_Class = nullptr;std::shared_ptr<ecore::EClass> m_expressionInOclEval_Class = nullptr;std::shared_ptr<ecore::EClass> m_ifExpEval_Class = nullptr;std::shared_ptr<ecore::EClass> m_integerLiteralExpEval_Class = nullptr;std::shared_ptr<ecore::EClass> m_iterateExpEval_Class = nullptr;std::shared_ptr<ecore::EClass> m_iteratorExpEval_Class = nullptr;std::shared_ptr<ecore::EClass> m_letExpEval_Class = nullptr;std::shared_ptr<ecore::EClass> m_literalExpEval_Class = nullptr;std::shared_ptr<ecore::EClass> m_loopExpEval_Class = nullptr;std::shared_ptr<ecore::EClass> m_modelPropertyCallExpEval_Class = nullptr;std::shared_ptr<ecore::EClass> m_navigationCallExpEval_Class = nullptr;std::shared_ptr<ecore::EClass> m_numericLiteralExpEval_Class = nullptr;std::shared_ptr<ecore::EClass> m_oclExpEval_Class = nullptr;std::shared_ptr<ecore::EClass> m_oclMessageArgEval_Class = nullptr;std::shared_ptr<ecore::EClass> m_oclMessageExpEval_Class = nullptr;std::shared_ptr<ecore::EClass> m_operationCallExpEval_Class = nullptr;std::shared_ptr<ecore::EClass> m_primitiveLiteralExpEval_Class = nullptr;std::shared_ptr<ecore::EClass> m_propertyCallExpEval_Class = nullptr;std::shared_ptr<ecore::EClass> m_realLiteralExpEval_Class = nullptr;std::shared_ptr<ecore::EClass> m_stringLiteralExpEval_Class = nullptr;std::shared_ptr<ecore::EClass> m_tupleLiteralExpEval_Class = nullptr;std::shared_ptr<ecore::EClass> m_tupleLiteralExpPartEval_Class = nullptr;std::shared_ptr<ecore::EClass> m_unlimitedNaturalLiteralExpEval_Class = nullptr;std::shared_ptr<ecore::EClass> m_unspecifiedValueExpEval_Class = nullptr;std::shared_ptr<ecore::EClass> m_variableDeclEval_Class = nullptr;std::shared_ptr<ecore::EClass> m_variableExpEval_Class = nullptr;
			
			std::shared_ptr<ecore::EAttribute> m_oclMessageExpEval_Attribute_name = nullptr;
			std::shared_ptr<ecore::EReference> m_oclMessageExpEval_Attribute_arguments = nullptr;std::shared_ptr<ecore::EReference> m_operationCallExpEval_Attribute_arguments = nullptr;std::shared_ptr<ecore::EReference> m_oclExpEval_Attribute_beforeEnvironment = nullptr;std::shared_ptr<ecore::EReference> m_evalEnvironment_Attribute_bindings = nullptr;std::shared_ptr<ecore::EReference> m_loopExpEval_Attribute_bodyEvals = nullptr;std::shared_ptr<ecore::EReference> m_ifExpEval_Attribute_condition = nullptr;std::shared_ptr<ecore::EReference> m_expressionInOclEval_Attribute_context = nullptr;std::shared_ptr<ecore::EReference> m_collectionLiteralPartEval_Attribute_element = nullptr;std::shared_ptr<ecore::EReference> m_ifExpEval_Attribute_elseExpression = nullptr;std::shared_ptr<ecore::EReference> m_expressionInOclEval_Attribute_environment = nullptr;std::shared_ptr<ecore::EReference> m_oclExpEval_Attribute_environment = nullptr;std::shared_ptr<ecore::EReference> m_oclMessageArgEval_Attribute_expression = nullptr;std::shared_ptr<ecore::EReference> m_collectionRangeEval_Attribute_first = nullptr;std::shared_ptr<ecore::EReference> m_letExpEval_Attribute_in = nullptr;std::shared_ptr<ecore::EReference> m_variableDeclEval_Attribute_initExp = nullptr;std::shared_ptr<ecore::EReference> m_letExpEval_Attribute_initExpression = nullptr;std::shared_ptr<ecore::EReference> m_collectionItemEval_Attribute_item = nullptr;std::shared_ptr<ecore::EReference> m_loopExpEval_Attribute_iterators = nullptr;std::shared_ptr<ecore::EReference> m_collectionRangeEval_Attribute_last = nullptr;std::shared_ptr<ecore::EReference> m_oclExpEval_Attribute_model = nullptr;std::shared_ptr<ecore::EReference> m_variableDeclEval_Attribute_name = nullptr;std::shared_ptr<ecore::EReference> m_navigationCallExpEval_Attribute_navigationSource = nullptr;std::shared_ptr<ecore::EReference> m_collectionLiteralExpEval_Attribute_parts = nullptr;std::shared_ptr<ecore::EReference> m_navigationCallExpEval_Attribute_qualifiers = nullptr;std::shared_ptr<ecore::EReference> m_associationClassCallExpEval_Attribute_referredAssociationClass = nullptr;std::shared_ptr<ecore::EReference> m_associationEndCallExpEval_Attribute_referredAssociationEnd = nullptr;std::shared_ptr<ecore::EReference> m_attributeCallExpEval_Attribute_referredAttribute = nullptr;std::shared_ptr<ecore::EReference> m_operationCallExpEval_Attribute_referredOperation = nullptr;std::shared_ptr<ecore::EReference> m_variableExpEval_Attribute_referredVariable = nullptr;std::shared_ptr<ecore::EReference> m_iterateExpEval_Attribute_result = nullptr;std::shared_ptr<ecore::EReference> m_oclExpEval_Attribute_resultValue = nullptr;std::shared_ptr<ecore::EReference> m_propertyCallExpEval_Attribute_source = nullptr;std::shared_ptr<ecore::EReference> m_oclMessageExpEval_Attribute_target = nullptr;std::shared_ptr<ecore::EReference> m_ifExpEval_Attribute_thenExpression = nullptr;std::shared_ptr<ecore::EReference> m_tupleLiteralExpEval_Attribute_tuplePart = nullptr;std::shared_ptr<ecore::EReference> m_oclMessageArgEval_Attribute_unspecified = nullptr;std::shared_ptr<ecore::EReference> m_oclMessageArgEval_Attribute_variable = nullptr;std::shared_ptr<ecore::EReference> m_letExpEval_Attribute_variable = nullptr;
			std::shared_ptr<ecore::EOperation> m_evalEnvironment_Operation_add_NameValueBinding = nullptr;std::shared_ptr<ecore::EOperation> m_evalEnvironment_Operation_addAll_NameValueBinding = nullptr;std::shared_ptr<ecore::EOperation> m_modelPropertyCallExpEval_Operation_atPre = nullptr;std::shared_ptr<ecore::EOperation> m_evalEnvironment_Operation_find_String = nullptr;std::shared_ptr<ecore::EOperation> m_evalEnvironment_Operation_getValueOf_EString = nullptr;std::shared_ptr<ecore::EOperation> m_evalEnvironment_Operation_replace_NameValueBinding = nullptr;

			friend class EvaluationsPackage;

			static bool isInited;
			static EvaluationsPackage* create();
			bool isInitialized = false;
 			bool isCreated = false;

			virtual void init(std::shared_ptr<ecore::EPackage> package);

		public:
			void createPackageContents(std::shared_ptr<ecore::EPackage> package);
			void initializePackageContents();

		private:
			void createAssociationClassCallExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createAssociationEndCallExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createAttributeCallExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createBooleanLiteralExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createCollectionItemEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createCollectionLiteralExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createCollectionLiteralPartEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createCollectionRangeEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createEnumLiteralExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createEvalEnvironmentContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createEvalNameSpaceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createExpressionInOclEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createIfExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createIntegerLiteralExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createIterateExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createIteratorExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createLetExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createLiteralExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createLoopExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createModelPropertyCallExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createNavigationCallExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createNumericLiteralExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createOclExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createOclMessageArgEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createOclMessageExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createOperationCallExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createPrimitiveLiteralExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createPropertyCallExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createRealLiteralExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createStringLiteralExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createTupleLiteralExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createTupleLiteralExpPartEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createUnlimitedNaturalLiteralExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createUnspecifiedValueExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createVariableDeclEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createVariableExpEvalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);

			void initializeAssociationClassCallExpEvalContent();
			void initializeAssociationEndCallExpEvalContent();
			void initializeAttributeCallExpEvalContent();
			void initializeBooleanLiteralExpEvalContent();
			void initializeCollectionItemEvalContent();
			void initializeCollectionLiteralExpEvalContent();
			void initializeCollectionLiteralPartEvalContent();
			void initializeCollectionRangeEvalContent();
			void initializeEnumLiteralExpEvalContent();
			void initializeEvalEnvironmentContent();
			void initializeEvalNameSpaceContent();
			void initializeExpressionInOclEvalContent();
			void initializeIfExpEvalContent();
			void initializeIntegerLiteralExpEvalContent();
			void initializeIterateExpEvalContent();
			void initializeIteratorExpEvalContent();
			void initializeLetExpEvalContent();
			void initializeLiteralExpEvalContent();
			void initializeLoopExpEvalContent();
			void initializeModelPropertyCallExpEvalContent();
			void initializeNavigationCallExpEvalContent();
			void initializeNumericLiteralExpEvalContent();
			void initializeOclExpEvalContent();
			void initializeOclMessageArgEvalContent();
			void initializeOclMessageExpEvalContent();
			void initializeOperationCallExpEvalContent();
			void initializePrimitiveLiteralExpEvalContent();
			void initializePropertyCallExpEvalContent();
			void initializeRealLiteralExpEvalContent();
			void initializeStringLiteralExpEvalContent();
			void initializeTupleLiteralExpEvalContent();
			void initializeTupleLiteralExpPartEvalContent();
			void initializeUnlimitedNaturalLiteralExpEvalContent();
			void initializeUnspecifiedValueExpEvalContent();
			void initializeVariableDeclEvalContent();
			void initializeVariableExpEvalContent();
			void initializePackageEDataTypes();



	};
}
#endif /* end of include guard: OCL_EVALUATIONSPACKAGEIMPL_HPP */