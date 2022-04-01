//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_STRINGEXPRESSION_HPP
#define UML_STRINGEXPRESSION_HPP

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
	class Comment;
	class Dependency;
	class Namespace;
	class Package;
	class Slot;
	class TemplateBinding;
	class TemplateParameter;
	class TemplateSignature;
	class Type;
	class ValueSpecificationAction;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Expression.hpp"
#include "uml/TemplateableElement.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A StringExpression is an Expression that specifies a String value that is derived by concatenating a sequence of operands with String values or a sequence of subExpressions, some of which might be template parameters.
	<p>From package UML::Values.</p>
	*/
	
	class UML_API StringExpression: virtual public Expression, virtual public TemplateableElement
	{
		public:
 			StringExpression(const StringExpression &) {}

		protected:
			StringExpression(){}
			//Additional constructors for the containments back reference
			StringExpression(std::weak_ptr<uml::Namespace> par_namespace);

			//Additional constructors for the containments back reference
			StringExpression(std::weak_ptr<uml::Element> par_owner);

			//Additional constructors for the containments back reference
			StringExpression(std::weak_ptr<uml::StringExpression> par_owningExpression);

			//Additional constructors for the containments back reference
			StringExpression(std::weak_ptr<uml::Package> par_owningPackage);

			//Additional constructors for the containments back reference
			StringExpression(std::weak_ptr<uml::Slot> par_owningSlot);

			//Additional constructors for the containments back reference
			StringExpression(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

			//Additional constructors for the containments back reference
			StringExpression(std::weak_ptr<uml::ValueSpecificationAction> par_valueSpecificationAction);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~StringExpression() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			All the operands of a StringExpression must be LiteralStrings
			operand->forAll (oclIsKindOf (LiteralString))
			*/
			 
			virtual bool operands(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < std::shared_ptr<Any>, std::shared_ptr<Any>>> context) = 0;
			/*!
			If a StringExpression has sub-expressions, it cannot have operands and vice versa (this avoids the problem of having to define a collating sequence between operands and subexpressions).
			if subExpression->notEmpty() then operand->isEmpty() else operand->notEmpty() endif
			*/
			 
			virtual bool subexpressions(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < std::shared_ptr<Any>, std::shared_ptr<Any>>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The StringExpression of which this StringExpression is a subExpression.
			<p>From package UML::Values.</p>
			*/
			
			virtual std::weak_ptr<uml::StringExpression> getOwningExpression() const = 0;
			/*!
			The StringExpression of which this StringExpression is a subExpression.
			<p>From package UML::Values.</p>
			*/
			
			virtual void setOwningExpression(std::weak_ptr<uml::StringExpression>) = 0;
			/*!
			The StringExpressions that constitute this StringExpression.
			<p>From package UML::Values.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::StringExpression, uml::Element>> getSubExpression() const = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
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
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const = 0;
			

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
			The StringExpression of which this StringExpression is a subExpression.
			<p>From package UML::Values.</p>
			*/
			
			std::weak_ptr<uml::StringExpression> m_owningExpression;
			/*!
			The StringExpressions that constitute this StringExpression.
			<p>From package UML::Values.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::StringExpression, uml::Element>> m_subExpression;
	};
}
#endif /* end of include guard: UML_STRINGEXPRESSION_HPP */
