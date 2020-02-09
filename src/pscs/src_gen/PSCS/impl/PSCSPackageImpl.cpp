#include "PSCS/impl/PSCSPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EEnumLiteral.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

//metamodel factory
#include "PSCS/PSCSFactory.hpp"

//depending model packages
#include "ecore/EcorePackage.hpp"
#include "fUML/FUMLPackage.hpp"
#include "types/TypesPackage.hpp"
#include "uml/UmlPackage.hpp"

using namespace PSCS;

bool PSCSPackageImpl::isInited = false;

PSCSPackageImpl::PSCSPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( PSCSFactory::eInstance()));
}

PSCSPackageImpl::~PSCSPackageImpl()
{
}

PSCSPackage* PSCSPackageImpl::create()
{
	if (isInited)
	{
		return PSCSPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    PSCSPackageImpl * metaModelPackage = new PSCSPackageImpl();
    return metaModelPackage;
}

void PSCSPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}

// Begin Class CS_AcceptCallActionActivation
std::shared_ptr<ecore::EClass> PSCSPackageImpl::getCS_AcceptCallActionActivation_Class() const
{
	return m_cS_AcceptCallActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_AcceptCallActionActivation_Operation_accept_EventOccurrence() const
{
	return m_cS_AcceptCallActionActivation_Operation_accept_EventOccurrence;
}

// End Class CS_AcceptCallActionActivation

// Begin Class CS_AcceptEventActionActivation
std::shared_ptr<ecore::EClass> PSCSPackageImpl::getCS_AcceptEventActionActivation_Class() const
{
	return m_cS_AcceptEventActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_AcceptEventActionActivation_Operation_accept_EventOccurrence() const
{
	return m_cS_AcceptEventActionActivation_Operation_accept_EventOccurrence;
}

// End Class CS_AcceptEventActionActivation

// Begin Class CS_AddStructuralFeatureValueActionActivation
std::shared_ptr<ecore::EClass> PSCSPackageImpl::getCS_AddStructuralFeatureValueActionActivation_Class() const
{
	return m_cS_AddStructuralFeatureValueActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_AddStructuralFeatureValueActionActivation_Operation_doAction() const
{
	return m_cS_AddStructuralFeatureValueActionActivation_Operation_doAction;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_AddStructuralFeatureValueActionActivation_Operation_doActionDefault() const
{
	return m_cS_AddStructuralFeatureValueActionActivation_Operation_doActionDefault;
}

// End Class CS_AddStructuralFeatureValueActionActivation

// Begin Class CS_CallEventExecution
std::shared_ptr<ecore::EClass> PSCSPackageImpl::getCS_CallEventExecution_Class() const
{
	return m_cS_CallEventExecution_Class;
}


std::shared_ptr<ecore::EReference> PSCSPackageImpl::getCS_CallEventExecution_Attribute_interactionPoint() const
{
	return m_cS_CallEventExecution_Attribute_interactionPoint;
}

std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_CallEventExecution_Operation_copy() const
{
	return m_cS_CallEventExecution_Operation_copy;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_CallEventExecution_Operation_createEventOccurrence() const
{
	return m_cS_CallEventExecution_Operation_createEventOccurrence;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_CallEventExecution_Operation_new_() const
{
	return m_cS_CallEventExecution_Operation_new_;
}

// End Class CS_CallEventExecution

// Begin Class CS_CallOperationActionActivation
std::shared_ptr<ecore::EClass> PSCSPackageImpl::getCS_CallOperationActionActivation_Class() const
{
	return m_cS_CallOperationActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_CallOperationActionActivation_Operation__isCreate_Operation() const
{
	return m_cS_CallOperationActionActivation_Operation__isCreate_Operation;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_CallOperationActionActivation_Operation_doAction() const
{
	return m_cS_CallOperationActionActivation_Operation_doAction;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_CallOperationActionActivation_Operation_getCallExecution() const
{
	return m_cS_CallOperationActionActivation_Operation_getCallExecution;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_CallOperationActionActivation_Operation_isCreate_Operation() const
{
	return m_cS_CallOperationActionActivation_Operation_isCreate_Operation;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_CallOperationActionActivation_Operation_isOperationProvided_Port_Operation() const
{
	return m_cS_CallOperationActionActivation_Operation_isOperationProvided_Port_Operation;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_CallOperationActionActivation_Operation_isOperationRequired_Port_Operation() const
{
	return m_cS_CallOperationActionActivation_Operation_isOperationRequired_Port_Operation;
}

// End Class CS_CallOperationActionActivation

// Begin Class CS_ClearStructuralFeatureActionActivation
std::shared_ptr<ecore::EClass> PSCSPackageImpl::getCS_ClearStructuralFeatureActionActivation_Class() const
{
	return m_cS_ClearStructuralFeatureActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_ClearStructuralFeatureActionActivation_Operation_doAction() const
{
	return m_cS_ClearStructuralFeatureActionActivation_Operation_doAction;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_ClearStructuralFeatureActionActivation_Operation_getLinksToDestroy_StructuredValue_StructuralFeature() const
{
	return m_cS_ClearStructuralFeatureActionActivation_Operation_getLinksToDestroy_StructuredValue_StructuralFeature;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_ClearStructuralFeatureActionActivation_Operation_getPotentialLinkEnds_CS_Reference_StructuralFeature() const
{
	return m_cS_ClearStructuralFeatureActionActivation_Operation_getPotentialLinkEnds_CS_Reference_StructuralFeature;
}

// End Class CS_ClearStructuralFeatureActionActivation

// Begin Class CS_ConstructStrategy
std::shared_ptr<ecore::EClass> PSCSPackageImpl::getCS_ConstructStrategy_Class() const
{
	return m_cS_ConstructStrategy_Class;
}



std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_ConstructStrategy_Operation_construct_Operation_CS_Object() const
{
	return m_cS_ConstructStrategy_Operation_construct_Operation_CS_Object;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_ConstructStrategy_Operation_getName() const
{
	return m_cS_ConstructStrategy_Operation_getName;
}

// End Class CS_ConstructStrategy

// Begin Class CS_CreateLinkActionActivation
std::shared_ptr<ecore::EClass> PSCSPackageImpl::getCS_CreateLinkActionActivation_Class() const
{
	return m_cS_CreateLinkActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_CreateLinkActionActivation_Operation_doAction() const
{
	return m_cS_CreateLinkActionActivation_Operation_doAction;
}

// End Class CS_CreateLinkActionActivation

// Begin Class CS_CreateObjectActionActivation
std::shared_ptr<ecore::EClass> PSCSPackageImpl::getCS_CreateObjectActionActivation_Class() const
{
	return m_cS_CreateObjectActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_CreateObjectActionActivation_Operation_doAction() const
{
	return m_cS_CreateObjectActionActivation_Operation_doAction;
}

// End Class CS_CreateObjectActionActivation

// Begin Class CS_DefaultConstructStrategy
std::shared_ptr<ecore::EClass> PSCSPackageImpl::getCS_DefaultConstructStrategy_Class() const
{
	return m_cS_DefaultConstructStrategy_Class;
}


std::shared_ptr<ecore::EReference> PSCSPackageImpl::getCS_DefaultConstructStrategy_Attribute_defaultAssociation() const
{
	return m_cS_DefaultConstructStrategy_Attribute_defaultAssociation;
}
std::shared_ptr<ecore::EReference> PSCSPackageImpl::getCS_DefaultConstructStrategy_Attribute_generatedRealizingClasses() const
{
	return m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses;
}
std::shared_ptr<ecore::EReference> PSCSPackageImpl::getCS_DefaultConstructStrategy_Attribute_locus() const
{
	return m_cS_DefaultConstructStrategy_Attribute_locus;
}

std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_DefaultConstructStrategy_Operation_addStructuralFeatureValue_CS_Reference_Value() const
{
	return m_cS_DefaultConstructStrategy_Operation_addStructuralFeatureValue_CS_Reference_Value;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_DefaultConstructStrategy_Operation_canInstantiate_Property() const
{
	return m_cS_DefaultConstructStrategy_Operation_canInstantiate_Property;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_DefaultConstructStrategy_Operation_construct_Operation_CS_Object() const
{
	return m_cS_DefaultConstructStrategy_Operation_construct_Operation_CS_Object;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_DefaultConstructStrategy_Operation_constructObject_CS_Object_Class() const
{
	return m_cS_DefaultConstructStrategy_Operation_constructObject_CS_Object_Class;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_DefaultConstructStrategy_Operation_generateArrayPattern_CS_Reference_Connector() const
{
	return m_cS_DefaultConstructStrategy_Operation_generateArrayPattern_CS_Reference_Connector;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_DefaultConstructStrategy_Operation_generateRealizingClass_Interface_EString() const
{
	return m_cS_DefaultConstructStrategy_Operation_generateRealizingClass_Interface_EString;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_DefaultConstructStrategy_Operation_generateStarPattern_CS_Reference_Connector() const
{
	return m_cS_DefaultConstructStrategy_Operation_generateStarPattern_CS_Reference_Connector;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_DefaultConstructStrategy_Operation_getCardinality_ConnectorEnd() const
{
	return m_cS_DefaultConstructStrategy_Operation_getCardinality_ConnectorEnd;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_DefaultConstructStrategy_Operation_getDefaultAssociation() const
{
	return m_cS_DefaultConstructStrategy_Operation_getDefaultAssociation;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_DefaultConstructStrategy_Operation_getRealizingClass_Interface() const
{
	return m_cS_DefaultConstructStrategy_Operation_getRealizingClass_Interface;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_DefaultConstructStrategy_Operation_getValuesFromConnectorEnd_CS_Reference_ConnectorEnd() const
{
	return m_cS_DefaultConstructStrategy_Operation_getValuesFromConnectorEnd_CS_Reference_ConnectorEnd;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_DefaultConstructStrategy_Operation_instantiateInterface_Interface_Locus() const
{
	return m_cS_DefaultConstructStrategy_Operation_instantiateInterface_Interface_Locus;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_DefaultConstructStrategy_Operation_isArrayPattern_Connector() const
{
	return m_cS_DefaultConstructStrategy_Operation_isArrayPattern_Connector;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_DefaultConstructStrategy_Operation_isStarPattern_Connector() const
{
	return m_cS_DefaultConstructStrategy_Operation_isStarPattern_Connector;
}

// End Class CS_DefaultConstructStrategy

// Begin Class CS_DefaultRequestPropagationStrategy
std::shared_ptr<ecore::EClass> PSCSPackageImpl::getCS_DefaultRequestPropagationStrategy_Class() const
{
	return m_cS_DefaultRequestPropagationStrategy_Class;
}



std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_DefaultRequestPropagationStrategy_Operation_select_Reference_SemanticVisitor() const
{
	return m_cS_DefaultRequestPropagationStrategy_Operation_select_Reference_SemanticVisitor;
}

// End Class CS_DefaultRequestPropagationStrategy

// Begin Class CS_DispatchOperationOfInterfaceStrategy
std::shared_ptr<ecore::EClass> PSCSPackageImpl::getCS_DispatchOperationOfInterfaceStrategy_Class() const
{
	return m_cS_DispatchOperationOfInterfaceStrategy_Class;
}



std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_DispatchOperationOfInterfaceStrategy_Operation_operationsMatch_Operation_Operation() const
{
	return m_cS_DispatchOperationOfInterfaceStrategy_Operation_operationsMatch_Operation_Operation;
}

// End Class CS_DispatchOperationOfInterfaceStrategy

// Begin Class CS_EventOccurrence
std::shared_ptr<ecore::EClass> PSCSPackageImpl::getCS_EventOccurrence_Class() const
{
	return m_cS_EventOccurrence_Class;
}

std::shared_ptr<ecore::EAttribute> PSCSPackageImpl::getCS_EventOccurrence_Attribute_propagationInward() const
{
	return m_cS_EventOccurrence_Attribute_propagationInward;
}

std::shared_ptr<ecore::EReference> PSCSPackageImpl::getCS_EventOccurrence_Attribute_interactionPoint() const
{
	return m_cS_EventOccurrence_Attribute_interactionPoint;
}
std::shared_ptr<ecore::EReference> PSCSPackageImpl::getCS_EventOccurrence_Attribute_onPort() const
{
	return m_cS_EventOccurrence_Attribute_onPort;
}
std::shared_ptr<ecore::EReference> PSCSPackageImpl::getCS_EventOccurrence_Attribute_wrappedEventOccurrence() const
{
	return m_cS_EventOccurrence_Attribute_wrappedEventOccurrence;
}

std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_EventOccurrence_Operation_doSend() const
{
	return m_cS_EventOccurrence_Operation_doSend;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_EventOccurrence_Operation_getParameterValues() const
{
	return m_cS_EventOccurrence_Operation_getParameterValues;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_EventOccurrence_Operation_match_Trigger() const
{
	return m_cS_EventOccurrence_Operation_match_Trigger;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_EventOccurrence_Operation_sendInTo_CS_Reference_Port() const
{
	return m_cS_EventOccurrence_Operation_sendInTo_CS_Reference_Port;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_EventOccurrence_Operation_sendOutTo_CS_Reference_Port() const
{
	return m_cS_EventOccurrence_Operation_sendOutTo_CS_Reference_Port;
}

// End Class CS_EventOccurrence

// Begin Class CS_ExecutionFactory
std::shared_ptr<ecore::EClass> PSCSPackageImpl::getCS_ExecutionFactory_Class() const
{
	return m_cS_ExecutionFactory_Class;
}


std::shared_ptr<ecore::EReference> PSCSPackageImpl::getCS_ExecutionFactory_Attribute_appliedProfiles() const
{
	return m_cS_ExecutionFactory_Attribute_appliedProfiles;
}

std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_ExecutionFactory_Operation_getStereotypeApplication_Class_Element() const
{
	return m_cS_ExecutionFactory_Operation_getStereotypeApplication_Class_Element;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_ExecutionFactory_Operation_getStereotypeClass_EString_EString() const
{
	return m_cS_ExecutionFactory_Operation_getStereotypeClass_EString_EString;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_ExecutionFactory_Operation_instantiateVisitor_Element() const
{
	return m_cS_ExecutionFactory_Operation_instantiateVisitor_Element;
}

// End Class CS_ExecutionFactory

// Begin Class CS_Executor
std::shared_ptr<ecore::EClass> PSCSPackageImpl::getCS_Executor_Class() const
{
	return m_cS_Executor_Class;
}



std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Executor_Operation_start_Class_ParameterValue() const
{
	return m_cS_Executor_Operation_start_Class_ParameterValue;
}

// End Class CS_Executor

// Begin Class CS_InstanceValueEvaluation
std::shared_ptr<ecore::EClass> PSCSPackageImpl::getCS_InstanceValueEvaluation_Class() const
{
	return m_cS_InstanceValueEvaluation_Class;
}



std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_InstanceValueEvaluation_Operation_evaluate() const
{
	return m_cS_InstanceValueEvaluation_Operation_evaluate;
}

// End Class CS_InstanceValueEvaluation

// Begin Class CS_InteractionPoint
std::shared_ptr<ecore::EClass> PSCSPackageImpl::getCS_InteractionPoint_Class() const
{
	return m_cS_InteractionPoint_Class;
}


std::shared_ptr<ecore::EReference> PSCSPackageImpl::getCS_InteractionPoint_Attribute_definingPort() const
{
	return m_cS_InteractionPoint_Attribute_definingPort;
}
std::shared_ptr<ecore::EReference> PSCSPackageImpl::getCS_InteractionPoint_Attribute_owner() const
{
	return m_cS_InteractionPoint_Attribute_owner;
}

std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_InteractionPoint_Operation_checkAllParents_Classifier_Classifier() const
{
	return m_cS_InteractionPoint_Operation_checkAllParents_Classifier_Classifier;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_InteractionPoint_Operation_dispatch_Operation() const
{
	return m_cS_InteractionPoint_Operation_dispatch_Operation;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_InteractionPoint_Operation_send_EventOccurrence() const
{
	return m_cS_InteractionPoint_Operation_send_EventOccurrence;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_InteractionPoint_Operation_startBehavior_Class_ParameterValue() const
{
	return m_cS_InteractionPoint_Operation_startBehavior_Class_ParameterValue;
}

// End Class CS_InteractionPoint

// Begin Class CS_Link
std::shared_ptr<ecore::EClass> PSCSPackageImpl::getCS_Link_Class() const
{
	return m_cS_Link_Class;
}



std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Link_Operation_getFeature_Value() const
{
	return m_cS_Link_Operation_getFeature_Value;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Link_Operation_hasValueForAFeature_Value() const
{
	return m_cS_Link_Operation_hasValueForAFeature_Value;
}

// End Class CS_Link

// Begin Class CS_Locus
std::shared_ptr<ecore::EClass> PSCSPackageImpl::getCS_Locus_Class() const
{
	return m_cS_Locus_Class;
}



std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Locus_Operation_instantiate_Class() const
{
	return m_cS_Locus_Operation_instantiate_Class;
}

// End Class CS_Locus

// Begin Class CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy
std::shared_ptr<ecore::EClass> PSCSPackageImpl::getCS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Class() const
{
	return m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Class;
}



std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature() const
{
	return m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_EInt() const
{
	return m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_EInt;
}

// End Class CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy

// Begin Class CS_Object
std::shared_ptr<ecore::EClass> PSCSPackageImpl::getCS_Object_Class() const
{
	return m_cS_Object_Class;
}



std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Object_Operation_checkAllParents_Classifier_Classifier() const
{
	return m_cS_Object_Operation_checkAllParents_Classifier_Classifier;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Object_Operation_contains_Object() const
{
	return m_cS_Object_Operation_contains_Object;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Object_Operation_directlyContains_Object() const
{
	return m_cS_Object_Operation_directlyContains_Object;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Object_Operation_dispatchIn_Operation_CS_InteractionPoint() const
{
	return m_cS_Object_Operation_dispatchIn_Operation_CS_InteractionPoint;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Object_Operation_dispatchIn_Operation_Port() const
{
	return m_cS_Object_Operation_dispatchIn_Operation_Port;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Object_Operation_dispatchOut_Operation_CS_InteractionPoint() const
{
	return m_cS_Object_Operation_dispatchOut_Operation_CS_InteractionPoint;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Object_Operation_dispatchOut_Operation_Port() const
{
	return m_cS_Object_Operation_dispatchOut_Operation_Port;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Object_Operation_getDirectContainers() const
{
	return m_cS_Object_Operation_getDirectContainers;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Object_Operation_getFeatureValue_StructuralFeature() const
{
	return m_cS_Object_Operation_getFeatureValue_StructuralFeature;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Object_Operation_getLinkKind_CS_Link_CS_InteractionPoint() const
{
	return m_cS_Object_Operation_getLinkKind_CS_Link_CS_InteractionPoint;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Object_Operation_getLinks_CS_InteractionPoint() const
{
	return m_cS_Object_Operation_getLinks_CS_InteractionPoint;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Object_Operation_hasValueForAFeature_Value() const
{
	return m_cS_Object_Operation_hasValueForAFeature_Value;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Object_Operation_isDescendant_Interface_Interface() const
{
	return m_cS_Object_Operation_isDescendant_Interface_Interface;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Object_Operation_isOperationProvided_Reference_Operation() const
{
	return m_cS_Object_Operation_isOperationProvided_Reference_Operation;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Object_Operation_isOperationRequired_Reference_Operation() const
{
	return m_cS_Object_Operation_isOperationRequired_Reference_Operation;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Object_Operation_realizesInterface_Class_Interface() const
{
	return m_cS_Object_Operation_realizesInterface_Class_Interface;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Object_Operation_selectTargetsForDispatching_CS_Link_EBoolean() const
{
	return m_cS_Object_Operation_selectTargetsForDispatching_CS_Link_EBoolean;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Object_Operation_selectTargetsForSending_CS_Link_EBoolean() const
{
	return m_cS_Object_Operation_selectTargetsForSending_CS_Link_EBoolean;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Object_Operation_sendIn_EventOccurrence_CS_InteractionPoint() const
{
	return m_cS_Object_Operation_sendIn_EventOccurrence_CS_InteractionPoint;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Object_Operation_sendIn_EventOccurrence_Port() const
{
	return m_cS_Object_Operation_sendIn_EventOccurrence_Port;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Object_Operation_sendOut_EventOccurrence_CS_InteractionPoint() const
{
	return m_cS_Object_Operation_sendOut_EventOccurrence_CS_InteractionPoint;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Object_Operation_sendOut_EventOccurrence_Port() const
{
	return m_cS_Object_Operation_sendOut_EventOccurrence_Port;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Object_Operation_setFeatureValue_StructuralFeature_EInt() const
{
	return m_cS_Object_Operation_setFeatureValue_StructuralFeature_EInt;
}

// End Class CS_Object

// Begin Class CS_OpaqueExpressionEvaluation
std::shared_ptr<ecore::EClass> PSCSPackageImpl::getCS_OpaqueExpressionEvaluation_Class() const
{
	return m_cS_OpaqueExpressionEvaluation_Class;
}



std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_OpaqueExpressionEvaluation_Operation_evaluate() const
{
	return m_cS_OpaqueExpressionEvaluation_Operation_evaluate;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_OpaqueExpressionEvaluation_Operation_executeExpressionBehavior() const
{
	return m_cS_OpaqueExpressionEvaluation_Operation_executeExpressionBehavior;
}

// End Class CS_OpaqueExpressionEvaluation

// Begin Class CS_ReadExtentActionActivation
std::shared_ptr<ecore::EClass> PSCSPackageImpl::getCS_ReadExtentActionActivation_Class() const
{
	return m_cS_ReadExtentActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_ReadExtentActionActivation_Operation_doAction() const
{
	return m_cS_ReadExtentActionActivation_Operation_doAction;
}

// End Class CS_ReadExtentActionActivation

// Begin Class CS_ReadSelfActionActivation
std::shared_ptr<ecore::EClass> PSCSPackageImpl::getCS_ReadSelfActionActivation_Class() const
{
	return m_cS_ReadSelfActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_ReadSelfActionActivation_Operation_doAction() const
{
	return m_cS_ReadSelfActionActivation_Operation_doAction;
}

// End Class CS_ReadSelfActionActivation

// Begin Class CS_Reference
std::shared_ptr<ecore::EClass> PSCSPackageImpl::getCS_Reference_Class() const
{
	return m_cS_Reference_Class;
}


std::shared_ptr<ecore::EReference> PSCSPackageImpl::getCS_Reference_Attribute_compositeReferent() const
{
	return m_cS_Reference_Attribute_compositeReferent;
}

std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Reference_Operation_copy() const
{
	return m_cS_Reference_Operation_copy;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Reference_Operation_dispatchIn_Operation_CS_InteractionPoint() const
{
	return m_cS_Reference_Operation_dispatchIn_Operation_CS_InteractionPoint;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Reference_Operation_dispatchIn_Operation_Port() const
{
	return m_cS_Reference_Operation_dispatchIn_Operation_Port;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Reference_Operation_dispatchOut_Operation_Port() const
{
	return m_cS_Reference_Operation_dispatchOut_Operation_Port;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Reference_Operation_dispatchOut_Operation_CS_InteractionPoint() const
{
	return m_cS_Reference_Operation_dispatchOut_Operation_CS_InteractionPoint;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Reference_Operation_sendIn_EventOccurrence_CS_InteractionPoint() const
{
	return m_cS_Reference_Operation_sendIn_EventOccurrence_CS_InteractionPoint;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Reference_Operation_sendIn_EventOccurrence_Port() const
{
	return m_cS_Reference_Operation_sendIn_EventOccurrence_Port;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Reference_Operation_sendOut_EventOccurrence_Port() const
{
	return m_cS_Reference_Operation_sendOut_EventOccurrence_Port;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_Reference_Operation_sendOut_EventOccurrence_CS_InteractionPoint() const
{
	return m_cS_Reference_Operation_sendOut_EventOccurrence_CS_InteractionPoint;
}

// End Class CS_Reference

// Begin Class CS_RemoveStructuralFeatureValueActionActivation
std::shared_ptr<ecore::EClass> PSCSPackageImpl::getCS_RemoveStructuralFeatureValueActionActivation_Class() const
{
	return m_cS_RemoveStructuralFeatureValueActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_RemoveStructuralFeatureValueActionActivation_Operation_doAction() const
{
	return m_cS_RemoveStructuralFeatureValueActionActivation_Operation_doAction;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_StructuredValue_Value() const
{
	return m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_StructuredValue_Value;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_RemoveStructuralFeatureValueActionActivation_Operation_getPotentialLinkEnds_CS_Reference_StructuralFeature() const
{
	return m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getPotentialLinkEnds_CS_Reference_StructuralFeature;
}

// End Class CS_RemoveStructuralFeatureValueActionActivation

// Begin Class CS_RequestPropagationStrategy
std::shared_ptr<ecore::EClass> PSCSPackageImpl::getCS_RequestPropagationStrategy_Class() const
{
	return m_cS_RequestPropagationStrategy_Class;
}



std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_RequestPropagationStrategy_Operation_getName() const
{
	return m_cS_RequestPropagationStrategy_Operation_getName;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_RequestPropagationStrategy_Operation_select_Reference_SemanticVisitor() const
{
	return m_cS_RequestPropagationStrategy_Operation_select_Reference_SemanticVisitor;
}

// End Class CS_RequestPropagationStrategy

// Begin Class CS_SendSignalActionActivation
std::shared_ptr<ecore::EClass> PSCSPackageImpl::getCS_SendSignalActionActivation_Class() const
{
	return m_cS_SendSignalActionActivation_Class;
}



std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_SendSignalActionActivation_Operation_doAction() const
{
	return m_cS_SendSignalActionActivation_Operation_doAction;
}

// End Class CS_SendSignalActionActivation

// Begin Class CS_StructuralFeatureOfInterfaceAccessStrategy
std::shared_ptr<ecore::EClass> PSCSPackageImpl::getCS_StructuralFeatureOfInterfaceAccessStrategy_Class() const
{
	return m_cS_StructuralFeatureOfInterfaceAccessStrategy_Class;
}



std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName() const
{
	return m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature() const
{
	return m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature;
}
std::shared_ptr<ecore::EOperation> PSCSPackageImpl::getCS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_Integer() const
{
	return m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_Integer;
}

// End Class CS_StructuralFeatureOfInterfaceAccessStrategy
std::shared_ptr<ecore::EEnum> PSCSPackageImpl::getCS_LinkKind_Class() const
{
	return m_cS_LinkKind_Class;
}

