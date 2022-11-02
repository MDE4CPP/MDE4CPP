//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_COMPONENTREALIZATION_HPP
#define UML_COMPONENTREALIZATION_HPP


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
	class Classifier;
	class Comment;
	class Component;
	class Namespace;
	class OpaqueExpression;
	class Package;
	class StringExpression;
	class TemplateParameter;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Realization.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	Realization is specialized to (optionally) define the Classifiers that realize the contract offered by a Component in terms of its provided and required Interfaces. The Component forms an abstraction from these various Classifiers.
	<p>From package UML::StructuredClassifiers.</p>
	*/
	
	class UML_API ComponentRealization : virtual public Realization
	{
		public:
 			ComponentRealization(const ComponentRealization &) {}

		protected:
			ComponentRealization(){}
			//Additional constructors for the containments back reference
			ComponentRealization(std::weak_ptr<uml::Component> par_abstraction);

			//Additional constructors for the containments back reference
			ComponentRealization(std::weak_ptr<uml::Namespace> par_namespace);

			//Additional constructors for the containments back reference
			ComponentRealization(std::weak_ptr<uml::Element> par_owner);

			//Additional constructors for the containments back reference
			ComponentRealization(std::weak_ptr<uml::Package> par_owningPackage);

			//Additional constructors for the containments back reference
			ComponentRealization(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ComponentRealization() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The Component that owns this ComponentRealization and which is implemented by its realizing Classifiers.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::weak_ptr<uml::Component> getAbstraction() const = 0;
			/*!
			The Component that owns this ComponentRealization and which is implemented by its realizing Classifiers.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual void setAbstraction(std::weak_ptr<uml::Component>) = 0;
			/*!
			The Classifiers that are involved in the implementation of the Component that owns this Realization.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Classifier, uml::NamedElement /*Subset does not reference a union*/>> getRealizingClassifier() const = 0;

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
			The Component that owns this ComponentRealization and which is implemented by its realizing Classifiers.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			std::weak_ptr<uml::Component> m_abstraction;
			/*!
			The Classifiers that are involved in the implementation of the Component that owns this Realization.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Classifier, uml::NamedElement /*Subset does not reference a union*/>> m_realizingClassifier;
	};
}
#endif /* end of include guard: UML_COMPONENTREALIZATION_HPP */
