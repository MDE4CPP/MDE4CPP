//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_READSTRUCTURALFEATUREACTIONACTIVATION_HPP
#define FUML_SEMANTICS_ACTIONS_READSTRUCTURALFEATUREACTIONACTIVATION_HPP


#include <memory>
#include <string>
// forward declarations


//*********************************
// generated Includes

//Forward Declaration for used types 
namespace fUML::Semantics::Actions 
{
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
namespace uml 
{
	class Action;
	class ActivityNode;
	class ReadStructuralFeatureAction;
}

// namespace macro header include
#include "fUML/fUML.hpp"

// base class includes
#include "fUML/Semantics/Actions/StructuralFeatureActionActivation.hpp"




//*********************************
namespace fUML::Semantics::Actions 
{
	
	class FUML_API ReadStructuralFeatureActionActivation : virtual public StructuralFeatureActionActivation
	{
		public:
 			ReadStructuralFeatureActionActivation(const ReadStructuralFeatureActionActivation &) {}

		protected:
			ReadStructuralFeatureActionActivation(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ReadStructuralFeatureActionActivation() {}

			//*********************************
			// Operations
			//*********************************
			virtual void doAction() = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<uml::ReadStructuralFeatureAction> getReadStructuralFeatureAction() const = 0;
			virtual void setReadStructuralFeatureAction(std::shared_ptr<uml::ReadStructuralFeatureAction>) = 0;
			/*Additional Setter for 'ActionActivation::action' redefined by reference 'readStructuralFeatureAction'*/
			virtual void setAction(std::shared_ptr<uml::Action>) = 0;
			/*Additional Setter for 'ActivityNodeActivation::node' redefined by reference 'readStructuralFeatureAction'*/
			virtual void setNode(std::shared_ptr<uml::ActivityNode>) = 0;

			//*********************************
			// Union Reference Getters
			//*********************************

			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			//*********************************
			// Reference Members
			//*********************************
			std::shared_ptr<uml::ReadStructuralFeatureAction> m_readStructuralFeatureAction;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_READSTRUCTURALFEATUREACTIONACTIVATION_HPP */
