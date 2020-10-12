//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_TRIGGER_HPP
#define UML_TRIGGER_HPP

#include <map>
#include <list>
#include <memory>
#include <string>


// forward declarations
template<class T> class Bag; 


class AnyObject;
typedef std::shared_ptr<AnyObject> Any;

//*********************************
// generated Includes

#include <map>

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
	class UmlFactory;
}

//Forward Declaration for used types
namespace uml 
{
	class Comment;
}

namespace uml 
{
	class Dependency;
}

namespace uml 
{
	class Element;
}

namespace uml 
{
	class Event;
}

namespace uml 
{
	class NamedElement;
}

namespace uml 
{
	class Namespace;
}

namespace uml 
{
	class Port;
}

namespace uml 
{
	class StringExpression;
}

// base class includes
#include "uml/NamedElement.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"


//*********************************
namespace uml 
{
	/*!
	 A Trigger specifies a specific point  at which an Event occurrence may trigger an effect in a Behavior. A Trigger may be qualified by the Port on which the Event occurred.
	<p>From package UML::CommonBehavior.</p> */
	class Trigger:virtual public NamedElement
	{
		public:
 			Trigger(const Trigger &) {}
			Trigger& operator=(Trigger const&) = delete;

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
			port->notEmpty() implies event.oclIsKindOf(MessageEvent) */ 
			virtual bool trigger_with_ports(Any diagnostics,std::map <   Any, Any >  context) = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 The Event that detected by the Trigger.
			<p>From package UML::CommonBehavior.</p> */
			virtual std::shared_ptr<uml::Event > getEvent() const = 0;
			
			/*!
			 The Event that detected by the Trigger.
			<p>From package UML::CommonBehavior.</p> */
			virtual void setEvent(std::shared_ptr<uml::Event> _event_event) = 0;
			/*!
			 A optional Port of through which the given effect is detected.
			<p>From package UML::CommonBehavior.</p> */
			virtual std::shared_ptr<Bag<uml::Port>> getPort() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 The Event that detected by the Trigger.
			<p>From package UML::CommonBehavior.</p> */
			std::shared_ptr<uml::Event > m_event;
			/*!
			 A optional Port of through which the given effect is detected.
			<p>From package UML::CommonBehavior.</p> */
			mutable std::shared_ptr<Bag<uml::Port>> m_port;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Element > getOwner() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_TRIGGER_HPP */
