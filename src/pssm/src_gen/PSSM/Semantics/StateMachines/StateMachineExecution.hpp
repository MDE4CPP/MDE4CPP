//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSSM_SEMANTICS_STATEMACHINES_STATEMACHINEEXECUTION_HPP
#define PSSM_SEMANTICS_STATEMACHINES_STATEMACHINEEXECUTION_HPP


#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 


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
namespace fUML::Semantics::CommonBehavior 
{
	class ObjectActivation;
	class ParameterValue;
}
namespace fUML::Semantics::Loci 
{
	class Locus;
}
namespace PSSM::Semantics::StateMachines 
{
	class RegionActivation;
	class StateMachineConfiguration;
	class VertexActivation;
}
namespace ecore 
{
	class EAnnotation;
}
namespace uml 
{
	class Behavior;
	class Class;
	class Classifier;
	class Comment;
	class Vertex;
}

// namespace macro header include
#include "PSSM/PSSM.hpp"

// base class includes
#include "fUML/Semantics/CommonBehavior/Execution.hpp"



//Includes from codegen annotation
#include <thread>
#include <mutex>
#include <condition_variable>

//*********************************
namespace PSSM::Semantics::StateMachines 
{
	
	class PSSM_API StateMachineExecution : virtual public fUML::Semantics::CommonBehavior::Execution
	{
		public:
 			StateMachineExecution(const StateMachineExecution &) {}

		protected:
			StateMachineExecution(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~StateMachineExecution() {}

			//*********************************
			// Operations
			//*********************************
			virtual void execute() = 0;
			
			virtual std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation> getVertexActivation(const std::shared_ptr<uml::Vertex>& vertex) = 0;
			
			
			virtual void startBehavior(const std::shared_ptr<uml::Class>& classifier, const std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>>& inputs) = 0;
			virtual void terminate() = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<std::condition_variable>& getConditionVariable() const = 0;
			virtual void setConditionVariable(const std::shared_ptr<std::condition_variable>&) = 0;
			virtual const std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineConfiguration>& getConfiguration() const = 0;
			virtual void setConfiguration(const std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineConfiguration>&) = 0;
			virtual const std::shared_ptr<std::mutex>& getMutex() const = 0;
			virtual void setMutex(const std::shared_ptr<std::mutex>&) = 0;
			virtual const std::shared_ptr<Bag<PSSM::Semantics::StateMachines::RegionActivation>>& getRegionActivations() const = 0;

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
			std::shared_ptr<std::condition_variable> m_conditionVariable;
			std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineConfiguration> m_configuration;
			std::shared_ptr<std::mutex> m_mutex;
			mutable std::shared_ptr<Bag<PSSM::Semantics::StateMachines::RegionActivation>> m_regionActivations;
	};
}
#endif /* end of include guard: PSSM_SEMANTICS_STATEMACHINES_STATEMACHINEEXECUTION_HPP */
