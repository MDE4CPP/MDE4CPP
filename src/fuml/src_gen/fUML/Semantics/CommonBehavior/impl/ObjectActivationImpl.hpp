//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_COMMONBEHAVIOR_OBJECTACTIVATIONOBJECTACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_COMMONBEHAVIOR_OBJECTACTIVATIONOBJECTACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../ObjectActivation.hpp"

#include "fUML/Semantics/CommonBehavior/impl/CommonBehaviorFactoryImpl.hpp"

#include "ecore/impl/EModelElementImpl.hpp"

//*********************************
namespace fUML::Semantics::CommonBehavior 
{
	class FUML_API ObjectActivationImpl : virtual public ecore::EModelElementImpl,
virtual public ObjectActivation 
	{
		public: 
			ObjectActivationImpl(const ObjectActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ObjectActivationImpl& operator=(ObjectActivationImpl const&); 

		protected:
			friend class fUML::Semantics::CommonBehavior::CommonBehaviorFactoryImpl;
			ObjectActivationImpl();
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> getThisObjectActivationPtr() const;
			virtual void setThisObjectActivationPtr(std::weak_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> thisObjectActivationPtr);


		public:
			//destructor
			virtual ~ObjectActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual void _register(std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter> accepter) ;
			virtual void _send(Any signal) ;
			virtual void _startObjectBehavior() ;
			virtual void dispatchNextEvent() ;
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> retrieveNextEvent() ;
			virtual void send(std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> signalInstance) ;
			virtual void startBehavior(std::shared_ptr<uml::Class> classifier,std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> inputs) ;
			virtual void stop() ;
			virtual void unregister(std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter> accepter) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution>> getClassifierBehaviorExecutions() const ;
			virtual std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::SignalInstance>> getEventPool() const ;
			virtual std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> getObject() const ;
			virtual void setObject(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object>) ;
			virtual std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::EventAccepter>> getWaitingEventAccepters() const ;
			
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
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments) ;

		private:
			std::weak_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> m_thisObjectActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_COMMONBEHAVIOR_OBJECTACTIVATIONOBJECTACTIVATIONIMPL_HPP */
