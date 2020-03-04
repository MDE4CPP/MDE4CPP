//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_SIMPLECLASSIFIERSPACKAGEIMPL_HPP
#define FUML_SEMANTICS_SIMPLECLASSIFIERSPACKAGEIMPL_HPP

#include "ecore/EcorePackage.hpp"
#include "ecore/impl/EPackageImpl.hpp"

#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp" 


namespace fUML::Semantics::SimpleClassifiers 
{
	class BooleanValue;
	class CompoundValue;
	class DataValue;
	class EnumerationValue;
	class FeatureValue;
	class IntegerValue;
	class PrimitiveValue;
	class RealValue;
	class SignalInstance;
	class StringValue;
	class StructuredValue;
	class UnlimitedNaturalValue;}

namespace ecore
{
	class EcoreFactory;
}

namespace fUML::Semantics::SimpleClassifiers
{
	class SimpleClassifiersPackageImpl : public ecore::EPackageImpl ,virtual public SimpleClassifiersPackage
	{
		private:    
			SimpleClassifiersPackageImpl(SimpleClassifiersPackageImpl const&) = delete;
			SimpleClassifiersPackageImpl& operator=(SimpleClassifiersPackageImpl const&) = delete;

		protected:
			SimpleClassifiersPackageImpl();

		public:
			virtual ~SimpleClassifiersPackageImpl();

			// Begin Class BooleanValue
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getBooleanValue_Class() const ;
			
			virtual std::shared_ptr<ecore::EAttribute> getBooleanValue_Attribute_value() const ;
			
			
			virtual std::shared_ptr<ecore::EOperation> getBooleanValue_Operation_equals_Value() const ;
			virtual std::shared_ptr<ecore::EOperation> getBooleanValue_Operation_specify() const ;
			virtual std::shared_ptr<ecore::EOperation> getBooleanValue_Operation_toString() const ;
			
			// End Class BooleanValue

			// Begin Class CompoundValue
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCompoundValue_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getCompoundValue_Attribute_featureValues() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getCompoundValue_Operation_assignFeatureValue_StructuralFeature_EInt() const ;
			virtual std::shared_ptr<ecore::EOperation> getCompoundValue_Operation_equals_Value() const ;
			virtual std::shared_ptr<ecore::EOperation> getCompoundValue_Operation_removeFeatureValues_Classifier() const ;
			virtual std::shared_ptr<ecore::EOperation> getCompoundValue_Operation_retrieveFeatureValue_StructuralFeature() const ;
			virtual std::shared_ptr<ecore::EOperation> getCompoundValue_Operation_retrieveFeatureValues() const ;
			virtual std::shared_ptr<ecore::EOperation> getCompoundValue_Operation_toString() const ;
			
			// End Class CompoundValue

			// Begin Class DataValue
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getDataValue_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getDataValue_Attribute_type() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getDataValue_Operation_getTypes() const ;
			virtual std::shared_ptr<ecore::EOperation> getDataValue_Operation_new_() const ;
			
			// End Class DataValue

			// Begin Class EnumerationValue
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEnumerationValue_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getEnumerationValue_Attribute_literal() const ;
			virtual std::shared_ptr<ecore::EReference> getEnumerationValue_Attribute_type() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getEnumerationValue_Operation_equals_Value() const ;
			virtual std::shared_ptr<ecore::EOperation> getEnumerationValue_Operation_getTypes() const ;
			virtual std::shared_ptr<ecore::EOperation> getEnumerationValue_Operation_new_() const ;
			virtual std::shared_ptr<ecore::EOperation> getEnumerationValue_Operation_specify() const ;
			virtual std::shared_ptr<ecore::EOperation> getEnumerationValue_Operation_toString() const ;
			
			// End Class EnumerationValue

			// Begin Class FeatureValue
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getFeatureValue_Class() const ;
			
			virtual std::shared_ptr<ecore::EAttribute> getFeatureValue_Attribute_position() const ;
			
			virtual std::shared_ptr<ecore::EReference> getFeatureValue_Attribute_feature() const ;
			virtual std::shared_ptr<ecore::EReference> getFeatureValue_Attribute_values() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getFeatureValue_Operation_hasEqualValues_FeatureValue() const ;
			
			// End Class FeatureValue

			// Begin Class IntegerValue
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getIntegerValue_Class() const ;
			
			virtual std::shared_ptr<ecore::EAttribute> getIntegerValue_Attribute_value() const ;
			
			
			virtual std::shared_ptr<ecore::EOperation> getIntegerValue_Operation_equals_Value() const ;
			virtual std::shared_ptr<ecore::EOperation> getIntegerValue_Operation_specify() const ;
			virtual std::shared_ptr<ecore::EOperation> getIntegerValue_Operation_toString() const ;
			
			// End Class IntegerValue

			// Begin Class PrimitiveValue
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getPrimitiveValue_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getPrimitiveValue_Attribute_type() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getPrimitiveValue_Operation_getTypes() const ;
			
			// End Class PrimitiveValue

			// Begin Class RealValue
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getRealValue_Class() const ;
			
			virtual std::shared_ptr<ecore::EAttribute> getRealValue_Attribute_value() const ;
			
			
			virtual std::shared_ptr<ecore::EOperation> getRealValue_Operation_equals_Value() const ;
			virtual std::shared_ptr<ecore::EOperation> getRealValue_Operation_specify() const ;
			virtual std::shared_ptr<ecore::EOperation> getRealValue_Operation_toString() const ;
			
			// End Class RealValue

			// Begin Class SignalInstance
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getSignalInstance_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getSignalInstance_Attribute_type() const ;
			
			
			// End Class SignalInstance

			// Begin Class StringValue
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getStringValue_Class() const ;
			
			virtual std::shared_ptr<ecore::EAttribute> getStringValue_Attribute_value() const ;
			
			
			virtual std::shared_ptr<ecore::EOperation> getStringValue_Operation_equals_Value() const ;
			virtual std::shared_ptr<ecore::EOperation> getStringValue_Operation_specify() const ;
			virtual std::shared_ptr<ecore::EOperation> getStringValue_Operation_toString() const ;
			
			// End Class StringValue

			// Begin Class StructuredValue
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getStructuredValue_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getStructuredValue_Operation_assignFeatureValue_StructuralFeature_EInt() const ;
			virtual std::shared_ptr<ecore::EOperation> getStructuredValue_Operation_createFeatureValues() const ;
			virtual std::shared_ptr<ecore::EOperation> getStructuredValue_Operation_getValues_StructuralFeature_FeatureValue() const ;
			virtual std::shared_ptr<ecore::EOperation> getStructuredValue_Operation_removeValue_StructuralFeature_Value() const ;
			virtual std::shared_ptr<ecore::EOperation> getStructuredValue_Operation_retrieveFeatureValue_StructuralFeature() const ;
			virtual std::shared_ptr<ecore::EOperation> getStructuredValue_Operation_retrieveFeatureValues() const ;
			virtual std::shared_ptr<ecore::EOperation> getStructuredValue_Operation_setFeatureValue_StructuralFeature_EInt() const ;
			virtual std::shared_ptr<ecore::EOperation> getStructuredValue_Operation_specify() const ;
			
			// End Class StructuredValue

			// Begin Class UnlimitedNaturalValue
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getUnlimitedNaturalValue_Class() const ;
			
			virtual std::shared_ptr<ecore::EAttribute> getUnlimitedNaturalValue_Attribute_value() const ;
			
			
			virtual std::shared_ptr<ecore::EOperation> getUnlimitedNaturalValue_Operation_equals_Value() const ;
			virtual std::shared_ptr<ecore::EOperation> getUnlimitedNaturalValue_Operation_specify() const ;
			virtual std::shared_ptr<ecore::EOperation> getUnlimitedNaturalValue_Operation_toString() const ;
			
			// End Class UnlimitedNaturalValue

			
			// SubPackages Getters
			

		private:
			std::shared_ptr<ecore::EClass> m_booleanValue_Class = nullptr;std::shared_ptr<ecore::EClass> m_compoundValue_Class = nullptr;std::shared_ptr<ecore::EClass> m_dataValue_Class = nullptr;std::shared_ptr<ecore::EClass> m_enumerationValue_Class = nullptr;std::shared_ptr<ecore::EClass> m_featureValue_Class = nullptr;std::shared_ptr<ecore::EClass> m_integerValue_Class = nullptr;std::shared_ptr<ecore::EClass> m_primitiveValue_Class = nullptr;std::shared_ptr<ecore::EClass> m_realValue_Class = nullptr;std::shared_ptr<ecore::EClass> m_signalInstance_Class = nullptr;std::shared_ptr<ecore::EClass> m_stringValue_Class = nullptr;std::shared_ptr<ecore::EClass> m_structuredValue_Class = nullptr;std::shared_ptr<ecore::EClass> m_unlimitedNaturalValue_Class = nullptr;
			
			std::shared_ptr<ecore::EAttribute> m_featureValue_Attribute_position = nullptr;std::shared_ptr<ecore::EAttribute> m_booleanValue_Attribute_value = nullptr;std::shared_ptr<ecore::EAttribute> m_integerValue_Attribute_value = nullptr;std::shared_ptr<ecore::EAttribute> m_realValue_Attribute_value = nullptr;std::shared_ptr<ecore::EAttribute> m_stringValue_Attribute_value = nullptr;std::shared_ptr<ecore::EAttribute> m_unlimitedNaturalValue_Attribute_value = nullptr;
			std::shared_ptr<ecore::EReference> m_featureValue_Attribute_feature = nullptr;std::shared_ptr<ecore::EReference> m_compoundValue_Attribute_featureValues = nullptr;std::shared_ptr<ecore::EReference> m_enumerationValue_Attribute_literal = nullptr;std::shared_ptr<ecore::EReference> m_dataValue_Attribute_type = nullptr;std::shared_ptr<ecore::EReference> m_enumerationValue_Attribute_type = nullptr;std::shared_ptr<ecore::EReference> m_primitiveValue_Attribute_type = nullptr;std::shared_ptr<ecore::EReference> m_signalInstance_Attribute_type = nullptr;std::shared_ptr<ecore::EReference> m_featureValue_Attribute_values = nullptr;
			std::shared_ptr<ecore::EOperation> m_compoundValue_Operation_assignFeatureValue_StructuralFeature_EInt = nullptr;std::shared_ptr<ecore::EOperation> m_structuredValue_Operation_assignFeatureValue_StructuralFeature_EInt = nullptr;std::shared_ptr<ecore::EOperation> m_structuredValue_Operation_createFeatureValues = nullptr;std::shared_ptr<ecore::EOperation> m_booleanValue_Operation_equals_Value = nullptr;std::shared_ptr<ecore::EOperation> m_compoundValue_Operation_equals_Value = nullptr;std::shared_ptr<ecore::EOperation> m_enumerationValue_Operation_equals_Value = nullptr;std::shared_ptr<ecore::EOperation> m_integerValue_Operation_equals_Value = nullptr;std::shared_ptr<ecore::EOperation> m_realValue_Operation_equals_Value = nullptr;std::shared_ptr<ecore::EOperation> m_stringValue_Operation_equals_Value = nullptr;std::shared_ptr<ecore::EOperation> m_unlimitedNaturalValue_Operation_equals_Value = nullptr;std::shared_ptr<ecore::EOperation> m_dataValue_Operation_getTypes = nullptr;std::shared_ptr<ecore::EOperation> m_enumerationValue_Operation_getTypes = nullptr;std::shared_ptr<ecore::EOperation> m_primitiveValue_Operation_getTypes = nullptr;std::shared_ptr<ecore::EOperation> m_structuredValue_Operation_getValues_StructuralFeature_FeatureValue = nullptr;std::shared_ptr<ecore::EOperation> m_featureValue_Operation_hasEqualValues_FeatureValue = nullptr;std::shared_ptr<ecore::EOperation> m_dataValue_Operation_new_ = nullptr;std::shared_ptr<ecore::EOperation> m_enumerationValue_Operation_new_ = nullptr;std::shared_ptr<ecore::EOperation> m_compoundValue_Operation_removeFeatureValues_Classifier = nullptr;std::shared_ptr<ecore::EOperation> m_structuredValue_Operation_removeValue_StructuralFeature_Value = nullptr;std::shared_ptr<ecore::EOperation> m_compoundValue_Operation_retrieveFeatureValue_StructuralFeature = nullptr;std::shared_ptr<ecore::EOperation> m_structuredValue_Operation_retrieveFeatureValue_StructuralFeature = nullptr;std::shared_ptr<ecore::EOperation> m_compoundValue_Operation_retrieveFeatureValues = nullptr;std::shared_ptr<ecore::EOperation> m_structuredValue_Operation_retrieveFeatureValues = nullptr;std::shared_ptr<ecore::EOperation> m_structuredValue_Operation_setFeatureValue_StructuralFeature_EInt = nullptr;std::shared_ptr<ecore::EOperation> m_booleanValue_Operation_specify = nullptr;std::shared_ptr<ecore::EOperation> m_enumerationValue_Operation_specify = nullptr;std::shared_ptr<ecore::EOperation> m_integerValue_Operation_specify = nullptr;std::shared_ptr<ecore::EOperation> m_realValue_Operation_specify = nullptr;std::shared_ptr<ecore::EOperation> m_stringValue_Operation_specify = nullptr;std::shared_ptr<ecore::EOperation> m_structuredValue_Operation_specify = nullptr;std::shared_ptr<ecore::EOperation> m_unlimitedNaturalValue_Operation_specify = nullptr;std::shared_ptr<ecore::EOperation> m_booleanValue_Operation_toString = nullptr;std::shared_ptr<ecore::EOperation> m_compoundValue_Operation_toString = nullptr;std::shared_ptr<ecore::EOperation> m_enumerationValue_Operation_toString = nullptr;std::shared_ptr<ecore::EOperation> m_integerValue_Operation_toString = nullptr;std::shared_ptr<ecore::EOperation> m_realValue_Operation_toString = nullptr;std::shared_ptr<ecore::EOperation> m_stringValue_Operation_toString = nullptr;std::shared_ptr<ecore::EOperation> m_unlimitedNaturalValue_Operation_toString = nullptr;

			friend class SimpleClassifiersPackage;

			static bool isInited;
			static SimpleClassifiersPackage* create();
			bool isInitialized = false;
 			bool isCreated = false;

			virtual void init(std::shared_ptr<ecore::EPackage> package);

		public:
			void createPackageContents(std::shared_ptr<ecore::EPackage> package);
			void initializePackageContents();

		private:
			void createBooleanValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory);
			void createCompoundValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory);
			void createDataValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory);
			void createEnumerationValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory);
			void createFeatureValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory);
			void createIntegerValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory);
			void createPrimitiveValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory);
			void createRealValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory);
			void createSignalInstanceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory);
			void createStringValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory);
			void createStructuredValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory);
			void createUnlimitedNaturalValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory);
			void createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory);

			void initializeBooleanValueContent();
			void initializeCompoundValueContent();
			void initializeDataValueContent();
			void initializeEnumerationValueContent();
			void initializeFeatureValueContent();
			void initializeIntegerValueContent();
			void initializePrimitiveValueContent();
			void initializeRealValueContent();
			void initializeSignalInstanceContent();
			void initializeStringValueContent();
			void initializeStructuredValueContent();
			void initializeUnlimitedNaturalValueContent();
			void initializePackageEDataTypes();



	};
}
#endif /* end of include guard: FUML_SEMANTICS_SIMPLECLASSIFIERSPACKAGEIMPL_HPP */
