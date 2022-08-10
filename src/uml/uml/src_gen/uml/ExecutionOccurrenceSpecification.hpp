//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_EXECUTIONOCCURRENCESPECIFICATION_HPP
#define UML_EXECUTIONOCCURRENCESPECIFICATION_HPP


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
	class ExecutionSpecification;
	class GeneralOrdering;
	class Interaction;
	class InteractionOperand;
	class Lifeline;
	class Namespace;
	class StringExpression;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/OccurrenceSpecification.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	An ExecutionOccurrenceSpecification represents moments in time at which Actions or Behaviors start or finish.
	<p>From package UML::Interactions.</p>
	*/
	
	class UML_API ExecutionOccurrenceSpecification : virtual public OccurrenceSpecification
	{
		public:
 			ExecutionOccurrenceSpecification(const ExecutionOccurrenceSpecification &) {}

		protected:
			ExecutionOccurrenceSpecification(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ExecutionOccurrenceSpecification() {}

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
			References the execution specification describing the execution that is started or finished at this execution event.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::ExecutionSpecification> getExecution() const = 0;
			/*!
			References the execution specification describing the execution that is started or finished at this execution event.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setExecution(std::shared_ptr<uml::ExecutionSpecification>) = 0;

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
			References the execution specification describing the execution that is started or finished at this execution event.
			<p>From package UML::Interactions.</p>
			*/
			
			std::shared_ptr<uml::ExecutionSpecification> m_execution;
	};
}
#endif /* end of include guard: UML_EXECUTIONOCCURRENCESPECIFICATION_HPP */
