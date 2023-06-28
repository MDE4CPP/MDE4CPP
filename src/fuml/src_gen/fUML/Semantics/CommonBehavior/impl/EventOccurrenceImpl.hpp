//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_COMMONBEHAVIOR_EVENTOCCURRENCEEVENTOCCURRENCEIMPL_HPP
#define FUML_SEMANTICS_COMMONBEHAVIOR_EVENTOCCURRENCEEVENTOCCURRENCEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../EventOccurrence.hpp"

#include "fUML/Semantics/CommonBehavior/impl/CommonBehaviorFactoryImpl.hpp"

#include "ecore/impl/EModelElementImpl.hpp"

//*********************************
namespace fUML::Semantics::CommonBehavior 
{
	class FUML_API EventOccurrenceImpl : virtual public ecore::EModelElementImpl,
virtual public EventOccurrence 
	{
		public: 
			EventOccurrenceImpl(const EventOccurrenceImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			EventOccurrenceImpl& operator=(EventOccurrenceImpl const&); 

		protected:
			friend class fUML::Semantics::CommonBehavior::CommonBehaviorFactoryImpl;
			EventOccurrenceImpl();
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> getThisEventOccurrencePtr() const;
			virtual void setThisEventOccurrencePtr(std::weak_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> thisEventOccurrencePtr);


		public:
			//destructor
			virtual ~EventOccurrenceImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual void doSend() ;
			virtual std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> getParameterValues(const std::shared_ptr<uml::Event>& event) ;
			virtual bool match(const std::shared_ptr<uml::Trigger>& trigger) ;
			virtual bool matchAny(const std::shared_ptr<Bag<uml::Trigger>>& triggers) ;
			virtual void sendTo(const std::shared_ptr<uml::Element>& target) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<uml::Element>& getTarget() const ;
			virtual void setTarget(const std::shared_ptr<uml::Element>&) ;
			
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
			std::weak_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> m_thisEventOccurrencePtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_COMMONBEHAVIOR_EVENTOCCURRENCEEVENTOCCURRENCEIMPL_HPP */
