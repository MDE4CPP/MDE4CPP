#include "StandardProfile/impl/StandardProfilePackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EClass.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EReference.hpp"

// metametamodel factory
#include "ecore/EcoreFactory.hpp"

//depending model packages
#include "uml/UmlPackage.hpp"

using namespace StandardProfile;

void StandardProfilePackageImpl::initializePackageContents()
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
	m_document_Class->getESuperTypes()->push_back(getFile_Class());
	m_executable_Class->getESuperTypes()->push_back(getFile_Class());
	m_library_Class->getESuperTypes()->push_back(getFile_Class());
	m_script_Class->getESuperTypes()->push_back(getFile_Class());
	m_source_Class->getESuperTypes()->push_back(getFile_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeAuxiliaryContent();
	initializeBuildComponentContent();
	initializeCallContent();
	initializeCreateContent();
	initializeDeriveContent();
	initializeDestroyContent();
	initializeDocumentContent();
	initializeEntityContent();
	initializeExecutableContent();
	initializeFileContent();
	initializeFocusContent();
	initializeFrameworkContent();
	initializeImplementContent();
	initializeImplementationClassContent();
	initializeInstantiateContent();
	initializeLibraryContent();
	initializeMetaclassContent();
	initializeMetamodelContent();
	initializeModelLibraryContent();
	initializeProcessContent();
	initializeRealizationContent();
	initializeRefineContent();
	initializeResponsibilityContent();
	initializeScriptContent();
	initializeSendContent();
	initializeServiceContent();
	initializeSourceContent();
	initializeSpecificationContent();
	initializeSubsystemContent();
	initializeSystemModelContent();
	initializeTraceContent();
	initializeTypeContent();
	initializeUtilityContent();

	initializePackageEDataTypes();
}

void StandardProfilePackageImpl::initializeAuxiliaryContent()
{
	m_auxiliary_Class->setName("Auxiliary");
	m_auxiliary_Class->setAbstract(false);
	m_auxiliary_Class->setInterface(false);
	
	
	m_auxiliary_Attribute_base_Class->setName("base_Class");
	m_auxiliary_Attribute_base_Class->setEType(uml::UmlPackage::eInstance()->getClass_Class());
	m_auxiliary_Attribute_base_Class->setLowerBound(1);
	m_auxiliary_Attribute_base_Class->setUpperBound(1);
	m_auxiliary_Attribute_base_Class->setTransient(false);
	m_auxiliary_Attribute_base_Class->setVolatile(false);
	m_auxiliary_Attribute_base_Class->setChangeable(true);
	m_auxiliary_Attribute_base_Class->setUnsettable(false);
	m_auxiliary_Attribute_base_Class->setUnique(true);
	m_auxiliary_Attribute_base_Class->setDerived(false);
	m_auxiliary_Attribute_base_Class->setOrdered(false);
	m_auxiliary_Attribute_base_Class->setContainment(false);
	m_auxiliary_Attribute_base_Class->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_auxiliary_Attribute_base_Class->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_auxiliary_Attribute_base_Class->setEOpposite(otherEnd);
	    }
	}
	
	
}

void StandardProfilePackageImpl::initializeBuildComponentContent()
{
	m_buildComponent_Class->setName("BuildComponent");
	m_buildComponent_Class->setAbstract(false);
	m_buildComponent_Class->setInterface(false);
	
	
	m_buildComponent_Attribute_base_Component->setName("base_Component");
	m_buildComponent_Attribute_base_Component->setEType(uml::UmlPackage::eInstance()->getComponent_Class());
	m_buildComponent_Attribute_base_Component->setLowerBound(1);
	m_buildComponent_Attribute_base_Component->setUpperBound(1);
	m_buildComponent_Attribute_base_Component->setTransient(false);
	m_buildComponent_Attribute_base_Component->setVolatile(false);
	m_buildComponent_Attribute_base_Component->setChangeable(true);
	m_buildComponent_Attribute_base_Component->setUnsettable(false);
	m_buildComponent_Attribute_base_Component->setUnique(true);
	m_buildComponent_Attribute_base_Component->setDerived(false);
	m_buildComponent_Attribute_base_Component->setOrdered(false);
	m_buildComponent_Attribute_base_Component->setContainment(false);
	m_buildComponent_Attribute_base_Component->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_buildComponent_Attribute_base_Component->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_buildComponent_Attribute_base_Component->setEOpposite(otherEnd);
	    }
	}
	
	
}

void StandardProfilePackageImpl::initializeCallContent()
{
	m_call_Class->setName("Call");
	m_call_Class->setAbstract(false);
	m_call_Class->setInterface(false);
	
	
	m_call_Attribute_base_Usage->setName("base_Usage");
	m_call_Attribute_base_Usage->setEType(uml::UmlPackage::eInstance()->getUsage_Class());
	m_call_Attribute_base_Usage->setLowerBound(1);
	m_call_Attribute_base_Usage->setUpperBound(1);
	m_call_Attribute_base_Usage->setTransient(false);
	m_call_Attribute_base_Usage->setVolatile(false);
	m_call_Attribute_base_Usage->setChangeable(true);
	m_call_Attribute_base_Usage->setUnsettable(false);
	m_call_Attribute_base_Usage->setUnique(true);
	m_call_Attribute_base_Usage->setDerived(false);
	m_call_Attribute_base_Usage->setOrdered(false);
	m_call_Attribute_base_Usage->setContainment(false);
	m_call_Attribute_base_Usage->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_call_Attribute_base_Usage->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_call_Attribute_base_Usage->setEOpposite(otherEnd);
	    }
	}
	
	
}

void StandardProfilePackageImpl::initializeCreateContent()
{
	m_create_Class->setName("Create");
	m_create_Class->setAbstract(false);
	m_create_Class->setInterface(false);
	
	
	m_create_Attribute_base_BehavioralFeature->setName("base_BehavioralFeature");
	m_create_Attribute_base_BehavioralFeature->setEType(uml::UmlPackage::eInstance()->getBehavioralFeature_Class());
	m_create_Attribute_base_BehavioralFeature->setLowerBound(1);
	m_create_Attribute_base_BehavioralFeature->setUpperBound(1);
	m_create_Attribute_base_BehavioralFeature->setTransient(false);
	m_create_Attribute_base_BehavioralFeature->setVolatile(false);
	m_create_Attribute_base_BehavioralFeature->setChangeable(true);
	m_create_Attribute_base_BehavioralFeature->setUnsettable(false);
	m_create_Attribute_base_BehavioralFeature->setUnique(true);
	m_create_Attribute_base_BehavioralFeature->setDerived(false);
	m_create_Attribute_base_BehavioralFeature->setOrdered(false);
	m_create_Attribute_base_BehavioralFeature->setContainment(false);
	m_create_Attribute_base_BehavioralFeature->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_create_Attribute_base_BehavioralFeature->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_create_Attribute_base_BehavioralFeature->setEOpposite(otherEnd);
	    }
	}
	m_create_Attribute_base_Usage->setName("base_Usage");
	m_create_Attribute_base_Usage->setEType(uml::UmlPackage::eInstance()->getUsage_Class());
	m_create_Attribute_base_Usage->setLowerBound(1);
	m_create_Attribute_base_Usage->setUpperBound(1);
	m_create_Attribute_base_Usage->setTransient(false);
	m_create_Attribute_base_Usage->setVolatile(false);
	m_create_Attribute_base_Usage->setChangeable(true);
	m_create_Attribute_base_Usage->setUnsettable(false);
	m_create_Attribute_base_Usage->setUnique(true);
	m_create_Attribute_base_Usage->setDerived(false);
	m_create_Attribute_base_Usage->setOrdered(false);
	m_create_Attribute_base_Usage->setContainment(false);
	m_create_Attribute_base_Usage->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_create_Attribute_base_Usage->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_create_Attribute_base_Usage->setEOpposite(otherEnd);
	    }
	}
	
	
}

void StandardProfilePackageImpl::initializeDeriveContent()
{
	m_derive_Class->setName("Derive");
	m_derive_Class->setAbstract(false);
	m_derive_Class->setInterface(false);
	
	
	m_derive_Attribute_base_Abstraction->setName("base_Abstraction");
	m_derive_Attribute_base_Abstraction->setEType(uml::UmlPackage::eInstance()->getAbstraction_Class());
	m_derive_Attribute_base_Abstraction->setLowerBound(1);
	m_derive_Attribute_base_Abstraction->setUpperBound(1);
	m_derive_Attribute_base_Abstraction->setTransient(false);
	m_derive_Attribute_base_Abstraction->setVolatile(false);
	m_derive_Attribute_base_Abstraction->setChangeable(true);
	m_derive_Attribute_base_Abstraction->setUnsettable(false);
	m_derive_Attribute_base_Abstraction->setUnique(true);
	m_derive_Attribute_base_Abstraction->setDerived(false);
	m_derive_Attribute_base_Abstraction->setOrdered(false);
	m_derive_Attribute_base_Abstraction->setContainment(false);
	m_derive_Attribute_base_Abstraction->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_derive_Attribute_base_Abstraction->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_derive_Attribute_base_Abstraction->setEOpposite(otherEnd);
	    }
	}
	
	
}

void StandardProfilePackageImpl::initializeDestroyContent()
{
	m_destroy_Class->setName("Destroy");
	m_destroy_Class->setAbstract(false);
	m_destroy_Class->setInterface(false);
	
	
	m_destroy_Attribute_base_BehavioralFeature->setName("base_BehavioralFeature");
	m_destroy_Attribute_base_BehavioralFeature->setEType(uml::UmlPackage::eInstance()->getBehavioralFeature_Class());
	m_destroy_Attribute_base_BehavioralFeature->setLowerBound(1);
	m_destroy_Attribute_base_BehavioralFeature->setUpperBound(1);
	m_destroy_Attribute_base_BehavioralFeature->setTransient(false);
	m_destroy_Attribute_base_BehavioralFeature->setVolatile(false);
	m_destroy_Attribute_base_BehavioralFeature->setChangeable(true);
	m_destroy_Attribute_base_BehavioralFeature->setUnsettable(false);
	m_destroy_Attribute_base_BehavioralFeature->setUnique(true);
	m_destroy_Attribute_base_BehavioralFeature->setDerived(false);
	m_destroy_Attribute_base_BehavioralFeature->setOrdered(false);
	m_destroy_Attribute_base_BehavioralFeature->setContainment(false);
	m_destroy_Attribute_base_BehavioralFeature->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_destroy_Attribute_base_BehavioralFeature->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_destroy_Attribute_base_BehavioralFeature->setEOpposite(otherEnd);
	    }
	}
	
	
}

void StandardProfilePackageImpl::initializeDocumentContent()
{
	m_document_Class->setName("Document");
	m_document_Class->setAbstract(false);
	m_document_Class->setInterface(false);
	
	
	
	
}

void StandardProfilePackageImpl::initializeEntityContent()
{
	m_entity_Class->setName("Entity");
	m_entity_Class->setAbstract(false);
	m_entity_Class->setInterface(false);
	
	
	m_entity_Attribute_base_Component->setName("base_Component");
	m_entity_Attribute_base_Component->setEType(uml::UmlPackage::eInstance()->getComponent_Class());
	m_entity_Attribute_base_Component->setLowerBound(1);
	m_entity_Attribute_base_Component->setUpperBound(1);
	m_entity_Attribute_base_Component->setTransient(false);
	m_entity_Attribute_base_Component->setVolatile(false);
	m_entity_Attribute_base_Component->setChangeable(true);
	m_entity_Attribute_base_Component->setUnsettable(false);
	m_entity_Attribute_base_Component->setUnique(true);
	m_entity_Attribute_base_Component->setDerived(false);
	m_entity_Attribute_base_Component->setOrdered(false);
	m_entity_Attribute_base_Component->setContainment(false);
	m_entity_Attribute_base_Component->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_entity_Attribute_base_Component->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_entity_Attribute_base_Component->setEOpposite(otherEnd);
	    }
	}
	
	
}

void StandardProfilePackageImpl::initializeExecutableContent()
{
	m_executable_Class->setName("Executable");
	m_executable_Class->setAbstract(false);
	m_executable_Class->setInterface(false);
	
	
	
	
}

void StandardProfilePackageImpl::initializeFileContent()
{
	m_file_Class->setName("File");
	m_file_Class->setAbstract(false);
	m_file_Class->setInterface(false);
	
	
	m_file_Attribute_base_Artifact->setName("base_Artifact");
	m_file_Attribute_base_Artifact->setEType(uml::UmlPackage::eInstance()->getArtifact_Class());
	m_file_Attribute_base_Artifact->setLowerBound(1);
	m_file_Attribute_base_Artifact->setUpperBound(1);
	m_file_Attribute_base_Artifact->setTransient(false);
	m_file_Attribute_base_Artifact->setVolatile(false);
	m_file_Attribute_base_Artifact->setChangeable(true);
	m_file_Attribute_base_Artifact->setUnsettable(false);
	m_file_Attribute_base_Artifact->setUnique(true);
	m_file_Attribute_base_Artifact->setDerived(false);
	m_file_Attribute_base_Artifact->setOrdered(false);
	m_file_Attribute_base_Artifact->setContainment(false);
	m_file_Attribute_base_Artifact->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_file_Attribute_base_Artifact->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_file_Attribute_base_Artifact->setEOpposite(otherEnd);
	    }
	}
	
	
}

void StandardProfilePackageImpl::initializeFocusContent()
{
	m_focus_Class->setName("Focus");
	m_focus_Class->setAbstract(false);
	m_focus_Class->setInterface(false);
	
	
	m_focus_Attribute_base_Class->setName("base_Class");
	m_focus_Attribute_base_Class->setEType(uml::UmlPackage::eInstance()->getClass_Class());
	m_focus_Attribute_base_Class->setLowerBound(1);
	m_focus_Attribute_base_Class->setUpperBound(1);
	m_focus_Attribute_base_Class->setTransient(false);
	m_focus_Attribute_base_Class->setVolatile(false);
	m_focus_Attribute_base_Class->setChangeable(true);
	m_focus_Attribute_base_Class->setUnsettable(false);
	m_focus_Attribute_base_Class->setUnique(true);
	m_focus_Attribute_base_Class->setDerived(false);
	m_focus_Attribute_base_Class->setOrdered(false);
	m_focus_Attribute_base_Class->setContainment(false);
	m_focus_Attribute_base_Class->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_focus_Attribute_base_Class->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_focus_Attribute_base_Class->setEOpposite(otherEnd);
	    }
	}
	
	
}

void StandardProfilePackageImpl::initializeFrameworkContent()
{
	m_framework_Class->setName("Framework");
	m_framework_Class->setAbstract(false);
	m_framework_Class->setInterface(false);
	
	
	m_framework_Attribute_base_Package->setName("base_Package");
	m_framework_Attribute_base_Package->setEType(uml::UmlPackage::eInstance()->getPackage_Class());
	m_framework_Attribute_base_Package->setLowerBound(1);
	m_framework_Attribute_base_Package->setUpperBound(1);
	m_framework_Attribute_base_Package->setTransient(false);
	m_framework_Attribute_base_Package->setVolatile(false);
	m_framework_Attribute_base_Package->setChangeable(true);
	m_framework_Attribute_base_Package->setUnsettable(false);
	m_framework_Attribute_base_Package->setUnique(true);
	m_framework_Attribute_base_Package->setDerived(false);
	m_framework_Attribute_base_Package->setOrdered(false);
	m_framework_Attribute_base_Package->setContainment(false);
	m_framework_Attribute_base_Package->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_framework_Attribute_base_Package->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_framework_Attribute_base_Package->setEOpposite(otherEnd);
	    }
	}
	
	
}

void StandardProfilePackageImpl::initializeImplementContent()
{
	m_implement_Class->setName("Implement");
	m_implement_Class->setAbstract(false);
	m_implement_Class->setInterface(false);
	
	
	m_implement_Attribute_base_Component->setName("base_Component");
	m_implement_Attribute_base_Component->setEType(uml::UmlPackage::eInstance()->getComponent_Class());
	m_implement_Attribute_base_Component->setLowerBound(1);
	m_implement_Attribute_base_Component->setUpperBound(1);
	m_implement_Attribute_base_Component->setTransient(false);
	m_implement_Attribute_base_Component->setVolatile(false);
	m_implement_Attribute_base_Component->setChangeable(true);
	m_implement_Attribute_base_Component->setUnsettable(false);
	m_implement_Attribute_base_Component->setUnique(true);
	m_implement_Attribute_base_Component->setDerived(false);
	m_implement_Attribute_base_Component->setOrdered(false);
	m_implement_Attribute_base_Component->setContainment(false);
	m_implement_Attribute_base_Component->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_implement_Attribute_base_Component->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_implement_Attribute_base_Component->setEOpposite(otherEnd);
	    }
	}
	
	
}

void StandardProfilePackageImpl::initializeImplementationClassContent()
{
	m_implementationClass_Class->setName("ImplementationClass");
	m_implementationClass_Class->setAbstract(false);
	m_implementationClass_Class->setInterface(false);
	
	
	m_implementationClass_Attribute_base_Class->setName("base_Class");
	m_implementationClass_Attribute_base_Class->setEType(uml::UmlPackage::eInstance()->getClass_Class());
	m_implementationClass_Attribute_base_Class->setLowerBound(1);
	m_implementationClass_Attribute_base_Class->setUpperBound(1);
	m_implementationClass_Attribute_base_Class->setTransient(false);
	m_implementationClass_Attribute_base_Class->setVolatile(false);
	m_implementationClass_Attribute_base_Class->setChangeable(true);
	m_implementationClass_Attribute_base_Class->setUnsettable(false);
	m_implementationClass_Attribute_base_Class->setUnique(true);
	m_implementationClass_Attribute_base_Class->setDerived(false);
	m_implementationClass_Attribute_base_Class->setOrdered(false);
	m_implementationClass_Attribute_base_Class->setContainment(false);
	m_implementationClass_Attribute_base_Class->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_implementationClass_Attribute_base_Class->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_implementationClass_Attribute_base_Class->setEOpposite(otherEnd);
	    }
	}
	
	
}

void StandardProfilePackageImpl::initializeInstantiateContent()
{
	m_instantiate_Class->setName("Instantiate");
	m_instantiate_Class->setAbstract(false);
	m_instantiate_Class->setInterface(false);
	
	
	m_instantiate_Attribute_base_Usage->setName("base_Usage");
	m_instantiate_Attribute_base_Usage->setEType(uml::UmlPackage::eInstance()->getUsage_Class());
	m_instantiate_Attribute_base_Usage->setLowerBound(1);
	m_instantiate_Attribute_base_Usage->setUpperBound(1);
	m_instantiate_Attribute_base_Usage->setTransient(false);
	m_instantiate_Attribute_base_Usage->setVolatile(false);
	m_instantiate_Attribute_base_Usage->setChangeable(true);
	m_instantiate_Attribute_base_Usage->setUnsettable(false);
	m_instantiate_Attribute_base_Usage->setUnique(true);
	m_instantiate_Attribute_base_Usage->setDerived(false);
	m_instantiate_Attribute_base_Usage->setOrdered(false);
	m_instantiate_Attribute_base_Usage->setContainment(false);
	m_instantiate_Attribute_base_Usage->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_instantiate_Attribute_base_Usage->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_instantiate_Attribute_base_Usage->setEOpposite(otherEnd);
	    }
	}
	
	
}

void StandardProfilePackageImpl::initializeLibraryContent()
{
	m_library_Class->setName("Library");
	m_library_Class->setAbstract(false);
	m_library_Class->setInterface(false);
	
	
	
	
}

void StandardProfilePackageImpl::initializeMetaclassContent()
{
	m_metaclass_Class->setName("Metaclass");
	m_metaclass_Class->setAbstract(false);
	m_metaclass_Class->setInterface(false);
	
	
	m_metaclass_Attribute_base_Class->setName("base_Class");
	m_metaclass_Attribute_base_Class->setEType(uml::UmlPackage::eInstance()->getClass_Class());
	m_metaclass_Attribute_base_Class->setLowerBound(1);
	m_metaclass_Attribute_base_Class->setUpperBound(1);
	m_metaclass_Attribute_base_Class->setTransient(false);
	m_metaclass_Attribute_base_Class->setVolatile(false);
	m_metaclass_Attribute_base_Class->setChangeable(true);
	m_metaclass_Attribute_base_Class->setUnsettable(false);
	m_metaclass_Attribute_base_Class->setUnique(true);
	m_metaclass_Attribute_base_Class->setDerived(false);
	m_metaclass_Attribute_base_Class->setOrdered(false);
	m_metaclass_Attribute_base_Class->setContainment(false);
	m_metaclass_Attribute_base_Class->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_metaclass_Attribute_base_Class->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_metaclass_Attribute_base_Class->setEOpposite(otherEnd);
	    }
	}
	
	
}

void StandardProfilePackageImpl::initializeMetamodelContent()
{
	m_metamodel_Class->setName("Metamodel");
	m_metamodel_Class->setAbstract(false);
	m_metamodel_Class->setInterface(false);
	
	
	m_metamodel_Attribute_base_Model->setName("base_Model");
	m_metamodel_Attribute_base_Model->setEType(uml::UmlPackage::eInstance()->getModel_Class());
	m_metamodel_Attribute_base_Model->setLowerBound(1);
	m_metamodel_Attribute_base_Model->setUpperBound(1);
	m_metamodel_Attribute_base_Model->setTransient(false);
	m_metamodel_Attribute_base_Model->setVolatile(false);
	m_metamodel_Attribute_base_Model->setChangeable(true);
	m_metamodel_Attribute_base_Model->setUnsettable(false);
	m_metamodel_Attribute_base_Model->setUnique(true);
	m_metamodel_Attribute_base_Model->setDerived(false);
	m_metamodel_Attribute_base_Model->setOrdered(false);
	m_metamodel_Attribute_base_Model->setContainment(false);
	m_metamodel_Attribute_base_Model->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_metamodel_Attribute_base_Model->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_metamodel_Attribute_base_Model->setEOpposite(otherEnd);
	    }
	}
	
	
}

void StandardProfilePackageImpl::initializeModelLibraryContent()
{
	m_modelLibrary_Class->setName("ModelLibrary");
	m_modelLibrary_Class->setAbstract(false);
	m_modelLibrary_Class->setInterface(false);
	
	
	m_modelLibrary_Attribute_base_Package->setName("base_Package");
	m_modelLibrary_Attribute_base_Package->setEType(uml::UmlPackage::eInstance()->getPackage_Class());
	m_modelLibrary_Attribute_base_Package->setLowerBound(1);
	m_modelLibrary_Attribute_base_Package->setUpperBound(1);
	m_modelLibrary_Attribute_base_Package->setTransient(false);
	m_modelLibrary_Attribute_base_Package->setVolatile(false);
	m_modelLibrary_Attribute_base_Package->setChangeable(true);
	m_modelLibrary_Attribute_base_Package->setUnsettable(false);
	m_modelLibrary_Attribute_base_Package->setUnique(true);
	m_modelLibrary_Attribute_base_Package->setDerived(false);
	m_modelLibrary_Attribute_base_Package->setOrdered(false);
	m_modelLibrary_Attribute_base_Package->setContainment(false);
	m_modelLibrary_Attribute_base_Package->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_modelLibrary_Attribute_base_Package->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_modelLibrary_Attribute_base_Package->setEOpposite(otherEnd);
	    }
	}
	
	
}

void StandardProfilePackageImpl::initializeProcessContent()
{
	m_process_Class->setName("Process");
	m_process_Class->setAbstract(false);
	m_process_Class->setInterface(false);
	
	
	m_process_Attribute_base_Component->setName("base_Component");
	m_process_Attribute_base_Component->setEType(uml::UmlPackage::eInstance()->getComponent_Class());
	m_process_Attribute_base_Component->setLowerBound(1);
	m_process_Attribute_base_Component->setUpperBound(1);
	m_process_Attribute_base_Component->setTransient(false);
	m_process_Attribute_base_Component->setVolatile(false);
	m_process_Attribute_base_Component->setChangeable(true);
	m_process_Attribute_base_Component->setUnsettable(false);
	m_process_Attribute_base_Component->setUnique(true);
	m_process_Attribute_base_Component->setDerived(false);
	m_process_Attribute_base_Component->setOrdered(false);
	m_process_Attribute_base_Component->setContainment(false);
	m_process_Attribute_base_Component->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_process_Attribute_base_Component->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_process_Attribute_base_Component->setEOpposite(otherEnd);
	    }
	}
	
	
}

void StandardProfilePackageImpl::initializeRealizationContent()
{
	m_realization_Class->setName("Realization");
	m_realization_Class->setAbstract(false);
	m_realization_Class->setInterface(false);
	
	
	m_realization_Attribute_base_Classifier->setName("base_Classifier");
	m_realization_Attribute_base_Classifier->setEType(uml::UmlPackage::eInstance()->getClassifier_Class());
	m_realization_Attribute_base_Classifier->setLowerBound(1);
	m_realization_Attribute_base_Classifier->setUpperBound(1);
	m_realization_Attribute_base_Classifier->setTransient(false);
	m_realization_Attribute_base_Classifier->setVolatile(false);
	m_realization_Attribute_base_Classifier->setChangeable(true);
	m_realization_Attribute_base_Classifier->setUnsettable(false);
	m_realization_Attribute_base_Classifier->setUnique(true);
	m_realization_Attribute_base_Classifier->setDerived(false);
	m_realization_Attribute_base_Classifier->setOrdered(false);
	m_realization_Attribute_base_Classifier->setContainment(false);
	m_realization_Attribute_base_Classifier->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_realization_Attribute_base_Classifier->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_realization_Attribute_base_Classifier->setEOpposite(otherEnd);
	    }
	}
	
	
}

void StandardProfilePackageImpl::initializeRefineContent()
{
	m_refine_Class->setName("Refine");
	m_refine_Class->setAbstract(false);
	m_refine_Class->setInterface(false);
	
	
	m_refine_Attribute_base_Abstraction->setName("base_Abstraction");
	m_refine_Attribute_base_Abstraction->setEType(uml::UmlPackage::eInstance()->getAbstraction_Class());
	m_refine_Attribute_base_Abstraction->setLowerBound(1);
	m_refine_Attribute_base_Abstraction->setUpperBound(1);
	m_refine_Attribute_base_Abstraction->setTransient(false);
	m_refine_Attribute_base_Abstraction->setVolatile(false);
	m_refine_Attribute_base_Abstraction->setChangeable(true);
	m_refine_Attribute_base_Abstraction->setUnsettable(false);
	m_refine_Attribute_base_Abstraction->setUnique(true);
	m_refine_Attribute_base_Abstraction->setDerived(false);
	m_refine_Attribute_base_Abstraction->setOrdered(false);
	m_refine_Attribute_base_Abstraction->setContainment(false);
	m_refine_Attribute_base_Abstraction->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_refine_Attribute_base_Abstraction->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_refine_Attribute_base_Abstraction->setEOpposite(otherEnd);
	    }
	}
	
	
}

void StandardProfilePackageImpl::initializeResponsibilityContent()
{
	m_responsibility_Class->setName("Responsibility");
	m_responsibility_Class->setAbstract(false);
	m_responsibility_Class->setInterface(false);
	
	
	m_responsibility_Attribute_base_Usage->setName("base_Usage");
	m_responsibility_Attribute_base_Usage->setEType(uml::UmlPackage::eInstance()->getUsage_Class());
	m_responsibility_Attribute_base_Usage->setLowerBound(1);
	m_responsibility_Attribute_base_Usage->setUpperBound(1);
	m_responsibility_Attribute_base_Usage->setTransient(false);
	m_responsibility_Attribute_base_Usage->setVolatile(false);
	m_responsibility_Attribute_base_Usage->setChangeable(true);
	m_responsibility_Attribute_base_Usage->setUnsettable(false);
	m_responsibility_Attribute_base_Usage->setUnique(true);
	m_responsibility_Attribute_base_Usage->setDerived(false);
	m_responsibility_Attribute_base_Usage->setOrdered(false);
	m_responsibility_Attribute_base_Usage->setContainment(false);
	m_responsibility_Attribute_base_Usage->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_responsibility_Attribute_base_Usage->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_responsibility_Attribute_base_Usage->setEOpposite(otherEnd);
	    }
	}
	
	
}

void StandardProfilePackageImpl::initializeScriptContent()
{
	m_script_Class->setName("Script");
	m_script_Class->setAbstract(false);
	m_script_Class->setInterface(false);
	
	
	
	
}

void StandardProfilePackageImpl::initializeSendContent()
{
	m_send_Class->setName("Send");
	m_send_Class->setAbstract(false);
	m_send_Class->setInterface(false);
	
	
	m_send_Attribute_base_Usage->setName("base_Usage");
	m_send_Attribute_base_Usage->setEType(uml::UmlPackage::eInstance()->getUsage_Class());
	m_send_Attribute_base_Usage->setLowerBound(1);
	m_send_Attribute_base_Usage->setUpperBound(1);
	m_send_Attribute_base_Usage->setTransient(false);
	m_send_Attribute_base_Usage->setVolatile(false);
	m_send_Attribute_base_Usage->setChangeable(true);
	m_send_Attribute_base_Usage->setUnsettable(false);
	m_send_Attribute_base_Usage->setUnique(true);
	m_send_Attribute_base_Usage->setDerived(false);
	m_send_Attribute_base_Usage->setOrdered(false);
	m_send_Attribute_base_Usage->setContainment(false);
	m_send_Attribute_base_Usage->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_send_Attribute_base_Usage->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_send_Attribute_base_Usage->setEOpposite(otherEnd);
	    }
	}
	
	
}

void StandardProfilePackageImpl::initializeServiceContent()
{
	m_service_Class->setName("Service");
	m_service_Class->setAbstract(false);
	m_service_Class->setInterface(false);
	
	
	m_service_Attribute_base_Component->setName("base_Component");
	m_service_Attribute_base_Component->setEType(uml::UmlPackage::eInstance()->getComponent_Class());
	m_service_Attribute_base_Component->setLowerBound(1);
	m_service_Attribute_base_Component->setUpperBound(1);
	m_service_Attribute_base_Component->setTransient(false);
	m_service_Attribute_base_Component->setVolatile(false);
	m_service_Attribute_base_Component->setChangeable(true);
	m_service_Attribute_base_Component->setUnsettable(false);
	m_service_Attribute_base_Component->setUnique(true);
	m_service_Attribute_base_Component->setDerived(false);
	m_service_Attribute_base_Component->setOrdered(false);
	m_service_Attribute_base_Component->setContainment(false);
	m_service_Attribute_base_Component->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_service_Attribute_base_Component->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_service_Attribute_base_Component->setEOpposite(otherEnd);
	    }
	}
	
	
}

void StandardProfilePackageImpl::initializeSourceContent()
{
	m_source_Class->setName("Source");
	m_source_Class->setAbstract(false);
	m_source_Class->setInterface(false);
	
	
	
	
}

void StandardProfilePackageImpl::initializeSpecificationContent()
{
	m_specification_Class->setName("Specification");
	m_specification_Class->setAbstract(false);
	m_specification_Class->setInterface(false);
	
	
	m_specification_Attribute_base_Classifier->setName("base_Classifier");
	m_specification_Attribute_base_Classifier->setEType(uml::UmlPackage::eInstance()->getClassifier_Class());
	m_specification_Attribute_base_Classifier->setLowerBound(1);
	m_specification_Attribute_base_Classifier->setUpperBound(1);
	m_specification_Attribute_base_Classifier->setTransient(false);
	m_specification_Attribute_base_Classifier->setVolatile(false);
	m_specification_Attribute_base_Classifier->setChangeable(true);
	m_specification_Attribute_base_Classifier->setUnsettable(false);
	m_specification_Attribute_base_Classifier->setUnique(true);
	m_specification_Attribute_base_Classifier->setDerived(false);
	m_specification_Attribute_base_Classifier->setOrdered(false);
	m_specification_Attribute_base_Classifier->setContainment(false);
	m_specification_Attribute_base_Classifier->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_specification_Attribute_base_Classifier->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_specification_Attribute_base_Classifier->setEOpposite(otherEnd);
	    }
	}
	
	
}

void StandardProfilePackageImpl::initializeSubsystemContent()
{
	m_subsystem_Class->setName("Subsystem");
	m_subsystem_Class->setAbstract(false);
	m_subsystem_Class->setInterface(false);
	
	
	m_subsystem_Attribute_base_Component->setName("base_Component");
	m_subsystem_Attribute_base_Component->setEType(uml::UmlPackage::eInstance()->getComponent_Class());
	m_subsystem_Attribute_base_Component->setLowerBound(1);
	m_subsystem_Attribute_base_Component->setUpperBound(1);
	m_subsystem_Attribute_base_Component->setTransient(false);
	m_subsystem_Attribute_base_Component->setVolatile(false);
	m_subsystem_Attribute_base_Component->setChangeable(true);
	m_subsystem_Attribute_base_Component->setUnsettable(false);
	m_subsystem_Attribute_base_Component->setUnique(true);
	m_subsystem_Attribute_base_Component->setDerived(false);
	m_subsystem_Attribute_base_Component->setOrdered(false);
	m_subsystem_Attribute_base_Component->setContainment(false);
	m_subsystem_Attribute_base_Component->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_subsystem_Attribute_base_Component->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_subsystem_Attribute_base_Component->setEOpposite(otherEnd);
	    }
	}
	
	
}

void StandardProfilePackageImpl::initializeSystemModelContent()
{
	m_systemModel_Class->setName("SystemModel");
	m_systemModel_Class->setAbstract(false);
	m_systemModel_Class->setInterface(false);
	
	
	m_systemModel_Attribute_base_Model->setName("base_Model");
	m_systemModel_Attribute_base_Model->setEType(uml::UmlPackage::eInstance()->getModel_Class());
	m_systemModel_Attribute_base_Model->setLowerBound(1);
	m_systemModel_Attribute_base_Model->setUpperBound(1);
	m_systemModel_Attribute_base_Model->setTransient(false);
	m_systemModel_Attribute_base_Model->setVolatile(false);
	m_systemModel_Attribute_base_Model->setChangeable(true);
	m_systemModel_Attribute_base_Model->setUnsettable(false);
	m_systemModel_Attribute_base_Model->setUnique(true);
	m_systemModel_Attribute_base_Model->setDerived(false);
	m_systemModel_Attribute_base_Model->setOrdered(false);
	m_systemModel_Attribute_base_Model->setContainment(false);
	m_systemModel_Attribute_base_Model->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_systemModel_Attribute_base_Model->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_systemModel_Attribute_base_Model->setEOpposite(otherEnd);
	    }
	}
	
	
}

void StandardProfilePackageImpl::initializeTraceContent()
{
	m_trace_Class->setName("Trace");
	m_trace_Class->setAbstract(false);
	m_trace_Class->setInterface(false);
	
	
	m_trace_Attribute_base_Abstraction->setName("base_Abstraction");
	m_trace_Attribute_base_Abstraction->setEType(uml::UmlPackage::eInstance()->getAbstraction_Class());
	m_trace_Attribute_base_Abstraction->setLowerBound(1);
	m_trace_Attribute_base_Abstraction->setUpperBound(1);
	m_trace_Attribute_base_Abstraction->setTransient(false);
	m_trace_Attribute_base_Abstraction->setVolatile(false);
	m_trace_Attribute_base_Abstraction->setChangeable(true);
	m_trace_Attribute_base_Abstraction->setUnsettable(false);
	m_trace_Attribute_base_Abstraction->setUnique(true);
	m_trace_Attribute_base_Abstraction->setDerived(false);
	m_trace_Attribute_base_Abstraction->setOrdered(false);
	m_trace_Attribute_base_Abstraction->setContainment(false);
	m_trace_Attribute_base_Abstraction->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_trace_Attribute_base_Abstraction->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_trace_Attribute_base_Abstraction->setEOpposite(otherEnd);
	    }
	}
	
	
}

void StandardProfilePackageImpl::initializeTypeContent()
{
	m_type_Class->setName("Type");
	m_type_Class->setAbstract(false);
	m_type_Class->setInterface(false);
	
	
	m_type_Attribute_base_Class->setName("base_Class");
	m_type_Attribute_base_Class->setEType(uml::UmlPackage::eInstance()->getClass_Class());
	m_type_Attribute_base_Class->setLowerBound(1);
	m_type_Attribute_base_Class->setUpperBound(1);
	m_type_Attribute_base_Class->setTransient(false);
	m_type_Attribute_base_Class->setVolatile(false);
	m_type_Attribute_base_Class->setChangeable(true);
	m_type_Attribute_base_Class->setUnsettable(false);
	m_type_Attribute_base_Class->setUnique(true);
	m_type_Attribute_base_Class->setDerived(false);
	m_type_Attribute_base_Class->setOrdered(false);
	m_type_Attribute_base_Class->setContainment(false);
	m_type_Attribute_base_Class->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_type_Attribute_base_Class->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_type_Attribute_base_Class->setEOpposite(otherEnd);
	    }
	}
	
	
}

void StandardProfilePackageImpl::initializeUtilityContent()
{
	m_utility_Class->setName("Utility");
	m_utility_Class->setAbstract(false);
	m_utility_Class->setInterface(false);
	
	
	m_utility_Attribute_base_Class->setName("base_Class");
	m_utility_Attribute_base_Class->setEType(uml::UmlPackage::eInstance()->getClass_Class());
	m_utility_Attribute_base_Class->setLowerBound(1);
	m_utility_Attribute_base_Class->setUpperBound(1);
	m_utility_Attribute_base_Class->setTransient(false);
	m_utility_Attribute_base_Class->setVolatile(false);
	m_utility_Attribute_base_Class->setChangeable(true);
	m_utility_Attribute_base_Class->setUnsettable(false);
	m_utility_Attribute_base_Class->setUnique(true);
	m_utility_Attribute_base_Class->setDerived(false);
	m_utility_Attribute_base_Class->setOrdered(false);
	m_utility_Attribute_base_Class->setContainment(false);
	m_utility_Attribute_base_Class->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_utility_Attribute_base_Class->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_utility_Attribute_base_Class->setEOpposite(otherEnd);
	    }
	}
	
	
}

void StandardProfilePackageImpl::initializePackageEDataTypes()
{
	
}
