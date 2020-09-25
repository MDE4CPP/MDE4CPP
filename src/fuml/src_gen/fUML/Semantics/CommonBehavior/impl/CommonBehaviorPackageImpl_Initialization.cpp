#include "fUML/Semantics/CommonBehavior/impl/CommonBehaviorPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

// metametamodel factory
#include "ecore/EcoreFactory.hpp"

//depending model packages

#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "ecore/EcorePackage.hpp"
#include "fUML/FUMLPackage.hpp"
#include "types/TypesPackage.hpp"
#include "uml/UmlPackage.hpp"


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
	m_callEventExecution_Class->getESuperTypes()->push_back(getExecution_Class());
	m_callEventOccurrence_Class->getESuperTypes()->push_back(getEventOccurrence_Class());
	m_classifierBehaviorInvocationEventAccepter_Class->getESuperTypes()->push_back(getEventAccepter_Class());
	m_execution_Class->getESuperTypes()->push_back(fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getObject_Class());
	m_fIFOGetNextEventStrategy_Class->getESuperTypes()->push_back(getGetNextEventStrategy_Class());
	m_getNextEventStrategy_Class->getESuperTypes()->push_back(fUML::Semantics::Loci::LociPackage::eInstance()->getSemanticStrategy_Class());
	m_invocationEventOccurrence_Class->getESuperTypes()->push_back(getEventOccurrence_Class());
	m_opaqueBehaviorExecution_Class->getESuperTypes()->push_back(getExecution_Class());
	m_signalEventOccurrence_Class->getESuperTypes()->push_back(getEventOccurrence_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeCallEventBehaviorContent();
	initializeCallEventExecutionContent();
	initializeCallEventOccurrenceContent();
	initializeClassifierBehaviorExecutionContent();
	initializeClassifierBehaviorInvocationEventAccepterContent();
	initializeEventAccepterContent();
	initializeEventDispatchLoopContent();
	initializeEventOccurrenceContent();
	initializeExecutionContent();
	initializeFIFOGetNextEventStrategyContent();
	initializeGetNextEventStrategyContent();
	initializeInvocationEventOccurrenceContent();
	initializeObjectActivationContent();
	initializeOpaqueBehaviorExecutionContent();
	initializeParameterValueContent();
	initializeSignalEventOccurrenceContent();

	initializePackageEDataTypes();

}

void CommonBehaviorPackageImpl::initializeCallEventBehaviorContent()
{
	m_callEventBehavior_Class->setName("CallEventBehavior");
	m_callEventBehavior_Class->setAbstract(false);
	m_callEventBehavior_Class->setInterface(false);
	
	
	m_callEventBehavior_Attribute_operation->setName("operation");
	m_callEventBehavior_Attribute_operation->setEType(uml::UmlPackage::eInstance()->getOperation_Class());
	m_callEventBehavior_Attribute_operation->setLowerBound(1);
	m_callEventBehavior_Attribute_operation->setUpperBound(1);
	m_callEventBehavior_Attribute_operation->setTransient(false);
	m_callEventBehavior_Attribute_operation->setVolatile(false);
	m_callEventBehavior_Attribute_operation->setChangeable(true);
	m_callEventBehavior_Attribute_operation->setUnsettable(false);
	m_callEventBehavior_Attribute_operation->setUnique(true);
	m_callEventBehavior_Attribute_operation->setDerived(false);
	m_callEventBehavior_Attribute_operation->setOrdered(true);
	m_callEventBehavior_Attribute_operation->setContainment(false);
	m_callEventBehavior_Attribute_operation->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_callEventBehavior_Attribute_operation->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_callEventBehavior_Operation_assignOperation_Operation->setEType(nullptr);
	m_callEventBehavior_Operation_assignOperation_Operation->setName("assignOperation");
	m_callEventBehavior_Operation_assignOperation_Operation->setLowerBound(0);
	m_callEventBehavior_Operation_assignOperation_Operation->setUpperBound(1);
	m_callEventBehavior_Operation_assignOperation_Operation->setUnique(true);
	m_callEventBehavior_Operation_assignOperation_Operation->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_callEventBehavior_Operation_assignOperation_Operation);
		parameter->setName("operation");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void CommonBehaviorPackageImpl::initializeCallEventExecutionContent()
{
	m_callEventExecution_Class->setName("CallEventExecution");
	m_callEventExecution_Class->setAbstract(false);
	m_callEventExecution_Class->setInterface(false);
	
	m_callEventExecution_Attribute_callerSuspended = getCallEventExecution_Attribute_callerSuspended();
	m_callEventExecution_Attribute_callerSuspended->setName("callerSuspended");
	m_callEventExecution_Attribute_callerSuspended->setEType(types::TypesPackage::eInstance()->getBoolean_Class());
	m_callEventExecution_Attribute_callerSuspended->setLowerBound(0);
	m_callEventExecution_Attribute_callerSuspended->setUpperBound(1);
	m_callEventExecution_Attribute_callerSuspended->setTransient(false);
	m_callEventExecution_Attribute_callerSuspended->setVolatile(false);
	m_callEventExecution_Attribute_callerSuspended->setChangeable(true);
	m_callEventExecution_Attribute_callerSuspended->setUnsettable(false);
	m_callEventExecution_Attribute_callerSuspended->setUnique(true);
	m_callEventExecution_Attribute_callerSuspended->setDerived(false);
	m_callEventExecution_Attribute_callerSuspended->setOrdered(true);
	m_callEventExecution_Attribute_callerSuspended->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_callEventExecution_Attribute_callerSuspended->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	m_callEventExecution_Operation__copy->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_callEventExecution_Operation__copy->setName("_copy");
	m_callEventExecution_Operation__copy->setLowerBound(1);
	m_callEventExecution_Operation__copy->setUpperBound(1);
	m_callEventExecution_Operation__copy->setUnique(true);
	m_callEventExecution_Operation__copy->setOrdered(true);
	
	
	m_callEventExecution_Operation_createEventOccurrence->setEType(getEventOccurrence_Class());
	m_callEventExecution_Operation_createEventOccurrence->setName("createEventOccurrence");
	m_callEventExecution_Operation_createEventOccurrence->setLowerBound(1);
	m_callEventExecution_Operation_createEventOccurrence->setUpperBound(1);
	m_callEventExecution_Operation_createEventOccurrence->setUnique(true);
	m_callEventExecution_Operation_createEventOccurrence->setOrdered(true);
	
	
	m_callEventExecution_Operation_execute->setEType(nullptr);
	m_callEventExecution_Operation_execute->setName("execute");
	m_callEventExecution_Operation_execute->setLowerBound(0);
	m_callEventExecution_Operation_execute->setUpperBound(1);
	m_callEventExecution_Operation_execute->setUnique(true);
	m_callEventExecution_Operation_execute->setOrdered(true);
	
	
	m_callEventExecution_Operation_getInputParameterValues->setEType(getParameterValue_Class());
	m_callEventExecution_Operation_getInputParameterValues->setName("getInputParameterValues");
	m_callEventExecution_Operation_getInputParameterValues->setLowerBound(0);
	m_callEventExecution_Operation_getInputParameterValues->setUpperBound(-1);
	m_callEventExecution_Operation_getInputParameterValues->setUnique(true);
	m_callEventExecution_Operation_getInputParameterValues->setOrdered(true);
	
	
	m_callEventExecution_Operation_getOperation->setEType(uml::UmlPackage::eInstance()->getOperation_Class());
	m_callEventExecution_Operation_getOperation->setName("getOperation");
	m_callEventExecution_Operation_getOperation->setLowerBound(0);
	m_callEventExecution_Operation_getOperation->setUpperBound(1);
	m_callEventExecution_Operation_getOperation->setUnique(true);
	m_callEventExecution_Operation_getOperation->setOrdered(true);
	
	
	m_callEventExecution_Operation_isCallerSuspended->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_callEventExecution_Operation_isCallerSuspended->setName("isCallerSuspended");
	m_callEventExecution_Operation_isCallerSuspended->setLowerBound(0);
	m_callEventExecution_Operation_isCallerSuspended->setUpperBound(1);
	m_callEventExecution_Operation_isCallerSuspended->setUnique(true);
	m_callEventExecution_Operation_isCallerSuspended->setOrdered(true);
	
	
	m_callEventExecution_Operation_makeCall->setEType(nullptr);
	m_callEventExecution_Operation_makeCall->setName("makeCall");
	m_callEventExecution_Operation_makeCall->setLowerBound(0);
	m_callEventExecution_Operation_makeCall->setUpperBound(1);
	m_callEventExecution_Operation_makeCall->setUnique(true);
	m_callEventExecution_Operation_makeCall->setOrdered(true);
	
	
	m_callEventExecution_Operation_new_->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_callEventExecution_Operation_new_->setName("new_");
	m_callEventExecution_Operation_new_->setLowerBound(0);
	m_callEventExecution_Operation_new_->setUpperBound(1);
	m_callEventExecution_Operation_new_->setUnique(true);
	m_callEventExecution_Operation_new_->setOrdered(true);
	
	
	m_callEventExecution_Operation_releaseCaller->setEType(nullptr);
	m_callEventExecution_Operation_releaseCaller->setName("releaseCaller");
	m_callEventExecution_Operation_releaseCaller->setLowerBound(0);
	m_callEventExecution_Operation_releaseCaller->setUpperBound(1);
	m_callEventExecution_Operation_releaseCaller->setUnique(true);
	m_callEventExecution_Operation_releaseCaller->setOrdered(true);
	
	
	m_callEventExecution_Operation_setOutputParameterValues_ParameterValue->setEType(nullptr);
	m_callEventExecution_Operation_setOutputParameterValues_ParameterValue->setName("setOutputParameterValues");
	m_callEventExecution_Operation_setOutputParameterValues_ParameterValue->setLowerBound(0);
	m_callEventExecution_Operation_setOutputParameterValues_ParameterValue->setUpperBound(1);
	m_callEventExecution_Operation_setOutputParameterValues_ParameterValue->setUnique(true);
	m_callEventExecution_Operation_setOutputParameterValues_ParameterValue->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_callEventExecution_Operation_setOutputParameterValues_ParameterValue);
		parameter->setName("parameterValues");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_callEventExecution_Operation_suspendCaller->setEType(nullptr);
	m_callEventExecution_Operation_suspendCaller->setName("suspendCaller");
	m_callEventExecution_Operation_suspendCaller->setLowerBound(0);
	m_callEventExecution_Operation_suspendCaller->setUpperBound(1);
	m_callEventExecution_Operation_suspendCaller->setUnique(true);
	m_callEventExecution_Operation_suspendCaller->setOrdered(true);
	
	
	m_callEventExecution_Operation_wait_->setEType(nullptr);
	m_callEventExecution_Operation_wait_->setName("wait_");
	m_callEventExecution_Operation_wait_->setLowerBound(0);
	m_callEventExecution_Operation_wait_->setUpperBound(1);
	m_callEventExecution_Operation_wait_->setUnique(true);
	m_callEventExecution_Operation_wait_->setOrdered(true);
	
	
	
}

void CommonBehaviorPackageImpl::initializeCallEventOccurrenceContent()
{
	m_callEventOccurrence_Class->setName("CallEventOccurrence");
	m_callEventOccurrence_Class->setAbstract(false);
	m_callEventOccurrence_Class->setInterface(false);
	
	
	m_callEventOccurrence_Attribute_execution->setName("execution");
	m_callEventOccurrence_Attribute_execution->setEType(getCallEventExecution_Class());
	m_callEventOccurrence_Attribute_execution->setLowerBound(1);
	m_callEventOccurrence_Attribute_execution->setUpperBound(1);
	m_callEventOccurrence_Attribute_execution->setTransient(false);
	m_callEventOccurrence_Attribute_execution->setVolatile(false);
	m_callEventOccurrence_Attribute_execution->setChangeable(true);
	m_callEventOccurrence_Attribute_execution->setUnsettable(false);
	m_callEventOccurrence_Attribute_execution->setUnique(true);
	m_callEventOccurrence_Attribute_execution->setDerived(false);
	m_callEventOccurrence_Attribute_execution->setOrdered(true);
	m_callEventOccurrence_Attribute_execution->setContainment(false);
	m_callEventOccurrence_Attribute_execution->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_callEventOccurrence_Attribute_execution->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_callEventOccurrence_Operation_getOperation->setEType(uml::UmlPackage::eInstance()->getOperation_Class());
	m_callEventOccurrence_Operation_getOperation->setName("getOperation");
	m_callEventOccurrence_Operation_getOperation->setLowerBound(1);
	m_callEventOccurrence_Operation_getOperation->setUpperBound(1);
	m_callEventOccurrence_Operation_getOperation->setUnique(true);
	m_callEventOccurrence_Operation_getOperation->setOrdered(true);
	
	
	m_callEventOccurrence_Operation_getParameterValues->setEType(getParameterValue_Class());
	m_callEventOccurrence_Operation_getParameterValues->setName("getParameterValues");
	m_callEventOccurrence_Operation_getParameterValues->setLowerBound(0);
	m_callEventOccurrence_Operation_getParameterValues->setUpperBound(-1);
	m_callEventOccurrence_Operation_getParameterValues->setUnique(true);
	m_callEventOccurrence_Operation_getParameterValues->setOrdered(true);
	
	
	m_callEventOccurrence_Operation_match_Trigger->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_callEventOccurrence_Operation_match_Trigger->setName("match");
	m_callEventOccurrence_Operation_match_Trigger->setLowerBound(0);
	m_callEventOccurrence_Operation_match_Trigger->setUpperBound(1);
	m_callEventOccurrence_Operation_match_Trigger->setUnique(true);
	m_callEventOccurrence_Operation_match_Trigger->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_callEventOccurrence_Operation_match_Trigger);
		parameter->setName("trigger");
		parameter->setEType(uml::UmlPackage::eInstance()->getTrigger_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_callEventOccurrence_Operation_releaseCaller->setEType(nullptr);
	m_callEventOccurrence_Operation_releaseCaller->setName("releaseCaller");
	m_callEventOccurrence_Operation_releaseCaller->setLowerBound(0);
	m_callEventOccurrence_Operation_releaseCaller->setUpperBound(1);
	m_callEventOccurrence_Operation_releaseCaller->setUnique(true);
	m_callEventOccurrence_Operation_releaseCaller->setOrdered(true);
	
	
	m_callEventOccurrence_Operation_setOutputParameterValues_ParameterValue->setEType(nullptr);
	m_callEventOccurrence_Operation_setOutputParameterValues_ParameterValue->setName("setOutputParameterValues");
	m_callEventOccurrence_Operation_setOutputParameterValues_ParameterValue->setLowerBound(0);
	m_callEventOccurrence_Operation_setOutputParameterValues_ParameterValue->setUpperBound(1);
	m_callEventOccurrence_Operation_setOutputParameterValues_ParameterValue->setUnique(true);
	m_callEventOccurrence_Operation_setOutputParameterValues_ParameterValue->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_callEventOccurrence_Operation_setOutputParameterValues_ParameterValue);
		parameter->setName("parameterValues");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void CommonBehaviorPackageImpl::initializeClassifierBehaviorExecutionContent()
{
	m_classifierBehaviorExecution_Class->setName("ClassifierBehaviorExecution");
	m_classifierBehaviorExecution_Class->setAbstract(false);
	m_classifierBehaviorExecution_Class->setInterface(false);
	
	
	m_classifierBehaviorExecution_Attribute_classifier->setName("classifier");
	m_classifierBehaviorExecution_Attribute_classifier->setEType(uml::UmlPackage::eInstance()->getClass_Class());
	m_classifierBehaviorExecution_Attribute_classifier->setLowerBound(1);
	m_classifierBehaviorExecution_Attribute_classifier->setUpperBound(1);
	m_classifierBehaviorExecution_Attribute_classifier->setTransient(false);
	m_classifierBehaviorExecution_Attribute_classifier->setVolatile(false);
	m_classifierBehaviorExecution_Attribute_classifier->setChangeable(true);
	m_classifierBehaviorExecution_Attribute_classifier->setUnsettable(false);
	m_classifierBehaviorExecution_Attribute_classifier->setUnique(true);
	m_classifierBehaviorExecution_Attribute_classifier->setDerived(false);
	m_classifierBehaviorExecution_Attribute_classifier->setOrdered(false);
	m_classifierBehaviorExecution_Attribute_classifier->setContainment(false);
	m_classifierBehaviorExecution_Attribute_classifier->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_classifierBehaviorExecution_Attribute_classifier->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_classifierBehaviorExecution_Attribute_execution->setName("execution");
	m_classifierBehaviorExecution_Attribute_execution->setEType(getExecution_Class());
	m_classifierBehaviorExecution_Attribute_execution->setLowerBound(1);
	m_classifierBehaviorExecution_Attribute_execution->setUpperBound(1);
	m_classifierBehaviorExecution_Attribute_execution->setTransient(false);
	m_classifierBehaviorExecution_Attribute_execution->setVolatile(false);
	m_classifierBehaviorExecution_Attribute_execution->setChangeable(true);
	m_classifierBehaviorExecution_Attribute_execution->setUnsettable(false);
	m_classifierBehaviorExecution_Attribute_execution->setUnique(true);
	m_classifierBehaviorExecution_Attribute_execution->setDerived(false);
	m_classifierBehaviorExecution_Attribute_execution->setOrdered(false);
	m_classifierBehaviorExecution_Attribute_execution->setContainment(false);
	m_classifierBehaviorExecution_Attribute_execution->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_classifierBehaviorExecution_Attribute_execution->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_classifierBehaviorExecution_Attribute_objectActivation->setName("objectActivation");
	m_classifierBehaviorExecution_Attribute_objectActivation->setEType(getObjectActivation_Class());
	m_classifierBehaviorExecution_Attribute_objectActivation->setLowerBound(0);
	m_classifierBehaviorExecution_Attribute_objectActivation->setUpperBound(1);
	m_classifierBehaviorExecution_Attribute_objectActivation->setTransient(false);
	m_classifierBehaviorExecution_Attribute_objectActivation->setVolatile(false);
	m_classifierBehaviorExecution_Attribute_objectActivation->setChangeable(true);
	m_classifierBehaviorExecution_Attribute_objectActivation->setUnsettable(false);
	m_classifierBehaviorExecution_Attribute_objectActivation->setUnique(true);
	m_classifierBehaviorExecution_Attribute_objectActivation->setDerived(false);
	m_classifierBehaviorExecution_Attribute_objectActivation->setOrdered(false);
	m_classifierBehaviorExecution_Attribute_objectActivation->setContainment(false);
	m_classifierBehaviorExecution_Attribute_objectActivation->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_classifierBehaviorExecution_Attribute_objectActivation->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_classifierBehaviorExecution_Operation__startObjectBehavior->setEType(nullptr);
	m_classifierBehaviorExecution_Operation__startObjectBehavior->setName("_startObjectBehavior");
	m_classifierBehaviorExecution_Operation__startObjectBehavior->setLowerBound(1);
	m_classifierBehaviorExecution_Operation__startObjectBehavior->setUpperBound(1);
	m_classifierBehaviorExecution_Operation__startObjectBehavior->setUnique(true);
	m_classifierBehaviorExecution_Operation__startObjectBehavior->setOrdered(false);
	
	
	m_classifierBehaviorExecution_Operation_execute_Class_ParameterValue->setEType(nullptr);
	m_classifierBehaviorExecution_Operation_execute_Class_ParameterValue->setName("execute");
	m_classifierBehaviorExecution_Operation_execute_Class_ParameterValue->setLowerBound(1);
	m_classifierBehaviorExecution_Operation_execute_Class_ParameterValue->setUpperBound(1);
	m_classifierBehaviorExecution_Operation_execute_Class_ParameterValue->setUnique(true);
	m_classifierBehaviorExecution_Operation_execute_Class_ParameterValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_classifierBehaviorExecution_Operation_execute_Class_ParameterValue);
		parameter->setName("classifier");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_classifierBehaviorExecution_Operation_execute_Class_ParameterValue);
		parameter->setName("inputs");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_classifierBehaviorExecution_Operation_terminate->setEType(nullptr);
	m_classifierBehaviorExecution_Operation_terminate->setName("terminate");
	m_classifierBehaviorExecution_Operation_terminate->setLowerBound(1);
	m_classifierBehaviorExecution_Operation_terminate->setUpperBound(1);
	m_classifierBehaviorExecution_Operation_terminate->setUnique(true);
	m_classifierBehaviorExecution_Operation_terminate->setOrdered(false);
	
	
	
}

void CommonBehaviorPackageImpl::initializeClassifierBehaviorInvocationEventAccepterContent()
{
	m_classifierBehaviorInvocationEventAccepter_Class->setName("ClassifierBehaviorInvocationEventAccepter");
	m_classifierBehaviorInvocationEventAccepter_Class->setAbstract(false);
	m_classifierBehaviorInvocationEventAccepter_Class->setInterface(false);
	
	
	m_classifierBehaviorInvocationEventAccepter_Attribute_classifier->setName("classifier");
	m_classifierBehaviorInvocationEventAccepter_Attribute_classifier->setEType(uml::UmlPackage::eInstance()->getClass_Class());
	m_classifierBehaviorInvocationEventAccepter_Attribute_classifier->setLowerBound(1);
	m_classifierBehaviorInvocationEventAccepter_Attribute_classifier->setUpperBound(1);
	m_classifierBehaviorInvocationEventAccepter_Attribute_classifier->setTransient(false);
	m_classifierBehaviorInvocationEventAccepter_Attribute_classifier->setVolatile(false);
	m_classifierBehaviorInvocationEventAccepter_Attribute_classifier->setChangeable(true);
	m_classifierBehaviorInvocationEventAccepter_Attribute_classifier->setUnsettable(false);
	m_classifierBehaviorInvocationEventAccepter_Attribute_classifier->setUnique(true);
	m_classifierBehaviorInvocationEventAccepter_Attribute_classifier->setDerived(false);
	m_classifierBehaviorInvocationEventAccepter_Attribute_classifier->setOrdered(true);
	m_classifierBehaviorInvocationEventAccepter_Attribute_classifier->setContainment(false);
	m_classifierBehaviorInvocationEventAccepter_Attribute_classifier->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_classifierBehaviorInvocationEventAccepter_Attribute_classifier->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_classifierBehaviorInvocationEventAccepter_Attribute_execution->setName("execution");
	m_classifierBehaviorInvocationEventAccepter_Attribute_execution->setEType(getExecution_Class());
	m_classifierBehaviorInvocationEventAccepter_Attribute_execution->setLowerBound(1);
	m_classifierBehaviorInvocationEventAccepter_Attribute_execution->setUpperBound(1);
	m_classifierBehaviorInvocationEventAccepter_Attribute_execution->setTransient(false);
	m_classifierBehaviorInvocationEventAccepter_Attribute_execution->setVolatile(false);
	m_classifierBehaviorInvocationEventAccepter_Attribute_execution->setChangeable(true);
	m_classifierBehaviorInvocationEventAccepter_Attribute_execution->setUnsettable(false);
	m_classifierBehaviorInvocationEventAccepter_Attribute_execution->setUnique(true);
	m_classifierBehaviorInvocationEventAccepter_Attribute_execution->setDerived(false);
	m_classifierBehaviorInvocationEventAccepter_Attribute_execution->setOrdered(true);
	m_classifierBehaviorInvocationEventAccepter_Attribute_execution->setContainment(false);
	m_classifierBehaviorInvocationEventAccepter_Attribute_execution->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_classifierBehaviorInvocationEventAccepter_Attribute_execution->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_classifierBehaviorInvocationEventAccepter_Attribute_objectActivation->setName("objectActivation");
	m_classifierBehaviorInvocationEventAccepter_Attribute_objectActivation->setEType(getObjectActivation_Class());
	m_classifierBehaviorInvocationEventAccepter_Attribute_objectActivation->setLowerBound(0);
	m_classifierBehaviorInvocationEventAccepter_Attribute_objectActivation->setUpperBound(1);
	m_classifierBehaviorInvocationEventAccepter_Attribute_objectActivation->setTransient(false);
	m_classifierBehaviorInvocationEventAccepter_Attribute_objectActivation->setVolatile(false);
	m_classifierBehaviorInvocationEventAccepter_Attribute_objectActivation->setChangeable(true);
	m_classifierBehaviorInvocationEventAccepter_Attribute_objectActivation->setUnsettable(false);
	m_classifierBehaviorInvocationEventAccepter_Attribute_objectActivation->setUnique(true);
	m_classifierBehaviorInvocationEventAccepter_Attribute_objectActivation->setDerived(false);
	m_classifierBehaviorInvocationEventAccepter_Attribute_objectActivation->setOrdered(true);
	m_classifierBehaviorInvocationEventAccepter_Attribute_objectActivation->setContainment(false);
	m_classifierBehaviorInvocationEventAccepter_Attribute_objectActivation->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_classifierBehaviorInvocationEventAccepter_Attribute_objectActivation->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_classifierBehaviorInvocationEventAccepter_Operation_accept_EventOccurrence->setEType(nullptr);
	m_classifierBehaviorInvocationEventAccepter_Operation_accept_EventOccurrence->setName("accept");
	m_classifierBehaviorInvocationEventAccepter_Operation_accept_EventOccurrence->setLowerBound(0);
	m_classifierBehaviorInvocationEventAccepter_Operation_accept_EventOccurrence->setUpperBound(1);
	m_classifierBehaviorInvocationEventAccepter_Operation_accept_EventOccurrence->setUnique(true);
	m_classifierBehaviorInvocationEventAccepter_Operation_accept_EventOccurrence->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_classifierBehaviorInvocationEventAccepter_Operation_accept_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_classifierBehaviorInvocationEventAccepter_Operation_invokeBehavior_Class_ParameterValue->setEType(nullptr);
	m_classifierBehaviorInvocationEventAccepter_Operation_invokeBehavior_Class_ParameterValue->setName("invokeBehavior");
	m_classifierBehaviorInvocationEventAccepter_Operation_invokeBehavior_Class_ParameterValue->setLowerBound(0);
	m_classifierBehaviorInvocationEventAccepter_Operation_invokeBehavior_Class_ParameterValue->setUpperBound(1);
	m_classifierBehaviorInvocationEventAccepter_Operation_invokeBehavior_Class_ParameterValue->setUnique(true);
	m_classifierBehaviorInvocationEventAccepter_Operation_invokeBehavior_Class_ParameterValue->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_classifierBehaviorInvocationEventAccepter_Operation_invokeBehavior_Class_ParameterValue);
		parameter->setName("classifier");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_classifierBehaviorInvocationEventAccepter_Operation_invokeBehavior_Class_ParameterValue);
		parameter->setName("inputs");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_classifierBehaviorInvocationEventAccepter_Operation_match_EventOccurrence->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_classifierBehaviorInvocationEventAccepter_Operation_match_EventOccurrence->setName("match");
	m_classifierBehaviorInvocationEventAccepter_Operation_match_EventOccurrence->setLowerBound(0);
	m_classifierBehaviorInvocationEventAccepter_Operation_match_EventOccurrence->setUpperBound(1);
	m_classifierBehaviorInvocationEventAccepter_Operation_match_EventOccurrence->setUnique(true);
	m_classifierBehaviorInvocationEventAccepter_Operation_match_EventOccurrence->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_classifierBehaviorInvocationEventAccepter_Operation_match_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(getEventOccurrence_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_classifierBehaviorInvocationEventAccepter_Operation_terminate->setEType(nullptr);
	m_classifierBehaviorInvocationEventAccepter_Operation_terminate->setName("terminate");
	m_classifierBehaviorInvocationEventAccepter_Operation_terminate->setLowerBound(0);
	m_classifierBehaviorInvocationEventAccepter_Operation_terminate->setUpperBound(1);
	m_classifierBehaviorInvocationEventAccepter_Operation_terminate->setUnique(true);
	m_classifierBehaviorInvocationEventAccepter_Operation_terminate->setOrdered(true);
	
	
	
}

void CommonBehaviorPackageImpl::initializeEventAccepterContent()
{
	m_eventAccepter_Class->setName("EventAccepter");
	m_eventAccepter_Class->setAbstract(true);
	m_eventAccepter_Class->setInterface(false);
	
	
	
	m_eventAccepter_Operation_accept_SignalInstance->setEType(nullptr);
	m_eventAccepter_Operation_accept_SignalInstance->setName("accept");
	m_eventAccepter_Operation_accept_SignalInstance->setLowerBound(1);
	m_eventAccepter_Operation_accept_SignalInstance->setUpperBound(1);
	m_eventAccepter_Operation_accept_SignalInstance->setUnique(true);
	m_eventAccepter_Operation_accept_SignalInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eventAccepter_Operation_accept_SignalInstance);
		parameter->setName("signalInstance");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eventAccepter_Operation_match_SignalInstance->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_eventAccepter_Operation_match_SignalInstance->setName("match");
	m_eventAccepter_Operation_match_SignalInstance->setLowerBound(1);
	m_eventAccepter_Operation_match_SignalInstance->setUpperBound(1);
	m_eventAccepter_Operation_match_SignalInstance->setUnique(true);
	m_eventAccepter_Operation_match_SignalInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eventAccepter_Operation_match_SignalInstance);
		parameter->setName("signalInstance");
		parameter->setEType(fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getSignalInstance_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void CommonBehaviorPackageImpl::initializeEventDispatchLoopContent()
{
	m_eventDispatchLoop_Class->setName("EventDispatchLoop");
	m_eventDispatchLoop_Class->setAbstract(false);
	m_eventDispatchLoop_Class->setInterface(false);
	
	
	
	
}

void CommonBehaviorPackageImpl::initializeEventOccurrenceContent()
{
	m_eventOccurrence_Class->setName("EventOccurrence");
	m_eventOccurrence_Class->setAbstract(false);
	m_eventOccurrence_Class->setInterface(false);
	
	
	m_eventOccurrence_Attribute_target->setName("target");
	m_eventOccurrence_Attribute_target->setEType(fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getReference_Class());
	m_eventOccurrence_Attribute_target->setLowerBound(0);
	m_eventOccurrence_Attribute_target->setUpperBound(1);
	m_eventOccurrence_Attribute_target->setTransient(false);
	m_eventOccurrence_Attribute_target->setVolatile(false);
	m_eventOccurrence_Attribute_target->setChangeable(true);
	m_eventOccurrence_Attribute_target->setUnsettable(false);
	m_eventOccurrence_Attribute_target->setUnique(true);
	m_eventOccurrence_Attribute_target->setDerived(false);
	m_eventOccurrence_Attribute_target->setOrdered(true);
	m_eventOccurrence_Attribute_target->setContainment(false);
	m_eventOccurrence_Attribute_target->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_eventOccurrence_Attribute_target->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_eventOccurrence_Operation_doSend->setEType(nullptr);
	m_eventOccurrence_Operation_doSend->setName("doSend");
	m_eventOccurrence_Operation_doSend->setLowerBound(1);
	m_eventOccurrence_Operation_doSend->setUpperBound(1);
	m_eventOccurrence_Operation_doSend->setUnique(true);
	m_eventOccurrence_Operation_doSend->setOrdered(true);
	
	
	m_eventOccurrence_Operation_getParameterValues->setEType(getParameterValue_Class());
	m_eventOccurrence_Operation_getParameterValues->setName("getParameterValues");
	m_eventOccurrence_Operation_getParameterValues->setLowerBound(0);
	m_eventOccurrence_Operation_getParameterValues->setUpperBound(-1);
	m_eventOccurrence_Operation_getParameterValues->setUnique(true);
	m_eventOccurrence_Operation_getParameterValues->setOrdered(true);
	
	
	m_eventOccurrence_Operation_match_Trigger->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_eventOccurrence_Operation_match_Trigger->setName("match");
	m_eventOccurrence_Operation_match_Trigger->setLowerBound(1);
	m_eventOccurrence_Operation_match_Trigger->setUpperBound(1);
	m_eventOccurrence_Operation_match_Trigger->setUnique(true);
	m_eventOccurrence_Operation_match_Trigger->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eventOccurrence_Operation_match_Trigger);
		parameter->setName("trigger");
		parameter->setEType(uml::UmlPackage::eInstance()->getTrigger_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eventOccurrence_Operation_matchAny_Trigger->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_eventOccurrence_Operation_matchAny_Trigger->setName("matchAny");
	m_eventOccurrence_Operation_matchAny_Trigger->setLowerBound(1);
	m_eventOccurrence_Operation_matchAny_Trigger->setUpperBound(1);
	m_eventOccurrence_Operation_matchAny_Trigger->setUnique(true);
	m_eventOccurrence_Operation_matchAny_Trigger->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eventOccurrence_Operation_matchAny_Trigger);
		parameter->setName("triggers");
		parameter->setEType(uml::UmlPackage::eInstance()->getTrigger_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eventOccurrence_Operation_sendTo_Reference->setEType(nullptr);
	m_eventOccurrence_Operation_sendTo_Reference->setName("sendTo");
	m_eventOccurrence_Operation_sendTo_Reference->setLowerBound(1);
	m_eventOccurrence_Operation_sendTo_Reference->setUpperBound(1);
	m_eventOccurrence_Operation_sendTo_Reference->setUnique(true);
	m_eventOccurrence_Operation_sendTo_Reference->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eventOccurrence_Operation_sendTo_Reference);
		parameter->setName("target");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void CommonBehaviorPackageImpl::initializeExecutionContent()
{
	m_execution_Class->setName("Execution");
	m_execution_Class->setAbstract(true);
	m_execution_Class->setInterface(false);
	
	
	m_execution_Attribute_context->setName("context");
	m_execution_Attribute_context->setEType(fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getObject_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_execution_Attribute_context->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_execution_Attribute_parameterValues->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_execution_Operation__copy->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_execution_Operation__copy->setName("_copy");
	m_execution_Operation__copy->setLowerBound(1);
	m_execution_Operation__copy->setUpperBound(1);
	m_execution_Operation__copy->setUnique(true);
	m_execution_Operation__copy->setOrdered(true);
	
	
	m_execution_Operation_execute->setEType(nullptr);
	m_execution_Operation_execute->setName("execute");
	m_execution_Operation_execute->setLowerBound(1);
	m_execution_Operation_execute->setUpperBound(1);
	m_execution_Operation_execute->setUnique(true);
	m_execution_Operation_execute->setOrdered(false);
	
	
	m_execution_Operation_getBehavior->setEType(uml::UmlPackage::eInstance()->getBehavior_Class());
	m_execution_Operation_getBehavior->setName("getBehavior");
	m_execution_Operation_getBehavior->setLowerBound(1);
	m_execution_Operation_getBehavior->setUpperBound(1);
	m_execution_Operation_getBehavior->setUnique(true);
	m_execution_Operation_getBehavior->setOrdered(false);
	
	
	m_execution_Operation_getOutputParameterValues->setEType(getParameterValue_Class());
	m_execution_Operation_getOutputParameterValues->setName("getOutputParameterValues");
	m_execution_Operation_getOutputParameterValues->setLowerBound(0);
	m_execution_Operation_getOutputParameterValues->setUpperBound(-1);
	m_execution_Operation_getOutputParameterValues->setUnique(true);
	m_execution_Operation_getOutputParameterValues->setOrdered(false);
	
	
	m_execution_Operation_getParameterValue_Parameter->setEType(getParameterValue_Class());
	m_execution_Operation_getParameterValue_Parameter->setName("getParameterValue");
	m_execution_Operation_getParameterValue_Parameter->setLowerBound(1);
	m_execution_Operation_getParameterValue_Parameter->setUpperBound(1);
	m_execution_Operation_getParameterValue_Parameter->setUnique(true);
	m_execution_Operation_getParameterValue_Parameter->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_execution_Operation_getParameterValue_Parameter);
		parameter->setName("parameter");
		parameter->setEType(uml::UmlPackage::eInstance()->getParameter_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_execution_Operation_new_->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_execution_Operation_new_->setName("new_");
	m_execution_Operation_new_->setLowerBound(1);
	m_execution_Operation_new_->setUpperBound(1);
	m_execution_Operation_new_->setUnique(true);
	m_execution_Operation_new_->setOrdered(false);
	
	
	m_execution_Operation_setParameterValue_ParameterValue->setEType(nullptr);
	m_execution_Operation_setParameterValue_ParameterValue->setName("setParameterValue");
	m_execution_Operation_setParameterValue_ParameterValue->setLowerBound(1);
	m_execution_Operation_setParameterValue_ParameterValue->setUpperBound(1);
	m_execution_Operation_setParameterValue_ParameterValue->setUnique(true);
	m_execution_Operation_setParameterValue_ParameterValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_execution_Operation_setParameterValue_ParameterValue);
		parameter->setName("parameterValue");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_execution_Operation_terminate->setEType(nullptr);
	m_execution_Operation_terminate->setName("terminate");
	m_execution_Operation_terminate->setLowerBound(1);
	m_execution_Operation_terminate->setUpperBound(1);
	m_execution_Operation_terminate->setUnique(true);
	m_execution_Operation_terminate->setOrdered(false);
	
	
	
}

void CommonBehaviorPackageImpl::initializeFIFOGetNextEventStrategyContent()
{
	m_fIFOGetNextEventStrategy_Class->setName("FIFOGetNextEventStrategy");
	m_fIFOGetNextEventStrategy_Class->setAbstract(false);
	m_fIFOGetNextEventStrategy_Class->setInterface(false);
	
	
	
	
}

void CommonBehaviorPackageImpl::initializeGetNextEventStrategyContent()
{
	m_getNextEventStrategy_Class->setName("GetNextEventStrategy");
	m_getNextEventStrategy_Class->setAbstract(true);
	m_getNextEventStrategy_Class->setInterface(false);
	
	
	
	m_getNextEventStrategy_Operation_getName->setEType(types::TypesPackage::eInstance()->getString_Class());
	m_getNextEventStrategy_Operation_getName->setName("getName");
	m_getNextEventStrategy_Operation_getName->setLowerBound(0);
	m_getNextEventStrategy_Operation_getName->setUpperBound(1);
	m_getNextEventStrategy_Operation_getName->setUnique(true);
	m_getNextEventStrategy_Operation_getName->setOrdered(true);
	
	
	m_getNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation->setEType(fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getSignalInstance_Class());
	m_getNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation->setName("retrieveNextEvent");
	m_getNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation->setLowerBound(1);
	m_getNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation->setUpperBound(1);
	m_getNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation->setUnique(true);
	m_getNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_getNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation);
		parameter->setName("objectActivation");
		parameter->setEType(getObjectActivation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void CommonBehaviorPackageImpl::initializeInvocationEventOccurrenceContent()
{
	m_invocationEventOccurrence_Class->setName("InvocationEventOccurrence");
	m_invocationEventOccurrence_Class->setAbstract(false);
	m_invocationEventOccurrence_Class->setInterface(false);
	
	
	m_invocationEventOccurrence_Attribute_execution->setName("execution");
	m_invocationEventOccurrence_Attribute_execution->setEType(getExecution_Class());
	m_invocationEventOccurrence_Attribute_execution->setLowerBound(1);
	m_invocationEventOccurrence_Attribute_execution->setUpperBound(1);
	m_invocationEventOccurrence_Attribute_execution->setTransient(false);
	m_invocationEventOccurrence_Attribute_execution->setVolatile(false);
	m_invocationEventOccurrence_Attribute_execution->setChangeable(true);
	m_invocationEventOccurrence_Attribute_execution->setUnsettable(false);
	m_invocationEventOccurrence_Attribute_execution->setUnique(true);
	m_invocationEventOccurrence_Attribute_execution->setDerived(false);
	m_invocationEventOccurrence_Attribute_execution->setOrdered(true);
	m_invocationEventOccurrence_Attribute_execution->setContainment(false);
	m_invocationEventOccurrence_Attribute_execution->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_invocationEventOccurrence_Attribute_execution->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_invocationEventOccurrence_Operation_getParameterValues->setEType(getParameterValue_Class());
	m_invocationEventOccurrence_Operation_getParameterValues->setName("getParameterValues");
	m_invocationEventOccurrence_Operation_getParameterValues->setLowerBound(0);
	m_invocationEventOccurrence_Operation_getParameterValues->setUpperBound(-1);
	m_invocationEventOccurrence_Operation_getParameterValues->setUnique(true);
	m_invocationEventOccurrence_Operation_getParameterValues->setOrdered(true);
	
	
	m_invocationEventOccurrence_Operation_match_Trigger->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_invocationEventOccurrence_Operation_match_Trigger->setName("match");
	m_invocationEventOccurrence_Operation_match_Trigger->setLowerBound(0);
	m_invocationEventOccurrence_Operation_match_Trigger->setUpperBound(1);
	m_invocationEventOccurrence_Operation_match_Trigger->setUnique(true);
	m_invocationEventOccurrence_Operation_match_Trigger->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_invocationEventOccurrence_Operation_match_Trigger);
		parameter->setName("trigger");
		parameter->setEType(uml::UmlPackage::eInstance()->getTrigger_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void CommonBehaviorPackageImpl::initializeObjectActivationContent()
{
	m_objectActivation_Class->setName("ObjectActivation");
	m_objectActivation_Class->setAbstract(false);
	m_objectActivation_Class->setInterface(false);
	
	
	m_objectActivation_Attribute_classifierBehaviorExecutions->setName("classifierBehaviorExecutions");
	m_objectActivation_Attribute_classifierBehaviorExecutions->setEType(getClassifierBehaviorExecution_Class());
	m_objectActivation_Attribute_classifierBehaviorExecutions->setLowerBound(0);
	m_objectActivation_Attribute_classifierBehaviorExecutions->setUpperBound(-1);
	m_objectActivation_Attribute_classifierBehaviorExecutions->setTransient(false);
	m_objectActivation_Attribute_classifierBehaviorExecutions->setVolatile(false);
	m_objectActivation_Attribute_classifierBehaviorExecutions->setChangeable(true);
	m_objectActivation_Attribute_classifierBehaviorExecutions->setUnsettable(false);
	m_objectActivation_Attribute_classifierBehaviorExecutions->setUnique(true);
	m_objectActivation_Attribute_classifierBehaviorExecutions->setDerived(false);
	m_objectActivation_Attribute_classifierBehaviorExecutions->setOrdered(false);
	m_objectActivation_Attribute_classifierBehaviorExecutions->setContainment(true);
	m_objectActivation_Attribute_classifierBehaviorExecutions->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_objectActivation_Attribute_classifierBehaviorExecutions->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_objectActivation_Attribute_eventPool->setName("eventPool");
	m_objectActivation_Attribute_eventPool->setEType(fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getSignalInstance_Class());
	m_objectActivation_Attribute_eventPool->setLowerBound(0);
	m_objectActivation_Attribute_eventPool->setUpperBound(-1);
	m_objectActivation_Attribute_eventPool->setTransient(false);
	m_objectActivation_Attribute_eventPool->setVolatile(false);
	m_objectActivation_Attribute_eventPool->setChangeable(true);
	m_objectActivation_Attribute_eventPool->setUnsettable(false);
	m_objectActivation_Attribute_eventPool->setUnique(true);
	m_objectActivation_Attribute_eventPool->setDerived(false);
	m_objectActivation_Attribute_eventPool->setOrdered(false);
	m_objectActivation_Attribute_eventPool->setContainment(true);
	m_objectActivation_Attribute_eventPool->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_objectActivation_Attribute_eventPool->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_objectActivation_Attribute_object->setName("object");
	m_objectActivation_Attribute_object->setEType(fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getObject_Class());
	m_objectActivation_Attribute_object->setLowerBound(1);
	m_objectActivation_Attribute_object->setUpperBound(1);
	m_objectActivation_Attribute_object->setTransient(false);
	m_objectActivation_Attribute_object->setVolatile(false);
	m_objectActivation_Attribute_object->setChangeable(true);
	m_objectActivation_Attribute_object->setUnsettable(false);
	m_objectActivation_Attribute_object->setUnique(true);
	m_objectActivation_Attribute_object->setDerived(false);
	m_objectActivation_Attribute_object->setOrdered(false);
	m_objectActivation_Attribute_object->setContainment(false);
	m_objectActivation_Attribute_object->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_objectActivation_Attribute_object->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_objectActivation_Attribute_waitingEventAccepters->setName("waitingEventAccepters");
	m_objectActivation_Attribute_waitingEventAccepters->setEType(getEventAccepter_Class());
	m_objectActivation_Attribute_waitingEventAccepters->setLowerBound(0);
	m_objectActivation_Attribute_waitingEventAccepters->setUpperBound(-1);
	m_objectActivation_Attribute_waitingEventAccepters->setTransient(false);
	m_objectActivation_Attribute_waitingEventAccepters->setVolatile(false);
	m_objectActivation_Attribute_waitingEventAccepters->setChangeable(true);
	m_objectActivation_Attribute_waitingEventAccepters->setUnsettable(false);
	m_objectActivation_Attribute_waitingEventAccepters->setUnique(true);
	m_objectActivation_Attribute_waitingEventAccepters->setDerived(false);
	m_objectActivation_Attribute_waitingEventAccepters->setOrdered(false);
	m_objectActivation_Attribute_waitingEventAccepters->setContainment(false);
	m_objectActivation_Attribute_waitingEventAccepters->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_objectActivation_Attribute_waitingEventAccepters->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_objectActivation_Operation__register_EventAccepter->setEType(nullptr);
	m_objectActivation_Operation__register_EventAccepter->setName("_register");
	m_objectActivation_Operation__register_EventAccepter->setLowerBound(1);
	m_objectActivation_Operation__register_EventAccepter->setUpperBound(1);
	m_objectActivation_Operation__register_EventAccepter->setUnique(true);
	m_objectActivation_Operation__register_EventAccepter->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_objectActivation_Operation__register_EventAccepter);
		parameter->setName("accepter");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_objectActivation_Operation__send_EJavaObject->setEType(nullptr);
	m_objectActivation_Operation__send_EJavaObject->setName("_send");
	m_objectActivation_Operation__send_EJavaObject->setLowerBound(1);
	m_objectActivation_Operation__send_EJavaObject->setUpperBound(1);
	m_objectActivation_Operation__send_EJavaObject->setUnique(true);
	m_objectActivation_Operation__send_EJavaObject->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_objectActivation_Operation__send_EJavaObject);
		parameter->setName("signal");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_objectActivation_Operation__startObjectBehavior->setEType(nullptr);
	m_objectActivation_Operation__startObjectBehavior->setName("_startObjectBehavior");
	m_objectActivation_Operation__startObjectBehavior->setLowerBound(1);
	m_objectActivation_Operation__startObjectBehavior->setUpperBound(1);
	m_objectActivation_Operation__startObjectBehavior->setUnique(true);
	m_objectActivation_Operation__startObjectBehavior->setOrdered(false);
	
	
	m_objectActivation_Operation_dispatchNextEvent->setEType(nullptr);
	m_objectActivation_Operation_dispatchNextEvent->setName("dispatchNextEvent");
	m_objectActivation_Operation_dispatchNextEvent->setLowerBound(1);
	m_objectActivation_Operation_dispatchNextEvent->setUpperBound(1);
	m_objectActivation_Operation_dispatchNextEvent->setUnique(true);
	m_objectActivation_Operation_dispatchNextEvent->setOrdered(false);
	
	
	m_objectActivation_Operation_retrieveNextEvent->setEType(fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getSignalInstance_Class());
	m_objectActivation_Operation_retrieveNextEvent->setName("retrieveNextEvent");
	m_objectActivation_Operation_retrieveNextEvent->setLowerBound(1);
	m_objectActivation_Operation_retrieveNextEvent->setUpperBound(1);
	m_objectActivation_Operation_retrieveNextEvent->setUnique(true);
	m_objectActivation_Operation_retrieveNextEvent->setOrdered(false);
	
	
	m_objectActivation_Operation_send_SignalInstance->setEType(nullptr);
	m_objectActivation_Operation_send_SignalInstance->setName("send");
	m_objectActivation_Operation_send_SignalInstance->setLowerBound(1);
	m_objectActivation_Operation_send_SignalInstance->setUpperBound(1);
	m_objectActivation_Operation_send_SignalInstance->setUnique(true);
	m_objectActivation_Operation_send_SignalInstance->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_objectActivation_Operation_send_SignalInstance);
		parameter->setName("signalInstance");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_objectActivation_Operation_startBehavior_Class_ParameterValue->setEType(nullptr);
	m_objectActivation_Operation_startBehavior_Class_ParameterValue->setName("startBehavior");
	m_objectActivation_Operation_startBehavior_Class_ParameterValue->setLowerBound(1);
	m_objectActivation_Operation_startBehavior_Class_ParameterValue->setUpperBound(1);
	m_objectActivation_Operation_startBehavior_Class_ParameterValue->setUnique(true);
	m_objectActivation_Operation_startBehavior_Class_ParameterValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_objectActivation_Operation_startBehavior_Class_ParameterValue);
		parameter->setName("classifier");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_objectActivation_Operation_startBehavior_Class_ParameterValue);
		parameter->setName("inputs");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_objectActivation_Operation_stop->setEType(nullptr);
	m_objectActivation_Operation_stop->setName("stop");
	m_objectActivation_Operation_stop->setLowerBound(1);
	m_objectActivation_Operation_stop->setUpperBound(1);
	m_objectActivation_Operation_stop->setUnique(true);
	m_objectActivation_Operation_stop->setOrdered(false);
	
	
	m_objectActivation_Operation_unregister_EventAccepter->setEType(nullptr);
	m_objectActivation_Operation_unregister_EventAccepter->setName("unregister");
	m_objectActivation_Operation_unregister_EventAccepter->setLowerBound(1);
	m_objectActivation_Operation_unregister_EventAccepter->setUpperBound(1);
	m_objectActivation_Operation_unregister_EventAccepter->setUnique(true);
	m_objectActivation_Operation_unregister_EventAccepter->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_objectActivation_Operation_unregister_EventAccepter);
		parameter->setName("accepter");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void CommonBehaviorPackageImpl::initializeOpaqueBehaviorExecutionContent()
{
	m_opaqueBehaviorExecution_Class->setName("OpaqueBehaviorExecution");
	m_opaqueBehaviorExecution_Class->setAbstract(true);
	m_opaqueBehaviorExecution_Class->setInterface(false);
	
	
	
	m_opaqueBehaviorExecution_Operation_doBody_ParameterValue_ParameterValue->setEType(nullptr);
	m_opaqueBehaviorExecution_Operation_doBody_ParameterValue_ParameterValue->setName("doBody");
	m_opaqueBehaviorExecution_Operation_doBody_ParameterValue_ParameterValue->setLowerBound(1);
	m_opaqueBehaviorExecution_Operation_doBody_ParameterValue_ParameterValue->setUpperBound(1);
	m_opaqueBehaviorExecution_Operation_doBody_ParameterValue_ParameterValue->setUnique(true);
	m_opaqueBehaviorExecution_Operation_doBody_ParameterValue_ParameterValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_opaqueBehaviorExecution_Operation_doBody_ParameterValue_ParameterValue);
		parameter->setName("inputParameters");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_opaqueBehaviorExecution_Operation_doBody_ParameterValue_ParameterValue);
		parameter->setName("outputParameters");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_opaqueBehaviorExecution_Operation_execute->setEType(nullptr);
	m_opaqueBehaviorExecution_Operation_execute->setName("execute");
	m_opaqueBehaviorExecution_Operation_execute->setLowerBound(1);
	m_opaqueBehaviorExecution_Operation_execute->setUpperBound(1);
	m_opaqueBehaviorExecution_Operation_execute->setUnique(true);
	m_opaqueBehaviorExecution_Operation_execute->setOrdered(false);
	
	
	
}

void CommonBehaviorPackageImpl::initializeParameterValueContent()
{
	m_parameterValue_Class->setName("ParameterValue");
	m_parameterValue_Class->setAbstract(false);
	m_parameterValue_Class->setInterface(false);
	
	
	m_parameterValue_Attribute_parameter->setName("parameter");
	m_parameterValue_Attribute_parameter->setEType(uml::UmlPackage::eInstance()->getParameter_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_parameterValue_Attribute_parameter->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_parameterValue_Attribute_values->setName("values");
	m_parameterValue_Attribute_values->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_parameterValue_Attribute_values->setLowerBound(0);
	m_parameterValue_Attribute_values->setUpperBound(-1);
	m_parameterValue_Attribute_values->setTransient(false);
	m_parameterValue_Attribute_values->setVolatile(false);
	m_parameterValue_Attribute_values->setChangeable(true);
	m_parameterValue_Attribute_values->setUnsettable(false);
	m_parameterValue_Attribute_values->setUnique(true);
	m_parameterValue_Attribute_values->setDerived(false);
	m_parameterValue_Attribute_values->setOrdered(false);
	m_parameterValue_Attribute_values->setContainment(true);
	m_parameterValue_Attribute_values->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_parameterValue_Attribute_values->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_parameterValue_Operation__copy->setEType(getParameterValue_Class());
	m_parameterValue_Operation__copy->setName("_copy");
	m_parameterValue_Operation__copy->setLowerBound(1);
	m_parameterValue_Operation__copy->setUpperBound(1);
	m_parameterValue_Operation__copy->setUnique(true);
	m_parameterValue_Operation__copy->setOrdered(true);
	
	
	
}

void CommonBehaviorPackageImpl::initializeSignalEventOccurrenceContent()
{
	m_signalEventOccurrence_Class->setName("SignalEventOccurrence");
	m_signalEventOccurrence_Class->setAbstract(false);
	m_signalEventOccurrence_Class->setInterface(false);
	
	
	m_signalEventOccurrence_Attribute_signalInstance->setName("signalInstance");
	m_signalEventOccurrence_Attribute_signalInstance->setEType(fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getSignalInstance_Class());
	m_signalEventOccurrence_Attribute_signalInstance->setLowerBound(1);
	m_signalEventOccurrence_Attribute_signalInstance->setUpperBound(1);
	m_signalEventOccurrence_Attribute_signalInstance->setTransient(false);
	m_signalEventOccurrence_Attribute_signalInstance->setVolatile(false);
	m_signalEventOccurrence_Attribute_signalInstance->setChangeable(true);
	m_signalEventOccurrence_Attribute_signalInstance->setUnsettable(false);
	m_signalEventOccurrence_Attribute_signalInstance->setUnique(true);
	m_signalEventOccurrence_Attribute_signalInstance->setDerived(false);
	m_signalEventOccurrence_Attribute_signalInstance->setOrdered(true);
	m_signalEventOccurrence_Attribute_signalInstance->setContainment(false);
	m_signalEventOccurrence_Attribute_signalInstance->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_signalEventOccurrence_Attribute_signalInstance->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_signalEventOccurrence_Operation_getParameterValues->setEType(getParameterValue_Class());
	m_signalEventOccurrence_Operation_getParameterValues->setName("getParameterValues");
	m_signalEventOccurrence_Operation_getParameterValues->setLowerBound(0);
	m_signalEventOccurrence_Operation_getParameterValues->setUpperBound(-1);
	m_signalEventOccurrence_Operation_getParameterValues->setUnique(true);
	m_signalEventOccurrence_Operation_getParameterValues->setOrdered(true);
	
	
	m_signalEventOccurrence_Operation_match_Trigger->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_signalEventOccurrence_Operation_match_Trigger->setName("match");
	m_signalEventOccurrence_Operation_match_Trigger->setLowerBound(0);
	m_signalEventOccurrence_Operation_match_Trigger->setUpperBound(1);
	m_signalEventOccurrence_Operation_match_Trigger->setUnique(true);
	m_signalEventOccurrence_Operation_match_Trigger->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_signalEventOccurrence_Operation_match_Trigger);
		parameter->setName("trigger");
		parameter->setEType(uml::UmlPackage::eInstance()->getTrigger_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void CommonBehaviorPackageImpl::initializePackageEDataTypes()
{
	
}

