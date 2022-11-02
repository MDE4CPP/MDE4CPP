//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INTERACTIONCONSTRAINTINTERACTIONCONSTRAINTIMPL_HPP
#define UML_INTERACTIONCONSTRAINTINTERACTIONCONSTRAINTIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../InteractionConstraint.hpp"

#include "uml/impl/ConstraintImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API InteractionConstraintImpl : virtual public ConstraintImpl, virtual public InteractionConstraint 
	{
		public: 
			InteractionConstraintImpl(const InteractionConstraintImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			InteractionConstraintImpl& operator=(InteractionConstraintImpl const&); 

		protected:
			friend class umlFactoryImpl;
			InteractionConstraintImpl();
			virtual std::shared_ptr<uml::InteractionConstraint> getThisInteractionConstraintPtr() const;
			virtual void setThisInteractionConstraintPtr(std::weak_ptr<uml::InteractionConstraint> thisInteractionConstraintPtr);

			//Additional constructors for the containments back reference
			InteractionConstraintImpl(std::weak_ptr<uml::Namespace> par_Namespace, const int reference_id);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			InteractionConstraintImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			InteractionConstraintImpl(std::weak_ptr<uml::Package> par_owningPackage);
			//Additional constructors for the containments back reference
			InteractionConstraintImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

		public:
			//destructor
			virtual ~InteractionConstraintImpl();
			
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
			The maximum number of iterations of a loop
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::ValueSpecification> getMaxint() const ;
			/*!
			The maximum number of iterations of a loop
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setMaxint(std::shared_ptr<uml::ValueSpecification>) ;
			/*!
			The minimum number of iterations of a loop
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::ValueSpecification> getMinint() const ;
			/*!
			The minimum number of iterations of a loop
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setMinint(std::shared_ptr<uml::ValueSpecification>) ;
			
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
			std::weak_ptr<uml::InteractionConstraint> m_thisInteractionConstraintPtr;
	};
}
#endif /* end of include guard: UML_INTERACTIONCONSTRAINTINTERACTIONCONSTRAINTIMPL_HPP */
