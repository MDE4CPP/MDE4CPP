//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ARTIFACTARTIFACTIMPL_HPP
#define UML_ARTIFACTARTIFACTIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Artifact.hpp"

#include "uml/impl/ClassifierImpl.hpp"
#include "uml/impl/DeployedArtifactImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ArtifactImpl : virtual public ClassifierImpl, virtual public DeployedArtifactImpl, virtual public Artifact 
	{
		public: 
			ArtifactImpl(const ArtifactImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ArtifactImpl& operator=(ArtifactImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ArtifactImpl();
			virtual std::shared_ptr<uml::Artifact> getThisArtifactPtr() const;
			virtual void setThisArtifactPtr(std::weak_ptr<uml::Artifact> thisArtifactPtr);

			//Additional constructors for the containments back reference
			ArtifactImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ArtifactImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			ArtifactImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id);
			//Additional constructors for the containments back reference
			ArtifactImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference

		public:
			//destructor
			virtual ~ArtifactImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			Creates a property with the specified name, type, lower bound, and upper bound as an owned attribute of this artifact.
			*/
			 
			virtual std::shared_ptr<uml::Property> createOwnedAttribute(std::string name, std::shared_ptr<uml::Type> type, int lower, int upper) ;
			/*!
			Creates an operation with the specified name, parameter names, parameter types, and return type (or null) as an owned operation of this artifact.
			*/
			 
			virtual std::shared_ptr<uml::Operation> createOwnedOperation(std::string name, std::shared_ptr<Bag<std::string>> parameterNames, std::shared_ptr<Bag<uml::Type>> parameterTypes, std::shared_ptr<uml::Type> returnType) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			A concrete name that is used to refer to the Artifact in a physical context. Example: file system name, universal resource locator.
			<p>From package UML::Deployments.</p>
			*/
			 
			virtual std::string getFileName() const ;
			/*!
			A concrete name that is used to refer to the Artifact in a physical context. Example: file system name, universal resource locator.
			<p>From package UML::Deployments.</p>
			*/
			 
			virtual void setFileName (std::string _fileName);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The set of model elements that are manifested in the Artifact. That is, these model elements are utilized in the construction (or generation) of the artifact.
			<p>From package UML::Deployments.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Manifestation, uml::Element>> getManifestation() const ;
			/*!
			The Artifacts that are defined (nested) within the Artifact. The association is a specialization of the ownedMember association from Namespace to NamedElement.
			<p>From package UML::Deployments.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Artifact, uml::NamedElement>> getNestedArtifact() const ;
			/*!
			The attributes or association ends defined for the Artifact. The association is a specialization of the ownedMember association.
			<p>From package UML::Deployments.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Property, uml::NamedElement, uml::Property>> getOwnedAttribute() const ;
			/*!
			The Operations defined for the Artifact. The association is a specialization of the ownedMember association.
			<p>From package UML::Deployments.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Operation, uml::Feature, uml::NamedElement>> getOwnedOperation() const ;
			
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
			virtual std::shared_ptr<Any> eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, std::shared_ptr<Any> newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments) ;

		private:
			std::weak_ptr<uml::Artifact> m_thisArtifactPtr;
	};
}
#endif /* end of include guard: UML_ARTIFACTARTIFACTIMPL_HPP */
