//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INSTANCEVALUE_HPP
#define UML_INSTANCEVALUE_HPP


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
	class InstanceSpecification;
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
	An InstanceValue is a ValueSpecification that identifies an instance.
	<p>From package UML::Classification.</p>
	*/
	
	class UML_API InstanceValue : virtual public ValueSpecification
	{
		public:
 			InstanceValue(const InstanceValue &) {}

		protected:
			InstanceValue(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~InstanceValue() {}

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
			The InstanceSpecification that represents the specified value.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<uml::InstanceSpecification> getInstance() const = 0;
			/*!
			The InstanceSpecification that represents the specified value.
			<p>From package UML::Classification.</p>
			*/
			
			virtual void setInstance(std::shared_ptr<uml::InstanceSpecification>) = 0;

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
			The InstanceSpecification that represents the specified value.
			<p>From package UML::Classification.</p>
			*/
			
			std::shared_ptr<uml::InstanceSpecification> m_instance;
	};
}
#endif /* end of include guard: UML_INSTANCEVALUE_HPP */
