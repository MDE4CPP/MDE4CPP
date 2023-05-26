//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_TEMPLATEPARAMETERSUBSTITUTIONTEMPLATEPARAMETERSUBSTITUTIONIMPL_HPP
#define UML_TEMPLATEPARAMETERSUBSTITUTIONTEMPLATEPARAMETERSUBSTITUTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../TemplateParameterSubstitution.hpp"

#include "uml/impl/ElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API TemplateParameterSubstitutionImpl : virtual public ElementImpl, virtual public TemplateParameterSubstitution 
	{
		public: 
			TemplateParameterSubstitutionImpl(const TemplateParameterSubstitutionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			TemplateParameterSubstitutionImpl& operator=(TemplateParameterSubstitutionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			TemplateParameterSubstitutionImpl();
			virtual std::shared_ptr<uml::TemplateParameterSubstitution> getThisTemplateParameterSubstitutionPtr() const;
			virtual void setThisTemplateParameterSubstitutionPtr(std::weak_ptr<uml::TemplateParameterSubstitution> thisTemplateParameterSubstitutionPtr);

			//Additional constructors for the containments back reference
			TemplateParameterSubstitutionImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			TemplateParameterSubstitutionImpl(std::weak_ptr<uml::TemplateBinding> par_templateBinding);

		public:
			//destructor
			virtual ~TemplateParameterSubstitutionImpl();
			
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
			The ParameterableElement that is the actual parameter for this TemplateParameterSubstitution.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<uml::ParameterableElement> getActual() const ;
			/*!
			The ParameterableElement that is the actual parameter for this TemplateParameterSubstitution.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setActual(const std::shared_ptr<uml::ParameterableElement>&) ;
			/*!
			The formal TemplateParameter that is associated with this TemplateParameterSubstitution.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<uml::TemplateParameter> getFormal() const ;
			/*!
			The formal TemplateParameter that is associated with this TemplateParameterSubstitution.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setFormal(const std::shared_ptr<uml::TemplateParameter>&) ;
			/*!
			The ParameterableElement that is owned by this TemplateParameterSubstitution as its actual parameter.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<uml::ParameterableElement> getOwnedActual() const ;
			/*!
			The ParameterableElement that is owned by this TemplateParameterSubstitution as its actual parameter.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setOwnedActual(const std::shared_ptr<uml::ParameterableElement>&) ;
			/*!
			The TemplateBinding that owns this TemplateParameterSubstitution.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::TemplateBinding> getTemplateBinding() const ;
			/*!
			The TemplateBinding that owns this TemplateParameterSubstitution.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setTemplateBinding(std::weak_ptr<uml::TemplateBinding>) ;
			
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
			std::weak_ptr<uml::TemplateParameterSubstitution> m_thisTemplateParameterSubstitutionPtr;
	};
}
#endif /* end of include guard: UML_TEMPLATEPARAMETERSUBSTITUTIONTEMPLATEPARAMETERSUBSTITUTIONIMPL_HPP */
