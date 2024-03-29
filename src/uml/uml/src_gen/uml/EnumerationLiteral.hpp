//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ENUMERATIONLITERAL_HPP
#define UML_ENUMERATIONLITERAL_HPP


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
	class Classifier;
	class Comment;
	class Dependency;
	class Deployment;
	class Enumeration;
	class Namespace;
	class Package;
	class Slot;
	class StringExpression;
	class TemplateParameter;
	class ValueSpecification;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/InstanceSpecification.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	An EnumerationLiteral is a user-defined data value for an Enumeration.
	<p>From package UML::SimpleClassifiers.</p>
	*/
	
	class UML_API EnumerationLiteral: virtual public InstanceSpecification
	{
		public:
 			EnumerationLiteral(const EnumerationLiteral &) {}

		protected:
			EnumerationLiteral(){}
			//Additional constructors for the containments back reference
			EnumerationLiteral(std::weak_ptr<uml::Enumeration> par_enumeration);

			//Additional constructors for the containments back reference
			EnumerationLiteral(std::weak_ptr<uml::Namespace> par_namespace);

			//Additional constructors for the containments back reference
			EnumerationLiteral(std::weak_ptr<uml::Element> par_owner);

			//Additional constructors for the containments back reference
			EnumerationLiteral(std::weak_ptr<uml::Package> par_owningPackage);

			//Additional constructors for the containments back reference
			EnumerationLiteral(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~EnumerationLiteral() {}

			//*********************************
			// Operations
			//*********************************
			
			virtual std::shared_ptr<Bag<uml::Classifier> > getClassifiers() = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The Enumeration that this EnumerationLiteral is a member of.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			virtual std::weak_ptr<uml::Enumeration> getEnumeration() const = 0;
			/*!
			The Enumeration that this EnumerationLiteral is a member of.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			virtual void setEnumeration(std::weak_ptr<uml::Enumeration>) = 0;

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
			The Enumeration that this EnumerationLiteral is a member of.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			std::weak_ptr<uml::Enumeration> m_enumeration;
	};
}
#endif /* end of include guard: UML_ENUMERATIONLITERAL_HPP */
