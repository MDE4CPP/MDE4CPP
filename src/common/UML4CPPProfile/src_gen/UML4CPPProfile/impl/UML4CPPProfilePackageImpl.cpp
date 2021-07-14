#include "UML4CPPProfile/impl/UML4CPPProfilePackageImpl.hpp"

//meta meta model classes
#include "uml/Class.hpp"
#include "uml/Comment.hpp"
#include "uml/Extension.hpp"
#include "uml/ExtensionEnd.hpp"
#include "uml/LiteralBoolean.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PrimitiveType.hpp"
#include "uml/Property.hpp"
#include "uml/Stereotype.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "uml/VisibilityKind.hpp"
//meta meta model factory
#include "uml/umlFactory.hpp"

//metamodel factory
#include "UML4CPPProfile/UML4CPPProfileFactory.hpp"

//depending model packages
#include "ecoreReflection/EcorePackage.hpp"
#include "primitivetypesReflection/PrimitiveTypesPackage.hpp"
#include "umlReflection/UMLPackage.hpp"

//Subpackages

//Stereotypes

using namespace UML4CPPProfile;

UML4CPPProfilePackageImpl::UML4CPPProfilePackageImpl()
{
}

UML4CPPProfilePackageImpl::~UML4CPPProfilePackageImpl()
{
}

bool UML4CPPProfilePackageImpl::isInited = false;

UML4CPPProfilePackage* UML4CPPProfilePackageImpl::create()
{
	if (isInited)
	{
		return UML4CPPProfilePackage::eInstance().get();
	}
	isInited = true;
	
    // Obtain or create and register package, create package meta-data objects
    UML4CPPProfilePackageImpl * metaModelPackage = new UML4CPPProfilePackageImpl();
    return metaModelPackage;
}

void UML4CPPProfilePackageImpl::init(std::shared_ptr<uml::Package> uML4CPPProfile)
{
    // Initialize created meta-data
	setThisPackagePtr(uML4CPPProfile);
	initMetaModel();
    createPackageContents(uML4CPPProfile);
    initializePackageContents(uML4CPPProfile);   
}

void UML4CPPProfilePackageImpl::initMetaModel()
{
}

void UML4CPPProfilePackageImpl::createPackageContents(std::shared_ptr<uml::Package> uML4CPPProfile)
{
	if (isCreated)
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<uml::umlFactory> factory = uml::umlFactory::eInstance();

	createPackageValueSpecifications(uML4CPPProfile, factory);
	createPackageInterfaces(uML4CPPProfile, factory);
	createPackageClasses(uML4CPPProfile, factory);
	createPackageAssociations(uML4CPPProfile, factory);
	createPackageInstanceSpecifications(uML4CPPProfile, factory);
	createPackageStereotypes(uML4CPPProfile, factory);
	createPackageActivities(uML4CPPProfile, factory);
	createPackageDependencies(uML4CPPProfile, factory);
	createPackagePrimitiveTypes(uML4CPPProfile, factory);
	createPackageEnumerationLiterals(uML4CPPProfile, factory);
	createPackageInterfaceRealizations(uML4CPPProfile, factory);
}

void UML4CPPProfilePackageImpl::createPackageActivities(std::shared_ptr<uml::Package> uML4CPPProfile, std::shared_ptr<uml::umlFactory> factory)
{
}


void UML4CPPProfilePackageImpl::createPackageClasses(std::shared_ptr<uml::Package> uML4CPPProfile, std::shared_ptr<uml::umlFactory> factory)
{
	std::shared_ptr<uml::Constraint> con = nullptr;
	std::shared_ptr<uml::OpaqueExpression> oe = nullptr;


//-------------------------------------------
//Opaque Behaviors

} 

void UML4CPPProfilePackageImpl::createPackageAssociations(std::shared_ptr<uml::Package> uML4CPPProfile, std::shared_ptr<uml::umlFactory> factory)
{
}

void UML4CPPProfilePackageImpl::createPackageDependencies(std::shared_ptr<uml::Package> uML4CPPProfile, std::shared_ptr<uml::umlFactory> factory)
{
}

void UML4CPPProfilePackageImpl::createPackageEnumerationLiterals(std::shared_ptr<uml::Package> uML4CPPProfile, std::shared_ptr<uml::umlFactory> factory)
{
}

void UML4CPPProfilePackageImpl::createPackageInstanceSpecifications(std::shared_ptr<uml::Package> uML4CPPProfile, std::shared_ptr<uml::umlFactory> factory)
{
}

void UML4CPPProfilePackageImpl::createPackageInterfaceRealizations(std::shared_ptr<uml::Package> uML4CPPProfile, std::shared_ptr<uml::umlFactory> factory)
{
}

void UML4CPPProfilePackageImpl::createPackageInterfaces(std::shared_ptr<uml::Package> uML4CPPProfile, std::shared_ptr<uml::umlFactory> factory)
{
}

void UML4CPPProfilePackageImpl::createPackagePrimitiveTypes(std::shared_ptr<uml::Package> uML4CPPProfile, std::shared_ptr<uml::umlFactory> factory)
{
}

void UML4CPPProfilePackageImpl::createPackageStereotypes(std::shared_ptr<uml::Package> uML4CPPProfile, std::shared_ptr<uml::umlFactory> factory)
{
	uML4CPPProfile_DoNotGenerate = factory->createStereotype_in_Package(uML4CPPProfile, UML4CPPProfile::UML4CPPProfilePackage::DONOTGENERATE_CLASS);
	uML4CPPProfile_DoNotGenerate->setName("DoNotGenerate");
	uML4CPPProfile_DoNotGenerate->setIsAbstract(false);
	uML4CPPProfile_DoNotGenerate_base_Element = factory->createProperty_in_Class(uML4CPPProfile_DoNotGenerate);
	

	uML4CPPProfile_ExternalLibrary = factory->createStereotype_in_Package(uML4CPPProfile, UML4CPPProfile::UML4CPPProfilePackage::EXTERNALLIBRARY_CLASS);
	uML4CPPProfile_ExternalLibrary->setName("ExternalLibrary");
	uML4CPPProfile_ExternalLibrary->setIsAbstract(false);
	uML4CPPProfile_ExternalLibrary_base_Package = factory->createProperty_in_Class(uML4CPPProfile_ExternalLibrary);uML4CPPProfile_ExternalLibrary_includePath = factory->createProperty_in_Class(uML4CPPProfile_ExternalLibrary);uML4CPPProfile_ExternalLibrary_libraryName = factory->createProperty_in_Class(uML4CPPProfile_ExternalLibrary);uML4CPPProfile_ExternalLibrary_libraryPath = factory->createProperty_in_Class(uML4CPPProfile_ExternalLibrary);
	

	uML4CPPProfile_MainBehavior = factory->createStereotype_in_Package(uML4CPPProfile, UML4CPPProfile::UML4CPPProfilePackage::MAINBEHAVIOR_CLASS);
	uML4CPPProfile_MainBehavior->setName("MainBehavior");
	uML4CPPProfile_MainBehavior->setIsAbstract(false);
	uML4CPPProfile_MainBehavior_base_Behavior = factory->createProperty_in_Class(uML4CPPProfile_MainBehavior);
	

	uML4CPPProfile_NonExecutable = factory->createStereotype_in_Package(uML4CPPProfile, UML4CPPProfile::UML4CPPProfilePackage::NONEXECUTABLE_CLASS);
	uML4CPPProfile_NonExecutable->setName("NonExecutable");
	uML4CPPProfile_NonExecutable->setIsAbstract(false);
	uML4CPPProfile_NonExecutable_base_NamedElement = factory->createProperty_in_Class(uML4CPPProfile_NonExecutable);
	

	uML4CPPProfile_Singleton = factory->createStereotype_in_Package(uML4CPPProfile, UML4CPPProfile::UML4CPPProfilePackage::SINGLETON_CLASS);
	uML4CPPProfile_Singleton->setName("Singleton");
	uML4CPPProfile_Singleton->setIsAbstract(false);
	uML4CPPProfile_Singleton_base_Class = factory->createProperty_in_Class(uML4CPPProfile_Singleton);
	

	uML4CPPProfile_UML4CPPPackage = factory->createStereotype_in_Package(uML4CPPProfile, UML4CPPProfile::UML4CPPProfilePackage::UML4CPPPACKAGE_CLASS);
	uML4CPPProfile_UML4CPPPackage->setName("UML4CPPPackage");
	uML4CPPProfile_UML4CPPPackage->setIsAbstract(false);
	uML4CPPProfile_UML4CPPPackage_base_Package = factory->createProperty_in_Class(uML4CPPProfile_UML4CPPPackage);uML4CPPProfile_UML4CPPPackage_eclipseURI = factory->createProperty_in_Class(uML4CPPProfile_UML4CPPPackage);uML4CPPProfile_UML4CPPPackage_ignoreNamespace = factory->createProperty_in_Class(uML4CPPProfile_UML4CPPPackage);uML4CPPProfile_UML4CPPPackage_packageOnly = factory->createProperty_in_Class(uML4CPPProfile_UML4CPPPackage);
	
}

void UML4CPPProfilePackageImpl::createPackageValueSpecifications(std::shared_ptr<uml::Package> uML4CPPProfile, std::shared_ptr<uml::umlFactory> factory)
{
	uML4CPPProfile_UML4CPPPackage_ignoreNamespace_defaultValue_LiteralBoolean_UML4CPPProfile_UML4CPPPackage_ignoreNamespace = factory->createLiteralBoolean_in_Owner(uML4CPPProfile_UML4CPPPackage_ignoreNamespace);
	
	uML4CPPProfile_UML4CPPPackage_packageOnly_defaultValue_LiteralBoolean_UML4CPPProfile_UML4CPPPackage_packageOnly = factory->createLiteralBoolean_in_Owner(uML4CPPProfile_UML4CPPPackage_packageOnly);
	
}

void UML4CPPProfilePackageImpl::initializePackageContents(std::shared_ptr<uml::Package> uML4CPPProfile)
{
	if (isInitialized)
	{
		return;
	}
	isInitialized = true;

	// Initialize package
	setName(eNAME);
	setURI(eNS_URI);

	initializePackageActivities();
	initializePackageClasses();
	initializePackageAssociations();
	initializePackageDependencies();
	initializePackageInstanceSpecifications();
	initializePackageInterfaceRealizations();
	initializePackageInterfaces();
	initializePackageNestedPackages();
	initializePackageStereotypes();
	initializePackageValueSpecifications();
	
}

//ActivityNodes and Edges
void UML4CPPProfilePackageImpl::initializePackageActivities()
{
}


void UML4CPPProfilePackageImpl::initializePackageClasses()
{
	std::shared_ptr<uml::Generalization> gen = nullptr;


//-------------------------------------------
//Opaque Behaviors

}

void UML4CPPProfilePackageImpl::initializePackageAssociations()
{
}

void UML4CPPProfilePackageImpl::initializePackageDependencies()
{
}

void UML4CPPProfilePackageImpl::initializePackageInstanceSpecifications()
{
}


void UML4CPPProfilePackageImpl::initializePackageInterfaceRealizations()
{
}

void UML4CPPProfilePackageImpl::initializePackageInterfaces()
{
}

void UML4CPPProfilePackageImpl::initializePackageNestedPackages()
{
}

void UML4CPPProfilePackageImpl::initializePackageStereotypes()
{
	uML4CPPProfile_DoNotGenerate_base_Element->setName("base_Element");
	uML4CPPProfile_DoNotGenerate_base_Element->setType(UML::UMLPackage::eInstance()->get_UML_Element());
	uML4CPPProfile_DoNotGenerate_base_Element->setLower(1);
	uML4CPPProfile_DoNotGenerate_base_Element->setUpper(1);
	uML4CPPProfile_DoNotGenerate_base_Element->setIsUnique(true);
	uML4CPPProfile_DoNotGenerate_base_Element->setAggregation(uml::AggregationKind::NONE);
	uML4CPPProfile_DoNotGenerate_base_Element->setVisibility(uml::VisibilityKind::PUBLIC);
	uML4CPPProfile_DoNotGenerate_base_Element->setAssociation(get_UML4CPPProfile_Element_DoNotGenerate());
	
	
	

	uML4CPPProfile_ExternalLibrary_base_Package->setName("base_Package");
	uML4CPPProfile_ExternalLibrary_base_Package->setType(UML::UMLPackage::eInstance()->get_UML_Package());
	uML4CPPProfile_ExternalLibrary_base_Package->setLower(1);
	uML4CPPProfile_ExternalLibrary_base_Package->setUpper(1);
	uML4CPPProfile_ExternalLibrary_base_Package->setIsUnique(true);
	uML4CPPProfile_ExternalLibrary_base_Package->setAggregation(uml::AggregationKind::NONE);
	uML4CPPProfile_ExternalLibrary_base_Package->setVisibility(uml::VisibilityKind::PUBLIC);
	uML4CPPProfile_ExternalLibrary_base_Package->setAssociation(get_UML4CPPProfile_Package_ExternalLibrary());
	
	uML4CPPProfile_ExternalLibrary_includePath->setName("includePath");
	uML4CPPProfile_ExternalLibrary_includePath->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String());
	uML4CPPProfile_ExternalLibrary_includePath->setLower(1);
	uML4CPPProfile_ExternalLibrary_includePath->setUpper(1);
	uML4CPPProfile_ExternalLibrary_includePath->setIsUnique(true);
	uML4CPPProfile_ExternalLibrary_includePath->setAggregation(uml::AggregationKind::NONE);
	uML4CPPProfile_ExternalLibrary_includePath->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	uML4CPPProfile_ExternalLibrary_libraryName->setName("libraryName");
	uML4CPPProfile_ExternalLibrary_libraryName->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String());
	uML4CPPProfile_ExternalLibrary_libraryName->setLower(1);
	uML4CPPProfile_ExternalLibrary_libraryName->setUpper(1);
	uML4CPPProfile_ExternalLibrary_libraryName->setIsUnique(true);
	uML4CPPProfile_ExternalLibrary_libraryName->setAggregation(uml::AggregationKind::NONE);
	uML4CPPProfile_ExternalLibrary_libraryName->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	uML4CPPProfile_ExternalLibrary_libraryPath->setName("libraryPath");
	uML4CPPProfile_ExternalLibrary_libraryPath->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String());
	uML4CPPProfile_ExternalLibrary_libraryPath->setLower(1);
	uML4CPPProfile_ExternalLibrary_libraryPath->setUpper(1);
	uML4CPPProfile_ExternalLibrary_libraryPath->setIsUnique(true);
	uML4CPPProfile_ExternalLibrary_libraryPath->setAggregation(uml::AggregationKind::NONE);
	uML4CPPProfile_ExternalLibrary_libraryPath->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	
	

	uML4CPPProfile_MainBehavior_base_Behavior->setName("base_Behavior");
	uML4CPPProfile_MainBehavior_base_Behavior->setType(UML::UMLPackage::eInstance()->get_UML_Behavior());
	uML4CPPProfile_MainBehavior_base_Behavior->setLower(1);
	uML4CPPProfile_MainBehavior_base_Behavior->setUpper(1);
	uML4CPPProfile_MainBehavior_base_Behavior->setIsUnique(true);
	uML4CPPProfile_MainBehavior_base_Behavior->setAggregation(uml::AggregationKind::NONE);
	uML4CPPProfile_MainBehavior_base_Behavior->setVisibility(uml::VisibilityKind::PUBLIC);
	uML4CPPProfile_MainBehavior_base_Behavior->setAssociation(get_UML4CPPProfile_Behavior_MainBehavior());
	
	
	

	uML4CPPProfile_NonExecutable_base_NamedElement->setName("base_NamedElement");
	uML4CPPProfile_NonExecutable_base_NamedElement->setType(UML::UMLPackage::eInstance()->get_UML_NamedElement());
	uML4CPPProfile_NonExecutable_base_NamedElement->setLower(1);
	uML4CPPProfile_NonExecutable_base_NamedElement->setUpper(1);
	uML4CPPProfile_NonExecutable_base_NamedElement->setIsUnique(true);
	uML4CPPProfile_NonExecutable_base_NamedElement->setAggregation(uml::AggregationKind::NONE);
	uML4CPPProfile_NonExecutable_base_NamedElement->setVisibility(uml::VisibilityKind::PUBLIC);
	uML4CPPProfile_NonExecutable_base_NamedElement->setAssociation(get_UML4CPPProfile_NamedElement_NonExecutable());
	
	
	

	uML4CPPProfile_Singleton_base_Class->setName("base_Class");
	uML4CPPProfile_Singleton_base_Class->setType(UML::UMLPackage::eInstance()->get_UML_Class());
	uML4CPPProfile_Singleton_base_Class->setLower(1);
	uML4CPPProfile_Singleton_base_Class->setUpper(1);
	uML4CPPProfile_Singleton_base_Class->setIsUnique(true);
	uML4CPPProfile_Singleton_base_Class->setAggregation(uml::AggregationKind::NONE);
	uML4CPPProfile_Singleton_base_Class->setVisibility(uml::VisibilityKind::PUBLIC);
	uML4CPPProfile_Singleton_base_Class->setAssociation(get_UML4CPPProfile_Class_Singleton());
	
	
	

	uML4CPPProfile_UML4CPPPackage_base_Package->setName("base_Package");
	uML4CPPProfile_UML4CPPPackage_base_Package->setType(UML::UMLPackage::eInstance()->get_UML_Package());
	uML4CPPProfile_UML4CPPPackage_base_Package->setLower(1);
	uML4CPPProfile_UML4CPPPackage_base_Package->setUpper(1);
	uML4CPPProfile_UML4CPPPackage_base_Package->setIsUnique(true);
	uML4CPPProfile_UML4CPPPackage_base_Package->setAggregation(uml::AggregationKind::NONE);
	uML4CPPProfile_UML4CPPPackage_base_Package->setVisibility(uml::VisibilityKind::PUBLIC);
	uML4CPPProfile_UML4CPPPackage_base_Package->setAssociation(get_UML4CPPProfile_Package_UML4CPPPackage());
	
	uML4CPPProfile_UML4CPPPackage_eclipseURI->setName("eclipseURI");
	uML4CPPProfile_UML4CPPPackage_eclipseURI->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String());
	uML4CPPProfile_UML4CPPPackage_eclipseURI->setLower(1);
	uML4CPPProfile_UML4CPPPackage_eclipseURI->setUpper(1);
	uML4CPPProfile_UML4CPPPackage_eclipseURI->setIsUnique(true);
	uML4CPPProfile_UML4CPPPackage_eclipseURI->setAggregation(uml::AggregationKind::NONE);
	uML4CPPProfile_UML4CPPPackage_eclipseURI->setVisibility(uml::VisibilityKind::PUBLIC);
	
	
	uML4CPPProfile_UML4CPPPackage_ignoreNamespace->setName("ignoreNamespace");
	uML4CPPProfile_UML4CPPPackage_ignoreNamespace->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	uML4CPPProfile_UML4CPPPackage_ignoreNamespace->setLower(1);
	uML4CPPProfile_UML4CPPPackage_ignoreNamespace->setUpper(1);
	uML4CPPProfile_UML4CPPPackage_ignoreNamespace->setIsUnique(true);
	uML4CPPProfile_UML4CPPPackage_ignoreNamespace->setAggregation(uml::AggregationKind::NONE);
	uML4CPPProfile_UML4CPPPackage_ignoreNamespace->setVisibility(uml::VisibilityKind::PUBLIC);
	
	uML4CPPProfile_UML4CPPPackage_ignoreNamespace->setDefaultValue(uML4CPPProfile_UML4CPPPackage_ignoreNamespace_defaultValue_LiteralBoolean_UML4CPPProfile_UML4CPPPackage_ignoreNamespace);
	uML4CPPProfile_UML4CPPPackage_packageOnly->setName("packageOnly");
	uML4CPPProfile_UML4CPPPackage_packageOnly->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
	uML4CPPProfile_UML4CPPPackage_packageOnly->setLower(1);
	uML4CPPProfile_UML4CPPPackage_packageOnly->setUpper(1);
	uML4CPPProfile_UML4CPPPackage_packageOnly->setIsUnique(true);
	uML4CPPProfile_UML4CPPPackage_packageOnly->setAggregation(uml::AggregationKind::NONE);
	uML4CPPProfile_UML4CPPPackage_packageOnly->setVisibility(uml::VisibilityKind::PUBLIC);
	
	uML4CPPProfile_UML4CPPPackage_packageOnly->setDefaultValue(uML4CPPProfile_UML4CPPPackage_packageOnly_defaultValue_LiteralBoolean_UML4CPPProfile_UML4CPPPackage_packageOnly);
	
	
}

void UML4CPPProfilePackageImpl::initializePackageValueSpecifications()
{
	uML4CPPProfile_UML4CPPPackage_ignoreNamespace_defaultValue_LiteralBoolean_UML4CPPProfile_UML4CPPPackage_ignoreNamespace->setValue(false);

	uML4CPPProfile_UML4CPPPackage_packageOnly_defaultValue_LiteralBoolean_UML4CPPProfile_UML4CPPPackage_packageOnly->setValue(false);
}

std::shared_ptr<uml::ExtensionEnd> UML4CPPProfilePackageImpl::get_ExtensionEnd_extension_DoNotGenerate_UML4CPPProfile_DoNotGenerate()
{
	return extensionEnd_extension_DoNotGenerate_UML4CPPProfile_DoNotGenerate;
}
std::shared_ptr<uml::ExtensionEnd> UML4CPPProfilePackageImpl::get_ExtensionEnd_extension_ExternalLibrary_UML4CPPProfile_ExternalLibrary()
{
	return extensionEnd_extension_ExternalLibrary_UML4CPPProfile_ExternalLibrary;
}
std::shared_ptr<uml::ExtensionEnd> UML4CPPProfilePackageImpl::get_ExtensionEnd_extension_MainBehavior_UML4CPPProfile_MainBehavior()
{
	return extensionEnd_extension_MainBehavior_UML4CPPProfile_MainBehavior;
}
std::shared_ptr<uml::ExtensionEnd> UML4CPPProfilePackageImpl::get_ExtensionEnd_extension_NonExecutable_UML4CPPProfile_NonExecutable()
{
	return extensionEnd_extension_NonExecutable_UML4CPPProfile_NonExecutable;
}
std::shared_ptr<uml::ExtensionEnd> UML4CPPProfilePackageImpl::get_ExtensionEnd_extension_Singleton_UML4CPPProfile_Singleton()
{
	return extensionEnd_extension_Singleton_UML4CPPProfile_Singleton;
}
std::shared_ptr<uml::ExtensionEnd> UML4CPPProfilePackageImpl::get_ExtensionEnd_extension_UML4CPPPackage_UML4CPPProfile_UML4CPPPackage()
{
	return extensionEnd_extension_UML4CPPPackage_UML4CPPProfile_UML4CPPPackage;
}
std::shared_ptr<uml::Extension> UML4CPPProfilePackageImpl::get_UML4CPPProfile_Behavior_MainBehavior()
{
	return uML4CPPProfile_Behavior_MainBehavior;
}
std::shared_ptr<uml::Extension> UML4CPPProfilePackageImpl::get_UML4CPPProfile_Class_Singleton()
{
	return uML4CPPProfile_Class_Singleton;
}
std::shared_ptr<uml::Stereotype> UML4CPPProfilePackageImpl::get_UML4CPPProfile_DoNotGenerate()
{
	return uML4CPPProfile_DoNotGenerate;
}
std::shared_ptr<uml::Property> UML4CPPProfilePackageImpl::get_UML4CPPProfile_DoNotGenerate_base_Element()
{
	return uML4CPPProfile_DoNotGenerate_base_Element;
}
std::shared_ptr<uml::Extension> UML4CPPProfilePackageImpl::get_UML4CPPProfile_Element_DoNotGenerate()
{
	return uML4CPPProfile_Element_DoNotGenerate;
}
std::shared_ptr<uml::Stereotype> UML4CPPProfilePackageImpl::get_UML4CPPProfile_ExternalLibrary()
{
	return uML4CPPProfile_ExternalLibrary;
}
std::shared_ptr<uml::Property> UML4CPPProfilePackageImpl::get_UML4CPPProfile_ExternalLibrary_base_Package()
{
	return uML4CPPProfile_ExternalLibrary_base_Package;
}
std::shared_ptr<uml::Property> UML4CPPProfilePackageImpl::get_UML4CPPProfile_ExternalLibrary_includePath()
{
	return uML4CPPProfile_ExternalLibrary_includePath;
}
std::shared_ptr<uml::Property> UML4CPPProfilePackageImpl::get_UML4CPPProfile_ExternalLibrary_libraryName()
{
	return uML4CPPProfile_ExternalLibrary_libraryName;
}
std::shared_ptr<uml::Property> UML4CPPProfilePackageImpl::get_UML4CPPProfile_ExternalLibrary_libraryPath()
{
	return uML4CPPProfile_ExternalLibrary_libraryPath;
}
std::shared_ptr<uml::Stereotype> UML4CPPProfilePackageImpl::get_UML4CPPProfile_MainBehavior()
{
	return uML4CPPProfile_MainBehavior;
}
std::shared_ptr<uml::Property> UML4CPPProfilePackageImpl::get_UML4CPPProfile_MainBehavior_base_Behavior()
{
	return uML4CPPProfile_MainBehavior_base_Behavior;
}
std::shared_ptr<uml::Extension> UML4CPPProfilePackageImpl::get_UML4CPPProfile_NamedElement_NonExecutable()
{
	return uML4CPPProfile_NamedElement_NonExecutable;
}
std::shared_ptr<uml::Stereotype> UML4CPPProfilePackageImpl::get_UML4CPPProfile_NonExecutable()
{
	return uML4CPPProfile_NonExecutable;
}
std::shared_ptr<uml::Property> UML4CPPProfilePackageImpl::get_UML4CPPProfile_NonExecutable_base_NamedElement()
{
	return uML4CPPProfile_NonExecutable_base_NamedElement;
}
std::shared_ptr<uml::Extension> UML4CPPProfilePackageImpl::get_UML4CPPProfile_Package_ExternalLibrary()
{
	return uML4CPPProfile_Package_ExternalLibrary;
}
std::shared_ptr<uml::Extension> UML4CPPProfilePackageImpl::get_UML4CPPProfile_Package_UML4CPPPackage()
{
	return uML4CPPProfile_Package_UML4CPPPackage;
}
std::shared_ptr<uml::Stereotype> UML4CPPProfilePackageImpl::get_UML4CPPProfile_Singleton()
{
	return uML4CPPProfile_Singleton;
}
std::shared_ptr<uml::Property> UML4CPPProfilePackageImpl::get_UML4CPPProfile_Singleton_base_Class()
{
	return uML4CPPProfile_Singleton_base_Class;
}
std::shared_ptr<uml::Stereotype> UML4CPPProfilePackageImpl::get_UML4CPPProfile_UML4CPPPackage()
{
	return uML4CPPProfile_UML4CPPPackage;
}
std::shared_ptr<uml::Property> UML4CPPProfilePackageImpl::get_UML4CPPProfile_UML4CPPPackage_base_Package()
{
	return uML4CPPProfile_UML4CPPPackage_base_Package;
}
std::shared_ptr<uml::Property> UML4CPPProfilePackageImpl::get_UML4CPPProfile_UML4CPPPackage_eclipseURI()
{
	return uML4CPPProfile_UML4CPPPackage_eclipseURI;
}
std::shared_ptr<uml::Property> UML4CPPProfilePackageImpl::get_UML4CPPProfile_UML4CPPPackage_ignoreNamespace()
{
	return uML4CPPProfile_UML4CPPPackage_ignoreNamespace;
}
std::shared_ptr<uml::Property> UML4CPPProfilePackageImpl::get_UML4CPPProfile_UML4CPPPackage_packageOnly()
{
	return uML4CPPProfile_UML4CPPPackage_packageOnly;
}




