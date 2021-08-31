//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_STARTOBJECTBEHAVIORACTIONACTIVATIONSTARTOBJECTBEHAVIORACTIONACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIONS_STARTOBJECTBEHAVIORACTIONACTIVATIONSTARTOBJECTBEHAVIORACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../StartObjectBehaviorActionActivation.hpp"

#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/InvocationActionActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	class FUML_API StartObjectBehaviorActionActivationImpl : virtual public InvocationActionActivationImpl, virtual public StartObjectBehaviorActionActivation 
	{
		public: 
			StartObjectBehaviorActionActivationImpl(const StartObjectBehaviorActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			StartObjectBehaviorActionActivationImpl& operator=(StartObjectBehaviorActionActivationImpl const&); 

		protected:
			friend class fUML::Semantics::Actions::ActionsFactoryImpl;
			StartObjectBehaviorActionActivationImpl();
			virtual std::shared_ptr<StartObjectBehaviorActionActivation> getThisStartObjectBehaviorActionActivationPtr() const;
			virtual void setThisStartObjectBehaviorActionActivationPtr(std::weak_ptr<StartObjectBehaviorActionActivation> thisStartObjectBehaviorActionActivationPtr);

			//Additional constructors for the containments back reference
			StartObjectBehaviorActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~StartObjectBehaviorActionActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual void doAction() ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			
			
			//*********************************
			// Union Getter
			//*********************************
			
			virtual std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> getPinActivation() const ;
			

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
			

			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<StartObjectBehaviorActionActivation> m_thisStartObjectBehaviorActionActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_STARTOBJECTBEHAVIORACTIONACTIVATIONSTARTOBJECTBEHAVIORACTIONACTIVATIONIMPL_HPP */
