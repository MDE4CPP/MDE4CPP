//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_VALUEPIN_HPP
#define UML_VALUEPIN_HPP

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
	A ValuePin is an InputPin that provides a value by evaluating a ValueSpecification.
	<p>From package UML::Actions.</p>
	*/
	
	class UML_API ValuePin: virtual public InputPin
	{
		public:
 			ValuePin(const ValuePin &) {}

		protected:
			ValuePin(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ValuePin() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The type of the value ValueSpecification must conform to the type of the ValuePin.
			value.type.conformsTo(type)
			*/
			 
			virtual bool compatible_type(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			A ValuePin may have no incoming ActivityEdges.
			incoming->isEmpty()
			*/
			 
			virtual bool no_incoming_edges(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The ValueSpecification that is evaluated to obtain the value that the ValuePin will provide.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::ValueSpecification> getValue() const = 0;
			/*!
			The ValueSpecification that is evaluated to obtain the value that the ValuePin will provide.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setValue(std::shared_ptr<uml::ValueSpecification>) = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const = 0;
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;
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
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The ValueSpecification that is evaluated to obtain the value that the ValuePin will provide.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::ValueSpecification> m_value;
	};
}
#endif /* end of include guard: UML_VALUEPIN_HPP */
