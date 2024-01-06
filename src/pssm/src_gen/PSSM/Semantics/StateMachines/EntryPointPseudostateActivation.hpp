//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSSM_SEMANTICS_STATEMACHINES_ENTRYPOINTPSEUDOSTATEACTIVATION_HPP
#define PSSM_SEMANTICS_STATEMACHINES_ENTRYPOINTPSEUDOSTATEACTIVATION_HPP


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
	class TransitionActivation;
}
namespace uml 
{
	class NamedElement;
}

// namespace macro header include
#include "PSSM/PSSM.hpp"

// base class includes
#include "PSSM/Semantics/StateMachines/ConnectionPointActivation.hpp"

// enum includes
#include "PSSM/Semantics/StateMachines/StateMetadata.hpp"



//*********************************
namespace PSSM::Semantics::StateMachines 
{
	
	class PSSM_API EntryPointPseudostateActivation : virtual public ConnectionPointActivation
	{
		public:
 			EntryPointPseudostateActivation(const EntryPointPseudostateActivation &) {}

		protected:
			EntryPointPseudostateActivation(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~EntryPointPseudostateActivation() {}

			//*********************************
			// Operations
			//*********************************
			virtual void _enter(const std::shared_ptr<PSSM::Semantics::StateMachines::TransitionActivation>& enteringTransition, const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence, const std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation>& leastCommonAncestor) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************

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
	};
}
#endif /* end of include guard: PSSM_SEMANTICS_STATEMACHINES_ENTRYPOINTPSEUDOSTATEACTIVATION_HPP */
