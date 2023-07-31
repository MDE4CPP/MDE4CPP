//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_ACTIONS_CS_CLEARSTRUCTURALFEATUREACTIONACTIVATIONCS_CLEARSTRUCTURALFEATUREACTIONACTIVATIONIMPL_HPP
#define PSCS_SEMANTICS_ACTIONS_CS_CLEARSTRUCTURALFEATUREACTIONACTIVATIONCS_CLEARSTRUCTURALFEATUREACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "PSCS/PSCS.hpp" 

// model includes
#include "../CS_ClearStructuralFeatureActionActivation.hpp"

#include "PSCS/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/ClearStructuralFeatureActionActivationImpl.hpp"

//*********************************
namespace PSCS::Semantics::Actions 
{
	class PSCS_API CS_ClearStructuralFeatureActionActivationImpl : virtual public fUML::Semantics::Actions::ClearStructuralFeatureActionActivationImpl, virtual public CS_ClearStructuralFeatureActionActivation 
	{
		public: 
			CS_ClearStructuralFeatureActionActivationImpl(const CS_ClearStructuralFeatureActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			CS_ClearStructuralFeatureActionActivationImpl& operator=(CS_ClearStructuralFeatureActionActivationImpl const&); 

		protected:
			friend class PSCS::Semantics::Actions::ActionsFactoryImpl;
			CS_ClearStructuralFeatureActionActivationImpl();
			virtual std::shared_ptr<PSCS::Semantics::Actions::CS_ClearStructuralFeatureActionActivation> getThisCS_ClearStructuralFeatureActionActivationPtr() const;
			virtual void setThisCS_ClearStructuralFeatureActionActivationPtr(std::weak_ptr<PSCS::Semantics::Actions::CS_ClearStructuralFeatureActionActivation> thisCS_ClearStructuralFeatureActionActivationPtr);

			//Additional constructors for the containments back reference
			CS_ClearStructuralFeatureActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~CS_ClearStructuralFeatureActionActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual void doAction() ;
			virtual std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> getLinksToDestroy(const std::shared_ptr<fUML::Semantics::SimpleClassifiers::StructuredValue>& value, const std::shared_ptr<uml::StructuralFeature>& feature) ;
			virtual std::shared_ptr<Bag<fUML::Semantics::Values::Value>> getPotentialLinkEnds(const std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference>& context, const std::shared_ptr<uml::StructuralFeature>& feature) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			
			//*********************************
			// Union Reference Getters
			//*********************************
			virtual std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> getPinActivation() const ;
			
			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;

		protected:
			virtual const std::shared_ptr<ecore::EClass>& eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, const Any& newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments) ;

		private:
			std::weak_ptr<PSCS::Semantics::Actions::CS_ClearStructuralFeatureActionActivation> m_thisCS_ClearStructuralFeatureActionActivationPtr;
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_ACTIONS_CS_CLEARSTRUCTURALFEATUREACTIONACTIVATIONCS_CLEARSTRUCTURALFEATUREACTIONACTIVATIONIMPL_HPP */
