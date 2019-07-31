//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_ACTIONS_CS_SENDSIGNALACTIONACTIVATION_HPP
#define PSCS_SEMANTICS_ACTIONS_CS_SENDSIGNALACTIONACTIVATION_HPP

#include <list>
#include <memory>
#include <string>


// forward declarations



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

namespace PSCS
{
	class PSCSFactory;
}

//Forward Declaration for used types

// base class includes

// enum includes

#include "ecore/EObject.hpp"

//*********************************
namespace PSCS::Semantics::Actions 
{
	/*!
	 */
	class CS_SendSignalActionActivation : virtual public ecore::EObject 

	{
		public:
 			CS_SendSignalActionActivation(const CS_SendSignalActionActivation &) {}
			CS_SendSignalActionActivation& operator=(CS_SendSignalActionActivation const&) = delete;

		protected:
			CS_SendSignalActionActivation(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~CS_SendSignalActionActivation() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual void doAction() = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			

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
#endif /* end of include guard: PSCS_SEMANTICS_ACTIONS_CS_SENDSIGNALACTIONACTIVATION_HPP */
