//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CONSIDERIGNOREFRAGMENT_HPP
#define UML_CONSIDERIGNOREFRAGMENT_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 

class AnyObject;
typedef std::shared_ptr<AnyObject> Any;

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
	class Gate;
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
#include "uml/CombinedFragment.hpp"

// enum includes
#include "uml/InteractionOperatorKind.hpp"

#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A ConsiderIgnoreFragment is a kind of CombinedFragment that is used for the consider and ignore cases, which require lists of pertinent Messages to be specified.
	<p>From package UML::Interactions.</p>
	*/
	
	class UML_API ConsiderIgnoreFragment: virtual public CombinedFragment
	{
		public:
 			ConsiderIgnoreFragment(const ConsiderIgnoreFragment &) {}

		protected:
			ConsiderIgnoreFragment(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ConsiderIgnoreFragment() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The interaction operator of a ConsiderIgnoreFragment must be either 'consider' or 'ignore'.
			(interactionOperator =  InteractionOperatorKind::consider) or (interactionOperator =  InteractionOperatorKind::ignore)
			*/
			 
			virtual bool consider_or_ignore(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;/*!
			The NamedElements must be of a type of element that can be a signature for a message (i.e.., an Operation, or a Signal).
			message->forAll(m | m.oclIsKindOf(Operation) or m.oclIsKindOf(Signal))
			*/
			 
			virtual bool type(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			//*********************************
			// Attributes Getter & Setter
			//*********************************
			
			//*********************************
			// References Getter & Setter
			//*********************************
			/*!
			The set of messages that apply to this fragment.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::NamedElement>> getMessage() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The set of messages that apply to this fragment.
			<p>From package UML::Interactions.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::NamedElement>> m_message;

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const = 0;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_CONSIDERIGNOREFRAGMENT_HPP */
