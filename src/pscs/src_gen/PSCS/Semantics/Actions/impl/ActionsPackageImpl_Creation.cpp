#include "PSCS/Semantics/Actions/impl/ActionsPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EGenericType.hpp"

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
	createCS_DefaultConstructStrategyContent(package, factory);
	createCS_ReadExtentActionActivationContent(package, factory);
	createCS_ReadSelfActionActivationContent(package, factory);
	createCS_RemoveStructuralFeatureValueActionActivationContent(package, factory);
	createCS_SendSignalActionActivationContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void ActionsPackageImpl::createCS_AcceptEventActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_AcceptEventActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_ACCEPTEVENTACTIONACTIVATION_CLASS);
	
	
	
}

void ActionsPackageImpl::createCS_AddStructuralFeatureValueActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_AddStructuralFeatureValueActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS);
	
	
	
}

void ActionsPackageImpl::createCS_CallOperationActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_CallOperationActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_CALLOPERATIONACTIONACTIVATION_CLASS);
	
	
	
}

void ActionsPackageImpl::createCS_ClearStructuralFeatureActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_ClearStructuralFeatureActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS);
	
	
	
}

void ActionsPackageImpl::createCS_ConstructStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_ConstructStrategy_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_CONSTRUCTSTRATEGY_CLASS);
	
	
	
}

void ActionsPackageImpl::createCS_CreateLinkActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_CreateLinkActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_CREATELINKACTIONACTIVATION_CLASS);
	
	
	
}

void ActionsPackageImpl::createCS_CreateObjectActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_CreateObjectActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_CREATEOBJECTACTIONACTIVATION_CLASS);
	
	
	
}

void ActionsPackageImpl::createCS_DefaultConstructStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_DefaultConstructStrategy_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_DEFAULTCONSTRUCTSTRATEGY_CLASS);
	
	m_cS_DefaultConstructStrategy_Attribute_defaultAssociation = factory->createEReference_as_eReferences_in_EClass(m_cS_DefaultConstructStrategy_Class, CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_DEFAULTASSOCIATION);
	m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses = factory->createEReference_as_eReferences_in_EClass(m_cS_DefaultConstructStrategy_Class, CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_GENERATEDREALIZINGCLASSES);
	m_cS_DefaultConstructStrategy_Attribute_locus = factory->createEReference_as_eReferences_in_EClass(m_cS_DefaultConstructStrategy_Class, CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_LOCUS);
	
	
}

void ActionsPackageImpl::createCS_ReadExtentActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_ReadExtentActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_READEXTENTACTIONACTIVATION_CLASS);
	
	
	
}

void ActionsPackageImpl::createCS_ReadSelfActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_ReadSelfActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_READSELFACTIONACTIVATION_CLASS);
	
	
	
}

void ActionsPackageImpl::createCS_RemoveStructuralFeatureValueActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_RemoveStructuralFeatureValueActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS);
	
	
	
}

void ActionsPackageImpl::createCS_SendSignalActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_SendSignalActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_SENDSIGNALACTIONACTIVATION_CLASS);
	
	
	
}

void ActionsPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}
