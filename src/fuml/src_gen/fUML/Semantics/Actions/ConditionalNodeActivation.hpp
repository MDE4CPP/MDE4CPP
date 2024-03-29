//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_CONDITIONALNODEACTIVATION_HPP
#define FUML_SEMANTICS_ACTIONS_CONDITIONALNODEACTIVATION_HPP


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

namespace fUML
{
	class fUMLFactory;
}

//Forward Declaration for used types 
namespace fUML::Semantics::Actions 
{
	class ClauseActivation;
	class InputPinActivation;
	class OutputPinActivation;
	class PinActivation;
}
namespace fUML::Semantics::Activities 
{
	class ActivityEdgeInstance;
	class ActivityNodeActivationGroup;
	class Token;
}
namespace uml 
{
	class Action;
	class ActivityNode;
	class Clause;
}

// namespace macro header include
#include "fUML/fUML.hpp"

// base class includes
#include "fUML/Semantics/Actions/StructuredActivityNodeActivation.hpp"




//*********************************
namespace fUML::Semantics::Actions 
{
	
	class FUML_API ConditionalNodeActivation: virtual public StructuredActivityNodeActivation
	{
		public:
 			ConditionalNodeActivation(const ConditionalNodeActivation &) {}

		protected:
			ConditionalNodeActivation(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ConditionalNodeActivation() {}

			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<fUML::Semantics::Actions::ClauseActivation> getClauseActivation(std::shared_ptr<uml::Clause> clause) = 0;
			virtual void runTest(std::shared_ptr<uml::Clause> clause) = 0;
			virtual void selectBody(std::shared_ptr<uml::Clause> clause) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<Bag<fUML::Semantics::Actions::ClauseActivation>> getClauseActivations() const = 0;
			virtual std::shared_ptr<Bag<uml::Clause>> getSelectedClauses() const = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
			virtual std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> getPinActivation() const = 0;

			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 

			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			//*********************************
			// Reference Members
			//*********************************
			mutable std::shared_ptr<Bag<fUML::Semantics::Actions::ClauseActivation>> m_clauseActivations;
			mutable std::shared_ptr<Bag<uml::Clause>> m_selectedClauses;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_CONDITIONALNODEACTIVATION_HPP */
