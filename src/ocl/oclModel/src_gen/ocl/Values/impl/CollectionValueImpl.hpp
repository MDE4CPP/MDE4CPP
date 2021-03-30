//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_VALUES_COLLECTIONVALUECOLLECTIONVALUEIMPL_HPP
#define OCL_VALUES_COLLECTIONVALUECOLLECTIONVALUEIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../CollectionValue.hpp"

#include "ocl/Values/impl/ValuesFactoryImpl.hpp"
#include "ocl/Values/impl/StaticValueImpl.hpp"

//*********************************
namespace ocl::Values 
{
	class CollectionValueImpl : virtual public StaticValueImpl, virtual public CollectionValue 
	{
		public: 
			CollectionValueImpl(const CollectionValueImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			CollectionValueImpl& operator=(CollectionValueImpl const&); 

		protected:
			friend class ocl::Values::ValuesFactoryImpl;
			CollectionValueImpl();
			virtual std::shared_ptr<CollectionValue> getThisCollectionValuePtr() const;
			virtual void setThisCollectionValuePtr(std::weak_ptr<CollectionValue> thisCollectionValuePtr);


		public:
			//destructor
			virtual ~CollectionValueImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual bool addValue(std::shared_ptr<fUML::Semantics::Values::Value> value) ; 
			virtual bool equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue) ; 
			virtual bool find(std::shared_ptr<fUML::Semantics::Values::Value> value) ; 
			virtual std::string toString() ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<Bag<ocl::Values::Element>> getElements() const ;
			
			
			virtual std::shared_ptr<ocl::Types::CollectionType> getModel() const ;
			
			virtual void setModel(std::shared_ptr<ocl::Types::CollectionType>) ;
			
			
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
			std::weak_ptr<CollectionValue> m_thisCollectionValuePtr;
	};
}
#endif /* end of include guard: OCL_VALUES_COLLECTIONVALUECOLLECTIONVALUEIMPL_HPP */
