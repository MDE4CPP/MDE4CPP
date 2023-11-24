//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSSM_SEMANTICS_VALUESPACKAGE_HPP
#define PSSM_SEMANTICS_VALUESPACKAGE_HPP

// namespace macro header include
#include "PSSM/PSSM.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EStringToStringMapEntry;
	class EAnnotation;
	class EClass;
	class EOperation;
	class EReference;
	class EGenericType;
	class EDataType;
	class EParameter;
}

namespace PSSM::Semantics::Values 
{
	class SM_OpaqueExpressionEvaluation;
}
 
namespace PSSM::Semantics::Values 
{
	/*!
	The Metamodel Package for the Values metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class PSSM_API ValuesPackage : virtual public ecore::EPackage 
	{
		private:    
			ValuesPackage(ValuesPackage const&) = delete;
			ValuesPackage& operator=(ValuesPackage const&) = delete;

		protected:
			ValuesPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			// Begin Class SM_OpaqueExpressionEvaluation
			//Class and Feature IDs 
			static const unsigned long SM_OPAQUEEXPRESSIONEVALUATION_CLASS = 657025669;
			static const unsigned int SM_OPAQUEEXPRESSIONEVALUATION_CLASS_FEATURE_COUNT = 2;
			static const unsigned int SM_OPAQUEEXPRESSIONEVALUATION_CLASS_OPERATION_COUNT = 4;
			
			static const unsigned long SM_OPAQUEEXPRESSIONEVALUATION_ATTRIBUTE_CONTEXT = 1573020565;
			static const unsigned long SM_OPAQUEEXPRESSIONEVALUATION_ATTRIBUTE_PARAMETERVALUES = 1622641028;
			
			static const unsigned long SM_OPAQUEEXPRESSIONEVALUATION_OPERATION_EXECUTEEXPRESSIONBEHAVIOR = 29673340;
			static const unsigned long SM_OPAQUEEXPRESSIONEVALUATION_OPERATION_GETPARAMETERVALUE_PARAMETER = 2350817834;
			static const unsigned long SM_OPAQUEEXPRESSIONEVALUATION_OPERATION_INITIALIZE_EVENTOCCURRENCE = 611236674;
			static const unsigned long SM_OPAQUEEXPRESSIONEVALUATION_OPERATION_SETPARAMETERVALUE_PARAMETERVALUE = 747603173;
			
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getSM_OpaqueExpressionEvaluation_Class() const = 0;
			
			
			virtual const std::shared_ptr<ecore::EReference>& getSM_OpaqueExpressionEvaluation_Attribute_context() const = 0;
			virtual const std::shared_ptr<ecore::EReference>& getSM_OpaqueExpressionEvaluation_Attribute_parameterValues() const = 0;
			
			virtual const std::shared_ptr<ecore::EOperation>& getSM_OpaqueExpressionEvaluation_Operation_executeExpressionBehavior() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getSM_OpaqueExpressionEvaluation_Operation_getParameterValue_Parameter() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getSM_OpaqueExpressionEvaluation_Operation_initialize_EventOccurrence() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getSM_OpaqueExpressionEvaluation_Operation_setParameterValue_ParameterValue() const = 0;
			
			// End Class SM_OpaqueExpressionEvaluation

			
			

			

			//Singleton Getter
			public:
				static std::shared_ptr<ValuesPackage> eInstance();
	};
}
#endif /* end of include guard: PSSM_SEMANTICS_VALUESPACKAGE_HPP */
