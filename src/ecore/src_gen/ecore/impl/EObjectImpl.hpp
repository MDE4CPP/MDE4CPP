//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_EOBJECTEOBJECTIMPL_HPP
#define ECORE_EOBJECTEOBJECTIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ecore/ecore.hpp" 

// model includes
#include "../EObject.hpp"



//*********************************
namespace ecore 
{
	class ECORE_API EObjectImpl : 
virtual public EObject 
	{
		public: 
			EObjectImpl(const EObjectImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			EObjectImpl& operator=(EObjectImpl const&); 

		protected:
			friend class ecoreFactoryImpl;
			EObjectImpl();
			virtual std::shared_ptr<ecore::EObject> getThisEObjectPtr() const;
			virtual void setThisEObjectPtr(std::weak_ptr<ecore::EObject> thisEObjectPtr);

			//Additional constructors for the containments back reference
			EObjectImpl(std::weak_ptr<ecore::EObject> par_eContainer);

		public:
			//destructor
			virtual ~EObjectImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<Any> eAllContents() const ;
			virtual std::shared_ptr<ecore::EClass> eClass() const ;
			virtual std::shared_ptr<ecore::EObject> eContainer() ;
			virtual std::shared_ptr<ecore::EStructuralFeature> eContainingFeature() const ;
			virtual std::shared_ptr<ecore::EReference> eContainmentFeature() const ;
			virtual std::shared_ptr<Bag<ecore::EObject>> eContents() const ;
			virtual std::shared_ptr<std::list < std::shared_ptr<ecore::EObject>>> eCrossReferences() const ;
			virtual std::shared_ptr<Any> eGet(std::shared_ptr<ecore::EStructuralFeature> feature) const ;
			virtual std::shared_ptr<Any> eGet(std::shared_ptr<ecore::EStructuralFeature> feature, bool resolve) const ;
			virtual std::shared_ptr<Any> eInvoke(std::shared_ptr<ecore::EOperation> operation, std::shared_ptr<Bag<Any>> arguments) ;
			virtual bool eIsProxy() const ;
			virtual bool eIsSet(std::shared_ptr<ecore::EStructuralFeature> feature) const ;
			virtual int eResource() const ;
			virtual void eSet(std::shared_ptr<ecore::EStructuralFeature> feature, std::shared_ptr<Any> newValue) ;
			virtual void eUnset(std::shared_ptr<ecore::EStructuralFeature> feature) const ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual long long getMetaElementID() const ;
			virtual void setMetaElementID (long long _metaElementID);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual void setEContainer(std::weak_ptr<ecore::EObject>) ;
			
			
			//*********************************
			// Union Reference Getters
			//*********************************
			virtual std::shared_ptr<Union<ecore::EObject>> getEContentUnion() const ;
			
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
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;

		protected:
			virtual std::shared_ptr<EClass> eStaticClass() const;

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
			std::weak_ptr<ecore::EObject> m_thisEObjectPtr;
	};
}
#endif /* end of include guard: ECORE_EOBJECTEOBJECTIMPL_HPP */