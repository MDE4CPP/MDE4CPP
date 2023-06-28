//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EVALUATIONS_REALLITERALEXPEVALREALLITERALEXPEVALIMPL_HPP
#define OCL_EVALUATIONS_REALLITERALEXPEVALREALLITERALEXPEVALIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../RealLiteralExpEval.hpp"

#include "ocl/Evaluations/impl/EvaluationsFactoryImpl.hpp"
#include "ocl/Evaluations/impl/NumericLiteralExpEvalImpl.hpp"

//*********************************
namespace ocl::Evaluations 
{
	class OCL_API RealLiteralExpEvalImpl : virtual public NumericLiteralExpEvalImpl, virtual public RealLiteralExpEval 
	{
		public: 
			RealLiteralExpEvalImpl(const RealLiteralExpEvalImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			RealLiteralExpEvalImpl& operator=(RealLiteralExpEvalImpl const&); 

		protected:
			friend class ocl::Evaluations::EvaluationsFactoryImpl;
			RealLiteralExpEvalImpl();
			virtual std::shared_ptr<ocl::Evaluations::RealLiteralExpEval> getThisRealLiteralExpEvalPtr() const;
			virtual void setThisRealLiteralExpEvalPtr(std::weak_ptr<ocl::Evaluations::RealLiteralExpEval> thisRealLiteralExpEvalPtr);


		public:
			//destructor
			virtual ~RealLiteralExpEvalImpl();
			
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
			std::weak_ptr<ocl::Evaluations::RealLiteralExpEval> m_thisRealLiteralExpEvalPtr;
	};
}
#endif /* end of include guard: OCL_EVALUATIONS_REALLITERALEXPEVALREALLITERALEXPEVALIMPL_HPP */
