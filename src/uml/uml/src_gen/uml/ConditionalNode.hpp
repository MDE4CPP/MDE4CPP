//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CONDITIONALNODE_HPP
#define UML_CONDITIONALNODE_HPP


#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 
template<class T, class ... U> class Subset;


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
			
			virtual const std::shared_ptr<Subset<uml::Clause, uml::Element>>& getClause() const = 0;
			/*!
			The OutputPins that onto which are moved values from the bodyOutputs of the Clause selected for execution.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::OutputPin>> getResult() const = 0;

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
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references) = 0;
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
