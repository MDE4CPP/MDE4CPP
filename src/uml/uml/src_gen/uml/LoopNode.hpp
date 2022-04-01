//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_LOOPNODE_HPP
#define UML_LOOPNODE_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 
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
	class ActivityPartition;
	class Classifier;
	class Comment;
	class Constraint;
	class Dependency;
	class ElementImport;
	class ExceptionHandler;
	class InputPin;
	class InterruptibleActivityRegion;
	class OutputPin;
	class PackageImport;
	class PackageableElement;
	class StringExpression;
	class Variable;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/StructuredActivityNode.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A LoopNode is a StructuredActivityNode that represents an iterative loop with setup, test, and body sections.
	<p>From package UML::Actions.</p>
	*/
	
	class UML_API LoopNode: virtual public StructuredActivityNode
	{
		public:
 			LoopNode(const LoopNode &) {}

		protected:
			LoopNode(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~LoopNode() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The bodyOutput pins are OutputPins on Actions in the body of the LoopNode.
			bodyPart.oclAsType(Action).allActions().output->includesAll(bodyOutput)
			*/
			 
			virtual bool body_output_pins(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < std::shared_ptr<Any>, std::shared_ptr<Any>>> context) = 0;
			/*!
			The union of the ExecutableNodes in the setupPart, test and bodyPart of a LoopNode must be the same as the subset of nodes contained in the LoopNode (considered as a StructuredActivityNode) that are ExecutableNodes.
			setupPart->union(test)->union(bodyPart)=node->select(oclIsKindOf(ExecutableNode)).oclAsType(ExecutableNode)->asSet()
			*/
			 
			virtual bool executable_nodes(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < std::shared_ptr<Any>, std::shared_ptr<Any>>> context) = 0;
			/*!
			The loopVariableInputs must not have outgoing edges.
			loopVariableInput.outgoing->isEmpty()
			*/
			 
			virtual bool input_edges(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < std::shared_ptr<Any>, std::shared_ptr<Any>>> context) = 0;
			/*!
			All ActivityEdges outgoing from loopVariable OutputPins must have targets within the LoopNode.
			allOwnedNodes()->includesAll(loopVariable.outgoing.target)
			*/
			 
			virtual bool loop_variable_outgoing(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < std::shared_ptr<Any>, std::shared_ptr<Any>>> context) = 0;
			/*!
			A LoopNode must have the same number of loopVariableInputs and loopVariables, and they must match in type, uniqueness and multiplicity.
			loopVariableInput->size()=loopVariable->size() and
			loopVariableInput.type=loopVariable.type and
			loopVariableInput.isUnique=loopVariable.isUnique and
			loopVariableInput.lower=loopVariable.lower and
			loopVariableInput.upper=loopVariable.upper
			*/
			 
			virtual bool matching_loop_variables(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < std::shared_ptr<Any>, std::shared_ptr<Any>>> context) = 0;
			/*!
			A LoopNode must have the same number of bodyOutput Pins as loopVariables, and each bodyOutput Pin must be compatible with the corresponding loopVariable (by positional order) in type, multiplicity, ordering and uniqueness.
			bodyOutput->size()=loopVariable->size() and
			Sequence{1..loopVariable->size()}->forAll(i |
				bodyOutput->at(i).type.conformsTo(loopVariable->at(i).type) and
				bodyOutput->at(i).isOrdered = loopVariable->at(i).isOrdered and
				bodyOutput->at(i).isUnique = loopVariable->at(i).isUnique and
				loopVariable->at(i).includesMultiplicity(bodyOutput->at(i)))
			*/
			 
			virtual bool matching_output_pins(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < std::shared_ptr<Any>, std::shared_ptr<Any>>> context) = 0;
			/*!
			A LoopNode must have the same number of result OutputPins and loopVariables, and they must match in type, uniqueness and multiplicity.
			result->size()=loopVariable->size() and
			result.type=loopVariable.type and
			result.isUnique=loopVariable.isUnique and
			result.lower=loopVariable.lower and
			result.upper=loopVariable.upper
			*/
			 
			virtual bool matching_result_pins(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < std::shared_ptr<Any>, std::shared_ptr<Any>>> context) = 0;
			/*!
			The result OutputPins have no incoming edges.
			result.incoming->isEmpty()
			*/
			 
			virtual bool result_no_incoming(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < std::shared_ptr<Any>, std::shared_ptr<Any>>> context) = 0;
			/*!
			The test and body parts of a ConditionalNode must be disjoint with each other.
			setupPart->intersection(test)->isEmpty() and
			setupPart->intersection(bodyPart)->isEmpty() and
			test->intersection(bodyPart)->isEmpty()
			*/
			 
			virtual bool setup_test_and_body(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < std::shared_ptr<Any>, std::shared_ptr<Any>>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			If true, the test is performed before the first execution of the bodyPart. If false, the bodyPart is executed once before the test is performed.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual bool getIsTestedFirst() const = 0;
			/*!
			If true, the test is performed before the first execution of the bodyPart. If false, the bodyPart is executed once before the test is performed.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual void setIsTestedFirst (bool _isTestedFirst)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The OutputPins on Actions within the bodyPart, the values of which are moved to the loopVariable OutputPins after the completion of each execution of the bodyPart, before the next iteration of the loop begins or before the loop exits.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::OutputPin>> getBodyOutput() const = 0;
			/*!
			The set of ExecutableNodes that perform the repetitive computations of the loop. The bodyPart is executed as long as the test section produces a true value.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::ExecutableNode>> getBodyPart() const = 0;
			/*!
			An OutputPin on an Action in the test section whose Boolean value determines whether to continue executing the loop bodyPart.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::OutputPin> getDecider() const = 0;
			/*!
			An OutputPin on an Action in the test section whose Boolean value determines whether to continue executing the loop bodyPart.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setDecider(std::shared_ptr<uml::OutputPin>) = 0;
			/*!
			A list of OutputPins that hold the values of the loop variables during an execution of the loop. When the test fails, the values are moved to the result OutputPins of the loop.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::OutputPin, uml::Element>> getLoopVariable() const = 0;
			/*!
			A list of InputPins whose values are moved into the loopVariable Pins before the first iteration of the loop.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::InputPin>> getLoopVariableInput() const = 0;
			/*!
			A list of OutputPins that receive the loopVariable values after the last iteration of the loop and constitute the output of the LoopNode.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::OutputPin>> getResult() const = 0;
			/*!
			The set of ExecutableNodes executed before the first iteration of the loop, in order to initialize values or perform other setup computations.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::ExecutableNode>> getSetupPart() const = 0;
			/*!
			The set of ExecutableNodes executed in order to provide the test result for the loop.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::ExecutableNode>> getTest() const = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			ActivityEdges immediately contained in the ActivityGroup.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityEdge>> getContainedEdge() const = 0;
			/*!
			ActivityNodes immediately contained in the ActivityGroup.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityNode>> getContainedNode() const = 0;
			/*!
			ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const = 0;
			/*!
			The ordered set of InputPins representing the inputs to the Action.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> getInput() const = 0;
			/*!
			A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::NamedElement>> getMember() const = 0;
			/*!
			The ordered set of OutputPins representing outputs from the Action.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> getOutput() const = 0;
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;
			/*!
			A collection of NamedElements owned by the Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement>> getOwnedMember() const = 0;
			/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const = 0;
			/*!
			The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const = 0;

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
			/*!
			If true, the test is performed before the first execution of the bodyPart. If false, the bodyPart is executed once before the test is performed.
			<p>From package UML::Actions.</p>
			*/
			
			bool m_isTestedFirst= false;
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The OutputPins on Actions within the bodyPart, the values of which are moved to the loopVariable OutputPins after the completion of each execution of the bodyPart, before the next iteration of the loop begins or before the loop exits.
			<p>From package UML::Actions.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::OutputPin>> m_bodyOutput;
			/*!
			The set of ExecutableNodes that perform the repetitive computations of the loop. The bodyPart is executed as long as the test section produces a true value.
			<p>From package UML::Actions.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::ExecutableNode>> m_bodyPart;
			/*!
			An OutputPin on an Action in the test section whose Boolean value determines whether to continue executing the loop bodyPart.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::OutputPin> m_decider;
			/*!
			A list of OutputPins that hold the values of the loop variables during an execution of the loop. When the test fails, the values are moved to the result OutputPins of the loop.
			<p>From package UML::Actions.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::OutputPin, uml::Element>> m_loopVariable;
			/*!
			The set of ExecutableNodes executed before the first iteration of the loop, in order to initialize values or perform other setup computations.
			<p>From package UML::Actions.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::ExecutableNode>> m_setupPart;
			/*!
			The set of ExecutableNodes executed in order to provide the test result for the loop.
			<p>From package UML::Actions.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::ExecutableNode>> m_test;
	};
}
#endif /* end of include guard: UML_LOOPNODE_HPP */
