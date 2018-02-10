#include "ecore/impl/EcorePackageImpl.hpp"

//metametamodel classes
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EReference.hpp"

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
	eAttributeEClass.reset();
	eAnnotationEClass.reset();
	eClassEClass.reset();
	eClassifierEClass.reset();
	eDataTypeEClass.reset();
	eEnumEClass.reset();
	eEnumLiteralEClass.reset();
	eFactoryEClass.reset();
	eModelElementEClass.reset();
	eNamedElementEClass.reset();
	eObjectEClass.reset();
	eOperationEClass.reset();
	ePackageEClass.reset();
	eParameterEClass.reset();
	eReferenceEClass.reset();
	eStructuralFeatureEClass.reset();
	eTypedElementEClass.reset();
	eStringToStringMapEntryEClass.reset();
	eGenericTypeEClass.reset();
	eTypeParameterEClass.reset();
	
	eBigDecimalEDataType.reset();
	eBigIntegerEDataType.reset();
	eBooleanEDataType.reset();
	eBooleanObjectEDataType.reset();
	eByteEDataType.reset();
	eByteArrayEDataType.reset();
	eByteObjectEDataType.reset();
	eCharEDataType.reset();
	eCharacterObjectEDataType.reset();
	eDateEDataType.reset();
	eDiagnosticChainEDataType.reset();
	eDoubleEDataType.reset();
	eDoubleObjectEDataType.reset();
	eEListEDataType.reset();
	eEnumeratorEDataType.reset();
	eFeatureMapEDataType.reset();
	eFeatureMapEntryEDataType.reset();
	eFloatEDataType.reset();
	eFloatObjectEDataType.reset();
	eIntEDataType.reset();
	eIntegerObjectEDataType.reset();
	eJavaClassEDataType.reset();
	eJavaObjectEDataType.reset();
	eLongEDataType.reset();
	eLongObjectEDataType.reset();
	eMapEDataType.reset();
	eResourceEDataType.reset();
	eResourceSetEDataType.reset();
	eShortEDataType.reset();
	eShortObjectEDataType.reset();
	eStringEDataType.reset();
	eTreeIteratorEDataType.reset();
	eInvocationTargetExceptionEDataType.reset();
	
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

	eAnnotationEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EANNOTATION);
	
	factory->createEAttribute_in_EContainingClass(eAnnotationEClass, EANNOTATION_SOURCE);
	
	factory->createEReference_in_EContainingClass(eAnnotationEClass, EANNOTATION_CONTENTS);
	factory->createEReference_in_EContainingClass(eAnnotationEClass, EANNOTATION_DETAILS);
	factory->createEReference_in_EContainingClass(eAnnotationEClass, EANNOTATION_EMODELELEMENT);
	factory->createEReference_in_EContainingClass(eAnnotationEClass, EANNOTATION_REFERENCES);
	
	

	eAttributeEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EATTRIBUTE);
	
	factory->createEAttribute_in_EContainingClass(eAttributeEClass, EATTRIBUTE_ID);
	
	factory->createEReference_in_EContainingClass(eAttributeEClass, EATTRIBUTE_EATTRIBUTETYPE);
	
	

	eClassEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ECLASS);
	
	factory->createEAttribute_in_EContainingClass(eClassEClass, ECLASS_ABSTRACT);
	factory->createEAttribute_in_EContainingClass(eClassEClass, ECLASS_INTERFACE);
	
	factory->createEReference_in_EContainingClass(eClassEClass, ECLASS_EALLATTRIBUTES);
	factory->createEReference_in_EContainingClass(eClassEClass, ECLASS_EALLCONTAINMENTS);
	factory->createEReference_in_EContainingClass(eClassEClass, ECLASS_EALLGENERICSUPERTYPES);
	factory->createEReference_in_EContainingClass(eClassEClass, ECLASS_EALLOPERATIONS);
	factory->createEReference_in_EContainingClass(eClassEClass, ECLASS_EALLREFERENCES);
	factory->createEReference_in_EContainingClass(eClassEClass, ECLASS_EALLSTRUCTURALFEATURES);
	factory->createEReference_in_EContainingClass(eClassEClass, ECLASS_EALLSUPERTYPES);
	factory->createEReference_in_EContainingClass(eClassEClass, ECLASS_EATTRIBUTES);
	factory->createEReference_in_EContainingClass(eClassEClass, ECLASS_EGENERICSUPERTYPES);
	factory->createEReference_in_EContainingClass(eClassEClass, ECLASS_EIDATTRIBUTE);
	factory->createEReference_in_EContainingClass(eClassEClass, ECLASS_EOPERATIONS);
	factory->createEReference_in_EContainingClass(eClassEClass, ECLASS_EREFERENCES);
	factory->createEReference_in_EContainingClass(eClassEClass, ECLASS_ESTRUCTURALFEATURES);
	factory->createEReference_in_EContainingClass(eClassEClass, ECLASS_ESUPERTYPES);
	
	factory->createEOperation_in_EContainingClass(eClassEClass, ECLASS___GETEOPERATION__EINT);
	factory->createEOperation_in_EContainingClass(eClassEClass, ECLASS___GETESTRUCTURALFEATURE__EINT);
	factory->createEOperation_in_EContainingClass(eClassEClass, ECLASS___GETESTRUCTURALFEATURE__ESTRING);
	factory->createEOperation_in_EContainingClass(eClassEClass, ECLASS___GETFEATURECOUNT);
	factory->createEOperation_in_EContainingClass(eClassEClass, ECLASS___GETFEATUREID__ESTRUCTURALFEATURE);
	factory->createEOperation_in_EContainingClass(eClassEClass, ECLASS___GETFEATURETYPE__ESTRUCTURALFEATURE);
	factory->createEOperation_in_EContainingClass(eClassEClass, ECLASS___GETOPERATIONCOUNT);
	factory->createEOperation_in_EContainingClass(eClassEClass, ECLASS___GETOPERATIONID__EOPERATION);
	factory->createEOperation_in_EContainingClass(eClassEClass, ECLASS___GETOVERRIDE__EOPERATION);
	factory->createEOperation_in_EContainingClass(eClassEClass, ECLASS___ISSUPERTYPEOF__ECLASS);
	

	eClassifierEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ECLASSIFIER);
	
	factory->createEAttribute_in_EContainingClass(eClassifierEClass, ECLASSIFIER_CLASSIFIERID);
	factory->createEAttribute_in_EContainingClass(eClassifierEClass, ECLASSIFIER_DEFAULTVALUE);
	factory->createEAttribute_in_EContainingClass(eClassifierEClass, ECLASSIFIER_INSTANCECLASS);
	factory->createEAttribute_in_EContainingClass(eClassifierEClass, ECLASSIFIER_INSTANCECLASSNAME);
	factory->createEAttribute_in_EContainingClass(eClassifierEClass, ECLASSIFIER_INSTANCETYPENAME);
	
	factory->createEReference_in_EContainingClass(eClassifierEClass, ECLASSIFIER_EPACKAGE);
	factory->createEReference_in_EContainingClass(eClassifierEClass, ECLASSIFIER_ETYPEPARAMETERS);
	
	factory->createEOperation_in_EContainingClass(eClassifierEClass, ECLASSIFIER___ISINSTANCE__EJAVAOBJECT);
	

	eDataTypeEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EDATATYPE);
	
	factory->createEAttribute_in_EContainingClass(eDataTypeEClass, EDATATYPE_SERIALIZABLE);
	
	
	

	eEnumEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EENUM);
	
	
	factory->createEReference_in_EContainingClass(eEnumEClass, EENUM_ELITERALS);
	
	factory->createEOperation_in_EContainingClass(eEnumEClass, EENUM___GETEENUMLITERAL__ESTRING);
	factory->createEOperation_in_EContainingClass(eEnumEClass, EENUM___GETEENUMLITERAL__EINT);
	factory->createEOperation_in_EContainingClass(eEnumEClass, EENUM___GETEENUMLITERALBYLITERAL__ESTRING);
	

	eEnumLiteralEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EENUMLITERAL);
	
	factory->createEAttribute_in_EContainingClass(eEnumLiteralEClass, EENUMLITERAL_INSTANCE);
	factory->createEAttribute_in_EContainingClass(eEnumLiteralEClass, EENUMLITERAL_LITERAL);
	factory->createEAttribute_in_EContainingClass(eEnumLiteralEClass, EENUMLITERAL_VALUE);
	
	factory->createEReference_in_EContainingClass(eEnumLiteralEClass, EENUMLITERAL_EENUM);
	
	

	eFactoryEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EFACTORY);
	
	
	factory->createEReference_in_EContainingClass(eFactoryEClass, EFACTORY_EPACKAGE);
	
	factory->createEOperation_in_EContainingClass(eFactoryEClass, EFACTORY___CONVERTTOSTRING__EDATATYPE_EJAVAOBJECT);
	factory->createEOperation_in_EContainingClass(eFactoryEClass, EFACTORY___CREATE__ECLASS_EOBJECT);
	factory->createEOperation_in_EContainingClass(eFactoryEClass, EFACTORY___CREATEFROMSTRING__EDATATYPE_ESTRING);
	

	eGenericTypeEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EGENERICTYPE);
	
	
	factory->createEReference_in_EContainingClass(eGenericTypeEClass, EGENERICTYPE_ECLASSIFIER);
	factory->createEReference_in_EContainingClass(eGenericTypeEClass, EGENERICTYPE_ELOWERBOUND);
	factory->createEReference_in_EContainingClass(eGenericTypeEClass, EGENERICTYPE_ERAWTYPE);
	factory->createEReference_in_EContainingClass(eGenericTypeEClass, EGENERICTYPE_ETYPEARGUMENTS);
	factory->createEReference_in_EContainingClass(eGenericTypeEClass, EGENERICTYPE_ETYPEPARAMETER);
	factory->createEReference_in_EContainingClass(eGenericTypeEClass, EGENERICTYPE_EUPPERBOUND);
	
	factory->createEOperation_in_EContainingClass(eGenericTypeEClass, EGENERICTYPE___ISINSTANCE__EJAVAOBJECT);
	

	eModelElementEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EMODELELEMENT);
	
	
	factory->createEReference_in_EContainingClass(eModelElementEClass, EMODELELEMENT_EANNOTATIONS);
	
	factory->createEOperation_in_EContainingClass(eModelElementEClass, EMODELELEMENT___GETEANNOTATION__ESTRING);
	

	eNamedElementEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ENAMEDELEMENT);
	
	factory->createEAttribute_in_EContainingClass(eNamedElementEClass, ENAMEDELEMENT_NAME);
	
	
	

	eObjectEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EOBJECT);
	
	
	factory->createEReference_in_EContainingClass(eObjectEClass, EOBJECT_ECONTAINER);
	
	factory->createEOperation_in_EContainingClass(eObjectEClass, EOBJECT___EALLCONTENTS);
	factory->createEOperation_in_EContainingClass(eObjectEClass, EOBJECT___ECLASS);
	factory->createEOperation_in_EContainingClass(eObjectEClass, EOBJECT___ECONTAININGFEATURE);
	factory->createEOperation_in_EContainingClass(eObjectEClass, EOBJECT___ECONTAINMENTFEATURE);
	factory->createEOperation_in_EContainingClass(eObjectEClass, EOBJECT___ECONTENTS);
	factory->createEOperation_in_EContainingClass(eObjectEClass, EOBJECT___ECROSSREFERENCES);
	factory->createEOperation_in_EContainingClass(eObjectEClass, EOBJECT___EGET__ESTRUCTURALFEATURE);
	factory->createEOperation_in_EContainingClass(eObjectEClass, EOBJECT___EGET__ESTRUCTURALFEATURE_EBOOLEAN);
	factory->createEOperation_in_EContainingClass(eObjectEClass, EOBJECT___EINVOKE__EOPERATION_EELIST);
	factory->createEOperation_in_EContainingClass(eObjectEClass, EOBJECT___EISPROXY);
	factory->createEOperation_in_EContainingClass(eObjectEClass, EOBJECT___EISSET__ESTRUCTURALFEATURE);
	factory->createEOperation_in_EContainingClass(eObjectEClass, EOBJECT___ERESOURCE);
	factory->createEOperation_in_EContainingClass(eObjectEClass, EOBJECT___ESET__ESTRUCTURALFEATURE_EJAVAOBJECT);
	factory->createEOperation_in_EContainingClass(eObjectEClass, EOBJECT___EUNSET__ESTRUCTURALFEATURE);
	

	eOperationEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EOPERATION);
	
	factory->createEAttribute_in_EContainingClass(eOperationEClass, EOPERATION_OPERATIONID);
	
	factory->createEReference_in_EContainingClass(eOperationEClass, EOPERATION_ECONTAININGCLASS);
	factory->createEReference_in_EContainingClass(eOperationEClass, EOPERATION_EEXCEPTIONS);
	factory->createEReference_in_EContainingClass(eOperationEClass, EOPERATION_EGENERICEXCEPTIONS);
	factory->createEReference_in_EContainingClass(eOperationEClass, EOPERATION_EPARAMETERS);
	factory->createEReference_in_EContainingClass(eOperationEClass, EOPERATION_ETYPEPARAMETERS);
	
	factory->createEOperation_in_EContainingClass(eOperationEClass, EOPERATION___ISOVERRIDEOF__EOPERATION);
	

	ePackageEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EPACKAGE);
	
	factory->createEAttribute_in_EContainingClass(ePackageEClass, EPACKAGE_NSPREFIX);
	factory->createEAttribute_in_EContainingClass(ePackageEClass, EPACKAGE_NSURI);
	
	factory->createEReference_in_EContainingClass(ePackageEClass, EPACKAGE_ECLASSIFIERS);
	factory->createEReference_in_EContainingClass(ePackageEClass, EPACKAGE_EFACTORYINSTANCE);
	factory->createEReference_in_EContainingClass(ePackageEClass, EPACKAGE_ESUBPACKAGES);
	factory->createEReference_in_EContainingClass(ePackageEClass, EPACKAGE_ESUPERPACKAGE);
	
	factory->createEOperation_in_EContainingClass(ePackageEClass, EPACKAGE___GETECLASSIFIER__ESTRING);
	

	eParameterEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EPARAMETER);
	
	
	factory->createEReference_in_EContainingClass(eParameterEClass, EPARAMETER_EOPERATION);
	
	

	eReferenceEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EREFERENCE);
	
	factory->createEAttribute_in_EContainingClass(eReferenceEClass, EREFERENCE_CONTAINER);
	factory->createEAttribute_in_EContainingClass(eReferenceEClass, EREFERENCE_CONTAINMENT);
	factory->createEAttribute_in_EContainingClass(eReferenceEClass, EREFERENCE_RESOLVEPROXIES);
	
	factory->createEReference_in_EContainingClass(eReferenceEClass, EREFERENCE_EKEYS);
	factory->createEReference_in_EContainingClass(eReferenceEClass, EREFERENCE_EOPPOSITE);
	factory->createEReference_in_EContainingClass(eReferenceEClass, EREFERENCE_EREFERENCETYPE);
	
	

	eStringToStringMapEntryEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ESTRINGTOSTRINGMAPENTRY);
	
	factory->createEAttribute_in_EContainingClass(eStringToStringMapEntryEClass, ESTRINGTOSTRINGMAPENTRY_KEY);
	factory->createEAttribute_in_EContainingClass(eStringToStringMapEntryEClass, ESTRINGTOSTRINGMAPENTRY_VALUE);
	
	
	

	eStructuralFeatureEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ESTRUCTURALFEATURE);
	
	factory->createEAttribute_in_EContainingClass(eStructuralFeatureEClass, ESTRUCTURALFEATURE_CHANGEABLE);
	factory->createEAttribute_in_EContainingClass(eStructuralFeatureEClass, ESTRUCTURALFEATURE_CONTAINERCLASS);
	factory->createEAttribute_in_EContainingClass(eStructuralFeatureEClass, ESTRUCTURALFEATURE_DEFAULTVALUE);
	factory->createEAttribute_in_EContainingClass(eStructuralFeatureEClass, ESTRUCTURALFEATURE_DEFAULTVALUELITERAL);
	factory->createEAttribute_in_EContainingClass(eStructuralFeatureEClass, ESTRUCTURALFEATURE_DERIVED);
	factory->createEAttribute_in_EContainingClass(eStructuralFeatureEClass, ESTRUCTURALFEATURE_FEATUREID);
	factory->createEAttribute_in_EContainingClass(eStructuralFeatureEClass, ESTRUCTURALFEATURE_TRANSIENT);
	factory->createEAttribute_in_EContainingClass(eStructuralFeatureEClass, ESTRUCTURALFEATURE_UNSETTABLE);
	factory->createEAttribute_in_EContainingClass(eStructuralFeatureEClass, ESTRUCTURALFEATURE_VOLATILE);
	
	factory->createEReference_in_EContainingClass(eStructuralFeatureEClass, ESTRUCTURALFEATURE_ECONTAININGCLASS);
	
	

	eTypeParameterEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ETYPEPARAMETER);
	
	
	factory->createEReference_in_EContainingClass(eTypeParameterEClass, ETYPEPARAMETER_EBOUNDS);
	
	

	eTypedElementEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ETYPEDELEMENT);
	
	factory->createEAttribute_in_EContainingClass(eTypedElementEClass, ETYPEDELEMENT_LOWERBOUND);
	factory->createEAttribute_in_EContainingClass(eTypedElementEClass, ETYPEDELEMENT_MANY);
	factory->createEAttribute_in_EContainingClass(eTypedElementEClass, ETYPEDELEMENT_ORDERED);
	factory->createEAttribute_in_EContainingClass(eTypedElementEClass, ETYPEDELEMENT_REQUIRED);
	factory->createEAttribute_in_EContainingClass(eTypedElementEClass, ETYPEDELEMENT_UNIQUE);
	factory->createEAttribute_in_EContainingClass(eTypedElementEClass, ETYPEDELEMENT_UPPERBOUND);
	
	factory->createEReference_in_EContainingClass(eTypedElementEClass, ETYPEDELEMENT_EGENERICTYPE);
	factory->createEReference_in_EContainingClass(eTypedElementEClass, ETYPEDELEMENT_ETYPE);
	
	

	eBigDecimalEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EBIGDECIMAL);
	eBigIntegerEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EBIGINTEGER);
	eBooleanEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EBOOLEAN);
	eBooleanObjectEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EBOOLEANOBJECT);
	eByteEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EBYTE);
	eByteArrayEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EBYTEARRAY);
	eByteObjectEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EBYTEOBJECT);
	eCharEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ECHAR);
	eCharacterObjectEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ECHARACTEROBJECT);
	eDateEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EDATE);
	eDiagnosticChainEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EDIAGNOSTICCHAIN);
	eDoubleEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EDOUBLE);
	eDoubleObjectEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EDOUBLEOBJECT);
	eEListEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EELIST);
	eEnumeratorEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EENUMERATOR);
	eFeatureMapEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EFEATUREMAP);
	eFeatureMapEntryEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EFEATUREMAPENTRY);
	eFloatEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EFLOAT);
	eFloatObjectEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EFLOATOBJECT);
	eIntEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EINT);
	eIntegerObjectEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EINTEGEROBJECT);
	eInvocationTargetExceptionEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EINVOCATIONTARGETEXCEPTION);
	eJavaClassEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EJAVACLASS);
	eJavaObjectEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EJAVAOBJECT);
	eLongEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ELONG);
	eLongObjectEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ELONGOBJECT);
	eMapEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EMAP);
	eResourceEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ERESOURCE);
	eResourceSetEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ERESOURCESET);
	eShortEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ESHORT);
	eShortObjectEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ESHORTOBJECT);
	eStringEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ESTRING);
	eTreeIteratorEDataType = factory->createEDataType_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ETREEITERATOR);
	
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
	eAnnotationEClass->getESuperTypes()->push_back(getEModelElement());
	eAttributeEClass->getESuperTypes()->push_back(getEStructuralFeature());
	eClassEClass->getESuperTypes()->push_back(getEClassifier());
	eClassifierEClass->getESuperTypes()->push_back(getENamedElement());
	eDataTypeEClass->getESuperTypes()->push_back(getEClassifier());
	eEnumEClass->getESuperTypes()->push_back(getEDataType());
	eEnumLiteralEClass->getESuperTypes()->push_back(getENamedElement());
	eFactoryEClass->getESuperTypes()->push_back(getEModelElement());
	eGenericTypeEClass->getESuperTypes()->push_back(getEObject());
	eNamedElementEClass->getESuperTypes()->push_back(getEModelElement());
	eOperationEClass->getESuperTypes()->push_back(getETypedElement());
	ePackageEClass->getESuperTypes()->push_back(getENamedElement());
	eParameterEClass->getESuperTypes()->push_back(getETypedElement());
	eReferenceEClass->getESuperTypes()->push_back(getEStructuralFeature());
	eStringToStringMapEntryEClass->getESuperTypes()->push_back(getEObject());
	eStructuralFeatureEClass->getESuperTypes()->push_back(getETypedElement());
	eTypeParameterEClass->getESuperTypes()->push_back(getENamedElement());
	eTypedElementEClass->getESuperTypes()->push_back(getENamedElement());
	
	std::shared_ptr<EOperation> op;

 	// Initialize classes and features; add operations and parameters
	// Begin Class EAnnotation
	initEClass(eAnnotationEClass, nullptr, "EAnnotation", false, false, true);
	initEAttribute(getEAnnotation_Source(),getEString(),"source","",0,1, false,false, true, false, false, true, false, true);
	
	initEReference(getEAnnotation_Contents(),getEObject(),nullptr,"contents","",0,-1, false,false, true, true, false, false, true, false,true);
	initEReference(getEAnnotation_Details(),getEStringToStringMapEntry(),nullptr,"details","",0,-1, false,false, true, true, false, false, true, false,true);
	initEReference(getEAnnotation_EModelElement(),getEModelElement(),getEModelElement_EAnnotations(),"eModelElement","",0,1, true,false, true, false, false, false, true, false,true);
	initEReference(getEAnnotation_References(),getEObject(),nullptr,"references","",0,-1, false,false, true, false, true, false, true, false,true);
	
	
	// End Class EAnnotation

	// Begin Class EAttribute
	initEClass(eAttributeEClass, nullptr, "EAttribute", false, false, true);
	initEAttribute(getEAttribute_ID(),getEBoolean(),"iD","",0,1, false,false, true, false, false, true, false, true);
	
	initEReference(getEAttribute_EAttributeType(),getEDataType(),nullptr,"eAttributeType","",1,1, true,true, false, false, true, false, true, true,true);
	
	
	// End Class EAttribute

	// Begin Class EClass
	initEClass(eClassEClass, nullptr, "EClass", false, false, true);
	initEAttribute(getEClass_Abstract(),getEBoolean(),"abstract","",0,1, false,false, true, false, false, true, false, true);
	initEAttribute(getEClass_Interface(),getEBoolean(),"interface","",0,1, false,false, true, false, false, true, false, true);
	
	initEReference(getEClass_EAllAttributes(),getEAttribute(),nullptr,"eAllAttributes","",0,-1, true,true, false, false, true, false, true, true,true);
	initEReference(getEClass_EAllContainments(),getEReference(),nullptr,"eAllContainments","",0,-1, true,true, false, false, true, false, true, true,true);
	initEReference(getEClass_EAllGenericSuperTypes(),getEGenericType(),nullptr,"eAllGenericSuperTypes","",0,-1, true,true, false, false, true, false, true, true,true);
	initEReference(getEClass_EAllOperations(),getEOperation(),nullptr,"eAllOperations","",0,-1, true,true, false, false, true, false, true, true,true);
	initEReference(getEClass_EAllReferences(),getEReference(),nullptr,"eAllReferences","",0,-1, true,true, false, false, true, false, true, true,true);
	initEReference(getEClass_EAllStructuralFeatures(),getEStructuralFeature(),nullptr,"eAllStructuralFeatures","",0,-1, true,true, false, false, true, false, true, true,true);
	initEReference(getEClass_EAllSuperTypes(),getEClass(),nullptr,"eAllSuperTypes","",0,-1, true,true, false, false, true, false, true, true,true);
	initEReference(getEClass_EAttributes(),getEAttribute(),nullptr,"eAttributes","",0,-1, true,true, false, false, true, false, true, true,true);
	initEReference(getEClass_EGenericSuperTypes(),getEGenericType(),nullptr,"eGenericSuperTypes","",0,-1, false,false, true, true, false, true, true, false,true);
	initEReference(getEClass_EIDAttribute(),getEAttribute(),nullptr,"eIDAttribute","",0,1, true,true, false, false, false, false, true, true,true);
	initEReference(getEClass_EOperations(),getEOperation(),getEOperation_EContainingClass(),"eOperations","",0,-1, false,false, true, true, false, false, true, false,true);
	initEReference(getEClass_EReferences(),getEReference(),nullptr,"eReferences","",0,-1, true,true, false, false, true, false, true, true,true);
	initEReference(getEClass_EStructuralFeatures(),getEStructuralFeature(),getEStructuralFeature_EContainingClass(),"eStructuralFeatures","",0,-1, false,false, true, true, false, false, true, false,true);
	initEReference(getEClass_ESuperTypes(),getEClass(),nullptr,"eSuperTypes","",0,-1, false,false, true, false, true, true, true, false,true);
	
	op = initEOperation(getEClass___GetEOperation__EInt(),getEOperation(), "getEOperation", 0, 1, true,true );
	addEParameter(op ,getEInt()  , "operationID",0,1, true,true);
	
	op = initEOperation(getEClass___GetEStructuralFeature__EInt(),getEStructuralFeature(), "getEStructuralFeature", 0, 1, true,true );
	addEParameter(op ,getEInt()  , "featureID",0,1, true,true);
	
	op = initEOperation(getEClass___GetEStructuralFeature__EString(),getEStructuralFeature(), "getEStructuralFeature", 0, 1, true,true );
	addEParameter(op ,getEString()  , "featureName",0,1, true,true);
	
	op = initEOperation(getEClass___GetFeatureCount(),getEInt(), "getFeatureCount", 0, 1, true,true );
	
	op = initEOperation(getEClass___GetFeatureID__EStructuralFeature(),getEInt(), "getFeatureID", 0, 1, true,true );
	addEParameter(op ,getEStructuralFeature()  , "feature",0,1, true,true);
	
	op = initEOperation(getEClass___GetFeatureType__EStructuralFeature(),getEGenericType(), "getFeatureType", 0, 1, true,true );
	addEParameter(op ,getEStructuralFeature()  , "feature",0,1, true,true);
	
	op = initEOperation(getEClass___GetOperationCount(),getEInt(), "getOperationCount", 0, 1, true,true );
	
	op = initEOperation(getEClass___GetOperationID__EOperation(),getEInt(), "getOperationID", 0, 1, true,true );
	addEParameter(op ,getEOperation()  , "operation",0,1, true,true);
	
	op = initEOperation(getEClass___GetOverride__EOperation(),getEOperation(), "getOverride", 0, 1, true,true );
	addEParameter(op ,getEOperation()  , "operation",0,1, true,true);
	
	op = initEOperation(getEClass___IsSuperTypeOf__EClass(),getEBoolean(), "isSuperTypeOf", 0, 1, true,true );
	addEParameter(op ,getEClass()  , "someClass",0,1, true,true);
	
	
	// End Class EClass

	// Begin Class EClassifier
	initEClass(eClassifierEClass, nullptr, "EClassifier", true, false, true);
	initEAttribute(getEClassifier_ClassifierID(),getEInt(),"classifierID","-1",0,1, false,false, false, false, false, true, false, true);
	initEAttribute(getEClassifier_DefaultValue(),getEJavaObject(),"defaultValue","",0,1, true,true, false, false, false, true, true, true);
	initEAttribute(getEClassifier_InstanceClass(),getEJavaClass(),"instanceClass","",0,1, true,true, true, false, false, true, false, true);
	initEAttribute(getEClassifier_InstanceClassName(),getEString(),"instanceClassName","",0,1, false,true, true, true, false, true, false, true);
	initEAttribute(getEClassifier_InstanceTypeName(),getEString(),"instanceTypeName","",0,1, false,true, true, true, false, true, false, true);
	
	initEReference(getEClassifier_EPackage(),getEPackage(),getEPackage_EClassifiers(),"ePackage","",0,1, true,false, true, false, true, false, true, false,true);
	initEReference(getEClassifier_ETypeParameters(),getETypeParameter(),nullptr,"eTypeParameters","",0,-1, false,false, true, true, true, false, true, false,true);
	
	op = initEOperation(getEClassifier___IsInstance__EJavaObject(),getEBoolean(), "isInstance", 0, 1, true,true );
	addEParameter(op ,getEJavaObject()  , "object",0,1, true,true);
	
	
	// End Class EClassifier

	// Begin Class EDataType
	initEClass(eDataTypeEClass, nullptr, "EDataType", false, false, true);
	initEAttribute(getEDataType_Serializable(),getEBoolean(),"serializable","true",0,1, false,false, true, false, false, true, false, true);
	
	
	
	// End Class EDataType

	// Begin Class EEnum
	initEClass(eEnumEClass, nullptr, "EEnum", false, false, true);
	
	initEReference(getEEnum_ELiterals(),getEEnumLiteral(),getEEnumLiteral_EEnum(),"eLiterals","",0,-1, false,false, true, true, false, false, true, false,true);
	
	op = initEOperation(getEEnum___GetEEnumLiteral__EString(),getEEnumLiteral(), "getEEnumLiteral", 0, 1, true,true );
	addEParameter(op ,getEString()  , "name",0,1, true,true);
	
	op = initEOperation(getEEnum___GetEEnumLiteral__EInt(),getEEnumLiteral(), "getEEnumLiteral", 0, 1, true,true );
	addEParameter(op ,getEInt()  , "value",0,1, true,true);
	
	op = initEOperation(getEEnum___GetEEnumLiteralByLiteral__EString(),getEEnumLiteral(), "getEEnumLiteralByLiteral", 0, 1, true,true );
	addEParameter(op ,getEString()  , "literal",0,1, true,true);
	
	
	// End Class EEnum

	// Begin Class EEnumLiteral
	initEClass(eEnumLiteralEClass, nullptr, "EEnumLiteral", false, false, true);
	initEAttribute(getEEnumLiteral_Instance(),getEEnumerator(),"instance","",0,1, true,false, true, false, false, true, false, true);
	initEAttribute(getEEnumLiteral_Literal(),getEString(),"literal","",0,1, false,false, true, false, false, true, false, true);
	initEAttribute(getEEnumLiteral_Value(),getEInt(),"value","",0,1, false,false, true, false, false, true, false, true);
	
	initEReference(getEEnumLiteral_EEnum(),getEEnum(),getEEnum_ELiterals(),"eEnum","",0,1, true,false, false, false, false, false, true, false,true);
	
	
	// End Class EEnumLiteral

	// Begin Class EFactory
	initEClass(eFactoryEClass, nullptr, "EFactory", false, false, true);
	
	initEReference(getEFactory_EPackage(),getEPackage(),getEPackage_EFactoryInstance(),"ePackage","",1,1, true,false, true, false, false, false, true, false,true);
	
	op = initEOperation(getEFactory___ConvertToString__EDataType_EJavaObject(),getEString(), "convertToString", 0, 1, true,true );
	addEParameter(op ,getEDataType()  , "eDataType",0,1, true,true);
	addEParameter(op ,getEJavaObject()  , "instanceValue",0,1, true,true);
	
	op = initEOperation(getEFactory___Create__EClass_EObject(),getEObject(), "create", 0, 1, true,true );
	addEParameter(op ,getEClass()  , "eClass",0,1, true,true);
	addEParameter(op ,getEObject()  , "container",0,1, true,true);
	
	op = initEOperation(getEFactory___CreateFromString__EDataType_EString(),getEJavaObject(), "createFromString", 0, 1, true,true );
	addEParameter(op ,getEDataType()  , "eDataType",0,1, true,true);
	addEParameter(op ,getEString()  , "literalValue",0,1, true,true);
	
	
	// End Class EFactory

	// Begin Class EGenericType
	initEClass(eGenericTypeEClass, nullptr, "EGenericType", false, false, true);
	
	initEReference(getEGenericType_EClassifier(),getEClassifier(),nullptr,"eClassifier","",0,1, false,false, true, false, true, false, true, false,true);
	initEReference(getEGenericType_ELowerBound(),getEGenericType(),nullptr,"eLowerBound","",0,1, false,false, true, true, false, false, true, false,true);
	initEReference(getEGenericType_ERawType(),getEClassifier(),nullptr,"eRawType","",1,1, true,false, false, false, true, false, true, true,true);
	initEReference(getEGenericType_ETypeArguments(),getEGenericType(),nullptr,"eTypeArguments","",0,-1, false,false, true, true, false, false, true, false,true);
	initEReference(getEGenericType_ETypeParameter(),getETypeParameter(),nullptr,"eTypeParameter","",0,1, false,false, true, false, false, false, true, false,true);
	initEReference(getEGenericType_EUpperBound(),getEGenericType(),nullptr,"eUpperBound","",0,1, false,false, true, true, false, false, true, false,true);
	
	op = initEOperation(getEGenericType___IsInstance__EJavaObject(),getEBoolean(), "isInstance", 0, 1, true,true );
	addEParameter(op ,getEJavaObject()  , "object",0,1, true,true);
	
	
	// End Class EGenericType

	// Begin Class EModelElement
	initEClass(eModelElementEClass, nullptr, "EModelElement", true, false, true);
	
	initEReference(getEModelElement_EAnnotations(),getEAnnotation(),getEAnnotation_EModelElement(),"eAnnotations","",0,-1, false,false, true, true, false, false, true, false,true);
	
	op = initEOperation(getEModelElement___GetEAnnotation__EString(),getEAnnotation(), "getEAnnotation", 0, 1, true,true );
	addEParameter(op ,getEString()  , "source",0,1, true,true);
	
	
	// End Class EModelElement

	// Begin Class ENamedElement
	initEClass(eNamedElementEClass, nullptr, "ENamedElement", true, false, true);
	initEAttribute(getENamedElement_Name(),getEString(),"name","",0,1, false,false, true, false, false, true, false, true);
	
	
	
	// End Class ENamedElement

	// Begin Class EObject
	initEClass(eObjectEClass, nullptr, "EObject", false, false, true);
	
	initEReference(getEObject_EContainer(),getEObject(),nullptr,"eContainer","",0,1, false,false, false, false, true, false, true, false,true);
	
	op = initEOperation(getEObject___EAllContents(),getETreeIterator(), "eAllContents", 0, 1, true,true );
	
	op = initEOperation(getEObject___EClass(),getEClass(), "eClass", 0, 1, true,true );
	
	op = initEOperation(getEObject___EContainingFeature(),getEStructuralFeature(), "eContainingFeature", 0, 1, true,true );
	
	op = initEOperation(getEObject___EContainmentFeature(),getEReference(), "eContainmentFeature", 0, 1, true,true );
	
	op = initEOperation(getEObject___EContents(),getEEList(), "eContents", 0, 1, true,true );
	
	op = initEOperation(getEObject___ECrossReferences(),getEEList(), "eCrossReferences", 0, 1, true,true );
	
	op = initEOperation(getEObject___EGet__EStructuralFeature(),getEJavaObject(), "eGet", 0, 1, true,true );
	addEParameter(op ,getEStructuralFeature()  , "feature",0,1, true,true);
	
	op = initEOperation(getEObject___EGet__EStructuralFeature_EBoolean(),getEJavaObject(), "eGet", 0, 1, true,true );
	addEParameter(op ,getEStructuralFeature()  , "feature",0,1, true,true);
	addEParameter(op ,getEBoolean()  , "resolve",0,1, true,true);
	
	op = initEOperation(getEObject___EInvoke__EOperation_EEList(),getEJavaObject(), "eInvoke", 0, 1, true,true );
	addEParameter(op ,getEOperation()  , "operation",0,1, true,true);
	addEParameter(op ,getEEList()  , "arguments",0,1, true,true);
	
	op = initEOperation(getEObject___EIsProxy(),getEBoolean(), "eIsProxy", 0, 1, true,true );
	
	op = initEOperation(getEObject___EIsSet__EStructuralFeature(),getEBoolean(), "eIsSet", 0, 1, true,true );
	addEParameter(op ,getEStructuralFeature()  , "feature",0,1, true,true);
	
	op = initEOperation(getEObject___EResource(),getEResource(), "eResource", 0, 1, true,true );
	
	op = initEOperation(getEObject___ESet__EStructuralFeature_EJavaObject(),nullptr, "eSet", 0, 1, true,true );
	addEParameter(op ,nullptr  , "feature",0,1, true,true);
	addEParameter(op ,nullptr  , "newValue",0,1, true,true);
	
	op = initEOperation(getEObject___EUnset__EStructuralFeature(),nullptr, "eUnset", 0, 1, true,true );
	addEParameter(op ,nullptr  , "feature",0,1, true,true);
	
	
	// End Class EObject

	// Begin Class EOperation
	initEClass(eOperationEClass, nullptr, "EOperation", false, false, true);
	initEAttribute(getEOperation_OperationID(),getEInt(),"operationID","-1",0,1, false,false, false, false, false, true, false, true);
	
	initEReference(getEOperation_EContainingClass(),getEClass(),getEClass_EOperations(),"eContainingClass","",0,1, true,false, false, false, false, false, true, false,true);
	initEReference(getEOperation_EExceptions(),getEClassifier(),nullptr,"eExceptions","",0,-1, false,false, true, false, true, true, true, false,true);
	initEReference(getEOperation_EGenericExceptions(),getEGenericType(),nullptr,"eGenericExceptions","",0,-1, false,false, true, true, false, true, true, false,true);
	initEReference(getEOperation_EParameters(),getEParameter(),getEParameter_EOperation(),"eParameters","",0,-1, false,false, true, true, false, false, true, false,true);
	initEReference(getEOperation_ETypeParameters(),getETypeParameter(),nullptr,"eTypeParameters","",0,-1, false,false, true, true, true, false, true, false,true);
	
	op = initEOperation(getEOperation___IsOverrideOf__EOperation(),getEBoolean(), "isOverrideOf", 0, 1, true,true );
	addEParameter(op ,getEOperation()  , "someOperation",0,1, true,true);
	
	
	// End Class EOperation

	// Begin Class EPackage
	initEClass(ePackageEClass, nullptr, "EPackage", false, false, true);
	initEAttribute(getEPackage_NsPrefix(),getEString(),"nsPrefix","",0,1, false,false, true, false, false, true, false, true);
	initEAttribute(getEPackage_NsURI(),getEString(),"nsURI","",0,1, false,false, true, false, false, true, false, true);
	
	initEReference(getEPackage_EClassifiers(),getEClassifier(),getEClassifier_EPackage(),"eClassifiers","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getEPackage_EFactoryInstance(),getEFactory(),getEFactory_EPackage(),"eFactoryInstance","",1,1, true,false, true, false, false, false, true, false,true);
	initEReference(getEPackage_ESubpackages(),getEPackage(),getEPackage_ESuperPackage(),"eSubpackages","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getEPackage_ESuperPackage(),getEPackage(),getEPackage_ESubpackages(),"eSuperPackage","",0,1, true,false, false, false, true, false, true, false,true);
	
	op = initEOperation(getEPackage___GetEClassifier__EString(),getEClassifier(), "getEClassifier", 0, 1, true,true );
	addEParameter(op ,getEString()  , "name",0,1, true,true);
	
	
	// End Class EPackage

	// Begin Class EParameter
	initEClass(eParameterEClass, nullptr, "EParameter", false, false, true);
	
	initEReference(getEParameter_EOperation(),getEOperation(),getEOperation_EParameters(),"eOperation","",0,1, true,false, false, false, false, false, true, false,true);
	
	
	// End Class EParameter

	// Begin Class EReference
	initEClass(eReferenceEClass, nullptr, "EReference", false, false, true);
	initEAttribute(getEReference_Container(),getEBoolean(),"container","",0,1, true,true, false, false, false, true, true, true);
	initEAttribute(getEReference_Containment(),getEBoolean(),"containment","",0,1, false,false, true, false, false, true, false, true);
	initEAttribute(getEReference_ResolveProxies(),getEBoolean(),"resolveProxies","true",0,1, false,false, true, false, false, true, false, true);
	
	initEReference(getEReference_EKeys(),getEAttribute(),nullptr,"eKeys","",0,-1, false,false, true, false, true, false, true, false,true);
	initEReference(getEReference_EOpposite(),getEReference(),nullptr,"eOpposite","",0,1, false,false, true, false, true, false, true, false,true);
	initEReference(getEReference_EReferenceType(),getEClass(),nullptr,"eReferenceType","",1,1, true,true, false, false, true, false, true, true,true);
	
	
	// End Class EReference

	// Begin Class EStringToStringMapEntry
	initEClass(eStringToStringMapEntryEClass, nullptr, "EStringToStringMapEntry", false, false, true);
	initEAttribute(getEStringToStringMapEntry_Key(),getEString(),"key","",0,1, false,false, true, false, false, true, false, true);
	initEAttribute(getEStringToStringMapEntry_Value(),getEString(),"value","",0,1, false,false, true, false, false, true, false, true);
	
	
	
	// End Class EStringToStringMapEntry

	// Begin Class EStructuralFeature
	initEClass(eStructuralFeatureEClass, nullptr, "EStructuralFeature", true, false, true);
	initEAttribute(getEStructuralFeature_Changeable(),getEBoolean(),"changeable","true",0,1, false,false, true, false, false, true, false, true);
	initEAttribute(getEStructuralFeature_ContainerClass(),getEJavaClass(),"containerClass","",0,1, false,false, false, false, false, true, false, true);
	initEAttribute(getEStructuralFeature_DefaultValue(),getEJavaObject(),"defaultValue","",0,1, true,true, false, false, false, true, true, true);
	initEAttribute(getEStructuralFeature_DefaultValueLiteral(),getEString(),"defaultValueLiteral","",0,1, false,false, true, false, false, true, false, true);
	initEAttribute(getEStructuralFeature_Derived(),getEBoolean(),"derived","",0,1, false,false, true, false, false, true, false, true);
	initEAttribute(getEStructuralFeature_FeatureID(),getEInt(),"featureID","-1",0,1, false,false, false, false, false, true, false, true);
	initEAttribute(getEStructuralFeature_Transient(),getEBoolean(),"transient","",0,1, false,false, true, false, false, true, false, true);
	initEAttribute(getEStructuralFeature_Unsettable(),getEBoolean(),"unsettable","",0,1, false,false, true, false, false, true, false, true);
	initEAttribute(getEStructuralFeature_Volatile(),getEBoolean(),"volatile","",0,1, false,false, true, false, false, true, false, true);
	
	initEReference(getEStructuralFeature_EContainingClass(),getEClass(),getEClass_EStructuralFeatures(),"eContainingClass","",0,1, true,false, false, false, false, false, true, false,true);
	
	
	// End Class EStructuralFeature

	// Begin Class ETypeParameter
	initEClass(eTypeParameterEClass, nullptr, "ETypeParameter", false, false, true);
	
	initEReference(getETypeParameter_EBounds(),getEGenericType(),nullptr,"eBounds","",0,-1, false,false, true, true, false, false, true, false,true);
	
	
	// End Class ETypeParameter

	// Begin Class ETypedElement
	initEClass(eTypedElementEClass, nullptr, "ETypedElement", true, false, true);
	initEAttribute(getETypedElement_LowerBound(),getEInt(),"lowerBound","",0,1, false,false, true, false, false, true, false, true);
	initEAttribute(getETypedElement_Many(),getEBoolean(),"many","",0,1, true,true, false, false, false, true, true, true);
	initEAttribute(getETypedElement_Ordered(),getEBoolean(),"ordered","true",0,1, false,false, true, false, false, true, false, true);
	initEAttribute(getETypedElement_Required(),getEBoolean(),"required","",0,1, true,true, false, false, false, true, true, true);
	initEAttribute(getETypedElement_Unique(),getEBoolean(),"unique","true",0,1, false,false, true, false, false, true, false, true);
	initEAttribute(getETypedElement_UpperBound(),getEInt(),"upperBound","1",0,1, false,false, true, false, false, true, false, true);
	
	initEReference(getETypedElement_EGenericType(),getEGenericType(),nullptr,"eGenericType","",0,1, false,true, true, true, false, true, true, false,true);
	initEReference(getETypedElement_EType(),getEClassifier(),nullptr,"eType","",0,1, false,true, true, false, true, true, true, false,true);
	
	
	// End Class ETypedElement

	initEDataType(eBigDecimalEDataType, nullptr, "EBigDecimal", true, true);
	initEDataType(eBigIntegerEDataType, nullptr, "EBigInteger", true, true);
	initEDataType(eBooleanEDataType, nullptr, "EBoolean", true, true);
	initEDataType(eBooleanObjectEDataType, nullptr, "EBooleanObject", true, true);
	initEDataType(eByteEDataType, nullptr, "EByte", true, true);
	initEDataType(eByteArrayEDataType, nullptr, "EByteArray", true, true);
	initEDataType(eByteObjectEDataType, nullptr, "EByteObject", true, true);
	initEDataType(eCharEDataType, nullptr, "EChar", true, true);
	initEDataType(eCharacterObjectEDataType, nullptr, "ECharacterObject", true, true);
	initEDataType(eDateEDataType, nullptr, "EDate", true, true);
	initEDataType(eDiagnosticChainEDataType, nullptr, "EDiagnosticChain", false, true);
	initEDataType(eDoubleEDataType, nullptr, "EDouble", true, true);
	initEDataType(eDoubleObjectEDataType, nullptr, "EDoubleObject", true, true);
	initEDataType(eEListEDataType, nullptr, "EEList", false, true);
	initEDataType(eEnumeratorEDataType, nullptr, "EEnumerator", false, true);
	initEDataType(eFeatureMapEDataType, nullptr, "EFeatureMap", false, true);
	initEDataType(eFeatureMapEntryEDataType, nullptr, "EFeatureMapEntry", false, true);
	initEDataType(eFloatEDataType, nullptr, "EFloat", true, true);
	initEDataType(eFloatObjectEDataType, nullptr, "EFloatObject", true, true);
	initEDataType(eIntEDataType, nullptr, "EInt", true, true);
	initEDataType(eIntegerObjectEDataType, nullptr, "EIntegerObject", true, true);
	initEDataType(eInvocationTargetExceptionEDataType, nullptr, "EInvocationTargetException", false, true);
	initEDataType(eJavaClassEDataType, nullptr, "EJavaClass", true, true);
	initEDataType(eJavaObjectEDataType, nullptr, "EJavaObject", true, true);
	initEDataType(eLongEDataType, nullptr, "ELong", true, true);
	initEDataType(eLongObjectEDataType, nullptr, "ELongObject", true, true);
	initEDataType(eMapEDataType, nullptr, "EMap", false, true);
	initEDataType(eResourceEDataType, nullptr, "EResource", false, true);
	initEDataType(eResourceSetEDataType, nullptr, "EResourceSet", false, true);
	initEDataType(eShortEDataType, nullptr, "EShort", true, true);
	initEDataType(eShortObjectEDataType, nullptr, "EShortObject", true, true);
	initEDataType(eStringEDataType, nullptr, "EString", true, true);
	initEDataType(eTreeIteratorEDataType, nullptr, "ETreeIterator", false, true);
	
}

// Begin Class EAnnotation
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEAnnotation() const
{
	return eAnnotationEClass;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEAnnotation_Source() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eAnnotationEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEAnnotation_Contents() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eAnnotationEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEAnnotation_Details() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eAnnotationEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEAnnotation_EModelElement() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eAnnotationEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEAnnotation_References() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eAnnotationEClass->getEStructuralFeatures()->at(4));
}


// End Class EAnnotation

// Begin Class EAttribute
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEAttribute() const
{
	return eAttributeEClass;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEAttribute_ID() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eAttributeEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEAttribute_EAttributeType() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eAttributeEClass->getEStructuralFeatures()->at(1));
}


// End Class EAttribute

// Begin Class EClass
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEClass() const
{
	return eClassEClass;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEClass_Abstract() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eClassEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEClass_Interface() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eClassEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EAllAttributes() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eClassEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EAllContainments() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eClassEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EAllGenericSuperTypes() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eClassEClass->getEStructuralFeatures()->at(4));
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EAllOperations() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eClassEClass->getEStructuralFeatures()->at(5));
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EAllReferences() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eClassEClass->getEStructuralFeatures()->at(6));
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EAllStructuralFeatures() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eClassEClass->getEStructuralFeatures()->at(7));
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EAllSuperTypes() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eClassEClass->getEStructuralFeatures()->at(8));
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EAttributes() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eClassEClass->getEStructuralFeatures()->at(9));
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EGenericSuperTypes() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eClassEClass->getEStructuralFeatures()->at(10));
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EIDAttribute() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eClassEClass->getEStructuralFeatures()->at(11));
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EOperations() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eClassEClass->getEStructuralFeatures()->at(12));
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EReferences() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eClassEClass->getEStructuralFeatures()->at(13));
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EStructuralFeatures() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eClassEClass->getEStructuralFeatures()->at(14));
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_ESuperTypes() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eClassEClass->getEStructuralFeatures()->at(15));
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass___GetEOperation__EInt() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eClassEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass___GetEStructuralFeature__EInt() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eClassEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass___GetEStructuralFeature__EString() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eClassEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass___GetFeatureCount() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eClassEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass___GetFeatureID__EStructuralFeature() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eClassEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass___GetFeatureType__EStructuralFeature() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eClassEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass___GetOperationCount() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eClassEClass->getEOperations()->at(6));
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass___GetOperationID__EOperation() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eClassEClass->getEOperations()->at(7));
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass___GetOverride__EOperation() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eClassEClass->getEOperations()->at(8));
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass___IsSuperTypeOf__EClass() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eClassEClass->getEOperations()->at(9));
}

// End Class EClass

// Begin Class EClassifier
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEClassifier() const
{
	return eClassifierEClass;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEClassifier_ClassifierID() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eClassifierEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEClassifier_DefaultValue() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eClassifierEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEClassifier_InstanceClass() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eClassifierEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEClassifier_InstanceClassName() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eClassifierEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEClassifier_InstanceTypeName() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eClassifierEClass->getEStructuralFeatures()->at(4));
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClassifier_EPackage() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eClassifierEClass->getEStructuralFeatures()->at(5));
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClassifier_ETypeParameters() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eClassifierEClass->getEStructuralFeatures()->at(6));
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClassifier___IsInstance__EJavaObject() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eClassifierEClass->getEOperations()->at(0));
}

// End Class EClassifier

// Begin Class EDataType
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEDataType() const
{
	return eDataTypeEClass;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEDataType_Serializable() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eDataTypeEClass->getEStructuralFeatures()->at(0));
}



// End Class EDataType

// Begin Class EEnum
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEEnum() const
{
	return eEnumEClass;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEEnum_ELiterals() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eEnumEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEEnum___GetEEnumLiteral__EString() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eEnumEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEEnum___GetEEnumLiteral__EInt() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eEnumEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEEnum___GetEEnumLiteralByLiteral__EString() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eEnumEClass->getEOperations()->at(2));
}

// End Class EEnum

// Begin Class EEnumLiteral
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEEnumLiteral() const
{
	return eEnumLiteralEClass;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEEnumLiteral_Instance() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eEnumLiteralEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEEnumLiteral_Literal() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eEnumLiteralEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEEnumLiteral_Value() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eEnumLiteralEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEEnumLiteral_EEnum() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eEnumLiteralEClass->getEStructuralFeatures()->at(3));
}


// End Class EEnumLiteral

// Begin Class EFactory
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEFactory() const
{
	return eFactoryEClass;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEFactory_EPackage() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eFactoryEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEFactory___ConvertToString__EDataType_EJavaObject() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eFactoryEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEFactory___Create__EClass_EObject() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eFactoryEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEFactory___CreateFromString__EDataType_EString() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eFactoryEClass->getEOperations()->at(2));
}

// End Class EFactory

// Begin Class EGenericType
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEGenericType() const
{
	return eGenericTypeEClass;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEGenericType_EClassifier() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eGenericTypeEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEGenericType_ELowerBound() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eGenericTypeEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEGenericType_ERawType() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eGenericTypeEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEGenericType_ETypeArguments() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eGenericTypeEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEGenericType_ETypeParameter() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eGenericTypeEClass->getEStructuralFeatures()->at(4));
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEGenericType_EUpperBound() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eGenericTypeEClass->getEStructuralFeatures()->at(5));
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEGenericType___IsInstance__EJavaObject() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eGenericTypeEClass->getEOperations()->at(0));
}

// End Class EGenericType

// Begin Class EModelElement
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEModelElement() const
{
	return eModelElementEClass;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEModelElement_EAnnotations() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eModelElementEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEModelElement___GetEAnnotation__EString() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eModelElementEClass->getEOperations()->at(0));
}

// End Class EModelElement

// Begin Class ENamedElement
std::shared_ptr<ecore::EClass> EcorePackageImpl::getENamedElement() const
{
	return eNamedElementEClass;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getENamedElement_Name() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eNamedElementEClass->getEStructuralFeatures()->at(0));
}



// End Class ENamedElement

// Begin Class EObject
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEObject() const
{
	return eObjectEClass;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEObject_EContainer() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eObjectEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject___EAllContents() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eObjectEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject___EClass() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eObjectEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject___EContainingFeature() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eObjectEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject___EContainmentFeature() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eObjectEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject___EContents() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eObjectEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject___ECrossReferences() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eObjectEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject___EGet__EStructuralFeature() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eObjectEClass->getEOperations()->at(6));
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject___EGet__EStructuralFeature_EBoolean() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eObjectEClass->getEOperations()->at(7));
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject___EInvoke__EOperation_EEList() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eObjectEClass->getEOperations()->at(8));
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject___EIsProxy() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eObjectEClass->getEOperations()->at(9));
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject___EIsSet__EStructuralFeature() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eObjectEClass->getEOperations()->at(10));
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject___EResource() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eObjectEClass->getEOperations()->at(11));
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject___ESet__EStructuralFeature_EJavaObject() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eObjectEClass->getEOperations()->at(12));
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject___EUnset__EStructuralFeature() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eObjectEClass->getEOperations()->at(13));
}

// End Class EObject

// Begin Class EOperation
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEOperation() const
{
	return eOperationEClass;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEOperation_OperationID() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eOperationEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEOperation_EContainingClass() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eOperationEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEOperation_EExceptions() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eOperationEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEOperation_EGenericExceptions() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eOperationEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEOperation_EParameters() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eOperationEClass->getEStructuralFeatures()->at(4));
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEOperation_ETypeParameters() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eOperationEClass->getEStructuralFeatures()->at(5));
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEOperation___IsOverrideOf__EOperation() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eOperationEClass->getEOperations()->at(0));
}

// End Class EOperation

// Begin Class EPackage
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEPackage() const
{
	return ePackageEClass;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEPackage_NsPrefix() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(ePackageEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEPackage_NsURI() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(ePackageEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEPackage_EClassifiers() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(ePackageEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEPackage_EFactoryInstance() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(ePackageEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEPackage_ESubpackages() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(ePackageEClass->getEStructuralFeatures()->at(4));
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEPackage_ESuperPackage() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(ePackageEClass->getEStructuralFeatures()->at(5));
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEPackage___GetEClassifier__EString() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(ePackageEClass->getEOperations()->at(0));
}

// End Class EPackage

// Begin Class EParameter
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEParameter() const
{
	return eParameterEClass;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEParameter_EOperation() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eParameterEClass->getEStructuralFeatures()->at(0));
}


// End Class EParameter

// Begin Class EReference
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEReference() const
{
	return eReferenceEClass;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEReference_Container() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eReferenceEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEReference_Containment() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eReferenceEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEReference_ResolveProxies() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eReferenceEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEReference_EKeys() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eReferenceEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEReference_EOpposite() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eReferenceEClass->getEStructuralFeatures()->at(4));
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEReference_EReferenceType() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eReferenceEClass->getEStructuralFeatures()->at(5));
}


// End Class EReference

// Begin Class EStringToStringMapEntry
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEStringToStringMapEntry() const
{
	return eStringToStringMapEntryEClass;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStringToStringMapEntry_Key() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eStringToStringMapEntryEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStringToStringMapEntry_Value() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eStringToStringMapEntryEClass->getEStructuralFeatures()->at(1));
}



// End Class EStringToStringMapEntry

// Begin Class EStructuralFeature
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEStructuralFeature() const
{
	return eStructuralFeatureEClass;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_Changeable() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eStructuralFeatureEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_ContainerClass() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eStructuralFeatureEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_DefaultValue() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eStructuralFeatureEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_DefaultValueLiteral() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eStructuralFeatureEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_Derived() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eStructuralFeatureEClass->getEStructuralFeatures()->at(4));
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_FeatureID() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eStructuralFeatureEClass->getEStructuralFeatures()->at(5));
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_Transient() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eStructuralFeatureEClass->getEStructuralFeatures()->at(6));
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_Unsettable() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eStructuralFeatureEClass->getEStructuralFeatures()->at(7));
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_Volatile() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eStructuralFeatureEClass->getEStructuralFeatures()->at(8));
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEStructuralFeature_EContainingClass() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eStructuralFeatureEClass->getEStructuralFeatures()->at(9));
}


// End Class EStructuralFeature

// Begin Class ETypeParameter
std::shared_ptr<ecore::EClass> EcorePackageImpl::getETypeParameter() const
{
	return eTypeParameterEClass;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getETypeParameter_EBounds() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eTypeParameterEClass->getEStructuralFeatures()->at(0));
}


// End Class ETypeParameter

// Begin Class ETypedElement
std::shared_ptr<ecore::EClass> EcorePackageImpl::getETypedElement() const
{
	return eTypedElementEClass;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getETypedElement_LowerBound() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eTypedElementEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getETypedElement_Many() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eTypedElementEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getETypedElement_Ordered() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eTypedElementEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getETypedElement_Required() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eTypedElementEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getETypedElement_Unique() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eTypedElementEClass->getEStructuralFeatures()->at(4));
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getETypedElement_UpperBound() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(eTypedElementEClass->getEStructuralFeatures()->at(5));
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getETypedElement_EGenericType() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eTypedElementEClass->getEStructuralFeatures()->at(6));
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getETypedElement_EType() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(eTypedElementEClass->getEStructuralFeatures()->at(7));
}


// End Class ETypedElement
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEBigDecimal() const
{
	assert(eBigDecimalEDataType);
	return eBigDecimalEDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEBigInteger() const
{
	assert(eBigIntegerEDataType);
	return eBigIntegerEDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEBoolean() const
{
	assert(eBooleanEDataType);
	return eBooleanEDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEBooleanObject() const
{
	assert(eBooleanObjectEDataType);
	return eBooleanObjectEDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEByte() const
{
	assert(eByteEDataType);
	return eByteEDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEByteArray() const
{
	assert(eByteArrayEDataType);
	return eByteArrayEDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEByteObject() const
{
	assert(eByteObjectEDataType);
	return eByteObjectEDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEChar() const
{
	assert(eCharEDataType);
	return eCharEDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getECharacterObject() const
{
	assert(eCharacterObjectEDataType);
	return eCharacterObjectEDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEDate() const
{
	assert(eDateEDataType);
	return eDateEDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEDiagnosticChain() const
{
	assert(eDiagnosticChainEDataType);
	return eDiagnosticChainEDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEDouble() const
{
	assert(eDoubleEDataType);
	return eDoubleEDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEDoubleObject() const
{
	assert(eDoubleObjectEDataType);
	return eDoubleObjectEDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEEList() const
{
	assert(eEListEDataType);
	return eEListEDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEEnumerator() const
{
	assert(eEnumeratorEDataType);
	return eEnumeratorEDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEFeatureMap() const
{
	assert(eFeatureMapEDataType);
	return eFeatureMapEDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEFeatureMapEntry() const
{
	assert(eFeatureMapEntryEDataType);
	return eFeatureMapEntryEDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEFloat() const
{
	assert(eFloatEDataType);
	return eFloatEDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEFloatObject() const
{
	assert(eFloatObjectEDataType);
	return eFloatObjectEDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEInt() const
{
	assert(eIntEDataType);
	return eIntEDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEIntegerObject() const
{
	assert(eIntegerObjectEDataType);
	return eIntegerObjectEDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEInvocationTargetException() const
{
	assert(eInvocationTargetExceptionEDataType);
	return eInvocationTargetExceptionEDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEJavaClass() const
{
	assert(eJavaClassEDataType);
	return eJavaClassEDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEJavaObject() const
{
	assert(eJavaObjectEDataType);
	return eJavaObjectEDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getELong() const
{
	assert(eLongEDataType);
	return eLongEDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getELongObject() const
{
	assert(eLongObjectEDataType);
	return eLongObjectEDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEMap() const
{
	assert(eMapEDataType);
	return eMapEDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEResource() const
{
	assert(eResourceEDataType);
	return eResourceEDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEResourceSet() const
{
	assert(eResourceSetEDataType);
	return eResourceSetEDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEShort() const
{
	assert(eShortEDataType);
	return eShortEDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEShortObject() const
{
	assert(eShortObjectEDataType);
	return eShortObjectEDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEString() const
{
	assert(eStringEDataType);
	return eStringEDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getETreeIterator() const
{
	assert(eTreeIteratorEDataType);
	return eTreeIteratorEDataType;
}

