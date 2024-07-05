#include "PSSM/Semantics/Values/impl/ValuesPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EReference.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EGenericType.hpp"

//depending model packages
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"
//include subpackages 
 
using namespace PSSM::Semantics::Values;

void ValuesPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();

	createSM_OpaqueExpressionEvaluationContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void ValuesPackageImpl::createSM_OpaqueExpressionEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_sM_OpaqueExpressionEvaluation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, SM_OPAQUEEXPRESSIONEVALUATION_CLASS);
	
	m_sM_OpaqueExpressionEvaluation_Attribute_context = factory->createEReference_as_eReferences_in_EClass(m_sM_OpaqueExpressionEvaluation_Class, SM_OPAQUEEXPRESSIONEVALUATION_ATTRIBUTE_CONTEXT);
	m_sM_OpaqueExpressionEvaluation_Attribute_parameterValues = factory->createEReference_as_eReferences_in_EClass(m_sM_OpaqueExpressionEvaluation_Class, SM_OPAQUEEXPRESSIONEVALUATION_ATTRIBUTE_PARAMETERVALUES);
	
	m_sM_OpaqueExpressionEvaluation_Operation_executeExpressionBehavior = factory->createEOperation_as_eOperations_in_EClass(m_sM_OpaqueExpressionEvaluation_Class, SM_OPAQUEEXPRESSIONEVALUATION_OPERATION_EXECUTEEXPRESSIONBEHAVIOR);
	m_sM_OpaqueExpressionEvaluation_Operation_getParameterValue_Parameter = factory->createEOperation_as_eOperations_in_EClass(m_sM_OpaqueExpressionEvaluation_Class, SM_OPAQUEEXPRESSIONEVALUATION_OPERATION_GETPARAMETERVALUE_PARAMETER);
	m_sM_OpaqueExpressionEvaluation_Operation_initialize_EventOccurrence = factory->createEOperation_as_eOperations_in_EClass(m_sM_OpaqueExpressionEvaluation_Class, SM_OPAQUEEXPRESSIONEVALUATION_OPERATION_INITIALIZE_EVENTOCCURRENCE);
	m_sM_OpaqueExpressionEvaluation_Operation_setParameterValue_ParameterValue = factory->createEOperation_as_eOperations_in_EClass(m_sM_OpaqueExpressionEvaluation_Class, SM_OPAQUEEXPRESSIONEVALUATION_OPERATION_SETPARAMETERVALUE_PARAMETERVALUE);
	
}

void ValuesPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}
