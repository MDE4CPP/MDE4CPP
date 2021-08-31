//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_EREFERENCEEREFERENCEIMPL_HPP
#define ECORE_EREFERENCEEREFERENCEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ecore/ecore.hpp" 

// model includes
#include "../EReference.hpp"

#include "ecore/impl/EStructuralFeatureImpl.hpp"

//*********************************
namespace ecore 
{
	class ECORE_API EReferenceImpl : virtual public EStructuralFeatureImpl, virtual public EReference 
	{
		public: 
			EReferenceImpl(const EReferenceImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			EReferenceImpl& operator=(EReferenceImpl const&); 

		protected:
			friend class ecoreFactoryImpl;
			EReferenceImpl();
			virtual std::shared_ptr<EReference> getThisEReferencePtr() const;
			virtual void setThisEReferencePtr(std::weak_ptr<EReference> thisEReferencePtr);

			//Additional constructors for the containments back reference
			EReferenceImpl(std::weak_ptr<ecore::EObject> par_eContainer);
			//Additional constructors for the containments back reference
			EReferenceImpl(std::weak_ptr<ecore::EClass> par_eContainingClass);

		public:
			//destructor
			virtual ~EReferenceImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			 
			virtual bool isContainer() const ;
			
			 
			virtual bool isContainment() const ;
			 
			virtual void setContainment (bool _containment);
			 
			virtual bool isResolveProxies() const ;
			 
			virtual void setResolveProxies (bool _resolveProxies);
			
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<Bag<ecore::EAttribute>> getEKeys() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getEOpposite() const ;
			
			virtual void setEOpposite(std::shared_ptr<ecore::EReference>) ;
			
			virtual std::shared_ptr<ecore::EClass> getEReferenceType() const ;
			
			virtual void setEReferenceType(std::shared_ptr<ecore::EClass>) ;
			
			
			//*********************************
			// Union Getter
			//*********************************
			
			virtual std::shared_ptr<Union<ecore::EObject>> getEContens() const ;
			

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
			

			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
		protected:
			virtual std::shared_ptr<EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<EReference> m_thisEReferencePtr;
	};
}
#endif /* end of include guard: ECORE_EREFERENCEEREFERENCEIMPL_HPP */
