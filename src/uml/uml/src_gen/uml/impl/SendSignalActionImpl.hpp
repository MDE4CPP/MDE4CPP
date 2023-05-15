//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_SENDSIGNALACTIONSENDSIGNALACTIONIMPL_HPP
#define UML_SENDSIGNALACTIONSENDSIGNALACTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../SendSignalAction.hpp"

#include "uml/impl/InvocationActionImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API SendSignalActionImpl : virtual public InvocationActionImpl, virtual public SendSignalAction 
	{
		public: 
			SendSignalActionImpl(const SendSignalActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			SendSignalActionImpl& operator=(SendSignalActionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			SendSignalActionImpl();
			virtual std::shared_ptr<uml::SendSignalAction> getThisSendSignalActionPtr() const;
			virtual void setThisSendSignalActionPtr(std::weak_ptr<uml::SendSignalAction> thisSendSignalActionPtr);

			//Additional constructors for the containments back reference
			SendSignalActionImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			SendSignalActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			SendSignalActionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			SendSignalActionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~SendSignalActionImpl();
			
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
			The Signal whose instance is transmitted to the target.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::Signal> getSignal() const ;
			/*!
			The Signal whose instance is transmitted to the target.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setSignal(std::shared_ptr<uml::Signal>) ;
			/*!
			The InputPin that provides the target object to which the Signal instance is sent.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::InputPin> getTarget() const ;
			/*!
			The InputPin that provides the target object to which the Signal instance is sent.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setTarget(std::shared_ptr<uml::InputPin>) ;
			
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
			std::weak_ptr<uml::SendSignalAction> m_thisSendSignalActionPtr;
	};
}
#endif /* end of include guard: UML_SENDSIGNALACTIONSENDSIGNALACTIONIMPL_HPP */
