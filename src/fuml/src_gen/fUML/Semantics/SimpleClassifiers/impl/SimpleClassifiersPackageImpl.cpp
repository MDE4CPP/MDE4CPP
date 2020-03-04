#include "fUML/Semantics/SimpleClassifiers/impl/SimpleClassifiersPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

//metamodel factory
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersFactory.hpp"

//depending model packages
#include "ecore/EcorePackage.hpp"
#include "fUML/FUMLPackage.hpp"
#include "uml/UmlPackage.hpp"

using namespace fUML::Semantics::SimpleClassifiers;

bool SimpleClassifiersPackageImpl::isInited = false;

SimpleClassifiersPackageImpl::SimpleClassifiersPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( SimpleClassifiersFactory::eInstance()));
}

SimpleClassifiersPackageImpl::~SimpleClassifiersPackageImpl()
{
}

SimpleClassifiersPackage* SimpleClassifiersPackageImpl::create()
{
	if (isInited)
	{
		return SimpleClassifiersPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    SimpleClassifiersPackageImpl * metaModelPackage = new SimpleClassifiersPackageImpl();
    return metaModelPackage;
}

void SimpleClassifiersPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}



// Begin Class BooleanValue
std::shared_ptr<ecore::EClass> SimpleClassifiersPackageImpl::getBooleanValue_Class() const
{
	return m_booleanValue_Class;
}

std::shared_ptr<ecore::EAttribute> SimpleClassifiersPackageImpl::getBooleanValue_Attribute_value() const
{
	return m_booleanValue_Attribute_value;
}


std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getBooleanValue_Operation_equals_Value() const
{
	return m_booleanValue_Operation_equals_Value;
}
std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getBooleanValue_Operation_specify() const
{
	return m_booleanValue_Operation_specify;
}
std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getBooleanValue_Operation_toString() const
{
	return m_booleanValue_Operation_toString;
}

// End Class BooleanValue

// Begin Class CompoundValue
std::shared_ptr<ecore::EClass> SimpleClassifiersPackageImpl::getCompoundValue_Class() const
{
	return m_compoundValue_Class;
}


std::shared_ptr<ecore::EReference> SimpleClassifiersPackageImpl::getCompoundValue_Attribute_featureValues() const
{
	return m_compoundValue_Attribute_featureValues;
}

std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getCompoundValue_Operation_assignFeatureValue_StructuralFeature_EInt() const
{
	return m_compoundValue_Operation_assignFeatureValue_StructuralFeature_EInt;
}
std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getCompoundValue_Operation_equals_Value() const
{
	return m_compoundValue_Operation_equals_Value;
}
std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getCompoundValue_Operation_removeFeatureValues_Classifier() const
{
	return m_compoundValue_Operation_removeFeatureValues_Classifier;
}
std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getCompoundValue_Operation_retrieveFeatureValue_StructuralFeature() const
{
	return m_compoundValue_Operation_retrieveFeatureValue_StructuralFeature;
}
std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getCompoundValue_Operation_retrieveFeatureValues() const
{
	return m_compoundValue_Operation_retrieveFeatureValues;
}
std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getCompoundValue_Operation_toString() const
{
	return m_compoundValue_Operation_toString;
}

// End Class CompoundValue

// Begin Class DataValue
std::shared_ptr<ecore::EClass> SimpleClassifiersPackageImpl::getDataValue_Class() const
{
	return m_dataValue_Class;
}


std::shared_ptr<ecore::EReference> SimpleClassifiersPackageImpl::getDataValue_Attribute_type() const
{
	return m_dataValue_Attribute_type;
}

std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getDataValue_Operation_getTypes() const
{
	return m_dataValue_Operation_getTypes;
}
std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getDataValue_Operation_new_() const
{
	return m_dataValue_Operation_new_;
}

// End Class DataValue

// Begin Class EnumerationValue
std::shared_ptr<ecore::EClass> SimpleClassifiersPackageImpl::getEnumerationValue_Class() const
{
	return m_enumerationValue_Class;
}


std::shared_ptr<ecore::EReference> SimpleClassifiersPackageImpl::getEnumerationValue_Attribute_literal() const
{
	return m_enumerationValue_Attribute_literal;
}
std::shared_ptr<ecore::EReference> SimpleClassifiersPackageImpl::getEnumerationValue_Attribute_type() const
{
	return m_enumerationValue_Attribute_type;
}

std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getEnumerationValue_Operation_equals_Value() const
{
	return m_enumerationValue_Operation_equals_Value;
}
std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getEnumerationValue_Operation_getTypes() const
{
	return m_enumerationValue_Operation_getTypes;
}
std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getEnumerationValue_Operation_new_() const
{
	return m_enumerationValue_Operation_new_;
}
std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getEnumerationValue_Operation_specify() const
{
	return m_enumerationValue_Operation_specify;
}
std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getEnumerationValue_Operation_toString() const
{
	return m_enumerationValue_Operation_toString;
}

// End Class EnumerationValue

// Begin Class FeatureValue
std::shared_ptr<ecore::EClass> SimpleClassifiersPackageImpl::getFeatureValue_Class() const
{
	return m_featureValue_Class;
}

std::shared_ptr<ecore::EAttribute> SimpleClassifiersPackageImpl::getFeatureValue_Attribute_position() const
{
	return m_featureValue_Attribute_position;
}

std::shared_ptr<ecore::EReference> SimpleClassifiersPackageImpl::getFeatureValue_Attribute_feature() const
{
	return m_featureValue_Attribute_feature;
}
std::shared_ptr<ecore::EReference> SimpleClassifiersPackageImpl::getFeatureValue_Attribute_values() const
{
	return m_featureValue_Attribute_values;
}

std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getFeatureValue_Operation_hasEqualValues_FeatureValue() const
{
	return m_featureValue_Operation_hasEqualValues_FeatureValue;
}

// End Class FeatureValue

// Begin Class IntegerValue
std::shared_ptr<ecore::EClass> SimpleClassifiersPackageImpl::getIntegerValue_Class() const
{
	return m_integerValue_Class;
}

std::shared_ptr<ecore::EAttribute> SimpleClassifiersPackageImpl::getIntegerValue_Attribute_value() const
{
	return m_integerValue_Attribute_value;
}


std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getIntegerValue_Operation_equals_Value() const
{
	return m_integerValue_Operation_equals_Value;
}
std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getIntegerValue_Operation_specify() const
{
	return m_integerValue_Operation_specify;
}
std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getIntegerValue_Operation_toString() const
{
	return m_integerValue_Operation_toString;
}

// End Class IntegerValue

// Begin Class PrimitiveValue
std::shared_ptr<ecore::EClass> SimpleClassifiersPackageImpl::getPrimitiveValue_Class() const
{
	return m_primitiveValue_Class;
}


std::shared_ptr<ecore::EReference> SimpleClassifiersPackageImpl::getPrimitiveValue_Attribute_type() const
{
	return m_primitiveValue_Attribute_type;
}

std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getPrimitiveValue_Operation_getTypes() const
{
	return m_primitiveValue_Operation_getTypes;
}

// End Class PrimitiveValue

// Begin Class RealValue
std::shared_ptr<ecore::EClass> SimpleClassifiersPackageImpl::getRealValue_Class() const
{
	return m_realValue_Class;
}

std::shared_ptr<ecore::EAttribute> SimpleClassifiersPackageImpl::getRealValue_Attribute_value() const
{
	return m_realValue_Attribute_value;
}


std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getRealValue_Operation_equals_Value() const
{
	return m_realValue_Operation_equals_Value;
}
std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getRealValue_Operation_specify() const
{
	return m_realValue_Operation_specify;
}
std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getRealValue_Operation_toString() const
{
	return m_realValue_Operation_toString;
}

// End Class RealValue

// Begin Class SignalInstance
std::shared_ptr<ecore::EClass> SimpleClassifiersPackageImpl::getSignalInstance_Class() const
{
	return m_signalInstance_Class;
}


std::shared_ptr<ecore::EReference> SimpleClassifiersPackageImpl::getSignalInstance_Attribute_type() const
{
	return m_signalInstance_Attribute_type;
}


// End Class SignalInstance

// Begin Class StringValue
std::shared_ptr<ecore::EClass> SimpleClassifiersPackageImpl::getStringValue_Class() const
{
	return m_stringValue_Class;
}

std::shared_ptr<ecore::EAttribute> SimpleClassifiersPackageImpl::getStringValue_Attribute_value() const
{
	return m_stringValue_Attribute_value;
}


std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getStringValue_Operation_equals_Value() const
{
	return m_stringValue_Operation_equals_Value;
}
std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getStringValue_Operation_specify() const
{
	return m_stringValue_Operation_specify;
}
std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getStringValue_Operation_toString() const
{
	return m_stringValue_Operation_toString;
}

// End Class StringValue

// Begin Class StructuredValue
std::shared_ptr<ecore::EClass> SimpleClassifiersPackageImpl::getStructuredValue_Class() const
{
	return m_structuredValue_Class;
}



std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getStructuredValue_Operation_assignFeatureValue_StructuralFeature_EInt() const
{
	return m_structuredValue_Operation_assignFeatureValue_StructuralFeature_EInt;
}
std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getStructuredValue_Operation_createFeatureValues() const
{
	return m_structuredValue_Operation_createFeatureValues;
}
std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getStructuredValue_Operation_getValues_StructuralFeature_FeatureValue() const
{
	return m_structuredValue_Operation_getValues_StructuralFeature_FeatureValue;
}
std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getStructuredValue_Operation_removeValue_StructuralFeature_Value() const
{
	return m_structuredValue_Operation_removeValue_StructuralFeature_Value;
}
std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getStructuredValue_Operation_retrieveFeatureValue_StructuralFeature() const
{
	return m_structuredValue_Operation_retrieveFeatureValue_StructuralFeature;
}
std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getStructuredValue_Operation_retrieveFeatureValues() const
{
	return m_structuredValue_Operation_retrieveFeatureValues;
}
std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getStructuredValue_Operation_setFeatureValue_StructuralFeature_EInt() const
{
	return m_structuredValue_Operation_setFeatureValue_StructuralFeature_EInt;
}
std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getStructuredValue_Operation_specify() const
{
	return m_structuredValue_Operation_specify;
}

// End Class StructuredValue

// Begin Class UnlimitedNaturalValue
std::shared_ptr<ecore::EClass> SimpleClassifiersPackageImpl::getUnlimitedNaturalValue_Class() const
{
	return m_unlimitedNaturalValue_Class;
}

std::shared_ptr<ecore::EAttribute> SimpleClassifiersPackageImpl::getUnlimitedNaturalValue_Attribute_value() const
{
	return m_unlimitedNaturalValue_Attribute_value;
}


std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getUnlimitedNaturalValue_Operation_equals_Value() const
{
	return m_unlimitedNaturalValue_Operation_equals_Value;
}
std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getUnlimitedNaturalValue_Operation_specify() const
{
	return m_unlimitedNaturalValue_Operation_specify;
}
std::shared_ptr<ecore::EOperation> SimpleClassifiersPackageImpl::getUnlimitedNaturalValue_Operation_toString() const
{
	return m_unlimitedNaturalValue_Operation_toString;
}

// End Class UnlimitedNaturalValue

