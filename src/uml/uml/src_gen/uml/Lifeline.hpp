//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_LIFELINE_HPP
#define UML_LIFELINE_HPP

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
	class Comment;
	class ConnectableElement;
	class Dependency;
	class Interaction;
	class InteractionFragment;
	class Namespace;
	class PartDecomposition;
	class StringExpression;
	class ValueSpecification;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/NamedElement.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A Lifeline represents an individual participant in the Interaction. While parts and structural features may have multiplicity greater than 1, Lifelines represent only one interacting entity.
	<p>From package UML::Interactions.</p>
	*/
	
	class UML_API Lifeline : virtual public NamedElement
	{
		public:
 			Lifeline(const Lifeline &) {}

		protected:
			Lifeline(){}
			//Additional constructors for the containments back reference
			Lifeline(std::weak_ptr<uml::Interaction> par_interaction);

			//Additional constructors for the containments back reference
			Lifeline(std::weak_ptr<uml::Namespace> par_namespace);

			//Additional constructors for the containments back reference
			Lifeline(std::weak_ptr<uml::Element> par_owner);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Lifeline() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			If a lifeline is in an Interaction referred to by an InteractionUse in an enclosing Interaction,  and that lifeline is common with another lifeline in an Interaction referred to by another InteractonUse within that same enclosing Interaction, it must be common to a lifeline within that enclosing Interaction. By common Lifelines we mean Lifelines with the same selector and represents associations.
			let intUses : Set(InteractionUse) = interaction.interactionUse  in 
			intUses->forAll
			( iuse : InteractionUse | 
			let usingInteraction : Set(Interaction)  = iuse.enclosingInteraction->asSet()
			->union(
			iuse.enclosingOperand.combinedFragment->asSet()->closure(enclosingOperand.combinedFragment).enclosingInteraction->asSet()
			               ) 
			in
			let peerUses : Set(InteractionUse) = usingInteraction.fragment->select(oclIsKindOf(InteractionUse)).oclAsType(InteractionUse)->asSet()
			->union(
			usingInteraction.fragment->select(oclIsKindOf(CombinedFragment)).oclAsType(CombinedFragment)->asSet()
			->closure(operand.fragment->select(oclIsKindOf(CombinedFragment)).oclAsType(CombinedFragment)).operand.fragment->
			select(oclIsKindOf(InteractionUse)).oclAsType(InteractionUse)->asSet()
			               )->excluding(iuse)
			 in
			peerUses->forAll( peerUse : InteractionUse |
			 peerUse.refersTo.lifeline->forAll( l : Lifeline | (l.represents = self.represents and 
			 ( self.selector.oclIsKindOf(LiteralString) implies
			  l.selector.oclIsKindOf(LiteralString) and 
			  self.selector.oclAsType(LiteralString).value = l.selector.oclAsType(LiteralString).value )
			  and 
			( self.selector.oclIsKindOf(LiteralInteger) implies
			  l.selector.oclIsKindOf(LiteralInteger) and 
			  self.selector.oclAsType(LiteralInteger).value = l.selector.oclAsType(LiteralInteger).value )
			)  
			implies
			 usingInteraction.lifeline->exists(represents = self.represents and
			 ( self.selector.oclIsKindOf(LiteralString) implies
			  l.selector.oclIsKindOf(LiteralString) and 
			  self.selector.oclAsType(LiteralString).value = l.selector.oclAsType(LiteralString).value )
			and 
			( self.selector.oclIsKindOf(LiteralInteger) implies
			  l.selector.oclIsKindOf(LiteralInteger) and 
			  self.selector.oclAsType(LiteralInteger).value = l.selector.oclAsType(LiteralInteger).value )
			)
			                                                )
			                    )
			)
			*/
			 
			virtual bool interaction_uses_share_lifeline(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			The classifier containing the referenced ConnectableElement must be the same classifier, or an ancestor, of the classifier that contains the interaction enclosing this lifeline.
			represents.namespace->closure(namespace)->includes(interaction._'context')
			*/
			 
			virtual bool same_classifier(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			The selector value, if present, must be a LiteralString or a LiteralInteger
			self.selector->notEmpty() implies 
			self.selector.oclIsKindOf(LiteralInteger) or 
			self.selector.oclIsKindOf(LiteralString)
			*/
			 
			virtual bool selector_int_or_string(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			The selector for a Lifeline must only be specified if the referenced Part is multivalued.
			 self.selector->notEmpty() = (self.represents.oclIsKindOf(MultiplicityElement) and self.represents.oclAsType(MultiplicityElement).isMultivalued())
			*/
			 
			virtual bool selector_specified(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			References the InteractionFragments in which this Lifeline takes part.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::InteractionFragment>> getCoveredBy() const = 0;
			/*!
			References the Interaction that represents the decomposition.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::PartDecomposition> getDecomposedAs() const = 0;
			/*!
			References the Interaction that represents the decomposition.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setDecomposedAs(std::shared_ptr<uml::PartDecomposition>) = 0;
			/*!
			References the Interaction enclosing this Lifeline.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::weak_ptr<uml::Interaction> getInteraction() const = 0;
			/*!
			References the Interaction enclosing this Lifeline.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setInteraction(std::weak_ptr<uml::Interaction>) = 0;
			/*!
			References the ConnectableElement within the classifier that contains the enclosing interaction.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::ConnectableElement> getRepresents() const = 0;
			/*!
			References the ConnectableElement within the classifier that contains the enclosing interaction.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setRepresents(std::shared_ptr<uml::ConnectableElement>) = 0;
			/*!
			If the referenced ConnectableElement is multivalued, then this specifies the specific individual part within that set.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::ValueSpecification> getSelector() const = 0;
			/*!
			If the referenced ConnectableElement is multivalued, then this specifies the specific individual part within that set.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setSelector(std::shared_ptr<uml::ValueSpecification>) = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
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
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const = 0;

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
			References the InteractionFragments in which this Lifeline takes part.
			<p>From package UML::Interactions.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::InteractionFragment>> m_coveredBy;
			/*!
			References the Interaction that represents the decomposition.
			<p>From package UML::Interactions.</p>
			*/
			
			std::shared_ptr<uml::PartDecomposition> m_decomposedAs;
			/*!
			References the Interaction enclosing this Lifeline.
			<p>From package UML::Interactions.</p>
			*/
			
			std::weak_ptr<uml::Interaction> m_interaction;
			/*!
			References the ConnectableElement within the classifier that contains the enclosing interaction.
			<p>From package UML::Interactions.</p>
			*/
			
			std::shared_ptr<uml::ConnectableElement> m_represents;
			/*!
			If the referenced ConnectableElement is multivalued, then this specifies the specific individual part within that set.
			<p>From package UML::Interactions.</p>
			*/
			
			std::shared_ptr<uml::ValueSpecification> m_selector;
	};
}
#endif /* end of include guard: UML_LIFELINE_HPP */
