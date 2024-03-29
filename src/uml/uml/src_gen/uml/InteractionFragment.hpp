//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INTERACTIONFRAGMENT_HPP
#define UML_INTERACTIONFRAGMENT_HPP


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
	class GeneralOrdering;
	class Interaction;
	class InteractionOperand;
	class Lifeline;
	class Namespace;
	class StringExpression;
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
	InteractionFragment is an abstract notion of the most general interaction unit. An InteractionFragment is a piece of an Interaction. Each InteractionFragment is conceptually like an Interaction by itself.
	<p>From package UML::Interactions.</p>
	*/
	
	class UML_API InteractionFragment: virtual public NamedElement
	{
		public:
 			InteractionFragment(const InteractionFragment &) {}

		protected:
			InteractionFragment(){}
			//Additional constructors for the containments back reference
			InteractionFragment(std::weak_ptr<uml::Interaction> par_enclosingInteraction);

			//Additional constructors for the containments back reference
			InteractionFragment(std::weak_ptr<uml::InteractionOperand> par_enclosingOperand);

			//Additional constructors for the containments back reference
			InteractionFragment(std::weak_ptr<uml::Namespace> par_namespace);

			//Additional constructors for the containments back reference
			InteractionFragment(std::weak_ptr<uml::Element> par_owner);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~InteractionFragment() {}

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
			References the Lifelines that the InteractionFragment involves.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Lifeline>> getCovered() const = 0;
			/*!
			The Interaction enclosing this InteractionFragment.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::weak_ptr<uml::Interaction> getEnclosingInteraction() const = 0;
			/*!
			The Interaction enclosing this InteractionFragment.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setEnclosingInteraction(std::weak_ptr<uml::Interaction>) = 0;
			/*!
			The operand enclosing this InteractionFragment (they may nest recursively).
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::weak_ptr<uml::InteractionOperand> getEnclosingOperand() const = 0;
			/*!
			The operand enclosing this InteractionFragment (they may nest recursively).
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setEnclosingOperand(std::weak_ptr<uml::InteractionOperand>) = 0;
			/*!
			The general ordering relationships contained in this fragment.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::GeneralOrdering, uml::Element>> getGeneralOrdering() const = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
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
			References the Lifelines that the InteractionFragment involves.
			<p>From package UML::Interactions.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::Lifeline>> m_covered;
			/*!
			The Interaction enclosing this InteractionFragment.
			<p>From package UML::Interactions.</p>
			*/
			
			std::weak_ptr<uml::Interaction> m_enclosingInteraction;
			/*!
			The operand enclosing this InteractionFragment (they may nest recursively).
			<p>From package UML::Interactions.</p>
			*/
			
			std::weak_ptr<uml::InteractionOperand> m_enclosingOperand;
			/*!
			The general ordering relationships contained in this fragment.
			<p>From package UML::Interactions.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::GeneralOrdering, uml::Element>> m_generalOrdering;
	};
}
#endif /* end of include guard: UML_INTERACTIONFRAGMENT_HPP */
