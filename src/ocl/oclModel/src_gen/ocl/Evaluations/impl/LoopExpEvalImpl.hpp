//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EVALUATIONS_LOOPEXPEVALLOOPEXPEVALIMPL_HPP
#define OCL_EVALUATIONS_LOOPEXPEVALLOOPEXPEVALIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../LoopExpEval.hpp"

#include "ocl/Evaluations/impl/EvaluationsFactoryImpl.hpp"
#include "ocl/Evaluations/impl/PropertyCallExpEvalImpl.hpp"

//*********************************
namespace ocl::Evaluations 
{
	class OCL_API LoopExpEvalImpl : virtual public PropertyCallExpEvalImpl, virtual public LoopExpEval 
	{
		public: 
			LoopExpEvalImpl(const LoopExpEvalImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			LoopExpEvalImpl& operator=(LoopExpEvalImpl const&); 

		protected:
			friend class ocl::Evaluations::EvaluationsFactoryImpl;
			LoopExpEvalImpl();
			virtual std::shared_ptr<ocl::Evaluations::LoopExpEval> getThisLoopExpEvalPtr() const;
			virtual void setThisLoopExpEvalPtr(std::weak_ptr<ocl::Evaluations::LoopExpEval> thisLoopExpEvalPtr);


		public:
			//destructor
			virtual ~LoopExpEvalImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<Bag<ocl::Evaluations::OclExpEval>> getBodyEvals() const ;
			virtual std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::StringValue>> getIterators() const ;
			
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
			std::weak_ptr<ocl::Evaluations::LoopExpEval> m_thisLoopExpEvalPtr;
	};
}
#endif /* end of include guard: OCL_EVALUATIONS_LOOPEXPEVALLOOPEXPEVALIMPL_HPP */
