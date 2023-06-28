//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_LITERALSTRING_HPP
#define UML_LITERALSTRING_HPP


#include <memory>
#include <string>
// forward declarations


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
#include "uml/LiteralSpecification.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A LiteralString is a specification of a String value.
	<p>From package UML::Values.</p>
	*/
	
	class UML_API LiteralString : virtual public LiteralSpecification
	{
		public:
 			LiteralString(const LiteralString &) {}

		protected:
			LiteralString(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~LiteralString() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The query isComputable() is redefined to be true.
			result = (true)
			<p>From package UML::Values.</p>
			*/
			 
			virtual bool isComputable() = 0;
			/*!
			The query stringValue() gives the value.
			result = (value)
			<p>From package UML::Values.</p>
			*/
			 
			virtual std::string stringValue() = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			The specified String value.
			<p>From package UML::Values.</p>
			*/
			 
			virtual std::string getValue() const = 0;
			/*!
			The specified String value.
			<p>From package UML::Values.</p>
			*/
			 
			virtual void setValue (std::string _value)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************

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
			The specified String value.
			<p>From package UML::Values.</p>
			*/
			
			std::string m_value= "";
			
			//*********************************
			// Reference Members
			//*********************************
	};
}
#endif /* end of include guard: UML_LITERALSTRING_HPP */
