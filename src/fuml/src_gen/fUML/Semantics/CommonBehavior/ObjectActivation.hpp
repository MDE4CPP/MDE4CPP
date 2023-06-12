//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_COMMONBEHAVIOR_OBJECTACTIVATION_HPP
#define FUML_SEMANTICS_COMMONBEHAVIOR_OBJECTACTIVATION_HPP


#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 


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

namespace fUML
{
	class fUMLFactory;
}

//Forward Declaration for used types 
namespace fUML::Semantics::CommonBehavior 
{
	class ClassifierBehaviorExecution;
	class EventAccepter;
	class EventOccurrence;
	class ParameterValue;
}
namespace fUML::MDE4CPP_Extensions 
{
	class FUML_Object;
}
namespace uml 
{
	class Class;
}

// namespace macro header include
#include "fUML/fUML.hpp"



#include "ecore/EModelElement.hpp"


//*********************************
namespace fUML::Semantics::CommonBehavior 
{
	
	class FUML_API ObjectActivation : virtual public ecore::EModelElement
	{
		public:
 			ObjectActivation(const ObjectActivation &) {}

		protected:
			ObjectActivation(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ObjectActivation() {}

			//*********************************
			// Operations
			//*********************************
			virtual void _register(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter>& accepter) = 0;
			virtual void _startObjectBehavior() = 0;
			virtual void dispatchNextEvent() = 0;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> retrieveNextEvent() = 0;
			virtual void send(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence) = 0;
			virtual void startBehavior(const std::shared_ptr<uml::Class>& classifier, const std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>>& inputs) = 0;
			virtual void stop() = 0;
			virtual void unregister(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter>& accepter) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution>>& getClassifierBehaviorExecutions() const = 0;
			virtual const std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::EventOccurrence>>& getEventPool() const = 0;
			virtual const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object>& getObject() const = 0;
			virtual void setObject(const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object>&) = 0;
			virtual const std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::EventAccepter>>& getWaitingEventAccepters() const = 0;

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
			mutable std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution>> m_classifierBehaviorExecutions;
			mutable std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::EventOccurrence>> m_eventPool;
			std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object> m_object;
			mutable std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::EventAccepter>> m_waitingEventAccepters;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_COMMONBEHAVIOR_OBJECTACTIVATION_HPP */
