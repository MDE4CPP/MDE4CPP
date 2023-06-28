//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EVALUATIONS_OCLEXPEVALOCLEXPEVALIMPL_HPP
#define OCL_EVALUATIONS_OCLEXPEVALOCLEXPEVALIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../OclExpEval.hpp"

#include "ocl/Evaluations/impl/EvaluationsFactoryImpl.hpp"
#include "ecore/impl/ETypedElementImpl.hpp"

//*********************************
namespace ocl::Evaluations 
{
	class OCL_API OclExpEvalImpl : virtual public ecore::ETypedElementImpl, virtual public OclExpEval 
	{
		public: 
			OclExpEvalImpl(const OclExpEvalImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			OclExpEvalImpl& operator=(OclExpEvalImpl const&); 

		protected:
			friend class ocl::Evaluations::EvaluationsFactoryImpl;
			OclExpEvalImpl();
			virtual std::shared_ptr<ocl::Evaluations::OclExpEval> getThisOclExpEvalPtr() const;
			virtual void setThisOclExpEvalPtr(std::weak_ptr<ocl::Evaluations::OclExpEval> thisOclExpEvalPtr);


		public:
			//destructor
			virtual ~OclExpEvalImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<ocl::Evaluations::EvalEnvironment>& getBeforeEnvironment() const ;
			virtual void setBeforeEnvironment(const std::shared_ptr<ocl::Evaluations::EvalEnvironment>&) ;
			virtual const std::shared_ptr<ocl::Evaluations::EvalEnvironment>& getEnvironment() const ;
			virtual void setEnvironment(const std::shared_ptr<ocl::Evaluations::EvalEnvironment>&) ;
			virtual const std::shared_ptr<ocl::Expressions::OclExpression>& getModel() const ;
			virtual void setModel(const std::shared_ptr<ocl::Expressions::OclExpression>&) ;
			virtual const std::shared_ptr<ecore::EObject>& getResultValue() const ;
			virtual void setResultValue(const std::shared_ptr<ecore::EObject>&) ;
			
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
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;

		protected:
			virtual const std::shared_ptr<ecore::EClass>& eStaticClass() const;

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
			std::weak_ptr<ocl::Evaluations::OclExpEval> m_thisOclExpEvalPtr;
	};
}
#endif /* end of include guard: OCL_EVALUATIONS_OCLEXPEVALOCLEXPEVALIMPL_HPP */
