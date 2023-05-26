//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EXPRESSIONS_COLLECTIONLITERALPARTSCOLLECTIONLITERALPARTSIMPL_HPP
#define OCL_EXPRESSIONS_COLLECTIONLITERALPARTSCOLLECTIONLITERALPARTSIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../CollectionLiteralParts.hpp"

#include "ocl/Expressions/impl/ExpressionsFactoryImpl.hpp"
#include "ecore/impl/ETypedElementImpl.hpp"

//*********************************
namespace ocl::Expressions 
{
	class OCL_API CollectionLiteralPartsImpl : virtual public ecore::ETypedElementImpl, virtual public CollectionLiteralParts 
	{
		public: 
			CollectionLiteralPartsImpl(const CollectionLiteralPartsImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			CollectionLiteralPartsImpl& operator=(CollectionLiteralPartsImpl const&); 

		protected:
			friend class ocl::Expressions::ExpressionsFactoryImpl;
			CollectionLiteralPartsImpl();
			virtual std::shared_ptr<ocl::Expressions::CollectionLiteralParts> getThisCollectionLiteralPartsPtr() const;
			virtual void setThisCollectionLiteralPartsPtr(std::weak_ptr<ocl::Expressions::CollectionLiteralParts> thisCollectionLiteralPartsPtr);


		public:
			//destructor
			virtual ~CollectionLiteralPartsImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<Bag<ocl::Expressions::CollectionLiteralPart>>& getLiteralParts() const ;
			
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
			virtual std::shared_ptr<Any> eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, const std::shared_ptr<Any>& newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID,const std::shared_ptr<Bag<Any>>& arguments) ;

		private:
			std::weak_ptr<ocl::Expressions::CollectionLiteralParts> m_thisCollectionLiteralPartsPtr;
	};
}
#endif /* end of include guard: OCL_EXPRESSIONS_COLLECTIONLITERALPARTSCOLLECTIONLITERALPARTSIMPL_HPP */
