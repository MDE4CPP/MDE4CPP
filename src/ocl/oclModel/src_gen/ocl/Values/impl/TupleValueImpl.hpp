//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_VALUES_TUPLEVALUETUPLEVALUEIMPL_HPP
#define OCL_VALUES_TUPLEVALUETUPLEVALUEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../TupleValue.hpp"

#include "ocl/Values/impl/ValuesFactoryImpl.hpp"
#include "ocl/Values/impl/StaticValueImpl.hpp"

//*********************************
namespace ocl::Values 
{
	class OCL_API TupleValueImpl : virtual public StaticValueImpl, virtual public TupleValue 
	{
		public: 
			TupleValueImpl(const TupleValueImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			TupleValueImpl& operator=(TupleValueImpl const&); 

		protected:
			friend class ocl::Values::ValuesFactoryImpl;
			TupleValueImpl();
			virtual std::shared_ptr<TupleValue> getThisTupleValuePtr() const;
			virtual void setThisTupleValuePtr(std::weak_ptr<TupleValue> thisTupleValuePtr);


		public:
			//destructor
			virtual ~TupleValueImpl();
			
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
			
			virtual std::shared_ptr<Bag<ocl::Values::NameValueBinding>> getElements() const ;
			
			
			virtual std::shared_ptr<ocl::Types::TupleType> getModel() const ;
			
			virtual void setModel(std::shared_ptr<ocl::Types::TupleType>) ;
			
			
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
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<TupleValue> m_thisTupleValuePtr;
	};
}
#endif /* end of include guard: OCL_VALUES_TUPLEVALUETUPLEVALUEIMPL_HPP */
