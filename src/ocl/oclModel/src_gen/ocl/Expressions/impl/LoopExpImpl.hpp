//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EXPRESSIONS_LOOPEXPLOOPEXPIMPL_HPP
#define OCL_EXPRESSIONS_LOOPEXPLOOPEXPIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../LoopExp.hpp"

#include "ocl/Expressions/impl/ExpressionsFactoryImpl.hpp"
#include "ocl/Expressions/impl/CallExpImpl.hpp"

//*********************************
namespace ocl::Expressions 
{
	class OCL_API LoopExpImpl : virtual public CallExpImpl, virtual public LoopExp 
	{
		public: 
			LoopExpImpl(const LoopExpImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			LoopExpImpl& operator=(LoopExpImpl const&); 

		protected:
			friend class ocl::Expressions::ExpressionsFactoryImpl;
			LoopExpImpl();
			virtual std::shared_ptr<ocl::Expressions::LoopExp> getThisLoopExpPtr() const;
			virtual void setThisLoopExpPtr(std::weak_ptr<ocl::Expressions::LoopExp> thisLoopExpPtr);

			//Additional constructors for the containments back reference
			LoopExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id);
			//Additional constructors for the containments back reference
			LoopExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			LoopExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int reference_id);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			LoopExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall);
			//Additional constructors for the containments back reference
			LoopExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			LoopExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression);

		public:
			//destructor
			virtual ~LoopExpImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual bool isIsCollectionOperation() const ;
			virtual void setIsCollectionOperation (bool _isCollectionOperation);
			virtual bool isIsImplCollectIterator() const ;
			virtual void setIsImplCollectIterator (bool _isImplCollectIterator);
			virtual std::string getIterName() const ;
			virtual void setIterName (std::string _iterName);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<ocl::Expressions::OclExpression>& getBody() const ;
			virtual void setBody(const std::shared_ptr<ocl::Expressions::OclExpression>&) ;
			virtual const std::shared_ptr<Bag<ocl::Expressions::OclExpression>>& getIterator() const ;
			
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
			std::weak_ptr<ocl::Expressions::LoopExp> m_thisLoopExpPtr;
	};
}
#endif /* end of include guard: OCL_EXPRESSIONS_LOOPEXPLOOPEXPIMPL_HPP */
