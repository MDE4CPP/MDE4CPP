//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_VALUES_UNDEFINEDVALUE_HPP
#define OCL_VALUES_UNDEFINEDVALUE_HPP


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

namespace ocl
{
	class oclFactory;
}

//Forward Declaration for used types 

// namespace macro header include
#include "ocl/ocl.hpp"

// base class includes
#include "fUML/Semantics/Values/Value.hpp"




//*********************************
namespace ocl::Values 
{
	
	class OCL_API UndefinedValue: virtual public fUML::Semantics::Values::Value
	{
		public:
 			UndefinedValue(const UndefinedValue &) {}

		protected:
			UndefinedValue(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~UndefinedValue() {}

			//*********************************
			// Operations
			//*********************************
			virtual bool equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue) = 0;
			virtual std::string toString() = 0;

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
#endif /* end of include guard: OCL_VALUES_UNDEFINEDVALUE_HPP */
