//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INTERVALINTERVALIMPL_HPP
#define UML_INTERVALINTERVALIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Interval.hpp"

#include "uml/impl/ValueSpecificationImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API IntervalImpl : virtual public ValueSpecificationImpl, virtual public Interval 
	{
		public: 
			IntervalImpl(const IntervalImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			IntervalImpl& operator=(IntervalImpl const&); 

		protected:
			friend class umlFactoryImpl;
			IntervalImpl();
			virtual std::shared_ptr<uml::Interval> getThisIntervalPtr() const;
			virtual void setThisIntervalPtr(std::weak_ptr<uml::Interval> thisIntervalPtr);

			//Additional constructors for the containments back reference
			IntervalImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			IntervalImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			IntervalImpl(std::weak_ptr<uml::Package> par_owningPackage);
			//Additional constructors for the containments back reference
			IntervalImpl(std::weak_ptr<uml::Slot> par_owningSlot);
			//Additional constructors for the containments back reference
			IntervalImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference
			IntervalImpl(std::weak_ptr<uml::ValueSpecificationAction> par_valueSpecificationAction);

		public:
			//destructor
			virtual ~IntervalImpl();
			
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
			Refers to the ValueSpecification denoting the maximum value of the range.
			<p>From package UML::Values.</p>
			*/
			
			virtual std::shared_ptr<uml::ValueSpecification> getMax() const ;
			/*!
			Refers to the ValueSpecification denoting the maximum value of the range.
			<p>From package UML::Values.</p>
			*/
			
			virtual void setMax(std::shared_ptr<uml::ValueSpecification>) ;
			/*!
			Refers to the ValueSpecification denoting the minimum value of the range.
			<p>From package UML::Values.</p>
			*/
			
			virtual std::shared_ptr<uml::ValueSpecification> getMin() const ;
			/*!
			Refers to the ValueSpecification denoting the minimum value of the range.
			<p>From package UML::Values.</p>
			*/
			
			virtual void setMin(std::shared_ptr<uml::ValueSpecification>) ;
			
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
			std::weak_ptr<uml::Interval> m_thisIntervalPtr;
	};
}
#endif /* end of include guard: UML_INTERVALINTERVALIMPL_HPP */
