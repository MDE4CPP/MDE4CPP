//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_ECLASSECLASSIMPL_HPP
#define ECORE_ECLASSECLASSIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ecore/ecore.hpp" 

// model includes
#include "../EClass.hpp"

#include "ecore/impl/EClassifierImpl.hpp"

//*********************************
namespace ecore 
{
	class ECORE_API EClassImpl : virtual public EClassifierImpl, virtual public EClass 
	{
		public: 
			EClassImpl(const EClassImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			EClassImpl& operator=(EClassImpl const&); 

		protected:
			friend class ecoreFactoryImpl;
			EClassImpl();
			virtual std::shared_ptr<ecore::EClass> getThisEClassPtr() const;
			virtual void setThisEClassPtr(std::weak_ptr<ecore::EClass> thisEClassPtr);

			//Additional constructors for the containments back reference
			EClassImpl(std::weak_ptr<ecore::EObject> par_eContainer);
			//Additional constructors for the containments back reference
			EClassImpl(std::weak_ptr<ecore::EPackage> par_ePackage);

		public:
			//destructor
			virtual ~EClassImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<ecore::EOperation> getEOperation(int operationID) const ;
			virtual std::shared_ptr<ecore::EStructuralFeature> getEStructuralFeature(int featureID) const ;
			virtual std::shared_ptr<ecore::EStructuralFeature> getEStructuralFeature(std::string featureName) const ;
			virtual int getFeatureCount() const ;
			virtual int getFeatureID(const std::shared_ptr<ecore::EStructuralFeature>& feature) const ;
			virtual std::shared_ptr<ecore::EGenericType> getFeatureType(const std::shared_ptr<ecore::EStructuralFeature>& feature) const ;
			virtual int getOperationCount() const ;
			virtual int getOperationID(const std::shared_ptr<ecore::EOperation>& operation) const ;
			virtual std::shared_ptr<ecore::EOperation> getOverride(const std::shared_ptr<ecore::EOperation>& operation) const ;
			virtual bool isSuperTypeOf(const std::shared_ptr<ecore::EClass>& someClass) const ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual bool isAbstract() const ;
			virtual void setAbstract (bool _abstract);
			virtual bool isInterface() const ;
			virtual void setInterface (bool _interface);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<Bag<ecore::EAttribute>> getEAllAttributes() const ;
			virtual std::shared_ptr<Bag<ecore::EReference>> getEAllContainments() const ;
			virtual std::shared_ptr<Bag<ecore::EGenericType>> getEAllGenericSuperTypes() const ;
			virtual std::shared_ptr<Bag<ecore::EOperation>> getEAllOperations() const ;
			virtual std::shared_ptr<Bag<ecore::EReference>> getEAllReferences() const ;
			virtual std::shared_ptr<Bag<ecore::EStructuralFeature>> getEAllStructuralFeatures() const ;
			virtual std::shared_ptr<Bag<ecore::EClass>> getEAllSuperTypes() const ;
			virtual std::shared_ptr<Subset<ecore::EAttribute, ecore::EStructuralFeature>> getEAttributes() const ;
			virtual std::shared_ptr<Bag<ecore::EGenericType>> getEGenericSuperTypes() const ;
			virtual std::shared_ptr<ecore::EAttribute> getEIDAttribute() const ;
			virtual void setEIDAttribute(std::shared_ptr<ecore::EAttribute>) ;
			virtual std::shared_ptr<Subset<ecore::EOperation, ecore::EObject>> getEOperations() const ;
			virtual std::shared_ptr<Subset<ecore::EReference, ecore::EStructuralFeature>> getEReferences() const ;
			
			virtual std::shared_ptr<Bag<ecore::EClass>> getESuperTypes() const ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			virtual std::shared_ptr<SubsetUnion<ecore::EStructuralFeature, ecore::EObject>> getEStructuralFeatures() const ;
			
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
			virtual bool eSet(int featureID, const std::shared_ptr<Any>& newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID,const std::shared_ptr<Bag<Any>>& arguments) ;

		private:
			std::weak_ptr<ecore::EClass> m_thisEClassPtr;
	};
}
#endif /* end of include guard: ECORE_ECLASSECLASSIMPL_HPP */
