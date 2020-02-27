#include "Values/impl/ValuesPackageImpl.hpp"

// metametamodel factory
#include "ecore/EcoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

//depending model packages
#include "fUML/FUMLPackage.hpp"

using namespace Values;

void ValuesPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::EcoreFactory> factory = ecore::EcoreFactory::eInstance();

	createCS_OpaqueExpressionEvaluationContent(package, factory);

	createPackageEDataTypes(package, factory);
}

void ValuesPackageImpl::createCS_OpaqueExpressionEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_cS_OpaqueExpressionEvaluation_Class = factory->createEClass_in_EPackage(package, CS_OPAQUEEXPRESSIONEVALUATION_CLASS);
	
	
	m_cS_OpaqueExpressionEvaluation_Operation_evaluate = factory->createEOperation_in_EContainingClass(m_cS_OpaqueExpressionEvaluation_Class, CS_OPAQUEEXPRESSIONEVALUATION_OPERATION_EVALUATE);
	m_cS_OpaqueExpressionEvaluation_Operation_executeExpressionBehavior = factory->createEOperation_in_EContainingClass(m_cS_OpaqueExpressionEvaluation_Class, CS_OPAQUEEXPRESSIONEVALUATION_OPERATION_EXECUTEEXPRESSIONBEHAVIOR);
	
}

void ValuesPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	
}
