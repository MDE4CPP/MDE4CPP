//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_TRANSITION_HPP
#define UML_TRANSITION_HPP


#include <memory>
#include <string>
// forward declarations
template<class T, class ... U> class Subset;
template<class T, class ... U> class SubsetUnion;


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
	class Behavior;
	class Classifier;
	class Comment;
	class Constraint;
	class Dependency;
	class ElementImport;
	class PackageImport;
	class PackageableElement;
	class Region;
	class StateMachine;
	class StringExpression;
	class Trigger;
	class Vertex;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Namespace.hpp"
#include "uml/RedefinableElement.hpp"

// enum includes
#include "uml/TransitionKind.hpp"
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A Transition represents an arc between exactly one source Vertex and exactly one Target vertex (the source and targets may be the same Vertex). It may form part of a compound transition, which takes the StateMachine from one steady State configuration to another, representing the full response of the StateMachine to an occurrence of an Event that triggered it.
	<p>From package UML::StateMachines.</p>
	*/
	
	class UML_API Transition : virtual public Namespace, virtual public RedefinableElement
	{
		public:
 			Transition(const Transition &) {}

		protected:
			Transition(){}
			//Additional constructors for the containments back reference
			Transition(std::weak_ptr<uml::Region> par_container);

			//Additional constructors for the containments back reference
			Transition(std::weak_ptr<uml::Namespace> par_namespace);

			//Additional constructors for the containments back reference
			Transition(std::weak_ptr<uml::Element> par_owner);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Transition() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The query containingStateMachine() returns the StateMachine that contains the Transition either directly or transitively.
			result = (container.containingStateMachine())
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual std::shared_ptr<uml::StateMachine> containingStateMachine() = 0;
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
			 
			virtual std::shared_ptr<uml::Classifier> redefinitionContext() = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Indicates the precise type of the Transition.
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual uml::TransitionKind getKind() const = 0;
			/*!
			Indicates the precise type of the Transition.
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual void setKind (uml::TransitionKind _kind)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			Designates the Region that owns this Transition.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::weak_ptr<uml::Region> getContainer() const = 0;
			/*!
			Designates the Region that owns this Transition.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setContainer(std::weak_ptr<uml::Region>) = 0;
			/*!
			Specifies an optional behavior to be performed when the Transition fires.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<uml::Behavior> getEffect() const = 0;
			/*!
			Specifies an optional behavior to be performed when the Transition fires.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setEffect(const std::shared_ptr<uml::Behavior>&) = 0;
			/*!
			A guard is a Constraint that provides a fine-grained control over the firing of the Transition. The guard is evaluated when an Event occurrence is dispatched by the StateMachine. If the guard is true at that time, the Transition may be enabled, otherwise, it is disabled. Guards should be pure expressions without side effects. Guard expressions with side effects are ill formed.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<uml::Constraint> getGuard() const = 0;
			/*!
			A guard is a Constraint that provides a fine-grained control over the firing of the Transition. The guard is evaluated when an Event occurrence is dispatched by the StateMachine. If the guard is true at that time, the Transition may be enabled, otherwise, it is disabled. Guards should be pure expressions without side effects. Guard expressions with side effects are ill formed.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setGuard(const std::shared_ptr<uml::Constraint>&) = 0;
			/*!
			The Transition that is redefined by this Transition.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<uml::Transition> getRedefinedTransition() const = 0;
			/*!
			The Transition that is redefined by this Transition.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setRedefinedTransition(const std::shared_ptr<uml::Transition>&) = 0;
			/*!
			Designates the originating Vertex (State or Pseudostate) of the Transition.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<uml::Vertex> getSource() const = 0;
			/*!
			Designates the originating Vertex (State or Pseudostate) of the Transition.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setSource(const std::shared_ptr<uml::Vertex>&) = 0;
			/*!
			Designates the target Vertex that is reached when the Transition is taken.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<uml::Vertex> getTarget() const = 0;
			/*!
			Designates the target Vertex that is reached when the Transition is taken.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setTarget(const std::shared_ptr<uml::Vertex>&) = 0;
			/*!
			Specifies the Triggers that may fire the transition.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Trigger, uml::Element>> getTrigger() const = 0;

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
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			Indicates the precise type of the Transition.
			<p>From package UML::StateMachines.</p>
			*/
			
			uml::TransitionKind m_kind= uml::TransitionKind::EXTERNAL;
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			Designates the Region that owns this Transition.
			<p>From package UML::StateMachines.</p>
			*/
			
			std::weak_ptr<uml::Region> m_container;
			/*!
			Specifies an optional behavior to be performed when the Transition fires.
			<p>From package UML::StateMachines.</p>
			*/
			
			std::shared_ptr<uml::Behavior> m_effect;
			/*!
			A guard is a Constraint that provides a fine-grained control over the firing of the Transition. The guard is evaluated when an Event occurrence is dispatched by the StateMachine. If the guard is true at that time, the Transition may be enabled, otherwise, it is disabled. Guards should be pure expressions without side effects. Guard expressions with side effects are ill formed.
			<p>From package UML::StateMachines.</p>
			*/
			
			std::shared_ptr<uml::Constraint> m_guard;
			/*!
			The Transition that is redefined by this Transition.
			<p>From package UML::StateMachines.</p>
			*/
			
			std::shared_ptr<uml::Transition> m_redefinedTransition;
			/*!
			Designates the originating Vertex (State or Pseudostate) of the Transition.
			<p>From package UML::StateMachines.</p>
			*/
			
			std::shared_ptr<uml::Vertex> m_source;
			/*!
			Designates the target Vertex that is reached when the Transition is taken.
			<p>From package UML::StateMachines.</p>
			*/
			
			std::shared_ptr<uml::Vertex> m_target;
			/*!
			Specifies the Triggers that may fire the transition.
			<p>From package UML::StateMachines.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Trigger, uml::Element>> m_trigger;
	};
}
#endif /* end of include guard: UML_TRANSITION_HPP */
