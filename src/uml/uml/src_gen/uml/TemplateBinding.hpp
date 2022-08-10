//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_TEMPLATEBINDING_HPP
#define UML_TEMPLATEBINDING_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations
template<class T, class ... U> class Subset;

class Any;

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
	class TemplateParameterSubstitution;
	class TemplateSignature;
	class TemplateableElement;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/DirectedRelationship.hpp"




//*********************************
namespace uml 
{
	/*!
	A TemplateBinding is a DirectedRelationship between a TemplateableElement and a template. A TemplateBinding specifies the TemplateParameterSubstitutions of actual parameters for the formal parameters of the template.
	<p>From package UML::CommonStructure.</p>
	*/
	
	class UML_API TemplateBinding : virtual public DirectedRelationship
	{
		public:
 			TemplateBinding(const TemplateBinding &) {}

		protected:
			TemplateBinding(){}
			//Additional constructors for the containments back reference
			TemplateBinding(std::weak_ptr<uml::TemplateableElement> par_boundElement);

			//Additional constructors for the containments back reference
			TemplateBinding(std::weak_ptr<uml::Element> par_owner);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~TemplateBinding() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			A TemplateBiinding contains at most one TemplateParameterSubstitution for each formal TemplateParameter of the target TemplateSignature.
			signature.parameter->forAll(p | parameterSubstitution->select(b | b.formal = p)->size() <= 1)
			*/
			 
			virtual bool one_parameter_substitution(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			Each parameterSubstitution must refer to a formal TemplateParameter of the target TemplateSignature.
			parameterSubstitution->forAll(b | signature.parameter->includes(b.formal))
			*/
			 
			virtual bool parameter_substitution_formal(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The TemplateableElement that is bound by this TemplateBinding.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::TemplateableElement> getBoundElement() const = 0;
			/*!
			The TemplateableElement that is bound by this TemplateBinding.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setBoundElement(std::weak_ptr<uml::TemplateableElement>) = 0;
			/*!
			The TemplateParameterSubstitutions owned by this TemplateBinding.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::TemplateParameterSubstitution, uml::Element>> getParameterSubstitution() const = 0;
			/*!
			The TemplateSignature for the template that is the target of this TemplateBinding.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<uml::TemplateSignature> getSignature() const = 0;
			/*!
			The TemplateSignature for the template that is the target of this TemplateBinding.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setSignature(std::shared_ptr<uml::TemplateSignature>) = 0;

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
			Specifies the elements related by the Relationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getRelatedElement() const = 0;
			/*!
			Specifies the source Element(s) of the DirectedRelationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> getSource() const = 0;
			/*!
			Specifies the target Element(s) of the DirectedRelationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> getTarget() const = 0;

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
			The TemplateableElement that is bound by this TemplateBinding.
			<p>From package UML::CommonStructure.</p>
			*/
			
			std::weak_ptr<uml::TemplateableElement> m_boundElement;
			/*!
			The TemplateParameterSubstitutions owned by this TemplateBinding.
			<p>From package UML::CommonStructure.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::TemplateParameterSubstitution, uml::Element>> m_parameterSubstitution;
			/*!
			The TemplateSignature for the template that is the target of this TemplateBinding.
			<p>From package UML::CommonStructure.</p>
			*/
			
			std::shared_ptr<uml::TemplateSignature> m_signature;
	};
}
#endif /* end of include guard: UML_TEMPLATEBINDING_HPP */
