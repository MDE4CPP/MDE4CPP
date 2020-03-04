//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_NAMESPACENAMESPACEIMPL_HPP
#define UML_NAMESPACENAMESPACEIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../Namespace.hpp"

#include "uml/impl/NamedElementImpl.hpp"

//*********************************
namespace uml 
{
	class NamespaceImpl :virtual public NamedElementImpl, virtual public Namespace 
	{
		public: 
			NamespaceImpl(const NamespaceImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			NamespaceImpl& operator=(NamespaceImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			NamespaceImpl();
			virtual std::shared_ptr<Namespace> getThisNamespacePtr() const;
			virtual void setThisNamespacePtr(std::weak_ptr<Namespace> thisNamespacePtr);

			//Additional constructors for the containments back reference
			NamespaceImpl(std::weak_ptr<uml::Namespace > par_namespace);


			//Additional constructors for the containments back reference
			NamespaceImpl(std::weak_ptr<uml::Element > par_owner);




		public:
			//destructor
			virtual ~NamespaceImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 A Namespace cannot have an ElementImport to one of its ownedMembers.
			elementImport.importedElement.oclAsType(Element)->excludesAll(ownedMember) */ 
			virtual bool cannot_import_ownedMembers(Any diagnostics,std::map <   Any, Any >  context) ;
			
			/*!
			 A Namespace cannot have a PackageImport to itself.
			packageImport.importedPackage.oclAsType(Namespace)->excludes(self) */ 
			virtual bool cannot_import_self(Any diagnostics,std::map <   Any, Any >  context) ;
			
			/*!
			 Creates an import of the specified element into this namespace with the specified visibility. */ 
			virtual std::shared_ptr<uml::ElementImport> createElementImport(std::shared_ptr<uml::PackageableElement>  element,uml::VisibilityKind visibility) ;
			
			/*!
			 Creates an import of the specified package into this namespace with the specified visibility. */ 
			virtual std::shared_ptr<uml::PackageImport> createPackageImport(std::shared_ptr<uml::Package>  package_,uml::VisibilityKind visibility) ;
			
			/*!
			 The query excludeCollisions() excludes from a set of PackageableElements any that would not be distinguishable from each other in this Namespace.
			result = (imps->reject(imp1  | imps->exists(imp2 | not imp1.isDistinguishableFrom(imp2, self))))
			<p>From package UML::CommonStructure.</p> */ 
			virtual std::shared_ptr<Bag<uml::PackageableElement> > excludeCollisions(std::shared_ptr<Bag<uml::PackageableElement> >  imps) ;
			
			/*!
			 Retrieves the elements imported by this namespace. */ 
			virtual std::shared_ptr<Bag<uml::PackageableElement> > getImportedElements() ;
			
			/*!
			 The importedMember property is derived as the PackageableElements that are members of this Namespace as a result of either PackageImports or ElementImports.
			result = (self.importMembers(elementImport.importedElement->asSet()->union(packageImport.importedPackage->collect(p | p.visibleMembers()))->asSet()))
			<p>From package UML::CommonStructure.</p> */ 
			virtual std::shared_ptr<Bag<uml::PackageableElement> > getImportedMembers() ;
			
			/*!
			 Retrieves the packages imported by this namespace. */ 
			virtual std::shared_ptr<Bag<uml::Package> > getImportedPackages() ;
			
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
			<p>From package UML::CommonStructure.</p> */ 
			virtual std::shared_ptr<Bag<std::string> > getNamesOfMember(std::shared_ptr<uml::NamedElement>  element) ;
			
			/*!
			 */ 
			virtual std::shared_ptr<Bag<uml::NamedElement> > getOwnedMembers() ;
			
			/*!
			 The query importMembers() defines which of a set of PackageableElements are actually imported into the Namespace. This excludes hidden ones, i.e., those which have names that conflict with names of ownedMembers, and it also excludes PackageableElements that would have the indistinguishable names when imported.
			result = (self.excludeCollisions(imps)->select(imp | self.ownedMember->forAll(mem | imp.isDistinguishableFrom(mem, self))))
			<p>From package UML::CommonStructure.</p> */ 
			virtual std::shared_ptr<Bag<uml::PackageableElement> > importMembers(std::shared_ptr<Bag<uml::PackageableElement> >  imps) ;
			
			/*!
			 The Boolean query membersAreDistinguishable() determines whether all of the Namespace's members are distinguishable within it.
			result = (member->forAll( memb |
			   member->excluding(memb)->forAll(other |
			       memb.isDistinguishableFrom(other, self))))
			<p>From package UML::CommonStructure.</p> */ 
			virtual bool membersAreDistinguishable() ;
			
			/*!
			 All the members of a Namespace are distinguishable within it.
			membersAreDistinguishable() */ 
			virtual bool members_distinguishable(Any diagnostics,std::map <   Any, Any >  context) ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 References the ElementImports owned by the Namespace.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::ElementImport, uml::Element>> getElementImport() const ;
			
			/*!
			 References the PackageableElements that are members of this Namespace as a result of either PackageImports or ElementImports.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Subset<uml::PackageableElement, uml::NamedElement>> getImportedMember() const ;
			
			
			
			/*!
			 Specifies a set of Constraints owned by this Namespace.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::Constraint, uml::NamedElement>> getOwnedRule() const ;
			
			/*!
			 References the PackageImports owned by the Namespace.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::PackageImport, uml::Element>> getPackageImport() const ;
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::NamedElement>> getMember() const ;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			 A collection of NamedElements owned by the Namespace.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> getOwnedMember() const ;/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Element > getOwner() const ; 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<Namespace> m_thisNamespacePtr;
	};
}
#endif /* end of include guard: UML_NAMESPACENAMESPACEIMPL_HPP */
