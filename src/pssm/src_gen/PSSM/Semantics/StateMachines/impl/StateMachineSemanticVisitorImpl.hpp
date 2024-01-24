//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSSM_SEMANTICS_STATEMACHINES_STATEMACHINESEMANTICVISITORSTATEMACHINESEMANTICVISITORIMPL_HPP
#define PSSM_SEMANTICS_STATEMACHINES_STATEMACHINESEMANTICVISITORSTATEMACHINESEMANTICVISITORIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "PSSM/PSSM.hpp" 

// model includes
#include "../StateMachineSemanticVisitor.hpp"

#include "PSSM/Semantics/StateMachines/impl/StateMachinesFactoryImpl.hpp"
#include "fUML/Semantics/Loci/impl/SemanticVisitorImpl.hpp"

//*********************************
namespace PSSM::Semantics::StateMachines 
{
	class PSSM_API StateMachineSemanticVisitorImpl : virtual public fUML::Semantics::Loci::SemanticVisitorImpl, virtual public StateMachineSemanticVisitor 
	{
		public: 
			StateMachineSemanticVisitorImpl(const StateMachineSemanticVisitorImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			StateMachineSemanticVisitorImpl& operator=(StateMachineSemanticVisitorImpl const&); 

		protected:
			friend class PSSM::Semantics::StateMachines::StateMachinesFactoryImpl;
			StateMachineSemanticVisitorImpl();
			virtual std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineSemanticVisitor> getThisStateMachineSemanticVisitorPtr() const;
			virtual void setThisStateMachineSemanticVisitorPtr(std::weak_ptr<PSSM::Semantics::StateMachines::StateMachineSemanticVisitor> thisStateMachineSemanticVisitorPtr);


		public:
			//destructor
			virtual ~StateMachineSemanticVisitorImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			virtual void activate() ;
			virtual void activateTransitions() ;
			virtual std::shared_ptr<Bag<fUML::Semantics::Loci::SemanticVisitor>> getContextChain() ;
			virtual std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object> getExecutionContext() ;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> getExecutionFor(const std::shared_ptr<uml::Behavior>& behavior, const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence, const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object>& context) ;
			virtual std::shared_ptr<fUML::Semantics::Loci::Locus> getExecutionLocus() ;
			
			
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> getStateMachineExecution() ;
			virtual bool isVisitorFor(const std::shared_ptr<uml::NamedElement>& node) ;
			virtual bool match(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence, const std::shared_ptr<Bag<uml::Trigger>>& triggers) ;
			
			
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<uml::NamedElement>& getNode() const ;
			virtual void setNode(const std::shared_ptr<uml::NamedElement>&) ;
			virtual const std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor>& getParent() const ;
			virtual void setParent(const std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor>&) ;
			
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
			std::weak_ptr<PSSM::Semantics::StateMachines::StateMachineSemanticVisitor> m_thisStateMachineSemanticVisitorPtr;
	};
}
#endif /* end of include guard: PSSM_SEMANTICS_STATEMACHINES_STATEMACHINESEMANTICVISITORSTATEMACHINESEMANTICVISITORIMPL_HPP */