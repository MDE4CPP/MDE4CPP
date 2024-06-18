#include "PSCS/Semantics/Actions/impl/ActionsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EClass.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EDataType.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"


using namespace PSCS::Semantics::Actions;

void ActionsPackageImpl::initializePackageContents()
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
	m_cS_AcceptEventActionActivation_Class->getESuperTypes()->push_back(fUML::Semantics::Actions::ActionsPackage::eInstance()->getAcceptEventActionActivation_Class());
	m_cS_AddStructuralFeatureValueActionActivation_Class->getESuperTypes()->push_back(fUML::Semantics::Actions::ActionsPackage::eInstance()->getAddStructuralFeatureValueActionActivation_Class());
	m_cS_CallOperationActionActivation_Class->getESuperTypes()->push_back(fUML::Semantics::Actions::ActionsPackage::eInstance()->getCallOperationActionActivation_Class());
	m_cS_ClearStructuralFeatureActionActivation_Class->getESuperTypes()->push_back(fUML::Semantics::Actions::ActionsPackage::eInstance()->getClearStructuralFeatureActionActivation_Class());
	m_cS_ConstructStrategy_Class->getESuperTypes()->push_back(fUML::Semantics::Loci::LociPackage::eInstance()->getSemanticStrategy_Class());
	m_cS_CreateLinkActionActivation_Class->getESuperTypes()->push_back(fUML::Semantics::Actions::ActionsPackage::eInstance()->getCreateLinkActionActivation_Class());
	m_cS_CreateObjectActionActivation_Class->getESuperTypes()->push_back(fUML::Semantics::Actions::ActionsPackage::eInstance()->getCreateObjectActionActivation_Class());
	m_cS_DefaultConstructStrategy_Class->getESuperTypes()->push_back(getCS_ConstructStrategy_Class());
	m_cS_ReadExtentActionActivation_Class->getESuperTypes()->push_back(fUML::Semantics::Actions::ActionsPackage::eInstance()->getReadExtentActionActivation_Class());
	m_cS_ReadSelfActionActivation_Class->getESuperTypes()->push_back(fUML::Semantics::Actions::ActionsPackage::eInstance()->getReadSelfActionActivation_Class());
	m_cS_RemoveStructuralFeatureValueActionActivation_Class->getESuperTypes()->push_back(fUML::Semantics::Actions::ActionsPackage::eInstance()->getRemoveStructuralFeatureValueActionActivation_Class());
	m_cS_SendSignalActionActivation_Class->getESuperTypes()->push_back(fUML::Semantics::Actions::ActionsPackage::eInstance()->getSendSignalActionActivation_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeCS_AcceptEventActionActivationContent();
	initializeCS_AddStructuralFeatureValueActionActivationContent();
	initializeCS_CallOperationActionActivationContent();
	initializeCS_ClearStructuralFeatureActionActivationContent();
	initializeCS_ConstructStrategyContent();
	initializeCS_CreateLinkActionActivationContent();
	initializeCS_CreateObjectActionActivationContent();
	initializeCS_DefaultConstructStrategyContent();
	initializeCS_ReadExtentActionActivationContent();
	initializeCS_ReadSelfActionActivationContent();
	initializeCS_RemoveStructuralFeatureValueActionActivationContent();
	initializeCS_SendSignalActionActivationContent();

	initializePackageEDataTypes();

}

void ActionsPackageImpl::initializeCS_AcceptEventActionActivationContent()
{
	m_cS_AcceptEventActionActivation_Class->setName("CS_AcceptEventActionActivation");
	m_cS_AcceptEventActionActivation_Class->setAbstract(false);
	m_cS_AcceptEventActionActivation_Class->setInterface(false);
	
	m_cS_AcceptEventActionActivation_Class->_setID(CS_ACCEPTEVENTACTIONACTIVATION_CLASS);
	
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

void ActionsPackageImpl::initializeCS_AddStructuralFeatureValueActionActivationContent()
{
	m_cS_AddStructuralFeatureValueActionActivation_Class->setName("CS_AddStructuralFeatureValueActionActivation");
	m_cS_AddStructuralFeatureValueActionActivation_Class->setAbstract(false);
	m_cS_AddStructuralFeatureValueActionActivation_Class->setInterface(false);
	
	m_cS_AddStructuralFeatureValueActionActivation_Class->_setID(CS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS);
	
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

void ActionsPackageImpl::initializeCS_CallOperationActionActivationContent()
{
	m_cS_CallOperationActionActivation_Class->setName("CS_CallOperationActionActivation");
	m_cS_CallOperationActionActivation_Class->setAbstract(false);
	m_cS_CallOperationActionActivation_Class->setInterface(false);
	
	m_cS_CallOperationActionActivation_Class->_setID(CS_CALLOPERATIONACTIONACTIVATION_CLASS);
	
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

void ActionsPackageImpl::initializeCS_ClearStructuralFeatureActionActivationContent()
{
	m_cS_ClearStructuralFeatureActionActivation_Class->setName("CS_ClearStructuralFeatureActionActivation");
	m_cS_ClearStructuralFeatureActionActivation_Class->setAbstract(false);
	m_cS_ClearStructuralFeatureActionActivation_Class->setInterface(false);
	
	m_cS_ClearStructuralFeatureActionActivation_Class->_setID(CS_CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS);
	
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

void ActionsPackageImpl::initializeCS_ConstructStrategyContent()
{
	m_cS_ConstructStrategy_Class->setName("CS_ConstructStrategy");
	m_cS_ConstructStrategy_Class->setAbstract(true);
	m_cS_ConstructStrategy_Class->setInterface(false);
	
	m_cS_ConstructStrategy_Class->_setID(CS_CONSTRUCTSTRATEGY_CLASS);
	
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

void ActionsPackageImpl::initializeCS_CreateLinkActionActivationContent()
{
	m_cS_CreateLinkActionActivation_Class->setName("CS_CreateLinkActionActivation");
	m_cS_CreateLinkActionActivation_Class->setAbstract(false);
	m_cS_CreateLinkActionActivation_Class->setInterface(false);
	
	m_cS_CreateLinkActionActivation_Class->_setID(CS_CREATELINKACTIONACTIVATION_CLASS);
	
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

void ActionsPackageImpl::initializeCS_CreateObjectActionActivationContent()
{
	m_cS_CreateObjectActionActivation_Class->setName("CS_CreateObjectActionActivation");
	m_cS_CreateObjectActionActivation_Class->setAbstract(false);
	m_cS_CreateObjectActionActivation_Class->setInterface(false);
	
	m_cS_CreateObjectActionActivation_Class->_setID(CS_CREATEOBJECTACTIONACTIVATION_CLASS);
	
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

void ActionsPackageImpl::initializeCS_DefaultConstructStrategyContent()
{
	m_cS_DefaultConstructStrategy_Class->setName("CS_DefaultConstructStrategy");
	m_cS_DefaultConstructStrategy_Class->setAbstract(false);
	m_cS_DefaultConstructStrategy_Class->setInterface(false);
	
	m_cS_DefaultConstructStrategy_Class->_setID(CS_DEFAULTCONSTRUCTSTRATEGY_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_cS_DefaultConstructStrategy_Attribute_defaultAssociation->setName("defaultAssociation");
	m_cS_DefaultConstructStrategy_Attribute_defaultAssociation->setEType(uml::umlPackage::eInstance()->getAssociation_Class());
	m_cS_DefaultConstructStrategy_Attribute_defaultAssociation->setLowerBound(1);
	m_cS_DefaultConstructStrategy_Attribute_defaultAssociation->setUpperBound(1);
	m_cS_DefaultConstructStrategy_Attribute_defaultAssociation->setTransient(false);
	m_cS_DefaultConstructStrategy_Attribute_defaultAssociation->setVolatile(false);
	m_cS_DefaultConstructStrategy_Attribute_defaultAssociation->setChangeable(true);
	m_cS_DefaultConstructStrategy_Attribute_defaultAssociation->setUnsettable(false);
	m_cS_DefaultConstructStrategy_Attribute_defaultAssociation->setUnique(true);
	m_cS_DefaultConstructStrategy_Attribute_defaultAssociation->setDerived(false);
	m_cS_DefaultConstructStrategy_Attribute_defaultAssociation->setOrdered(false);
	m_cS_DefaultConstructStrategy_Attribute_defaultAssociation->setContainment(true);
	m_cS_DefaultConstructStrategy_Attribute_defaultAssociation->setResolveProxies(true);
	m_cS_DefaultConstructStrategy_Attribute_defaultAssociation->setDefaultValueLiteral("");	
	
	m_cS_DefaultConstructStrategy_Attribute_defaultAssociation->_setID(CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_DEFAULTASSOCIATION);
	m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses->setName("generatedRealizingClasses");
	m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses->setEType(uml::umlPackage::eInstance()->getClass_Class());
	m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses->setLowerBound(0);
	m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses->setUpperBound(-1);
	m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses->setTransient(false);
	m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses->setVolatile(false);
	m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses->setChangeable(true);
	m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses->setUnsettable(false);
	m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses->setUnique(true);
	m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses->setDerived(false);
	m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses->setOrdered(false);
	m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses->setContainment(true);
	m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses->setResolveProxies(true);
	m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses->setDefaultValueLiteral("");	
	
	m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses->_setID(CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_GENERATEDREALIZINGCLASSES);
	m_cS_DefaultConstructStrategy_Attribute_locus->setName("locus");
	m_cS_DefaultConstructStrategy_Attribute_locus->setEType(fUML::Semantics::Loci::LociPackage::eInstance()->getLocus_Class());
	m_cS_DefaultConstructStrategy_Attribute_locus->setLowerBound(1);
	m_cS_DefaultConstructStrategy_Attribute_locus->setUpperBound(1);
	m_cS_DefaultConstructStrategy_Attribute_locus->setTransient(false);
	m_cS_DefaultConstructStrategy_Attribute_locus->setVolatile(false);
	m_cS_DefaultConstructStrategy_Attribute_locus->setChangeable(true);
	m_cS_DefaultConstructStrategy_Attribute_locus->setUnsettable(false);
	m_cS_DefaultConstructStrategy_Attribute_locus->setUnique(true);
	m_cS_DefaultConstructStrategy_Attribute_locus->setDerived(false);
	m_cS_DefaultConstructStrategy_Attribute_locus->setOrdered(false);
	m_cS_DefaultConstructStrategy_Attribute_locus->setContainment(false);
	m_cS_DefaultConstructStrategy_Attribute_locus->setResolveProxies(true);
	m_cS_DefaultConstructStrategy_Attribute_locus->setDefaultValueLiteral("");	
	
	m_cS_DefaultConstructStrategy_Attribute_locus->_setID(CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_LOCUS);
	
	/*
	 * EOperations
	 */
	
}

void ActionsPackageImpl::initializeCS_ReadExtentActionActivationContent()
{
	m_cS_ReadExtentActionActivation_Class->setName("CS_ReadExtentActionActivation");
	m_cS_ReadExtentActionActivation_Class->setAbstract(false);
	m_cS_ReadExtentActionActivation_Class->setInterface(false);
	
	m_cS_ReadExtentActionActivation_Class->_setID(CS_READEXTENTACTIONACTIVATION_CLASS);
	
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

void ActionsPackageImpl::initializeCS_ReadSelfActionActivationContent()
{
	m_cS_ReadSelfActionActivation_Class->setName("CS_ReadSelfActionActivation");
	m_cS_ReadSelfActionActivation_Class->setAbstract(false);
	m_cS_ReadSelfActionActivation_Class->setInterface(false);
	
	m_cS_ReadSelfActionActivation_Class->_setID(CS_READSELFACTIONACTIVATION_CLASS);
	
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

void ActionsPackageImpl::initializeCS_RemoveStructuralFeatureValueActionActivationContent()
{
	m_cS_RemoveStructuralFeatureValueActionActivation_Class->setName("CS_RemoveStructuralFeatureValueActionActivation");
	m_cS_RemoveStructuralFeatureValueActionActivation_Class->setAbstract(false);
	m_cS_RemoveStructuralFeatureValueActionActivation_Class->setInterface(false);
	
	m_cS_RemoveStructuralFeatureValueActionActivation_Class->_setID(CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS);
	
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

void ActionsPackageImpl::initializeCS_SendSignalActionActivationContent()
{
	m_cS_SendSignalActionActivation_Class->setName("CS_SendSignalActionActivation");
	m_cS_SendSignalActionActivation_Class->setAbstract(false);
	m_cS_SendSignalActionActivation_Class->setInterface(false);
	
	m_cS_SendSignalActionActivation_Class->_setID(CS_SENDSIGNALACTIONACTIVATION_CLASS);
	
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

void ActionsPackageImpl::initializePackageEDataTypes()
{
	
}

