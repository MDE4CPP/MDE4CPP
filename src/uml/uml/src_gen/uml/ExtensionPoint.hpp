//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_EXTENSIONPOINT_HPP
#define UML_EXTENSIONPOINT_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations
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
	class Classifier;
	class Comment;
	class Dependency;
	class Namespace;
	class StringExpression;
	class UseCase;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/RedefinableElement.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	An ExtensionPoint identifies a point in the behavior of a UseCase where that behavior can be extended by the behavior of some other (extending) UseCase, as specified by an Extend relationship.
	<p>From package UML::UseCases.</p>
	*/
	
	class UML_API ExtensionPoint: virtual public RedefinableElement
	{
		public:
 			ExtensionPoint(const ExtensionPoint &) {}

		protected:
			ExtensionPoint(){}
			//Additional constructors for the containments back reference
			ExtensionPoint(std::weak_ptr<uml::Namespace> par_namespace);

			//Additional constructors for the containments back reference
			ExtensionPoint(std::weak_ptr<uml::Element> par_owner);

			//Additional constructors for the containments back reference
			ExtensionPoint(std::weak_ptr<uml::UseCase> par_useCase);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ExtensionPoint() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			An ExtensionPoint must have a name.
			name->notEmpty ()
			*/
			 
			virtual bool must_have_name(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The UseCase that owns this ExtensionPoint.
			<p>From package UML::UseCases.</p>
			*/
			
			virtual std::weak_ptr<uml::UseCase> getUseCase() const = 0;
			/*!
			The UseCase that owns this ExtensionPoint.
			<p>From package UML::UseCases.</p>
			*/
			
			virtual void setUseCase(std::weak_ptr<uml::UseCase>) = 0;

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
			The UseCase that owns this ExtensionPoint.
			<p>From package UML::UseCases.</p>
			*/
			
			std::weak_ptr<uml::UseCase> m_useCase;
	};
}
#endif /* end of include guard: UML_EXTENSIONPOINT_HPP */
