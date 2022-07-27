#include "PSCS/Semantics/CommonBehavior/impl/CommonBehaviorPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EClass.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"


using namespace PSCS::Semantics::CommonBehavior;

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
	m_cS_CallEventExecution_Class->getESuperTypes()->push_back(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getCallEventExecution_Class());
	m_cS_EventOccurrence_Class->getESuperTypes()->push_back(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeCS_CallEventExecutionContent();
	initializeCS_EventOccurrenceContent();

	initializePackageEDataTypes();

}

void CommonBehaviorPackageImpl::initializeCS_CallEventExecutionContent()
{
	m_cS_CallEventExecution_Class->setName("CS_CallEventExecution");
	m_cS_CallEventExecution_Class->setAbstract(false);
	m_cS_CallEventExecution_Class->setInterface(false);
	
	
	m_cS_CallEventExecution_Attribute_interactionPoint->setName("interactionPoint");
	m_cS_CallEventExecution_Attribute_interactionPoint->setEType(PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getCS_InteractionPoint_Class());
	m_cS_CallEventExecution_Attribute_interactionPoint->setLowerBound(0);
	m_cS_CallEventExecution_Attribute_interactionPoint->setUpperBound(1);
	m_cS_CallEventExecution_Attribute_interactionPoint->setTransient(false);
	m_cS_CallEventExecution_Attribute_interactionPoint->setVolatile(false);
	m_cS_CallEventExecution_Attribute_interactionPoint->setChangeable(true);
	m_cS_CallEventExecution_Attribute_interactionPoint->setUnsettable(false);
	m_cS_CallEventExecution_Attribute_interactionPoint->setUnique(true);
	m_cS_CallEventExecution_Attribute_interactionPoint->setDerived(false);
	m_cS_CallEventExecution_Attribute_interactionPoint->setOrdered(false);
	m_cS_CallEventExecution_Attribute_interactionPoint->setContainment(false);
	m_cS_CallEventExecution_Attribute_interactionPoint->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_cS_CallEventExecution_Attribute_interactionPoint->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_cS_CallEventExecution_Operation__copy->setName("_copy");
	m_cS_CallEventExecution_Operation__copy->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_cS_CallEventExecution_Operation__copy->setLowerBound(1);
	m_cS_CallEventExecution_Operation__copy->setUpperBound(1);
	m_cS_CallEventExecution_Operation__copy->setUnique(true);
	m_cS_CallEventExecution_Operation__copy->setOrdered(true);
	
	m_cS_CallEventExecution_Operation_createEventOccurrence->setName("createEventOccurrence");
	m_cS_CallEventExecution_Operation_createEventOccurrence->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
	m_cS_CallEventExecution_Operation_createEventOccurrence->setLowerBound(1);
	m_cS_CallEventExecution_Operation_createEventOccurrence->setUpperBound(1);
	m_cS_CallEventExecution_Operation_createEventOccurrence->setUnique(true);
	m_cS_CallEventExecution_Operation_createEventOccurrence->setOrdered(false);
	
	m_cS_CallEventExecution_Operation_new_->setName("new_");
	m_cS_CallEventExecution_Operation_new_->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_cS_CallEventExecution_Operation_new_->setLowerBound(1);
	m_cS_CallEventExecution_Operation_new_->setUpperBound(1);
	m_cS_CallEventExecution_Operation_new_->setUnique(true);
	m_cS_CallEventExecution_Operation_new_->setOrdered(false);
	
	
}

void CommonBehaviorPackageImpl::initializeCS_EventOccurrenceContent()
{
	m_cS_EventOccurrence_Class->setName("CS_EventOccurrence");
	m_cS_EventOccurrence_Class->setAbstract(false);
	m_cS_EventOccurrence_Class->setInterface(false);
	
	m_cS_EventOccurrence_Attribute_propagationInward = getCS_EventOccurrence_Attribute_propagationInward();
	m_cS_EventOccurrence_Attribute_propagationInward->setName("propagationInward");
		m_cS_EventOccurrence_Attribute_propagationInward->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_cS_EventOccurrence_Attribute_propagationInward->setLowerBound(0);
	m_cS_EventOccurrence_Attribute_propagationInward->setUpperBound(1);
	m_cS_EventOccurrence_Attribute_propagationInward->setTransient(false);
	m_cS_EventOccurrence_Attribute_propagationInward->setVolatile(false);
	m_cS_EventOccurrence_Attribute_propagationInward->setChangeable(true);
	m_cS_EventOccurrence_Attribute_propagationInward->setUnsettable(false);
	m_cS_EventOccurrence_Attribute_propagationInward->setUnique(true);
	m_cS_EventOccurrence_Attribute_propagationInward->setDerived(false);
	m_cS_EventOccurrence_Attribute_propagationInward->setOrdered(false);
	m_cS_EventOccurrence_Attribute_propagationInward->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_cS_EventOccurrence_Attribute_propagationInward->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_cS_EventOccurrence_Attribute_interactionPoint->setName("interactionPoint");
	m_cS_EventOccurrence_Attribute_interactionPoint->setEType(PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getCS_InteractionPoint_Class());
	m_cS_EventOccurrence_Attribute_interactionPoint->setLowerBound(0);
	m_cS_EventOccurrence_Attribute_interactionPoint->setUpperBound(1);
	m_cS_EventOccurrence_Attribute_interactionPoint->setTransient(false);
	m_cS_EventOccurrence_Attribute_interactionPoint->setVolatile(false);
	m_cS_EventOccurrence_Attribute_interactionPoint->setChangeable(true);
	m_cS_EventOccurrence_Attribute_interactionPoint->setUnsettable(false);
	m_cS_EventOccurrence_Attribute_interactionPoint->setUnique(true);
	m_cS_EventOccurrence_Attribute_interactionPoint->setDerived(false);
	m_cS_EventOccurrence_Attribute_interactionPoint->setOrdered(false);
	m_cS_EventOccurrence_Attribute_interactionPoint->setContainment(false);
	m_cS_EventOccurrence_Attribute_interactionPoint->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_cS_EventOccurrence_Attribute_interactionPoint->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_cS_EventOccurrence_Attribute_onPort->setName("onPort");
	m_cS_EventOccurrence_Attribute_onPort->setEType(uml::umlPackage::eInstance()->getPort_Class());
	m_cS_EventOccurrence_Attribute_onPort->setLowerBound(0);
	m_cS_EventOccurrence_Attribute_onPort->setUpperBound(1);
	m_cS_EventOccurrence_Attribute_onPort->setTransient(false);
	m_cS_EventOccurrence_Attribute_onPort->setVolatile(false);
	m_cS_EventOccurrence_Attribute_onPort->setChangeable(true);
	m_cS_EventOccurrence_Attribute_onPort->setUnsettable(false);
	m_cS_EventOccurrence_Attribute_onPort->setUnique(true);
	m_cS_EventOccurrence_Attribute_onPort->setDerived(false);
	m_cS_EventOccurrence_Attribute_onPort->setOrdered(false);
	m_cS_EventOccurrence_Attribute_onPort->setContainment(false);
	m_cS_EventOccurrence_Attribute_onPort->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_cS_EventOccurrence_Attribute_onPort->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setName("wrappedEventOccurrence");
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setLowerBound(0);
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setUpperBound(1);
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setTransient(false);
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setVolatile(false);
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setChangeable(true);
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setUnsettable(false);
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setUnique(true);
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setDerived(false);
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setOrdered(false);
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setContainment(false);
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_cS_EventOccurrence_Operation_doSend->setName("doSend");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_cS_EventOccurrence_Operation_doSend->setEType(unknownClass);
	}
	m_cS_EventOccurrence_Operation_doSend->setLowerBound(1);
	m_cS_EventOccurrence_Operation_doSend->setUpperBound(1);
	m_cS_EventOccurrence_Operation_doSend->setUnique(true);
	m_cS_EventOccurrence_Operation_doSend->setOrdered(false);
	
	m_cS_EventOccurrence_Operation_getParameterValues->setName("getParameterValues");
	m_cS_EventOccurrence_Operation_getParameterValues->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getParameterValue_Class());
	m_cS_EventOccurrence_Operation_getParameterValues->setLowerBound(0);
	m_cS_EventOccurrence_Operation_getParameterValues->setUpperBound(-1);
	m_cS_EventOccurrence_Operation_getParameterValues->setUnique(true);
	m_cS_EventOccurrence_Operation_getParameterValues->setOrdered(false);
	
	m_cS_EventOccurrence_Operation_match_Trigger->setName("match");
	m_cS_EventOccurrence_Operation_match_Trigger->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_cS_EventOccurrence_Operation_match_Trigger->setLowerBound(1);
	m_cS_EventOccurrence_Operation_match_Trigger->setUpperBound(1);
	m_cS_EventOccurrence_Operation_match_Trigger->setUnique(true);
	m_cS_EventOccurrence_Operation_match_Trigger->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_EventOccurrence_Operation_match_Trigger);
		parameter->setName("trigger");
		parameter->setEType(uml::umlPackage::eInstance()->getTrigger_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_EventOccurrence_Operation_sendInTo_CS_Reference_Port->setName("sendInTo");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_cS_EventOccurrence_Operation_sendInTo_CS_Reference_Port->setEType(unknownClass);
	}
	m_cS_EventOccurrence_Operation_sendInTo_CS_Reference_Port->setLowerBound(1);
	m_cS_EventOccurrence_Operation_sendInTo_CS_Reference_Port->setUpperBound(1);
	m_cS_EventOccurrence_Operation_sendInTo_CS_Reference_Port->setUnique(true);
	m_cS_EventOccurrence_Operation_sendInTo_CS_Reference_Port->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_EventOccurrence_Operation_sendInTo_CS_Reference_Port);
		parameter->setName("target");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_EventOccurrence_Operation_sendInTo_CS_Reference_Port);
		parameter->setName("port");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_EventOccurrence_Operation_sendOutTo_CS_Reference_Port->setName("sendOutTo");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_cS_EventOccurrence_Operation_sendOutTo_CS_Reference_Port->setEType(unknownClass);
	}
	m_cS_EventOccurrence_Operation_sendOutTo_CS_Reference_Port->setLowerBound(1);
	m_cS_EventOccurrence_Operation_sendOutTo_CS_Reference_Port->setUpperBound(1);
	m_cS_EventOccurrence_Operation_sendOutTo_CS_Reference_Port->setUnique(true);
	m_cS_EventOccurrence_Operation_sendOutTo_CS_Reference_Port->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_EventOccurrence_Operation_sendOutTo_CS_Reference_Port);
		parameter->setName("target");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_EventOccurrence_Operation_sendOutTo_CS_Reference_Port);
		parameter->setName("port");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void CommonBehaviorPackageImpl::initializePackageEDataTypes()
{
	
}

