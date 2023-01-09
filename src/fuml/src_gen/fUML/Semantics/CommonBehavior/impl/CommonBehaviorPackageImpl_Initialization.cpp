#include "fUML/Semantics/CommonBehavior/impl/CommonBehaviorPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EDataType.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"


using namespace fUML::Semantics::CommonBehavior;

void CommonBehaviorPackageImpl::initializePackageContents()
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
	m_execution_Class->getESuperTypes()->push_back(uml::umlPackage::eInstance()->getElement_Class());
	m_execution_Class->getESuperTypes()->push_back(fUML::Semantics::Loci::LociPackage::eInstance()->getSemanticVisitor_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeExecutionContent();
	initializeParameterValueContent();

	initializePackageEDataTypes();

}

void CommonBehaviorPackageImpl::initializeExecutionContent()
{
	m_execution_Class->setName("Execution");
	m_execution_Class->setAbstract(true);
	m_execution_Class->setInterface(false);
	
	m_execution_Class->_setID(EXECUTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_execution_Attribute_behavior->setName("behavior");
	m_execution_Attribute_behavior->setEType(uml::umlPackage::eInstance()->getBehavior_Class());
	m_execution_Attribute_behavior->setLowerBound(1);
	m_execution_Attribute_behavior->setUpperBound(1);
	m_execution_Attribute_behavior->setTransient(false);
	m_execution_Attribute_behavior->setVolatile(false);
	m_execution_Attribute_behavior->setChangeable(true);
	m_execution_Attribute_behavior->setUnsettable(false);
	m_execution_Attribute_behavior->setUnique(true);
	m_execution_Attribute_behavior->setDerived(false);
	m_execution_Attribute_behavior->setOrdered(true);
	m_execution_Attribute_behavior->setContainment(false);
	m_execution_Attribute_behavior->setResolveProxies(true);
	m_execution_Attribute_behavior->setDefaultValueLiteral("");	
	
	m_execution_Attribute_behavior->_setID(EXECUTION_ATTRIBUTE_BEHAVIOR);
	m_execution_Attribute_context->setName("context");
	m_execution_Attribute_context->setEType(uml::umlPackage::eInstance()->getElement_Class());
	m_execution_Attribute_context->setLowerBound(1);
	m_execution_Attribute_context->setUpperBound(1);
	m_execution_Attribute_context->setTransient(false);
	m_execution_Attribute_context->setVolatile(false);
	m_execution_Attribute_context->setChangeable(true);
	m_execution_Attribute_context->setUnsettable(false);
	m_execution_Attribute_context->setUnique(true);
	m_execution_Attribute_context->setDerived(false);
	m_execution_Attribute_context->setOrdered(false);
	m_execution_Attribute_context->setContainment(false);
	m_execution_Attribute_context->setResolveProxies(true);
	m_execution_Attribute_context->setDefaultValueLiteral("");	
	
	m_execution_Attribute_context->_setID(EXECUTION_ATTRIBUTE_CONTEXT);
	m_execution_Attribute_locus->setName("locus");
	m_execution_Attribute_locus->setEType(fUML::Semantics::Loci::LociPackage::eInstance()->getLocus_Class());
	m_execution_Attribute_locus->setLowerBound(0);
	m_execution_Attribute_locus->setUpperBound(1);
	m_execution_Attribute_locus->setTransient(false);
	m_execution_Attribute_locus->setVolatile(false);
	m_execution_Attribute_locus->setChangeable(true);
	m_execution_Attribute_locus->setUnsettable(false);
	m_execution_Attribute_locus->setUnique(true);
	m_execution_Attribute_locus->setDerived(false);
	m_execution_Attribute_locus->setOrdered(false);
	m_execution_Attribute_locus->setContainment(false);
	m_execution_Attribute_locus->setResolveProxies(true);
	m_execution_Attribute_locus->setDefaultValueLiteral("");	
	
	m_execution_Attribute_locus->_setID(EXECUTION_ATTRIBUTE_LOCUS);
	m_execution_Attribute_parameterValues->setName("parameterValues");
	m_execution_Attribute_parameterValues->setEType(getParameterValue_Class());
	m_execution_Attribute_parameterValues->setLowerBound(0);
	m_execution_Attribute_parameterValues->setUpperBound(-1);
	m_execution_Attribute_parameterValues->setTransient(false);
	m_execution_Attribute_parameterValues->setVolatile(false);
	m_execution_Attribute_parameterValues->setChangeable(true);
	m_execution_Attribute_parameterValues->setUnsettable(false);
	m_execution_Attribute_parameterValues->setUnique(true);
	m_execution_Attribute_parameterValues->setDerived(false);
	m_execution_Attribute_parameterValues->setOrdered(false);
	m_execution_Attribute_parameterValues->setContainment(true);
	m_execution_Attribute_parameterValues->setResolveProxies(true);
	m_execution_Attribute_parameterValues->setDefaultValueLiteral("");	
	
	m_execution_Attribute_parameterValues->_setID(EXECUTION_ATTRIBUTE_PARAMETERVALUES);
	m_execution_Attribute_types->setName("types");
	m_execution_Attribute_types->setEType(uml::umlPackage::eInstance()->getClassifier_Class());
	m_execution_Attribute_types->setLowerBound(0);
	m_execution_Attribute_types->setUpperBound(-1);
	m_execution_Attribute_types->setTransient(false);
	m_execution_Attribute_types->setVolatile(false);
	m_execution_Attribute_types->setChangeable(true);
	m_execution_Attribute_types->setUnsettable(false);
	m_execution_Attribute_types->setUnique(true);
	m_execution_Attribute_types->setDerived(false);
	m_execution_Attribute_types->setOrdered(false);
	m_execution_Attribute_types->setContainment(false);
	m_execution_Attribute_types->setResolveProxies(true);
	m_execution_Attribute_types->setDefaultValueLiteral("");	
	
	m_execution_Attribute_types->_setID(EXECUTION_ATTRIBUTE_TYPES);
	
	/*
	 * EOperations
	 */
	m_execution_Operation__copy->setName("_copy");
	m_execution_Operation__copy->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_execution_Operation__copy->setLowerBound(1);
	m_execution_Operation__copy->setUpperBound(1);
	m_execution_Operation__copy->setUnique(true);
	m_execution_Operation__copy->setOrdered(true);
	
	m_execution_Operation__copy->_setID(EXECUTION_OPERATION__COPY);
	
	
	m_execution_Operation_destroy->setName("destroy");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_execution_Operation_destroy->setEType(unknownClass);
	}
	m_execution_Operation_destroy->setLowerBound(1);
	m_execution_Operation_destroy->setUpperBound(1);
	m_execution_Operation_destroy->setUnique(true);
	m_execution_Operation_destroy->setOrdered(false);
	
	m_execution_Operation_destroy->_setID(EXECUTION_OPERATION_DESTROY);
	
	
	m_execution_Operation_execute->setName("execute");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_execution_Operation_execute->setEType(unknownClass);
	}
	m_execution_Operation_execute->setLowerBound(1);
	m_execution_Operation_execute->setUpperBound(1);
	m_execution_Operation_execute->setUnique(true);
	m_execution_Operation_execute->setOrdered(false);
	
	m_execution_Operation_execute->_setID(EXECUTION_OPERATION_EXECUTE);
	
	
	m_execution_Operation_getOutputParameterValues->setName("getOutputParameterValues");
	m_execution_Operation_getOutputParameterValues->setEType(getParameterValue_Class());
	m_execution_Operation_getOutputParameterValues->setLowerBound(0);
	m_execution_Operation_getOutputParameterValues->setUpperBound(-1);
	m_execution_Operation_getOutputParameterValues->setUnique(true);
	m_execution_Operation_getOutputParameterValues->setOrdered(false);
	
	m_execution_Operation_getOutputParameterValues->_setID(EXECUTION_OPERATION_GETOUTPUTPARAMETERVALUES);
	
	
	m_execution_Operation_getParameterValue_Parameter->setName("getParameterValue");
	m_execution_Operation_getParameterValue_Parameter->setEType(getParameterValue_Class());
	m_execution_Operation_getParameterValue_Parameter->setLowerBound(1);
	m_execution_Operation_getParameterValue_Parameter->setUpperBound(1);
	m_execution_Operation_getParameterValue_Parameter->setUnique(true);
	m_execution_Operation_getParameterValue_Parameter->setOrdered(false);
	
	m_execution_Operation_getParameterValue_Parameter->_setID(EXECUTION_OPERATION_GETPARAMETERVALUE_PARAMETER);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_execution_Operation_getParameterValue_Parameter);
		parameter->setName("parameter");
		parameter->setEType(uml::umlPackage::eInstance()->getParameter_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_execution_Operation_new_->setName("new_");
	m_execution_Operation_new_->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_execution_Operation_new_->setLowerBound(1);
	m_execution_Operation_new_->setUpperBound(1);
	m_execution_Operation_new_->setUnique(true);
	m_execution_Operation_new_->setOrdered(false);
	
	m_execution_Operation_new_->_setID(EXECUTION_OPERATION_NEW_);
	
	
	m_execution_Operation_setParameterValue_ParameterValue->setName("setParameterValue");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_execution_Operation_setParameterValue_ParameterValue->setEType(unknownClass);
	}
	m_execution_Operation_setParameterValue_ParameterValue->setLowerBound(1);
	m_execution_Operation_setParameterValue_ParameterValue->setUpperBound(1);
	m_execution_Operation_setParameterValue_ParameterValue->setUnique(true);
	m_execution_Operation_setParameterValue_ParameterValue->setOrdered(false);
	
	m_execution_Operation_setParameterValue_ParameterValue->_setID(EXECUTION_OPERATION_SETPARAMETERVALUE_PARAMETERVALUE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_execution_Operation_setParameterValue_ParameterValue);
		parameter->setName("parameterValue");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_execution_Operation_terminate->setName("terminate");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_execution_Operation_terminate->setEType(unknownClass);
	}
	m_execution_Operation_terminate->setLowerBound(1);
	m_execution_Operation_terminate->setUpperBound(1);
	m_execution_Operation_terminate->setUnique(true);
	m_execution_Operation_terminate->setOrdered(false);
	
	m_execution_Operation_terminate->_setID(EXECUTION_OPERATION_TERMINATE);
	
	
	
}

void CommonBehaviorPackageImpl::initializeParameterValueContent()
{
	m_parameterValue_Class->setName("ParameterValue");
	m_parameterValue_Class->setAbstract(false);
	m_parameterValue_Class->setInterface(false);
	
	m_parameterValue_Class->_setID(PARAMETERVALUE_CLASS);
	
	/*
	 * EAttributes
	 */
	m_parameterValue_Attribute_values = getParameterValue_Attribute_values();
	m_parameterValue_Attribute_values->setName("values");
	m_parameterValue_Attribute_values->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_parameterValue_Attribute_values->setLowerBound(0);
	m_parameterValue_Attribute_values->setUpperBound(-1);
	m_parameterValue_Attribute_values->setTransient(false);
	m_parameterValue_Attribute_values->setVolatile(false);
	m_parameterValue_Attribute_values->setChangeable(true);
	m_parameterValue_Attribute_values->setUnsettable(false);
	m_parameterValue_Attribute_values->setUnique(true);
	m_parameterValue_Attribute_values->setDerived(false);
	m_parameterValue_Attribute_values->setOrdered(true);
	m_parameterValue_Attribute_values->setID(false);
	m_parameterValue_Attribute_values->setDefaultValueLiteral("");
	
	m_parameterValue_Attribute_values->_setID(PARAMETERVALUE_ATTRIBUTE_VALUES);
	
	/*
	 * EReferences
	 */
	m_parameterValue_Attribute_parameter->setName("parameter");
	m_parameterValue_Attribute_parameter->setEType(uml::umlPackage::eInstance()->getParameter_Class());
	m_parameterValue_Attribute_parameter->setLowerBound(1);
	m_parameterValue_Attribute_parameter->setUpperBound(1);
	m_parameterValue_Attribute_parameter->setTransient(false);
	m_parameterValue_Attribute_parameter->setVolatile(false);
	m_parameterValue_Attribute_parameter->setChangeable(true);
	m_parameterValue_Attribute_parameter->setUnsettable(false);
	m_parameterValue_Attribute_parameter->setUnique(true);
	m_parameterValue_Attribute_parameter->setDerived(false);
	m_parameterValue_Attribute_parameter->setOrdered(false);
	m_parameterValue_Attribute_parameter->setContainment(false);
	m_parameterValue_Attribute_parameter->setResolveProxies(true);
	m_parameterValue_Attribute_parameter->setDefaultValueLiteral("");	
	
	m_parameterValue_Attribute_parameter->_setID(PARAMETERVALUE_ATTRIBUTE_PARAMETER);
	
	/*
	 * EOperations
	 */
	m_parameterValue_Operation__copy->setName("_copy");
	m_parameterValue_Operation__copy->setEType(getParameterValue_Class());
	m_parameterValue_Operation__copy->setLowerBound(1);
	m_parameterValue_Operation__copy->setUpperBound(1);
	m_parameterValue_Operation__copy->setUnique(true);
	m_parameterValue_Operation__copy->setOrdered(true);
	
	m_parameterValue_Operation__copy->_setID(PARAMETERVALUE_OPERATION__COPY);
	
	
	
}

void CommonBehaviorPackageImpl::initializePackageEDataTypes()
{
	
}

