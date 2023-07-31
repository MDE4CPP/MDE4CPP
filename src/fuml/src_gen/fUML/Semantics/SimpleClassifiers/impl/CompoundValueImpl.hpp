//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_SIMPLECLASSIFIERS_COMPOUNDVALUECOMPOUNDVALUEIMPL_HPP
#define FUML_SEMANTICS_SIMPLECLASSIFIERS_COMPOUNDVALUECOMPOUNDVALUEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../CompoundValue.hpp"

#include "fUML/Semantics/SimpleClassifiers/impl/SimpleClassifiersFactoryImpl.hpp"
#include "fUML/Semantics/SimpleClassifiers/impl/StructuredValueImpl.hpp"

//*********************************
namespace fUML::Semantics::SimpleClassifiers 
{
	class FUML_API CompoundValueImpl : virtual public StructuredValueImpl, virtual public CompoundValue 
	{
		public: 
			CompoundValueImpl(const CompoundValueImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			CompoundValueImpl& operator=(CompoundValueImpl const&); 

		protected:
			friend class fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactoryImpl;
			CompoundValueImpl();
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::CompoundValue> getThisCompoundValuePtr() const;
			virtual void setThisCompoundValuePtr(std::weak_ptr<fUML::Semantics::SimpleClassifiers::CompoundValue> thisCompoundValuePtr);


		public:
			//destructor
			virtual ~CompoundValueImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<fUML::Semantics::Values::Value> _copy() ;
			virtual void assignFeatureValue(const std::shared_ptr<uml::StructuralFeature>& feature, const std::shared_ptr<Bag<fUML::Semantics::Values::Value>>& values, int position) ;
			virtual bool equals(const std::shared_ptr<fUML::Semantics::Values::Value>& otherValue) ;
			virtual void removeFeatureValues(const std::shared_ptr<uml::Classifier>& classifier) ;
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> retrieveFeatureValue(const std::shared_ptr<uml::StructuralFeature>& feature) ;
			virtual std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> retrieveFeatureValues() ;
			virtual std::string toString() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>>& getFeatureValues() const ;
			
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
			virtual const std::shared_ptr<ecore::EClass>& eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, const Any& newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments) ;

		private:
			std::weak_ptr<fUML::Semantics::SimpleClassifiers::CompoundValue> m_thisCompoundValuePtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_SIMPLECLASSIFIERS_COMPOUNDVALUECOMPOUNDVALUEIMPL_HPP */
