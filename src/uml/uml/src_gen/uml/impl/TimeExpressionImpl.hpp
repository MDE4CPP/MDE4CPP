//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_TIMEEXPRESSIONTIMEEXPRESSIONIMPL_HPP
#define UML_TIMEEXPRESSIONTIMEEXPRESSIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../TimeExpression.hpp"

#include "uml/impl/ValueSpecificationImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API TimeExpressionImpl : virtual public ValueSpecificationImpl, virtual public TimeExpression 
	{
		public: 
			TimeExpressionImpl(const TimeExpressionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			TimeExpressionImpl& operator=(TimeExpressionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			TimeExpressionImpl();
			virtual std::shared_ptr<uml::TimeExpression> getThisTimeExpressionPtr() const;
			virtual void setThisTimeExpressionPtr(std::weak_ptr<uml::TimeExpression> thisTimeExpressionPtr);

			//Additional constructors for the containments back reference
			TimeExpressionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			TimeExpressionImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			TimeExpressionImpl(std::weak_ptr<uml::Package> par_owningPackage);
			//Additional constructors for the containments back reference
			TimeExpressionImpl(std::weak_ptr<uml::Slot> par_owningSlot);
			//Additional constructors for the containments back reference
			TimeExpressionImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference
			TimeExpressionImpl(std::weak_ptr<uml::ValueSpecificationAction> par_valueSpecificationAction);

		public:
			//destructor
			virtual ~TimeExpressionImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			A ValueSpecification that evaluates to the value of the TimeExpression.
			<p>From package UML::Values.</p>
			*/
			
			virtual const std::shared_ptr<uml::ValueSpecification>& getExpr() const ;
			/*!
			A ValueSpecification that evaluates to the value of the TimeExpression.
			<p>From package UML::Values.</p>
			*/
			
			virtual void setExpr(const std::shared_ptr<uml::ValueSpecification>&) ;
			/*!
			Refers to the Observations that are involved in the computation of the TimeExpression value.
			<p>From package UML::Values.</p>
			*/
			
			virtual const std::shared_ptr<Bag<uml::Observation>>& getObservation() const ;
			
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
			std::weak_ptr<uml::TimeExpression> m_thisTimeExpressionPtr;
	};
}
#endif /* end of include guard: UML_TIMEEXPRESSIONTIMEEXPRESSIONIMPL_HPP */
