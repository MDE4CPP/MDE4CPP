//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_RAISEEXCEPTIONACTIONRAISEEXCEPTIONACTIONIMPL_HPP
#define UML_RAISEEXCEPTIONACTIONRAISEEXCEPTIONACTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../RaiseExceptionAction.hpp"

#include "uml/impl/ActionImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API RaiseExceptionActionImpl : virtual public ActionImpl, virtual public RaiseExceptionAction 
	{
		public: 
			RaiseExceptionActionImpl(const RaiseExceptionActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			RaiseExceptionActionImpl& operator=(RaiseExceptionActionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			RaiseExceptionActionImpl();
			virtual std::shared_ptr<uml::RaiseExceptionAction> getThisRaiseExceptionActionPtr() const;
			virtual void setThisRaiseExceptionActionPtr(std::weak_ptr<uml::RaiseExceptionAction> thisRaiseExceptionActionPtr);

			//Additional constructors for the containments back reference
			RaiseExceptionActionImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			RaiseExceptionActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			RaiseExceptionActionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			RaiseExceptionActionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~RaiseExceptionActionImpl();
			
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
			An InputPin whose value becomes the exception object.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::InputPin> getException() const ;
			/*!
			An InputPin whose value becomes the exception object.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setException(const std::shared_ptr<uml::InputPin>&) ;
			
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
			std::weak_ptr<uml::RaiseExceptionAction> m_thisRaiseExceptionActionPtr;
	};
}
#endif /* end of include guard: UML_RAISEEXCEPTIONACTIONRAISEEXCEPTIONACTIONIMPL_HPP */
