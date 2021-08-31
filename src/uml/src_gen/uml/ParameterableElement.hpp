//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_PARAMETERABLEELEMENT_HPP
#define UML_PARAMETERABLEELEMENT_HPP


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
	class Comment;
	class TemplateParameter;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Element.hpp"

// enum includes



//*********************************
namespace uml 
{
	/*!
	A ParameterableElement is an Element that can be exposed as a formal TemplateParameter for a template, or specified as an actual parameter in a binding of a template.
	<p>From package UML::CommonStructure.</p>
	*/
	
	class UML_API ParameterableElement: virtual public Element
	{
		public:
 			ParameterableElement(const ParameterableElement &) {}

		protected:
			ParameterableElement(){}
			//Additional constructors for the containments back reference
			ParameterableElement(std::weak_ptr<uml::Element> par_owner);

			//Additional constructors for the containments back reference
			ParameterableElement(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ParameterableElement() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The query isCompatibleWith() determines if this ParameterableElement is compatible with the specified ParameterableElement. By default, this ParameterableElement is compatible with another ParameterableElement p if the kind of this ParameterableElement is the same as or a subtype of the kind of p. Subclasses of ParameterableElement should override this operation to specify different compatibility constraints.
			result = (self.oclIsKindOf(p.oclType()))
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual bool isCompatibleWith(std::shared_ptr<uml::ParameterableElement> p) = 0;/*!
			The query isTemplateParameter() determines if this ParameterableElement is exposed as a formal TemplateParameter.
			result = (templateParameter->notEmpty())
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual bool isTemplateParameter() = 0;
			//*********************************
			// Attributes Getter & Setter
			//*********************************
			
			//*********************************
			// References Getter & Setter
			//*********************************
			/*!
			The formal TemplateParameter that owns this ParameterableElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::TemplateParameter> getOwningTemplateParameter() const = 0;
			/*!
			The formal TemplateParameter that owns this ParameterableElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setOwningTemplateParameter(std::weak_ptr<uml::TemplateParameter>) = 0;
			/*!
			The TemplateParameter that exposes this ParameterableElement as a formal parameter.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<uml::TemplateParameter> getTemplateParameter() const = 0;
			/*!
			The TemplateParameter that exposes this ParameterableElement as a formal parameter.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setTemplateParameter(std::shared_ptr<uml::TemplateParameter>) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The formal TemplateParameter that owns this ParameterableElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			std::weak_ptr<uml::TemplateParameter> m_owningTemplateParameter;/*!
			The TemplateParameter that exposes this ParameterableElement as a formal parameter.
			<p>From package UML::CommonStructure.</p>
			*/
			
			std::shared_ptr<uml::TemplateParameter> m_templateParameter;

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_PARAMETERABLEELEMENT_HPP */
