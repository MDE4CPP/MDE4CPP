//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSSM_SEMANTICS_STATEMACHINES_TRANSITIONACTIVATIONTRANSITIONACTIVATIONIMPL_HPP
#define PSSM_SEMANTICS_STATEMACHINES_TRANSITIONACTIVATIONTRANSITIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "PSSM/PSSM.hpp" 

// model includes
#include "../TransitionActivation.hpp"

#include "PSSM/Semantics/StateMachines/impl/StateMachinesFactoryImpl.hpp"
#include "PSSM/Semantics/StateMachines/impl/StateMachineSemanticVisitorImpl.hpp"

//*********************************
namespace PSSM::Semantics::StateMachines 
{
	class PSSM_API TransitionActivationImpl : virtual public StateMachineSemanticVisitorImpl, virtual public TransitionActivation 
	{
		public: 
			TransitionActivationImpl(const TransitionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			TransitionActivationImpl& operator=(TransitionActivationImpl const&); 

		protected:
			friend class PSSM::Semantics::StateMachines::StateMachinesFactoryImpl;
			TransitionActivationImpl();
			virtual std::shared_ptr<PSSM::Semantics::StateMachines::TransitionActivation> getThisTransitionActivationPtr() const;
			virtual void setThisTransitionActivationPtr(std::weak_ptr<PSSM::Semantics::StateMachines::TransitionActivation> thisTransitionActivationPtr);


		public:
			//destructor
			virtual ~TransitionActivationImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			virtual bool canFireOn(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence) ;
			virtual bool canPropagateExecution(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence) ;
			virtual void enterTarget(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence) ;
			virtual bool evaluateGuard(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence) ;
			virtual void exitSource(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence) ;
			virtual void fire(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence) ;
			
			virtual std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation> getSourceActivation() ;
			
			virtual std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation> getTargetActivation() ;
			virtual bool hasTrigger(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence) ;
			virtual bool isGuarded() ;
			virtual bool isReached() ;
			virtual bool isTraversed(bool staticCheck) ;
			virtual bool isTriggered(bool staticCheck) ;
			virtual void setSourceActivation(const std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation>& sourceActivation) ;
			
			virtual void setTargetActivation(const std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation>& targetActivation) ;
			virtual void tryExecuteEffect(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual PSSM::Semantics::StateMachines::TransitionMetadata getAnalyticalStatus() const ;
			virtual void setAnalyticalStatus (PSSM::Semantics::StateMachines::TransitionMetadata _analyticalStatus);
			virtual bool getLastPropagation() const ;
			virtual void setLastPropagation (bool _lastPropagation);
			virtual PSSM::Semantics::StateMachines::TransitionMetadata getStatus() const ;
			virtual void setStatus (PSSM::Semantics::StateMachines::TransitionMetadata _status);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& getLastTriggeringEventOccurrence() const ;
			virtual void setLastTriggeringEventOccurrence(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>&) ;
			virtual const std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation>& getLeastCommonAncestor() const ;
			virtual void setLeastCommonAncestor(const std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation>&) ;
			virtual const std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation>& getSourceVertexActivation() const ;
			virtual void setSourceVertexActivation(const std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation>&) ;
			virtual const std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation>& getTargetVertexActivation() const ;
			virtual void setTargetVertexActivation(const std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation>&) ;
			
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
			std::weak_ptr<PSSM::Semantics::StateMachines::TransitionActivation> m_thisTransitionActivationPtr;
	};
}
#endif /* end of include guard: PSSM_SEMANTICS_STATEMACHINES_TRANSITIONACTIVATIONTRANSITIONACTIVATIONIMPL_HPP */