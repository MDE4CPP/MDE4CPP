//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_EOBJECTANYEOBJECTANYIMPL_HPP
#define ECORE_EOBJECTANYEOBJECTANYIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ecore/ecore.hpp" 

// model includes
#include "../EObjectAny.hpp"

#include "ecore/impl/EObjectImpl.hpp"

//*********************************
namespace ecore 
{
	class ECORE_API EObjectAnyImpl : virtual public EObjectImpl, virtual public EObjectAny 
	{
		public: 
			EObjectAnyImpl(const EObjectAnyImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			EObjectAnyImpl& operator=(EObjectAnyImpl const&); 

		protected:
			friend class ecoreFactoryImpl;
			EObjectAnyImpl();
			virtual std::shared_ptr<ecore::EObjectAny> getThisEObjectAnyPtr() const;
			virtual void setThisEObjectAnyPtr(std::weak_ptr<ecore::EObjectAny> thisEObjectAnyPtr);

			//Additional constructors for the containments back reference
			EObjectAnyImpl(std::weak_ptr<ecore::EObject> par_eContainer);

		public:
			//destructor
			virtual ~EObjectAnyImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual const std::shared_ptr<Any>& getAny() const ;
			virtual void setAny (const std::shared_ptr<Any>& _any);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			
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
			std::weak_ptr<ecore::EObjectAny> m_thisEObjectAnyPtr;
	};
}
#endif /* end of include guard: ECORE_EOBJECTANYEOBJECTANYIMPL_HPP */
