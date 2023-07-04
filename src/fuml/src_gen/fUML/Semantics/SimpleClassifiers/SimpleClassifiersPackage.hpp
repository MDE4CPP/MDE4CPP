//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_SIMPLECLASSIFIERSPACKAGE_HPP
#define FUML_SEMANTICS_SIMPLECLASSIFIERSPACKAGE_HPP

// namespace macro header include
#include "fUML/fUML.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EReference;
	class EAnnotation;
	class EAttribute;
	class EDataType;
	class EGenericType;
	class EClass;
	class EStringToStringMapEntry;
	class EOperation;
	class EParameter;
}

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
	class UnlimitedNaturalValue;
}
 
namespace fUML::Semantics::SimpleClassifiers 
{
	/*!
	The Metamodel Package for the SimpleClassifiers metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class FUML_API SimpleClassifiersPackage : virtual public ecore::EPackage 
	{
		private:    
			SimpleClassifiersPackage(SimpleClassifiersPackage const&) = delete;
			SimpleClassifiersPackage& operator=(SimpleClassifiersPackage const&) = delete;

		protected:
			SimpleClassifiersPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			// Begin Class BooleanValue
			//Class and Feature IDs 
			static const unsigned long BOOLEANVALUE_CLASS = 696652347;
			static const unsigned int BOOLEANVALUE_CLASS_FEATURE_COUNT = 2;
			static const unsigned int BOOLEANVALUE_CLASS_OPERATION_COUNT = 19;
			static const unsigned long BOOLEANVALUE_ATTRIBUTE_VALUE = 1331291534;
			
			
			static const unsigned int BOOLEANVALUE_OPERATION__COPY = 4154941943;
			static const unsigned int BOOLEANVALUE_OPERATION_EQUALS_VALUE = 3523942500;
			static const unsigned int BOOLEANVALUE_OPERATION_NEW_ = 3001681470;
			static const unsigned int BOOLEANVALUE_OPERATION_SPECIFY = 3642390552;
			static const unsigned int BOOLEANVALUE_OPERATION_TOSTRING = 3084939113;
			
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getBooleanValue_Class() const = 0;
			
			virtual const std::shared_ptr<ecore::EAttribute>& getBooleanValue_Attribute_value() const = 0;
			
			
			virtual const std::shared_ptr<ecore::EOperation>& getBooleanValue_Operation__copy() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getBooleanValue_Operation_equals_Value() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getBooleanValue_Operation_new_() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getBooleanValue_Operation_specify() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getBooleanValue_Operation_toString() const = 0;
			
			// End Class BooleanValue


			// Begin Class CompoundValue
			//Class and Feature IDs 
			static const unsigned long COMPOUNDVALUE_CLASS = 960723248;
			static const unsigned int COMPOUNDVALUE_CLASS_FEATURE_COUNT = 1;
			static const unsigned int COMPOUNDVALUE_CLASS_OPERATION_COUNT = 30;
			
			static const unsigned long COMPOUNDVALUE_ATTRIBUTE_FEATUREVALUES = 956860599;
			
			static const unsigned int COMPOUNDVALUE_OPERATION__COPY = 2533723316;
			static const unsigned int COMPOUNDVALUE_OPERATION_ASSIGNFEATUREVALUE_STRUCTURALFEATURE_EINT = 1372552534;
			static const unsigned int COMPOUNDVALUE_OPERATION_EQUALS_VALUE = 3450491205;
			static const unsigned int COMPOUNDVALUE_OPERATION_REMOVEFEATUREVALUES_CLASSIFIER = 665324585;
			static const unsigned int COMPOUNDVALUE_OPERATION_RETRIEVEFEATUREVALUE_STRUCTURALFEATURE = 3564898586;
			static const unsigned int COMPOUNDVALUE_OPERATION_RETRIEVEFEATUREVALUES = 379911432;
			static const unsigned int COMPOUNDVALUE_OPERATION_TOSTRING = 1658148174;
			
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getCompoundValue_Class() const = 0;
			
			
			virtual const std::shared_ptr<ecore::EReference>& getCompoundValue_Attribute_featureValues() const = 0;
			
			virtual const std::shared_ptr<ecore::EOperation>& getCompoundValue_Operation__copy() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getCompoundValue_Operation_assignFeatureValue_StructuralFeature_EInt() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getCompoundValue_Operation_equals_Value() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getCompoundValue_Operation_removeFeatureValues_Classifier() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getCompoundValue_Operation_retrieveFeatureValue_StructuralFeature() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getCompoundValue_Operation_retrieveFeatureValues() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getCompoundValue_Operation_toString() const = 0;
			
			// End Class CompoundValue


			// Begin Class DataValue
			//Class and Feature IDs 
			static const unsigned long DATAVALUE_CLASS = 622084858;
			static const unsigned int DATAVALUE_CLASS_FEATURE_COUNT = 2;
			static const unsigned int DATAVALUE_CLASS_OPERATION_COUNT = 33;
			
			static const unsigned long DATAVALUE_ATTRIBUTE_TYPE = 1769283923;
			
			static const unsigned int DATAVALUE_OPERATION__COPY = 3736200145;
			static const unsigned int DATAVALUE_OPERATION_GETTYPES = 120141329;
			static const unsigned int DATAVALUE_OPERATION_NEW_ = 1021578740;
			
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getDataValue_Class() const = 0;
			
			
			virtual const std::shared_ptr<ecore::EReference>& getDataValue_Attribute_type() const = 0;
			
			virtual const std::shared_ptr<ecore::EOperation>& getDataValue_Operation__copy() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getDataValue_Operation_getTypes() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getDataValue_Operation_new_() const = 0;
			
			// End Class DataValue


			// Begin Class EnumerationValue
			//Class and Feature IDs 
			static const unsigned long ENUMERATIONVALUE_CLASS = 241622527;
			static const unsigned int ENUMERATIONVALUE_CLASS_FEATURE_COUNT = 2;
			static const unsigned int ENUMERATIONVALUE_CLASS_OPERATION_COUNT = 18;
			
			static const unsigned long ENUMERATIONVALUE_ATTRIBUTE_LITERAL = 1720521261;
			static const unsigned long ENUMERATIONVALUE_ATTRIBUTE_TYPE = 941000500;
			
			static const unsigned int ENUMERATIONVALUE_OPERATION__COPY = 412360958;
			static const unsigned int ENUMERATIONVALUE_OPERATION_EQUALS_VALUE = 594639323;
			static const unsigned int ENUMERATIONVALUE_OPERATION_GETTYPES = 1927916094;
			static const unsigned int ENUMERATIONVALUE_OPERATION_NEW_ = 2131877013;
			static const unsigned int ENUMERATIONVALUE_OPERATION_SPECIFY = 2045018959;
			static const unsigned int ENUMERATIONVALUE_OPERATION_TOSTRING = 3964346320;
			
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getEnumerationValue_Class() const = 0;
			
			
			virtual const std::shared_ptr<ecore::EReference>& getEnumerationValue_Attribute_literal() const = 0;
			virtual const std::shared_ptr<ecore::EReference>& getEnumerationValue_Attribute_type() const = 0;
			
			virtual const std::shared_ptr<ecore::EOperation>& getEnumerationValue_Operation__copy() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getEnumerationValue_Operation_equals_Value() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getEnumerationValue_Operation_getTypes() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getEnumerationValue_Operation_new_() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getEnumerationValue_Operation_specify() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getEnumerationValue_Operation_toString() const = 0;
			
			// End Class EnumerationValue


			// Begin Class FeatureValue
			//Class and Feature IDs 
			static const unsigned long FEATUREVALUE_CLASS = 1582063511;
			static const unsigned int FEATUREVALUE_CLASS_FEATURE_COUNT = 3;
			static const unsigned int FEATUREVALUE_CLASS_OPERATION_COUNT = 2;
			static const unsigned long FEATUREVALUE_ATTRIBUTE_POSITION = 1521498994;
			
			static const unsigned long FEATUREVALUE_ATTRIBUTE_FEATURE = 1140053072;
			static const unsigned long FEATUREVALUE_ATTRIBUTE_VALUES = 740866004;
			
			static const unsigned int FEATUREVALUE_OPERATION__COPY = 3021163793;
			static const unsigned int FEATUREVALUE_OPERATION_HASEQUALVALUES_FEATUREVALUE = 2370187995;
			
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getFeatureValue_Class() const = 0;
			
			virtual const std::shared_ptr<ecore::EAttribute>& getFeatureValue_Attribute_position() const = 0;
			
			virtual const std::shared_ptr<ecore::EReference>& getFeatureValue_Attribute_feature() const = 0;
			virtual const std::shared_ptr<ecore::EReference>& getFeatureValue_Attribute_values() const = 0;
			
			virtual const std::shared_ptr<ecore::EOperation>& getFeatureValue_Operation__copy() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getFeatureValue_Operation_hasEqualValues_FeatureValue() const = 0;
			
			// End Class FeatureValue


			// Begin Class IntegerValue
			//Class and Feature IDs 
			static const unsigned long INTEGERVALUE_CLASS = 2030861441;
			static const unsigned int INTEGERVALUE_CLASS_FEATURE_COUNT = 2;
			static const unsigned int INTEGERVALUE_CLASS_OPERATION_COUNT = 19;
			static const unsigned long INTEGERVALUE_ATTRIBUTE_VALUE = 518016981;
			
			
			static const unsigned int INTEGERVALUE_OPERATION__COPY = 4095267589;
			static const unsigned int INTEGERVALUE_OPERATION_EQUALS_VALUE = 3464268146;
			static const unsigned int INTEGERVALUE_OPERATION_NEW_ = 2942007116;
			static const unsigned int INTEGERVALUE_OPERATION_SPECIFY = 3582716198;
			static const unsigned int INTEGERVALUE_OPERATION_TOSTRING = 3025264759;
			
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getIntegerValue_Class() const = 0;
			
			virtual const std::shared_ptr<ecore::EAttribute>& getIntegerValue_Attribute_value() const = 0;
			
			
			virtual const std::shared_ptr<ecore::EOperation>& getIntegerValue_Operation__copy() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getIntegerValue_Operation_equals_Value() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getIntegerValue_Operation_new_() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getIntegerValue_Operation_specify() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getIntegerValue_Operation_toString() const = 0;
			
			// End Class IntegerValue


			// Begin Class PrimitiveValue
			//Class and Feature IDs 
			static const unsigned long PRIMITIVEVALUE_CLASS = 884702000;
			static const unsigned int PRIMITIVEVALUE_CLASS_FEATURE_COUNT = 1;
			static const unsigned int PRIMITIVEVALUE_CLASS_OPERATION_COUNT = 14;
			
			static const unsigned long PRIMITIVEVALUE_ATTRIBUTE_TYPE = 1999593611;
			
			static const unsigned int PRIMITIVEVALUE_OPERATION__COPY = 2505682004;
			static const unsigned int PRIMITIVEVALUE_OPERATION_GETTYPES = 951226260;
			
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getPrimitiveValue_Class() const = 0;
			
			
			virtual const std::shared_ptr<ecore::EReference>& getPrimitiveValue_Attribute_type() const = 0;
			
			virtual const std::shared_ptr<ecore::EOperation>& getPrimitiveValue_Operation__copy() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getPrimitiveValue_Operation_getTypes() const = 0;
			
			// End Class PrimitiveValue


			// Begin Class RealValue
			//Class and Feature IDs 
			static const unsigned long REALVALUE_CLASS = 1589674022;
			static const unsigned int REALVALUE_CLASS_FEATURE_COUNT = 2;
			static const unsigned int REALVALUE_CLASS_OPERATION_COUNT = 19;
			static const unsigned long REALVALUE_ATTRIBUTE_VALUE = 305114459;
			
			
			static const unsigned int REALVALUE_OPERATION__COPY = 2829436007;
			static const unsigned int REALVALUE_OPERATION_EQUALS_VALUE = 1760399560;
			static const unsigned int REALVALUE_OPERATION_NEW_ = 114814602;
			static const unsigned int REALVALUE_OPERATION_SPECIFY = 1095688268;
			static const unsigned int REALVALUE_OPERATION_TOSTRING = 1044160033;
			
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getRealValue_Class() const = 0;
			
			virtual const std::shared_ptr<ecore::EAttribute>& getRealValue_Attribute_value() const = 0;
			
			
			virtual const std::shared_ptr<ecore::EOperation>& getRealValue_Operation__copy() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getRealValue_Operation_equals_Value() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getRealValue_Operation_new_() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getRealValue_Operation_specify() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getRealValue_Operation_toString() const = 0;
			
			// End Class RealValue


			// Begin Class SignalInstance
			//Class and Feature IDs 
			static const unsigned long SIGNALINSTANCE_CLASS = 1044212856;
			static const unsigned int SIGNALINSTANCE_CLASS_FEATURE_COUNT = 2;
			static const unsigned int SIGNALINSTANCE_CLASS_OPERATION_COUNT = 33;
			
			static const unsigned long SIGNALINSTANCE_ATTRIBUTE_TYPE = 11620820;
			
			static const unsigned int SIGNALINSTANCE_OPERATION__COPY = 2945212473;
			static const unsigned int SIGNALINSTANCE_OPERATION_GETTYPES = 1341600700;
			static const unsigned int SIGNALINSTANCE_OPERATION_NEW_ = 1841885000;
			
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getSignalInstance_Class() const = 0;
			
			
			virtual const std::shared_ptr<ecore::EReference>& getSignalInstance_Attribute_type() const = 0;
			
			virtual const std::shared_ptr<ecore::EOperation>& getSignalInstance_Operation__copy() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getSignalInstance_Operation_getTypes() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getSignalInstance_Operation_new_() const = 0;
			
			// End Class SignalInstance


			// Begin Class StringValue
			//Class and Feature IDs 
			static const unsigned long STRINGVALUE_CLASS = 1276339704;
			static const unsigned int STRINGVALUE_CLASS_FEATURE_COUNT = 2;
			static const unsigned int STRINGVALUE_CLASS_OPERATION_COUNT = 19;
			static const unsigned long STRINGVALUE_ATTRIBUTE_VALUE = 721054197;
			
			
			static const unsigned int STRINGVALUE_OPERATION__COPY = 3142539350;
			static const unsigned int STRINGVALUE_OPERATION_EQUALS_VALUE = 2401299631;
			static const unsigned int STRINGVALUE_OPERATION_NEW_ = 1337963105;
			static const unsigned int STRINGVALUE_OPERATION_SPECIFY = 3538054163;
			static const unsigned int STRINGVALUE_OPERATION_TOSTRING = 529162816;
			
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getStringValue_Class() const = 0;
			
			virtual const std::shared_ptr<ecore::EAttribute>& getStringValue_Attribute_value() const = 0;
			
			
			virtual const std::shared_ptr<ecore::EOperation>& getStringValue_Operation__copy() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getStringValue_Operation_equals_Value() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getStringValue_Operation_new_() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getStringValue_Operation_specify() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getStringValue_Operation_toString() const = 0;
			
			// End Class StringValue


			// Begin Class StructuredValue
			//Class and Feature IDs 
			static const unsigned long STRUCTUREDVALUE_CLASS = 1984808016;
			static const unsigned int STRUCTUREDVALUE_CLASS_FEATURE_COUNT = 0;
			static const unsigned int STRUCTUREDVALUE_CLASS_OPERATION_COUNT = 23;
			
			
			static const unsigned int STRUCTUREDVALUE_OPERATION_ASSIGNFEATUREVALUE_STRUCTURALFEATURE_EINT = 2915015402;
			static const unsigned int STRUCTUREDVALUE_OPERATION_CREATEFEATUREVALUES = 4258337868;
			static const unsigned int STRUCTUREDVALUE_OPERATION_GETMEMBERFEATURES_CLASSIFIER = 1309752345;
			static const unsigned int STRUCTUREDVALUE_OPERATION_GETSTRUCTURALFEATUREFORTYPE_CLASSIFIER = 4241902516;
			static const unsigned int STRUCTUREDVALUE_OPERATION_GETVALUES_STRUCTURALFEATURE_FEATUREVALUE = 3849835591;
			static const unsigned int STRUCTUREDVALUE_OPERATION_REMOVEVALUE_STRUCTURALFEATURE_VALUE = 3525281514;
			static const unsigned int STRUCTUREDVALUE_OPERATION_RETRIEVEFEATUREVALUE_STRUCTURALFEATURE = 2231973006;
			static const unsigned int STRUCTUREDVALUE_OPERATION_RETRIEVEFEATUREVALUES = 2019934988;
			static const unsigned int STRUCTUREDVALUE_OPERATION_RETRIEVESTRUCTURALFEATURES = 3859098145;
			static const unsigned int STRUCTUREDVALUE_OPERATION_SETFEATUREVALUE_STRUCTURALFEATURE_EINT = 3826465969;
			static const unsigned int STRUCTUREDVALUE_OPERATION_SPECIFY = 2039107205;
			
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getStructuredValue_Class() const = 0;
			
			
			
			virtual const std::shared_ptr<ecore::EOperation>& getStructuredValue_Operation_assignFeatureValue_StructuralFeature_EInt() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getStructuredValue_Operation_createFeatureValues() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getStructuredValue_Operation_getMemberFeatures_Classifier() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getStructuredValue_Operation_getStructuralFeatureForType_Classifier() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getStructuredValue_Operation_getValues_StructuralFeature_FeatureValue() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getStructuredValue_Operation_removeValue_StructuralFeature_Value() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getStructuredValue_Operation_retrieveFeatureValue_StructuralFeature() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getStructuredValue_Operation_retrieveFeatureValues() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getStructuredValue_Operation_retrieveStructuralFeatures() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getStructuredValue_Operation_setFeatureValue_StructuralFeature_EInt() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getStructuredValue_Operation_specify() const = 0;
			
			// End Class StructuredValue


			// Begin Class UnlimitedNaturalValue
			//Class and Feature IDs 
			static const unsigned long UNLIMITEDNATURALVALUE_CLASS = 459381760;
			static const unsigned int UNLIMITEDNATURALVALUE_CLASS_FEATURE_COUNT = 2;
			static const unsigned int UNLIMITEDNATURALVALUE_CLASS_OPERATION_COUNT = 19;
			static const unsigned long UNLIMITEDNATURALVALUE_ATTRIBUTE_VALUE = 1958359245;
			
			
			static const unsigned int UNLIMITEDNATURALVALUE_OPERATION__COPY = 2602066957;
			static const unsigned int UNLIMITEDNATURALVALUE_OPERATION_EQUALS_VALUE = 3214001150;
			static const unsigned int UNLIMITEDNATURALVALUE_OPERATION_NEW_ = 3814660320;
			static const unsigned int UNLIMITEDNATURALVALUE_OPERATION_SPECIFY = 3624944066;
			static const unsigned int UNLIMITEDNATURALVALUE_OPERATION_TOSTRING = 1690699879;
			
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getUnlimitedNaturalValue_Class() const = 0;
			
			virtual const std::shared_ptr<ecore::EAttribute>& getUnlimitedNaturalValue_Attribute_value() const = 0;
			
			
			virtual const std::shared_ptr<ecore::EOperation>& getUnlimitedNaturalValue_Operation__copy() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getUnlimitedNaturalValue_Operation_equals_Value() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getUnlimitedNaturalValue_Operation_new_() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getUnlimitedNaturalValue_Operation_specify() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getUnlimitedNaturalValue_Operation_toString() const = 0;
			
			// End Class UnlimitedNaturalValue

			
			

			

			//Singleton Instance and Getter
			private:
				static std::shared_ptr<SimpleClassifiersPackage> instance;
			public:
				static std::shared_ptr<SimpleClassifiersPackage> eInstance();
	};
}
#endif /* end of include guard: FUML_SEMANTICS_SIMPLECLASSIFIERSPACKAGE_HPP */
