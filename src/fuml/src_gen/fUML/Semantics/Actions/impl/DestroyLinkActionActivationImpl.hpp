//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_DESTROYLINKACTIONACTIVATIONDESTROYLINKACTIONACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIONS_DESTROYLINKACTIONACTIVATIONDESTROYLINKACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../DestroyLinkActionActivation.hpp"

#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/WriteLinkActionActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	class FUML_API DestroyLinkActionActivationImpl : virtual public WriteLinkActionActivationImpl, virtual public DestroyLinkActionActivation 
	{
		public: 
			DestroyLinkActionActivationImpl(const DestroyLinkActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			DestroyLinkActionActivationImpl& operator=(DestroyLinkActionActivationImpl const&); 

		protected:
			friend class fUML::Semantics::Actions::ActionsFactoryImpl;
			DestroyLinkActionActivationImpl();
			virtual std::shared_ptr<fUML::Semantics::Actions::DestroyLinkActionActivation> getThisDestroyLinkActionActivationPtr() const;
			virtual void setThisDestroyLinkActionActivationPtr(std::weak_ptr<fUML::Semantics::Actions::DestroyLinkActionActivation> thisDestroyLinkActionActivationPtr);

			//Additional constructors for the containments back reference
			DestroyLinkActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~DestroyLinkActionActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			
			//*********************************
			// Union Reference Getters
			//*********************************
			virtual std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> getPinActivation() const ;
			
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
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments) ;

		private:
			std::weak_ptr<fUML::Semantics::Actions::DestroyLinkActionActivation> m_thisDestroyLinkActionActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_DESTROYLINKACTIONACTIVATIONDESTROYLINKACTIONACTIVATIONIMPL_HPP */
