//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIES_DECISIONNODEACTIVATION_HPP
#define FUML_SEMANTICS_ACTIVITIES_DECISIONNODEACTIVATION_HPP


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
namespace fUML::Semantics::Activities 
{
	class ActivityEdgeInstance;
	class ActivityNodeActivationGroup;
	class Token;
}
namespace fUML::Semantics::CommonBehavior 
{
	class Execution;
}
namespace fUML::Semantics::Values 
{
	class Value;
}
namespace uml 
{
	class ActivityNode;
	class DecisionNode;
	class ValueSpecification;
}

// namespace macro header include
#include "fUML/fUML.hpp"

// base class includes
#include "fUML/Semantics/Activities/ControlNodeActivation.hpp"




//*********************************
namespace fUML::Semantics::Activities 
{
	
	class FUML_API DecisionNodeActivation: virtual public ControlNodeActivation
	{
		public:
 			DecisionNodeActivation(const DecisionNodeActivation &) {}

		protected:
			DecisionNodeActivation(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~DecisionNodeActivation() {}

			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<fUML::Semantics::Values::Value> executeDecisionInputBehavior(std::shared_ptr<fUML::Semantics::Values::Value> inputValue,std::shared_ptr<fUML::Semantics::Values::Value> decisionInputValue) = 0;
			virtual void fire(std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incomingTokens) = 0;
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> getDecisionInputFlowInstance() = 0;
			virtual std::shared_ptr<fUML::Semantics::Values::Value> getDecisionInputFlowValue() = 0;
			virtual std::shared_ptr<Bag<fUML::Semantics::Values::Value> > getDecisionValues(std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incomingTokens) = 0;
			virtual bool hasObjectFlowInput() = 0;
			virtual bool isReady() = 0;
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > removeJoinedControlTokens(std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incomingTokens) = 0;
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > takeOfferedTokens() = 0;
			virtual void terminate() = 0;
			virtual bool test(std::shared_ptr<uml::ValueSpecification> gaurd,std::shared_ptr<fUML::Semantics::Values::Value> value) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> getDecisionInputExecution() const = 0;
			virtual void setDecisionInputExecution(std::shared_ptr<fUML::Semantics::CommonBehavior::Execution>) = 0;
			virtual std::shared_ptr<uml::DecisionNode> getDecisionNode() const = 0;
			virtual void setDecisionNode(std::shared_ptr<uml::DecisionNode>) = 0;
			/*Additional Setter for 'ActivityNodeActivation::node' redefined by reference 'decisionNode'*/
			virtual void setNode(std::shared_ptr<uml::ActivityNode>) = 0;

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
			
			//*********************************
			// Reference Members
			//*********************************
			std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> m_decisionInputExecution;
			std::shared_ptr<uml::DecisionNode> m_decisionNode;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_DECISIONNODEACTIVATION_HPP */
