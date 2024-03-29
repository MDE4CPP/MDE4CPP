//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_STRUCTURALFEATUREACTION_HPP
#define UML_STRUCTURALFEATUREACTION_HPP

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
	class StructuralFeature;
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
	StructuralFeatureAction is an abstract class for all Actions that operate on StructuralFeatures.
	<p>From package UML::Actions.</p>
	*/
	
	class UML_API StructuralFeatureAction: virtual public Action
	{
		public:
 			StructuralFeatureAction(const StructuralFeatureAction &) {}

		protected:
			StructuralFeatureAction(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~StructuralFeatureAction() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The multiplicity of the object InputPin must be 1..1.
			object.is(1,1)
			*/
			 
			virtual bool multiplicity(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			The structuralFeature must not be static.
			not structuralFeature.isStatic
			*/
			 
			virtual bool not_static(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			The structuralFeature must either be an owned or inherited feature of the type of the object InputPin, or it must be an owned end of a binary Association whose opposite end had as a type to which the type of the object InputPin conforms.
			object.type.oclAsType(Classifier).allFeatures()->includes(structuralFeature) or
				object.type.conformsTo(structuralFeature.oclAsType(Property).opposite.type)
			*/
			 
			virtual bool object_type(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			The structuralFeature must have exactly one featuringClassifier.
			structuralFeature.featuringClassifier->size() = 1
			*/
			 
			virtual bool one_featuring_classifier(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			The visibility of the structuralFeature must allow access from the object performing the ReadStructuralFeatureAction.
			structuralFeature.visibility = VisibilityKind::public or
			_'context'.allFeatures()->includes(structuralFeature) or
			structuralFeature.visibility=VisibilityKind::protected and
			_'context'.conformsTo(structuralFeature.oclAsType(Property).opposite.type.oclAsType(Classifier))
			*/
			 
			virtual bool visibility(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The InputPin from which the object whose StructuralFeature is to be read or written is obtained.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::InputPin> getObject() const = 0;
			/*!
			The InputPin from which the object whose StructuralFeature is to be read or written is obtained.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setObject(std::shared_ptr<uml::InputPin>) = 0;
			/*!
			The StructuralFeature to be read or written.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::StructuralFeature> getStructuralFeature() const = 0;
			/*!
			The StructuralFeature to be read or written.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setStructuralFeature(std::shared_ptr<uml::StructuralFeature>) = 0;

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
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The InputPin from which the object whose StructuralFeature is to be read or written is obtained.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::InputPin> m_object;
			/*!
			The StructuralFeature to be read or written.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::StructuralFeature> m_structuralFeature;
	};
}
#endif /* end of include guard: UML_STRUCTURALFEATUREACTION_HPP */
