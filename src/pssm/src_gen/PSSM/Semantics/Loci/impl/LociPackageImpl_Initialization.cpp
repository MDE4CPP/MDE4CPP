#include "PSSM/Semantics/Loci/impl/LociPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EClass.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"


using namespace PSSM::Semantics::Loci;

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
	m_sM_ExecutionFactory_Class->getESuperTypes()->push_back(fUML::Semantics::Loci::LociPackage::eInstance()->getExecutionFactory_Class());
	m_sM_Locus_Class->getESuperTypes()->push_back(fUML::Semantics::Loci::LociPackage::eInstance()->getLocus_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeSM_ExecutionFactoryContent();
	initializeSM_LocusContent();

	initializePackageEDataTypes();

}

void LociPackageImpl::initializeSM_ExecutionFactoryContent()
{
	m_sM_ExecutionFactory_Class->setName("SM_ExecutionFactory");
	m_sM_ExecutionFactory_Class->setAbstract(false);
	m_sM_ExecutionFactory_Class->setInterface(false);
	
	m_sM_ExecutionFactory_Class->_setID(SM_EXECUTIONFACTORY_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_sM_ExecutionFactory_Operation_instantiateVisitor_Element->setName("instantiateVisitor");
	m_sM_ExecutionFactory_Operation_instantiateVisitor_Element->setEType(fUML::Semantics::Loci::LociPackage::eInstance()->getSemanticVisitor_Class());
	m_sM_ExecutionFactory_Operation_instantiateVisitor_Element->setLowerBound(1);
	m_sM_ExecutionFactory_Operation_instantiateVisitor_Element->setUpperBound(1);
	m_sM_ExecutionFactory_Operation_instantiateVisitor_Element->setUnique(true);
	m_sM_ExecutionFactory_Operation_instantiateVisitor_Element->setOrdered(false);
	
	m_sM_ExecutionFactory_Operation_instantiateVisitor_Element->_setID(SM_EXECUTIONFACTORY_OPERATION_INSTANTIATEVISITOR_ELEMENT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_sM_ExecutionFactory_Operation_instantiateVisitor_Element);
		parameter->setName("element");
		parameter->setEType(uml::umlPackage::eInstance()->getElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void LociPackageImpl::initializeSM_LocusContent()
{
	m_sM_Locus_Class->setName("SM_Locus");
	m_sM_Locus_Class->setAbstract(false);
	m_sM_Locus_Class->setInterface(false);
	
	m_sM_Locus_Class->_setID(SM_LOCUS_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_sM_Locus_Operation_instantiate_Class->setName("instantiate");
	m_sM_Locus_Operation_instantiate_Class->setEType(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
	m_sM_Locus_Operation_instantiate_Class->setLowerBound(1);
	m_sM_Locus_Operation_instantiate_Class->setUpperBound(1);
	m_sM_Locus_Operation_instantiate_Class->setUnique(true);
	m_sM_Locus_Operation_instantiate_Class->setOrdered(false);
	
	m_sM_Locus_Operation_instantiate_Class->_setID(SM_LOCUS_OPERATION_INSTANTIATE_CLASS);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_sM_Locus_Operation_instantiate_Class);
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

