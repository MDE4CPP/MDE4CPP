//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSSM_SEMANTICS_STATEMACHINES_SHALLOWHISTORYPSEUDOSTATEACTIVATIONSHALLOWHISTORYPSEUDOSTATEACTIVATIONIMPL_HPP
#define PSSM_SEMANTICS_STATEMACHINES_SHALLOWHISTORYPSEUDOSTATEACTIVATIONSHALLOWHISTORYPSEUDOSTATEACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "PSSM/PSSM.hpp" 

// model includes
#include "../ShallowHistoryPseudostateActivation.hpp"

#include "PSSM/Semantics/StateMachines/impl/StateMachinesFactoryImpl.hpp"
#include "PSSM/Semantics/StateMachines/impl/HistoryPseudostateActivationImpl.hpp"

//*********************************
namespace PSSM::Semantics::StateMachines 
{
	class PSSM_API ShallowHistoryPseudostateActivationImpl : virtual public HistoryPseudostateActivationImpl, virtual public ShallowHistoryPseudostateActivation 
	{
		public: 
			ShallowHistoryPseudostateActivationImpl(const ShallowHistoryPseudostateActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ShallowHistoryPseudostateActivationImpl& operator=(ShallowHistoryPseudostateActivationImpl const&); 

		protected:
			friend class PSSM::Semantics::StateMachines::StateMachinesFactoryImpl;
			ShallowHistoryPseudostateActivationImpl();
			virtual std::shared_ptr<PSSM::Semantics::StateMachines::ShallowHistoryPseudostateActivation> getThisShallowHistoryPseudostateActivationPtr() const;
			virtual void setThisShallowHistoryPseudostateActivationPtr(std::weak_ptr<PSSM::Semantics::StateMachines::ShallowHistoryPseudostateActivation> thisShallowHistoryPseudostateActivationPtr);


		public:
			//destructor
			virtual ~ShallowHistoryPseudostateActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			
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
			std::weak_ptr<PSSM::Semantics::StateMachines::ShallowHistoryPseudostateActivation> m_thisShallowHistoryPseudostateActivationPtr;
	};
}
#endif /* end of include guard: PSSM_SEMANTICS_STATEMACHINES_SHALLOWHISTORYPSEUDOSTATEACTIVATIONSHALLOWHISTORYPSEUDOSTATEACTIVATIONIMPL_HPP */
