//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EVALUATIONS_ENUMLITERALEXPEVALENUMLITERALEXPEVALIMPL_HPP
#define OCL_EVALUATIONS_ENUMLITERALEXPEVALENUMLITERALEXPEVALIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../EnumLiteralExpEval.hpp"

#include "ocl/Evaluations/impl/EvaluationsFactoryImpl.hpp"
#include "ocl/Evaluations/impl/LiteralExpEvalImpl.hpp"

//*********************************
namespace ocl::Evaluations 
{
	class OCL_API EnumLiteralExpEvalImpl : virtual public LiteralExpEvalImpl, virtual public EnumLiteralExpEval 
	{
		public: 
			EnumLiteralExpEvalImpl(const EnumLiteralExpEvalImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			EnumLiteralExpEvalImpl& operator=(EnumLiteralExpEvalImpl const&); 

		protected:
			friend class ocl::Evaluations::EvaluationsFactoryImpl;
			EnumLiteralExpEvalImpl();
			virtual std::shared_ptr<ocl::Evaluations::EnumLiteralExpEval> getThisEnumLiteralExpEvalPtr() const;
			virtual void setThisEnumLiteralExpEvalPtr(std::weak_ptr<ocl::Evaluations::EnumLiteralExpEval> thisEnumLiteralExpEvalPtr);


		public:
			//destructor
			virtual ~EnumLiteralExpEvalImpl();
			
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
			std::weak_ptr<ocl::Evaluations::EnumLiteralExpEval> m_thisEnumLiteralExpEvalPtr;
	};
}
#endif /* end of include guard: OCL_EVALUATIONS_ENUMLITERALEXPEVALENUMLITERALEXPEVALIMPL_HPP */
