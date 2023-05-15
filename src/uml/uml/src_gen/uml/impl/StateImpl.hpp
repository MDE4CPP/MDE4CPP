//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_STATESTATEIMPL_HPP
#define UML_STATESTATEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../State.hpp"

#include "uml/impl/NamespaceImpl.hpp"
#include "uml/impl/RedefinableElementImpl.hpp"
#include "uml/impl/VertexImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API StateImpl : virtual public NamespaceImpl, virtual public RedefinableElementImpl, virtual public VertexImpl, virtual public State 
	{
		public: 
			StateImpl(const StateImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			StateImpl& operator=(StateImpl const&); 

		protected:
			friend class umlFactoryImpl;
			StateImpl();
			virtual std::shared_ptr<uml::State> getThisStatePtr() const;
			virtual void setThisStatePtr(std::weak_ptr<uml::State> thisStatePtr);

			//Additional constructors for the containments back reference
			StateImpl(std::weak_ptr<uml::Region> par_container);
			//Additional constructors for the containments back reference
			StateImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			StateImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~StateImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			A composite State is a State with at least one Region.
			result = (region->notEmpty())
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual bool isComposite() ;
			/*!
			An orthogonal State is a composite state with at least 2 regions.
			result = (region->size () > 1)
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual bool isOrthogonal() ;
			/*!
			A simple State is a State without any regions.
			result = ((region->isEmpty()) and not isSubmachineState())
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual bool isSimple() ;
			/*!
			Only submachine State references another StateMachine.
			result = (submachine <> null)
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual bool isSubmachineState() ;
			/*!
			The redefinition context of a State is the nearest containing StateMachine.
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
			A state with isComposite=true is said to be a composite State. A composite State is a State that contains at least one Region.
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual bool getIsComposite() const ;
			/*!
			A State with isOrthogonal=true is said to be an orthogonal composite State An orthogonal composite State contains two or more Regions.
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual bool getIsOrthogonal() const ;
			/*!
			A State with isSimple=true is said to be a simple State A simple State does not have any Regions and it does not refer to any submachine StateMachine.
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual bool getIsSimple() const ;
			/*!
			A State with isSubmachineState=true is said to be a submachine State Such a State refers to another StateMachine(submachine).
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual bool getIsSubmachineState() const ;
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The entry and exit connection points used in conjunction with this (submachine) State, i.e., as targets and sources, respectively, in the Region with the submachine State. A connection point reference references the corresponding definition of a connection point Pseudostate in the StateMachine referenced by the submachine State.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ConnectionPointReference, uml::NamedElement>> getConnection() const ;
			/*!
			The entry and exit Pseudostates of a composite State. These can only be entry or exit Pseudostates, and they must have different names. They can only be defined for composite States.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Pseudostate, uml::NamedElement>> getConnectionPoint() const ;
			/*!
			A list of Triggers that are candidates to be retained by the StateMachine if they trigger no Transitions out of the State (not consumed). A deferred Trigger is retained until the StateMachine reaches a State configuration where it is no longer deferred.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Trigger, uml::Element>> getDeferrableTrigger() const ;
			/*!
			An optional Behavior that is executed while being in the State. The execution starts when this State is entered, and ceases either by itself when done, or when the State is exited, whichever comes first.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<uml::Behavior> getDoActivity() const ;
			/*!
			An optional Behavior that is executed while being in the State. The execution starts when this State is entered, and ceases either by itself when done, or when the State is exited, whichever comes first.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setDoActivity(std::shared_ptr<uml::Behavior>) ;
			/*!
			An optional Behavior that is executed whenever this State is entered regardless of the Transition taken to reach the State. If defined, entry Behaviors are always executed to completion prior to any internal Behavior or Transitions performed within the State.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<uml::Behavior> getEntry() const ;
			/*!
			An optional Behavior that is executed whenever this State is entered regardless of the Transition taken to reach the State. If defined, entry Behaviors are always executed to completion prior to any internal Behavior or Transitions performed within the State.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setEntry(std::shared_ptr<uml::Behavior>) ;
			/*!
			An optional Behavior that is executed whenever this State is exited regardless of which Transition was taken out of the State. If defined, exit Behaviors are always executed to completion only after all internal and transition Behaviors have completed execution.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<uml::Behavior> getExit() const ;
			/*!
			An optional Behavior that is executed whenever this State is exited regardless of which Transition was taken out of the State. If defined, exit Behaviors are always executed to completion only after all internal and transition Behaviors have completed execution.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setExit(std::shared_ptr<uml::Behavior>) ;
			/*!
			The State of which this State is a redefinition.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<uml::State> getRedefinedState() const ;
			/*!
			The State of which this State is a redefinition.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setRedefinedState(std::shared_ptr<uml::State>) ;
			/*!
			The Regions owned directly by the State.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Region, uml::NamedElement>> getRegion() const ;
			/*!
			Specifies conditions that are always true when this State is the current State. In ProtocolStateMachines state invariants are additional conditions to the preconditions of the outgoing Transitions, and to the postcondition of the incoming Transitions.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<uml::Constraint> getStateInvariant() const ;
			/*!
			Specifies conditions that are always true when this State is the current State. In ProtocolStateMachines state invariants are additional conditions to the preconditions of the outgoing Transitions, and to the postcondition of the incoming Transitions.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setStateInvariant(std::shared_ptr<uml::Constraint>) ;
			/*!
			The StateMachine that is to be inserted in place of the (submachine) State.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<uml::StateMachine> getSubmachine() const ;
			/*!
			The StateMachine that is to be inserted in place of the (submachine) State.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setSubmachine(std::shared_ptr<uml::StateMachine>) ;
			
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
			std::weak_ptr<uml::State> m_thisStatePtr;
	};
}
#endif /* end of include guard: UML_STATESTATEIMPL_HPP */
