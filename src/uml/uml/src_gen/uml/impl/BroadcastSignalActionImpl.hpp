//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_BROADCASTSIGNALACTIONBROADCASTSIGNALACTIONIMPL_HPP
#define UML_BROADCASTSIGNALACTIONBROADCASTSIGNALACTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../BroadcastSignalAction.hpp"

#include "uml/impl/InvocationActionImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API BroadcastSignalActionImpl : virtual public InvocationActionImpl, virtual public BroadcastSignalAction 
	{
		public: 
			BroadcastSignalActionImpl(const BroadcastSignalActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			BroadcastSignalActionImpl& operator=(BroadcastSignalActionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			BroadcastSignalActionImpl();
			virtual std::shared_ptr<uml::BroadcastSignalAction> getThisBroadcastSignalActionPtr() const;
			virtual void setThisBroadcastSignalActionPtr(std::weak_ptr<uml::BroadcastSignalAction> thisBroadcastSignalActionPtr);

			//Additional constructors for the containments back reference
			BroadcastSignalActionImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			BroadcastSignalActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			BroadcastSignalActionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			BroadcastSignalActionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~BroadcastSignalActionImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The Signal whose instances are to be sent.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::Signal>& getSignal() const ;
			/*!
			The Signal whose instances are to be sent.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setSignal(const std::shared_ptr<uml::Signal>&) ;
			
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
			virtual std::shared_ptr<Any> eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, const std::shared_ptr<Any>& newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID,const std::shared_ptr<Bag<Any>>& arguments) ;

		private:
			std::weak_ptr<uml::BroadcastSignalAction> m_thisBroadcastSignalActionPtr;
	};
}
#endif /* end of include guard: UML_BROADCASTSIGNALACTIONBROADCASTSIGNALACTIONIMPL_HPP */
