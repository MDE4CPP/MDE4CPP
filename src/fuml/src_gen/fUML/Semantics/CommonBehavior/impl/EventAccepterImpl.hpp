//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_COMMONBEHAVIOR_EVENTACCEPTEREVENTACCEPTERIMPL_HPP
#define FUML_SEMANTICS_COMMONBEHAVIOR_EVENTACCEPTEREVENTACCEPTERIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../EventAccepter.hpp"

#include "fUML/Semantics/CommonBehavior/impl/CommonBehaviorFactoryImpl.hpp"

#include "ecore/impl/EModelElementImpl.hpp"

//*********************************
namespace fUML::Semantics::CommonBehavior 
{
	class EventAccepterImpl : virtual public ecore::EModelElementImpl,
virtual public EventAccepter 
	{
		public: 
			EventAccepterImpl(const EventAccepterImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			EventAccepterImpl& operator=(EventAccepterImpl const&) = delete;

		protected:
			friend class fUML::Semantics::CommonBehavior::CommonBehaviorFactoryImpl;
			EventAccepterImpl();
			virtual std::shared_ptr<EventAccepter> getThisEventAccepterPtr() const;
			virtual void setThisEventAccepterPtr(std::weak_ptr<EventAccepter> thisEventAccepterPtr);



		public:
			//destructor
			virtual ~EventAccepterImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual void accept(std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance>  signalInstance) ;
			
			 
			virtual bool match(std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance>  signalInstance) ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
							
			
			//*********************************
			// Union Getter
			//*********************************
			 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<EventAccepter> m_thisEventAccepterPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_COMMONBEHAVIOR_EVENTACCEPTEREVENTACCEPTERIMPL_HPP */
