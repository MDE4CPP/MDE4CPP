//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INTERACTION_HPP
#define UML_INTERACTION_HPP


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
	class Action;
	class BehavioralFeature;
	class CollaborationUse;
	class Comment;
	class ConnectableElement;
	class Connector;
	class Constraint;
	class Dependency;
	class ElementImport;
	class Extension;
	class Feature;
	class Gate;
	class GeneralOrdering;
	class Generalization;
	class GeneralizationSet;
	class InteractionOperand;
	class InterfaceRealization;
	class Lifeline;
	class Message;
	class Operation;
	class Package;
	class PackageImport;
	class Parameter;
	class ParameterSet;
	class Port;
	class Property;
	class Reception;
	class StringExpression;
	class Substitution;
	class TemplateBinding;
	class TemplateParameter;
	class TemplateSignature;
	class UseCase;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Behavior.hpp"
#include "uml/InteractionFragment.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	An Interaction is a unit of Behavior that focuses on the observable exchange of information between connectable elements.
	<p>From package UML::Interactions.</p>
	*/
	
	class UML_API Interaction : virtual public Behavior, virtual public InteractionFragment
	{
		public:
 			Interaction(const Interaction &) {}

		protected:
			Interaction(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Interaction() {}

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
			Actions owned by the Interaction.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::Action, uml::Element>>& getAction() const = 0;
			/*!
			Specifies the gates that form the message interface between this Interaction and any InteractionUses which reference it.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::Gate, uml::NamedElement>>& getFormalGate() const = 0;
			/*!
			The ordered set of fragments in the Interaction.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::InteractionFragment, uml::NamedElement>>& getFragment() const = 0;
			/*!
			Specifies the participants in this Interaction.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::Lifeline, uml::NamedElement>>& getLifeline() const = 0;
			/*!
			The Messages contained in this Interaction.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::Message, uml::NamedElement>>& getMessage() const = 0;

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
			Actions owned by the Interaction.
			<p>From package UML::Interactions.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Action, uml::Element>> m_action;
			/*!
			Specifies the gates that form the message interface between this Interaction and any InteractionUses which reference it.
			<p>From package UML::Interactions.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Gate, uml::NamedElement>> m_formalGate;
			/*!
			The ordered set of fragments in the Interaction.
			<p>From package UML::Interactions.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::InteractionFragment, uml::NamedElement>> m_fragment;
			/*!
			Specifies the participants in this Interaction.
			<p>From package UML::Interactions.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Lifeline, uml::NamedElement>> m_lifeline;
			/*!
			The Messages contained in this Interaction.
			<p>From package UML::Interactions.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Message, uml::NamedElement>> m_message;
	};
}
#endif /* end of include guard: UML_INTERACTION_HPP */
