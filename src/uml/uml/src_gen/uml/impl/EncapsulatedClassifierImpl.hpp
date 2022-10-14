//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ENCAPSULATEDCLASSIFIERENCAPSULATEDCLASSIFIERIMPL_HPP
#define UML_ENCAPSULATEDCLASSIFIERENCAPSULATEDCLASSIFIERIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../EncapsulatedClassifier.hpp"

#include "uml/impl/StructuredClassifierImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API EncapsulatedClassifierImpl : virtual public StructuredClassifierImpl, virtual public EncapsulatedClassifier 
	{
		public: 
			EncapsulatedClassifierImpl(const EncapsulatedClassifierImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			EncapsulatedClassifierImpl& operator=(EncapsulatedClassifierImpl const&); 

		protected:
			friend class umlFactoryImpl;
			EncapsulatedClassifierImpl();
			virtual std::shared_ptr<uml::EncapsulatedClassifier> getThisEncapsulatedClassifierPtr() const;
			virtual void setThisEncapsulatedClassifierPtr(std::weak_ptr<uml::EncapsulatedClassifier> thisEncapsulatedClassifierPtr);

			//Additional constructors for the containments back reference
			EncapsulatedClassifierImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			EncapsulatedClassifierImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			EncapsulatedClassifierImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id);
			//Additional constructors for the containments back reference
			EncapsulatedClassifierImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference

		public:
			//destructor
			virtual ~EncapsulatedClassifierImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			/*!
			Derivation for EncapsulatedClassifier::/ownedPort : Port
			result = (ownedAttribute->select(oclIsKindOf(Port))->collect(oclAsType(Port))->asOrderedSet())
			<p>From package UML::StructuredClassifiers.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::Port>> getOwnedPorts() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The Ports owned by the EncapsulatedClassifier.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Port, uml::Property /*Subset does not reference a union*/>> getOwnedPort() const ;
			
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
			std::weak_ptr<uml::EncapsulatedClassifier> m_thisEncapsulatedClassifierPtr;
	};
}
#endif /* end of include guard: UML_ENCAPSULATEDCLASSIFIERENCAPSULATEDCLASSIFIERIMPL_HPP */
