//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSSM_SEMANTICS_STRUCTUREDCLASSIFIERSPACKAGE_HPP
#define PSSM_SEMANTICS_STRUCTUREDCLASSIFIERSPACKAGE_HPP

// namespace macro header include
#include "PSSM/PSSM.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EAnnotation;
	class EClass;
	class EOperation;
	class EParameter;
	class EStringToStringMapEntry;
	class EGenericType;
}

namespace PSSM::Semantics::StructuredClassifiers 
{
	class SM_RedefinitionBasedDispatchStrategy;
}
 
namespace PSSM::Semantics::StructuredClassifiers 
{
	/*!
	The Metamodel Package for the StructuredClassifiers metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class PSSM_API StructuredClassifiersPackage : virtual public ecore::EPackage 
	{
		private:    
			StructuredClassifiersPackage(StructuredClassifiersPackage const&) = delete;
			StructuredClassifiersPackage& operator=(StructuredClassifiersPackage const&) = delete;

		protected:
			StructuredClassifiersPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			// Begin Class SM_RedefinitionBasedDispatchStrategy
			//Class and Feature IDs 
			static const unsigned long SM_REDEFINITIONBASEDDISPATCHSTRATEGY_CLASS = 764701097;
			static const unsigned int SM_REDEFINITIONBASEDDISPATCHSTRATEGY_CLASS_FEATURE_COUNT = 0;
			static const unsigned int SM_REDEFINITIONBASEDDISPATCHSTRATEGY_CLASS_OPERATION_COUNT = 2;
			
			
			static const unsigned long SM_REDEFINITIONBASEDDISPATCHSTRATEGY_OPERATION_DISPATCH_FUML_OBJECT_OPERATION = 1964522576;
			static const unsigned long SM_REDEFINITIONBASEDDISPATCHSTRATEGY_OPERATION_GETMETHOD_FUML_OBJECT_OPERATION = 1643090071;
			
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getSM_RedefinitionBasedDispatchStrategy_Class() const = 0;
			
			
			
			virtual const std::shared_ptr<ecore::EOperation>& getSM_RedefinitionBasedDispatchStrategy_Operation_dispatch_FUML_Object_Operation() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getSM_RedefinitionBasedDispatchStrategy_Operation_getMethod_FUML_Object_Operation() const = 0;
			
			// End Class SM_RedefinitionBasedDispatchStrategy

			
			

			

			//Singleton Getter
			public:
				static std::shared_ptr<StructuredClassifiersPackage> eInstance();
	};
}
#endif /* end of include guard: PSSM_SEMANTICS_STRUCTUREDCLASSIFIERSPACKAGE_HPP */
