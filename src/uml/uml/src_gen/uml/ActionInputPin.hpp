//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ACTIONINPUTPIN_HPP
#define UML_ACTIONINPUTPIN_HPP

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
	class Action;
	class Activity;
	class ActivityEdge;
	class ActivityGroup;
	class ActivityPartition;
	class AddStructuralFeatureValueAction;
	class Behavior;
	class CallOperationAction;
	class Classifier;
	class Comment;
	class Dependency;
	class DestroyObjectAction;
	class InterruptibleActivityRegion;
	class InvocationAction;
	class Namespace;
	class RemoveStructuralFeatureValueAction;
	class State;
	class StringExpression;
	class StructuralFeatureAction;
	class StructuredActivityNode;
	class Type;
	class ValueSpecification;
	class WriteStructuralFeatureAction;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/InputPin.hpp"

// enum includes
#include "uml/ObjectNodeOrderingKind.hpp"
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	An ActionInputPin is a kind of InputPin that executes an Action to determine the values to input to another Action.
	<p>From package UML::Actions.</p>
	*/
	
	class UML_API ActionInputPin : virtual public InputPin
	{
		public:
 			ActionInputPin(const ActionInputPin &) {}

		protected:
			ActionInputPin(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ActionInputPin() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The fromAction of an ActionInputPin must only have ActionInputPins as InputPins.
			fromAction.input->forAll(oclIsKindOf(ActionInputPin))
			*/
			 
			virtual bool input_pin(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			The fromAction of an ActionInputPin cannot have ActivityEdges coming into or out of it or its Pins.
			fromAction.incoming->union(outgoing)->isEmpty() and
			fromAction.input.incoming->isEmpty() and
			fromAction.output.outgoing->isEmpty()
			*/
			 
			virtual bool no_control_or_object_flow(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			The fromAction of an ActionInputPin must have exactly one OutputPin.
			fromAction.output->size() = 1
			*/
			 
			virtual bool one_output_pin(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The Action used to provide the values of the ActionInputPin.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::Action> getFromAction() const = 0;
			/*!
			The Action used to provide the values of the ActionInputPin.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setFromAction(std::shared_ptr<uml::Action>) = 0;

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
			The Action used to provide the values of the ActionInputPin.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::Action> m_fromAction;
	};
}
#endif /* end of include guard: UML_ACTIONINPUTPIN_HPP */
