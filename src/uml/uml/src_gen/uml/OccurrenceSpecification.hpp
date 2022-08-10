//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_OCCURRENCESPECIFICATION_HPP
#define UML_OCCURRENCESPECIFICATION_HPP


#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 


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
#include "uml/InteractionFragment.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	An OccurrenceSpecification is the basic semantic unit of Interactions. The sequences of occurrences specified by them are the meanings of Interactions.
	<p>From package UML::Interactions.</p>
	*/
	
	class UML_API OccurrenceSpecification : virtual public InteractionFragment
	{
		public:
 			OccurrenceSpecification(const OccurrenceSpecification &) {}

		protected:
			OccurrenceSpecification(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~OccurrenceSpecification() {}

			//*********************************
			// Operations
			//*********************************
			
			/*!
			Sets the Lifeline on which the OccurrenceSpecification appears.
			*/
			 
			virtual void setCovered(std::shared_ptr<uml::Lifeline> value) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			References the GeneralOrderings that specify EventOcurrences that must occur after this OccurrenceSpecification.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::GeneralOrdering>> getToAfter() const = 0;
			/*!
			References the GeneralOrderings that specify EventOcurrences that must occur before this OccurrenceSpecification.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::GeneralOrdering>> getToBefore() const = 0;

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
			References the GeneralOrderings that specify EventOcurrences that must occur after this OccurrenceSpecification.
			<p>From package UML::Interactions.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::GeneralOrdering>> m_toAfter;
			/*!
			References the GeneralOrderings that specify EventOcurrences that must occur before this OccurrenceSpecification.
			<p>From package UML::Interactions.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::GeneralOrdering>> m_toBefore;
	};
}
#endif /* end of include guard: UML_OCCURRENCESPECIFICATION_HPP */
