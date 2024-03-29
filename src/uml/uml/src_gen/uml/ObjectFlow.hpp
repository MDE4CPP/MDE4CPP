//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_OBJECTFLOW_HPP
#define UML_OBJECTFLOW_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations

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
	class ActivityGroup;
	class ActivityNode;
	class ActivityPartition;
	class Behavior;
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
#include "uml/ActivityEdge.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	An ObjectFlow is an ActivityEdge that is traversed by object tokens that may hold values. Object flows also support multicast/receive, token selection from object nodes, and transformation of tokens.
	<p>From package UML::Activities.</p>
	*/
	
	class UML_API ObjectFlow: virtual public ActivityEdge
	{
		public:
 			ObjectFlow(const ObjectFlow &) {}

		protected:
			ObjectFlow(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ObjectFlow() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			ObjectNodes connected by an ObjectFlow, with optionally intervening ControlNodes, must have compatible types. In particular, the downstream ObjectNode type must be the same or a supertype of the upstream ObjectNode type.
			*/
			 
			virtual bool compatible_types(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			A selection Behavior has one input Parameter and one output Parameter. The input Parameter must have the same as or a supertype of the type of the source ObjectNode, be non-unique and have multiplicity 0..*. The output Parameter must be the same or a subtype of the type of source ObjectNode. The Behavior cannot have side effects.
			selection<>null implies
				selection.inputParameters()->size()=1 and
				selection.inputParameters()->forAll(not isUnique and is(0,*)) and
				selection.outputParameters()->size()=1
			*/
			 
			virtual bool input_and_output_parameter(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			isMulticast and isMultireceive cannot both be true.
			not (isMulticast and isMultireceive)
			*/
			 
			virtual bool is_multicast_or_is_multireceive(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			ObjectFlows may not have ExecutableNodes at either end.
			not (source.oclIsKindOf(ExecutableNode) or target.oclIsKindOf(ExecutableNode))
			*/
			 
			virtual bool no_executable_nodes(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			ObjectNodes connected by an ObjectFlow, with optionally intervening ControlNodes, must have the same upperBounds.
			*/
			 
			virtual bool same_upper_bounds(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			An ObjectFlow may have a selection Behavior only if it has an ObjectNode as its source.
			selection<>null implies source.oclIsKindOf(ObjectNode)
			*/
			 
			virtual bool selection_behavior(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			An ObjectFlow with a constant weight may not target an ObjectNode, with optionally intervening ControlNodes, that has an upper bound less than the weight.
			*/
			 
			virtual bool target(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			A transformation Behavior has one input Parameter and one output Parameter. The input Parameter must be the same as or a supertype of the type of object token coming from the source end. The output Parameter must be the same or a subtype of the type of object token expected downstream. The Behavior cannot have side effects.
			transformation<>null implies
				transformation.inputParameters()->size()=1 and
				transformation.outputParameters()->size()=1
			*/
			 
			virtual bool transformation_behavior(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Indicates whether the objects in the ObjectFlow are passed by multicasting.
			<p>From package UML::Activities.</p>
			*/
			 
			virtual bool getIsMulticast() const = 0;
			/*!
			Indicates whether the objects in the ObjectFlow are passed by multicasting.
			<p>From package UML::Activities.</p>
			*/
			 
			virtual void setIsMulticast (bool _isMulticast)= 0;
			/*!
			Indicates whether the objects in the ObjectFlow are gathered from respondents to multicasting.
			<p>From package UML::Activities.</p>
			*/
			 
			virtual bool getIsMultireceive() const = 0;
			/*!
			Indicates whether the objects in the ObjectFlow are gathered from respondents to multicasting.
			<p>From package UML::Activities.</p>
			*/
			 
			virtual void setIsMultireceive (bool _isMultireceive)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			A Behavior used to select tokens from a source ObjectNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<uml::Behavior> getSelection() const = 0;
			/*!
			A Behavior used to select tokens from a source ObjectNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual void setSelection(std::shared_ptr<uml::Behavior>) = 0;
			/*!
			A Behavior used to change or replace object tokens flowing along the ObjectFlow.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<uml::Behavior> getTransformation() const = 0;
			/*!
			A Behavior used to change or replace object tokens flowing along the ObjectFlow.
			<p>From package UML::Activities.</p>
			*/
			
			virtual void setTransformation(std::shared_ptr<uml::Behavior>) = 0;

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
			/*!
			Indicates whether the objects in the ObjectFlow are passed by multicasting.
			<p>From package UML::Activities.</p>
			*/
			
			bool m_isMulticast= false;
			/*!
			Indicates whether the objects in the ObjectFlow are gathered from respondents to multicasting.
			<p>From package UML::Activities.</p>
			*/
			
			bool m_isMultireceive= false;
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			A Behavior used to select tokens from a source ObjectNode.
			<p>From package UML::Activities.</p>
			*/
			
			std::shared_ptr<uml::Behavior> m_selection;
			/*!
			A Behavior used to change or replace object tokens flowing along the ObjectFlow.
			<p>From package UML::Activities.</p>
			*/
			
			std::shared_ptr<uml::Behavior> m_transformation;
	};
}
#endif /* end of include guard: UML_OBJECTFLOW_HPP */
