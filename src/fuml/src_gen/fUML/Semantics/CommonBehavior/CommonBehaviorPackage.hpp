//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_COMMONBEHAVIORPACKAGE_HPP
#define FUML_SEMANTICS_COMMONBEHAVIORPACKAGE_HPP

// namespace macro header include
#include "fUML/fUML.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EAttribute;
	class EReference;
	class EDataType;
	class EGenericType;
	class EStringToStringMapEntry;
	class EOperation;
	class EParameter;
	class EClass;
	class EAnnotation;
}

namespace fUML::Semantics::CommonBehavior 
{
	class Execution;
	class ParameterValue;
}
 
namespace fUML::Semantics::CommonBehavior 
{
	/*!
	The Metamodel Package for the CommonBehavior metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class FUML_API CommonBehaviorPackage : virtual public ecore::EPackage 
	{
		private:    
			CommonBehaviorPackage(CommonBehaviorPackage const&) = delete;
			CommonBehaviorPackage& operator=(CommonBehaviorPackage const&) = delete;

		protected:
			CommonBehaviorPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			// Begin Class Execution
			//Class and Feature IDs 
			static const unsigned long EXECUTION_CLASS = 921905715;
			static const unsigned int EXECUTION_CLASS_FEATURE_COUNT = 9;
			static const unsigned int EXECUTION_CLASS_OPERATION_COUNT = 47;
			
			static const unsigned long EXECUTION_ATTRIBUTE_BEHAVIOR = 106545659;
			static const unsigned long EXECUTION_ATTRIBUTE_CONTEXT = 646122967;
			static const unsigned long EXECUTION_ATTRIBUTE_LOCUS = 352953143;
			static const unsigned long EXECUTION_ATTRIBUTE_PARAMETERVALUES = 1718346120;
			static const unsigned long EXECUTION_ATTRIBUTE_TYPES = 1361902853;
			
			static const unsigned long EXECUTION_OPERATION__COPY = 4021493409;
			static const unsigned long EXECUTION_OPERATION_DESTROY = 2183551203;
			static const unsigned long EXECUTION_OPERATION_EXECUTE = 2717216448;
			static const unsigned long EXECUTION_OPERATION_GETOUTPUTPARAMETERVALUES = 3117320457;
			static const unsigned long EXECUTION_OPERATION_GETPARAMETERVALUE_PARAMETER = 972104598;
			static const unsigned long EXECUTION_OPERATION_NEW_ = 1530257024;
			static const unsigned long EXECUTION_OPERATION_SETPARAMETERVALUE_PARAMETERVALUE = 1714178337;
			static const unsigned long EXECUTION_OPERATION_TERMINATE = 1246638906;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getExecution_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getExecution_Attribute_behavior() const = 0;
			virtual std::shared_ptr<ecore::EReference> getExecution_Attribute_context() const = 0;
			virtual std::shared_ptr<ecore::EReference> getExecution_Attribute_locus() const = 0;
			virtual std::shared_ptr<ecore::EReference> getExecution_Attribute_parameterValues() const = 0;
			virtual std::shared_ptr<ecore::EReference> getExecution_Attribute_types() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getExecution_Operation__copy() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecution_Operation_destroy() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecution_Operation_execute() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecution_Operation_getOutputParameterValues() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecution_Operation_getParameterValue_Parameter() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecution_Operation_new_() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecution_Operation_setParameterValue_ParameterValue() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecution_Operation_terminate() const = 0;
			
			// End Class Execution


			// Begin Class ParameterValue
			//Class and Feature IDs 
			static const unsigned long PARAMETERVALUE_CLASS = 1804530160;
			static const unsigned int PARAMETERVALUE_CLASS_FEATURE_COUNT = 2;
			static const unsigned int PARAMETERVALUE_CLASS_OPERATION_COUNT = 1;
			static const unsigned long PARAMETERVALUE_ATTRIBUTE_VALUES = 937768762;
			
			static const unsigned long PARAMETERVALUE_ATTRIBUTE_PARAMETER = 1803315899;
			
			static const unsigned long PARAMETERVALUE_OPERATION__COPY = 2742640749;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getParameterValue_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getParameterValue_Attribute_values() const = 0;
			
			virtual std::shared_ptr<ecore::EReference> getParameterValue_Attribute_parameter() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getParameterValue_Operation__copy() const = 0;
			
			// End Class ParameterValue

			
			

			

			//Singleton Getter
			public:
				static std::shared_ptr<CommonBehaviorPackage> eInstance();
	};
}
#endif /* end of include guard: FUML_SEMANTICS_COMMONBEHAVIORPACKAGE_HPP */
