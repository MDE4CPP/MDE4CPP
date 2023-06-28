//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EXPRESSIONS_INVORDEFEXPINVORDEFEXPIMPL_HPP
#define OCL_EXPRESSIONS_INVORDEFEXPINVORDEFEXPIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../InvOrDefExp.hpp"

#include "ocl/Expressions/impl/ExpressionsFactoryImpl.hpp"
#include "ecore/impl/ETypedElementImpl.hpp"

//*********************************
namespace ocl::Expressions 
{
	class OCL_API InvOrDefExpImpl : virtual public ecore::ETypedElementImpl, virtual public InvOrDefExp 
	{
		public: 
			InvOrDefExpImpl(const InvOrDefExpImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			InvOrDefExpImpl& operator=(InvOrDefExpImpl const&); 

		protected:
			friend class ocl::Expressions::ExpressionsFactoryImpl;
			InvOrDefExpImpl();
			virtual std::shared_ptr<ocl::Expressions::InvOrDefExp> getThisInvOrDefExpPtr() const;
			virtual void setThisInvOrDefExpPtr(std::weak_ptr<ocl::Expressions::InvOrDefExp> thisInvOrDefExpPtr);


		public:
			//destructor
			virtual ~InvOrDefExpImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual std::string getKind() const ;
			virtual void setKind (std::string _kind);
			virtual std::string getName() const ;
			virtual void setName (std::string _name);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<ocl::Expressions::OclExpression>& getReferredExpression() const ;
			virtual void setReferredExpression(const std::shared_ptr<ocl::Expressions::OclExpression>&) ;
			
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
			std::weak_ptr<ocl::Expressions::InvOrDefExp> m_thisInvOrDefExpPtr;
	};
}
#endif /* end of include guard: OCL_EXPRESSIONS_INVORDEFEXPINVORDEFEXPIMPL_HPP */
