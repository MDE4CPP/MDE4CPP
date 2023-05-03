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
	class CallAction;
	class Parameter;
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
			virtual std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> doCall(const std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>>& inputParameterValues) = 0;
			
			
			virtual std::shared_ptr<Bag<uml::Parameter>> retrieveCallParameters() const = 0;
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
			std::shared_ptr<uml::CallAction> m_callAction;
			
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_CALLACTIONACTIVATION_HPP */
