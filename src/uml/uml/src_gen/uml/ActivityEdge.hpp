//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ACTIVITYEDGE_HPP
#define UML_ACTIVITYEDGE_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations
template<class T, class ... U> class Subset;
template<class T> class Union;
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
	class ActivityGroup;
	class ActivityNode;
	class ActivityPartition;
	class Classifier;
	class Comment;
	class Dependency;
	class InterruptibleActivityRegion;
	class Namespace;
	class StringExpression;
	class StructuredActivityNode;
	class ValueSpecification;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/RedefinableElement.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	An ActivityEdge is an abstract class for directed connections between two ActivityNodes.
	<p>From package UML::Activities.</p>
	*/
	
	class UML_API ActivityEdge: virtual public RedefinableElement
	{
		public:
 			ActivityEdge(const ActivityEdge &) {}

		protected:
			ActivityEdge(){}
			//Additional constructors for the containments back reference
			ActivityEdge(std::weak_ptr<uml::Activity> par_activity);

			//Additional constructors for the containments back reference
			ActivityEdge(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);

			//Additional constructors for the containments back reference
			ActivityEdge(std::weak_ptr<uml::Namespace> par_namespace);

			//Additional constructors for the containments back reference
			ActivityEdge(std::weak_ptr<uml::Element> par_owner);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ActivityEdge() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			If an ActivityEdge is directly owned by an Activity, then its source and target must be directly or indirectly contained in the same Activity.
			activity<>null implies source.containingActivity() = activity and target.containingActivity() = activity
			*/
			 
			virtual bool source_and_target(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < std::shared_ptr<Any>, std::shared_ptr<Any>>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The Activity containing the ActivityEdge, if it is directly owned by an Activity.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::weak_ptr<uml::Activity> getActivity() const = 0;
			/*!
			The Activity containing the ActivityEdge, if it is directly owned by an Activity.
			<p>From package UML::Activities.</p>
			*/
			
			virtual void setActivity(std::weak_ptr<uml::Activity>) = 0;
			/*!
			A ValueSpecification that is evaluated to determine if a token can traverse the ActivityEdge. If an ActivityEdge has no guard, then there is no restriction on tokens traversing the edge.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<uml::ValueSpecification> getGuard() const = 0;
			/*!
			A ValueSpecification that is evaluated to determine if a token can traverse the ActivityEdge. If an ActivityEdge has no guard, then there is no restriction on tokens traversing the edge.
			<p>From package UML::Activities.</p>
			*/
			
			virtual void setGuard(std::shared_ptr<uml::ValueSpecification>) = 0;
			
			/*!
			ActivityPartitions containing the ActivityEdge.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup>> getInPartition() const = 0;
			/*!
			The StructuredActivityNode containing the ActivityEdge, if it is owned by a StructuredActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::weak_ptr<uml::StructuredActivityNode> getInStructuredNode() const = 0;
			/*!
			The StructuredActivityNode containing the ActivityEdge, if it is owned by a StructuredActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual void setInStructuredNode(std::weak_ptr<uml::StructuredActivityNode>) = 0;
			/*!
			The InterruptibleActivityRegion for which this ActivityEdge is an interruptingEdge.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<uml::InterruptibleActivityRegion> getInterrupts() const = 0;
			/*!
			The InterruptibleActivityRegion for which this ActivityEdge is an interruptingEdge.
			<p>From package UML::Activities.</p>
			*/
			
			virtual void setInterrupts(std::shared_ptr<uml::InterruptibleActivityRegion>) = 0;
			/*!
			ActivityEdges from a generalization of the Activity containing this ActivityEdge that are redefined by this ActivityEdge.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ActivityEdge, uml::RedefinableElement>> getRedefinedEdge() const = 0;
			/*!
			The ActivityNode from which tokens are taken when they traverse the ActivityEdge.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<uml::ActivityNode> getSource() const = 0;
			/*!
			The ActivityNode from which tokens are taken when they traverse the ActivityEdge.
			<p>From package UML::Activities.</p>
			*/
			
			virtual void setSource(std::shared_ptr<uml::ActivityNode>) = 0;
			/*!
			The ActivityNode to which tokens are put when they traverse the ActivityEdge.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<uml::ActivityNode> getTarget() const = 0;
			/*!
			The ActivityNode to which tokens are put when they traverse the ActivityEdge.
			<p>From package UML::Activities.</p>
			*/
			
			virtual void setTarget(std::shared_ptr<uml::ActivityNode>) = 0;
			/*!
			The minimum number of tokens that must traverse the ActivityEdge at the same time. If no weight is specified, this is equivalent to specifying a constant value of 1.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<uml::ValueSpecification> getWeight() const = 0;
			/*!
			The minimum number of tokens that must traverse the ActivityEdge at the same time. If no weight is specified, this is equivalent to specifying a constant value of 1.
			<p>From package UML::Activities.</p>
			*/
			
			virtual void setWeight(std::shared_ptr<uml::ValueSpecification>) = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			ActivityGroups containing the ActivityEdge.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const = 0;
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
			The Activity containing the ActivityEdge, if it is directly owned by an Activity.
			<p>From package UML::Activities.</p>
			*/
			
			std::weak_ptr<uml::Activity> m_activity;
			/*!
			A ValueSpecification that is evaluated to determine if a token can traverse the ActivityEdge. If an ActivityEdge has no guard, then there is no restriction on tokens traversing the edge.
			<p>From package UML::Activities.</p>
			*/
			
			std::shared_ptr<uml::ValueSpecification> m_guard;
			/*!
			ActivityGroups containing the ActivityEdge.
			<p>From package UML::Activities.</p>
			*/
			
			mutable std::shared_ptr<Union<uml::ActivityGroup>> m_inGroup;
			/*!
			ActivityPartitions containing the ActivityEdge.
			<p>From package UML::Activities.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup>> m_inPartition;
			/*!
			The StructuredActivityNode containing the ActivityEdge, if it is owned by a StructuredActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			std::weak_ptr<uml::StructuredActivityNode> m_inStructuredNode;
			/*!
			The InterruptibleActivityRegion for which this ActivityEdge is an interruptingEdge.
			<p>From package UML::Activities.</p>
			*/
			
			std::shared_ptr<uml::InterruptibleActivityRegion> m_interrupts;
			/*!
			ActivityEdges from a generalization of the Activity containing this ActivityEdge that are redefined by this ActivityEdge.
			<p>From package UML::Activities.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::ActivityEdge, uml::RedefinableElement>> m_redefinedEdge;
			/*!
			The ActivityNode from which tokens are taken when they traverse the ActivityEdge.
			<p>From package UML::Activities.</p>
			*/
			
			std::shared_ptr<uml::ActivityNode> m_source;
			/*!
			The ActivityNode to which tokens are put when they traverse the ActivityEdge.
			<p>From package UML::Activities.</p>
			*/
			
			std::shared_ptr<uml::ActivityNode> m_target;
			/*!
			The minimum number of tokens that must traverse the ActivityEdge at the same time. If no weight is specified, this is equivalent to specifying a constant value of 1.
			<p>From package UML::Activities.</p>
			*/
			
			std::shared_ptr<uml::ValueSpecification> m_weight;
	};
}
#endif /* end of include guard: UML_ACTIVITYEDGE_HPP */
