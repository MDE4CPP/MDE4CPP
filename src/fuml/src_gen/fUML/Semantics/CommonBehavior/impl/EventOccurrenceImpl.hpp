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
			virtual std::shared_ptr<EventOccurrence> getThisEventOccurrencePtr() const;
			virtual void setThisEventOccurrencePtr(std::weak_ptr<EventOccurrence> thisEventOccurrencePtr);


		public:
			//destructor
			virtual ~EventOccurrenceImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual void doSend() ; 
			virtual std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > getParameterValues() ; 
			virtual bool match(std::shared_ptr<uml::Trigger> trigger) ; 
			virtual bool matchAny(std::shared_ptr<Bag<uml::Trigger>> triggers) ; 
			virtual void sendTo(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> target) ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> getTarget() const ;
			
			virtual void setTarget(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference>) ;
			
			
			//*********************************
			// Union Getter
			//*********************************
			
			

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<EventOccurrence> m_thisEventOccurrencePtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_COMMONBEHAVIOR_EVENTOCCURRENCEEVENTOCCURRENCEIMPL_HPP */
