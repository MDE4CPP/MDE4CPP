//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_NAMEDELEMENT_HPP
#define UML_NAMEDELEMENT_HPP


#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 
template<class T, class ... U> class Subset;
template<class T, class ... U> class SubsetUnion;


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
	class Package;
	class StringExpression;
	class Usage;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Element.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A NamedElement is an Element in a model that may have a name. The name may be given directly and/or via the use of a StringExpression.
	<p>From package UML::CommonStructure.</p>
	*/
	
	class UML_API NamedElement : virtual public Element
	{
		public:
 			NamedElement(const NamedElement &) {}

		protected:
			NamedElement(){}
			//Additional constructors for the containments back reference
			NamedElement(std::weak_ptr<uml::Namespace> par_namespace);

			//Additional constructors for the containments back reference
			NamedElement(std::weak_ptr<uml::Element> par_owner);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~NamedElement() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The query allNamespaces() gives the sequence of Namespaces in which the NamedElement is nested, working outwards.
			result = (
			if owner = null
			  then OrderedSet{}
			else
			  let enclosingNamespace : Namespace =
			    if owner.oclIsKindOf(TemplateParameter) and owner.oclAsType(TemplateParameter).signature.template.oclIsKindOf(Namespace)
			      then owner.oclAsType(TemplateParameter).signature.template.oclAsType(Namespace)
			    else
			      namespace
			    endif
			  in enclosingNamespace.allNamespaces()->prepend(enclosingNamespace)
			endif)
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::Namespace>> allNamespaces() const = 0;
			/*!
			The query allOwningPackages() returns the set of all the enclosing Namespaces of this NamedElement, working outwards, that are Packages, up to but not including the first such Namespace that is not a Package.
			result = (if namespace.oclIsKindOf(Package)
			then
			  let owningPackage : Package = namespace.oclAsType(Package) in
			    owningPackage->union(owningPackage.allOwningPackages())
			else
			  null
			endif)
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::Package>> allOwningPackages() = 0;
			/*!
			Creates a dependency between this named element and the specified supplier, owned by this named element's nearest package.
			*/
			 
			virtual std::shared_ptr<uml::Dependency> createDependency(std::shared_ptr<uml::NamedElement> supplier) = 0;
			/*!
			Creates a usage between this named element and the specified supplier, owned by this named element's nearest package.
			*/
			 
			virtual std::shared_ptr<uml::Usage> createUsage(std::shared_ptr<uml::NamedElement> supplier) = 0;
			/*!
			result = (Dependency.allInstances()->select(d | d.client->includes(self)))
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::Dependency>> getClientDependencies() = 0;
			/*!
			Retrieves a localized label for this named element.
			*/
			 
			virtual std::string getLabel() = 0;
			/*!
			Retrieves a label for this named element, localized if indicated.
			*/
			 
			virtual std::string getLabel(bool localize) = 0;
			
			/*!
			When a NamedElement has a name, and all of its containing Namespaces have a name, the qualifiedName is constructed from the name of the NamedElement and the names of the containing Namespaces.
			result = (if self.name <> null and self.allNamespaces()->select( ns | ns.name=null )->isEmpty()
			then 
			    self.allNamespaces()->iterate( ns : Namespace; agg: String = self.name | ns.name.concat(self.separator()).concat(agg))
			else
			   null
			endif)
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual std::string getQualifiedName() const = 0;
			/*!
			The query isDistinguishableFrom() determines whether two NamedElements may logically co-exist within a Namespace. By default, two named elements are distinguishable if (a) they have types neither of which is a kind of the other or (b) they have different names.
			result = ((self.oclIsKindOf(n.oclType()) or n.oclIsKindOf(self.oclType())) implies
			    ns.getNamesOfMember(self)->intersection(ns.getNamesOfMember(n))->isEmpty()
			)
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual bool isDistinguishableFrom(std::shared_ptr<uml::NamedElement> n, std::shared_ptr<uml::Namespace> ns) = 0;
			/*!
			The query separator() gives the string that is used to separate names when constructing a qualifiedName.
			result = ('::')
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual std::string separator() const = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			The name of the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual std::string getName() const = 0;
			/*!
			The name of the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual void setName (std::string _name)= 0;
			
			/*!
			Determines whether and how the NamedElement is visible outside its owning Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual uml::VisibilityKind getVisibility() const = 0;
			/*!
			Determines whether and how the NamedElement is visible outside its owning Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual void setVisibility (uml::VisibilityKind _visibility)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			Indicates the Dependencies that reference this NamedElement as a client.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Dependency>> getClientDependency() const = 0;
			/*!
			The StringExpression used to define the name of this NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<uml::StringExpression> getNameExpression() const = 0;
			/*!
			The StringExpression used to define the name of this NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setNameExpression(std::shared_ptr<uml::StringExpression>) = 0;
			

			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const = 0;

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
			The name of the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			std::string m_name= "";
			/*!
			A name that allows the NamedElement to be identified within a hierarchy of nested Namespaces. It is constructed from the names of the containing Namespaces starting at the root of the hierarchy and ending with the name of the NamedElement itself.
			<p>From package UML::CommonStructure.</p>
			*/
			
			std::string m_qualifiedName= "";
			/*!
			Determines whether and how the NamedElement is visible outside its owning Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			uml::VisibilityKind m_visibility= uml::VisibilityKind::PUBLIC;
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			Indicates the Dependencies that reference this NamedElement as a client.
			<p>From package UML::CommonStructure.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::Dependency>> m_clientDependency;
			/*!
			The StringExpression used to define the name of this NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			std::shared_ptr<uml::StringExpression> m_nameExpression;
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			std::weak_ptr<uml::Namespace> m_namespace;
	};
}
#endif /* end of include guard: UML_NAMEDELEMENT_HPP */
