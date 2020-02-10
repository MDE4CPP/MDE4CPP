#include "StandardProfile/impl/StandardProfilePackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EClass.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EReference.hpp"

//metamodel factory
#include "StandardProfile/StandardProfileFactory.hpp"

//depending model packages
#include "uml/UmlPackage.hpp"

using namespace StandardProfile;

bool StandardProfilePackageImpl::isInited = false;

StandardProfilePackageImpl::StandardProfilePackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( StandardProfileFactory::eInstance()));
}

StandardProfilePackageImpl::~StandardProfilePackageImpl()
{
}

StandardProfilePackage* StandardProfilePackageImpl::create()
{
	if (isInited)
	{
		return StandardProfilePackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    StandardProfilePackageImpl * metaModelPackage = new StandardProfilePackageImpl();
    return metaModelPackage;
}

void StandardProfilePackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}

// Begin Class Auxiliary
std::shared_ptr<ecore::EClass> StandardProfilePackageImpl::getAuxiliary_Class() const
{
	return m_auxiliary_Class;
}


std::shared_ptr<ecore::EReference> StandardProfilePackageImpl::getAuxiliary_Attribute_base_Class() const
{
	return m_auxiliary_Attribute_base_Class;
}


// End Class Auxiliary

// Begin Class BuildComponent
std::shared_ptr<ecore::EClass> StandardProfilePackageImpl::getBuildComponent_Class() const
{
	return m_buildComponent_Class;
}


std::shared_ptr<ecore::EReference> StandardProfilePackageImpl::getBuildComponent_Attribute_base_Component() const
{
	return m_buildComponent_Attribute_base_Component;
}


// End Class BuildComponent

// Begin Class Call
std::shared_ptr<ecore::EClass> StandardProfilePackageImpl::getCall_Class() const
{
	return m_call_Class;
}


std::shared_ptr<ecore::EReference> StandardProfilePackageImpl::getCall_Attribute_base_Usage() const
{
	return m_call_Attribute_base_Usage;
}


// End Class Call

// Begin Class Create
std::shared_ptr<ecore::EClass> StandardProfilePackageImpl::getCreate_Class() const
{
	return m_create_Class;
}


std::shared_ptr<ecore::EReference> StandardProfilePackageImpl::getCreate_Attribute_base_BehavioralFeature() const
{
	return m_create_Attribute_base_BehavioralFeature;
}
std::shared_ptr<ecore::EReference> StandardProfilePackageImpl::getCreate_Attribute_base_Usage() const
{
	return m_create_Attribute_base_Usage;
}


// End Class Create

// Begin Class Derive
std::shared_ptr<ecore::EClass> StandardProfilePackageImpl::getDerive_Class() const
{
	return m_derive_Class;
}


std::shared_ptr<ecore::EReference> StandardProfilePackageImpl::getDerive_Attribute_base_Abstraction() const
{
	return m_derive_Attribute_base_Abstraction;
}


// End Class Derive

// Begin Class Destroy
std::shared_ptr<ecore::EClass> StandardProfilePackageImpl::getDestroy_Class() const
{
	return m_destroy_Class;
}


std::shared_ptr<ecore::EReference> StandardProfilePackageImpl::getDestroy_Attribute_base_BehavioralFeature() const
{
	return m_destroy_Attribute_base_BehavioralFeature;
}


// End Class Destroy

// Begin Class Document
std::shared_ptr<ecore::EClass> StandardProfilePackageImpl::getDocument_Class() const
{
	return m_document_Class;
}




// End Class Document

// Begin Class Entity
std::shared_ptr<ecore::EClass> StandardProfilePackageImpl::getEntity_Class() const
{
	return m_entity_Class;
}


std::shared_ptr<ecore::EReference> StandardProfilePackageImpl::getEntity_Attribute_base_Component() const
{
	return m_entity_Attribute_base_Component;
}


// End Class Entity

// Begin Class Executable
std::shared_ptr<ecore::EClass> StandardProfilePackageImpl::getExecutable_Class() const
{
	return m_executable_Class;
}




// End Class Executable

// Begin Class File
std::shared_ptr<ecore::EClass> StandardProfilePackageImpl::getFile_Class() const
{
	return m_file_Class;
}


std::shared_ptr<ecore::EReference> StandardProfilePackageImpl::getFile_Attribute_base_Artifact() const
{
	return m_file_Attribute_base_Artifact;
}


// End Class File

// Begin Class Focus
std::shared_ptr<ecore::EClass> StandardProfilePackageImpl::getFocus_Class() const
{
	return m_focus_Class;
}


std::shared_ptr<ecore::EReference> StandardProfilePackageImpl::getFocus_Attribute_base_Class() const
{
	return m_focus_Attribute_base_Class;
}


// End Class Focus

// Begin Class Framework
std::shared_ptr<ecore::EClass> StandardProfilePackageImpl::getFramework_Class() const
{
	return m_framework_Class;
}


std::shared_ptr<ecore::EReference> StandardProfilePackageImpl::getFramework_Attribute_base_Package() const
{
	return m_framework_Attribute_base_Package;
}


// End Class Framework

// Begin Class Implement
std::shared_ptr<ecore::EClass> StandardProfilePackageImpl::getImplement_Class() const
{
	return m_implement_Class;
}


std::shared_ptr<ecore::EReference> StandardProfilePackageImpl::getImplement_Attribute_base_Component() const
{
	return m_implement_Attribute_base_Component;
}


// End Class Implement

// Begin Class ImplementationClass
std::shared_ptr<ecore::EClass> StandardProfilePackageImpl::getImplementationClass_Class() const
{
	return m_implementationClass_Class;
}


std::shared_ptr<ecore::EReference> StandardProfilePackageImpl::getImplementationClass_Attribute_base_Class() const
{
	return m_implementationClass_Attribute_base_Class;
}


// End Class ImplementationClass

// Begin Class Instantiate
std::shared_ptr<ecore::EClass> StandardProfilePackageImpl::getInstantiate_Class() const
{
	return m_instantiate_Class;
}


std::shared_ptr<ecore::EReference> StandardProfilePackageImpl::getInstantiate_Attribute_base_Usage() const
{
	return m_instantiate_Attribute_base_Usage;
}


// End Class Instantiate

// Begin Class Library
std::shared_ptr<ecore::EClass> StandardProfilePackageImpl::getLibrary_Class() const
{
	return m_library_Class;
}




// End Class Library

// Begin Class Metaclass
std::shared_ptr<ecore::EClass> StandardProfilePackageImpl::getMetaclass_Class() const
{
	return m_metaclass_Class;
}


std::shared_ptr<ecore::EReference> StandardProfilePackageImpl::getMetaclass_Attribute_base_Class() const
{
	return m_metaclass_Attribute_base_Class;
}


// End Class Metaclass

// Begin Class Metamodel
std::shared_ptr<ecore::EClass> StandardProfilePackageImpl::getMetamodel_Class() const
{
	return m_metamodel_Class;
}


std::shared_ptr<ecore::EReference> StandardProfilePackageImpl::getMetamodel_Attribute_base_Model() const
{
	return m_metamodel_Attribute_base_Model;
}


// End Class Metamodel

// Begin Class ModelLibrary
std::shared_ptr<ecore::EClass> StandardProfilePackageImpl::getModelLibrary_Class() const
{
	return m_modelLibrary_Class;
}


std::shared_ptr<ecore::EReference> StandardProfilePackageImpl::getModelLibrary_Attribute_base_Package() const
{
	return m_modelLibrary_Attribute_base_Package;
}


// End Class ModelLibrary

// Begin Class Process
std::shared_ptr<ecore::EClass> StandardProfilePackageImpl::getProcess_Class() const
{
	return m_process_Class;
}


std::shared_ptr<ecore::EReference> StandardProfilePackageImpl::getProcess_Attribute_base_Component() const
{
	return m_process_Attribute_base_Component;
}


// End Class Process

// Begin Class Realization
std::shared_ptr<ecore::EClass> StandardProfilePackageImpl::getRealization_Class() const
{
	return m_realization_Class;
}


std::shared_ptr<ecore::EReference> StandardProfilePackageImpl::getRealization_Attribute_base_Classifier() const
{
	return m_realization_Attribute_base_Classifier;
}


// End Class Realization

// Begin Class Refine
std::shared_ptr<ecore::EClass> StandardProfilePackageImpl::getRefine_Class() const
{
	return m_refine_Class;
}


std::shared_ptr<ecore::EReference> StandardProfilePackageImpl::getRefine_Attribute_base_Abstraction() const
{
	return m_refine_Attribute_base_Abstraction;
}


// End Class Refine

// Begin Class Responsibility
std::shared_ptr<ecore::EClass> StandardProfilePackageImpl::getResponsibility_Class() const
{
	return m_responsibility_Class;
}


std::shared_ptr<ecore::EReference> StandardProfilePackageImpl::getResponsibility_Attribute_base_Usage() const
{
	return m_responsibility_Attribute_base_Usage;
}


// End Class Responsibility

// Begin Class Script
std::shared_ptr<ecore::EClass> StandardProfilePackageImpl::getScript_Class() const
{
	return m_script_Class;
}




// End Class Script

// Begin Class Send
std::shared_ptr<ecore::EClass> StandardProfilePackageImpl::getSend_Class() const
{
	return m_send_Class;
}


std::shared_ptr<ecore::EReference> StandardProfilePackageImpl::getSend_Attribute_base_Usage() const
{
	return m_send_Attribute_base_Usage;
}


// End Class Send

// Begin Class Service
std::shared_ptr<ecore::EClass> StandardProfilePackageImpl::getService_Class() const
{
	return m_service_Class;
}


std::shared_ptr<ecore::EReference> StandardProfilePackageImpl::getService_Attribute_base_Component() const
{
	return m_service_Attribute_base_Component;
}


// End Class Service

// Begin Class Source
std::shared_ptr<ecore::EClass> StandardProfilePackageImpl::getSource_Class() const
{
	return m_source_Class;
}




// End Class Source

// Begin Class Specification
std::shared_ptr<ecore::EClass> StandardProfilePackageImpl::getSpecification_Class() const
{
	return m_specification_Class;
}


std::shared_ptr<ecore::EReference> StandardProfilePackageImpl::getSpecification_Attribute_base_Classifier() const
{
	return m_specification_Attribute_base_Classifier;
}


// End Class Specification

// Begin Class Subsystem
std::shared_ptr<ecore::EClass> StandardProfilePackageImpl::getSubsystem_Class() const
{
	return m_subsystem_Class;
}


std::shared_ptr<ecore::EReference> StandardProfilePackageImpl::getSubsystem_Attribute_base_Component() const
{
	return m_subsystem_Attribute_base_Component;
}


// End Class Subsystem

// Begin Class SystemModel
std::shared_ptr<ecore::EClass> StandardProfilePackageImpl::getSystemModel_Class() const
{
	return m_systemModel_Class;
}


std::shared_ptr<ecore::EReference> StandardProfilePackageImpl::getSystemModel_Attribute_base_Model() const
{
	return m_systemModel_Attribute_base_Model;
}


// End Class SystemModel

// Begin Class Trace
std::shared_ptr<ecore::EClass> StandardProfilePackageImpl::getTrace_Class() const
{
	return m_trace_Class;
}


std::shared_ptr<ecore::EReference> StandardProfilePackageImpl::getTrace_Attribute_base_Abstraction() const
{
	return m_trace_Attribute_base_Abstraction;
}


// End Class Trace

// Begin Class Type
std::shared_ptr<ecore::EClass> StandardProfilePackageImpl::getType_Class() const
{
	return m_type_Class;
}


std::shared_ptr<ecore::EReference> StandardProfilePackageImpl::getType_Attribute_base_Class() const
{
	return m_type_Attribute_base_Class;
}


// End Class Type

// Begin Class Utility
std::shared_ptr<ecore::EClass> StandardProfilePackageImpl::getUtility_Class() const
{
	return m_utility_Class;
}


std::shared_ptr<ecore::EReference> StandardProfilePackageImpl::getUtility_Attribute_base_Class() const
{
	return m_utility_Attribute_base_Class;
}


// End Class Utility

