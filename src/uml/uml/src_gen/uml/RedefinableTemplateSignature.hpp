//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_REDEFINABLETEMPLATESIGNATURE_HPP
#define UML_REDEFINABLETEMPLATESIGNATURE_HPP


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
	class Dependency;
	class Namespace;
	class StringExpression;
	class TemplateParameter;
	class TemplateableElement;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/RedefinableElement.hpp"
#include "uml/TemplateSignature.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A RedefinableTemplateSignature supports the addition of formal template parameters in a specialization of a template classifier.
	<p>From package UML::Classification.</p>
	*/
	
	class UML_API RedefinableTemplateSignature : virtual public RedefinableElement, virtual public TemplateSignature
	{
		public:
 			RedefinableTemplateSignature(const RedefinableTemplateSignature &) {}

		protected:
			RedefinableTemplateSignature(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~RedefinableTemplateSignature() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			Derivation for RedefinableTemplateSignature::/inheritedParameter
			result = (if extendedSignature->isEmpty() then Set{} else extendedSignature.parameter->asSet() endif)
			<p>From package UML::Classification.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::TemplateParameter>> getInheritedParameters() = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The Classifier that owns this RedefinableTemplateSignature.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::weak_ptr<uml::Classifier> getClassifier() const = 0;
			/*!
			The Classifier that owns this RedefinableTemplateSignature.
			<p>From package UML::Classification.</p>
			*/
			
			virtual void setClassifier(std::weak_ptr<uml::Classifier>) = 0;
			/*Additional Setter for 'TemplateSignature::template' redefined by reference 'classifier'*/
			/*!
			The TemplateableElement that owns this TemplateSignature.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setTemplate(std::weak_ptr<uml::TemplateableElement>) = 0;
			/*!
			The signatures extended by this RedefinableTemplateSignature.
			<p>From package UML::Classification.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::RedefinableTemplateSignature, uml::RedefinableElement>>& getExtendedSignature() const = 0;
			/*!
			The formal template parameters of the extended signatures.
			<p>From package UML::Classification.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::TemplateParameter, uml::TemplateParameter>>& getInheritedParameter() const = 0;

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
			The Classifier that owns this RedefinableTemplateSignature.
			<p>From package UML::Classification.</p>
			*/
			
			std::weak_ptr<uml::Classifier> m_classifier;
			/*!
			The signatures extended by this RedefinableTemplateSignature.
			<p>From package UML::Classification.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::RedefinableTemplateSignature, uml::RedefinableElement>> m_extendedSignature;
			/*!
			The formal template parameters of the extended signatures.
			<p>From package UML::Classification.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::TemplateParameter, uml::TemplateParameter>> m_inheritedParameter;
	};
}
#endif /* end of include guard: UML_REDEFINABLETEMPLATESIGNATURE_HPP */
