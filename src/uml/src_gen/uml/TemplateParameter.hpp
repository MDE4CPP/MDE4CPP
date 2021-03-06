//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_TEMPLATEPARAMETER_HPP
#define UML_TEMPLATEPARAMETER_HPP

#include <map>
#include <list>
#include <memory>
#include <string>


// forward declarations
template<class T, class ... U> class Subset;


class AnyObject;
typedef std::shared_ptr<AnyObject> Any;

//*********************************
// generated Includes

#include <map>

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
}

namespace uml 
{
	class Element;
}

namespace uml 
{
	class ParameterableElement;
}

namespace uml 
{
	class TemplateSignature;
}

// base class includes
#include "uml/Element.hpp"

// enum includes


//*********************************
namespace uml 
{
	/*!
	A TemplateParameter exposes a ParameterableElement as a formal parameter of a template.
	<p>From package UML::CommonStructure.</p>
	*/
	
	class TemplateParameter:virtual public Element
	{
		public:
 			TemplateParameter(const TemplateParameter &) {}
			TemplateParameter& operator=(TemplateParameter const&) = delete;

		protected:
			TemplateParameter(){}


			//Additional constructors for the containments back reference

			TemplateParameter(std::weak_ptr<uml::Element > par_owner);

			//Additional constructors for the containments back reference

			TemplateParameter(std::weak_ptr<uml::TemplateSignature > par_signature);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~TemplateParameter() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The default must be compatible with the formal TemplateParameter.
			default <> null implies default.isCompatibleWith(parameteredElement)
			*/
			 
			virtual bool must_be_compatible(Any diagnostics,std::map <   Any, Any >  context) = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The ParameterableElement that is the default for this formal TemplateParameter.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<uml::ParameterableElement > getDefault() const = 0;
			
			/*!
			The ParameterableElement that is the default for this formal TemplateParameter.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setDefault(std::shared_ptr<uml::ParameterableElement> _default) = 0;
			
			/*!
			The ParameterableElement that is owned by this TemplateParameter for the purpose of providing a default.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<uml::ParameterableElement > getOwnedDefault() const = 0;
			
			/*!
			The ParameterableElement that is owned by this TemplateParameter for the purpose of providing a default.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setOwnedDefault(std::shared_ptr<uml::ParameterableElement> _ownedDefault) = 0;
			
			/*!
			The ParameterableElement that is owned by this TemplateParameter for the purpose of exposing it as the parameteredElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<uml::ParameterableElement > getOwnedParameteredElement() const = 0;
			
			/*!
			The ParameterableElement that is owned by this TemplateParameter for the purpose of exposing it as the parameteredElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setOwnedParameteredElement(std::shared_ptr<uml::ParameterableElement> _ownedParameteredElement) = 0;
			
			/*!
			The ParameterableElement exposed by this TemplateParameter.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<uml::ParameterableElement > getParameteredElement() const = 0;
			
			/*!
			The ParameterableElement exposed by this TemplateParameter.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setParameteredElement(std::shared_ptr<uml::ParameterableElement> _parameteredElement) = 0;
			
			/*!
			The TemplateSignature that owns this TemplateParameter.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::TemplateSignature > getSignature() const = 0;
			
			/*!
			The TemplateSignature that owns this TemplateParameter.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setSignature(std::shared_ptr<uml::TemplateSignature> _signature) = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The ParameterableElement that is the default for this formal TemplateParameter.
			<p>From package UML::CommonStructure.</p>
			*/
			
			std::shared_ptr<uml::ParameterableElement > m_default;/*!
			The ParameterableElement that is owned by this TemplateParameter for the purpose of providing a default.
			<p>From package UML::CommonStructure.</p>
			*/
			
			std::shared_ptr<uml::ParameterableElement > m_ownedDefault;/*!
			The ParameterableElement that is owned by this TemplateParameter for the purpose of exposing it as the parameteredElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			std::shared_ptr<uml::ParameterableElement > m_ownedParameteredElement;/*!
			The ParameterableElement exposed by this TemplateParameter.
			<p>From package UML::CommonStructure.</p>
			*/
			
			std::shared_ptr<uml::ParameterableElement > m_parameteredElement;/*!
			The TemplateSignature that owns this TemplateParameter.
			<p>From package UML::CommonStructure.</p>
			*/
			
			std::weak_ptr<uml::TemplateSignature > m_signature;

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
			
			virtual std::weak_ptr<uml::Element > getOwner() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_TEMPLATEPARAMETER_HPP */
