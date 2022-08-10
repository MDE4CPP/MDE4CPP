//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CONDITIONALNODE_HPP
#define UML_CONDITIONALNODE_HPP

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
	class Clause;
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
	A ConditionalNode is a StructuredActivityNode that chooses one among some number of alternative collections of ExecutableNodes to execute.
	<p>From package UML::Actions.</p>
	*/
	
	class UML_API ConditionalNode : virtual public StructuredActivityNode
	{
		public:
 			ConditionalNode(const ConditionalNode &) {}

		protected:
			ConditionalNode(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ConditionalNode() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			No two clauses within a ConditionalNode may be predecessorClauses of each other, either directly or indirectly.
			clause->closure(predecessorClause)->intersection(clause)->isEmpty()
			*/
			 
			virtual bool clause_no_predecessor(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			The union of the ExecutableNodes in the test and body parts of all clauses must be the same as the subset of nodes contained in the ConditionalNode (considered as a StructuredActivityNode) that are ExecutableNodes.
			clause.test->union(clause._'body') = node->select(oclIsKindOf(ExecutableNode)).oclAsType(ExecutableNode)
			*/
			 
			virtual bool executable_nodes(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			Each clause of a ConditionalNode must have the same number of bodyOutput pins as the ConditionalNode has result OutputPins, and each clause bodyOutput Pin must be compatible with the corresponding result OutputPin (by positional order) in type, multiplicity, ordering, and uniqueness.
			clause->forAll(
				bodyOutput->size()=self.result->size() and
				Sequence{1..self.result->size()}->forAll(i |
					bodyOutput->at(i).type.conformsTo(result->at(i).type) and
					bodyOutput->at(i).isOrdered = result->at(i).isOrdered and
					bodyOutput->at(i).isUnique = result->at(i).isUnique and
					bodyOutput->at(i).compatibleWith(result->at(i))))
			*/
			 
			virtual bool matching_output_pins(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			A ConditionalNode has no InputPins.
			input->isEmpty()
			*/
			 
			virtual bool no_input_pins(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			No ExecutableNode in the ConditionNode may appear in the test or body part of more than one clause of a ConditionalNode.
			node->select(oclIsKindOf(ExecutableNode)).oclAsType(ExecutableNode)->forAll(n | 
				self.clause->select(test->union(_'body')->includes(n))->size()=1)
			*/
			 
			virtual bool one_clause_with_executable_node(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			The result OutputPins have no incoming edges.
			result.incoming->isEmpty()
			*/
			 
			virtual bool result_no_incoming(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			If true, the modeler asserts that the test for at least one Clause of the ConditionalNode will succeed.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual bool getIsAssured() const = 0;
			/*!
			If true, the modeler asserts that the test for at least one Clause of the ConditionalNode will succeed.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual void setIsAssured (bool _isAssured)= 0;
			/*!
			If true, the modeler asserts that the test for at most one Clause of the ConditionalNode will succeed.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual bool getIsDeterminate() const = 0;
			/*!
			If true, the modeler asserts that the test for at most one Clause of the ConditionalNode will succeed.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual void setIsDeterminate (bool _isDeterminate)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The set of Clauses composing the ConditionalNode.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Clause, uml::Element>> getClause() const = 0;
			/*!
			The OutputPins that onto which are moved values from the bodyOutputs of the Clause selected for execution.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::OutputPin>> getResult() const = 0;

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
			If true, the modeler asserts that the test for at least one Clause of the ConditionalNode will succeed.
			<p>From package UML::Actions.</p>
			*/
			
			bool m_isAssured= false;
			/*!
			If true, the modeler asserts that the test for at most one Clause of the ConditionalNode will succeed.
			<p>From package UML::Actions.</p>
			*/
			
			bool m_isDeterminate= false;
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The set of Clauses composing the ConditionalNode.
			<p>From package UML::Actions.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Clause, uml::Element>> m_clause;
	};
}
#endif /* end of include guard: UML_CONDITIONALNODE_HPP */
