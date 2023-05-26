//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_TRANSITIONTRANSITIONIMPL_HPP
#define UML_TRANSITIONTRANSITIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Transition.hpp"

#include "uml/impl/NamespaceImpl.hpp"
#include "uml/impl/RedefinableElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API TransitionImpl : virtual public NamespaceImpl, virtual public RedefinableElementImpl, virtual public Transition 
	{
		public: 
			TransitionImpl(const TransitionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			TransitionImpl& operator=(TransitionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			TransitionImpl();
			virtual std::shared_ptr<uml::Transition> getThisTransitionPtr() const;
			virtual void setThisTransitionPtr(std::weak_ptr<uml::Transition> thisTransitionPtr);

			//Additional constructors for the containments back reference
			TransitionImpl(std::weak_ptr<uml::Region> par_container);
			//Additional constructors for the containments back reference
			TransitionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			TransitionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~TransitionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The query containingStateMachine() returns the StateMachine that contains the Transition either directly or transitively.
			result = (container.containingStateMachine())
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual std::shared_ptr<uml::StateMachine> containingStateMachine() ;
			/*!
			The redefinition context of a Transition is the nearest containing StateMachine.
			result = (let sm : StateMachine = containingStateMachine() in
			if sm._'context' = null or sm.general->notEmpty() then
			  sm
			else
			  sm._'context'
			endif)
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual std::shared_ptr<uml::Classifier> redefinitionContext() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Indicates the precise type of the Transition.
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual uml::TransitionKind getKind() const ;
			/*!
			Indicates the precise type of the Transition.
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual void setKind (uml::TransitionKind _kind);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			Designates the Region that owns this Transition.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::weak_ptr<uml::Region> getContainer() const ;
			/*!
			Designates the Region that owns this Transition.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setContainer(std::weak_ptr<uml::Region>) ;
			/*!
			Specifies an optional behavior to be performed when the Transition fires.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<uml::Behavior> getEffect() const ;
			/*!
			Specifies an optional behavior to be performed when the Transition fires.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setEffect(const std::shared_ptr<uml::Behavior>&) ;
			/*!
			A guard is a Constraint that provides a fine-grained control over the firing of the Transition. The guard is evaluated when an Event occurrence is dispatched by the StateMachine. If the guard is true at that time, the Transition may be enabled, otherwise, it is disabled. Guards should be pure expressions without side effects. Guard expressions with side effects are ill formed.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<uml::Constraint> getGuard() const ;
			/*!
			A guard is a Constraint that provides a fine-grained control over the firing of the Transition. The guard is evaluated when an Event occurrence is dispatched by the StateMachine. If the guard is true at that time, the Transition may be enabled, otherwise, it is disabled. Guards should be pure expressions without side effects. Guard expressions with side effects are ill formed.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setGuard(const std::shared_ptr<uml::Constraint>&) ;
			/*!
			The Transition that is redefined by this Transition.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<uml::Transition> getRedefinedTransition() const ;
			/*!
			The Transition that is redefined by this Transition.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setRedefinedTransition(const std::shared_ptr<uml::Transition>&) ;
			/*!
			Designates the originating Vertex (State or Pseudostate) of the Transition.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<uml::Vertex> getSource() const ;
			/*!
			Designates the originating Vertex (State or Pseudostate) of the Transition.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setSource(const std::shared_ptr<uml::Vertex>&) ;
			/*!
			Designates the target Vertex that is reached when the Transition is taken.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<uml::Vertex> getTarget() const ;
			/*!
			Designates the target Vertex that is reached when the Transition is taken.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setTarget(const std::shared_ptr<uml::Vertex>&) ;
			/*!
			Specifies the Triggers that may fire the transition.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Trigger, uml::Element>> getTrigger() const ;
			
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
			virtual bool eSet(int featureID, const std::shared_ptr<Any>& newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID,const std::shared_ptr<Bag<Any>>& arguments) ;

		private:
			std::weak_ptr<uml::Transition> m_thisTransitionPtr;
	};
}
#endif /* end of include guard: UML_TRANSITIONTRANSITIONIMPL_HPP */
