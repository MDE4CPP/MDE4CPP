//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_REDEFINABLEELEMENT_HPP
#define UML_REDEFINABLEELEMENT_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations
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
	class Classifier;
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
	A RedefinableElement is an element that, when defined in the context of a Classifier, can be redefined more specifically or differently in the context of another Classifier that specializes (directly or indirectly) the context Classifier.
	<p>From package UML::Classification.</p>
	*/
	
	class UML_API RedefinableElement : virtual public NamedElement
	{
		public:
 			RedefinableElement(const RedefinableElement &) {}

		protected:
			RedefinableElement(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~RedefinableElement() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The query isConsistentWith() specifies, for any two RedefinableElements in a context in which redefinition is possible, whether redefinition would be logically consistent. By default, this is false; this operation must be overridden for subclasses of RedefinableElement to define the consistency conditions.
			result = (false)
			redefiningElement.isRedefinitionContextValid(self)
			<p>From package UML::Classification.</p>
			*/
			 
			virtual bool isConsistentWith(std::shared_ptr<uml::RedefinableElement> redefiningElement) = 0;
			/*!
			The query isRedefinitionContextValid() specifies whether the redefinition contexts of this RedefinableElement are properly related to the redefinition contexts of the specified RedefinableElement to allow this element to redefine the other. By default at least one of the redefinition contexts of this element must be a specialization of at least one of the redefinition contexts of the specified element.
			result = (redefinitionContext->exists(c | c.allParents()->includesAll(redefinedElement.redefinitionContext)))
			<p>From package UML::Classification.</p>
			*/
			 
			virtual bool isRedefinitionContextValid(std::shared_ptr<uml::RedefinableElement> redefinedElement) = 0;
			/*!
			A RedefinableElement can only redefine non-leaf RedefinableElements.
			redefinedElement->forAll(re | not re.isLeaf)
			*/
			 
			virtual bool non_leaf_redefinition(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			A redefining element must be consistent with each redefined element.
			redefinedElement->forAll(re | re.isConsistentWith(self))
			*/
			 
			virtual bool redefinition_consistent(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			At least one of the redefinition contexts of the redefining element must be a specialization of at least one of the redefinition contexts for each redefined element.
			redefinedElement->forAll(re | self.isRedefinitionContextValid(re))
			*/
			 
			virtual bool redefinition_context_valid(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Indicates whether it is possible to further redefine a RedefinableElement. If the value is true, then it is not possible to further redefine the RedefinableElement.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual bool getIsLeaf() const = 0;
			/*!
			Indicates whether it is possible to further redefine a RedefinableElement. If the value is true, then it is not possible to further redefine the RedefinableElement.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual void setIsLeaf (bool _isLeaf)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			
			

			//*********************************
			// Union Reference Getters
			//*********************************
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
			/*!
			The contexts that this element may be redefined from.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Classifier>> getRedefinitionContext() const = 0;

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
			Indicates whether it is possible to further redefine a RedefinableElement. If the value is true, then it is not possible to further redefine the RedefinableElement.
			<p>From package UML::Classification.</p>
			*/
			
			bool m_isLeaf= false;
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p>
			*/
			
			mutable std::shared_ptr<Union<uml::RedefinableElement>> m_redefinedElement;
			/*!
			The contexts that this element may be redefined from.
			<p>From package UML::Classification.</p>
			*/
			
			mutable std::shared_ptr<Union<uml::Classifier>> m_redefinitionContext;
	};
}
#endif /* end of include guard: UML_REDEFINABLEELEMENT_HPP */
