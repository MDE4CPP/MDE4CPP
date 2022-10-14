//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_OPAQUEEXPRESSION_HPP
#define UML_OPAQUEEXPRESSION_HPP

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
	class Behavior;
	class Comment;
	class Dependency;
	class Namespace;
	class Package;
	class Parameter;
	class Slot;
	class StringExpression;
	class TemplateParameter;
	class Type;
	class ValueSpecificationAction;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/ValueSpecification.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	An OpaqueExpression is a ValueSpecification that specifies the computation of a collection of values either in terms of a UML Behavior or based on a textual statement in a language other than UML
	<p>From package UML::Values.</p>
	*/
	
	class UML_API OpaqueExpression : virtual public ValueSpecification
	{
		public:
 			OpaqueExpression(const OpaqueExpression &) {}

		protected:
			OpaqueExpression(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~OpaqueExpression() {}

			//*********************************
			// Operations
			//*********************************
			
			/*!
			The query isIntegral() tells whether an expression is intended to produce an Integer.
			result = (false)
			<p>From package UML::Values.</p>
			*/
			 
			virtual bool isIntegral() = 0;
			/*!
			The query isNonNegative() tells whether an integer expression has a non-negative value.
			self.isIntegral()
			result = (false)
			<p>From package UML::Values.</p>
			*/
			 
			virtual bool isNonNegative() = 0;
			/*!
			The query isPositive() tells whether an integer expression has a positive value.
			result = (false)
			self.isIntegral()
			<p>From package UML::Values.</p>
			*/
			 
			virtual bool isPositive() = 0;
			/*!
			If the language attribute is not empty, then the size of the body and language arrays must be the same.
			language->notEmpty() implies (_'body'->size() = language->size())
			*/
			 
			virtual bool language_body_size(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			The behavior must have exactly one return result parameter.
			behavior <> null implies
			   behavior.ownedParameter->select(direction=ParameterDirectionKind::return)->size() = 1
			*/
			 
			virtual bool one_return_result_parameter(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			The behavior may only have return result parameters.
			behavior <> null implies behavior.ownedParameter->select(direction<>ParameterDirectionKind::return)->isEmpty()
			*/
			 
			virtual bool only_return_result_parameters(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			The query value() gives an integer value for an expression intended to produce one.
			self.isIntegral()
			result = (0)
			<p>From package UML::Values.</p>
			*/
			 
			virtual int value() = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			A textual definition of the behavior of the OpaqueExpression, possibly in multiple languages.
			<p>From package UML::Values.</p>
			*/
			 
			virtual std::shared_ptr<Bag<std::string>> getBody() const = 0;
			/*!
			Specifies the languages used to express the textual bodies of the OpaqueExpression.  Languages are matched to body Strings by order. The interpretation of the body depends on the languages. If the languages are unspecified, they may be implicit from the expression body or the context.
			<p>From package UML::Values.</p>
			*/
			 
			virtual std::shared_ptr<Bag<std::string>> getLanguage() const = 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			Specifies the behavior of the OpaqueExpression as a UML Behavior.
			<p>From package UML::Values.</p>
			*/
			
			virtual std::shared_ptr<uml::Behavior> getBehavior() const = 0;
			/*!
			Specifies the behavior of the OpaqueExpression as a UML Behavior.
			<p>From package UML::Values.</p>
			*/
			
			virtual void setBehavior(std::shared_ptr<uml::Behavior>) = 0;
			/*!
			If an OpaqueExpression is specified using a UML Behavior, then this refers to the single required return Parameter of that Behavior. When the Behavior completes execution, the values on this Parameter give the result of evaluating the OpaqueExpression.
			<p>From package UML::Values.</p>
			*/
			
			virtual std::shared_ptr<uml::Parameter> getResult() const = 0;

			//*********************************
			// Union Reference Getters
			//*********************************

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
			A textual definition of the behavior of the OpaqueExpression, possibly in multiple languages.
			<p>From package UML::Values.</p>
			*/
			
			mutable std::shared_ptr<Bag<std::string>> m_body;
			/*!
			Specifies the languages used to express the textual bodies of the OpaqueExpression.  Languages are matched to body Strings by order. The interpretation of the body depends on the languages. If the languages are unspecified, they may be implicit from the expression body or the context.
			<p>From package UML::Values.</p>
			*/
			
			mutable std::shared_ptr<Bag<std::string>> m_language;
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			Specifies the behavior of the OpaqueExpression as a UML Behavior.
			<p>From package UML::Values.</p>
			*/
			
			std::shared_ptr<uml::Behavior> m_behavior;
			/*!
			If an OpaqueExpression is specified using a UML Behavior, then this refers to the single required return Parameter of that Behavior. When the Behavior completes execution, the values on this Parameter give the result of evaluating the OpaqueExpression.
			<p>From package UML::Values.</p>
			*/
			
			std::shared_ptr<uml::Parameter> m_result;
	};
}
#endif /* end of include guard: UML_OPAQUEEXPRESSION_HPP */
