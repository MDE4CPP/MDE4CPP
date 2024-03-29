//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_VALUES_CS_OPAQUEEXPRESSIONEVALUATIONCS_OPAQUEEXPRESSIONEVALUATIONIMPL_HPP
#define PSCS_SEMANTICS_VALUES_CS_OPAQUEEXPRESSIONEVALUATIONCS_OPAQUEEXPRESSIONEVALUATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "PSCS/PSCS.hpp" 

// model includes
#include "../CS_OpaqueExpressionEvaluation.hpp"

#include "PSCS/Semantics/Values/impl/ValuesFactoryImpl.hpp"
#include "fUML/Semantics/Values/impl/EvaluationImpl.hpp"

//*********************************
namespace PSCS::Semantics::Values 
{
	class PSCS_API CS_OpaqueExpressionEvaluationImpl : virtual public fUML::Semantics::Values::EvaluationImpl, virtual public CS_OpaqueExpressionEvaluation 
	{
		public: 
			CS_OpaqueExpressionEvaluationImpl(const CS_OpaqueExpressionEvaluationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			CS_OpaqueExpressionEvaluationImpl& operator=(CS_OpaqueExpressionEvaluationImpl const&); 

		protected:
			friend class PSCS::Semantics::Values::ValuesFactoryImpl;
			CS_OpaqueExpressionEvaluationImpl();
			virtual std::shared_ptr<PSCS::Semantics::Values::CS_OpaqueExpressionEvaluation> getThisCS_OpaqueExpressionEvaluationPtr() const;
			virtual void setThisCS_OpaqueExpressionEvaluationPtr(std::weak_ptr<PSCS::Semantics::Values::CS_OpaqueExpressionEvaluation> thisCS_OpaqueExpressionEvaluationPtr);


		public:
			//destructor
			virtual ~CS_OpaqueExpressionEvaluationImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<fUML::Semantics::Values::Value> evaluate() ;
			virtual std::shared_ptr<Bag<fUML::Semantics::Values::Value> > executeExpressionBehavior() ;
			
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
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments) ;

		private:
			std::weak_ptr<PSCS::Semantics::Values::CS_OpaqueExpressionEvaluation> m_thisCS_OpaqueExpressionEvaluationPtr;
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_VALUES_CS_OPAQUEEXPRESSIONEVALUATIONCS_OPAQUEEXPRESSIONEVALUATIONIMPL_HPP */
