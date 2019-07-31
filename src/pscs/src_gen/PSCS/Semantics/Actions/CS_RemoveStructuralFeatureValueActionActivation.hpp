//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_ACTIONS_CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_HPP
#define PSCS_SEMANTICS_ACTIONS_CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_HPP

#include <list>
#include <memory>
#include <string>


// forward declarations


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

namespace PSCS
{
	class PSCSFactory;
}

//Forward Declaration for used types
namespace PSCS::Semantics::StructuredClassifiers 
{
	class CS_Link;
}

namespace PSCS::Semantics::StructuredClassifiers 
{
	class CS_Reference;
}

namespace uml 
{
	class StructuralFeature;
}

// base class includes

// enum includes

#include "ecore/EObject.hpp"

//*********************************
namespace PSCS::Semantics::Actions 
{
	/*!
	 */
	class CS_RemoveStructuralFeatureValueActionActivation : virtual public ecore::EObject 

	{
		public:
 			CS_RemoveStructuralFeatureValueActionActivation(const CS_RemoveStructuralFeatureValueActionActivation &) {}
			CS_RemoveStructuralFeatureValueActionActivation& operator=(CS_RemoveStructuralFeatureValueActionActivation const&) = delete;

		protected:
			CS_RemoveStructuralFeatureValueActionActivation(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~CS_RemoveStructuralFeatureValueActionActivation() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual void doAction() = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link> > getLinksToDestroy(Any value,std::shared_ptr<uml::StructuralFeature>  feature,Any removedValue) = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<Bag<Any> > getPotentialLinkEnds(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference>  context,std::shared_ptr<uml::StructuralFeature>  feature) = 0;
			
			
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
#endif /* end of include guard: PSCS_SEMANTICS_ACTIONS_CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_HPP */
