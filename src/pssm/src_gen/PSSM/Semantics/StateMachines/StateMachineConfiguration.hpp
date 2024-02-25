//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSSM_SEMANTICS_STATEMACHINES_STATEMACHINECONFIGURATION_HPP
#define PSSM_SEMANTICS_STATEMACHINES_STATEMACHINECONFIGURATION_HPP


#include <memory>
#include <string>
// forward declarations


//*********************************
// generated Includes
#include <map> // used for Persistence
#include <vector> // used for Persistence
namespace persistence
{
	namespace interfaces
	{
		class XLoadHandler; // used for Persistence
		class XSaveHandler; // used for Persistence
	}
}

namespace PSSM
{
	class PSSMFactory;
}

//Forward Declaration for used types 
namespace PSSM::Semantics::StateMachines 
{
	class StateActivation;
	class StateConfiguration;
	class StateMachineExecution;
	class VertexActivation;
}

// namespace macro header include
#include "PSSM/PSSM.hpp"



#include "ecore/EModelElement.hpp"


//*********************************
namespace PSSM::Semantics::StateMachines 
{
	
	class PSSM_API StateMachineConfiguration : virtual public ecore::EModelElement
	{
		public:
 			StateMachineConfiguration(const StateMachineConfiguration &) {}

		protected:
			StateMachineConfiguration(){}
			//Additional constructors for the containments back reference
			StateMachineConfiguration(std::weak_ptr<PSSM::Semantics::StateMachines::StateMachineExecution> par_execution);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~StateMachineConfiguration() {}

			//*********************************
			// Operations
			//*********************************
			virtual bool _register(const std::shared_ptr<PSSM::Semantics::StateMachines::StateActivation>& stateActivation) = 0;
			virtual bool add(const std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation>& activation) = 0;
			
			
			virtual std::shared_ptr<Bag<PSSM::Semantics::StateMachines::VertexActivation>> getVertexActivationsAtLevel(int level) = 0;
			virtual bool isActive(const std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation>& activation) = 0;
			virtual bool isStable() = 0;
			virtual bool remove(const std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation>& vertexActivation) = 0;
			virtual bool unregister(const std::shared_ptr<PSSM::Semantics::StateMachines::StateActivation>& stateActivation) = 0;
			virtual void unregisterAll() = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::weak_ptr<PSSM::Semantics::StateMachines::StateMachineExecution> getExecution() const = 0;
			virtual void setExecution(std::weak_ptr<PSSM::Semantics::StateMachines::StateMachineExecution>) = 0;
			virtual const std::shared_ptr<PSSM::Semantics::StateMachines::StateConfiguration>& getRootConfiguration() const = 0;
			virtual void setRootConfiguration(const std::shared_ptr<PSSM::Semantics::StateMachines::StateConfiguration>&) = 0;

			//*********************************
			// Union Reference Getters
			//*********************************

			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 

			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			//*********************************
			// Reference Members
			//*********************************
			std::weak_ptr<PSSM::Semantics::StateMachines::StateMachineExecution> m_execution;
			std::shared_ptr<PSSM::Semantics::StateMachines::StateConfiguration> m_rootConfiguration;
	};
}
#endif /* end of include guard: PSSM_SEMANTICS_STATEMACHINES_STATEMACHINECONFIGURATION_HPP */
