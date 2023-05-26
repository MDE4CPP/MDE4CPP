//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_EXPANSIONREGIONACTIVATION_HPP
#define FUML_SEMANTICS_ACTIONS_EXPANSIONREGIONACTIVATION_HPP


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
	class ExpansionActivationGroup;
	class ExpansionNodeActivation;
	class InputPinActivation;
	class OutputPinActivation;
	class PinActivation;
}
namespace fUML::Semantics::Activities 
{
	class ActivityEdgeInstance;
	class ActivityNodeActivationGroup;
	class Token;
	class TokenSet;
}
namespace uml 
{
	class Action;
	class ActivityNode;
	class ExpansionNode;
}

// namespace macro header include
#include "fUML/fUML.hpp"

// base class includes
#include "fUML/Semantics/Actions/ActionActivation.hpp"




//*********************************
namespace fUML::Semantics::Actions 
{
	
	class FUML_API ExpansionRegionActivation : virtual public ActionActivation
	{
		public:
 			ExpansionRegionActivation(const ExpansionRegionActivation &) {}

		protected:
			ExpansionRegionActivation(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ExpansionRegionActivation() {}

			//*********************************
			// Operations
			//*********************************
			virtual void doAction() = 0;
			virtual void doOutput() = 0;
			virtual void doStructuredActivity() = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::ExpansionNodeActivation> getExpansionNodeActivation(const std::shared_ptr<uml::ExpansionNode>& node) = 0;
			virtual bool isSuspended() = 0;
			virtual int numberOfValues() = 0;
			virtual void resume(const std::shared_ptr<fUML::Semantics::Actions::ExpansionActivationGroup>& activationGroup) = 0;
			virtual void runGroup(const std::shared_ptr<fUML::Semantics::Actions::ExpansionActivationGroup>& activationGroup) = 0;
			virtual void runIterative() = 0;
			virtual void runParallel() = 0;
			virtual void sendOffers() = 0;
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> takeOfferedTokens() = 0;
			virtual void terminate() = 0;
			virtual void terminateGroup(const std::shared_ptr<fUML::Semantics::Actions::ExpansionActivationGroup>& activationGroup) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual int getNext() const = 0;
			virtual void setNext (int _next)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<Bag<fUML::Semantics::Actions::ExpansionActivationGroup>>& getActivationGroups() const = 0;
			virtual const std::shared_ptr<Bag<fUML::Semantics::Activities::TokenSet>>& getInputExpansionTokens() const = 0;
			virtual const std::shared_ptr<Bag<fUML::Semantics::Activities::TokenSet>>& getInputTokens() const = 0;

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
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			int m_next= 0;
			
			//*********************************
			// Reference Members
			//*********************************
			mutable std::shared_ptr<Bag<fUML::Semantics::Actions::ExpansionActivationGroup>> m_activationGroups;
			mutable std::shared_ptr<Bag<fUML::Semantics::Activities::TokenSet>> m_inputExpansionTokens;
			mutable std::shared_ptr<Bag<fUML::Semantics::Activities::TokenSet>> m_inputTokens;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_EXPANSIONREGIONACTIVATION_HPP */
