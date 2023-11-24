//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSSM_SEMANTICS_STATEMACHINES_DEFERREDEVENTOCCURRENCEDEFERREDEVENTOCCURRENCEIMPL_HPP
#define PSSM_SEMANTICS_STATEMACHINES_DEFERREDEVENTOCCURRENCEDEFERREDEVENTOCCURRENCEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "PSSM/PSSM.hpp" 

// model includes
#include "../DeferredEventOccurrence.hpp"

#include "PSSM/Semantics/StateMachines/impl/StateMachinesFactoryImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/EventOccurrenceImpl.hpp"

//*********************************
namespace PSSM::Semantics::StateMachines 
{
	class PSSM_API DeferredEventOccurrenceImpl : virtual public fUML::Semantics::CommonBehavior::EventOccurrenceImpl, virtual public DeferredEventOccurrence 
	{
		public: 
			DeferredEventOccurrenceImpl(const DeferredEventOccurrenceImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			DeferredEventOccurrenceImpl& operator=(DeferredEventOccurrenceImpl const&); 

		protected:
			friend class PSSM::Semantics::StateMachines::StateMachinesFactoryImpl;
			DeferredEventOccurrenceImpl();
			virtual std::shared_ptr<PSSM::Semantics::StateMachines::DeferredEventOccurrence> getThisDeferredEventOccurrencePtr() const;
			virtual void setThisDeferredEventOccurrencePtr(std::weak_ptr<PSSM::Semantics::StateMachines::DeferredEventOccurrence> thisDeferredEventOccurrencePtr);


		public:
			//destructor
			virtual ~DeferredEventOccurrenceImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<PSSM::Semantics::StateMachines::StateActivation>& getConstrainingStateActivation() const ;
			virtual void setConstrainingStateActivation(const std::shared_ptr<PSSM::Semantics::StateMachines::StateActivation>&) ;
			virtual const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& getDeferredEventOccurrence() const ;
			virtual void setDeferredEventOccurrence(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>&) ;
			
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
			std::weak_ptr<PSSM::Semantics::StateMachines::DeferredEventOccurrence> m_thisDeferredEventOccurrencePtr;
	};
}
#endif /* end of include guard: PSSM_SEMANTICS_STATEMACHINES_DEFERREDEVENTOCCURRENCEDEFERREDEVENTOCCURRENCEIMPL_HPP */
