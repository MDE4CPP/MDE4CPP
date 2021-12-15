//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_COMMONBEHAVIOR_CS_EVENTOCCURRENCE_HPP
#define PSCS_SEMANTICS_COMMONBEHAVIOR_CS_EVENTOCCURRENCE_HPP


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

namespace PSCS
{
	class PSCSFactory;
}

//Forward Declaration for used types 
namespace fUML::Semantics::CommonBehavior 
{
	class ParameterValue;
}
namespace fUML::Semantics::StructuredClassifiers 
{
	class Reference;
}
namespace PSCS::Semantics::StructuredClassifiers 
{
	class CS_InteractionPoint;
	class CS_Reference;
}
namespace uml 
{
	class Port;
	class Trigger;
}

// namespace macro header include
#include "PSCS/PSCS.hpp"

// base class includes
#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"




//*********************************
namespace PSCS::Semantics::CommonBehavior 
{
	
	class PSCS_API CS_EventOccurrence: virtual public fUML::Semantics::CommonBehavior::EventOccurrence
	{
		public:
 			CS_EventOccurrence(const CS_EventOccurrence &) {}

		protected:
			CS_EventOccurrence(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~CS_EventOccurrence() {}

			//*********************************
			// Operations
			//*********************************
			virtual void doSend() = 0;
			virtual std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > getParameterValues() = 0;
			virtual bool match(std::shared_ptr<uml::Trigger> trigger) = 0;
			virtual void sendInTo(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> target,std::shared_ptr<uml::Port> port) = 0;
			virtual void sendOutTo(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> target,std::shared_ptr<uml::Port> port) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual bool isPropagationInward() const = 0;
			virtual void setPropagationInward (bool _propagationInward)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> getInteractionPoint() const = 0;
			virtual void setInteractionPoint(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>) = 0;
			virtual std::shared_ptr<uml::Port> getOnPort() const = 0;
			virtual void setOnPort(std::shared_ptr<uml::Port>) = 0;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> getWrappedEventOccurrence() const = 0;
			virtual void setWrappedEventOccurrence(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>) = 0;

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
			bool m_propagationInward= false;
			
			//*********************************
			// Reference Members
			//*********************************
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> m_interactionPoint;
			std::shared_ptr<uml::Port> m_onPort;
			std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> m_wrappedEventOccurrence;
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_COMMONBEHAVIOR_CS_EVENTOCCURRENCE_HPP */
