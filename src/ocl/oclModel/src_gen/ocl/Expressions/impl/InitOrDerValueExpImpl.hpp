//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EXPRESSIONS_INITORDERVALUEEXPINITORDERVALUEEXPIMPL_HPP
#define OCL_EXPRESSIONS_INITORDERVALUEEXPINITORDERVALUEEXPIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../InitOrDerValueExp.hpp"

#include "ocl/Expressions/impl/ExpressionsFactoryImpl.hpp"
#include "ecore/impl/ETypedElementImpl.hpp"

//*********************************
namespace ocl::Expressions 
{
	class OCL_API InitOrDerValueExpImpl : virtual public ecore::ETypedElementImpl, virtual public InitOrDerValueExp 
	{
		public: 
			InitOrDerValueExpImpl(const InitOrDerValueExpImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			InitOrDerValueExpImpl& operator=(InitOrDerValueExpImpl const&); 

		protected:
			friend class ocl::Expressions::ExpressionsFactoryImpl;
			InitOrDerValueExpImpl();
			virtual std::shared_ptr<ocl::Expressions::InitOrDerValueExp> getThisInitOrDerValueExpPtr() const;
			virtual void setThisInitOrDerValueExpPtr(std::weak_ptr<ocl::Expressions::InitOrDerValueExp> thisInitOrDerValueExpPtr);


		public:
			//destructor
			virtual ~InitOrDerValueExpImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual std::string getKind() const ;
			virtual void setKind (std::string _kind);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<ocl::Expressions::OclExpression>& getBodyExpression() const ;
			virtual void setBodyExpression(const std::shared_ptr<ocl::Expressions::OclExpression>&) ;
			
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
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;

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
			std::weak_ptr<ocl::Expressions::InitOrDerValueExp> m_thisInitOrDerValueExpPtr;
	};
}
#endif /* end of include guard: OCL_EXPRESSIONS_INITORDERVALUEEXPINITORDERVALUEEXPIMPL_HPP */
