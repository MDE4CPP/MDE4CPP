//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_FEATUREFEATUREIMPL_HPP
#define UML_FEATUREFEATUREIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Feature.hpp"

#include "uml/impl/RedefinableElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API FeatureImpl : virtual public RedefinableElementImpl, virtual public Feature 
	{
		public: 
			FeatureImpl(const FeatureImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			FeatureImpl& operator=(FeatureImpl const&); 

		protected:
			friend class umlFactoryImpl;
			FeatureImpl();
			virtual std::shared_ptr<uml::Feature> getThisFeaturePtr() const;
			virtual void setThisFeaturePtr(std::weak_ptr<uml::Feature> thisFeaturePtr);

			//Additional constructors for the containments back reference
			FeatureImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			FeatureImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~FeatureImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Specifies whether this Feature characterizes individual instances classified by the Classifier (false) or the Classifier itself (true).
			<p>From package UML::Classification.</p>
			*/
			 
			virtual bool getIsStatic() const ;
			/*!
			Specifies whether this Feature characterizes individual instances classified by the Classifier (false) or the Classifier itself (true).
			<p>From package UML::Classification.</p>
			*/
			 
			virtual void setIsStatic (bool _isStatic);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			
			
			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			The Classifiers that have this Feature as a feature.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Classifier>> getFeaturingClassifier() const ;
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
			std::weak_ptr<uml::Feature> m_thisFeaturePtr;
	};
}
#endif /* end of include guard: UML_FEATUREFEATUREIMPL_HPP */
