//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_VERTEX_HPP
#define UML_VERTEX_HPP


#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 
template<class T, class ... U> class Subset;


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
	class Dependency;
	class Namespace;
	class Region;
	class State;
	class StateMachine;
	class StringExpression;
	class Transition;
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
	A Vertex is an abstraction of a node in a StateMachine graph. It can be the source or destination of any number of Transitions.
	<p>From package UML::StateMachines.</p>
	*/
	
	class UML_API Vertex : virtual public NamedElement
	{
		public:
 			Vertex(const Vertex &) {}

		protected:
			Vertex(){}
			//Additional constructors for the containments back reference
			Vertex(std::weak_ptr<uml::Region> par_container);

			//Additional constructors for the containments back reference
			Vertex(std::weak_ptr<uml::Namespace> par_namespace);

			//Additional constructors for the containments back reference
			Vertex(std::weak_ptr<uml::Element> par_owner);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Vertex() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The operation containingStateMachine() returns the StateMachine in which this Vertex is defined.
			result = (if container <> null
			then
			-- the container is a region
			   container.containingStateMachine()
			else 
			   if (self.oclIsKindOf(Pseudostate)) and ((self.oclAsType(Pseudostate).kind = PseudostateKind::entryPoint) or (self.oclAsType(Pseudostate).kind = PseudostateKind::exitPoint)) then
			      self.oclAsType(Pseudostate).stateMachine
			   else 
			      if (self.oclIsKindOf(ConnectionPointReference)) then
			          self.oclAsType(ConnectionPointReference).state.containingStateMachine() -- no other valid cases possible
			      else 
			          null
			      endif
			   endif
			endif
			)
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual std::shared_ptr<uml::StateMachine> containingStateMachine() = 0;
			/*!
			Derivation for Vertex::/incoming.
			result = (Transition.allInstances()->select(target=self))
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::Transition>> getIncomings() = 0;
			/*!
			Derivation for Vertex::/outgoing
			result = (Transition.allInstances()->select(source=self))
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::Transition>> getOutgoings() = 0;
			/*!
			This utility query returns true if the Vertex is contained in the Region r (input argument).
			result = (if (container = r) then
				true
			else
				if (r.state->isEmpty()) then
					false
				else
					container.state.isContainedInRegion(r)
				endif
			endif)
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual bool isContainedInRegion(std::shared_ptr<uml::Region> r) = 0;
			/*!
			This utility operation returns true if the Vertex is contained in the State s (input argument).
			result = (if not s.isComposite() or container->isEmpty() then
				false
			else
				if container.state = s then 
					true
				else
					container.state.isContainedInState(s)
				endif
			endif)
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual bool isContainedInState(std::shared_ptr<uml::State> s) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The Region that contains this Vertex.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::weak_ptr<uml::Region> getContainer() const = 0;
			/*!
			The Region that contains this Vertex.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setContainer(std::weak_ptr<uml::Region>) = 0;
			/*!
			Specifies the Transitions entering this Vertex.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Transition>> getIncoming() const = 0;
			/*!
			Specifies the Transitions departing from this Vertex.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Transition>> getOutgoing() const = 0;

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
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The Region that contains this Vertex.
			<p>From package UML::StateMachines.</p>
			*/
			
			std::weak_ptr<uml::Region> m_container;
			/*!
			Specifies the Transitions entering this Vertex.
			<p>From package UML::StateMachines.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::Transition>> m_incoming;
			/*!
			Specifies the Transitions departing from this Vertex.
			<p>From package UML::StateMachines.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::Transition>> m_outgoing;
	};
}
#endif /* end of include guard: UML_VERTEX_HPP */
