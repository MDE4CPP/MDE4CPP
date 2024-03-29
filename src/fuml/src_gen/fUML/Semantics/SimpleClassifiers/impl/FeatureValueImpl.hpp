//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_SIMPLECLASSIFIERS_FEATUREVALUEFEATUREVALUEIMPL_HPP
#define FUML_SEMANTICS_SIMPLECLASSIFIERS_FEATUREVALUEFEATUREVALUEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../FeatureValue.hpp"

#include "fUML/Semantics/SimpleClassifiers/impl/SimpleClassifiersFactoryImpl.hpp"

#include "ecore/impl/EModelElementImpl.hpp"

//*********************************
namespace fUML::Semantics::SimpleClassifiers 
{
	class FUML_API FeatureValueImpl : virtual public ecore::EModelElementImpl,
virtual public FeatureValue 
	{
		public: 
			FeatureValueImpl(const FeatureValueImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			FeatureValueImpl& operator=(FeatureValueImpl const&); 

		protected:
			friend class fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactoryImpl;
			FeatureValueImpl();
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> getThisFeatureValuePtr() const;
			virtual void setThisFeatureValuePtr(std::weak_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> thisFeatureValuePtr);


		public:
			//destructor
			virtual ~FeatureValueImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> _copy() ;
			virtual bool hasEqualValues(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> other) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual int getPosition() const ;
			virtual void setPosition (int _position);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<uml::StructuralFeature> getFeature() const ;
			virtual void setFeature(std::shared_ptr<uml::StructuralFeature>) ;
			virtual std::shared_ptr<Bag<fUML::Semantics::Values::Value>> getValues() const ;
			
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
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments) ;

		private:
			std::weak_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> m_thisFeatureValuePtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_SIMPLECLASSIFIERS_FEATUREVALUEFEATUREVALUEIMPL_HPP */
