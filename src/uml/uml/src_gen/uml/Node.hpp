//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_NODE_HPP
#define UML_NODE_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations
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
	class Behavior;
	class CollaborationUse;
	class Comment;
	class CommunicationPath;
	class ConnectableElement;
	class Connector;
	class Constraint;
	class Dependency;
	class Deployment;
	class ElementImport;
	class Extension;
	class Feature;
	class Generalization;
	class GeneralizationSet;
	class InterfaceRealization;
	class Operation;
	class Package;
	class PackageImport;
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
#include "uml/Class.hpp"
#include "uml/DeploymentTarget.hpp"

// enum includes
#include "uml/AggregationKind.hpp"
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A Node is computational resource upon which artifacts may be deployed for execution. Nodes can be interconnected through communication paths to define network structures.
	<p>From package UML::Deployments.</p>
	*/
	
	class UML_API Node: virtual public Class, virtual public DeploymentTarget
	{
		public:
 			Node(const Node &) {}

		protected:
			Node(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Node() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			Creates a (binary) communication path between this node and the specified other node, with the specified navigabilities, aggregations, names, lower bounds, and upper bounds, and owned by this node's nearest package.
			*/
			 
			virtual std::shared_ptr<uml::CommunicationPath> createCommunicationPath(bool end1IsNavigable, uml::AggregationKind end1Aggregation, std::string end1Name, int end1Lower, int end1Upper, std::shared_ptr<uml::Node> end1Node, bool end2IsNavigable, uml::AggregationKind end2Aggregation, std::string end2Name, int end2Lower, int end2Upper) = 0;
			/*!
			Retrieves the communication paths in which this node is involved.
			*/
			 
			virtual std::shared_ptr<Bag<uml::CommunicationPath>> getCommunicationPaths() = 0;
			/*!
			The internal structure of a Node (if defined) consists solely of parts of type Node.
			part->forAll(oclIsKindOf(Node))
			*/
			 
			virtual bool internal_structure(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The Nodes that are defined (nested) within the Node.
			<p>From package UML::Deployments.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Node, uml::NamedElement>> getNestedNode() const = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			All of the Properties that are direct (i.e., not inherited or imported) attributes of the Classifier.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> getAttribute() const = 0;
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
			/*!
			The roles that instances may play in this StructuredClassifier.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement>> getRole() const = 0;
			

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
			The Nodes that are defined (nested) within the Node.
			<p>From package UML::Deployments.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Node, uml::NamedElement>> m_nestedNode;
	};
}
#endif /* end of include guard: UML_NODE_HPP */
