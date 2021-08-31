//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EVALUATIONS_COLLECTIONLITERALEXPEVALCOLLECTIONLITERALEXPEVALIMPL_HPP
#define OCL_EVALUATIONS_COLLECTIONLITERALEXPEVALCOLLECTIONLITERALEXPEVALIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../CollectionLiteralExpEval.hpp"

#include "ocl/Evaluations/impl/EvaluationsFactoryImpl.hpp"
#include "ocl/Evaluations/impl/LiteralExpEvalImpl.hpp"

//*********************************
namespace ocl::Evaluations 
{
	class OCL_API CollectionLiteralExpEvalImpl : virtual public LiteralExpEvalImpl, virtual public CollectionLiteralExpEval 
	{
		public: 
			CollectionLiteralExpEvalImpl(const CollectionLiteralExpEvalImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			CollectionLiteralExpEvalImpl& operator=(CollectionLiteralExpEvalImpl const&); 

		protected:
			friend class ocl::Evaluations::EvaluationsFactoryImpl;
			CollectionLiteralExpEvalImpl();
			virtual std::shared_ptr<CollectionLiteralExpEval> getThisCollectionLiteralExpEvalPtr() const;
			virtual void setThisCollectionLiteralExpEvalPtr(std::weak_ptr<CollectionLiteralExpEval> thisCollectionLiteralExpEvalPtr);


		public:
			//destructor
			virtual ~CollectionLiteralExpEvalImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<Bag<ocl::Evaluations::CollectionLiteralPartEval>> getParts() const ;
			
			
			
			//*********************************
			// Union Getter
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
			

			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<CollectionLiteralExpEval> m_thisCollectionLiteralExpEvalPtr;
	};
}
#endif /* end of include guard: OCL_EVALUATIONS_COLLECTIONLITERALEXPEVALCOLLECTIONLITERALEXPEVALIMPL_HPP */
