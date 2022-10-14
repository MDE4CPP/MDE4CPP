//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIES_ACTIVITYFINALNODEACTIVATION_HPP
#define FUML_SEMANTICS_ACTIVITIES_ACTIVITYFINALNODEACTIVATION_HPP


#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 


//*********************************
// generated Includes

//Forward Declaration for used types 
namespace fUML::Semantics::Activities 
{
	class ActivityEdgeInstance;
	class ActivityNodeActivationGroup;
	class Token;
}
namespace uml 
{
	class ActivityNode;
}

// namespace macro header include
#include "fUML/fUML.hpp"

// base class includes
#include "fUML/Semantics/Activities/ControlNodeActivation.hpp"




//*********************************
namespace fUML::Semantics::Activities 
{
	
	class FUML_API ActivityFinalNodeActivation : virtual public ControlNodeActivation
	{
		public:
 			ActivityFinalNodeActivation(const ActivityFinalNodeActivation &) {}

		protected:
			ActivityFinalNodeActivation(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ActivityFinalNodeActivation() {}

			//*********************************
			// Operations
			//*********************************
			virtual void fire(std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incomingTokens) = 0;

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

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			//*********************************
			// Reference Members
			//*********************************
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_ACTIVITYFINALNODEACTIVATION_HPP */
