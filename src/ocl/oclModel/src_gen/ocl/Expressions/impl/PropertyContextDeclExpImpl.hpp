//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EXPRESSIONS_PROPERTYCONTEXTDECLEXPPROPERTYCONTEXTDECLEXPIMPL_HPP
#define OCL_EXPRESSIONS_PROPERTYCONTEXTDECLEXPPROPERTYCONTEXTDECLEXPIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../PropertyContextDeclExp.hpp"

#include "ocl/Expressions/impl/ExpressionsFactoryImpl.hpp"
#include "ocl/Expressions/impl/ContextDeclarationExpImpl.hpp"

//*********************************
namespace ocl::Expressions 
{
	class OCL_API PropertyContextDeclExpImpl : virtual public ContextDeclarationExpImpl, virtual public PropertyContextDeclExp 
	{
		public: 
			PropertyContextDeclExpImpl(const PropertyContextDeclExpImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			PropertyContextDeclExpImpl& operator=(PropertyContextDeclExpImpl const&); 

		protected:
			friend class ocl::Expressions::ExpressionsFactoryImpl;
			PropertyContextDeclExpImpl();
			virtual std::shared_ptr<ocl::Expressions::PropertyContextDeclExp> getThisPropertyContextDeclExpPtr() const;
			virtual void setThisPropertyContextDeclExpPtr(std::weak_ptr<ocl::Expressions::PropertyContextDeclExp> thisPropertyContextDeclExpPtr);

			//Additional constructors for the containments back reference
			PropertyContextDeclExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id);
			//Additional constructors for the containments back reference
			PropertyContextDeclExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			PropertyContextDeclExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int reference_id);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			PropertyContextDeclExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall);
			//Additional constructors for the containments back reference
			PropertyContextDeclExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			PropertyContextDeclExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression);

		public:
			//destructor
			virtual ~PropertyContextDeclExpImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual std::string getPropName() const ;
			virtual void setPropName (std::string _propName);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<ocl::Expressions::InitOrDerValueListExp> getInitOrDerValues() const ;
			virtual void setInitOrDerValues(std::shared_ptr<ocl::Expressions::InitOrDerValueListExp>) ;
			virtual std::shared_ptr<ocl::Expressions::TypeExp> getPropType() const ;
			virtual void setPropType(std::shared_ptr<ocl::Expressions::TypeExp>) ;
			
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
			std::weak_ptr<ocl::Expressions::PropertyContextDeclExp> m_thisPropertyContextDeclExpPtr;
	};
}
#endif /* end of include guard: OCL_EXPRESSIONS_PROPERTYCONTEXTDECLEXPPROPERTYCONTEXTDECLEXPIMPL_HPP */