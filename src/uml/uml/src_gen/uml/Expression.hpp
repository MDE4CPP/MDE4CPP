//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_EXPRESSION_HPP
#define UML_EXPRESSION_HPP


#include <memory>
#include <string>
// forward declarations
template<class T, class ... U> class Subset;


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
	An Expression represents a node in an expression tree, which may be non-terminal or terminal. It defines a symbol, and has a possibly empty sequence of operands that are ValueSpecifications. It denotes a (possibly empty) set of values when evaluated in a context.
	<p>From package UML::Values.</p>
	*/
	
	class UML_API Expression : virtual public ValueSpecification
	{
		public:
 			Expression(const Expression &) {}

		protected:
			Expression(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Expression() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			The symbol associated with this node in the expression tree.
			<p>From package UML::Values.</p>
			*/
			 
			virtual std::string getSymbol() const = 0;
			/*!
			The symbol associated with this node in the expression tree.
			<p>From package UML::Values.</p>
			*/
			 
			virtual void setSymbol (std::string _symbol)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			Specifies a sequence of operand ValueSpecifications.
			<p>From package UML::Values.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::ValueSpecification, uml::Element>>& getOperand() const = 0;

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
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			The symbol associated with this node in the expression tree.
			<p>From package UML::Values.</p>
			*/
			
			std::string m_symbol= "";
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			Specifies a sequence of operand ValueSpecifications.
			<p>From package UML::Values.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::ValueSpecification, uml::Element>> m_operand;
	};
}
#endif /* end of include guard: UML_EXPRESSION_HPP */
