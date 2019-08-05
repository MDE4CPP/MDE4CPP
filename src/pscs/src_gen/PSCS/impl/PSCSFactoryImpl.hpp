//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCSFACTORYIMPL_HPP
#define PSCSFACTORYIMPL_HPP

#include "ecore/impl/EFactoryImpl.hpp"

#include "PSCS/PSCSFactory.hpp"

namespace PSCS 
{
}

namespace PSCS 
{
	class PSCSFactoryImpl : virtual public ecore::EFactoryImpl , virtual public PSCSFactory 
	{
		private:    
			PSCSFactoryImpl(PSCSFactoryImpl const&) = delete;
			PSCSFactoryImpl& operator=(PSCSFactoryImpl const&) = delete;

		protected:
			friend class PSCSFactory;
			// Constructor
			PSCSFactoryImpl();

		public:
			virtual ~PSCSFactoryImpl();
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const;

			//Creator functions
			virtual std::shared_ptr<PSCS::Semantics::Actions::CS_AcceptCallActionActivation> createCS_AcceptCallActionActivation(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<PSCS::Semantics::Actions::CS_AcceptEventActionActivation> createCS_AcceptEventActionActivation(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<PSCS::Semantics::Actions::CS_AddStructuralFeatureValueActionActivation> createCS_AddStructuralFeatureValueActionActivation(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_CallEventExecution> createCS_CallEventExecution(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<PSCS::Semantics::Actions::CS_CallOperationActionActivation> createCS_CallOperationActionActivation(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<PSCS::Semantics::Actions::CS_ClearStructuralFeatureActionActivation> createCS_ClearStructuralFeatureActionActivation(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<PSCS::Semantics::Actions::CS_CreateLinkActionActivation> createCS_CreateLinkActionActivation(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<PSCS::Semantics::Actions::CS_CreateObjectActionActivation> createCS_CreateObjectActionActivation(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<PSCS::Semantics::Actions::CS_DefaultConstructStrategy> createCS_DefaultConstructStrategy(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_DefaultRequestPropagationStrategy> createCS_DefaultRequestPropagationStrategy(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_DispatchOperationOfInterfaceStrategy> createCS_DispatchOperationOfInterfaceStrategy(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_EventOccurrence> createCS_EventOccurrence(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<PSCS::Semantics::Loci::CS_ExecutionFactory> createCS_ExecutionFactory(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<PSCS::Semantics::Loci::CS_Executor> createCS_Executor(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<PSCS::Semantics::Classification::CS_InstanceValueEvaluation> createCS_InstanceValueEvaluation(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> createCS_InteractionPoint(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> createCS_Link(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<PSCS::Semantics::Loci::CS_Locus> createCS_Locus(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy> createCS_NameBased_StructuralFeatureOfInterfaceAccessStrategy(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> createCS_Object(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<PSCS::Semantics::Values::CS_OpaqueExpressionEvaluation> createCS_OpaqueExpressionEvaluation(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<PSCS::Semantics::Actions::CS_ReadExtentActionActivation> createCS_ReadExtentActionActivation(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<PSCS::Semantics::Actions::CS_ReadSelfActionActivation> createCS_ReadSelfActionActivation(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> createCS_Reference(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<PSCS::Semantics::Actions::CS_RemoveStructuralFeatureValueActionActivation> createCS_RemoveStructuralFeatureValueActionActivation(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<PSCS::Semantics::Actions::CS_SendSignalActionActivation> createCS_SendSignalActionActivation(const int metaElementID=-1) const ;
			
			

			//Package
			virtual std::shared_ptr<PSCSPackage> getPSCSPackage() const;

		private:
			static PSCSFactory* create();
            std::map<std::string,int> m_idMap;
	};
}
#endif /* end of include guard: PSCSFACTORYIMPL_HPP */
