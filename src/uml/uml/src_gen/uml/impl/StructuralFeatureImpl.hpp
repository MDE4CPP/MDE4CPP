//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_STRUCTURALFEATURESTRUCTURALFEATUREIMPL_HPP
#define UML_STRUCTURALFEATURESTRUCTURALFEATUREIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../StructuralFeature.hpp"

#include "uml/impl/FeatureImpl.hpp"
#include "uml/impl/MultiplicityElementImpl.hpp"
#include "uml/impl/TypedElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API StructuralFeatureImpl : virtual public FeatureImpl, virtual public MultiplicityElementImpl, virtual public TypedElementImpl, virtual public StructuralFeature 
	{
		public: 
			StructuralFeatureImpl(const StructuralFeatureImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			StructuralFeatureImpl& operator=(StructuralFeatureImpl const&); 

		protected:
			friend class umlFactoryImpl;
			StructuralFeatureImpl();
			virtual std::shared_ptr<uml::StructuralFeature> getThisStructuralFeaturePtr() const;
			virtual void setThisStructuralFeaturePtr(std::weak_ptr<uml::StructuralFeature> thisStructuralFeaturePtr);

			//Additional constructors for the containments back reference
			StructuralFeatureImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			StructuralFeatureImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~StructuralFeatureImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			If isReadOnly is true, the StructuralFeature may not be written to after initialization.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual bool getIsReadOnly() const ;
			/*!
			If isReadOnly is true, the StructuralFeature may not be written to after initialization.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual void setIsReadOnly (bool _isReadOnly);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			
			//*********************************
			// Union Reference Getters
			//*********************************
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
			virtual std::shared_ptr<Any> eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, std::shared_ptr<Any> newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments) ;

		private:
			std::weak_ptr<uml::StructuralFeature> m_thisStructuralFeaturePtr;
	};
}
#endif /* end of include guard: UML_STRUCTURALFEATURESTRUCTURALFEATUREIMPL_HPP */
