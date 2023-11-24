//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSSM_SEMANTICS_STATEMACHINES_STATECONFIGURATION_HPP
#define PSSM_SEMANTICS_STATEMACHINES_STATECONFIGURATION_HPP


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
namespace PSSM::Semantics::StateMachines 
{
	class StateMachineConfiguration;
	class VertexActivation;
}

// namespace macro header include
#include "PSSM/PSSM.hpp"



#include "ecore/EModelElement.hpp"


//*********************************
namespace PSSM::Semantics::StateMachines 
{
	
	class PSSM_API StateConfiguration : virtual public ecore::EModelElement
	{
		public:
 			StateConfiguration(const StateConfiguration &) {}

		protected:
			StateConfiguration(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~StateConfiguration() {}

			//*********************************
			// Operations
			//*********************************
			virtual bool add(const std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation>& activation, const std::shared_ptr<Bag<PSSM::Semantics::StateMachines::VertexActivation>>& context) = 0;
			virtual bool addChild(const std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation>& activation) = 0;
			
			virtual std::shared_ptr<Bag<PSSM::Semantics::StateMachines::VertexActivation>> getContext(const std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation>& activation) = 0;
			
			
			virtual bool isActive(const std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation>& activation) = 0;
			virtual bool remove(const std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation>& activation, const std::shared_ptr<Bag<PSSM::Semantics::StateMachines::VertexActivation>>& context) = 0;
			virtual bool removeChild(const std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation>& activation) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual int getLevel() const = 0;
			virtual void setLevel (int _level)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<Bag<PSSM::Semantics::StateMachines::StateConfiguration>>& getChildren() const = 0;
			virtual const std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineConfiguration>& getCompleteConfiguration() const = 0;
			virtual void setCompleteConfiguration(const std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineConfiguration>&) = 0;
			virtual const std::shared_ptr<PSSM::Semantics::StateMachines::StateConfiguration>& getParent() const = 0;
			virtual void setParent(const std::shared_ptr<PSSM::Semantics::StateMachines::StateConfiguration>&) = 0;
			virtual const std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation>& getVertexActivation() const = 0;
			virtual void setVertexActivation(const std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation>&) = 0;

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
			int m_level= 0;
			
			//*********************************
			// Reference Members
			//*********************************
			mutable std::shared_ptr<Bag<PSSM::Semantics::StateMachines::StateConfiguration>> m_children;
			std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineConfiguration> m_completeConfiguration;
			std::shared_ptr<PSSM::Semantics::StateMachines::StateConfiguration> m_parent;
			std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation> m_vertexActivation;
	};
}
#endif /* end of include guard: PSSM_SEMANTICS_STATEMACHINES_STATECONFIGURATION_HPP */
