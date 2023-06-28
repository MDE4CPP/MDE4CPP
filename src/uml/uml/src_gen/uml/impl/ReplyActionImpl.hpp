//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_REPLYACTIONREPLYACTIONIMPL_HPP
#define UML_REPLYACTIONREPLYACTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../ReplyAction.hpp"

#include "uml/impl/ActionImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ReplyActionImpl : virtual public ActionImpl, virtual public ReplyAction 
	{
		public: 
			ReplyActionImpl(const ReplyActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ReplyActionImpl& operator=(ReplyActionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ReplyActionImpl();
			virtual std::shared_ptr<uml::ReplyAction> getThisReplyActionPtr() const;
			virtual void setThisReplyActionPtr(std::weak_ptr<uml::ReplyAction> thisReplyActionPtr);

			//Additional constructors for the containments back reference
			ReplyActionImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			ReplyActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			ReplyActionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ReplyActionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~ReplyActionImpl();
			
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
			The Trigger specifying the Operation whose call is being replied to.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::Trigger>& getReplyToCall() const ;
			/*!
			The Trigger specifying the Operation whose call is being replied to.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setReplyToCall(const std::shared_ptr<uml::Trigger>&) ;
			/*!
			A list of InputPins providing the values for the output (inout, out, and return) Parameters of the Operation. These values are returned to the caller.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::InputPin, uml::InputPin>>& getReplyValue() const ;
			/*!
			An InputPin that holds the return information value produced by an earlier AcceptCallAction.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::InputPin>& getReturnInformation() const ;
			/*!
			An InputPin that holds the return information value produced by an earlier AcceptCallAction.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setReturnInformation(const std::shared_ptr<uml::InputPin>&) ;
			
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
			std::weak_ptr<uml::ReplyAction> m_thisReplyActionPtr;
	};
}
#endif /* end of include guard: UML_REPLYACTIONREPLYACTIONIMPL_HPP */
