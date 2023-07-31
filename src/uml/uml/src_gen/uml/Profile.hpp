//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_PROFILE_HPP
#define UML_PROFILE_HPP

#include <map>
#include <unordered_map>

#include <memory>
#include <string>
// forward declarations
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
namespace ecore 
{
	class ENamedElement;
	class EObject;
	class EPackage;
}
namespace uml 
{
	class Class;
	class Classifier;
	class Comment;
	class Constraint;
	class Dependency;
	class ElementImport;
	class Extension;
	class Model;
	class PackageImport;
	class PackageMerge;
	class ProfileApplication;
	class Stereotype;
	class StringExpression;
	class TemplateBinding;
	class TemplateParameter;
	class TemplateSignature;
	class Type;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Package.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A profile defines limited extensions to a reference metamodel with the purpose of adapting the metamodel to a specific platform or domain.
	<p>From package UML::Packages.</p>
	*/
	
	class UML_API Profile: virtual public Package
	{
		public:
 			Profile(const Profile &) {}

		protected:
			Profile(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Profile() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			Creates and returns an instance of (the Ecore representation of) the specified classifier defined in this profile.
			*/
			 
			virtual std::shared_ptr<ecore::EObject> create(const std::shared_ptr<uml::Classifier>& classifier) = 0;
			/*!
			Defines this profile by (re)creating Ecore representations of its current contents.
			*/
			 
			virtual std::shared_ptr<ecore::EPackage> define() = 0;
			/*!
			Defines this profile by (re)creating Ecore representations of its current contents, using the specified options, diagnostics, and context.
			*/
			 
			virtual std::shared_ptr<ecore::EPackage> define(std::shared_ptr<std::unordered_map < std::string, std::string>> options, const Any& diagnostics, std::shared_ptr<std::unordered_map < Any, Any>> context) = 0;
			/*!
			Retrieves the current definition (Ecore representation) of this profile.
			*/
			 
			virtual std::shared_ptr<ecore::EPackage> getDefinition() = 0;
			/*!
			Retrieves the current definition (Ecore representation) of the specified named element in this profile.
			*/
			 
			virtual std::shared_ptr<ecore::ENamedElement> getDefinition(const std::shared_ptr<uml::NamedElement>& namedElement) = 0;
			/*!
			Retrieves the extensions owned by this profile, excluding non-required extensions if indicated.
			*/
			 
			virtual std::shared_ptr<Bag<uml::Extension>> getOwnedExtensions(bool requiredOnly) = 0;
			/*!
			Retrieves the metaclasses referenced by this profile.
			*/
			 
			virtual std::shared_ptr<Bag<uml::Class>> getReferencedMetaclasses() = 0;
			/*!
			Retrieves the metamodels referenced by this profile.
			*/
			 
			virtual std::shared_ptr<Bag<uml::Model>> getReferencedMetamodels() = 0;
			/*!
			Determines whether this profile is defined.
			*/
			 
			virtual bool isDefined() = 0;
			/*!
			An element imported as a metaclassReference is not specialized or generalized in a Profile.
			metaclassReference.importedElement->
				select(c | c.oclIsKindOf(Classifier) and
					(c.oclAsType(Classifier).allParents()->collect(namespace)->includes(self)))->isEmpty()
			and 
			packagedElement->
			    select(oclIsKindOf(Classifier))->collect(oclAsType(Classifier).allParents())->
			       intersection(metaclassReference.importedElement->select(oclIsKindOf(Classifier))->collect(oclAsType(Classifier)))->isEmpty()
			*/
			 
			virtual bool metaclass_reference_not_specialized(const Any& diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			All elements imported either as metaclassReferences or through metamodelReferences are members of the same base reference metamodel.
			metamodelReference.importedPackage.elementImport.importedElement.allOwningPackages()->
			  union(metaclassReference.importedElement.allOwningPackages() )->notEmpty()
			*/
			 
			virtual bool references_same_metamodel(const Any& diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			References a metaclass that may be extended.
			<p>From package UML::Packages.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::ElementImport, uml::ElementImport /*Subset does not reference a union*/>>& getMetaclassReference() const = 0;
			/*!
			References a package containing (directly or indirectly) metaclasses that may be extended.
			<p>From package UML::Packages.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::PackageImport, uml::PackageImport /*Subset does not reference a union*/>>& getMetamodelReference() const = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
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
			References a metaclass that may be extended.
			<p>From package UML::Packages.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::ElementImport, uml::ElementImport /*Subset does not reference a union*/>> m_metaclassReference;
			/*!
			References a package containing (directly or indirectly) metaclasses that may be extended.
			<p>From package UML::Packages.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::PackageImport, uml::PackageImport /*Subset does not reference a union*/>> m_metamodelReference;
	};
}
#endif /* end of include guard: UML_PROFILE_HPP */
