//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_SEQUENCENODE_HPP
#define UML_SEQUENCENODE_HPP


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
	A SequenceNode is a StructuredActivityNode that executes a sequence of ExecutableNodes in order.
	<p>From package UML::Actions.</p>
	*/
	
	class UML_API SequenceNode : virtual public StructuredActivityNode
	{
		public:
 			SequenceNode(const SequenceNode &) {}

		protected:
			SequenceNode(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~SequenceNode() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The ordered set of ExecutableNodes to be sequenced.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::ExecutableNode>> getExecutableNode() const = 0;

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
	};
}
#endif /* end of include guard: UML_SEQUENCENODE_HPP */
