//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_COMPONENTREALIZATIONCOMPONENTREALIZATIONIMPL_HPP
#define UML_COMPONENTREALIZATIONCOMPONENTREALIZATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../ComponentRealization.hpp"

#include "uml/impl/RealizationImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ComponentRealizationImpl : virtual public RealizationImpl, virtual public ComponentRealization 
	{
		public: 
			ComponentRealizationImpl(const ComponentRealizationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ComponentRealizationImpl& operator=(ComponentRealizationImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ComponentRealizationImpl();
			virtual std::shared_ptr<uml::ComponentRealization> getThisComponentRealizationPtr() const;
			virtual void setThisComponentRealizationPtr(std::weak_ptr<uml::ComponentRealization> thisComponentRealizationPtr);

			//Additional constructors for the containments back reference
			ComponentRealizationImpl(std::weak_ptr<uml::Component> par_abstraction);
			//Additional constructors for the containments back reference
			ComponentRealizationImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ComponentRealizationImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			ComponentRealizationImpl(std::weak_ptr<uml::Package> par_owningPackage);
			//Additional constructors for the containments back reference
			ComponentRealizationImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

		public:
			//destructor
			virtual ~ComponentRealizationImpl();
			
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
			The Component that owns this ComponentRealization and which is implemented by its realizing Classifiers.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::weak_ptr<uml::Component> getAbstraction() const ;
			/*!
			The Component that owns this ComponentRealization and which is implemented by its realizing Classifiers.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual void setAbstraction(std::weak_ptr<uml::Component>) ;
			/*!
			The Classifiers that are involved in the implementation of the Component that owns this Realization.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Classifier, uml::NamedElement /*Subset does not reference a union*/>> getRealizingClassifier() const ;
			
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
			std::weak_ptr<uml::ComponentRealization> m_thisComponentRealizationPtr;
	};
}
#endif /* end of include guard: UML_COMPONENTREALIZATIONCOMPONENTREALIZATIONIMPL_HPP */
