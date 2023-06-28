//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EXPRESSIONS_LETEXPLETEXPIMPL_HPP
#define OCL_EXPRESSIONS_LETEXPLETEXPIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../LetExp.hpp"

#include "ocl/Expressions/impl/ExpressionsFactoryImpl.hpp"
#include "ocl/Expressions/impl/OclExpressionImpl.hpp"

//*********************************
namespace ocl::Expressions 
{
	class OCL_API LetExpImpl : virtual public OclExpressionImpl, virtual public LetExp 
	{
		public: 
			LetExpImpl(const LetExpImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			LetExpImpl& operator=(LetExpImpl const&); 

		protected:
			friend class ocl::Expressions::ExpressionsFactoryImpl;
			LetExpImpl();
			virtual std::shared_ptr<ocl::Expressions::LetExp> getThisLetExpPtr() const;
			virtual void setThisLetExpPtr(std::weak_ptr<ocl::Expressions::LetExp> thisLetExpPtr);

			//Additional constructors for the containments back reference
			LetExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id);
			//Additional constructors for the containments back reference
			LetExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			LetExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int reference_id);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			LetExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall);
			//Additional constructors for the containments back reference
			LetExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			LetExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression);

		public:
			//destructor
			virtual ~LetExpImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<ocl::Expressions::OclExpression>& getIn() const ;
			virtual void setIn(const std::shared_ptr<ocl::Expressions::OclExpression>&) ;
			virtual const std::shared_ptr<Bag<ocl::Expressions::VarDeclarationExp>>& getVariables() const ;
			
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
			std::weak_ptr<ocl::Expressions::LetExp> m_thisLetExpPtr;
	};
}
#endif /* end of include guard: OCL_EXPRESSIONS_LETEXPLETEXPIMPL_HPP */
