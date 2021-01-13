//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_EPACKAGEEPACKAGEIMPL_HPP
#define ECORE_EPACKAGEEPACKAGEIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../EPackage.hpp"

#include "ecore/impl/ENamedElementImpl.hpp"

//*********************************
namespace ecore 
{
	class EPackageImpl : virtual public ENamedElementImpl, virtual public EPackage 
	{
		public: 
			EPackageImpl(const EPackageImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			EPackageImpl& operator=(EPackageImpl const&) = delete;

		protected:
			friend class ecoreFactoryImpl;
			EPackageImpl();
			virtual std::shared_ptr<EPackage> getThisEPackagePtr() const;
			virtual void setThisEPackagePtr(std::weak_ptr<EPackage> thisEPackagePtr);

			//Additional constructors for the containments back reference
			EPackageImpl(std::weak_ptr<ecore::EObject > par_eContainer);


			//Additional constructors for the containments back reference
			EPackageImpl(std::weak_ptr<ecore::EPackage > par_eSuperPackage);




		public:
			//destructor
			virtual ~EPackageImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual std::shared_ptr<ecore::EClassifier> getEClassifier(std::string name) const ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			 
			virtual std::string getNsPrefix() const ;
			
			 
			virtual void setNsPrefix (std::string _nsPrefix); 
			 
			virtual std::string getNsURI() const ;
			
			 
			virtual void setNsURI (std::string _nsURI); 
			
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<Subset<ecore::EClassifier, ecore::EObject>> getEClassifiers() const ;
			
			
			
			virtual std::shared_ptr<ecore::EFactory > getEFactoryInstance() const ;
			
			
			virtual void setEFactoryInstance(std::shared_ptr<ecore::EFactory> _eFactoryInstance) ;
			
			
			virtual std::shared_ptr<Bag<ecore::EPackage>> getESubpackages() const ;
			
			
			
			virtual std::weak_ptr<ecore::EPackage > getESuperPackage() const ;
			
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			
			virtual std::shared_ptr<Union<ecore::EObject>> getEContens() const ; 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<EPackage> m_thisEPackagePtr;
	};
}
#endif /* end of include guard: ECORE_EPACKAGEEPACKAGEIMPL_HPP */
