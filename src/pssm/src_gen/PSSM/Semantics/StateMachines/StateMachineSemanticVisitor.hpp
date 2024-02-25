//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSSM_SEMANTICS_STATEMACHINES_STATEMACHINESEMANTICVISITOR_HPP
#define PSSM_SEMANTICS_STATEMACHINES_STATEMACHINESEMANTICVISITOR_HPP


#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 

class Any;

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
	class EventOccurrence;
	class Execution;
}
namespace fUML::Semantics::Loci 
{
	class Locus;
}
namespace fUML::MDE4CPP_Extensions 
{
	class FUML_Object;
}
namespace PSSM::Semantics::StateMachines 
{
	class StateMachineExecution;
}
namespace uml 
{
	class Behavior;
	class NamedElement;
	class Trigger;
}

// namespace macro header include
#include "PSSM/PSSM.hpp"

// base class includes
#include "fUML/Semantics/Loci/SemanticVisitor.hpp"




//*********************************
namespace PSSM::Semantics::StateMachines 
{
	
	class PSSM_API StateMachineSemanticVisitor : virtual public fUML::Semantics::Loci::SemanticVisitor
	{
		public:
 			StateMachineSemanticVisitor(const StateMachineSemanticVisitor &) {}

		protected:
			StateMachineSemanticVisitor(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~StateMachineSemanticVisitor() {}

			//*********************************
			// Operations
			//*********************************
			virtual void activate() = 0;
			virtual void activateTransitions() = 0;
			virtual std::shared_ptr<Bag<fUML::Semantics::Loci::SemanticVisitor>> getContextChain() = 0;
			virtual std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object> getExecutionContext() = 0;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> getExecutionFor(const std::shared_ptr<uml::Behavior>& behavior, const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence, const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object>& context) = 0;
			virtual std::shared_ptr<fUML::Semantics::Loci::Locus> getExecutionLocus() = 0;
			
			
			virtual std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineExecution> getStateMachineExecution() = 0;
			virtual bool isVisitorFor(const std::shared_ptr<uml::NamedElement>& node) = 0;
			virtual bool match(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence, const std::shared_ptr<Bag<uml::Trigger>>& triggers) = 0;
			
			

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<uml::NamedElement>& getNode() const = 0;
			virtual void setNode(const std::shared_ptr<uml::NamedElement>&) = 0;
			virtual const std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor>& getParent() const = 0;
			virtual void setParent(const std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor>&) = 0;

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
			std::shared_ptr<uml::NamedElement> m_node;
			std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor> m_parent;
	};
}
#endif /* end of include guard: PSSM_SEMANTICS_STATEMACHINES_STATEMACHINESEMANTICVISITOR_HPP */
