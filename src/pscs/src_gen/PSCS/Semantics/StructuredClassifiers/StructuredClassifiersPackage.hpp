//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_STRUCTUREDCLASSIFIERSPACKAGE_HPP
#define PSCS_SEMANTICS_STRUCTUREDCLASSIFIERSPACKAGE_HPP

// namespace macro header include
#include "PSCS/PSCS.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EClass;
	class EAnnotation;
	class EEnum;
	class EGenericType;
	class EEnumLiteral;
	class EStringToStringMapEntry;
	class EOperation;
	class EReference;
	class EDataType;
	class EParameter;
}

namespace PSCS::Semantics::StructuredClassifiers 
{
	class CS_DefaultRequestPropagationStrategy;
	class CS_DispatchOperationOfInterfaceStrategy;
	class CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy;
	class CS_RequestPropagationStrategy;
	class CS_StructuralFeatureOfInterfaceAccessStrategy;
}
 
namespace PSCS::Semantics::StructuredClassifiers 
{
	/*!
	The Metamodel Package for the StructuredClassifiers metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class PSCS_API StructuredClassifiersPackage : virtual public ecore::EPackage 
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

			// Begin Class CS_DefaultRequestPropagationStrategy
			//Class and Feature IDs 
			static const unsigned long CS_DEFAULTREQUESTPROPAGATIONSTRATEGY_CLASS = 114292004;
			static const unsigned int CS_DEFAULTREQUESTPROPAGATIONSTRATEGY_CLASS_FEATURE_COUNT = 0;
			static const unsigned int CS_DEFAULTREQUESTPROPAGATIONSTRATEGY_CLASS_OPERATION_COUNT = 2;
			
			
			
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getCS_DefaultRequestPropagationStrategy_Class() const = 0;
			
			
			
			
			// End Class CS_DefaultRequestPropagationStrategy


			// Begin Class CS_DispatchOperationOfInterfaceStrategy
			//Class and Feature IDs 
			static const unsigned long CS_DISPATCHOPERATIONOFINTERFACESTRATEGY_CLASS = 732334652;
			static const unsigned int CS_DISPATCHOPERATIONOFINTERFACESTRATEGY_CLASS_FEATURE_COUNT = 0;
			static const unsigned int CS_DISPATCHOPERATIONOFINTERFACESTRATEGY_CLASS_OPERATION_COUNT = 6;
			
			
			
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getCS_DispatchOperationOfInterfaceStrategy_Class() const = 0;
			
			
			
			
			// End Class CS_DispatchOperationOfInterfaceStrategy


			// Begin Class CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy
			//Class and Feature IDs 
			static const unsigned long CS_NAMEBASED_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_CLASS = 1596515744;
			static const unsigned int CS_NAMEBASED_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_CLASS_FEATURE_COUNT = 0;
			static const unsigned int CS_NAMEBASED_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_CLASS_OPERATION_COUNT = 2;
			
			
			
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getCS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Class() const = 0;
			
			
			
			
			// End Class CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy


			// Begin Class CS_RequestPropagationStrategy
			//Class and Feature IDs 
			static const unsigned long CS_REQUESTPROPAGATIONSTRATEGY_CLASS = 1044958815;
			static const unsigned int CS_REQUESTPROPAGATIONSTRATEGY_CLASS_FEATURE_COUNT = 0;
			static const unsigned int CS_REQUESTPROPAGATIONSTRATEGY_CLASS_OPERATION_COUNT = 2;
			
			
			static const unsigned long CS_REQUESTPROPAGATIONSTRATEGY_OPERATION_GETNAME = 2901676164;
			
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getCS_RequestPropagationStrategy_Class() const = 0;
			
			
			
			virtual const std::shared_ptr<ecore::EOperation>& getCS_RequestPropagationStrategy_Operation_getName() const = 0;
			
			// End Class CS_RequestPropagationStrategy


			// Begin Class CS_StructuralFeatureOfInterfaceAccessStrategy
			//Class and Feature IDs 
			static const unsigned long CS_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_CLASS = 1746875136;
			static const unsigned int CS_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_CLASS_FEATURE_COUNT = 0;
			static const unsigned int CS_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_CLASS_OPERATION_COUNT = 2;
			
			
			static const unsigned long CS_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_OPERATION_GETNAME = 2308162148;
			
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getCS_StructuralFeatureOfInterfaceAccessStrategy_Class() const = 0;
			
			
			
			virtual const std::shared_ptr<ecore::EOperation>& getCS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName() const = 0;
			
			// End Class CS_StructuralFeatureOfInterfaceAccessStrategy

			static const int CS_LINKKIND_CLASS = 19;
			
			virtual const std::shared_ptr<ecore::EEnum>& getCS_LinkKind_Class() const = 0;
			

			

			//Singleton Getter
			public:
				static std::shared_ptr<StructuredClassifiersPackage> eInstance();
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_STRUCTUREDCLASSIFIERSPACKAGE_HPP */
