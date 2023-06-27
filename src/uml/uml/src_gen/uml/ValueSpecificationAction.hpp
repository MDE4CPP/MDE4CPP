//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_VALUESPECIFICATIONACTION_HPP
#define UML_VALUESPECIFICATIONACTION_HPP

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
	class StructuredActivityNode;
	class ValueSpecification;
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
	A ValueSpecificationAction is an Action that evaluates a ValueSpecification and provides a result.
	<p>From package UML::Actions.</p>
	*/
	
	class UML_API ValueSpecificationAction: virtual public Action
	{
		public:
 			ValueSpecificationAction(const ValueSpecificationAction &) {}

		protected:
			ValueSpecificationAction(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ValueSpecificationAction() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The type of the value ValueSpecification must conform to the type of the result OutputPin.
			value.type.conformsTo(result.type)
			*/
			 
			virtual bool compatible_type(const Any& diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			The multiplicity of the result OutputPin is 1..1
			result.is(1,1)
			*/
			 
			virtual bool multiplicity(const Any& diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The OutputPin on which the result value is placed.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::OutputPin>& getResult() const = 0;
			/*!
			The OutputPin on which the result value is placed.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setResult(const std::shared_ptr<uml::OutputPin>&) = 0;
			/*!
			The ValueSpecification to be evaluated.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::ValueSpecification>& getValue() const = 0;
			/*!
			The ValueSpecification to be evaluated.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setValue(const std::shared_ptr<uml::ValueSpecification>&) = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const = 0;
			/*!
			The ordered set of OutputPins representing outputs from the Action.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> getOutput() const = 0;
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
			The OutputPin on which the result value is placed.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::OutputPin> m_result;
			/*!
			The ValueSpecification to be evaluated.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::ValueSpecification> m_value;
	};
}
#endif /* end of include guard: UML_VALUESPECIFICATIONACTION_HPP */
