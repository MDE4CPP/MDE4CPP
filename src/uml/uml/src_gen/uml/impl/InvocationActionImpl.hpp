//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INVOCATIONACTIONINVOCATIONACTIONIMPL_HPP
#define UML_INVOCATIONACTIONINVOCATIONACTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../InvocationAction.hpp"

#include "uml/impl/ActionImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API InvocationActionImpl : virtual public ActionImpl, virtual public InvocationAction 
	{
		public: 
			InvocationActionImpl(const InvocationActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			InvocationActionImpl& operator=(InvocationActionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			InvocationActionImpl();
			virtual std::shared_ptr<uml::InvocationAction> getThisInvocationActionPtr() const;
			virtual void setThisInvocationActionPtr(std::weak_ptr<uml::InvocationAction> thisInvocationActionPtr);

			//Additional constructors for the containments back reference
			InvocationActionImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			InvocationActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			InvocationActionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			InvocationActionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~InvocationActionImpl() = 0;
			
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
			The InputPins that provide the argument values passed in the invocation request.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<SubsetUnion<uml::InputPin, uml::InputPin>>& getArgument() const ;
			/*!
			For CallOperationActions, SendSignalActions, and SendObjectActions, an optional Port of the target object through which the invocation request is sent.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::Port>& getOnPort() const ;
			/*!
			For CallOperationActions, SendSignalActions, and SendObjectActions, an optional Port of the target object through which the invocation request is sent.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setOnPort(const std::shared_ptr<uml::Port>&) ;
			
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
			std::weak_ptr<uml::InvocationAction> m_thisInvocationActionPtr;
	};
}
#endif /* end of include guard: UML_INVOCATIONACTIONINVOCATIONACTIONIMPL_HPP */
