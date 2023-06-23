//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_SENDOBJECTACTIONSENDOBJECTACTIONIMPL_HPP
#define UML_SENDOBJECTACTIONSENDOBJECTACTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../SendObjectAction.hpp"

#include "uml/impl/InvocationActionImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API SendObjectActionImpl : virtual public InvocationActionImpl, virtual public SendObjectAction 
	{
		public: 
			SendObjectActionImpl(const SendObjectActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			SendObjectActionImpl& operator=(SendObjectActionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			SendObjectActionImpl();
			virtual std::shared_ptr<uml::SendObjectAction> getThisSendObjectActionPtr() const;
			virtual void setThisSendObjectActionPtr(std::weak_ptr<uml::SendObjectAction> thisSendObjectActionPtr);

			//Additional constructors for the containments back reference
			SendObjectActionImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			SendObjectActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			SendObjectActionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			SendObjectActionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~SendObjectActionImpl();
			
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
			The request object, which is transmitted to the target object. The object may be copied in transmission, so identity might not be preserved.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::InputPin>& getRequest() const ;
			/*!
			The request object, which is transmitted to the target object. The object may be copied in transmission, so identity might not be preserved.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setRequest(const std::shared_ptr<uml::InputPin>&) ;
			/*!
			The target object to which the object is sent.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::InputPin>& getTarget() const ;
			/*!
			The target object to which the object is sent.
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
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;

		protected:
			virtual const std::shared_ptr<ecore::EClass>& eStaticClass() const;

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
			std::weak_ptr<uml::SendObjectAction> m_thisSendObjectActionPtr;
	};
}
#endif /* end of include guard: UML_SENDOBJECTACTIONSENDOBJECTACTIONIMPL_HPP */
