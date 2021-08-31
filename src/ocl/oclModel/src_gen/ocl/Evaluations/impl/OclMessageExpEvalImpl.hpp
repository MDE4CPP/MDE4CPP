//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EVALUATIONS_OCLMESSAGEEXPEVALOCLMESSAGEEXPEVALIMPL_HPP
#define OCL_EVALUATIONS_OCLMESSAGEEXPEVALOCLMESSAGEEXPEVALIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../OclMessageExpEval.hpp"

#include "ocl/Evaluations/impl/EvaluationsFactoryImpl.hpp"
#include "ocl/Evaluations/impl/OclExpEvalImpl.hpp"

//*********************************
namespace ocl::Evaluations 
{
	class OCL_API OclMessageExpEvalImpl : virtual public OclExpEvalImpl, virtual public OclMessageExpEval 
	{
		public: 
			OclMessageExpEvalImpl(const OclMessageExpEvalImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			OclMessageExpEvalImpl& operator=(OclMessageExpEvalImpl const&); 

		protected:
			friend class ocl::Evaluations::EvaluationsFactoryImpl;
			OclMessageExpEvalImpl();
			virtual std::shared_ptr<OclMessageExpEval> getThisOclMessageExpEvalPtr() const;
			virtual void setThisOclMessageExpEvalPtr(std::weak_ptr<OclMessageExpEval> thisOclMessageExpEvalPtr);


		public:
			//destructor
			virtual ~OclMessageExpEvalImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			 
			virtual std::string getName() const ;
			 
			virtual void setName (std::string _name);
			
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<Bag<ocl::Evaluations::OclMessageArgEval>> getArguments() const ;
			
			
			virtual std::shared_ptr<ocl::Evaluations::OclExpEval> getTarget() const ;
			
			virtual void setTarget(std::shared_ptr<ocl::Evaluations::OclExpEval>) ;
			
			
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
			std::weak_ptr<OclMessageExpEval> m_thisOclMessageExpEvalPtr;
	};
}
#endif /* end of include guard: OCL_EVALUATIONS_OCLMESSAGEEXPEVALOCLMESSAGEEXPEVALIMPL_HPP */
