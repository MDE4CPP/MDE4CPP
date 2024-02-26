//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSSM_SEMANTICS_STATEMACHINES_INTERNALTRANSITIONACTIVATIONINTERNALTRANSITIONACTIVATIONIMPL_HPP
#define PSSM_SEMANTICS_STATEMACHINES_INTERNALTRANSITIONACTIVATIONINTERNALTRANSITIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "PSSM/PSSM.hpp" 

// model includes
#include "../InternalTransitionActivation.hpp"

#include "PSSM/Semantics/StateMachines/impl/StateMachinesFactoryImpl.hpp"
#include "PSSM/Semantics/StateMachines/impl/TransitionActivationImpl.hpp"

//*********************************
namespace PSSM::Semantics::StateMachines 
{
	class PSSM_API InternalTransitionActivationImpl : virtual public TransitionActivationImpl, virtual public InternalTransitionActivation 
	{
		public: 
			InternalTransitionActivationImpl(const InternalTransitionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			InternalTransitionActivationImpl& operator=(InternalTransitionActivationImpl const&); 

		protected:
			friend class PSSM::Semantics::StateMachines::StateMachinesFactoryImpl;
			InternalTransitionActivationImpl();
			virtual std::shared_ptr<PSSM::Semantics::StateMachines::InternalTransitionActivation> getThisInternalTransitionActivationPtr() const;
			virtual void setThisInternalTransitionActivationPtr(std::weak_ptr<PSSM::Semantics::StateMachines::InternalTransitionActivation> thisInternalTransitionActivationPtr);


		public:
			//destructor
			virtual ~InternalTransitionActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual void enterTarget(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence) ;
			virtual void exitSource(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			
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
			std::weak_ptr<PSSM::Semantics::StateMachines::InternalTransitionActivation> m_thisInternalTransitionActivationPtr;
	};
}
#endif /* end of include guard: PSSM_SEMANTICS_STATEMACHINES_INTERNALTRANSITIONACTIVATIONINTERNALTRANSITIONACTIVATIONIMPL_HPP */
