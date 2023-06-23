//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_EFACTORYEFACTORYIMPL_HPP
#define ECORE_EFACTORYEFACTORYIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ecore/ecore.hpp" 

// model includes
#include "../EFactory.hpp"

#include "ecore/impl/EModelElementImpl.hpp"

//*********************************
namespace ecore 
{
	class ECORE_API EFactoryImpl : virtual public EModelElementImpl, virtual public EFactory 
	{
		public: 
			EFactoryImpl(const EFactoryImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			EFactoryImpl& operator=(EFactoryImpl const&); 

		protected:
			friend class ecoreFactoryImpl;
			EFactoryImpl();
			virtual std::shared_ptr<ecore::EFactory> getThisEFactoryPtr() const;
			virtual void setThisEFactoryPtr(std::weak_ptr<ecore::EFactory> thisEFactoryPtr);

			//Additional constructors for the containments back reference
			EFactoryImpl(std::weak_ptr<ecore::EObject> par_eContainer);

		public:
			//destructor
			virtual ~EFactoryImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual std::string convertToString(const std::shared_ptr<ecore::EDataType>& eDataType, const std::shared_ptr<Any>& instanceValue) const ;
			virtual std::shared_ptr<ecore::EObject> create(const std::shared_ptr<ecore::EClass>& eClass) const ;
			virtual std::shared_ptr<Any> createFromString(const std::shared_ptr<ecore::EDataType>& eDataType, std::string literalValue) const ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<ecore::EPackage>& getEPackage() const ;
			virtual void setEPackage(const std::shared_ptr<ecore::EPackage>&) ;
			
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
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;

		protected:
			virtual const std::shared_ptr<EClass>& eStaticClass() const;

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
			std::weak_ptr<ecore::EFactory> m_thisEFactoryPtr;
	};
}
#endif /* end of include guard: ECORE_EFACTORYEFACTORYIMPL_HPP */
