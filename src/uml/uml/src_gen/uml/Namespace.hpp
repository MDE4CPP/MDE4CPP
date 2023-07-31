//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_NAMESPACE_HPP
#define UML_NAMESPACE_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 
template<class T, class ... U> class Subset;
template<class T, class ... U> class SubsetUnion;
template<class T> class Union;
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
	class Constraint;
	class Dependency;
	class ElementImport;
	class Package;
	class PackageImport;
	class PackageableElement;
	class StringExpression;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/NamedElement.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A Namespace is an Element in a model that owns and/or imports a set of NamedElements that can be identified by name.
	<p>From package UML::CommonStructure.</p>
	*/
	
	class UML_API Namespace: virtual public NamedElement
	{
		public:
 			Namespace(const Namespace &) {}

		protected:
			Namespace(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Namespace() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			A Namespace cannot have an ElementImport to one of its ownedMembers.
			elementImport.importedElement.oclAsType(Element)->excludesAll(ownedMember)
			*/
			 
			virtual bool cannot_import_ownedMembers(const Any& diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			A Namespace cannot have a PackageImport to itself.
			packageImport.importedPackage.oclAsType(Namespace)->excludes(self)
			*/
			 
			virtual bool cannot_import_self(const Any& diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			Creates an import of the specified element into this namespace with the specified visibility.
			*/
			 
			virtual std::shared_ptr<uml::ElementImport> createElementImport(const std::shared_ptr<uml::PackageableElement>& element, uml::VisibilityKind visibility) = 0;
			/*!
			Creates an import of the specified package into this namespace with the specified visibility.
			*/
			 
			virtual std::shared_ptr<uml::PackageImport> createPackageImport(const std::shared_ptr<uml::Package>& package_, uml::VisibilityKind visibility) = 0;
			/*!
			The query excludeCollisions() excludes from a set of PackageableElements any that would not be distinguishable from each other in this Namespace.
			result = (imps->reject(imp1  | imps->exists(imp2 | not imp1.isDistinguishableFrom(imp2, self))))
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::PackageableElement>> excludeCollisions(const std::shared_ptr<Bag<uml::PackageableElement>>& imps) = 0;
			/*!
			Retrieves the elements imported by this namespace.
			*/
			 
			virtual std::shared_ptr<Bag<uml::PackageableElement>> getImportedElements() = 0;
			/*!
			The importedMember property is derived as the PackageableElements that are members of this Namespace as a result of either PackageImports or ElementImports.
			result = (self.importMembers(elementImport.importedElement->asSet()->union(packageImport.importedPackage->collect(p | p.visibleMembers()))->asSet()))
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::PackageableElement>> getImportedMembers() = 0;
			/*!
			Retrieves the packages imported by this namespace.
			*/
			 
			virtual std::shared_ptr<Bag<uml::Package>> getImportedPackages() = 0;
			/*!
			The query getNamesOfMember() gives a set of all of the names that a member would have in a Namespace, taking importing into account. In general a member can have multiple names in a Namespace if it is imported more than once with different aliases.
			result = (if self.ownedMember ->includes(element)
			then Set{element.name}
			else let elementImports : Set(ElementImport) = self.elementImport->select(ei | ei.importedElement = element) in
			  if elementImports->notEmpty()
			  then
			     elementImports->collect(el | el.getName())->asSet()
			  else 
			     self.packageImport->select(pi | pi.importedPackage.visibleMembers().oclAsType(NamedElement)->includes(element))-> collect(pi | pi.importedPackage.getNamesOfMember(element))->asSet()
			  endif
			endif)
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual std::shared_ptr<Bag<std::string>> getNamesOfMember(const std::shared_ptr<uml::NamedElement>& element) = 0;
			virtual std::shared_ptr<Bag<uml::NamedElement>> getOwnedMembers() = 0;
			/*!
			The query importMembers() defines which of a set of PackageableElements are actually imported into the Namespace. This excludes hidden ones, i.e., those which have names that conflict with names of ownedMembers, and it also excludes PackageableElements that would have the indistinguishable names when imported.
			result = (self.excludeCollisions(imps)->select(imp | self.ownedMember->forAll(mem | imp.isDistinguishableFrom(mem, self))))
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::PackageableElement>> importMembers(const std::shared_ptr<Bag<uml::PackageableElement>>& imps) = 0;
			/*!
			The Boolean query membersAreDistinguishable() determines whether all of the Namespace's members are distinguishable within it.
			result = (member->forAll( memb |
			   member->excluding(memb)->forAll(other |
			       memb.isDistinguishableFrom(other, self))))
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual bool membersAreDistinguishable() = 0;
			/*!
			All the members of a Namespace are distinguishable within it.
			membersAreDistinguishable()
			*/
			 
			virtual bool members_distinguishable(const Any& diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			References the ElementImports owned by the Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual const std::shared_ptr<SubsetUnion<uml::ElementImport, uml::Element>>& getElementImport() const = 0;
			/*!
			References the PackageableElements that are members of this Namespace as a result of either PackageImports or ElementImports.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::PackageableElement, uml::NamedElement>>& getImportedMember() const = 0;
			
			
			/*!
			Specifies a set of Constraints owned by this Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual const std::shared_ptr<SubsetUnion<uml::Constraint, uml::NamedElement>>& getOwnedRule() const = 0;
			/*!
			References the PackageImports owned by the Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual const std::shared_ptr<SubsetUnion<uml::PackageImport, uml::Element>>& getPackageImport() const = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::NamedElement>> getMember() const = 0;
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
			References the ElementImports owned by the Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			mutable std::shared_ptr<SubsetUnion<uml::ElementImport, uml::Element>> m_elementImport;
			/*!
			References the PackageableElements that are members of this Namespace as a result of either PackageImports or ElementImports.
			<p>From package UML::CommonStructure.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::PackageableElement, uml::NamedElement>> m_importedMember;
			/*!
			A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p>
			*/
			
			mutable std::shared_ptr<Union<uml::NamedElement>> m_member;
			/*!
			A collection of NamedElements owned by the Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			mutable std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement>> m_ownedMember;
			/*!
			Specifies a set of Constraints owned by this Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			mutable std::shared_ptr<SubsetUnion<uml::Constraint, uml::NamedElement>> m_ownedRule;
			/*!
			References the PackageImports owned by the Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			mutable std::shared_ptr<SubsetUnion<uml::PackageImport, uml::Element>> m_packageImport;
	};
}
#endif /* end of include guard: UML_NAMESPACE_HPP */
