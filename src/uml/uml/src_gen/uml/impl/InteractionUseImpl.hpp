//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INTERACTIONUSEINTERACTIONUSEIMPL_HPP
#define UML_INTERACTIONUSEINTERACTIONUSEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../InteractionUse.hpp"

#include "uml/impl/InteractionFragmentImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API InteractionUseImpl : virtual public InteractionFragmentImpl, virtual public InteractionUse 
	{
		public: 
			InteractionUseImpl(const InteractionUseImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			InteractionUseImpl& operator=(InteractionUseImpl const&); 

		protected:
			friend class umlFactoryImpl;
			InteractionUseImpl();
			virtual std::shared_ptr<uml::InteractionUse> getThisInteractionUsePtr() const;
			virtual void setThisInteractionUsePtr(std::weak_ptr<uml::InteractionUse> thisInteractionUsePtr);

			//Additional constructors for the containments back reference
			InteractionUseImpl(std::weak_ptr<uml::Interaction> par_enclosingInteraction);
			//Additional constructors for the containments back reference
			InteractionUseImpl(std::weak_ptr<uml::InteractionOperand> par_enclosingOperand);
			//Additional constructors for the containments back reference
			InteractionUseImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			InteractionUseImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~InteractionUseImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The InteractionUse must cover all Lifelines of the enclosing Interaction that are common with the lifelines covered by the referred Interaction. Lifelines are common if they have the same selector and represents associationEnd values.
			let parentInteraction : Set(Interaction) = enclosingInteraction->asSet()->
			union(enclosingOperand.combinedFragment->closure(enclosingOperand.combinedFragment)->
			collect(enclosingInteraction).oclAsType(Interaction)->asSet()) in
			parentInteraction->size()=1 and let refInteraction : Interaction = refersTo in
			parentInteraction.covered-> forAll(intLifeline : Lifeline | refInteraction.covered->
			forAll( refLifeline : Lifeline | refLifeline.represents = intLifeline.represents and 
			(
			( refLifeline.selector.oclIsKindOf(LiteralString) implies
			  intLifeline.selector.oclIsKindOf(LiteralString) and 
			  refLifeline.selector.oclAsType(LiteralString).value = intLifeline.selector.oclAsType(LiteralString).value ) and
			( refLifeline.selector.oclIsKindOf(LiteralInteger) implies
			  intLifeline.selector.oclIsKindOf(LiteralInteger) and 
			  refLifeline.selector.oclAsType(LiteralInteger).value = intLifeline.selector.oclAsType(LiteralInteger).value )
			)
			 implies self.covered->asSet()->includes(intLifeline)))
			*/
			 
			virtual bool all_lifelines(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			The arguments must only be constants, parameters of the enclosing Interaction or attributes of the classifier owning the enclosing Interaction.
			*/
			 
			virtual bool arguments_are_constants(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			The arguments of the InteractionUse must correspond to parameters of the referred Interaction.
			*/
			 
			virtual bool arguments_correspond_to_parameters(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			Actual Gates of the InteractionUse must match Formal Gates of the referred Interaction. Gates match when their names are equal and their messages correspond.
			actualGate->notEmpty() implies 
			refersTo.formalGate->forAll( fg : Gate | self.actualGate->select(matches(fg))->size()=1) and
			self.actualGate->forAll(ag : Gate | refersTo.formalGate->select(matches(ag))->size()=1)
			*/
			 
			virtual bool gates_match(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			The returnValueRecipient must be a Property of a ConnectableElement that is represented by a Lifeline covered by this InteractionUse.
			returnValueRecipient->asSet()->notEmpty() implies
			let covCE : Set(ConnectableElement) = covered.represents->asSet() in 
			covCE->notEmpty() and let classes:Set(Classifier) = covCE.type.oclIsKindOf(Classifier).oclAsType(Classifier)->asSet() in 
			let allProps : Set(Property) = classes.attribute->union(classes.allParents().attribute)->asSet() in 
			allProps->includes(returnValueRecipient)
			*/
			 
			virtual bool returnValueRecipient_coverage(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			The type of the returnValue must correspond to the type of the returnValueRecipient.
			returnValue.type->asSequence()->notEmpty() implies returnValue.type->asSequence()->first() = returnValueRecipient.type->asSequence()->first()
			*/
			 
			virtual bool returnValue_type_recipient_correspondence(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The actual gates of the InteractionUse.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Gate, uml::Element>> getActualGate() const ;
			/*!
			The actual arguments of the Interaction.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ValueSpecification, uml::Element>> getArgument() const ;
			/*!
			Refers to the Interaction that defines its meaning.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::Interaction> getRefersTo() const ;
			/*!
			Refers to the Interaction that defines its meaning.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setRefersTo(std::shared_ptr<uml::Interaction>) ;
			/*!
			The value of the executed Interaction.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::ValueSpecification> getReturnValue() const ;
			/*!
			The value of the executed Interaction.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setReturnValue(std::shared_ptr<uml::ValueSpecification>) ;
			/*!
			The recipient of the return value.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::Property> getReturnValueRecipient() const ;
			/*!
			The recipient of the return value.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setReturnValueRecipient(std::shared_ptr<uml::Property>) ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			
			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual std::shared_ptr<Any> eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, std::shared_ptr<Any> newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments) ;

		private:
			std::weak_ptr<uml::InteractionUse> m_thisInteractionUsePtr;
	};
}
#endif /* end of include guard: UML_INTERACTIONUSEINTERACTIONUSEIMPL_HPP */
