#include "ecore/impl/ecorePackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EReference.hpp"
#include "ecore/ETypeParameter.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

//depending model packages
//include subpackages 
 
using namespace ecore;

void ecorePackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();

	createEAnnotationContent(package, factory);
	createEAttributeContent(package, factory);
	createEClassContent(package, factory);
	createEClassifierContent(package, factory);
	createEDataTypeContent(package, factory);
	createEEnumContent(package, factory);
	createEEnumLiteralContent(package, factory);
	createEFactoryContent(package, factory);
	createEGenericTypeContent(package, factory);
	createEModelElementContent(package, factory);
	createENamedElementContent(package, factory);
	createEObjectContent(package, factory);
	createEObjectContainerContent(package, factory);
	createEOperationContent(package, factory);
	createEPackageContent(package, factory);
	createEParameterContent(package, factory);
	createEReferenceContent(package, factory);
	createEStringToStringMapEntryContent(package, factory);
	createEStructuralFeatureContent(package, factory);
	createETypeParameterContent(package, factory);
	createETypedElementContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void ecorePackageImpl::createEAnnotationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_eAnnotation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EANNOTATION_CLASS);
	m_eAnnotation_Attribute_details = factory->createEAttribute_as_eAttributes_in_EClass(m_eAnnotation_Class, EANNOTATION_ATTRIBUTE_DETAILS);
	m_eAnnotation_Attribute_source = factory->createEAttribute_as_eAttributes_in_EClass(m_eAnnotation_Class, EANNOTATION_ATTRIBUTE_SOURCE);
	
	m_eAnnotation_Attribute_contents = factory->createEReference_as_eReferences_in_EClass(m_eAnnotation_Class, EANNOTATION_ATTRIBUTE_CONTENTS);
	m_eAnnotation_Attribute_eModelElement = factory->createEReference_as_eReferences_in_EClass(m_eAnnotation_Class, EANNOTATION_ATTRIBUTE_EMODELELEMENT);
	m_eAnnotation_Attribute_references = factory->createEReference_as_eReferences_in_EClass(m_eAnnotation_Class, EANNOTATION_ATTRIBUTE_REFERENCES);
	
	
}

void ecorePackageImpl::createEAttributeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_eAttribute_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EATTRIBUTE_CLASS);
	m_eAttribute_Attribute_iD = factory->createEAttribute_as_eAttributes_in_EClass(m_eAttribute_Class, EATTRIBUTE_ATTRIBUTE_ID);
	
	m_eAttribute_Attribute_eAttributeType = factory->createEReference_as_eReferences_in_EClass(m_eAttribute_Class, EATTRIBUTE_ATTRIBUTE_EATTRIBUTETYPE);
	
	
}

void ecorePackageImpl::createEClassContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_eClass_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ECLASS_CLASS);
	m_eClass_Attribute_abstract = factory->createEAttribute_as_eAttributes_in_EClass(m_eClass_Class, ECLASS_ATTRIBUTE_ABSTRACT);
	m_eClass_Attribute_interface = factory->createEAttribute_as_eAttributes_in_EClass(m_eClass_Class, ECLASS_ATTRIBUTE_INTERFACE);
	
	m_eClass_Attribute_eAllAttributes = factory->createEReference_as_eReferences_in_EClass(m_eClass_Class, ECLASS_ATTRIBUTE_EALLATTRIBUTES);
	m_eClass_Attribute_eAllContainments = factory->createEReference_as_eReferences_in_EClass(m_eClass_Class, ECLASS_ATTRIBUTE_EALLCONTAINMENTS);
	m_eClass_Attribute_eAllGenericSuperTypes = factory->createEReference_as_eReferences_in_EClass(m_eClass_Class, ECLASS_ATTRIBUTE_EALLGENERICSUPERTYPES);
	m_eClass_Attribute_eAllOperations = factory->createEReference_as_eReferences_in_EClass(m_eClass_Class, ECLASS_ATTRIBUTE_EALLOPERATIONS);
	m_eClass_Attribute_eAllReferences = factory->createEReference_as_eReferences_in_EClass(m_eClass_Class, ECLASS_ATTRIBUTE_EALLREFERENCES);
	m_eClass_Attribute_eAllStructuralFeatures = factory->createEReference_as_eReferences_in_EClass(m_eClass_Class, ECLASS_ATTRIBUTE_EALLSTRUCTURALFEATURES);
	m_eClass_Attribute_eAllSuperTypes = factory->createEReference_as_eReferences_in_EClass(m_eClass_Class, ECLASS_ATTRIBUTE_EALLSUPERTYPES);
	m_eClass_Attribute_eAttributes = factory->createEReference_as_eReferences_in_EClass(m_eClass_Class, ECLASS_ATTRIBUTE_EATTRIBUTES);
	m_eClass_Attribute_eGenericSuperTypes = factory->createEReference_as_eReferences_in_EClass(m_eClass_Class, ECLASS_ATTRIBUTE_EGENERICSUPERTYPES);
	m_eClass_Attribute_eIDAttribute = factory->createEReference_as_eReferences_in_EClass(m_eClass_Class, ECLASS_ATTRIBUTE_EIDATTRIBUTE);
	m_eClass_Attribute_eOperations = factory->createEReference_as_eReferences_in_EClass(m_eClass_Class, ECLASS_ATTRIBUTE_EOPERATIONS);
	m_eClass_Attribute_eReferences = factory->createEReference_as_eReferences_in_EClass(m_eClass_Class, ECLASS_ATTRIBUTE_EREFERENCES);
	m_eClass_Attribute_eStructuralFeatures = factory->createEReference_as_eReferences_in_EClass(m_eClass_Class, ECLASS_ATTRIBUTE_ESTRUCTURALFEATURES);
	m_eClass_Attribute_eSuperTypes = factory->createEReference_as_eReferences_in_EClass(m_eClass_Class, ECLASS_ATTRIBUTE_ESUPERTYPES);
	
	m_eClass_Operation_getEOperation_EInt = factory->createEOperation_as_eOperations_in_EClass(m_eClass_Class, ECLASS_OPERATION_GETEOPERATION_EINT);
	m_eClass_Operation_getEStructuralFeature_EInt = factory->createEOperation_as_eOperations_in_EClass(m_eClass_Class, ECLASS_OPERATION_GETESTRUCTURALFEATURE_EINT);
	m_eClass_Operation_getEStructuralFeature_EString = factory->createEOperation_as_eOperations_in_EClass(m_eClass_Class, ECLASS_OPERATION_GETESTRUCTURALFEATURE_ESTRING);
	m_eClass_Operation_getFeatureCount = factory->createEOperation_as_eOperations_in_EClass(m_eClass_Class, ECLASS_OPERATION_GETFEATURECOUNT);
	m_eClass_Operation_getFeatureID_EStructuralFeature = factory->createEOperation_as_eOperations_in_EClass(m_eClass_Class, ECLASS_OPERATION_GETFEATUREID_ESTRUCTURALFEATURE);
	m_eClass_Operation_getFeatureType_EStructuralFeature = factory->createEOperation_as_eOperations_in_EClass(m_eClass_Class, ECLASS_OPERATION_GETFEATURETYPE_ESTRUCTURALFEATURE);
	m_eClass_Operation_getOperationCount = factory->createEOperation_as_eOperations_in_EClass(m_eClass_Class, ECLASS_OPERATION_GETOPERATIONCOUNT);
	m_eClass_Operation_getOperationID_EOperation = factory->createEOperation_as_eOperations_in_EClass(m_eClass_Class, ECLASS_OPERATION_GETOPERATIONID_EOPERATION);
	m_eClass_Operation_getOverride_EOperation = factory->createEOperation_as_eOperations_in_EClass(m_eClass_Class, ECLASS_OPERATION_GETOVERRIDE_EOPERATION);
	m_eClass_Operation_isSuperTypeOf_EClass = factory->createEOperation_as_eOperations_in_EClass(m_eClass_Class, ECLASS_OPERATION_ISSUPERTYPEOF_ECLASS);
	
}

void ecorePackageImpl::createEClassifierContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_eClassifier_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ECLASSIFIER_CLASS);
	m_eClassifier_Attribute_defaultValue = factory->createEAttribute_as_eAttributes_in_EClass(m_eClassifier_Class, ECLASSIFIER_ATTRIBUTE_DEFAULTVALUE);
	m_eClassifier_Attribute_instanceClass = factory->createEAttribute_as_eAttributes_in_EClass(m_eClassifier_Class, ECLASSIFIER_ATTRIBUTE_INSTANCECLASS);
	m_eClassifier_Attribute_instanceClassName = factory->createEAttribute_as_eAttributes_in_EClass(m_eClassifier_Class, ECLASSIFIER_ATTRIBUTE_INSTANCECLASSNAME);
	m_eClassifier_Attribute_instanceTypeName = factory->createEAttribute_as_eAttributes_in_EClass(m_eClassifier_Class, ECLASSIFIER_ATTRIBUTE_INSTANCETYPENAME);
	
	m_eClassifier_Attribute_ePackage = factory->createEReference_as_eReferences_in_EClass(m_eClassifier_Class, ECLASSIFIER_ATTRIBUTE_EPACKAGE);
	m_eClassifier_Attribute_eTypeParameters = factory->createEReference_as_eReferences_in_EClass(m_eClassifier_Class, ECLASSIFIER_ATTRIBUTE_ETYPEPARAMETERS);
	
	m_eClassifier_Operation_getClassifierID = factory->createEOperation_as_eOperations_in_EClass(m_eClassifier_Class, ECLASSIFIER_OPERATION_GETCLASSIFIERID);
	m_eClassifier_Operation_isInstance_EJavaObject = factory->createEOperation_as_eOperations_in_EClass(m_eClassifier_Class, ECLASSIFIER_OPERATION_ISINSTANCE_EJAVAOBJECT);
	
}

void ecorePackageImpl::createEDataTypeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_eDataType_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EDATATYPE_CLASS);
	m_eDataType_Attribute_serializable = factory->createEAttribute_as_eAttributes_in_EClass(m_eDataType_Class, EDATATYPE_ATTRIBUTE_SERIALIZABLE);
	
	
	
}

void ecorePackageImpl::createEEnumContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_eEnum_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EENUM_CLASS);
	
	m_eEnum_Attribute_eLiterals = factory->createEReference_as_eReferences_in_EClass(m_eEnum_Class, EENUM_ATTRIBUTE_ELITERALS);
	
	m_eEnum_Operation_getEEnumLiteral_EString = factory->createEOperation_as_eOperations_in_EClass(m_eEnum_Class, EENUM_OPERATION_GETEENUMLITERAL_ESTRING);
	m_eEnum_Operation_getEEnumLiteral_EInt = factory->createEOperation_as_eOperations_in_EClass(m_eEnum_Class, EENUM_OPERATION_GETEENUMLITERAL_EINT);
	m_eEnum_Operation_getEEnumLiteralByLiteral_EString = factory->createEOperation_as_eOperations_in_EClass(m_eEnum_Class, EENUM_OPERATION_GETEENUMLITERALBYLITERAL_ESTRING);
	
}

void ecorePackageImpl::createEEnumLiteralContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_eEnumLiteral_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EENUMLITERAL_CLASS);
	m_eEnumLiteral_Attribute_instance = factory->createEAttribute_as_eAttributes_in_EClass(m_eEnumLiteral_Class, EENUMLITERAL_ATTRIBUTE_INSTANCE);
	m_eEnumLiteral_Attribute_literal = factory->createEAttribute_as_eAttributes_in_EClass(m_eEnumLiteral_Class, EENUMLITERAL_ATTRIBUTE_LITERAL);
	m_eEnumLiteral_Attribute_value = factory->createEAttribute_as_eAttributes_in_EClass(m_eEnumLiteral_Class, EENUMLITERAL_ATTRIBUTE_VALUE);
	
	m_eEnumLiteral_Attribute_eEnum = factory->createEReference_as_eReferences_in_EClass(m_eEnumLiteral_Class, EENUMLITERAL_ATTRIBUTE_EENUM);
	
	
}

void ecorePackageImpl::createEFactoryContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_eFactory_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EFACTORY_CLASS);
	
	m_eFactory_Attribute_ePackage = factory->createEReference_as_eReferences_in_EClass(m_eFactory_Class, EFACTORY_ATTRIBUTE_EPACKAGE);
	
	m_eFactory_Operation_convertToString_EDataType_EJavaObject = factory->createEOperation_as_eOperations_in_EClass(m_eFactory_Class, EFACTORY_OPERATION_CONVERTTOSTRING_EDATATYPE_EJAVAOBJECT);
	m_eFactory_Operation_create_EClass = factory->createEOperation_as_eOperations_in_EClass(m_eFactory_Class, EFACTORY_OPERATION_CREATE_ECLASS);
	m_eFactory_Operation_createFromString_EDataType_EString = factory->createEOperation_as_eOperations_in_EClass(m_eFactory_Class, EFACTORY_OPERATION_CREATEFROMSTRING_EDATATYPE_ESTRING);
	
}

void ecorePackageImpl::createEGenericTypeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_eGenericType_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EGENERICTYPE_CLASS);
	
	m_eGenericType_Attribute_eClassifier = factory->createEReference_as_eReferences_in_EClass(m_eGenericType_Class, EGENERICTYPE_ATTRIBUTE_ECLASSIFIER);
	m_eGenericType_Attribute_eLowerBound = factory->createEReference_as_eReferences_in_EClass(m_eGenericType_Class, EGENERICTYPE_ATTRIBUTE_ELOWERBOUND);
	m_eGenericType_Attribute_eRawType = factory->createEReference_as_eReferences_in_EClass(m_eGenericType_Class, EGENERICTYPE_ATTRIBUTE_ERAWTYPE);
	m_eGenericType_Attribute_eTypeArguments = factory->createEReference_as_eReferences_in_EClass(m_eGenericType_Class, EGENERICTYPE_ATTRIBUTE_ETYPEARGUMENTS);
	m_eGenericType_Attribute_eTypeParameter = factory->createEReference_as_eReferences_in_EClass(m_eGenericType_Class, EGENERICTYPE_ATTRIBUTE_ETYPEPARAMETER);
	m_eGenericType_Attribute_eUpperBound = factory->createEReference_as_eReferences_in_EClass(m_eGenericType_Class, EGENERICTYPE_ATTRIBUTE_EUPPERBOUND);
	
	m_eGenericType_Operation_isInstance_EJavaObject = factory->createEOperation_as_eOperations_in_EClass(m_eGenericType_Class, EGENERICTYPE_OPERATION_ISINSTANCE_EJAVAOBJECT);
	
}

void ecorePackageImpl::createEModelElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_eModelElement_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EMODELELEMENT_CLASS);
	
	m_eModelElement_Attribute_eAnnotations = factory->createEReference_as_eReferences_in_EClass(m_eModelElement_Class, EMODELELEMENT_ATTRIBUTE_EANNOTATIONS);
	
	m_eModelElement_Operation_getEAnnotation_EString = factory->createEOperation_as_eOperations_in_EClass(m_eModelElement_Class, EMODELELEMENT_OPERATION_GETEANNOTATION_ESTRING);
	
}

void ecorePackageImpl::createENamedElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_eNamedElement_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ENAMEDELEMENT_CLASS);
	m_eNamedElement_Attribute_name = factory->createEAttribute_as_eAttributes_in_EClass(m_eNamedElement_Class, ENAMEDELEMENT_ATTRIBUTE_NAME);
	
	
	
}

void ecorePackageImpl::createEObjectContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_eObject_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EOBJECT_CLASS);
	m_eObject_Attribute_metaElementID = factory->createEAttribute_as_eAttributes_in_EClass(m_eObject_Class, EOBJECT_ATTRIBUTE_METAELEMENTID);
	
	m_eObject_Attribute_eContainer = factory->createEReference_as_eReferences_in_EClass(m_eObject_Class, EOBJECT_ATTRIBUTE_ECONTAINER);
	m_eObject_Attribute_eContentUnion = factory->createEReference_as_eReferences_in_EClass(m_eObject_Class, EOBJECT_ATTRIBUTE_ECONTENTUNION);
	
	m_eObject_Operation_eAllContents = factory->createEOperation_as_eOperations_in_EClass(m_eObject_Class, EOBJECT_OPERATION_EALLCONTENTS);
	m_eObject_Operation_eClass = factory->createEOperation_as_eOperations_in_EClass(m_eObject_Class, EOBJECT_OPERATION_ECLASS);
	m_eObject_Operation_eContainer = factory->createEOperation_as_eOperations_in_EClass(m_eObject_Class, EOBJECT_OPERATION_ECONTAINER);
	m_eObject_Operation_eContainingFeature = factory->createEOperation_as_eOperations_in_EClass(m_eObject_Class, EOBJECT_OPERATION_ECONTAININGFEATURE);
	m_eObject_Operation_eContainmentFeature = factory->createEOperation_as_eOperations_in_EClass(m_eObject_Class, EOBJECT_OPERATION_ECONTAINMENTFEATURE);
	m_eObject_Operation_eContents = factory->createEOperation_as_eOperations_in_EClass(m_eObject_Class, EOBJECT_OPERATION_ECONTENTS);
	m_eObject_Operation_eCrossReferences = factory->createEOperation_as_eOperations_in_EClass(m_eObject_Class, EOBJECT_OPERATION_ECROSSREFERENCES);
	m_eObject_Operation_eGet_EStructuralFeature = factory->createEOperation_as_eOperations_in_EClass(m_eObject_Class, EOBJECT_OPERATION_EGET_ESTRUCTURALFEATURE);
	m_eObject_Operation_eGet_EStructuralFeature_EBoolean = factory->createEOperation_as_eOperations_in_EClass(m_eObject_Class, EOBJECT_OPERATION_EGET_ESTRUCTURALFEATURE_EBOOLEAN);
	m_eObject_Operation_eInvoke_EOperation_EEList = factory->createEOperation_as_eOperations_in_EClass(m_eObject_Class, EOBJECT_OPERATION_EINVOKE_EOPERATION_EELIST);
	m_eObject_Operation_eIsProxy = factory->createEOperation_as_eOperations_in_EClass(m_eObject_Class, EOBJECT_OPERATION_EISPROXY);
	m_eObject_Operation_eIsSet_EStructuralFeature = factory->createEOperation_as_eOperations_in_EClass(m_eObject_Class, EOBJECT_OPERATION_EISSET_ESTRUCTURALFEATURE);
	m_eObject_Operation_eResource = factory->createEOperation_as_eOperations_in_EClass(m_eObject_Class, EOBJECT_OPERATION_ERESOURCE);
	m_eObject_Operation_eSet_EStructuralFeature_EJavaObject = factory->createEOperation_as_eOperations_in_EClass(m_eObject_Class, EOBJECT_OPERATION_ESET_ESTRUCTURALFEATURE_EJAVAOBJECT);
	m_eObject_Operation_eUnset_EStructuralFeature = factory->createEOperation_as_eOperations_in_EClass(m_eObject_Class, EOBJECT_OPERATION_EUNSET_ESTRUCTURALFEATURE);
	
}

void ecorePackageImpl::createEObjectContainerContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_eObjectContainer_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EOBJECTCONTAINER_CLASS);
	
	m_eObjectContainer_Attribute_container = factory->createEReference_as_eReferences_in_EClass(m_eObjectContainer_Class, EOBJECTCONTAINER_ATTRIBUTE_CONTAINER);
	
	
}

void ecorePackageImpl::createEOperationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_eOperation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EOPERATION_CLASS);
	m_eOperation_Attribute_operationID = factory->createEAttribute_as_eAttributes_in_EClass(m_eOperation_Class, EOPERATION_ATTRIBUTE_OPERATIONID);
	
	m_eOperation_Attribute_eContainingClass = factory->createEReference_as_eReferences_in_EClass(m_eOperation_Class, EOPERATION_ATTRIBUTE_ECONTAININGCLASS);
	m_eOperation_Attribute_eExceptions = factory->createEReference_as_eReferences_in_EClass(m_eOperation_Class, EOPERATION_ATTRIBUTE_EEXCEPTIONS);
	m_eOperation_Attribute_eGenericExceptions = factory->createEReference_as_eReferences_in_EClass(m_eOperation_Class, EOPERATION_ATTRIBUTE_EGENERICEXCEPTIONS);
	m_eOperation_Attribute_eParameters = factory->createEReference_as_eReferences_in_EClass(m_eOperation_Class, EOPERATION_ATTRIBUTE_EPARAMETERS);
	m_eOperation_Attribute_eTypeParameters = factory->createEReference_as_eReferences_in_EClass(m_eOperation_Class, EOPERATION_ATTRIBUTE_ETYPEPARAMETERS);
	
	m_eOperation_Operation_isOverrideOf_EOperation = factory->createEOperation_as_eOperations_in_EClass(m_eOperation_Class, EOPERATION_OPERATION_ISOVERRIDEOF_EOPERATION);
	
}

void ecorePackageImpl::createEPackageContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_ePackage_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EPACKAGE_CLASS);
	m_ePackage_Attribute_nsPrefix = factory->createEAttribute_as_eAttributes_in_EClass(m_ePackage_Class, EPACKAGE_ATTRIBUTE_NSPREFIX);
	m_ePackage_Attribute_nsURI = factory->createEAttribute_as_eAttributes_in_EClass(m_ePackage_Class, EPACKAGE_ATTRIBUTE_NSURI);
	
	m_ePackage_Attribute_eClassifiers = factory->createEReference_as_eReferences_in_EClass(m_ePackage_Class, EPACKAGE_ATTRIBUTE_ECLASSIFIERS);
	m_ePackage_Attribute_eFactoryInstance = factory->createEReference_as_eReferences_in_EClass(m_ePackage_Class, EPACKAGE_ATTRIBUTE_EFACTORYINSTANCE);
	m_ePackage_Attribute_eSubpackages = factory->createEReference_as_eReferences_in_EClass(m_ePackage_Class, EPACKAGE_ATTRIBUTE_ESUBPACKAGES);
	m_ePackage_Attribute_eSuperPackage = factory->createEReference_as_eReferences_in_EClass(m_ePackage_Class, EPACKAGE_ATTRIBUTE_ESUPERPACKAGE);
	
	m_ePackage_Operation_getEClassifier_EString = factory->createEOperation_as_eOperations_in_EClass(m_ePackage_Class, EPACKAGE_OPERATION_GETECLASSIFIER_ESTRING);
	
}

void ecorePackageImpl::createEParameterContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_eParameter_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EPARAMETER_CLASS);
	
	m_eParameter_Attribute_eOperation = factory->createEReference_as_eReferences_in_EClass(m_eParameter_Class, EPARAMETER_ATTRIBUTE_EOPERATION);
	
	
}

void ecorePackageImpl::createEReferenceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_eReference_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EREFERENCE_CLASS);
	m_eReference_Attribute_container = factory->createEAttribute_as_eAttributes_in_EClass(m_eReference_Class, EREFERENCE_ATTRIBUTE_CONTAINER);
	m_eReference_Attribute_containment = factory->createEAttribute_as_eAttributes_in_EClass(m_eReference_Class, EREFERENCE_ATTRIBUTE_CONTAINMENT);
	m_eReference_Attribute_resolveProxies = factory->createEAttribute_as_eAttributes_in_EClass(m_eReference_Class, EREFERENCE_ATTRIBUTE_RESOLVEPROXIES);
	
	m_eReference_Attribute_eKeys = factory->createEReference_as_eReferences_in_EClass(m_eReference_Class, EREFERENCE_ATTRIBUTE_EKEYS);
	m_eReference_Attribute_eOpposite = factory->createEReference_as_eReferences_in_EClass(m_eReference_Class, EREFERENCE_ATTRIBUTE_EOPPOSITE);
	m_eReference_Attribute_eReferenceType = factory->createEReference_as_eReferences_in_EClass(m_eReference_Class, EREFERENCE_ATTRIBUTE_EREFERENCETYPE);
	
	
}

void ecorePackageImpl::createEStringToStringMapEntryContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_eStringToStringMapEntry_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ESTRINGTOSTRINGMAPENTRY_CLASS);
	m_eStringToStringMapEntry_Attribute_key = factory->createEAttribute_as_eAttributes_in_EClass(m_eStringToStringMapEntry_Class, ESTRINGTOSTRINGMAPENTRY_ATTRIBUTE_KEY);
	m_eStringToStringMapEntry_Attribute_value = factory->createEAttribute_as_eAttributes_in_EClass(m_eStringToStringMapEntry_Class, ESTRINGTOSTRINGMAPENTRY_ATTRIBUTE_VALUE);
	
	
	
}

void ecorePackageImpl::createEStructuralFeatureContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_eStructuralFeature_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ESTRUCTURALFEATURE_CLASS);
	m_eStructuralFeature_Attribute_changeable = factory->createEAttribute_as_eAttributes_in_EClass(m_eStructuralFeature_Class, ESTRUCTURALFEATURE_ATTRIBUTE_CHANGEABLE);
	m_eStructuralFeature_Attribute_defaultValue = factory->createEAttribute_as_eAttributes_in_EClass(m_eStructuralFeature_Class, ESTRUCTURALFEATURE_ATTRIBUTE_DEFAULTVALUE);
	m_eStructuralFeature_Attribute_defaultValueLiteral = factory->createEAttribute_as_eAttributes_in_EClass(m_eStructuralFeature_Class, ESTRUCTURALFEATURE_ATTRIBUTE_DEFAULTVALUELITERAL);
	m_eStructuralFeature_Attribute_derived = factory->createEAttribute_as_eAttributes_in_EClass(m_eStructuralFeature_Class, ESTRUCTURALFEATURE_ATTRIBUTE_DERIVED);
	m_eStructuralFeature_Attribute_featureID = factory->createEAttribute_as_eAttributes_in_EClass(m_eStructuralFeature_Class, ESTRUCTURALFEATURE_ATTRIBUTE_FEATUREID);
	m_eStructuralFeature_Attribute_transient = factory->createEAttribute_as_eAttributes_in_EClass(m_eStructuralFeature_Class, ESTRUCTURALFEATURE_ATTRIBUTE_TRANSIENT);
	m_eStructuralFeature_Attribute_unsettable = factory->createEAttribute_as_eAttributes_in_EClass(m_eStructuralFeature_Class, ESTRUCTURALFEATURE_ATTRIBUTE_UNSETTABLE);
	m_eStructuralFeature_Attribute_volatile = factory->createEAttribute_as_eAttributes_in_EClass(m_eStructuralFeature_Class, ESTRUCTURALFEATURE_ATTRIBUTE_VOLATILE);
	
	m_eStructuralFeature_Attribute_eContainingClass = factory->createEReference_as_eReferences_in_EClass(m_eStructuralFeature_Class, ESTRUCTURALFEATURE_ATTRIBUTE_ECONTAININGCLASS);
	
	m_eStructuralFeature_Operation_getContainerClass = factory->createEOperation_as_eOperations_in_EClass(m_eStructuralFeature_Class, ESTRUCTURALFEATURE_OPERATION_GETCONTAINERCLASS);
	
}

void ecorePackageImpl::createETypeParameterContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_eTypeParameter_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ETYPEPARAMETER_CLASS);
	
	m_eTypeParameter_Attribute_eBounds = factory->createEReference_as_eReferences_in_EClass(m_eTypeParameter_Class, ETYPEPARAMETER_ATTRIBUTE_EBOUNDS);
	
	
}

void ecorePackageImpl::createETypedElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_eTypedElement_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ETYPEDELEMENT_CLASS);
	m_eTypedElement_Attribute_lowerBound = factory->createEAttribute_as_eAttributes_in_EClass(m_eTypedElement_Class, ETYPEDELEMENT_ATTRIBUTE_LOWERBOUND);
	m_eTypedElement_Attribute_many = factory->createEAttribute_as_eAttributes_in_EClass(m_eTypedElement_Class, ETYPEDELEMENT_ATTRIBUTE_MANY);
	m_eTypedElement_Attribute_ordered = factory->createEAttribute_as_eAttributes_in_EClass(m_eTypedElement_Class, ETYPEDELEMENT_ATTRIBUTE_ORDERED);
	m_eTypedElement_Attribute_required = factory->createEAttribute_as_eAttributes_in_EClass(m_eTypedElement_Class, ETYPEDELEMENT_ATTRIBUTE_REQUIRED);
	m_eTypedElement_Attribute_unique = factory->createEAttribute_as_eAttributes_in_EClass(m_eTypedElement_Class, ETYPEDELEMENT_ATTRIBUTE_UNIQUE);
	m_eTypedElement_Attribute_upperBound = factory->createEAttribute_as_eAttributes_in_EClass(m_eTypedElement_Class, ETYPEDELEMENT_ATTRIBUTE_UPPERBOUND);
	
	m_eTypedElement_Attribute_eGenericType = factory->createEReference_as_eReferences_in_EClass(m_eTypedElement_Class, ETYPEDELEMENT_ATTRIBUTE_EGENERICTYPE);
	m_eTypedElement_Attribute_eType = factory->createEReference_as_eReferences_in_EClass(m_eTypedElement_Class, ETYPEDELEMENT_ATTRIBUTE_ETYPE);
	
	
}

void ecorePackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_eBigDecimal_Class = factory->createEDataType_as_eClassifiers_in_EPackage(package, EBIGDECIMAL_CLASS);
	m_eBigInteger_Class = factory->createEDataType_as_eClassifiers_in_EPackage(package, EBIGINTEGER_CLASS);
	m_eBoolean_Class = factory->createEDataType_as_eClassifiers_in_EPackage(package, EBOOLEAN_CLASS);
	m_eBooleanObject_Class = factory->createEDataType_as_eClassifiers_in_EPackage(package, EBOOLEANOBJECT_CLASS);
	m_eByte_Class = factory->createEDataType_as_eClassifiers_in_EPackage(package, EBYTE_CLASS);
	m_eByteArray_Class = factory->createEDataType_as_eClassifiers_in_EPackage(package, EBYTEARRAY_CLASS);
	m_eByteObject_Class = factory->createEDataType_as_eClassifiers_in_EPackage(package, EBYTEOBJECT_CLASS);
	m_eChar_Class = factory->createEDataType_as_eClassifiers_in_EPackage(package, ECHAR_CLASS);
	m_eCharacterObject_Class = factory->createEDataType_as_eClassifiers_in_EPackage(package, ECHARACTEROBJECT_CLASS);
	m_eDate_Class = factory->createEDataType_as_eClassifiers_in_EPackage(package, EDATE_CLASS);
	m_eDiagnosticChain_Class = factory->createEDataType_as_eClassifiers_in_EPackage(package, EDIAGNOSTICCHAIN_CLASS);
	m_eDouble_Class = factory->createEDataType_as_eClassifiers_in_EPackage(package, EDOUBLE_CLASS);
	m_eDoubleObject_Class = factory->createEDataType_as_eClassifiers_in_EPackage(package, EDOUBLEOBJECT_CLASS);
	m_eEList_Class = factory->createEDataType_as_eClassifiers_in_EPackage(package, EELIST_CLASS);
	m_eEnumerator_Class = factory->createEDataType_as_eClassifiers_in_EPackage(package, EENUMERATOR_CLASS);
	m_eFeatureMap_Class = factory->createEDataType_as_eClassifiers_in_EPackage(package, EFEATUREMAP_CLASS);
	m_eFeatureMapEntry_Class = factory->createEDataType_as_eClassifiers_in_EPackage(package, EFEATUREMAPENTRY_CLASS);
	m_eFloat_Class = factory->createEDataType_as_eClassifiers_in_EPackage(package, EFLOAT_CLASS);
	m_eFloatObject_Class = factory->createEDataType_as_eClassifiers_in_EPackage(package, EFLOATOBJECT_CLASS);
	m_eInt_Class = factory->createEDataType_as_eClassifiers_in_EPackage(package, EINT_CLASS);
	m_eIntegerObject_Class = factory->createEDataType_as_eClassifiers_in_EPackage(package, EINTEGEROBJECT_CLASS);
	m_eInvocationTargetException_Class = factory->createEDataType_as_eClassifiers_in_EPackage(package, EINVOCATIONTARGETEXCEPTION_CLASS);
	m_eJavaClass_Class = factory->createEDataType_as_eClassifiers_in_EPackage(package, EJAVACLASS_CLASS);
	m_eJavaObject_Class = factory->createEDataType_as_eClassifiers_in_EPackage(package, EJAVAOBJECT_CLASS);
	m_eLong_Class = factory->createEDataType_as_eClassifiers_in_EPackage(package, ELONG_CLASS);
	m_eLongObject_Class = factory->createEDataType_as_eClassifiers_in_EPackage(package, ELONGOBJECT_CLASS);
	m_eMap_Class = factory->createEDataType_as_eClassifiers_in_EPackage(package, EMAP_CLASS);
	m_eResource_Class = factory->createEDataType_as_eClassifiers_in_EPackage(package, ERESOURCE_CLASS);
	m_eResourceSet_Class = factory->createEDataType_as_eClassifiers_in_EPackage(package, ERESOURCESET_CLASS);
	m_eShort_Class = factory->createEDataType_as_eClassifiers_in_EPackage(package, ESHORT_CLASS);
	m_eShortObject_Class = factory->createEDataType_as_eClassifiers_in_EPackage(package, ESHORTOBJECT_CLASS);
	m_eString_Class = factory->createEDataType_as_eClassifiers_in_EPackage(package, ESTRING_CLASS);
	m_eTreeIterator_Class = factory->createEDataType_as_eClassifiers_in_EPackage(package, ETREEITERATOR_CLASS);
	
}
