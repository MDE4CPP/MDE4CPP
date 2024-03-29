//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_DEPLOYMENTSPECIFICATIONDEPLOYMENTSPECIFICATIONIMPL_HPP
#define UML_DEPLOYMENTSPECIFICATIONDEPLOYMENTSPECIFICATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../DeploymentSpecification.hpp"

#include "uml/impl/ArtifactImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API DeploymentSpecificationImpl : virtual public ArtifactImpl, virtual public DeploymentSpecification 
	{
		public: 
			DeploymentSpecificationImpl(const DeploymentSpecificationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			DeploymentSpecificationImpl& operator=(DeploymentSpecificationImpl const&); 

		protected:
			friend class umlFactoryImpl;
			DeploymentSpecificationImpl();
			virtual std::shared_ptr<uml::DeploymentSpecification> getThisDeploymentSpecificationPtr() const;
			virtual void setThisDeploymentSpecificationPtr(std::weak_ptr<uml::DeploymentSpecification> thisDeploymentSpecificationPtr);

			//Additional constructors for the containments back reference
			DeploymentSpecificationImpl(std::weak_ptr<uml::Deployment> par_deployment);
			//Additional constructors for the containments back reference
			DeploymentSpecificationImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			DeploymentSpecificationImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			DeploymentSpecificationImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id);
			//Additional constructors for the containments back reference
			DeploymentSpecificationImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference

		public:
			//destructor
			virtual ~DeploymentSpecificationImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The deployedElements of a DeploymentTarget that are involved in a Deployment that has an associated Deployment-Specification is a kind of Component (i.e., the configured components).
			deployment->forAll (location.deployedElement->forAll (oclIsKindOf(Component)))
			*/
			 
			virtual bool deployed_elements(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			The DeploymentTarget of a DeploymentSpecification is a kind of ExecutionEnvironment.
			deployment->forAll (location.oclIsKindOf(ExecutionEnvironment))
			*/
			 
			virtual bool deployment_target(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			The location where an Artifact is deployed onto a Node. This is typically a 'directory' or 'memory address.'
			<p>From package UML::Deployments.</p>
			*/
			 
			virtual std::string getDeploymentLocation() const ;
			/*!
			The location where an Artifact is deployed onto a Node. This is typically a 'directory' or 'memory address.'
			<p>From package UML::Deployments.</p>
			*/
			 
			virtual void setDeploymentLocation (std::string _deploymentLocation);
			/*!
			The location where a component Artifact executes. This may be a local or remote location.
			<p>From package UML::Deployments.</p>
			*/
			 
			virtual std::string getExecutionLocation() const ;
			/*!
			The location where a component Artifact executes. This may be a local or remote location.
			<p>From package UML::Deployments.</p>
			*/
			 
			virtual void setExecutionLocation (std::string _executionLocation);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The deployment with which the DeploymentSpecification is associated.
			<p>From package UML::Deployments.</p>
			*/
			
			virtual std::weak_ptr<uml::Deployment> getDeployment() const ;
			/*!
			The deployment with which the DeploymentSpecification is associated.
			<p>From package UML::Deployments.</p>
			*/
			
			virtual void setDeployment(std::weak_ptr<uml::Deployment>) ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			All of the Properties that are direct (i.e., not inherited or imported) attributes of the Classifier.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> getAttribute() const ;
			/*!
			Specifies each Feature directly defined in the classifier. Note that there may be members of the Classifier that are of the type Feature but are not included, e.g., inherited features.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> getFeature() const ;
			/*!
			A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::NamedElement>> getMember() const ;
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
			A collection of NamedElements owned by the Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement>> getOwnedMember() const ;
			/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ;
			/*!
			The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const ;
			
			
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
			std::weak_ptr<uml::DeploymentSpecification> m_thisDeploymentSpecificationPtr;
	};
}
#endif /* end of include guard: UML_DEPLOYMENTSPECIFICATIONDEPLOYMENTSPECIFICATIONIMPL_HPP */
