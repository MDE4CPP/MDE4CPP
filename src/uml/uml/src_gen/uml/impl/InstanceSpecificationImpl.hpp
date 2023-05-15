//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INSTANCESPECIFICATIONINSTANCESPECIFICATIONIMPL_HPP
#define UML_INSTANCESPECIFICATIONINSTANCESPECIFICATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../InstanceSpecification.hpp"

#include "uml/impl/DeployedArtifactImpl.hpp"
#include "uml/impl/DeploymentTargetImpl.hpp"
#include "uml/impl/PackageableElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API InstanceSpecificationImpl : virtual public DeployedArtifactImpl, virtual public DeploymentTargetImpl, virtual public PackageableElementImpl, virtual public InstanceSpecification 
	{
		public: 
			InstanceSpecificationImpl(const InstanceSpecificationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			InstanceSpecificationImpl& operator=(InstanceSpecificationImpl const&); 

		protected:
			friend class umlFactoryImpl;
			InstanceSpecificationImpl();
			virtual std::shared_ptr<uml::InstanceSpecification> getThisInstanceSpecificationPtr() const;
			virtual void setThisInstanceSpecificationPtr(std::weak_ptr<uml::InstanceSpecification> thisInstanceSpecificationPtr);

			//Additional constructors for the containments back reference
			InstanceSpecificationImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			InstanceSpecificationImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			InstanceSpecificationImpl(std::weak_ptr<uml::Package> par_owningPackage);
			//Additional constructors for the containments back reference
			InstanceSpecificationImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

		public:
			//destructor
			virtual ~InstanceSpecificationImpl();
			
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
			The Classifier or Classifiers of the represented instance. If multiple Classifiers are specified, the instance is classified by all of them.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Classifier>> getClassifier() const ;
			/*!
			A Slot giving the value or values of a StructuralFeature of the instance. An InstanceSpecification can have one Slot per StructuralFeature of its Classifiers, including inherited features. It is not necessary to model a Slot for every StructuralFeature, in which case the InstanceSpecification is a partial description.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Slot, uml::Element>> getSlot() const ;
			/*!
			A specification of how to compute, derive, or construct the instance.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<uml::ValueSpecification> getSpecification() const ;
			/*!
			A specification of how to compute, derive, or construct the instance.
			<p>From package UML::Classification.</p>
			*/
			
			virtual void setSpecification(std::shared_ptr<uml::ValueSpecification>) ;
			
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
			virtual bool eSet(int featureID, const std::shared_ptr<Any>& newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID,const std::shared_ptr<Bag<Any>>& arguments) ;

		private:
			std::weak_ptr<uml::InstanceSpecification> m_thisInstanceSpecificationPtr;
	};
}
#endif /* end of include guard: UML_INSTANCESPECIFICATIONINSTANCESPECIFICATIONIMPL_HPP */
