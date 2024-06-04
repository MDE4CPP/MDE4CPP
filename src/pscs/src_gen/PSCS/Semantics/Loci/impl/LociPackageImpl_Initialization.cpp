#include "PSCS/Semantics/Loci/impl/LociPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EReference.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"


using namespace PSCS::Semantics::Loci;

void LociPackageImpl::initializePackageContents()
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
	m_cS_ExecutionFactory_Class->getESuperTypes()->push_back(fUML::Semantics::Loci::LociPackage::eInstance()->getExecutionFactory_Class());
	m_cS_Executor_Class->getESuperTypes()->push_back(fUML::Semantics::Loci::LociPackage::eInstance()->getExecutor_Class());
	m_cS_Locus_Class->getESuperTypes()->push_back(fUML::Semantics::Loci::LociPackage::eInstance()->getLocus_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeCS_ExecutionFactoryContent();
	initializeCS_ExecutorContent();
	initializeCS_LocusContent();

	initializePackageEDataTypes();

}

void LociPackageImpl::initializeCS_ExecutionFactoryContent()
{
	m_cS_ExecutionFactory_Class->setName("CS_ExecutionFactory");
	m_cS_ExecutionFactory_Class->setAbstract(false);
	m_cS_ExecutionFactory_Class->setInterface(false);
	
	m_cS_ExecutionFactory_Class->_setID(CS_EXECUTIONFACTORY_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_cS_ExecutionFactory_Attribute_appliedProfiles->setName("appliedProfiles");
	m_cS_ExecutionFactory_Attribute_appliedProfiles->setEType(uml::umlPackage::eInstance()->getPackage_Class());
	m_cS_ExecutionFactory_Attribute_appliedProfiles->setLowerBound(0);
	m_cS_ExecutionFactory_Attribute_appliedProfiles->setUpperBound(-1);
	m_cS_ExecutionFactory_Attribute_appliedProfiles->setTransient(false);
	m_cS_ExecutionFactory_Attribute_appliedProfiles->setVolatile(false);
	m_cS_ExecutionFactory_Attribute_appliedProfiles->setChangeable(true);
	m_cS_ExecutionFactory_Attribute_appliedProfiles->setUnsettable(false);
	m_cS_ExecutionFactory_Attribute_appliedProfiles->setUnique(true);
	m_cS_ExecutionFactory_Attribute_appliedProfiles->setDerived(false);
	m_cS_ExecutionFactory_Attribute_appliedProfiles->setOrdered(false);
	m_cS_ExecutionFactory_Attribute_appliedProfiles->setContainment(false);
	m_cS_ExecutionFactory_Attribute_appliedProfiles->setResolveProxies(true);
	m_cS_ExecutionFactory_Attribute_appliedProfiles->setDefaultValueLiteral("");	
	
	m_cS_ExecutionFactory_Attribute_appliedProfiles->_setID(CS_EXECUTIONFACTORY_ATTRIBUTE_APPLIEDPROFILES);
	
	/*
	 * EOperations
	 */
	m_cS_ExecutionFactory_Operation_getStereotypeApplication_Class_Element->setName("getStereotypeApplication");
	m_cS_ExecutionFactory_Operation_getStereotypeApplication_Class_Element->setEType(uml::umlPackage::eInstance()->getElement_Class());
	m_cS_ExecutionFactory_Operation_getStereotypeApplication_Class_Element->setLowerBound(1);
	m_cS_ExecutionFactory_Operation_getStereotypeApplication_Class_Element->setUpperBound(1);
	m_cS_ExecutionFactory_Operation_getStereotypeApplication_Class_Element->setUnique(true);
	m_cS_ExecutionFactory_Operation_getStereotypeApplication_Class_Element->setOrdered(false);
	
	m_cS_ExecutionFactory_Operation_getStereotypeApplication_Class_Element->_setID(CS_EXECUTIONFACTORY_OPERATION_GETSTEREOTYPEAPPLICATION_CLASS_ELEMENT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_ExecutionFactory_Operation_getStereotypeApplication_Class_Element);
		parameter->setName("stereotype");
		parameter->setEType(uml::umlPackage::eInstance()->getClass_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_ExecutionFactory_Operation_getStereotypeApplication_Class_Element);
		parameter->setName("element");
		parameter->setEType(uml::umlPackage::eInstance()->getElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_ExecutionFactory_Operation_getStereotypeClass_EString_EString->setName("getStereotypeClass");
	m_cS_ExecutionFactory_Operation_getStereotypeClass_EString_EString->setEType(uml::umlPackage::eInstance()->getClassifier_Class());
	m_cS_ExecutionFactory_Operation_getStereotypeClass_EString_EString->setLowerBound(1);
	m_cS_ExecutionFactory_Operation_getStereotypeClass_EString_EString->setUpperBound(1);
	m_cS_ExecutionFactory_Operation_getStereotypeClass_EString_EString->setUnique(true);
	m_cS_ExecutionFactory_Operation_getStereotypeClass_EString_EString->setOrdered(false);
	
	m_cS_ExecutionFactory_Operation_getStereotypeClass_EString_EString->_setID(CS_EXECUTIONFACTORY_OPERATION_GETSTEREOTYPECLASS_ESTRING_ESTRING);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_ExecutionFactory_Operation_getStereotypeClass_EString_EString);
		parameter->setName("profileName");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_ExecutionFactory_Operation_getStereotypeClass_EString_EString);
		parameter->setName("stereotypeName");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_ExecutionFactory_Operation_instantiateVisitor_Element->setName("instantiateVisitor");
	m_cS_ExecutionFactory_Operation_instantiateVisitor_Element->setEType(fUML::Semantics::Loci::LociPackage::eInstance()->getSemanticVisitor_Class());
	m_cS_ExecutionFactory_Operation_instantiateVisitor_Element->setLowerBound(1);
	m_cS_ExecutionFactory_Operation_instantiateVisitor_Element->setUpperBound(1);
	m_cS_ExecutionFactory_Operation_instantiateVisitor_Element->setUnique(true);
	m_cS_ExecutionFactory_Operation_instantiateVisitor_Element->setOrdered(false);
	
	m_cS_ExecutionFactory_Operation_instantiateVisitor_Element->_setID(CS_EXECUTIONFACTORY_OPERATION_INSTANTIATEVISITOR_ELEMENT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_ExecutionFactory_Operation_instantiateVisitor_Element);
		parameter->setName("element");
		parameter->setEType(uml::umlPackage::eInstance()->getElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void LociPackageImpl::initializeCS_ExecutorContent()
{
	m_cS_Executor_Class->setName("CS_Executor");
	m_cS_Executor_Class->setAbstract(false);
	m_cS_Executor_Class->setInterface(false);
	
	m_cS_Executor_Class->_setID(CS_EXECUTOR_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_cS_Executor_Operation_start_Class_ParameterValue->setName("start");
	m_cS_Executor_Operation_start_Class_ParameterValue->setEType(uml::umlPackage::eInstance()->getElement_Class());
	m_cS_Executor_Operation_start_Class_ParameterValue->setLowerBound(1);
	m_cS_Executor_Operation_start_Class_ParameterValue->setUpperBound(1);
	m_cS_Executor_Operation_start_Class_ParameterValue->setUnique(true);
	m_cS_Executor_Operation_start_Class_ParameterValue->setOrdered(true);
	
	m_cS_Executor_Operation_start_Class_ParameterValue->_setID(CS_EXECUTOR_OPERATION_START_CLASS_PARAMETERVALUE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Executor_Operation_start_Class_ParameterValue);
		parameter->setName("type");
		parameter->setEType(uml::umlPackage::eInstance()->getClass_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Executor_Operation_start_Class_ParameterValue);
		parameter->setName("inputs");
		parameter->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getParameterValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void LociPackageImpl::initializeCS_LocusContent()
{
	m_cS_Locus_Class->setName("CS_Locus");
	m_cS_Locus_Class->setAbstract(false);
	m_cS_Locus_Class->setInterface(false);
	
	m_cS_Locus_Class->_setID(CS_LOCUS_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_cS_Locus_Operation_instantiate_Class->setName("instantiate");
	m_cS_Locus_Operation_instantiate_Class->setEType(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
	m_cS_Locus_Operation_instantiate_Class->setLowerBound(1);
	m_cS_Locus_Operation_instantiate_Class->setUpperBound(1);
	m_cS_Locus_Operation_instantiate_Class->setUnique(true);
	m_cS_Locus_Operation_instantiate_Class->setOrdered(false);
	
	m_cS_Locus_Operation_instantiate_Class->_setID(CS_LOCUS_OPERATION_INSTANTIATE_CLASS);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Locus_Operation_instantiate_Class);
		parameter->setName("type");
		parameter->setEType(uml::umlPackage::eInstance()->getClass_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void LociPackageImpl::initializePackageEDataTypes()
{
	
}

