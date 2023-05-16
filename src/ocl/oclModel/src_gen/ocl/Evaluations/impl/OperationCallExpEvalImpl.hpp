//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EVALUATIONS_OPERATIONCALLEXPEVALOPERATIONCALLEXPEVALIMPL_HPP
#define OCL_EVALUATIONS_OPERATIONCALLEXPEVALOPERATIONCALLEXPEVALIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../OperationCallExpEval.hpp"

#include "ocl/Evaluations/impl/EvaluationsFactoryImpl.hpp"
#include "ocl/Evaluations/impl/ModelPropertyCallExpEvalImpl.hpp"

//*********************************
namespace ocl::Evaluations 
{
	class OCL_API OperationCallExpEvalImpl : virtual public ModelPropertyCallExpEvalImpl, virtual public OperationCallExpEval 
	{
		public: 
			OperationCallExpEvalImpl(const OperationCallExpEvalImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			OperationCallExpEvalImpl& operator=(OperationCallExpEvalImpl const&); 

		protected:
			friend class ocl::Evaluations::EvaluationsFactoryImpl;
			OperationCallExpEvalImpl();
			virtual std::shared_ptr<ocl::Evaluations::OperationCallExpEval> getThisOperationCallExpEvalPtr() const;
			virtual void setThisOperationCallExpEvalPtr(std::weak_ptr<ocl::Evaluations::OperationCallExpEval> thisOperationCallExpEvalPtr);


		public:
			//destructor
			virtual ~OperationCallExpEvalImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual std::string getReferredOperation() const ;
			virtual void setReferredOperation (std::string _referredOperation);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<Bag<ocl::Evaluations::OclExpEval>> getArguments() const ;
			
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
			std::weak_ptr<ocl::Evaluations::OperationCallExpEval> m_thisOperationCallExpEvalPtr;
	};
}
#endif /* end of include guard: OCL_EVALUATIONS_OPERATIONCALLEXPEVALOPERATIONCALLEXPEVALIMPL_HPP */
