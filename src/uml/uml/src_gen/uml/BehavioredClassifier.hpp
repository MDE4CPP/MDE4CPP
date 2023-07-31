//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_BEHAVIOREDCLASSIFIER_HPP
#define UML_BEHAVIOREDCLASSIFIER_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations
template<class T, class ... U> class Subset;
template<class T, class ... U> class SubsetUnion;

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
	class Behavior;
	class CollaborationUse;
	class Comment;
	class Constraint;
	class Dependency;
	class ElementImport;
	class Feature;
	class Generalization;
	class GeneralizationSet;
	class Interface;
	class InterfaceRealization;
	class Package;
	class PackageImport;
	class Property;
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
#include "uml/Classifier.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A BehavioredClassifier may have InterfaceRealizations, and owns a set of Behaviors one of which may specify the behavior of the BehavioredClassifier itself.
	<p>From package UML::SimpleClassifiers.</p>
	*/
	
	class UML_API BehavioredClassifier: virtual public Classifier
	{
		public:
 			BehavioredClassifier(const BehavioredClassifier &) {}

		protected:
			BehavioredClassifier(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~BehavioredClassifier() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			If a behavior is classifier behavior, it does not have a specification.
			classifierBehavior->notEmpty() implies classifierBehavior.specification->isEmpty()
			*/
			 
			virtual bool class_behavior(const Any& diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			Retrieves all the interfaces on which this behaviored classifier or any of its parents has an interface realization dependency.
			*/
			 
			virtual std::shared_ptr<Bag<uml::Interface>> getAllImplementedInterfaces() = 0;
			/*!
			Retrieves the interfaces on which this behaviored classifier has an interface realization dependency.
			*/
			 
			virtual std::shared_ptr<Bag<uml::Interface>> getImplementedInterfaces() = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			A Behavior that specifies the behavior of the BehavioredClassifier itself.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			virtual const std::shared_ptr<uml::Behavior>& getClassifierBehavior() const = 0;
			/*!
			A Behavior that specifies the behavior of the BehavioredClassifier itself.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			virtual void setClassifierBehavior(const std::shared_ptr<uml::Behavior>&) = 0;
			/*!
			The set of InterfaceRealizations owned by the BehavioredClassifier. Interface realizations reference the Interfaces of which the BehavioredClassifier is an implementation.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::InterfaceRealization, uml::Element>>& getInterfaceRealization() const = 0;
			/*!
			Behaviors owned by a BehavioredClassifier.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			virtual const std::shared_ptr<SubsetUnion<uml::Behavior, uml::NamedElement>>& getOwnedBehavior() const = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			Specifies each Feature directly defined in the classifier. Note that there may be members of the Classifier that are of the type Feature but are not included, e.g., inherited features.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> getFeature() const = 0;
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
			A Behavior that specifies the behavior of the BehavioredClassifier itself.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			std::shared_ptr<uml::Behavior> m_classifierBehavior;
			/*!
			The set of InterfaceRealizations owned by the BehavioredClassifier. Interface realizations reference the Interfaces of which the BehavioredClassifier is an implementation.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::InterfaceRealization, uml::Element>> m_interfaceRealization;
			/*!
			Behaviors owned by a BehavioredClassifier.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			mutable std::shared_ptr<SubsetUnion<uml::Behavior, uml::NamedElement>> m_ownedBehavior;
	};
}
#endif /* end of include guard: UML_BEHAVIOREDCLASSIFIER_HPP */
