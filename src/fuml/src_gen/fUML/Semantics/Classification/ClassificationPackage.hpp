//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_CLASSIFICATIONPACKAGE_HPP
#define FUML_SEMANTICS_CLASSIFICATIONPACKAGE_HPP

// namespace macro header include
#include "fUML/fUML.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EOperation;
	class EAnnotation;
	class EClass;
	class EStringToStringMapEntry;
	class EGenericType;
}

namespace fUML::Semantics::Classification 
{
	class InstanceValueEvaluation;
}
 
namespace fUML::Semantics::Classification 
{
	/*!
	The Metamodel Package for the Classification metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class FUML_API ClassificationPackage : virtual public ecore::EPackage 
	{
		private:    
			ClassificationPackage(ClassificationPackage const&) = delete;
			ClassificationPackage& operator=(ClassificationPackage const&) = delete;

		protected:
			ClassificationPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			// Begin Class InstanceValueEvaluation
			//Class and Feature IDs 
			static const unsigned long INSTANCEVALUEEVALUATION_CLASS = 1738756913;
			static const unsigned int INSTANCEVALUEEVALUATION_CLASS_FEATURE_COUNT = 2;
			static const unsigned int INSTANCEVALUEEVALUATION_CLASS_OPERATION_COUNT = 4;
			
			
			static const unsigned int INSTANCEVALUEEVALUATION_OPERATION_EVALUATE = 2581799787;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getInstanceValueEvaluation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getInstanceValueEvaluation_Operation_evaluate() const = 0;
			
			// End Class InstanceValueEvaluation

			
			

			

			//Singleton Instance and Getter
			private:
				static std::shared_ptr<ClassificationPackage> instance;
			public:
				static std::shared_ptr<ClassificationPackage> eInstance();
	};
}
#endif /* end of include guard: FUML_SEMANTICS_CLASSIFICATIONPACKAGE_HPP */
