//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_VARIABLE_HPP
#define UML_VARIABLE_HPP


#include <memory>
#include <string>
// forward declarations
template<class T, class ... U> class Subset;


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
	class Action;
	class Activity;
	class Comment;
	class ConnectorEnd;
	class Dependency;
	class Namespace;
	class StringExpression;
	class StructuredActivityNode;
	class TemplateParameter;
	class Type;
	class ValueSpecification;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/ConnectableElement.hpp"
#include "uml/MultiplicityElement.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A Variable is a ConnectableElement that may store values during the execution of an Activity. Reading and writing the values of a Variable provides an alternative means for passing data than the use of ObjectFlows. A Variable may be owned directly by an Activity, in which case it is accessible from anywhere within that activity, or it may be owned by a StructuredActivityNode, in which case it is only accessible within that node.
	<p>From package UML::Activities.</p>
	*/
	
	class UML_API Variable: virtual public ConnectableElement, virtual public MultiplicityElement
	{
		public:
 			Variable(const Variable &) {}

		protected:
			Variable(){}
			//Additional constructors for the containments back reference
			Variable(std::weak_ptr<uml::Activity> par_activityScope);

			//Additional constructors for the containments back reference
			Variable(std::weak_ptr<uml::Namespace> par_namespace);

			//Additional constructors for the containments back reference
			Variable(std::weak_ptr<uml::Element> par_owner);

			//Additional constructors for the containments back reference
			Variable(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

			//Additional constructors for the containments back reference
			Variable(std::weak_ptr<uml::StructuredActivityNode> par_scope);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Variable() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			A Variable is accessible by Actions within its scope (the Activity or StructuredActivityNode that owns it).
			result = (if scope<>null then scope.allOwnedNodes()->includes(a)
			else a.containingActivity()=activityScope
			endif)
			<p>From package UML::Activities.</p>
			*/
			 
			virtual bool isAccessibleBy(std::shared_ptr<uml::Action> a) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			An Activity that owns the Variable.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::weak_ptr<uml::Activity> getActivityScope() const = 0;
			/*!
			An Activity that owns the Variable.
			<p>From package UML::Activities.</p>
			*/
			
			virtual void setActivityScope(std::weak_ptr<uml::Activity>) = 0;
			/*!
			A StructuredActivityNode that owns the Variable.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::weak_ptr<uml::StructuredActivityNode> getScope() const = 0;
			/*!
			A StructuredActivityNode that owns the Variable.
			<p>From package UML::Activities.</p>
			*/
			
			virtual void setScope(std::weak_ptr<uml::StructuredActivityNode>) = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const = 0;
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;
			/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const = 0;
			

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
			An Activity that owns the Variable.
			<p>From package UML::Activities.</p>
			*/
			
			std::weak_ptr<uml::Activity> m_activityScope;
			/*!
			A StructuredActivityNode that owns the Variable.
			<p>From package UML::Activities.</p>
			*/
			
			std::weak_ptr<uml::StructuredActivityNode> m_scope;
	};
}
#endif /* end of include guard: UML_VARIABLE_HPP */
