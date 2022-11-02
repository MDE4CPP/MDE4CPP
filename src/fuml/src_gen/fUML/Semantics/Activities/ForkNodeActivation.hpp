//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIES_FORKNODEACTIVATION_HPP
#define FUML_SEMANTICS_ACTIVITIES_FORKNODEACTIVATION_HPP


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
	
	class FUML_API ForkNodeActivation : virtual public ControlNodeActivation
	{
		public:
 			ForkNodeActivation(const ForkNodeActivation &) {}

		protected:
			ForkNodeActivation(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ForkNodeActivation() {}

			//*********************************
			// Operations
			//*********************************
			virtual void fire(std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incomingTokens) = 0;
			virtual void terminate() = 0;

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
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
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
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_FORKNODEACTIVATION_HPP */
