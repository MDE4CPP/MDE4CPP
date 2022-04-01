//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_READLINKOBJECTENDQUALIFIERACTION_HPP
#define UML_READLINKOBJECTENDQUALIFIERACTION_HPP

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
	class Property;
	class StringExpression;
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
	A ReadLinkObjectEndQualifierAction is an Action that retrieves a qualifier end value from a link object.
	<p>From package UML::Actions.</p>
	*/
	
	class UML_API ReadLinkObjectEndQualifierAction: virtual public Action
	{
		public:
 			ReadLinkObjectEndQualifierAction(const ReadLinkObjectEndQualifierAction &) {}

		protected:
			ReadLinkObjectEndQualifierAction(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ReadLinkObjectEndQualifierAction() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The association of the Association end of the qualifier Property must be an AssociationClass.
			qualifier.associationEnd.association.oclIsKindOf(AssociationClass)
			*/
			 
			virtual bool association_of_association(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < std::shared_ptr<Any>, std::shared_ptr<Any>>> context) = 0;
			/*!
			The ends of the Association must not be static.
			qualifier.associationEnd.association.memberEnd->forAll(e | not e.isStatic)
			*/
			 
			virtual bool ends_of_association(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < std::shared_ptr<Any>, std::shared_ptr<Any>>> context) = 0;
			/*!
			The multiplicity of the object InputPin is 1..1.
			object.is(1,1)
			*/
			 
			virtual bool multiplicity_of_object(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < std::shared_ptr<Any>, std::shared_ptr<Any>>> context) = 0;
			/*!
			The multiplicity of the qualifier Property is 1..1.
			qualifier.is(1,1)
			*/
			 
			virtual bool multiplicity_of_qualifier(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < std::shared_ptr<Any>, std::shared_ptr<Any>>> context) = 0;
			/*!
			The multiplicity of the result OutputPin is 1..1.
			result.is(1,1)
			*/
			 
			virtual bool multiplicity_of_result(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < std::shared_ptr<Any>, std::shared_ptr<Any>>> context) = 0;
			/*!
			The qualifier Property must be a qualifier of an Association end.
			qualifier.associationEnd <> null
			*/
			 
			virtual bool qualifier_attribute(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < std::shared_ptr<Any>, std::shared_ptr<Any>>> context) = 0;
			/*!
			The type of the result OutputPin is the same as the type of the qualifier Property.
			result.type = qualifier.type
			*/
			 
			virtual bool same_type(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < std::shared_ptr<Any>, std::shared_ptr<Any>>> context) = 0;
			/*!
			The type of the object InputPin is the AssociationClass that owns the Association end that has the given qualifier Property.
			object.type = qualifier.associationEnd.association
			*/
			 
			virtual bool type_of_object(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < std::shared_ptr<Any>, std::shared_ptr<Any>>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The InputPin from which the link object is obtained.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::InputPin> getObject() const = 0;
			/*!
			The InputPin from which the link object is obtained.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setObject(std::shared_ptr<uml::InputPin>) = 0;
			/*!
			The qualifier Property to be read.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::Property> getQualifier() const = 0;
			/*!
			The qualifier Property to be read.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setQualifier(std::shared_ptr<uml::Property>) = 0;
			/*!
			The OutputPin where the result value is placed.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::OutputPin> getResult() const = 0;
			/*!
			The OutputPin where the result value is placed.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setResult(std::shared_ptr<uml::OutputPin>) = 0;

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
			The InputPin from which the link object is obtained.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::InputPin> m_object;
			/*!
			The qualifier Property to be read.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::Property> m_qualifier;
			/*!
			The OutputPin where the result value is placed.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::OutputPin> m_result;
	};
}
#endif /* end of include guard: UML_READLINKOBJECTENDQUALIFIERACTION_HPP */
