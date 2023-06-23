//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EXPRESSIONS_VARIABLEVARIABLEIMPL_HPP
#define OCL_EXPRESSIONS_VARIABLEVARIABLEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../Variable.hpp"

#include "ocl/Expressions/impl/ExpressionsFactoryImpl.hpp"
#include "ecore/impl/ETypedElementImpl.hpp"

//*********************************
namespace ocl::Expressions 
{
	class OCL_API VariableImpl : virtual public ecore::ETypedElementImpl, virtual public Variable 
	{
		public: 
			VariableImpl(const VariableImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			VariableImpl& operator=(VariableImpl const&); 

		protected:
			friend class ocl::Expressions::ExpressionsFactoryImpl;
			VariableImpl();
			virtual std::shared_ptr<ocl::Expressions::Variable> getThisVariablePtr() const;
			virtual void setThisVariablePtr(std::weak_ptr<ocl::Expressions::Variable> thisVariablePtr);


		public:
			//destructor
			virtual ~VariableImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<ocl::Expressions::IterateExp>& getBaseExp() const ;
			virtual void setBaseExp(const std::shared_ptr<ocl::Expressions::IterateExp>&) ;
			virtual const std::shared_ptr<ocl::Expressions::OclExpression>& getInitExpression() const ;
			virtual void setInitExpression(const std::shared_ptr<ocl::Expressions::OclExpression>&) ;
			virtual const std::shared_ptr<ocl::Expressions::LoopExp>& getLoopExp() const ;
			virtual void setLoopExp(const std::shared_ptr<ocl::Expressions::LoopExp>&) ;
			virtual const std::shared_ptr<ocl::Expressions::VariableExp>& getReferringExp() const ;
			virtual void setReferringExp(const std::shared_ptr<ocl::Expressions::VariableExp>&) ;
			virtual const std::shared_ptr<ecore::EParameter>& getRepresentedParameter() const ;
			virtual void setRepresentedParameter(const std::shared_ptr<ecore::EParameter>&) ;
			virtual const std::shared_ptr<ocl::Expressions::ExpressionInOcl>& getResultOwner() const ;
			virtual void setResultOwner(const std::shared_ptr<ocl::Expressions::ExpressionInOcl>&) ;
			virtual const std::shared_ptr<ocl::Expressions::ExpressionInOcl>& getSelfOwner() const ;
			virtual void setSelfOwner(const std::shared_ptr<ocl::Expressions::ExpressionInOcl>&) ;
			virtual const std::shared_ptr<ecore::ETypedElement>& getValue() const ;
			virtual void setValue(const std::shared_ptr<ecore::ETypedElement>&) ;
			virtual const std::shared_ptr<ocl::Expressions::ExpressionInOcl>& getVarOwner() const ;
			virtual void setVarOwner(const std::shared_ptr<ocl::Expressions::ExpressionInOcl>&) ;
			
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
			std::weak_ptr<ocl::Expressions::Variable> m_thisVariablePtr;
	};
}
#endif /* end of include guard: OCL_EXPRESSIONS_VARIABLEVARIABLEIMPL_HPP */
