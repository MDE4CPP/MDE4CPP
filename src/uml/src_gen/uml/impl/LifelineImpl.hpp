//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_LIFELINELIFELINEIMPL_HPP
#define UML_LIFELINELIFELINEIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../Lifeline.hpp"

#include "uml/impl/NamedElementImpl.hpp"

//*********************************
namespace uml 
{
	class LifelineImpl :virtual public NamedElementImpl, virtual public Lifeline 
	{
		public: 
			LifelineImpl(const LifelineImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			LifelineImpl& operator=(LifelineImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			LifelineImpl();
			virtual std::shared_ptr<Lifeline> getThisLifelinePtr() const;
			virtual void setThisLifelinePtr(std::weak_ptr<Lifeline> thisLifelinePtr);

			//Additional constructors for the containments back reference
			LifelineImpl(std::weak_ptr<uml::Interaction > par_interaction);


			//Additional constructors for the containments back reference
			LifelineImpl(std::weak_ptr<uml::Namespace > par_namespace);


			//Additional constructors for the containments back reference
			LifelineImpl(std::weak_ptr<uml::Element > par_owner);




		public:
			//destructor
			virtual ~LifelineImpl();
			
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
			) */ 
			virtual bool interaction_uses_share_lifeline(Any diagnostics,std::map <   Any, Any >  context) ;
			
			/*!
			 The classifier containing the referenced ConnectableElement must be the same classifier, or an ancestor, of the classifier that contains the interaction enclosing this lifeline.
			represents.namespace->closure(namespace)->includes(interaction._'context') */ 
			virtual bool same_classifier(Any diagnostics,std::map <   Any, Any >  context) ;
			
			/*!
			 The selector value, if present, must be a LiteralString or a LiteralInteger
			self.selector->notEmpty() implies 
			self.selector.oclIsKindOf(LiteralInteger) or 
			self.selector.oclIsKindOf(LiteralString) */ 
			virtual bool selector_int_or_string(Any diagnostics,std::map <   Any, Any >  context) ;
			
			/*!
			 The selector for a Lifeline must only be specified if the referenced Part is multivalued.
			 self.selector->notEmpty() = (self.represents.oclIsKindOf(MultiplicityElement) and self.represents.oclAsType(MultiplicityElement).isMultivalued()) */ 
			virtual bool selector_specified(Any diagnostics,std::map <   Any, Any >  context) ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 References the InteractionFragments in which this Lifeline takes part.
			<p>From package UML::Interactions.</p> */
			virtual std::shared_ptr<Bag<uml::InteractionFragment>> getCoveredBy() const ;
			
			/*!
			 References the Interaction that represents the decomposition.
			<p>From package UML::Interactions.</p> */
			virtual std::shared_ptr<uml::PartDecomposition > getDecomposedAs() const ;
			
			/*!
			 References the Interaction that represents the decomposition.
			<p>From package UML::Interactions.</p> */
			virtual void setDecomposedAs(std::shared_ptr<uml::PartDecomposition> _decomposedAs_decomposedAs) ;
			/*!
			 References the Interaction enclosing this Lifeline.
			<p>From package UML::Interactions.</p> */
			virtual std::weak_ptr<uml::Interaction > getInteraction() const ;
			
			/*!
			 References the Interaction enclosing this Lifeline.
			<p>From package UML::Interactions.</p> */
			virtual void setInteraction(std::shared_ptr<uml::Interaction> _interaction_interaction) ;
			/*!
			 References the ConnectableElement within the classifier that contains the enclosing interaction.
			<p>From package UML::Interactions.</p> */
			virtual std::shared_ptr<uml::ConnectableElement > getRepresents() const ;
			
			/*!
			 References the ConnectableElement within the classifier that contains the enclosing interaction.
			<p>From package UML::Interactions.</p> */
			virtual void setRepresents(std::shared_ptr<uml::ConnectableElement> _represents_represents) ;
			/*!
			 If the referenced ConnectableElement is multivalued, then this specifies the specific individual part within that set.
			<p>From package UML::Interactions.</p> */
			virtual std::shared_ptr<uml::ValueSpecification > getSelector() const ;
			
			/*!
			 If the referenced ConnectableElement is multivalued, then this specifies the specific individual part within that set.
			<p>From package UML::Interactions.</p> */
			virtual void setSelector(std::shared_ptr<uml::ValueSpecification> _selector_selector) ;
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Namespace > getNamespace() const ;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Element > getOwner() const ; 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<Lifeline> m_thisLifelinePtr;
	};
}
#endif /* end of include guard: UML_LIFELINELIFELINEIMPL_HPP */
