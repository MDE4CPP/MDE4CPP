//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_RECLASSIFYOBJECTACTION_HPP
#define UML_RECLASSIFYOBJECTACTION_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 
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
	A ReclassifyObjectAction is an Action that changes the Classifiers that classify an object.
	<p>From package UML::Actions.</p>
	*/
	
	class UML_API ReclassifyObjectAction : virtual public Action
	{
		public:
 			ReclassifyObjectAction(const ReclassifyObjectAction &) {}

		protected:
			ReclassifyObjectAction(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ReclassifyObjectAction() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			None of the newClassifiers may be abstract.
			not newClassifier->exists(isAbstract)
			*/
			 
			virtual bool classifier_not_abstract(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			The object InputPin has no type.
			object.type = null
			*/
			 
			virtual bool input_pin(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			The multiplicity of the object InputPin is 1..1.
			object.is(1,1)
			*/
			 
			virtual bool multiplicity(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Specifies whether existing Classifiers should be removed before adding the new Classifiers.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual bool getIsReplaceAll() const = 0;
			/*!
			Specifies whether existing Classifiers should be removed before adding the new Classifiers.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual void setIsReplaceAll (bool _isReplaceAll)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			A set of Classifiers to be added to the Classifiers of the given object.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Classifier>> getNewClassifier() const = 0;
			/*!
			The InputPin that holds the object to be reclassified.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::InputPin> getObject() const = 0;
			/*!
			The InputPin that holds the object to be reclassified.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setObject(std::shared_ptr<uml::InputPin>) = 0;
			/*!
			A set of Classifiers to be removed from the Classifiers of the given object.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Classifier>> getOldClassifier() const = 0;

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
			Specifies whether existing Classifiers should be removed before adding the new Classifiers.
			<p>From package UML::Actions.</p>
			*/
			
			bool m_isReplaceAll= false;
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			A set of Classifiers to be added to the Classifiers of the given object.
			<p>From package UML::Actions.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::Classifier>> m_newClassifier;
			/*!
			The InputPin that holds the object to be reclassified.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::InputPin> m_object;
			/*!
			A set of Classifiers to be removed from the Classifiers of the given object.
			<p>From package UML::Actions.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::Classifier>> m_oldClassifier;
	};
}
#endif /* end of include guard: UML_RECLASSIFYOBJECTACTION_HPP */
