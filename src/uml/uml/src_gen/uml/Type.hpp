//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_TYPE_HPP
#define UML_TYPE_HPP


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
	class Association;
	class Comment;
	class Dependency;
	class Namespace;
	class Package;
	class StringExpression;
	class TemplateParameter;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/PackageableElement.hpp"

// enum includes
#include "uml/AggregationKind.hpp"
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A Type constrains the values represented by a TypedElement.
	<p>From package UML::CommonStructure.</p>
	*/
	
	class UML_API Type: virtual public PackageableElement
	{
		public:
 			Type(const Type &) {}

		protected:
			Type(){}
			//Additional constructors for the containments back reference
			Type(std::weak_ptr<uml::Namespace> par_namespace);

			//Additional constructors for the containments back reference
			Type(std::weak_ptr<uml::Element> par_owner);

			//Additional constructors for the containments back reference
			Type(std::weak_ptr<uml::Package> par_Package, const int reference_id);

			//Additional constructors for the containments back reference
			Type(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

			//Additional constructors for the containments back reference

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Type() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The query conformsTo() gives true for a Type that conforms to another. By default, two Types do not conform to each other. This query is intended to be redefined for specific conformance situations.
			result = (false)
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual bool conformsTo(std::shared_ptr<uml::Type> other) = 0;
			/*!
			Creates a(n) (binary) association between this type and the specified other type, with the specified navigabilities, aggregations, names, lower bounds, and upper bounds, and owned by this type's nearest package.
			*/
			 
			virtual std::shared_ptr<uml::Association> createAssociation(bool end1IsNavigable, uml::AggregationKind end1Aggregation, std::string end1Name, int end1Lower, int end1Upper, std::shared_ptr<uml::Type> end1Type, bool end2IsNavigable, uml::AggregationKind end2Aggregation, std::string end2Name, int end2Lower, int end2Upper) = 0;
			/*!
			Retrieves the associations in which this type is involved.
			*/
			 
			virtual std::shared_ptr<Bag<uml::Association>> getAssociations() = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			Specifies the owning Package of this Type, if any.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Package> getPackage() const = 0;
			/*!
			Specifies the owning Package of this Type, if any.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setPackage(std::weak_ptr<uml::Package>) = 0;

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
			Specifies the owning Package of this Type, if any.
			<p>From package UML::CommonStructure.</p>
			*/
			
			std::weak_ptr<uml::Package> m_package;
	};
}
#endif /* end of include guard: UML_TYPE_HPP */
