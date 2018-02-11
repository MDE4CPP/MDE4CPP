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
	std::shared_ptr<EAttribute> attr;
	std::shared_ptr<EReference> ref;

 	// Initialize classes and features; add operations and parameters
	// Begin Class EAnnotation
	eAnnotationEClass->setInstanceClass(nullptr);
	eAnnotationEClass->setName("EAnnotation");
	eAnnotationEClass->setAbstract(false);
	eAnnotationEClass->setInterface(false);
	
	attr = getEAnnotation_Source();
	attr->setName("source");
	attr->setEType(getEString());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(false);
	attr->setVolatile(false);
	attr->setChangeable(true);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(false);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	
	ref = getEAnnotation_Contents();
	ref->setName("contents");
	ref->setEType(getEObject());
	ref->setLowerBound(0);
	ref->setUpperBound(-1);
	ref->setTransient(false);
	ref->setVolatile(false);
	ref->setChangeable(true);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(true);
	ref->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	ref = getEAnnotation_Details();
	ref->setName("details");
	ref->setEType(getEStringToStringMapEntry());
	ref->setLowerBound(0);
	ref->setUpperBound(-1);
	ref->setTransient(false);
	ref->setVolatile(false);
	ref->setChangeable(true);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(true);
	ref->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	ref = getEAnnotation_EModelElement();
	ref->setName("eModelElement");
	ref->setEType(getEModelElement());
	ref->setLowerBound(0);
	ref->setUpperBound(1);
	ref->setTransient(true);
	ref->setVolatile(false);
	ref->setChangeable(true);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(false);
	ref->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEModelElement_EAnnotations();
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	ref = getEAnnotation_References();
	ref->setName("references");
	ref->setEType(getEObject());
	ref->setLowerBound(0);
	ref->setUpperBound(-1);
	ref->setTransient(false);
	ref->setVolatile(false);
	ref->setChangeable(true);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(false);
	ref->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	
	
	// End Class EAnnotation

	// Begin Class EAttribute
	eAttributeEClass->setInstanceClass(nullptr);
	eAttributeEClass->setName("EAttribute");
	eAttributeEClass->setAbstract(false);
	eAttributeEClass->setInterface(false);
	
	attr = getEAttribute_ID();
	attr->setName("iD");
	attr->setEType(getEBoolean());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(false);
	attr->setVolatile(false);
	attr->setChangeable(true);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(false);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	
	ref = getEAttribute_EAttributeType();
	ref->setName("eAttributeType");
	ref->setEType(getEDataType());
	ref->setLowerBound(1);
	ref->setUpperBound(1);
	ref->setTransient(true);
	ref->setVolatile(true);
	ref->setChangeable(false);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(true);
	ref->setOrdered(true);
	ref->setContainment(false);
	ref->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	
	
	// End Class EAttribute

	// Begin Class EClass
	eClassEClass->setInstanceClass(nullptr);
	eClassEClass->setName("EClass");
	eClassEClass->setAbstract(false);
	eClassEClass->setInterface(false);
	
	attr = getEClass_Abstract();
	attr->setName("abstract");
	attr->setEType(getEBoolean());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(false);
	attr->setVolatile(false);
	attr->setChangeable(true);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(false);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	attr = getEClass_Interface();
	attr->setName("interface");
	attr->setEType(getEBoolean());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(false);
	attr->setVolatile(false);
	attr->setChangeable(true);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(false);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	
	ref = getEClass_EAllAttributes();
	ref->setName("eAllAttributes");
	ref->setEType(getEAttribute());
	ref->setLowerBound(0);
	ref->setUpperBound(-1);
	ref->setTransient(true);
	ref->setVolatile(true);
	ref->setChangeable(false);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(true);
	ref->setOrdered(true);
	ref->setContainment(false);
	ref->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	ref = getEClass_EAllContainments();
	ref->setName("eAllContainments");
	ref->setEType(getEReference());
	ref->setLowerBound(0);
	ref->setUpperBound(-1);
	ref->setTransient(true);
	ref->setVolatile(true);
	ref->setChangeable(false);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(true);
	ref->setOrdered(true);
	ref->setContainment(false);
	ref->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	ref = getEClass_EAllGenericSuperTypes();
	ref->setName("eAllGenericSuperTypes");
	ref->setEType(getEGenericType());
	ref->setLowerBound(0);
	ref->setUpperBound(-1);
	ref->setTransient(true);
	ref->setVolatile(true);
	ref->setChangeable(false);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(true);
	ref->setOrdered(true);
	ref->setContainment(false);
	ref->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	ref = getEClass_EAllOperations();
	ref->setName("eAllOperations");
	ref->setEType(getEOperation());
	ref->setLowerBound(0);
	ref->setUpperBound(-1);
	ref->setTransient(true);
	ref->setVolatile(true);
	ref->setChangeable(false);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(true);
	ref->setOrdered(true);
	ref->setContainment(false);
	ref->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	ref = getEClass_EAllReferences();
	ref->setName("eAllReferences");
	ref->setEType(getEReference());
	ref->setLowerBound(0);
	ref->setUpperBound(-1);
	ref->setTransient(true);
	ref->setVolatile(true);
	ref->setChangeable(false);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(true);
	ref->setOrdered(true);
	ref->setContainment(false);
	ref->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	ref = getEClass_EAllStructuralFeatures();
	ref->setName("eAllStructuralFeatures");
	ref->setEType(getEStructuralFeature());
	ref->setLowerBound(0);
	ref->setUpperBound(-1);
	ref->setTransient(true);
	ref->setVolatile(true);
	ref->setChangeable(false);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(true);
	ref->setOrdered(true);
	ref->setContainment(false);
	ref->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	ref = getEClass_EAllSuperTypes();
	ref->setName("eAllSuperTypes");
	ref->setEType(getEClass());
	ref->setLowerBound(0);
	ref->setUpperBound(-1);
	ref->setTransient(true);
	ref->setVolatile(true);
	ref->setChangeable(false);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(true);
	ref->setOrdered(true);
	ref->setContainment(false);
	ref->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	ref = getEClass_EAttributes();
	ref->setName("eAttributes");
	ref->setEType(getEAttribute());
	ref->setLowerBound(0);
	ref->setUpperBound(-1);
	ref->setTransient(true);
	ref->setVolatile(true);
	ref->setChangeable(false);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(true);
	ref->setOrdered(true);
	ref->setContainment(false);
	ref->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	ref = getEClass_EGenericSuperTypes();
	ref->setName("eGenericSuperTypes");
	ref->setEType(getEGenericType());
	ref->setLowerBound(0);
	ref->setUpperBound(-1);
	ref->setTransient(false);
	ref->setVolatile(false);
	ref->setChangeable(true);
	ref->setUnsettable(true);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(true);
	ref->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	ref = getEClass_EIDAttribute();
	ref->setName("eIDAttribute");
	ref->setEType(getEAttribute());
	ref->setLowerBound(0);
	ref->setUpperBound(1);
	ref->setTransient(true);
	ref->setVolatile(true);
	ref->setChangeable(false);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(true);
	ref->setOrdered(true);
	ref->setContainment(false);
	ref->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	ref = getEClass_EOperations();
	ref->setName("eOperations");
	ref->setEType(getEOperation());
	ref->setLowerBound(0);
	ref->setUpperBound(-1);
	ref->setTransient(false);
	ref->setVolatile(false);
	ref->setChangeable(true);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(true);
	ref->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEOperation_EContainingClass();
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	ref = getEClass_EReferences();
	ref->setName("eReferences");
	ref->setEType(getEReference());
	ref->setLowerBound(0);
	ref->setUpperBound(-1);
	ref->setTransient(true);
	ref->setVolatile(true);
	ref->setChangeable(false);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(true);
	ref->setOrdered(true);
	ref->setContainment(false);
	ref->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	ref = getEClass_EStructuralFeatures();
	ref->setName("eStructuralFeatures");
	ref->setEType(getEStructuralFeature());
	ref->setLowerBound(0);
	ref->setUpperBound(-1);
	ref->setTransient(false);
	ref->setVolatile(false);
	ref->setChangeable(true);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(true);
	ref->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEStructuralFeature_EContainingClass();
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	ref = getEClass_ESuperTypes();
	ref->setName("eSuperTypes");
	ref->setEType(getEClass());
	ref->setLowerBound(0);
	ref->setUpperBound(-1);
	ref->setTransient(false);
	ref->setVolatile(false);
	ref->setChangeable(true);
	ref->setUnsettable(true);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(false);
	ref->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	
	op = getEClass___GetEOperation__EInt();
	op->setEType(getEOperation());
	op->setName("getEOperation");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	addEParameter(op ,getEInt()  , "operationID",0,1, true,true);
	
	op = getEClass___GetEStructuralFeature__EInt();
	op->setEType(getEStructuralFeature());
	op->setName("getEStructuralFeature");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	addEParameter(op ,getEInt()  , "featureID",0,1, true,true);
	
	op = getEClass___GetEStructuralFeature__EString();
	op->setEType(getEStructuralFeature());
	op->setName("getEStructuralFeature");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	addEParameter(op ,getEString()  , "featureName",0,1, true,true);
	
	op = getEClass___GetFeatureCount();
	op->setEType(getEInt());
	op->setName("getFeatureCount");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	
	op = getEClass___GetFeatureID__EStructuralFeature();
	op->setEType(getEInt());
	op->setName("getFeatureID");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	addEParameter(op ,getEStructuralFeature()  , "feature",0,1, true,true);
	
	op = getEClass___GetFeatureType__EStructuralFeature();
	op->setEType(getEGenericType());
	op->setName("getFeatureType");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	addEParameter(op ,getEStructuralFeature()  , "feature",0,1, true,true);
	
	op = getEClass___GetOperationCount();
	op->setEType(getEInt());
	op->setName("getOperationCount");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	
	op = getEClass___GetOperationID__EOperation();
	op->setEType(getEInt());
	op->setName("getOperationID");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	addEParameter(op ,getEOperation()  , "operation",0,1, true,true);
	
	op = getEClass___GetOverride__EOperation();
	op->setEType(getEOperation());
	op->setName("getOverride");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	addEParameter(op ,getEOperation()  , "operation",0,1, true,true);
	
	op = getEClass___IsSuperTypeOf__EClass();
	op->setEType(getEBoolean());
	op->setName("isSuperTypeOf");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	addEParameter(op ,getEClass()  , "someClass",0,1, true,true);
	
	
	// End Class EClass

	// Begin Class EClassifier
	eClassifierEClass->setInstanceClass(nullptr);
	eClassifierEClass->setName("EClassifier");
	eClassifierEClass->setAbstract(true);
	eClassifierEClass->setInterface(false);
	
	attr = getEClassifier_ClassifierID();
	attr->setName("classifierID");
	attr->setEType(getEInt());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(false);
	attr->setVolatile(false);
	attr->setChangeable(false);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(false);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "-1";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	attr = getEClassifier_DefaultValue();
	attr->setName("defaultValue");
	attr->setEType(getEJavaObject());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(true);
	attr->setVolatile(true);
	attr->setChangeable(false);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(true);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	attr = getEClassifier_InstanceClass();
	attr->setName("instanceClass");
	attr->setEType(getEJavaClass());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(true);
	attr->setVolatile(true);
	attr->setChangeable(true);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(false);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	attr = getEClassifier_InstanceClassName();
	attr->setName("instanceClassName");
	attr->setEType(getEString());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(false);
	attr->setVolatile(true);
	attr->setChangeable(true);
	attr->setUnsettable(true);
	attr->setUnique(true);
	attr->setDerived(false);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	attr = getEClassifier_InstanceTypeName();
	attr->setName("instanceTypeName");
	attr->setEType(getEString());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(false);
	attr->setVolatile(true);
	attr->setChangeable(true);
	attr->setUnsettable(true);
	attr->setUnique(true);
	attr->setDerived(false);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	
	ref = getEClassifier_EPackage();
	ref->setName("ePackage");
	ref->setEType(getEPackage());
	ref->setLowerBound(0);
	ref->setUpperBound(1);
	ref->setTransient(true);
	ref->setVolatile(false);
	ref->setChangeable(true);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(false);
	ref->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEPackage_EClassifiers();
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	ref = getEClassifier_ETypeParameters();
	ref->setName("eTypeParameters");
	ref->setEType(getETypeParameter());
	ref->setLowerBound(0);
	ref->setUpperBound(-1);
	ref->setTransient(false);
	ref->setVolatile(false);
	ref->setChangeable(true);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(true);
	ref->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	
	op = getEClassifier___IsInstance__EJavaObject();
	op->setEType(getEBoolean());
	op->setName("isInstance");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	addEParameter(op ,getEJavaObject()  , "object",0,1, true,true);
	
	
	// End Class EClassifier

	// Begin Class EDataType
	eDataTypeEClass->setInstanceClass(nullptr);
	eDataTypeEClass->setName("EDataType");
	eDataTypeEClass->setAbstract(false);
	eDataTypeEClass->setInterface(false);
	
	attr = getEDataType_Serializable();
	attr->setName("serializable");
	attr->setEType(getEBoolean());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(false);
	attr->setVolatile(false);
	attr->setChangeable(true);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(false);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "true";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	
	// End Class EDataType

	// Begin Class EEnum
	eEnumEClass->setInstanceClass(nullptr);
	eEnumEClass->setName("EEnum");
	eEnumEClass->setAbstract(false);
	eEnumEClass->setInterface(false);
	
	
	ref = getEEnum_ELiterals();
	ref->setName("eLiterals");
	ref->setEType(getEEnumLiteral());
	ref->setLowerBound(0);
	ref->setUpperBound(-1);
	ref->setTransient(false);
	ref->setVolatile(false);
	ref->setChangeable(true);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(true);
	ref->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEEnumLiteral_EEnum();
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	
	op = getEEnum___GetEEnumLiteral__EString();
	op->setEType(getEEnumLiteral());
	op->setName("getEEnumLiteral");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	addEParameter(op ,getEString()  , "name",0,1, true,true);
	
	op = getEEnum___GetEEnumLiteral__EInt();
	op->setEType(getEEnumLiteral());
	op->setName("getEEnumLiteral");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	addEParameter(op ,getEInt()  , "value",0,1, true,true);
	
	op = getEEnum___GetEEnumLiteralByLiteral__EString();
	op->setEType(getEEnumLiteral());
	op->setName("getEEnumLiteralByLiteral");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	addEParameter(op ,getEString()  , "literal",0,1, true,true);
	
	
	// End Class EEnum

	// Begin Class EEnumLiteral
	eEnumLiteralEClass->setInstanceClass(nullptr);
	eEnumLiteralEClass->setName("EEnumLiteral");
	eEnumLiteralEClass->setAbstract(false);
	eEnumLiteralEClass->setInterface(false);
	
	attr = getEEnumLiteral_Instance();
	attr->setName("instance");
	attr->setEType(getEEnumerator());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(true);
	attr->setVolatile(false);
	attr->setChangeable(true);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(false);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	attr = getEEnumLiteral_Literal();
	attr->setName("literal");
	attr->setEType(getEString());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(false);
	attr->setVolatile(false);
	attr->setChangeable(true);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(false);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	attr = getEEnumLiteral_Value();
	attr->setName("value");
	attr->setEType(getEInt());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(false);
	attr->setVolatile(false);
	attr->setChangeable(true);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(false);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	
	ref = getEEnumLiteral_EEnum();
	ref->setName("eEnum");
	ref->setEType(getEEnum());
	ref->setLowerBound(0);
	ref->setUpperBound(1);
	ref->setTransient(true);
	ref->setVolatile(false);
	ref->setChangeable(false);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(false);
	ref->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEEnum_ELiterals();
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	
	
	// End Class EEnumLiteral

	// Begin Class EFactory
	eFactoryEClass->setInstanceClass(nullptr);
	eFactoryEClass->setName("EFactory");
	eFactoryEClass->setAbstract(false);
	eFactoryEClass->setInterface(false);
	
	
	ref = getEFactory_EPackage();
	ref->setName("ePackage");
	ref->setEType(getEPackage());
	ref->setLowerBound(1);
	ref->setUpperBound(1);
	ref->setTransient(true);
	ref->setVolatile(false);
	ref->setChangeable(true);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(false);
	ref->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEPackage_EFactoryInstance();
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	
	op = getEFactory___ConvertToString__EDataType_EJavaObject();
	op->setEType(getEString());
	op->setName("convertToString");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	addEParameter(op ,getEDataType()  , "eDataType",0,1, true,true);
	addEParameter(op ,getEJavaObject()  , "instanceValue",0,1, true,true);
	
	op = getEFactory___Create__EClass_EObject();
	op->setEType(getEObject());
	op->setName("create");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	addEParameter(op ,getEClass()  , "eClass",0,1, true,true);
	addEParameter(op ,getEObject()  , "container",0,1, true,true);
	
	op = getEFactory___CreateFromString__EDataType_EString();
	op->setEType(getEJavaObject());
	op->setName("createFromString");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	addEParameter(op ,getEDataType()  , "eDataType",0,1, true,true);
	addEParameter(op ,getEString()  , "literalValue",0,1, true,true);
	
	
	// End Class EFactory

	// Begin Class EGenericType
	eGenericTypeEClass->setInstanceClass(nullptr);
	eGenericTypeEClass->setName("EGenericType");
	eGenericTypeEClass->setAbstract(false);
	eGenericTypeEClass->setInterface(false);
	
	
	ref = getEGenericType_EClassifier();
	ref->setName("eClassifier");
	ref->setEType(getEClassifier());
	ref->setLowerBound(0);
	ref->setUpperBound(1);
	ref->setTransient(false);
	ref->setVolatile(false);
	ref->setChangeable(true);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(false);
	ref->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	ref = getEGenericType_ELowerBound();
	ref->setName("eLowerBound");
	ref->setEType(getEGenericType());
	ref->setLowerBound(0);
	ref->setUpperBound(1);
	ref->setTransient(false);
	ref->setVolatile(false);
	ref->setChangeable(true);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(true);
	ref->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	ref = getEGenericType_ERawType();
	ref->setName("eRawType");
	ref->setEType(getEClassifier());
	ref->setLowerBound(1);
	ref->setUpperBound(1);
	ref->setTransient(true);
	ref->setVolatile(false);
	ref->setChangeable(false);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(true);
	ref->setOrdered(true);
	ref->setContainment(false);
	ref->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	ref = getEGenericType_ETypeArguments();
	ref->setName("eTypeArguments");
	ref->setEType(getEGenericType());
	ref->setLowerBound(0);
	ref->setUpperBound(-1);
	ref->setTransient(false);
	ref->setVolatile(false);
	ref->setChangeable(true);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(true);
	ref->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	ref = getEGenericType_ETypeParameter();
	ref->setName("eTypeParameter");
	ref->setEType(getETypeParameter());
	ref->setLowerBound(0);
	ref->setUpperBound(1);
	ref->setTransient(false);
	ref->setVolatile(false);
	ref->setChangeable(true);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(false);
	ref->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	ref = getEGenericType_EUpperBound();
	ref->setName("eUpperBound");
	ref->setEType(getEGenericType());
	ref->setLowerBound(0);
	ref->setUpperBound(1);
	ref->setTransient(false);
	ref->setVolatile(false);
	ref->setChangeable(true);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(true);
	ref->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	
	op = getEGenericType___IsInstance__EJavaObject();
	op->setEType(getEBoolean());
	op->setName("isInstance");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	addEParameter(op ,getEJavaObject()  , "object",0,1, true,true);
	
	
	// End Class EGenericType

	// Begin Class EModelElement
	eModelElementEClass->setInstanceClass(nullptr);
	eModelElementEClass->setName("EModelElement");
	eModelElementEClass->setAbstract(true);
	eModelElementEClass->setInterface(false);
	
	
	ref = getEModelElement_EAnnotations();
	ref->setName("eAnnotations");
	ref->setEType(getEAnnotation());
	ref->setLowerBound(0);
	ref->setUpperBound(-1);
	ref->setTransient(false);
	ref->setVolatile(false);
	ref->setChangeable(true);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(true);
	ref->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEAnnotation_EModelElement();
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	
	op = getEModelElement___GetEAnnotation__EString();
	op->setEType(getEAnnotation());
	op->setName("getEAnnotation");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	addEParameter(op ,getEString()  , "source",0,1, true,true);
	
	
	// End Class EModelElement

	// Begin Class ENamedElement
	eNamedElementEClass->setInstanceClass(nullptr);
	eNamedElementEClass->setName("ENamedElement");
	eNamedElementEClass->setAbstract(true);
	eNamedElementEClass->setInterface(false);
	
	attr = getENamedElement_Name();
	attr->setName("name");
	attr->setEType(getEString());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(false);
	attr->setVolatile(false);
	attr->setChangeable(true);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(false);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	
	// End Class ENamedElement

	// Begin Class EObject
	eObjectEClass->setInstanceClass(nullptr);
	eObjectEClass->setName("EObject");
	eObjectEClass->setAbstract(false);
	eObjectEClass->setInterface(false);
	
	
	ref = getEObject_EContainer();
	ref->setName("eContainer");
	ref->setEType(getEObject());
	ref->setLowerBound(0);
	ref->setUpperBound(1);
	ref->setTransient(false);
	ref->setVolatile(false);
	ref->setChangeable(false);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(false);
	ref->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	
	op = getEObject___EAllContents();
	op->setEType(getETreeIterator());
	op->setName("eAllContents");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	
	op = getEObject___EClass();
	op->setEType(getEClass());
	op->setName("eClass");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	
	op = getEObject___EContainingFeature();
	op->setEType(getEStructuralFeature());
	op->setName("eContainingFeature");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	
	op = getEObject___EContainmentFeature();
	op->setEType(getEReference());
	op->setName("eContainmentFeature");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	
	op = getEObject___EContents();
	op->setEType(getEEList());
	op->setName("eContents");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	
	op = getEObject___ECrossReferences();
	op->setEType(getEEList());
	op->setName("eCrossReferences");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	
	op = getEObject___EGet__EStructuralFeature();
	op->setEType(getEJavaObject());
	op->setName("eGet");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	addEParameter(op ,getEStructuralFeature()  , "feature",0,1, true,true);
	
	op = getEObject___EGet__EStructuralFeature_EBoolean();
	op->setEType(getEJavaObject());
	op->setName("eGet");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	addEParameter(op ,getEStructuralFeature()  , "feature",0,1, true,true);
	addEParameter(op ,getEBoolean()  , "resolve",0,1, true,true);
	
	op = getEObject___EInvoke__EOperation_EEList();
	op->setEType(getEJavaObject());
	op->setName("eInvoke");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	addEParameter(op ,getEOperation()  , "operation",0,1, true,true);
	addEParameter(op ,getEEList()  , "arguments",0,1, true,true);
	
	op = getEObject___EIsProxy();
	op->setEType(getEBoolean());
	op->setName("eIsProxy");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	
	op = getEObject___EIsSet__EStructuralFeature();
	op->setEType(getEBoolean());
	op->setName("eIsSet");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	addEParameter(op ,getEStructuralFeature()  , "feature",0,1, true,true);
	
	op = getEObject___EResource();
	op->setEType(getEResource());
	op->setName("eResource");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	
	op = getEObject___ESet__EStructuralFeature_EJavaObject();
	op->setEType(nullptr);
	op->setName("eSet");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	addEParameter(op ,nullptr  , "feature",0,1, true,true);
	addEParameter(op ,nullptr  , "newValue",0,1, true,true);
	
	op = getEObject___EUnset__EStructuralFeature();
	op->setEType(nullptr);
	op->setName("eUnset");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	addEParameter(op ,nullptr  , "feature",0,1, true,true);
	
	
	// End Class EObject

	// Begin Class EOperation
	eOperationEClass->setInstanceClass(nullptr);
	eOperationEClass->setName("EOperation");
	eOperationEClass->setAbstract(false);
	eOperationEClass->setInterface(false);
	
	attr = getEOperation_OperationID();
	attr->setName("operationID");
	attr->setEType(getEInt());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(false);
	attr->setVolatile(false);
	attr->setChangeable(false);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(false);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "-1";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	
	ref = getEOperation_EContainingClass();
	ref->setName("eContainingClass");
	ref->setEType(getEClass());
	ref->setLowerBound(0);
	ref->setUpperBound(1);
	ref->setTransient(true);
	ref->setVolatile(false);
	ref->setChangeable(false);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(false);
	ref->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEClass_EOperations();
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	ref = getEOperation_EExceptions();
	ref->setName("eExceptions");
	ref->setEType(getEClassifier());
	ref->setLowerBound(0);
	ref->setUpperBound(-1);
	ref->setTransient(false);
	ref->setVolatile(false);
	ref->setChangeable(true);
	ref->setUnsettable(true);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(false);
	ref->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	ref = getEOperation_EGenericExceptions();
	ref->setName("eGenericExceptions");
	ref->setEType(getEGenericType());
	ref->setLowerBound(0);
	ref->setUpperBound(-1);
	ref->setTransient(false);
	ref->setVolatile(false);
	ref->setChangeable(true);
	ref->setUnsettable(true);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(true);
	ref->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	ref = getEOperation_EParameters();
	ref->setName("eParameters");
	ref->setEType(getEParameter());
	ref->setLowerBound(0);
	ref->setUpperBound(-1);
	ref->setTransient(false);
	ref->setVolatile(false);
	ref->setChangeable(true);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(true);
	ref->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEParameter_EOperation();
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	ref = getEOperation_ETypeParameters();
	ref->setName("eTypeParameters");
	ref->setEType(getETypeParameter());
	ref->setLowerBound(0);
	ref->setUpperBound(-1);
	ref->setTransient(false);
	ref->setVolatile(false);
	ref->setChangeable(true);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(true);
	ref->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	
	op = getEOperation___IsOverrideOf__EOperation();
	op->setEType(getEBoolean());
	op->setName("isOverrideOf");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	addEParameter(op ,getEOperation()  , "someOperation",0,1, true,true);
	
	
	// End Class EOperation

	// Begin Class EPackage
	ePackageEClass->setInstanceClass(nullptr);
	ePackageEClass->setName("EPackage");
	ePackageEClass->setAbstract(false);
	ePackageEClass->setInterface(false);
	
	attr = getEPackage_NsPrefix();
	attr->setName("nsPrefix");
	attr->setEType(getEString());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(false);
	attr->setVolatile(false);
	attr->setChangeable(true);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(false);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	attr = getEPackage_NsURI();
	attr->setName("nsURI");
	attr->setEType(getEString());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(false);
	attr->setVolatile(false);
	attr->setChangeable(true);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(false);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	
	ref = getEPackage_EClassifiers();
	ref->setName("eClassifiers");
	ref->setEType(getEClassifier());
	ref->setLowerBound(0);
	ref->setUpperBound(-1);
	ref->setTransient(false);
	ref->setVolatile(false);
	ref->setChangeable(true);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(true);
	ref->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEClassifier_EPackage();
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	ref = getEPackage_EFactoryInstance();
	ref->setName("eFactoryInstance");
	ref->setEType(getEFactory());
	ref->setLowerBound(1);
	ref->setUpperBound(1);
	ref->setTransient(true);
	ref->setVolatile(false);
	ref->setChangeable(true);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(false);
	ref->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEFactory_EPackage();
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	ref = getEPackage_ESubpackages();
	ref->setName("eSubpackages");
	ref->setEType(getEPackage());
	ref->setLowerBound(0);
	ref->setUpperBound(-1);
	ref->setTransient(false);
	ref->setVolatile(false);
	ref->setChangeable(true);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(true);
	ref->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEPackage_ESuperPackage();
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	ref = getEPackage_ESuperPackage();
	ref->setName("eSuperPackage");
	ref->setEType(getEPackage());
	ref->setLowerBound(0);
	ref->setUpperBound(1);
	ref->setTransient(true);
	ref->setVolatile(false);
	ref->setChangeable(false);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(false);
	ref->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEPackage_ESubpackages();
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	
	op = getEPackage___GetEClassifier__EString();
	op->setEType(getEClassifier());
	op->setName("getEClassifier");
	op->setLowerBound(0);
	op->setUpperBound(1);
	op->setUnique(true);
	op->setOrdered(true);
	addEParameter(op ,getEString()  , "name",0,1, true,true);
	
	
	// End Class EPackage

	// Begin Class EParameter
	eParameterEClass->setInstanceClass(nullptr);
	eParameterEClass->setName("EParameter");
	eParameterEClass->setAbstract(false);
	eParameterEClass->setInterface(false);
	
	
	ref = getEParameter_EOperation();
	ref->setName("eOperation");
	ref->setEType(getEOperation());
	ref->setLowerBound(0);
	ref->setUpperBound(1);
	ref->setTransient(true);
	ref->setVolatile(false);
	ref->setChangeable(false);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(false);
	ref->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEOperation_EParameters();
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	
	
	// End Class EParameter

	// Begin Class EReference
	eReferenceEClass->setInstanceClass(nullptr);
	eReferenceEClass->setName("EReference");
	eReferenceEClass->setAbstract(false);
	eReferenceEClass->setInterface(false);
	
	attr = getEReference_Container();
	attr->setName("container");
	attr->setEType(getEBoolean());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(true);
	attr->setVolatile(true);
	attr->setChangeable(false);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(true);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	attr = getEReference_Containment();
	attr->setName("containment");
	attr->setEType(getEBoolean());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(false);
	attr->setVolatile(false);
	attr->setChangeable(true);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(false);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	attr = getEReference_ResolveProxies();
	attr->setName("resolveProxies");
	attr->setEType(getEBoolean());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(false);
	attr->setVolatile(false);
	attr->setChangeable(true);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(false);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "true";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	
	ref = getEReference_EKeys();
	ref->setName("eKeys");
	ref->setEType(getEAttribute());
	ref->setLowerBound(0);
	ref->setUpperBound(-1);
	ref->setTransient(false);
	ref->setVolatile(false);
	ref->setChangeable(true);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(false);
	ref->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	ref = getEReference_EOpposite();
	ref->setName("eOpposite");
	ref->setEType(getEReference());
	ref->setLowerBound(0);
	ref->setUpperBound(1);
	ref->setTransient(false);
	ref->setVolatile(false);
	ref->setChangeable(true);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(false);
	ref->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	ref = getEReference_EReferenceType();
	ref->setName("eReferenceType");
	ref->setEType(getEClass());
	ref->setLowerBound(1);
	ref->setUpperBound(1);
	ref->setTransient(true);
	ref->setVolatile(true);
	ref->setChangeable(false);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(true);
	ref->setOrdered(true);
	ref->setContainment(false);
	ref->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	
	
	// End Class EReference

	// Begin Class EStringToStringMapEntry
	eStringToStringMapEntryEClass->setInstanceClass(nullptr);
	eStringToStringMapEntryEClass->setName("EStringToStringMapEntry");
	eStringToStringMapEntryEClass->setAbstract(false);
	eStringToStringMapEntryEClass->setInterface(false);
	
	attr = getEStringToStringMapEntry_Key();
	attr->setName("key");
	attr->setEType(getEString());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(false);
	attr->setVolatile(false);
	attr->setChangeable(true);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(false);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	attr = getEStringToStringMapEntry_Value();
	attr->setName("value");
	attr->setEType(getEString());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(false);
	attr->setVolatile(false);
	attr->setChangeable(true);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(false);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	
	// End Class EStringToStringMapEntry

	// Begin Class EStructuralFeature
	eStructuralFeatureEClass->setInstanceClass(nullptr);
	eStructuralFeatureEClass->setName("EStructuralFeature");
	eStructuralFeatureEClass->setAbstract(true);
	eStructuralFeatureEClass->setInterface(false);
	
	attr = getEStructuralFeature_Changeable();
	attr->setName("changeable");
	attr->setEType(getEBoolean());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(false);
	attr->setVolatile(false);
	attr->setChangeable(true);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(false);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "true";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	attr = getEStructuralFeature_ContainerClass();
	attr->setName("containerClass");
	attr->setEType(getEJavaClass());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(false);
	attr->setVolatile(false);
	attr->setChangeable(false);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(false);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	attr = getEStructuralFeature_DefaultValue();
	attr->setName("defaultValue");
	attr->setEType(getEJavaObject());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(true);
	attr->setVolatile(true);
	attr->setChangeable(false);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(true);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	attr = getEStructuralFeature_DefaultValueLiteral();
	attr->setName("defaultValueLiteral");
	attr->setEType(getEString());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(false);
	attr->setVolatile(false);
	attr->setChangeable(true);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(false);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	attr = getEStructuralFeature_Derived();
	attr->setName("derived");
	attr->setEType(getEBoolean());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(false);
	attr->setVolatile(false);
	attr->setChangeable(true);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(false);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	attr = getEStructuralFeature_FeatureID();
	attr->setName("featureID");
	attr->setEType(getEInt());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(false);
	attr->setVolatile(false);
	attr->setChangeable(false);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(false);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "-1";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	attr = getEStructuralFeature_Transient();
	attr->setName("transient");
	attr->setEType(getEBoolean());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(false);
	attr->setVolatile(false);
	attr->setChangeable(true);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(false);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	attr = getEStructuralFeature_Unsettable();
	attr->setName("unsettable");
	attr->setEType(getEBoolean());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(false);
	attr->setVolatile(false);
	attr->setChangeable(true);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(false);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	attr = getEStructuralFeature_Volatile();
	attr->setName("volatile");
	attr->setEType(getEBoolean());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(false);
	attr->setVolatile(false);
	attr->setChangeable(true);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(false);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	
	ref = getEStructuralFeature_EContainingClass();
	ref->setName("eContainingClass");
	ref->setEType(getEClass());
	ref->setLowerBound(0);
	ref->setUpperBound(1);
	ref->setTransient(true);
	ref->setVolatile(false);
	ref->setChangeable(false);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(false);
	ref->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getEClass_EStructuralFeatures();
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	
	
	// End Class EStructuralFeature

	// Begin Class ETypeParameter
	eTypeParameterEClass->setInstanceClass(nullptr);
	eTypeParameterEClass->setName("ETypeParameter");
	eTypeParameterEClass->setAbstract(false);
	eTypeParameterEClass->setInterface(false);
	
	
	ref = getETypeParameter_EBounds();
	ref->setName("eBounds");
	ref->setEType(getEGenericType());
	ref->setLowerBound(0);
	ref->setUpperBound(-1);
	ref->setTransient(false);
	ref->setVolatile(false);
	ref->setChangeable(true);
	ref->setUnsettable(false);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(true);
	ref->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	
	
	// End Class ETypeParameter

	// Begin Class ETypedElement
	eTypedElementEClass->setInstanceClass(nullptr);
	eTypedElementEClass->setName("ETypedElement");
	eTypedElementEClass->setAbstract(true);
	eTypedElementEClass->setInterface(false);
	
	attr = getETypedElement_LowerBound();
	attr->setName("lowerBound");
	attr->setEType(getEInt());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(false);
	attr->setVolatile(false);
	attr->setChangeable(true);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(false);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	attr = getETypedElement_Many();
	attr->setName("many");
	attr->setEType(getEBoolean());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(true);
	attr->setVolatile(true);
	attr->setChangeable(false);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(true);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	attr = getETypedElement_Ordered();
	attr->setName("ordered");
	attr->setEType(getEBoolean());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(false);
	attr->setVolatile(false);
	attr->setChangeable(true);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(false);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "true";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	attr = getETypedElement_Required();
	attr->setName("required");
	attr->setEType(getEBoolean());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(true);
	attr->setVolatile(true);
	attr->setChangeable(false);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(true);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	attr = getETypedElement_Unique();
	attr->setName("unique");
	attr->setEType(getEBoolean());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(false);
	attr->setVolatile(false);
	attr->setChangeable(true);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(false);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "true";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	attr = getETypedElement_UpperBound();
	attr->setName("upperBound");
	attr->setEType(getEInt());
	attr->setLowerBound(0);
	attr->setUpperBound(1);
	attr->setTransient(false);
	attr->setVolatile(false);
	attr->setChangeable(true);
	attr->setUnsettable(false);
	attr->setUnique(true);
	attr->setDerived(false);
	attr->setOrdered(true);
	attr->setID(false);
	{
		std::string defaultValue = "1";
		if (!defaultValue.empty())
		{
		   attr->setDefaultValueLiteral(defaultValue);
		}
	}
	
	ref = getETypedElement_EGenericType();
	ref->setName("eGenericType");
	ref->setEType(getEGenericType());
	ref->setLowerBound(0);
	ref->setUpperBound(1);
	ref->setTransient(false);
	ref->setVolatile(true);
	ref->setChangeable(true);
	ref->setUnsettable(true);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(true);
	ref->setResolveProxies(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	ref = getETypedElement_EType();
	ref->setName("eType");
	ref->setEType(getEClassifier());
	ref->setLowerBound(0);
	ref->setUpperBound(1);
	ref->setTransient(false);
	ref->setVolatile(true);
	ref->setChangeable(true);
	ref->setUnsettable(true);
	ref->setUnique(true);
	ref->setDerived(false);
	ref->setOrdered(true);
	ref->setContainment(false);
	ref->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			ref->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		ref->setEOpposite(otherEnd);
	    }
	}
	
	
	// End Class ETypedElement

	eBigDecimalEDataType->setInstanceClass(nullptr);
	eBigDecimalEDataType->setName("EBigDecimal");
	eBigDecimalEDataType->setSerializable(true);
	eBigIntegerEDataType->setInstanceClass(nullptr);
	eBigIntegerEDataType->setName("EBigInteger");
	eBigIntegerEDataType->setSerializable(true);
	eBooleanEDataType->setInstanceClass(nullptr);
	eBooleanEDataType->setName("EBoolean");
	eBooleanEDataType->setSerializable(true);
	eBooleanObjectEDataType->setInstanceClass(nullptr);
	eBooleanObjectEDataType->setName("EBooleanObject");
	eBooleanObjectEDataType->setSerializable(true);
	eByteEDataType->setInstanceClass(nullptr);
	eByteEDataType->setName("EByte");
	eByteEDataType->setSerializable(true);
	eByteArrayEDataType->setInstanceClass(nullptr);
	eByteArrayEDataType->setName("EByteArray");
	eByteArrayEDataType->setSerializable(true);
	eByteObjectEDataType->setInstanceClass(nullptr);
	eByteObjectEDataType->setName("EByteObject");
	eByteObjectEDataType->setSerializable(true);
	eCharEDataType->setInstanceClass(nullptr);
	eCharEDataType->setName("EChar");
	eCharEDataType->setSerializable(true);
	eCharacterObjectEDataType->setInstanceClass(nullptr);
	eCharacterObjectEDataType->setName("ECharacterObject");
	eCharacterObjectEDataType->setSerializable(true);
	eDateEDataType->setInstanceClass(nullptr);
	eDateEDataType->setName("EDate");
	eDateEDataType->setSerializable(true);
	eDiagnosticChainEDataType->setInstanceClass(nullptr);
	eDiagnosticChainEDataType->setName("EDiagnosticChain");
	eDiagnosticChainEDataType->setSerializable(false);
	eDoubleEDataType->setInstanceClass(nullptr);
	eDoubleEDataType->setName("EDouble");
	eDoubleEDataType->setSerializable(true);
	eDoubleObjectEDataType->setInstanceClass(nullptr);
	eDoubleObjectEDataType->setName("EDoubleObject");
	eDoubleObjectEDataType->setSerializable(true);
	eEListEDataType->setInstanceClass(nullptr);
	eEListEDataType->setName("EEList");
	eEListEDataType->setSerializable(false);
	eEnumeratorEDataType->setInstanceClass(nullptr);
	eEnumeratorEDataType->setName("EEnumerator");
	eEnumeratorEDataType->setSerializable(false);
	eFeatureMapEDataType->setInstanceClass(nullptr);
	eFeatureMapEDataType->setName("EFeatureMap");
	eFeatureMapEDataType->setSerializable(false);
	eFeatureMapEntryEDataType->setInstanceClass(nullptr);
	eFeatureMapEntryEDataType->setName("EFeatureMapEntry");
	eFeatureMapEntryEDataType->setSerializable(false);
	eFloatEDataType->setInstanceClass(nullptr);
	eFloatEDataType->setName("EFloat");
	eFloatEDataType->setSerializable(true);
	eFloatObjectEDataType->setInstanceClass(nullptr);
	eFloatObjectEDataType->setName("EFloatObject");
	eFloatObjectEDataType->setSerializable(true);
	eIntEDataType->setInstanceClass(nullptr);
	eIntEDataType->setName("EInt");
	eIntEDataType->setSerializable(true);
	eIntegerObjectEDataType->setInstanceClass(nullptr);
	eIntegerObjectEDataType->setName("EIntegerObject");
	eIntegerObjectEDataType->setSerializable(true);
	eInvocationTargetExceptionEDataType->setInstanceClass(nullptr);
	eInvocationTargetExceptionEDataType->setName("EInvocationTargetException");
	eInvocationTargetExceptionEDataType->setSerializable(false);
	eJavaClassEDataType->setInstanceClass(nullptr);
	eJavaClassEDataType->setName("EJavaClass");
	eJavaClassEDataType->setSerializable(true);
	eJavaObjectEDataType->setInstanceClass(nullptr);
	eJavaObjectEDataType->setName("EJavaObject");
	eJavaObjectEDataType->setSerializable(true);
	eLongEDataType->setInstanceClass(nullptr);
	eLongEDataType->setName("ELong");
	eLongEDataType->setSerializable(true);
	eLongObjectEDataType->setInstanceClass(nullptr);
	eLongObjectEDataType->setName("ELongObject");
	eLongObjectEDataType->setSerializable(true);
	eMapEDataType->setInstanceClass(nullptr);
	eMapEDataType->setName("EMap");
	eMapEDataType->setSerializable(false);
	eResourceEDataType->setInstanceClass(nullptr);
	eResourceEDataType->setName("EResource");
	eResourceEDataType->setSerializable(false);
	eResourceSetEDataType->setInstanceClass(nullptr);
	eResourceSetEDataType->setName("EResourceSet");
	eResourceSetEDataType->setSerializable(false);
	eShortEDataType->setInstanceClass(nullptr);
	eShortEDataType->setName("EShort");
	eShortEDataType->setSerializable(true);
	eShortObjectEDataType->setInstanceClass(nullptr);
	eShortObjectEDataType->setName("EShortObject");
	eShortObjectEDataType->setSerializable(true);
	eStringEDataType->setInstanceClass(nullptr);
	eStringEDataType->setName("EString");
	eStringEDataType->setSerializable(true);
	eTreeIteratorEDataType->setInstanceClass(nullptr);
	eTreeIteratorEDataType->setName("ETreeIterator");
	eTreeIteratorEDataType->setSerializable(false);
	
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

