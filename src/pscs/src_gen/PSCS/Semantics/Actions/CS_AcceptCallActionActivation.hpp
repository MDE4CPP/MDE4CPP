//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_ACTIONS_CS_ACCEPTCALLACTIONACTIVATION_HPP
#define PSCS_SEMANTICS_ACTIONS_CS_ACCEPTCALLACTIONACTIVATION_HPP


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
namespace fUML::Semantics::Actions 
{
	class AcceptEventActionEventAccepter;
	class InputPinActivation;
	class OutputPinActivation;
	class PinActivation;
}
namespace fUML::Semantics::Activities 
{
	class ActivityEdgeInstance;
	class ActivityNodeActivationGroup;
	class Token;
}
namespace fUML::Semantics::CommonBehavior 
{
	class EventOccurrence;
}
namespace uml 
{
	class AcceptEventAction;
	class Action;
	class ActivityNode;
}

// namespace macro header include
#include "PSCS/PSCS.hpp"



#include "ecore/EModelElement.hpp"


//*********************************
namespace PSCS::Semantics::Actions 
{
	
	class PSCS_API CS_AcceptCallActionActivation : virtual public ecore::EModelElement
	{
		public:
 			CS_AcceptCallActionActivation(const CS_AcceptCallActionActivation &) {}

		protected:
			CS_AcceptCallActionActivation(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~CS_AcceptCallActionActivation() {}

			//*********************************
			// Operations
			//*********************************
			

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************

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
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			//*********************************
			// Reference Members
			//*********************************
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_ACTIONS_CS_ACCEPTCALLACTIONACTIVATION_HPP */
