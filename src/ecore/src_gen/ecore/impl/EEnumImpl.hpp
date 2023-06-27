//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_EENUMEENUMIMPL_HPP
#define ECORE_EENUMEENUMIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ecore/ecore.hpp" 

// model includes
#include "../EEnum.hpp"

#include "ecore/impl/EDataTypeImpl.hpp"

//*********************************
namespace ecore 
{
	class ECORE_API EEnumImpl : virtual public EDataTypeImpl, virtual public EEnum 
	{
		public: 
			EEnumImpl(const EEnumImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			EEnumImpl& operator=(EEnumImpl const&); 

		protected:
			friend class ecoreFactoryImpl;
			EEnumImpl();
			virtual std::shared_ptr<ecore::EEnum> getThisEEnumPtr() const;
			virtual void setThisEEnumPtr(std::weak_ptr<ecore::EEnum> thisEEnumPtr);

			//Additional constructors for the containments back reference
			EEnumImpl(std::weak_ptr<ecore::EObject> par_eContainer);
			//Additional constructors for the containments back reference
			EEnumImpl(std::weak_ptr<ecore::EPackage> par_ePackage);

		public:
			//destructor
			virtual ~EEnumImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<ecore::EEnumLiteral> getEEnumLiteral(std::string name) const ;
			virtual std::shared_ptr<ecore::EEnumLiteral> getEEnumLiteral(int value) const ;
			virtual std::shared_ptr<ecore::EEnumLiteral> getEEnumLiteralByLiteral(std::string literal) const ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<Subset<ecore::EEnumLiteral, ecore::EObject>>& getELiterals() const ;
			
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
			std::weak_ptr<ecore::EEnum> m_thisEEnumPtr;
	};
}
#endif /* end of include guard: ECORE_EENUMEENUMIMPL_HPP */
