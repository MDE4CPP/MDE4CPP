//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_DURATIONDURATIONIMPL_HPP
#define UML_DURATIONDURATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Duration.hpp"

#include "uml/impl/ValueSpecificationImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API DurationImpl : virtual public ValueSpecificationImpl, virtual public Duration 
	{
		public: 
			DurationImpl(const DurationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			DurationImpl& operator=(DurationImpl const&); 

		protected:
			friend class umlFactoryImpl;
			DurationImpl();
			virtual std::shared_ptr<uml::Duration> getThisDurationPtr() const;
			virtual void setThisDurationPtr(std::weak_ptr<uml::Duration> thisDurationPtr);

			//Additional constructors for the containments back reference
			DurationImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			DurationImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			DurationImpl(std::weak_ptr<uml::Package> par_owningPackage);
			//Additional constructors for the containments back reference
			DurationImpl(std::weak_ptr<uml::Slot> par_owningSlot);
			//Additional constructors for the containments back reference
			DurationImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference
			DurationImpl(std::weak_ptr<uml::ValueSpecificationAction> par_valueSpecificationAction);

		public:
			//destructor
			virtual ~DurationImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			If a Duration has no expr, then it must have a single observation that is a DurationObservation.
			expr = null implies (observation->size() = 1 and observation->forAll(oclIsKindOf(DurationObservation)))
			*/
			 
			virtual bool no_expr_requires_observation(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			A ValueSpecification that evaluates to the value of the Duration.
			<p>From package UML::Values.</p>
			*/
			
			virtual std::shared_ptr<uml::ValueSpecification> getExpr() const ;
			/*!
			A ValueSpecification that evaluates to the value of the Duration.
			<p>From package UML::Values.</p>
			*/
			
			virtual void setExpr(std::shared_ptr<uml::ValueSpecification>) ;
			/*!
			Refers to the Observations that are involved in the computation of the Duration value
			<p>From package UML::Values.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Observation>> getObservation() const ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const ;
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;
			/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ;
			
			
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
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments) ;

		private:
			std::weak_ptr<uml::Duration> m_thisDurationPtr;
	};
}
#endif /* end of include guard: UML_DURATIONDURATIONIMPL_HPP */
