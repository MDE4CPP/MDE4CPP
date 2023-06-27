//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_TIMEEXPRESSION_HPP
#define UML_TIMEEXPRESSION_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 
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
	class Comment;
	class Dependency;
	class Namespace;
	class Observation;
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
	A TimeExpression is a ValueSpecification that represents a time value.
	<p>From package UML::Values.</p>
	*/
	
	class UML_API TimeExpression: virtual public ValueSpecification
	{
		public:
 			TimeExpression(const TimeExpression &) {}

		protected:
			TimeExpression(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~TimeExpression() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			If a TimeExpression has no expr, then it must have a single observation that is a TimeObservation.
			expr = null implies (observation->size() = 1 and observation->forAll(oclIsKindOf(TimeObservation)))
			*/
			 
			virtual bool no_expr_requires_observation(const Any& diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			A ValueSpecification that evaluates to the value of the TimeExpression.
			<p>From package UML::Values.</p>
			*/
			
			virtual const std::shared_ptr<uml::ValueSpecification>& getExpr() const = 0;
			/*!
			A ValueSpecification that evaluates to the value of the TimeExpression.
			<p>From package UML::Values.</p>
			*/
			
			virtual void setExpr(const std::shared_ptr<uml::ValueSpecification>&) = 0;
			/*!
			Refers to the Observations that are involved in the computation of the TimeExpression value.
			<p>From package UML::Values.</p>
			*/
			
			virtual const std::shared_ptr<Bag<uml::Observation>>& getObservation() const = 0;

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
			A ValueSpecification that evaluates to the value of the TimeExpression.
			<p>From package UML::Values.</p>
			*/
			
			std::shared_ptr<uml::ValueSpecification> m_expr;
			/*!
			Refers to the Observations that are involved in the computation of the TimeExpression value.
			<p>From package UML::Values.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::Observation>> m_observation;
	};
}
#endif /* end of include guard: UML_TIMEEXPRESSION_HPP */
