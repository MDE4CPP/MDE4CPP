//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CONNECTORENDCONNECTORENDIMPL_HPP
#define UML_CONNECTORENDCONNECTORENDIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../ConnectorEnd.hpp"

#include "uml/impl/MultiplicityElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ConnectorEndImpl : virtual public MultiplicityElementImpl, virtual public ConnectorEnd 
	{
		public: 
			ConnectorEndImpl(const ConnectorEndImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ConnectorEndImpl& operator=(ConnectorEndImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ConnectorEndImpl();
			virtual std::shared_ptr<uml::ConnectorEnd> getThisConnectorEndPtr() const;
			virtual void setThisConnectorEndPtr(std::weak_ptr<uml::ConnectorEnd> thisConnectorEndPtr);

			//Additional constructors for the containments back reference
			ConnectorEndImpl(std::weak_ptr<uml::Connector> par_connector);
			//Additional constructors for the containments back reference
			ConnectorEndImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~ConnectorEndImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::weak_ptr<uml::Connector> getConnector() const ;
			virtual void setConnector(std::weak_ptr<uml::Connector>) ;
			/*!
			A derived property referencing the corresponding end on the Association which types the Connector owing this ConnectorEnd, if any. It is derived by selecting the end at the same place in the ordering of Association ends as this ConnectorEnd.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::shared_ptr<uml::Property> getDefiningEnd() const ;
			/*!
			Indicates the role of the internal structure of a Classifier with the Port to which the ConnectorEnd is attached.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::shared_ptr<uml::Property> getPartWithPort() const ;
			/*!
			Indicates the role of the internal structure of a Classifier with the Port to which the ConnectorEnd is attached.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual void setPartWithPort(std::shared_ptr<uml::Property>) ;
			/*!
			The ConnectableElement attached at this ConnectorEnd. When an instance of the containing Classifier is created, a link may (depending on the multiplicities) be created to an instance of the Classifier that types this ConnectableElement.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::shared_ptr<uml::ConnectableElement> getRole() const ;
			/*!
			The ConnectableElement attached at this ConnectorEnd. When an instance of the containing Classifier is created, a link may (depending on the multiplicities) be created to an instance of the Classifier that types this ConnectableElement.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual void setRole(std::shared_ptr<uml::ConnectableElement>) ;
			
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
			virtual bool eSet(int featureID, const std::shared_ptr<Any>& newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID,const std::shared_ptr<Bag<Any>>& arguments) ;

		private:
			std::weak_ptr<uml::ConnectorEnd> m_thisConnectorEndPtr;
	};
}
#endif /* end of include guard: UML_CONNECTORENDCONNECTORENDIMPL_HPP */
