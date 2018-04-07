//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_LITERALBOOLEANEVALUATIONLITERALBOOLEANEVALUATIONIMPL_HPP
#define FUML_LITERALBOOLEANEVALUATIONLITERALBOOLEANEVALUATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../LiteralBooleanEvaluation.hpp"

#include "fUML/impl/LiteralEvaluationImpl.hpp"

//*********************************
namespace fUML 
{
	class LiteralBooleanEvaluationImpl :virtual public LiteralEvaluationImpl, virtual public LiteralBooleanEvaluation 
	{
		public: 
			LiteralBooleanEvaluationImpl(const LiteralBooleanEvaluationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			LiteralBooleanEvaluationImpl& operator=(LiteralBooleanEvaluationImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			LiteralBooleanEvaluationImpl();
			virtual std::shared_ptr<LiteralBooleanEvaluation> getThisLiteralBooleanEvaluationPtr();
			virtual void setThisLiteralBooleanEvaluationPtr(std::weak_ptr<LiteralBooleanEvaluation> thisLiteralBooleanEvaluationPtr);



		public:
			//destructor
			virtual ~LiteralBooleanEvaluationImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Value> evaluate()  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
							
			
			//*********************************
			// Union Getter
			//*********************************
			 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual boost::any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, boost::any newValue) ;

		private:
			std::weak_ptr<LiteralBooleanEvaluation> m_thisLiteralBooleanEvaluationPtr;
	};
}
#endif /* end of include guard: FUML_LITERALBOOLEANEVALUATIONLITERALBOOLEANEVALUATIONIMPL_HPP */