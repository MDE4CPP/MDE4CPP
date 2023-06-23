//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EXPRESSIONS_INITORDERVALUELISTEXPINITORDERVALUELISTEXPIMPL_HPP
#define OCL_EXPRESSIONS_INITORDERVALUELISTEXPINITORDERVALUELISTEXPIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../InitOrDerValueListExp.hpp"

#include "ocl/Expressions/impl/ExpressionsFactoryImpl.hpp"
#include "ocl/Expressions/impl/OclExpressionImpl.hpp"

//*********************************
namespace ocl::Expressions 
{
	class OCL_API InitOrDerValueListExpImpl : virtual public OclExpressionImpl, virtual public InitOrDerValueListExp 
	{
		public: 
			InitOrDerValueListExpImpl(const InitOrDerValueListExpImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			InitOrDerValueListExpImpl& operator=(InitOrDerValueListExpImpl const&); 

		protected:
			friend class ocl::Expressions::ExpressionsFactoryImpl;
			InitOrDerValueListExpImpl();
			virtual std::shared_ptr<ocl::Expressions::InitOrDerValueListExp> getThisInitOrDerValueListExpPtr() const;
			virtual void setThisInitOrDerValueListExpPtr(std::weak_ptr<ocl::Expressions::InitOrDerValueListExp> thisInitOrDerValueListExpPtr);

			//Additional constructors for the containments back reference
			InitOrDerValueListExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id);
			//Additional constructors for the containments back reference
			InitOrDerValueListExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			InitOrDerValueListExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int reference_id);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			InitOrDerValueListExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall);
			//Additional constructors for the containments back reference
			InitOrDerValueListExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			InitOrDerValueListExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression);

		public:
			//destructor
			virtual ~InitOrDerValueListExpImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<Bag<ocl::Expressions::InitOrDerValueExp>>& getDerExpressionList() const ;
			virtual const std::shared_ptr<Bag<ocl::Expressions::InitOrDerValueExp>>& getInitExpressionList() const ;
			
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
			std::weak_ptr<ocl::Expressions::InitOrDerValueListExp> m_thisInitOrDerValueListExpPtr;
	};
}
#endif /* end of include guard: OCL_EXPRESSIONS_INITORDERVALUELISTEXPINITORDERVALUELISTEXPIMPL_HPP */
