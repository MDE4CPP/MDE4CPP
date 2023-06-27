//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_TEMPLATESIGNATURETEMPLATESIGNATUREIMPL_HPP
#define UML_TEMPLATESIGNATURETEMPLATESIGNATUREIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../TemplateSignature.hpp"

#include "uml/impl/ElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API TemplateSignatureImpl : virtual public ElementImpl, virtual public TemplateSignature 
	{
		public: 
			TemplateSignatureImpl(const TemplateSignatureImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			TemplateSignatureImpl& operator=(TemplateSignatureImpl const&); 

		protected:
			friend class umlFactoryImpl;
			TemplateSignatureImpl();
			virtual std::shared_ptr<uml::TemplateSignature> getThisTemplateSignaturePtr() const;
			virtual void setThisTemplateSignaturePtr(std::weak_ptr<uml::TemplateSignature> thisTemplateSignaturePtr);

			//Additional constructors for the containments back reference
			TemplateSignatureImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			TemplateSignatureImpl(std::weak_ptr<uml::TemplateableElement> par_template);

		public:
			//destructor
			virtual ~TemplateSignatureImpl();
			
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
			The formal parameters that are owned by this TemplateSignature.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::TemplateParameter, uml::Element, uml::TemplateParameter>>& getOwnedParameter() const ;
			
			/*!
			The TemplateableElement that owns this TemplateSignature.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::TemplateableElement> getTemplate() const ;
			/*!
			The TemplateableElement that owns this TemplateSignature.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setTemplate(std::weak_ptr<uml::TemplateableElement>) ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			The ordered set of all formal TemplateParameters for this TemplateSignature.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::TemplateParameter>> getParameter() const ;
			
			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 

			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual std::shared_ptr<Any> eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, const std::shared_ptr<Any>& newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID,const std::shared_ptr<Bag<Any>>& arguments) ;

		private:
			std::weak_ptr<uml::TemplateSignature> m_thisTemplateSignaturePtr;
	};
}
#endif /* end of include guard: UML_TEMPLATESIGNATURETEMPLATESIGNATUREIMPL_HPP */
