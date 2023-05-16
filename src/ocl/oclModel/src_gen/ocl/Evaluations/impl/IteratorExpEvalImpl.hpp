//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EVALUATIONS_ITERATOREXPEVALITERATOREXPEVALIMPL_HPP
#define OCL_EVALUATIONS_ITERATOREXPEVALITERATOREXPEVALIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../IteratorExpEval.hpp"

#include "ocl/Evaluations/impl/EvaluationsFactoryImpl.hpp"
#include "ocl/Evaluations/impl/LoopExpEvalImpl.hpp"

//*********************************
namespace ocl::Evaluations 
{
	class OCL_API IteratorExpEvalImpl : virtual public LoopExpEvalImpl, virtual public IteratorExpEval 
	{
		public: 
			IteratorExpEvalImpl(const IteratorExpEvalImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			IteratorExpEvalImpl& operator=(IteratorExpEvalImpl const&); 

		protected:
			friend class ocl::Evaluations::EvaluationsFactoryImpl;
			IteratorExpEvalImpl();
			virtual std::shared_ptr<ocl::Evaluations::IteratorExpEval> getThisIteratorExpEvalPtr() const;
			virtual void setThisIteratorExpEvalPtr(std::weak_ptr<ocl::Evaluations::IteratorExpEval> thisIteratorExpEvalPtr);


		public:
			//destructor
			virtual ~IteratorExpEvalImpl();
			
			//*********************************
			// Operations
			//*********************************
			
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
			virtual std::shared_ptr<Any> eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, std::shared_ptr<Any> newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments) ;

		private:
			std::weak_ptr<ocl::Evaluations::IteratorExpEval> m_thisIteratorExpEvalPtr;
	};
}
#endif /* end of include guard: OCL_EVALUATIONS_ITERATOREXPEVALITERATOREXPEVALIMPL_HPP */
