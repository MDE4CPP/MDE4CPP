//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_ACTIONSPACKAGEIMPL_HPP
#define PSCS_SEMANTICS_ACTIONSPACKAGEIMPL_HPP

#include "ecore/ecorePackage.hpp"
#include "ecore/impl/EPackageImpl.hpp"

#include "PSCS/Semantics/Actions/ActionsPackage.hpp" 


namespace PSCS::Semantics::Actions 
{
	class CS_AcceptCallActionActivation;
	class CS_AcceptEventActionActivation;
	class CS_AddStructuralFeatureValueActionActivation;
	class CS_CallOperationActionActivation;
	class CS_ClearStructuralFeatureActionActivation;
	class CS_ConstructStrategy;
	class CS_CreateLinkActionActivation;
	class CS_CreateObjectActionActivation;
	class CS_DefaultConstructStrategy;
	class CS_ReadExtentActionActivation;
	class CS_ReadSelfActionActivation;
	class CS_RemoveStructuralFeatureValueActionActivation;
	class CS_SendSignalActionActivation;}

namespace ecore
{
	class ecoreFactory;
}

namespace PSCS::Semantics::Actions
{
	class ActionsPackageImpl : public ecore::EPackageImpl ,virtual public ActionsPackage
	{
		private:    
			ActionsPackageImpl(ActionsPackageImpl const&) = delete;
			ActionsPackageImpl& operator=(ActionsPackageImpl const&) = delete;

		protected:
			ActionsPackageImpl();

		public:
			virtual ~ActionsPackageImpl();

			// Begin Class CS_AcceptCallActionActivation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_AcceptCallActionActivation_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_AcceptCallActionActivation_Operation_accept_EventOccurrence() const ;
			
			// End Class CS_AcceptCallActionActivation

			// Begin Class CS_AcceptEventActionActivation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_AcceptEventActionActivation_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_AcceptEventActionActivation_Operation_accept_EventOccurrence() const ;
			
			// End Class CS_AcceptEventActionActivation

			// Begin Class CS_AddStructuralFeatureValueActionActivation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_AddStructuralFeatureValueActionActivation_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_AddStructuralFeatureValueActionActivation_Operation_doAction() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_AddStructuralFeatureValueActionActivation_Operation_doActionDefault() const ;
			
			// End Class CS_AddStructuralFeatureValueActionActivation

			// Begin Class CS_CallOperationActionActivation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_CallOperationActionActivation_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_CallOperationActionActivation_Operation__isCreate_Operation() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_CallOperationActionActivation_Operation_doAction() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_CallOperationActionActivation_Operation_getCallExecution() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_CallOperationActionActivation_Operation_isCreate_Operation() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_CallOperationActionActivation_Operation_isOperationProvided_Port_Operation() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_CallOperationActionActivation_Operation_isOperationRequired_Port_Operation() const ;
			
			// End Class CS_CallOperationActionActivation

			// Begin Class CS_ClearStructuralFeatureActionActivation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_ClearStructuralFeatureActionActivation_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_ClearStructuralFeatureActionActivation_Operation_doAction() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_ClearStructuralFeatureActionActivation_Operation_getLinksToDestroy_StructuredValue_StructuralFeature() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_ClearStructuralFeatureActionActivation_Operation_getPotentialLinkEnds_CS_Reference_StructuralFeature() const ;
			
			// End Class CS_ClearStructuralFeatureActionActivation

			// Begin Class CS_ConstructStrategy
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_ConstructStrategy_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_ConstructStrategy_Operation_construct_Operation_CS_Object() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_ConstructStrategy_Operation_getName() const ;
			
			// End Class CS_ConstructStrategy

			// Begin Class CS_CreateLinkActionActivation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_CreateLinkActionActivation_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_CreateLinkActionActivation_Operation_doAction() const ;
			
			// End Class CS_CreateLinkActionActivation

			// Begin Class CS_CreateObjectActionActivation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_CreateObjectActionActivation_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_CreateObjectActionActivation_Operation_doAction() const ;
			
			// End Class CS_CreateObjectActionActivation

			// Begin Class CS_DefaultConstructStrategy
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_DefaultConstructStrategy_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getCS_DefaultConstructStrategy_Attribute_defaultAssociation() const ;
			virtual std::shared_ptr<ecore::EReference> getCS_DefaultConstructStrategy_Attribute_generatedRealizingClasses() const ;
			virtual std::shared_ptr<ecore::EReference> getCS_DefaultConstructStrategy_Attribute_locus() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getCS_DefaultConstructStrategy_Operation_addStructuralFeatureValue_CS_Reference_Value() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_DefaultConstructStrategy_Operation_canInstantiate_Property() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_DefaultConstructStrategy_Operation_construct_Operation_CS_Object() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_DefaultConstructStrategy_Operation_constructObject_CS_Object_Class() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_DefaultConstructStrategy_Operation_generateArrayPattern_CS_Reference_Connector() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_DefaultConstructStrategy_Operation_generateRealizingClass_Interface_EString() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_DefaultConstructStrategy_Operation_generateStarPattern_CS_Reference_Connector() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_DefaultConstructStrategy_Operation_getCardinality_ConnectorEnd() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_DefaultConstructStrategy_Operation_getDefaultAssociation() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_DefaultConstructStrategy_Operation_getRealizingClass_Interface() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_DefaultConstructStrategy_Operation_getValuesFromConnectorEnd_CS_Reference_ConnectorEnd() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_DefaultConstructStrategy_Operation_instantiateInterface_Interface_Locus() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_DefaultConstructStrategy_Operation_isArrayPattern_Connector() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_DefaultConstructStrategy_Operation_isStarPattern_Connector() const ;
			
			// End Class CS_DefaultConstructStrategy

			// Begin Class CS_ReadExtentActionActivation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_ReadExtentActionActivation_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_ReadExtentActionActivation_Operation_doAction() const ;
			
			// End Class CS_ReadExtentActionActivation

			// Begin Class CS_ReadSelfActionActivation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_ReadSelfActionActivation_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_ReadSelfActionActivation_Operation_doAction() const ;
			
			// End Class CS_ReadSelfActionActivation

			// Begin Class CS_RemoveStructuralFeatureValueActionActivation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_RemoveStructuralFeatureValueActionActivation_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_RemoveStructuralFeatureValueActionActivation_Operation_doAction() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_StructuredValue_Value() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_RemoveStructuralFeatureValueActionActivation_Operation_getPotentialLinkEnds_CS_Reference_StructuralFeature() const ;
			
			// End Class CS_RemoveStructuralFeatureValueActionActivation

			// Begin Class CS_SendSignalActionActivation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_SendSignalActionActivation_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_SendSignalActionActivation_Operation_doAction() const ;
			
			// End Class CS_SendSignalActionActivation

			
			// SubPackages Getters
			

		private:
			std::shared_ptr<ecore::EClass> m_cS_AcceptCallActionActivation_Class = nullptr;std::shared_ptr<ecore::EClass> m_cS_AcceptEventActionActivation_Class = nullptr;std::shared_ptr<ecore::EClass> m_cS_AddStructuralFeatureValueActionActivation_Class = nullptr;std::shared_ptr<ecore::EClass> m_cS_CallOperationActionActivation_Class = nullptr;std::shared_ptr<ecore::EClass> m_cS_ClearStructuralFeatureActionActivation_Class = nullptr;std::shared_ptr<ecore::EClass> m_cS_ConstructStrategy_Class = nullptr;std::shared_ptr<ecore::EClass> m_cS_CreateLinkActionActivation_Class = nullptr;std::shared_ptr<ecore::EClass> m_cS_CreateObjectActionActivation_Class = nullptr;std::shared_ptr<ecore::EClass> m_cS_DefaultConstructStrategy_Class = nullptr;std::shared_ptr<ecore::EClass> m_cS_ReadExtentActionActivation_Class = nullptr;std::shared_ptr<ecore::EClass> m_cS_ReadSelfActionActivation_Class = nullptr;std::shared_ptr<ecore::EClass> m_cS_RemoveStructuralFeatureValueActionActivation_Class = nullptr;std::shared_ptr<ecore::EClass> m_cS_SendSignalActionActivation_Class = nullptr;
			
			
			std::shared_ptr<ecore::EReference> m_cS_DefaultConstructStrategy_Attribute_defaultAssociation = nullptr;std::shared_ptr<ecore::EReference> m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses = nullptr;std::shared_ptr<ecore::EReference> m_cS_DefaultConstructStrategy_Attribute_locus = nullptr;
			std::shared_ptr<ecore::EOperation> m_cS_CallOperationActionActivation_Operation__isCreate_Operation = nullptr;std::shared_ptr<ecore::EOperation> m_cS_AcceptCallActionActivation_Operation_accept_EventOccurrence = nullptr;std::shared_ptr<ecore::EOperation> m_cS_AcceptEventActionActivation_Operation_accept_EventOccurrence = nullptr;std::shared_ptr<ecore::EOperation> m_cS_DefaultConstructStrategy_Operation_addStructuralFeatureValue_CS_Reference_Value = nullptr;std::shared_ptr<ecore::EOperation> m_cS_DefaultConstructStrategy_Operation_canInstantiate_Property = nullptr;std::shared_ptr<ecore::EOperation> m_cS_ConstructStrategy_Operation_construct_Operation_CS_Object = nullptr;std::shared_ptr<ecore::EOperation> m_cS_DefaultConstructStrategy_Operation_construct_Operation_CS_Object = nullptr;std::shared_ptr<ecore::EOperation> m_cS_DefaultConstructStrategy_Operation_constructObject_CS_Object_Class = nullptr;std::shared_ptr<ecore::EOperation> m_cS_ReadExtentActionActivation_Operation_doAction = nullptr;std::shared_ptr<ecore::EOperation> m_cS_AddStructuralFeatureValueActionActivation_Operation_doAction = nullptr;std::shared_ptr<ecore::EOperation> m_cS_ReadSelfActionActivation_Operation_doAction = nullptr;std::shared_ptr<ecore::EOperation> m_cS_RemoveStructuralFeatureValueActionActivation_Operation_doAction = nullptr;std::shared_ptr<ecore::EOperation> m_cS_ClearStructuralFeatureActionActivation_Operation_doAction = nullptr;std::shared_ptr<ecore::EOperation> m_cS_CreateLinkActionActivation_Operation_doAction = nullptr;std::shared_ptr<ecore::EOperation> m_cS_CreateObjectActionActivation_Operation_doAction = nullptr;std::shared_ptr<ecore::EOperation> m_cS_CallOperationActionActivation_Operation_doAction = nullptr;std::shared_ptr<ecore::EOperation> m_cS_SendSignalActionActivation_Operation_doAction = nullptr;std::shared_ptr<ecore::EOperation> m_cS_AddStructuralFeatureValueActionActivation_Operation_doActionDefault = nullptr;std::shared_ptr<ecore::EOperation> m_cS_DefaultConstructStrategy_Operation_generateArrayPattern_CS_Reference_Connector = nullptr;std::shared_ptr<ecore::EOperation> m_cS_DefaultConstructStrategy_Operation_generateRealizingClass_Interface_EString = nullptr;std::shared_ptr<ecore::EOperation> m_cS_DefaultConstructStrategy_Operation_generateStarPattern_CS_Reference_Connector = nullptr;std::shared_ptr<ecore::EOperation> m_cS_CallOperationActionActivation_Operation_getCallExecution = nullptr;std::shared_ptr<ecore::EOperation> m_cS_DefaultConstructStrategy_Operation_getCardinality_ConnectorEnd = nullptr;std::shared_ptr<ecore::EOperation> m_cS_DefaultConstructStrategy_Operation_getDefaultAssociation = nullptr;std::shared_ptr<ecore::EOperation> m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_StructuredValue_Value = nullptr;std::shared_ptr<ecore::EOperation> m_cS_ClearStructuralFeatureActionActivation_Operation_getLinksToDestroy_StructuredValue_StructuralFeature = nullptr;std::shared_ptr<ecore::EOperation> m_cS_ConstructStrategy_Operation_getName = nullptr;std::shared_ptr<ecore::EOperation> m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getPotentialLinkEnds_CS_Reference_StructuralFeature = nullptr;std::shared_ptr<ecore::EOperation> m_cS_ClearStructuralFeatureActionActivation_Operation_getPotentialLinkEnds_CS_Reference_StructuralFeature = nullptr;std::shared_ptr<ecore::EOperation> m_cS_DefaultConstructStrategy_Operation_getRealizingClass_Interface = nullptr;std::shared_ptr<ecore::EOperation> m_cS_DefaultConstructStrategy_Operation_getValuesFromConnectorEnd_CS_Reference_ConnectorEnd = nullptr;std::shared_ptr<ecore::EOperation> m_cS_DefaultConstructStrategy_Operation_instantiateInterface_Interface_Locus = nullptr;std::shared_ptr<ecore::EOperation> m_cS_DefaultConstructStrategy_Operation_isArrayPattern_Connector = nullptr;std::shared_ptr<ecore::EOperation> m_cS_CallOperationActionActivation_Operation_isCreate_Operation = nullptr;std::shared_ptr<ecore::EOperation> m_cS_CallOperationActionActivation_Operation_isOperationProvided_Port_Operation = nullptr;std::shared_ptr<ecore::EOperation> m_cS_CallOperationActionActivation_Operation_isOperationRequired_Port_Operation = nullptr;std::shared_ptr<ecore::EOperation> m_cS_DefaultConstructStrategy_Operation_isStarPattern_Connector = nullptr;

			friend class ActionsPackage;

			static bool isInited;
			static ActionsPackage* create();
			bool isInitialized = false;
 			bool isCreated = false;

			virtual void init(std::shared_ptr<ecore::EPackage> package);

		public:
			void createPackageContents(std::shared_ptr<ecore::EPackage> package);
			void initializePackageContents();

		private:
			void createCS_AcceptCallActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createCS_AcceptEventActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createCS_AddStructuralFeatureValueActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createCS_CallOperationActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createCS_ClearStructuralFeatureActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createCS_ConstructStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createCS_CreateLinkActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createCS_CreateObjectActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createCS_DefaultConstructStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createCS_ReadExtentActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createCS_ReadSelfActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createCS_RemoveStructuralFeatureValueActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createCS_SendSignalActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);

			void initializeCS_AcceptCallActionActivationContent();
			void initializeCS_AcceptEventActionActivationContent();
			void initializeCS_AddStructuralFeatureValueActionActivationContent();
			void initializeCS_CallOperationActionActivationContent();
			void initializeCS_ClearStructuralFeatureActionActivationContent();
			void initializeCS_ConstructStrategyContent();
			void initializeCS_CreateLinkActionActivationContent();
			void initializeCS_CreateObjectActionActivationContent();
			void initializeCS_DefaultConstructStrategyContent();
			void initializeCS_ReadExtentActionActivationContent();
			void initializeCS_ReadSelfActionActivationContent();
			void initializeCS_RemoveStructuralFeatureValueActionActivationContent();
			void initializeCS_SendSignalActionActivationContent();
			void initializePackageEDataTypes();



	};
}
#endif /* end of include guard: PSCS_SEMANTICS_ACTIONSPACKAGEIMPL_HPP */
