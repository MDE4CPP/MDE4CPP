//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_CALLACTIONACTIVATION_HPP
#define FUML_SEMANTICS_ACTIONS_CALLACTIONACTIVATION_HPP

#include <list>
#include <memory>
#include <string>


// forward declarations
template<class T> class Bag; 



//*********************************
// generated Includes

#include <map>

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
namespace uml 
{
	class Action;
}

namespace fUML::Semantics::Activities 
{
	class ActivityEdgeInstance;
}

namespace uml 
{
	class ActivityNode;
}

namespace fUML::Semantics::Activities 
{
	class ActivityNodeActivationGroup;
}

namespace uml 
{
	class CallAction;
}

namespace fUML::Semantics::CommonBehavior 
{
	class Execution;
}

namespace fUML::Semantics::Actions 
{
	class InputPinActivation;
}

namespace fUML::Semantics::Actions 
{
	class InvocationActionActivation;
}

namespace fUML::Semantics::Actions 
{
	class OutputPinActivation;
}

namespace fUML::Semantics::Actions 
{
	class PinActivation;
}

namespace fUML::Semantics::Activities 
{
	class Token;
}

// base class includes
#include "fUML/Semantics/Actions/InvocationActionActivation.hpp"

// enum includes


//*********************************
namespace fUML::Semantics::Actions 
{
	
	class CallActionActivation:virtual public InvocationActionActivation
	{
		public:
 			CallActionActivation(const CallActionActivation &) {}
			CallActionActivation& operator=(CallActionActivation const&) = delete;

		protected:
			CallActionActivation(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~CallActionActivation() {}

			//*********************************
			// Operations
			//*********************************
			 
			virtual void doAction() = 0;
			
			 
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> getCallExecution() = 0;
			
			 
			virtual void removeCallExecution(std::shared_ptr<fUML::Semantics::CommonBehavior::Execution>  execution) = 0;
			
			 
			virtual void terminate() = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<uml::CallAction > getCallAction() const = 0;
			
			
			virtual void setCallAction(std::shared_ptr<uml::CallAction> _callAction) = 0;
			
			/*Additional Setter for 'ActionActivation::action' redefined by reference 'callAction'*/
			
			virtual void setAction(std::shared_ptr<uml::Action> _action) = 0;
			
			/*Additional Setter for 'ActivityNodeActivation::node' redefined by reference 'callAction'*/
			
			virtual void setNode(std::shared_ptr<uml::ActivityNode> _node) = 0;
			
			
			virtual std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::Execution>> getCallExecutions() const = 0;
			
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			
			std::shared_ptr<uml::CallAction > m_callAction;
			mutable std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::Execution>> m_callExecutions;

		public:
			//*********************************
			// Union Getter
			//*********************************
			
			virtual std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> getPinActivation() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_CALLACTIONACTIVATION_HPP */
