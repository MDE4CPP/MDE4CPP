//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_TYPES_ANYTYPEANYTYPEIMPL_HPP
#define OCL_TYPES_ANYTYPEANYTYPEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../AnyType.hpp"

#include "ocl/Types/impl/TypesFactoryImpl.hpp"
#include "ecore/impl/EClassifierImpl.hpp"

//*********************************
namespace ocl::Types 
{
	class OCL_API AnyTypeImpl : virtual public ecore::EClassifierImpl, virtual public AnyType 
	{
		public: 
			AnyTypeImpl(const AnyTypeImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			AnyTypeImpl& operator=(AnyTypeImpl const&); 

		protected:
			friend class ocl::Types::TypesFactoryImpl;
			AnyTypeImpl();
			virtual std::shared_ptr<AnyType> getThisAnyTypePtr() const;
			virtual void setThisAnyTypePtr(std::weak_ptr<AnyType> thisAnyTypePtr);

			//Additional constructors for the containments back reference
			AnyTypeImpl(std::weak_ptr<ecore::EPackage> par_ePackage);

		public:
			//destructor
			virtual ~AnyTypeImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<ecore::EClassifier> getObject() const ;
			
			virtual void setObject(std::shared_ptr<ecore::EClassifier>) ;
			
			
			//*********************************
			// Union Getter
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
			

			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<AnyType> m_thisAnyTypePtr;
	};
}
#endif /* end of include guard: OCL_TYPES_ANYTYPEANYTYPEIMPL_HPP */
