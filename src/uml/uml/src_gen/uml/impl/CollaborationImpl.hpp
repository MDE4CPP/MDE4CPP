//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_COLLABORATIONCOLLABORATIONIMPL_HPP
#define UML_COLLABORATIONCOLLABORATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Collaboration.hpp"

#include "uml/impl/BehavioredClassifierImpl.hpp"
#include "uml/impl/StructuredClassifierImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API CollaborationImpl : virtual public BehavioredClassifierImpl, virtual public StructuredClassifierImpl, virtual public Collaboration 
	{
		public: 
			CollaborationImpl(const CollaborationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			CollaborationImpl& operator=(CollaborationImpl const&); 

		protected:
			friend class umlFactoryImpl;
			CollaborationImpl();
			virtual std::shared_ptr<uml::Collaboration> getThisCollaborationPtr() const;
			virtual void setThisCollaborationPtr(std::weak_ptr<uml::Collaboration> thisCollaborationPtr);

			//Additional constructors for the containments back reference
			CollaborationImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			CollaborationImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			CollaborationImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id);
			//Additional constructors for the containments back reference
			CollaborationImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference

		public:
			//destructor
			virtual ~CollaborationImpl();
			
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
			Represents the participants in the Collaboration.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::ConnectableElement, uml::ConnectableElement>>& getCollaborationRole() const ;
			
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
			std::weak_ptr<uml::Collaboration> m_thisCollaborationPtr;
	};
}
#endif /* end of include guard: UML_COLLABORATIONCOLLABORATIONIMPL_HPP */
