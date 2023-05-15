//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_EGENERICTYPEEGENERICTYPEIMPL_HPP
#define ECORE_EGENERICTYPEEGENERICTYPEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ecore/ecore.hpp" 

// model includes
#include "../EGenericType.hpp"


#include "ecore/impl/EModelElementImpl.hpp"

//*********************************
namespace ecore 
{
	class ECORE_API EGenericTypeImpl : virtual public ecore::EModelElementImpl,
virtual public EGenericType 
	{
		public: 
			EGenericTypeImpl(const EGenericTypeImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			EGenericTypeImpl& operator=(EGenericTypeImpl const&); 

		protected:
			friend class ecoreFactoryImpl;
			EGenericTypeImpl();
			virtual std::shared_ptr<ecore::EGenericType> getThisEGenericTypePtr() const;
			virtual void setThisEGenericTypePtr(std::weak_ptr<ecore::EGenericType> thisEGenericTypePtr);


		public:
			//destructor
			virtual ~EGenericTypeImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual bool isInstance(const std::shared_ptr<Any>& object) const ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<ecore::EClassifier> getEClassifier() const ;
			virtual void setEClassifier(std::shared_ptr<ecore::EClassifier>) ;
			virtual std::shared_ptr<ecore::EGenericType> getELowerBound() const ;
			virtual void setELowerBound(std::shared_ptr<ecore::EGenericType>) ;
			virtual std::shared_ptr<ecore::EClassifier> getERawType() const ;
			virtual void setERawType(std::shared_ptr<ecore::EClassifier>) ;
			virtual std::shared_ptr<Bag<ecore::EGenericType>> getETypeArguments() const ;
			virtual std::shared_ptr<ecore::ETypeParameter> getETypeParameter() const ;
			virtual void setETypeParameter(std::shared_ptr<ecore::ETypeParameter>) ;
			virtual std::shared_ptr<ecore::EGenericType> getEUpperBound() const ;
			virtual void setEUpperBound(std::shared_ptr<ecore::EGenericType>) ;
			
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
			std::weak_ptr<ecore::EGenericType> m_thisEGenericTypePtr;
	};
}
#endif /* end of include guard: ECORE_EGENERICTYPEEGENERICTYPEIMPL_HPP */
