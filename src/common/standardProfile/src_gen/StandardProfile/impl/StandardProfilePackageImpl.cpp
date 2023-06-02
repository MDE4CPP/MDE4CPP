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

//Singleton implemenation
std::shared_ptr<StandardProfilePackage> StandardProfilePackage::eInstance()
{
	static std::shared_ptr<StandardProfilePackage> instance;
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(StandardProfilePackageImpl::create());
		std::dynamic_pointer_cast<StandardProfilePackageImpl>(instance)->init(instance);
	}	
	return instance;
}
//static initialization
const std::string StandardProfilePackage::eNAME ="StandardProfile";
const std::string StandardProfilePackage::eNS_URI ="http://www.omg.org/spec/UML/20161101/StandardProfile";
const std::string StandardProfilePackage::eNS_PREFIX ="";

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

	createPackageActivities(standardProfile, factory);
	createPackageAssociations(standardProfile, factory);
	createPackageClasses(standardProfile, factory);
	createPackageDataTypes(standardProfile, factory);
	createPackageDependencies(standardProfile, factory);
	createPackageEnumerationLiterals(standardProfile, factory);
	createPackageValueSpecifications(standardProfile, factory);
	createPackageInstanceSpecifications(standardProfile, factory);
	createPackageInterfaces(standardProfile, factory);
	createPackageInterfaceRealizations(standardProfile, factory);
	createPackagePrimitiveTypes(standardProfile, factory);
	createPackageStereotypes(standardProfile, factory);
}

void StandardProfilePackageImpl::createPackageActivities(std::shared_ptr<uml::Package> standardProfile, std::shared_ptr<uml::umlFactory> factory)
{
}


void StandardProfilePackageImpl::createPackageAssociations(std::shared_ptr<uml::Package> standardProfile, std::shared_ptr<uml::umlFactory> factory)
{
}

void StandardProfilePackageImpl::createPackageClasses(std::shared_ptr<uml::Package> standardProfile, std::shared_ptr<uml::umlFactory> factory)
{
	std::shared_ptr<uml::Constraint> con = nullptr;
	std::shared_ptr<uml::OpaqueExpression> oe = nullptr;


//-------------------------------------------
//Opaque Behaviors

}

void StandardProfilePackageImpl::createPackageDataTypes(std::shared_ptr<uml::Package> standardProfile, std::shared_ptr<uml::umlFactory> factory)
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
	standardProfile_Auxiliary = factory->createStereotype_as_ownedType_in_Package(standardProfile, AUXILIARY_STEREOTYPE);
	standardProfile_Auxiliary->setName("Auxiliary");
	standardProfile_Auxiliary->setIsAbstract(false);
	standardProfile_Auxiliary_base_Class = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Auxiliary);
	

	standardProfile_BuildComponent = factory->createStereotype_as_ownedType_in_Package(standardProfile, BUILDCOMPONENT_STEREOTYPE);
	standardProfile_BuildComponent->setName("BuildComponent");
	standardProfile_BuildComponent->setIsAbstract(false);
	standardProfile_BuildComponent_base_Component = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_BuildComponent);
	

	standardProfile_Call = factory->createStereotype_as_ownedType_in_Package(standardProfile, CALL_STEREOTYPE);
	standardProfile_Call->setName("Call");
	standardProfile_Call->setIsAbstract(false);
	standardProfile_Call_base_Usage = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Call);
	

	standardProfile_Create = factory->createStereotype_as_ownedType_in_Package(standardProfile, CREATE_STEREOTYPE);
	standardProfile_Create->setName("Create");
	standardProfile_Create->setIsAbstract(false);
	standardProfile_Create_base_BehavioralFeature = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Create);standardProfile_Create_base_Usage = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Create);
	

	standardProfile_Derive = factory->createStereotype_as_ownedType_in_Package(standardProfile, DERIVE_STEREOTYPE);
	standardProfile_Derive->setName("Derive");
	standardProfile_Derive->setIsAbstract(false);
	standardProfile_Derive_base_Abstraction = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Derive);
	

	standardProfile_Destroy = factory->createStereotype_as_ownedType_in_Package(standardProfile, DESTROY_STEREOTYPE);
	standardProfile_Destroy->setName("Destroy");
	standardProfile_Destroy->setIsAbstract(false);
	standardProfile_Destroy_base_BehavioralFeature = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Destroy);
	

	standardProfile_Document = factory->createStereotype_as_ownedType_in_Package(standardProfile, DOCUMENT_STEREOTYPE);
	standardProfile_Document->setName("Document");
	standardProfile_Document->setIsAbstract(false);
	standardProfile_Document_base_Artifact = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Document);
	

	standardProfile_Entity = factory->createStereotype_as_ownedType_in_Package(standardProfile, ENTITY_STEREOTYPE);
	standardProfile_Entity->setName("Entity");
	standardProfile_Entity->setIsAbstract(false);
	standardProfile_Entity_base_Component = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Entity);
	

	standardProfile_Executable = factory->createStereotype_as_ownedType_in_Package(standardProfile, EXECUTABLE_STEREOTYPE);
	standardProfile_Executable->setName("Executable");
	standardProfile_Executable->setIsAbstract(false);
	standardProfile_Executable_base_Artifact = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Executable);
	

	standardProfile_File = factory->createStereotype_as_ownedType_in_Package(standardProfile, FILE_STEREOTYPE);
	standardProfile_File->setName("File");
	standardProfile_File->setIsAbstract(false);
	standardProfile_File_base_Artifact = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_File);
	

	standardProfile_Focus = factory->createStereotype_as_ownedType_in_Package(standardProfile, FOCUS_STEREOTYPE);
	standardProfile_Focus->setName("Focus");
	standardProfile_Focus->setIsAbstract(false);
	standardProfile_Focus_base_Class = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Focus);
	

	standardProfile_Framework = factory->createStereotype_as_ownedType_in_Package(standardProfile, FRAMEWORK_STEREOTYPE);
	standardProfile_Framework->setName("Framework");
	standardProfile_Framework->setIsAbstract(false);
	standardProfile_Framework_base_Package = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Framework);
	

	standardProfile_Implement = factory->createStereotype_as_ownedType_in_Package(standardProfile, IMPLEMENT_STEREOTYPE);
	standardProfile_Implement->setName("Implement");
	standardProfile_Implement->setIsAbstract(false);
	standardProfile_Implement_base_Component = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Implement);
	

	standardProfile_ImplementationClass = factory->createStereotype_as_ownedType_in_Package(standardProfile, IMPLEMENTATIONCLASS_STEREOTYPE);
	standardProfile_ImplementationClass->setName("ImplementationClass");
	standardProfile_ImplementationClass->setIsAbstract(false);
	standardProfile_ImplementationClass_base_Class = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_ImplementationClass);
	

	standardProfile_Instantiate = factory->createStereotype_as_ownedType_in_Package(standardProfile, INSTANTIATE_STEREOTYPE);
	standardProfile_Instantiate->setName("Instantiate");
	standardProfile_Instantiate->setIsAbstract(false);
	standardProfile_Instantiate_base_Usage = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Instantiate);
	

	standardProfile_Library = factory->createStereotype_as_ownedType_in_Package(standardProfile, LIBRARY_STEREOTYPE);
	standardProfile_Library->setName("Library");
	standardProfile_Library->setIsAbstract(false);
	standardProfile_Library_base_Artifact = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Library);
	

	standardProfile_Metaclass = factory->createStereotype_as_ownedType_in_Package(standardProfile, METACLASS_STEREOTYPE);
	standardProfile_Metaclass->setName("Metaclass");
	standardProfile_Metaclass->setIsAbstract(false);
	standardProfile_Metaclass_base_Class = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Metaclass);
	

	standardProfile_Metamodel = factory->createStereotype_as_ownedType_in_Package(standardProfile, METAMODEL_STEREOTYPE);
	standardProfile_Metamodel->setName("Metamodel");
	standardProfile_Metamodel->setIsAbstract(false);
	standardProfile_Metamodel_base_Model = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Metamodel);
	

	standardProfile_ModelLibrary = factory->createStereotype_as_ownedType_in_Package(standardProfile, MODELLIBRARY_STEREOTYPE);
	standardProfile_ModelLibrary->setName("ModelLibrary");
	standardProfile_ModelLibrary->setIsAbstract(false);
	standardProfile_ModelLibrary_base_Package = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_ModelLibrary);
	

	standardProfile_Process = factory->createStereotype_as_ownedType_in_Package(standardProfile, PROCESS_STEREOTYPE);
	standardProfile_Process->setName("Process");
	standardProfile_Process->setIsAbstract(false);
	standardProfile_Process_base_Component = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Process);
	

	standardProfile_Realization = factory->createStereotype_as_ownedType_in_Package(standardProfile, REALIZATION_STEREOTYPE);
	standardProfile_Realization->setName("Realization");
	standardProfile_Realization->setIsAbstract(false);
	standardProfile_Realization_base_Classifier = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Realization);
	

	standardProfile_Refine = factory->createStereotype_as_ownedType_in_Package(standardProfile, REFINE_STEREOTYPE);
	standardProfile_Refine->setName("Refine");
	standardProfile_Refine->setIsAbstract(false);
	standardProfile_Refine_base_Abstraction = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Refine);
	

	standardProfile_Responsibility = factory->createStereotype_as_ownedType_in_Package(standardProfile, RESPONSIBILITY_STEREOTYPE);
	standardProfile_Responsibility->setName("Responsibility");
	standardProfile_Responsibility->setIsAbstract(false);
	standardProfile_Responsibility_base_Usage = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Responsibility);
	

	standardProfile_Script = factory->createStereotype_as_ownedType_in_Package(standardProfile, SCRIPT_STEREOTYPE);
	standardProfile_Script->setName("Script");
	standardProfile_Script->setIsAbstract(false);
	standardProfile_Script_base_Artifact = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Script);
	

	standardProfile_Send = factory->createStereotype_as_ownedType_in_Package(standardProfile, SEND_STEREOTYPE);
	standardProfile_Send->setName("Send");
	standardProfile_Send->setIsAbstract(false);
	standardProfile_Send_base_Usage = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Send);
	

	standardProfile_Service = factory->createStereotype_as_ownedType_in_Package(standardProfile, SERVICE_STEREOTYPE);
	standardProfile_Service->setName("Service");
	standardProfile_Service->setIsAbstract(false);
	standardProfile_Service_base_Component = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Service);
	

	standardProfile_Source = factory->createStereotype_as_ownedType_in_Package(standardProfile, SOURCE_STEREOTYPE);
	standardProfile_Source->setName("Source");
	standardProfile_Source->setIsAbstract(false);
	standardProfile_Source_base_Artifact = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Source);
	

	standardProfile_Specification = factory->createStereotype_as_ownedType_in_Package(standardProfile, SPECIFICATION_STEREOTYPE);
	standardProfile_Specification->setName("Specification");
	standardProfile_Specification->setIsAbstract(false);
	standardProfile_Specification_base_Classifier = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Specification);
	

	standardProfile_Subsystem = factory->createStereotype_as_ownedType_in_Package(standardProfile, SUBSYSTEM_STEREOTYPE);
	standardProfile_Subsystem->setName("Subsystem");
	standardProfile_Subsystem->setIsAbstract(false);
	standardProfile_Subsystem_base_Component = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Subsystem);
	

	standardProfile_SystemModel = factory->createStereotype_as_ownedType_in_Package(standardProfile, SYSTEMMODEL_STEREOTYPE);
	standardProfile_SystemModel->setName("SystemModel");
	standardProfile_SystemModel->setIsAbstract(false);
	standardProfile_SystemModel_base_Model = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_SystemModel);
	

	standardProfile_Trace = factory->createStereotype_as_ownedType_in_Package(standardProfile, TRACE_STEREOTYPE);
	standardProfile_Trace->setName("Trace");
	standardProfile_Trace->setIsAbstract(false);
	standardProfile_Trace_base_Abstraction = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Trace);
	

	standardProfile_Type = factory->createStereotype_as_ownedType_in_Package(standardProfile, TYPE_STEREOTYPE);
	standardProfile_Type->setName("Type");
	standardProfile_Type->setIsAbstract(false);
	standardProfile_Type_base_Class = factory->createProperty_as_ownedAttribute_in_Class(standardProfile_Type);
	

	standardProfile_Utility = factory->createStereotype_as_ownedType_in_Package(standardProfile, UTILITY_STEREOTYPE);
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
	initializePackageAssociations();
	initializePackageClasses();
	initializePackageDataTypes();
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


void StandardProfilePackageImpl::initializePackageAssociations()
{
}

void StandardProfilePackageImpl::initializePackageClasses()
{
	std::shared_ptr<uml::Generalization> gen = nullptr;


//-------------------------------------------
//Opaque Behaviors

}

void StandardProfilePackageImpl::initializePackageDataTypes()
{
	std::shared_ptr<uml::Generalization> gen = nullptr;

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
	
	standardProfile_Auxiliary_base_Class->_setID(AUXILIARY_PROPERTY_BASE_CLASS);
	
	

	standardProfile_BuildComponent_base_Component->setName("base_Component");
	standardProfile_BuildComponent_base_Component->setType(UML::UMLPackage::eInstance()->get_UML_Component());
	standardProfile_BuildComponent_base_Component->setLower(1);
	standardProfile_BuildComponent_base_Component->setUpper(1);
	standardProfile_BuildComponent_base_Component->setIsUnique(true);
	standardProfile_BuildComponent_base_Component->setAggregation(uml::AggregationKind::NONE);
	standardProfile_BuildComponent_base_Component->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_BuildComponent_base_Component->setAssociation(get_StandardProfile_Component_BuildComponent());
	
	standardProfile_BuildComponent_base_Component->_setID(BUILDCOMPONENT_PROPERTY_BASE_COMPONENT);
	
	

	standardProfile_Call_base_Usage->setName("base_Usage");
	standardProfile_Call_base_Usage->setType(UML::UMLPackage::eInstance()->get_UML_Usage());
	standardProfile_Call_base_Usage->setLower(1);
	standardProfile_Call_base_Usage->setUpper(1);
	standardProfile_Call_base_Usage->setIsUnique(true);
	standardProfile_Call_base_Usage->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Call_base_Usage->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Call_base_Usage->setAssociation(get_StandardProfile_Usage_Call());
	
	standardProfile_Call_base_Usage->_setID(CALL_PROPERTY_BASE_USAGE);
	
	

	standardProfile_Create_base_BehavioralFeature->setName("base_BehavioralFeature");
	standardProfile_Create_base_BehavioralFeature->setType(UML::UMLPackage::eInstance()->get_UML_BehavioralFeature());
	standardProfile_Create_base_BehavioralFeature->setLower(1);
	standardProfile_Create_base_BehavioralFeature->setUpper(1);
	standardProfile_Create_base_BehavioralFeature->setIsUnique(true);
	standardProfile_Create_base_BehavioralFeature->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Create_base_BehavioralFeature->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Create_base_BehavioralFeature->setAssociation(get_StandardProfile_BehavioralFeature_Create());
	
	standardProfile_Create_base_BehavioralFeature->_setID(CREATE_PROPERTY_BASE_BEHAVIORALFEATURE);
	standardProfile_Create_base_Usage->setName("base_Usage");
	standardProfile_Create_base_Usage->setType(UML::UMLPackage::eInstance()->get_UML_Usage());
	standardProfile_Create_base_Usage->setLower(1);
	standardProfile_Create_base_Usage->setUpper(1);
	standardProfile_Create_base_Usage->setIsUnique(true);
	standardProfile_Create_base_Usage->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Create_base_Usage->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Create_base_Usage->setAssociation(get_StandardProfile_Usage_Create());
	
	standardProfile_Create_base_Usage->_setID(CREATE_PROPERTY_BASE_USAGE);
	
	

	standardProfile_Derive_base_Abstraction->setName("base_Abstraction");
	standardProfile_Derive_base_Abstraction->setType(UML::UMLPackage::eInstance()->get_UML_Abstraction());
	standardProfile_Derive_base_Abstraction->setLower(1);
	standardProfile_Derive_base_Abstraction->setUpper(1);
	standardProfile_Derive_base_Abstraction->setIsUnique(true);
	standardProfile_Derive_base_Abstraction->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Derive_base_Abstraction->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Derive_base_Abstraction->setAssociation(get_StandardProfile_Abstraction_Derive());
	
	standardProfile_Derive_base_Abstraction->_setID(DERIVE_PROPERTY_BASE_ABSTRACTION);
	
	

	standardProfile_Destroy_base_BehavioralFeature->setName("base_BehavioralFeature");
	standardProfile_Destroy_base_BehavioralFeature->setType(UML::UMLPackage::eInstance()->get_UML_BehavioralFeature());
	standardProfile_Destroy_base_BehavioralFeature->setLower(1);
	standardProfile_Destroy_base_BehavioralFeature->setUpper(1);
	standardProfile_Destroy_base_BehavioralFeature->setIsUnique(true);
	standardProfile_Destroy_base_BehavioralFeature->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Destroy_base_BehavioralFeature->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Destroy_base_BehavioralFeature->setAssociation(get_StandardProfile_BehavioralFeature_Destroy());
	
	standardProfile_Destroy_base_BehavioralFeature->_setID(DESTROY_PROPERTY_BASE_BEHAVIORALFEATURE);
	
	

	standardProfile_Document_base_Artifact->setName("base_Artifact");
	standardProfile_Document_base_Artifact->setType(UML::UMLPackage::eInstance()->get_UML_Artifact());
	standardProfile_Document_base_Artifact->setLower(1);
	standardProfile_Document_base_Artifact->setUpper(1);
	standardProfile_Document_base_Artifact->setIsUnique(true);
	standardProfile_Document_base_Artifact->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Document_base_Artifact->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Document_base_Artifact->setAssociation(get_StandardProfile_Artifact_Document());
	
	standardProfile_Document_base_Artifact->_setID(DOCUMENT_PROPERTY_BASE_ARTIFACT);
	
	

	standardProfile_Entity_base_Component->setName("base_Component");
	standardProfile_Entity_base_Component->setType(UML::UMLPackage::eInstance()->get_UML_Component());
	standardProfile_Entity_base_Component->setLower(1);
	standardProfile_Entity_base_Component->setUpper(1);
	standardProfile_Entity_base_Component->setIsUnique(true);
	standardProfile_Entity_base_Component->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Entity_base_Component->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Entity_base_Component->setAssociation(get_StandardProfile_Component_Entity());
	
	standardProfile_Entity_base_Component->_setID(ENTITY_PROPERTY_BASE_COMPONENT);
	
	

	standardProfile_Executable_base_Artifact->setName("base_Artifact");
	standardProfile_Executable_base_Artifact->setType(UML::UMLPackage::eInstance()->get_UML_Artifact());
	standardProfile_Executable_base_Artifact->setLower(1);
	standardProfile_Executable_base_Artifact->setUpper(1);
	standardProfile_Executable_base_Artifact->setIsUnique(true);
	standardProfile_Executable_base_Artifact->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Executable_base_Artifact->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Executable_base_Artifact->setAssociation(get_StandardProfile_Artifact_Executable());
	
	standardProfile_Executable_base_Artifact->_setID(EXECUTABLE_PROPERTY_BASE_ARTIFACT);
	
	

	standardProfile_File_base_Artifact->setName("base_Artifact");
	standardProfile_File_base_Artifact->setType(UML::UMLPackage::eInstance()->get_UML_Artifact());
	standardProfile_File_base_Artifact->setLower(1);
	standardProfile_File_base_Artifact->setUpper(1);
	standardProfile_File_base_Artifact->setIsUnique(true);
	standardProfile_File_base_Artifact->setAggregation(uml::AggregationKind::NONE);
	standardProfile_File_base_Artifact->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_File_base_Artifact->setAssociation(get_StandardProfile_Artifact_File());
	
	standardProfile_File_base_Artifact->_setID(FILE_PROPERTY_BASE_ARTIFACT);
	
	

	standardProfile_Focus_base_Class->setName("base_Class");
	standardProfile_Focus_base_Class->setType(UML::UMLPackage::eInstance()->get_UML_Class());
	standardProfile_Focus_base_Class->setLower(1);
	standardProfile_Focus_base_Class->setUpper(1);
	standardProfile_Focus_base_Class->setIsUnique(true);
	standardProfile_Focus_base_Class->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Focus_base_Class->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Focus_base_Class->setAssociation(get_StandardProfile_Class_Focus());
	
	standardProfile_Focus_base_Class->_setID(FOCUS_PROPERTY_BASE_CLASS);
	
	

	standardProfile_Framework_base_Package->setName("base_Package");
	standardProfile_Framework_base_Package->setType(UML::UMLPackage::eInstance()->get_UML_Package());
	standardProfile_Framework_base_Package->setLower(1);
	standardProfile_Framework_base_Package->setUpper(1);
	standardProfile_Framework_base_Package->setIsUnique(true);
	standardProfile_Framework_base_Package->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Framework_base_Package->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Framework_base_Package->setAssociation(get_StandardProfile_Package_Framework());
	
	standardProfile_Framework_base_Package->_setID(FRAMEWORK_PROPERTY_BASE_PACKAGE);
	
	

	standardProfile_Implement_base_Component->setName("base_Component");
	standardProfile_Implement_base_Component->setType(UML::UMLPackage::eInstance()->get_UML_Component());
	standardProfile_Implement_base_Component->setLower(1);
	standardProfile_Implement_base_Component->setUpper(1);
	standardProfile_Implement_base_Component->setIsUnique(true);
	standardProfile_Implement_base_Component->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Implement_base_Component->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Implement_base_Component->setAssociation(get_StandardProfile_Component_Implement());
	
	standardProfile_Implement_base_Component->_setID(IMPLEMENT_PROPERTY_BASE_COMPONENT);
	
	

	standardProfile_ImplementationClass_base_Class->setName("base_Class");
	standardProfile_ImplementationClass_base_Class->setType(UML::UMLPackage::eInstance()->get_UML_Class());
	standardProfile_ImplementationClass_base_Class->setLower(1);
	standardProfile_ImplementationClass_base_Class->setUpper(1);
	standardProfile_ImplementationClass_base_Class->setIsUnique(true);
	standardProfile_ImplementationClass_base_Class->setAggregation(uml::AggregationKind::NONE);
	standardProfile_ImplementationClass_base_Class->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_ImplementationClass_base_Class->setAssociation(get_StandardProfile_Class_ImplementationClass());
	
	standardProfile_ImplementationClass_base_Class->_setID(IMPLEMENTATIONCLASS_PROPERTY_BASE_CLASS);
	
	

	standardProfile_Instantiate_base_Usage->setName("base_Usage");
	standardProfile_Instantiate_base_Usage->setType(UML::UMLPackage::eInstance()->get_UML_Usage());
	standardProfile_Instantiate_base_Usage->setLower(1);
	standardProfile_Instantiate_base_Usage->setUpper(1);
	standardProfile_Instantiate_base_Usage->setIsUnique(true);
	standardProfile_Instantiate_base_Usage->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Instantiate_base_Usage->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Instantiate_base_Usage->setAssociation(get_StandardProfile_Usage_Instantiate());
	
	standardProfile_Instantiate_base_Usage->_setID(INSTANTIATE_PROPERTY_BASE_USAGE);
	
	

	standardProfile_Library_base_Artifact->setName("base_Artifact");
	standardProfile_Library_base_Artifact->setType(UML::UMLPackage::eInstance()->get_UML_Artifact());
	standardProfile_Library_base_Artifact->setLower(1);
	standardProfile_Library_base_Artifact->setUpper(1);
	standardProfile_Library_base_Artifact->setIsUnique(true);
	standardProfile_Library_base_Artifact->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Library_base_Artifact->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Library_base_Artifact->setAssociation(get_StandardProfile_Artifact_Library());
	
	standardProfile_Library_base_Artifact->_setID(LIBRARY_PROPERTY_BASE_ARTIFACT);
	
	

	standardProfile_Metaclass_base_Class->setName("base_Class");
	standardProfile_Metaclass_base_Class->setType(UML::UMLPackage::eInstance()->get_UML_Class());
	standardProfile_Metaclass_base_Class->setLower(1);
	standardProfile_Metaclass_base_Class->setUpper(1);
	standardProfile_Metaclass_base_Class->setIsUnique(true);
	standardProfile_Metaclass_base_Class->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Metaclass_base_Class->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Metaclass_base_Class->setAssociation(get_StandardProfile_Class_Metaclass());
	
	standardProfile_Metaclass_base_Class->_setID(METACLASS_PROPERTY_BASE_CLASS);
	
	

	standardProfile_Metamodel_base_Model->setName("base_Model");
	standardProfile_Metamodel_base_Model->setType(UML::UMLPackage::eInstance()->get_UML_Model());
	standardProfile_Metamodel_base_Model->setLower(1);
	standardProfile_Metamodel_base_Model->setUpper(1);
	standardProfile_Metamodel_base_Model->setIsUnique(true);
	standardProfile_Metamodel_base_Model->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Metamodel_base_Model->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Metamodel_base_Model->setAssociation(get_StandardProfile_Model_Metamodel());
	
	standardProfile_Metamodel_base_Model->_setID(METAMODEL_PROPERTY_BASE_MODEL);
	
	

	standardProfile_ModelLibrary_base_Package->setName("base_Package");
	standardProfile_ModelLibrary_base_Package->setType(UML::UMLPackage::eInstance()->get_UML_Package());
	standardProfile_ModelLibrary_base_Package->setLower(1);
	standardProfile_ModelLibrary_base_Package->setUpper(1);
	standardProfile_ModelLibrary_base_Package->setIsUnique(true);
	standardProfile_ModelLibrary_base_Package->setAggregation(uml::AggregationKind::NONE);
	standardProfile_ModelLibrary_base_Package->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_ModelLibrary_base_Package->setAssociation(get_StandardProfile_Package_ModelLibrary());
	
	standardProfile_ModelLibrary_base_Package->_setID(MODELLIBRARY_PROPERTY_BASE_PACKAGE);
	
	

	standardProfile_Process_base_Component->setName("base_Component");
	standardProfile_Process_base_Component->setType(UML::UMLPackage::eInstance()->get_UML_Component());
	standardProfile_Process_base_Component->setLower(1);
	standardProfile_Process_base_Component->setUpper(1);
	standardProfile_Process_base_Component->setIsUnique(true);
	standardProfile_Process_base_Component->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Process_base_Component->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Process_base_Component->setAssociation(get_StandardProfile_Component_Process());
	
	standardProfile_Process_base_Component->_setID(PROCESS_PROPERTY_BASE_COMPONENT);
	
	

	standardProfile_Realization_base_Classifier->setName("base_Classifier");
	standardProfile_Realization_base_Classifier->setType(UML::UMLPackage::eInstance()->get_UML_Classifier());
	standardProfile_Realization_base_Classifier->setLower(1);
	standardProfile_Realization_base_Classifier->setUpper(1);
	standardProfile_Realization_base_Classifier->setIsUnique(true);
	standardProfile_Realization_base_Classifier->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Realization_base_Classifier->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Realization_base_Classifier->setAssociation(get_StandardProfile_Classifier_Realization());
	
	standardProfile_Realization_base_Classifier->_setID(REALIZATION_PROPERTY_BASE_CLASSIFIER);
	
	

	standardProfile_Refine_base_Abstraction->setName("base_Abstraction");
	standardProfile_Refine_base_Abstraction->setType(UML::UMLPackage::eInstance()->get_UML_Abstraction());
	standardProfile_Refine_base_Abstraction->setLower(1);
	standardProfile_Refine_base_Abstraction->setUpper(1);
	standardProfile_Refine_base_Abstraction->setIsUnique(true);
	standardProfile_Refine_base_Abstraction->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Refine_base_Abstraction->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Refine_base_Abstraction->setAssociation(get_StandardProfile_Abstraction_Refine());
	
	standardProfile_Refine_base_Abstraction->_setID(REFINE_PROPERTY_BASE_ABSTRACTION);
	
	

	standardProfile_Responsibility_base_Usage->setName("base_Usage");
	standardProfile_Responsibility_base_Usage->setType(UML::UMLPackage::eInstance()->get_UML_Usage());
	standardProfile_Responsibility_base_Usage->setLower(1);
	standardProfile_Responsibility_base_Usage->setUpper(1);
	standardProfile_Responsibility_base_Usage->setIsUnique(true);
	standardProfile_Responsibility_base_Usage->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Responsibility_base_Usage->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Responsibility_base_Usage->setAssociation(get_StandardProfile_Usage_Responsibility());
	
	standardProfile_Responsibility_base_Usage->_setID(RESPONSIBILITY_PROPERTY_BASE_USAGE);
	
	

	standardProfile_Script_base_Artifact->setName("base_Artifact");
	standardProfile_Script_base_Artifact->setType(UML::UMLPackage::eInstance()->get_UML_Artifact());
	standardProfile_Script_base_Artifact->setLower(1);
	standardProfile_Script_base_Artifact->setUpper(1);
	standardProfile_Script_base_Artifact->setIsUnique(true);
	standardProfile_Script_base_Artifact->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Script_base_Artifact->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Script_base_Artifact->setAssociation(get_StandardProfile_Artifact_Script());
	
	standardProfile_Script_base_Artifact->_setID(SCRIPT_PROPERTY_BASE_ARTIFACT);
	
	

	standardProfile_Send_base_Usage->setName("base_Usage");
	standardProfile_Send_base_Usage->setType(UML::UMLPackage::eInstance()->get_UML_Usage());
	standardProfile_Send_base_Usage->setLower(1);
	standardProfile_Send_base_Usage->setUpper(1);
	standardProfile_Send_base_Usage->setIsUnique(true);
	standardProfile_Send_base_Usage->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Send_base_Usage->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Send_base_Usage->setAssociation(get_StandardProfile_Usage_Send());
	
	standardProfile_Send_base_Usage->_setID(SEND_PROPERTY_BASE_USAGE);
	
	

	standardProfile_Service_base_Component->setName("base_Component");
	standardProfile_Service_base_Component->setType(UML::UMLPackage::eInstance()->get_UML_Component());
	standardProfile_Service_base_Component->setLower(1);
	standardProfile_Service_base_Component->setUpper(1);
	standardProfile_Service_base_Component->setIsUnique(true);
	standardProfile_Service_base_Component->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Service_base_Component->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Service_base_Component->setAssociation(get_StandardProfile_Component_Service());
	
	standardProfile_Service_base_Component->_setID(SERVICE_PROPERTY_BASE_COMPONENT);
	
	

	standardProfile_Source_base_Artifact->setName("base_Artifact");
	standardProfile_Source_base_Artifact->setType(UML::UMLPackage::eInstance()->get_UML_Artifact());
	standardProfile_Source_base_Artifact->setLower(1);
	standardProfile_Source_base_Artifact->setUpper(1);
	standardProfile_Source_base_Artifact->setIsUnique(true);
	standardProfile_Source_base_Artifact->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Source_base_Artifact->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Source_base_Artifact->setAssociation(get_StandardProfile_Artifact_Source());
	
	standardProfile_Source_base_Artifact->_setID(SOURCE_PROPERTY_BASE_ARTIFACT);
	
	

	standardProfile_Specification_base_Classifier->setName("base_Classifier");
	standardProfile_Specification_base_Classifier->setType(UML::UMLPackage::eInstance()->get_UML_Classifier());
	standardProfile_Specification_base_Classifier->setLower(1);
	standardProfile_Specification_base_Classifier->setUpper(1);
	standardProfile_Specification_base_Classifier->setIsUnique(true);
	standardProfile_Specification_base_Classifier->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Specification_base_Classifier->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Specification_base_Classifier->setAssociation(get_StandardProfile_Classifier_Specification());
	
	standardProfile_Specification_base_Classifier->_setID(SPECIFICATION_PROPERTY_BASE_CLASSIFIER);
	
	

	standardProfile_Subsystem_base_Component->setName("base_Component");
	standardProfile_Subsystem_base_Component->setType(UML::UMLPackage::eInstance()->get_UML_Component());
	standardProfile_Subsystem_base_Component->setLower(1);
	standardProfile_Subsystem_base_Component->setUpper(1);
	standardProfile_Subsystem_base_Component->setIsUnique(true);
	standardProfile_Subsystem_base_Component->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Subsystem_base_Component->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Subsystem_base_Component->setAssociation(get_StandardProfile_Component_Subsystem());
	
	standardProfile_Subsystem_base_Component->_setID(SUBSYSTEM_PROPERTY_BASE_COMPONENT);
	
	

	standardProfile_SystemModel_base_Model->setName("base_Model");
	standardProfile_SystemModel_base_Model->setType(UML::UMLPackage::eInstance()->get_UML_Model());
	standardProfile_SystemModel_base_Model->setLower(1);
	standardProfile_SystemModel_base_Model->setUpper(1);
	standardProfile_SystemModel_base_Model->setIsUnique(true);
	standardProfile_SystemModel_base_Model->setAggregation(uml::AggregationKind::NONE);
	standardProfile_SystemModel_base_Model->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_SystemModel_base_Model->setAssociation(get_StandardProfile_Model_SystemModel());
	
	standardProfile_SystemModel_base_Model->_setID(SYSTEMMODEL_PROPERTY_BASE_MODEL);
	
	

	standardProfile_Trace_base_Abstraction->setName("base_Abstraction");
	standardProfile_Trace_base_Abstraction->setType(UML::UMLPackage::eInstance()->get_UML_Abstraction());
	standardProfile_Trace_base_Abstraction->setLower(1);
	standardProfile_Trace_base_Abstraction->setUpper(1);
	standardProfile_Trace_base_Abstraction->setIsUnique(true);
	standardProfile_Trace_base_Abstraction->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Trace_base_Abstraction->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Trace_base_Abstraction->setAssociation(get_StandardProfile_Abstraction_Trace());
	
	standardProfile_Trace_base_Abstraction->_setID(TRACE_PROPERTY_BASE_ABSTRACTION);
	
	

	standardProfile_Type_base_Class->setName("base_Class");
	standardProfile_Type_base_Class->setType(UML::UMLPackage::eInstance()->get_UML_Class());
	standardProfile_Type_base_Class->setLower(1);
	standardProfile_Type_base_Class->setUpper(1);
	standardProfile_Type_base_Class->setIsUnique(true);
	standardProfile_Type_base_Class->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Type_base_Class->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Type_base_Class->setAssociation(get_StandardProfile_Class_Type());
	
	standardProfile_Type_base_Class->_setID(TYPE_PROPERTY_BASE_CLASS);
	
	

	standardProfile_Utility_base_Class->setName("base_Class");
	standardProfile_Utility_base_Class->setType(UML::UMLPackage::eInstance()->get_UML_Class());
	standardProfile_Utility_base_Class->setLower(1);
	standardProfile_Utility_base_Class->setUpper(1);
	standardProfile_Utility_base_Class->setIsUnique(true);
	standardProfile_Utility_base_Class->setAggregation(uml::AggregationKind::NONE);
	standardProfile_Utility_base_Class->setVisibility(uml::VisibilityKind::PUBLIC);
	standardProfile_Utility_base_Class->setAssociation(get_StandardProfile_Class_Utility());
	
	standardProfile_Utility_base_Class->_setID(UTILITY_PROPERTY_BASE_CLASS);
	
	
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

const std::shared_ptr<uml::ExtensionEnd>& StandardProfilePackageImpl::get_ExtensionEnd_extension_Auxiliary_StandardProfile_Auxiliary()
{
	return extensionEnd_extension_Auxiliary_StandardProfile_Auxiliary;
}
const std::shared_ptr<uml::ExtensionEnd>& StandardProfilePackageImpl::get_ExtensionEnd_extension_BehavioralFeature_Create_StandardProfile_Create()
{
	return extensionEnd_extension_BehavioralFeature_Create_StandardProfile_Create;
}
const std::shared_ptr<uml::ExtensionEnd>& StandardProfilePackageImpl::get_ExtensionEnd_extension_BuildComponent_StandardProfile_BuildComponent()
{
	return extensionEnd_extension_BuildComponent_StandardProfile_BuildComponent;
}
const std::shared_ptr<uml::ExtensionEnd>& StandardProfilePackageImpl::get_ExtensionEnd_extension_Call_StandardProfile_Call()
{
	return extensionEnd_extension_Call_StandardProfile_Call;
}
const std::shared_ptr<uml::ExtensionEnd>& StandardProfilePackageImpl::get_ExtensionEnd_extension_Derive_StandardProfile_Derive()
{
	return extensionEnd_extension_Derive_StandardProfile_Derive;
}
const std::shared_ptr<uml::ExtensionEnd>& StandardProfilePackageImpl::get_ExtensionEnd_extension_Destroy_StandardProfile_Destroy()
{
	return extensionEnd_extension_Destroy_StandardProfile_Destroy;
}
const std::shared_ptr<uml::ExtensionEnd>& StandardProfilePackageImpl::get_ExtensionEnd_extension_Document_StandardProfile_Document()
{
	return extensionEnd_extension_Document_StandardProfile_Document;
}
const std::shared_ptr<uml::ExtensionEnd>& StandardProfilePackageImpl::get_ExtensionEnd_extension_Entity_StandardProfile_Entity()
{
	return extensionEnd_extension_Entity_StandardProfile_Entity;
}
const std::shared_ptr<uml::ExtensionEnd>& StandardProfilePackageImpl::get_ExtensionEnd_extension_Executable_StandardProfile_Executable()
{
	return extensionEnd_extension_Executable_StandardProfile_Executable;
}
const std::shared_ptr<uml::ExtensionEnd>& StandardProfilePackageImpl::get_ExtensionEnd_extension_File_StandardProfile_File()
{
	return extensionEnd_extension_File_StandardProfile_File;
}
const std::shared_ptr<uml::ExtensionEnd>& StandardProfilePackageImpl::get_ExtensionEnd_extension_Focus_StandardProfile_Focus()
{
	return extensionEnd_extension_Focus_StandardProfile_Focus;
}
const std::shared_ptr<uml::ExtensionEnd>& StandardProfilePackageImpl::get_ExtensionEnd_extension_Framework_StandardProfile_Framework()
{
	return extensionEnd_extension_Framework_StandardProfile_Framework;
}
const std::shared_ptr<uml::ExtensionEnd>& StandardProfilePackageImpl::get_ExtensionEnd_extension_Implement_StandardProfile_Implement()
{
	return extensionEnd_extension_Implement_StandardProfile_Implement;
}
const std::shared_ptr<uml::ExtensionEnd>& StandardProfilePackageImpl::get_ExtensionEnd_extension_ImplementationClass_StandardProfile_ImplementationClass()
{
	return extensionEnd_extension_ImplementationClass_StandardProfile_ImplementationClass;
}
const std::shared_ptr<uml::ExtensionEnd>& StandardProfilePackageImpl::get_ExtensionEnd_extension_Instantiate_StandardProfile_Instantiate()
{
	return extensionEnd_extension_Instantiate_StandardProfile_Instantiate;
}
const std::shared_ptr<uml::ExtensionEnd>& StandardProfilePackageImpl::get_ExtensionEnd_extension_Library_StandardProfile_Library()
{
	return extensionEnd_extension_Library_StandardProfile_Library;
}
const std::shared_ptr<uml::ExtensionEnd>& StandardProfilePackageImpl::get_ExtensionEnd_extension_Metaclass_StandardProfile_Metaclass()
{
	return extensionEnd_extension_Metaclass_StandardProfile_Metaclass;
}
const std::shared_ptr<uml::ExtensionEnd>& StandardProfilePackageImpl::get_ExtensionEnd_extension_Metamodel_StandardProfile_Metamodel()
{
	return extensionEnd_extension_Metamodel_StandardProfile_Metamodel;
}
const std::shared_ptr<uml::ExtensionEnd>& StandardProfilePackageImpl::get_ExtensionEnd_extension_ModelLibrary_StandardProfile_ModelLibrary()
{
	return extensionEnd_extension_ModelLibrary_StandardProfile_ModelLibrary;
}
const std::shared_ptr<uml::ExtensionEnd>& StandardProfilePackageImpl::get_ExtensionEnd_extension_Process_StandardProfile_Process()
{
	return extensionEnd_extension_Process_StandardProfile_Process;
}
const std::shared_ptr<uml::ExtensionEnd>& StandardProfilePackageImpl::get_ExtensionEnd_extension_Realization_StandardProfile_Realization()
{
	return extensionEnd_extension_Realization_StandardProfile_Realization;
}
const std::shared_ptr<uml::ExtensionEnd>& StandardProfilePackageImpl::get_ExtensionEnd_extension_Refine_StandardProfile_Refine()
{
	return extensionEnd_extension_Refine_StandardProfile_Refine;
}
const std::shared_ptr<uml::ExtensionEnd>& StandardProfilePackageImpl::get_ExtensionEnd_extension_Responsibility_StandardProfile_Responsibility()
{
	return extensionEnd_extension_Responsibility_StandardProfile_Responsibility;
}
const std::shared_ptr<uml::ExtensionEnd>& StandardProfilePackageImpl::get_ExtensionEnd_extension_Script_StandardProfile_Script()
{
	return extensionEnd_extension_Script_StandardProfile_Script;
}
const std::shared_ptr<uml::ExtensionEnd>& StandardProfilePackageImpl::get_ExtensionEnd_extension_Send_StandardProfile_Send()
{
	return extensionEnd_extension_Send_StandardProfile_Send;
}
const std::shared_ptr<uml::ExtensionEnd>& StandardProfilePackageImpl::get_ExtensionEnd_extension_Service_StandardProfile_Service()
{
	return extensionEnd_extension_Service_StandardProfile_Service;
}
const std::shared_ptr<uml::ExtensionEnd>& StandardProfilePackageImpl::get_ExtensionEnd_extension_Source_StandardProfile_Source()
{
	return extensionEnd_extension_Source_StandardProfile_Source;
}
const std::shared_ptr<uml::ExtensionEnd>& StandardProfilePackageImpl::get_ExtensionEnd_extension_Specification_StandardProfile_Specification()
{
	return extensionEnd_extension_Specification_StandardProfile_Specification;
}
const std::shared_ptr<uml::ExtensionEnd>& StandardProfilePackageImpl::get_ExtensionEnd_extension_Subsystem_StandardProfile_Subsystem()
{
	return extensionEnd_extension_Subsystem_StandardProfile_Subsystem;
}
const std::shared_ptr<uml::ExtensionEnd>& StandardProfilePackageImpl::get_ExtensionEnd_extension_SystemModel_StandardProfile_SystemModel()
{
	return extensionEnd_extension_SystemModel_StandardProfile_SystemModel;
}
const std::shared_ptr<uml::ExtensionEnd>& StandardProfilePackageImpl::get_ExtensionEnd_extension_Trace_StandardProfile_Trace()
{
	return extensionEnd_extension_Trace_StandardProfile_Trace;
}
const std::shared_ptr<uml::ExtensionEnd>& StandardProfilePackageImpl::get_ExtensionEnd_extension_Type_StandardProfile_Type()
{
	return extensionEnd_extension_Type_StandardProfile_Type;
}
const std::shared_ptr<uml::ExtensionEnd>& StandardProfilePackageImpl::get_ExtensionEnd_extension_Usage_Create_StandardProfile_Create()
{
	return extensionEnd_extension_Usage_Create_StandardProfile_Create;
}
const std::shared_ptr<uml::ExtensionEnd>& StandardProfilePackageImpl::get_ExtensionEnd_extension_Utility_StandardProfile_Utility()
{
	return extensionEnd_extension_Utility_StandardProfile_Utility;
}
const std::shared_ptr<uml::Extension>& StandardProfilePackageImpl::get_StandardProfile_Abstraction_Derive()
{
	return standardProfile_Abstraction_Derive;
}
const std::shared_ptr<uml::Extension>& StandardProfilePackageImpl::get_StandardProfile_Abstraction_Refine()
{
	return standardProfile_Abstraction_Refine;
}
const std::shared_ptr<uml::Extension>& StandardProfilePackageImpl::get_StandardProfile_Abstraction_Trace()
{
	return standardProfile_Abstraction_Trace;
}
const std::shared_ptr<uml::Extension>& StandardProfilePackageImpl::get_StandardProfile_Artifact_Document()
{
	return standardProfile_Artifact_Document;
}
const std::shared_ptr<uml::Extension>& StandardProfilePackageImpl::get_StandardProfile_Artifact_Executable()
{
	return standardProfile_Artifact_Executable;
}
const std::shared_ptr<uml::Extension>& StandardProfilePackageImpl::get_StandardProfile_Artifact_File()
{
	return standardProfile_Artifact_File;
}
const std::shared_ptr<uml::Extension>& StandardProfilePackageImpl::get_StandardProfile_Artifact_Library()
{
	return standardProfile_Artifact_Library;
}
const std::shared_ptr<uml::Extension>& StandardProfilePackageImpl::get_StandardProfile_Artifact_Script()
{
	return standardProfile_Artifact_Script;
}
const std::shared_ptr<uml::Extension>& StandardProfilePackageImpl::get_StandardProfile_Artifact_Source()
{
	return standardProfile_Artifact_Source;
}
const std::shared_ptr<uml::Stereotype>& StandardProfilePackageImpl::get_StandardProfile_Auxiliary()
{
	return standardProfile_Auxiliary;
}
const std::shared_ptr<uml::Property>& StandardProfilePackageImpl::get_StandardProfile_Auxiliary_base_Class()
{
	return standardProfile_Auxiliary_base_Class;
}
const std::shared_ptr<uml::Extension>& StandardProfilePackageImpl::get_StandardProfile_BehavioralFeature_Create()
{
	return standardProfile_BehavioralFeature_Create;
}
const std::shared_ptr<uml::Extension>& StandardProfilePackageImpl::get_StandardProfile_BehavioralFeature_Destroy()
{
	return standardProfile_BehavioralFeature_Destroy;
}
const std::shared_ptr<uml::Stereotype>& StandardProfilePackageImpl::get_StandardProfile_BuildComponent()
{
	return standardProfile_BuildComponent;
}
const std::shared_ptr<uml::Property>& StandardProfilePackageImpl::get_StandardProfile_BuildComponent_base_Component()
{
	return standardProfile_BuildComponent_base_Component;
}
const std::shared_ptr<uml::Stereotype>& StandardProfilePackageImpl::get_StandardProfile_Call()
{
	return standardProfile_Call;
}
const std::shared_ptr<uml::Property>& StandardProfilePackageImpl::get_StandardProfile_Call_base_Usage()
{
	return standardProfile_Call_base_Usage;
}
const std::shared_ptr<uml::Extension>& StandardProfilePackageImpl::get_StandardProfile_Class_Auxiliary()
{
	return standardProfile_Class_Auxiliary;
}
const std::shared_ptr<uml::Extension>& StandardProfilePackageImpl::get_StandardProfile_Class_Focus()
{
	return standardProfile_Class_Focus;
}
const std::shared_ptr<uml::Extension>& StandardProfilePackageImpl::get_StandardProfile_Class_ImplementationClass()
{
	return standardProfile_Class_ImplementationClass;
}
const std::shared_ptr<uml::Extension>& StandardProfilePackageImpl::get_StandardProfile_Class_Metaclass()
{
	return standardProfile_Class_Metaclass;
}
const std::shared_ptr<uml::Extension>& StandardProfilePackageImpl::get_StandardProfile_Class_Type()
{
	return standardProfile_Class_Type;
}
const std::shared_ptr<uml::Extension>& StandardProfilePackageImpl::get_StandardProfile_Class_Utility()
{
	return standardProfile_Class_Utility;
}
const std::shared_ptr<uml::Extension>& StandardProfilePackageImpl::get_StandardProfile_Classifier_Realization()
{
	return standardProfile_Classifier_Realization;
}
const std::shared_ptr<uml::Extension>& StandardProfilePackageImpl::get_StandardProfile_Classifier_Specification()
{
	return standardProfile_Classifier_Specification;
}
const std::shared_ptr<uml::Extension>& StandardProfilePackageImpl::get_StandardProfile_Component_BuildComponent()
{
	return standardProfile_Component_BuildComponent;
}
const std::shared_ptr<uml::Extension>& StandardProfilePackageImpl::get_StandardProfile_Component_Entity()
{
	return standardProfile_Component_Entity;
}
const std::shared_ptr<uml::Extension>& StandardProfilePackageImpl::get_StandardProfile_Component_Implement()
{
	return standardProfile_Component_Implement;
}
const std::shared_ptr<uml::Extension>& StandardProfilePackageImpl::get_StandardProfile_Component_Process()
{
	return standardProfile_Component_Process;
}
const std::shared_ptr<uml::Extension>& StandardProfilePackageImpl::get_StandardProfile_Component_Service()
{
	return standardProfile_Component_Service;
}
const std::shared_ptr<uml::Extension>& StandardProfilePackageImpl::get_StandardProfile_Component_Subsystem()
{
	return standardProfile_Component_Subsystem;
}
const std::shared_ptr<uml::Stereotype>& StandardProfilePackageImpl::get_StandardProfile_Create()
{
	return standardProfile_Create;
}
const std::shared_ptr<uml::Property>& StandardProfilePackageImpl::get_StandardProfile_Create_base_BehavioralFeature()
{
	return standardProfile_Create_base_BehavioralFeature;
}
const std::shared_ptr<uml::Property>& StandardProfilePackageImpl::get_StandardProfile_Create_base_Usage()
{
	return standardProfile_Create_base_Usage;
}
const std::shared_ptr<uml::Stereotype>& StandardProfilePackageImpl::get_StandardProfile_Derive()
{
	return standardProfile_Derive;
}
const std::shared_ptr<uml::Property>& StandardProfilePackageImpl::get_StandardProfile_Derive_base_Abstraction()
{
	return standardProfile_Derive_base_Abstraction;
}
const std::shared_ptr<uml::Stereotype>& StandardProfilePackageImpl::get_StandardProfile_Destroy()
{
	return standardProfile_Destroy;
}
const std::shared_ptr<uml::Property>& StandardProfilePackageImpl::get_StandardProfile_Destroy_base_BehavioralFeature()
{
	return standardProfile_Destroy_base_BehavioralFeature;
}
const std::shared_ptr<uml::Stereotype>& StandardProfilePackageImpl::get_StandardProfile_Document()
{
	return standardProfile_Document;
}
const std::shared_ptr<uml::Property>& StandardProfilePackageImpl::get_StandardProfile_Document_base_Artifact()
{
	return standardProfile_Document_base_Artifact;
}
const std::shared_ptr<uml::Stereotype>& StandardProfilePackageImpl::get_StandardProfile_Entity()
{
	return standardProfile_Entity;
}
const std::shared_ptr<uml::Property>& StandardProfilePackageImpl::get_StandardProfile_Entity_base_Component()
{
	return standardProfile_Entity_base_Component;
}
const std::shared_ptr<uml::Stereotype>& StandardProfilePackageImpl::get_StandardProfile_Executable()
{
	return standardProfile_Executable;
}
const std::shared_ptr<uml::Property>& StandardProfilePackageImpl::get_StandardProfile_Executable_base_Artifact()
{
	return standardProfile_Executable_base_Artifact;
}
const std::shared_ptr<uml::Stereotype>& StandardProfilePackageImpl::get_StandardProfile_File()
{
	return standardProfile_File;
}
const std::shared_ptr<uml::Property>& StandardProfilePackageImpl::get_StandardProfile_File_base_Artifact()
{
	return standardProfile_File_base_Artifact;
}
const std::shared_ptr<uml::Stereotype>& StandardProfilePackageImpl::get_StandardProfile_Focus()
{
	return standardProfile_Focus;
}
const std::shared_ptr<uml::Property>& StandardProfilePackageImpl::get_StandardProfile_Focus_base_Class()
{
	return standardProfile_Focus_base_Class;
}
const std::shared_ptr<uml::Stereotype>& StandardProfilePackageImpl::get_StandardProfile_Framework()
{
	return standardProfile_Framework;
}
const std::shared_ptr<uml::Property>& StandardProfilePackageImpl::get_StandardProfile_Framework_base_Package()
{
	return standardProfile_Framework_base_Package;
}
const std::shared_ptr<uml::Stereotype>& StandardProfilePackageImpl::get_StandardProfile_Implement()
{
	return standardProfile_Implement;
}
const std::shared_ptr<uml::Property>& StandardProfilePackageImpl::get_StandardProfile_Implement_base_Component()
{
	return standardProfile_Implement_base_Component;
}
const std::shared_ptr<uml::Stereotype>& StandardProfilePackageImpl::get_StandardProfile_ImplementationClass()
{
	return standardProfile_ImplementationClass;
}
const std::shared_ptr<uml::Property>& StandardProfilePackageImpl::get_StandardProfile_ImplementationClass_base_Class()
{
	return standardProfile_ImplementationClass_base_Class;
}
const std::shared_ptr<uml::Stereotype>& StandardProfilePackageImpl::get_StandardProfile_Instantiate()
{
	return standardProfile_Instantiate;
}
const std::shared_ptr<uml::Property>& StandardProfilePackageImpl::get_StandardProfile_Instantiate_base_Usage()
{
	return standardProfile_Instantiate_base_Usage;
}
const std::shared_ptr<uml::Stereotype>& StandardProfilePackageImpl::get_StandardProfile_Library()
{
	return standardProfile_Library;
}
const std::shared_ptr<uml::Property>& StandardProfilePackageImpl::get_StandardProfile_Library_base_Artifact()
{
	return standardProfile_Library_base_Artifact;
}
const std::shared_ptr<uml::Stereotype>& StandardProfilePackageImpl::get_StandardProfile_Metaclass()
{
	return standardProfile_Metaclass;
}
const std::shared_ptr<uml::Property>& StandardProfilePackageImpl::get_StandardProfile_Metaclass_base_Class()
{
	return standardProfile_Metaclass_base_Class;
}
const std::shared_ptr<uml::Stereotype>& StandardProfilePackageImpl::get_StandardProfile_Metamodel()
{
	return standardProfile_Metamodel;
}
const std::shared_ptr<uml::Property>& StandardProfilePackageImpl::get_StandardProfile_Metamodel_base_Model()
{
	return standardProfile_Metamodel_base_Model;
}
const std::shared_ptr<uml::Stereotype>& StandardProfilePackageImpl::get_StandardProfile_ModelLibrary()
{
	return standardProfile_ModelLibrary;
}
const std::shared_ptr<uml::Property>& StandardProfilePackageImpl::get_StandardProfile_ModelLibrary_base_Package()
{
	return standardProfile_ModelLibrary_base_Package;
}
const std::shared_ptr<uml::Extension>& StandardProfilePackageImpl::get_StandardProfile_Model_Metamodel()
{
	return standardProfile_Model_Metamodel;
}
const std::shared_ptr<uml::Extension>& StandardProfilePackageImpl::get_StandardProfile_Model_SystemModel()
{
	return standardProfile_Model_SystemModel;
}
const std::shared_ptr<uml::Extension>& StandardProfilePackageImpl::get_StandardProfile_Package_Framework()
{
	return standardProfile_Package_Framework;
}
const std::shared_ptr<uml::Extension>& StandardProfilePackageImpl::get_StandardProfile_Package_ModelLibrary()
{
	return standardProfile_Package_ModelLibrary;
}
const std::shared_ptr<uml::Stereotype>& StandardProfilePackageImpl::get_StandardProfile_Process()
{
	return standardProfile_Process;
}
const std::shared_ptr<uml::Property>& StandardProfilePackageImpl::get_StandardProfile_Process_base_Component()
{
	return standardProfile_Process_base_Component;
}
const std::shared_ptr<uml::Stereotype>& StandardProfilePackageImpl::get_StandardProfile_Realization()
{
	return standardProfile_Realization;
}
const std::shared_ptr<uml::Property>& StandardProfilePackageImpl::get_StandardProfile_Realization_base_Classifier()
{
	return standardProfile_Realization_base_Classifier;
}
const std::shared_ptr<uml::Stereotype>& StandardProfilePackageImpl::get_StandardProfile_Refine()
{
	return standardProfile_Refine;
}
const std::shared_ptr<uml::Property>& StandardProfilePackageImpl::get_StandardProfile_Refine_base_Abstraction()
{
	return standardProfile_Refine_base_Abstraction;
}
const std::shared_ptr<uml::Stereotype>& StandardProfilePackageImpl::get_StandardProfile_Responsibility()
{
	return standardProfile_Responsibility;
}
const std::shared_ptr<uml::Property>& StandardProfilePackageImpl::get_StandardProfile_Responsibility_base_Usage()
{
	return standardProfile_Responsibility_base_Usage;
}
const std::shared_ptr<uml::Stereotype>& StandardProfilePackageImpl::get_StandardProfile_Script()
{
	return standardProfile_Script;
}
const std::shared_ptr<uml::Property>& StandardProfilePackageImpl::get_StandardProfile_Script_base_Artifact()
{
	return standardProfile_Script_base_Artifact;
}
const std::shared_ptr<uml::Stereotype>& StandardProfilePackageImpl::get_StandardProfile_Send()
{
	return standardProfile_Send;
}
const std::shared_ptr<uml::Property>& StandardProfilePackageImpl::get_StandardProfile_Send_base_Usage()
{
	return standardProfile_Send_base_Usage;
}
const std::shared_ptr<uml::Stereotype>& StandardProfilePackageImpl::get_StandardProfile_Service()
{
	return standardProfile_Service;
}
const std::shared_ptr<uml::Property>& StandardProfilePackageImpl::get_StandardProfile_Service_base_Component()
{
	return standardProfile_Service_base_Component;
}
const std::shared_ptr<uml::Stereotype>& StandardProfilePackageImpl::get_StandardProfile_Source()
{
	return standardProfile_Source;
}
const std::shared_ptr<uml::Property>& StandardProfilePackageImpl::get_StandardProfile_Source_base_Artifact()
{
	return standardProfile_Source_base_Artifact;
}
const std::shared_ptr<uml::Stereotype>& StandardProfilePackageImpl::get_StandardProfile_Specification()
{
	return standardProfile_Specification;
}
const std::shared_ptr<uml::Property>& StandardProfilePackageImpl::get_StandardProfile_Specification_base_Classifier()
{
	return standardProfile_Specification_base_Classifier;
}
const std::shared_ptr<uml::Stereotype>& StandardProfilePackageImpl::get_StandardProfile_Subsystem()
{
	return standardProfile_Subsystem;
}
const std::shared_ptr<uml::Property>& StandardProfilePackageImpl::get_StandardProfile_Subsystem_base_Component()
{
	return standardProfile_Subsystem_base_Component;
}
const std::shared_ptr<uml::Stereotype>& StandardProfilePackageImpl::get_StandardProfile_SystemModel()
{
	return standardProfile_SystemModel;
}
const std::shared_ptr<uml::Property>& StandardProfilePackageImpl::get_StandardProfile_SystemModel_base_Model()
{
	return standardProfile_SystemModel_base_Model;
}
const std::shared_ptr<uml::Stereotype>& StandardProfilePackageImpl::get_StandardProfile_Trace()
{
	return standardProfile_Trace;
}
const std::shared_ptr<uml::Property>& StandardProfilePackageImpl::get_StandardProfile_Trace_base_Abstraction()
{
	return standardProfile_Trace_base_Abstraction;
}
const std::shared_ptr<uml::Stereotype>& StandardProfilePackageImpl::get_StandardProfile_Type()
{
	return standardProfile_Type;
}
const std::shared_ptr<uml::Property>& StandardProfilePackageImpl::get_StandardProfile_Type_base_Class()
{
	return standardProfile_Type_base_Class;
}
const std::shared_ptr<uml::Extension>& StandardProfilePackageImpl::get_StandardProfile_Usage_Call()
{
	return standardProfile_Usage_Call;
}
const std::shared_ptr<uml::Extension>& StandardProfilePackageImpl::get_StandardProfile_Usage_Create()
{
	return standardProfile_Usage_Create;
}
const std::shared_ptr<uml::Extension>& StandardProfilePackageImpl::get_StandardProfile_Usage_Instantiate()
{
	return standardProfile_Usage_Instantiate;
}
const std::shared_ptr<uml::Extension>& StandardProfilePackageImpl::get_StandardProfile_Usage_Responsibility()
{
	return standardProfile_Usage_Responsibility;
}
const std::shared_ptr<uml::Extension>& StandardProfilePackageImpl::get_StandardProfile_Usage_Send()
{
	return standardProfile_Usage_Send;
}
const std::shared_ptr<uml::Stereotype>& StandardProfilePackageImpl::get_StandardProfile_Utility()
{
	return standardProfile_Utility;
}
const std::shared_ptr<uml::Property>& StandardProfilePackageImpl::get_StandardProfile_Utility_base_Class()
{
	return standardProfile_Utility_base_Class;
}




