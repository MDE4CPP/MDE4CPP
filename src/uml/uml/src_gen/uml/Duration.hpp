//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_DURATION_HPP
#define UML_DURATION_HPP


#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 
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
	A Duration is a ValueSpecification that specifies the temporal distance between two time instants.
	<p>From package UML::Values.</p>
	*/
	
	class UML_API Duration : virtual public ValueSpecification
	{
		public:
 			Duration(const Duration &) {}

		protected:
			Duration(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Duration() {}

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
			A ValueSpecification that evaluates to the value of the Duration.
			<p>From package UML::Values.</p>
			*/
			
			virtual std::shared_ptr<uml::ValueSpecification> getExpr() const = 0;
			/*!
			A ValueSpecification that evaluates to the value of the Duration.
			<p>From package UML::Values.</p>
			*/
			
			virtual void setExpr(const std::shared_ptr<uml::ValueSpecification>&) = 0;
			/*!
			Refers to the Observations that are involved in the computation of the Duration value
			<p>From package UML::Values.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Observation>> getObservation() const = 0;

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
			A ValueSpecification that evaluates to the value of the Duration.
			<p>From package UML::Values.</p>
			*/
			
			std::shared_ptr<uml::ValueSpecification> m_expr;
			/*!
			Refers to the Observations that are involved in the computation of the Duration value
			<p>From package UML::Values.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::Observation>> m_observation;
	};
}
#endif /* end of include guard: UML_DURATION_HPP */
