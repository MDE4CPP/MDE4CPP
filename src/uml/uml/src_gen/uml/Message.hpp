//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_MESSAGE_HPP
#define UML_MESSAGE_HPP


#include <memory>
#include <string>
// forward declarations
template<class T, class ... U> class Subset;


//*********************************
// generated Includes
#include <map> // used for Persistence
#include <vector> // used for Persistence
namespace persistence
{
	namespace interfaces
	{
		class XLoadHandler; // used for Persistence
		class XSaveHandler; // used for Persistence
	}
}

namespace uml
{
	class umlFactory;
}

//Forward Declaration for used types 
namespace uml 
{
	class Comment;
	class Connector;
	class Dependency;
	class Interaction;
	class MessageEnd;
	class Namespace;
	class StringExpression;
	class ValueSpecification;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/NamedElement.hpp"

// enum includes
#include "uml/MessageKind.hpp"
#include "uml/MessageSort.hpp"
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A Message defines a particular communication between Lifelines of an Interaction.
	<p>From package UML::Interactions.</p>
	*/
	
	class UML_API Message : virtual public NamedElement
	{
		public:
 			Message(const Message &) {}

		protected:
			Message(){}
			//Additional constructors for the containments back reference
			Message(std::weak_ptr<uml::Interaction> par_interaction);

			//Additional constructors for the containments back reference
			Message(std::weak_ptr<uml::Namespace> par_namespace);

			//Additional constructors for the containments back reference
			Message(std::weak_ptr<uml::Element> par_owner);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Message() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			This query returns the MessageKind value for this Message.
			result = (messageKind)
			<p>From package UML::Interactions.</p>
			*/
			 
			virtual uml::MessageKind getMessageKind() = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			The derived kind of the Message (complete, lost, found, or unknown).
			<p>From package UML::Interactions.</p>
			*/
			 
			virtual uml::MessageKind getMessageKind() const = 0;
			/*!
			The sort of communication reflected by the Message.
			<p>From package UML::Interactions.</p>
			*/
			 
			virtual uml::MessageSort getMessageSort() const = 0;
			/*!
			The sort of communication reflected by the Message.
			<p>From package UML::Interactions.</p>
			*/
			 
			virtual void setMessageSort (uml::MessageSort _messageSort)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The arguments of the Message.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ValueSpecification, uml::Element>> getArgument() const = 0;
			/*!
			The Connector on which this Message is sent.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::Connector> getConnector() const = 0;
			/*!
			The Connector on which this Message is sent.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setConnector(std::shared_ptr<uml::Connector>) = 0;
			/*!
			The enclosing Interaction owning the Message.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::weak_ptr<uml::Interaction> getInteraction() const = 0;
			/*!
			The enclosing Interaction owning the Message.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setInteraction(std::weak_ptr<uml::Interaction>) = 0;
			/*!
			References the Receiving of the Message.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::MessageEnd> getReceiveEvent() const = 0;
			/*!
			References the Receiving of the Message.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setReceiveEvent(std::shared_ptr<uml::MessageEnd>) = 0;
			/*!
			References the Sending of the Message.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::MessageEnd> getSendEvent() const = 0;
			/*!
			References the Sending of the Message.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setSendEvent(std::shared_ptr<uml::MessageEnd>) = 0;
			/*!
			The signature of the Message is the specification of its content. It refers either an Operation or a Signal.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::NamedElement> getSignature() const = 0;
			/*!
			The signature of the Message is the specification of its content. It refers either an Operation or a Signal.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setSignature(std::shared_ptr<uml::NamedElement>) = 0;

			//*********************************
			// Union Reference Getters
			//*********************************

			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 

			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			The derived kind of the Message (complete, lost, found, or unknown).
			<p>From package UML::Interactions.</p>
			*/
			
			uml::MessageKind m_messageKind= uml::MessageKind::UNKNOWN;
			/*!
			The sort of communication reflected by the Message.
			<p>From package UML::Interactions.</p>
			*/
			
			uml::MessageSort m_messageSort= uml::MessageSort::SYNCHCALL;
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The arguments of the Message.
			<p>From package UML::Interactions.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::ValueSpecification, uml::Element>> m_argument;
			/*!
			The Connector on which this Message is sent.
			<p>From package UML::Interactions.</p>
			*/
			
			std::shared_ptr<uml::Connector> m_connector;
			/*!
			The enclosing Interaction owning the Message.
			<p>From package UML::Interactions.</p>
			*/
			
			std::weak_ptr<uml::Interaction> m_interaction;
			/*!
			References the Receiving of the Message.
			<p>From package UML::Interactions.</p>
			*/
			
			std::shared_ptr<uml::MessageEnd> m_receiveEvent;
			/*!
			References the Sending of the Message.
			<p>From package UML::Interactions.</p>
			*/
			
			std::shared_ptr<uml::MessageEnd> m_sendEvent;
			/*!
			The signature of the Message is the specification of its content. It refers either an Operation or a Signal.
			<p>From package UML::Interactions.</p>
			*/
			
			std::shared_ptr<uml::NamedElement> m_signature;
	};
}
#endif /* end of include guard: UML_MESSAGE_HPP */
