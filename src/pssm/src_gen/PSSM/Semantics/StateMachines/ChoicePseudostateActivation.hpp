//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSSM_SEMANTICS_STATEMACHINES_CHOICEPSEUDOSTATEACTIVATION_HPP
#define PSSM_SEMANTICS_STATEMACHINES_CHOICEPSEUDOSTATEACTIVATION_HPP


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
	class TransitionActivation;
}
namespace uml 
{
	class NamedElement;
}

// namespace macro header include
#include "PSSM/PSSM.hpp"


// enum includes
#include "PSSM/Semantics/StateMachines/StateMetadata.hpp"

#include "ecore/EModelElement.hpp"


//*********************************
namespace PSSM::Semantics::StateMachines 
{
	
	class PSSM_API ChoicePseudostateActivation : virtual public ecore::EModelElement
	{
		public:
 			ChoicePseudostateActivation(const ChoicePseudostateActivation &) {}

		protected:
			ChoicePseudostateActivation(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ChoicePseudostateActivation() {}

			//*********************************
			// Operations
			//*********************************

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
#endif /* end of include guard: PSSM_SEMANTICS_STATEMACHINES_CHOICEPSEUDOSTATEACTIVATION_HPP */