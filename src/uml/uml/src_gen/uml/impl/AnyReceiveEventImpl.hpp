//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ANYRECEIVEEVENTANYRECEIVEEVENTIMPL_HPP
#define UML_ANYRECEIVEEVENTANYRECEIVEEVENTIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../AnyReceiveEvent.hpp"

#include "uml/impl/MessageEventImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API AnyReceiveEventImpl : virtual public MessageEventImpl, virtual public AnyReceiveEvent 
	{
		public: 
			AnyReceiveEventImpl(const AnyReceiveEventImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			AnyReceiveEventImpl& operator=(AnyReceiveEventImpl const&); 

		protected:
			friend class umlFactoryImpl;
			AnyReceiveEventImpl();
			virtual std::shared_ptr<uml::AnyReceiveEvent> getThisAnyReceiveEventPtr() const;
			virtual void setThisAnyReceiveEventPtr(std::weak_ptr<uml::AnyReceiveEvent> thisAnyReceiveEventPtr);

			//Additional constructors for the containments back reference
			AnyReceiveEventImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			AnyReceiveEventImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			AnyReceiveEventImpl(std::weak_ptr<uml::Package> par_owningPackage);
			//Additional constructors for the containments back reference
			AnyReceiveEventImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

		public:
			//destructor
			virtual ~AnyReceiveEventImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			
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
			std::weak_ptr<uml::AnyReceiveEvent> m_thisAnyReceiveEventPtr;
	};
}
#endif /* end of include guard: UML_ANYRECEIVEEVENTANYRECEIVEEVENTIMPL_HPP */
