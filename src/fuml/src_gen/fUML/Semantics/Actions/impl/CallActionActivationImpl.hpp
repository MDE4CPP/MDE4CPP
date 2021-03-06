//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_CALLACTIONACTIVATIONCALLACTIONACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIONS_CALLACTIONACTIVATIONCALLACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../CallActionActivation.hpp"

#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/InvocationActionActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	class CallActionActivationImpl : virtual public InvocationActionActivationImpl, virtual public CallActionActivation 
	{
		public: 
			CallActionActivationImpl(const CallActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			CallActionActivationImpl& operator=(CallActionActivationImpl const&) = delete;

		protected:
			friend class fUML::Semantics::Actions::ActionsFactoryImpl;
			CallActionActivationImpl();
			virtual std::shared_ptr<CallActionActivation> getThisCallActionActivationPtr() const;
			virtual void setThisCallActionActivationPtr(std::weak_ptr<CallActionActivation> thisCallActionActivationPtr);

			//Additional constructors for the containments back reference
			CallActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group);




		public:
			//destructor
			virtual ~CallActionActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual void doAction() ;
			
			 
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> getCallExecution() ;
			
			 
			virtual void removeCallExecution(std::shared_ptr<fUML::Semantics::CommonBehavior::Execution>  execution) ;
			
			 
			virtual void terminate() ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<uml::CallAction > getCallAction() const ;
			
			
			virtual void setCallAction(std::shared_ptr<uml::CallAction> _callAction) ;
			
			/*Additional Setter for 'ActionActivation::action' redefined by reference 'callAction'*/
			
			virtual void setAction(std::shared_ptr<uml::Action> _action) ;
			
			/*Additional Setter for 'ActivityNodeActivation::node' redefined by reference 'callAction'*/
			
			virtual void setNode(std::shared_ptr<uml::ActivityNode> _node) ;
			
			
			virtual std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::Execution>> getCallExecutions() const ;
			
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			
			virtual std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> getPinActivation() const ; 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<CallActionActivation> m_thisCallActionActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_CALLACTIONACTIVATIONCALLACTIONACTIVATIONIMPL_HPP */
