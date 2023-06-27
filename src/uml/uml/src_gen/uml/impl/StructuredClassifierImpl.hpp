//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_STRUCTUREDCLASSIFIERSTRUCTUREDCLASSIFIERIMPL_HPP
#define UML_STRUCTUREDCLASSIFIERSTRUCTUREDCLASSIFIERIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../StructuredClassifier.hpp"

#include "uml/impl/ClassifierImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API StructuredClassifierImpl : virtual public ClassifierImpl, virtual public StructuredClassifier 
	{
		public: 
			StructuredClassifierImpl(const StructuredClassifierImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			StructuredClassifierImpl& operator=(StructuredClassifierImpl const&); 

		protected:
			friend class umlFactoryImpl;
			StructuredClassifierImpl();
			virtual std::shared_ptr<uml::StructuredClassifier> getThisStructuredClassifierPtr() const;
			virtual void setThisStructuredClassifierPtr(std::weak_ptr<uml::StructuredClassifier> thisStructuredClassifierPtr);

			//Additional constructors for the containments back reference
			StructuredClassifierImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			StructuredClassifierImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			StructuredClassifierImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id);
			//Additional constructors for the containments back reference
			StructuredClassifierImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference

		public:
			//destructor
			virtual ~StructuredClassifierImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			/*!
			All features of type ConnectableElement, equivalent to all direct and inherited roles.
			result = (allFeatures()->select(oclIsKindOf(ConnectableElement))->collect(oclAsType(ConnectableElement))->asSet())
			<p>From package UML::StructuredClassifiers.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::ConnectableElement>> allRoles() ;
			/*!
			Creates a property with the specified name, type, lower bound, and upper bound as an owned attribute of this structured classifier.
			*/
			 
			virtual std::shared_ptr<uml::Property> createOwnedAttribute(std::string name, const std::shared_ptr<uml::Type>& type, int lower, int upper) ;
			/*!
			Derivation for StructuredClassifier::/part
			result = (ownedAttribute->select(isComposite)->asSet())
			<p>From package UML::StructuredClassifiers.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::Property>> getParts() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The Properties owned by the StructuredClassifier.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual const std::shared_ptr<SubsetUnion<uml::Property, uml::ConnectableElement, uml::NamedElement, uml::Property>>& getOwnedAttribute() const ;
			/*!
			The connectors owned by the StructuredClassifier.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::Connector, uml::Feature, uml::NamedElement>>& getOwnedConnector() const ;
			/*!
			The Properties specifying instances that the StructuredClassifier owns by composition. This collection is derived, selecting those owned Properties where isComposite is true.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Property>> getPart() const ;
			
			
			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			The roles that instances may play in this StructuredClassifier.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement>> getRole() const ;
			
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
			virtual bool eSet(int featureID, const std::shared_ptr<Any>& newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID,const std::shared_ptr<Bag<Any>>& arguments) ;

		private:
			std::weak_ptr<uml::StructuredClassifier> m_thisStructuredClassifierPtr;
	};
}
#endif /* end of include guard: UML_STRUCTUREDCLASSIFIERSTRUCTUREDCLASSIFIERIMPL_HPP */
