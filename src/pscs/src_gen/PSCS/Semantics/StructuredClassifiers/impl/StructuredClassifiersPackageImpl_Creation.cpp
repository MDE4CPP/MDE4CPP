#include "PSCS/Semantics/StructuredClassifiers/impl/StructuredClassifiersPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EEnum.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EEnumLiteral.hpp"
#include "ecore/EGenericType.hpp"

//depending model packages
#include "PSCS/PSCSPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"
//include subpackages 
 
using namespace PSCS::Semantics::StructuredClassifiers;

void StructuredClassifiersPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();

	createCS_DefaultRequestPropagationStrategyContent(package, factory);
	createCS_DispatchOperationOfInterfaceStrategyContent(package, factory);
	createCS_NameBased_StructuralFeatureOfInterfaceAccessStrategyContent(package, factory);
	createCS_RequestPropagationStrategyContent(package, factory);
	createCS_StructuralFeatureOfInterfaceAccessStrategyContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void StructuredClassifiersPackageImpl::createCS_DefaultRequestPropagationStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_DefaultRequestPropagationStrategy_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_DEFAULTREQUESTPROPAGATIONSTRATEGY_CLASS);
	
	
	
}

void StructuredClassifiersPackageImpl::createCS_DispatchOperationOfInterfaceStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_DispatchOperationOfInterfaceStrategy_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_DISPATCHOPERATIONOFINTERFACESTRATEGY_CLASS);
	
	
	
}

void StructuredClassifiersPackageImpl::createCS_NameBased_StructuralFeatureOfInterfaceAccessStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_NAMEBASED_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_CLASS);
	
	
	
}

void StructuredClassifiersPackageImpl::createCS_RequestPropagationStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_RequestPropagationStrategy_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_REQUESTPROPAGATIONSTRATEGY_CLASS);
	
	
	m_cS_RequestPropagationStrategy_Operation_getName = factory->createEOperation_as_eOperations_in_EClass(m_cS_RequestPropagationStrategy_Class, CS_REQUESTPROPAGATIONSTRATEGY_OPERATION_GETNAME);
	
}

void StructuredClassifiersPackageImpl::createCS_StructuralFeatureOfInterfaceAccessStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_CLASS);
	
	
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName = factory->createEOperation_as_eOperations_in_EClass(m_cS_StructuralFeatureOfInterfaceAccessStrategy_Class, CS_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_OPERATION_GETNAME);
	
}

void StructuredClassifiersPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_LinkKind_Class = factory->createEEnum_as_eClassifiers_in_EPackage(package, CS_LINKKIND_CLASS);
	
}
