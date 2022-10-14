//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_EXPANSIONREGION_HPP
#define UML_EXPANSIONREGION_HPP


#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 


//*********************************
// generated Includes

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
	class ExpansionNode;
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
#include "uml/ExpansionKind.hpp"
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	An ExpansionRegion is a StructuredActivityNode that executes its content multiple times corresponding to elements of input collection(s).
	<p>From package UML::Actions.</p>
	*/
	
	class UML_API ExpansionRegion : virtual public StructuredActivityNode
	{
		public:
 			ExpansionRegion(const ExpansionRegion &) {}

		protected:
			ExpansionRegion(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ExpansionRegion() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			The mode in which the ExpansionRegion executes its contents. If parallel, executions are concurrent. If iterative, executions are sequential. If stream, a stream of values flows into a single execution.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual uml::ExpansionKind getMode() const = 0;
			/*!
			The mode in which the ExpansionRegion executes its contents. If parallel, executions are concurrent. If iterative, executions are sequential. If stream, a stream of values flows into a single execution.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual void setMode (uml::ExpansionKind _mode)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The ExpansionNodes that hold the input collections for the ExpansionRegion.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::ExpansionNode>> getInputElement() const = 0;
			/*!
			The ExpansionNodes that form the output collections of the ExpansionRegion.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::ExpansionNode>> getOutputElement() const = 0;

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
			/*!
			The mode in which the ExpansionRegion executes its contents. If parallel, executions are concurrent. If iterative, executions are sequential. If stream, a stream of values flows into a single execution.
			<p>From package UML::Actions.</p>
			*/
			
			uml::ExpansionKind m_mode= uml::ExpansionKind::ITERATIVE;
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The ExpansionNodes that hold the input collections for the ExpansionRegion.
			<p>From package UML::Actions.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::ExpansionNode>> m_inputElement;
			/*!
			The ExpansionNodes that form the output collections of the ExpansionRegion.
			<p>From package UML::Actions.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::ExpansionNode>> m_outputElement;
	};
}
#endif /* end of include guard: UML_EXPANSIONREGION_HPP */
