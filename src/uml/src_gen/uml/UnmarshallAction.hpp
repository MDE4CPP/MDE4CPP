//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_UNMARSHALLACTION_HPP
#define UML_UNMARSHALLACTION_HPP

#include <map>
#include <list>
#include <memory>
#include <string>


// forward declarations
template<class T, class ... U> class Subset;


class AnyObject;
typedef std::shared_ptr<AnyObject> Any;

//*********************************
// generated Includes

#include <map>

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
	class Action;
}

namespace uml 
{
	class Activity;
}

namespace uml 
{
	class ActivityEdge;
}

namespace uml 
{
	class ActivityGroup;
}

namespace uml 
{
	class ActivityNode;
}

namespace uml 
{
	class ActivityPartition;
}

namespace uml 
{
	class Classifier;
}

namespace uml 
{
	class Comment;
}

namespace uml 
{
	class Constraint;
}

namespace uml 
{
	class Dependency;
}

namespace uml 
{
	class Element;
}

namespace uml 
{
	class ExceptionHandler;
}

namespace uml 
{
	class InputPin;
}

namespace uml 
{
	class InterruptibleActivityRegion;
}

namespace uml 
{
	class Namespace;
}

namespace uml 
{
	class OutputPin;
}

namespace uml 
{
	class RedefinableElement;
}

namespace uml 
{
	class StringExpression;
}

namespace uml 
{
	class StructuredActivityNode;
}

// base class includes
#include "uml/Action.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"


//*********************************
namespace uml 
{
	/*!
	An UnmarshallAction is an Action that retrieves the values of the StructuralFeatures of an object and places them on OutputPins.
	<p>From package UML::Actions.</p>
	*/
	
	class UnmarshallAction:virtual public Action
	{
		public:
 			UnmarshallAction(const UnmarshallAction &) {}
			UnmarshallAction& operator=(UnmarshallAction const&) = delete;

		protected:
			UnmarshallAction(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~UnmarshallAction() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The multiplicity of the object InputPin is 1..1
			object.is(1,1)
			*/
			 
			virtual bool multiplicity_of_object(Any diagnostics,std::map <   Any, Any >  context) = 0;
			
			/*!
			The number of result outputPins must be the same as the number of attributes of the unmarshallType.
			unmarshallType.allAttributes()->size() = result->size()
			*/
			 
			virtual bool number_of_result(Any diagnostics,std::map <   Any, Any >  context) = 0;
			
			/*!
			The type of the object InputPin conform to the unmarshallType.
			object.type.conformsTo(unmarshallType)
			*/
			 
			virtual bool object_type(Any diagnostics,std::map <   Any, Any >  context) = 0;
			
			/*!
			The unmarshallType must have at least one StructuralFeature.
			unmarshallType.allAttributes()->size() >= 1
			*/
			 
			virtual bool structural_feature(Any diagnostics,std::map <   Any, Any >  context) = 0;
			
			/*!
			The type, ordering and multiplicity of each attribute of the unmarshallType must be compatible with the type, ordering and multiplicity of the corresponding result OutputPin.
			let attribute:OrderedSet(Property) = unmarshallType.allAttributes() in
			Sequence{1..result->size()}->forAll(i | 
				attribute->at(i).type.conformsTo(result->at(i).type) and
				attribute->at(i).isOrdered=result->at(i).isOrdered and
				attribute->at(i).compatibleWith(result->at(i)))
			*/
			 
			virtual bool type_ordering_and_multiplicity(Any diagnostics,std::map <   Any, Any >  context) = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The InputPin that gives the object to be unmarshalled.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::InputPin > getObject() const = 0;
			
			/*!
			The InputPin that gives the object to be unmarshalled.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setObject(std::shared_ptr<uml::InputPin> _object) = 0;
			
			/*!
			The OutputPins on which are placed the values of the StructuralFeatures of the input object.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin>> getResult() const = 0;
			
			
			/*!
			The type of the object to be unmarshalled.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::Classifier > getUnmarshallType() const = 0;
			
			/*!
			The type of the object to be unmarshalled.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setUnmarshallType(std::shared_ptr<uml::Classifier> _unmarshallType) = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The InputPin that gives the object to be unmarshalled.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::InputPin > m_object;/*!
			The OutputPins on which are placed the values of the StructuralFeatures of the input object.
			<p>From package UML::Actions.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin>> m_result;/*!
			The type of the object to be unmarshalled.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::Classifier > m_unmarshallType;

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const = 0;/*!
			The ordered set of InputPins representing the inputs to the Action.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> getInput() const = 0;/*!
			The ordered set of OutputPins representing outputs from the Action.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> getOutput() const = 0;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element > getOwner() const = 0;/*!
			The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_UNMARSHALLACTION_HPP */
