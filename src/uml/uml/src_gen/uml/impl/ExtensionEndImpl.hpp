//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_EXTENSIONENDEXTENSIONENDIMPL_HPP
#define UML_EXTENSIONENDEXTENSIONENDIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../ExtensionEnd.hpp"

#include "uml/impl/PropertyImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ExtensionEndImpl : virtual public PropertyImpl, virtual public ExtensionEnd 
	{
		public: 
			ExtensionEndImpl(const ExtensionEndImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ExtensionEndImpl& operator=(ExtensionEndImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ExtensionEndImpl();
			virtual std::shared_ptr<uml::ExtensionEnd> getThisExtensionEndPtr() const;
			virtual void setThisExtensionEndPtr(std::weak_ptr<uml::ExtensionEnd> thisExtensionEndPtr);

			//Additional constructors for the containments back reference
			ExtensionEndImpl(std::weak_ptr<uml::Property> par_associationEnd);
			//Additional constructors for the containments back reference
			ExtensionEndImpl(std::weak_ptr<uml::Class> par_class);
			//Additional constructors for the containments back reference
			ExtensionEndImpl(std::weak_ptr<uml::DataType> par_datatype);
			//Additional constructors for the containments back reference
			ExtensionEndImpl(std::weak_ptr<uml::Interface> par_interface);
			//Additional constructors for the containments back reference
			ExtensionEndImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ExtensionEndImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			ExtensionEndImpl(std::weak_ptr<uml::Association> par_owningAssociation);
			//Additional constructors for the containments back reference
			ExtensionEndImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

		public:
			//destructor
			virtual ~ExtensionEndImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The aggregation of an ExtensionEnd is composite.
			self.aggregation = AggregationKind::composite
			*/
			 
			virtual bool aggregation(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			The multiplicity of ExtensionEnd is 0..1 or 1.
			(lowerBound() = 0 or lowerBound() = 1) and upperBound() = 1
			*/
			 
			virtual bool multiplicity(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			
			//*********************************
			// Union Reference Getters
			//*********************************
			
			/*!
			The Classifiers that have this Feature as a feature.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Classifier>> getFeaturingClassifier() const ;
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
			/*!
			The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const ;
			/*!
			The contexts that this element may be redefined from.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Classifier>> getRedefinitionContext() const ;
			
			
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
			std::weak_ptr<uml::ExtensionEnd> m_thisExtensionEndPtr;
	};
}
#endif /* end of include guard: UML_EXTENSIONENDEXTENSIONENDIMPL_HPP */
