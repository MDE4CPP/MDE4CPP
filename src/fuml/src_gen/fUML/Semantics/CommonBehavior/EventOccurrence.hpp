//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_COMMONBEHAVIOR_EVENTOCCURRENCE_HPP
#define FUML_SEMANTICS_COMMONBEHAVIOR_EVENTOCCURRENCE_HPP


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
	class ParameterValue;
}
namespace fUML::Semantics::StructuredClassifiers 
{
	class Reference;
}
namespace uml 
{
	class Event;
	class Trigger;
}

// namespace macro header include
#include "fUML/fUML.hpp"



#include "ecore/EModelElement.hpp"


//*********************************
namespace fUML::Semantics::CommonBehavior 
{
	
	class FUML_API EventOccurrence : virtual public ecore::EModelElement
	{
		public:
 			EventOccurrence(const EventOccurrence &) {}

		protected:
			EventOccurrence(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~EventOccurrence() {}

			//*********************************
			// Operations
			//*********************************
			virtual void doSend() = 0;
			virtual std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> getParameterValues(const std::shared_ptr<uml::Event>& event) = 0;
			virtual std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> getParameterValues() = 0;
			virtual bool match(const std::shared_ptr<uml::Trigger>& trigger) = 0;
			virtual bool matchAny(const std::shared_ptr<Bag<uml::Trigger>>& triggers) = 0;
			virtual void sendTo(const std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference>& target) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference>& getTarget() const = 0;
			virtual void setTarget(const std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference>&) = 0;

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
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> m_target;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_COMMONBEHAVIOR_EVENTOCCURRENCE_HPP */
