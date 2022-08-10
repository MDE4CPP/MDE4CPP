//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_REGION_HPP
#define UML_REGION_HPP

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
	class Classifier;
	class Comment;
	class Constraint;
	class Dependency;
	class ElementImport;
	class PackageImport;
	class PackageableElement;
	class State;
	class StateMachine;
	class StringExpression;
	class Transition;
	class Vertex;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Namespace.hpp"
#include "uml/RedefinableElement.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A Region is a top-level part of a StateMachine or a composite State, that serves as a container for the Vertices and Transitions of the StateMachine. A StateMachine or composite State may contain multiple Regions representing behaviors that may occur in parallel.
	<p>From package UML::StateMachines.</p>
	*/
	
	class UML_API Region : virtual public Namespace, virtual public RedefinableElement
	{
		public:
 			Region(const Region &) {}

		protected:
			Region(){}
			//Additional constructors for the containments back reference
			Region(std::weak_ptr<uml::Namespace> par_namespace);

			//Additional constructors for the containments back reference
			Region(std::weak_ptr<uml::Element> par_owner);

			//Additional constructors for the containments back reference
			Region(std::weak_ptr<uml::State> par_state);

			//Additional constructors for the containments back reference
			Region(std::weak_ptr<uml::StateMachine> par_stateMachine);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Region() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The operation belongsToPSM () checks if the Region belongs to a ProtocolStateMachine.
			result = (if  stateMachine <> null 
			then
			  stateMachine.oclIsKindOf(ProtocolStateMachine)
			else 
			  state <> null  implies  state.container.belongsToPSM()
			endif )
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual bool belongsToPSM() = 0;
			/*!
			The operation containingStateMachine() returns the StateMachine in which this Region is defined.
			result = (if stateMachine = null 
			then
			  state.containingStateMachine()
			else
			  stateMachine
			endif)
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual std::shared_ptr<uml::StateMachine> containingStateMachine() = 0;
			/*!
			A Region can have at most one deep history Vertex.
			self.subvertex->select (oclIsKindOf(Pseudostate))->collect(oclAsType(Pseudostate))->
			   select(kind = PseudostateKind::deepHistory)->size() <= 1
			*/
			 
			virtual bool deep_history_vertex(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			A Region can have at most one initial Vertex.
			self.subvertex->select (oclIsKindOf(Pseudostate))->collect(oclAsType(Pseudostate))->
			  select(kind = PseudostateKind::initial)->size() <= 1
			*/
			 
			virtual bool initial_vertex(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			If a Region is owned by a StateMachine, then it cannot also be owned by a State and vice versa.
			(stateMachine <> null implies state = null) and (state <> null implies stateMachine = null)
			*/
			 
			virtual bool owned(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			The redefinition context of a Region is the nearest containing StateMachine.
			result = (let sm : StateMachine = containingStateMachine() in
			if sm._'context' = null or sm.general->notEmpty() then
			  sm
			else
			  sm._'context'
			endif)
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual std::shared_ptr<uml::Classifier> redefinitionContext() = 0;
			/*!
			A Region can have at most one shallow history Vertex.
			subvertex->select(oclIsKindOf(Pseudostate))->collect(oclAsType(Pseudostate))->
			  select(kind = PseudostateKind::shallowHistory)->size() <= 1
			*/
			 
			virtual bool shallow_history_vertex(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The region of which this region is an extension.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<uml::Region> getExtendedRegion() const = 0;
			/*!
			The region of which this region is an extension.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setExtendedRegion(std::shared_ptr<uml::Region>) = 0;
			/*!
			The State that owns the Region. If a Region is owned by a State, then it cannot also be owned by a StateMachine.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::weak_ptr<uml::State> getState() const = 0;
			/*!
			The State that owns the Region. If a Region is owned by a State, then it cannot also be owned by a StateMachine.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setState(std::weak_ptr<uml::State>) = 0;
			/*!
			The StateMachine that owns the Region. If a Region is owned by a StateMachine, then it cannot also be owned by a State.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::weak_ptr<uml::StateMachine> getStateMachine() const = 0;
			/*!
			The StateMachine that owns the Region. If a Region is owned by a StateMachine, then it cannot also be owned by a State.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setStateMachine(std::weak_ptr<uml::StateMachine>) = 0;
			/*!
			The set of Vertices that are owned by this Region.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Vertex, uml::NamedElement>> getSubvertex() const = 0;
			/*!
			The set of Transitions owned by the Region.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Transition, uml::NamedElement>> getTransition() const = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
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
			The region of which this region is an extension.
			<p>From package UML::StateMachines.</p>
			*/
			
			std::shared_ptr<uml::Region> m_extendedRegion;
			/*!
			The State that owns the Region. If a Region is owned by a State, then it cannot also be owned by a StateMachine.
			<p>From package UML::StateMachines.</p>
			*/
			
			std::weak_ptr<uml::State> m_state;
			/*!
			The StateMachine that owns the Region. If a Region is owned by a StateMachine, then it cannot also be owned by a State.
			<p>From package UML::StateMachines.</p>
			*/
			
			std::weak_ptr<uml::StateMachine> m_stateMachine;
			/*!
			The set of Vertices that are owned by this Region.
			<p>From package UML::StateMachines.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Vertex, uml::NamedElement>> m_subvertex;
			/*!
			The set of Transitions owned by the Region.
			<p>From package UML::StateMachines.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Transition, uml::NamedElement>> m_transition;
	};
}
#endif /* end of include guard: UML_REGION_HPP */
