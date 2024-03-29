//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EXPRESSIONS_OCLEXPRESSIONOCLEXPRESSIONIMPL_HPP
#define OCL_EXPRESSIONS_OCLEXPRESSIONOCLEXPRESSIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../OclExpression.hpp"

#include "ocl/Expressions/impl/ExpressionsFactoryImpl.hpp"
#include "ecore/impl/ETypedElementImpl.hpp"

//*********************************
namespace ocl::Expressions 
{
	class OCL_API OclExpressionImpl : virtual public ecore::ETypedElementImpl, virtual public OclExpression 
	{
		public: 
			OclExpressionImpl(const OclExpressionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			OclExpressionImpl& operator=(OclExpressionImpl const&); 

		protected:
			friend class ocl::Expressions::ExpressionsFactoryImpl;
			OclExpressionImpl();
			virtual std::shared_ptr<ocl::Expressions::OclExpression> getThisOclExpressionPtr() const;
			virtual void setThisOclExpressionPtr(std::weak_ptr<ocl::Expressions::OclExpression> thisOclExpressionPtr);

			//Additional constructors for the containments back reference
			OclExpressionImpl(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement);
			//Additional constructors for the containments back reference
			OclExpressionImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id);
			//Additional constructors for the containments back reference
			OclExpressionImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			OclExpressionImpl(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			OclExpressionImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner);
			//Additional constructors for the containments back reference
			OclExpressionImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall);
			//Additional constructors for the containments back reference
			OclExpressionImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			OclExpressionImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression);

		public:
			//destructor
			virtual ~OclExpressionImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::weak_ptr<ocl::Expressions::CallExp> getAppliedElement() const ;
			virtual void setAppliedElement(std::weak_ptr<ocl::Expressions::CallExp>) ;
			virtual std::weak_ptr<ocl::Expressions::IfExp> getElseOwner() const ;
			virtual void setElseOwner(std::weak_ptr<ocl::Expressions::IfExp>) ;
			virtual std::weak_ptr<ocl::Expressions::CollectionRange> getFirstOwner() const ;
			virtual void setFirstOwner(std::weak_ptr<ocl::Expressions::CollectionRange>) ;
			virtual std::weak_ptr<ocl::Expressions::IfExp> getIfOwner() const ;
			virtual void setIfOwner(std::weak_ptr<ocl::Expressions::IfExp>) ;
			virtual std::weak_ptr<ocl::Expressions::Variable> getInitializedElement() const ;
			virtual void setInitializedElement(std::weak_ptr<ocl::Expressions::Variable>) ;
			virtual std::shared_ptr<ocl::Evaluations::OclExpEval> getInstance() const ;
			virtual void setInstance(std::shared_ptr<ocl::Evaluations::OclExpEval>) ;
			virtual std::weak_ptr<ocl::Expressions::CollectionRange> getLastOwner() const ;
			virtual void setLastOwner(std::weak_ptr<ocl::Expressions::CollectionRange>) ;
			virtual std::weak_ptr<ocl::Expressions::LoopExp> getLoopBodyOwner() const ;
			virtual void setLoopBodyOwner(std::weak_ptr<ocl::Expressions::LoopExp>) ;
			virtual std::weak_ptr<ocl::Expressions::OperationCallExp> getParentCall() const ;
			virtual void setParentCall(std::weak_ptr<ocl::Expressions::OperationCallExp>) ;
			virtual std::weak_ptr<ocl::Expressions::NavigationCallExp> getParentNav() const ;
			virtual void setParentNav(std::weak_ptr<ocl::Expressions::NavigationCallExp>) ;
			virtual std::weak_ptr<ocl::Expressions::IfExp> getThenOwner() const ;
			virtual void setThenOwner(std::weak_ptr<ocl::Expressions::IfExp>) ;
			virtual std::weak_ptr<ocl::Expressions::ExpressionInOcl> getTopExpression() const ;
			virtual void setTopExpression(std::weak_ptr<ocl::Expressions::ExpressionInOcl>) ;
			
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
			std::weak_ptr<ocl::Expressions::OclExpression> m_thisOclExpressionPtr;
	};
}
#endif /* end of include guard: OCL_EXPRESSIONS_OCLEXPRESSIONOCLEXPRESSIONIMPL_HPP */
