//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_CALLBEHAVIORACTIONACTIVATIONCALLBEHAVIORACTIONACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIONS_CALLBEHAVIORACTIONACTIVATIONCALLBEHAVIORACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../CallBehaviorActionActivation.hpp"

#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/CallActionActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	class FUML_API CallBehaviorActionActivationImpl : virtual public CallActionActivationImpl, virtual public CallBehaviorActionActivation 
	{
		public: 
			CallBehaviorActionActivationImpl(const CallBehaviorActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			CallBehaviorActionActivationImpl& operator=(CallBehaviorActionActivationImpl const&); 

		protected:
			friend class fUML::Semantics::Actions::ActionsFactoryImpl;
			CallBehaviorActionActivationImpl();
			virtual std::shared_ptr<fUML::Semantics::Actions::CallBehaviorActionActivation> getThisCallBehaviorActionActivationPtr() const;
			virtual void setThisCallBehaviorActionActivationPtr(std::weak_ptr<fUML::Semantics::Actions::CallBehaviorActionActivation> thisCallBehaviorActionActivationPtr);

			//Additional constructors for the containments back reference
			CallBehaviorActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~CallBehaviorActionActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> doCall(const std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>>& inputParameterValues) ;
			
			virtual std::shared_ptr<uml::Behavior> retrieveBehavior() const ;
			virtual std::shared_ptr<Bag<uml::Parameter>> retrieveCallParameters() const ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<uml::CallBehaviorAction> getCallBehaviorAction() const ;
			virtual void setCallBehaviorAction(std::shared_ptr<uml::CallBehaviorAction>) ;
			/*Additional Setter for 'CallActionActivation::callAction' redefined by reference 'callBehaviorAction'*/
			virtual void setCallAction(std::shared_ptr<uml::CallAction>) ;
			/*Additional Setter for 'ActionActivation::action' redefined by reference 'callBehaviorAction'*/
			virtual void setAction(std::shared_ptr<uml::Action>) ;
			/*Additional Setter for 'ActivityNodeActivation::node' redefined by reference 'callBehaviorAction'*/
			virtual void setNode(std::shared_ptr<uml::ActivityNode>) ;
			
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
			std::weak_ptr<fUML::Semantics::Actions::CallBehaviorActionActivation> m_thisCallBehaviorActionActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_CALLBEHAVIORACTIONACTIVATIONCALLBEHAVIORACTIONACTIVATIONIMPL_HPP */
