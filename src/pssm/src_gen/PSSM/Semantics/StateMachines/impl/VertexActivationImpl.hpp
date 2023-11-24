//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSSM_SEMANTICS_STATEMACHINES_VERTEXACTIVATIONVERTEXACTIVATIONIMPL_HPP
#define PSSM_SEMANTICS_STATEMACHINES_VERTEXACTIVATIONVERTEXACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "PSSM/PSSM.hpp" 

// model includes
#include "../VertexActivation.hpp"

#include "PSSM/Semantics/StateMachines/impl/StateMachinesFactoryImpl.hpp"
#include "PSSM/Semantics/StateMachines/impl/StateMachineSemanticVisitorImpl.hpp"

//*********************************
namespace PSSM::Semantics::StateMachines 
{
	class PSSM_API VertexActivationImpl : virtual public StateMachineSemanticVisitorImpl, virtual public VertexActivation 
	{
		public: 
			VertexActivationImpl(const VertexActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			VertexActivationImpl& operator=(VertexActivationImpl const&); 

		protected:
			friend class PSSM::Semantics::StateMachines::StateMachinesFactoryImpl;
			VertexActivationImpl();
			virtual std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation> getThisVertexActivationPtr() const;
			virtual void setThisVertexActivationPtr(std::weak_ptr<PSSM::Semantics::StateMachines::VertexActivation> thisVertexActivationPtr);


		public:
			//destructor
			virtual ~VertexActivationImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			virtual void addIncomingTransition(const std::shared_ptr<PSSM::Semantics::StateMachines::TransitionActivation>& transitionActivation) ;
			virtual void addOutgoingTransition(const std::shared_ptr<PSSM::Semantics::StateMachines::TransitionActivation>& transitionActivation) ;
			virtual bool canPropagateExecution(const std::shared_ptr<PSSM::Semantics::StateMachines::TransitionActivation>& enteringTransition, const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence, const std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation>& leastCommonAncestor) ;
			virtual void enter(const std::shared_ptr<PSSM::Semantics::StateMachines::TransitionActivation>& enteringTransition, const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence, const std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation>& leastCommonAncestor) ;
			virtual void exit(const std::shared_ptr<PSSM::Semantics::StateMachines::TransitionActivation>& exitingTransition, const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence, const std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation>& leastCommonAncestor) ;
			virtual std::shared_ptr<Bag<PSSM::Semantics::StateMachines::VertexActivation>> getAscendingHierarchy() ;
			virtual std::shared_ptr<Bag<PSSM::Semantics::StateMachines::TransitionActivation>> getIncomingTransitions() ;
			virtual std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation> getLeastCommonAncestor(const std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation>& vertexActivation) ;
			virtual std::shared_ptr<Bag<PSSM::Semantics::StateMachines::TransitionActivation>> getOutgoingTransitions() ;
			virtual std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation> getOwningRegionActivation() ;
			virtual std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation> getParentVertexActivation() ;
			virtual std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation> getRegionActivation(const std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor>& semanticVisitor) ;
			
			virtual std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation> getVertexActivation(const std::shared_ptr<uml::Vertex>& vertex) ;
			virtual bool isActive() ;
			virtual bool isEnterable(const std::shared_ptr<PSSM::Semantics::StateMachines::TransitionActivation>& enteringTransition, bool staticCheck) ;
			virtual bool isExitable(const std::shared_ptr<PSSM::Semantics::StateMachines::TransitionActivation>& exitingTransition, bool staticCheck) ;
			
			virtual void tagIncomingTransition(PSSM::Semantics::StateMachines::TransitionMetadata status, bool staticCheck) ;
			virtual void tagOutgoingTransition(PSSM::Semantics::StateMachines::TransitionMetadata status, bool staticCheck) ;
			virtual void terminate() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual PSSM::Semantics::StateMachines::StateMetadata getStatus() const ;
			virtual void setStatus (PSSM::Semantics::StateMachines::StateMetadata _status);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<Bag<PSSM::Semantics::StateMachines::TransitionActivation>>& getIncomingTransitionActivations() const ;
			virtual const std::shared_ptr<Bag<PSSM::Semantics::StateMachines::TransitionActivation>>& getOutgoingTransitionActivations() const ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			
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
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;

		protected:
			virtual const std::shared_ptr<ecore::EClass>& eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual std::shared_ptr<Any> eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, const std::shared_ptr<Any>& newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID,const std::shared_ptr<Bag<Any>>& arguments) ;

		private:
			std::weak_ptr<PSSM::Semantics::StateMachines::VertexActivation> m_thisVertexActivationPtr;
	};
}
#endif /* end of include guard: PSSM_SEMANTICS_STATEMACHINES_VERTEXACTIVATIONVERTEXACTIVATIONIMPL_HPP */
