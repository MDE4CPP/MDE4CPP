//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_REDUCEACTION_HPP
#define UML_REDUCEACTION_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations
template<class T, class ... U> class Subset;

class AnyObject;
typedef std::shared_ptr<AnyObject> Any;

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
	class Behavior;
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
	A ReduceAction is an Action that reduces a collection to a single value by repeatedly combining the elements of the collection using a reducer Behavior.
	<p>From package UML::Actions.</p>
	*/
	
	class UML_API ReduceAction: virtual public Action
	{
		public:
 			ReduceAction(const ReduceAction &) {}

		protected:
			ReduceAction(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ReduceAction() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The type of the collection InputPin must be a collection.
			*/
			 
			virtual bool input_type_is_collection(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;/*!
			The type of the output of the reducer Behavior must conform to the type of the result OutputPin.
			reducer.outputParameters().type->forAll(conformsTo(result.type))
			*/
			 
			virtual bool output_types_are_compatible(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;/*!
			The reducer Behavior must have two input ownedParameters and one output ownedParameter, where the type of the output Parameter and the type of elements of the input collection conform to the types of the input Parameters.
			let inputs: OrderedSet(Parameter) = reducer.inputParameters() in
			let outputs: OrderedSet(Parameter) = reducer.outputParameters() in
			inputs->size()=2 and outputs->size()=1 and
			inputs.type->forAll(t | 
				outputs.type->forAll(conformsTo(t)) and 
				-- Note that the following only checks the case when the collection is via multiple tokens.
				collection.upperBound()>1 implies collection.type.conformsTo(t))
			*/
			 
			virtual bool reducer_inputs_output(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			//*********************************
			// Attributes Getter & Setter
			//*********************************
			/*!
			Indicates whether the order of the input collection should determine the order in which the reducer Behavior is applied to its elements.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual bool getIsOrdered() const = 0;
			/*!
			Indicates whether the order of the input collection should determine the order in which the reducer Behavior is applied to its elements.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual void setIsOrdered (bool _isOrdered)= 0;
			
			//*********************************
			// References Getter & Setter
			//*********************************
			/*!
			The InputPin that provides the collection to be reduced.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::InputPin> getCollection() const = 0;
			/*!
			The InputPin that provides the collection to be reduced.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setCollection(std::shared_ptr<uml::InputPin>) = 0;
			/*!
			A Behavior that is repreatedly applied to two elements of the input collection to produce a value that is of the same type as elements of the collection.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::Behavior> getReducer() const = 0;
			/*!
			A Behavior that is repreatedly applied to two elements of the input collection to produce a value that is of the same type as elements of the collection.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setReducer(std::shared_ptr<uml::Behavior>) = 0;
			/*!
			The output pin on which the result value is placed.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::OutputPin> getResult() const = 0;
			/*!
			The output pin on which the result value is placed.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setResult(std::shared_ptr<uml::OutputPin>) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			Indicates whether the order of the input collection should determine the order in which the reducer Behavior is applied to its elements.
			<p>From package UML::Actions.</p>
			*/
			
			bool m_isOrdered = false;
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The InputPin that provides the collection to be reduced.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::InputPin> m_collection;/*!
			A Behavior that is repreatedly applied to two elements of the input collection to produce a value that is of the same type as elements of the collection.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::Behavior> m_reducer;/*!
			The output pin on which the result value is placed.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::OutputPin> m_result;

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const = 0;/*!
			The ordered set of InputPins representing the inputs to the Action.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> getInput() const = 0;/*!
			The ordered set of OutputPins representing outputs from the Action.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> getOutput() const = 0;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const = 0;/*!
			The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_REDUCEACTION_HPP */
