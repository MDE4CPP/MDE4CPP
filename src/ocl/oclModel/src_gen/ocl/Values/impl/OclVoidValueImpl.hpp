//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_VALUES_OCLVOIDVALUEOCLVOIDVALUEIMPL_HPP
#define OCL_VALUES_OCLVOIDVALUEOCLVOIDVALUEIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../OclVoidValue.hpp"

#include "ocl/Values/impl/ValuesFactoryImpl.hpp"
#include "fUML/Semantics/Values/impl/ValueImpl.hpp"

//*********************************
namespace ocl::Values 
{
	class OclVoidValueImpl : virtual public fUML::Semantics::Values::ValueImpl, virtual public OclVoidValue 
	{
		public: 
			OclVoidValueImpl(const OclVoidValueImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			OclVoidValueImpl& operator=(OclVoidValueImpl const&); 

		protected:
			friend class ocl::Values::ValuesFactoryImpl;
			OclVoidValueImpl();
			virtual std::shared_ptr<OclVoidValue> getThisOclVoidValuePtr() const;
			virtual void setThisOclVoidValuePtr(std::weak_ptr<OclVoidValue> thisOclVoidValuePtr);


		public:
			//destructor
			virtual ~OclVoidValueImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual bool equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue) ; 
			virtual std::string toString() ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			
			
			//*********************************
			// Union Getter
			//*********************************
			 
			 
			//*********************************
			// Structural Feature Getter/Setter
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
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<OclVoidValue> m_thisOclVoidValuePtr;
	};
}
#endif /* end of include guard: OCL_VALUES_OCLVOIDVALUEOCLVOIDVALUEIMPL_HPP */
