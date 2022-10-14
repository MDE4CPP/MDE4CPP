//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_TRIGGER_HPP
#define UML_TRIGGER_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 

class Any;

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
	class Dependency;
	class Event;
	class Namespace;
	class Port;
	class StringExpression;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/NamedElement.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A Trigger specifies a specific point  at which an Event occurrence may trigger an effect in a Behavior. A Trigger may be qualified by the Port on which the Event occurred.
	<p>From package UML::CommonBehavior.</p>
	*/
	
	class UML_API Trigger : virtual public NamedElement
	{
		public:
 			Trigger(const Trigger &) {}

		protected:
			Trigger(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Trigger() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			If a Trigger specifies one or more ports, the event of the Trigger must be a MessageEvent.
			port->notEmpty() implies event.oclIsKindOf(MessageEvent)
			*/
			 
			virtual bool trigger_with_ports(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The Event that detected by the Trigger.
			<p>From package UML::CommonBehavior.</p>
			*/
			
			virtual std::shared_ptr<uml::Event> getEvent() const = 0;
			/*!
			The Event that detected by the Trigger.
			<p>From package UML::CommonBehavior.</p>
			*/
			
			virtual void setEvent(std::shared_ptr<uml::Event>) = 0;
			/*!
			A optional Port of through which the given effect is detected.
			<p>From package UML::CommonBehavior.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Port>> getPort() const = 0;

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
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The Event that detected by the Trigger.
			<p>From package UML::CommonBehavior.</p>
			*/
			
			std::shared_ptr<uml::Event> m_event;
			/*!
			A optional Port of through which the given effect is detected.
			<p>From package UML::CommonBehavior.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::Port>> m_port;
	};
}
#endif /* end of include guard: UML_TRIGGER_HPP */
