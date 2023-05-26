//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_SIGNALEVENT_HPP
#define UML_SIGNALEVENT_HPP


#include <memory>
#include <string>
// forward declarations


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
	class Namespace;
	class Package;
	class Signal;
	class StringExpression;
	class TemplateParameter;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/MessageEvent.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A SignalEvent represents the receipt of an asynchronous Signal instance.
	<p>From package UML::CommonBehavior.</p>
	*/
	
	class UML_API SignalEvent : virtual public MessageEvent
	{
		public:
 			SignalEvent(const SignalEvent &) {}

		protected:
			SignalEvent(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~SignalEvent() {}

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
			The specific Signal that is associated with this SignalEvent.
			<p>From package UML::CommonBehavior.</p>
			*/
			
			virtual std::shared_ptr<uml::Signal> getSignal() const = 0;
			/*!
			The specific Signal that is associated with this SignalEvent.
			<p>From package UML::CommonBehavior.</p>
			*/
			
			virtual void setSignal(const std::shared_ptr<uml::Signal>&) = 0;

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
			The specific Signal that is associated with this SignalEvent.
			<p>From package UML::CommonBehavior.</p>
			*/
			
			std::shared_ptr<uml::Signal> m_signal;
	};
}
#endif /* end of include guard: UML_SIGNALEVENT_HPP */
