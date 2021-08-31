//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_COMMONBEHAVIOR_INVOCATIONEVENTOCCURRENCEINVOCATIONEVENTOCCURRENCEIMPL_HPP
#define FUML_SEMANTICS_COMMONBEHAVIOR_INVOCATIONEVENTOCCURRENCEINVOCATIONEVENTOCCURRENCEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../InvocationEventOccurrence.hpp"

#include "fUML/Semantics/CommonBehavior/impl/CommonBehaviorFactoryImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/EventOccurrenceImpl.hpp"

//*********************************
namespace fUML::Semantics::CommonBehavior 
{
	class FUML_API InvocationEventOccurrenceImpl : virtual public EventOccurrenceImpl, virtual public InvocationEventOccurrence 
	{
		public: 
			InvocationEventOccurrenceImpl(const InvocationEventOccurrenceImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			InvocationEventOccurrenceImpl& operator=(InvocationEventOccurrenceImpl const&); 

		protected:
			friend class fUML::Semantics::CommonBehavior::CommonBehaviorFactoryImpl;
			InvocationEventOccurrenceImpl();
			virtual std::shared_ptr<InvocationEventOccurrence> getThisInvocationEventOccurrencePtr() const;
			virtual void setThisInvocationEventOccurrencePtr(std::weak_ptr<InvocationEventOccurrence> thisInvocationEventOccurrencePtr);


		public:
			//destructor
			virtual ~InvocationEventOccurrenceImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > getParameterValues() ; 
			virtual bool match(std::shared_ptr<uml::Trigger> trigger) ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> getExecution() const ;
			
			virtual void setExecution(std::shared_ptr<fUML::Semantics::CommonBehavior::Execution>) ;
			
			
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
			std::weak_ptr<InvocationEventOccurrence> m_thisInvocationEventOccurrencePtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_COMMONBEHAVIOR_INVOCATIONEVENTOCCURRENCEINVOCATIONEVENTOCCURRENCEIMPL_HPP */
