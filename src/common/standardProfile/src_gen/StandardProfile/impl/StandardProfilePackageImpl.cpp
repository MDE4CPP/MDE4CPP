#include "StandardProfile/impl/StandardProfilePackageImpl.hpp"

//meta meta model classes
#include "uml/Class.hpp"
#include "uml/Extension.hpp"
#include "uml/ExtensionEnd.hpp"
#include "uml/Generalization.hpp"
#include "uml/LiteralInteger.hpp"
#include "uml/PackageImport.hpp"
#include "uml/Property.hpp"
#include "uml/Stereotype.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "uml/VisibilityKind.hpp"
//meta meta model factory
#include "uml/umlFactory.hpp"

//metamodel factory
#include "StandardProfile/StandardProfileFactory.hpp"

//depending model packages
#include "ecoreReflection/EcorePackage.hpp"
#include "umlReflection/UMLPackage.hpp"




using namespace StandardProfile;

StandardProfilePackageImpl::StandardProfilePackageImpl()
{
}

StandardProfilePackageImpl::~StandardProfilePackageImpl()
{
}

bool StandardProfilePackageImpl::isInited = false;

StandardProfilePackage* StandardProfilePackageImpl::create()
{
	if (isInited)
	{
		return StandardProfilePackage::eInstance().get();
	}
	isInited = true;
	
    // Obtain or create and register package, create package meta-data objects
    StandardProfilePackageImpl * metaModelPackage = new StandardProfilePackageImpl();
    return metaModelPackage;
}

void StandardProfilePackageImpl::init(std::shared_ptr<uml::Package> standardProfile)
{
    // Initialize created meta-data
	setThisPackagePtr(standardProfile);
	initMetaModel();
    createPackageContents(standardProfile);
    initializePackageContents(standardProfile);   
}

void StandardProfilePackageImpl::initMetaModel()
{
}

void StandardProfilePackageImpl::createPackageContents(std::shared_ptr<uml::Package> standardProfile)
{
	if (isCreated)
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<uml::umlFactory> factory = uml::umlFactory::eInstance();

	createPackageValueSpecifications(standardProfile, factory);
	createPackageInterfaces(standardProfile, factory);
	createPackageClasses(standardProfile, factory);
	createPackageAssociations(standardProfile, factory);
	createPackageInstanceSpecifications(standardProfile, factory);
	createPackageStereotypes(standardProfile, factory);
	createPackageActivities(standardProfile, factory);
	createPackageDependencies(standardProfile, factory);
	createPackagePrimitiveTypes(standardProfile, factory);
	createPackageEnumerationLiterals(standardProfile, factory);
	createPackageInterfaceRealizations(standardProfile, factory);
}

void StandardProfilePackageImpl::createPackageActivities(std::shared_ptr<uml::Package> standardProfile, std::shared_ptr<uml::umlFactory> factory)
{
}


void StandardProfilePackageImpl::createPackageClasses(std::shared_ptr<uml::Package> standardProfile, std::shared_ptr<uml::umlFactory> factory)
{
	std::shared_ptr<uml::Constraint> con = nullptr;
	std::shared_ptr<uml::OpaqueExpression> oe = nullptr;


//-------------------------------------------
//Opaque Behaviors

} 

void StandardProfilePackageImpl::createPackageAssociations(std::shared_ptr<uml::Package> standardProfile, std::shared_ptr<uml::umlFactory> factory)
{
}

void StandardProfilePackageImpl::createPackageDependencies(std::shared_ptr<uml::Package> standardProfile, std::shared_ptr<uml::umlFactory> factory)
{
}

void StandardProfilePackageImpl::createPackageEnumerationLiterals(std::shared_ptr<uml::Package> standardProfile, std::shared_ptr<uml::umlFactory> factory)
{
}

void StandardProfilePackageImpl::createPackageInstanceSpecifications(std::shared_ptr<uml::Package> standardProfile, std::shared_ptr<uml::umlFactory> factory)
{
}

void StandardProfilePackageImpl::createPackageInterfaceRealizations(std::shared_ptr<uml::Package> standardProfile, std::shared_ptr<uml::umlFactory> factory)
{
}

void StandardProfilePackageImpl::createPackageInterfaces(std::shared_ptr<uml::Package> standardProfile, std::shared_ptr<uml::umlFactory> factory)
{
}

void StandardProfilePackageImpl::createPackagePrimitiveTypes(std::shared_ptr<uml::Package> standardProfile, std::shared_ptr<uml::umlFactory> factory)
{
}

void StandardProfilePackageImpl::createPackageStereotypes(std::shared_ptr<uml::Package> standardProfile, std::shared_ptr<uml::umlFactory> factory)
{
	standardProfile_Auxiliary = factory->createStereotype_as_ownedType_in_Package(standardProfile, StandardProfile::StandardProfilePackage::AUXILIARY_STEREOTYPE);
	standardProfile_Auxiliary->setName("Auxiliary");
	standardProfile_Auxiliary->setIsAbstract(false);
	standardProfile_Auxiliary_base_Class = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Auxiliary);
	

	standardProfile_BuildComponent = factory->createStereotype_as_ownedType_in_Package(standardProfile, StandardProfile::StandardProfilePackage::BUILDCOMPONENT_STEREOTYPE);
	standardProfile_BuildComponent->setName("BuildComponent");
	standardProfile_BuildComponent->setIsAbstract(false);
	standardProfile_BuildComponent_base_Component = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_BuildComponent);
	

	standardProfile_Call = factory->createStereotype_as_ownedType_in_Package(standardProfile, StandardProfile::StandardProfilePackage::CALL_STEREOTYPE);
	standardProfile_Call->setName("Call");
	standardProfile_Call->setIsAbstract(false);
	standardProfile_Call_base_Usage = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Call);
	

	standardProfile_Create = factory->createStereotype_as_ownedType_in_Package(standardProfile, StandardProfile::StandardProfilePackage::CREATE_STEREOTYPE);
	standardProfile_Create->setName("Create");
	standardProfile_Create->setIsAbstract(false);
	standardProfile_Create_base_BehavioralFeature = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Create);standardProfile_Create_base_Usage = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Create);
	

	standardProfile_Derive = factory->createStereotype_as_ownedType_in_Package(standardProfile, StandardProfile::StandardProfilePackage::DERIVE_STEREOTYPE);
	standardProfile_Derive->setName("Derive");
	standardProfile_Derive->setIsAbstract(false);
	standardProfile_Derive_base_Abstraction = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Derive);
	

	standardProfile_Destroy = factory->createStereotype_as_ownedType_in_Package(standardProfile, StandardProfile::StandardProfilePackage::DESTROY_STEREOTYPE);
	standardProfile_Destroy->setName("Destroy");
	standardProfile_Destroy->setIsAbstract(false);
	standardProfile_Destroy_base_BehavioralFeature = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Destroy);
	

	standardProfile_Document = factory->createStereotype_as_ownedType_in_Package(standardProfile, StandardProfile::StandardProfilePackage::DOCUMENT_STEREOTYPE);
	standardProfile_Document->setName("Document");
	standardProfile_Document->setIsAbstract(false);
	standardProfile_Document_base_Artifact = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Document);
	

	standardProfile_Entity = factory->createStereotype_as_ownedType_in_Package(standardProfile, StandardProfile::StandardProfilePackage::ENTITY_STEREOTYPE);
	standardProfile_Entity->setName("Entity");
	standardProfile_Entity->setIsAbstract(false);
	standardProfile_Entity_base_Component = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Entity);
	

	standardProfile_Executable = factory->createStereotype_as_ownedType_in_Package(standardProfile, StandardProfile::StandardProfilePackage::EXECUTABLE_STEREOTYPE);
	standardProfile_Executable->setName("Executable");
	standardProfile_Executable->setIsAbstract(false);
	standardProfile_Executable_base_Artifact = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Executable);
	

	standardProfile_File = factory->createStereotype_as_ownedType_in_Package(standardProfile, StandardProfile::StandardProfilePackage::FILE_STEREOTYPE);
	standardProfile_File->setName("File");
	standardProfile_File->setIsAbstract(false);
	standardProfile_File_base_Artifact = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_File);
	

	standardProfile_Focus = factory->createStereotype_as_ownedType_in_Package(standardProfile, StandardProfile::StandardProfilePackage::FOCUS_STEREOTYPE);
	standardProfile_Focus->setName("Focus");
	standardProfile_Focus->setIsAbstract(false);
	standardProfile_Focus_base_Class = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Focus);
	

	standardProfile_Framework = factory->createStereotype_as_ownedType_in_Package(standardProfile, StandardProfile::StandardProfilePackage::FRAMEWORK_STEREOTYPE);
	standardProfile_Framework->setName("Framework");
	standardProfile_Framework->setIsAbstract(false);
	standardProfile_Framework_base_Package = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Framework);
	

	standardProfile_Implement = factory->createStereotype_as_ownedType_in_Package(standardProfile, StandardProfile::StandardProfilePackage::IMPLEMENT_STEREOTYPE);
	standardProfile_Implement->setName("Implement");
	standardProfile_Implement->setIsAbstract(false);
	standardProfile_Implement_base_Component = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Implement);
	

	standardProfile_ImplementationClass = factory->createStereotype_as_ownedType_in_Package(standardProfile, StandardProfile::StandardProfilePackage::IMPLEMENTATIONCLASS_STEREOTYPE);
	standardProfile_ImplementationClass->setName("ImplementationClass");
	standardProfile_ImplementationClass->setIsAbstract(false);
	standardProfile_ImplementationClass_base_Class = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_ImplementationClass);
	

	standardProfile_Instantiate = factory->createStereotype_as_ownedType_in_Package(standardProfile, StandardProfile::StandardProfilePackage::INSTANTIATE_STEREOTYPE);
	standardProfile_Instantiate->setName("Instantiate");
	standardProfile_Instantiate->setIsAbstract(false);
	standardProfile_Instantiate_base_Usage = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Instantiate);
	

	standardProfile_Library = factory->createStereotype_as_ownedType_in_Package(standardProfile, StandardProfile::StandardProfilePackage::LIBRARY_STEREOTYPE);
	standardProfile_Library->setName("Library");
	standardProfile_Library->setIsAbstract(false);
	standardProfile_Library_base_Artifact = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Library);
	

	standardProfile_Metaclass = factory->createStereotype_as_ownedType_in_Package(standardProfile, StandardProfile::StandardProfilePackage::METACLASS_STEREOTYPE);
	standardProfile_Metaclass->setName("Metaclass");
	standardProfile_Metaclass->setIsAbstract(false);
	standardProfile_Metaclass_base_Class = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Metaclass);
	

	standardProfile_Metamodel = factory->createStereotype_as_ownedType_in_Package(standardProfile, StandardProfile::StandardProfilePackage::METAMODEL_STEREOTYPE);
	standardProfile_Metamodel->setName("Metamodel");
	standardProfile_Metamodel->setIsAbstract(false);
	standardProfile_Metamodel_base_Model = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Metamodel);
	

	standardProfile_ModelLibrary = factory->createStereotype_as_ownedType_in_Package(standardProfile, StandardProfile::StandardProfilePackage::MODELLIBRARY_STEREOTYPE);
	standardProfile_ModelLibrary->setName("ModelLibrary");
	standardProfile_ModelLibrary->setIsAbstract(false);
	standardProfile_ModelLibrary_base_Package = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_ModelLibrary);
	

	standardProfile_Process = factory->createStereotype_as_ownedType_in_Package(standardProfile, StandardProfile::StandardProfilePackage::PROCESS_STEREOTYPE);
	standardProfile_Process->setName("Process");
	standardProfile_Process->setIsAbstract(false);
	standardProfile_Process_base_Component = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Process);
	

	standardProfile_Realization = factory->createStereotype_as_ownedType_in_Package(standardProfile, StandardProfile::StandardProfilePackage::REALIZATION_STEREOTYPE);
	standardProfile_Realization->setName("Realization");
	standardProfile_Realization->setIsAbstract(false);
	standardProfile_Realization_base_Classifier = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Realization);
	

	standardProfile_Refine = factory->createStereotype_as_ownedType_in_Package(standardProfile, StandardProfile::StandardProfilePackage::REFINE_STEREOTYPE);
	standardProfile_Refine->setName("Refine");
	standardProfile_Refine->setIsAbstract(false);
	standardProfile_Refine_base_Abstraction = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Refine);
	

	standardProfile_Responsibility = factory->createStereotype_as_ownedType_in_Package(standardProfile, StandardProfile::StandardProfilePackage::RESPONSIBILITY_STEREOTYPE);
	standardProfile_Responsibility->setName("Responsibility");
	standardProfile_Responsibility->setIsAbstract(false);
	standardProfile_Responsibility_base_Usage = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Responsibility);
	

	standardProfile_Script = factory->createStereotype_as_ownedType_in_Package(standardProfile, StandardProfile::StandardProfilePackage::SCRIPT_STEREOTYPE);
	standardProfile_Script->setName("Script");
	standardProfile_Script->setIsAbstract(false);
	standardProfile_Script_base_Artifact = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Script);
	

	standardProfile_Send = factory->createStereotype_as_ownedType_in_Package(standardProfile, StandardProfile::StandardProfilePackage::SEND_STEREOTYPE);
	standardProfile_Send->setName("Send");
	standardProfile_Send->setIsAbstract(false);
	standardProfile_Send_base_Usage = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Send);
	

	standardProfile_Service = factory->createStereotype_as_ownedType_in_Package(standardProfile, StandardProfile::StandardProfilePackage::SERVICE_STEREOTYPE);
	standardProfile_Service->setName("Service");
	standardProfile_Service->setIsAbstract(false);
	standardProfile_Service_base_Component = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Service);
	

	standardProfile_Source = factory->createStereotype_as_ownedType_in_Package(standardProfile, StandardProfile::StandardProfilePackage::SOURCE_STEREOTYPE);
	standardProfile_Source->setName("Source");
	standardProfile_Source->setIsAbstract(false);
	standardProfile_Source_base_Artifact = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Source);
	

	standardProfile_Specification = factory->createStereotype_as_ownedType_in_Package(standardProfile, StandardProfile::StandardProfilePackage::SPECIFICATION_STEREOTYPE);
	standardProfile_Specification->setName("Specification");
	standardProfile_Specification->setIsAbstract(false);
	standardProfile_Specification_base_Classifier = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Specification);
	

	standardProfile_Subsystem = factory->createStereotype_as_ownedType_in_Package(standardProfile, StandardProfile::StandardProfilePackage::SUBSYSTEM_STEREOTYPE);
	standardProfile_Subsystem->setName("Subsystem");
	standardProfile_Subsystem->setIsAbstract(false);
	standardProfile_Subsystem_base_Component = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Subsystem);
	

	standardProfile_SystemModel = factory->createStereotype_as_ownedType_in_Package(standardProfile, StandardProfile::StandardProfilePackage::SYSTEMMODEL_STEREOTYPE);
	standardProfile_SystemModel->setName("SystemModel");
	standardProfile_SystemModel->setIsAbstract(false);
	standardProfile_SystemModel_base_Model = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_SystemModel);
	

	standardProfile_Trace = factory->createStereotype_as_ownedType_in_Package(standardProfile, StandardProfile::StandardProfilePackage::TRACE_STEREOTYPE);
	standardProfile_Trace->setName("Trace");
	standardProfile_Trace->setIsAbstract(false);
	standardProfile_Trace_base_Abstraction = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Trace);
	

	standardProfile_Type = factory->createStereotype_as_ownedType_in_Package(standardProfile, StandardProfile::StandardProfilePackage::TYPE_STEREOTYPE);
	standardProfile_Type->setName("Type");
	standardProfile_Type->setIsAbstract(false);
	standardProfile_Type_base_Class = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Type);
	

	standardProfile_Utility = factory->createStereotype_as_ownedType_in_Package(standardProfile, StandardProfile::StandardProfilePackage::UTILITY_STEREOTYPE);
	standardProfile_Utility->setName("Utility");
	standardProfile_Utility->setIsAbstract(false);
	standardProfile_Utility_base_Class = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Utility);
	
}

void StandardProfilePackageImpl::createPackageValueSpecifications(std::shared_ptr<uml::Package> standardProfile, std::shared_ptr<uml::umlFactory> factory)
{
	extensionEnd_extension_Auxiliary_StandardProfile_Auxiliary_lowerValue_LiteralInteger_ExtensionEnd_extension_Auxiliary_StandardProfile_Auxiliary = factory->createLiteralInteger_as_ownedElement_in_Element(extensionEnd_extension_Auxiliary_StandardProfile_Auxiliary);
	
	extensionEnd_extension_BehavioralFeature_Create_StandardProfile_Create_lowerValue_LiteralInteger_ExtensionEnd_extension_BehavioralFeature_Create_StandardProfile_Create = factory->createLiteralInteger_as_ownedElement_in_Element(extensionEnd_extension_BehavioralFeature_Create_StandardProfile_Create);
	
	extensionEnd_extension_BuildComponent_StandardProfile_BuildComponent_lowerValue_LiteralInteger_ExtensionEnd_extension_BuildComponent_StandardProfile_BuildComponent = factory->createLiteralInteger_as_ownedElement_in_Element(extensionEnd_extension_BuildComponent_StandardProfile_BuildComponent);
	
	extensionEnd_extension_Call_StandardProfile_Call_lowerValue_LiteralInteger_ExtensionEnd_extension_Call_StandardProfile_Call = factory->createLiteralInteger_as_ownedElement_in_Element(extensionEnd_extension_Call_StandardProfile_Call);
	
	extensionEnd_extension_Derive_StandardProfile_Derive_lowerValue_LiteralInteger_ExtensionEnd_extension_Derive_StandardProfile_Derive = factory->createLiteralInteger_as_ownedElement_in_Element(extensionEnd_extension_Derive_StandardProfile_Derive);
	
	extensionEnd_extension_Destroy_StandardProfile_Destroy_lowerValue_LiteralInteger_ExtensionEnd_extension_Destroy_StandardProfile_Destroy = factory->createLiteralInteger_as_ownedElement_in_Element(extensionEnd_extension_Destroy_StandardProfile_Destroy);
	
	extensionEnd_extension_Document_StandardProfile_Document_lowerValue_LiteralInteger_ExtensionEnd_extension_Document_StandardProfile_Document = factory->createLiteralInteger_as_ownedElement_in_Element(extensionEnd_extension_Document_StandardProfile_Document);
	
	extensionEnd_extension_Entity_StandardProfile_Entity_lowerValue_LiteralInteger_ExtensionEnd_extension_Entity_StandardProfile_Entity = factory->createLiteralInteger_as_ownedElement_in_Element(extensionEnd_extension_Entity_StandardProfile_Entity);
	
	extensionEnd_extension_Executable_StandardProfile_Executable_lowerValue_LiteralInteger_ExtensionEnd_extension_Executable_StandardProfile_Executable = factory->createLiteralInteger_as_ownedElement_in_Element(extensionEnd_extension_Executable_StandardProfile_Executable);
	
	extensionEnd_extension_File_StandardProfile_File_lowerValue_LiteralInteger_ExtensionEnd_extension_File_StandardProfile_File = factory->createLiteralInteger_as_ownedElement_in_Element(extensionEnd_extension_File_StandardProfile_File);
	
	extensionEnd_extension_Focus_StandardProfile_Focus_lowerValue_LiteralInteger_ExtensionEnd_extension_Focus_StandardProfile_Focus = factory->createLiteralInteger_as_ownedElement_in_Element(extensionEnd_extension_Focus_StandardProfile_Focus);
	
	extensionEnd_extension_Framework_StandardProfile_Framework_lowerValue_LiteralInteger_ExtensionEnd_extension_Framework_StandardProfile_Framework = factory->createLiteralInteger_as_ownedElement_in_Element(extensionEnd_extension_Framework_StandardProfile_Framework);
	
	extensionEnd_extension_Implement_StandardProfile_Implement_lowerValue_LiteralInteger_ExtensionEnd_extension_Implement_StandardProfile_Implement = factory->createLiteralInteger_as_ownedElement_in_Element(extensionEnd_extension_Implement_StandardProfile_Implement);
	
	extensionEnd_extension_ImplementationClass_StandardProfile_ImplementationClass_lowerValue_LiteralInteger_ExtensionEnd_extension_ImplementationClass_StandardProfile_ImplementationClass = factory->createLiteralInteger_as_ownedElement_in_Element(extensionEnd_extension_ImplementationClass_StandardProfile_ImplementationClass);
	
	extensionEnd_extension_Instantiate_StandardProfile_Instantiate_lowerValue_LiteralInteger_ExtensionEnd_extension_Instantiate_StandardProfile_Instantiate = factory->createLiteralInteger_as_ownedElement_in_Element(extensionEnd_extension_Instantiate_StandardProfile_Instantiate);
	
	extensionEnd_extension_Library_StandardProfile_Library_lowerValue_LiteralInteger_ExtensionEnd_extension_Library_StandardProfile_Library = factory->createLiteralInteger_as_ownedElement_in_Element(extensionEnd_extension_Library_StandardProfile_Library);
	
	extensionEnd_extension_Metaclass_StandardProfile_Metaclass_lowerValue_LiteralInteger_ExtensionEnd_extension_Metaclass_StandardProfile_Metaclass = factory->createLiteralInteger_as_ownedElement_in_Element(extensionEnd_extension_Metaclass_StandardProfile_Metaclass);
	
	extensionEnd_extension_Metamodel_StandardProfile_Metamodel_lowerValue_LiteralInteger_ExtensionEnd_extension_Metamodel_StandardProfile_Metamodel = factory->createLiteralInteger_as_ownedElement_in_Element(extensionEnd_extension_Metamodel_StandardProfile_Metamodel);
	
	extensionEnd_extension_ModelLibrary_StandardProfile_ModelLibrary_lowerValue_LiteralInteger_ExtensionEnd_extension_ModelLibrary_StandardProfile_ModelLibrary = factory->createLiteralInteger_as_ownedElement_in_Element(extensionEnd_extension_ModelLibrary_StandardProfile_ModelLibrary);
	
	extensionEnd_extension_Process_StandardProfile_Process_lowerValue_LiteralInteger_ExtensionEnd_extension_Process_StandardProfile_Process = factory->createLiteralInteger_as_ownedElement_in_Element(extensionEnd_extension_Process_StandardProfile_Process);
	
	extensionEnd_extension_Realization_StandardProfile_Realization_lowerValue_LiteralInteger_ExtensionEnd_extension_Realization_StandardProfile_Realization = factory->createLiteralInteger_as_ownedElement_in_Element(extensionEnd_extension_Realization_StandardProfile_Realization);
	
	extensionEnd_extension_Refine_StandardProfile_Refine_lowerValue_LiteralInteger_ExtensionEnd_extension_Refine_StandardProfile_Refine = factory->createLiteralInteger_as_ownedElement_in_Element(extensionEnd_extension_Refine_StandardProfile_Refine);
	
	extensionEnd_extension_Responsibility_StandardProfile_Responsibility_lowerValue_LiteralInteger_ExtensionEnd_extension_Responsibility_StandardProfile_Responsibility = factory->createLiteralInteger_as_ownedElement_in_Element(extensionEnd_extension_Responsibility_StandardProfile_Responsibility);
	
	extensionEnd_extension_Script_StandardProfile_Script_lowerValue_LiteralInteger_ExtensionEnd_extension_Script_StandardProfile_Script = factory->createLiteralInteger_as_ownedElement_in_Element(extensionEnd_extension_Script_StandardProfile_Script);
	
	extensionEnd_extension_Send_StandardProfile_Send_lowerValue_LiteralInteger_ExtensionEnd_extension_Send_StandardProfile_Send = factory->createLiteralInteger_as_ownedElement_in_Element(extensionEnd_extension_Send_StandardProfile_Send);
	
	extensionEnd_extension_Service_StandardProfile_Service_lowerValue_LiteralInteger_ExtensionEnd_extension_Service_StandardProfile_Service = factory->createLiteralInteger_as_ownedElement_in_Element(extensionEnd_extension_Service_StandardProfile_Service);
	
	extensionEnd_extension_Source_StandardProfile_Source_lowerValue_LiteralInteger_ExtensionEnd_extension_Source_StandardProfile_Source = factory->createLiteralInteger_as_ownedElement_in_Element(extensionEnd_extension_Source_StandardProfile_Source);
	
	extensionEnd_extension_Specification_StandardProfile_Specification_lowerValue_LiteralInteger_ExtensionEnd_extension_Specification_StandardProfile_Specification = factory->createLiteralInteger_as_ownedElement_in_Element(extensionEnd_extension_Specification_StandardProfile_Specification);
	
	extensionEnd_extension_Subsystem_StandardProfile_Subsystem_lowerValue_LiteralInteger_ExtensionEnd_extension_Subsystem_StandardProfile_Subsystem = factory->createLiteralInteger_as_ownedElement_in_Element(extensionEnd_extension_Subsystem_StandardProfile_Subsystem);
	
	extensionEnd_extension_SystemModel_StandardProfile_SystemModel_lowerValue_LiteralInteger_ExtensionEnd_extension_SystemModel_StandardProfile_SystemModel = factory->createLiteralInteger_as_ownedElement_in_Element(extensionEnd_extension_SystemModel_StandardProfile_SystemModel);
	
	extensionEnd_extension_Trace_StandardProfile_Trace_lowerValue_LiteralInteger_ExtensionEnd_extension_Trace_StandardProfile_Trace = factory->createLiteralInteger_as_ownedElement_in_Element(extensionEnd_extension_Trace_StandardProfile_Trace);
	
	extensionEnd_extension_Type_StandardProfile_Type_lowerValue_LiteralInteger_ExtensionEnd_extension_Type_StandardProfile_Type = factory->createLiteralInteger_as_ownedElement_in_Element(extensionEnd_extension_Type_StandardProfile_Type);
	
	extensionEnd_extension_Usage_Create_StandardProfile_Create_lowerValue_LiteralInteger_ExtensionEnd_extension_Usage_Create_StandardProfile_Create = factory->createLiteralInteger_as_ownedElement_in_Element(extensionEnd_extension_Usage_Create_StandardProfile_Create);
	
	extensionEnd_extension_Utility_StandardProfile_Utility_lowerValue_LiteralInteger_ExtensionEnd_extension_Utility_StandardProfile_Utility = factory->createLiteralInteger_as_ownedElement_in_Element(extensionEnd_extension_Utility_StandardProfile_Utility);
	
}

void StandardProfilePackageImpl::initializePackageContents(std::shared_ptr<uml::Package> standardProfile)
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
void StandardProfilePackageImpl::initializePackageActivities()
{
}


void StandardProfilePackageImpl::initializePackageClasses()
{
	std::shared_ptr<uml::Generalization> gen = nullptr;


//-------------------------------------------
//Opaque Behaviors

}

void StandardProfilePackageImpl::initializePackageAssociations()
{
}

void StandardProfilePackageImpl::initializePackageDependencies()
{
}

void StandardProfilePackageImpl::initializePackageInstanceSpecifications()
{
}


void StandardProfilePackageImpl::initializePackageInterfaceRealizations()
{
}

void StandardProfilePackageImpl::initializePackageInterfaces()
{
}

void StandardProfilePackageImpl::initializePackageNestedPackages()
{
}

void StandardProfilePackageImpl::initializePackageStereotypes()
{
	standardProfile_Auxiliary_base_Class->setName("base_Class");
	standardProfile_Auxiliary_base_Class->setType(UML::UMLPackage::eInstance()->get_UML_Class());
	standardProfile_Auxiliary_base_Class->setLower(1);
	standardProfile_Auxiliary_base_Class->setUpper(1);
	standardProfile_Auxiliary_base_Class->setIsUnique(true);
	standardProfile_Auxiliary_base_Class->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Auxiliary_base_Class->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Auxiliary_base_Class->setAssociation(get_StandardProfile_Class_Auxiliary());
	
	standardProfile_Auxiliary_base_Class->_setID(AUXILIARY_ATTRIBUTE_BASE_CLASS);
	
	

	standardProfile_BuildComponent_base_Component->setName("base_Component");
	standardProfile_BuildComponent_base_Component->setType(UML::UMLPackage::eInstance()->get_UML_Component());
	standardProfile_BuildComponent_base_Component->setLower(1);
	standardProfile_BuildComponent_base_Component->setUpper(1);
	standardProfile_BuildComponent_base_Component->setIsUnique(true);
	standardProfile_BuildComponent_base_Component->setAggregation(uml::AggregationKind::NONE);
	standardProfile_BuildComponent_base_Component->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_BuildComponent_base_Component->setAssociation(get_StandardProfile_Component_BuildComponent());
	
	standardProfile_BuildComponent_base_Component->_setID(BUILDCOMPONENT_ATTRIBUTE_BASE_COMPONENT);
	
	

	standardProfile_Call_base_Usage->setName("base_Usage");
	standardProfile_Call_base_Usage->setType(UML::UMLPackage::eInstance()->get_UML_Usage());
	standardProfile_Call_base_Usage->setLower(1);
	standardProfile_Call_base_Usage->setUpper(1);
	standardProfile_Call_base_Usage->setIsUnique(true);
	standardProfile_Call_base_Usage->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Call_base_Usage->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Call_base_Usage->setAssociation(get_StandardProfile_Usage_Call());
	
	standardProfile_Call_base_Usage->_setID(CALL_ATTRIBUTE_BASE_USAGE);
	
	

	standardProfile_Create_base_BehavioralFeature->setName("base_BehavioralFeature");
	standardProfile_Create_base_BehavioralFeature->setType(UML::UMLPackage::eInstance()->get_UML_BehavioralFeature());
	standardProfile_Create_base_BehavioralFeature->setLower(1);
	standardProfile_Create_base_BehavioralFeature->setUpper(1);
	standardProfile_Create_base_BehavioralFeature->setIsUnique(true);
	standardProfile_Create_base_BehavioralFeature->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Create_base_BehavioralFeature->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Create_base_BehavioralFeature->setAssociation(get_StandardProfile_BehavioralFeature_Create());
	
	standardProfile_Create_base_BehavioralFeature->_setID(CREATE_ATTRIBUTE_BASE_BEHAVIORALFEATURE);
	standardProfile_Create_base_Usage->setName("base_Usage");
	standardProfile_Create_base_Usage->setType(UML::UMLPackage::eInstance()->get_UML_Usage());
	standardProfile_Create_base_Usage->setLower(1);
	standardProfile_Create_base_Usage->setUpper(1);
	standardProfile_Create_base_Usage->setIsUnique(true);
	standardProfile_Create_base_Usage->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Create_base_Usage->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Create_base_Usage->setAssociation(get_StandardProfile_Usage_Create());
	
	standardProfile_Create_base_Usage->_setID(CREATE_ATTRIBUTE_BASE_USAGE);
	
	

	standardProfile_Derive_base_Abstraction->setName("base_Abstraction");
	standardProfile_Derive_base_Abstraction->setType(UML::UMLPackage::eInstance()->get_UML_Abstraction());
	standardProfile_Derive_base_Abstraction->setLower(1);
	standardProfile_Derive_base_Abstraction->setUpper(1);
	standardProfile_Derive_base_Abstraction->setIsUnique(true);
	standardProfile_Derive_base_Abstraction->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Derive_base_Abstraction->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Derive_base_Abstraction->setAssociation(get_StandardProfile_Abstraction_Derive());
	
	standardProfile_Derive_base_Abstraction->_setID(DERIVE_ATTRIBUTE_BASE_ABSTRACTION);
	
	

	standardProfile_Destroy_base_BehavioralFeature->setName("base_BehavioralFeature");
	standardProfile_Destroy_base_BehavioralFeature->setType(UML::UMLPackage::eInstance()->get_UML_BehavioralFeature());
	standardProfile_Destroy_base_BehavioralFeature->setLower(1);
	standardProfile_Destroy_base_BehavioralFeature->setUpper(1);
	standardProfile_Destroy_base_BehavioralFeature->setIsUnique(true);
	standardProfile_Destroy_base_BehavioralFeature->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Destroy_base_BehavioralFeature->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Destroy_base_BehavioralFeature->setAssociation(get_StandardProfile_BehavioralFeature_Destroy());
	
	standardProfile_Destroy_base_BehavioralFeature->_setID(DESTROY_ATTRIBUTE_BASE_BEHAVIORALFEATURE);
	
	

	standardProfile_Document_base_Artifact->setName("base_Artifact");
	standardProfile_Document_base_Artifact->setType(UML::UMLPackage::eInstance()->get_UML_Artifact());
	standardProfile_Document_base_Artifact->setLower(1);
	standardProfile_Document_base_Artifact->setUpper(1);
	standardProfile_Document_base_Artifact->setIsUnique(true);
	standardProfile_Document_base_Artifact->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Document_base_Artifact->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Document_base_Artifact->setAssociation(get_StandardProfile_Artifact_Document());
	
	standardProfile_Document_base_Artifact->_setID(DOCUMENT_ATTRIBUTE_BASE_ARTIFACT);
	
	

	standardProfile_Entity_base_Component->setName("base_Component");
	standardProfile_Entity_base_Component->setType(UML::UMLPackage::eInstance()->get_UML_Component());
	standardProfile_Entity_base_Component->setLower(1);
	standardProfile_Entity_base_Component->setUpper(1);
	standardProfile_Entity_base_Component->setIsUnique(true);
	standardProfile_Entity_base_Component->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Entity_base_Component->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Entity_base_Component->setAssociation(get_StandardProfile_Component_Entity());
	
	standardProfile_Entity_base_Component->_setID(ENTITY_ATTRIBUTE_BASE_COMPONENT);
	
	

	standardProfile_Executable_base_Artifact->setName("base_Artifact");
	standardProfile_Executable_base_Artifact->setType(UML::UMLPackage::eInstance()->get_UML_Artifact());
	standardProfile_Executable_base_Artifact->setLower(1);
	standardProfile_Executable_base_Artifact->setUpper(1);
	standardProfile_Executable_base_Artifact->setIsUnique(true);
	standardProfile_Executable_base_Artifact->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Executable_base_Artifact->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Executable_base_Artifact->setAssociation(get_StandardProfile_Artifact_Executable());
	
	standardProfile_Executable_base_Artifact->_setID(EXECUTABLE_ATTRIBUTE_BASE_ARTIFACT);
	
	

	standardProfile_File_base_Artifact->setName("base_Artifact");
	standardProfile_File_base_Artifact->setType(UML::UMLPackage::eInstance()->get_UML_Artifact());
	standardProfile_File_base_Artifact->setLower(1);
	standardProfile_File_base_Artifact->setUpper(1);
	standardProfile_File_base_Artifact->setIsUnique(true);
	standardProfile_File_base_Artifact->setAggregation(uml::AggregationKind::NONE);
	standardProfile_File_base_Artifact->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_File_base_Artifact->setAssociation(get_StandardProfile_Artifact_File());
	
	standardProfile_File_base_Artifact->_setID(FILE_ATTRIBUTE_BASE_ARTIFACT);
	
	

	standardProfile_Focus_base_Class->setName("base_Class");
	standardProfile_Focus_base_Class->setType(UML::UMLPackage::eInstance()->get_UML_Class());
	standardProfile_Focus_base_Class->setLower(1);
	standardProfile_Focus_base_Class->setUpper(1);
	standardProfile_Focus_base_Class->setIsUnique(true);
	standardProfile_Focus_base_Class->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Focus_base_Class->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Focus_base_Class->setAssociation(get_StandardProfile_Class_Focus());
	
	standardProfile_Focus_base_Class->_setID(FOCUS_ATTRIBUTE_BASE_CLASS);
	
	

	standardProfile_Framework_base_Package->setName("base_Package");
	standardProfile_Framework_base_Package->setType(UML::UMLPackage::eInstance()->get_UML_Package());
	standardProfile_Framework_base_Package->setLower(1);
	standardProfile_Framework_base_Package->setUpper(1);
	standardProfile_Framework_base_Package->setIsUnique(true);
	standardProfile_Framework_base_Package->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Framework_base_Package->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Framework_base_Package->setAssociation(get_StandardProfile_Package_Framework());
	
	standardProfile_Framework_base_Package->_setID(FRAMEWORK_ATTRIBUTE_BASE_PACKAGE);
	
	

	standardProfile_Implement_base_Component->setName("base_Component");
	standardProfile_Implement_base_Component->setType(UML::UMLPackage::eInstance()->get_UML_Component());
	standardProfile_Implement_base_Component->setLower(1);
	standardProfile_Implement_base_Component->setUpper(1);
	standardProfile_Implement_base_Component->setIsUnique(true);
	standardProfile_Implement_base_Component->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Implement_base_Component->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Implement_base_Component->setAssociation(get_StandardProfile_Component_Implement());
	
	standardProfile_Implement_base_Component->_setID(IMPLEMENT_ATTRIBUTE_BASE_COMPONENT);
	
	

	standardProfile_ImplementationClass_base_Class->setName("base_Class");
	standardProfile_ImplementationClass_base_Class->setType(UML::UMLPackage::eInstance()->get_UML_Class());
	standardProfile_ImplementationClass_base_Class->setLower(1);
	standardProfile_ImplementationClass_base_Class->setUpper(1);
	standardProfile_ImplementationClass_base_Class->setIsUnique(true);
	standardProfile_ImplementationClass_base_Class->setAggregation(uml::AggregationKind::NONE);
	standardProfile_ImplementationClass_base_Class->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_ImplementationClass_base_Class->setAssociation(get_StandardProfile_Class_ImplementationClass());
	
	standardProfile_ImplementationClass_base_Class->_setID(IMPLEMENTATIONCLASS_ATTRIBUTE_BASE_CLASS);
	
	

	standardProfile_Instantiate_base_Usage->setName("base_Usage");
	standardProfile_Instantiate_base_Usage->setType(UML::UMLPackage::eInstance()->get_UML_Usage());
	standardProfile_Instantiate_base_Usage->setLower(1);
	standardProfile_Instantiate_base_Usage->setUpper(1);
	standardProfile_Instantiate_base_Usage->setIsUnique(true);
	standardProfile_Instantiate_base_Usage->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Instantiate_base_Usage->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Instantiate_base_Usage->setAssociation(get_StandardProfile_Usage_Instantiate());
	
	standardProfile_Instantiate_base_Usage->_setID(INSTANTIATE_ATTRIBUTE_BASE_USAGE);
	
	

	standardProfile_Library_base_Artifact->setName("base_Artifact");
	standardProfile_Library_base_Artifact->setType(UML::UMLPackage::eInstance()->get_UML_Artifact());
	standardProfile_Library_base_Artifact->setLower(1);
	standardProfile_Library_base_Artifact->setUpper(1);
	standardProfile_Library_base_Artifact->setIsUnique(true);
	standardProfile_Library_base_Artifact->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Library_base_Artifact->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Library_base_Artifact->setAssociation(get_StandardProfile_Artifact_Library());
	
	standardProfile_Library_base_Artifact->_setID(LIBRARY_ATTRIBUTE_BASE_ARTIFACT);
	
	

	standardProfile_Metaclass_base_Class->setName("base_Class");
	standardProfile_Metaclass_base_Class->setType(UML::UMLPackage::eInstance()->get_UML_Class());
	standardProfile_Metaclass_base_Class->setLower(1);
	standardProfile_Metaclass_base_Class->setUpper(1);
	standardProfile_Metaclass_base_Class->setIsUnique(true);
	standardProfile_Metaclass_base_Class->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Metaclass_base_Class->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Metaclass_base_Class->setAssociation(get_StandardProfile_Class_Metaclass());
	
	standardProfile_Metaclass_base_Class->_setID(METACLASS_ATTRIBUTE_BASE_CLASS);
	
	

	standardProfile_Metamodel_base_Model->setName("base_Model");
	standardProfile_Metamodel_base_Model->setType(UML::UMLPackage::eInstance()->get_UML_Model());
	standardProfile_Metamodel_base_Model->setLower(1);
	standardProfile_Metamodel_base_Model->setUpper(1);
	standardProfile_Metamodel_base_Model->setIsUnique(true);
	standardProfile_Metamodel_base_Model->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Metamodel_base_Model->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Metamodel_base_Model->setAssociation(get_StandardProfile_Model_Metamodel());
	
	standardProfile_Metamodel_base_Model->_setID(METAMODEL_ATTRIBUTE_BASE_MODEL);
	
	

	standardProfile_ModelLibrary_base_Package->setName("base_Package");
	standardProfile_ModelLibrary_base_Package->setType(UML::UMLPackage::eInstance()->get_UML_Package());
	standardProfile_ModelLibrary_base_Package->setLower(1);
	standardProfile_ModelLibrary_base_Package->setUpper(1);
	standardProfile_ModelLibrary_base_Package->setIsUnique(true);
	standardProfile_ModelLibrary_base_Package->setAggregation(uml::AggregationKind::NONE);
	standardProfile_ModelLibrary_base_Package->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_ModelLibrary_base_Package->setAssociation(get_StandardProfile_Package_ModelLibrary());
	
	standardProfile_ModelLibrary_base_Package->_setID(MODELLIBRARY_ATTRIBUTE_BASE_PACKAGE);
	
	

	standardProfile_Process_base_Component->setName("base_Component");
	standardProfile_Process_base_Component->setType(UML::UMLPackage::eInstance()->get_UML_Component());
	standardProfile_Process_base_Component->setLower(1);
	standardProfile_Process_base_Component->setUpper(1);
	standardProfile_Process_base_Component->setIsUnique(true);
	standardProfile_Process_base_Component->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Process_base_Component->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Process_base_Component->setAssociation(get_StandardProfile_Component_Process());
	
	standardProfile_Process_base_Component->_setID(PROCESS_ATTRIBUTE_BASE_COMPONENT);
	
	

	standardProfile_Realization_base_Classifier->setName("base_Classifier");
	standardProfile_Realization_base_Classifier->setType(UML::UMLPackage::eInstance()->get_UML_Classifier());
	standardProfile_Realization_base_Classifier->setLower(1);
	standardProfile_Realization_base_Classifier->setUpper(1);
	standardProfile_Realization_base_Classifier->setIsUnique(true);
	standardProfile_Realization_base_Classifier->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Realization_base_Classifier->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Realization_base_Classifier->setAssociation(get_StandardProfile_Classifier_Realization());
	
	standardProfile_Realization_base_Classifier->_setID(REALIZATION_ATTRIBUTE_BASE_CLASSIFIER);
	
	

	standardProfile_Refine_base_Abstraction->setName("base_Abstraction");
	standardProfile_Refine_base_Abstraction->setType(UML::UMLPackage::eInstance()->get_UML_Abstraction());
	standardProfile_Refine_base_Abstraction->setLower(1);
	standardProfile_Refine_base_Abstraction->setUpper(1);
	standardProfile_Refine_base_Abstraction->setIsUnique(true);
	standardProfile_Refine_base_Abstraction->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Refine_base_Abstraction->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Refine_base_Abstraction->setAssociation(get_StandardProfile_Abstraction_Refine());
	
	standardProfile_Refine_base_Abstraction->_setID(REFINE_ATTRIBUTE_BASE_ABSTRACTION);
	
	

	standardProfile_Responsibility_base_Usage->setName("base_Usage");
	standardProfile_Responsibility_base_Usage->setType(UML::UMLPackage::eInstance()->get_UML_Usage());
	standardProfile_Responsibility_base_Usage->setLower(1);
	standardProfile_Responsibility_base_Usage->setUpper(1);
	standardProfile_Responsibility_base_Usage->setIsUnique(true);
	standardProfile_Responsibility_base_Usage->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Responsibility_base_Usage->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Responsibility_base_Usage->setAssociation(get_StandardProfile_Usage_Responsibility());
	
	standardProfile_Responsibility_base_Usage->_setID(RESPONSIBILITY_ATTRIBUTE_BASE_USAGE);
	
	

	standardProfile_Script_base_Artifact->setName("base_Artifact");
	standardProfile_Script_base_Artifact->setType(UML::UMLPackage::eInstance()->get_UML_Artifact());
	standardProfile_Script_base_Artifact->setLower(1);
	standardProfile_Script_base_Artifact->setUpper(1);
	standardProfile_Script_base_Artifact->setIsUnique(true);
	standardProfile_Script_base_Artifact->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Script_base_Artifact->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Script_base_Artifact->setAssociation(get_StandardProfile_Artifact_Script());
	
	standardProfile_Script_base_Artifact->_setID(SCRIPT_ATTRIBUTE_BASE_ARTIFACT);
	
	

	standardProfile_Send_base_Usage->setName("base_Usage");
	standardProfile_Send_base_Usage->setType(UML::UMLPackage::eInstance()->get_UML_Usage());
	standardProfile_Send_base_Usage->setLower(1);
	standardProfile_Send_base_Usage->setUpper(1);
	standardProfile_Send_base_Usage->setIsUnique(true);
	standardProfile_Send_base_Usage->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Send_base_Usage->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Send_base_Usage->setAssociation(get_StandardProfile_Usage_Send());
	
	standardProfile_Send_base_Usage->_setID(SEND_ATTRIBUTE_BASE_USAGE);
	
	

	standardProfile_Service_base_Component->setName("base_Component");
	standardProfile_Service_base_Component->setType(UML::UMLPackage::eInstance()->get_UML_Component());
	standardProfile_Service_base_Component->setLower(1);
	standardProfile_Service_base_Component->setUpper(1);
	standardProfile_Service_base_Component->setIsUnique(true);
	standardProfile_Service_base_Component->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Service_base_Component->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Service_base_Component->setAssociation(get_StandardProfile_Component_Service());
	
	standardProfile_Service_base_Component->_setID(SERVICE_ATTRIBUTE_BASE_COMPONENT);
	
	

	standardProfile_Source_base_Artifact->setName("base_Artifact");
	standardProfile_Source_base_Artifact->setType(UML::UMLPackage::eInstance()->get_UML_Artifact());
	standardProfile_Source_base_Artifact->setLower(1);
	standardProfile_Source_base_Artifact->setUpper(1);
	standardProfile_Source_base_Artifact->setIsUnique(true);
	standardProfile_Source_base_Artifact->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Source_base_Artifact->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Source_base_Artifact->setAssociation(get_StandardProfile_Artifact_Source());
	
	standardProfile_Source_base_Artifact->_setID(SOURCE_ATTRIBUTE_BASE_ARTIFACT);
	
	

	standardProfile_Specification_base_Classifier->setName("base_Classifier");
	standardProfile_Specification_base_Classifier->setType(UML::UMLPackage::eInstance()->get_UML_Classifier());
	standardProfile_Specification_base_Classifier->setLower(1);
	standardProfile_Specification_base_Classifier->setUpper(1);
	standardProfile_Specification_base_Classifier->setIsUnique(true);
	standardProfile_Specification_base_Classifier->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Specification_base_Classifier->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Specification_base_Classifier->setAssociation(get_StandardProfile_Classifier_Specification());
	
	standardProfile_Specification_base_Classifier->_setID(SPECIFICATION_ATTRIBUTE_BASE_CLASSIFIER);
	
	

	standardProfile_Subsystem_base_Component->setName("base_Component");
	standardProfile_Subsystem_base_Component->setType(UML::UMLPackage::eInstance()->get_UML_Component());
	standardProfile_Subsystem_base_Component->setLower(1);
	standardProfile_Subsystem_base_Component->setUpper(1);
	standardProfile_Subsystem_base_Component->setIsUnique(true);
	standardProfile_Subsystem_base_Component->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Subsystem_base_Component->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Subsystem_base_Component->setAssociation(get_StandardProfile_Component_Subsystem());
	
	standardProfile_Subsystem_base_Component->_setID(SUBSYSTEM_ATTRIBUTE_BASE_COMPONENT);
	
	

	standardProfile_SystemModel_base_Model->setName("base_Model");
	standardProfile_SystemModel_base_Model->setType(UML::UMLPackage::eInstance()->get_UML_Model());
	standardProfile_SystemModel_base_Model->setLower(1);
	standardProfile_SystemModel_base_Model->setUpper(1);
	standardProfile_SystemModel_base_Model->setIsUnique(true);
	standardProfile_SystemModel_base_Model->setAggregation(uml::AggregationKind::NONE);
	standardProfile_SystemModel_base_Model->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_SystemModel_base_Model->setAssociation(get_StandardProfile_Model_SystemModel());
	
	standardProfile_SystemModel_base_Model->_setID(SYSTEMMODEL_ATTRIBUTE_BASE_MODEL);
	
	

	standardProfile_Trace_base_Abstraction->setName("base_Abstraction");
	standardProfile_Trace_base_Abstraction->setType(UML::UMLPackage::eInstance()->get_UML_Abstraction());
	standardProfile_Trace_base_Abstraction->setLower(1);
	standardProfile_Trace_base_Abstraction->setUpper(1);
	standardProfile_Trace_base_Abstraction->setIsUnique(true);
	standardProfile_Trace_base_Abstraction->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Trace_base_Abstraction->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Trace_base_Abstraction->setAssociation(get_StandardProfile_Abstraction_Trace());
	
	standardProfile_Trace_base_Abstraction->_setID(TRACE_ATTRIBUTE_BASE_ABSTRACTION);
	
	

	standardProfile_Type_base_Class->setName("base_Class");
	standardProfile_Type_base_Class->setType(UML::UMLPackage::eInstance()->get_UML_Class());
	standardProfile_Type_base_Class->setLower(1);
	standardProfile_Type_base_Class->setUpper(1);
	standardProfile_Type_base_Class->setIsUnique(true);
	standardProfile_Type_base_Class->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Type_base_Class->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Type_base_Class->setAssociation(get_StandardProfile_Class_Type());
	
	standardProfile_Type_base_Class->_setID(TYPE_ATTRIBUTE_BASE_CLASS);
	
	

	standardProfile_Utility_base_Class->setName("base_Class");
	standardProfile_Utility_base_Class->setType(UML::UMLPackage::eInstance()->get_UML_Class());
	standardProfile_Utility_base_Class->setLower(1);
	standardProfile_Utility_base_Class->setUpper(1);
	standardProfile_Utility_base_Class->setIsUnique(true);
	standardProfile_Utility_base_Class->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Utility_base_Class->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Utility_base_Class->setAssociation(get_StandardProfile_Class_Utility());
	
	standardProfile_Utility_base_Class->_setID(UTILITY_ATTRIBUTE_BASE_CLASS);
	
	
}

void StandardProfilePackageImpl::initializePackageValueSpecifications()
{
	extensionEnd_extension_Auxiliary_StandardProfile_Auxiliary_lowerValue_LiteralInteger_ExtensionEnd_extension_Auxiliary_StandardProfile_Auxiliary->setValue(0);

	extensionEnd_extension_BehavioralFeature_Create_StandardProfile_Create_lowerValue_LiteralInteger_ExtensionEnd_extension_BehavioralFeature_Create_StandardProfile_Create->setValue(0);

	extensionEnd_extension_BuildComponent_StandardProfile_BuildComponent_lowerValue_LiteralInteger_ExtensionEnd_extension_BuildComponent_StandardProfile_BuildComponent->setValue(0);

	extensionEnd_extension_Call_StandardProfile_Call_lowerValue_LiteralInteger_ExtensionEnd_extension_Call_StandardProfile_Call->setValue(0);

	extensionEnd_extension_Derive_StandardProfile_Derive_lowerValue_LiteralInteger_ExtensionEnd_extension_Derive_StandardProfile_Derive->setValue(0);

	extensionEnd_extension_Destroy_StandardProfile_Destroy_lowerValue_LiteralInteger_ExtensionEnd_extension_Destroy_StandardProfile_Destroy->setValue(0);

	extensionEnd_extension_Document_StandardProfile_Document_lowerValue_LiteralInteger_ExtensionEnd_extension_Document_StandardProfile_Document->setValue(0);

	extensionEnd_extension_Entity_StandardProfile_Entity_lowerValue_LiteralInteger_ExtensionEnd_extension_Entity_StandardProfile_Entity->setValue(0);

	extensionEnd_extension_Executable_StandardProfile_Executable_lowerValue_LiteralInteger_ExtensionEnd_extension_Executable_StandardProfile_Executable->setValue(0);

	extensionEnd_extension_File_StandardProfile_File_lowerValue_LiteralInteger_ExtensionEnd_extension_File_StandardProfile_File->setValue(0);

	extensionEnd_extension_Focus_StandardProfile_Focus_lowerValue_LiteralInteger_ExtensionEnd_extension_Focus_StandardProfile_Focus->setValue(0);

	extensionEnd_extension_Framework_StandardProfile_Framework_lowerValue_LiteralInteger_ExtensionEnd_extension_Framework_StandardProfile_Framework->setValue(0);

	extensionEnd_extension_Implement_StandardProfile_Implement_lowerValue_LiteralInteger_ExtensionEnd_extension_Implement_StandardProfile_Implement->setValue(0);

	extensionEnd_extension_ImplementationClass_StandardProfile_ImplementationClass_lowerValue_LiteralInteger_ExtensionEnd_extension_ImplementationClass_StandardProfile_ImplementationClass->setValue(0);

	extensionEnd_extension_Instantiate_StandardProfile_Instantiate_lowerValue_LiteralInteger_ExtensionEnd_extension_Instantiate_StandardProfile_Instantiate->setValue(0);

	extensionEnd_extension_Library_StandardProfile_Library_lowerValue_LiteralInteger_ExtensionEnd_extension_Library_StandardProfile_Library->setValue(0);

	extensionEnd_extension_Metaclass_StandardProfile_Metaclass_lowerValue_LiteralInteger_ExtensionEnd_extension_Metaclass_StandardProfile_Metaclass->setValue(0);

	extensionEnd_extension_Metamodel_StandardProfile_Metamodel_lowerValue_LiteralInteger_ExtensionEnd_extension_Metamodel_StandardProfile_Metamodel->setValue(0);

	extensionEnd_extension_ModelLibrary_StandardProfile_ModelLibrary_lowerValue_LiteralInteger_ExtensionEnd_extension_ModelLibrary_StandardProfile_ModelLibrary->setValue(0);

	extensionEnd_extension_Process_StandardProfile_Process_lowerValue_LiteralInteger_ExtensionEnd_extension_Process_StandardProfile_Process->setValue(0);

	extensionEnd_extension_Realization_StandardProfile_Realization_lowerValue_LiteralInteger_ExtensionEnd_extension_Realization_StandardProfile_Realization->setValue(0);

	extensionEnd_extension_Refine_StandardProfile_Refine_lowerValue_LiteralInteger_ExtensionEnd_extension_Refine_StandardProfile_Refine->setValue(0);

	extensionEnd_extension_Responsibility_StandardProfile_Responsibility_lowerValue_LiteralInteger_ExtensionEnd_extension_Responsibility_StandardProfile_Responsibility->setValue(0);

	extensionEnd_extension_Script_StandardProfile_Script_lowerValue_LiteralInteger_ExtensionEnd_extension_Script_StandardProfile_Script->setValue(0);

	extensionEnd_extension_Send_StandardProfile_Send_lowerValue_LiteralInteger_ExtensionEnd_extension_Send_StandardProfile_Send->setValue(0);

	extensionEnd_extension_Service_StandardProfile_Service_lowerValue_LiteralInteger_ExtensionEnd_extension_Service_StandardProfile_Service->setValue(0);

	extensionEnd_extension_Source_StandardProfile_Source_lowerValue_LiteralInteger_ExtensionEnd_extension_Source_StandardProfile_Source->setValue(0);

	extensionEnd_extension_Specification_StandardProfile_Specification_lowerValue_LiteralInteger_ExtensionEnd_extension_Specification_StandardProfile_Specification->setValue(0);

	extensionEnd_extension_Subsystem_StandardProfile_Subsystem_lowerValue_LiteralInteger_ExtensionEnd_extension_Subsystem_StandardProfile_Subsystem->setValue(0);

	extensionEnd_extension_SystemModel_StandardProfile_SystemModel_lowerValue_LiteralInteger_ExtensionEnd_extension_SystemModel_StandardProfile_SystemModel->setValue(0);

	extensionEnd_extension_Trace_StandardProfile_Trace_lowerValue_LiteralInteger_ExtensionEnd_extension_Trace_StandardProfile_Trace->setValue(0);

	extensionEnd_extension_Type_StandardProfile_Type_lowerValue_LiteralInteger_ExtensionEnd_extension_Type_StandardProfile_Type->setValue(0);

	extensionEnd_extension_Usage_Create_StandardProfile_Create_lowerValue_LiteralInteger_ExtensionEnd_extension_Usage_Create_StandardProfile_Create->setValue(0);

	extensionEnd_extension_Utility_StandardProfile_Utility_lowerValue_LiteralInteger_ExtensionEnd_extension_Utility_StandardProfile_Utility->setValue(0);
}

std::shared_ptr<uml::ExtensionEnd> StandardProfilePackageImpl::get_ExtensionEnd_extension_Auxiliary_StandardProfile_Auxiliary()
{
	return extensionEnd_extension_Auxiliary_StandardProfile_Auxiliary;
}
std::shared_ptr<uml::ExtensionEnd> StandardProfilePackageImpl::get_ExtensionEnd_extension_BehavioralFeature_Create_StandardProfile_Create()
{
	return extensionEnd_extension_BehavioralFeature_Create_StandardProfile_Create;
}
std::shared_ptr<uml::ExtensionEnd> StandardProfilePackageImpl::get_ExtensionEnd_extension_BuildComponent_StandardProfile_BuildComponent()
{
	return extensionEnd_extension_BuildComponent_StandardProfile_BuildComponent;
}
std::shared_ptr<uml::ExtensionEnd> StandardProfilePackageImpl::get_ExtensionEnd_extension_Call_StandardProfile_Call()
{
	return extensionEnd_extension_Call_StandardProfile_Call;
}
std::shared_ptr<uml::ExtensionEnd> StandardProfilePackageImpl::get_ExtensionEnd_extension_Derive_StandardProfile_Derive()
{
	return extensionEnd_extension_Derive_StandardProfile_Derive;
}
std::shared_ptr<uml::ExtensionEnd> StandardProfilePackageImpl::get_ExtensionEnd_extension_Destroy_StandardProfile_Destroy()
{
	return extensionEnd_extension_Destroy_StandardProfile_Destroy;
}
std::shared_ptr<uml::ExtensionEnd> StandardProfilePackageImpl::get_ExtensionEnd_extension_Document_StandardProfile_Document()
{
	return extensionEnd_extension_Document_StandardProfile_Document;
}
std::shared_ptr<uml::ExtensionEnd> StandardProfilePackageImpl::get_ExtensionEnd_extension_Entity_StandardProfile_Entity()
{
	return extensionEnd_extension_Entity_StandardProfile_Entity;
}
std::shared_ptr<uml::ExtensionEnd> StandardProfilePackageImpl::get_ExtensionEnd_extension_Executable_StandardProfile_Executable()
{
	return extensionEnd_extension_Executable_StandardProfile_Executable;
}
std::shared_ptr<uml::ExtensionEnd> StandardProfilePackageImpl::get_ExtensionEnd_extension_File_StandardProfile_File()
{
	return extensionEnd_extension_File_StandardProfile_File;
}
std::shared_ptr<uml::ExtensionEnd> StandardProfilePackageImpl::get_ExtensionEnd_extension_Focus_StandardProfile_Focus()
{
	return extensionEnd_extension_Focus_StandardProfile_Focus;
}
std::shared_ptr<uml::ExtensionEnd> StandardProfilePackageImpl::get_ExtensionEnd_extension_Framework_StandardProfile_Framework()
{
	return extensionEnd_extension_Framework_StandardProfile_Framework;
}
std::shared_ptr<uml::ExtensionEnd> StandardProfilePackageImpl::get_ExtensionEnd_extension_Implement_StandardProfile_Implement()
{
	return extensionEnd_extension_Implement_StandardProfile_Implement;
}
std::shared_ptr<uml::ExtensionEnd> StandardProfilePackageImpl::get_ExtensionEnd_extension_ImplementationClass_StandardProfile_ImplementationClass()
{
	return extensionEnd_extension_ImplementationClass_StandardProfile_ImplementationClass;
}
std::shared_ptr<uml::ExtensionEnd> StandardProfilePackageImpl::get_ExtensionEnd_extension_Instantiate_StandardProfile_Instantiate()
{
	return extensionEnd_extension_Instantiate_StandardProfile_Instantiate;
}
std::shared_ptr<uml::ExtensionEnd> StandardProfilePackageImpl::get_ExtensionEnd_extension_Library_StandardProfile_Library()
{
	return extensionEnd_extension_Library_StandardProfile_Library;
}
std::shared_ptr<uml::ExtensionEnd> StandardProfilePackageImpl::get_ExtensionEnd_extension_Metaclass_StandardProfile_Metaclass()
{
	return extensionEnd_extension_Metaclass_StandardProfile_Metaclass;
}
std::shared_ptr<uml::ExtensionEnd> StandardProfilePackageImpl::get_ExtensionEnd_extension_Metamodel_StandardProfile_Metamodel()
{
	return extensionEnd_extension_Metamodel_StandardProfile_Metamodel;
}
std::shared_ptr<uml::ExtensionEnd> StandardProfilePackageImpl::get_ExtensionEnd_extension_ModelLibrary_StandardProfile_ModelLibrary()
{
	return extensionEnd_extension_ModelLibrary_StandardProfile_ModelLibrary;
}
std::shared_ptr<uml::ExtensionEnd> StandardProfilePackageImpl::get_ExtensionEnd_extension_Process_StandardProfile_Process()
{
	return extensionEnd_extension_Process_StandardProfile_Process;
}
std::shared_ptr<uml::ExtensionEnd> StandardProfilePackageImpl::get_ExtensionEnd_extension_Realization_StandardProfile_Realization()
{
	return extensionEnd_extension_Realization_StandardProfile_Realization;
}
std::shared_ptr<uml::ExtensionEnd> StandardProfilePackageImpl::get_ExtensionEnd_extension_Refine_StandardProfile_Refine()
{
	return extensionEnd_extension_Refine_StandardProfile_Refine;
}
std::shared_ptr<uml::ExtensionEnd> StandardProfilePackageImpl::get_ExtensionEnd_extension_Responsibility_StandardProfile_Responsibility()
{
	return extensionEnd_extension_Responsibility_StandardProfile_Responsibility;
}
std::shared_ptr<uml::ExtensionEnd> StandardProfilePackageImpl::get_ExtensionEnd_extension_Script_StandardProfile_Script()
{
	return extensionEnd_extension_Script_StandardProfile_Script;
}
std::shared_ptr<uml::ExtensionEnd> StandardProfilePackageImpl::get_ExtensionEnd_extension_Send_StandardProfile_Send()
{
	return extensionEnd_extension_Send_StandardProfile_Send;
}
std::shared_ptr<uml::ExtensionEnd> StandardProfilePackageImpl::get_ExtensionEnd_extension_Service_StandardProfile_Service()
{
	return extensionEnd_extension_Service_StandardProfile_Service;
}
std::shared_ptr<uml::ExtensionEnd> StandardProfilePackageImpl::get_ExtensionEnd_extension_Source_StandardProfile_Source()
{
	return extensionEnd_extension_Source_StandardProfile_Source;
}
std::shared_ptr<uml::ExtensionEnd> StandardProfilePackageImpl::get_ExtensionEnd_extension_Specification_StandardProfile_Specification()
{
	return extensionEnd_extension_Specification_StandardProfile_Specification;
}
std::shared_ptr<uml::ExtensionEnd> StandardProfilePackageImpl::get_ExtensionEnd_extension_Subsystem_StandardProfile_Subsystem()
{
	return extensionEnd_extension_Subsystem_StandardProfile_Subsystem;
}
std::shared_ptr<uml::ExtensionEnd> StandardProfilePackageImpl::get_ExtensionEnd_extension_SystemModel_StandardProfile_SystemModel()
{
	return extensionEnd_extension_SystemModel_StandardProfile_SystemModel;
}
std::shared_ptr<uml::ExtensionEnd> StandardProfilePackageImpl::get_ExtensionEnd_extension_Trace_StandardProfile_Trace()
{
	return extensionEnd_extension_Trace_StandardProfile_Trace;
}
std::shared_ptr<uml::ExtensionEnd> StandardProfilePackageImpl::get_ExtensionEnd_extension_Type_StandardProfile_Type()
{
	return extensionEnd_extension_Type_StandardProfile_Type;
}
std::shared_ptr<uml::ExtensionEnd> StandardProfilePackageImpl::get_ExtensionEnd_extension_Usage_Create_StandardProfile_Create()
{
	return extensionEnd_extension_Usage_Create_StandardProfile_Create;
}
std::shared_ptr<uml::ExtensionEnd> StandardProfilePackageImpl::get_ExtensionEnd_extension_Utility_StandardProfile_Utility()
{
	return extensionEnd_extension_Utility_StandardProfile_Utility;
}
std::shared_ptr<uml::Extension> StandardProfilePackageImpl::get_StandardProfile_Abstraction_Derive()
{
	return standardProfile_Abstraction_Derive;
}
std::shared_ptr<uml::Extension> StandardProfilePackageImpl::get_StandardProfile_Abstraction_Refine()
{
	return standardProfile_Abstraction_Refine;
}
std::shared_ptr<uml::Extension> StandardProfilePackageImpl::get_StandardProfile_Abstraction_Trace()
{
	return standardProfile_Abstraction_Trace;
}
std::shared_ptr<uml::Extension> StandardProfilePackageImpl::get_StandardProfile_Artifact_Document()
{
	return standardProfile_Artifact_Document;
}
std::shared_ptr<uml::Extension> StandardProfilePackageImpl::get_StandardProfile_Artifact_Executable()
{
	return standardProfile_Artifact_Executable;
}
std::shared_ptr<uml::Extension> StandardProfilePackageImpl::get_StandardProfile_Artifact_File()
{
	return standardProfile_Artifact_File;
}
std::shared_ptr<uml::Extension> StandardProfilePackageImpl::get_StandardProfile_Artifact_Library()
{
	return standardProfile_Artifact_Library;
}
std::shared_ptr<uml::Extension> StandardProfilePackageImpl::get_StandardProfile_Artifact_Script()
{
	return standardProfile_Artifact_Script;
}
std::shared_ptr<uml::Extension> StandardProfilePackageImpl::get_StandardProfile_Artifact_Source()
{
	return standardProfile_Artifact_Source;
}
std::shared_ptr<uml::Stereotype> StandardProfilePackageImpl::get_StandardProfile_Auxiliary()
{
	return standardProfile_Auxiliary;
}
std::shared_ptr<uml::Property> StandardProfilePackageImpl::get_StandardProfile_Auxiliary_base_Class()
{
	return standardProfile_Auxiliary_base_Class;
}
std::shared_ptr<uml::Extension> StandardProfilePackageImpl::get_StandardProfile_BehavioralFeature_Create()
{
	return standardProfile_BehavioralFeature_Create;
}
std::shared_ptr<uml::Extension> StandardProfilePackageImpl::get_StandardProfile_BehavioralFeature_Destroy()
{
	return standardProfile_BehavioralFeature_Destroy;
}
std::shared_ptr<uml::Stereotype> StandardProfilePackageImpl::get_StandardProfile_BuildComponent()
{
	return standardProfile_BuildComponent;
}
std::shared_ptr<uml::Property> StandardProfilePackageImpl::get_StandardProfile_BuildComponent_base_Component()
{
	return standardProfile_BuildComponent_base_Component;
}
std::shared_ptr<uml::Stereotype> StandardProfilePackageImpl::get_StandardProfile_Call()
{
	return standardProfile_Call;
}
std::shared_ptr<uml::Property> StandardProfilePackageImpl::get_StandardProfile_Call_base_Usage()
{
	return standardProfile_Call_base_Usage;
}
std::shared_ptr<uml::Extension> StandardProfilePackageImpl::get_StandardProfile_Class_Auxiliary()
{
	return standardProfile_Class_Auxiliary;
}
std::shared_ptr<uml::Extension> StandardProfilePackageImpl::get_StandardProfile_Class_Focus()
{
	return standardProfile_Class_Focus;
}
std::shared_ptr<uml::Extension> StandardProfilePackageImpl::get_StandardProfile_Class_ImplementationClass()
{
	return standardProfile_Class_ImplementationClass;
}
std::shared_ptr<uml::Extension> StandardProfilePackageImpl::get_StandardProfile_Class_Metaclass()
{
	return standardProfile_Class_Metaclass;
}
std::shared_ptr<uml::Extension> StandardProfilePackageImpl::get_StandardProfile_Class_Type()
{
	return standardProfile_Class_Type;
}
std::shared_ptr<uml::Extension> StandardProfilePackageImpl::get_StandardProfile_Class_Utility()
{
	return standardProfile_Class_Utility;
}
std::shared_ptr<uml::Extension> StandardProfilePackageImpl::get_StandardProfile_Classifier_Realization()
{
	return standardProfile_Classifier_Realization;
}
std::shared_ptr<uml::Extension> StandardProfilePackageImpl::get_StandardProfile_Classifier_Specification()
{
	return standardProfile_Classifier_Specification;
}
std::shared_ptr<uml::Extension> StandardProfilePackageImpl::get_StandardProfile_Component_BuildComponent()
{
	return standardProfile_Component_BuildComponent;
}
std::shared_ptr<uml::Extension> StandardProfilePackageImpl::get_StandardProfile_Component_Entity()
{
	return standardProfile_Component_Entity;
}
std::shared_ptr<uml::Extension> StandardProfilePackageImpl::get_StandardProfile_Component_Implement()
{
	return standardProfile_Component_Implement;
}
std::shared_ptr<uml::Extension> StandardProfilePackageImpl::get_StandardProfile_Component_Process()
{
	return standardProfile_Component_Process;
}
std::shared_ptr<uml::Extension> StandardProfilePackageImpl::get_StandardProfile_Component_Service()
{
	return standardProfile_Component_Service;
}
std::shared_ptr<uml::Extension> StandardProfilePackageImpl::get_StandardProfile_Component_Subsystem()
{
	return standardProfile_Component_Subsystem;
}
std::shared_ptr<uml::Stereotype> StandardProfilePackageImpl::get_StandardProfile_Create()
{
	return standardProfile_Create;
}
std::shared_ptr<uml::Property> StandardProfilePackageImpl::get_StandardProfile_Create_base_BehavioralFeature()
{
	return standardProfile_Create_base_BehavioralFeature;
}
std::shared_ptr<uml::Property> StandardProfilePackageImpl::get_StandardProfile_Create_base_Usage()
{
	return standardProfile_Create_base_Usage;
}
std::shared_ptr<uml::Stereotype> StandardProfilePackageImpl::get_StandardProfile_Derive()
{
	return standardProfile_Derive;
}
std::shared_ptr<uml::Property> StandardProfilePackageImpl::get_StandardProfile_Derive_base_Abstraction()
{
	return standardProfile_Derive_base_Abstraction;
}
std::shared_ptr<uml::Stereotype> StandardProfilePackageImpl::get_StandardProfile_Destroy()
{
	return standardProfile_Destroy;
}
std::shared_ptr<uml::Property> StandardProfilePackageImpl::get_StandardProfile_Destroy_base_BehavioralFeature()
{
	return standardProfile_Destroy_base_BehavioralFeature;
}
std::shared_ptr<uml::Stereotype> StandardProfilePackageImpl::get_StandardProfile_Document()
{
	return standardProfile_Document;
}
std::shared_ptr<uml::Property> StandardProfilePackageImpl::get_StandardProfile_Document_base_Artifact()
{
	return standardProfile_Document_base_Artifact;
}
std::shared_ptr<uml::Stereotype> StandardProfilePackageImpl::get_StandardProfile_Entity()
{
	return standardProfile_Entity;
}
std::shared_ptr<uml::Property> StandardProfilePackageImpl::get_StandardProfile_Entity_base_Component()
{
	return standardProfile_Entity_base_Component;
}
std::shared_ptr<uml::Stereotype> StandardProfilePackageImpl::get_StandardProfile_Executable()
{
	return standardProfile_Executable;
}
std::shared_ptr<uml::Property> StandardProfilePackageImpl::get_StandardProfile_Executable_base_Artifact()
{
	return standardProfile_Executable_base_Artifact;
}
std::shared_ptr<uml::Stereotype> StandardProfilePackageImpl::get_StandardProfile_File()
{
	return standardProfile_File;
}
std::shared_ptr<uml::Property> StandardProfilePackageImpl::get_StandardProfile_File_base_Artifact()
{
	return standardProfile_File_base_Artifact;
}
std::shared_ptr<uml::Stereotype> StandardProfilePackageImpl::get_StandardProfile_Focus()
{
	return standardProfile_Focus;
}
std::shared_ptr<uml::Property> StandardProfilePackageImpl::get_StandardProfile_Focus_base_Class()
{
	return standardProfile_Focus_base_Class;
}
std::shared_ptr<uml::Stereotype> StandardProfilePackageImpl::get_StandardProfile_Framework()
{
	return standardProfile_Framework;
}
std::shared_ptr<uml::Property> StandardProfilePackageImpl::get_StandardProfile_Framework_base_Package()
{
	return standardProfile_Framework_base_Package;
}
std::shared_ptr<uml::Stereotype> StandardProfilePackageImpl::get_StandardProfile_Implement()
{
	return standardProfile_Implement;
}
std::shared_ptr<uml::Property> StandardProfilePackageImpl::get_StandardProfile_Implement_base_Component()
{
	return standardProfile_Implement_base_Component;
}
std::shared_ptr<uml::Stereotype> StandardProfilePackageImpl::get_StandardProfile_ImplementationClass()
{
	return standardProfile_ImplementationClass;
}
std::shared_ptr<uml::Property> StandardProfilePackageImpl::get_StandardProfile_ImplementationClass_base_Class()
{
	return standardProfile_ImplementationClass_base_Class;
}
std::shared_ptr<uml::Stereotype> StandardProfilePackageImpl::get_StandardProfile_Instantiate()
{
	return standardProfile_Instantiate;
}
std::shared_ptr<uml::Property> StandardProfilePackageImpl::get_StandardProfile_Instantiate_base_Usage()
{
	return standardProfile_Instantiate_base_Usage;
}
std::shared_ptr<uml::Stereotype> StandardProfilePackageImpl::get_StandardProfile_Library()
{
	return standardProfile_Library;
}
std::shared_ptr<uml::Property> StandardProfilePackageImpl::get_StandardProfile_Library_base_Artifact()
{
	return standardProfile_Library_base_Artifact;
}
std::shared_ptr<uml::Stereotype> StandardProfilePackageImpl::get_StandardProfile_Metaclass()
{
	return standardProfile_Metaclass;
}
std::shared_ptr<uml::Property> StandardProfilePackageImpl::get_StandardProfile_Metaclass_base_Class()
{
	return standardProfile_Metaclass_base_Class;
}
std::shared_ptr<uml::Stereotype> StandardProfilePackageImpl::get_StandardProfile_Metamodel()
{
	return standardProfile_Metamodel;
}
std::shared_ptr<uml::Property> StandardProfilePackageImpl::get_StandardProfile_Metamodel_base_Model()
{
	return standardProfile_Metamodel_base_Model;
}
std::shared_ptr<uml::Stereotype> StandardProfilePackageImpl::get_StandardProfile_ModelLibrary()
{
	return standardProfile_ModelLibrary;
}
std::shared_ptr<uml::Property> StandardProfilePackageImpl::get_StandardProfile_ModelLibrary_base_Package()
{
	return standardProfile_ModelLibrary_base_Package;
}
std::shared_ptr<uml::Extension> StandardProfilePackageImpl::get_StandardProfile_Model_Metamodel()
{
	return standardProfile_Model_Metamodel;
}
std::shared_ptr<uml::Extension> StandardProfilePackageImpl::get_StandardProfile_Model_SystemModel()
{
	return standardProfile_Model_SystemModel;
}
std::shared_ptr<uml::Extension> StandardProfilePackageImpl::get_StandardProfile_Package_Framework()
{
	return standardProfile_Package_Framework;
}
std::shared_ptr<uml::Extension> StandardProfilePackageImpl::get_StandardProfile_Package_ModelLibrary()
{
	return standardProfile_Package_ModelLibrary;
}
std::shared_ptr<uml::Stereotype> StandardProfilePackageImpl::get_StandardProfile_Process()
{
	return standardProfile_Process;
}
std::shared_ptr<uml::Property> StandardProfilePackageImpl::get_StandardProfile_Process_base_Component()
{
	return standardProfile_Process_base_Component;
}
std::shared_ptr<uml::Stereotype> StandardProfilePackageImpl::get_StandardProfile_Realization()
{
	return standardProfile_Realization;
}
std::shared_ptr<uml::Property> StandardProfilePackageImpl::get_StandardProfile_Realization_base_Classifier()
{
	return standardProfile_Realization_base_Classifier;
}
std::shared_ptr<uml::Stereotype> StandardProfilePackageImpl::get_StandardProfile_Refine()
{
	return standardProfile_Refine;
}
std::shared_ptr<uml::Property> StandardProfilePackageImpl::get_StandardProfile_Refine_base_Abstraction()
{
	return standardProfile_Refine_base_Abstraction;
}
std::shared_ptr<uml::Stereotype> StandardProfilePackageImpl::get_StandardProfile_Responsibility()
{
	return standardProfile_Responsibility;
}
std::shared_ptr<uml::Property> StandardProfilePackageImpl::get_StandardProfile_Responsibility_base_Usage()
{
	return standardProfile_Responsibility_base_Usage;
}
std::shared_ptr<uml::Stereotype> StandardProfilePackageImpl::get_StandardProfile_Script()
{
	return standardProfile_Script;
}
std::shared_ptr<uml::Property> StandardProfilePackageImpl::get_StandardProfile_Script_base_Artifact()
{
	return standardProfile_Script_base_Artifact;
}
std::shared_ptr<uml::Stereotype> StandardProfilePackageImpl::get_StandardProfile_Send()
{
	return standardProfile_Send;
}
std::shared_ptr<uml::Property> StandardProfilePackageImpl::get_StandardProfile_Send_base_Usage()
{
	return standardProfile_Send_base_Usage;
}
std::shared_ptr<uml::Stereotype> StandardProfilePackageImpl::get_StandardProfile_Service()
{
	return standardProfile_Service;
}
std::shared_ptr<uml::Property> StandardProfilePackageImpl::get_StandardProfile_Service_base_Component()
{
	return standardProfile_Service_base_Component;
}
std::shared_ptr<uml::Stereotype> StandardProfilePackageImpl::get_StandardProfile_Source()
{
	return standardProfile_Source;
}
std::shared_ptr<uml::Property> StandardProfilePackageImpl::get_StandardProfile_Source_base_Artifact()
{
	return standardProfile_Source_base_Artifact;
}
std::shared_ptr<uml::Stereotype> StandardProfilePackageImpl::get_StandardProfile_Specification()
{
	return standardProfile_Specification;
}
std::shared_ptr<uml::Property> StandardProfilePackageImpl::get_StandardProfile_Specification_base_Classifier()
{
	return standardProfile_Specification_base_Classifier;
}
std::shared_ptr<uml::Stereotype> StandardProfilePackageImpl::get_StandardProfile_Subsystem()
{
	return standardProfile_Subsystem;
}
std::shared_ptr<uml::Property> StandardProfilePackageImpl::get_StandardProfile_Subsystem_base_Component()
{
	return standardProfile_Subsystem_base_Component;
}
std::shared_ptr<uml::Stereotype> StandardProfilePackageImpl::get_StandardProfile_SystemModel()
{
	return standardProfile_SystemModel;
}
std::shared_ptr<uml::Property> StandardProfilePackageImpl::get_StandardProfile_SystemModel_base_Model()
{
	return standardProfile_SystemModel_base_Model;
}
std::shared_ptr<uml::Stereotype> StandardProfilePackageImpl::get_StandardProfile_Trace()
{
	return standardProfile_Trace;
}
std::shared_ptr<uml::Property> StandardProfilePackageImpl::get_StandardProfile_Trace_base_Abstraction()
{
	return standardProfile_Trace_base_Abstraction;
}
std::shared_ptr<uml::Stereotype> StandardProfilePackageImpl::get_StandardProfile_Type()
{
	return standardProfile_Type;
}
std::shared_ptr<uml::Property> StandardProfilePackageImpl::get_StandardProfile_Type_base_Class()
{
	return standardProfile_Type_base_Class;
}
std::shared_ptr<uml::Extension> StandardProfilePackageImpl::get_StandardProfile_Usage_Call()
{
	return standardProfile_Usage_Call;
}
std::shared_ptr<uml::Extension> StandardProfilePackageImpl::get_StandardProfile_Usage_Create()
{
	return standardProfile_Usage_Create;
}
std::shared_ptr<uml::Extension> StandardProfilePackageImpl::get_StandardProfile_Usage_Instantiate()
{
	return standardProfile_Usage_Instantiate;
}
std::shared_ptr<uml::Extension> StandardProfilePackageImpl::get_StandardProfile_Usage_Responsibility()
{
	return standardProfile_Usage_Responsibility;
}
std::shared_ptr<uml::Extension> StandardProfilePackageImpl::get_StandardProfile_Usage_Send()
{
	return standardProfile_Usage_Send;
}
std::shared_ptr<uml::Stereotype> StandardProfilePackageImpl::get_StandardProfile_Utility()
{
	return standardProfile_Utility;
}
std::shared_ptr<uml::Property> StandardProfilePackageImpl::get_StandardProfile_Utility_base_Class()
{
	return standardProfile_Utility_base_Class;
}




