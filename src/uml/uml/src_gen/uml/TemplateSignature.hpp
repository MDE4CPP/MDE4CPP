//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_TEMPLATESIGNATURE_HPP
#define UML_TEMPLATESIGNATURE_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations
template<class T, class ... U> class Subset;
template<class T> class Union;
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
	class Comment;
	class TemplateParameter;
	class TemplateableElement;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Element.hpp"




//*********************************
namespace uml 
{
	/*!
	A Template Signature bundles the set of formal TemplateParameters for a template.
	<p>From package UML::CommonStructure.</p>
	*/
	
	class UML_API TemplateSignature: virtual public Element
	{
		public:
 			TemplateSignature(const TemplateSignature &) {}

		protected:
			TemplateSignature(){}
			//Additional constructors for the containments back reference
			TemplateSignature(std::weak_ptr<uml::Element> par_owner);

			//Additional constructors for the containments back reference
			TemplateSignature(std::weak_ptr<uml::TemplateableElement> par_template);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~TemplateSignature() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			Parameters must own the ParameterableElements they parameter or those ParameterableElements must be owned by the TemplateableElement being templated.
			template.ownedElement->includesAll(parameter.parameteredElement->asSet() - parameter.ownedParameteredElement->asSet())
			*/
			 
			virtual bool own_elements(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			The names of the parameters of a TemplateSignature are unique.
			parameter->forAll( p1, p2 | (p1 <> p2 and p1.parameteredElement.oclIsKindOf(NamedElement) and p2.parameteredElement.oclIsKindOf(NamedElement) ) implies
			   p1.parameteredElement.oclAsType(NamedElement).name <> p2.parameteredElement.oclAsType(NamedElement).name)
			*/
			 
			virtual bool unique_parameters(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The formal parameters that are owned by this TemplateSignature.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::TemplateParameter, uml::Element, uml::TemplateParameter>> getOwnedParameter() const = 0;
			
			/*!
			The TemplateableElement that owns this TemplateSignature.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::TemplateableElement> getTemplate() const = 0;
			/*!
			The TemplateableElement that owns this TemplateSignature.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setTemplate(std::weak_ptr<uml::TemplateableElement>) = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
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
			/*!
			The ordered set of all formal TemplateParameters for this TemplateSignature.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::TemplateParameter>> getParameter() const = 0;

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
			The formal parameters that are owned by this TemplateSignature.
			<p>From package UML::CommonStructure.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::TemplateParameter, uml::Element, uml::TemplateParameter>> m_ownedParameter;
			/*!
			The ordered set of all formal TemplateParameters for this TemplateSignature.
			<p>From package UML::CommonStructure.</p>
			*/
			
			mutable std::shared_ptr<Union<uml::TemplateParameter>> m_parameter;
			/*!
			The TemplateableElement that owns this TemplateSignature.
			<p>From package UML::CommonStructure.</p>
			*/
			
			std::weak_ptr<uml::TemplateableElement> m_template;
	};
}
#endif /* end of include guard: UML_TEMPLATESIGNATURE_HPP */
