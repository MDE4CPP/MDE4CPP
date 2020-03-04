//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_PACKAGEABLEELEMENTPACKAGEABLEELEMENTIMPL_HPP
#define UML_PACKAGEABLEELEMENTPACKAGEABLEELEMENTIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../PackageableElement.hpp"

#include "uml/impl/NamedElementImpl.hpp"
#include "uml/impl/ParameterableElementImpl.hpp"

//*********************************
namespace uml 
{
	class PackageableElementImpl :virtual public NamedElementImpl, virtual public ParameterableElementImpl, virtual public PackageableElement 
	{
		public: 
			PackageableElementImpl(const PackageableElementImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			PackageableElementImpl& operator=(PackageableElementImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			PackageableElementImpl();
			virtual std::shared_ptr<PackageableElement> getThisPackageableElementPtr() const;
			virtual void setThisPackageableElementPtr(std::weak_ptr<PackageableElement> thisPackageableElementPtr);

			//Additional constructors for the containments back reference
			PackageableElementImpl(std::weak_ptr<uml::Namespace > par_namespace);


			//Additional constructors for the containments back reference
			PackageableElementImpl(std::weak_ptr<uml::Element > par_owner);


			//Additional constructors for the containments back reference
			PackageableElementImpl(std::weak_ptr<uml::Package > par_owningPackage);


			//Additional constructors for the containments back reference
			PackageableElementImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter);




		public:
			//destructor
			virtual ~PackageableElementImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 A PackageableElement owned by a Namespace must have a visibility.
			visibility = null implies namespace = null */ 
			virtual bool namespace_needs_visibility(Any diagnostics,std::map <   Any, Any >  context) ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::weak_ptr<uml::Package > getOwningPackage() const ;
			
			/*!
			 */
			virtual void setOwningPackage(std::shared_ptr<uml::Package> _owningPackage_owningPackage) ;
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Namespace > getNamespace() const ;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
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
			std::weak_ptr<PackageableElement> m_thisPackageableElementPtr;
	};
}
#endif /* end of include guard: UML_PACKAGEABLEELEMENTPACKAGEABLEELEMENTIMPL_HPP */
