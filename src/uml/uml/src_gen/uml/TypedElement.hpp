//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_TYPEDELEMENT_HPP
#define UML_TYPEDELEMENT_HPP


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
	class StringExpression;
	class Type;
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
	A TypedElement is a NamedElement that may have a Type specified for it.
	<p>From package UML::CommonStructure.</p>
	*/
	
	class UML_API TypedElement : virtual public NamedElement
	{
		public:
 			TypedElement(const TypedElement &) {}

		protected:
			TypedElement(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~TypedElement() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The type of the TypedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual const std::shared_ptr<uml::Type>& getType() const = 0;
			/*!
			The type of the TypedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setType(const std::shared_ptr<uml::Type>&) = 0;

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
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The type of the TypedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			std::shared_ptr<uml::Type> m_type;
	};
}
#endif /* end of include guard: UML_TYPEDELEMENT_HPP */
