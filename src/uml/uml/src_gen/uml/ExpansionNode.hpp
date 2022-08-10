//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_EXPANSIONNODE_HPP
#define UML_EXPANSIONNODE_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations

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
	class Behavior;
	class Classifier;
	class Comment;
	class Dependency;
	class ExpansionRegion;
	class InterruptibleActivityRegion;
	class Namespace;
	class State;
	class StringExpression;
	class StructuredActivityNode;
	class Type;
	class ValueSpecification;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/ObjectNode.hpp"

// enum includes
#include "uml/ObjectNodeOrderingKind.hpp"
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	An ExpansionNode is an ObjectNode used to indicate a collection input or output for an ExpansionRegion. A collection input of an ExpansionRegion contains a collection that is broken into its individual elements inside the region, whose content is executed once per element. A collection output of an ExpansionRegion combines individual elements produced by the execution of the region into a collection for use outside the region.
	<p>From package UML::Actions.</p>
	*/
	
	class UML_API ExpansionNode : virtual public ObjectNode
	{
		public:
 			ExpansionNode(const ExpansionNode &) {}

		protected:
			ExpansionNode(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ExpansionNode() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			One of regionAsInput or regionAsOutput must be non-empty, but not both.
			regionAsInput->notEmpty() xor regionAsOutput->notEmpty()
			*/
			 
			virtual bool region_as_input_or_output(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The ExpansionRegion for which the ExpansionNode is an input.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::ExpansionRegion> getRegionAsInput() const = 0;
			/*!
			The ExpansionRegion for which the ExpansionNode is an input.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setRegionAsInput(std::shared_ptr<uml::ExpansionRegion>) = 0;
			/*!
			The ExpansionRegion for which the ExpansionNode is an output.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::ExpansionRegion> getRegionAsOutput() const = 0;
			/*!
			The ExpansionRegion for which the ExpansionNode is an output.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setRegionAsOutput(std::shared_ptr<uml::ExpansionRegion>) = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			ActivityGroups containing the ActivityNode.
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
			The ExpansionRegion for which the ExpansionNode is an input.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::ExpansionRegion> m_regionAsInput;
			/*!
			The ExpansionRegion for which the ExpansionNode is an output.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::ExpansionRegion> m_regionAsOutput;
	};
}
#endif /* end of include guard: UML_EXPANSIONNODE_HPP */
