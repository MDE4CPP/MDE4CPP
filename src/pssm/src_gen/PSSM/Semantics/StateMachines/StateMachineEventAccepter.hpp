//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSSM_SEMANTICS_STATEMACHINES_STATEMACHINEEVENTACCEPTER_HPP
#define PSSM_SEMANTICS_STATEMACHINES_STATEMACHINEEVENTACCEPTER_HPP


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
	class StateConfiguration;
	class StateMachineExecution;
	class TransitionActivation;
}

// namespace macro header include
#include "PSSM/PSSM.hpp"

// base class includes
#include "fUML/Semantics/CommonBehavior/EventAccepter.hpp"




//*********************************
namespace PSSM::Semantics::StateMachines 
{
	
	class PSSM_API StateMachineEventAccepter : virtual public fUML::Semantics::CommonBehavior::EventAccepter
	{
		public:
 			StateMachineEventAccepter(const StateMachineEventAccepter &) {}

		protected:
			StateMachineEventAccepter(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~StateMachineEventAccepter() {}

			//*********************************
			// Operations
			//*********************************
			virtual bool _defer(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence, const std::shared_ptr<PSSM::Semantics::StateMachines::StateConfiguration>& stateConfiguration) = 0;
			virtual bool _isDeferred(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence, const std::shared_ptr<PSSM::Semantics::StateMachines::StateConfiguration>& stateConfiguration) = 0;
			virtual std::shared_ptr<Bag<PSSM::Semantics::StateMachines::TransitionActivation>> _select(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence, const std::shared_ptr<PSSM::Semantics::StateMachines::StateConfiguration>& stateConfiguration) = 0;
			virtual void accept(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence) = 0;
			virtual bool defer(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence) = 0;
			virtual bool isDeferred(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence) = 0;
			virtual bool isTriggering(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence) = 0;
			virtual bool match(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence) = 0;
			virtual std::shared_ptr<Bag<PSSM::Semantics::StateMachines::TransitionActivation>> select(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineExecution>& getRegistrationContext() const = 0;
			virtual void setRegistrationContext(const std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineExecution>&) = 0;

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
			
			//*********************************
			// Reference Members
			//*********************************
			std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineExecution> m_registrationContext;
	};
}
#endif /* end of include guard: PSSM_SEMANTICS_STATEMACHINES_STATEMACHINEEVENTACCEPTER_HPP */
