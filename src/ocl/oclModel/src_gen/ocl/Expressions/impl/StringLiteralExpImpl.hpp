//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EXPRESSIONS_STRINGLITERALEXPSTRINGLITERALEXPIMPL_HPP
#define OCL_EXPRESSIONS_STRINGLITERALEXPSTRINGLITERALEXPIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../StringLiteralExp.hpp"

#include "ocl/Expressions/impl/ExpressionsFactoryImpl.hpp"
#include "ocl/Expressions/impl/PrimitiveLiteralExpImpl.hpp"

//*********************************
namespace ocl::Expressions 
{
	class OCL_API StringLiteralExpImpl : virtual public PrimitiveLiteralExpImpl, virtual public StringLiteralExp 
	{
		public: 
			StringLiteralExpImpl(const StringLiteralExpImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			StringLiteralExpImpl& operator=(StringLiteralExpImpl const&); 

		protected:
			friend class ocl::Expressions::ExpressionsFactoryImpl;
			StringLiteralExpImpl();
			virtual std::shared_ptr<ocl::Expressions::StringLiteralExp> getThisStringLiteralExpPtr() const;
			virtual void setThisStringLiteralExpPtr(std::weak_ptr<ocl::Expressions::StringLiteralExp> thisStringLiteralExpPtr);

			//Additional constructors for the containments back reference
			StringLiteralExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id);
			//Additional constructors for the containments back reference
			StringLiteralExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			StringLiteralExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int reference_id);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			StringLiteralExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall);
			//Additional constructors for the containments back reference
			StringLiteralExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			StringLiteralExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression);

		public:
			//destructor
			virtual ~StringLiteralExpImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual std::string getStringSymbol() const ;
			virtual void setStringSymbol (std::string _stringSymbol);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			
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
			virtual std::shared_ptr<Any> eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, std::shared_ptr<Any> newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments) ;

		private:
			std::weak_ptr<ocl::Expressions::StringLiteralExp> m_thisStringLiteralExpPtr;
	};
}
#endif /* end of include guard: OCL_EXPRESSIONS_STRINGLITERALEXPSTRINGLITERALEXPIMPL_HPP */
