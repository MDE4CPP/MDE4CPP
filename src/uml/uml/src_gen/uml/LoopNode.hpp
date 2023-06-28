//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_LOOPNODE_HPP
#define UML_LOOPNODE_HPP


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
	
	class UML_API LoopNode : virtual public StructuredActivityNode
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
			
			virtual const std::shared_ptr<Bag<uml::OutputPin>>& getBodyOutput() const = 0;
			/*!
			The set of ExecutableNodes that perform the repetitive computations of the loop. The bodyPart is executed as long as the test section produces a true value.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<Bag<uml::ExecutableNode>>& getBodyPart() const = 0;
			/*!
			An OutputPin on an Action in the test section whose Boolean value determines whether to continue executing the loop bodyPart.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::OutputPin>& getDecider() const = 0;
			/*!
			An OutputPin on an Action in the test section whose Boolean value determines whether to continue executing the loop bodyPart.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setDecider(const std::shared_ptr<uml::OutputPin>&) = 0;
			/*!
			A list of OutputPins that hold the values of the loop variables during an execution of the loop. When the test fails, the values are moved to the result OutputPins of the loop.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::OutputPin, uml::Element>>& getLoopVariable() const = 0;
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
			
			virtual const std::shared_ptr<Bag<uml::ExecutableNode>>& getSetupPart() const = 0;
			/*!
			The set of ExecutableNodes executed in order to provide the test result for the loop.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<Bag<uml::ExecutableNode>>& getTest() const = 0;

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
