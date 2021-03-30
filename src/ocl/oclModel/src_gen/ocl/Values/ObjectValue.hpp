//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_VALUES_OBJECTVALUE_HPP
#define OCL_VALUES_OBJECTVALUE_HPP


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

namespace ocl
{
	class oclFactory;
}

//Forward Declaration for used types 
namespace ocl::Values 
{
	class LocalSnapshot;
}
namespace ecore 
{
	class EObject;
}

// base class includes
#include "fUML/Semantics/Values/Value.hpp"

// enum includes



//*********************************
namespace ocl::Values 
{
	
	class ObjectValue: virtual public fUML::Semantics::Values::Value
	{
		public:
 			ObjectValue(const ObjectValue &) {}

		protected:
			ObjectValue(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ObjectValue() {}

			//*********************************
			// Operations
			//*********************************
			 
			virtual bool equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue) = 0; 
			virtual std::string toString() = 0;
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<Bag<ocl::Values::LocalSnapshot>> getHistory() const = 0;
			
			
			virtual std::shared_ptr<ecore::EObject> getValue() const = 0;
			
			virtual void setValue(std::shared_ptr<ecore::EObject>) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			
			mutable std::shared_ptr<Bag<ocl::Values::LocalSnapshot>> m_history;
			std::shared_ptr<ecore::EObject> m_value;

		public:
			//*********************************
			// Union Getter
			//*********************************
			

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: OCL_VALUES_OBJECTVALUE_HPP */
