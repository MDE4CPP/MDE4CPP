//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSSM_SEMANTICS_STATEMACHINES_DOACTIVITYEXECUTIONEVENTACCEPTERDOACTIVITYEXECUTIONEVENTACCEPTERIMPL_HPP
#define PSSM_SEMANTICS_STATEMACHINES_DOACTIVITYEXECUTIONEVENTACCEPTERDOACTIVITYEXECUTIONEVENTACCEPTERIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "PSSM/PSSM.hpp" 

// model includes
#include "../DoActivityExecutionEventAccepter.hpp"

#include "PSSM/Semantics/StateMachines/impl/StateMachinesFactoryImpl.hpp"

#include "ecore/impl/EModelElementImpl.hpp"

//*********************************
namespace PSSM::Semantics::StateMachines 
{
	class PSSM_API DoActivityExecutionEventAccepterImpl : virtual public ecore::EModelElementImpl,
virtual public DoActivityExecutionEventAccepter 
	{
		public: 
			DoActivityExecutionEventAccepterImpl(const DoActivityExecutionEventAccepterImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			DoActivityExecutionEventAccepterImpl& operator=(DoActivityExecutionEventAccepterImpl const&); 

		protected:
			friend class PSSM::Semantics::StateMachines::StateMachinesFactoryImpl;
			DoActivityExecutionEventAccepterImpl();
			virtual std::shared_ptr<PSSM::Semantics::StateMachines::DoActivityExecutionEventAccepter> getThisDoActivityExecutionEventAccepterPtr() const;
			virtual void setThisDoActivityExecutionEventAccepterPtr(std::weak_ptr<PSSM::Semantics::StateMachines::DoActivityExecutionEventAccepter> thisDoActivityExecutionEventAccepterPtr);


		public:
			//destructor
			virtual ~DoActivityExecutionEventAccepterImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<PSSM::Semantics::StateMachines::DoActivityContextObject>& getContext() const ;
			virtual void setContext(const std::shared_ptr<PSSM::Semantics::StateMachines::DoActivityContextObject>&) ;
			virtual const std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter>& getEncapsulatedAccepter() const ;
			virtual void setEncapsulatedAccepter(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter>&) ;
			
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
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;

		protected:
			virtual const std::shared_ptr<ecore::EClass>& eStaticClass() const;

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
			std::weak_ptr<PSSM::Semantics::StateMachines::DoActivityExecutionEventAccepter> m_thisDoActivityExecutionEventAccepterPtr;
	};
}
#endif /* end of include guard: PSSM_SEMANTICS_STATEMACHINES_DOACTIVITYEXECUTIONEVENTACCEPTERDOACTIVITYEXECUTIONEVENTACCEPTERIMPL_HPP */
