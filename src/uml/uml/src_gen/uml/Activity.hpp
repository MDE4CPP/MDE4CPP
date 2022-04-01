//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ACTIVITY_HPP
#define UML_ACTIVITY_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations
template<class T, class ... U> class Subset;
template<class T, class ... U> class SubsetUnion;

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
	class ActivityEdge;
	class ActivityGroup;
	class ActivityNode;
	class ActivityPartition;
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
	class Generalization;
	class GeneralizationSet;
	class InterfaceRealization;
	class Operation;
	class Package;
	class PackageImport;
	class Parameter;
	class ParameterSet;
	class Port;
	class Property;
	class Reception;
	class StringExpression;
	class StructuredActivityNode;
	class Substitution;
	class TemplateBinding;
	class TemplateParameter;
	class TemplateSignature;
	class UseCase;
	class Variable;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Behavior.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	An Activity is the specification of parameterized Behavior as the coordinated sequencing of subordinate units.
	<p>From package UML::Activities.</p>
	*/
	
	class UML_API Activity: virtual public Behavior
	{
		public:
 			Activity(const Activity &) {}

		protected:
			Activity(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Activity() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			A Parameter with direction other than inout must have exactly one ActivityParameterNode in an Activity.
			ownedParameter->forAll(p | 
			   p.direction <> ParameterDirectionKind::inout implies node->select(
			       oclIsKindOf(ActivityParameterNode) and oclAsType(ActivityParameterNode).parameter = p)->size()= 1)
			*/
			 
			virtual bool maximum_one_parameter_node(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < std::shared_ptr<Any>, std::shared_ptr<Any>>> context) = 0;
			/*!
			A Parameter with direction inout must have exactly two ActivityParameterNodes in an Activity, at most one with incoming ActivityEdges and at most one with outgoing ActivityEdges.
			ownedParameter->forAll(p | 
			p.direction = ParameterDirectionKind::inout implies
			let associatedNodes : Set(ActivityNode) = node->select(
			       oclIsKindOf(ActivityParameterNode) and oclAsType(ActivityParameterNode).parameter = p) in 
			  associatedNodes->size()=2 and
			  associatedNodes->select(incoming->notEmpty())->size()<=1 and
			  associatedNodes->select(outgoing->notEmpty())->size()<=1
			)
			*/
			 
			virtual bool maximum_two_parameter_nodes(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < std::shared_ptr<Any>, std::shared_ptr<Any>>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			If true, this Activity must not make any changes to objects. The default is false (an Activity may make nonlocal changes). (This is an assertion, not an executable property. It may be used by an execution engine to optimize model execution. If the assertion is violated by the Activity, then the model is ill-formed.)
			<p>From package UML::Activities.</p>
			*/
			 
			virtual bool getIsReadOnly() const = 0;
			/*!
			If true, this Activity must not make any changes to objects. The default is false (an Activity may make nonlocal changes). (This is an assertion, not an executable property. It may be used by an execution engine to optimize model execution. If the assertion is violated by the Activity, then the model is ill-formed.)
			<p>From package UML::Activities.</p>
			*/
			 
			virtual void setIsReadOnly (bool _isReadOnly)= 0;
			/*!
			If true, all invocations of the Activity are handled by the same execution.
			<p>From package UML::Activities.</p>
			*/
			 
			virtual bool getIsSingleExecution() const = 0;
			/*!
			If true, all invocations of the Activity are handled by the same execution.
			<p>From package UML::Activities.</p>
			*/
			 
			virtual void setIsSingleExecution (bool _isSingleExecution)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			ActivityEdges expressing flow between the nodes of the Activity.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ActivityEdge, uml::Element>> getEdge() const = 0;
			
			/*!
			ActivityNodes coordinated by the Activity.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::ActivityNode, uml::Element>> getNode() const = 0;
			virtual std::shared_ptr<SubsetUnion<uml::ActivityGroup, uml::ActivityGroup>> getOwnedGroup() const = 0;
			virtual std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode /*Subset does not reference a union*/>> getOwnedNode() const = 0;
			/*!
			Top-level ActivityPartitions in the Activity.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup /*Subset does not reference a union*/, uml::ActivityGroup>> getPartition() const = 0;
			/*!
			Top-level StructuredActivityNodes in the Activity.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::StructuredActivityNode, uml::ActivityGroup, uml::ActivityNode /*Subset does not reference a union*/>> getStructuredNode() const = 0;
			/*!
			Top-level Variables defined by the Activity.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Variable, uml::NamedElement>> getVariable() const = 0;

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
			Top-level ActivityGroups in the Activity.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::ActivityGroup, uml::Element>> getGroup() const = 0;
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
			The contexts that this element may be redefined from.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Classifier>> getRedefinitionContext() const = 0;
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
			/*!
			If true, this Activity must not make any changes to objects. The default is false (an Activity may make nonlocal changes). (This is an assertion, not an executable property. It may be used by an execution engine to optimize model execution. If the assertion is violated by the Activity, then the model is ill-formed.)
			<p>From package UML::Activities.</p>
			*/
			
			bool m_isReadOnly= false;
			/*!
			If true, all invocations of the Activity are handled by the same execution.
			<p>From package UML::Activities.</p>
			*/
			
			bool m_isSingleExecution= false;
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			ActivityEdges expressing flow between the nodes of the Activity.
			<p>From package UML::Activities.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::ActivityEdge, uml::Element>> m_edge;
			/*!
			Top-level ActivityGroups in the Activity.
			<p>From package UML::Activities.</p>
			*/
			
			mutable std::shared_ptr<SubsetUnion<uml::ActivityGroup, uml::Element>> m_group;
			/*!
			ActivityNodes coordinated by the Activity.
			<p>From package UML::Activities.</p>
			*/
			
			mutable std::shared_ptr<SubsetUnion<uml::ActivityNode, uml::Element>> m_node;
			mutable std::shared_ptr<SubsetUnion<uml::ActivityGroup, uml::ActivityGroup>> m_ownedGroup;
			mutable std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode /*Subset does not reference a union*/>> m_ownedNode;
			/*!
			Top-level ActivityPartitions in the Activity.
			<p>From package UML::Activities.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup /*Subset does not reference a union*/, uml::ActivityGroup>> m_partition;
			/*!
			Top-level StructuredActivityNodes in the Activity.
			<p>From package UML::Activities.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::StructuredActivityNode, uml::ActivityGroup, uml::ActivityNode /*Subset does not reference a union*/>> m_structuredNode;
			/*!
			Top-level Variables defined by the Activity.
			<p>From package UML::Activities.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Variable, uml::NamedElement>> m_variable;
	};
}
#endif /* end of include guard: UML_ACTIVITY_HPP */
