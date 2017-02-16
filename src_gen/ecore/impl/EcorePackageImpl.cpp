#include "EcorePackageImpl.hpp"

//metametamodel classes
#include "EAttribute.hpp"
#include "EClass.hpp"
#include "EDataType.hpp"
#include "EEnum.hpp"
#include "EOperation.hpp"
#include "EReference.hpp"

//metamodel factory
#include "EcoreFactory.hpp"

//depending model packages

using namespace ecore;

bool EcorePackageImpl::isInited = false;

EcorePackageImpl::EcorePackageImpl()
{
	setEFactoryInstance(EcoreFactory::eInstance());
}

EcorePackageImpl::~EcorePackageImpl()
{
	if (eAttributeEClass != nullptr)
	{
		delete(eAttributeEClass);
		eAttributeEClass = nullptr;
	}
	if (eAnnotationEClass != nullptr)
	{
		delete(eAnnotationEClass);
		eAnnotationEClass = nullptr;
	}
	if (eClassEClass != nullptr)
	{
		delete(eClassEClass);
		eClassEClass = nullptr;
	}
	if (eClassifierEClass != nullptr)
	{
		delete(eClassifierEClass);
		eClassifierEClass = nullptr;
	}
	if (eDataTypeEClass != nullptr)
	{
		delete(eDataTypeEClass);
		eDataTypeEClass = nullptr;
	}
	if (eEnumEClass != nullptr)
	{
		delete(eEnumEClass);
		eEnumEClass = nullptr;
	}
	if (eEnumLiteralEClass != nullptr)
	{
		delete(eEnumLiteralEClass);
		eEnumLiteralEClass = nullptr;
	}
	if (eFactoryEClass != nullptr)
	{
		delete(eFactoryEClass);
		eFactoryEClass = nullptr;
	}
	if (eModelElementEClass != nullptr)
	{
		delete(eModelElementEClass);
		eModelElementEClass = nullptr;
	}
	if (eNamedElementEClass != nullptr)
	{
		delete(eNamedElementEClass);
		eNamedElementEClass = nullptr;
	}
	if (eObjectEClass != nullptr)
	{
		delete(eObjectEClass);
		eObjectEClass = nullptr;
	}
	if (eOperationEClass != nullptr)
	{
		delete(eOperationEClass);
		eOperationEClass = nullptr;
	}
	if (ePackageEClass != nullptr)
	{
		delete(ePackageEClass);
		ePackageEClass = nullptr;
	}
	if (eParameterEClass != nullptr)
	{
		delete(eParameterEClass);
		eParameterEClass = nullptr;
	}
	if (eReferenceEClass != nullptr)
	{
		delete(eReferenceEClass);
		eReferenceEClass = nullptr;
	}
	if (eStructuralFeatureEClass != nullptr)
	{
		delete(eStructuralFeatureEClass);
		eStructuralFeatureEClass = nullptr;
	}
	if (eTypedElementEClass != nullptr)
	{
		delete(eTypedElementEClass);
		eTypedElementEClass = nullptr;
	}
	if (eStringToStringMapEntryEClass != nullptr)
	{
		delete(eStringToStringMapEntryEClass);
		eStringToStringMapEntryEClass = nullptr;
	}
	if (eGenericTypeEClass != nullptr)
	{
		delete(eGenericTypeEClass);
		eGenericTypeEClass = nullptr;
	}
	if (eTypeParameterEClass != nullptr)
	{
		delete(eTypeParameterEClass);
		eTypeParameterEClass = nullptr;
	}
	
	if (eBigDecimalEDataType != nullptr)
	{
		delete(eBigDecimalEDataType);
		eBigDecimalEDataType = nullptr;
	}
	if (eBigIntegerEDataType != nullptr)
	{
		delete(eBigIntegerEDataType);
		eBigIntegerEDataType = nullptr;
	}
	if (eBooleanEDataType != nullptr)
	{
		delete(eBooleanEDataType);
		eBooleanEDataType = nullptr;
	}
	if (eBooleanObjectEDataType != nullptr)
	{
		delete(eBooleanObjectEDataType);
		eBooleanObjectEDataType = nullptr;
	}
	if (eByteEDataType != nullptr)
	{
		delete(eByteEDataType);
		eByteEDataType = nullptr;
	}
	if (eByteArrayEDataType != nullptr)
	{
		delete(eByteArrayEDataType);
		eByteArrayEDataType = nullptr;
	}
	if (eByteObjectEDataType != nullptr)
	{
		delete(eByteObjectEDataType);
		eByteObjectEDataType = nullptr;
	}
	if (eCharEDataType != nullptr)
	{
		delete(eCharEDataType);
		eCharEDataType = nullptr;
	}
	if (eCharacterObjectEDataType != nullptr)
	{
		delete(eCharacterObjectEDataType);
		eCharacterObjectEDataType = nullptr;
	}
	if (eDateEDataType != nullptr)
	{
		delete(eDateEDataType);
		eDateEDataType = nullptr;
	}
	if (eDiagnosticChainEDataType != nullptr)
	{
		delete(eDiagnosticChainEDataType);
		eDiagnosticChainEDataType = nullptr;
	}
	if (eDoubleEDataType != nullptr)
	{
		delete(eDoubleEDataType);
		eDoubleEDataType = nullptr;
	}
	if (eDoubleObjectEDataType != nullptr)
	{
		delete(eDoubleObjectEDataType);
		eDoubleObjectEDataType = nullptr;
	}
	if (eEListEDataType != nullptr)
	{
		delete(eEListEDataType);
		eEListEDataType = nullptr;
	}
	if (eEnumeratorEDataType != nullptr)
	{
		delete(eEnumeratorEDataType);
		eEnumeratorEDataType = nullptr;
	}
	if (eFeatureMapEDataType != nullptr)
	{
		delete(eFeatureMapEDataType);
		eFeatureMapEDataType = nullptr;
	}
	if (eFeatureMapEntryEDataType != nullptr)
	{
		delete(eFeatureMapEntryEDataType);
		eFeatureMapEntryEDataType = nullptr;
	}
	if (eFloatEDataType != nullptr)
	{
		delete(eFloatEDataType);
		eFloatEDataType = nullptr;
	}
	if (eFloatObjectEDataType != nullptr)
	{
		delete(eFloatObjectEDataType);
		eFloatObjectEDataType = nullptr;
	}
	if (eIntEDataType != nullptr)
	{
		delete(eIntEDataType);
		eIntEDataType = nullptr;
	}
	if (eIntegerObjectEDataType != nullptr)
	{
		delete(eIntegerObjectEDataType);
		eIntegerObjectEDataType = nullptr;
	}
	if (eJavaClassEDataType != nullptr)
	{
		delete(eJavaClassEDataType);
		eJavaClassEDataType = nullptr;
	}
	if (eJavaObjectEDataType != nullptr)
	{
		delete(eJavaObjectEDataType);
		eJavaObjectEDataType = nullptr;
	}
	if (eLongEDataType != nullptr)
	{
		delete(eLongEDataType);
		eLongEDataType = nullptr;
	}
	if (eLongObjectEDataType != nullptr)
	{
		delete(eLongObjectEDataType);
		eLongObjectEDataType = nullptr;
	}
	if (eMapEDataType != nullptr)
	{
		delete(eMapEDataType);
		eMapEDataType = nullptr;
	}
	if (eResourceEDataType != nullptr)
	{
		delete(eResourceEDataType);
		eResourceEDataType = nullptr;
	}
	if (eResourceSetEDataType != nullptr)
	{
		delete(eResourceSetEDataType);
		eResourceSetEDataType = nullptr;
	}
	if (eShortEDataType != nullptr)
	{
		delete(eShortEDataType);
		eShortEDataType = nullptr;
	}
	if (eShortObjectEDataType != nullptr)
	{
		delete(eShortObjectEDataType);
		eShortObjectEDataType = nullptr;
	}
	if (eStringEDataType != nullptr)
	{
		delete(eStringEDataType);
		eStringEDataType = nullptr;
	}
	if (eTreeIteratorEDataType != nullptr)
	{
		delete(eTreeIteratorEDataType);
		eTreeIteratorEDataType = nullptr;
	}
	if (eInvocationTargetExceptionEDataType != nullptr)
	{
		delete(eInvocationTargetExceptionEDataType);
		eInvocationTargetExceptionEDataType = nullptr;
	}
	
}

EcorePackage* EcorePackageImpl::create()
{
	if (isInited)
	{
		return EcorePackage::eInstance();
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

	eAnnotationEClass = createEClass(EANNOTATION);
	createEAttribute(eAnnotationEClass, EANNOTATION_SOURCE);
	createEReference(eAnnotationEClass, EANNOTATION_CONTENTS);
	createEReference(eAnnotationEClass, EANNOTATION_DETAILS);
	createEReference(eAnnotationEClass, EANNOTATION_EMODELELEMENT);
	createEReference(eAnnotationEClass, EANNOTATION_REFERENCES);
	
	

	eAttributeEClass = createEClass(EATTRIBUTE);
	createEAttribute(eAttributeEClass, EATTRIBUTE_ID);
	createEReference(eAttributeEClass, EATTRIBUTE_EATTRIBUTETYPE);
	
	

	eClassEClass = createEClass(ECLASS);
	createEAttribute(eClassEClass, ECLASS_ABSTRACT);createEAttribute(eClassEClass, ECLASS_INTERFACE);
	createEReference(eClassEClass, ECLASS_EALLATTRIBUTES);
	createEReference(eClassEClass, ECLASS_EALLCONTAINMENTS);
	createEReference(eClassEClass, ECLASS_EALLGENERICSUPERTYPES);
	createEReference(eClassEClass, ECLASS_EALLOPERATIONS);
	createEReference(eClassEClass, ECLASS_EALLREFERENCES);
	createEReference(eClassEClass, ECLASS_EALLSTRUCTURALFEATURES);
	createEReference(eClassEClass, ECLASS_EALLSUPERTYPES);
	createEReference(eClassEClass, ECLASS_EATTRIBUTES);
	createEReference(eClassEClass, ECLASS_EGENERICSUPERTYPES);
	createEReference(eClassEClass, ECLASS_EIDATTRIBUTE);
	createEReference(eClassEClass, ECLASS_EOPERATIONS);
	createEReference(eClassEClass, ECLASS_EREFERENCES);
	createEReference(eClassEClass, ECLASS_ESTRUCTURALFEATURES);
	createEReference(eClassEClass, ECLASS_ESUPERTYPES);
	
	createEOperation(eClassEClass, ECLASS___GETEOPERATION__EINT);
	createEOperation(eClassEClass, ECLASS___GETESTRUCTURALFEATURE__EINT);
	createEOperation(eClassEClass, ECLASS___GETESTRUCTURALFEATURE__ESTRING);
	createEOperation(eClassEClass, ECLASS___GETFEATURECOUNT);
	createEOperation(eClassEClass, ECLASS___GETFEATUREID__ESTRUCTURALFEATURE);
	createEOperation(eClassEClass, ECLASS___GETFEATURETYPE__ESTRUCTURALFEATURE);
	createEOperation(eClassEClass, ECLASS___GETOPERATIONCOUNT);
	createEOperation(eClassEClass, ECLASS___GETOPERATIONID__EOPERATION);
	createEOperation(eClassEClass, ECLASS___GETOVERRIDE__EOPERATION);
	createEOperation(eClassEClass, ECLASS___ISSUPERTYPEOF__ECLASS);
	

	eClassifierEClass = createEClass(ECLASSIFIER);
	createEAttribute(eClassifierEClass, ECLASSIFIER_CLASSIFIERID);createEAttribute(eClassifierEClass, ECLASSIFIER_DEFAULTVALUE);createEAttribute(eClassifierEClass, ECLASSIFIER_INSTANCECLASS);createEAttribute(eClassifierEClass, ECLASSIFIER_INSTANCECLASSNAME);createEAttribute(eClassifierEClass, ECLASSIFIER_INSTANCETYPENAME);
	createEReference(eClassifierEClass, ECLASSIFIER_EPACKAGE);
	createEReference(eClassifierEClass, ECLASSIFIER_ETYPEPARAMETERS);
	
	createEOperation(eClassifierEClass, ECLASSIFIER___ISINSTANCE__EJAVAOBJECT);
	

	eDataTypeEClass = createEClass(EDATATYPE);
	createEAttribute(eDataTypeEClass, EDATATYPE_SERIALIZABLE);
	
	

	eEnumEClass = createEClass(EENUM);
	
	createEReference(eEnumEClass, EENUM_ELITERALS);
	
	createEOperation(eEnumEClass, EENUM___GETEENUMLITERAL__ESTRING);
	createEOperation(eEnumEClass, EENUM___GETEENUMLITERAL__EINT);
	createEOperation(eEnumEClass, EENUM___GETEENUMLITERALBYLITERAL__ESTRING);
	

	eEnumLiteralEClass = createEClass(EENUMLITERAL);
	createEAttribute(eEnumLiteralEClass, EENUMLITERAL_INSTANCE);createEAttribute(eEnumLiteralEClass, EENUMLITERAL_LITERAL);createEAttribute(eEnumLiteralEClass, EENUMLITERAL_VALUE);
	createEReference(eEnumLiteralEClass, EENUMLITERAL_EENUM);
	
	

	eFactoryEClass = createEClass(EFACTORY);
	
	createEReference(eFactoryEClass, EFACTORY_EPACKAGE);
	
	createEOperation(eFactoryEClass, EFACTORY___CONVERTTOSTRING__EDATATYPE_EJAVAOBJECT);
	createEOperation(eFactoryEClass, EFACTORY___CREATE__ECLASS);
	createEOperation(eFactoryEClass, EFACTORY___CREATEFROMSTRING__EDATATYPE_ESTRING);
	

	eGenericTypeEClass = createEClass(EGENERICTYPE);
	
	createEReference(eGenericTypeEClass, EGENERICTYPE_ECLASSIFIER);
	createEReference(eGenericTypeEClass, EGENERICTYPE_ELOWERBOUND);
	createEReference(eGenericTypeEClass, EGENERICTYPE_ERAWTYPE);
	createEReference(eGenericTypeEClass, EGENERICTYPE_ETYPEARGUMENTS);
	createEReference(eGenericTypeEClass, EGENERICTYPE_ETYPEPARAMETER);
	createEReference(eGenericTypeEClass, EGENERICTYPE_EUPPERBOUND);
	
	createEOperation(eGenericTypeEClass, EGENERICTYPE___ISINSTANCE__EJAVAOBJECT);
	

	eModelElementEClass = createEClass(EMODELELEMENT);
	
	createEReference(eModelElementEClass, EMODELELEMENT_EANNOTATIONS);
	
	createEOperation(eModelElementEClass, EMODELELEMENT___GETEANNOTATION__ESTRING);
	

	eNamedElementEClass = createEClass(ENAMEDELEMENT);
	createEAttribute(eNamedElementEClass, ENAMEDELEMENT_NAME);
	
	

	eObjectEClass = createEClass(EOBJECT);
	
	createEReference(eObjectEClass, EOBJECT_ECONTAINER);
	
	createEOperation(eObjectEClass, EOBJECT___EALLCONTENTS);
	createEOperation(eObjectEClass, EOBJECT___ECLASS);
	createEOperation(eObjectEClass, EOBJECT___ECONTAININGFEATURE);
	createEOperation(eObjectEClass, EOBJECT___ECONTAINMENTFEATURE);
	createEOperation(eObjectEClass, EOBJECT___ECONTENTS);
	createEOperation(eObjectEClass, EOBJECT___ECROSSREFERENCES);
	createEOperation(eObjectEClass, EOBJECT___EGET__ESTRUCTURALFEATURE);
	createEOperation(eObjectEClass, EOBJECT___EGET__ESTRUCTURALFEATURE_EBOOLEAN);
	createEOperation(eObjectEClass, EOBJECT___EINVOKE__EOPERATION_EELIST);
	createEOperation(eObjectEClass, EOBJECT___EISPROXY);
	createEOperation(eObjectEClass, EOBJECT___EISSET__ESTRUCTURALFEATURE);
	createEOperation(eObjectEClass, EOBJECT___ERESOURCE);
	createEOperation(eObjectEClass, EOBJECT___ESET__ESTRUCTURALFEATURE_EJAVAOBJECT);
	createEOperation(eObjectEClass, EOBJECT___EUNSET__ESTRUCTURALFEATURE);
	

	eOperationEClass = createEClass(EOPERATION);
	createEAttribute(eOperationEClass, EOPERATION_OPERATIONID);
	createEReference(eOperationEClass, EOPERATION_ECONTAININGCLASS);
	createEReference(eOperationEClass, EOPERATION_EEXCEPTIONS);
	createEReference(eOperationEClass, EOPERATION_EGENERICEXCEPTIONS);
	createEReference(eOperationEClass, EOPERATION_EPARAMETERS);
	createEReference(eOperationEClass, EOPERATION_ETYPEPARAMETERS);
	
	createEOperation(eOperationEClass, EOPERATION___ISOVERRIDEOF__EOPERATION);
	

	ePackageEClass = createEClass(EPACKAGE);
	createEAttribute(ePackageEClass, EPACKAGE_NSPREFIX);createEAttribute(ePackageEClass, EPACKAGE_NSURI);
	createEReference(ePackageEClass, EPACKAGE_ECLASSIFIERS);
	createEReference(ePackageEClass, EPACKAGE_EFACTORYINSTANCE);
	createEReference(ePackageEClass, EPACKAGE_ESUBPACKAGES);
	createEReference(ePackageEClass, EPACKAGE_ESUPERPACKAGE);
	
	createEOperation(ePackageEClass, EPACKAGE___GETECLASSIFIER__ESTRING);
	

	eParameterEClass = createEClass(EPARAMETER);
	
	createEReference(eParameterEClass, EPARAMETER_EOPERATION);
	
	

	eReferenceEClass = createEClass(EREFERENCE);
	createEAttribute(eReferenceEClass, EREFERENCE_CONTAINER);createEAttribute(eReferenceEClass, EREFERENCE_CONTAINMENT);createEAttribute(eReferenceEClass, EREFERENCE_RESOLVEPROXIES);
	createEReference(eReferenceEClass, EREFERENCE_EKEYS);
	createEReference(eReferenceEClass, EREFERENCE_EOPPOSITE);
	createEReference(eReferenceEClass, EREFERENCE_EREFERENCETYPE);
	
	

	eStringToStringMapEntryEClass = createEClass(ESTRINGTOSTRINGMAPENTRY);
	createEAttribute(eStringToStringMapEntryEClass, ESTRINGTOSTRINGMAPENTRY_KEY);createEAttribute(eStringToStringMapEntryEClass, ESTRINGTOSTRINGMAPENTRY_VALUE);
	
	

	eStructuralFeatureEClass = createEClass(ESTRUCTURALFEATURE);
	createEAttribute(eStructuralFeatureEClass, ESTRUCTURALFEATURE_CHANGEABLE);createEAttribute(eStructuralFeatureEClass, ESTRUCTURALFEATURE_CONTAINERCLASS);createEAttribute(eStructuralFeatureEClass, ESTRUCTURALFEATURE_DEFAULTVALUE);createEAttribute(eStructuralFeatureEClass, ESTRUCTURALFEATURE_DEFAULTVALUELITERAL);createEAttribute(eStructuralFeatureEClass, ESTRUCTURALFEATURE_DERIVED);createEAttribute(eStructuralFeatureEClass, ESTRUCTURALFEATURE_FEATUREID);createEAttribute(eStructuralFeatureEClass, ESTRUCTURALFEATURE_TRANSIENT);createEAttribute(eStructuralFeatureEClass, ESTRUCTURALFEATURE_UNSETTABLE);createEAttribute(eStructuralFeatureEClass, ESTRUCTURALFEATURE_VOLATILE);
	createEReference(eStructuralFeatureEClass, ESTRUCTURALFEATURE_ECONTAININGCLASS);
	
	

	eTypeParameterEClass = createEClass(ETYPEPARAMETER);
	
	createEReference(eTypeParameterEClass, ETYPEPARAMETER_EBOUNDS);
	
	

	eTypedElementEClass = createEClass(ETYPEDELEMENT);
	createEAttribute(eTypedElementEClass, ETYPEDELEMENT_LOWERBOUND);createEAttribute(eTypedElementEClass, ETYPEDELEMENT_MANY);createEAttribute(eTypedElementEClass, ETYPEDELEMENT_ORDERED);createEAttribute(eTypedElementEClass, ETYPEDELEMENT_REQUIRED);createEAttribute(eTypedElementEClass, ETYPEDELEMENT_UNIQUE);createEAttribute(eTypedElementEClass, ETYPEDELEMENT_UPPERBOUND);
	createEReference(eTypedElementEClass, ETYPEDELEMENT_EGENERICTYPE);
	createEReference(eTypedElementEClass, ETYPEDELEMENT_ETYPE);
	
	

	eBigDecimalEDataType = createEDataType(EBIGDECIMAL);
	eBigIntegerEDataType = createEDataType(EBIGINTEGER);
	eBooleanEDataType = createEDataType(EBOOLEAN);
	eBooleanObjectEDataType = createEDataType(EBOOLEANOBJECT);
	eByteEDataType = createEDataType(EBYTE);
	eByteArrayEDataType = createEDataType(EBYTEARRAY);
	eByteObjectEDataType = createEDataType(EBYTEOBJECT);
	eCharEDataType = createEDataType(ECHAR);
	eCharacterObjectEDataType = createEDataType(ECHARACTEROBJECT);
	eDateEDataType = createEDataType(EDATE);
	eDiagnosticChainEDataType = createEDataType(EDIAGNOSTICCHAIN);
	eDoubleEDataType = createEDataType(EDOUBLE);
	eDoubleObjectEDataType = createEDataType(EDOUBLEOBJECT);
	eEListEDataType = createEDataType(EELIST);
	eEnumeratorEDataType = createEDataType(EENUMERATOR);
	eFeatureMapEDataType = createEDataType(EFEATUREMAP);
	eFeatureMapEntryEDataType = createEDataType(EFEATUREMAPENTRY);
	eFloatEDataType = createEDataType(EFLOAT);
	eFloatObjectEDataType = createEDataType(EFLOATOBJECT);
	eIntEDataType = createEDataType(EINT);
	eIntegerObjectEDataType = createEDataType(EINTEGEROBJECT);
	eInvocationTargetExceptionEDataType = createEDataType(EINVOCATIONTARGETEXCEPTION);
	eJavaClassEDataType = createEDataType(EJAVACLASS);
	eJavaObjectEDataType = createEDataType(EJAVAOBJECT);
	eLongEDataType = createEDataType(ELONG);
	eLongObjectEDataType = createEDataType(ELONGOBJECT);
	eMapEDataType = createEDataType(EMAP);
	eResourceEDataType = createEDataType(ERESOURCE);
	eResourceSetEDataType = createEDataType(ERESOURCESET);
	eShortEDataType = createEDataType(ESHORT);
	eShortObjectEDataType = createEDataType(ESHORTOBJECT);
	eStringEDataType = createEDataType(ESTRING);
	eTreeIteratorEDataType = createEDataType(ETREEITERATOR);
	
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
	
	EOperation *  op;

 	// Initialize classes and features; add operations and parameters
	// Begin Class EAnnotation
	initEClass(eAnnotationEClass, nullptr, "EAnnotation", false, false, true);
	initEAttribute(getEAnnotation_Source(),getEString(),"source","",0,1, nullptr, false,false, true, false, false, true, false, true);
	initEReference(getEAnnotation_Contents(),getEObject(),nullptr,"contents","",0,-1, nullptr , false,false, true, true, false, false, true, false,true);
	initEReference(getEAnnotation_Details(),getEStringToStringMapEntry(),nullptr,"details","",0,-1, nullptr , false,false, true, true, false, false, true, false,true);
	initEReference(getEAnnotation_EModelElement(),getEModelElement(),getEModelElement_EAnnotations(),"eModelElement","",0,1, nullptr , true,false, true, false, false, false, true, false,true);
	initEReference(getEAnnotation_References(),getEObject(),nullptr,"references","",0,-1, nullptr , false,false, true, false, true, false, true, false,true);
	
	
	// End Class EAnnotation

	// Begin Class EAttribute
	initEClass(eAttributeEClass, nullptr, "EAttribute", false, false, true);
	initEAttribute(getEAttribute_ID(),getEBoolean(),"iD","",0,1, nullptr, false,false, true, false, false, true, false, true);
	initEReference(getEAttribute_EAttributeType(),getEDataType(),nullptr,"eAttributeType","",1,1, nullptr , true,true, false, false, true, false, true, true,true);
	
	
	// End Class EAttribute

	// Begin Class EClass
	initEClass(eClassEClass, nullptr, "EClass", false, false, true);
	initEAttribute(getEClass_Abstract(),getEBoolean(),"abstract","",0,1, nullptr, false,false, true, false, false, true, false, true);initEAttribute(getEClass_Interface(),getEBoolean(),"interface","",0,1, nullptr, false,false, true, false, false, true, false, true);
	initEReference(getEClass_EAllAttributes(),getEAttribute(),nullptr,"eAllAttributes","",0,-1, nullptr , true,true, false, false, true, false, true, true,true);
	initEReference(getEClass_EAllContainments(),getEReference(),nullptr,"eAllContainments","",0,-1, nullptr , true,true, false, false, true, false, true, true,true);
	initEReference(getEClass_EAllGenericSuperTypes(),getEGenericType(),nullptr,"eAllGenericSuperTypes","",0,-1, nullptr , true,true, false, false, true, false, true, true,true);
	initEReference(getEClass_EAllOperations(),getEOperation(),nullptr,"eAllOperations","",0,-1, nullptr , true,true, false, false, true, false, true, true,true);
	initEReference(getEClass_EAllReferences(),getEReference(),nullptr,"eAllReferences","",0,-1, nullptr , true,true, false, false, true, false, true, true,true);
	initEReference(getEClass_EAllStructuralFeatures(),getEStructuralFeature(),nullptr,"eAllStructuralFeatures","",0,-1, nullptr , true,true, false, false, true, false, true, true,true);
	initEReference(getEClass_EAllSuperTypes(),getEClass(),nullptr,"eAllSuperTypes","",0,-1, nullptr , true,true, false, false, true, false, true, true,true);
	initEReference(getEClass_EAttributes(),getEAttribute(),nullptr,"eAttributes","",0,-1, nullptr , true,true, false, false, true, false, true, true,true);
	initEReference(getEClass_EGenericSuperTypes(),getEGenericType(),nullptr,"eGenericSuperTypes","",0,-1, nullptr , false,false, true, true, false, true, true, false,true);
	initEReference(getEClass_EIDAttribute(),getEAttribute(),nullptr,"eIDAttribute","",0,1, nullptr , true,true, false, false, false, false, true, true,true);
	initEReference(getEClass_EOperations(),getEOperation(),getEOperation_EContainingClass(),"eOperations","",0,-1, nullptr , false,false, true, true, false, false, true, false,true);
	initEReference(getEClass_EReferences(),getEReference(),nullptr,"eReferences","",0,-1, nullptr , true,true, false, false, true, false, true, true,true);
	initEReference(getEClass_EStructuralFeatures(),getEStructuralFeature(),getEStructuralFeature_EContainingClass(),"eStructuralFeatures","",0,-1, nullptr , false,false, true, true, false, false, true, false,true);
	initEReference(getEClass_ESuperTypes(),getEClass(),nullptr,"eSuperTypes","",0,-1, nullptr , false,false, true, false, true, true, true, false,true);
	
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
	initEAttribute(getEClassifier_ClassifierID(),getEInt(),"classifierID","-1",0,1, nullptr, false,false, false, false, false, true, false, true);initEAttribute(getEClassifier_DefaultValue(),getEJavaObject(),"defaultValue","",0,1, nullptr, true,true, false, false, false, true, true, true);initEAttribute(getEClassifier_InstanceClass(),getEJavaClass(),"instanceClass","",0,1, nullptr, true,true, true, false, false, true, false, true);initEAttribute(getEClassifier_InstanceClassName(),getEString(),"instanceClassName","",0,1, nullptr, false,true, true, true, false, true, false, true);initEAttribute(getEClassifier_InstanceTypeName(),getEString(),"instanceTypeName","",0,1, nullptr, false,true, true, true, false, true, false, true);
	initEReference(getEClassifier_EPackage(),getEPackage(),getEPackage_EClassifiers(),"ePackage","",0,1, nullptr , true,false, true, false, true, false, true, false,true);
	initEReference(getEClassifier_ETypeParameters(),getETypeParameter(),nullptr,"eTypeParameters","",0,-1, nullptr , false,false, true, true, true, false, true, false,true);
	
	op = initEOperation(getEClassifier___IsInstance__EJavaObject(),getEBoolean(), "isInstance", 0, 1, true,true );
	addEParameter(op ,getEJavaObject()  , "object",0,1, true,true);
	
	
	// End Class EClassifier

	// Begin Class EDataType
	initEClass(eDataTypeEClass, nullptr, "EDataType", false, false, true);
	initEAttribute(getEDataType_Serializable(),getEBoolean(),"serializable","true",0,1, nullptr, false,false, true, false, false, true, false, true);
	
	
	// End Class EDataType

	// Begin Class EEnum
	initEClass(eEnumEClass, nullptr, "EEnum", false, false, true);
	
	initEReference(getEEnum_ELiterals(),getEEnumLiteral(),getEEnumLiteral_EEnum(),"eLiterals","",0,-1, nullptr , false,false, true, true, false, false, true, false,true);
	
	op = initEOperation(getEEnum___GetEEnumLiteral__EString(),getEEnumLiteral(), "getEEnumLiteral", 0, 1, true,true );
	addEParameter(op ,getEString()  , "name",0,1, true,true);
	
	op = initEOperation(getEEnum___GetEEnumLiteral__EInt(),getEEnumLiteral(), "getEEnumLiteral", 0, 1, true,true );
	addEParameter(op ,getEInt()  , "value",0,1, true,true);
	
	op = initEOperation(getEEnum___GetEEnumLiteralByLiteral__EString(),getEEnumLiteral(), "getEEnumLiteralByLiteral", 0, 1, true,true );
	addEParameter(op ,getEString()  , "literal",0,1, true,true);
	
	
	// End Class EEnum

	// Begin Class EEnumLiteral
	initEClass(eEnumLiteralEClass, nullptr, "EEnumLiteral", false, false, true);
	initEAttribute(getEEnumLiteral_Instance(),getEEnumerator(),"instance","",0,1, nullptr, true,false, true, false, false, true, false, true);initEAttribute(getEEnumLiteral_Literal(),getEString(),"literal","",0,1, nullptr, false,false, true, false, false, true, false, true);initEAttribute(getEEnumLiteral_Value(),getEInt(),"value","",0,1, nullptr, false,false, true, false, false, true, false, true);
	initEReference(getEEnumLiteral_EEnum(),getEEnum(),getEEnum_ELiterals(),"eEnum","",0,1, nullptr , true,false, false, false, false, false, true, false,true);
	
	
	// End Class EEnumLiteral

	// Begin Class EFactory
	initEClass(eFactoryEClass, nullptr, "EFactory", false, false, true);
	
	initEReference(getEFactory_EPackage(),getEPackage(),getEPackage_EFactoryInstance(),"ePackage","",1,1, nullptr , true,false, true, false, false, false, true, false,true);
	
	op = initEOperation(getEFactory___ConvertToString__EDataType_EJavaObject(),getEString(), "convertToString", 0, 1, true,true );
	addEParameter(op ,getEDataType()  , "eDataType",0,1, true,true);
	addEParameter(op ,getEJavaObject()  , "instanceValue",0,1, true,true);
	
	op = initEOperation(getEFactory___Create__EClass(),getEObject(), "create", 0, 1, true,true );
	addEParameter(op ,getEClass()  , "eClass",0,1, true,true);
	
	op = initEOperation(getEFactory___CreateFromString__EDataType_EString(),getEJavaObject(), "createFromString", 0, 1, true,true );
	addEParameter(op ,getEDataType()  , "eDataType",0,1, true,true);
	addEParameter(op ,getEString()  , "literalValue",0,1, true,true);
	
	
	// End Class EFactory

	// Begin Class EGenericType
	initEClass(eGenericTypeEClass, nullptr, "EGenericType", false, false, true);
	
	initEReference(getEGenericType_EClassifier(),getEClassifier(),nullptr,"eClassifier","",0,1, nullptr , false,false, true, false, true, false, true, false,true);
	initEReference(getEGenericType_ELowerBound(),getEGenericType(),nullptr,"eLowerBound","",0,1, nullptr , false,false, true, true, false, false, true, false,true);
	initEReference(getEGenericType_ERawType(),getEClassifier(),nullptr,"eRawType","",1,1, nullptr , true,false, false, false, true, false, true, true,true);
	initEReference(getEGenericType_ETypeArguments(),getEGenericType(),nullptr,"eTypeArguments","",0,-1, nullptr , false,false, true, true, false, false, true, false,true);
	initEReference(getEGenericType_ETypeParameter(),getETypeParameter(),nullptr,"eTypeParameter","",0,1, nullptr , false,false, true, false, false, false, true, false,true);
	initEReference(getEGenericType_EUpperBound(),getEGenericType(),nullptr,"eUpperBound","",0,1, nullptr , false,false, true, true, false, false, true, false,true);
	
	op = initEOperation(getEGenericType___IsInstance__EJavaObject(),getEBoolean(), "isInstance", 0, 1, true,true );
	addEParameter(op ,getEJavaObject()  , "object",0,1, true,true);
	
	
	// End Class EGenericType

	// Begin Class EModelElement
	initEClass(eModelElementEClass, nullptr, "EModelElement", true, false, true);
	
	initEReference(getEModelElement_EAnnotations(),getEAnnotation(),getEAnnotation_EModelElement(),"eAnnotations","",0,-1, nullptr , false,false, true, true, false, false, true, false,true);
	
	op = initEOperation(getEModelElement___GetEAnnotation__EString(),getEAnnotation(), "getEAnnotation", 0, 1, true,true );
	addEParameter(op ,getEString()  , "source",0,1, true,true);
	
	
	// End Class EModelElement

	// Begin Class ENamedElement
	initEClass(eNamedElementEClass, nullptr, "ENamedElement", true, false, true);
	initEAttribute(getENamedElement_Name(),getEString(),"name","",0,1, nullptr, false,false, true, false, false, true, false, true);
	
	
	// End Class ENamedElement

	// Begin Class EObject
	initEClass(eObjectEClass, nullptr, "EObject", false, false, true);
	
	initEReference(getEObject_EContainer(),getEObject(),nullptr,"eContainer","",0,1, nullptr , false,false, true, false, true, false, true, false,true);
	
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
	initEAttribute(getEOperation_OperationID(),getEInt(),"operationID","-1",0,1, nullptr, false,false, false, false, false, true, false, true);
	initEReference(getEOperation_EContainingClass(),getEClass(),getEClass_EOperations(),"eContainingClass","",0,1, nullptr , true,false, false, false, false, false, true, false,true);
	initEReference(getEOperation_EExceptions(),getEClassifier(),nullptr,"eExceptions","",0,-1, nullptr , false,false, true, false, true, true, true, false,true);
	initEReference(getEOperation_EGenericExceptions(),getEGenericType(),nullptr,"eGenericExceptions","",0,-1, nullptr , false,false, true, true, false, true, true, false,true);
	initEReference(getEOperation_EParameters(),getEParameter(),getEParameter_EOperation(),"eParameters","",0,-1, nullptr , false,false, true, true, false, false, true, false,true);
	initEReference(getEOperation_ETypeParameters(),getETypeParameter(),nullptr,"eTypeParameters","",0,-1, nullptr , false,false, true, true, true, false, true, false,true);
	
	op = initEOperation(getEOperation___IsOverrideOf__EOperation(),getEBoolean(), "isOverrideOf", 0, 1, true,true );
	addEParameter(op ,getEOperation()  , "someOperation",0,1, true,true);
	
	
	// End Class EOperation

	// Begin Class EPackage
	initEClass(ePackageEClass, nullptr, "EPackage", false, false, true);
	initEAttribute(getEPackage_NsPrefix(),getEString(),"nsPrefix","",0,1, nullptr, false,false, true, false, false, true, false, true);initEAttribute(getEPackage_NsURI(),getEString(),"nsURI","",0,1, nullptr, false,false, true, false, false, true, false, true);
	initEReference(getEPackage_EClassifiers(),getEClassifier(),getEClassifier_EPackage(),"eClassifiers","",0,-1, nullptr , false,false, true, true, true, false, true, false,true);
	initEReference(getEPackage_EFactoryInstance(),getEFactory(),getEFactory_EPackage(),"eFactoryInstance","",1,1, nullptr , true,false, true, false, false, false, true, false,true);
	initEReference(getEPackage_ESubpackages(),getEPackage(),getEPackage_ESuperPackage(),"eSubpackages","",0,-1, nullptr , false,false, true, true, true, false, true, false,true);
	initEReference(getEPackage_ESuperPackage(),getEPackage(),getEPackage_ESubpackages(),"eSuperPackage","",0,1, nullptr , true,false, false, false, true, false, true, false,true);
	
	op = initEOperation(getEPackage___GetEClassifier__EString(),getEClassifier(), "getEClassifier", 0, 1, true,true );
	addEParameter(op ,getEString()  , "name",0,1, true,true);
	
	
	// End Class EPackage

	// Begin Class EParameter
	initEClass(eParameterEClass, nullptr, "EParameter", false, false, true);
	
	initEReference(getEParameter_EOperation(),getEOperation(),getEOperation_EParameters(),"eOperation","",0,1, nullptr , true,false, false, false, false, false, true, false,true);
	
	
	// End Class EParameter

	// Begin Class EReference
	initEClass(eReferenceEClass, nullptr, "EReference", false, false, true);
	initEAttribute(getEReference_Container(),getEBoolean(),"container","",0,1, nullptr, true,true, false, false, false, true, true, true);initEAttribute(getEReference_Containment(),getEBoolean(),"containment","",0,1, nullptr, false,false, true, false, false, true, false, true);initEAttribute(getEReference_ResolveProxies(),getEBoolean(),"resolveProxies","true",0,1, nullptr, false,false, true, false, false, true, false, true);
	initEReference(getEReference_EKeys(),getEAttribute(),nullptr,"eKeys","",0,-1, nullptr , false,false, true, false, true, false, true, false,true);
	initEReference(getEReference_EOpposite(),getEReference(),nullptr,"eOpposite","",0,1, nullptr , false,false, true, false, true, false, true, false,true);
	initEReference(getEReference_EReferenceType(),getEClass(),nullptr,"eReferenceType","",1,1, nullptr , true,true, false, false, true, false, true, true,true);
	
	
	// End Class EReference

	// Begin Class EStringToStringMapEntry
	initEClass(eStringToStringMapEntryEClass, nullptr, "EStringToStringMapEntry", false, false, true);
	initEAttribute(getEStringToStringMapEntry_Key(),getEString(),"key","",0,1, nullptr, false,false, true, false, false, true, false, true);initEAttribute(getEStringToStringMapEntry_Value(),getEString(),"value","",0,1, nullptr, false,false, true, false, false, true, false, true);
	
	
	// End Class EStringToStringMapEntry

	// Begin Class EStructuralFeature
	initEClass(eStructuralFeatureEClass, nullptr, "EStructuralFeature", true, false, true);
	initEAttribute(getEStructuralFeature_Changeable(),getEBoolean(),"changeable","true",0,1, nullptr, false,false, true, false, false, true, false, true);initEAttribute(getEStructuralFeature_ContainerClass(),getEJavaClass(),"containerClass","",0,1, nullptr, false,false, false, false, false, true, false, true);initEAttribute(getEStructuralFeature_DefaultValue(),getEJavaObject(),"defaultValue","",0,1, nullptr, true,true, false, false, false, true, true, true);initEAttribute(getEStructuralFeature_DefaultValueLiteral(),getEString(),"defaultValueLiteral","",0,1, nullptr, false,false, true, false, false, true, false, true);initEAttribute(getEStructuralFeature_Derived(),getEBoolean(),"derived","",0,1, nullptr, false,false, true, false, false, true, false, true);initEAttribute(getEStructuralFeature_FeatureID(),getEInt(),"featureID","-1",0,1, nullptr, false,false, false, false, false, true, false, true);initEAttribute(getEStructuralFeature_Transient(),getEBoolean(),"transient","",0,1, nullptr, false,false, true, false, false, true, false, true);initEAttribute(getEStructuralFeature_Unsettable(),getEBoolean(),"unsettable","",0,1, nullptr, false,false, true, false, false, true, false, true);initEAttribute(getEStructuralFeature_Volatile(),getEBoolean(),"volatile","",0,1, nullptr, false,false, true, false, false, true, false, true);
	initEReference(getEStructuralFeature_EContainingClass(),getEClass(),getEClass_EStructuralFeatures(),"eContainingClass","",0,1, nullptr , true,false, false, false, false, false, true, false,true);
	
	
	// End Class EStructuralFeature

	// Begin Class ETypeParameter
	initEClass(eTypeParameterEClass, nullptr, "ETypeParameter", false, false, true);
	
	initEReference(getETypeParameter_EBounds(),getEGenericType(),nullptr,"eBounds","",0,-1, nullptr , false,false, true, true, false, false, true, false,true);
	
	
	// End Class ETypeParameter

	// Begin Class ETypedElement
	initEClass(eTypedElementEClass, nullptr, "ETypedElement", true, false, true);
	initEAttribute(getETypedElement_LowerBound(),getEInt(),"lowerBound","",0,1, nullptr, false,false, true, false, false, true, false, true);initEAttribute(getETypedElement_Many(),getEBoolean(),"many","",0,1, nullptr, true,true, false, false, false, true, true, true);initEAttribute(getETypedElement_Ordered(),getEBoolean(),"ordered","true",0,1, nullptr, false,false, true, false, false, true, false, true);initEAttribute(getETypedElement_Required(),getEBoolean(),"required","",0,1, nullptr, true,true, false, false, false, true, true, true);initEAttribute(getETypedElement_Unique(),getEBoolean(),"unique","true",0,1, nullptr, false,false, true, false, false, true, false, true);initEAttribute(getETypedElement_UpperBound(),getEInt(),"upperBound","1",0,1, nullptr, false,false, true, false, false, true, false, true);
	initEReference(getETypedElement_EGenericType(),getEGenericType(),nullptr,"eGenericType","",0,1, nullptr , false,true, true, true, false, true, true, false,true);
	initEReference(getETypedElement_EType(),getEClassifier(),nullptr,"eType","",0,1, nullptr , false,true, true, false, true, true, true, false,true);
	
	
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
ecore::EClass* EcorePackageImpl::getEAnnotation() const
{
	return eAnnotationEClass;
}
ecore::EAttribute* EcorePackageImpl::getEAnnotation_Source() const
{
	return dynamic_cast<ecore::EAttribute*>(eAnnotationEClass->getEStructuralFeatures()->at(0));
}

ecore::EReference* EcorePackageImpl::getEAnnotation_Contents() const
{
	return dynamic_cast<ecore::EReference*>(eAnnotationEClass->getEStructuralFeatures()->at(3));
}
ecore::EReference* EcorePackageImpl::getEAnnotation_Details() const
{
	return dynamic_cast<ecore::EReference*>(eAnnotationEClass->getEStructuralFeatures()->at(1));
}
ecore::EReference* EcorePackageImpl::getEAnnotation_EModelElement() const
{
	return dynamic_cast<ecore::EReference*>(eAnnotationEClass->getEStructuralFeatures()->at(2));
}
ecore::EReference* EcorePackageImpl::getEAnnotation_References() const
{
	return dynamic_cast<ecore::EReference*>(eAnnotationEClass->getEStructuralFeatures()->at(4));
}


// End Class EAnnotation

// Begin Class EAttribute
ecore::EClass* EcorePackageImpl::getEAttribute() const
{
	return eAttributeEClass;
}
ecore::EAttribute* EcorePackageImpl::getEAttribute_ID() const
{
	return dynamic_cast<ecore::EAttribute*>(eAttributeEClass->getEStructuralFeatures()->at(0));
}

ecore::EReference* EcorePackageImpl::getEAttribute_EAttributeType() const
{
	return dynamic_cast<ecore::EReference*>(eAttributeEClass->getEStructuralFeatures()->at(1));
}


// End Class EAttribute

// Begin Class EClass
ecore::EClass* EcorePackageImpl::getEClass() const
{
	return eClassEClass;
}
ecore::EAttribute* EcorePackageImpl::getEClass_Abstract() const
{
	return dynamic_cast<ecore::EAttribute*>(eClassEClass->getEStructuralFeatures()->at(0));
}
ecore::EAttribute* EcorePackageImpl::getEClass_Interface() const
{
	return dynamic_cast<ecore::EAttribute*>(eClassEClass->getEStructuralFeatures()->at(1));
}

ecore::EReference* EcorePackageImpl::getEClass_EAllAttributes() const
{
	return dynamic_cast<ecore::EReference*>(eClassEClass->getEStructuralFeatures()->at(4));
}
ecore::EReference* EcorePackageImpl::getEClass_EAllContainments() const
{
	return dynamic_cast<ecore::EReference*>(eClassEClass->getEStructuralFeatures()->at(8));
}
ecore::EReference* EcorePackageImpl::getEClass_EAllGenericSuperTypes() const
{
	return dynamic_cast<ecore::EReference*>(eClassEClass->getEStructuralFeatures()->at(15));
}
ecore::EReference* EcorePackageImpl::getEClass_EAllOperations() const
{
	return dynamic_cast<ecore::EReference*>(eClassEClass->getEStructuralFeatures()->at(9));
}
ecore::EReference* EcorePackageImpl::getEClass_EAllReferences() const
{
	return dynamic_cast<ecore::EReference*>(eClassEClass->getEStructuralFeatures()->at(5));
}
ecore::EReference* EcorePackageImpl::getEClass_EAllStructuralFeatures() const
{
	return dynamic_cast<ecore::EReference*>(eClassEClass->getEStructuralFeatures()->at(10));
}
ecore::EReference* EcorePackageImpl::getEClass_EAllSuperTypes() const
{
	return dynamic_cast<ecore::EReference*>(eClassEClass->getEStructuralFeatures()->at(11));
}
ecore::EReference* EcorePackageImpl::getEClass_EAttributes() const
{
	return dynamic_cast<ecore::EReference*>(eClassEClass->getEStructuralFeatures()->at(7));
}
ecore::EReference* EcorePackageImpl::getEClass_EGenericSuperTypes() const
{
	return dynamic_cast<ecore::EReference*>(eClassEClass->getEStructuralFeatures()->at(14));
}
ecore::EReference* EcorePackageImpl::getEClass_EIDAttribute() const
{
	return dynamic_cast<ecore::EReference*>(eClassEClass->getEStructuralFeatures()->at(12));
}
ecore::EReference* EcorePackageImpl::getEClass_EOperations() const
{
	return dynamic_cast<ecore::EReference*>(eClassEClass->getEStructuralFeatures()->at(3));
}
ecore::EReference* EcorePackageImpl::getEClass_EReferences() const
{
	return dynamic_cast<ecore::EReference*>(eClassEClass->getEStructuralFeatures()->at(6));
}
ecore::EReference* EcorePackageImpl::getEClass_EStructuralFeatures() const
{
	return dynamic_cast<ecore::EReference*>(eClassEClass->getEStructuralFeatures()->at(13));
}
ecore::EReference* EcorePackageImpl::getEClass_ESuperTypes() const
{
	return dynamic_cast<ecore::EReference*>(eClassEClass->getEStructuralFeatures()->at(2));
}

ecore::EOperation* EcorePackageImpl::getEClass___GetEOperation__EInt() const
{
	return dynamic_cast<ecore::EOperation*>(eClassEClass->getEOperations()->at(6));
}
ecore::EOperation* EcorePackageImpl::getEClass___GetEStructuralFeature__EInt() const
{
	return dynamic_cast<ecore::EOperation*>(eClassEClass->getEOperations()->at(2));
}
ecore::EOperation* EcorePackageImpl::getEClass___GetEStructuralFeature__EString() const
{
	return dynamic_cast<ecore::EOperation*>(eClassEClass->getEOperations()->at(4));
}
ecore::EOperation* EcorePackageImpl::getEClass___GetFeatureCount() const
{
	return dynamic_cast<ecore::EOperation*>(eClassEClass->getEOperations()->at(1));
}
ecore::EOperation* EcorePackageImpl::getEClass___GetFeatureID__EStructuralFeature() const
{
	return dynamic_cast<ecore::EOperation*>(eClassEClass->getEOperations()->at(3));
}
ecore::EOperation* EcorePackageImpl::getEClass___GetFeatureType__EStructuralFeature() const
{
	return dynamic_cast<ecore::EOperation*>(eClassEClass->getEOperations()->at(9));
}
ecore::EOperation* EcorePackageImpl::getEClass___GetOperationCount() const
{
	return dynamic_cast<ecore::EOperation*>(eClassEClass->getEOperations()->at(5));
}
ecore::EOperation* EcorePackageImpl::getEClass___GetOperationID__EOperation() const
{
	return dynamic_cast<ecore::EOperation*>(eClassEClass->getEOperations()->at(7));
}
ecore::EOperation* EcorePackageImpl::getEClass___GetOverride__EOperation() const
{
	return dynamic_cast<ecore::EOperation*>(eClassEClass->getEOperations()->at(8));
}
ecore::EOperation* EcorePackageImpl::getEClass___IsSuperTypeOf__EClass() const
{
	return dynamic_cast<ecore::EOperation*>(eClassEClass->getEOperations()->at(0));
}

// End Class EClass

// Begin Class EClassifier
ecore::EClass* EcorePackageImpl::getEClassifier() const
{
	return eClassifierEClass;
}
ecore::EAttribute* EcorePackageImpl::getEClassifier_ClassifierID() const
{
	return dynamic_cast<ecore::EAttribute*>(eClassifierEClass->getEStructuralFeatures()->at(3));
}
ecore::EAttribute* EcorePackageImpl::getEClassifier_DefaultValue() const
{
	return dynamic_cast<ecore::EAttribute*>(eClassifierEClass->getEStructuralFeatures()->at(2));
}
ecore::EAttribute* EcorePackageImpl::getEClassifier_InstanceClass() const
{
	return dynamic_cast<ecore::EAttribute*>(eClassifierEClass->getEStructuralFeatures()->at(1));
}
ecore::EAttribute* EcorePackageImpl::getEClassifier_InstanceClassName() const
{
	return dynamic_cast<ecore::EAttribute*>(eClassifierEClass->getEStructuralFeatures()->at(0));
}
ecore::EAttribute* EcorePackageImpl::getEClassifier_InstanceTypeName() const
{
	return dynamic_cast<ecore::EAttribute*>(eClassifierEClass->getEStructuralFeatures()->at(4));
}

ecore::EReference* EcorePackageImpl::getEClassifier_EPackage() const
{
	return dynamic_cast<ecore::EReference*>(eClassifierEClass->getEStructuralFeatures()->at(5));
}
ecore::EReference* EcorePackageImpl::getEClassifier_ETypeParameters() const
{
	return dynamic_cast<ecore::EReference*>(eClassifierEClass->getEStructuralFeatures()->at(6));
}

ecore::EOperation* EcorePackageImpl::getEClassifier___IsInstance__EJavaObject() const
{
	return dynamic_cast<ecore::EOperation*>(eClassifierEClass->getEOperations()->at(0));
}

// End Class EClassifier

// Begin Class EDataType
ecore::EClass* EcorePackageImpl::getEDataType() const
{
	return eDataTypeEClass;
}
ecore::EAttribute* EcorePackageImpl::getEDataType_Serializable() const
{
	return dynamic_cast<ecore::EAttribute*>(eDataTypeEClass->getEStructuralFeatures()->at(0));
}



// End Class EDataType

// Begin Class EEnum
ecore::EClass* EcorePackageImpl::getEEnum() const
{
	return eEnumEClass;
}

ecore::EReference* EcorePackageImpl::getEEnum_ELiterals() const
{
	return dynamic_cast<ecore::EReference*>(eEnumEClass->getEStructuralFeatures()->at(0));
}

ecore::EOperation* EcorePackageImpl::getEEnum___GetEEnumLiteral__EString() const
{
	return dynamic_cast<ecore::EOperation*>(eEnumEClass->getEOperations()->at(0));
}
ecore::EOperation* EcorePackageImpl::getEEnum___GetEEnumLiteral__EInt() const
{
	return dynamic_cast<ecore::EOperation*>(eEnumEClass->getEOperations()->at(1));
}
ecore::EOperation* EcorePackageImpl::getEEnum___GetEEnumLiteralByLiteral__EString() const
{
	return dynamic_cast<ecore::EOperation*>(eEnumEClass->getEOperations()->at(2));
}

// End Class EEnum

// Begin Class EEnumLiteral
ecore::EClass* EcorePackageImpl::getEEnumLiteral() const
{
	return eEnumLiteralEClass;
}
ecore::EAttribute* EcorePackageImpl::getEEnumLiteral_Instance() const
{
	return dynamic_cast<ecore::EAttribute*>(eEnumLiteralEClass->getEStructuralFeatures()->at(1));
}
ecore::EAttribute* EcorePackageImpl::getEEnumLiteral_Literal() const
{
	return dynamic_cast<ecore::EAttribute*>(eEnumLiteralEClass->getEStructuralFeatures()->at(2));
}
ecore::EAttribute* EcorePackageImpl::getEEnumLiteral_Value() const
{
	return dynamic_cast<ecore::EAttribute*>(eEnumLiteralEClass->getEStructuralFeatures()->at(0));
}

ecore::EReference* EcorePackageImpl::getEEnumLiteral_EEnum() const
{
	return dynamic_cast<ecore::EReference*>(eEnumLiteralEClass->getEStructuralFeatures()->at(3));
}


// End Class EEnumLiteral

// Begin Class EFactory
ecore::EClass* EcorePackageImpl::getEFactory() const
{
	return eFactoryEClass;
}

ecore::EReference* EcorePackageImpl::getEFactory_EPackage() const
{
	return dynamic_cast<ecore::EReference*>(eFactoryEClass->getEStructuralFeatures()->at(0));
}

ecore::EOperation* EcorePackageImpl::getEFactory___ConvertToString__EDataType_EJavaObject() const
{
	return dynamic_cast<ecore::EOperation*>(eFactoryEClass->getEOperations()->at(2));
}
ecore::EOperation* EcorePackageImpl::getEFactory___Create__EClass() const
{
	return dynamic_cast<ecore::EOperation*>(eFactoryEClass->getEOperations()->at(0));
}
ecore::EOperation* EcorePackageImpl::getEFactory___CreateFromString__EDataType_EString() const
{
	return dynamic_cast<ecore::EOperation*>(eFactoryEClass->getEOperations()->at(1));
}

// End Class EFactory

// Begin Class EGenericType
ecore::EClass* EcorePackageImpl::getEGenericType() const
{
	return eGenericTypeEClass;
}

ecore::EReference* EcorePackageImpl::getEGenericType_EClassifier() const
{
	return dynamic_cast<ecore::EReference*>(eGenericTypeEClass->getEStructuralFeatures()->at(5));
}
ecore::EReference* EcorePackageImpl::getEGenericType_ELowerBound() const
{
	return dynamic_cast<ecore::EReference*>(eGenericTypeEClass->getEStructuralFeatures()->at(3));
}
ecore::EReference* EcorePackageImpl::getEGenericType_ERawType() const
{
	return dynamic_cast<ecore::EReference*>(eGenericTypeEClass->getEStructuralFeatures()->at(2));
}
ecore::EReference* EcorePackageImpl::getEGenericType_ETypeArguments() const
{
	return dynamic_cast<ecore::EReference*>(eGenericTypeEClass->getEStructuralFeatures()->at(1));
}
ecore::EReference* EcorePackageImpl::getEGenericType_ETypeParameter() const
{
	return dynamic_cast<ecore::EReference*>(eGenericTypeEClass->getEStructuralFeatures()->at(4));
}
ecore::EReference* EcorePackageImpl::getEGenericType_EUpperBound() const
{
	return dynamic_cast<ecore::EReference*>(eGenericTypeEClass->getEStructuralFeatures()->at(0));
}

ecore::EOperation* EcorePackageImpl::getEGenericType___IsInstance__EJavaObject() const
{
	return dynamic_cast<ecore::EOperation*>(eGenericTypeEClass->getEOperations()->at(0));
}

// End Class EGenericType

// Begin Class EModelElement
ecore::EClass* EcorePackageImpl::getEModelElement() const
{
	return eModelElementEClass;
}

ecore::EReference* EcorePackageImpl::getEModelElement_EAnnotations() const
{
	return dynamic_cast<ecore::EReference*>(eModelElementEClass->getEStructuralFeatures()->at(0));
}

ecore::EOperation* EcorePackageImpl::getEModelElement___GetEAnnotation__EString() const
{
	return dynamic_cast<ecore::EOperation*>(eModelElementEClass->getEOperations()->at(0));
}

// End Class EModelElement

// Begin Class ENamedElement
ecore::EClass* EcorePackageImpl::getENamedElement() const
{
	return eNamedElementEClass;
}
ecore::EAttribute* EcorePackageImpl::getENamedElement_Name() const
{
	return dynamic_cast<ecore::EAttribute*>(eNamedElementEClass->getEStructuralFeatures()->at(0));
}



// End Class ENamedElement

// Begin Class EObject
ecore::EClass* EcorePackageImpl::getEObject() const
{
	return eObjectEClass;
}

ecore::EReference* EcorePackageImpl::getEObject_EContainer() const
{
	return dynamic_cast<ecore::EReference*>(eObjectEClass->getEStructuralFeatures()->at(0));
}

ecore::EOperation* EcorePackageImpl::getEObject___EAllContents() const
{
	return dynamic_cast<ecore::EOperation*>(eObjectEClass->getEOperations()->at(6));
}
ecore::EOperation* EcorePackageImpl::getEObject___EClass() const
{
	return dynamic_cast<ecore::EOperation*>(eObjectEClass->getEOperations()->at(0));
}
ecore::EOperation* EcorePackageImpl::getEObject___EContainingFeature() const
{
	return dynamic_cast<ecore::EOperation*>(eObjectEClass->getEOperations()->at(3));
}
ecore::EOperation* EcorePackageImpl::getEObject___EContainmentFeature() const
{
	return dynamic_cast<ecore::EOperation*>(eObjectEClass->getEOperations()->at(4));
}
ecore::EOperation* EcorePackageImpl::getEObject___EContents() const
{
	return dynamic_cast<ecore::EOperation*>(eObjectEClass->getEOperations()->at(5));
}
ecore::EOperation* EcorePackageImpl::getEObject___ECrossReferences() const
{
	return dynamic_cast<ecore::EOperation*>(eObjectEClass->getEOperations()->at(7));
}
ecore::EOperation* EcorePackageImpl::getEObject___EGet__EStructuralFeature() const
{
	return dynamic_cast<ecore::EOperation*>(eObjectEClass->getEOperations()->at(8));
}
ecore::EOperation* EcorePackageImpl::getEObject___EGet__EStructuralFeature_EBoolean() const
{
	return dynamic_cast<ecore::EOperation*>(eObjectEClass->getEOperations()->at(9));
}
ecore::EOperation* EcorePackageImpl::getEObject___EInvoke__EOperation_EEList() const
{
	return dynamic_cast<ecore::EOperation*>(eObjectEClass->getEOperations()->at(13));
}
ecore::EOperation* EcorePackageImpl::getEObject___EIsProxy() const
{
	return dynamic_cast<ecore::EOperation*>(eObjectEClass->getEOperations()->at(1));
}
ecore::EOperation* EcorePackageImpl::getEObject___EIsSet__EStructuralFeature() const
{
	return dynamic_cast<ecore::EOperation*>(eObjectEClass->getEOperations()->at(11));
}
ecore::EOperation* EcorePackageImpl::getEObject___EResource() const
{
	return dynamic_cast<ecore::EOperation*>(eObjectEClass->getEOperations()->at(2));
}
ecore::EOperation* EcorePackageImpl::getEObject___ESet__EStructuralFeature_EJavaObject() const
{
	return dynamic_cast<ecore::EOperation*>(eObjectEClass->getEOperations()->at(10));
}
ecore::EOperation* EcorePackageImpl::getEObject___EUnset__EStructuralFeature() const
{
	return dynamic_cast<ecore::EOperation*>(eObjectEClass->getEOperations()->at(12));
}

// End Class EObject

// Begin Class EOperation
ecore::EClass* EcorePackageImpl::getEOperation() const
{
	return eOperationEClass;
}
ecore::EAttribute* EcorePackageImpl::getEOperation_OperationID() const
{
	return dynamic_cast<ecore::EAttribute*>(eOperationEClass->getEStructuralFeatures()->at(0));
}

ecore::EReference* EcorePackageImpl::getEOperation_EContainingClass() const
{
	return dynamic_cast<ecore::EReference*>(eOperationEClass->getEStructuralFeatures()->at(1));
}
ecore::EReference* EcorePackageImpl::getEOperation_EExceptions() const
{
	return dynamic_cast<ecore::EReference*>(eOperationEClass->getEStructuralFeatures()->at(4));
}
ecore::EReference* EcorePackageImpl::getEOperation_EGenericExceptions() const
{
	return dynamic_cast<ecore::EReference*>(eOperationEClass->getEStructuralFeatures()->at(5));
}
ecore::EReference* EcorePackageImpl::getEOperation_EParameters() const
{
	return dynamic_cast<ecore::EReference*>(eOperationEClass->getEStructuralFeatures()->at(3));
}
ecore::EReference* EcorePackageImpl::getEOperation_ETypeParameters() const
{
	return dynamic_cast<ecore::EReference*>(eOperationEClass->getEStructuralFeatures()->at(2));
}

ecore::EOperation* EcorePackageImpl::getEOperation___IsOverrideOf__EOperation() const
{
	return dynamic_cast<ecore::EOperation*>(eOperationEClass->getEOperations()->at(0));
}

// End Class EOperation

// Begin Class EPackage
ecore::EClass* EcorePackageImpl::getEPackage() const
{
	return ePackageEClass;
}
ecore::EAttribute* EcorePackageImpl::getEPackage_NsPrefix() const
{
	return dynamic_cast<ecore::EAttribute*>(ePackageEClass->getEStructuralFeatures()->at(1));
}
ecore::EAttribute* EcorePackageImpl::getEPackage_NsURI() const
{
	return dynamic_cast<ecore::EAttribute*>(ePackageEClass->getEStructuralFeatures()->at(0));
}

ecore::EReference* EcorePackageImpl::getEPackage_EClassifiers() const
{
	return dynamic_cast<ecore::EReference*>(ePackageEClass->getEStructuralFeatures()->at(3));
}
ecore::EReference* EcorePackageImpl::getEPackage_EFactoryInstance() const
{
	return dynamic_cast<ecore::EReference*>(ePackageEClass->getEStructuralFeatures()->at(2));
}
ecore::EReference* EcorePackageImpl::getEPackage_ESubpackages() const
{
	return dynamic_cast<ecore::EReference*>(ePackageEClass->getEStructuralFeatures()->at(4));
}
ecore::EReference* EcorePackageImpl::getEPackage_ESuperPackage() const
{
	return dynamic_cast<ecore::EReference*>(ePackageEClass->getEStructuralFeatures()->at(5));
}

ecore::EOperation* EcorePackageImpl::getEPackage___GetEClassifier__EString() const
{
	return dynamic_cast<ecore::EOperation*>(ePackageEClass->getEOperations()->at(0));
}

// End Class EPackage

// Begin Class EParameter
ecore::EClass* EcorePackageImpl::getEParameter() const
{
	return eParameterEClass;
}

ecore::EReference* EcorePackageImpl::getEParameter_EOperation() const
{
	return dynamic_cast<ecore::EReference*>(eParameterEClass->getEStructuralFeatures()->at(0));
}


// End Class EParameter

// Begin Class EReference
ecore::EClass* EcorePackageImpl::getEReference() const
{
	return eReferenceEClass;
}
ecore::EAttribute* EcorePackageImpl::getEReference_Container() const
{
	return dynamic_cast<ecore::EAttribute*>(eReferenceEClass->getEStructuralFeatures()->at(1));
}
ecore::EAttribute* EcorePackageImpl::getEReference_Containment() const
{
	return dynamic_cast<ecore::EAttribute*>(eReferenceEClass->getEStructuralFeatures()->at(0));
}
ecore::EAttribute* EcorePackageImpl::getEReference_ResolveProxies() const
{
	return dynamic_cast<ecore::EAttribute*>(eReferenceEClass->getEStructuralFeatures()->at(2));
}

ecore::EReference* EcorePackageImpl::getEReference_EKeys() const
{
	return dynamic_cast<ecore::EReference*>(eReferenceEClass->getEStructuralFeatures()->at(5));
}
ecore::EReference* EcorePackageImpl::getEReference_EOpposite() const
{
	return dynamic_cast<ecore::EReference*>(eReferenceEClass->getEStructuralFeatures()->at(3));
}
ecore::EReference* EcorePackageImpl::getEReference_EReferenceType() const
{
	return dynamic_cast<ecore::EReference*>(eReferenceEClass->getEStructuralFeatures()->at(4));
}


// End Class EReference

// Begin Class EStringToStringMapEntry
ecore::EClass* EcorePackageImpl::getEStringToStringMapEntry() const
{
	return eStringToStringMapEntryEClass;
}
ecore::EAttribute* EcorePackageImpl::getEStringToStringMapEntry_Key() const
{
	return dynamic_cast<ecore::EAttribute*>(eStringToStringMapEntryEClass->getEStructuralFeatures()->at(0));
}
ecore::EAttribute* EcorePackageImpl::getEStringToStringMapEntry_Value() const
{
	return dynamic_cast<ecore::EAttribute*>(eStringToStringMapEntryEClass->getEStructuralFeatures()->at(1));
}



// End Class EStringToStringMapEntry

// Begin Class EStructuralFeature
ecore::EClass* EcorePackageImpl::getEStructuralFeature() const
{
	return eStructuralFeatureEClass;
}
ecore::EAttribute* EcorePackageImpl::getEStructuralFeature_Changeable() const
{
	return dynamic_cast<ecore::EAttribute*>(eStructuralFeatureEClass->getEStructuralFeatures()->at(0));
}
ecore::EAttribute* EcorePackageImpl::getEStructuralFeature_ContainerClass() const
{
	return dynamic_cast<ecore::EAttribute*>(eStructuralFeatureEClass->getEStructuralFeatures()->at(8));
}
ecore::EAttribute* EcorePackageImpl::getEStructuralFeature_DefaultValue() const
{
	return dynamic_cast<ecore::EAttribute*>(eStructuralFeatureEClass->getEStructuralFeatures()->at(4));
}
ecore::EAttribute* EcorePackageImpl::getEStructuralFeature_DefaultValueLiteral() const
{
	return dynamic_cast<ecore::EAttribute*>(eStructuralFeatureEClass->getEStructuralFeatures()->at(3));
}
ecore::EAttribute* EcorePackageImpl::getEStructuralFeature_Derived() const
{
	return dynamic_cast<ecore::EAttribute*>(eStructuralFeatureEClass->getEStructuralFeatures()->at(6));
}
ecore::EAttribute* EcorePackageImpl::getEStructuralFeature_FeatureID() const
{
	return dynamic_cast<ecore::EAttribute*>(eStructuralFeatureEClass->getEStructuralFeatures()->at(7));
}
ecore::EAttribute* EcorePackageImpl::getEStructuralFeature_Transient() const
{
	return dynamic_cast<ecore::EAttribute*>(eStructuralFeatureEClass->getEStructuralFeatures()->at(2));
}
ecore::EAttribute* EcorePackageImpl::getEStructuralFeature_Unsettable() const
{
	return dynamic_cast<ecore::EAttribute*>(eStructuralFeatureEClass->getEStructuralFeatures()->at(5));
}
ecore::EAttribute* EcorePackageImpl::getEStructuralFeature_Volatile() const
{
	return dynamic_cast<ecore::EAttribute*>(eStructuralFeatureEClass->getEStructuralFeatures()->at(1));
}

ecore::EReference* EcorePackageImpl::getEStructuralFeature_EContainingClass() const
{
	return dynamic_cast<ecore::EReference*>(eStructuralFeatureEClass->getEStructuralFeatures()->at(9));
}


// End Class EStructuralFeature

// Begin Class ETypeParameter
ecore::EClass* EcorePackageImpl::getETypeParameter() const
{
	return eTypeParameterEClass;
}

ecore::EReference* EcorePackageImpl::getETypeParameter_EBounds() const
{
	return dynamic_cast<ecore::EReference*>(eTypeParameterEClass->getEStructuralFeatures()->at(0));
}


// End Class ETypeParameter

// Begin Class ETypedElement
ecore::EClass* EcorePackageImpl::getETypedElement() const
{
	return eTypedElementEClass;
}
ecore::EAttribute* EcorePackageImpl::getETypedElement_LowerBound() const
{
	return dynamic_cast<ecore::EAttribute*>(eTypedElementEClass->getEStructuralFeatures()->at(2));
}
ecore::EAttribute* EcorePackageImpl::getETypedElement_Many() const
{
	return dynamic_cast<ecore::EAttribute*>(eTypedElementEClass->getEStructuralFeatures()->at(4));
}
ecore::EAttribute* EcorePackageImpl::getETypedElement_Ordered() const
{
	return dynamic_cast<ecore::EAttribute*>(eTypedElementEClass->getEStructuralFeatures()->at(0));
}
ecore::EAttribute* EcorePackageImpl::getETypedElement_Required() const
{
	return dynamic_cast<ecore::EAttribute*>(eTypedElementEClass->getEStructuralFeatures()->at(5));
}
ecore::EAttribute* EcorePackageImpl::getETypedElement_Unique() const
{
	return dynamic_cast<ecore::EAttribute*>(eTypedElementEClass->getEStructuralFeatures()->at(1));
}
ecore::EAttribute* EcorePackageImpl::getETypedElement_UpperBound() const
{
	return dynamic_cast<ecore::EAttribute*>(eTypedElementEClass->getEStructuralFeatures()->at(3));
}

ecore::EReference* EcorePackageImpl::getETypedElement_EGenericType() const
{
	return dynamic_cast<ecore::EReference*>(eTypedElementEClass->getEStructuralFeatures()->at(7));
}
ecore::EReference* EcorePackageImpl::getETypedElement_EType() const
{
	return dynamic_cast<ecore::EReference*>(eTypedElementEClass->getEStructuralFeatures()->at(6));
}


// End Class ETypedElement
ecore::EDataType* EcorePackageImpl::getEBigDecimal() const
{
	assert(eBigDecimalEDataType);
	return eBigDecimalEDataType;
}
ecore::EDataType* EcorePackageImpl::getEBigInteger() const
{
	assert(eBigIntegerEDataType);
	return eBigIntegerEDataType;
}
ecore::EDataType* EcorePackageImpl::getEBoolean() const
{
	assert(eBooleanEDataType);
	return eBooleanEDataType;
}
ecore::EDataType* EcorePackageImpl::getEBooleanObject() const
{
	assert(eBooleanObjectEDataType);
	return eBooleanObjectEDataType;
}
ecore::EDataType* EcorePackageImpl::getEByte() const
{
	assert(eByteEDataType);
	return eByteEDataType;
}
ecore::EDataType* EcorePackageImpl::getEByteArray() const
{
	assert(eByteArrayEDataType);
	return eByteArrayEDataType;
}
ecore::EDataType* EcorePackageImpl::getEByteObject() const
{
	assert(eByteObjectEDataType);
	return eByteObjectEDataType;
}
ecore::EDataType* EcorePackageImpl::getEChar() const
{
	assert(eCharEDataType);
	return eCharEDataType;
}
ecore::EDataType* EcorePackageImpl::getECharacterObject() const
{
	assert(eCharacterObjectEDataType);
	return eCharacterObjectEDataType;
}
ecore::EDataType* EcorePackageImpl::getEDate() const
{
	assert(eDateEDataType);
	return eDateEDataType;
}
ecore::EDataType* EcorePackageImpl::getEDiagnosticChain() const
{
	assert(eDiagnosticChainEDataType);
	return eDiagnosticChainEDataType;
}
ecore::EDataType* EcorePackageImpl::getEDouble() const
{
	assert(eDoubleEDataType);
	return eDoubleEDataType;
}
ecore::EDataType* EcorePackageImpl::getEDoubleObject() const
{
	assert(eDoubleObjectEDataType);
	return eDoubleObjectEDataType;
}
ecore::EDataType* EcorePackageImpl::getEEList() const
{
	assert(eEListEDataType);
	return eEListEDataType;
}
ecore::EDataType* EcorePackageImpl::getEEnumerator() const
{
	assert(eEnumeratorEDataType);
	return eEnumeratorEDataType;
}
ecore::EDataType* EcorePackageImpl::getEFeatureMap() const
{
	assert(eFeatureMapEDataType);
	return eFeatureMapEDataType;
}
ecore::EDataType* EcorePackageImpl::getEFeatureMapEntry() const
{
	assert(eFeatureMapEntryEDataType);
	return eFeatureMapEntryEDataType;
}
ecore::EDataType* EcorePackageImpl::getEFloat() const
{
	assert(eFloatEDataType);
	return eFloatEDataType;
}
ecore::EDataType* EcorePackageImpl::getEFloatObject() const
{
	assert(eFloatObjectEDataType);
	return eFloatObjectEDataType;
}
ecore::EDataType* EcorePackageImpl::getEInt() const
{
	assert(eIntEDataType);
	return eIntEDataType;
}
ecore::EDataType* EcorePackageImpl::getEIntegerObject() const
{
	assert(eIntegerObjectEDataType);
	return eIntegerObjectEDataType;
}
ecore::EDataType* EcorePackageImpl::getEInvocationTargetException() const
{
	assert(eInvocationTargetExceptionEDataType);
	return eInvocationTargetExceptionEDataType;
}
ecore::EDataType* EcorePackageImpl::getEJavaClass() const
{
	assert(eJavaClassEDataType);
	return eJavaClassEDataType;
}
ecore::EDataType* EcorePackageImpl::getEJavaObject() const
{
	assert(eJavaObjectEDataType);
	return eJavaObjectEDataType;
}
ecore::EDataType* EcorePackageImpl::getELong() const
{
	assert(eLongEDataType);
	return eLongEDataType;
}
ecore::EDataType* EcorePackageImpl::getELongObject() const
{
	assert(eLongObjectEDataType);
	return eLongObjectEDataType;
}
ecore::EDataType* EcorePackageImpl::getEMap() const
{
	assert(eMapEDataType);
	return eMapEDataType;
}
ecore::EDataType* EcorePackageImpl::getEResource() const
{
	assert(eResourceEDataType);
	return eResourceEDataType;
}
ecore::EDataType* EcorePackageImpl::getEResourceSet() const
{
	assert(eResourceSetEDataType);
	return eResourceSetEDataType;
}
ecore::EDataType* EcorePackageImpl::getEShort() const
{
	assert(eShortEDataType);
	return eShortEDataType;
}
ecore::EDataType* EcorePackageImpl::getEShortObject() const
{
	assert(eShortObjectEDataType);
	return eShortObjectEDataType;
}
ecore::EDataType* EcorePackageImpl::getEString() const
{
	assert(eStringEDataType);
	return eStringEDataType;
}
ecore::EDataType* EcorePackageImpl::getETreeIterator() const
{
	assert(eTreeIteratorEDataType);
	return eTreeIteratorEDataType;
}

