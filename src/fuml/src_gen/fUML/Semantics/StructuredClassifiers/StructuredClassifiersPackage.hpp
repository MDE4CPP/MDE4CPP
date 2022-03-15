//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_STRUCTUREDCLASSIFIERSPACKAGE_HPP
#define FUML_SEMANTICS_STRUCTUREDCLASSIFIERSPACKAGE_HPP

// namespace macro header include
#include "fUML/fUML.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EParameter;
	class EDataType;
	class EStringToStringMapEntry;
	class EGenericType;
	class EReference;
	class EOperation;
	class EAnnotation;
	class EClass;
}

namespace fUML::Semantics::StructuredClassifiers 
{
	class DispatchStrategy;
	class RedefinitionBasedDispatchStrategy;
}
 
namespace fUML::Semantics::StructuredClassifiers 
{
	/*!
	The Metamodel Package for the StructuredClassifiers metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class FUML_API StructuredClassifiersPackage : virtual public ecore::EPackage 
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

			// Begin Class DispatchStrategy
			//Class and Feature IDs 
			static const unsigned long DISPATCHSTRATEGY_CLASS = 1413517210;
			static const unsigned int DISPATCHSTRATEGY_CLASS_FEATURE_COUNT = 0;
			static const unsigned int DISPATCHSTRATEGY_CLASS_OPERATION_COUNT = 4;
			
			
			static const unsigned int DISPATCHSTRATEGY_OPERATION_DISPATCH_ELEMENT_OPERATION = 2531361209;
			static const unsigned int DISPATCHSTRATEGY_OPERATION_GETNAME = 1474882685;
			static const unsigned int DISPATCHSTRATEGY_OPERATION_RETRIEVEMETHOD_ELEMENT_OPERATION = 2607212722;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getDispatchStrategy_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getDispatchStrategy_Operation_dispatch_Element_Operation() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getDispatchStrategy_Operation_getName() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getDispatchStrategy_Operation_retrieveMethod_Element_Operation() const = 0;
			
			// End Class DispatchStrategy


			// Begin Class RedefinitionBasedDispatchStrategy
			//Class and Feature IDs 
			static const unsigned long REDEFINITIONBASEDDISPATCHSTRATEGY_CLASS = 784625732;
			static const unsigned int REDEFINITIONBASEDDISPATCHSTRATEGY_CLASS_FEATURE_COUNT = 0;
			static const unsigned int REDEFINITIONBASEDDISPATCHSTRATEGY_CLASS_OPERATION_COUNT = 6;
			
			
			static const unsigned int REDEFINITIONBASEDDISPATCHSTRATEGY_OPERATION_OPERATIONSMATCH_OPERATION_OPERATION = 3748574732;
			static const unsigned int REDEFINITIONBASEDDISPATCHSTRATEGY_OPERATION_RETRIEVEMETHOD_ELEMENT_OPERATION = 4193381461;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getRedefinitionBasedDispatchStrategy_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getRedefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getRedefinitionBasedDispatchStrategy_Operation_retrieveMethod_Element_Operation() const = 0;
			
			// End Class RedefinitionBasedDispatchStrategy

			
			

			

			//Singleton Instance and Getter
			private:
				static std::shared_ptr<StructuredClassifiersPackage> instance;
			public:
				static std::shared_ptr<StructuredClassifiersPackage> eInstance();
	};
}
#endif /* end of include guard: FUML_SEMANTICS_STRUCTUREDCLASSIFIERSPACKAGE_HPP */
