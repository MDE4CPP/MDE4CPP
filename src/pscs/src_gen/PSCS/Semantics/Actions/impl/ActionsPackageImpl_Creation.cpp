#include "PSCS/Semantics/Actions/impl/ActionsPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EClass.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

//depending model packages
#include "PSCS/PSCSPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"
//include subpackages 
 
using namespace PSCS::Semantics::Actions;

void ActionsPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();

	createCS_AcceptEventActionActivationContent(package, factory);
	createCS_AddStructuralFeatureValueActionActivationContent(package, factory);
	createCS_CallOperationActionActivationContent(package, factory);
	createCS_ClearStructuralFeatureActionActivationContent(package, factory);
	createCS_ConstructStrategyContent(package, factory);
	createCS_CreateLinkActionActivationContent(package, factory);
	createCS_CreateObjectActionActivationContent(package, factory);
	createCS_ReadExtentActionActivationContent(package, factory);
	createCS_ReadSelfActionActivationContent(package, factory);
	createCS_RemoveStructuralFeatureValueActionActivationContent(package, factory);
	createCS_SendSignalActionActivationContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void ActionsPackageImpl::createCS_AcceptEventActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_AcceptEventActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_ACCEPTEVENTACTIONACTIVATION_CLASS);
	
	
	m_cS_AcceptEventActionActivation_Operation_accept_EventOccurrence = factory->createEOperation_as_eOperations_in_EClass(m_cS_AcceptEventActionActivation_Class, CS_ACCEPTEVENTACTIONACTIVATION_OPERATION_ACCEPT_EVENTOCCURRENCE);
	
}

void ActionsPackageImpl::createCS_AddStructuralFeatureValueActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_AddStructuralFeatureValueActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS);
	
	
	m_cS_AddStructuralFeatureValueActionActivation_Operation_doAction = factory->createEOperation_as_eOperations_in_EClass(m_cS_AddStructuralFeatureValueActionActivation_Class, CS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_OPERATION_DOACTION);
	m_cS_AddStructuralFeatureValueActionActivation_Operation_doActionDefault = factory->createEOperation_as_eOperations_in_EClass(m_cS_AddStructuralFeatureValueActionActivation_Class, CS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_OPERATION_DOACTIONDEFAULT);
	
}

void ActionsPackageImpl::createCS_CallOperationActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_CallOperationActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_CALLOPERATIONACTIONACTIVATION_CLASS);
	
	
	m_cS_CallOperationActionActivation_Operation__isCreate_Operation = factory->createEOperation_as_eOperations_in_EClass(m_cS_CallOperationActionActivation_Class, CS_CALLOPERATIONACTIONACTIVATION_OPERATION__ISCREATE_OPERATION);
	m_cS_CallOperationActionActivation_Operation_doAction = factory->createEOperation_as_eOperations_in_EClass(m_cS_CallOperationActionActivation_Class, CS_CALLOPERATIONACTIONACTIVATION_OPERATION_DOACTION);
	m_cS_CallOperationActionActivation_Operation_doCall_ParameterValue = factory->createEOperation_as_eOperations_in_EClass(m_cS_CallOperationActionActivation_Class, CS_CALLOPERATIONACTIONACTIVATION_OPERATION_DOCALL_PARAMETERVALUE);
	m_cS_CallOperationActionActivation_Operation_isCreate_Operation = factory->createEOperation_as_eOperations_in_EClass(m_cS_CallOperationActionActivation_Class, CS_CALLOPERATIONACTIONACTIVATION_OPERATION_ISCREATE_OPERATION);
	m_cS_CallOperationActionActivation_Operation_isOperationProvided_Port_Operation = factory->createEOperation_as_eOperations_in_EClass(m_cS_CallOperationActionActivation_Class, CS_CALLOPERATIONACTIONACTIVATION_OPERATION_ISOPERATIONPROVIDED_PORT_OPERATION);
	m_cS_CallOperationActionActivation_Operation_isOperationRequired_Port_Operation = factory->createEOperation_as_eOperations_in_EClass(m_cS_CallOperationActionActivation_Class, CS_CALLOPERATIONACTIONACTIVATION_OPERATION_ISOPERATIONREQUIRED_PORT_OPERATION);
	
}

void ActionsPackageImpl::createCS_ClearStructuralFeatureActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_ClearStructuralFeatureActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS);
	
	
	m_cS_ClearStructuralFeatureActionActivation_Operation_doAction = factory->createEOperation_as_eOperations_in_EClass(m_cS_ClearStructuralFeatureActionActivation_Class, CS_CLEARSTRUCTURALFEATUREACTIONACTIVATION_OPERATION_DOACTION);
	m_cS_ClearStructuralFeatureActionActivation_Operation_getLinksToDestroy_Element_StructuralFeature = factory->createEOperation_as_eOperations_in_EClass(m_cS_ClearStructuralFeatureActionActivation_Class, CS_CLEARSTRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETLINKSTODESTROY_ELEMENT_STRUCTURALFEATURE);
	m_cS_ClearStructuralFeatureActionActivation_Operation_getPotentialLinkEnds_PSCS_Object_StructuralFeature = factory->createEOperation_as_eOperations_in_EClass(m_cS_ClearStructuralFeatureActionActivation_Class, CS_CLEARSTRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETPOTENTIALLINKENDS_PSCS_OBJECT_STRUCTURALFEATURE);
	
}

void ActionsPackageImpl::createCS_ConstructStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_ConstructStrategy_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_CONSTRUCTSTRATEGY_CLASS);
	
	
	m_cS_ConstructStrategy_Operation_construct_Operation_PSCS_Object = factory->createEOperation_as_eOperations_in_EClass(m_cS_ConstructStrategy_Class, CS_CONSTRUCTSTRATEGY_OPERATION_CONSTRUCT_OPERATION_PSCS_OBJECT);
	m_cS_ConstructStrategy_Operation_getName = factory->createEOperation_as_eOperations_in_EClass(m_cS_ConstructStrategy_Class, CS_CONSTRUCTSTRATEGY_OPERATION_GETNAME);
	
}

void ActionsPackageImpl::createCS_CreateLinkActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_CreateLinkActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_CREATELINKACTIONACTIVATION_CLASS);
	
	
	m_cS_CreateLinkActionActivation_Operation_doAction = factory->createEOperation_as_eOperations_in_EClass(m_cS_CreateLinkActionActivation_Class, CS_CREATELINKACTIONACTIVATION_OPERATION_DOACTION);
	
}

void ActionsPackageImpl::createCS_CreateObjectActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_CreateObjectActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_CREATEOBJECTACTIONACTIVATION_CLASS);
	
	
	m_cS_CreateObjectActionActivation_Operation_doAction = factory->createEOperation_as_eOperations_in_EClass(m_cS_CreateObjectActionActivation_Class, CS_CREATEOBJECTACTIONACTIVATION_OPERATION_DOACTION);
	
}

void ActionsPackageImpl::createCS_ReadExtentActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_ReadExtentActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_READEXTENTACTIONACTIVATION_CLASS);
	
	
	m_cS_ReadExtentActionActivation_Operation_doAction = factory->createEOperation_as_eOperations_in_EClass(m_cS_ReadExtentActionActivation_Class, CS_READEXTENTACTIONACTIVATION_OPERATION_DOACTION);
	
}

void ActionsPackageImpl::createCS_ReadSelfActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_ReadSelfActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_READSELFACTIONACTIVATION_CLASS);
	
	
	m_cS_ReadSelfActionActivation_Operation_doAction = factory->createEOperation_as_eOperations_in_EClass(m_cS_ReadSelfActionActivation_Class, CS_READSELFACTIONACTIVATION_OPERATION_DOACTION);
	
}

void ActionsPackageImpl::createCS_RemoveStructuralFeatureValueActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_RemoveStructuralFeatureValueActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS);
	
	
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_doAction = factory->createEOperation_as_eOperations_in_EClass(m_cS_RemoveStructuralFeatureValueActionActivation_Class, CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_OPERATION_DOACTION);
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_Element_EJavaObject = factory->createEOperation_as_eOperations_in_EClass(m_cS_RemoveStructuralFeatureValueActionActivation_Class, CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_OPERATION_GETLINKSTODESTROY_ELEMENT_EJAVAOBJECT);
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getPotentialLinkEnds_PSCS_Object_StructuralFeature = factory->createEOperation_as_eOperations_in_EClass(m_cS_RemoveStructuralFeatureValueActionActivation_Class, CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_OPERATION_GETPOTENTIALLINKENDS_PSCS_OBJECT_STRUCTURALFEATURE);
	
}

void ActionsPackageImpl::createCS_SendSignalActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_SendSignalActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_SENDSIGNALACTIONACTIVATION_CLASS);
	
	
	m_cS_SendSignalActionActivation_Operation_doAction = factory->createEOperation_as_eOperations_in_EClass(m_cS_SendSignalActionActivation_Class, CS_SENDSIGNALACTIONACTIVATION_OPERATION_DOACTION);
	
}

void ActionsPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}
