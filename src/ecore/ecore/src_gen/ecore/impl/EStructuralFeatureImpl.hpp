//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_ESTRUCTURALFEATUREESTRUCTURALFEATUREIMPL_HPP
#define ECORE_ESTRUCTURALFEATUREESTRUCTURALFEATUREIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../EStructuralFeature.hpp"

#include "ecore/impl/ETypedElementImpl.hpp"

//*********************************
namespace ecore 
{
	class EStructuralFeatureImpl :virtual public ETypedElementImpl, virtual public EStructuralFeature 
	{
		public: 
			EStructuralFeatureImpl(const EStructuralFeatureImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			EStructuralFeatureImpl& operator=(EStructuralFeatureImpl const&) = delete;

		protected:
			friend class EcoreFactoryImpl;
			EStructuralFeatureImpl();
			virtual std::shared_ptr<EStructuralFeature> getThisEStructuralFeaturePtr() const;
			virtual void setThisEStructuralFeaturePtr(std::weak_ptr<EStructuralFeature> thisEStructuralFeaturePtr);

			//Additional constructors for the containments back reference
			EStructuralFeatureImpl(std::weak_ptr<ecore::EObject > par_eContainer);


			//Additional constructors for the containments back reference
			EStructuralFeatureImpl(std::weak_ptr<ecore::EClass > par_eContainingClass);




		public:
			//destructor
			virtual ~EStructuralFeatureImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual void * getContainerClass() ;
			
			
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 */ 
			virtual bool isChangeable() const ;
			
			/*!
			 */ 
			virtual void setChangeable (bool _changeable); 
			
			/*!
			 */ 
			virtual Any getDefaultValue() const ;
			
			/*!
			 */ 
			virtual void setDefaultValue (Any _defaultValue); 
			
			/*!
			 */ 
			virtual std::string getDefaultValueLiteral() const ;
			
			/*!
			 */ 
			virtual void setDefaultValueLiteral (std::string _defaultValueLiteral); 
			
			/*!
			 */ 
			virtual bool isDerived() const ;
			
			/*!
			 */ 
			virtual void setDerived (bool _derived); 
			
			/*!
			 */ 
			virtual int getFeatureID() const ;
			
			/*!
			 */ 
			virtual void setFeatureID (int _featureID); 
			
			/*!
			 */ 
			virtual bool isTransient() const ;
			
			/*!
			 */ 
			virtual void setTransient (bool _transient); 
			
			/*!
			 */ 
			virtual bool isUnsettable() const ;
			
			/*!
			 */ 
			virtual void setUnsettable (bool _unsettable); 
			
			/*!
			 */ 
			virtual bool isVolatile() const ;
			
			/*!
			 */ 
			virtual void setVolatile (bool _volatile); 
			
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::weak_ptr<ecore::EClass > getEContainingClass() const ;
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 */
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
			std::weak_ptr<EStructuralFeature> m_thisEStructuralFeaturePtr;
	};
}
#endif /* end of include guard: ECORE_ESTRUCTURALFEATUREESTRUCTURALFEATUREIMPL_HPP */
