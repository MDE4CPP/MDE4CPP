#include "PSCS/Semantics/StructuredClassifiers/impl/StructuredClassifiersPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EReference.hpp"
#include "ecore/EEnumLiteral.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EGenericType.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"


using namespace PSCS::Semantics::StructuredClassifiers;

void StructuredClassifiersPackageImpl::initializePackageContents()
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
	m_cS_DefaultRequestPropagationStrategy_Class->getESuperTypes()->push_back(getCS_RequestPropagationStrategy_Class());
	m_cS_DispatchOperationOfInterfaceStrategy_Class->getESuperTypes()->push_back(fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getRedefinitionBasedDispatchStrategy_Class());
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Class->getESuperTypes()->push_back(getCS_StructuralFeatureOfInterfaceAccessStrategy_Class());
	m_cS_RequestPropagationStrategy_Class->getESuperTypes()->push_back(fUML::Semantics::Loci::LociPackage::eInstance()->getSemanticStrategy_Class());
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Class->getESuperTypes()->push_back(fUML::Semantics::Loci::LociPackage::eInstance()->getSemanticStrategy_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeCS_DefaultRequestPropagationStrategyContent();
	initializeCS_DispatchOperationOfInterfaceStrategyContent();
	initializeCS_NameBased_StructuralFeatureOfInterfaceAccessStrategyContent();
	initializeCS_RequestPropagationStrategyContent();
	initializeCS_StructuralFeatureOfInterfaceAccessStrategyContent();

	initializePackageEDataTypes();

}

void StructuredClassifiersPackageImpl::initializeCS_DefaultRequestPropagationStrategyContent()
{
	m_cS_DefaultRequestPropagationStrategy_Class->setName("CS_DefaultRequestPropagationStrategy");
	m_cS_DefaultRequestPropagationStrategy_Class->setAbstract(false);
	m_cS_DefaultRequestPropagationStrategy_Class->setInterface(false);
	
	m_cS_DefaultRequestPropagationStrategy_Class->_setID(CS_DEFAULTREQUESTPROPAGATIONSTRATEGY_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void StructuredClassifiersPackageImpl::initializeCS_DispatchOperationOfInterfaceStrategyContent()
{
	m_cS_DispatchOperationOfInterfaceStrategy_Class->setName("CS_DispatchOperationOfInterfaceStrategy");
	m_cS_DispatchOperationOfInterfaceStrategy_Class->setAbstract(false);
	m_cS_DispatchOperationOfInterfaceStrategy_Class->setInterface(false);
	
	m_cS_DispatchOperationOfInterfaceStrategy_Class->_setID(CS_DISPATCHOPERATIONOFINTERFACESTRATEGY_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void StructuredClassifiersPackageImpl::initializeCS_NameBased_StructuralFeatureOfInterfaceAccessStrategyContent()
{
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Class->setName("CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy");
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Class->setAbstract(false);
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Class->setInterface(false);
	
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Class->_setID(CS_NAMEBASED_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void StructuredClassifiersPackageImpl::initializeCS_RequestPropagationStrategyContent()
{
	m_cS_RequestPropagationStrategy_Class->setName("CS_RequestPropagationStrategy");
	m_cS_RequestPropagationStrategy_Class->setAbstract(true);
	m_cS_RequestPropagationStrategy_Class->setInterface(false);
	
	m_cS_RequestPropagationStrategy_Class->_setID(CS_REQUESTPROPAGATIONSTRATEGY_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_cS_RequestPropagationStrategy_Operation_getName->setName("getName");
	m_cS_RequestPropagationStrategy_Operation_getName->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_cS_RequestPropagationStrategy_Operation_getName->setLowerBound(1);
	m_cS_RequestPropagationStrategy_Operation_getName->setUpperBound(1);
	m_cS_RequestPropagationStrategy_Operation_getName->setUnique(true);
	m_cS_RequestPropagationStrategy_Operation_getName->setOrdered(false);
	
	m_cS_RequestPropagationStrategy_Operation_getName->_setID(CS_REQUESTPROPAGATIONSTRATEGY_OPERATION_GETNAME);
	
	
	
}

void StructuredClassifiersPackageImpl::initializeCS_StructuralFeatureOfInterfaceAccessStrategyContent()
{
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Class->setName("CS_StructuralFeatureOfInterfaceAccessStrategy");
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Class->setAbstract(true);
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Class->setInterface(false);
	
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Class->_setID(CS_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName->setName("getName");
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName->setLowerBound(1);
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName->setUpperBound(1);
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName->setUnique(true);
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName->setOrdered(false);
	
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName->_setID(CS_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_OPERATION_GETNAME);
	
	
	
}

void StructuredClassifiersPackageImpl::initializePackageEDataTypes()
{
	m_cS_LinkKind_Class->setName("CS_LinkKind");
	
}

