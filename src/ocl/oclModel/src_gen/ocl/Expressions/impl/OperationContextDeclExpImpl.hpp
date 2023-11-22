//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EXPRESSIONS_OPERATIONCONTEXTDECLEXPOPERATIONCONTEXTDECLEXPIMPL_HPP
#define OCL_EXPRESSIONS_OPERATIONCONTEXTDECLEXPOPERATIONCONTEXTDECLEXPIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../OperationContextDeclExp.hpp"

#include "ocl/Expressions/impl/ExpressionsFactoryImpl.hpp"
#include "ocl/Expressions/impl/ContextDeclarationExpImpl.hpp"

//*********************************
namespace ocl::Expressions 
{
	class OCL_API OperationContextDeclExpImpl : virtual public ContextDeclarationExpImpl, virtual public OperationContextDeclExp 
	{
		public: 
			OperationContextDeclExpImpl(const OperationContextDeclExpImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			OperationContextDeclExpImpl& operator=(OperationContextDeclExpImpl const&); 

		protected:
			friend class ocl::Expressions::ExpressionsFactoryImpl;
			OperationContextDeclExpImpl();
			virtual std::shared_ptr<ocl::Expressions::OperationContextDeclExp> getThisOperationContextDeclExpPtr() const;
			virtual void setThisOperationContextDeclExpPtr(std::weak_ptr<ocl::Expressions::OperationContextDeclExp> thisOperationContextDeclExpPtr);

			//Additional constructors for the containments back reference
			OperationContextDeclExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id);
			//Additional constructors for the containments back reference
			OperationContextDeclExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			OperationContextDeclExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int reference_id);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			OperationContextDeclExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall);
			//Additional constructors for the containments back reference
			OperationContextDeclExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			OperationContextDeclExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression);

		public:
			//destructor
			virtual ~OperationContextDeclExpImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<ocl::Expressions::OperationContextExp>& getOperationContext() const ;
			virtual void setOperationContext(const std::shared_ptr<ocl::Expressions::OperationContextExp>&) ;
			virtual const std::shared_ptr<ocl::Expressions::PrePostBodyListExp>& getPrePostBodyExpressions() const ;
			virtual void setPrePostBodyExpressions(const std::shared_ptr<ocl::Expressions::PrePostBodyListExp>&) ;
			
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
			std::weak_ptr<ocl::Expressions::OperationContextDeclExp> m_thisOperationContextDeclExpPtr;
	};
}
#endif /* end of include guard: OCL_EXPRESSIONS_OPERATIONCONTEXTDECLEXPOPERATIONCONTEXTDECLEXPIMPL_HPP */