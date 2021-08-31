//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ACTIVITYPARTITION_HPP
#define UML_ACTIVITYPARTITION_HPP

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
	class ActivityNode;
	class Comment;
	class Dependency;
	class Namespace;
	class StringExpression;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/ActivityGroup.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	An ActivityPartition is a kind of ActivityGroup for identifying ActivityNodes that have some characteristic in common.
	<p>From package UML::Activities.</p>
	*/
	
	class UML_API ActivityPartition: virtual public ActivityGroup
	{
		public:
 			ActivityPartition(const ActivityPartition &) {}

		protected:
			ActivityPartition(){}
			//Additional constructors for the containments back reference
			ActivityPartition(std::weak_ptr<uml::Activity> par_inActivity);

			//Additional constructors for the containments back reference
			ActivityPartition(std::weak_ptr<uml::Namespace> par_namespace);

			//Additional constructors for the containments back reference
			ActivityPartition(std::weak_ptr<uml::Element> par_owner);

			//Additional constructors for the containments back reference
			ActivityPartition(std::weak_ptr<uml::ActivityGroup> par_superGroup);

			//Additional constructors for the containments back reference
			ActivityPartition(std::weak_ptr<uml::ActivityPartition> par_superPartition);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ActivityPartition() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			An ActvivityPartition with isDimension = true may not be contained by another ActivityPartition.
			isDimension implies superPartition->isEmpty()
			*/
			 
			virtual bool dimension_not_contained(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;/*!
			If a non-external ActivityPartition represents a Classifier and has a superPartition, then the superPartition must represent a Classifier, and the Classifier of the subpartition must be nested (nestedClassifier or ownedBehavior) in the Classifier represented by the superPartition, or be at the contained end of a composition Association with the Classifier represented by the superPartition.
			(not isExternal and represents.oclIsKindOf(Classifier) and superPartition->notEmpty()) implies
			(
			   let representedClassifier : Classifier = represents.oclAsType(Classifier) in
			     superPartition.represents.oclIsKindOf(Classifier) and
			      let representedSuperClassifier : Classifier = superPartition.represents.oclAsType(Classifier) in
			       (representedSuperClassifier.oclIsKindOf(BehavioredClassifier) and representedClassifier.oclIsKindOf(Behavior) and 
			        representedSuperClassifier.oclAsType(BehavioredClassifier).ownedBehavior->includes(representedClassifier.oclAsType(Behavior))) 
			       or
			       (representedSuperClassifier.oclIsKindOf(Class) and  representedSuperClassifier.oclAsType(Class).nestedClassifier->includes(representedClassifier))
			       or
			       (Association.allInstances()->exists(a | a.memberEnd->exists(end1 | end1.isComposite and end1.type = representedClassifier and 
			                                                                      a.memberEnd->exists(end2 | end1<>end2 and end2.type = representedSuperClassifier))))
			)
			*/
			 
			virtual bool represents_classifier(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;/*!
			If an ActivityPartition represents a Property and has a superPartition representing a Classifier, then all the other non-external subpartitions of the superPartition must represent Properties directly owned by the same Classifier.
			(represents.oclIsKindOf(Property) and superPartition->notEmpty() and superPartition.represents.oclIsKindOf(Classifier)) implies
			(
			  let representedClassifier : Classifier = superPartition.represents.oclAsType(Classifier)
			  in
			    superPartition.subpartition->reject(isExternal)->forAll(p | 
			       p.represents.oclIsKindOf(Property) and p.owner=representedClassifier)
			)
			*/
			 
			virtual bool represents_property(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;/*!
			If an ActivityPartition represents a Property and has a superPartition, then the Property must be of a Classifier represented by the superPartition, or of a Classifier that is the type of a Property represented by the superPartition.
			(represents.oclIsKindOf(Property) and superPartition->notEmpty()) implies
			(
			  (superPartition.represents.oclIsKindOf(Classifier) and represents.owner = superPartition.represents) or 
			  (superPartition.represents.oclIsKindOf(Property) and represents.owner = superPartition.represents.oclAsType(Property).type)
			)
			*/
			 
			virtual bool represents_property_and_is_contained(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			//*********************************
			// Attributes Getter & Setter
			//*********************************
			/*!
			Indicates whether the ActivityPartition groups other ActivityPartitions along a dimension.
			<p>From package UML::Activities.</p>
			*/
			 
			virtual bool getIsDimension() const = 0;
			/*!
			Indicates whether the ActivityPartition groups other ActivityPartitions along a dimension.
			<p>From package UML::Activities.</p>
			*/
			 
			virtual void setIsDimension (bool _isDimension)= 0;
			/*!
			Indicates whether the ActivityPartition represents an entity to which the partitioning structure does not apply.
			<p>From package UML::Activities.</p>
			*/
			 
			virtual bool getIsExternal() const = 0;
			/*!
			Indicates whether the ActivityPartition represents an entity to which the partitioning structure does not apply.
			<p>From package UML::Activities.</p>
			*/
			 
			virtual void setIsExternal (bool _isExternal)= 0;
			
			//*********************************
			// References Getter & Setter
			//*********************************
			/*!
			ActivityEdges immediately contained in the ActivityPartition.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ActivityEdge, uml::ActivityEdge>> getEdge() const = 0;
			
			/*!
			ActivityNodes immediately contained in the ActivityPartition.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode>> getNode() const = 0;
			
			/*!
			An Element represented by the functionality modeled within the ActivityPartition.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<uml::Element> getRepresents() const = 0;
			/*!
			An Element represented by the functionality modeled within the ActivityPartition.
			<p>From package UML::Activities.</p>
			*/
			
			virtual void setRepresents(std::shared_ptr<uml::Element>) = 0;
			/*!
			Other ActivityPartitions immediately contained in this ActivityPartition (as its subgroups).
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup>> getSubpartition() const = 0;
			
			/*!
			Other ActivityPartitions immediately containing this ActivityPartition (as its superGroups).
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::weak_ptr<uml::ActivityPartition> getSuperPartition() const = 0;
			/*!
			Other ActivityPartitions immediately containing this ActivityPartition (as its superGroups).
			<p>From package UML::Activities.</p>
			*/
			
			virtual void setSuperPartition(std::weak_ptr<uml::ActivityPartition>) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			Indicates whether the ActivityPartition groups other ActivityPartitions along a dimension.
			<p>From package UML::Activities.</p>
			*/
			
			bool m_isDimension = false;
			/*!
			Indicates whether the ActivityPartition represents an entity to which the partitioning structure does not apply.
			<p>From package UML::Activities.</p>
			*/
			
			bool m_isExternal = false;
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			ActivityEdges immediately contained in the ActivityPartition.
			<p>From package UML::Activities.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::ActivityEdge, uml::ActivityEdge>> m_edge;/*!
			ActivityNodes immediately contained in the ActivityPartition.
			<p>From package UML::Activities.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode>> m_node;/*!
			An Element represented by the functionality modeled within the ActivityPartition.
			<p>From package UML::Activities.</p>
			*/
			
			std::shared_ptr<uml::Element> m_represents;/*!
			Other ActivityPartitions immediately contained in this ActivityPartition (as its subgroups).
			<p>From package UML::Activities.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup>> m_subpartition;/*!
			Other ActivityPartitions immediately containing this ActivityPartition (as its superGroups).
			<p>From package UML::Activities.</p>
			*/
			
			std::weak_ptr<uml::ActivityPartition> m_superPartition;

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			ActivityEdges immediately contained in the ActivityGroup.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityEdge>> getContainedEdge() const = 0;/*!
			ActivityNodes immediately contained in the ActivityGroup.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityNode>> getContainedNode() const = 0;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const = 0;/*!
			Other ActivityGroups immediately contained in this ActivityGroup.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::ActivityGroup, uml::Element>> getSubgroup() const = 0;/*!
			The ActivityGroup immediately containing this ActivityGroup, if it is directly owned by another ActivityGroup.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::weak_ptr<uml::ActivityGroup> getSuperGroup() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_ACTIVITYPARTITION_HPP */
