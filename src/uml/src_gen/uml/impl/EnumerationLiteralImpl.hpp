//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ENUMERATIONLITERALENUMERATIONLITERALIMPL_HPP
#define UML_ENUMERATIONLITERALENUMERATIONLITERALIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../EnumerationLiteral.hpp"

#include "uml/impl/InstanceSpecificationImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API EnumerationLiteralImpl : virtual public InstanceSpecificationImpl, virtual public EnumerationLiteral 
	{
		public: 
			EnumerationLiteralImpl(const EnumerationLiteralImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			EnumerationLiteralImpl& operator=(EnumerationLiteralImpl const&); 

		protected:
			friend class umlFactoryImpl;
			EnumerationLiteralImpl();
			virtual std::shared_ptr<EnumerationLiteral> getThisEnumerationLiteralPtr() const;
			virtual void setThisEnumerationLiteralPtr(std::weak_ptr<EnumerationLiteral> thisEnumerationLiteralPtr);

			//Additional constructors for the containments back reference
			EnumerationLiteralImpl(std::weak_ptr<uml::Enumeration> par_enumeration);
			//Additional constructors for the containments back reference
			EnumerationLiteralImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			EnumerationLiteralImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			EnumerationLiteralImpl(std::weak_ptr<uml::Package> par_owningPackage);
			//Additional constructors for the containments back reference
			EnumerationLiteralImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

		public:
			//destructor
			virtual ~EnumerationLiteralImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual std::shared_ptr<Bag<uml::Classifier> > getClassifiers() ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The Enumeration that this EnumerationLiteral is a member of.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			virtual std::weak_ptr<uml::Enumeration> getEnumeration() const ;
			/*!
			The Enumeration that this EnumerationLiteral is a member of.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			virtual void setEnumeration(std::weak_ptr<uml::Enumeration>) ;
			
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const ;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ;
			

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
			

			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<EnumerationLiteral> m_thisEnumerationLiteralPtr;
	};
}
#endif /* end of include guard: UML_ENUMERATIONLITERALENUMERATIONLITERALIMPL_HPP */
