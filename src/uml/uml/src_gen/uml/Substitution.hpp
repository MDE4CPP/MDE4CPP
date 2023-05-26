//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_SUBSTITUTION_HPP
#define UML_SUBSTITUTION_HPP


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
	A substitution is a relationship between two classifiers signifying that the substituting classifier complies with the contract specified by the contract classifier. This implies that instances of the substituting classifier are runtime substitutable where instances of the contract classifier are expected.
	<p>From package UML::Classification.</p>
	*/
	
	class UML_API Substitution : virtual public Realization
	{
		public:
 			Substitution(const Substitution &) {}

		protected:
			Substitution(){}
			//Additional constructors for the containments back reference
			Substitution(std::weak_ptr<uml::Namespace> par_namespace);

			//Additional constructors for the containments back reference
			Substitution(std::weak_ptr<uml::Element> par_owner);

			//Additional constructors for the containments back reference
			Substitution(std::weak_ptr<uml::Package> par_owningPackage);

			//Additional constructors for the containments back reference
			Substitution(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

			//Additional constructors for the containments back reference
			Substitution(std::weak_ptr<uml::Classifier> par_substitutingClassifier);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Substitution() {}

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
			The contract with which the substituting classifier complies.
			<p>From package UML::Classification.</p>
			*/
			
			virtual const std::shared_ptr<uml::Classifier>& getContract() const = 0;
			/*!
			The contract with which the substituting classifier complies.
			<p>From package UML::Classification.</p>
			*/
			
			virtual void setContract(const std::shared_ptr<uml::Classifier>&) = 0;
			/*!
			Instances of the substituting classifier are runtime substitutable where instances of the contract classifier are expected.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::weak_ptr<uml::Classifier> getSubstitutingClassifier() const = 0;
			/*!
			Instances of the substituting classifier are runtime substitutable where instances of the contract classifier are expected.
			<p>From package UML::Classification.</p>
			*/
			
			virtual void setSubstitutingClassifier(std::weak_ptr<uml::Classifier>) = 0;

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
			The contract with which the substituting classifier complies.
			<p>From package UML::Classification.</p>
			*/
			
			std::shared_ptr<uml::Classifier> m_contract;
			/*!
			Instances of the substituting classifier are runtime substitutable where instances of the contract classifier are expected.
			<p>From package UML::Classification.</p>
			*/
			
			std::weak_ptr<uml::Classifier> m_substitutingClassifier;
	};
}
#endif /* end of include guard: UML_SUBSTITUTION_HPP */
