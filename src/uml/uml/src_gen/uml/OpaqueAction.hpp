//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_OPAQUEACTION_HPP
#define UML_OPAQUEACTION_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations
template<class T, class ... U> class Subset;

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
	class Activity;
	class ActivityEdge;
	class ActivityGroup;
	class ActivityPartition;
	class Classifier;
	class Comment;
	class Constraint;
	class Dependency;
	class ExceptionHandler;
	class InputPin;
	class InterruptibleActivityRegion;
	class Namespace;
	class OutputPin;
	class StringExpression;
	class StructuredActivityNode;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Action.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	An OpaqueAction is an Action whose functionality is not specified within UML.
	<p>From package UML::Actions.</p>
	*/
	
	class UML_API OpaqueAction: virtual public Action
	{
		public:
 			OpaqueAction(const OpaqueAction &) {}

		protected:
			OpaqueAction(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~OpaqueAction() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			If the language attribute is not empty, then the size of the body and language lists must be the same.
			language->notEmpty() implies (_'body'->size() = language->size())
			*/
			 
			virtual bool language_body_size(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Provides a textual specification of the functionality of the Action, in one or more languages other than UML.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual std::shared_ptr<Bag<std::string>> getBody() const = 0;
			/*!
			If provided, a specification of the language used for each of the body Strings.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual std::shared_ptr<Bag<std::string>> getLanguage() const = 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The InputPins providing inputs to the OpaqueAction.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::InputPin, uml::InputPin>> getInputValue() const = 0;
			/*!
			The OutputPins on which the OpaqueAction provides outputs.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin>> getOutputValue() const = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const = 0;
			/*!
			The ordered set of InputPins representing the inputs to the Action.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> getInput() const = 0;
			/*!
			The ordered set of OutputPins representing outputs from the Action.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> getOutput() const = 0;
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
			/*!
			Provides a textual specification of the functionality of the Action, in one or more languages other than UML.
			<p>From package UML::Actions.</p>
			*/
			
			mutable std::shared_ptr<Bag<std::string>> m_body;
			/*!
			If provided, a specification of the language used for each of the body Strings.
			<p>From package UML::Actions.</p>
			*/
			
			mutable std::shared_ptr<Bag<std::string>> m_language;
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The InputPins providing inputs to the OpaqueAction.
			<p>From package UML::Actions.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::InputPin, uml::InputPin>> m_inputValue;
			/*!
			The OutputPins on which the OpaqueAction provides outputs.
			<p>From package UML::Actions.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin>> m_outputValue;
	};
}
#endif /* end of include guard: UML_OPAQUEACTION_HPP */
