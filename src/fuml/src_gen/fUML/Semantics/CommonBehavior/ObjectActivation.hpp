//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_COMMONBEHAVIOR_OBJECTACTIVATION_HPP
#define FUML_SEMANTICS_COMMONBEHAVIOR_OBJECTACTIVATION_HPP

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

namespace fUML
{
	class fUMLFactory;
}

//Forward Declaration for used types
namespace uml 
{
	class Class;
}

namespace fUML::Semantics::CommonBehavior 
{
	class ClassifierBehaviorExecution;
}

namespace fUML::Semantics::CommonBehavior 
{
	class EventAccepter;
}

namespace fUML::Semantics::StructuredClassifiers 
{
	class Object;
}

namespace fUML::Semantics::CommonBehavior 
{
	class ParameterValue;
}

namespace fUML::Semantics::SimpleClassifiers 
{
	class SignalInstance;
}

// base class includes

// enum includes

#include "ecore/EModelElement.hpp"

//*********************************
namespace fUML::Semantics::CommonBehavior 
{
	
	class ObjectActivation : virtual public ecore::EModelElement

	{
		public:
 			ObjectActivation(const ObjectActivation &) {}
			ObjectActivation& operator=(ObjectActivation const&) = delete;

		protected:
			ObjectActivation(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ObjectActivation() {}

			//*********************************
			// Operations
			//*********************************
			 
			virtual void _register(std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter>  accepter) = 0;
			
			 
			virtual void _send(Any signal) = 0;
			
			 
			virtual void _startObjectBehavior() = 0;
			
			 
			virtual void dispatchNextEvent() = 0;
			
			 
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> retrieveNextEvent() = 0;
			
			 
			virtual void send(std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance>  signalInstance) = 0;
			
			 
			virtual void startBehavior(std::shared_ptr<uml::Class>  classifier,std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> >  inputs) = 0;
			
			 
			virtual void stop() = 0;
			
			 
			virtual void unregister(std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter>  accepter) = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution>> getClassifierBehaviorExecutions() const = 0;
			
			
			
			virtual std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::SignalInstance>> getEventPool() const = 0;
			
			
			
			virtual std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object > getObject() const = 0;
			
			
			virtual void setObject(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> _object) = 0;
			
			
			virtual std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::EventAccepter>> getWaitingEventAccepters() const = 0;
			
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			
			mutable std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution>> m_classifierBehaviorExecutions;
			mutable std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::SignalInstance>> m_eventPool;
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object > m_object;
			mutable std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::EventAccepter>> m_waitingEventAccepters;

		public:
			//*********************************
			// Union Getter
			//*********************************
			

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: FUML_SEMANTICS_COMMONBEHAVIOR_OBJECTACTIVATION_HPP */
