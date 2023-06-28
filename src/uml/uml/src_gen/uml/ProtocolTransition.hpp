//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_PROTOCOLTRANSITION_HPP
#define UML_PROTOCOLTRANSITION_HPP


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
	class Behavior;
	class Classifier;
	class Comment;
	class Constraint;
	class Dependency;
	class ElementImport;
	class Operation;
	class PackageImport;
	class PackageableElement;
	class Region;
	class StringExpression;
	class Trigger;
	class Vertex;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Transition.hpp"

// enum includes
#include "uml/TransitionKind.hpp"
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A ProtocolTransition specifies a legal Transition for an Operation. Transitions of ProtocolStateMachines have the following information: a pre-condition (guard), a Trigger, and a post-condition. Every ProtocolTransition is associated with at most one BehavioralFeature belonging to the context Classifier of the ProtocolStateMachine.
	<p>From package UML::StateMachines.</p>
	*/
	
	class UML_API ProtocolTransition : virtual public Transition
	{
		public:
 			ProtocolTransition(const ProtocolTransition &) {}

		protected:
			ProtocolTransition(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ProtocolTransition() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			Derivation for ProtocolTransition::/referred
			result = (trigger->collect(event)->select(oclIsKindOf(CallEvent))->collect(oclAsType(CallEvent).operation)->asSet())
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::Operation>> getReferreds() = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			Specifies the post condition of the Transition which is the Condition that should be obtained once the Transition is triggered. This post condition is part of the post condition of the Operation connected to the Transition.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual const std::shared_ptr<uml::Constraint>& getPostCondition() const = 0;
			/*!
			Specifies the post condition of the Transition which is the Condition that should be obtained once the Transition is triggered. This post condition is part of the post condition of the Operation connected to the Transition.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setPostCondition(const std::shared_ptr<uml::Constraint>&) = 0;
			/*!
			Specifies the precondition of the Transition. It specifies the Condition that should be verified before triggering the Transition. This guard condition added to the source State will be evaluated as part of the precondition of the Operation referred by the Transition if any.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual const std::shared_ptr<uml::Constraint>& getPreCondition() const = 0;
			/*!
			Specifies the precondition of the Transition. It specifies the Condition that should be verified before triggering the Transition. This guard condition added to the source State will be evaluated as part of the precondition of the Operation referred by the Transition if any.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setPreCondition(const std::shared_ptr<uml::Constraint>&) = 0;
			/*!
			This association refers to the associated Operation. It is derived from the Operation of the CallEvent Trigger when applicable.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual const std::shared_ptr<Bag<uml::Operation>>& getReferred() const = 0;

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
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			Specifies the post condition of the Transition which is the Condition that should be obtained once the Transition is triggered. This post condition is part of the post condition of the Operation connected to the Transition.
			<p>From package UML::StateMachines.</p>
			*/
			
			std::shared_ptr<uml::Constraint> m_postCondition;
			/*!
			Specifies the precondition of the Transition. It specifies the Condition that should be verified before triggering the Transition. This guard condition added to the source State will be evaluated as part of the precondition of the Operation referred by the Transition if any.
			<p>From package UML::StateMachines.</p>
			*/
			
			std::shared_ptr<uml::Constraint> m_preCondition;
			/*!
			This association refers to the associated Operation. It is derived from the Operation of the CallEvent Trigger when applicable.
			<p>From package UML::StateMachines.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::Operation>> m_referred;
	};
}
#endif /* end of include guard: UML_PROTOCOLTRANSITION_HPP */
