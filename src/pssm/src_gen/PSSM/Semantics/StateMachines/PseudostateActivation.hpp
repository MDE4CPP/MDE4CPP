//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSSM_SEMANTICS_STATEMACHINES_PSEUDOSTATEACTIVATION_HPP
#define PSSM_SEMANTICS_STATEMACHINES_PSEUDOSTATEACTIVATION_HPP


#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 


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
	class TransitionActivation;
}
namespace uml 
{
	class NamedElement;
}

// namespace macro header include
#include "PSSM/PSSM.hpp"

// base class includes
#include "PSSM/Semantics/StateMachines/VertexActivation.hpp"

// enum includes
#include "PSSM/Semantics/StateMachines/StateMetadata.hpp"



//*********************************
namespace PSSM::Semantics::StateMachines 
{
	
	class PSSM_API PseudostateActivation : virtual public VertexActivation
	{
		public:
 			PseudostateActivation(const PseudostateActivation &) {}

		protected:
			PseudostateActivation(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~PseudostateActivation() {}

			//*********************************
			// Operations
			//*********************************
			virtual void evaluateAllGuards(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<Bag<PSSM::Semantics::StateMachines::TransitionActivation>>& getFireableTransitions() const = 0;

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
			mutable std::shared_ptr<Bag<PSSM::Semantics::StateMachines::TransitionActivation>> m_fireableTransitions;
	};
}
#endif /* end of include guard: PSSM_SEMANTICS_STATEMACHINES_PSEUDOSTATEACTIVATION_HPP */