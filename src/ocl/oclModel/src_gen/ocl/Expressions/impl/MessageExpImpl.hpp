//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EXPRESSIONS_MESSAGEEXPMESSAGEEXPIMPL_HPP
#define OCL_EXPRESSIONS_MESSAGEEXPMESSAGEEXPIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../MessageExp.hpp"

#include "ocl/Expressions/impl/ExpressionsFactoryImpl.hpp"
#include "ocl/Expressions/impl/OclExpressionImpl.hpp"

//*********************************
namespace ocl::Expressions 
{
	class OCL_API MessageExpImpl : virtual public OclExpressionImpl, virtual public MessageExp 
	{
		public: 
			MessageExpImpl(const MessageExpImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			MessageExpImpl& operator=(MessageExpImpl const&); 

		protected:
			friend class ocl::Expressions::ExpressionsFactoryImpl;
			MessageExpImpl();
			virtual std::shared_ptr<MessageExp> getThisMessageExpPtr() const;
			virtual void setThisMessageExpPtr(std::weak_ptr<MessageExp> thisMessageExpPtr);

			//Additional constructors for the containments back reference
			MessageExpImpl(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement);
			//Additional constructors for the containments back reference
			MessageExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id);
			//Additional constructors for the containments back reference
			MessageExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			MessageExpImpl(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			MessageExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner);
			//Additional constructors for the containments back reference
			MessageExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall);
			//Additional constructors for the containments back reference
			MessageExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			MessageExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression);

		public:
			//destructor
			virtual ~MessageExpImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<Bag<ocl::Expressions::OclExpression>> getArgument() const ;
			
			
			virtual std::shared_ptr<uml::CallOperationAction> getCalledOperation() const ;
			
			virtual void setCalledOperation(std::shared_ptr<uml::CallOperationAction>) ;
			
			virtual std::shared_ptr<uml::SendSignalAction> getSentSignal() const ;
			
			virtual void setSentSignal(std::shared_ptr<uml::SendSignalAction>) ;
			
			virtual std::shared_ptr<ocl::Expressions::OclExpression> getTarget() const ;
			
			virtual void setTarget(std::shared_ptr<ocl::Expressions::OclExpression>) ;
			
			
			//*********************************
			// Union Getter
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
			

			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<MessageExp> m_thisMessageExpPtr;
	};
}
#endif /* end of include guard: OCL_EXPRESSIONS_MESSAGEEXPMESSAGEEXPIMPL_HPP */
