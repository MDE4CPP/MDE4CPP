//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_FEATUREVALUEFEATUREVALUEIMPL_HPP
#define FUML_FEATUREVALUEFEATUREVALUEIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../FeatureValue.hpp"


#include "ecore/impl/EObjectImpl.hpp"

//*********************************
namespace fUML 
{
	class FeatureValueImpl :virtual public ecore::EObjectImpl,
virtual public FeatureValue 
	{
		public: 
			FeatureValueImpl(const FeatureValueImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			FeatureValueImpl& operator=(FeatureValueImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			FeatureValueImpl();
			virtual std::shared_ptr<FeatureValue> getThisFeatureValuePtr();
			virtual void setThisFeatureValuePtr(std::weak_ptr<FeatureValue> thisFeatureValuePtr);



		public:
			//destructor
			virtual ~FeatureValueImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual bool hasEqualValues(std::shared_ptr<fUML::FeatureValue>  other)  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 */ 
			virtual int getPosition() const ;
			
			/*!
			 */ 
			virtual void setPosition (int _position); 
			
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<uml::StructuralFeature > getFeature() const ;
			
			/*!
			 */
			virtual void setFeature(std::shared_ptr<uml::StructuralFeature> _feature_feature) ;
			/*!
			 */
			virtual std::shared_ptr<Bag<fUML::Value>> getValues() const ;
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual boost::any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, boost::any newValue) ;

		private:
			std::weak_ptr<FeatureValue> m_thisFeatureValuePtr;
	};
}
#endif /* end of include guard: FUML_FEATUREVALUEFEATUREVALUEIMPL_HPP */