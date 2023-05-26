//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_DESTROYOBJECTACTIONACTIVATION_HPP
#define FUML_SEMANTICS_ACTIONS_DESTROYOBJECTACTIONACTIVATION_HPP


#include <memory>
#include <string>
// forward declarations

class Any;

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
	class DestroyObjectAction;
	class Element;
}

// namespace macro header include
#include "fUML/fUML.hpp"

// base class includes
#include "fUML/Semantics/Actions/ActionActivation.hpp"




//*********************************
namespace fUML::Semantics::Actions 
{
	
	class FUML_API DestroyObjectActionActivation : virtual public ActionActivation
	{
		public:
 			DestroyObjectActionActivation(const DestroyObjectActionActivation &) {}

		protected:
			DestroyObjectActionActivation(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~DestroyObjectActionActivation() {}

			//*********************************
			// Operations
			//*********************************
			virtual void destroyObject(const std::shared_ptr<Any>& value, bool isDestroyLinks, bool isDestroyOwnedObjects) = 0;
			virtual void doAction() = 0;
			virtual bool objectIsComposite(const std::shared_ptr<uml::Element>& reference, const std::shared_ptr<uml::Element>& link) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<uml::DestroyObjectAction>& getDestroyObjectAction() const = 0;
			virtual void setDestroyObjectAction(const std::shared_ptr<uml::DestroyObjectAction>&) = 0;
			/*Additional Setter for 'ActionActivation::action' redefined by reference 'destroyObjectAction'*/
			virtual void setAction(const std::shared_ptr<uml::Action>&) = 0;
			/*Additional Setter for 'ActivityNodeActivation::node' redefined by reference 'destroyObjectAction'*/
			virtual void setNode(const std::shared_ptr<uml::ActivityNode>&) = 0;

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
			std::shared_ptr<uml::DestroyObjectAction> m_destroyObjectAction;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_DESTROYOBJECTACTIONACTIVATION_HPP */
