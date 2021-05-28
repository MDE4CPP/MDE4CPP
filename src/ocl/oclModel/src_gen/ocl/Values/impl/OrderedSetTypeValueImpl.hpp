//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_VALUES_ORDEREDSETTYPEVALUEORDEREDSETTYPEVALUEIMPL_HPP
#define OCL_VALUES_ORDEREDSETTYPEVALUEORDEREDSETTYPEVALUEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../OrderedSetTypeValue.hpp"

#include "ocl/Values/impl/ValuesFactoryImpl.hpp"
#include "ocl/Values/impl/CollectionValueImpl.hpp"

//*********************************
namespace ocl::Values 
{
	class OCL_API OrderedSetTypeValueImpl : virtual public CollectionValueImpl, virtual public OrderedSetTypeValue 
	{
		public: 
			OrderedSetTypeValueImpl(const OrderedSetTypeValueImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			OrderedSetTypeValueImpl& operator=(OrderedSetTypeValueImpl const&); 

		protected:
			friend class ocl::Values::ValuesFactoryImpl;
			OrderedSetTypeValueImpl();
			virtual std::shared_ptr<OrderedSetTypeValue> getThisOrderedSetTypeValuePtr() const;
			virtual void setThisOrderedSetTypeValuePtr(std::weak_ptr<OrderedSetTypeValue> thisOrderedSetTypeValuePtr);


		public:
			//destructor
			virtual ~OrderedSetTypeValueImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual bool addValue(std::shared_ptr<fUML::Semantics::Values::Value> value) ;
			
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
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<OrderedSetTypeValue> m_thisOrderedSetTypeValuePtr;
	};
}
#endif /* end of include guard: OCL_VALUES_ORDEREDSETTYPEVALUEORDEREDSETTYPEVALUEIMPL_HPP */
