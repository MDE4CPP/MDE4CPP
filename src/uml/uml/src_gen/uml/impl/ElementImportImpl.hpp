//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ELEMENTIMPORTELEMENTIMPORTIMPL_HPP
#define UML_ELEMENTIMPORTELEMENTIMPORTIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../ElementImport.hpp"

#include "uml/impl/DirectedRelationshipImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ElementImportImpl : virtual public DirectedRelationshipImpl, virtual public ElementImport 
	{
		public: 
			ElementImportImpl(const ElementImportImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ElementImportImpl& operator=(ElementImportImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ElementImportImpl();
			virtual std::shared_ptr<uml::ElementImport> getThisElementImportPtr() const;
			virtual void setThisElementImportPtr(std::weak_ptr<uml::ElementImport> thisElementImportPtr);

			//Additional constructors for the containments back reference
			ElementImportImpl(std::weak_ptr<uml::Namespace> par_importingNamespace);
			//Additional constructors for the containments back reference
			ElementImportImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~ElementImportImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The query getName() returns the name under which the imported PackageableElement will be known in the importing namespace.
			result = (if alias->notEmpty() then
			  alias
			else
			  importedElement.name
			endif)
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual std::string getName() ;
			/*!
			An importedElement has either public visibility or no visibility at all.
			importedElement.visibility <> null implies importedElement.visibility = VisibilityKind::public
			*/
			 
			virtual bool imported_element_is_public(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			The visibility of an ElementImport is either public or private.
			visibility = VisibilityKind::public or visibility = VisibilityKind::private
			*/
			 
			virtual bool visibility_public_or_private(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Specifies the name that should be added to the importing Namespace in lieu of the name of the imported PackagableElement. The alias must not clash with any other member in the importing Namespace. By default, no alias is used.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual std::string getAlias() const ;
			/*!
			Specifies the name that should be added to the importing Namespace in lieu of the name of the imported PackagableElement. The alias must not clash with any other member in the importing Namespace. By default, no alias is used.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual void setAlias (std::string _alias);
			/*!
			Specifies the visibility of the imported PackageableElement within the importingNamespace, i.e., whether the  importedElement will in turn be visible to other Namespaces. If the ElementImport is public, the importedElement will be visible outside the importingNamespace while, if the ElementImport is private, it will not.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual uml::VisibilityKind getVisibility() const ;
			/*!
			Specifies the visibility of the imported PackageableElement within the importingNamespace, i.e., whether the  importedElement will in turn be visible to other Namespaces. If the ElementImport is public, the importedElement will be visible outside the importingNamespace while, if the ElementImport is private, it will not.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual void setVisibility (uml::VisibilityKind _visibility);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			Specifies the PackageableElement whose name is to be added to a Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<uml::PackageableElement> getImportedElement() const ;
			/*!
			Specifies the PackageableElement whose name is to be added to a Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setImportedElement(std::shared_ptr<uml::PackageableElement>) ;
			/*!
			Specifies the Namespace that imports a PackageableElement from another Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getImportingNamespace() const ;
			/*!
			Specifies the Namespace that imports a PackageableElement from another Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setImportingNamespace(std::weak_ptr<uml::Namespace>) ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			
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
			virtual std::shared_ptr<Any> eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, std::shared_ptr<Any> newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments) ;

		private:
			std::weak_ptr<uml::ElementImport> m_thisElementImportPtr;
	};
}
#endif /* end of include guard: UML_ELEMENTIMPORTELEMENTIMPORTIMPL_HPP */
