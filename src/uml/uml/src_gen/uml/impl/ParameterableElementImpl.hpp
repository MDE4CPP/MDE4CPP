//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_PARAMETERABLEELEMENTPARAMETERABLEELEMENTIMPL_HPP
#define UML_PARAMETERABLEELEMENTPARAMETERABLEELEMENTIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../ParameterableElement.hpp"

#include "uml/impl/ElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ParameterableElementImpl : virtual public ElementImpl, virtual public ParameterableElement 
	{
		public: 
			ParameterableElementImpl(const ParameterableElementImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			ParameterableElementImpl& operator=(ParameterableElementImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ParameterableElementImpl();
			virtual std::shared_ptr<uml::ParameterableElement> getThisParameterableElementPtr() const;
			virtual void setThisParameterableElementPtr(std::weak_ptr<uml::ParameterableElement> thisParameterableElementPtr);

			//Additional constructors for the containments back reference
			ParameterableElementImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			ParameterableElementImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

		public:
			//destructor
			virtual ~ParameterableElementImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The query isCompatibleWith() determines if this ParameterableElement is compatible with the specified ParameterableElement. By default, this ParameterableElement is compatible with another ParameterableElement p if the kind of this ParameterableElement is the same as or a subtype of the kind of p. Subclasses of ParameterableElement should override this operation to specify different compatibility constraints.
			result = (self.oclIsKindOf(p.oclType()))
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual bool isCompatibleWith(std::shared_ptr<uml::ParameterableElement> p) ;
			/*!
			The query isTemplateParameter() determines if this ParameterableElement is exposed as a formal TemplateParameter.
			result = (templateParameter->notEmpty())
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual bool isTemplateParameter() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The formal TemplateParameter that owns this ParameterableElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::TemplateParameter> getOwningTemplateParameter() const ;
			/*!
			The formal TemplateParameter that owns this ParameterableElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setOwningTemplateParameter(std::weak_ptr<uml::TemplateParameter>) ;
			/*!
			The TemplateParameter that exposes this ParameterableElement as a formal parameter.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<uml::TemplateParameter> getTemplateParameter() const ;
			/*!
			The TemplateParameter that exposes this ParameterableElement as a formal parameter.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setTemplateParameter(std::shared_ptr<uml::TemplateParameter>) ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			
			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual std::shared_ptr<Any> eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, std::shared_ptr<Any> newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments) ;

		private:
			std::weak_ptr<uml::ParameterableElement> m_thisParameterableElementPtr;
	};
}
#endif /* end of include guard: UML_PARAMETERABLEELEMENTPARAMETERABLEELEMENTIMPL_HPP */
