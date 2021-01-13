//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INTERACTIONFRAGMENT_HPP
#define UML_INTERACTIONFRAGMENT_HPP

#include <list>
#include <memory>
#include <string>


// forward declarations
template<class T> class Bag; 
template<class T, class ... U> class Subset;



//*********************************
// generated Includes

#include <map>

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
}

namespace uml 
{
	class Dependency;
}

namespace uml 
{
	class Element;
}

namespace uml 
{
	class GeneralOrdering;
}

namespace uml 
{
	class Interaction;
}

namespace uml 
{
	class InteractionOperand;
}

namespace uml 
{
	class Lifeline;
}

namespace uml 
{
	class NamedElement;
}

namespace uml 
{
	class Namespace;
}

namespace uml 
{
	class StringExpression;
}

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
	
	class InteractionFragment:virtual public NamedElement
	{
		public:
 			InteractionFragment(const InteractionFragment &) {}
			InteractionFragment& operator=(InteractionFragment const&) = delete;

		protected:
			InteractionFragment(){}


			//Additional constructors for the containments back reference

			InteractionFragment(std::weak_ptr<uml::Interaction > par_enclosingInteraction);

			//Additional constructors for the containments back reference

			InteractionFragment(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand);

			//Additional constructors for the containments back reference

			InteractionFragment(std::weak_ptr<uml::Namespace > par_namespace);

			//Additional constructors for the containments back reference

			InteractionFragment(std::weak_ptr<uml::Element > par_owner);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~InteractionFragment() {}

			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
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
			
			virtual std::weak_ptr<uml::Interaction > getEnclosingInteraction() const = 0;
			
			/*!
			The Interaction enclosing this InteractionFragment.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setEnclosingInteraction(std::shared_ptr<uml::Interaction> _enclosingInteraction) = 0;
			
			/*!
			The operand enclosing this InteractionFragment (they may nest recursively).
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::weak_ptr<uml::InteractionOperand > getEnclosingOperand() const = 0;
			
			/*!
			The operand enclosing this InteractionFragment (they may nest recursively).
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setEnclosingOperand(std::shared_ptr<uml::InteractionOperand> _enclosingOperand) = 0;
			
			/*!
			The general ordering relationships contained in this fragment.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::GeneralOrdering, uml::Element>> getGeneralOrdering() const = 0;
			
			
			

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
			
			mutable std::shared_ptr<Bag<uml::Lifeline>> m_covered;/*!
			The Interaction enclosing this InteractionFragment.
			<p>From package UML::Interactions.</p>
			*/
			
			std::weak_ptr<uml::Interaction > m_enclosingInteraction;/*!
			The operand enclosing this InteractionFragment (they may nest recursively).
			<p>From package UML::Interactions.</p>
			*/
			
			std::weak_ptr<uml::InteractionOperand > m_enclosingOperand;/*!
			The general ordering relationships contained in this fragment.
			<p>From package UML::Interactions.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::GeneralOrdering, uml::Element>> m_generalOrdering;

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace > getNamespace() const = 0;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element > getOwner() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_INTERACTIONFRAGMENT_HPP */
