//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_EPARAMETEREPARAMETERIMPL_HPP
#define ECORE_EPARAMETEREPARAMETERIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ecore/ecore.hpp" 

// model includes
#include "../EParameter.hpp"

#include "ecore/impl/ETypedElementImpl.hpp"

//*********************************
namespace ecore 
{
	class ECORE_API EParameterImpl : virtual public ETypedElementImpl, virtual public EParameter 
	{
		public: 
			EParameterImpl(const EParameterImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			EParameterImpl& operator=(EParameterImpl const&); 

		protected:
			friend class ecoreFactoryImpl;
			EParameterImpl();
			virtual std::shared_ptr<ecore::EParameter> getThisEParameterPtr() const;
			virtual void setThisEParameterPtr(std::weak_ptr<ecore::EParameter> thisEParameterPtr);

			//Additional constructors for the containments back reference
			EParameterImpl(std::weak_ptr<ecore::EObject> par_eContainer);
			//Additional constructors for the containments back reference
			EParameterImpl(std::weak_ptr<ecore::EOperation> par_eOperation);

		public:
			//destructor
			virtual ~EParameterImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::weak_ptr<ecore::EOperation> getEOperation() const ;
			
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
			virtual bool eSet(int featureID, std::shared_ptr<Any> newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments) ;

		private:
			std::weak_ptr<ecore::EParameter> m_thisEParameterPtr;
	};
}
#endif /* end of include guard: ECORE_EPARAMETEREPARAMETERIMPL_HPP */
