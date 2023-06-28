//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INTERFACEREALIZATION_HPP
#define UML_INTERFACEREALIZATION_HPP


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
	class BehavioredClassifier;
	class Comment;
	class Interface;
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
	An InterfaceRealization is a specialized realization relationship between a BehavioredClassifier and an Interface. This relationship signifies that the realizing BehavioredClassifier conforms to the contract specified by the Interface.
	<p>From package UML::SimpleClassifiers.</p>
	*/
	
	class UML_API InterfaceRealization : virtual public Realization
	{
		public:
 			InterfaceRealization(const InterfaceRealization &) {}

		protected:
			InterfaceRealization(){}
			//Additional constructors for the containments back reference
			InterfaceRealization(std::weak_ptr<uml::BehavioredClassifier> par_implementingClassifier);

			//Additional constructors for the containments back reference
			InterfaceRealization(std::weak_ptr<uml::Namespace> par_namespace);

			//Additional constructors for the containments back reference
			InterfaceRealization(std::weak_ptr<uml::Element> par_owner);

			//Additional constructors for the containments back reference
			InterfaceRealization(std::weak_ptr<uml::Package> par_owningPackage);

			//Additional constructors for the containments back reference
			InterfaceRealization(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~InterfaceRealization() {}

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
			References the Interface specifying the conformance contract.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			virtual const std::shared_ptr<uml::Interface>& getContract() const = 0;
			/*!
			References the Interface specifying the conformance contract.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			virtual void setContract(const std::shared_ptr<uml::Interface>&) = 0;
			/*!
			References the BehavioredClassifier that owns this InterfaceRealization, i.e., the BehavioredClassifier that realizes the Interface to which it refers.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			virtual std::weak_ptr<uml::BehavioredClassifier> getImplementingClassifier() const = 0;
			/*!
			References the BehavioredClassifier that owns this InterfaceRealization, i.e., the BehavioredClassifier that realizes the Interface to which it refers.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			virtual void setImplementingClassifier(std::weak_ptr<uml::BehavioredClassifier>) = 0;

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
			/*!
			References the Interface specifying the conformance contract.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			std::shared_ptr<uml::Interface> m_contract;
			/*!
			References the BehavioredClassifier that owns this InterfaceRealization, i.e., the BehavioredClassifier that realizes the Interface to which it refers.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			std::weak_ptr<uml::BehavioredClassifier> m_implementingClassifier;
	};
}
#endif /* end of include guard: UML_INTERFACEREALIZATION_HPP */
