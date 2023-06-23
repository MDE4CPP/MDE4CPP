//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_MESSAGEMESSAGEIMPL_HPP
#define UML_MESSAGEMESSAGEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Message.hpp"

#include "uml/impl/NamedElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API MessageImpl : virtual public NamedElementImpl, virtual public Message 
	{
		public: 
			MessageImpl(const MessageImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			MessageImpl& operator=(MessageImpl const&); 

		protected:
			friend class umlFactoryImpl;
			MessageImpl();
			virtual std::shared_ptr<uml::Message> getThisMessagePtr() const;
			virtual void setThisMessagePtr(std::weak_ptr<uml::Message> thisMessagePtr);

			//Additional constructors for the containments back reference
			MessageImpl(std::weak_ptr<uml::Interaction> par_interaction);
			//Additional constructors for the containments back reference
			MessageImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			MessageImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~MessageImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			This query returns the MessageKind value for this Message.
			result = (messageKind)
			<p>From package UML::Interactions.</p>
			*/
			 
			virtual uml::MessageKind getMessageKind() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			The derived kind of the Message (complete, lost, found, or unknown).
			<p>From package UML::Interactions.</p>
			*/
			 
			virtual uml::MessageKind getMessageKind() const ;
			/*!
			The sort of communication reflected by the Message.
			<p>From package UML::Interactions.</p>
			*/
			 
			virtual uml::MessageSort getMessageSort() const ;
			/*!
			The sort of communication reflected by the Message.
			<p>From package UML::Interactions.</p>
			*/
			 
			virtual void setMessageSort (uml::MessageSort _messageSort);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The arguments of the Message.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::ValueSpecification, uml::Element>>& getArgument() const ;
			/*!
			The Connector on which this Message is sent.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual const std::shared_ptr<uml::Connector>& getConnector() const ;
			/*!
			The Connector on which this Message is sent.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setConnector(const std::shared_ptr<uml::Connector>&) ;
			/*!
			The enclosing Interaction owning the Message.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::weak_ptr<uml::Interaction> getInteraction() const ;
			/*!
			The enclosing Interaction owning the Message.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setInteraction(std::weak_ptr<uml::Interaction>) ;
			/*!
			References the Receiving of the Message.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual const std::shared_ptr<uml::MessageEnd>& getReceiveEvent() const ;
			/*!
			References the Receiving of the Message.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setReceiveEvent(const std::shared_ptr<uml::MessageEnd>&) ;
			/*!
			References the Sending of the Message.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual const std::shared_ptr<uml::MessageEnd>& getSendEvent() const ;
			/*!
			References the Sending of the Message.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setSendEvent(const std::shared_ptr<uml::MessageEnd>&) ;
			/*!
			The signature of the Message is the specification of its content. It refers either an Operation or a Signal.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual const std::shared_ptr<uml::NamedElement>& getSignature() const ;
			/*!
			The signature of the Message is the specification of its content. It refers either an Operation or a Signal.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setSignature(const std::shared_ptr<uml::NamedElement>&) ;
			
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
			std::weak_ptr<uml::Message> m_thisMessagePtr;
	};
}
#endif /* end of include guard: UML_MESSAGEMESSAGEIMPL_HPP */
