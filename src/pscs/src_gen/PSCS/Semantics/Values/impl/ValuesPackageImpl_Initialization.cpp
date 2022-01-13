#include "PSCS/Semantics/Values/impl/ValuesPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EOperation.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EGenericType.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "fUML/fUMLPackage.hpp"


using namespace PSCS::Semantics::Values;

void ValuesPackageImpl::initializePackageContents()
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
	m_cS_OpaqueExpressionEvaluation_Class->getESuperTypes()->push_back(fUML::Semantics::Values::ValuesPackage::eInstance()->getEvaluation_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeCS_OpaqueExpressionEvaluationContent();

	initializePackageEDataTypes();

}

void ValuesPackageImpl::initializeCS_OpaqueExpressionEvaluationContent()
{
	m_cS_OpaqueExpressionEvaluation_Class->setName("CS_OpaqueExpressionEvaluation");
	m_cS_OpaqueExpressionEvaluation_Class->setAbstract(false);
	m_cS_OpaqueExpressionEvaluation_Class->setInterface(false);
	
	
	
	m_cS_OpaqueExpressionEvaluation_Operation_evaluate->setName("evaluate");
	m_cS_OpaqueExpressionEvaluation_Operation_evaluate->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_cS_OpaqueExpressionEvaluation_Operation_evaluate->setLowerBound(0);
	m_cS_OpaqueExpressionEvaluation_Operation_evaluate->setUpperBound(1);
	m_cS_OpaqueExpressionEvaluation_Operation_evaluate->setUnique(true);
	m_cS_OpaqueExpressionEvaluation_Operation_evaluate->setOrdered(false);
	
	m_cS_OpaqueExpressionEvaluation_Operation_executeExpressionBehavior->setName("executeExpressionBehavior");
	m_cS_OpaqueExpressionEvaluation_Operation_executeExpressionBehavior->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_cS_OpaqueExpressionEvaluation_Operation_executeExpressionBehavior->setLowerBound(0);
	m_cS_OpaqueExpressionEvaluation_Operation_executeExpressionBehavior->setUpperBound(-1);
	m_cS_OpaqueExpressionEvaluation_Operation_executeExpressionBehavior->setUnique(true);
	m_cS_OpaqueExpressionEvaluation_Operation_executeExpressionBehavior->setOrdered(false);
	
	
}

void ValuesPackageImpl::initializePackageEDataTypes()
{
	
}

