//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSSM_SEMANTICS_VALUESPACKAGEIMPL_HPP
#define PSSM_SEMANTICS_VALUESPACKAGEIMPL_HPP

// namespace macro header include
#include "PSSM/PSSM.hpp"

#include "ecore/ecorePackage.hpp"
#include "ecore/impl/EPackageImpl.hpp"

#include "PSSM/Semantics/Values/ValuesPackage.hpp" 


namespace PSSM::Semantics::Values 
{
	class SM_OpaqueExpressionEvaluation;}

namespace ecore
{
	class ecoreFactory;
}

namespace PSSM::Semantics::Values
{
	class PSSM_API ValuesPackageImpl : public ecore::EPackageImpl ,virtual public ValuesPackage
	{
		private:    
			ValuesPackageImpl(ValuesPackageImpl const&) = delete;
			ValuesPackageImpl& operator=(ValuesPackageImpl const&) = delete;

		protected:
			ValuesPackageImpl();

		public:
			virtual ~ValuesPackageImpl();

			// Begin Class SM_OpaqueExpressionEvaluation
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getSM_OpaqueExpressionEvaluation_Class() const ;
			
			
			virtual const std::shared_ptr<ecore::EReference>& getSM_OpaqueExpressionEvaluation_Attribute_context() const ;
			virtual const std::shared_ptr<ecore::EReference>& getSM_OpaqueExpressionEvaluation_Attribute_parameterValues() const ;
			
			virtual const std::shared_ptr<ecore::EOperation>& getSM_OpaqueExpressionEvaluation_Operation_executeExpressionBehavior() const ;
			virtual const std::shared_ptr<ecore::EOperation>& getSM_OpaqueExpressionEvaluation_Operation_getParameterValue_Parameter() const ;
			virtual const std::shared_ptr<ecore::EOperation>& getSM_OpaqueExpressionEvaluation_Operation_initialize_EventOccurrence() const ;
			virtual const std::shared_ptr<ecore::EOperation>& getSM_OpaqueExpressionEvaluation_Operation_setParameterValue_ParameterValue() const ;
			
			// End Class SM_OpaqueExpressionEvaluation

			
			// SubPackages Getters
			

		private:
			std::shared_ptr<ecore::EClass> m_sM_OpaqueExpressionEvaluation_Class = nullptr;
			
			
			std::shared_ptr<ecore::EReference> m_sM_OpaqueExpressionEvaluation_Attribute_context = nullptr;std::shared_ptr<ecore::EReference> m_sM_OpaqueExpressionEvaluation_Attribute_parameterValues = nullptr;
			std::shared_ptr<ecore::EOperation> m_sM_OpaqueExpressionEvaluation_Operation_executeExpressionBehavior = nullptr;std::shared_ptr<ecore::EOperation> m_sM_OpaqueExpressionEvaluation_Operation_getParameterValue_Parameter = nullptr;std::shared_ptr<ecore::EOperation> m_sM_OpaqueExpressionEvaluation_Operation_initialize_EventOccurrence = nullptr;std::shared_ptr<ecore::EOperation> m_sM_OpaqueExpressionEvaluation_Operation_setParameterValue_ParameterValue = nullptr;

			friend class ValuesPackage;

			static bool isInited;
			static ValuesPackage* create();
			bool isInitialized = false;
 			bool isCreated = false;

			virtual void init(std::shared_ptr<ecore::EPackage> package);

		public:
			void createPackageContents(std::shared_ptr<ecore::EPackage> package);
			void initializePackageContents();

		private:
			void createSM_OpaqueExpressionEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);

			void initializeSM_OpaqueExpressionEvaluationContent();
			void initializePackageEDataTypes();



	};
}
#endif /* end of include guard: PSSM_SEMANTICS_VALUESPACKAGEIMPL_HPP */