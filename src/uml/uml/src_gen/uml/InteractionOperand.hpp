//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INTERACTIONOPERAND_HPP
#define UML_INTERACTIONOPERAND_HPP

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
	class Comment;
	class Constraint;
	class Dependency;
	class ElementImport;
	class GeneralOrdering;
	class Interaction;
	class InteractionConstraint;
	class Lifeline;
	class PackageImport;
	class PackageableElement;
	class StringExpression;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/InteractionFragment.hpp"
#include "uml/Namespace.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	An InteractionOperand is contained in a CombinedFragment. An InteractionOperand represents one operand of the expression given by the enclosing CombinedFragment.
	<p>From package UML::Interactions.</p>
	*/
	
	class UML_API InteractionOperand: virtual public InteractionFragment, virtual public Namespace
	{
		public:
 			InteractionOperand(const InteractionOperand &) {}

		protected:
			InteractionOperand(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~InteractionOperand() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The guard must contain only references to values local to the Lifeline on which it resides, or values global to the whole Interaction.
			*/
			 
			virtual bool guard_contain_references(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			The guard must be placed directly prior to (above) the OccurrenceSpecification that will become the first OccurrenceSpecification within this InteractionOperand.
			*/
			 
			virtual bool guard_directly_prior(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;

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
			
			virtual std::shared_ptr<Subset<uml::InteractionFragment, uml::NamedElement>> getFragment() const = 0;
			/*!
			Constraint of the operand.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::InteractionConstraint> getGuard() const = 0;
			/*!
			Constraint of the operand.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setGuard(std::shared_ptr<uml::InteractionConstraint>) = 0;

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
			The fragments of the operand.
			<p>From package UML::Interactions.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::InteractionFragment, uml::NamedElement>> m_fragment;
			/*!
			Constraint of the operand.
			<p>From package UML::Interactions.</p>
			*/
			
			std::shared_ptr<uml::InteractionConstraint> m_guard;
	};
}
#endif /* end of include guard: UML_INTERACTIONOPERAND_HPP */
