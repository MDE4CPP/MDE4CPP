//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_REPLYACTION_HPP
#define UML_REPLYACTION_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations
template<class T, class ... U> class Subset;

class Any;

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

namespace uml
{
	class umlFactory;
}

//Forward Declaration for used types 
namespace uml 
{
	class Activity;
	class ActivityEdge;
	class ActivityGroup;
	class ActivityPartition;
	class Classifier;
	class Comment;
	class Constraint;
	class Dependency;
	class ExceptionHandler;
	class InputPin;
	class InterruptibleActivityRegion;
	class Namespace;
	class OutputPin;
	class StringExpression;
	class StructuredActivityNode;
	class Trigger;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Action.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A ReplyAction is an Action that accepts a set of reply values and a value containing return information produced by a previous AcceptCallAction. The ReplyAction returns the values to the caller of the previous call, completing execution of the call.
	<p>From package UML::Actions.</p>
	*/
	
	class UML_API ReplyAction : virtual public Action
	{
		public:
 			ReplyAction(const ReplyAction &) {}

		protected:
			ReplyAction(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ReplyAction() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The event of the replyToCall Trigger must be a CallEvent.
			replyToCall.event.oclIsKindOf(CallEvent)
			*/
			 
			virtual bool event_on_reply_to_call_trigger(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			The replyValue InputPins must match the output (return, out, and inout) parameters of the operation of the event of the replyToCall Trigger in number, type, ordering, and multiplicity.
			let parameter:OrderedSet(Parameter) = replyToCall.event.oclAsType(CallEvent).operation.outputParameters() in
			replyValue->size()=parameter->size() and
			Sequence{1..replyValue->size()}->forAll(i |
				replyValue->at(i).type.conformsTo(parameter->at(i).type) and
				replyValue->at(i).isOrdered=parameter->at(i).isOrdered and
				replyValue->at(i).compatibleWith(parameter->at(i)))
			*/
			 
			virtual bool pins_match_parameter(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The Trigger specifying the Operation whose call is being replied to.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::Trigger> getReplyToCall() const = 0;
			/*!
			The Trigger specifying the Operation whose call is being replied to.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setReplyToCall(std::shared_ptr<uml::Trigger>) = 0;
			/*!
			A list of InputPins providing the values for the output (inout, out, and return) Parameters of the Operation. These values are returned to the caller.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::InputPin, uml::InputPin>> getReplyValue() const = 0;
			/*!
			An InputPin that holds the return information value produced by an earlier AcceptCallAction.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::InputPin> getReturnInformation() const = 0;
			/*!
			An InputPin that holds the return information value produced by an earlier AcceptCallAction.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setReturnInformation(std::shared_ptr<uml::InputPin>) = 0;

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
			/*!
			The Trigger specifying the Operation whose call is being replied to.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::Trigger> m_replyToCall;
			/*!
			A list of InputPins providing the values for the output (inout, out, and return) Parameters of the Operation. These values are returned to the caller.
			<p>From package UML::Actions.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::InputPin, uml::InputPin>> m_replyValue;
			/*!
			An InputPin that holds the return information value produced by an earlier AcceptCallAction.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::InputPin> m_returnInformation;
	};
}
#endif /* end of include guard: UML_REPLYACTION_HPP */
