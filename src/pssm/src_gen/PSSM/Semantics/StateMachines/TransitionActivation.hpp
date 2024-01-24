//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSSM_SEMANTICS_STATEMACHINES_TRANSITIONACTIVATION_HPP
#define PSSM_SEMANTICS_STATEMACHINES_TRANSITIONACTIVATION_HPP


#include <memory>
#include <string>
// forward declarations


//*********************************
// generated Includes
#include <map> // used for Persistence
#include <vector> // used for Persistence
namespace persistence
{
	namespace interfaces
	{
		class XLoadHandler; // used for Persistence
		class XSaveHandler; // used for Persistence
	}
}

namespace PSSM
{
	class PSSMFactory;
}

//Forward Declaration for used types 
namespace fUML::Semantics::CommonBehavior 
{
	class EventOccurrence;
}
namespace PSSM::Semantics::StateMachines 
{
	class RegionActivation;
	class VertexActivation;
}
namespace uml 
{
	class NamedElement;
}

// namespace macro header include
#include "PSSM/PSSM.hpp"

// base class includes
#include "PSSM/Semantics/StateMachines/StateMachineSemanticVisitor.hpp"

// enum includes
#include "PSSM/Semantics/StateMachines/TransitionMetadata.hpp"



//*********************************
namespace PSSM::Semantics::StateMachines 
{
	
	class PSSM_API TransitionActivation : virtual public StateMachineSemanticVisitor
	{
		public:
 			TransitionActivation(const TransitionActivation &) {}

		protected:
			TransitionActivation(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~TransitionActivation() {}

			//*********************************
			// Operations
			//*********************************
			virtual bool canFireOn(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence) = 0;
			virtual bool canPropagateExecution(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence) = 0;
			virtual void enterTarget(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence) = 0;
			virtual bool evaluateGuard(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence) = 0;
			virtual void exitSource(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence) = 0;
			virtual void fire(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence) = 0;
			
			virtual std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation> getSourceActivation() = 0;
			
			virtual std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation> getTargetActivation() = 0;
			virtual bool hasTrigger(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence) = 0;
			virtual bool isGuarded() = 0;
			virtual bool isReached() = 0;
			virtual bool isTraversed(bool staticCheck) = 0;
			virtual bool isTriggered(bool staticCheck) = 0;
			virtual void setSourceActivation(const std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation>& sourceActivation) = 0;
			
			virtual void setTargetActivation(const std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation>& targetActivation) = 0;
			virtual void tryExecuteEffect(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual PSSM::Semantics::StateMachines::TransitionMetadata getAnalyticalStatus() const = 0;
			virtual void setAnalyticalStatus (PSSM::Semantics::StateMachines::TransitionMetadata _analyticalStatus)= 0;
			virtual bool getLastPropagation() const = 0;
			virtual void setLastPropagation (bool _lastPropagation)= 0;
			virtual PSSM::Semantics::StateMachines::TransitionMetadata getStatus() const = 0;
			virtual void setStatus (PSSM::Semantics::StateMachines::TransitionMetadata _status)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& getLastTriggeringEventOccurrence() const = 0;
			virtual void setLastTriggeringEventOccurrence(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>&) = 0;
			virtual const std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation>& getLeastCommonAncestor() const = 0;
			virtual void setLeastCommonAncestor(const std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation>&) = 0;
			virtual const std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation>& getSourceVertexActivation() const = 0;
			virtual void setSourceVertexActivation(const std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation>&) = 0;
			virtual const std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation>& getTargetVertexActivation() const = 0;
			virtual void setTargetVertexActivation(const std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation>&) = 0;

			//*********************************
			// Union Reference Getters
			//*********************************

			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 

			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			PSSM::Semantics::StateMachines::TransitionMetadata m_analyticalStatus= PSSM::Semantics::StateMachines::TransitionMetadata::NONE;
			bool m_lastPropagation= false;
			PSSM::Semantics::StateMachines::TransitionMetadata m_status= PSSM::Semantics::StateMachines::TransitionMetadata::NONE;
			
			//*********************************
			// Reference Members
			//*********************************
			std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> m_lastTriggeringEventOccurrence;
			std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation> m_leastCommonAncestor;
			std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation> m_sourceVertexActivation;
			std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation> m_targetVertexActivation;
	};
}
#endif /* end of include guard: PSSM_SEMANTICS_STATEMACHINES_TRANSITIONACTIVATION_HPP */