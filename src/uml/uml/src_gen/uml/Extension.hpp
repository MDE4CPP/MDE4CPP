//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_EXTENSION_HPP
#define UML_EXTENSION_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations

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
	class Class;
	class CollaborationUse;
	class Comment;
	class Constraint;
	class Dependency;
	class ElementImport;
	class Feature;
	class Generalization;
	class GeneralizationSet;
	class Package;
	class PackageImport;
	class Property;
	class Stereotype;
	class StringExpression;
	class Substitution;
	class TemplateBinding;
	class TemplateParameter;
	class TemplateSignature;
	class UseCase;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Association.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	An extension is used to indicate that the properties of a metaclass are extended through a stereotype, and gives the ability to flexibly add (and later remove) stereotypes to classes.
	<p>From package UML::Packages.</p>
	*/
	
	class UML_API Extension: virtual public Association
	{
		public:
 			Extension(const Extension &) {}

		protected:
			Extension(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Extension() {}

			//*********************************
			// Operations
			//*********************************
			
			/*!
			Retrieves the stereotype that extends a metaclass through this extension.
			*/
			 
			virtual std::shared_ptr<uml::Stereotype> getStereotype() = 0;
			/*!
			Retrieves the extension end that is typed by a stereotype (as opposed to a metaclass).
			*/
			 
			virtual std::shared_ptr<uml::Property> getStereotypeEnd() = 0;
			/*!
			The query isRequired() is true if the owned end has a multiplicity with the lower bound of 1.
			result = (ownedEnd.lowerBound() = 1)
			<p>From package UML::Packages.</p>
			*/
			 
			virtual bool isRequired() = 0;
			/*!
			An Extension is binary, i.e., it has only two memberEnds.
			memberEnd->size() = 2
			*/
			 
			virtual bool is_binary(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			The query metaclassEnd() returns the Property that is typed by a metaclass (as opposed to a stereotype).
			result = (memberEnd->reject(p | ownedEnd->includes(p.oclAsType(ExtensionEnd)))->any(true))
			<p>From package UML::Packages.</p>
			*/
			 
			virtual std::shared_ptr<uml::Property> metaclassEnd() = 0;
			/*!
			The non-owned end of an Extension is typed by a Class.
			metaclassEnd()->notEmpty() and metaclassEnd().type.oclIsKindOf(Class)
			*/
			 
			virtual bool non_owned_end(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Indicates whether an instance of the extending stereotype must be created when an instance of the extended class is created. The attribute value is derived from the value of the lower property of the ExtensionEnd referenced by Extension::ownedEnd; a lower value of 1 means that isRequired is true, but otherwise it is false. Since the default value of ExtensionEnd::lower is 0, the default value of isRequired is false.
			<p>From package UML::Packages.</p>
			*/
			 
			virtual bool getIsRequired() const = 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			References the Class that is extended through an Extension. The property is derived from the type of the memberEnd that is not the ownedEnd.
			<p>From package UML::Packages.</p>
			*/
			
			virtual std::shared_ptr<uml::Class> getMetaclass() const = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			Specifies each Feature directly defined in the classifier. Note that there may be members of the Classifier that are of the type Feature but are not included, e.g., inherited features.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> getFeature() const = 0;
			/*!
			A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::NamedElement>> getMember() const = 0;
			
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
			A collection of NamedElements owned by the Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement>> getOwnedMember() const = 0;
			/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const = 0;
			/*!
			The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const = 0;
			/*!
			Specifies the elements related by the Relationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getRelatedElement() const = 0;
			

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
			/*!
			Indicates whether an instance of the extending stereotype must be created when an instance of the extended class is created. The attribute value is derived from the value of the lower property of the ExtensionEnd referenced by Extension::ownedEnd; a lower value of 1 means that isRequired is true, but otherwise it is false. Since the default value of ExtensionEnd::lower is 0, the default value of isRequired is false.
			<p>From package UML::Packages.</p>
			*/
			
			bool m_isRequired= false;
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			References the Class that is extended through an Extension. The property is derived from the type of the memberEnd that is not the ownedEnd.
			<p>From package UML::Packages.</p>
			*/
			
			std::shared_ptr<uml::Class> m_metaclass;
	};
}
#endif /* end of include guard: UML_EXTENSION_HPP */
