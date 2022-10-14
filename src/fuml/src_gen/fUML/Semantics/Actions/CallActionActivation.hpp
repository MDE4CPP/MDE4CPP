//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_CALLACTIONACTIVATION_HPP
#define FUML_SEMANTICS_ACTIONS_CALLACTIONACTIVATION_HPP


#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 


//*********************************
// generated Includes

//Forward Declaration for used types 
namespace fUML::Semantics::Actions 
{
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
namespace fUML::Semantics::CommonBehavior 
{
	class Execution;
	class ParameterValue;
}
namespace uml 
{
	class Action;
	class ActivityNode;
	class Behavior;
	class CallAction;
}

// namespace macro header include
#include "fUML/fUML.hpp"

// base class includes
#include "fUML/Semantics/Actions/InvocationActionActivation.hpp"




//*********************************
namespace fUML::Semantics::Actions 
{
	
	class FUML_API CallActionActivation : virtual public InvocationActionActivation
	{
		public:
 			CallActionActivation(const CallActionActivation &) {}

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
			virtual std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> doCall(std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> inputParameterValues) = 0;
			
			
			virtual std::shared_ptr<uml::Behavior> retrieveBehavior() const = 0;
			virtual void terminate() = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<uml::CallAction> getCallAction() const = 0;
			virtual void setCallAction(std::shared_ptr<uml::CallAction>) = 0;
			/*Additional Setter for 'ActionActivation::action' redefined by reference 'callAction'*/
			virtual void setAction(std::shared_ptr<uml::Action>) = 0;
			/*Additional Setter for 'ActivityNodeActivation::node' redefined by reference 'callAction'*/
			virtual void setNode(std::shared_ptr<uml::ActivityNode>) = 0;
			

			//*********************************
			// Union Reference Getters
			//*********************************

			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			//*********************************
			// Reference Members
			//*********************************
			std::shared_ptr<uml::CallAction> m_callAction;
			
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_CALLACTIONACTIVATION_HPP */
