//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_VALUES_UNDEFINEDVALUEUNDEFINEDVALUEIMPL_HPP
#define OCL_VALUES_UNDEFINEDVALUEUNDEFINEDVALUEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../UndefinedValue.hpp"

#include "ocl/Values/impl/ValuesFactoryImpl.hpp"
#include "fUML/Semantics/Values/impl/ValueImpl.hpp"

//*********************************
namespace ocl::Values 
{
	class OCL_API UndefinedValueImpl : virtual public fUML::Semantics::Values::ValueImpl, virtual public UndefinedValue 
	{
		public: 
			UndefinedValueImpl(const UndefinedValueImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			UndefinedValueImpl& operator=(UndefinedValueImpl const&); 

		protected:
			friend class ocl::Values::ValuesFactoryImpl;
			UndefinedValueImpl();
			virtual std::shared_ptr<ocl::Values::UndefinedValue> getThisUndefinedValuePtr() const;
			virtual void setThisUndefinedValuePtr(std::weak_ptr<ocl::Values::UndefinedValue> thisUndefinedValuePtr);


		public:
			//destructor
			virtual ~UndefinedValueImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual bool equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue) ;
			virtual std::string toString() ;
			
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
			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments) ;

		private:
			std::weak_ptr<ocl::Values::UndefinedValue> m_thisUndefinedValuePtr;
	};
}
#endif /* end of include guard: OCL_VALUES_UNDEFINEDVALUEUNDEFINEDVALUEIMPL_HPP */
