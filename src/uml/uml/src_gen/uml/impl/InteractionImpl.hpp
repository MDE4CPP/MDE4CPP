//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INTERACTIONINTERACTIONIMPL_HPP
#define UML_INTERACTIONINTERACTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Interaction.hpp"

#include "uml/impl/BehaviorImpl.hpp"
#include "uml/impl/InteractionFragmentImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API InteractionImpl : virtual public BehaviorImpl, virtual public InteractionFragmentImpl, virtual public Interaction 
	{
		public: 
			InteractionImpl(const InteractionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			InteractionImpl& operator=(InteractionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			InteractionImpl();
			virtual std::shared_ptr<uml::Interaction> getThisInteractionPtr() const;
			virtual void setThisInteractionPtr(std::weak_ptr<uml::Interaction> thisInteractionPtr);

			//Additional constructors for the containments back reference
			InteractionImpl(std::weak_ptr<uml::BehavioredClassifier> par_behavioredClassifier);
			//Additional constructors for the containments back reference
			InteractionImpl(std::weak_ptr<uml::Interaction> par_enclosingInteraction);
			//Additional constructors for the containments back reference
			InteractionImpl(std::weak_ptr<uml::InteractionOperand> par_enclosingOperand);
			//Additional constructors for the containments back reference
			InteractionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			InteractionImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			InteractionImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id);
			//Additional constructors for the containments back reference
			InteractionImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference

		public:
			//destructor
			virtual ~InteractionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			An Interaction instance must not be contained within another Interaction instance.
			enclosingInteraction->isEmpty()
			*/
			 
			virtual bool not_contained(const Any& diagnostics, std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			Actions owned by the Interaction.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::Action, uml::Element>>& getAction() const ;
			/*!
			Specifies the gates that form the message interface between this Interaction and any InteractionUses which reference it.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::Gate, uml::NamedElement>>& getFormalGate() const ;
			/*!
			The ordered set of fragments in the Interaction.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::InteractionFragment, uml::NamedElement>>& getFragment() const ;
			/*!
			Specifies the participants in this Interaction.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::Lifeline, uml::NamedElement>>& getLifeline() const ;
			/*!
			The Messages contained in this Interaction.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::Message, uml::NamedElement>>& getMessage() const ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			All of the Properties that are direct (i.e., not inherited or imported) attributes of the Classifier.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> getAttribute() const ;
			/*!
			Specifies each Feature directly defined in the classifier. Note that there may be members of the Classifier that are of the type Feature but are not included, e.g., inherited features.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> getFeature() const ;
			/*!
			A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::NamedElement>> getMember() const ;
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const ;
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;
			/*!
			A collection of NamedElements owned by the Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement>> getOwnedMember() const ;
			/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ;
			/*!
			The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const ;
			/*!
			The contexts that this element may be redefined from.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Classifier>> getRedefinitionContext() const ;
			/*!
			The roles that instances may play in this StructuredClassifier.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement>> getRole() const ;
			
			
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
			virtual const std::shared_ptr<ecore::EClass>& eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, const Any& newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments) ;

		private:
			std::weak_ptr<uml::Interaction> m_thisInteractionPtr;
	};
}
#endif /* end of include guard: UML_INTERACTIONINTERACTIONIMPL_HPP */
