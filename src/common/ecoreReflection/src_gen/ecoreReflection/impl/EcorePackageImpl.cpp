#include "ecoreReflection/impl/EcorePackageImpl.hpp"

//meta meta model classes
#include "uml/Association.hpp"
#include "uml/Class.hpp"
#include "uml/ClassifierTemplateParameter.hpp"
#include "uml/Generalization.hpp"
#include "uml/LiteralInteger.hpp"
#include "uml/LiteralUnlimitedNatural.hpp"
#include "uml/Operation.hpp"
#include "uml/Parameter.hpp"
#include "uml/PrimitiveType.hpp"
#include "uml/ProfileApplication.hpp"
#include "uml/Property.hpp"
#include "uml/RedefinableTemplateSignature.hpp"
#include "uml/TemplateBinding.hpp"
#include "uml/TemplateParameterSubstitution.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "uml/VisibilityKind.hpp"
//meta meta model factory
#include "uml/umlFactory.hpp"
#include "ecore/ecorePackage.hpp"


//depending model packages



//Stereotypes
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/EReference.hpp"

using namespace Ecore;

//Singleton implemenation
std::shared_ptr<EcorePackage> EcorePackage::eInstance()
{
	static std::shared_ptr<EcorePackage> instance;
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(EcorePackageImpl::create());
		std::dynamic_pointer_cast<EcorePackageImpl>(instance)->init(instance);
	}	
	return instance;
}
//static initialization
const std::string EcorePackage::eNAME ="Ecore";
const std::string EcorePackage::eNS_URI ="http://www.eclipse.org/emf/2002/Ecore";
const std::string EcorePackage::eNS_PREFIX ="";

EcorePackageImpl::EcorePackageImpl()
{
}

EcorePackageImpl::~EcorePackageImpl()
{
}

bool EcorePackageImpl::isInited = false;

EcorePackage* EcorePackageImpl::create()
{
	if (isInited)
	{
		return EcorePackage::eInstance().get();
	}
	isInited = true;
	
    // Obtain or create and register package, create package meta-data objects
    EcorePackageImpl * metaModelPackage = new EcorePackageImpl();
    return metaModelPackage;
}

void EcorePackageImpl::init(std::shared_ptr<uml::Package> ecore)
{
    // Initialize created meta-data
	setThisPackagePtr(ecore);
	initMetaModel();
    createPackageContents(ecore);
    initializePackageContents(ecore);   
}

void EcorePackageImpl::initMetaModel()
{
}

void EcorePackageImpl::createPackageContents(std::shared_ptr<uml::Package> ecore)
{
	if (isCreated)
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<uml::umlFactory> factory = uml::umlFactory::eInstance();

	createPackageActivities(ecore, factory);
	createPackageAssociations(ecore, factory);
	createPackageClasses(ecore, factory);
	createPackageDataTypes(ecore, factory);
	createPackageDependencies(ecore, factory);
	createPackageEnumerationLiterals(ecore, factory);
	createPackageEvents(ecore, factory);
	createPackageValueSpecifications(ecore, factory);
	createPackageInstanceSpecifications(ecore, factory);
	createPackageInterfaces(ecore, factory);
	createPackageInterfaceRealizations(ecore, factory);
	createPackagePrimitiveTypes(ecore, factory);
	createPackageSignals(ecore, factory);
	createPackageStereotypes(ecore, factory);
}

void EcorePackageImpl::createPackageActivities(std::shared_ptr<uml::Package> ecore, std::shared_ptr<uml::umlFactory> factory)
{
}


void EcorePackageImpl::createPackageAssociations(std::shared_ptr<uml::Package> ecore, std::shared_ptr<uml::umlFactory> factory)
{
	//
	a_Ecore_EAnnotation_eAnnotations_Ecore_EModelElement_eModelElement = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EAttribute_eAllAttributes_eClass = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EAttribute_eAttributes_eClass = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EAttribute_eIDAttribute_eClass = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EAttribute_eKeys_eReference = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EClass_eAllSuperTypes_eClass = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EClass_eReferenceType_eReference = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EClass_eSuperTypes_eClass = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EClassifier_eClassifier_eGenericType = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EClassifier_eClassifiers_Ecore_EPackage_ePackage = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EClassifier_eExceptions_eOperation = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EClassifier_eRawType_eGenericType = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EClassifier_eType_eTypedElement = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EDataType_eAttributeType_eAttribute = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EEnumLiteral_eLiterals_Ecore_EEnum_eEnum = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EGenericType_eAllGenericSuperTypes_eClass = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EGenericType_eBounds_eTypeParameter = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EGenericType_eGenericExceptions_eOperation = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EGenericType_eGenericSuperTypes_eClass = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EGenericType_eGenericType_eTypedElement = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EGenericType_eLowerBound_eGenericType = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EGenericType_eTypeArguments_eGenericType = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EGenericType_eUpperBound_eGenericType = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EObject_contents_eAnnotation = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EObject_references_eAnnotation = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EOperation_eAllOperations_eClass = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EOperation_eOperations_Ecore_EClass_eContainingClass = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EPackage_ePackage_Ecore_EFactory_eFactoryInstance = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EPackage_eSubpackages_Ecore_EPackage_eSuperPackage = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EParameter_eParameters_Ecore_EOperation_eOperation = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EReference_eAllContainments_eClass = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EReference_eAllReferences_eClass = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EReference_eOpposite_eReference = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EReference_eReferences_eClass = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EStringToStringMapEntry_details_eAnnotation = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EStructuralFeature_eAllStructuralFeatures_eClass = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_EStructuralFeature_eStructuralFeatures_Ecore_EClass_eContainingClass = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_ETypeParameter_eTypeParameter_eGenericType = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_ETypeParameter_eTypeParameters_eClassifier = factory->createAssociation_as_ownedType_in_Package(ecore);

    //-------------------------------------------
	//
	a_Ecore_ETypeParameter_eTypeParameters_eOperation = factory->createAssociation_as_ownedType_in_Package(ecore);
}

void EcorePackageImpl::createPackageClasses(std::shared_ptr<uml::Package> ecore, std::shared_ptr<uml::umlFactory> factory)
{
	std::shared_ptr<uml::Constraint> con = nullptr;
	std::shared_ptr<uml::OpaqueExpression> oe = nullptr;

	//EAnnotation
	ecore_EAnnotation = factory->createClass_as_ownedType_in_Package(ecore, ecore::ecorePackage::EANNOTATION_CLASS);
	
    // EAnnotation attributes
	//contents
	ecore_EAnnotation_contents = factory->createProperty_as_ownedAttribute_in_Class(ecore_EAnnotation);
	//details
	ecore_EAnnotation_details = factory->createProperty_as_ownedAttribute_in_Class(ecore_EAnnotation);
	//eModelElement
	ecore_EAnnotation_eModelElement = factory->createProperty_as_ownedAttribute_in_Class(ecore_EAnnotation);
	//references
	ecore_EAnnotation_references = factory->createProperty_as_ownedAttribute_in_Class(ecore_EAnnotation);
	//source
	ecore_EAnnotation_source = factory->createProperty_as_ownedAttribute_in_Class(ecore_EAnnotation);

    //-------------------------------------------
	//EAttribute
	ecore_EAttribute = factory->createClass_as_ownedType_in_Package(ecore, ecore::ecorePackage::EATTRIBUTE_CLASS);
	
    // EAttribute attributes
	//eAttributeType
	ecore_EAttribute_eAttributeType = factory->createProperty_as_ownedAttribute_in_Class(ecore_EAttribute);
	//id
	ecore_EAttribute_id = factory->createProperty_as_ownedAttribute_in_Class(ecore_EAttribute);

    //-------------------------------------------
	//EClass
	ecore_EClass = factory->createClass_as_ownedType_in_Package(ecore, ecore::ecorePackage::ECLASS_CLASS);
	
    // EClass attributes
	//abstract
	ecore_EClass_abstract = factory->createProperty_as_ownedAttribute_in_Class(ecore_EClass);
	//eAllAttributes
	ecore_EClass_eAllAttributes = factory->createProperty_as_ownedAttribute_in_Class(ecore_EClass);
	//eAllContainments
	ecore_EClass_eAllContainments = factory->createProperty_as_ownedAttribute_in_Class(ecore_EClass);
	//eAllGenericSuperTypes
	ecore_EClass_eAllGenericSuperTypes = factory->createProperty_as_ownedAttribute_in_Class(ecore_EClass);
	//eAllOperations
	ecore_EClass_eAllOperations = factory->createProperty_as_ownedAttribute_in_Class(ecore_EClass);
	//eAllReferences
	ecore_EClass_eAllReferences = factory->createProperty_as_ownedAttribute_in_Class(ecore_EClass);
	//eAllStructuralFeatures
	ecore_EClass_eAllStructuralFeatures = factory->createProperty_as_ownedAttribute_in_Class(ecore_EClass);
	//eAllSuperTypes
	ecore_EClass_eAllSuperTypes = factory->createProperty_as_ownedAttribute_in_Class(ecore_EClass);
	//eAttributes
	ecore_EClass_eAttributes = factory->createProperty_as_ownedAttribute_in_Class(ecore_EClass);
	//eGenericSuperTypes
	ecore_EClass_eGenericSuperTypes = factory->createProperty_as_ownedAttribute_in_Class(ecore_EClass);
	//eIDAttribute
	ecore_EClass_eIDAttribute = factory->createProperty_as_ownedAttribute_in_Class(ecore_EClass);
	//eOperations
	ecore_EClass_eOperations = factory->createProperty_as_ownedAttribute_in_Class(ecore_EClass);
	//eReferences
	ecore_EClass_eReferences = factory->createProperty_as_ownedAttribute_in_Class(ecore_EClass);
	//eStructuralFeatures
	ecore_EClass_eStructuralFeatures = factory->createProperty_as_ownedAttribute_in_Class(ecore_EClass);
	//eSuperTypes
	ecore_EClass_eSuperTypes = factory->createProperty_as_ownedAttribute_in_Class(ecore_EClass);
	//interface
	ecore_EClass_interface = factory->createProperty_as_ownedAttribute_in_Class(ecore_EClass);
    // EClass operations
	//getEStructuralFeature
	ecore_EClass_getEStructuralFeature_EInt_EInt = factory->createOperation_as_ownedOperation_in_Class(ecore_EClass);
	ecore_EClass_getEStructuralFeature_EInt_EIntreturn = factory->createParameter_as_ownedParameter_in_Operation(ecore_EClass_getEStructuralFeature_EInt_EInt);ecore_EClass_getEStructuralFeature_EInt_EInt_featureID = factory->createParameter_as_ownedParameter_in_Operation(ecore_EClass_getEStructuralFeature_EInt_EInt);

	//getEStructuralFeature
	ecore_EClass_getEStructuralFeature_EString_EString = factory->createOperation_as_ownedOperation_in_Class(ecore_EClass);
	ecore_EClass_getEStructuralFeature_EString_EStringreturn = factory->createParameter_as_ownedParameter_in_Operation(ecore_EClass_getEStructuralFeature_EString_EString);ecore_EClass_getEStructuralFeature_EString_EString_featureName = factory->createParameter_as_ownedParameter_in_Operation(ecore_EClass_getEStructuralFeature_EString_EString);

	//getFeatureCount
	ecore_EClass_getFeatureCount__ = factory->createOperation_as_ownedOperation_in_Class(ecore_EClass);
	ecore_EClass_getFeatureCount__return = factory->createParameter_as_ownedParameter_in_Operation(ecore_EClass_getFeatureCount__);

	//getFeatureID
	ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeature = factory->createOperation_as_ownedOperation_in_Class(ecore_EClass);
	ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeaturereturn = factory->createParameter_as_ownedParameter_in_Operation(ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeature);ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeature_feature = factory->createParameter_as_ownedParameter_in_Operation(ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeature);

	//isSuperTypeOf
	ecore_EClass_isSuperTypeOf_EClass_EClass = factory->createOperation_as_ownedOperation_in_Class(ecore_EClass);
	ecore_EClass_isSuperTypeOf_EClass_EClassreturn = factory->createParameter_as_ownedParameter_in_Operation(ecore_EClass_isSuperTypeOf_EClass_EClass);ecore_EClass_isSuperTypeOf_EClass_EClass_someClass = factory->createParameter_as_ownedParameter_in_Operation(ecore_EClass_isSuperTypeOf_EClass_EClass);

    //-------------------------------------------
	//EClassifier
	ecore_EClassifier = factory->createClass_as_ownedType_in_Package(ecore, ecore::ecorePackage::ECLASSIFIER_CLASS);
	
    // EClassifier attributes
	//defaultValue
	ecore_EClassifier_defaultValue = factory->createProperty_as_ownedAttribute_in_Class(ecore_EClassifier);
	//ePackage
	ecore_EClassifier_ePackage = factory->createProperty_as_ownedAttribute_in_Class(ecore_EClassifier);
	//eTypeParameters
	ecore_EClassifier_eTypeParameters = factory->createProperty_as_ownedAttribute_in_Class(ecore_EClassifier);
	//instanceClass
	ecore_EClassifier_instanceClass = factory->createProperty_as_ownedAttribute_in_Class(ecore_EClassifier);
	//instanceClassName
	ecore_EClassifier_instanceClassName = factory->createProperty_as_ownedAttribute_in_Class(ecore_EClassifier);
	//instanceTypeName
	ecore_EClassifier_instanceTypeName = factory->createProperty_as_ownedAttribute_in_Class(ecore_EClassifier);
    // EClassifier operations
	//getClassifierID
	ecore_EClassifier_getClassifierID__ = factory->createOperation_as_ownedOperation_in_Class(ecore_EClassifier);
	ecore_EClassifier_getClassifierID__return = factory->createParameter_as_ownedParameter_in_Operation(ecore_EClassifier_getClassifierID__);

	//isInstance
	ecore_EClassifier_isInstance_EJavaObject_EJavaObject = factory->createOperation_as_ownedOperation_in_Class(ecore_EClassifier);
	ecore_EClassifier_isInstance_EJavaObject_EJavaObjectreturn = factory->createParameter_as_ownedParameter_in_Operation(ecore_EClassifier_isInstance_EJavaObject_EJavaObject);ecore_EClassifier_isInstance_EJavaObject_EJavaObject_object = factory->createParameter_as_ownedParameter_in_Operation(ecore_EClassifier_isInstance_EJavaObject_EJavaObject);

    //-------------------------------------------
	//EDataType
	ecore_EDataType = factory->createClass_as_ownedType_in_Package(ecore, ecore::ecorePackage::EDATATYPE_CLASS);
	
    // EDataType attributes
	//serializable
	ecore_EDataType_serializable = factory->createProperty_as_ownedAttribute_in_Class(ecore_EDataType);

    //-------------------------------------------
	//EEnum
	ecore_EEnum = factory->createClass_as_ownedType_in_Package(ecore, ecore::ecorePackage::EENUM_CLASS);
	
    // EEnum attributes
	//eLiterals
	ecore_EEnum_eLiterals = factory->createProperty_as_ownedAttribute_in_Class(ecore_EEnum);
    // EEnum operations
	//getEEnumLiteral
	ecore_EEnum_getEEnumLiteral_EString_EString = factory->createOperation_as_ownedOperation_in_Class(ecore_EEnum);
	ecore_EEnum_getEEnumLiteral_EString_EStringreturn = factory->createParameter_as_ownedParameter_in_Operation(ecore_EEnum_getEEnumLiteral_EString_EString);ecore_EEnum_getEEnumLiteral_EString_EString_name = factory->createParameter_as_ownedParameter_in_Operation(ecore_EEnum_getEEnumLiteral_EString_EString);

	//getEEnumLiteral
	ecore_EEnum_getEEnumLiteral_EInt_EInt = factory->createOperation_as_ownedOperation_in_Class(ecore_EEnum);
	ecore_EEnum_getEEnumLiteral_EInt_EIntreturn = factory->createParameter_as_ownedParameter_in_Operation(ecore_EEnum_getEEnumLiteral_EInt_EInt);ecore_EEnum_getEEnumLiteral_EInt_EInt_value = factory->createParameter_as_ownedParameter_in_Operation(ecore_EEnum_getEEnumLiteral_EInt_EInt);

	//getEEnumLiteralByLiteral
	ecore_EEnum_getEEnumLiteralByLiteral_EString_EString = factory->createOperation_as_ownedOperation_in_Class(ecore_EEnum);
	ecore_EEnum_getEEnumLiteralByLiteral_EString_EStringreturn = factory->createParameter_as_ownedParameter_in_Operation(ecore_EEnum_getEEnumLiteralByLiteral_EString_EString);ecore_EEnum_getEEnumLiteralByLiteral_EString_EString_literal = factory->createParameter_as_ownedParameter_in_Operation(ecore_EEnum_getEEnumLiteralByLiteral_EString_EString);

    //-------------------------------------------
	//EEnumLiteral
	ecore_EEnumLiteral = factory->createClass_as_ownedType_in_Package(ecore, ecore::ecorePackage::EENUMLITERAL_CLASS);
	
    // EEnumLiteral attributes
	//eEnum
	ecore_EEnumLiteral_eEnum = factory->createProperty_as_ownedAttribute_in_Class(ecore_EEnumLiteral);
	//instance
	ecore_EEnumLiteral_instance = factory->createProperty_as_ownedAttribute_in_Class(ecore_EEnumLiteral);
	//literal
	ecore_EEnumLiteral_literal = factory->createProperty_as_ownedAttribute_in_Class(ecore_EEnumLiteral);
	//value
	ecore_EEnumLiteral_value = factory->createProperty_as_ownedAttribute_in_Class(ecore_EEnumLiteral);

    //-------------------------------------------
	//EFactory
	ecore_EFactory = factory->createClass_as_ownedType_in_Package(ecore, ecore::ecorePackage::EFACTORY_CLASS);
	
    // EFactory attributes
	//ePackage
	ecore_EFactory_ePackage = factory->createProperty_as_ownedAttribute_in_Class(ecore_EFactory);
    // EFactory operations
	//convertToString
	ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject = factory->createOperation_as_ownedOperation_in_Class(ecore_EFactory);
	ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObjectreturn = factory->createParameter_as_ownedParameter_in_Operation(ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject);ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject_eDataType = factory->createParameter_as_ownedParameter_in_Operation(ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject);ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject_instanceValue = factory->createParameter_as_ownedParameter_in_Operation(ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject);

	//create
	ecore_EFactory_create_EClass_EClass = factory->createOperation_as_ownedOperation_in_Class(ecore_EFactory);
	ecore_EFactory_create_EClass_EClassreturn = factory->createParameter_as_ownedParameter_in_Operation(ecore_EFactory_create_EClass_EClass);ecore_EFactory_create_EClass_EClass_eClass = factory->createParameter_as_ownedParameter_in_Operation(ecore_EFactory_create_EClass_EClass);

	//createFromString
	ecore_EFactory_createFromString_EDataType_EString_EDataType_EString = factory->createOperation_as_ownedOperation_in_Class(ecore_EFactory);
	ecore_EFactory_createFromString_EDataType_EString_EDataType_EStringreturn = factory->createParameter_as_ownedParameter_in_Operation(ecore_EFactory_createFromString_EDataType_EString_EDataType_EString);ecore_EFactory_createFromString_EDataType_EString_EDataType_EString_eDataType = factory->createParameter_as_ownedParameter_in_Operation(ecore_EFactory_createFromString_EDataType_EString_EDataType_EString);ecore_EFactory_createFromString_EDataType_EString_EDataType_EString_literalValue = factory->createParameter_as_ownedParameter_in_Operation(ecore_EFactory_createFromString_EDataType_EString_EDataType_EString);

    //-------------------------------------------
	//EGenericType
	ecore_EGenericType = factory->createClass_as_ownedType_in_Package(ecore, ecore::ecorePackage::EGENERICTYPE_CLASS);
	
    // EGenericType attributes
	//eClassifier
	ecore_EGenericType_eClassifier = factory->createProperty_as_ownedAttribute_in_Class(ecore_EGenericType);
	//eLowerBound
	ecore_EGenericType_eLowerBound = factory->createProperty_as_ownedAttribute_in_Class(ecore_EGenericType);
	//eRawType
	ecore_EGenericType_eRawType = factory->createProperty_as_ownedAttribute_in_Class(ecore_EGenericType);
	//eTypeArguments
	ecore_EGenericType_eTypeArguments = factory->createProperty_as_ownedAttribute_in_Class(ecore_EGenericType);
	//eTypeParameter
	ecore_EGenericType_eTypeParameter = factory->createProperty_as_ownedAttribute_in_Class(ecore_EGenericType);
	//eUpperBound
	ecore_EGenericType_eUpperBound = factory->createProperty_as_ownedAttribute_in_Class(ecore_EGenericType);

    //-------------------------------------------
	//EModelElement
	ecore_EModelElement = factory->createClass_as_ownedType_in_Package(ecore, ecore::ecorePackage::EMODELELEMENT_CLASS);
	
    // EModelElement attributes
	//eAnnotations
	ecore_EModelElement_eAnnotations = factory->createProperty_as_ownedAttribute_in_Class(ecore_EModelElement);
    // EModelElement operations
	//getEAnnotation
	ecore_EModelElement_getEAnnotation_EString_EString = factory->createOperation_as_ownedOperation_in_Class(ecore_EModelElement);
	ecore_EModelElement_getEAnnotation_EString_EStringreturn = factory->createParameter_as_ownedParameter_in_Operation(ecore_EModelElement_getEAnnotation_EString_EString);ecore_EModelElement_getEAnnotation_EString_EString_source = factory->createParameter_as_ownedParameter_in_Operation(ecore_EModelElement_getEAnnotation_EString_EString);

    //-------------------------------------------
	//ENamedElement
	ecore_ENamedElement = factory->createClass_as_ownedType_in_Package(ecore, ecore::ecorePackage::ENAMEDELEMENT_CLASS);
	
    // ENamedElement attributes
	//name
	ecore_ENamedElement_name = factory->createProperty_as_ownedAttribute_in_Class(ecore_ENamedElement);

    //-------------------------------------------
	//EObject
	ecore_EObject = factory->createClass_as_ownedType_in_Package(ecore, ecore::ecorePackage::EOBJECT_CLASS);
	
    // EObject operations
	//eAllContents
	ecore_EObject_eAllContents__ = factory->createOperation_as_ownedOperation_in_Class(ecore_EObject);
	ecore_EObject_eAllContents__return = factory->createParameter_as_ownedParameter_in_Operation(ecore_EObject_eAllContents__);

	//eClass
	ecore_EObject_eClass__ = factory->createOperation_as_ownedOperation_in_Class(ecore_EObject);
	ecore_EObject_eClass__return = factory->createParameter_as_ownedParameter_in_Operation(ecore_EObject_eClass__);

	//eContainer
	ecore_EObject_eContainer__ = factory->createOperation_as_ownedOperation_in_Class(ecore_EObject);
	ecore_EObject_eContainer__return = factory->createParameter_as_ownedParameter_in_Operation(ecore_EObject_eContainer__);

	//eContainingFeature
	ecore_EObject_eContainingFeature__ = factory->createOperation_as_ownedOperation_in_Class(ecore_EObject);
	ecore_EObject_eContainingFeature__return = factory->createParameter_as_ownedParameter_in_Operation(ecore_EObject_eContainingFeature__);

	//eContainmentFeature
	ecore_EObject_eContainmentFeature__ = factory->createOperation_as_ownedOperation_in_Class(ecore_EObject);
	ecore_EObject_eContainmentFeature__return = factory->createParameter_as_ownedParameter_in_Operation(ecore_EObject_eContainmentFeature__);

	//eContents
	ecore_EObject_eContents__ = factory->createOperation_as_ownedOperation_in_Class(ecore_EObject);
	ecore_EObject_eContents__return = factory->createParameter_as_ownedParameter_in_Operation(ecore_EObject_eContents__);

	//eCrossReferences
	ecore_EObject_eCrossReferences__ = factory->createOperation_as_ownedOperation_in_Class(ecore_EObject);
	ecore_EObject_eCrossReferences__return = factory->createParameter_as_ownedParameter_in_Operation(ecore_EObject_eCrossReferences__);

	//eGet
	ecore_EObject_eGet_EStructuralFeature_EStructuralFeature = factory->createOperation_as_ownedOperation_in_Class(ecore_EObject);
	ecore_EObject_eGet_EStructuralFeature_EStructuralFeaturereturn = factory->createParameter_as_ownedParameter_in_Operation(ecore_EObject_eGet_EStructuralFeature_EStructuralFeature);ecore_EObject_eGet_EStructuralFeature_EStructuralFeature_feature = factory->createParameter_as_ownedParameter_in_Operation(ecore_EObject_eGet_EStructuralFeature_EStructuralFeature);

	//eGet
	ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean = factory->createOperation_as_ownedOperation_in_Class(ecore_EObject);
	ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBooleanreturn = factory->createParameter_as_ownedParameter_in_Operation(ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean);ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean_feature = factory->createParameter_as_ownedParameter_in_Operation(ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean);ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean_resolve = factory->createParameter_as_ownedParameter_in_Operation(ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean);

	//eIsProxy
	ecore_EObject_eIsProxy__ = factory->createOperation_as_ownedOperation_in_Class(ecore_EObject);
	ecore_EObject_eIsProxy__return = factory->createParameter_as_ownedParameter_in_Operation(ecore_EObject_eIsProxy__);

	//eIsSet
	ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeature = factory->createOperation_as_ownedOperation_in_Class(ecore_EObject);
	ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeaturereturn = factory->createParameter_as_ownedParameter_in_Operation(ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeature);ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeature_feature = factory->createParameter_as_ownedParameter_in_Operation(ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeature);

	//eResource
	ecore_EObject_eResource__ = factory->createOperation_as_ownedOperation_in_Class(ecore_EObject);
	ecore_EObject_eResource__return = factory->createParameter_as_ownedParameter_in_Operation(ecore_EObject_eResource__);

	//eSet
	ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject = factory->createOperation_as_ownedOperation_in_Class(ecore_EObject);
	ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObjectreturn = factory->createParameter_as_ownedParameter_in_Operation(ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject);ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject_feature = factory->createParameter_as_ownedParameter_in_Operation(ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject);ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject_newValue = factory->createParameter_as_ownedParameter_in_Operation(ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject);

	//eUnset
	ecore_EObject_eUnset_EStructuralFeature_EStructuralFeature = factory->createOperation_as_ownedOperation_in_Class(ecore_EObject);
	ecore_EObject_eUnset_EStructuralFeature_EStructuralFeaturereturn = factory->createParameter_as_ownedParameter_in_Operation(ecore_EObject_eUnset_EStructuralFeature_EStructuralFeature);ecore_EObject_eUnset_EStructuralFeature_EStructuralFeature_feature = factory->createParameter_as_ownedParameter_in_Operation(ecore_EObject_eUnset_EStructuralFeature_EStructuralFeature);

    //-------------------------------------------
	//EOperation
	ecore_EOperation = factory->createClass_as_ownedType_in_Package(ecore, ecore::ecorePackage::EOPERATION_CLASS);
	
    // EOperation attributes
	//eContainingClass
	ecore_EOperation_eContainingClass = factory->createProperty_as_ownedAttribute_in_Class(ecore_EOperation);
	//eExceptions
	ecore_EOperation_eExceptions = factory->createProperty_as_ownedAttribute_in_Class(ecore_EOperation);
	//eGenericExceptions
	ecore_EOperation_eGenericExceptions = factory->createProperty_as_ownedAttribute_in_Class(ecore_EOperation);
	//eParameters
	ecore_EOperation_eParameters = factory->createProperty_as_ownedAttribute_in_Class(ecore_EOperation);
	//eTypeParameters
	ecore_EOperation_eTypeParameters = factory->createProperty_as_ownedAttribute_in_Class(ecore_EOperation);

    //-------------------------------------------
	//EPackage
	ecore_EPackage = factory->createClass_as_ownedType_in_Package(ecore, ecore::ecorePackage::EPACKAGE_CLASS);
	
    // EPackage attributes
	//eClassifiers
	ecore_EPackage_eClassifiers = factory->createProperty_as_ownedAttribute_in_Class(ecore_EPackage);
	//eFactoryInstance
	ecore_EPackage_eFactoryInstance = factory->createProperty_as_ownedAttribute_in_Class(ecore_EPackage);
	//eSubpackages
	ecore_EPackage_eSubpackages = factory->createProperty_as_ownedAttribute_in_Class(ecore_EPackage);
	//eSuperPackage
	ecore_EPackage_eSuperPackage = factory->createProperty_as_ownedAttribute_in_Class(ecore_EPackage);
	//nsPrefix
	ecore_EPackage_nsPrefix = factory->createProperty_as_ownedAttribute_in_Class(ecore_EPackage);
	//nsURI
	ecore_EPackage_nsURI = factory->createProperty_as_ownedAttribute_in_Class(ecore_EPackage);
    // EPackage operations
	//getEClassifier
	ecore_EPackage_getEClassifier_EString_EString = factory->createOperation_as_ownedOperation_in_Class(ecore_EPackage);
	ecore_EPackage_getEClassifier_EString_EStringreturn = factory->createParameter_as_ownedParameter_in_Operation(ecore_EPackage_getEClassifier_EString_EString);ecore_EPackage_getEClassifier_EString_EString_name = factory->createParameter_as_ownedParameter_in_Operation(ecore_EPackage_getEClassifier_EString_EString);

    //-------------------------------------------
	//EParameter
	ecore_EParameter = factory->createClass_as_ownedType_in_Package(ecore, ecore::ecorePackage::EPARAMETER_CLASS);
	
    // EParameter attributes
	//eOperation
	ecore_EParameter_eOperation = factory->createProperty_as_ownedAttribute_in_Class(ecore_EParameter);

    //-------------------------------------------
	//EReference
	ecore_EReference = factory->createClass_as_ownedType_in_Package(ecore, ecore::ecorePackage::EREFERENCE_CLASS);
	
    // EReference attributes
	//container
	ecore_EReference_container = factory->createProperty_as_ownedAttribute_in_Class(ecore_EReference);
	//containment
	ecore_EReference_containment = factory->createProperty_as_ownedAttribute_in_Class(ecore_EReference);
	//eKeys
	ecore_EReference_eKeys = factory->createProperty_as_ownedAttribute_in_Class(ecore_EReference);
	//eOpposite
	ecore_EReference_eOpposite = factory->createProperty_as_ownedAttribute_in_Class(ecore_EReference);
	//eReferenceType
	ecore_EReference_eReferenceType = factory->createProperty_as_ownedAttribute_in_Class(ecore_EReference);
	//resolveProxies
	ecore_EReference_resolveProxies = factory->createProperty_as_ownedAttribute_in_Class(ecore_EReference);

    //-------------------------------------------
	//EStringToStringMapEntry
	ecore_EStringToStringMapEntry = factory->createClass_as_ownedType_in_Package(ecore, ecore::ecorePackage::ESTRINGTOSTRINGMAPENTRY_CLASS);
	
    // EStringToStringMapEntry attributes
	//key
	ecore_EStringToStringMapEntry_key = factory->createProperty_as_ownedAttribute_in_Class(ecore_EStringToStringMapEntry);
	//value
	ecore_EStringToStringMapEntry_value = factory->createProperty_as_ownedAttribute_in_Class(ecore_EStringToStringMapEntry);

    //-------------------------------------------
	//EStructuralFeature
	ecore_EStructuralFeature = factory->createClass_as_ownedType_in_Package(ecore, ecore::ecorePackage::ESTRUCTURALFEATURE_CLASS);
	
    // EStructuralFeature attributes
	//changeable
	ecore_EStructuralFeature_changeable = factory->createProperty_as_ownedAttribute_in_Class(ecore_EStructuralFeature);
	//defaultValue
	ecore_EStructuralFeature_defaultValue = factory->createProperty_as_ownedAttribute_in_Class(ecore_EStructuralFeature);
	//defaultValueLiteral
	ecore_EStructuralFeature_defaultValueLiteral = factory->createProperty_as_ownedAttribute_in_Class(ecore_EStructuralFeature);
	//derived
	ecore_EStructuralFeature_derived = factory->createProperty_as_ownedAttribute_in_Class(ecore_EStructuralFeature);
	//eContainingClass
	ecore_EStructuralFeature_eContainingClass = factory->createProperty_as_ownedAttribute_in_Class(ecore_EStructuralFeature);
	//transient
	ecore_EStructuralFeature_transient = factory->createProperty_as_ownedAttribute_in_Class(ecore_EStructuralFeature);
	//unsettable
	ecore_EStructuralFeature_unsettable = factory->createProperty_as_ownedAttribute_in_Class(ecore_EStructuralFeature);
	//volatile
	ecore_EStructuralFeature_volatile = factory->createProperty_as_ownedAttribute_in_Class(ecore_EStructuralFeature);
    // EStructuralFeature operations
	//getContainerClass
	ecore_EStructuralFeature_getContainerClass__ = factory->createOperation_as_ownedOperation_in_Class(ecore_EStructuralFeature);
	ecore_EStructuralFeature_getContainerClass__return = factory->createParameter_as_ownedParameter_in_Operation(ecore_EStructuralFeature_getContainerClass__);

	//getFeatureID
	ecore_EStructuralFeature_getFeatureID__ = factory->createOperation_as_ownedOperation_in_Class(ecore_EStructuralFeature);
	ecore_EStructuralFeature_getFeatureID__return = factory->createParameter_as_ownedParameter_in_Operation(ecore_EStructuralFeature_getFeatureID__);

    //-------------------------------------------
	//ETypeParameter
	ecore_ETypeParameter = factory->createClass_as_ownedType_in_Package(ecore, ecore::ecorePackage::ETYPEPARAMETER_CLASS);
	
    // ETypeParameter attributes
	//eBounds
	ecore_ETypeParameter_eBounds = factory->createProperty_as_ownedAttribute_in_Class(ecore_ETypeParameter);

    //-------------------------------------------
	//ETypedElement
	ecore_ETypedElement = factory->createClass_as_ownedType_in_Package(ecore, ecore::ecorePackage::ETYPEDELEMENT_CLASS);
	
    // ETypedElement attributes
	//eGenericType
	ecore_ETypedElement_eGenericType = factory->createProperty_as_ownedAttribute_in_Class(ecore_ETypedElement);
	//eType
	ecore_ETypedElement_eType = factory->createProperty_as_ownedAttribute_in_Class(ecore_ETypedElement);
	//lowerBound
	ecore_ETypedElement_lowerBound = factory->createProperty_as_ownedAttribute_in_Class(ecore_ETypedElement);
	//many
	ecore_ETypedElement_many = factory->createProperty_as_ownedAttribute_in_Class(ecore_ETypedElement);
	//ordered
	ecore_ETypedElement_ordered = factory->createProperty_as_ownedAttribute_in_Class(ecore_ETypedElement);
	//required
	ecore_ETypedElement_required = factory->createProperty_as_ownedAttribute_in_Class(ecore_ETypedElement);
	//unique
	ecore_ETypedElement_unique = factory->createProperty_as_ownedAttribute_in_Class(ecore_ETypedElement);
	//upperBound
	ecore_ETypedElement_upperBound = factory->createProperty_as_ownedAttribute_in_Class(ecore_ETypedElement);

//-------------------------------------------
//Opaque Behaviors

}

void EcorePackageImpl::createPackageSignals(std::shared_ptr<uml::Package> ecore, std::shared_ptr<uml::umlFactory> factory)
{
	std::shared_ptr<uml::Constraint> con = nullptr;
	std::shared_ptr<uml::OpaqueExpression> oe = nullptr;

}

void EcorePackageImpl::createPackageDataTypes(std::shared_ptr<uml::Package> ecore, std::shared_ptr<uml::umlFactory> factory)
{
}

void EcorePackageImpl::createPackageDependencies(std::shared_ptr<uml::Package> ecore, std::shared_ptr<uml::umlFactory> factory)
{
}

void EcorePackageImpl::createPackageEnumerationLiterals(std::shared_ptr<uml::Package> ecore, std::shared_ptr<uml::umlFactory> factory)
{
}

void EcorePackageImpl::createPackageEvents(std::shared_ptr<uml::Package> ecore, std::shared_ptr<uml::umlFactory> factory)
{
}

void EcorePackageImpl::createPackageInstanceSpecifications(std::shared_ptr<uml::Package> ecore, std::shared_ptr<uml::umlFactory> factory)
{
}

void EcorePackageImpl::createPackageInterfaceRealizations(std::shared_ptr<uml::Package> ecore, std::shared_ptr<uml::umlFactory> factory)
{
}

void EcorePackageImpl::createPackageInterfaces(std::shared_ptr<uml::Package> ecore, std::shared_ptr<uml::umlFactory> factory)
{
}

void EcorePackageImpl::createPackagePrimitiveTypes(std::shared_ptr<uml::Package> ecore, std::shared_ptr<uml::umlFactory> factory)
{
	ecore_EBigDecimal = factory->createPrimitiveType_as_ownedType_in_Package(ecore);
	ecore_EBigDecimal->setName("EBigDecimal");

	ecore_EBigInteger = factory->createPrimitiveType_as_ownedType_in_Package(ecore);
	ecore_EBigInteger->setName("EBigInteger");

	ecore_EBoolean = factory->createPrimitiveType_as_ownedType_in_Package(ecore);
	ecore_EBoolean->setName("EBoolean");

	ecore_EBooleanObject = factory->createPrimitiveType_as_ownedType_in_Package(ecore);
	ecore_EBooleanObject->setName("EBooleanObject");

	ecore_EByte = factory->createPrimitiveType_as_ownedType_in_Package(ecore);
	ecore_EByte->setName("EByte");

	ecore_EByteArray = factory->createPrimitiveType_as_ownedType_in_Package(ecore);
	ecore_EByteArray->setName("EByteArray");

	ecore_EByteObject = factory->createPrimitiveType_as_ownedType_in_Package(ecore);
	ecore_EByteObject->setName("EByteObject");

	ecore_EChar = factory->createPrimitiveType_as_ownedType_in_Package(ecore);
	ecore_EChar->setName("EChar");

	ecore_ECharacterObject = factory->createPrimitiveType_as_ownedType_in_Package(ecore);
	ecore_ECharacterObject->setName("ECharacterObject");

	ecore_EDate = factory->createPrimitiveType_as_ownedType_in_Package(ecore);
	ecore_EDate->setName("EDate");

	ecore_EDiagnosticChain = factory->createPrimitiveType_as_ownedType_in_Package(ecore);
	ecore_EDiagnosticChain->setName("EDiagnosticChain");

	ecore_EDouble = factory->createPrimitiveType_as_ownedType_in_Package(ecore);
	ecore_EDouble->setName("EDouble");

	ecore_EDoubleObject = factory->createPrimitiveType_as_ownedType_in_Package(ecore);
	ecore_EDoubleObject->setName("EDoubleObject");

	ecore_EEList = factory->createPrimitiveType_as_ownedType_in_Package(ecore);
	ecore_EEList->setName("EEList");

	ecore_EEnumerator = factory->createPrimitiveType_as_ownedType_in_Package(ecore);
	ecore_EEnumerator->setName("EEnumerator");

	ecore_EFeatureMap = factory->createPrimitiveType_as_ownedType_in_Package(ecore);
	ecore_EFeatureMap->setName("EFeatureMap");

	ecore_EFeatureMapEntry = factory->createPrimitiveType_as_ownedType_in_Package(ecore);
	ecore_EFeatureMapEntry->setName("EFeatureMapEntry");

	ecore_EFloat = factory->createPrimitiveType_as_ownedType_in_Package(ecore);
	ecore_EFloat->setName("EFloat");

	ecore_EFloatObject = factory->createPrimitiveType_as_ownedType_in_Package(ecore);
	ecore_EFloatObject->setName("EFloatObject");

	ecore_EInt = factory->createPrimitiveType_as_ownedType_in_Package(ecore);
	ecore_EInt->setName("EInt");

	ecore_EIntegerObject = factory->createPrimitiveType_as_ownedType_in_Package(ecore);
	ecore_EIntegerObject->setName("EIntegerObject");

	ecore_EInvocationTargetException = factory->createPrimitiveType_as_ownedType_in_Package(ecore);
	ecore_EInvocationTargetException->setName("EInvocationTargetException");

	ecore_EJavaClass = factory->createPrimitiveType_as_ownedType_in_Package(ecore);
	ecore_EJavaClass->setName("EJavaClass");

	ecore_EJavaObject = factory->createPrimitiveType_as_ownedType_in_Package(ecore);
	ecore_EJavaObject->setName("EJavaObject");

	ecore_ELong = factory->createPrimitiveType_as_ownedType_in_Package(ecore);
	ecore_ELong->setName("ELong");

	ecore_ELongObject = factory->createPrimitiveType_as_ownedType_in_Package(ecore);
	ecore_ELongObject->setName("ELongObject");

	ecore_EMap = factory->createPrimitiveType_as_ownedType_in_Package(ecore);
	ecore_EMap->setName("EMap");

	ecore_EResource = factory->createPrimitiveType_as_ownedType_in_Package(ecore);
	ecore_EResource->setName("EResource");

	ecore_EResourceSet = factory->createPrimitiveType_as_ownedType_in_Package(ecore);
	ecore_EResourceSet->setName("EResourceSet");

	ecore_EShort = factory->createPrimitiveType_as_ownedType_in_Package(ecore);
	ecore_EShort->setName("EShort");

	ecore_EShortObject = factory->createPrimitiveType_as_ownedType_in_Package(ecore);
	ecore_EShortObject->setName("EShortObject");

	ecore_EString = factory->createPrimitiveType_as_ownedType_in_Package(ecore);
	ecore_EString->setName("EString");

	ecore_ETreeIterator = factory->createPrimitiveType_as_ownedType_in_Package(ecore);
	ecore_ETreeIterator->setName("ETreeIterator");
}

void EcorePackageImpl::createPackageStereotypes(std::shared_ptr<uml::Package> ecore, std::shared_ptr<uml::umlFactory> factory)
{
}

void EcorePackageImpl::createPackageValueSpecifications(std::shared_ptr<uml::Package> ecore, std::shared_ptr<uml::umlFactory> factory)
{
	ecore_EAnnotation_contents_lowerValue_LiteralInteger_Ecore_EAnnotation_contents = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EAnnotation_contents);
	
	ecore_EAnnotation_contents_upperValue_LiteralUnlimitedNatural_Ecore_EAnnotation_contents = factory->createLiteralUnlimitedNatural_as_ownedElement_in_Element(ecore_EAnnotation_contents);
	
	ecore_EAnnotation_details_lowerValue_LiteralInteger_Ecore_EAnnotation_details = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EAnnotation_details);
	
	ecore_EAnnotation_details_upperValue_LiteralUnlimitedNatural_Ecore_EAnnotation_details = factory->createLiteralUnlimitedNatural_as_ownedElement_in_Element(ecore_EAnnotation_details);
	
	ecore_EAnnotation_eModelElement_lowerValue_LiteralInteger_Ecore_EAnnotation_eModelElement = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EAnnotation_eModelElement);
	
	ecore_EAnnotation_references_lowerValue_LiteralInteger_Ecore_EAnnotation_references = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EAnnotation_references);
	
	ecore_EAnnotation_references_upperValue_LiteralUnlimitedNatural_Ecore_EAnnotation_references = factory->createLiteralUnlimitedNatural_as_ownedElement_in_Element(ecore_EAnnotation_references);
	
	ecore_EAnnotation_source_lowerValue_LiteralInteger_Ecore_EAnnotation_source = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EAnnotation_source);
	
	ecore_EAttribute_id_lowerValue_LiteralInteger_Ecore_EAttribute_id = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EAttribute_id);
	
	ecore_EClass_abstract_lowerValue_LiteralInteger_Ecore_EClass_abstract = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EClass_abstract);
	
	ecore_EClass_eAllAttributes_lowerValue_LiteralInteger_Ecore_EClass_eAllAttributes = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EClass_eAllAttributes);
	
	ecore_EClass_eAllAttributes_upperValue_LiteralUnlimitedNatural_Ecore_EClass_eAllAttributes = factory->createLiteralUnlimitedNatural_as_ownedElement_in_Element(ecore_EClass_eAllAttributes);
	
	ecore_EClass_eAllContainments_lowerValue_LiteralInteger_Ecore_EClass_eAllContainments = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EClass_eAllContainments);
	
	ecore_EClass_eAllContainments_upperValue_LiteralUnlimitedNatural_Ecore_EClass_eAllContainments = factory->createLiteralUnlimitedNatural_as_ownedElement_in_Element(ecore_EClass_eAllContainments);
	
	ecore_EClass_eAllGenericSuperTypes_lowerValue_LiteralInteger_Ecore_EClass_eAllGenericSuperTypes = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EClass_eAllGenericSuperTypes);
	
	ecore_EClass_eAllGenericSuperTypes_upperValue_LiteralUnlimitedNatural_Ecore_EClass_eAllGenericSuperTypes = factory->createLiteralUnlimitedNatural_as_ownedElement_in_Element(ecore_EClass_eAllGenericSuperTypes);
	
	ecore_EClass_eAllOperations_lowerValue_LiteralInteger_Ecore_EClass_eAllOperations = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EClass_eAllOperations);
	
	ecore_EClass_eAllOperations_upperValue_LiteralUnlimitedNatural_Ecore_EClass_eAllOperations = factory->createLiteralUnlimitedNatural_as_ownedElement_in_Element(ecore_EClass_eAllOperations);
	
	ecore_EClass_eAllReferences_lowerValue_LiteralInteger_Ecore_EClass_eAllReferences = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EClass_eAllReferences);
	
	ecore_EClass_eAllReferences_upperValue_LiteralUnlimitedNatural_Ecore_EClass_eAllReferences = factory->createLiteralUnlimitedNatural_as_ownedElement_in_Element(ecore_EClass_eAllReferences);
	
	ecore_EClass_eAllStructuralFeatures_lowerValue_LiteralInteger_Ecore_EClass_eAllStructuralFeatures = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EClass_eAllStructuralFeatures);
	
	ecore_EClass_eAllStructuralFeatures_upperValue_LiteralUnlimitedNatural_Ecore_EClass_eAllStructuralFeatures = factory->createLiteralUnlimitedNatural_as_ownedElement_in_Element(ecore_EClass_eAllStructuralFeatures);
	
	ecore_EClass_eAllSuperTypes_lowerValue_LiteralInteger_Ecore_EClass_eAllSuperTypes = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EClass_eAllSuperTypes);
	
	ecore_EClass_eAllSuperTypes_upperValue_LiteralUnlimitedNatural_Ecore_EClass_eAllSuperTypes = factory->createLiteralUnlimitedNatural_as_ownedElement_in_Element(ecore_EClass_eAllSuperTypes);
	
	ecore_EClass_eAttributes_lowerValue_LiteralInteger_Ecore_EClass_eAttributes = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EClass_eAttributes);
	
	ecore_EClass_eAttributes_upperValue_LiteralUnlimitedNatural_Ecore_EClass_eAttributes = factory->createLiteralUnlimitedNatural_as_ownedElement_in_Element(ecore_EClass_eAttributes);
	
	ecore_EClass_eGenericSuperTypes_lowerValue_LiteralInteger_Ecore_EClass_eGenericSuperTypes = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EClass_eGenericSuperTypes);
	
	ecore_EClass_eGenericSuperTypes_upperValue_LiteralUnlimitedNatural_Ecore_EClass_eGenericSuperTypes = factory->createLiteralUnlimitedNatural_as_ownedElement_in_Element(ecore_EClass_eGenericSuperTypes);
	
	ecore_EClass_eIDAttribute_lowerValue_LiteralInteger_Ecore_EClass_eIDAttribute = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EClass_eIDAttribute);
	
	ecore_EClass_eOperations_lowerValue_LiteralInteger_Ecore_EClass_eOperations = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EClass_eOperations);
	
	ecore_EClass_eOperations_upperValue_LiteralUnlimitedNatural_Ecore_EClass_eOperations = factory->createLiteralUnlimitedNatural_as_ownedElement_in_Element(ecore_EClass_eOperations);
	
	ecore_EClass_eReferences_lowerValue_LiteralInteger_Ecore_EClass_eReferences = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EClass_eReferences);
	
	ecore_EClass_eReferences_upperValue_LiteralUnlimitedNatural_Ecore_EClass_eReferences = factory->createLiteralUnlimitedNatural_as_ownedElement_in_Element(ecore_EClass_eReferences);
	
	ecore_EClass_eStructuralFeatures_lowerValue_LiteralInteger_Ecore_EClass_eStructuralFeatures = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EClass_eStructuralFeatures);
	
	ecore_EClass_eStructuralFeatures_upperValue_LiteralUnlimitedNatural_Ecore_EClass_eStructuralFeatures = factory->createLiteralUnlimitedNatural_as_ownedElement_in_Element(ecore_EClass_eStructuralFeatures);
	
	ecore_EClass_eSuperTypes_lowerValue_LiteralInteger_Ecore_EClass_eSuperTypes = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EClass_eSuperTypes);
	
	ecore_EClass_eSuperTypes_upperValue_LiteralUnlimitedNatural_Ecore_EClass_eSuperTypes = factory->createLiteralUnlimitedNatural_as_ownedElement_in_Element(ecore_EClass_eSuperTypes);
	
	ecore_EClass_getEStructuralFeature_EInt_EInt_featureID_lowerValue_LiteralInteger_Ecore_EClass_getEStructuralFeature_EInt_EInt_featureID = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EClass_getEStructuralFeature_EInt_EInt_featureID);
	
	ecore_EClass_getEStructuralFeature_EInt_EIntreturn_lowerValue_LiteralInteger_Ecore_EClass_getEStructuralFeature_EInt_EIntreturn = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EClass_getEStructuralFeature_EInt_EIntreturn);
	
	ecore_EClass_getEStructuralFeature_EString_EString_featureName_lowerValue_LiteralInteger_Ecore_EClass_getEStructuralFeature_EString_EString_featureName = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EClass_getEStructuralFeature_EString_EString_featureName);
	
	ecore_EClass_getEStructuralFeature_EString_EStringreturn_lowerValue_LiteralInteger_Ecore_EClass_getEStructuralFeature_EString_EStringreturn = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EClass_getEStructuralFeature_EString_EStringreturn);
	
	ecore_EClass_getFeatureCount__return_lowerValue_LiteralInteger_Ecore_EClass_getFeatureCount__return = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EClass_getFeatureCount__return);
	
	ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeature_feature_lowerValue_LiteralInteger_Ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeature_feature = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeature_feature);
	
	ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeaturereturn_lowerValue_LiteralInteger_Ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeaturereturn = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeaturereturn);
	
	ecore_EClass_interface_lowerValue_LiteralInteger_Ecore_EClass_interface = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EClass_interface);
	
	ecore_EClass_isSuperTypeOf_EClass_EClass_someClass_lowerValue_LiteralInteger_Ecore_EClass_isSuperTypeOf_EClass_EClass_someClass = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EClass_isSuperTypeOf_EClass_EClass_someClass);
	
	ecore_EClass_isSuperTypeOf_EClass_EClassreturn_lowerValue_LiteralInteger_Ecore_EClass_isSuperTypeOf_EClass_EClassreturn = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EClass_isSuperTypeOf_EClass_EClassreturn);
	
	ecore_EClassifier_defaultValue_lowerValue_LiteralInteger_Ecore_EClassifier_defaultValue = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EClassifier_defaultValue);
	
	ecore_EClassifier_ePackage_lowerValue_LiteralInteger_Ecore_EClassifier_ePackage = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EClassifier_ePackage);
	
	ecore_EClassifier_eTypeParameters_lowerValue_LiteralInteger_Ecore_EClassifier_eTypeParameters = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EClassifier_eTypeParameters);
	
	ecore_EClassifier_eTypeParameters_upperValue_LiteralUnlimitedNatural_Ecore_EClassifier_eTypeParameters = factory->createLiteralUnlimitedNatural_as_ownedElement_in_Element(ecore_EClassifier_eTypeParameters);
	
	ecore_EClassifier_getClassifierID__return_lowerValue_LiteralInteger_Ecore_EClassifier_getClassifierID__return = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EClassifier_getClassifierID__return);
	
	ecore_EClassifier_instanceClassName_lowerValue_LiteralInteger_Ecore_EClassifier_instanceClassName = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EClassifier_instanceClassName);
	
	ecore_EClassifier_instanceClass_lowerValue_LiteralInteger_Ecore_EClassifier_instanceClass = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EClassifier_instanceClass);
	
	ecore_EClassifier_instanceTypeName_lowerValue_LiteralInteger_Ecore_EClassifier_instanceTypeName = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EClassifier_instanceTypeName);
	
	ecore_EClassifier_isInstance_EJavaObject_EJavaObject_object_lowerValue_LiteralInteger_Ecore_EClassifier_isInstance_EJavaObject_EJavaObject_object = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EClassifier_isInstance_EJavaObject_EJavaObject_object);
	
	ecore_EClassifier_isInstance_EJavaObject_EJavaObjectreturn_lowerValue_LiteralInteger_Ecore_EClassifier_isInstance_EJavaObject_EJavaObjectreturn = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EClassifier_isInstance_EJavaObject_EJavaObjectreturn);
	
	ecore_EDataType_serializable_lowerValue_LiteralInteger_Ecore_EDataType_serializable = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EDataType_serializable);
	
	ecore_EEnumLiteral_eEnum_lowerValue_LiteralInteger_Ecore_EEnumLiteral_eEnum = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EEnumLiteral_eEnum);
	
	ecore_EEnumLiteral_instance_lowerValue_LiteralInteger_Ecore_EEnumLiteral_instance = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EEnumLiteral_instance);
	
	ecore_EEnumLiteral_literal_lowerValue_LiteralInteger_Ecore_EEnumLiteral_literal = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EEnumLiteral_literal);
	
	ecore_EEnumLiteral_value_lowerValue_LiteralInteger_Ecore_EEnumLiteral_value = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EEnumLiteral_value);
	
	ecore_EEnum_eLiterals_lowerValue_LiteralInteger_Ecore_EEnum_eLiterals = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EEnum_eLiterals);
	
	ecore_EEnum_eLiterals_upperValue_LiteralUnlimitedNatural_Ecore_EEnum_eLiterals = factory->createLiteralUnlimitedNatural_as_ownedElement_in_Element(ecore_EEnum_eLiterals);
	
	ecore_EEnum_getEEnumLiteralByLiteral_EString_EString_literal_lowerValue_LiteralInteger_Ecore_EEnum_getEEnumLiteralByLiteral_EString_EString_literal = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EEnum_getEEnumLiteralByLiteral_EString_EString_literal);
	
	ecore_EEnum_getEEnumLiteralByLiteral_EString_EStringreturn_lowerValue_LiteralInteger_Ecore_EEnum_getEEnumLiteralByLiteral_EString_EStringreturn = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EEnum_getEEnumLiteralByLiteral_EString_EStringreturn);
	
	ecore_EEnum_getEEnumLiteral_EInt_EInt_value_lowerValue_LiteralInteger_Ecore_EEnum_getEEnumLiteral_EInt_EInt_value = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EEnum_getEEnumLiteral_EInt_EInt_value);
	
	ecore_EEnum_getEEnumLiteral_EInt_EIntreturn_lowerValue_LiteralInteger_Ecore_EEnum_getEEnumLiteral_EInt_EIntreturn = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EEnum_getEEnumLiteral_EInt_EIntreturn);
	
	ecore_EEnum_getEEnumLiteral_EString_EString_name_lowerValue_LiteralInteger_Ecore_EEnum_getEEnumLiteral_EString_EString_name = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EEnum_getEEnumLiteral_EString_EString_name);
	
	ecore_EEnum_getEEnumLiteral_EString_EStringreturn_lowerValue_LiteralInteger_Ecore_EEnum_getEEnumLiteral_EString_EStringreturn = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EEnum_getEEnumLiteral_EString_EStringreturn);
	
	ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject_eDataType_lowerValue_LiteralInteger_Ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject_eDataType = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject_eDataType);
	
	ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject_instanceValue_lowerValue_LiteralInteger_Ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject_instanceValue = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject_instanceValue);
	
	ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObjectreturn_lowerValue_LiteralInteger_Ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObjectreturn = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObjectreturn);
	
	ecore_EFactory_createFromString_EDataType_EString_EDataType_EString_eDataType_lowerValue_LiteralInteger_Ecore_EFactory_createFromString_EDataType_EString_EDataType_EString_eDataType = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EFactory_createFromString_EDataType_EString_EDataType_EString_eDataType);
	
	ecore_EFactory_createFromString_EDataType_EString_EDataType_EString_literalValue_lowerValue_LiteralInteger_Ecore_EFactory_createFromString_EDataType_EString_EDataType_EString_literalValue = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EFactory_createFromString_EDataType_EString_EDataType_EString_literalValue);
	
	ecore_EFactory_createFromString_EDataType_EString_EDataType_EStringreturn_lowerValue_LiteralInteger_Ecore_EFactory_createFromString_EDataType_EString_EDataType_EStringreturn = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EFactory_createFromString_EDataType_EString_EDataType_EStringreturn);
	
	ecore_EFactory_create_EClass_EClass_eClass_lowerValue_LiteralInteger_Ecore_EFactory_create_EClass_EClass_eClass = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EFactory_create_EClass_EClass_eClass);
	
	ecore_EFactory_create_EClass_EClassreturn_lowerValue_LiteralInteger_Ecore_EFactory_create_EClass_EClassreturn = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EFactory_create_EClass_EClassreturn);
	
	ecore_EGenericType_eClassifier_lowerValue_LiteralInteger_Ecore_EGenericType_eClassifier = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EGenericType_eClassifier);
	
	ecore_EGenericType_eLowerBound_lowerValue_LiteralInteger_Ecore_EGenericType_eLowerBound = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EGenericType_eLowerBound);
	
	ecore_EGenericType_eTypeArguments_lowerValue_LiteralInteger_Ecore_EGenericType_eTypeArguments = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EGenericType_eTypeArguments);
	
	ecore_EGenericType_eTypeArguments_upperValue_LiteralUnlimitedNatural_Ecore_EGenericType_eTypeArguments = factory->createLiteralUnlimitedNatural_as_ownedElement_in_Element(ecore_EGenericType_eTypeArguments);
	
	ecore_EGenericType_eTypeParameter_lowerValue_LiteralInteger_Ecore_EGenericType_eTypeParameter = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EGenericType_eTypeParameter);
	
	ecore_EGenericType_eUpperBound_lowerValue_LiteralInteger_Ecore_EGenericType_eUpperBound = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EGenericType_eUpperBound);
	
	ecore_EModelElement_eAnnotations_lowerValue_LiteralInteger_Ecore_EModelElement_eAnnotations = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EModelElement_eAnnotations);
	
	ecore_EModelElement_eAnnotations_upperValue_LiteralUnlimitedNatural_Ecore_EModelElement_eAnnotations = factory->createLiteralUnlimitedNatural_as_ownedElement_in_Element(ecore_EModelElement_eAnnotations);
	
	ecore_EModelElement_getEAnnotation_EString_EString_source_lowerValue_LiteralInteger_Ecore_EModelElement_getEAnnotation_EString_EString_source = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EModelElement_getEAnnotation_EString_EString_source);
	
	ecore_EModelElement_getEAnnotation_EString_EStringreturn_lowerValue_LiteralInteger_Ecore_EModelElement_getEAnnotation_EString_EStringreturn = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EModelElement_getEAnnotation_EString_EStringreturn);
	
	ecore_ENamedElement_name_lowerValue_LiteralInteger_Ecore_ENamedElement_name = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_ENamedElement_name);
	
	ecore_EObject_eAllContents__return_lowerValue_LiteralInteger_Ecore_EObject_eAllContents__return = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EObject_eAllContents__return);
	
	ecore_EObject_eClass__return_lowerValue_LiteralInteger_Ecore_EObject_eClass__return = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EObject_eClass__return);
	
	ecore_EObject_eContainer__return_lowerValue_LiteralInteger_Ecore_EObject_eContainer__return = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EObject_eContainer__return);
	
	ecore_EObject_eContainingFeature__return_lowerValue_LiteralInteger_Ecore_EObject_eContainingFeature__return = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EObject_eContainingFeature__return);
	
	ecore_EObject_eContainmentFeature__return_lowerValue_LiteralInteger_Ecore_EObject_eContainmentFeature__return = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EObject_eContainmentFeature__return);
	
	ecore_EObject_eContents__return_lowerValue_LiteralInteger_Ecore_EObject_eContents__return = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EObject_eContents__return);
	
	ecore_EObject_eCrossReferences__return_lowerValue_LiteralInteger_Ecore_EObject_eCrossReferences__return = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EObject_eCrossReferences__return);
	
	ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean_feature_lowerValue_LiteralInteger_Ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean_feature = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean_feature);
	
	ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean_resolve_lowerValue_LiteralInteger_Ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean_resolve = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean_resolve);
	
	ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBooleanreturn_lowerValue_LiteralInteger_Ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBooleanreturn = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBooleanreturn);
	
	ecore_EObject_eGet_EStructuralFeature_EStructuralFeature_feature_lowerValue_LiteralInteger_Ecore_EObject_eGet_EStructuralFeature_EStructuralFeature_feature = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EObject_eGet_EStructuralFeature_EStructuralFeature_feature);
	
	ecore_EObject_eGet_EStructuralFeature_EStructuralFeaturereturn_lowerValue_LiteralInteger_Ecore_EObject_eGet_EStructuralFeature_EStructuralFeaturereturn = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EObject_eGet_EStructuralFeature_EStructuralFeaturereturn);
	
	ecore_EObject_eIsProxy__return_lowerValue_LiteralInteger_Ecore_EObject_eIsProxy__return = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EObject_eIsProxy__return);
	
	ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeature_feature_lowerValue_LiteralInteger_Ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeature_feature = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeature_feature);
	
	ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeaturereturn_lowerValue_LiteralInteger_Ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeaturereturn = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeaturereturn);
	
	ecore_EObject_eResource__return_lowerValue_LiteralInteger_Ecore_EObject_eResource__return = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EObject_eResource__return);
	
	ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject_feature_lowerValue_LiteralInteger_Ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject_feature = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject_feature);
	
	ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject_newValue_lowerValue_LiteralInteger_Ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject_newValue = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject_newValue);
	
	ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObjectreturn_lowerValue_LiteralInteger_Ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObjectreturn = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObjectreturn);
	
	ecore_EObject_eUnset_EStructuralFeature_EStructuralFeature_feature_lowerValue_LiteralInteger_Ecore_EObject_eUnset_EStructuralFeature_EStructuralFeature_feature = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EObject_eUnset_EStructuralFeature_EStructuralFeature_feature);
	
	ecore_EObject_eUnset_EStructuralFeature_EStructuralFeaturereturn_lowerValue_LiteralInteger_Ecore_EObject_eUnset_EStructuralFeature_EStructuralFeaturereturn = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EObject_eUnset_EStructuralFeature_EStructuralFeaturereturn);
	
	ecore_EOperation_eContainingClass_lowerValue_LiteralInteger_Ecore_EOperation_eContainingClass = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EOperation_eContainingClass);
	
	ecore_EOperation_eExceptions_lowerValue_LiteralInteger_Ecore_EOperation_eExceptions = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EOperation_eExceptions);
	
	ecore_EOperation_eExceptions_upperValue_LiteralUnlimitedNatural_Ecore_EOperation_eExceptions = factory->createLiteralUnlimitedNatural_as_ownedElement_in_Element(ecore_EOperation_eExceptions);
	
	ecore_EOperation_eGenericExceptions_lowerValue_LiteralInteger_Ecore_EOperation_eGenericExceptions = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EOperation_eGenericExceptions);
	
	ecore_EOperation_eGenericExceptions_upperValue_LiteralUnlimitedNatural_Ecore_EOperation_eGenericExceptions = factory->createLiteralUnlimitedNatural_as_ownedElement_in_Element(ecore_EOperation_eGenericExceptions);
	
	ecore_EOperation_eParameters_lowerValue_LiteralInteger_Ecore_EOperation_eParameters = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EOperation_eParameters);
	
	ecore_EOperation_eParameters_upperValue_LiteralUnlimitedNatural_Ecore_EOperation_eParameters = factory->createLiteralUnlimitedNatural_as_ownedElement_in_Element(ecore_EOperation_eParameters);
	
	ecore_EOperation_eTypeParameters_lowerValue_LiteralInteger_Ecore_EOperation_eTypeParameters = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EOperation_eTypeParameters);
	
	ecore_EOperation_eTypeParameters_upperValue_LiteralUnlimitedNatural_Ecore_EOperation_eTypeParameters = factory->createLiteralUnlimitedNatural_as_ownedElement_in_Element(ecore_EOperation_eTypeParameters);
	
	ecore_EPackage_eClassifiers_lowerValue_LiteralInteger_Ecore_EPackage_eClassifiers = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EPackage_eClassifiers);
	
	ecore_EPackage_eClassifiers_upperValue_LiteralUnlimitedNatural_Ecore_EPackage_eClassifiers = factory->createLiteralUnlimitedNatural_as_ownedElement_in_Element(ecore_EPackage_eClassifiers);
	
	ecore_EPackage_eSubpackages_lowerValue_LiteralInteger_Ecore_EPackage_eSubpackages = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EPackage_eSubpackages);
	
	ecore_EPackage_eSubpackages_upperValue_LiteralUnlimitedNatural_Ecore_EPackage_eSubpackages = factory->createLiteralUnlimitedNatural_as_ownedElement_in_Element(ecore_EPackage_eSubpackages);
	
	ecore_EPackage_eSuperPackage_lowerValue_LiteralInteger_Ecore_EPackage_eSuperPackage = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EPackage_eSuperPackage);
	
	ecore_EPackage_getEClassifier_EString_EString_name_lowerValue_LiteralInteger_Ecore_EPackage_getEClassifier_EString_EString_name = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EPackage_getEClassifier_EString_EString_name);
	
	ecore_EPackage_getEClassifier_EString_EStringreturn_lowerValue_LiteralInteger_Ecore_EPackage_getEClassifier_EString_EStringreturn = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EPackage_getEClassifier_EString_EStringreturn);
	
	ecore_EPackage_nsPrefix_lowerValue_LiteralInteger_Ecore_EPackage_nsPrefix = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EPackage_nsPrefix);
	
	ecore_EPackage_nsURI_lowerValue_LiteralInteger_Ecore_EPackage_nsURI = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EPackage_nsURI);
	
	ecore_EParameter_eOperation_lowerValue_LiteralInteger_Ecore_EParameter_eOperation = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EParameter_eOperation);
	
	ecore_EReference_container_lowerValue_LiteralInteger_Ecore_EReference_container = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EReference_container);
	
	ecore_EReference_containment_lowerValue_LiteralInteger_Ecore_EReference_containment = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EReference_containment);
	
	ecore_EReference_eKeys_lowerValue_LiteralInteger_Ecore_EReference_eKeys = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EReference_eKeys);
	
	ecore_EReference_eKeys_upperValue_LiteralUnlimitedNatural_Ecore_EReference_eKeys = factory->createLiteralUnlimitedNatural_as_ownedElement_in_Element(ecore_EReference_eKeys);
	
	ecore_EReference_eOpposite_lowerValue_LiteralInteger_Ecore_EReference_eOpposite = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EReference_eOpposite);
	
	ecore_EReference_resolveProxies_lowerValue_LiteralInteger_Ecore_EReference_resolveProxies = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EReference_resolveProxies);
	
	ecore_EStringToStringMapEntry_key_lowerValue_LiteralInteger_Ecore_EStringToStringMapEntry_key = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EStringToStringMapEntry_key);
	
	ecore_EStringToStringMapEntry_value_lowerValue_LiteralInteger_Ecore_EStringToStringMapEntry_value = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EStringToStringMapEntry_value);
	
	ecore_EStructuralFeature_changeable_lowerValue_LiteralInteger_Ecore_EStructuralFeature_changeable = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EStructuralFeature_changeable);
	
	ecore_EStructuralFeature_defaultValueLiteral_lowerValue_LiteralInteger_Ecore_EStructuralFeature_defaultValueLiteral = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EStructuralFeature_defaultValueLiteral);
	
	ecore_EStructuralFeature_defaultValue_lowerValue_LiteralInteger_Ecore_EStructuralFeature_defaultValue = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EStructuralFeature_defaultValue);
	
	ecore_EStructuralFeature_derived_lowerValue_LiteralInteger_Ecore_EStructuralFeature_derived = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EStructuralFeature_derived);
	
	ecore_EStructuralFeature_eContainingClass_lowerValue_LiteralInteger_Ecore_EStructuralFeature_eContainingClass = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EStructuralFeature_eContainingClass);
	
	ecore_EStructuralFeature_getContainerClass__return_lowerValue_LiteralInteger_Ecore_EStructuralFeature_getContainerClass__return = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EStructuralFeature_getContainerClass__return);
	
	ecore_EStructuralFeature_getFeatureID__return_lowerValue_LiteralInteger_Ecore_EStructuralFeature_getFeatureID__return = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EStructuralFeature_getFeatureID__return);
	
	ecore_EStructuralFeature_transient_lowerValue_LiteralInteger_Ecore_EStructuralFeature_transient = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EStructuralFeature_transient);
	
	ecore_EStructuralFeature_unsettable_lowerValue_LiteralInteger_Ecore_EStructuralFeature_unsettable = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EStructuralFeature_unsettable);
	
	ecore_EStructuralFeature_volatile_lowerValue_LiteralInteger_Ecore_EStructuralFeature_volatile = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_EStructuralFeature_volatile);
	
	ecore_ETypeParameter_eBounds_lowerValue_LiteralInteger_Ecore_ETypeParameter_eBounds = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_ETypeParameter_eBounds);
	
	ecore_ETypeParameter_eBounds_upperValue_LiteralUnlimitedNatural_Ecore_ETypeParameter_eBounds = factory->createLiteralUnlimitedNatural_as_ownedElement_in_Element(ecore_ETypeParameter_eBounds);
	
	ecore_ETypedElement_eGenericType_lowerValue_LiteralInteger_Ecore_ETypedElement_eGenericType = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_ETypedElement_eGenericType);
	
	ecore_ETypedElement_eType_lowerValue_LiteralInteger_Ecore_ETypedElement_eType = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_ETypedElement_eType);
	
	ecore_ETypedElement_lowerBound_lowerValue_LiteralInteger_Ecore_ETypedElement_lowerBound = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_ETypedElement_lowerBound);
	
	ecore_ETypedElement_many_lowerValue_LiteralInteger_Ecore_ETypedElement_many = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_ETypedElement_many);
	
	ecore_ETypedElement_ordered_lowerValue_LiteralInteger_Ecore_ETypedElement_ordered = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_ETypedElement_ordered);
	
	ecore_ETypedElement_required_lowerValue_LiteralInteger_Ecore_ETypedElement_required = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_ETypedElement_required);
	
	ecore_ETypedElement_unique_lowerValue_LiteralInteger_Ecore_ETypedElement_unique = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_ETypedElement_unique);
	
	ecore_ETypedElement_upperBound_lowerValue_LiteralInteger_Ecore_ETypedElement_upperBound = factory->createLiteralInteger_as_ownedElement_in_Element(ecore_ETypedElement_upperBound);
	
}

void EcorePackageImpl::initializePackageContents(std::shared_ptr<uml::Package> ecore)
{
	if (isInitialized)
	{
		return;
	}
	isInitialized = true;

	// Initialize package
	this->setName(eNAME);
	this->setURI(eNS_URI);

	initializePackageActivities();
	initializePackageAssociations();
	initializePackageClasses();
	initializePackageDataTypes();
	initializePackageDependencies();
	initializePackageEvents();
	initializePackageInstanceSpecifications();
	initializePackageInterfaceRealizations();
	initializePackageInterfaces();
	initializePackageNestedPackages();
	initializePackageSignals();
	initializePackageStereotypes();
	initializePackageValueSpecifications();
	
}

//ActivityNodes and Edges
void EcorePackageImpl::initializePackageActivities()
{
}


void EcorePackageImpl::initializePackageAssociations()
{
	//
	a_Ecore_EAnnotation_eAnnotations_Ecore_EModelElement_eModelElement->setName("a_Ecore_EAnnotation_eAnnotations_Ecore_EModelElement_eModelElement");
	a_Ecore_EAnnotation_eAnnotations_Ecore_EModelElement_eModelElement->getMemberEnd()->add(get_Ecore_EModelElement_eAnnotations());
	a_Ecore_EAnnotation_eAnnotations_Ecore_EModelElement_eModelElement->getMemberEnd()->add(get_Ecore_EAnnotation_eModelElement());
	

    //-------------------------------------------
	//
	a_Ecore_EAttribute_eAllAttributes_eClass->setName("a_Ecore_EAttribute_eAllAttributes_eClass");
	a_Ecore_EAttribute_eAllAttributes_eClass->getMemberEnd()->add(get_Ecore_EClass_eAllAttributes());
	a_Ecore_EAttribute_eAllAttributes_eClass->getMemberEnd()->add(get_A_Ecore_EAttribute_eAllAttributes_eClass_eClass());
	

    //-------------------------------------------
	//
	a_Ecore_EAttribute_eAttributes_eClass->setName("a_Ecore_EAttribute_eAttributes_eClass");
	a_Ecore_EAttribute_eAttributes_eClass->getMemberEnd()->add(get_Ecore_EClass_eAttributes());
	a_Ecore_EAttribute_eAttributes_eClass->getMemberEnd()->add(get_A_Ecore_EAttribute_eAttributes_eClass_eClass());
	

    //-------------------------------------------
	//
	a_Ecore_EAttribute_eIDAttribute_eClass->setName("a_Ecore_EAttribute_eIDAttribute_eClass");
	a_Ecore_EAttribute_eIDAttribute_eClass->getMemberEnd()->add(get_Ecore_EClass_eIDAttribute());
	a_Ecore_EAttribute_eIDAttribute_eClass->getMemberEnd()->add(get_A_Ecore_EAttribute_eIDAttribute_eClass_eClass());
	

    //-------------------------------------------
	//
	a_Ecore_EAttribute_eKeys_eReference->setName("a_Ecore_EAttribute_eKeys_eReference");
	a_Ecore_EAttribute_eKeys_eReference->getMemberEnd()->add(get_Ecore_EReference_eKeys());
	a_Ecore_EAttribute_eKeys_eReference->getMemberEnd()->add(get_A_Ecore_EAttribute_eKeys_eReference_eReference());
	

    //-------------------------------------------
	//
	a_Ecore_EClass_eAllSuperTypes_eClass->setName("a_Ecore_EClass_eAllSuperTypes_eClass");
	a_Ecore_EClass_eAllSuperTypes_eClass->getMemberEnd()->add(get_Ecore_EClass_eAllSuperTypes());
	a_Ecore_EClass_eAllSuperTypes_eClass->getMemberEnd()->add(get_A_Ecore_EClass_eAllSuperTypes_eClass_eClass());
	

    //-------------------------------------------
	//
	a_Ecore_EClass_eReferenceType_eReference->setName("a_Ecore_EClass_eReferenceType_eReference");
	a_Ecore_EClass_eReferenceType_eReference->getMemberEnd()->add(get_Ecore_EReference_eReferenceType());
	a_Ecore_EClass_eReferenceType_eReference->getMemberEnd()->add(get_A_Ecore_EClass_eReferenceType_eReference_eReference());
	

    //-------------------------------------------
	//
	a_Ecore_EClass_eSuperTypes_eClass->setName("a_Ecore_EClass_eSuperTypes_eClass");
	a_Ecore_EClass_eSuperTypes_eClass->getMemberEnd()->add(get_Ecore_EClass_eSuperTypes());
	a_Ecore_EClass_eSuperTypes_eClass->getMemberEnd()->add(get_A_Ecore_EClass_eSuperTypes_eClass_eClass());
	

    //-------------------------------------------
	//
	a_Ecore_EClassifier_eClassifier_eGenericType->setName("a_Ecore_EClassifier_eClassifier_eGenericType");
	a_Ecore_EClassifier_eClassifier_eGenericType->getMemberEnd()->add(get_Ecore_EGenericType_eClassifier());
	a_Ecore_EClassifier_eClassifier_eGenericType->getMemberEnd()->add(get_A_Ecore_EClassifier_eClassifier_eGenericType_eGenericType());
	

    //-------------------------------------------
	//
	a_Ecore_EClassifier_eClassifiers_Ecore_EPackage_ePackage->setName("a_Ecore_EClassifier_eClassifiers_Ecore_EPackage_ePackage");
	a_Ecore_EClassifier_eClassifiers_Ecore_EPackage_ePackage->getMemberEnd()->add(get_Ecore_EPackage_eClassifiers());
	a_Ecore_EClassifier_eClassifiers_Ecore_EPackage_ePackage->getMemberEnd()->add(get_Ecore_EClassifier_ePackage());
	

    //-------------------------------------------
	//
	a_Ecore_EClassifier_eExceptions_eOperation->setName("a_Ecore_EClassifier_eExceptions_eOperation");
	a_Ecore_EClassifier_eExceptions_eOperation->getMemberEnd()->add(get_Ecore_EOperation_eExceptions());
	a_Ecore_EClassifier_eExceptions_eOperation->getMemberEnd()->add(get_A_Ecore_EClassifier_eExceptions_eOperation_eOperation());
	

    //-------------------------------------------
	//
	a_Ecore_EClassifier_eRawType_eGenericType->setName("a_Ecore_EClassifier_eRawType_eGenericType");
	a_Ecore_EClassifier_eRawType_eGenericType->getMemberEnd()->add(get_Ecore_EGenericType_eRawType());
	a_Ecore_EClassifier_eRawType_eGenericType->getMemberEnd()->add(get_A_Ecore_EClassifier_eRawType_eGenericType_eGenericType());
	

    //-------------------------------------------
	//
	a_Ecore_EClassifier_eType_eTypedElement->setName("a_Ecore_EClassifier_eType_eTypedElement");
	a_Ecore_EClassifier_eType_eTypedElement->getMemberEnd()->add(get_Ecore_ETypedElement_eType());
	a_Ecore_EClassifier_eType_eTypedElement->getMemberEnd()->add(get_A_Ecore_EClassifier_eType_eTypedElement_eTypedElement());
	

    //-------------------------------------------
	//
	a_Ecore_EDataType_eAttributeType_eAttribute->setName("a_Ecore_EDataType_eAttributeType_eAttribute");
	a_Ecore_EDataType_eAttributeType_eAttribute->getMemberEnd()->add(get_Ecore_EAttribute_eAttributeType());
	a_Ecore_EDataType_eAttributeType_eAttribute->getMemberEnd()->add(get_A_Ecore_EDataType_eAttributeType_eAttribute_eAttribute());
	

    //-------------------------------------------
	//
	a_Ecore_EEnumLiteral_eLiterals_Ecore_EEnum_eEnum->setName("a_Ecore_EEnumLiteral_eLiterals_Ecore_EEnum_eEnum");
	a_Ecore_EEnumLiteral_eLiterals_Ecore_EEnum_eEnum->getMemberEnd()->add(get_Ecore_EEnum_eLiterals());
	a_Ecore_EEnumLiteral_eLiterals_Ecore_EEnum_eEnum->getMemberEnd()->add(get_Ecore_EEnumLiteral_eEnum());
	

    //-------------------------------------------
	//
	a_Ecore_EGenericType_eAllGenericSuperTypes_eClass->setName("a_Ecore_EGenericType_eAllGenericSuperTypes_eClass");
	a_Ecore_EGenericType_eAllGenericSuperTypes_eClass->getMemberEnd()->add(get_Ecore_EClass_eAllGenericSuperTypes());
	a_Ecore_EGenericType_eAllGenericSuperTypes_eClass->getMemberEnd()->add(get_A_Ecore_EGenericType_eAllGenericSuperTypes_eClass_eClass());
	

    //-------------------------------------------
	//
	a_Ecore_EGenericType_eBounds_eTypeParameter->setName("a_Ecore_EGenericType_eBounds_eTypeParameter");
	a_Ecore_EGenericType_eBounds_eTypeParameter->getMemberEnd()->add(get_Ecore_ETypeParameter_eBounds());
	a_Ecore_EGenericType_eBounds_eTypeParameter->getMemberEnd()->add(get_A_Ecore_EGenericType_eBounds_eTypeParameter_eTypeParameter());
	

    //-------------------------------------------
	//
	a_Ecore_EGenericType_eGenericExceptions_eOperation->setName("a_Ecore_EGenericType_eGenericExceptions_eOperation");
	a_Ecore_EGenericType_eGenericExceptions_eOperation->getMemberEnd()->add(get_Ecore_EOperation_eGenericExceptions());
	a_Ecore_EGenericType_eGenericExceptions_eOperation->getMemberEnd()->add(get_A_Ecore_EGenericType_eGenericExceptions_eOperation_eOperation());
	

    //-------------------------------------------
	//
	a_Ecore_EGenericType_eGenericSuperTypes_eClass->setName("a_Ecore_EGenericType_eGenericSuperTypes_eClass");
	a_Ecore_EGenericType_eGenericSuperTypes_eClass->getMemberEnd()->add(get_Ecore_EClass_eGenericSuperTypes());
	a_Ecore_EGenericType_eGenericSuperTypes_eClass->getMemberEnd()->add(get_A_Ecore_EGenericType_eGenericSuperTypes_eClass_eClass());
	

    //-------------------------------------------
	//
	a_Ecore_EGenericType_eGenericType_eTypedElement->setName("a_Ecore_EGenericType_eGenericType_eTypedElement");
	a_Ecore_EGenericType_eGenericType_eTypedElement->getMemberEnd()->add(get_Ecore_ETypedElement_eGenericType());
	a_Ecore_EGenericType_eGenericType_eTypedElement->getMemberEnd()->add(get_A_Ecore_EGenericType_eGenericType_eTypedElement_eTypedElement());
	

    //-------------------------------------------
	//
	a_Ecore_EGenericType_eLowerBound_eGenericType->setName("a_Ecore_EGenericType_eLowerBound_eGenericType");
	a_Ecore_EGenericType_eLowerBound_eGenericType->getMemberEnd()->add(get_Ecore_EGenericType_eLowerBound());
	a_Ecore_EGenericType_eLowerBound_eGenericType->getMemberEnd()->add(get_A_Ecore_EGenericType_eLowerBound_eGenericType_eGenericType());
	

    //-------------------------------------------
	//
	a_Ecore_EGenericType_eTypeArguments_eGenericType->setName("a_Ecore_EGenericType_eTypeArguments_eGenericType");
	a_Ecore_EGenericType_eTypeArguments_eGenericType->getMemberEnd()->add(get_Ecore_EGenericType_eTypeArguments());
	a_Ecore_EGenericType_eTypeArguments_eGenericType->getMemberEnd()->add(get_A_Ecore_EGenericType_eTypeArguments_eGenericType_eGenericType());
	

    //-------------------------------------------
	//
	a_Ecore_EGenericType_eUpperBound_eGenericType->setName("a_Ecore_EGenericType_eUpperBound_eGenericType");
	a_Ecore_EGenericType_eUpperBound_eGenericType->getMemberEnd()->add(get_Ecore_EGenericType_eUpperBound());
	a_Ecore_EGenericType_eUpperBound_eGenericType->getMemberEnd()->add(get_A_Ecore_EGenericType_eUpperBound_eGenericType_eGenericType());
	

    //-------------------------------------------
	//
	a_Ecore_EObject_contents_eAnnotation->setName("a_Ecore_EObject_contents_eAnnotation");
	a_Ecore_EObject_contents_eAnnotation->getMemberEnd()->add(get_Ecore_EAnnotation_contents());
	a_Ecore_EObject_contents_eAnnotation->getMemberEnd()->add(get_A_Ecore_EObject_contents_eAnnotation_eAnnotation());
	

    //-------------------------------------------
	//
	a_Ecore_EObject_references_eAnnotation->setName("a_Ecore_EObject_references_eAnnotation");
	a_Ecore_EObject_references_eAnnotation->getMemberEnd()->add(get_Ecore_EAnnotation_references());
	a_Ecore_EObject_references_eAnnotation->getMemberEnd()->add(get_A_Ecore_EObject_references_eAnnotation_eAnnotation());
	

    //-------------------------------------------
	//
	a_Ecore_EOperation_eAllOperations_eClass->setName("a_Ecore_EOperation_eAllOperations_eClass");
	a_Ecore_EOperation_eAllOperations_eClass->getMemberEnd()->add(get_Ecore_EClass_eAllOperations());
	a_Ecore_EOperation_eAllOperations_eClass->getMemberEnd()->add(get_A_Ecore_EOperation_eAllOperations_eClass_eClass());
	

    //-------------------------------------------
	//
	a_Ecore_EOperation_eOperations_Ecore_EClass_eContainingClass->setName("a_Ecore_EOperation_eOperations_Ecore_EClass_eContainingClass");
	a_Ecore_EOperation_eOperations_Ecore_EClass_eContainingClass->getMemberEnd()->add(get_Ecore_EClass_eOperations());
	a_Ecore_EOperation_eOperations_Ecore_EClass_eContainingClass->getMemberEnd()->add(get_Ecore_EOperation_eContainingClass());
	

    //-------------------------------------------
	//
	a_Ecore_EPackage_ePackage_Ecore_EFactory_eFactoryInstance->setName("a_Ecore_EPackage_ePackage_Ecore_EFactory_eFactoryInstance");
	a_Ecore_EPackage_ePackage_Ecore_EFactory_eFactoryInstance->getMemberEnd()->add(get_Ecore_EFactory_ePackage());
	a_Ecore_EPackage_ePackage_Ecore_EFactory_eFactoryInstance->getMemberEnd()->add(get_Ecore_EPackage_eFactoryInstance());
	

    //-------------------------------------------
	//
	a_Ecore_EPackage_eSubpackages_Ecore_EPackage_eSuperPackage->setName("a_Ecore_EPackage_eSubpackages_Ecore_EPackage_eSuperPackage");
	a_Ecore_EPackage_eSubpackages_Ecore_EPackage_eSuperPackage->getMemberEnd()->add(get_Ecore_EPackage_eSubpackages());
	a_Ecore_EPackage_eSubpackages_Ecore_EPackage_eSuperPackage->getMemberEnd()->add(get_Ecore_EPackage_eSuperPackage());
	

    //-------------------------------------------
	//
	a_Ecore_EParameter_eParameters_Ecore_EOperation_eOperation->setName("a_Ecore_EParameter_eParameters_Ecore_EOperation_eOperation");
	a_Ecore_EParameter_eParameters_Ecore_EOperation_eOperation->getMemberEnd()->add(get_Ecore_EOperation_eParameters());
	a_Ecore_EParameter_eParameters_Ecore_EOperation_eOperation->getMemberEnd()->add(get_Ecore_EParameter_eOperation());
	

    //-------------------------------------------
	//
	a_Ecore_EReference_eAllContainments_eClass->setName("a_Ecore_EReference_eAllContainments_eClass");
	a_Ecore_EReference_eAllContainments_eClass->getMemberEnd()->add(get_Ecore_EClass_eAllContainments());
	a_Ecore_EReference_eAllContainments_eClass->getMemberEnd()->add(get_A_Ecore_EReference_eAllContainments_eClass_eClass());
	

    //-------------------------------------------
	//
	a_Ecore_EReference_eAllReferences_eClass->setName("a_Ecore_EReference_eAllReferences_eClass");
	a_Ecore_EReference_eAllReferences_eClass->getMemberEnd()->add(get_Ecore_EClass_eAllReferences());
	a_Ecore_EReference_eAllReferences_eClass->getMemberEnd()->add(get_A_Ecore_EReference_eAllReferences_eClass_eClass());
	

    //-------------------------------------------
	//
	a_Ecore_EReference_eOpposite_eReference->setName("a_Ecore_EReference_eOpposite_eReference");
	a_Ecore_EReference_eOpposite_eReference->getMemberEnd()->add(get_Ecore_EReference_eOpposite());
	a_Ecore_EReference_eOpposite_eReference->getMemberEnd()->add(get_A_Ecore_EReference_eOpposite_eReference_eReference());
	

    //-------------------------------------------
	//
	a_Ecore_EReference_eReferences_eClass->setName("a_Ecore_EReference_eReferences_eClass");
	a_Ecore_EReference_eReferences_eClass->getMemberEnd()->add(get_Ecore_EClass_eReferences());
	a_Ecore_EReference_eReferences_eClass->getMemberEnd()->add(get_A_Ecore_EReference_eReferences_eClass_eClass());
	

    //-------------------------------------------
	//
	a_Ecore_EStringToStringMapEntry_details_eAnnotation->setName("a_Ecore_EStringToStringMapEntry_details_eAnnotation");
	a_Ecore_EStringToStringMapEntry_details_eAnnotation->getMemberEnd()->add(get_Ecore_EAnnotation_details());
	a_Ecore_EStringToStringMapEntry_details_eAnnotation->getMemberEnd()->add(get_A_Ecore_EStringToStringMapEntry_details_eAnnotation_eAnnotation());
	

    //-------------------------------------------
	//
	a_Ecore_EStructuralFeature_eAllStructuralFeatures_eClass->setName("a_Ecore_EStructuralFeature_eAllStructuralFeatures_eClass");
	a_Ecore_EStructuralFeature_eAllStructuralFeatures_eClass->getMemberEnd()->add(get_Ecore_EClass_eAllStructuralFeatures());
	a_Ecore_EStructuralFeature_eAllStructuralFeatures_eClass->getMemberEnd()->add(get_A_Ecore_EStructuralFeature_eAllStructuralFeatures_eClass_eClass());
	

    //-------------------------------------------
	//
	a_Ecore_EStructuralFeature_eStructuralFeatures_Ecore_EClass_eContainingClass->setName("a_Ecore_EStructuralFeature_eStructuralFeatures_Ecore_EClass_eContainingClass");
	a_Ecore_EStructuralFeature_eStructuralFeatures_Ecore_EClass_eContainingClass->getMemberEnd()->add(get_Ecore_EClass_eStructuralFeatures());
	a_Ecore_EStructuralFeature_eStructuralFeatures_Ecore_EClass_eContainingClass->getMemberEnd()->add(get_Ecore_EStructuralFeature_eContainingClass());
	

    //-------------------------------------------
	//
	a_Ecore_ETypeParameter_eTypeParameter_eGenericType->setName("a_Ecore_ETypeParameter_eTypeParameter_eGenericType");
	a_Ecore_ETypeParameter_eTypeParameter_eGenericType->getMemberEnd()->add(get_Ecore_EGenericType_eTypeParameter());
	a_Ecore_ETypeParameter_eTypeParameter_eGenericType->getMemberEnd()->add(get_A_Ecore_ETypeParameter_eTypeParameter_eGenericType_eGenericType());
	

    //-------------------------------------------
	//
	a_Ecore_ETypeParameter_eTypeParameters_eClassifier->setName("a_Ecore_ETypeParameter_eTypeParameters_eClassifier");
	a_Ecore_ETypeParameter_eTypeParameters_eClassifier->getMemberEnd()->add(get_Ecore_EClassifier_eTypeParameters());
	a_Ecore_ETypeParameter_eTypeParameters_eClassifier->getMemberEnd()->add(get_A_Ecore_ETypeParameter_eTypeParameters_eClassifier_eClassifier());
	

    //-------------------------------------------
	//
	a_Ecore_ETypeParameter_eTypeParameters_eOperation->setName("a_Ecore_ETypeParameter_eTypeParameters_eOperation");
	a_Ecore_ETypeParameter_eTypeParameters_eOperation->getMemberEnd()->add(get_Ecore_EOperation_eTypeParameters());
	a_Ecore_ETypeParameter_eTypeParameters_eOperation->getMemberEnd()->add(get_A_Ecore_ETypeParameter_eTypeParameters_eOperation_eOperation());
	
}

void EcorePackageImpl::initializePackageClasses()
{
	std::shared_ptr<uml::Generalization> gen = nullptr;

	//	class EAnnotation
	ecore_EAnnotation->setName("EAnnotation");
	ecore_EAnnotation->setIsAbstract(false);
	
	gen = uml::umlFactory::eInstance()->createGeneralization_as_generalization_in_Classifier(get_Ecore_EAnnotation());
	gen->setGeneral(get_Ecore_EModelElement());
	
    // EAnnotation attributes
	//contents
	ecore_EAnnotation_contents->setName("contents");
	ecore_EAnnotation_contents->setType(get_Ecore_EObject());
	ecore_EAnnotation_contents->setLower(0);
	ecore_EAnnotation_contents->setUpper(-1);
	ecore_EAnnotation_contents->setIsUnique(true);
	ecore_EAnnotation_contents->setAggregation(uml::AggregationKind::COMPOSITE);
	ecore_EAnnotation_contents->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EAnnotation_contents->setAssociation(get_A_Ecore_EObject_contents_eAnnotation());
	
	
	//details
	ecore_EAnnotation_details->setName("details");
	ecore_EAnnotation_details->setType(get_Ecore_EStringToStringMapEntry());
	ecore_EAnnotation_details->setLower(0);
	ecore_EAnnotation_details->setUpper(-1);
	ecore_EAnnotation_details->setIsUnique(true);
	ecore_EAnnotation_details->setAggregation(uml::AggregationKind::COMPOSITE);
	ecore_EAnnotation_details->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EAnnotation_details->setAssociation(get_A_Ecore_EStringToStringMapEntry_details_eAnnotation());
	
	
	//eModelElement
	ecore_EAnnotation_eModelElement->setName("eModelElement");
	ecore_EAnnotation_eModelElement->setType(get_Ecore_EModelElement());
	ecore_EAnnotation_eModelElement->setLower(0);
	ecore_EAnnotation_eModelElement->setUpper(1);
	ecore_EAnnotation_eModelElement->setIsUnique(true);
	ecore_EAnnotation_eModelElement->setAggregation(uml::AggregationKind::NONE);
	ecore_EAnnotation_eModelElement->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EAnnotation_eModelElement->setAssociation(get_A_Ecore_EAnnotation_eAnnotations_Ecore_EModelElement_eModelElement());
	
	
	//references
	ecore_EAnnotation_references->setName("references");
	ecore_EAnnotation_references->setType(get_Ecore_EObject());
	ecore_EAnnotation_references->setLower(0);
	ecore_EAnnotation_references->setUpper(-1);
	ecore_EAnnotation_references->setIsUnique(true);
	ecore_EAnnotation_references->setAggregation(uml::AggregationKind::NONE);
	ecore_EAnnotation_references->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EAnnotation_references->setAssociation(get_A_Ecore_EObject_references_eAnnotation());
	
	
	//source
	ecore_EAnnotation_source->setName("source");
	ecore_EAnnotation_source->setType(get_Ecore_EString());
	ecore_EAnnotation_source->setLower(0);
	ecore_EAnnotation_source->setUpper(1);
	ecore_EAnnotation_source->setIsUnique(true);
	ecore_EAnnotation_source->setAggregation(uml::AggregationKind::NONE);
	ecore_EAnnotation_source->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	


    //-------------------------------------------
	//	class EAttribute
	ecore_EAttribute->setName("EAttribute");
	ecore_EAttribute->setIsAbstract(false);
	
	gen = uml::umlFactory::eInstance()->createGeneralization_as_generalization_in_Classifier(get_Ecore_EAttribute());
	gen->setGeneral(get_Ecore_EStructuralFeature());
	
    // EAttribute attributes
	//eAttributeType
	ecore_EAttribute_eAttributeType->setName("eAttributeType");
	ecore_EAttribute_eAttributeType->setType(get_Ecore_EDataType());
	ecore_EAttribute_eAttributeType->setLower(1);
	ecore_EAttribute_eAttributeType->setUpper(1);
	ecore_EAttribute_eAttributeType->setIsUnique(true);
	ecore_EAttribute_eAttributeType->setAggregation(uml::AggregationKind::NONE);
	ecore_EAttribute_eAttributeType->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EAttribute_eAttributeType->setAssociation(get_A_Ecore_EDataType_eAttributeType_eAttribute());
	
	
	//id
	ecore_EAttribute_id->setName("id");
	ecore_EAttribute_id->setType(get_Ecore_EBoolean());
	ecore_EAttribute_id->setLower(0);
	ecore_EAttribute_id->setUpper(1);
	ecore_EAttribute_id->setIsUnique(true);
	ecore_EAttribute_id->setAggregation(uml::AggregationKind::NONE);
	ecore_EAttribute_id->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	


    //-------------------------------------------
	//	class EClass
	ecore_EClass->setName("EClass");
	ecore_EClass->setIsAbstract(false);
	
	gen = uml::umlFactory::eInstance()->createGeneralization_as_generalization_in_Classifier(get_Ecore_EClass());
	gen->setGeneral(get_Ecore_EClassifier());
	
    // EClass attributes
	//abstract
	ecore_EClass_abstract->setName("abstract");
	ecore_EClass_abstract->setType(get_Ecore_EBoolean());
	ecore_EClass_abstract->setLower(0);
	ecore_EClass_abstract->setUpper(1);
	ecore_EClass_abstract->setIsUnique(true);
	ecore_EClass_abstract->setAggregation(uml::AggregationKind::NONE);
	ecore_EClass_abstract->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	
	//eAllAttributes
	ecore_EClass_eAllAttributes->setName("eAllAttributes");
	ecore_EClass_eAllAttributes->setType(get_Ecore_EAttribute());
	ecore_EClass_eAllAttributes->setLower(0);
	ecore_EClass_eAllAttributes->setUpper(-1);
	ecore_EClass_eAllAttributes->setIsUnique(true);
	ecore_EClass_eAllAttributes->setAggregation(uml::AggregationKind::NONE);
	ecore_EClass_eAllAttributes->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EClass_eAllAttributes->setAssociation(get_A_Ecore_EAttribute_eAllAttributes_eClass());
	
	
	//eAllContainments
	ecore_EClass_eAllContainments->setName("eAllContainments");
	ecore_EClass_eAllContainments->setType(get_Ecore_EReference());
	ecore_EClass_eAllContainments->setLower(0);
	ecore_EClass_eAllContainments->setUpper(-1);
	ecore_EClass_eAllContainments->setIsUnique(true);
	ecore_EClass_eAllContainments->setAggregation(uml::AggregationKind::NONE);
	ecore_EClass_eAllContainments->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EClass_eAllContainments->setAssociation(get_A_Ecore_EReference_eAllContainments_eClass());
	
	
	//eAllGenericSuperTypes
	ecore_EClass_eAllGenericSuperTypes->setName("eAllGenericSuperTypes");
	ecore_EClass_eAllGenericSuperTypes->setType(get_Ecore_EGenericType());
	ecore_EClass_eAllGenericSuperTypes->setLower(0);
	ecore_EClass_eAllGenericSuperTypes->setUpper(-1);
	ecore_EClass_eAllGenericSuperTypes->setIsUnique(true);
	ecore_EClass_eAllGenericSuperTypes->setAggregation(uml::AggregationKind::NONE);
	ecore_EClass_eAllGenericSuperTypes->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EClass_eAllGenericSuperTypes->setAssociation(get_A_Ecore_EGenericType_eAllGenericSuperTypes_eClass());
	
	
	//eAllOperations
	ecore_EClass_eAllOperations->setName("eAllOperations");
	ecore_EClass_eAllOperations->setType(get_Ecore_EOperation());
	ecore_EClass_eAllOperations->setLower(0);
	ecore_EClass_eAllOperations->setUpper(-1);
	ecore_EClass_eAllOperations->setIsUnique(true);
	ecore_EClass_eAllOperations->setAggregation(uml::AggregationKind::NONE);
	ecore_EClass_eAllOperations->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EClass_eAllOperations->setAssociation(get_A_Ecore_EOperation_eAllOperations_eClass());
	
	
	//eAllReferences
	ecore_EClass_eAllReferences->setName("eAllReferences");
	ecore_EClass_eAllReferences->setType(get_Ecore_EReference());
	ecore_EClass_eAllReferences->setLower(0);
	ecore_EClass_eAllReferences->setUpper(-1);
	ecore_EClass_eAllReferences->setIsUnique(true);
	ecore_EClass_eAllReferences->setAggregation(uml::AggregationKind::NONE);
	ecore_EClass_eAllReferences->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EClass_eAllReferences->setAssociation(get_A_Ecore_EReference_eAllReferences_eClass());
	
	
	//eAllStructuralFeatures
	ecore_EClass_eAllStructuralFeatures->setName("eAllStructuralFeatures");
	ecore_EClass_eAllStructuralFeatures->setType(get_Ecore_EStructuralFeature());
	ecore_EClass_eAllStructuralFeatures->setLower(0);
	ecore_EClass_eAllStructuralFeatures->setUpper(-1);
	ecore_EClass_eAllStructuralFeatures->setIsUnique(true);
	ecore_EClass_eAllStructuralFeatures->setAggregation(uml::AggregationKind::NONE);
	ecore_EClass_eAllStructuralFeatures->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EClass_eAllStructuralFeatures->setAssociation(get_A_Ecore_EStructuralFeature_eAllStructuralFeatures_eClass());
	
	
	//eAllSuperTypes
	ecore_EClass_eAllSuperTypes->setName("eAllSuperTypes");
	ecore_EClass_eAllSuperTypes->setType(get_Ecore_EClass());
	ecore_EClass_eAllSuperTypes->setLower(0);
	ecore_EClass_eAllSuperTypes->setUpper(-1);
	ecore_EClass_eAllSuperTypes->setIsUnique(true);
	ecore_EClass_eAllSuperTypes->setAggregation(uml::AggregationKind::NONE);
	ecore_EClass_eAllSuperTypes->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EClass_eAllSuperTypes->setAssociation(get_A_Ecore_EClass_eAllSuperTypes_eClass());
	
	
	//eAttributes
	ecore_EClass_eAttributes->setName("eAttributes");
	ecore_EClass_eAttributes->setType(get_Ecore_EAttribute());
	ecore_EClass_eAttributes->setLower(0);
	ecore_EClass_eAttributes->setUpper(-1);
	ecore_EClass_eAttributes->setIsUnique(true);
	ecore_EClass_eAttributes->setAggregation(uml::AggregationKind::NONE);
	ecore_EClass_eAttributes->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EClass_eAttributes->setAssociation(get_A_Ecore_EAttribute_eAttributes_eClass());
	
	
	//eGenericSuperTypes
	ecore_EClass_eGenericSuperTypes->setName("eGenericSuperTypes");
	ecore_EClass_eGenericSuperTypes->setType(get_Ecore_EGenericType());
	ecore_EClass_eGenericSuperTypes->setLower(0);
	ecore_EClass_eGenericSuperTypes->setUpper(-1);
	ecore_EClass_eGenericSuperTypes->setIsUnique(true);
	ecore_EClass_eGenericSuperTypes->setAggregation(uml::AggregationKind::COMPOSITE);
	ecore_EClass_eGenericSuperTypes->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EClass_eGenericSuperTypes->setAssociation(get_A_Ecore_EGenericType_eGenericSuperTypes_eClass());
	
	
	//eIDAttribute
	ecore_EClass_eIDAttribute->setName("eIDAttribute");
	ecore_EClass_eIDAttribute->setType(get_Ecore_EAttribute());
	ecore_EClass_eIDAttribute->setLower(0);
	ecore_EClass_eIDAttribute->setUpper(1);
	ecore_EClass_eIDAttribute->setIsUnique(true);
	ecore_EClass_eIDAttribute->setAggregation(uml::AggregationKind::NONE);
	ecore_EClass_eIDAttribute->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EClass_eIDAttribute->setAssociation(get_A_Ecore_EAttribute_eIDAttribute_eClass());
	
	
	//eOperations
	ecore_EClass_eOperations->setName("eOperations");
	ecore_EClass_eOperations->setType(get_Ecore_EOperation());
	ecore_EClass_eOperations->setLower(0);
	ecore_EClass_eOperations->setUpper(-1);
	ecore_EClass_eOperations->setIsUnique(true);
	ecore_EClass_eOperations->setAggregation(uml::AggregationKind::COMPOSITE);
	ecore_EClass_eOperations->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EClass_eOperations->setAssociation(get_A_Ecore_EOperation_eOperations_Ecore_EClass_eContainingClass());
	
	
	//eReferences
	ecore_EClass_eReferences->setName("eReferences");
	ecore_EClass_eReferences->setType(get_Ecore_EReference());
	ecore_EClass_eReferences->setLower(0);
	ecore_EClass_eReferences->setUpper(-1);
	ecore_EClass_eReferences->setIsUnique(true);
	ecore_EClass_eReferences->setAggregation(uml::AggregationKind::NONE);
	ecore_EClass_eReferences->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EClass_eReferences->setAssociation(get_A_Ecore_EReference_eReferences_eClass());
	
	
	//eStructuralFeatures
	ecore_EClass_eStructuralFeatures->setName("eStructuralFeatures");
	ecore_EClass_eStructuralFeatures->setType(get_Ecore_EStructuralFeature());
	ecore_EClass_eStructuralFeatures->setLower(0);
	ecore_EClass_eStructuralFeatures->setUpper(-1);
	ecore_EClass_eStructuralFeatures->setIsUnique(true);
	ecore_EClass_eStructuralFeatures->setAggregation(uml::AggregationKind::COMPOSITE);
	ecore_EClass_eStructuralFeatures->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EClass_eStructuralFeatures->setAssociation(get_A_Ecore_EStructuralFeature_eStructuralFeatures_Ecore_EClass_eContainingClass());
	
	
	//eSuperTypes
	ecore_EClass_eSuperTypes->setName("eSuperTypes");
	ecore_EClass_eSuperTypes->setType(get_Ecore_EClass());
	ecore_EClass_eSuperTypes->setLower(0);
	ecore_EClass_eSuperTypes->setUpper(-1);
	ecore_EClass_eSuperTypes->setIsUnique(true);
	ecore_EClass_eSuperTypes->setAggregation(uml::AggregationKind::NONE);
	ecore_EClass_eSuperTypes->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EClass_eSuperTypes->setAssociation(get_A_Ecore_EClass_eSuperTypes_eClass());
	
	
	//interface
	ecore_EClass_interface->setName("interface");
	ecore_EClass_interface->setType(get_Ecore_EBoolean());
	ecore_EClass_interface->setLower(0);
	ecore_EClass_interface->setUpper(1);
	ecore_EClass_interface->setIsUnique(true);
	ecore_EClass_interface->setAggregation(uml::AggregationKind::NONE);
	ecore_EClass_interface->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	

    // EClass operations
	//getEStructuralFeature
	ecore_EClass_getEStructuralFeature_EInt_EInt->setName("getEStructuralFeature");
	ecore_EClass_getEStructuralFeature_EInt_EInt->setType(get_Ecore_EStructuralFeature());
	
	// parameter 
	ecore_EClass_getEStructuralFeature_EInt_EIntreturn->setName("ecore_EClass_getEStructuralFeature_EInt_EIntreturn");
	ecore_EClass_getEStructuralFeature_EInt_EIntreturn->setType(get_Ecore_EStructuralFeature());
	ecore_EClass_getEStructuralFeature_EInt_EIntreturn->setLower(0);
	ecore_EClass_getEStructuralFeature_EInt_EIntreturn->setUpper(1);
	ecore_EClass_getEStructuralFeature_EInt_EIntreturn->setDirection(uml::ParameterDirectionKind::RETURN);
	
	
	// parameter featureID
	
	ecore_EClass_getEStructuralFeature_EInt_EInt_featureID->setName("featureID");
	
	ecore_EClass_getEStructuralFeature_EInt_EInt_featureID->setType(get_Ecore_EInt());
	
	ecore_EClass_getEStructuralFeature_EInt_EInt_featureID->setLower(0);
	
	ecore_EClass_getEStructuralFeature_EInt_EInt_featureID->setUpper(1);
	
	ecore_EClass_getEStructuralFeature_EInt_EInt_featureID->setDirection(uml::ParameterDirectionKind::IN);
	
	
	

	//getEStructuralFeature
	ecore_EClass_getEStructuralFeature_EString_EString->setName("getEStructuralFeature");
	ecore_EClass_getEStructuralFeature_EString_EString->setType(get_Ecore_EStructuralFeature());
	
	// parameter 
	ecore_EClass_getEStructuralFeature_EString_EStringreturn->setName("ecore_EClass_getEStructuralFeature_EString_EStringreturn");
	ecore_EClass_getEStructuralFeature_EString_EStringreturn->setType(get_Ecore_EStructuralFeature());
	ecore_EClass_getEStructuralFeature_EString_EStringreturn->setLower(0);
	ecore_EClass_getEStructuralFeature_EString_EStringreturn->setUpper(1);
	ecore_EClass_getEStructuralFeature_EString_EStringreturn->setDirection(uml::ParameterDirectionKind::RETURN);
	
	
	// parameter featureName
	
	ecore_EClass_getEStructuralFeature_EString_EString_featureName->setName("featureName");
	
	ecore_EClass_getEStructuralFeature_EString_EString_featureName->setType(get_Ecore_EString());
	
	ecore_EClass_getEStructuralFeature_EString_EString_featureName->setLower(0);
	
	ecore_EClass_getEStructuralFeature_EString_EString_featureName->setUpper(1);
	
	ecore_EClass_getEStructuralFeature_EString_EString_featureName->setDirection(uml::ParameterDirectionKind::IN);
	
	
	

	//getFeatureCount
	ecore_EClass_getFeatureCount__->setName("getFeatureCount");
	ecore_EClass_getFeatureCount__->setType(get_Ecore_EInt());
	
	// parameter 
	ecore_EClass_getFeatureCount__return->setName("ecore_EClass_getFeatureCount__return");
	ecore_EClass_getFeatureCount__return->setType(get_Ecore_EInt());
	ecore_EClass_getFeatureCount__return->setLower(0);
	ecore_EClass_getFeatureCount__return->setUpper(1);
	ecore_EClass_getFeatureCount__return->setDirection(uml::ParameterDirectionKind::RETURN);
	
	

	//getFeatureID
	ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeature->setName("getFeatureID");
	ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeature->setType(get_Ecore_EInt());
	
	// parameter 
	ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeaturereturn->setName("ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeaturereturn");
	ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeaturereturn->setType(get_Ecore_EInt());
	ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeaturereturn->setLower(0);
	ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeaturereturn->setUpper(1);
	ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeaturereturn->setDirection(uml::ParameterDirectionKind::RETURN);
	
	
	// parameter feature
	
	ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeature_feature->setName("feature");
	
	ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeature_feature->setType(get_Ecore_EStructuralFeature());
	
	ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeature_feature->setLower(0);
	
	ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeature_feature->setUpper(1);
	
	ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeature_feature->setDirection(uml::ParameterDirectionKind::IN);
	
	
	

	//isSuperTypeOf
	ecore_EClass_isSuperTypeOf_EClass_EClass->setName("isSuperTypeOf");
	ecore_EClass_isSuperTypeOf_EClass_EClass->setType(get_Ecore_EBoolean());
	
	// parameter 
	ecore_EClass_isSuperTypeOf_EClass_EClassreturn->setName("ecore_EClass_isSuperTypeOf_EClass_EClassreturn");
	ecore_EClass_isSuperTypeOf_EClass_EClassreturn->setType(get_Ecore_EBoolean());
	ecore_EClass_isSuperTypeOf_EClass_EClassreturn->setLower(0);
	ecore_EClass_isSuperTypeOf_EClass_EClassreturn->setUpper(1);
	ecore_EClass_isSuperTypeOf_EClass_EClassreturn->setDirection(uml::ParameterDirectionKind::RETURN);
	
	
	// parameter someClass
	
	ecore_EClass_isSuperTypeOf_EClass_EClass_someClass->setName("someClass");
	
	ecore_EClass_isSuperTypeOf_EClass_EClass_someClass->setType(get_Ecore_EClass());
	
	ecore_EClass_isSuperTypeOf_EClass_EClass_someClass->setLower(0);
	
	ecore_EClass_isSuperTypeOf_EClass_EClass_someClass->setUpper(1);
	
	ecore_EClass_isSuperTypeOf_EClass_EClass_someClass->setDirection(uml::ParameterDirectionKind::IN);
	
	
	

    //-------------------------------------------
	//	class EClassifier
	ecore_EClassifier->setName("EClassifier");
	ecore_EClassifier->setIsAbstract(true);
	
	gen = uml::umlFactory::eInstance()->createGeneralization_as_generalization_in_Classifier(get_Ecore_EClassifier());
	gen->setGeneral(get_Ecore_ENamedElement());
	
    // EClassifier attributes
	//defaultValue
	ecore_EClassifier_defaultValue->setName("defaultValue");
	ecore_EClassifier_defaultValue->setType(get_Ecore_EJavaObject());
	ecore_EClassifier_defaultValue->setLower(0);
	ecore_EClassifier_defaultValue->setUpper(1);
	ecore_EClassifier_defaultValue->setIsUnique(true);
	ecore_EClassifier_defaultValue->setAggregation(uml::AggregationKind::NONE);
	ecore_EClassifier_defaultValue->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	
	//ePackage
	ecore_EClassifier_ePackage->setName("ePackage");
	ecore_EClassifier_ePackage->setType(get_Ecore_EPackage());
	ecore_EClassifier_ePackage->setLower(0);
	ecore_EClassifier_ePackage->setUpper(1);
	ecore_EClassifier_ePackage->setIsUnique(true);
	ecore_EClassifier_ePackage->setAggregation(uml::AggregationKind::NONE);
	ecore_EClassifier_ePackage->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EClassifier_ePackage->setAssociation(get_A_Ecore_EClassifier_eClassifiers_Ecore_EPackage_ePackage());
	
	
	//eTypeParameters
	ecore_EClassifier_eTypeParameters->setName("eTypeParameters");
	ecore_EClassifier_eTypeParameters->setType(get_Ecore_ETypeParameter());
	ecore_EClassifier_eTypeParameters->setLower(0);
	ecore_EClassifier_eTypeParameters->setUpper(-1);
	ecore_EClassifier_eTypeParameters->setIsUnique(true);
	ecore_EClassifier_eTypeParameters->setAggregation(uml::AggregationKind::COMPOSITE);
	ecore_EClassifier_eTypeParameters->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EClassifier_eTypeParameters->setAssociation(get_A_Ecore_ETypeParameter_eTypeParameters_eClassifier());
	
	
	//instanceClass
	ecore_EClassifier_instanceClass->setName("instanceClass");
	ecore_EClassifier_instanceClass->setType(get_Ecore_EClassifier_EJavaClass_Wildcard());
	ecore_EClassifier_instanceClass->setLower(0);
	ecore_EClassifier_instanceClass->setUpper(1);
	ecore_EClassifier_instanceClass->setIsUnique(true);
	ecore_EClassifier_instanceClass->setAggregation(uml::AggregationKind::NONE);
	ecore_EClassifier_instanceClass->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	
	//instanceClassName
	ecore_EClassifier_instanceClassName->setName("instanceClassName");
	ecore_EClassifier_instanceClassName->setType(get_Ecore_EString());
	ecore_EClassifier_instanceClassName->setLower(0);
	ecore_EClassifier_instanceClassName->setUpper(1);
	ecore_EClassifier_instanceClassName->setIsUnique(true);
	ecore_EClassifier_instanceClassName->setAggregation(uml::AggregationKind::NONE);
	ecore_EClassifier_instanceClassName->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	
	//instanceTypeName
	ecore_EClassifier_instanceTypeName->setName("instanceTypeName");
	ecore_EClassifier_instanceTypeName->setType(get_Ecore_EString());
	ecore_EClassifier_instanceTypeName->setLower(0);
	ecore_EClassifier_instanceTypeName->setUpper(1);
	ecore_EClassifier_instanceTypeName->setIsUnique(true);
	ecore_EClassifier_instanceTypeName->setAggregation(uml::AggregationKind::NONE);
	ecore_EClassifier_instanceTypeName->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	

    // EClassifier operations
	//getClassifierID
	ecore_EClassifier_getClassifierID__->setName("getClassifierID");
	ecore_EClassifier_getClassifierID__->setType(get_Ecore_EInt());
	
	// parameter 
	ecore_EClassifier_getClassifierID__return->setName("ecore_EClassifier_getClassifierID__return");
	ecore_EClassifier_getClassifierID__return->setType(get_Ecore_EInt());
	ecore_EClassifier_getClassifierID__return->setLower(0);
	ecore_EClassifier_getClassifierID__return->setUpper(1);
	ecore_EClassifier_getClassifierID__return->setDirection(uml::ParameterDirectionKind::RETURN);
	
	

	//isInstance
	ecore_EClassifier_isInstance_EJavaObject_EJavaObject->setName("isInstance");
	ecore_EClassifier_isInstance_EJavaObject_EJavaObject->setType(get_Ecore_EBoolean());
	
	// parameter 
	ecore_EClassifier_isInstance_EJavaObject_EJavaObjectreturn->setName("ecore_EClassifier_isInstance_EJavaObject_EJavaObjectreturn");
	ecore_EClassifier_isInstance_EJavaObject_EJavaObjectreturn->setType(get_Ecore_EBoolean());
	ecore_EClassifier_isInstance_EJavaObject_EJavaObjectreturn->setLower(0);
	ecore_EClassifier_isInstance_EJavaObject_EJavaObjectreturn->setUpper(1);
	ecore_EClassifier_isInstance_EJavaObject_EJavaObjectreturn->setDirection(uml::ParameterDirectionKind::RETURN);
	
	
	// parameter object
	
	ecore_EClassifier_isInstance_EJavaObject_EJavaObject_object->setName("object");
	
	ecore_EClassifier_isInstance_EJavaObject_EJavaObject_object->setType(get_Ecore_EJavaObject());
	
	ecore_EClassifier_isInstance_EJavaObject_EJavaObject_object->setLower(0);
	
	ecore_EClassifier_isInstance_EJavaObject_EJavaObject_object->setUpper(1);
	
	ecore_EClassifier_isInstance_EJavaObject_EJavaObject_object->setDirection(uml::ParameterDirectionKind::IN);
	
	
	

    //-------------------------------------------
	//	class EDataType
	ecore_EDataType->setName("EDataType");
	ecore_EDataType->setIsAbstract(false);
	
	gen = uml::umlFactory::eInstance()->createGeneralization_as_generalization_in_Classifier(get_Ecore_EDataType());
	gen->setGeneral(get_Ecore_EClassifier());
	
    // EDataType attributes
	//serializable
	ecore_EDataType_serializable->setName("serializable");
	ecore_EDataType_serializable->setType(get_Ecore_EBoolean());
	ecore_EDataType_serializable->setLower(0);
	ecore_EDataType_serializable->setUpper(1);
	ecore_EDataType_serializable->setIsUnique(true);
	ecore_EDataType_serializable->setAggregation(uml::AggregationKind::NONE);
	ecore_EDataType_serializable->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	


    //-------------------------------------------
	//	class EEnum
	ecore_EEnum->setName("EEnum");
	ecore_EEnum->setIsAbstract(false);
	
	gen = uml::umlFactory::eInstance()->createGeneralization_as_generalization_in_Classifier(get_Ecore_EEnum());
	gen->setGeneral(get_Ecore_EDataType());
	
    // EEnum attributes
	//eLiterals
	ecore_EEnum_eLiterals->setName("eLiterals");
	ecore_EEnum_eLiterals->setType(get_Ecore_EEnumLiteral());
	ecore_EEnum_eLiterals->setLower(0);
	ecore_EEnum_eLiterals->setUpper(-1);
	ecore_EEnum_eLiterals->setIsUnique(true);
	ecore_EEnum_eLiterals->setAggregation(uml::AggregationKind::COMPOSITE);
	ecore_EEnum_eLiterals->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EEnum_eLiterals->setAssociation(get_A_Ecore_EEnumLiteral_eLiterals_Ecore_EEnum_eEnum());
	
	

    // EEnum operations
	//getEEnumLiteral
	ecore_EEnum_getEEnumLiteral_EString_EString->setName("getEEnumLiteral");
	ecore_EEnum_getEEnumLiteral_EString_EString->setType(get_Ecore_EEnumLiteral());
	
	// parameter 
	ecore_EEnum_getEEnumLiteral_EString_EStringreturn->setName("ecore_EEnum_getEEnumLiteral_EString_EStringreturn");
	ecore_EEnum_getEEnumLiteral_EString_EStringreturn->setType(get_Ecore_EEnumLiteral());
	ecore_EEnum_getEEnumLiteral_EString_EStringreturn->setLower(0);
	ecore_EEnum_getEEnumLiteral_EString_EStringreturn->setUpper(1);
	ecore_EEnum_getEEnumLiteral_EString_EStringreturn->setDirection(uml::ParameterDirectionKind::RETURN);
	
	
	// parameter name
	
	ecore_EEnum_getEEnumLiteral_EString_EString_name->setName("name");
	
	ecore_EEnum_getEEnumLiteral_EString_EString_name->setType(get_Ecore_EString());
	
	ecore_EEnum_getEEnumLiteral_EString_EString_name->setLower(0);
	
	ecore_EEnum_getEEnumLiteral_EString_EString_name->setUpper(1);
	
	ecore_EEnum_getEEnumLiteral_EString_EString_name->setDirection(uml::ParameterDirectionKind::IN);
	
	
	

	//getEEnumLiteral
	ecore_EEnum_getEEnumLiteral_EInt_EInt->setName("getEEnumLiteral");
	ecore_EEnum_getEEnumLiteral_EInt_EInt->setType(get_Ecore_EEnumLiteral());
	
	// parameter 
	ecore_EEnum_getEEnumLiteral_EInt_EIntreturn->setName("ecore_EEnum_getEEnumLiteral_EInt_EIntreturn");
	ecore_EEnum_getEEnumLiteral_EInt_EIntreturn->setType(get_Ecore_EEnumLiteral());
	ecore_EEnum_getEEnumLiteral_EInt_EIntreturn->setLower(0);
	ecore_EEnum_getEEnumLiteral_EInt_EIntreturn->setUpper(1);
	ecore_EEnum_getEEnumLiteral_EInt_EIntreturn->setDirection(uml::ParameterDirectionKind::RETURN);
	
	
	// parameter value
	
	ecore_EEnum_getEEnumLiteral_EInt_EInt_value->setName("value");
	
	ecore_EEnum_getEEnumLiteral_EInt_EInt_value->setType(get_Ecore_EInt());
	
	ecore_EEnum_getEEnumLiteral_EInt_EInt_value->setLower(0);
	
	ecore_EEnum_getEEnumLiteral_EInt_EInt_value->setUpper(1);
	
	ecore_EEnum_getEEnumLiteral_EInt_EInt_value->setDirection(uml::ParameterDirectionKind::IN);
	
	
	

	//getEEnumLiteralByLiteral
	ecore_EEnum_getEEnumLiteralByLiteral_EString_EString->setName("getEEnumLiteralByLiteral");
	ecore_EEnum_getEEnumLiteralByLiteral_EString_EString->setType(get_Ecore_EEnumLiteral());
	
	// parameter 
	ecore_EEnum_getEEnumLiteralByLiteral_EString_EStringreturn->setName("ecore_EEnum_getEEnumLiteralByLiteral_EString_EStringreturn");
	ecore_EEnum_getEEnumLiteralByLiteral_EString_EStringreturn->setType(get_Ecore_EEnumLiteral());
	ecore_EEnum_getEEnumLiteralByLiteral_EString_EStringreturn->setLower(0);
	ecore_EEnum_getEEnumLiteralByLiteral_EString_EStringreturn->setUpper(1);
	ecore_EEnum_getEEnumLiteralByLiteral_EString_EStringreturn->setDirection(uml::ParameterDirectionKind::RETURN);
	
	
	// parameter literal
	
	ecore_EEnum_getEEnumLiteralByLiteral_EString_EString_literal->setName("literal");
	
	ecore_EEnum_getEEnumLiteralByLiteral_EString_EString_literal->setType(get_Ecore_EString());
	
	ecore_EEnum_getEEnumLiteralByLiteral_EString_EString_literal->setLower(0);
	
	ecore_EEnum_getEEnumLiteralByLiteral_EString_EString_literal->setUpper(1);
	
	ecore_EEnum_getEEnumLiteralByLiteral_EString_EString_literal->setDirection(uml::ParameterDirectionKind::IN);
	
	
	

    //-------------------------------------------
	//	class EEnumLiteral
	ecore_EEnumLiteral->setName("EEnumLiteral");
	ecore_EEnumLiteral->setIsAbstract(false);
	
	gen = uml::umlFactory::eInstance()->createGeneralization_as_generalization_in_Classifier(get_Ecore_EEnumLiteral());
	gen->setGeneral(get_Ecore_ENamedElement());
	
    // EEnumLiteral attributes
	//eEnum
	ecore_EEnumLiteral_eEnum->setName("eEnum");
	ecore_EEnumLiteral_eEnum->setType(get_Ecore_EEnum());
	ecore_EEnumLiteral_eEnum->setLower(0);
	ecore_EEnumLiteral_eEnum->setUpper(1);
	ecore_EEnumLiteral_eEnum->setIsUnique(true);
	ecore_EEnumLiteral_eEnum->setAggregation(uml::AggregationKind::NONE);
	ecore_EEnumLiteral_eEnum->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EEnumLiteral_eEnum->setAssociation(get_A_Ecore_EEnumLiteral_eLiterals_Ecore_EEnum_eEnum());
	
	
	//instance
	ecore_EEnumLiteral_instance->setName("instance");
	ecore_EEnumLiteral_instance->setType(get_Ecore_EEnumerator());
	ecore_EEnumLiteral_instance->setLower(0);
	ecore_EEnumLiteral_instance->setUpper(1);
	ecore_EEnumLiteral_instance->setIsUnique(true);
	ecore_EEnumLiteral_instance->setAggregation(uml::AggregationKind::NONE);
	ecore_EEnumLiteral_instance->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	
	//literal
	ecore_EEnumLiteral_literal->setName("literal");
	ecore_EEnumLiteral_literal->setType(get_Ecore_EString());
	ecore_EEnumLiteral_literal->setLower(0);
	ecore_EEnumLiteral_literal->setUpper(1);
	ecore_EEnumLiteral_literal->setIsUnique(true);
	ecore_EEnumLiteral_literal->setAggregation(uml::AggregationKind::NONE);
	ecore_EEnumLiteral_literal->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	
	//value
	ecore_EEnumLiteral_value->setName("value");
	ecore_EEnumLiteral_value->setType(get_Ecore_EInt());
	ecore_EEnumLiteral_value->setLower(0);
	ecore_EEnumLiteral_value->setUpper(1);
	ecore_EEnumLiteral_value->setIsUnique(true);
	ecore_EEnumLiteral_value->setAggregation(uml::AggregationKind::NONE);
	ecore_EEnumLiteral_value->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	


    //-------------------------------------------
	//	class EFactory
	ecore_EFactory->setName("EFactory");
	ecore_EFactory->setIsAbstract(false);
	
	gen = uml::umlFactory::eInstance()->createGeneralization_as_generalization_in_Classifier(get_Ecore_EFactory());
	gen->setGeneral(get_Ecore_EModelElement());
	
    // EFactory attributes
	//ePackage
	ecore_EFactory_ePackage->setName("ePackage");
	ecore_EFactory_ePackage->setType(get_Ecore_EPackage());
	ecore_EFactory_ePackage->setLower(1);
	ecore_EFactory_ePackage->setUpper(1);
	ecore_EFactory_ePackage->setIsUnique(true);
	ecore_EFactory_ePackage->setAggregation(uml::AggregationKind::NONE);
	ecore_EFactory_ePackage->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EFactory_ePackage->setAssociation(get_A_Ecore_EPackage_ePackage_Ecore_EFactory_eFactoryInstance());
	
	

    // EFactory operations
	//convertToString
	ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject->setName("convertToString");
	ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject->setType(get_Ecore_EString());
	
	// parameter 
	ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObjectreturn->setName("ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObjectreturn");
	ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObjectreturn->setType(get_Ecore_EString());
	ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObjectreturn->setLower(0);
	ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObjectreturn->setUpper(1);
	ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObjectreturn->setDirection(uml::ParameterDirectionKind::RETURN);
	
	
	// parameter eDataType
	
	ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject_eDataType->setName("eDataType");
	
	ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject_eDataType->setType(get_Ecore_EDataType());
	
	ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject_eDataType->setLower(0);
	
	ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject_eDataType->setUpper(1);
	
	ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject_eDataType->setDirection(uml::ParameterDirectionKind::IN);
	
	
	
	// parameter instanceValue
	
	ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject_instanceValue->setName("instanceValue");
	
	ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject_instanceValue->setType(get_Ecore_EJavaObject());
	
	ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject_instanceValue->setLower(0);
	
	ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject_instanceValue->setUpper(1);
	
	ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject_instanceValue->setDirection(uml::ParameterDirectionKind::IN);
	
	
	

	//create
	ecore_EFactory_create_EClass_EClass->setName("create");
	ecore_EFactory_create_EClass_EClass->setType(get_Ecore_EObject());
	
	// parameter 
	ecore_EFactory_create_EClass_EClassreturn->setName("ecore_EFactory_create_EClass_EClassreturn");
	ecore_EFactory_create_EClass_EClassreturn->setType(get_Ecore_EObject());
	ecore_EFactory_create_EClass_EClassreturn->setLower(0);
	ecore_EFactory_create_EClass_EClassreturn->setUpper(1);
	ecore_EFactory_create_EClass_EClassreturn->setDirection(uml::ParameterDirectionKind::RETURN);
	
	
	// parameter eClass
	
	ecore_EFactory_create_EClass_EClass_eClass->setName("eClass");
	
	ecore_EFactory_create_EClass_EClass_eClass->setType(get_Ecore_EClass());
	
	ecore_EFactory_create_EClass_EClass_eClass->setLower(0);
	
	ecore_EFactory_create_EClass_EClass_eClass->setUpper(1);
	
	ecore_EFactory_create_EClass_EClass_eClass->setDirection(uml::ParameterDirectionKind::IN);
	
	
	

	//createFromString
	ecore_EFactory_createFromString_EDataType_EString_EDataType_EString->setName("createFromString");
	ecore_EFactory_createFromString_EDataType_EString_EDataType_EString->setType(get_Ecore_EJavaObject());
	
	// parameter 
	ecore_EFactory_createFromString_EDataType_EString_EDataType_EStringreturn->setName("ecore_EFactory_createFromString_EDataType_EString_EDataType_EStringreturn");
	ecore_EFactory_createFromString_EDataType_EString_EDataType_EStringreturn->setType(get_Ecore_EJavaObject());
	ecore_EFactory_createFromString_EDataType_EString_EDataType_EStringreturn->setLower(0);
	ecore_EFactory_createFromString_EDataType_EString_EDataType_EStringreturn->setUpper(1);
	ecore_EFactory_createFromString_EDataType_EString_EDataType_EStringreturn->setDirection(uml::ParameterDirectionKind::RETURN);
	
	
	// parameter eDataType
	
	ecore_EFactory_createFromString_EDataType_EString_EDataType_EString_eDataType->setName("eDataType");
	
	ecore_EFactory_createFromString_EDataType_EString_EDataType_EString_eDataType->setType(get_Ecore_EDataType());
	
	ecore_EFactory_createFromString_EDataType_EString_EDataType_EString_eDataType->setLower(0);
	
	ecore_EFactory_createFromString_EDataType_EString_EDataType_EString_eDataType->setUpper(1);
	
	ecore_EFactory_createFromString_EDataType_EString_EDataType_EString_eDataType->setDirection(uml::ParameterDirectionKind::IN);
	
	
	
	// parameter literalValue
	
	ecore_EFactory_createFromString_EDataType_EString_EDataType_EString_literalValue->setName("literalValue");
	
	ecore_EFactory_createFromString_EDataType_EString_EDataType_EString_literalValue->setType(get_Ecore_EString());
	
	ecore_EFactory_createFromString_EDataType_EString_EDataType_EString_literalValue->setLower(0);
	
	ecore_EFactory_createFromString_EDataType_EString_EDataType_EString_literalValue->setUpper(1);
	
	ecore_EFactory_createFromString_EDataType_EString_EDataType_EString_literalValue->setDirection(uml::ParameterDirectionKind::IN);
	
	
	

    //-------------------------------------------
	//	class EGenericType
	ecore_EGenericType->setName("EGenericType");
	ecore_EGenericType->setIsAbstract(false);
	
	gen = uml::umlFactory::eInstance()->createGeneralization_as_generalization_in_Classifier(get_Ecore_EGenericType());
	gen->setGeneral(get_Ecore_EObject());
	
    // EGenericType attributes
	//eClassifier
	ecore_EGenericType_eClassifier->setName("eClassifier");
	ecore_EGenericType_eClassifier->setType(get_Ecore_EClassifier());
	ecore_EGenericType_eClassifier->setLower(0);
	ecore_EGenericType_eClassifier->setUpper(1);
	ecore_EGenericType_eClassifier->setIsUnique(true);
	ecore_EGenericType_eClassifier->setAggregation(uml::AggregationKind::NONE);
	ecore_EGenericType_eClassifier->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EGenericType_eClassifier->setAssociation(get_A_Ecore_EClassifier_eClassifier_eGenericType());
	
	
	//eLowerBound
	ecore_EGenericType_eLowerBound->setName("eLowerBound");
	ecore_EGenericType_eLowerBound->setType(get_Ecore_EGenericType());
	ecore_EGenericType_eLowerBound->setLower(0);
	ecore_EGenericType_eLowerBound->setUpper(1);
	ecore_EGenericType_eLowerBound->setIsUnique(true);
	ecore_EGenericType_eLowerBound->setAggregation(uml::AggregationKind::COMPOSITE);
	ecore_EGenericType_eLowerBound->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EGenericType_eLowerBound->setAssociation(get_A_Ecore_EGenericType_eLowerBound_eGenericType());
	
	
	//eRawType
	ecore_EGenericType_eRawType->setName("eRawType");
	ecore_EGenericType_eRawType->setType(get_Ecore_EClassifier());
	ecore_EGenericType_eRawType->setLower(1);
	ecore_EGenericType_eRawType->setUpper(1);
	ecore_EGenericType_eRawType->setIsUnique(true);
	ecore_EGenericType_eRawType->setAggregation(uml::AggregationKind::NONE);
	ecore_EGenericType_eRawType->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EGenericType_eRawType->setAssociation(get_A_Ecore_EClassifier_eRawType_eGenericType());
	
	
	//eTypeArguments
	ecore_EGenericType_eTypeArguments->setName("eTypeArguments");
	ecore_EGenericType_eTypeArguments->setType(get_Ecore_EGenericType());
	ecore_EGenericType_eTypeArguments->setLower(0);
	ecore_EGenericType_eTypeArguments->setUpper(-1);
	ecore_EGenericType_eTypeArguments->setIsUnique(true);
	ecore_EGenericType_eTypeArguments->setAggregation(uml::AggregationKind::COMPOSITE);
	ecore_EGenericType_eTypeArguments->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EGenericType_eTypeArguments->setAssociation(get_A_Ecore_EGenericType_eTypeArguments_eGenericType());
	
	
	//eTypeParameter
	ecore_EGenericType_eTypeParameter->setName("eTypeParameter");
	ecore_EGenericType_eTypeParameter->setType(get_Ecore_ETypeParameter());
	ecore_EGenericType_eTypeParameter->setLower(0);
	ecore_EGenericType_eTypeParameter->setUpper(1);
	ecore_EGenericType_eTypeParameter->setIsUnique(true);
	ecore_EGenericType_eTypeParameter->setAggregation(uml::AggregationKind::NONE);
	ecore_EGenericType_eTypeParameter->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EGenericType_eTypeParameter->setAssociation(get_A_Ecore_ETypeParameter_eTypeParameter_eGenericType());
	
	
	//eUpperBound
	ecore_EGenericType_eUpperBound->setName("eUpperBound");
	ecore_EGenericType_eUpperBound->setType(get_Ecore_EGenericType());
	ecore_EGenericType_eUpperBound->setLower(0);
	ecore_EGenericType_eUpperBound->setUpper(1);
	ecore_EGenericType_eUpperBound->setIsUnique(true);
	ecore_EGenericType_eUpperBound->setAggregation(uml::AggregationKind::COMPOSITE);
	ecore_EGenericType_eUpperBound->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EGenericType_eUpperBound->setAssociation(get_A_Ecore_EGenericType_eUpperBound_eGenericType());
	
	


    //-------------------------------------------
	//	class EModelElement
	ecore_EModelElement->setName("EModelElement");
	ecore_EModelElement->setIsAbstract(true);
	
	gen = uml::umlFactory::eInstance()->createGeneralization_as_generalization_in_Classifier(get_Ecore_EModelElement());
	gen->setGeneral(get_Ecore_EObject());
	
    // EModelElement attributes
	//eAnnotations
	ecore_EModelElement_eAnnotations->setName("eAnnotations");
	ecore_EModelElement_eAnnotations->setType(get_Ecore_EAnnotation());
	ecore_EModelElement_eAnnotations->setLower(0);
	ecore_EModelElement_eAnnotations->setUpper(-1);
	ecore_EModelElement_eAnnotations->setIsUnique(true);
	ecore_EModelElement_eAnnotations->setAggregation(uml::AggregationKind::COMPOSITE);
	ecore_EModelElement_eAnnotations->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EModelElement_eAnnotations->setAssociation(get_A_Ecore_EAnnotation_eAnnotations_Ecore_EModelElement_eModelElement());
	
	

    // EModelElement operations
	//getEAnnotation
	ecore_EModelElement_getEAnnotation_EString_EString->setName("getEAnnotation");
	ecore_EModelElement_getEAnnotation_EString_EString->setType(get_Ecore_EAnnotation());
	
	// parameter 
	ecore_EModelElement_getEAnnotation_EString_EStringreturn->setName("ecore_EModelElement_getEAnnotation_EString_EStringreturn");
	ecore_EModelElement_getEAnnotation_EString_EStringreturn->setType(get_Ecore_EAnnotation());
	ecore_EModelElement_getEAnnotation_EString_EStringreturn->setLower(0);
	ecore_EModelElement_getEAnnotation_EString_EStringreturn->setUpper(1);
	ecore_EModelElement_getEAnnotation_EString_EStringreturn->setDirection(uml::ParameterDirectionKind::RETURN);
	
	
	// parameter source
	
	ecore_EModelElement_getEAnnotation_EString_EString_source->setName("source");
	
	ecore_EModelElement_getEAnnotation_EString_EString_source->setType(get_Ecore_EString());
	
	ecore_EModelElement_getEAnnotation_EString_EString_source->setLower(0);
	
	ecore_EModelElement_getEAnnotation_EString_EString_source->setUpper(1);
	
	ecore_EModelElement_getEAnnotation_EString_EString_source->setDirection(uml::ParameterDirectionKind::IN);
	
	
	

    //-------------------------------------------
	//	class ENamedElement
	ecore_ENamedElement->setName("ENamedElement");
	ecore_ENamedElement->setIsAbstract(true);
	
	gen = uml::umlFactory::eInstance()->createGeneralization_as_generalization_in_Classifier(get_Ecore_ENamedElement());
	gen->setGeneral(get_Ecore_EModelElement());
	
    // ENamedElement attributes
	//name
	ecore_ENamedElement_name->setName("name");
	ecore_ENamedElement_name->setType(get_Ecore_EString());
	ecore_ENamedElement_name->setLower(0);
	ecore_ENamedElement_name->setUpper(1);
	ecore_ENamedElement_name->setIsUnique(true);
	ecore_ENamedElement_name->setAggregation(uml::AggregationKind::NONE);
	ecore_ENamedElement_name->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	


    //-------------------------------------------
	//	class EObject
	ecore_EObject->setName("EObject");
	ecore_EObject->setIsAbstract(false);
	
    // EObject operations
	//eAllContents
	ecore_EObject_eAllContents__->setName("eAllContents");
	ecore_EObject_eAllContents__->setType(get_Ecore_EObject_ETreeIterator_EObject());
	
	// parameter 
	ecore_EObject_eAllContents__return->setName("ecore_EObject_eAllContents__return");
	ecore_EObject_eAllContents__return->setType(get_Ecore_EObject_ETreeIterator_EObject());
	ecore_EObject_eAllContents__return->setLower(0);
	ecore_EObject_eAllContents__return->setUpper(1);
	ecore_EObject_eAllContents__return->setDirection(uml::ParameterDirectionKind::RETURN);
	
	

	//eClass
	ecore_EObject_eClass__->setName("eClass");
	ecore_EObject_eClass__->setType(get_Ecore_EClass());
	
	// parameter 
	ecore_EObject_eClass__return->setName("ecore_EObject_eClass__return");
	ecore_EObject_eClass__return->setType(get_Ecore_EClass());
	ecore_EObject_eClass__return->setLower(0);
	ecore_EObject_eClass__return->setUpper(1);
	ecore_EObject_eClass__return->setDirection(uml::ParameterDirectionKind::RETURN);
	
	

	//eContainer
	ecore_EObject_eContainer__->setName("eContainer");
	ecore_EObject_eContainer__->setType(get_Ecore_EObject());
	
	// parameter 
	ecore_EObject_eContainer__return->setName("ecore_EObject_eContainer__return");
	ecore_EObject_eContainer__return->setType(get_Ecore_EObject());
	ecore_EObject_eContainer__return->setLower(0);
	ecore_EObject_eContainer__return->setUpper(1);
	ecore_EObject_eContainer__return->setDirection(uml::ParameterDirectionKind::RETURN);
	
	

	//eContainingFeature
	ecore_EObject_eContainingFeature__->setName("eContainingFeature");
	ecore_EObject_eContainingFeature__->setType(get_Ecore_EStructuralFeature());
	
	// parameter 
	ecore_EObject_eContainingFeature__return->setName("ecore_EObject_eContainingFeature__return");
	ecore_EObject_eContainingFeature__return->setType(get_Ecore_EStructuralFeature());
	ecore_EObject_eContainingFeature__return->setLower(0);
	ecore_EObject_eContainingFeature__return->setUpper(1);
	ecore_EObject_eContainingFeature__return->setDirection(uml::ParameterDirectionKind::RETURN);
	
	

	//eContainmentFeature
	ecore_EObject_eContainmentFeature__->setName("eContainmentFeature");
	ecore_EObject_eContainmentFeature__->setType(get_Ecore_EReference());
	
	// parameter 
	ecore_EObject_eContainmentFeature__return->setName("ecore_EObject_eContainmentFeature__return");
	ecore_EObject_eContainmentFeature__return->setType(get_Ecore_EReference());
	ecore_EObject_eContainmentFeature__return->setLower(0);
	ecore_EObject_eContainmentFeature__return->setUpper(1);
	ecore_EObject_eContainmentFeature__return->setDirection(uml::ParameterDirectionKind::RETURN);
	
	

	//eContents
	ecore_EObject_eContents__->setName("eContents");
	ecore_EObject_eContents__->setType(get_Ecore_EObject_EEList_EObject());
	
	// parameter 
	ecore_EObject_eContents__return->setName("ecore_EObject_eContents__return");
	ecore_EObject_eContents__return->setType(get_Ecore_EObject_EEList_EObject());
	ecore_EObject_eContents__return->setLower(0);
	ecore_EObject_eContents__return->setUpper(1);
	ecore_EObject_eContents__return->setDirection(uml::ParameterDirectionKind::RETURN);
	
	

	//eCrossReferences
	ecore_EObject_eCrossReferences__->setName("eCrossReferences");
	ecore_EObject_eCrossReferences__->setType(get_Ecore_EObject_EEList_EObject());
	
	// parameter 
	ecore_EObject_eCrossReferences__return->setName("ecore_EObject_eCrossReferences__return");
	ecore_EObject_eCrossReferences__return->setType(get_Ecore_EObject_EEList_EObject());
	ecore_EObject_eCrossReferences__return->setLower(0);
	ecore_EObject_eCrossReferences__return->setUpper(1);
	ecore_EObject_eCrossReferences__return->setDirection(uml::ParameterDirectionKind::RETURN);
	
	

	//eGet
	ecore_EObject_eGet_EStructuralFeature_EStructuralFeature->setName("eGet");
	ecore_EObject_eGet_EStructuralFeature_EStructuralFeature->setType(get_Ecore_EJavaObject());
	
	// parameter 
	ecore_EObject_eGet_EStructuralFeature_EStructuralFeaturereturn->setName("ecore_EObject_eGet_EStructuralFeature_EStructuralFeaturereturn");
	ecore_EObject_eGet_EStructuralFeature_EStructuralFeaturereturn->setType(get_Ecore_EJavaObject());
	ecore_EObject_eGet_EStructuralFeature_EStructuralFeaturereturn->setLower(0);
	ecore_EObject_eGet_EStructuralFeature_EStructuralFeaturereturn->setUpper(1);
	ecore_EObject_eGet_EStructuralFeature_EStructuralFeaturereturn->setDirection(uml::ParameterDirectionKind::RETURN);
	
	
	// parameter feature
	
	ecore_EObject_eGet_EStructuralFeature_EStructuralFeature_feature->setName("feature");
	
	ecore_EObject_eGet_EStructuralFeature_EStructuralFeature_feature->setType(get_Ecore_EStructuralFeature());
	
	ecore_EObject_eGet_EStructuralFeature_EStructuralFeature_feature->setLower(0);
	
	ecore_EObject_eGet_EStructuralFeature_EStructuralFeature_feature->setUpper(1);
	
	ecore_EObject_eGet_EStructuralFeature_EStructuralFeature_feature->setDirection(uml::ParameterDirectionKind::IN);
	
	
	

	//eGet
	ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean->setName("eGet");
	ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean->setType(get_Ecore_EJavaObject());
	
	// parameter 
	ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBooleanreturn->setName("ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBooleanreturn");
	ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBooleanreturn->setType(get_Ecore_EJavaObject());
	ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBooleanreturn->setLower(0);
	ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBooleanreturn->setUpper(1);
	ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBooleanreturn->setDirection(uml::ParameterDirectionKind::RETURN);
	
	
	// parameter feature
	
	ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean_feature->setName("feature");
	
	ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean_feature->setType(get_Ecore_EStructuralFeature());
	
	ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean_feature->setLower(0);
	
	ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean_feature->setUpper(1);
	
	ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean_feature->setDirection(uml::ParameterDirectionKind::IN);
	
	
	
	// parameter resolve
	
	ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean_resolve->setName("resolve");
	
	ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean_resolve->setType(get_Ecore_EBoolean());
	
	ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean_resolve->setLower(0);
	
	ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean_resolve->setUpper(1);
	
	ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean_resolve->setDirection(uml::ParameterDirectionKind::IN);
	
	
	

	//eIsProxy
	ecore_EObject_eIsProxy__->setName("eIsProxy");
	ecore_EObject_eIsProxy__->setType(get_Ecore_EBoolean());
	
	// parameter 
	ecore_EObject_eIsProxy__return->setName("ecore_EObject_eIsProxy__return");
	ecore_EObject_eIsProxy__return->setType(get_Ecore_EBoolean());
	ecore_EObject_eIsProxy__return->setLower(0);
	ecore_EObject_eIsProxy__return->setUpper(1);
	ecore_EObject_eIsProxy__return->setDirection(uml::ParameterDirectionKind::RETURN);
	
	

	//eIsSet
	ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeature->setName("eIsSet");
	ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeature->setType(get_Ecore_EBoolean());
	
	// parameter 
	ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeaturereturn->setName("ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeaturereturn");
	ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeaturereturn->setType(get_Ecore_EBoolean());
	ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeaturereturn->setLower(0);
	ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeaturereturn->setUpper(1);
	ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeaturereturn->setDirection(uml::ParameterDirectionKind::RETURN);
	
	
	// parameter feature
	
	ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeature_feature->setName("feature");
	
	ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeature_feature->setType(get_Ecore_EStructuralFeature());
	
	ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeature_feature->setLower(0);
	
	ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeature_feature->setUpper(1);
	
	ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeature_feature->setDirection(uml::ParameterDirectionKind::IN);
	
	
	

	//eResource
	ecore_EObject_eResource__->setName("eResource");
	ecore_EObject_eResource__->setType(get_Ecore_EResource());
	
	// parameter 
	ecore_EObject_eResource__return->setName("ecore_EObject_eResource__return");
	ecore_EObject_eResource__return->setType(get_Ecore_EResource());
	ecore_EObject_eResource__return->setLower(0);
	ecore_EObject_eResource__return->setUpper(1);
	ecore_EObject_eResource__return->setDirection(uml::ParameterDirectionKind::RETURN);
	
	

	//eSet
	ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject->setName("eSet");
	
	// parameter 
	ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObjectreturn->setName("ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObjectreturn");
	ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObjectreturn->setType(nullptr);
	ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObjectreturn->setLower(0);
	ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObjectreturn->setUpper(1);
	ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObjectreturn->setDirection(uml::ParameterDirectionKind::RETURN);
	
	
	// parameter feature
	
	ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject_feature->setName("feature");
	
	ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject_feature->setType(get_Ecore_EStructuralFeature());
	
	ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject_feature->setLower(0);
	
	ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject_feature->setUpper(1);
	
	ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject_feature->setDirection(uml::ParameterDirectionKind::IN);
	
	
	
	// parameter newValue
	
	ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject_newValue->setName("newValue");
	
	ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject_newValue->setType(get_Ecore_EJavaObject());
	
	ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject_newValue->setLower(0);
	
	ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject_newValue->setUpper(1);
	
	ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject_newValue->setDirection(uml::ParameterDirectionKind::IN);
	
	
	

	//eUnset
	ecore_EObject_eUnset_EStructuralFeature_EStructuralFeature->setName("eUnset");
	
	// parameter 
	ecore_EObject_eUnset_EStructuralFeature_EStructuralFeaturereturn->setName("ecore_EObject_eUnset_EStructuralFeature_EStructuralFeaturereturn");
	ecore_EObject_eUnset_EStructuralFeature_EStructuralFeaturereturn->setType(nullptr);
	ecore_EObject_eUnset_EStructuralFeature_EStructuralFeaturereturn->setLower(0);
	ecore_EObject_eUnset_EStructuralFeature_EStructuralFeaturereturn->setUpper(1);
	ecore_EObject_eUnset_EStructuralFeature_EStructuralFeaturereturn->setDirection(uml::ParameterDirectionKind::RETURN);
	
	
	// parameter feature
	
	ecore_EObject_eUnset_EStructuralFeature_EStructuralFeature_feature->setName("feature");
	
	ecore_EObject_eUnset_EStructuralFeature_EStructuralFeature_feature->setType(get_Ecore_EStructuralFeature());
	
	ecore_EObject_eUnset_EStructuralFeature_EStructuralFeature_feature->setLower(0);
	
	ecore_EObject_eUnset_EStructuralFeature_EStructuralFeature_feature->setUpper(1);
	
	ecore_EObject_eUnset_EStructuralFeature_EStructuralFeature_feature->setDirection(uml::ParameterDirectionKind::IN);
	
	
	

    //-------------------------------------------
	//	class EOperation
	ecore_EOperation->setName("EOperation");
	ecore_EOperation->setIsAbstract(false);
	
	gen = uml::umlFactory::eInstance()->createGeneralization_as_generalization_in_Classifier(get_Ecore_EOperation());
	gen->setGeneral(get_Ecore_ETypedElement());
	
    // EOperation attributes
	//eContainingClass
	ecore_EOperation_eContainingClass->setName("eContainingClass");
	ecore_EOperation_eContainingClass->setType(get_Ecore_EClass());
	ecore_EOperation_eContainingClass->setLower(0);
	ecore_EOperation_eContainingClass->setUpper(1);
	ecore_EOperation_eContainingClass->setIsUnique(true);
	ecore_EOperation_eContainingClass->setAggregation(uml::AggregationKind::NONE);
	ecore_EOperation_eContainingClass->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EOperation_eContainingClass->setAssociation(get_A_Ecore_EOperation_eOperations_Ecore_EClass_eContainingClass());
	
	
	//eExceptions
	ecore_EOperation_eExceptions->setName("eExceptions");
	ecore_EOperation_eExceptions->setType(get_Ecore_EClassifier());
	ecore_EOperation_eExceptions->setLower(0);
	ecore_EOperation_eExceptions->setUpper(-1);
	ecore_EOperation_eExceptions->setIsUnique(true);
	ecore_EOperation_eExceptions->setAggregation(uml::AggregationKind::NONE);
	ecore_EOperation_eExceptions->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EOperation_eExceptions->setAssociation(get_A_Ecore_EClassifier_eExceptions_eOperation());
	
	
	//eGenericExceptions
	ecore_EOperation_eGenericExceptions->setName("eGenericExceptions");
	ecore_EOperation_eGenericExceptions->setType(get_Ecore_EGenericType());
	ecore_EOperation_eGenericExceptions->setLower(0);
	ecore_EOperation_eGenericExceptions->setUpper(-1);
	ecore_EOperation_eGenericExceptions->setIsUnique(true);
	ecore_EOperation_eGenericExceptions->setAggregation(uml::AggregationKind::COMPOSITE);
	ecore_EOperation_eGenericExceptions->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EOperation_eGenericExceptions->setAssociation(get_A_Ecore_EGenericType_eGenericExceptions_eOperation());
	
	
	//eParameters
	ecore_EOperation_eParameters->setName("eParameters");
	ecore_EOperation_eParameters->setType(get_Ecore_EParameter());
	ecore_EOperation_eParameters->setLower(0);
	ecore_EOperation_eParameters->setUpper(-1);
	ecore_EOperation_eParameters->setIsUnique(true);
	ecore_EOperation_eParameters->setAggregation(uml::AggregationKind::COMPOSITE);
	ecore_EOperation_eParameters->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EOperation_eParameters->setAssociation(get_A_Ecore_EParameter_eParameters_Ecore_EOperation_eOperation());
	
	
	//eTypeParameters
	ecore_EOperation_eTypeParameters->setName("eTypeParameters");
	ecore_EOperation_eTypeParameters->setType(get_Ecore_ETypeParameter());
	ecore_EOperation_eTypeParameters->setLower(0);
	ecore_EOperation_eTypeParameters->setUpper(-1);
	ecore_EOperation_eTypeParameters->setIsUnique(true);
	ecore_EOperation_eTypeParameters->setAggregation(uml::AggregationKind::COMPOSITE);
	ecore_EOperation_eTypeParameters->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EOperation_eTypeParameters->setAssociation(get_A_Ecore_ETypeParameter_eTypeParameters_eOperation());
	
	


    //-------------------------------------------
	//	class EPackage
	ecore_EPackage->setName("EPackage");
	ecore_EPackage->setIsAbstract(false);
	
	gen = uml::umlFactory::eInstance()->createGeneralization_as_generalization_in_Classifier(get_Ecore_EPackage());
	gen->setGeneral(get_Ecore_ENamedElement());
	
    // EPackage attributes
	//eClassifiers
	ecore_EPackage_eClassifiers->setName("eClassifiers");
	ecore_EPackage_eClassifiers->setType(get_Ecore_EClassifier());
	ecore_EPackage_eClassifiers->setLower(0);
	ecore_EPackage_eClassifiers->setUpper(-1);
	ecore_EPackage_eClassifiers->setIsUnique(true);
	ecore_EPackage_eClassifiers->setAggregation(uml::AggregationKind::COMPOSITE);
	ecore_EPackage_eClassifiers->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EPackage_eClassifiers->setAssociation(get_A_Ecore_EClassifier_eClassifiers_Ecore_EPackage_ePackage());
	
	
	//eFactoryInstance
	ecore_EPackage_eFactoryInstance->setName("eFactoryInstance");
	ecore_EPackage_eFactoryInstance->setType(get_Ecore_EFactory());
	ecore_EPackage_eFactoryInstance->setLower(1);
	ecore_EPackage_eFactoryInstance->setUpper(1);
	ecore_EPackage_eFactoryInstance->setIsUnique(true);
	ecore_EPackage_eFactoryInstance->setAggregation(uml::AggregationKind::NONE);
	ecore_EPackage_eFactoryInstance->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EPackage_eFactoryInstance->setAssociation(get_A_Ecore_EPackage_ePackage_Ecore_EFactory_eFactoryInstance());
	
	
	//eSubpackages
	ecore_EPackage_eSubpackages->setName("eSubpackages");
	ecore_EPackage_eSubpackages->setType(get_Ecore_EPackage());
	ecore_EPackage_eSubpackages->setLower(0);
	ecore_EPackage_eSubpackages->setUpper(-1);
	ecore_EPackage_eSubpackages->setIsUnique(true);
	ecore_EPackage_eSubpackages->setAggregation(uml::AggregationKind::COMPOSITE);
	ecore_EPackage_eSubpackages->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EPackage_eSubpackages->setAssociation(get_A_Ecore_EPackage_eSubpackages_Ecore_EPackage_eSuperPackage());
	
	
	//eSuperPackage
	ecore_EPackage_eSuperPackage->setName("eSuperPackage");
	ecore_EPackage_eSuperPackage->setType(get_Ecore_EPackage());
	ecore_EPackage_eSuperPackage->setLower(0);
	ecore_EPackage_eSuperPackage->setUpper(1);
	ecore_EPackage_eSuperPackage->setIsUnique(true);
	ecore_EPackage_eSuperPackage->setAggregation(uml::AggregationKind::NONE);
	ecore_EPackage_eSuperPackage->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EPackage_eSuperPackage->setAssociation(get_A_Ecore_EPackage_eSubpackages_Ecore_EPackage_eSuperPackage());
	
	
	//nsPrefix
	ecore_EPackage_nsPrefix->setName("nsPrefix");
	ecore_EPackage_nsPrefix->setType(get_Ecore_EString());
	ecore_EPackage_nsPrefix->setLower(0);
	ecore_EPackage_nsPrefix->setUpper(1);
	ecore_EPackage_nsPrefix->setIsUnique(true);
	ecore_EPackage_nsPrefix->setAggregation(uml::AggregationKind::NONE);
	ecore_EPackage_nsPrefix->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	
	//nsURI
	ecore_EPackage_nsURI->setName("nsURI");
	ecore_EPackage_nsURI->setType(get_Ecore_EString());
	ecore_EPackage_nsURI->setLower(0);
	ecore_EPackage_nsURI->setUpper(1);
	ecore_EPackage_nsURI->setIsUnique(true);
	ecore_EPackage_nsURI->setAggregation(uml::AggregationKind::NONE);
	ecore_EPackage_nsURI->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	

    // EPackage operations
	//getEClassifier
	ecore_EPackage_getEClassifier_EString_EString->setName("getEClassifier");
	ecore_EPackage_getEClassifier_EString_EString->setType(get_Ecore_EClassifier());
	
	// parameter 
	ecore_EPackage_getEClassifier_EString_EStringreturn->setName("ecore_EPackage_getEClassifier_EString_EStringreturn");
	ecore_EPackage_getEClassifier_EString_EStringreturn->setType(get_Ecore_EClassifier());
	ecore_EPackage_getEClassifier_EString_EStringreturn->setLower(0);
	ecore_EPackage_getEClassifier_EString_EStringreturn->setUpper(1);
	ecore_EPackage_getEClassifier_EString_EStringreturn->setDirection(uml::ParameterDirectionKind::RETURN);
	
	
	// parameter name
	
	ecore_EPackage_getEClassifier_EString_EString_name->setName("name");
	
	ecore_EPackage_getEClassifier_EString_EString_name->setType(get_Ecore_EString());
	
	ecore_EPackage_getEClassifier_EString_EString_name->setLower(0);
	
	ecore_EPackage_getEClassifier_EString_EString_name->setUpper(1);
	
	ecore_EPackage_getEClassifier_EString_EString_name->setDirection(uml::ParameterDirectionKind::IN);
	
	
	

    //-------------------------------------------
	//	class EParameter
	ecore_EParameter->setName("EParameter");
	ecore_EParameter->setIsAbstract(false);
	
	gen = uml::umlFactory::eInstance()->createGeneralization_as_generalization_in_Classifier(get_Ecore_EParameter());
	gen->setGeneral(get_Ecore_ETypedElement());
	
    // EParameter attributes
	//eOperation
	ecore_EParameter_eOperation->setName("eOperation");
	ecore_EParameter_eOperation->setType(get_Ecore_EOperation());
	ecore_EParameter_eOperation->setLower(0);
	ecore_EParameter_eOperation->setUpper(1);
	ecore_EParameter_eOperation->setIsUnique(true);
	ecore_EParameter_eOperation->setAggregation(uml::AggregationKind::NONE);
	ecore_EParameter_eOperation->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EParameter_eOperation->setAssociation(get_A_Ecore_EParameter_eParameters_Ecore_EOperation_eOperation());
	
	


    //-------------------------------------------
	//	class EReference
	ecore_EReference->setName("EReference");
	ecore_EReference->setIsAbstract(false);
	
	gen = uml::umlFactory::eInstance()->createGeneralization_as_generalization_in_Classifier(get_Ecore_EReference());
	gen->setGeneral(get_Ecore_EStructuralFeature());
	
    // EReference attributes
	//container
	ecore_EReference_container->setName("container");
	ecore_EReference_container->setType(get_Ecore_EBoolean());
	ecore_EReference_container->setLower(0);
	ecore_EReference_container->setUpper(1);
	ecore_EReference_container->setIsUnique(true);
	ecore_EReference_container->setAggregation(uml::AggregationKind::NONE);
	ecore_EReference_container->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	
	//containment
	ecore_EReference_containment->setName("containment");
	ecore_EReference_containment->setType(get_Ecore_EBoolean());
	ecore_EReference_containment->setLower(0);
	ecore_EReference_containment->setUpper(1);
	ecore_EReference_containment->setIsUnique(true);
	ecore_EReference_containment->setAggregation(uml::AggregationKind::NONE);
	ecore_EReference_containment->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	
	//eKeys
	ecore_EReference_eKeys->setName("eKeys");
	ecore_EReference_eKeys->setType(get_Ecore_EAttribute());
	ecore_EReference_eKeys->setLower(0);
	ecore_EReference_eKeys->setUpper(-1);
	ecore_EReference_eKeys->setIsUnique(true);
	ecore_EReference_eKeys->setAggregation(uml::AggregationKind::NONE);
	ecore_EReference_eKeys->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EReference_eKeys->setAssociation(get_A_Ecore_EAttribute_eKeys_eReference());
	
	
	//eOpposite
	ecore_EReference_eOpposite->setName("eOpposite");
	ecore_EReference_eOpposite->setType(get_Ecore_EReference());
	ecore_EReference_eOpposite->setLower(0);
	ecore_EReference_eOpposite->setUpper(1);
	ecore_EReference_eOpposite->setIsUnique(true);
	ecore_EReference_eOpposite->setAggregation(uml::AggregationKind::NONE);
	ecore_EReference_eOpposite->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EReference_eOpposite->setAssociation(get_A_Ecore_EReference_eOpposite_eReference());
	
	
	//eReferenceType
	ecore_EReference_eReferenceType->setName("eReferenceType");
	ecore_EReference_eReferenceType->setType(get_Ecore_EClass());
	ecore_EReference_eReferenceType->setLower(1);
	ecore_EReference_eReferenceType->setUpper(1);
	ecore_EReference_eReferenceType->setIsUnique(true);
	ecore_EReference_eReferenceType->setAggregation(uml::AggregationKind::NONE);
	ecore_EReference_eReferenceType->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EReference_eReferenceType->setAssociation(get_A_Ecore_EClass_eReferenceType_eReference());
	
	
	//resolveProxies
	ecore_EReference_resolveProxies->setName("resolveProxies");
	ecore_EReference_resolveProxies->setType(get_Ecore_EBoolean());
	ecore_EReference_resolveProxies->setLower(0);
	ecore_EReference_resolveProxies->setUpper(1);
	ecore_EReference_resolveProxies->setIsUnique(true);
	ecore_EReference_resolveProxies->setAggregation(uml::AggregationKind::NONE);
	ecore_EReference_resolveProxies->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	


    //-------------------------------------------
	//	class EStringToStringMapEntry
	ecore_EStringToStringMapEntry->setName("EStringToStringMapEntry");
	ecore_EStringToStringMapEntry->setIsAbstract(false);
	
    // EStringToStringMapEntry attributes
	//key
	ecore_EStringToStringMapEntry_key->setName("key");
	ecore_EStringToStringMapEntry_key->setType(get_Ecore_EString());
	ecore_EStringToStringMapEntry_key->setLower(0);
	ecore_EStringToStringMapEntry_key->setUpper(1);
	ecore_EStringToStringMapEntry_key->setIsUnique(true);
	ecore_EStringToStringMapEntry_key->setAggregation(uml::AggregationKind::NONE);
	ecore_EStringToStringMapEntry_key->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	
	//value
	ecore_EStringToStringMapEntry_value->setName("value");
	ecore_EStringToStringMapEntry_value->setType(get_Ecore_EString());
	ecore_EStringToStringMapEntry_value->setLower(0);
	ecore_EStringToStringMapEntry_value->setUpper(1);
	ecore_EStringToStringMapEntry_value->setIsUnique(true);
	ecore_EStringToStringMapEntry_value->setAggregation(uml::AggregationKind::NONE);
	ecore_EStringToStringMapEntry_value->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	


    //-------------------------------------------
	//	class EStructuralFeature
	ecore_EStructuralFeature->setName("EStructuralFeature");
	ecore_EStructuralFeature->setIsAbstract(true);
	
	gen = uml::umlFactory::eInstance()->createGeneralization_as_generalization_in_Classifier(get_Ecore_EStructuralFeature());
	gen->setGeneral(get_Ecore_ETypedElement());
	
    // EStructuralFeature attributes
	//changeable
	ecore_EStructuralFeature_changeable->setName("changeable");
	ecore_EStructuralFeature_changeable->setType(get_Ecore_EBoolean());
	ecore_EStructuralFeature_changeable->setLower(0);
	ecore_EStructuralFeature_changeable->setUpper(1);
	ecore_EStructuralFeature_changeable->setIsUnique(true);
	ecore_EStructuralFeature_changeable->setAggregation(uml::AggregationKind::NONE);
	ecore_EStructuralFeature_changeable->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	
	//defaultValue
	ecore_EStructuralFeature_defaultValue->setName("defaultValue");
	ecore_EStructuralFeature_defaultValue->setType(get_Ecore_EJavaObject());
	ecore_EStructuralFeature_defaultValue->setLower(0);
	ecore_EStructuralFeature_defaultValue->setUpper(1);
	ecore_EStructuralFeature_defaultValue->setIsUnique(true);
	ecore_EStructuralFeature_defaultValue->setAggregation(uml::AggregationKind::NONE);
	ecore_EStructuralFeature_defaultValue->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	
	//defaultValueLiteral
	ecore_EStructuralFeature_defaultValueLiteral->setName("defaultValueLiteral");
	ecore_EStructuralFeature_defaultValueLiteral->setType(get_Ecore_EString());
	ecore_EStructuralFeature_defaultValueLiteral->setLower(0);
	ecore_EStructuralFeature_defaultValueLiteral->setUpper(1);
	ecore_EStructuralFeature_defaultValueLiteral->setIsUnique(true);
	ecore_EStructuralFeature_defaultValueLiteral->setAggregation(uml::AggregationKind::NONE);
	ecore_EStructuralFeature_defaultValueLiteral->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	
	//derived
	ecore_EStructuralFeature_derived->setName("derived");
	ecore_EStructuralFeature_derived->setType(get_Ecore_EBoolean());
	ecore_EStructuralFeature_derived->setLower(0);
	ecore_EStructuralFeature_derived->setUpper(1);
	ecore_EStructuralFeature_derived->setIsUnique(true);
	ecore_EStructuralFeature_derived->setAggregation(uml::AggregationKind::NONE);
	ecore_EStructuralFeature_derived->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	
	//eContainingClass
	ecore_EStructuralFeature_eContainingClass->setName("eContainingClass");
	ecore_EStructuralFeature_eContainingClass->setType(get_Ecore_EClass());
	ecore_EStructuralFeature_eContainingClass->setLower(0);
	ecore_EStructuralFeature_eContainingClass->setUpper(1);
	ecore_EStructuralFeature_eContainingClass->setIsUnique(true);
	ecore_EStructuralFeature_eContainingClass->setAggregation(uml::AggregationKind::NONE);
	ecore_EStructuralFeature_eContainingClass->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_EStructuralFeature_eContainingClass->setAssociation(get_A_Ecore_EStructuralFeature_eStructuralFeatures_Ecore_EClass_eContainingClass());
	
	
	//transient
	ecore_EStructuralFeature_transient->setName("transient");
	ecore_EStructuralFeature_transient->setType(get_Ecore_EBoolean());
	ecore_EStructuralFeature_transient->setLower(0);
	ecore_EStructuralFeature_transient->setUpper(1);
	ecore_EStructuralFeature_transient->setIsUnique(true);
	ecore_EStructuralFeature_transient->setAggregation(uml::AggregationKind::NONE);
	ecore_EStructuralFeature_transient->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	
	//unsettable
	ecore_EStructuralFeature_unsettable->setName("unsettable");
	ecore_EStructuralFeature_unsettable->setType(get_Ecore_EBoolean());
	ecore_EStructuralFeature_unsettable->setLower(0);
	ecore_EStructuralFeature_unsettable->setUpper(1);
	ecore_EStructuralFeature_unsettable->setIsUnique(true);
	ecore_EStructuralFeature_unsettable->setAggregation(uml::AggregationKind::NONE);
	ecore_EStructuralFeature_unsettable->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	
	//volatile
	ecore_EStructuralFeature_volatile->setName("volatile");
	ecore_EStructuralFeature_volatile->setType(get_Ecore_EBoolean());
	ecore_EStructuralFeature_volatile->setLower(0);
	ecore_EStructuralFeature_volatile->setUpper(1);
	ecore_EStructuralFeature_volatile->setIsUnique(true);
	ecore_EStructuralFeature_volatile->setAggregation(uml::AggregationKind::NONE);
	ecore_EStructuralFeature_volatile->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	

    // EStructuralFeature operations
	//getContainerClass
	ecore_EStructuralFeature_getContainerClass__->setName("getContainerClass");
	ecore_EStructuralFeature_getContainerClass__->setType(get_Ecore_EStructuralFeature_EJavaClass_Wildcard());
	
	// parameter 
	ecore_EStructuralFeature_getContainerClass__return->setName("ecore_EStructuralFeature_getContainerClass__return");
	ecore_EStructuralFeature_getContainerClass__return->setType(get_Ecore_EStructuralFeature_EJavaClass_Wildcard());
	ecore_EStructuralFeature_getContainerClass__return->setLower(0);
	ecore_EStructuralFeature_getContainerClass__return->setUpper(1);
	ecore_EStructuralFeature_getContainerClass__return->setDirection(uml::ParameterDirectionKind::RETURN);
	
	

	//getFeatureID
	ecore_EStructuralFeature_getFeatureID__->setName("getFeatureID");
	ecore_EStructuralFeature_getFeatureID__->setType(get_Ecore_EInt());
	
	// parameter 
	ecore_EStructuralFeature_getFeatureID__return->setName("ecore_EStructuralFeature_getFeatureID__return");
	ecore_EStructuralFeature_getFeatureID__return->setType(get_Ecore_EInt());
	ecore_EStructuralFeature_getFeatureID__return->setLower(0);
	ecore_EStructuralFeature_getFeatureID__return->setUpper(1);
	ecore_EStructuralFeature_getFeatureID__return->setDirection(uml::ParameterDirectionKind::RETURN);
	
	

    //-------------------------------------------
	//	class ETypeParameter
	ecore_ETypeParameter->setName("ETypeParameter");
	ecore_ETypeParameter->setIsAbstract(false);
	
	gen = uml::umlFactory::eInstance()->createGeneralization_as_generalization_in_Classifier(get_Ecore_ETypeParameter());
	gen->setGeneral(get_Ecore_ENamedElement());
	
    // ETypeParameter attributes
	//eBounds
	ecore_ETypeParameter_eBounds->setName("eBounds");
	ecore_ETypeParameter_eBounds->setType(get_Ecore_EGenericType());
	ecore_ETypeParameter_eBounds->setLower(0);
	ecore_ETypeParameter_eBounds->setUpper(-1);
	ecore_ETypeParameter_eBounds->setIsUnique(true);
	ecore_ETypeParameter_eBounds->setAggregation(uml::AggregationKind::COMPOSITE);
	ecore_ETypeParameter_eBounds->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_ETypeParameter_eBounds->setAssociation(get_A_Ecore_EGenericType_eBounds_eTypeParameter());
	
	


    //-------------------------------------------
	//	class ETypedElement
	ecore_ETypedElement->setName("ETypedElement");
	ecore_ETypedElement->setIsAbstract(true);
	
	gen = uml::umlFactory::eInstance()->createGeneralization_as_generalization_in_Classifier(get_Ecore_ETypedElement());
	gen->setGeneral(get_Ecore_ENamedElement());
	
    // ETypedElement attributes
	//eGenericType
	ecore_ETypedElement_eGenericType->setName("eGenericType");
	ecore_ETypedElement_eGenericType->setType(get_Ecore_EGenericType());
	ecore_ETypedElement_eGenericType->setLower(0);
	ecore_ETypedElement_eGenericType->setUpper(1);
	ecore_ETypedElement_eGenericType->setIsUnique(true);
	ecore_ETypedElement_eGenericType->setAggregation(uml::AggregationKind::COMPOSITE);
	ecore_ETypedElement_eGenericType->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_ETypedElement_eGenericType->setAssociation(get_A_Ecore_EGenericType_eGenericType_eTypedElement());
	
	
	//eType
	ecore_ETypedElement_eType->setName("eType");
	ecore_ETypedElement_eType->setType(get_Ecore_EClassifier());
	ecore_ETypedElement_eType->setLower(0);
	ecore_ETypedElement_eType->setUpper(1);
	ecore_ETypedElement_eType->setIsUnique(true);
	ecore_ETypedElement_eType->setAggregation(uml::AggregationKind::NONE);
	ecore_ETypedElement_eType->setVisibility(uml::VisibilityKind::PUBLIC);
	ecore_ETypedElement_eType->setAssociation(get_A_Ecore_EClassifier_eType_eTypedElement());
	
	
	//lowerBound
	ecore_ETypedElement_lowerBound->setName("lowerBound");
	ecore_ETypedElement_lowerBound->setType(get_Ecore_EInt());
	ecore_ETypedElement_lowerBound->setLower(0);
	ecore_ETypedElement_lowerBound->setUpper(1);
	ecore_ETypedElement_lowerBound->setIsUnique(true);
	ecore_ETypedElement_lowerBound->setAggregation(uml::AggregationKind::NONE);
	ecore_ETypedElement_lowerBound->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	
	//many
	ecore_ETypedElement_many->setName("many");
	ecore_ETypedElement_many->setType(get_Ecore_EBoolean());
	ecore_ETypedElement_many->setLower(0);
	ecore_ETypedElement_many->setUpper(1);
	ecore_ETypedElement_many->setIsUnique(true);
	ecore_ETypedElement_many->setAggregation(uml::AggregationKind::NONE);
	ecore_ETypedElement_many->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	
	//ordered
	ecore_ETypedElement_ordered->setName("ordered");
	ecore_ETypedElement_ordered->setType(get_Ecore_EBoolean());
	ecore_ETypedElement_ordered->setLower(0);
	ecore_ETypedElement_ordered->setUpper(1);
	ecore_ETypedElement_ordered->setIsUnique(true);
	ecore_ETypedElement_ordered->setAggregation(uml::AggregationKind::NONE);
	ecore_ETypedElement_ordered->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	
	//required
	ecore_ETypedElement_required->setName("required");
	ecore_ETypedElement_required->setType(get_Ecore_EBoolean());
	ecore_ETypedElement_required->setLower(0);
	ecore_ETypedElement_required->setUpper(1);
	ecore_ETypedElement_required->setIsUnique(true);
	ecore_ETypedElement_required->setAggregation(uml::AggregationKind::NONE);
	ecore_ETypedElement_required->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	
	//unique
	ecore_ETypedElement_unique->setName("unique");
	ecore_ETypedElement_unique->setType(get_Ecore_EBoolean());
	ecore_ETypedElement_unique->setLower(0);
	ecore_ETypedElement_unique->setUpper(1);
	ecore_ETypedElement_unique->setIsUnique(true);
	ecore_ETypedElement_unique->setAggregation(uml::AggregationKind::NONE);
	ecore_ETypedElement_unique->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	
	//upperBound
	ecore_ETypedElement_upperBound->setName("upperBound");
	ecore_ETypedElement_upperBound->setType(get_Ecore_EInt());
	ecore_ETypedElement_upperBound->setLower(0);
	ecore_ETypedElement_upperBound->setUpper(1);
	ecore_ETypedElement_upperBound->setIsUnique(true);
	ecore_ETypedElement_upperBound->setAggregation(uml::AggregationKind::NONE);
	ecore_ETypedElement_upperBound->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	


//-------------------------------------------
//Opaque Behaviors

}

void EcorePackageImpl::initializePackageSignals()
{
	std::shared_ptr<uml::Generalization> gen = nullptr;


//-------------------------------------------
//Opaque Behaviors

}

void EcorePackageImpl::initializePackageDataTypes()
{
	std::shared_ptr<uml::Generalization> gen = nullptr;

}

void EcorePackageImpl::initializePackageDependencies()
{
}

void EcorePackageImpl::initializePackageEvents()
{
}

void EcorePackageImpl::initializePackageInstanceSpecifications()
{
}


void EcorePackageImpl::initializePackageInterfaceRealizations()
{
}

void EcorePackageImpl::initializePackageInterfaces()
{
}

void EcorePackageImpl::initializePackageNestedPackages()
{
}

void EcorePackageImpl::initializePackageStereotypes()
{
}

void EcorePackageImpl::initializePackageValueSpecifications()
{
	ecore_EAnnotation_contents_lowerValue_LiteralInteger_Ecore_EAnnotation_contents->setValue(0);

	ecore_EAnnotation_contents_upperValue_LiteralUnlimitedNatural_Ecore_EAnnotation_contents->setValue(-1);

	ecore_EAnnotation_details_lowerValue_LiteralInteger_Ecore_EAnnotation_details->setValue(0);

	ecore_EAnnotation_details_upperValue_LiteralUnlimitedNatural_Ecore_EAnnotation_details->setValue(-1);

	ecore_EAnnotation_eModelElement_lowerValue_LiteralInteger_Ecore_EAnnotation_eModelElement->setValue(0);

	ecore_EAnnotation_references_lowerValue_LiteralInteger_Ecore_EAnnotation_references->setValue(0);

	ecore_EAnnotation_references_upperValue_LiteralUnlimitedNatural_Ecore_EAnnotation_references->setValue(-1);

	ecore_EAnnotation_source_lowerValue_LiteralInteger_Ecore_EAnnotation_source->setValue(0);

	ecore_EAttribute_id_lowerValue_LiteralInteger_Ecore_EAttribute_id->setValue(0);

	ecore_EClass_abstract_lowerValue_LiteralInteger_Ecore_EClass_abstract->setValue(0);

	ecore_EClass_eAllAttributes_lowerValue_LiteralInteger_Ecore_EClass_eAllAttributes->setValue(0);

	ecore_EClass_eAllAttributes_upperValue_LiteralUnlimitedNatural_Ecore_EClass_eAllAttributes->setValue(-1);

	ecore_EClass_eAllContainments_lowerValue_LiteralInteger_Ecore_EClass_eAllContainments->setValue(0);

	ecore_EClass_eAllContainments_upperValue_LiteralUnlimitedNatural_Ecore_EClass_eAllContainments->setValue(-1);

	ecore_EClass_eAllGenericSuperTypes_lowerValue_LiteralInteger_Ecore_EClass_eAllGenericSuperTypes->setValue(0);

	ecore_EClass_eAllGenericSuperTypes_upperValue_LiteralUnlimitedNatural_Ecore_EClass_eAllGenericSuperTypes->setValue(-1);

	ecore_EClass_eAllOperations_lowerValue_LiteralInteger_Ecore_EClass_eAllOperations->setValue(0);

	ecore_EClass_eAllOperations_upperValue_LiteralUnlimitedNatural_Ecore_EClass_eAllOperations->setValue(-1);

	ecore_EClass_eAllReferences_lowerValue_LiteralInteger_Ecore_EClass_eAllReferences->setValue(0);

	ecore_EClass_eAllReferences_upperValue_LiteralUnlimitedNatural_Ecore_EClass_eAllReferences->setValue(-1);

	ecore_EClass_eAllStructuralFeatures_lowerValue_LiteralInteger_Ecore_EClass_eAllStructuralFeatures->setValue(0);

	ecore_EClass_eAllStructuralFeatures_upperValue_LiteralUnlimitedNatural_Ecore_EClass_eAllStructuralFeatures->setValue(-1);

	ecore_EClass_eAllSuperTypes_lowerValue_LiteralInteger_Ecore_EClass_eAllSuperTypes->setValue(0);

	ecore_EClass_eAllSuperTypes_upperValue_LiteralUnlimitedNatural_Ecore_EClass_eAllSuperTypes->setValue(-1);

	ecore_EClass_eAttributes_lowerValue_LiteralInteger_Ecore_EClass_eAttributes->setValue(0);

	ecore_EClass_eAttributes_upperValue_LiteralUnlimitedNatural_Ecore_EClass_eAttributes->setValue(-1);

	ecore_EClass_eGenericSuperTypes_lowerValue_LiteralInteger_Ecore_EClass_eGenericSuperTypes->setValue(0);

	ecore_EClass_eGenericSuperTypes_upperValue_LiteralUnlimitedNatural_Ecore_EClass_eGenericSuperTypes->setValue(-1);

	ecore_EClass_eIDAttribute_lowerValue_LiteralInteger_Ecore_EClass_eIDAttribute->setValue(0);

	ecore_EClass_eOperations_lowerValue_LiteralInteger_Ecore_EClass_eOperations->setValue(0);

	ecore_EClass_eOperations_upperValue_LiteralUnlimitedNatural_Ecore_EClass_eOperations->setValue(-1);

	ecore_EClass_eReferences_lowerValue_LiteralInteger_Ecore_EClass_eReferences->setValue(0);

	ecore_EClass_eReferences_upperValue_LiteralUnlimitedNatural_Ecore_EClass_eReferences->setValue(-1);

	ecore_EClass_eStructuralFeatures_lowerValue_LiteralInteger_Ecore_EClass_eStructuralFeatures->setValue(0);

	ecore_EClass_eStructuralFeatures_upperValue_LiteralUnlimitedNatural_Ecore_EClass_eStructuralFeatures->setValue(-1);

	ecore_EClass_eSuperTypes_lowerValue_LiteralInteger_Ecore_EClass_eSuperTypes->setValue(0);

	ecore_EClass_eSuperTypes_upperValue_LiteralUnlimitedNatural_Ecore_EClass_eSuperTypes->setValue(-1);

	ecore_EClass_getEStructuralFeature_EInt_EInt_featureID_lowerValue_LiteralInteger_Ecore_EClass_getEStructuralFeature_EInt_EInt_featureID->setValue(0);

	ecore_EClass_getEStructuralFeature_EInt_EIntreturn_lowerValue_LiteralInteger_Ecore_EClass_getEStructuralFeature_EInt_EIntreturn->setValue(0);

	ecore_EClass_getEStructuralFeature_EString_EString_featureName_lowerValue_LiteralInteger_Ecore_EClass_getEStructuralFeature_EString_EString_featureName->setValue(0);

	ecore_EClass_getEStructuralFeature_EString_EStringreturn_lowerValue_LiteralInteger_Ecore_EClass_getEStructuralFeature_EString_EStringreturn->setValue(0);

	ecore_EClass_getFeatureCount__return_lowerValue_LiteralInteger_Ecore_EClass_getFeatureCount__return->setValue(0);

	ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeature_feature_lowerValue_LiteralInteger_Ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeature_feature->setValue(0);

	ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeaturereturn_lowerValue_LiteralInteger_Ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeaturereturn->setValue(0);

	ecore_EClass_interface_lowerValue_LiteralInteger_Ecore_EClass_interface->setValue(0);

	ecore_EClass_isSuperTypeOf_EClass_EClass_someClass_lowerValue_LiteralInteger_Ecore_EClass_isSuperTypeOf_EClass_EClass_someClass->setValue(0);

	ecore_EClass_isSuperTypeOf_EClass_EClassreturn_lowerValue_LiteralInteger_Ecore_EClass_isSuperTypeOf_EClass_EClassreturn->setValue(0);

	ecore_EClassifier_defaultValue_lowerValue_LiteralInteger_Ecore_EClassifier_defaultValue->setValue(0);

	ecore_EClassifier_ePackage_lowerValue_LiteralInteger_Ecore_EClassifier_ePackage->setValue(0);

	ecore_EClassifier_eTypeParameters_lowerValue_LiteralInteger_Ecore_EClassifier_eTypeParameters->setValue(0);

	ecore_EClassifier_eTypeParameters_upperValue_LiteralUnlimitedNatural_Ecore_EClassifier_eTypeParameters->setValue(-1);

	ecore_EClassifier_getClassifierID__return_lowerValue_LiteralInteger_Ecore_EClassifier_getClassifierID__return->setValue(0);

	ecore_EClassifier_instanceClassName_lowerValue_LiteralInteger_Ecore_EClassifier_instanceClassName->setValue(0);

	ecore_EClassifier_instanceClass_lowerValue_LiteralInteger_Ecore_EClassifier_instanceClass->setValue(0);

	ecore_EClassifier_instanceTypeName_lowerValue_LiteralInteger_Ecore_EClassifier_instanceTypeName->setValue(0);

	ecore_EClassifier_isInstance_EJavaObject_EJavaObject_object_lowerValue_LiteralInteger_Ecore_EClassifier_isInstance_EJavaObject_EJavaObject_object->setValue(0);

	ecore_EClassifier_isInstance_EJavaObject_EJavaObjectreturn_lowerValue_LiteralInteger_Ecore_EClassifier_isInstance_EJavaObject_EJavaObjectreturn->setValue(0);

	ecore_EDataType_serializable_lowerValue_LiteralInteger_Ecore_EDataType_serializable->setValue(0);

	ecore_EEnumLiteral_eEnum_lowerValue_LiteralInteger_Ecore_EEnumLiteral_eEnum->setValue(0);

	ecore_EEnumLiteral_instance_lowerValue_LiteralInteger_Ecore_EEnumLiteral_instance->setValue(0);

	ecore_EEnumLiteral_literal_lowerValue_LiteralInteger_Ecore_EEnumLiteral_literal->setValue(0);

	ecore_EEnumLiteral_value_lowerValue_LiteralInteger_Ecore_EEnumLiteral_value->setValue(0);

	ecore_EEnum_eLiterals_lowerValue_LiteralInteger_Ecore_EEnum_eLiterals->setValue(0);

	ecore_EEnum_eLiterals_upperValue_LiteralUnlimitedNatural_Ecore_EEnum_eLiterals->setValue(-1);

	ecore_EEnum_getEEnumLiteralByLiteral_EString_EString_literal_lowerValue_LiteralInteger_Ecore_EEnum_getEEnumLiteralByLiteral_EString_EString_literal->setValue(0);

	ecore_EEnum_getEEnumLiteralByLiteral_EString_EStringreturn_lowerValue_LiteralInteger_Ecore_EEnum_getEEnumLiteralByLiteral_EString_EStringreturn->setValue(0);

	ecore_EEnum_getEEnumLiteral_EInt_EInt_value_lowerValue_LiteralInteger_Ecore_EEnum_getEEnumLiteral_EInt_EInt_value->setValue(0);

	ecore_EEnum_getEEnumLiteral_EInt_EIntreturn_lowerValue_LiteralInteger_Ecore_EEnum_getEEnumLiteral_EInt_EIntreturn->setValue(0);

	ecore_EEnum_getEEnumLiteral_EString_EString_name_lowerValue_LiteralInteger_Ecore_EEnum_getEEnumLiteral_EString_EString_name->setValue(0);

	ecore_EEnum_getEEnumLiteral_EString_EStringreturn_lowerValue_LiteralInteger_Ecore_EEnum_getEEnumLiteral_EString_EStringreturn->setValue(0);

	ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject_eDataType_lowerValue_LiteralInteger_Ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject_eDataType->setValue(0);

	ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject_instanceValue_lowerValue_LiteralInteger_Ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject_instanceValue->setValue(0);

	ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObjectreturn_lowerValue_LiteralInteger_Ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObjectreturn->setValue(0);

	ecore_EFactory_createFromString_EDataType_EString_EDataType_EString_eDataType_lowerValue_LiteralInteger_Ecore_EFactory_createFromString_EDataType_EString_EDataType_EString_eDataType->setValue(0);

	ecore_EFactory_createFromString_EDataType_EString_EDataType_EString_literalValue_lowerValue_LiteralInteger_Ecore_EFactory_createFromString_EDataType_EString_EDataType_EString_literalValue->setValue(0);

	ecore_EFactory_createFromString_EDataType_EString_EDataType_EStringreturn_lowerValue_LiteralInteger_Ecore_EFactory_createFromString_EDataType_EString_EDataType_EStringreturn->setValue(0);

	ecore_EFactory_create_EClass_EClass_eClass_lowerValue_LiteralInteger_Ecore_EFactory_create_EClass_EClass_eClass->setValue(0);

	ecore_EFactory_create_EClass_EClassreturn_lowerValue_LiteralInteger_Ecore_EFactory_create_EClass_EClassreturn->setValue(0);

	ecore_EGenericType_eClassifier_lowerValue_LiteralInteger_Ecore_EGenericType_eClassifier->setValue(0);

	ecore_EGenericType_eLowerBound_lowerValue_LiteralInteger_Ecore_EGenericType_eLowerBound->setValue(0);

	ecore_EGenericType_eTypeArguments_lowerValue_LiteralInteger_Ecore_EGenericType_eTypeArguments->setValue(0);

	ecore_EGenericType_eTypeArguments_upperValue_LiteralUnlimitedNatural_Ecore_EGenericType_eTypeArguments->setValue(-1);

	ecore_EGenericType_eTypeParameter_lowerValue_LiteralInteger_Ecore_EGenericType_eTypeParameter->setValue(0);

	ecore_EGenericType_eUpperBound_lowerValue_LiteralInteger_Ecore_EGenericType_eUpperBound->setValue(0);

	ecore_EModelElement_eAnnotations_lowerValue_LiteralInteger_Ecore_EModelElement_eAnnotations->setValue(0);

	ecore_EModelElement_eAnnotations_upperValue_LiteralUnlimitedNatural_Ecore_EModelElement_eAnnotations->setValue(-1);

	ecore_EModelElement_getEAnnotation_EString_EString_source_lowerValue_LiteralInteger_Ecore_EModelElement_getEAnnotation_EString_EString_source->setValue(0);

	ecore_EModelElement_getEAnnotation_EString_EStringreturn_lowerValue_LiteralInteger_Ecore_EModelElement_getEAnnotation_EString_EStringreturn->setValue(0);

	ecore_ENamedElement_name_lowerValue_LiteralInteger_Ecore_ENamedElement_name->setValue(0);

	ecore_EObject_eAllContents__return_lowerValue_LiteralInteger_Ecore_EObject_eAllContents__return->setValue(0);

	ecore_EObject_eClass__return_lowerValue_LiteralInteger_Ecore_EObject_eClass__return->setValue(0);

	ecore_EObject_eContainer__return_lowerValue_LiteralInteger_Ecore_EObject_eContainer__return->setValue(0);

	ecore_EObject_eContainingFeature__return_lowerValue_LiteralInteger_Ecore_EObject_eContainingFeature__return->setValue(0);

	ecore_EObject_eContainmentFeature__return_lowerValue_LiteralInteger_Ecore_EObject_eContainmentFeature__return->setValue(0);

	ecore_EObject_eContents__return_lowerValue_LiteralInteger_Ecore_EObject_eContents__return->setValue(0);

	ecore_EObject_eCrossReferences__return_lowerValue_LiteralInteger_Ecore_EObject_eCrossReferences__return->setValue(0);

	ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean_feature_lowerValue_LiteralInteger_Ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean_feature->setValue(0);

	ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean_resolve_lowerValue_LiteralInteger_Ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean_resolve->setValue(0);

	ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBooleanreturn_lowerValue_LiteralInteger_Ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBooleanreturn->setValue(0);

	ecore_EObject_eGet_EStructuralFeature_EStructuralFeature_feature_lowerValue_LiteralInteger_Ecore_EObject_eGet_EStructuralFeature_EStructuralFeature_feature->setValue(0);

	ecore_EObject_eGet_EStructuralFeature_EStructuralFeaturereturn_lowerValue_LiteralInteger_Ecore_EObject_eGet_EStructuralFeature_EStructuralFeaturereturn->setValue(0);

	ecore_EObject_eIsProxy__return_lowerValue_LiteralInteger_Ecore_EObject_eIsProxy__return->setValue(0);

	ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeature_feature_lowerValue_LiteralInteger_Ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeature_feature->setValue(0);

	ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeaturereturn_lowerValue_LiteralInteger_Ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeaturereturn->setValue(0);

	ecore_EObject_eResource__return_lowerValue_LiteralInteger_Ecore_EObject_eResource__return->setValue(0);

	ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject_feature_lowerValue_LiteralInteger_Ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject_feature->setValue(0);

	ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject_newValue_lowerValue_LiteralInteger_Ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject_newValue->setValue(0);

	ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObjectreturn_lowerValue_LiteralInteger_Ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObjectreturn->setValue(0);

	ecore_EObject_eUnset_EStructuralFeature_EStructuralFeature_feature_lowerValue_LiteralInteger_Ecore_EObject_eUnset_EStructuralFeature_EStructuralFeature_feature->setValue(0);

	ecore_EObject_eUnset_EStructuralFeature_EStructuralFeaturereturn_lowerValue_LiteralInteger_Ecore_EObject_eUnset_EStructuralFeature_EStructuralFeaturereturn->setValue(0);

	ecore_EOperation_eContainingClass_lowerValue_LiteralInteger_Ecore_EOperation_eContainingClass->setValue(0);

	ecore_EOperation_eExceptions_lowerValue_LiteralInteger_Ecore_EOperation_eExceptions->setValue(0);

	ecore_EOperation_eExceptions_upperValue_LiteralUnlimitedNatural_Ecore_EOperation_eExceptions->setValue(-1);

	ecore_EOperation_eGenericExceptions_lowerValue_LiteralInteger_Ecore_EOperation_eGenericExceptions->setValue(0);

	ecore_EOperation_eGenericExceptions_upperValue_LiteralUnlimitedNatural_Ecore_EOperation_eGenericExceptions->setValue(-1);

	ecore_EOperation_eParameters_lowerValue_LiteralInteger_Ecore_EOperation_eParameters->setValue(0);

	ecore_EOperation_eParameters_upperValue_LiteralUnlimitedNatural_Ecore_EOperation_eParameters->setValue(-1);

	ecore_EOperation_eTypeParameters_lowerValue_LiteralInteger_Ecore_EOperation_eTypeParameters->setValue(0);

	ecore_EOperation_eTypeParameters_upperValue_LiteralUnlimitedNatural_Ecore_EOperation_eTypeParameters->setValue(-1);

	ecore_EPackage_eClassifiers_lowerValue_LiteralInteger_Ecore_EPackage_eClassifiers->setValue(0);

	ecore_EPackage_eClassifiers_upperValue_LiteralUnlimitedNatural_Ecore_EPackage_eClassifiers->setValue(-1);

	ecore_EPackage_eSubpackages_lowerValue_LiteralInteger_Ecore_EPackage_eSubpackages->setValue(0);

	ecore_EPackage_eSubpackages_upperValue_LiteralUnlimitedNatural_Ecore_EPackage_eSubpackages->setValue(-1);

	ecore_EPackage_eSuperPackage_lowerValue_LiteralInteger_Ecore_EPackage_eSuperPackage->setValue(0);

	ecore_EPackage_getEClassifier_EString_EString_name_lowerValue_LiteralInteger_Ecore_EPackage_getEClassifier_EString_EString_name->setValue(0);

	ecore_EPackage_getEClassifier_EString_EStringreturn_lowerValue_LiteralInteger_Ecore_EPackage_getEClassifier_EString_EStringreturn->setValue(0);

	ecore_EPackage_nsPrefix_lowerValue_LiteralInteger_Ecore_EPackage_nsPrefix->setValue(0);

	ecore_EPackage_nsURI_lowerValue_LiteralInteger_Ecore_EPackage_nsURI->setValue(0);

	ecore_EParameter_eOperation_lowerValue_LiteralInteger_Ecore_EParameter_eOperation->setValue(0);

	ecore_EReference_container_lowerValue_LiteralInteger_Ecore_EReference_container->setValue(0);

	ecore_EReference_containment_lowerValue_LiteralInteger_Ecore_EReference_containment->setValue(0);

	ecore_EReference_eKeys_lowerValue_LiteralInteger_Ecore_EReference_eKeys->setValue(0);

	ecore_EReference_eKeys_upperValue_LiteralUnlimitedNatural_Ecore_EReference_eKeys->setValue(-1);

	ecore_EReference_eOpposite_lowerValue_LiteralInteger_Ecore_EReference_eOpposite->setValue(0);

	ecore_EReference_resolveProxies_lowerValue_LiteralInteger_Ecore_EReference_resolveProxies->setValue(0);

	ecore_EStringToStringMapEntry_key_lowerValue_LiteralInteger_Ecore_EStringToStringMapEntry_key->setValue(0);

	ecore_EStringToStringMapEntry_value_lowerValue_LiteralInteger_Ecore_EStringToStringMapEntry_value->setValue(0);

	ecore_EStructuralFeature_changeable_lowerValue_LiteralInteger_Ecore_EStructuralFeature_changeable->setValue(0);

	ecore_EStructuralFeature_defaultValueLiteral_lowerValue_LiteralInteger_Ecore_EStructuralFeature_defaultValueLiteral->setValue(0);

	ecore_EStructuralFeature_defaultValue_lowerValue_LiteralInteger_Ecore_EStructuralFeature_defaultValue->setValue(0);

	ecore_EStructuralFeature_derived_lowerValue_LiteralInteger_Ecore_EStructuralFeature_derived->setValue(0);

	ecore_EStructuralFeature_eContainingClass_lowerValue_LiteralInteger_Ecore_EStructuralFeature_eContainingClass->setValue(0);

	ecore_EStructuralFeature_getContainerClass__return_lowerValue_LiteralInteger_Ecore_EStructuralFeature_getContainerClass__return->setValue(0);

	ecore_EStructuralFeature_getFeatureID__return_lowerValue_LiteralInteger_Ecore_EStructuralFeature_getFeatureID__return->setValue(0);

	ecore_EStructuralFeature_transient_lowerValue_LiteralInteger_Ecore_EStructuralFeature_transient->setValue(0);

	ecore_EStructuralFeature_unsettable_lowerValue_LiteralInteger_Ecore_EStructuralFeature_unsettable->setValue(0);

	ecore_EStructuralFeature_volatile_lowerValue_LiteralInteger_Ecore_EStructuralFeature_volatile->setValue(0);

	ecore_ETypeParameter_eBounds_lowerValue_LiteralInteger_Ecore_ETypeParameter_eBounds->setValue(0);

	ecore_ETypeParameter_eBounds_upperValue_LiteralUnlimitedNatural_Ecore_ETypeParameter_eBounds->setValue(-1);

	ecore_ETypedElement_eGenericType_lowerValue_LiteralInteger_Ecore_ETypedElement_eGenericType->setValue(0);

	ecore_ETypedElement_eType_lowerValue_LiteralInteger_Ecore_ETypedElement_eType->setValue(0);

	ecore_ETypedElement_lowerBound_lowerValue_LiteralInteger_Ecore_ETypedElement_lowerBound->setValue(0);

	ecore_ETypedElement_many_lowerValue_LiteralInteger_Ecore_ETypedElement_many->setValue(0);

	ecore_ETypedElement_ordered_lowerValue_LiteralInteger_Ecore_ETypedElement_ordered->setValue(0);

	ecore_ETypedElement_required_lowerValue_LiteralInteger_Ecore_ETypedElement_required->setValue(0);

	ecore_ETypedElement_unique_lowerValue_LiteralInteger_Ecore_ETypedElement_unique->setValue(0);

	ecore_ETypedElement_upperBound_lowerValue_LiteralInteger_Ecore_ETypedElement_upperBound->setValue(0);
}

const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EAnnotation_eAnnotations_Ecore_EModelElement_eModelElement()
{
	return a_Ecore_EAnnotation_eAnnotations_Ecore_EModelElement_eModelElement;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EAttribute_eAllAttributes_eClass()
{
	return a_Ecore_EAttribute_eAllAttributes_eClass;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_A_Ecore_EAttribute_eAllAttributes_eClass_eClass()
{
	return a_Ecore_EAttribute_eAllAttributes_eClass_eClass;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EAttribute_eAttributes_eClass()
{
	return a_Ecore_EAttribute_eAttributes_eClass;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_A_Ecore_EAttribute_eAttributes_eClass_eClass()
{
	return a_Ecore_EAttribute_eAttributes_eClass_eClass;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EAttribute_eIDAttribute_eClass()
{
	return a_Ecore_EAttribute_eIDAttribute_eClass;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_A_Ecore_EAttribute_eIDAttribute_eClass_eClass()
{
	return a_Ecore_EAttribute_eIDAttribute_eClass_eClass;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EAttribute_eKeys_eReference()
{
	return a_Ecore_EAttribute_eKeys_eReference;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_A_Ecore_EAttribute_eKeys_eReference_eReference()
{
	return a_Ecore_EAttribute_eKeys_eReference_eReference;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EClass_eAllSuperTypes_eClass()
{
	return a_Ecore_EClass_eAllSuperTypes_eClass;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_A_Ecore_EClass_eAllSuperTypes_eClass_eClass()
{
	return a_Ecore_EClass_eAllSuperTypes_eClass_eClass;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EClass_eReferenceType_eReference()
{
	return a_Ecore_EClass_eReferenceType_eReference;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_A_Ecore_EClass_eReferenceType_eReference_eReference()
{
	return a_Ecore_EClass_eReferenceType_eReference_eReference;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EClass_eSuperTypes_eClass()
{
	return a_Ecore_EClass_eSuperTypes_eClass;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_A_Ecore_EClass_eSuperTypes_eClass_eClass()
{
	return a_Ecore_EClass_eSuperTypes_eClass_eClass;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EClassifier_eClassifier_eGenericType()
{
	return a_Ecore_EClassifier_eClassifier_eGenericType;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_A_Ecore_EClassifier_eClassifier_eGenericType_eGenericType()
{
	return a_Ecore_EClassifier_eClassifier_eGenericType_eGenericType;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EClassifier_eClassifiers_Ecore_EPackage_ePackage()
{
	return a_Ecore_EClassifier_eClassifiers_Ecore_EPackage_ePackage;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EClassifier_eExceptions_eOperation()
{
	return a_Ecore_EClassifier_eExceptions_eOperation;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_A_Ecore_EClassifier_eExceptions_eOperation_eOperation()
{
	return a_Ecore_EClassifier_eExceptions_eOperation_eOperation;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EClassifier_eRawType_eGenericType()
{
	return a_Ecore_EClassifier_eRawType_eGenericType;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_A_Ecore_EClassifier_eRawType_eGenericType_eGenericType()
{
	return a_Ecore_EClassifier_eRawType_eGenericType_eGenericType;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EClassifier_eType_eTypedElement()
{
	return a_Ecore_EClassifier_eType_eTypedElement;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_A_Ecore_EClassifier_eType_eTypedElement_eTypedElement()
{
	return a_Ecore_EClassifier_eType_eTypedElement_eTypedElement;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EDataType_eAttributeType_eAttribute()
{
	return a_Ecore_EDataType_eAttributeType_eAttribute;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_A_Ecore_EDataType_eAttributeType_eAttribute_eAttribute()
{
	return a_Ecore_EDataType_eAttributeType_eAttribute_eAttribute;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EEnumLiteral_eLiterals_Ecore_EEnum_eEnum()
{
	return a_Ecore_EEnumLiteral_eLiterals_Ecore_EEnum_eEnum;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EGenericType_eAllGenericSuperTypes_eClass()
{
	return a_Ecore_EGenericType_eAllGenericSuperTypes_eClass;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_A_Ecore_EGenericType_eAllGenericSuperTypes_eClass_eClass()
{
	return a_Ecore_EGenericType_eAllGenericSuperTypes_eClass_eClass;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EGenericType_eBounds_eTypeParameter()
{
	return a_Ecore_EGenericType_eBounds_eTypeParameter;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_A_Ecore_EGenericType_eBounds_eTypeParameter_eTypeParameter()
{
	return a_Ecore_EGenericType_eBounds_eTypeParameter_eTypeParameter;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EGenericType_eGenericExceptions_eOperation()
{
	return a_Ecore_EGenericType_eGenericExceptions_eOperation;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_A_Ecore_EGenericType_eGenericExceptions_eOperation_eOperation()
{
	return a_Ecore_EGenericType_eGenericExceptions_eOperation_eOperation;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EGenericType_eGenericSuperTypes_eClass()
{
	return a_Ecore_EGenericType_eGenericSuperTypes_eClass;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_A_Ecore_EGenericType_eGenericSuperTypes_eClass_eClass()
{
	return a_Ecore_EGenericType_eGenericSuperTypes_eClass_eClass;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EGenericType_eGenericType_eTypedElement()
{
	return a_Ecore_EGenericType_eGenericType_eTypedElement;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_A_Ecore_EGenericType_eGenericType_eTypedElement_eTypedElement()
{
	return a_Ecore_EGenericType_eGenericType_eTypedElement_eTypedElement;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EGenericType_eLowerBound_eGenericType()
{
	return a_Ecore_EGenericType_eLowerBound_eGenericType;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_A_Ecore_EGenericType_eLowerBound_eGenericType_eGenericType()
{
	return a_Ecore_EGenericType_eLowerBound_eGenericType_eGenericType;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EGenericType_eTypeArguments_eGenericType()
{
	return a_Ecore_EGenericType_eTypeArguments_eGenericType;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_A_Ecore_EGenericType_eTypeArguments_eGenericType_eGenericType()
{
	return a_Ecore_EGenericType_eTypeArguments_eGenericType_eGenericType;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EGenericType_eUpperBound_eGenericType()
{
	return a_Ecore_EGenericType_eUpperBound_eGenericType;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_A_Ecore_EGenericType_eUpperBound_eGenericType_eGenericType()
{
	return a_Ecore_EGenericType_eUpperBound_eGenericType_eGenericType;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EObject_contents_eAnnotation()
{
	return a_Ecore_EObject_contents_eAnnotation;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_A_Ecore_EObject_contents_eAnnotation_eAnnotation()
{
	return a_Ecore_EObject_contents_eAnnotation_eAnnotation;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EObject_references_eAnnotation()
{
	return a_Ecore_EObject_references_eAnnotation;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_A_Ecore_EObject_references_eAnnotation_eAnnotation()
{
	return a_Ecore_EObject_references_eAnnotation_eAnnotation;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EOperation_eAllOperations_eClass()
{
	return a_Ecore_EOperation_eAllOperations_eClass;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_A_Ecore_EOperation_eAllOperations_eClass_eClass()
{
	return a_Ecore_EOperation_eAllOperations_eClass_eClass;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EOperation_eOperations_Ecore_EClass_eContainingClass()
{
	return a_Ecore_EOperation_eOperations_Ecore_EClass_eContainingClass;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EPackage_ePackage_Ecore_EFactory_eFactoryInstance()
{
	return a_Ecore_EPackage_ePackage_Ecore_EFactory_eFactoryInstance;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EPackage_eSubpackages_Ecore_EPackage_eSuperPackage()
{
	return a_Ecore_EPackage_eSubpackages_Ecore_EPackage_eSuperPackage;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EParameter_eParameters_Ecore_EOperation_eOperation()
{
	return a_Ecore_EParameter_eParameters_Ecore_EOperation_eOperation;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EReference_eAllContainments_eClass()
{
	return a_Ecore_EReference_eAllContainments_eClass;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_A_Ecore_EReference_eAllContainments_eClass_eClass()
{
	return a_Ecore_EReference_eAllContainments_eClass_eClass;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EReference_eAllReferences_eClass()
{
	return a_Ecore_EReference_eAllReferences_eClass;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_A_Ecore_EReference_eAllReferences_eClass_eClass()
{
	return a_Ecore_EReference_eAllReferences_eClass_eClass;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EReference_eOpposite_eReference()
{
	return a_Ecore_EReference_eOpposite_eReference;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_A_Ecore_EReference_eOpposite_eReference_eReference()
{
	return a_Ecore_EReference_eOpposite_eReference_eReference;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EReference_eReferences_eClass()
{
	return a_Ecore_EReference_eReferences_eClass;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_A_Ecore_EReference_eReferences_eClass_eClass()
{
	return a_Ecore_EReference_eReferences_eClass_eClass;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EStringToStringMapEntry_details_eAnnotation()
{
	return a_Ecore_EStringToStringMapEntry_details_eAnnotation;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_A_Ecore_EStringToStringMapEntry_details_eAnnotation_eAnnotation()
{
	return a_Ecore_EStringToStringMapEntry_details_eAnnotation_eAnnotation;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EStructuralFeature_eAllStructuralFeatures_eClass()
{
	return a_Ecore_EStructuralFeature_eAllStructuralFeatures_eClass;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_A_Ecore_EStructuralFeature_eAllStructuralFeatures_eClass_eClass()
{
	return a_Ecore_EStructuralFeature_eAllStructuralFeatures_eClass_eClass;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_EStructuralFeature_eStructuralFeatures_Ecore_EClass_eContainingClass()
{
	return a_Ecore_EStructuralFeature_eStructuralFeatures_Ecore_EClass_eContainingClass;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_ETypeParameter_eTypeParameter_eGenericType()
{
	return a_Ecore_ETypeParameter_eTypeParameter_eGenericType;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_A_Ecore_ETypeParameter_eTypeParameter_eGenericType_eGenericType()
{
	return a_Ecore_ETypeParameter_eTypeParameter_eGenericType_eGenericType;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_ETypeParameter_eTypeParameters_eClassifier()
{
	return a_Ecore_ETypeParameter_eTypeParameters_eClassifier;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_A_Ecore_ETypeParameter_eTypeParameters_eClassifier_eClassifier()
{
	return a_Ecore_ETypeParameter_eTypeParameters_eClassifier_eClassifier;
}
const std::shared_ptr<uml::Association>& EcorePackageImpl::get_A_Ecore_ETypeParameter_eTypeParameters_eOperation()
{
	return a_Ecore_ETypeParameter_eTypeParameters_eOperation;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_A_Ecore_ETypeParameter_eTypeParameters_eOperation_eOperation()
{
	return a_Ecore_ETypeParameter_eTypeParameters_eOperation_eOperation;
}
const std::shared_ptr<uml::Class>& EcorePackageImpl::get_Ecore_EAnnotation()
{
	return ecore_EAnnotation;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EAnnotation_contents()
{
	return ecore_EAnnotation_contents;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EAnnotation_details()
{
	return ecore_EAnnotation_details;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EAnnotation_eModelElement()
{
	return ecore_EAnnotation_eModelElement;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EAnnotation_references()
{
	return ecore_EAnnotation_references;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EAnnotation_source()
{
	return ecore_EAnnotation_source;
}
const std::shared_ptr<uml::Class>& EcorePackageImpl::get_Ecore_EAttribute()
{
	return ecore_EAttribute;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EAttribute_eAttributeType()
{
	return ecore_EAttribute_eAttributeType;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EAttribute_id()
{
	return ecore_EAttribute_id;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_EBigDecimal()
{
	return ecore_EBigDecimal;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_EBigInteger()
{
	return ecore_EBigInteger;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_EBoolean()
{
	return ecore_EBoolean;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_EBooleanObject()
{
	return ecore_EBooleanObject;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_EByte()
{
	return ecore_EByte;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_EByteArray()
{
	return ecore_EByteArray;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_EByteObject()
{
	return ecore_EByteObject;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_EChar()
{
	return ecore_EChar;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_ECharacterObject()
{
	return ecore_ECharacterObject;
}
const std::shared_ptr<uml::Class>& EcorePackageImpl::get_Ecore_EClass()
{
	return ecore_EClass;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EClass_abstract()
{
	return ecore_EClass_abstract;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EClass_eAllAttributes()
{
	return ecore_EClass_eAllAttributes;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EClass_eAllContainments()
{
	return ecore_EClass_eAllContainments;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EClass_eAllGenericSuperTypes()
{
	return ecore_EClass_eAllGenericSuperTypes;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EClass_eAllOperations()
{
	return ecore_EClass_eAllOperations;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EClass_eAllReferences()
{
	return ecore_EClass_eAllReferences;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EClass_eAllStructuralFeatures()
{
	return ecore_EClass_eAllStructuralFeatures;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EClass_eAllSuperTypes()
{
	return ecore_EClass_eAllSuperTypes;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EClass_eAttributes()
{
	return ecore_EClass_eAttributes;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EClass_eGenericSuperTypes()
{
	return ecore_EClass_eGenericSuperTypes;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EClass_eIDAttribute()
{
	return ecore_EClass_eIDAttribute;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EClass_eOperations()
{
	return ecore_EClass_eOperations;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EClass_eReferences()
{
	return ecore_EClass_eReferences;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EClass_eStructuralFeatures()
{
	return ecore_EClass_eStructuralFeatures;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EClass_eSuperTypes()
{
	return ecore_EClass_eSuperTypes;
}
const std::shared_ptr<uml::Operation>& EcorePackageImpl::get_Ecore_EClass_getEStructuralFeature_EInt_EInt()
{
	return ecore_EClass_getEStructuralFeature_EInt_EInt;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EClass_getEStructuralFeature_EInt_EInt_featureID()
{
	return ecore_EClass_getEStructuralFeature_EInt_EInt_featureID;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EClass_getEStructuralFeature_EInt_EIntreturn()
{
	return ecore_EClass_getEStructuralFeature_EInt_EIntreturn;
}
const std::shared_ptr<uml::Operation>& EcorePackageImpl::get_Ecore_EClass_getEStructuralFeature_EString_EString()
{
	return ecore_EClass_getEStructuralFeature_EString_EString;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EClass_getEStructuralFeature_EString_EString_featureName()
{
	return ecore_EClass_getEStructuralFeature_EString_EString_featureName;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EClass_getEStructuralFeature_EString_EStringreturn()
{
	return ecore_EClass_getEStructuralFeature_EString_EStringreturn;
}
const std::shared_ptr<uml::Operation>& EcorePackageImpl::get_Ecore_EClass_getFeatureCount__()
{
	return ecore_EClass_getFeatureCount__;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EClass_getFeatureCount__return()
{
	return ecore_EClass_getFeatureCount__return;
}
const std::shared_ptr<uml::Operation>& EcorePackageImpl::get_Ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeature()
{
	return ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeature;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeature_feature()
{
	return ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeature_feature;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeaturereturn()
{
	return ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeaturereturn;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EClass_interface()
{
	return ecore_EClass_interface;
}
const std::shared_ptr<uml::Operation>& EcorePackageImpl::get_Ecore_EClass_isSuperTypeOf_EClass_EClass()
{
	return ecore_EClass_isSuperTypeOf_EClass_EClass;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EClass_isSuperTypeOf_EClass_EClass_someClass()
{
	return ecore_EClass_isSuperTypeOf_EClass_EClass_someClass;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EClass_isSuperTypeOf_EClass_EClassreturn()
{
	return ecore_EClass_isSuperTypeOf_EClass_EClassreturn;
}
const std::shared_ptr<uml::Class>& EcorePackageImpl::get_Ecore_EClassifier()
{
	return ecore_EClassifier;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_EClassifier_EJavaClass_Wildcard()
{
	return ecore_EClassifier_EJavaClass_Wildcard;
}
const std::shared_ptr<uml::Class>& EcorePackageImpl::get_Ecore_EClassifier_Wildcard()
{
	return ecore_EClassifier_Wildcard;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EClassifier_defaultValue()
{
	return ecore_EClassifier_defaultValue;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EClassifier_ePackage()
{
	return ecore_EClassifier_ePackage;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EClassifier_eTypeParameters()
{
	return ecore_EClassifier_eTypeParameters;
}
const std::shared_ptr<uml::Operation>& EcorePackageImpl::get_Ecore_EClassifier_getClassifierID__()
{
	return ecore_EClassifier_getClassifierID__;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EClassifier_getClassifierID__return()
{
	return ecore_EClassifier_getClassifierID__return;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EClassifier_instanceClass()
{
	return ecore_EClassifier_instanceClass;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EClassifier_instanceClassName()
{
	return ecore_EClassifier_instanceClassName;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EClassifier_instanceTypeName()
{
	return ecore_EClassifier_instanceTypeName;
}
const std::shared_ptr<uml::Operation>& EcorePackageImpl::get_Ecore_EClassifier_isInstance_EJavaObject_EJavaObject()
{
	return ecore_EClassifier_isInstance_EJavaObject_EJavaObject;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EClassifier_isInstance_EJavaObject_EJavaObject_object()
{
	return ecore_EClassifier_isInstance_EJavaObject_EJavaObject_object;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EClassifier_isInstance_EJavaObject_EJavaObjectreturn()
{
	return ecore_EClassifier_isInstance_EJavaObject_EJavaObjectreturn;
}
const std::shared_ptr<uml::Class>& EcorePackageImpl::get_Ecore_EDataType()
{
	return ecore_EDataType;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EDataType_serializable()
{
	return ecore_EDataType_serializable;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_EDate()
{
	return ecore_EDate;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_EDiagnosticChain()
{
	return ecore_EDiagnosticChain;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_EDouble()
{
	return ecore_EDouble;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_EDoubleObject()
{
	return ecore_EDoubleObject;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_EEList()
{
	return ecore_EEList;
}
const std::shared_ptr<uml::Class>& EcorePackageImpl::get_Ecore_EEList_E()
{
	return ecore_EEList_E;
}
const std::shared_ptr<uml::RedefinableTemplateSignature>& EcorePackageImpl::get_Ecore_EEList_RedefinableTemplateSignature()
{
	return ecore_EEList_RedefinableTemplateSignature;
}
const std::shared_ptr<uml::Class>& EcorePackageImpl::get_Ecore_EEnum()
{
	return ecore_EEnum;
}
const std::shared_ptr<uml::Class>& EcorePackageImpl::get_Ecore_EEnumLiteral()
{
	return ecore_EEnumLiteral;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EEnumLiteral_eEnum()
{
	return ecore_EEnumLiteral_eEnum;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EEnumLiteral_instance()
{
	return ecore_EEnumLiteral_instance;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EEnumLiteral_literal()
{
	return ecore_EEnumLiteral_literal;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EEnumLiteral_value()
{
	return ecore_EEnumLiteral_value;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EEnum_eLiterals()
{
	return ecore_EEnum_eLiterals;
}
const std::shared_ptr<uml::Operation>& EcorePackageImpl::get_Ecore_EEnum_getEEnumLiteralByLiteral_EString_EString()
{
	return ecore_EEnum_getEEnumLiteralByLiteral_EString_EString;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EEnum_getEEnumLiteralByLiteral_EString_EString_literal()
{
	return ecore_EEnum_getEEnumLiteralByLiteral_EString_EString_literal;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EEnum_getEEnumLiteralByLiteral_EString_EStringreturn()
{
	return ecore_EEnum_getEEnumLiteralByLiteral_EString_EStringreturn;
}
const std::shared_ptr<uml::Operation>& EcorePackageImpl::get_Ecore_EEnum_getEEnumLiteral_EInt_EInt()
{
	return ecore_EEnum_getEEnumLiteral_EInt_EInt;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EEnum_getEEnumLiteral_EInt_EInt_value()
{
	return ecore_EEnum_getEEnumLiteral_EInt_EInt_value;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EEnum_getEEnumLiteral_EInt_EIntreturn()
{
	return ecore_EEnum_getEEnumLiteral_EInt_EIntreturn;
}
const std::shared_ptr<uml::Operation>& EcorePackageImpl::get_Ecore_EEnum_getEEnumLiteral_EString_EString()
{
	return ecore_EEnum_getEEnumLiteral_EString_EString;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EEnum_getEEnumLiteral_EString_EString_name()
{
	return ecore_EEnum_getEEnumLiteral_EString_EString_name;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EEnum_getEEnumLiteral_EString_EStringreturn()
{
	return ecore_EEnum_getEEnumLiteral_EString_EStringreturn;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_EEnumerator()
{
	return ecore_EEnumerator;
}
const std::shared_ptr<uml::Class>& EcorePackageImpl::get_Ecore_EFactory()
{
	return ecore_EFactory;
}
const std::shared_ptr<uml::Operation>& EcorePackageImpl::get_Ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject()
{
	return ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject_eDataType()
{
	return ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject_eDataType;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject_instanceValue()
{
	return ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject_instanceValue;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObjectreturn()
{
	return ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObjectreturn;
}
const std::shared_ptr<uml::Operation>& EcorePackageImpl::get_Ecore_EFactory_createFromString_EDataType_EString_EDataType_EString()
{
	return ecore_EFactory_createFromString_EDataType_EString_EDataType_EString;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EFactory_createFromString_EDataType_EString_EDataType_EString_eDataType()
{
	return ecore_EFactory_createFromString_EDataType_EString_EDataType_EString_eDataType;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EFactory_createFromString_EDataType_EString_EDataType_EString_literalValue()
{
	return ecore_EFactory_createFromString_EDataType_EString_EDataType_EString_literalValue;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EFactory_createFromString_EDataType_EString_EDataType_EStringreturn()
{
	return ecore_EFactory_createFromString_EDataType_EString_EDataType_EStringreturn;
}
const std::shared_ptr<uml::Operation>& EcorePackageImpl::get_Ecore_EFactory_create_EClass_EClass()
{
	return ecore_EFactory_create_EClass_EClass;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EFactory_create_EClass_EClass_eClass()
{
	return ecore_EFactory_create_EClass_EClass_eClass;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EFactory_create_EClass_EClassreturn()
{
	return ecore_EFactory_create_EClass_EClassreturn;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EFactory_ePackage()
{
	return ecore_EFactory_ePackage;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_EFeatureMap()
{
	return ecore_EFeatureMap;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_EFeatureMapEntry()
{
	return ecore_EFeatureMapEntry;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_EFloat()
{
	return ecore_EFloat;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_EFloatObject()
{
	return ecore_EFloatObject;
}
const std::shared_ptr<uml::Class>& EcorePackageImpl::get_Ecore_EGenericType()
{
	return ecore_EGenericType;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EGenericType_eClassifier()
{
	return ecore_EGenericType_eClassifier;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EGenericType_eLowerBound()
{
	return ecore_EGenericType_eLowerBound;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EGenericType_eRawType()
{
	return ecore_EGenericType_eRawType;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EGenericType_eTypeArguments()
{
	return ecore_EGenericType_eTypeArguments;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EGenericType_eTypeParameter()
{
	return ecore_EGenericType_eTypeParameter;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EGenericType_eUpperBound()
{
	return ecore_EGenericType_eUpperBound;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_EInt()
{
	return ecore_EInt;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_EIntegerObject()
{
	return ecore_EIntegerObject;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_EInvocationTargetException()
{
	return ecore_EInvocationTargetException;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_EJavaClass()
{
	return ecore_EJavaClass;
}
const std::shared_ptr<uml::RedefinableTemplateSignature>& EcorePackageImpl::get_Ecore_EJavaClass_RedefinableTemplateSignature()
{
	return ecore_EJavaClass_RedefinableTemplateSignature;
}
const std::shared_ptr<uml::Class>& EcorePackageImpl::get_Ecore_EJavaClass_T()
{
	return ecore_EJavaClass_T;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_EJavaObject()
{
	return ecore_EJavaObject;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_ELong()
{
	return ecore_ELong;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_ELongObject()
{
	return ecore_ELongObject;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_EMap()
{
	return ecore_EMap;
}
const std::shared_ptr<uml::Class>& EcorePackageImpl::get_Ecore_EMap_K()
{
	return ecore_EMap_K;
}
const std::shared_ptr<uml::RedefinableTemplateSignature>& EcorePackageImpl::get_Ecore_EMap_RedefinableTemplateSignature()
{
	return ecore_EMap_RedefinableTemplateSignature;
}
const std::shared_ptr<uml::Class>& EcorePackageImpl::get_Ecore_EMap_V()
{
	return ecore_EMap_V;
}
const std::shared_ptr<uml::Class>& EcorePackageImpl::get_Ecore_EModelElement()
{
	return ecore_EModelElement;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EModelElement_eAnnotations()
{
	return ecore_EModelElement_eAnnotations;
}
const std::shared_ptr<uml::Operation>& EcorePackageImpl::get_Ecore_EModelElement_getEAnnotation_EString_EString()
{
	return ecore_EModelElement_getEAnnotation_EString_EString;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EModelElement_getEAnnotation_EString_EString_source()
{
	return ecore_EModelElement_getEAnnotation_EString_EString_source;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EModelElement_getEAnnotation_EString_EStringreturn()
{
	return ecore_EModelElement_getEAnnotation_EString_EStringreturn;
}
const std::shared_ptr<uml::Class>& EcorePackageImpl::get_Ecore_ENamedElement()
{
	return ecore_ENamedElement;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_ENamedElement_name()
{
	return ecore_ENamedElement_name;
}
const std::shared_ptr<uml::Class>& EcorePackageImpl::get_Ecore_EObject()
{
	return ecore_EObject;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_EObject_EEList_EObject()
{
	return ecore_EObject_EEList_EObject;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_EObject_ETreeIterator_EObject()
{
	return ecore_EObject_ETreeIterator_EObject;
}
const std::shared_ptr<uml::Operation>& EcorePackageImpl::get_Ecore_EObject_eAllContents__()
{
	return ecore_EObject_eAllContents__;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EObject_eAllContents__return()
{
	return ecore_EObject_eAllContents__return;
}
const std::shared_ptr<uml::Operation>& EcorePackageImpl::get_Ecore_EObject_eClass__()
{
	return ecore_EObject_eClass__;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EObject_eClass__return()
{
	return ecore_EObject_eClass__return;
}
const std::shared_ptr<uml::Operation>& EcorePackageImpl::get_Ecore_EObject_eContainer__()
{
	return ecore_EObject_eContainer__;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EObject_eContainer__return()
{
	return ecore_EObject_eContainer__return;
}
const std::shared_ptr<uml::Operation>& EcorePackageImpl::get_Ecore_EObject_eContainingFeature__()
{
	return ecore_EObject_eContainingFeature__;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EObject_eContainingFeature__return()
{
	return ecore_EObject_eContainingFeature__return;
}
const std::shared_ptr<uml::Operation>& EcorePackageImpl::get_Ecore_EObject_eContainmentFeature__()
{
	return ecore_EObject_eContainmentFeature__;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EObject_eContainmentFeature__return()
{
	return ecore_EObject_eContainmentFeature__return;
}
const std::shared_ptr<uml::Operation>& EcorePackageImpl::get_Ecore_EObject_eContents__()
{
	return ecore_EObject_eContents__;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EObject_eContents__return()
{
	return ecore_EObject_eContents__return;
}
const std::shared_ptr<uml::Operation>& EcorePackageImpl::get_Ecore_EObject_eCrossReferences__()
{
	return ecore_EObject_eCrossReferences__;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EObject_eCrossReferences__return()
{
	return ecore_EObject_eCrossReferences__return;
}
const std::shared_ptr<uml::Operation>& EcorePackageImpl::get_Ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean()
{
	return ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean_feature()
{
	return ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean_feature;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean_resolve()
{
	return ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean_resolve;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBooleanreturn()
{
	return ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBooleanreturn;
}
const std::shared_ptr<uml::Operation>& EcorePackageImpl::get_Ecore_EObject_eGet_EStructuralFeature_EStructuralFeature()
{
	return ecore_EObject_eGet_EStructuralFeature_EStructuralFeature;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EObject_eGet_EStructuralFeature_EStructuralFeature_feature()
{
	return ecore_EObject_eGet_EStructuralFeature_EStructuralFeature_feature;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EObject_eGet_EStructuralFeature_EStructuralFeaturereturn()
{
	return ecore_EObject_eGet_EStructuralFeature_EStructuralFeaturereturn;
}
const std::shared_ptr<uml::Operation>& EcorePackageImpl::get_Ecore_EObject_eIsProxy__()
{
	return ecore_EObject_eIsProxy__;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EObject_eIsProxy__return()
{
	return ecore_EObject_eIsProxy__return;
}
const std::shared_ptr<uml::Operation>& EcorePackageImpl::get_Ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeature()
{
	return ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeature;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeature_feature()
{
	return ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeature_feature;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeaturereturn()
{
	return ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeaturereturn;
}
const std::shared_ptr<uml::Operation>& EcorePackageImpl::get_Ecore_EObject_eResource__()
{
	return ecore_EObject_eResource__;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EObject_eResource__return()
{
	return ecore_EObject_eResource__return;
}
const std::shared_ptr<uml::Operation>& EcorePackageImpl::get_Ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject()
{
	return ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject_feature()
{
	return ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject_feature;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject_newValue()
{
	return ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject_newValue;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObjectreturn()
{
	return ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObjectreturn;
}
const std::shared_ptr<uml::Operation>& EcorePackageImpl::get_Ecore_EObject_eUnset_EStructuralFeature_EStructuralFeature()
{
	return ecore_EObject_eUnset_EStructuralFeature_EStructuralFeature;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EObject_eUnset_EStructuralFeature_EStructuralFeature_feature()
{
	return ecore_EObject_eUnset_EStructuralFeature_EStructuralFeature_feature;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EObject_eUnset_EStructuralFeature_EStructuralFeaturereturn()
{
	return ecore_EObject_eUnset_EStructuralFeature_EStructuralFeaturereturn;
}
const std::shared_ptr<uml::Class>& EcorePackageImpl::get_Ecore_EOperation()
{
	return ecore_EOperation;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EOperation_eContainingClass()
{
	return ecore_EOperation_eContainingClass;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EOperation_eExceptions()
{
	return ecore_EOperation_eExceptions;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EOperation_eGenericExceptions()
{
	return ecore_EOperation_eGenericExceptions;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EOperation_eParameters()
{
	return ecore_EOperation_eParameters;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EOperation_eTypeParameters()
{
	return ecore_EOperation_eTypeParameters;
}
const std::shared_ptr<uml::Class>& EcorePackageImpl::get_Ecore_EPackage()
{
	return ecore_EPackage;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EPackage_eClassifiers()
{
	return ecore_EPackage_eClassifiers;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EPackage_eFactoryInstance()
{
	return ecore_EPackage_eFactoryInstance;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EPackage_eSubpackages()
{
	return ecore_EPackage_eSubpackages;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EPackage_eSuperPackage()
{
	return ecore_EPackage_eSuperPackage;
}
const std::shared_ptr<uml::Operation>& EcorePackageImpl::get_Ecore_EPackage_getEClassifier_EString_EString()
{
	return ecore_EPackage_getEClassifier_EString_EString;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EPackage_getEClassifier_EString_EString_name()
{
	return ecore_EPackage_getEClassifier_EString_EString_name;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EPackage_getEClassifier_EString_EStringreturn()
{
	return ecore_EPackage_getEClassifier_EString_EStringreturn;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EPackage_nsPrefix()
{
	return ecore_EPackage_nsPrefix;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EPackage_nsURI()
{
	return ecore_EPackage_nsURI;
}
const std::shared_ptr<uml::Class>& EcorePackageImpl::get_Ecore_EParameter()
{
	return ecore_EParameter;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EParameter_eOperation()
{
	return ecore_EParameter_eOperation;
}
const std::shared_ptr<uml::Class>& EcorePackageImpl::get_Ecore_EReference()
{
	return ecore_EReference;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EReference_container()
{
	return ecore_EReference_container;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EReference_containment()
{
	return ecore_EReference_containment;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EReference_eKeys()
{
	return ecore_EReference_eKeys;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EReference_eOpposite()
{
	return ecore_EReference_eOpposite;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EReference_eReferenceType()
{
	return ecore_EReference_eReferenceType;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EReference_resolveProxies()
{
	return ecore_EReference_resolveProxies;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_EResource()
{
	return ecore_EResource;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_EResourceSet()
{
	return ecore_EResourceSet;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_EShort()
{
	return ecore_EShort;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_EShortObject()
{
	return ecore_EShortObject;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_EString()
{
	return ecore_EString;
}
const std::shared_ptr<uml::Class>& EcorePackageImpl::get_Ecore_EStringToStringMapEntry()
{
	return ecore_EStringToStringMapEntry;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EStringToStringMapEntry_key()
{
	return ecore_EStringToStringMapEntry_key;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EStringToStringMapEntry_value()
{
	return ecore_EStringToStringMapEntry_value;
}
const std::shared_ptr<uml::Class>& EcorePackageImpl::get_Ecore_EStructuralFeature()
{
	return ecore_EStructuralFeature;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_EStructuralFeature_EJavaClass_Wildcard()
{
	return ecore_EStructuralFeature_EJavaClass_Wildcard;
}
const std::shared_ptr<uml::Class>& EcorePackageImpl::get_Ecore_EStructuralFeature_Wildcard()
{
	return ecore_EStructuralFeature_Wildcard;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EStructuralFeature_changeable()
{
	return ecore_EStructuralFeature_changeable;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EStructuralFeature_defaultValue()
{
	return ecore_EStructuralFeature_defaultValue;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EStructuralFeature_defaultValueLiteral()
{
	return ecore_EStructuralFeature_defaultValueLiteral;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EStructuralFeature_derived()
{
	return ecore_EStructuralFeature_derived;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EStructuralFeature_eContainingClass()
{
	return ecore_EStructuralFeature_eContainingClass;
}
const std::shared_ptr<uml::Operation>& EcorePackageImpl::get_Ecore_EStructuralFeature_getContainerClass__()
{
	return ecore_EStructuralFeature_getContainerClass__;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EStructuralFeature_getContainerClass__return()
{
	return ecore_EStructuralFeature_getContainerClass__return;
}
const std::shared_ptr<uml::Operation>& EcorePackageImpl::get_Ecore_EStructuralFeature_getFeatureID__()
{
	return ecore_EStructuralFeature_getFeatureID__;
}
const std::shared_ptr<uml::Parameter>& EcorePackageImpl::get_Ecore_EStructuralFeature_getFeatureID__return()
{
	return ecore_EStructuralFeature_getFeatureID__return;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EStructuralFeature_transient()
{
	return ecore_EStructuralFeature_transient;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EStructuralFeature_unsettable()
{
	return ecore_EStructuralFeature_unsettable;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_EStructuralFeature_volatile()
{
	return ecore_EStructuralFeature_volatile;
}
const std::shared_ptr<uml::PrimitiveType>& EcorePackageImpl::get_Ecore_ETreeIterator()
{
	return ecore_ETreeIterator;
}
const std::shared_ptr<uml::Class>& EcorePackageImpl::get_Ecore_ETreeIterator_E()
{
	return ecore_ETreeIterator_E;
}
const std::shared_ptr<uml::RedefinableTemplateSignature>& EcorePackageImpl::get_Ecore_ETreeIterator_RedefinableTemplateSignature()
{
	return ecore_ETreeIterator_RedefinableTemplateSignature;
}
const std::shared_ptr<uml::Class>& EcorePackageImpl::get_Ecore_ETypeParameter()
{
	return ecore_ETypeParameter;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_ETypeParameter_eBounds()
{
	return ecore_ETypeParameter_eBounds;
}
const std::shared_ptr<uml::Class>& EcorePackageImpl::get_Ecore_ETypedElement()
{
	return ecore_ETypedElement;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_ETypedElement_eGenericType()
{
	return ecore_ETypedElement_eGenericType;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_ETypedElement_eType()
{
	return ecore_ETypedElement_eType;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_ETypedElement_lowerBound()
{
	return ecore_ETypedElement_lowerBound;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_ETypedElement_many()
{
	return ecore_ETypedElement_many;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_ETypedElement_ordered()
{
	return ecore_ETypedElement_ordered;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_ETypedElement_required()
{
	return ecore_ETypedElement_required;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_ETypedElement_unique()
{
	return ecore_ETypedElement_unique;
}
const std::shared_ptr<uml::Property>& EcorePackageImpl::get_Ecore_ETypedElement_upperBound()
{
	return ecore_ETypedElement_upperBound;
}




