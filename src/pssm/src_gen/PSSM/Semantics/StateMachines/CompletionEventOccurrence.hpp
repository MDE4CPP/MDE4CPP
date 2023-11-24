//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSSM_SEMANTICS_STATEMACHINES_COMPLETIONEVENTOCCURRENCE_HPP
#define PSSM_SEMANTICS_STATEMACHINES_COMPLETIONEVENTOCCURRENCE_HPP


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
namespace PSSM::Semantics::StateMachines 
{
	class StateActivation;
}
namespace uml 
{
	class Element;
	class Trigger;
}

// namespace macro header include
#include "PSSM/PSSM.hpp"

// base class includes
#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"




//*********************************
namespace PSSM::Semantics::StateMachines 
{
	
	class PSSM_API CompletionEventOccurrence : virtual public fUML::Semantics::CommonBehavior::EventOccurrence
	{
		public:
 			CompletionEventOccurrence(const CompletionEventOccurrence &) {}

		protected:
			CompletionEventOccurrence(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~CompletionEventOccurrence() {}

			//*********************************
			// Operations
			//*********************************
			virtual void _register(const std::shared_ptr<PSSM::Semantics::StateMachines::StateActivation>& stateActivation) = 0;
			virtual bool match(const std::shared_ptr<uml::Trigger>& trigger) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<PSSM::Semantics::StateMachines::StateActivation>& getStateActivation() const = 0;
			virtual void setStateActivation(const std::shared_ptr<PSSM::Semantics::StateMachines::StateActivation>&) = 0;

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
			std::shared_ptr<PSSM::Semantics::StateMachines::StateActivation> m_stateActivation;
	};
}
#endif /* end of include guard: PSSM_SEMANTICS_STATEMACHINES_COMPLETIONEVENTOCCURRENCE_HPP */
