//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EXPRESSIONS_VARIABLEVARIABLEIMPL_HPP
#define OCL_EXPRESSIONS_VARIABLEVARIABLEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../Variable.hpp"

#include "ocl/Expressions/impl/ExpressionsFactoryImpl.hpp"
#include "ecore/impl/ETypedElementImpl.hpp"

//*********************************
namespace ocl::Expressions 
{
	class OCL_API VariableImpl : virtual public ecore::ETypedElementImpl, virtual public Variable 
	{
		public: 
			VariableImpl(const VariableImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			VariableImpl& operator=(VariableImpl const&); 

		protected:
			friend class ocl::Expressions::ExpressionsFactoryImpl;
			VariableImpl();
			virtual std::shared_ptr<ocl::Expressions::Variable> getThisVariablePtr() const;
			virtual void setThisVariablePtr(std::weak_ptr<ocl::Expressions::Variable> thisVariablePtr);

			//Additional constructors for the containments back reference
			VariableImpl(std::weak_ptr<ocl::Expressions::IterateExp> par_baseExp);
			//Additional constructors for the containments back reference
			VariableImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_loopExp);
			//Additional constructors for the containments back reference
			VariableImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int reference_id);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference

		public:
			//destructor
			virtual ~VariableImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::weak_ptr<ocl::Expressions::IterateExp> getBaseExp() const ;
			virtual void setBaseExp(std::weak_ptr<ocl::Expressions::IterateExp>) ;
			virtual std::shared_ptr<ocl::Expressions::OclExpression> getInitExpression() const ;
			virtual void setInitExpression(std::shared_ptr<ocl::Expressions::OclExpression>) ;
			virtual std::weak_ptr<ocl::Expressions::LoopExp> getLoopExp() const ;
			virtual void setLoopExp(std::weak_ptr<ocl::Expressions::LoopExp>) ;
			virtual std::shared_ptr<ocl::Expressions::VariableExp> getReferringExp() const ;
			virtual void setReferringExp(std::shared_ptr<ocl::Expressions::VariableExp>) ;
			virtual std::shared_ptr<ecore::EParameter> getRepresentedParameter() const ;
			virtual void setRepresentedParameter(std::shared_ptr<ecore::EParameter>) ;
			virtual std::weak_ptr<ocl::Expressions::ExpressionInOcl> getResultOwner() const ;
			virtual void setResultOwner(std::weak_ptr<ocl::Expressions::ExpressionInOcl>) ;
			virtual std::weak_ptr<ocl::Expressions::ExpressionInOcl> getSelfOwner() const ;
			virtual void setSelfOwner(std::weak_ptr<ocl::Expressions::ExpressionInOcl>) ;
			virtual std::shared_ptr<fUML::Semantics::Values::Value> getValue() const ;
			virtual void setValue(std::shared_ptr<fUML::Semantics::Values::Value>) ;
			virtual std::weak_ptr<ocl::Expressions::ExpressionInOcl> getVarOwner() const ;
			virtual void setVarOwner(std::weak_ptr<ocl::Expressions::ExpressionInOcl>) ;
			
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
			std::weak_ptr<ocl::Expressions::Variable> m_thisVariablePtr;
	};
}
#endif /* end of include guard: OCL_EXPRESSIONS_VARIABLEVARIABLEIMPL_HPP */
