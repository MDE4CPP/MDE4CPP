//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ACTIVITYGROUP_HPP
#define UML_ACTIVITYGROUP_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations
template<class T, class ... U> class Subset;
template<class T, class ... U> class SubsetUnion;
template<class T> class Union;
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
#include "uml/NamedElement.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	ActivityGroup is an abstract class for defining sets of ActivityNodes and ActivityEdges in an Activity.
	<p>From package UML::Activities.</p>
	*/
	
	class UML_API ActivityGroup: virtual public NamedElement
	{
		public:
 			ActivityGroup(const ActivityGroup &) {}

		protected:
			ActivityGroup(){}
			//Additional constructors for the containments back reference
			ActivityGroup(std::weak_ptr<uml::Activity> par_inActivity);

			//Additional constructors for the containments back reference
			ActivityGroup(std::weak_ptr<uml::Namespace> par_namespace);

			//Additional constructors for the containments back reference
			ActivityGroup(std::weak_ptr<uml::Element> par_owner);

			//Additional constructors for the containments back reference
			ActivityGroup(std::weak_ptr<uml::ActivityGroup> par_superGroup);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ActivityGroup() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The Activity that directly or indirectly contains this ActivityGroup.
			result = (if superGroup<>null then superGroup.containingActivity()
			else inActivity
			endif)
			<p>From package UML::Activities.</p>
			*/
			 
			virtual std::shared_ptr<uml::Activity> containingActivity() = 0;
			/*!
			All containedNodes and containeEdges of an ActivityGroup must be in the same Activity as the group.
			containedNode->forAll(activity = self.containingActivity()) and 
			containedEdge->forAll(activity = self.containingActivity())
			*/
			 
			virtual bool nodes_and_edges(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			No containedNode or containedEdge of an ActivityGroup may be contained by its subgroups or its superGroups, transitively.
			subgroup->closure(subgroup).containedNode->excludesAll(containedNode) and
			superGroup->closure(superGroup).containedNode->excludesAll(containedNode) and 
			subgroup->closure(subgroup).containedEdge->excludesAll(containedEdge) and 
			superGroup->closure(superGroup).containedEdge->excludesAll(containedEdge)
			*/
			 
			virtual bool not_contained(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			
			
			/*!
			The Activity containing the ActivityGroup, if it is directly owned by an Activity.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::weak_ptr<uml::Activity> getInActivity() const = 0;
			/*!
			The Activity containing the ActivityGroup, if it is directly owned by an Activity.
			<p>From package UML::Activities.</p>
			*/
			
			virtual void setInActivity(std::weak_ptr<uml::Activity>) = 0;
			
			

			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			ActivityEdges immediately contained in the ActivityGroup.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityEdge>> getContainedEdge() const = 0;
			/*!
			ActivityNodes immediately contained in the ActivityGroup.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityNode>> getContainedNode() const = 0;
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
			Other ActivityGroups immediately contained in this ActivityGroup.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::ActivityGroup, uml::Element>> getSubgroup() const = 0;
			/*!
			The ActivityGroup immediately containing this ActivityGroup, if it is directly owned by another ActivityGroup.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::weak_ptr<uml::ActivityGroup> getSuperGroup() const = 0;

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
			ActivityEdges immediately contained in the ActivityGroup.
			<p>From package UML::Activities.</p>
			*/
			
			mutable std::shared_ptr<Union<uml::ActivityEdge>> m_containedEdge;
			/*!
			ActivityNodes immediately contained in the ActivityGroup.
			<p>From package UML::Activities.</p>
			*/
			
			mutable std::shared_ptr<Union<uml::ActivityNode>> m_containedNode;
			/*!
			The Activity containing the ActivityGroup, if it is directly owned by an Activity.
			<p>From package UML::Activities.</p>
			*/
			
			std::weak_ptr<uml::Activity> m_inActivity;
			/*!
			Other ActivityGroups immediately contained in this ActivityGroup.
			<p>From package UML::Activities.</p>
			*/
			
			mutable std::shared_ptr<SubsetUnion<uml::ActivityGroup, uml::Element>> m_subgroup;
			/*!
			The ActivityGroup immediately containing this ActivityGroup, if it is directly owned by another ActivityGroup.
			<p>From package UML::Activities.</p>
			*/
			
			std::weak_ptr<uml::ActivityGroup> m_superGroup;
	};
}
#endif /* end of include guard: UML_ACTIVITYGROUP_HPP */
