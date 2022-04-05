//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIES_ACTIVITYEXECUTION_HPP
#define FUML_SEMANTICS_ACTIVITIES_ACTIVITYEXECUTION_HPP


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

namespace fUML
{
	class fUMLFactory;
}

//Forward Declaration for used types 
namespace fUML::Semantics::Activities 
{
	class ActivityNodeActivationGroup;
}
namespace fUML::Semantics::CommonBehavior 
{
	class ParameterValue;
}
namespace fUML::Semantics::Loci 
{
	class Locus;
}
namespace ecore 
{
	class EAnnotation;
}
namespace uml 
{
	class Activity;
	class Behavior;
	class Classifier;
	class Comment;
}

// namespace macro header include
#include "fUML/fUML.hpp"

// base class includes
#include "fUML/Semantics/CommonBehavior/Execution.hpp"




//*********************************
namespace fUML::Semantics::Activities 
{
	
	class FUML_API ActivityExecution: virtual public fUML::Semantics::CommonBehavior::Execution
	{
		public:
 			ActivityExecution(const ActivityExecution &) {}

		protected:
			ActivityExecution(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ActivityExecution() {}

			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<Any> _copy() = 0;
			virtual void execute() = 0;
			virtual std::shared_ptr<Any> new_() = 0;
			virtual void terminate() = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> getActivationGroup() const = 0;
			virtual void setActivationGroup(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup>) = 0;
			virtual std::shared_ptr<uml::Activity> getActivity() const = 0;
			virtual void setActivity(std::shared_ptr<uml::Activity>) = 0;
			/*Additional Setter for 'Execution::behavior' redefined by reference 'activity'*/
			virtual void setBehavior(std::shared_ptr<uml::Behavior>) = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;

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
			std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> m_activationGroup;
			mutable std::shared_ptr<uml::Activity> m_activity;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_ACTIVITYEXECUTION_HPP */
