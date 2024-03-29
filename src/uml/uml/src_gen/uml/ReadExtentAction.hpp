//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_READEXTENTACTION_HPP
#define UML_READEXTENTACTION_HPP

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
	A ReadExtentAction is an Action that retrieves the current instances of a Classifier.
	<p>From package UML::Actions.</p>
	*/
	
	class UML_API ReadExtentAction: virtual public Action
	{
		public:
 			ReadExtentAction(const ReadExtentAction &) {}

		protected:
			ReadExtentAction(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ReadExtentAction() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The multiplicity of the result OutputPin is 0..*.
			result.is(0,*)
			*/
			 
			virtual bool multiplicity_of_result(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			The type of the result OutputPin is the classifier.
			result.type = classifier
			*/
			 
			virtual bool type_is_classifier(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The Classifier whose instances are to be retrieved.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::Classifier> getClassifier() const = 0;
			/*!
			The Classifier whose instances are to be retrieved.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setClassifier(std::shared_ptr<uml::Classifier>) = 0;
			/*!
			The OutputPin on which the Classifier instances are placed.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::OutputPin> getResult() const = 0;
			/*!
			The OutputPin on which the Classifier instances are placed.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setResult(std::shared_ptr<uml::OutputPin>) = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const = 0;
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
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The Classifier whose instances are to be retrieved.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::Classifier> m_classifier;
			/*!
			The OutputPin on which the Classifier instances are placed.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::OutputPin> m_result;
	};
}
#endif /* end of include guard: UML_READEXTENTACTION_HPP */
