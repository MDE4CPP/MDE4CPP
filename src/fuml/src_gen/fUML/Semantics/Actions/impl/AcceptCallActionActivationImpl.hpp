//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_ACCEPTCALLACTIONACTIVATIONACCEPTCALLACTIONACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIONS_ACCEPTCALLACTIONACTIVATIONACCEPTCALLACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../AcceptCallActionActivation.hpp"

#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/AcceptEventActionActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	class FUML_API AcceptCallActionActivationImpl : virtual public AcceptEventActionActivationImpl, virtual public AcceptCallActionActivation 
	{
		public: 
			AcceptCallActionActivationImpl(const AcceptCallActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			AcceptCallActionActivationImpl& operator=(AcceptCallActionActivationImpl const&); 

		protected:
			friend class fUML::Semantics::Actions::ActionsFactoryImpl;
			AcceptCallActionActivationImpl();
			virtual std::shared_ptr<fUML::Semantics::Actions::AcceptCallActionActivation> getThisAcceptCallActionActivationPtr() const;
			virtual void setThisAcceptCallActionActivationPtr(std::weak_ptr<fUML::Semantics::Actions::AcceptCallActionActivation> thisAcceptCallActionActivationPtr);

			//Additional constructors for the containments back reference
			AcceptCallActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~AcceptCallActionActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual void accept(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence) ;
			
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
			virtual const std::shared_ptr<ecore::EClass>& eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, const Any& newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments) ;

		private:
			std::weak_ptr<fUML::Semantics::Actions::AcceptCallActionActivation> m_thisAcceptCallActionActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_ACCEPTCALLACTIONACTIVATIONACCEPTCALLACTIONACTIVATIONIMPL_HPP */
