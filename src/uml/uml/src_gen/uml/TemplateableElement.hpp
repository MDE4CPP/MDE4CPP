//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_TEMPLATEABLEELEMENT_HPP
#define UML_TEMPLATEABLEELEMENT_HPP


#include <memory>
#include <string>
// forward declarations
template<class T, class ... U> class Subset;


//*********************************
// generated Includes

//Forward Declaration for used types 
namespace uml 
{
	class Comment;
	class ParameterableElement;
	class TemplateBinding;
	class TemplateSignature;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Element.hpp"




//*********************************
namespace uml 
{
	/*!
	A TemplateableElement is an Element that can optionally be defined as a template and bound to other templates.
	<p>From package UML::CommonStructure.</p>
	*/
	
	class UML_API TemplateableElement : virtual public Element
	{
		public:
 			TemplateableElement(const TemplateableElement &) {}

		protected:
			TemplateableElement(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~TemplateableElement() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The query isTemplate() returns whether this TemplateableElement is actually a template.
			result = (ownedTemplateSignature <> null)
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual bool isTemplate() = 0;
			/*!
			The query parameterableElements() returns the set of ParameterableElements that may be used as the parameteredElements for a TemplateParameter of this TemplateableElement. By default, this set includes all the ownedElements. Subclasses may override this operation if they choose to restrict the set of ParameterableElements.
			result = (self.allOwnedElements()->select(oclIsKindOf(ParameterableElement)).oclAsType(ParameterableElement)->asSet())
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::ParameterableElement>> parameterableElements() = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The optional TemplateSignature specifying the formal TemplateParameters for this TemplateableElement. If a TemplateableElement has a TemplateSignature, then it is a template.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<uml::TemplateSignature> getOwnedTemplateSignature() const = 0;
			/*!
			The optional TemplateSignature specifying the formal TemplateParameters for this TemplateableElement. If a TemplateableElement has a TemplateSignature, then it is a template.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setOwnedTemplateSignature(std::shared_ptr<uml::TemplateSignature>) = 0;
			/*!
			The optional TemplateBindings from this TemplateableElement to one or more templates.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::TemplateBinding, uml::Element>> getTemplateBinding() const = 0;

			//*********************************
			// Union Reference Getters
			//*********************************

			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The optional TemplateSignature specifying the formal TemplateParameters for this TemplateableElement. If a TemplateableElement has a TemplateSignature, then it is a template.
			<p>From package UML::CommonStructure.</p>
			*/
			
			std::shared_ptr<uml::TemplateSignature> m_ownedTemplateSignature;
			/*!
			The optional TemplateBindings from this TemplateableElement to one or more templates.
			<p>From package UML::CommonStructure.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::TemplateBinding, uml::Element>> m_templateBinding;
	};
}
#endif /* end of include guard: UML_TEMPLATEABLEELEMENT_HPP */
