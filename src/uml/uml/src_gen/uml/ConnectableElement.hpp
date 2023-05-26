//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CONNECTABLEELEMENT_HPP
#define UML_CONNECTABLEELEMENT_HPP


#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 


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
	class ConnectorEnd;
	class Dependency;
	class Namespace;
	class StringExpression;
	class TemplateParameter;
	class Type;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/ParameterableElement.hpp"
#include "uml/TypedElement.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	ConnectableElement is an abstract metaclass representing a set of instances that play roles of a StructuredClassifier. ConnectableElements may be joined by attached Connectors and specify configurations of linked instances to be created within an instance of the containing StructuredClassifier.
	<p>From package UML::StructuredClassifiers.</p>
	*/
	
	class UML_API ConnectableElement : virtual public ParameterableElement, virtual public TypedElement
	{
		public:
 			ConnectableElement(const ConnectableElement &) {}

		protected:
			ConnectableElement(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ConnectableElement() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			Derivation for ConnectableElement::/end : ConnectorEnd
			result = (ConnectorEnd.allInstances()->select(role = self))
			<p>From package UML::StructuredClassifiers.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::ConnectorEnd>> getEnds() = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			A set of ConnectorEnds that attach to this ConnectableElement.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual const std::shared_ptr<Bag<uml::ConnectorEnd>>& getEnd() const = 0;

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
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			A set of ConnectorEnds that attach to this ConnectableElement.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::ConnectorEnd>> m_end;
	};
}
#endif /* end of include guard: UML_CONNECTABLEELEMENT_HPP */
