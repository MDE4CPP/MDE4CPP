//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INTERACTIONOPERAND_HPP
#define UML_INTERACTIONOPERAND_HPP


#include <memory>
#include <string>
// forward declarations
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
	
	class UML_API InteractionOperand : virtual public InteractionFragment, virtual public Namespace
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
			
			virtual void setGuard(const std::shared_ptr<uml::InteractionConstraint>&) = 0;

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
