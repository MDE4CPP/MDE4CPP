//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CONNECTOR_HPP
#define UML_CONNECTOR_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 
template<class T, class ... U> class Subset;

class AnyObject;
typedef std::shared_ptr<AnyObject> Any;

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
	class Association;
	class Behavior;
	class Classifier;
	class Comment;
	class ConnectorEnd;
	class Dependency;
	class Namespace;
	class StringExpression;
	class StructuredClassifier;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Feature.hpp"

// enum includes
#include "uml/ConnectorKind.hpp"

#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A Connector specifies links that enables communication between two or more instances. In contrast to Associations, which specify links between any instance of the associated Classifiers, Connectors specify links between instances playing the connected parts only.
	<p>From package UML::StructuredClassifiers.</p>
	*/
	
	class UML_API Connector: virtual public Feature
	{
		public:
 			Connector(const Connector &) {}

		protected:
			Connector(){}
			//Additional constructors for the containments back reference
			Connector(std::weak_ptr<uml::Namespace> par_namespace);

			//Additional constructors for the containments back reference
			Connector(std::weak_ptr<uml::Element> par_owner);

			//Additional constructors for the containments back reference
			Connector(std::weak_ptr<uml::StructuredClassifier> par_structuredClassifier);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Connector() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			Derivation for Connector::/kind : ConnectorKind
			result = (if end->exists(
					role.oclIsKindOf(Port) 
					and partWithPort->isEmpty()
					and not role.oclAsType(Port).isBehavior)
			then ConnectorKind::delegation 
			else ConnectorKind::assembly 
			endif)
			<p>From package UML::StructuredClassifiers.</p>
			*/
			 
			virtual uml::ConnectorKind getKind() = 0;/*!
			The ConnectableElements attached as roles to each ConnectorEnd owned by a Connector must be owned or inherited roles of the Classifier that owned the Connector, or they must be Ports of such roles.
			structuredClassifier <> null
			and
			  end->forAll( e | structuredClassifier.allRoles()->includes(e.role)
			or
			  e.role.oclIsKindOf(Port) and structuredClassifier.allRoles()->includes(e.partWithPort))
			*/
			 
			virtual bool roles(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;/*!
			The types of the ConnectableElements that the ends of a Connector are attached to must conform to the types of the ends of the Association that types the Connector, if any.
			type<>null implies 
			  let noOfEnds : Integer = end->size() in 
			  (type.memberEnd->size() = noOfEnds) and Sequence{1..noOfEnds}->forAll(i | end->at(i).role.type.conformsTo(type.memberEnd->at(i).type))
			*/
			 
			virtual bool types(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			//*********************************
			// Attributes Getter & Setter
			//*********************************
			/*!
			Indicates the kind of Connector. This is derived: a Connector with one or more ends connected to a Port which is not on a Part and which is not a behavior port is a delegation; otherwise it is an assembly.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			 
			virtual uml::ConnectorKind getKind() const = 0;
			
			
			//*********************************
			// References Getter & Setter
			//*********************************
			/*!
			The set of Behaviors that specify the valid interaction patterns across the Connector.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Behavior>> getContract() const = 0;
			
			/*!
			A Connector has at least two ConnectorEnds, each representing the participation of instances of the Classifiers typing the ConnectableElements attached to the end. The set of ConnectorEnds is ordered.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ConnectorEnd, uml::Element>> getEnd() const = 0;
			
			/*!
			A Connector may be redefined when its containing Classifier is specialized. The redefining Connector may have a type that specializes the type of the redefined Connector. The types of the ConnectorEnds of the redefining Connector may specialize the types of the ConnectorEnds of the redefined Connector. The properties of the ConnectorEnds of the redefining Connector may be replaced.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Connector, uml::RedefinableElement>> getRedefinedConnector() const = 0;
			
			
			virtual std::weak_ptr<uml::StructuredClassifier> getStructuredClassifier() const = 0;
			
			virtual void setStructuredClassifier(std::weak_ptr<uml::StructuredClassifier>) = 0;
			/*!
			An optional Association that classifies links corresponding to this Connector.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::shared_ptr<uml::Association> getType() const = 0;
			/*!
			An optional Association that classifies links corresponding to this Connector.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual void setType(std::shared_ptr<uml::Association>) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			Indicates the kind of Connector. This is derived: a Connector with one or more ends connected to a Port which is not on a Part and which is not a behavior port is a delegation; otherwise it is an assembly.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			uml::ConnectorKind m_kind = ConnectorKind::ASSEMBLY;
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The set of Behaviors that specify the valid interaction patterns across the Connector.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::Behavior>> m_contract;/*!
			A Connector has at least two ConnectorEnds, each representing the participation of instances of the Classifiers typing the ConnectableElements attached to the end. The set of ConnectorEnds is ordered.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::ConnectorEnd, uml::Element>> m_end;/*!
			A Connector may be redefined when its containing Classifier is specialized. The redefining Connector may have a type that specializes the type of the redefined Connector. The types of the ConnectorEnds of the redefining Connector may specialize the types of the ConnectorEnds of the redefined Connector. The properties of the ConnectorEnds of the redefining Connector may be replaced.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Connector, uml::RedefinableElement>> m_redefinedConnector;
			std::weak_ptr<uml::StructuredClassifier> m_structuredClassifier;/*!
			An optional Association that classifies links corresponding to this Connector.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			std::shared_ptr<uml::Association> m_type;

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			The Classifiers that have this Feature as a feature.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Classifier>> getFeaturingClassifier() const = 0;/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const = 0;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const = 0;/*!
			The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const = 0;/*!
			The contexts that this element may be redefined from.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Classifier>> getRedefinitionContext() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_CONNECTOR_HPP */
