//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_EMODELELEMENTEMODELELEMENTIMPL_HPP
#define ECORE_EMODELELEMENTEMODELELEMENTIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ecore/ecore.hpp" 

// model includes
#include "../EModelElement.hpp"

#include "ecore/impl/EObjectImpl.hpp"

//*********************************
namespace ecore 
{
	class ECORE_API EModelElementImpl : virtual public EObjectImpl, virtual public EModelElement 
	{
		public: 
			EModelElementImpl(const EModelElementImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			EModelElementImpl& operator=(EModelElementImpl const&); 

		protected:
			friend class ecoreFactoryImpl;
			EModelElementImpl();
			virtual std::shared_ptr<ecore::EModelElement> getThisEModelElementPtr() const;
			virtual void setThisEModelElementPtr(std::weak_ptr<ecore::EModelElement> thisEModelElementPtr);

			//Additional constructors for the containments back reference
			EModelElementImpl(std::weak_ptr<ecore::EObject> par_eContainer);

		public:
			//destructor
			virtual ~EModelElementImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<ecore::EAnnotation> getEAnnotation(std::string source) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<Subset<ecore::EAnnotation, ecore::EObject>>& getEAnnotations() const ;
			
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
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<EObject>> references) ;
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
			std::weak_ptr<ecore::EModelElement> m_thisEModelElementPtr;
	};
}
#endif /* end of include guard: ECORE_EMODELELEMENTEMODELELEMENTIMPL_HPP */
