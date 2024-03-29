//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_TYPES_COLLECTIONTYPECOLLECTIONTYPEIMPL_HPP
#define OCL_TYPES_COLLECTIONTYPECOLLECTIONTYPEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../CollectionType.hpp"

#include "ocl/Types/impl/TypesFactoryImpl.hpp"
#include "ecore/impl/EDataTypeImpl.hpp"

//*********************************
namespace ocl::Types 
{
	class OCL_API CollectionTypeImpl : virtual public ecore::EDataTypeImpl, virtual public CollectionType 
	{
		public: 
			CollectionTypeImpl(const CollectionTypeImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			CollectionTypeImpl& operator=(CollectionTypeImpl const&); 

		protected:
			friend class ocl::Types::TypesFactoryImpl;
			CollectionTypeImpl();
			virtual std::shared_ptr<ocl::Types::CollectionType> getThisCollectionTypePtr() const;
			virtual void setThisCollectionTypePtr(std::weak_ptr<ocl::Types::CollectionType> thisCollectionTypePtr);

			//Additional constructors for the containments back reference
			CollectionTypeImpl(std::weak_ptr<ecore::EPackage> par_ePackage);

		public:
			//destructor
			virtual ~CollectionTypeImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual bool kindOf(std::shared_ptr<ocl::Types::CollectionType> coll) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<ecore::EClassifier> getElementType() const ;
			virtual void setElementType(std::shared_ptr<ecore::EClassifier>) ;
			virtual std::shared_ptr<ocl::Values::CollectionValue> getInstance() const ;
			virtual void setInstance(std::shared_ptr<ocl::Values::CollectionValue>) ;
			
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
			std::weak_ptr<ocl::Types::CollectionType> m_thisCollectionTypePtr;
	};
}
#endif /* end of include guard: OCL_TYPES_COLLECTIONTYPECOLLECTIONTYPEIMPL_HPP */
