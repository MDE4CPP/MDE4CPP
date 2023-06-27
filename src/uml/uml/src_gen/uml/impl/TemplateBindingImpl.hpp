//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_TEMPLATEBINDINGTEMPLATEBINDINGIMPL_HPP
#define UML_TEMPLATEBINDINGTEMPLATEBINDINGIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../TemplateBinding.hpp"

#include "uml/impl/DirectedRelationshipImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API TemplateBindingImpl : virtual public DirectedRelationshipImpl, virtual public TemplateBinding 
	{
		public: 
			TemplateBindingImpl(const TemplateBindingImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			TemplateBindingImpl& operator=(TemplateBindingImpl const&); 

		protected:
			friend class umlFactoryImpl;
			TemplateBindingImpl();
			virtual std::shared_ptr<uml::TemplateBinding> getThisTemplateBindingPtr() const;
			virtual void setThisTemplateBindingPtr(std::weak_ptr<uml::TemplateBinding> thisTemplateBindingPtr);

			//Additional constructors for the containments back reference
			TemplateBindingImpl(std::weak_ptr<uml::TemplateableElement> par_boundElement);
			//Additional constructors for the containments back reference
			TemplateBindingImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~TemplateBindingImpl();
			
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
			The TemplateableElement that is bound by this TemplateBinding.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::TemplateableElement> getBoundElement() const ;
			/*!
			The TemplateableElement that is bound by this TemplateBinding.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setBoundElement(std::weak_ptr<uml::TemplateableElement>) ;
			/*!
			The TemplateParameterSubstitutions owned by this TemplateBinding.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::TemplateParameterSubstitution, uml::Element>>& getParameterSubstitution() const ;
			/*!
			The TemplateSignature for the template that is the target of this TemplateBinding.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual const std::shared_ptr<uml::TemplateSignature>& getSignature() const ;
			/*!
			The TemplateSignature for the template that is the target of this TemplateBinding.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setSignature(const std::shared_ptr<uml::TemplateSignature>&) ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			
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
			std::weak_ptr<uml::TemplateBinding> m_thisTemplateBindingPtr;
	};
}
#endif /* end of include guard: UML_TEMPLATEBINDINGTEMPLATEBINDINGIMPL_HPP */
