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
			virtual std::shared_ptr<ConnectorEnd> getThisConnectorEndPtr() const;
			virtual void setThisConnectorEndPtr(std::weak_ptr<ConnectorEnd> thisConnectorEndPtr);

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
			/*!
			The multiplicity of the ConnectorEnd may not be more general than the multiplicity of the corresponding end of the Association typing the owning Connector, if any.
			self.compatibleWith(definingEnd)
			*/
			 
			virtual bool multiplicity(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			If a ConnectorEnd is attached to a Port of the containing Classifier, partWithPort will be empty.
			(role.oclIsKindOf(Port) and role.owner = connector.owner) implies partWithPort->isEmpty()
			*/
			 
			virtual bool part_with_port_empty(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			If a ConnectorEnd references a partWithPort, then the role must be a Port that is defined or inherited by the type of the partWithPort.
			partWithPort->notEmpty() implies 
			  (role.oclIsKindOf(Port) and partWithPort.type.oclAsType(Namespace).member->includes(role))
			*/
			 
			virtual bool role_and_part_with_port(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			The Property held in self.partWithPort must not be a Port.
			partWithPort->notEmpty() implies not partWithPort.oclIsKindOf(Port)
			*/
			 
			virtual bool self_part_with_port(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
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
			// Union Getter
			//*********************************
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;
			

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
			std::weak_ptr<ConnectorEnd> m_thisConnectorEndPtr;
	};
}
#endif /* end of include guard: UML_CONNECTORENDCONNECTORENDIMPL_HPP */
