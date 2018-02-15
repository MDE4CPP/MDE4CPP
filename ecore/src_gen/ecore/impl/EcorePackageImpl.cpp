#include "ecore/impl/EcorePackageImpl.hpp"

//metametamodel classes
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EReference.hpp"

// metametamodel factory
#include "ecore/EcoreFactory.hpp"
//metamodel factory
#include "ecore/EcoreFactory.hpp"

//depending model packages

using namespace ecore;

bool EcorePackageImpl::isInited = false;

EcorePackageImpl::EcorePackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( EcoreFactory::eInstance()));
}

EcorePackageImpl::~EcorePackageImpl()
{
}

EcorePackage* EcorePackageImpl::create()
{
	if (isInited)
	{
		return EcorePackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    EcorePackageImpl * metaModelPackage = new EcorePackageImpl();
	metaModelPackage->createPackageContents();
    return metaModelPackage;
}

void EcorePackageImpl::init()
{
    // Initialize created meta-data
    initializePackageContents();   
}

void EcorePackageImpl::createPackageContents()
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;
	struct null_deleter{void operator()(void const *) const { } };

	std::shared_ptr<ecore::EcoreFactory> factory = ecore::EcoreFactory::eInstance();

	createEAnnotationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createEAttributeContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createEClassContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createEClassifierContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createEDataTypeContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createEEnumContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createEEnumLiteralContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createEFactoryContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createEGenericTypeContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createEModelElementContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createENamedElementContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createEObjectContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createEOperationContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createEPackageContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createEParameterContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createEReferenceContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createEStringToStringMapEntryContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createEStructuralFeatureContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createETypeParameterContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);
	createETypedElementContent(std::shared_ptr<EPackage>(this, null_deleter()), factory);

	createPackageEDataTypes(std::shared_ptr<EPackage>(this, null_deleter()), factory);
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
	m_eFactory_EOperation_create_EClass_EObject = factory->createEOperation_in_EContainingClass(m_eFactory_EClass, EFACTORY_EOPERATION_CREATE_ECLASS_EOBJECT);
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
	
	m_eObject_EOperation_eAllContents = factory->createEOperation_in_EContainingClass(m_eObject_EClass, EOBJECT_EOPERATION_EALLCONTENTS);
	m_eObject_EOperation_eClass = factory->createEOperation_in_EContainingClass(m_eObject_EClass, EOBJECT_EOPERATION_ECLASS);
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
	m_eStructuralFeature_EAttribute_containerClass = factory->createEAttribute_in_EContainingClass(m_eStructuralFeature_EClass, ESTRUCTURALFEATURE_EATTRIBUTE_CONTAINERCLASS);
	m_eStructuralFeature_EAttribute_defaultValue = factory->createEAttribute_in_EContainingClass(m_eStructuralFeature_EClass, ESTRUCTURALFEATURE_EATTRIBUTE_DEFAULTVALUE);
	m_eStructuralFeature_EAttribute_defaultValueLiteral = factory->createEAttribute_in_EContainingClass(m_eStructuralFeature_EClass, ESTRUCTURALFEATURE_EATTRIBUTE_DEFAULTVALUELITERAL);
	m_eStructuralFeature_EAttribute_derived = factory->createEAttribute_in_EContainingClass(m_eStructuralFeature_EClass, ESTRUCTURALFEATURE_EATTRIBUTE_DERIVED);
	m_eStructuralFeature_EAttribute_featureID = factory->createEAttribute_in_EContainingClass(m_eStructuralFeature_EClass, ESTRUCTURALFEATURE_EATTRIBUTE_FEATUREID);
	m_eStructuralFeature_EAttribute_transient = factory->createEAttribute_in_EContainingClass(m_eStructuralFeature_EClass, ESTRUCTURALFEATURE_EATTRIBUTE_TRANSIENT);
	m_eStructuralFeature_EAttribute_unsettable = factory->createEAttribute_in_EContainingClass(m_eStructuralFeature_EClass, ESTRUCTURALFEATURE_EATTRIBUTE_UNSETTABLE);
	m_eStructuralFeature_EAttribute_volatile = factory->createEAttribute_in_EContainingClass(m_eStructuralFeature_EClass, ESTRUCTURALFEATURE_EATTRIBUTE_VOLATILE);
	
	m_eStructuralFeature_EReference_eContainingClass = factory->createEReference_in_EContainingClass(m_eStructuralFeature_EClass, ESTRUCTURALFEATURE_EREFERENCE_ECONTAININGCLASS);
	
	
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

void EcorePackageImpl::initializePackageContents()
{
	if (isInitialized)
	{
		return;
	}
	isInitialized = true;

	// Initialize package
	setName(eNAME);
	setNsPrefix(eNS_PREFIX);
	setNsURI(eNS_URI);
	
	// Add supertypes to classes
	m_eAnnotation_EClass->getESuperTypes()->push_back(getEModelElement_EClass());
	m_eAttribute_EClass->getESuperTypes()->push_back(getEStructuralFeature_EClass());
	m_eClass_EClass->getESuperTypes()->push_back(getEClassifier_EClass());
	m_eClassifier_EClass->getESuperTypes()->push_back(getENamedElement_EClass());
	m_eDataType_EClass->getESuperTypes()->push_back(getEClassifier_EClass());
	m_eEnum_EClass->getESuperTypes()->push_back(getEDataType_EClass());
	m_eEnumLiteral_EClass->getESuperTypes()->push_back(getENamedElement_EClass());
	m_eFactory_EClass->getESuperTypes()->push_back(getEModelElement_EClass());
	m_eGenericType_EClass->getESuperTypes()->push_back(getEObject_EClass());
	m_eNamedElement_EClass->getESuperTypes()->push_back(getEModelElement_EClass());
	m_eOperation_EClass->getESuperTypes()->push_back(getETypedElement_EClass());
	m_ePackage_EClass->getESuperTypes()->push_back(getENamedElement_EClass());
	m_eParameter_EClass->getESuperTypes()->push_back(getETypedElement_EClass());
	m_eReference_EClass->getESuperTypes()->push_back(getEStructuralFeature_EClass());
	m_eStringToStringMapEntry_EClass->getESuperTypes()->push_back(getEObject_EClass());
	m_eStructuralFeature_EClass->getESuperTypes()->push_back(getETypedElement_EClass());
	m_eTypeParameter_EClass->getESuperTypes()->push_back(getENamedElement_EClass());
	m_eTypedElement_EClass->getESuperTypes()->push_back(getENamedElement_EClass());
	

 	// Initialize classes and features; add operations and parameters
	initializeEAnnotationContent();
	initializeEAttributeContent();
	initializeEClassContent();
	initializeEClassifierContent();
	initializeEDataTypeContent();
	initializeEEnumContent();
	initializeEEnumLiteralContent();
	initializeEFactoryContent();
	initializeEGenericTypeContent();
	initializeEModelElementContent();
	initializeENamedElementContent();
	initializeEObjectContent();
	initializeEOperationContent();
	initializeEPackageContent();
	initializeEParameterContent();
	initializeEReferenceContent();
	initializeEStringToStringMapEntryContent();
	initializeEStructuralFeatureContent();
	initializeETypeParameterContent();
	initializeETypedElementContent();

	initializePackageEDataTypes();
}

void EcorePackageImpl::initializeEAnnotationContent()
{
	m_eAnnotation_EClass->setInstanceClass(nullptr);
	m_eAnnotation_EClass->setName("EAnnotation");
	m_eAnnotation_EClass->setAbstract(false);
	m_eAnnotation_EClass->setInterface(false);
	
	m_eAnnotation_EAttribute_source = getEAnnotation_EAttribute_source();
	m_eAnnotation_EAttribute_source->setName("source");
	m_eAnnotation_EAttribute_source->setEType(getEString_EDataType());
	m_eAnnotation_EAttribute_source->setLowerBound(0);
	m_eAnnotation_EAttribute_source->setUpperBound(1);
	m_eAnnotation_EAttribute_source->setTransient(false);
	m_eAnnotation_EAttribute_source->setVolatile(false);
	m_eAnnotation_EAttribute_source->setChangeable(true);
	m_eAnnotation_EAttribute_source->setUnsettable(false);
	m_eAnnotation_EAttribute_source->setUnique(true);
	m_eAnnotation_EAttribute_source->setDerived(false);
	m_eAnnotation_EAttribute_source->setOrdered(true);
	m_eAnnotation_EAttribute_source->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eAnnotation_EAttribute_source->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_eAnnotation_EReference_contents->setName("contents");
	m_eAnnotation_EReference_contents->setEType(getEObject_EClass());
	m_eAnnotation_EReference_contents->setLowerBound(0);
	m_eAnnotation_EReference_contents->setUpperBound(-1);
	m_eAnnotation_EReference_contents->setTransient(false);
	m_eAnnotation_EReference_contents->setVolatile(false);
	m_eAnnotation_EReference_contents->setChangeable(true);
	m_eAnnotation_EReference_contents->setUnsettable(false);
	m_eAnnotation_EReference_contents->setUnique(true);
	m_eAnnotation_EReference_contents->setDerived(false);
	m_eAnnotation_EReference_contents->setOrdered(true);
	m_eAnnotation_EReference_contents->setContainment(true);
	m_eAnnotation_EReference_contents->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eAnnotation_EReference_contents->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eAnnotation_EReference_contents->setEOpposite(otherEnd);
	    }
	}
	m_eAnnotation_EReference_details->setName("details");
	m_eAnnotation_EReference_details->setEType(getEStringToStringMapEntry_EClass());
	m_eAnnotation_EReference_details->setLowerBound(0);
	m_eAnnotation_EReference_details->setUpperBound(-1);
	m_eAnnotation_EReference_details->setTransient(false);
	m_eAnnotation_EReference_details->setVolatile(false);
	m_eAnnotation_EReference_details->setChangeable(true);
	m_eAnnotation_EReference_details->setUnsettable(false);
	m_eAnnotation_EReference_details->setUnique(true);
	m_eAnnotation_EReference_details->setDerived(false);
	m_eAnnotation_EReference_details->setOrdered(true);
	m_eAnnotation_EReference_details->setContainment(true);
	m_eAnnotation_EReference_details->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eAnnotation_EReference_details->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eAnnotation_EReference_details->setEOpposite(otherEnd);
	    }
	}
	m_eAnnotation_EReference_eModelElement->setName("eModelElement");
	m_eAnnotation_EReference_eModelElement->setEType(getEModelElement_EClass());
	m_eAnnotation_EReference_eModelElement->setLowerBound(0);
	m_eAnnotation_EReference_eModelElement->setUpperBound(1);
	m_eAnnotation_EReference_eModelElement->setTransient(true);
	m_eAnnotation_EReference_eModelElement->setVolatile(false);
	m_eAnnotation_EReference_eModelElement->setChangeable(true);
	m_eAnnotation_EReference_eModelElement->setUnsettable(false);
	m_eAnnotation_EReference_eModelElement->setUnique(true);
	m_eAnnotation_EReference_eModelElement->setDerived(false);
	m_eAnnotation_EReference_eModelElement->setOrdered(true);
	m_eAnnotation_EReference_eModelElement->setContainment(false);
	m_eAnnotation_EReference_eModelElement->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eAnnotation_EReference_eModelElement->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEModelElement_EReference_eAnnotations();
		if (otherEnd != nullptr)
	    {
	   		m_eAnnotation_EReference_eModelElement->setEOpposite(otherEnd);
	    }
	}
	m_eAnnotation_EReference_references->setName("references");
	m_eAnnotation_EReference_references->setEType(getEObject_EClass());
	m_eAnnotation_EReference_references->setLowerBound(0);
	m_eAnnotation_EReference_references->setUpperBound(-1);
	m_eAnnotation_EReference_references->setTransient(false);
	m_eAnnotation_EReference_references->setVolatile(false);
	m_eAnnotation_EReference_references->setChangeable(true);
	m_eAnnotation_EReference_references->setUnsettable(false);
	m_eAnnotation_EReference_references->setUnique(true);
	m_eAnnotation_EReference_references->setDerived(false);
	m_eAnnotation_EReference_references->setOrdered(true);
	m_eAnnotation_EReference_references->setContainment(false);
	m_eAnnotation_EReference_references->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eAnnotation_EReference_references->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eAnnotation_EReference_references->setEOpposite(otherEnd);
	    }
	}
	
	
}

void EcorePackageImpl::initializeEAttributeContent()
{
	m_eAttribute_EClass->setInstanceClass(nullptr);
	m_eAttribute_EClass->setName("EAttribute");
	m_eAttribute_EClass->setAbstract(false);
	m_eAttribute_EClass->setInterface(false);
	
	m_eAttribute_EAttribute_iD = getEAttribute_EAttribute_iD();
	m_eAttribute_EAttribute_iD->setName("iD");
	m_eAttribute_EAttribute_iD->setEType(getEBoolean_EDataType());
	m_eAttribute_EAttribute_iD->setLowerBound(0);
	m_eAttribute_EAttribute_iD->setUpperBound(1);
	m_eAttribute_EAttribute_iD->setTransient(false);
	m_eAttribute_EAttribute_iD->setVolatile(false);
	m_eAttribute_EAttribute_iD->setChangeable(true);
	m_eAttribute_EAttribute_iD->setUnsettable(false);
	m_eAttribute_EAttribute_iD->setUnique(true);
	m_eAttribute_EAttribute_iD->setDerived(false);
	m_eAttribute_EAttribute_iD->setOrdered(true);
	m_eAttribute_EAttribute_iD->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eAttribute_EAttribute_iD->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_eAttribute_EReference_eAttributeType->setName("eAttributeType");
	m_eAttribute_EReference_eAttributeType->setEType(getEDataType_EClass());
	m_eAttribute_EReference_eAttributeType->setLowerBound(1);
	m_eAttribute_EReference_eAttributeType->setUpperBound(1);
	m_eAttribute_EReference_eAttributeType->setTransient(true);
	m_eAttribute_EReference_eAttributeType->setVolatile(true);
	m_eAttribute_EReference_eAttributeType->setChangeable(false);
	m_eAttribute_EReference_eAttributeType->setUnsettable(false);
	m_eAttribute_EReference_eAttributeType->setUnique(true);
	m_eAttribute_EReference_eAttributeType->setDerived(true);
	m_eAttribute_EReference_eAttributeType->setOrdered(true);
	m_eAttribute_EReference_eAttributeType->setContainment(false);
	m_eAttribute_EReference_eAttributeType->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eAttribute_EReference_eAttributeType->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eAttribute_EReference_eAttributeType->setEOpposite(otherEnd);
	    }
	}
	
	
}

void EcorePackageImpl::initializeEClassContent()
{
	m_eClass_EClass->setInstanceClass(nullptr);
	m_eClass_EClass->setName("EClass");
	m_eClass_EClass->setAbstract(false);
	m_eClass_EClass->setInterface(false);
	
	m_eClass_EAttribute_abstract = getEClass_EAttribute_abstract();
	m_eClass_EAttribute_abstract->setName("abstract");
	m_eClass_EAttribute_abstract->setEType(getEBoolean_EDataType());
	m_eClass_EAttribute_abstract->setLowerBound(0);
	m_eClass_EAttribute_abstract->setUpperBound(1);
	m_eClass_EAttribute_abstract->setTransient(false);
	m_eClass_EAttribute_abstract->setVolatile(false);
	m_eClass_EAttribute_abstract->setChangeable(true);
	m_eClass_EAttribute_abstract->setUnsettable(false);
	m_eClass_EAttribute_abstract->setUnique(true);
	m_eClass_EAttribute_abstract->setDerived(false);
	m_eClass_EAttribute_abstract->setOrdered(true);
	m_eClass_EAttribute_abstract->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eClass_EAttribute_abstract->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eClass_EAttribute_interface = getEClass_EAttribute_interface();
	m_eClass_EAttribute_interface->setName("interface");
	m_eClass_EAttribute_interface->setEType(getEBoolean_EDataType());
	m_eClass_EAttribute_interface->setLowerBound(0);
	m_eClass_EAttribute_interface->setUpperBound(1);
	m_eClass_EAttribute_interface->setTransient(false);
	m_eClass_EAttribute_interface->setVolatile(false);
	m_eClass_EAttribute_interface->setChangeable(true);
	m_eClass_EAttribute_interface->setUnsettable(false);
	m_eClass_EAttribute_interface->setUnique(true);
	m_eClass_EAttribute_interface->setDerived(false);
	m_eClass_EAttribute_interface->setOrdered(true);
	m_eClass_EAttribute_interface->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eClass_EAttribute_interface->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_eClass_EReference_eAllAttributes->setName("eAllAttributes");
	m_eClass_EReference_eAllAttributes->setEType(getEAttribute_EClass());
	m_eClass_EReference_eAllAttributes->setLowerBound(0);
	m_eClass_EReference_eAllAttributes->setUpperBound(-1);
	m_eClass_EReference_eAllAttributes->setTransient(true);
	m_eClass_EReference_eAllAttributes->setVolatile(true);
	m_eClass_EReference_eAllAttributes->setChangeable(false);
	m_eClass_EReference_eAllAttributes->setUnsettable(false);
	m_eClass_EReference_eAllAttributes->setUnique(true);
	m_eClass_EReference_eAllAttributes->setDerived(true);
	m_eClass_EReference_eAllAttributes->setOrdered(true);
	m_eClass_EReference_eAllAttributes->setContainment(false);
	m_eClass_EReference_eAllAttributes->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_EReference_eAllAttributes->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eClass_EReference_eAllAttributes->setEOpposite(otherEnd);
	    }
	}
	m_eClass_EReference_eAllContainments->setName("eAllContainments");
	m_eClass_EReference_eAllContainments->setEType(getEReference_EClass());
	m_eClass_EReference_eAllContainments->setLowerBound(0);
	m_eClass_EReference_eAllContainments->setUpperBound(-1);
	m_eClass_EReference_eAllContainments->setTransient(true);
	m_eClass_EReference_eAllContainments->setVolatile(true);
	m_eClass_EReference_eAllContainments->setChangeable(false);
	m_eClass_EReference_eAllContainments->setUnsettable(false);
	m_eClass_EReference_eAllContainments->setUnique(true);
	m_eClass_EReference_eAllContainments->setDerived(true);
	m_eClass_EReference_eAllContainments->setOrdered(true);
	m_eClass_EReference_eAllContainments->setContainment(false);
	m_eClass_EReference_eAllContainments->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_EReference_eAllContainments->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eClass_EReference_eAllContainments->setEOpposite(otherEnd);
	    }
	}
	m_eClass_EReference_eAllGenericSuperTypes->setName("eAllGenericSuperTypes");
	m_eClass_EReference_eAllGenericSuperTypes->setEType(getEGenericType_EClass());
	m_eClass_EReference_eAllGenericSuperTypes->setLowerBound(0);
	m_eClass_EReference_eAllGenericSuperTypes->setUpperBound(-1);
	m_eClass_EReference_eAllGenericSuperTypes->setTransient(true);
	m_eClass_EReference_eAllGenericSuperTypes->setVolatile(true);
	m_eClass_EReference_eAllGenericSuperTypes->setChangeable(false);
	m_eClass_EReference_eAllGenericSuperTypes->setUnsettable(false);
	m_eClass_EReference_eAllGenericSuperTypes->setUnique(true);
	m_eClass_EReference_eAllGenericSuperTypes->setDerived(true);
	m_eClass_EReference_eAllGenericSuperTypes->setOrdered(true);
	m_eClass_EReference_eAllGenericSuperTypes->setContainment(false);
	m_eClass_EReference_eAllGenericSuperTypes->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_EReference_eAllGenericSuperTypes->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eClass_EReference_eAllGenericSuperTypes->setEOpposite(otherEnd);
	    }
	}
	m_eClass_EReference_eAllOperations->setName("eAllOperations");
	m_eClass_EReference_eAllOperations->setEType(getEOperation_EClass());
	m_eClass_EReference_eAllOperations->setLowerBound(0);
	m_eClass_EReference_eAllOperations->setUpperBound(-1);
	m_eClass_EReference_eAllOperations->setTransient(true);
	m_eClass_EReference_eAllOperations->setVolatile(true);
	m_eClass_EReference_eAllOperations->setChangeable(false);
	m_eClass_EReference_eAllOperations->setUnsettable(false);
	m_eClass_EReference_eAllOperations->setUnique(true);
	m_eClass_EReference_eAllOperations->setDerived(true);
	m_eClass_EReference_eAllOperations->setOrdered(true);
	m_eClass_EReference_eAllOperations->setContainment(false);
	m_eClass_EReference_eAllOperations->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_EReference_eAllOperations->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eClass_EReference_eAllOperations->setEOpposite(otherEnd);
	    }
	}
	m_eClass_EReference_eAllReferences->setName("eAllReferences");
	m_eClass_EReference_eAllReferences->setEType(getEReference_EClass());
	m_eClass_EReference_eAllReferences->setLowerBound(0);
	m_eClass_EReference_eAllReferences->setUpperBound(-1);
	m_eClass_EReference_eAllReferences->setTransient(true);
	m_eClass_EReference_eAllReferences->setVolatile(true);
	m_eClass_EReference_eAllReferences->setChangeable(false);
	m_eClass_EReference_eAllReferences->setUnsettable(false);
	m_eClass_EReference_eAllReferences->setUnique(true);
	m_eClass_EReference_eAllReferences->setDerived(true);
	m_eClass_EReference_eAllReferences->setOrdered(true);
	m_eClass_EReference_eAllReferences->setContainment(false);
	m_eClass_EReference_eAllReferences->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_EReference_eAllReferences->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eClass_EReference_eAllReferences->setEOpposite(otherEnd);
	    }
	}
	m_eClass_EReference_eAllStructuralFeatures->setName("eAllStructuralFeatures");
	m_eClass_EReference_eAllStructuralFeatures->setEType(getEStructuralFeature_EClass());
	m_eClass_EReference_eAllStructuralFeatures->setLowerBound(0);
	m_eClass_EReference_eAllStructuralFeatures->setUpperBound(-1);
	m_eClass_EReference_eAllStructuralFeatures->setTransient(true);
	m_eClass_EReference_eAllStructuralFeatures->setVolatile(true);
	m_eClass_EReference_eAllStructuralFeatures->setChangeable(false);
	m_eClass_EReference_eAllStructuralFeatures->setUnsettable(false);
	m_eClass_EReference_eAllStructuralFeatures->setUnique(true);
	m_eClass_EReference_eAllStructuralFeatures->setDerived(true);
	m_eClass_EReference_eAllStructuralFeatures->setOrdered(true);
	m_eClass_EReference_eAllStructuralFeatures->setContainment(false);
	m_eClass_EReference_eAllStructuralFeatures->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_EReference_eAllStructuralFeatures->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eClass_EReference_eAllStructuralFeatures->setEOpposite(otherEnd);
	    }
	}
	m_eClass_EReference_eAllSuperTypes->setName("eAllSuperTypes");
	m_eClass_EReference_eAllSuperTypes->setEType(getEClass_EClass());
	m_eClass_EReference_eAllSuperTypes->setLowerBound(0);
	m_eClass_EReference_eAllSuperTypes->setUpperBound(-1);
	m_eClass_EReference_eAllSuperTypes->setTransient(true);
	m_eClass_EReference_eAllSuperTypes->setVolatile(true);
	m_eClass_EReference_eAllSuperTypes->setChangeable(false);
	m_eClass_EReference_eAllSuperTypes->setUnsettable(false);
	m_eClass_EReference_eAllSuperTypes->setUnique(true);
	m_eClass_EReference_eAllSuperTypes->setDerived(true);
	m_eClass_EReference_eAllSuperTypes->setOrdered(true);
	m_eClass_EReference_eAllSuperTypes->setContainment(false);
	m_eClass_EReference_eAllSuperTypes->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_EReference_eAllSuperTypes->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eClass_EReference_eAllSuperTypes->setEOpposite(otherEnd);
	    }
	}
	m_eClass_EReference_eAttributes->setName("eAttributes");
	m_eClass_EReference_eAttributes->setEType(getEAttribute_EClass());
	m_eClass_EReference_eAttributes->setLowerBound(0);
	m_eClass_EReference_eAttributes->setUpperBound(-1);
	m_eClass_EReference_eAttributes->setTransient(true);
	m_eClass_EReference_eAttributes->setVolatile(true);
	m_eClass_EReference_eAttributes->setChangeable(false);
	m_eClass_EReference_eAttributes->setUnsettable(false);
	m_eClass_EReference_eAttributes->setUnique(true);
	m_eClass_EReference_eAttributes->setDerived(true);
	m_eClass_EReference_eAttributes->setOrdered(true);
	m_eClass_EReference_eAttributes->setContainment(false);
	m_eClass_EReference_eAttributes->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_EReference_eAttributes->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eClass_EReference_eAttributes->setEOpposite(otherEnd);
	    }
	}
	m_eClass_EReference_eGenericSuperTypes->setName("eGenericSuperTypes");
	m_eClass_EReference_eGenericSuperTypes->setEType(getEGenericType_EClass());
	m_eClass_EReference_eGenericSuperTypes->setLowerBound(0);
	m_eClass_EReference_eGenericSuperTypes->setUpperBound(-1);
	m_eClass_EReference_eGenericSuperTypes->setTransient(false);
	m_eClass_EReference_eGenericSuperTypes->setVolatile(false);
	m_eClass_EReference_eGenericSuperTypes->setChangeable(true);
	m_eClass_EReference_eGenericSuperTypes->setUnsettable(true);
	m_eClass_EReference_eGenericSuperTypes->setUnique(true);
	m_eClass_EReference_eGenericSuperTypes->setDerived(false);
	m_eClass_EReference_eGenericSuperTypes->setOrdered(true);
	m_eClass_EReference_eGenericSuperTypes->setContainment(true);
	m_eClass_EReference_eGenericSuperTypes->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_EReference_eGenericSuperTypes->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eClass_EReference_eGenericSuperTypes->setEOpposite(otherEnd);
	    }
	}
	m_eClass_EReference_eIDAttribute->setName("eIDAttribute");
	m_eClass_EReference_eIDAttribute->setEType(getEAttribute_EClass());
	m_eClass_EReference_eIDAttribute->setLowerBound(0);
	m_eClass_EReference_eIDAttribute->setUpperBound(1);
	m_eClass_EReference_eIDAttribute->setTransient(true);
	m_eClass_EReference_eIDAttribute->setVolatile(true);
	m_eClass_EReference_eIDAttribute->setChangeable(false);
	m_eClass_EReference_eIDAttribute->setUnsettable(false);
	m_eClass_EReference_eIDAttribute->setUnique(true);
	m_eClass_EReference_eIDAttribute->setDerived(true);
	m_eClass_EReference_eIDAttribute->setOrdered(true);
	m_eClass_EReference_eIDAttribute->setContainment(false);
	m_eClass_EReference_eIDAttribute->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_EReference_eIDAttribute->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eClass_EReference_eIDAttribute->setEOpposite(otherEnd);
	    }
	}
	m_eClass_EReference_eOperations->setName("eOperations");
	m_eClass_EReference_eOperations->setEType(getEOperation_EClass());
	m_eClass_EReference_eOperations->setLowerBound(0);
	m_eClass_EReference_eOperations->setUpperBound(-1);
	m_eClass_EReference_eOperations->setTransient(false);
	m_eClass_EReference_eOperations->setVolatile(false);
	m_eClass_EReference_eOperations->setChangeable(true);
	m_eClass_EReference_eOperations->setUnsettable(false);
	m_eClass_EReference_eOperations->setUnique(true);
	m_eClass_EReference_eOperations->setDerived(false);
	m_eClass_EReference_eOperations->setOrdered(true);
	m_eClass_EReference_eOperations->setContainment(true);
	m_eClass_EReference_eOperations->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_EReference_eOperations->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEOperation_EReference_eContainingClass();
		if (otherEnd != nullptr)
	    {
	   		m_eClass_EReference_eOperations->setEOpposite(otherEnd);
	    }
	}
	m_eClass_EReference_eReferences->setName("eReferences");
	m_eClass_EReference_eReferences->setEType(getEReference_EClass());
	m_eClass_EReference_eReferences->setLowerBound(0);
	m_eClass_EReference_eReferences->setUpperBound(-1);
	m_eClass_EReference_eReferences->setTransient(true);
	m_eClass_EReference_eReferences->setVolatile(true);
	m_eClass_EReference_eReferences->setChangeable(false);
	m_eClass_EReference_eReferences->setUnsettable(false);
	m_eClass_EReference_eReferences->setUnique(true);
	m_eClass_EReference_eReferences->setDerived(true);
	m_eClass_EReference_eReferences->setOrdered(true);
	m_eClass_EReference_eReferences->setContainment(false);
	m_eClass_EReference_eReferences->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_EReference_eReferences->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eClass_EReference_eReferences->setEOpposite(otherEnd);
	    }
	}
	m_eClass_EReference_eStructuralFeatures->setName("eStructuralFeatures");
	m_eClass_EReference_eStructuralFeatures->setEType(getEStructuralFeature_EClass());
	m_eClass_EReference_eStructuralFeatures->setLowerBound(0);
	m_eClass_EReference_eStructuralFeatures->setUpperBound(-1);
	m_eClass_EReference_eStructuralFeatures->setTransient(false);
	m_eClass_EReference_eStructuralFeatures->setVolatile(false);
	m_eClass_EReference_eStructuralFeatures->setChangeable(true);
	m_eClass_EReference_eStructuralFeatures->setUnsettable(false);
	m_eClass_EReference_eStructuralFeatures->setUnique(true);
	m_eClass_EReference_eStructuralFeatures->setDerived(false);
	m_eClass_EReference_eStructuralFeatures->setOrdered(true);
	m_eClass_EReference_eStructuralFeatures->setContainment(true);
	m_eClass_EReference_eStructuralFeatures->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_EReference_eStructuralFeatures->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEStructuralFeature_EReference_eContainingClass();
		if (otherEnd != nullptr)
	    {
	   		m_eClass_EReference_eStructuralFeatures->setEOpposite(otherEnd);
	    }
	}
	m_eClass_EReference_eSuperTypes->setName("eSuperTypes");
	m_eClass_EReference_eSuperTypes->setEType(getEClass_EClass());
	m_eClass_EReference_eSuperTypes->setLowerBound(0);
	m_eClass_EReference_eSuperTypes->setUpperBound(-1);
	m_eClass_EReference_eSuperTypes->setTransient(false);
	m_eClass_EReference_eSuperTypes->setVolatile(false);
	m_eClass_EReference_eSuperTypes->setChangeable(true);
	m_eClass_EReference_eSuperTypes->setUnsettable(true);
	m_eClass_EReference_eSuperTypes->setUnique(true);
	m_eClass_EReference_eSuperTypes->setDerived(false);
	m_eClass_EReference_eSuperTypes->setOrdered(true);
	m_eClass_EReference_eSuperTypes->setContainment(false);
	m_eClass_EReference_eSuperTypes->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClass_EReference_eSuperTypes->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eClass_EReference_eSuperTypes->setEOpposite(otherEnd);
	    }
	}
	
	m_eClass_EOperation_getEOperation_EInt->setEType(getEOperation_EClass());
	m_eClass_EOperation_getEOperation_EInt->setName("getEOperation");
	m_eClass_EOperation_getEOperation_EInt->setLowerBound(0);
	m_eClass_EOperation_getEOperation_EInt->setUpperBound(1);
	m_eClass_EOperation_getEOperation_EInt->setUnique(true);
	m_eClass_EOperation_getEOperation_EInt->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eClass_EOperation_getEOperation_EInt);
		parameter->setName("operationID");
		parameter->setEType(getEInt_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eClass_EOperation_getEStructuralFeature_EInt->setEType(getEStructuralFeature_EClass());
	m_eClass_EOperation_getEStructuralFeature_EInt->setName("getEStructuralFeature");
	m_eClass_EOperation_getEStructuralFeature_EInt->setLowerBound(0);
	m_eClass_EOperation_getEStructuralFeature_EInt->setUpperBound(1);
	m_eClass_EOperation_getEStructuralFeature_EInt->setUnique(true);
	m_eClass_EOperation_getEStructuralFeature_EInt->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eClass_EOperation_getEStructuralFeature_EInt);
		parameter->setName("featureID");
		parameter->setEType(getEInt_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eClass_EOperation_getEStructuralFeature_EString->setEType(getEStructuralFeature_EClass());
	m_eClass_EOperation_getEStructuralFeature_EString->setName("getEStructuralFeature");
	m_eClass_EOperation_getEStructuralFeature_EString->setLowerBound(0);
	m_eClass_EOperation_getEStructuralFeature_EString->setUpperBound(1);
	m_eClass_EOperation_getEStructuralFeature_EString->setUnique(true);
	m_eClass_EOperation_getEStructuralFeature_EString->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eClass_EOperation_getEStructuralFeature_EString);
		parameter->setName("featureName");
		parameter->setEType(getEString_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eClass_EOperation_getFeatureCount->setEType(getEInt_EDataType());
	m_eClass_EOperation_getFeatureCount->setName("getFeatureCount");
	m_eClass_EOperation_getFeatureCount->setLowerBound(0);
	m_eClass_EOperation_getFeatureCount->setUpperBound(1);
	m_eClass_EOperation_getFeatureCount->setUnique(true);
	m_eClass_EOperation_getFeatureCount->setOrdered(true);
	
	
	m_eClass_EOperation_getFeatureID_EStructuralFeature->setEType(getEInt_EDataType());
	m_eClass_EOperation_getFeatureID_EStructuralFeature->setName("getFeatureID");
	m_eClass_EOperation_getFeatureID_EStructuralFeature->setLowerBound(0);
	m_eClass_EOperation_getFeatureID_EStructuralFeature->setUpperBound(1);
	m_eClass_EOperation_getFeatureID_EStructuralFeature->setUnique(true);
	m_eClass_EOperation_getFeatureID_EStructuralFeature->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eClass_EOperation_getFeatureID_EStructuralFeature);
		parameter->setName("feature");
		parameter->setEType(getEStructuralFeature_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eClass_EOperation_getFeatureType_EStructuralFeature->setEType(getEGenericType_EClass());
	m_eClass_EOperation_getFeatureType_EStructuralFeature->setName("getFeatureType");
	m_eClass_EOperation_getFeatureType_EStructuralFeature->setLowerBound(0);
	m_eClass_EOperation_getFeatureType_EStructuralFeature->setUpperBound(1);
	m_eClass_EOperation_getFeatureType_EStructuralFeature->setUnique(true);
	m_eClass_EOperation_getFeatureType_EStructuralFeature->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eClass_EOperation_getFeatureType_EStructuralFeature);
		parameter->setName("feature");
		parameter->setEType(getEStructuralFeature_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eClass_EOperation_getOperationCount->setEType(getEInt_EDataType());
	m_eClass_EOperation_getOperationCount->setName("getOperationCount");
	m_eClass_EOperation_getOperationCount->setLowerBound(0);
	m_eClass_EOperation_getOperationCount->setUpperBound(1);
	m_eClass_EOperation_getOperationCount->setUnique(true);
	m_eClass_EOperation_getOperationCount->setOrdered(true);
	
	
	m_eClass_EOperation_getOperationID_EOperation->setEType(getEInt_EDataType());
	m_eClass_EOperation_getOperationID_EOperation->setName("getOperationID");
	m_eClass_EOperation_getOperationID_EOperation->setLowerBound(0);
	m_eClass_EOperation_getOperationID_EOperation->setUpperBound(1);
	m_eClass_EOperation_getOperationID_EOperation->setUnique(true);
	m_eClass_EOperation_getOperationID_EOperation->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eClass_EOperation_getOperationID_EOperation);
		parameter->setName("operation");
		parameter->setEType(getEOperation_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eClass_EOperation_getOverride_EOperation->setEType(getEOperation_EClass());
	m_eClass_EOperation_getOverride_EOperation->setName("getOverride");
	m_eClass_EOperation_getOverride_EOperation->setLowerBound(0);
	m_eClass_EOperation_getOverride_EOperation->setUpperBound(1);
	m_eClass_EOperation_getOverride_EOperation->setUnique(true);
	m_eClass_EOperation_getOverride_EOperation->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eClass_EOperation_getOverride_EOperation);
		parameter->setName("operation");
		parameter->setEType(getEOperation_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eClass_EOperation_isSuperTypeOf_EClass->setEType(getEBoolean_EDataType());
	m_eClass_EOperation_isSuperTypeOf_EClass->setName("isSuperTypeOf");
	m_eClass_EOperation_isSuperTypeOf_EClass->setLowerBound(0);
	m_eClass_EOperation_isSuperTypeOf_EClass->setUpperBound(1);
	m_eClass_EOperation_isSuperTypeOf_EClass->setUnique(true);
	m_eClass_EOperation_isSuperTypeOf_EClass->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eClass_EOperation_isSuperTypeOf_EClass);
		parameter->setName("someClass");
		parameter->setEType(getEClass_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void EcorePackageImpl::initializeEClassifierContent()
{
	m_eClassifier_EClass->setInstanceClass(nullptr);
	m_eClassifier_EClass->setName("EClassifier");
	m_eClassifier_EClass->setAbstract(true);
	m_eClassifier_EClass->setInterface(false);
	
	m_eClassifier_EAttribute_classifierID = getEClassifier_EAttribute_classifierID();
	m_eClassifier_EAttribute_classifierID->setName("classifierID");
	m_eClassifier_EAttribute_classifierID->setEType(getEInt_EDataType());
	m_eClassifier_EAttribute_classifierID->setLowerBound(0);
	m_eClassifier_EAttribute_classifierID->setUpperBound(1);
	m_eClassifier_EAttribute_classifierID->setTransient(false);
	m_eClassifier_EAttribute_classifierID->setVolatile(false);
	m_eClassifier_EAttribute_classifierID->setChangeable(false);
	m_eClassifier_EAttribute_classifierID->setUnsettable(false);
	m_eClassifier_EAttribute_classifierID->setUnique(true);
	m_eClassifier_EAttribute_classifierID->setDerived(false);
	m_eClassifier_EAttribute_classifierID->setOrdered(true);
	m_eClassifier_EAttribute_classifierID->setID(false);
	{
		std::string defaultValue = "-1";
		if (!defaultValue.empty())
		{
		   m_eClassifier_EAttribute_classifierID->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eClassifier_EAttribute_defaultValue = getEClassifier_EAttribute_defaultValue();
	m_eClassifier_EAttribute_defaultValue->setName("defaultValue");
	m_eClassifier_EAttribute_defaultValue->setEType(getEJavaObject_EDataType());
	m_eClassifier_EAttribute_defaultValue->setLowerBound(0);
	m_eClassifier_EAttribute_defaultValue->setUpperBound(1);
	m_eClassifier_EAttribute_defaultValue->setTransient(true);
	m_eClassifier_EAttribute_defaultValue->setVolatile(true);
	m_eClassifier_EAttribute_defaultValue->setChangeable(false);
	m_eClassifier_EAttribute_defaultValue->setUnsettable(false);
	m_eClassifier_EAttribute_defaultValue->setUnique(true);
	m_eClassifier_EAttribute_defaultValue->setDerived(true);
	m_eClassifier_EAttribute_defaultValue->setOrdered(true);
	m_eClassifier_EAttribute_defaultValue->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eClassifier_EAttribute_defaultValue->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eClassifier_EAttribute_instanceClass = getEClassifier_EAttribute_instanceClass();
	m_eClassifier_EAttribute_instanceClass->setName("instanceClass");
	m_eClassifier_EAttribute_instanceClass->setEType(getEJavaClass_EDataType());
	m_eClassifier_EAttribute_instanceClass->setLowerBound(0);
	m_eClassifier_EAttribute_instanceClass->setUpperBound(1);
	m_eClassifier_EAttribute_instanceClass->setTransient(true);
	m_eClassifier_EAttribute_instanceClass->setVolatile(true);
	m_eClassifier_EAttribute_instanceClass->setChangeable(true);
	m_eClassifier_EAttribute_instanceClass->setUnsettable(false);
	m_eClassifier_EAttribute_instanceClass->setUnique(true);
	m_eClassifier_EAttribute_instanceClass->setDerived(false);
	m_eClassifier_EAttribute_instanceClass->setOrdered(true);
	m_eClassifier_EAttribute_instanceClass->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eClassifier_EAttribute_instanceClass->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eClassifier_EAttribute_instanceClassName = getEClassifier_EAttribute_instanceClassName();
	m_eClassifier_EAttribute_instanceClassName->setName("instanceClassName");
	m_eClassifier_EAttribute_instanceClassName->setEType(getEString_EDataType());
	m_eClassifier_EAttribute_instanceClassName->setLowerBound(0);
	m_eClassifier_EAttribute_instanceClassName->setUpperBound(1);
	m_eClassifier_EAttribute_instanceClassName->setTransient(false);
	m_eClassifier_EAttribute_instanceClassName->setVolatile(true);
	m_eClassifier_EAttribute_instanceClassName->setChangeable(true);
	m_eClassifier_EAttribute_instanceClassName->setUnsettable(true);
	m_eClassifier_EAttribute_instanceClassName->setUnique(true);
	m_eClassifier_EAttribute_instanceClassName->setDerived(false);
	m_eClassifier_EAttribute_instanceClassName->setOrdered(true);
	m_eClassifier_EAttribute_instanceClassName->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eClassifier_EAttribute_instanceClassName->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eClassifier_EAttribute_instanceTypeName = getEClassifier_EAttribute_instanceTypeName();
	m_eClassifier_EAttribute_instanceTypeName->setName("instanceTypeName");
	m_eClassifier_EAttribute_instanceTypeName->setEType(getEString_EDataType());
	m_eClassifier_EAttribute_instanceTypeName->setLowerBound(0);
	m_eClassifier_EAttribute_instanceTypeName->setUpperBound(1);
	m_eClassifier_EAttribute_instanceTypeName->setTransient(false);
	m_eClassifier_EAttribute_instanceTypeName->setVolatile(true);
	m_eClassifier_EAttribute_instanceTypeName->setChangeable(true);
	m_eClassifier_EAttribute_instanceTypeName->setUnsettable(true);
	m_eClassifier_EAttribute_instanceTypeName->setUnique(true);
	m_eClassifier_EAttribute_instanceTypeName->setDerived(false);
	m_eClassifier_EAttribute_instanceTypeName->setOrdered(true);
	m_eClassifier_EAttribute_instanceTypeName->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eClassifier_EAttribute_instanceTypeName->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_eClassifier_EReference_ePackage->setName("ePackage");
	m_eClassifier_EReference_ePackage->setEType(getEPackage_EClass());
	m_eClassifier_EReference_ePackage->setLowerBound(0);
	m_eClassifier_EReference_ePackage->setUpperBound(1);
	m_eClassifier_EReference_ePackage->setTransient(true);
	m_eClassifier_EReference_ePackage->setVolatile(false);
	m_eClassifier_EReference_ePackage->setChangeable(true);
	m_eClassifier_EReference_ePackage->setUnsettable(false);
	m_eClassifier_EReference_ePackage->setUnique(true);
	m_eClassifier_EReference_ePackage->setDerived(false);
	m_eClassifier_EReference_ePackage->setOrdered(true);
	m_eClassifier_EReference_ePackage->setContainment(false);
	m_eClassifier_EReference_ePackage->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClassifier_EReference_ePackage->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEPackage_EReference_eClassifiers();
		if (otherEnd != nullptr)
	    {
	   		m_eClassifier_EReference_ePackage->setEOpposite(otherEnd);
	    }
	}
	m_eClassifier_EReference_eTypeParameters->setName("eTypeParameters");
	m_eClassifier_EReference_eTypeParameters->setEType(getETypeParameter_EClass());
	m_eClassifier_EReference_eTypeParameters->setLowerBound(0);
	m_eClassifier_EReference_eTypeParameters->setUpperBound(-1);
	m_eClassifier_EReference_eTypeParameters->setTransient(false);
	m_eClassifier_EReference_eTypeParameters->setVolatile(false);
	m_eClassifier_EReference_eTypeParameters->setChangeable(true);
	m_eClassifier_EReference_eTypeParameters->setUnsettable(false);
	m_eClassifier_EReference_eTypeParameters->setUnique(true);
	m_eClassifier_EReference_eTypeParameters->setDerived(false);
	m_eClassifier_EReference_eTypeParameters->setOrdered(true);
	m_eClassifier_EReference_eTypeParameters->setContainment(true);
	m_eClassifier_EReference_eTypeParameters->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eClassifier_EReference_eTypeParameters->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eClassifier_EReference_eTypeParameters->setEOpposite(otherEnd);
	    }
	}
	
	m_eClassifier_EOperation_isInstance_EJavaObject->setEType(getEBoolean_EDataType());
	m_eClassifier_EOperation_isInstance_EJavaObject->setName("isInstance");
	m_eClassifier_EOperation_isInstance_EJavaObject->setLowerBound(0);
	m_eClassifier_EOperation_isInstance_EJavaObject->setUpperBound(1);
	m_eClassifier_EOperation_isInstance_EJavaObject->setUnique(true);
	m_eClassifier_EOperation_isInstance_EJavaObject->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eClassifier_EOperation_isInstance_EJavaObject);
		parameter->setName("object");
		parameter->setEType(getEJavaObject_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void EcorePackageImpl::initializeEDataTypeContent()
{
	m_eDataType_EClass->setInstanceClass(nullptr);
	m_eDataType_EClass->setName("EDataType");
	m_eDataType_EClass->setAbstract(false);
	m_eDataType_EClass->setInterface(false);
	
	m_eDataType_EAttribute_serializable = getEDataType_EAttribute_serializable();
	m_eDataType_EAttribute_serializable->setName("serializable");
	m_eDataType_EAttribute_serializable->setEType(getEBoolean_EDataType());
	m_eDataType_EAttribute_serializable->setLowerBound(0);
	m_eDataType_EAttribute_serializable->setUpperBound(1);
	m_eDataType_EAttribute_serializable->setTransient(false);
	m_eDataType_EAttribute_serializable->setVolatile(false);
	m_eDataType_EAttribute_serializable->setChangeable(true);
	m_eDataType_EAttribute_serializable->setUnsettable(false);
	m_eDataType_EAttribute_serializable->setUnique(true);
	m_eDataType_EAttribute_serializable->setDerived(false);
	m_eDataType_EAttribute_serializable->setOrdered(true);
	m_eDataType_EAttribute_serializable->setID(false);
	{
		std::string defaultValue = "true";
		if (!defaultValue.empty())
		{
		   m_eDataType_EAttribute_serializable->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	
}

void EcorePackageImpl::initializeEEnumContent()
{
	m_eEnum_EClass->setInstanceClass(nullptr);
	m_eEnum_EClass->setName("EEnum");
	m_eEnum_EClass->setAbstract(false);
	m_eEnum_EClass->setInterface(false);
	
	
	m_eEnum_EReference_eLiterals->setName("eLiterals");
	m_eEnum_EReference_eLiterals->setEType(getEEnumLiteral_EClass());
	m_eEnum_EReference_eLiterals->setLowerBound(0);
	m_eEnum_EReference_eLiterals->setUpperBound(-1);
	m_eEnum_EReference_eLiterals->setTransient(false);
	m_eEnum_EReference_eLiterals->setVolatile(false);
	m_eEnum_EReference_eLiterals->setChangeable(true);
	m_eEnum_EReference_eLiterals->setUnsettable(false);
	m_eEnum_EReference_eLiterals->setUnique(true);
	m_eEnum_EReference_eLiterals->setDerived(false);
	m_eEnum_EReference_eLiterals->setOrdered(true);
	m_eEnum_EReference_eLiterals->setContainment(true);
	m_eEnum_EReference_eLiterals->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eEnum_EReference_eLiterals->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEEnumLiteral_EReference_eEnum();
		if (otherEnd != nullptr)
	    {
	   		m_eEnum_EReference_eLiterals->setEOpposite(otherEnd);
	    }
	}
	
	m_eEnum_EOperation_getEEnumLiteral_EString->setEType(getEEnumLiteral_EClass());
	m_eEnum_EOperation_getEEnumLiteral_EString->setName("getEEnumLiteral");
	m_eEnum_EOperation_getEEnumLiteral_EString->setLowerBound(0);
	m_eEnum_EOperation_getEEnumLiteral_EString->setUpperBound(1);
	m_eEnum_EOperation_getEEnumLiteral_EString->setUnique(true);
	m_eEnum_EOperation_getEEnumLiteral_EString->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eEnum_EOperation_getEEnumLiteral_EString);
		parameter->setName("name");
		parameter->setEType(getEString_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eEnum_EOperation_getEEnumLiteral_EInt->setEType(getEEnumLiteral_EClass());
	m_eEnum_EOperation_getEEnumLiteral_EInt->setName("getEEnumLiteral");
	m_eEnum_EOperation_getEEnumLiteral_EInt->setLowerBound(0);
	m_eEnum_EOperation_getEEnumLiteral_EInt->setUpperBound(1);
	m_eEnum_EOperation_getEEnumLiteral_EInt->setUnique(true);
	m_eEnum_EOperation_getEEnumLiteral_EInt->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eEnum_EOperation_getEEnumLiteral_EInt);
		parameter->setName("value");
		parameter->setEType(getEInt_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eEnum_EOperation_getEEnumLiteralByLiteral_EString->setEType(getEEnumLiteral_EClass());
	m_eEnum_EOperation_getEEnumLiteralByLiteral_EString->setName("getEEnumLiteralByLiteral");
	m_eEnum_EOperation_getEEnumLiteralByLiteral_EString->setLowerBound(0);
	m_eEnum_EOperation_getEEnumLiteralByLiteral_EString->setUpperBound(1);
	m_eEnum_EOperation_getEEnumLiteralByLiteral_EString->setUnique(true);
	m_eEnum_EOperation_getEEnumLiteralByLiteral_EString->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eEnum_EOperation_getEEnumLiteralByLiteral_EString);
		parameter->setName("literal");
		parameter->setEType(getEString_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void EcorePackageImpl::initializeEEnumLiteralContent()
{
	m_eEnumLiteral_EClass->setInstanceClass(nullptr);
	m_eEnumLiteral_EClass->setName("EEnumLiteral");
	m_eEnumLiteral_EClass->setAbstract(false);
	m_eEnumLiteral_EClass->setInterface(false);
	
	m_eEnumLiteral_EAttribute_instance = getEEnumLiteral_EAttribute_instance();
	m_eEnumLiteral_EAttribute_instance->setName("instance");
	m_eEnumLiteral_EAttribute_instance->setEType(getEEnumerator_EDataType());
	m_eEnumLiteral_EAttribute_instance->setLowerBound(0);
	m_eEnumLiteral_EAttribute_instance->setUpperBound(1);
	m_eEnumLiteral_EAttribute_instance->setTransient(true);
	m_eEnumLiteral_EAttribute_instance->setVolatile(false);
	m_eEnumLiteral_EAttribute_instance->setChangeable(true);
	m_eEnumLiteral_EAttribute_instance->setUnsettable(false);
	m_eEnumLiteral_EAttribute_instance->setUnique(true);
	m_eEnumLiteral_EAttribute_instance->setDerived(false);
	m_eEnumLiteral_EAttribute_instance->setOrdered(true);
	m_eEnumLiteral_EAttribute_instance->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eEnumLiteral_EAttribute_instance->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eEnumLiteral_EAttribute_literal = getEEnumLiteral_EAttribute_literal();
	m_eEnumLiteral_EAttribute_literal->setName("literal");
	m_eEnumLiteral_EAttribute_literal->setEType(getEString_EDataType());
	m_eEnumLiteral_EAttribute_literal->setLowerBound(0);
	m_eEnumLiteral_EAttribute_literal->setUpperBound(1);
	m_eEnumLiteral_EAttribute_literal->setTransient(false);
	m_eEnumLiteral_EAttribute_literal->setVolatile(false);
	m_eEnumLiteral_EAttribute_literal->setChangeable(true);
	m_eEnumLiteral_EAttribute_literal->setUnsettable(false);
	m_eEnumLiteral_EAttribute_literal->setUnique(true);
	m_eEnumLiteral_EAttribute_literal->setDerived(false);
	m_eEnumLiteral_EAttribute_literal->setOrdered(true);
	m_eEnumLiteral_EAttribute_literal->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eEnumLiteral_EAttribute_literal->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eEnumLiteral_EAttribute_value = getEEnumLiteral_EAttribute_value();
	m_eEnumLiteral_EAttribute_value->setName("value");
	m_eEnumLiteral_EAttribute_value->setEType(getEInt_EDataType());
	m_eEnumLiteral_EAttribute_value->setLowerBound(0);
	m_eEnumLiteral_EAttribute_value->setUpperBound(1);
	m_eEnumLiteral_EAttribute_value->setTransient(false);
	m_eEnumLiteral_EAttribute_value->setVolatile(false);
	m_eEnumLiteral_EAttribute_value->setChangeable(true);
	m_eEnumLiteral_EAttribute_value->setUnsettable(false);
	m_eEnumLiteral_EAttribute_value->setUnique(true);
	m_eEnumLiteral_EAttribute_value->setDerived(false);
	m_eEnumLiteral_EAttribute_value->setOrdered(true);
	m_eEnumLiteral_EAttribute_value->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eEnumLiteral_EAttribute_value->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_eEnumLiteral_EReference_eEnum->setName("eEnum");
	m_eEnumLiteral_EReference_eEnum->setEType(getEEnum_EClass());
	m_eEnumLiteral_EReference_eEnum->setLowerBound(0);
	m_eEnumLiteral_EReference_eEnum->setUpperBound(1);
	m_eEnumLiteral_EReference_eEnum->setTransient(true);
	m_eEnumLiteral_EReference_eEnum->setVolatile(false);
	m_eEnumLiteral_EReference_eEnum->setChangeable(false);
	m_eEnumLiteral_EReference_eEnum->setUnsettable(false);
	m_eEnumLiteral_EReference_eEnum->setUnique(true);
	m_eEnumLiteral_EReference_eEnum->setDerived(false);
	m_eEnumLiteral_EReference_eEnum->setOrdered(true);
	m_eEnumLiteral_EReference_eEnum->setContainment(false);
	m_eEnumLiteral_EReference_eEnum->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eEnumLiteral_EReference_eEnum->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEEnum_EReference_eLiterals();
		if (otherEnd != nullptr)
	    {
	   		m_eEnumLiteral_EReference_eEnum->setEOpposite(otherEnd);
	    }
	}
	
	
}

void EcorePackageImpl::initializeEFactoryContent()
{
	m_eFactory_EClass->setInstanceClass(nullptr);
	m_eFactory_EClass->setName("EFactory");
	m_eFactory_EClass->setAbstract(false);
	m_eFactory_EClass->setInterface(false);
	
	
	m_eFactory_EReference_ePackage->setName("ePackage");
	m_eFactory_EReference_ePackage->setEType(getEPackage_EClass());
	m_eFactory_EReference_ePackage->setLowerBound(1);
	m_eFactory_EReference_ePackage->setUpperBound(1);
	m_eFactory_EReference_ePackage->setTransient(true);
	m_eFactory_EReference_ePackage->setVolatile(false);
	m_eFactory_EReference_ePackage->setChangeable(true);
	m_eFactory_EReference_ePackage->setUnsettable(false);
	m_eFactory_EReference_ePackage->setUnique(true);
	m_eFactory_EReference_ePackage->setDerived(false);
	m_eFactory_EReference_ePackage->setOrdered(true);
	m_eFactory_EReference_ePackage->setContainment(false);
	m_eFactory_EReference_ePackage->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eFactory_EReference_ePackage->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEPackage_EReference_eFactoryInstance();
		if (otherEnd != nullptr)
	    {
	   		m_eFactory_EReference_ePackage->setEOpposite(otherEnd);
	    }
	}
	
	m_eFactory_EOperation_convertToString_EDataType_EJavaObject->setEType(getEString_EDataType());
	m_eFactory_EOperation_convertToString_EDataType_EJavaObject->setName("convertToString");
	m_eFactory_EOperation_convertToString_EDataType_EJavaObject->setLowerBound(0);
	m_eFactory_EOperation_convertToString_EDataType_EJavaObject->setUpperBound(1);
	m_eFactory_EOperation_convertToString_EDataType_EJavaObject->setUnique(true);
	m_eFactory_EOperation_convertToString_EDataType_EJavaObject->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eFactory_EOperation_convertToString_EDataType_EJavaObject);
		parameter->setName("eDataType");
		parameter->setEType(getEDataType_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eFactory_EOperation_convertToString_EDataType_EJavaObject);
		parameter->setName("instanceValue");
		parameter->setEType(getEJavaObject_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eFactory_EOperation_create_EClass_EObject->setEType(getEObject_EClass());
	m_eFactory_EOperation_create_EClass_EObject->setName("create");
	m_eFactory_EOperation_create_EClass_EObject->setLowerBound(0);
	m_eFactory_EOperation_create_EClass_EObject->setUpperBound(1);
	m_eFactory_EOperation_create_EClass_EObject->setUnique(true);
	m_eFactory_EOperation_create_EClass_EObject->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eFactory_EOperation_create_EClass_EObject);
		parameter->setName("eClass");
		parameter->setEType(getEClass_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eFactory_EOperation_create_EClass_EObject);
		parameter->setName("container");
		parameter->setEType(getEObject_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eFactory_EOperation_createFromString_EDataType_EString->setEType(getEJavaObject_EDataType());
	m_eFactory_EOperation_createFromString_EDataType_EString->setName("createFromString");
	m_eFactory_EOperation_createFromString_EDataType_EString->setLowerBound(0);
	m_eFactory_EOperation_createFromString_EDataType_EString->setUpperBound(1);
	m_eFactory_EOperation_createFromString_EDataType_EString->setUnique(true);
	m_eFactory_EOperation_createFromString_EDataType_EString->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eFactory_EOperation_createFromString_EDataType_EString);
		parameter->setName("eDataType");
		parameter->setEType(getEDataType_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eFactory_EOperation_createFromString_EDataType_EString);
		parameter->setName("literalValue");
		parameter->setEType(getEString_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void EcorePackageImpl::initializeEGenericTypeContent()
{
	m_eGenericType_EClass->setInstanceClass(nullptr);
	m_eGenericType_EClass->setName("EGenericType");
	m_eGenericType_EClass->setAbstract(false);
	m_eGenericType_EClass->setInterface(false);
	
	
	m_eGenericType_EReference_eClassifier->setName("eClassifier");
	m_eGenericType_EReference_eClassifier->setEType(getEClassifier_EClass());
	m_eGenericType_EReference_eClassifier->setLowerBound(0);
	m_eGenericType_EReference_eClassifier->setUpperBound(1);
	m_eGenericType_EReference_eClassifier->setTransient(false);
	m_eGenericType_EReference_eClassifier->setVolatile(false);
	m_eGenericType_EReference_eClassifier->setChangeable(true);
	m_eGenericType_EReference_eClassifier->setUnsettable(false);
	m_eGenericType_EReference_eClassifier->setUnique(true);
	m_eGenericType_EReference_eClassifier->setDerived(false);
	m_eGenericType_EReference_eClassifier->setOrdered(true);
	m_eGenericType_EReference_eClassifier->setContainment(false);
	m_eGenericType_EReference_eClassifier->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eGenericType_EReference_eClassifier->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eGenericType_EReference_eClassifier->setEOpposite(otherEnd);
	    }
	}
	m_eGenericType_EReference_eLowerBound->setName("eLowerBound");
	m_eGenericType_EReference_eLowerBound->setEType(getEGenericType_EClass());
	m_eGenericType_EReference_eLowerBound->setLowerBound(0);
	m_eGenericType_EReference_eLowerBound->setUpperBound(1);
	m_eGenericType_EReference_eLowerBound->setTransient(false);
	m_eGenericType_EReference_eLowerBound->setVolatile(false);
	m_eGenericType_EReference_eLowerBound->setChangeable(true);
	m_eGenericType_EReference_eLowerBound->setUnsettable(false);
	m_eGenericType_EReference_eLowerBound->setUnique(true);
	m_eGenericType_EReference_eLowerBound->setDerived(false);
	m_eGenericType_EReference_eLowerBound->setOrdered(true);
	m_eGenericType_EReference_eLowerBound->setContainment(true);
	m_eGenericType_EReference_eLowerBound->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eGenericType_EReference_eLowerBound->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eGenericType_EReference_eLowerBound->setEOpposite(otherEnd);
	    }
	}
	m_eGenericType_EReference_eRawType->setName("eRawType");
	m_eGenericType_EReference_eRawType->setEType(getEClassifier_EClass());
	m_eGenericType_EReference_eRawType->setLowerBound(1);
	m_eGenericType_EReference_eRawType->setUpperBound(1);
	m_eGenericType_EReference_eRawType->setTransient(true);
	m_eGenericType_EReference_eRawType->setVolatile(false);
	m_eGenericType_EReference_eRawType->setChangeable(false);
	m_eGenericType_EReference_eRawType->setUnsettable(false);
	m_eGenericType_EReference_eRawType->setUnique(true);
	m_eGenericType_EReference_eRawType->setDerived(true);
	m_eGenericType_EReference_eRawType->setOrdered(true);
	m_eGenericType_EReference_eRawType->setContainment(false);
	m_eGenericType_EReference_eRawType->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eGenericType_EReference_eRawType->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eGenericType_EReference_eRawType->setEOpposite(otherEnd);
	    }
	}
	m_eGenericType_EReference_eTypeArguments->setName("eTypeArguments");
	m_eGenericType_EReference_eTypeArguments->setEType(getEGenericType_EClass());
	m_eGenericType_EReference_eTypeArguments->setLowerBound(0);
	m_eGenericType_EReference_eTypeArguments->setUpperBound(-1);
	m_eGenericType_EReference_eTypeArguments->setTransient(false);
	m_eGenericType_EReference_eTypeArguments->setVolatile(false);
	m_eGenericType_EReference_eTypeArguments->setChangeable(true);
	m_eGenericType_EReference_eTypeArguments->setUnsettable(false);
	m_eGenericType_EReference_eTypeArguments->setUnique(true);
	m_eGenericType_EReference_eTypeArguments->setDerived(false);
	m_eGenericType_EReference_eTypeArguments->setOrdered(true);
	m_eGenericType_EReference_eTypeArguments->setContainment(true);
	m_eGenericType_EReference_eTypeArguments->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eGenericType_EReference_eTypeArguments->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eGenericType_EReference_eTypeArguments->setEOpposite(otherEnd);
	    }
	}
	m_eGenericType_EReference_eTypeParameter->setName("eTypeParameter");
	m_eGenericType_EReference_eTypeParameter->setEType(getETypeParameter_EClass());
	m_eGenericType_EReference_eTypeParameter->setLowerBound(0);
	m_eGenericType_EReference_eTypeParameter->setUpperBound(1);
	m_eGenericType_EReference_eTypeParameter->setTransient(false);
	m_eGenericType_EReference_eTypeParameter->setVolatile(false);
	m_eGenericType_EReference_eTypeParameter->setChangeable(true);
	m_eGenericType_EReference_eTypeParameter->setUnsettable(false);
	m_eGenericType_EReference_eTypeParameter->setUnique(true);
	m_eGenericType_EReference_eTypeParameter->setDerived(false);
	m_eGenericType_EReference_eTypeParameter->setOrdered(true);
	m_eGenericType_EReference_eTypeParameter->setContainment(false);
	m_eGenericType_EReference_eTypeParameter->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eGenericType_EReference_eTypeParameter->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eGenericType_EReference_eTypeParameter->setEOpposite(otherEnd);
	    }
	}
	m_eGenericType_EReference_eUpperBound->setName("eUpperBound");
	m_eGenericType_EReference_eUpperBound->setEType(getEGenericType_EClass());
	m_eGenericType_EReference_eUpperBound->setLowerBound(0);
	m_eGenericType_EReference_eUpperBound->setUpperBound(1);
	m_eGenericType_EReference_eUpperBound->setTransient(false);
	m_eGenericType_EReference_eUpperBound->setVolatile(false);
	m_eGenericType_EReference_eUpperBound->setChangeable(true);
	m_eGenericType_EReference_eUpperBound->setUnsettable(false);
	m_eGenericType_EReference_eUpperBound->setUnique(true);
	m_eGenericType_EReference_eUpperBound->setDerived(false);
	m_eGenericType_EReference_eUpperBound->setOrdered(true);
	m_eGenericType_EReference_eUpperBound->setContainment(true);
	m_eGenericType_EReference_eUpperBound->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eGenericType_EReference_eUpperBound->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eGenericType_EReference_eUpperBound->setEOpposite(otherEnd);
	    }
	}
	
	m_eGenericType_EOperation_isInstance_EJavaObject->setEType(getEBoolean_EDataType());
	m_eGenericType_EOperation_isInstance_EJavaObject->setName("isInstance");
	m_eGenericType_EOperation_isInstance_EJavaObject->setLowerBound(0);
	m_eGenericType_EOperation_isInstance_EJavaObject->setUpperBound(1);
	m_eGenericType_EOperation_isInstance_EJavaObject->setUnique(true);
	m_eGenericType_EOperation_isInstance_EJavaObject->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eGenericType_EOperation_isInstance_EJavaObject);
		parameter->setName("object");
		parameter->setEType(getEJavaObject_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void EcorePackageImpl::initializeEModelElementContent()
{
	m_eModelElement_EClass->setInstanceClass(nullptr);
	m_eModelElement_EClass->setName("EModelElement");
	m_eModelElement_EClass->setAbstract(true);
	m_eModelElement_EClass->setInterface(false);
	
	
	m_eModelElement_EReference_eAnnotations->setName("eAnnotations");
	m_eModelElement_EReference_eAnnotations->setEType(getEAnnotation_EClass());
	m_eModelElement_EReference_eAnnotations->setLowerBound(0);
	m_eModelElement_EReference_eAnnotations->setUpperBound(-1);
	m_eModelElement_EReference_eAnnotations->setTransient(false);
	m_eModelElement_EReference_eAnnotations->setVolatile(false);
	m_eModelElement_EReference_eAnnotations->setChangeable(true);
	m_eModelElement_EReference_eAnnotations->setUnsettable(false);
	m_eModelElement_EReference_eAnnotations->setUnique(true);
	m_eModelElement_EReference_eAnnotations->setDerived(false);
	m_eModelElement_EReference_eAnnotations->setOrdered(true);
	m_eModelElement_EReference_eAnnotations->setContainment(true);
	m_eModelElement_EReference_eAnnotations->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eModelElement_EReference_eAnnotations->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEAnnotation_EReference_eModelElement();
		if (otherEnd != nullptr)
	    {
	   		m_eModelElement_EReference_eAnnotations->setEOpposite(otherEnd);
	    }
	}
	
	m_eModelElement_EOperation_getEAnnotation_EString->setEType(getEAnnotation_EClass());
	m_eModelElement_EOperation_getEAnnotation_EString->setName("getEAnnotation");
	m_eModelElement_EOperation_getEAnnotation_EString->setLowerBound(0);
	m_eModelElement_EOperation_getEAnnotation_EString->setUpperBound(1);
	m_eModelElement_EOperation_getEAnnotation_EString->setUnique(true);
	m_eModelElement_EOperation_getEAnnotation_EString->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eModelElement_EOperation_getEAnnotation_EString);
		parameter->setName("source");
		parameter->setEType(getEString_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void EcorePackageImpl::initializeENamedElementContent()
{
	m_eNamedElement_EClass->setInstanceClass(nullptr);
	m_eNamedElement_EClass->setName("ENamedElement");
	m_eNamedElement_EClass->setAbstract(true);
	m_eNamedElement_EClass->setInterface(false);
	
	m_eNamedElement_EAttribute_name = getENamedElement_EAttribute_name();
	m_eNamedElement_EAttribute_name->setName("name");
	m_eNamedElement_EAttribute_name->setEType(getEString_EDataType());
	m_eNamedElement_EAttribute_name->setLowerBound(0);
	m_eNamedElement_EAttribute_name->setUpperBound(1);
	m_eNamedElement_EAttribute_name->setTransient(false);
	m_eNamedElement_EAttribute_name->setVolatile(false);
	m_eNamedElement_EAttribute_name->setChangeable(true);
	m_eNamedElement_EAttribute_name->setUnsettable(false);
	m_eNamedElement_EAttribute_name->setUnique(true);
	m_eNamedElement_EAttribute_name->setDerived(false);
	m_eNamedElement_EAttribute_name->setOrdered(true);
	m_eNamedElement_EAttribute_name->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eNamedElement_EAttribute_name->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	
}

void EcorePackageImpl::initializeEObjectContent()
{
	m_eObject_EClass->setInstanceClass(nullptr);
	m_eObject_EClass->setName("EObject");
	m_eObject_EClass->setAbstract(false);
	m_eObject_EClass->setInterface(false);
	
	
	m_eObject_EReference_eContainer->setName("eContainer");
	m_eObject_EReference_eContainer->setEType(getEObject_EClass());
	m_eObject_EReference_eContainer->setLowerBound(0);
	m_eObject_EReference_eContainer->setUpperBound(1);
	m_eObject_EReference_eContainer->setTransient(false);
	m_eObject_EReference_eContainer->setVolatile(false);
	m_eObject_EReference_eContainer->setChangeable(false);
	m_eObject_EReference_eContainer->setUnsettable(false);
	m_eObject_EReference_eContainer->setUnique(true);
	m_eObject_EReference_eContainer->setDerived(false);
	m_eObject_EReference_eContainer->setOrdered(true);
	m_eObject_EReference_eContainer->setContainment(false);
	m_eObject_EReference_eContainer->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eObject_EReference_eContainer->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eObject_EReference_eContainer->setEOpposite(otherEnd);
	    }
	}
	
	m_eObject_EOperation_eAllContents->setEType(getETreeIterator_EDataType());
	m_eObject_EOperation_eAllContents->setName("eAllContents");
	m_eObject_EOperation_eAllContents->setLowerBound(0);
	m_eObject_EOperation_eAllContents->setUpperBound(1);
	m_eObject_EOperation_eAllContents->setUnique(true);
	m_eObject_EOperation_eAllContents->setOrdered(true);
	
	
	m_eObject_EOperation_eClass->setEType(getEClass_EClass());
	m_eObject_EOperation_eClass->setName("eClass");
	m_eObject_EOperation_eClass->setLowerBound(0);
	m_eObject_EOperation_eClass->setUpperBound(1);
	m_eObject_EOperation_eClass->setUnique(true);
	m_eObject_EOperation_eClass->setOrdered(true);
	
	
	m_eObject_EOperation_eContainingFeature->setEType(getEStructuralFeature_EClass());
	m_eObject_EOperation_eContainingFeature->setName("eContainingFeature");
	m_eObject_EOperation_eContainingFeature->setLowerBound(0);
	m_eObject_EOperation_eContainingFeature->setUpperBound(1);
	m_eObject_EOperation_eContainingFeature->setUnique(true);
	m_eObject_EOperation_eContainingFeature->setOrdered(true);
	
	
	m_eObject_EOperation_eContainmentFeature->setEType(getEReference_EClass());
	m_eObject_EOperation_eContainmentFeature->setName("eContainmentFeature");
	m_eObject_EOperation_eContainmentFeature->setLowerBound(0);
	m_eObject_EOperation_eContainmentFeature->setUpperBound(1);
	m_eObject_EOperation_eContainmentFeature->setUnique(true);
	m_eObject_EOperation_eContainmentFeature->setOrdered(true);
	
	
	m_eObject_EOperation_eContents->setEType(getEEList_EDataType());
	m_eObject_EOperation_eContents->setName("eContents");
	m_eObject_EOperation_eContents->setLowerBound(0);
	m_eObject_EOperation_eContents->setUpperBound(1);
	m_eObject_EOperation_eContents->setUnique(true);
	m_eObject_EOperation_eContents->setOrdered(true);
	
	
	m_eObject_EOperation_eCrossReferences->setEType(getEEList_EDataType());
	m_eObject_EOperation_eCrossReferences->setName("eCrossReferences");
	m_eObject_EOperation_eCrossReferences->setLowerBound(0);
	m_eObject_EOperation_eCrossReferences->setUpperBound(1);
	m_eObject_EOperation_eCrossReferences->setUnique(true);
	m_eObject_EOperation_eCrossReferences->setOrdered(true);
	
	
	m_eObject_EOperation_eGet_EStructuralFeature->setEType(getEJavaObject_EDataType());
	m_eObject_EOperation_eGet_EStructuralFeature->setName("eGet");
	m_eObject_EOperation_eGet_EStructuralFeature->setLowerBound(0);
	m_eObject_EOperation_eGet_EStructuralFeature->setUpperBound(1);
	m_eObject_EOperation_eGet_EStructuralFeature->setUnique(true);
	m_eObject_EOperation_eGet_EStructuralFeature->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eObject_EOperation_eGet_EStructuralFeature);
		parameter->setName("feature");
		parameter->setEType(getEStructuralFeature_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eObject_EOperation_eGet_EStructuralFeature_EBoolean->setEType(getEJavaObject_EDataType());
	m_eObject_EOperation_eGet_EStructuralFeature_EBoolean->setName("eGet");
	m_eObject_EOperation_eGet_EStructuralFeature_EBoolean->setLowerBound(0);
	m_eObject_EOperation_eGet_EStructuralFeature_EBoolean->setUpperBound(1);
	m_eObject_EOperation_eGet_EStructuralFeature_EBoolean->setUnique(true);
	m_eObject_EOperation_eGet_EStructuralFeature_EBoolean->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eObject_EOperation_eGet_EStructuralFeature_EBoolean);
		parameter->setName("feature");
		parameter->setEType(getEStructuralFeature_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eObject_EOperation_eGet_EStructuralFeature_EBoolean);
		parameter->setName("resolve");
		parameter->setEType(getEBoolean_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eObject_EOperation_eInvoke_EOperation_EEList->setEType(getEJavaObject_EDataType());
	m_eObject_EOperation_eInvoke_EOperation_EEList->setName("eInvoke");
	m_eObject_EOperation_eInvoke_EOperation_EEList->setLowerBound(0);
	m_eObject_EOperation_eInvoke_EOperation_EEList->setUpperBound(1);
	m_eObject_EOperation_eInvoke_EOperation_EEList->setUnique(true);
	m_eObject_EOperation_eInvoke_EOperation_EEList->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eObject_EOperation_eInvoke_EOperation_EEList);
		parameter->setName("operation");
		parameter->setEType(getEOperation_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eObject_EOperation_eInvoke_EOperation_EEList);
		parameter->setName("arguments");
		parameter->setEType(getEEList_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eObject_EOperation_eIsProxy->setEType(getEBoolean_EDataType());
	m_eObject_EOperation_eIsProxy->setName("eIsProxy");
	m_eObject_EOperation_eIsProxy->setLowerBound(0);
	m_eObject_EOperation_eIsProxy->setUpperBound(1);
	m_eObject_EOperation_eIsProxy->setUnique(true);
	m_eObject_EOperation_eIsProxy->setOrdered(true);
	
	
	m_eObject_EOperation_eIsSet_EStructuralFeature->setEType(getEBoolean_EDataType());
	m_eObject_EOperation_eIsSet_EStructuralFeature->setName("eIsSet");
	m_eObject_EOperation_eIsSet_EStructuralFeature->setLowerBound(0);
	m_eObject_EOperation_eIsSet_EStructuralFeature->setUpperBound(1);
	m_eObject_EOperation_eIsSet_EStructuralFeature->setUnique(true);
	m_eObject_EOperation_eIsSet_EStructuralFeature->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eObject_EOperation_eIsSet_EStructuralFeature);
		parameter->setName("feature");
		parameter->setEType(getEStructuralFeature_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eObject_EOperation_eResource->setEType(getEResource_EDataType());
	m_eObject_EOperation_eResource->setName("eResource");
	m_eObject_EOperation_eResource->setLowerBound(0);
	m_eObject_EOperation_eResource->setUpperBound(1);
	m_eObject_EOperation_eResource->setUnique(true);
	m_eObject_EOperation_eResource->setOrdered(true);
	
	
	m_eObject_EOperation_eSet_EStructuralFeature_EJavaObject->setEType(nullptr);
	m_eObject_EOperation_eSet_EStructuralFeature_EJavaObject->setName("eSet");
	m_eObject_EOperation_eSet_EStructuralFeature_EJavaObject->setLowerBound(0);
	m_eObject_EOperation_eSet_EStructuralFeature_EJavaObject->setUpperBound(1);
	m_eObject_EOperation_eSet_EStructuralFeature_EJavaObject->setUnique(true);
	m_eObject_EOperation_eSet_EStructuralFeature_EJavaObject->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eObject_EOperation_eSet_EStructuralFeature_EJavaObject);
		parameter->setName("feature");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eObject_EOperation_eSet_EStructuralFeature_EJavaObject);
		parameter->setName("newValue");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eObject_EOperation_eUnset_EStructuralFeature->setEType(nullptr);
	m_eObject_EOperation_eUnset_EStructuralFeature->setName("eUnset");
	m_eObject_EOperation_eUnset_EStructuralFeature->setLowerBound(0);
	m_eObject_EOperation_eUnset_EStructuralFeature->setUpperBound(1);
	m_eObject_EOperation_eUnset_EStructuralFeature->setUnique(true);
	m_eObject_EOperation_eUnset_EStructuralFeature->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eObject_EOperation_eUnset_EStructuralFeature);
		parameter->setName("feature");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void EcorePackageImpl::initializeEOperationContent()
{
	m_eOperation_EClass->setInstanceClass(nullptr);
	m_eOperation_EClass->setName("EOperation");
	m_eOperation_EClass->setAbstract(false);
	m_eOperation_EClass->setInterface(false);
	
	m_eOperation_EAttribute_operationID = getEOperation_EAttribute_operationID();
	m_eOperation_EAttribute_operationID->setName("operationID");
	m_eOperation_EAttribute_operationID->setEType(getEInt_EDataType());
	m_eOperation_EAttribute_operationID->setLowerBound(0);
	m_eOperation_EAttribute_operationID->setUpperBound(1);
	m_eOperation_EAttribute_operationID->setTransient(false);
	m_eOperation_EAttribute_operationID->setVolatile(false);
	m_eOperation_EAttribute_operationID->setChangeable(false);
	m_eOperation_EAttribute_operationID->setUnsettable(false);
	m_eOperation_EAttribute_operationID->setUnique(true);
	m_eOperation_EAttribute_operationID->setDerived(false);
	m_eOperation_EAttribute_operationID->setOrdered(true);
	m_eOperation_EAttribute_operationID->setID(false);
	{
		std::string defaultValue = "-1";
		if (!defaultValue.empty())
		{
		   m_eOperation_EAttribute_operationID->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_eOperation_EReference_eContainingClass->setName("eContainingClass");
	m_eOperation_EReference_eContainingClass->setEType(getEClass_EClass());
	m_eOperation_EReference_eContainingClass->setLowerBound(0);
	m_eOperation_EReference_eContainingClass->setUpperBound(1);
	m_eOperation_EReference_eContainingClass->setTransient(true);
	m_eOperation_EReference_eContainingClass->setVolatile(false);
	m_eOperation_EReference_eContainingClass->setChangeable(false);
	m_eOperation_EReference_eContainingClass->setUnsettable(false);
	m_eOperation_EReference_eContainingClass->setUnique(true);
	m_eOperation_EReference_eContainingClass->setDerived(false);
	m_eOperation_EReference_eContainingClass->setOrdered(true);
	m_eOperation_EReference_eContainingClass->setContainment(false);
	m_eOperation_EReference_eContainingClass->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eOperation_EReference_eContainingClass->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEClass_EReference_eOperations();
		if (otherEnd != nullptr)
	    {
	   		m_eOperation_EReference_eContainingClass->setEOpposite(otherEnd);
	    }
	}
	m_eOperation_EReference_eExceptions->setName("eExceptions");
	m_eOperation_EReference_eExceptions->setEType(getEClassifier_EClass());
	m_eOperation_EReference_eExceptions->setLowerBound(0);
	m_eOperation_EReference_eExceptions->setUpperBound(-1);
	m_eOperation_EReference_eExceptions->setTransient(false);
	m_eOperation_EReference_eExceptions->setVolatile(false);
	m_eOperation_EReference_eExceptions->setChangeable(true);
	m_eOperation_EReference_eExceptions->setUnsettable(true);
	m_eOperation_EReference_eExceptions->setUnique(true);
	m_eOperation_EReference_eExceptions->setDerived(false);
	m_eOperation_EReference_eExceptions->setOrdered(true);
	m_eOperation_EReference_eExceptions->setContainment(false);
	m_eOperation_EReference_eExceptions->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eOperation_EReference_eExceptions->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eOperation_EReference_eExceptions->setEOpposite(otherEnd);
	    }
	}
	m_eOperation_EReference_eGenericExceptions->setName("eGenericExceptions");
	m_eOperation_EReference_eGenericExceptions->setEType(getEGenericType_EClass());
	m_eOperation_EReference_eGenericExceptions->setLowerBound(0);
	m_eOperation_EReference_eGenericExceptions->setUpperBound(-1);
	m_eOperation_EReference_eGenericExceptions->setTransient(false);
	m_eOperation_EReference_eGenericExceptions->setVolatile(false);
	m_eOperation_EReference_eGenericExceptions->setChangeable(true);
	m_eOperation_EReference_eGenericExceptions->setUnsettable(true);
	m_eOperation_EReference_eGenericExceptions->setUnique(true);
	m_eOperation_EReference_eGenericExceptions->setDerived(false);
	m_eOperation_EReference_eGenericExceptions->setOrdered(true);
	m_eOperation_EReference_eGenericExceptions->setContainment(true);
	m_eOperation_EReference_eGenericExceptions->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eOperation_EReference_eGenericExceptions->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eOperation_EReference_eGenericExceptions->setEOpposite(otherEnd);
	    }
	}
	m_eOperation_EReference_eParameters->setName("eParameters");
	m_eOperation_EReference_eParameters->setEType(getEParameter_EClass());
	m_eOperation_EReference_eParameters->setLowerBound(0);
	m_eOperation_EReference_eParameters->setUpperBound(-1);
	m_eOperation_EReference_eParameters->setTransient(false);
	m_eOperation_EReference_eParameters->setVolatile(false);
	m_eOperation_EReference_eParameters->setChangeable(true);
	m_eOperation_EReference_eParameters->setUnsettable(false);
	m_eOperation_EReference_eParameters->setUnique(true);
	m_eOperation_EReference_eParameters->setDerived(false);
	m_eOperation_EReference_eParameters->setOrdered(true);
	m_eOperation_EReference_eParameters->setContainment(true);
	m_eOperation_EReference_eParameters->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eOperation_EReference_eParameters->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEParameter_EReference_eOperation();
		if (otherEnd != nullptr)
	    {
	   		m_eOperation_EReference_eParameters->setEOpposite(otherEnd);
	    }
	}
	m_eOperation_EReference_eTypeParameters->setName("eTypeParameters");
	m_eOperation_EReference_eTypeParameters->setEType(getETypeParameter_EClass());
	m_eOperation_EReference_eTypeParameters->setLowerBound(0);
	m_eOperation_EReference_eTypeParameters->setUpperBound(-1);
	m_eOperation_EReference_eTypeParameters->setTransient(false);
	m_eOperation_EReference_eTypeParameters->setVolatile(false);
	m_eOperation_EReference_eTypeParameters->setChangeable(true);
	m_eOperation_EReference_eTypeParameters->setUnsettable(false);
	m_eOperation_EReference_eTypeParameters->setUnique(true);
	m_eOperation_EReference_eTypeParameters->setDerived(false);
	m_eOperation_EReference_eTypeParameters->setOrdered(true);
	m_eOperation_EReference_eTypeParameters->setContainment(true);
	m_eOperation_EReference_eTypeParameters->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eOperation_EReference_eTypeParameters->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eOperation_EReference_eTypeParameters->setEOpposite(otherEnd);
	    }
	}
	
	m_eOperation_EOperation_isOverrideOf_EOperation->setEType(getEBoolean_EDataType());
	m_eOperation_EOperation_isOverrideOf_EOperation->setName("isOverrideOf");
	m_eOperation_EOperation_isOverrideOf_EOperation->setLowerBound(0);
	m_eOperation_EOperation_isOverrideOf_EOperation->setUpperBound(1);
	m_eOperation_EOperation_isOverrideOf_EOperation->setUnique(true);
	m_eOperation_EOperation_isOverrideOf_EOperation->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eOperation_EOperation_isOverrideOf_EOperation);
		parameter->setName("someOperation");
		parameter->setEType(getEOperation_EClass());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void EcorePackageImpl::initializeEPackageContent()
{
	m_ePackage_EClass->setInstanceClass(nullptr);
	m_ePackage_EClass->setName("EPackage");
	m_ePackage_EClass->setAbstract(false);
	m_ePackage_EClass->setInterface(false);
	
	m_ePackage_EAttribute_nsPrefix = getEPackage_EAttribute_nsPrefix();
	m_ePackage_EAttribute_nsPrefix->setName("nsPrefix");
	m_ePackage_EAttribute_nsPrefix->setEType(getEString_EDataType());
	m_ePackage_EAttribute_nsPrefix->setLowerBound(0);
	m_ePackage_EAttribute_nsPrefix->setUpperBound(1);
	m_ePackage_EAttribute_nsPrefix->setTransient(false);
	m_ePackage_EAttribute_nsPrefix->setVolatile(false);
	m_ePackage_EAttribute_nsPrefix->setChangeable(true);
	m_ePackage_EAttribute_nsPrefix->setUnsettable(false);
	m_ePackage_EAttribute_nsPrefix->setUnique(true);
	m_ePackage_EAttribute_nsPrefix->setDerived(false);
	m_ePackage_EAttribute_nsPrefix->setOrdered(true);
	m_ePackage_EAttribute_nsPrefix->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_ePackage_EAttribute_nsPrefix->setDefaultValueLiteral(defaultValue);
		}
	}
	m_ePackage_EAttribute_nsURI = getEPackage_EAttribute_nsURI();
	m_ePackage_EAttribute_nsURI->setName("nsURI");
	m_ePackage_EAttribute_nsURI->setEType(getEString_EDataType());
	m_ePackage_EAttribute_nsURI->setLowerBound(0);
	m_ePackage_EAttribute_nsURI->setUpperBound(1);
	m_ePackage_EAttribute_nsURI->setTransient(false);
	m_ePackage_EAttribute_nsURI->setVolatile(false);
	m_ePackage_EAttribute_nsURI->setChangeable(true);
	m_ePackage_EAttribute_nsURI->setUnsettable(false);
	m_ePackage_EAttribute_nsURI->setUnique(true);
	m_ePackage_EAttribute_nsURI->setDerived(false);
	m_ePackage_EAttribute_nsURI->setOrdered(true);
	m_ePackage_EAttribute_nsURI->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_ePackage_EAttribute_nsURI->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_ePackage_EReference_eClassifiers->setName("eClassifiers");
	m_ePackage_EReference_eClassifiers->setEType(getEClassifier_EClass());
	m_ePackage_EReference_eClassifiers->setLowerBound(0);
	m_ePackage_EReference_eClassifiers->setUpperBound(-1);
	m_ePackage_EReference_eClassifiers->setTransient(false);
	m_ePackage_EReference_eClassifiers->setVolatile(false);
	m_ePackage_EReference_eClassifiers->setChangeable(true);
	m_ePackage_EReference_eClassifiers->setUnsettable(false);
	m_ePackage_EReference_eClassifiers->setUnique(true);
	m_ePackage_EReference_eClassifiers->setDerived(false);
	m_ePackage_EReference_eClassifiers->setOrdered(true);
	m_ePackage_EReference_eClassifiers->setContainment(true);
	m_ePackage_EReference_eClassifiers->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_ePackage_EReference_eClassifiers->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEClassifier_EReference_ePackage();
		if (otherEnd != nullptr)
	    {
	   		m_ePackage_EReference_eClassifiers->setEOpposite(otherEnd);
	    }
	}
	m_ePackage_EReference_eFactoryInstance->setName("eFactoryInstance");
	m_ePackage_EReference_eFactoryInstance->setEType(getEFactory_EClass());
	m_ePackage_EReference_eFactoryInstance->setLowerBound(1);
	m_ePackage_EReference_eFactoryInstance->setUpperBound(1);
	m_ePackage_EReference_eFactoryInstance->setTransient(true);
	m_ePackage_EReference_eFactoryInstance->setVolatile(false);
	m_ePackage_EReference_eFactoryInstance->setChangeable(true);
	m_ePackage_EReference_eFactoryInstance->setUnsettable(false);
	m_ePackage_EReference_eFactoryInstance->setUnique(true);
	m_ePackage_EReference_eFactoryInstance->setDerived(false);
	m_ePackage_EReference_eFactoryInstance->setOrdered(true);
	m_ePackage_EReference_eFactoryInstance->setContainment(false);
	m_ePackage_EReference_eFactoryInstance->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_ePackage_EReference_eFactoryInstance->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEFactory_EReference_ePackage();
		if (otherEnd != nullptr)
	    {
	   		m_ePackage_EReference_eFactoryInstance->setEOpposite(otherEnd);
	    }
	}
	m_ePackage_EReference_eSubpackages->setName("eSubpackages");
	m_ePackage_EReference_eSubpackages->setEType(getEPackage_EClass());
	m_ePackage_EReference_eSubpackages->setLowerBound(0);
	m_ePackage_EReference_eSubpackages->setUpperBound(-1);
	m_ePackage_EReference_eSubpackages->setTransient(false);
	m_ePackage_EReference_eSubpackages->setVolatile(false);
	m_ePackage_EReference_eSubpackages->setChangeable(true);
	m_ePackage_EReference_eSubpackages->setUnsettable(false);
	m_ePackage_EReference_eSubpackages->setUnique(true);
	m_ePackage_EReference_eSubpackages->setDerived(false);
	m_ePackage_EReference_eSubpackages->setOrdered(true);
	m_ePackage_EReference_eSubpackages->setContainment(true);
	m_ePackage_EReference_eSubpackages->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_ePackage_EReference_eSubpackages->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEPackage_EReference_eSuperPackage();
		if (otherEnd != nullptr)
	    {
	   		m_ePackage_EReference_eSubpackages->setEOpposite(otherEnd);
	    }
	}
	m_ePackage_EReference_eSuperPackage->setName("eSuperPackage");
	m_ePackage_EReference_eSuperPackage->setEType(getEPackage_EClass());
	m_ePackage_EReference_eSuperPackage->setLowerBound(0);
	m_ePackage_EReference_eSuperPackage->setUpperBound(1);
	m_ePackage_EReference_eSuperPackage->setTransient(true);
	m_ePackage_EReference_eSuperPackage->setVolatile(false);
	m_ePackage_EReference_eSuperPackage->setChangeable(false);
	m_ePackage_EReference_eSuperPackage->setUnsettable(false);
	m_ePackage_EReference_eSuperPackage->setUnique(true);
	m_ePackage_EReference_eSuperPackage->setDerived(false);
	m_ePackage_EReference_eSuperPackage->setOrdered(true);
	m_ePackage_EReference_eSuperPackage->setContainment(false);
	m_ePackage_EReference_eSuperPackage->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_ePackage_EReference_eSuperPackage->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEPackage_EReference_eSubpackages();
		if (otherEnd != nullptr)
	    {
	   		m_ePackage_EReference_eSuperPackage->setEOpposite(otherEnd);
	    }
	}
	
	m_ePackage_EOperation_getEClassifier_EString->setEType(getEClassifier_EClass());
	m_ePackage_EOperation_getEClassifier_EString->setName("getEClassifier");
	m_ePackage_EOperation_getEClassifier_EString->setLowerBound(0);
	m_ePackage_EOperation_getEClassifier_EString->setUpperBound(1);
	m_ePackage_EOperation_getEClassifier_EString->setUnique(true);
	m_ePackage_EOperation_getEClassifier_EString->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_ePackage_EOperation_getEClassifier_EString);
		parameter->setName("name");
		parameter->setEType(getEString_EDataType());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void EcorePackageImpl::initializeEParameterContent()
{
	m_eParameter_EClass->setInstanceClass(nullptr);
	m_eParameter_EClass->setName("EParameter");
	m_eParameter_EClass->setAbstract(false);
	m_eParameter_EClass->setInterface(false);
	
	
	m_eParameter_EReference_eOperation->setName("eOperation");
	m_eParameter_EReference_eOperation->setEType(getEOperation_EClass());
	m_eParameter_EReference_eOperation->setLowerBound(0);
	m_eParameter_EReference_eOperation->setUpperBound(1);
	m_eParameter_EReference_eOperation->setTransient(true);
	m_eParameter_EReference_eOperation->setVolatile(false);
	m_eParameter_EReference_eOperation->setChangeable(false);
	m_eParameter_EReference_eOperation->setUnsettable(false);
	m_eParameter_EReference_eOperation->setUnique(true);
	m_eParameter_EReference_eOperation->setDerived(false);
	m_eParameter_EReference_eOperation->setOrdered(true);
	m_eParameter_EReference_eOperation->setContainment(false);
	m_eParameter_EReference_eOperation->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eParameter_EReference_eOperation->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEOperation_EReference_eParameters();
		if (otherEnd != nullptr)
	    {
	   		m_eParameter_EReference_eOperation->setEOpposite(otherEnd);
	    }
	}
	
	
}

void EcorePackageImpl::initializeEReferenceContent()
{
	m_eReference_EClass->setInstanceClass(nullptr);
	m_eReference_EClass->setName("EReference");
	m_eReference_EClass->setAbstract(false);
	m_eReference_EClass->setInterface(false);
	
	m_eReference_EAttribute_container = getEReference_EAttribute_container();
	m_eReference_EAttribute_container->setName("container");
	m_eReference_EAttribute_container->setEType(getEBoolean_EDataType());
	m_eReference_EAttribute_container->setLowerBound(0);
	m_eReference_EAttribute_container->setUpperBound(1);
	m_eReference_EAttribute_container->setTransient(true);
	m_eReference_EAttribute_container->setVolatile(true);
	m_eReference_EAttribute_container->setChangeable(false);
	m_eReference_EAttribute_container->setUnsettable(false);
	m_eReference_EAttribute_container->setUnique(true);
	m_eReference_EAttribute_container->setDerived(true);
	m_eReference_EAttribute_container->setOrdered(true);
	m_eReference_EAttribute_container->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eReference_EAttribute_container->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eReference_EAttribute_containment = getEReference_EAttribute_containment();
	m_eReference_EAttribute_containment->setName("containment");
	m_eReference_EAttribute_containment->setEType(getEBoolean_EDataType());
	m_eReference_EAttribute_containment->setLowerBound(0);
	m_eReference_EAttribute_containment->setUpperBound(1);
	m_eReference_EAttribute_containment->setTransient(false);
	m_eReference_EAttribute_containment->setVolatile(false);
	m_eReference_EAttribute_containment->setChangeable(true);
	m_eReference_EAttribute_containment->setUnsettable(false);
	m_eReference_EAttribute_containment->setUnique(true);
	m_eReference_EAttribute_containment->setDerived(false);
	m_eReference_EAttribute_containment->setOrdered(true);
	m_eReference_EAttribute_containment->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eReference_EAttribute_containment->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eReference_EAttribute_resolveProxies = getEReference_EAttribute_resolveProxies();
	m_eReference_EAttribute_resolveProxies->setName("resolveProxies");
	m_eReference_EAttribute_resolveProxies->setEType(getEBoolean_EDataType());
	m_eReference_EAttribute_resolveProxies->setLowerBound(0);
	m_eReference_EAttribute_resolveProxies->setUpperBound(1);
	m_eReference_EAttribute_resolveProxies->setTransient(false);
	m_eReference_EAttribute_resolveProxies->setVolatile(false);
	m_eReference_EAttribute_resolveProxies->setChangeable(true);
	m_eReference_EAttribute_resolveProxies->setUnsettable(false);
	m_eReference_EAttribute_resolveProxies->setUnique(true);
	m_eReference_EAttribute_resolveProxies->setDerived(false);
	m_eReference_EAttribute_resolveProxies->setOrdered(true);
	m_eReference_EAttribute_resolveProxies->setID(false);
	{
		std::string defaultValue = "true";
		if (!defaultValue.empty())
		{
		   m_eReference_EAttribute_resolveProxies->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_eReference_EReference_eKeys->setName("eKeys");
	m_eReference_EReference_eKeys->setEType(getEAttribute_EClass());
	m_eReference_EReference_eKeys->setLowerBound(0);
	m_eReference_EReference_eKeys->setUpperBound(-1);
	m_eReference_EReference_eKeys->setTransient(false);
	m_eReference_EReference_eKeys->setVolatile(false);
	m_eReference_EReference_eKeys->setChangeable(true);
	m_eReference_EReference_eKeys->setUnsettable(false);
	m_eReference_EReference_eKeys->setUnique(true);
	m_eReference_EReference_eKeys->setDerived(false);
	m_eReference_EReference_eKeys->setOrdered(true);
	m_eReference_EReference_eKeys->setContainment(false);
	m_eReference_EReference_eKeys->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eReference_EReference_eKeys->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eReference_EReference_eKeys->setEOpposite(otherEnd);
	    }
	}
	m_eReference_EReference_eOpposite->setName("eOpposite");
	m_eReference_EReference_eOpposite->setEType(getEReference_EClass());
	m_eReference_EReference_eOpposite->setLowerBound(0);
	m_eReference_EReference_eOpposite->setUpperBound(1);
	m_eReference_EReference_eOpposite->setTransient(false);
	m_eReference_EReference_eOpposite->setVolatile(false);
	m_eReference_EReference_eOpposite->setChangeable(true);
	m_eReference_EReference_eOpposite->setUnsettable(false);
	m_eReference_EReference_eOpposite->setUnique(true);
	m_eReference_EReference_eOpposite->setDerived(false);
	m_eReference_EReference_eOpposite->setOrdered(true);
	m_eReference_EReference_eOpposite->setContainment(false);
	m_eReference_EReference_eOpposite->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eReference_EReference_eOpposite->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eReference_EReference_eOpposite->setEOpposite(otherEnd);
	    }
	}
	m_eReference_EReference_eReferenceType->setName("eReferenceType");
	m_eReference_EReference_eReferenceType->setEType(getEClass_EClass());
	m_eReference_EReference_eReferenceType->setLowerBound(1);
	m_eReference_EReference_eReferenceType->setUpperBound(1);
	m_eReference_EReference_eReferenceType->setTransient(true);
	m_eReference_EReference_eReferenceType->setVolatile(true);
	m_eReference_EReference_eReferenceType->setChangeable(false);
	m_eReference_EReference_eReferenceType->setUnsettable(false);
	m_eReference_EReference_eReferenceType->setUnique(true);
	m_eReference_EReference_eReferenceType->setDerived(true);
	m_eReference_EReference_eReferenceType->setOrdered(true);
	m_eReference_EReference_eReferenceType->setContainment(false);
	m_eReference_EReference_eReferenceType->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eReference_EReference_eReferenceType->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eReference_EReference_eReferenceType->setEOpposite(otherEnd);
	    }
	}
	
	
}

void EcorePackageImpl::initializeEStringToStringMapEntryContent()
{
	m_eStringToStringMapEntry_EClass->setInstanceClass(nullptr);
	m_eStringToStringMapEntry_EClass->setName("EStringToStringMapEntry");
	m_eStringToStringMapEntry_EClass->setAbstract(false);
	m_eStringToStringMapEntry_EClass->setInterface(false);
	
	m_eStringToStringMapEntry_EAttribute_key = getEStringToStringMapEntry_EAttribute_key();
	m_eStringToStringMapEntry_EAttribute_key->setName("key");
	m_eStringToStringMapEntry_EAttribute_key->setEType(getEString_EDataType());
	m_eStringToStringMapEntry_EAttribute_key->setLowerBound(0);
	m_eStringToStringMapEntry_EAttribute_key->setUpperBound(1);
	m_eStringToStringMapEntry_EAttribute_key->setTransient(false);
	m_eStringToStringMapEntry_EAttribute_key->setVolatile(false);
	m_eStringToStringMapEntry_EAttribute_key->setChangeable(true);
	m_eStringToStringMapEntry_EAttribute_key->setUnsettable(false);
	m_eStringToStringMapEntry_EAttribute_key->setUnique(true);
	m_eStringToStringMapEntry_EAttribute_key->setDerived(false);
	m_eStringToStringMapEntry_EAttribute_key->setOrdered(true);
	m_eStringToStringMapEntry_EAttribute_key->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eStringToStringMapEntry_EAttribute_key->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eStringToStringMapEntry_EAttribute_value = getEStringToStringMapEntry_EAttribute_value();
	m_eStringToStringMapEntry_EAttribute_value->setName("value");
	m_eStringToStringMapEntry_EAttribute_value->setEType(getEString_EDataType());
	m_eStringToStringMapEntry_EAttribute_value->setLowerBound(0);
	m_eStringToStringMapEntry_EAttribute_value->setUpperBound(1);
	m_eStringToStringMapEntry_EAttribute_value->setTransient(false);
	m_eStringToStringMapEntry_EAttribute_value->setVolatile(false);
	m_eStringToStringMapEntry_EAttribute_value->setChangeable(true);
	m_eStringToStringMapEntry_EAttribute_value->setUnsettable(false);
	m_eStringToStringMapEntry_EAttribute_value->setUnique(true);
	m_eStringToStringMapEntry_EAttribute_value->setDerived(false);
	m_eStringToStringMapEntry_EAttribute_value->setOrdered(true);
	m_eStringToStringMapEntry_EAttribute_value->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eStringToStringMapEntry_EAttribute_value->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	
}

void EcorePackageImpl::initializeEStructuralFeatureContent()
{
	m_eStructuralFeature_EClass->setInstanceClass(nullptr);
	m_eStructuralFeature_EClass->setName("EStructuralFeature");
	m_eStructuralFeature_EClass->setAbstract(true);
	m_eStructuralFeature_EClass->setInterface(false);
	
	m_eStructuralFeature_EAttribute_changeable = getEStructuralFeature_EAttribute_changeable();
	m_eStructuralFeature_EAttribute_changeable->setName("changeable");
	m_eStructuralFeature_EAttribute_changeable->setEType(getEBoolean_EDataType());
	m_eStructuralFeature_EAttribute_changeable->setLowerBound(0);
	m_eStructuralFeature_EAttribute_changeable->setUpperBound(1);
	m_eStructuralFeature_EAttribute_changeable->setTransient(false);
	m_eStructuralFeature_EAttribute_changeable->setVolatile(false);
	m_eStructuralFeature_EAttribute_changeable->setChangeable(true);
	m_eStructuralFeature_EAttribute_changeable->setUnsettable(false);
	m_eStructuralFeature_EAttribute_changeable->setUnique(true);
	m_eStructuralFeature_EAttribute_changeable->setDerived(false);
	m_eStructuralFeature_EAttribute_changeable->setOrdered(true);
	m_eStructuralFeature_EAttribute_changeable->setID(false);
	{
		std::string defaultValue = "true";
		if (!defaultValue.empty())
		{
		   m_eStructuralFeature_EAttribute_changeable->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eStructuralFeature_EAttribute_containerClass = getEStructuralFeature_EAttribute_containerClass();
	m_eStructuralFeature_EAttribute_containerClass->setName("containerClass");
	m_eStructuralFeature_EAttribute_containerClass->setEType(getEJavaClass_EDataType());
	m_eStructuralFeature_EAttribute_containerClass->setLowerBound(0);
	m_eStructuralFeature_EAttribute_containerClass->setUpperBound(1);
	m_eStructuralFeature_EAttribute_containerClass->setTransient(false);
	m_eStructuralFeature_EAttribute_containerClass->setVolatile(false);
	m_eStructuralFeature_EAttribute_containerClass->setChangeable(false);
	m_eStructuralFeature_EAttribute_containerClass->setUnsettable(false);
	m_eStructuralFeature_EAttribute_containerClass->setUnique(true);
	m_eStructuralFeature_EAttribute_containerClass->setDerived(false);
	m_eStructuralFeature_EAttribute_containerClass->setOrdered(true);
	m_eStructuralFeature_EAttribute_containerClass->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eStructuralFeature_EAttribute_containerClass->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eStructuralFeature_EAttribute_defaultValue = getEStructuralFeature_EAttribute_defaultValue();
	m_eStructuralFeature_EAttribute_defaultValue->setName("defaultValue");
	m_eStructuralFeature_EAttribute_defaultValue->setEType(getEJavaObject_EDataType());
	m_eStructuralFeature_EAttribute_defaultValue->setLowerBound(0);
	m_eStructuralFeature_EAttribute_defaultValue->setUpperBound(1);
	m_eStructuralFeature_EAttribute_defaultValue->setTransient(true);
	m_eStructuralFeature_EAttribute_defaultValue->setVolatile(true);
	m_eStructuralFeature_EAttribute_defaultValue->setChangeable(false);
	m_eStructuralFeature_EAttribute_defaultValue->setUnsettable(false);
	m_eStructuralFeature_EAttribute_defaultValue->setUnique(true);
	m_eStructuralFeature_EAttribute_defaultValue->setDerived(true);
	m_eStructuralFeature_EAttribute_defaultValue->setOrdered(true);
	m_eStructuralFeature_EAttribute_defaultValue->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eStructuralFeature_EAttribute_defaultValue->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eStructuralFeature_EAttribute_defaultValueLiteral = getEStructuralFeature_EAttribute_defaultValueLiteral();
	m_eStructuralFeature_EAttribute_defaultValueLiteral->setName("defaultValueLiteral");
	m_eStructuralFeature_EAttribute_defaultValueLiteral->setEType(getEString_EDataType());
	m_eStructuralFeature_EAttribute_defaultValueLiteral->setLowerBound(0);
	m_eStructuralFeature_EAttribute_defaultValueLiteral->setUpperBound(1);
	m_eStructuralFeature_EAttribute_defaultValueLiteral->setTransient(false);
	m_eStructuralFeature_EAttribute_defaultValueLiteral->setVolatile(false);
	m_eStructuralFeature_EAttribute_defaultValueLiteral->setChangeable(true);
	m_eStructuralFeature_EAttribute_defaultValueLiteral->setUnsettable(false);
	m_eStructuralFeature_EAttribute_defaultValueLiteral->setUnique(true);
	m_eStructuralFeature_EAttribute_defaultValueLiteral->setDerived(false);
	m_eStructuralFeature_EAttribute_defaultValueLiteral->setOrdered(true);
	m_eStructuralFeature_EAttribute_defaultValueLiteral->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eStructuralFeature_EAttribute_defaultValueLiteral->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eStructuralFeature_EAttribute_derived = getEStructuralFeature_EAttribute_derived();
	m_eStructuralFeature_EAttribute_derived->setName("derived");
	m_eStructuralFeature_EAttribute_derived->setEType(getEBoolean_EDataType());
	m_eStructuralFeature_EAttribute_derived->setLowerBound(0);
	m_eStructuralFeature_EAttribute_derived->setUpperBound(1);
	m_eStructuralFeature_EAttribute_derived->setTransient(false);
	m_eStructuralFeature_EAttribute_derived->setVolatile(false);
	m_eStructuralFeature_EAttribute_derived->setChangeable(true);
	m_eStructuralFeature_EAttribute_derived->setUnsettable(false);
	m_eStructuralFeature_EAttribute_derived->setUnique(true);
	m_eStructuralFeature_EAttribute_derived->setDerived(false);
	m_eStructuralFeature_EAttribute_derived->setOrdered(true);
	m_eStructuralFeature_EAttribute_derived->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eStructuralFeature_EAttribute_derived->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eStructuralFeature_EAttribute_featureID = getEStructuralFeature_EAttribute_featureID();
	m_eStructuralFeature_EAttribute_featureID->setName("featureID");
	m_eStructuralFeature_EAttribute_featureID->setEType(getEInt_EDataType());
	m_eStructuralFeature_EAttribute_featureID->setLowerBound(0);
	m_eStructuralFeature_EAttribute_featureID->setUpperBound(1);
	m_eStructuralFeature_EAttribute_featureID->setTransient(false);
	m_eStructuralFeature_EAttribute_featureID->setVolatile(false);
	m_eStructuralFeature_EAttribute_featureID->setChangeable(false);
	m_eStructuralFeature_EAttribute_featureID->setUnsettable(false);
	m_eStructuralFeature_EAttribute_featureID->setUnique(true);
	m_eStructuralFeature_EAttribute_featureID->setDerived(false);
	m_eStructuralFeature_EAttribute_featureID->setOrdered(true);
	m_eStructuralFeature_EAttribute_featureID->setID(false);
	{
		std::string defaultValue = "-1";
		if (!defaultValue.empty())
		{
		   m_eStructuralFeature_EAttribute_featureID->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eStructuralFeature_EAttribute_transient = getEStructuralFeature_EAttribute_transient();
	m_eStructuralFeature_EAttribute_transient->setName("transient");
	m_eStructuralFeature_EAttribute_transient->setEType(getEBoolean_EDataType());
	m_eStructuralFeature_EAttribute_transient->setLowerBound(0);
	m_eStructuralFeature_EAttribute_transient->setUpperBound(1);
	m_eStructuralFeature_EAttribute_transient->setTransient(false);
	m_eStructuralFeature_EAttribute_transient->setVolatile(false);
	m_eStructuralFeature_EAttribute_transient->setChangeable(true);
	m_eStructuralFeature_EAttribute_transient->setUnsettable(false);
	m_eStructuralFeature_EAttribute_transient->setUnique(true);
	m_eStructuralFeature_EAttribute_transient->setDerived(false);
	m_eStructuralFeature_EAttribute_transient->setOrdered(true);
	m_eStructuralFeature_EAttribute_transient->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eStructuralFeature_EAttribute_transient->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eStructuralFeature_EAttribute_unsettable = getEStructuralFeature_EAttribute_unsettable();
	m_eStructuralFeature_EAttribute_unsettable->setName("unsettable");
	m_eStructuralFeature_EAttribute_unsettable->setEType(getEBoolean_EDataType());
	m_eStructuralFeature_EAttribute_unsettable->setLowerBound(0);
	m_eStructuralFeature_EAttribute_unsettable->setUpperBound(1);
	m_eStructuralFeature_EAttribute_unsettable->setTransient(false);
	m_eStructuralFeature_EAttribute_unsettable->setVolatile(false);
	m_eStructuralFeature_EAttribute_unsettable->setChangeable(true);
	m_eStructuralFeature_EAttribute_unsettable->setUnsettable(false);
	m_eStructuralFeature_EAttribute_unsettable->setUnique(true);
	m_eStructuralFeature_EAttribute_unsettable->setDerived(false);
	m_eStructuralFeature_EAttribute_unsettable->setOrdered(true);
	m_eStructuralFeature_EAttribute_unsettable->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eStructuralFeature_EAttribute_unsettable->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eStructuralFeature_EAttribute_volatile = getEStructuralFeature_EAttribute_volatile();
	m_eStructuralFeature_EAttribute_volatile->setName("volatile");
	m_eStructuralFeature_EAttribute_volatile->setEType(getEBoolean_EDataType());
	m_eStructuralFeature_EAttribute_volatile->setLowerBound(0);
	m_eStructuralFeature_EAttribute_volatile->setUpperBound(1);
	m_eStructuralFeature_EAttribute_volatile->setTransient(false);
	m_eStructuralFeature_EAttribute_volatile->setVolatile(false);
	m_eStructuralFeature_EAttribute_volatile->setChangeable(true);
	m_eStructuralFeature_EAttribute_volatile->setUnsettable(false);
	m_eStructuralFeature_EAttribute_volatile->setUnique(true);
	m_eStructuralFeature_EAttribute_volatile->setDerived(false);
	m_eStructuralFeature_EAttribute_volatile->setOrdered(true);
	m_eStructuralFeature_EAttribute_volatile->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eStructuralFeature_EAttribute_volatile->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_eStructuralFeature_EReference_eContainingClass->setName("eContainingClass");
	m_eStructuralFeature_EReference_eContainingClass->setEType(getEClass_EClass());
	m_eStructuralFeature_EReference_eContainingClass->setLowerBound(0);
	m_eStructuralFeature_EReference_eContainingClass->setUpperBound(1);
	m_eStructuralFeature_EReference_eContainingClass->setTransient(true);
	m_eStructuralFeature_EReference_eContainingClass->setVolatile(false);
	m_eStructuralFeature_EReference_eContainingClass->setChangeable(false);
	m_eStructuralFeature_EReference_eContainingClass->setUnsettable(false);
	m_eStructuralFeature_EReference_eContainingClass->setUnique(true);
	m_eStructuralFeature_EReference_eContainingClass->setDerived(false);
	m_eStructuralFeature_EReference_eContainingClass->setOrdered(true);
	m_eStructuralFeature_EReference_eContainingClass->setContainment(false);
	m_eStructuralFeature_EReference_eContainingClass->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eStructuralFeature_EReference_eContainingClass->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEClass_EReference_eStructuralFeatures();
		if (otherEnd != nullptr)
	    {
	   		m_eStructuralFeature_EReference_eContainingClass->setEOpposite(otherEnd);
	    }
	}
	
	
}

void EcorePackageImpl::initializeETypeParameterContent()
{
	m_eTypeParameter_EClass->setInstanceClass(nullptr);
	m_eTypeParameter_EClass->setName("ETypeParameter");
	m_eTypeParameter_EClass->setAbstract(false);
	m_eTypeParameter_EClass->setInterface(false);
	
	
	m_eTypeParameter_EReference_eBounds->setName("eBounds");
	m_eTypeParameter_EReference_eBounds->setEType(getEGenericType_EClass());
	m_eTypeParameter_EReference_eBounds->setLowerBound(0);
	m_eTypeParameter_EReference_eBounds->setUpperBound(-1);
	m_eTypeParameter_EReference_eBounds->setTransient(false);
	m_eTypeParameter_EReference_eBounds->setVolatile(false);
	m_eTypeParameter_EReference_eBounds->setChangeable(true);
	m_eTypeParameter_EReference_eBounds->setUnsettable(false);
	m_eTypeParameter_EReference_eBounds->setUnique(true);
	m_eTypeParameter_EReference_eBounds->setDerived(false);
	m_eTypeParameter_EReference_eBounds->setOrdered(true);
	m_eTypeParameter_EReference_eBounds->setContainment(true);
	m_eTypeParameter_EReference_eBounds->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eTypeParameter_EReference_eBounds->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eTypeParameter_EReference_eBounds->setEOpposite(otherEnd);
	    }
	}
	
	
}

void EcorePackageImpl::initializeETypedElementContent()
{
	m_eTypedElement_EClass->setInstanceClass(nullptr);
	m_eTypedElement_EClass->setName("ETypedElement");
	m_eTypedElement_EClass->setAbstract(true);
	m_eTypedElement_EClass->setInterface(false);
	
	m_eTypedElement_EAttribute_lowerBound = getETypedElement_EAttribute_lowerBound();
	m_eTypedElement_EAttribute_lowerBound->setName("lowerBound");
	m_eTypedElement_EAttribute_lowerBound->setEType(getEInt_EDataType());
	m_eTypedElement_EAttribute_lowerBound->setLowerBound(0);
	m_eTypedElement_EAttribute_lowerBound->setUpperBound(1);
	m_eTypedElement_EAttribute_lowerBound->setTransient(false);
	m_eTypedElement_EAttribute_lowerBound->setVolatile(false);
	m_eTypedElement_EAttribute_lowerBound->setChangeable(true);
	m_eTypedElement_EAttribute_lowerBound->setUnsettable(false);
	m_eTypedElement_EAttribute_lowerBound->setUnique(true);
	m_eTypedElement_EAttribute_lowerBound->setDerived(false);
	m_eTypedElement_EAttribute_lowerBound->setOrdered(true);
	m_eTypedElement_EAttribute_lowerBound->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eTypedElement_EAttribute_lowerBound->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eTypedElement_EAttribute_many = getETypedElement_EAttribute_many();
	m_eTypedElement_EAttribute_many->setName("many");
	m_eTypedElement_EAttribute_many->setEType(getEBoolean_EDataType());
	m_eTypedElement_EAttribute_many->setLowerBound(0);
	m_eTypedElement_EAttribute_many->setUpperBound(1);
	m_eTypedElement_EAttribute_many->setTransient(true);
	m_eTypedElement_EAttribute_many->setVolatile(true);
	m_eTypedElement_EAttribute_many->setChangeable(false);
	m_eTypedElement_EAttribute_many->setUnsettable(false);
	m_eTypedElement_EAttribute_many->setUnique(true);
	m_eTypedElement_EAttribute_many->setDerived(true);
	m_eTypedElement_EAttribute_many->setOrdered(true);
	m_eTypedElement_EAttribute_many->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eTypedElement_EAttribute_many->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eTypedElement_EAttribute_ordered = getETypedElement_EAttribute_ordered();
	m_eTypedElement_EAttribute_ordered->setName("ordered");
	m_eTypedElement_EAttribute_ordered->setEType(getEBoolean_EDataType());
	m_eTypedElement_EAttribute_ordered->setLowerBound(0);
	m_eTypedElement_EAttribute_ordered->setUpperBound(1);
	m_eTypedElement_EAttribute_ordered->setTransient(false);
	m_eTypedElement_EAttribute_ordered->setVolatile(false);
	m_eTypedElement_EAttribute_ordered->setChangeable(true);
	m_eTypedElement_EAttribute_ordered->setUnsettable(false);
	m_eTypedElement_EAttribute_ordered->setUnique(true);
	m_eTypedElement_EAttribute_ordered->setDerived(false);
	m_eTypedElement_EAttribute_ordered->setOrdered(true);
	m_eTypedElement_EAttribute_ordered->setID(false);
	{
		std::string defaultValue = "true";
		if (!defaultValue.empty())
		{
		   m_eTypedElement_EAttribute_ordered->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eTypedElement_EAttribute_required = getETypedElement_EAttribute_required();
	m_eTypedElement_EAttribute_required->setName("required");
	m_eTypedElement_EAttribute_required->setEType(getEBoolean_EDataType());
	m_eTypedElement_EAttribute_required->setLowerBound(0);
	m_eTypedElement_EAttribute_required->setUpperBound(1);
	m_eTypedElement_EAttribute_required->setTransient(true);
	m_eTypedElement_EAttribute_required->setVolatile(true);
	m_eTypedElement_EAttribute_required->setChangeable(false);
	m_eTypedElement_EAttribute_required->setUnsettable(false);
	m_eTypedElement_EAttribute_required->setUnique(true);
	m_eTypedElement_EAttribute_required->setDerived(true);
	m_eTypedElement_EAttribute_required->setOrdered(true);
	m_eTypedElement_EAttribute_required->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_eTypedElement_EAttribute_required->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eTypedElement_EAttribute_unique = getETypedElement_EAttribute_unique();
	m_eTypedElement_EAttribute_unique->setName("unique");
	m_eTypedElement_EAttribute_unique->setEType(getEBoolean_EDataType());
	m_eTypedElement_EAttribute_unique->setLowerBound(0);
	m_eTypedElement_EAttribute_unique->setUpperBound(1);
	m_eTypedElement_EAttribute_unique->setTransient(false);
	m_eTypedElement_EAttribute_unique->setVolatile(false);
	m_eTypedElement_EAttribute_unique->setChangeable(true);
	m_eTypedElement_EAttribute_unique->setUnsettable(false);
	m_eTypedElement_EAttribute_unique->setUnique(true);
	m_eTypedElement_EAttribute_unique->setDerived(false);
	m_eTypedElement_EAttribute_unique->setOrdered(true);
	m_eTypedElement_EAttribute_unique->setID(false);
	{
		std::string defaultValue = "true";
		if (!defaultValue.empty())
		{
		   m_eTypedElement_EAttribute_unique->setDefaultValueLiteral(defaultValue);
		}
	}
	m_eTypedElement_EAttribute_upperBound = getETypedElement_EAttribute_upperBound();
	m_eTypedElement_EAttribute_upperBound->setName("upperBound");
	m_eTypedElement_EAttribute_upperBound->setEType(getEInt_EDataType());
	m_eTypedElement_EAttribute_upperBound->setLowerBound(0);
	m_eTypedElement_EAttribute_upperBound->setUpperBound(1);
	m_eTypedElement_EAttribute_upperBound->setTransient(false);
	m_eTypedElement_EAttribute_upperBound->setVolatile(false);
	m_eTypedElement_EAttribute_upperBound->setChangeable(true);
	m_eTypedElement_EAttribute_upperBound->setUnsettable(false);
	m_eTypedElement_EAttribute_upperBound->setUnique(true);
	m_eTypedElement_EAttribute_upperBound->setDerived(false);
	m_eTypedElement_EAttribute_upperBound->setOrdered(true);
	m_eTypedElement_EAttribute_upperBound->setID(false);
	{
		std::string defaultValue = "1";
		if (!defaultValue.empty())
		{
		   m_eTypedElement_EAttribute_upperBound->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_eTypedElement_EReference_eGenericType->setName("eGenericType");
	m_eTypedElement_EReference_eGenericType->setEType(getEGenericType_EClass());
	m_eTypedElement_EReference_eGenericType->setLowerBound(0);
	m_eTypedElement_EReference_eGenericType->setUpperBound(1);
	m_eTypedElement_EReference_eGenericType->setTransient(false);
	m_eTypedElement_EReference_eGenericType->setVolatile(true);
	m_eTypedElement_EReference_eGenericType->setChangeable(true);
	m_eTypedElement_EReference_eGenericType->setUnsettable(true);
	m_eTypedElement_EReference_eGenericType->setUnique(true);
	m_eTypedElement_EReference_eGenericType->setDerived(false);
	m_eTypedElement_EReference_eGenericType->setOrdered(true);
	m_eTypedElement_EReference_eGenericType->setContainment(true);
	m_eTypedElement_EReference_eGenericType->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eTypedElement_EReference_eGenericType->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eTypedElement_EReference_eGenericType->setEOpposite(otherEnd);
	    }
	}
	m_eTypedElement_EReference_eType->setName("eType");
	m_eTypedElement_EReference_eType->setEType(getEClassifier_EClass());
	m_eTypedElement_EReference_eType->setLowerBound(0);
	m_eTypedElement_EReference_eType->setUpperBound(1);
	m_eTypedElement_EReference_eType->setTransient(false);
	m_eTypedElement_EReference_eType->setVolatile(true);
	m_eTypedElement_EReference_eType->setChangeable(true);
	m_eTypedElement_EReference_eType->setUnsettable(true);
	m_eTypedElement_EReference_eType->setUnique(true);
	m_eTypedElement_EReference_eType->setDerived(false);
	m_eTypedElement_EReference_eType->setOrdered(true);
	m_eTypedElement_EReference_eType->setContainment(false);
	m_eTypedElement_EReference_eType->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eTypedElement_EReference_eType->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_eTypedElement_EReference_eType->setEOpposite(otherEnd);
	    }
	}
	
	
}

void EcorePackageImpl::initializePackageEDataTypes()
{
	m_eBigDecimal_EDataType->setInstanceClass(nullptr);
	m_eBigDecimal_EDataType->setName("EBigDecimal");
	m_eBigDecimal_EDataType->setSerializable(true);
	m_eBigInteger_EDataType->setInstanceClass(nullptr);
	m_eBigInteger_EDataType->setName("EBigInteger");
	m_eBigInteger_EDataType->setSerializable(true);
	m_eBoolean_EDataType->setInstanceClass(nullptr);
	m_eBoolean_EDataType->setName("EBoolean");
	m_eBoolean_EDataType->setSerializable(true);
	m_eBooleanObject_EDataType->setInstanceClass(nullptr);
	m_eBooleanObject_EDataType->setName("EBooleanObject");
	m_eBooleanObject_EDataType->setSerializable(true);
	m_eByte_EDataType->setInstanceClass(nullptr);
	m_eByte_EDataType->setName("EByte");
	m_eByte_EDataType->setSerializable(true);
	m_eByteArray_EDataType->setInstanceClass(nullptr);
	m_eByteArray_EDataType->setName("EByteArray");
	m_eByteArray_EDataType->setSerializable(true);
	m_eByteObject_EDataType->setInstanceClass(nullptr);
	m_eByteObject_EDataType->setName("EByteObject");
	m_eByteObject_EDataType->setSerializable(true);
	m_eChar_EDataType->setInstanceClass(nullptr);
	m_eChar_EDataType->setName("EChar");
	m_eChar_EDataType->setSerializable(true);
	m_eCharacterObject_EDataType->setInstanceClass(nullptr);
	m_eCharacterObject_EDataType->setName("ECharacterObject");
	m_eCharacterObject_EDataType->setSerializable(true);
	m_eDate_EDataType->setInstanceClass(nullptr);
	m_eDate_EDataType->setName("EDate");
	m_eDate_EDataType->setSerializable(true);
	m_eDiagnosticChain_EDataType->setInstanceClass(nullptr);
	m_eDiagnosticChain_EDataType->setName("EDiagnosticChain");
	m_eDiagnosticChain_EDataType->setSerializable(false);
	m_eDouble_EDataType->setInstanceClass(nullptr);
	m_eDouble_EDataType->setName("EDouble");
	m_eDouble_EDataType->setSerializable(true);
	m_eDoubleObject_EDataType->setInstanceClass(nullptr);
	m_eDoubleObject_EDataType->setName("EDoubleObject");
	m_eDoubleObject_EDataType->setSerializable(true);
	m_eEList_EDataType->setInstanceClass(nullptr);
	m_eEList_EDataType->setName("EEList");
	m_eEList_EDataType->setSerializable(false);
	m_eEnumerator_EDataType->setInstanceClass(nullptr);
	m_eEnumerator_EDataType->setName("EEnumerator");
	m_eEnumerator_EDataType->setSerializable(false);
	m_eFeatureMap_EDataType->setInstanceClass(nullptr);
	m_eFeatureMap_EDataType->setName("EFeatureMap");
	m_eFeatureMap_EDataType->setSerializable(false);
	m_eFeatureMapEntry_EDataType->setInstanceClass(nullptr);
	m_eFeatureMapEntry_EDataType->setName("EFeatureMapEntry");
	m_eFeatureMapEntry_EDataType->setSerializable(false);
	m_eFloat_EDataType->setInstanceClass(nullptr);
	m_eFloat_EDataType->setName("EFloat");
	m_eFloat_EDataType->setSerializable(true);
	m_eFloatObject_EDataType->setInstanceClass(nullptr);
	m_eFloatObject_EDataType->setName("EFloatObject");
	m_eFloatObject_EDataType->setSerializable(true);
	m_eInt_EDataType->setInstanceClass(nullptr);
	m_eInt_EDataType->setName("EInt");
	m_eInt_EDataType->setSerializable(true);
	m_eIntegerObject_EDataType->setInstanceClass(nullptr);
	m_eIntegerObject_EDataType->setName("EIntegerObject");
	m_eIntegerObject_EDataType->setSerializable(true);
	m_eInvocationTargetException_EDataType->setInstanceClass(nullptr);
	m_eInvocationTargetException_EDataType->setName("EInvocationTargetException");
	m_eInvocationTargetException_EDataType->setSerializable(false);
	m_eJavaClass_EDataType->setInstanceClass(nullptr);
	m_eJavaClass_EDataType->setName("EJavaClass");
	m_eJavaClass_EDataType->setSerializable(true);
	m_eJavaObject_EDataType->setInstanceClass(nullptr);
	m_eJavaObject_EDataType->setName("EJavaObject");
	m_eJavaObject_EDataType->setSerializable(true);
	m_eLong_EDataType->setInstanceClass(nullptr);
	m_eLong_EDataType->setName("ELong");
	m_eLong_EDataType->setSerializable(true);
	m_eLongObject_EDataType->setInstanceClass(nullptr);
	m_eLongObject_EDataType->setName("ELongObject");
	m_eLongObject_EDataType->setSerializable(true);
	m_eMap_EDataType->setInstanceClass(nullptr);
	m_eMap_EDataType->setName("EMap");
	m_eMap_EDataType->setSerializable(false);
	m_eResource_EDataType->setInstanceClass(nullptr);
	m_eResource_EDataType->setName("EResource");
	m_eResource_EDataType->setSerializable(false);
	m_eResourceSet_EDataType->setInstanceClass(nullptr);
	m_eResourceSet_EDataType->setName("EResourceSet");
	m_eResourceSet_EDataType->setSerializable(false);
	m_eShort_EDataType->setInstanceClass(nullptr);
	m_eShort_EDataType->setName("EShort");
	m_eShort_EDataType->setSerializable(true);
	m_eShortObject_EDataType->setInstanceClass(nullptr);
	m_eShortObject_EDataType->setName("EShortObject");
	m_eShortObject_EDataType->setSerializable(true);
	m_eString_EDataType->setInstanceClass(nullptr);
	m_eString_EDataType->setName("EString");
	m_eString_EDataType->setSerializable(true);
	m_eTreeIterator_EDataType->setInstanceClass(nullptr);
	m_eTreeIterator_EDataType->setName("ETreeIterator");
	m_eTreeIterator_EDataType->setSerializable(false);
	
}

// Begin Class EAnnotation
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEAnnotation_EClass() const
{
	return m_eAnnotation_EClass;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEAnnotation_EAttribute_source() const
{
	return m_eAnnotation_EAttribute_source;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEAnnotation_EReference_contents() const
{
	return m_eAnnotation_EReference_contents;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEAnnotation_EReference_details() const
{
	return m_eAnnotation_EReference_details;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEAnnotation_EReference_eModelElement() const
{
	return m_eAnnotation_EReference_eModelElement;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEAnnotation_EReference_references() const
{
	return m_eAnnotation_EReference_references;
}


// End Class EAnnotation

// Begin Class EAttribute
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEAttribute_EClass() const
{
	return m_eAttribute_EClass;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEAttribute_EAttribute_iD() const
{
	return m_eAttribute_EAttribute_iD;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEAttribute_EReference_eAttributeType() const
{
	return m_eAttribute_EReference_eAttributeType;
}


// End Class EAttribute

// Begin Class EClass
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEClass_EClass() const
{
	return m_eClass_EClass;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEClass_EAttribute_abstract() const
{
	return m_eClass_EAttribute_abstract;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEClass_EAttribute_interface() const
{
	return m_eClass_EAttribute_interface;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EReference_eAllAttributes() const
{
	return m_eClass_EReference_eAllAttributes;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EReference_eAllContainments() const
{
	return m_eClass_EReference_eAllContainments;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EReference_eAllGenericSuperTypes() const
{
	return m_eClass_EReference_eAllGenericSuperTypes;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EReference_eAllOperations() const
{
	return m_eClass_EReference_eAllOperations;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EReference_eAllReferences() const
{
	return m_eClass_EReference_eAllReferences;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EReference_eAllStructuralFeatures() const
{
	return m_eClass_EReference_eAllStructuralFeatures;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EReference_eAllSuperTypes() const
{
	return m_eClass_EReference_eAllSuperTypes;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EReference_eAttributes() const
{
	return m_eClass_EReference_eAttributes;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EReference_eGenericSuperTypes() const
{
	return m_eClass_EReference_eGenericSuperTypes;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EReference_eIDAttribute() const
{
	return m_eClass_EReference_eIDAttribute;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EReference_eOperations() const
{
	return m_eClass_EReference_eOperations;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EReference_eReferences() const
{
	return m_eClass_EReference_eReferences;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EReference_eStructuralFeatures() const
{
	return m_eClass_EReference_eStructuralFeatures;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EReference_eSuperTypes() const
{
	return m_eClass_EReference_eSuperTypes;
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass_EOperation_getEOperation_EInt() const
{
	return m_eClass_EOperation_getEOperation_EInt;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass_EOperation_getEStructuralFeature_EInt() const
{
	return m_eClass_EOperation_getEStructuralFeature_EInt;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass_EOperation_getEStructuralFeature_EString() const
{
	return m_eClass_EOperation_getEStructuralFeature_EString;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass_EOperation_getFeatureCount() const
{
	return m_eClass_EOperation_getFeatureCount;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass_EOperation_getFeatureID_EStructuralFeature() const
{
	return m_eClass_EOperation_getFeatureID_EStructuralFeature;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass_EOperation_getFeatureType_EStructuralFeature() const
{
	return m_eClass_EOperation_getFeatureType_EStructuralFeature;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass_EOperation_getOperationCount() const
{
	return m_eClass_EOperation_getOperationCount;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass_EOperation_getOperationID_EOperation() const
{
	return m_eClass_EOperation_getOperationID_EOperation;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass_EOperation_getOverride_EOperation() const
{
	return m_eClass_EOperation_getOverride_EOperation;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass_EOperation_isSuperTypeOf_EClass() const
{
	return m_eClass_EOperation_isSuperTypeOf_EClass;
}

// End Class EClass

// Begin Class EClassifier
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEClassifier_EClass() const
{
	return m_eClassifier_EClass;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEClassifier_EAttribute_classifierID() const
{
	return m_eClassifier_EAttribute_classifierID;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEClassifier_EAttribute_defaultValue() const
{
	return m_eClassifier_EAttribute_defaultValue;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEClassifier_EAttribute_instanceClass() const
{
	return m_eClassifier_EAttribute_instanceClass;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEClassifier_EAttribute_instanceClassName() const
{
	return m_eClassifier_EAttribute_instanceClassName;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEClassifier_EAttribute_instanceTypeName() const
{
	return m_eClassifier_EAttribute_instanceTypeName;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClassifier_EReference_ePackage() const
{
	return m_eClassifier_EReference_ePackage;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClassifier_EReference_eTypeParameters() const
{
	return m_eClassifier_EReference_eTypeParameters;
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClassifier_EOperation_isInstance_EJavaObject() const
{
	return m_eClassifier_EOperation_isInstance_EJavaObject;
}

// End Class EClassifier

// Begin Class EDataType
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEDataType_EClass() const
{
	return m_eDataType_EClass;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEDataType_EAttribute_serializable() const
{
	return m_eDataType_EAttribute_serializable;
}



// End Class EDataType

// Begin Class EEnum
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEEnum_EClass() const
{
	return m_eEnum_EClass;
}


std::shared_ptr<ecore::EReference> EcorePackageImpl::getEEnum_EReference_eLiterals() const
{
	return m_eEnum_EReference_eLiterals;
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEEnum_EOperation_getEEnumLiteral_EString() const
{
	return m_eEnum_EOperation_getEEnumLiteral_EString;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEEnum_EOperation_getEEnumLiteral_EInt() const
{
	return m_eEnum_EOperation_getEEnumLiteral_EInt;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEEnum_EOperation_getEEnumLiteralByLiteral_EString() const
{
	return m_eEnum_EOperation_getEEnumLiteralByLiteral_EString;
}

// End Class EEnum

// Begin Class EEnumLiteral
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEEnumLiteral_EClass() const
{
	return m_eEnumLiteral_EClass;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEEnumLiteral_EAttribute_instance() const
{
	return m_eEnumLiteral_EAttribute_instance;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEEnumLiteral_EAttribute_literal() const
{
	return m_eEnumLiteral_EAttribute_literal;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEEnumLiteral_EAttribute_value() const
{
	return m_eEnumLiteral_EAttribute_value;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEEnumLiteral_EReference_eEnum() const
{
	return m_eEnumLiteral_EReference_eEnum;
}


// End Class EEnumLiteral

// Begin Class EFactory
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEFactory_EClass() const
{
	return m_eFactory_EClass;
}


std::shared_ptr<ecore::EReference> EcorePackageImpl::getEFactory_EReference_ePackage() const
{
	return m_eFactory_EReference_ePackage;
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEFactory_EOperation_convertToString_EDataType_EJavaObject() const
{
	return m_eFactory_EOperation_convertToString_EDataType_EJavaObject;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEFactory_EOperation_create_EClass_EObject() const
{
	return m_eFactory_EOperation_create_EClass_EObject;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEFactory_EOperation_createFromString_EDataType_EString() const
{
	return m_eFactory_EOperation_createFromString_EDataType_EString;
}

// End Class EFactory

// Begin Class EGenericType
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEGenericType_EClass() const
{
	return m_eGenericType_EClass;
}


std::shared_ptr<ecore::EReference> EcorePackageImpl::getEGenericType_EReference_eClassifier() const
{
	return m_eGenericType_EReference_eClassifier;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEGenericType_EReference_eLowerBound() const
{
	return m_eGenericType_EReference_eLowerBound;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEGenericType_EReference_eRawType() const
{
	return m_eGenericType_EReference_eRawType;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEGenericType_EReference_eTypeArguments() const
{
	return m_eGenericType_EReference_eTypeArguments;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEGenericType_EReference_eTypeParameter() const
{
	return m_eGenericType_EReference_eTypeParameter;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEGenericType_EReference_eUpperBound() const
{
	return m_eGenericType_EReference_eUpperBound;
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEGenericType_EOperation_isInstance_EJavaObject() const
{
	return m_eGenericType_EOperation_isInstance_EJavaObject;
}

// End Class EGenericType

// Begin Class EModelElement
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEModelElement_EClass() const
{
	return m_eModelElement_EClass;
}


std::shared_ptr<ecore::EReference> EcorePackageImpl::getEModelElement_EReference_eAnnotations() const
{
	return m_eModelElement_EReference_eAnnotations;
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEModelElement_EOperation_getEAnnotation_EString() const
{
	return m_eModelElement_EOperation_getEAnnotation_EString;
}

// End Class EModelElement

// Begin Class ENamedElement
std::shared_ptr<ecore::EClass> EcorePackageImpl::getENamedElement_EClass() const
{
	return m_eNamedElement_EClass;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getENamedElement_EAttribute_name() const
{
	return m_eNamedElement_EAttribute_name;
}



// End Class ENamedElement

// Begin Class EObject
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEObject_EClass() const
{
	return m_eObject_EClass;
}


std::shared_ptr<ecore::EReference> EcorePackageImpl::getEObject_EReference_eContainer() const
{
	return m_eObject_EReference_eContainer;
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_EOperation_eAllContents() const
{
	return m_eObject_EOperation_eAllContents;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_EOperation_eClass() const
{
	return m_eObject_EOperation_eClass;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_EOperation_eContainingFeature() const
{
	return m_eObject_EOperation_eContainingFeature;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_EOperation_eContainmentFeature() const
{
	return m_eObject_EOperation_eContainmentFeature;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_EOperation_eContents() const
{
	return m_eObject_EOperation_eContents;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_EOperation_eCrossReferences() const
{
	return m_eObject_EOperation_eCrossReferences;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_EOperation_eGet_EStructuralFeature() const
{
	return m_eObject_EOperation_eGet_EStructuralFeature;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_EOperation_eGet_EStructuralFeature_EBoolean() const
{
	return m_eObject_EOperation_eGet_EStructuralFeature_EBoolean;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_EOperation_eInvoke_EOperation_EEList() const
{
	return m_eObject_EOperation_eInvoke_EOperation_EEList;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_EOperation_eIsProxy() const
{
	return m_eObject_EOperation_eIsProxy;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_EOperation_eIsSet_EStructuralFeature() const
{
	return m_eObject_EOperation_eIsSet_EStructuralFeature;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_EOperation_eResource() const
{
	return m_eObject_EOperation_eResource;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_EOperation_eSet_EStructuralFeature_EJavaObject() const
{
	return m_eObject_EOperation_eSet_EStructuralFeature_EJavaObject;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_EOperation_eUnset_EStructuralFeature() const
{
	return m_eObject_EOperation_eUnset_EStructuralFeature;
}

// End Class EObject

// Begin Class EOperation
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEOperation_EClass() const
{
	return m_eOperation_EClass;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEOperation_EAttribute_operationID() const
{
	return m_eOperation_EAttribute_operationID;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEOperation_EReference_eContainingClass() const
{
	return m_eOperation_EReference_eContainingClass;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEOperation_EReference_eExceptions() const
{
	return m_eOperation_EReference_eExceptions;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEOperation_EReference_eGenericExceptions() const
{
	return m_eOperation_EReference_eGenericExceptions;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEOperation_EReference_eParameters() const
{
	return m_eOperation_EReference_eParameters;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEOperation_EReference_eTypeParameters() const
{
	return m_eOperation_EReference_eTypeParameters;
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEOperation_EOperation_isOverrideOf_EOperation() const
{
	return m_eOperation_EOperation_isOverrideOf_EOperation;
}

// End Class EOperation

// Begin Class EPackage
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEPackage_EClass() const
{
	return m_ePackage_EClass;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEPackage_EAttribute_nsPrefix() const
{
	return m_ePackage_EAttribute_nsPrefix;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEPackage_EAttribute_nsURI() const
{
	return m_ePackage_EAttribute_nsURI;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEPackage_EReference_eClassifiers() const
{
	return m_ePackage_EReference_eClassifiers;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEPackage_EReference_eFactoryInstance() const
{
	return m_ePackage_EReference_eFactoryInstance;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEPackage_EReference_eSubpackages() const
{
	return m_ePackage_EReference_eSubpackages;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEPackage_EReference_eSuperPackage() const
{
	return m_ePackage_EReference_eSuperPackage;
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEPackage_EOperation_getEClassifier_EString() const
{
	return m_ePackage_EOperation_getEClassifier_EString;
}

// End Class EPackage

// Begin Class EParameter
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEParameter_EClass() const
{
	return m_eParameter_EClass;
}


std::shared_ptr<ecore::EReference> EcorePackageImpl::getEParameter_EReference_eOperation() const
{
	return m_eParameter_EReference_eOperation;
}


// End Class EParameter

// Begin Class EReference
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEReference_EClass() const
{
	return m_eReference_EClass;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEReference_EAttribute_container() const
{
	return m_eReference_EAttribute_container;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEReference_EAttribute_containment() const
{
	return m_eReference_EAttribute_containment;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEReference_EAttribute_resolveProxies() const
{
	return m_eReference_EAttribute_resolveProxies;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEReference_EReference_eKeys() const
{
	return m_eReference_EReference_eKeys;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEReference_EReference_eOpposite() const
{
	return m_eReference_EReference_eOpposite;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEReference_EReference_eReferenceType() const
{
	return m_eReference_EReference_eReferenceType;
}


// End Class EReference

// Begin Class EStringToStringMapEntry
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEStringToStringMapEntry_EClass() const
{
	return m_eStringToStringMapEntry_EClass;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStringToStringMapEntry_EAttribute_key() const
{
	return m_eStringToStringMapEntry_EAttribute_key;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStringToStringMapEntry_EAttribute_value() const
{
	return m_eStringToStringMapEntry_EAttribute_value;
}



// End Class EStringToStringMapEntry

// Begin Class EStructuralFeature
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEStructuralFeature_EClass() const
{
	return m_eStructuralFeature_EClass;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_EAttribute_changeable() const
{
	return m_eStructuralFeature_EAttribute_changeable;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_EAttribute_containerClass() const
{
	return m_eStructuralFeature_EAttribute_containerClass;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_EAttribute_defaultValue() const
{
	return m_eStructuralFeature_EAttribute_defaultValue;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_EAttribute_defaultValueLiteral() const
{
	return m_eStructuralFeature_EAttribute_defaultValueLiteral;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_EAttribute_derived() const
{
	return m_eStructuralFeature_EAttribute_derived;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_EAttribute_featureID() const
{
	return m_eStructuralFeature_EAttribute_featureID;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_EAttribute_transient() const
{
	return m_eStructuralFeature_EAttribute_transient;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_EAttribute_unsettable() const
{
	return m_eStructuralFeature_EAttribute_unsettable;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_EAttribute_volatile() const
{
	return m_eStructuralFeature_EAttribute_volatile;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEStructuralFeature_EReference_eContainingClass() const
{
	return m_eStructuralFeature_EReference_eContainingClass;
}


// End Class EStructuralFeature

// Begin Class ETypeParameter
std::shared_ptr<ecore::EClass> EcorePackageImpl::getETypeParameter_EClass() const
{
	return m_eTypeParameter_EClass;
}


std::shared_ptr<ecore::EReference> EcorePackageImpl::getETypeParameter_EReference_eBounds() const
{
	return m_eTypeParameter_EReference_eBounds;
}


// End Class ETypeParameter

// Begin Class ETypedElement
std::shared_ptr<ecore::EClass> EcorePackageImpl::getETypedElement_EClass() const
{
	return m_eTypedElement_EClass;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getETypedElement_EAttribute_lowerBound() const
{
	return m_eTypedElement_EAttribute_lowerBound;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getETypedElement_EAttribute_many() const
{
	return m_eTypedElement_EAttribute_many;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getETypedElement_EAttribute_ordered() const
{
	return m_eTypedElement_EAttribute_ordered;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getETypedElement_EAttribute_required() const
{
	return m_eTypedElement_EAttribute_required;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getETypedElement_EAttribute_unique() const
{
	return m_eTypedElement_EAttribute_unique;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getETypedElement_EAttribute_upperBound() const
{
	return m_eTypedElement_EAttribute_upperBound;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getETypedElement_EReference_eGenericType() const
{
	return m_eTypedElement_EReference_eGenericType;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getETypedElement_EReference_eType() const
{
	return m_eTypedElement_EReference_eType;
}


// End Class ETypedElement
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEBigDecimal_EDataType() const
{
	return m_eBigDecimal_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEBigInteger_EDataType() const
{
	return m_eBigInteger_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEBoolean_EDataType() const
{
	return m_eBoolean_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEBooleanObject_EDataType() const
{
	return m_eBooleanObject_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEByte_EDataType() const
{
	return m_eByte_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEByteArray_EDataType() const
{
	return m_eByteArray_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEByteObject_EDataType() const
{
	return m_eByteObject_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEChar_EDataType() const
{
	return m_eChar_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getECharacterObject_EDataType() const
{
	return m_eCharacterObject_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEDate_EDataType() const
{
	return m_eDate_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEDiagnosticChain_EDataType() const
{
	return m_eDiagnosticChain_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEDouble_EDataType() const
{
	return m_eDouble_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEDoubleObject_EDataType() const
{
	return m_eDoubleObject_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEEList_EDataType() const
{
	return m_eEList_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEEnumerator_EDataType() const
{
	return m_eEnumerator_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEFeatureMap_EDataType() const
{
	return m_eFeatureMap_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEFeatureMapEntry_EDataType() const
{
	return m_eFeatureMapEntry_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEFloat_EDataType() const
{
	return m_eFloat_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEFloatObject_EDataType() const
{
	return m_eFloatObject_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEInt_EDataType() const
{
	return m_eInt_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEIntegerObject_EDataType() const
{
	return m_eIntegerObject_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEInvocationTargetException_EDataType() const
{
	return m_eInvocationTargetException_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEJavaClass_EDataType() const
{
	return m_eJavaClass_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEJavaObject_EDataType() const
{
	return m_eJavaObject_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getELong_EDataType() const
{
	return m_eLong_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getELongObject_EDataType() const
{
	return m_eLongObject_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEMap_EDataType() const
{
	return m_eMap_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEResource_EDataType() const
{
	return m_eResource_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEResourceSet_EDataType() const
{
	return m_eResourceSet_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEShort_EDataType() const
{
	return m_eShort_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEShortObject_EDataType() const
{
	return m_eShortObject_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEString_EDataType() const
{
	return m_eString_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getETreeIterator_EDataType() const
{
	return m_eTreeIterator_EDataType;
}

