//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_VALUES_OCLMESSAGEVALUE_HPP
#define OCL_VALUES_OCLMESSAGEVALUE_HPP


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
	class NameValueBinding;
	class ObjectValue;
}

// namespace macro header include
#include "ocl/ocl.hpp"

// base class includes
#include "fUML/Semantics/Values/Value.hpp"

// enum includes



//*********************************
namespace ocl::Values 
{
	
	class OCL_API OclMessageValue: virtual public fUML::Semantics::Values::Value
	{
		public:
 			OclMessageValue(const OclMessageValue &) {}

		protected:
			OclMessageValue(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~OclMessageValue() {}

			//*********************************
			// Operations
			//*********************************
			 
			virtual std::string toString() = 0;
			//*********************************
			// Attributes Getter & Setter
			//*********************************
			 
			virtual bool getIsAsyncOperation() const = 0;
			 
			virtual void setIsAsyncOperation (bool _isAsyncOperation)= 0;
			 
			virtual bool getIsSignal() const = 0;
			 
			virtual void setIsSignal (bool _isSignal)= 0;
			 
			virtual bool getIsSyncOperation() const = 0;
			 
			virtual void setIsSyncOperation (bool _isSyncOperation)= 0;
			 
			virtual std::string getName() const = 0;
			 
			virtual void setName (std::string _name)= 0;
			
			//*********************************
			// References Getter & Setter
			//*********************************
			
			virtual std::shared_ptr<Bag<ocl::Values::NameValueBinding>> getArguments() const = 0;
			
			
			virtual std::shared_ptr<ocl::Values::OclMessageValue> getReturnMessage() const = 0;
			
			virtual void setReturnMessage(std::shared_ptr<ocl::Values::OclMessageValue>) = 0;
			
			virtual std::shared_ptr<ocl::Values::ObjectValue> getSource() const = 0;
			
			virtual void setSource(std::shared_ptr<ocl::Values::ObjectValue>) = 0;
			
			virtual std::shared_ptr<ocl::Values::ObjectValue> getTarget() const = 0;
			
			virtual void setTarget(std::shared_ptr<ocl::Values::ObjectValue>) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			bool m_isAsyncOperation = false;
			
			bool m_isSignal = false;
			
			bool m_isSyncOperation = false;
			
			std::string m_name = "";
			
			
			//*********************************
			// Reference Members
			//*********************************
			
			mutable std::shared_ptr<Bag<ocl::Values::NameValueBinding>> m_arguments;
			std::shared_ptr<ocl::Values::OclMessageValue> m_returnMessage;
			std::shared_ptr<ocl::Values::ObjectValue> m_source;
			std::shared_ptr<ocl::Values::ObjectValue> m_target;

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
#endif /* end of include guard: OCL_VALUES_OCLMESSAGEVALUE_HPP */
