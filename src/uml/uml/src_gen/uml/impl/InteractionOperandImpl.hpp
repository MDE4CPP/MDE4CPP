//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INTERACTIONOPERANDINTERACTIONOPERANDIMPL_HPP
#define UML_INTERACTIONOPERANDINTERACTIONOPERANDIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../InteractionOperand.hpp"

#include "uml/impl/InteractionFragmentImpl.hpp"
#include "uml/impl/NamespaceImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API InteractionOperandImpl : virtual public InteractionFragmentImpl, virtual public NamespaceImpl, virtual public InteractionOperand 
	{
		public: 
			InteractionOperandImpl(const InteractionOperandImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			InteractionOperandImpl& operator=(InteractionOperandImpl const&); 

		protected:
			friend class umlFactoryImpl;
			InteractionOperandImpl();
			virtual std::shared_ptr<uml::InteractionOperand> getThisInteractionOperandPtr() const;
			virtual void setThisInteractionOperandPtr(std::weak_ptr<uml::InteractionOperand> thisInteractionOperandPtr);

			//Additional constructors for the containments back reference
			InteractionOperandImpl(std::weak_ptr<uml::Interaction> par_enclosingInteraction);
			//Additional constructors for the containments back reference
			InteractionOperandImpl(std::weak_ptr<uml::InteractionOperand> par_enclosingOperand);
			//Additional constructors for the containments back reference
			InteractionOperandImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			InteractionOperandImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~InteractionOperandImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The guard must contain only references to values local to the Lifeline on which it resides, or values global to the whole Interaction.
			*/
			 
			virtual bool guard_contain_references(const Any& diagnostics, std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			The guard must be placed directly prior to (above) the OccurrenceSpecification that will become the first OccurrenceSpecification within this InteractionOperand.
			*/
			 
			virtual bool guard_directly_prior(const Any& diagnostics, std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The fragments of the operand.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::InteractionFragment, uml::NamedElement>>& getFragment() const ;
			/*!
			Constraint of the operand.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual const std::shared_ptr<uml::InteractionConstraint>& getGuard() const ;
			/*!
			Constraint of the operand.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setGuard(const std::shared_ptr<uml::InteractionConstraint>&) ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
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
			std::weak_ptr<uml::InteractionOperand> m_thisInteractionOperandPtr;
	};
}
#endif /* end of include guard: UML_INTERACTIONOPERANDINTERACTIONOPERANDIMPL_HPP */
