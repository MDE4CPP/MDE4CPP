//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CONSTRAINT_HPP
#define UML_CONSTRAINT_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 
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
	class StringExpression;
	class TemplateParameter;
	class ValueSpecification;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/PackageableElement.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A Constraint is a condition or restriction expressed in natural language text or in a machine readable language for the purpose of declaring some of the semantics of an Element or set of Elements.
	<p>From package UML::CommonStructure.</p>
	*/
	
	class UML_API Constraint : virtual public PackageableElement
	{
		public:
 			Constraint(const Constraint &) {}

		protected:
			Constraint(){}
			//Additional constructors for the containments back reference
			Constraint(std::weak_ptr<uml::Namespace> par_Namespace, const int reference_id);

			//Additional constructors for the containments back reference

			//Additional constructors for the containments back reference
			Constraint(std::weak_ptr<uml::Element> par_owner);

			//Additional constructors for the containments back reference
			Constraint(std::weak_ptr<uml::Package> par_owningPackage);

			//Additional constructors for the containments back reference
			Constraint(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Constraint() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The ValueSpecification for a Constraint must evaluate to a Boolean value.
			*/
			 
			virtual bool boolean_value(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			Evaluating the ValueSpecification for a Constraint must not have side effects.
			*/
			 
			virtual bool no_side_effects(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			A Constraint cannot be applied to itself.
			not constrainedElement->includes(self)
			*/
			 
			virtual bool not_apply_to_self(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The ordered set of Elements referenced by this Constraint.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Element>> getConstrainedElement() const = 0;
			/*!
			Specifies the Namespace that owns the Constraint.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getContext() const = 0;
			/*!
			Specifies the Namespace that owns the Constraint.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setContext(std::weak_ptr<uml::Namespace>) = 0;
			/*!
			A condition that must be true when evaluated in order for the Constraint to be satisfied.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<uml::ValueSpecification> getSpecification() const = 0;
			/*!
			A condition that must be true when evaluated in order for the Constraint to be satisfied.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setSpecification(std::shared_ptr<uml::ValueSpecification>) = 0;

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
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The ordered set of Elements referenced by this Constraint.
			<p>From package UML::CommonStructure.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::Element>> m_constrainedElement;
			/*!
			Specifies the Namespace that owns the Constraint.
			<p>From package UML::CommonStructure.</p>
			*/
			
			std::weak_ptr<uml::Namespace> m_context;
			/*!
			A condition that must be true when evaluated in order for the Constraint to be satisfied.
			<p>From package UML::CommonStructure.</p>
			*/
			
			std::shared_ptr<uml::ValueSpecification> m_specification;
	};
}
#endif /* end of include guard: UML_CONSTRAINT_HPP */
