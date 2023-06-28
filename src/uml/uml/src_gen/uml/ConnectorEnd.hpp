//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CONNECTOREND_HPP
#define UML_CONNECTOREND_HPP


#include <memory>
#include <string>
// forward declarations


//*********************************
// generated Includes
#include <map> // used for Persistence
#include <vector> // used for Persistence
namespace persistence
{
	namespace interfaces
	{
		class XLoadHandler; // used for Persistence
		class XSaveHandler; // used for Persistence
	}
}

namespace uml
{
	class umlFactory;
}

//Forward Declaration for used types 
namespace uml 
{
	class Comment;
	class ConnectableElement;
	class Connector;
	class Property;
	class ValueSpecification;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/MultiplicityElement.hpp"




//*********************************
namespace uml 
{
	/*!
	A ConnectorEnd is an endpoint of a Connector, which attaches the Connector to a ConnectableElement.
	<p>From package UML::StructuredClassifiers.</p>
	*/
	
	class UML_API ConnectorEnd : virtual public MultiplicityElement
	{
		public:
 			ConnectorEnd(const ConnectorEnd &) {}

		protected:
			ConnectorEnd(){}
			//Additional constructors for the containments back reference
			ConnectorEnd(std::weak_ptr<uml::Connector> par_connector);

			//Additional constructors for the containments back reference
			ConnectorEnd(std::weak_ptr<uml::Element> par_owner);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ConnectorEnd() {}

			//*********************************
			// Operations
			//*********************************
			

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::weak_ptr<uml::Connector> getConnector() const = 0;
			virtual void setConnector(std::weak_ptr<uml::Connector>) = 0;
			/*!
			A derived property referencing the corresponding end on the Association which types the Connector owing this ConnectorEnd, if any. It is derived by selecting the end at the same place in the ordering of Association ends as this ConnectorEnd.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual const std::shared_ptr<uml::Property>& getDefiningEnd() const = 0;
			/*!
			Indicates the role of the internal structure of a Classifier with the Port to which the ConnectorEnd is attached.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual const std::shared_ptr<uml::Property>& getPartWithPort() const = 0;
			/*!
			Indicates the role of the internal structure of a Classifier with the Port to which the ConnectorEnd is attached.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual void setPartWithPort(const std::shared_ptr<uml::Property>&) = 0;
			/*!
			The ConnectableElement attached at this ConnectorEnd. When an instance of the containing Classifier is created, a link may (depending on the multiplicities) be created to an instance of the Classifier that types this ConnectableElement.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual const std::shared_ptr<uml::ConnectableElement>& getRole() const = 0;
			/*!
			The ConnectableElement attached at this ConnectorEnd. When an instance of the containing Classifier is created, a link may (depending on the multiplicities) be created to an instance of the Classifier that types this ConnectableElement.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual void setRole(const std::shared_ptr<uml::ConnectableElement>&) = 0;

			//*********************************
			// Union Reference Getters
			//*********************************

			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 

			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			//*********************************
			// Reference Members
			//*********************************
			std::weak_ptr<uml::Connector> m_connector;
			/*!
			A derived property referencing the corresponding end on the Association which types the Connector owing this ConnectorEnd, if any. It is derived by selecting the end at the same place in the ordering of Association ends as this ConnectorEnd.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			std::shared_ptr<uml::Property> m_definingEnd;
			/*!
			Indicates the role of the internal structure of a Classifier with the Port to which the ConnectorEnd is attached.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			std::shared_ptr<uml::Property> m_partWithPort;
			/*!
			The ConnectableElement attached at this ConnectorEnd. When an instance of the containing Classifier is created, a link may (depending on the multiplicities) be created to an instance of the Classifier that types this ConnectableElement.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			std::shared_ptr<uml::ConnectableElement> m_role;
	};
}
#endif /* end of include guard: UML_CONNECTOREND_HPP */
