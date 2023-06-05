#include "fUML/Semantics/CommonBehavior/impl/CommonBehaviorPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EParameter.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"
//include subpackages 
 
using namespace fUML::Semantics::CommonBehavior;

void CommonBehaviorPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();

	createEventAccepterContent(package, factory);
	createEventOccurrenceContent(package, factory);
	createExecutionContent(package, factory);
	createParameterValueContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void CommonBehaviorPackageImpl::createEventAccepterContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_eventAccepter_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EVENTACCEPTER_CLASS);
	
	
	m_eventAccepter_Operation_accept_Element = factory->createEOperation_as_eOperations_in_EClass(m_eventAccepter_Class, EVENTACCEPTER_OPERATION_ACCEPT_ELEMENT);
	m_eventAccepter_Operation_match_Element = factory->createEOperation_as_eOperations_in_EClass(m_eventAccepter_Class, EVENTACCEPTER_OPERATION_MATCH_ELEMENT);
	
}

void CommonBehaviorPackageImpl::createEventOccurrenceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_eventOccurrence_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EVENTOCCURRENCE_CLASS);
	
	m_eventOccurrence_Attribute_target = factory->createEReference_as_eReferences_in_EClass(m_eventOccurrence_Class, EVENTOCCURRENCE_ATTRIBUTE_TARGET);
	
	m_eventOccurrence_Operation_doSend = factory->createEOperation_as_eOperations_in_EClass(m_eventOccurrence_Class, EVENTOCCURRENCE_OPERATION_DOSEND);
	m_eventOccurrence_Operation_getParameterValues = factory->createEOperation_as_eOperations_in_EClass(m_eventOccurrence_Class, EVENTOCCURRENCE_OPERATION_GETPARAMETERVALUES);
	m_eventOccurrence_Operation_match_Trigger = factory->createEOperation_as_eOperations_in_EClass(m_eventOccurrence_Class, EVENTOCCURRENCE_OPERATION_MATCH_TRIGGER);
	m_eventOccurrence_Operation_matchAny_Trigger = factory->createEOperation_as_eOperations_in_EClass(m_eventOccurrence_Class, EVENTOCCURRENCE_OPERATION_MATCHANY_TRIGGER);
	m_eventOccurrence_Operation_sendTo_Element = factory->createEOperation_as_eOperations_in_EClass(m_eventOccurrence_Class, EVENTOCCURRENCE_OPERATION_SENDTO_ELEMENT);
	
}

void CommonBehaviorPackageImpl::createExecutionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_execution_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EXECUTION_CLASS);
	
	m_execution_Attribute_behavior = factory->createEReference_as_eReferences_in_EClass(m_execution_Class, EXECUTION_ATTRIBUTE_BEHAVIOR);
	m_execution_Attribute_context = factory->createEReference_as_eReferences_in_EClass(m_execution_Class, EXECUTION_ATTRIBUTE_CONTEXT);
	m_execution_Attribute_locus = factory->createEReference_as_eReferences_in_EClass(m_execution_Class, EXECUTION_ATTRIBUTE_LOCUS);
	m_execution_Attribute_parameterValues = factory->createEReference_as_eReferences_in_EClass(m_execution_Class, EXECUTION_ATTRIBUTE_PARAMETERVALUES);
	m_execution_Attribute_types = factory->createEReference_as_eReferences_in_EClass(m_execution_Class, EXECUTION_ATTRIBUTE_TYPES);
	
	m_execution_Operation__copy = factory->createEOperation_as_eOperations_in_EClass(m_execution_Class, EXECUTION_OPERATION__COPY);
	m_execution_Operation_destroy = factory->createEOperation_as_eOperations_in_EClass(m_execution_Class, EXECUTION_OPERATION_DESTROY);
	m_execution_Operation_execute = factory->createEOperation_as_eOperations_in_EClass(m_execution_Class, EXECUTION_OPERATION_EXECUTE);
	m_execution_Operation_getOutputParameterValues = factory->createEOperation_as_eOperations_in_EClass(m_execution_Class, EXECUTION_OPERATION_GETOUTPUTPARAMETERVALUES);
	m_execution_Operation_getParameterValue_Parameter = factory->createEOperation_as_eOperations_in_EClass(m_execution_Class, EXECUTION_OPERATION_GETPARAMETERVALUE_PARAMETER);
	m_execution_Operation_new_ = factory->createEOperation_as_eOperations_in_EClass(m_execution_Class, EXECUTION_OPERATION_NEW_);
	m_execution_Operation_setParameterValue_ParameterValue = factory->createEOperation_as_eOperations_in_EClass(m_execution_Class, EXECUTION_OPERATION_SETPARAMETERVALUE_PARAMETERVALUE);
	m_execution_Operation_terminate = factory->createEOperation_as_eOperations_in_EClass(m_execution_Class, EXECUTION_OPERATION_TERMINATE);
	
}

void CommonBehaviorPackageImpl::createParameterValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_parameterValue_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PARAMETERVALUE_CLASS);
	m_parameterValue_Attribute_values = factory->createEAttribute_as_eAttributes_in_EClass(m_parameterValue_Class, PARAMETERVALUE_ATTRIBUTE_VALUES);
	
	m_parameterValue_Attribute_parameter = factory->createEReference_as_eReferences_in_EClass(m_parameterValue_Class, PARAMETERVALUE_ATTRIBUTE_PARAMETER);
	
	m_parameterValue_Operation__copy = factory->createEOperation_as_eOperations_in_EClass(m_parameterValue_Class, PARAMETERVALUE_OPERATION__COPY);
	
}

void CommonBehaviorPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}
