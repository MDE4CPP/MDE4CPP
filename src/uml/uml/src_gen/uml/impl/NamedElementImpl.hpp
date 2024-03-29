//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_NAMEDELEMENTNAMEDELEMENTIMPL_HPP
#define UML_NAMEDELEMENTNAMEDELEMENTIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../NamedElement.hpp"

#include "uml/impl/ElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API NamedElementImpl : virtual public ElementImpl, virtual public NamedElement 
	{
		public: 
			NamedElementImpl(const NamedElementImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			NamedElementImpl& operator=(NamedElementImpl const&); 

		protected:
			friend class umlFactoryImpl;
			NamedElementImpl();
			virtual std::shared_ptr<uml::NamedElement> getThisNamedElementPtr() const;
			virtual void setThisNamedElementPtr(std::weak_ptr<uml::NamedElement> thisNamedElementPtr);

			//Additional constructors for the containments back reference
			NamedElementImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			NamedElementImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~NamedElementImpl() = 0;
			
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
			 
			virtual std::shared_ptr<Bag<uml::Namespace> > allNamespaces() const ;
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
			 
			virtual std::shared_ptr<Bag<uml::Package> > allOwningPackages() ;
			/*!
			Creates a dependency between this named element and the specified supplier, owned by this named element's nearest package.
			*/
			 
			virtual std::shared_ptr<uml::Dependency> createDependency(std::shared_ptr<uml::NamedElement> supplier) ;
			/*!
			Creates a usage between this named element and the specified supplier, owned by this named element's nearest package.
			*/
			 
			virtual std::shared_ptr<uml::Usage> createUsage(std::shared_ptr<uml::NamedElement> supplier) ;
			/*!
			result = (Dependency.allInstances()->select(d | d.client->includes(self)))
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::Dependency> > getClientDependencies() ;
			/*!
			Retrieves a localized label for this named element.
			*/
			 
			virtual std::string getLabel() ;
			/*!
			Retrieves a label for this named element, localized if indicated.
			*/
			 
			virtual std::string getLabel(bool localize) ;
			
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
			 
			virtual std::string getQualifiedName() const ;
			/*!
			If there is no name, or one of the containing Namespaces has no name, there is no qualifiedName.
			name=null or allNamespaces()->select( ns | ns.name=null )->notEmpty() implies qualifiedName = null
			*/
			 
			virtual bool has_no_qualified_name(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			When there is a name, and all of the containing Namespaces have a name, the qualifiedName is constructed from the name of the NamedElement and the names of the containing Namespaces.
			(name <> null and allNamespaces()->select(ns | ns.name = null)->isEmpty()) implies
			  qualifiedName = allNamespaces()->iterate( ns : Namespace; agg: String = name | ns.name.concat(self.separator()).concat(agg))
			*/
			 
			virtual bool has_qualified_name(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			The query isDistinguishableFrom() determines whether two NamedElements may logically co-exist within a Namespace. By default, two named elements are distinguishable if (a) they have types neither of which is a kind of the other or (b) they have different names.
			result = ((self.oclIsKindOf(n.oclType()) or n.oclIsKindOf(self.oclType())) implies
			    ns.getNamesOfMember(self)->intersection(ns.getNamesOfMember(n))->isEmpty()
			)
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual bool isDistinguishableFrom(std::shared_ptr<uml::NamedElement> n,std::shared_ptr<uml::Namespace> ns) ;
			/*!
			The query separator() gives the string that is used to separate names when constructing a qualifiedName.
			result = ('::')
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual std::string separator() const ;
			/*!
			If a NamedElement is owned by something other than a Namespace, it does not have a visibility. One that is not owned by anything (and hence must be a Package, as this is the only kind of NamedElement that overrides mustBeOwned()) may have a visibility.
			(namespace = null and owner <> null) implies visibility = null
			*/
			 
			virtual bool visibility_needs_ownership(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			The name of the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual std::string getName() const ;
			/*!
			The name of the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual void setName (std::string _name);
			
			/*!
			Determines whether and how the NamedElement is visible outside its owning Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual uml::VisibilityKind getVisibility() const ;
			/*!
			Determines whether and how the NamedElement is visible outside its owning Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual void setVisibility (uml::VisibilityKind _visibility);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			Indicates the Dependencies that reference this NamedElement as a client.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Dependency>> getClientDependency() const ;
			/*!
			The StringExpression used to define the name of this NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<uml::StringExpression> getNameExpression() const ;
			/*!
			The StringExpression used to define the name of this NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setNameExpression(std::shared_ptr<uml::StringExpression>) ;
			
			
			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const ;
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;
			/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ;
			
			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments) ;

		private:
			std::weak_ptr<uml::NamedElement> m_thisNamedElementPtr;
	};
}
#endif /* end of include guard: UML_NAMEDELEMENTNAMEDELEMENTIMPL_HPP */
