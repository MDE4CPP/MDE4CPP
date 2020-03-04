//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_CLASSIFICATION_INSTANCEVALUEEVALUATIONINSTANCEVALUEEVALUATIONIMPL_HPP
#define FUML_SEMANTICS_CLASSIFICATION_INSTANCEVALUEEVALUATIONINSTANCEVALUEEVALUATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../InstanceValueEvaluation.hpp"

#include "fUML/Semantics/Classification/Impl/ClassificationFactoryImpl.hpp"
#include "fUML/Semantics/Values/impl/EvaluationImpl.hpp"

//*********************************
namespace fUML::Semantics::Classification 
{
	class InstanceValueEvaluationImpl :virtual public fUML::Semantics::Values::EvaluationImpl, virtual public InstanceValueEvaluation 
	{
		public: 
			InstanceValueEvaluationImpl(const InstanceValueEvaluationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			InstanceValueEvaluationImpl& operator=(InstanceValueEvaluationImpl const&) = delete;

		protected:
			friend class fUML::Semantics::Classification::ClassificationFactoryImpl;
			InstanceValueEvaluationImpl();
			virtual std::shared_ptr<InstanceValueEvaluation> getThisInstanceValueEvaluationPtr() const;
			virtual void setThisInstanceValueEvaluationPtr(std::weak_ptr<InstanceValueEvaluation> thisInstanceValueEvaluationPtr);



		public:
			//destructor
			virtual ~InstanceValueEvaluationImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Semantics::Values::Value> evaluate() ;
			
			
			
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
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<InstanceValueEvaluation> m_thisInstanceValueEvaluationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_CLASSIFICATION_INSTANCEVALUEEVALUATIONINSTANCEVALUEEVALUATIONIMPL_HPP */
