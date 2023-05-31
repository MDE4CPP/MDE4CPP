#include "PSCS/Semantics/CommonBehavior/impl/CommonBehaviorPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

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

//depending model packages
#include "PSCS/PSCSPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"
//include subpackages 
 
using namespace PSCS::Semantics::CommonBehavior;

void CommonBehaviorPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();

	createCS_CallEventExecutionContent(package, factory);
	createCS_EventOccurrenceContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void CommonBehaviorPackageImpl::createCS_CallEventExecutionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_CallEventExecution_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_CALLEVENTEXECUTION_CLASS);
	
	m_cS_CallEventExecution_Attribute_interactionPoint = factory->createEReference_as_eReferences_in_EClass(m_cS_CallEventExecution_Class, CS_CALLEVENTEXECUTION_ATTRIBUTE_INTERACTIONPOINT);
	
	m_cS_CallEventExecution_Operation__copy = factory->createEOperation_as_eOperations_in_EClass(m_cS_CallEventExecution_Class, CS_CALLEVENTEXECUTION_OPERATION__COPY);
	m_cS_CallEventExecution_Operation_createEventOccurrence = factory->createEOperation_as_eOperations_in_EClass(m_cS_CallEventExecution_Class, CS_CALLEVENTEXECUTION_OPERATION_CREATEEVENTOCCURRENCE);
	m_cS_CallEventExecution_Operation_new_ = factory->createEOperation_as_eOperations_in_EClass(m_cS_CallEventExecution_Class, CS_CALLEVENTEXECUTION_OPERATION_NEW_);
	
}

void CommonBehaviorPackageImpl::createCS_EventOccurrenceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_EventOccurrence_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_EVENTOCCURRENCE_CLASS);
	m_cS_EventOccurrence_Attribute_propagationInward = factory->createEAttribute_as_eAttributes_in_EClass(m_cS_EventOccurrence_Class, CS_EVENTOCCURRENCE_ATTRIBUTE_PROPAGATIONINWARD);
	
	m_cS_EventOccurrence_Attribute_interactionPoint = factory->createEReference_as_eReferences_in_EClass(m_cS_EventOccurrence_Class, CS_EVENTOCCURRENCE_ATTRIBUTE_INTERACTIONPOINT);
	m_cS_EventOccurrence_Attribute_onPort = factory->createEReference_as_eReferences_in_EClass(m_cS_EventOccurrence_Class, CS_EVENTOCCURRENCE_ATTRIBUTE_ONPORT);
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence = factory->createEReference_as_eReferences_in_EClass(m_cS_EventOccurrence_Class, CS_EVENTOCCURRENCE_ATTRIBUTE_WRAPPEDEVENTOCCURRENCE);
	
	m_cS_EventOccurrence_Operation_doSend = factory->createEOperation_as_eOperations_in_EClass(m_cS_EventOccurrence_Class, CS_EVENTOCCURRENCE_OPERATION_DOSEND);
	m_cS_EventOccurrence_Operation_getParameterValues = factory->createEOperation_as_eOperations_in_EClass(m_cS_EventOccurrence_Class, CS_EVENTOCCURRENCE_OPERATION_GETPARAMETERVALUES);
	m_cS_EventOccurrence_Operation_match_Trigger = factory->createEOperation_as_eOperations_in_EClass(m_cS_EventOccurrence_Class, CS_EVENTOCCURRENCE_OPERATION_MATCH_TRIGGER);
	m_cS_EventOccurrence_Operation_sendInTo_CS_Reference_Port = factory->createEOperation_as_eOperations_in_EClass(m_cS_EventOccurrence_Class, CS_EVENTOCCURRENCE_OPERATION_SENDINTO_CS_REFERENCE_PORT);
	m_cS_EventOccurrence_Operation_sendOutTo_CS_Reference_Port = factory->createEOperation_as_eOperations_in_EClass(m_cS_EventOccurrence_Class, CS_EVENTOCCURRENCE_OPERATION_SENDOUTTO_CS_REFERENCE_PORT);
	
}

void CommonBehaviorPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}
