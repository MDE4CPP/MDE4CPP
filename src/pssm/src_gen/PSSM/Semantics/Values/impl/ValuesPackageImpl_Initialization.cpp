#include "PSSM/Semantics/Values/impl/ValuesPackageImpl.hpp"

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

#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"


using namespace PSSM::Semantics::Values;

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
	

 	// Initialize classes and features; add operations and parameters
	initializeSM_OpaqueExpressionEvaluationContent();

	initializePackageEDataTypes();

}

void ValuesPackageImpl::initializeSM_OpaqueExpressionEvaluationContent()
{
	m_sM_OpaqueExpressionEvaluation_Class->setName("SM_OpaqueExpressionEvaluation");
	m_sM_OpaqueExpressionEvaluation_Class->setAbstract(false);
	m_sM_OpaqueExpressionEvaluation_Class->setInterface(false);
	
	m_sM_OpaqueExpressionEvaluation_Class->_setID(SM_OPAQUEEXPRESSIONEVALUATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_sM_OpaqueExpressionEvaluation_Attribute_context->setName("context");
	m_sM_OpaqueExpressionEvaluation_Attribute_context->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getParameterValue_Class());
	m_sM_OpaqueExpressionEvaluation_Attribute_context->setLowerBound(0);
	m_sM_OpaqueExpressionEvaluation_Attribute_context->setUpperBound(1);
	m_sM_OpaqueExpressionEvaluation_Attribute_context->setTransient(false);
	m_sM_OpaqueExpressionEvaluation_Attribute_context->setVolatile(false);
	m_sM_OpaqueExpressionEvaluation_Attribute_context->setChangeable(true);
	m_sM_OpaqueExpressionEvaluation_Attribute_context->setUnsettable(false);
	m_sM_OpaqueExpressionEvaluation_Attribute_context->setUnique(true);
	m_sM_OpaqueExpressionEvaluation_Attribute_context->setDerived(false);
	m_sM_OpaqueExpressionEvaluation_Attribute_context->setOrdered(false);
	m_sM_OpaqueExpressionEvaluation_Attribute_context->setContainment(false);
	m_sM_OpaqueExpressionEvaluation_Attribute_context->setResolveProxies(true);
	m_sM_OpaqueExpressionEvaluation_Attribute_context->setDefaultValueLiteral("");	
	
	m_sM_OpaqueExpressionEvaluation_Attribute_context->_setID(SM_OPAQUEEXPRESSIONEVALUATION_ATTRIBUTE_CONTEXT);
	m_sM_OpaqueExpressionEvaluation_Attribute_parameterValues->setName("parameterValues");
	m_sM_OpaqueExpressionEvaluation_Attribute_parameterValues->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getParameterValue_Class());
	m_sM_OpaqueExpressionEvaluation_Attribute_parameterValues->setLowerBound(0);
	m_sM_OpaqueExpressionEvaluation_Attribute_parameterValues->setUpperBound(-1);
	m_sM_OpaqueExpressionEvaluation_Attribute_parameterValues->setTransient(false);
	m_sM_OpaqueExpressionEvaluation_Attribute_parameterValues->setVolatile(false);
	m_sM_OpaqueExpressionEvaluation_Attribute_parameterValues->setChangeable(true);
	m_sM_OpaqueExpressionEvaluation_Attribute_parameterValues->setUnsettable(false);
	m_sM_OpaqueExpressionEvaluation_Attribute_parameterValues->setUnique(true);
	m_sM_OpaqueExpressionEvaluation_Attribute_parameterValues->setDerived(false);
	m_sM_OpaqueExpressionEvaluation_Attribute_parameterValues->setOrdered(false);
	m_sM_OpaqueExpressionEvaluation_Attribute_parameterValues->setContainment(false);
	m_sM_OpaqueExpressionEvaluation_Attribute_parameterValues->setResolveProxies(true);
	m_sM_OpaqueExpressionEvaluation_Attribute_parameterValues->setDefaultValueLiteral("");	
	
	m_sM_OpaqueExpressionEvaluation_Attribute_parameterValues->_setID(SM_OPAQUEEXPRESSIONEVALUATION_ATTRIBUTE_PARAMETERVALUES);
	
	/*
	 * EOperations
	 */
	m_sM_OpaqueExpressionEvaluation_Operation_executeExpressionBehavior->setName("executeExpressionBehavior");
	m_sM_OpaqueExpressionEvaluation_Operation_executeExpressionBehavior->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_sM_OpaqueExpressionEvaluation_Operation_executeExpressionBehavior->setLowerBound(0);
	m_sM_OpaqueExpressionEvaluation_Operation_executeExpressionBehavior->setUpperBound(-1);
	m_sM_OpaqueExpressionEvaluation_Operation_executeExpressionBehavior->setUnique(true);
	m_sM_OpaqueExpressionEvaluation_Operation_executeExpressionBehavior->setOrdered(false);
	
	m_sM_OpaqueExpressionEvaluation_Operation_executeExpressionBehavior->_setID(SM_OPAQUEEXPRESSIONEVALUATION_OPERATION_EXECUTEEXPRESSIONBEHAVIOR);
	
	
	m_sM_OpaqueExpressionEvaluation_Operation_getParameterValue_Parameter->setName("getParameterValue");
	m_sM_OpaqueExpressionEvaluation_Operation_getParameterValue_Parameter->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getParameterValue_Class());
	m_sM_OpaqueExpressionEvaluation_Operation_getParameterValue_Parameter->setLowerBound(1);
	m_sM_OpaqueExpressionEvaluation_Operation_getParameterValue_Parameter->setUpperBound(1);
	m_sM_OpaqueExpressionEvaluation_Operation_getParameterValue_Parameter->setUnique(true);
	m_sM_OpaqueExpressionEvaluation_Operation_getParameterValue_Parameter->setOrdered(false);
	
	m_sM_OpaqueExpressionEvaluation_Operation_getParameterValue_Parameter->_setID(SM_OPAQUEEXPRESSIONEVALUATION_OPERATION_GETPARAMETERVALUE_PARAMETER);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_sM_OpaqueExpressionEvaluation_Operation_getParameterValue_Parameter);
		parameter->setName("parameter");
		parameter->setEType(uml::umlPackage::eInstance()->getParameter_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_sM_OpaqueExpressionEvaluation_Operation_initialize_EventOccurrence->setName("initialize");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_sM_OpaqueExpressionEvaluation_Operation_initialize_EventOccurrence->setEType(unknownClass);
	}
	m_sM_OpaqueExpressionEvaluation_Operation_initialize_EventOccurrence->setLowerBound(1);
	m_sM_OpaqueExpressionEvaluation_Operation_initialize_EventOccurrence->setUpperBound(1);
	m_sM_OpaqueExpressionEvaluation_Operation_initialize_EventOccurrence->setUnique(true);
	m_sM_OpaqueExpressionEvaluation_Operation_initialize_EventOccurrence->setOrdered(false);
	
	m_sM_OpaqueExpressionEvaluation_Operation_initialize_EventOccurrence->_setID(SM_OPAQUEEXPRESSIONEVALUATION_OPERATION_INITIALIZE_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_sM_OpaqueExpressionEvaluation_Operation_initialize_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_sM_OpaqueExpressionEvaluation_Operation_setParameterValue_ParameterValue->setName("setParameterValue");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_sM_OpaqueExpressionEvaluation_Operation_setParameterValue_ParameterValue->setEType(unknownClass);
	}
	m_sM_OpaqueExpressionEvaluation_Operation_setParameterValue_ParameterValue->setLowerBound(1);
	m_sM_OpaqueExpressionEvaluation_Operation_setParameterValue_ParameterValue->setUpperBound(1);
	m_sM_OpaqueExpressionEvaluation_Operation_setParameterValue_ParameterValue->setUnique(true);
	m_sM_OpaqueExpressionEvaluation_Operation_setParameterValue_ParameterValue->setOrdered(false);
	
	m_sM_OpaqueExpressionEvaluation_Operation_setParameterValue_ParameterValue->_setID(SM_OPAQUEEXPRESSIONEVALUATION_OPERATION_SETPARAMETERVALUE_PARAMETERVALUE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_sM_OpaqueExpressionEvaluation_Operation_setParameterValue_ParameterValue);
		parameter->setName("parameterValue");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ValuesPackageImpl::initializePackageEDataTypes()
{
	
}

