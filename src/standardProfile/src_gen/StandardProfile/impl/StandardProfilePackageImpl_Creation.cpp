#include "StandardProfile/impl/StandardProfilePackageImpl.hpp"

// metametamodel factory
#include "ecore/EcoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EClass.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EReference.hpp"

//depending model packages
#include "uml/UmlPackage.hpp"

using namespace StandardProfile;

void StandardProfilePackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::EcoreFactory> factory = ecore::EcoreFactory::eInstance();

	createAuxiliaryContent(package, factory);
	createBuildComponentContent(package, factory);
	createCallContent(package, factory);
	createCreateContent(package, factory);
	createDeriveContent(package, factory);
	createDestroyContent(package, factory);
	createDocumentContent(package, factory);
	createEntityContent(package, factory);
	createExecutableContent(package, factory);
	createFileContent(package, factory);
	createFocusContent(package, factory);
	createFrameworkContent(package, factory);
	createImplementContent(package, factory);
	createImplementationClassContent(package, factory);
	createInstantiateContent(package, factory);
	createLibraryContent(package, factory);
	createMetaclassContent(package, factory);
	createMetamodelContent(package, factory);
	createModelLibraryContent(package, factory);
	createProcessContent(package, factory);
	createRealizationContent(package, factory);
	createRefineContent(package, factory);
	createResponsibilityContent(package, factory);
	createScriptContent(package, factory);
	createSendContent(package, factory);
	createServiceContent(package, factory);
	createSourceContent(package, factory);
	createSpecificationContent(package, factory);
	createSubsystemContent(package, factory);
	createSystemModelContent(package, factory);
	createTraceContent(package, factory);
	createTypeContent(package, factory);
	createUtilityContent(package, factory);

	createPackageEDataTypes(package, factory);
}

void StandardProfilePackageImpl::createAuxiliaryContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_auxiliary_Class = factory->createEClass_in_EPackage(package, AUXILIARY_CLASS);
	
	m_auxiliary_Attribute_base_Class = factory->createEReference_in_EContainingClass(m_auxiliary_Class, AUXILIARY_ATTRIBUTE_BASE_CLASS);
	
	
}

void StandardProfilePackageImpl::createBuildComponentContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_buildComponent_Class = factory->createEClass_in_EPackage(package, BUILDCOMPONENT_CLASS);
	
	m_buildComponent_Attribute_base_Component = factory->createEReference_in_EContainingClass(m_buildComponent_Class, BUILDCOMPONENT_ATTRIBUTE_BASE_COMPONENT);
	
	
}

void StandardProfilePackageImpl::createCallContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_call_Class = factory->createEClass_in_EPackage(package, CALL_CLASS);
	
	m_call_Attribute_base_Usage = factory->createEReference_in_EContainingClass(m_call_Class, CALL_ATTRIBUTE_BASE_USAGE);
	
	
}

void StandardProfilePackageImpl::createCreateContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_create_Class = factory->createEClass_in_EPackage(package, CREATE_CLASS);
	
	m_create_Attribute_base_BehavioralFeature = factory->createEReference_in_EContainingClass(m_create_Class, CREATE_ATTRIBUTE_BASE_BEHAVIORALFEATURE);
	m_create_Attribute_base_Usage = factory->createEReference_in_EContainingClass(m_create_Class, CREATE_ATTRIBUTE_BASE_USAGE);
	
	
}

void StandardProfilePackageImpl::createDeriveContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_derive_Class = factory->createEClass_in_EPackage(package, DERIVE_CLASS);
	
	m_derive_Attribute_base_Abstraction = factory->createEReference_in_EContainingClass(m_derive_Class, DERIVE_ATTRIBUTE_BASE_ABSTRACTION);
	
	
}

void StandardProfilePackageImpl::createDestroyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_destroy_Class = factory->createEClass_in_EPackage(package, DESTROY_CLASS);
	
	m_destroy_Attribute_base_BehavioralFeature = factory->createEReference_in_EContainingClass(m_destroy_Class, DESTROY_ATTRIBUTE_BASE_BEHAVIORALFEATURE);
	
	
}

void StandardProfilePackageImpl::createDocumentContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_document_Class = factory->createEClass_in_EPackage(package, DOCUMENT_CLASS);
	
	
	
}

void StandardProfilePackageImpl::createEntityContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_entity_Class = factory->createEClass_in_EPackage(package, ENTITY_CLASS);
	
	m_entity_Attribute_base_Component = factory->createEReference_in_EContainingClass(m_entity_Class, ENTITY_ATTRIBUTE_BASE_COMPONENT);
	
	
}

void StandardProfilePackageImpl::createExecutableContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_executable_Class = factory->createEClass_in_EPackage(package, EXECUTABLE_CLASS);
	
	
	
}

void StandardProfilePackageImpl::createFileContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_file_Class = factory->createEClass_in_EPackage(package, FILE_CLASS);
	
	m_file_Attribute_base_Artifact = factory->createEReference_in_EContainingClass(m_file_Class, FILE_ATTRIBUTE_BASE_ARTIFACT);
	
	
}

void StandardProfilePackageImpl::createFocusContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_focus_Class = factory->createEClass_in_EPackage(package, FOCUS_CLASS);
	
	m_focus_Attribute_base_Class = factory->createEReference_in_EContainingClass(m_focus_Class, FOCUS_ATTRIBUTE_BASE_CLASS);
	
	
}

void StandardProfilePackageImpl::createFrameworkContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_framework_Class = factory->createEClass_in_EPackage(package, FRAMEWORK_CLASS);
	
	m_framework_Attribute_base_Package = factory->createEReference_in_EContainingClass(m_framework_Class, FRAMEWORK_ATTRIBUTE_BASE_PACKAGE);
	
	
}

void StandardProfilePackageImpl::createImplementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_implement_Class = factory->createEClass_in_EPackage(package, IMPLEMENT_CLASS);
	
	m_implement_Attribute_base_Component = factory->createEReference_in_EContainingClass(m_implement_Class, IMPLEMENT_ATTRIBUTE_BASE_COMPONENT);
	
	
}

void StandardProfilePackageImpl::createImplementationClassContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_implementationClass_Class = factory->createEClass_in_EPackage(package, IMPLEMENTATIONCLASS_CLASS);
	
	m_implementationClass_Attribute_base_Class = factory->createEReference_in_EContainingClass(m_implementationClass_Class, IMPLEMENTATIONCLASS_ATTRIBUTE_BASE_CLASS);
	
	
}

void StandardProfilePackageImpl::createInstantiateContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_instantiate_Class = factory->createEClass_in_EPackage(package, INSTANTIATE_CLASS);
	
	m_instantiate_Attribute_base_Usage = factory->createEReference_in_EContainingClass(m_instantiate_Class, INSTANTIATE_ATTRIBUTE_BASE_USAGE);
	
	
}

void StandardProfilePackageImpl::createLibraryContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_library_Class = factory->createEClass_in_EPackage(package, LIBRARY_CLASS);
	
	
	
}

void StandardProfilePackageImpl::createMetaclassContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_metaclass_Class = factory->createEClass_in_EPackage(package, METACLASS_CLASS);
	
	m_metaclass_Attribute_base_Class = factory->createEReference_in_EContainingClass(m_metaclass_Class, METACLASS_ATTRIBUTE_BASE_CLASS);
	
	
}

void StandardProfilePackageImpl::createMetamodelContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_metamodel_Class = factory->createEClass_in_EPackage(package, METAMODEL_CLASS);
	
	m_metamodel_Attribute_base_Model = factory->createEReference_in_EContainingClass(m_metamodel_Class, METAMODEL_ATTRIBUTE_BASE_MODEL);
	
	
}

void StandardProfilePackageImpl::createModelLibraryContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_modelLibrary_Class = factory->createEClass_in_EPackage(package, MODELLIBRARY_CLASS);
	
	m_modelLibrary_Attribute_base_Package = factory->createEReference_in_EContainingClass(m_modelLibrary_Class, MODELLIBRARY_ATTRIBUTE_BASE_PACKAGE);
	
	
}

void StandardProfilePackageImpl::createProcessContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_process_Class = factory->createEClass_in_EPackage(package, PROCESS_CLASS);
	
	m_process_Attribute_base_Component = factory->createEReference_in_EContainingClass(m_process_Class, PROCESS_ATTRIBUTE_BASE_COMPONENT);
	
	
}

void StandardProfilePackageImpl::createRealizationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_realization_Class = factory->createEClass_in_EPackage(package, REALIZATION_CLASS);
	
	m_realization_Attribute_base_Classifier = factory->createEReference_in_EContainingClass(m_realization_Class, REALIZATION_ATTRIBUTE_BASE_CLASSIFIER);
	
	
}

void StandardProfilePackageImpl::createRefineContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_refine_Class = factory->createEClass_in_EPackage(package, REFINE_CLASS);
	
	m_refine_Attribute_base_Abstraction = factory->createEReference_in_EContainingClass(m_refine_Class, REFINE_ATTRIBUTE_BASE_ABSTRACTION);
	
	
}

void StandardProfilePackageImpl::createResponsibilityContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_responsibility_Class = factory->createEClass_in_EPackage(package, RESPONSIBILITY_CLASS);
	
	m_responsibility_Attribute_base_Usage = factory->createEReference_in_EContainingClass(m_responsibility_Class, RESPONSIBILITY_ATTRIBUTE_BASE_USAGE);
	
	
}

void StandardProfilePackageImpl::createScriptContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_script_Class = factory->createEClass_in_EPackage(package, SCRIPT_CLASS);
	
	
	
}

void StandardProfilePackageImpl::createSendContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_send_Class = factory->createEClass_in_EPackage(package, SEND_CLASS);
	
	m_send_Attribute_base_Usage = factory->createEReference_in_EContainingClass(m_send_Class, SEND_ATTRIBUTE_BASE_USAGE);
	
	
}

void StandardProfilePackageImpl::createServiceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_service_Class = factory->createEClass_in_EPackage(package, SERVICE_CLASS);
	
	m_service_Attribute_base_Component = factory->createEReference_in_EContainingClass(m_service_Class, SERVICE_ATTRIBUTE_BASE_COMPONENT);
	
	
}

void StandardProfilePackageImpl::createSourceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_source_Class = factory->createEClass_in_EPackage(package, SOURCE_CLASS);
	
	
	
}

void StandardProfilePackageImpl::createSpecificationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_specification_Class = factory->createEClass_in_EPackage(package, SPECIFICATION_CLASS);
	
	m_specification_Attribute_base_Classifier = factory->createEReference_in_EContainingClass(m_specification_Class, SPECIFICATION_ATTRIBUTE_BASE_CLASSIFIER);
	
	
}

void StandardProfilePackageImpl::createSubsystemContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_subsystem_Class = factory->createEClass_in_EPackage(package, SUBSYSTEM_CLASS);
	
	m_subsystem_Attribute_base_Component = factory->createEReference_in_EContainingClass(m_subsystem_Class, SUBSYSTEM_ATTRIBUTE_BASE_COMPONENT);
	
	
}

void StandardProfilePackageImpl::createSystemModelContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_systemModel_Class = factory->createEClass_in_EPackage(package, SYSTEMMODEL_CLASS);
	
	m_systemModel_Attribute_base_Model = factory->createEReference_in_EContainingClass(m_systemModel_Class, SYSTEMMODEL_ATTRIBUTE_BASE_MODEL);
	
	
}

void StandardProfilePackageImpl::createTraceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_trace_Class = factory->createEClass_in_EPackage(package, TRACE_CLASS);
	
	m_trace_Attribute_base_Abstraction = factory->createEReference_in_EContainingClass(m_trace_Class, TRACE_ATTRIBUTE_BASE_ABSTRACTION);
	
	
}

void StandardProfilePackageImpl::createTypeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_type_Class = factory->createEClass_in_EPackage(package, TYPE_CLASS);
	
	m_type_Attribute_base_Class = factory->createEReference_in_EContainingClass(m_type_Class, TYPE_ATTRIBUTE_BASE_CLASS);
	
	
}

void StandardProfilePackageImpl::createUtilityContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_utility_Class = factory->createEClass_in_EPackage(package, UTILITY_CLASS);
	
	m_utility_Attribute_base_Class = factory->createEReference_in_EContainingClass(m_utility_Class, UTILITY_ATTRIBUTE_BASE_CLASS);
	
	
}

void StandardProfilePackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	
}
