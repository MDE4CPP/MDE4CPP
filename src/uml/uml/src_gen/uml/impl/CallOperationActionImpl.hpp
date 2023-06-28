//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CALLOPERATIONACTIONCALLOPERATIONACTIONIMPL_HPP
#define UML_CALLOPERATIONACTIONCALLOPERATIONACTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../CallOperationAction.hpp"

#include "uml/impl/CallActionImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API CallOperationActionImpl : virtual public CallActionImpl, virtual public CallOperationAction 
	{
		public: 
			CallOperationActionImpl(const CallOperationActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			CallOperationActionImpl& operator=(CallOperationActionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			CallOperationActionImpl();
			virtual std::shared_ptr<uml::CallOperationAction> getThisCallOperationActionPtr() const;
			virtual void setThisCallOperationActionPtr(std::weak_ptr<uml::CallOperationAction> thisCallOperationActionPtr);

			//Additional constructors for the containments back reference
			CallOperationActionImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			CallOperationActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			CallOperationActionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			CallOperationActionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~CallOperationActionImpl();
			
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
			The Operation being invoked.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::Operation>& getOperation() const ;
			/*!
			The Operation being invoked.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setOperation(const std::shared_ptr<uml::Operation>&) ;
			/*!
			The InputPin that provides the target object to which the Operation call request is sent.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::InputPin>& getTarget() const ;
			/*!
			The InputPin that provides the target object to which the Operation call request is sent.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setTarget(const std::shared_ptr<uml::InputPin>&) ;
			
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
			std::weak_ptr<uml::CallOperationAction> m_thisCallOperationActionPtr;
	};
}
#endif /* end of include guard: UML_CALLOPERATIONACTIONCALLOPERATIONACTIONIMPL_HPP */
