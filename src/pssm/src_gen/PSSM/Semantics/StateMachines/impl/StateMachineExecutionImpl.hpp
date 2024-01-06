//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSSM_SEMANTICS_STATEMACHINES_STATEMACHINEEXECUTIONSTATEMACHINEEXECUTIONIMPL_HPP
#define PSSM_SEMANTICS_STATEMACHINES_STATEMACHINEEXECUTIONSTATEMACHINEEXECUTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "PSSM/PSSM.hpp" 

// model includes
#include "../StateMachineExecution.hpp"

#include "PSSM/Semantics/StateMachines/impl/StateMachinesFactoryImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/ExecutionImpl.hpp"

//*********************************
namespace PSSM::Semantics::StateMachines 
{
	class PSSM_API StateMachineExecutionImpl : virtual public fUML::Semantics::CommonBehavior::ExecutionImpl, virtual public StateMachineExecution 
	{
		public: 
			StateMachineExecutionImpl(const StateMachineExecutionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			StateMachineExecutionImpl& operator=(StateMachineExecutionImpl const&); 

		protected:
			friend class PSSM::Semantics::StateMachines::StateMachinesFactoryImpl;
			StateMachineExecutionImpl();
			virtual std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineExecution> getThisStateMachineExecutionPtr() const;
			virtual void setThisStateMachineExecutionPtr(std::weak_ptr<PSSM::Semantics::StateMachines::StateMachineExecution> thisStateMachineExecutionPtr);


		public:
			//destructor
			virtual ~StateMachineExecutionImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual void execute() ;
			
			virtual std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation> getVertexActivation(const std::shared_ptr<uml::Vertex>& vertex) ;
			
			
			virtual void startBehavior(const std::shared_ptr<uml::Class>& classifier, const std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>>& inputs) ;
			virtual void terminate() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<std::condition_variable>& getConditionVariable() const ;
			virtual void setConditionVariable(const std::shared_ptr<std::condition_variable>&) ;
			virtual const std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineConfiguration>& getConfiguration() const ;
			virtual void setConfiguration(const std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineConfiguration>&) ;
			virtual const std::shared_ptr<std::mutex>& getMutex() const ;
			virtual void setMutex(const std::shared_ptr<std::mutex>&) ;
			virtual const std::shared_ptr<Bag<PSSM::Semantics::StateMachines::RegionActivation>>& getRegionActivations() const ;
			
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
			std::weak_ptr<PSSM::Semantics::StateMachines::StateMachineExecution> m_thisStateMachineExecutionPtr;
	};
}
#endif /* end of include guard: PSSM_SEMANTICS_STATEMACHINES_STATEMACHINEEXECUTIONSTATEMACHINEEXECUTIONIMPL_HPP */
