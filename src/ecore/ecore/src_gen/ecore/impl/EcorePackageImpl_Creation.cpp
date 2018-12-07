#include "ecore/impl/EcorePackageImpl.hpp"

// metametamodel factory
#include "ecore/EcoreFactory.hpp"

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
#include "ecore/ETypeParameter.hpp"

//depending model packages

using namespace ecore;

void EcorePackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::EcoreFactory> factory = ecore::EcoreFactory::eInstance();

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

void EcorePackageImpl::createEAnnotationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_eAnnotation_EClass = factory->createEClass_in_EPackage(package, EANNOTATION_ECLASS);
	m_eAnnotation_EAttribute_source = factory->createEAttribute_in_EContainingClass(m_eAnnotation_EClass, EANNOTATION_EATTRIBUTE_SOURCE);
	
	m_eAnnotation_EReference_contents = factory->createEReference_in_EContainingClass(m_eAnnotation_EClass, EANNOTATION_EREFERENCE_CONTENTS);
	m_eAnnotation_EReference_details = factory->createEReference_in_EContainingClass(m_eAnnotation_EClass, EANNOTATION_EREFERENCE_DETAILS);
	m_eAnnotation_EReference_eModelElement = factory->createEReference_in_EContainingClass(m_eAnnotation_EClass, EANNOTATION_EREFERENCE_EMODELELEMENT);
	m_eAnnotation_EReference_references = factory->createEReference_in_EContainingClass(m_eAnnotation_EClass, EANNOTATION_EREFERENCE_REFERENCES);
	
	
}

void EcorePackageImpl::createEAttributeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_eAttribute_EClass = factory->createEClass_in_EPackage(package, EATTRIBUTE_ECLASS);
	m_eAttribute_EAttribute_iD = factory->createEAttribute_in_EContainingClass(m_eAttribute_EClass, EATTRIBUTE_EATTRIBUTE_ID);
	
	m_eAttribute_EReference_eAttributeType = factory->createEReference_in_EContainingClass(m_eAttribute_EClass, EATTRIBUTE_EREFERENCE_EATTRIBUTETYPE);
	
	
}

void EcorePackageImpl::createEClassContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_eClass_EClass = factory->createEClass_in_EPackage(package, ECLASS_ECLASS);
	m_eClass_EAttribute_abstract = factory->createEAttribute_in_EContainingClass(m_eClass_EClass, ECLASS_EATTRIBUTE_ABSTRACT);
	m_eClass_EAttribute_interface = factory->createEAttribute_in_EContainingClass(m_eClass_EClass, ECLASS_EATTRIBUTE_INTERFACE);
	
	m_eClass_EReference_eAllAttributes = factory->createEReference_in_EContainingClass(m_eClass_EClass, ECLASS_EREFERENCE_EALLATTRIBUTES);
	m_eClass_EReference_eAllContainments = factory->createEReference_in_EContainingClass(m_eClass_EClass, ECLASS_EREFERENCE_EALLCONTAINMENTS);
	m_eClass_EReference_eAllGenericSuperTypes = factory->createEReference_in_EContainingClass(m_eClass_EClass, ECLASS_EREFERENCE_EALLGENERICSUPERTYPES);
	m_eClass_EReference_eAllOperations = factory->createEReference_in_EContainingClass(m_eClass_EClass, ECLASS_EREFERENCE_EALLOPERATIONS);
	m_eClass_EReference_eAllReferences = factory->createEReference_in_EContainingClass(m_eClass_EClass, ECLASS_EREFERENCE_EALLREFERENCES);
	m_eClass_EReference_eAllStructuralFeatures = factory->createEReference_in_EContainingClass(m_eClass_EClass, ECLASS_EREFERENCE_EALLSTRUCTURALFEATURES);
	m_eClass_EReference_eAllSuperTypes = factory->createEReference_in_EContainingClass(m_eClass_EClass, ECLASS_EREFERENCE_EALLSUPERTYPES);
	m_eClass_EReference_eAttributes = factory->createEReference_in_EContainingClass(m_eClass_EClass, ECLASS_EREFERENCE_EATTRIBUTES);
	m_eClass_EReference_eGenericSuperTypes = factory->createEReference_in_EContainingClass(m_eClass_EClass, ECLASS_EREFERENCE_EGENERICSUPERTYPES);
	m_eClass_EReference_eIDAttribute = factory->createEReference_in_EContainingClass(m_eClass_EClass, ECLASS_EREFERENCE_EIDATTRIBUTE);
	m_eClass_EReference_eOperations = factory->createEReference_in_EContainingClass(m_eClass_EClass, ECLASS_EREFERENCE_EOPERATIONS);
	m_eClass_EReference_eReferences = factory->createEReference_in_EContainingClass(m_eClass_EClass, ECLASS_EREFERENCE_EREFERENCES);
	m_eClass_EReference_eStructuralFeatures = factory->createEReference_in_EContainingClass(m_eClass_EClass, ECLASS_EREFERENCE_ESTRUCTURALFEATURES);
	m_eClass_EReference_eSuperTypes = factory->createEReference_in_EContainingClass(m_eClass_EClass, ECLASS_EREFERENCE_ESUPERTYPES);
	
	m_eClass_EOperation_getEOperation_EInt = factory->createEOperation_in_EContainingClass(m_eClass_EClass, ECLASS_EOPERATION_GETEOPERATION_EINT);
	m_eClass_EOperation_getEStructuralFeature_EInt = factory->createEOperation_in_EContainingClass(m_eClass_EClass, ECLASS_EOPERATION_GETESTRUCTURALFEATURE_EINT);
	m_eClass_EOperation_getEStructuralFeature_EString = factory->createEOperation_in_EContainingClass(m_eClass_EClass, ECLASS_EOPERATION_GETESTRUCTURALFEATURE_ESTRING);
	m_eClass_EOperation_getFeatureCount = factory->createEOperation_in_EContainingClass(m_eClass_EClass, ECLASS_EOPERATION_GETFEATURECOUNT);
	m_eClass_EOperation_getFeatureID_EStructuralFeature = factory->createEOperation_in_EContainingClass(m_eClass_EClass, ECLASS_EOPERATION_GETFEATUREID_ESTRUCTURALFEATURE);
	m_eClass_EOperation_getFeatureType_EStructuralFeature = factory->createEOperation_in_EContainingClass(m_eClass_EClass, ECLASS_EOPERATION_GETFEATURETYPE_ESTRUCTURALFEATURE);
	m_eClass_EOperation_getOperationCount = factory->createEOperation_in_EContainingClass(m_eClass_EClass, ECLASS_EOPERATION_GETOPERATIONCOUNT);
	m_eClass_EOperation_getOperationID_EOperation = factory->createEOperation_in_EContainingClass(m_eClass_EClass, ECLASS_EOPERATION_GETOPERATIONID_EOPERATION);
	m_eClass_EOperation_getOverride_EOperation = factory->createEOperation_in_EContainingClass(m_eClass_EClass, ECLASS_EOPERATION_GETOVERRIDE_EOPERATION);
	m_eClass_EOperation_isSuperTypeOf_EClass = factory->createEOperation_in_EContainingClass(m_eClass_EClass, ECLASS_EOPERATION_ISSUPERTYPEOF_ECLASS);
	
}

void EcorePackageImpl::createEClassifierContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_eClassifier_EClass = factory->createEClass_in_EPackage(package, ECLASSIFIER_ECLASS);
	m_eClassifier_EAttribute_classifierID = factory->createEAttribute_in_EContainingClass(m_eClassifier_EClass, ECLASSIFIER_EATTRIBUTE_CLASSIFIERID);
	m_eClassifier_EAttribute_defaultValue = factory->createEAttribute_in_EContainingClass(m_eClassifier_EClass, ECLASSIFIER_EATTRIBUTE_DEFAULTVALUE);
	m_eClassifier_EAttribute_instanceClass = factory->createEAttribute_in_EContainingClass(m_eClassifier_EClass, ECLASSIFIER_EATTRIBUTE_INSTANCECLASS);
	m_eClassifier_EAttribute_instanceClassName = factory->createEAttribute_in_EContainingClass(m_eClassifier_EClass, ECLASSIFIER_EATTRIBUTE_INSTANCECLASSNAME);
	m_eClassifier_EAttribute_instanceTypeName = factory->createEAttribute_in_EContainingClass(m_eClassifier_EClass, ECLASSIFIER_EATTRIBUTE_INSTANCETYPENAME);
	
	m_eClassifier_EReference_ePackage = factory->createEReference_in_EContainingClass(m_eClassifier_EClass, ECLASSIFIER_EREFERENCE_EPACKAGE);
	m_eClassifier_EReference_eTypeParameters = factory->createEReference_in_EContainingClass(m_eClassifier_EClass, ECLASSIFIER_EREFERENCE_ETYPEPARAMETERS);
	
	m_eClassifier_EOperation_getClassifierID = factory->createEOperation_in_EContainingClass(m_eClassifier_EClass, ECLASSIFIER_EOPERATION_GETCLASSIFIERID);
	m_eClassifier_EOperation_isInstance_EJavaObject = factory->createEOperation_in_EContainingClass(m_eClassifier_EClass, ECLASSIFIER_EOPERATION_ISINSTANCE_EJAVAOBJECT);
	
}

void EcorePackageImpl::createEDataTypeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_eDataType_EClass = factory->createEClass_in_EPackage(package, EDATATYPE_ECLASS);
	m_eDataType_EAttribute_serializable = factory->createEAttribute_in_EContainingClass(m_eDataType_EClass, EDATATYPE_EATTRIBUTE_SERIALIZABLE);
	
	
	
}

void EcorePackageImpl::createEEnumContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_eEnum_EClass = factory->createEClass_in_EPackage(package, EENUM_ECLASS);
	
	m_eEnum_EReference_eLiterals = factory->createEReference_in_EContainingClass(m_eEnum_EClass, EENUM_EREFERENCE_ELITERALS);
	
	m_eEnum_EOperation_getEEnumLiteral_EString = factory->createEOperation_in_EContainingClass(m_eEnum_EClass, EENUM_EOPERATION_GETEENUMLITERAL_ESTRING);
	m_eEnum_EOperation_getEEnumLiteral_EInt = factory->createEOperation_in_EContainingClass(m_eEnum_EClass, EENUM_EOPERATION_GETEENUMLITERAL_EINT);
	m_eEnum_EOperation_getEEnumLiteralByLiteral_EString = factory->createEOperation_in_EContainingClass(m_eEnum_EClass, EENUM_EOPERATION_GETEENUMLITERALBYLITERAL_ESTRING);
	
}

void EcorePackageImpl::createEEnumLiteralContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_eEnumLiteral_EClass = factory->createEClass_in_EPackage(package, EENUMLITERAL_ECLASS);
	m_eEnumLiteral_EAttribute_instance = factory->createEAttribute_in_EContainingClass(m_eEnumLiteral_EClass, EENUMLITERAL_EATTRIBUTE_INSTANCE);
	m_eEnumLiteral_EAttribute_literal = factory->createEAttribute_in_EContainingClass(m_eEnumLiteral_EClass, EENUMLITERAL_EATTRIBUTE_LITERAL);
	m_eEnumLiteral_EAttribute_value = factory->createEAttribute_in_EContainingClass(m_eEnumLiteral_EClass, EENUMLITERAL_EATTRIBUTE_VALUE);
	
	m_eEnumLiteral_EReference_eEnum = factory->createEReference_in_EContainingClass(m_eEnumLiteral_EClass, EENUMLITERAL_EREFERENCE_EENUM);
	
	
}

void EcorePackageImpl::createEFactoryContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_eFactory_EClass = factory->createEClass_in_EPackage(package, EFACTORY_ECLASS);
	
	m_eFactory_EReference_ePackage = factory->createEReference_in_EContainingClass(m_eFactory_EClass, EFACTORY_EREFERENCE_EPACKAGE);
	
	m_eFactory_EOperation_convertToString_EDataType_EJavaObject = factory->createEOperation_in_EContainingClass(m_eFactory_EClass, EFACTORY_EOPERATION_CONVERTTOSTRING_EDATATYPE_EJAVAOBJECT);
	m_eFactory_EOperation_create_EClass = factory->createEOperation_in_EContainingClass(m_eFactory_EClass, EFACTORY_EOPERATION_CREATE_ECLASS);
	m_eFactory_EOperation_createFromString_EDataType_EString = factory->createEOperation_in_EContainingClass(m_eFactory_EClass, EFACTORY_EOPERATION_CREATEFROMSTRING_EDATATYPE_ESTRING);
	
}

void EcorePackageImpl::createEGenericTypeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_eGenericType_EClass = factory->createEClass_in_EPackage(package, EGENERICTYPE_ECLASS);
	
	m_eGenericType_EReference_eClassifier = factory->createEReference_in_EContainingClass(m_eGenericType_EClass, EGENERICTYPE_EREFERENCE_ECLASSIFIER);
	m_eGenericType_EReference_eLowerBound = factory->createEReference_in_EContainingClass(m_eGenericType_EClass, EGENERICTYPE_EREFERENCE_ELOWERBOUND);
	m_eGenericType_EReference_eRawType = factory->createEReference_in_EContainingClass(m_eGenericType_EClass, EGENERICTYPE_EREFERENCE_ERAWTYPE);
	m_eGenericType_EReference_eTypeArguments = factory->createEReference_in_EContainingClass(m_eGenericType_EClass, EGENERICTYPE_EREFERENCE_ETYPEARGUMENTS);
	m_eGenericType_EReference_eTypeParameter = factory->createEReference_in_EContainingClass(m_eGenericType_EClass, EGENERICTYPE_EREFERENCE_ETYPEPARAMETER);
	m_eGenericType_EReference_eUpperBound = factory->createEReference_in_EContainingClass(m_eGenericType_EClass, EGENERICTYPE_EREFERENCE_EUPPERBOUND);
	
	m_eGenericType_EOperation_isInstance_EJavaObject = factory->createEOperation_in_EContainingClass(m_eGenericType_EClass, EGENERICTYPE_EOPERATION_ISINSTANCE_EJAVAOBJECT);
	
}

void EcorePackageImpl::createEModelElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_eModelElement_EClass = factory->createEClass_in_EPackage(package, EMODELELEMENT_ECLASS);
	
	m_eModelElement_EReference_eAnnotations = factory->createEReference_in_EContainingClass(m_eModelElement_EClass, EMODELELEMENT_EREFERENCE_EANNOTATIONS);
	
	m_eModelElement_EOperation_getEAnnotation_EString = factory->createEOperation_in_EContainingClass(m_eModelElement_EClass, EMODELELEMENT_EOPERATION_GETEANNOTATION_ESTRING);
	
}

void EcorePackageImpl::createENamedElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_eNamedElement_EClass = factory->createEClass_in_EPackage(package, ENAMEDELEMENT_ECLASS);
	m_eNamedElement_EAttribute_name = factory->createEAttribute_in_EContainingClass(m_eNamedElement_EClass, ENAMEDELEMENT_EATTRIBUTE_NAME);
	
	
	
}

void EcorePackageImpl::createEObjectContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_eObject_EClass = factory->createEClass_in_EPackage(package, EOBJECT_ECLASS);
	
	m_eObject_EReference_eContainer = factory->createEReference_in_EContainingClass(m_eObject_EClass, EOBJECT_EREFERENCE_ECONTAINER);
	m_eObject_EReference_eContens = factory->createEReference_in_EContainingClass(m_eObject_EClass, EOBJECT_EREFERENCE_ECONTENS);
	
	m_eObject_EOperation_eAllContents = factory->createEOperation_in_EContainingClass(m_eObject_EClass, EOBJECT_EOPERATION_EALLCONTENTS);
	m_eObject_EOperation_eClass = factory->createEOperation_in_EContainingClass(m_eObject_EClass, EOBJECT_EOPERATION_ECLASS);
	m_eObject_EOperation_eContainer = factory->createEOperation_in_EContainingClass(m_eObject_EClass, EOBJECT_EOPERATION_ECONTAINER);
	m_eObject_EOperation_eContainingFeature = factory->createEOperation_in_EContainingClass(m_eObject_EClass, EOBJECT_EOPERATION_ECONTAININGFEATURE);
	m_eObject_EOperation_eContainmentFeature = factory->createEOperation_in_EContainingClass(m_eObject_EClass, EOBJECT_EOPERATION_ECONTAINMENTFEATURE);
	m_eObject_EOperation_eContents = factory->createEOperation_in_EContainingClass(m_eObject_EClass, EOBJECT_EOPERATION_ECONTENTS);
	m_eObject_EOperation_eCrossReferences = factory->createEOperation_in_EContainingClass(m_eObject_EClass, EOBJECT_EOPERATION_ECROSSREFERENCES);
	m_eObject_EOperation_eGet_EStructuralFeature = factory->createEOperation_in_EContainingClass(m_eObject_EClass, EOBJECT_EOPERATION_EGET_ESTRUCTURALFEATURE);
	m_eObject_EOperation_eGet_EStructuralFeature_EBoolean = factory->createEOperation_in_EContainingClass(m_eObject_EClass, EOBJECT_EOPERATION_EGET_ESTRUCTURALFEATURE_EBOOLEAN);
	m_eObject_EOperation_eInvoke_EOperation_EEList = factory->createEOperation_in_EContainingClass(m_eObject_EClass, EOBJECT_EOPERATION_EINVOKE_EOPERATION_EELIST);
	m_eObject_EOperation_eIsProxy = factory->createEOperation_in_EContainingClass(m_eObject_EClass, EOBJECT_EOPERATION_EISPROXY);
	m_eObject_EOperation_eIsSet_EStructuralFeature = factory->createEOperation_in_EContainingClass(m_eObject_EClass, EOBJECT_EOPERATION_EISSET_ESTRUCTURALFEATURE);
	m_eObject_EOperation_eResource = factory->createEOperation_in_EContainingClass(m_eObject_EClass, EOBJECT_EOPERATION_ERESOURCE);
	m_eObject_EOperation_eSet_EStructuralFeature_EJavaObject = factory->createEOperation_in_EContainingClass(m_eObject_EClass, EOBJECT_EOPERATION_ESET_ESTRUCTURALFEATURE_EJAVAOBJECT);
	m_eObject_EOperation_eUnset_EStructuralFeature = factory->createEOperation_in_EContainingClass(m_eObject_EClass, EOBJECT_EOPERATION_EUNSET_ESTRUCTURALFEATURE);
	
}

void EcorePackageImpl::createEOperationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_eOperation_EClass = factory->createEClass_in_EPackage(package, EOPERATION_ECLASS);
	m_eOperation_EAttribute_operationID = factory->createEAttribute_in_EContainingClass(m_eOperation_EClass, EOPERATION_EATTRIBUTE_OPERATIONID);
	
	m_eOperation_EReference_eContainingClass = factory->createEReference_in_EContainingClass(m_eOperation_EClass, EOPERATION_EREFERENCE_ECONTAININGCLASS);
	m_eOperation_EReference_eExceptions = factory->createEReference_in_EContainingClass(m_eOperation_EClass, EOPERATION_EREFERENCE_EEXCEPTIONS);
	m_eOperation_EReference_eGenericExceptions = factory->createEReference_in_EContainingClass(m_eOperation_EClass, EOPERATION_EREFERENCE_EGENERICEXCEPTIONS);
	m_eOperation_EReference_eParameters = factory->createEReference_in_EContainingClass(m_eOperation_EClass, EOPERATION_EREFERENCE_EPARAMETERS);
	m_eOperation_EReference_eTypeParameters = factory->createEReference_in_EContainingClass(m_eOperation_EClass, EOPERATION_EREFERENCE_ETYPEPARAMETERS);
	
	m_eOperation_EOperation_getOperationID = factory->createEOperation_in_EContainingClass(m_eOperation_EClass, EOPERATION_EOPERATION_GETOPERATIONID);
	m_eOperation_EOperation_isOverrideOf_EOperation = factory->createEOperation_in_EContainingClass(m_eOperation_EClass, EOPERATION_EOPERATION_ISOVERRIDEOF_EOPERATION);
	
}

void EcorePackageImpl::createEPackageContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_ePackage_EClass = factory->createEClass_in_EPackage(package, EPACKAGE_ECLASS);
	m_ePackage_EAttribute_nsPrefix = factory->createEAttribute_in_EContainingClass(m_ePackage_EClass, EPACKAGE_EATTRIBUTE_NSPREFIX);
	m_ePackage_EAttribute_nsURI = factory->createEAttribute_in_EContainingClass(m_ePackage_EClass, EPACKAGE_EATTRIBUTE_NSURI);
	
	m_ePackage_EReference_eClassifiers = factory->createEReference_in_EContainingClass(m_ePackage_EClass, EPACKAGE_EREFERENCE_ECLASSIFIERS);
	m_ePackage_EReference_eFactoryInstance = factory->createEReference_in_EContainingClass(m_ePackage_EClass, EPACKAGE_EREFERENCE_EFACTORYINSTANCE);
	m_ePackage_EReference_eSubpackages = factory->createEReference_in_EContainingClass(m_ePackage_EClass, EPACKAGE_EREFERENCE_ESUBPACKAGES);
	m_ePackage_EReference_eSuperPackage = factory->createEReference_in_EContainingClass(m_ePackage_EClass, EPACKAGE_EREFERENCE_ESUPERPACKAGE);
	
	m_ePackage_EOperation_getEClassifier_EString = factory->createEOperation_in_EContainingClass(m_ePackage_EClass, EPACKAGE_EOPERATION_GETECLASSIFIER_ESTRING);
	
}

void EcorePackageImpl::createEParameterContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_eParameter_EClass = factory->createEClass_in_EPackage(package, EPARAMETER_ECLASS);
	
	m_eParameter_EReference_eOperation = factory->createEReference_in_EContainingClass(m_eParameter_EClass, EPARAMETER_EREFERENCE_EOPERATION);
	
	
}

void EcorePackageImpl::createEReferenceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_eReference_EClass = factory->createEClass_in_EPackage(package, EREFERENCE_ECLASS);
	m_eReference_EAttribute_container = factory->createEAttribute_in_EContainingClass(m_eReference_EClass, EREFERENCE_EATTRIBUTE_CONTAINER);
	m_eReference_EAttribute_containment = factory->createEAttribute_in_EContainingClass(m_eReference_EClass, EREFERENCE_EATTRIBUTE_CONTAINMENT);
	m_eReference_EAttribute_resolveProxies = factory->createEAttribute_in_EContainingClass(m_eReference_EClass, EREFERENCE_EATTRIBUTE_RESOLVEPROXIES);
	
	m_eReference_EReference_eKeys = factory->createEReference_in_EContainingClass(m_eReference_EClass, EREFERENCE_EREFERENCE_EKEYS);
	m_eReference_EReference_eOpposite = factory->createEReference_in_EContainingClass(m_eReference_EClass, EREFERENCE_EREFERENCE_EOPPOSITE);
	m_eReference_EReference_eReferenceType = factory->createEReference_in_EContainingClass(m_eReference_EClass, EREFERENCE_EREFERENCE_EREFERENCETYPE);
	
	
}

void EcorePackageImpl::createEStringToStringMapEntryContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_eStringToStringMapEntry_EClass = factory->createEClass_in_EPackage(package, ESTRINGTOSTRINGMAPENTRY_ECLASS);
	m_eStringToStringMapEntry_EAttribute_key = factory->createEAttribute_in_EContainingClass(m_eStringToStringMapEntry_EClass, ESTRINGTOSTRINGMAPENTRY_EATTRIBUTE_KEY);
	m_eStringToStringMapEntry_EAttribute_value = factory->createEAttribute_in_EContainingClass(m_eStringToStringMapEntry_EClass, ESTRINGTOSTRINGMAPENTRY_EATTRIBUTE_VALUE);
	
	
	
}

void EcorePackageImpl::createEStructuralFeatureContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_eStructuralFeature_EClass = factory->createEClass_in_EPackage(package, ESTRUCTURALFEATURE_ECLASS);
	m_eStructuralFeature_EAttribute_changeable = factory->createEAttribute_in_EContainingClass(m_eStructuralFeature_EClass, ESTRUCTURALFEATURE_EATTRIBUTE_CHANGEABLE);
	m_eStructuralFeature_EAttribute_defaultValue = factory->createEAttribute_in_EContainingClass(m_eStructuralFeature_EClass, ESTRUCTURALFEATURE_EATTRIBUTE_DEFAULTVALUE);
	m_eStructuralFeature_EAttribute_defaultValueLiteral = factory->createEAttribute_in_EContainingClass(m_eStructuralFeature_EClass, ESTRUCTURALFEATURE_EATTRIBUTE_DEFAULTVALUELITERAL);
	m_eStructuralFeature_EAttribute_derived = factory->createEAttribute_in_EContainingClass(m_eStructuralFeature_EClass, ESTRUCTURALFEATURE_EATTRIBUTE_DERIVED);
	m_eStructuralFeature_EAttribute_featureID = factory->createEAttribute_in_EContainingClass(m_eStructuralFeature_EClass, ESTRUCTURALFEATURE_EATTRIBUTE_FEATUREID);
	m_eStructuralFeature_EAttribute_transient = factory->createEAttribute_in_EContainingClass(m_eStructuralFeature_EClass, ESTRUCTURALFEATURE_EATTRIBUTE_TRANSIENT);
	m_eStructuralFeature_EAttribute_unsettable = factory->createEAttribute_in_EContainingClass(m_eStructuralFeature_EClass, ESTRUCTURALFEATURE_EATTRIBUTE_UNSETTABLE);
	m_eStructuralFeature_EAttribute_volatile = factory->createEAttribute_in_EContainingClass(m_eStructuralFeature_EClass, ESTRUCTURALFEATURE_EATTRIBUTE_VOLATILE);
	
	m_eStructuralFeature_EReference_eContainingClass = factory->createEReference_in_EContainingClass(m_eStructuralFeature_EClass, ESTRUCTURALFEATURE_EREFERENCE_ECONTAININGCLASS);
	
	m_eStructuralFeature_EOperation_getContainerClass = factory->createEOperation_in_EContainingClass(m_eStructuralFeature_EClass, ESTRUCTURALFEATURE_EOPERATION_GETCONTAINERCLASS);
	m_eStructuralFeature_EOperation_getFeatureID = factory->createEOperation_in_EContainingClass(m_eStructuralFeature_EClass, ESTRUCTURALFEATURE_EOPERATION_GETFEATUREID);
	
}

void EcorePackageImpl::createETypeParameterContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_eTypeParameter_EClass = factory->createEClass_in_EPackage(package, ETYPEPARAMETER_ECLASS);
	
	m_eTypeParameter_EReference_eBounds = factory->createEReference_in_EContainingClass(m_eTypeParameter_EClass, ETYPEPARAMETER_EREFERENCE_EBOUNDS);
	
	
}

void EcorePackageImpl::createETypedElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_eTypedElement_EClass = factory->createEClass_in_EPackage(package, ETYPEDELEMENT_ECLASS);
	m_eTypedElement_EAttribute_lowerBound = factory->createEAttribute_in_EContainingClass(m_eTypedElement_EClass, ETYPEDELEMENT_EATTRIBUTE_LOWERBOUND);
	m_eTypedElement_EAttribute_many = factory->createEAttribute_in_EContainingClass(m_eTypedElement_EClass, ETYPEDELEMENT_EATTRIBUTE_MANY);
	m_eTypedElement_EAttribute_ordered = factory->createEAttribute_in_EContainingClass(m_eTypedElement_EClass, ETYPEDELEMENT_EATTRIBUTE_ORDERED);
	m_eTypedElement_EAttribute_required = factory->createEAttribute_in_EContainingClass(m_eTypedElement_EClass, ETYPEDELEMENT_EATTRIBUTE_REQUIRED);
	m_eTypedElement_EAttribute_unique = factory->createEAttribute_in_EContainingClass(m_eTypedElement_EClass, ETYPEDELEMENT_EATTRIBUTE_UNIQUE);
	m_eTypedElement_EAttribute_upperBound = factory->createEAttribute_in_EContainingClass(m_eTypedElement_EClass, ETYPEDELEMENT_EATTRIBUTE_UPPERBOUND);
	
	m_eTypedElement_EReference_eGenericType = factory->createEReference_in_EContainingClass(m_eTypedElement_EClass, ETYPEDELEMENT_EREFERENCE_EGENERICTYPE);
	m_eTypedElement_EReference_eType = factory->createEReference_in_EContainingClass(m_eTypedElement_EClass, ETYPEDELEMENT_EREFERENCE_ETYPE);
	
	
}

void EcorePackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_eBigDecimal_EDataType = factory->createEDataType_in_EPackage(package, EBIGDECIMAL_EDATATYPE);
	m_eBigInteger_EDataType = factory->createEDataType_in_EPackage(package, EBIGINTEGER_EDATATYPE);
	m_eBoolean_EDataType = factory->createEDataType_in_EPackage(package, EBOOLEAN_EDATATYPE);
	m_eBooleanObject_EDataType = factory->createEDataType_in_EPackage(package, EBOOLEANOBJECT_EDATATYPE);
	m_eByte_EDataType = factory->createEDataType_in_EPackage(package, EBYTE_EDATATYPE);
	m_eByteArray_EDataType = factory->createEDataType_in_EPackage(package, EBYTEARRAY_EDATATYPE);
	m_eByteObject_EDataType = factory->createEDataType_in_EPackage(package, EBYTEOBJECT_EDATATYPE);
	m_eChar_EDataType = factory->createEDataType_in_EPackage(package, ECHAR_EDATATYPE);
	m_eCharacterObject_EDataType = factory->createEDataType_in_EPackage(package, ECHARACTEROBJECT_EDATATYPE);
	m_eDate_EDataType = factory->createEDataType_in_EPackage(package, EDATE_EDATATYPE);
	m_eDiagnosticChain_EDataType = factory->createEDataType_in_EPackage(package, EDIAGNOSTICCHAIN_EDATATYPE);
	m_eDouble_EDataType = factory->createEDataType_in_EPackage(package, EDOUBLE_EDATATYPE);
	m_eDoubleObject_EDataType = factory->createEDataType_in_EPackage(package, EDOUBLEOBJECT_EDATATYPE);
	m_eEList_EDataType = factory->createEDataType_in_EPackage(package, EELIST_EDATATYPE);
	m_eEnumerator_EDataType = factory->createEDataType_in_EPackage(package, EENUMERATOR_EDATATYPE);
	m_eFeatureMap_EDataType = factory->createEDataType_in_EPackage(package, EFEATUREMAP_EDATATYPE);
	m_eFeatureMapEntry_EDataType = factory->createEDataType_in_EPackage(package, EFEATUREMAPENTRY_EDATATYPE);
	m_eFloat_EDataType = factory->createEDataType_in_EPackage(package, EFLOAT_EDATATYPE);
	m_eFloatObject_EDataType = factory->createEDataType_in_EPackage(package, EFLOATOBJECT_EDATATYPE);
	m_eInt_EDataType = factory->createEDataType_in_EPackage(package, EINT_EDATATYPE);
	m_eIntegerObject_EDataType = factory->createEDataType_in_EPackage(package, EINTEGEROBJECT_EDATATYPE);
	m_eInvocationTargetException_EDataType = factory->createEDataType_in_EPackage(package, EINVOCATIONTARGETEXCEPTION_EDATATYPE);
	m_eJavaClass_EDataType = factory->createEDataType_in_EPackage(package, EJAVACLASS_EDATATYPE);
	m_eJavaObject_EDataType = factory->createEDataType_in_EPackage(package, EJAVAOBJECT_EDATATYPE);
	m_eLong_EDataType = factory->createEDataType_in_EPackage(package, ELONG_EDATATYPE);
	m_eLongObject_EDataType = factory->createEDataType_in_EPackage(package, ELONGOBJECT_EDATATYPE);
	m_eMap_EDataType = factory->createEDataType_in_EPackage(package, EMAP_EDATATYPE);
	m_eResource_EDataType = factory->createEDataType_in_EPackage(package, ERESOURCE_EDATATYPE);
	m_eResourceSet_EDataType = factory->createEDataType_in_EPackage(package, ERESOURCESET_EDATATYPE);
	m_eShort_EDataType = factory->createEDataType_in_EPackage(package, ESHORT_EDATATYPE);
	m_eShortObject_EDataType = factory->createEDataType_in_EPackage(package, ESHORTOBJECT_EDATATYPE);
	m_eString_EDataType = factory->createEDataType_in_EPackage(package, ESTRING_EDATATYPE);
	m_eTreeIterator_EDataType = factory->createEDataType_in_EPackage(package, ETREEITERATOR_EDATATYPE);
	
}
