//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_PROTOCOLSTATEMACHINE_HPP
#define UML_PROTOCOLSTATEMACHINE_HPP

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
	class BehavioralFeature;
	class CollaborationUse;
	class Comment;
	class ConnectableElement;
	class Connector;
	class Constraint;
	class Dependency;
	class ElementImport;
	class Extension;
	class Feature;
	class Generalization;
	class GeneralizationSet;
	class InterfaceRealization;
	class Operation;
	class Package;
	class PackageImport;
	class Parameter;
	class ParameterSet;
	class Port;
	class Property;
	class ProtocolConformance;
	class Pseudostate;
	class Reception;
	class Region;
	class State;
	class StringExpression;
	class Substitution;
	class TemplateBinding;
	class TemplateParameter;
	class TemplateSignature;
	class UseCase;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/StateMachine.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A ProtocolStateMachine is always defined in the context of a Classifier. It specifies which BehavioralFeatures of the Classifier can be called in which State and under which conditions, thus specifying the allowed invocation sequences on the Classifier's BehavioralFeatures. A ProtocolStateMachine specifies the possible and permitted Transitions on the instances of its context Classifier, together with the BehavioralFeatures that carry the Transitions. In this manner, an instance lifecycle can be specified for a Classifier, by defining the order in which the BehavioralFeatures can be activated and the States through which an instance progresses during its existence.
	<p>From package UML::StateMachines.</p>
	*/
	
	class UML_API ProtocolStateMachine: virtual public StateMachine
	{
		public:
 			ProtocolStateMachine(const ProtocolStateMachine &) {}

		protected:
			ProtocolStateMachine(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ProtocolStateMachine() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			ProtocolStateMachines cannot have deep or shallow history Pseudostates.
			region->forAll (r | r.subvertex->forAll (v | v.oclIsKindOf(Pseudostate) implies
			((v.oclAsType(Pseudostate).kind <>  PseudostateKind::deepHistory) and (v.oclAsType(Pseudostate).kind <> PseudostateKind::shallowHistory))))
			*/
			 
			virtual bool deep_or_shallow_history(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			The states of a ProtocolStateMachine cannot have entry, exit, or do activity Behaviors.
			region->forAll(r | r.subvertex->forAll(v | v.oclIsKindOf(State) implies
			(v.oclAsType(State).entry->isEmpty() and v.oclAsType(State).exit->isEmpty() and v.oclAsType(State).doActivity->isEmpty())))
			*/
			 
			virtual bool entry_exit_do(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			All Transitions of a ProtocolStateMachine must be ProtocolTransitions.
			region->forAll(r | r.transition->forAll(t | t.oclIsTypeOf(ProtocolTransition)))
			*/
			 
			virtual bool protocol_transitions(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			Conformance between ProtocolStateMachine
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ProtocolConformance, uml::Element>> getConformance() const = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			All of the Properties that are direct (i.e., not inherited or imported) attributes of the Classifier.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> getAttribute() const = 0;
			/*!
			Specifies each Feature directly defined in the classifier. Note that there may be members of the Classifier that are of the type Feature but are not included, e.g., inherited features.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> getFeature() const = 0;
			/*!
			A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::NamedElement>> getMember() const = 0;
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const = 0;
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
			/*!
			The contexts that this element may be redefined from.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Classifier>> getRedefinitionContext() const = 0;
			/*!
			The roles that instances may play in this StructuredClassifier.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement>> getRole() const = 0;
			

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
			Conformance between ProtocolStateMachine
			<p>From package UML::StateMachines.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::ProtocolConformance, uml::Element>> m_conformance;
	};
}
#endif /* end of include guard: UML_PROTOCOLSTATEMACHINE_HPP */
