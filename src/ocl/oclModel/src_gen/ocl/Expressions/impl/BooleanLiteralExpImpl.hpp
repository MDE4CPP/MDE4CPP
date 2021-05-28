//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EXPRESSIONS_BOOLEANLITERALEXPBOOLEANLITERALEXPIMPL_HPP
#define OCL_EXPRESSIONS_BOOLEANLITERALEXPBOOLEANLITERALEXPIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../BooleanLiteralExp.hpp"

#include "ocl/Expressions/impl/ExpressionsFactoryImpl.hpp"
#include "ocl/Expressions/impl/PrimitiveLiteralExpImpl.hpp"

//*********************************
namespace ocl::Expressions 
{
	class OCL_API BooleanLiteralExpImpl : virtual public PrimitiveLiteralExpImpl, virtual public BooleanLiteralExp 
	{
		public: 
			BooleanLiteralExpImpl(const BooleanLiteralExpImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			BooleanLiteralExpImpl& operator=(BooleanLiteralExpImpl const&); 

		protected:
			friend class ocl::Expressions::ExpressionsFactoryImpl;
			BooleanLiteralExpImpl();
			virtual std::shared_ptr<BooleanLiteralExp> getThisBooleanLiteralExpPtr() const;
			virtual void setThisBooleanLiteralExpPtr(std::weak_ptr<BooleanLiteralExp> thisBooleanLiteralExpPtr);

			//Additional constructors for the containments back reference
			BooleanLiteralExpImpl(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement);
			//Additional constructors for the containments back reference
			BooleanLiteralExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id);
			//Additional constructors for the containments back reference
			BooleanLiteralExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			BooleanLiteralExpImpl(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			BooleanLiteralExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner);
			//Additional constructors for the containments back reference
			BooleanLiteralExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall);
			//Additional constructors for the containments back reference
			BooleanLiteralExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			BooleanLiteralExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression);

		public:
			//destructor
			virtual ~BooleanLiteralExpImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			 
			virtual bool getBooleanSymbol() const ;
			 
			virtual void setBooleanSymbol (bool _booleanSymbol);
			
			
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
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<BooleanLiteralExp> m_thisBooleanLiteralExpPtr;
	};
}
#endif /* end of include guard: OCL_EXPRESSIONS_BOOLEANLITERALEXPBOOLEANLITERALEXPIMPL_HPP */
